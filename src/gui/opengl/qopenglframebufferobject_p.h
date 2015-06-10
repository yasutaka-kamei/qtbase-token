begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLFRAMEBUFFEROBJECT_P_H
end_ifndef
begin_define
DECL|macro|QOPENGLFRAMEBUFFEROBJECT_P_H
define|#
directive|define
name|QOPENGLFRAMEBUFFEROBJECT_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qopenglframebufferobject.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglextensions_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QOpenGLFramebufferObjectFormatPrivate
block|{
name|public
label|:
name|QOpenGLFramebufferObjectFormatPrivate
argument_list|()
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|samples
argument_list|(
literal|0
argument_list|)
operator|,
name|attachment
argument_list|(
name|QOpenGLFramebufferObject
operator|::
name|NoAttachment
argument_list|)
operator|,
name|target
argument_list|(
name|GL_TEXTURE_2D
argument_list|)
operator|,
name|mipmap
argument_list|(
argument|false
argument_list|)
block|{
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
comment|// There is nothing that says QOpenGLFramebufferObjectFormat needs a current
comment|// context, so we need a fallback just to be safe, even though in pratice there
comment|// will usually be a context current.
name|QOpenGLContext
operator|*
name|ctx
operator|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
block|;
specifier|const
name|bool
name|isES
operator|=
name|ctx
condition|?
name|ctx
operator|->
name|isOpenGLES
argument_list|()
else|:
name|QOpenGLContext
operator|::
name|openGLModuleType
argument_list|()
operator|!=
name|QOpenGLContext
operator|::
name|LibGL
block|;
name|internal_format
operator|=
name|isES
condition|?
name|GL_RGBA
else|:
name|GL_RGBA8
block|;
else|#
directive|else
name|internal_format
operator|=
name|GL_RGBA
block|;
endif|#
directive|endif
block|}
name|QOpenGLFramebufferObjectFormatPrivate
argument_list|(
specifier|const
name|QOpenGLFramebufferObjectFormatPrivate
operator|*
name|other
argument_list|)
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|samples
argument_list|(
name|other
operator|->
name|samples
argument_list|)
operator|,
name|attachment
argument_list|(
name|other
operator|->
name|attachment
argument_list|)
operator|,
name|target
argument_list|(
name|other
operator|->
name|target
argument_list|)
operator|,
name|internal_format
argument_list|(
name|other
operator|->
name|internal_format
argument_list|)
operator|,
name|mipmap
argument_list|(
argument|other->mipmap
argument_list|)
block|{     }
name|bool
name|equals
argument_list|(
argument|const QOpenGLFramebufferObjectFormatPrivate *other
argument_list|)
block|{
return|return
name|samples
operator|==
name|other
operator|->
name|samples
operator|&&
name|attachment
operator|==
name|other
operator|->
name|attachment
operator|&&
name|target
operator|==
name|other
operator|->
name|target
operator|&&
name|internal_format
operator|==
name|other
operator|->
name|internal_format
operator|&&
name|mipmap
operator|==
name|other
operator|->
name|mipmap
return|;
block|}
name|QAtomicInt
name|ref
decl_stmt|;
name|int
name|samples
decl_stmt|;
name|QOpenGLFramebufferObject
operator|::
name|Attachment
name|attachment
expr_stmt|;
name|GLenum
name|target
decl_stmt|;
name|GLenum
name|internal_format
decl_stmt|;
name|uint
name|mipmap
range|:
literal|1
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QOpenGLFramebufferObjectPrivate
block|{
name|public
label|:
name|QOpenGLFramebufferObjectPrivate
argument_list|()
operator|:
name|fbo_guard
argument_list|(
literal|0
argument_list|)
operator|,
name|depth_buffer_guard
argument_list|(
literal|0
argument_list|)
operator|,
name|stencil_buffer_guard
argument_list|(
literal|0
argument_list|)
operator|,
name|valid
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|QOpenGLFramebufferObjectPrivate
argument_list|()
block|{}
name|void
name|init
argument_list|(
argument|QOpenGLFramebufferObject *q
argument_list|,
argument|const QSize&size
argument_list|,
argument|QOpenGLFramebufferObject::Attachment attachment
argument_list|,
argument|GLenum texture_target
argument_list|,
argument|GLenum internal_format
argument_list|,
argument|GLint samples =
literal|0
argument_list|,
argument|bool mipmap = false
argument_list|)
expr_stmt|;
name|void
name|initTexture
parameter_list|(
name|int
name|idx
parameter_list|)
function_decl|;
name|void
name|initColorBuffer
parameter_list|(
name|int
name|idx
parameter_list|,
name|GLint
modifier|*
name|samples
parameter_list|)
function_decl|;
name|void
name|initDepthStencilAttachments
argument_list|(
name|QOpenGLContext
operator|*
name|ctx
argument_list|,
name|QOpenGLFramebufferObject
operator|::
name|Attachment
name|attachment
argument_list|)
decl_stmt|;
name|bool
name|checkFramebufferStatus
argument_list|(
name|QOpenGLContext
operator|*
name|ctx
argument_list|)
decl|const
decl_stmt|;
name|QOpenGLSharedResourceGuard
modifier|*
name|fbo_guard
decl_stmt|;
name|QOpenGLSharedResourceGuard
modifier|*
name|depth_buffer_guard
decl_stmt|;
name|QOpenGLSharedResourceGuard
modifier|*
name|stencil_buffer_guard
decl_stmt|;
name|GLenum
name|target
decl_stmt|;
name|QSize
name|dsSize
decl_stmt|;
name|QOpenGLFramebufferObjectFormat
name|format
decl_stmt|;
name|int
name|requestedSamples
decl_stmt|;
name|uint
name|valid
range|:
literal|1
decl_stmt|;
name|QOpenGLFramebufferObject
operator|::
name|Attachment
name|fbo_attachment
expr_stmt|;
name|QOpenGLExtensions
name|funcs
decl_stmt|;
struct|struct
name|ColorAttachment
block|{
name|ColorAttachment
argument_list|()
operator|:
name|internalFormat
argument_list|(
literal|0
argument_list|)
operator|,
name|guard
argument_list|(
literal|0
argument_list|)
block|{ }
name|ColorAttachment
argument_list|(
argument|const QSize&size
argument_list|,
argument|GLenum internalFormat
argument_list|)
operator|:
name|size
argument_list|(
name|size
argument_list|)
operator|,
name|internalFormat
argument_list|(
name|internalFormat
argument_list|)
operator|,
name|guard
argument_list|(
literal|0
argument_list|)
block|{ }
name|QSize
name|size
expr_stmt|;
name|GLenum
name|internalFormat
decl_stmt|;
name|QOpenGLSharedResourceGuard
modifier|*
name|guard
decl_stmt|;
block|}
struct|;
name|QVector
operator|<
name|ColorAttachment
operator|>
name|colorAttachments
expr_stmt|;
specifier|inline
name|GLuint
name|fbo
argument_list|()
specifier|const
block|{
return|return
name|fbo_guard
operator|?
name|fbo_guard
operator|->
name|id
argument_list|()
operator|:
literal|0
return|;
block|}
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
comment|// QOPENGLFRAMEBUFFEROBJECT_P_H
end_comment
end_unit
