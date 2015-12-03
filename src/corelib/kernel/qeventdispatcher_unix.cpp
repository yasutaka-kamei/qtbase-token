begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"qpair.h"
end_include
begin_include
include|#
directive|include
file|"qsocketnotifier.h"
end_include
begin_include
include|#
directive|include
file|"qthread.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"qeventdispatcher_unix_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qthread_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_unix_p.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EVENTFD
end_ifndef
begin_include
include|#
directive|include
file|<sys/eventfd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// VxWorks doesn't correctly set the _POSIX_... options
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_MONOTONIC_CLOCK
argument_list|)
operator|&&
operator|(
name|_POSIX_MONOTONIC_CLOCK
operator|<=
literal|0
operator|)
end_if
begin_undef
DECL|macro|_POSIX_MONOTONIC_CLOCK
undef|#
directive|undef
name|_POSIX_MONOTONIC_CLOCK
end_undef
begin_define
DECL|macro|_POSIX_MONOTONIC_CLOCK
define|#
directive|define
name|_POSIX_MONOTONIC_CLOCK
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<pipeDrv.h>
end_include
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|_POSIX_MONOTONIC_CLOCK
operator|-
literal|0
operator|<=
literal|0
operator|)
operator|||
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/times.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|socketType
specifier|static
specifier|const
name|char
modifier|*
name|socketType
parameter_list|(
name|QSocketNotifier
operator|::
name|Type
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QSocketNotifier
operator|::
name|Read
case|:
return|return
literal|"Read"
return|;
case|case
name|QSocketNotifier
operator|::
name|Write
case|:
return|return
literal|"Write"
return|;
case|case
name|QSocketNotifier
operator|::
name|Exception
case|:
return|return
literal|"Exception"
return|;
block|}
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|make_pollfd
specifier|static
name|pollfd
name|make_pollfd
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|events
parameter_list|)
block|{
name|pollfd
name|pfd
init|=
block|{
name|fd
block|,
name|events
block|,
literal|0
block|}
decl_stmt|;
return|return
name|pfd
return|;
block|}
end_function
begin_constructor
DECL|function|QThreadPipe
name|QThreadPipe
operator|::
name|QThreadPipe
parameter_list|()
block|{
name|fds
index|[
literal|0
index|]
operator|=
operator|-
literal|1
expr_stmt|;
name|fds
index|[
literal|1
index|]
operator|=
operator|-
literal|1
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
name|name
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~QThreadPipe
name|QThreadPipe
operator|::
name|~
name|QThreadPipe
parameter_list|()
block|{
if|if
condition|(
name|fds
index|[
literal|0
index|]
operator|>=
literal|0
condition|)
name|close
argument_list|(
name|fds
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|fds
index|[
literal|1
index|]
operator|>=
literal|0
condition|)
name|close
argument_list|(
name|fds
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
name|pipeDevDelete
argument_list|(
name|name
argument_list|,
literal|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_destructor
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_function
DECL|function|initThreadPipeFD
specifier|static
name|void
name|initThreadPipeFD
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|int
name|ret
init|=
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
name|perror
argument_list|(
literal|"QEventDispatcherUNIXPrivate: Unable to init thread pipe"
argument_list|)
expr_stmt|;
name|int
name|flags
init|=
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_GETFL
argument_list|)
decl_stmt|;
if|if
condition|(
name|flags
operator|==
operator|-
literal|1
condition|)
name|perror
argument_list|(
literal|"QEventDispatcherUNIXPrivate: Unable to get flags on thread pipe"
argument_list|)
expr_stmt|;
name|ret
operator|=
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFL
argument_list|,
name|flags
operator||
name|O_NONBLOCK
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
name|perror
argument_list|(
literal|"QEventDispatcherUNIXPrivate: Unable to set flags on thread pipe"
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|init
name|bool
name|QThreadPipe
operator|::
name|init
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_NACL
argument_list|)
comment|// do nothing.
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
name|qsnprintf
argument_list|(
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
argument_list|,
literal|"/pipe/qt_%08x"
argument_list|,
name|int
argument_list|(
name|taskIdSelf
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// make sure there is no pipe with this name
name|pipeDevDelete
argument_list|(
name|name
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|// create the pipe
if|if
condition|(
name|pipeDevCreate
argument_list|(
name|name
argument_list|,
literal|128
comment|/*maxMsg*/
argument_list|,
literal|1
comment|/*maxLength*/
argument_list|)
operator|!=
name|OK
condition|)
block|{
name|perror
argument_list|(
literal|"QThreadPipe: Unable to create thread pipe device %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|(
name|fds
index|[
literal|0
index|]
operator|=
name|open
argument_list|(
name|name
argument_list|,
name|O_RDWR
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"QThreadPipe: Unable to open pipe device %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|initThreadPipeFD
argument_list|(
name|fds
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|fds
index|[
literal|1
index|]
operator|=
name|fds
index|[
literal|0
index|]
expr_stmt|;
else|#
directive|else
ifndef|#
directive|ifndef
name|QT_NO_EVENTFD
if|if
condition|(
operator|(
name|fds
index|[
literal|0
index|]
operator|=
name|eventfd
argument_list|(
literal|0
argument_list|,
name|EFD_NONBLOCK
operator||
name|EFD_CLOEXEC
argument_list|)
operator|)
operator|>=
literal|0
condition|)
return|return
literal|true
return|;
endif|#
directive|endif
if|if
condition|(
name|qt_safe_pipe
argument_list|(
name|fds
argument_list|,
name|O_NONBLOCK
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"QThreadPipe: Unable to create pipe"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
endif|#
directive|endif
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|prepare
name|pollfd
name|QThreadPipe
operator|::
name|prepare
parameter_list|()
specifier|const
block|{
return|return
name|make_pollfd
argument_list|(
name|fds
index|[
literal|0
index|]
argument_list|,
name|POLLIN
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|wakeUp
name|void
name|QThreadPipe
operator|::
name|wakeUp
parameter_list|()
block|{
if|if
condition|(
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
ifndef|#
directive|ifndef
name|QT_NO_EVENTFD
if|if
condition|(
name|fds
index|[
literal|1
index|]
operator|==
operator|-
literal|1
condition|)
block|{
comment|// eventfd
name|eventfd_t
name|value
init|=
literal|1
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|eventfd_write
argument_list|(
name|fds
index|[
literal|0
index|]
argument_list|,
name|value
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
name|char
name|c
init|=
literal|0
decl_stmt|;
name|qt_safe_write
argument_list|(
name|fds
index|[
literal|1
index|]
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|check
name|int
name|QThreadPipe
operator|::
name|check
parameter_list|(
specifier|const
name|pollfd
modifier|&
name|pfd
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|pfd
operator|.
name|fd
operator|==
name|fds
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|char
name|c
index|[
literal|16
index|]
decl_stmt|;
specifier|const
name|int
name|readyread
init|=
name|pfd
operator|.
name|revents
operator|&
name|POLLIN
decl_stmt|;
if|if
condition|(
name|readyread
condition|)
block|{
comment|// consume the data on the thread pipe so that
comment|// poll doesn't immediately return next time
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
operator|::
name|read
argument_list|(
name|fds
index|[
literal|0
index|]
argument_list|,
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
operator|::
name|ioctl
argument_list|(
name|fds
index|[
literal|0
index|]
argument_list|,
name|FIOFLUSH
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
ifndef|#
directive|ifndef
name|QT_NO_EVENTFD
if|if
condition|(
name|fds
index|[
literal|1
index|]
operator|==
operator|-
literal|1
condition|)
block|{
comment|// eventfd
name|eventfd_t
name|value
decl_stmt|;
name|eventfd_read
argument_list|(
name|fds
index|[
literal|0
index|]
argument_list|,
operator|&
name|value
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
while|while
condition|(
operator|::
name|read
argument_list|(
name|fds
index|[
literal|0
index|]
argument_list|,
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|c
argument_list|)
argument_list|)
operator|>
literal|0
condition|)
block|{}
block|}
endif|#
directive|endif
if|if
condition|(
operator|!
name|wakeUps
operator|.
name|testAndSetRelease
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
condition|)
block|{
comment|// hopefully, this is dead code
name|qWarning
argument_list|(
literal|"QThreadPipe: internal error, wakeUps.testAndSetRelease(1, 0) failed!"
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|readyread
return|;
block|}
end_function
begin_constructor
DECL|function|QEventDispatcherUNIXPrivate
name|QEventDispatcherUNIXPrivate
operator|::
name|QEventDispatcherUNIXPrivate
parameter_list|()
block|{
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|threadPipe
operator|.
name|init
argument_list|()
operator|==
literal|false
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"QEventDispatcherUNIXPrivate(): Can not continue without a thread pipe"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEventDispatcherUNIXPrivate
name|QEventDispatcherUNIXPrivate
operator|::
name|~
name|QEventDispatcherUNIXPrivate
parameter_list|()
block|{
comment|// cleanup timers
name|qDeleteAll
argument_list|(
name|timerList
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setSocketNotifierPending
name|void
name|QEventDispatcherUNIXPrivate
operator|::
name|setSocketNotifierPending
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
if|if
condition|(
name|pendingNotifiers
operator|.
name|contains
argument_list|(
name|notifier
argument_list|)
condition|)
return|return;
name|pendingNotifiers
operator|<<
name|notifier
expr_stmt|;
block|}
end_function
begin_function
DECL|function|activateTimers
name|int
name|QEventDispatcherUNIXPrivate
operator|::
name|activateTimers
parameter_list|()
block|{
return|return
name|timerList
operator|.
name|activateTimers
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|markPendingSocketNotifiers
name|void
name|QEventDispatcherUNIXPrivate
operator|::
name|markPendingSocketNotifiers
parameter_list|()
block|{
for|for
control|(
specifier|const
name|pollfd
modifier|&
name|pfd
range|:
name|qAsConst
argument_list|(
name|pollfds
argument_list|)
control|)
block|{
if|if
condition|(
name|pfd
operator|.
name|fd
operator|<
literal|0
operator|||
name|pfd
operator|.
name|revents
operator|==
literal|0
condition|)
continue|continue;
name|auto
name|it
init|=
name|socketNotifiers
operator|.
name|find
argument_list|(
name|pfd
operator|.
name|fd
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|it
operator|!=
name|socketNotifiers
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QSocketNotifierSetUNIX
modifier|&
name|sn_set
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
specifier|static
specifier|const
struct|struct
block|{
name|QSocketNotifier
operator|::
name|Type
name|type
decl_stmt|;
name|short
name|flags
decl_stmt|;
block|}
name|notifiers
index|[]
init|=
block|{
block|{
name|QSocketNotifier
operator|::
name|Read
block|,
name|POLLIN
operator||
name|POLLHUP
operator||
name|POLLERR
block|}
block|,
block|{
name|QSocketNotifier
operator|::
name|Write
block|,
name|POLLOUT
operator||
name|POLLHUP
operator||
name|POLLERR
block|}
block|,
block|{
name|QSocketNotifier
operator|::
name|Exception
block|,
name|POLLPRI
operator||
name|POLLHUP
operator||
name|POLLERR
block|}
block|}
struct|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|n
range|:
name|notifiers
control|)
block|{
name|QSocketNotifier
modifier|*
name|notifier
init|=
name|sn_set
operator|.
name|notifiers
index|[
name|n
operator|.
name|type
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|notifier
condition|)
continue|continue;
if|if
condition|(
name|pfd
operator|.
name|revents
operator|&
name|POLLNVAL
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSocketNotifier: Invalid socket %d with type %s, disabling..."
argument_list|,
name|it
operator|.
name|key
argument_list|()
argument_list|,
name|socketType
argument_list|(
name|n
operator|.
name|type
argument_list|)
argument_list|)
expr_stmt|;
name|notifier
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pfd
operator|.
name|revents
operator|&
name|n
operator|.
name|flags
condition|)
name|setSocketNotifierPending
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
block|}
block|}
name|pollfds
operator|.
name|resize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|activateSocketNotifiers
name|int
name|QEventDispatcherUNIXPrivate
operator|::
name|activateSocketNotifiers
parameter_list|()
block|{
name|markPendingSocketNotifiers
argument_list|()
expr_stmt|;
if|if
condition|(
name|pendingNotifiers
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
name|int
name|n_activated
init|=
literal|0
decl_stmt|;
name|QEvent
name|event
argument_list|(
name|QEvent
operator|::
name|SockAct
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|pendingNotifiers
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QSocketNotifier
modifier|*
name|notifier
init|=
name|pendingNotifiers
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|notifier
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
operator|++
name|n_activated
expr_stmt|;
block|}
return|return
name|n_activated
return|;
block|}
end_function
begin_constructor
DECL|function|QEventDispatcherUNIX
name|QEventDispatcherUNIX
operator|::
name|QEventDispatcherUNIX
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
name|QEventDispatcherUNIXPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QEventDispatcherUNIX
name|QEventDispatcherUNIX
operator|::
name|QEventDispatcherUNIX
parameter_list|(
name|QEventDispatcherUNIXPrivate
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
DECL|function|~QEventDispatcherUNIX
name|QEventDispatcherUNIX
operator|::
name|~
name|QEventDispatcherUNIX
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|registerTimer
name|void
name|QEventDispatcherUNIX
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
name|obj
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
operator|||
name|interval
operator|<
literal|0
operator|||
operator|!
name|obj
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherUNIX::registerTimer: invalid arguments"
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|obj
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
literal|"QEventDispatcherUNIX::registerTimer: timers cannot be started from another thread"
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
name|Q_D
argument_list|(
name|QEventDispatcherUNIX
argument_list|)
expr_stmt|;
name|d
operator|->
name|timerList
operator|.
name|registerTimer
argument_list|(
name|timerId
argument_list|,
name|interval
argument_list|,
name|timerType
argument_list|,
name|obj
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|unregisterTimer
name|bool
name|QEventDispatcherUNIX
operator|::
name|unregisterTimer
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
literal|"QEventDispatcherUNIX::unregisterTimer: invalid argument"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
elseif|else
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
literal|"QEventDispatcherUNIX::unregisterTimer: timers cannot be stopped from another thread"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
endif|#
directive|endif
name|Q_D
argument_list|(
name|QEventDispatcherUNIX
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|timerList
operator|.
name|unregisterTimer
argument_list|(
name|timerId
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|unregisterTimers
name|bool
name|QEventDispatcherUNIX
operator|::
name|unregisterTimers
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
operator|!
name|object
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherUNIX::unregisterTimers: invalid argument"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
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
literal|"QEventDispatcherUNIX::unregisterTimers: timers cannot be stopped from another thread"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
endif|#
directive|endif
name|Q_D
argument_list|(
name|QEventDispatcherUNIX
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|timerList
operator|.
name|unregisterTimers
argument_list|(
name|object
argument_list|)
return|;
block|}
end_function
begin_function
name|QList
argument_list|<
name|QEventDispatcherUNIX
operator|::
name|TimerInfo
argument_list|>
DECL|function|registeredTimers
name|QEventDispatcherUNIX
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
literal|"QEventDispatcherUNIX:registeredTimers: invalid argument"
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
name|QEventDispatcherUNIX
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|timerList
operator|.
name|registeredTimers
argument_list|(
name|object
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*****************************************************************************  QEventDispatcher implementations for UNIX  *****************************************************************************/
end_comment
begin_function
DECL|function|registerSocketNotifier
name|void
name|QEventDispatcherUNIX
operator|::
name|registerSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|int
name|sockfd
init|=
name|notifier
operator|->
name|socket
argument_list|()
decl_stmt|;
name|QSocketNotifier
operator|::
name|Type
name|type
init|=
name|notifier
operator|->
name|type
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
name|notifier
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
literal|"QSocketNotifier: socket notifiers cannot be enabled from another thread"
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
name|Q_D
argument_list|(
name|QEventDispatcherUNIX
argument_list|)
expr_stmt|;
name|QSocketNotifierSetUNIX
modifier|&
name|sn_set
init|=
name|d
operator|->
name|socketNotifiers
index|[
name|sockfd
index|]
decl_stmt|;
if|if
condition|(
name|sn_set
operator|.
name|notifiers
index|[
name|type
index|]
operator|&&
name|sn_set
operator|.
name|notifiers
index|[
name|type
index|]
operator|!=
name|notifier
condition|)
name|qWarning
argument_list|(
literal|"%s: Multiple socket notifiers for same socket %d and type %s"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|sockfd
argument_list|,
name|socketType
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
name|sn_set
operator|.
name|notifiers
index|[
name|type
index|]
operator|=
name|notifier
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterSocketNotifier
name|void
name|QEventDispatcherUNIX
operator|::
name|unregisterSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|int
name|sockfd
init|=
name|notifier
operator|->
name|socket
argument_list|()
decl_stmt|;
name|QSocketNotifier
operator|::
name|Type
name|type
init|=
name|notifier
operator|->
name|type
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
if|if
condition|(
name|notifier
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
literal|"QSocketNotifier: socket notifiers cannot be disabled from another thread"
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
name|Q_D
argument_list|(
name|QEventDispatcherUNIX
argument_list|)
expr_stmt|;
name|d
operator|->
name|pendingNotifiers
operator|.
name|removeOne
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|auto
name|i
init|=
name|d
operator|->
name|socketNotifiers
operator|.
name|find
argument_list|(
name|sockfd
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|==
name|d
operator|->
name|socketNotifiers
operator|.
name|end
argument_list|()
condition|)
return|return;
name|QSocketNotifierSetUNIX
modifier|&
name|sn_set
init|=
name|i
operator|.
name|value
argument_list|()
decl_stmt|;
if|if
condition|(
name|sn_set
operator|.
name|notifiers
index|[
name|type
index|]
operator|==
literal|nullptr
condition|)
return|return;
if|if
condition|(
name|sn_set
operator|.
name|notifiers
index|[
name|type
index|]
operator|!=
name|notifier
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Multiple socket notifiers for same socket %d and type %s"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|sockfd
argument_list|,
name|socketType
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|sn_set
operator|.
name|notifiers
index|[
name|type
index|]
operator|=
literal|nullptr
expr_stmt|;
if|if
condition|(
name|sn_set
operator|.
name|isEmpty
argument_list|()
condition|)
name|d
operator|->
name|socketNotifiers
operator|.
name|erase
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processEvents
name|bool
name|QEventDispatcherUNIX
operator|::
name|processEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventDispatcherUNIX
argument_list|)
expr_stmt|;
name|d
operator|->
name|interrupt
operator|.
name|store
argument_list|(
literal|0
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
name|d
operator|->
name|threadData
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|include_timers
init|=
operator|(
name|flags
operator|&
name|QEventLoop
operator|::
name|X11ExcludeTimers
operator|)
operator|==
literal|0
decl_stmt|;
specifier|const
name|bool
name|include_notifiers
init|=
operator|(
name|flags
operator|&
name|QEventLoop
operator|::
name|ExcludeSocketNotifiers
operator|)
operator|==
literal|0
decl_stmt|;
specifier|const
name|bool
name|wait_for_events
init|=
name|flags
operator|&
name|QEventLoop
operator|::
name|WaitForMoreEvents
decl_stmt|;
specifier|const
name|bool
name|canWait
init|=
operator|(
name|d
operator|->
name|threadData
operator|->
name|canWaitLocked
argument_list|()
operator|&&
operator|!
name|d
operator|->
name|interrupt
operator|.
name|load
argument_list|()
operator|&&
name|wait_for_events
operator|)
decl_stmt|;
if|if
condition|(
name|canWait
condition|)
emit|emit
name|aboutToBlock
argument_list|()
emit|;
if|if
condition|(
name|d
operator|->
name|interrupt
operator|.
name|load
argument_list|()
condition|)
return|return
literal|false
return|;
name|timespec
modifier|*
name|tm
init|=
literal|nullptr
decl_stmt|;
name|timespec
name|wait_tm
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
if|if
condition|(
operator|!
name|canWait
operator|||
operator|(
name|include_timers
operator|&&
name|d
operator|->
name|timerList
operator|.
name|timerWait
argument_list|(
name|wait_tm
argument_list|)
operator|)
condition|)
name|tm
operator|=
operator|&
name|wait_tm
expr_stmt|;
name|d
operator|->
name|pollfds
operator|.
name|reserve
argument_list|(
literal|1
operator|+
operator|(
name|include_notifiers
condition|?
name|d
operator|->
name|socketNotifiers
operator|.
name|size
argument_list|()
else|:
literal|0
operator|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|pollfds
operator|.
name|resize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|include_notifiers
condition|)
for|for
control|(
name|auto
name|it
init|=
name|d
operator|->
name|socketNotifiers
operator|.
name|cbegin
argument_list|()
init|;
name|it
operator|!=
name|d
operator|->
name|socketNotifiers
operator|.
name|cend
argument_list|()
condition|;
operator|++
name|it
control|)
name|d
operator|->
name|pollfds
operator|.
name|append
argument_list|(
name|make_pollfd
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|,
name|it
operator|.
name|value
argument_list|()
operator|.
name|events
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// This must be last, as it's popped off the end below
name|d
operator|->
name|pollfds
operator|.
name|append
argument_list|(
name|d
operator|->
name|threadPipe
operator|.
name|prepare
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|nevents
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|qt_safe_poll
argument_list|(
name|d
operator|->
name|pollfds
operator|.
name|data
argument_list|()
argument_list|,
name|d
operator|->
name|pollfds
operator|.
name|size
argument_list|()
argument_list|,
name|tm
argument_list|)
condition|)
block|{
case|case
operator|-
literal|1
case|:
name|perror
argument_list|(
literal|"qt_safe_poll"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0
case|:
break|break;
default|default:
name|nevents
operator|+=
name|d
operator|->
name|threadPipe
operator|.
name|check
argument_list|(
name|d
operator|->
name|pollfds
operator|.
name|takeLast
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|include_notifiers
condition|)
name|nevents
operator|+=
name|d
operator|->
name|activateSocketNotifiers
argument_list|()
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|include_timers
condition|)
name|nevents
operator|+=
name|d
operator|->
name|activateTimers
argument_list|()
expr_stmt|;
comment|// return true if we handled events, false otherwise
return|return
operator|(
name|nevents
operator|>
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|hasPendingEvents
name|bool
name|QEventDispatcherUNIX
operator|::
name|hasPendingEvents
parameter_list|()
block|{
specifier|extern
name|uint
name|qGlobalPostedEventsCount
argument_list|()
decl_stmt|;
comment|// from qapplication.cpp
return|return
name|qGlobalPostedEventsCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|remainingTime
name|int
name|QEventDispatcherUNIX
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
literal|"QEventDispatcherUNIX::remainingTime: invalid argument"
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
name|QEventDispatcherUNIX
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|timerList
operator|.
name|timerRemainingTime
argument_list|(
name|timerId
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|wakeUp
name|void
name|QEventDispatcherUNIX
operator|::
name|wakeUp
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherUNIX
argument_list|)
expr_stmt|;
name|d
operator|->
name|threadPipe
operator|.
name|wakeUp
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|interrupt
name|void
name|QEventDispatcherUNIX
operator|::
name|interrupt
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherUNIX
argument_list|)
expr_stmt|;
name|d
operator|->
name|interrupt
operator|.
name|store
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|wakeUp
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QEventDispatcherUNIX
operator|::
name|flush
parameter_list|()
block|{ }
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
