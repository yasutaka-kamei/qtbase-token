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
comment|// SwapChain9.h: Defines a back-end specific class for the D3D9 swap chain.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D9_SWAPCHAIN9_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D9_SWAPCHAIN9_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D9_SWAPCHAIN9_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/SwapChainD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/RenderTarget9.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer9
decl_stmt|;
name|class
name|SwapChain9
range|:
name|public
name|SwapChainD3D
block|{
name|public
operator|:
name|SwapChain9
argument_list|(
argument|Renderer9 *renderer
argument_list|,
argument|NativeWindow nativeWindow
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
name|SwapChain9
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
name|RenderTargetD3D
operator|*
name|getColorRenderTarget
argument_list|()
name|override
block|{
return|return
operator|&
name|mColorRenderTarget
return|;
block|}
name|RenderTargetD3D
operator|*
name|getDepthStencilRenderTarget
argument_list|()
name|override
block|{
return|return
operator|&
name|mDepthStencilRenderTarget
return|;
block|}
name|virtual
name|IDirect3DSurface9
operator|*
name|getRenderTarget
argument_list|()
block|;
name|virtual
name|IDirect3DSurface9
operator|*
name|getDepthStencil
argument_list|()
block|;
name|virtual
name|IDirect3DTexture9
operator|*
name|getOffscreenTexture
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
name|SwapChain9
operator|*
name|makeSwapChain9
argument_list|(
name|SwapChainD3D
operator|*
name|swapChain
argument_list|)
block|;
name|private
operator|:
name|void
name|release
argument_list|()
block|;
name|Renderer9
operator|*
name|mRenderer
block|;
name|EGLint
name|mHeight
block|;
name|EGLint
name|mWidth
block|;
name|EGLint
name|mSwapInterval
block|;
name|IDirect3DSwapChain9
operator|*
name|mSwapChain
block|;
name|IDirect3DSurface9
operator|*
name|mBackBuffer
block|;
name|IDirect3DSurface9
operator|*
name|mRenderTarget
block|;
name|IDirect3DSurface9
operator|*
name|mDepthStencil
block|;
name|IDirect3DTexture9
operator|*
name|mOffscreenTexture
block|;
name|SurfaceRenderTarget9
name|mColorRenderTarget
block|;
name|SurfaceRenderTarget9
name|mDepthStencilRenderTarget
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D9_SWAPCHAIN9_H_
end_comment
end_unit