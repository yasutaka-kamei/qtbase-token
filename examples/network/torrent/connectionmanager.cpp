begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"connectionmanager.h"
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QDateTime>
end_include
begin_decl_stmt
DECL|variable|MaxConnections
specifier|static
specifier|const
name|int
name|MaxConnections
init|=
literal|250
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|ConnectionManager
argument_list|,
argument|connectionManager
argument_list|)
end_macro
begin_function
DECL|function|instance
name|ConnectionManager
modifier|*
name|ConnectionManager
operator|::
name|instance
parameter_list|()
block|{
return|return
name|connectionManager
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|canAddConnection
name|bool
name|ConnectionManager
operator|::
name|canAddConnection
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|connections
operator|.
name|size
argument_list|()
operator|<
name|MaxConnections
operator|)
return|;
block|}
end_function
begin_function
DECL|function|addConnection
name|void
name|ConnectionManager
operator|::
name|addConnection
parameter_list|(
name|PeerWireClient
modifier|*
name|client
parameter_list|)
block|{
name|connections
operator|<<
name|client
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeConnection
name|void
name|ConnectionManager
operator|::
name|removeConnection
parameter_list|(
name|PeerWireClient
modifier|*
name|client
parameter_list|)
block|{
name|connections
operator|.
name|remove
argument_list|(
name|client
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|maxConnections
name|int
name|ConnectionManager
operator|::
name|maxConnections
parameter_list|()
specifier|const
block|{
return|return
name|MaxConnections
return|;
block|}
end_function
begin_function
DECL|function|clientId
name|QByteArray
name|ConnectionManager
operator|::
name|clientId
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|id
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Generate peer id
name|int
name|startupTime
init|=
name|int
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
operator|.
name|toTime_t
argument_list|()
argument_list|)
decl_stmt|;
name|id
operator|+=
name|QString
operator|::
name|asprintf
argument_list|(
literal|"-QT%04x-"
argument_list|,
operator|(
name|QT_VERSION
operator|%
literal|0xffff00
operator|)
operator|>>
literal|8
argument_list|)
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
name|id
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|startupTime
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|id
operator|+=
name|QByteArray
argument_list|(
literal|20
operator|-
name|id
operator|.
name|size
argument_list|()
argument_list|,
literal|'-'
argument_list|)
expr_stmt|;
block|}
return|return
name|id
return|;
block|}
end_function
end_unit
