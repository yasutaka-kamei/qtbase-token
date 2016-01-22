begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"diagramitem.h"
end_include
begin_include
include|#
directive|include
file|"arrow.h"
end_include
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QGraphicsSceneContextMenuEvent>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|DiagramItem
name|DiagramItem
operator|::
name|DiagramItem
parameter_list|(
name|DiagramType
name|diagramType
parameter_list|,
name|QMenu
modifier|*
name|contextMenu
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsPolygonItem
argument_list|(
name|parent
argument_list|)
block|{
name|myDiagramType
operator|=
name|diagramType
expr_stmt|;
name|myContextMenu
operator|=
name|contextMenu
expr_stmt|;
name|QPainterPath
name|path
decl_stmt|;
switch|switch
condition|(
name|myDiagramType
condition|)
block|{
case|case
name|StartEnd
case|:
name|path
operator|.
name|moveTo
argument_list|(
literal|200
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|path
operator|.
name|arcTo
argument_list|(
literal|150
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|0
argument_list|,
literal|90
argument_list|)
expr_stmt|;
name|path
operator|.
name|arcTo
argument_list|(
literal|50
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|90
argument_list|,
literal|90
argument_list|)
expr_stmt|;
name|path
operator|.
name|arcTo
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|180
argument_list|,
literal|90
argument_list|)
expr_stmt|;
name|path
operator|.
name|arcTo
argument_list|(
literal|150
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|270
argument_list|,
literal|90
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
literal|200
argument_list|,
literal|25
argument_list|)
expr_stmt|;
name|myPolygon
operator|=
name|path
operator|.
name|toFillPolygon
argument_list|()
expr_stmt|;
break|break;
case|case
name|Conditional
case|:
name|myPolygon
operator|<<
name|QPointF
argument_list|(
operator|-
literal|100
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|0
argument_list|,
operator|-
literal|100
argument_list|)
operator|<<
name|QPointF
argument_list|(
operator|-
literal|100
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Step
case|:
name|myPolygon
operator|<<
name|QPointF
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|100
argument_list|,
operator|-
literal|100
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
name|QPointF
argument_list|(
operator|-
literal|100
argument_list|,
literal|100
argument_list|)
operator|<<
name|QPointF
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|)
expr_stmt|;
break|break;
default|default:
name|myPolygon
operator|<<
name|QPointF
argument_list|(
operator|-
literal|120
argument_list|,
operator|-
literal|80
argument_list|)
operator|<<
name|QPointF
argument_list|(
operator|-
literal|70
argument_list|,
literal|80
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|120
argument_list|,
literal|80
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|70
argument_list|,
operator|-
literal|80
argument_list|)
operator|<<
name|QPointF
argument_list|(
operator|-
literal|120
argument_list|,
operator|-
literal|80
argument_list|)
expr_stmt|;
break|break;
block|}
name|setPolygon
argument_list|(
name|myPolygon
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsMovable
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsSelectable
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemSendsGeometryChanges
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|removeArrow
name|void
name|DiagramItem
operator|::
name|removeArrow
parameter_list|(
name|Arrow
modifier|*
name|arrow
parameter_list|)
block|{
name|int
name|index
init|=
name|arrows
operator|.
name|indexOf
argument_list|(
name|arrow
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
name|arrows
operator|.
name|removeAt
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|removeArrows
name|void
name|DiagramItem
operator|::
name|removeArrows
parameter_list|()
block|{
foreach|foreach
control|(
name|Arrow
modifier|*
name|arrow
decl|,
name|arrows
control|)
block|{
name|arrow
operator|->
name|startItem
argument_list|()
operator|->
name|removeArrow
argument_list|(
name|arrow
argument_list|)
expr_stmt|;
name|arrow
operator|->
name|endItem
argument_list|()
operator|->
name|removeArrow
argument_list|(
name|arrow
argument_list|)
expr_stmt|;
name|scene
argument_list|()
operator|->
name|removeItem
argument_list|(
name|arrow
argument_list|)
expr_stmt|;
operator|delete
name|arrow
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|addArrow
name|void
name|DiagramItem
operator|::
name|addArrow
parameter_list|(
name|Arrow
modifier|*
name|arrow
parameter_list|)
block|{
name|arrows
operator|.
name|append
argument_list|(
name|arrow
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|image
name|QPixmap
name|DiagramItem
operator|::
name|image
parameter_list|()
specifier|const
block|{
name|QPixmap
name|pixmap
argument_list|(
literal|250
argument_list|,
literal|250
argument_list|)
decl_stmt|;
name|pixmap
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|pixmap
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|8
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
literal|125
argument_list|,
literal|125
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPolyline
argument_list|(
name|myPolygon
argument_list|)
expr_stmt|;
return|return
name|pixmap
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
DECL|function|contextMenuEvent
name|void
name|DiagramItem
operator|::
name|contextMenuEvent
parameter_list|(
name|QGraphicsSceneContextMenuEvent
modifier|*
name|event
parameter_list|)
block|{
name|scene
argument_list|()
operator|->
name|clearSelection
argument_list|()
expr_stmt|;
name|setSelected
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|myContextMenu
operator|->
name|exec
argument_list|(
name|event
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|itemChange
name|QVariant
name|DiagramItem
operator|::
name|itemChange
parameter_list|(
name|GraphicsItemChange
name|change
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|change
operator|==
name|QGraphicsItem
operator|::
name|ItemPositionChange
condition|)
block|{
foreach|foreach
control|(
name|Arrow
modifier|*
name|arrow
decl|,
name|arrows
control|)
block|{
name|arrow
operator|->
name|updatePosition
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|value
return|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
end_unit
