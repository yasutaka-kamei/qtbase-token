begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// VertexDataManager.h: Defines the VertexDataManager, a class that
end_comment
begin_comment
comment|// runs the Buffer translation process.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/VertexDataManager.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/BufferD3D.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/VertexBuffer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Buffer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/ProgramBinary.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/VertexAttribute.h"
end_include
begin_namespace
namespace|namespace
block|{
DECL|enumerator|INITIAL_STREAM_BUFFER_SIZE
enum|enum
block|{
name|INITIAL_STREAM_BUFFER_SIZE
init|=
literal|1024
operator|*
literal|1024
block|}
enum|;
comment|// This has to be at least 4k or else it fails on ATI cards.
DECL|enumerator|CONSTANT_VERTEX_BUFFER_SIZE
enum|enum
block|{
name|CONSTANT_VERTEX_BUFFER_SIZE
init|=
literal|4096
block|}
enum|;
block|}
end_namespace
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|ElementsInBuffer
specifier|static
name|int
name|ElementsInBuffer
parameter_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
modifier|&
name|attrib
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
block|{
comment|// Size cannot be larger than a GLsizei
if|if
condition|(
name|size
operator|>
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|std
operator|::
name|numeric_limits
argument_list|<
name|int
argument_list|>
operator|::
name|max
argument_list|()
argument_list|)
condition|)
block|{
name|size
operator|=
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|std
operator|::
name|numeric_limits
argument_list|<
name|int
argument_list|>
operator|::
name|max
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|GLsizei
name|stride
init|=
name|ComputeVertexAttributeStride
argument_list|(
name|attrib
argument_list|)
decl_stmt|;
return|return
operator|(
name|size
operator|-
name|attrib
operator|.
name|offset
operator|%
name|stride
operator|+
operator|(
name|stride
operator|-
name|ComputeVertexAttributeTypeSize
argument_list|(
name|attrib
argument_list|)
operator|)
operator|)
operator|/
name|stride
return|;
block|}
DECL|function|StreamingBufferElementCount
specifier|static
name|int
name|StreamingBufferElementCount
parameter_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
modifier|&
name|attrib
parameter_list|,
name|int
name|vertexDrawCount
parameter_list|,
name|int
name|instanceDrawCount
parameter_list|)
block|{
comment|// For instanced rendering, we draw "instanceDrawCount" sets of "vertexDrawCount" vertices.
comment|//
comment|// A vertex attribute with a positive divisor loads one instanced vertex for every set of
comment|// non-instanced vertices, and the instanced vertex index advances once every "mDivisor" instances.
if|if
condition|(
name|instanceDrawCount
operator|>
literal|0
operator|&&
name|attrib
operator|.
name|divisor
operator|>
literal|0
condition|)
block|{
return|return
name|instanceDrawCount
operator|/
name|attrib
operator|.
name|divisor
return|;
block|}
return|return
name|vertexDrawCount
return|;
block|}
DECL|function|VertexDataManager
name|VertexDataManager
operator|::
name|VertexDataManager
parameter_list|(
name|Renderer
modifier|*
name|renderer
parameter_list|)
member_init_list|:
name|mRenderer
argument_list|(
name|renderer
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|i
operator|++
control|)
block|{
name|mCurrentValue
index|[
name|i
index|]
operator|.
name|FloatValues
index|[
literal|0
index|]
operator|=
name|std
operator|::
name|numeric_limits
argument_list|<
name|float
argument_list|>
operator|::
name|quiet_NaN
argument_list|()
expr_stmt|;
name|mCurrentValue
index|[
name|i
index|]
operator|.
name|FloatValues
index|[
literal|1
index|]
operator|=
name|std
operator|::
name|numeric_limits
argument_list|<
name|float
argument_list|>
operator|::
name|quiet_NaN
argument_list|()
expr_stmt|;
name|mCurrentValue
index|[
name|i
index|]
operator|.
name|FloatValues
index|[
literal|2
index|]
operator|=
name|std
operator|::
name|numeric_limits
argument_list|<
name|float
argument_list|>
operator|::
name|quiet_NaN
argument_list|()
expr_stmt|;
name|mCurrentValue
index|[
name|i
index|]
operator|.
name|FloatValues
index|[
literal|3
index|]
operator|=
name|std
operator|::
name|numeric_limits
argument_list|<
name|float
argument_list|>
operator|::
name|quiet_NaN
argument_list|()
expr_stmt|;
name|mCurrentValue
index|[
name|i
index|]
operator|.
name|Type
operator|=
name|GL_FLOAT
expr_stmt|;
name|mCurrentValueBuffer
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
name|mCurrentValueOffsets
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|mStreamingBuffer
operator|=
operator|new
name|StreamingVertexBufferInterface
argument_list|(
name|renderer
argument_list|,
name|INITIAL_STREAM_BUFFER_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mStreamingBuffer
condition|)
block|{
name|ERR
argument_list|(
literal|"Failed to allocate the streaming vertex buffer."
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|~VertexDataManager
name|VertexDataManager
operator|::
name|~
name|VertexDataManager
parameter_list|()
block|{
operator|delete
name|mStreamingBuffer
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|i
operator|++
control|)
block|{
operator|delete
name|mCurrentValueBuffer
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
DECL|function|prepareVertexData
name|gl
operator|::
name|Error
name|VertexDataManager
operator|::
name|prepareVertexData
parameter_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
name|attribs
index|[]
parameter_list|,
specifier|const
name|gl
operator|::
name|VertexAttribCurrentValueData
name|currentValues
index|[]
parameter_list|,
name|gl
operator|::
name|ProgramBinary
modifier|*
name|programBinary
parameter_list|,
name|GLint
name|start
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|TranslatedAttribute
modifier|*
name|translated
parameter_list|,
name|GLsizei
name|instances
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mStreamingBuffer
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Internal streaming vertex buffer is unexpectedly NULL."
argument_list|)
return|;
block|}
comment|// Invalidate static buffers that don't contain matching attributes
for|for
control|(
name|int
name|attributeIndex
init|=
literal|0
init|;
name|attributeIndex
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|attributeIndex
operator|++
control|)
block|{
name|translated
index|[
name|attributeIndex
index|]
operator|.
name|active
operator|=
operator|(
name|programBinary
operator|->
name|getSemanticIndex
argument_list|(
name|attributeIndex
argument_list|)
operator|!=
operator|-
literal|1
operator|)
expr_stmt|;
if|if
condition|(
name|translated
index|[
name|attributeIndex
index|]
operator|.
name|active
operator|&&
name|attribs
index|[
name|attributeIndex
index|]
operator|.
name|enabled
condition|)
block|{
name|invalidateMatchingStaticData
argument_list|(
name|attribs
index|[
name|attributeIndex
index|]
argument_list|,
name|currentValues
index|[
name|attributeIndex
index|]
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Reserve the required space in the buffers
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|translated
index|[
name|i
index|]
operator|.
name|active
operator|&&
name|attribs
index|[
name|i
index|]
operator|.
name|enabled
condition|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|reserveSpaceForAttrib
argument_list|(
name|attribs
index|[
name|i
index|]
argument_list|,
name|currentValues
index|[
name|i
index|]
argument_list|,
name|count
argument_list|,
name|instances
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
block|}
block|}
comment|// Perform the vertex data translations
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|translated
index|[
name|i
index|]
operator|.
name|active
condition|)
block|{
if|if
condition|(
name|attribs
index|[
name|i
index|]
operator|.
name|enabled
condition|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|storeAttribute
argument_list|(
name|attribs
index|[
name|i
index|]
argument_list|,
name|currentValues
index|[
name|i
index|]
argument_list|,
operator|&
name|translated
index|[
name|i
index|]
argument_list|,
name|start
argument_list|,
name|count
argument_list|,
name|instances
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
block|}
else|else
block|{
if|if
condition|(
operator|!
name|mCurrentValueBuffer
index|[
name|i
index|]
condition|)
block|{
name|mCurrentValueBuffer
index|[
name|i
index|]
operator|=
operator|new
name|StreamingVertexBufferInterface
argument_list|(
name|mRenderer
argument_list|,
name|CONSTANT_VERTEX_BUFFER_SIZE
argument_list|)
expr_stmt|;
block|}
name|gl
operator|::
name|Error
name|error
init|=
name|storeCurrentValue
argument_list|(
name|attribs
index|[
name|i
index|]
argument_list|,
name|currentValues
index|[
name|i
index|]
argument_list|,
operator|&
name|translated
index|[
name|i
index|]
argument_list|,
operator|&
name|mCurrentValue
index|[
name|i
index|]
argument_list|,
operator|&
name|mCurrentValueOffsets
index|[
name|i
index|]
argument_list|,
name|mCurrentValueBuffer
index|[
name|i
index|]
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
block|}
block|}
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|translated
index|[
name|i
index|]
operator|.
name|active
operator|&&
name|attribs
index|[
name|i
index|]
operator|.
name|enabled
condition|)
block|{
name|gl
operator|::
name|Buffer
modifier|*
name|buffer
init|=
name|attribs
index|[
name|i
index|]
operator|.
name|buffer
operator|.
name|get
argument_list|()
decl_stmt|;
if|if
condition|(
name|buffer
condition|)
block|{
name|BufferD3D
modifier|*
name|bufferImpl
init|=
name|BufferD3D
operator|::
name|makeBufferD3D
argument_list|(
name|buffer
operator|->
name|getImplementation
argument_list|()
argument_list|)
decl_stmt|;
name|bufferImpl
operator|->
name|promoteStaticUsage
argument_list|(
name|count
operator|*
name|ComputeVertexAttributeTypeSize
argument_list|(
name|attribs
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
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
DECL|function|invalidateMatchingStaticData
name|void
name|VertexDataManager
operator|::
name|invalidateMatchingStaticData
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
parameter_list|)
specifier|const
block|{
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
if|if
condition|(
name|buffer
condition|)
block|{
name|BufferD3D
modifier|*
name|bufferImpl
init|=
name|BufferD3D
operator|::
name|makeBufferD3D
argument_list|(
name|buffer
operator|->
name|getImplementation
argument_list|()
argument_list|)
decl_stmt|;
name|StaticVertexBufferInterface
modifier|*
name|staticBuffer
init|=
name|bufferImpl
operator|->
name|getStaticVertexBuffer
argument_list|()
decl_stmt|;
if|if
condition|(
name|staticBuffer
operator|&&
name|staticBuffer
operator|->
name|getBufferSize
argument_list|()
operator|>
literal|0
operator|&&
operator|!
name|staticBuffer
operator|->
name|lookupAttribute
argument_list|(
name|attrib
argument_list|,
name|NULL
argument_list|)
operator|&&
operator|!
name|staticBuffer
operator|->
name|directStoragePossible
argument_list|(
name|attrib
argument_list|,
name|currentValue
argument_list|)
condition|)
block|{
name|bufferImpl
operator|->
name|invalidateStaticData
argument_list|()
expr_stmt|;
block|}
block|}
block|}
DECL|function|reserveSpaceForAttrib
name|gl
operator|::
name|Error
name|VertexDataManager
operator|::
name|reserveSpaceForAttrib
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
name|GLsizei
name|count
parameter_list|,
name|GLsizei
name|instances
parameter_list|)
specifier|const
block|{
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
name|BufferD3D
modifier|*
name|bufferImpl
init|=
name|buffer
condition|?
name|BufferD3D
operator|::
name|makeBufferD3D
argument_list|(
name|buffer
operator|->
name|getImplementation
argument_list|()
argument_list|)
else|:
name|NULL
decl_stmt|;
name|StaticVertexBufferInterface
modifier|*
name|staticBuffer
init|=
name|bufferImpl
condition|?
name|bufferImpl
operator|->
name|getStaticVertexBuffer
argument_list|()
else|:
name|NULL
decl_stmt|;
name|VertexBufferInterface
modifier|*
name|vertexBuffer
init|=
name|staticBuffer
condition|?
name|staticBuffer
else|:
cast|static_cast
argument_list|<
name|VertexBufferInterface
operator|*
argument_list|>
argument_list|(
name|mStreamingBuffer
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|vertexBuffer
operator|->
name|directStoragePossible
argument_list|(
name|attrib
argument_list|,
name|currentValue
argument_list|)
condition|)
block|{
if|if
condition|(
name|staticBuffer
condition|)
block|{
if|if
condition|(
name|staticBuffer
operator|->
name|getBufferSize
argument_list|()
operator|==
literal|0
condition|)
block|{
name|int
name|totalCount
init|=
name|ElementsInBuffer
argument_list|(
name|attrib
argument_list|,
name|bufferImpl
operator|->
name|getSize
argument_list|()
argument_list|)
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|staticBuffer
operator|->
name|reserveVertexSpace
argument_list|(
name|attrib
argument_list|,
name|totalCount
argument_list|,
literal|0
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
block|}
block|}
else|else
block|{
name|int
name|totalCount
init|=
name|StreamingBufferElementCount
argument_list|(
name|attrib
argument_list|,
name|count
argument_list|,
name|instances
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
operator|!
name|bufferImpl
operator|||
name|ElementsInBuffer
argument_list|(
name|attrib
argument_list|,
name|bufferImpl
operator|->
name|getSize
argument_list|()
argument_list|)
operator|>=
name|totalCount
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|mStreamingBuffer
operator|->
name|reserveVertexSpace
argument_list|(
name|attrib
argument_list|,
name|totalCount
argument_list|,
name|instances
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
DECL|function|storeAttribute
name|gl
operator|::
name|Error
name|VertexDataManager
operator|::
name|storeAttribute
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
name|TranslatedAttribute
modifier|*
name|translated
parameter_list|,
name|GLint
name|start
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLsizei
name|instances
parameter_list|)
block|{
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
name|ASSERT
argument_list|(
name|buffer
operator|||
name|attrib
operator|.
name|pointer
argument_list|)
expr_stmt|;
name|BufferD3D
modifier|*
name|storage
init|=
name|buffer
condition|?
name|BufferD3D
operator|::
name|makeBufferD3D
argument_list|(
name|buffer
operator|->
name|getImplementation
argument_list|()
argument_list|)
else|:
name|NULL
decl_stmt|;
name|StaticVertexBufferInterface
modifier|*
name|staticBuffer
init|=
name|storage
condition|?
name|storage
operator|->
name|getStaticVertexBuffer
argument_list|()
else|:
name|NULL
decl_stmt|;
name|VertexBufferInterface
modifier|*
name|vertexBuffer
init|=
name|staticBuffer
condition|?
name|staticBuffer
else|:
cast|static_cast
argument_list|<
name|VertexBufferInterface
operator|*
argument_list|>
argument_list|(
name|mStreamingBuffer
argument_list|)
decl_stmt|;
name|bool
name|directStorage
init|=
name|vertexBuffer
operator|->
name|directStoragePossible
argument_list|(
name|attrib
argument_list|,
name|currentValue
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|streamOffset
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|outputElementSize
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|directStorage
condition|)
block|{
name|outputElementSize
operator|=
name|ComputeVertexAttributeStride
argument_list|(
name|attrib
argument_list|)
expr_stmt|;
name|streamOffset
operator|=
name|attrib
operator|.
name|offset
operator|+
name|outputElementSize
operator|*
name|start
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|staticBuffer
condition|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|staticBuffer
operator|->
name|getVertexBuffer
argument_list|()
operator|->
name|getSpaceRequired
argument_list|(
name|attrib
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
operator|&
name|outputElementSize
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
if|if
condition|(
operator|!
name|staticBuffer
operator|->
name|lookupAttribute
argument_list|(
name|attrib
argument_list|,
operator|&
name|streamOffset
argument_list|)
condition|)
block|{
comment|// Convert the entire buffer
name|int
name|totalCount
init|=
name|ElementsInBuffer
argument_list|(
name|attrib
argument_list|,
name|storage
operator|->
name|getSize
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|startIndex
init|=
name|attrib
operator|.
name|offset
operator|/
name|ComputeVertexAttributeStride
argument_list|(
name|attrib
argument_list|)
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|staticBuffer
operator|->
name|storeVertexAttributes
argument_list|(
name|attrib
argument_list|,
name|currentValue
argument_list|,
operator|-
name|startIndex
argument_list|,
name|totalCount
argument_list|,
literal|0
argument_list|,
operator|&
name|streamOffset
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
block|}
name|unsigned
name|int
name|firstElementOffset
init|=
operator|(
name|attrib
operator|.
name|offset
operator|/
name|ComputeVertexAttributeStride
argument_list|(
name|attrib
argument_list|)
operator|)
operator|*
name|outputElementSize
decl_stmt|;
name|unsigned
name|int
name|startOffset
init|=
operator|(
name|instances
operator|==
literal|0
operator|||
name|attrib
operator|.
name|divisor
operator|==
literal|0
operator|)
condition|?
name|start
operator|*
name|outputElementSize
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|streamOffset
operator|+
name|firstElementOffset
operator|+
name|startOffset
operator|<
name|streamOffset
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|)
return|;
block|}
name|streamOffset
operator|+=
name|firstElementOffset
operator|+
name|startOffset
expr_stmt|;
block|}
else|else
block|{
name|int
name|totalCount
init|=
name|StreamingBufferElementCount
argument_list|(
name|attrib
argument_list|,
name|count
argument_list|,
name|instances
argument_list|)
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|mStreamingBuffer
operator|->
name|getVertexBuffer
argument_list|()
operator|->
name|getSpaceRequired
argument_list|(
name|attrib
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
operator|&
name|outputElementSize
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
name|error
operator|=
name|mStreamingBuffer
operator|->
name|storeVertexAttributes
argument_list|(
name|attrib
argument_list|,
name|currentValue
argument_list|,
name|start
argument_list|,
name|totalCount
argument_list|,
name|instances
argument_list|,
operator|&
name|streamOffset
argument_list|)
expr_stmt|;
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
block|}
name|translated
operator|->
name|storage
operator|=
name|directStorage
condition|?
name|storage
else|:
name|NULL
expr_stmt|;
name|translated
operator|->
name|vertexBuffer
operator|=
name|vertexBuffer
operator|->
name|getVertexBuffer
argument_list|()
expr_stmt|;
name|translated
operator|->
name|serial
operator|=
name|directStorage
condition|?
name|storage
operator|->
name|getSerial
argument_list|()
else|:
name|vertexBuffer
operator|->
name|getSerial
argument_list|()
expr_stmt|;
name|translated
operator|->
name|divisor
operator|=
name|attrib
operator|.
name|divisor
expr_stmt|;
name|translated
operator|->
name|attribute
operator|=
operator|&
name|attrib
expr_stmt|;
name|translated
operator|->
name|currentValueType
operator|=
name|currentValue
operator|.
name|Type
expr_stmt|;
name|translated
operator|->
name|stride
operator|=
name|outputElementSize
expr_stmt|;
name|translated
operator|->
name|offset
operator|=
name|streamOffset
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
DECL|function|storeCurrentValue
name|gl
operator|::
name|Error
name|VertexDataManager
operator|::
name|storeCurrentValue
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
name|TranslatedAttribute
modifier|*
name|translated
parameter_list|,
name|gl
operator|::
name|VertexAttribCurrentValueData
modifier|*
name|cachedValue
parameter_list|,
name|size_t
modifier|*
name|cachedOffset
parameter_list|,
name|StreamingVertexBufferInterface
modifier|*
name|buffer
parameter_list|)
block|{
if|if
condition|(
operator|*
name|cachedValue
operator|!=
name|currentValue
condition|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|buffer
operator|->
name|reserveVertexSpace
argument_list|(
name|attrib
argument_list|,
literal|1
argument_list|,
literal|0
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
name|unsigned
name|int
name|streamOffset
decl_stmt|;
name|error
operator|=
name|buffer
operator|->
name|storeVertexAttributes
argument_list|(
name|attrib
argument_list|,
name|currentValue
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
operator|&
name|streamOffset
argument_list|)
expr_stmt|;
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
operator|*
name|cachedValue
operator|=
name|currentValue
expr_stmt|;
operator|*
name|cachedOffset
operator|=
name|streamOffset
expr_stmt|;
block|}
name|translated
operator|->
name|storage
operator|=
name|NULL
expr_stmt|;
name|translated
operator|->
name|vertexBuffer
operator|=
name|buffer
operator|->
name|getVertexBuffer
argument_list|()
expr_stmt|;
name|translated
operator|->
name|serial
operator|=
name|buffer
operator|->
name|getSerial
argument_list|()
expr_stmt|;
name|translated
operator|->
name|divisor
operator|=
literal|0
expr_stmt|;
name|translated
operator|->
name|attribute
operator|=
operator|&
name|attrib
expr_stmt|;
name|translated
operator|->
name|currentValueType
operator|=
name|currentValue
operator|.
name|Type
expr_stmt|;
name|translated
operator|->
name|stride
operator|=
literal|0
expr_stmt|;
name|translated
operator|->
name|offset
operator|=
operator|*
name|cachedOffset
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
block|}
end_namespace
end_unit
