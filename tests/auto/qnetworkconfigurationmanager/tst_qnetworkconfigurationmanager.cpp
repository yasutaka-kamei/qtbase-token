begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"../qbearertestcommon.h"
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkconfiguration.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkconfigmanager.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_ICD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<iapconf.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_USE_NAMESPACE
end_macro
begin_class
DECL|class|tst_QNetworkConfigurationManager
class|class
name|tst_QNetworkConfigurationManager
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
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
name|usedInThread
parameter_list|()
function_decl|;
comment|// this test must be first, or it will falsely pass
name|void
name|allConfigurations
parameter_list|()
function_decl|;
name|void
name|defaultConfiguration
parameter_list|()
function_decl|;
name|void
name|configurationFromIdentifier
parameter_list|()
function_decl|;
private|private:
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_ICD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
DECL|member|iapconf
name|Maemo
operator|::
name|IAPConf
modifier|*
name|iapconf
decl_stmt|;
DECL|member|iapconf2
name|Maemo
operator|::
name|IAPConf
modifier|*
name|iapconf2
decl_stmt|;
DECL|member|gprsiap
name|Maemo
operator|::
name|IAPConf
modifier|*
name|gprsiap
decl_stmt|;
DECL|macro|MAX_IAPS
define|#
directive|define
name|MAX_IAPS
value|50
DECL|member|iaps
name|Maemo
operator|::
name|IAPConf
modifier|*
name|iaps
index|[
name|MAX_IAPS
index|]
decl_stmt|;
DECL|member|icd_stub
name|QProcess
modifier|*
name|icd_stub
decl_stmt|;
endif|#
directive|endif
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QNetworkConfigurationManager
operator|::
name|initTestCase
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_ICD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|iapconf
operator|=
operator|new
name|Maemo
operator|::
name|IAPConf
argument_list|(
literal|"007"
argument_list|)
expr_stmt|;
name|iapconf
operator|->
name|setValue
argument_list|(
literal|"ipv4_type"
argument_list|,
literal|"AUTO"
argument_list|)
expr_stmt|;
name|iapconf
operator|->
name|setValue
argument_list|(
literal|"wlan_wepkey1"
argument_list|,
literal|"connt"
argument_list|)
expr_stmt|;
name|iapconf
operator|->
name|setValue
argument_list|(
literal|"wlan_wepdefkey"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|iapconf
operator|->
name|setValue
argument_list|(
literal|"wlan_ssid"
argument_list|,
name|QByteArray
argument_list|(
literal|"JamesBond"
argument_list|)
argument_list|)
expr_stmt|;
name|iapconf
operator|->
name|setValue
argument_list|(
literal|"name"
argument_list|,
literal|"James Bond"
argument_list|)
expr_stmt|;
name|iapconf
operator|->
name|setValue
argument_list|(
literal|"type"
argument_list|,
literal|"WLAN_INFRA"
argument_list|)
expr_stmt|;
name|gprsiap
operator|=
operator|new
name|Maemo
operator|::
name|IAPConf
argument_list|(
literal|"This-is-GPRS-IAP"
argument_list|)
expr_stmt|;
name|gprsiap
operator|->
name|setValue
argument_list|(
literal|"ask_password"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|gprsiap
operator|->
name|setValue
argument_list|(
literal|"gprs_accesspointname"
argument_list|,
literal|"internet"
argument_list|)
expr_stmt|;
name|gprsiap
operator|->
name|setValue
argument_list|(
literal|"gprs_password"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|gprsiap
operator|->
name|setValue
argument_list|(
literal|"gprs_username"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|gprsiap
operator|->
name|setValue
argument_list|(
literal|"ipv4_autodns"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|gprsiap
operator|->
name|setValue
argument_list|(
literal|"ipv4_type"
argument_list|,
literal|"AUTO"
argument_list|)
expr_stmt|;
name|gprsiap
operator|->
name|setValue
argument_list|(
literal|"sim_imsi"
argument_list|,
literal|"244070123456789"
argument_list|)
expr_stmt|;
name|gprsiap
operator|->
name|setValue
argument_list|(
literal|"name"
argument_list|,
literal|"MI6"
argument_list|)
expr_stmt|;
name|gprsiap
operator|->
name|setValue
argument_list|(
literal|"type"
argument_list|,
literal|"GPRS"
argument_list|)
expr_stmt|;
name|iapconf2
operator|=
operator|new
name|Maemo
operator|::
name|IAPConf
argument_list|(
literal|"osso.net"
argument_list|)
expr_stmt|;
name|iapconf2
operator|->
name|setValue
argument_list|(
literal|"ipv4_type"
argument_list|,
literal|"AUTO"
argument_list|)
expr_stmt|;
name|iapconf2
operator|->
name|setValue
argument_list|(
literal|"wlan_wepkey1"
argument_list|,
literal|"osso.net"
argument_list|)
expr_stmt|;
name|iapconf2
operator|->
name|setValue
argument_list|(
literal|"wlan_wepdefkey"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|iapconf2
operator|->
name|setValue
argument_list|(
literal|"wlan_ssid"
argument_list|,
name|QByteArray
argument_list|(
literal|"osso.net"
argument_list|)
argument_list|)
expr_stmt|;
name|iapconf2
operator|->
name|setValue
argument_list|(
literal|"name"
argument_list|,
literal|"osso.net"
argument_list|)
expr_stmt|;
name|iapconf2
operator|->
name|setValue
argument_list|(
literal|"type"
argument_list|,
literal|"WLAN_INFRA"
argument_list|)
expr_stmt|;
name|iapconf2
operator|->
name|setValue
argument_list|(
literal|"wlan_security"
argument_list|,
literal|"WEP"
argument_list|)
expr_stmt|;
comment|/* Create large number of IAPs in the gconf and see what happens */
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Creating %d IAPS: "
argument_list|,
name|MAX_IAPS
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|MAX_IAPS
condition|;
name|i
operator|++
control|)
block|{
name|QString
name|num
init|=
name|QString
argument_list|()
operator|.
name|sprintf
argument_list|(
literal|"%d"
argument_list|,
name|i
argument_list|)
decl_stmt|;
name|QString
name|iap
init|=
literal|"iap-"
operator|+
name|num
decl_stmt|;
name|iaps
index|[
name|i
index|]
operator|=
operator|new
name|Maemo
operator|::
name|IAPConf
argument_list|(
name|iap
argument_list|)
expr_stmt|;
name|iaps
index|[
name|i
index|]
operator|->
name|setValue
argument_list|(
literal|"name"
argument_list|,
name|QString
argument_list|(
literal|"test-iap-"
argument_list|)
operator|+
name|num
argument_list|)
expr_stmt|;
name|iaps
index|[
name|i
index|]
operator|->
name|setValue
argument_list|(
literal|"type"
argument_list|,
literal|"WLAN_INFRA"
argument_list|)
expr_stmt|;
name|iaps
index|[
name|i
index|]
operator|->
name|setValue
argument_list|(
literal|"wlan_ssid"
argument_list|,
name|QString
argument_list|(
name|QString
argument_list|(
literal|"test-ssid-"
argument_list|)
operator|+
name|num
argument_list|)
operator|.
name|toAscii
argument_list|()
argument_list|)
expr_stmt|;
name|iaps
index|[
name|i
index|]
operator|->
name|setValue
argument_list|(
literal|"wlan_security"
argument_list|,
literal|"WPA_PSK"
argument_list|)
expr_stmt|;
name|iaps
index|[
name|i
index|]
operator|->
name|setValue
argument_list|(
literal|"EAP_wpa_preshared_passphrase"
argument_list|,
name|QString
argument_list|(
literal|"test-passphrase-"
argument_list|)
operator|+
name|num
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"."
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|icd_stub
operator|=
operator|new
name|QProcess
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|icd_stub
operator|->
name|start
argument_list|(
literal|"/usr/bin/icd2_stub.py"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|// Add a known network to scan list that icd2 stub returns
name|QProcess
name|dbus_send
decl_stmt|;
comment|// 007 network
name|dbus_send
operator|.
name|start
argument_list|(
literal|"dbus-send --type=method_call --system "
literal|"--dest=com.nokia.icd2 /com/nokia/icd2 "
literal|"com.nokia.icd2.testing.add_available_network "
literal|"string:'' uint32:0 string:'' "
literal|"string:WLAN_INFRA uint32:5000011 array:byte:48,48,55"
argument_list|)
expr_stmt|;
name|dbus_send
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
comment|// osso.net network
name|dbus_send
operator|.
name|start
argument_list|(
literal|"dbus-send --type=method_call --system "
literal|"--dest=com.nokia.icd2 /com/nokia/icd2 "
literal|"com.nokia.icd2.testing.add_available_network "
literal|"string:'' uint32:0 string:'' "
literal|"string:WLAN_INFRA uint32:83886097 array:byte:111,115,115,111,46,110,101,116"
argument_list|)
expr_stmt|;
name|dbus_send
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QNetworkConfigurationManager
operator|::
name|cleanupTestCase
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_ICD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|iapconf
operator|->
name|clear
argument_list|()
expr_stmt|;
operator|delete
name|iapconf
expr_stmt|;
name|iapconf2
operator|->
name|clear
argument_list|()
expr_stmt|;
operator|delete
name|iapconf2
expr_stmt|;
name|gprsiap
operator|->
name|clear
argument_list|()
expr_stmt|;
operator|delete
name|gprsiap
expr_stmt|;
name|printf
argument_list|(
literal|"Deleting %d IAPS : "
argument_list|,
name|MAX_IAPS
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|MAX_IAPS
condition|;
name|i
operator|++
control|)
block|{
name|iaps
index|[
name|i
index|]
operator|->
name|clear
argument_list|()
expr_stmt|;
operator|delete
name|iaps
index|[
name|i
index|]
expr_stmt|;
name|printf
argument_list|(
literal|"."
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Deleted"
operator|<<
name|MAX_IAPS
operator|<<
literal|"IAPs"
expr_stmt|;
name|icd_stub
operator|->
name|terminate
argument_list|()
expr_stmt|;
name|icd_stub
operator|->
name|waitForFinished
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QNetworkConfigurationManager
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QNetworkConfigurationManager
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|printConfigurationDetails
name|void
name|printConfigurationDetails
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|p
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
name|p
operator|.
name|name
argument_list|()
operator|<<
literal|":  isvalid->"
operator|<<
name|p
operator|.
name|isValid
argument_list|()
operator|<<
literal|" type->"
operator|<<
name|p
operator|.
name|type
argument_list|()
operator|<<
literal|" roaming->"
operator|<<
name|p
operator|.
name|isRoamingAvailable
argument_list|()
operator|<<
literal|"identifier->"
operator|<<
name|p
operator|.
name|identifier
argument_list|()
operator|<<
literal|" purpose->"
operator|<<
name|p
operator|.
name|purpose
argument_list|()
operator|<<
literal|" state->"
operator|<<
name|p
operator|.
name|state
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|allConfigurations
name|void
name|tst_QNetworkConfigurationManager
operator|::
name|allConfigurations
parameter_list|()
block|{
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|preScanConfigs
init|=
name|manager
operator|.
name|allConfigurations
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QNetworkConfiguration
name|c
decl|,
name|preScanConfigs
control|)
block|{
name|QVERIFY2
argument_list|(
name|c
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkConfiguration
operator|::
name|UserChoice
argument_list|,
literal|"allConfiguration must not return UserChoice configs"
argument_list|)
expr_stmt|;
block|}
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|manager
operator|.
name|updateConfigurations
argument_list|()
expr_stmt|;
comment|//initiate scans
name|QTRY_VERIFY
argument_list|(
name|spy
operator|.
name|count
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
comment|//wait for scan to complete
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|configs
init|=
name|manager
operator|.
name|allConfigurations
argument_list|()
decl_stmt|;
name|int
name|all
init|=
name|configs
operator|.
name|count
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"All configurations:"
operator|<<
name|all
expr_stmt|;
name|QVERIFY
argument_list|(
name|all
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QNetworkConfiguration
name|p
decl|,
name|configs
control|)
block|{
name|QVERIFY
argument_list|(
name|p
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|printConfigurationDetails
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkConfiguration
operator|::
name|Invalid
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkConfiguration
operator|::
name|UserChoice
argument_list|)
expr_stmt|;
block|}
name|configs
operator|=
name|manager
operator|.
name|allConfigurations
argument_list|(
name|QNetworkConfiguration
operator|::
name|Undefined
argument_list|)
expr_stmt|;
name|int
name|undefined
init|=
name|configs
operator|.
name|count
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|undefined
operator|<=
name|all
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Undefined configurations:"
operator|<<
name|undefined
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QNetworkConfiguration
name|p
decl|,
name|configs
control|)
block|{
name|printConfigurationDetails
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Undefined
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Defined
operator|)
argument_list|)
expr_stmt|;
block|}
comment|//get defined configs only (same as all)
name|configs
operator|=
name|manager
operator|.
name|allConfigurations
argument_list|(
name|QNetworkConfiguration
operator|::
name|Defined
argument_list|)
expr_stmt|;
name|int
name|defined
init|=
name|configs
operator|.
name|count
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Defined configurations:"
operator|<<
name|defined
expr_stmt|;
name|QVERIFY
argument_list|(
name|defined
operator|<=
name|all
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QNetworkConfiguration
name|p
decl|,
name|configs
control|)
block|{
name|printConfigurationDetails
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Defined
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Undefined
operator|)
argument_list|)
expr_stmt|;
block|}
comment|//get discovered configurations only
name|configs
operator|=
name|manager
operator|.
name|allConfigurations
argument_list|(
name|QNetworkConfiguration
operator|::
name|Discovered
argument_list|)
expr_stmt|;
name|int
name|discovered
init|=
name|configs
operator|.
name|count
argument_list|()
decl_stmt|;
comment|//QVERIFY(discovered);
name|qDebug
argument_list|()
operator|<<
literal|"Discovered configurations:"
operator|<<
name|discovered
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QNetworkConfiguration
name|p
decl|,
name|configs
control|)
block|{
name|printConfigurationDetails
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Undefined
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Defined
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
argument_list|)
expr_stmt|;
block|}
comment|//getactive configurations only
name|configs
operator|=
name|manager
operator|.
name|allConfigurations
argument_list|(
name|QNetworkConfiguration
operator|::
name|Active
argument_list|)
expr_stmt|;
name|int
name|active
init|=
name|configs
operator|.
name|count
argument_list|()
decl_stmt|;
if|if
condition|(
name|active
condition|)
name|QVERIFY
argument_list|(
name|manager
operator|.
name|isOnline
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|QVERIFY
argument_list|(
operator|!
name|manager
operator|.
name|isOnline
argument_list|()
argument_list|)
expr_stmt|;
comment|//QVERIFY(active);
name|qDebug
argument_list|()
operator|<<
literal|"Active configurations:"
operator|<<
name|active
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QNetworkConfiguration
name|p
decl|,
name|configs
control|)
block|{
name|printConfigurationDetails
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Undefined
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Active
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Defined
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|all
operator|>=
name|discovered
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|discovered
operator|>=
name|active
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultConfiguration
name|void
name|tst_QNetworkConfigurationManager
operator|::
name|defaultConfiguration
parameter_list|()
block|{
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|manager
operator|.
name|updateConfigurations
argument_list|()
expr_stmt|;
comment|//initiate scans
name|QTRY_VERIFY
argument_list|(
name|spy
operator|.
name|count
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
comment|//wait for scan to complete
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|configs
init|=
name|manager
operator|.
name|allConfigurations
argument_list|()
decl_stmt|;
name|QNetworkConfiguration
name|defaultConfig
init|=
name|manager
operator|.
name|defaultConfiguration
argument_list|()
decl_stmt|;
name|bool
name|confirm
init|=
name|configs
operator|.
name|contains
argument_list|(
name|defaultConfig
argument_list|)
decl_stmt|;
if|if
condition|(
name|defaultConfig
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkConfiguration
operator|::
name|UserChoice
condition|)
block|{
name|QVERIFY
argument_list|(
name|confirm
operator|||
operator|!
name|defaultConfig
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|confirm
operator|&&
operator|!
name|defaultConfig
operator|.
name|isValid
argument_list|()
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QVERIFY
argument_list|(
operator|!
name|confirm
argument_list|)
expr_stmt|;
comment|// user choice config is not part of allConfigurations()
name|QVERIFY
argument_list|(
name|defaultConfig
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|defaultConfig
operator|.
name|name
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"UserChoice"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|defaultConfig
operator|.
name|children
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|defaultConfig
operator|.
name|isRoamingAvailable
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|defaultConfig
operator|.
name|state
argument_list|()
argument_list|,
name|QNetworkConfiguration
operator|::
name|Discovered
argument_list|)
expr_stmt|;
name|QNetworkConfiguration
name|copy
init|=
name|manager
operator|.
name|configurationFromIdentifier
argument_list|(
name|defaultConfig
operator|.
name|identifier
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|copy
operator|==
name|defaultConfig
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|configurationFromIdentifier
name|void
name|tst_QNetworkConfigurationManager
operator|::
name|configurationFromIdentifier
parameter_list|()
block|{
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|allIdentifier
decl_stmt|;
comment|//force an update to get maximum number of configs
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|manager
operator|.
name|updateConfigurations
argument_list|()
expr_stmt|;
comment|//initiate scans
name|QTRY_VERIFY
argument_list|(
name|spy
operator|.
name|count
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
comment|//wait for scan to complete
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|configs
init|=
name|manager
operator|.
name|allConfigurations
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QNetworkConfiguration
name|c
decl|,
name|configs
control|)
block|{
name|QVERIFY
argument_list|(
operator|!
name|allIdentifier
operator|.
name|contains
argument_list|(
name|c
operator|.
name|identifier
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|allIdentifier
operator|.
name|insert
argument_list|(
name|c
operator|.
name|identifier
argument_list|()
argument_list|)
expr_stmt|;
name|QNetworkConfiguration
name|direct
init|=
name|manager
operator|.
name|configurationFromIdentifier
argument_list|(
name|c
operator|.
name|identifier
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|direct
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|direct
operator|==
name|c
argument_list|)
expr_stmt|;
block|}
comment|//assume that there is no item with identifier 'FooBar'
name|QVERIFY
argument_list|(
operator|!
name|allIdentifier
operator|.
name|contains
argument_list|(
literal|"FooBar"
argument_list|)
argument_list|)
expr_stmt|;
name|QNetworkConfiguration
name|invalid
init|=
name|manager
operator|.
name|configurationFromIdentifier
argument_list|(
literal|"FooBar"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|invalid
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QNCMTestThread
class|class
name|QNCMTestThread
super|:
specifier|public
name|QThread
block|{
protected|protected:
DECL|function|run
specifier|virtual
name|void
name|run
parameter_list|()
block|{
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
name|preScanConfigs
operator|=
name|manager
operator|.
name|allConfigurations
argument_list|()
expr_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|manager
operator|.
name|updateConfigurations
argument_list|()
expr_stmt|;
comment|//initiate scans
name|QTRY_VERIFY
argument_list|(
name|spy
operator|.
name|count
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
comment|//wait for scan to complete
name|configs
operator|=
name|manager
operator|.
name|allConfigurations
argument_list|()
expr_stmt|;
block|}
public|public:
DECL|member|configs
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|configs
decl_stmt|;
DECL|member|preScanConfigs
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|preScanConfigs
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|// regression test for QTBUG-18795
end_comment
begin_function
DECL|function|usedInThread
name|void
name|tst_QNetworkConfigurationManager
operator|::
name|usedInThread
parameter_list|()
block|{
name|QNCMTestThread
name|thread
decl_stmt|;
name|connect
argument_list|(
operator|&
name|thread
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|instance
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|thread
operator|.
name|start
argument_list|()
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|thread
operator|.
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"prescan:"
operator|<<
name|thread
operator|.
name|preScanConfigs
operator|.
name|count
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"postscan:"
operator|<<
name|thread
operator|.
name|configs
operator|.
name|count
argument_list|()
expr_stmt|;
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|preScanConfigs
init|=
name|manager
operator|.
name|allConfigurations
argument_list|()
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|manager
operator|.
name|updateConfigurations
argument_list|()
expr_stmt|;
comment|//initiate scans
name|QTRY_VERIFY
argument_list|(
name|spy
operator|.
name|count
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
comment|//wait for scan to complete
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|configs
init|=
name|manager
operator|.
name|allConfigurations
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|thread
operator|.
name|configs
argument_list|,
name|configs
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|thread
operator|.
name|preScanConfigs
argument_list|,
name|preScanConfigs
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QNetworkConfigurationManager
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkconfigurationmanager.moc"
end_include
end_unit
