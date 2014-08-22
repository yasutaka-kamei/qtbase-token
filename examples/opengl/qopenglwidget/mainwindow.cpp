begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QSlider>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QSpinBox>
end_include
begin_include
include|#
directive|include
file|"glwidget.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
member_init_list|:
name|m_nextX
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|m_nextY
argument_list|(
literal|1
argument_list|)
block|{
name|GLWidget
modifier|*
name|glwidget
init|=
operator|new
name|GLWidget
argument_list|(
name|this
argument_list|,
literal|true
argument_list|,
name|qRgb
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
literal|50
argument_list|)
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|m_timer
operator|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QSlider
modifier|*
name|slider
init|=
operator|new
name|QSlider
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|slider
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|updateLabel
init|=
operator|new
name|QLabel
argument_list|(
literal|"Update interval"
argument_list|)
decl_stmt|;
name|QSpinBox
modifier|*
name|updateInterval
init|=
operator|new
name|QSpinBox
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|updateInterval
operator|->
name|setSuffix
argument_list|(
literal|" ms"
argument_list|)
expr_stmt|;
name|updateInterval
operator|->
name|setValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|updateInterval
operator|->
name|setToolTip
argument_list|(
literal|"Interval for the timer that calls update().\n"
literal|"Note that on most systems the swap will block to wait for vsync\n"
literal|"and therefore an interval< 16 ms will likely lead to a 60 FPS update rate."
argument_list|)
expr_stmt|;
name|QGroupBox
modifier|*
name|updateGroupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QCheckBox
modifier|*
name|transparent
init|=
operator|new
name|QCheckBox
argument_list|(
literal|"Transparent background"
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|transparent
operator|->
name|setToolTip
argument_list|(
literal|"Toggles Qt::WA_AlwaysStackOnTop and transparent clear color for glClear().\n"
literal|"Note how the button on top stacks incorrectly when enabling this."
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|updateLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|updateLayout
operator|->
name|addWidget
argument_list|(
name|updateLabel
argument_list|)
expr_stmt|;
name|updateLayout
operator|->
name|addWidget
argument_list|(
name|updateInterval
argument_list|)
expr_stmt|;
name|updateLayout
operator|->
name|addWidget
argument_list|(
name|transparent
argument_list|)
expr_stmt|;
name|updateGroupBox
operator|->
name|setLayout
argument_list|(
name|updateLayout
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setSliderPosition
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|m_timer
operator|->
name|setInterval
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|label
operator|->
name|setText
argument_list|(
literal|"A QOpenGLWidget"
argument_list|)
expr_stmt|;
name|label
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|setCentralWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setTitle
argument_list|(
literal|"QOpenGLWidget Example"
argument_list|)
expr_stmt|;
name|m_layout
operator|=
operator|new
name|QGridLayout
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|addWidget
argument_list|(
name|glwidget
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|,
literal|9
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|addWidget
argument_list|(
name|updateGroupBox
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|addWidget
argument_list|(
name|slider
argument_list|,
literal|11
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|m_layout
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|fileMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"&File"
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|showMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"&Show"
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|helpMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"&Help"
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|exit
init|=
operator|new
name|QAction
argument_list|(
literal|"E&xit"
argument_list|,
name|fileMenu
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|aboutQt
init|=
operator|new
name|QAction
argument_list|(
literal|"About Qt"
argument_list|,
name|helpMenu
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|showLogo
init|=
operator|new
name|QAction
argument_list|(
literal|"Show 3D Logo"
argument_list|,
name|showMenu
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|showTexture
init|=
operator|new
name|QAction
argument_list|(
literal|"Show 2D Texture"
argument_list|,
name|showMenu
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|showBubbles
init|=
operator|new
name|QAction
argument_list|(
literal|"Show bubbles"
argument_list|,
name|showMenu
argument_list|)
decl_stmt|;
name|showBubbles
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|showBubbles
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exit
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutQt
argument_list|)
expr_stmt|;
name|showMenu
operator|->
name|addAction
argument_list|(
name|showLogo
argument_list|)
expr_stmt|;
name|showMenu
operator|->
name|addAction
argument_list|(
name|showTexture
argument_list|)
expr_stmt|;
name|showMenu
operator|->
name|addAction
argument_list|(
name|showBubbles
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exit
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutQt
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|aboutQt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|glwidget
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|showLogo
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|glwidget
argument_list|,
name|SLOT
argument_list|(
name|setLogo
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|showTexture
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|glwidget
argument_list|,
name|SLOT
argument_list|(
name|setTexture
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|showBubbles
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|glwidget
argument_list|,
name|SLOT
argument_list|(
name|setShowBubbles
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|slider
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|glwidget
argument_list|,
name|SLOT
argument_list|(
name|setScaling
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|transparent
argument_list|,
operator|&
name|QCheckBox
operator|::
name|toggled
argument_list|,
name|glwidget
argument_list|,
operator|&
name|GLWidget
operator|::
name|setTransparent
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|updateInterval
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateIntervalChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_timer
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|updateIntervalChanged
name|void
name|MainWindow
operator|::
name|updateIntervalChanged
parameter_list|(
name|int
name|value
parameter_list|)
block|{
name|m_timer
operator|->
name|setInterval
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|m_timer
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addNew
name|void
name|MainWindow
operator|::
name|addNew
parameter_list|()
block|{
if|if
condition|(
name|m_nextY
operator|==
literal|4
condition|)
return|return;
name|GLWidget
modifier|*
name|w
init|=
operator|new
name|GLWidget
argument_list|(
name|this
argument_list|,
literal|false
argument_list|,
name|qRgb
argument_list|(
name|qrand
argument_list|()
operator|%
literal|256
argument_list|,
name|qrand
argument_list|()
operator|%
literal|256
argument_list|,
name|qrand
argument_list|()
operator|%
literal|256
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|m_timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|w
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|addWidget
argument_list|(
name|w
argument_list|,
name|m_nextY
argument_list|,
name|m_nextX
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_nextX
operator|==
literal|3
condition|)
block|{
name|m_nextX
operator|=
literal|1
expr_stmt|;
operator|++
name|m_nextY
expr_stmt|;
block|}
else|else
block|{
operator|++
name|m_nextX
expr_stmt|;
block|}
block|}
end_function
end_unit
