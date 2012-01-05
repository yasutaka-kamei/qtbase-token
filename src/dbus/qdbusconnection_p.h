begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
comment|// This file is not part of the public API.  This header file may
end_comment
begin_comment
comment|// change from version to version without notice, or even be
end_comment
begin_comment
comment|// removed.
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
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSCONNECTION_P_H
end_ifndef
begin_define
DECL|macro|QDBUSCONNECTION_P_H
define|#
directive|define
name|QDBUSCONNECTION_P_H
end_define
begin_include
include|#
directive|include
file|<qdbuserror.h>
end_include
begin_include
include|#
directive|include
file|<qdbusconnection.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qreadwritelock.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|"qdbus_symbols_p.h"
end_include
begin_include
include|#
directive|include
file|<qdbusmessage.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusMessage
name|class
name|QDBusMessage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimerEvent
name|class
name|QTimerEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusObjectPrivate
name|class
name|QDBusObjectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusCallDeliveryEvent
name|class
name|QDBusCallDeliveryEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusActivateObjectEvent
name|class
name|QDBusActivateObjectEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMetaMethod
name|class
name|QMetaMethod
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusInterfacePrivate
name|class
name|QDBusInterfacePrivate
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QDBusMetaObject
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QDBusAbstractInterface
name|class
name|QDBusAbstractInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusConnectionInterface
name|class
name|QDBusConnectionInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPendingCallPrivate
name|class
name|QDBusPendingCallPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusErrorInternal
block|{
name|mutable
name|DBusError
name|error
decl_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QDBusErrorInternal
argument_list|)
name|public
label|:
specifier|inline
name|QDBusErrorInternal
argument_list|()
block|{
name|q_dbus_error_init
argument_list|(
operator|&
name|error
argument_list|)
block|; }
specifier|inline
operator|~
name|QDBusErrorInternal
argument_list|()
block|{
name|q_dbus_error_free
argument_list|(
operator|&
name|error
argument_list|)
block|; }
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
operator|!
name|q_dbus_error_is_set
argument_list|(
operator|&
name|error
argument_list|)
return|;
block|}
specifier|inline
name|operator
name|DBusError
modifier|*
parameter_list|()
block|{
name|q_dbus_error_free
argument_list|(
operator|&
name|error
argument_list|)
expr_stmt|;
return|return
operator|&
name|error
return|;
block|}
specifier|inline
name|operator
name|QDBusError
argument_list|()
specifier|const
block|{
name|QDBusError
name|err
argument_list|(
operator|&
name|error
argument_list|)
block|;
name|q_dbus_error_free
argument_list|(
operator|&
name|error
argument_list|)
block|;
return|return
name|err
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// QDBusConnectionPrivate holds the DBusConnection and
end_comment
begin_comment
comment|// can have many QDBusConnection objects referring to it
end_comment
begin_decl_stmt
name|class
name|QDBusConnectionPrivate
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
comment|// structs and enums
expr|enum
name|ConnectionMode
block|{
name|InvalidMode
block|,
name|ServerMode
block|,
name|ClientMode
block|,
name|PeerMode
block|}
block|;
comment|// LocalMode
block|struct
name|Watcher
block|{
name|Watcher
argument_list|()
operator|:
name|watch
argument_list|(
literal|0
argument_list|)
block|,
name|read
argument_list|(
literal|0
argument_list|)
block|,
name|write
argument_list|(
literal|0
argument_list|)
block|{}
name|DBusWatch
operator|*
name|watch
block|;
name|QSocketNotifier
operator|*
name|read
block|;
name|QSocketNotifier
operator|*
name|write
block|;     }
block|;      struct
name|SignalHook
block|{
specifier|inline
name|SignalHook
argument_list|()
operator|:
name|obj
argument_list|(
literal|0
argument_list|)
block|,
name|midx
argument_list|(
argument|-
literal|1
argument_list|)
block|{ }
name|QString
name|service
block|,
name|path
block|,
name|signature
block|;
name|QObject
operator|*
name|obj
block|;
name|int
name|midx
block|;
name|QList
operator|<
name|int
operator|>
name|params
block|;
name|QStringList
name|argumentMatch
block|;
name|QByteArray
name|matchRule
block|;     }
block|;      enum
name|TreeNodeType
block|{
name|Object
operator|=
literal|0x0
block|,
name|VirtualObject
operator|=
literal|0x01000000
block|}
block|;      struct
name|ObjectTreeNode
block|{
typedef|typedef
name|QVector
operator|<
name|ObjectTreeNode
operator|>
name|DataList
expr_stmt|;
specifier|inline
name|ObjectTreeNode
argument_list|()
operator|:
name|obj
argument_list|(
literal|0
argument_list|)
block|,
name|flags
argument_list|(
literal|0
argument_list|)
block|{ }
specifier|inline
name|ObjectTreeNode
argument_list|(
specifier|const
name|QString
operator|&
name|n
argument_list|)
comment|// intentionally implicit
operator|:
name|name
argument_list|(
name|n
argument_list|)
block|,
name|obj
argument_list|(
literal|0
argument_list|)
block|,
name|flags
argument_list|(
literal|0
argument_list|)
block|{ }
specifier|inline
operator|~
name|ObjectTreeNode
argument_list|()
block|{ }
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QString
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|name
operator|<
name|other
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QStringRef
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|QStringRef
argument_list|(
operator|&
name|name
argument_list|)
operator|<
name|other
return|;
block|}
name|QString
name|name
block|;
expr|union
block|{
name|QObject
operator|*
name|obj
block|;
name|QDBusVirtualObject
operator|*
name|treeNode
block|;         }
block|;
name|int
name|flags
block|;
name|DataList
name|children
block|;     }
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_comment
comment|// typedefs
end_comment
begin_typedef
typedef|typedef
name|QMultiHash
operator|<
name|int
operator|,
name|Watcher
operator|>
name|WatcherHash
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|DBusTimeout
operator|*
operator|>
name|TimeoutHash
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QList
operator|<
name|QPair
operator|<
name|DBusTimeout
operator|*
operator|,
name|int
operator|>
expr|>
name|PendingTimeoutList
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QMultiHash
operator|<
name|QString
operator|,
name|SignalHook
operator|>
name|SignalHookHash
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|QDBusMetaObject
operator|*
operator|>
name|MetaObjectHash
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|QHash
operator|<
name|QByteArray
operator|,
name|int
operator|>
name|MatchRefCountHash
expr_stmt|;
end_typedef
begin_struct
struct|struct
name|WatchedServiceData
block|{
name|WatchedServiceData
argument_list|()
operator|:
name|refcount
argument_list|(
literal|0
argument_list|)
block|{}
name|WatchedServiceData
argument_list|(
argument|const QString&owner
argument_list|,
argument|int refcount =
literal|0
argument_list|)
operator|:
name|owner
argument_list|(
name|owner
argument_list|)
operator|,
name|refcount
argument_list|(
argument|refcount
argument_list|)
block|{}
name|QString
name|owner
expr_stmt|;
name|int
name|refcount
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|WatchedServiceData
operator|>
name|WatchedServicesHash
expr_stmt|;
end_typedef
begin_label
name|public
label|:
end_label
begin_comment
comment|// public methods are entry points from other objects
end_comment
begin_function_decl
name|explicit
name|QDBusConnectionPrivate
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
operator|~
name|QDBusConnectionPrivate
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|deleteYourself
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setBusService
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setPeer
parameter_list|(
name|DBusConnection
modifier|*
name|connection
parameter_list|,
specifier|const
name|QDBusErrorInternal
modifier|&
name|error
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setConnection
parameter_list|(
name|DBusConnection
modifier|*
name|connection
parameter_list|,
specifier|const
name|QDBusErrorInternal
modifier|&
name|error
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setServer
parameter_list|(
name|DBusServer
modifier|*
name|server
parameter_list|,
specifier|const
name|QDBusErrorInternal
modifier|&
name|error
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|closeConnection
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QString
name|getNameOwner
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|send
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QDBusMessage
name|sendWithReply
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|timeout
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QDBusMessage
name|sendWithReplyLocal
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QDBusPendingCallPrivate
modifier|*
name|sendWithReplyAsync
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|,
name|int
name|timeout
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|sendWithReplyAsync
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|returnMethod
parameter_list|,
specifier|const
name|char
modifier|*
name|errorMethod
parameter_list|,
name|int
name|timeout
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|connectSignal
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|argumentMatch
parameter_list|,
specifier|const
name|QString
modifier|&
name|signature
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|connectSignal
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|SignalHook
modifier|&
name|hook
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|SignalHookHash
operator|::
name|Iterator
name|disconnectSignal
argument_list|(
name|SignalHookHash
operator|::
name|Iterator
operator|&
name|it
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|disconnectSignal
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|argumentMatch
parameter_list|,
specifier|const
name|QString
modifier|&
name|signature
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|registerObject
parameter_list|(
specifier|const
name|ObjectTreeNode
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|connectRelay
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
name|QDBusAbstractInterface
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|signal
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|disconnectRelay
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
name|QDBusAbstractInterface
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|signal
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|registerService
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|unregisterService
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|handleMessage
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|waitForFinished
parameter_list|(
name|QDBusPendingCallPrivate
modifier|*
name|pcall
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QDBusMetaObject
modifier|*
name|findMetaObject
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
name|QDBusError
modifier|&
name|error
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|postEventToThread
parameter_list|(
name|int
name|action
parameter_list|,
name|QObject
modifier|*
name|target
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|void
name|serverConnection
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|)
block|{
name|emit
name|newServerConnection
argument_list|(
name|connection
argument_list|)
decl_stmt|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|checkThread
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|handleError
parameter_list|(
specifier|const
name|QDBusErrorInternal
modifier|&
name|error
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleSignal
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleSignal
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleObjectCall
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|activateSignal
parameter_list|(
specifier|const
name|SignalHook
modifier|&
name|hook
parameter_list|,
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|activateObject
parameter_list|(
name|ObjectTreeNode
modifier|&
name|node
parameter_list|,
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|,
name|int
name|pathStartPos
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|activateInternalFilters
parameter_list|(
specifier|const
name|ObjectTreeNode
modifier|&
name|node
parameter_list|,
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|activateCall
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|sendError
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|,
name|QDBusError
operator|::
name|ErrorType
name|code
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|deliverCall
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
name|int
name|flags
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|,
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|metaTypes
argument_list|,
name|int
name|slotIdx
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|isServiceRegisteredByThread
argument_list|(
specifier|const
name|QString
operator|&
name|serviceName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QString
name|getNameOwnerNoCache
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_function_decl
name|void
name|customEvent
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|public
name|slots
range|:
comment|// public slots
name|void
name|doDispatch
argument_list|()
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|socketRead
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|socketWrite
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|objectDestroyed
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|relaySignal
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
parameter_list|,
name|int
name|signalId
parameter_list|,
specifier|const
name|QVariantList
modifier|&
name|args
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|private
name|slots
range|:
name|void
name|serviceOwnerChangedNoLock
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|oldOwner
argument_list|,
specifier|const
name|QString
operator|&
name|newOwner
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|registerServiceNoLock
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|unregisterServiceNoLock
parameter_list|(
specifier|const
name|QString
modifier|&
name|serviceName
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|signals
label|:
end_label
begin_function_decl
name|void
name|serviceOwnerChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|oldOwner
parameter_list|,
specifier|const
name|QString
modifier|&
name|newOwner
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|callWithCallbackFailed
parameter_list|(
specifier|const
name|QDBusError
modifier|&
name|error
parameter_list|,
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|newServerConnection
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|public
label|:
end_label
begin_decl_stmt
name|QAtomicInt
name|ref
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QDBusConnection
operator|::
name|ConnectionCapabilities
name|capabilities
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|name
decl_stmt|;
end_decl_stmt
begin_comment
comment|// this connection's name
end_comment
begin_decl_stmt
name|QString
name|baseService
decl_stmt|;
end_decl_stmt
begin_comment
comment|// this connection's base service
end_comment
begin_decl_stmt
name|ConnectionMode
name|mode
decl_stmt|;
end_decl_stmt
begin_comment
comment|// members accessed in unlocked mode (except for deletion)
end_comment
begin_comment
comment|// connection and server provide their own locking mechanisms
end_comment
begin_comment
comment|// busService doesn't have state to be changed
end_comment
begin_decl_stmt
name|DBusConnection
modifier|*
name|connection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|DBusServer
modifier|*
name|server
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDBusConnectionInterface
modifier|*
name|busService
decl_stmt|;
end_decl_stmt
begin_comment
comment|// watchers and timeouts are accessed from any thread
end_comment
begin_comment
comment|// but the corresponding timer and QSocketNotifier must be handled
end_comment
begin_comment
comment|// only in the object's thread
end_comment
begin_decl_stmt
name|QMutex
name|watchAndTimeoutLock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|WatcherHash
name|watchers
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TimeoutHash
name|timeouts
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PendingTimeoutList
name|timeoutsPendingAdd
decl_stmt|;
end_decl_stmt
begin_comment
comment|// members accessed through a lock
end_comment
begin_decl_stmt
name|QMutex
name|dispatchLock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QReadWriteLock
name|lock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDBusError
name|lastError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringList
name|serviceNames
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|WatchedServicesHash
name|watchedServices
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|SignalHookHash
name|signalHooks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|MatchRefCountHash
name|matchRefCounts
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ObjectTreeNode
name|rootNode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|MetaObjectHash
name|cachedMetaObjects
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QMutex
name|callDeliveryMutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDBusCallDeliveryEvent
modifier|*
name|callDeliveryState
decl_stmt|;
end_decl_stmt
begin_comment
comment|// protected by the callDeliveryMutex mutex
end_comment
begin_label
name|public
label|:
end_label
begin_comment
comment|// static methods
end_comment
begin_decl_stmt
specifier|static
name|int
name|findSlot
argument_list|(
name|QObject
operator|*
name|obj
argument_list|,
specifier|const
name|QByteArray
operator|&
name|normalizedName
argument_list|,
name|QList
operator|<
name|int
operator|>
operator|&
name|params
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|bool
name|prepareHook
argument_list|(
name|QDBusConnectionPrivate
operator|::
name|SignalHook
operator|&
name|hook
argument_list|,
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QString
operator|&
name|service
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QString
operator|&
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QStringList
operator|&
name|argMatch
argument_list|,
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|signal
argument_list|,
name|int
name|minMIdx
argument_list|,
name|bool
name|buildSignature
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|DBusHandlerResult
name|messageFilter
parameter_list|(
name|DBusConnection
modifier|*
parameter_list|,
name|DBusMessage
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|bool
name|checkReplyForDelivery
argument_list|(
name|QDBusConnectionPrivate
operator|*
name|target
argument_list|,
name|QObject
operator|*
name|object
argument_list|,
name|int
name|idx
argument_list|,
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|metaTypes
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|QDBusCallDeliveryEvent
modifier|*
name|prepareReply
argument_list|(
name|QDBusConnectionPrivate
operator|*
name|target
argument_list|,
name|QObject
operator|*
name|object
argument_list|,
name|int
name|idx
argument_list|,
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|metaTypes
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|void
name|processFinishedCall
parameter_list|(
name|QDBusPendingCallPrivate
modifier|*
name|call
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|static
name|QDBusConnectionPrivate
modifier|*
name|d
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|q
parameter_list|)
block|{
return|return
name|q
operator|.
name|d
return|;
block|}
end_function
begin_function
specifier|static
name|QDBusConnection
name|q
parameter_list|(
name|QDBusConnectionPrivate
modifier|*
name|connection
parameter_list|)
block|{
return|return
name|QDBusConnection
argument_list|(
name|connection
argument_list|)
return|;
block|}
end_function
begin_function_decl
specifier|static
name|void
name|setSender
parameter_list|(
specifier|const
name|QDBusConnectionPrivate
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|friend
name|class
name|QDBusActivateObjectEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QDBusCallDeliveryEvent
decl_stmt|;
end_decl_stmt
begin_comment
unit|};
comment|// in qdbusmisc.cpp
end_comment
begin_decl_stmt
specifier|extern
name|int
name|qDBusParametersForMethod
argument_list|(
specifier|const
name|QMetaMethod
operator|&
name|mm
argument_list|,
name|QList
operator|<
name|int
operator|>
operator|&
name|metaTypes
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|extern
name|int
name|qDBusNameToTypeId
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|bool
name|qDBusCheckAsyncTag
parameter_list|(
specifier|const
name|char
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|bool
name|qDBusInterfaceInObject
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface_name
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|QString
name|qDBusInterfaceFromMetaObject
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|mo
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// in qdbusinternalfilters.cpp
end_comment
begin_decl_stmt
specifier|extern
name|QString
name|qDBusIntrospectObject
argument_list|(
specifier|const
name|QDBusConnectionPrivate
operator|::
name|ObjectTreeNode
operator|&
name|node
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|QDBusMessage
name|qDBusPropertyGet
argument_list|(
specifier|const
name|QDBusConnectionPrivate
operator|::
name|ObjectTreeNode
operator|&
name|node
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|QDBusMessage
name|qDBusPropertySet
argument_list|(
specifier|const
name|QDBusConnectionPrivate
operator|::
name|ObjectTreeNode
operator|&
name|node
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|QDBusMessage
name|qDBusPropertyGetAll
argument_list|(
specifier|const
name|QDBusConnectionPrivate
operator|::
name|ObjectTreeNode
operator|&
name|node
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|)
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
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
