begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVDEVKEYBOARDHANDLER_P_H
end_ifndef
begin_define
DECL|macro|QEVDEVKEYBOARDHANDLER_P_H
define|#
directive|define
name|QEVDEVKEYBOARDHANDLER_P_H
end_define
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QDataStream>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|namespace
name|QEvdevKeyboardMap
block|{
specifier|const
name|quint32
name|FileMagic
init|=
literal|0x514d4150
decl_stmt|;
comment|// 'QMAP'
struct|struct
name|Mapping
block|{
name|quint16
name|keycode
decl_stmt|;
name|quint16
name|unicode
decl_stmt|;
name|quint32
name|qtcode
decl_stmt|;
name|quint8
name|modifiers
decl_stmt|;
name|quint8
name|flags
decl_stmt|;
name|quint16
name|special
decl_stmt|;
block|}
struct|;
enum|enum
name|Flags
block|{
name|IsDead
init|=
literal|0x01
block|,
name|IsLetter
init|=
literal|0x02
block|,
name|IsModifier
init|=
literal|0x04
block|,
name|IsSystem
init|=
literal|0x08
block|}
enum|;
enum|enum
name|System
block|{
name|SystemConsoleFirst
init|=
literal|0x0100
block|,
name|SystemConsoleMask
init|=
literal|0x007f
block|,
name|SystemConsoleLast
init|=
literal|0x017f
block|,
name|SystemConsolePrevious
init|=
literal|0x0180
block|,
name|SystemConsoleNext
init|=
literal|0x0181
block|,
name|SystemReboot
init|=
literal|0x0200
block|,
name|SystemZap
init|=
literal|0x0300
block|}
enum|;
struct|struct
name|Composing
block|{
name|quint16
name|first
decl_stmt|;
name|quint16
name|second
decl_stmt|;
name|quint16
name|result
decl_stmt|;
block|}
struct|;
enum|enum
name|Modifiers
block|{
name|ModPlain
init|=
literal|0x00
block|,
name|ModShift
init|=
literal|0x01
block|,
name|ModAltGr
init|=
literal|0x02
block|,
name|ModControl
init|=
literal|0x04
block|,
name|ModAlt
init|=
literal|0x08
block|,
name|ModShiftL
init|=
literal|0x10
block|,
name|ModShiftR
init|=
literal|0x20
block|,
name|ModCtrlL
init|=
literal|0x40
block|,
name|ModCtrlR
init|=
literal|0x80
comment|// ModCapsShift = 0x100, // not supported!
block|}
enum|;
block|}
end_decl_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|ds
operator|,
name|QEvdevKeyboardMap
operator|::
name|Mapping
operator|&
name|m
operator|)
block|{
return|return
name|ds
operator|>>
name|m
operator|.
name|keycode
operator|>>
name|m
operator|.
name|unicode
operator|>>
name|m
operator|.
name|qtcode
operator|>>
name|m
operator|.
name|modifiers
operator|>>
name|m
operator|.
name|flags
operator|>>
name|m
operator|.
name|special
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|ds
operator|,
specifier|const
name|QEvdevKeyboardMap
operator|::
name|Mapping
operator|&
name|m
operator|)
block|{
return|return
name|ds
operator|<<
name|m
operator|.
name|keycode
operator|<<
name|m
operator|.
name|unicode
operator|<<
name|m
operator|.
name|qtcode
operator|<<
name|m
operator|.
name|modifiers
operator|<<
name|m
operator|.
name|flags
operator|<<
name|m
operator|.
name|special
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|ds
operator|,
name|QEvdevKeyboardMap
operator|::
name|Composing
operator|&
name|c
operator|)
block|{
return|return
name|ds
operator|>>
name|c
operator|.
name|first
operator|>>
name|c
operator|.
name|second
operator|>>
name|c
operator|.
name|result
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|ds
operator|,
specifier|const
name|QEvdevKeyboardMap
operator|::
name|Composing
operator|&
name|c
operator|)
block|{
return|return
name|ds
operator|<<
name|c
operator|.
name|first
operator|<<
name|c
operator|.
name|second
operator|<<
name|c
operator|.
name|result
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|class
name|QEvdevKeyboardHandler
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QEvdevKeyboardHandler
argument_list|(
argument|const QString&device
argument_list|,
argument|int fd
argument_list|,
argument|bool disableZap
argument_list|,
argument|bool enableCompose
argument_list|,
argument|const QString&keymapFile
argument_list|)
block|;
operator|~
name|QEvdevKeyboardHandler
argument_list|()
block|;      enum
name|KeycodeAction
block|{
name|None
operator|=
literal|0
block|,
name|CapsLockOff
operator|=
literal|0x01000000
block|,
name|CapsLockOn
operator|=
literal|0x01000001
block|,
name|NumLockOff
operator|=
literal|0x02000000
block|,
name|NumLockOn
operator|=
literal|0x02000001
block|,
name|ScrollLockOff
operator|=
literal|0x03000000
block|,
name|ScrollLockOn
operator|=
literal|0x03000001
block|,
name|Reboot
operator|=
literal|0x04000000
block|,
name|PreviousConsole
operator|=
literal|0x05000000
block|,
name|NextConsole
operator|=
literal|0x05000001
block|,
name|SwitchConsoleFirst
operator|=
literal|0x06000000
block|,
name|SwitchConsoleLast
operator|=
literal|0x0600007f
block|,
name|SwitchConsoleMask
operator|=
literal|0x0000007f
block|}
block|;
specifier|static
name|QEvdevKeyboardHandler
operator|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|device
argument_list|,
specifier|const
name|QString
operator|&
name|specification
argument_list|)
block|;
specifier|static
name|Qt
operator|::
name|KeyboardModifiers
name|toQtModifiers
argument_list|(
argument|quint8 mod
argument_list|)
block|{
name|Qt
operator|::
name|KeyboardModifiers
name|qtmod
operator|=
name|Qt
operator|::
name|NoModifier
block|;
if|if
condition|(
name|mod
operator|&
operator|(
name|QEvdevKeyboardMap
operator|::
name|ModShift
operator||
name|QEvdevKeyboardMap
operator|::
name|ModShiftL
operator||
name|QEvdevKeyboardMap
operator|::
name|ModShiftR
operator|)
condition|)
name|qtmod
operator||=
name|Qt
operator|::
name|ShiftModifier
expr_stmt|;
if|if
condition|(
name|mod
operator|&
operator|(
name|QEvdevKeyboardMap
operator|::
name|ModControl
operator||
name|QEvdevKeyboardMap
operator|::
name|ModCtrlL
operator||
name|QEvdevKeyboardMap
operator|::
name|ModCtrlR
operator|)
condition|)
name|qtmod
operator||=
name|Qt
operator|::
name|ControlModifier
expr_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|mod
operator|&
name|QEvdevKeyboardMap
operator|::
name|ModAlt
condition|)
name|qtmod
operator||=
name|Qt
operator|::
name|AltModifier
expr_stmt|;
end_if
begin_return
return|return
name|qtmod
return|;
end_return
begin_label
unit|}  private
name|slots
label|:
end_label
begin_function_decl
name|void
name|readKeycode
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|KeycodeAction
name|processKeycode
parameter_list|(
name|quint16
name|keycode
parameter_list|,
name|bool
name|pressed
parameter_list|,
name|bool
name|autorepeat
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|unloadKeymap
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|loadKeymap
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|processKeyEvent
argument_list|(
name|int
name|nativecode
argument_list|,
name|int
name|unicode
argument_list|,
name|int
name|qtcode
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|,
name|bool
name|isPress
argument_list|,
name|bool
name|autoRepeat
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|switchLed
parameter_list|(
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QString
name|m_device
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_fd
decl_stmt|;
end_decl_stmt
begin_comment
comment|// keymap handling
end_comment
begin_decl_stmt
name|quint8
name|m_modifiers
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|quint8
name|m_locks
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_composing
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|quint16
name|m_dead_unicode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_no_zap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_do_compose
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|const
name|QEvdevKeyboardMap
operator|::
name|Mapping
operator|*
name|m_keymap
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|m_keymap_size
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|const
name|QEvdevKeyboardMap
operator|::
name|Composing
operator|*
name|m_keycompose
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|m_keycompose_size
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|static
specifier|const
name|QEvdevKeyboardMap
operator|::
name|Mapping
name|s_keymap_default
index|[]
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|static
specifier|const
name|QEvdevKeyboardMap
operator|::
name|Composing
name|s_keycompose_default
index|[]
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEVDEVKEYBOARDHANDLER_P_H
end_comment
end_unit
