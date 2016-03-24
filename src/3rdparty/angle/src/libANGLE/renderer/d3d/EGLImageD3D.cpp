begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
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
comment|// EGLImageD3D.cpp: Implements the rx::EGLImageD3D class, the D3D implementation of EGL images
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/EGLImageD3D.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/AttributeMap.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Texture.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RenderbufferD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RendererD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RenderTargetD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/TextureD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/TextureStorage.h"
end_include
begin_include
include|#
directive|include
file|<EGL/eglext.h>
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|GetImageIndex
specifier|static
name|gl
operator|::
name|ImageIndex
name|GetImageIndex
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|size_t
name|mip
parameter_list|,
name|size_t
name|layer
parameter_list|)
block|{
if|if
condition|(
name|target
operator|==
name|GL_TEXTURE_3D
condition|)
block|{
return|return
name|gl
operator|::
name|ImageIndex
operator|::
name|Make3D
argument_list|(
cast|static_cast
argument_list|<
name|GLint
argument_list|>
argument_list|(
name|mip
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|GLint
argument_list|>
argument_list|(
name|layer
argument_list|)
argument_list|)
return|;
block|}
else|else
block|{
name|ASSERT
argument_list|(
name|layer
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
name|gl
operator|::
name|ImageIndex
operator|::
name|MakeGeneric
argument_list|(
name|target
argument_list|,
cast|static_cast
argument_list|<
name|GLint
argument_list|>
argument_list|(
name|mip
argument_list|)
argument_list|)
return|;
block|}
block|}
DECL|function|EGLImageD3D
name|EGLImageD3D
operator|::
name|EGLImageD3D
parameter_list|(
name|RendererD3D
modifier|*
name|renderer
parameter_list|,
name|EGLenum
name|target
parameter_list|,
name|egl
operator|::
name|ImageSibling
modifier|*
name|buffer
parameter_list|,
specifier|const
name|egl
operator|::
name|AttributeMap
modifier|&
name|attribs
parameter_list|)
member_init_list|:
name|mRenderer
argument_list|(
name|renderer
argument_list|)
member_init_list|,
name|mBuffer
argument_list|(
name|buffer
argument_list|)
member_init_list|,
name|mAttachmentBuffer
argument_list|(
literal|nullptr
argument_list|)
member_init_list|,
name|mRenderTarget
argument_list|(
literal|nullptr
argument_list|)
block|{
name|ASSERT
argument_list|(
name|renderer
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|buffer
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|egl
operator|::
name|IsTextureTarget
argument_list|(
name|target
argument_list|)
condition|)
block|{
name|mAttachmentBuffer
operator|=
name|GetImplAs
argument_list|<
name|TextureD3D
argument_list|>
argument_list|(
name|GetAs
argument_list|<
name|gl
operator|::
name|Texture
argument_list|>
argument_list|(
name|buffer
argument_list|)
argument_list|)
expr_stmt|;
name|mAttachmentTarget
operator|=
name|gl
operator|::
name|FramebufferAttachment
operator|::
name|Target
argument_list|(
name|GL_NONE
argument_list|,
name|GetImageIndex
argument_list|(
name|egl_gl
operator|::
name|EGLImageTargetToGLTextureTarget
argument_list|(
name|target
argument_list|)
argument_list|,
name|attribs
operator|.
name|get
argument_list|(
name|EGL_GL_TEXTURE_LEVEL_KHR
argument_list|,
literal|0
argument_list|)
argument_list|,
name|attribs
operator|.
name|get
argument_list|(
name|EGL_GL_TEXTURE_ZOFFSET_KHR
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|egl
operator|::
name|IsRenderbufferTarget
argument_list|(
name|target
argument_list|)
condition|)
block|{
name|mAttachmentBuffer
operator|=
name|GetImplAs
argument_list|<
name|RenderbufferD3D
argument_list|>
argument_list|(
name|GetAs
argument_list|<
name|gl
operator|::
name|Renderbuffer
argument_list|>
argument_list|(
name|buffer
argument_list|)
argument_list|)
expr_stmt|;
name|mAttachmentTarget
operator|=
name|gl
operator|::
name|FramebufferAttachment
operator|::
name|Target
argument_list|(
name|GL_NONE
argument_list|,
name|gl
operator|::
name|ImageIndex
operator|::
name|MakeInvalid
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|~EGLImageD3D
name|EGLImageD3D
operator|::
name|~
name|EGLImageD3D
parameter_list|()
block|{
name|SafeDelete
argument_list|(
name|mRenderTarget
argument_list|)
expr_stmt|;
block|}
DECL|function|initialize
name|egl
operator|::
name|Error
name|EGLImageD3D
operator|::
name|initialize
parameter_list|()
block|{
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
return|;
block|}
DECL|function|orphan
name|gl
operator|::
name|Error
name|EGLImageD3D
operator|::
name|orphan
parameter_list|(
name|egl
operator|::
name|ImageSibling
modifier|*
name|sibling
parameter_list|)
block|{
if|if
condition|(
name|sibling
operator|==
name|mBuffer
condition|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|copyToLocalRendertarget
argument_list|()
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
block|}
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|getRenderTarget
name|gl
operator|::
name|Error
name|EGLImageD3D
operator|::
name|getRenderTarget
parameter_list|(
name|RenderTargetD3D
modifier|*
modifier|*
name|outRT
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|mAttachmentBuffer
condition|)
block|{
name|FramebufferAttachmentRenderTarget
modifier|*
name|rt
init|=
literal|nullptr
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|mAttachmentBuffer
operator|->
name|getAttachmentRenderTarget
argument_list|(
name|mAttachmentTarget
argument_list|,
operator|&
name|rt
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
operator|*
name|outRT
operator|=
cast|static_cast
argument_list|<
name|RenderTargetD3D
operator|*
argument_list|>
argument_list|(
name|rt
argument_list|)
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
else|else
block|{
name|ASSERT
argument_list|(
name|mRenderTarget
argument_list|)
expr_stmt|;
operator|*
name|outRT
operator|=
name|mRenderTarget
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
block|}
DECL|function|copyToLocalRendertarget
name|gl
operator|::
name|Error
name|EGLImageD3D
operator|::
name|copyToLocalRendertarget
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|mBuffer
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mAttachmentBuffer
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mRenderTarget
operator|==
literal|nullptr
argument_list|)
expr_stmt|;
name|RenderTargetD3D
modifier|*
name|curRenderTarget
init|=
literal|nullptr
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|getRenderTarget
argument_list|(
operator|&
name|curRenderTarget
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
comment|// Clear the source image buffers
name|mBuffer
operator|=
literal|nullptr
expr_stmt|;
name|mAttachmentBuffer
operator|=
literal|nullptr
expr_stmt|;
return|return
name|mRenderer
operator|->
name|createRenderTargetCopy
argument_list|(
name|curRenderTarget
argument_list|,
operator|&
name|mRenderTarget
argument_list|)
return|;
block|}
block|}
end_namespace
end_unit
