begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QStandardItemModel>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|"freezetablewidget.h"
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
name|Q_INIT_RESOURCE
argument_list|(
name|grades
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QStandardItemModel
modifier|*
name|model
init|=
operator|new
name|QStandardItemModel
argument_list|()
decl_stmt|;
name|QFile
name|file
argument_list|(
literal|":/grades.txt"
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|QString
name|line
init|=
name|file
operator|.
name|readLine
argument_list|(
literal|200
argument_list|)
decl_stmt|;
name|QStringList
name|list
init|=
name|line
operator|.
name|simplified
argument_list|()
operator|.
name|split
argument_list|(
literal|','
argument_list|)
decl_stmt|;
name|model
operator|->
name|setHorizontalHeaderLabels
argument_list|(
name|list
argument_list|)
expr_stmt|;
name|int
name|row
init|=
literal|0
decl_stmt|;
name|QStandardItem
modifier|*
name|newItem
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|file
operator|.
name|canReadLine
argument_list|()
condition|)
block|{
name|line
operator|=
name|file
operator|.
name|readLine
argument_list|(
literal|200
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|line
operator|.
name|startsWith
argument_list|(
literal|'#'
argument_list|)
operator|&&
name|line
operator|.
name|contains
argument_list|(
literal|','
argument_list|)
condition|)
block|{
name|list
operator|=
name|line
operator|.
name|simplified
argument_list|()
operator|.
name|split
argument_list|(
literal|','
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|col
init|=
literal|0
init|;
name|col
operator|<
name|list
operator|.
name|length
argument_list|()
condition|;
operator|++
name|col
control|)
block|{
name|newItem
operator|=
operator|new
name|QStandardItem
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|col
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
name|col
argument_list|,
name|newItem
argument_list|)
expr_stmt|;
block|}
operator|++
name|row
expr_stmt|;
block|}
block|}
block|}
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
name|FreezeTableWidget
modifier|*
name|tableView
init|=
operator|new
name|FreezeTableWidget
argument_list|(
name|model
argument_list|)
decl_stmt|;
name|tableView
operator|->
name|setWindowTitle
argument_list|(
name|QObject
operator|::
name|tr
argument_list|(
literal|"Frozen Column Example"
argument_list|)
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|resize
argument_list|(
literal|560
argument_list|,
literal|680
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|show
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
