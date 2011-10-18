begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|"client.h"
end_include
begin_include
include|#
directive|include
file|"connection.h"
end_include
begin_include
include|#
directive|include
file|"peermanager.h"
end_include
begin_decl_stmt
DECL|variable|BroadcastInterval
specifier|static
specifier|const
name|qint32
name|BroadcastInterval
init|=
literal|2000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|broadcastPort
specifier|static
specifier|const
name|unsigned
name|broadcastPort
init|=
literal|45000
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|PeerManager
name|PeerManager
operator|::
name|PeerManager
parameter_list|(
name|Client
modifier|*
name|client
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|client
argument_list|)
block|{
name|this
operator|->
name|client
operator|=
name|client
expr_stmt|;
name|QStringList
name|envVariables
decl_stmt|;
name|envVariables
operator|<<
literal|"USERNAME.*"
operator|<<
literal|"USER.*"
operator|<<
literal|"USERDOMAIN.*"
operator|<<
literal|"HOSTNAME.*"
operator|<<
literal|"DOMAINNAME.*"
expr_stmt|;
name|QStringList
name|environment
init|=
name|QProcess
operator|::
name|systemEnvironment
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QString
name|string
decl|,
name|envVariables
control|)
block|{
name|int
name|index
init|=
name|environment
operator|.
name|indexOf
argument_list|(
name|QRegExp
argument_list|(
name|string
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
block|{
name|QStringList
name|stringList
init|=
name|environment
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|split
argument_list|(
literal|'='
argument_list|)
decl_stmt|;
if|if
condition|(
name|stringList
operator|.
name|size
argument_list|()
operator|==
literal|2
condition|)
block|{
name|username
operator|=
name|stringList
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toUtf8
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
if|if
condition|(
name|username
operator|.
name|isEmpty
argument_list|()
condition|)
name|username
operator|=
literal|"unknown"
expr_stmt|;
name|updateAddresses
argument_list|()
expr_stmt|;
name|serverPort
operator|=
literal|0
expr_stmt|;
name|broadcastSocket
operator|.
name|bind
argument_list|(
name|QHostAddress
operator|::
name|Any
argument_list|,
name|broadcastPort
argument_list|,
name|QUdpSocket
operator|::
name|ShareAddress
operator||
name|QUdpSocket
operator|::
name|ReuseAddressHint
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|broadcastSocket
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
name|readBroadcastDatagram
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|broadcastTimer
operator|.
name|setInterval
argument_list|(
name|BroadcastInterval
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|broadcastTimer
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
name|sendBroadcastDatagram
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setServerPort
name|void
name|PeerManager
operator|::
name|setServerPort
parameter_list|(
name|int
name|port
parameter_list|)
block|{
name|serverPort
operator|=
name|port
expr_stmt|;
block|}
end_function
begin_function
DECL|function|userName
name|QByteArray
name|PeerManager
operator|::
name|userName
parameter_list|()
specifier|const
block|{
return|return
name|username
return|;
block|}
end_function
begin_function
DECL|function|startBroadcasting
name|void
name|PeerManager
operator|::
name|startBroadcasting
parameter_list|()
block|{
name|broadcastTimer
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isLocalHostAddress
name|bool
name|PeerManager
operator|::
name|isLocalHostAddress
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|address
parameter_list|)
block|{
foreach|foreach
control|(
name|QHostAddress
name|localAddress
decl|,
name|ipAddresses
control|)
block|{
if|if
condition|(
name|address
operator|==
name|localAddress
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|sendBroadcastDatagram
name|void
name|PeerManager
operator|::
name|sendBroadcastDatagram
parameter_list|()
block|{
name|QByteArray
name|datagram
argument_list|(
name|username
argument_list|)
decl_stmt|;
name|datagram
operator|.
name|append
argument_list|(
literal|'@'
argument_list|)
expr_stmt|;
name|datagram
operator|.
name|append
argument_list|(
name|QByteArray
operator|::
name|number
argument_list|(
name|serverPort
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|validBroadcastAddresses
init|=
literal|true
decl_stmt|;
foreach|foreach
control|(
name|QHostAddress
name|address
decl|,
name|broadcastAddresses
control|)
block|{
if|if
condition|(
name|broadcastSocket
operator|.
name|writeDatagram
argument_list|(
name|datagram
argument_list|,
name|address
argument_list|,
name|broadcastPort
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|validBroadcastAddresses
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|validBroadcastAddresses
condition|)
name|updateAddresses
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readBroadcastDatagram
name|void
name|PeerManager
operator|::
name|readBroadcastDatagram
parameter_list|()
block|{
while|while
condition|(
name|broadcastSocket
operator|.
name|hasPendingDatagrams
argument_list|()
condition|)
block|{
name|QHostAddress
name|senderIp
decl_stmt|;
name|quint16
name|senderPort
decl_stmt|;
name|QByteArray
name|datagram
decl_stmt|;
name|datagram
operator|.
name|resize
argument_list|(
name|broadcastSocket
operator|.
name|pendingDatagramSize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|broadcastSocket
operator|.
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
argument_list|,
operator|&
name|senderIp
argument_list|,
operator|&
name|senderPort
argument_list|)
operator|==
operator|-
literal|1
condition|)
continue|continue;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|list
init|=
name|datagram
operator|.
name|split
argument_list|(
literal|'@'
argument_list|)
decl_stmt|;
if|if
condition|(
name|list
operator|.
name|size
argument_list|()
operator|!=
literal|2
condition|)
continue|continue;
name|int
name|senderServerPort
init|=
name|list
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|isLocalHostAddress
argument_list|(
name|senderIp
argument_list|)
operator|&&
name|senderServerPort
operator|==
name|serverPort
condition|)
continue|continue;
if|if
condition|(
operator|!
name|client
operator|->
name|hasConnection
argument_list|(
name|senderIp
argument_list|)
condition|)
block|{
name|Connection
modifier|*
name|connection
init|=
operator|new
name|Connection
argument_list|(
name|this
argument_list|)
decl_stmt|;
emit|emit
name|newConnection
argument_list|(
name|connection
argument_list|)
emit|;
name|connection
operator|->
name|connectToHost
argument_list|(
name|senderIp
argument_list|,
name|senderServerPort
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|updateAddresses
name|void
name|PeerManager
operator|::
name|updateAddresses
parameter_list|()
block|{
name|broadcastAddresses
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ipAddresses
operator|.
name|clear
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QNetworkInterface
name|interface
decl|,
name|QNetworkInterface
operator|::
name|allInterfaces
argument_list|()
control|)
block|{
foreach|foreach
control|(
name|QNetworkAddressEntry
name|entry
decl|,
name|interface
operator|.
name|addressEntries
argument_list|()
control|)
block|{
name|QHostAddress
name|broadcastAddress
init|=
name|entry
operator|.
name|broadcast
argument_list|()
decl_stmt|;
if|if
condition|(
name|broadcastAddress
operator|!=
name|QHostAddress
operator|::
name|Null
operator|&&
name|entry
operator|.
name|ip
argument_list|()
operator|!=
name|QHostAddress
operator|::
name|LocalHost
condition|)
block|{
name|broadcastAddresses
operator|<<
name|broadcastAddress
expr_stmt|;
name|ipAddresses
operator|<<
name|entry
operator|.
name|ip
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
end_unit
