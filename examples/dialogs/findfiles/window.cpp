begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|browseButton
operator|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"&Browse..."
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|browse
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|findButton
operator|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"&Find"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|find
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|fileComboBox
operator|=
name|createComboBox
argument_list|(
name|tr
argument_list|(
literal|"*"
argument_list|)
argument_list|)
expr_stmt|;
name|textComboBox
operator|=
name|createComboBox
argument_list|()
expr_stmt|;
name|directoryComboBox
operator|=
name|createComboBox
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
expr_stmt|;
name|fileLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Named:"
argument_list|)
argument_list|)
expr_stmt|;
name|textLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Containing text:"
argument_list|)
argument_list|)
expr_stmt|;
name|directoryLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"In directory:"
argument_list|)
argument_list|)
expr_stmt|;
name|filesFoundLabel
operator|=
operator|new
name|QLabel
expr_stmt|;
name|createFilesTable
argument_list|()
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|mainLayout
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetNoConstraint
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|fileLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|fileComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|textLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|textComboBox
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|directoryLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|directoryComboBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|browseButton
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|filesTable
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|filesFoundLabel
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|findButton
argument_list|,
literal|4
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Find Files"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|700
argument_list|,
literal|300
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|browse
name|void
name|Window
operator|::
name|browse
parameter_list|()
block|{
name|QString
name|directory
init|=
name|QFileDialog
operator|::
name|getExistingDirectory
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Find Files"
argument_list|)
argument_list|,
name|QDir
operator|::
name|currentPath
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|directory
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|directoryComboBox
operator|->
name|findText
argument_list|(
name|directory
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|directoryComboBox
operator|->
name|addItem
argument_list|(
name|directory
argument_list|)
expr_stmt|;
name|directoryComboBox
operator|->
name|setCurrentIndex
argument_list|(
name|directoryComboBox
operator|->
name|findText
argument_list|(
name|directory
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|updateComboBox
specifier|static
name|void
name|updateComboBox
parameter_list|(
name|QComboBox
modifier|*
name|comboBox
parameter_list|)
block|{
if|if
condition|(
name|comboBox
operator|->
name|findText
argument_list|(
name|comboBox
operator|->
name|currentText
argument_list|()
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|comboBox
operator|->
name|addItem
argument_list|(
name|comboBox
operator|->
name|currentText
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|find
name|void
name|Window
operator|::
name|find
parameter_list|()
block|{
name|filesTable
operator|->
name|setRowCount
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QString
name|fileName
init|=
name|fileComboBox
operator|->
name|currentText
argument_list|()
decl_stmt|;
name|QString
name|text
init|=
name|textComboBox
operator|->
name|currentText
argument_list|()
decl_stmt|;
name|QString
name|path
init|=
name|directoryComboBox
operator|->
name|currentText
argument_list|()
decl_stmt|;
comment|//! [3]
name|updateComboBox
argument_list|(
name|fileComboBox
argument_list|)
expr_stmt|;
name|updateComboBox
argument_list|(
name|textComboBox
argument_list|)
expr_stmt|;
name|updateComboBox
argument_list|(
name|directoryComboBox
argument_list|)
expr_stmt|;
comment|//! [4]
name|currentDir
operator|=
name|QDir
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|QStringList
name|files
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|fileName
operator|=
literal|"*"
expr_stmt|;
name|files
operator|=
name|currentDir
operator|.
name|entryList
argument_list|(
name|QStringList
argument_list|(
name|fileName
argument_list|)
argument_list|,
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|NoSymLinks
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
name|files
operator|=
name|findFiles
argument_list|(
name|files
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|showFiles
argument_list|(
name|files
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
DECL|function|findFiles
name|QStringList
name|Window
operator|::
name|findFiles
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|files
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QProgressDialog
name|progressDialog
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|progressDialog
operator|.
name|setCancelButtonText
argument_list|(
name|tr
argument_list|(
literal|"&Cancel"
argument_list|)
argument_list|)
expr_stmt|;
name|progressDialog
operator|.
name|setRange
argument_list|(
literal|0
argument_list|,
name|files
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|progressDialog
operator|.
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Find Files"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [5] //! [6]
name|QStringList
name|foundFiles
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|files
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|progressDialog
operator|.
name|setValue
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|progressDialog
operator|.
name|setLabelText
argument_list|(
name|tr
argument_list|(
literal|"Searching file number %1 of %2..."
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
operator|.
name|arg
argument_list|(
name|files
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
comment|//! [6]
if|if
condition|(
name|progressDialog
operator|.
name|wasCanceled
argument_list|()
condition|)
break|break;
comment|//! [7]
name|QFile
name|file
argument_list|(
name|currentDir
operator|.
name|absoluteFilePath
argument_list|(
name|files
index|[
name|i
index|]
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|QString
name|line
decl_stmt|;
name|QTextStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|in
operator|.
name|atEnd
argument_list|()
condition|)
block|{
if|if
condition|(
name|progressDialog
operator|.
name|wasCanceled
argument_list|()
condition|)
break|break;
name|line
operator|=
name|in
operator|.
name|readLine
argument_list|()
expr_stmt|;
if|if
condition|(
name|line
operator|.
name|contains
argument_list|(
name|text
argument_list|)
condition|)
block|{
name|foundFiles
operator|<<
name|files
index|[
name|i
index|]
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
return|return
name|foundFiles
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|showFiles
name|void
name|Window
operator|::
name|showFiles
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|files
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|files
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QFile
name|file
argument_list|(
name|currentDir
operator|.
name|absoluteFilePath
argument_list|(
name|files
index|[
name|i
index|]
argument_list|)
argument_list|)
decl_stmt|;
name|qint64
name|size
init|=
name|QFileInfo
argument_list|(
name|file
argument_list|)
operator|.
name|size
argument_list|()
decl_stmt|;
name|QTableWidgetItem
modifier|*
name|fileNameItem
init|=
operator|new
name|QTableWidgetItem
argument_list|(
name|files
index|[
name|i
index|]
argument_list|)
decl_stmt|;
name|fileNameItem
operator|->
name|setFlags
argument_list|(
name|fileNameItem
operator|->
name|flags
argument_list|()
operator|^
name|Qt
operator|::
name|ItemIsEditable
argument_list|)
expr_stmt|;
name|QTableWidgetItem
modifier|*
name|sizeItem
init|=
operator|new
name|QTableWidgetItem
argument_list|(
name|tr
argument_list|(
literal|"%1 KB"
argument_list|)
operator|.
name|arg
argument_list|(
name|int
argument_list|(
operator|(
name|size
operator|+
literal|1023
operator|)
operator|/
literal|1024
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|sizeItem
operator|->
name|setTextAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
expr_stmt|;
name|sizeItem
operator|->
name|setFlags
argument_list|(
name|sizeItem
operator|->
name|flags
argument_list|()
operator|^
name|Qt
operator|::
name|ItemIsEditable
argument_list|)
expr_stmt|;
name|int
name|row
init|=
name|filesTable
operator|->
name|rowCount
argument_list|()
decl_stmt|;
name|filesTable
operator|->
name|insertRow
argument_list|(
name|row
argument_list|)
expr_stmt|;
name|filesTable
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|0
argument_list|,
name|fileNameItem
argument_list|)
expr_stmt|;
name|filesTable
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|1
argument_list|,
name|sizeItem
argument_list|)
expr_stmt|;
block|}
name|filesFoundLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"%1 file(s) found"
argument_list|)
operator|.
name|arg
argument_list|(
name|files
operator|.
name|size
argument_list|()
argument_list|)
operator|+
operator|(
literal|" (Double click on a file to open it)"
operator|)
argument_list|)
expr_stmt|;
name|filesFoundLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|createButton
name|QPushButton
modifier|*
name|Window
operator|::
name|createButton
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
name|QPushButton
modifier|*
name|button
init|=
operator|new
name|QPushButton
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|member
argument_list|)
expr_stmt|;
return|return
name|button
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
DECL|function|createComboBox
name|QComboBox
modifier|*
name|Window
operator|::
name|createComboBox
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QComboBox
modifier|*
name|comboBox
init|=
operator|new
name|QComboBox
decl_stmt|;
name|comboBox
operator|->
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
argument_list|)
expr_stmt|;
return|return
name|comboBox
return|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|createFilesTable
name|void
name|Window
operator|::
name|createFilesTable
parameter_list|()
block|{
name|filesTable
operator|=
operator|new
name|QTableWidget
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|filesTable
operator|->
name|setSelectionBehavior
argument_list|(
name|QAbstractItemView
operator|::
name|SelectRows
argument_list|)
expr_stmt|;
name|QStringList
name|labels
decl_stmt|;
name|labels
operator|<<
name|tr
argument_list|(
literal|"Filename"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Size"
argument_list|)
expr_stmt|;
name|filesTable
operator|->
name|setHorizontalHeaderLabels
argument_list|(
name|labels
argument_list|)
expr_stmt|;
name|filesTable
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setResizeMode
argument_list|(
literal|0
argument_list|,
name|QHeaderView
operator|::
name|Stretch
argument_list|)
expr_stmt|;
name|filesTable
operator|->
name|verticalHeader
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|filesTable
operator|->
name|setShowGrid
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|filesTable
argument_list|,
name|SIGNAL
argument_list|(
name|cellActivated
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|openFileOfItem
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|openFileOfItem
name|void
name|Window
operator|::
name|openFileOfItem
parameter_list|(
name|int
name|row
parameter_list|,
name|int
comment|/* column */
parameter_list|)
block|{
name|QTableWidgetItem
modifier|*
name|item
init|=
name|filesTable
operator|->
name|item
argument_list|(
name|row
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|currentDir
operator|.
name|absoluteFilePath
argument_list|(
name|item
operator|->
name|text
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
end_unit
