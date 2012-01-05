begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|receive
name|void
name|MyClass
operator|::
name|receive
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|QDataStream
name|in
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
name|message
operator|==
literal|"execute(QString,QString)"
condition|)
block|{
name|QString
name|cmd
decl_stmt|;
name|QString
name|arg
decl_stmt|;
name|in
operator|>>
name|cmd
operator|>>
name|arg
expr_stmt|;
operator|...
block|}
elseif|else
if|if
condition|(
name|message
operator|==
literal|"delete(QString)"
condition|)
block|{
name|QString
name|fileName
decl_stmt|;
name|in
operator|>>
name|fileName
expr_stmt|;
operator|...
block|}
else|else
block|{
operator|...
block|}
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|data
name|QByteArray
name|data
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|out
name|QDataStream
name|out
argument_list|(
operator|&
name|data
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|out
operator|<<
name|QString
argument_list|(
literal|"cat"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"file.txt"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QCopChannel
operator|::
name|send
argument_list|(
literal|"System/Shell"
argument_list|,
literal|"execute(QString,QString)"
argument_list|,
name|data
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
end_unit
