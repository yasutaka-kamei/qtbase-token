begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLPIXELBUFFER_H
end_ifndef
begin_define
DECL|macro|QGLPIXELBUFFER_H
define|#
directive|define
name|QGLPIXELBUFFER_H
end_define
begin_include
include|#
directive|include
file|<QtOpenGL/qgl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGLPixelBufferPrivate
name|class
name|QGLPixelBufferPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLPixelBuffer
range|:
name|public
name|QPaintDevice
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGLPixelBuffer
argument_list|)
name|public
operator|:
name|QGLPixelBuffer
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QGLFormat
operator|&
name|format
operator|=
name|QGLFormat
operator|::
name|defaultFormat
argument_list|()
argument_list|,
name|QGLWidget
operator|*
name|shareWidget
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|QGLPixelBuffer
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|const QGLFormat&format = QGLFormat::defaultFormat()
argument_list|,
argument|QGLWidget *shareWidget = Q_NULLPTR
argument_list|)
block|;
name|virtual
operator|~
name|QGLPixelBuffer
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|bool
name|makeCurrent
argument_list|()
block|;
name|bool
name|doneCurrent
argument_list|()
block|;
name|QGLContext
operator|*
name|context
argument_list|()
specifier|const
block|;
name|GLuint
name|generateDynamicTexture
argument_list|()
specifier|const
block|;
name|bool
name|bindToDynamicTexture
argument_list|(
argument|GLuint texture
argument_list|)
block|;
name|void
name|releaseFromDynamicTexture
argument_list|()
block|;
name|void
name|updateDynamicTexture
argument_list|(
argument|GLuint texture_id
argument_list|)
specifier|const
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|const QImage&image
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|)
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|)
block|;
name|GLuint
name|bindTexture
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|deleteTexture
argument_list|(
argument|GLuint texture_id
argument_list|)
block|;
name|void
name|drawTexture
argument_list|(
argument|const QRectF&target
argument_list|,
argument|GLuint textureId
argument_list|,
argument|GLenum textureTarget = GL_TEXTURE_2D
argument_list|)
block|;
name|void
name|drawTexture
argument_list|(
argument|const QPointF&point
argument_list|,
argument|GLuint textureId
argument_list|,
argument|GLenum textureTarget = GL_TEXTURE_2D
argument_list|)
block|;
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QGLFormat
name|format
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|hasOpenGLPbuffers
argument_list|()
block|;
name|protected
operator|:
name|int
name|metric
argument_list|(
argument|PaintDeviceMetric metric
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|devType
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QInternal
operator|::
name|Pbuffer
return|;
block|}
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGLPixelBuffer
argument_list|)
name|QScopedPointer
operator|<
name|QGLPixelBufferPrivate
operator|>
name|d_ptr
block|;
name|friend
name|class
name|QGLDrawable
block|;
name|friend
name|class
name|QGLPaintDevice
block|;
name|friend
name|class
name|QGLPBufferGLPaintDevice
block|;
name|friend
name|class
name|QGLContextPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLPIXELBUFFER_H
end_comment
end_unit
