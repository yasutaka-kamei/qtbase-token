begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   window.cpp    A minimal subclass of QTableView with slots to allow the selection model   to be monitored. */
end_comment
begin_include
include|#
directive|include
file|<QAbstractItemModel>
end_include
begin_include
include|#
directive|include
file|<QItemSelection>
end_include
begin_include
include|#
directive|include
file|<QItemSelectionModel>
end_include
begin_include
include|#
directive|include
file|<QStatusBar>
end_include
begin_include
include|#
directive|include
file|"model.h"
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
block|{
name|setWindowTitle
argument_list|(
literal|"Selected items in a table model"
argument_list|)
expr_stmt|;
name|model
operator|=
operator|new
name|TableModel
argument_list|(
literal|8
argument_list|,
literal|4
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|table
operator|=
operator|new
name|QTableView
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|table
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|selectionModel
operator|=
name|table
operator|->
name|selectionModel
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|selectionModel
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|(
name|QItemSelection
argument_list|,
name|QItemSelection
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateSelection
argument_list|(
name|QItemSelection
argument_list|,
name|QItemSelection
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|selectionModel
argument_list|,
name|SIGNAL
argument_list|(
name|currentChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeCurrent
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|statusBar
argument_list|()
expr_stmt|;
name|setCentralWidget
argument_list|(
name|table
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|updateSelection
name|void
name|MainWindow
operator|::
name|updateSelection
parameter_list|(
specifier|const
name|QItemSelection
modifier|&
name|selected
parameter_list|,
specifier|const
name|QItemSelection
modifier|&
name|deselected
parameter_list|)
block|{
name|QModelIndex
name|index
decl_stmt|;
name|QModelIndexList
name|items
init|=
name|selected
operator|.
name|indexes
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|index
init|,
name|items
control|)
block|{
name|QString
name|text
init|=
name|QString
argument_list|(
literal|"(%1,%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|index
operator|.
name|column
argument_list|()
argument_list|)
decl_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|text
argument_list|)
expr_stmt|;
comment|//! [0] //! [1]
block|}
comment|//! [1]
comment|//! [2]
name|items
operator|=
name|deselected
operator|.
name|indexes
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|index
init|,
name|items
control|)
name|model
operator|->
name|setData
argument_list|(
name|index
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|changeCurrent
name|void
name|MainWindow
operator|::
name|changeCurrent
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|current
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|previous
parameter_list|)
block|{
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Moved from (%1,%2) to (%3,%4)"
argument_list|)
operator|.
name|arg
argument_list|(
name|previous
operator|.
name|row
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|previous
operator|.
name|column
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|current
operator|.
name|row
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|current
operator|.
name|column
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
end_unit
