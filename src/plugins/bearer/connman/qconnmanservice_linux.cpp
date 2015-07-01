begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusConnection>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusError>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusInterface>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusMessage>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusReply>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusPendingCallWatcher>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusObjectPath>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusPendingCall>
end_include
begin_include
include|#
directive|include
file|"qconnmanservice_linux_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|ConnmanMap
modifier|&
name|map
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|map
operator|.
name|objectPath
operator|<<
name|map
operator|.
name|propertyMap
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|ConnmanMap
modifier|&
name|map
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|map
operator|.
name|objectPath
operator|>>
name|map
operator|.
name|propertyMap
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_constructor
DECL|function|QConnmanManagerInterface
name|QConnmanManagerInterface
operator|::
name|QConnmanManagerInterface
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDBusAbstractInterface
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_MANAGER_PATH
argument_list|)
argument_list|,
name|CONNMAN_MANAGER_INTERFACE
argument_list|,
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{
name|qDBusRegisterMetaType
argument_list|<
name|ConnmanMap
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|ConnmanMapList
argument_list|>
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|argumentList
decl_stmt|;
name|QDBusPendingReply
argument_list|<
name|QVariantMap
argument_list|>
name|props_reply
init|=
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetProperties"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
decl_stmt|;
name|QDBusPendingCallWatcher
modifier|*
name|watcher
init|=
operator|new
name|QDBusPendingCallWatcher
argument_list|(
name|props_reply
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|propertiesReply
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
operator|.
name|connect
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_MANAGER_PATH
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE_INTERFACE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"PropertyChanged"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changedProperty
argument_list|(
name|QString
argument_list|,
name|QDBusVariant
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
operator|.
name|connect
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_MANAGER_PATH
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE_INTERFACE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"TechnologyAdded"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|technologyAdded
argument_list|(
name|QDBusObjectPath
argument_list|,
name|QVariantMap
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
operator|.
name|connect
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_MANAGER_PATH
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE_INTERFACE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"TechnologyRemoved"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|technologyRemoved
argument_list|(
name|QDBusObjectPath
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|argumentList2
decl_stmt|;
name|QDBusPendingReply
argument_list|<
name|ConnmanMapList
argument_list|>
name|serv_reply
init|=
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetServices"
argument_list|)
argument_list|,
name|argumentList2
argument_list|)
decl_stmt|;
name|QDBusPendingCallWatcher
modifier|*
name|watcher2
init|=
operator|new
name|QDBusPendingCallWatcher
argument_list|(
name|serv_reply
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|watcher2
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|servicesReply
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QConnmanManagerInterface
name|QConnmanManagerInterface
operator|::
name|~
name|QConnmanManagerInterface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|changedProperty
name|void
name|QConnmanManagerInterface
operator|::
name|changedProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QDBusVariant
modifier|&
name|value
parameter_list|)
block|{
name|propertiesCacheMap
index|[
name|name
index|]
operator|=
name|value
operator|.
name|variant
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|propertiesReply
name|void
name|QConnmanManagerInterface
operator|::
name|propertiesReply
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|call
parameter_list|)
block|{
name|QDBusPendingReply
argument_list|<
name|QVariantMap
argument_list|>
name|props_reply
init|=
operator|*
name|call
decl_stmt|;
if|if
condition|(
name|props_reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
name|props_reply
operator|.
name|error
argument_list|()
operator|.
name|message
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|propertiesCacheMap
operator|=
name|props_reply
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
name|call
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|servicesReply
name|void
name|QConnmanManagerInterface
operator|::
name|servicesReply
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|call
parameter_list|)
block|{
name|QDBusPendingReply
argument_list|<
name|ConnmanMapList
argument_list|>
name|serv_reply
init|=
operator|*
name|call
decl_stmt|;
if|if
condition|(
name|serv_reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
name|serv_reply
operator|.
name|error
argument_list|()
operator|.
name|message
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|servicesList
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//connman list changes order
name|ConnmanMap
name|connmanobj
decl_stmt|;
name|Q_FOREACH
argument_list|(
argument|connmanobj
argument_list|,
argument|serv_reply.value()
argument_list|)
block|{
name|servicesList
operator|<<
name|connmanobj
operator|.
name|objectPath
operator|.
name|path
argument_list|()
expr_stmt|;
block|}
name|Q_EMIT
name|servicesReady
argument_list|(
name|servicesList
argument_list|)
decl_stmt|;
block|}
name|call
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connectNotify
name|void
name|QConnmanManagerInterface
operator|::
name|connectNotify
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|signal
parameter_list|)
block|{
specifier|static
specifier|const
name|QMetaMethod
name|propertyChangedSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QConnmanManagerInterface
operator|::
name|propertyChanged
argument_list|)
decl_stmt|;
if|if
condition|(
name|signal
operator|==
name|propertyChangedSignal
condition|)
block|{
if|if
condition|(
operator|!
name|connection
argument_list|()
operator|.
name|connect
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_MANAGER_PATH
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_MANAGER_INTERFACE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"PropertyChanged"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|propertyChanged
argument_list|(
name|QString
argument_list|,
name|QDBusVariant
argument_list|)
argument_list|)
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"PropertyChanged not connected"
expr_stmt|;
block|}
block|}
specifier|static
specifier|const
name|QMetaMethod
name|servicesChangedSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QConnmanManagerInterface
operator|::
name|servicesChanged
argument_list|)
decl_stmt|;
if|if
condition|(
name|signal
operator|==
name|servicesChangedSignal
condition|)
block|{
if|if
condition|(
operator|!
name|connection
argument_list|()
operator|.
name|connect
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_MANAGER_PATH
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_MANAGER_INTERFACE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"ServicesChanged"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onServicesChanged
argument_list|(
name|ConnmanMapList
argument_list|,
name|QList
argument_list|<
name|QDBusObjectPath
argument_list|>
argument_list|)
argument_list|)
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"servicesChanged not connected"
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|onServicesChanged
name|void
name|QConnmanManagerInterface
operator|::
name|onServicesChanged
parameter_list|(
specifier|const
name|ConnmanMapList
modifier|&
name|changed
parameter_list|,
specifier|const
name|QList
argument_list|<
name|QDBusObjectPath
argument_list|>
modifier|&
name|removed
parameter_list|)
block|{
name|servicesList
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//connman list changes order
name|Q_FOREACH
argument_list|(
argument|const ConnmanMap&connmanobj
argument_list|,
argument|changed
argument_list|)
block|{
specifier|const
name|QString
name|svcPath
argument_list|(
name|connmanobj
operator|.
name|objectPath
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|servicesList
operator|<<
name|svcPath
expr_stmt|;
block|}
name|Q_EMIT
name|servicesChanged
argument_list|(
name|changed
argument_list|,
name|removed
argument_list|)
decl_stmt|;
block|}
end_function
begin_function
DECL|function|getProperty
name|QVariant
name|QConnmanManagerInterface
operator|::
name|getProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|property
parameter_list|)
block|{
name|QVariant
name|var
decl_stmt|;
name|var
operator|=
name|propertiesCacheMap
operator|.
name|value
argument_list|(
name|property
argument_list|)
expr_stmt|;
return|return
name|var
return|;
block|}
end_function
begin_function
DECL|function|getProperties
name|QVariantMap
name|QConnmanManagerInterface
operator|::
name|getProperties
parameter_list|()
block|{
if|if
condition|(
name|propertiesCacheMap
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDBusPendingReply
argument_list|<
name|QVariantMap
argument_list|>
name|reply
init|=
name|call
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetProperties"
argument_list|)
argument_list|)
decl_stmt|;
name|reply
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|propertiesCacheMap
operator|=
name|reply
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|propertiesCacheMap
return|;
block|}
end_function
begin_function
DECL|function|getState
name|QString
name|QConnmanManagerInterface
operator|::
name|getState
parameter_list|()
block|{
return|return
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"State"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|getOfflineMode
name|bool
name|QConnmanManagerInterface
operator|::
name|getOfflineMode
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"OfflineMode"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|bool
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|getTechnologies
name|QStringList
name|QConnmanManagerInterface
operator|::
name|getTechnologies
parameter_list|()
block|{
if|if
condition|(
name|technologiesMap
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDBusPendingReply
argument_list|<
name|ConnmanMapList
argument_list|>
name|reply
init|=
name|call
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetTechnologies"
argument_list|)
argument_list|)
decl_stmt|;
name|reply
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|Q_FOREACH
argument_list|(
argument|const ConnmanMap&map
argument_list|,
argument|reply.value()
argument_list|)
block|{
if|if
condition|(
operator|!
name|technologiesMap
operator|.
name|contains
argument_list|(
name|map
operator|.
name|objectPath
operator|.
name|path
argument_list|()
argument_list|)
condition|)
block|{
name|technologyAdded
argument_list|(
name|map
operator|.
name|objectPath
argument_list|,
name|map
operator|.
name|propertyMap
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
return|return
name|technologiesMap
operator|.
name|keys
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|getServices
name|QStringList
name|QConnmanManagerInterface
operator|::
name|getServices
parameter_list|()
block|{
if|if
condition|(
name|servicesList
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDBusPendingReply
argument_list|<
name|ConnmanMapList
argument_list|>
name|reply
init|=
name|call
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetServices"
argument_list|)
argument_list|)
decl_stmt|;
name|reply
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|Q_FOREACH
argument_list|(
argument|const ConnmanMap&map
argument_list|,
argument|reply.value()
argument_list|)
block|{
name|servicesList
operator|<<
name|map
operator|.
name|objectPath
operator|.
name|path
argument_list|()
expr_stmt|;
block|}
block|}
block|}
return|return
name|servicesList
return|;
block|}
end_function
begin_function
DECL|function|requestScan
name|void
name|QConnmanManagerInterface
operator|::
name|requestScan
parameter_list|(
specifier|const
name|QString
modifier|&
name|type
parameter_list|)
block|{
name|Q_FOREACH
argument_list|(
argument|QConnmanTechnologyInterface *tech
argument_list|,
argument|technologiesMap
argument_list|)
block|{
if|if
condition|(
name|tech
operator|->
name|type
argument_list|()
operator|==
name|type
condition|)
block|{
name|tech
operator|->
name|scan
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|technologyAdded
name|void
name|QConnmanManagerInterface
operator|::
name|technologyAdded
parameter_list|(
specifier|const
name|QDBusObjectPath
modifier|&
name|path
parameter_list|,
specifier|const
name|QVariantMap
modifier|&
parameter_list|)
block|{
if|if
condition|(
operator|!
name|technologiesList
operator|.
name|contains
argument_list|(
name|path
operator|.
name|path
argument_list|()
argument_list|)
condition|)
block|{
name|technologiesList
operator|<<
name|path
operator|.
name|path
argument_list|()
expr_stmt|;
name|QConnmanTechnologyInterface
modifier|*
name|tech
decl_stmt|;
name|tech
operator|=
operator|new
name|QConnmanTechnologyInterface
argument_list|(
name|path
operator|.
name|path
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|technologiesMap
operator|.
name|insert
argument_list|(
name|path
operator|.
name|path
argument_list|()
argument_list|,
name|tech
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|tech
argument_list|,
name|SIGNAL
argument_list|(
name|scanFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|scanFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|technologyRemoved
name|void
name|QConnmanManagerInterface
operator|::
name|technologyRemoved
parameter_list|(
specifier|const
name|QDBusObjectPath
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|technologiesList
operator|.
name|contains
argument_list|(
name|path
operator|.
name|path
argument_list|()
argument_list|)
condition|)
block|{
name|technologiesList
operator|.
name|removeOne
argument_list|(
name|path
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
name|QConnmanTechnologyInterface
modifier|*
name|tech
init|=
name|technologiesMap
operator|.
name|take
argument_list|(
name|path
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
operator|delete
name|tech
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|QConnmanServiceInterface
name|QConnmanServiceInterface
operator|::
name|QConnmanServiceInterface
parameter_list|(
specifier|const
name|QString
modifier|&
name|dbusPathName
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDBusAbstractInterface
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|dbusPathName
argument_list|,
name|CONNMAN_SERVICE_INTERFACE
argument_list|,
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{
name|QList
argument_list|<
name|QVariant
argument_list|>
name|argumentList
decl_stmt|;
name|QDBusPendingReply
argument_list|<
name|QVariantMap
argument_list|>
name|props_reply
init|=
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetProperties"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
decl_stmt|;
name|QDBusPendingCallWatcher
modifier|*
name|watcher
init|=
operator|new
name|QDBusPendingCallWatcher
argument_list|(
name|props_reply
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|propertiesReply
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
operator|.
name|connect
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|path
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE_INTERFACE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"PropertyChanged"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|changedProperty
argument_list|(
name|QString
argument_list|,
name|QDBusVariant
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QConnmanServiceInterface
name|QConnmanServiceInterface
operator|::
name|~
name|QConnmanServiceInterface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|getProperties
name|QVariantMap
name|QConnmanServiceInterface
operator|::
name|getProperties
parameter_list|()
block|{
if|if
condition|(
name|propertiesCacheMap
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDBusPendingReply
argument_list|<
name|QVariantMap
argument_list|>
name|reply
init|=
name|call
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetProperties"
argument_list|)
argument_list|)
decl_stmt|;
name|reply
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|propertiesCacheMap
operator|=
name|reply
operator|.
name|value
argument_list|()
expr_stmt|;
name|Q_EMIT
name|propertiesReady
argument_list|()
decl_stmt|;
block|}
block|}
return|return
name|propertiesCacheMap
return|;
block|}
end_function
begin_function
DECL|function|propertiesReply
name|void
name|QConnmanServiceInterface
operator|::
name|propertiesReply
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|call
parameter_list|)
block|{
name|QDBusPendingReply
argument_list|<
name|QVariantMap
argument_list|>
name|props_reply
init|=
operator|*
name|call
decl_stmt|;
if|if
condition|(
name|props_reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
name|props_reply
operator|.
name|error
argument_list|()
operator|.
name|message
argument_list|()
expr_stmt|;
return|return;
block|}
name|propertiesCacheMap
operator|=
name|props_reply
operator|.
name|value
argument_list|()
expr_stmt|;
name|Q_EMIT
name|propertiesReady
argument_list|()
decl_stmt|;
block|}
end_function
begin_function
DECL|function|connectNotify
name|void
name|QConnmanServiceInterface
operator|::
name|connectNotify
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|signal
parameter_list|)
block|{
specifier|static
specifier|const
name|QMetaMethod
name|propertyChangedSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QConnmanServiceInterface
operator|::
name|propertyChanged
argument_list|)
decl_stmt|;
if|if
condition|(
name|signal
operator|==
name|propertyChangedSignal
condition|)
block|{
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
operator|.
name|connect
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|path
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE_INTERFACE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"PropertyChanged"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|propertyChanged
argument_list|(
name|QString
argument_list|,
name|QDBusVariant
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|changedProperty
name|void
name|QConnmanServiceInterface
operator|::
name|changedProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QDBusVariant
modifier|&
name|value
parameter_list|)
block|{
name|propertiesCacheMap
index|[
name|name
index|]
operator|=
name|value
operator|.
name|variant
argument_list|()
expr_stmt|;
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"State"
argument_list|)
condition|)
name|Q_EMIT
name|stateChanged
argument_list|(
name|value
operator|.
name|variant
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
block|}
end_function
begin_function
DECL|function|getProperty
name|QVariant
name|QConnmanServiceInterface
operator|::
name|getProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|property
parameter_list|)
block|{
name|QVariant
name|var
decl_stmt|;
name|QVariantMap
name|map
init|=
name|getProperties
argument_list|()
decl_stmt|;
name|var
operator|=
name|map
operator|.
name|value
argument_list|(
name|property
argument_list|)
expr_stmt|;
return|return
name|var
return|;
block|}
end_function
begin_function
DECL|function|connect
name|void
name|QConnmanServiceInterface
operator|::
name|connect
parameter_list|()
block|{
name|asyncCall
argument_list|(
name|QLatin1String
argument_list|(
literal|"Connect"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|disconnect
name|void
name|QConnmanServiceInterface
operator|::
name|disconnect
parameter_list|()
block|{
name|asyncCall
argument_list|(
name|QLatin1String
argument_list|(
literal|"Disconnect"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|remove
name|void
name|QConnmanServiceInterface
operator|::
name|remove
parameter_list|()
block|{
name|asyncCall
argument_list|(
name|QLatin1String
argument_list|(
literal|"Remove"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// properties
end_comment
begin_function
DECL|function|state
name|QString
name|QConnmanServiceInterface
operator|::
name|state
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"State"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|lastError
name|QString
name|QConnmanServiceInterface
operator|::
name|lastError
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Error"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|name
name|QString
name|QConnmanServiceInterface
operator|::
name|name
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Name"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|type
name|QString
name|QConnmanServiceInterface
operator|::
name|type
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Type"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|security
name|QString
name|QConnmanServiceInterface
operator|::
name|security
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Security"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|favorite
name|bool
name|QConnmanServiceInterface
operator|::
name|favorite
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Favorite"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|bool
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|autoConnect
name|bool
name|QConnmanServiceInterface
operator|::
name|autoConnect
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"AutoConnect"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|bool
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|roaming
name|bool
name|QConnmanServiceInterface
operator|::
name|roaming
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Roaming"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|bool
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|ethernet
name|QVariantMap
name|QConnmanServiceInterface
operator|::
name|ethernet
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Ethernet"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|QVariantMap
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|serviceInterface
name|QString
name|QConnmanServiceInterface
operator|::
name|serviceInterface
parameter_list|()
block|{
name|QVariantMap
name|map
init|=
name|ethernet
argument_list|()
decl_stmt|;
return|return
name|map
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Interface"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isOfflineMode
name|bool
name|QConnmanServiceInterface
operator|::
name|isOfflineMode
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"OfflineMode"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|bool
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|services
name|QStringList
name|QConnmanServiceInterface
operator|::
name|services
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Services"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|QStringList
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//////////////////////////
end_comment
begin_constructor
DECL|function|QConnmanTechnologyInterface
name|QConnmanTechnologyInterface
operator|::
name|QConnmanTechnologyInterface
parameter_list|(
specifier|const
name|QString
modifier|&
name|dbusPathName
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDBusAbstractInterface
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|dbusPathName
argument_list|,
name|CONNMAN_TECHNOLOGY_INTERFACE
argument_list|,
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QConnmanTechnologyInterface
name|QConnmanTechnologyInterface
operator|::
name|~
name|QConnmanTechnologyInterface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|connectNotify
name|void
name|QConnmanTechnologyInterface
operator|::
name|connectNotify
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|signal
parameter_list|)
block|{
specifier|static
specifier|const
name|QMetaMethod
name|propertyChangedSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|QConnmanTechnologyInterface
operator|::
name|propertyChanged
argument_list|)
decl_stmt|;
if|if
condition|(
name|signal
operator|==
name|propertyChangedSignal
condition|)
block|{
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
operator|.
name|connect
argument_list|(
name|QLatin1String
argument_list|(
name|CONNMAN_SERVICE
argument_list|)
argument_list|,
name|path
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
name|CONNMAN_TECHNOLOGY_INTERFACE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"PropertyChanged"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|propertyChanged
argument_list|(
name|QString
argument_list|,
name|QDBusVariant
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|properties
name|QVariantMap
name|QConnmanTechnologyInterface
operator|::
name|properties
parameter_list|()
block|{
if|if
condition|(
name|propertiesMap
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDBusPendingReply
argument_list|<
name|QVariantMap
argument_list|>
name|reply
init|=
name|call
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetProperties"
argument_list|)
argument_list|)
decl_stmt|;
name|reply
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
name|propertiesMap
operator|=
name|reply
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
return|return
name|propertiesMap
return|;
block|}
end_function
begin_function
DECL|function|getProperty
name|QVariant
name|QConnmanTechnologyInterface
operator|::
name|getProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|property
parameter_list|)
block|{
name|QVariant
name|var
decl_stmt|;
name|QVariantMap
name|map
init|=
name|properties
argument_list|()
decl_stmt|;
name|var
operator|=
name|map
operator|.
name|value
argument_list|(
name|property
argument_list|)
expr_stmt|;
return|return
name|var
return|;
block|}
end_function
begin_function
DECL|function|type
name|QString
name|QConnmanTechnologyInterface
operator|::
name|type
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Type"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|qdbus_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|var
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|scan
name|void
name|QConnmanTechnologyInterface
operator|::
name|scan
parameter_list|()
block|{
name|QDBusPendingReply
argument_list|<>
name|reply
init|=
name|asyncCall
argument_list|(
name|QLatin1String
argument_list|(
literal|"Scan"
argument_list|)
argument_list|)
decl_stmt|;
name|QDBusPendingCallWatcher
modifier|*
name|watcher
init|=
operator|new
name|QDBusPendingCallWatcher
argument_list|(
name|reply
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|watcher
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|scanReply
argument_list|(
name|QDBusPendingCallWatcher
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scanReply
name|void
name|QConnmanTechnologyInterface
operator|::
name|scanReply
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|call
parameter_list|)
block|{
name|Q_EMIT
name|scanFinished
argument_list|()
decl_stmt|;
name|call
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
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
end_unit
