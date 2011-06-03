begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qxcbconnection.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxcbwindowsurface.h"
end_include
begin_include
include|#
directive|include
file|"qxcbnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qxcbclipboard.h"
end_include
begin_include
include|#
directive|include
file|<qsimpledrag.h>
end_include
begin_include
include|#
directive|include
file|<qgenericunixprintersupport.h>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|<private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|"qgenericunixfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_EGL
end_ifdef
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QXcbIntegration
name|QXcbIntegration
operator|::
name|QXcbIntegration
parameter_list|()
member_init_list|:
name|m_connection
argument_list|(
operator|new
name|QXcbConnection
argument_list|)
member_init_list|,
name|m_printerSupport
argument_list|(
operator|new
name|QGenericUnixPrinterSupport
argument_list|)
block|{
foreach|foreach
control|(
name|QXcbScreen
modifier|*
name|screen
decl|,
name|m_connection
operator|->
name|screens
argument_list|()
control|)
name|m_screens
operator|<<
name|screen
expr_stmt|;
name|m_fontDatabase
operator|=
operator|new
name|QGenericUnixFontDatabase
argument_list|()
expr_stmt|;
name|m_nativeInterface
operator|=
operator|new
name|QXcbNativeInterface
expr_stmt|;
name|m_drag
operator|=
operator|new
name|QSimpleDrag
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QXcbIntegration
name|QXcbIntegration
operator|::
name|~
name|QXcbIntegration
parameter_list|()
block|{
operator|delete
name|m_connection
expr_stmt|;
operator|delete
name|m_drag
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hasCapability
name|bool
name|QXcbIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
case|case
name|OpenGL
case|:
return|return
name|hasOpenGL
argument_list|()
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPixmapData
name|QPixmapData
modifier|*
name|QXcbIntegration
operator|::
name|createPixmapData
parameter_list|(
name|QPixmapData
operator|::
name|PixelType
name|type
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QRasterPixmapData
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QXcbIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QXcbWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createWindowSurface
name|QWindowSurface
modifier|*
name|QXcbIntegration
operator|::
name|createWindowSurface
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|WId
name|winId
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|winId
argument_list|)
expr_stmt|;
return|return
operator|new
name|QXcbWindowSurface
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|screens
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|QXcbIntegration
operator|::
name|screens
parameter_list|()
specifier|const
block|{
return|return
name|m_screens
return|;
block|}
end_function
begin_function
DECL|function|moveToScreen
name|void
name|QXcbIntegration
operator|::
name|moveToScreen
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|int
name|screen
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isVirtualDesktop
name|bool
name|QXcbIntegration
operator|::
name|isVirtualDesktop
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QXcbIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|m_fontDatabase
return|;
block|}
end_function
begin_function
DECL|function|imageFormatForVisual
specifier|static
name|QImage
operator|::
name|Format
name|imageFormatForVisual
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
DECL|function|grabWindow
name|QPixmap
name|QXcbIntegration
operator|::
name|grabWindow
parameter_list|(
name|WId
name|window
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|width
operator|==
literal|0
operator|||
name|height
operator|==
literal|0
condition|)
return|return
name|QPixmap
argument_list|()
return|;
name|xcb_connection_t
modifier|*
name|connection
init|=
name|m_connection
operator|->
name|xcb_connection
argument_list|()
decl_stmt|;
name|xcb_get_geometry_cookie_t
name|geometry_cookie
init|=
name|xcb_get_geometry
argument_list|(
name|connection
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|xcb_generic_error_t
modifier|*
name|error
decl_stmt|;
name|xcb_get_geometry_reply_t
modifier|*
name|reply
init|=
name|xcb_get_geometry_reply
argument_list|(
name|connection
argument_list|,
name|geometry_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|m_connection
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
if|if
condition|(
name|width
operator|<
literal|0
condition|)
name|width
operator|=
name|reply
operator|->
name|width
operator|-
name|x
expr_stmt|;
if|if
condition|(
name|height
operator|<
literal|0
condition|)
name|height
operator|=
name|reply
operator|->
name|height
operator|-
name|y
expr_stmt|;
comment|// TODO: handle multiple screens
name|QXcbScreen
modifier|*
name|screen
init|=
name|m_connection
operator|->
name|screens
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|xcb_window_t
name|root
init|=
name|screen
operator|->
name|root
argument_list|()
decl_stmt|;
name|geometry_cookie
operator|=
name|xcb_get_geometry
argument_list|(
name|connection
argument_list|,
name|root
argument_list|)
expr_stmt|;
name|xcb_get_geometry_reply_t
modifier|*
name|root_reply
init|=
name|xcb_get_geometry_reply
argument_list|(
name|connection
argument_list|,
name|geometry_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|root_reply
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|m_connection
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
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
if|if
condition|(
name|reply
operator|->
name|depth
operator|==
name|root_reply
operator|->
name|depth
condition|)
block|{
comment|// if the depth of the specified window and the root window are the
comment|// same, grab pixels from the root window (so that we get the any
comment|// overlapping windows and window manager frames)
comment|// map x and y to the root window
name|xcb_translate_coordinates_cookie_t
name|translate_cookie
init|=
name|xcb_translate_coordinates
argument_list|(
name|connection
argument_list|,
name|window
argument_list|,
name|root
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|xcb_translate_coordinates_reply_t
modifier|*
name|translate_reply
init|=
name|xcb_translate_coordinates_reply
argument_list|(
name|connection
argument_list|,
name|translate_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|translate_reply
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|m_connection
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
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|root_reply
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
name|x
operator|=
name|translate_reply
operator|->
name|dst_x
expr_stmt|;
name|y
operator|=
name|translate_reply
operator|->
name|dst_y
expr_stmt|;
name|window
operator|=
name|root
expr_stmt|;
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
name|reply
operator|=
name|root_reply
expr_stmt|;
block|}
else|else
block|{
name|free
argument_list|(
name|root_reply
argument_list|)
expr_stmt|;
name|root_reply
operator|=
literal|0
expr_stmt|;
block|}
name|xcb_get_window_attributes_reply_t
modifier|*
name|attributes_reply
init|=
name|xcb_get_window_attributes_reply
argument_list|(
name|connection
argument_list|,
name|xcb_get_window_attributes
argument_list|(
name|connection
argument_list|,
name|window
argument_list|)
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|attributes_reply
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|m_connection
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
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
specifier|const
name|xcb_visualtype_t
modifier|*
name|visual
init|=
name|screen
operator|->
name|visualForId
argument_list|(
name|attributes_reply
operator|->
name|visual
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|attributes_reply
argument_list|)
expr_stmt|;
name|xcb_pixmap_t
name|pixmap
init|=
name|xcb_generate_id
argument_list|(
name|connection
argument_list|)
decl_stmt|;
name|error
operator|=
name|xcb_request_check
argument_list|(
name|connection
argument_list|,
name|xcb_create_pixmap_checked
argument_list|(
name|connection
argument_list|,
name|reply
operator|->
name|depth
argument_list|,
name|pixmap
argument_list|,
name|window
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|m_connection
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
name|uint32_t
name|gc_value_mask
init|=
name|XCB_GC_SUBWINDOW_MODE
decl_stmt|;
name|uint32_t
name|gc_value_list
index|[]
init|=
block|{
name|XCB_SUBWINDOW_MODE_INCLUDE_INFERIORS
block|}
decl_stmt|;
name|xcb_gcontext_t
name|gc
init|=
name|xcb_generate_id
argument_list|(
name|connection
argument_list|)
decl_stmt|;
name|xcb_create_gc
argument_list|(
name|connection
argument_list|,
name|gc
argument_list|,
name|pixmap
argument_list|,
name|gc_value_mask
argument_list|,
name|gc_value_list
argument_list|)
expr_stmt|;
name|error
operator|=
name|xcb_request_check
argument_list|(
name|connection
argument_list|,
name|xcb_copy_area_checked
argument_list|(
name|connection
argument_list|,
name|window
argument_list|,
name|pixmap
argument_list|,
name|gc
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|m_connection
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
name|xcb_get_image_cookie_t
name|get_image_cookie
init|=
name|xcb_get_image
argument_list|(
name|connection
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
name|connection
argument_list|,
name|get_image_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
name|xcb_free_gc
argument_list|(
name|connection
argument_list|,
name|gc
argument_list|)
expr_stmt|;
name|xcb_free_pixmap
argument_list|(
name|connection
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|uint8_t
name|depth
init|=
name|reply
operator|->
name|depth
decl_stmt|;
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
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
name|m_connection
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
name|imageFormatForVisual
argument_list|(
name|m_connection
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
name|m_connection
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
name|image
operator|.
name|detach
argument_list|()
expr_stmt|;
name|result
operator|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
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
DECL|function|hasOpenGL
name|bool
name|QXcbIntegration
operator|::
name|hasOpenGL
parameter_list|()
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
return|return
literal|true
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
return|return
name|m_connection
operator|->
name|hasEgl
argument_list|()
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_DRI2
argument_list|)
if|if
condition|(
name|m_connection
operator|->
name|hasSupportForDri2
argument_list|()
condition|)
block|{
return|return
literal|true
return|;
block|}
endif|#
directive|endif
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QXcbIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
name|m_nativeInterface
return|;
block|}
end_function
begin_function
DECL|function|printerSupport
name|QPlatformPrinterSupport
modifier|*
name|QXcbIntegration
operator|::
name|printerSupport
parameter_list|()
specifier|const
block|{
return|return
name|m_printerSupport
return|;
block|}
end_function
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QXcbIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
return|return
name|m_connection
operator|->
name|clipboard
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|drag
name|QPlatformDrag
modifier|*
name|QXcbIntegration
operator|::
name|drag
parameter_list|()
specifier|const
block|{
return|return
name|m_drag
return|;
block|}
end_function
end_unit
