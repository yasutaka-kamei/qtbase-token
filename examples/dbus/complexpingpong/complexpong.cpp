begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTimer>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|"ping-common.h"
end_include
begin_include
include|#
directive|include
file|"complexpong.h"
end_include
begin_comment
comment|// the property
end_comment
begin_function
DECL|function|value
name|QString
name|Pong
operator|::
name|value
parameter_list|()
specifier|const
block|{
return|return
name|m_value
return|;
block|}
end_function
begin_function
DECL|function|setValue
name|void
name|Pong
operator|::
name|setValue
parameter_list|(
specifier|const
name|QString
modifier|&
name|newValue
parameter_list|)
block|{
name|m_value
operator|=
name|newValue
expr_stmt|;
block|}
end_function
begin_function
DECL|function|quit
name|void
name|Pong
operator|::
name|quit
parameter_list|()
block|{
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|QCoreApplication
operator|::
name|instance
argument_list|()
argument_list|,
operator|&
name|QCoreApplication
operator|::
name|quit
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|query
name|QDBusVariant
name|Pong
operator|::
name|query
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
parameter_list|)
block|{
name|QString
name|q
init|=
name|query
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|q
operator|==
literal|"hello"
condition|)
return|return
name|QDBusVariant
argument_list|(
literal|"World"
argument_list|)
return|;
if|if
condition|(
name|q
operator|==
literal|"ping"
condition|)
return|return
name|QDBusVariant
argument_list|(
literal|"Pong"
argument_list|)
return|;
if|if
condition|(
name|q
operator|.
name|indexOf
argument_list|(
literal|"the answer to life, the universe and everything"
argument_list|)
operator|!=
operator|-
literal|1
condition|)
return|return
name|QDBusVariant
argument_list|(
literal|42
argument_list|)
return|;
if|if
condition|(
name|q
operator|.
name|indexOf
argument_list|(
literal|"unladen swallow"
argument_list|)
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|q
operator|.
name|indexOf
argument_list|(
literal|"european"
argument_list|)
operator|!=
operator|-
literal|1
condition|)
return|return
name|QDBusVariant
argument_list|(
literal|11.0
argument_list|)
return|;
return|return
name|QDBusVariant
argument_list|(
name|QByteArray
argument_list|(
literal|"african or european?"
argument_list|)
argument_list|)
return|;
block|}
return|return
name|QDBusVariant
argument_list|(
literal|"Sorry, I don't know the answer"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QObject
name|obj
decl_stmt|;
name|Pong
modifier|*
name|pong
init|=
operator|new
name|Pong
argument_list|(
operator|&
name|obj
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|app
argument_list|,
operator|&
name|QCoreApplication
operator|::
name|aboutToQuit
argument_list|,
name|pong
argument_list|,
operator|&
name|Pong
operator|::
name|aboutToQuit
argument_list|)
expr_stmt|;
name|pong
operator|->
name|setProperty
argument_list|(
literal|"value"
argument_list|,
literal|"initial value"
argument_list|)
expr_stmt|;
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
operator|.
name|registerObject
argument_list|(
literal|"/"
argument_list|,
operator|&
name|obj
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
operator|.
name|registerService
argument_list|(
name|SERVICE_NAME
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
operator|.
name|lastError
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
