begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNET_UNIX_P_H
end_ifndef
begin_define
DECL|macro|QNET_UNIX_P_H
define|#
directive|define
name|QNET_UNIX_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of Qt code on Unix. This header file may change from version to
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"private/qcore_unix_p.h"
end_include
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
begin_include
include|#
directive|include
file|<netinet/in.h>
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
file|<sockLib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// for inet_addr
end_comment
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
begin_function
name|QT_BEGIN_NAMESPACE
comment|// Almost always the same. If not, specify in qplatformdefs.h.
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_SOCKOPTLEN_T
argument_list|)
DECL|macro|QT_SOCKOPTLEN_T
define|#
directive|define
name|QT_SOCKOPTLEN_T
value|QT_SOCKLEN_T
endif|#
directive|endif
comment|// UnixWare 7 redefines socket -> _socket
DECL|function|qt_safe_socket
specifier|static
specifier|inline
name|int
name|qt_safe_socket
parameter_list|(
name|int
name|domain
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|protocol
parameter_list|,
name|int
name|flags
init|=
literal|0
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|(
name|flags
operator|&
operator|~
name|O_NONBLOCK
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
specifier|register
name|int
name|fd
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SOCK_CLOEXEC
argument_list|)
operator|&&
name|defined
argument_list|(
name|SOCK_NONBLOCK
argument_list|)
name|int
name|newtype
init|=
name|type
operator||
name|SOCK_CLOEXEC
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|O_NONBLOCK
condition|)
name|newtype
operator||=
name|SOCK_NONBLOCK
expr_stmt|;
name|fd
operator|=
operator|::
name|socket
argument_list|(
name|domain
argument_list|,
name|newtype
argument_list|,
name|protocol
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
operator|||
name|errno
operator|!=
name|EINVAL
condition|)
return|return
name|fd
return|;
endif|#
directive|endif
name|fd
operator|=
operator|::
name|socket
argument_list|(
name|domain
argument_list|,
name|type
argument_list|,
name|protocol
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
operator|::
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
expr_stmt|;
comment|// set non-block too?
if|if
condition|(
name|flags
operator|&
name|O_NONBLOCK
condition|)
operator|::
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFL
argument_list|,
operator|::
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_GETFL
argument_list|)
operator||
name|O_NONBLOCK
argument_list|)
expr_stmt|;
return|return
name|fd
return|;
block|}
end_function
begin_comment
comment|// Tru64 redefines accept -> _accept with _XOPEN_SOURCE_EXTENDED
end_comment
begin_function
DECL|function|qt_safe_accept
specifier|static
specifier|inline
name|int
name|qt_safe_accept
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|QT_SOCKLEN_T
modifier|*
name|addrlen
parameter_list|,
name|int
name|flags
init|=
literal|0
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|(
name|flags
operator|&
operator|~
name|O_NONBLOCK
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
specifier|register
name|int
name|fd
decl_stmt|;
if|#
directive|if
name|QT_UNIX_SUPPORTS_THREADSAFE_CLOEXEC
operator|&&
name|defined
argument_list|(
name|SOCK_CLOEXEC
argument_list|)
operator|&&
name|defined
argument_list|(
name|SOCK_NONBLOCK
argument_list|)
comment|// use accept4
name|int
name|sockflags
init|=
name|SOCK_CLOEXEC
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|O_NONBLOCK
condition|)
name|sockflags
operator||=
name|SOCK_NONBLOCK
expr_stmt|;
name|fd
operator|=
operator|::
name|accept4
argument_list|(
name|s
argument_list|,
name|addr
argument_list|,
name|static_cast
operator|<
name|QT_SOCKLEN_T
operator|*
operator|>
operator|(
name|addrlen
operator|)
argument_list|,
name|sockflags
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
operator|||
operator|!
operator|(
name|errno
operator|==
name|ENOSYS
operator|||
name|errno
operator|==
name|EINVAL
operator|)
condition|)
return|return
name|fd
return|;
endif|#
directive|endif
name|fd
operator|=
operator|::
name|accept
argument_list|(
name|s
argument_list|,
name|addr
argument_list|,
name|static_cast
operator|<
name|QT_SOCKLEN_T
operator|*
operator|>
operator|(
name|addrlen
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
operator|::
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
expr_stmt|;
comment|// set non-block too?
if|if
condition|(
name|flags
operator|&
name|O_NONBLOCK
condition|)
operator|::
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFL
argument_list|,
operator|::
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_GETFL
argument_list|)
operator||
name|O_NONBLOCK
argument_list|)
expr_stmt|;
return|return
name|fd
return|;
block|}
end_function
begin_comment
comment|// UnixWare 7 redefines listen -> _listen
end_comment
begin_function
DECL|function|qt_safe_listen
specifier|static
specifier|inline
name|int
name|qt_safe_listen
parameter_list|(
name|int
name|s
parameter_list|,
name|int
name|backlog
parameter_list|)
block|{
return|return
operator|::
name|listen
argument_list|(
name|s
argument_list|,
name|backlog
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_safe_connect
specifier|static
specifier|inline
name|int
name|qt_safe_connect
parameter_list|(
name|int
name|sockfd
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|QT_SOCKLEN_T
name|addrlen
parameter_list|)
block|{
specifier|register
name|int
name|ret
decl_stmt|;
comment|// Solaris e.g. expects a non-const 2nd parameter
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|QT_SOCKET_CONNECT
argument_list|(
name|sockfd
argument_list|,
name|const_cast
operator|<
expr|struct
name|sockaddr
operator|*
operator|>
operator|(
name|addr
operator|)
argument_list|,
name|addrlen
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_undef
DECL|macro|QT_SOCKET_CONNECT
undef|#
directive|undef
name|QT_SOCKET_CONNECT
end_undef
begin_define
DECL|macro|QT_SOCKET_CONNECT
define|#
directive|define
name|QT_SOCKET_CONNECT
value|qt_safe_connect
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|socket
argument_list|)
end_if
begin_undef
DECL|macro|socket
undef|#
directive|undef
name|socket
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|accept
argument_list|)
end_if
begin_undef
DECL|macro|accept
undef|#
directive|undef
name|accept
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|listen
argument_list|)
end_if
begin_undef
DECL|macro|listen
undef|#
directive|undef
name|listen
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// VxWorks' headers specify 'int' instead of '...' for the 3rd ioctl() parameter.
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qt_safe_ioctl
specifier|static
specifier|inline
name|int
name|qt_safe_ioctl
argument_list|(
argument|int sockfd
argument_list|,
argument|int request
argument_list|,
argument|T arg
argument_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_VXWORKS
return|return
operator|::
name|ioctl
argument_list|(
name|sockfd
argument_list|,
name|request
argument_list|,
operator|(
name|int
operator|)
name|arg
argument_list|)
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
operator|::
name|ioctl
argument_list|(
name|sockfd
argument_list|,
name|request
argument_list|,
name|arg
argument_list|)
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_comment
unit|}
comment|// VxWorks' headers do not specify any const modifiers
end_comment
begin_function
unit|static
DECL|function|qt_safe_inet_addr
specifier|inline
name|in_addr_t
name|qt_safe_inet_addr
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_VXWORKS
return|return
operator|::
name|inet_addr
argument_list|(
operator|(
name|char
operator|*
operator|)
name|cp
argument_list|)
return|;
else|#
directive|else
return|return
operator|::
name|inet_addr
argument_list|(
name|cp
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|// VxWorks' headers do not specify any const modifiers
end_comment
begin_function
DECL|function|qt_safe_sendto
specifier|static
specifier|inline
name|int
name|qt_safe_sendto
parameter_list|(
name|int
name|sockfd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|to
parameter_list|,
name|QT_SOCKLEN_T
name|tolen
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|MSG_NOSIGNAL
name|flags
operator||=
name|MSG_NOSIGNAL
expr_stmt|;
endif|#
directive|endif
specifier|register
name|int
name|ret
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_VXWORKS
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|sendto
argument_list|(
name|sockfd
argument_list|,
operator|(
name|char
operator|*
operator|)
name|buf
argument_list|,
name|len
argument_list|,
name|flags
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
name|to
argument_list|,
name|tolen
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|sendto
argument_list|(
name|sockfd
argument_list|,
name|buf
argument_list|,
name|len
argument_list|,
name|flags
argument_list|,
name|to
argument_list|,
name|tolen
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|ret
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
comment|// QNET_UNIX_P_H
end_comment
end_unit
