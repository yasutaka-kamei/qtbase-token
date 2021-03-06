begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ROBOT_H
end_ifndef
begin_define
DECL|macro|ROBOT_H
define|#
directive|define
name|ROBOT_H
end_define
begin_include
include|#
directive|include
file|<QGraphicsItem>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsSceneMouseEvent
name|class
name|QGraphicsSceneMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QParallelAnimationGroup
name|class
name|QParallelAnimationGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|RobotPart
range|:
name|public
name|QGraphicsObject
block|{
name|public
operator|:
name|RobotPart
argument_list|(
name|QGraphicsItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|protected
operator|:
name|void
name|dragEnterEvent
argument_list|(
argument|QGraphicsSceneDragDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dragLeaveEvent
argument_list|(
argument|QGraphicsSceneDragDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dropEvent
argument_list|(
argument|QGraphicsSceneDragDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QColor
name|color
block|;
name|bool
name|dragOver
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
name|class
name|RobotHead
range|:
name|public
name|RobotPart
block|{
name|public
operator|:
name|RobotHead
argument_list|(
name|QGraphicsItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QRectF
name|boundingRect
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget =
literal|0
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|void
name|dragEnterEvent
argument_list|(
argument|QGraphicsSceneDragDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|dropEvent
argument_list|(
argument|QGraphicsSceneDragDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QPixmap
name|pixmap
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|class
name|RobotTorso
range|:
name|public
name|RobotPart
block|{
name|public
operator|:
name|RobotTorso
argument_list|(
name|QGraphicsItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QRectF
name|boundingRect
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget =
literal|0
argument_list|)
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
name|class
name|RobotLimb
range|:
name|public
name|RobotPart
block|{
name|public
operator|:
name|RobotLimb
argument_list|(
name|QGraphicsItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QRectF
name|boundingRect
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget =
literal|0
argument_list|)
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
name|class
name|Robot
range|:
name|public
name|RobotPart
block|{
name|public
operator|:
name|Robot
argument_list|(
name|QGraphicsItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QRectF
name|boundingRect
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget =
literal|0
argument_list|)
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [4]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
