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
file|"characterwidget.h"
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
name|QWidget
modifier|*
name|centralWidget
init|=
operator|new
name|QWidget
decl_stmt|;
name|QLabel
modifier|*
name|fontLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Font:"
argument_list|)
argument_list|)
decl_stmt|;
name|fontCombo
operator|=
operator|new
name|QFontComboBox
expr_stmt|;
name|QLabel
modifier|*
name|sizeLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Size:"
argument_list|)
argument_list|)
decl_stmt|;
name|sizeCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|QLabel
modifier|*
name|styleLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Style:"
argument_list|)
argument_list|)
decl_stmt|;
name|styleCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|QLabel
modifier|*
name|fontMergingLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Automatic Font Merging:"
argument_list|)
argument_list|)
decl_stmt|;
name|fontMerging
operator|=
operator|new
name|QCheckBox
expr_stmt|;
name|fontMerging
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scrollArea
operator|=
operator|new
name|QScrollArea
expr_stmt|;
name|characterWidget
operator|=
operator|new
name|CharacterWidget
expr_stmt|;
name|scrollArea
operator|->
name|setWidget
argument_list|(
name|characterWidget
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|findStyles
argument_list|(
name|fontCombo
operator|->
name|currentFont
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [1]
name|findSizes
argument_list|(
name|fontCombo
operator|->
name|currentFont
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [2]
name|lineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|QPushButton
modifier|*
name|clipboardButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"&To clipboard"
argument_list|)
argument_list|)
decl_stmt|;
comment|//! [2]
comment|//! [3]
name|clipboard
operator|=
name|QApplication
operator|::
name|clipboard
argument_list|()
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|connect
argument_list|(
name|fontCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentFontChanged
argument_list|(
name|QFont
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|findStyles
argument_list|(
name|QFont
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fontCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentFontChanged
argument_list|(
name|QFont
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|findSizes
argument_list|(
name|QFont
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fontCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentFontChanged
argument_list|(
name|QFont
argument_list|)
argument_list|)
argument_list|,
name|characterWidget
argument_list|,
name|SLOT
argument_list|(
name|updateFont
argument_list|(
name|QFont
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|sizeCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|characterWidget
argument_list|,
name|SLOT
argument_list|(
name|updateSize
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|styleCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|characterWidget
argument_list|,
name|SLOT
argument_list|(
name|updateStyle
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [4] //! [5]
name|connect
argument_list|(
name|characterWidget
argument_list|,
name|SIGNAL
argument_list|(
name|characterSelected
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|insertCharacter
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|clipboardButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateClipboard
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [5]
name|connect
argument_list|(
name|fontMerging
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|characterWidget
argument_list|,
name|SLOT
argument_list|(
name|updateFontMerging
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [6]
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
name|fontLabel
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|fontCombo
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|sizeLabel
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|sizeCombo
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|styleLabel
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|styleCombo
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|fontMergingLabel
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addWidget
argument_list|(
name|fontMerging
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|controlsLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|lineLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|lineLayout
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|lineLayout
operator|->
name|addSpacing
argument_list|(
literal|12
argument_list|)
expr_stmt|;
name|lineLayout
operator|->
name|addWidget
argument_list|(
name|clipboardButton
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|centralLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|centralLayout
operator|->
name|addLayout
argument_list|(
name|controlsLayout
argument_list|)
expr_stmt|;
name|centralLayout
operator|->
name|addWidget
argument_list|(
name|scrollArea
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|centralLayout
operator|->
name|addSpacing
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|centralLayout
operator|->
name|addLayout
argument_list|(
name|lineLayout
argument_list|)
expr_stmt|;
name|centralWidget
operator|->
name|setLayout
argument_list|(
name|centralLayout
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
literal|"Character Map"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|findStyles
name|void
name|MainWindow
operator|::
name|findStyles
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
name|QFontDatabase
name|fontDatabase
decl_stmt|;
name|QString
name|currentItem
init|=
name|styleCombo
operator|->
name|currentText
argument_list|()
decl_stmt|;
name|styleCombo
operator|->
name|clear
argument_list|()
expr_stmt|;
comment|//! [7]
comment|//! [8]
name|QString
name|style
decl_stmt|;
foreach|foreach
control|(
name|style
init|,
name|fontDatabase
operator|.
name|styles
argument_list|(
name|font
operator|.
name|family
argument_list|()
argument_list|)
control|)
name|styleCombo
operator|->
name|addItem
argument_list|(
name|style
argument_list|)
expr_stmt|;
name|int
name|styleIndex
init|=
name|styleCombo
operator|->
name|findText
argument_list|(
name|currentItem
argument_list|)
decl_stmt|;
if|if
condition|(
name|styleIndex
operator|==
operator|-
literal|1
condition|)
name|styleCombo
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|else
name|styleCombo
operator|->
name|setCurrentIndex
argument_list|(
name|styleIndex
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|findSizes
name|void
name|MainWindow
operator|::
name|findSizes
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
name|QFontDatabase
name|fontDatabase
decl_stmt|;
name|QString
name|currentSize
init|=
name|sizeCombo
operator|->
name|currentText
argument_list|()
decl_stmt|;
name|sizeCombo
operator|->
name|blockSignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|sizeCombo
operator|->
name|clear
argument_list|()
expr_stmt|;
name|int
name|size
decl_stmt|;
if|if
condition|(
name|fontDatabase
operator|.
name|isSmoothlyScalable
argument_list|(
name|font
operator|.
name|family
argument_list|()
argument_list|,
name|fontDatabase
operator|.
name|styleString
argument_list|(
name|font
argument_list|)
argument_list|)
condition|)
block|{
foreach|foreach
control|(
name|size
init|,
name|QFontDatabase
operator|::
name|standardSizes
argument_list|()
control|)
block|{
name|sizeCombo
operator|->
name|addItem
argument_list|(
name|QVariant
argument_list|(
name|size
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|sizeCombo
operator|->
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
foreach|foreach
control|(
name|size
init|,
name|fontDatabase
operator|.
name|smoothSizes
argument_list|(
name|font
operator|.
name|family
argument_list|()
argument_list|,
name|fontDatabase
operator|.
name|styleString
argument_list|(
name|font
argument_list|)
argument_list|)
control|)
block|{
name|sizeCombo
operator|->
name|addItem
argument_list|(
name|QVariant
argument_list|(
name|size
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|sizeCombo
operator|->
name|setEditable
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
name|sizeCombo
operator|->
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|int
name|sizeIndex
init|=
name|sizeCombo
operator|->
name|findText
argument_list|(
name|currentSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|sizeIndex
operator|==
operator|-
literal|1
condition|)
name|sizeCombo
operator|->
name|setCurrentIndex
argument_list|(
name|qMax
argument_list|(
literal|0
argument_list|,
name|sizeCombo
operator|->
name|count
argument_list|()
operator|/
literal|3
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|sizeCombo
operator|->
name|setCurrentIndex
argument_list|(
name|sizeIndex
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|insertCharacter
name|void
name|MainWindow
operator|::
name|insertCharacter
parameter_list|(
specifier|const
name|QString
modifier|&
name|character
parameter_list|)
block|{
name|lineEdit
operator|->
name|insert
argument_list|(
name|character
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|updateClipboard
name|void
name|MainWindow
operator|::
name|updateClipboard
parameter_list|()
block|{
comment|//! [11]
name|clipboard
operator|->
name|setText
argument_list|(
name|lineEdit
operator|->
name|text
argument_list|()
argument_list|,
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
comment|//! [11]
name|clipboard
operator|->
name|setText
argument_list|(
name|lineEdit
operator|->
name|text
argument_list|()
argument_list|,
name|QClipboard
operator|::
name|Selection
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
end_unit
