begin_unit
begin_comment
comment|/************************************************* *      Perl-Compatible Regular Expressions       * *************************************************/
end_comment
begin_comment
comment|/* PCRE is a library of functions to support regular expressions whose syntax and semantics are as close as possible to those of the Perl 5 language.                         Written by Philip Hazel            Copyright (c) 1997-2012 University of Cambridge  ----------------------------------------------------------------------------- Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.      * Neither the name of the University of Cambridge nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ----------------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* This module contains an internal function that is used to match an extended class. It is used by both pcre_exec() and pcre_def_exec(). */
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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILE_PCRE8
end_ifndef
begin_comment
comment|/************************************************* *           Compare string utilities             * *************************************************/
end_comment
begin_comment
comment|/* The following two functions compares two strings. Basically an strcmp for non 8 bit characters.  Arguments:   str1        first string   str2        second string  Returns:      0 if both string are equal (like strcmp), 1 otherwise */
end_comment
begin_function
name|int
DECL|function|strcmp_uc_uc
name|PRIV
function|(
name|strcmp_uc_uc
function|)
parameter_list|(
specifier|const
name|pcre_uchar
modifier|*
name|str1
parameter_list|,
specifier|const
name|pcre_uchar
modifier|*
name|str2
parameter_list|)
block|{
name|pcre_uchar
name|c1
decl_stmt|;
name|pcre_uchar
name|c2
decl_stmt|;
while|while
condition|(
operator|*
name|str1
operator|!=
literal|'\0'
operator|||
operator|*
name|str2
operator|!=
literal|'\0'
condition|)
block|{
name|c1
operator|=
operator|*
name|str1
operator|++
expr_stmt|;
name|c2
operator|=
operator|*
name|str2
operator|++
expr_stmt|;
if|if
condition|(
name|c1
operator|!=
name|c2
condition|)
return|return
operator|(
operator|(
name|c1
operator|>
name|c2
operator|)
operator|<<
literal|1
operator|)
operator|-
literal|1
return|;
block|}
comment|/* Both length and characters must be equal. */
return|return
literal|0
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|COMPILE_PCRE32
end_ifdef
begin_function
name|int
DECL|function|strcmp_uc_uc_utf
name|PRIV
function|(
name|strcmp_uc_uc_utf
function|)
parameter_list|(
specifier|const
name|pcre_uchar
modifier|*
name|str1
parameter_list|,
specifier|const
name|pcre_uchar
modifier|*
name|str2
parameter_list|)
block|{
name|pcre_uchar
name|c1
decl_stmt|;
name|pcre_uchar
name|c2
decl_stmt|;
while|while
condition|(
operator|*
name|str1
operator|!=
literal|'\0'
operator|||
operator|*
name|str2
operator|!=
literal|'\0'
condition|)
block|{
name|c1
operator|=
name|RAWUCHARINC
argument_list|(
name|str1
argument_list|)
expr_stmt|;
name|c2
operator|=
name|RAWUCHARINC
argument_list|(
name|str2
argument_list|)
expr_stmt|;
if|if
condition|(
name|c1
operator|!=
name|c2
condition|)
return|return
operator|(
operator|(
name|c1
operator|>
name|c2
operator|)
operator|<<
literal|1
operator|)
operator|-
literal|1
return|;
block|}
comment|/* Both length and characters must be equal. */
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* COMPILE_PCRE32 */
end_comment
begin_function
name|int
DECL|function|strcmp_uc_c8
name|PRIV
function|(
name|strcmp_uc_c8
function|)
parameter_list|(
specifier|const
name|pcre_uchar
modifier|*
name|str1
parameter_list|,
specifier|const
name|char
modifier|*
name|str2
parameter_list|)
block|{
specifier|const
name|pcre_uint8
modifier|*
name|ustr2
init|=
operator|(
name|pcre_uint8
operator|*
operator|)
name|str2
decl_stmt|;
name|pcre_uchar
name|c1
decl_stmt|;
name|pcre_uchar
name|c2
decl_stmt|;
while|while
condition|(
operator|*
name|str1
operator|!=
literal|'\0'
operator|||
operator|*
name|ustr2
operator|!=
literal|'\0'
condition|)
block|{
name|c1
operator|=
operator|*
name|str1
operator|++
expr_stmt|;
name|c2
operator|=
operator|(
name|pcre_uchar
operator|)
operator|*
name|ustr2
operator|++
expr_stmt|;
if|if
condition|(
name|c1
operator|!=
name|c2
condition|)
return|return
operator|(
operator|(
name|c1
operator|>
name|c2
operator|)
operator|<<
literal|1
operator|)
operator|-
literal|1
return|;
block|}
comment|/* Both length and characters must be equal. */
return|return
literal|0
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|COMPILE_PCRE32
end_ifdef
begin_function
name|int
DECL|function|strcmp_uc_c8_utf
name|PRIV
function|(
name|strcmp_uc_c8_utf
function|)
parameter_list|(
specifier|const
name|pcre_uchar
modifier|*
name|str1
parameter_list|,
specifier|const
name|char
modifier|*
name|str2
parameter_list|)
block|{
specifier|const
name|pcre_uint8
modifier|*
name|ustr2
init|=
operator|(
name|pcre_uint8
operator|*
operator|)
name|str2
decl_stmt|;
name|pcre_uchar
name|c1
decl_stmt|;
name|pcre_uchar
name|c2
decl_stmt|;
while|while
condition|(
operator|*
name|str1
operator|!=
literal|'\0'
operator|||
operator|*
name|ustr2
operator|!=
literal|'\0'
condition|)
block|{
name|c1
operator|=
name|RAWUCHARINC
argument_list|(
name|str1
argument_list|)
expr_stmt|;
name|c2
operator|=
operator|(
name|pcre_uchar
operator|)
operator|*
name|ustr2
operator|++
expr_stmt|;
if|if
condition|(
name|c1
operator|!=
name|c2
condition|)
return|return
operator|(
operator|(
name|c1
operator|>
name|c2
operator|)
operator|<<
literal|1
operator|)
operator|-
literal|1
return|;
block|}
comment|/* Both length and characters must be equal. */
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* COMPILE_PCRE32 */
end_comment
begin_comment
comment|/* The following two functions compares two, fixed length strings. Basically an strncmp for non 8 bit characters.  Arguments:   str1        first string   str2        second string   num         size of the string  Returns:      0 if both string are equal (like strcmp), 1 otherwise */
end_comment
begin_function
name|int
DECL|function|strncmp_uc_uc
name|PRIV
function|(
name|strncmp_uc_uc
function|)
parameter_list|(
specifier|const
name|pcre_uchar
modifier|*
name|str1
parameter_list|,
specifier|const
name|pcre_uchar
modifier|*
name|str2
parameter_list|,
name|unsigned
name|int
name|num
parameter_list|)
block|{
name|pcre_uchar
name|c1
decl_stmt|;
name|pcre_uchar
name|c2
decl_stmt|;
while|while
condition|(
name|num
operator|--
operator|>
literal|0
condition|)
block|{
name|c1
operator|=
operator|*
name|str1
operator|++
expr_stmt|;
name|c2
operator|=
operator|*
name|str2
operator|++
expr_stmt|;
if|if
condition|(
name|c1
operator|!=
name|c2
condition|)
return|return
operator|(
operator|(
name|c1
operator|>
name|c2
operator|)
operator|<<
literal|1
operator|)
operator|-
literal|1
return|;
block|}
comment|/* Both length and characters must be equal. */
return|return
literal|0
return|;
block|}
end_function
begin_function
name|int
DECL|function|strncmp_uc_c8
name|PRIV
function|(
name|strncmp_uc_c8
function|)
parameter_list|(
specifier|const
name|pcre_uchar
modifier|*
name|str1
parameter_list|,
specifier|const
name|char
modifier|*
name|str2
parameter_list|,
name|unsigned
name|int
name|num
parameter_list|)
block|{
specifier|const
name|pcre_uint8
modifier|*
name|ustr2
init|=
operator|(
name|pcre_uint8
operator|*
operator|)
name|str2
decl_stmt|;
name|pcre_uchar
name|c1
decl_stmt|;
name|pcre_uchar
name|c2
decl_stmt|;
while|while
condition|(
name|num
operator|--
operator|>
literal|0
condition|)
block|{
name|c1
operator|=
operator|*
name|str1
operator|++
expr_stmt|;
name|c2
operator|=
operator|(
name|pcre_uchar
operator|)
operator|*
name|ustr2
operator|++
expr_stmt|;
if|if
condition|(
name|c1
operator|!=
name|c2
condition|)
return|return
operator|(
operator|(
name|c1
operator|>
name|c2
operator|)
operator|<<
literal|1
operator|)
operator|-
literal|1
return|;
block|}
comment|/* Both length and characters must be equal. */
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/* The following function returns with the length of a zero terminated string. Basically an strlen for non 8 bit characters.  Arguments:   str         string  Returns:      length of the string */
end_comment
begin_function
name|unsigned
name|int
DECL|function|strlen_uc
name|PRIV
function|(
name|strlen_uc
function|)
parameter_list|(
specifier|const
name|pcre_uchar
modifier|*
name|str
parameter_list|)
block|{
name|unsigned
name|int
name|len
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|*
name|str
operator|++
operator|!=
literal|0
condition|)
name|len
operator|++
expr_stmt|;
return|return
name|len
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !COMPILE_PCRE8 */
end_comment
begin_comment
comment|/* End of pcre_string_utils.c */
end_comment
end_unit
