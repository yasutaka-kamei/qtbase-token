begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"previewwindow.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|PreviewWindow
name|PreviewWindow
operator|::
name|PreviewWindow
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
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|textEdit
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|setLineWrapMode
argument_list|(
name|QTextEdit
operator|::
name|NoWrap
argument_list|)
expr_stmt|;
name|closeButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Close"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|closeButton
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
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|textEdit
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|closeButton
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Preview"
argument_list|)
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
DECL|function|setWindowFlags
name|void
name|PreviewWindow
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
name|QWidget
operator|::
name|setWindowFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
name|QString
name|text
decl_stmt|;
name|Qt
operator|::
name|WindowFlags
name|type
init|=
operator|(
name|flags
operator|&
name|Qt
operator|::
name|WindowType_Mask
operator|)
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Window
condition|)
block|{
name|text
operator|=
literal|"Qt::Window"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Dialog
condition|)
block|{
name|text
operator|=
literal|"Qt::Dialog"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Sheet
condition|)
block|{
name|text
operator|=
literal|"Qt::Sheet"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Drawer
condition|)
block|{
name|text
operator|=
literal|"Qt::Drawer"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Popup
condition|)
block|{
name|text
operator|=
literal|"Qt::Popup"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|Tool
condition|)
block|{
name|text
operator|=
literal|"Qt::Tool"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|ToolTip
condition|)
block|{
name|text
operator|=
literal|"Qt::ToolTip"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|Qt
operator|::
name|SplashScreen
condition|)
block|{
name|text
operator|=
literal|"Qt::SplashScreen"
expr_stmt|;
block|}
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|MSWindowsFixedSizeDialogHint
condition|)
name|text
operator|+=
literal|"\n| Qt::MSWindowsFixedSizeDialogHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|X11BypassWindowManagerHint
condition|)
name|text
operator|+=
literal|"\n| Qt::X11BypassWindowManagerHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|FramelessWindowHint
condition|)
name|text
operator|+=
literal|"\n| Qt::FramelessWindowHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|NoDropShadowWindowHint
condition|)
name|text
operator|+=
literal|"\n| Qt::NoDropShadowWindowHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowTitleHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowTitleHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowSystemMenuHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowSystemMenuHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowMinimizeButtonHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowMinimizeButtonHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowMaximizeButtonHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowMaximizeButtonHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowCloseButtonHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowCloseButtonHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowContextHelpButtonHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowContextHelpButtonHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowShadeButtonHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowShadeButtonHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowStaysOnTopHint
condition|)
name|text
operator|+=
literal|"\n| Qt::WindowStaysOnTopHint"
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|CustomizeWindowHint
condition|)
name|text
operator|+=
literal|"\n| Qt::CustomizeWindowHint"
expr_stmt|;
name|textEdit
operator|->
name|setPlainText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
end_unit
