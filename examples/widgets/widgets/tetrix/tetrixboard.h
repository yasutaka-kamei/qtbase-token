begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TETRIXBOARD_H
end_ifndef
begin_define
DECL|macro|TETRIXBOARD_H
define|#
directive|define
name|TETRIXBOARD_H
end_define
begin_include
include|#
directive|include
file|<QBasicTimer>
end_include
begin_include
include|#
directive|include
file|<QFrame>
end_include
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_include
include|#
directive|include
file|"tetrixpiece.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|TetrixBoard
range|:
name|public
name|QFrame
block|{
name|Q_OBJECT
name|public
operator|:
name|TetrixBoard
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setNextPieceLabel
argument_list|(
name|QLabel
operator|*
name|label
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|public
name|slots
operator|:
name|void
name|start
argument_list|()
block|;
name|void
name|pause
argument_list|()
block|;
name|signals
operator|:
name|void
name|scoreChanged
argument_list|(
argument|int score
argument_list|)
block|;
name|void
name|levelChanged
argument_list|(
argument|int level
argument_list|)
block|;
name|void
name|linesRemovedChanged
argument_list|(
argument|int numLines
argument_list|)
block|;
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|event
argument_list|)
block|;
comment|//! [0]
comment|//! [1]
name|private
operator|:
expr|enum
block|{
name|BoardWidth
operator|=
literal|10
block|,
name|BoardHeight
operator|=
literal|22
block|}
block|;
name|TetrixShape
operator|&
name|shapeAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|{
return|return
name|board
index|[
operator|(
name|y
operator|*
name|BoardWidth
operator|)
operator|+
name|x
index|]
return|;
block|}
name|int
name|timeoutTime
argument_list|()
block|{
return|return
literal|1000
operator|/
operator|(
literal|1
operator|+
name|level
operator|)
return|;
block|}
name|int
name|squareWidth
argument_list|()
block|{
return|return
name|contentsRect
argument_list|()
operator|.
name|width
argument_list|()
operator|/
name|BoardWidth
return|;
block|}
name|int
name|squareHeight
argument_list|()
block|{
return|return
name|contentsRect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|BoardHeight
return|;
block|}
name|void
name|clearBoard
argument_list|()
block|;
name|void
name|dropDown
argument_list|()
block|;
name|void
name|oneLineDown
argument_list|()
block|;
name|void
name|pieceDropped
argument_list|(
argument|int dropHeight
argument_list|)
block|;
name|void
name|removeFullLines
argument_list|()
block|;
name|void
name|newPiece
argument_list|()
block|;
name|void
name|showNextPiece
argument_list|()
block|;
name|bool
name|tryMove
argument_list|(
argument|const TetrixPiece&newPiece
argument_list|,
argument|int newX
argument_list|,
argument|int newY
argument_list|)
block|;
name|void
name|drawSquare
argument_list|(
argument|QPainter&painter
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|TetrixShape shape
argument_list|)
block|;
name|QBasicTimer
name|timer
block|;
name|QPointer
operator|<
name|QLabel
operator|>
name|nextPieceLabel
block|;
name|bool
name|isStarted
block|;
name|bool
name|isPaused
block|;
name|bool
name|isWaitingAfterLine
block|;
name|TetrixPiece
name|curPiece
block|;
name|TetrixPiece
name|nextPiece
block|;
name|int
name|curX
block|;
name|int
name|curY
block|;
name|int
name|numLinesRemoved
block|;
name|int
name|numPiecesDropped
block|;
name|int
name|score
block|;
name|int
name|level
block|;
name|TetrixShape
name|board
index|[
name|BoardWidth
operator|*
name|BoardHeight
index|]
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
