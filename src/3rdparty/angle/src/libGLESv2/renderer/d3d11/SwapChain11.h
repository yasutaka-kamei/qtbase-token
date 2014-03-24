begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// SwapChain11.h: Defines a back-end specific class for the D3D11 swap chain.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_SWAPCHAIN11_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_SWAPCHAIN11_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_SWAPCHAIN11_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/SwapChain.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer11
decl_stmt|;
name|class
name|SwapChain11
range|:
name|public
name|SwapChain
block|{
name|public
operator|:
name|SwapChain11
argument_list|(
argument|Renderer11 *renderer
argument_list|,
argument|EGLNativeWindowType window
argument_list|,
argument|HANDLE shareHandle
argument_list|,
argument|GLenum backBufferFormat
argument_list|,
argument|GLenum depthBufferFormat
argument_list|)
block|;
name|virtual
operator|~
name|SwapChain11
argument_list|()
block|;
name|EGLint
name|resize
argument_list|(
argument|EGLint backbufferWidth
argument_list|,
argument|EGLint backbufferHeight
argument_list|)
block|;
name|virtual
name|EGLint
name|reset
argument_list|(
argument|EGLint backbufferWidth
argument_list|,
argument|EGLint backbufferHeight
argument_list|,
argument|EGLint swapInterval
argument_list|)
block|;
name|virtual
name|EGLint
name|swapRect
argument_list|(
argument|EGLint x
argument_list|,
argument|EGLint y
argument_list|,
argument|EGLint width
argument_list|,
argument|EGLint height
argument_list|)
block|;
name|virtual
name|void
name|recreate
argument_list|()
block|;
name|virtual
name|ID3D11Texture2D
operator|*
name|getOffscreenTexture
argument_list|()
block|;
name|virtual
name|ID3D11RenderTargetView
operator|*
name|getRenderTarget
argument_list|()
block|;
name|virtual
name|ID3D11ShaderResourceView
operator|*
name|getRenderTargetShaderResource
argument_list|()
block|;
name|virtual
name|ID3D11Texture2D
operator|*
name|getDepthStencilTexture
argument_list|()
block|;
name|virtual
name|ID3D11DepthStencilView
operator|*
name|getDepthStencil
argument_list|()
block|;
name|EGLint
name|getWidth
argument_list|()
specifier|const
block|{
return|return
name|mWidth
return|;
block|}
name|EGLint
name|getHeight
argument_list|()
specifier|const
block|{
return|return
name|mHeight
return|;
block|}
specifier|static
name|SwapChain11
operator|*
name|makeSwapChain11
argument_list|(
name|SwapChain
operator|*
name|swapChain
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|SwapChain11
argument_list|)
block|;
name|void
name|release
argument_list|()
block|;
name|void
name|initPassThroughResources
argument_list|()
block|;
name|void
name|releaseOffscreenTexture
argument_list|()
block|;
name|EGLint
name|resetOffscreenTexture
argument_list|(
argument|int backbufferWidth
argument_list|,
argument|int backbufferHeight
argument_list|)
block|;
name|Renderer11
operator|*
name|mRenderer
block|;
name|EGLint
name|mHeight
block|;
name|EGLint
name|mWidth
block|;
name|bool
name|mAppCreatedShareHandle
block|;
name|unsigned
name|int
name|mSwapInterval
block|;
name|bool
name|mPassThroughResourcesInit
block|;
name|IDXGISwapChain
operator|*
name|mSwapChain
block|;
name|ID3D11Texture2D
operator|*
name|mBackBufferTexture
block|;
name|ID3D11RenderTargetView
operator|*
name|mBackBufferRTView
block|;
name|ID3D11Texture2D
operator|*
name|mOffscreenTexture
block|;
name|ID3D11RenderTargetView
operator|*
name|mOffscreenRTView
block|;
name|ID3D11ShaderResourceView
operator|*
name|mOffscreenSRView
block|;
name|ID3D11Texture2D
operator|*
name|mDepthStencilTexture
block|;
name|ID3D11DepthStencilView
operator|*
name|mDepthStencilDSView
block|;
name|ID3D11Buffer
operator|*
name|mQuadVB
block|;
name|ID3D11SamplerState
operator|*
name|mPassThroughSampler
block|;
name|ID3D11InputLayout
operator|*
name|mPassThroughIL
block|;
name|ID3D11VertexShader
operator|*
name|mPassThroughVS
block|;
name|ID3D11PixelShader
operator|*
name|mPassThroughPS
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_SWAPCHAIN11_H_
end_comment
end_unit