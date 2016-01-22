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
DECL|function|tr
name|QString
name|tr
parameter_list|(
specifier|const
name|char
modifier|*
name|text
parameter_list|)
block|{
return|return
name|QApplication
operator|::
name|translate
argument_list|(
name|text
argument_list|,
name|text
argument_list|)
return|;
block|}
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
name|argv
index|[]
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
name|QTextEdit
modifier|*
name|editor
init|=
operator|new
name|QTextEdit
argument_list|()
decl_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|editor
operator|->
name|textCursor
argument_list|()
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|plainFormat
argument_list|(
name|cursor
operator|.
name|charFormat
argument_list|()
argument_list|)
decl_stmt|;
name|QTextCharFormat
name|headingFormat
init|=
name|plainFormat
decl_stmt|;
name|headingFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
name|headingFormat
operator|.
name|setFontPointSize
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|emphasisFormat
init|=
name|plainFormat
decl_stmt|;
name|emphasisFormat
operator|.
name|setFontItalic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|qtFormat
init|=
name|plainFormat
decl_stmt|;
name|qtFormat
operator|.
name|setForeground
argument_list|(
name|QColor
argument_list|(
literal|"#990000"
argument_list|)
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|underlineFormat
init|=
name|plainFormat
decl_stmt|;
name|underlineFormat
operator|.
name|setFontUnderline
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [0]
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"Character formats"
argument_list|)
argument_list|,
name|headingFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"Text can be displayed in a variety of "
literal|"different character formats. "
argument_list|)
argument_list|,
name|plainFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"We can emphasize text by "
argument_list|)
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"making it italic"
argument_list|)
argument_list|,
name|emphasisFormat
argument_list|)
expr_stmt|;
comment|//! [0]
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|", give it a "
argument_list|)
argument_list|,
name|plainFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"different color "
argument_list|)
argument_list|,
name|qtFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"to the default text color, "
argument_list|)
argument_list|,
name|plainFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"underline it"
argument_list|)
argument_list|,
name|underlineFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|", and use many other effects."
argument_list|)
argument_list|,
name|plainFormat
argument_list|)
expr_stmt|;
name|editor
operator|->
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Text Document Character Formats"
argument_list|)
argument_list|)
expr_stmt|;
name|editor
operator|->
name|resize
argument_list|(
literal|320
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|editor
operator|->
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
end_unit
