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
file|"regexpdialog.h"
end_include
begin_constructor
DECL|function|RegExpDialog
name|RegExpDialog
operator|::
name|RegExpDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|patternComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|patternComboBox
operator|->
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|patternComboBox
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
name|patternLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Pattern:"
argument_list|)
argument_list|)
expr_stmt|;
name|patternLabel
operator|->
name|setBuddy
argument_list|(
name|patternComboBox
argument_list|)
expr_stmt|;
name|escapedPatternLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|escapedPatternLineEdit
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QPalette
name|palette
init|=
name|escapedPatternLineEdit
operator|->
name|palette
argument_list|()
decl_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Base
argument_list|)
argument_list|)
expr_stmt|;
name|escapedPatternLineEdit
operator|->
name|setPalette
argument_list|(
name|palette
argument_list|)
expr_stmt|;
name|escapedPatternLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Escaped Pattern:"
argument_list|)
argument_list|)
expr_stmt|;
name|escapedPatternLabel
operator|->
name|setBuddy
argument_list|(
name|escapedPatternLineEdit
argument_list|)
expr_stmt|;
name|syntaxComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|syntaxComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Regular expression v1"
argument_list|)
argument_list|,
name|QRegExp
operator|::
name|RegExp
argument_list|)
expr_stmt|;
name|syntaxComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Regular expression v2"
argument_list|)
argument_list|,
name|QRegExp
operator|::
name|RegExp2
argument_list|)
expr_stmt|;
name|syntaxComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Wildcard"
argument_list|)
argument_list|,
name|QRegExp
operator|::
name|Wildcard
argument_list|)
expr_stmt|;
name|syntaxComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Fixed string"
argument_list|)
argument_list|,
name|QRegExp
operator|::
name|FixedString
argument_list|)
expr_stmt|;
name|syntaxComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"W3C Xml Schema 1.1"
argument_list|)
argument_list|,
name|QRegExp
operator|::
name|W3CXmlSchema11
argument_list|)
expr_stmt|;
name|syntaxLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Pattern Syntax:"
argument_list|)
argument_list|)
expr_stmt|;
name|syntaxLabel
operator|->
name|setBuddy
argument_list|(
name|syntaxComboBox
argument_list|)
expr_stmt|;
name|textComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|textComboBox
operator|->
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|textComboBox
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
name|textLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Text:"
argument_list|)
argument_list|)
expr_stmt|;
name|textLabel
operator|->
name|setBuddy
argument_list|(
name|textComboBox
argument_list|)
expr_stmt|;
name|caseSensitiveCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Case&Sensitive"
argument_list|)
argument_list|)
expr_stmt|;
name|caseSensitiveCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|minimalCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Minimal"
argument_list|)
argument_list|)
expr_stmt|;
name|indexLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Index of Match:"
argument_list|)
argument_list|)
expr_stmt|;
name|indexEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|indexEdit
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|matchedLengthLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Matched Length:"
argument_list|)
argument_list|)
expr_stmt|;
name|matchedLengthEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|matchedLengthEdit
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|MaxCaptures
condition|;
operator|++
name|i
control|)
block|{
name|captureLabels
index|[
name|i
index|]
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Capture %1:"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|captureEdits
index|[
name|i
index|]
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|captureEdits
index|[
name|i
index|]
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
name|captureLabels
index|[
literal|0
index|]
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Match:"
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|checkBoxLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|checkBoxLayout
operator|->
name|addWidget
argument_list|(
name|caseSensitiveCheckBox
argument_list|)
expr_stmt|;
name|checkBoxLayout
operator|->
name|addWidget
argument_list|(
name|minimalCheckBox
argument_list|)
expr_stmt|;
name|checkBoxLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|patternLabel
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
name|patternComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|escapedPatternLabel
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
name|escapedPatternLineEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|syntaxLabel
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
name|syntaxComboBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|checkBoxLayout
argument_list|,
literal|3
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
name|textLabel
argument_list|,
literal|4
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
literal|4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|indexLabel
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|indexEdit
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|matchedLengthLabel
argument_list|,
literal|6
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|matchedLengthEdit
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|MaxCaptures
condition|;
operator|++
name|j
control|)
block|{
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|captureLabels
index|[
name|j
index|]
argument_list|,
literal|7
operator|+
name|j
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|captureEdits
index|[
name|j
index|]
argument_list|,
literal|7
operator|+
name|j
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|patternComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|editTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|refresh
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|textComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|editTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|refresh
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|caseSensitiveCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|refresh
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|minimalCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|refresh
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|syntaxComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|refresh
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|patternComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"[A-Za-z_]+([A-Za-z_0-9]*)"
argument_list|)
argument_list|)
expr_stmt|;
name|textComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"(10 + delta4) * 32"
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"RegExp"
argument_list|)
argument_list|)
expr_stmt|;
name|setFixedHeight
argument_list|(
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|refresh
name|void
name|RegExpDialog
operator|::
name|refresh
parameter_list|()
block|{
name|setUpdatesEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QString
name|pattern
init|=
name|patternComboBox
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
name|escaped
init|=
name|pattern
decl_stmt|;
name|escaped
operator|.
name|replace
argument_list|(
literal|"\\"
argument_list|,
literal|"\\\\"
argument_list|)
expr_stmt|;
name|escaped
operator|.
name|replace
argument_list|(
literal|"\""
argument_list|,
literal|"\\\""
argument_list|)
expr_stmt|;
name|escaped
operator|.
name|prepend
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
name|escaped
operator|.
name|append
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
name|escapedPatternLineEdit
operator|->
name|setText
argument_list|(
name|escaped
argument_list|)
expr_stmt|;
name|QRegExp
name|rx
argument_list|(
name|pattern
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|CaseSensitivity
name|cs
init|=
name|Qt
operator|::
name|CaseInsensitive
decl_stmt|;
if|if
condition|(
name|caseSensitiveCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
name|cs
operator|=
name|Qt
operator|::
name|CaseSensitive
expr_stmt|;
name|rx
operator|.
name|setCaseSensitivity
argument_list|(
name|cs
argument_list|)
expr_stmt|;
name|rx
operator|.
name|setMinimal
argument_list|(
name|minimalCheckBox
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
name|QRegExp
operator|::
name|PatternSyntax
name|syntax
init|=
name|QRegExp
operator|::
name|PatternSyntax
argument_list|(
name|syntaxComboBox
operator|->
name|itemData
argument_list|(
name|syntaxComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|syntax
argument_list|)
expr_stmt|;
name|QPalette
name|palette
init|=
name|patternComboBox
operator|->
name|palette
argument_list|()
decl_stmt|;
if|if
condition|(
name|rx
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Text
argument_list|,
name|textComboBox
operator|->
name|palette
argument_list|()
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Text
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|palette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Text
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
block|}
name|patternComboBox
operator|->
name|setPalette
argument_list|(
name|palette
argument_list|)
expr_stmt|;
name|indexEdit
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|rx
operator|.
name|indexIn
argument_list|(
name|text
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|matchedLengthEdit
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|rx
operator|.
name|matchedLength
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|MaxCaptures
condition|;
operator|++
name|i
control|)
block|{
name|captureLabels
index|[
name|i
index|]
operator|->
name|setEnabled
argument_list|(
name|i
operator|<=
name|rx
operator|.
name|captureCount
argument_list|()
argument_list|)
expr_stmt|;
name|captureEdits
index|[
name|i
index|]
operator|->
name|setEnabled
argument_list|(
name|i
operator|<=
name|rx
operator|.
name|captureCount
argument_list|()
argument_list|)
expr_stmt|;
name|captureEdits
index|[
name|i
index|]
operator|->
name|setText
argument_list|(
name|rx
operator|.
name|cap
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|setUpdatesEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
