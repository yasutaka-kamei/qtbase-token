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
comment|// PixelTransfer11.cpp:
end_comment
begin_comment
comment|//   Implementation for buffer-to-texture and texture-to-buffer copies.
end_comment
begin_comment
comment|//   Used to implement pixel transfers from unpack and to pack buffers.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/PixelTransfer11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Buffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Context.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/formatutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Buffer11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/formatutils11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Renderer11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/renderer11_utils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/RenderTarget11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/texture_format_table.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/TextureStorage11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Texture.h"
end_include
begin_comment
comment|// Precompiled shaders
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/shaders/compiled/buffertotexture11_gs.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/shaders/compiled/buffertotexture11_ps_4f.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/shaders/compiled/buffertotexture11_ps_4i.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/shaders/compiled/buffertotexture11_ps_4ui.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/shaders/compiled/buffertotexture11_vs.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|PixelTransfer11
name|PixelTransfer11
operator|::
name|PixelTransfer11
parameter_list|(
name|Renderer11
modifier|*
name|renderer
parameter_list|)
member_init_list|:
name|mRenderer
argument_list|(
name|renderer
argument_list|)
member_init_list|,
name|mResourcesLoaded
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mBufferToTextureVS
argument_list|(
name|NULL
argument_list|)
member_init_list|,
name|mBufferToTextureGS
argument_list|(
name|NULL
argument_list|)
member_init_list|,
name|mParamsConstantBuffer
argument_list|(
name|NULL
argument_list|)
member_init_list|,
name|mCopyRasterizerState
argument_list|(
name|NULL
argument_list|)
member_init_list|,
name|mCopyDepthStencilState
argument_list|(
name|NULL
argument_list|)
block|{ }
DECL|function|~PixelTransfer11
name|PixelTransfer11
operator|::
name|~
name|PixelTransfer11
parameter_list|()
block|{
for|for
control|(
name|auto
name|shaderMapIt
init|=
name|mBufferToTexturePSMap
operator|.
name|begin
argument_list|()
init|;
name|shaderMapIt
operator|!=
name|mBufferToTexturePSMap
operator|.
name|end
argument_list|()
condition|;
name|shaderMapIt
operator|++
control|)
block|{
name|SafeRelease
argument_list|(
name|shaderMapIt
operator|->
name|second
argument_list|)
expr_stmt|;
block|}
name|mBufferToTexturePSMap
operator|.
name|clear
argument_list|()
expr_stmt|;
name|SafeRelease
argument_list|(
name|mBufferToTextureVS
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|mBufferToTextureGS
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|mParamsConstantBuffer
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|mCopyRasterizerState
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|mCopyDepthStencilState
argument_list|)
expr_stmt|;
block|}
DECL|function|loadResources
name|gl
operator|::
name|Error
name|PixelTransfer11
operator|::
name|loadResources
parameter_list|()
block|{
if|if
condition|(
name|mResourcesLoaded
condition|)
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
name|HRESULT
name|result
init|=
name|S_OK
decl_stmt|;
name|ID3D11Device
modifier|*
name|device
init|=
name|mRenderer
operator|->
name|getDevice
argument_list|()
decl_stmt|;
name|D3D11_RASTERIZER_DESC
name|rasterDesc
decl_stmt|;
name|rasterDesc
operator|.
name|FillMode
operator|=
name|D3D11_FILL_SOLID
expr_stmt|;
name|rasterDesc
operator|.
name|CullMode
operator|=
name|D3D11_CULL_NONE
expr_stmt|;
name|rasterDesc
operator|.
name|FrontCounterClockwise
operator|=
name|FALSE
expr_stmt|;
name|rasterDesc
operator|.
name|DepthBias
operator|=
literal|0
expr_stmt|;
name|rasterDesc
operator|.
name|SlopeScaledDepthBias
operator|=
literal|0.0f
expr_stmt|;
name|rasterDesc
operator|.
name|DepthBiasClamp
operator|=
literal|0.0f
expr_stmt|;
name|rasterDesc
operator|.
name|DepthClipEnable
operator|=
name|TRUE
expr_stmt|;
name|rasterDesc
operator|.
name|ScissorEnable
operator|=
name|FALSE
expr_stmt|;
name|rasterDesc
operator|.
name|MultisampleEnable
operator|=
name|FALSE
expr_stmt|;
name|rasterDesc
operator|.
name|AntialiasedLineEnable
operator|=
name|FALSE
expr_stmt|;
name|result
operator|=
name|device
operator|->
name|CreateRasterizerState
argument_list|(
operator|&
name|rasterDesc
argument_list|,
operator|&
name|mCopyRasterizerState
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
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to create internal pixel transfer rasterizer state, result: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
name|D3D11_DEPTH_STENCIL_DESC
name|depthStencilDesc
decl_stmt|;
name|depthStencilDesc
operator|.
name|DepthEnable
operator|=
literal|true
expr_stmt|;
name|depthStencilDesc
operator|.
name|DepthWriteMask
operator|=
name|D3D11_DEPTH_WRITE_MASK_ALL
expr_stmt|;
name|depthStencilDesc
operator|.
name|DepthFunc
operator|=
name|D3D11_COMPARISON_ALWAYS
expr_stmt|;
name|depthStencilDesc
operator|.
name|StencilEnable
operator|=
name|FALSE
expr_stmt|;
name|depthStencilDesc
operator|.
name|StencilReadMask
operator|=
name|D3D11_DEFAULT_STENCIL_READ_MASK
expr_stmt|;
name|depthStencilDesc
operator|.
name|StencilWriteMask
operator|=
name|D3D11_DEFAULT_STENCIL_WRITE_MASK
expr_stmt|;
name|depthStencilDesc
operator|.
name|FrontFace
operator|.
name|StencilFailOp
operator|=
name|D3D11_STENCIL_OP_KEEP
expr_stmt|;
name|depthStencilDesc
operator|.
name|FrontFace
operator|.
name|StencilDepthFailOp
operator|=
name|D3D11_STENCIL_OP_KEEP
expr_stmt|;
name|depthStencilDesc
operator|.
name|FrontFace
operator|.
name|StencilPassOp
operator|=
name|D3D11_STENCIL_OP_KEEP
expr_stmt|;
name|depthStencilDesc
operator|.
name|FrontFace
operator|.
name|StencilFunc
operator|=
name|D3D11_COMPARISON_ALWAYS
expr_stmt|;
name|depthStencilDesc
operator|.
name|BackFace
operator|.
name|StencilFailOp
operator|=
name|D3D11_STENCIL_OP_KEEP
expr_stmt|;
name|depthStencilDesc
operator|.
name|BackFace
operator|.
name|StencilDepthFailOp
operator|=
name|D3D11_STENCIL_OP_KEEP
expr_stmt|;
name|depthStencilDesc
operator|.
name|BackFace
operator|.
name|StencilPassOp
operator|=
name|D3D11_STENCIL_OP_KEEP
expr_stmt|;
name|depthStencilDesc
operator|.
name|BackFace
operator|.
name|StencilFunc
operator|=
name|D3D11_COMPARISON_ALWAYS
expr_stmt|;
name|result
operator|=
name|device
operator|->
name|CreateDepthStencilState
argument_list|(
operator|&
name|depthStencilDesc
argument_list|,
operator|&
name|mCopyDepthStencilState
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
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to create internal pixel transfer depth stencil state, result: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
name|D3D11_BUFFER_DESC
name|constantBufferDesc
init|=
block|{
literal|0
block|}
decl_stmt|;
name|constantBufferDesc
operator|.
name|ByteWidth
operator|=
name|roundUp
argument_list|<
name|UINT
argument_list|>
argument_list|(
sizeof|sizeof
argument_list|(
name|CopyShaderParams
argument_list|)
argument_list|,
literal|32u
argument_list|)
expr_stmt|;
name|constantBufferDesc
operator|.
name|Usage
operator|=
name|D3D11_USAGE_DYNAMIC
expr_stmt|;
name|constantBufferDesc
operator|.
name|BindFlags
operator|=
name|D3D11_BIND_CONSTANT_BUFFER
expr_stmt|;
name|constantBufferDesc
operator|.
name|CPUAccessFlags
operator|=
name|D3D11_CPU_ACCESS_WRITE
expr_stmt|;
name|constantBufferDesc
operator|.
name|MiscFlags
operator|=
literal|0
expr_stmt|;
name|constantBufferDesc
operator|.
name|StructureByteStride
operator|=
literal|0
expr_stmt|;
name|result
operator|=
name|device
operator|->
name|CreateBuffer
argument_list|(
operator|&
name|constantBufferDesc
argument_list|,
name|NULL
argument_list|,
operator|&
name|mParamsConstantBuffer
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
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to create internal pixel transfer constant buffer, result: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
name|d3d11
operator|::
name|SetDebugName
argument_list|(
name|mParamsConstantBuffer
argument_list|,
literal|"PixelTransfer11 constant buffer"
argument_list|)
expr_stmt|;
comment|// init shaders
name|mBufferToTextureVS
operator|=
name|d3d11
operator|::
name|CompileVS
argument_list|(
name|device
argument_list|,
name|g_VS_BufferToTexture
argument_list|,
literal|"BufferToTexture VS"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mBufferToTextureVS
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to create internal buffer to texture vertex shader."
argument_list|)
return|;
block|}
name|mBufferToTextureGS
operator|=
name|d3d11
operator|::
name|CompileGS
argument_list|(
name|device
argument_list|,
name|g_GS_BufferToTexture
argument_list|,
literal|"BufferToTexture GS"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mBufferToTextureGS
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to create internal buffer to texture geometry shader."
argument_list|)
return|;
block|}
name|gl
operator|::
name|Error
name|error
init|=
name|buildShaderMap
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
name|StructZero
argument_list|(
operator|&
name|mParamsData
argument_list|)
expr_stmt|;
name|mResourcesLoaded
operator|=
literal|true
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|setBufferToTextureCopyParams
name|void
name|PixelTransfer11
operator|::
name|setBufferToTextureCopyParams
parameter_list|(
specifier|const
name|gl
operator|::
name|Box
modifier|&
name|destArea
parameter_list|,
specifier|const
name|gl
operator|::
name|Extents
modifier|&
name|destSize
parameter_list|,
name|GLenum
name|internalFormat
parameter_list|,
specifier|const
name|gl
operator|::
name|PixelUnpackState
modifier|&
name|unpack
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|,
name|CopyShaderParams
modifier|*
name|parametersOut
parameter_list|)
block|{
name|StructZero
argument_list|(
name|parametersOut
argument_list|)
expr_stmt|;
name|float
name|texelCenterX
init|=
literal|0.5f
operator|/
cast|static_cast
argument_list|<
name|float
argument_list|>
argument_list|(
name|destSize
operator|.
name|width
operator|-
literal|1
argument_list|)
decl_stmt|;
name|float
name|texelCenterY
init|=
literal|0.5f
operator|/
cast|static_cast
argument_list|<
name|float
argument_list|>
argument_list|(
name|destSize
operator|.
name|height
operator|-
literal|1
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|bytesPerPixel
init|=
name|gl
operator|::
name|GetInternalFormatInfo
argument_list|(
name|internalFormat
argument_list|)
operator|.
name|pixelBytes
decl_stmt|;
name|unsigned
name|int
name|alignmentBytes
init|=
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|unpack
operator|.
name|alignment
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|alignmentPixels
init|=
operator|(
name|alignmentBytes
operator|<=
name|bytesPerPixel
condition|?
literal|1
else|:
name|alignmentBytes
operator|/
name|bytesPerPixel
operator|)
decl_stmt|;
name|parametersOut
operator|->
name|FirstPixelOffset
operator|=
name|offset
operator|/
name|bytesPerPixel
expr_stmt|;
name|parametersOut
operator|->
name|PixelsPerRow
operator|=
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
operator|(
name|unpack
operator|.
name|rowLength
operator|>
literal|0
operator|)
condition|?
name|unpack
operator|.
name|rowLength
else|:
name|destArea
operator|.
name|width
argument_list|)
expr_stmt|;
name|parametersOut
operator|->
name|RowStride
operator|=
name|roundUp
argument_list|(
name|parametersOut
operator|->
name|PixelsPerRow
argument_list|,
name|alignmentPixels
argument_list|)
expr_stmt|;
name|parametersOut
operator|->
name|RowsPerSlice
operator|=
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|destArea
operator|.
name|height
argument_list|)
expr_stmt|;
name|parametersOut
operator|->
name|PositionOffset
index|[
literal|0
index|]
operator|=
name|texelCenterX
operator|+
operator|(
name|destArea
operator|.
name|x
operator|/
name|float
argument_list|(
name|destSize
operator|.
name|width
argument_list|)
operator|)
operator|*
literal|2.0f
operator|-
literal|1.0f
expr_stmt|;
name|parametersOut
operator|->
name|PositionOffset
index|[
literal|1
index|]
operator|=
name|texelCenterY
operator|+
operator|(
operator|(
name|destSize
operator|.
name|height
operator|-
name|destArea
operator|.
name|y
operator|-
literal|1
operator|)
operator|/
name|float
argument_list|(
name|destSize
operator|.
name|height
argument_list|)
operator|)
operator|*
literal|2.0f
operator|-
literal|1.0f
expr_stmt|;
name|parametersOut
operator|->
name|PositionScale
index|[
literal|0
index|]
operator|=
literal|2.0f
operator|/
cast|static_cast
argument_list|<
name|float
argument_list|>
argument_list|(
name|destSize
operator|.
name|width
argument_list|)
expr_stmt|;
name|parametersOut
operator|->
name|PositionScale
index|[
literal|1
index|]
operator|=
operator|-
literal|2.0f
operator|/
cast|static_cast
argument_list|<
name|float
argument_list|>
argument_list|(
name|destSize
operator|.
name|height
argument_list|)
expr_stmt|;
name|parametersOut
operator|->
name|FirstSlice
operator|=
name|destArea
operator|.
name|z
expr_stmt|;
block|}
DECL|function|copyBufferToTexture
name|gl
operator|::
name|Error
name|PixelTransfer11
operator|::
name|copyBufferToTexture
parameter_list|(
specifier|const
name|gl
operator|::
name|PixelUnpackState
modifier|&
name|unpack
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|,
name|RenderTargetD3D
modifier|*
name|destRenderTarget
parameter_list|,
name|GLenum
name|destinationFormat
parameter_list|,
name|GLenum
name|sourcePixelsType
parameter_list|,
specifier|const
name|gl
operator|::
name|Box
modifier|&
name|destArea
parameter_list|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|loadResources
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
name|gl
operator|::
name|Extents
name|destSize
init|=
name|destRenderTarget
operator|->
name|getExtents
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|destArea
operator|.
name|x
operator|>=
literal|0
operator|&&
name|destArea
operator|.
name|x
operator|+
name|destArea
operator|.
name|width
operator|<=
name|destSize
operator|.
name|width
operator|&&
name|destArea
operator|.
name|y
operator|>=
literal|0
operator|&&
name|destArea
operator|.
name|y
operator|+
name|destArea
operator|.
name|height
operator|<=
name|destSize
operator|.
name|height
operator|&&
name|destArea
operator|.
name|z
operator|>=
literal|0
operator|&&
name|destArea
operator|.
name|z
operator|+
name|destArea
operator|.
name|depth
operator|<=
name|destSize
operator|.
name|depth
argument_list|)
expr_stmt|;
specifier|const
name|gl
operator|::
name|Buffer
modifier|&
name|sourceBuffer
init|=
operator|*
name|unpack
operator|.
name|pixelBuffer
operator|.
name|get
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|mRenderer
operator|->
name|supportsFastCopyBufferToTexture
argument_list|(
name|destinationFormat
argument_list|)
argument_list|)
expr_stmt|;
name|ID3D11PixelShader
modifier|*
name|pixelShader
init|=
name|findBufferToTexturePS
argument_list|(
name|destinationFormat
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|pixelShader
argument_list|)
expr_stmt|;
comment|// The SRV must be in the proper read format, which may be different from the destination format
comment|// EG: for half float data, we can load full precision floats with implicit conversion
name|GLenum
name|unsizedFormat
init|=
name|gl
operator|::
name|GetInternalFormatInfo
argument_list|(
name|destinationFormat
argument_list|)
operator|.
name|format
decl_stmt|;
name|GLenum
name|sourceFormat
init|=
name|gl
operator|::
name|GetSizedInternalFormat
argument_list|(
name|unsizedFormat
argument_list|,
name|sourcePixelsType
argument_list|)
decl_stmt|;
specifier|const
name|d3d11
operator|::
name|TextureFormat
modifier|&
name|sourceFormatInfo
init|=
name|d3d11
operator|::
name|GetTextureFormatInfo
argument_list|(
name|sourceFormat
argument_list|,
name|mRenderer
operator|->
name|getRenderer11DeviceCaps
argument_list|()
argument_list|)
decl_stmt|;
name|DXGI_FORMAT
name|srvFormat
init|=
name|sourceFormatInfo
operator|.
name|srvFormat
decl_stmt|;
name|ASSERT
argument_list|(
name|srvFormat
operator|!=
name|DXGI_FORMAT_UNKNOWN
argument_list|)
expr_stmt|;
name|Buffer11
modifier|*
name|bufferStorage11
init|=
name|GetAs
argument_list|<
name|Buffer11
argument_list|>
argument_list|(
name|sourceBuffer
operator|.
name|getImplementation
argument_list|()
argument_list|)
decl_stmt|;
name|ID3D11ShaderResourceView
modifier|*
name|bufferSRV
init|=
name|bufferStorage11
operator|->
name|getSRV
argument_list|(
name|srvFormat
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|bufferSRV
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ID3D11RenderTargetView
modifier|*
name|textureRTV
init|=
name|GetAs
argument_list|<
name|RenderTarget11
argument_list|>
argument_list|(
name|destRenderTarget
argument_list|)
operator|->
name|getRenderTargetView
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|textureRTV
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|CopyShaderParams
name|shaderParams
decl_stmt|;
name|setBufferToTextureCopyParams
argument_list|(
name|destArea
argument_list|,
name|destSize
argument_list|,
name|sourceFormat
argument_list|,
name|unpack
argument_list|,
name|offset
argument_list|,
operator|&
name|shaderParams
argument_list|)
expr_stmt|;
name|ID3D11DeviceContext
modifier|*
name|deviceContext
init|=
name|mRenderer
operator|->
name|getDeviceContext
argument_list|()
decl_stmt|;
name|ID3D11Buffer
modifier|*
name|nullBuffer
init|=
name|NULL
decl_stmt|;
name|UINT
name|zero
init|=
literal|0
decl_stmt|;
comment|// Are we doing a 2D or 3D copy?
name|ID3D11GeometryShader
modifier|*
name|geometryShader
init|=
operator|(
operator|(
name|destSize
operator|.
name|depth
operator|>
literal|1
operator|)
condition|?
name|mBufferToTextureGS
else|:
name|NULL
operator|)
decl_stmt|;
name|auto
name|stateManager
init|=
name|mRenderer
operator|->
name|getStateManager
argument_list|()
decl_stmt|;
name|deviceContext
operator|->
name|VSSetShader
argument_list|(
name|mBufferToTextureVS
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|deviceContext
operator|->
name|GSSetShader
argument_list|(
name|geometryShader
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|deviceContext
operator|->
name|PSSetShader
argument_list|(
name|pixelShader
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|stateManager
operator|->
name|setShaderResource
argument_list|(
name|gl
operator|::
name|SAMPLER_PIXEL
argument_list|,
literal|0
argument_list|,
name|bufferSRV
argument_list|)
expr_stmt|;
name|deviceContext
operator|->
name|IASetInputLayout
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|deviceContext
operator|->
name|IASetPrimitiveTopology
argument_list|(
name|D3D11_PRIMITIVE_TOPOLOGY_POINTLIST
argument_list|)
expr_stmt|;
name|deviceContext
operator|->
name|IASetVertexBuffers
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
operator|&
name|nullBuffer
argument_list|,
operator|&
name|zero
argument_list|,
operator|&
name|zero
argument_list|)
expr_stmt|;
name|deviceContext
operator|->
name|OMSetBlendState
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
literal|0xFFFFFFF
argument_list|)
expr_stmt|;
name|deviceContext
operator|->
name|OMSetDepthStencilState
argument_list|(
name|mCopyDepthStencilState
argument_list|,
literal|0xFFFFFFFF
argument_list|)
expr_stmt|;
name|deviceContext
operator|->
name|RSSetState
argument_list|(
name|mCopyRasterizerState
argument_list|)
expr_stmt|;
name|mRenderer
operator|->
name|setOneTimeRenderTarget
argument_list|(
name|textureRTV
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|StructEquals
argument_list|(
name|mParamsData
argument_list|,
name|shaderParams
argument_list|)
condition|)
block|{
name|d3d11
operator|::
name|SetBufferData
argument_list|(
name|deviceContext
argument_list|,
name|mParamsConstantBuffer
argument_list|,
name|shaderParams
argument_list|)
expr_stmt|;
name|mParamsData
operator|=
name|shaderParams
expr_stmt|;
block|}
name|deviceContext
operator|->
name|VSSetConstantBuffers
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
operator|&
name|mParamsConstantBuffer
argument_list|)
expr_stmt|;
comment|// Set the viewport
name|D3D11_VIEWPORT
name|viewport
decl_stmt|;
name|viewport
operator|.
name|TopLeftX
operator|=
literal|0
expr_stmt|;
name|viewport
operator|.
name|TopLeftY
operator|=
literal|0
expr_stmt|;
name|viewport
operator|.
name|Width
operator|=
cast|static_cast
argument_list|<
name|FLOAT
argument_list|>
argument_list|(
name|destSize
operator|.
name|width
argument_list|)
expr_stmt|;
name|viewport
operator|.
name|Height
operator|=
cast|static_cast
argument_list|<
name|FLOAT
argument_list|>
argument_list|(
name|destSize
operator|.
name|height
argument_list|)
expr_stmt|;
name|viewport
operator|.
name|MinDepth
operator|=
literal|0.0f
expr_stmt|;
name|viewport
operator|.
name|MaxDepth
operator|=
literal|1.0f
expr_stmt|;
name|deviceContext
operator|->
name|RSSetViewports
argument_list|(
literal|1
argument_list|,
operator|&
name|viewport
argument_list|)
expr_stmt|;
name|UINT
name|numPixels
init|=
operator|(
name|destArea
operator|.
name|width
operator|*
name|destArea
operator|.
name|height
operator|*
name|destArea
operator|.
name|depth
operator|)
decl_stmt|;
name|deviceContext
operator|->
name|Draw
argument_list|(
name|numPixels
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// Unbind textures and render targets and vertex buffer
name|stateManager
operator|->
name|setShaderResource
argument_list|(
name|gl
operator|::
name|SAMPLER_PIXEL
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|deviceContext
operator|->
name|VSSetConstantBuffers
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
operator|&
name|nullBuffer
argument_list|)
expr_stmt|;
name|mRenderer
operator|->
name|markAllStateDirty
argument_list|()
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|buildShaderMap
name|gl
operator|::
name|Error
name|PixelTransfer11
operator|::
name|buildShaderMap
parameter_list|()
block|{
name|ID3D11Device
modifier|*
name|device
init|=
name|mRenderer
operator|->
name|getDevice
argument_list|()
decl_stmt|;
name|mBufferToTexturePSMap
index|[
name|GL_FLOAT
index|]
operator|=
name|d3d11
operator|::
name|CompilePS
argument_list|(
name|device
argument_list|,
name|g_PS_BufferToTexture_4F
argument_list|,
literal|"BufferToTexture RGBA ps"
argument_list|)
expr_stmt|;
name|mBufferToTexturePSMap
index|[
name|GL_INT
index|]
operator|=
name|d3d11
operator|::
name|CompilePS
argument_list|(
name|device
argument_list|,
name|g_PS_BufferToTexture_4I
argument_list|,
literal|"BufferToTexture RGBA-I ps"
argument_list|)
expr_stmt|;
name|mBufferToTexturePSMap
index|[
name|GL_UNSIGNED_INT
index|]
operator|=
name|d3d11
operator|::
name|CompilePS
argument_list|(
name|device
argument_list|,
name|g_PS_BufferToTexture_4UI
argument_list|,
literal|"BufferToTexture RGBA-UI ps"
argument_list|)
expr_stmt|;
comment|// Check that all the shaders were created successfully
for|for
control|(
name|auto
name|shaderMapIt
init|=
name|mBufferToTexturePSMap
operator|.
name|begin
argument_list|()
init|;
name|shaderMapIt
operator|!=
name|mBufferToTexturePSMap
operator|.
name|end
argument_list|()
condition|;
name|shaderMapIt
operator|++
control|)
block|{
if|if
condition|(
name|shaderMapIt
operator|->
name|second
operator|==
name|NULL
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to create internal buffer to texture pixel shader."
argument_list|)
return|;
block|}
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
DECL|function|findBufferToTexturePS
name|ID3D11PixelShader
modifier|*
name|PixelTransfer11
operator|::
name|findBufferToTexturePS
parameter_list|(
name|GLenum
name|internalFormat
parameter_list|)
specifier|const
block|{
name|GLenum
name|componentType
init|=
name|gl
operator|::
name|GetInternalFormatInfo
argument_list|(
name|internalFormat
argument_list|)
operator|.
name|componentType
decl_stmt|;
if|if
condition|(
name|componentType
operator|==
name|GL_SIGNED_NORMALIZED
operator|||
name|componentType
operator|==
name|GL_UNSIGNED_NORMALIZED
condition|)
block|{
name|componentType
operator|=
name|GL_FLOAT
expr_stmt|;
block|}
name|auto
name|shaderMapIt
init|=
name|mBufferToTexturePSMap
operator|.
name|find
argument_list|(
name|componentType
argument_list|)
decl_stmt|;
return|return
operator|(
name|shaderMapIt
operator|==
name|mBufferToTexturePSMap
operator|.
name|end
argument_list|()
condition|?
name|NULL
else|:
name|shaderMapIt
operator|->
name|second
operator|)
return|;
block|}
block|}
end_namespace
end_unit
