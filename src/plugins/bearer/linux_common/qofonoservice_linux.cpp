begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"qofonoservice_linux_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
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
name|ObjectPathProperties
modifier|&
name|item
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|item
operator|.
name|path
operator|<<
name|item
operator|.
name|properties
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
name|ObjectPathProperties
modifier|&
name|item
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|item
operator|.
name|path
operator|>>
name|item
operator|.
name|properties
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
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QOfonoManagerInterface
name|QOfonoManagerInterface
operator|::
name|QOfonoManagerInterface
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
name|OFONO_SERVICE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|OFONO_MANAGER_PATH
argument_list|)
argument_list|,
name|OFONO_MANAGER_INTERFACE
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
name|ObjectPathProperties
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|PathPropertiesList
argument_list|>
argument_list|()
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
name|OFONO_SERVICE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|OFONO_MANAGER_PATH
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|OFONO_MANAGER_INTERFACE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"ModemAdded"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|modemAdded
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
name|OFONO_SERVICE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|OFONO_MANAGER_PATH
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|OFONO_MANAGER_INTERFACE
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"ModemRemoved"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|modemRemoved
argument_list|(
name|QDBusObjectPath
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QOfonoManagerInterface
name|QOfonoManagerInterface
operator|::
name|~
name|QOfonoManagerInterface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|getModems
name|QStringList
name|QOfonoManagerInterface
operator|::
name|getModems
parameter_list|()
block|{
if|if
condition|(
name|modemList
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QList
argument_list|<
name|QVariant
argument_list|>
name|argumentList
decl_stmt|;
name|QDBusPendingReply
argument_list|<
name|PathPropertiesList
argument_list|>
name|reply
init|=
name|callWithArgumentList
argument_list|(
name|QDBus
operator|::
name|Block
argument_list|,
name|QLatin1String
argument_list|(
literal|"GetModems"
argument_list|)
argument_list|,
name|argumentList
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
foreach|foreach
control|(
name|ObjectPathProperties
name|modem
decl|,
name|reply
operator|.
name|value
argument_list|()
control|)
block|{
name|modemList
operator|<<
name|modem
operator|.
name|path
operator|.
name|path
argument_list|()
expr_stmt|;
block|}
block|}
block|}
return|return
name|modemList
return|;
block|}
end_function
begin_function
DECL|function|currentModem
name|QString
name|QOfonoManagerInterface
operator|::
name|currentModem
parameter_list|()
block|{
name|QStringList
name|modems
init|=
name|getModems
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|modem
decl|,
name|modems
control|)
block|{
name|QOfonoModemInterface
name|device
argument_list|(
name|modem
argument_list|)
decl_stmt|;
if|if
condition|(
name|device
operator|.
name|isPowered
argument_list|()
operator|&&
name|device
operator|.
name|isOnline
argument_list|()
operator|&&
name|device
operator|.
name|interfaces
argument_list|()
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"org.ofono.NetworkRegistration"
argument_list|)
argument_list|)
condition|)
return|return
name|modem
return|;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|modemAdded
name|void
name|QOfonoManagerInterface
operator|::
name|modemAdded
parameter_list|(
specifier|const
name|QDBusObjectPath
modifier|&
name|path
parameter_list|,
specifier|const
name|QVariantMap
modifier|&
comment|/*var*/
parameter_list|)
block|{
if|if
condition|(
operator|!
name|modemList
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
name|modemList
operator|<<
name|path
operator|.
name|path
argument_list|()
expr_stmt|;
name|Q_EMIT
name|modemChanged
argument_list|()
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|modemRemoved
name|void
name|QOfonoManagerInterface
operator|::
name|modemRemoved
parameter_list|(
specifier|const
name|QDBusObjectPath
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|modemList
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
name|modemList
operator|.
name|removeOne
argument_list|(
name|path
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
name|Q_EMIT
name|modemChanged
argument_list|()
decl_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|QOfonoModemInterface
name|QOfonoModemInterface
operator|::
name|QOfonoModemInterface
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
name|OFONO_SERVICE
argument_list|)
argument_list|,
name|dbusPathName
argument_list|,
name|OFONO_MODEM_INTERFACE
argument_list|,
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
argument_list|,
name|parent
argument_list|)
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
name|OFONO_SERVICE
argument_list|)
argument_list|,
name|path
argument_list|()
argument_list|,
name|OFONO_MODEM_INTERFACE
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
end_constructor
begin_destructor
DECL|function|~QOfonoModemInterface
name|QOfonoModemInterface
operator|::
name|~
name|QOfonoModemInterface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|propertyChanged
name|void
name|QOfonoModemInterface
operator|::
name|propertyChanged
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
name|propertiesMap
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
DECL|function|isPowered
name|bool
name|QOfonoModemInterface
operator|::
name|isPowered
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Powered"
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
DECL|function|isOnline
name|bool
name|QOfonoModemInterface
operator|::
name|isOnline
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Online"
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
DECL|function|interfaces
name|QStringList
name|QOfonoModemInterface
operator|::
name|interfaces
parameter_list|()
block|{
specifier|const
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Interfaces"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|var
operator|.
name|toStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|getProperties
name|QVariantMap
name|QOfonoModemInterface
operator|::
name|getProperties
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
name|reply
init|=
name|callWithArgumentList
argument_list|(
name|QDBus
operator|::
name|Block
argument_list|,
name|QLatin1String
argument_list|(
literal|"GetProperties"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|propertiesMap
operator|=
name|reply
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|propertiesMap
return|;
block|}
end_function
begin_function
DECL|function|getProperty
name|QVariant
name|QOfonoModemInterface
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
if|if
condition|(
name|map
operator|.
name|contains
argument_list|(
name|property
argument_list|)
condition|)
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
begin_constructor
DECL|function|QOfonoNetworkRegistrationInterface
name|QOfonoNetworkRegistrationInterface
operator|::
name|QOfonoNetworkRegistrationInterface
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
name|OFONO_SERVICE
argument_list|)
argument_list|,
name|dbusPathName
argument_list|,
name|OFONO_NETWORK_REGISTRATION_INTERFACE
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
DECL|function|~QOfonoNetworkRegistrationInterface
name|QOfonoNetworkRegistrationInterface
operator|::
name|~
name|QOfonoNetworkRegistrationInterface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|getTechnology
name|QString
name|QOfonoNetworkRegistrationInterface
operator|::
name|getTechnology
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Technology"
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
DECL|function|getProperty
name|QVariant
name|QOfonoNetworkRegistrationInterface
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
if|if
condition|(
name|map
operator|.
name|contains
argument_list|(
name|property
argument_list|)
condition|)
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
DECL|function|getProperties
name|QVariantMap
name|QOfonoNetworkRegistrationInterface
operator|::
name|getProperties
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
name|reply
init|=
name|callWithArgumentList
argument_list|(
name|QDBus
operator|::
name|Block
argument_list|,
name|QLatin1String
argument_list|(
literal|"GetProperties"
argument_list|)
argument_list|,
name|argumentList
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
name|propertiesMap
operator|=
name|reply
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|propertiesMap
return|;
block|}
end_function
begin_constructor
DECL|function|QOfonoDataConnectionManagerInterface
name|QOfonoDataConnectionManagerInterface
operator|::
name|QOfonoDataConnectionManagerInterface
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
name|OFONO_SERVICE
argument_list|)
argument_list|,
name|dbusPathName
argument_list|,
name|OFONO_DATA_CONNECTION_MANAGER_INTERFACE
argument_list|,
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
argument_list|,
name|parent
argument_list|)
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
name|OFONO_SERVICE
argument_list|)
argument_list|,
name|path
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
name|OFONO_MODEM_INTERFACE
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
end_constructor
begin_destructor
DECL|function|~QOfonoDataConnectionManagerInterface
name|QOfonoDataConnectionManagerInterface
operator|::
name|~
name|QOfonoDataConnectionManagerInterface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|contexts
name|QStringList
name|QOfonoDataConnectionManagerInterface
operator|::
name|contexts
parameter_list|()
block|{
if|if
condition|(
name|contextList
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDBusPendingReply
argument_list|<
name|PathPropertiesList
argument_list|>
name|reply
init|=
name|call
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetContexts"
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
foreach|foreach
control|(
name|ObjectPathProperties
name|context
decl|,
name|reply
operator|.
name|value
argument_list|()
control|)
block|{
name|contextList
operator|<<
name|context
operator|.
name|path
operator|.
name|path
argument_list|()
expr_stmt|;
block|}
block|}
block|}
return|return
name|contextList
return|;
block|}
end_function
begin_function
DECL|function|contextsWithProperties
name|PathPropertiesList
name|QOfonoDataConnectionManagerInterface
operator|::
name|contextsWithProperties
parameter_list|()
block|{
if|if
condition|(
name|contextListProperties
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDBusPendingReply
argument_list|<
name|PathPropertiesList
argument_list|>
name|reply
init|=
name|call
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetContexts"
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
name|contextListProperties
operator|=
name|reply
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|contextListProperties
return|;
block|}
end_function
begin_function
DECL|function|roamingAllowed
name|bool
name|QOfonoDataConnectionManagerInterface
operator|::
name|roamingAllowed
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"RoamingAllowed"
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
DECL|function|bearer
name|QString
name|QOfonoDataConnectionManagerInterface
operator|::
name|bearer
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Bearer"
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
DECL|function|getProperty
name|QVariant
name|QOfonoDataConnectionManagerInterface
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
if|if
condition|(
name|map
operator|.
name|contains
argument_list|(
name|property
argument_list|)
condition|)
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
DECL|function|getProperties
name|QVariantMap
name|QOfonoDataConnectionManagerInterface
operator|::
name|getProperties
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
name|reply
init|=
name|callWithArgumentList
argument_list|(
name|QDBus
operator|::
name|Block
argument_list|,
name|QLatin1String
argument_list|(
literal|"GetProperties"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|propertiesMap
operator|=
name|reply
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|propertiesMap
return|;
block|}
end_function
begin_function
DECL|function|propertyChanged
name|void
name|QOfonoDataConnectionManagerInterface
operator|::
name|propertyChanged
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
name|propertiesMap
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
literal|"RoamingAllowed"
argument_list|)
condition|)
name|Q_EMIT
name|roamingAllowedChanged
argument_list|(
name|value
operator|.
name|variant
argument_list|()
operator|.
name|toBool
argument_list|()
argument_list|)
decl_stmt|;
block|}
end_function
begin_constructor
DECL|function|QOfonoConnectionContextInterface
name|QOfonoConnectionContextInterface
operator|::
name|QOfonoConnectionContextInterface
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
name|OFONO_SERVICE
argument_list|)
argument_list|,
name|dbusPathName
argument_list|,
name|OFONO_CONNECTION_CONTEXT_INTERFACE
argument_list|,
name|QDBusConnection
operator|::
name|systemBus
argument_list|()
argument_list|,
name|parent
argument_list|)
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
name|OFONO_SERVICE
argument_list|)
argument_list|,
name|path
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
name|OFONO_MODEM_INTERFACE
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
end_constructor
begin_destructor
DECL|function|~QOfonoConnectionContextInterface
name|QOfonoConnectionContextInterface
operator|::
name|~
name|QOfonoConnectionContextInterface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|getProperties
name|QVariantMap
name|QOfonoConnectionContextInterface
operator|::
name|getProperties
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
name|reply
init|=
name|callWithArgumentList
argument_list|(
name|QDBus
operator|::
name|Block
argument_list|,
name|QLatin1String
argument_list|(
literal|"GetProperties"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
operator|.
name|isError
argument_list|()
condition|)
block|{
name|propertiesMap
operator|=
name|reply
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|propertiesMap
return|;
block|}
end_function
begin_function
DECL|function|propertyChanged
name|void
name|QOfonoConnectionContextInterface
operator|::
name|propertyChanged
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
name|propertiesMap
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
DECL|function|getProperty
name|QVariant
name|QOfonoConnectionContextInterface
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
if|if
condition|(
name|map
operator|.
name|contains
argument_list|(
name|property
argument_list|)
condition|)
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
DECL|function|active
name|bool
name|QOfonoConnectionContextInterface
operator|::
name|active
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Active"
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
DECL|function|accessPointName
name|QString
name|QOfonoConnectionContextInterface
operator|::
name|accessPointName
parameter_list|()
block|{
name|QVariant
name|var
init|=
name|getProperty
argument_list|(
name|QStringLiteral
argument_list|(
literal|"AccessPointName"
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
name|QOfonoConnectionContextInterface
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
begin_comment
comment|// QT_NO_BEARERMANAGEMENT
end_comment
end_unit
