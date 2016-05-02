begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Kai Pastor ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QFileDialog>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QPdfWriter>
end_include
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
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QString
name|filepath
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
literal|nullptr
argument_list|,
literal|"Save File"
argument_list|,
literal|""
argument_list|,
literal|"PDF files (*.pdf)"
argument_list|)
decl_stmt|;
if|if
condition|(
name|filepath
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|1
return|;
name|QPdfWriter
name|writer
argument_list|(
name|filepath
argument_list|)
decl_stmt|;
name|writer
operator|.
name|setPageSize
argument_list|(
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|A4
argument_list|)
argument_list|)
expr_stmt|;
name|writer
operator|.
name|setResolution
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|moveTo
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|1000
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|1000
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|0
argument_list|,
literal|800
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|500
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|800
argument_list|,
literal|900
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|300
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|QPen
name|pen
decl_stmt|;
name|pen
operator|.
name|setWidth
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|pen
operator|.
name|setJoinStyle
argument_list|(
name|Qt
operator|::
name|MiterJoin
argument_list|)
expr_stmt|;
comment|// The black path on the first page must always be visible in the PDF viewer.
name|QPainter
name|p
argument_list|(
operator|&
name|writer
argument_list|)
decl_stmt|;
name|pen
operator|.
name|setMiterLimit
argument_list|(
literal|6.0
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|pen
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
comment|// If a miter limit below 1.0 is written to the PDF,
comment|// broken PDF viewers may not show the red path on the second page.
name|writer
operator|.
name|newPage
argument_list|()
expr_stmt|;
name|pen
operator|.
name|setMiterLimit
argument_list|(
literal|0.6
argument_list|)
expr_stmt|;
name|pen
operator|.
name|setColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|pen
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
