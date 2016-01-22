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
file|<QtCore/QCoreApplication>
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
if|if
condition|(
operator|!
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
operator|.
name|isConnected
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot connect to the D-Bus session bus.\n"
literal|"To start it, run:\n"
literal|"\teval `dbus-launch --auto-syntax`\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|QDBusInterface
name|iface
argument_list|(
name|SERVICE_NAME
argument_list|,
literal|"/"
argument_list|,
literal|""
argument_list|,
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|iface
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QDBusReply
argument_list|<
name|QString
argument_list|>
name|reply
init|=
name|iface
operator|.
name|call
argument_list|(
literal|"ping"
argument_list|,
name|argc
operator|>
literal|1
condition|?
name|argv
index|[
literal|1
index|]
else|:
literal|""
argument_list|)
decl_stmt|;
if|if
condition|(
name|reply
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|printf
argument_list|(
literal|"Reply was: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|reply
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Call failed: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|reply
operator|.
name|error
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
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
return|return
literal|1
return|;
block|}
end_function
end_unit
