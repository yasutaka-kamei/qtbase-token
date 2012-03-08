begin_unit
begin_comment
comment|/************************************************* *      Perl-Compatible Regular Expressions       * *************************************************/
end_comment
begin_comment
comment|/* PCRE is a library of functions to support regular expressions whose syntax and semantics are as close as possible to those of the Perl 5 language.                         Written by Philip Hazel            Copyright (c) 1997-2012 University of Cambridge  ----------------------------------------------------------------------------- Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.      * Neither the name of the University of Cambridge nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ----------------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* This module contains an internal function for validating UTF-8 character strings. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|PCRE_HAVE_CONFIG_H
end_ifdef
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"pcre_internal.h"
end_include
begin_comment
comment|/************************************************* *         Validate a UTF-8 string                * *************************************************/
end_comment
begin_comment
comment|/* This function is called (optionally) at the start of compile or match, to check that a supposed UTF-8 string is actually valid. The early check means that subsequent code can assume it is dealing with a valid string. The check can be turned off for maximum performance, but the consequences of supplying an invalid string are then undefined.  Originally, this function checked according to RFC 2279, allowing for values in the range 0 to 0x7fffffff, up to 6 bytes long, but ensuring that they were in the canonical format. Once somebody had pointed out RFC 3629 to me (it obsoletes 2279), additional restrictions were applied. The values are now limited to be between 0 and 0x0010ffff, no more than 4 bytes long, and the subrange 0xd000 to 0xdfff is excluded. However, the format of 5-byte and 6-byte characters is still checked.  From release 8.13 more information about the details of the error are passed back in the returned value:  PCRE_UTF8_ERR0   No error PCRE_UTF8_ERR1   Missing 1 byte at the end of the string PCRE_UTF8_ERR2   Missing 2 bytes at the end of the string PCRE_UTF8_ERR3   Missing 3 bytes at the end of the string PCRE_UTF8_ERR4   Missing 4 bytes at the end of the string PCRE_UTF8_ERR5   Missing 5 bytes at the end of the string PCRE_UTF8_ERR6   2nd-byte's two top bits are not 0x80 PCRE_UTF8_ERR7   3rd-byte's two top bits are not 0x80 PCRE_UTF8_ERR8   4th-byte's two top bits are not 0x80 PCRE_UTF8_ERR9   5th-byte's two top bits are not 0x80 PCRE_UTF8_ERR10  6th-byte's two top bits are not 0x80 PCRE_UTF8_ERR11  5-byte character is not permitted by RFC 3629 PCRE_UTF8_ERR12  6-byte character is not permitted by RFC 3629 PCRE_UTF8_ERR13  4-byte character with value> 0x10ffff is not permitted PCRE_UTF8_ERR14  3-byte character with value 0xd000-0xdfff is not permitted PCRE_UTF8_ERR15  Overlong 2-byte sequence PCRE_UTF8_ERR16  Overlong 3-byte sequence PCRE_UTF8_ERR17  Overlong 4-byte sequence PCRE_UTF8_ERR18  Overlong 5-byte sequence (won't ever occur) PCRE_UTF8_ERR19  Overlong 6-byte sequence (won't ever occur) PCRE_UTF8_ERR20  Isolated 0x80 byte (not within UTF-8 character) PCRE_UTF8_ERR21  Byte with the illegal value 0xfe or 0xff  Arguments:   string       points to the string   length       length of string, or -1 if the string is zero-terminated   errp         pointer to an error position offset variable  Returns:       = 0    if the string is a valid UTF-8 string> 0    otherwise, setting the offset of the bad character */
end_comment
begin_function
name|int
DECL|function|valid_utf
name|PRIV
function|(
name|valid_utf
function|)
parameter_list|(
name|PCRE_PUCHAR
name|string
parameter_list|,
name|int
name|length
parameter_list|,
name|int
modifier|*
name|erroroffset
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SUPPORT_UTF
specifier|register
name|PCRE_PUCHAR
name|p
decl_stmt|;
if|if
condition|(
name|length
operator|<
literal|0
condition|)
block|{
for|for
control|(
name|p
operator|=
name|string
init|;
operator|*
name|p
operator|!=
literal|0
condition|;
name|p
operator|++
control|)
empty_stmt|;
name|length
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|p
operator|=
name|string
init|;
name|length
operator|--
operator|>
literal|0
condition|;
name|p
operator|++
control|)
block|{
specifier|register
name|int
name|ab
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|;
name|c
operator|=
operator|*
name|p
expr_stmt|;
if|if
condition|(
name|c
operator|<
literal|128
condition|)
continue|continue;
comment|/* ASCII character */
if|if
condition|(
name|c
operator|<
literal|0xc0
condition|)
comment|/* Isolated 10xx xxxx byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
expr_stmt|;
return|return
name|PCRE_UTF8_ERR20
return|;
block|}
if|if
condition|(
name|c
operator|>=
literal|0xfe
condition|)
comment|/* Invalid 0xfe or 0xff bytes */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
expr_stmt|;
return|return
name|PCRE_UTF8_ERR21
return|;
block|}
name|ab
operator|=
name|PRIV
argument_list|(
name|utf8_table4
argument_list|)
index|[
name|c
operator|&
literal|0x3f
index|]
expr_stmt|;
comment|/* Number of additional bytes */
if|if
condition|(
name|length
operator|<
name|ab
condition|)
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
expr_stmt|;
comment|/* Missing bytes */
return|return
name|ab
operator|-
name|length
return|;
comment|/* Codes ERR1 to ERR5 */
block|}
name|length
operator|-=
name|ab
expr_stmt|;
comment|/* Length remaining */
comment|/* Check top bits in the second byte */
if|if
condition|(
operator|(
operator|(
name|d
operator|=
operator|*
operator|(
operator|++
name|p
operator|)
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|1
expr_stmt|;
return|return
name|PCRE_UTF8_ERR6
return|;
block|}
comment|/* For each length, check that the remaining bytes start with the 0x80 bit   set and not the 0x40 bit. Then check for an overlong sequence, and for the   excluded range 0xd800 to 0xdfff. */
switch|switch
condition|(
name|ab
condition|)
block|{
comment|/* 2-byte character. No further bytes to check for 0x80. Check first byte     for for xx00 000x (overlong sequence). */
case|case
literal|1
case|:
if|if
condition|(
operator|(
name|c
operator|&
literal|0x3e
operator|)
operator|==
literal|0
condition|)
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|1
expr_stmt|;
return|return
name|PCRE_UTF8_ERR15
return|;
block|}
break|break;
comment|/* 3-byte character. Check third byte for 0x80. Then check first 2 bytes       for 1110 0000, xx0x xxxx (overlong sequence) or           1110 1101, 1010 xxxx (0xd800 - 0xdfff) */
case|case
literal|2
case|:
if|if
condition|(
operator|(
operator|*
operator|(
operator|++
name|p
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
comment|/* Third byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|2
expr_stmt|;
return|return
name|PCRE_UTF8_ERR7
return|;
block|}
if|if
condition|(
name|c
operator|==
literal|0xe0
operator|&&
operator|(
name|d
operator|&
literal|0x20
operator|)
operator|==
literal|0
condition|)
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|2
expr_stmt|;
return|return
name|PCRE_UTF8_ERR16
return|;
block|}
if|if
condition|(
name|c
operator|==
literal|0xed
operator|&&
name|d
operator|>=
literal|0xa0
condition|)
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|2
expr_stmt|;
return|return
name|PCRE_UTF8_ERR14
return|;
block|}
break|break;
comment|/* 4-byte character. Check 3rd and 4th bytes for 0x80. Then check first 2        bytes for for 1111 0000, xx00 xxxx (overlong sequence), then check for a        character greater than 0x0010ffff (f4 8f bf bf) */
case|case
literal|3
case|:
if|if
condition|(
operator|(
operator|*
operator|(
operator|++
name|p
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
comment|/* Third byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|2
expr_stmt|;
return|return
name|PCRE_UTF8_ERR7
return|;
block|}
if|if
condition|(
operator|(
operator|*
operator|(
operator|++
name|p
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
comment|/* Fourth byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|3
expr_stmt|;
return|return
name|PCRE_UTF8_ERR8
return|;
block|}
if|if
condition|(
name|c
operator|==
literal|0xf0
operator|&&
operator|(
name|d
operator|&
literal|0x30
operator|)
operator|==
literal|0
condition|)
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|3
expr_stmt|;
return|return
name|PCRE_UTF8_ERR17
return|;
block|}
if|if
condition|(
name|c
operator|>
literal|0xf4
operator|||
operator|(
name|c
operator|==
literal|0xf4
operator|&&
name|d
operator|>
literal|0x8f
operator|)
condition|)
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|3
expr_stmt|;
return|return
name|PCRE_UTF8_ERR13
return|;
block|}
break|break;
comment|/* 5-byte and 6-byte characters are not allowed by RFC 3629, and will be     rejected by the length test below. However, we do the appropriate tests     here so that overlong sequences get diagnosed, and also in case there is     ever an option for handling these larger code points. */
comment|/* 5-byte character. Check 3rd, 4th, and 5th bytes for 0x80. Then check for     1111 1000, xx00 0xxx */
case|case
literal|4
case|:
if|if
condition|(
operator|(
operator|*
operator|(
operator|++
name|p
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
comment|/* Third byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|2
expr_stmt|;
return|return
name|PCRE_UTF8_ERR7
return|;
block|}
if|if
condition|(
operator|(
operator|*
operator|(
operator|++
name|p
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
comment|/* Fourth byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|3
expr_stmt|;
return|return
name|PCRE_UTF8_ERR8
return|;
block|}
if|if
condition|(
operator|(
operator|*
operator|(
operator|++
name|p
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
comment|/* Fifth byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|4
expr_stmt|;
return|return
name|PCRE_UTF8_ERR9
return|;
block|}
if|if
condition|(
name|c
operator|==
literal|0xf8
operator|&&
operator|(
name|d
operator|&
literal|0x38
operator|)
operator|==
literal|0
condition|)
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|4
expr_stmt|;
return|return
name|PCRE_UTF8_ERR18
return|;
block|}
break|break;
comment|/* 6-byte character. Check 3rd-6th bytes for 0x80. Then check for     1111 1100, xx00 00xx. */
case|case
literal|5
case|:
if|if
condition|(
operator|(
operator|*
operator|(
operator|++
name|p
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
comment|/* Third byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|2
expr_stmt|;
return|return
name|PCRE_UTF8_ERR7
return|;
block|}
if|if
condition|(
operator|(
operator|*
operator|(
operator|++
name|p
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
comment|/* Fourth byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|3
expr_stmt|;
return|return
name|PCRE_UTF8_ERR8
return|;
block|}
if|if
condition|(
operator|(
operator|*
operator|(
operator|++
name|p
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
comment|/* Fifth byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|4
expr_stmt|;
return|return
name|PCRE_UTF8_ERR9
return|;
block|}
if|if
condition|(
operator|(
operator|*
operator|(
operator|++
name|p
operator|)
operator|&
literal|0xc0
operator|)
operator|!=
literal|0x80
condition|)
comment|/* Sixth byte */
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|5
expr_stmt|;
return|return
name|PCRE_UTF8_ERR10
return|;
block|}
if|if
condition|(
name|c
operator|==
literal|0xfc
operator|&&
operator|(
name|d
operator|&
literal|0x3c
operator|)
operator|==
literal|0
condition|)
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
literal|5
expr_stmt|;
return|return
name|PCRE_UTF8_ERR19
return|;
block|}
break|break;
block|}
comment|/* Character is valid under RFC 2279, but 4-byte and 5-byte characters are   excluded by RFC 3629. The pointer p is currently at the last byte of the   character. */
if|if
condition|(
name|ab
operator|>
literal|3
condition|)
block|{
operator|*
name|erroroffset
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|string
argument_list|)
operator|-
name|ab
expr_stmt|;
return|return
operator|(
name|ab
operator|==
literal|4
operator|)
condition|?
name|PCRE_UTF8_ERR11
else|:
name|PCRE_UTF8_ERR12
return|;
block|}
block|}
else|#
directive|else
comment|/* SUPPORT_UTF */
call|(
name|void
call|)
argument_list|(
name|string
argument_list|)
expr_stmt|;
comment|/* Keep picky compilers happy */
call|(
name|void
call|)
argument_list|(
name|length
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|PCRE_UTF8_ERR0
return|;
comment|/* This indicates success */
block|}
end_function
begin_comment
comment|/* End of pcre_valid_utf8.c */
end_comment
end_unit
