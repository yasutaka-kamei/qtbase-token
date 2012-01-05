begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|QMouseEvent
name|event
argument_list|(
name|QEvent
operator|::
name|MouseButtonPress
argument_list|,
name|pos
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|mainWindow
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|quitButton
name|QPushButton
modifier|*
name|quitButton
init|=
operator|new
name|QPushButton
argument_list|(
literal|"Quit"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|connect
argument_list|(
name|quitButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
operator|&
name|app
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_foreach
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|path
decl|,
name|app
operator|.
name|libraryPaths
argument_list|()
control|)
DECL|variable|path
name|do_something
argument_list|(
name|path
argument_list|)
expr_stmt|;
end_foreach
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function_decl
name|bool
name|myEventFilter
parameter_list|(
name|void
modifier|*
name|message
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|global_ptr
specifier|static
name|int
modifier|*
name|global_ptr
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|cleanup_ptr
specifier|static
name|void
name|cleanup_ptr
parameter_list|()
block|{
operator|delete
index|[]
name|global_ptr
expr_stmt|;
name|global_ptr
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init_ptr
name|void
name|init_ptr
parameter_list|()
block|{
name|global_ptr
operator|=
operator|new
name|int
index|[
literal|100
index|]
expr_stmt|;
comment|// allocate data
name|qAddPostRoutine
argument_list|(
name|cleanup_ptr
argument_list|)
expr_stmt|;
comment|// delete later
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_class
DECL|class|MyPrivateInitStuff
class|class
name|MyPrivateInitStuff
super|:
specifier|public
name|QObject
block|{
public|public:
DECL|function|initStuff
specifier|static
name|MyPrivateInitStuff
modifier|*
name|initStuff
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
block|{
if|if
condition|(
operator|!
name|p
condition|)
name|p
operator|=
operator|new
name|MyPrivateInitStuff
argument_list|(
name|parent
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
DECL|function|~MyPrivateInitStuff
name|~
name|MyPrivateInitStuff
parameter_list|()
block|{
comment|// cleanup goes here
block|}
private|private:
DECL|function|MyPrivateInitStuff
name|MyPrivateInitStuff
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{
comment|// initialization goes here
block|}
DECL|member|p
name|MyPrivateInitStuff
modifier|*
name|p
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function_decl
specifier|static
specifier|inline
name|QString
name|tr
parameter_list|(
specifier|const
name|char
modifier|*
name|sourceText
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
specifier|inline
name|QString
name|trUtf8
parameter_list|(
specifier|const
name|char
modifier|*
name|sourceText
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_class
DECL|class|MyMfcView
class|class
name|MyMfcView
super|:
specifier|public
name|CView
block|{
name|Q_DECLARE_TR_FUNCTIONS
parameter_list|(
name|MyMfcView
parameter_list|)
specifier|public
private|:
name|MyMfcView
parameter_list|()
constructor_decl|;
operator|...
block|}
class|;
end_class
begin_comment
comment|//! [7]
end_comment
end_unit
