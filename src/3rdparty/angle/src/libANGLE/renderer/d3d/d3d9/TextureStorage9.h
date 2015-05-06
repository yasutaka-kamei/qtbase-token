begin_unit
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
comment|// TextureStorage9.h: Defines the abstract rx::TextureStorage9 class and its concrete derived
end_comment
begin_comment
comment|// classes TextureStorage9_2D and TextureStorage9_Cube, which act as the interface to the
end_comment
begin_comment
comment|// D3D9 texture.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D9_TEXTURESTORAGE9_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D9_TEXTURESTORAGE9_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D9_TEXTURESTORAGE9_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/TextureStorage.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
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
decl_stmt|;
name|class
name|RenderTargetD3D
decl_stmt|;
name|class
name|RenderTarget9
decl_stmt|;
name|class
name|TextureStorage9
range|:
name|public
name|TextureStorage
block|{
name|public
operator|:
name|virtual
operator|~
name|TextureStorage9
argument_list|()
block|;
specifier|static
name|TextureStorage9
operator|*
name|makeTextureStorage9
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
block|;
specifier|static
name|DWORD
name|GetTextureUsage
argument_list|(
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|)
block|;
name|D3DPOOL
name|getPool
argument_list|()
specifier|const
block|;
name|DWORD
name|getUsage
argument_list|()
specifier|const
block|;
name|virtual
name|gl
operator|::
name|Error
name|getBaseTexture
argument_list|(
name|IDirect3DBaseTexture9
operator|*
operator|*
name|outTexture
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|getRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|,
name|RenderTargetD3D
operator|*
operator|*
name|outRT
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getTopLevel
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isRenderTarget
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isManaged
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|getLevelCount
argument_list|()
specifier|const
block|;
name|virtual
name|gl
operator|::
name|Error
name|setData
argument_list|(
argument|const gl::ImageIndex&index
argument_list|,
argument|ImageD3D *image
argument_list|,
argument|const gl::Box *destBox
argument_list|,
argument|GLenum type
argument_list|,
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const uint8_t *pixelData
argument_list|)
block|;
name|protected
operator|:
name|int
name|mTopLevel
block|;
name|size_t
name|mMipLevels
block|;
name|size_t
name|mTextureWidth
block|;
name|size_t
name|mTextureHeight
block|;
name|GLenum
name|mInternalFormat
block|;
name|D3DFORMAT
name|mTextureFormat
block|;
name|Renderer9
operator|*
name|mRenderer
block|;
name|TextureStorage9
argument_list|(
argument|Renderer9 *renderer
argument_list|,
argument|DWORD usage
argument_list|)
block|;
name|private
operator|:
specifier|const
name|DWORD
name|mD3DUsage
block|;
specifier|const
name|D3DPOOL
name|mD3DPool
block|; }
decl_stmt|;
name|class
name|TextureStorage9_2D
range|:
name|public
name|TextureStorage9
block|{
name|public
operator|:
name|TextureStorage9_2D
argument_list|(
name|Renderer9
operator|*
name|renderer
argument_list|,
name|SwapChain9
operator|*
name|swapchain
argument_list|)
block|;
name|TextureStorage9_2D
argument_list|(
argument|Renderer9 *renderer
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|int levels
argument_list|)
block|;
name|virtual
operator|~
name|TextureStorage9_2D
argument_list|()
block|;
specifier|static
name|TextureStorage9_2D
operator|*
name|makeTextureStorage9_2D
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getSurfaceLevel
argument_list|(
argument|int level
argument_list|,
argument|bool dirty
argument_list|,
argument|IDirect3DSurface9 **outSurface
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|getRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|,
name|RenderTargetD3D
operator|*
operator|*
name|outRT
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|getBaseTexture
argument_list|(
name|IDirect3DBaseTexture9
operator|*
operator|*
name|outTexture
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|generateMipmap
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|sourceIndex
argument_list|,
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|destIndex
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|copyToStorage
argument_list|(
name|TextureStorage
operator|*
name|destStorage
argument_list|)
block|;
name|private
operator|:
name|IDirect3DTexture9
operator|*
name|mTexture
block|;
name|RenderTarget9
operator|*
name|mRenderTarget
block|; }
decl_stmt|;
name|class
name|TextureStorage9_Cube
range|:
name|public
name|TextureStorage9
block|{
name|public
operator|:
name|TextureStorage9_Cube
argument_list|(
argument|Renderer9 *renderer
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|,
argument|int size
argument_list|,
argument|int levels
argument_list|,
argument|bool hintLevelZeroOnly
argument_list|)
block|;
name|virtual
operator|~
name|TextureStorage9_Cube
argument_list|()
block|;
specifier|static
name|TextureStorage9_Cube
operator|*
name|makeTextureStorage9_Cube
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getCubeMapSurface
argument_list|(
argument|GLenum faceTarget
argument_list|,
argument|int level
argument_list|,
argument|bool dirty
argument_list|,
argument|IDirect3DSurface9 **outSurface
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|getRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|,
name|RenderTargetD3D
operator|*
operator|*
name|outRT
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|getBaseTexture
argument_list|(
name|IDirect3DBaseTexture9
operator|*
operator|*
name|outTexture
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|generateMipmap
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|sourceIndex
argument_list|,
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|destIndex
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|copyToStorage
argument_list|(
name|TextureStorage
operator|*
name|destStorage
argument_list|)
block|;
name|private
operator|:
specifier|static
specifier|const
name|size_t
name|CUBE_FACE_COUNT
operator|=
literal|6
block|;
name|IDirect3DCubeTexture9
operator|*
name|mTexture
block|;
name|RenderTarget9
operator|*
name|mRenderTarget
index|[
name|CUBE_FACE_COUNT
index|]
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D9_TEXTURESTORAGE9_H_
end_comment
end_unit