begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"chip.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_constructor
DECL|function|Chip
name|Chip
operator|::
name|Chip
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|this
operator|->
name|x
operator|=
name|x
expr_stmt|;
name|this
operator|->
name|y
operator|=
name|y
expr_stmt|;
name|this
operator|->
name|color
operator|=
name|color
expr_stmt|;
name|setZValue
argument_list|(
operator|(
name|x
operator|+
name|y
operator|)
operator|%
literal|2
argument_list|)
expr_stmt|;
name|setFlags
argument_list|(
name|ItemIsSelectable
operator||
name|ItemIsMovable
argument_list|)
expr_stmt|;
name|setAcceptHoverEvents
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|boundingRect
name|QRectF
name|Chip
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|110
argument_list|,
literal|70
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|shape
name|QPainterPath
name|Chip
operator|::
name|shape
parameter_list|()
specifier|const
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addRect
argument_list|(
literal|14
argument_list|,
literal|14
argument_list|,
literal|82
argument_list|,
literal|42
argument_list|)
expr_stmt|;
return|return
name|path
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|Chip
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|QColor
name|fillColor
init|=
operator|(
name|option
operator|->
name|state
operator|&
name|QStyle
operator|::
name|State_Selected
operator|)
condition|?
name|color
operator|.
name|dark
argument_list|(
literal|150
argument_list|)
else|:
name|color
decl_stmt|;
if|if
condition|(
name|option
operator|->
name|state
operator|&
name|QStyle
operator|::
name|State_MouseOver
condition|)
name|fillColor
operator|=
name|fillColor
operator|.
name|light
argument_list|(
literal|125
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|lod
init|=
name|option
operator|->
name|levelOfDetailFromTransform
argument_list|(
name|painter
operator|->
name|worldTransform
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|lod
operator|<
literal|0.2
condition|)
block|{
if|if
condition|(
name|lod
operator|<
literal|0.125
condition|)
block|{
name|painter
operator|->
name|fillRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|110
argument_list|,
literal|70
argument_list|)
argument_list|,
name|fillColor
argument_list|)
expr_stmt|;
return|return;
block|}
name|QBrush
name|b
init|=
name|painter
operator|->
name|brush
argument_list|()
decl_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|fillColor
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRect
argument_list|(
literal|13
argument_list|,
literal|13
argument_list|,
literal|97
argument_list|,
literal|57
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|b
argument_list|)
expr_stmt|;
return|return;
block|}
name|QPen
name|oldPen
init|=
name|painter
operator|->
name|pen
argument_list|()
decl_stmt|;
name|QPen
name|pen
init|=
name|oldPen
decl_stmt|;
name|int
name|width
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|option
operator|->
name|state
operator|&
name|QStyle
operator|::
name|State_Selected
condition|)
name|width
operator|+=
literal|2
expr_stmt|;
name|pen
operator|.
name|setWidth
argument_list|(
name|width
argument_list|)
expr_stmt|;
name|QBrush
name|b
init|=
name|painter
operator|->
name|brush
argument_list|()
decl_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|fillColor
operator|.
name|dark
argument_list|(
name|option
operator|->
name|state
operator|&
name|QStyle
operator|::
name|State_Sunken
condition|?
literal|120
else|:
literal|100
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRect
argument_list|(
name|QRect
argument_list|(
literal|14
argument_list|,
literal|14
argument_list|,
literal|79
argument_list|,
literal|39
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|b
argument_list|)
expr_stmt|;
if|if
condition|(
name|lod
operator|>=
literal|1
condition|)
block|{
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|gray
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawLine
argument_list|(
literal|15
argument_list|,
literal|54
argument_list|,
literal|94
argument_list|,
literal|54
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawLine
argument_list|(
literal|94
argument_list|,
literal|53
argument_list|,
literal|94
argument_list|,
literal|15
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Draw text
if|if
condition|(
name|lod
operator|>=
literal|2
condition|)
block|{
name|QFont
name|font
argument_list|(
literal|"Times"
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|font
operator|.
name|setStyleStrategy
argument_list|(
name|QFont
operator|::
name|ForceOutline
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|scale
argument_list|(
literal|0.1
argument_list|,
literal|0.1
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
literal|170
argument_list|,
literal|180
argument_list|,
name|QString
argument_list|(
literal|"Model: VSC-2000 (Very Small Chip) at %1x%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|x
argument_list|)
operator|.
name|arg
argument_list|(
name|y
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
literal|170
argument_list|,
literal|200
argument_list|,
name|QString
argument_list|(
literal|"Serial number: DLWR-WEER-123L-ZZ33-SDSJ"
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
literal|170
argument_list|,
literal|220
argument_list|,
name|QString
argument_list|(
literal|"Manufacturer: Chip Manufacturer"
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
comment|// Draw lines
name|QVarLengthArray
argument_list|<
name|QLineF
argument_list|,
literal|36
argument_list|>
name|lines
decl_stmt|;
if|if
condition|(
name|lod
operator|>=
literal|0.5
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|10
condition|;
name|i
operator|+=
operator|(
name|lod
operator|>
literal|0.5
condition|?
literal|1
else|:
literal|2
operator|)
control|)
block|{
name|lines
operator|.
name|append
argument_list|(
name|QLineF
argument_list|(
literal|18
operator|+
literal|7
operator|*
name|i
argument_list|,
literal|13
argument_list|,
literal|18
operator|+
literal|7
operator|*
name|i
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|lines
operator|.
name|append
argument_list|(
name|QLineF
argument_list|(
literal|18
operator|+
literal|7
operator|*
name|i
argument_list|,
literal|54
argument_list|,
literal|18
operator|+
literal|7
operator|*
name|i
argument_list|,
literal|62
argument_list|)
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|6
condition|;
name|i
operator|+=
operator|(
name|lod
operator|>
literal|0.5
condition|?
literal|1
else|:
literal|2
operator|)
control|)
block|{
name|lines
operator|.
name|append
argument_list|(
name|QLineF
argument_list|(
literal|5
argument_list|,
literal|18
operator|+
name|i
operator|*
literal|5
argument_list|,
literal|13
argument_list|,
literal|18
operator|+
name|i
operator|*
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|lines
operator|.
name|append
argument_list|(
name|QLineF
argument_list|(
literal|94
argument_list|,
literal|18
operator|+
name|i
operator|*
literal|5
argument_list|,
literal|102
argument_list|,
literal|18
operator|+
name|i
operator|*
literal|5
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|lod
operator|>=
literal|0.4
condition|)
block|{
specifier|const
name|QLineF
name|lineData
index|[]
init|=
block|{
name|QLineF
argument_list|(
literal|25
argument_list|,
literal|35
argument_list|,
literal|35
argument_list|,
literal|35
argument_list|)
block|,
name|QLineF
argument_list|(
literal|35
argument_list|,
literal|30
argument_list|,
literal|35
argument_list|,
literal|40
argument_list|)
block|,
name|QLineF
argument_list|(
literal|35
argument_list|,
literal|30
argument_list|,
literal|45
argument_list|,
literal|35
argument_list|)
block|,
name|QLineF
argument_list|(
literal|35
argument_list|,
literal|40
argument_list|,
literal|45
argument_list|,
literal|35
argument_list|)
block|,
name|QLineF
argument_list|(
literal|45
argument_list|,
literal|30
argument_list|,
literal|45
argument_list|,
literal|40
argument_list|)
block|,
name|QLineF
argument_list|(
literal|45
argument_list|,
literal|35
argument_list|,
literal|55
argument_list|,
literal|35
argument_list|)
block|}
decl_stmt|;
name|lines
operator|.
name|append
argument_list|(
name|lineData
argument_list|,
literal|6
argument_list|)
expr_stmt|;
block|}
name|painter
operator|->
name|drawLines
argument_list|(
name|lines
operator|.
name|data
argument_list|()
argument_list|,
name|lines
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
comment|// Draw red ink
if|if
condition|(
name|stuff
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
block|{
name|QPen
name|p
init|=
name|painter
operator|->
name|pen
argument_list|()
decl_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|SolidLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|RoundJoin
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|moveTo
argument_list|(
name|stuff
operator|.
name|first
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|stuff
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|path
operator|.
name|lineTo
argument_list|(
name|stuff
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|Chip
operator|::
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|QGraphicsItem
operator|::
name|mousePressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|Chip
operator|::
name|mouseMoveEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|modifiers
argument_list|()
operator|&
name|Qt
operator|::
name|ShiftModifier
condition|)
block|{
name|stuff
operator|<<
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
return|return;
block|}
name|QGraphicsItem
operator|::
name|mouseMoveEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|Chip
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|QGraphicsItem
operator|::
name|mouseReleaseEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
