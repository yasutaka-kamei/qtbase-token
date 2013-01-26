begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSCONNECTIONINTERFACE_H
end_ifndef
begin_define
DECL|macro|QDBUSCONNECTIONINTERFACE_H
define|#
directive|define
name|QDBUSCONNECTIONINTERFACE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusabstractinterface.h>
end_include
begin_include
include|#
directive|include
file|<QtDBus/qdbusreply.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusConnection
name|class
name|QDBusConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*  * Proxy class for interface org.freedesktop.DBus  */
end_comment
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusConnectionInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|ServiceQueueOptions ServiceReplacementOptions RegisterServiceReply
argument_list|)
name|friend
name|class
name|QDBusConnectionPrivate
block|;
specifier|static
specifier|inline
specifier|const
name|char
operator|*
name|staticInterfaceName
argument_list|()
block|;
name|explicit
name|QDBusConnectionInterface
argument_list|(
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
operator|~
name|QDBusConnectionInterface
argument_list|()
block|;
name|Q_PROPERTY
argument_list|(
argument|QDBusReply<QStringList> registeredServiceNames READ registeredServiceNames
argument_list|)
name|public
operator|:
expr|enum
name|ServiceQueueOptions
block|{
name|DontQueueService
block|,
name|QueueService
block|,
name|ReplaceExistingService
block|}
block|;     enum
name|ServiceReplacementOptions
block|{
name|DontAllowReplacement
block|,
name|AllowReplacement
block|}
block|;     enum
name|RegisterServiceReply
block|{
name|ServiceNotRegistered
operator|=
literal|0
block|,
name|ServiceRegistered
block|,
name|ServiceQueued
block|}
block|;
name|public
name|Q_SLOTS
operator|:
name|QDBusReply
operator|<
name|QStringList
operator|>
name|registeredServiceNames
argument_list|()
specifier|const
block|;
name|QDBusReply
operator|<
name|bool
operator|>
name|isServiceRegistered
argument_list|(
argument|const QString&serviceName
argument_list|)
specifier|const
block|;
name|QDBusReply
operator|<
name|QString
operator|>
name|serviceOwner
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|QDBusReply
operator|<
name|bool
operator|>
name|unregisterService
argument_list|(
specifier|const
name|QString
operator|&
name|serviceName
argument_list|)
block|;
name|QDBusReply
operator|<
name|QDBusConnectionInterface
operator|::
name|RegisterServiceReply
operator|>
name|registerService
argument_list|(
argument|const QString&serviceName
argument_list|,
argument|ServiceQueueOptions qoption = DontQueueService
argument_list|,
argument|ServiceReplacementOptions roption = DontAllowReplacement
argument_list|)
block|;
name|QDBusReply
operator|<
name|uint
operator|>
name|servicePid
argument_list|(
argument|const QString&serviceName
argument_list|)
specifier|const
block|;
name|QDBusReply
operator|<
name|uint
operator|>
name|serviceUid
argument_list|(
argument|const QString&serviceName
argument_list|)
specifier|const
block|;
name|QDBusReply
operator|<
name|void
operator|>
name|startService
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|serviceRegistered
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|)
block|;
name|void
name|serviceUnregistered
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|)
block|;
name|void
name|serviceOwnerChanged
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
block|;
name|void
name|callWithCallbackFailed
argument_list|(
specifier|const
name|QDBusError
operator|&
name|error
argument_list|,
specifier|const
name|QDBusMessage
operator|&
name|call
argument_list|)
block|;
ifndef|#
directive|ifndef
name|Q_QDOC
comment|// internal signals
comment|// do not use
name|void
name|NameAcquired
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|NameLost
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|NameOwnerChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|protected
operator|:
name|void
name|connectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
argument_list|)
block|;
name|void
name|disconnectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
argument_list|)
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|UInt
argument_list|,
name|QMetaType
operator|::
name|UInt
argument_list|,
name|QDBusConnectionInterface
operator|::
name|RegisterServiceReply
argument_list|)
end_decl_stmt
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
