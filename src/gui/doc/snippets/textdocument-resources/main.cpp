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
decl_stmt|;
name|QTextDocument
modifier|*
name|document
init|=
operator|new
name|QTextDocument
argument_list|(
name|editor
argument_list|)
decl_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|document
argument_list|)
decl_stmt|;
name|QImage
name|image
argument_list|(
literal|64
argument_list|,
literal|64
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|image
operator|.
name|fill
argument_list|(
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|160
argument_list|,
literal|128
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [Adding a resource]
name|document
operator|->
name|addResource
argument_list|(
name|QTextDocument
operator|::
name|ImageResource
argument_list|,
name|QUrl
argument_list|(
literal|"mydata://image.png"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|image
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [Adding a resource]
comment|//! [Inserting an image with a cursor]
name|QTextImageFormat
name|imageFormat
decl_stmt|;
name|imageFormat
operator|.
name|setName
argument_list|(
literal|"mydata://image.png"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertImage
argument_list|(
name|imageFormat
argument_list|)
expr_stmt|;
comment|//! [Inserting an image with a cursor]
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Code less. Create more."
argument_list|)
expr_stmt|;
name|editor
operator|->
name|setDocument
argument_list|(
name|document
argument_list|)
expr_stmt|;
name|editor
operator|->
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Text Document Images"
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
comment|//! [Inserting an image using HTML]
name|editor
operator|->
name|append
argument_list|(
literal|"<img src=\"mydata://image.png\" />"
argument_list|)
expr_stmt|;
comment|//! [Inserting an image using HTML]
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
