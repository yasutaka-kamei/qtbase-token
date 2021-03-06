begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTDISPATCHER_WIN_P_H
end_ifndef
begin_define
DECL|macro|QEVENTDISPATCHER_WIN_P_H
define|#
directive|define
name|QEVENTDISPATCHER_WIN_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qabstracteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qt_windows.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"qabstracteventdispatcher_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWinEventNotifier
name|class
name|QWinEventNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEventDispatcherWin32Private
name|class
name|QEventDispatcherWin32Private
decl_stmt|;
end_decl_stmt
begin_comment
comment|// forward declaration
end_comment
begin_function_decl
name|LRESULT
name|QT_WIN_CALLBACK
name|qt_internal_proc
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|UINT
name|message
parameter_list|,
name|WPARAM
name|wp
parameter_list|,
name|LPARAM
name|lp
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|quint64
name|qt_msectime
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QEventDispatcherWin32
range|:
name|public
name|QAbstractEventDispatcher
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QEventDispatcherWin32
argument_list|)
name|protected
operator|:
name|void
name|createInternalHwnd
argument_list|()
block|;
name|void
name|installMessageHook
argument_list|()
block|;
name|void
name|uninstallMessageHook
argument_list|()
block|;
name|public
operator|:
name|explicit
name|QEventDispatcherWin32
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEventDispatcherWin32
argument_list|()
block|;
name|bool
name|QT_ENSURE_STACK_ALIGNED_FOR_SSE
name|processEvents
argument_list|(
argument|QEventLoop::ProcessEventsFlags flags
argument_list|)
block|;
name|bool
name|hasPendingEvents
argument_list|()
block|;
name|void
name|registerSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|unregisterSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|registerTimer
argument_list|(
argument|int timerId
argument_list|,
argument|int interval
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|QObject *object
argument_list|)
block|;
name|bool
name|unregisterTimer
argument_list|(
argument|int timerId
argument_list|)
block|;
name|bool
name|unregisterTimers
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|QList
operator|<
name|TimerInfo
operator|>
name|registeredTimers
argument_list|(
argument|QObject *object
argument_list|)
specifier|const
block|;
name|bool
name|registerEventNotifier
argument_list|(
name|QWinEventNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|unregisterEventNotifier
argument_list|(
name|QWinEventNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|activateEventNotifiers
argument_list|()
block|;
name|int
name|remainingTime
argument_list|(
argument|int timerId
argument_list|)
block|;
name|void
name|wakeUp
argument_list|()
block|;
name|void
name|interrupt
argument_list|()
block|;
name|void
name|flush
argument_list|()
block|;
name|void
name|startingUp
argument_list|()
block|;
name|void
name|closingDown
argument_list|()
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|protected
operator|:
name|QEventDispatcherWin32
argument_list|(
name|QEventDispatcherWin32Private
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
name|void
name|sendPostedEvents
argument_list|()
block|;
name|void
name|doUnregisterSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
name|private
operator|:
name|friend
name|LRESULT
name|QT_WIN_CALLBACK
name|qt_internal_proc
argument_list|(
argument|HWND hwnd
argument_list|,
argument|UINT message
argument_list|,
argument|WPARAM wp
argument_list|,
argument|LPARAM lp
argument_list|)
block|;
name|friend
name|LRESULT
name|QT_WIN_CALLBACK
name|qt_GetMessageHook
argument_list|(
name|int
argument_list|,
name|WPARAM
argument_list|,
name|LPARAM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QSockNot
struct|struct
name|QSockNot
block|{
DECL|member|obj
name|QSocketNotifier
modifier|*
name|obj
decl_stmt|;
DECL|member|fd
name|int
name|fd
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|QSNDict
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|QSockNot
operator|*
operator|>
name|QSNDict
expr_stmt|;
end_typedef
begin_struct
DECL|struct|QSockFd
struct|struct
name|QSockFd
block|{
DECL|member|event
name|long
name|event
decl_stmt|;
DECL|member|selected
name|bool
name|selected
decl_stmt|;
DECL|function|QSockFd
name|explicit
specifier|inline
name|QSockFd
argument_list|(
argument|long ev =
literal|0
argument_list|)
operator|:
name|event
argument_list|(
name|ev
argument_list|)
operator|,
name|selected
argument_list|(
argument|false
argument_list|)
block|{ }
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|QSFDict
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|QSockFd
operator|>
name|QSFDict
expr_stmt|;
end_typedef
begin_struct
DECL|struct|WinTimerInfo
struct|struct
name|WinTimerInfo
block|{
comment|// internal timer info
DECL|member|dispatcher
name|QObject
modifier|*
name|dispatcher
decl_stmt|;
DECL|member|timerId
name|int
name|timerId
decl_stmt|;
DECL|member|interval
name|int
name|interval
decl_stmt|;
DECL|member|timerType
name|Qt
operator|::
name|TimerType
name|timerType
expr_stmt|;
DECL|member|timeout
name|quint64
name|timeout
decl_stmt|;
comment|// - when to actually fire
DECL|member|obj
name|QObject
modifier|*
name|obj
decl_stmt|;
comment|// - object to receive events
DECL|member|inTimerEvent
name|bool
name|inTimerEvent
decl_stmt|;
DECL|member|fastTimerId
name|int
name|fastTimerId
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QZeroTimerEvent
range|:
name|public
name|QTimerEvent
block|{
name|public
operator|:
name|explicit
specifier|inline
name|QZeroTimerEvent
argument_list|(
argument|int timerId
argument_list|)
operator|:
name|QTimerEvent
argument_list|(
argument|timerId
argument_list|)
block|{
name|t
operator|=
name|QEvent
operator|::
name|ZeroTimerEvent
block|; }
block|}
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|WinTimerVec
typedef|typedef
name|QList
operator|<
name|WinTimerInfo
operator|*
operator|>
name|WinTimerVec
expr_stmt|;
end_typedef
begin_comment
DECL|typedef|WinTimerVec
comment|// vector of TimerInfo structs
end_comment
begin_typedef
DECL|typedef|WinTimerDict
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|WinTimerInfo
operator|*
operator|>
name|WinTimerDict
expr_stmt|;
end_typedef
begin_comment
DECL|typedef|WinTimerDict
comment|// fast dict of timers
end_comment
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QEventDispatcherWin32Private
range|:
name|public
name|QAbstractEventDispatcherPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QEventDispatcherWin32
argument_list|)
name|public
operator|:
name|QEventDispatcherWin32Private
argument_list|()
block|;
operator|~
name|QEventDispatcherWin32Private
argument_list|()
block|;
name|DWORD
name|threadId
block|;
name|bool
name|interrupt
block|;
name|bool
name|closingDown
block|;
comment|// internal window handle used for socketnotifiers/timers/etc
name|HWND
name|internalHwnd
block|;
name|HHOOK
name|getMessageHook
block|;
comment|// for controlling when to send posted events
name|QAtomicInt
name|serialNumber
block|;
name|int
name|lastSerialNumber
block|,
name|sendPostedEventsWindowsTimerId
block|;
name|QAtomicInt
name|wakeUps
block|;
comment|// timers
name|WinTimerVec
name|timerVec
block|;
name|WinTimerDict
name|timerDict
block|;
name|void
name|registerTimer
argument_list|(
name|WinTimerInfo
operator|*
name|t
argument_list|)
block|;
name|void
name|unregisterTimer
argument_list|(
name|WinTimerInfo
operator|*
name|t
argument_list|)
block|;
name|void
name|sendTimerEvent
argument_list|(
argument|int timerId
argument_list|)
block|;
comment|// socket notifiers
name|QSNDict
name|sn_read
block|;
name|QSNDict
name|sn_write
block|;
name|QSNDict
name|sn_except
block|;
name|QSFDict
name|active_fd
block|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|bool
name|activateNotifiersPosted
block|;
name|void
name|postActivateSocketNotifiers
argument_list|()
block|;
endif|#
directive|endif
name|void
name|doWsaAsyncSelect
argument_list|(
argument|int socket
argument_list|,
argument|long event
argument_list|)
block|;
name|QList
operator|<
name|QWinEventNotifier
operator|*
operator|>
name|winEventNotifierList
block|;
name|void
name|activateEventNotifier
argument_list|(
name|QWinEventNotifier
operator|*
name|wen
argument_list|)
block|;
name|QList
operator|<
name|MSG
operator|>
name|queuedUserInputEvents
block|;
name|QList
operator|<
name|MSG
operator|>
name|queuedSocketEvents
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEVENTDISPATCHER_WIN_P_H
end_comment
end_unit
