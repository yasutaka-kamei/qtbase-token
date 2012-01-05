begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"sender.h"
end_include
begin_constructor
DECL|function|Sender
name|Sender
operator|::
name|Sender
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
name|statusLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Ready to broadcast datagrams on port 45454"
argument_list|)
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
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
name|timer
operator|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|//! [0]
name|udpSocket
operator|=
operator|new
name|QUdpSocket
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|//! [0]
name|messageNo
operator|=
literal|1
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
name|startBroadcasting
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
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|broadcastDatagram
argument_list|()
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
name|statusLabel
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
literal|"Broadcast Sender"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|startBroadcasting
name|void
name|Sender
operator|::
name|startBroadcasting
parameter_list|()
block|{
name|startButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|broadcastDatagram
name|void
name|Sender
operator|::
name|broadcastDatagram
parameter_list|()
block|{
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Now broadcasting datagram %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|messageNo
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
name|QByteArray
name|datagram
init|=
literal|"Broadcast message "
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|messageNo
argument_list|)
decl_stmt|;
name|udpSocket
operator|->
name|writeDatagram
argument_list|(
name|datagram
operator|.
name|data
argument_list|()
argument_list|,
name|datagram
operator|.
name|size
argument_list|()
argument_list|,
name|QHostAddress
operator|::
name|Broadcast
argument_list|,
literal|45454
argument_list|)
expr_stmt|;
comment|//! [1]
operator|++
name|messageNo
expr_stmt|;
block|}
end_function
end_unit
