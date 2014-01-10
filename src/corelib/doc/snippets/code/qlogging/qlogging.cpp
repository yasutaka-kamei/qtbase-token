begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_include
include|#
directive|include
file|<QDeclarativeComponent>
end_include
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|statusChanged
name|void
name|statusChanged
parameter_list|(
name|QDeclarativeComponent
operator|::
name|Status
name|status
parameter_list|)
block|{
if|if
condition|(
name|status
operator|==
name|QDeclarativeComponent
operator|::
name|Error
condition|)
block|{
foreach|foreach
control|(
specifier|const
name|QDeclarativeError
modifier|&
name|error
decl|,
name|component
operator|->
name|errors
argument_list|()
control|)
block|{
specifier|const
name|QByteArray
name|file
init|=
name|error
operator|.
name|url
argument_list|()
operator|.
name|toEncoded
argument_list|()
decl_stmt|;
name|QMessageLogger
argument_list|(
name|file
operator|.
name|constData
argument_list|()
argument_list|,
name|error
operator|.
name|line
argument_list|()
argument_list|,
literal|0
argument_list|)
operator|.
name|debug
argument_list|()
operator|<<
name|error
operator|.
name|description
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function_decl
specifier|const
name|QLoggingCategory
modifier|&
name|category
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//! [2]
end_comment
end_unit
