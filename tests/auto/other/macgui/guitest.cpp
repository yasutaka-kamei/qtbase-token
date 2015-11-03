begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"guitest.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QStack>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<ApplicationServices/ApplicationServices.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*     Not really a test, just prints interface info. */
end_comment
begin_class
DECL|class|PrintTest
class|class
name|PrintTest
super|:
specifier|public
name|TestBase
block|{
public|public:
DECL|function|operator ()
name|bool
name|operator
name|()
parameter_list|(
name|QAccessibleInterface
modifier|*
name|candidate
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Name"
operator|<<
name|candidate
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|Name
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Pos"
operator|<<
name|candidate
operator|->
name|rect
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Number of children"
operator|<<
name|candidate
operator|->
name|childCount
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|NameTest
class|class
name|NameTest
super|:
specifier|public
name|TestBase
block|{
public|public:
DECL|function|NameTest
name|NameTest
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QAccessible
operator|::
name|Text
name|textType
parameter_list|)
member_init_list|:
name|text
argument_list|(
name|text
argument_list|)
member_init_list|,
name|textType
argument_list|(
name|textType
argument_list|)
block|{}
DECL|member|text
name|QString
name|text
decl_stmt|;
DECL|member|textType
name|QAccessible
operator|::
name|Text
name|textType
decl_stmt|;
DECL|function|operator ()
name|bool
name|operator
name|()
parameter_list|(
name|QAccessibleInterface
modifier|*
name|candidate
parameter_list|)
block|{
return|return
operator|(
name|candidate
operator|->
name|text
argument_list|(
name|textType
argument_list|)
operator|==
name|text
operator|)
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|printAll
name|void
name|WidgetNavigator
operator|::
name|printAll
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|QAccessibleInterface
modifier|*
specifier|const
name|iface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|widget
argument_list|)
decl_stmt|;
name|printAll
argument_list|(
name|iface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printAll
name|void
name|WidgetNavigator
operator|::
name|printAll
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
block|{
name|PrintTest
name|printTest
decl_stmt|;
name|recursiveSearch
argument_list|(
operator|&
name|printTest
argument_list|,
name|interface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|find
name|QAccessibleInterface
modifier|*
name|WidgetNavigator
operator|::
name|find
parameter_list|(
name|QAccessible
operator|::
name|Text
name|textType
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|start
parameter_list|)
block|{
name|QAccessibleInterface
modifier|*
specifier|const
name|iface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|start
argument_list|)
decl_stmt|;
return|return
name|find
argument_list|(
name|textType
argument_list|,
name|text
argument_list|,
name|iface
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|find
name|QAccessibleInterface
modifier|*
name|WidgetNavigator
operator|::
name|find
parameter_list|(
name|QAccessible
operator|::
name|Text
name|textType
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QAccessibleInterface
modifier|*
name|start
parameter_list|)
block|{
name|NameTest
name|nameTest
argument_list|(
name|text
argument_list|,
name|textType
argument_list|)
decl_stmt|;
return|return
name|recursiveSearch
argument_list|(
operator|&
name|nameTest
argument_list|,
name|start
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*     Recursiveley navigates the accessible hiearchy looking for an interface that     passsed the Test (meaning it returns true). */
end_comment
begin_function
DECL|function|recursiveSearch
name|QAccessibleInterface
modifier|*
name|WidgetNavigator
operator|::
name|recursiveSearch
parameter_list|(
name|TestBase
modifier|*
name|test
parameter_list|,
name|QAccessibleInterface
modifier|*
name|iface
parameter_list|)
block|{
name|QStack
argument_list|<
name|QAccessibleInterface
modifier|*
argument_list|>
name|todoInterfaces
decl_stmt|;
name|todoInterfaces
operator|.
name|push
argument_list|(
name|iface
argument_list|)
expr_stmt|;
while|while
condition|(
name|todoInterfaces
operator|.
name|isEmpty
argument_list|()
operator|==
literal|false
condition|)
block|{
name|QAccessibleInterface
modifier|*
name|testInterface
init|=
name|todoInterfaces
operator|.
name|pop
argument_list|()
decl_stmt|;
if|if
condition|(
call|(
modifier|*
name|test
call|)
argument_list|(
name|testInterface
argument_list|)
condition|)
return|return
name|testInterface
return|;
specifier|const
name|int
name|numChildren
init|=
name|testInterface
operator|->
name|childCount
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numChildren
condition|;
operator|++
name|i
control|)
block|{
name|QAccessibleInterface
modifier|*
name|childInterface
init|=
name|testInterface
operator|->
name|child
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|childInterface
condition|)
block|{
name|todoInterfaces
operator|.
name|push
argument_list|(
name|childInterface
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|getWidget
name|QWidget
modifier|*
name|WidgetNavigator
operator|::
name|getWidget
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
block|{
return|return
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|interface
operator|->
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_destructor
DECL|function|~WidgetNavigator
name|WidgetNavigator
operator|::
name|~
name|WidgetNavigator
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment
begin_namespace
DECL|namespace|NativeEvents
namespace|namespace
name|NativeEvents
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
DECL|function|mouseClick
name|void
name|mouseClick
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|globalPos
parameter_list|,
name|Qt
operator|::
name|MouseButtons
name|buttons
parameter_list|)
block|{
name|CGPoint
name|position
decl_stmt|;
name|position
operator|.
name|x
operator|=
name|globalPos
operator|.
name|x
argument_list|()
expr_stmt|;
name|position
operator|.
name|y
operator|=
name|globalPos
operator|.
name|y
argument_list|()
expr_stmt|;
name|CGEventType
name|mouseDownType
init|=
operator|(
name|buttons
operator|&
name|Qt
operator|::
name|LeftButton
operator|)
condition|?
name|kCGEventLeftMouseDown
else|:
operator|(
name|buttons
operator|&
name|Qt
operator|::
name|RightButton
operator|)
condition|?
name|kCGEventRightMouseDown
else|:
name|kCGEventOtherMouseDown
decl_stmt|;
comment|// The mouseButton argument to CGEventCreateMouseEvent() is ignored unless the type
comment|// is kCGEventOtherMouseDown, so defaulting to kCGMouseButtonLeft is fine.
name|CGMouseButton
name|mouseButton
init|=
name|mouseDownType
operator|==
name|kCGEventOtherMouseDown
condition|?
name|kCGMouseButtonCenter
else|:
name|kCGMouseButtonLeft
decl_stmt|;
name|CGEventRef
name|mouseEvent
init|=
name|CGEventCreateMouseEvent
argument_list|(
name|NULL
argument_list|,
name|mouseDownType
argument_list|,
name|position
argument_list|,
name|mouseButton
argument_list|)
decl_stmt|;
name|CGEventPost
argument_list|(
name|kCGHIDEventTap
argument_list|,
name|mouseEvent
argument_list|)
expr_stmt|;
name|CGEventType
name|mouseUpType
init|=
operator|(
name|buttons
operator|&
name|Qt
operator|::
name|LeftButton
operator|)
condition|?
name|kCGEventLeftMouseUp
else|:
operator|(
name|buttons
operator|&
name|Qt
operator|::
name|RightButton
operator|)
condition|?
name|kCGEventRightMouseUp
else|:
name|kCGEventOtherMouseUp
decl_stmt|;
name|CGEventSetType
argument_list|(
name|mouseEvent
argument_list|,
name|mouseUpType
argument_list|)
expr_stmt|;
name|CGEventPost
argument_list|(
name|kCGHIDEventTap
argument_list|,
name|mouseEvent
argument_list|)
expr_stmt|;
name|CFRelease
argument_list|(
name|mouseEvent
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
error|#
directive|error
error|Oops, NativeEvents::mouseClick() is not implemented on this platform.
endif|#
directive|endif
block|}
end_namespace
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment
begin_constructor
DECL|function|GuiTester
name|GuiTester
operator|::
name|GuiTester
parameter_list|()
block|{
name|clearSequence
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~GuiTester
name|GuiTester
operator|::
name|~
name|GuiTester
parameter_list|()
block|{
foreach|foreach
control|(
name|DelayedAction
modifier|*
name|action
decl|,
name|actions
control|)
operator|delete
name|action
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|checkPixel
name|bool
name|checkPixel
parameter_list|(
name|QColor
name|pixel
parameter_list|,
name|QColor
name|expected
parameter_list|)
block|{
specifier|const
name|int
name|allowedDiff
init|=
literal|20
decl_stmt|;
return|return
operator|!
operator|(
name|qAbs
argument_list|(
name|pixel
operator|.
name|red
argument_list|()
operator|-
name|expected
operator|.
name|red
argument_list|()
argument_list|)
operator|>
name|allowedDiff
operator|||
name|qAbs
argument_list|(
name|pixel
operator|.
name|green
argument_list|()
operator|-
name|expected
operator|.
name|green
argument_list|()
argument_list|)
operator|>
name|allowedDiff
operator|||
name|qAbs
argument_list|(
name|pixel
operator|.
name|blue
argument_list|()
operator|-
name|expected
operator|.
name|blue
argument_list|()
argument_list|)
operator|>
name|allowedDiff
operator|)
return|;
block|}
end_function
begin_comment
comment|/*     Tests that the pixels inside rect in image all have the given color. */
end_comment
begin_function
DECL|function|isFilled
name|bool
name|GuiTester
operator|::
name|isFilled
parameter_list|(
specifier|const
name|QImage
name|image
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
for|for
control|(
name|int
name|y
init|=
name|rect
operator|.
name|top
argument_list|()
init|;
name|y
operator|<=
name|rect
operator|.
name|bottom
argument_list|()
condition|;
operator|++
name|y
control|)
for|for
control|(
name|int
name|x
init|=
name|rect
operator|.
name|left
argument_list|()
init|;
name|x
operator|<=
name|rect
operator|.
name|right
argument_list|()
condition|;
operator|++
name|x
control|)
block|{
specifier|const
name|QColor
name|pixel
init|=
name|image
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
if|if
condition|(
name|checkPixel
argument_list|(
name|pixel
argument_list|,
name|color
argument_list|)
operator|==
literal|false
condition|)
block|{
comment|//                qDebug()<< "Wrong pixel value at"<< x<< y<< pixel.red()<< pixel.green()<< pixel.blue();
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*     Tests that stuff is painted to the pixels inside rect.     This test fails if any lines in the given direction have pixels     of only one color. */
end_comment
begin_function
DECL|function|isContent
name|bool
name|GuiTester
operator|::
name|isContent
parameter_list|(
specifier|const
name|QImage
name|image
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|Directions
name|directions
parameter_list|)
block|{
if|if
condition|(
name|directions
operator|&
name|Horizontal
condition|)
block|{
for|for
control|(
name|int
name|y
init|=
name|rect
operator|.
name|top
argument_list|()
init|;
name|y
operator|<=
name|rect
operator|.
name|bottom
argument_list|()
condition|;
operator|++
name|y
control|)
block|{
name|QColor
name|currentColor
init|=
name|image
operator|.
name|pixel
argument_list|(
name|rect
operator|.
name|left
argument_list|()
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|bool
name|fullRun
init|=
literal|true
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
name|rect
operator|.
name|left
argument_list|()
operator|+
literal|1
init|;
name|x
operator|<=
name|rect
operator|.
name|right
argument_list|()
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
name|checkPixel
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|,
name|currentColor
argument_list|)
operator|==
literal|false
condition|)
block|{
name|fullRun
operator|=
literal|false
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|fullRun
condition|)
block|{
comment|//                qDebug()<< "Single-color line at horizontal line "<< y<< currentColor;
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
if|if
condition|(
name|directions
operator|&
name|Vertical
condition|)
block|{
for|for
control|(
name|int
name|x
init|=
name|rect
operator|.
name|left
argument_list|()
init|;
name|x
operator|<=
name|rect
operator|.
name|right
argument_list|()
condition|;
operator|++
name|x
control|)
block|{
name|QRgb
name|currentColor
init|=
name|image
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|rect
operator|.
name|top
argument_list|()
argument_list|)
decl_stmt|;
name|bool
name|fullRun
init|=
literal|true
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
name|rect
operator|.
name|top
argument_list|()
operator|+
literal|1
init|;
name|y
operator|<=
name|rect
operator|.
name|bottom
argument_list|()
condition|;
operator|++
name|y
control|)
block|{
if|if
condition|(
name|checkPixel
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|,
name|currentColor
argument_list|)
operator|==
literal|false
condition|)
block|{
name|fullRun
operator|=
literal|false
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|fullRun
condition|)
block|{
comment|//                qDebug()<< "Single-color line at vertical line"<< x<< currentColor;
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
comment|// shut the compiler up.
block|}
end_function
begin_function
DECL|function|run
name|void
name|DelayedAction
operator|::
name|run
parameter_list|()
block|{
if|if
condition|(
name|next
condition|)
name|QTimer
operator|::
name|singleShot
argument_list|(
name|next
operator|->
name|delay
argument_list|,
name|next
argument_list|,
name|SLOT
argument_list|(
name|run
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*     Schedules a mouse click at an interface using a singleShot timer.     Only one click can be scheduled at a time. */
end_comment
begin_constructor
DECL|function|ClickLaterAction
name|ClickLaterAction
operator|::
name|ClickLaterAction
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|,
name|Qt
operator|::
name|MouseButtons
name|buttons
parameter_list|)
block|{
name|this
operator|->
name|useInterface
operator|=
literal|true
expr_stmt|;
name|this
operator|->
name|interface
operator|=
name|interface
expr_stmt|;
name|this
operator|->
name|buttons
operator|=
name|buttons
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*     Schedules a mouse click at a widget using a singleShot timer.     Only one click can be scheduled at a time. */
end_comment
begin_constructor
DECL|function|ClickLaterAction
name|ClickLaterAction
operator|::
name|ClickLaterAction
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|Qt
operator|::
name|MouseButtons
name|buttons
parameter_list|)
block|{
name|this
operator|->
name|useInterface
operator|=
literal|false
expr_stmt|;
name|this
operator|->
name|widget
operator|=
name|widget
expr_stmt|;
name|this
operator|->
name|buttons
operator|=
name|buttons
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|run
name|void
name|ClickLaterAction
operator|::
name|run
parameter_list|()
block|{
if|if
condition|(
name|useInterface
condition|)
block|{
specifier|const
name|QPoint
name|globalCenter
init|=
name|interface
operator|->
name|rect
argument_list|()
operator|.
name|center
argument_list|()
decl_stmt|;
name|NativeEvents
operator|::
name|mouseClick
argument_list|(
name|globalCenter
argument_list|,
name|buttons
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// use widget
specifier|const
name|QSize
name|halfSize
init|=
name|widget
operator|->
name|size
argument_list|()
operator|/
literal|2
decl_stmt|;
specifier|const
name|QPoint
name|globalCenter
init|=
name|widget
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
name|halfSize
operator|.
name|width
argument_list|()
argument_list|,
name|halfSize
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|NativeEvents
operator|::
name|mouseClick
argument_list|(
name|globalCenter
argument_list|,
name|buttons
argument_list|)
expr_stmt|;
block|}
name|DelayedAction
operator|::
name|run
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clickLater
name|void
name|GuiTester
operator|::
name|clickLater
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|,
name|Qt
operator|::
name|MouseButtons
name|buttons
parameter_list|,
name|int
name|delay
parameter_list|)
block|{
name|clearSequence
argument_list|()
expr_stmt|;
name|addToSequence
argument_list|(
operator|new
name|ClickLaterAction
argument_list|(
name|interface
argument_list|,
name|buttons
argument_list|)
argument_list|,
name|delay
argument_list|)
expr_stmt|;
name|runSequence
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clickLater
name|void
name|GuiTester
operator|::
name|clickLater
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|Qt
operator|::
name|MouseButtons
name|buttons
parameter_list|,
name|int
name|delay
parameter_list|)
block|{
name|clearSequence
argument_list|()
expr_stmt|;
name|addToSequence
argument_list|(
operator|new
name|ClickLaterAction
argument_list|(
name|widget
argument_list|,
name|buttons
argument_list|)
argument_list|,
name|delay
argument_list|)
expr_stmt|;
name|runSequence
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearSequence
name|void
name|GuiTester
operator|::
name|clearSequence
parameter_list|()
block|{
name|startAction
operator|=
operator|new
name|DelayedAction
argument_list|()
expr_stmt|;
name|actions
operator|.
name|insert
argument_list|(
name|startAction
argument_list|)
expr_stmt|;
name|lastAction
operator|=
name|startAction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addToSequence
name|void
name|GuiTester
operator|::
name|addToSequence
parameter_list|(
name|DelayedAction
modifier|*
name|action
parameter_list|,
name|int
name|delay
parameter_list|)
block|{
name|actions
operator|.
name|insert
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|action
operator|->
name|delay
operator|=
name|delay
expr_stmt|;
name|lastAction
operator|->
name|next
operator|=
name|action
expr_stmt|;
name|lastAction
operator|=
name|action
expr_stmt|;
block|}
end_function
begin_function
DECL|function|runSequence
name|void
name|GuiTester
operator|::
name|runSequence
parameter_list|()
block|{
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|startAction
argument_list|,
name|SLOT
argument_list|(
name|run
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|exitLoopSlot
name|void
name|GuiTester
operator|::
name|exitLoopSlot
parameter_list|()
block|{
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|exitLoop
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
