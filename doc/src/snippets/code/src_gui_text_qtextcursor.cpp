begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_expr_stmt
name|cursor
operator|.
name|clearSelection
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|NextWord
argument_list|,
name|QTextCursor
operator|::
name|KeepAnchor
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hello World"
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
DECL|variable|img
name|QImage
name|img
init|=
operator|...
name|textDocument
operator|->
name|addResource
argument_list|(
name|QTextDocument
operator|::
name|ImageResource
argument_list|,
name|QUrl
argument_list|(
literal|"myimage"
argument_list|)
argument_list|,
name|img
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|cursor
operator|.
name|insertImage
argument_list|(
literal|"myimage"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function_decl
name|QTextCursor
name|cursor
parameter_list|(
name|textDocument
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hello"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cursor
operator|.
name|insertText
argument_list|(
literal|"World"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|textDocument
operator|->
name|undo
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function_decl
name|QTextCursor
name|cursor
parameter_list|(
name|textDocument
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hello"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cursor
operator|.
name|insertText
argument_list|(
literal|"World"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|...
name|cursor
operator|.
name|joinPreviousEditBlock
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hey"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|textDocument
operator|->
name|undo
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [3]
end_comment
end_unit
