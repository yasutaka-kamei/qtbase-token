begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"openglwindow.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QKeyEvent>
end_include
begin_include
include|#
directive|include
file|<QFocusEvent>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_comment
comment|// Making use of the class from the opengl example in gui.
end_comment
begin_class
DECL|class|Window
class|class
name|Window
super|:
specifier|public
name|OpenGLWindow
block|{
name|Q_OBJECT
public|public:
DECL|function|Window
name|Window
parameter_list|()
member_init_list|:
name|m_mouseDown
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_focus
argument_list|(
literal|false
argument_list|)
block|{     }
DECL|function|render
name|void
name|render
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
block|{
name|QLinearGradient
name|g
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|g
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|QColor
argument_list|(
literal|"lightsteelblue"
argument_list|)
argument_list|)
expr_stmt|;
name|g
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|p
operator|->
name|fillRect
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
argument_list|,
name|g
argument_list|)
expr_stmt|;
name|p
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawText
argument_list|(
literal|20
argument_list|,
literal|30
argument_list|,
name|QLatin1String
argument_list|(
literal|"This is an OpenGL based QWindow"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_key
operator|.
name|trimmed
argument_list|()
operator|.
name|length
argument_list|()
operator|>
literal|0
condition|)
block|{
name|QRect
name|bounds
init|=
name|p
operator|->
name|boundingRect
argument_list|(
name|QRect
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
argument_list|,
name|Qt
operator|::
name|AlignTop
operator||
name|Qt
operator|::
name|AlignLeft
argument_list|,
name|m_key
argument_list|)
decl_stmt|;
name|p
operator|->
name|save
argument_list|()
expr_stmt|;
name|p
operator|->
name|translate
argument_list|(
name|width
argument_list|()
operator|/
literal|2.0
argument_list|,
name|height
argument_list|()
operator|/
literal|2.0
argument_list|)
expr_stmt|;
name|p
operator|->
name|scale
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|p
operator|->
name|translate
argument_list|(
operator|-
name|bounds
operator|.
name|width
argument_list|()
operator|/
literal|2.0
argument_list|,
operator|-
name|bounds
operator|.
name|height
argument_list|()
operator|/
literal|2.0
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawText
argument_list|(
name|bounds
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|m_key
argument_list|)
expr_stmt|;
name|p
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|m_focus
condition|)
block|{
name|p
operator|->
name|drawText
argument_list|(
literal|20
argument_list|,
name|height
argument_list|()
operator|-
literal|20
argument_list|,
name|QLatin1String
argument_list|(
literal|"Window has focus!"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|p
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawPolyline
argument_list|(
name|m_polygon
argument_list|)
expr_stmt|;
block|}
DECL|function|mousePressEvent
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
name|m_mouseDown
operator|=
literal|true
expr_stmt|;
name|m_polygon
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_polygon
operator|.
name|append
argument_list|(
name|e
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|renderLater
argument_list|()
expr_stmt|;
block|}
DECL|function|mouseMoveEvent
name|void
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|m_mouseDown
condition|)
block|{
name|m_polygon
operator|.
name|append
argument_list|(
name|e
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|renderLater
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|mouseReleaseEvent
name|void
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
name|m_mouseDown
operator|=
literal|false
expr_stmt|;
name|m_polygon
operator|.
name|append
argument_list|(
name|e
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|renderLater
argument_list|()
expr_stmt|;
block|}
DECL|function|focusInEvent
name|void
name|focusInEvent
parameter_list|(
name|QFocusEvent
modifier|*
parameter_list|)
block|{
name|m_focus
operator|=
literal|true
expr_stmt|;
name|renderLater
argument_list|()
expr_stmt|;
block|}
DECL|function|focusOutEvent
name|void
name|focusOutEvent
parameter_list|(
name|QFocusEvent
modifier|*
parameter_list|)
block|{
name|m_focus
operator|=
literal|false
expr_stmt|;
name|m_polygon
operator|.
name|clear
argument_list|()
expr_stmt|;
name|renderLater
argument_list|()
expr_stmt|;
block|}
DECL|function|keyPressEvent
name|void
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|e
parameter_list|)
block|{
name|m_key
operator|=
name|e
operator|->
name|text
argument_list|()
expr_stmt|;
name|renderLater
argument_list|()
expr_stmt|;
block|}
DECL|function|keyReleaseEvent
name|void
name|keyReleaseEvent
parameter_list|(
name|QKeyEvent
modifier|*
parameter_list|)
block|{
name|m_key
operator|=
name|QString
argument_list|()
expr_stmt|;
name|renderLater
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|m_polygon
name|QPolygon
name|m_polygon
decl_stmt|;
DECL|member|m_mouseDown
name|bool
name|m_mouseDown
decl_stmt|;
DECL|member|m_focus
name|bool
name|m_focus
decl_stmt|;
DECL|member|m_key
name|QString
name|m_key
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|widget
init|=
operator|new
name|QWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|widget
argument_list|)
decl_stmt|;
name|Window
modifier|*
name|window
init|=
operator|new
name|Window
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|container
init|=
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|container
operator|->
name|setMinimumSize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|container
operator|->
name|setMaximumSize
argument_list|(
literal|600
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|container
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|container
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|window
operator|->
name|setGeometry
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|300
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLineEdit
argument_list|(
name|QLatin1String
argument_list|(
literal|"A QLineEdit"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|container
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLineEdit
argument_list|(
name|QLatin1String
argument_list|(
literal|"A QLabel"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|widget
operator|->
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"windowcontainer.moc"
end_include
end_unit
