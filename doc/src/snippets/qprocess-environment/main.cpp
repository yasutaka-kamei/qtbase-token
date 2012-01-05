begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_function
DECL|function|startProcess
name|void
name|startProcess
parameter_list|()
block|{
block|{
comment|//! [0]
name|QProcess
name|process
decl_stmt|;
name|QStringList
name|env
init|=
name|QProcess
operator|::
name|systemEnvironment
argument_list|()
decl_stmt|;
name|env
operator|<<
literal|"TMPDIR=C:\\MyApp\\temp"
expr_stmt|;
comment|// Add an environment variable
name|env
operator|.
name|replaceInStrings
argument_list|(
name|QRegExp
argument_list|(
literal|"^PATH=(.*)"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
argument_list|,
literal|"PATH=\\1;C:\\Bin"
argument_list|)
expr_stmt|;
name|process
operator|.
name|setEnvironment
argument_list|(
name|env
argument_list|)
expr_stmt|;
name|process
operator|.
name|start
argument_list|(
literal|"myapp"
argument_list|)
expr_stmt|;
comment|//! [0]
block|}
block|{
comment|//! [1]
name|QProcess
name|process
decl_stmt|;
name|QProcessEnvironment
name|env
init|=
name|QProcessEnvironment
operator|::
name|systemEnvironment
argument_list|()
decl_stmt|;
name|env
operator|.
name|insert
argument_list|(
literal|"TMPDIR"
argument_list|,
literal|"C:\\MyApp\\temp"
argument_list|)
expr_stmt|;
comment|// Add an environment variable
name|env
operator|.
name|insert
argument_list|(
literal|"PATH"
argument_list|,
name|env
operator|.
name|value
argument_list|(
literal|"Path"
argument_list|)
operator|+
literal|";C:\\Bin"
argument_list|)
expr_stmt|;
name|process
operator|.
name|setProcessEnvironment
argument_list|(
name|env
argument_list|)
expr_stmt|;
name|process
operator|.
name|start
argument_list|(
literal|"myapp"
argument_list|)
expr_stmt|;
comment|//! [1]
block|}
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
name|argv
index|[]
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
name|startProcess
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
