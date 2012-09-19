begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mousepangesturerecognizer.h"
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_include
include|#
directive|include
file|<QGraphicsSceneMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QGesture>
end_include
begin_constructor
DECL|function|MousePanGestureRecognizer
name|MousePanGestureRecognizer
operator|::
name|MousePanGestureRecognizer
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|create
name|QGesture
modifier|*
name|MousePanGestureRecognizer
operator|::
name|create
parameter_list|(
name|QObject
modifier|*
parameter_list|)
block|{
return|return
operator|new
name|QPanGesture
return|;
block|}
end_function
begin_function
DECL|function|recognize
name|QGestureRecognizer
operator|::
name|Result
name|MousePanGestureRecognizer
operator|::
name|recognize
parameter_list|(
name|QGesture
modifier|*
name|state
parameter_list|,
name|QObject
modifier|*
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPanGesture
modifier|*
name|g
init|=
cast|static_cast
argument_list|<
name|QPanGesture
operator|*
argument_list|>
argument_list|(
name|state
argument_list|)
decl_stmt|;
name|QPoint
name|globalPos
decl_stmt|;
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|GraphicsSceneMousePress
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneMouseDoubleClick
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneMouseMove
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneMouseRelease
case|:
name|globalPos
operator|=
cast|static_cast
argument_list|<
name|QGraphicsSceneMouseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
operator|->
name|screenPos
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseMove
case|:
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
name|globalPos
operator|=
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
operator|->
name|globalPos
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonPress
operator|||
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonDblClick
operator|||
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GraphicsSceneMousePress
operator|||
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GraphicsSceneMouseDoubleClick
condition|)
block|{
name|g
operator|->
name|setHotSpot
argument_list|(
name|globalPos
argument_list|)
expr_stmt|;
name|g
operator|->
name|setProperty
argument_list|(
literal|"startPos"
argument_list|,
name|globalPos
argument_list|)
expr_stmt|;
name|g
operator|->
name|setProperty
argument_list|(
literal|"pressed"
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|true
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|TriggerGesture
operator||
name|QGestureRecognizer
operator|::
name|ConsumeEventHint
return|;
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseMove
operator|||
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GraphicsSceneMouseMove
condition|)
block|{
if|if
condition|(
name|g
operator|->
name|property
argument_list|(
literal|"pressed"
argument_list|)
operator|.
name|toBool
argument_list|()
condition|)
block|{
name|QPoint
name|offset
init|=
name|globalPos
operator|-
name|g
operator|->
name|property
argument_list|(
literal|"startPos"
argument_list|)
operator|.
name|toPoint
argument_list|()
decl_stmt|;
name|g
operator|->
name|setLastOffset
argument_list|(
name|g
operator|->
name|offset
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setOffset
argument_list|(
name|QPointF
argument_list|(
name|offset
operator|.
name|x
argument_list|()
argument_list|,
name|offset
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QGestureRecognizer
operator|::
name|TriggerGesture
operator||
name|QGestureRecognizer
operator|::
name|ConsumeEventHint
return|;
block|}
return|return
name|QGestureRecognizer
operator|::
name|CancelGesture
return|;
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonRelease
operator|||
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GraphicsSceneMouseRelease
condition|)
block|{
return|return
name|QGestureRecognizer
operator|::
name|FinishGesture
operator||
name|QGestureRecognizer
operator|::
name|ConsumeEventHint
return|;
block|}
return|return
name|QGestureRecognizer
operator|::
name|Ignore
return|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|MousePanGestureRecognizer
operator|::
name|reset
parameter_list|(
name|QGesture
modifier|*
name|state
parameter_list|)
block|{
name|QPanGesture
modifier|*
name|g
init|=
cast|static_cast
argument_list|<
name|QPanGesture
operator|*
argument_list|>
argument_list|(
name|state
argument_list|)
decl_stmt|;
name|g
operator|->
name|setLastOffset
argument_list|(
name|QPointF
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setOffset
argument_list|(
name|QPointF
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setAcceleration
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|g
operator|->
name|setProperty
argument_list|(
literal|"startPos"
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
name|g
operator|->
name|setProperty
argument_list|(
literal|"pressed"
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|false
argument_list|)
argument_list|)
expr_stmt|;
name|QGestureRecognizer
operator|::
name|reset
argument_list|(
name|state
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
