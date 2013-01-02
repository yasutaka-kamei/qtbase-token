begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CLIENT_H
end_ifndef
begin_define
DECL|macro|CLIENT_H
define|#
directive|define
name|CLIENT_H
end_define
begin_include
include|#
directive|include
file|<QDialog>
end_include
begin_include
include|#
directive|include
file|<QTcpSocket>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDialogButtonBox
name|class
name|QDialogButtonBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTcpSocket
name|class
name|QTcpSocket
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkSession
name|class
name|QNetworkSession
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|Client
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|public
operator|:
name|Client
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|requestNewFortune
argument_list|()
block|;
name|void
name|readFortune
argument_list|()
block|;
name|void
name|displayError
argument_list|(
argument|QAbstractSocket::SocketError socketError
argument_list|)
block|;
name|void
name|enableGetFortuneButton
argument_list|()
block|;
name|void
name|sessionOpened
argument_list|()
block|;
name|private
operator|:
name|QLabel
operator|*
name|hostLabel
block|;
name|QLabel
operator|*
name|portLabel
block|;
name|QComboBox
operator|*
name|hostCombo
block|;
name|QLineEdit
operator|*
name|portLineEdit
block|;
name|QLabel
operator|*
name|statusLabel
block|;
name|QPushButton
operator|*
name|getFortuneButton
block|;
name|QPushButton
operator|*
name|quitButton
block|;
name|QDialogButtonBox
operator|*
name|buttonBox
block|;
name|QTcpSocket
operator|*
name|tcpSocket
block|;
name|QString
name|currentFortune
block|;
name|quint16
name|blockSize
block|;
name|QNetworkSession
operator|*
name|networkSession
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
