begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeventdispatcher_winrt_p.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"qthread.h"
end_include
begin_include
include|#
directive|include
file|<private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qthread_p.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.h>
end_include
begin_include
include|#
directive|include
file|<windows.system.threading.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|System
operator|::
name|Threading
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEventDispatcherWinRT
name|QEventDispatcherWinRT
operator|::
name|QEventDispatcherWinRT
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractEventDispatcher
argument_list|(
operator|*
operator|new
name|QEventDispatcherWinRTPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QEventDispatcherWinRT
name|QEventDispatcherWinRT
operator|::
name|QEventDispatcherWinRT
parameter_list|(
name|QEventDispatcherWinRTPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractEventDispatcher
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QEventDispatcherWinRT
name|QEventDispatcherWinRT
operator|::
name|~
name|QEventDispatcherWinRT
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|processEvents
name|bool
name|QEventDispatcherWinRT
operator|::
name|processEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|flags
argument_list|)
expr_stmt|;
comment|// we are awake, broadcast it
emit|emit
name|awake
argument_list|()
emit|;
name|QCoreApplicationPrivate
operator|::
name|sendPostedEvents
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QThreadData
operator|::
name|current
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|hasPendingEvents
name|bool
name|QEventDispatcherWinRT
operator|::
name|hasPendingEvents
parameter_list|()
block|{
return|return
name|qGlobalPostedEventsCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|registerSocketNotifier
name|void
name|QEventDispatcherWinRT
operator|::
name|registerSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterSocketNotifier
name|void
name|QEventDispatcherWinRT
operator|::
name|unregisterSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|registerTimer
name|void
name|QEventDispatcherWinRT
operator|::
name|registerTimer
parameter_list|(
name|int
name|timerId
parameter_list|,
name|int
name|interval
parameter_list|,
name|Qt
operator|::
name|TimerType
name|timerType
parameter_list|,
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|timerType
argument_list|)
expr_stmt|;
if|if
condition|(
name|timerId
operator|<
literal|1
operator|||
name|interval
operator|<
literal|0
operator|||
operator|!
name|object
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::registerTimer: invalid arguments"
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|object
operator|->
name|thread
argument_list|()
operator|!=
name|thread
argument_list|()
operator|||
name|thread
argument_list|()
operator|!=
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QObject::startTimer: timers cannot be started from another thread"
argument_list|)
expr_stmt|;
return|return;
block|}
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|WinRTTimerInfo
modifier|*
name|t
init|=
operator|new
name|WinRTTimerInfo
argument_list|()
decl_stmt|;
name|t
operator|->
name|dispatcher
operator|=
name|this
expr_stmt|;
name|t
operator|->
name|timerId
operator|=
name|timerId
expr_stmt|;
name|t
operator|->
name|interval
operator|=
name|interval
expr_stmt|;
name|t
operator|->
name|timeout
operator|=
name|interval
expr_stmt|;
name|t
operator|->
name|timerType
operator|=
name|timerType
expr_stmt|;
name|t
operator|->
name|obj
operator|=
name|object
expr_stmt|;
name|t
operator|->
name|inTimerEvent
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|registerTimer
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|d
operator|->
name|timerVec
operator|.
name|append
argument_list|(
name|t
argument_list|)
expr_stmt|;
comment|// store in timer vector
name|d
operator|->
name|timerDict
operator|.
name|insert
argument_list|(
name|t
operator|->
name|timerId
argument_list|,
name|t
argument_list|)
expr_stmt|;
comment|// store timers in dict
block|}
end_function
begin_function
DECL|function|unregisterTimer
name|bool
name|QEventDispatcherWinRT
operator|::
name|unregisterTimer
parameter_list|(
name|int
name|timerId
parameter_list|)
block|{
if|if
condition|(
name|timerId
operator|<
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::unregisterTimer: invalid argument"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|thread
argument_list|()
operator|!=
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QObject::killTimer: timers cannot be stopped from another thread"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|timerVec
operator|.
name|isEmpty
argument_list|()
operator|||
name|timerId
operator|<=
literal|0
condition|)
return|return
literal|false
return|;
name|WinRTTimerInfo
modifier|*
name|t
init|=
name|d
operator|->
name|timerDict
operator|.
name|value
argument_list|(
name|timerId
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|t
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|t
operator|->
name|timer
condition|)
name|d
operator|->
name|threadPoolTimerDict
operator|.
name|remove
argument_list|(
name|t
operator|->
name|timer
argument_list|)
expr_stmt|;
name|d
operator|->
name|timerDict
operator|.
name|remove
argument_list|(
name|t
operator|->
name|timerId
argument_list|)
expr_stmt|;
name|d
operator|->
name|timerVec
operator|.
name|removeAll
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|d
operator|->
name|unregisterTimer
argument_list|(
name|t
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|unregisterTimers
name|bool
name|QEventDispatcherWinRT
operator|::
name|unregisterTimers
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
if|if
condition|(
operator|!
name|object
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::unregisterTimers: invalid argument"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QThread
modifier|*
name|currentThread
init|=
name|QThread
operator|::
name|currentThread
argument_list|()
decl_stmt|;
if|if
condition|(
name|object
operator|->
name|thread
argument_list|()
operator|!=
name|thread
argument_list|()
operator|||
name|thread
argument_list|()
operator|!=
name|currentThread
condition|)
block|{
name|qWarning
argument_list|(
literal|"QObject::killTimers: timers cannot be stopped from another thread"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|timerVec
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
specifier|register
name|WinRTTimerInfo
modifier|*
name|t
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
name|d
operator|->
name|timerVec
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|t
operator|=
name|d
operator|->
name|timerVec
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|&&
name|t
operator|->
name|obj
operator|==
name|object
condition|)
block|{
comment|// object found
if|if
condition|(
name|t
operator|->
name|timer
condition|)
name|d
operator|->
name|threadPoolTimerDict
operator|.
name|remove
argument_list|(
name|t
operator|->
name|timer
argument_list|)
expr_stmt|;
name|d
operator|->
name|timerDict
operator|.
name|remove
argument_list|(
name|t
operator|->
name|timerId
argument_list|)
expr_stmt|;
name|d
operator|->
name|timerVec
operator|.
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|d
operator|->
name|unregisterTimer
argument_list|(
name|t
argument_list|)
expr_stmt|;
operator|--
name|i
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|registeredTimers
name|QList
argument_list|<
name|QAbstractEventDispatcher
operator|::
name|TimerInfo
argument_list|>
name|QEventDispatcherWinRT
operator|::
name|registeredTimers
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|object
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT:registeredTimers: invalid argument"
argument_list|)
expr_stmt|;
return|return
name|QList
argument_list|<
name|TimerInfo
argument_list|>
argument_list|()
return|;
block|}
name|Q_D
argument_list|(
specifier|const
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|TimerInfo
argument_list|>
name|list
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
name|d
operator|->
name|timerVec
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|WinRTTimerInfo
modifier|*
name|t
init|=
name|d
operator|->
name|timerVec
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|t
operator|&&
name|t
operator|->
name|obj
operator|==
name|object
condition|)
name|list
operator|<<
name|TimerInfo
argument_list|(
name|t
operator|->
name|timerId
argument_list|,
name|t
operator|->
name|interval
argument_list|,
name|t
operator|->
name|timerType
argument_list|)
expr_stmt|;
block|}
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|registerEventNotifier
name|bool
name|QEventDispatcherWinRT
operator|::
name|registerEventNotifier
parameter_list|(
name|QWinEventNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|unregisterEventNotifier
name|void
name|QEventDispatcherWinRT
operator|::
name|unregisterEventNotifier
parameter_list|(
name|QWinEventNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|remainingTime
name|int
name|QEventDispatcherWinRT
operator|::
name|remainingTime
parameter_list|(
name|int
name|timerId
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
name|timerId
operator|<
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::remainingTime: invalid argument"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
endif|#
directive|endif
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|timerVec
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
name|quint64
name|currentTime
init|=
name|qt_msectime
argument_list|()
decl_stmt|;
specifier|register
name|WinRTTimerInfo
modifier|*
name|t
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
name|d
operator|->
name|timerVec
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|t
operator|=
name|d
operator|->
name|timerVec
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|&&
name|t
operator|->
name|timerId
operator|==
name|timerId
condition|)
block|{
comment|// timer found
if|if
condition|(
name|currentTime
operator|<
name|t
operator|->
name|timeout
condition|)
block|{
comment|// time to wait
return|return
name|t
operator|->
name|timeout
operator|-
name|currentTime
return|;
block|}
else|else
block|{
return|return
literal|0
return|;
block|}
block|}
block|}
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::remainingTime: timer id %d not found"
argument_list|,
name|timerId
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|wakeUp
name|void
name|QEventDispatcherWinRT
operator|::
name|wakeUp
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|wakeUps
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
condition|)
block|{
comment|// ###TODO: is there any thing to wake up?
block|}
block|}
end_function
begin_function
DECL|function|interrupt
name|void
name|QEventDispatcherWinRT
operator|::
name|interrupt
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|d
operator|->
name|interrupt
operator|=
literal|true
expr_stmt|;
name|wakeUp
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QEventDispatcherWinRT
operator|::
name|flush
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|startingUp
name|void
name|QEventDispatcherWinRT
operator|::
name|startingUp
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|closingDown
name|void
name|QEventDispatcherWinRT
operator|::
name|closingDown
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
comment|// clean up any timers
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|timerVec
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|unregisterTimer
argument_list|(
name|d
operator|->
name|timerVec
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|timerVec
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|timerDict
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|threadPoolTimerDict
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|QEventDispatcherWinRT
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|ZeroTimerEvent
condition|)
block|{
name|QZeroTimerEvent
modifier|*
name|zte
init|=
cast|static_cast
argument_list|<
name|QZeroTimerEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|WinRTTimerInfo
modifier|*
name|t
init|=
name|d
operator|->
name|timerDict
operator|.
name|value
argument_list|(
name|zte
operator|->
name|timerId
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|t
condition|)
block|{
name|t
operator|->
name|inTimerEvent
operator|=
literal|true
expr_stmt|;
name|QTimerEvent
name|te
argument_list|(
name|zte
operator|->
name|timerId
argument_list|()
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|t
operator|->
name|obj
argument_list|,
operator|&
name|te
argument_list|)
expr_stmt|;
name|t
operator|=
name|d
operator|->
name|timerDict
operator|.
name|value
argument_list|(
name|zte
operator|->
name|timerId
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
condition|)
block|{
if|if
condition|(
name|t
operator|->
name|interval
operator|==
literal|0
operator|&&
name|t
operator|->
name|inTimerEvent
condition|)
block|{
comment|// post the next zero timer event as long as the timer was not restarted
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QZeroTimerEvent
argument_list|(
name|zte
operator|->
name|timerId
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|t
operator|->
name|inTimerEvent
operator|=
literal|false
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Timer
condition|)
block|{
name|QTimerEvent
modifier|*
name|te
init|=
cast|static_cast
argument_list|<
name|QTimerEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|d
operator|->
name|sendTimerEvent
argument_list|(
name|te
operator|->
name|timerId
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|QAbstractEventDispatcher
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QEventDispatcherWinRTPrivate
name|QEventDispatcherWinRTPrivate
operator|::
name|QEventDispatcherWinRTPrivate
parameter_list|()
member_init_list|:
name|interrupt
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|timerFactory
argument_list|(
literal|0
argument_list|)
block|{
name|CoInitializeEx
argument_list|(
name|NULL
argument_list|,
name|COINIT_APARTMENTTHREADED
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
init|=
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_System_Threading_ThreadPoolTimer
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|timerFactory
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRTPrivate::QEventDispatcherWinRTPrivate: Could not obtain timer factory: %lx"
argument_list|,
name|hr
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEventDispatcherWinRTPrivate
name|QEventDispatcherWinRTPrivate
operator|::
name|~
name|QEventDispatcherWinRTPrivate
parameter_list|()
block|{
if|if
condition|(
name|timerFactory
condition|)
name|timerFactory
operator|->
name|Release
argument_list|()
expr_stmt|;
name|CoUninitialize
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|registerTimer
name|void
name|QEventDispatcherWinRTPrivate
operator|::
name|registerTimer
parameter_list|(
name|WinRTTimerInfo
modifier|*
name|t
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|int
name|ok
init|=
literal|0
decl_stmt|;
name|uint
name|interval
init|=
name|t
operator|->
name|interval
decl_stmt|;
if|if
condition|(
name|interval
operator|==
literal|0u
condition|)
block|{
comment|// optimization for single-shot-zero-timer
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|q
argument_list|,
operator|new
name|QZeroTimerEvent
argument_list|(
name|t
operator|->
name|timerId
argument_list|)
argument_list|)
expr_stmt|;
name|ok
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|TimeSpan
name|period
decl_stmt|;
name|period
operator|.
name|Duration
operator|=
name|interval
operator|*
literal|10000
expr_stmt|;
comment|// TimeSpan is based on 100-nanosecond units
name|ok
operator|=
name|SUCCEEDED
argument_list|(
name|timerFactory
operator|->
name|CreatePeriodicTimer
argument_list|(
name|Callback
argument_list|<
name|ITimerElapsedHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QEventDispatcherWinRTPrivate
operator|::
name|timerExpiredCallback
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|period
argument_list|,
operator|&
name|t
operator|->
name|timer
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ok
condition|)
name|threadPoolTimerDict
operator|.
name|insert
argument_list|(
name|t
operator|->
name|timer
argument_list|,
name|t
argument_list|)
expr_stmt|;
block|}
name|t
operator|->
name|timeout
operator|=
name|qt_msectime
argument_list|()
operator|+
name|interval
expr_stmt|;
if|if
condition|(
name|ok
operator|==
literal|0
condition|)
name|qErrnoWarning
argument_list|(
literal|"QEventDispatcherWinRT::registerTimer: Failed to create a timer"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterTimer
name|void
name|QEventDispatcherWinRTPrivate
operator|::
name|unregisterTimer
parameter_list|(
name|WinRTTimerInfo
modifier|*
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|->
name|timer
condition|)
block|{
name|t
operator|->
name|timer
operator|->
name|Cancel
argument_list|()
expr_stmt|;
name|t
operator|->
name|timer
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
operator|delete
name|t
expr_stmt|;
name|t
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sendTimerEvent
name|void
name|QEventDispatcherWinRTPrivate
operator|::
name|sendTimerEvent
parameter_list|(
name|int
name|timerId
parameter_list|)
block|{
name|WinRTTimerInfo
modifier|*
name|t
init|=
name|timerDict
operator|.
name|value
argument_list|(
name|timerId
argument_list|)
decl_stmt|;
if|if
condition|(
name|t
operator|&&
operator|!
name|t
operator|->
name|inTimerEvent
condition|)
block|{
comment|// send event, but don't allow it to recurse
name|t
operator|->
name|inTimerEvent
operator|=
literal|true
expr_stmt|;
name|QTimerEvent
name|e
argument_list|(
name|t
operator|->
name|timerId
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|t
operator|->
name|obj
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
comment|// timer could have been removed
name|t
operator|=
name|timerDict
operator|.
name|value
argument_list|(
name|timerId
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
condition|)
block|{
name|t
operator|->
name|inTimerEvent
operator|=
literal|false
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|timerExpiredCallback
name|HRESULT
name|QEventDispatcherWinRTPrivate
operator|::
name|timerExpiredCallback
parameter_list|(
name|IThreadPoolTimer
modifier|*
name|source
parameter_list|)
block|{
specifier|register
name|WinRTTimerInfo
modifier|*
name|t
init|=
name|threadPoolTimerDict
operator|.
name|value
argument_list|(
name|source
argument_list|)
decl_stmt|;
if|if
condition|(
name|t
condition|)
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|t
operator|->
name|dispatcher
argument_list|,
operator|new
name|QTimerEvent
argument_list|(
name|t
operator|->
name|timerId
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::timerExpiredCallback: Could not find timer %d in timer list"
argument_list|,
name|source
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
