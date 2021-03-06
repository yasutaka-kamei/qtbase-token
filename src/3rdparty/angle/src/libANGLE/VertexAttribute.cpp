begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// Implementation of the state class for mananging GLES 3 Vertex Array Objects.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"libANGLE/VertexAttribute.h"
end_include
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|function|VertexAttribute
name|VertexAttribute
operator|::
name|VertexAttribute
parameter_list|()
member_init_list|:
name|enabled
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|type
argument_list|(
name|GL_FLOAT
argument_list|)
member_init_list|,
name|size
argument_list|(
literal|4
argument_list|)
member_init_list|,
name|normalized
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|pureInteger
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|stride
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|pointer
argument_list|(
name|NULL
argument_list|)
member_init_list|,
name|divisor
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|ComputeVertexAttributeTypeSize
name|size_t
name|ComputeVertexAttributeTypeSize
parameter_list|(
specifier|const
name|VertexAttribute
modifier|&
name|attrib
parameter_list|)
block|{
name|GLuint
name|size
init|=
name|attrib
operator|.
name|size
decl_stmt|;
switch|switch
condition|(
name|attrib
operator|.
name|type
condition|)
block|{
case|case
name|GL_BYTE
case|:
return|return
name|size
operator|*
sizeof|sizeof
argument_list|(
name|GLbyte
argument_list|)
return|;
case|case
name|GL_UNSIGNED_BYTE
case|:
return|return
name|size
operator|*
sizeof|sizeof
argument_list|(
name|GLubyte
argument_list|)
return|;
case|case
name|GL_SHORT
case|:
return|return
name|size
operator|*
sizeof|sizeof
argument_list|(
name|GLshort
argument_list|)
return|;
case|case
name|GL_UNSIGNED_SHORT
case|:
return|return
name|size
operator|*
sizeof|sizeof
argument_list|(
name|GLushort
argument_list|)
return|;
case|case
name|GL_INT
case|:
return|return
name|size
operator|*
sizeof|sizeof
argument_list|(
name|GLint
argument_list|)
return|;
case|case
name|GL_UNSIGNED_INT
case|:
return|return
name|size
operator|*
sizeof|sizeof
argument_list|(
name|GLuint
argument_list|)
return|;
case|case
name|GL_INT_2_10_10_10_REV
case|:
return|return
literal|4
return|;
case|case
name|GL_UNSIGNED_INT_2_10_10_10_REV
case|:
return|return
literal|4
return|;
case|case
name|GL_FIXED
case|:
return|return
name|size
operator|*
sizeof|sizeof
argument_list|(
name|GLfixed
argument_list|)
return|;
case|case
name|GL_HALF_FLOAT
case|:
return|return
name|size
operator|*
sizeof|sizeof
argument_list|(
name|GLhalf
argument_list|)
return|;
case|case
name|GL_FLOAT
case|:
return|return
name|size
operator|*
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|size
operator|*
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
return|;
block|}
block|}
DECL|function|ComputeVertexAttributeStride
name|size_t
name|ComputeVertexAttributeStride
parameter_list|(
specifier|const
name|VertexAttribute
modifier|&
name|attrib
parameter_list|)
block|{
if|if
condition|(
operator|!
name|attrib
operator|.
name|enabled
condition|)
block|{
return|return
literal|16
return|;
block|}
return|return
name|attrib
operator|.
name|stride
condition|?
name|attrib
operator|.
name|stride
else|:
name|ComputeVertexAttributeTypeSize
argument_list|(
name|attrib
argument_list|)
return|;
block|}
DECL|function|ComputeVertexAttributeElementCount
name|size_t
name|ComputeVertexAttributeElementCount
parameter_list|(
specifier|const
name|VertexAttribute
modifier|&
name|attrib
parameter_list|,
name|size_t
name|drawCount
parameter_list|,
name|size_t
name|instanceCount
parameter_list|)
block|{
comment|// For instanced rendering, we draw "instanceDrawCount" sets of "vertexDrawCount" vertices.
comment|//
comment|// A vertex attribute with a positive divisor loads one instanced vertex for every set of
comment|// non-instanced vertices, and the instanced vertex index advances once every "mDivisor"
comment|// instances.
if|if
condition|(
name|instanceCount
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
comment|// When instanceDrawCount is not a multiple attrib.divisor, the division must round up.
comment|// For instance, with 5 non-instanced vertices and a divisor equal to 3, we need 2 instanced
comment|// vertices.
return|return
operator|(
name|instanceCount
operator|+
name|attrib
operator|.
name|divisor
operator|-
literal|1u
operator|)
operator|/
name|attrib
operator|.
name|divisor
return|;
block|}
return|return
name|drawCount
return|;
block|}
block|}
end_namespace
end_unit
