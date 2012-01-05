begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QNetworkProxy>
end_include
begin_include
include|#
directive|include
file|<QAuthenticator>
end_include
begin_include
include|#
directive|include
file|"private/qhostinfo_p.h"
end_include
begin_include
include|#
directive|include
file|"../../../network-settings.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
end_ifndef
begin_class
DECL|class|QSslSocketPtr
class|class
name|QSslSocketPtr
super|:
specifier|public
name|QSharedPointer
argument_list|<
name|QSslSocket
argument_list|>
block|{
public|public:
DECL|function|QSslSocketPtr
specifier|inline
name|QSslSocketPtr
parameter_list|(
name|QSslSocket
modifier|*
name|ptr
init|=
literal|0
parameter_list|)
member_init_list|:
name|QSharedPointer
argument_list|<
name|QSslSocket
argument_list|>
argument_list|(
name|ptr
argument_list|)
block|{ }
DECL|function|operator QSslSocket *
specifier|inline
name|operator
name|QSslSocket *
parameter_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
return|;
block|}
block|}
class|;
end_class
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QSslSocket_onDemandCertificates_member
class|class
name|tst_QSslSocket_onDemandCertificates_member
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|proxyAuthCalled
name|int
name|proxyAuthCalled
decl_stmt|;
public|public:
name|tst_QSslSocket_onDemandCertificates_member
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSslSocket_onDemandCertificates_member
parameter_list|()
destructor_decl|;
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
name|QSslSocketPtr
name|newSocket
parameter_list|()
function_decl|;
endif|#
directive|endif
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
name|void
name|proxyAuthenticationRequired
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
parameter_list|,
name|QAuthenticator
modifier|*
name|auth
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
private|private
name|slots
private|:
name|void
name|onDemandRootCertLoadingMemberMethods
parameter_list|()
function_decl|;
private|private:
DECL|member|socket
name|QSslSocket
modifier|*
name|socket
decl_stmt|;
endif|#
directive|endif
comment|// QT_NO_OPENSSL
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSslSocket_onDemandCertificates_member
name|tst_QSslSocket_onDemandCertificates_member
operator|::
name|tst_QSslSocket_onDemandCertificates_member
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSslSocket_onDemandCertificates_member
name|tst_QSslSocket_onDemandCertificates_member
operator|::
name|~
name|tst_QSslSocket_onDemandCertificates_member
parameter_list|()
block|{ }
end_destructor
begin_enum
DECL|enum|ProxyTests
enum|enum
name|ProxyTests
block|{
DECL|enumerator|NoProxy
name|NoProxy
init|=
literal|0x00
block|,
DECL|enumerator|Socks5Proxy
name|Socks5Proxy
init|=
literal|0x01
block|,
DECL|enumerator|HttpProxy
name|HttpProxy
init|=
literal|0x02
block|,
DECL|enumerator|TypeMask
name|TypeMask
init|=
literal|0x0f
block|,
DECL|enumerator|NoAuth
name|NoAuth
init|=
literal|0x00
block|,
DECL|enumerator|AuthBasic
name|AuthBasic
init|=
literal|0x10
block|,
DECL|enumerator|AuthNtlm
name|AuthNtlm
init|=
literal|0x20
block|,
DECL|enumerator|AuthMask
name|AuthMask
init|=
literal|0xf0
block|}
enum|;
end_enum
begin_function
DECL|function|initTestCase_data
name|void
name|tst_QSslSocket_onDemandCertificates_member
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
name|Socks5Proxy
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"WithSocks5ProxyAuth"
argument_list|)
operator|<<
literal|true
operator|<<
name|int
argument_list|(
name|Socks5Proxy
operator||
name|AuthBasic
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"WithHttpProxy"
argument_list|)
operator|<<
literal|true
operator|<<
name|int
argument_list|(
name|HttpProxy
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"WithHttpProxyBasicAuth"
argument_list|)
operator|<<
literal|true
operator|<<
name|int
argument_list|(
name|HttpProxy
operator||
name|AuthBasic
argument_list|)
expr_stmt|;
comment|// uncomment the line below when NTLM works
comment|//    QTest::newRow("WithHttpProxyNtlmAuth")<< true<< int(HttpProxy | AuthNtlm);
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_QSslSocket_onDemandCertificates_member
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
name|tst_QSslSocket_onDemandCertificates_member
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
name|QFETCH_GLOBAL
argument_list|(
name|int
argument_list|,
name|proxyType
argument_list|)
expr_stmt|;
name|QString
name|testServer
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
operator|.
name|addresses
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QNetworkProxy
name|proxy
decl_stmt|;
switch|switch
condition|(
name|proxyType
condition|)
block|{
case|case
name|Socks5Proxy
case|:
name|proxy
operator|=
name|QNetworkProxy
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|,
name|testServer
argument_list|,
literal|1080
argument_list|)
expr_stmt|;
break|break;
case|case
name|Socks5Proxy
operator||
name|AuthBasic
case|:
name|proxy
operator|=
name|QNetworkProxy
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|,
name|testServer
argument_list|,
literal|1081
argument_list|)
expr_stmt|;
break|break;
case|case
name|HttpProxy
operator||
name|NoAuth
case|:
name|proxy
operator|=
name|QNetworkProxy
argument_list|(
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|,
name|testServer
argument_list|,
literal|3128
argument_list|)
expr_stmt|;
break|break;
case|case
name|HttpProxy
operator||
name|AuthBasic
case|:
name|proxy
operator|=
name|QNetworkProxy
argument_list|(
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|,
name|testServer
argument_list|,
literal|3129
argument_list|)
expr_stmt|;
break|break;
case|case
name|HttpProxy
operator||
name|AuthNtlm
case|:
name|proxy
operator|=
name|QNetworkProxy
argument_list|(
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|,
name|testServer
argument_list|,
literal|3130
argument_list|)
expr_stmt|;
break|break;
block|}
name|QNetworkProxy
operator|::
name|setApplicationProxy
argument_list|(
name|proxy
argument_list|)
expr_stmt|;
block|}
name|qt_qhostinfo_clear_cache
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSslSocket_onDemandCertificates_member
operator|::
name|cleanup
parameter_list|()
block|{
name|QNetworkProxy
operator|::
name|setApplicationProxy
argument_list|(
name|QNetworkProxy
operator|::
name|DefaultProxy
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
end_ifndef
begin_function
DECL|function|newSocket
name|QSslSocketPtr
name|tst_QSslSocket_onDemandCertificates_member
operator|::
name|newSocket
parameter_list|()
block|{
name|QSslSocket
modifier|*
name|socket
init|=
operator|new
name|QSslSocket
decl_stmt|;
name|proxyAuthCalled
operator|=
literal|0
expr_stmt|;
name|connect
argument_list|(
name|socket
argument_list|,
name|SIGNAL
argument_list|(
name|proxyAuthenticationRequired
argument_list|(
name|QNetworkProxy
argument_list|,
name|QAuthenticator
operator|*
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|proxyAuthenticationRequired
argument_list|(
name|QNetworkProxy
argument_list|,
name|QAuthenticator
operator|*
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|)
expr_stmt|;
return|return
name|QSslSocketPtr
argument_list|(
name|socket
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|proxyAuthenticationRequired
name|void
name|tst_QSslSocket_onDemandCertificates_member
operator|::
name|proxyAuthenticationRequired
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
parameter_list|,
name|QAuthenticator
modifier|*
name|auth
parameter_list|)
block|{
operator|++
name|proxyAuthCalled
expr_stmt|;
name|auth
operator|->
name|setUser
argument_list|(
literal|"qsockstest"
argument_list|)
expr_stmt|;
name|auth
operator|->
name|setPassword
argument_list|(
literal|"password"
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
end_ifndef
begin_function
DECL|function|onDemandRootCertLoadingMemberMethods
name|void
name|tst_QSslSocket_onDemandCertificates_member
operator|::
name|onDemandRootCertLoadingMemberMethods
parameter_list|()
block|{
name|QString
name|host
argument_list|(
literal|"qt.nokia.com"
argument_list|)
decl_stmt|;
comment|// not using any root certs -> should not work
name|QSslSocketPtr
name|socket2
init|=
name|newSocket
argument_list|()
decl_stmt|;
name|this
operator|->
name|socket
operator|=
name|socket2
expr_stmt|;
name|socket2
operator|->
name|setCaCertificates
argument_list|(
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|socket2
operator|->
name|connectToHostEncrypted
argument_list|(
name|host
argument_list|,
literal|443
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|socket2
operator|->
name|waitForEncrypted
argument_list|()
argument_list|)
expr_stmt|;
comment|// default: using on demand loading -> should work
name|QSslSocketPtr
name|socket
init|=
name|newSocket
argument_list|()
decl_stmt|;
name|this
operator|->
name|socket
operator|=
name|socket
expr_stmt|;
name|socket
operator|->
name|connectToHostEncrypted
argument_list|(
name|host
argument_list|,
literal|443
argument_list|)
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-20983 fails"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|socket
operator|->
name|waitForEncrypted
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|socket
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// not using any root certs again -> should not work
name|QSslSocketPtr
name|socket3
init|=
name|newSocket
argument_list|()
decl_stmt|;
name|this
operator|->
name|socket
operator|=
name|socket3
expr_stmt|;
name|socket3
operator|->
name|setCaCertificates
argument_list|(
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|socket3
operator|->
name|connectToHostEncrypted
argument_list|(
name|host
argument_list|,
literal|443
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|socket3
operator|->
name|waitForEncrypted
argument_list|()
argument_list|)
expr_stmt|;
comment|// setting empty SSL configuration explicitly -> should not work
name|QSslSocketPtr
name|socket4
init|=
name|newSocket
argument_list|()
decl_stmt|;
name|this
operator|->
name|socket
operator|=
name|socket4
expr_stmt|;
name|socket4
operator|->
name|setSslConfiguration
argument_list|(
name|QSslConfiguration
argument_list|()
argument_list|)
expr_stmt|;
name|socket4
operator|->
name|connectToHostEncrypted
argument_list|(
name|host
argument_list|,
literal|443
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|socket4
operator|->
name|waitForEncrypted
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENSSL
end_comment
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSslSocket_onDemandCertificates_member
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsslsocket_onDemandCertificates_member.moc"
end_include
end_unit
