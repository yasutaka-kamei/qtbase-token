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
comment|// VertexBuffer11.cpp: Defines the D3D11 VertexBuffer implementation.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d11/VertexBuffer11.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d11/Buffer11.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d11/Renderer11.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d11/formatutils11.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Buffer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/VertexAttribute.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|VertexBuffer11
name|VertexBuffer11
operator|::
name|VertexBuffer11
parameter_list|(
name|Renderer11
modifier|*
specifier|const
name|renderer
parameter_list|)
member_init_list|:
name|mRenderer
argument_list|(
name|renderer
argument_list|)
block|{
name|mBuffer
operator|=
name|NULL
expr_stmt|;
name|mBufferSize
operator|=
literal|0
expr_stmt|;
name|mDynamicUsage
operator|=
literal|false
expr_stmt|;
block|}
DECL|function|~VertexBuffer11
name|VertexBuffer11
operator|::
name|~
name|VertexBuffer11
parameter_list|()
block|{
name|SafeRelease
argument_list|(
name|mBuffer
argument_list|)
expr_stmt|;
block|}
DECL|function|initialize
name|gl
operator|::
name|Error
name|VertexBuffer11
operator|::
name|initialize
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|,
name|bool
name|dynamicUsage
parameter_list|)
block|{
name|SafeRelease
argument_list|(
name|mBuffer
argument_list|)
expr_stmt|;
name|updateSerial
argument_list|()
expr_stmt|;
if|if
condition|(
name|size
operator|>
literal|0
condition|)
block|{
name|ID3D11Device
modifier|*
name|dxDevice
init|=
name|mRenderer
operator|->
name|getDevice
argument_list|()
decl_stmt|;
name|D3D11_BUFFER_DESC
name|bufferDesc
decl_stmt|;
name|bufferDesc
operator|.
name|ByteWidth
operator|=
name|size
expr_stmt|;
name|bufferDesc
operator|.
name|Usage
operator|=
name|D3D11_USAGE_DYNAMIC
expr_stmt|;
name|bufferDesc
operator|.
name|BindFlags
operator|=
name|D3D11_BIND_VERTEX_BUFFER
expr_stmt|;
name|bufferDesc
operator|.
name|CPUAccessFlags
operator|=
name|D3D11_CPU_ACCESS_WRITE
expr_stmt|;
name|bufferDesc
operator|.
name|MiscFlags
operator|=
literal|0
expr_stmt|;
name|bufferDesc
operator|.
name|StructureByteStride
operator|=
literal|0
expr_stmt|;
name|HRESULT
name|result
init|=
name|dxDevice
operator|->
name|CreateBuffer
argument_list|(
operator|&
name|bufferDesc
argument_list|,
name|NULL
argument_list|,
operator|&
name|mBuffer
argument_list|)
decl_stmt|;
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
literal|"Failed to allocate internal vertex buffer of size, %lu."
argument_list|,
name|size
argument_list|)
return|;
block|}
block|}
name|mBufferSize
operator|=
name|size
expr_stmt|;
name|mDynamicUsage
operator|=
name|dynamicUsage
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
DECL|function|makeVertexBuffer11
name|VertexBuffer11
modifier|*
name|VertexBuffer11
operator|::
name|makeVertexBuffer11
parameter_list|(
name|VertexBuffer
modifier|*
name|vetexBuffer
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|HAS_DYNAMIC_TYPE
argument_list|(
name|VertexBuffer11
operator|*
argument_list|,
name|vetexBuffer
argument_list|)
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|VertexBuffer11
operator|*
argument_list|>
argument_list|(
name|vetexBuffer
argument_list|)
return|;
block|}
DECL|function|storeVertexAttributes
name|gl
operator|::
name|Error
name|VertexBuffer11
operator|::
name|storeVertexAttributes
parameter_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
modifier|&
name|attrib
parameter_list|,
specifier|const
name|gl
operator|::
name|VertexAttribCurrentValueData
modifier|&
name|currentValue
parameter_list|,
name|GLint
name|start
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLsizei
name|instances
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mBuffer
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Internal vertex buffer is not initialized."
argument_list|)
return|;
block|}
name|gl
operator|::
name|Buffer
modifier|*
name|buffer
init|=
name|attrib
operator|.
name|buffer
operator|.
name|get
argument_list|()
decl_stmt|;
name|int
name|inputStride
init|=
name|ComputeVertexAttributeStride
argument_list|(
name|attrib
argument_list|)
decl_stmt|;
name|ID3D11DeviceContext
modifier|*
name|dxContext
init|=
name|mRenderer
operator|->
name|getDeviceContext
argument_list|()
decl_stmt|;
name|D3D11_MAPPED_SUBRESOURCE
name|mappedResource
decl_stmt|;
name|HRESULT
name|result
init|=
name|dxContext
operator|->
name|Map
argument_list|(
name|mBuffer
argument_list|,
literal|0
argument_list|,
name|D3D11_MAP_WRITE_NO_OVERWRITE
argument_list|,
literal|0
argument_list|,
operator|&
name|mappedResource
argument_list|)
decl_stmt|;
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
literal|"Failed to map internal vertex buffer, HRESULT: 0x%08x."
argument_list|,
name|result
argument_list|)
return|;
block|}
name|uint8_t
modifier|*
name|output
init|=
cast|reinterpret_cast
argument_list|<
name|uint8_t
operator|*
argument_list|>
argument_list|(
name|mappedResource
operator|.
name|pData
argument_list|)
operator|+
name|offset
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|input
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|attrib
operator|.
name|enabled
condition|)
block|{
if|if
condition|(
name|buffer
condition|)
block|{
name|BufferD3D
modifier|*
name|storage
init|=
name|BufferD3D
operator|::
name|makeFromBuffer
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|storage
operator|->
name|getData
argument_list|(
operator|&
name|input
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
return|return
name|error
return|;
block|}
name|input
operator|+=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|attrib
operator|.
name|offset
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|input
operator|=
cast|static_cast
argument_list|<
specifier|const
name|uint8_t
operator|*
argument_list|>
argument_list|(
name|attrib
operator|.
name|pointer
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|input
operator|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|uint8_t
operator|*
argument_list|>
argument_list|(
name|currentValue
operator|.
name|FloatValues
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|instances
operator|==
literal|0
operator|||
name|attrib
operator|.
name|divisor
operator|==
literal|0
condition|)
block|{
name|input
operator|+=
name|inputStride
operator|*
name|start
expr_stmt|;
block|}
name|gl
operator|::
name|VertexFormat
name|vertexFormat
argument_list|(
name|attrib
argument_list|,
name|currentValue
operator|.
name|Type
argument_list|)
decl_stmt|;
specifier|const
name|d3d11
operator|::
name|VertexFormat
modifier|&
name|vertexFormatInfo
init|=
name|d3d11
operator|::
name|GetVertexFormatInfo
argument_list|(
name|vertexFormat
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|vertexFormatInfo
operator|.
name|copyFunction
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|vertexFormatInfo
operator|.
name|copyFunction
argument_list|(
name|input
argument_list|,
name|inputStride
argument_list|,
name|count
argument_list|,
name|output
argument_list|)
expr_stmt|;
name|dxContext
operator|->
name|Unmap
argument_list|(
name|mBuffer
argument_list|,
literal|0
argument_list|)
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
DECL|function|getSpaceRequired
name|gl
operator|::
name|Error
name|VertexBuffer11
operator|::
name|getSpaceRequired
parameter_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
modifier|&
name|attrib
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLsizei
name|instances
parameter_list|,
name|unsigned
name|int
modifier|*
name|outSpaceRequired
parameter_list|)
specifier|const
block|{
name|unsigned
name|int
name|elementCount
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|attrib
operator|.
name|enabled
condition|)
block|{
if|if
condition|(
name|instances
operator|==
literal|0
operator|||
name|attrib
operator|.
name|divisor
operator|==
literal|0
condition|)
block|{
name|elementCount
operator|=
name|count
expr_stmt|;
block|}
else|else
block|{
comment|// Round up to divisor, if possible
name|elementCount
operator|=
name|UnsignedCeilDivide
argument_list|(
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|instances
argument_list|)
argument_list|,
name|attrib
operator|.
name|divisor
argument_list|)
expr_stmt|;
block|}
name|gl
operator|::
name|VertexFormat
name|vertexFormat
argument_list|(
name|attrib
argument_list|)
decl_stmt|;
specifier|const
name|d3d11
operator|::
name|VertexFormat
modifier|&
name|vertexFormatInfo
init|=
name|d3d11
operator|::
name|GetVertexFormatInfo
argument_list|(
name|vertexFormat
argument_list|)
decl_stmt|;
specifier|const
name|d3d11
operator|::
name|DXGIFormat
modifier|&
name|dxgiFormatInfo
init|=
name|d3d11
operator|::
name|GetDXGIFormatInfo
argument_list|(
name|vertexFormatInfo
operator|.
name|nativeFormat
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|elementSize
init|=
name|dxgiFormatInfo
operator|.
name|pixelBytes
decl_stmt|;
if|if
condition|(
name|elementSize
operator|<=
name|std
operator|::
name|numeric_limits
argument_list|<
name|unsigned
name|int
argument_list|>
operator|::
name|max
argument_list|()
operator|/
name|elementCount
condition|)
block|{
if|if
condition|(
name|outSpaceRequired
condition|)
block|{
operator|*
name|outSpaceRequired
operator|=
name|elementSize
operator|*
name|elementCount
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
else|else
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"New vertex buffer size would result in an overflow."
argument_list|)
return|;
block|}
block|}
else|else
block|{
specifier|const
name|unsigned
name|int
name|elementSize
init|=
literal|4
decl_stmt|;
if|if
condition|(
name|outSpaceRequired
condition|)
block|{
operator|*
name|outSpaceRequired
operator|=
name|elementSize
operator|*
literal|4
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
DECL|function|getBufferSize
name|unsigned
name|int
name|VertexBuffer11
operator|::
name|getBufferSize
parameter_list|()
specifier|const
block|{
return|return
name|mBufferSize
return|;
block|}
DECL|function|setBufferSize
name|gl
operator|::
name|Error
name|VertexBuffer11
operator|::
name|setBufferSize
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|size
operator|>
name|mBufferSize
condition|)
block|{
return|return
name|initialize
argument_list|(
name|size
argument_list|,
name|mDynamicUsage
argument_list|)
return|;
block|}
else|else
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
block|}
DECL|function|discard
name|gl
operator|::
name|Error
name|VertexBuffer11
operator|::
name|discard
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mBuffer
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Internal vertex buffer is not initialized."
argument_list|)
return|;
block|}
name|ID3D11DeviceContext
modifier|*
name|dxContext
init|=
name|mRenderer
operator|->
name|getDeviceContext
argument_list|()
decl_stmt|;
name|D3D11_MAPPED_SUBRESOURCE
name|mappedResource
decl_stmt|;
name|HRESULT
name|result
init|=
name|dxContext
operator|->
name|Map
argument_list|(
name|mBuffer
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
decl_stmt|;
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
literal|"Failed to map internal buffer for discarding, HRESULT: 0x%08x"
argument_list|,
name|result
argument_list|)
return|;
block|}
name|dxContext
operator|->
name|Unmap
argument_list|(
name|mBuffer
argument_list|,
literal|0
argument_list|)
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
DECL|function|getBuffer
name|ID3D11Buffer
modifier|*
name|VertexBuffer11
operator|::
name|getBuffer
parameter_list|()
specifier|const
block|{
return|return
name|mBuffer
return|;
block|}
block|}
end_namespace
end_unit
