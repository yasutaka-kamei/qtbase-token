begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//#define QHOSTINFO_DEBUG
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qhostinfo_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qnativesocketengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qiodevice.h"
end_include
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qlibrary.h>
end_include
begin_include
include|#
directive|include
file|<qbasicatomic.h>
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<private/qmutexpool_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qnet_unix_p.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<netdb.h>
end_include
begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_include
include|#
directive|include
file|<hostLib.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<resolv.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_GETADDRINFO
argument_list|)
end_if
begin_decl_stmt
DECL|variable|getHostByNameMutex
specifier|static
name|QBasicMutex
name|getHostByNameMutex
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// Almost always the same. If not, specify in qplatformdefs.h.
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_SOCKOPTLEN_T
argument_list|)
end_if
begin_define
DECL|macro|QT_SOCKOPTLEN_T
define|#
directive|define
name|QT_SOCKOPTLEN_T
value|QT_SOCKLEN_T
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// HP-UXi has a bug in getaddrinfo(3) that makes it thread-unsafe
end_comment
begin_comment
comment|// with this flag. So disable it in that platform.
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|AI_ADDRCONFIG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_HPUX
argument_list|)
end_if
begin_define
DECL|macro|Q_ADDRCONFIG
define|#
directive|define
name|Q_ADDRCONFIG
value|AI_ADDRCONFIG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|res_state_ptr
typedef|typedef
name|struct
name|__res_state
modifier|*
name|res_state_ptr
typedef|;
end_typedef
begin_typedef
DECL|typedef|res_init_proto
typedef|typedef
name|int
function_decl|(
modifier|*
name|res_init_proto
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|local_res_init
specifier|static
name|res_init_proto
name|local_res_init
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|res_ninit_proto
typedef|typedef
name|int
function_decl|(
modifier|*
name|res_ninit_proto
function_decl|)
parameter_list|(
name|res_state_ptr
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|local_res_ninit
specifier|static
name|res_ninit_proto
name|local_res_ninit
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|res_nclose_proto
typedef|typedef
name|void
function_decl|(
modifier|*
name|res_nclose_proto
function_decl|)
parameter_list|(
name|res_state_ptr
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|local_res_nclose
specifier|static
name|res_nclose_proto
name|local_res_nclose
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|local_res
specifier|static
name|res_state_ptr
name|local_res
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|resolveLibrary
specifier|static
name|void
name|resolveLibrary
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|QLibrary
name|lib
argument_list|(
name|QLatin1String
argument_list|(
literal|"resolv"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|lib
operator|.
name|load
argument_list|()
condition|)
return|return;
name|local_res_init
operator|=
name|res_init_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"__res_init"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_init
condition|)
name|local_res_init
operator|=
name|res_init_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"res_init"
argument_list|)
argument_list|)
expr_stmt|;
name|local_res_ninit
operator|=
name|res_ninit_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"__res_ninit"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_ninit
condition|)
name|local_res_ninit
operator|=
name|res_ninit_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"res_ninit"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_ninit
condition|)
block|{
comment|// if we can't get a thread-safe context, we have to use the global _res state
name|local_res
operator|=
name|res_state_ptr
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"_res"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|local_res_nclose
operator|=
name|res_nclose_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"res_nclose"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_nclose
condition|)
name|local_res_nclose
operator|=
name|res_nclose_proto
argument_list|(
name|lib
operator|.
name|resolve
argument_list|(
literal|"__res_nclose"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|local_res_nclose
condition|)
name|local_res_ninit
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|fromName
name|QHostInfo
name|QHostInfoAgent
operator|::
name|fromName
parameter_list|(
specifier|const
name|QString
modifier|&
name|hostName
parameter_list|)
block|{
name|QHostInfo
name|results
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QHOSTINFO_DEBUG
argument_list|)
name|qDebug
argument_list|(
literal|"QHostInfoAgent::fromName(%s) looking up..."
argument_list|,
name|hostName
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Load res_init on demand.
specifier|static
name|QBasicAtomicInt
name|triedResolve
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|false
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|triedResolve
operator|.
name|loadAcquire
argument_list|()
condition|)
block|{
name|QMutexLocker
name|locker
argument_list|(
name|QMutexPool
operator|::
name|globalInstanceGet
argument_list|(
operator|&
name|local_res_init
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|triedResolve
operator|.
name|load
argument_list|()
condition|)
block|{
name|resolveLibrary
argument_list|()
expr_stmt|;
name|triedResolve
operator|.
name|storeRelease
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
comment|// If res_init is available, poll it.
if|if
condition|(
name|local_res_init
condition|)
name|local_res_init
argument_list|()
expr_stmt|;
name|QHostAddress
name|address
decl_stmt|;
if|if
condition|(
name|address
operator|.
name|setAddress
argument_list|(
name|hostName
argument_list|)
condition|)
block|{
comment|// Reverse lookup
comment|// Reverse lookups using getnameinfo are broken on darwin, use gethostbyaddr instead.
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GETADDRINFO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_DARWIN
argument_list|)
name|sockaddr_in
name|sa4
decl_stmt|;
name|sockaddr_in6
name|sa6
decl_stmt|;
name|sockaddr
modifier|*
name|sa
init|=
literal|0
decl_stmt|;
name|QT_SOCKLEN_T
name|saSize
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|address
operator|.
name|protocol
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|IPv4Protocol
condition|)
block|{
name|sa
operator|=
operator|(
name|sockaddr
operator|*
operator|)
operator|&
name|sa4
expr_stmt|;
name|saSize
operator|=
sizeof|sizeof
argument_list|(
name|sa4
argument_list|)
expr_stmt|;
name|memset
argument_list|(
operator|&
name|sa4
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|sa4
argument_list|)
argument_list|)
expr_stmt|;
name|sa4
operator|.
name|sin_family
operator|=
name|AF_INET
expr_stmt|;
name|sa4
operator|.
name|sin_addr
operator|.
name|s_addr
operator|=
name|htonl
argument_list|(
name|address
operator|.
name|toIPv4Address
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sa
operator|=
operator|(
name|sockaddr
operator|*
operator|)
operator|&
name|sa6
expr_stmt|;
name|saSize
operator|=
sizeof|sizeof
argument_list|(
name|sa6
argument_list|)
expr_stmt|;
name|memset
argument_list|(
operator|&
name|sa6
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|sa6
argument_list|)
argument_list|)
expr_stmt|;
name|sa6
operator|.
name|sin6_family
operator|=
name|AF_INET6
expr_stmt|;
name|memcpy
argument_list|(
name|sa6
operator|.
name|sin6_addr
operator|.
name|s6_addr
argument_list|,
name|address
operator|.
name|toIPv6Address
argument_list|()
operator|.
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|sa6
operator|.
name|sin6_addr
operator|.
name|s6_addr
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|char
name|hbuf
index|[
name|NI_MAXHOST
index|]
decl_stmt|;
if|if
condition|(
name|sa
operator|&&
name|getnameinfo
argument_list|(
name|sa
argument_list|,
name|saSize
argument_list|,
name|hbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|hbuf
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
condition|)
name|results
operator|.
name|setHostName
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|hbuf
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|in_addr_t
name|inetaddr
init|=
name|qt_safe_inet_addr
argument_list|(
name|hostName
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
name|struct
name|hostent
modifier|*
name|ent
init|=
name|gethostbyaddr
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
operator|&
name|inetaddr
argument_list|,
sizeof|sizeof
argument_list|(
name|inetaddr
argument_list|)
argument_list|,
name|AF_INET
argument_list|)
decl_stmt|;
if|if
condition|(
name|ent
condition|)
name|results
operator|.
name|setHostName
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|ent
operator|->
name|h_name
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|results
operator|.
name|hostName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|results
operator|.
name|setHostName
argument_list|(
name|address
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|results
operator|.
name|setAddresses
argument_list|(
name|QList
argument_list|<
name|QHostAddress
argument_list|>
argument_list|()
operator|<<
name|address
argument_list|)
expr_stmt|;
return|return
name|results
return|;
block|}
comment|// IDN support
name|QByteArray
name|aceHostname
init|=
name|QUrl
operator|::
name|toAce
argument_list|(
name|hostName
argument_list|)
decl_stmt|;
name|results
operator|.
name|setHostName
argument_list|(
name|hostName
argument_list|)
expr_stmt|;
if|if
condition|(
name|aceHostname
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|results
operator|.
name|setError
argument_list|(
name|QHostInfo
operator|::
name|HostNotFound
argument_list|)
expr_stmt|;
name|results
operator|.
name|setErrorString
argument_list|(
name|hostName
operator|.
name|isEmpty
argument_list|()
condition|?
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QHostInfoAgent"
argument_list|,
literal|"No host name given"
argument_list|)
else|:
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QHostInfoAgent"
argument_list|,
literal|"Invalid hostname"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|results
return|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GETADDRINFO
argument_list|)
comment|// Call getaddrinfo, and place all IPv4 addresses at the start and
comment|// the IPv6 addresses at the end of the address list in results.
name|addrinfo
modifier|*
name|res
init|=
literal|0
decl_stmt|;
name|struct
name|addrinfo
name|hints
decl_stmt|;
name|memset
argument_list|(
operator|&
name|hints
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|hints
argument_list|)
argument_list|)
expr_stmt|;
name|hints
operator|.
name|ai_family
operator|=
name|PF_UNSPEC
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_ADDRCONFIG
name|hints
operator|.
name|ai_flags
operator|=
name|Q_ADDRCONFIG
expr_stmt|;
endif|#
directive|endif
name|int
name|result
init|=
name|getaddrinfo
argument_list|(
name|aceHostname
operator|.
name|constData
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|&
name|hints
argument_list|,
operator|&
name|res
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_ADDRCONFIG
if|if
condition|(
name|result
operator|==
name|EAI_BADFLAGS
condition|)
block|{
comment|// if the lookup failed with AI_ADDRCONFIG set, try again without it
name|hints
operator|.
name|ai_flags
operator|=
literal|0
expr_stmt|;
name|result
operator|=
name|getaddrinfo
argument_list|(
name|aceHostname
operator|.
name|constData
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|&
name|hints
argument_list|,
operator|&
name|res
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|result
operator|==
literal|0
condition|)
block|{
name|addrinfo
modifier|*
name|node
init|=
name|res
decl_stmt|;
name|QList
argument_list|<
name|QHostAddress
argument_list|>
name|addresses
decl_stmt|;
while|while
condition|(
name|node
condition|)
block|{
ifdef|#
directive|ifdef
name|QHOSTINFO_DEBUG
name|qDebug
argument_list|()
operator|<<
literal|"getaddrinfo node: flags:"
operator|<<
name|node
operator|->
name|ai_flags
operator|<<
literal|"family:"
operator|<<
name|node
operator|->
name|ai_family
operator|<<
literal|"ai_socktype:"
operator|<<
name|node
operator|->
name|ai_socktype
operator|<<
literal|"ai_protocol:"
operator|<<
name|node
operator|->
name|ai_protocol
operator|<<
literal|"ai_addrlen:"
operator|<<
name|node
operator|->
name|ai_addrlen
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|node
operator|->
name|ai_family
operator|==
name|AF_INET
condition|)
block|{
name|QHostAddress
name|addr
decl_stmt|;
name|addr
operator|.
name|setAddress
argument_list|(
name|ntohl
argument_list|(
operator|(
operator|(
name|sockaddr_in
operator|*
operator|)
name|node
operator|->
name|ai_addr
operator|)
operator|->
name|sin_addr
operator|.
name|s_addr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|addresses
operator|.
name|contains
argument_list|(
name|addr
argument_list|)
condition|)
name|addresses
operator|.
name|append
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|node
operator|->
name|ai_family
operator|==
name|AF_INET6
condition|)
block|{
name|QHostAddress
name|addr
decl_stmt|;
name|sockaddr_in6
modifier|*
name|sa6
init|=
operator|(
name|sockaddr_in6
operator|*
operator|)
name|node
operator|->
name|ai_addr
decl_stmt|;
name|addr
operator|.
name|setAddress
argument_list|(
name|sa6
operator|->
name|sin6_addr
operator|.
name|s6_addr
argument_list|)
expr_stmt|;
if|if
condition|(
name|sa6
operator|->
name|sin6_scope_id
condition|)
name|addr
operator|.
name|setScopeId
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|sa6
operator|->
name|sin6_scope_id
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|addresses
operator|.
name|contains
argument_list|(
name|addr
argument_list|)
condition|)
name|addresses
operator|.
name|append
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
name|node
operator|=
name|node
operator|->
name|ai_next
expr_stmt|;
block|}
if|if
condition|(
name|addresses
operator|.
name|isEmpty
argument_list|()
operator|&&
name|node
operator|==
literal|0
condition|)
block|{
comment|// Reached the end of the list, but no addresses were found; this
comment|// means the list contains one or more unknown address types.
name|results
operator|.
name|setError
argument_list|(
name|QHostInfo
operator|::
name|UnknownError
argument_list|)
expr_stmt|;
name|results
operator|.
name|setErrorString
argument_list|(
name|tr
argument_list|(
literal|"Unknown address type"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|results
operator|.
name|setAddresses
argument_list|(
name|addresses
argument_list|)
expr_stmt|;
name|freeaddrinfo
argument_list|(
name|res
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|result
operator|==
name|EAI_NONAME
operator|||
name|result
operator|==
name|EAI_FAIL
ifdef|#
directive|ifdef
name|EAI_NODATA
comment|// EAI_NODATA is deprecated in RFC 3493
operator|||
name|result
operator|==
name|EAI_NODATA
endif|#
directive|endif
condition|)
block|{
name|results
operator|.
name|setError
argument_list|(
name|QHostInfo
operator|::
name|HostNotFound
argument_list|)
expr_stmt|;
name|results
operator|.
name|setErrorString
argument_list|(
name|tr
argument_list|(
literal|"Host not found"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|results
operator|.
name|setError
argument_list|(
name|QHostInfo
operator|::
name|UnknownError
argument_list|)
expr_stmt|;
name|results
operator|.
name|setErrorString
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|gai_strerror
argument_list|(
name|result
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|// Fall back to gethostbyname for platforms that don't define
comment|// getaddrinfo. gethostbyname does not support IPv6, and it's not
comment|// reentrant on all platforms. For now this is okay since we only
comment|// use one QHostInfoAgent, but if more agents are introduced, locking
comment|// must be provided.
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|getHostByNameMutex
argument_list|)
decl_stmt|;
name|hostent
modifier|*
name|result
init|=
name|gethostbyname
argument_list|(
name|aceHostname
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
condition|)
block|{
if|if
condition|(
name|result
operator|->
name|h_addrtype
operator|==
name|AF_INET
condition|)
block|{
name|QList
argument_list|<
name|QHostAddress
argument_list|>
name|addresses
decl_stmt|;
for|for
control|(
name|char
modifier|*
modifier|*
name|p
init|=
name|result
operator|->
name|h_addr_list
init|;
operator|*
name|p
operator|!=
literal|0
condition|;
name|p
operator|++
control|)
block|{
name|QHostAddress
name|addr
decl_stmt|;
name|addr
operator|.
name|setAddress
argument_list|(
name|ntohl
argument_list|(
operator|*
operator|(
operator|(
name|quint32
operator|*
operator|)
operator|*
name|p
operator|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|addresses
operator|.
name|contains
argument_list|(
name|addr
argument_list|)
condition|)
name|addresses
operator|.
name|prepend
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
name|results
operator|.
name|setAddresses
argument_list|(
name|addresses
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|results
operator|.
name|setError
argument_list|(
name|QHostInfo
operator|::
name|UnknownError
argument_list|)
expr_stmt|;
name|results
operator|.
name|setErrorString
argument_list|(
name|tr
argument_list|(
literal|"Unknown address type"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
block|}
elseif|else
if|if
condition|(
name|h_errno
operator|==
name|HOST_NOT_FOUND
operator|||
name|h_errno
operator|==
name|NO_DATA
operator|||
name|h_errno
operator|==
name|NO_ADDRESS
condition|)
block|{
name|results
operator|.
name|setError
argument_list|(
name|QHostInfo
operator|::
name|HostNotFound
argument_list|)
expr_stmt|;
name|results
operator|.
name|setErrorString
argument_list|(
name|tr
argument_list|(
literal|"Host not found"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
name|results
operator|.
name|setError
argument_list|(
name|QHostInfo
operator|::
name|UnknownError
argument_list|)
expr_stmt|;
name|results
operator|.
name|setErrorString
argument_list|(
name|tr
argument_list|(
literal|"Unknown error"
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|//  !defined (QT_NO_GETADDRINFO)
if|#
directive|if
name|defined
argument_list|(
name|QHOSTINFO_DEBUG
argument_list|)
if|if
condition|(
name|results
operator|.
name|error
argument_list|()
operator|!=
name|QHostInfo
operator|::
name|NoError
condition|)
block|{
name|qDebug
argument_list|(
literal|"QHostInfoAgent::fromName(): error #%d %s"
argument_list|,
name|h_errno
argument_list|,
name|results
operator|.
name|errorString
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QString
name|tmp
decl_stmt|;
name|QList
argument_list|<
name|QHostAddress
argument_list|>
name|addresses
init|=
name|results
operator|.
name|addresses
argument_list|()
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
name|addresses
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|!=
literal|0
condition|)
name|tmp
operator|+=
literal|", "
expr_stmt|;
name|tmp
operator|+=
name|addresses
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
name|qDebug
argument_list|(
literal|"QHostInfoAgent::fromName(): found %i entries for \"%s\": {%s}"
argument_list|,
name|addresses
operator|.
name|count
argument_list|()
argument_list|,
name|hostName
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|tmp
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|results
return|;
block|}
end_function
begin_function
DECL|function|localHostName
name|QString
name|QHostInfo
operator|::
name|localHostName
parameter_list|()
block|{
name|char
name|hostName
index|[
literal|512
index|]
decl_stmt|;
if|if
condition|(
name|gethostname
argument_list|(
name|hostName
argument_list|,
sizeof|sizeof
argument_list|(
name|hostName
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
name|QString
argument_list|()
return|;
name|hostName
index|[
sizeof|sizeof
argument_list|(
name|hostName
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|hostName
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|localDomainName
name|QString
name|QHostInfo
operator|::
name|localDomainName
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_LINUX_ANDROID
argument_list|)
name|resolveLibrary
argument_list|()
expr_stmt|;
if|if
condition|(
name|local_res_ninit
condition|)
block|{
comment|// using thread-safe version
name|res_state_ptr
name|state
init|=
name|res_state_ptr
argument_list|(
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|state
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|state
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|state
argument_list|)
argument_list|)
expr_stmt|;
name|local_res_ninit
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|QString
name|domainName
init|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|state
operator|->
name|defdname
argument_list|)
decl_stmt|;
if|if
condition|(
name|domainName
operator|.
name|isEmpty
argument_list|()
condition|)
name|domainName
operator|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|state
operator|->
name|dnsrch
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|local_res_nclose
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|state
argument_list|)
expr_stmt|;
return|return
name|domainName
return|;
block|}
if|if
condition|(
name|local_res_init
operator|&&
name|local_res
condition|)
block|{
comment|// using thread-unsafe version
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_GETADDRINFO
argument_list|)
comment|// We have to call res_init to be sure that _res was initialized
comment|// So, for systems without getaddrinfo (which is thread-safe), we lock the mutex too
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|getHostByNameMutex
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|local_res_init
argument_list|()
expr_stmt|;
name|QString
name|domainName
init|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|local_res
operator|->
name|defdname
argument_list|)
decl_stmt|;
if|if
condition|(
name|domainName
operator|.
name|isEmpty
argument_list|()
condition|)
name|domainName
operator|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|local_res
operator|->
name|dnsrch
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
name|domainName
return|;
block|}
endif|#
directive|endif
comment|// nothing worked, try doing it by ourselves:
name|QFile
name|resolvconf
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_PATH_RESCONF
argument_list|)
name|resolvconf
operator|.
name|setFileName
argument_list|(
name|QFile
operator|::
name|decodeName
argument_list|(
name|_PATH_RESCONF
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|resolvconf
operator|.
name|setFileName
argument_list|(
name|QLatin1String
argument_list|(
literal|"/etc/resolv.conf"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|resolvconf
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return
name|QString
argument_list|()
return|;
comment|// failure
name|QString
name|domainName
decl_stmt|;
while|while
condition|(
operator|!
name|resolvconf
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
init|=
name|resolvconf
operator|.
name|readLine
argument_list|()
operator|.
name|trimmed
argument_list|()
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|"domain "
argument_list|)
condition|)
return|return
name|QUrl
operator|::
name|fromAce
argument_list|(
name|line
operator|.
name|mid
argument_list|(
sizeof|sizeof
expr|"domain "
operator|-
literal|1
argument_list|)
operator|.
name|trimmed
argument_list|()
argument_list|)
return|;
comment|// in case there's no "domain" line, fall back to the first "search" entry
if|if
condition|(
name|domainName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|line
operator|.
name|startsWith
argument_list|(
literal|"search "
argument_list|)
condition|)
block|{
name|QByteArray
name|searchDomain
init|=
name|line
operator|.
name|mid
argument_list|(
sizeof|sizeof
expr|"search "
operator|-
literal|1
argument_list|)
operator|.
name|trimmed
argument_list|()
decl_stmt|;
name|int
name|pos
init|=
name|searchDomain
operator|.
name|indexOf
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos
operator|!=
operator|-
literal|1
condition|)
name|searchDomain
operator|.
name|truncate
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|domainName
operator|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|searchDomain
argument_list|)
expr_stmt|;
block|}
block|}
comment|// return the fallen-back-to searched domain
return|return
name|domainName
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
