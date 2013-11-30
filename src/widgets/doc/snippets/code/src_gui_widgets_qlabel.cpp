begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|label
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|label
operator|->
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|Panel
operator||
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|label
operator|->
name|setText
argument_list|(
literal|"first line\nsecond line"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|label
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignBottom
operator||
name|Qt
operator|::
name|AlignRight
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
DECL|variable|phoneEdit
name|QLineEdit
modifier|*
name|phoneEdit
init|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|phoneLabel
name|QLabel
modifier|*
name|phoneLabel
init|=
operator|new
name|QLabel
argument_list|(
literal|"&Phone:"
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|phoneLabel
operator|->
name|setBuddy
argument_list|(
name|phoneEdit
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|nameEdit
name|QLineEdit
modifier|*
name|nameEdit
init|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|nameLabel
name|QLabel
modifier|*
name|nameLabel
init|=
operator|new
name|QLabel
argument_list|(
literal|"&Name:"
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|nameLabel
operator|->
name|setBuddy
argument_list|(
name|nameEdit
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|phoneEdit
name|QLineEdit
modifier|*
name|phoneEdit
init|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|phoneLabel
name|QLabel
modifier|*
name|phoneLabel
init|=
operator|new
name|QLabel
argument_list|(
literal|"&Phone:"
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|phoneLabel
operator|->
name|setBuddy
argument_list|(
name|phoneEdit
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// (layout setup not shown)
end_comment
begin_comment
comment|//! [2]
end_comment
end_unit
