begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgenericengine.h"
end_include
begin_include
include|#
directive|include
file|"../qnetworksession_impl.h"
end_include
begin_include
include|#
directive|include
file|<QtNetwork/private/qnetworkconfiguration_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qthread.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcoreapplication_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|"../platformdefs_win.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_typedef
DECL|typedef|NDIS_OID
DECL|typedef|PNDIS_OID
typedef|typedef
name|ULONG
name|NDIS_OID
typedef|,
modifier|*
name|PNDIS_OID
typedef|;
end_typedef
begin_include
include|#
directive|include
file|<nuiouser.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_LINUX
end_ifdef
begin_include
include|#
directive|include
file|<sys/socket.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_include
include|#
directive|include
file|<net/if.h>
end_include
begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
DECL|function|qGetInterfaceType
specifier|static
name|QNetworkConfiguration
operator|::
name|BearerType
name|qGetInterfaceType
parameter_list|(
specifier|const
name|QString
modifier|&
name|interface
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|DWORD
name|bytesWritten
decl_stmt|;
name|NDIS_MEDIUM
name|medium
decl_stmt|;
name|NDIS_PHYSICAL_MEDIUM
name|physicalMedium
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|NDISUIO_QUERY_OID
name|nicGetOid
decl_stmt|;
name|HANDLE
name|handle
init|=
name|CreateFile
argument_list|(
operator|(
name|PTCHAR
operator|)
name|NDISUIO_DEVICE_NAME
argument_list|,
literal|0
argument_list|,
name|FILE_SHARE_READ
argument_list|,
literal|0
argument_list|,
name|OPEN_EXISTING
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
else|#
directive|else
name|unsigned
name|long
name|oid
decl_stmt|;
name|HANDLE
name|handle
init|=
name|CreateFile
argument_list|(
operator|(
name|TCHAR
operator|*
operator|)
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\\\\.\\%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|interface
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
name|FILE_SHARE_READ
argument_list|,
literal|0
argument_list|,
name|OPEN_EXISTING
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|handle
operator|==
name|INVALID_HANDLE_VALUE
condition|)
return|return
name|QNetworkConfiguration
operator|::
name|BearerUnknown
return|;
name|bytesWritten
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|ZeroMemory
argument_list|(
operator|&
name|nicGetOid
argument_list|,
sizeof|sizeof
argument_list|(
name|NDISUIO_QUERY_OID
argument_list|)
argument_list|)
expr_stmt|;
name|nicGetOid
operator|.
name|Oid
operator|=
name|OID_GEN_MEDIA_SUPPORTED
expr_stmt|;
name|nicGetOid
operator|.
name|ptcDeviceName
operator|=
operator|(
name|PTCHAR
operator|)
name|interface
operator|.
name|utf16
argument_list|()
expr_stmt|;
name|bool
name|result
init|=
name|DeviceIoControl
argument_list|(
name|handle
argument_list|,
name|IOCTL_NDISUIO_QUERY_OID_VALUE
argument_list|,
operator|&
name|nicGetOid
argument_list|,
sizeof|sizeof
argument_list|(
name|nicGetOid
argument_list|)
argument_list|,
operator|&
name|nicGetOid
argument_list|,
sizeof|sizeof
argument_list|(
name|nicGetOid
argument_list|)
argument_list|,
operator|&
name|bytesWritten
argument_list|,
literal|0
argument_list|)
decl_stmt|;
else|#
directive|else
name|oid
operator|=
name|OID_GEN_MEDIA_SUPPORTED
expr_stmt|;
name|bool
name|result
init|=
name|DeviceIoControl
argument_list|(
name|handle
argument_list|,
name|IOCTL_NDIS_QUERY_GLOBAL_STATS
argument_list|,
operator|&
name|oid
argument_list|,
sizeof|sizeof
argument_list|(
name|oid
argument_list|)
argument_list|,
operator|&
name|medium
argument_list|,
sizeof|sizeof
argument_list|(
name|medium
argument_list|)
argument_list|,
operator|&
name|bytesWritten
argument_list|,
literal|0
argument_list|)
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|result
condition|)
block|{
name|CloseHandle
argument_list|(
name|handle
argument_list|)
expr_stmt|;
return|return
name|QNetworkConfiguration
operator|::
name|BearerUnknown
return|;
block|}
name|bytesWritten
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|medium
operator|=
name|NDIS_MEDIUM
argument_list|(
operator|*
operator|(
name|LPDWORD
operator|)
name|nicGetOid
operator|.
name|Data
argument_list|)
expr_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|nicGetOid
argument_list|,
sizeof|sizeof
argument_list|(
name|NDISUIO_QUERY_OID
argument_list|)
argument_list|)
expr_stmt|;
name|nicGetOid
operator|.
name|Oid
operator|=
name|OID_GEN_PHYSICAL_MEDIUM
expr_stmt|;
name|nicGetOid
operator|.
name|ptcDeviceName
operator|=
operator|(
name|PTCHAR
operator|)
name|interface
operator|.
name|utf16
argument_list|()
expr_stmt|;
name|result
operator|=
name|DeviceIoControl
argument_list|(
name|handle
argument_list|,
name|IOCTL_NDISUIO_QUERY_OID_VALUE
argument_list|,
operator|&
name|nicGetOid
argument_list|,
sizeof|sizeof
argument_list|(
name|nicGetOid
argument_list|)
argument_list|,
operator|&
name|nicGetOid
argument_list|,
sizeof|sizeof
argument_list|(
name|nicGetOid
argument_list|)
argument_list|,
operator|&
name|bytesWritten
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|physicalMedium
operator|=
name|NDIS_PHYSICAL_MEDIUM
argument_list|(
operator|*
operator|(
name|LPDWORD
operator|)
name|nicGetOid
operator|.
name|Data
argument_list|)
expr_stmt|;
else|#
directive|else
name|oid
operator|=
name|OID_GEN_PHYSICAL_MEDIUM
expr_stmt|;
name|result
operator|=
name|DeviceIoControl
argument_list|(
name|handle
argument_list|,
name|IOCTL_NDIS_QUERY_GLOBAL_STATS
argument_list|,
operator|&
name|oid
argument_list|,
sizeof|sizeof
argument_list|(
name|oid
argument_list|)
argument_list|,
operator|&
name|physicalMedium
argument_list|,
sizeof|sizeof
argument_list|(
name|physicalMedium
argument_list|)
argument_list|,
operator|&
name|bytesWritten
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|result
condition|)
block|{
name|CloseHandle
argument_list|(
name|handle
argument_list|)
expr_stmt|;
if|if
condition|(
name|medium
operator|==
name|NdisMedium802_3
condition|)
return|return
name|QNetworkConfiguration
operator|::
name|BearerEthernet
return|;
else|else
return|return
name|QNetworkConfiguration
operator|::
name|BearerUnknown
return|;
block|}
name|CloseHandle
argument_list|(
name|handle
argument_list|)
expr_stmt|;
if|if
condition|(
name|medium
operator|==
name|NdisMedium802_3
condition|)
block|{
switch|switch
condition|(
name|physicalMedium
condition|)
block|{
case|case
name|NdisPhysicalMediumWirelessLan
case|:
return|return
name|QNetworkConfiguration
operator|::
name|BearerWLAN
return|;
case|case
name|NdisPhysicalMediumBluetooth
case|:
return|return
name|QNetworkConfiguration
operator|::
name|BearerBluetooth
return|;
case|case
name|NdisPhysicalMediumWiMax
case|:
return|return
name|QNetworkConfiguration
operator|::
name|BearerWiMAX
return|;
default|default:
ifdef|#
directive|ifdef
name|BEARER_MANAGEMENT_DEBUG
name|qDebug
argument_list|()
operator|<<
literal|"Physical Medium"
operator|<<
name|physicalMedium
expr_stmt|;
endif|#
directive|endif
return|return
name|QNetworkConfiguration
operator|::
name|BearerEthernet
return|;
block|}
block|}
ifdef|#
directive|ifdef
name|BEARER_MANAGEMENT_DEBUG
name|qDebug
argument_list|()
operator|<<
name|medium
operator|<<
name|physicalMedium
expr_stmt|;
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
name|int
name|sock
init|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_DGRAM
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|ifreq
name|request
decl_stmt|;
name|strncpy
argument_list|(
name|request
operator|.
name|ifr_name
argument_list|,
name|interface
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
sizeof|sizeof
argument_list|(
name|request
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
name|request
operator|.
name|ifr_name
index|[
sizeof|sizeof
argument_list|(
name|request
operator|.
name|ifr_name
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|int
name|result
init|=
name|ioctl
argument_list|(
name|sock
argument_list|,
name|SIOCGIFHWADDR
argument_list|,
operator|&
name|request
argument_list|)
decl_stmt|;
name|close
argument_list|(
name|sock
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|>=
literal|0
operator|&&
name|request
operator|.
name|ifr_hwaddr
operator|.
name|sa_family
operator|==
name|ARPHRD_ETHER
condition|)
return|return
name|QNetworkConfiguration
operator|::
name|BearerEthernet
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|interface
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|QNetworkConfiguration
operator|::
name|BearerUnknown
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QGenericEngine
name|QGenericEngine
operator|::
name|QGenericEngine
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QBearerEngineImpl
argument_list|(
name|parent
argument_list|)
block|{
comment|//workaround for deadlock in __cxa_guard_acquire with webkit on macos x
comment|//initialise the Q_GLOBAL_STATIC in same thread as the AtomicallyInitializedStatic
operator|(
name|void
operator|)
name|QNetworkInterface
operator|::
name|interfaceFromIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QGenericEngine
name|QGenericEngine
operator|::
name|~
name|QGenericEngine
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|getInterfaceFromId
name|QString
name|QGenericEngine
operator|::
name|getInterfaceFromId
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
return|return
name|configurationInterface
operator|.
name|value
argument_list|(
name|id
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|hasIdentifier
name|bool
name|QGenericEngine
operator|::
name|hasIdentifier
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
return|return
name|configurationInterface
operator|.
name|contains
argument_list|(
name|id
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|connectToId
name|void
name|QGenericEngine
operator|::
name|connectToId
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
emit|emit
name|connectionError
argument_list|(
name|id
argument_list|,
name|OperationNotSupported
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|disconnectFromId
name|void
name|QGenericEngine
operator|::
name|disconnectFromId
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
emit|emit
name|connectionError
argument_list|(
name|id
argument_list|,
name|OperationNotSupported
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|QGenericEngine
operator|::
name|initialize
parameter_list|()
block|{
name|doRequestUpdate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|requestUpdate
name|void
name|QGenericEngine
operator|::
name|requestUpdate
parameter_list|()
block|{
name|doRequestUpdate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doRequestUpdate
name|void
name|QGenericEngine
operator|::
name|doRequestUpdate
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
comment|// Immediately after connecting with a wireless access point
comment|// QNetworkInterface::allInterfaces() will sometimes return an empty list. Calling it again a
comment|// second time results in a non-empty list. If we loose interfaces we will end up removing
comment|// network configurations which will break current sessions.
name|QList
argument_list|<
name|QNetworkInterface
argument_list|>
name|interfaces
init|=
name|QNetworkInterface
operator|::
name|allInterfaces
argument_list|()
decl_stmt|;
if|if
condition|(
name|interfaces
operator|.
name|isEmpty
argument_list|()
condition|)
name|interfaces
operator|=
name|QNetworkInterface
operator|::
name|allInterfaces
argument_list|()
expr_stmt|;
name|QStringList
name|previous
init|=
name|accessPointConfigurations
operator|.
name|keys
argument_list|()
decl_stmt|;
comment|// create configuration for each interface
while|while
condition|(
operator|!
name|interfaces
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QNetworkInterface
name|interface
init|=
name|interfaces
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|interface
operator|.
name|isValid
argument_list|()
condition|)
continue|continue;
comment|// ignore loopback interface
if|if
condition|(
name|interface
operator|.
name|flags
argument_list|()
operator|&
name|QNetworkInterface
operator|::
name|IsLoopBack
condition|)
continue|continue;
comment|// ignore WLAN interface handled in separate engine
if|if
condition|(
name|qGetInterfaceType
argument_list|(
name|interface
operator|.
name|name
argument_list|()
argument_list|)
operator|==
name|QNetworkConfiguration
operator|::
name|BearerWLAN
condition|)
continue|continue;
name|uint
name|identifier
decl_stmt|;
if|if
condition|(
name|interface
operator|.
name|index
argument_list|()
condition|)
name|identifier
operator|=
name|qHash
argument_list|(
name|QLatin1String
argument_list|(
literal|"generic:"
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|interface
operator|.
name|index
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|identifier
operator|=
name|qHash
argument_list|(
name|QLatin1String
argument_list|(
literal|"generic:"
argument_list|)
operator|+
name|interface
operator|.
name|hardwareAddress
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|id
init|=
name|QString
operator|::
name|number
argument_list|(
name|identifier
argument_list|)
decl_stmt|;
name|previous
operator|.
name|removeAll
argument_list|(
name|id
argument_list|)
expr_stmt|;
name|QString
name|name
init|=
name|interface
operator|.
name|humanReadableName
argument_list|()
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
name|name
operator|=
name|interface
operator|.
name|name
argument_list|()
expr_stmt|;
name|QNetworkConfiguration
operator|::
name|StateFlags
name|state
init|=
name|QNetworkConfiguration
operator|::
name|Defined
decl_stmt|;
if|if
condition|(
operator|(
name|interface
operator|.
name|flags
argument_list|()
operator|&
name|QNetworkInterface
operator|::
name|IsRunning
operator|)
operator|&&
operator|!
name|interface
operator|.
name|addressEntries
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|state
operator||=
name|QNetworkConfiguration
operator|::
name|Active
expr_stmt|;
if|if
condition|(
name|accessPointConfigurations
operator|.
name|contains
argument_list|(
name|id
argument_list|)
condition|)
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|accessPointConfigurations
operator|.
name|value
argument_list|(
name|id
argument_list|)
decl_stmt|;
name|bool
name|changed
init|=
literal|false
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
operator|!
name|ptr
operator|->
name|isValid
condition|)
block|{
name|ptr
operator|->
name|isValid
operator|=
literal|true
expr_stmt|;
name|changed
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|ptr
operator|->
name|name
operator|!=
name|name
condition|)
block|{
name|ptr
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|changed
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|ptr
operator|->
name|id
operator|!=
name|id
condition|)
block|{
name|ptr
operator|->
name|id
operator|=
name|id
expr_stmt|;
name|changed
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|ptr
operator|->
name|state
operator|!=
name|state
condition|)
block|{
name|ptr
operator|->
name|state
operator|=
name|state
expr_stmt|;
name|changed
operator|=
literal|true
expr_stmt|;
block|}
name|ptr
operator|->
name|mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
name|changed
condition|)
block|{
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
emit|emit
name|configurationChanged
argument_list|(
name|ptr
argument_list|)
emit|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
argument_list|(
operator|new
name|QNetworkConfigurationPrivate
argument_list|)
decl_stmt|;
name|ptr
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|ptr
operator|->
name|isValid
operator|=
literal|true
expr_stmt|;
name|ptr
operator|->
name|id
operator|=
name|id
expr_stmt|;
name|ptr
operator|->
name|state
operator|=
name|state
expr_stmt|;
name|ptr
operator|->
name|type
operator|=
name|QNetworkConfiguration
operator|::
name|InternetAccessPoint
expr_stmt|;
name|ptr
operator|->
name|bearerType
operator|=
name|qGetInterfaceType
argument_list|(
name|interface
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|accessPointConfigurations
operator|.
name|insert
argument_list|(
name|id
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
name|configurationInterface
operator|.
name|insert
argument_list|(
name|id
argument_list|,
name|interface
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
emit|emit
name|configurationAdded
argument_list|(
name|ptr
argument_list|)
emit|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
block|}
block|}
while|while
condition|(
operator|!
name|previous
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|accessPointConfigurations
operator|.
name|take
argument_list|(
name|previous
operator|.
name|takeFirst
argument_list|()
argument_list|)
decl_stmt|;
name|configurationInterface
operator|.
name|remove
argument_list|(
name|ptr
operator|->
name|id
argument_list|)
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
emit|emit
name|configurationRemoved
argument_list|(
name|ptr
argument_list|)
emit|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
block|}
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
endif|#
directive|endif
emit|emit
name|updateCompleted
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|sessionStateForId
name|QNetworkSession
operator|::
name|State
name|QGenericEngine
operator|::
name|sessionStateForId
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|QNetworkConfigurationPrivatePointer
name|ptr
init|=
name|accessPointConfigurations
operator|.
name|value
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ptr
condition|)
return|return
name|QNetworkSession
operator|::
name|Invalid
return|;
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
operator|!
name|ptr
operator|->
name|isValid
condition|)
block|{
return|return
name|QNetworkSession
operator|::
name|Invalid
return|;
block|}
elseif|else
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
return|return
name|QNetworkSession
operator|::
name|Connected
return|;
block|}
elseif|else
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
return|return
name|QNetworkSession
operator|::
name|Disconnected
return|;
block|}
elseif|else
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|QNetworkConfiguration
operator|::
name|Defined
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Defined
condition|)
block|{
return|return
name|QNetworkSession
operator|::
name|NotAvailable
return|;
block|}
elseif|else
if|if
condition|(
operator|(
name|ptr
operator|->
name|state
operator|&
name|QNetworkConfiguration
operator|::
name|Undefined
operator|)
operator|==
name|QNetworkConfiguration
operator|::
name|Undefined
condition|)
block|{
return|return
name|QNetworkSession
operator|::
name|NotAvailable
return|;
block|}
return|return
name|QNetworkSession
operator|::
name|Invalid
return|;
block|}
end_function
begin_function
DECL|function|capabilities
name|QNetworkConfigurationManager
operator|::
name|Capabilities
name|QGenericEngine
operator|::
name|capabilities
parameter_list|()
specifier|const
block|{
return|return
name|QNetworkConfigurationManager
operator|::
name|ForcedRoaming
return|;
block|}
end_function
begin_function
DECL|function|createSessionBackend
name|QNetworkSessionPrivate
modifier|*
name|QGenericEngine
operator|::
name|createSessionBackend
parameter_list|()
block|{
return|return
operator|new
name|QNetworkSessionPrivateImpl
return|;
block|}
end_function
begin_function
DECL|function|defaultConfiguration
name|QNetworkConfigurationPrivatePointer
name|QGenericEngine
operator|::
name|defaultConfiguration
parameter_list|()
block|{
return|return
name|QNetworkConfigurationPrivatePointer
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|requiresPolling
name|bool
name|QGenericEngine
operator|::
name|requiresPolling
parameter_list|()
specifier|const
block|{
return|return
literal|true
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
comment|// QT_NO_BEARERMANAGEMENT
end_comment
end_unit
