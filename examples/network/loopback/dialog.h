begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DIALOG_H
end_ifndef
begin_define
DECL|macro|DIALOG_H
define|#
directive|define
name|DIALOG_H
end_define
begin_include
include|#
directive|include
file|<QDialog>
end_include
begin_include
include|#
directive|include
file|<QTcpServer>
end_include
begin_include
include|#
directive|include
file|<QTcpSocket>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
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
DECL|variable|QProgressBar
name|class
name|QProgressBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTcpServer
name|class
name|QTcpServer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTcpSocket
name|class
name|QTcpSocket
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|Dialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|public
operator|:
name|Dialog
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|start
argument_list|()
block|;
name|void
name|acceptConnection
argument_list|()
block|;
name|void
name|startTransfer
argument_list|()
block|;
name|void
name|updateServerProgress
argument_list|()
block|;
name|void
name|updateClientProgress
argument_list|(
argument|qint64 numBytes
argument_list|)
block|;
name|void
name|displayError
argument_list|(
argument|QAbstractSocket::SocketError socketError
argument_list|)
block|;
name|private
operator|:
name|QProgressBar
operator|*
name|clientProgressBar
block|;
name|QProgressBar
operator|*
name|serverProgressBar
block|;
name|QLabel
operator|*
name|clientStatusLabel
block|;
name|QLabel
operator|*
name|serverStatusLabel
block|;
name|QPushButton
operator|*
name|startButton
block|;
name|QPushButton
operator|*
name|quitButton
block|;
name|QDialogButtonBox
operator|*
name|buttonBox
block|;
name|QTcpServer
name|tcpServer
block|;
name|QTcpSocket
name|tcpClient
block|;
name|QTcpSocket
operator|*
name|tcpServerConnection
block|;
name|int
name|bytesToWrite
block|;
name|int
name|bytesWritten
block|;
name|int
name|bytesReceived
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
