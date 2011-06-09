begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbimage.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QColor>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qimage_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qdrawhelper_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_RENDER
end_ifdef
begin_include
include|#
directive|include
file|<xcb/render.h>
end_include
begin_comment
comment|// 'template' is used as a function argument name in xcb_renderutil.h
end_comment
begin_define
DECL|macro|template
define|#
directive|define
name|template
value|template_param
end_define
begin_comment
comment|// extern "C" is missing too
end_comment
begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|<xcb/xcb_renderutil.h>
block|}
end_extern
begin_undef
DECL|macro|template
undef|#
directive|undef
name|template
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|qt_xcb_imageFormatForVisual
name|QImage
operator|::
name|Format
name|qt_xcb_imageFormatForVisual
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|uint8_t
name|depth
parameter_list|,
specifier|const
name|xcb_visualtype_t
modifier|*
name|visual
parameter_list|)
block|{
specifier|const
name|xcb_format_t
modifier|*
name|format
init|=
name|connection
operator|->
name|formatForDepth
argument_list|(
name|depth
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|visual
operator|||
operator|!
name|format
condition|)
return|return
name|QImage
operator|::
name|Format_Invalid
return|;
if|if
condition|(
name|depth
operator|==
literal|32
operator|&&
name|format
operator|->
name|bits_per_pixel
operator|==
literal|32
operator|&&
name|visual
operator|->
name|red_mask
operator|==
literal|0xff0000
operator|&&
name|visual
operator|->
name|green_mask
operator|==
literal|0xff00
operator|&&
name|visual
operator|->
name|blue_mask
operator|==
literal|0xff
condition|)
return|return
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
return|;
if|if
condition|(
name|depth
operator|==
literal|24
operator|&&
name|format
operator|->
name|bits_per_pixel
operator|==
literal|32
operator|&&
name|visual
operator|->
name|red_mask
operator|==
literal|0xff0000
operator|&&
name|visual
operator|->
name|green_mask
operator|==
literal|0xff00
operator|&&
name|visual
operator|->
name|blue_mask
operator|==
literal|0xff
condition|)
return|return
name|QImage
operator|::
name|Format_RGB32
return|;
if|if
condition|(
name|depth
operator|==
literal|16
operator|&&
name|format
operator|->
name|bits_per_pixel
operator|==
literal|16
operator|&&
name|visual
operator|->
name|red_mask
operator|==
literal|0xf800
operator|&&
name|visual
operator|->
name|green_mask
operator|==
literal|0x7e0
operator|&&
name|visual
operator|->
name|blue_mask
operator|==
literal|0x1f
condition|)
return|return
name|QImage
operator|::
name|Format_RGB16
return|;
return|return
name|QImage
operator|::
name|Format_Invalid
return|;
block|}
end_function
begin_function
DECL|function|qt_xcb_pixmapFromXPixmap
name|QPixmap
name|qt_xcb_pixmapFromXPixmap
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|xcb_pixmap_t
name|pixmap
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|depth
parameter_list|,
specifier|const
name|xcb_visualtype_t
modifier|*
name|visual
parameter_list|)
block|{
name|xcb_connection_t
modifier|*
name|conn
init|=
name|connection
operator|->
name|xcb_connection
argument_list|()
decl_stmt|;
name|xcb_generic_error_t
modifier|*
name|error
init|=
literal|0
decl_stmt|;
name|xcb_get_image_cookie_t
name|get_image_cookie
init|=
name|xcb_get_image
argument_list|(
name|conn
argument_list|,
name|XCB_IMAGE_FORMAT_Z_PIXMAP
argument_list|,
name|pixmap
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
literal|0xffffffff
argument_list|)
decl_stmt|;
name|xcb_get_image_reply_t
modifier|*
name|image_reply
init|=
name|xcb_get_image_reply
argument_list|(
name|conn
argument_list|,
name|get_image_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|image_reply
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|connection
operator|->
name|handleXcbError
argument_list|(
name|error
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
return|return
name|QPixmap
argument_list|()
return|;
block|}
name|uint8_t
modifier|*
name|data
init|=
name|xcb_get_image_data
argument_list|(
name|image_reply
argument_list|)
decl_stmt|;
name|uint32_t
name|length
init|=
name|xcb_get_image_data_length
argument_list|(
name|image_reply
argument_list|)
decl_stmt|;
name|QPixmap
name|result
decl_stmt|;
name|QImage
operator|::
name|Format
name|format
init|=
name|qt_xcb_imageFormatForVisual
argument_list|(
name|connection
argument_list|,
name|depth
argument_list|,
name|visual
argument_list|)
decl_stmt|;
if|if
condition|(
name|format
operator|!=
name|QImage
operator|::
name|Format_Invalid
condition|)
block|{
name|uint32_t
name|bytes_per_line
init|=
name|length
operator|/
name|height
decl_stmt|;
name|QImage
name|image
argument_list|(
cast|const_cast
argument_list|<
name|uint8_t
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|bytes_per_line
argument_list|,
name|format
argument_list|)
decl_stmt|;
name|uint8_t
name|image_byte_order
init|=
name|connection
operator|->
name|setup
argument_list|()
operator|->
name|image_byte_order
decl_stmt|;
comment|// we may have to swap the byte order
if|if
condition|(
operator|(
name|QSysInfo
operator|::
name|ByteOrder
operator|==
name|QSysInfo
operator|::
name|LittleEndian
operator|&&
name|image_byte_order
operator|==
name|XCB_IMAGE_ORDER_MSB_FIRST
operator|)
operator|||
operator|(
name|QSysInfo
operator|::
name|ByteOrder
operator|==
name|QSysInfo
operator|::
name|BigEndian
operator|&&
name|image_byte_order
operator|==
name|XCB_IMAGE_ORDER_LSB_FIRST
operator|)
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|image
operator|.
name|height
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|format
condition|)
block|{
case|case
name|QImage
operator|::
name|Format_RGB16
case|:
block|{
name|ushort
modifier|*
name|p
init|=
operator|(
name|ushort
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|ushort
modifier|*
name|end
init|=
name|p
operator|+
name|image
operator|.
name|width
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|<
name|end
condition|)
block|{
operator|*
name|p
operator|=
operator|(
operator|(
operator|*
name|p
operator|<<
literal|8
operator|)
operator|&
literal|0xff00
operator|)
operator||
operator|(
operator|(
operator|*
name|p
operator|>>
literal|8
operator|)
operator|&
literal|0x00ff
operator|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
break|break;
block|}
case|case
name|QImage
operator|::
name|Format_RGB32
case|:
comment|// fall-through
case|case
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
case|:
block|{
name|uint
modifier|*
name|p
init|=
operator|(
name|uint
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|uint
modifier|*
name|end
init|=
name|p
operator|+
name|image
operator|.
name|width
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
operator|<
name|end
condition|)
block|{
operator|*
name|p
operator|=
operator|(
operator|(
operator|*
name|p
operator|<<
literal|24
operator|)
operator|&
literal|0xff000000
operator|)
operator||
operator|(
operator|(
operator|*
name|p
operator|<<
literal|8
operator|)
operator|&
literal|0x00ff0000
operator|)
operator||
operator|(
operator|(
operator|*
name|p
operator|>>
literal|8
operator|)
operator|&
literal|0x0000ff00
operator|)
operator||
operator|(
operator|(
operator|*
name|p
operator|>>
literal|24
operator|)
operator|&
literal|0x000000ff
operator|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
break|break;
block|}
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|// fix-up alpha channel
if|if
condition|(
name|format
operator|==
name|QImage
operator|::
name|Format_RGB32
condition|)
block|{
name|QRgb
modifier|*
name|p
init|=
operator|(
name|QRgb
operator|*
operator|)
name|image
operator|.
name|bits
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|height
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|width
condition|;
operator|++
name|x
control|)
name|p
index|[
name|x
index|]
operator||=
literal|0xff000000
expr_stmt|;
name|p
operator|+=
name|bytes_per_line
operator|/
literal|4
expr_stmt|;
block|}
block|}
name|result
operator|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
operator|.
name|copy
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|image_reply
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|qt_xcb_XPixmapFromBitmap
name|xcb_pixmap_t
name|qt_xcb_XPixmapFromBitmap
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|xcb_connection_t
modifier|*
name|conn
init|=
name|screen
operator|->
name|xcb_connection
argument_list|()
decl_stmt|;
name|QImage
name|bitmap
init|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_MonoLSB
argument_list|)
decl_stmt|;
specifier|const
name|QRgb
name|c0
init|=
name|QColor
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
operator|.
name|rgb
argument_list|()
decl_stmt|;
specifier|const
name|QRgb
name|c1
init|=
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
operator|.
name|rgb
argument_list|()
decl_stmt|;
if|if
condition|(
name|bitmap
operator|.
name|color
argument_list|(
literal|0
argument_list|)
operator|==
name|c0
operator|&&
name|bitmap
operator|.
name|color
argument_list|(
literal|1
argument_list|)
operator|==
name|c1
condition|)
block|{
name|bitmap
operator|.
name|invertPixels
argument_list|()
expr_stmt|;
name|bitmap
operator|.
name|setColor
argument_list|(
literal|0
argument_list|,
name|c1
argument_list|)
expr_stmt|;
name|bitmap
operator|.
name|setColor
argument_list|(
literal|1
argument_list|,
name|c0
argument_list|)
expr_stmt|;
block|}
specifier|const
name|int
name|width
init|=
name|bitmap
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|height
init|=
name|bitmap
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|int
name|bytesPerLine
init|=
name|bitmap
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
name|int
name|destLineSize
init|=
name|width
operator|/
literal|8
decl_stmt|;
if|if
condition|(
name|width
operator|%
literal|8
condition|)
operator|++
name|destLineSize
expr_stmt|;
specifier|const
name|uchar
modifier|*
name|map
init|=
name|bitmap
operator|.
name|bits
argument_list|()
decl_stmt|;
name|uint8_t
modifier|*
name|buf
init|=
operator|new
name|uint8_t
index|[
name|height
operator|*
name|destLineSize
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|height
condition|;
name|i
operator|++
control|)
name|memcpy
argument_list|(
name|buf
operator|+
operator|(
name|destLineSize
operator|*
name|i
operator|)
argument_list|,
name|map
operator|+
operator|(
name|bytesPerLine
operator|*
name|i
operator|)
argument_list|,
name|destLineSize
argument_list|)
expr_stmt|;
name|xcb_pixmap_t
name|pm
init|=
name|xcb_create_pixmap_from_bitmap_data
argument_list|(
name|conn
argument_list|,
name|screen
operator|->
name|root
argument_list|()
argument_list|,
name|buf
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
operator|delete
index|[]
name|buf
expr_stmt|;
return|return
name|pm
return|;
block|}
end_function
begin_function
DECL|function|qt_xcb_createCursorXRender
name|xcb_cursor_t
name|qt_xcb_createCursorXRender
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|spot
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|XCB_USE_RENDER
name|xcb_connection_t
modifier|*
name|conn
init|=
name|screen
operator|->
name|xcb_connection
argument_list|()
decl_stmt|;
specifier|const
name|int
name|w
init|=
name|image
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|h
init|=
name|image
operator|.
name|height
argument_list|()
decl_stmt|;
name|xcb_generic_error_t
modifier|*
name|error
init|=
literal|0
decl_stmt|;
name|xcb_render_query_pict_formats_cookie_t
name|formatsCookie
init|=
name|xcb_render_query_pict_formats
argument_list|(
name|conn
argument_list|)
decl_stmt|;
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|formatsReply
init|=
name|xcb_render_query_pict_formats_reply
argument_list|(
name|conn
argument_list|,
name|formatsCookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|formatsReply
operator|||
name|error
condition|)
block|{
name|qWarning
argument_list|(
literal|"createCursorXRender: query_pict_formats failed"
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|formatsReply
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
name|XCB_NONE
return|;
block|}
name|xcb_render_pictforminfo_t
modifier|*
name|fmt
init|=
name|xcb_render_util_find_standard_format
argument_list|(
name|formatsReply
argument_list|,
name|XCB_PICT_STANDARD_ARGB_32
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fmt
condition|)
block|{
name|qWarning
argument_list|(
literal|"createCursorXRender: Failed to find format PICT_STANDARD_ARGB_32"
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|formatsReply
argument_list|)
expr_stmt|;
return|return
name|XCB_NONE
return|;
block|}
name|QImage
name|img
init|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|xcb_image_t
modifier|*
name|xi
init|=
name|xcb_image_create
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
name|XCB_IMAGE_FORMAT_Z_PIXMAP
argument_list|,
literal|32
argument_list|,
literal|32
argument_list|,
literal|32
argument_list|,
literal|32
argument_list|,
name|QSysInfo
operator|::
name|ByteOrder
operator|==
name|QSysInfo
operator|::
name|BigEndian
condition|?
name|XCB_IMAGE_ORDER_MSB_FIRST
else|:
name|XCB_IMAGE_ORDER_LSB_FIRST
argument_list|,
name|XCB_IMAGE_ORDER_MSB_FIRST
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|xi
condition|)
block|{
name|qWarning
argument_list|(
literal|"createCursorXRender: xcb_image_create failed"
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|formatsReply
argument_list|)
expr_stmt|;
return|return
name|XCB_NONE
return|;
block|}
name|xi
operator|->
name|data
operator|=
operator|(
name|uint8_t
operator|*
operator|)
name|malloc
argument_list|(
name|xi
operator|->
name|stride
operator|*
name|h
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|xi
operator|->
name|data
condition|)
block|{
name|qWarning
argument_list|(
literal|"createCursorXRender: Failed to malloc() image data"
argument_list|)
expr_stmt|;
name|xcb_image_destroy
argument_list|(
name|xi
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|formatsReply
argument_list|)
expr_stmt|;
return|return
name|XCB_NONE
return|;
block|}
name|memcpy
argument_list|(
name|xi
operator|->
name|data
argument_list|,
name|img
operator|.
name|constBits
argument_list|()
argument_list|,
name|img
operator|.
name|byteCount
argument_list|()
argument_list|)
expr_stmt|;
name|xcb_pixmap_t
name|pix
init|=
name|xcb_generate_id
argument_list|(
name|conn
argument_list|)
decl_stmt|;
name|xcb_create_pixmap
argument_list|(
name|conn
argument_list|,
literal|32
argument_list|,
name|pix
argument_list|,
name|screen
operator|->
name|root
argument_list|()
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|xcb_render_picture_t
name|pic
init|=
name|xcb_generate_id
argument_list|(
name|conn
argument_list|)
decl_stmt|;
name|xcb_render_create_picture
argument_list|(
name|conn
argument_list|,
name|pic
argument_list|,
name|pix
argument_list|,
name|fmt
operator|->
name|id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|xcb_gcontext_t
name|gc
init|=
name|xcb_generate_id
argument_list|(
name|conn
argument_list|)
decl_stmt|;
name|xcb_create_gc
argument_list|(
name|conn
argument_list|,
name|gc
argument_list|,
name|pix
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|xcb_image_put
argument_list|(
name|conn
argument_list|,
name|pix
argument_list|,
name|gc
argument_list|,
name|xi
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|xcb_free_gc
argument_list|(
name|conn
argument_list|,
name|gc
argument_list|)
expr_stmt|;
name|xcb_cursor_t
name|cursor
init|=
name|xcb_generate_id
argument_list|(
name|conn
argument_list|)
decl_stmt|;
name|xcb_render_create_cursor
argument_list|(
name|conn
argument_list|,
name|cursor
argument_list|,
name|pic
argument_list|,
name|spot
operator|.
name|x
argument_list|()
argument_list|,
name|spot
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|xi
operator|->
name|data
argument_list|)
expr_stmt|;
name|xcb_image_destroy
argument_list|(
name|xi
argument_list|)
expr_stmt|;
name|xcb_render_free_picture
argument_list|(
name|conn
argument_list|,
name|pic
argument_list|)
expr_stmt|;
name|xcb_free_pixmap
argument_list|(
name|conn
argument_list|,
name|pix
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|formatsReply
argument_list|)
expr_stmt|;
return|return
name|cursor
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|image
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|spot
argument_list|)
expr_stmt|;
return|return
name|XCB_NONE
return|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
