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
file|"chatdialog.h"
end_include
begin_constructor
DECL|function|ChatDialog
name|ChatDialog
operator|::
name|ChatDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|listWidget
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|lineEdit
argument_list|,
name|SIGNAL
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|lineEdit
argument_list|,
name|SIGNAL
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|client
argument_list|,
name|SIGNAL
argument_list|(
name|newMessage
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|appendMessage
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|client
argument_list|,
name|SIGNAL
argument_list|(
name|newParticipant
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|newParticipant
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|client
argument_list|,
name|SIGNAL
argument_list|(
name|participantLeft
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|participantLeft
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|myNickName
operator|=
name|client
operator|.
name|nickName
argument_list|()
expr_stmt|;
name|newParticipant
argument_list|(
name|myNickName
argument_list|)
expr_stmt|;
name|tableFormat
operator|.
name|setBorder
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|10
operator|*
literal|1000
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showInformation
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|appendMessage
name|void
name|ChatDialog
operator|::
name|appendMessage
parameter_list|(
specifier|const
name|QString
modifier|&
name|from
parameter_list|,
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
block|{
if|if
condition|(
name|from
operator|.
name|isEmpty
argument_list|()
operator|||
name|message
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QTextCursor
name|cursor
argument_list|(
name|textEdit
operator|->
name|textCursor
argument_list|()
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|End
argument_list|)
expr_stmt|;
name|QTextTable
modifier|*
name|table
init|=
name|cursor
operator|.
name|insertTable
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|tableFormat
argument_list|)
decl_stmt|;
name|table
operator|->
name|cellAt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
operator|.
name|insertText
argument_list|(
literal|'<'
operator|+
name|from
operator|+
literal|"> "
argument_list|)
expr_stmt|;
name|table
operator|->
name|cellAt
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
operator|.
name|insertText
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|QScrollBar
modifier|*
name|bar
init|=
name|textEdit
operator|->
name|verticalScrollBar
argument_list|()
decl_stmt|;
name|bar
operator|->
name|setValue
argument_list|(
name|bar
operator|->
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|returnPressed
name|void
name|ChatDialog
operator|::
name|returnPressed
parameter_list|()
block|{
name|QString
name|text
init|=
name|lineEdit
operator|->
name|text
argument_list|()
decl_stmt|;
if|if
condition|(
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
if|if
condition|(
name|text
operator|.
name|startsWith
argument_list|(
name|QChar
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
block|{
name|QColor
name|color
init|=
name|textEdit
operator|->
name|textColor
argument_list|()
decl_stmt|;
name|textEdit
operator|->
name|setTextColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"! Unknown command: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|text
operator|.
name|left
argument_list|(
name|text
operator|.
name|indexOf
argument_list|(
literal|' '
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|setTextColor
argument_list|(
name|color
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|client
operator|.
name|sendMessage
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|appendMessage
argument_list|(
name|myNickName
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
name|lineEdit
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|newParticipant
name|void
name|ChatDialog
operator|::
name|newParticipant
parameter_list|(
specifier|const
name|QString
modifier|&
name|nick
parameter_list|)
block|{
if|if
condition|(
name|nick
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QColor
name|color
init|=
name|textEdit
operator|->
name|textColor
argument_list|()
decl_stmt|;
name|textEdit
operator|->
name|setTextColor
argument_list|(
name|Qt
operator|::
name|gray
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"* %1 has joined"
argument_list|)
operator|.
name|arg
argument_list|(
name|nick
argument_list|)
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|setTextColor
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|listWidget
operator|->
name|addItem
argument_list|(
name|nick
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|participantLeft
name|void
name|ChatDialog
operator|::
name|participantLeft
parameter_list|(
specifier|const
name|QString
modifier|&
name|nick
parameter_list|)
block|{
if|if
condition|(
name|nick
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QList
argument_list|<
name|QListWidgetItem
modifier|*
argument_list|>
name|items
init|=
name|listWidget
operator|->
name|findItems
argument_list|(
name|nick
argument_list|,
name|Qt
operator|::
name|MatchExactly
argument_list|)
decl_stmt|;
if|if
condition|(
name|items
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
operator|delete
name|items
operator|.
name|at
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QColor
name|color
init|=
name|textEdit
operator|->
name|textColor
argument_list|()
decl_stmt|;
name|textEdit
operator|->
name|setTextColor
argument_list|(
name|Qt
operator|::
name|gray
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"* %1 has left"
argument_list|)
operator|.
name|arg
argument_list|(
name|nick
argument_list|)
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|setTextColor
argument_list|(
name|color
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showInformation
name|void
name|ChatDialog
operator|::
name|showInformation
parameter_list|()
block|{
if|if
condition|(
name|listWidget
operator|->
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Chat"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Launch several instances of this "
literal|"program on your local network and "
literal|"start chatting!"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
