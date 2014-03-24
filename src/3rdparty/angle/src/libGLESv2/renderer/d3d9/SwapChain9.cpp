begin_unit
begin_include
include|#
directive|include
file|"precompiled.h"
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// SwapChain9.cpp: Implements a back-end specific class for the D3D9 swap chain.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d9/SwapChain9.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d9/renderer9_utils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d9/Renderer9.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|SwapChain9
name|SwapChain9
operator|::
name|SwapChain9
parameter_list|(
name|Renderer9
modifier|*
name|renderer
parameter_list|,
name|HWND
name|window
parameter_list|,
name|HANDLE
name|shareHandle
parameter_list|,
name|GLenum
name|backBufferFormat
parameter_list|,
name|GLenum
name|depthBufferFormat
parameter_list|)
member_init_list|:
name|mRenderer
argument_list|(
name|renderer
argument_list|)
member_init_list|,
name|SwapChain
argument_list|(
name|window
argument_list|,
name|shareHandle
argument_list|,
name|backBufferFormat
argument_list|,
name|depthBufferFormat
argument_list|)
block|{
name|mSwapChain
operator|=
name|NULL
expr_stmt|;
name|mBackBuffer
operator|=
name|NULL
expr_stmt|;
name|mDepthStencil
operator|=
name|NULL
expr_stmt|;
name|mRenderTarget
operator|=
name|NULL
expr_stmt|;
name|mOffscreenTexture
operator|=
name|NULL
expr_stmt|;
name|mWidth
operator|=
operator|-
literal|1
expr_stmt|;
name|mHeight
operator|=
operator|-
literal|1
expr_stmt|;
name|mSwapInterval
operator|=
operator|-
literal|1
expr_stmt|;
block|}
DECL|function|~SwapChain9
name|SwapChain9
operator|::
name|~
name|SwapChain9
parameter_list|()
block|{
name|release
argument_list|()
expr_stmt|;
block|}
DECL|function|release
name|void
name|SwapChain9
operator|::
name|release
parameter_list|()
block|{
if|if
condition|(
name|mSwapChain
condition|)
block|{
name|mSwapChain
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mSwapChain
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mBackBuffer
condition|)
block|{
name|mBackBuffer
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mBackBuffer
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mDepthStencil
condition|)
block|{
name|mDepthStencil
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mDepthStencil
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mRenderTarget
condition|)
block|{
name|mRenderTarget
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mRenderTarget
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mOffscreenTexture
condition|)
block|{
name|mOffscreenTexture
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mOffscreenTexture
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mWindow
condition|)
name|mShareHandle
operator|=
name|NULL
expr_stmt|;
block|}
DECL|function|convertInterval
specifier|static
name|DWORD
name|convertInterval
parameter_list|(
name|EGLint
name|interval
parameter_list|)
block|{
if|#
directive|if
name|ANGLE_FORCE_VSYNC_OFF
return|return
name|D3DPRESENT_INTERVAL_IMMEDIATE
return|;
else|#
directive|else
switch|switch
condition|(
name|interval
condition|)
block|{
case|case
literal|0
case|:
return|return
name|D3DPRESENT_INTERVAL_IMMEDIATE
return|;
case|case
literal|1
case|:
return|return
name|D3DPRESENT_INTERVAL_ONE
return|;
case|case
literal|2
case|:
return|return
name|D3DPRESENT_INTERVAL_TWO
return|;
case|case
literal|3
case|:
return|return
name|D3DPRESENT_INTERVAL_THREE
return|;
case|case
literal|4
case|:
return|return
name|D3DPRESENT_INTERVAL_FOUR
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|D3DPRESENT_INTERVAL_DEFAULT
return|;
endif|#
directive|endif
block|}
DECL|function|resize
name|EGLint
name|SwapChain9
operator|::
name|resize
parameter_list|(
name|int
name|backbufferWidth
parameter_list|,
name|int
name|backbufferHeight
parameter_list|)
block|{
comment|// D3D9 does not support resizing swap chains without recreating them
return|return
name|reset
argument_list|(
name|backbufferWidth
argument_list|,
name|backbufferHeight
argument_list|,
name|mSwapInterval
argument_list|)
return|;
block|}
DECL|function|reset
name|EGLint
name|SwapChain9
operator|::
name|reset
parameter_list|(
name|int
name|backbufferWidth
parameter_list|,
name|int
name|backbufferHeight
parameter_list|,
name|EGLint
name|swapInterval
parameter_list|)
block|{
name|IDirect3DDevice9
modifier|*
name|device
init|=
name|mRenderer
operator|->
name|getDevice
argument_list|()
decl_stmt|;
if|if
condition|(
name|device
operator|==
name|NULL
condition|)
block|{
return|return
name|EGL_BAD_ACCESS
return|;
block|}
comment|// Evict all non-render target textures to system memory and release all resources
comment|// before reallocating them to free up as much video memory as possible.
name|device
operator|->
name|EvictManagedResources
argument_list|()
expr_stmt|;
name|HRESULT
name|result
decl_stmt|;
comment|// Release specific resources to free up memory for the new render target, while the
comment|// old render target still exists for the purpose of preserving its contents.
if|if
condition|(
name|mSwapChain
condition|)
block|{
name|mSwapChain
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mSwapChain
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mBackBuffer
condition|)
block|{
name|mBackBuffer
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mBackBuffer
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mOffscreenTexture
condition|)
block|{
name|mOffscreenTexture
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mOffscreenTexture
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|mDepthStencil
condition|)
block|{
name|mDepthStencil
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mDepthStencil
operator|=
name|NULL
expr_stmt|;
block|}
name|HANDLE
modifier|*
name|pShareHandle
init|=
name|NULL
decl_stmt|;
if|if
condition|(
operator|!
name|mWindow
operator|&&
name|mRenderer
operator|->
name|getShareHandleSupport
argument_list|()
condition|)
block|{
name|pShareHandle
operator|=
operator|&
name|mShareHandle
expr_stmt|;
block|}
name|result
operator|=
name|device
operator|->
name|CreateTexture
argument_list|(
name|backbufferWidth
argument_list|,
name|backbufferHeight
argument_list|,
literal|1
argument_list|,
name|D3DUSAGE_RENDERTARGET
argument_list|,
name|gl_d3d9
operator|::
name|ConvertRenderbufferFormat
argument_list|(
name|mBackBufferFormat
argument_list|)
argument_list|,
name|D3DPOOL_DEFAULT
argument_list|,
operator|&
name|mOffscreenTexture
argument_list|,
name|pShareHandle
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|ERR
argument_list|(
literal|"Could not create offscreen texture: %08lX"
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|release
argument_list|()
expr_stmt|;
if|if
condition|(
name|d3d9
operator|::
name|isDeviceLostError
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|EGL_CONTEXT_LOST
return|;
block|}
else|else
block|{
return|return
name|EGL_BAD_ALLOC
return|;
block|}
block|}
name|IDirect3DSurface9
modifier|*
name|oldRenderTarget
init|=
name|mRenderTarget
decl_stmt|;
name|result
operator|=
name|mOffscreenTexture
operator|->
name|GetSurfaceLevel
argument_list|(
literal|0
argument_list|,
operator|&
name|mRenderTarget
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|oldRenderTarget
condition|)
block|{
name|RECT
name|rect
init|=
block|{
literal|0
block|,
literal|0
block|,
name|mWidth
block|,
name|mHeight
block|}
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|right
operator|>
cast|static_cast
argument_list|<
name|LONG
argument_list|>
argument_list|(
name|backbufferWidth
argument_list|)
condition|)
block|{
name|rect
operator|.
name|right
operator|=
name|backbufferWidth
expr_stmt|;
block|}
if|if
condition|(
name|rect
operator|.
name|bottom
operator|>
cast|static_cast
argument_list|<
name|LONG
argument_list|>
argument_list|(
name|backbufferHeight
argument_list|)
condition|)
block|{
name|rect
operator|.
name|bottom
operator|=
name|backbufferHeight
expr_stmt|;
block|}
name|mRenderer
operator|->
name|endScene
argument_list|()
expr_stmt|;
name|result
operator|=
name|device
operator|->
name|StretchRect
argument_list|(
name|oldRenderTarget
argument_list|,
operator|&
name|rect
argument_list|,
name|mRenderTarget
argument_list|,
operator|&
name|rect
argument_list|,
name|D3DTEXF_NONE
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
name|oldRenderTarget
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|mWindow
condition|)
block|{
name|D3DPRESENT_PARAMETERS
name|presentParameters
init|=
block|{
literal|0
block|}
decl_stmt|;
name|presentParameters
operator|.
name|AutoDepthStencilFormat
operator|=
name|gl_d3d9
operator|::
name|ConvertRenderbufferFormat
argument_list|(
name|mDepthBufferFormat
argument_list|)
expr_stmt|;
name|presentParameters
operator|.
name|BackBufferCount
operator|=
literal|1
expr_stmt|;
name|presentParameters
operator|.
name|BackBufferFormat
operator|=
name|gl_d3d9
operator|::
name|ConvertRenderbufferFormat
argument_list|(
name|mBackBufferFormat
argument_list|)
expr_stmt|;
name|presentParameters
operator|.
name|EnableAutoDepthStencil
operator|=
name|FALSE
expr_stmt|;
name|presentParameters
operator|.
name|Flags
operator|=
literal|0
expr_stmt|;
name|presentParameters
operator|.
name|hDeviceWindow
operator|=
name|mWindow
expr_stmt|;
name|presentParameters
operator|.
name|MultiSampleQuality
operator|=
literal|0
expr_stmt|;
comment|// FIXME: Unimplemented
name|presentParameters
operator|.
name|MultiSampleType
operator|=
name|D3DMULTISAMPLE_NONE
expr_stmt|;
comment|// FIXME: Unimplemented
name|presentParameters
operator|.
name|PresentationInterval
operator|=
name|convertInterval
argument_list|(
name|swapInterval
argument_list|)
expr_stmt|;
name|presentParameters
operator|.
name|SwapEffect
operator|=
name|D3DSWAPEFFECT_DISCARD
expr_stmt|;
name|presentParameters
operator|.
name|Windowed
operator|=
name|TRUE
expr_stmt|;
name|presentParameters
operator|.
name|BackBufferWidth
operator|=
name|backbufferWidth
expr_stmt|;
name|presentParameters
operator|.
name|BackBufferHeight
operator|=
name|backbufferHeight
expr_stmt|;
comment|// http://crbug.com/140239
comment|// http://crbug.com/143434
comment|//
comment|// Some AMD/Intel switchable systems / drivers appear to round swap chain surfaces to a multiple of 64 pixels in width
comment|// when using the integrated Intel. This rounds the width up rather than down.
comment|//
comment|// Some non-switchable AMD GPUs / drivers do not respect the source rectangle to Present. Therefore, when the vendor ID
comment|// is not Intel, the back buffer width must be exactly the same width as the window or horizontal scaling will occur.
if|if
condition|(
name|mRenderer
operator|->
name|getAdapterVendor
argument_list|()
operator|==
name|VENDOR_ID_INTEL
condition|)
block|{
name|presentParameters
operator|.
name|BackBufferWidth
operator|=
operator|(
name|presentParameters
operator|.
name|BackBufferWidth
operator|+
literal|63
operator|)
operator|/
literal|64
operator|*
literal|64
expr_stmt|;
block|}
name|result
operator|=
name|device
operator|->
name|CreateAdditionalSwapChain
argument_list|(
operator|&
name|presentParameters
argument_list|,
operator|&
name|mSwapChain
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|ASSERT
argument_list|(
name|result
operator|==
name|D3DERR_OUTOFVIDEOMEMORY
operator|||
name|result
operator|==
name|E_OUTOFMEMORY
operator|||
name|result
operator|==
name|D3DERR_INVALIDCALL
operator|||
name|result
operator|==
name|D3DERR_DEVICELOST
argument_list|)
expr_stmt|;
name|ERR
argument_list|(
literal|"Could not create additional swap chains or offscreen surfaces: %08lX"
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|release
argument_list|()
expr_stmt|;
if|if
condition|(
name|d3d9
operator|::
name|isDeviceLostError
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|EGL_CONTEXT_LOST
return|;
block|}
else|else
block|{
return|return
name|EGL_BAD_ALLOC
return|;
block|}
block|}
name|result
operator|=
name|mSwapChain
operator|->
name|GetBackBuffer
argument_list|(
literal|0
argument_list|,
name|D3DBACKBUFFER_TYPE_MONO
argument_list|,
operator|&
name|mBackBuffer
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
name|InvalidateRect
argument_list|(
name|mWindow
argument_list|,
name|NULL
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mDepthBufferFormat
operator|!=
name|GL_NONE
condition|)
block|{
name|result
operator|=
name|device
operator|->
name|CreateDepthStencilSurface
argument_list|(
name|backbufferWidth
argument_list|,
name|backbufferHeight
argument_list|,
name|gl_d3d9
operator|::
name|ConvertRenderbufferFormat
argument_list|(
name|mDepthBufferFormat
argument_list|)
argument_list|,
name|D3DMULTISAMPLE_NONE
argument_list|,
literal|0
argument_list|,
name|FALSE
argument_list|,
operator|&
name|mDepthStencil
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|ASSERT
argument_list|(
name|result
operator|==
name|D3DERR_OUTOFVIDEOMEMORY
operator|||
name|result
operator|==
name|E_OUTOFMEMORY
operator|||
name|result
operator|==
name|D3DERR_INVALIDCALL
argument_list|)
expr_stmt|;
name|ERR
argument_list|(
literal|"Could not create depthstencil surface for new swap chain: 0x%08X"
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|release
argument_list|()
expr_stmt|;
if|if
condition|(
name|d3d9
operator|::
name|isDeviceLostError
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|EGL_CONTEXT_LOST
return|;
block|}
else|else
block|{
return|return
name|EGL_BAD_ALLOC
return|;
block|}
block|}
block|}
name|mWidth
operator|=
name|backbufferWidth
expr_stmt|;
name|mHeight
operator|=
name|backbufferHeight
expr_stmt|;
name|mSwapInterval
operator|=
name|swapInterval
expr_stmt|;
return|return
name|EGL_SUCCESS
return|;
block|}
comment|// parameters should be validated/clamped by caller
DECL|function|swapRect
name|EGLint
name|SwapChain9
operator|::
name|swapRect
parameter_list|(
name|EGLint
name|x
parameter_list|,
name|EGLint
name|y
parameter_list|,
name|EGLint
name|width
parameter_list|,
name|EGLint
name|height
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mSwapChain
condition|)
block|{
return|return
name|EGL_SUCCESS
return|;
block|}
name|IDirect3DDevice9
modifier|*
name|device
init|=
name|mRenderer
operator|->
name|getDevice
argument_list|()
decl_stmt|;
comment|// Disable all pipeline operations
name|device
operator|->
name|SetRenderState
argument_list|(
name|D3DRS_ZENABLE
argument_list|,
name|D3DZB_FALSE
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetRenderState
argument_list|(
name|D3DRS_FILLMODE
argument_list|,
name|D3DFILL_SOLID
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetRenderState
argument_list|(
name|D3DRS_ALPHATESTENABLE
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetRenderState
argument_list|(
name|D3DRS_ALPHABLENDENABLE
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetRenderState
argument_list|(
name|D3DRS_CULLMODE
argument_list|,
name|D3DCULL_NONE
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetRenderState
argument_list|(
name|D3DRS_STENCILENABLE
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetRenderState
argument_list|(
name|D3DRS_CLIPPLANEENABLE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetRenderState
argument_list|(
name|D3DRS_COLORWRITEENABLE
argument_list|,
name|D3DCOLORWRITEENABLE_ALPHA
operator||
name|D3DCOLORWRITEENABLE_BLUE
operator||
name|D3DCOLORWRITEENABLE_GREEN
operator||
name|D3DCOLORWRITEENABLE_RED
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetRenderState
argument_list|(
name|D3DRS_SRGBWRITEENABLE
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetRenderState
argument_list|(
name|D3DRS_SCISSORTESTENABLE
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetPixelShader
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetVertexShader
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetRenderTarget
argument_list|(
literal|0
argument_list|,
name|mBackBuffer
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetDepthStencilSurface
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetTexture
argument_list|(
literal|0
argument_list|,
name|mOffscreenTexture
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetTextureStageState
argument_list|(
literal|0
argument_list|,
name|D3DTSS_COLOROP
argument_list|,
name|D3DTOP_SELECTARG1
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetTextureStageState
argument_list|(
literal|0
argument_list|,
name|D3DTSS_COLORARG1
argument_list|,
name|D3DTA_TEXTURE
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetTextureStageState
argument_list|(
literal|1
argument_list|,
name|D3DTSS_COLOROP
argument_list|,
name|D3DTOP_DISABLE
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetSamplerState
argument_list|(
literal|0
argument_list|,
name|D3DSAMP_MAGFILTER
argument_list|,
name|D3DTEXF_POINT
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetSamplerState
argument_list|(
literal|0
argument_list|,
name|D3DSAMP_MINFILTER
argument_list|,
name|D3DTEXF_POINT
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetSamplerState
argument_list|(
literal|0
argument_list|,
name|D3DSAMP_ADDRESSU
argument_list|,
name|D3DTADDRESS_CLAMP
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetSamplerState
argument_list|(
literal|0
argument_list|,
name|D3DSAMP_ADDRESSV
argument_list|,
name|D3DTADDRESS_CLAMP
argument_list|)
expr_stmt|;
name|device
operator|->
name|SetFVF
argument_list|(
name|D3DFVF_XYZRHW
operator||
name|D3DFVF_TEX1
argument_list|)
expr_stmt|;
for|for
control|(
name|UINT
name|streamIndex
init|=
literal|0
init|;
name|streamIndex
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|streamIndex
operator|++
control|)
block|{
name|device
operator|->
name|SetStreamSourceFreq
argument_list|(
name|streamIndex
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|D3DVIEWPORT9
name|viewport
init|=
block|{
literal|0
block|,
literal|0
block|,
name|mWidth
block|,
name|mHeight
block|,
literal|0.0f
block|,
literal|1.0f
block|}
decl_stmt|;
name|device
operator|->
name|SetViewport
argument_list|(
operator|&
name|viewport
argument_list|)
expr_stmt|;
name|float
name|x1
init|=
name|x
operator|-
literal|0.5f
decl_stmt|;
name|float
name|y1
init|=
operator|(
name|mHeight
operator|-
name|y
operator|-
name|height
operator|)
operator|-
literal|0.5f
decl_stmt|;
name|float
name|x2
init|=
operator|(
name|x
operator|+
name|width
operator|)
operator|-
literal|0.5f
decl_stmt|;
name|float
name|y2
init|=
operator|(
name|mHeight
operator|-
name|y
operator|)
operator|-
literal|0.5f
decl_stmt|;
name|float
name|u1
init|=
name|x
operator|/
name|float
argument_list|(
name|mWidth
argument_list|)
decl_stmt|;
name|float
name|v1
init|=
name|y
operator|/
name|float
argument_list|(
name|mHeight
argument_list|)
decl_stmt|;
name|float
name|u2
init|=
operator|(
name|x
operator|+
name|width
operator|)
operator|/
name|float
argument_list|(
name|mWidth
argument_list|)
decl_stmt|;
name|float
name|v2
init|=
operator|(
name|y
operator|+
name|height
operator|)
operator|/
name|float
argument_list|(
name|mHeight
argument_list|)
decl_stmt|;
name|float
name|quad
index|[
literal|4
index|]
index|[
literal|6
index|]
init|=
block|{
block|{
name|x1
block|,
name|y1
block|,
literal|0.0f
block|,
literal|1.0f
block|,
name|u1
block|,
name|v2
block|}
block|,
block|{
name|x2
block|,
name|y1
block|,
literal|0.0f
block|,
literal|1.0f
block|,
name|u2
block|,
name|v2
block|}
block|,
block|{
name|x2
block|,
name|y2
block|,
literal|0.0f
block|,
literal|1.0f
block|,
name|u2
block|,
name|v1
block|}
block|,
block|{
name|x1
block|,
name|y2
block|,
literal|0.0f
block|,
literal|1.0f
block|,
name|u1
block|,
name|v1
block|}
block|}
decl_stmt|;
comment|// x, y, z, rhw, u, v
name|mRenderer
operator|->
name|startScene
argument_list|()
expr_stmt|;
name|device
operator|->
name|DrawPrimitiveUP
argument_list|(
name|D3DPT_TRIANGLEFAN
argument_list|,
literal|2
argument_list|,
name|quad
argument_list|,
literal|6
operator|*
sizeof|sizeof
argument_list|(
name|float
argument_list|)
argument_list|)
expr_stmt|;
name|mRenderer
operator|->
name|endScene
argument_list|()
expr_stmt|;
name|device
operator|->
name|SetTexture
argument_list|(
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|RECT
name|rect
init|=
block|{
name|x
block|,
name|mHeight
operator|-
name|y
operator|-
name|height
block|,
name|x
operator|+
name|width
block|,
name|mHeight
operator|-
name|y
block|}
decl_stmt|;
name|HRESULT
name|result
init|=
name|mSwapChain
operator|->
name|Present
argument_list|(
operator|&
name|rect
argument_list|,
operator|&
name|rect
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|mRenderer
operator|->
name|markAllStateDirty
argument_list|()
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|D3DERR_OUTOFVIDEOMEMORY
operator|||
name|result
operator|==
name|E_OUTOFMEMORY
operator|||
name|result
operator|==
name|D3DERR_DRIVERINTERNALERROR
condition|)
block|{
return|return
name|EGL_BAD_ALLOC
return|;
block|}
comment|// http://crbug.com/313210
comment|// If our swap failed, trigger a device lost event. Resetting will work around an AMD-specific
comment|// device removed bug with lost contexts when reinstalling drivers.
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|mRenderer
operator|->
name|notifyDeviceLost
argument_list|()
expr_stmt|;
return|return
name|EGL_CONTEXT_LOST
return|;
block|}
return|return
name|EGL_SUCCESS
return|;
block|}
comment|// Increments refcount on surface.
comment|// caller must Release() the returned surface
DECL|function|getRenderTarget
name|IDirect3DSurface9
modifier|*
name|SwapChain9
operator|::
name|getRenderTarget
parameter_list|()
block|{
if|if
condition|(
name|mRenderTarget
condition|)
block|{
name|mRenderTarget
operator|->
name|AddRef
argument_list|()
expr_stmt|;
block|}
return|return
name|mRenderTarget
return|;
block|}
comment|// Increments refcount on surface.
comment|// caller must Release() the returned surface
DECL|function|getDepthStencil
name|IDirect3DSurface9
modifier|*
name|SwapChain9
operator|::
name|getDepthStencil
parameter_list|()
block|{
if|if
condition|(
name|mDepthStencil
condition|)
block|{
name|mDepthStencil
operator|->
name|AddRef
argument_list|()
expr_stmt|;
block|}
return|return
name|mDepthStencil
return|;
block|}
comment|// Increments refcount on texture.
comment|// caller must Release() the returned texture
DECL|function|getOffscreenTexture
name|IDirect3DTexture9
modifier|*
name|SwapChain9
operator|::
name|getOffscreenTexture
parameter_list|()
block|{
if|if
condition|(
name|mOffscreenTexture
condition|)
block|{
name|mOffscreenTexture
operator|->
name|AddRef
argument_list|()
expr_stmt|;
block|}
return|return
name|mOffscreenTexture
return|;
block|}
DECL|function|makeSwapChain9
name|SwapChain9
modifier|*
name|SwapChain9
operator|::
name|makeSwapChain9
parameter_list|(
name|SwapChain
modifier|*
name|swapChain
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|HAS_DYNAMIC_TYPE
argument_list|(
name|rx
operator|::
name|SwapChain9
operator|*
argument_list|,
name|swapChain
argument_list|)
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|rx
operator|::
name|SwapChain9
operator|*
argument_list|>
argument_list|(
name|swapChain
argument_list|)
return|;
block|}
DECL|function|recreate
name|void
name|SwapChain9
operator|::
name|recreate
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mSwapChain
condition|)
block|{
return|return;
block|}
name|IDirect3DDevice9
modifier|*
name|device
init|=
name|mRenderer
operator|->
name|getDevice
argument_list|()
decl_stmt|;
if|if
condition|(
name|device
operator|==
name|NULL
condition|)
block|{
return|return;
block|}
name|D3DPRESENT_PARAMETERS
name|presentParameters
decl_stmt|;
name|HRESULT
name|result
init|=
name|mSwapChain
operator|->
name|GetPresentParameters
argument_list|(
operator|&
name|presentParameters
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
name|IDirect3DSwapChain9
modifier|*
name|newSwapChain
init|=
name|NULL
decl_stmt|;
name|result
operator|=
name|device
operator|->
name|CreateAdditionalSwapChain
argument_list|(
operator|&
name|presentParameters
argument_list|,
operator|&
name|newSwapChain
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return;
block|}
name|mSwapChain
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mSwapChain
operator|=
name|newSwapChain
expr_stmt|;
name|mBackBuffer
operator|->
name|Release
argument_list|()
expr_stmt|;
name|result
operator|=
name|mSwapChain
operator|->
name|GetBackBuffer
argument_list|(
literal|0
argument_list|,
name|D3DBACKBUFFER_TYPE_MONO
argument_list|,
operator|&
name|mBackBuffer
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
end_unit