begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|__XCB_PIXEL_H__
end_ifndef
begin_define
DECL|macro|__XCB_PIXEL_H__
define|#
directive|define
name|__XCB_PIXEL_H__
end_define
begin_comment
comment|/* Copyright (C) 2007 Bart Massey  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *   * Except as contained in this notice, the names of the authors or their  * institutions shall not be used in advertising or otherwise to promote the  * sale, use or other dealings in this Software without prior written  * authorization from the authors.  */
end_comment
begin_include
include|#
directive|include
file|<inttypes.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|BUILD
end_ifndef
begin_include
include|#
directive|include
file|<xcb/xcb_bitops.h>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb_image.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/**  * XCB Image fast pixel ops.  *  * Fast inline versions of xcb_image_get_pixel() and  * xcb_image_put_pixel() for various common cases.  * The naming convention is xcb_image_put_pixel_FUB()  * where F is the format and is either XY for bitmaps  * or Z for pixmaps, U is the bitmap unit size or pixmap  * bits-per-pixel, and B is the endianness (if needed)  * and is either M for most-significant-first or L for  * least-significant-first.  Note that no checking  * is done on the arguments to these routines---caller beware.  * Also note that the pixel type is chosen to be appropriate  * to the unit; bitmaps use int and pixmaps use the appropriate  * size of unsigned.  * @ingroup xcb__image_t  */
end_comment
begin_function
name|_X_INLINE
specifier|static
name|void
DECL|function|xcb_image_put_pixel_XY32M
name|xcb_image_put_pixel_XY32M
parameter_list|(
name|xcb_image_t
modifier|*
name|image
parameter_list|,
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|,
name|int
name|pixel
parameter_list|)
block|{
name|uint32_t
name|unit
init|=
operator|(
name|x
operator|>>
literal|3
operator|)
operator|&
operator|~
name|xcb_mask
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|uint32_t
name|byte
init|=
name|xcb_mask
argument_list|(
literal|2
argument_list|)
operator|-
operator|(
operator|(
name|x
operator|>>
literal|3
operator|)
operator|&
name|xcb_mask
argument_list|(
literal|2
argument_list|)
operator|)
decl_stmt|;
name|uint32_t
name|bit
init|=
name|xcb_mask
argument_list|(
literal|3
argument_list|)
operator|-
operator|(
name|x
operator|&
name|xcb_mask
argument_list|(
literal|3
argument_list|)
operator|)
decl_stmt|;
name|uint8_t
name|m
init|=
literal|1
operator|<<
name|bit
decl_stmt|;
name|uint8_t
name|p
init|=
name|pixel
operator|<<
name|bit
decl_stmt|;
name|uint8_t
modifier|*
name|bp
init|=
name|image
operator|->
name|data
operator|+
operator|(
name|y
operator|*
name|image
operator|->
name|stride
operator|)
operator|+
operator|(
name|unit
operator||
name|byte
operator|)
decl_stmt|;
operator|*
name|bp
operator|=
operator|(
operator|*
name|bp
operator|&
operator|~
name|m
operator|)
operator||
name|p
expr_stmt|;
block|}
end_function
begin_function
name|_X_INLINE
specifier|static
name|void
DECL|function|xcb_image_put_pixel_XY32L
name|xcb_image_put_pixel_XY32L
parameter_list|(
name|xcb_image_t
modifier|*
name|image
parameter_list|,
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|,
name|int
name|pixel
parameter_list|)
block|{
name|uint32_t
name|bit
init|=
name|x
operator|&
name|xcb_mask
argument_list|(
literal|3
argument_list|)
decl_stmt|;
name|uint8_t
name|m
init|=
literal|1
operator|<<
name|bit
decl_stmt|;
name|uint8_t
name|p
init|=
name|pixel
operator|<<
name|bit
decl_stmt|;
name|uint8_t
modifier|*
name|bp
init|=
name|image
operator|->
name|data
operator|+
operator|(
name|y
operator|*
name|image
operator|->
name|stride
operator|)
operator|+
operator|(
name|x
operator|>>
literal|3
operator|)
decl_stmt|;
operator|*
name|bp
operator|=
operator|(
operator|*
name|bp
operator|&
operator|~
name|m
operator|)
operator||
name|p
expr_stmt|;
block|}
end_function
begin_function
name|_X_INLINE
specifier|static
name|int
DECL|function|xcb_image_get_pixel_XY32M
name|xcb_image_get_pixel_XY32M
parameter_list|(
name|xcb_image_t
modifier|*
name|image
parameter_list|,
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|)
block|{
name|uint32_t
name|unit
init|=
operator|(
name|x
operator|>>
literal|3
operator|)
operator|&
operator|~
name|xcb_mask
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|uint32_t
name|byte
init|=
name|xcb_mask
argument_list|(
literal|2
argument_list|)
operator|-
operator|(
operator|(
name|x
operator|>>
literal|3
operator|)
operator|&
name|xcb_mask
argument_list|(
literal|2
argument_list|)
operator|)
decl_stmt|;
name|uint32_t
name|bit
init|=
name|xcb_mask
argument_list|(
literal|3
argument_list|)
operator|-
operator|(
name|x
operator|&
name|xcb_mask
argument_list|(
literal|3
argument_list|)
operator|)
decl_stmt|;
name|uint8_t
modifier|*
name|bp
init|=
name|image
operator|->
name|data
operator|+
operator|(
name|y
operator|*
name|image
operator|->
name|stride
operator|)
operator|+
operator|(
name|unit
operator||
name|byte
operator|)
decl_stmt|;
return|return
operator|(
operator|*
name|bp
operator|>>
name|bit
operator|)
operator|&
literal|1
return|;
block|}
end_function
begin_function
name|_X_INLINE
specifier|static
name|int
DECL|function|xcb_image_get_pixel_XY32L
name|xcb_image_get_pixel_XY32L
parameter_list|(
name|xcb_image_t
modifier|*
name|image
parameter_list|,
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|)
block|{
name|uint32_t
name|bit
init|=
name|x
operator|&
name|xcb_mask
argument_list|(
literal|3
argument_list|)
decl_stmt|;
name|uint8_t
modifier|*
name|bp
init|=
name|image
operator|->
name|data
operator|+
operator|(
name|y
operator|*
name|image
operator|->
name|stride
operator|)
operator|+
operator|(
name|x
operator|>>
literal|3
operator|)
decl_stmt|;
return|return
operator|(
operator|*
name|bp
operator|>>
name|bit
operator|)
operator|&
literal|1
return|;
block|}
end_function
begin_function
name|_X_INLINE
specifier|static
name|void
DECL|function|xcb_image_put_pixel_Z8
name|xcb_image_put_pixel_Z8
parameter_list|(
name|xcb_image_t
modifier|*
name|image
parameter_list|,
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|,
name|uint8_t
name|pixel
parameter_list|)
block|{
name|image
operator|->
name|data
index|[
name|x
operator|+
name|y
operator|*
name|image
operator|->
name|stride
index|]
operator|=
name|pixel
expr_stmt|;
block|}
end_function
begin_function
name|_X_INLINE
specifier|static
name|uint8_t
DECL|function|xcb_image_get_pixel_Z8
name|xcb_image_get_pixel_Z8
parameter_list|(
name|xcb_image_t
modifier|*
name|image
parameter_list|,
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|)
block|{
return|return
name|image
operator|->
name|data
index|[
name|x
operator|+
name|y
operator|*
name|image
operator|->
name|stride
index|]
return|;
block|}
end_function
begin_function
name|_X_INLINE
specifier|static
name|void
DECL|function|xcb_image_put_pixel_Z32M
name|xcb_image_put_pixel_Z32M
parameter_list|(
name|xcb_image_t
modifier|*
name|image
parameter_list|,
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|,
name|uint32_t
name|pixel
parameter_list|)
block|{
name|uint8_t
modifier|*
name|row
init|=
name|image
operator|->
name|data
operator|+
operator|(
name|y
operator|*
name|image
operator|->
name|stride
operator|)
decl_stmt|;
name|row
index|[
name|x
operator|<<
literal|2
index|]
operator|=
name|pixel
operator|>>
literal|24
expr_stmt|;
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|1
index|]
operator|=
name|pixel
operator|>>
literal|16
expr_stmt|;
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|2
index|]
operator|=
name|pixel
operator|>>
literal|8
expr_stmt|;
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|3
index|]
operator|=
name|pixel
expr_stmt|;
block|}
end_function
begin_function
name|_X_INLINE
specifier|static
name|void
DECL|function|xcb_image_put_pixel_Z32L
name|xcb_image_put_pixel_Z32L
parameter_list|(
name|xcb_image_t
modifier|*
name|image
parameter_list|,
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|,
name|uint32_t
name|pixel
parameter_list|)
block|{
name|uint8_t
modifier|*
name|row
init|=
name|image
operator|->
name|data
operator|+
operator|(
name|y
operator|*
name|image
operator|->
name|stride
operator|)
decl_stmt|;
name|row
index|[
name|x
operator|<<
literal|2
index|]
operator|=
name|pixel
expr_stmt|;
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|1
index|]
operator|=
name|pixel
operator|>>
literal|8
expr_stmt|;
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|2
index|]
operator|=
name|pixel
operator|>>
literal|16
expr_stmt|;
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|3
index|]
operator|=
name|pixel
operator|>>
literal|24
expr_stmt|;
block|}
end_function
begin_function
name|_X_INLINE
specifier|static
name|uint32_t
DECL|function|xcb_image_get_pixel_Z32M
name|xcb_image_get_pixel_Z32M
parameter_list|(
name|xcb_image_t
modifier|*
name|image
parameter_list|,
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|)
block|{
name|uint8_t
modifier|*
name|row
init|=
name|image
operator|->
name|data
operator|+
operator|(
name|y
operator|*
name|image
operator|->
name|stride
operator|)
decl_stmt|;
name|uint32_t
name|pixel
init|=
name|row
index|[
name|x
operator|<<
literal|2
index|]
operator|<<
literal|24
decl_stmt|;
name|pixel
operator||=
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|1
index|]
operator|<<
literal|16
expr_stmt|;
name|pixel
operator||=
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|2
index|]
operator|<<
literal|8
expr_stmt|;
return|return
name|pixel
operator||
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|3
index|]
return|;
block|}
end_function
begin_function
name|_X_INLINE
specifier|static
name|uint32_t
DECL|function|xcb_image_get_pixel_Z32L
name|xcb_image_get_pixel_Z32L
parameter_list|(
name|xcb_image_t
modifier|*
name|image
parameter_list|,
name|uint32_t
name|x
parameter_list|,
name|uint32_t
name|y
parameter_list|)
block|{
name|uint8_t
modifier|*
name|row
init|=
name|image
operator|->
name|data
operator|+
operator|(
name|y
operator|*
name|image
operator|->
name|stride
operator|)
decl_stmt|;
name|uint32_t
name|pixel
init|=
name|row
index|[
name|x
operator|<<
literal|2
index|]
decl_stmt|;
name|pixel
operator||=
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|1
index|]
operator|<<
literal|8
expr_stmt|;
name|pixel
operator||=
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|2
index|]
operator|<<
literal|16
expr_stmt|;
return|return
name|pixel
operator||
name|row
index|[
operator|(
name|x
operator|<<
literal|2
operator|)
operator|+
literal|3
index|]
operator|<<
literal|24
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __XCB_PIXEL_H__ */
end_comment
end_unit
