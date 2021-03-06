begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTKEYBOARD_H
end_ifndef
begin_define
DECL|macro|QTESTKEYBOARD_H
define|#
directive|define
name|QTESTKEYBOARD_H
end_define
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// inform syncqt
end_comment
begin_pragma
pragma|#
directive|pragma
name|qt_no_master_include
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtTest/qtestassert.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestsystem.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestspontaneevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qapplication.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_GUI_EXPORT
name|void
name|qt_handleKeyEvent
argument_list|(
name|QWindow
operator|*
name|w
argument_list|,
name|QEvent
operator|::
name|Type
name|t
argument_list|,
name|int
name|k
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
argument_list|,
specifier|const
name|QString
operator|&
name|text
operator|=
name|QString
argument_list|()
argument_list|,
name|bool
name|autorep
operator|=
name|false
argument_list|,
name|ushort
name|count
operator|=
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Q_GUI_EXPORT
name|bool
name|qt_sendShortcutOverrideEvent
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|ulong
name|timestamp
argument_list|,
name|int
name|k
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
argument_list|,
specifier|const
name|QString
operator|&
name|text
operator|=
name|QString
argument_list|()
argument_list|,
name|bool
name|autorep
operator|=
name|false
argument_list|,
name|ushort
name|count
operator|=
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QTest
block|{
enum|enum
name|KeyAction
block|{
name|Press
block|,
name|Release
block|,
name|Click
block|,
name|Shortcut
block|}
enum|;
specifier|static
name|void
name|simulateEvent
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|bool
name|press
argument_list|,
name|int
name|code
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
argument_list|,
name|QString
name|text
argument_list|,
name|bool
name|repeat
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|QEvent
operator|::
name|Type
name|type
expr_stmt|;
name|type
operator|=
name|press
condition|?
name|QEvent
operator|::
name|KeyPress
else|:
name|QEvent
operator|::
name|KeyRelease
expr_stmt|;
name|qt_handleKeyEvent
argument_list|(
name|window
argument_list|,
name|type
argument_list|,
name|code
argument_list|,
name|modifier
argument_list|,
name|text
argument_list|,
name|repeat
argument_list|,
name|delay
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
block|}
specifier|static
name|void
name|sendKeyEvent
argument_list|(
name|KeyAction
name|action
argument_list|,
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|Key
name|code
argument_list|,
name|QString
name|text
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|QTEST_ASSERT
argument_list|(
name|qApp
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|window
condition|)
name|window
operator|=
name|QGuiApplication
operator|::
name|focusWindow
argument_list|()
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
name|action
operator|==
name|Click
condition|)
block|{
name|sendKeyEvent
argument_list|(
name|Press
argument_list|,
name|window
argument_list|,
name|code
argument_list|,
name|text
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
name|sendKeyEvent
argument_list|(
name|Release
argument_list|,
name|window
argument_list|,
name|code
argument_list|,
name|text
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
return|return;
block|}
name|bool
name|repeat
init|=
name|false
decl_stmt|;
if|if
condition|(
name|action
operator|==
name|Shortcut
condition|)
block|{
name|int
name|timestamp
init|=
literal|0
decl_stmt|;
name|qt_sendShortcutOverrideEvent
argument_list|(
name|window
argument_list|,
name|timestamp
argument_list|,
name|code
argument_list|,
name|modifier
argument_list|,
name|text
argument_list|,
name|repeat
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|action
operator|==
name|Press
condition|)
block|{
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|ShiftModifier
condition|)
name|simulateEvent
argument_list|(
name|window
argument_list|,
name|true
argument_list|,
name|Qt
operator|::
name|Key_Shift
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|ControlModifier
condition|)
name|simulateEvent
argument_list|(
name|window
argument_list|,
name|true
argument_list|,
name|Qt
operator|::
name|Key_Control
argument_list|,
name|modifier
operator|&
name|Qt
operator|::
name|ShiftModifier
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|AltModifier
condition|)
name|simulateEvent
argument_list|(
name|window
argument_list|,
name|true
argument_list|,
name|Qt
operator|::
name|Key_Alt
argument_list|,
name|modifier
operator|&
operator|(
name|Qt
operator|::
name|ShiftModifier
operator||
name|Qt
operator|::
name|ControlModifier
operator|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|MetaModifier
condition|)
name|simulateEvent
argument_list|(
name|window
argument_list|,
name|true
argument_list|,
name|Qt
operator|::
name|Key_Meta
argument_list|,
name|modifier
operator|&
operator|(
name|Qt
operator|::
name|ShiftModifier
operator||
name|Qt
operator|::
name|ControlModifier
operator||
name|Qt
operator|::
name|AltModifier
operator|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
name|simulateEvent
argument_list|(
name|window
argument_list|,
name|true
argument_list|,
name|code
argument_list|,
name|modifier
argument_list|,
name|text
argument_list|,
name|repeat
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|action
operator|==
name|Release
condition|)
block|{
name|simulateEvent
argument_list|(
name|window
argument_list|,
name|false
argument_list|,
name|code
argument_list|,
name|modifier
argument_list|,
name|text
argument_list|,
name|repeat
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|MetaModifier
condition|)
name|simulateEvent
argument_list|(
name|window
argument_list|,
name|false
argument_list|,
name|Qt
operator|::
name|Key_Meta
argument_list|,
name|modifier
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|AltModifier
condition|)
name|simulateEvent
argument_list|(
name|window
argument_list|,
name|false
argument_list|,
name|Qt
operator|::
name|Key_Alt
argument_list|,
name|modifier
operator|&
operator|(
name|Qt
operator|::
name|ShiftModifier
operator||
name|Qt
operator|::
name|ControlModifier
operator||
name|Qt
operator|::
name|AltModifier
operator|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|ControlModifier
condition|)
name|simulateEvent
argument_list|(
name|window
argument_list|,
name|false
argument_list|,
name|Qt
operator|::
name|Key_Control
argument_list|,
name|modifier
operator|&
operator|(
name|Qt
operator|::
name|ShiftModifier
operator||
name|Qt
operator|::
name|ControlModifier
operator|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|ShiftModifier
condition|)
name|simulateEvent
argument_list|(
name|window
argument_list|,
name|false
argument_list|,
name|Qt
operator|::
name|Key_Shift
argument_list|,
name|modifier
operator|&
name|Qt
operator|::
name|ShiftModifier
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Convenience function
specifier|static
name|void
name|sendKeyEvent
argument_list|(
name|KeyAction
name|action
argument_list|,
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|Key
name|code
argument_list|,
name|char
name|ascii
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|QString
name|text
decl_stmt|;
if|if
condition|(
name|ascii
condition|)
name|text
operator|=
name|QString
argument_list|(
name|QChar
operator|::
name|fromLatin1
argument_list|(
name|ascii
argument_list|)
argument_list|)
expr_stmt|;
name|sendKeyEvent
argument_list|(
name|action
argument_list|,
name|window
argument_list|,
name|code
argument_list|,
name|text
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyEvent
argument_list|(
name|KeyAction
name|action
argument_list|,
name|QWindow
operator|*
name|window
argument_list|,
name|char
name|ascii
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|sendKeyEvent
argument_list|(
name|action
argument_list|,
name|window
argument_list|,
name|asciiToKey
argument_list|(
name|ascii
argument_list|)
argument_list|,
name|ascii
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyEvent
argument_list|(
name|KeyAction
name|action
argument_list|,
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|Key
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|sendKeyEvent
argument_list|(
name|action
argument_list|,
name|window
argument_list|,
name|key
argument_list|,
name|keyToAscii
argument_list|(
name|key
argument_list|)
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
name|Q_DECL_UNUSED
specifier|inline
specifier|static
name|void
name|keyClick
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|Key
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Click
argument_list|,
name|window
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
name|Q_DECL_UNUSED
specifier|inline
specifier|static
name|void
name|keyClick
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|char
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Click
argument_list|,
name|window
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
name|Q_DECL_UNUSED
specifier|inline
specifier|static
name|void
name|keyRelease
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|char
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Release
argument_list|,
name|window
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
name|Q_DECL_UNUSED
specifier|inline
specifier|static
name|void
name|keyRelease
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|Key
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Release
argument_list|,
name|window
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
name|Q_DECL_UNUSED
specifier|inline
specifier|static
name|void
name|keyPress
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|char
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Press
argument_list|,
name|window
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
name|Q_DECL_UNUSED
specifier|inline
specifier|static
name|void
name|keyPress
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|Qt
operator|::
name|Key
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Press
argument_list|,
name|window
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
specifier|static
name|void
name|simulateEvent
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|bool
name|press
argument_list|,
name|int
name|code
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
argument_list|,
name|QString
name|text
argument_list|,
name|bool
name|repeat
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|QTEST_ASSERT
argument_list|(
name|widget
argument_list|)
expr_stmt|;
specifier|extern
name|int
name|Q_TESTLIB_EXPORT
name|defaultKeyDelay
parameter_list|()
function_decl|;
if|if
condition|(
name|delay
operator|==
operator|-
literal|1
operator|||
name|delay
operator|<
name|defaultKeyDelay
argument_list|()
condition|)
name|delay
operator|=
name|defaultKeyDelay
argument_list|()
expr_stmt|;
if|if
condition|(
name|delay
operator|>
literal|0
condition|)
name|QTest
operator|::
name|qWait
argument_list|(
name|delay
argument_list|)
expr_stmt|;
name|QKeyEvent
name|a
argument_list|(
name|press
condition|?
name|QEvent
operator|::
name|KeyPress
else|:
name|QEvent
operator|::
name|KeyRelease
argument_list|,
name|code
argument_list|,
name|modifier
argument_list|,
name|text
argument_list|,
name|repeat
argument_list|)
decl_stmt|;
name|QSpontaneKeyEvent
operator|::
name|setSpontaneous
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
if|if
condition|(
name|press
operator|&&
name|qt_sendShortcutOverrideEvent
argument_list|(
name|widget
argument_list|,
name|a
operator|.
name|timestamp
argument_list|()
argument_list|,
name|code
argument_list|,
name|modifier
argument_list|,
name|text
argument_list|,
name|repeat
argument_list|)
condition|)
return|return;
if|if
condition|(
operator|!
name|qApp
operator|->
name|notify
argument_list|(
name|widget
argument_list|,
operator|&
name|a
argument_list|)
condition|)
name|QTest
operator|::
name|qWarn
argument_list|(
literal|"Keyboard event not accepted by receiving widget"
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|sendKeyEvent
argument_list|(
name|KeyAction
name|action
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|Key
name|code
argument_list|,
name|QString
name|text
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|QTEST_ASSERT
argument_list|(
name|qApp
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
name|widget
operator|=
name|QWidget
operator|::
name|keyboardGrabber
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
block|{
comment|// Popup widgets stealthily steal the keyboard grab
if|if
condition|(
name|QWidget
modifier|*
name|apw
init|=
name|QApplication
operator|::
name|activePopupWidget
argument_list|()
condition|)
name|widget
operator|=
name|apw
operator|->
name|focusWidget
argument_list|()
condition|?
name|apw
operator|->
name|focusWidget
argument_list|()
else|:
name|apw
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|widget
condition|)
block|{
name|QWindow
modifier|*
name|window
init|=
name|QGuiApplication
operator|::
name|focusWindow
argument_list|()
decl_stmt|;
if|if
condition|(
name|window
condition|)
block|{
name|sendKeyEvent
argument_list|(
name|action
argument_list|,
name|window
argument_list|,
name|code
argument_list|,
name|text
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
if|if
condition|(
operator|!
name|widget
condition|)
name|widget
operator|=
name|QApplication
operator|::
name|focusWidget
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
name|widget
operator|=
name|QApplication
operator|::
name|activeWindow
argument_list|()
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|widget
argument_list|)
expr_stmt|;
if|if
condition|(
name|action
operator|==
name|Click
condition|)
block|{
name|QPointer
operator|<
name|QWidget
operator|>
name|ptr
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|sendKeyEvent
argument_list|(
name|Press
argument_list|,
name|widget
argument_list|,
name|code
argument_list|,
name|text
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ptr
condition|)
block|{
comment|// if we send key-events to embedded widgets, they might be destroyed
comment|// when the user presses Return
return|return;
block|}
name|sendKeyEvent
argument_list|(
name|Release
argument_list|,
name|widget
argument_list|,
name|code
argument_list|,
name|text
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
return|return;
block|}
name|bool
name|repeat
init|=
name|false
decl_stmt|;
if|if
condition|(
name|action
operator|==
name|Press
condition|)
block|{
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|ShiftModifier
condition|)
name|simulateEvent
argument_list|(
name|widget
argument_list|,
name|true
argument_list|,
name|Qt
operator|::
name|Key_Shift
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|ControlModifier
condition|)
name|simulateEvent
argument_list|(
name|widget
argument_list|,
name|true
argument_list|,
name|Qt
operator|::
name|Key_Control
argument_list|,
name|modifier
operator|&
name|Qt
operator|::
name|ShiftModifier
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|AltModifier
condition|)
name|simulateEvent
argument_list|(
name|widget
argument_list|,
name|true
argument_list|,
name|Qt
operator|::
name|Key_Alt
argument_list|,
name|modifier
operator|&
operator|(
name|Qt
operator|::
name|ShiftModifier
operator||
name|Qt
operator|::
name|ControlModifier
operator|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|MetaModifier
condition|)
name|simulateEvent
argument_list|(
name|widget
argument_list|,
name|true
argument_list|,
name|Qt
operator|::
name|Key_Meta
argument_list|,
name|modifier
operator|&
operator|(
name|Qt
operator|::
name|ShiftModifier
operator||
name|Qt
operator|::
name|ControlModifier
operator||
name|Qt
operator|::
name|AltModifier
operator|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
name|simulateEvent
argument_list|(
name|widget
argument_list|,
name|true
argument_list|,
name|code
argument_list|,
name|modifier
argument_list|,
name|text
argument_list|,
name|repeat
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|action
operator|==
name|Release
condition|)
block|{
name|simulateEvent
argument_list|(
name|widget
argument_list|,
name|false
argument_list|,
name|code
argument_list|,
name|modifier
argument_list|,
name|text
argument_list|,
name|repeat
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|MetaModifier
condition|)
name|simulateEvent
argument_list|(
name|widget
argument_list|,
name|false
argument_list|,
name|Qt
operator|::
name|Key_Meta
argument_list|,
name|modifier
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|AltModifier
condition|)
name|simulateEvent
argument_list|(
name|widget
argument_list|,
name|false
argument_list|,
name|Qt
operator|::
name|Key_Alt
argument_list|,
name|modifier
operator|&
operator|(
name|Qt
operator|::
name|ShiftModifier
operator||
name|Qt
operator|::
name|ControlModifier
operator||
name|Qt
operator|::
name|AltModifier
operator|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|ControlModifier
condition|)
name|simulateEvent
argument_list|(
name|widget
argument_list|,
name|false
argument_list|,
name|Qt
operator|::
name|Key_Control
argument_list|,
name|modifier
operator|&
operator|(
name|Qt
operator|::
name|ShiftModifier
operator||
name|Qt
operator|::
name|ControlModifier
operator|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
if|if
condition|(
name|modifier
operator|&
name|Qt
operator|::
name|ShiftModifier
condition|)
name|simulateEvent
argument_list|(
name|widget
argument_list|,
name|false
argument_list|,
name|Qt
operator|::
name|Key_Shift
argument_list|,
name|modifier
operator|&
name|Qt
operator|::
name|ShiftModifier
argument_list|,
name|QString
argument_list|()
argument_list|,
name|false
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Convenience function
specifier|static
name|void
name|sendKeyEvent
argument_list|(
name|KeyAction
name|action
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|Key
name|code
argument_list|,
name|char
name|ascii
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|QString
name|text
decl_stmt|;
if|if
condition|(
name|ascii
condition|)
name|text
operator|=
name|QString
argument_list|(
name|QChar
operator|::
name|fromLatin1
argument_list|(
name|ascii
argument_list|)
argument_list|)
expr_stmt|;
name|sendKeyEvent
argument_list|(
name|action
argument_list|,
name|widget
argument_list|,
name|code
argument_list|,
name|text
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyEvent
argument_list|(
name|KeyAction
name|action
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|,
name|char
name|ascii
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|sendKeyEvent
argument_list|(
name|action
argument_list|,
name|widget
argument_list|,
name|asciiToKey
argument_list|(
name|ascii
argument_list|)
argument_list|,
name|ascii
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyEvent
argument_list|(
name|KeyAction
name|action
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|Key
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|sendKeyEvent
argument_list|(
name|action
argument_list|,
name|widget
argument_list|,
name|key
argument_list|,
name|keyToAscii
argument_list|(
name|key
argument_list|)
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyClicks
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QString
operator|&
name|sequence
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|sequence
operator|.
name|length
argument_list|()
condition|;
name|i
operator|++
control|)
name|keyEvent
argument_list|(
name|Click
argument_list|,
name|widget
argument_list|,
name|sequence
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyPress
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|char
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Press
argument_list|,
name|widget
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyRelease
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|char
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Release
argument_list|,
name|widget
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyClick
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|char
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Click
argument_list|,
name|widget
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyPress
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|Key
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Press
argument_list|,
name|widget
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyRelease
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|Key
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Release
argument_list|,
name|widget
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
specifier|inline
specifier|static
name|void
name|keyClick
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|Qt
operator|::
name|Key
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifier
operator|=
name|Qt
operator|::
name|NoModifier
argument_list|,
name|int
name|delay
operator|=
operator|-
literal|1
argument_list|)
block|{
name|keyEvent
argument_list|(
name|Click
argument_list|,
name|widget
argument_list|,
name|key
argument_list|,
name|modifier
argument_list|,
name|delay
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// QT_WIDGETS_LIB
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTESTKEYBOARD_H
end_comment
end_unit
