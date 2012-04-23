begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkproxy.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_comment
comment|/*  * Construct a proxy from the environment variables http_proxy and no_proxy.  * Or no system proxy. Just return a list with NoProxy.  */
end_comment
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|ignoreProxyFor
specifier|static
name|bool
name|ignoreProxyFor
parameter_list|(
specifier|const
name|QNetworkProxyQuery
modifier|&
name|query
parameter_list|)
block|{
specifier|const
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|noProxyTokens
init|=
name|qgetenv
argument_list|(
literal|"no_proxy"
argument_list|)
operator|.
name|split
argument_list|(
literal|','
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QByteArray
name|rawToken
decl|,
name|noProxyTokens
control|)
block|{
name|QByteArray
name|token
init|=
name|rawToken
operator|.
name|trimmed
argument_list|()
decl_stmt|;
name|QString
name|peerHostName
init|=
name|query
operator|.
name|peerHostName
argument_list|()
decl_stmt|;
comment|// Since we use suffix matching, "*" is our 'default' behaviour
if|if
condition|(
name|token
operator|.
name|startsWith
argument_list|(
literal|"*"
argument_list|)
condition|)
name|token
operator|=
name|token
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// Harmonize trailing dot notation
if|if
condition|(
name|token
operator|.
name|endsWith
argument_list|(
literal|'.'
argument_list|)
operator|&&
operator|!
name|peerHostName
operator|.
name|endsWith
argument_list|(
literal|'.'
argument_list|)
condition|)
name|token
operator|=
name|token
operator|.
name|left
argument_list|(
name|token
operator|.
name|length
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// We prepend a dot to both values, so that when we do a suffix match,
comment|// we don't match "donotmatch.com" with "match.com"
if|if
condition|(
operator|!
name|token
operator|.
name|startsWith
argument_list|(
literal|'.'
argument_list|)
condition|)
name|token
operator|.
name|prepend
argument_list|(
literal|'.'
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|peerHostName
operator|.
name|startsWith
argument_list|(
literal|'.'
argument_list|)
condition|)
name|peerHostName
operator|.
name|prepend
argument_list|(
literal|'.'
argument_list|)
expr_stmt|;
if|if
condition|(
name|peerHostName
operator|.
name|endsWith
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|token
argument_list|)
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|systemProxyForQuery
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
parameter_list|(
specifier|const
name|QNetworkProxyQuery
modifier|&
name|query
parameter_list|)
block|{
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|proxyList
decl_stmt|;
if|if
condition|(
name|ignoreProxyFor
argument_list|(
name|query
argument_list|)
condition|)
return|return
name|proxyList
operator|<<
name|QNetworkProxy
operator|::
name|NoProxy
return|;
name|QByteArray
name|proxy_env
init|=
name|qgetenv
argument_list|(
literal|"http_proxy"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|proxy_env
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QUrl
name|url
init|=
name|QUrl
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|proxy_env
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"socks5"
argument_list|)
condition|)
block|{
name|QNetworkProxy
name|proxy
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|,
name|url
operator|.
name|host
argument_list|()
argument_list|,
name|url
operator|.
name|port
argument_list|()
condition|?
name|url
operator|.
name|port
argument_list|()
else|:
literal|1080
argument_list|,
name|url
operator|.
name|userName
argument_list|()
argument_list|,
name|url
operator|.
name|password
argument_list|()
argument_list|)
decl_stmt|;
name|proxyList
operator|<<
name|proxy
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"socks5h"
argument_list|)
condition|)
block|{
name|QNetworkProxy
name|proxy
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|,
name|url
operator|.
name|host
argument_list|()
argument_list|,
name|url
operator|.
name|port
argument_list|()
condition|?
name|url
operator|.
name|port
argument_list|()
else|:
literal|1080
argument_list|,
name|url
operator|.
name|userName
argument_list|()
argument_list|,
name|url
operator|.
name|password
argument_list|()
argument_list|)
decl_stmt|;
name|proxy
operator|.
name|setCapabilities
argument_list|(
name|QNetworkProxy
operator|::
name|HostNameLookupCapability
argument_list|)
expr_stmt|;
name|proxyList
operator|<<
name|proxy
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|url
operator|.
name|scheme
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"http"
argument_list|)
operator|||
name|url
operator|.
name|scheme
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QNetworkProxy
name|proxy
argument_list|(
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|,
name|url
operator|.
name|host
argument_list|()
argument_list|,
name|url
operator|.
name|port
argument_list|()
condition|?
name|url
operator|.
name|port
argument_list|()
else|:
literal|8080
argument_list|,
name|url
operator|.
name|userName
argument_list|()
argument_list|,
name|url
operator|.
name|password
argument_list|()
argument_list|)
decl_stmt|;
name|proxyList
operator|<<
name|proxy
expr_stmt|;
block|}
block|}
if|if
condition|(
name|proxyList
operator|.
name|isEmpty
argument_list|()
condition|)
name|proxyList
operator|<<
name|QNetworkProxy
operator|::
name|NoProxy
expr_stmt|;
return|return
name|proxyList
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
end_unit
