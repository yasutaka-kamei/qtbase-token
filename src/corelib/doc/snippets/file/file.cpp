begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_function
DECL|function|process_line
specifier|static
name|void
name|process_line
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|process_line
specifier|static
name|void
name|process_line
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|noStream_snippet
specifier|static
name|void
name|noStream_snippet
parameter_list|()
block|{
comment|//! [0]
name|QFile
name|file
argument_list|(
literal|"in.txt"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
condition|)
return|return;
while|while
condition|(
operator|!
name|file
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
init|=
name|file
operator|.
name|readLine
argument_list|()
decl_stmt|;
name|process_line
argument_list|(
name|line
argument_list|)
expr_stmt|;
block|}
comment|//! [0]
block|}
end_function
begin_function
DECL|function|readTextStream_snippet
specifier|static
name|void
name|readTextStream_snippet
parameter_list|()
block|{
comment|//! [1]
name|QFile
name|file
argument_list|(
literal|"in.txt"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
condition|)
return|return;
name|QTextStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|in
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|line
init|=
name|in
operator|.
name|readLine
argument_list|()
decl_stmt|;
name|process_line
argument_list|(
name|line
argument_list|)
expr_stmt|;
block|}
comment|//! [1]
block|}
end_function
begin_function
DECL|function|writeTextStream_snippet
specifier|static
name|void
name|writeTextStream_snippet
parameter_list|()
block|{
comment|//! [2]
name|QFile
name|file
argument_list|(
literal|"out.txt"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
condition|)
return|return;
name|QTextStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|out
operator|<<
literal|"The magic number is: "
operator|<<
literal|49
operator|<<
literal|"\n"
expr_stmt|;
comment|//! [2]
block|}
end_function
begin_function
DECL|function|writeTextStream_snippet
specifier|static
name|void
name|writeTextStream_snippet
parameter_list|()
block|{
name|QFile
name|file
argument_list|(
literal|"out.dat"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
return|return;
name|QDataStream
name|out
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|out
operator|<<
literal|"The magic number is: "
operator|<<
literal|49
operator|<<
literal|"\n"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readRegularEmptyFile_snippet
specifier|static
name|void
name|readRegularEmptyFile_snippet
parameter_list|()
block|{
comment|//! [3]
name|QFile
name|file
argument_list|(
literal|"/proc/modules"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
condition|)
return|return;
name|QTextStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|QString
name|line
init|=
name|in
operator|.
name|readLine
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|line
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|process_line
argument_list|(
name|line
argument_list|)
expr_stmt|;
name|line
operator|=
name|in
operator|.
name|readLine
argument_list|()
expr_stmt|;
block|}
comment|//! [3]
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|lineByLine_snippet
argument_list|()
expr_stmt|;
name|writeStream_snippet
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
