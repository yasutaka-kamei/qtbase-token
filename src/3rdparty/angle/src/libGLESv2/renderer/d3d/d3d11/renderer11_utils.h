begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// renderer11_utils.h: Conversion functions and other utility routines
end_comment
begin_comment
comment|// specific to the D3D11 renderer.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_RENDERER11_UTILS_H
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_RENDERER11_UTILS_H
define|#
directive|define
name|LIBGLESV2_RENDERER_RENDERER11_UTILS_H
end_define
begin_include
include|#
directive|include
file|"libGLESv2/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Caps.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Error.h"
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|FramebufferAttachment
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RenderTarget11
decl_stmt|;
struct_decl|struct
name|Workarounds
struct_decl|;
name|namespace
name|gl_d3d11
block|{
name|D3D11_BLEND
name|ConvertBlendFunc
parameter_list|(
name|GLenum
name|glBlend
parameter_list|,
name|bool
name|isAlpha
parameter_list|)
function_decl|;
name|D3D11_BLEND_OP
name|ConvertBlendOp
parameter_list|(
name|GLenum
name|glBlendOp
parameter_list|)
function_decl|;
name|UINT8
name|ConvertColorMask
parameter_list|(
name|bool
name|maskRed
parameter_list|,
name|bool
name|maskGreen
parameter_list|,
name|bool
name|maskBlue
parameter_list|,
name|bool
name|maskAlpha
parameter_list|)
function_decl|;
name|D3D11_CULL_MODE
name|ConvertCullMode
parameter_list|(
name|bool
name|cullEnabled
parameter_list|,
name|GLenum
name|cullMode
parameter_list|)
function_decl|;
name|D3D11_COMPARISON_FUNC
name|ConvertComparison
parameter_list|(
name|GLenum
name|comparison
parameter_list|)
function_decl|;
name|D3D11_DEPTH_WRITE_MASK
name|ConvertDepthMask
parameter_list|(
name|bool
name|depthWriteEnabled
parameter_list|)
function_decl|;
name|UINT8
name|ConvertStencilMask
parameter_list|(
name|GLuint
name|stencilmask
parameter_list|)
function_decl|;
name|D3D11_STENCIL_OP
name|ConvertStencilOp
parameter_list|(
name|GLenum
name|stencilOp
parameter_list|)
function_decl|;
name|D3D11_FILTER
name|ConvertFilter
parameter_list|(
name|GLenum
name|minFilter
parameter_list|,
name|GLenum
name|magFilter
parameter_list|,
name|float
name|maxAnisotropy
parameter_list|,
name|GLenum
name|comparisonMode
parameter_list|)
function_decl|;
name|D3D11_TEXTURE_ADDRESS_MODE
name|ConvertTextureWrap
parameter_list|(
name|GLenum
name|wrap
parameter_list|)
function_decl|;
name|D3D11_QUERY
name|ConvertQueryType
parameter_list|(
name|GLenum
name|queryType
parameter_list|)
function_decl|;
block|}
name|namespace
name|d3d11_gl
block|{
name|void
name|GenerateCaps
argument_list|(
name|ID3D11Device
operator|*
name|device
argument_list|,
name|gl
operator|::
name|Caps
operator|*
name|caps
argument_list|,
name|gl
operator|::
name|TextureCapsMap
operator|*
name|textureCapsMap
argument_list|,
name|gl
operator|::
name|Extensions
operator|*
name|extensions
argument_list|)
decl_stmt|;
block|}
name|namespace
name|d3d11
block|{
name|void
name|MakeValidSize
parameter_list|(
name|bool
name|isImage
parameter_list|,
name|DXGI_FORMAT
name|format
parameter_list|,
name|GLsizei
modifier|*
name|requestWidth
parameter_list|,
name|GLsizei
modifier|*
name|requestHeight
parameter_list|,
name|int
modifier|*
name|levelOffset
parameter_list|)
function_decl|;
name|void
name|GenerateInitialTextureData
argument_list|(
name|GLint
name|internalFormat
argument_list|,
name|GLuint
name|width
argument_list|,
name|GLuint
name|height
argument_list|,
name|GLuint
name|depth
argument_list|,
name|GLuint
name|mipLevels
argument_list|,
name|std
operator|::
name|vector
operator|<
name|D3D11_SUBRESOURCE_DATA
operator|>
operator|*
name|outSubresourceData
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|BYTE
operator|>
expr|>
operator|*
name|outData
argument_list|)
decl_stmt|;
struct|struct
name|PositionTexCoordVertex
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
name|float
name|u
decl_stmt|,
name|v
decl_stmt|;
block|}
struct|;
name|void
name|SetPositionTexCoordVertex
parameter_list|(
name|PositionTexCoordVertex
modifier|*
name|vertex
parameter_list|,
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
name|float
name|u
parameter_list|,
name|float
name|v
parameter_list|)
function_decl|;
struct|struct
name|PositionLayerTexCoord3DVertex
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
name|unsigned
name|int
name|l
decl_stmt|;
name|float
name|u
decl_stmt|,
name|v
decl_stmt|,
name|s
decl_stmt|;
block|}
struct|;
name|void
name|SetPositionLayerTexCoord3DVertex
parameter_list|(
name|PositionLayerTexCoord3DVertex
modifier|*
name|vertex
parameter_list|,
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
name|unsigned
name|int
name|layer
parameter_list|,
name|float
name|u
parameter_list|,
name|float
name|v
parameter_list|,
name|float
name|s
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|PositionDepthColorVertex
block|{
name|float
name|x
block|,
name|y
block|,
name|z
block|;
name|T
name|r
block|,
name|g
block|,
name|b
block|,
name|a
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|SetPositionDepthColorVertex
argument_list|(
argument|PositionDepthColorVertex<T>* vertex
argument_list|,
argument|float x
argument_list|,
argument|float y
argument_list|,
argument|float z
argument_list|,
argument|const gl::Color<T>&color
argument_list|)
block|{
name|vertex
operator|->
name|x
operator|=
name|x
block|;
name|vertex
operator|->
name|y
operator|=
name|y
block|;
name|vertex
operator|->
name|z
operator|=
name|z
block|;
name|vertex
operator|->
name|r
operator|=
name|color
operator|.
name|red
block|;
name|vertex
operator|->
name|g
operator|=
name|color
operator|.
name|green
block|;
name|vertex
operator|->
name|b
operator|=
name|color
operator|.
name|blue
block|;
name|vertex
operator|->
name|a
operator|=
name|color
operator|.
name|alpha
block|; }
name|HRESULT
name|SetDebugName
argument_list|(
name|ID3D11DeviceChild
operator|*
name|resource
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|outType
operator|>
name|outType
operator|*
name|DynamicCastComObject
argument_list|(
argument|IUnknown* object
argument_list|)
block|{
name|outType
operator|*
name|outObject
operator|=
name|NULL
block|;
name|HRESULT
name|result
operator|=
name|object
operator|->
name|QueryInterface
argument_list|(
name|__uuidof
argument_list|(
name|outType
argument_list|)
argument_list|,
name|reinterpret_cast
operator|<
name|void
operator|*
operator|*
operator|>
operator|(
operator|&
name|outObject
operator|)
argument_list|)
block|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|outObject
return|;
block|}
else|else
block|{
name|SafeRelease
argument_list|(
name|outObject
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
block|}
specifier|inline
name|bool
name|isDeviceLostError
argument_list|(
argument|HRESULT errorCode
argument_list|)
block|{
switch|switch
condition|(
name|errorCode
condition|)
block|{
case|case
name|DXGI_ERROR_DEVICE_HUNG
case|:
case|case
name|DXGI_ERROR_DEVICE_REMOVED
case|:
case|case
name|DXGI_ERROR_DEVICE_RESET
case|:
case|case
name|DXGI_ERROR_DRIVER_INTERNAL_ERROR
case|:
case|case
name|DXGI_ERROR_NOT_CURRENTLY_AVAILABLE
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
name|template
operator|<
name|unsigned
name|int
name|N
operator|>
specifier|inline
name|ID3D11VertexShader
operator|*
name|CompileVS
argument_list|(
argument|ID3D11Device *device
argument_list|,
argument|const BYTE (&byteCode)[N]
argument_list|,
argument|const char *name
argument_list|)
block|{
name|ID3D11VertexShader
operator|*
name|vs
operator|=
name|NULL
block|;
name|HRESULT
name|result
operator|=
name|device
operator|->
name|CreateVertexShader
argument_list|(
name|byteCode
argument_list|,
name|N
argument_list|,
name|NULL
argument_list|,
operator|&
name|vs
argument_list|)
block|;
name|UNUSED_ASSERTION_VARIABLE
argument_list|(
name|result
argument_list|)
block|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
block|;
name|SetDebugName
argument_list|(
name|vs
argument_list|,
name|name
argument_list|)
block|;
return|return
name|vs
return|;
block|}
name|template
operator|<
name|unsigned
name|int
name|N
operator|>
specifier|inline
name|ID3D11GeometryShader
operator|*
name|CompileGS
argument_list|(
argument|ID3D11Device *device
argument_list|,
argument|const BYTE (&byteCode)[N]
argument_list|,
argument|const char *name
argument_list|)
block|{
name|ID3D11GeometryShader
operator|*
name|gs
operator|=
name|NULL
block|;
name|HRESULT
name|result
operator|=
name|device
operator|->
name|CreateGeometryShader
argument_list|(
name|byteCode
argument_list|,
name|N
argument_list|,
name|NULL
argument_list|,
operator|&
name|gs
argument_list|)
block|;
name|UNUSED_ASSERTION_VARIABLE
argument_list|(
name|result
argument_list|)
block|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
block|;
name|SetDebugName
argument_list|(
name|gs
argument_list|,
name|name
argument_list|)
block|;
return|return
name|gs
return|;
block|}
name|template
operator|<
name|unsigned
name|int
name|N
operator|>
specifier|inline
name|ID3D11PixelShader
operator|*
name|CompilePS
argument_list|(
argument|ID3D11Device *device
argument_list|,
argument|const BYTE (&byteCode)[N]
argument_list|,
argument|const char *name
argument_list|)
block|{
name|ID3D11PixelShader
operator|*
name|ps
operator|=
name|NULL
block|;
name|HRESULT
name|result
operator|=
name|device
operator|->
name|CreatePixelShader
argument_list|(
name|byteCode
argument_list|,
name|N
argument_list|,
name|NULL
argument_list|,
operator|&
name|ps
argument_list|)
block|;
name|UNUSED_ASSERTION_VARIABLE
argument_list|(
name|result
argument_list|)
block|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
block|;
name|SetDebugName
argument_list|(
name|ps
argument_list|,
name|name
argument_list|)
block|;
return|return
name|ps
return|;
block|}
comment|// Copy data to small D3D11 buffers, such as for small constant buffers, which use one struct to
comment|// represent an entire buffer.
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|void
name|SetBufferData
argument_list|(
argument|ID3D11DeviceContext *context
argument_list|,
argument|ID3D11Buffer *constantBuffer
argument_list|,
argument|const T&value
argument_list|)
block|{
name|D3D11_MAPPED_SUBRESOURCE
name|mappedResource
block|;
name|context
operator|->
name|Map
argument_list|(
name|constantBuffer
argument_list|,
literal|0
argument_list|,
name|D3D11_MAP_WRITE_DISCARD
argument_list|,
literal|0
argument_list|,
operator|&
name|mappedResource
argument_list|)
block|;
name|memcpy
argument_list|(
name|mappedResource
operator|.
name|pData
argument_list|,
operator|&
name|value
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;
name|context
operator|->
name|Unmap
argument_list|(
name|constantBuffer
argument_list|,
literal|0
argument_list|)
block|; }
name|gl
operator|::
name|Error
name|GetAttachmentRenderTarget
argument_list|(
name|gl
operator|::
name|FramebufferAttachment
operator|*
name|attachment
argument_list|,
name|RenderTarget11
operator|*
operator|*
name|outRT
argument_list|)
expr_stmt|;
name|Workarounds
name|GenerateWorkarounds
parameter_list|()
function_decl|;
block|}
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_RENDERER11_UTILS_H
end_comment
end_unit
