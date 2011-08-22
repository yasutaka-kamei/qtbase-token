begin_unit
begin_include
include|#
directive|include
file|"paintedwindow.h"
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_constructor
DECL|function|PaintedWindow
name|PaintedWindow
operator|::
name|PaintedWindow
parameter_list|()
member_init_list|:
name|m_fbo
argument_list|(
literal|0
argument_list|)
block|{
name|QSurfaceFormat
name|format
decl_stmt|;
name|format
operator|.
name|setStencilBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|setSurfaceType
argument_list|(
name|QWindow
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|Window
operator||
name|Qt
operator|::
name|WindowTitleHint
operator||
name|Qt
operator|::
name|WindowMinMaxButtonsHint
operator||
name|Qt
operator|::
name|WindowCloseButtonHint
argument_list|)
expr_stmt|;
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|create
argument_list|()
expr_stmt|;
name|m_context
operator|=
operator|new
name|QOpenGLContext
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|create
argument_list|()
expr_stmt|;
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|timer
operator|->
name|setInterval
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|paint
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|()
expr_stmt|;
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QOpenGLShader
modifier|*
name|vshader
init|=
operator|new
name|QOpenGLShader
argument_list|(
name|QOpenGLShader
operator|::
name|Vertex
argument_list|,
name|this
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|vsrc
init|=
literal|"attribute highp vec2 vertexCoordsInput;\n"
literal|"attribute mediump vec2 texCoordsInput;\n"
literal|"varying mediump vec2 texCoords;\n"
literal|"void main(void)\n"
literal|"{\n"
literal|"    texCoords = texCoordsInput;\n"
literal|"    gl_Position = vec4(vertexCoordsInput, 0, 1);\n"
literal|"}\n"
decl_stmt|;
name|vshader
operator|->
name|compileSourceCode
argument_list|(
name|vsrc
argument_list|)
expr_stmt|;
name|QOpenGLShader
modifier|*
name|fshader
init|=
operator|new
name|QOpenGLShader
argument_list|(
name|QOpenGLShader
operator|::
name|Fragment
argument_list|,
name|this
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|fsrc
init|=
literal|"uniform sampler2D tex;\n"
literal|"varying mediump vec2 texCoords;\n"
literal|"void main(void)\n"
literal|"{\n"
literal|"    gl_FragColor = texture2D(tex, texCoords);\n"
literal|"}\n"
decl_stmt|;
name|fshader
operator|->
name|compileSourceCode
argument_list|(
name|fsrc
argument_list|)
expr_stmt|;
name|m_program
operator|=
operator|new
name|QOpenGLShaderProgram
expr_stmt|;
name|m_program
operator|->
name|addShader
argument_list|(
name|vshader
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|addShader
argument_list|(
name|fshader
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|link
argument_list|()
expr_stmt|;
name|m_vertexAttribute
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"vertexCoordsInput"
argument_list|)
expr_stmt|;
name|m_texCoordsAttribute
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"texCoordsInput"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|resizeEvent
name|void
name|PaintedWindow
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|this
argument_list|)
expr_stmt|;
operator|delete
name|m_fbo
expr_stmt|;
name|m_fbo
operator|=
operator|new
name|QOpenGLFramebufferObject
argument_list|(
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|PaintedWindow
operator|::
name|paint
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_fbo
condition|)
return|return;
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addEllipse
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_fbo
operator|->
name|width
argument_list|()
argument_list|,
name|m_fbo
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
name|m_fbo
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_fbo
operator|->
name|width
argument_list|()
argument_list|,
name|m_fbo
operator|->
name|height
argument_list|()
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillPath
argument_list|(
name|path
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_STENCIL_TEST
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|glClearColor
argument_list|(
literal|0.1f
argument_list|,
literal|0.1f
argument_list|,
literal|0.2f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
argument_list|)
expr_stmt|;
name|GLfloat
name|texCoords
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|}
decl_stmt|;
name|GLfloat
name|vertexCoords
index|[]
init|=
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|1
block|,
operator|-
literal|1
block|,
literal|1
block|}
decl_stmt|;
name|m_program
operator|->
name|bind
argument_list|()
expr_stmt|;
name|m_context
operator|->
name|functions
argument_list|()
operator|->
name|glEnableVertexAttribArray
argument_list|(
name|m_vertexAttribute
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|functions
argument_list|()
operator|->
name|glEnableVertexAttribArray
argument_list|(
name|m_texCoordsAttribute
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|functions
argument_list|()
operator|->
name|glVertexAttribPointer
argument_list|(
name|m_vertexAttribute
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|vertexCoords
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|functions
argument_list|()
operator|->
name|glVertexAttribPointer
argument_list|(
name|m_texCoordsAttribute
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|texCoords
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_fbo
operator|->
name|texture
argument_list|()
argument_list|)
expr_stmt|;
name|glDrawArrays
argument_list|(
name|GL_TRIANGLES
argument_list|,
literal|0
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|functions
argument_list|()
operator|->
name|glDisableVertexAttribArray
argument_list|(
name|m_vertexAttribute
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|functions
argument_list|()
operator|->
name|glDisableVertexAttribArray
argument_list|(
name|m_texCoordsAttribute
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|release
argument_list|()
expr_stmt|;
name|m_context
operator|->
name|swapBuffers
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
