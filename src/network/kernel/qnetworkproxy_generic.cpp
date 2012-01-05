begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
comment|/*  * Construct a proxy from the environment variable http_proxy.  * Or no system proxy. Just return a list with NoProxy.  */
end_comment
begin_function
name|QT_BEGIN_NAMESPACE
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
parameter_list|)
block|{
name|QList
argument_list|<
name|QNetworkProxy
argument_list|>
name|proxyList
decl_stmt|;
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
