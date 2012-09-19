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
file|"receiver.h"
end_include
begin_constructor
DECL|function|Receiver
name|Receiver
operator|::
name|Receiver
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
literal|"Listening for broadcasted messages"
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
comment|//! [0]
name|udpSocket
operator|=
operator|new
name|QUdpSocket
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|udpSocket
operator|->
name|bind
argument_list|(
literal|45454
argument_list|,
name|QUdpSocket
operator|::
name|ShareAddress
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|connect
argument_list|(
name|udpSocket
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
name|processPendingDatagrams
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
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
name|QHBoxLayout
modifier|*
name|buttonLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|buttonLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|quitButton
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addStretch
argument_list|(
literal|1
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
name|addLayout
argument_list|(
name|buttonLayout
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
literal|"Broadcast Receiver"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|processPendingDatagrams
name|void
name|Receiver
operator|::
name|processPendingDatagrams
parameter_list|()
block|{
comment|//! [2]
while|while
condition|(
name|udpSocket
operator|->
name|hasPendingDatagrams
argument_list|()
condition|)
block|{
name|QByteArray
name|datagram
decl_stmt|;
name|datagram
operator|.
name|resize
argument_list|(
name|udpSocket
operator|->
name|pendingDatagramSize
argument_list|()
argument_list|)
expr_stmt|;
name|udpSocket
operator|->
name|readDatagram
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
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Received datagram: \"%1\""
argument_list|)
operator|.
name|arg
argument_list|(
name|datagram
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//! [2]
block|}
end_function
end_unit
