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
begin_include
include|#
directive|include
file|<QPrintPreviewDialog>
end_include
begin_endif
endif|#
directive|endif
end_endif
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
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|sampleSizes
operator|<<
literal|32
operator|<<
literal|24
operator|<<
literal|16
operator|<<
literal|14
operator|<<
literal|12
operator|<<
literal|8
operator|<<
literal|4
operator|<<
literal|2
operator|<<
literal|1
expr_stmt|;
name|markedCount
operator|=
literal|0
expr_stmt|;
name|setupFontTree
argument_list|()
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
name|fontTree
argument_list|,
name|SIGNAL
argument_list|(
name|currentItemChanged
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|QTreeWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showFont
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fontTree
argument_list|,
name|SIGNAL
argument_list|(
name|itemChanged
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateStyles
argument_list|(
name|QTreeWidgetItem
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|fontTree
operator|->
name|setItemSelected
argument_list|(
name|fontTree
operator|->
name|topLevelItem
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|showFont
argument_list|(
name|fontTree
operator|->
name|topLevelItem
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setupFontTree
name|void
name|MainWindow
operator|::
name|setupFontTree
parameter_list|()
block|{
name|QFontDatabase
name|database
decl_stmt|;
name|fontTree
operator|->
name|setColumnCount
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|fontTree
operator|->
name|setHeaderLabels
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|tr
argument_list|(
literal|"Font"
argument_list|)
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QString
name|family
decl|,
name|database
operator|.
name|families
argument_list|()
control|)
block|{
specifier|const
name|QStringList
name|styles
init|=
name|database
operator|.
name|styles
argument_list|(
name|family
argument_list|)
decl_stmt|;
if|if
condition|(
name|styles
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|QTreeWidgetItem
modifier|*
name|familyItem
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|fontTree
argument_list|)
decl_stmt|;
name|familyItem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|family
argument_list|)
expr_stmt|;
name|familyItem
operator|->
name|setCheckState
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Unchecked
argument_list|)
expr_stmt|;
name|familyItem
operator|->
name|setFlags
argument_list|(
name|familyItem
operator|->
name|flags
argument_list|()
operator||
name|Qt
operator|::
name|ItemIsAutoTristate
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QString
name|style
decl|,
name|styles
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|styleItem
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|familyItem
argument_list|)
decl_stmt|;
name|styleItem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|style
argument_list|)
expr_stmt|;
name|styleItem
operator|->
name|setCheckState
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Unchecked
argument_list|)
expr_stmt|;
name|styleItem
operator|->
name|setData
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|,
name|QVariant
argument_list|(
name|database
operator|.
name|weight
argument_list|(
name|family
argument_list|,
name|style
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|styleItem
operator|->
name|setData
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
operator|+
literal|1
argument_list|,
name|QVariant
argument_list|(
name|database
operator|.
name|italic
argument_list|(
name|family
argument_list|,
name|style
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|on_clearAction_triggered
name|void
name|MainWindow
operator|::
name|on_clearAction_triggered
parameter_list|()
block|{
name|QTreeWidgetItem
modifier|*
name|currentItem
init|=
name|fontTree
operator|->
name|currentItem
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QTreeWidgetItem
modifier|*
name|item
decl|,
name|fontTree
operator|->
name|selectedItems
argument_list|()
control|)
name|fontTree
operator|->
name|setItemSelected
argument_list|(
name|item
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|fontTree
operator|->
name|setItemSelected
argument_list|(
name|currentItem
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_markAction_triggered
name|void
name|MainWindow
operator|::
name|on_markAction_triggered
parameter_list|()
block|{
name|markUnmarkFonts
argument_list|(
name|Qt
operator|::
name|Checked
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_unmarkAction_triggered
name|void
name|MainWindow
operator|::
name|on_unmarkAction_triggered
parameter_list|()
block|{
name|markUnmarkFonts
argument_list|(
name|Qt
operator|::
name|Unchecked
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|markUnmarkFonts
name|void
name|MainWindow
operator|::
name|markUnmarkFonts
parameter_list|(
name|Qt
operator|::
name|CheckState
name|state
parameter_list|)
block|{
name|QList
argument_list|<
name|QTreeWidgetItem
modifier|*
argument_list|>
name|items
init|=
name|fontTree
operator|->
name|selectedItems
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QTreeWidgetItem
modifier|*
name|item
decl|,
name|items
control|)
block|{
if|if
condition|(
name|item
operator|->
name|checkState
argument_list|(
literal|0
argument_list|)
operator|!=
name|state
condition|)
name|item
operator|->
name|setCheckState
argument_list|(
literal|0
argument_list|,
name|state
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|showFont
name|void
name|MainWindow
operator|::
name|showFont
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
block|{
if|if
condition|(
operator|!
name|item
condition|)
return|return;
name|QString
name|family
decl_stmt|;
name|QString
name|style
decl_stmt|;
name|int
name|weight
decl_stmt|;
name|bool
name|italic
decl_stmt|;
if|if
condition|(
name|item
operator|->
name|parent
argument_list|()
condition|)
block|{
name|family
operator|=
name|item
operator|->
name|parent
argument_list|()
operator|->
name|text
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|style
operator|=
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|weight
operator|=
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|italic
operator|=
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
operator|+
literal|1
argument_list|)
operator|.
name|toBool
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|family
operator|=
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|style
operator|=
name|item
operator|->
name|child
argument_list|(
literal|0
argument_list|)
operator|->
name|text
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|weight
operator|=
name|item
operator|->
name|child
argument_list|(
literal|0
argument_list|)
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|italic
operator|=
name|item
operator|->
name|child
argument_list|(
literal|0
argument_list|)
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
operator|+
literal|1
argument_list|)
operator|.
name|toBool
argument_list|()
expr_stmt|;
block|}
name|QString
name|oldText
init|=
name|textEdit
operator|->
name|toPlainText
argument_list|()
operator|.
name|trimmed
argument_list|()
decl_stmt|;
name|bool
name|modified
init|=
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|isModified
argument_list|()
decl_stmt|;
name|textEdit
operator|->
name|clear
argument_list|()
expr_stmt|;
name|QFont
name|font
argument_list|(
name|family
argument_list|,
literal|32
argument_list|,
name|weight
argument_list|,
name|italic
argument_list|)
decl_stmt|;
name|font
operator|.
name|setStyleName
argument_list|(
name|style
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|setDefaultFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|QTextCursor
name|cursor
init|=
name|textEdit
operator|->
name|textCursor
argument_list|()
decl_stmt|;
name|QTextBlockFormat
name|blockFormat
decl_stmt|;
name|blockFormat
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|(
name|blockFormat
argument_list|)
expr_stmt|;
if|if
condition|(
name|modified
condition|)
name|cursor
operator|.
name|insertText
argument_list|(
name|QString
argument_list|(
name|oldText
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|cursor
operator|.
name|insertText
argument_list|(
name|QString
argument_list|(
literal|"%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|family
argument_list|)
operator|.
name|arg
argument_list|(
name|style
argument_list|)
argument_list|)
expr_stmt|;
name|textEdit
operator|->
name|document
argument_list|()
operator|->
name|setModified
argument_list|(
name|modified
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateStyles
name|void
name|MainWindow
operator|::
name|updateStyles
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|,
name|int
name|column
parameter_list|)
block|{
if|if
condition|(
operator|!
name|item
operator|||
name|column
operator|!=
literal|0
condition|)
return|return;
name|Qt
operator|::
name|CheckState
name|state
init|=
name|item
operator|->
name|checkState
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QTreeWidgetItem
modifier|*
name|parent
init|=
name|item
operator|->
name|parent
argument_list|()
decl_stmt|;
if|if
condition|(
name|parent
condition|)
block|{
comment|// Only count style items.
if|if
condition|(
name|state
operator|==
name|Qt
operator|::
name|Checked
condition|)
operator|++
name|markedCount
expr_stmt|;
else|else
operator|--
name|markedCount
expr_stmt|;
block|}
name|printAction
operator|->
name|setEnabled
argument_list|(
name|markedCount
operator|>
literal|0
argument_list|)
expr_stmt|;
name|printPreviewAction
operator|->
name|setEnabled
argument_list|(
name|markedCount
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentPageMap
name|QMap
argument_list|<
name|QString
argument_list|,
name|StyleItems
argument_list|>
name|MainWindow
operator|::
name|currentPageMap
parameter_list|()
block|{
name|QMap
argument_list|<
name|QString
argument_list|,
name|StyleItems
argument_list|>
name|pageMap
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
name|fontTree
operator|->
name|topLevelItemCount
argument_list|()
condition|;
operator|++
name|row
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|familyItem
init|=
name|fontTree
operator|->
name|topLevelItem
argument_list|(
name|row
argument_list|)
decl_stmt|;
name|QString
name|family
decl_stmt|;
if|if
condition|(
name|familyItem
operator|->
name|checkState
argument_list|(
literal|0
argument_list|)
operator|==
name|Qt
operator|::
name|Checked
condition|)
block|{
name|family
operator|=
name|familyItem
operator|->
name|text
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|pageMap
index|[
name|family
index|]
operator|=
name|StyleItems
argument_list|()
expr_stmt|;
block|}
for|for
control|(
name|int
name|childRow
init|=
literal|0
init|;
name|childRow
operator|<
name|familyItem
operator|->
name|childCount
argument_list|()
condition|;
operator|++
name|childRow
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|styleItem
init|=
name|familyItem
operator|->
name|child
argument_list|(
name|childRow
argument_list|)
decl_stmt|;
if|if
condition|(
name|styleItem
operator|->
name|checkState
argument_list|(
literal|0
argument_list|)
operator|==
name|Qt
operator|::
name|Checked
condition|)
name|pageMap
index|[
name|family
index|]
operator|.
name|append
argument_list|(
name|styleItem
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|pageMap
return|;
block|}
end_function
begin_if
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
end_if
begin_function
DECL|function|on_printAction_triggered
name|void
name|MainWindow
operator|::
name|on_printAction_triggered
parameter_list|()
block|{
name|pageMap
operator|=
name|currentPageMap
argument_list|()
expr_stmt|;
if|if
condition|(
name|pageMap
operator|.
name|count
argument_list|()
operator|==
literal|0
condition|)
return|return;
name|QPrinter
name|printer
argument_list|(
name|QPrinter
operator|::
name|HighResolution
argument_list|)
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
return|return;
name|int
name|from
init|=
name|printer
operator|.
name|fromPage
argument_list|()
decl_stmt|;
name|int
name|to
init|=
name|printer
operator|.
name|toPage
argument_list|()
decl_stmt|;
if|if
condition|(
name|from
operator|<=
literal|0
operator|&&
name|to
operator|<=
literal|0
condition|)
name|printer
operator|.
name|setFromTo
argument_list|(
literal|1
argument_list|,
name|pageMap
operator|.
name|keys
argument_list|()
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|printDocument
argument_list|(
operator|&
name|printer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printDocument
name|void
name|MainWindow
operator|::
name|printDocument
parameter_list|(
name|QPrinter
modifier|*
name|printer
parameter_list|)
block|{
name|printer
operator|->
name|setFromTo
argument_list|(
literal|1
argument_list|,
name|pageMap
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|QProgressDialog
name|progress
argument_list|(
name|tr
argument_list|(
literal|"Preparing font samples..."
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Cancel"
argument_list|)
argument_list|,
literal|0
argument_list|,
name|pageMap
operator|.
name|count
argument_list|()
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
name|progress
operator|.
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Font Sampler"
argument_list|)
argument_list|)
expr_stmt|;
name|progress
operator|.
name|setMinimum
argument_list|(
name|printer
operator|->
name|fromPage
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|progress
operator|.
name|setMaximum
argument_list|(
name|printer
operator|->
name|toPage
argument_list|()
argument_list|)
expr_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
name|printer
argument_list|)
expr_stmt|;
name|bool
name|firstPage
init|=
literal|true
decl_stmt|;
for|for
control|(
name|int
name|page
init|=
name|printer
operator|->
name|fromPage
argument_list|()
init|;
name|page
operator|<=
name|printer
operator|->
name|toPage
argument_list|()
condition|;
operator|++
name|page
control|)
block|{
if|if
condition|(
operator|!
name|firstPage
condition|)
name|printer
operator|->
name|newPage
argument_list|()
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
name|printPage
argument_list|(
name|page
operator|-
literal|1
argument_list|,
operator|&
name|painter
argument_list|,
name|printer
argument_list|)
expr_stmt|;
name|progress
operator|.
name|setValue
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|firstPage
operator|=
literal|false
expr_stmt|;
block|}
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_printPreviewAction_triggered
name|void
name|MainWindow
operator|::
name|on_printPreviewAction_triggered
parameter_list|()
block|{
name|pageMap
operator|=
name|currentPageMap
argument_list|()
expr_stmt|;
if|if
condition|(
name|pageMap
operator|.
name|count
argument_list|()
operator|==
literal|0
condition|)
return|return;
name|QPrinter
name|printer
argument_list|(
name|QPrinter
operator|::
name|HighResolution
argument_list|)
decl_stmt|;
name|QPrintPreviewDialog
name|preview
argument_list|(
operator|&
name|printer
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
operator|&
name|preview
argument_list|,
name|SIGNAL
argument_list|(
name|paintRequested
argument_list|(
name|QPrinter
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|printDocument
argument_list|(
name|QPrinter
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|preview
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printPage
name|void
name|MainWindow
operator|::
name|printPage
parameter_list|(
name|int
name|index
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
name|QPrinter
modifier|*
name|printer
parameter_list|)
block|{
name|QString
name|family
init|=
name|pageMap
operator|.
name|keys
argument_list|()
index|[
name|index
index|]
decl_stmt|;
name|StyleItems
name|items
init|=
name|pageMap
index|[
name|family
index|]
decl_stmt|;
comment|// Find the dimensions of the text on each page.
name|qreal
name|width
init|=
literal|0.0
decl_stmt|;
name|qreal
name|height
init|=
literal|0.0
decl_stmt|;
foreach|foreach
control|(
name|QTreeWidgetItem
modifier|*
name|item
decl|,
name|items
control|)
block|{
name|QString
name|style
init|=
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|int
name|weight
init|=
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|bool
name|italic
init|=
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
operator|+
literal|1
argument_list|)
operator|.
name|toBool
argument_list|()
decl_stmt|;
comment|// Calculate the maximum width and total height of the text.
foreach|foreach
control|(
name|int
name|size
decl|,
name|sampleSizes
control|)
block|{
name|QFont
name|font
argument_list|(
name|family
argument_list|,
name|size
argument_list|,
name|weight
argument_list|,
name|italic
argument_list|)
decl_stmt|;
name|font
operator|.
name|setStyleName
argument_list|(
name|style
argument_list|)
expr_stmt|;
name|font
operator|=
name|QFont
argument_list|(
name|font
argument_list|,
name|painter
operator|->
name|device
argument_list|()
argument_list|)
expr_stmt|;
name|QFontMetricsF
name|fontMetrics
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QRectF
name|rect
init|=
name|fontMetrics
operator|.
name|boundingRect
argument_list|(
name|QString
argument_list|(
literal|"%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|family
argument_list|)
operator|.
name|arg
argument_list|(
name|style
argument_list|)
argument_list|)
decl_stmt|;
name|width
operator|=
name|qMax
argument_list|(
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|width
argument_list|)
expr_stmt|;
name|height
operator|+=
name|rect
operator|.
name|height
argument_list|()
expr_stmt|;
block|}
block|}
name|qreal
name|xScale
init|=
name|printer
operator|->
name|pageRect
argument_list|()
operator|.
name|width
argument_list|()
operator|/
name|width
decl_stmt|;
name|qreal
name|yScale
init|=
name|printer
operator|->
name|pageRect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|height
decl_stmt|;
name|qreal
name|scale
init|=
name|qMin
argument_list|(
name|xScale
argument_list|,
name|yScale
argument_list|)
decl_stmt|;
name|qreal
name|remainingHeight
init|=
name|printer
operator|->
name|pageRect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|scale
operator|-
name|height
decl_stmt|;
name|qreal
name|spaceHeight
init|=
operator|(
name|remainingHeight
operator|/
literal|4.0
operator|)
operator|/
operator|(
name|items
operator|.
name|count
argument_list|()
operator|+
literal|1
operator|)
decl_stmt|;
name|qreal
name|interLineHeight
init|=
operator|(
name|remainingHeight
operator|/
literal|4.0
operator|)
operator|/
operator|(
name|sampleSizes
operator|.
name|count
argument_list|()
operator|*
name|items
operator|.
name|count
argument_list|()
operator|)
decl_stmt|;
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|translate
argument_list|(
name|printer
operator|->
name|pageRect
argument_list|()
operator|.
name|width
argument_list|()
operator|/
literal|2.0
argument_list|,
name|printer
operator|->
name|pageRect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
literal|2.0
argument_list|)
expr_stmt|;
name|painter
operator|->
name|scale
argument_list|(
name|scale
argument_list|,
name|scale
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
argument_list|)
expr_stmt|;
name|qreal
name|x
init|=
operator|-
name|width
operator|/
literal|2.0
decl_stmt|;
name|qreal
name|y
init|=
operator|-
name|height
operator|/
literal|2.0
operator|-
name|remainingHeight
operator|/
literal|4.0
operator|+
name|spaceHeight
decl_stmt|;
foreach|foreach
control|(
name|QTreeWidgetItem
modifier|*
name|item
decl|,
name|items
control|)
block|{
name|QString
name|style
init|=
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|int
name|weight
init|=
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|bool
name|italic
init|=
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
operator|+
literal|1
argument_list|)
operator|.
name|toBool
argument_list|()
decl_stmt|;
comment|// Draw each line of text.
foreach|foreach
control|(
name|int
name|size
decl|,
name|sampleSizes
control|)
block|{
name|QFont
name|font
argument_list|(
name|family
argument_list|,
name|size
argument_list|,
name|weight
argument_list|,
name|italic
argument_list|)
decl_stmt|;
name|font
operator|.
name|setStyleName
argument_list|(
name|style
argument_list|)
expr_stmt|;
name|font
operator|=
name|QFont
argument_list|(
name|font
argument_list|,
name|painter
operator|->
name|device
argument_list|()
argument_list|)
expr_stmt|;
name|QFontMetricsF
name|fontMetrics
argument_list|(
name|font
argument_list|)
decl_stmt|;
name|QRectF
name|rect
init|=
name|fontMetrics
operator|.
name|boundingRect
argument_list|(
name|QString
argument_list|(
literal|"%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|font
operator|.
name|family
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|style
argument_list|)
argument_list|)
decl_stmt|;
name|y
operator|+=
name|rect
operator|.
name|height
argument_list|()
expr_stmt|;
name|painter
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|family
argument_list|)
operator|.
name|arg
argument_list|(
name|style
argument_list|)
argument_list|)
expr_stmt|;
name|y
operator|+=
name|interLineHeight
expr_stmt|;
block|}
name|y
operator|+=
name|spaceHeight
expr_stmt|;
block|}
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
end_unit
