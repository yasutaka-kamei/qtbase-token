begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_include
include|#
directive|include
file|"detailsdialog.h"
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
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|newAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&New..."
argument_list|)
argument_list|)
decl_stmt|;
name|newAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|New
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
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|printFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|printAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Print
argument_list|)
expr_stmt|;
name|printAction
operator|->
name|setEnabled
argument_list|(
literal|false
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
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|letters
operator|=
operator|new
name|QTabWidget
expr_stmt|;
name|connect
argument_list|(
name|newAction
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
name|openDialog
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
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|letters
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Order Form"
argument_list|)
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
DECL|function|createLetter
name|void
name|MainWindow
operator|::
name|createLetter
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|address
parameter_list|,
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|>
name|orderItems
parameter_list|,
name|bool
name|sendOffers
parameter_list|)
block|{
name|QTextEdit
modifier|*
name|editor
init|=
operator|new
name|QTextEdit
decl_stmt|;
name|int
name|tabIndex
init|=
name|letters
operator|->
name|addTab
argument_list|(
name|editor
argument_list|,
name|name
argument_list|)
decl_stmt|;
name|letters
operator|->
name|setCurrentIndex
argument_list|(
name|tabIndex
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|QTextCursor
name|cursor
argument_list|(
name|editor
operator|->
name|textCursor
argument_list|()
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
comment|//! [2] //! [3]
name|QTextFrame
modifier|*
name|topFrame
init|=
name|cursor
operator|.
name|currentFrame
argument_list|()
decl_stmt|;
name|QTextFrameFormat
name|topFrameFormat
init|=
name|topFrame
operator|->
name|frameFormat
argument_list|()
decl_stmt|;
name|topFrameFormat
operator|.
name|setPadding
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|topFrame
operator|->
name|setFrameFormat
argument_list|(
name|topFrameFormat
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|textFormat
decl_stmt|;
name|QTextCharFormat
name|boldFormat
decl_stmt|;
name|boldFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|QTextFrameFormat
name|referenceFrameFormat
decl_stmt|;
name|referenceFrameFormat
operator|.
name|setBorder
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|referenceFrameFormat
operator|.
name|setPadding
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|referenceFrameFormat
operator|.
name|setPosition
argument_list|(
name|QTextFrameFormat
operator|::
name|FloatRight
argument_list|)
expr_stmt|;
name|referenceFrameFormat
operator|.
name|setWidth
argument_list|(
name|QTextLength
argument_list|(
name|QTextLength
operator|::
name|PercentageLength
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertFrame
argument_list|(
name|referenceFrameFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"A company"
argument_list|,
name|boldFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"321 City Street"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Industry Park"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Another country"
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|cursor
operator|.
name|setPosition
argument_list|(
name|topFrame
operator|->
name|lastPosition
argument_list|()
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|name
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
name|QString
name|line
decl_stmt|;
foreach|foreach
control|(
name|line
init|,
name|address
operator|.
name|split
argument_list|(
literal|"\n"
argument_list|)
control|)
block|{
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|line
argument_list|)
expr_stmt|;
block|}
comment|//! [4] //! [5]
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QDate
name|date
init|=
name|QDate
operator|::
name|currentDate
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"Date: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|date
operator|.
name|toString
argument_list|(
literal|"d MMMM yyyy"
argument_list|)
argument_list|)
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QTextFrameFormat
name|bodyFrameFormat
decl_stmt|;
name|bodyFrameFormat
operator|.
name|setWidth
argument_list|(
name|QTextLength
argument_list|(
name|QTextLength
operator|::
name|PercentageLength
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertFrame
argument_list|(
name|bodyFrameFormat
argument_list|)
expr_stmt|;
comment|//! [5]
comment|//! [6]
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"I would like to place an order for the following "
literal|"items:"
argument_list|)
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
comment|//! [6] //! [7]
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
comment|//! [7]
comment|//! [8]
name|QTextTableFormat
name|orderTableFormat
decl_stmt|;
name|orderTableFormat
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|QTextTable
modifier|*
name|orderTable
init|=
name|cursor
operator|.
name|insertTable
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|orderTableFormat
argument_list|)
decl_stmt|;
name|QTextFrameFormat
name|orderFrameFormat
init|=
name|cursor
operator|.
name|currentFrame
argument_list|()
operator|->
name|frameFormat
argument_list|()
decl_stmt|;
name|orderFrameFormat
operator|.
name|setBorder
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|currentFrame
argument_list|()
operator|->
name|setFrameFormat
argument_list|(
name|orderFrameFormat
argument_list|)
expr_stmt|;
comment|//! [8]
comment|//! [9]
name|cursor
operator|=
name|orderTable
operator|->
name|cellAt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"Product"
argument_list|)
argument_list|,
name|boldFormat
argument_list|)
expr_stmt|;
name|cursor
operator|=
name|orderTable
operator|->
name|cellAt
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"Quantity"
argument_list|)
argument_list|,
name|boldFormat
argument_list|)
expr_stmt|;
comment|//! [9]
comment|//! [10]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|orderItems
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|item
init|=
name|orderItems
index|[
name|i
index|]
decl_stmt|;
name|int
name|row
init|=
name|orderTable
operator|->
name|rows
argument_list|()
decl_stmt|;
name|orderTable
operator|->
name|insertRows
argument_list|(
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|cursor
operator|=
name|orderTable
operator|->
name|cellAt
argument_list|(
name|row
argument_list|,
literal|0
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|item
operator|.
name|first
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
name|cursor
operator|=
name|orderTable
operator|->
name|cellAt
argument_list|(
name|row
argument_list|,
literal|1
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|QString
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|item
operator|.
name|second
argument_list|)
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
block|}
comment|//! [10]
comment|//! [11]
name|cursor
operator|.
name|setPosition
argument_list|(
name|topFrame
operator|->
name|lastPosition
argument_list|()
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
comment|//! [11] //! [12]
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"Please update my records to take account of the "
literal|"following privacy information:"
argument_list|)
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
comment|//! [12]
comment|//! [13]
name|QTextTable
modifier|*
name|offersTable
init|=
name|cursor
operator|.
name|insertTable
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
decl_stmt|;
name|cursor
operator|=
name|offersTable
operator|->
name|cellAt
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"I want to receive more information about your "
literal|"company's products and special offers."
argument_list|)
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
name|cursor
operator|=
name|offersTable
operator|->
name|cellAt
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"I do not want to receive any promotional information "
literal|"from your company."
argument_list|)
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
if|if
condition|(
name|sendOffers
condition|)
name|cursor
operator|=
name|offersTable
operator|->
name|cellAt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
else|else
name|cursor
operator|=
name|offersTable
operator|->
name|cellAt
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
operator|.
name|firstCursorPosition
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"X"
argument_list|,
name|boldFormat
argument_list|)
expr_stmt|;
comment|//! [13]
comment|//! [14]
name|cursor
operator|.
name|setPosition
argument_list|(
name|topFrame
operator|->
name|lastPosition
argument_list|()
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"Sincerely,"
argument_list|)
argument_list|,
name|textFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|printAction
operator|->
name|setEnabled
argument_list|(
literal|true
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
DECL|function|createSample
name|void
name|MainWindow
operator|::
name|createSample
parameter_list|()
block|{
name|DetailsDialog
name|dialog
argument_list|(
literal|"Dialog with default values"
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|createLetter
argument_list|(
literal|"Mr. Smith"
argument_list|,
literal|"12 High Street\nSmall Town\nThis country"
argument_list|,
name|dialog
operator|.
name|orderItems
argument_list|()
argument_list|,
literal|true
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
DECL|function|openDialog
name|void
name|MainWindow
operator|::
name|openDialog
parameter_list|()
block|{
name|DetailsDialog
name|dialog
argument_list|(
name|tr
argument_list|(
literal|"Enter Customer Details"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|dialog
operator|.
name|exec
argument_list|()
operator|==
name|QDialog
operator|::
name|Accepted
condition|)
block|{
name|createLetter
argument_list|(
name|dialog
operator|.
name|senderName
argument_list|()
argument_list|,
name|dialog
operator|.
name|senderAddress
argument_list|()
argument_list|,
name|dialog
operator|.
name|orderItems
argument_list|()
argument_list|,
name|dialog
operator|.
name|sendOffers
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_function
DECL|function|printFile
name|void
name|MainWindow
operator|::
name|printFile
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
name|QTextEdit
modifier|*
name|editor
init|=
cast|static_cast
argument_list|<
name|QTextEdit
operator|*
argument_list|>
argument_list|(
name|letters
operator|->
name|currentWidget
argument_list|()
argument_list|)
decl_stmt|;
comment|//! [18]
name|QPrinter
name|printer
decl_stmt|;
name|QPrintDialog
name|dialog
argument_list|(
operator|&
name|printer
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|dialog
operator|.
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Print Document"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|editor
operator|->
name|textCursor
argument_list|()
operator|.
name|hasSelection
argument_list|()
condition|)
name|dialog
operator|.
name|addEnabledOption
argument_list|(
name|QAbstractPrintDialog
operator|::
name|PrintSelection
argument_list|)
expr_stmt|;
if|if
condition|(
name|dialog
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
comment|//! [18]
name|editor
operator|->
name|print
argument_list|(
operator|&
name|printer
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|//! [17]
end_comment
end_unit
