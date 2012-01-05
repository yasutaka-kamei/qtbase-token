begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DIAGRAMITEM_H
end_ifndef
begin_define
DECL|macro|DIAGRAMITEM_H
define|#
directive|define
name|DIAGRAMITEM_H
end_define
begin_include
include|#
directive|include
file|<QGraphicsPixmapItem>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsItem
name|class
name|QGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsScene
name|class
name|QGraphicsScene
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextEdit
name|class
name|QTextEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneMouseEvent
name|class
name|QGraphicsSceneMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneContextMenuEvent
name|class
name|QGraphicsSceneContextMenuEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionGraphicsItem
name|class
name|QStyleOptionGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPolygonF
name|class
name|QPolygonF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|Arrow
name|class
name|Arrow
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|DiagramItem
range|:
name|public
name|QGraphicsPolygonItem
block|{
name|public
operator|:
expr|enum
block|{
name|Type
operator|=
name|UserType
operator|+
literal|15
block|}
block|;     enum
name|DiagramType
block|{
name|Step
block|,
name|Conditional
block|,
name|StartEnd
block|,
name|Io
block|}
block|;
name|DiagramItem
argument_list|(
argument|DiagramType diagramType
argument_list|,
argument|QMenu *contextMenu
argument_list|,
argument|QGraphicsItem *parent =
literal|0
argument_list|,
argument|QGraphicsScene *scene =
literal|0
argument_list|)
block|;
name|void
name|removeArrow
argument_list|(
name|Arrow
operator|*
name|arrow
argument_list|)
block|;
name|void
name|removeArrows
argument_list|()
block|;
name|DiagramType
name|diagramType
argument_list|()
specifier|const
block|{
return|return
name|myDiagramType
return|;
block|}
name|QPolygonF
name|polygon
argument_list|()
specifier|const
block|{
return|return
name|myPolygon
return|;
block|}
name|void
name|addArrow
argument_list|(
name|Arrow
operator|*
name|arrow
argument_list|)
block|;
name|QPixmap
name|image
argument_list|()
specifier|const
block|;
name|int
name|type
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|protected
operator|:
name|void
name|contextMenuEvent
argument_list|(
name|QGraphicsSceneContextMenuEvent
operator|*
name|event
argument_list|)
block|;
name|QVariant
name|itemChange
argument_list|(
argument|GraphicsItemChange change
argument_list|,
argument|const QVariant&value
argument_list|)
block|;
name|private
operator|:
name|DiagramType
name|myDiagramType
block|;
name|QPolygonF
name|myPolygon
block|;
name|QMenu
operator|*
name|myContextMenu
block|;
name|QList
operator|<
name|Arrow
operator|*
operator|>
name|arrows
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
