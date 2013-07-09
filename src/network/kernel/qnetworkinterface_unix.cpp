begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qset.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkinterface.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkinterface_p.h"
end_include
begin_include
include|#
directive|include
file|"qalgorithms.h"
end_include
begin_include
include|#
directive|include
file|"private/qnet_unix_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
end_ifndef
begin_define
DECL|macro|IP_MULTICAST
define|#
directive|define
name|IP_MULTICAST
end_define
begin_comment
DECL|macro|IP_MULTICAST
comment|// make AIX happy and define IFF_MULTICAST
end_comment
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/socket.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SOLARIS
end_ifdef
begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<net/if.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_LINUXBASE
argument_list|)
end_if
begin_define
DECL|macro|QT_NO_GETIFADDRS
define|#
directive|define
name|QT_NO_GETIFADDRS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_ANDROID
end_ifdef
begin_comment
comment|// android lacks if_nameindex
end_comment
begin_define
DECL|macro|QT_NO_IPV6IFNAME
define|#
directive|define
name|QT_NO_IPV6IFNAME
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GETIFADDRS
end_ifndef
begin_include
include|#
directive|include
file|<ifaddrs.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_LINUXBASE
end_ifdef
begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|SIOCGIFBRDADDR
end_ifndef
begin_define
DECL|macro|SIOCGIFBRDADDR
define|#
directive|define
name|SIOCGIFBRDADDR
value|0x8919
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
comment|// QT_LINUXBASE
end_comment
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|addressFromSockaddr
specifier|static
name|QHostAddress
name|addressFromSockaddr
parameter_list|(
name|sockaddr
modifier|*
name|sa
parameter_list|)
block|{
name|QHostAddress
name|address
decl_stmt|;
if|if
condition|(
operator|!
name|sa
condition|)
return|return
name|address
return|;
if|if
condition|(
name|sa
operator|->
name|sa_family
operator|==
name|AF_INET
condition|)
name|address
operator|.
name|setAddress
argument_list|(
name|htonl
argument_list|(
operator|(
operator|(
name|sockaddr_in
operator|*
operator|)
name|sa
operator|)
operator|->
name|sin_addr
operator|.
name|s_addr
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|sa
operator|->
name|sa_family
operator|==
name|AF_INET6
condition|)
block|{
name|address
operator|.
name|setAddress
argument_list|(
operator|(
operator|(
name|sockaddr_in6
operator|*
operator|)
name|sa
operator|)
operator|->
name|sin6_addr
operator|.
name|s6_addr
argument_list|)
expr_stmt|;
name|int
name|scope
init|=
operator|(
operator|(
name|sockaddr_in6
operator|*
operator|)
name|sa
operator|)
operator|->
name|sin6_scope_id
decl_stmt|;
if|if
condition|(
name|scope
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_IPV6IFNAME
name|char
name|scopeid
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
if|if
condition|(
operator|::
name|if_indextoname
argument_list|(
name|scope
argument_list|,
name|scopeid
argument_list|)
condition|)
block|{
name|address
operator|.
name|setScopeId
argument_list|(
name|QLatin1String
argument_list|(
name|scopeid
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
name|address
operator|.
name|setScopeId
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|scope
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|address
return|;
block|}
end_function
begin_function
DECL|function|convertFlags
specifier|static
name|QNetworkInterface
operator|::
name|InterfaceFlags
name|convertFlags
parameter_list|(
name|uint
name|rawFlags
parameter_list|)
block|{
name|QNetworkInterface
operator|::
name|InterfaceFlags
name|flags
init|=
literal|0
decl_stmt|;
name|flags
operator||=
operator|(
name|rawFlags
operator|&
name|IFF_UP
operator|)
condition|?
name|QNetworkInterface
operator|::
name|IsUp
else|:
name|QNetworkInterface
operator|::
name|InterfaceFlag
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|flags
operator||=
operator|(
name|rawFlags
operator|&
name|IFF_RUNNING
operator|)
condition|?
name|QNetworkInterface
operator|::
name|IsRunning
else|:
name|QNetworkInterface
operator|::
name|InterfaceFlag
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|flags
operator||=
operator|(
name|rawFlags
operator|&
name|IFF_BROADCAST
operator|)
condition|?
name|QNetworkInterface
operator|::
name|CanBroadcast
else|:
name|QNetworkInterface
operator|::
name|InterfaceFlag
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|flags
operator||=
operator|(
name|rawFlags
operator|&
name|IFF_LOOPBACK
operator|)
condition|?
name|QNetworkInterface
operator|::
name|IsLoopBack
else|:
name|QNetworkInterface
operator|::
name|InterfaceFlag
argument_list|(
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|IFF_POINTOPOINT
comment|//cygwin doesn't define IFF_POINTOPOINT
name|flags
operator||=
operator|(
name|rawFlags
operator|&
name|IFF_POINTOPOINT
operator|)
condition|?
name|QNetworkInterface
operator|::
name|IsPointToPoint
else|:
name|QNetworkInterface
operator|::
name|InterfaceFlag
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IFF_MULTICAST
name|flags
operator||=
operator|(
name|rawFlags
operator|&
name|IFF_MULTICAST
operator|)
condition|?
name|QNetworkInterface
operator|::
name|CanMulticast
else|:
name|QNetworkInterface
operator|::
name|InterfaceFlag
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|flags
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_GETIFADDRS
end_ifdef
begin_comment
comment|// getifaddrs not available
end_comment
begin_decl_stmt
DECL|variable|STORAGEBUFFER_GROWTH
specifier|static
specifier|const
name|int
name|STORAGEBUFFER_GROWTH
init|=
literal|256
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|interfaceNames
specifier|static
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|interfaceNames
parameter_list|(
name|int
name|socket
parameter_list|)
block|{
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|result
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_NO_IPV6IFNAME
name|QByteArray
name|storageBuffer
decl_stmt|;
name|struct
name|ifconf
name|interfaceList
decl_stmt|;
forever|forever
block|{
comment|// grow the storage buffer
name|storageBuffer
operator|.
name|resize
argument_list|(
name|storageBuffer
operator|.
name|size
argument_list|()
operator|+
name|STORAGEBUFFER_GROWTH
argument_list|)
expr_stmt|;
name|interfaceList
operator|.
name|ifc_buf
operator|=
name|storageBuffer
operator|.
name|data
argument_list|()
expr_stmt|;
name|interfaceList
operator|.
name|ifc_len
operator|=
name|storageBuffer
operator|.
name|size
argument_list|()
expr_stmt|;
comment|// get the interface list
if|if
condition|(
name|qt_safe_ioctl
argument_list|(
name|socket
argument_list|,
name|SIOCGIFCONF
argument_list|,
operator|&
name|interfaceList
argument_list|)
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|int
argument_list|(
name|interfaceList
operator|.
name|ifc_len
operator|+
sizeof|sizeof
argument_list|(
name|ifreq
argument_list|)
operator|+
literal|64
argument_list|)
operator|<
name|storageBuffer
operator|.
name|size
argument_list|()
condition|)
block|{
comment|// if the buffer was big enough, break
name|storageBuffer
operator|.
name|resize
argument_list|(
name|interfaceList
operator|.
name|ifc_len
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
else|else
block|{
comment|// internal error
return|return
name|result
return|;
block|}
if|if
condition|(
name|storageBuffer
operator|.
name|size
argument_list|()
operator|>
literal|100000
condition|)
block|{
comment|// out of space
return|return
name|result
return|;
block|}
block|}
name|int
name|interfaceCount
init|=
name|interfaceList
operator|.
name|ifc_len
operator|/
sizeof|sizeof
argument_list|(
name|ifreq
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|interfaceCount
condition|;
operator|++
name|i
control|)
block|{
name|QByteArray
name|name
init|=
name|QByteArray
argument_list|(
name|interfaceList
operator|.
name|ifc_req
index|[
name|i
index|]
operator|.
name|ifr_name
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|<<
name|name
expr_stmt|;
block|}
return|return
name|result
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|socket
argument_list|)
expr_stmt|;
comment|// use if_nameindex
name|struct
name|if_nameindex
modifier|*
name|interfaceList
init|=
operator|::
name|if_nameindex
argument_list|()
decl_stmt|;
for|for
control|(
name|struct
name|if_nameindex
modifier|*
name|ptr
init|=
name|interfaceList
init|;
name|ptr
operator|&&
name|ptr
operator|->
name|if_name
condition|;
operator|++
name|ptr
control|)
name|result
operator|<<
name|ptr
operator|->
name|if_name
expr_stmt|;
name|if_freenameindex
argument_list|(
name|interfaceList
argument_list|)
expr_stmt|;
return|return
name|result
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|findInterface
specifier|static
name|QNetworkInterfacePrivate
modifier|*
name|findInterface
parameter_list|(
name|int
name|socket
parameter_list|,
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
modifier|&
name|interfaces
parameter_list|,
name|struct
name|ifreq
modifier|&
name|req
parameter_list|)
block|{
name|QNetworkInterfacePrivate
modifier|*
name|iface
init|=
literal|0
decl_stmt|;
name|int
name|ifindex
init|=
literal|0
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_IPV6IFNAME
comment|// Get the interface index
name|ifindex
operator|=
name|if_nametoindex
argument_list|(
name|req
operator|.
name|ifr_name
argument_list|)
expr_stmt|;
comment|// find the interface data
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
operator|::
name|Iterator
name|if_it
init|=
name|interfaces
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|if_it
operator|!=
name|interfaces
operator|.
name|end
argument_list|()
condition|;
operator|++
name|if_it
control|)
if|if
condition|(
operator|(
operator|*
name|if_it
operator|)
operator|->
name|index
operator|==
name|ifindex
condition|)
block|{
comment|// existing interface
name|iface
operator|=
operator|*
name|if_it
expr_stmt|;
break|break;
block|}
else|#
directive|else
comment|// Search by name
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
operator|::
name|Iterator
name|if_it
init|=
name|interfaces
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|if_it
operator|!=
name|interfaces
operator|.
name|end
argument_list|()
condition|;
operator|++
name|if_it
control|)
if|if
condition|(
operator|(
operator|*
name|if_it
operator|)
operator|->
name|name
operator|==
name|QLatin1String
argument_list|(
name|req
operator|.
name|ifr_name
argument_list|)
condition|)
block|{
comment|// existing interface
name|iface
operator|=
operator|*
name|if_it
expr_stmt|;
break|break;
block|}
endif|#
directive|endif
if|if
condition|(
operator|!
name|iface
condition|)
block|{
comment|// new interface, create data:
name|iface
operator|=
operator|new
name|QNetworkInterfacePrivate
expr_stmt|;
name|iface
operator|->
name|index
operator|=
name|ifindex
expr_stmt|;
name|interfaces
operator|<<
name|iface
expr_stmt|;
ifdef|#
directive|ifdef
name|SIOCGIFNAME
comment|// Get the canonical name
name|QByteArray
name|oldName
init|=
name|req
operator|.
name|ifr_name
decl_stmt|;
if|if
condition|(
name|qt_safe_ioctl
argument_list|(
name|socket
argument_list|,
name|SIOCGIFNAME
argument_list|,
operator|&
name|req
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|iface
operator|->
name|name
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|req
operator|.
name|ifr_name
argument_list|)
expr_stmt|;
comment|// reset the name:
name|memcpy
argument_list|(
name|req
operator|.
name|ifr_name
argument_list|,
name|oldName
argument_list|,
name|qMin
argument_list|<
name|int
argument_list|>
argument_list|(
name|oldName
operator|.
name|length
argument_list|()
operator|+
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|req
operator|.
name|ifr_name
argument_list|)
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
comment|// use this name anyways
name|iface
operator|->
name|name
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|req
operator|.
name|ifr_name
argument_list|)
expr_stmt|;
block|}
comment|// Get interface flags
if|if
condition|(
name|qt_safe_ioctl
argument_list|(
name|socket
argument_list|,
name|SIOCGIFFLAGS
argument_list|,
operator|&
name|req
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|iface
operator|->
name|flags
operator|=
name|convertFlags
argument_list|(
name|req
operator|.
name|ifr_flags
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|SIOCGIFHWADDR
comment|// Get the HW address
if|if
condition|(
name|qt_safe_ioctl
argument_list|(
name|socket
argument_list|,
name|SIOCGIFHWADDR
argument_list|,
operator|&
name|req
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|uchar
modifier|*
name|addr
init|=
operator|(
name|uchar
operator|*
operator|)
name|req
operator|.
name|ifr_addr
operator|.
name|sa_data
decl_stmt|;
name|iface
operator|->
name|hardwareAddress
operator|=
name|iface
operator|->
name|makeHwAddress
argument_list|(
literal|6
argument_list|,
name|addr
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
return|return
name|iface
return|;
block|}
end_function
begin_function
DECL|function|interfaceListing
specifier|static
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaceListing
parameter_list|()
block|{
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaces
decl_stmt|;
name|int
name|socket
decl_stmt|;
if|if
condition|(
operator|(
name|socket
operator|=
name|qt_safe_socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_STREAM
argument_list|,
name|IPPROTO_IP
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
return|return
name|interfaces
return|;
comment|// error
name|QSet
argument_list|<
name|QByteArray
argument_list|>
name|names
init|=
name|interfaceNames
argument_list|(
name|socket
argument_list|)
decl_stmt|;
name|QSet
argument_list|<
name|QByteArray
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|names
operator|.
name|constBegin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|names
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|ifreq
name|req
decl_stmt|;
name|memset
argument_list|(
operator|&
name|req
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ifreq
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|req
operator|.
name|ifr_name
argument_list|,
operator|*
name|it
argument_list|,
name|qMin
argument_list|<
name|int
argument_list|>
argument_list|(
name|it
operator|->
name|length
argument_list|()
operator|+
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|req
operator|.
name|ifr_name
argument_list|)
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QNetworkInterfacePrivate
modifier|*
name|iface
init|=
name|findInterface
argument_list|(
name|socket
argument_list|,
name|interfaces
argument_list|,
name|req
argument_list|)
decl_stmt|;
comment|// Get the interface broadcast address
name|QNetworkAddressEntry
name|entry
decl_stmt|;
if|if
condition|(
name|iface
operator|->
name|flags
operator|&
name|QNetworkInterface
operator|::
name|CanBroadcast
condition|)
block|{
if|if
condition|(
name|qt_safe_ioctl
argument_list|(
name|socket
argument_list|,
name|SIOCGIFBRDADDR
argument_list|,
operator|&
name|req
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|sockaddr
modifier|*
name|sa
init|=
operator|&
name|req
operator|.
name|ifr_addr
decl_stmt|;
if|if
condition|(
name|sa
operator|->
name|sa_family
operator|==
name|AF_INET
condition|)
name|entry
operator|.
name|setBroadcast
argument_list|(
name|addressFromSockaddr
argument_list|(
name|sa
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Get the interface netmask
if|if
condition|(
name|qt_safe_ioctl
argument_list|(
name|socket
argument_list|,
name|SIOCGIFNETMASK
argument_list|,
operator|&
name|req
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|sockaddr
modifier|*
name|sa
init|=
operator|&
name|req
operator|.
name|ifr_addr
decl_stmt|;
name|entry
operator|.
name|setNetmask
argument_list|(
name|addressFromSockaddr
argument_list|(
name|sa
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Get the address of the interface
if|if
condition|(
name|qt_safe_ioctl
argument_list|(
name|socket
argument_list|,
name|SIOCGIFADDR
argument_list|,
operator|&
name|req
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|sockaddr
modifier|*
name|sa
init|=
operator|&
name|req
operator|.
name|ifr_addr
decl_stmt|;
name|entry
operator|.
name|setIp
argument_list|(
name|addressFromSockaddr
argument_list|(
name|sa
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|iface
operator|->
name|addressEntries
operator|<<
name|entry
expr_stmt|;
block|}
operator|::
name|close
argument_list|(
name|socket
argument_list|)
expr_stmt|;
return|return
name|interfaces
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|// use getifaddrs
end_comment
begin_comment
comment|// platform-specific defs:
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_LINUX
end_ifdef
begin_function
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<features.h>
name|QT_END_INCLUDE_NAMESPACE
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
name|__GLIBC__
operator|-
literal|0
operator|>=
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|-
literal|0
operator|>=
literal|1
operator|&&
operator|!
name|defined
argument_list|(
name|QT_LINUXBASE
argument_list|)
include|#
directive|include
file|<netpacket/packet.h>
DECL|function|createInterfaces
specifier|static
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|createInterfaces
parameter_list|(
name|ifaddrs
modifier|*
name|rawList
parameter_list|)
block|{
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaces
decl_stmt|;
for|for
control|(
name|ifaddrs
modifier|*
name|ptr
init|=
name|rawList
init|;
name|ptr
condition|;
name|ptr
operator|=
name|ptr
operator|->
name|ifa_next
control|)
block|{
if|if
condition|(
operator|!
name|ptr
operator|->
name|ifa_addr
condition|)
continue|continue;
comment|// Get the interface index
name|int
name|ifindex
init|=
name|if_nametoindex
argument_list|(
name|ptr
operator|->
name|ifa_name
argument_list|)
decl_stmt|;
comment|// on Linux we use AF_PACKET and sockaddr_ll to obtain hHwAddress
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
operator|::
name|Iterator
name|if_it
init|=
name|interfaces
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|if_it
operator|!=
name|interfaces
operator|.
name|end
argument_list|()
condition|;
operator|++
name|if_it
control|)
if|if
condition|(
operator|(
operator|*
name|if_it
operator|)
operator|->
name|index
operator|==
name|ifindex
condition|)
block|{
comment|// this one has been added already
if|if
condition|(
name|ptr
operator|->
name|ifa_addr
operator|->
name|sa_family
operator|==
name|AF_PACKET
operator|&&
operator|(
operator|*
name|if_it
operator|)
operator|->
name|hardwareAddress
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|sockaddr_ll
modifier|*
name|sll
init|=
operator|(
name|sockaddr_ll
operator|*
operator|)
name|ptr
operator|->
name|ifa_addr
decl_stmt|;
operator|(
operator|*
name|if_it
operator|)
operator|->
name|hardwareAddress
operator|=
operator|(
operator|*
name|if_it
operator|)
operator|->
name|makeHwAddress
argument_list|(
name|sll
operator|->
name|sll_halen
argument_list|,
operator|(
name|uchar
operator|*
operator|)
name|sll
operator|->
name|sll_addr
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
if|if
condition|(
name|if_it
operator|!=
name|interfaces
operator|.
name|end
argument_list|()
condition|)
continue|continue;
name|QNetworkInterfacePrivate
modifier|*
name|iface
init|=
operator|new
name|QNetworkInterfacePrivate
decl_stmt|;
name|interfaces
operator|<<
name|iface
expr_stmt|;
name|iface
operator|->
name|index
operator|=
name|ifindex
expr_stmt|;
name|iface
operator|->
name|name
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|ptr
operator|->
name|ifa_name
argument_list|)
expr_stmt|;
name|iface
operator|->
name|flags
operator|=
name|convertFlags
argument_list|(
name|ptr
operator|->
name|ifa_flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptr
operator|->
name|ifa_addr
operator|->
name|sa_family
operator|==
name|AF_PACKET
condition|)
block|{
name|sockaddr_ll
modifier|*
name|sll
init|=
operator|(
name|sockaddr_ll
operator|*
operator|)
name|ptr
operator|->
name|ifa_addr
decl_stmt|;
name|iface
operator|->
name|hardwareAddress
operator|=
name|iface
operator|->
name|makeHwAddress
argument_list|(
name|sll
operator|->
name|sll_halen
argument_list|,
operator|(
name|uchar
operator|*
operator|)
name|sll
operator|->
name|sll_addr
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|interfaces
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
end_elif
begin_function
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<net/if_dl.h>
name|QT_END_INCLUDE_NAMESPACE
specifier|static
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|createInterfaces
parameter_list|(
name|ifaddrs
modifier|*
name|rawList
parameter_list|)
block|{
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaces
decl_stmt|;
comment|// on NetBSD we use AF_LINK and sockaddr_dl
comment|// scan the list for that family
for|for
control|(
name|ifaddrs
modifier|*
name|ptr
init|=
name|rawList
init|;
name|ptr
condition|;
name|ptr
operator|=
name|ptr
operator|->
name|ifa_next
control|)
if|if
condition|(
name|ptr
operator|->
name|ifa_addr
operator|&&
name|ptr
operator|->
name|ifa_addr
operator|->
name|sa_family
operator|==
name|AF_LINK
condition|)
block|{
name|QNetworkInterfacePrivate
modifier|*
name|iface
init|=
operator|new
name|QNetworkInterfacePrivate
decl_stmt|;
name|interfaces
operator|<<
name|iface
expr_stmt|;
name|sockaddr_dl
modifier|*
name|sdl
init|=
operator|(
name|sockaddr_dl
operator|*
operator|)
name|ptr
operator|->
name|ifa_addr
decl_stmt|;
name|iface
operator|->
name|index
operator|=
name|sdl
operator|->
name|sdl_index
expr_stmt|;
name|iface
operator|->
name|name
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|ptr
operator|->
name|ifa_name
argument_list|)
expr_stmt|;
name|iface
operator|->
name|flags
operator|=
name|convertFlags
argument_list|(
name|ptr
operator|->
name|ifa_flags
argument_list|)
expr_stmt|;
name|iface
operator|->
name|hardwareAddress
operator|=
name|iface
operator|->
name|makeHwAddress
argument_list|(
name|sdl
operator|->
name|sdl_alen
argument_list|,
operator|(
name|uchar
operator|*
operator|)
name|LLADDR
argument_list|(
name|sdl
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|interfaces
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|// Generic version
end_comment
begin_function
specifier|static
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|createInterfaces
parameter_list|(
name|ifaddrs
modifier|*
name|rawList
parameter_list|)
block|{
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaces
decl_stmt|;
comment|// make sure there's one entry for each interface
for|for
control|(
name|ifaddrs
modifier|*
name|ptr
init|=
name|rawList
init|;
name|ptr
condition|;
name|ptr
operator|=
name|ptr
operator|->
name|ifa_next
control|)
block|{
comment|// Get the interface index
name|int
name|ifindex
init|=
name|if_nametoindex
argument_list|(
name|ptr
operator|->
name|ifa_name
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
operator|::
name|Iterator
name|if_it
init|=
name|interfaces
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|if_it
operator|!=
name|interfaces
operator|.
name|end
argument_list|()
condition|;
operator|++
name|if_it
control|)
if|if
condition|(
operator|(
operator|*
name|if_it
operator|)
operator|->
name|index
operator|==
name|ifindex
condition|)
comment|// this one has been added already
break|break;
if|if
condition|(
name|if_it
operator|==
name|interfaces
operator|.
name|end
argument_list|()
condition|)
block|{
comment|// none found, create
name|QNetworkInterfacePrivate
modifier|*
name|iface
init|=
operator|new
name|QNetworkInterfacePrivate
decl_stmt|;
name|interfaces
operator|<<
name|iface
expr_stmt|;
name|iface
operator|->
name|index
operator|=
name|ifindex
expr_stmt|;
name|iface
operator|->
name|name
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|ptr
operator|->
name|ifa_name
argument_list|)
expr_stmt|;
name|iface
operator|->
name|flags
operator|=
name|convertFlags
argument_list|(
name|ptr
operator|->
name|ifa_flags
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|interfaces
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|interfaceListing
specifier|static
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaceListing
parameter_list|()
block|{
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|interfaces
decl_stmt|;
name|ifaddrs
modifier|*
name|interfaceListing
decl_stmt|;
if|if
condition|(
name|getifaddrs
argument_list|(
operator|&
name|interfaceListing
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|// error
return|return
name|interfaces
return|;
block|}
name|interfaces
operator|=
name|createInterfaces
argument_list|(
name|interfaceListing
argument_list|)
expr_stmt|;
for|for
control|(
name|ifaddrs
modifier|*
name|ptr
init|=
name|interfaceListing
init|;
name|ptr
condition|;
name|ptr
operator|=
name|ptr
operator|->
name|ifa_next
control|)
block|{
comment|// Get the interface index
name|int
name|ifindex
init|=
name|if_nametoindex
argument_list|(
name|ptr
operator|->
name|ifa_name
argument_list|)
decl_stmt|;
name|QNetworkInterfacePrivate
modifier|*
name|iface
init|=
literal|0
decl_stmt|;
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
operator|::
name|Iterator
name|if_it
init|=
name|interfaces
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|if_it
operator|!=
name|interfaces
operator|.
name|end
argument_list|()
condition|;
operator|++
name|if_it
control|)
if|if
condition|(
operator|(
operator|*
name|if_it
operator|)
operator|->
name|index
operator|==
name|ifindex
condition|)
block|{
comment|// found this interface already
name|iface
operator|=
operator|*
name|if_it
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|!
name|iface
condition|)
block|{
comment|// skip all non-IP interfaces
continue|continue;
block|}
name|QNetworkAddressEntry
name|entry
decl_stmt|;
name|entry
operator|.
name|setIp
argument_list|(
name|addressFromSockaddr
argument_list|(
name|ptr
operator|->
name|ifa_addr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|entry
operator|.
name|ip
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
comment|// could not parse the address
continue|continue;
name|entry
operator|.
name|setNetmask
argument_list|(
name|addressFromSockaddr
argument_list|(
name|ptr
operator|->
name|ifa_netmask
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|iface
operator|->
name|flags
operator|&
name|QNetworkInterface
operator|::
name|CanBroadcast
condition|)
name|entry
operator|.
name|setBroadcast
argument_list|(
name|addressFromSockaddr
argument_list|(
name|ptr
operator|->
name|ifa_broadaddr
argument_list|)
argument_list|)
expr_stmt|;
name|iface
operator|->
name|addressEntries
operator|<<
name|entry
expr_stmt|;
block|}
name|freeifaddrs
argument_list|(
name|interfaceListing
argument_list|)
expr_stmt|;
return|return
name|interfaces
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|scan
name|QList
argument_list|<
name|QNetworkInterfacePrivate
modifier|*
argument_list|>
name|QNetworkInterfaceManager
operator|::
name|scan
parameter_list|()
block|{
return|return
name|interfaceListing
argument_list|()
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
comment|// QT_NO_NETWORKINTERFACE
end_comment
end_unit
