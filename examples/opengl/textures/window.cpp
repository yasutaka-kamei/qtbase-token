begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"glwidget.h"
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumRows
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|NumColumns
condition|;
operator|++
name|j
control|)
block|{
name|QColor
name|clearColor
decl_stmt|;
name|clearColor
operator|.
name|setHsv
argument_list|(
operator|(
operator|(
name|i
operator|*
name|NumColumns
operator|)
operator|+
name|j
operator|)
operator|*
literal|255
operator|/
operator|(
name|NumRows
operator|*
name|NumColumns
operator|-
literal|1
operator|)
argument_list|,
literal|255
argument_list|,
literal|63
argument_list|)
expr_stmt|;
name|glWidgets
index|[
name|i
index|]
index|[
name|j
index|]
operator|=
operator|new
name|GLWidget
expr_stmt|;
name|glWidgets
index|[
name|i
index|]
index|[
name|j
index|]
operator|->
name|setClearColor
argument_list|(
name|clearColor
argument_list|)
expr_stmt|;
name|glWidgets
index|[
name|i
index|]
index|[
name|j
index|]
operator|->
name|rotateBy
argument_list|(
operator|+
literal|42
operator|*
literal|16
argument_list|,
operator|+
literal|42
operator|*
literal|16
argument_list|,
operator|-
literal|21
operator|*
literal|16
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|glWidgets
index|[
name|i
index|]
index|[
name|j
index|]
argument_list|,
name|i
argument_list|,
name|j
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|glWidgets
index|[
name|i
index|]
index|[
name|j
index|]
argument_list|,
operator|&
name|GLWidget
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
operator|&
name|Window
operator|::
name|setCurrentGlWidget
argument_list|)
expr_stmt|;
block|}
block|}
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|currentGlWidget
operator|=
name|glWidgets
index|[
literal|0
index|]
index|[
literal|0
index|]
expr_stmt|;
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|timer
argument_list|,
operator|&
name|QTimer
operator|::
name|timeout
argument_list|,
name|this
argument_list|,
operator|&
name|Window
operator|::
name|rotateOneStep
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Textures"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setCurrentGlWidget
name|void
name|Window
operator|::
name|setCurrentGlWidget
parameter_list|()
block|{
name|currentGlWidget
operator|=
name|qobject_cast
argument_list|<
name|GLWidget
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rotateOneStep
name|void
name|Window
operator|::
name|rotateOneStep
parameter_list|()
block|{
if|if
condition|(
name|currentGlWidget
condition|)
name|currentGlWidget
operator|->
name|rotateBy
argument_list|(
operator|+
literal|2
operator|*
literal|16
argument_list|,
operator|+
literal|2
operator|*
literal|16
argument_list|,
operator|-
literal|1
operator|*
literal|16
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
