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
comment|// RenderbufferD3d.h: Defines the RenderbufferD3D class which implements RenderbufferImpl.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_RENDERBUFFERD3D_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_RENDERBUFFERD3D_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_RENDERBUFFERD3D_H_
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
file|"libGLESv2/renderer/RenderbufferImpl.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RendererD3D
decl_stmt|;
name|class
name|RenderTarget
decl_stmt|;
name|class
name|SwapChain
decl_stmt|;
name|class
name|RenderbufferD3D
range|:
name|public
name|RenderbufferImpl
block|{
name|public
operator|:
name|RenderbufferD3D
argument_list|(
name|RendererD3D
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|RenderbufferD3D
argument_list|()
block|;
specifier|static
name|RenderbufferD3D
operator|*
name|makeRenderbufferD3D
argument_list|(
name|RenderbufferImpl
operator|*
name|renderbuffer
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|setStorage
argument_list|(
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei samples
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|setStorage
argument_list|(
argument|SwapChain *swapChain
argument_list|,
argument|bool depth
argument_list|)
block|;
name|virtual
name|GLsizei
name|getWidth
argument_list|()
specifier|const
block|;
name|virtual
name|GLsizei
name|getHeight
argument_list|()
specifier|const
block|;
name|virtual
name|GLenum
name|getInternalFormat
argument_list|()
specifier|const
block|;
name|virtual
name|GLenum
name|getActualFormat
argument_list|()
specifier|const
block|;
name|virtual
name|GLsizei
name|getSamples
argument_list|()
specifier|const
block|;
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|()
block|;
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|()
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RenderbufferD3D
argument_list|)
block|;
name|RendererD3D
operator|*
name|mRenderer
block|;
name|RenderTarget
operator|*
name|mRenderTarget
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_RENDERBUFFERD3D_H_
end_comment
end_unit