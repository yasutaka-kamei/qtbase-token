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
comment|// Surface.h: Defines the egl::Surface class, representing a drawing surface
end_comment
begin_comment
comment|// such as the client area of a window, including any back buffers.
end_comment
begin_comment
comment|// Implements EGLSurface and related functionality. [EGL 1.4] section 2.2 page 3.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|INCLUDE_SURFACE_H_
end_ifndef
begin_define
DECL|macro|INCLUDE_SURFACE_H_
define|#
directive|define
name|INCLUDE_SURFACE_H_
end_define
begin_define
DECL|macro|EGLAPI
define|#
directive|define
name|EGLAPI
end_define
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<d3d9.h>
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Texture2D
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|Display
decl_stmt|;
name|class
name|Config
decl_stmt|;
name|class
name|Surface
block|{
name|public
label|:
name|Surface
argument_list|(
argument|Display *display
argument_list|,
argument|const egl::Config *config
argument_list|,
argument|HWND window
argument_list|,
argument|EGLint postSubBufferSupported
argument_list|)
empty_stmt|;
name|Surface
argument_list|(
argument|Display *display
argument_list|,
argument|const egl::Config *config
argument_list|,
argument|HANDLE shareHandle
argument_list|,
argument|EGLint width
argument_list|,
argument|EGLint height
argument_list|,
argument|EGLenum textureFormat
argument_list|,
argument|EGLenum textureTarget
argument_list|)
empty_stmt|;
operator|~
name|Surface
argument_list|()
expr_stmt|;
name|bool
name|initialize
parameter_list|()
function_decl|;
name|void
name|release
parameter_list|()
function_decl|;
name|bool
name|resetSwapChain
parameter_list|()
function_decl|;
name|HWND
name|getWindowHandle
parameter_list|()
function_decl|;
name|bool
name|swap
parameter_list|()
function_decl|;
name|bool
name|postSubBuffer
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
function_decl|;
name|virtual
name|EGLint
name|getWidth
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|EGLint
name|getHeight
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|EGLint
name|isPostSubBufferSupported
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|IDirect3DSurface9
modifier|*
name|getRenderTarget
parameter_list|()
function_decl|;
name|virtual
name|IDirect3DSurface9
modifier|*
name|getDepthStencil
parameter_list|()
function_decl|;
name|virtual
name|IDirect3DTexture9
modifier|*
name|getOffscreenTexture
parameter_list|()
function_decl|;
name|HANDLE
name|getShareHandle
parameter_list|()
block|{
return|return
name|mShareHandle
return|;
block|}
name|void
name|setSwapInterval
parameter_list|(
name|EGLint
name|interval
parameter_list|)
function_decl|;
name|bool
name|checkForOutOfDateSwapChain
parameter_list|()
function_decl|;
comment|// Returns true if swapchain changed due to resize or interval update
name|virtual
name|EGLenum
name|getTextureFormat
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|EGLenum
name|getTextureTarget
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|D3DFORMAT
name|getFormat
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|setBoundTexture
argument_list|(
name|gl
operator|::
name|Texture2D
operator|*
name|texture
argument_list|)
decl_stmt|;
name|virtual
name|gl
operator|::
name|Texture2D
operator|*
name|getBoundTexture
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Surface
argument_list|)
expr_stmt|;
name|Display
modifier|*
specifier|const
name|mDisplay
decl_stmt|;
name|IDirect3DSwapChain9
modifier|*
name|mSwapChain
decl_stmt|;
name|IDirect3DSurface9
modifier|*
name|mBackBuffer
decl_stmt|;
name|IDirect3DSurface9
modifier|*
name|mDepthStencil
decl_stmt|;
name|IDirect3DSurface9
modifier|*
name|mRenderTarget
decl_stmt|;
name|IDirect3DTexture9
modifier|*
name|mOffscreenTexture
decl_stmt|;
name|HANDLE
name|mShareHandle
decl_stmt|;
name|void
name|subclassWindow
parameter_list|()
function_decl|;
name|void
name|unsubclassWindow
parameter_list|()
function_decl|;
name|bool
name|resetSwapChain
parameter_list|(
name|int
name|backbufferWidth
parameter_list|,
name|int
name|backbufferHeight
parameter_list|)
function_decl|;
name|bool
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
function_decl|;
specifier|static
name|DWORD
name|convertInterval
parameter_list|(
name|EGLint
name|interval
parameter_list|)
function_decl|;
specifier|const
name|HWND
name|mWindow
decl_stmt|;
comment|// Window that the surface is created for.
name|bool
name|mWindowSubclassed
decl_stmt|;
comment|// Indicates whether we successfully subclassed mWindow for WM_RESIZE hooking
specifier|const
name|egl
operator|::
name|Config
operator|*
name|mConfig
expr_stmt|;
comment|// EGL config surface was created with
name|EGLint
name|mHeight
decl_stmt|;
comment|// Height of surface
name|EGLint
name|mWidth
decl_stmt|;
comment|// Width of surface
comment|//  EGLint horizontalResolution;   // Horizontal dot pitch
comment|//  EGLint verticalResolution;     // Vertical dot pitch
comment|//  EGLBoolean largestPBuffer;     // If true, create largest pbuffer possible
comment|//  EGLBoolean mipmapTexture;      // True if texture has mipmaps
comment|//  EGLint mipmapLevel;            // Mipmap level to render to
comment|//  EGLenum multisampleResolve;    // Multisample resolve behavior
name|EGLint
name|mPixelAspectRatio
decl_stmt|;
comment|// Display aspect ratio
name|EGLenum
name|mRenderBuffer
decl_stmt|;
comment|// Render buffer
name|EGLenum
name|mSwapBehavior
decl_stmt|;
comment|// Buffer swap behavior
name|EGLenum
name|mTextureFormat
decl_stmt|;
comment|// Format of texture: RGB, RGBA, or no texture
name|EGLenum
name|mTextureTarget
decl_stmt|;
comment|// Type of texture: 2D or no texture
comment|//  EGLenum vgAlphaFormat;         // Alpha format for OpenVG
comment|//  EGLenum vgColorSpace;          // Color space for OpenVG
name|EGLint
name|mSwapInterval
decl_stmt|;
name|EGLint
name|mPostSubBufferSupported
decl_stmt|;
name|DWORD
name|mPresentInterval
decl_stmt|;
name|bool
name|mPresentIntervalDirty
decl_stmt|;
name|gl
operator|::
name|Texture2D
operator|*
name|mTexture
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// INCLUDE_SURFACE_H_
end_comment
end_unit
