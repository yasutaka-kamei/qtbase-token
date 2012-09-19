begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|"fortunethread.h"
end_include
begin_constructor
DECL|function|FortuneThread
name|FortuneThread
operator|::
name|FortuneThread
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|quit
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_destructor
DECL|function|~FortuneThread
name|FortuneThread
operator|::
name|~
name|FortuneThread
parameter_list|()
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|quit
operator|=
literal|true
expr_stmt|;
name|cond
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|wait
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1] //! [2]
end_comment
begin_function
DECL|function|requestNewFortune
name|void
name|FortuneThread
operator|::
name|requestNewFortune
parameter_list|(
specifier|const
name|QString
modifier|&
name|hostName
parameter_list|,
name|quint16
name|port
parameter_list|)
block|{
comment|//! [1]
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|this
operator|->
name|hostName
operator|=
name|hostName
expr_stmt|;
name|this
operator|->
name|port
operator|=
name|port
expr_stmt|;
comment|//! [3]
if|if
condition|(
operator|!
name|isRunning
argument_list|()
condition|)
name|start
argument_list|()
expr_stmt|;
else|else
name|cond
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2] //! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|run
name|void
name|FortuneThread
operator|::
name|run
parameter_list|()
block|{
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
comment|//! [4] //! [5]
name|QString
name|serverName
init|=
name|hostName
decl_stmt|;
name|quint16
name|serverPort
init|=
name|port
decl_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
comment|//! [5]
comment|//! [6]
while|while
condition|(
operator|!
name|quit
condition|)
block|{
comment|//! [7]
specifier|const
name|int
name|Timeout
init|=
literal|5
operator|*
literal|1000
decl_stmt|;
name|QTcpSocket
name|socket
decl_stmt|;
name|socket
operator|.
name|connectToHost
argument_list|(
name|serverName
argument_list|,
name|serverPort
argument_list|)
expr_stmt|;
comment|//! [6] //! [8]
if|if
condition|(
operator|!
name|socket
operator|.
name|waitForConnected
argument_list|(
name|Timeout
argument_list|)
condition|)
block|{
emit|emit
name|error
argument_list|(
name|socket
operator|.
name|error
argument_list|()
argument_list|,
name|socket
operator|.
name|errorString
argument_list|()
argument_list|)
emit|;
return|return;
block|}
comment|//! [8] //! [9]
while|while
condition|(
name|socket
operator|.
name|bytesAvailable
argument_list|()
operator|<
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
name|quint16
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|socket
operator|.
name|waitForReadyRead
argument_list|(
name|Timeout
argument_list|)
condition|)
block|{
emit|emit
name|error
argument_list|(
name|socket
operator|.
name|error
argument_list|()
argument_list|,
name|socket
operator|.
name|errorString
argument_list|()
argument_list|)
emit|;
return|return;
block|}
comment|//! [9] //! [10]
block|}
comment|//! [10] //! [11]
name|quint16
name|blockSize
decl_stmt|;
name|QDataStream
name|in
argument_list|(
operator|&
name|socket
argument_list|)
decl_stmt|;
name|in
operator|.
name|setVersion
argument_list|(
name|QDataStream
operator|::
name|Qt_4_0
argument_list|)
expr_stmt|;
name|in
operator|>>
name|blockSize
expr_stmt|;
comment|//! [11] //! [12]
while|while
condition|(
name|socket
operator|.
name|bytesAvailable
argument_list|()
operator|<
name|blockSize
condition|)
block|{
if|if
condition|(
operator|!
name|socket
operator|.
name|waitForReadyRead
argument_list|(
name|Timeout
argument_list|)
condition|)
block|{
emit|emit
name|error
argument_list|(
name|socket
operator|.
name|error
argument_list|()
argument_list|,
name|socket
operator|.
name|errorString
argument_list|()
argument_list|)
emit|;
return|return;
block|}
comment|//! [12] //! [13]
block|}
comment|//! [13] //! [14]
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QString
name|fortune
decl_stmt|;
name|in
operator|>>
name|fortune
expr_stmt|;
emit|emit
name|newFortune
argument_list|(
name|fortune
argument_list|)
emit|;
comment|//! [7] //! [14] //! [15]
name|cond
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
name|serverName
operator|=
name|hostName
expr_stmt|;
name|serverPort
operator|=
name|port
expr_stmt|;
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
comment|//! [15]
block|}
end_function
end_unit
