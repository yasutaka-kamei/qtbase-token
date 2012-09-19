begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qget.h"
end_include
begin_include
include|#
directive|include
file|<QNetworkProxy>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QNetworkConfiguration>
end_include
begin_include
include|#
directive|include
file|<QNetworkConfigurationManager>
end_include
begin_include
include|#
directive|include
file|<QNetworkSession>
end_include
begin_function
DECL|function|printShortUsage
name|void
name|printShortUsage
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
operator|<<
literal|" [options] [list of urls]"
operator|<<
name|endl
operator|<<
literal|"Get one or more urls using QNetworkAccessManager"
operator|<<
name|endl
operator|<<
literal|"--help to display detailed usage"
operator|<<
name|endl
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printUsage
name|void
name|printUsage
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
operator|<<
literal|" [options] [list of urls]"
operator|<<
name|endl
operator|<<
literal|"Get one or more urls using QNetworkAccessManager"
operator|<<
name|endl
operator|<<
literal|"Options:"
operator|<<
literal|"--help                             This message"
operator|<<
name|endl
operator|<<
literal|"--user=<username>                  Set username to use for authentication"
operator|<<
name|endl
operator|<<
literal|"--password=<password>              Set password to use for authentication"
operator|<<
name|endl
operator|<<
literal|"--proxy-user=<username>            Set username to use for proxy authentication"
operator|<<
name|endl
operator|<<
literal|"--proxy-password=<password>        Set password to use for proxy authentication"
operator|<<
name|endl
operator|<<
literal|"--proxy=on                         Use system proxy (default)"
operator|<<
name|endl
operator|<<
literal|"--proxy=off                        Don't use system proxy"
operator|<<
name|endl
operator|<<
literal|"--proxy=<host:port>[,type]         Use specified proxy"
operator|<<
name|endl
operator|<<
literal|"                   ,http           HTTP proxy (default)"
operator|<<
name|endl
operator|<<
literal|"                   ,socks          SOCKS5 proxy"
operator|<<
name|endl
operator|<<
literal|"                   ,ftp            FTP proxy"
operator|<<
name|endl
operator|<<
literal|"                   ,httpcaching    HTTP caching proxy (no CONNECT method)"
operator|<<
name|endl
operator|<<
literal|"--headers=filename                 Set request headers from file contents"
operator|<<
name|endl
operator|<<
literal|"--post=filename                    upload the file to the next url using HTTP POST"
operator|<<
name|endl
operator|<<
literal|"--put=filename                     upload the file to the next url using HTTP PUT"
operator|<<
name|endl
operator|<<
literal|"--content-type=<MIME>              set content-type header for upload"
operator|<<
name|endl
operator|<<
literal|"--serial                           don't run requests in parallel"
operator|<<
name|endl
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|printShortUsage
argument_list|()
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
comment|//use system proxy (by default)
name|QNetworkProxyFactory
operator|::
name|setUseSystemConfiguration
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|DownloadManager
name|dl
decl_stmt|;
name|QString
name|uploadFileName
decl_stmt|;
name|QString
name|contentType
decl_stmt|;
name|QString
name|httpUser
decl_stmt|;
name|QString
name|httpPassword
decl_stmt|;
name|QString
name|headersFile
decl_stmt|;
name|TransferItem
operator|::
name|Method
name|method
init|=
name|TransferItem
operator|::
name|Get
decl_stmt|;
comment|//arguments match wget where possible
foreach|foreach
control|(
name|QString
name|str
decl|,
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
control|)
block|{
if|if
condition|(
name|str
operator|==
literal|"--help"
condition|)
name|printUsage
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--user="
argument_list|)
condition|)
name|httpUser
operator|=
name|str
operator|.
name|mid
argument_list|(
literal|7
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--password="
argument_list|)
condition|)
name|httpPassword
operator|=
name|str
operator|.
name|mid
argument_list|(
literal|11
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--proxy-user="
argument_list|)
condition|)
name|dl
operator|.
name|setProxyUser
argument_list|(
name|str
operator|.
name|mid
argument_list|(
literal|13
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--proxy-password="
argument_list|)
condition|)
name|dl
operator|.
name|setProxyPassword
argument_list|(
name|str
operator|.
name|mid
argument_list|(
literal|17
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"--proxy=off"
condition|)
name|QNetworkProxyFactory
operator|::
name|setUseSystemConfiguration
argument_list|(
literal|false
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"--proxy=on"
condition|)
name|QNetworkProxyFactory
operator|::
name|setUseSystemConfiguration
argument_list|(
literal|true
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--proxy="
argument_list|)
condition|)
block|{
comment|//parse "--proxy=host:port[,type]"
name|QNetworkProxy
name|proxy
decl_stmt|;
name|str
operator|=
name|str
operator|.
name|mid
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|int
name|sep
init|=
name|str
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|)
decl_stmt|;
name|proxy
operator|.
name|setHostName
argument_list|(
name|str
operator|.
name|left
argument_list|(
name|sep
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|=
name|str
operator|.
name|mid
argument_list|(
name|sep
operator|+
literal|1
argument_list|)
expr_stmt|;
name|sep
operator|=
name|str
operator|.
name|indexOf
argument_list|(
literal|','
argument_list|)
expr_stmt|;
name|QString
name|port
decl_stmt|;
if|if
condition|(
name|sep
operator|<
literal|0
condition|)
block|{
name|port
operator|=
name|str
expr_stmt|;
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|port
operator|=
name|str
operator|.
name|left
argument_list|(
name|sep
argument_list|)
expr_stmt|;
name|str
operator|=
name|str
operator|.
name|mid
argument_list|(
name|sep
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|str
operator|==
literal|"socks"
condition|)
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"ftp"
condition|)
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|FtpCachingProxy
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"httpcaching"
condition|)
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|HttpCachingProxy
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"http"
condition|)
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|)
expr_stmt|;
else|else
block|{
name|qDebug
argument_list|()
operator|<<
literal|"unknown proxy type"
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
block|}
name|bool
name|ok
decl_stmt|;
name|quint16
name|p
init|=
name|port
operator|.
name|toUShort
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
block|{
name|qDebug
argument_list|()
operator|<<
literal|"couldn't parse proxy"
expr_stmt|;
return|return
name|EXIT_FAILURE
return|;
block|}
name|proxy
operator|.
name|setPort
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"proxy:"
operator|<<
name|proxy
operator|.
name|hostName
argument_list|()
operator|<<
name|proxy
operator|.
name|port
argument_list|()
operator|<<
name|proxy
operator|.
name|type
argument_list|()
expr_stmt|;
name|dl
operator|.
name|setProxy
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--put="
argument_list|)
condition|)
block|{
name|method
operator|=
name|TransferItem
operator|::
name|Put
expr_stmt|;
name|uploadFileName
operator|=
name|str
operator|.
name|mid
argument_list|(
literal|6
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--post="
argument_list|)
condition|)
block|{
name|method
operator|=
name|TransferItem
operator|::
name|Post
expr_stmt|;
name|uploadFileName
operator|=
name|str
operator|.
name|mid
argument_list|(
literal|7
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--content-type="
argument_list|)
condition|)
name|contentType
operator|=
name|str
operator|.
name|mid
argument_list|(
literal|15
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"--headers="
argument_list|)
condition|)
name|headersFile
operator|=
name|str
operator|.
name|mid
argument_list|(
literal|10
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|==
literal|"--serial"
condition|)
name|dl
operator|.
name|setQueueMode
argument_list|(
name|DownloadManager
operator|::
name|Serial
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|str
operator|.
name|startsWith
argument_list|(
literal|"-"
argument_list|)
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"unsupported option"
operator|<<
name|str
expr_stmt|;
else|else
block|{
name|QUrl
name|url
argument_list|(
name|QUrl
operator|::
name|fromUserInput
argument_list|(
name|str
argument_list|)
argument_list|)
decl_stmt|;
name|QNetworkRequest
name|request
argument_list|(
name|url
argument_list|)
decl_stmt|;
comment|//set headers
if|if
condition|(
operator|!
name|headersFile
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFile
name|f
argument_list|(
name|headersFile
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"can't open headers file: "
operator|<<
name|headersFile
expr_stmt|;
block|}
else|else
block|{
while|while
condition|(
operator|!
name|f
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
init|=
name|f
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
name|isEmpty
argument_list|()
condition|)
break|break;
name|int
name|colon
init|=
name|line
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|line
expr_stmt|;
if|if
condition|(
name|colon
operator|>
literal|0
operator|&&
name|colon
operator|<
name|line
operator|.
name|length
argument_list|()
operator|-
literal|2
condition|)
block|{
name|request
operator|.
name|setRawHeader
argument_list|(
name|line
operator|.
name|left
argument_list|(
name|colon
argument_list|)
argument_list|,
name|line
operator|.
name|mid
argument_list|(
name|colon
operator|+
literal|2
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|contentType
operator|.
name|isEmpty
argument_list|()
condition|)
name|request
operator|.
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentTypeHeader
argument_list|,
name|contentType
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|method
condition|)
block|{
case|case
name|TransferItem
operator|::
name|Put
case|:
case|case
name|TransferItem
operator|::
name|Post
case|:
name|dl
operator|.
name|upload
argument_list|(
name|request
argument_list|,
name|httpUser
argument_list|,
name|httpPassword
argument_list|,
name|uploadFileName
argument_list|,
name|method
argument_list|)
expr_stmt|;
break|break;
case|case
name|TransferItem
operator|::
name|Get
case|:
name|dl
operator|.
name|get
argument_list|(
name|request
argument_list|,
name|httpUser
argument_list|,
name|httpPassword
argument_list|)
expr_stmt|;
break|break;
block|}
name|method
operator|=
name|TransferItem
operator|::
name|Get
expr_stmt|;
comment|//default for urls without a request type before it
block|}
block|}
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
operator|&
name|dl
argument_list|,
literal|"checkForAllDone"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
