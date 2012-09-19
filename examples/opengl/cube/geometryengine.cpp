begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"geometryengine.h"
end_include
begin_include
include|#
directive|include
file|<QVector2D>
end_include
begin_include
include|#
directive|include
file|<QVector3D>
end_include
begin_struct
DECL|struct|VertexData
struct|struct
name|VertexData
block|{
DECL|member|position
name|QVector3D
name|position
decl_stmt|;
DECL|member|texCoord
name|QVector2D
name|texCoord
decl_stmt|;
block|}
struct|;
end_struct
begin_constructor
DECL|function|GeometryEngine
name|GeometryEngine
operator|::
name|GeometryEngine
parameter_list|()
member_init_list|:
name|vboIds
argument_list|(
operator|new
name|GLuint
index|[
literal|2
index|]
argument_list|)
block|{     }
end_constructor
begin_destructor
DECL|function|~GeometryEngine
name|GeometryEngine
operator|::
name|~
name|GeometryEngine
parameter_list|()
block|{
name|glDeleteBuffers
argument_list|(
literal|2
argument_list|,
name|vboIds
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|vboIds
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|init
name|void
name|GeometryEngine
operator|::
name|init
parameter_list|()
block|{
name|initializeGLFunctions
argument_list|()
expr_stmt|;
comment|//! [0]
comment|// Generate 2 VBOs
name|glGenBuffers
argument_list|(
literal|2
argument_list|,
name|vboIds
argument_list|)
expr_stmt|;
comment|//! [0]
comment|// Initializes cube geometry and transfers it to VBOs
name|initCubeGeometry
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initCubeGeometry
name|void
name|GeometryEngine
operator|::
name|initCubeGeometry
parameter_list|()
block|{
comment|// For cube we would need only 8 vertices but we have to
comment|// duplicate vertex for each face because texture coordinate
comment|// is different.
name|VertexData
name|vertices
index|[]
init|=
block|{
comment|// Vertex data for face 0
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
block|}
block|,
comment|// v0
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.33
argument_list|,
literal|0.0
argument_list|)
block|}
block|,
comment|// v1
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.0
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v2
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.33
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v3
comment|// Vertex data for face 1
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.0
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v4
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.33
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v5
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.0
argument_list|,
literal|1.0
argument_list|)
block|}
block|,
comment|// v6
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.33
argument_list|,
literal|1.0
argument_list|)
block|}
block|,
comment|// v7
comment|// Vertex data for face 2
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.66
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v8
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|1.0
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v9
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.66
argument_list|,
literal|1.0
argument_list|)
block|}
block|,
comment|// v10
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|}
block|,
comment|// v11
comment|// Vertex data for face 3
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.66
argument_list|,
literal|0.0
argument_list|)
block|}
block|,
comment|// v12
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|1.0
argument_list|,
literal|0.0
argument_list|)
block|}
block|,
comment|// v13
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.66
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v14
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|1.0
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v15
comment|// Vertex data for face 4
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.33
argument_list|,
literal|0.0
argument_list|)
block|}
block|,
comment|// v16
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.66
argument_list|,
literal|0.0
argument_list|)
block|}
block|,
comment|// v17
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.33
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v18
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.66
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v19
comment|// Vertex data for face 5
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.33
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v20
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.66
argument_list|,
literal|0.5
argument_list|)
block|}
block|,
comment|// v21
block|{
name|QVector3D
argument_list|(
operator|-
literal|1.0
argument_list|,
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.33
argument_list|,
literal|1.0
argument_list|)
block|}
block|,
comment|// v22
block|{
name|QVector3D
argument_list|(
literal|1.0
argument_list|,
literal|1.0
argument_list|,
operator|-
literal|1.0
argument_list|)
block|,
name|QVector2D
argument_list|(
literal|0.66
argument_list|,
literal|1.0
argument_list|)
block|}
comment|// v23
block|}
decl_stmt|;
comment|// Indices for drawing cube faces using triangle strips.
comment|// Triangle strips can be connected by duplicating indices
comment|// between the strips. If connecting strips have opposite
comment|// vertex order then last index of the first strip and first
comment|// index of the second strip needs to be duplicated. If
comment|// connecting strips have same vertex order then only last
comment|// index of the first strip needs to be duplicated.
name|GLushort
name|indices
index|[]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|3
block|,
comment|// Face 0 - triangle strip ( v0,  v1,  v2,  v3)
literal|4
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|7
block|,
comment|// Face 1 - triangle strip ( v4,  v5,  v6,  v7)
literal|8
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|11
block|,
comment|// Face 2 - triangle strip ( v8,  v9, v10, v11)
literal|12
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|15
block|,
comment|// Face 3 - triangle strip (v12, v13, v14, v15)
literal|16
block|,
literal|16
block|,
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|19
block|,
comment|// Face 4 - triangle strip (v16, v17, v18, v19)
literal|20
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
comment|// Face 5 - triangle strip (v20, v21, v22, v23)
block|}
decl_stmt|;
comment|//! [1]
comment|// Transfer vertex data to VBO 0
name|glBindBuffer
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
name|vboIds
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|glBufferData
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
literal|24
operator|*
sizeof|sizeof
argument_list|(
name|VertexData
argument_list|)
argument_list|,
name|vertices
argument_list|,
name|GL_STATIC_DRAW
argument_list|)
expr_stmt|;
comment|// Transfer index data to VBO 1
name|glBindBuffer
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|,
name|vboIds
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|glBufferData
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|,
literal|34
operator|*
sizeof|sizeof
argument_list|(
name|GLushort
argument_list|)
argument_list|,
name|indices
argument_list|,
name|GL_STATIC_DRAW
argument_list|)
expr_stmt|;
comment|//! [1]
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|drawCubeGeometry
name|void
name|GeometryEngine
operator|::
name|drawCubeGeometry
parameter_list|(
name|QGLShaderProgram
modifier|*
name|program
parameter_list|)
block|{
comment|// Tell OpenGL which VBOs to use
name|glBindBuffer
argument_list|(
name|GL_ARRAY_BUFFER
argument_list|,
name|vboIds
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|glBindBuffer
argument_list|(
name|GL_ELEMENT_ARRAY_BUFFER
argument_list|,
name|vboIds
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// Offset for position
name|int
name|offset
init|=
literal|0
decl_stmt|;
comment|// Tell OpenGL programmable pipeline how to locate vertex position data
name|int
name|vertexLocation
init|=
name|program
operator|->
name|attributeLocation
argument_list|(
literal|"a_position"
argument_list|)
decl_stmt|;
name|program
operator|->
name|enableAttributeArray
argument_list|(
name|vertexLocation
argument_list|)
expr_stmt|;
name|glVertexAttribPointer
argument_list|(
name|vertexLocation
argument_list|,
literal|3
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
sizeof|sizeof
argument_list|(
name|VertexData
argument_list|)
argument_list|,
operator|(
specifier|const
name|void
operator|*
operator|)
name|offset
argument_list|)
expr_stmt|;
comment|// Offset for texture coordinate
name|offset
operator|+=
sizeof|sizeof
argument_list|(
name|QVector3D
argument_list|)
expr_stmt|;
comment|// Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
name|int
name|texcoordLocation
init|=
name|program
operator|->
name|attributeLocation
argument_list|(
literal|"a_texcoord"
argument_list|)
decl_stmt|;
name|program
operator|->
name|enableAttributeArray
argument_list|(
name|texcoordLocation
argument_list|)
expr_stmt|;
name|glVertexAttribPointer
argument_list|(
name|texcoordLocation
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
sizeof|sizeof
argument_list|(
name|VertexData
argument_list|)
argument_list|,
operator|(
specifier|const
name|void
operator|*
operator|)
name|offset
argument_list|)
expr_stmt|;
comment|// Draw cube geometry using indices from VBO 1
name|glDrawElements
argument_list|(
name|GL_TRIANGLE_STRIP
argument_list|,
literal|34
argument_list|,
name|GL_UNSIGNED_SHORT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
end_unit
