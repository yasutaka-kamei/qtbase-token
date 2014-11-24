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
comment|// Image11.h: Defines the rx::Image11 class, which acts as the interface to
end_comment
begin_comment
comment|// the actual underlying resources of a Texture
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_IMAGE11_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_IMAGE11_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_IMAGE11_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/ImageD3D.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/ImageIndex.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Framebuffer
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer11
decl_stmt|;
name|class
name|TextureStorage11
decl_stmt|;
name|class
name|Image11
range|:
name|public
name|ImageD3D
block|{
name|public
operator|:
name|Image11
argument_list|()
block|;
name|virtual
operator|~
name|Image11
argument_list|()
block|;
specifier|static
name|Image11
operator|*
name|makeImage11
argument_list|(
name|Image
operator|*
name|img
argument_list|)
block|;
specifier|static
name|gl
operator|::
name|Error
name|generateMipmap
argument_list|(
name|Image11
operator|*
name|dest
argument_list|,
name|Image11
operator|*
name|src
argument_list|)
block|;
name|virtual
name|bool
name|isDirty
argument_list|()
specifier|const
block|;
name|virtual
name|gl
operator|::
name|Error
name|copyToStorage
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|,
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|,
specifier|const
name|gl
operator|::
name|Box
operator|&
name|region
argument_list|)
block|;
name|bool
name|redefine
argument_list|(
argument|RendererD3D *renderer
argument_list|,
argument|GLenum target
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|bool forceRelease
argument_list|)
name|override
block|;
name|DXGI_FORMAT
name|getDXGIFormat
argument_list|()
specifier|const
block|;
name|virtual
name|gl
operator|::
name|Error
name|loadData
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *input
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|loadCompressedData
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|const void *input
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|copy
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|RenderTarget *source
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|copy
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|const gl::ImageIndex&sourceIndex
argument_list|,
argument|TextureStorage *source
argument_list|)
block|;
name|gl
operator|::
name|Error
name|recoverFromAssociatedStorage
argument_list|()
block|;
name|bool
name|isAssociatedStorageValid
argument_list|(
argument|TextureStorage11* textureStorage
argument_list|)
specifier|const
block|;
name|void
name|disassociateStorage
argument_list|()
block|;
name|protected
operator|:
name|gl
operator|::
name|Error
name|map
argument_list|(
argument|D3D11_MAP mapType
argument_list|,
argument|D3D11_MAPPED_SUBRESOURCE *map
argument_list|)
block|;
name|void
name|unmap
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Image11
argument_list|)
block|;
name|gl
operator|::
name|Error
name|copyToStorageImpl
argument_list|(
name|TextureStorage11
operator|*
name|storage11
argument_list|,
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|,
specifier|const
name|gl
operator|::
name|Box
operator|&
name|region
argument_list|)
block|;
name|gl
operator|::
name|Error
name|copy
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|ID3D11Texture2D *source
argument_list|,
argument|UINT sourceSubResource
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getStagingTexture
argument_list|(
argument|ID3D11Resource **outStagingTexture
argument_list|,
argument|unsigned int *outSubresourceIndex
argument_list|)
block|;
name|gl
operator|::
name|Error
name|createStagingTexture
argument_list|()
block|;
name|void
name|releaseStagingTexture
argument_list|()
block|;
name|Renderer11
operator|*
name|mRenderer
block|;
name|DXGI_FORMAT
name|mDXGIFormat
block|;
name|ID3D11Resource
operator|*
name|mStagingTexture
block|;
name|unsigned
name|int
name|mStagingSubresource
block|;
name|bool
name|mRecoverFromStorage
block|;
name|TextureStorage11
operator|*
name|mAssociatedStorage
block|;
name|gl
operator|::
name|ImageIndex
name|mAssociatedImageIndex
block|;
name|unsigned
name|int
name|mRecoveredFromStorageCount
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_IMAGE11_H_
end_comment
end_unit
