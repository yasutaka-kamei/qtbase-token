begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"imagemodel.h"
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"pixeldelegate.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|<QPrinter>
end_include
begin_include
include|#
directive|include
file|<QPrintDialog>
end_include
begin_endif
endif|#
directive|endif
end_endif
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
comment|//! [0]
name|currentPath
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
expr_stmt|;
name|model
operator|=
operator|new
name|ImageModel
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|centralWidget
init|=
operator|new
name|QWidget
decl_stmt|;
comment|//! [1]
name|view
operator|=
operator|new
name|QTableView
expr_stmt|;
name|view
operator|->
name|setShowGrid
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|view
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|view
operator|->
name|verticalHeader
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|view
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setMinimumSectionSize
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|view
operator|->
name|verticalHeader
argument_list|()
operator|->
name|setMinimumSectionSize
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|view
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|PixelDelegate
modifier|*
name|delegate
init|=
operator|new
name|PixelDelegate
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|view
operator|->
name|setItemDelegate
argument_list|(
name|delegate
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QLabel
modifier|*
name|pixelSizeLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Pixel size:"
argument_list|)
argument_list|)
decl_stmt|;
name|QSpinBox
modifier|*
name|pixelSizeSpinBox
init|=
operator|new
name|QSpinBox
decl_stmt|;
name|pixelSizeSpinBox
operator|->
name|setMinimum
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|pixelSizeSpinBox
operator|->
name|setMaximum
argument_list|(
literal|32
argument_list|)
expr_stmt|;
name|pixelSizeSpinBox
operator|->
name|setValue
argument_list|(
literal|12
argument_list|)
expr_stmt|;
comment|//! [3]
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
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|openAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|)
decl_stmt|;
name|openAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|printAction
operator|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Print..."
argument_list|)
argument_list|)
expr_stmt|;
name|printAction
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|printAction
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
operator|::
name|Print
argument_list|)
expr_stmt|;
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
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|helpMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&Help"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|aboutAction
init|=
name|helpMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&About"
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
name|addSeparator
argument_list|()
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|helpMenu
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openAction
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
name|chooseImage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|printAction
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
name|printImage
argument_list|()
argument_list|)
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
name|aboutAction
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
name|showAboutBox
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [4]
name|connect
argument_list|(
name|pixelSizeSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|delegate
argument_list|,
name|SLOT
argument_list|(
name|setPixelSize
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pixelSizeSpinBox
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
name|updateView
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [4]
name|QHBoxLayout
modifier|*
name|controlsLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|pixelSizeLabel
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|pixelSizeSpinBox
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|view
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|controlsLayout
argument_list|)
expr_stmt|;
name|centralWidget
operator|->
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Pixelator"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
comment|//! [5]
block|}
end_constructor
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|chooseImage
name|void
name|MainWindow
operator|::
name|chooseImage
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
literal|"Choose an image"
argument_list|)
argument_list|,
name|currentPath
argument_list|,
literal|"*"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|openImage
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openImage
name|void
name|MainWindow
operator|::
name|openImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QImage
name|image
decl_stmt|;
if|if
condition|(
name|image
operator|.
name|load
argument_list|(
name|fileName
argument_list|)
condition|)
block|{
name|model
operator|->
name|setImage
argument_list|(
name|image
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|startsWith
argument_list|(
literal|":/"
argument_list|)
condition|)
block|{
name|currentPath
operator|=
name|fileName
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"%1 - Pixelator"
argument_list|)
operator|.
name|arg
argument_list|(
name|currentPath
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|printAction
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|updateView
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|printImage
name|void
name|MainWindow
operator|::
name|printImage
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_PRINTDIALOG
argument_list|)
if|if
condition|(
name|model
operator|->
name|rowCount
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
operator|*
name|model
operator|->
name|columnCount
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
operator|>
literal|90000
condition|)
block|{
name|QMessageBox
operator|::
name|StandardButton
name|answer
decl_stmt|;
name|answer
operator|=
name|QMessageBox
operator|::
name|question
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Large Image Size"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The printed image may be very large. Are you sure that "
literal|"you want to print it?"
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Yes
operator||
name|QMessageBox
operator|::
name|No
argument_list|)
expr_stmt|;
if|if
condition|(
name|answer
operator|==
name|QMessageBox
operator|::
name|No
condition|)
return|return;
block|}
name|QPrinter
name|printer
argument_list|(
name|QPrinter
operator|::
name|HighResolution
argument_list|)
decl_stmt|;
name|QPrintDialog
name|dlg
argument_list|(
operator|&
name|printer
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|dlg
operator|.
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Print Image"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|dlg
operator|.
name|exec
argument_list|()
operator|!=
name|QDialog
operator|::
name|Accepted
condition|)
block|{
return|return;
block|}
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|printer
argument_list|)
expr_stmt|;
name|int
name|rows
init|=
name|model
operator|->
name|rowCount
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|columns
init|=
name|model
operator|->
name|columnCount
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|sourceWidth
init|=
operator|(
name|columns
operator|+
literal|1
operator|)
operator|*
name|ItemSize
decl_stmt|;
name|int
name|sourceHeight
init|=
operator|(
name|rows
operator|+
literal|1
operator|)
operator|*
name|ItemSize
decl_stmt|;
name|painter
operator|.
name|save
argument_list|()
expr_stmt|;
name|double
name|xscale
init|=
name|printer
operator|.
name|pageRect
argument_list|()
operator|.
name|width
argument_list|()
operator|/
name|double
argument_list|(
name|sourceWidth
argument_list|)
decl_stmt|;
name|double
name|yscale
init|=
name|printer
operator|.
name|pageRect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|double
argument_list|(
name|sourceHeight
argument_list|)
decl_stmt|;
name|double
name|scale
init|=
name|qMin
argument_list|(
name|xscale
argument_list|,
name|yscale
argument_list|)
decl_stmt|;
name|painter
operator|.
name|translate
argument_list|(
name|printer
operator|.
name|paperRect
argument_list|()
operator|.
name|x
argument_list|()
operator|+
name|printer
operator|.
name|pageRect
argument_list|()
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|printer
operator|.
name|paperRect
argument_list|()
operator|.
name|y
argument_list|()
operator|+
name|printer
operator|.
name|pageRect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|painter
operator|.
name|scale
argument_list|(
name|scale
argument_list|,
name|scale
argument_list|)
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
operator|-
name|sourceWidth
operator|/
literal|2
argument_list|,
operator|-
name|sourceHeight
operator|/
literal|2
argument_list|)
expr_stmt|;
name|QStyleOptionViewItem
name|option
decl_stmt|;
name|QModelIndex
name|parent
init|=
name|QModelIndex
argument_list|()
decl_stmt|;
name|QProgressDialog
name|progress
argument_list|(
name|tr
argument_list|(
literal|"Printing..."
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cancel"
argument_list|)
argument_list|,
literal|0
argument_list|,
name|rows
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|progress
operator|.
name|setWindowModality
argument_list|(
name|Qt
operator|::
name|ApplicationModal
argument_list|)
expr_stmt|;
name|float
name|y
init|=
name|ItemSize
operator|/
literal|2
decl_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|rows
condition|;
operator|++
name|row
control|)
block|{
name|progress
operator|.
name|setValue
argument_list|(
name|row
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
if|if
condition|(
name|progress
operator|.
name|wasCanceled
argument_list|()
condition|)
break|break;
name|float
name|x
init|=
name|ItemSize
operator|/
literal|2
decl_stmt|;
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
name|columns
condition|;
operator|++
name|column
control|)
block|{
name|option
operator|.
name|rect
operator|=
name|QRect
argument_list|(
name|int
argument_list|(
name|x
argument_list|)
argument_list|,
name|int
argument_list|(
name|y
argument_list|)
argument_list|,
name|ItemSize
argument_list|,
name|ItemSize
argument_list|)
expr_stmt|;
name|view
operator|->
name|itemDelegate
argument_list|()
operator|->
name|paint
argument_list|(
operator|&
name|painter
argument_list|,
name|option
argument_list|,
name|model
operator|->
name|index
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|parent
argument_list|)
argument_list|)
expr_stmt|;
name|x
operator|=
name|x
operator|+
name|ItemSize
expr_stmt|;
block|}
name|y
operator|=
name|y
operator|+
name|ItemSize
expr_stmt|;
block|}
name|progress
operator|.
name|setValue
argument_list|(
name|rows
argument_list|)
expr_stmt|;
name|painter
operator|.
name|restore
argument_list|()
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
if|if
condition|(
name|progress
operator|.
name|wasCanceled
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Printing canceled"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The printing process was canceled."
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Printing canceled"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Printing is not supported on this Qt build"
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|showAboutBox
name|void
name|MainWindow
operator|::
name|showAboutBox
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
literal|"About the Pixelator example"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"This example demonstrates how a standard view and a custom\n"
literal|"delegate can be used to produce a specialized representation\n"
literal|"of data in a simple custom model."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|updateView
name|void
name|MainWindow
operator|::
name|updateView
parameter_list|()
block|{
name|view
operator|->
name|resizeColumnsToContents
argument_list|()
expr_stmt|;
name|view
operator|->
name|resizeRowsToContents
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
end_unit
