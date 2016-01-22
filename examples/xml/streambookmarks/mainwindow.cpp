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
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"xbelreader.h"
end_include
begin_include
include|#
directive|include
file|"xbelwriter.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|QStringList
name|labels
decl_stmt|;
name|labels
operator|<<
name|tr
argument_list|(
literal|"Title"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Location"
argument_list|)
expr_stmt|;
name|treeWidget
operator|=
operator|new
name|QTreeWidget
expr_stmt|;
name|treeWidget
operator|->
name|header
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
name|QHeaderView
operator|::
name|Stretch
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setHeaderLabels
argument_list|(
name|labels
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|treeWidget
argument_list|)
expr_stmt|;
name|createActions
argument_list|()
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Ready"
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"QXmlStream Bookmarks"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|480
argument_list|,
literal|320
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|open
name|void
name|MainWindow
operator|::
name|open
parameter_list|()
block|{
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
literal|"Open Bookmark File"
argument_list|)
argument_list|,
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"XBEL Files (*.xbel *.xml)"
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
name|treeWidget
operator|->
name|clear
argument_list|()
expr_stmt|;
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
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QXmlStream Bookmarks"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot read file %1:\n%2."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|XbelReader
name|reader
argument_list|(
name|treeWidget
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reader
operator|.
name|read
argument_list|(
operator|&
name|file
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QXmlStream Bookmarks"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Parse error in file %1:\n\n%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|reader
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"File loaded"
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|saveAs
name|void
name|MainWindow
operator|::
name|saveAs
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Save Bookmark File"
argument_list|)
argument_list|,
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"XBEL Files (*.xbel *.xml)"
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
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"QXmlStream Bookmarks"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cannot write file %1:\n%2."
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|XbelWriter
name|writer
argument_list|(
name|treeWidget
argument_list|)
decl_stmt|;
if|if
condition|(
name|writer
operator|.
name|writeFile
argument_list|(
operator|&
name|file
argument_list|)
condition|)
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"File saved"
argument_list|)
argument_list|,
literal|2000
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
literal|"About QXmlStream Bookmarks"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The<b>QXmlStream Bookmarks</b> example demonstrates how to use Qt's "
literal|"QXmlStream classes to read and write XML documents."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|createActions
name|void
name|MainWindow
operator|::
name|createActions
parameter_list|()
block|{
name|openAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|openAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openAct
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
name|open
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|saveAsAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Save As..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|saveAsAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|SaveAs
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAsAct
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
name|saveAs
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|exitAct
operator|=
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
expr_stmt|;
name|exitAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|aboutAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&About"
argument_list|)
argument_list|,
name|this
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
name|aboutQtAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About&Qt"
argument_list|)
argument_list|,
name|this
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
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|createMenus
name|void
name|MainWindow
operator|::
name|createMenus
parameter_list|()
block|{
name|fileMenu
operator|=
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
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAsAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAct
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|helpMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Help"
argument_list|)
argument_list|)
expr_stmt|;
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
comment|//! [5]
end_comment
end_unit
