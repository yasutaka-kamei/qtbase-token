begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QProcess>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
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
comment|//! [0]
name|QProcess
name|process
decl_stmt|;
name|process
operator|.
name|setCreateProcessArgumentsModifier
argument_list|(
capture|[]
parameter_list|(
name|QProcess
operator|::
name|CreateProcessArguments
modifier|*
name|args
parameter_list|)
block|{
name|args
operator|->
name|flags
operator||=
name|CREATE_NEW_CONSOLE
expr_stmt|;
name|args
operator|->
name|startupInfo
operator|->
name|dwFlags
operator|&=
operator|~
name|STARTF_USESTDHANDLES
expr_stmt|;
name|args
operator|->
name|startupInfo
operator|->
name|dwFlags
operator||=
name|STARTF_USEFILLATTRIBUTE
expr_stmt|;
name|args
operator|->
name|startupInfo
operator|->
name|dwFillAttribute
operator|=
name|BACKGROUND_BLUE
operator||
name|FOREGROUND_RED
operator||
name|FOREGROUND_INTENSITY
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
name|process
operator|.
name|start
argument_list|(
literal|"C:\\Windows\\System32\\cmd.exe"
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"/k"
operator|<<
literal|"title"
operator|<<
literal|"The Child Process"
argument_list|)
expr_stmt|;
comment|//! [0]
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit