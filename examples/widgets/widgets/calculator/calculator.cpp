begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<cmath>
end_include
begin_include
include|#
directive|include
file|"button.h"
end_include
begin_include
include|#
directive|include
file|"calculator.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Calculator
name|Calculator
operator|::
name|Calculator
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
name|sumInMemory
operator|=
literal|0.0
expr_stmt|;
name|sumSoFar
operator|=
literal|0.0
expr_stmt|;
name|factorSoFar
operator|=
literal|0.0
expr_stmt|;
name|waitingForOperand
operator|=
literal|true
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|display
operator|=
operator|new
name|QLineEdit
argument_list|(
literal|"0"
argument_list|)
expr_stmt|;
comment|//! [1] //! [2]
name|display
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|display
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|display
operator|->
name|setMaxLength
argument_list|(
literal|15
argument_list|)
expr_stmt|;
name|QFont
name|font
init|=
name|display
operator|->
name|font
argument_list|()
decl_stmt|;
name|font
operator|.
name|setPointSize
argument_list|(
name|font
operator|.
name|pointSize
argument_list|()
operator|+
literal|8
argument_list|)
expr_stmt|;
name|display
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [4]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumDigitButtons
condition|;
operator|++
name|i
control|)
block|{
name|digitButtons
index|[
name|i
index|]
operator|=
name|createButton
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|digitClicked
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|Button
modifier|*
name|pointButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"."
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|pointClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|changeSignButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"\302\261"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|changeSignClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|backspaceButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"Backspace"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|backspaceClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|clearButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"Clear"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|clear
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|clearAllButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"Clear All"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|clearAll
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|clearMemoryButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"MC"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|clearMemory
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|readMemoryButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"MR"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|readMemory
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|setMemoryButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"MS"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|setMemory
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|addToMemoryButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"M+"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|addToMemory
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|divisionButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"\303\267"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|multiplicativeOperatorClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|timesButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"\303\227"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|multiplicativeOperatorClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|minusButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"-"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|additiveOperatorClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|plusButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"+"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|additiveOperatorClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|squareRootButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"Sqrt"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|unaryOperatorClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|powerButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"x\302\262"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|unaryOperatorClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|reciprocalButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"1/x"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|unaryOperatorClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Button
modifier|*
name|equalButton
init|=
name|createButton
argument_list|(
name|tr
argument_list|(
literal|"="
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|equalClicked
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
comment|//! [4]
comment|//! [5]
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
comment|//! [5] //! [6]
name|mainLayout
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetFixedSize
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|display
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|backspaceButton
argument_list|,
literal|1
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
name|clearButton
argument_list|,
literal|1
argument_list|,
literal|2
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
name|clearAllButton
argument_list|,
literal|1
argument_list|,
literal|4
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
name|clearMemoryButton
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
name|readMemoryButton
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|setMemoryButton
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
name|addToMemoryButton
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|NumDigitButtons
condition|;
operator|++
name|i
control|)
block|{
name|int
name|row
init|=
operator|(
operator|(
literal|9
operator|-
name|i
operator|)
operator|/
literal|3
operator|)
operator|+
literal|2
decl_stmt|;
name|int
name|column
init|=
operator|(
operator|(
name|i
operator|-
literal|1
operator|)
operator|%
literal|3
operator|)
operator|+
literal|1
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|digitButtons
index|[
name|i
index|]
argument_list|,
name|row
argument_list|,
name|column
argument_list|)
expr_stmt|;
block|}
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|digitButtons
index|[
literal|0
index|]
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
name|pointButton
argument_list|,
literal|5
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|changeSignButton
argument_list|,
literal|5
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|divisionButton
argument_list|,
literal|2
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|timesButton
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|minusButton
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|plusButton
argument_list|,
literal|5
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|squareRootButton
argument_list|,
literal|2
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|powerButton
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|reciprocalButton
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|equalButton
argument_list|,
literal|5
argument_list|,
literal|5
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
literal|"Calculator"
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
DECL|function|digitClicked
name|void
name|Calculator
operator|::
name|digitClicked
parameter_list|()
block|{
name|Button
modifier|*
name|clickedButton
init|=
name|qobject_cast
argument_list|<
name|Button
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|digitValue
init|=
name|clickedButton
operator|->
name|text
argument_list|()
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|display
operator|->
name|text
argument_list|()
operator|==
literal|"0"
operator|&&
name|digitValue
operator|==
literal|0.0
condition|)
return|return;
if|if
condition|(
name|waitingForOperand
condition|)
block|{
name|display
operator|->
name|clear
argument_list|()
expr_stmt|;
name|waitingForOperand
operator|=
literal|false
expr_stmt|;
block|}
name|display
operator|->
name|setText
argument_list|(
name|display
operator|->
name|text
argument_list|()
operator|+
name|QString
operator|::
name|number
argument_list|(
name|digitValue
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|unaryOperatorClicked
name|void
name|Calculator
operator|::
name|unaryOperatorClicked
parameter_list|()
comment|//! [8] //! [9]
block|{
name|Button
modifier|*
name|clickedButton
init|=
name|qobject_cast
argument_list|<
name|Button
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|clickedOperator
init|=
name|clickedButton
operator|->
name|text
argument_list|()
decl_stmt|;
name|double
name|operand
init|=
name|display
operator|->
name|text
argument_list|()
operator|.
name|toDouble
argument_list|()
decl_stmt|;
name|double
name|result
init|=
literal|0.0
decl_stmt|;
if|if
condition|(
name|clickedOperator
operator|==
name|tr
argument_list|(
literal|"Sqrt"
argument_list|)
condition|)
block|{
if|if
condition|(
name|operand
operator|<
literal|0.0
condition|)
block|{
name|abortOperation
argument_list|()
expr_stmt|;
return|return;
block|}
name|result
operator|=
name|std
operator|::
name|sqrt
argument_list|(
name|operand
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|clickedOperator
operator|==
name|tr
argument_list|(
literal|"x\302\262"
argument_list|)
condition|)
block|{
name|result
operator|=
name|std
operator|::
name|pow
argument_list|(
name|operand
argument_list|,
literal|2.0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|clickedOperator
operator|==
name|tr
argument_list|(
literal|"1/x"
argument_list|)
condition|)
block|{
if|if
condition|(
name|operand
operator|==
literal|0.0
condition|)
block|{
name|abortOperation
argument_list|()
expr_stmt|;
return|return;
block|}
name|result
operator|=
literal|1.0
operator|/
name|operand
expr_stmt|;
block|}
name|display
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
name|waitingForOperand
operator|=
literal|true
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
DECL|function|additiveOperatorClicked
name|void
name|Calculator
operator|::
name|additiveOperatorClicked
parameter_list|()
comment|//! [10] //! [11]
block|{
name|Button
modifier|*
name|clickedButton
init|=
name|qobject_cast
argument_list|<
name|Button
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|clickedOperator
init|=
name|clickedButton
operator|->
name|text
argument_list|()
decl_stmt|;
name|double
name|operand
init|=
name|display
operator|->
name|text
argument_list|()
operator|.
name|toDouble
argument_list|()
decl_stmt|;
comment|//! [11] //! [12]
if|if
condition|(
operator|!
name|pendingMultiplicativeOperator
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|//! [12] //! [13]
if|if
condition|(
operator|!
name|calculate
argument_list|(
name|operand
argument_list|,
name|pendingMultiplicativeOperator
argument_list|)
condition|)
block|{
name|abortOperation
argument_list|()
expr_stmt|;
return|return;
block|}
name|display
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|factorSoFar
argument_list|)
argument_list|)
expr_stmt|;
name|operand
operator|=
name|factorSoFar
expr_stmt|;
name|factorSoFar
operator|=
literal|0.0
expr_stmt|;
name|pendingMultiplicativeOperator
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|//! [13] //! [14]
if|if
condition|(
operator|!
name|pendingAdditiveOperator
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|//! [14] //! [15]
if|if
condition|(
operator|!
name|calculate
argument_list|(
name|operand
argument_list|,
name|pendingAdditiveOperator
argument_list|)
condition|)
block|{
name|abortOperation
argument_list|()
expr_stmt|;
return|return;
block|}
name|display
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|sumSoFar
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sumSoFar
operator|=
name|operand
expr_stmt|;
block|}
comment|//! [15] //! [16]
name|pendingAdditiveOperator
operator|=
name|clickedOperator
expr_stmt|;
comment|//! [16] //! [17]
name|waitingForOperand
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_function
DECL|function|multiplicativeOperatorClicked
name|void
name|Calculator
operator|::
name|multiplicativeOperatorClicked
parameter_list|()
block|{
name|Button
modifier|*
name|clickedButton
init|=
name|qobject_cast
argument_list|<
name|Button
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|clickedOperator
init|=
name|clickedButton
operator|->
name|text
argument_list|()
decl_stmt|;
name|double
name|operand
init|=
name|display
operator|->
name|text
argument_list|()
operator|.
name|toDouble
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|pendingMultiplicativeOperator
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|calculate
argument_list|(
name|operand
argument_list|,
name|pendingMultiplicativeOperator
argument_list|)
condition|)
block|{
name|abortOperation
argument_list|()
expr_stmt|;
return|return;
block|}
name|display
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|factorSoFar
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|factorSoFar
operator|=
name|operand
expr_stmt|;
block|}
name|pendingMultiplicativeOperator
operator|=
name|clickedOperator
expr_stmt|;
name|waitingForOperand
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_function
DECL|function|equalClicked
name|void
name|Calculator
operator|::
name|equalClicked
parameter_list|()
block|{
name|double
name|operand
init|=
name|display
operator|->
name|text
argument_list|()
operator|.
name|toDouble
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|pendingMultiplicativeOperator
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|calculate
argument_list|(
name|operand
argument_list|,
name|pendingMultiplicativeOperator
argument_list|)
condition|)
block|{
name|abortOperation
argument_list|()
expr_stmt|;
return|return;
block|}
name|operand
operator|=
name|factorSoFar
expr_stmt|;
name|factorSoFar
operator|=
literal|0.0
expr_stmt|;
name|pendingMultiplicativeOperator
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|pendingAdditiveOperator
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|calculate
argument_list|(
name|operand
argument_list|,
name|pendingAdditiveOperator
argument_list|)
condition|)
block|{
name|abortOperation
argument_list|()
expr_stmt|;
return|return;
block|}
name|pendingAdditiveOperator
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|sumSoFar
operator|=
name|operand
expr_stmt|;
block|}
name|display
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|sumSoFar
argument_list|)
argument_list|)
expr_stmt|;
name|sumSoFar
operator|=
literal|0.0
expr_stmt|;
name|waitingForOperand
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_function
DECL|function|pointClicked
name|void
name|Calculator
operator|::
name|pointClicked
parameter_list|()
block|{
if|if
condition|(
name|waitingForOperand
condition|)
name|display
operator|->
name|setText
argument_list|(
literal|"0"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|display
operator|->
name|text
argument_list|()
operator|.
name|contains
argument_list|(
literal|'.'
argument_list|)
condition|)
name|display
operator|->
name|setText
argument_list|(
name|display
operator|->
name|text
argument_list|()
operator|+
name|tr
argument_list|(
literal|"."
argument_list|)
argument_list|)
expr_stmt|;
name|waitingForOperand
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_function
DECL|function|changeSignClicked
name|void
name|Calculator
operator|::
name|changeSignClicked
parameter_list|()
block|{
name|QString
name|text
init|=
name|display
operator|->
name|text
argument_list|()
decl_stmt|;
name|double
name|value
init|=
name|text
operator|.
name|toDouble
argument_list|()
decl_stmt|;
if|if
condition|(
name|value
operator|>
literal|0.0
condition|)
block|{
name|text
operator|.
name|prepend
argument_list|(
name|tr
argument_list|(
literal|"-"
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|value
operator|<
literal|0.0
condition|)
block|{
name|text
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|display
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [26]
end_comment
begin_function
DECL|function|backspaceClicked
name|void
name|Calculator
operator|::
name|backspaceClicked
parameter_list|()
block|{
if|if
condition|(
name|waitingForOperand
condition|)
return|return;
name|QString
name|text
init|=
name|display
operator|->
name|text
argument_list|()
decl_stmt|;
name|text
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|text
operator|=
literal|"0"
expr_stmt|;
name|waitingForOperand
operator|=
literal|true
expr_stmt|;
block|}
name|display
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [26]
end_comment
begin_comment
comment|//! [28]
end_comment
begin_function
DECL|function|clear
name|void
name|Calculator
operator|::
name|clear
parameter_list|()
block|{
if|if
condition|(
name|waitingForOperand
condition|)
return|return;
name|display
operator|->
name|setText
argument_list|(
literal|"0"
argument_list|)
expr_stmt|;
name|waitingForOperand
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [28]
end_comment
begin_comment
comment|//! [30]
end_comment
begin_function
DECL|function|clearAll
name|void
name|Calculator
operator|::
name|clearAll
parameter_list|()
block|{
name|sumSoFar
operator|=
literal|0.0
expr_stmt|;
name|factorSoFar
operator|=
literal|0.0
expr_stmt|;
name|pendingAdditiveOperator
operator|.
name|clear
argument_list|()
expr_stmt|;
name|pendingMultiplicativeOperator
operator|.
name|clear
argument_list|()
expr_stmt|;
name|display
operator|->
name|setText
argument_list|(
literal|"0"
argument_list|)
expr_stmt|;
name|waitingForOperand
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [30]
end_comment
begin_comment
comment|//! [32]
end_comment
begin_function
DECL|function|clearMemory
name|void
name|Calculator
operator|::
name|clearMemory
parameter_list|()
block|{
name|sumInMemory
operator|=
literal|0.0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readMemory
name|void
name|Calculator
operator|::
name|readMemory
parameter_list|()
block|{
name|display
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|sumInMemory
argument_list|)
argument_list|)
expr_stmt|;
name|waitingForOperand
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setMemory
name|void
name|Calculator
operator|::
name|setMemory
parameter_list|()
block|{
name|equalClicked
argument_list|()
expr_stmt|;
name|sumInMemory
operator|=
name|display
operator|->
name|text
argument_list|()
operator|.
name|toDouble
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addToMemory
name|void
name|Calculator
operator|::
name|addToMemory
parameter_list|()
block|{
name|equalClicked
argument_list|()
expr_stmt|;
name|sumInMemory
operator|+=
name|display
operator|->
name|text
argument_list|()
operator|.
name|toDouble
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [32]
end_comment
begin_comment
comment|//! [34]
end_comment
begin_function
DECL|function|createButton
name|Button
modifier|*
name|Calculator
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
name|Button
modifier|*
name|button
init|=
operator|new
name|Button
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
comment|//! [34]
end_comment
begin_comment
comment|//! [36]
end_comment
begin_function
DECL|function|abortOperation
name|void
name|Calculator
operator|::
name|abortOperation
parameter_list|()
block|{
name|clearAll
argument_list|()
expr_stmt|;
name|display
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"####"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [36]
end_comment
begin_comment
comment|//! [38]
end_comment
begin_function
DECL|function|calculate
name|bool
name|Calculator
operator|::
name|calculate
parameter_list|(
name|double
name|rightOperand
parameter_list|,
specifier|const
name|QString
modifier|&
name|pendingOperator
parameter_list|)
block|{
if|if
condition|(
name|pendingOperator
operator|==
name|tr
argument_list|(
literal|"+"
argument_list|)
condition|)
block|{
name|sumSoFar
operator|+=
name|rightOperand
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pendingOperator
operator|==
name|tr
argument_list|(
literal|"-"
argument_list|)
condition|)
block|{
name|sumSoFar
operator|-=
name|rightOperand
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pendingOperator
operator|==
name|tr
argument_list|(
literal|"\303\227"
argument_list|)
condition|)
block|{
name|factorSoFar
operator|*=
name|rightOperand
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pendingOperator
operator|==
name|tr
argument_list|(
literal|"\303\267"
argument_list|)
condition|)
block|{
if|if
condition|(
name|rightOperand
operator|==
literal|0.0
condition|)
return|return
literal|false
return|;
name|factorSoFar
operator|/=
name|rightOperand
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [38]
end_comment
end_unit
