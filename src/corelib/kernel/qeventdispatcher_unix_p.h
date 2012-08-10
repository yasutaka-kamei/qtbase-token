begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTDISPATCHER_UNIX_P_H
end_ifndef
begin_define
DECL|macro|QEVENTDISPATCHER_UNIX_P_H
define|#
directive|define
name|QEVENTDISPATCHER_UNIX_P_H
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
file|"QtCore/qlist.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstracteventdispatcher_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpodlist_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvarlengtharray.h"
end_include
begin_include
include|#
directive|include
file|"private/qtimerinfo_unix_p.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|Q_OS_HPUX
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_NACL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/select.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
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
DECL|member|queue
name|fd_set
modifier|*
name|queue
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QSockNotType
block|{
name|public
label|:
name|QSockNotType
argument_list|()
expr_stmt|;
operator|~
name|QSockNotType
argument_list|()
expr_stmt|;
typedef|typedef
name|QPodList
operator|<
name|QSockNot
operator|*
operator|,
literal|32
operator|>
name|List
expr_stmt|;
name|List
name|list
decl_stmt|;
name|fd_set
name|select_fds
decl_stmt|;
name|fd_set
name|enabled_fds
decl_stmt|;
name|fd_set
name|pending_fds
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QEventDispatcherUNIXPrivate
name|class
name|QEventDispatcherUNIXPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QEventDispatcherUNIX
range|:
name|public
name|QAbstractEventDispatcher
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QEventDispatcherUNIX
argument_list|)
name|public
operator|:
name|explicit
name|QEventDispatcherUNIX
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEventDispatcherUNIX
argument_list|()
block|;
name|bool
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
name|protected
operator|:
name|QEventDispatcherUNIX
argument_list|(
name|QEventDispatcherUNIXPrivate
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
name|void
name|setSocketNotifierPending
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
name|int
name|activateTimers
argument_list|()
block|;
name|int
name|activateSocketNotifiers
argument_list|()
block|;
name|virtual
name|int
name|select
argument_list|(
argument|int nfds
argument_list|,
argument|fd_set *readfds
argument_list|,
argument|fd_set *writefds
argument_list|,
argument|fd_set *exceptfds
argument_list|,
argument|timespec *timeout
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QEventDispatcherUNIXPrivate
range|:
name|public
name|QAbstractEventDispatcherPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QEventDispatcherUNIX
argument_list|)
name|public
operator|:
name|QEventDispatcherUNIXPrivate
argument_list|()
block|;
operator|~
name|QEventDispatcherUNIXPrivate
argument_list|()
block|;
name|int
name|doSelect
argument_list|(
argument|QEventLoop::ProcessEventsFlags flags
argument_list|,
argument|timespec *timeout
argument_list|)
block|;
name|virtual
name|int
name|initThreadWakeUp
argument_list|()
block|;
name|virtual
name|int
name|processThreadWakeUp
argument_list|(
argument|int nsel
argument_list|)
block|;
name|bool
name|mainThread
block|;
comment|// note for eventfd(7) support:
comment|// if thread_pipe[1] is -1, then eventfd(7) is in use and is stored in thread_pipe[0]
name|int
name|thread_pipe
index|[
literal|2
index|]
block|;
comment|// highest fd for all socket notifiers
name|int
name|sn_highest
block|;
comment|// 3 socket notifier types - read, write and exception
name|QSockNotType
name|sn_vec
index|[
literal|3
index|]
block|;
name|QTimerInfoList
name|timerList
block|;
comment|// pending socket notifiers list
name|QSockNotType
operator|::
name|List
name|sn_pending_list
block|;
name|QAtomicInt
name|wakeUps
block|;
name|bool
name|interrupt
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
comment|// QEVENTDISPATCHER_UNIX_P_H
end_comment
end_unit
