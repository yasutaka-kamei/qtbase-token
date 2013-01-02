begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|"tetrixpiece.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|setRandomShape
name|void
name|TetrixPiece
operator|::
name|setRandomShape
parameter_list|()
block|{
name|setShape
argument_list|(
name|TetrixShape
argument_list|(
name|qrand
argument_list|()
operator|%
literal|7
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|setShape
name|void
name|TetrixPiece
operator|::
name|setShape
parameter_list|(
name|TetrixShape
name|shape
parameter_list|)
block|{
specifier|static
specifier|const
name|int
name|coordsTable
index|[
literal|8
index|]
index|[
literal|4
index|]
index|[
literal|2
index|]
init|=
block|{
block|{
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
block|,
block|{
block|{
literal|0
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|1
block|}
block|}
block|,
block|{
block|{
literal|0
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|1
block|,
literal|0
block|}
block|,
block|{
literal|1
block|,
literal|1
block|}
block|}
block|,
block|{
block|{
literal|0
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|2
block|}
block|}
block|,
block|{
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|1
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|1
block|}
block|}
block|,
block|{
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|1
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|1
block|}
block|,
block|{
literal|1
block|,
literal|1
block|}
block|}
block|,
block|{
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|0
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|1
block|}
block|}
block|,
block|{
block|{
literal|1
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|0
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|1
block|}
block|}
block|}
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
literal|4
condition|;
name|i
operator|++
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
literal|2
condition|;
operator|++
name|j
control|)
name|coords
index|[
name|i
index|]
index|[
name|j
index|]
operator|=
name|coordsTable
index|[
name|shape
index|]
index|[
name|i
index|]
index|[
name|j
index|]
expr_stmt|;
block|}
name|pieceShape
operator|=
name|shape
expr_stmt|;
comment|//! [1] //! [2]
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|minX
name|int
name|TetrixPiece
operator|::
name|minX
parameter_list|()
specifier|const
block|{
name|int
name|min
init|=
name|coords
index|[
literal|0
index|]
index|[
literal|0
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
name|min
operator|=
name|qMin
argument_list|(
name|min
argument_list|,
name|coords
index|[
name|i
index|]
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
name|min
return|;
block|}
end_function
begin_function
DECL|function|maxX
name|int
name|TetrixPiece
operator|::
name|maxX
parameter_list|()
specifier|const
comment|//! [3] //! [4]
block|{
name|int
name|max
init|=
name|coords
index|[
literal|0
index|]
index|[
literal|0
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
name|max
operator|=
name|qMax
argument_list|(
name|max
argument_list|,
name|coords
index|[
name|i
index|]
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
name|max
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|minY
name|int
name|TetrixPiece
operator|::
name|minY
parameter_list|()
specifier|const
block|{
name|int
name|min
init|=
name|coords
index|[
literal|0
index|]
index|[
literal|1
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
name|min
operator|=
name|qMin
argument_list|(
name|min
argument_list|,
name|coords
index|[
name|i
index|]
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
return|return
name|min
return|;
block|}
end_function
begin_function
DECL|function|maxY
name|int
name|TetrixPiece
operator|::
name|maxY
parameter_list|()
specifier|const
comment|//! [5] //! [6]
block|{
name|int
name|max
init|=
name|coords
index|[
literal|0
index|]
index|[
literal|1
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
name|max
operator|=
name|qMax
argument_list|(
name|max
argument_list|,
name|coords
index|[
name|i
index|]
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
return|return
name|max
return|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|rotatedLeft
name|TetrixPiece
name|TetrixPiece
operator|::
name|rotatedLeft
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|pieceShape
operator|==
name|SquareShape
condition|)
return|return
operator|*
name|this
return|;
name|TetrixPiece
name|result
decl_stmt|;
name|result
operator|.
name|pieceShape
operator|=
name|pieceShape
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|result
operator|.
name|setX
argument_list|(
name|i
argument_list|,
name|y
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setY
argument_list|(
name|i
argument_list|,
operator|-
name|x
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//! [7]
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|rotatedRight
name|TetrixPiece
name|TetrixPiece
operator|::
name|rotatedRight
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|pieceShape
operator|==
name|SquareShape
condition|)
return|return
operator|*
name|this
return|;
name|TetrixPiece
name|result
decl_stmt|;
name|result
operator|.
name|pieceShape
operator|=
name|pieceShape
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|result
operator|.
name|setX
argument_list|(
name|i
argument_list|,
operator|-
name|y
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setY
argument_list|(
name|i
argument_list|,
name|x
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//! [9]
return|return
name|result
return|;
block|}
end_function
end_unit
