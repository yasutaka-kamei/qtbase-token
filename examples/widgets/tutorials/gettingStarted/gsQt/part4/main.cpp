begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|Notepad
class|class
name|Notepad
super|:
specifier|public
name|QMainWindow
block|{
name|Q_OBJECT
public|public:
name|Notepad
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|load
parameter_list|()
function_decl|;
name|void
name|save
parameter_list|()
function_decl|;
private|private:
DECL|member|textEdit
name|QTextEdit
modifier|*
name|textEdit
decl_stmt|;
DECL|member|loadAction
name|QAction
modifier|*
name|loadAction
decl_stmt|;
DECL|member|saveAction
name|QAction
modifier|*
name|saveAction
decl_stmt|;
DECL|member|exitAction
name|QAction
modifier|*
name|exitAction
decl_stmt|;
DECL|member|fileMenu
name|QMenu
modifier|*
name|fileMenu
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|Notepad
name|Notepad
operator|::
name|Notepad
parameter_list|()
block|{
name|loadAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Load"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|saveAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Save"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|exitAction
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
name|connect
argument_list|(
name|loadAction
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
name|load
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAction
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
name|save
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAction
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
name|loadAction
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAction
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAction
argument_list|)
expr_stmt|;
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|setCentralWidget
argument_list|(
name|textEdit
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Notepad"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|load
name|void
name|Notepad
operator|::
name|load
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|save
name|void
name|Notepad
operator|::
name|save
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|Notepad
name|notepad
decl_stmt|;
name|notepad
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
