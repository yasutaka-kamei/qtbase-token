begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|args
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argv
argument_list|,
name|args
argument_list|)
decl_stmt|;
name|QStateMachine
name|machine
decl_stmt|;
comment|//![0]
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
name|QState
modifier|*
name|s11
init|=
operator|new
name|QState
argument_list|(
name|s1
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|s12
init|=
operator|new
name|QState
argument_list|(
name|s1
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|s13
init|=
operator|new
name|QState
argument_list|(
name|s1
argument_list|)
decl_stmt|;
name|s1
operator|->
name|setInitialState
argument_list|(
name|s11
argument_list|)
expr_stmt|;
name|machine
operator|.
name|addState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
comment|//![0]
comment|//![2]
name|s12
operator|->
name|addTransition
argument_list|(
name|quitButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|s12
argument_list|)
expr_stmt|;
comment|//![2]
comment|//![1]
name|QFinalState
modifier|*
name|s2
init|=
operator|new
name|QFinalState
argument_list|()
decl_stmt|;
name|s1
operator|->
name|addTransition
argument_list|(
name|quitButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|s2
argument_list|)
expr_stmt|;
name|machine
operator|.
name|addState
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|machine
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|QApplication
operator|::
name|instance
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//![1]
name|QButton
modifier|*
name|interruptButton
init|=
operator|new
name|QPushButton
argument_list|(
literal|"Interrupt Button"
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|mainWindow
init|=
operator|new
name|QWidget
argument_list|()
decl_stmt|;
comment|//![3]
name|QHistoryState
modifier|*
name|s1h
init|=
operator|new
name|QHistoryState
argument_list|(
name|s1
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|s3
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
name|s3
operator|->
name|assignProperty
argument_list|(
name|label
argument_list|,
literal|"text"
argument_list|,
literal|"In s3"
argument_list|)
expr_stmt|;
name|QMessageBox
modifier|*
name|mbox
init|=
operator|new
name|QMessageBox
argument_list|(
name|mainWindow
argument_list|)
decl_stmt|;
name|mbox
operator|->
name|addButton
argument_list|(
name|QMessageBox
operator|::
name|Ok
argument_list|)
expr_stmt|;
name|mbox
operator|->
name|setText
argument_list|(
literal|"Interrupted!"
argument_list|)
expr_stmt|;
name|mbox
operator|->
name|setIcon
argument_list|(
name|QMessageBox
operator|::
name|Information
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|s3
argument_list|,
name|SIGNAL
argument_list|(
name|entered
argument_list|()
argument_list|)
argument_list|,
name|mbox
argument_list|,
name|SLOT
argument_list|(
name|exec
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|s3
operator|->
name|addTransition
argument_list|(
name|s1h
argument_list|)
expr_stmt|;
name|machine
operator|.
name|addState
argument_list|(
name|s3
argument_list|)
expr_stmt|;
name|s1
operator|->
name|addTransition
argument_list|(
name|interruptButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|s3
argument_list|)
expr_stmt|;
comment|//![3]
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
