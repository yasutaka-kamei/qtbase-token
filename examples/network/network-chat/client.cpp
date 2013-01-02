begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_constructor
DECL|function|Client
name|Client
operator|::
name|Client
parameter_list|()
block|{
name|peerManager
operator|=
operator|new
name|PeerManager
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|peerManager
operator|->
name|setServerPort
argument_list|(
name|server
operator|.
name|serverPort
argument_list|()
argument_list|)
expr_stmt|;
name|peerManager
operator|->
name|startBroadcasting
argument_list|()
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|peerManager
argument_list|,
name|SIGNAL
argument_list|(
name|newConnection
argument_list|(
name|Connection
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|newConnection
argument_list|(
name|Connection
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|server
argument_list|,
name|SIGNAL
argument_list|(
name|newConnection
argument_list|(
name|Connection
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|newConnection
argument_list|(
name|Connection
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|sendMessage
name|void
name|Client
operator|::
name|sendMessage
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
block|{
if|if
condition|(
name|message
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QList
argument_list|<
name|Connection
modifier|*
argument_list|>
name|connections
init|=
name|peers
operator|.
name|values
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|Connection
modifier|*
name|connection
decl|,
name|connections
control|)
name|connection
operator|->
name|sendMessage
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nickName
name|QString
name|Client
operator|::
name|nickName
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|(
name|peerManager
operator|->
name|userName
argument_list|()
argument_list|)
operator|+
literal|'@'
operator|+
name|QHostInfo
operator|::
name|localHostName
argument_list|()
operator|+
literal|':'
operator|+
name|QString
operator|::
name|number
argument_list|(
name|server
operator|.
name|serverPort
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|hasConnection
name|bool
name|Client
operator|::
name|hasConnection
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|senderIp
parameter_list|,
name|int
name|senderPort
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|senderPort
operator|==
operator|-
literal|1
condition|)
return|return
name|peers
operator|.
name|contains
argument_list|(
name|senderIp
argument_list|)
return|;
if|if
condition|(
operator|!
name|peers
operator|.
name|contains
argument_list|(
name|senderIp
argument_list|)
condition|)
return|return
literal|false
return|;
name|QList
argument_list|<
name|Connection
modifier|*
argument_list|>
name|connections
init|=
name|peers
operator|.
name|values
argument_list|(
name|senderIp
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|Connection
modifier|*
name|connection
decl|,
name|connections
control|)
block|{
if|if
condition|(
name|connection
operator|->
name|peerPort
argument_list|()
operator|==
name|senderPort
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
DECL|function|newConnection
name|void
name|Client
operator|::
name|newConnection
parameter_list|(
name|Connection
modifier|*
name|connection
parameter_list|)
block|{
name|connection
operator|->
name|setGreetingMessage
argument_list|(
name|peerManager
operator|->
name|userName
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|connection
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
name|connectionError
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|connection
argument_list|,
name|SIGNAL
argument_list|(
name|disconnected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|disconnected
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|connection
argument_list|,
name|SIGNAL
argument_list|(
name|readyForUse
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readyForUse
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readyForUse
name|void
name|Client
operator|::
name|readyForUse
parameter_list|()
block|{
name|Connection
modifier|*
name|connection
init|=
name|qobject_cast
argument_list|<
name|Connection
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|connection
operator|||
name|hasConnection
argument_list|(
name|connection
operator|->
name|peerAddress
argument_list|()
argument_list|,
name|connection
operator|->
name|peerPort
argument_list|()
argument_list|)
condition|)
return|return;
name|connect
argument_list|(
name|connection
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
name|SIGNAL
argument_list|(
name|newMessage
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|peers
operator|.
name|insert
argument_list|(
name|connection
operator|->
name|peerAddress
argument_list|()
argument_list|,
name|connection
argument_list|)
expr_stmt|;
name|QString
name|nick
init|=
name|connection
operator|->
name|name
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|nick
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|newParticipant
argument_list|(
name|nick
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|disconnected
name|void
name|Client
operator|::
name|disconnected
parameter_list|()
block|{
if|if
condition|(
name|Connection
modifier|*
name|connection
init|=
name|qobject_cast
argument_list|<
name|Connection
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
condition|)
name|removeConnection
argument_list|(
name|connection
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connectionError
name|void
name|Client
operator|::
name|connectionError
parameter_list|(
name|QAbstractSocket
operator|::
name|SocketError
comment|/* socketError */
parameter_list|)
block|{
if|if
condition|(
name|Connection
modifier|*
name|connection
init|=
name|qobject_cast
argument_list|<
name|Connection
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
condition|)
name|removeConnection
argument_list|(
name|connection
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeConnection
name|void
name|Client
operator|::
name|removeConnection
parameter_list|(
name|Connection
modifier|*
name|connection
parameter_list|)
block|{
if|if
condition|(
name|peers
operator|.
name|contains
argument_list|(
name|connection
operator|->
name|peerAddress
argument_list|()
argument_list|)
condition|)
block|{
name|peers
operator|.
name|remove
argument_list|(
name|connection
operator|->
name|peerAddress
argument_list|()
argument_list|)
expr_stmt|;
name|QString
name|nick
init|=
name|connection
operator|->
name|name
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|nick
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|participantLeft
argument_list|(
name|nick
argument_list|)
emit|;
block|}
name|connection
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
