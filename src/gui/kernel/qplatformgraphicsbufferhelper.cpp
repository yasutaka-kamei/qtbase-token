begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtPlatformSupport module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/qpa/qplatformgraphicsbuffer.h>
end_include
begin_include
include|#
directive|include
file|"qplatformgraphicsbufferhelper.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     Convenience function to both lock and bind the buffer to a texture. This     function will first try and lock with texture read and texture write     access. If this succeeds it will use the bindToTexture function to bind the     content to the currently bound texture. If this fail it will try and lock     with SWReadAccess and then use the bindSWToTexture convenience function.      \a swizzle is suppose to be used by the caller to figure out if the Red and     Blue color channels need to be swizzled when rendering.      \a rect is the subrect which is desired to be bounded to the texture. This     argument has a no less than semantic, meaning more (if not all) of the buffer     can be bounded to the texture. An empty QRect is interpreted as entire buffer     should be bound.      The user should use the AccessTypes returned by isLocked to figure out what     lock has been obtained.      returns true if the buffer has successfully been bound to the currently     bound texture, otherwise returns false. */
DECL|function|lockAndBindToTexture
name|bool
name|QPlatformGraphicsBufferHelper
operator|::
name|lockAndBindToTexture
parameter_list|(
name|QPlatformGraphicsBuffer
modifier|*
name|graphicsBuffer
parameter_list|,
name|bool
modifier|*
name|swizzle
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
if|if
condition|(
name|graphicsBuffer
operator|->
name|lock
argument_list|(
name|QPlatformGraphicsBuffer
operator|::
name|TextureAccess
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|graphicsBuffer
operator|->
name|bindToTexture
argument_list|(
name|rect
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Failed to bind graphicsbuffer to texture"
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|swizzle
condition|)
operator|*
name|swizzle
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|graphicsBuffer
operator|->
name|lock
argument_list|(
name|QPlatformGraphicsBuffer
operator|::
name|SWReadAccess
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|bindSWToTexture
argument_list|(
name|graphicsBuffer
argument_list|,
name|swizzle
argument_list|,
name|rect
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Failed to bind SW graphcisbuffer to texture"
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Failed to lock"
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function that uploads the current raster content to the currently bound texture.      \a swizzleRandB is suppose to be used by the caller to figure out if the Red and     Blue color channels need to be swizzled when rendering. This is an     optimization. Qt often renders to software buffers interpreting pixels as     unsigned ints. When these buffers are uploaded to textures and each color     channel per pixel is interpreted as a byte (read sequentially), then the     Red and Blue channels are swapped. Conveniently the Alpha buffer will be     correct since Qt historically has had the alpha channel as the first     channel, while OpenGL typically expects the alpha channel to be the last     channel.      \a subRect is the subrect which is desired to be bounded to the texture. This     argument has a no less than semantic, meaning more (if not all) of the buffer     can be bounded to the texture. An empty QRect is interpreted as entire buffer     should be bound.      This function fails for buffers not capable of locking to SWAccess.      Returns true on success, otherwise false. */
end_comment
begin_function
DECL|function|bindSWToTexture
name|bool
name|QPlatformGraphicsBufferHelper
operator|::
name|bindSWToTexture
parameter_list|(
specifier|const
name|QPlatformGraphicsBuffer
modifier|*
name|graphicsBuffer
parameter_list|,
name|bool
modifier|*
name|swizzleRandB
parameter_list|,
specifier|const
name|QRect
modifier|&
name|subRect
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
if|if
condition|(
operator|!
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
operator|(
name|graphicsBuffer
operator|->
name|isLocked
argument_list|()
operator|&
name|QPlatformGraphicsBuffer
operator|::
name|SWReadAccess
operator|)
condition|)
return|return
literal|false
return|;
name|QSize
name|size
init|=
name|graphicsBuffer
operator|->
name|size
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|subRect
operator|.
name|isEmpty
argument_list|()
operator|||
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|)
operator|.
name|contains
argument_list|(
name|subRect
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|swizzle
init|=
literal|false
decl_stmt|;
name|QImage
operator|::
name|Format
name|imageformat
init|=
name|QImage
operator|::
name|toImageFormat
argument_list|(
name|graphicsBuffer
operator|->
name|format
argument_list|()
argument_list|)
decl_stmt|;
name|QImage
name|image
argument_list|(
name|graphicsBuffer
operator|->
name|data
argument_list|()
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
name|graphicsBuffer
operator|->
name|bytesPerLine
argument_list|()
argument_list|,
name|imageformat
argument_list|)
decl_stmt|;
if|if
condition|(
name|graphicsBuffer
operator|->
name|bytesPerLine
argument_list|()
operator|!=
operator|(
name|size
operator|.
name|width
argument_list|()
operator|*
literal|4
operator|)
condition|)
block|{
name|image
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGBA8888
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|imageformat
operator|==
name|QImage
operator|::
name|Format_RGB32
condition|)
block|{
name|swizzle
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|imageformat
operator|!=
name|QImage
operator|::
name|Format_RGBA8888
condition|)
block|{
name|image
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGBA8888
argument_list|)
expr_stmt|;
block|}
name|QOpenGLFunctions
modifier|*
name|funcs
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
decl_stmt|;
name|QRect
name|rect
init|=
name|subRect
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|isNull
argument_list|()
operator|||
name|rect
operator|==
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|)
condition|)
block|{
name|funcs
operator|->
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
if|if
condition|(
operator|!
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|isOpenGLES
argument_list|()
condition|)
block|{
name|funcs
operator|->
name|glPixelStorei
argument_list|(
name|GL_UNPACK_ROW_LENGTH
argument_list|,
name|image
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
operator|.
name|constScanLine
argument_list|(
name|rect
operator|.
name|y
argument_list|()
argument_list|)
operator|+
name|rect
operator|.
name|x
argument_list|()
operator|*
literal|4
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glPixelStorei
argument_list|(
name|GL_UNPACK_ROW_LENGTH
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
comment|// if the rect is wide enough it's cheaper to just
comment|// extend it instead of doing an image copy
if|if
condition|(
name|rect
operator|.
name|width
argument_list|()
operator|>=
name|size
operator|.
name|width
argument_list|()
operator|/
literal|2
condition|)
block|{
name|rect
operator|.
name|setX
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|rect
operator|.
name|setWidth
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// if the sub-rect is full-width we can pass the image data directly to
comment|// OpenGL instead of copying, since there's no gap between scanlines
if|if
condition|(
name|rect
operator|.
name|width
argument_list|()
operator|==
name|size
operator|.
name|width
argument_list|()
condition|)
block|{
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
operator|.
name|constScanLine
argument_list|(
name|rect
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
operator|.
name|copy
argument_list|(
name|rect
argument_list|)
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|swizzleRandB
condition|)
operator|*
name|swizzleRandB
operator|=
name|swizzle
expr_stmt|;
return|return
literal|true
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|graphicsBuffer
argument_list|)
name|Q_UNUSED
argument_list|(
argument|swizzleRandB
argument_list|)
name|Q_UNUSED
argument_list|(
argument|subRect
argument_list|)
return|return
literal|false
return|;
endif|#
directive|endif
comment|// QT_NO_OPENGL
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
