begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpixmapdata_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qbuffer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qbitmap.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimagereader.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_qpa_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qimagepixmapcleanuphooks_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|qt_pixmap_bit_mask
specifier|const
name|uchar
name|qt_pixmap_bit_mask
index|[]
init|=
block|{
literal|0x01
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x20
block|,
literal|0x40
block|,
literal|0x80
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|create
name|QPixmapData
modifier|*
name|QPixmapData
operator|::
name|create
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|PixelType
name|type
parameter_list|)
block|{
name|QPixmapData
modifier|*
name|data
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|createPixmapData
argument_list|(
cast|static_cast
argument_list|<
name|QPixmapData
operator|::
name|PixelType
argument_list|>
argument_list|(
name|type
argument_list|)
argument_list|)
decl_stmt|;
name|data
operator|->
name|resize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
return|return
name|data
return|;
block|}
end_function
begin_constructor
DECL|function|QPixmapData
name|QPixmapData
operator|::
name|QPixmapData
parameter_list|(
name|PixelType
name|pixelType
parameter_list|,
name|int
name|objectId
parameter_list|)
member_init_list|:
name|w
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|h
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|is_null
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|ref
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|detach_no
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|type
argument_list|(
name|pixelType
argument_list|)
member_init_list|,
name|id
argument_list|(
name|objectId
argument_list|)
member_init_list|,
name|ser_no
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|is_cached
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QPixmapData
name|QPixmapData
operator|::
name|~
name|QPixmapData
parameter_list|()
block|{
comment|// Sometimes the pixmap cleanup hooks will be called from derrived classes, which will
comment|// then set is_cached to false. For example, on X11 QtOpenGL needs to delete the GLXPixmap
comment|// or EGL Pixmap Surface for a given pixmap _before_ the native X11 pixmap is deleted,
comment|// otherwise some drivers will leak the GL surface. In this case, QX11PixmapData will
comment|// call the cleanup hooks itself before deleting the native pixmap and set is_cached to
comment|// false.
if|if
condition|(
name|is_cached
condition|)
block|{
name|QImagePixmapCleanupHooks
operator|::
name|executePixmapDataDestructionHooks
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|is_cached
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|createCompatiblePixmapData
name|QPixmapData
modifier|*
name|QPixmapData
operator|::
name|createCompatiblePixmapData
parameter_list|()
specifier|const
block|{
name|QPixmapData
modifier|*
name|d
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|createPixmapData
argument_list|(
name|pixelType
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_function
DECL|function|makeBitmapCompliantIfNeeded
specifier|static
name|QImage
name|makeBitmapCompliantIfNeeded
parameter_list|(
name|QPixmapData
modifier|*
name|d
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|pixelType
argument_list|()
operator|==
name|QPixmapData
operator|::
name|BitmapType
condition|)
block|{
name|QImage
name|img
init|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_MonoLSB
argument_list|,
name|flags
argument_list|)
decl_stmt|;
comment|// make sure image.color(0) == Qt::color0 (white)
comment|// and image.color(1) == Qt::color1 (black)
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
name|img
operator|.
name|color
argument_list|(
literal|0
argument_list|)
operator|==
name|c0
operator|&&
name|img
operator|.
name|color
argument_list|(
literal|1
argument_list|)
operator|==
name|c1
condition|)
block|{
name|img
operator|.
name|invertPixels
argument_list|()
expr_stmt|;
name|img
operator|.
name|setColor
argument_list|(
literal|0
argument_list|,
name|c1
argument_list|)
expr_stmt|;
name|img
operator|.
name|setColor
argument_list|(
literal|1
argument_list|,
name|c0
argument_list|)
expr_stmt|;
block|}
return|return
name|img
return|;
block|}
return|return
name|image
return|;
block|}
end_function
begin_function
DECL|function|fromImageReader
name|void
name|QPixmapData
operator|::
name|fromImageReader
parameter_list|(
name|QImageReader
modifier|*
name|imageReader
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
parameter_list|)
block|{
specifier|const
name|QImage
name|image
init|=
name|imageReader
operator|->
name|read
argument_list|()
decl_stmt|;
name|fromImage
argument_list|(
name|image
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromFile
name|bool
name|QPixmapData
operator|::
name|fromFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
parameter_list|)
block|{
name|QImage
name|image
init|=
name|QImageReader
argument_list|(
name|fileName
argument_list|,
name|format
argument_list|)
operator|.
name|read
argument_list|()
decl_stmt|;
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|false
return|;
name|fromImage
argument_list|(
name|makeBitmapCompliantIfNeeded
argument_list|(
name|this
argument_list|,
name|image
argument_list|,
name|flags
argument_list|)
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
operator|!
name|isNull
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fromData
name|bool
name|QPixmapData
operator|::
name|fromData
parameter_list|(
specifier|const
name|uchar
modifier|*
name|buf
parameter_list|,
name|uint
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
parameter_list|)
block|{
name|QByteArray
name|a
init|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|buf
argument_list|)
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|QBuffer
name|b
argument_list|(
operator|&
name|a
argument_list|)
decl_stmt|;
name|b
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QImage
name|image
init|=
name|QImageReader
argument_list|(
operator|&
name|b
argument_list|,
name|format
argument_list|)
operator|.
name|read
argument_list|()
decl_stmt|;
name|fromImage
argument_list|(
name|makeBitmapCompliantIfNeeded
argument_list|(
name|this
argument_list|,
name|image
argument_list|,
name|flags
argument_list|)
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
operator|!
name|isNull
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|copy
name|void
name|QPixmapData
operator|::
name|copy
parameter_list|(
specifier|const
name|QPixmapData
modifier|*
name|data
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|fromImage
argument_list|(
name|data
operator|->
name|toImage
argument_list|(
name|rect
argument_list|)
argument_list|,
name|Qt
operator|::
name|NoOpaqueDetection
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scroll
name|bool
name|QPixmapData
operator|::
name|scroll
parameter_list|(
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|dx
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|dy
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|rect
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|setMask
name|void
name|QPixmapData
operator|::
name|setMask
parameter_list|(
specifier|const
name|QBitmap
modifier|&
name|mask
parameter_list|)
block|{
if|if
condition|(
name|mask
operator|.
name|size
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|depth
argument_list|()
operator|!=
literal|1
condition|)
name|fromImage
argument_list|(
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
argument_list|,
name|Qt
operator|::
name|AutoColor
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QImage
name|image
init|=
name|toImage
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
switch|switch
condition|(
name|image
operator|.
name|depth
argument_list|()
condition|)
block|{
case|case
literal|1
case|:
block|{
specifier|const
name|QImage
name|imageMask
init|=
name|mask
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|image
operator|.
name|format
argument_list|()
argument_list|)
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
name|h
condition|;
operator|++
name|y
control|)
block|{
specifier|const
name|uchar
modifier|*
name|mscan
init|=
name|imageMask
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
name|uchar
modifier|*
name|tscan
init|=
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
name|int
name|bytesPerLine
init|=
name|image
operator|.
name|bytesPerLine
argument_list|()
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
name|bytesPerLine
condition|;
operator|++
name|i
control|)
name|tscan
index|[
name|i
index|]
operator|&=
name|mscan
index|[
name|i
index|]
expr_stmt|;
block|}
break|break;
block|}
default|default:
block|{
specifier|const
name|QImage
name|imageMask
init|=
name|mask
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_MonoLSB
argument_list|)
decl_stmt|;
name|image
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
specifier|const
name|uchar
modifier|*
name|mscan
init|=
name|imageMask
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
name|QRgb
modifier|*
name|tscan
init|=
operator|(
name|QRgb
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
operator|!
operator|(
name|mscan
index|[
name|x
operator|>>
literal|3
index|]
operator|&
name|qt_pixmap_bit_mask
index|[
name|x
operator|&
literal|7
index|]
operator|)
condition|)
name|tscan
index|[
name|x
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
break|break;
block|}
block|}
name|fromImage
argument_list|(
name|image
argument_list|,
name|Qt
operator|::
name|AutoColor
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|mask
name|QBitmap
name|QPixmapData
operator|::
name|mask
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasAlphaChannel
argument_list|()
condition|)
return|return
name|QBitmap
argument_list|()
return|;
specifier|const
name|QImage
name|img
init|=
name|toImage
argument_list|()
decl_stmt|;
specifier|const
name|QImage
name|image
init|=
operator|(
name|img
operator|.
name|depth
argument_list|()
operator|<
literal|32
condition|?
name|img
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
else|:
name|img
operator|)
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
name|QImage
name|mask
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
name|QImage
operator|::
name|Format_MonoLSB
argument_list|)
decl_stmt|;
if|if
condition|(
name|mask
operator|.
name|isNull
argument_list|()
condition|)
comment|// allocation failed
return|return
name|QBitmap
argument_list|()
return|;
name|mask
operator|.
name|setColorCount
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setColor
argument_list|(
literal|0
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|color0
argument_list|)
operator|.
name|rgba
argument_list|()
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setColor
argument_list|(
literal|1
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|color1
argument_list|)
operator|.
name|rgba
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|int
name|bpl
init|=
name|mask
operator|.
name|bytesPerLine
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
name|h
condition|;
operator|++
name|y
control|)
block|{
specifier|const
name|QRgb
modifier|*
name|src
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|QRgb
operator|*
argument_list|>
argument_list|(
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
argument_list|)
decl_stmt|;
name|uchar
modifier|*
name|dest
init|=
name|mask
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|dest
argument_list|,
literal|0
argument_list|,
name|bpl
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
name|qAlpha
argument_list|(
operator|*
name|src
argument_list|)
operator|>
literal|0
condition|)
name|dest
index|[
name|x
operator|>>
literal|3
index|]
operator||=
name|qt_pixmap_bit_mask
index|[
name|x
operator|&
literal|7
index|]
expr_stmt|;
operator|++
name|src
expr_stmt|;
block|}
block|}
return|return
name|QBitmap
operator|::
name|fromImage
argument_list|(
name|mask
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|transformed
name|QPixmap
name|QPixmapData
operator|::
name|transformed
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|,
name|Qt
operator|::
name|TransformationMode
name|mode
parameter_list|)
specifier|const
block|{
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|toImage
argument_list|()
operator|.
name|transformed
argument_list|(
name|matrix
argument_list|,
name|mode
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setAlphaChannel
name|void
name|QPixmapData
operator|::
name|setAlphaChannel
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|alphaChannel
parameter_list|)
block|{
name|QImage
name|image
init|=
name|toImage
argument_list|()
decl_stmt|;
name|image
operator|.
name|setAlphaChannel
argument_list|(
name|alphaChannel
operator|.
name|toImage
argument_list|()
argument_list|)
expr_stmt|;
name|fromImage
argument_list|(
name|image
argument_list|,
name|Qt
operator|::
name|AutoColor
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|alphaChannel
name|QPixmap
name|QPixmapData
operator|::
name|alphaChannel
parameter_list|()
specifier|const
block|{
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|toImage
argument_list|()
operator|.
name|alphaChannel
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setSerialNumber
name|void
name|QPixmapData
operator|::
name|setSerialNumber
parameter_list|(
name|int
name|serNo
parameter_list|)
block|{
name|ser_no
operator|=
name|serNo
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toImage
name|QImage
name|QPixmapData
operator|::
name|toImage
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|rect
operator|.
name|contains
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
condition|)
return|return
name|toImage
argument_list|()
return|;
else|else
return|return
name|toImage
argument_list|()
operator|.
name|copy
argument_list|(
name|rect
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|buffer
name|QImage
modifier|*
name|QPixmapData
operator|::
name|buffer
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_function
DECL|function|toNativeType
name|void
modifier|*
name|QPixmapData
operator|::
name|toNativeType
parameter_list|(
name|NativeType
comment|/* type */
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|fromNativeType
name|void
name|QPixmapData
operator|::
name|fromNativeType
parameter_list|(
name|void
modifier|*
comment|/* pixmap */
parameter_list|,
name|NativeType
comment|/* typre */
parameter_list|)
block|{
return|return;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
