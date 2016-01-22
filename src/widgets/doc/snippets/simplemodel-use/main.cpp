begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   main.cpp    A simple example of how to access items from an existing model. */
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_comment
comment|/*!     Create a default directory model and, using the index-based interface to     the model and some QLabel widgets, populate the window's layout with the     names of objects in the directory.      Note that we only want to read the filenames in the highest level of the     directory, so we supply a default (invalid) QModelIndex to the model in     order to indicate that we want top-level items. */
end_comment
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
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|window
init|=
operator|new
name|QWidget
decl_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|title
init|=
operator|new
name|QLabel
argument_list|(
literal|"Some items from the directory model"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|title
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
expr_stmt|;
name|title
operator|->
name|setMargin
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|title
argument_list|)
expr_stmt|;
comment|//! [0]
name|QFileSystemModel
modifier|*
name|model
init|=
operator|new
name|QFileSystemModel
decl_stmt|;
name|QModelIndex
name|parentIndex
init|=
name|model
operator|->
name|index
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|numRows
init|=
name|model
operator|->
name|rowCount
argument_list|(
name|parentIndex
argument_list|)
decl_stmt|;
comment|//! [0]
comment|//! [1]
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|numRows
condition|;
operator|++
name|row
control|)
block|{
name|QModelIndex
name|index
init|=
name|model
operator|->
name|index
argument_list|(
name|row
argument_list|,
literal|0
argument_list|,
name|parentIndex
argument_list|)
decl_stmt|;
comment|//! [1]
comment|//! [2]
name|QString
name|text
init|=
name|model
operator|->
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
comment|// Display the text in a widget.
comment|//! [2]
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|text
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
comment|//! [3]
block|}
comment|//! [3]
name|window
operator|->
name|setWindowTitle
argument_list|(
literal|"A simple model example"
argument_list|)
expr_stmt|;
name|window
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
