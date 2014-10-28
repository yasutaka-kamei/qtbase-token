begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_comment
comment|//! [Window constructor start]
end_comment
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|thread
operator|=
operator|new
name|RenderThread
argument_list|()
expr_stmt|;
comment|//! [Window constructor start] //! [set up widgets and connections]
name|label
operator|=
operator|new
name|QLabel
argument_list|()
expr_stmt|;
name|label
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|loadButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Load image..."
argument_list|)
argument_list|)
expr_stmt|;
name|resetButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Stop"
argument_list|)
argument_list|)
expr_stmt|;
name|resetButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|loadButton
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
name|loadImage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|resetButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|thread
argument_list|,
name|SLOT
argument_list|(
name|stopProcess
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|thread
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|resetUi
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [set up widgets and connections] //! [connecting signal with custom type]
name|connect
argument_list|(
name|thread
argument_list|,
name|SIGNAL
argument_list|(
name|sendBlock
argument_list|(
name|Block
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|addBlock
argument_list|(
name|Block
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [connecting signal with custom type]
name|QHBoxLayout
modifier|*
name|buttonLayout
init|=
operator|new
name|QHBoxLayout
argument_list|()
decl_stmt|;
name|buttonLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|loadButton
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|resetButton
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addLayout
argument_list|(
name|buttonLayout
argument_list|)
expr_stmt|;
comment|//! [Window constructor finish]
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Queued Custom Type"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [Window constructor finish]
end_comment
begin_function
DECL|function|loadImage
name|void
name|Window
operator|::
name|loadImage
parameter_list|()
block|{
name|QStringList
name|formats
decl_stmt|;
foreach|foreach
control|(
name|QByteArray
name|format
decl|,
name|QImageReader
operator|::
name|supportedImageFormats
argument_list|()
control|)
if|if
condition|(
name|format
operator|.
name|toLower
argument_list|()
operator|==
name|format
condition|)
name|formats
operator|.
name|append
argument_list|(
literal|"*."
operator|+
name|format
argument_list|)
expr_stmt|;
name|QString
name|newPath
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open Image"
argument_list|)
argument_list|,
name|path
argument_list|,
name|tr
argument_list|(
literal|"Image files (%1)"
argument_list|)
operator|.
name|arg
argument_list|(
name|formats
operator|.
name|join
argument_list|(
literal|' '
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|newPath
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QImage
name|image
argument_list|(
name|newPath
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|loadImage
argument_list|(
name|image
argument_list|)
expr_stmt|;
name|path
operator|=
name|newPath
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|loadImage
name|void
name|Window
operator|::
name|loadImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|QDesktopWidget
name|desktop
decl_stmt|;
name|QImage
name|useImage
decl_stmt|;
name|QRect
name|space
init|=
name|desktop
operator|.
name|availableGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|image
operator|.
name|width
argument_list|()
operator|>
literal|0.75
operator|*
name|space
operator|.
name|width
argument_list|()
operator|||
name|image
operator|.
name|height
argument_list|()
operator|>
literal|0.75
operator|*
name|space
operator|.
name|height
argument_list|()
condition|)
name|useImage
operator|=
name|image
operator|.
name|scaled
argument_list|(
literal|0.75
operator|*
name|space
operator|.
name|width
argument_list|()
argument_list|,
literal|0.75
operator|*
name|space
operator|.
name|height
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
expr_stmt|;
else|else
name|useImage
operator|=
name|image
expr_stmt|;
name|pixmap
operator|=
name|QPixmap
argument_list|(
name|useImage
operator|.
name|width
argument_list|()
argument_list|,
name|useImage
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|pixmap
operator|.
name|fill
argument_list|(
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|loadButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|resetButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|thread
operator|->
name|processImage
argument_list|(
name|useImage
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [Adding blocks to the display]
end_comment
begin_function
DECL|function|addBlock
name|void
name|Window
operator|::
name|addBlock
parameter_list|(
specifier|const
name|Block
modifier|&
name|block
parameter_list|)
block|{
name|QColor
name|color
init|=
name|block
operator|.
name|color
argument_list|()
decl_stmt|;
name|color
operator|.
name|setAlpha
argument_list|(
literal|64
argument_list|)
expr_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|pixmap
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|block
operator|.
name|rect
argument_list|()
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|label
operator|->
name|setPixmap
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [Adding blocks to the display]
end_comment
begin_function
DECL|function|resetUi
name|void
name|Window
operator|::
name|resetUi
parameter_list|()
block|{
name|loadButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|resetButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
end_unit