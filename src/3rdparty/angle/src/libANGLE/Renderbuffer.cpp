begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// Renderbuffer.cpp: Implements the renderer-agnostic gl::Renderbuffer class,
end_comment
begin_comment
comment|// GL renderbuffer objects and related functionality.
end_comment
begin_comment
comment|// [OpenGL ES 2.0.24] section 4.4.3 page 108.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/Renderbuffer.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
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
file|"libANGLE/Texture.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/formatutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RenderTargetD3D.h"
end_include
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|function|Renderbuffer
name|Renderbuffer
operator|::
name|Renderbuffer
parameter_list|(
name|rx
operator|::
name|RenderbufferImpl
modifier|*
name|impl
parameter_list|,
name|GLuint
name|id
parameter_list|)
member_init_list|:
name|egl
operator|::
name|ImageSibling
argument_list|(
name|id
argument_list|)
member_init_list|,
name|mRenderbuffer
argument_list|(
name|impl
argument_list|)
member_init_list|,
name|mLabel
argument_list|()
member_init_list|,
name|mWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mHeight
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mInternalFormat
argument_list|(
name|GL_RGBA4
argument_list|)
member_init_list|,
name|mSamples
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|~Renderbuffer
name|Renderbuffer
operator|::
name|~
name|Renderbuffer
parameter_list|()
block|{
name|SafeDelete
argument_list|(
name|mRenderbuffer
argument_list|)
expr_stmt|;
block|}
DECL|function|setLabel
name|void
name|Renderbuffer
operator|::
name|setLabel
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|label
parameter_list|)
block|{
name|mLabel
operator|=
name|label
expr_stmt|;
block|}
DECL|function|getLabel
specifier|const
name|std
operator|::
name|string
modifier|&
name|Renderbuffer
operator|::
name|getLabel
parameter_list|()
specifier|const
block|{
return|return
name|mLabel
return|;
block|}
DECL|function|setStorage
name|Error
name|Renderbuffer
operator|::
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
block|{
name|orphanImages
argument_list|()
expr_stmt|;
name|Error
name|error
init|=
name|mRenderbuffer
operator|->
name|setStorage
argument_list|(
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|mWidth
operator|=
cast|static_cast
argument_list|<
name|GLsizei
argument_list|>
argument_list|(
name|width
argument_list|)
expr_stmt|;
name|mHeight
operator|=
cast|static_cast
argument_list|<
name|GLsizei
argument_list|>
argument_list|(
name|height
argument_list|)
expr_stmt|;
name|mInternalFormat
operator|=
name|internalformat
expr_stmt|;
name|mSamples
operator|=
literal|0
expr_stmt|;
return|return
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|setStorageMultisample
name|Error
name|Renderbuffer
operator|::
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
block|{
name|orphanImages
argument_list|()
expr_stmt|;
name|Error
name|error
init|=
name|mRenderbuffer
operator|->
name|setStorageMultisample
argument_list|(
name|samples
argument_list|,
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|mWidth
operator|=
cast|static_cast
argument_list|<
name|GLsizei
argument_list|>
argument_list|(
name|width
argument_list|)
expr_stmt|;
name|mHeight
operator|=
cast|static_cast
argument_list|<
name|GLsizei
argument_list|>
argument_list|(
name|height
argument_list|)
expr_stmt|;
name|mInternalFormat
operator|=
name|internalformat
expr_stmt|;
name|mSamples
operator|=
cast|static_cast
argument_list|<
name|GLsizei
argument_list|>
argument_list|(
name|samples
argument_list|)
expr_stmt|;
return|return
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|setStorageEGLImageTarget
name|Error
name|Renderbuffer
operator|::
name|setStorageEGLImageTarget
parameter_list|(
name|egl
operator|::
name|Image
modifier|*
name|image
parameter_list|)
block|{
name|orphanImages
argument_list|()
expr_stmt|;
name|Error
name|error
init|=
name|mRenderbuffer
operator|->
name|setStorageEGLImageTarget
argument_list|(
name|image
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|setTargetImage
argument_list|(
name|image
argument_list|)
expr_stmt|;
name|mWidth
operator|=
cast|static_cast
argument_list|<
name|GLsizei
argument_list|>
argument_list|(
name|image
operator|->
name|getWidth
argument_list|()
argument_list|)
expr_stmt|;
name|mHeight
operator|=
cast|static_cast
argument_list|<
name|GLsizei
argument_list|>
argument_list|(
name|image
operator|->
name|getHeight
argument_list|()
argument_list|)
expr_stmt|;
name|mInternalFormat
operator|=
name|image
operator|->
name|getInternalFormat
argument_list|()
expr_stmt|;
name|mSamples
operator|=
literal|0
expr_stmt|;
return|return
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|getImplementation
name|rx
operator|::
name|RenderbufferImpl
modifier|*
name|Renderbuffer
operator|::
name|getImplementation
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|mRenderbuffer
argument_list|)
expr_stmt|;
return|return
name|mRenderbuffer
return|;
block|}
DECL|function|getImplementation
specifier|const
name|rx
operator|::
name|RenderbufferImpl
modifier|*
name|Renderbuffer
operator|::
name|getImplementation
parameter_list|()
specifier|const
block|{
return|return
name|mRenderbuffer
return|;
block|}
DECL|function|getWidth
name|GLsizei
name|Renderbuffer
operator|::
name|getWidth
parameter_list|()
specifier|const
block|{
return|return
name|mWidth
return|;
block|}
DECL|function|getHeight
name|GLsizei
name|Renderbuffer
operator|::
name|getHeight
parameter_list|()
specifier|const
block|{
return|return
name|mHeight
return|;
block|}
DECL|function|getInternalFormat
name|GLenum
name|Renderbuffer
operator|::
name|getInternalFormat
parameter_list|()
specifier|const
block|{
return|return
name|mInternalFormat
return|;
block|}
DECL|function|getSamples
name|GLsizei
name|Renderbuffer
operator|::
name|getSamples
parameter_list|()
specifier|const
block|{
return|return
name|mSamples
return|;
block|}
DECL|function|getRedSize
name|GLuint
name|Renderbuffer
operator|::
name|getRedSize
parameter_list|()
specifier|const
block|{
return|return
name|GetInternalFormatInfo
argument_list|(
name|mInternalFormat
argument_list|)
operator|.
name|redBits
return|;
block|}
DECL|function|getGreenSize
name|GLuint
name|Renderbuffer
operator|::
name|getGreenSize
parameter_list|()
specifier|const
block|{
return|return
name|GetInternalFormatInfo
argument_list|(
name|mInternalFormat
argument_list|)
operator|.
name|greenBits
return|;
block|}
DECL|function|getBlueSize
name|GLuint
name|Renderbuffer
operator|::
name|getBlueSize
parameter_list|()
specifier|const
block|{
return|return
name|GetInternalFormatInfo
argument_list|(
name|mInternalFormat
argument_list|)
operator|.
name|blueBits
return|;
block|}
DECL|function|getAlphaSize
name|GLuint
name|Renderbuffer
operator|::
name|getAlphaSize
parameter_list|()
specifier|const
block|{
return|return
name|GetInternalFormatInfo
argument_list|(
name|mInternalFormat
argument_list|)
operator|.
name|alphaBits
return|;
block|}
DECL|function|getDepthSize
name|GLuint
name|Renderbuffer
operator|::
name|getDepthSize
parameter_list|()
specifier|const
block|{
return|return
name|GetInternalFormatInfo
argument_list|(
name|mInternalFormat
argument_list|)
operator|.
name|depthBits
return|;
block|}
DECL|function|getStencilSize
name|GLuint
name|Renderbuffer
operator|::
name|getStencilSize
parameter_list|()
specifier|const
block|{
return|return
name|GetInternalFormatInfo
argument_list|(
name|mInternalFormat
argument_list|)
operator|.
name|stencilBits
return|;
block|}
DECL|function|onAttach
name|void
name|Renderbuffer
operator|::
name|onAttach
parameter_list|()
block|{
name|addRef
argument_list|()
expr_stmt|;
block|}
DECL|function|onDetach
name|void
name|Renderbuffer
operator|::
name|onDetach
parameter_list|()
block|{
name|release
argument_list|()
expr_stmt|;
block|}
DECL|function|getId
name|GLuint
name|Renderbuffer
operator|::
name|getId
parameter_list|()
specifier|const
block|{
return|return
name|id
argument_list|()
return|;
block|}
DECL|function|getAttachmentSize
name|Extents
name|Renderbuffer
operator|::
name|getAttachmentSize
parameter_list|(
specifier|const
name|FramebufferAttachment
operator|::
name|Target
modifier|&
comment|/*target*/
parameter_list|)
specifier|const
block|{
return|return
name|Extents
argument_list|(
name|mWidth
argument_list|,
name|mHeight
argument_list|,
literal|1
argument_list|)
return|;
block|}
block|}
end_namespace
end_unit
