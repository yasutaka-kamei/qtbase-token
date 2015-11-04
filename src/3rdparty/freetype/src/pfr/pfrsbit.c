begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pfrsbit.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType PFR bitmap loader (body).                                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002-2015 by                                                 */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"pfrsbit.h"
end_include
begin_include
include|#
directive|include
file|"pfrload.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
file|"pfrerror.h"
end_include
begin_undef
DECL|macro|FT_COMPONENT
undef|#
directive|undef
name|FT_COMPONENT
end_undef
begin_define
DECL|macro|FT_COMPONENT
define|#
directive|define
name|FT_COMPONENT
value|trace_pfr
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                      PFR BIT WRITER                           *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_typedef
DECL|struct|PFR_BitWriter_
typedef|typedef
struct|struct
name|PFR_BitWriter_
block|{
DECL|member|line
name|FT_Byte
modifier|*
name|line
decl_stmt|;
comment|/* current line start                    */
DECL|member|pitch
name|FT_Int
name|pitch
decl_stmt|;
comment|/* line size in bytes                    */
DECL|member|width
name|FT_UInt
name|width
decl_stmt|;
comment|/* width in pixels/bits                  */
DECL|member|rows
name|FT_UInt
name|rows
decl_stmt|;
comment|/* number of remaining rows to scan      */
DECL|member|total
name|FT_UInt
name|total
decl_stmt|;
comment|/* total number of bits to draw          */
block|}
DECL|typedef|PFR_BitWriterRec
DECL|typedef|PFR_BitWriter
name|PFR_BitWriterRec
operator|,
typedef|*
name|PFR_BitWriter
typedef|;
end_typedef
begin_function
specifier|static
name|void
DECL|function|pfr_bitwriter_init
name|pfr_bitwriter_init
parameter_list|(
name|PFR_BitWriter
name|writer
parameter_list|,
name|FT_Bitmap
modifier|*
name|target
parameter_list|,
name|FT_Bool
name|decreasing
parameter_list|)
block|{
name|writer
operator|->
name|line
operator|=
name|target
operator|->
name|buffer
expr_stmt|;
name|writer
operator|->
name|pitch
operator|=
name|target
operator|->
name|pitch
expr_stmt|;
name|writer
operator|->
name|width
operator|=
name|target
operator|->
name|width
expr_stmt|;
name|writer
operator|->
name|rows
operator|=
name|target
operator|->
name|rows
expr_stmt|;
name|writer
operator|->
name|total
operator|=
name|writer
operator|->
name|width
operator|*
name|writer
operator|->
name|rows
expr_stmt|;
if|if
condition|(
operator|!
name|decreasing
condition|)
block|{
name|writer
operator|->
name|line
operator|+=
name|writer
operator|->
name|pitch
operator|*
call|(
name|FT_Int
call|)
argument_list|(
name|target
operator|->
name|rows
operator|-
literal|1
argument_list|)
expr_stmt|;
name|writer
operator|->
name|pitch
operator|=
operator|-
name|writer
operator|->
name|pitch
expr_stmt|;
block|}
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|pfr_bitwriter_decode_bytes
name|pfr_bitwriter_decode_bytes
parameter_list|(
name|PFR_BitWriter
name|writer
parameter_list|,
name|FT_Byte
modifier|*
name|p
parameter_list|,
name|FT_Byte
modifier|*
name|limit
parameter_list|)
block|{
name|FT_UInt
name|n
decl_stmt|,
name|reload
decl_stmt|;
name|FT_UInt
name|left
init|=
name|writer
operator|->
name|width
decl_stmt|;
name|FT_Byte
modifier|*
name|cur
init|=
name|writer
operator|->
name|line
decl_stmt|;
name|FT_UInt
name|mask
init|=
literal|0x80
decl_stmt|;
name|FT_UInt
name|val
init|=
literal|0
decl_stmt|;
name|FT_UInt
name|c
init|=
literal|0
decl_stmt|;
name|n
operator|=
call|(
name|FT_UInt
call|)
argument_list|(
name|limit
operator|-
name|p
argument_list|)
operator|*
literal|8
expr_stmt|;
if|if
condition|(
name|n
operator|>
name|writer
operator|->
name|total
condition|)
name|n
operator|=
name|writer
operator|->
name|total
expr_stmt|;
name|reload
operator|=
name|n
operator|&
literal|7
expr_stmt|;
for|for
control|(
init|;
name|n
operator|>
literal|0
condition|;
name|n
operator|--
control|)
block|{
if|if
condition|(
operator|(
name|n
operator|&
literal|7
operator|)
operator|==
name|reload
condition|)
name|val
operator|=
operator|*
name|p
operator|++
expr_stmt|;
if|if
condition|(
name|val
operator|&
literal|0x80
condition|)
name|c
operator||=
name|mask
expr_stmt|;
name|val
operator|<<=
literal|1
expr_stmt|;
name|mask
operator|>>=
literal|1
expr_stmt|;
if|if
condition|(
operator|--
name|left
operator|<=
literal|0
condition|)
block|{
name|cur
index|[
literal|0
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|c
expr_stmt|;
name|left
operator|=
name|writer
operator|->
name|width
expr_stmt|;
name|mask
operator|=
literal|0x80
expr_stmt|;
name|writer
operator|->
name|line
operator|+=
name|writer
operator|->
name|pitch
expr_stmt|;
name|cur
operator|=
name|writer
operator|->
name|line
expr_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mask
operator|==
literal|0
condition|)
block|{
name|cur
index|[
literal|0
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|c
expr_stmt|;
name|mask
operator|=
literal|0x80
expr_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
name|cur
operator|++
expr_stmt|;
block|}
block|}
if|if
condition|(
name|mask
operator|!=
literal|0x80
condition|)
name|cur
index|[
literal|0
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|c
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|pfr_bitwriter_decode_rle1
name|pfr_bitwriter_decode_rle1
parameter_list|(
name|PFR_BitWriter
name|writer
parameter_list|,
name|FT_Byte
modifier|*
name|p
parameter_list|,
name|FT_Byte
modifier|*
name|limit
parameter_list|)
block|{
name|FT_Int
name|phase
decl_stmt|,
name|count
decl_stmt|,
name|counts
index|[
literal|2
index|]
decl_stmt|;
name|FT_UInt
name|n
decl_stmt|,
name|reload
decl_stmt|;
name|FT_UInt
name|left
init|=
name|writer
operator|->
name|width
decl_stmt|;
name|FT_Byte
modifier|*
name|cur
init|=
name|writer
operator|->
name|line
decl_stmt|;
name|FT_UInt
name|mask
init|=
literal|0x80
decl_stmt|;
name|FT_UInt
name|c
init|=
literal|0
decl_stmt|;
name|n
operator|=
name|writer
operator|->
name|total
expr_stmt|;
name|phase
operator|=
literal|1
expr_stmt|;
name|counts
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|counts
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
name|reload
operator|=
literal|1
expr_stmt|;
for|for
control|(
init|;
name|n
operator|>
literal|0
condition|;
name|n
operator|--
control|)
block|{
if|if
condition|(
name|reload
condition|)
block|{
do|do
block|{
if|if
condition|(
name|phase
condition|)
block|{
name|FT_Int
name|v
decl_stmt|;
if|if
condition|(
name|p
operator|>=
name|limit
condition|)
break|break;
name|v
operator|=
operator|*
name|p
operator|++
expr_stmt|;
name|counts
index|[
literal|0
index|]
operator|=
name|v
operator|>>
literal|4
expr_stmt|;
name|counts
index|[
literal|1
index|]
operator|=
name|v
operator|&
literal|15
expr_stmt|;
name|phase
operator|=
literal|0
expr_stmt|;
name|count
operator|=
name|counts
index|[
literal|0
index|]
expr_stmt|;
block|}
else|else
block|{
name|phase
operator|=
literal|1
expr_stmt|;
name|count
operator|=
name|counts
index|[
literal|1
index|]
expr_stmt|;
block|}
block|}
do|while
condition|(
name|count
operator|==
literal|0
condition|)
do|;
block|}
if|if
condition|(
name|phase
condition|)
name|c
operator||=
name|mask
expr_stmt|;
name|mask
operator|>>=
literal|1
expr_stmt|;
if|if
condition|(
operator|--
name|left
operator|<=
literal|0
condition|)
block|{
name|cur
index|[
literal|0
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|c
expr_stmt|;
name|left
operator|=
name|writer
operator|->
name|width
expr_stmt|;
name|mask
operator|=
literal|0x80
expr_stmt|;
name|writer
operator|->
name|line
operator|+=
name|writer
operator|->
name|pitch
expr_stmt|;
name|cur
operator|=
name|writer
operator|->
name|line
expr_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mask
operator|==
literal|0
condition|)
block|{
name|cur
index|[
literal|0
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|c
expr_stmt|;
name|mask
operator|=
literal|0x80
expr_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
name|cur
operator|++
expr_stmt|;
block|}
name|reload
operator|=
operator|(
operator|--
name|count
operator|<=
literal|0
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|!=
literal|0x80
condition|)
name|cur
index|[
literal|0
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|c
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|pfr_bitwriter_decode_rle2
name|pfr_bitwriter_decode_rle2
parameter_list|(
name|PFR_BitWriter
name|writer
parameter_list|,
name|FT_Byte
modifier|*
name|p
parameter_list|,
name|FT_Byte
modifier|*
name|limit
parameter_list|)
block|{
name|FT_Int
name|phase
decl_stmt|,
name|count
decl_stmt|;
name|FT_UInt
name|n
decl_stmt|,
name|reload
decl_stmt|;
name|FT_UInt
name|left
init|=
name|writer
operator|->
name|width
decl_stmt|;
name|FT_Byte
modifier|*
name|cur
init|=
name|writer
operator|->
name|line
decl_stmt|;
name|FT_UInt
name|mask
init|=
literal|0x80
decl_stmt|;
name|FT_UInt
name|c
init|=
literal|0
decl_stmt|;
name|n
operator|=
name|writer
operator|->
name|total
expr_stmt|;
name|phase
operator|=
literal|1
expr_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
name|reload
operator|=
literal|1
expr_stmt|;
for|for
control|(
init|;
name|n
operator|>
literal|0
condition|;
name|n
operator|--
control|)
block|{
if|if
condition|(
name|reload
condition|)
block|{
do|do
block|{
if|if
condition|(
name|p
operator|>=
name|limit
condition|)
break|break;
name|count
operator|=
operator|*
name|p
operator|++
expr_stmt|;
name|phase
operator|=
name|phase
operator|^
literal|1
expr_stmt|;
block|}
do|while
condition|(
name|count
operator|==
literal|0
condition|)
do|;
block|}
if|if
condition|(
name|phase
condition|)
name|c
operator||=
name|mask
expr_stmt|;
name|mask
operator|>>=
literal|1
expr_stmt|;
if|if
condition|(
operator|--
name|left
operator|<=
literal|0
condition|)
block|{
name|cur
index|[
literal|0
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|c
expr_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
name|mask
operator|=
literal|0x80
expr_stmt|;
name|left
operator|=
name|writer
operator|->
name|width
expr_stmt|;
name|writer
operator|->
name|line
operator|+=
name|writer
operator|->
name|pitch
expr_stmt|;
name|cur
operator|=
name|writer
operator|->
name|line
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mask
operator|==
literal|0
condition|)
block|{
name|cur
index|[
literal|0
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|c
expr_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
name|mask
operator|=
literal|0x80
expr_stmt|;
name|cur
operator|++
expr_stmt|;
block|}
name|reload
operator|=
operator|(
operator|--
name|count
operator|<=
literal|0
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|!=
literal|0x80
condition|)
name|cur
index|[
literal|0
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|c
expr_stmt|;
block|}
end_function
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                  BITMAP DATA DECODING                         *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_function
specifier|static
name|void
DECL|function|pfr_lookup_bitmap_data
name|pfr_lookup_bitmap_data
parameter_list|(
name|FT_Byte
modifier|*
name|base
parameter_list|,
name|FT_Byte
modifier|*
name|limit
parameter_list|,
name|FT_UInt
name|count
parameter_list|,
name|FT_UInt
name|flags
parameter_list|,
name|FT_UInt
name|char_code
parameter_list|,
name|FT_ULong
modifier|*
name|found_offset
parameter_list|,
name|FT_ULong
modifier|*
name|found_size
parameter_list|)
block|{
name|FT_UInt
name|left
decl_stmt|,
name|right
decl_stmt|,
name|char_len
decl_stmt|;
name|FT_Bool
name|two
init|=
name|FT_BOOL
argument_list|(
name|flags
operator|&
literal|1
argument_list|)
decl_stmt|;
name|FT_Byte
modifier|*
name|buff
decl_stmt|;
name|char_len
operator|=
literal|4
expr_stmt|;
if|if
condition|(
name|two
condition|)
name|char_len
operator|+=
literal|1
expr_stmt|;
if|if
condition|(
name|flags
operator|&
literal|2
condition|)
name|char_len
operator|+=
literal|1
expr_stmt|;
if|if
condition|(
name|flags
operator|&
literal|4
condition|)
name|char_len
operator|+=
literal|1
expr_stmt|;
name|left
operator|=
literal|0
expr_stmt|;
name|right
operator|=
name|count
expr_stmt|;
while|while
condition|(
name|left
operator|<
name|right
condition|)
block|{
name|FT_UInt
name|middle
decl_stmt|,
name|code
decl_stmt|;
name|middle
operator|=
operator|(
name|left
operator|+
name|right
operator|)
operator|>>
literal|1
expr_stmt|;
name|buff
operator|=
name|base
operator|+
name|middle
operator|*
name|char_len
expr_stmt|;
comment|/* check that we are not outside of the table -- */
comment|/* this is possible with broken fonts...         */
if|if
condition|(
name|buff
operator|+
name|char_len
operator|>
name|limit
condition|)
goto|goto
name|Fail
goto|;
if|if
condition|(
name|two
condition|)
name|code
operator|=
name|PFR_NEXT_USHORT
argument_list|(
name|buff
argument_list|)
expr_stmt|;
else|else
name|code
operator|=
name|PFR_NEXT_BYTE
argument_list|(
name|buff
argument_list|)
expr_stmt|;
if|if
condition|(
name|code
operator|==
name|char_code
condition|)
goto|goto
name|Found_It
goto|;
if|if
condition|(
name|code
operator|<
name|char_code
condition|)
name|left
operator|=
name|middle
expr_stmt|;
else|else
name|right
operator|=
name|middle
expr_stmt|;
block|}
name|Fail
label|:
comment|/* Not found */
operator|*
name|found_size
operator|=
literal|0
expr_stmt|;
operator|*
name|found_offset
operator|=
literal|0
expr_stmt|;
return|return;
name|Found_It
label|:
if|if
condition|(
name|flags
operator|&
literal|2
condition|)
operator|*
name|found_size
operator|=
name|PFR_NEXT_USHORT
argument_list|(
name|buff
argument_list|)
expr_stmt|;
else|else
operator|*
name|found_size
operator|=
name|PFR_NEXT_BYTE
argument_list|(
name|buff
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
literal|4
condition|)
operator|*
name|found_offset
operator|=
name|PFR_NEXT_ULONG
argument_list|(
name|buff
argument_list|)
expr_stmt|;
else|else
operator|*
name|found_offset
operator|=
name|PFR_NEXT_USHORT
argument_list|(
name|buff
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/* load bitmap metrics.  "*padvance" must be set to the default value */
end_comment
begin_comment
comment|/* before calling this function...                                    */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|pfr_load_bitmap_metrics
name|pfr_load_bitmap_metrics
parameter_list|(
name|FT_Byte
modifier|*
modifier|*
name|pdata
parameter_list|,
name|FT_Byte
modifier|*
name|limit
parameter_list|,
name|FT_Long
name|scaled_advance
parameter_list|,
name|FT_Long
modifier|*
name|axpos
parameter_list|,
name|FT_Long
modifier|*
name|aypos
parameter_list|,
name|FT_UInt
modifier|*
name|axsize
parameter_list|,
name|FT_UInt
modifier|*
name|aysize
parameter_list|,
name|FT_Long
modifier|*
name|aadvance
parameter_list|,
name|FT_UInt
modifier|*
name|aformat
parameter_list|)
block|{
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|FT_Byte
name|flags
decl_stmt|;
name|FT_Char
name|c
decl_stmt|;
name|FT_Byte
name|b
decl_stmt|;
name|FT_Byte
modifier|*
name|p
init|=
operator|*
name|pdata
decl_stmt|;
name|FT_Long
name|xpos
decl_stmt|,
name|ypos
decl_stmt|,
name|advance
decl_stmt|;
name|FT_UInt
name|xsize
decl_stmt|,
name|ysize
decl_stmt|;
name|PFR_CHECK
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|flags
operator|=
name|PFR_NEXT_BYTE
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|xpos
operator|=
literal|0
expr_stmt|;
name|ypos
operator|=
literal|0
expr_stmt|;
name|xsize
operator|=
literal|0
expr_stmt|;
name|ysize
operator|=
literal|0
expr_stmt|;
name|advance
operator|=
literal|0
expr_stmt|;
switch|switch
condition|(
name|flags
operator|&
literal|3
condition|)
block|{
case|case
literal|0
case|:
name|PFR_CHECK
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|c
operator|=
name|PFR_NEXT_INT8
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|xpos
operator|=
name|c
operator|>>
literal|4
expr_stmt|;
name|ypos
operator|=
operator|(
call|(
name|FT_Char
call|)
argument_list|(
name|c
operator|<<
literal|4
argument_list|)
operator|)
operator|>>
literal|4
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|PFR_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|xpos
operator|=
name|PFR_NEXT_INT8
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|ypos
operator|=
name|PFR_NEXT_INT8
argument_list|(
name|p
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|PFR_CHECK
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|xpos
operator|=
name|PFR_NEXT_SHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|ypos
operator|=
name|PFR_NEXT_SHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|PFR_CHECK
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|xpos
operator|=
name|PFR_NEXT_LONG
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|ypos
operator|=
name|PFR_NEXT_LONG
argument_list|(
name|p
argument_list|)
expr_stmt|;
break|break;
default|default:
empty_stmt|;
block|}
name|flags
operator|>>=
literal|2
expr_stmt|;
switch|switch
condition|(
name|flags
operator|&
literal|3
condition|)
block|{
case|case
literal|0
case|:
comment|/* blank image */
name|xsize
operator|=
literal|0
expr_stmt|;
name|ysize
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|PFR_CHECK
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|b
operator|=
name|PFR_NEXT_BYTE
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|xsize
operator|=
operator|(
name|b
operator|>>
literal|4
operator|)
operator|&
literal|0xF
expr_stmt|;
name|ysize
operator|=
name|b
operator|&
literal|0xF
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|PFR_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|xsize
operator|=
name|PFR_NEXT_BYTE
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|ysize
operator|=
name|PFR_NEXT_BYTE
argument_list|(
name|p
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|PFR_CHECK
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|xsize
operator|=
name|PFR_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|ysize
operator|=
name|PFR_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
break|break;
default|default:
empty_stmt|;
block|}
name|flags
operator|>>=
literal|2
expr_stmt|;
switch|switch
condition|(
name|flags
operator|&
literal|3
condition|)
block|{
case|case
literal|0
case|:
name|advance
operator|=
name|scaled_advance
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|PFR_CHECK
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|advance
operator|=
name|PFR_NEXT_INT8
argument_list|(
name|p
argument_list|)
operator|<<
literal|8
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|PFR_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|advance
operator|=
name|PFR_NEXT_SHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|PFR_CHECK
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|advance
operator|=
name|PFR_NEXT_LONG
argument_list|(
name|p
argument_list|)
expr_stmt|;
break|break;
default|default:
empty_stmt|;
block|}
operator|*
name|axpos
operator|=
name|xpos
expr_stmt|;
operator|*
name|aypos
operator|=
name|ypos
expr_stmt|;
operator|*
name|axsize
operator|=
name|xsize
expr_stmt|;
operator|*
name|aysize
operator|=
name|ysize
expr_stmt|;
operator|*
name|aadvance
operator|=
name|advance
expr_stmt|;
operator|*
name|aformat
operator|=
name|flags
operator|>>
literal|2
expr_stmt|;
operator|*
name|pdata
operator|=
name|p
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
name|Too_Short
label|:
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Table
argument_list|)
expr_stmt|;
name|FT_ERROR
argument_list|(
operator|(
literal|"pfr_load_bitmap_metrics: invalid glyph data\n"
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|pfr_load_bitmap_bits
name|pfr_load_bitmap_bits
parameter_list|(
name|FT_Byte
modifier|*
name|p
parameter_list|,
name|FT_Byte
modifier|*
name|limit
parameter_list|,
name|FT_UInt
name|format
parameter_list|,
name|FT_Bool
name|decreasing
parameter_list|,
name|FT_Bitmap
modifier|*
name|target
parameter_list|)
block|{
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|PFR_BitWriterRec
name|writer
decl_stmt|;
if|if
condition|(
name|target
operator|->
name|rows
operator|>
literal|0
operator|&&
name|target
operator|->
name|width
operator|>
literal|0
condition|)
block|{
name|pfr_bitwriter_init
argument_list|(
operator|&
name|writer
argument_list|,
name|target
argument_list|,
name|decreasing
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|format
condition|)
block|{
case|case
literal|0
case|:
comment|/* packed bits */
name|pfr_bitwriter_decode_bytes
argument_list|(
operator|&
name|writer
argument_list|,
name|p
argument_list|,
name|limit
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|/* RLE1 */
name|pfr_bitwriter_decode_rle1
argument_list|(
operator|&
name|writer
argument_list|,
name|p
argument_list|,
name|limit
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
comment|/* RLE2 */
name|pfr_bitwriter_decode_rle2
argument_list|(
operator|&
name|writer
argument_list|,
name|p
argument_list|,
name|limit
argument_list|)
expr_stmt|;
break|break;
default|default:
name|FT_ERROR
argument_list|(
operator|(
literal|"pfr_read_bitmap_data: invalid image type\n"
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_File_Format
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|error
return|;
block|}
end_function
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                     BITMAP LOADING                            *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_macro
DECL|function|FT_LOCAL
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|pfr_slot_load_bitmap
argument_list|(
argument|PFR_Slot  glyph
argument_list|,
argument|PFR_Size  size
argument_list|,
argument|FT_UInt   glyph_index
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|PFR_Face
name|face
init|=
operator|(
name|PFR_Face
operator|)
name|glyph
operator|->
name|root
operator|.
name|face
decl_stmt|;
name|FT_Stream
name|stream
init|=
name|face
operator|->
name|root
operator|.
name|stream
decl_stmt|;
name|PFR_PhyFont
name|phys
init|=
operator|&
name|face
operator|->
name|phy_font
decl_stmt|;
name|FT_ULong
name|gps_offset
decl_stmt|;
name|FT_ULong
name|gps_size
decl_stmt|;
name|PFR_Char
name|character
decl_stmt|;
name|PFR_Strike
name|strike
decl_stmt|;
name|character
operator|=
operator|&
name|phys
operator|->
name|chars
index|[
name|glyph_index
index|]
expr_stmt|;
comment|/* Look-up a bitmap strike corresponding to the current */
comment|/* character dimensions                                 */
block|{
name|FT_UInt
name|n
decl_stmt|;
name|strike
operator|=
name|phys
operator|->
name|strikes
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|phys
operator|->
name|num_strikes
condition|;
name|n
operator|++
control|)
block|{
if|if
condition|(
name|strike
operator|->
name|x_ppm
operator|==
operator|(
name|FT_UInt
operator|)
name|size
operator|->
name|root
operator|.
name|metrics
operator|.
name|x_ppem
operator|&&
name|strike
operator|->
name|y_ppm
operator|==
operator|(
name|FT_UInt
operator|)
name|size
operator|->
name|root
operator|.
name|metrics
operator|.
name|y_ppem
condition|)
block|{
goto|goto
name|Found_Strike
goto|;
block|}
name|strike
operator|++
expr_stmt|;
block|}
comment|/* couldn't find it */
return|return
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
return|;
block|}
name|Found_Strike
label|:
comment|/* Now lookup the glyph's position within the file */
block|{
name|FT_UInt
name|char_len
decl_stmt|;
name|char_len
operator|=
literal|4
expr_stmt|;
if|if
condition|(
name|strike
operator|->
name|flags
operator|&
literal|1
condition|)
name|char_len
operator|+=
literal|1
expr_stmt|;
if|if
condition|(
name|strike
operator|->
name|flags
operator|&
literal|2
condition|)
name|char_len
operator|+=
literal|1
expr_stmt|;
if|if
condition|(
name|strike
operator|->
name|flags
operator|&
literal|4
condition|)
name|char_len
operator|+=
literal|1
expr_stmt|;
comment|/* Access data directly in the frame to speed lookups */
if|if
condition|(
name|FT_STREAM_SEEK
argument_list|(
name|phys
operator|->
name|bct_offset
operator|+
name|strike
operator|->
name|bct_offset
argument_list|)
operator|||
name|FT_FRAME_ENTER
argument_list|(
name|char_len
operator|*
name|strike
operator|->
name|num_bitmaps
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|pfr_lookup_bitmap_data
argument_list|(
name|stream
operator|->
name|cursor
argument_list|,
name|stream
operator|->
name|limit
argument_list|,
name|strike
operator|->
name|num_bitmaps
argument_list|,
name|strike
operator|->
name|flags
argument_list|,
name|character
operator|->
name|char_code
argument_list|,
operator|&
name|gps_offset
argument_list|,
operator|&
name|gps_size
argument_list|)
expr_stmt|;
name|FT_FRAME_EXIT
argument_list|()
expr_stmt|;
if|if
condition|(
name|gps_size
operator|==
literal|0
condition|)
block|{
comment|/* Could not find a bitmap program string for this glyph */
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
block|}
comment|/* get the bitmap metrics */
block|{
name|FT_Long
name|xpos
init|=
literal|0
decl_stmt|,
name|ypos
init|=
literal|0
decl_stmt|,
name|advance
init|=
literal|0
decl_stmt|;
name|FT_UInt
name|xsize
init|=
literal|0
decl_stmt|,
name|ysize
init|=
literal|0
decl_stmt|,
name|format
init|=
literal|0
decl_stmt|;
name|FT_Byte
modifier|*
name|p
decl_stmt|;
comment|/* compute linear advance */
name|advance
operator|=
name|character
operator|->
name|advance
expr_stmt|;
if|if
condition|(
name|phys
operator|->
name|metrics_resolution
operator|!=
name|phys
operator|->
name|outline_resolution
condition|)
name|advance
operator|=
name|FT_MulDiv
argument_list|(
name|advance
argument_list|,
operator|(
name|FT_Long
operator|)
name|phys
operator|->
name|outline_resolution
argument_list|,
operator|(
name|FT_Long
operator|)
name|phys
operator|->
name|metrics_resolution
argument_list|)
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|linearHoriAdvance
operator|=
name|advance
expr_stmt|;
comment|/* compute default advance, i.e., scaled advance.  This can be */
comment|/* overridden in the bitmap header of certain glyphs.          */
name|advance
operator|=
name|FT_MulDiv
argument_list|(
operator|(
name|FT_Fixed
operator|)
name|size
operator|->
name|root
operator|.
name|metrics
operator|.
name|x_ppem
operator|<<
literal|8
argument_list|,
name|character
operator|->
name|advance
argument_list|,
operator|(
name|FT_Long
operator|)
name|phys
operator|->
name|metrics_resolution
argument_list|)
expr_stmt|;
if|if
condition|(
name|FT_STREAM_SEEK
argument_list|(
name|face
operator|->
name|header
operator|.
name|gps_section_offset
operator|+
name|gps_offset
argument_list|)
operator|||
name|FT_FRAME_ENTER
argument_list|(
name|gps_size
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|p
operator|=
name|stream
operator|->
name|cursor
expr_stmt|;
name|error
operator|=
name|pfr_load_bitmap_metrics
argument_list|(
operator|&
name|p
argument_list|,
name|stream
operator|->
name|limit
argument_list|,
name|advance
argument_list|,
operator|&
name|xpos
argument_list|,
operator|&
name|ypos
argument_list|,
operator|&
name|xsize
argument_list|,
operator|&
name|ysize
argument_list|,
operator|&
name|advance
argument_list|,
operator|&
name|format
argument_list|)
expr_stmt|;
comment|/*        * XXX: on 16bit systems we return an error for huge bitmaps        *      that cause size truncation, because truncated        *      size properties make bitmap glyphs broken.        */
if|if
condition|(
name|xpos
operator|>
name|FT_INT_MAX
operator|||
name|xpos
operator|<
name|FT_INT_MIN
operator|||
name|ysize
operator|>
name|FT_INT_MAX
operator|||
name|ypos
operator|>
name|FT_INT_MAX
operator|-
operator|(
name|FT_Long
operator|)
name|ysize
operator|||
name|ypos
operator|+
operator|(
name|FT_Long
operator|)
name|ysize
operator|<
name|FT_INT_MIN
condition|)
block|{
name|FT_TRACE1
argument_list|(
operator|(
literal|"pfr_slot_load_bitmap:"
operator|)
argument_list|)
expr_stmt|;
name|FT_TRACE1
argument_list|(
operator|(
literal|"huge bitmap glyph %dx%d over FT_GlyphSlot\n"
operator|,
name|xpos
operator|,
name|ypos
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Pixel_Size
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|error
condition|)
block|{
name|glyph
operator|->
name|root
operator|.
name|format
operator|=
name|FT_GLYPH_FORMAT_BITMAP
expr_stmt|;
comment|/* Set up glyph bitmap and metrics */
comment|/* XXX: needs casts to fit FT_Bitmap.{width|rows|pitch} */
name|glyph
operator|->
name|root
operator|.
name|bitmap
operator|.
name|width
operator|=
name|xsize
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|bitmap
operator|.
name|rows
operator|=
name|ysize
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|bitmap
operator|.
name|pitch
operator|=
call|(
name|FT_Int
call|)
argument_list|(
name|xsize
operator|+
literal|7
argument_list|)
operator|>>
literal|3
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|bitmap
operator|.
name|pixel_mode
operator|=
name|FT_PIXEL_MODE_MONO
expr_stmt|;
comment|/* XXX: needs casts to fit FT_Glyph_Metrics.{width|height} */
name|glyph
operator|->
name|root
operator|.
name|metrics
operator|.
name|width
operator|=
operator|(
name|FT_Pos
operator|)
name|xsize
operator|<<
literal|6
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|metrics
operator|.
name|height
operator|=
operator|(
name|FT_Pos
operator|)
name|ysize
operator|<<
literal|6
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|metrics
operator|.
name|horiBearingX
operator|=
name|xpos
operator|<<
literal|6
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|metrics
operator|.
name|horiBearingY
operator|=
name|ypos
operator|<<
literal|6
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|metrics
operator|.
name|horiAdvance
operator|=
name|FT_PIX_ROUND
argument_list|(
operator|(
name|advance
operator|>>
literal|2
operator|)
argument_list|)
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|metrics
operator|.
name|vertBearingX
operator|=
operator|-
name|glyph
operator|->
name|root
operator|.
name|metrics
operator|.
name|width
operator|>>
literal|1
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|metrics
operator|.
name|vertBearingY
operator|=
literal|0
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|metrics
operator|.
name|vertAdvance
operator|=
name|size
operator|->
name|root
operator|.
name|metrics
operator|.
name|height
expr_stmt|;
comment|/* XXX: needs casts fit FT_GlyphSlotRec.bitmap_{left|top} */
name|glyph
operator|->
name|root
operator|.
name|bitmap_left
operator|=
operator|(
name|FT_Int
operator|)
name|xpos
expr_stmt|;
name|glyph
operator|->
name|root
operator|.
name|bitmap_top
operator|=
call|(
name|FT_Int
call|)
argument_list|(
name|ypos
operator|+
operator|(
name|FT_Long
operator|)
name|ysize
argument_list|)
expr_stmt|;
comment|/* Allocate and read bitmap data */
block|{
name|FT_ULong
name|len
init|=
operator|(
name|FT_ULong
operator|)
name|glyph
operator|->
name|root
operator|.
name|bitmap
operator|.
name|pitch
operator|*
name|ysize
decl_stmt|;
name|error
operator|=
name|ft_glyphslot_alloc_bitmap
argument_list|(
operator|&
name|glyph
operator|->
name|root
argument_list|,
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
block|{
name|error
operator|=
name|pfr_load_bitmap_bits
argument_list|(
name|p
argument_list|,
name|stream
operator|->
name|limit
argument_list|,
name|format
argument_list|,
name|FT_BOOL
argument_list|(
name|face
operator|->
name|header
operator|.
name|color_flags
operator|&
literal|2
argument_list|)
argument_list|,
operator|&
name|glyph
operator|->
name|root
operator|.
name|bitmap
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|FT_FRAME_EXIT
argument_list|()
expr_stmt|;
block|}
name|Exit
label|:
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
