begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformpixmap_qpa.h"
end_include
begin_include
include|#
directive|include
file|"qplatformintegration_qpa.h"
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
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qimagepixmapcleanuphooks_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPlatformPixmap     \since 5.0     \internal     \preliminary     \ingroup qpa      \brief The QPlatformPixmap class provides an abstraction for native pixmaps.  */
DECL|function|create
name|QPlatformPixmap
modifier|*
name|QPlatformPixmap
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
name|QPlatformPixmap
modifier|*
name|data
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|createPlatformPixmap
argument_list|(
cast|static_cast
argument_list|<
name|QPlatformPixmap
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
DECL|function|QPlatformPixmap
name|QPlatformPixmap
operator|::
name|QPlatformPixmap
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
DECL|function|~QPlatformPixmap
name|QPlatformPixmap
operator|::
name|~
name|QPlatformPixmap
parameter_list|()
block|{
comment|// Sometimes the pixmap cleanup hooks will be called from derrived classes, which will
comment|// then set is_cached to false. For example, on X11 QtGui needs to delete the GLXPixmap
comment|// or EGL Pixmap Surface for a given pixmap _before_ the native X11 pixmap is deleted,
comment|// otherwise some drivers will leak the GL surface. In this case, QX11PlatformPixmap will
comment|// call the cleanup hooks itself before deleting the native pixmap and set is_cached to
comment|// false.
if|if
condition|(
name|is_cached
condition|)
block|{
name|QImagePixmapCleanupHooks
operator|::
name|executePlatformPixmapDestructionHooks
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
DECL|function|createCompatiblePlatformPixmap
name|QPlatformPixmap
modifier|*
name|QPlatformPixmap
operator|::
name|createCompatiblePlatformPixmap
parameter_list|()
specifier|const
block|{
name|QPlatformPixmap
modifier|*
name|d
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|createPlatformPixmap
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
name|QPlatformPixmap
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
name|QPlatformPixmap
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
name|QPlatformPixmap
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
name|QPlatformPixmap
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
name|QPlatformPixmap
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
DECL|function|copy
name|void
name|QPlatformPixmap
operator|::
name|copy
parameter_list|(
specifier|const
name|QPlatformPixmap
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
name|QPlatformPixmap
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
DECL|function|transformed
name|QPixmap
name|QPlatformPixmap
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
DECL|function|setSerialNumber
name|void
name|QPlatformPixmap
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
name|QPlatformPixmap
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
name|QPlatformPixmap
operator|::
name|buffer
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
