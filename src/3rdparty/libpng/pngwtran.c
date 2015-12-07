begin_unit
begin_comment
comment|/* pngwtran.c - transforms the data in a row for PNG writers  *  * Last changed in libpng 1.6.18 [July 23, 2015]  * Copyright (c) 1998-2015 Glenn Randers-Pehrson  * (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)  * (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)  *  * This code is released under the libpng license.  * For conditions of distribution and use, see the disclaimer  * and license in png.h  */
end_comment
begin_include
include|#
directive|include
file|"pngpriv.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_WRITE_SUPPORTED
end_ifdef
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_WRITE_TRANSFORMS_SUPPORTED
end_ifdef
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_WRITE_PACK_SUPPORTED
end_ifdef
begin_comment
comment|/* Pack pixels into bytes.  Pass the true bit depth in bit_depth.  The  * row_info bit depth should be 8 (one pixel per byte).  The channels  * should be 1 (this only happens on grayscale and paletted images).  */
end_comment
begin_function
specifier|static
name|void
DECL|function|png_do_pack
name|png_do_pack
parameter_list|(
name|png_row_infop
name|row_info
parameter_list|,
name|png_bytep
name|row
parameter_list|,
name|png_uint_32
name|bit_depth
parameter_list|)
block|{
name|png_debug
argument_list|(
literal|1
argument_list|,
literal|"in png_do_pack"
argument_list|)
expr_stmt|;
if|if
condition|(
name|row_info
operator|->
name|bit_depth
operator|==
literal|8
operator|&&
name|row_info
operator|->
name|channels
operator|==
literal|1
condition|)
block|{
switch|switch
condition|(
operator|(
name|int
operator|)
name|bit_depth
condition|)
block|{
case|case
literal|1
case|:
block|{
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|int
name|mask
decl_stmt|,
name|v
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
name|sp
operator|=
name|row
expr_stmt|;
name|dp
operator|=
name|row
expr_stmt|;
name|mask
operator|=
literal|0x80
expr_stmt|;
name|v
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|sp
operator|!=
literal|0
condition|)
name|v
operator||=
name|mask
expr_stmt|;
name|sp
operator|++
expr_stmt|;
if|if
condition|(
name|mask
operator|>
literal|1
condition|)
name|mask
operator|>>=
literal|1
expr_stmt|;
else|else
block|{
name|mask
operator|=
literal|0x80
expr_stmt|;
operator|*
name|dp
operator|=
operator|(
name|png_byte
operator|)
name|v
expr_stmt|;
name|dp
operator|++
expr_stmt|;
name|v
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
name|mask
operator|!=
literal|0x80
condition|)
operator|*
name|dp
operator|=
operator|(
name|png_byte
operator|)
name|v
expr_stmt|;
break|break;
block|}
case|case
literal|2
case|:
block|{
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|unsigned
name|int
name|shift
decl_stmt|;
name|int
name|v
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
name|sp
operator|=
name|row
expr_stmt|;
name|dp
operator|=
name|row
expr_stmt|;
name|shift
operator|=
literal|6
expr_stmt|;
name|v
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
name|png_byte
name|value
decl_stmt|;
name|value
operator|=
call|(
name|png_byte
call|)
argument_list|(
operator|*
name|sp
operator|&
literal|0x03
argument_list|)
expr_stmt|;
name|v
operator||=
operator|(
name|value
operator|<<
name|shift
operator|)
expr_stmt|;
if|if
condition|(
name|shift
operator|==
literal|0
condition|)
block|{
name|shift
operator|=
literal|6
expr_stmt|;
operator|*
name|dp
operator|=
operator|(
name|png_byte
operator|)
name|v
expr_stmt|;
name|dp
operator|++
expr_stmt|;
name|v
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|shift
operator|-=
literal|2
expr_stmt|;
name|sp
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|shift
operator|!=
literal|6
condition|)
operator|*
name|dp
operator|=
operator|(
name|png_byte
operator|)
name|v
expr_stmt|;
break|break;
block|}
case|case
literal|4
case|:
block|{
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|unsigned
name|int
name|shift
decl_stmt|;
name|int
name|v
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
name|sp
operator|=
name|row
expr_stmt|;
name|dp
operator|=
name|row
expr_stmt|;
name|shift
operator|=
literal|4
expr_stmt|;
name|v
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
name|png_byte
name|value
decl_stmt|;
name|value
operator|=
call|(
name|png_byte
call|)
argument_list|(
operator|*
name|sp
operator|&
literal|0x0f
argument_list|)
expr_stmt|;
name|v
operator||=
operator|(
name|value
operator|<<
name|shift
operator|)
expr_stmt|;
if|if
condition|(
name|shift
operator|==
literal|0
condition|)
block|{
name|shift
operator|=
literal|4
expr_stmt|;
operator|*
name|dp
operator|=
operator|(
name|png_byte
operator|)
name|v
expr_stmt|;
name|dp
operator|++
expr_stmt|;
name|v
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|shift
operator|-=
literal|4
expr_stmt|;
name|sp
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|shift
operator|!=
literal|4
condition|)
operator|*
name|dp
operator|=
operator|(
name|png_byte
operator|)
name|v
expr_stmt|;
break|break;
block|}
default|default:
break|break;
block|}
name|row_info
operator|->
name|bit_depth
operator|=
operator|(
name|png_byte
operator|)
name|bit_depth
expr_stmt|;
name|row_info
operator|->
name|pixel_depth
operator|=
call|(
name|png_byte
call|)
argument_list|(
name|bit_depth
operator|*
name|row_info
operator|->
name|channels
argument_list|)
expr_stmt|;
name|row_info
operator|->
name|rowbytes
operator|=
name|PNG_ROWBYTES
argument_list|(
name|row_info
operator|->
name|pixel_depth
argument_list|,
name|row_info
operator|->
name|width
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_WRITE_SHIFT_SUPPORTED
end_ifdef
begin_comment
comment|/* Shift pixel values to take advantage of whole range.  Pass the  * true number of bits in bit_depth.  The row should be packed  * according to row_info->bit_depth.  Thus, if you had a row of  * bit depth 4, but the pixels only had values from 0 to 7, you  * would pass 3 as bit_depth, and this routine would translate the  * data to 0 to 15.  */
end_comment
begin_function
specifier|static
name|void
DECL|function|png_do_shift
name|png_do_shift
parameter_list|(
name|png_row_infop
name|row_info
parameter_list|,
name|png_bytep
name|row
parameter_list|,
name|png_const_color_8p
name|bit_depth
parameter_list|)
block|{
name|png_debug
argument_list|(
literal|1
argument_list|,
literal|"in png_do_shift"
argument_list|)
expr_stmt|;
if|if
condition|(
name|row_info
operator|->
name|color_type
operator|!=
name|PNG_COLOR_TYPE_PALETTE
condition|)
block|{
name|int
name|shift_start
index|[
literal|4
index|]
decl_stmt|,
name|shift_dec
index|[
literal|4
index|]
decl_stmt|;
name|int
name|channels
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|row_info
operator|->
name|color_type
operator|&
name|PNG_COLOR_MASK_COLOR
operator|)
operator|!=
literal|0
condition|)
block|{
name|shift_start
index|[
name|channels
index|]
operator|=
name|row_info
operator|->
name|bit_depth
operator|-
name|bit_depth
operator|->
name|red
expr_stmt|;
name|shift_dec
index|[
name|channels
index|]
operator|=
name|bit_depth
operator|->
name|red
expr_stmt|;
name|channels
operator|++
expr_stmt|;
name|shift_start
index|[
name|channels
index|]
operator|=
name|row_info
operator|->
name|bit_depth
operator|-
name|bit_depth
operator|->
name|green
expr_stmt|;
name|shift_dec
index|[
name|channels
index|]
operator|=
name|bit_depth
operator|->
name|green
expr_stmt|;
name|channels
operator|++
expr_stmt|;
name|shift_start
index|[
name|channels
index|]
operator|=
name|row_info
operator|->
name|bit_depth
operator|-
name|bit_depth
operator|->
name|blue
expr_stmt|;
name|shift_dec
index|[
name|channels
index|]
operator|=
name|bit_depth
operator|->
name|blue
expr_stmt|;
name|channels
operator|++
expr_stmt|;
block|}
else|else
block|{
name|shift_start
index|[
name|channels
index|]
operator|=
name|row_info
operator|->
name|bit_depth
operator|-
name|bit_depth
operator|->
name|gray
expr_stmt|;
name|shift_dec
index|[
name|channels
index|]
operator|=
name|bit_depth
operator|->
name|gray
expr_stmt|;
name|channels
operator|++
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|row_info
operator|->
name|color_type
operator|&
name|PNG_COLOR_MASK_ALPHA
operator|)
operator|!=
literal|0
condition|)
block|{
name|shift_start
index|[
name|channels
index|]
operator|=
name|row_info
operator|->
name|bit_depth
operator|-
name|bit_depth
operator|->
name|alpha
expr_stmt|;
name|shift_dec
index|[
name|channels
index|]
operator|=
name|bit_depth
operator|->
name|alpha
expr_stmt|;
name|channels
operator|++
expr_stmt|;
block|}
comment|/* With low row depths, could only be grayscale, so one channel */
if|if
condition|(
name|row_info
operator|->
name|bit_depth
operator|<
literal|8
condition|)
block|{
name|png_bytep
name|bp
init|=
name|row
decl_stmt|;
name|png_size_t
name|i
decl_stmt|;
name|unsigned
name|int
name|mask
decl_stmt|;
name|png_size_t
name|row_bytes
init|=
name|row_info
operator|->
name|rowbytes
decl_stmt|;
if|if
condition|(
name|bit_depth
operator|->
name|gray
operator|==
literal|1
operator|&&
name|row_info
operator|->
name|bit_depth
operator|==
literal|2
condition|)
name|mask
operator|=
literal|0x55
expr_stmt|;
elseif|else
if|if
condition|(
name|row_info
operator|->
name|bit_depth
operator|==
literal|4
operator|&&
name|bit_depth
operator|->
name|gray
operator|==
literal|3
condition|)
name|mask
operator|=
literal|0x11
expr_stmt|;
else|else
name|mask
operator|=
literal|0xff
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|row_bytes
condition|;
name|i
operator|++
operator|,
name|bp
operator|++
control|)
block|{
name|int
name|j
decl_stmt|;
name|unsigned
name|int
name|v
decl_stmt|,
name|out
decl_stmt|;
name|v
operator|=
operator|*
name|bp
expr_stmt|;
name|out
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|j
operator|=
name|shift_start
index|[
literal|0
index|]
init|;
name|j
operator|>
operator|-
name|shift_dec
index|[
literal|0
index|]
condition|;
name|j
operator|-=
name|shift_dec
index|[
literal|0
index|]
control|)
block|{
if|if
condition|(
name|j
operator|>
literal|0
condition|)
name|out
operator||=
name|v
operator|<<
name|j
expr_stmt|;
else|else
name|out
operator||=
operator|(
name|v
operator|>>
operator|(
operator|-
name|j
operator|)
operator|)
operator|&
name|mask
expr_stmt|;
block|}
operator|*
name|bp
operator|=
call|(
name|png_byte
call|)
argument_list|(
name|out
operator|&
literal|0xff
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|row_info
operator|->
name|bit_depth
operator|==
literal|8
condition|)
block|{
name|png_bytep
name|bp
init|=
name|row
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|istop
init|=
name|channels
operator|*
name|row_info
operator|->
name|width
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|istop
condition|;
name|i
operator|++
operator|,
name|bp
operator|++
control|)
block|{
specifier|const
name|unsigned
name|int
name|c
init|=
name|i
operator|%
name|channels
decl_stmt|;
name|int
name|j
decl_stmt|;
name|unsigned
name|int
name|v
decl_stmt|,
name|out
decl_stmt|;
name|v
operator|=
operator|*
name|bp
expr_stmt|;
name|out
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|j
operator|=
name|shift_start
index|[
name|c
index|]
init|;
name|j
operator|>
operator|-
name|shift_dec
index|[
name|c
index|]
condition|;
name|j
operator|-=
name|shift_dec
index|[
name|c
index|]
control|)
block|{
if|if
condition|(
name|j
operator|>
literal|0
condition|)
name|out
operator||=
name|v
operator|<<
name|j
expr_stmt|;
else|else
name|out
operator||=
name|v
operator|>>
operator|(
operator|-
name|j
operator|)
expr_stmt|;
block|}
operator|*
name|bp
operator|=
call|(
name|png_byte
call|)
argument_list|(
name|out
operator|&
literal|0xff
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|png_bytep
name|bp
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|istop
init|=
name|channels
operator|*
name|row_info
operator|->
name|width
decl_stmt|;
for|for
control|(
name|bp
operator|=
name|row
operator|,
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|istop
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|unsigned
name|int
name|c
init|=
name|i
operator|%
name|channels
decl_stmt|;
name|int
name|j
decl_stmt|;
name|unsigned
name|int
name|value
decl_stmt|,
name|v
decl_stmt|;
name|v
operator|=
name|png_get_uint_16
argument_list|(
name|bp
argument_list|)
expr_stmt|;
name|value
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|j
operator|=
name|shift_start
index|[
name|c
index|]
init|;
name|j
operator|>
operator|-
name|shift_dec
index|[
name|c
index|]
condition|;
name|j
operator|-=
name|shift_dec
index|[
name|c
index|]
control|)
block|{
if|if
condition|(
name|j
operator|>
literal|0
condition|)
name|value
operator||=
name|v
operator|<<
name|j
expr_stmt|;
else|else
name|value
operator||=
name|v
operator|>>
operator|(
operator|-
name|j
operator|)
expr_stmt|;
block|}
operator|*
name|bp
operator|++
operator|=
call|(
name|png_byte
call|)
argument_list|(
operator|(
name|value
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
operator|*
name|bp
operator|++
operator|=
call|(
name|png_byte
call|)
argument_list|(
name|value
operator|&
literal|0xff
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_WRITE_SWAP_ALPHA_SUPPORTED
end_ifdef
begin_function
specifier|static
name|void
DECL|function|png_do_write_swap_alpha
name|png_do_write_swap_alpha
parameter_list|(
name|png_row_infop
name|row_info
parameter_list|,
name|png_bytep
name|row
parameter_list|)
block|{
name|png_debug
argument_list|(
literal|1
argument_list|,
literal|"in png_do_write_swap_alpha"
argument_list|)
expr_stmt|;
block|{
if|if
condition|(
name|row_info
operator|->
name|color_type
operator|==
name|PNG_COLOR_TYPE_RGB_ALPHA
condition|)
block|{
if|if
condition|(
name|row_info
operator|->
name|bit_depth
operator|==
literal|8
condition|)
block|{
comment|/* This converts from ARGB to RGBA */
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|sp
operator|=
name|dp
operator|=
name|row
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
name|png_byte
name|save
init|=
operator|*
operator|(
name|sp
operator|++
operator|)
decl_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
name|save
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|PNG_WRITE_16BIT_SUPPORTED
else|else
block|{
comment|/* This converts from AARRGGBB to RRGGBBAA */
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|sp
operator|=
name|dp
operator|=
name|row
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
name|png_byte
name|save
index|[
literal|2
index|]
decl_stmt|;
name|save
index|[
literal|0
index|]
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
name|save
index|[
literal|1
index|]
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
name|save
index|[
literal|0
index|]
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
name|save
index|[
literal|1
index|]
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* WRITE_16BIT */
block|}
elseif|else
if|if
condition|(
name|row_info
operator|->
name|color_type
operator|==
name|PNG_COLOR_TYPE_GRAY_ALPHA
condition|)
block|{
if|if
condition|(
name|row_info
operator|->
name|bit_depth
operator|==
literal|8
condition|)
block|{
comment|/* This converts from AG to GA */
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|sp
operator|=
name|dp
operator|=
name|row
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
name|png_byte
name|save
init|=
operator|*
operator|(
name|sp
operator|++
operator|)
decl_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
name|save
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|PNG_WRITE_16BIT_SUPPORTED
else|else
block|{
comment|/* This converts from AAGG to GGAA */
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|sp
operator|=
name|dp
operator|=
name|row
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
name|png_byte
name|save
index|[
literal|2
index|]
decl_stmt|;
name|save
index|[
literal|0
index|]
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
name|save
index|[
literal|1
index|]
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
name|save
index|[
literal|0
index|]
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
name|save
index|[
literal|1
index|]
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* WRITE_16BIT */
block|}
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_WRITE_INVERT_ALPHA_SUPPORTED
end_ifdef
begin_function
specifier|static
name|void
DECL|function|png_do_write_invert_alpha
name|png_do_write_invert_alpha
parameter_list|(
name|png_row_infop
name|row_info
parameter_list|,
name|png_bytep
name|row
parameter_list|)
block|{
name|png_debug
argument_list|(
literal|1
argument_list|,
literal|"in png_do_write_invert_alpha"
argument_list|)
expr_stmt|;
block|{
if|if
condition|(
name|row_info
operator|->
name|color_type
operator|==
name|PNG_COLOR_TYPE_RGB_ALPHA
condition|)
block|{
if|if
condition|(
name|row_info
operator|->
name|bit_depth
operator|==
literal|8
condition|)
block|{
comment|/* This inverts the alpha channel in RGBA */
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|sp
operator|=
name|dp
operator|=
name|row
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
comment|/* Does nothing                *(dp++) = *(sp++);                *(dp++) = *(sp++);                *(dp++) = *(sp++);                */
name|sp
operator|+=
literal|3
expr_stmt|;
name|dp
operator|=
name|sp
expr_stmt|;
operator|*
name|dp
operator|=
call|(
name|png_byte
call|)
argument_list|(
literal|255
operator|-
operator|*
operator|(
name|sp
operator|++
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|PNG_WRITE_16BIT_SUPPORTED
else|else
block|{
comment|/* This inverts the alpha channel in RRGGBBAA */
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|sp
operator|=
name|dp
operator|=
name|row
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
comment|/* Does nothing                *(dp++) = *(sp++);                *(dp++) = *(sp++);                *(dp++) = *(sp++);                *(dp++) = *(sp++);                *(dp++) = *(sp++);                *(dp++) = *(sp++);                */
name|sp
operator|+=
literal|6
expr_stmt|;
name|dp
operator|=
name|sp
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
call|(
name|png_byte
call|)
argument_list|(
literal|255
operator|-
operator|*
operator|(
name|sp
operator|++
operator|)
argument_list|)
expr_stmt|;
operator|*
name|dp
operator|=
call|(
name|png_byte
call|)
argument_list|(
literal|255
operator|-
operator|*
operator|(
name|sp
operator|++
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* WRITE_16BIT */
block|}
elseif|else
if|if
condition|(
name|row_info
operator|->
name|color_type
operator|==
name|PNG_COLOR_TYPE_GRAY_ALPHA
condition|)
block|{
if|if
condition|(
name|row_info
operator|->
name|bit_depth
operator|==
literal|8
condition|)
block|{
comment|/* This inverts the alpha channel in GA */
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|sp
operator|=
name|dp
operator|=
name|row
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
operator|*
operator|(
name|sp
operator|++
operator|)
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
call|(
name|png_byte
call|)
argument_list|(
literal|255
operator|-
operator|*
operator|(
name|sp
operator|++
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|PNG_WRITE_16BIT_SUPPORTED
else|else
block|{
comment|/* This inverts the alpha channel in GGAA */
name|png_bytep
name|sp
decl_stmt|,
name|dp
decl_stmt|;
name|png_uint_32
name|i
decl_stmt|;
name|png_uint_32
name|row_width
init|=
name|row_info
operator|->
name|width
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|sp
operator|=
name|dp
operator|=
name|row
init|;
name|i
operator|<
name|row_width
condition|;
name|i
operator|++
control|)
block|{
comment|/* Does nothing                *(dp++) = *(sp++);                *(dp++) = *(sp++);                */
name|sp
operator|+=
literal|2
expr_stmt|;
name|dp
operator|=
name|sp
expr_stmt|;
operator|*
operator|(
name|dp
operator|++
operator|)
operator|=
call|(
name|png_byte
call|)
argument_list|(
literal|255
operator|-
operator|*
operator|(
name|sp
operator|++
operator|)
argument_list|)
expr_stmt|;
operator|*
name|dp
operator|=
call|(
name|png_byte
call|)
argument_list|(
literal|255
operator|-
operator|*
operator|(
name|sp
operator|++
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* WRITE_16BIT */
block|}
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Transform the data according to the user's wishes.  The order of  * transformations is significant.  */
end_comment
begin_function
name|void
comment|/* PRIVATE */
DECL|function|png_do_write_transformations
name|png_do_write_transformations
parameter_list|(
name|png_structrp
name|png_ptr
parameter_list|,
name|png_row_infop
name|row_info
parameter_list|)
block|{
name|png_debug
argument_list|(
literal|1
argument_list|,
literal|"in png_do_write_transformations"
argument_list|)
expr_stmt|;
if|if
condition|(
name|png_ptr
operator|==
name|NULL
condition|)
return|return;
ifdef|#
directive|ifdef
name|PNG_WRITE_USER_TRANSFORM_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|transformations
operator|&
name|PNG_USER_TRANSFORM
operator|)
operator|!=
literal|0
condition|)
if|if
condition|(
name|png_ptr
operator|->
name|write_user_transform_fn
operator|!=
name|NULL
condition|)
operator|(
operator|*
operator|(
name|png_ptr
operator|->
name|write_user_transform_fn
operator|)
operator|)
comment|/* User write transform                                                  function */
operator|(
name|png_ptr
operator|,
comment|/* png_ptr */
name|row_info
operator|,
comment|/* row_info: */
comment|/*  png_uint_32 width;       width of row */
comment|/*  png_size_t rowbytes;     number of bytes in row */
comment|/*  png_byte color_type;     color type of pixels */
comment|/*  png_byte bit_depth;      bit depth of samples */
comment|/*  png_byte channels;       number of channels (1-4) */
comment|/*  png_byte pixel_depth;    bits per pixel (depth*channels) */
name|png_ptr
operator|->
name|row_buf
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* start of pixel data for row */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_FILLER_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|transformations
operator|&
name|PNG_FILLER
operator|)
operator|!=
literal|0
condition|)
name|png_do_strip_channel
argument_list|(
name|row_info
argument_list|,
name|png_ptr
operator|->
name|row_buf
operator|+
literal|1
argument_list|,
operator|!
operator|(
name|png_ptr
operator|->
name|flags
operator|&
name|PNG_FLAG_FILLER_AFTER
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_PACKSWAP_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|transformations
operator|&
name|PNG_PACKSWAP
operator|)
operator|!=
literal|0
condition|)
name|png_do_packswap
argument_list|(
name|row_info
argument_list|,
name|png_ptr
operator|->
name|row_buf
operator|+
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_PACK_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|transformations
operator|&
name|PNG_PACK
operator|)
operator|!=
literal|0
condition|)
name|png_do_pack
argument_list|(
name|row_info
argument_list|,
name|png_ptr
operator|->
name|row_buf
operator|+
literal|1
argument_list|,
operator|(
name|png_uint_32
operator|)
name|png_ptr
operator|->
name|bit_depth
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_SWAP_SUPPORTED
ifdef|#
directive|ifdef
name|PNG_16BIT_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|transformations
operator|&
name|PNG_SWAP_BYTES
operator|)
operator|!=
literal|0
condition|)
name|png_do_swap
argument_list|(
name|row_info
argument_list|,
name|png_ptr
operator|->
name|row_buf
operator|+
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_SHIFT_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|transformations
operator|&
name|PNG_SHIFT
operator|)
operator|!=
literal|0
condition|)
name|png_do_shift
argument_list|(
name|row_info
argument_list|,
name|png_ptr
operator|->
name|row_buf
operator|+
literal|1
argument_list|,
operator|&
operator|(
name|png_ptr
operator|->
name|shift
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_SWAP_ALPHA_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|transformations
operator|&
name|PNG_SWAP_ALPHA
operator|)
operator|!=
literal|0
condition|)
name|png_do_write_swap_alpha
argument_list|(
name|row_info
argument_list|,
name|png_ptr
operator|->
name|row_buf
operator|+
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_INVERT_ALPHA_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|transformations
operator|&
name|PNG_INVERT_ALPHA
operator|)
operator|!=
literal|0
condition|)
name|png_do_write_invert_alpha
argument_list|(
name|row_info
argument_list|,
name|png_ptr
operator|->
name|row_buf
operator|+
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_BGR_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|transformations
operator|&
name|PNG_BGR
operator|)
operator|!=
literal|0
condition|)
name|png_do_bgr
argument_list|(
name|row_info
argument_list|,
name|png_ptr
operator|->
name|row_buf
operator|+
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_INVERT_SUPPORTED
if|if
condition|(
operator|(
name|png_ptr
operator|->
name|transformations
operator|&
name|PNG_INVERT_MONO
operator|)
operator|!=
literal|0
condition|)
name|png_do_invert
argument_list|(
name|row_info
argument_list|,
name|png_ptr
operator|->
name|row_buf
operator|+
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* WRITE_TRANSFORMS */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* WRITE */
end_comment
end_unit
