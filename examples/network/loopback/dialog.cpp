begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|"dialog.h"
end_include
begin_decl_stmt
DECL|variable|TotalBytes
specifier|static
specifier|const
name|int
name|TotalBytes
init|=
literal|50
operator|*
literal|1024
operator|*
literal|1024
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|PayloadSize
specifier|static
specifier|const
name|int
name|PayloadSize
init|=
literal|64
operator|*
literal|1024
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|PayloadSize
comment|// 64 KB
end_comment
begin_constructor
DECL|function|Dialog
name|Dialog
operator|::
name|Dialog
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
name|clientProgressBar
operator|=
operator|new
name|QProgressBar
expr_stmt|;
name|clientStatusLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Client ready"
argument_list|)
argument_list|)
expr_stmt|;
name|serverProgressBar
operator|=
operator|new
name|QProgressBar
expr_stmt|;
name|serverStatusLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Server ready"
argument_list|)
argument_list|)
expr_stmt|;
name|startButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Start"
argument_list|)
argument_list|)
expr_stmt|;
name|quitButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&Quit"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
operator|new
name|QDialogButtonBox
expr_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|startButton
argument_list|,
name|QDialogButtonBox
operator|::
name|ActionRole
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|quitButton
argument_list|,
name|QDialogButtonBox
operator|::
name|RejectRole
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|startButton
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
name|start
argument_list|()
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
name|connect
argument_list|(
operator|&
name|tcpServer
argument_list|,
name|SIGNAL
argument_list|(
name|newConnection
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|acceptConnection
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|tcpClient
argument_list|,
name|SIGNAL
argument_list|(
name|connected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|startTransfer
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|tcpClient
argument_list|,
name|SIGNAL
argument_list|(
name|bytesWritten
argument_list|(
name|qint64
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateClientProgress
argument_list|(
name|qint64
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|tcpClient
argument_list|,
name|SIGNAL
argument_list|(
name|error
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|displayError
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|clientProgressBar
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|clientStatusLabel
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|serverProgressBar
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|serverStatusLabel
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addSpacing
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Loopback"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|start
name|void
name|Dialog
operator|::
name|start
parameter_list|()
block|{
name|startButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|bytesWritten
operator|=
literal|0
expr_stmt|;
name|bytesReceived
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|!
name|tcpServer
operator|.
name|isListening
argument_list|()
operator|&&
operator|!
name|tcpServer
operator|.
name|listen
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|StandardButton
name|ret
init|=
name|QMessageBox
operator|::
name|critical
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Loopback"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Unable to start the test: %1."
argument_list|)
operator|.
name|arg
argument_list|(
name|tcpServer
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Retry
operator||
name|QMessageBox
operator|::
name|Cancel
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
name|QMessageBox
operator|::
name|Cancel
condition|)
return|return;
block|}
name|serverStatusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Listening"
argument_list|)
argument_list|)
expr_stmt|;
name|clientStatusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Connecting"
argument_list|)
argument_list|)
expr_stmt|;
name|tcpClient
operator|.
name|connectToHost
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|,
name|tcpServer
operator|.
name|serverPort
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptConnection
name|void
name|Dialog
operator|::
name|acceptConnection
parameter_list|()
block|{
name|tcpServerConnection
operator|=
name|tcpServer
operator|.
name|nextPendingConnection
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|tcpServerConnection
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateServerProgress
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|tcpServerConnection
argument_list|,
name|SIGNAL
argument_list|(
name|error
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|displayError
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|serverStatusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Accepted connection"
argument_list|)
argument_list|)
expr_stmt|;
name|tcpServer
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startTransfer
name|void
name|Dialog
operator|::
name|startTransfer
parameter_list|()
block|{
comment|// called when the TCP client connected to the loopback server
name|bytesToWrite
operator|=
name|TotalBytes
operator|-
operator|(
name|int
operator|)
name|tcpClient
operator|.
name|write
argument_list|(
name|QByteArray
argument_list|(
name|PayloadSize
argument_list|,
literal|'@'
argument_list|)
argument_list|)
expr_stmt|;
name|clientStatusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Connected"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateServerProgress
name|void
name|Dialog
operator|::
name|updateServerProgress
parameter_list|()
block|{
name|bytesReceived
operator|+=
operator|(
name|int
operator|)
name|tcpServerConnection
operator|->
name|bytesAvailable
argument_list|()
expr_stmt|;
name|tcpServerConnection
operator|->
name|readAll
argument_list|()
expr_stmt|;
name|serverProgressBar
operator|->
name|setMaximum
argument_list|(
name|TotalBytes
argument_list|)
expr_stmt|;
name|serverProgressBar
operator|->
name|setValue
argument_list|(
name|bytesReceived
argument_list|)
expr_stmt|;
name|serverStatusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Received %1MB"
argument_list|)
operator|.
name|arg
argument_list|(
name|bytesReceived
operator|/
operator|(
literal|1024
operator|*
literal|1024
operator|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|bytesReceived
operator|==
name|TotalBytes
condition|)
block|{
name|tcpServerConnection
operator|->
name|close
argument_list|()
expr_stmt|;
name|startButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|updateClientProgress
name|void
name|Dialog
operator|::
name|updateClientProgress
parameter_list|(
name|qint64
name|numBytes
parameter_list|)
block|{
comment|// callen when the TCP client has written some bytes
name|bytesWritten
operator|+=
operator|(
name|int
operator|)
name|numBytes
expr_stmt|;
comment|// only write more if not finished and when the Qt write buffer is below a certain size.
if|if
condition|(
name|bytesToWrite
operator|>
literal|0
operator|&&
name|tcpClient
operator|.
name|bytesToWrite
argument_list|()
operator|<=
literal|4
operator|*
name|PayloadSize
condition|)
name|bytesToWrite
operator|-=
operator|(
name|int
operator|)
name|tcpClient
operator|.
name|write
argument_list|(
name|QByteArray
argument_list|(
name|qMin
argument_list|(
name|bytesToWrite
argument_list|,
name|PayloadSize
argument_list|)
argument_list|,
literal|'@'
argument_list|)
argument_list|)
expr_stmt|;
name|clientProgressBar
operator|->
name|setMaximum
argument_list|(
name|TotalBytes
argument_list|)
expr_stmt|;
name|clientProgressBar
operator|->
name|setValue
argument_list|(
name|bytesWritten
argument_list|)
expr_stmt|;
name|clientStatusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Sent %1MB"
argument_list|)
operator|.
name|arg
argument_list|(
name|bytesWritten
operator|/
operator|(
literal|1024
operator|*
literal|1024
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|displayError
name|void
name|Dialog
operator|::
name|displayError
parameter_list|(
name|QAbstractSocket
operator|::
name|SocketError
name|socketError
parameter_list|)
block|{
if|if
condition|(
name|socketError
operator|==
name|QTcpSocket
operator|::
name|RemoteHostClosedError
condition|)
return|return;
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Network error"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The following error occurred: %1."
argument_list|)
operator|.
name|arg
argument_list|(
name|tcpClient
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|tcpClient
operator|.
name|close
argument_list|()
expr_stmt|;
name|tcpServer
operator|.
name|close
argument_list|()
expr_stmt|;
name|clientProgressBar
operator|->
name|reset
argument_list|()
expr_stmt|;
name|serverProgressBar
operator|->
name|reset
argument_list|()
expr_stmt|;
name|clientStatusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Client ready"
argument_list|)
argument_list|)
expr_stmt|;
name|serverStatusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Server ready"
argument_list|)
argument_list|)
expr_stmt|;
name|startButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function
end_unit
