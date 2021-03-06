begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"movieplayer.h"
end_include
begin_constructor
DECL|function|MoviePlayer
name|MoviePlayer
operator|::
name|MoviePlayer
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|movie
operator|=
operator|new
name|QMovie
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|movie
operator|->
name|setCacheMode
argument_list|(
name|QMovie
operator|::
name|CacheAll
argument_list|)
expr_stmt|;
name|movieLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"No movie loaded"
argument_list|)
argument_list|)
expr_stmt|;
name|movieLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|movieLabel
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|)
expr_stmt|;
name|movieLabel
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
expr_stmt|;
name|movieLabel
operator|->
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|currentMovieDirectory
operator|=
literal|"movies"
expr_stmt|;
name|createControls
argument_list|()
expr_stmt|;
name|createButtons
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|movie
argument_list|,
name|SIGNAL
argument_list|(
name|frameChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateFrameSlider
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|movie
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|QMovie
operator|::
name|MovieState
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateButtons
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fitCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|fitToWindow
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|frameSlider
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
name|goToFrame
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|speedSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|movie
argument_list|,
name|SLOT
argument_list|(
name|setSpeed
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|mainLayout
operator|=
operator|new
name|QVBoxLayout
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|movieLabel
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|controlsLayout
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|buttonsLayout
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|updateFrameSlider
argument_list|()
expr_stmt|;
name|updateButtons
argument_list|()
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Movie Player"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|open
name|void
name|MoviePlayer
operator|::
name|open
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open a Movie"
argument_list|)
argument_list|,
name|currentMovieDirectory
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|openFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openFile
name|void
name|MoviePlayer
operator|::
name|openFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|currentMovieDirectory
operator|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|path
argument_list|()
expr_stmt|;
name|movie
operator|->
name|stop
argument_list|()
expr_stmt|;
name|movieLabel
operator|->
name|setMovie
argument_list|(
name|movie
argument_list|)
expr_stmt|;
name|movie
operator|->
name|setFileName
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|movie
operator|->
name|start
argument_list|()
expr_stmt|;
name|updateFrameSlider
argument_list|()
expr_stmt|;
name|updateButtons
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|goToFrame
name|void
name|MoviePlayer
operator|::
name|goToFrame
parameter_list|(
name|int
name|frame
parameter_list|)
block|{
name|movie
operator|->
name|jumpToFrame
argument_list|(
name|frame
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fitToWindow
name|void
name|MoviePlayer
operator|::
name|fitToWindow
parameter_list|()
block|{
name|movieLabel
operator|->
name|setScaledContents
argument_list|(
name|fitCheckBox
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateFrameSlider
name|void
name|MoviePlayer
operator|::
name|updateFrameSlider
parameter_list|()
block|{
name|bool
name|hasFrames
init|=
operator|(
name|movie
operator|->
name|currentFrameNumber
argument_list|()
operator|>=
literal|0
operator|)
decl_stmt|;
if|if
condition|(
name|hasFrames
condition|)
block|{
if|if
condition|(
name|movie
operator|->
name|frameCount
argument_list|()
operator|>
literal|0
condition|)
block|{
name|frameSlider
operator|->
name|setMaximum
argument_list|(
name|movie
operator|->
name|frameCount
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|movie
operator|->
name|currentFrameNumber
argument_list|()
operator|>
name|frameSlider
operator|->
name|maximum
argument_list|()
condition|)
name|frameSlider
operator|->
name|setMaximum
argument_list|(
name|movie
operator|->
name|currentFrameNumber
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|frameSlider
operator|->
name|setValue
argument_list|(
name|movie
operator|->
name|currentFrameNumber
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|frameSlider
operator|->
name|setMaximum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|frameLabel
operator|->
name|setEnabled
argument_list|(
name|hasFrames
argument_list|)
expr_stmt|;
name|frameSlider
operator|->
name|setEnabled
argument_list|(
name|hasFrames
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateButtons
name|void
name|MoviePlayer
operator|::
name|updateButtons
parameter_list|()
block|{
name|playButton
operator|->
name|setEnabled
argument_list|(
name|movie
operator|->
name|isValid
argument_list|()
operator|&&
name|movie
operator|->
name|frameCount
argument_list|()
operator|!=
literal|1
operator|&&
name|movie
operator|->
name|state
argument_list|()
operator|==
name|QMovie
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
name|pauseButton
operator|->
name|setEnabled
argument_list|(
name|movie
operator|->
name|state
argument_list|()
operator|!=
name|QMovie
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
name|pauseButton
operator|->
name|setChecked
argument_list|(
name|movie
operator|->
name|state
argument_list|()
operator|==
name|QMovie
operator|::
name|Paused
argument_list|)
expr_stmt|;
name|stopButton
operator|->
name|setEnabled
argument_list|(
name|movie
operator|->
name|state
argument_list|()
operator|!=
name|QMovie
operator|::
name|NotRunning
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createControls
name|void
name|MoviePlayer
operator|::
name|createControls
parameter_list|()
block|{
name|fitCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Fit to Window"
argument_list|)
argument_list|)
expr_stmt|;
name|frameLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Current frame:"
argument_list|)
argument_list|)
expr_stmt|;
name|frameSlider
operator|=
operator|new
name|QSlider
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|frameSlider
operator|->
name|setTickPosition
argument_list|(
name|QSlider
operator|::
name|TicksBelow
argument_list|)
expr_stmt|;
name|frameSlider
operator|->
name|setTickInterval
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|speedLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Speed:"
argument_list|)
argument_list|)
expr_stmt|;
name|speedSpinBox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
name|speedSpinBox
operator|->
name|setRange
argument_list|(
literal|1
argument_list|,
literal|9999
argument_list|)
expr_stmt|;
name|speedSpinBox
operator|->
name|setValue
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|speedSpinBox
operator|->
name|setSuffix
argument_list|(
name|tr
argument_list|(
literal|"%"
argument_list|)
argument_list|)
expr_stmt|;
name|controlsLayout
operator|=
operator|new
name|QGridLayout
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|fitCheckBox
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|frameLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|frameSlider
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|speedLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|speedSpinBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createButtons
name|void
name|MoviePlayer
operator|::
name|createButtons
parameter_list|()
block|{
name|QSize
name|iconSize
argument_list|(
literal|36
argument_list|,
literal|36
argument_list|)
decl_stmt|;
name|openButton
operator|=
operator|new
name|QToolButton
expr_stmt|;
name|openButton
operator|->
name|setIcon
argument_list|(
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_DialogOpenButton
argument_list|)
argument_list|)
expr_stmt|;
name|openButton
operator|->
name|setIconSize
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
name|openButton
operator|->
name|setToolTip
argument_list|(
name|tr
argument_list|(
literal|"Open File"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|open
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|playButton
operator|=
operator|new
name|QToolButton
expr_stmt|;
name|playButton
operator|->
name|setIcon
argument_list|(
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_MediaPlay
argument_list|)
argument_list|)
expr_stmt|;
name|playButton
operator|->
name|setIconSize
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
name|playButton
operator|->
name|setToolTip
argument_list|(
name|tr
argument_list|(
literal|"Play"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|playButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|movie
argument_list|,
name|SLOT
argument_list|(
name|start
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|pauseButton
operator|=
operator|new
name|QToolButton
expr_stmt|;
name|pauseButton
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|pauseButton
operator|->
name|setIcon
argument_list|(
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_MediaPause
argument_list|)
argument_list|)
expr_stmt|;
name|pauseButton
operator|->
name|setIconSize
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
name|pauseButton
operator|->
name|setToolTip
argument_list|(
name|tr
argument_list|(
literal|"Pause"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pauseButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|movie
argument_list|,
name|SLOT
argument_list|(
name|setPaused
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|stopButton
operator|=
operator|new
name|QToolButton
expr_stmt|;
name|stopButton
operator|->
name|setIcon
argument_list|(
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_MediaStop
argument_list|)
argument_list|)
expr_stmt|;
name|stopButton
operator|->
name|setIconSize
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
name|stopButton
operator|->
name|setToolTip
argument_list|(
name|tr
argument_list|(
literal|"Stop"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|stopButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|movie
argument_list|,
name|SLOT
argument_list|(
name|stop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|quitButton
operator|=
operator|new
name|QToolButton
expr_stmt|;
name|quitButton
operator|->
name|setIcon
argument_list|(
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_DialogCloseButton
argument_list|)
argument_list|)
expr_stmt|;
name|quitButton
operator|->
name|setIconSize
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
name|quitButton
operator|->
name|setToolTip
argument_list|(
name|tr
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
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
name|buttonsLayout
operator|=
operator|new
name|QHBoxLayout
expr_stmt|;
name|buttonsLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|buttonsLayout
operator|->
name|addWidget
argument_list|(
name|openButton
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addWidget
argument_list|(
name|playButton
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addWidget
argument_list|(
name|pauseButton
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addWidget
argument_list|(
name|stopButton
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addWidget
argument_list|(
name|quitButton
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
