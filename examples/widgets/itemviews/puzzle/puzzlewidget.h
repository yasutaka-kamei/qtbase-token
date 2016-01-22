begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PUZZLEWIDGET_H
end_ifndef
begin_define
DECL|macro|PUZZLEWIDGET_H
define|#
directive|define
name|PUZZLEWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<QPoint>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDragEnterEvent
name|class
name|QDragEnterEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDropEvent
name|class
name|QDropEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|PuzzleWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|PuzzleWidget
argument_list|(
argument|int imageSize
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|int
name|pieceSize
argument_list|()
specifier|const
block|;
name|int
name|imageSize
argument_list|()
specifier|const
block|;
name|signals
operator|:
name|void
name|puzzleCompleted
argument_list|()
block|;
name|protected
operator|:
name|void
name|dragEnterEvent
argument_list|(
argument|QDragEnterEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dragLeaveEvent
argument_list|(
argument|QDragLeaveEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dragMoveEvent
argument_list|(
argument|QDragMoveEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dropEvent
argument_list|(
argument|QDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|int
name|findPiece
argument_list|(
argument|const QRect&pieceRect
argument_list|)
specifier|const
block|;
specifier|const
name|QRect
name|targetSquare
argument_list|(
argument|const QPoint&position
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QPixmap
operator|>
name|piecePixmaps
block|;
name|QList
operator|<
name|QRect
operator|>
name|pieceRects
block|;
name|QList
operator|<
name|QPoint
operator|>
name|pieceLocations
block|;
name|QRect
name|highlightedRect
block|;
name|int
name|inPlace
block|;
name|int
name|m_ImageSize
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PUZZLEWIDGET_H
end_comment
end_unit
