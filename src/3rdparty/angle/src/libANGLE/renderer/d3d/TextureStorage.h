begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// TextureStorage.h: Defines the abstract rx::TextureStorage class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_TEXTURESTORAGE_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_TEXTURESTORAGE_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_TEXTURESTORAGE_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
struct_decl|struct
name|ImageIndex
struct_decl|;
struct_decl|struct
name|Box
struct_decl|;
struct_decl|struct
name|PixelUnpackState
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|SwapChainD3D
decl_stmt|;
name|class
name|RenderTargetD3D
decl_stmt|;
name|class
name|ImageD3D
decl_stmt|;
name|class
name|TextureStorage
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|TextureStorage
argument_list|()
block|{}
name|virtual
operator|~
name|TextureStorage
argument_list|()
block|{}
name|virtual
name|int
name|getTopLevel
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|isRenderTarget
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|isManaged
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|supportsNativeMipmapFunction
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|int
name|getLevelCount
argument_list|()
specifier|const
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
operator|=
literal|0
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
operator|=
literal|0
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
operator|=
literal|0
block|;
comment|// This is a no-op for most implementations of TextureStorage. Some (e.g. TextureStorage11_2D) might override it.
name|virtual
name|gl
operator|::
name|Error
name|useLevelZeroWorkaroundTexture
argument_list|(
argument|bool useLevelZeroTexture
argument_list|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_TEXTURESTORAGE_H_
end_comment
end_unit
