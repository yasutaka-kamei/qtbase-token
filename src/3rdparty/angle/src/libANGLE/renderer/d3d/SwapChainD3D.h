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
comment|// SwapChainD3D.h: Defines a back-end specific class that hides the details of the
end_comment
begin_comment
comment|// implementation-specific swapchain.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_SWAPCHAIND3D_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_SWAPCHAIND3D_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_SWAPCHAIND3D_H_
end_define
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_comment
comment|// TODO: move out of D3D11
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/NativeWindow.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_FORCE_VSYNC_OFF
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_FORCE_VSYNC_OFF
define|#
directive|define
name|ANGLE_FORCE_VSYNC_OFF
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RenderTargetD3D
decl_stmt|;
name|class
name|SwapChainD3D
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|SwapChainD3D
argument_list|(
argument|rx::NativeWindow nativeWindow
argument_list|,
argument|HANDLE shareHandle
argument_list|,
argument|GLenum backBufferFormat
argument_list|,
argument|GLenum depthBufferFormat
argument_list|)
operator|:
name|mNativeWindow
argument_list|(
name|nativeWindow
argument_list|)
block|,
name|mShareHandle
argument_list|(
name|shareHandle
argument_list|)
block|,
name|mBackBufferFormat
argument_list|(
name|backBufferFormat
argument_list|)
block|,
name|mDepthBufferFormat
argument_list|(
argument|depthBufferFormat
argument_list|)
block|{     }
name|virtual
operator|~
name|SwapChainD3D
argument_list|()
block|{}
block|;
name|virtual
name|EGLint
name|resize
argument_list|(
argument|EGLint backbufferWidth
argument_list|,
argument|EGLint backbufferSize
argument_list|)
operator|=
literal|0
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
operator|=
literal|0
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
operator|=
literal|0
block|;
name|virtual
name|void
name|recreate
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
operator|*
name|getDevice
argument_list|()
block|{
return|return
name|NULL
return|;
block|}
name|virtual
name|RenderTargetD3D
operator|*
name|getColorRenderTarget
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|RenderTargetD3D
operator|*
name|getDepthStencilRenderTarget
argument_list|()
operator|=
literal|0
block|;
name|GLenum
name|GetBackBufferInternalFormat
argument_list|()
specifier|const
block|{
return|return
name|mBackBufferFormat
return|;
block|}
name|GLenum
name|GetDepthBufferInternalFormat
argument_list|()
specifier|const
block|{
return|return
name|mDepthBufferFormat
return|;
block|}
name|HANDLE
name|getShareHandle
argument_list|()
block|{
return|return
name|mShareHandle
return|;
block|}
name|protected
operator|:
name|rx
operator|::
name|NativeWindow
name|mNativeWindow
block|;
comment|// Handler for the Window that the surface is created for.
specifier|const
name|GLenum
name|mBackBufferFormat
block|;
specifier|const
name|GLenum
name|mDepthBufferFormat
block|;
name|HANDLE
name|mShareHandle
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_SWAPCHAIND3D_H_
end_comment
end_unit