begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"graphwidget.h"
end_include
begin_include
include|#
directive|include
file|"edge.h"
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<QKeyEvent>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|GraphWidget
name|GraphWidget
operator|::
name|GraphWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|timerId
argument_list|(
literal|0
argument_list|)
block|{
name|QGraphicsScene
modifier|*
name|scene
init|=
operator|new
name|QGraphicsScene
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|scene
operator|->
name|setItemIndexMethod
argument_list|(
name|QGraphicsScene
operator|::
name|NoIndex
argument_list|)
expr_stmt|;
name|scene
operator|->
name|setSceneRect
argument_list|(
operator|-
literal|200
argument_list|,
operator|-
literal|200
argument_list|,
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|setCacheMode
argument_list|(
name|CacheBackground
argument_list|)
expr_stmt|;
name|setViewportUpdateMode
argument_list|(
name|BoundingRectViewportUpdate
argument_list|)
expr_stmt|;
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|setTransformationAnchor
argument_list|(
name|AnchorUnderMouse
argument_list|)
expr_stmt|;
name|scale
argument_list|(
name|qreal
argument_list|(
literal|0.8
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|0.8
argument_list|)
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Elastic Nodes"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|Node
modifier|*
name|node1
init|=
operator|new
name|Node
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|Node
modifier|*
name|node2
init|=
operator|new
name|Node
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|Node
modifier|*
name|node3
init|=
operator|new
name|Node
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|Node
modifier|*
name|node4
init|=
operator|new
name|Node
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|centerNode
operator|=
operator|new
name|Node
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|Node
modifier|*
name|node6
init|=
operator|new
name|Node
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|Node
modifier|*
name|node7
init|=
operator|new
name|Node
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|Node
modifier|*
name|node8
init|=
operator|new
name|Node
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|Node
modifier|*
name|node9
init|=
operator|new
name|Node
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|node1
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|node2
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|node3
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|node4
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|centerNode
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|node6
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|node7
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|node8
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|node9
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|node1
argument_list|,
name|node2
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|node2
argument_list|,
name|node3
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|node2
argument_list|,
name|centerNode
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|node3
argument_list|,
name|node6
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|node4
argument_list|,
name|node1
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|node4
argument_list|,
name|centerNode
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|centerNode
argument_list|,
name|node6
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|centerNode
argument_list|,
name|node8
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|node6
argument_list|,
name|node9
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|node7
argument_list|,
name|node4
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|node8
argument_list|,
name|node7
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
operator|new
name|Edge
argument_list|(
name|node9
argument_list|,
name|node8
argument_list|)
argument_list|)
expr_stmt|;
name|node1
operator|->
name|setPos
argument_list|(
operator|-
literal|50
argument_list|,
operator|-
literal|50
argument_list|)
expr_stmt|;
name|node2
operator|->
name|setPos
argument_list|(
literal|0
argument_list|,
operator|-
literal|50
argument_list|)
expr_stmt|;
name|node3
operator|->
name|setPos
argument_list|(
literal|50
argument_list|,
operator|-
literal|50
argument_list|)
expr_stmt|;
name|node4
operator|->
name|setPos
argument_list|(
operator|-
literal|50
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|centerNode
operator|->
name|setPos
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|node6
operator|->
name|setPos
argument_list|(
literal|50
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|node7
operator|->
name|setPos
argument_list|(
operator|-
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|node8
operator|->
name|setPos
argument_list|(
literal|0
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|node9
operator|->
name|setPos
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|itemMoved
name|void
name|GraphWidget
operator|::
name|itemMoved
parameter_list|()
block|{
if|if
condition|(
operator|!
name|timerId
condition|)
name|timerId
operator|=
name|startTimer
argument_list|(
literal|1000
operator|/
literal|25
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|keyPressEvent
name|void
name|GraphWidget
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|key
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_Up
case|:
name|centerNode
operator|->
name|moveBy
argument_list|(
literal|0
argument_list|,
operator|-
literal|20
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Down
case|:
name|centerNode
operator|->
name|moveBy
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Left
case|:
name|centerNode
operator|->
name|moveBy
argument_list|(
operator|-
literal|20
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Right
case|:
name|centerNode
operator|->
name|moveBy
argument_list|(
literal|20
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Plus
case|:
name|zoomIn
argument_list|()
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Minus
case|:
name|zoomOut
argument_list|()
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Space
case|:
case|case
name|Qt
operator|::
name|Key_Enter
case|:
name|shuffle
argument_list|()
expr_stmt|;
break|break;
default|default:
name|QGraphicsView
operator|::
name|keyPressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|timerEvent
name|void
name|GraphWidget
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|Node
modifier|*
argument_list|>
name|nodes
decl_stmt|;
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|scene
argument_list|()
operator|->
name|items
argument_list|()
control|)
block|{
if|if
condition|(
name|Node
modifier|*
name|node
init|=
name|qgraphicsitem_cast
argument_list|<
name|Node
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
condition|)
name|nodes
operator|<<
name|node
expr_stmt|;
block|}
foreach|foreach
control|(
name|Node
modifier|*
name|node
decl|,
name|nodes
control|)
name|node
operator|->
name|calculateForces
argument_list|()
expr_stmt|;
name|bool
name|itemsMoved
init|=
literal|false
decl_stmt|;
foreach|foreach
control|(
name|Node
modifier|*
name|node
decl|,
name|nodes
control|)
block|{
if|if
condition|(
name|node
operator|->
name|advance
argument_list|()
condition|)
name|itemsMoved
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|itemsMoved
condition|)
block|{
name|killTimer
argument_list|(
name|timerId
argument_list|)
expr_stmt|;
name|timerId
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
end_ifndef
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|wheelEvent
name|void
name|GraphWidget
operator|::
name|wheelEvent
parameter_list|(
name|QWheelEvent
modifier|*
name|event
parameter_list|)
block|{
name|scaleView
argument_list|(
name|pow
argument_list|(
operator|(
name|double
operator|)
literal|2
argument_list|,
operator|-
name|event
operator|->
name|delta
argument_list|()
operator|/
literal|240.0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|drawBackground
name|void
name|GraphWidget
operator|::
name|drawBackground
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|rect
argument_list|)
expr_stmt|;
comment|// Shadow
name|QRectF
name|sceneRect
init|=
name|this
operator|->
name|sceneRect
argument_list|()
decl_stmt|;
name|QRectF
name|rightShadow
argument_list|(
name|sceneRect
operator|.
name|right
argument_list|()
argument_list|,
name|sceneRect
operator|.
name|top
argument_list|()
operator|+
literal|5
argument_list|,
literal|5
argument_list|,
name|sceneRect
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QRectF
name|bottomShadow
argument_list|(
name|sceneRect
operator|.
name|left
argument_list|()
operator|+
literal|5
argument_list|,
name|sceneRect
operator|.
name|bottom
argument_list|()
argument_list|,
name|sceneRect
operator|.
name|width
argument_list|()
argument_list|,
literal|5
argument_list|)
decl_stmt|;
if|if
condition|(
name|rightShadow
operator|.
name|intersects
argument_list|(
name|rect
argument_list|)
operator|||
name|rightShadow
operator|.
name|contains
argument_list|(
name|rect
argument_list|)
condition|)
name|painter
operator|->
name|fillRect
argument_list|(
name|rightShadow
argument_list|,
name|Qt
operator|::
name|darkGray
argument_list|)
expr_stmt|;
if|if
condition|(
name|bottomShadow
operator|.
name|intersects
argument_list|(
name|rect
argument_list|)
operator|||
name|bottomShadow
operator|.
name|contains
argument_list|(
name|rect
argument_list|)
condition|)
name|painter
operator|->
name|fillRect
argument_list|(
name|bottomShadow
argument_list|,
name|Qt
operator|::
name|darkGray
argument_list|)
expr_stmt|;
comment|// Fill
name|QLinearGradient
name|gradient
argument_list|(
name|sceneRect
operator|.
name|topLeft
argument_list|()
argument_list|,
name|sceneRect
operator|.
name|bottomRight
argument_list|()
argument_list|)
decl_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|lightGray
argument_list|)
expr_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
operator|.
name|intersected
argument_list|(
name|sceneRect
argument_list|)
argument_list|,
name|gradient
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
name|painter
operator|->
name|drawRect
argument_list|(
name|sceneRect
argument_list|)
expr_stmt|;
comment|// Text
name|QRectF
name|textRect
argument_list|(
name|sceneRect
operator|.
name|left
argument_list|()
operator|+
literal|4
argument_list|,
name|sceneRect
operator|.
name|top
argument_list|()
operator|+
literal|4
argument_list|,
name|sceneRect
operator|.
name|width
argument_list|()
operator|-
literal|4
argument_list|,
name|sceneRect
operator|.
name|height
argument_list|()
operator|-
literal|4
argument_list|)
decl_stmt|;
name|QString
name|message
argument_list|(
name|tr
argument_list|(
literal|"Click and drag the nodes around, and zoom with the mouse "
literal|"wheel or the '+' and '-' keys"
argument_list|)
argument_list|)
decl_stmt|;
name|QFont
name|font
init|=
name|painter
operator|->
name|font
argument_list|()
decl_stmt|;
name|font
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|font
operator|.
name|setPointSize
argument_list|(
literal|14
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
name|setPen
argument_list|(
name|Qt
operator|::
name|lightGray
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|textRect
operator|.
name|translated
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
argument_list|,
name|message
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|textRect
argument_list|,
name|message
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|scaleView
name|void
name|GraphWidget
operator|::
name|scaleView
parameter_list|(
name|qreal
name|scaleFactor
parameter_list|)
block|{
name|qreal
name|factor
init|=
name|transform
argument_list|()
operator|.
name|scale
argument_list|(
name|scaleFactor
argument_list|,
name|scaleFactor
argument_list|)
operator|.
name|mapRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
operator|.
name|width
argument_list|()
decl_stmt|;
if|if
condition|(
name|factor
argument_list|<
literal|0.07
operator|||
name|factor
argument_list|>
literal|100
condition|)
return|return;
name|scale
argument_list|(
name|scaleFactor
argument_list|,
name|scaleFactor
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|shuffle
name|void
name|GraphWidget
operator|::
name|shuffle
parameter_list|()
block|{
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|scene
argument_list|()
operator|->
name|items
argument_list|()
control|)
block|{
if|if
condition|(
name|qgraphicsitem_cast
argument_list|<
name|Node
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
condition|)
name|item
operator|->
name|setPos
argument_list|(
operator|-
literal|150
operator|+
name|qrand
argument_list|()
operator|%
literal|300
argument_list|,
operator|-
literal|150
operator|+
name|qrand
argument_list|()
operator|%
literal|300
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|zoomIn
name|void
name|GraphWidget
operator|::
name|zoomIn
parameter_list|()
block|{
name|scaleView
argument_list|(
name|qreal
argument_list|(
literal|1.2
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|zoomOut
name|void
name|GraphWidget
operator|::
name|zoomOut
parameter_list|()
block|{
name|scaleView
argument_list|(
literal|1
operator|/
name|qreal
argument_list|(
literal|1.2
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
