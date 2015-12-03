begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEventDispatcherUNIXPrivate
name|class
name|QEventDispatcherUNIXPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|struct|Q_DECL_FINAL
name|struct
name|Q_CORE_EXPORT
name|QSocketNotifierSetUNIX
name|Q_DECL_FINAL
block|{
DECL|member|Q_DECL_NOTHROW
specifier|inline
name|QSocketNotifierSetUNIX
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
DECL|member|Q_DECL_NOTHROW
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
DECL|member|Q_DECL_NOTHROW
specifier|inline
name|short
name|events
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
DECL|member|notifiers
name|QSocketNotifier
modifier|*
name|notifiers
index|[
literal|3
index|]
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QSocketNotifierSetUNIX
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_struct
DECL|struct|QThreadPipe
struct|struct
name|QThreadPipe
block|{
name|QThreadPipe
argument_list|()
expr_stmt|;
operator|~
name|QThreadPipe
argument_list|()
expr_stmt|;
name|bool
name|init
parameter_list|()
function_decl|;
name|pollfd
name|prepare
argument_list|()
specifier|const
expr_stmt|;
name|void
name|wakeUp
parameter_list|()
function_decl|;
name|int
name|check
parameter_list|(
specifier|const
name|pollfd
modifier|&
name|pfd
parameter_list|)
function_decl|;
comment|// note for eventfd(7) support:
comment|// if fds[1] is -1, then eventfd(7) is in use and is stored in fds[0]
DECL|member|fds
name|int
name|fds
index|[
literal|2
index|]
decl_stmt|;
DECL|member|wakeUps
name|QAtomicInt
name|wakeUps
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
DECL|member|len_name
specifier|static
specifier|const
name|int
name|len_name
init|=
literal|20
decl_stmt|;
DECL|member|name
name|char
name|name
index|[
name|len_name
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct
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
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasPendingEvents
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|registerSocketNotifier
argument_list|(
argument|QSocketNotifier *notifier
argument_list|)
name|Q_DECL_FINAL
block|;
name|void
name|unregisterSocketNotifier
argument_list|(
argument|QSocketNotifier *notifier
argument_list|)
name|Q_DECL_FINAL
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
name|Q_DECL_FINAL
block|;
name|bool
name|unregisterTimer
argument_list|(
argument|int timerId
argument_list|)
name|Q_DECL_FINAL
block|;
name|bool
name|unregisterTimers
argument_list|(
argument|QObject *object
argument_list|)
name|Q_DECL_FINAL
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
name|Q_DECL_FINAL
block|;
name|int
name|remainingTime
argument_list|(
argument|int timerId
argument_list|)
name|Q_DECL_FINAL
block|;
name|void
name|wakeUp
argument_list|()
name|Q_DECL_FINAL
block|;
name|void
name|interrupt
argument_list|()
name|Q_DECL_FINAL
block|;
name|void
name|flush
argument_list|()
name|Q_DECL_OVERRIDE
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
name|activateTimers
argument_list|()
block|;
name|void
name|markPendingSocketNotifiers
argument_list|()
block|;
name|int
name|activateSocketNotifiers
argument_list|()
block|;
name|void
name|setSocketNotifierPending
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
name|QThreadPipe
name|threadPipe
block|;
name|QVector
operator|<
name|pollfd
operator|>
name|pollfds
block|;
name|QHash
operator|<
name|int
block|,
name|QSocketNotifierSetUNIX
operator|>
name|socketNotifiers
block|;
name|QVector
operator|<
name|QSocketNotifier
operator|*
operator|>
name|pendingNotifiers
block|;
name|QTimerInfoList
name|timerList
block|;
name|QAtomicInt
name|interrupt
block|;
comment|// bool
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|QSocketNotifierSetUNIX
operator|::
name|QSocketNotifierSetUNIX
argument_list|()
name|Q_DECL_NOTHROW
block|{
name|notifiers
index|[
literal|0
index|]
operator|=
literal|0
block|;
name|notifiers
index|[
literal|1
index|]
operator|=
literal|0
block|;
name|notifiers
index|[
literal|2
index|]
operator|=
literal|0
block|; }
specifier|inline
name|bool
name|QSocketNotifierSetUNIX
operator|::
name|isEmpty
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
operator|!
name|notifiers
index|[
literal|0
index|]
operator|&&
operator|!
name|notifiers
index|[
literal|1
index|]
operator|&&
operator|!
name|notifiers
index|[
literal|2
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|short
name|QSocketNotifierSetUNIX
operator|::
name|events
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
name|short
name|result
operator|=
literal|0
block|;
if|if
condition|(
name|notifiers
index|[
literal|0
index|]
condition|)
name|result
operator||=
name|POLLIN
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|notifiers
index|[
literal|1
index|]
condition|)
name|result
operator||=
name|POLLOUT
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|notifiers
index|[
literal|2
index|]
condition|)
name|result
operator||=
name|POLLPRI
expr_stmt|;
end_if
begin_return
return|return
name|result
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QEVENTDISPATCHER_UNIX_P_H
end_comment
end_unit
