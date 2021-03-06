begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"fsmodel.h"
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_comment
comment|//! [0]
end_comment
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
name|completer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|lineEdit
argument_list|(
literal|0
argument_list|)
block|{
name|createMenu
argument_list|()
expr_stmt|;
name|QWidget
modifier|*
name|centralWidget
init|=
operator|new
name|QWidget
decl_stmt|;
name|QLabel
modifier|*
name|modelLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|modelLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Model"
argument_list|)
argument_list|)
expr_stmt|;
name|modelCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|modelCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"QFileSytemModel"
argument_list|)
argument_list|)
expr_stmt|;
name|modelCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"QFileSytemModel that shows full path"
argument_list|)
argument_list|)
expr_stmt|;
name|modelCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Country list"
argument_list|)
argument_list|)
expr_stmt|;
name|modelCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Word list"
argument_list|)
argument_list|)
expr_stmt|;
name|modelCombo
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|modeLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|modeLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Completion Mode"
argument_list|)
argument_list|)
expr_stmt|;
name|modeCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|modeCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Inline"
argument_list|)
argument_list|)
expr_stmt|;
name|modeCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Filtered Popup"
argument_list|)
argument_list|)
expr_stmt|;
name|modeCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Unfiltered Popup"
argument_list|)
argument_list|)
expr_stmt|;
name|modeCombo
operator|->
name|setCurrentIndex
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|caseLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|caseLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Case Sensitivity"
argument_list|)
argument_list|)
expr_stmt|;
name|caseCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|caseCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Case Insensitive"
argument_list|)
argument_list|)
expr_stmt|;
name|caseCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Case Sensitive"
argument_list|)
argument_list|)
expr_stmt|;
name|caseCombo
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QLabel
modifier|*
name|maxVisibleLabel
init|=
operator|new
name|QLabel
decl_stmt|;
name|maxVisibleLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Max Visible Items"
argument_list|)
argument_list|)
expr_stmt|;
name|maxVisibleSpinBox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
name|maxVisibleSpinBox
operator|->
name|setRange
argument_list|(
literal|3
argument_list|,
literal|25
argument_list|)
expr_stmt|;
name|maxVisibleSpinBox
operator|->
name|setValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|wrapCheckBox
operator|=
operator|new
name|QCheckBox
expr_stmt|;
name|wrapCheckBox
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Wrap around completions"
argument_list|)
argument_list|)
expr_stmt|;
name|wrapCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|contentsLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|contentsLabel
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|modelCombo
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeModel
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|modeCombo
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeMode
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|caseCombo
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeCase
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|maxVisibleSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changeMaxVisible
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|lineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|modelLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|modelCombo
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|modeLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|modeCombo
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|caseLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|caseCombo
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|maxVisibleLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|maxVisibleSpinBox
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|wrapCheckBox
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|contentsLabel
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|,
literal|6
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|centralWidget
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
name|changeModel
argument_list|()
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Completer"
argument_list|)
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|createMenu
name|void
name|MainWindow
operator|::
name|createMenu
parameter_list|()
block|{
name|QAction
modifier|*
name|exitAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Exit"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|aboutAct
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|aboutQtAct
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About Qt"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|exitAction
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
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutAct
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
name|about
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutQtAct
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
name|aboutQt
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
literal|"File"
argument_list|)
argument_list|)
decl_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAction
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|helpMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"About"
argument_list|)
argument_list|)
decl_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutAct
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutQtAct
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|modelFromFile
name|QAbstractItemModel
modifier|*
name|MainWindow
operator|::
name|modelFromFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return
operator|new
name|QStringListModel
argument_list|(
name|completer
argument_list|)
return|;
comment|//! [5]
comment|//! [6]
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|setOverrideCursor
argument_list|(
name|QCursor
argument_list|(
name|Qt
operator|::
name|WaitCursor
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QStringList
name|words
decl_stmt|;
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
if|if
condition|(
operator|!
name|line
operator|.
name|isEmpty
argument_list|()
condition|)
name|words
operator|<<
name|line
operator|.
name|trimmed
argument_list|()
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QApplication
operator|::
name|restoreOverrideCursor
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|//! [6]
comment|//! [7]
if|if
condition|(
operator|!
name|fileName
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"countries.txt"
argument_list|)
argument_list|)
condition|)
return|return
operator|new
name|QStringListModel
argument_list|(
name|words
argument_list|,
name|completer
argument_list|)
return|;
comment|//! [7]
comment|// The last two chars of the countries.txt file indicate the country
comment|// symbol. We put that in column 2 of a standard item model
comment|//! [8]
name|QStandardItemModel
modifier|*
name|m
init|=
operator|new
name|QStandardItemModel
argument_list|(
name|words
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|,
name|completer
argument_list|)
decl_stmt|;
comment|//! [8] //! [9]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|words
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QModelIndex
name|countryIdx
init|=
name|m
operator|->
name|index
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QModelIndex
name|symbolIdx
init|=
name|m
operator|->
name|index
argument_list|(
name|i
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|QString
name|country
init|=
name|words
index|[
name|i
index|]
operator|.
name|mid
argument_list|(
literal|0
argument_list|,
name|words
index|[
name|i
index|]
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
operator|.
name|trimmed
argument_list|()
decl_stmt|;
name|QString
name|symbol
init|=
name|words
index|[
name|i
index|]
operator|.
name|right
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|m
operator|->
name|setData
argument_list|(
name|countryIdx
argument_list|,
name|country
argument_list|)
expr_stmt|;
name|m
operator|->
name|setData
argument_list|(
name|symbolIdx
argument_list|,
name|symbol
argument_list|)
expr_stmt|;
block|}
return|return
name|m
return|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|changeMode
name|void
name|MainWindow
operator|::
name|changeMode
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|QCompleter
operator|::
name|CompletionMode
name|mode
decl_stmt|;
if|if
condition|(
name|index
operator|==
literal|0
condition|)
name|mode
operator|=
name|QCompleter
operator|::
name|InlineCompletion
expr_stmt|;
elseif|else
if|if
condition|(
name|index
operator|==
literal|1
condition|)
name|mode
operator|=
name|QCompleter
operator|::
name|PopupCompletion
expr_stmt|;
else|else
name|mode
operator|=
name|QCompleter
operator|::
name|UnfilteredPopupCompletion
expr_stmt|;
name|completer
operator|->
name|setCompletionMode
argument_list|(
name|mode
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|changeCase
name|void
name|MainWindow
operator|::
name|changeCase
parameter_list|(
name|int
name|cs
parameter_list|)
block|{
name|completer
operator|->
name|setCaseSensitivity
argument_list|(
name|cs
condition|?
name|Qt
operator|::
name|CaseSensitive
else|:
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|changeModel
name|void
name|MainWindow
operator|::
name|changeModel
parameter_list|()
block|{
operator|delete
name|completer
expr_stmt|;
name|completer
operator|=
operator|new
name|QCompleter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|completer
operator|->
name|setMaxVisibleItems
argument_list|(
name|maxVisibleSpinBox
operator|->
name|value
argument_list|()
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|modelCombo
operator|->
name|currentIndex
argument_list|()
condition|)
block|{
default|default:
case|case
literal|0
case|:
block|{
comment|// Unsorted QFileSystemModel
name|QFileSystemModel
modifier|*
name|fsModel
init|=
operator|new
name|QFileSystemModel
argument_list|(
name|completer
argument_list|)
decl_stmt|;
name|fsModel
operator|->
name|setRootPath
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|completer
operator|->
name|setModel
argument_list|(
name|fsModel
argument_list|)
expr_stmt|;
name|contentsLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Enter file path"
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
comment|//! [11] //! [12]
case|case
literal|1
case|:
block|{
comment|// FileSystemModel that shows full paths
name|FileSystemModel
modifier|*
name|fsModel
init|=
operator|new
name|FileSystemModel
argument_list|(
name|completer
argument_list|)
decl_stmt|;
name|completer
operator|->
name|setModel
argument_list|(
name|fsModel
argument_list|)
expr_stmt|;
name|fsModel
operator|->
name|setRootPath
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|contentsLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Enter file path"
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
comment|//! [12] //! [13]
case|case
literal|2
case|:
block|{
comment|// Country List
name|completer
operator|->
name|setModel
argument_list|(
name|modelFromFile
argument_list|(
literal|":/resources/countries.txt"
argument_list|)
argument_list|)
expr_stmt|;
name|QTreeView
modifier|*
name|treeView
init|=
operator|new
name|QTreeView
decl_stmt|;
name|completer
operator|->
name|setPopup
argument_list|(
name|treeView
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|setRootIsDecorated
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|header
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|treeView
operator|->
name|header
argument_list|()
operator|->
name|setStretchLastSection
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|header
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
literal|0
argument_list|,
name|QHeaderView
operator|::
name|Stretch
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|header
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
literal|1
argument_list|,
name|QHeaderView
operator|::
name|ResizeToContents
argument_list|)
expr_stmt|;
name|contentsLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Enter name of your country"
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
comment|//! [13] //! [14]
case|case
literal|3
case|:
block|{
comment|// Word list
name|completer
operator|->
name|setModel
argument_list|(
name|modelFromFile
argument_list|(
literal|":/resources/wordlist.txt"
argument_list|)
argument_list|)
expr_stmt|;
name|completer
operator|->
name|setModelSorting
argument_list|(
name|QCompleter
operator|::
name|CaseInsensitivelySortedModel
argument_list|)
expr_stmt|;
name|contentsLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Enter a word"
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
name|changeMode
argument_list|(
name|modeCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|changeCase
argument_list|(
name|caseCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|completer
operator|->
name|setWrapAround
argument_list|(
name|wrapCheckBox
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setCompleter
argument_list|(
name|completer
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|wrapCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|completer
argument_list|,
name|SLOT
argument_list|(
name|setWrapAround
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|changeMaxVisible
name|void
name|MainWindow
operator|::
name|changeMaxVisible
parameter_list|(
name|int
name|max
parameter_list|)
block|{
name|completer
operator|->
name|setMaxVisibleItems
argument_list|(
name|max
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_function
DECL|function|about
name|void
name|MainWindow
operator|::
name|about
parameter_list|()
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"This example demonstrates the "
literal|"different features of the QCompleter class."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [16]
end_comment
end_unit
