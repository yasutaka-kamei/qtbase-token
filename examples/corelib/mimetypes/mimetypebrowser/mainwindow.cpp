begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"mimetypemodel.h"
end_include
begin_include
include|#
directive|include
file|<QAction>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QFileDialog>
end_include
begin_include
include|#
directive|include
file|<QInputDialog>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QMessageBox>
end_include
begin_include
include|#
directive|include
file|<QPlainTextEdit>
end_include
begin_include
include|#
directive|include
file|<QSplitter>
end_include
begin_include
include|#
directive|include
file|<QStatusBar>
end_include
begin_include
include|#
directive|include
file|<QTextEdit>
end_include
begin_include
include|#
directive|include
file|<QTreeView>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QItemSelectionModel>
end_include
begin_include
include|#
directive|include
file|<QMimeDatabase>
end_include
begin_include
include|#
directive|include
file|<QMimeType>
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
member_init_list|,
name|m_model
argument_list|(
operator|new
name|MimetypeModel
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|m_treeView
argument_list|(
operator|new
name|QTreeView
argument_list|)
member_init_list|,
name|m_detailsText
argument_list|(
operator|new
name|QTextEdit
argument_list|)
member_init_list|,
name|m_findIndex
argument_list|(
literal|0
argument_list|)
block|{
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Qt Mime Database Browser"
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
name|QAction
modifier|*
name|detectFileAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Detect File Type..."
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|detectFile
argument_list|)
decl_stmt|;
name|detectFileAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|exitAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|qApp
argument_list|,
operator|&
name|QApplication
operator|::
name|closeAllWindows
argument_list|)
decl_stmt|;
name|exitAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|findMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Edit"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|findAction
init|=
name|findMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Find..."
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|find
argument_list|)
decl_stmt|;
name|findAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Find
argument_list|)
expr_stmt|;
name|m_findNextAction
operator|=
name|findMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Find&Next"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|findNext
argument_list|)
expr_stmt|;
name|m_findNextAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|FindNext
argument_list|)
expr_stmt|;
name|m_findPreviousAction
operator|=
name|findMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Find&Previous"
argument_list|)
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|findPrevious
argument_list|)
expr_stmt|;
name|m_findPreviousAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|FindPrevious
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&About"
argument_list|)
argument_list|)
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&About Qt"
argument_list|)
argument_list|,
name|qApp
argument_list|,
operator|&
name|QApplication
operator|::
name|aboutQt
argument_list|)
expr_stmt|;
name|QSplitter
modifier|*
name|centralSplitter
init|=
operator|new
name|QSplitter
decl_stmt|;
name|setCentralWidget
argument_list|(
name|centralSplitter
argument_list|)
expr_stmt|;
name|m_treeView
operator|=
operator|new
name|QTreeView
expr_stmt|;
name|m_treeView
operator|->
name|setUniformRowHeights
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_treeView
operator|->
name|setModel
argument_list|(
name|m_model
argument_list|)
expr_stmt|;
specifier|const
specifier|auto
name|items
init|=
name|m_model
operator|->
name|findItems
argument_list|(
literal|"application/octet-stream"
argument_list|,
name|Qt
operator|::
name|MatchContains
operator||
name|Qt
operator|::
name|MatchFixedString
operator||
name|Qt
operator|::
name|MatchRecursive
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|items
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_treeView
operator|->
name|expand
argument_list|(
name|m_model
operator|->
name|indexFromItem
argument_list|(
name|items
operator|.
name|constFirst
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_treeView
operator|->
name|selectionModel
argument_list|()
argument_list|,
operator|&
name|QItemSelectionModel
operator|::
name|currentChanged
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|currentChanged
argument_list|)
expr_stmt|;
name|centralSplitter
operator|->
name|addWidget
argument_list|(
name|m_treeView
argument_list|)
expr_stmt|;
name|m_detailsText
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|centralSplitter
operator|->
name|addWidget
argument_list|(
name|m_detailsText
argument_list|)
expr_stmt|;
name|updateFindActions
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|currentChanged
name|void
name|MainWindow
operator|::
name|currentChanged
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
if|if
condition|(
name|index
operator|.
name|isValid
argument_list|()
condition|)
name|m_detailsText
operator|->
name|setText
argument_list|(
name|MimetypeModel
operator|::
name|formatMimeTypeInfo
argument_list|(
name|m_model
operator|->
name|mimeType
argument_list|(
name|index
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|m_detailsText
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectAndGoTo
name|void
name|MainWindow
operator|::
name|selectAndGoTo
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
name|m_treeView
operator|->
name|scrollTo
argument_list|(
name|index
argument_list|,
name|QAbstractItemView
operator|::
name|PositionAtCenter
argument_list|)
expr_stmt|;
name|m_treeView
operator|->
name|setCurrentIndex
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|detectFile
name|void
name|MainWindow
operator|::
name|detectFile
parameter_list|()
block|{
specifier|const
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Choose File"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QMimeDatabase
name|mimeDatabase
decl_stmt|;
specifier|const
name|QFileInfo
name|fi
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
specifier|const
name|QMimeType
name|mimeType
init|=
name|mimeDatabase
operator|.
name|mimeTypeForFile
argument_list|(
name|fi
argument_list|)
decl_stmt|;
specifier|const
name|QModelIndex
name|index
init|=
name|mimeType
operator|.
name|isValid
argument_list|()
condition|?
name|m_model
operator|->
name|indexForMimeType
argument_list|(
name|mimeType
operator|.
name|name
argument_list|()
argument_list|)
else|:
name|QModelIndex
argument_list|()
decl_stmt|;
if|if
condition|(
name|index
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"\"%1\" is of type \"%2\""
argument_list|)
operator|.
name|arg
argument_list|(
name|fi
operator|.
name|fileName
argument_list|()
argument_list|,
name|mimeType
operator|.
name|name
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|selectAndGoTo
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Unknown File Type"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The type of %1 could not be determined."
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fileName
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|updateFindActions
name|void
name|MainWindow
operator|::
name|updateFindActions
parameter_list|()
block|{
specifier|const
name|bool
name|findNextPreviousEnabled
init|=
name|m_findMatches
operator|.
name|size
argument_list|()
operator|>
literal|1
decl_stmt|;
name|m_findNextAction
operator|->
name|setEnabled
argument_list|(
name|findNextPreviousEnabled
argument_list|)
expr_stmt|;
name|m_findPreviousAction
operator|->
name|setEnabled
argument_list|(
name|findNextPreviousEnabled
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|findPrevious
name|void
name|MainWindow
operator|::
name|findPrevious
parameter_list|()
block|{
if|if
condition|(
operator|--
name|m_findIndex
operator|<
literal|0
condition|)
name|m_findIndex
operator|=
name|m_findMatches
operator|.
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|m_findIndex
operator|>=
literal|0
condition|)
name|selectAndGoTo
argument_list|(
name|m_findMatches
operator|.
name|at
argument_list|(
name|m_findIndex
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|findNext
name|void
name|MainWindow
operator|::
name|findNext
parameter_list|()
block|{
if|if
condition|(
operator|++
name|m_findIndex
operator|>=
name|m_findMatches
operator|.
name|size
argument_list|()
condition|)
name|m_findIndex
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|m_findIndex
operator|<
name|m_findMatches
operator|.
name|size
argument_list|()
condition|)
name|selectAndGoTo
argument_list|(
name|m_findMatches
operator|.
name|at
argument_list|(
name|m_findIndex
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|find
name|void
name|MainWindow
operator|::
name|find
parameter_list|()
block|{
name|QInputDialog
name|inputDialog
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|inputDialog
operator|.
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Find"
argument_list|)
argument_list|)
expr_stmt|;
name|inputDialog
operator|.
name|setLabelText
argument_list|(
name|tr
argument_list|(
literal|"Text:"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|inputDialog
operator|.
name|exec
argument_list|()
operator|!=
name|QDialog
operator|::
name|Accepted
condition|)
return|return;
specifier|const
name|QString
name|value
init|=
name|inputDialog
operator|.
name|textValue
argument_list|()
operator|.
name|trimmed
argument_list|()
decl_stmt|;
if|if
condition|(
name|value
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|m_findMatches
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_findIndex
operator|=
literal|0
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QStandardItem
modifier|*
name|item
decl|,
name|m_model
operator|->
name|findItems
argument_list|(
name|value
argument_list|,
name|Qt
operator|::
name|MatchContains
operator||
name|Qt
operator|::
name|MatchFixedString
operator||
name|Qt
operator|::
name|MatchRecursive
argument_list|)
control|)
name|m_findMatches
operator|.
name|append
argument_list|(
name|m_model
operator|->
name|indexFromItem
argument_list|(
name|item
argument_list|)
argument_list|)
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"%n mime types match \"%1\"."
argument_list|,
literal|0
argument_list|,
name|m_findMatches
operator|.
name|size
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
name|updateFindActions
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_findMatches
operator|.
name|isEmpty
argument_list|()
condition|)
name|selectAndGoTo
argument_list|(
name|m_findMatches
operator|.
name|constFirst
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit