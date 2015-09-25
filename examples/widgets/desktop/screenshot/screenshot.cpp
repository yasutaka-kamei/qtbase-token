begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"screenshot.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Screenshot
name|Screenshot
operator|::
name|Screenshot
parameter_list|()
member_init_list|:
name|screenshotLabel
argument_list|(
operator|new
name|QLabel
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|screenshotLabel
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
name|screenshotLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|screenGeometry
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screenGeometry
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|screenshotLabel
operator|->
name|setMinimumSize
argument_list|(
name|screenGeometry
operator|.
name|width
argument_list|()
operator|/
literal|8
argument_list|,
name|screenGeometry
operator|.
name|height
argument_list|()
operator|/
literal|8
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|screenshotLabel
argument_list|)
expr_stmt|;
name|QGroupBox
modifier|*
name|optionsGroupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Options"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|delaySpinBox
operator|=
operator|new
name|QSpinBox
argument_list|(
name|optionsGroupBox
argument_list|)
expr_stmt|;
name|delaySpinBox
operator|->
name|setSuffix
argument_list|(
name|tr
argument_list|(
literal|" s"
argument_list|)
argument_list|)
expr_stmt|;
name|delaySpinBox
operator|->
name|setMaximum
argument_list|(
literal|60
argument_list|)
expr_stmt|;
typedef|typedef
name|void
function_decl|(
name|QSpinBox
operator|::
modifier|*
name|QSpinBoxIntSignal
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|connect
argument_list|(
name|delaySpinBox
argument_list|,
cast|static_cast
argument_list|<
name|QSpinBoxIntSignal
argument_list|>
argument_list|(
operator|&
name|QSpinBox
operator|::
name|valueChanged
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|Screenshot
operator|::
name|updateCheckBox
argument_list|)
expr_stmt|;
name|hideThisWindowCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Hide This Window"
argument_list|)
argument_list|,
name|optionsGroupBox
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|optionsGroupBoxLayout
init|=
operator|new
name|QGridLayout
argument_list|(
name|optionsGroupBox
argument_list|)
decl_stmt|;
name|optionsGroupBoxLayout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Screenshot Delay:"
argument_list|)
argument_list|,
name|this
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|optionsGroupBoxLayout
operator|->
name|addWidget
argument_list|(
name|delaySpinBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|optionsGroupBoxLayout
operator|->
name|addWidget
argument_list|(
name|hideThisWindowCheckBox
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|optionsGroupBox
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|buttonsLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|newScreenshotButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"New Screenshot"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|newScreenshotButton
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
operator|&
name|Screenshot
operator|::
name|newScreenshot
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addWidget
argument_list|(
name|newScreenshotButton
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|saveScreenshotButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Save Screenshot"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|saveScreenshotButton
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
operator|&
name|Screenshot
operator|::
name|saveScreenshot
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addWidget
argument_list|(
name|saveScreenshotButton
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|quitScreenshotButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Quit"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|quitScreenshotButton
operator|->
name|setShortcut
argument_list|(
name|Qt
operator|::
name|CTRL
operator|+
name|Qt
operator|::
name|Key_Q
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitScreenshotButton
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
operator|&
name|QWidget
operator|::
name|close
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addWidget
argument_list|(
name|quitScreenshotButton
argument_list|)
expr_stmt|;
name|buttonsLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|buttonsLayout
argument_list|)
expr_stmt|;
name|shootScreen
argument_list|()
expr_stmt|;
name|delaySpinBox
operator|->
name|setValue
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Screenshot"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|300
argument_list|,
literal|200
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|Screenshot
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
comment|/* event */
parameter_list|)
block|{
name|QSize
name|scaledSize
init|=
name|originalPixmap
operator|.
name|size
argument_list|()
decl_stmt|;
name|scaledSize
operator|.
name|scale
argument_list|(
name|screenshotLabel
operator|->
name|size
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|screenshotLabel
operator|->
name|pixmap
argument_list|()
operator|||
name|scaledSize
operator|!=
name|screenshotLabel
operator|->
name|pixmap
argument_list|()
operator|->
name|size
argument_list|()
condition|)
name|updateScreenshotLabel
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|newScreenshot
name|void
name|Screenshot
operator|::
name|newScreenshot
parameter_list|()
block|{
if|if
condition|(
name|hideThisWindowCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|hide
argument_list|()
expr_stmt|;
name|newScreenshotButton
operator|->
name|setDisabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
name|delaySpinBox
operator|->
name|value
argument_list|()
operator|*
literal|1000
argument_list|,
name|this
argument_list|,
operator|&
name|Screenshot
operator|::
name|shootScreen
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|saveScreenshot
name|void
name|Screenshot
operator|::
name|saveScreenshot
parameter_list|()
block|{
specifier|const
name|QString
name|format
init|=
literal|"png"
decl_stmt|;
name|QString
name|initialPath
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|PicturesLocation
argument_list|)
decl_stmt|;
if|if
condition|(
name|initialPath
operator|.
name|isEmpty
argument_list|()
condition|)
name|initialPath
operator|=
name|QDir
operator|::
name|currentPath
argument_list|()
expr_stmt|;
name|initialPath
operator|+=
name|tr
argument_list|(
literal|"/untitled."
argument_list|)
operator|+
name|format
expr_stmt|;
name|QFileDialog
name|fileDialog
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Save As"
argument_list|)
argument_list|,
name|initialPath
argument_list|)
decl_stmt|;
name|fileDialog
operator|.
name|setAcceptMode
argument_list|(
name|QFileDialog
operator|::
name|AcceptSave
argument_list|)
expr_stmt|;
name|fileDialog
operator|.
name|setFileMode
argument_list|(
name|QFileDialog
operator|::
name|AnyFile
argument_list|)
expr_stmt|;
name|fileDialog
operator|.
name|setDirectory
argument_list|(
name|initialPath
argument_list|)
expr_stmt|;
name|QStringList
name|mimeTypes
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QByteArray
modifier|&
name|bf
decl|,
name|QImageWriter
operator|::
name|supportedMimeTypes
argument_list|()
control|)
name|mimeTypes
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
name|bf
argument_list|)
argument_list|)
expr_stmt|;
name|fileDialog
operator|.
name|setMimeTypeFilters
argument_list|(
name|mimeTypes
argument_list|)
expr_stmt|;
name|fileDialog
operator|.
name|selectMimeTypeFilter
argument_list|(
literal|"image/"
operator|+
name|format
argument_list|)
expr_stmt|;
name|fileDialog
operator|.
name|setDefaultSuffix
argument_list|(
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
name|fileDialog
operator|.
name|exec
argument_list|()
operator|!=
name|QDialog
operator|::
name|Accepted
condition|)
return|return;
specifier|const
name|QString
name|fileName
init|=
name|fileDialog
operator|.
name|selectedFiles
argument_list|()
operator|.
name|first
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|originalPixmap
operator|.
name|save
argument_list|(
name|fileName
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Save Error"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The image could not be saved to \"%1\"."
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|shootScreen
name|void
name|Screenshot
operator|::
name|shootScreen
parameter_list|()
block|{
name|QScreen
modifier|*
name|screen
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
decl_stmt|;
if|if
condition|(
specifier|const
name|QWindow
modifier|*
name|window
init|=
name|windowHandle
argument_list|()
condition|)
name|screen
operator|=
name|window
operator|->
name|screen
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|screen
condition|)
return|return;
if|if
condition|(
name|delaySpinBox
operator|->
name|value
argument_list|()
operator|!=
literal|0
condition|)
name|QApplication
operator|::
name|beep
argument_list|()
expr_stmt|;
name|originalPixmap
operator|=
name|screen
operator|->
name|grabWindow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|updateScreenshotLabel
argument_list|()
expr_stmt|;
name|newScreenshotButton
operator|->
name|setDisabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|hideThisWindowCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|updateCheckBox
name|void
name|Screenshot
operator|::
name|updateCheckBox
parameter_list|()
block|{
if|if
condition|(
name|delaySpinBox
operator|->
name|value
argument_list|()
operator|==
literal|0
condition|)
block|{
name|hideThisWindowCheckBox
operator|->
name|setDisabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|hideThisWindowCheckBox
operator|->
name|setChecked
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|hideThisWindowCheckBox
operator|->
name|setDisabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|updateScreenshotLabel
name|void
name|Screenshot
operator|::
name|updateScreenshotLabel
parameter_list|()
block|{
name|screenshotLabel
operator|->
name|setPixmap
argument_list|(
name|originalPixmap
operator|.
name|scaled
argument_list|(
name|screenshotLabel
operator|->
name|size
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|,
name|Qt
operator|::
name|SmoothTransformation
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
end_unit
