begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnativeevents.h"
end_include
begin_constructor
DECL|function|QNativeInput
name|QNativeInput
operator|::
name|QNativeInput
parameter_list|(
name|bool
name|subscribe
parameter_list|)
block|{
if|if
condition|(
name|subscribe
condition|)
name|subscribeForNativeEvents
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QNativeInput
name|QNativeInput
operator|::
name|~
name|QNativeInput
parameter_list|()
block|{
name|unsubscribeForNativeEvents
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|notify
name|void
name|QNativeInput
operator|::
name|notify
parameter_list|(
name|QNativeEvent
modifier|*
name|event
parameter_list|)
block|{
name|nativeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nativeEvent
name|void
name|QNativeInput
operator|::
name|nativeEvent
parameter_list|(
name|QNativeEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|id
argument_list|()
condition|)
block|{
case|case
name|QNativeMouseButtonEvent
operator|::
name|eventId
case|:
block|{
name|QNativeMouseButtonEvent
modifier|*
name|e
init|=
cast|static_cast
argument_list|<
name|QNativeMouseButtonEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
operator|(
name|e
operator|->
name|clickCount
operator|>
literal|0
operator|)
condition|?
name|nativeMousePressEvent
argument_list|(
name|e
argument_list|)
else|:
name|nativeMouseReleaseEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QNativeMouseMoveEvent
operator|::
name|eventId
case|:
name|nativeMouseMoveEvent
argument_list|(
cast|static_cast
argument_list|<
name|QNativeMouseMoveEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNativeMouseDragEvent
operator|::
name|eventId
case|:
name|nativeMouseDragEvent
argument_list|(
cast|static_cast
argument_list|<
name|QNativeMouseDragEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNativeMouseWheelEvent
operator|::
name|eventId
case|:
name|nativeMouseWheelEvent
argument_list|(
cast|static_cast
argument_list|<
name|QNativeMouseWheelEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QNativeKeyEvent
operator|::
name|eventId
case|:
block|{
name|QNativeKeyEvent
modifier|*
name|e
init|=
cast|static_cast
argument_list|<
name|QNativeKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|e
operator|->
name|press
condition|?
name|nativeKeyPressEvent
argument_list|(
name|e
argument_list|)
else|:
name|nativeKeyReleaseEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QNativeModifierEvent
operator|::
name|eventId
case|:
name|nativeModifierEvent
argument_list|(
cast|static_cast
argument_list|<
name|QNativeModifierEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|sendNativeEvent
name|Qt
operator|::
name|Native
operator|::
name|Status
name|QNativeInput
operator|::
name|sendNativeEvent
parameter_list|(
specifier|const
name|QNativeEvent
modifier|&
name|event
parameter_list|,
name|int
name|pid
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|.
name|id
argument_list|()
condition|)
block|{
case|case
name|QNativeMouseMoveEvent
operator|::
name|eventId
case|:
return|return
name|sendNativeMouseMoveEvent
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QNativeMouseMoveEvent
operator|&
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
return|;
case|case
name|QNativeMouseButtonEvent
operator|::
name|eventId
case|:
return|return
name|sendNativeMouseButtonEvent
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QNativeMouseButtonEvent
operator|&
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
return|;
case|case
name|QNativeMouseDragEvent
operator|::
name|eventId
case|:
return|return
name|sendNativeMouseDragEvent
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QNativeMouseDragEvent
operator|&
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
return|;
case|case
name|QNativeMouseWheelEvent
operator|::
name|eventId
case|:
return|return
name|sendNativeMouseWheelEvent
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QNativeMouseWheelEvent
operator|&
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
return|;
case|case
name|QNativeKeyEvent
operator|::
name|eventId
case|:
return|return
name|sendNativeKeyEvent
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QNativeKeyEvent
operator|&
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|,
name|pid
argument_list|)
return|;
case|case
name|QNativeModifierEvent
operator|::
name|eventId
case|:
return|return
name|sendNativeModifierEvent
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QNativeModifierEvent
operator|&
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|)
return|;
case|case
name|QNativeEvent
operator|::
name|eventId
case|:
name|qWarning
argument_list|()
operator|<<
literal|"Warning: Cannot send a pure native event. Use a sub class."
expr_stmt|;
default|default:
return|return
name|Qt
operator|::
name|Native
operator|::
name|Failure
return|;
block|}
block|}
end_function
begin_constructor
DECL|function|QNativeEvent
name|QNativeEvent
operator|::
name|QNativeEvent
parameter_list|(
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
member_init_list|:
name|modifiers
argument_list|(
name|modifiers
argument_list|)
block|{}
end_constructor
begin_constructor
DECL|function|QNativeMouseEvent
name|QNativeMouseEvent
operator|::
name|QNativeMouseEvent
parameter_list|(
name|QPoint
name|pos
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
member_init_list|:
name|QNativeEvent
argument_list|(
name|modifiers
argument_list|)
member_init_list|,
name|globalPos
argument_list|(
name|pos
argument_list|)
block|{}
end_constructor
begin_constructor
DECL|function|QNativeMouseMoveEvent
name|QNativeMouseMoveEvent
operator|::
name|QNativeMouseMoveEvent
parameter_list|(
name|QPoint
name|pos
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
member_init_list|:
name|QNativeMouseEvent
argument_list|(
name|pos
argument_list|,
name|modifiers
argument_list|)
block|{}
end_constructor
begin_constructor
DECL|function|QNativeMouseButtonEvent
name|QNativeMouseButtonEvent
operator|::
name|QNativeMouseButtonEvent
parameter_list|(
name|QPoint
name|globalPos
parameter_list|,
name|Qt
operator|::
name|MouseButton
name|button
parameter_list|,
name|int
name|clickCount
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
member_init_list|:
name|QNativeMouseEvent
argument_list|(
name|globalPos
argument_list|,
name|modifiers
argument_list|)
member_init_list|,
name|button
argument_list|(
name|button
argument_list|)
member_init_list|,
name|clickCount
argument_list|(
name|clickCount
argument_list|)
block|{}
end_constructor
begin_constructor
DECL|function|QNativeMouseDragEvent
name|QNativeMouseDragEvent
operator|::
name|QNativeMouseDragEvent
parameter_list|(
name|QPoint
name|globalPos
parameter_list|,
name|Qt
operator|::
name|MouseButton
name|button
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
member_init_list|:
name|QNativeMouseButtonEvent
argument_list|(
name|globalPos
argument_list|,
name|button
argument_list|,
literal|true
argument_list|,
name|modifiers
argument_list|)
block|{}
end_constructor
begin_constructor
DECL|function|QNativeMouseWheelEvent
name|QNativeMouseWheelEvent
operator|::
name|QNativeMouseWheelEvent
parameter_list|(
name|QPoint
name|globalPos
parameter_list|,
name|int
name|delta
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
member_init_list|:
name|QNativeMouseEvent
argument_list|(
name|globalPos
argument_list|,
name|modifiers
argument_list|)
member_init_list|,
name|delta
argument_list|(
name|delta
argument_list|)
block|{}
end_constructor
begin_constructor
DECL|function|QNativeKeyEvent
name|QNativeKeyEvent
operator|::
name|QNativeKeyEvent
parameter_list|(
name|int
name|nativeKeyCode
parameter_list|,
name|bool
name|press
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
member_init_list|:
name|QNativeEvent
argument_list|(
name|modifiers
argument_list|)
member_init_list|,
name|nativeKeyCode
argument_list|(
name|nativeKeyCode
argument_list|)
member_init_list|,
name|press
argument_list|(
name|press
argument_list|)
member_init_list|,
name|character
argument_list|(
name|QChar
argument_list|()
argument_list|)
block|{}
end_constructor
begin_constructor
DECL|function|QNativeModifierEvent
name|QNativeModifierEvent
operator|::
name|QNativeModifierEvent
parameter_list|(
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|,
name|int
name|nativeKeyCode
parameter_list|)
member_init_list|:
name|QNativeEvent
argument_list|(
name|modifiers
argument_list|)
member_init_list|,
name|nativeKeyCode
argument_list|(
name|nativeKeyCode
argument_list|)
block|{}
end_constructor
begin_constructor
DECL|function|QNativeKeyEvent
name|QNativeKeyEvent
operator|::
name|QNativeKeyEvent
parameter_list|(
name|int
name|nativeKeyCode
parameter_list|,
name|bool
name|press
parameter_list|,
name|QChar
name|character
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
member_init_list|:
name|QNativeEvent
argument_list|(
name|modifiers
argument_list|)
member_init_list|,
name|nativeKeyCode
argument_list|(
name|nativeKeyCode
argument_list|)
member_init_list|,
name|press
argument_list|(
name|press
argument_list|)
member_init_list|,
name|character
argument_list|(
name|character
argument_list|)
block|{}
end_constructor
begin_function
DECL|function|getButtonAsString
specifier|static
name|QString
name|getButtonAsString
parameter_list|(
specifier|const
name|QNativeMouseButtonEvent
modifier|*
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
operator|->
name|button
condition|)
block|{
case|case
name|Qt
operator|::
name|LeftButton
case|:
return|return
literal|"button = LeftButton"
return|;
break|break;
case|case
name|Qt
operator|::
name|RightButton
case|:
return|return
literal|"button = RightButton"
return|;
break|break;
case|case
name|Qt
operator|::
name|MidButton
case|:
return|return
literal|"button = MidButton"
return|;
break|break;
default|default:
return|return
literal|"button = Other"
return|;
break|break;
block|}
block|}
end_function
begin_function
DECL|function|getModifiersAsString
specifier|static
name|QString
name|getModifiersAsString
parameter_list|(
specifier|const
name|QNativeEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|modifiers
operator|==
literal|0
condition|)
return|return
literal|"modifiers = none"
return|;
name|QString
name|tmp
init|=
literal|"modifiers = "
decl_stmt|;
if|if
condition|(
name|e
operator|->
name|modifiers
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|ShiftModifier
argument_list|)
condition|)
name|tmp
operator|+=
literal|"Shift"
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|modifiers
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|ControlModifier
argument_list|)
condition|)
name|tmp
operator|+=
literal|"Control"
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|modifiers
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|AltModifier
argument_list|)
condition|)
name|tmp
operator|+=
literal|"Alt"
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|modifiers
operator|.
name|testFlag
argument_list|(
name|Qt
operator|::
name|MetaModifier
argument_list|)
condition|)
name|tmp
operator|+=
literal|"Meta"
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function
begin_function
DECL|function|getPosAsString
specifier|static
name|QString
name|getPosAsString
parameter_list|(
name|QPoint
name|pos
parameter_list|)
block|{
return|return
name|QString
argument_list|(
literal|"QPoint(%1, %2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|pos
operator|.
name|x
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|pos
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|getBoolAsString
specifier|static
name|QString
name|getBoolAsString
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
return|return
name|b
condition|?
name|QString
argument_list|(
literal|"true"
argument_list|)
else|:
name|QString
argument_list|(
literal|"false"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|QNativeMouseMoveEvent
operator|::
name|toString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|(
literal|"QNativeMouseMoveEvent(globalPos = %1 %2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|getPosAsString
argument_list|(
name|globalPos
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|getModifiersAsString
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|QNativeMouseButtonEvent
operator|::
name|toString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|(
literal|"QNativeMouseButtonEvent(globalPos = %1, %2, clickCount = %3, %4)"
argument_list|)
operator|.
name|arg
argument_list|(
name|getPosAsString
argument_list|(
name|globalPos
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|getButtonAsString
argument_list|(
name|this
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|clickCount
argument_list|)
operator|.
name|arg
argument_list|(
name|getModifiersAsString
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|QNativeMouseDragEvent
operator|::
name|toString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|(
literal|"QNativeMouseDragEvent(globalPos = %1, %2, clickCount = %3, %4)"
argument_list|)
operator|.
name|arg
argument_list|(
name|getPosAsString
argument_list|(
name|globalPos
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|getButtonAsString
argument_list|(
name|this
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|clickCount
argument_list|)
operator|.
name|arg
argument_list|(
name|getModifiersAsString
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|QNativeMouseWheelEvent
operator|::
name|toString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|(
literal|"QNativeMouseWheelEvent(globalPos = %1, delta = %2, %3)"
argument_list|)
operator|.
name|arg
argument_list|(
name|getPosAsString
argument_list|(
name|globalPos
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|delta
argument_list|)
operator|.
name|arg
argument_list|(
name|getModifiersAsString
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|QNativeKeyEvent
operator|::
name|toString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|(
literal|"QNativeKeyEvent(press = %1, native key code = %2, character = %3, %4)"
argument_list|)
operator|.
name|arg
argument_list|(
name|getBoolAsString
argument_list|(
name|press
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|nativeKeyCode
argument_list|)
operator|.
name|arg
argument_list|(
name|character
operator|.
name|isPrint
argument_list|()
condition|?
name|character
else|:
name|QString
argument_list|(
literal|"<no char>"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|getModifiersAsString
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|QNativeModifierEvent
operator|::
name|toString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|(
literal|"QNativeModifierEvent(%1, native key code = %2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|getModifiersAsString
argument_list|(
name|this
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|nativeKeyCode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|d
parameter_list|,
name|QNativeEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return
name|d
operator|<<
name|e
operator|->
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|d
parameter_list|,
specifier|const
name|QNativeEvent
modifier|&
name|e
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return
name|d
operator|<<
name|e
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QTextStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|s
operator|<<
name|e
operator|->
name|eventId
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|modifiers
operator|<<
literal|" QNativeEvent"
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QTextStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeMouseEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|s
operator|<<
name|e
operator|->
name|eventId
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|globalPos
operator|.
name|x
argument_list|()
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|globalPos
operator|.
name|y
argument_list|()
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|modifiers
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QTextStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeMouseMoveEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|s
operator|<<
name|e
operator|->
name|eventId
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|globalPos
operator|.
name|x
argument_list|()
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|globalPos
operator|.
name|y
argument_list|()
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|modifiers
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QTextStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeMouseButtonEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|s
operator|<<
name|e
operator|->
name|eventId
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|globalPos
operator|.
name|x
argument_list|()
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|globalPos
operator|.
name|y
argument_list|()
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|button
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|clickCount
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|modifiers
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QTextStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeMouseDragEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|s
operator|<<
name|e
operator|->
name|eventId
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|globalPos
operator|.
name|x
argument_list|()
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|globalPos
operator|.
name|y
argument_list|()
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|button
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|clickCount
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|modifiers
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QTextStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeMouseWheelEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|s
operator|<<
name|e
operator|->
name|eventId
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|globalPos
operator|.
name|x
argument_list|()
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|globalPos
operator|.
name|y
argument_list|()
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|delta
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|modifiers
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QTextStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeKeyEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|s
operator|<<
name|e
operator|->
name|eventId
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|press
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|nativeKeyCode
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|character
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|modifiers
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QTextStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeModifierEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|s
operator|<<
name|e
operator|->
name|eventId
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|modifiers
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|nativeKeyCode
operator|<<
literal|" "
operator|<<
name|e
operator|->
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator >>
name|QTextStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeMouseMoveEvent
modifier|*
name|e
parameter_list|)
block|{
comment|// Skip reading eventId.
name|QString
name|humanReadable
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|modifiers
decl_stmt|;
name|s
operator|>>
name|x
operator|>>
name|y
operator|>>
name|modifiers
operator|>>
name|humanReadable
expr_stmt|;
name|e
operator|->
name|globalPos
operator|.
name|setX
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|e
operator|->
name|globalPos
operator|.
name|setY
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|e
operator|->
name|modifiers
operator|=
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|modifiers
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|operator >>
name|QTextStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeMouseButtonEvent
modifier|*
name|e
parameter_list|)
block|{
comment|// Skip reading eventId.
name|QString
name|humanReadable
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|button
decl_stmt|,
name|clickCount
decl_stmt|,
name|modifiers
decl_stmt|;
name|s
operator|>>
name|x
operator|>>
name|y
operator|>>
name|button
operator|>>
name|clickCount
operator|>>
name|modifiers
operator|>>
name|humanReadable
expr_stmt|;
name|e
operator|->
name|globalPos
operator|.
name|setX
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|e
operator|->
name|globalPos
operator|.
name|setY
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|e
operator|->
name|clickCount
operator|=
name|clickCount
expr_stmt|;
name|e
operator|->
name|modifiers
operator|=
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|modifiers
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|button
condition|)
block|{
case|case
literal|1
case|:
name|e
operator|->
name|button
operator|=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|e
operator|->
name|button
operator|=
name|Qt
operator|::
name|RightButton
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|e
operator|->
name|button
operator|=
name|Qt
operator|::
name|MidButton
expr_stmt|;
break|break;
default|default:
name|e
operator|->
name|button
operator|=
name|Qt
operator|::
name|NoButton
expr_stmt|;
break|break;
block|}
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|operator >>
name|QTextStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeMouseDragEvent
modifier|*
name|e
parameter_list|)
block|{
comment|// Skip reading eventId.
name|QString
name|humanReadable
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|button
decl_stmt|,
name|clickCount
decl_stmt|,
name|modifiers
decl_stmt|;
name|s
operator|>>
name|x
operator|>>
name|y
operator|>>
name|button
operator|>>
name|clickCount
operator|>>
name|modifiers
operator|>>
name|humanReadable
expr_stmt|;
name|e
operator|->
name|globalPos
operator|.
name|setX
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|e
operator|->
name|globalPos
operator|.
name|setY
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|e
operator|->
name|clickCount
operator|=
name|clickCount
expr_stmt|;
name|e
operator|->
name|modifiers
operator|=
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|modifiers
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|button
condition|)
block|{
case|case
literal|1
case|:
name|e
operator|->
name|button
operator|=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|e
operator|->
name|button
operator|=
name|Qt
operator|::
name|RightButton
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|e
operator|->
name|button
operator|=
name|Qt
operator|::
name|MidButton
expr_stmt|;
break|break;
default|default:
name|e
operator|->
name|button
operator|=
name|Qt
operator|::
name|NoButton
expr_stmt|;
break|break;
block|}
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|operator >>
name|QTextStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeMouseWheelEvent
modifier|*
name|e
parameter_list|)
block|{
comment|// Skip reading eventId.
name|QString
name|humanReadable
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|modifiers
decl_stmt|;
name|s
operator|>>
name|x
operator|>>
name|y
operator|>>
name|e
operator|->
name|delta
operator|>>
name|modifiers
operator|>>
name|humanReadable
expr_stmt|;
name|e
operator|->
name|globalPos
operator|.
name|setX
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|e
operator|->
name|globalPos
operator|.
name|setY
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|e
operator|->
name|modifiers
operator|=
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|modifiers
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|operator >>
name|QTextStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeKeyEvent
modifier|*
name|e
parameter_list|)
block|{
comment|// Skip reading eventId.
name|QString
name|humanReadable
decl_stmt|;
name|int
name|press
decl_stmt|,
name|modifiers
decl_stmt|;
name|QString
name|character
decl_stmt|;
name|s
operator|>>
name|press
operator|>>
name|e
operator|->
name|nativeKeyCode
operator|>>
name|character
operator|>>
name|modifiers
operator|>>
name|humanReadable
expr_stmt|;
name|e
operator|->
name|press
operator|=
name|bool
argument_list|(
name|press
argument_list|)
expr_stmt|;
name|e
operator|->
name|character
operator|=
name|character
index|[
literal|0
index|]
expr_stmt|;
name|e
operator|->
name|modifiers
operator|=
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|modifiers
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|operator >>
name|QTextStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QTextStream
modifier|&
name|s
parameter_list|,
name|QNativeModifierEvent
modifier|*
name|e
parameter_list|)
block|{
comment|// Skip reading eventId.
name|QString
name|humanReadable
decl_stmt|;
name|int
name|modifiers
decl_stmt|;
name|s
operator|>>
name|modifiers
operator|>>
name|e
operator|->
name|nativeKeyCode
operator|>>
name|humanReadable
expr_stmt|;
name|e
operator|->
name|modifiers
operator|=
name|Qt
operator|::
name|KeyboardModifiers
argument_list|(
name|modifiers
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
end_unit
