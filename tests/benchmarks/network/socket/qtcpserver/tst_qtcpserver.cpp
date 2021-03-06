begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qtcpsocket.h>
end_include
begin_include
include|#
directive|include
file|<qtcpserver.h>
end_include
begin_include
include|#
directive|include
file|<qhostaddress.h>
end_include
begin_include
include|#
directive|include
file|<qprocess.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_include
include|#
directive|include
file|<qhostinfo.h>
end_include
begin_include
include|#
directive|include
file|<QNetworkProxy>
end_include
begin_include
include|#
directive|include
file|"../../../../auto/network-settings.h"
end_include
begin_class
DECL|class|tst_QTcpServer
class|class
name|tst_QTcpServer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QTcpServer
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QTcpServer
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase_data
parameter_list|()
function_decl|;
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|ipv4LoopbackPerformanceTest
parameter_list|()
function_decl|;
name|void
name|ipv6LoopbackPerformanceTest
parameter_list|()
function_decl|;
name|void
name|ipv4PerformanceTest
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QTcpServer
name|tst_QTcpServer
operator|::
name|tst_QTcpServer
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QTcpServer
name|tst_QTcpServer
operator|::
name|~
name|tst_QTcpServer
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase_data
name|void
name|tst_QTcpServer
operator|::
name|initTestCase_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"setProxy"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"proxyType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"WithoutProxy"
argument_list|)
operator|<<
literal|false
operator|<<
literal|0
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QTest
operator|::
name|newRow
argument_list|(
literal|"WithSocks5Proxy"
argument_list|)
operator|<<
literal|true
operator|<<
name|int
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_QTcpServer
operator|::
name|initTestCase
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|QtNetworkSettings
operator|::
name|verifyTestNetworkSettings
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QTcpServer
operator|::
name|init
parameter_list|()
block|{
name|QFETCH_GLOBAL
argument_list|(
name|bool
argument_list|,
name|setProxy
argument_list|)
expr_stmt|;
if|if
condition|(
name|setProxy
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QFETCH_GLOBAL
argument_list|(
name|int
argument_list|,
name|proxyType
argument_list|)
expr_stmt|;
if|if
condition|(
name|proxyType
operator|==
name|QNetworkProxy
operator|::
name|Socks5Proxy
condition|)
block|{
name|QNetworkProxy
operator|::
name|setApplicationProxy
argument_list|(
name|QNetworkProxy
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|,
name|QtNetworkSettings
operator|::
name|serverName
argument_list|()
argument_list|,
literal|1080
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|// !QT_NO_NETWORKPROXY
name|QSKIP
argument_list|(
literal|"No proxy support"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_NETWORKPROXY
block|}
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QTcpServer
operator|::
name|cleanup
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QNetworkProxy
operator|::
name|setApplicationProxy
argument_list|(
name|QNetworkProxy
operator|::
name|DefaultProxy
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|//----------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|ipv4LoopbackPerformanceTest
name|void
name|tst_QTcpServer
operator|::
name|ipv4LoopbackPerformanceTest
parameter_list|()
block|{
name|QFETCH_GLOBAL
argument_list|(
name|bool
argument_list|,
name|setProxy
argument_list|)
expr_stmt|;
if|if
condition|(
name|setProxy
condition|)
return|return;
name|QTcpServer
name|server
decl_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|listen
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|isListening
argument_list|()
argument_list|)
expr_stmt|;
name|QTcpSocket
name|clientA
decl_stmt|;
name|clientA
operator|.
name|connectToHost
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|,
name|server
operator|.
name|serverPort
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|clientA
operator|.
name|waitForConnected
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|clientA
operator|.
name|state
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|ConnectedState
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|waitForNewConnection
argument_list|()
argument_list|)
expr_stmt|;
name|QTcpSocket
modifier|*
name|clientB
init|=
name|server
operator|.
name|nextPendingConnection
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|clientB
argument_list|)
expr_stmt|;
name|QByteArray
name|buffer
argument_list|(
literal|16384
argument_list|,
literal|'@'
argument_list|)
decl_stmt|;
name|QTime
name|stopWatch
decl_stmt|;
name|stopWatch
operator|.
name|start
argument_list|()
expr_stmt|;
name|qlonglong
name|totalWritten
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|<
literal|5000
condition|)
block|{
name|QVERIFY
argument_list|(
name|clientA
operator|.
name|write
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
name|clientA
operator|.
name|flush
argument_list|()
expr_stmt|;
name|totalWritten
operator|+=
name|buffer
operator|.
name|size
argument_list|()
expr_stmt|;
while|while
condition|(
name|clientB
operator|->
name|waitForReadyRead
argument_list|(
literal|100
argument_list|)
condition|)
block|{
if|if
condition|(
name|clientB
operator|->
name|bytesAvailable
argument_list|()
operator|==
literal|16384
condition|)
break|break;
block|}
name|clientB
operator|->
name|read
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|clientB
operator|->
name|write
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|clientB
operator|->
name|flush
argument_list|()
expr_stmt|;
name|totalWritten
operator|+=
name|buffer
operator|.
name|size
argument_list|()
expr_stmt|;
while|while
condition|(
name|clientA
operator|.
name|waitForReadyRead
argument_list|(
literal|100
argument_list|)
condition|)
block|{
if|if
condition|(
name|clientA
operator|.
name|bytesAvailable
argument_list|()
operator|==
literal|16384
condition|)
break|break;
block|}
name|clientA
operator|.
name|read
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|qDebug
argument_list|(
literal|"\t\t%s: %.1fMB/%.1fs: %.1fMB/s"
argument_list|,
name|server
operator|.
name|serverAddress
argument_list|()
operator|.
name|toString
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|totalWritten
operator|/
operator|(
literal|1024.0
operator|*
literal|1024.0
operator|)
argument_list|,
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|/
literal|1000.0
argument_list|,
operator|(
name|totalWritten
operator|/
operator|(
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|/
literal|1000.0
operator|)
operator|)
operator|/
operator|(
literal|1024
operator|*
literal|1024
operator|)
argument_list|)
expr_stmt|;
operator|delete
name|clientB
expr_stmt|;
block|}
end_function
begin_comment
comment|//----------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|ipv6LoopbackPerformanceTest
name|void
name|tst_QTcpServer
operator|::
name|ipv6LoopbackPerformanceTest
parameter_list|()
block|{
name|QFETCH_GLOBAL
argument_list|(
name|bool
argument_list|,
name|setProxy
argument_list|)
expr_stmt|;
if|if
condition|(
name|setProxy
condition|)
return|return;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE_WM
argument_list|)
name|QSKIP
argument_list|(
literal|"WinCE WM: Not yet supported"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QTcpServer
name|server
decl_stmt|;
if|if
condition|(
operator|!
name|server
operator|.
name|listen
argument_list|(
name|QHostAddress
operator|::
name|LocalHostIPv6
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|QVERIFY
argument_list|(
name|server
operator|.
name|serverError
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|UnsupportedSocketOperationError
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QTcpSocket
name|clientA
decl_stmt|;
name|clientA
operator|.
name|connectToHost
argument_list|(
name|server
operator|.
name|serverAddress
argument_list|()
argument_list|,
name|server
operator|.
name|serverPort
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|clientA
operator|.
name|waitForConnected
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|waitForNewConnection
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
name|QTcpSocket
modifier|*
name|clientB
init|=
name|server
operator|.
name|nextPendingConnection
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|clientB
argument_list|)
expr_stmt|;
name|QByteArray
name|buffer
argument_list|(
literal|16384
argument_list|,
literal|'@'
argument_list|)
decl_stmt|;
name|QTime
name|stopWatch
decl_stmt|;
name|stopWatch
operator|.
name|start
argument_list|()
expr_stmt|;
name|qlonglong
name|totalWritten
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|<
literal|5000
condition|)
block|{
name|clientA
operator|.
name|write
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|clientA
operator|.
name|flush
argument_list|()
expr_stmt|;
name|totalWritten
operator|+=
name|buffer
operator|.
name|size
argument_list|()
expr_stmt|;
while|while
condition|(
name|clientB
operator|->
name|waitForReadyRead
argument_list|(
literal|100
argument_list|)
condition|)
block|{
if|if
condition|(
name|clientB
operator|->
name|bytesAvailable
argument_list|()
operator|==
literal|16384
condition|)
break|break;
block|}
name|clientB
operator|->
name|read
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|clientB
operator|->
name|write
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|clientB
operator|->
name|flush
argument_list|()
expr_stmt|;
name|totalWritten
operator|+=
name|buffer
operator|.
name|size
argument_list|()
expr_stmt|;
while|while
condition|(
name|clientA
operator|.
name|waitForReadyRead
argument_list|(
literal|100
argument_list|)
condition|)
block|{
if|if
condition|(
name|clientA
operator|.
name|bytesAvailable
argument_list|()
operator|==
literal|16384
condition|)
break|break;
block|}
name|clientA
operator|.
name|read
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|qDebug
argument_list|(
literal|"\t\t%s: %.1fMB/%.1fs: %.1fMB/s"
argument_list|,
name|server
operator|.
name|serverAddress
argument_list|()
operator|.
name|toString
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|totalWritten
operator|/
operator|(
literal|1024.0
operator|*
literal|1024.0
operator|)
argument_list|,
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|/
literal|1000.0
argument_list|,
operator|(
name|totalWritten
operator|/
operator|(
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|/
literal|1000.0
operator|)
operator|)
operator|/
operator|(
literal|1024
operator|*
literal|1024
operator|)
argument_list|)
expr_stmt|;
operator|delete
name|clientB
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//----------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|ipv4PerformanceTest
name|void
name|tst_QTcpServer
operator|::
name|ipv4PerformanceTest
parameter_list|()
block|{
name|QTcpSocket
name|probeSocket
decl_stmt|;
name|probeSocket
operator|.
name|connectToHost
argument_list|(
name|QtNetworkSettings
operator|::
name|serverName
argument_list|()
argument_list|,
literal|143
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|probeSocket
operator|.
name|waitForConnected
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
name|QTcpServer
name|server
decl_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|listen
argument_list|(
name|probeSocket
operator|.
name|localAddress
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTcpSocket
name|clientA
decl_stmt|;
name|clientA
operator|.
name|connectToHost
argument_list|(
name|server
operator|.
name|serverAddress
argument_list|()
argument_list|,
name|server
operator|.
name|serverPort
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|clientA
operator|.
name|waitForConnected
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|waitForNewConnection
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
name|QTcpSocket
modifier|*
name|clientB
init|=
name|server
operator|.
name|nextPendingConnection
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|clientB
argument_list|)
expr_stmt|;
name|QByteArray
name|buffer
argument_list|(
literal|16384
argument_list|,
literal|'@'
argument_list|)
decl_stmt|;
name|QTime
name|stopWatch
decl_stmt|;
name|stopWatch
operator|.
name|start
argument_list|()
expr_stmt|;
name|qlonglong
name|totalWritten
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|<
literal|5000
condition|)
block|{
name|qlonglong
name|writtenA
init|=
name|clientA
operator|.
name|write
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|clientA
operator|.
name|flush
argument_list|()
expr_stmt|;
name|totalWritten
operator|+=
name|buffer
operator|.
name|size
argument_list|()
expr_stmt|;
while|while
condition|(
name|clientB
operator|->
name|waitForReadyRead
argument_list|(
literal|100
argument_list|)
condition|)
block|{
if|if
condition|(
name|clientB
operator|->
name|bytesAvailable
argument_list|()
operator|==
name|writtenA
condition|)
break|break;
block|}
name|clientB
operator|->
name|read
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|qlonglong
name|writtenB
init|=
name|clientB
operator|->
name|write
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|clientB
operator|->
name|flush
argument_list|()
expr_stmt|;
name|totalWritten
operator|+=
name|buffer
operator|.
name|size
argument_list|()
expr_stmt|;
while|while
condition|(
name|clientA
operator|.
name|waitForReadyRead
argument_list|(
literal|100
argument_list|)
condition|)
block|{
if|if
condition|(
name|clientA
operator|.
name|bytesAvailable
argument_list|()
operator|==
name|writtenB
condition|)
break|break;
block|}
name|clientA
operator|.
name|read
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|qDebug
argument_list|(
literal|"\t\t%s: %.1fMB/%.1fs: %.1fMB/s"
argument_list|,
name|probeSocket
operator|.
name|localAddress
argument_list|()
operator|.
name|toString
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|totalWritten
operator|/
operator|(
literal|1024.0
operator|*
literal|1024.0
operator|)
argument_list|,
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|/
literal|1000.0
argument_list|,
operator|(
name|totalWritten
operator|/
operator|(
name|stopWatch
operator|.
name|elapsed
argument_list|()
operator|/
literal|1000.0
operator|)
operator|)
operator|/
operator|(
literal|1024
operator|*
literal|1024
operator|)
argument_list|)
expr_stmt|;
operator|delete
name|clientB
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTcpServer
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtcpserver.moc"
end_include
end_unit
