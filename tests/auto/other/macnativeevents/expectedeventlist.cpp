begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"expectedeventlist.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QAbstractEventDispatcher>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_constructor
DECL|function|ExpectedEventList
name|ExpectedEventList
operator|::
name|ExpectedEventList
parameter_list|(
name|QObject
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|target
argument_list|)
member_init_list|,
name|eventCount
argument_list|(
literal|0
argument_list|)
block|{
name|target
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|debug
operator|=
name|qgetenv
argument_list|(
literal|"NATIVEDEBUG"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
if|if
condition|(
name|debug
operator|>
literal|0
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Debug level sat to:"
operator|<<
name|debug
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~ExpectedEventList
name|ExpectedEventList
operator|::
name|~
name|ExpectedEventList
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|eventList
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|append
name|void
name|ExpectedEventList
operator|::
name|append
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|eventList
operator|.
name|append
argument_list|(
name|e
argument_list|)
expr_stmt|;
operator|++
name|eventCount
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|ExpectedEventList
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
name|timer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
operator|->
name|interrupt
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForAllEvents
name|bool
name|ExpectedEventList
operator|::
name|waitForAllEvents
parameter_list|(
name|int
name|maxEventWaitTime
parameter_list|)
block|{
if|if
condition|(
name|eventList
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
name|int
name|eventCount
init|=
name|eventList
operator|.
name|size
argument_list|()
decl_stmt|;
name|timer
operator|.
name|start
argument_list|(
name|maxEventWaitTime
argument_list|,
name|this
argument_list|)
expr_stmt|;
while|while
condition|(
name|timer
operator|.
name|isActive
argument_list|()
condition|)
block|{
name|QCoreApplication
operator|::
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|WaitForMoreEvents
argument_list|)
expr_stmt|;
if|if
condition|(
name|eventList
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|eventCount
operator|<
name|eventList
operator|.
name|size
argument_list|()
condition|)
block|{
name|eventCount
operator|=
name|eventList
operator|.
name|size
argument_list|()
expr_stmt|;
name|timer
operator|.
name|start
argument_list|(
name|maxEventWaitTime
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
block|}
name|int
name|eventListNr
init|=
name|eventCount
operator|-
name|eventList
operator|.
name|size
argument_list|()
operator|+
literal|1
decl_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"Stopped waiting for expected event nr"
operator|<<
name|eventListNr
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|compareMouseEvents
name|void
name|ExpectedEventList
operator|::
name|compareMouseEvents
parameter_list|(
name|QEvent
modifier|*
name|received
parameter_list|,
name|QEvent
modifier|*
name|expected
parameter_list|)
block|{
name|QMouseEvent
modifier|*
name|e1
init|=
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|received
argument_list|)
decl_stmt|;
name|QMouseEvent
modifier|*
name|e2
init|=
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|expected
argument_list|)
decl_stmt|;
comment|// Do a manual check first to be able to write more sensible
comment|// debug output if we know we're going to fail:
if|if
condition|(
name|e1
operator|->
name|pos
argument_list|()
operator|==
name|e2
operator|->
name|pos
argument_list|()
operator|&&
operator|(
name|e1
operator|->
name|globalPos
argument_list|()
operator|==
name|e2
operator|->
name|globalPos
argument_list|()
operator|)
operator|&&
operator|(
name|e1
operator|->
name|button
argument_list|()
operator|==
name|e2
operator|->
name|button
argument_list|()
operator|)
operator|&&
operator|(
name|e1
operator|->
name|buttons
argument_list|()
operator|==
name|e2
operator|->
name|buttons
argument_list|()
operator|)
operator|&&
operator|(
name|e1
operator|->
name|modifiers
argument_list|()
operator|==
name|e2
operator|->
name|modifiers
argument_list|()
operator|)
condition|)
block|{
if|if
condition|(
name|debug
operator|>
literal|0
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"  Received (OK):"
operator|<<
name|e1
operator|<<
name|e1
operator|->
name|globalPos
argument_list|()
expr_stmt|;
return|return;
comment|// equal
block|}
comment|// INVARIANT: The two events are not equal. So we fail. Depending
comment|// on whether debug mode is no or not, we let QTest fail. Otherwise
comment|// we let the test continue for debugging puposes.
name|int
name|eventListNr
init|=
name|eventCount
operator|-
name|eventList
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|debug
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Expected event"
operator|<<
name|eventListNr
operator|<<
literal|"differs from received event:"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e1
operator|->
name|pos
argument_list|()
argument_list|,
name|e2
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e1
operator|->
name|globalPos
argument_list|()
argument_list|,
name|e2
operator|->
name|globalPos
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e1
operator|->
name|button
argument_list|()
argument_list|,
name|e2
operator|->
name|button
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e1
operator|->
name|buttons
argument_list|()
argument_list|,
name|e2
operator|->
name|buttons
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e1
operator|->
name|modifiers
argument_list|()
argument_list|,
name|e2
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
literal|"*** FAIL *** : Expected event"
operator|<<
name|eventListNr
operator|<<
literal|"differs from received event:"
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"Received:"
operator|<<
name|e1
operator|<<
name|e1
operator|->
name|globalPos
argument_list|()
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"Expected:"
operator|<<
name|e2
operator|<<
name|e2
operator|->
name|globalPos
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|compareKeyEvents
name|void
name|ExpectedEventList
operator|::
name|compareKeyEvents
parameter_list|(
name|QEvent
modifier|*
name|received
parameter_list|,
name|QEvent
modifier|*
name|expected
parameter_list|)
block|{
name|QKeyEvent
modifier|*
name|e1
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|received
argument_list|)
decl_stmt|;
name|QKeyEvent
modifier|*
name|e2
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|expected
argument_list|)
decl_stmt|;
comment|// Do a manual check first to be able to write more sensible
comment|// debug output if we know we're going to fail:
if|if
condition|(
name|e1
operator|->
name|key
argument_list|()
operator|==
name|e2
operator|->
name|key
argument_list|()
operator|&&
operator|(
name|e1
operator|->
name|modifiers
argument_list|()
operator|==
name|e2
operator|->
name|modifiers
argument_list|()
operator|)
operator|&&
operator|(
name|e1
operator|->
name|count
argument_list|()
operator|==
name|e2
operator|->
name|count
argument_list|()
operator|)
operator|&&
operator|(
name|e1
operator|->
name|isAutoRepeat
argument_list|()
operator|==
name|e2
operator|->
name|isAutoRepeat
argument_list|()
operator|)
condition|)
block|{
if|if
condition|(
name|debug
operator|>
literal|0
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"  Received (OK):"
operator|<<
name|e1
operator|<<
name|QKeySequence
argument_list|(
name|e1
operator|->
name|key
argument_list|()
argument_list|)
operator|.
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
expr_stmt|;
return|return;
comment|// equal
block|}
comment|// INVARIANT: The two events are not equal. So we fail. Depending
comment|// on whether debug mode is no or not, we let QTest fail. Otherwise
comment|// we let the test continue for debugging puposes.
name|int
name|eventListNr
init|=
name|eventCount
operator|-
name|eventList
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|debug
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Expected event"
operator|<<
name|eventListNr
operator|<<
literal|"differs from received event:"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e1
operator|->
name|key
argument_list|()
argument_list|,
name|e2
operator|->
name|key
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e1
operator|->
name|modifiers
argument_list|()
argument_list|,
name|e2
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e1
operator|->
name|count
argument_list|()
argument_list|,
name|e2
operator|->
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e1
operator|->
name|isAutoRepeat
argument_list|()
argument_list|,
name|e2
operator|->
name|isAutoRepeat
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
literal|"*** FAIL *** : Expected event"
operator|<<
name|eventListNr
operator|<<
literal|"differs from received event:"
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"Received:"
operator|<<
name|e1
operator|<<
name|QKeySequence
argument_list|(
name|e1
operator|->
name|key
argument_list|()
argument_list|)
operator|.
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"Expected:"
operator|<<
name|e2
operator|<<
name|QKeySequence
argument_list|(
name|e2
operator|->
name|key
argument_list|()
argument_list|)
operator|.
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|eventFilter
name|bool
name|ExpectedEventList
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
parameter_list|,
name|QEvent
modifier|*
name|received
parameter_list|)
block|{
if|if
condition|(
name|debug
operator|>
literal|1
condition|)
name|qDebug
argument_list|()
operator|<<
name|received
expr_stmt|;
if|if
condition|(
name|eventList
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
name|bool
name|eat
init|=
literal|false
decl_stmt|;
name|QEvent
modifier|*
name|expected
init|=
name|eventList
operator|.
name|first
argument_list|()
decl_stmt|;
if|if
condition|(
name|expected
operator|->
name|type
argument_list|()
operator|==
name|received
operator|->
name|type
argument_list|()
condition|)
block|{
name|eventList
operator|.
name|removeFirst
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|received
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
case|case
name|QEvent
operator|::
name|MouseMove
case|:
case|case
name|QEvent
operator|::
name|MouseButtonDblClick
case|:
case|case
name|QEvent
operator|::
name|NonClientAreaMouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|NonClientAreaMouseButtonRelease
case|:
case|case
name|QEvent
operator|::
name|NonClientAreaMouseButtonDblClick
case|:
case|case
name|QEvent
operator|::
name|NonClientAreaMouseMove
case|:
block|{
name|compareMouseEvents
argument_list|(
name|received
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|eat
operator|=
literal|true
expr_stmt|;
break|break;
block|}
case|case
name|QEvent
operator|::
name|KeyPress
case|:
case|case
name|QEvent
operator|::
name|KeyRelease
case|:
block|{
name|compareKeyEvents
argument_list|(
name|received
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|eat
operator|=
literal|true
expr_stmt|;
break|break;
block|}
case|case
name|QEvent
operator|::
name|Resize
case|:
block|{
break|break;
block|}
case|case
name|QEvent
operator|::
name|WindowActivate
case|:
block|{
break|break;
block|}
case|case
name|QEvent
operator|::
name|WindowDeactivate
case|:
block|{
break|break;
block|}
default|default:
break|break;
block|}
if|if
condition|(
name|eventList
operator|.
name|isEmpty
argument_list|()
condition|)
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
operator|->
name|interrupt
argument_list|()
expr_stmt|;
block|}
return|return
name|eat
return|;
block|}
end_function
end_unit
