begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QString>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NETWORK_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtNetwork/QHostInfo>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
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
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QtNetworkSettings
block|{
name|public
label|:
specifier|static
name|QString
name|serverLocalName
parameter_list|()
block|{
return|return
name|QString
argument_list|(
literal|"qt-test-server"
argument_list|)
return|;
block|}
specifier|static
name|QString
name|serverDomainName
parameter_list|()
block|{
return|return
name|QString
argument_list|(
literal|"qt-test-net"
argument_list|)
return|;
block|}
specifier|static
name|QString
name|serverName
parameter_list|()
block|{
return|return
name|serverLocalName
argument_list|()
operator|+
literal|"."
operator|+
name|serverDomainName
argument_list|()
return|;
block|}
specifier|static
name|QString
name|winServerName
parameter_list|()
block|{
return|return
name|serverName
argument_list|()
return|;
block|}
specifier|static
name|QString
name|wildcardServerName
parameter_list|()
block|{
return|return
literal|"qt-test-server.wildcard.dev."
operator|+
name|serverDomainName
argument_list|()
return|;
block|}
ifdef|#
directive|ifdef
name|QT_NETWORK_LIB
specifier|static
name|QHostAddress
name|serverIP
parameter_list|()
block|{
specifier|const
name|QHostInfo
name|info
init|=
name|QHostInfo
operator|::
name|fromName
argument_list|(
name|serverName
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|info
operator|.
name|error
argument_list|()
condition|)
block|{
name|QTest
operator|::
name|qFail
argument_list|(
name|qPrintable
argument_list|(
name|info
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
return|return
name|QHostAddress
argument_list|()
return|;
block|}
return|return
name|info
operator|.
name|addresses
argument_list|()
operator|.
name|constFirst
argument_list|()
return|;
block|}
endif|#
directive|endif
specifier|static
name|bool
name|compareReplyIMAP
parameter_list|(
name|QByteArray
specifier|const
modifier|&
name|actual
parameter_list|)
block|{
comment|// Server greeting may contain capability, version and server name
comment|// But spec only requires "* OK" and "\r\n"
comment|// Match against a prefix and postfix that covers all Cyrus versions
if|if
condition|(
name|actual
operator|.
name|startsWith
argument_list|(
literal|"* OK "
argument_list|)
operator|&&
name|actual
operator|.
name|endsWith
argument_list|(
literal|"server ready\r\n"
argument_list|)
condition|)
block|{
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
specifier|static
name|bool
name|compareReplyIMAPSSL
parameter_list|(
name|QByteArray
specifier|const
modifier|&
name|actual
parameter_list|)
block|{
return|return
name|compareReplyIMAP
argument_list|(
name|actual
argument_list|)
return|;
block|}
specifier|static
name|bool
name|compareReplyFtp
parameter_list|(
name|QByteArray
specifier|const
modifier|&
name|actual
parameter_list|)
block|{
comment|// output would be e.g. "220 (vsFTPd 2.3.5)\r\n221 Goodbye.\r\n"
name|QRegExp
name|ftpVersion
argument_list|(
name|QStringLiteral
argument_list|(
literal|"220 \\(vsFTPd \\d+\\.\\d+.\\d+\\)\\r\\n221 Goodbye.\\r\\n"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|ftpVersion
operator|.
name|exactMatch
argument_list|(
name|actual
argument_list|)
return|;
block|}
specifier|static
name|bool
name|hasIPv6
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_UNIX
name|int
name|s
init|=
operator|::
name|socket
argument_list|(
name|AF_INET6
argument_list|,
name|SOCK_DGRAM
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|s
operator|==
operator|-
literal|1
condition|)
return|return
name|false
return|;
else|else
block|{
name|struct
name|sockaddr_in6
name|addr
decl_stmt|;
name|memset
argument_list|(
operator|&
name|addr
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|addr
argument_list|)
argument_list|)
expr_stmt|;
name|addr
operator|.
name|sin6_family
operator|=
name|AF_INET6
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|addr
operator|.
name|sin6_addr
argument_list|,
operator|&
name|in6addr_loopback
argument_list|,
sizeof|sizeof
argument_list|(
name|in6_addr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
operator|::
name|bind
argument_list|(
name|s
argument_list|,
operator|(
name|sockaddr
operator|*
operator|)
operator|&
name|addr
argument_list|,
sizeof|sizeof
argument_list|(
name|addr
argument_list|)
argument_list|)
condition|)
block|{
operator|::
name|close
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
block|}
operator|::
name|close
argument_list|(
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|true
return|;
block|}
ifdef|#
directive|ifdef
name|QT_NETWORK_LIB
specifier|static
name|bool
name|verifyTestNetworkSettings
parameter_list|()
block|{
name|QHostInfo
name|testServerResult
init|=
name|QHostInfo
operator|::
name|fromName
argument_list|(
name|QtNetworkSettings
operator|::
name|serverName
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|testServerResult
operator|.
name|error
argument_list|()
operator|!=
name|QHostInfo
operator|::
name|NoError
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Could not lookup"
operator|<<
name|QtNetworkSettings
operator|::
name|serverName
argument_list|()
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"Please configure the test environment!"
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"See /etc/hosts or network-settings.h"
expr_stmt|;
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
end_unit
