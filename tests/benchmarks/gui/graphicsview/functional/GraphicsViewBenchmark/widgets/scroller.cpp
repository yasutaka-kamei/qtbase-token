begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QScrollBar>
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_include
include|#
directive|include
file|<QGraphicsSceneMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|"scroller.h"
end_include
begin_include
include|#
directive|include
file|"scroller_p.h"
end_include
begin_include
include|#
directive|include
file|"abstractscrollarea.h"
end_include
begin_include
include|#
directive|include
file|"scrollbar.h"
end_include
begin_decl_stmt
DECL|variable|ScrollStep
specifier|const
name|int
name|ScrollStep
init|=
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|UpdateScrollingInterval
specifier|const
name|int
name|UpdateScrollingInterval
init|=
literal|55
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|UpdateScrollingSmoothInterval
specifier|const
name|int
name|UpdateScrollingSmoothInterval
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|MaxScrollingSpeed
specifier|static
specifier|const
name|qreal
name|MaxScrollingSpeed
init|=
literal|48.0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|ScrollerPrivate
name|ScrollerPrivate
operator|::
name|ScrollerPrivate
parameter_list|(
name|Scroller
modifier|*
name|scroller
parameter_list|)
member_init_list|:
name|m_scrollArea
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_scrollFactor
argument_list|(
literal|1.0
argument_list|)
member_init_list|,
name|m_state
argument_list|(
name|Stopped
argument_list|)
member_init_list|,
name|q_ptr
argument_list|(
name|scroller
argument_list|)
member_init_list|,
name|m_eventViewport
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~ScrollerPrivate
name|ScrollerPrivate
operator|::
name|~
name|ScrollerPrivate
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|stopScrolling
name|void
name|ScrollerPrivate
operator|::
name|stopScrolling
parameter_list|()
block|{
name|m_state
operator|=
name|ScrollerPrivate
operator|::
name|Started
expr_stmt|;
name|m_cursorPos
operator|=
name|QCursor
operator|::
name|pos
argument_list|()
expr_stmt|;
name|m_speed
operator|=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_scrollTimer
operator|.
name|isActive
argument_list|()
condition|)
name|m_scrollTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//Maps screen coordinates to scrollArea coordinates though current m_eventViewport widget
end_comment
begin_function
DECL|function|mapToScrollArea
name|QPointF
name|ScrollerPrivate
operator|::
name|mapToScrollArea
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|point
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_scrollArea
operator|||
operator|!
name|m_eventViewport
condition|)
return|return
name|point
return|;
name|QObject
modifier|*
name|vparent
init|=
name|m_eventViewport
operator|->
name|parent
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|vparent
condition|)
return|return
name|point
return|;
name|QGraphicsView
modifier|*
name|view
init|=
name|qobject_cast
argument_list|<
name|QGraphicsView
operator|*
argument_list|>
argument_list|(
name|vparent
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|view
condition|)
return|return
name|point
return|;
name|QPoint
name|pt
init|=
name|view
operator|->
name|mapFromGlobal
argument_list|(
name|point
argument_list|)
decl_stmt|;
return|return
name|m_scrollArea
operator|->
name|mapFromScene
argument_list|(
name|view
operator|->
name|mapToScene
argument_list|(
name|pt
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|eventFilter
name|bool
name|ScrollerPrivate
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|obj
operator|!=
name|m_scrollArea
operator|||
operator|(
name|event
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|GraphicsSceneMouseMove
operator|&&
name|event
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|GraphicsSceneMousePress
operator|&&
name|event
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|GraphicsSceneMouseRelease
comment|/*&& event->type() != QEvent::GraphicsSceneKeyPressed&& event->type() != QEvent::GraphicsSceneKeyReleased*/
operator|)
condition|)
return|return
literal|false
return|;
name|QGraphicsSceneMouseEvent
modifier|*
name|mouseEvent
init|=
cast|static_cast
argument_list|<
name|QGraphicsSceneMouseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|m_eventViewport
operator|=
name|mouseEvent
operator|->
name|widget
argument_list|()
expr_stmt|;
name|bool
name|eventConsumed
init|=
literal|false
decl_stmt|;
switch|switch
condition|(
name|m_state
condition|)
block|{
case|case
name|ScrollerPrivate
operator|::
name|Stopped
case|:
if|if
condition|(
name|mouseEvent
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GraphicsSceneMousePress
operator|&&
name|mouseEvent
operator|->
name|buttons
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|m_cursorPos
operator|=
name|QCursor
operator|::
name|pos
argument_list|()
expr_stmt|;
name|m_speed
operator|=
name|QPointF
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|m_state
operator|=
name|Started
expr_stmt|;
block|}
name|eventConsumed
operator|=
literal|true
expr_stmt|;
break|break;
case|case
name|ScrollerPrivate
operator|::
name|Started
case|:
if|if
condition|(
name|mouseEvent
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GraphicsSceneMouseMove
condition|)
block|{
name|m_cursorPos
operator|=
name|QCursor
operator|::
name|pos
argument_list|()
expr_stmt|;
name|m_state
operator|=
name|ManualScrolling
expr_stmt|;
if|if
condition|(
operator|!
name|m_scrollTimer
operator|.
name|isActive
argument_list|()
condition|)
name|m_scrollTimer
operator|.
name|start
argument_list|(
name|UpdateScrollingInterval
argument_list|)
expr_stmt|;
else|else
block|{
name|m_scrollTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|m_scrollTimer
operator|.
name|start
argument_list|(
name|UpdateScrollingInterval
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|mouseEvent
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonRelease
condition|)
block|{
name|m_speed
operator|=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_state
operator|=
name|Stopped
expr_stmt|;
if|if
condition|(
name|m_scrollTimer
operator|.
name|isActive
argument_list|()
condition|)
name|m_scrollTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
name|eventConsumed
operator|=
literal|true
expr_stmt|;
break|break;
case|case
name|ScrollerPrivate
operator|::
name|ManualScrolling
case|:
if|if
condition|(
name|mouseEvent
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GraphicsSceneMouseMove
operator|&&
name|m_scrollArea
operator|->
name|viewport
argument_list|()
operator|->
name|boundingRect
argument_list|()
operator|.
name|contains
argument_list|(
name|mouseEvent
operator|->
name|pos
argument_list|()
argument_list|)
condition|)
block|{
name|ScrollBar
modifier|*
name|hscroll
init|=
name|m_scrollArea
operator|->
name|horizontalScrollBar
argument_list|()
decl_stmt|;
name|ScrollBar
modifier|*
name|vscroll
init|=
name|m_scrollArea
operator|->
name|verticalScrollBar
argument_list|()
decl_stmt|;
name|QPointF
name|d
init|=
name|m_scrollFactor
operator|*
operator|(
name|mapToScrollArea
argument_list|(
name|QCursor
operator|::
name|pos
argument_list|()
argument_list|)
operator|-
name|mapToScrollArea
argument_list|(
name|m_cursorPos
argument_list|)
operator|)
decl_stmt|;
name|hscroll
operator|->
name|setSliderPosition
argument_list|(
name|hscroll
operator|->
name|sliderPosition
argument_list|()
operator|-
name|d
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|vscroll
operator|->
name|setSliderPosition
argument_list|(
name|vscroll
operator|->
name|sliderPosition
argument_list|()
operator|-
name|d
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_lastCursorTime
operator|.
name|elapsed
argument_list|()
operator|>
name|UpdateScrollingInterval
condition|)
block|{
name|m_speed
operator|=
name|mapToScrollArea
argument_list|(
name|QCursor
operator|::
name|pos
argument_list|()
argument_list|)
operator|-
name|mapToScrollArea
argument_list|(
name|m_cursorPos
argument_list|)
expr_stmt|;
name|m_lastCursorTime
operator|.
name|restart
argument_list|()
expr_stmt|;
block|}
name|m_lastFrameTime
operator|.
name|restart
argument_list|()
expr_stmt|;
name|m_cursorPos
operator|=
name|QCursor
operator|::
name|pos
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mouseEvent
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GraphicsSceneMouseRelease
condition|)
block|{
name|m_state
operator|=
name|AutoScrolling
expr_stmt|;
name|m_scrollSlowAccum
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|m_scrollTimer
operator|.
name|isActive
argument_list|()
condition|)
block|{
name|m_scrollTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|m_scrollTimer
operator|.
name|start
argument_list|(
name|UpdateScrollingSmoothInterval
argument_list|)
expr_stmt|;
block|}
block|}
name|eventConsumed
operator|=
literal|true
expr_stmt|;
break|break;
case|case
name|ScrollerPrivate
operator|::
name|AutoScrolling
case|:
if|if
condition|(
name|mouseEvent
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GraphicsSceneMousePress
condition|)
block|{
name|stopScrolling
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mouseEvent
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonRelease
condition|)
block|{
name|m_state
operator|=
name|Stopped
expr_stmt|;
block|}
name|eventConsumed
operator|=
literal|true
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|eventConsumed
return|;
block|}
end_function
begin_function
DECL|function|updateScrolling
name|void
name|ScrollerPrivate
operator|::
name|updateScrolling
parameter_list|()
block|{
name|bool
name|scrollOngoing
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|m_scrollArea
condition|)
block|{
name|m_scrollTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|m_state
operator|==
name|ManualScrolling
condition|)
block|{
name|scrollOngoing
operator|=
literal|true
expr_stmt|;
name|m_speed
operator|=
name|mapToScrollArea
argument_list|(
name|QCursor
operator|::
name|pos
argument_list|()
argument_list|)
operator|-
name|mapToScrollArea
argument_list|(
name|m_cursorPos
argument_list|)
expr_stmt|;
name|m_cursorPos
operator|=
name|QCursor
operator|::
name|pos
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|m_state
operator|==
name|AutoScrolling
condition|)
block|{
name|scrollOngoing
operator|=
literal|true
expr_stmt|;
name|qreal
name|x
init|=
name|qMax
argument_list|(
operator|-
name|MaxScrollingSpeed
argument_list|,
name|qMin
argument_list|(
name|m_speed
operator|.
name|x
argument_list|()
argument_list|,
name|MaxScrollingSpeed
argument_list|)
argument_list|)
decl_stmt|;
name|qreal
name|y
init|=
name|qMax
argument_list|(
operator|-
name|MaxScrollingSpeed
argument_list|,
name|qMin
argument_list|(
name|m_speed
operator|.
name|y
argument_list|()
argument_list|,
name|MaxScrollingSpeed
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|sinceLast
init|=
name|m_lastFrameTime
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|int
name|slowdown
init|=
operator|(
name|ScrollStep
operator|*
name|sinceLast
operator|)
operator|+
name|m_scrollSlowAccum
decl_stmt|;
name|m_scrollSlowAccum
operator|=
name|slowdown
operator|&
literal|0x3F
expr_stmt|;
name|slowdown
operator|>>=
literal|6
expr_stmt|;
if|if
condition|(
name|x
operator|>
literal|0
condition|)
name|x
operator|=
name|qMax
argument_list|(
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|,
name|x
operator|-
name|slowdown
argument_list|)
expr_stmt|;
else|else
name|x
operator|=
name|qMin
argument_list|(
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|,
name|x
operator|+
name|slowdown
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|>
literal|0
condition|)
name|y
operator|=
name|qMax
argument_list|(
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|,
name|y
operator|-
name|slowdown
argument_list|)
expr_stmt|;
else|else
name|y
operator|=
name|qMin
argument_list|(
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|,
name|y
operator|+
name|slowdown
argument_list|)
expr_stmt|;
name|m_speed
operator|=
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_speed
operator|!=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|QPointF
name|d
decl_stmt|;
name|int
name|xstep
init|=
operator|(
name|int
argument_list|(
name|m_speed
operator|.
name|x
argument_list|()
argument_list|)
operator|*
name|sinceLast
operator|)
operator|>>
literal|6
decl_stmt|;
comment|//>>6 ~= *60 /1000 (==*64 /1024)
name|int
name|ystep
init|=
operator|(
name|int
argument_list|(
name|m_speed
operator|.
name|y
argument_list|()
argument_list|)
operator|*
name|sinceLast
operator|)
operator|>>
literal|6
decl_stmt|;
comment|//qDebug()<< sinceLast<< "speedy"<< speed.y()<<"ystep"<< ystep;
name|QPoint
name|step
init|=
name|QPoint
argument_list|(
name|xstep
argument_list|,
name|ystep
argument_list|)
decl_stmt|;
if|if
condition|(
name|ystep
operator|>
literal|0
condition|)
name|d
operator|=
operator|(
name|m_scrollArea
operator|->
name|pos
argument_list|()
operator|+
name|step
operator|)
expr_stmt|;
else|else
name|d
operator|=
operator|-
operator|(
name|m_scrollArea
operator|->
name|pos
argument_list|()
operator|-
name|step
operator|)
expr_stmt|;
name|ScrollBar
modifier|*
name|hscroll
init|=
name|m_scrollArea
operator|->
name|horizontalScrollBar
argument_list|()
decl_stmt|;
name|ScrollBar
modifier|*
name|vscroll
init|=
name|m_scrollArea
operator|->
name|verticalScrollBar
argument_list|()
decl_stmt|;
name|hscroll
operator|->
name|setSliderPosition
argument_list|(
name|hscroll
operator|->
name|sliderPosition
argument_list|()
operator|-
name|m_scrollFactor
operator|*
name|d
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|vscroll
operator|->
name|setSliderPosition
argument_list|(
name|vscroll
operator|->
name|sliderPosition
argument_list|()
operator|-
name|m_scrollFactor
operator|*
name|d
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_state
operator|=
name|Stopped
expr_stmt|;
name|scrollOngoing
operator|=
literal|false
expr_stmt|;
block|}
block|}
name|m_lastFrameTime
operator|.
name|restart
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|scrollOngoing
condition|)
name|m_scrollTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|Scroller
name|Scroller
operator|::
name|Scroller
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|ScrollerPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|Q_D
argument_list|(
name|Scroller
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|d
operator|->
name|m_scrollTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateScrolling
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Scroller
name|Scroller
operator|::
name|~
name|Scroller
parameter_list|()
block|{
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setScrollable
name|void
name|Scroller
operator|::
name|setScrollable
parameter_list|(
name|AbstractScrollArea
modifier|*
name|area
parameter_list|)
block|{
name|Q_D
argument_list|(
name|Scroller
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|area
condition|)
return|return;
name|d
operator|->
name|m_scrollArea
operator|=
name|area
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setScrollFactor
name|void
name|Scroller
operator|::
name|setScrollFactor
parameter_list|(
name|qreal
name|scrollFactor
parameter_list|)
block|{
name|Q_D
argument_list|(
name|Scroller
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_scrollFactor
operator|=
name|scrollFactor
expr_stmt|;
block|}
end_function
begin_function
DECL|function|eventFilter
name|bool
name|Scroller
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|Scroller
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|eventFilter
argument_list|(
name|obj
argument_list|,
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|stopScrolling
name|void
name|Scroller
operator|::
name|stopScrolling
parameter_list|()
block|{
name|Q_D
argument_list|(
name|Scroller
argument_list|)
expr_stmt|;
name|d
operator|->
name|stopScrolling
argument_list|()
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|"moc_scroller.cpp"
end_include
end_unit
