begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkreply.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkrequest.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkaccessmanager.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<private/qabstractsocketengine_p.h>
end_include
begin_include
include|#
directive|include
file|<cstdio>
end_include
begin_include
include|#
directive|include
file|<strings.h>
end_include
begin_include
include|#
directive|include
file|<QNetworkConfigurationManager>
end_include
begin_include
include|#
directive|include
file|<QNetworkConfiguration>
end_include
begin_include
include|#
directive|include
file|<QNetworkSession>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_decl_stmt
DECL|variable|bufsize
specifier|const
name|int
name|bufsize
init|=
literal|16
operator|*
literal|1024
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|buf
name|char
name|buf
index|[
name|bufsize
index|]
decl_stmt|;
end_decl_stmt
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
modifier|*
name|argv
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
comment|// create it
name|QAbstractSocketEngine
modifier|*
name|socketEngine
init|=
name|QAbstractSocketEngine
operator|::
name|createSocketEngine
argument_list|(
name|QAbstractSocket
operator|::
name|TcpSocket
argument_list|,
name|QNetworkProxy
argument_list|(
name|QNetworkProxy
operator|::
name|NoProxy
argument_list|)
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|socketEngine
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"could not create engine"
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|// initialize it
name|bool
name|initialized
init|=
name|socketEngine
operator|->
name|initialize
argument_list|(
name|QAbstractSocket
operator|::
name|TcpSocket
argument_list|,
name|QAbstractSocket
operator|::
name|IPv4Protocol
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"not able to initialize engine"
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|// wait for connected
name|int
name|r
init|=
name|socketEngine
operator|->
name|connectToHost
argument_list|(
name|QHostAddress
argument_list|(
literal|"74.125.77.99"
argument_list|)
argument_list|,
literal|80
argument_list|)
decl_stmt|;
comment|// google
name|bool
name|readyToRead
init|=
literal|false
decl_stmt|;
name|bool
name|readyToWrite
init|=
literal|false
decl_stmt|;
name|socketEngine
operator|->
name|waitForReadOrWrite
argument_list|(
operator|&
name|readyToRead
argument_list|,
operator|&
name|readyToWrite
argument_list|,
literal|true
argument_list|,
literal|true
argument_list|,
literal|10
operator|*
literal|1000
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|<=
literal|0
condition|)
comment|//timeout or error
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|readyToWrite
condition|)
block|{
comment|// write the request
name|QByteArray
name|request
argument_list|(
literal|"GET /robots.txt HTTP/1.0\r\n\r\n"
argument_list|)
decl_stmt|;
name|int
name|ret
init|=
name|socketEngine
operator|->
name|write
argument_list|(
name|request
operator|.
name|constData
argument_list|()
argument_list|,
name|request
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
name|request
operator|.
name|length
argument_list|()
condition|)
block|{
comment|// read the response in a loop
do|do
block|{
name|bool
name|waitReadResult
init|=
name|socketEngine
operator|->
name|waitForRead
argument_list|(
literal|10
operator|*
literal|1000
argument_list|)
decl_stmt|;
name|int
name|available
init|=
name|socketEngine
operator|->
name|bytesAvailable
argument_list|()
decl_stmt|;
if|if
condition|(
name|waitReadResult
operator|==
literal|true
operator|&&
name|available
operator|==
literal|0
condition|)
block|{
comment|// disconnected
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|bzero
argument_list|(
name|buf
argument_list|,
name|bufsize
argument_list|)
expr_stmt|;
name|ret
operator|=
name|socketEngine
operator|->
name|read
argument_list|(
name|buf
argument_list|,
name|available
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|>
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// some failure when reading
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
do|while
condition|(
literal|1
condition|)
do|;
block|}
else|else
block|{
name|qDebug
argument_list|()
operator|<<
literal|"failed writing"
expr_stmt|;
block|}
block|}
else|else
block|{
name|qDebug
argument_list|()
operator|<<
literal|"failed connecting"
expr_stmt|;
block|}
operator|delete
name|socketEngine
expr_stmt|;
block|}
end_function
end_unit
