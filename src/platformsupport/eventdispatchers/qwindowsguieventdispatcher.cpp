begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Samuel Gaist<samuel.gaist@edeltech.ch> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsguieventdispatcher_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QWindowsGuiEventDispatcher     \brief Event dispatcher for Windows      Maintains a global stack storing the current event dispatcher and     its processing flags for access from the Windows procedure     qWindowsWndProc. Handling the Lighthouse gui events should be done     from within the qWindowsWndProc to ensure correct processing of messages.      \internal     \ingroup qt-lighthouse-win */
end_comment
begin_constructor
DECL|function|QWindowsGuiEventDispatcher
name|QWindowsGuiEventDispatcher
operator|::
name|QWindowsGuiEventDispatcher
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QEventDispatcherWin32
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_flags
argument_list|(
literal|0
argument_list|)
block|{
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QWindowsGuiEventDispatcher"
argument_list|)
argument_list|)
expr_stmt|;
name|createInternalHwnd
argument_list|()
expr_stmt|;
comment|// QTBUG-40881: Do not delay registering timers, etc. for QtMfc.
block|}
end_constructor
begin_function
DECL|function|processEvents
name|bool
name|QWindowsGuiEventDispatcher
operator|::
name|processEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
specifier|const
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|oldFlags
init|=
name|m_flags
decl_stmt|;
name|m_flags
operator|=
name|flags
expr_stmt|;
specifier|const
name|bool
name|rc
init|=
name|QEventDispatcherWin32
operator|::
name|processEvents
argument_list|(
name|flags
argument_list|)
decl_stmt|;
name|m_flags
operator|=
name|oldFlags
expr_stmt|;
return|return
name|rc
return|;
block|}
end_function
begin_function
DECL|function|sendPostedEvents
name|void
name|QWindowsGuiEventDispatcher
operator|::
name|sendPostedEvents
parameter_list|()
block|{
name|QEventDispatcherWin32
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|sendWindowSystemEvents
argument_list|(
name|m_flags
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Helpers for printing debug output for WM_* messages.
end_comment
begin_struct
DECL|struct|MessageDebugEntry
struct|struct
name|MessageDebugEntry
block|{
DECL|member|message
name|UINT
name|message
decl_stmt|;
DECL|member|description
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
DECL|member|interesting
name|bool
name|interesting
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
specifier|static
specifier|const
name|MessageDebugEntry
DECL|variable|messageDebugEntries
name|messageDebugEntries
index|[]
init|=
block|{
block|{
name|WM_CREATE
block|,
literal|"WM_CREATE"
block|,
literal|true
block|}
block|,
block|{
name|WM_PAINT
block|,
literal|"WM_PAINT"
block|,
literal|true
block|}
block|,
block|{
name|WM_CLOSE
block|,
literal|"WM_CLOSE"
block|,
literal|true
block|}
block|,
block|{
name|WM_DESTROY
block|,
literal|"WM_DESTROY"
block|,
literal|true
block|}
block|,
block|{
name|WM_MOVE
block|,
literal|"WM_MOVE"
block|,
literal|true
block|}
block|,
block|{
name|WM_SIZE
block|,
literal|"WM_SIZE"
block|,
literal|true
block|}
block|,
block|{
name|WM_GETICON
block|,
literal|"WM_GETICON"
block|,
literal|false
block|}
block|,
block|{
name|WM_KEYDOWN
block|,
literal|"WM_KEYDOWN"
block|,
literal|true
block|}
block|,
block|{
name|WM_SYSKEYDOWN
block|,
literal|"WM_SYSKEYDOWN"
block|,
literal|true
block|}
block|,
block|{
name|WM_SYSCOMMAND
block|,
literal|"WM_SYSCOMMAND"
block|,
literal|true
block|}
block|,
block|{
name|WM_KEYUP
block|,
literal|"WM_KEYUP"
block|,
literal|true
block|}
block|,
block|{
name|WM_SYSKEYUP
block|,
literal|"WM_SYSKEYUP"
block|,
literal|true
block|}
block|,
if|#
directive|if
name|defined
argument_list|(
name|WM_APPCOMMAND
argument_list|)
block|{
name|WM_APPCOMMAND
block|,
literal|"WM_APPCOMMAND"
block|,
literal|true
block|}
block|,
endif|#
directive|endif
block|{
name|WM_IME_CHAR
block|,
literal|"WM_IMECHAR"
block|,
literal|true
block|}
block|,
block|{
name|WM_IME_KEYDOWN
block|,
literal|"WM_IMECHAR"
block|,
literal|true
block|}
block|,
block|{
name|WM_CANCELMODE
block|,
literal|"WM_CANCELMODE"
block|,
literal|true
block|}
block|,
block|{
name|WM_CHAR
block|,
literal|"WM_CHAR"
block|,
literal|true
block|}
block|,
block|{
name|WM_DEADCHAR
block|,
literal|"WM_DEADCHAR"
block|,
literal|true
block|}
block|,
block|{
name|WM_ACTIVATE
block|,
literal|"WM_ACTIVATE"
block|,
literal|true
block|}
block|,
block|{
name|WM_SETFOCUS
block|,
literal|"WM_SETFOCUS"
block|,
literal|true
block|}
block|,
block|{
name|WM_KILLFOCUS
block|,
literal|"WM_KILLFOCUS"
block|,
literal|true
block|}
block|,
block|{
name|WM_ENABLE
block|,
literal|"WM_ENABLE"
block|,
literal|true
block|}
block|,
block|{
name|WM_SHOWWINDOW
block|,
literal|"WM_SHOWWINDOW"
block|,
literal|true
block|}
block|,
block|{
name|WM_WINDOWPOSCHANGED
block|,
literal|"WM_WINDOWPOSCHANGED"
block|,
literal|true
block|}
block|,
block|{
name|WM_SETCURSOR
block|,
literal|"WM_SETCURSOR"
block|,
literal|false
block|}
block|,
block|{
name|WM_GETFONT
block|,
literal|"WM_GETFONT"
block|,
literal|true
block|}
block|,
block|{
name|WM_LBUTTONDOWN
block|,
literal|"WM_LBUTTONDOWN"
block|,
literal|true
block|}
block|,
block|{
name|WM_LBUTTONUP
block|,
literal|"WM_LBUTTONUP"
block|,
literal|true
block|}
block|,
block|{
name|WM_LBUTTONDBLCLK
block|,
literal|"WM_LBUTTONDBLCLK"
block|,
literal|true
block|}
block|,
block|{
name|WM_RBUTTONDOWN
block|,
literal|"WM_RBUTTONDOWN"
block|,
literal|true
block|}
block|,
block|{
name|WM_RBUTTONUP
block|,
literal|"WM_RBUTTONUP"
block|,
literal|true
block|}
block|,
block|{
name|WM_RBUTTONDBLCLK
block|,
literal|"WM_RBUTTONDBLCLK"
block|,
literal|true
block|}
block|,
block|{
name|WM_MBUTTONDOWN
block|,
literal|"WM_MBUTTONDOWN"
block|,
literal|true
block|}
block|,
block|{
name|WM_MBUTTONUP
block|,
literal|"WM_MBUTTONUP"
block|,
literal|true
block|}
block|,
block|{
name|WM_MBUTTONDBLCLK
block|,
literal|"WM_MBUTTONDBLCLK"
block|,
literal|true
block|}
block|,
block|{
name|WM_MOUSEWHEEL
block|,
literal|"WM_MOUSEWHEEL"
block|,
literal|true
block|}
block|,
block|{
name|WM_XBUTTONDOWN
block|,
literal|"WM_XBUTTONDOWN"
block|,
literal|true
block|}
block|,
block|{
name|WM_XBUTTONUP
block|,
literal|"WM_XBUTTONUP"
block|,
literal|true
block|}
block|,
block|{
name|WM_XBUTTONDBLCLK
block|,
literal|"WM_XBUTTONDBLCLK"
block|,
literal|true
block|}
block|,
block|{
name|WM_MOUSEHWHEEL
block|,
literal|"WM_MOUSEHWHEEL"
block|,
literal|true
block|}
block|,
block|{
name|WM_IME_SETCONTEXT
block|,
literal|"WM_IME_SETCONTEXT"
block|,
literal|true
block|}
block|,
block|{
name|WM_INPUTLANGCHANGE
block|,
literal|"WM_INPUTLANGCHANGE"
block|,
literal|true
block|}
block|,
block|{
name|WM_IME_NOTIFY
block|,
literal|"WM_IME_NOTIFY"
block|,
literal|true
block|}
block|,
if|#
directive|if
name|defined
argument_list|(
name|WM_DWMNCRENDERINGCHANGED
argument_list|)
block|{
name|WM_DWMNCRENDERINGCHANGED
block|,
literal|"WM_DWMNCRENDERINGCHANGED"
block|,
literal|true
block|}
block|,
endif|#
directive|endif
block|{
name|WM_IME_SETCONTEXT
block|,
literal|"WM_IME_SETCONTEXT"
block|,
literal|true
block|}
block|,
block|{
name|WM_IME_NOTIFY
block|,
literal|"WM_IME_NOTIFY"
block|,
literal|true
block|}
block|,
block|{
name|WM_RENDERFORMAT
block|,
literal|"WM_RENDERFORMAT"
block|,
literal|true
block|}
block|,
block|{
name|WM_RENDERALLFORMATS
block|,
literal|"WM_RENDERALLFORMATS"
block|,
literal|true
block|}
block|,
block|{
name|WM_DESTROYCLIPBOARD
block|,
literal|"WM_DESTROYCLIPBOARD"
block|,
literal|true
block|}
block|,
block|{
name|WM_CAPTURECHANGED
block|,
literal|"WM_CAPTURECHANGED"
block|,
literal|true
block|}
block|,
block|{
name|WM_IME_STARTCOMPOSITION
block|,
literal|"WM_IME_STARTCOMPOSITION"
block|,
literal|true
block|}
block|,
block|{
name|WM_IME_COMPOSITION
block|,
literal|"WM_IME_COMPOSITION"
block|,
literal|true
block|}
block|,
block|{
name|WM_IME_ENDCOMPOSITION
block|,
literal|"WM_IME_ENDCOMPOSITION"
block|,
literal|true
block|}
block|,
block|{
name|WM_IME_NOTIFY
block|,
literal|"WM_IME_NOTIFY"
block|,
literal|true
block|}
block|,
block|{
name|WM_IME_REQUEST
block|,
literal|"WM_IME_REQUEST"
block|,
literal|true
block|}
block|,
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SESSIONMANAGER
argument_list|)
block|{
name|WM_QUERYENDSESSION
block|,
literal|"WM_QUERYENDSESSION"
block|,
literal|true
block|}
block|,
block|{
name|WM_ENDSESSION
block|,
literal|"WM_ENDSESSION"
block|,
literal|true
block|}
block|,
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_WINCE
block|{
name|WM_MOUSEACTIVATE
block|,
literal|"WM_MOUSEACTIVATE"
block|,
literal|true
block|}
block|,
block|{
name|WM_CHILDACTIVATE
block|,
literal|"WM_CHILDACTIVATE"
block|,
literal|true
block|}
block|,
block|{
name|WM_PARENTNOTIFY
block|,
literal|"WM_PARENTNOTIFY"
block|,
literal|true
block|}
block|,
block|{
name|WM_ENTERIDLE
block|,
literal|"WM_ENTERIDLE"
block|,
literal|false
block|}
block|,
block|{
name|WM_GETMINMAXINFO
block|,
literal|"WM_GETMINMAXINFO"
block|,
literal|true
block|}
block|,
block|{
name|WM_WINDOWPOSCHANGING
block|,
literal|"WM_WINDOWPOSCHANGING"
block|,
literal|true
block|}
block|,
block|{
name|WM_NCCREATE
block|,
literal|"WM_NCCREATE"
block|,
literal|true
block|}
block|,
block|{
name|WM_NCCALCSIZE
block|,
literal|"WM_NCCALCSIZE"
block|,
literal|true
block|}
block|,
block|{
name|WM_NCACTIVATE
block|,
literal|"WM_NCACTIVATE"
block|,
literal|true
block|}
block|,
block|{
name|WM_NCMOUSEMOVE
block|,
literal|"WM_NCMOUSEMOVE"
block|,
literal|true
block|}
block|,
block|{
name|WM_NCMOUSELEAVE
block|,
literal|"WM_NCMOUSELEAVE"
block|,
literal|true
block|}
block|,
block|{
name|WM_NCLBUTTONDOWN
block|,
literal|"WM_NCLBUTTONDOWN"
block|,
literal|true
block|}
block|,
block|{
name|WM_NCLBUTTONUP
block|,
literal|"WM_NCLBUTTONUP"
block|,
literal|true
block|}
block|,
block|{
name|WM_ACTIVATEAPP
block|,
literal|"WM_ACTIVATEAPP"
block|,
literal|true
block|}
block|,
block|{
name|WM_NCPAINT
block|,
literal|"WM_NCPAINT"
block|,
literal|true
block|}
block|,
block|{
name|WM_ERASEBKGND
block|,
literal|"WM_ERASEBKGND"
block|,
literal|true
block|}
block|,
block|{
name|WM_MOUSEMOVE
block|,
literal|"WM_MOUSEMOVE"
block|,
literal|true
block|}
block|,
block|{
name|WM_MOUSELEAVE
block|,
literal|"WM_MOUSELEAVE"
block|,
literal|true
block|}
block|,
block|{
name|WM_NCHITTEST
block|,
literal|"WM_NCHITTEST"
block|,
literal|false
block|}
block|,
ifdef|#
directive|ifdef
name|WM_TOUCH
block|{
name|WM_TOUCH
block|,
literal|"WM_TOUCH"
block|,
literal|true
block|}
block|,
endif|#
directive|endif
block|{
name|WM_CHANGECBCHAIN
block|,
literal|"WM_CHANGECBCHAIN"
block|,
literal|true
block|}
block|,
block|{
name|WM_DISPLAYCHANGE
block|,
literal|"WM_DISPLAYCHANGE"
block|,
literal|true
block|}
block|,
block|{
name|WM_DRAWCLIPBOARD
block|,
literal|"WM_DRAWCLIPBOARD"
block|,
literal|true
block|}
block|,
endif|#
directive|endif
comment|// !Q_OS_WINCE
block|{
name|WM_THEMECHANGED
block|,
literal|"WM_THEMECHANGED"
block|,
literal|true
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|messageDebugEntry
specifier|static
specifier|inline
specifier|const
name|MessageDebugEntry
modifier|*
name|messageDebugEntry
parameter_list|(
name|UINT
name|msg
parameter_list|)
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|messageDebugEntries
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|MessageDebugEntry
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|messageDebugEntries
index|[
name|i
index|]
operator|.
name|message
operator|==
name|msg
condition|)
return|return
name|messageDebugEntries
operator|+
name|i
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|windowsMessageName
specifier|const
name|char
modifier|*
name|QWindowsGuiEventDispatcher
operator|::
name|windowsMessageName
parameter_list|(
name|UINT
name|msg
parameter_list|)
block|{
if|if
condition|(
specifier|const
name|MessageDebugEntry
modifier|*
name|e
init|=
name|messageDebugEntry
argument_list|(
name|msg
argument_list|)
condition|)
return|return
name|e
operator|->
name|description
return|;
return|return
literal|"Unknown"
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit