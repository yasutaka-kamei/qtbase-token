begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GLWIDGET_H
end_ifndef
begin_define
DECL|macro|GLWIDGET_H
define|#
directive|define
name|GLWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QOpenGLWindow>
end_include
begin_include
include|#
directive|include
file|<QMatrix4x4>
end_include
begin_include
include|#
directive|include
file|<QVector3D>
end_include
begin_include
include|#
directive|include
file|"../hellogl2/logo.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLTexture
name|class
name|QOpenGLTexture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLShaderProgram
name|class
name|QOpenGLShaderProgram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLBuffer
name|class
name|QOpenGLBuffer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLVertexArrayObject
name|class
name|QOpenGLVertexArrayObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|GLWindow
range|:
name|public
name|QOpenGLWindow
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|float z READ z WRITE setZ
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|float r READ r WRITE setR
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|float r2 READ r2 WRITE setR2
argument_list|)
name|public
operator|:
name|GLWindow
argument_list|()
block|;
operator|~
name|GLWindow
argument_list|()
block|;
name|void
name|initializeGL
argument_list|()
block|;
name|void
name|resizeGL
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|void
name|paintGL
argument_list|()
block|;
name|float
name|z
argument_list|()
specifier|const
block|{
return|return
name|m_eye
operator|.
name|z
argument_list|()
return|;
block|}
name|void
name|setZ
argument_list|(
argument|float v
argument_list|)
block|;
name|float
name|r
argument_list|()
specifier|const
block|{
return|return
name|m_r
return|;
block|}
name|void
name|setR
argument_list|(
argument|float v
argument_list|)
block|;
name|float
name|r2
argument_list|()
specifier|const
block|{
return|return
name|m_r2
return|;
block|}
name|void
name|setR2
argument_list|(
argument|float v
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|startSecondStage
argument_list|()
block|;
name|private
operator|:
name|QOpenGLTexture
operator|*
name|m_texture
block|;
name|QOpenGLShaderProgram
operator|*
name|m_program
block|;
name|QOpenGLBuffer
operator|*
name|m_vbo
block|;
name|QOpenGLVertexArrayObject
operator|*
name|m_vao
block|;
name|Logo
name|m_logo
block|;
name|int
name|m_projMatrixLoc
block|;
name|int
name|m_camMatrixLoc
block|;
name|int
name|m_worldMatrixLoc
block|;
name|int
name|m_myMatrixLoc
block|;
name|int
name|m_lightPosLoc
block|;
name|QMatrix4x4
name|m_proj
block|;
name|QMatrix4x4
name|m_world
block|;
name|QVector3D
name|m_eye
block|;
name|QVector3D
name|m_target
block|;
name|bool
name|m_uniformsDirty
block|;
name|float
name|m_r
block|;
name|float
name|m_r2
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
