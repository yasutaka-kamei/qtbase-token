begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"model.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QListView>
end_include
begin_include
include|#
directive|include
file|<QSplitter>
end_include
begin_include
include|#
directive|include
file|<QTableView>
end_include
begin_include
include|#
directive|include
file|<QTreeView>
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
name|interview
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
name|QSplitter
name|page
decl_stmt|;
name|QAbstractItemModel
modifier|*
name|data
init|=
operator|new
name|Model
argument_list|(
literal|1000
argument_list|,
literal|10
argument_list|,
operator|&
name|page
argument_list|)
decl_stmt|;
name|QItemSelectionModel
modifier|*
name|selections
init|=
operator|new
name|QItemSelectionModel
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|QTableView
modifier|*
name|table
init|=
operator|new
name|QTableView
decl_stmt|;
name|table
operator|->
name|setModel
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|table
operator|->
name|setSelectionModel
argument_list|(
name|selections
argument_list|)
expr_stmt|;
name|table
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setSectionsMovable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|table
operator|->
name|verticalHeader
argument_list|()
operator|->
name|setSectionsMovable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|// Set StaticContents to enable minimal repaints on resizes.
name|table
operator|->
name|viewport
argument_list|()
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
expr_stmt|;
name|page
operator|.
name|addWidget
argument_list|(
name|table
argument_list|)
expr_stmt|;
name|QTreeView
modifier|*
name|tree
init|=
operator|new
name|QTreeView
decl_stmt|;
name|tree
operator|->
name|setModel
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|tree
operator|->
name|setSelectionModel
argument_list|(
name|selections
argument_list|)
expr_stmt|;
name|tree
operator|->
name|setUniformRowHeights
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|tree
operator|->
name|header
argument_list|()
operator|->
name|setStretchLastSection
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|tree
operator|->
name|viewport
argument_list|()
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
expr_stmt|;
comment|// Disable the focus rect to get minimal repaints when scrolling on Mac.
name|tree
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_MacShowFocusRect
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|page
operator|.
name|addWidget
argument_list|(
name|tree
argument_list|)
expr_stmt|;
name|QListView
modifier|*
name|list
init|=
operator|new
name|QListView
decl_stmt|;
name|list
operator|->
name|setModel
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|list
operator|->
name|setSelectionModel
argument_list|(
name|selections
argument_list|)
expr_stmt|;
name|list
operator|->
name|setViewMode
argument_list|(
name|QListView
operator|::
name|IconMode
argument_list|)
expr_stmt|;
name|list
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|ExtendedSelection
argument_list|)
expr_stmt|;
name|list
operator|->
name|setAlternatingRowColors
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|list
operator|->
name|viewport
argument_list|()
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
expr_stmt|;
name|list
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_MacShowFocusRect
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|page
operator|.
name|addWidget
argument_list|(
name|list
argument_list|)
expr_stmt|;
name|page
operator|.
name|setWindowIcon
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/interview.png"
argument_list|)
argument_list|)
expr_stmt|;
name|page
operator|.
name|setWindowTitle
argument_list|(
literal|"Interview"
argument_list|)
expr_stmt|;
name|page
operator|.
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
