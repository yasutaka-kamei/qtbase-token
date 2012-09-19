begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CALCULATOR_H
end_ifndef
begin_define
DECL|macro|CALCULATOR_H
define|#
directive|define
name|CALCULATOR_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|Button
name|class
name|Button
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|Calculator
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|Calculator
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|digitClicked
argument_list|()
block|;
name|void
name|unaryOperatorClicked
argument_list|()
block|;
name|void
name|additiveOperatorClicked
argument_list|()
block|;
name|void
name|multiplicativeOperatorClicked
argument_list|()
block|;
name|void
name|equalClicked
argument_list|()
block|;
name|void
name|pointClicked
argument_list|()
block|;
name|void
name|changeSignClicked
argument_list|()
block|;
name|void
name|backspaceClicked
argument_list|()
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|clearAll
argument_list|()
block|;
name|void
name|clearMemory
argument_list|()
block|;
name|void
name|readMemory
argument_list|()
block|;
name|void
name|setMemory
argument_list|()
block|;
name|void
name|addToMemory
argument_list|()
block|;
comment|//! [0]
comment|//! [1]
name|private
operator|:
comment|//! [1] //! [2]
name|Button
operator|*
name|createButton
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
name|void
name|abortOperation
argument_list|()
block|;
name|bool
name|calculate
argument_list|(
argument|double rightOperand
argument_list|,
argument|const QString&pendingOperator
argument_list|)
block|;
comment|//! [2]
comment|//! [3]
name|double
name|sumInMemory
block|;
comment|//! [3] //! [4]
name|double
name|sumSoFar
block|;
comment|//! [4] //! [5]
name|double
name|factorSoFar
block|;
comment|//! [5] //! [6]
name|QString
name|pendingAdditiveOperator
block|;
comment|//! [6] //! [7]
name|QString
name|pendingMultiplicativeOperator
block|;
comment|//! [7] //! [8]
name|bool
name|waitingForOperand
block|;
comment|//! [8]
comment|//! [9]
name|QLineEdit
operator|*
name|display
block|;
comment|//! [9] //! [10]
block|enum
block|{
name|NumDigitButtons
operator|=
literal|10
block|}
block|;
name|Button
operator|*
name|digitButtons
index|[
name|NumDigitButtons
index|]
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [10]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
