begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLFRAMEBUFFEROBJECT_H
end_ifndef
begin_define
DECL|macro|QGLFRAMEBUFFEROBJECT_H
define|#
directive|define
name|QGLFRAMEBUFFEROBJECT_H
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
DECL|variable|QGLFramebufferObjectPrivate
name|class
name|QGLFramebufferObjectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGLFramebufferObjectFormat
name|class
name|QGLFramebufferObjectFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLFramebufferObject
range|:
name|public
name|QPaintDevice
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGLFramebufferObject
argument_list|)
name|public
operator|:
expr|enum
name|Attachment
block|{
name|NoAttachment
block|,
name|CombinedDepthStencil
block|,
name|Depth
block|}
block|;
name|QGLFramebufferObject
argument_list|(
argument|const QSize&size
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|)
block|;
name|QGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|)
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|QGLFramebufferObject
argument_list|(
argument|const QSize&size
argument_list|,
argument|Attachment attachment
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLenum internal_format = GL_RGBA8
argument_list|)
block|;
name|QGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Attachment attachment
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLenum internal_format = GL_RGBA8
argument_list|)
block|;
else|#
directive|else
name|QGLFramebufferObject
argument_list|(
argument|const QSize&size
argument_list|,
argument|Attachment attachment
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLenum internal_format = GL_RGBA
argument_list|)
block|;
name|QGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Attachment attachment
argument_list|,
argument|GLenum target = GL_TEXTURE_2D
argument_list|,
argument|GLenum internal_format = GL_RGBA
argument_list|)
block|;
endif|#
directive|endif
name|QGLFramebufferObject
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QGLFramebufferObjectFormat
operator|&
name|format
argument_list|)
block|;
name|QGLFramebufferObject
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|const QGLFramebufferObjectFormat&format
argument_list|)
block|;
name|virtual
operator|~
name|QGLFramebufferObject
argument_list|()
block|;
name|QGLFramebufferObjectFormat
name|format
argument_list|()
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|bool
name|isBound
argument_list|()
specifier|const
block|;
name|bool
name|bind
argument_list|()
block|;
name|bool
name|release
argument_list|()
block|;
name|GLuint
name|texture
argument_list|()
specifier|const
block|;
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
block|;
name|Attachment
name|attachment
argument_list|()
specifier|const
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
name|GLuint
name|handle
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|bindDefault
argument_list|()
block|;
specifier|static
name|bool
name|hasOpenGLFramebufferObjects
argument_list|()
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
specifier|static
name|bool
name|hasOpenGLFramebufferBlit
argument_list|()
block|;
specifier|static
name|void
name|blitFramebuffer
argument_list|(
argument|QGLFramebufferObject *target
argument_list|,
argument|const QRect&targetRect
argument_list|,
argument|QGLFramebufferObject *source
argument_list|,
argument|const QRect&sourceRect
argument_list|,
argument|GLbitfield buffers = GL_COLOR_BUFFER_BIT
argument_list|,
argument|GLenum filter = GL_NEAREST
argument_list|)
block|;
name|protected
operator|:
name|int
name|metric
argument_list|(
argument|PaintDeviceMetric metric
argument_list|)
specifier|const
block|;
name|int
name|devType
argument_list|()
specifier|const
block|{
return|return
name|QInternal
operator|::
name|FramebufferObject
return|;
block|}
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGLFramebufferObject
argument_list|)
name|QScopedPointer
operator|<
name|QGLFramebufferObjectPrivate
operator|>
name|d_ptr
block|;
name|friend
name|class
name|QGLPaintDevice
block|;
name|friend
name|class
name|QGLFBOGLPaintDevice
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGLFramebufferObjectFormatPrivate
name|class
name|QGLFramebufferObjectFormatPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLFramebufferObjectFormat
block|{
name|public
label|:
name|QGLFramebufferObjectFormat
argument_list|()
expr_stmt|;
name|QGLFramebufferObjectFormat
argument_list|(
specifier|const
name|QGLFramebufferObjectFormat
operator|&
name|other
argument_list|)
expr_stmt|;
name|QGLFramebufferObjectFormat
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QGLFramebufferObjectFormat
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QGLFramebufferObjectFormat
argument_list|()
expr_stmt|;
name|void
name|setSamples
parameter_list|(
name|int
name|samples
parameter_list|)
function_decl|;
name|int
name|samples
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMipmap
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|mipmap
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAttachment
argument_list|(
name|QGLFramebufferObject
operator|::
name|Attachment
name|attachment
argument_list|)
decl_stmt|;
name|QGLFramebufferObject
operator|::
name|Attachment
name|attachment
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTextureTarget
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|GLenum
name|textureTarget
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInternalTextureFormat
parameter_list|(
name|GLenum
name|internalTextureFormat
parameter_list|)
function_decl|;
name|GLenum
name|internalTextureFormat
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QGLFramebufferObjectFormat
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QGLFramebufferObjectFormat
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|private
label|:
name|QGLFramebufferObjectFormatPrivate
modifier|*
name|d
decl_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLFRAMEBUFFEROBJECT_H
end_comment
end_unit
