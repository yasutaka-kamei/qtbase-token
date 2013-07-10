begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
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
comment|// PixelTransfer11.h:
end_comment
begin_comment
comment|//   Buffer-to-Texture and Texture-to-Buffer data transfers.
end_comment
begin_comment
comment|//   Used to implement pixel unpack and pixel pack buffers in ES3.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_PIXELTRANSFER11_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_PIXELTRANSFER11_H_
define|#
directive|define
name|LIBGLESV2_PIXELTRANSFER11_H_
end_define
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Buffer
decl_stmt|;
struct_decl|struct
name|Box
struct_decl|;
struct_decl|struct
name|Extents
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
name|Renderer11
decl_stmt|;
name|class
name|RenderTarget
decl_stmt|;
name|class
name|PixelTransfer11
block|{
name|public
label|:
name|explicit
name|PixelTransfer11
parameter_list|(
name|Renderer11
modifier|*
name|renderer
parameter_list|)
function_decl|;
operator|~
name|PixelTransfer11
argument_list|()
expr_stmt|;
specifier|static
name|bool
name|supportsBufferToTextureCopy
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
function_decl|;
comment|// unpack: the source buffer is stored in the unpack state, and buffer strides
comment|// offset: the start of the data within the unpack buffer
comment|// destRenderTarget: individual slice/layer of a target texture
comment|// destinationFormat/sourcePixelsType: determines shaders + shader parameters
comment|// destArea: the sub-section of destRenderTarget to copy to
name|bool
name|copyBufferToTexture
argument_list|(
specifier|const
name|gl
operator|::
name|PixelUnpackState
operator|&
name|unpack
argument_list|,
name|unsigned
name|int
name|offset
argument_list|,
name|RenderTarget
operator|*
name|destRenderTarget
argument_list|,
name|GLenum
name|destinationFormat
argument_list|,
name|GLenum
name|sourcePixelsType
argument_list|,
specifier|const
name|gl
operator|::
name|Box
operator|&
name|destArea
argument_list|)
decl_stmt|;
name|private
label|:
struct|struct
name|CopyShaderParams
block|{
name|unsigned
name|int
name|FirstPixelOffset
decl_stmt|;
name|unsigned
name|int
name|PixelsPerRow
decl_stmt|;
name|unsigned
name|int
name|RowStride
decl_stmt|;
name|unsigned
name|int
name|RowsPerSlice
decl_stmt|;
name|float
name|PositionOffset
index|[
literal|2
index|]
decl_stmt|;
name|float
name|PositionScale
index|[
literal|2
index|]
decl_stmt|;
name|int
name|TexLocationOffset
index|[
literal|2
index|]
decl_stmt|;
name|int
name|TexLocationScale
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
specifier|static
name|void
name|setBufferToTextureCopyParams
argument_list|(
specifier|const
name|gl
operator|::
name|Box
operator|&
name|destArea
argument_list|,
specifier|const
name|gl
operator|::
name|Extents
operator|&
name|destSize
argument_list|,
name|GLenum
name|internalFormat
argument_list|,
specifier|const
name|gl
operator|::
name|PixelUnpackState
operator|&
name|unpack
argument_list|,
name|unsigned
name|int
name|offset
argument_list|,
name|CopyShaderParams
operator|*
name|parametersOut
argument_list|)
decl_stmt|;
name|void
name|buildShaderMap
parameter_list|()
function_decl|;
name|ID3D11PixelShader
modifier|*
name|findBufferToTexturePS
argument_list|(
name|GLenum
name|internalFormat
argument_list|)
decl|const
decl_stmt|;
name|Renderer11
modifier|*
name|mRenderer
decl_stmt|;
name|std
operator|::
name|map
operator|<
name|GLenum
operator|,
name|ID3D11PixelShader
operator|*
operator|>
name|mBufferToTexturePSMap
expr_stmt|;
name|ID3D11VertexShader
modifier|*
name|mBufferToTextureVS
decl_stmt|;
name|ID3D11GeometryShader
modifier|*
name|mBufferToTextureGS
decl_stmt|;
name|ID3D11Buffer
modifier|*
name|mParamsConstantBuffer
decl_stmt|;
name|CopyShaderParams
name|mParamsData
decl_stmt|;
name|ID3D11RasterizerState
modifier|*
name|mCopyRasterizerState
decl_stmt|;
name|ID3D11DepthStencilState
modifier|*
name|mCopyDepthStencilState
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_PIXELTRANSFER11_H_
end_comment
end_unit