begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2015 The ANGLE Project Authors. All rights reserved.
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
comment|// RenderTargetD3D.h: Defines an abstract wrapper class to manage IDirect3DSurface9
end_comment
begin_comment
comment|// and ID3D11View objects belonging to renderbuffers and renderable textures.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_RENDERTARGETD3D_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_RENDERTARGETD3D_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_RENDERTARGETD3D_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/FramebufferAttachment.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RenderTargetD3D
range|:
name|public
name|FramebufferAttachmentRenderTarget
block|{
name|public
operator|:
name|RenderTargetD3D
argument_list|()
block|;
name|virtual
operator|~
name|RenderTargetD3D
argument_list|()
block|;
name|virtual
name|GLsizei
name|getWidth
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|GLsizei
name|getHeight
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|GLsizei
name|getDepth
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|GLenum
name|getInternalFormat
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|GLsizei
name|getSamples
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|gl
operator|::
name|Extents
name|getExtents
argument_list|()
specifier|const
block|{
return|return
name|gl
operator|::
name|Extents
argument_list|(
name|getWidth
argument_list|()
argument_list|,
name|getHeight
argument_list|()
argument_list|,
name|getDepth
argument_list|()
argument_list|)
return|;
block|}
name|virtual
name|unsigned
name|int
name|getSerial
argument_list|()
specifier|const
block|;
specifier|static
name|unsigned
name|int
name|issueSerials
argument_list|(
argument|unsigned int count
argument_list|)
block|;
name|private
operator|:
specifier|const
name|unsigned
name|int
name|mSerial
block|;
specifier|static
name|unsigned
name|int
name|mCurrentSerial
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_RENDERTARGETD3D_H_
end_comment
end_unit
