begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CHAT_H
end_ifndef
begin_define
DECL|macro|CHAT_H
define|#
directive|define
name|CHAT_H
end_define
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|"ui_chatmainwindow.h"
end_include
begin_include
include|#
directive|include
file|"ui_chatsetnickname.h"
end_include
begin_decl_stmt
DECL|variable|QMainWindow
name|class
name|ChatMainWindow
range|:
name|public
name|QMainWindow
decl_stmt|,
name|Ui
decl|::
name|ChatMainWindow
block|{
name|Q_OBJECT
name|QString
name|m_nickname
decl_stmt|;
name|QStringList
name|m_messages
decl_stmt|;
name|public
label|:
name|ChatMainWindow
argument_list|()
expr_stmt|;
operator|~
name|ChatMainWindow
argument_list|()
expr_stmt|;
name|void
name|rebuildHistory
parameter_list|()
function_decl|;
name|signals
label|:
name|void
name|message
parameter_list|(
specifier|const
name|QString
modifier|&
name|nickname
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|void
name|action
parameter_list|(
specifier|const
name|QString
modifier|&
name|nickname
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|private
name|slots
range|:
name|void
name|messageSlot
argument_list|(
specifier|const
name|QString
operator|&
name|nickname
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
decl_stmt|;
name|void
name|actionSlot
parameter_list|(
specifier|const
name|QString
modifier|&
name|nickname
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|void
name|textChangedSlot
parameter_list|(
specifier|const
name|QString
modifier|&
name|newText
parameter_list|)
function_decl|;
name|void
name|sendClickedSlot
parameter_list|()
function_decl|;
name|void
name|changeNickname
parameter_list|()
function_decl|;
name|void
name|aboutQt
parameter_list|()
function_decl|;
name|void
name|exiting
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QDialog
name|class
name|NicknameDialog
range|:
name|public
name|QDialog
decl_stmt|,
name|public
name|Ui
decl|::
name|NicknameDialog
block|{
name|Q_OBJECT
name|public
range|:
name|NicknameDialog
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CHAT_H
end_comment
end_unit
