begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkconfigmanager_p.h"
end_include
begin_include
include|#
directive|include
file|"qbearerplugin_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfactoryloader_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtimer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qthread.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qthread_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|loader
argument_list|,
operator|(
name|QBearerEngineFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/bearer"
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
DECL|function|QNetworkConfigurationManagerPrivate
name|QNetworkConfigurationManagerPrivate
operator|::
name|QNetworkConfigurationManagerPrivate
argument_list|()
range|:
name|QObject
argument_list|()
decl_stmt|,
name|pollTimer
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|mutex
argument_list|(
name|QMutex
operator|::
name|Recursive
argument_list|)
decl_stmt|,
name|forcedPolling
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|firstUpdate
argument_list|(
literal|true
argument_list|)
argument_list|{
name|qRegisterMetaType
argument_list|<
name|QNetworkConfiguration
argument_list|>
argument_list|()
argument_list|;
name|qRegisterMetaType
argument_list|<
name|QNetworkConfigurationPrivatePointer
argument_list|>
argument_list|()
argument_list|; }
DECL|function|initialize
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|initialize
argument_list|()
argument_list|{
comment|//Two stage construction, because we only want to do this heavyweight work for the winner of the Q_GLOBAL_STATIC race.
name|bearerThread
operator|=
operator|new
name|QDaemonThread
argument_list|()
argument_list|;
name|bearerThread
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Qt bearer thread"
argument_list|)
argument_list|)
argument_list|;
name|bearerThread
operator|->
name|moveToThread
argument_list|(
name|QCoreApplicationPrivate
operator|::
name|mainThread
argument_list|()
argument_list|)
argument_list|;
comment|// because cleanup() is called in main thread context.
name|moveToThread
argument_list|(
name|bearerThread
argument_list|)
argument_list|;
name|bearerThread
operator|->
name|start
argument_list|()
argument_list|;
name|updateConfigurations
argument_list|()
argument_list|; }
DECL|function|~QNetworkConfigurationManagerPrivate
name|QNetworkConfigurationManagerPrivate
operator|::
name|~
name|QNetworkConfigurationManagerPrivate
argument_list|()
argument_list|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|;
name|qDeleteAll
argument_list|(
name|sessionEngines
argument_list|)
argument_list|;
name|sessionEngines
operator|.
name|clear
argument_list|()
argument_list|;     if
operator|(
name|bearerThread
operator|)
name|bearerThread
operator|->
name|quit
argument_list|()
argument_list|; }
DECL|function|cleanup
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|cleanup
argument_list|()
argument_list|{
name|QThread
operator|*
name|thread
operator|=
name|bearerThread
argument_list|;
name|deleteLater
argument_list|()
argument_list|;     if
operator|(
name|thread
operator|->
name|wait
argument_list|(
literal|5000
argument_list|)
operator|)
operator|delete
name|thread
argument_list|; }
DECL|function|defaultConfiguration
name|QNetworkConfiguration
name|QNetworkConfigurationManagerPrivate
operator|::
name|defaultConfiguration
argument_list|()
decl|const
argument_list|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
argument_list|;      foreach
operator|(
name|QBearerEngine
operator|*
name|engine
operator|,
name|sessionEngines
operator|)
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
operator|=
name|engine
operator|->
name|defaultConfiguration
argument_list|()
block|;
if|if
condition|(
name|ptr
condition|)
block|{
name|QNetworkConfiguration
name|config
block|;
name|config
operator|.
name|d
operator|=
name|ptr
expr_stmt|;
return|return
name|config
return|;
end_decl_stmt
begin_comment
unit|}     }
comment|// Engines don't have a default configuration.
end_comment
begin_comment
comment|// Return first active snap
end_comment
begin_decl_stmt
name|QNetworkConfigurationPrivatePointer
name|defaultConfiguration
decl_stmt|;
end_decl_stmt
begin_foreach
foreach|foreach
control|(
name|QBearerEngine
modifier|*
name|engine
decl|,
name|sessionEngines
control|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
operator|::
name|Iterator
name|it
decl_stmt|;
name|QHash
argument_list|<
name|QString
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
operator|::
name|Iterator
name|end
decl_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|engine
operator|->
name|mutex
argument_list|)
decl_stmt|;
for|for
control|(
name|it
operator|=
name|engine
operator|->
name|snapConfigurations
operator|.
name|begin
argument_list|()
operator|,
name|end
operator|=
name|engine
operator|->
name|snapConfigurations
operator|.
name|end
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|QMutexLocker
name|configLocker
argument_list|(
operator|&
name|ptr
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|QNetworkConfiguration
operator|::
name|Active
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Active
condition|)
block|{
name|QNetworkConfiguration
name|config
decl_stmt|;
name|config
operator|.
name|d
operator|=
name|ptr
expr_stmt|;
return|return
name|config
return|;
block|}
elseif|else
if|if
condition|(
operator|!
name|defaultConfiguration
condition|)
block|{
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Discovered
condition|)
name|defaultConfiguration
operator|=
name|ptr
expr_stmt|;
block|}
block|}
block|}
end_foreach
begin_comment
comment|// No Active SNAPs return first Discovered SNAP.
end_comment
begin_if
if|if
condition|(
name|defaultConfiguration
condition|)
block|{
name|QNetworkConfiguration
name|config
decl_stmt|;
name|config
operator|.
name|d
operator|=
name|defaultConfiguration
expr_stmt|;
return|return
name|config
return|;
block|}
end_if
begin_comment
comment|/*         No Active or Discovered SNAPs, find the perferred access point.         The following priority order is used:              1. Active Ethernet             2. Active WLAN             3. Active Other             4. Discovered Ethernet             5. Discovered WLAN             6. Discovered Other     */
end_comment
begin_foreach
foreach|foreach
control|(
name|QBearerEngine
modifier|*
name|engine
decl|,
name|sessionEngines
control|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
operator|::
name|Iterator
name|it
decl_stmt|;
name|QHash
argument_list|<
name|QString
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
operator|::
name|Iterator
name|end
decl_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|engine
operator|->
name|mutex
argument_list|)
decl_stmt|;
for|for
control|(
name|it
operator|=
name|engine
operator|->
name|accessPointConfigurations
operator|.
name|begin
argument_list|()
operator|,
name|end
operator|=
name|engine
operator|->
name|accessPointConfigurations
operator|.
name|end
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|QMutexLocker
name|configLocker
argument_list|(
operator|&
name|ptr
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|QNetworkConfiguration
operator|::
name|BearerType
name|bearerType
init|=
name|ptr
operator|->
name|bearerType
decl_stmt|;
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Discovered
condition|)
block|{
if|if
condition|(
operator|!
name|defaultConfiguration
condition|)
block|{
name|defaultConfiguration
operator|=
name|ptr
expr_stmt|;
block|}
else|else
block|{
name|QMutexLocker
name|defaultConfigLocker
argument_list|(
operator|&
name|defaultConfiguration
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|defaultConfiguration
operator|->
name|state
operator|==
name|ptr
operator|->
name|state
condition|)
block|{
switch|switch
condition|(
name|defaultConfiguration
operator|->
name|bearerType
condition|)
block|{
case|case
name|QNetworkConfiguration
operator|::
name|BearerEthernet
case|:
comment|// do nothing
break|break;
case|case
name|QNetworkConfiguration
operator|::
name|BearerWLAN
case|:
comment|// Ethernet beats WLAN
name|defaultConfiguration
operator|=
name|ptr
expr_stmt|;
break|break;
default|default:
comment|// Ethernet and WLAN beats other
if|if
condition|(
name|bearerType
operator|==
name|QNetworkConfiguration
operator|::
name|BearerEthernet
operator|||
name|bearerType
operator|==
name|QNetworkConfiguration
operator|::
name|BearerWLAN
condition|)
block|{
name|defaultConfiguration
operator|=
name|ptr
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|// active beats discovered
if|if
condition|(
operator|(
name|defaultConfiguration
operator|->
name|state
operator|&
name|QNetworkConfiguration
operator|::
name|Active
operator|)
operator|!=
name|QNetworkConfiguration
operator|::
name|Active
condition|)
block|{
name|defaultConfiguration
operator|=
name|ptr
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
block|}
end_foreach
begin_comment
comment|// No Active InternetAccessPoint return first Discovered InternetAccessPoint.
end_comment
begin_if
if|if
condition|(
name|defaultConfiguration
condition|)
block|{
name|QNetworkConfiguration
name|config
decl_stmt|;
name|config
operator|.
name|d
operator|=
name|defaultConfiguration
expr_stmt|;
return|return
name|config
return|;
block|}
end_if
begin_return
return|return
name|QNetworkConfiguration
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  QList
DECL|function|allConfigurations
operator|<
name|QNetworkConfiguration
operator|>
name|QNetworkConfigurationManagerPrivate
operator|::
name|allConfigurations
operator|(
name|QNetworkConfiguration
operator|::
name|StateFlags
name|filter
operator|)
specifier|const
block|{
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|result
block|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
block|;
foreach|foreach
control|(
name|QBearerEngine
modifier|*
name|engine
decl|,
name|sessionEngines
control|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
operator|::
name|Iterator
name|it
decl_stmt|;
name|QHash
argument_list|<
name|QString
argument_list|,
name|QNetworkConfigurationPrivatePointer
argument_list|>
operator|::
name|Iterator
name|end
decl_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|engine
operator|->
name|mutex
argument_list|)
decl_stmt|;
comment|//find all InternetAccessPoints
for|for
control|(
name|it
operator|=
name|engine
operator|->
name|accessPointConfigurations
operator|.
name|begin
argument_list|()
operator|,
name|end
operator|=
name|engine
operator|->
name|accessPointConfigurations
operator|.
name|end
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
name|QMutexLocker
name|configLocker
argument_list|(
operator|&
name|ptr
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|filter
operator|)
operator|==
name|filter
condition|)
block|{
name|QNetworkConfiguration
name|pt
decl_stmt|;
name|pt
operator|.
name|d
operator|=
name|ptr
expr_stmt|;
name|result
operator|<<
name|pt
expr_stmt|;
block|}
end_expr_stmt
begin_comment
unit|}
comment|//find all service networks
end_comment
begin_expr_stmt
unit|for
operator|(
name|it
operator|=
name|engine
operator|->
name|snapConfigurations
operator|.
name|begin
argument_list|()
operator|,
name|end
operator|=
name|engine
operator|->
name|snapConfigurations
operator|.
name|end
argument_list|()
expr|;
name|it
operator|!=
name|end
expr|;
operator|++
name|it
operator|)
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
operator|=
name|it
operator|.
name|value
argument_list|()
block|;
name|QMutexLocker
name|configLocker
argument_list|(
operator|&
name|ptr
operator|->
name|mutex
argument_list|)
block|;
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|filter
operator|)
operator|==
name|filter
condition|)
block|{
name|QNetworkConfiguration
name|pt
decl_stmt|;
name|pt
operator|.
name|d
operator|=
name|ptr
expr_stmt|;
name|result
operator|<<
name|pt
expr_stmt|;
block|}
end_expr_stmt
begin_return
unit|}     }
return|return
name|result
return|;
end_return
begin_macro
unit|}  QNetworkConfiguration
DECL|function|configurationFromIdentifier
name|QNetworkConfigurationManagerPrivate
end_macro
begin_expr_stmt
DECL|function|configurationFromIdentifier
operator|::
name|configurationFromIdentifier
operator|(
specifier|const
name|QString
operator|&
name|identifier
operator|)
specifier|const
block|{
name|QNetworkConfiguration
name|item
block|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
block|;
foreach|foreach
control|(
name|QBearerEngine
modifier|*
name|engine
decl|,
name|sessionEngines
control|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|engine
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|engine
operator|->
name|accessPointConfigurations
operator|.
name|contains
argument_list|(
name|identifier
argument_list|)
condition|)
name|item
operator|.
name|d
operator|=
name|engine
operator|->
name|accessPointConfigurations
index|[
name|identifier
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|engine
operator|->
name|snapConfigurations
operator|.
name|contains
argument_list|(
name|identifier
argument_list|)
condition|)
name|item
operator|.
name|d
operator|=
name|engine
operator|->
name|snapConfigurations
index|[
name|identifier
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|engine
operator|->
name|userChoiceConfigurations
operator|.
name|contains
argument_list|(
name|identifier
argument_list|)
condition|)
name|item
operator|.
name|d
operator|=
name|engine
operator|->
name|userChoiceConfigurations
index|[
name|identifier
index|]
expr_stmt|;
else|else
continue|continue;
return|return
name|item
return|;
block|}
end_expr_stmt
begin_return
return|return
name|item
return|;
end_return
begin_macro
unit|}  bool
DECL|function|isOnline
name|QNetworkConfigurationManagerPrivate
end_macro
begin_expr_stmt
DECL|function|isOnline
operator|::
name|isOnline
operator|(
operator|)
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
block|;
comment|// We need allConfigurations since onlineConfigurations is filled with queued connections
comment|// and thus is not always (more importantly just after creation) up to date
return|return
operator|!
name|allConfigurations
argument_list|(
name|QNetworkConfiguration
operator|::
name|Active
argument_list|)
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
DECL|function|capabilities
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|QNetworkConfigurationManagerPrivate
operator|::
name|capabilities
parameter_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|capFlags
decl_stmt|;
foreach|foreach
control|(
name|QBearerEngine
modifier|*
name|engine
decl|,
name|sessionEngines
control|)
name|capFlags
operator||=
name|engine
operator|->
name|capabilities
argument_list|()
expr_stmt|;
return|return
name|capFlags
return|;
block|}
end_function
begin_function
DECL|function|configurationAdded
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|configurationAdded
parameter_list|(
name|QNetworkConfigurationPrivatePointer
name|ptr
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|firstUpdate
condition|)
block|{
name|QNetworkConfiguration
name|item
decl_stmt|;
name|item
operator|.
name|d
operator|=
name|ptr
expr_stmt|;
emit|emit
name|configurationAdded
argument_list|(
name|item
argument_list|)
emit|;
block|}
name|ptr
operator|->
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|ptr
operator|->
name|state
operator|==
name|QNetworkConfiguration
operator|::
name|Active
condition|)
block|{
name|ptr
operator|->
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|onlineConfigurations
operator|.
name|insert
argument_list|(
name|ptr
operator|->
name|id
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|firstUpdate
operator|&&
name|onlineConfigurations
operator|.
name|count
argument_list|()
operator|==
literal|1
condition|)
emit|emit
name|onlineStateChanged
argument_list|(
literal|true
argument_list|)
emit|;
block|}
else|else
block|{
name|ptr
operator|->
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|configurationRemoved
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|configurationRemoved
parameter_list|(
name|QNetworkConfigurationPrivatePointer
name|ptr
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|ptr
operator|->
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|ptr
operator|->
name|isValid
operator|=
literal|false
expr_stmt|;
name|ptr
operator|->
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|firstUpdate
condition|)
block|{
name|QNetworkConfiguration
name|item
decl_stmt|;
name|item
operator|.
name|d
operator|=
name|ptr
expr_stmt|;
emit|emit
name|configurationRemoved
argument_list|(
name|item
argument_list|)
emit|;
block|}
name|onlineConfigurations
operator|.
name|remove
argument_list|(
name|ptr
operator|->
name|id
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|firstUpdate
operator|&&
name|onlineConfigurations
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|onlineStateChanged
argument_list|(
literal|false
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|configurationChanged
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|configurationChanged
parameter_list|(
name|QNetworkConfigurationPrivatePointer
name|ptr
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|firstUpdate
condition|)
block|{
name|QNetworkConfiguration
name|item
decl_stmt|;
name|item
operator|.
name|d
operator|=
name|ptr
expr_stmt|;
emit|emit
name|configurationChanged
argument_list|(
name|item
argument_list|)
emit|;
block|}
name|bool
name|previous
init|=
operator|!
name|onlineConfigurations
operator|.
name|isEmpty
argument_list|()
decl_stmt|;
name|ptr
operator|->
name|mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|ptr
operator|->
name|state
operator|==
name|QNetworkConfiguration
operator|::
name|Active
condition|)
name|onlineConfigurations
operator|.
name|insert
argument_list|(
name|ptr
operator|->
name|id
argument_list|)
expr_stmt|;
else|else
name|onlineConfigurations
operator|.
name|remove
argument_list|(
name|ptr
operator|->
name|id
argument_list|)
expr_stmt|;
name|ptr
operator|->
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|bool
name|online
init|=
operator|!
name|onlineConfigurations
operator|.
name|isEmpty
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|firstUpdate
operator|&&
name|online
operator|!=
name|previous
condition|)
emit|emit
name|onlineStateChanged
argument_list|(
name|online
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|updateConfigurations
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|updateConfigurations
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
typedef|typedef
name|QMultiMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|PluginKeyMap
typedef|;
typedef|typedef
name|PluginKeyMap
operator|::
name|const_iterator
name|PluginKeyMapConstIterator
typedef|;
endif|#
directive|endif
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|firstUpdate
condition|)
block|{
if|if
condition|(
name|qobject_cast
argument_list|<
name|QBearerEngine
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
condition|)
return|return;
name|updating
operator|=
literal|false
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|QBearerEngine
modifier|*
name|generic
init|=
literal|0
decl_stmt|;
name|QFactoryLoader
modifier|*
name|l
init|=
name|loader
argument_list|()
decl_stmt|;
specifier|const
name|PluginKeyMap
name|keyMap
init|=
name|l
operator|->
name|keyMap
argument_list|()
decl_stmt|;
specifier|const
name|PluginKeyMapConstIterator
name|cend
init|=
name|keyMap
operator|.
name|constEnd
argument_list|()
decl_stmt|;
name|QStringList
name|addedEngines
decl_stmt|;
for|for
control|(
name|PluginKeyMapConstIterator
name|it
init|=
name|keyMap
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
specifier|const
name|QString
modifier|&
name|key
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
if|if
condition|(
name|addedEngines
operator|.
name|contains
argument_list|(
name|key
argument_list|)
condition|)
continue|continue;
name|addedEngines
operator|.
name|append
argument_list|(
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
name|QBearerEngine
modifier|*
name|engine
init|=
name|qLoadPlugin
argument_list|<
name|QBearerEngine
argument_list|,
name|QBearerEnginePlugin
argument_list|>
argument_list|(
name|l
argument_list|,
name|key
argument_list|)
condition|)
block|{
if|if
condition|(
name|key
operator|==
name|QLatin1String
argument_list|(
literal|"generic"
argument_list|)
condition|)
name|generic
operator|=
name|engine
expr_stmt|;
else|else
name|sessionEngines
operator|.
name|append
argument_list|(
name|engine
argument_list|)
expr_stmt|;
name|engine
operator|->
name|moveToThread
argument_list|(
name|bearerThread
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateConfigurations
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|configurationAdded
argument_list|(
name|QNetworkConfigurationPrivatePointer
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|configurationAdded
argument_list|(
name|QNetworkConfigurationPrivatePointer
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|configurationRemoved
argument_list|(
name|QNetworkConfigurationPrivatePointer
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|configurationRemoved
argument_list|(
name|QNetworkConfigurationPrivatePointer
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|engine
argument_list|,
name|SIGNAL
argument_list|(
name|configurationChanged
argument_list|(
name|QNetworkConfigurationPrivatePointer
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|configurationChanged
argument_list|(
name|QNetworkConfigurationPrivatePointer
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|generic
condition|)
name|sessionEngines
operator|.
name|append
argument_list|(
name|generic
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_LIBRARY
block|}
name|QBearerEngine
modifier|*
name|engine
init|=
name|qobject_cast
argument_list|<
name|QBearerEngine
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|engine
operator|&&
operator|!
name|updatingEngines
operator|.
name|isEmpty
argument_list|()
condition|)
name|updatingEngines
operator|.
name|remove
argument_list|(
name|engine
argument_list|)
expr_stmt|;
if|if
condition|(
name|updating
operator|&&
name|updatingEngines
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|updating
operator|=
literal|false
expr_stmt|;
emit|emit
name|configurationUpdateComplete
argument_list|()
emit|;
block|}
if|if
condition|(
name|engine
operator|&&
operator|!
name|pollingEngines
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|pollingEngines
operator|.
name|remove
argument_list|(
name|engine
argument_list|)
expr_stmt|;
if|if
condition|(
name|pollingEngines
operator|.
name|isEmpty
argument_list|()
condition|)
name|startPolling
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|firstUpdate
condition|)
block|{
name|firstUpdate
operator|=
literal|false
expr_stmt|;
name|QList
argument_list|<
name|QBearerEngine
modifier|*
argument_list|>
name|enginesToInitialize
init|=
name|sessionEngines
decl_stmt|;
comment|//shallow copy the list in case it is modified when we unlock mutex
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QBearerEngine
modifier|*
name|engine
decl|,
name|enginesToInitialize
control|)
block|{
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|engine
argument_list|,
literal|"initialize"
argument_list|,
name|Qt
operator|::
name|BlockingQueuedConnection
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|performAsyncConfigurationUpdate
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|performAsyncConfigurationUpdate
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|sessionEngines
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
emit|emit
name|configurationUpdateComplete
argument_list|()
emit|;
return|return;
block|}
name|updating
operator|=
literal|true
expr_stmt|;
foreach|foreach
control|(
name|QBearerEngine
modifier|*
name|engine
decl|,
name|sessionEngines
control|)
block|{
name|updatingEngines
operator|.
name|insert
argument_list|(
name|engine
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|engine
argument_list|,
literal|"requestUpdate"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|engines
name|QList
argument_list|<
name|QBearerEngine
modifier|*
argument_list|>
name|QNetworkConfigurationManagerPrivate
operator|::
name|engines
parameter_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
return|return
name|sessionEngines
return|;
block|}
end_function
begin_function
DECL|function|startPolling
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|startPolling
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|pollTimer
condition|)
block|{
name|pollTimer
operator|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|bool
name|ok
decl_stmt|;
name|int
name|interval
init|=
name|qgetenv
argument_list|(
literal|"QT_BEARER_POLL_TIMEOUT"
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|interval
operator|=
literal|10000
expr_stmt|;
comment|//default 10 seconds
name|pollTimer
operator|->
name|setInterval
argument_list|(
name|interval
argument_list|)
expr_stmt|;
name|pollTimer
operator|->
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pollTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|pollEngines
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pollTimer
operator|->
name|isActive
argument_list|()
condition|)
return|return;
foreach|foreach
control|(
name|QBearerEngine
modifier|*
name|engine
decl|,
name|sessionEngines
control|)
block|{
if|if
condition|(
name|engine
operator|->
name|requiresPolling
argument_list|()
operator|&&
operator|(
name|forcedPolling
operator|||
name|engine
operator|->
name|configurationsInUse
argument_list|()
operator|)
condition|)
block|{
name|pollTimer
operator|->
name|start
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
name|performAsyncConfigurationUpdate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pollEngines
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|pollEngines
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QBearerEngine
modifier|*
name|engine
decl|,
name|sessionEngines
control|)
block|{
if|if
condition|(
name|engine
operator|->
name|requiresPolling
argument_list|()
operator|&&
operator|(
name|forcedPolling
operator|||
name|engine
operator|->
name|configurationsInUse
argument_list|()
operator|)
condition|)
block|{
name|pollingEngines
operator|.
name|insert
argument_list|(
name|engine
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|engine
argument_list|,
literal|"requestUpdate"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|enablePolling
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|enablePolling
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
operator|++
name|forcedPolling
expr_stmt|;
if|if
condition|(
name|forcedPolling
operator|==
literal|1
condition|)
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"startPolling"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|disablePolling
name|void
name|QNetworkConfigurationManagerPrivate
operator|::
name|disablePolling
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
operator|--
name|forcedPolling
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
comment|// QT_NO_BEARERMANAGEMENT
end_comment
end_unit
