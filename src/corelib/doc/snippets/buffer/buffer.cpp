begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<QPalette>
end_include
begin_function
DECL|function|main_snippet
specifier|static
name|void
name|main_snippet
parameter_list|()
block|{
comment|//! [0]
name|QBuffer
name|buffer
decl_stmt|;
name|char
name|ch
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QBuffer
operator|::
name|ReadWrite
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|write
argument_list|(
literal|"Qt rocks!"
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|getChar
argument_list|(
operator|&
name|ch
argument_list|)
expr_stmt|;
comment|// ch == 'Q'
name|buffer
operator|.
name|getChar
argument_list|(
operator|&
name|ch
argument_list|)
expr_stmt|;
comment|// ch == 't'
name|buffer
operator|.
name|getChar
argument_list|(
operator|&
name|ch
argument_list|)
expr_stmt|;
comment|// ch == ' '
name|buffer
operator|.
name|getChar
argument_list|(
operator|&
name|ch
argument_list|)
expr_stmt|;
comment|// ch == 'r'
comment|//! [0]
block|}
end_function
begin_function
DECL|function|write_datastream_snippets
specifier|static
name|void
name|write_datastream_snippets
parameter_list|()
block|{
comment|//! [1]
name|QByteArray
name|byteArray
decl_stmt|;
name|QBuffer
name|buffer
argument_list|(
operator|&
name|byteArray
argument_list|)
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|QDataStream
name|out
argument_list|(
operator|&
name|buffer
argument_list|)
decl_stmt|;
name|out
operator|<<
name|QApplication
operator|::
name|palette
argument_list|()
expr_stmt|;
comment|//! [1]
block|}
end_function
begin_function
DECL|function|read_datastream_snippets
specifier|static
name|void
name|read_datastream_snippets
parameter_list|()
block|{
name|QByteArray
name|byteArray
decl_stmt|;
comment|//! [2]
name|QPalette
name|palette
decl_stmt|;
name|QBuffer
name|buffer
argument_list|(
operator|&
name|byteArray
argument_list|)
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QDataStream
name|in
argument_list|(
operator|&
name|buffer
argument_list|)
decl_stmt|;
name|in
operator|>>
name|palette
expr_stmt|;
comment|//! [2]
block|}
end_function
begin_function
DECL|function|bytearray_ptr_ctor_snippet
specifier|static
name|void
name|bytearray_ptr_ctor_snippet
parameter_list|()
block|{
comment|//! [3]
name|QByteArray
name|byteArray
argument_list|(
literal|"abc"
argument_list|)
decl_stmt|;
name|QBuffer
name|buffer
argument_list|(
operator|&
name|byteArray
argument_list|)
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|seek
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|write
argument_list|(
literal|"def"
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|close
argument_list|()
expr_stmt|;
comment|// byteArray == "abcdef"
comment|//! [3]
block|}
end_function
begin_function
DECL|function|setBuffer_snippet
specifier|static
name|void
name|setBuffer_snippet
parameter_list|()
block|{
comment|//! [4]
name|QByteArray
name|byteArray
argument_list|(
literal|"abc"
argument_list|)
decl_stmt|;
name|QBuffer
name|buffer
decl_stmt|;
name|buffer
operator|.
name|setBuffer
argument_list|(
operator|&
name|byteArray
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|seek
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|write
argument_list|(
literal|"def"
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|close
argument_list|()
expr_stmt|;
comment|// byteArray == "abcdef"
comment|//! [4]
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
name|main_snippet
argument_list|()
expr_stmt|;
name|bytearray_ptr_ctor_snippet
argument_list|()
expr_stmt|;
name|write_datastream_snippets
argument_list|()
expr_stmt|;
name|read_datastream_snippets
argument_list|()
expr_stmt|;
name|setBuffer_snippet
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
