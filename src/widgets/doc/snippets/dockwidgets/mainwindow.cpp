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
literal|"Dock Widgets"
argument_list|)
expr_stmt|;
name|setupDockWindow
argument_list|()
expr_stmt|;
name|setupContents
argument_list|()
expr_stmt|;
name|setupMenus
argument_list|()
expr_stmt|;
name|textBrowser
operator|=
operator|new
name|QTextBrowser
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|headingList
argument_list|,
name|SIGNAL
argument_list|(
name|itemClicked
argument_list|(
name|QListWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateText
argument_list|(
name|QListWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|updateText
argument_list|(
name|headingList
operator|->
name|item
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|headingList
operator|->
name|setCurrentRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|textBrowser
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setupContents
name|void
name|MainWindow
operator|::
name|setupContents
parameter_list|()
block|{
name|QFile
name|titlesFile
argument_list|(
literal|":/Resources/titles.txt"
argument_list|)
decl_stmt|;
name|titlesFile
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|int
name|chapter
init|=
literal|0
decl_stmt|;
do|do
block|{
name|QString
name|line
init|=
name|titlesFile
operator|.
name|readLine
argument_list|()
operator|.
name|trimmed
argument_list|()
decl_stmt|;
name|QStringList
name|parts
init|=
name|line
operator|.
name|split
argument_list|(
literal|"\t"
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
if|if
condition|(
name|parts
operator|.
name|size
argument_list|()
operator|!=
literal|2
condition|)
break|break;
name|QString
name|chapterTitle
init|=
name|parts
index|[
literal|0
index|]
decl_stmt|;
name|QString
name|fileName
init|=
name|parts
index|[
literal|1
index|]
decl_stmt|;
name|QFile
name|chapterFile
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|chapterFile
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QListWidgetItem
modifier|*
name|item
init|=
operator|new
name|QListWidgetItem
argument_list|(
name|chapterTitle
argument_list|,
name|headingList
argument_list|)
decl_stmt|;
name|item
operator|->
name|setData
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|,
name|chapterTitle
argument_list|)
expr_stmt|;
name|item
operator|->
name|setData
argument_list|(
name|Qt
operator|::
name|UserRole
argument_list|,
name|chapterFile
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFlags
argument_list|(
name|Qt
operator|::
name|ItemIsEnabled
operator||
name|Qt
operator|::
name|ItemIsSelectable
argument_list|)
expr_stmt|;
name|chapterFile
operator|.
name|close
argument_list|()
expr_stmt|;
name|chapter
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|titlesFile
operator|.
name|isOpen
argument_list|()
condition|)
do|;
name|titlesFile
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupDockWindow
name|void
name|MainWindow
operator|::
name|setupDockWindow
parameter_list|()
block|{
comment|//! [0]
name|contentsWindow
operator|=
operator|new
name|QDockWidget
argument_list|(
name|tr
argument_list|(
literal|"Table of Contents"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|contentsWindow
operator|->
name|setAllowedAreas
argument_list|(
name|Qt
operator|::
name|LeftDockWidgetArea
operator||
name|Qt
operator|::
name|RightDockWidgetArea
argument_list|)
expr_stmt|;
name|addDockWidget
argument_list|(
name|Qt
operator|::
name|LeftDockWidgetArea
argument_list|,
name|contentsWindow
argument_list|)
expr_stmt|;
name|headingList
operator|=
operator|new
name|QListWidget
argument_list|(
name|contentsWindow
argument_list|)
expr_stmt|;
name|contentsWindow
operator|->
name|setWidget
argument_list|(
name|headingList
argument_list|)
expr_stmt|;
comment|//! [0]
block|}
end_function
begin_function
DECL|function|setupMenus
name|void
name|MainWindow
operator|::
name|setupMenus
parameter_list|()
block|{
name|QAction
modifier|*
name|exitAct
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|exitAct
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
argument_list|)
argument_list|)
expr_stmt|;
name|exitAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Exit the application"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|closeAllWindows
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|fileMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
decl_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAct
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateText
name|void
name|MainWindow
operator|::
name|updateText
parameter_list|(
name|QListWidgetItem
modifier|*
name|item
parameter_list|)
block|{
name|QString
name|text
init|=
name|item
operator|->
name|data
argument_list|(
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|textBrowser
operator|->
name|setHtml
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
