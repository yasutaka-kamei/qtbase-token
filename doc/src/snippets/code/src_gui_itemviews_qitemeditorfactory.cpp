begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_macro
name|Q_PROPERTY
argument_list|(
argument|QColor color READ color WRITE setColor USER
literal|true
argument_list|)
end_macro
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|itemCreator
name|QItemEditorCreator
argument_list|<
name|MyEditor
argument_list|>
modifier|*
name|itemCreator
init|=
operator|new
name|QItemEditorCreator
argument_list|<
name|MyEditor
argument_list|>
argument_list|(
literal|"myProperty"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|factory
name|QItemEditorFactory
modifier|*
name|factory
init|=
operator|new
name|QItemEditorFactory
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|editorFactory
name|QItemEditorFactory
modifier|*
name|editorFactory
init|=
operator|new
name|QItemEditorFactory
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|creator
name|QItemEditorCreatorBase
modifier|*
name|creator
init|=
operator|new
name|QStandardItemEditorCreator
argument_list|<
name|MyFancyDateTimeEdit
argument_list|>
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|editorFactory
operator|->
name|registerEditor
argument_list|(
name|QVariant
operator|::
name|DateType
argument_list|,
name|creator
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_macro
name|Q_PROPERTY
argument_list|(
argument|QColor color READ color WRITE setColor USER
literal|true
argument_list|)
end_macro
begin_comment
comment|//! [3]
end_comment
end_unit
