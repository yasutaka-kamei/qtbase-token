begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"ui_landscape.h"
end_include
begin_include
include|#
directive|include
file|"ui_portrait.h"
end_include
begin_include
include|#
directive|include
file|<QDesktopWidget>
end_include
begin_include
include|#
directive|include
file|<QResizeEvent>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
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
member_init_list|,
name|landscapeWidget
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|portraitWidget
argument_list|(
literal|0
argument_list|)
block|{
name|landscapeWidget
operator|=
operator|new
name|QWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|landscape
operator|.
name|setupUi
argument_list|(
name|landscapeWidget
argument_list|)
expr_stmt|;
name|portraitWidget
operator|=
operator|new
name|QWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|portrait
operator|.
name|setupUi
argument_list|(
name|portraitWidget
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|connect
argument_list|(
name|portrait
operator|.
name|exitButton
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
name|connect
argument_list|(
name|landscape
operator|.
name|exitButton
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
name|connect
argument_list|(
name|landscape
operator|.
name|buttonGroup
argument_list|,
name|SIGNAL
argument_list|(
name|buttonClicked
argument_list|(
name|QAbstractButton
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onRadioButtonClicked
argument_list|(
name|QAbstractButton
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|landscape
operator|.
name|radioAButton
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|onRadioButtonClicked
argument_list|(
name|landscape
operator|.
name|radioAButton
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
block|}
end_constructor
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|MainWindow
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|QSize
name|size
init|=
name|event
operator|->
name|size
argument_list|()
decl_stmt|;
name|bool
name|isLandscape
init|=
name|size
operator|.
name|width
argument_list|()
operator|>
name|size
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|isLandscape
condition|)
name|size
operator|.
name|transpose
argument_list|()
expr_stmt|;
name|landscapeWidget
operator|->
name|setFixedSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|size
operator|.
name|transpose
argument_list|()
expr_stmt|;
name|portraitWidget
operator|->
name|setFixedSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|landscapeWidget
operator|->
name|setVisible
argument_list|(
name|isLandscape
argument_list|)
expr_stmt|;
name|portraitWidget
operator|->
name|setVisible
argument_list|(
operator|!
name|isLandscape
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
DECL|function|onRadioButtonClicked
name|void
name|MainWindow
operator|::
name|onRadioButtonClicked
parameter_list|(
name|QAbstractButton
modifier|*
name|button
parameter_list|)
block|{
name|QString
name|styleTemplate
init|=
literal|"background-image: url(:/image_%1.png);"
literal|"background-repeat: no-repeat;"
literal|"background-position: center center"
decl_stmt|;
name|QString
name|imageStyle
argument_list|(
literal|""
argument_list|)
decl_stmt|;
if|if
condition|(
name|button
operator|==
name|landscape
operator|.
name|radioAButton
condition|)
name|imageStyle
operator|=
name|styleTemplate
operator|.
name|arg
argument_list|(
literal|"a"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|button
operator|==
name|landscape
operator|.
name|radioBButton
condition|)
name|imageStyle
operator|=
name|styleTemplate
operator|.
name|arg
argument_list|(
literal|"b"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|button
operator|==
name|landscape
operator|.
name|radioCButton
condition|)
name|imageStyle
operator|=
name|styleTemplate
operator|.
name|arg
argument_list|(
literal|"c"
argument_list|)
expr_stmt|;
name|portrait
operator|.
name|choiceWidget
operator|->
name|setStyleSheet
argument_list|(
name|imageStyle
argument_list|)
expr_stmt|;
name|landscape
operator|.
name|choiceWidget
operator|->
name|setStyleSheet
argument_list|(
name|imageStyle
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
