begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwidget.h"
end_include
begin_include
include|#
directive|include
file|<QMouseEvent>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<locale.h>
end_include
begin_constructor
DECL|function|MainWidget
name|MainWidget
operator|::
name|MainWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGLWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|angularSpeed
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~MainWidget
name|MainWidget
operator|::
name|~
name|MainWidget
parameter_list|()
block|{
name|deleteTexture
argument_list|(
name|texture
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|MainWidget
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
comment|// Save mouse press position
name|mousePressPosition
operator|=
name|QVector2D
argument_list|(
name|e
operator|->
name|localPos
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|MainWidget
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
comment|// Mouse release position - mouse press position
name|QVector2D
name|diff
init|=
name|QVector2D
argument_list|(
name|e
operator|->
name|localPos
argument_list|()
argument_list|)
operator|-
name|mousePressPosition
decl_stmt|;
comment|// Rotation axis is perpendicular to the mouse position difference
comment|// vector
name|QVector3D
name|n
init|=
name|QVector3D
argument_list|(
name|diff
operator|.
name|y
argument_list|()
argument_list|,
name|diff
operator|.
name|x
argument_list|()
argument_list|,
literal|0.0
argument_list|)
operator|.
name|normalized
argument_list|()
decl_stmt|;
comment|// Accelerate angular speed relative to the length of the mouse sweep
name|qreal
name|acc
init|=
name|diff
operator|.
name|length
argument_list|()
operator|/
literal|100.0
decl_stmt|;
comment|// Calculate new rotation axis as weighted sum
name|rotationAxis
operator|=
operator|(
name|rotationAxis
operator|*
name|angularSpeed
operator|+
name|n
operator|*
name|acc
operator|)
operator|.
name|normalized
argument_list|()
expr_stmt|;
comment|// Increase angular speed
name|angularSpeed
operator|+=
name|acc
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|timerEvent
name|void
name|MainWidget
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
comment|// Decrease angular speed (friction)
name|angularSpeed
operator|*=
literal|0.99
expr_stmt|;
comment|// Stop rotation when speed goes below threshold
if|if
condition|(
name|angularSpeed
operator|<
literal|0.01
condition|)
block|{
name|angularSpeed
operator|=
literal|0.0
expr_stmt|;
block|}
else|else
block|{
comment|// Update rotation
name|rotation
operator|=
name|QQuaternion
operator|::
name|fromAxisAndAngle
argument_list|(
name|rotationAxis
argument_list|,
name|angularSpeed
argument_list|)
operator|*
name|rotation
expr_stmt|;
comment|// Update scene
name|updateGL
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|initializeGL
name|void
name|MainWidget
operator|::
name|initializeGL
parameter_list|()
block|{
name|initializeGLFunctions
argument_list|()
expr_stmt|;
name|qglClearColor
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|initShaders
argument_list|()
expr_stmt|;
name|initTextures
argument_list|()
expr_stmt|;
comment|//! [2]
comment|// Enable depth buffer
name|glEnable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
comment|// Enable back face culling
name|glEnable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
comment|//! [2]
name|geometries
operator|.
name|init
argument_list|()
expr_stmt|;
comment|// Use QBasicTimer because its faster than QTimer
name|timer
operator|.
name|start
argument_list|(
literal|12
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|initShaders
name|void
name|MainWidget
operator|::
name|initShaders
parameter_list|()
block|{
comment|// Override system locale until shaders are compiled
name|setlocale
argument_list|(
name|LC_NUMERIC
argument_list|,
literal|"C"
argument_list|)
expr_stmt|;
comment|// Compile vertex shader
if|if
condition|(
operator|!
name|program
operator|.
name|addShaderFromSourceFile
argument_list|(
name|QGLShader
operator|::
name|Vertex
argument_list|,
literal|":/vshader.glsl"
argument_list|)
condition|)
name|close
argument_list|()
expr_stmt|;
comment|// Compile fragment shader
if|if
condition|(
operator|!
name|program
operator|.
name|addShaderFromSourceFile
argument_list|(
name|QGLShader
operator|::
name|Fragment
argument_list|,
literal|":/fshader.glsl"
argument_list|)
condition|)
name|close
argument_list|()
expr_stmt|;
comment|// Link shader pipeline
if|if
condition|(
operator|!
name|program
operator|.
name|link
argument_list|()
condition|)
name|close
argument_list|()
expr_stmt|;
comment|// Bind shader pipeline for use
if|if
condition|(
operator|!
name|program
operator|.
name|bind
argument_list|()
condition|)
name|close
argument_list|()
expr_stmt|;
comment|// Restore system locale
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|initTextures
name|void
name|MainWidget
operator|::
name|initTextures
parameter_list|()
block|{
comment|// Load cube.png image
name|glEnable
argument_list|(
name|GL_TEXTURE_2D
argument_list|)
expr_stmt|;
name|texture
operator|=
name|bindTexture
argument_list|(
name|QImage
argument_list|(
literal|":/cube.png"
argument_list|)
argument_list|)
expr_stmt|;
comment|// Set nearest filtering mode for texture minification
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
comment|// Set bilinear filtering mode for texture magnification
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_LINEAR
argument_list|)
expr_stmt|;
comment|// Wrap texture coordinates by repeating
comment|// f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_REPEAT
argument_list|)
expr_stmt|;
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_REPEAT
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|resizeGL
name|void
name|MainWidget
operator|::
name|resizeGL
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
comment|// Set OpenGL viewport to cover whole widget
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
comment|// Calculate aspect ratio
name|qreal
name|aspect
init|=
name|qreal
argument_list|(
name|w
argument_list|)
operator|/
name|qreal
argument_list|(
name|h
condition|?
name|h
else|:
literal|1
argument_list|)
decl_stmt|;
comment|// Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
specifier|const
name|qreal
name|zNear
init|=
literal|3.0
decl_stmt|,
name|zFar
init|=
literal|7.0
decl_stmt|,
name|fov
init|=
literal|45.0
decl_stmt|;
comment|// Reset projection
name|projection
operator|.
name|setToIdentity
argument_list|()
expr_stmt|;
comment|// Set perspective projection
name|projection
operator|.
name|perspective
argument_list|(
name|fov
argument_list|,
name|aspect
argument_list|,
name|zNear
argument_list|,
name|zFar
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|paintGL
name|void
name|MainWidget
operator|::
name|paintGL
parameter_list|()
block|{
comment|// Clear color and depth buffer
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
argument_list|)
expr_stmt|;
comment|//! [6]
comment|// Calculate model view transformation
name|QMatrix4x4
name|matrix
decl_stmt|;
name|matrix
operator|.
name|translate
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
operator|-
literal|5.0
argument_list|)
expr_stmt|;
name|matrix
operator|.
name|rotate
argument_list|(
name|rotation
argument_list|)
expr_stmt|;
comment|// Set modelview-projection matrix
name|program
operator|.
name|setUniformValue
argument_list|(
literal|"mvp_matrix"
argument_list|,
name|projection
operator|*
name|matrix
argument_list|)
expr_stmt|;
comment|//! [6]
comment|// Use texture unit 0 which contains cube.png
name|program
operator|.
name|setUniformValue
argument_list|(
literal|"texture"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// Draw cube geometry
name|geometries
operator|.
name|drawCubeGeometry
argument_list|(
operator|&
name|program
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
