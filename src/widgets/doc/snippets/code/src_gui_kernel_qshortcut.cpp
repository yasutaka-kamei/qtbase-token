begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_expr_stmt
name|shortcut
operator|=
operator|new
name|QShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+O"
argument_list|,
literal|"File|Open"
argument_list|)
argument_list|)
argument_list|,
name|parent
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|setKey
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// no signal emitted
end_comment
begin_expr_stmt
name|setKey
argument_list|(
name|QKeySequence
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// no signal emitted
end_comment
begin_expr_stmt
name|setKey
argument_list|(
literal|0x3b1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Greek letter alpha
end_comment
begin_expr_stmt
DECL|variable|Key_D
name|setKey
argument_list|(
name|Qt
operator|::
name|Key_D
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
DECL|variable|Key_D
comment|// 'd', e.g. to delete
end_comment
begin_expr_stmt
name|setKey
argument_list|(
literal|'q'
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// 'q', e.g. to quit
end_comment
begin_expr_stmt
name|setKey
argument_list|(
name|Qt
operator|::
name|CTRL
operator|+
name|Qt
operator|::
name|Key_P
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Ctrl+P, e.g. to print document
end_comment
begin_expr_stmt
name|setKey
argument_list|(
literal|"Ctrl+P"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Ctrl+P, e.g. to print document
end_comment
begin_comment
comment|//! [1]
end_comment
end_unit
