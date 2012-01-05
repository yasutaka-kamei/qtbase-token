begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSTHREADDEBUG_P_H
end_ifndef
begin_define
DECL|macro|QDBUSTHREADDEBUG_P_H
define|#
directive|define
name|QDBUSTHREADDEBUG_P_H
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
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QDBUS_THREAD_DEBUG
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_BUILD_INTERNAL
argument_list|)
end_if
begin_define
DECL|macro|QDBUS_THREAD_DEBUG
define|#
directive|define
name|QDBUS_THREAD_DEBUG
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|QDBUS_THREAD_DEBUG
end_if
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|qdbusThreadDebugFunc
typedef|typedef
name|void
function_decl|(
modifier|*
name|qdbusThreadDebugFunc
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|QDBusConnectionPrivate
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
name|Q_DBUS_EXPORT
name|void
name|qdbusDefaultThreadDebug
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|QDBusConnectionPrivate
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|extern
name|Q_DBUS_EXPORT
name|qdbusThreadDebugFunc
name|qdbusThreadDebug
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
endif|#
directive|endif
DECL|enum|ThreadAction
name|enum
name|ThreadAction
block|{
DECL|enumerator|ConnectAction
name|ConnectAction
operator|=
literal|0
operator|,
DECL|enumerator|DisconnectAction
name|DisconnectAction
operator|=
literal|1
operator|,
DECL|enumerator|RegisterObjectAction
name|RegisterObjectAction
operator|=
literal|2
operator|,
DECL|enumerator|UnregisterObjectAction
name|UnregisterObjectAction
operator|=
literal|3
operator|,
DECL|enumerator|ObjectRegisteredAtAction
name|ObjectRegisteredAtAction
operator|=
literal|4
operator|,
DECL|enumerator|CloseConnectionAction
name|CloseConnectionAction
operator|=
literal|10
operator|,
DECL|enumerator|ObjectDestroyedAction
name|ObjectDestroyedAction
operator|=
literal|11
operator|,
DECL|enumerator|RelaySignalAction
name|RelaySignalAction
operator|=
literal|12
operator|,
DECL|enumerator|HandleObjectCallAction
name|HandleObjectCallAction
operator|=
literal|13
operator|,
DECL|enumerator|HandleSignalAction
name|HandleSignalAction
operator|=
literal|14
operator|,
DECL|enumerator|ConnectRelayAction
name|ConnectRelayAction
operator|=
literal|15
operator|,
DECL|enumerator|DisconnectRelayAction
name|DisconnectRelayAction
operator|=
literal|16
operator|,
DECL|enumerator|FindMetaObject1Action
name|FindMetaObject1Action
operator|=
literal|17
operator|,
DECL|enumerator|FindMetaObject2Action
name|FindMetaObject2Action
operator|=
literal|18
operator|,
DECL|enumerator|RegisterServiceAction
name|RegisterServiceAction
operator|=
literal|19
operator|,
DECL|enumerator|UnregisterServiceAction
name|UnregisterServiceAction
operator|=
literal|20
operator|,
DECL|enumerator|UpdateSignalHookOwnerAction
name|UpdateSignalHookOwnerAction
operator|=
literal|21
operator|,
DECL|enumerator|HandleObjectCallPostEventAction
name|HandleObjectCallPostEventAction
operator|=
literal|22
operator|,
DECL|enumerator|HandleObjectCallSemaphoreAction
name|HandleObjectCallSemaphoreAction
operator|=
literal|23
operator|,
DECL|enumerator|DoDispatchAction
name|DoDispatchAction
operator|=
literal|24
operator|,
DECL|enumerator|SendWithReplyAsyncAction
name|SendWithReplyAsyncAction
operator|=
literal|25
operator|,
DECL|enumerator|MessageResultReceivedAction
name|MessageResultReceivedAction
operator|=
literal|26
operator|,
DECL|enumerator|ActivateSignalAction
name|ActivateSignalAction
operator|=
literal|27
operator|,
DECL|enumerator|PendingCallBlockAction
name|PendingCallBlockAction
operator|=
literal|28
operator|,
DECL|enumerator|AddTimeoutAction
name|AddTimeoutAction
operator|=
literal|50
operator|,
DECL|enumerator|RealAddTimeoutAction
name|RealAddTimeoutAction
operator|=
literal|51
operator|,
DECL|enumerator|RemoveTimeoutAction
name|RemoveTimeoutAction
operator|=
literal|52
operator|,
DECL|enumerator|KillTimerAction
name|KillTimerAction
operator|=
literal|58
operator|,
DECL|enumerator|TimerEventAction
name|TimerEventAction
operator|=
literal|59
operator|,
DECL|enumerator|AddWatchAction
name|AddWatchAction
operator|=
literal|60
operator|,
DECL|enumerator|RemoveWatchAction
name|RemoveWatchAction
operator|=
literal|61
operator|,
DECL|enumerator|ToggleWatchAction
name|ToggleWatchAction
operator|=
literal|62
operator|,
DECL|enumerator|SocketReadAction
name|SocketReadAction
operator|=
literal|63
operator|,
DECL|enumerator|SocketWriteAction
name|SocketWriteAction
operator|=
literal|64
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|QDBusLockerBase
struct|struct
name|QDBusLockerBase
block|{
DECL|enum|Condition
enum|enum
name|Condition
block|{
DECL|enumerator|BeforeLock
name|BeforeLock
block|,
DECL|enumerator|AfterLock
name|AfterLock
block|,
DECL|enumerator|BeforeUnlock
name|BeforeUnlock
block|,
DECL|enumerator|AfterUnlock
name|AfterUnlock
block|,
DECL|enumerator|BeforePost
name|BeforePost
block|,
DECL|enumerator|AfterPost
name|AfterPost
block|,
DECL|enumerator|BeforeDeliver
name|BeforeDeliver
block|,
DECL|enumerator|AfterDeliver
name|AfterDeliver
block|,
DECL|enumerator|BeforeAcquire
name|BeforeAcquire
block|,
DECL|enumerator|AfterAcquire
name|AfterAcquire
block|,
DECL|enumerator|BeforeRelease
name|BeforeRelease
block|,
DECL|enumerator|AfterRelease
name|AfterRelease
block|}
enum|;
if|#
directive|if
name|QDBUS_THREAD_DEBUG
DECL|function|reportThreadAction
specifier|static
specifier|inline
name|void
name|reportThreadAction
parameter_list|(
name|int
name|action
parameter_list|,
name|int
name|condition
parameter_list|,
name|QDBusConnectionPrivate
modifier|*
name|ptr
parameter_list|)
block|{
if|if
condition|(
name|qdbusThreadDebug
condition|)
name|qdbusThreadDebug
argument_list|(
name|action
argument_list|,
name|condition
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
DECL|function|reportThreadAction
specifier|static
specifier|inline
name|void
name|reportThreadAction
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|QDBusConnectionPrivate
modifier|*
parameter_list|)
block|{ }
endif|#
directive|endif
block|}
struct|;
end_struct
begin_decl_stmt
DECL|struct|QDBusLockerBase
name|struct
name|QDBusReadLocker
range|:
name|QDBusLockerBase
block|{
DECL|member|self
name|QDBusConnectionPrivate
operator|*
name|self
block|;
DECL|member|action
name|ThreadAction
name|action
block|;
DECL|function|QDBusReadLocker
specifier|inline
name|QDBusReadLocker
argument_list|(
argument|ThreadAction a
argument_list|,
argument|QDBusConnectionPrivate *s
argument_list|)
operator|:
name|self
argument_list|(
name|s
argument_list|)
block|,
name|action
argument_list|(
argument|a
argument_list|)
block|{
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|BeforeLock
argument_list|,
name|self
argument_list|)
block|;
name|self
operator|->
name|lock
operator|.
name|lockForRead
argument_list|()
block|;
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|AfterLock
argument_list|,
name|self
argument_list|)
block|;     }
DECL|function|~QDBusReadLocker
specifier|inline
operator|~
name|QDBusReadLocker
argument_list|()
block|{
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|BeforeUnlock
argument_list|,
name|self
argument_list|)
block|;
name|self
operator|->
name|lock
operator|.
name|unlock
argument_list|()
block|;
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|AfterUnlock
argument_list|,
name|self
argument_list|)
block|;     }
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|struct|QDBusLockerBase
name|struct
name|QDBusWriteLocker
range|:
name|QDBusLockerBase
block|{
DECL|member|self
name|QDBusConnectionPrivate
operator|*
name|self
block|;
DECL|member|action
name|ThreadAction
name|action
block|;
DECL|function|QDBusWriteLocker
specifier|inline
name|QDBusWriteLocker
argument_list|(
argument|ThreadAction a
argument_list|,
argument|QDBusConnectionPrivate *s
argument_list|)
operator|:
name|self
argument_list|(
name|s
argument_list|)
block|,
name|action
argument_list|(
argument|a
argument_list|)
block|{
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|BeforeLock
argument_list|,
name|self
argument_list|)
block|;
name|self
operator|->
name|lock
operator|.
name|lockForWrite
argument_list|()
block|;
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|AfterLock
argument_list|,
name|self
argument_list|)
block|;     }
DECL|function|~QDBusWriteLocker
specifier|inline
operator|~
name|QDBusWriteLocker
argument_list|()
block|{
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|BeforeUnlock
argument_list|,
name|self
argument_list|)
block|;
name|self
operator|->
name|lock
operator|.
name|unlock
argument_list|()
block|;
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|AfterUnlock
argument_list|,
name|self
argument_list|)
block|;     }
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|struct|QDBusLockerBase
name|struct
name|QDBusMutexLocker
range|:
name|QDBusLockerBase
block|{
DECL|member|self
name|QDBusConnectionPrivate
operator|*
name|self
block|;
DECL|member|mutex
name|QMutex
operator|*
name|mutex
block|;
DECL|member|action
name|ThreadAction
name|action
block|;
DECL|function|QDBusMutexLocker
specifier|inline
name|QDBusMutexLocker
argument_list|(
argument|ThreadAction a
argument_list|,
argument|QDBusConnectionPrivate *s
argument_list|,
argument|QMutex *m
argument_list|)
operator|:
name|self
argument_list|(
name|s
argument_list|)
block|,
name|mutex
argument_list|(
name|m
argument_list|)
block|,
name|action
argument_list|(
argument|a
argument_list|)
block|{
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|BeforeLock
argument_list|,
name|self
argument_list|)
block|;
name|mutex
operator|->
name|lock
argument_list|()
block|;
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|AfterLock
argument_list|,
name|self
argument_list|)
block|;     }
DECL|function|~QDBusMutexLocker
specifier|inline
operator|~
name|QDBusMutexLocker
argument_list|()
block|{
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|BeforeUnlock
argument_list|,
name|self
argument_list|)
block|;
name|mutex
operator|->
name|unlock
argument_list|()
block|;
name|reportThreadAction
argument_list|(
name|action
argument_list|,
name|AfterUnlock
argument_list|,
name|self
argument_list|)
block|;     }
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|struct|QDBusMutexLocker
name|struct
name|QDBusDispatchLocker
range|:
name|QDBusMutexLocker
block|{
DECL|function|QDBusDispatchLocker
specifier|inline
name|QDBusDispatchLocker
argument_list|(
argument|ThreadAction a
argument_list|,
argument|QDBusConnectionPrivate *s
argument_list|)
operator|:
name|QDBusMutexLocker
argument_list|(
argument|a
argument_list|,
argument|s
argument_list|,
argument|&s->dispatchLock
argument_list|)
block|{ }
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|struct|QDBusMutexLocker
name|struct
name|QDBusWatchAndTimeoutLocker
range|:
name|QDBusMutexLocker
block|{
DECL|function|QDBusWatchAndTimeoutLocker
specifier|inline
name|QDBusWatchAndTimeoutLocker
argument_list|(
argument|ThreadAction a
argument_list|,
argument|QDBusConnectionPrivate *s
argument_list|)
operator|:
name|QDBusMutexLocker
argument_list|(
argument|a
argument_list|,
argument|s
argument_list|,
argument|&s->watchAndTimeoutLock
argument_list|)
block|{ }
block|}
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|QDBUS_THREAD_DEBUG
end_if
begin_define
DECL|macro|SEM_ACQUIRE
define|#
directive|define
name|SEM_ACQUIRE
parameter_list|(
name|action
parameter_list|,
name|sem
parameter_list|)
define|\
value|do {                                                                \     QDBusLockerBase::reportThreadAction(action, QDBusLockerBase::BeforeAcquire, this); \     sem.acquire();                                                      \     QDBusLockerBase::reportThreadAction(action, QDBusLockerBase::AfterAcquire, this); \     } while (0)
end_define
begin_define
DECL|macro|SEM_RELEASE
define|#
directive|define
name|SEM_RELEASE
parameter_list|(
name|action
parameter_list|,
name|sem
parameter_list|)
define|\
value|do {                                                                \     QDBusLockerBase::reportThreadAction(action, QDBusLockerBase::BeforeRelease, that); \     sem.release();                                                      \     QDBusLockerBase::reportThreadAction(action, QDBusLockerBase::AfterRelease, that); \     } while (0)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SEM_ACQUIRE
define|#
directive|define
name|SEM_ACQUIRE
parameter_list|(
name|action
parameter_list|,
name|sem
parameter_list|)
value|sem.acquire()
end_define
begin_define
DECL|macro|SEM_RELEASE
define|#
directive|define
name|SEM_RELEASE
parameter_list|(
name|action
parameter_list|,
name|sem
parameter_list|)
value|sem.release()
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
