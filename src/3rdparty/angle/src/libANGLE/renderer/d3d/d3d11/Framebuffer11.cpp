begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// Framebuffer11.cpp: Implements the Framebuffer11 class.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Framebuffer11.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Buffer11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Clear11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/TextureStorage11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Renderer11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/renderer11_utils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/RenderTarget11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/formatutils11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/TextureD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Framebuffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/FramebufferAttachment.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Texture.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|Framebuffer11
name|Framebuffer11
operator|::
name|Framebuffer11
parameter_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
operator|::
name|Data
modifier|&
name|data
parameter_list|,
name|Renderer11
modifier|*
name|renderer
parameter_list|)
member_init_list|:
name|FramebufferD3D
argument_list|(
name|data
argument_list|,
name|renderer
argument_list|)
member_init_list|,
name|mRenderer
argument_list|(
name|renderer
argument_list|)
block|{
name|ASSERT
argument_list|(
name|mRenderer
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
block|}
DECL|function|~Framebuffer11
name|Framebuffer11
operator|::
name|~
name|Framebuffer11
parameter_list|()
block|{ }
DECL|function|InvalidateAttachmentSwizzles
specifier|static
name|gl
operator|::
name|Error
name|InvalidateAttachmentSwizzles
parameter_list|(
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|attachment
parameter_list|)
block|{
if|if
condition|(
name|attachment
operator|&&
name|attachment
operator|->
name|type
argument_list|()
operator|==
name|GL_TEXTURE
condition|)
block|{
name|gl
operator|::
name|Texture
modifier|*
name|texture
init|=
name|attachment
operator|->
name|getTexture
argument_list|()
decl_stmt|;
name|TextureD3D
modifier|*
name|textureD3D
init|=
name|GetImplAs
argument_list|<
name|TextureD3D
argument_list|>
argument_list|(
name|texture
argument_list|)
decl_stmt|;
name|TextureStorage
modifier|*
name|texStorage
init|=
name|NULL
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|textureD3D
operator|->
name|getNativeTexture
argument_list|(
operator|&
name|texStorage
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
if|if
condition|(
name|texStorage
condition|)
block|{
name|TextureStorage11
modifier|*
name|texStorage11
init|=
name|TextureStorage11
operator|::
name|makeTextureStorage11
argument_list|(
name|texStorage
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|texStorage11
argument_list|)
expr_stmt|;
name|texStorage11
operator|->
name|invalidateSwizzleCacheLevel
argument_list|(
name|attachment
operator|->
name|mipLevel
argument_list|()
argument_list|)
expr_stmt|;
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
DECL|function|invalidateSwizzles
name|gl
operator|::
name|Error
name|Framebuffer11
operator|::
name|invalidateSwizzles
parameter_list|()
specifier|const
block|{
for|for
control|(
name|auto
name|it
init|=
name|mData
operator|.
name|mColorAttachments
operator|.
name|cbegin
argument_list|()
init|;
name|it
operator|!=
name|mData
operator|.
name|mColorAttachments
operator|.
name|cend
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|colorAttachment
init|=
operator|*
name|it
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|InvalidateAttachmentSwizzles
argument_list|(
name|colorAttachment
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
block|}
name|gl
operator|::
name|Error
name|error
init|=
name|InvalidateAttachmentSwizzles
argument_list|(
name|mData
operator|.
name|mDepthAttachment
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
name|error
operator|=
name|InvalidateAttachmentSwizzles
argument_list|(
name|mData
operator|.
name|mStencilAttachment
argument_list|)
expr_stmt|;
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
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|clear
name|gl
operator|::
name|Error
name|Framebuffer11
operator|::
name|clear
parameter_list|(
specifier|const
name|gl
operator|::
name|State
modifier|&
name|state
parameter_list|,
specifier|const
name|ClearParameters
modifier|&
name|clearParams
parameter_list|)
block|{
name|Clear11
modifier|*
name|clearer
init|=
name|mRenderer
operator|->
name|getClearer
argument_list|()
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|clearer
operator|->
name|clearFramebuffer
argument_list|(
name|clearParams
argument_list|,
name|mData
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
name|error
operator|=
name|invalidateSwizzles
argument_list|()
expr_stmt|;
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
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|getRenderTargetResource
specifier|static
name|gl
operator|::
name|Error
name|getRenderTargetResource
parameter_list|(
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|colorbuffer
parameter_list|,
name|unsigned
name|int
modifier|*
name|subresourceIndexOut
parameter_list|,
name|ID3D11Texture2D
modifier|*
modifier|*
name|texture2DOut
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|colorbuffer
argument_list|)
expr_stmt|;
name|RenderTarget11
modifier|*
name|renderTarget
init|=
name|NULL
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|d3d11
operator|::
name|GetAttachmentRenderTarget
argument_list|(
name|colorbuffer
argument_list|,
operator|&
name|renderTarget
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
name|ID3D11Resource
modifier|*
name|renderTargetResource
init|=
name|renderTarget
operator|->
name|getTexture
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|renderTargetResource
argument_list|)
expr_stmt|;
operator|*
name|subresourceIndexOut
operator|=
name|renderTarget
operator|->
name|getSubresourceIndex
argument_list|()
expr_stmt|;
operator|*
name|texture2DOut
operator|=
name|d3d11
operator|::
name|DynamicCastComObject
argument_list|<
name|ID3D11Texture2D
argument_list|>
argument_list|(
name|renderTargetResource
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
operator|*
name|texture2DOut
operator|)
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to query the ID3D11Texture2D from a RenderTarget"
argument_list|)
return|;
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
DECL|function|readPixels
name|gl
operator|::
name|Error
name|Framebuffer11
operator|::
name|readPixels
parameter_list|(
specifier|const
name|gl
operator|::
name|Rectangle
modifier|&
name|area
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|size_t
name|outputPitch
parameter_list|,
specifier|const
name|gl
operator|::
name|PixelPackState
modifier|&
name|pack
parameter_list|,
name|uint8_t
modifier|*
name|pixels
parameter_list|)
specifier|const
block|{
name|ID3D11Texture2D
modifier|*
name|colorBufferTexture
init|=
name|NULL
decl_stmt|;
name|unsigned
name|int
name|subresourceIndex
init|=
literal|0
decl_stmt|;
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|colorbuffer
init|=
name|mData
operator|.
name|getReadAttachment
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|colorbuffer
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|getRenderTargetResource
argument_list|(
name|colorbuffer
argument_list|,
operator|&
name|subresourceIndex
argument_list|,
operator|&
name|colorBufferTexture
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
name|gl
operator|::
name|Buffer
modifier|*
name|packBuffer
init|=
name|pack
operator|.
name|pixelBuffer
operator|.
name|get
argument_list|()
decl_stmt|;
if|if
condition|(
name|packBuffer
operator|!=
name|NULL
condition|)
block|{
name|Buffer11
modifier|*
name|packBufferStorage
init|=
name|Buffer11
operator|::
name|makeBuffer11
argument_list|(
name|packBuffer
operator|->
name|getImplementation
argument_list|()
argument_list|)
decl_stmt|;
name|PackPixelsParams
name|packParams
argument_list|(
name|area
argument_list|,
name|format
argument_list|,
name|type
argument_list|,
name|outputPitch
argument_list|,
name|pack
argument_list|,
cast|reinterpret_cast
argument_list|<
name|ptrdiff_t
argument_list|>
argument_list|(
name|pixels
argument_list|)
argument_list|)
decl_stmt|;
name|error
operator|=
name|packBufferStorage
operator|->
name|packPixels
argument_list|(
name|colorBufferTexture
argument_list|,
name|subresourceIndex
argument_list|,
name|packParams
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|SafeRelease
argument_list|(
name|colorBufferTexture
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
name|packBuffer
operator|->
name|getIndexRangeCache
argument_list|()
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|error
operator|=
name|mRenderer
operator|->
name|readTextureData
argument_list|(
name|colorBufferTexture
argument_list|,
name|subresourceIndex
argument_list|,
name|area
argument_list|,
name|format
argument_list|,
name|type
argument_list|,
name|outputPitch
argument_list|,
name|pack
argument_list|,
name|pixels
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|SafeRelease
argument_list|(
name|colorBufferTexture
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
block|}
name|SafeRelease
argument_list|(
name|colorBufferTexture
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
DECL|function|blit
name|gl
operator|::
name|Error
name|Framebuffer11
operator|::
name|blit
parameter_list|(
specifier|const
name|gl
operator|::
name|Rectangle
modifier|&
name|sourceArea
parameter_list|,
specifier|const
name|gl
operator|::
name|Rectangle
modifier|&
name|destArea
parameter_list|,
specifier|const
name|gl
operator|::
name|Rectangle
modifier|*
name|scissor
parameter_list|,
name|bool
name|blitRenderTarget
parameter_list|,
name|bool
name|blitDepth
parameter_list|,
name|bool
name|blitStencil
parameter_list|,
name|GLenum
name|filter
parameter_list|,
specifier|const
name|gl
operator|::
name|Framebuffer
modifier|*
name|sourceFramebuffer
parameter_list|)
block|{
if|if
condition|(
name|blitRenderTarget
condition|)
block|{
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|readBuffer
init|=
name|sourceFramebuffer
operator|->
name|getReadColorbuffer
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|readBuffer
argument_list|)
expr_stmt|;
name|RenderTargetD3D
modifier|*
name|readRenderTarget
init|=
name|NULL
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|GetAttachmentRenderTarget
argument_list|(
name|readBuffer
argument_list|,
operator|&
name|readRenderTarget
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
name|ASSERT
argument_list|(
name|readRenderTarget
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|colorAttachment
init|=
literal|0
init|;
name|colorAttachment
operator|<
name|mData
operator|.
name|mColorAttachments
operator|.
name|size
argument_list|()
condition|;
name|colorAttachment
operator|++
control|)
block|{
if|if
condition|(
name|mData
operator|.
name|mColorAttachments
index|[
name|colorAttachment
index|]
operator|!=
literal|nullptr
operator|&&
name|mData
operator|.
name|mDrawBufferStates
index|[
name|colorAttachment
index|]
operator|!=
name|GL_NONE
condition|)
block|{
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|drawBuffer
init|=
name|mData
operator|.
name|mColorAttachments
index|[
name|colorAttachment
index|]
decl_stmt|;
name|RenderTargetD3D
modifier|*
name|drawRenderTarget
init|=
name|NULL
decl_stmt|;
name|error
operator|=
name|GetAttachmentRenderTarget
argument_list|(
name|drawBuffer
argument_list|,
operator|&
name|drawRenderTarget
argument_list|)
expr_stmt|;
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
name|ASSERT
argument_list|(
name|drawRenderTarget
argument_list|)
expr_stmt|;
name|error
operator|=
name|mRenderer
operator|->
name|blitRenderbufferRect
argument_list|(
name|sourceArea
argument_list|,
name|destArea
argument_list|,
name|readRenderTarget
argument_list|,
name|drawRenderTarget
argument_list|,
name|filter
argument_list|,
name|scissor
argument_list|,
name|blitRenderTarget
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|)
expr_stmt|;
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
block|}
block|}
if|if
condition|(
name|blitDepth
operator|||
name|blitStencil
condition|)
block|{
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|readBuffer
init|=
name|sourceFramebuffer
operator|->
name|getDepthOrStencilbuffer
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|readBuffer
argument_list|)
expr_stmt|;
name|RenderTargetD3D
modifier|*
name|readRenderTarget
init|=
name|NULL
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|GetAttachmentRenderTarget
argument_list|(
name|readBuffer
argument_list|,
operator|&
name|readRenderTarget
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
name|ASSERT
argument_list|(
name|readRenderTarget
argument_list|)
expr_stmt|;
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|drawBuffer
init|=
name|mData
operator|.
name|getDepthOrStencilAttachment
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|drawBuffer
argument_list|)
expr_stmt|;
name|RenderTargetD3D
modifier|*
name|drawRenderTarget
init|=
name|NULL
decl_stmt|;
name|error
operator|=
name|GetAttachmentRenderTarget
argument_list|(
name|drawBuffer
argument_list|,
operator|&
name|drawRenderTarget
argument_list|)
expr_stmt|;
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
name|ASSERT
argument_list|(
name|drawRenderTarget
argument_list|)
expr_stmt|;
name|error
operator|=
name|mRenderer
operator|->
name|blitRenderbufferRect
argument_list|(
name|sourceArea
argument_list|,
name|destArea
argument_list|,
name|readRenderTarget
argument_list|,
name|drawRenderTarget
argument_list|,
name|filter
argument_list|,
name|scissor
argument_list|,
literal|false
argument_list|,
name|blitDepth
argument_list|,
name|blitStencil
argument_list|)
expr_stmt|;
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
name|gl
operator|::
name|Error
name|error
init|=
name|invalidateSwizzles
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
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|getRenderTargetImplementationFormat
name|GLenum
name|Framebuffer11
operator|::
name|getRenderTargetImplementationFormat
parameter_list|(
name|RenderTargetD3D
modifier|*
name|renderTarget
parameter_list|)
specifier|const
block|{
name|RenderTarget11
modifier|*
name|renderTarget11
init|=
name|RenderTarget11
operator|::
name|makeRenderTarget11
argument_list|(
name|renderTarget
argument_list|)
decl_stmt|;
specifier|const
name|d3d11
operator|::
name|DXGIFormat
modifier|&
name|dxgiFormatInfo
init|=
name|d3d11
operator|::
name|GetDXGIFormatInfo
argument_list|(
name|renderTarget11
operator|->
name|getDXGIFormat
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|dxgiFormatInfo
operator|.
name|internalFormat
return|;
block|}
block|}
end_namespace
end_unit