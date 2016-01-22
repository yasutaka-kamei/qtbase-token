begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|QMenu
modifier|*
name|fileMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|quitAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|)
decl_stmt|;
name|quitAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|itemsMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Items"
argument_list|)
argument_list|)
decl_stmt|;
name|insertAction
operator|=
name|itemsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Insert Item"
argument_list|)
argument_list|)
expr_stmt|;
name|removeAction
operator|=
name|itemsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Remove Item"
argument_list|)
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|ascendingAction
init|=
name|itemsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Sort in&Ascending Order"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|descendingAction
init|=
name|itemsMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Sort in&Descending Order"
argument_list|)
argument_list|)
decl_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|itemsMenu
argument_list|)
expr_stmt|;
comment|/*  For convenient quoting: //! [0]     QListWidget *listWidget = new QListWidget(this); //! [0] */
name|listWidget
operator|=
operator|new
name|QListWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|listWidget
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|SingleSelection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ascendingAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sortAscending
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|descendingAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sortDescending
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|insertAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|insertItem
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|removeAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|removeItem
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|listWidget
argument_list|,
name|SIGNAL
argument_list|(
name|currentItemChanged
argument_list|(
name|QListWidgetItem
operator|*
argument_list|,
name|QListWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateMenus
argument_list|(
name|QListWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|setupListItems
argument_list|()
expr_stmt|;
name|updateMenus
argument_list|(
name|listWidget
operator|->
name|currentItem
argument_list|()
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|listWidget
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"List Widget"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setupListItems
name|void
name|MainWindow
operator|::
name|setupListItems
parameter_list|()
block|{
comment|//! [1]
operator|new
name|QListWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"Oak"
argument_list|)
argument_list|,
name|listWidget
argument_list|)
expr_stmt|;
operator|new
name|QListWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"Fir"
argument_list|)
argument_list|,
name|listWidget
argument_list|)
expr_stmt|;
operator|new
name|QListWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"Pine"
argument_list|)
argument_list|,
name|listWidget
argument_list|)
expr_stmt|;
comment|//! [1]
operator|new
name|QListWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"Birch"
argument_list|)
argument_list|,
name|listWidget
argument_list|)
expr_stmt|;
comment|//! [2]
operator|new
name|QListWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"Hazel"
argument_list|)
argument_list|,
name|listWidget
argument_list|)
expr_stmt|;
comment|//! [2]
operator|new
name|QListWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"Redwood"
argument_list|)
argument_list|,
name|listWidget
argument_list|)
expr_stmt|;
comment|//! [3]
operator|new
name|QListWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"Sycamore"
argument_list|)
argument_list|,
name|listWidget
argument_list|)
expr_stmt|;
operator|new
name|QListWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"Chestnut"
argument_list|)
argument_list|,
name|listWidget
argument_list|)
expr_stmt|;
operator|new
name|QListWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"Mahogany"
argument_list|)
argument_list|,
name|listWidget
argument_list|)
expr_stmt|;
comment|//! [3]
block|}
end_function
begin_function
DECL|function|sortAscending
name|void
name|MainWindow
operator|::
name|sortAscending
parameter_list|()
block|{
comment|//! [4]
name|listWidget
operator|->
name|sortItems
argument_list|(
name|Qt
operator|::
name|AscendingOrder
argument_list|)
expr_stmt|;
comment|//! [4]
block|}
end_function
begin_function
DECL|function|sortDescending
name|void
name|MainWindow
operator|::
name|sortDescending
parameter_list|()
block|{
comment|//! [5]
name|listWidget
operator|->
name|sortItems
argument_list|(
name|Qt
operator|::
name|DescendingOrder
argument_list|)
expr_stmt|;
comment|//! [5]
block|}
end_function
begin_function
DECL|function|insertItem
name|void
name|MainWindow
operator|::
name|insertItem
parameter_list|()
block|{
if|if
condition|(
operator|!
name|listWidget
operator|->
name|currentItem
argument_list|()
condition|)
return|return;
name|QString
name|itemText
init|=
name|QInputDialog
operator|::
name|getText
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Insert Item"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Input text for the new item:"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|itemText
operator|.
name|isNull
argument_list|()
condition|)
return|return;
comment|//! [6]
name|QListWidgetItem
modifier|*
name|newItem
init|=
operator|new
name|QListWidgetItem
decl_stmt|;
name|newItem
operator|->
name|setText
argument_list|(
name|itemText
argument_list|)
expr_stmt|;
comment|//! [6]
name|int
name|row
init|=
name|listWidget
operator|->
name|row
argument_list|(
name|listWidget
operator|->
name|currentItem
argument_list|()
argument_list|)
decl_stmt|;
comment|//! [7]
name|listWidget
operator|->
name|insertItem
argument_list|(
name|row
argument_list|,
name|newItem
argument_list|)
expr_stmt|;
comment|//! [7]
name|QString
name|toolTipText
init|=
name|tr
argument_list|(
literal|"Tooltip:"
argument_list|)
operator|+
name|itemText
decl_stmt|;
name|QString
name|statusTipText
init|=
name|tr
argument_list|(
literal|"Status tip:"
argument_list|)
operator|+
name|itemText
decl_stmt|;
name|QString
name|whatsThisText
init|=
name|tr
argument_list|(
literal|"What's This?:"
argument_list|)
operator|+
name|itemText
decl_stmt|;
comment|//! [8]
name|newItem
operator|->
name|setToolTip
argument_list|(
name|toolTipText
argument_list|)
expr_stmt|;
name|newItem
operator|->
name|setStatusTip
argument_list|(
name|toolTipText
argument_list|)
expr_stmt|;
name|newItem
operator|->
name|setWhatsThis
argument_list|(
name|whatsThisText
argument_list|)
expr_stmt|;
comment|//! [8]
block|}
end_function
begin_function
DECL|function|removeItem
name|void
name|MainWindow
operator|::
name|removeItem
parameter_list|()
block|{
name|listWidget
operator|->
name|takeItem
argument_list|(
name|listWidget
operator|->
name|row
argument_list|(
name|listWidget
operator|->
name|currentItem
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateMenus
name|void
name|MainWindow
operator|::
name|updateMenus
parameter_list|(
name|QListWidgetItem
modifier|*
name|current
parameter_list|)
block|{
name|insertAction
operator|->
name|setEnabled
argument_list|(
name|current
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|removeAction
operator|->
name|setEnabled
argument_list|(
name|current
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
