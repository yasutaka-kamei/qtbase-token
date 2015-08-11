begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qnetworkinterface.h>
end_include
begin_include
include|#
directive|include
file|<qtcpsocket.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
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
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"../../../network-settings.h"
end_include
begin_class
DECL|class|tst_QNetworkInterface
class|class
name|tst_QNetworkInterface
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QNetworkInterface
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QNetworkInterface
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|dump
parameter_list|()
function_decl|;
name|void
name|loopbackIPv4
parameter_list|()
function_decl|;
name|void
name|loopbackIPv6
parameter_list|()
function_decl|;
name|void
name|localAddress
parameter_list|()
function_decl|;
name|void
name|interfaceFromXXX_data
parameter_list|()
function_decl|;
name|void
name|interfaceFromXXX
parameter_list|()
function_decl|;
name|void
name|copyInvalidInterface
parameter_list|()
function_decl|;
private|private:
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
DECL|member|netConfMan
name|QNetworkConfigurationManager
modifier|*
name|netConfMan
decl_stmt|;
DECL|member|networkConfiguration
name|QNetworkConfiguration
name|networkConfiguration
decl_stmt|;
DECL|member|networkSession
name|QScopedPointer
argument_list|<
name|QNetworkSession
argument_list|>
name|networkSession
decl_stmt|;
endif|#
directive|endif
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QNetworkInterface
name|tst_QNetworkInterface
operator|::
name|tst_QNetworkInterface
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QNetworkInterface
name|tst_QNetworkInterface
operator|::
name|~
name|tst_QNetworkInterface
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QNetworkInterface
operator|::
name|initTestCase
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QtNetworkSettings
operator|::
name|verifyTestNetworkSettings
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"No network test server available"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|netConfMan
operator|=
operator|new
name|QNetworkConfigurationManager
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|netConfMan
operator|->
name|capabilities
argument_list|()
operator|&
name|QNetworkConfigurationManager
operator|::
name|NetworkSessionRequired
condition|)
block|{
name|networkConfiguration
operator|=
name|netConfMan
operator|->
name|defaultConfiguration
argument_list|()
expr_stmt|;
name|networkSession
operator|.
name|reset
argument_list|(
operator|new
name|QNetworkSession
argument_list|(
name|networkConfiguration
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|networkSession
operator|->
name|isOpen
argument_list|()
condition|)
block|{
name|networkSession
operator|->
name|open
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|networkSession
operator|->
name|waitForOpened
argument_list|(
literal|30000
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QNetworkInterface
operator|::
name|cleanupTestCase
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
if|if
condition|(
name|networkSession
operator|&&
name|networkSession
operator|->
name|isOpen
argument_list|()
condition|)
block|{
name|networkSession
operator|->
name|close
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|dump
name|void
name|tst_QNetworkInterface
operator|::
name|dump
parameter_list|()
block|{
comment|// This is for manual testing:
name|QList
argument_list|<
name|QNetworkInterface
argument_list|>
name|allInterfaces
init|=
name|QNetworkInterface
operator|::
name|allInterfaces
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QNetworkInterface
modifier|&
name|i
decl|,
name|allInterfaces
control|)
block|{
name|QString
name|flags
decl_stmt|;
if|if
condition|(
name|i
operator|.
name|flags
argument_list|()
operator|&
name|QNetworkInterface
operator|::
name|IsUp
condition|)
name|flags
operator|+=
literal|"Up,"
expr_stmt|;
if|if
condition|(
name|i
operator|.
name|flags
argument_list|()
operator|&
name|QNetworkInterface
operator|::
name|IsRunning
condition|)
name|flags
operator|+=
literal|"Running,"
expr_stmt|;
if|if
condition|(
name|i
operator|.
name|flags
argument_list|()
operator|&
name|QNetworkInterface
operator|::
name|CanBroadcast
condition|)
name|flags
operator|+=
literal|"Broadcast,"
expr_stmt|;
if|if
condition|(
name|i
operator|.
name|flags
argument_list|()
operator|&
name|QNetworkInterface
operator|::
name|IsLoopBack
condition|)
name|flags
operator|+=
literal|"Loopback,"
expr_stmt|;
if|if
condition|(
name|i
operator|.
name|flags
argument_list|()
operator|&
name|QNetworkInterface
operator|::
name|IsPointToPoint
condition|)
name|flags
operator|+=
literal|"PointToPoint,"
expr_stmt|;
if|if
condition|(
name|i
operator|.
name|flags
argument_list|()
operator|&
name|QNetworkInterface
operator|::
name|CanMulticast
condition|)
name|flags
operator|+=
literal|"Multicast,"
expr_stmt|;
name|flags
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// drop last comma
name|QString
name|friendlyName
init|=
name|i
operator|.
name|humanReadableName
argument_list|()
decl_stmt|;
if|if
condition|(
name|friendlyName
operator|!=
name|i
operator|.
name|name
argument_list|()
condition|)
block|{
name|friendlyName
operator|.
name|prepend
argument_list|(
literal|'('
argument_list|)
expr_stmt|;
name|friendlyName
operator|.
name|append
argument_list|(
literal|')'
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|friendlyName
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"Interface:     "
operator|<<
name|i
operator|.
name|name
argument_list|()
operator|<<
name|qPrintable
argument_list|(
name|friendlyName
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|i
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"    index:     "
operator|<<
name|i
operator|.
name|index
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"    flags:     "
operator|<<
name|qPrintable
argument_list|(
name|flags
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"    hw address:"
operator|<<
name|qPrintable
argument_list|(
name|i
operator|.
name|hardwareAddress
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QNetworkAddressEntry
modifier|&
name|e
decl|,
name|i
operator|.
name|addressEntries
argument_list|()
control|)
block|{
name|QDebug
name|s
init|=
name|qDebug
argument_list|()
decl_stmt|;
name|s
operator|.
name|nospace
argument_list|()
operator|<<
literal|"    address "
operator|<<
name|qSetFieldWidth
argument_list|(
literal|2
argument_list|)
operator|<<
name|count
operator|++
operator|<<
name|qSetFieldWidth
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|s
operator|.
name|nospace
argument_list|()
operator|<<
literal|": "
operator|<<
name|qPrintable
argument_list|(
name|e
operator|.
name|ip
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|e
operator|.
name|netmask
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
name|s
operator|.
name|nospace
argument_list|()
operator|<<
literal|'/'
operator|<<
name|e
operator|.
name|prefixLength
argument_list|()
operator|<<
literal|" ("
operator|<<
name|qPrintable
argument_list|(
name|e
operator|.
name|netmask
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
operator|<<
literal|')'
expr_stmt|;
if|if
condition|(
operator|!
name|e
operator|.
name|broadcast
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
name|s
operator|.
name|nospace
argument_list|()
operator|<<
literal|" broadcast "
operator|<<
name|qPrintable
argument_list|(
name|e
operator|.
name|broadcast
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|loopbackIPv4
name|void
name|tst_QNetworkInterface
operator|::
name|loopbackIPv4
parameter_list|()
block|{
name|QList
argument_list|<
name|QHostAddress
argument_list|>
name|all
init|=
name|QNetworkInterface
operator|::
name|allAddresses
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|all
operator|.
name|contains
argument_list|(
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loopbackIPv6
name|void
name|tst_QNetworkInterface
operator|::
name|loopbackIPv6
parameter_list|()
block|{
name|QList
argument_list|<
name|QHostAddress
argument_list|>
name|all
init|=
name|QNetworkInterface
operator|::
name|allAddresses
argument_list|()
decl_stmt|;
name|bool
name|loopbackfound
init|=
literal|false
decl_stmt|;
name|bool
name|anyIPv6
init|=
literal|false
decl_stmt|;
foreach|foreach
control|(
name|QHostAddress
name|addr
decl|,
name|all
control|)
if|if
condition|(
name|addr
operator|==
name|QHostAddress
operator|::
name|LocalHostIPv6
condition|)
block|{
name|loopbackfound
operator|=
literal|true
expr_stmt|;
name|anyIPv6
operator|=
literal|true
expr_stmt|;
break|break;
block|}
elseif|else
if|if
condition|(
name|addr
operator|.
name|protocol
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|IPv6Protocol
condition|)
name|anyIPv6
operator|=
literal|true
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|anyIPv6
operator|||
name|loopbackfound
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|localAddress
name|void
name|tst_QNetworkInterface
operator|::
name|localAddress
parameter_list|()
block|{
name|QTcpSocket
name|socket
decl_stmt|;
name|socket
operator|.
name|connectToHost
argument_list|(
name|QtNetworkSettings
operator|::
name|serverName
argument_list|()
argument_list|,
literal|80
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|socket
operator|.
name|waitForConnected
argument_list|(
literal|5000
argument_list|)
argument_list|)
expr_stmt|;
name|QHostAddress
name|local
init|=
name|socket
operator|.
name|localAddress
argument_list|()
decl_stmt|;
comment|// make Apache happy on fluke
name|socket
operator|.
name|write
argument_list|(
literal|"GET / HTTP/1.0\r\n\r\n"
argument_list|)
expr_stmt|;
name|socket
operator|.
name|waitForBytesWritten
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|socket
operator|.
name|close
argument_list|()
expr_stmt|;
comment|// test that we can find the address that QTcpSocket reported
name|QList
argument_list|<
name|QHostAddress
argument_list|>
name|all
init|=
name|QNetworkInterface
operator|::
name|allAddresses
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|all
operator|.
name|contains
argument_list|(
name|local
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|interfaceFromXXX_data
name|void
name|tst_QNetworkInterface
operator|::
name|interfaceFromXXX_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QNetworkInterface
argument_list|>
argument_list|(
literal|"iface"
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QNetworkInterface
argument_list|>
name|allInterfaces
init|=
name|QNetworkInterface
operator|::
name|allInterfaces
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QNetworkInterface
name|iface
decl|,
name|allInterfaces
control|)
name|QTest
operator|::
name|newRow
argument_list|(
name|iface
operator|.
name|name
argument_list|()
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
operator|<<
name|iface
expr_stmt|;
block|}
end_function
begin_function
DECL|function|interfaceFromXXX
name|void
name|tst_QNetworkInterface
operator|::
name|interfaceFromXXX
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QNetworkInterface
argument_list|,
name|iface
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QNetworkInterface
operator|::
name|interfaceFromName
argument_list|(
name|iface
operator|.
name|name
argument_list|()
argument_list|)
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|int
name|idx
init|=
name|iface
operator|.
name|index
argument_list|()
condition|)
block|{
name|QVERIFY
argument_list|(
name|QNetworkInterface
operator|::
name|interfaceFromIndex
argument_list|(
name|idx
argument_list|)
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QNetworkInterface
operator|::
name|interfaceNameFromIndex
argument_list|(
name|idx
argument_list|)
argument_list|,
name|iface
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QNetworkInterface
operator|::
name|interfaceIndexFromName
argument_list|(
name|iface
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|idx
argument_list|)
expr_stmt|;
block|}
foreach|foreach
control|(
name|QNetworkAddressEntry
name|entry
decl|,
name|iface
operator|.
name|addressEntries
argument_list|()
control|)
block|{
name|QVERIFY
argument_list|(
operator|!
name|entry
operator|.
name|ip
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|protocol
argument_list|()
argument_list|,
name|entry
operator|.
name|ip
argument_list|()
operator|.
name|protocol
argument_list|()
argument_list|)
expr_stmt|;
comment|// if the netmask is known, the broadcast is known
comment|// but only for IPv4 (there is no such thing as broadcast in IPv6)
if|if
condition|(
name|entry
operator|.
name|ip
argument_list|()
operator|.
name|protocol
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|IPv4Protocol
condition|)
block|{
name|QVERIFY
argument_list|(
operator|!
name|entry
operator|.
name|broadcast
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
comment|// verify that the broadcast address is correct
name|quint32
name|ip
init|=
name|entry
operator|.
name|ip
argument_list|()
operator|.
name|toIPv4Address
argument_list|()
decl_stmt|;
name|quint32
name|mask
init|=
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|toIPv4Address
argument_list|()
decl_stmt|;
name|quint32
name|bcast
init|=
name|entry
operator|.
name|broadcast
argument_list|()
operator|.
name|toIPv4Address
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|bcast
argument_list|,
name|ip
operator||
operator|~
name|mask
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|entry
operator|.
name|broadcast
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|broadcast
argument_list|()
operator|.
name|protocol
argument_list|()
argument_list|,
name|entry
operator|.
name|ip
argument_list|()
operator|.
name|protocol
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|copyInvalidInterface
name|void
name|tst_QNetworkInterface
operator|::
name|copyInvalidInterface
parameter_list|()
block|{
comment|// Force a copy of an interfaces that isn't likely to exist
name|QNetworkInterface
name|i
init|=
name|QNetworkInterface
operator|::
name|interfaceFromName
argument_list|(
literal|"plopp"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|i
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|i
operator|.
name|index
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|i
operator|.
name|name
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|i
operator|.
name|humanReadableName
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|i
operator|.
name|hardwareAddress
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|i
operator|.
name|flags
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|i
operator|.
name|addressEntries
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QNetworkInterface
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkinterface.moc"
end_include
end_unit
