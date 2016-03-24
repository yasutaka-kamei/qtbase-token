begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Renderbuffer.h: Defines the renderer-agnostic container class gl::Renderbuffer.
end_comment
begin_comment
comment|// Implements GL renderbuffer objects and related functionality.
end_comment
begin_comment
comment|// [OpenGL ES 2.0.24] section 4.4.3 page 108.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERBUFFER_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERBUFFER_H_
define|#
directive|define
name|LIBANGLE_RENDERBUFFER_H_
end_define
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Debug.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/FramebufferAttachment.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Image.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/RenderbufferImpl.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
comment|// A GL renderbuffer object is usually used as a depth or stencil buffer attachment
comment|// for a framebuffer object. The renderbuffer itself is a distinct GL object, see
comment|// FramebufferAttachment and Framebuffer for how they are applied to an FBO via an
comment|// attachment point.
name|class
name|Renderbuffer
name|final
range|:
name|public
name|egl
operator|::
name|ImageSibling
decl_stmt|,
name|public
name|gl
decl|::
name|FramebufferAttachmentObject
decl_stmt|,
name|public
name|LabeledObject
block|{
name|public
label|:
name|Renderbuffer
argument_list|(
argument|rx::RenderbufferImpl *impl
argument_list|,
argument|GLuint id
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|Renderbuffer
argument_list|()
expr_stmt|;
name|void
name|setLabel
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|label
argument_list|)
name|override
decl_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getLabel
argument_list|()
specifier|const
name|override
expr_stmt|;
name|Error
name|setStorage
parameter_list|(
name|GLenum
name|internalformat
parameter_list|,
name|size_t
name|width
parameter_list|,
name|size_t
name|height
parameter_list|)
function_decl|;
name|Error
name|setStorageMultisample
parameter_list|(
name|size_t
name|samples
parameter_list|,
name|GLenum
name|internalformat
parameter_list|,
name|size_t
name|width
parameter_list|,
name|size_t
name|height
parameter_list|)
function_decl|;
name|Error
name|setStorageEGLImageTarget
argument_list|(
name|egl
operator|::
name|Image
operator|*
name|imageTarget
argument_list|)
decl_stmt|;
name|rx
operator|::
name|RenderbufferImpl
operator|*
name|getImplementation
argument_list|()
expr_stmt|;
specifier|const
name|rx
operator|::
name|RenderbufferImpl
operator|*
name|getImplementation
argument_list|()
specifier|const
expr_stmt|;
name|GLsizei
name|getWidth
argument_list|()
specifier|const
expr_stmt|;
name|GLsizei
name|getHeight
argument_list|()
specifier|const
expr_stmt|;
name|GLenum
name|getInternalFormat
argument_list|()
specifier|const
expr_stmt|;
name|GLsizei
name|getSamples
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|getRedSize
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|getGreenSize
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|getBlueSize
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|getAlphaSize
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|getDepthSize
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|getStencilSize
argument_list|()
specifier|const
expr_stmt|;
comment|// FramebufferAttachmentObject Impl
name|Extents
name|getAttachmentSize
argument_list|(
specifier|const
name|FramebufferAttachment
operator|::
name|Target
operator|&
name|target
argument_list|)
decl|const
name|override
decl_stmt|;
name|GLenum
name|getAttachmentInternalFormat
argument_list|(
specifier|const
name|FramebufferAttachment
operator|::
name|Target
operator|&
comment|/*target*/
argument_list|)
decl|const
name|override
block|{
return|return
name|getInternalFormat
argument_list|()
return|;
block|}
name|GLsizei
name|getAttachmentSamples
argument_list|(
specifier|const
name|FramebufferAttachment
operator|::
name|Target
operator|&
comment|/*target*/
argument_list|)
decl|const
name|override
block|{
return|return
name|getSamples
argument_list|()
return|;
block|}
name|void
name|onAttach
argument_list|()
name|override
expr_stmt|;
name|void
name|onDetach
argument_list|()
name|override
expr_stmt|;
name|GLuint
name|getId
argument_list|()
specifier|const
name|override
expr_stmt|;
name|private
label|:
name|rx
operator|::
name|FramebufferAttachmentObjectImpl
operator|*
name|getAttachmentImpl
argument_list|()
specifier|const
name|override
block|{
return|return
name|mRenderbuffer
return|;
block|}
name|rx
operator|::
name|RenderbufferImpl
operator|*
name|mRenderbuffer
expr_stmt|;
name|std
operator|::
name|string
name|mLabel
expr_stmt|;
name|GLsizei
name|mWidth
decl_stmt|;
name|GLsizei
name|mHeight
decl_stmt|;
name|GLenum
name|mInternalFormat
decl_stmt|;
name|GLsizei
name|mSamples
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERBUFFER_H_
end_comment
end_unit
