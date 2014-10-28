begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOFONOSERVICE_H
end_ifndef
begin_define
DECL|macro|QOFONOSERVICE_H
define|#
directive|define
name|QOFONOSERVICE_H
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
file|<QtDBus/QDBusContext>
end_include
begin_include
include|#
directive|include
file|<QMap>
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
begin_define
DECL|macro|OFONO_SERVICE
define|#
directive|define
name|OFONO_SERVICE
value|"org.ofono"
end_define
begin_define
DECL|macro|OFONO_MANAGER_INTERFACE
define|#
directive|define
name|OFONO_MANAGER_INTERFACE
value|"org.ofono.Manager"
end_define
begin_define
DECL|macro|OFONO_MANAGER_PATH
define|#
directive|define
name|OFONO_MANAGER_PATH
value|"/"
end_define
begin_define
DECL|macro|OFONO_MODEM_INTERFACE
define|#
directive|define
name|OFONO_MODEM_INTERFACE
value|"org.ofono.Modem"
end_define
begin_define
DECL|macro|OFONO_NETWORK_REGISTRATION_INTERFACE
define|#
directive|define
name|OFONO_NETWORK_REGISTRATION_INTERFACE
value|"org.ofono.NetworkRegistration"
end_define
begin_define
DECL|macro|OFONO_DATA_CONNECTION_MANAGER_INTERFACE
define|#
directive|define
name|OFONO_DATA_CONNECTION_MANAGER_INTERFACE
value|"org.ofono.ConnectionManager"
end_define
begin_define
DECL|macro|OFONO_CONNECTION_CONTEXT_INTERFACE
define|#
directive|define
name|OFONO_CONNECTION_CONTEXT_INTERFACE
value|"org.ofono.ConnectionContext"
end_define
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|QT_END_NAMESPACE
expr|struct
DECL|struct|ObjectPathProperties
name|ObjectPathProperties
block|{
DECL|member|path
name|QDBusObjectPath
name|path
block|;
DECL|member|properties
name|QVariantMap
name|properties
block|; }
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|PathPropertiesList
typedef|typedef
name|QList
operator|<
name|ObjectPathProperties
operator|>
name|PathPropertiesList
expr_stmt|;
end_typedef
begin_macro
DECL|function|Q_DECLARE_METATYPE
name|Q_DECLARE_METATYPE
argument_list|(
argument|ObjectPathProperties
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|PathPropertiesList
argument_list|)
end_macro
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QOfonoManagerInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QOfonoManagerInterface
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOfonoManagerInterface
argument_list|()
block|;
name|QStringList
name|getModems
argument_list|()
block|;
name|QString
name|currentModem
argument_list|()
block|;
name|signals
operator|:
name|void
name|modemChanged
argument_list|()
block|;
name|private
operator|:
name|QStringList
name|modemList
block|;
name|private
name|slots
operator|:
name|void
name|modemAdded
argument_list|(
specifier|const
name|QDBusObjectPath
operator|&
name|path
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|var
argument_list|)
block|;
name|void
name|modemRemoved
argument_list|(
specifier|const
name|QDBusObjectPath
operator|&
name|path
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOfonoModemInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QOfonoModemInterface
argument_list|(
specifier|const
name|QString
operator|&
name|dbusModemPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOfonoModemInterface
argument_list|()
block|;
name|bool
name|isPowered
argument_list|()
block|;
name|bool
name|isOnline
argument_list|()
block|;
name|QStringList
name|interfaces
argument_list|()
block|;
name|private
operator|:
name|QVariantMap
name|getProperties
argument_list|()
block|;
name|QVariantMap
name|propertiesMap
block|;
name|QVariant
name|getProperty
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|propertyChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
name|value
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOfonoNetworkRegistrationInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QOfonoNetworkRegistrationInterface
argument_list|(
specifier|const
name|QString
operator|&
name|dbusModemPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOfonoNetworkRegistrationInterface
argument_list|()
block|;
name|QString
name|getTechnology
argument_list|()
block|;
name|private
operator|:
name|QVariantMap
name|getProperties
argument_list|()
block|;
name|QVariant
name|getProperty
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|QVariantMap
name|propertiesMap
block|;
name|Q_SIGNALS
operator|:
name|void
name|propertyChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
name|value
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOfonoDataConnectionManagerInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QOfonoDataConnectionManagerInterface
argument_list|(
specifier|const
name|QString
operator|&
name|dbusPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOfonoDataConnectionManagerInterface
argument_list|()
block|;
name|QStringList
name|contexts
argument_list|()
block|;
name|PathPropertiesList
name|contextsWithProperties
argument_list|()
block|;
name|bool
name|roamingAllowed
argument_list|()
block|;
name|QVariant
name|getProperty
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|QString
name|bearer
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|roamingAllowedChanged
argument_list|(
name|bool
argument_list|)
block|;
name|private
operator|:
name|QVariantMap
operator|&
name|getProperties
argument_list|()
block|;
name|QVariantMap
name|propertiesMap
block|;
name|QStringList
name|contextList
block|;
name|PathPropertiesList
name|contextListProperties
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|propertyChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
name|value
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOfonoConnectionContextInterface
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QOfonoConnectionContextInterface
argument_list|(
specifier|const
name|QString
operator|&
name|dbusPathName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOfonoConnectionContextInterface
argument_list|()
block|;
name|QVariant
name|getProperty
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|bool
name|active
argument_list|()
block|;
name|QString
name|accessPointName
argument_list|()
block|;
name|QString
name|name
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|private
operator|:
name|QVariantMap
name|getProperties
argument_list|()
block|;
name|QVariantMap
name|propertiesMap
block|;
name|private
name|slots
operator|:
name|void
name|propertyChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QDBusVariant
operator|&
name|value
argument_list|)
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
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BEARERMANAGEMENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QOFONOSERVICE_H
end_comment
end_unit