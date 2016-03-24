begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// SurfaceD3D.cpp: D3D implementation of an EGL surface
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/SurfaceD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Display.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Surface.h"
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
file|"libANGLE/renderer/d3d/SwapChainD3D.h"
end_include
begin_include
include|#
directive|include
file|<tchar.h>
end_include
begin_include
include|#
directive|include
file|<EGL/eglext.h>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|createOffscreen
name|SurfaceD3D
modifier|*
name|SurfaceD3D
operator|::
name|createOffscreen
parameter_list|(
name|RendererD3D
modifier|*
name|renderer
parameter_list|,
name|egl
operator|::
name|Display
modifier|*
name|display
parameter_list|,
specifier|const
name|egl
operator|::
name|Config
modifier|*
name|config
parameter_list|,
name|EGLClientBuffer
name|shareHandle
parameter_list|,
name|EGLint
name|width
parameter_list|,
name|EGLint
name|height
parameter_list|)
block|{
return|return
operator|new
name|SurfaceD3D
argument_list|(
name|renderer
argument_list|,
name|display
argument_list|,
name|config
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|EGL_TRUE
argument_list|,
literal|0
argument_list|,
name|EGL_FALSE
argument_list|,
name|shareHandle
argument_list|,
name|NULL
argument_list|)
return|;
block|}
DECL|function|createFromWindow
name|SurfaceD3D
modifier|*
name|SurfaceD3D
operator|::
name|createFromWindow
parameter_list|(
name|RendererD3D
modifier|*
name|renderer
parameter_list|,
name|egl
operator|::
name|Display
modifier|*
name|display
parameter_list|,
specifier|const
name|egl
operator|::
name|Config
modifier|*
name|config
parameter_list|,
name|EGLNativeWindowType
name|window
parameter_list|,
name|EGLint
name|fixedSize
parameter_list|,
name|EGLint
name|directComposition
parameter_list|,
name|EGLint
name|width
parameter_list|,
name|EGLint
name|height
parameter_list|,
name|EGLint
name|orientation
parameter_list|)
block|{
return|return
operator|new
name|SurfaceD3D
argument_list|(
name|renderer
argument_list|,
name|display
argument_list|,
name|config
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|fixedSize
argument_list|,
name|orientation
argument_list|,
name|directComposition
argument_list|,
cast|static_cast
argument_list|<
name|EGLClientBuffer
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|,
name|window
argument_list|)
return|;
block|}
DECL|function|SurfaceD3D
name|SurfaceD3D
operator|::
name|SurfaceD3D
parameter_list|(
name|RendererD3D
modifier|*
name|renderer
parameter_list|,
name|egl
operator|::
name|Display
modifier|*
name|display
parameter_list|,
specifier|const
name|egl
operator|::
name|Config
modifier|*
name|config
parameter_list|,
name|EGLint
name|width
parameter_list|,
name|EGLint
name|height
parameter_list|,
name|EGLint
name|fixedSize
parameter_list|,
name|EGLint
name|orientation
parameter_list|,
name|EGLint
name|directComposition
parameter_list|,
name|EGLClientBuffer
name|shareHandle
parameter_list|,
name|EGLNativeWindowType
name|window
parameter_list|)
member_init_list|:
name|SurfaceImpl
argument_list|()
member_init_list|,
name|mRenderer
argument_list|(
name|renderer
argument_list|)
member_init_list|,
name|mDisplay
argument_list|(
name|display
argument_list|)
member_init_list|,
name|mFixedSize
argument_list|(
name|fixedSize
operator|==
name|EGL_TRUE
argument_list|)
member_init_list|,
name|mOrientation
argument_list|(
name|orientation
argument_list|)
member_init_list|,
name|mRenderTargetFormat
argument_list|(
name|config
operator|->
name|renderTargetFormat
argument_list|)
member_init_list|,
name|mDepthStencilFormat
argument_list|(
name|config
operator|->
name|depthStencilFormat
argument_list|)
member_init_list|,
name|mSwapChain
argument_list|(
literal|nullptr
argument_list|)
member_init_list|,
name|mSwapIntervalDirty
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|mNativeWindow
argument_list|(
name|window
argument_list|,
name|config
argument_list|,
name|directComposition
operator|==
name|EGL_TRUE
argument_list|)
member_init_list|,
name|mWidth
argument_list|(
name|width
argument_list|)
member_init_list|,
name|mHeight
argument_list|(
name|height
argument_list|)
member_init_list|,
name|mSwapInterval
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|mShareHandle
argument_list|(
cast|reinterpret_cast
argument_list|<
name|HANDLE
operator|*
argument_list|>
argument_list|(
name|shareHandle
argument_list|)
argument_list|)
block|{ }
DECL|function|~SurfaceD3D
name|SurfaceD3D
operator|::
name|~
name|SurfaceD3D
parameter_list|()
block|{
name|releaseSwapChain
argument_list|()
expr_stmt|;
block|}
DECL|function|releaseSwapChain
name|void
name|SurfaceD3D
operator|::
name|releaseSwapChain
parameter_list|()
block|{
name|SafeDelete
argument_list|(
name|mSwapChain
argument_list|)
expr_stmt|;
block|}
DECL|function|initialize
name|egl
operator|::
name|Error
name|SurfaceD3D
operator|::
name|initialize
parameter_list|()
block|{
if|if
condition|(
name|mNativeWindow
operator|.
name|getNativeWindow
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|mNativeWindow
operator|.
name|initialize
argument_list|()
condition|)
block|{
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_BAD_SURFACE
argument_list|)
return|;
block|}
block|}
name|egl
operator|::
name|Error
name|error
init|=
name|resetSwapChain
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
name|egl
operator|::
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
return|;
block|}
DECL|function|createDefaultFramebuffer
name|FramebufferImpl
modifier|*
name|SurfaceD3D
operator|::
name|createDefaultFramebuffer
parameter_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
operator|::
name|Data
modifier|&
name|data
parameter_list|)
block|{
return|return
name|mRenderer
operator|->
name|createFramebuffer
argument_list|(
name|data
argument_list|)
return|;
block|}
DECL|function|bindTexImage
name|egl
operator|::
name|Error
name|SurfaceD3D
operator|::
name|bindTexImage
parameter_list|(
name|gl
operator|::
name|Texture
modifier|*
parameter_list|,
name|EGLint
parameter_list|)
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
DECL|function|releaseTexImage
name|egl
operator|::
name|Error
name|SurfaceD3D
operator|::
name|releaseTexImage
parameter_list|(
name|EGLint
parameter_list|)
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
DECL|function|resetSwapChain
name|egl
operator|::
name|Error
name|SurfaceD3D
operator|::
name|resetSwapChain
parameter_list|()
block|{
name|ASSERT
argument_list|(
operator|!
name|mSwapChain
argument_list|)
expr_stmt|;
name|int
name|width
decl_stmt|;
name|int
name|height
decl_stmt|;
if|if
condition|(
operator|!
name|mFixedSize
condition|)
block|{
name|RECT
name|windowRect
decl_stmt|;
if|if
condition|(
operator|!
name|mNativeWindow
operator|.
name|getClientRect
argument_list|(
operator|&
name|windowRect
argument_list|)
condition|)
block|{
name|ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_BAD_SURFACE
argument_list|,
literal|"Could not retrieve the window dimensions"
argument_list|)
return|;
block|}
name|width
operator|=
name|windowRect
operator|.
name|right
operator|-
name|windowRect
operator|.
name|left
expr_stmt|;
name|height
operator|=
name|windowRect
operator|.
name|bottom
operator|-
name|windowRect
operator|.
name|top
expr_stmt|;
block|}
else|else
block|{
comment|// non-window surface - size is determined at creation
name|width
operator|=
name|mWidth
expr_stmt|;
name|height
operator|=
name|mHeight
expr_stmt|;
block|}
name|mSwapChain
operator|=
name|mRenderer
operator|->
name|createSwapChain
argument_list|(
name|mNativeWindow
argument_list|,
name|mShareHandle
argument_list|,
name|mRenderTargetFormat
argument_list|,
name|mDepthStencilFormat
argument_list|,
name|mOrientation
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mSwapChain
condition|)
block|{
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_BAD_ALLOC
argument_list|)
return|;
block|}
name|egl
operator|::
name|Error
name|error
init|=
name|resetSwapChain
argument_list|(
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
name|SafeDelete
argument_list|(
name|mSwapChain
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
return|;
block|}
DECL|function|resizeSwapChain
name|egl
operator|::
name|Error
name|SurfaceD3D
operator|::
name|resizeSwapChain
parameter_list|(
name|int
name|backbufferWidth
parameter_list|,
name|int
name|backbufferHeight
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|backbufferWidth
operator|>=
literal|0
operator|&&
name|backbufferHeight
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mSwapChain
argument_list|)
expr_stmt|;
name|EGLint
name|status
init|=
name|mSwapChain
operator|->
name|resize
argument_list|(
name|std
operator|::
name|max
argument_list|(
literal|1
argument_list|,
name|backbufferWidth
argument_list|)
argument_list|,
name|std
operator|::
name|max
argument_list|(
literal|1
argument_list|,
name|backbufferHeight
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
operator|==
name|EGL_CONTEXT_LOST
condition|)
block|{
name|mDisplay
operator|->
name|notifyDeviceLost
argument_list|()
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|status
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|status
operator|!=
name|EGL_SUCCESS
condition|)
block|{
return|return
name|egl
operator|::
name|Error
argument_list|(
name|status
argument_list|)
return|;
block|}
name|mWidth
operator|=
name|backbufferWidth
expr_stmt|;
name|mHeight
operator|=
name|backbufferHeight
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
return|;
block|}
DECL|function|resetSwapChain
name|egl
operator|::
name|Error
name|SurfaceD3D
operator|::
name|resetSwapChain
parameter_list|(
name|int
name|backbufferWidth
parameter_list|,
name|int
name|backbufferHeight
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|backbufferWidth
operator|>=
literal|0
operator|&&
name|backbufferHeight
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mSwapChain
argument_list|)
expr_stmt|;
name|EGLint
name|status
init|=
name|mSwapChain
operator|->
name|reset
argument_list|(
name|std
operator|::
name|max
argument_list|(
literal|1
argument_list|,
name|backbufferWidth
argument_list|)
argument_list|,
name|std
operator|::
name|max
argument_list|(
literal|1
argument_list|,
name|backbufferHeight
argument_list|)
argument_list|,
name|mSwapInterval
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
operator|==
name|EGL_CONTEXT_LOST
condition|)
block|{
name|mRenderer
operator|->
name|notifyDeviceLost
argument_list|()
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|status
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|status
operator|!=
name|EGL_SUCCESS
condition|)
block|{
return|return
name|egl
operator|::
name|Error
argument_list|(
name|status
argument_list|)
return|;
block|}
name|mWidth
operator|=
name|backbufferWidth
expr_stmt|;
name|mHeight
operator|=
name|backbufferHeight
expr_stmt|;
name|mSwapIntervalDirty
operator|=
literal|false
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
return|;
block|}
DECL|function|swapRect
name|egl
operator|::
name|Error
name|SurfaceD3D
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
name|egl
operator|::
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
return|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
operator|&&
name|WINAPI_FAMILY
operator|==
name|WINAPI_FAMILY_PC_APP
operator|)
comment|// Qt WP: eglPostSubBufferNV comes here
if|if
condition|(
name|x
operator|+
name|width
operator|>
name|mWidth
condition|)
block|{
name|width
operator|=
name|mWidth
operator|-
name|x
expr_stmt|;
block|}
if|if
condition|(
name|y
operator|+
name|height
operator|>
name|mHeight
condition|)
block|{
name|height
operator|=
name|mHeight
operator|-
name|y
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|width
operator|!=
literal|0
operator|&&
name|height
operator|!=
literal|0
condition|)
block|{
name|EGLint
name|status
init|=
name|mSwapChain
operator|->
name|swapRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
operator|==
name|EGL_CONTEXT_LOST
condition|)
block|{
name|mRenderer
operator|->
name|notifyDeviceLost
argument_list|()
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|status
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|status
operator|!=
name|EGL_SUCCESS
condition|)
block|{
return|return
name|egl
operator|::
name|Error
argument_list|(
name|status
argument_list|)
return|;
block|}
block|}
name|checkForOutOfDateSwapChain
argument_list|()
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
return|;
block|}
DECL|function|checkForOutOfDateSwapChain
name|bool
name|SurfaceD3D
operator|::
name|checkForOutOfDateSwapChain
parameter_list|()
block|{
name|RECT
name|client
decl_stmt|;
name|int
name|clientWidth
init|=
name|getWidth
argument_list|()
decl_stmt|;
name|int
name|clientHeight
init|=
name|getHeight
argument_list|()
decl_stmt|;
name|bool
name|sizeDirty
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|mFixedSize
operator|&&
operator|!
name|mNativeWindow
operator|.
name|isIconic
argument_list|()
condition|)
block|{
comment|// The window is automatically resized to 150x22 when it's minimized, but the swapchain shouldn't be resized
comment|// because that's not a useful size to render to.
if|if
condition|(
operator|!
name|mNativeWindow
operator|.
name|getClientRect
argument_list|(
operator|&
name|client
argument_list|)
condition|)
block|{
name|ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Grow the buffer now, if the window has grown. We need to grow now to avoid losing information.
name|clientWidth
operator|=
name|client
operator|.
name|right
operator|-
name|client
operator|.
name|left
expr_stmt|;
name|clientHeight
operator|=
name|client
operator|.
name|bottom
operator|-
name|client
operator|.
name|top
expr_stmt|;
name|sizeDirty
operator|=
name|clientWidth
operator|!=
name|getWidth
argument_list|()
operator|||
name|clientHeight
operator|!=
name|getHeight
argument_list|()
expr_stmt|;
block|}
name|bool
name|wasDirty
init|=
operator|(
name|mSwapIntervalDirty
operator|||
name|sizeDirty
operator|)
decl_stmt|;
if|if
condition|(
name|mSwapIntervalDirty
condition|)
block|{
name|resetSwapChain
argument_list|(
name|clientWidth
argument_list|,
name|clientHeight
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sizeDirty
condition|)
block|{
name|resizeSwapChain
argument_list|(
name|clientWidth
argument_list|,
name|clientHeight
argument_list|)
expr_stmt|;
block|}
return|return
name|wasDirty
return|;
block|}
DECL|function|swap
name|egl
operator|::
name|Error
name|SurfaceD3D
operator|::
name|swap
parameter_list|()
block|{
return|return
name|swapRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|mWidth
argument_list|,
name|mHeight
argument_list|)
return|;
block|}
DECL|function|postSubBuffer
name|egl
operator|::
name|Error
name|SurfaceD3D
operator|::
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
block|{
return|return
name|swapRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
return|;
block|}
DECL|function|getSwapChain
name|rx
operator|::
name|SwapChainD3D
modifier|*
name|SurfaceD3D
operator|::
name|getSwapChain
parameter_list|()
specifier|const
block|{
return|return
name|mSwapChain
return|;
block|}
DECL|function|setSwapInterval
name|void
name|SurfaceD3D
operator|::
name|setSwapInterval
parameter_list|(
name|EGLint
name|interval
parameter_list|)
block|{
if|if
condition|(
name|mSwapInterval
operator|==
name|interval
condition|)
block|{
return|return;
block|}
name|mSwapInterval
operator|=
name|interval
expr_stmt|;
name|mSwapIntervalDirty
operator|=
literal|true
expr_stmt|;
block|}
DECL|function|getWidth
name|EGLint
name|SurfaceD3D
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
name|EGLint
name|SurfaceD3D
operator|::
name|getHeight
parameter_list|()
specifier|const
block|{
return|return
name|mHeight
return|;
block|}
DECL|function|isPostSubBufferSupported
name|EGLint
name|SurfaceD3D
operator|::
name|isPostSubBufferSupported
parameter_list|()
specifier|const
block|{
comment|// post sub buffer is always possible on D3D surfaces
return|return
name|EGL_TRUE
return|;
block|}
DECL|function|getSwapBehavior
name|EGLint
name|SurfaceD3D
operator|::
name|getSwapBehavior
parameter_list|()
specifier|const
block|{
return|return
name|EGL_BUFFER_PRESERVED
return|;
block|}
DECL|function|querySurfacePointerANGLE
name|egl
operator|::
name|Error
name|SurfaceD3D
operator|::
name|querySurfacePointerANGLE
parameter_list|(
name|EGLint
name|attribute
parameter_list|,
name|void
modifier|*
modifier|*
name|value
parameter_list|)
block|{
if|if
condition|(
name|attribute
operator|==
name|EGL_D3D_TEXTURE_2D_SHARE_HANDLE_ANGLE
condition|)
block|{
operator|*
name|value
operator|=
name|mSwapChain
operator|->
name|getShareHandle
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|attribute
operator|==
name|EGL_DXGI_KEYED_MUTEX_ANGLE
condition|)
block|{
operator|*
name|value
operator|=
name|mSwapChain
operator|->
name|getKeyedMutex
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|attribute
operator|==
name|EGL_DEVICE_EXT
condition|)
block|{
operator|*
name|value
operator|=
name|mSwapChain
operator|->
name|getDevice
argument_list|()
expr_stmt|;
block|}
else|else
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|egl
operator|::
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
return|;
block|}
DECL|function|getAttachmentRenderTarget
name|gl
operator|::
name|Error
name|SurfaceD3D
operator|::
name|getAttachmentRenderTarget
parameter_list|(
specifier|const
name|gl
operator|::
name|FramebufferAttachment
operator|::
name|Target
modifier|&
name|target
parameter_list|,
name|FramebufferAttachmentRenderTarget
modifier|*
modifier|*
name|rtOut
parameter_list|)
block|{
if|if
condition|(
name|target
operator|.
name|binding
argument_list|()
operator|==
name|GL_BACK
condition|)
block|{
operator|*
name|rtOut
operator|=
name|mSwapChain
operator|->
name|getColorRenderTarget
argument_list|()
expr_stmt|;
block|}
else|else
block|{
operator|*
name|rtOut
operator|=
name|mSwapChain
operator|->
name|getDepthStencilRenderTarget
argument_list|()
expr_stmt|;
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
block|}
end_namespace
end_unit
