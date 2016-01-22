begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|validator
name|QValidator
modifier|*
name|validator
init|=
operator|new
name|QIntValidator
argument_list|(
literal|100
argument_list|,
literal|999
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|edit
name|QLineEdit
modifier|*
name|edit
init|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// the edit lineedit will only accept integers between 100 and 999
end_comment
begin_expr_stmt
name|edit
operator|->
name|setValidator
argument_list|(
name|validator
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
DECL|variable|str
name|QString
name|str
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|pos
name|int
name|pos
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QIntValidator
name|v
argument_list|(
literal|100
argument_list|,
literal|900
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|str
operator|=
literal|"1"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|str
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Intermediate
end_comment
begin_expr_stmt
name|str
operator|=
literal|"012"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|str
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Intermediate
end_comment
begin_expr_stmt
name|str
operator|=
literal|"123"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|str
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Acceptable
end_comment
begin_expr_stmt
name|str
operator|=
literal|"678"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|str
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Acceptable
end_comment
begin_expr_stmt
name|str
operator|=
literal|"999"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|str
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Intermediate
end_comment
begin_expr_stmt
name|str
operator|=
literal|"1234"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|str
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Invalid
end_comment
begin_expr_stmt
name|str
operator|=
literal|"-123"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|str
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Invalid
end_comment
begin_expr_stmt
name|str
operator|=
literal|"abc"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|str
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Invalid
end_comment
begin_expr_stmt
name|str
operator|=
literal|"12cm"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|str
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Invalid
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|pos
name|int
name|pos
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|s
operator|=
literal|"abc"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Invalid
end_comment
begin_expr_stmt
name|s
operator|=
literal|"5"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Intermediate
end_comment
begin_expr_stmt
name|s
operator|=
literal|"50"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Acceptable
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|// regexp: optional '-' followed by between 1 and 3 digits
end_comment
begin_decl_stmt
name|QRegExp
name|rx
argument_list|(
literal|"-?\\d{1,3}"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|validator
name|QValidator
modifier|*
name|validator
init|=
operator|new
name|QRegExpValidator
argument_list|(
name|rx
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|edit
name|QLineEdit
modifier|*
name|edit
init|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|edit
operator|->
name|setValidator
argument_list|(
name|validator
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|// integers 1 to 9999
end_comment
begin_decl_stmt
name|QRegExp
name|rx
argument_list|(
literal|"[1-9]\\d{0,3}"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// the validator treats the regexp as "^[1-9]\\d{0,3}$"
end_comment
begin_decl_stmt
name|QRegExpValidator
name|v
argument_list|(
name|rx
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|s
name|QString
name|s
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|pos
name|int
name|pos
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|s
operator|=
literal|"0"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Invalid
end_comment
begin_expr_stmt
name|s
operator|=
literal|"12345"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Invalid
end_comment
begin_expr_stmt
name|s
operator|=
literal|"1"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Acceptable
end_comment
begin_expr_stmt
name|rx
operator|.
name|setPattern
argument_list|(
literal|"\\S+"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// one or more non-whitespace characters
end_comment
begin_expr_stmt
name|v
operator|.
name|setRegExp
argument_list|(
name|rx
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|s
operator|=
literal|"myfile.txt"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Acceptable
end_comment
begin_expr_stmt
name|s
operator|=
literal|"my file.txt"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Invalid
end_comment
begin_comment
comment|// A, B or C followed by exactly five digits followed by W, X, Y or Z
end_comment
begin_expr_stmt
name|rx
operator|.
name|setPattern
argument_list|(
literal|"[A-C]\\d{5}[W-Z]"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|setRegExp
argument_list|(
name|rx
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|s
operator|=
literal|"a12345Z"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Invalid
end_comment
begin_expr_stmt
name|s
operator|=
literal|"A12345Z"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Acceptable
end_comment
begin_expr_stmt
name|s
operator|=
literal|"B12"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Intermediate
end_comment
begin_comment
comment|// match most 'readme' files
end_comment
begin_expr_stmt
name|rx
operator|.
name|setPattern
argument_list|(
literal|"read\\S?me(\.(txt|asc|1st))?"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|rx
operator|.
name|setCaseSensitive
argument_list|(
literal|false
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|setRegExp
argument_list|(
name|rx
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|s
operator|=
literal|"readme"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Acceptable
end_comment
begin_expr_stmt
name|s
operator|=
literal|"README.1ST"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Acceptable
end_comment
begin_expr_stmt
name|s
operator|=
literal|"read me.txt"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Invalid
end_comment
begin_expr_stmt
name|s
operator|=
literal|"readm"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Intermediate
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|// regexp: optional '-' followed by between 1 and 3 digits
end_comment
begin_decl_stmt
name|QRegularExpression
name|rx
argument_list|(
literal|"-?\\d{1,3}"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|validator
name|QValidator
modifier|*
name|validator
init|=
operator|new
name|QRegularExpressionValidator
argument_list|(
name|rx
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|edit
name|QLineEdit
modifier|*
name|edit
init|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|edit
operator|->
name|setValidator
argument_list|(
name|validator
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|// integers 1 to 9999
end_comment
begin_decl_stmt
name|QRegularExpression
name|re
argument_list|(
literal|"[1-9]\\d{0,3}"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// the validator treats the regexp as "^[1-9]\\d{0,3}$"
end_comment
begin_decl_stmt
name|QRegularExpressionValidator
name|v
argument_list|(
name|re
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|s
name|QString
name|s
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|pos
name|int
name|pos
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|s
operator|=
literal|"0"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Invalid
end_comment
begin_expr_stmt
name|s
operator|=
literal|"12345"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Invalid
end_comment
begin_expr_stmt
name|s
operator|=
literal|"1"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns Acceptable
end_comment
begin_expr_stmt
name|re
operator|.
name|setPattern
argument_list|(
literal|"\\S+"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// one or more non-whitespace characters
end_comment
begin_expr_stmt
name|v
operator|.
name|setRegularExpression
argument_list|(
name|re
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|s
operator|=
literal|"myfile.txt"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Acceptable
end_comment
begin_expr_stmt
name|s
operator|=
literal|"my file.txt"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Invalid
end_comment
begin_comment
comment|// A, B or C followed by exactly five digits followed by W, X, Y or Z
end_comment
begin_expr_stmt
name|re
operator|.
name|setPattern
argument_list|(
literal|"[A-C]\\d{5}[W-Z]"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|setRegularExpression
argument_list|(
name|re
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|s
operator|=
literal|"a12345Z"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Invalid
end_comment
begin_expr_stmt
name|s
operator|=
literal|"A12345Z"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Acceptable
end_comment
begin_expr_stmt
name|s
operator|=
literal|"B12"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Intermediate
end_comment
begin_comment
comment|// match most 'readme' files
end_comment
begin_expr_stmt
name|re
operator|.
name|setPattern
argument_list|(
literal|"read\\S?me(\.(txt|asc|1st))?"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|re
operator|.
name|setPatternOptions
argument_list|(
name|QRegularExpression
operator|::
name|CaseInsensitiveOption
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|setRegularExpression
argument_list|(
name|re
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|s
operator|=
literal|"readme"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Acceptable
end_comment
begin_expr_stmt
name|s
operator|=
literal|"README.1ST"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Acceptable
end_comment
begin_expr_stmt
name|s
operator|=
literal|"read me.txt"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Invalid
end_comment
begin_expr_stmt
name|s
operator|=
literal|"readm"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|v
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|pos
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns Intermediate
end_comment
begin_comment
comment|//! [6]
end_comment
end_unit
