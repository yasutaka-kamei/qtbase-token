begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtNetwork/qsslsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|"private/qsslcontext_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qsslsocket_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qsslsocket_openssl_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qsslsocket_openssl_symbols_p.h"
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
comment|// defined in qsslsocket_openssl.cpp:
specifier|extern
name|int
name|q_X509Callback
parameter_list|(
name|int
name|ok
parameter_list|,
name|X509_STORE_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|QString
name|getErrorsFromOpenSsl
parameter_list|()
function_decl|;
end_function_decl
begin_constructor
DECL|function|QSslContext
name|QSslContext
operator|::
name|QSslContext
parameter_list|()
member_init_list|:
name|ctx
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|pkey
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|session
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QSslContext
name|QSslContext
operator|::
name|~
name|QSslContext
parameter_list|()
block|{
if|if
condition|(
name|ctx
condition|)
comment|// This will decrement the reference count by 1 and free the context eventually when possible
name|q_SSL_CTX_free
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
if|if
condition|(
name|pkey
condition|)
name|q_EVP_PKEY_free
argument_list|(
name|pkey
argument_list|)
expr_stmt|;
if|if
condition|(
name|session
condition|)
name|q_SSL_SESSION_free
argument_list|(
name|session
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|fromConfiguration
name|QSslContext
modifier|*
name|QSslContext
operator|::
name|fromConfiguration
parameter_list|(
name|QSslSocket
operator|::
name|SslMode
name|mode
parameter_list|,
specifier|const
name|QSslConfiguration
modifier|&
name|configuration
parameter_list|,
name|bool
name|allowRootCertOnDemandLoading
parameter_list|)
block|{
name|QSslContext
modifier|*
name|sslContext
init|=
operator|new
name|QSslContext
argument_list|()
decl_stmt|;
name|sslContext
operator|->
name|sslConfiguration
operator|=
name|configuration
expr_stmt|;
name|sslContext
operator|->
name|errorCode
operator|=
name|QSslError
operator|::
name|NoError
expr_stmt|;
name|bool
name|client
init|=
operator|(
name|mode
operator|==
name|QSslSocket
operator|::
name|SslClientMode
operator|)
decl_stmt|;
name|bool
name|reinitialized
init|=
literal|false
decl_stmt|;
name|init_context
label|:
switch|switch
condition|(
name|sslContext
operator|->
name|sslConfiguration
operator|.
name|protocol
argument_list|()
condition|)
block|{
case|case
name|QSsl
operator|::
name|SslV2
case|:
ifndef|#
directive|ifndef
name|OPENSSL_NO_SSL2
name|sslContext
operator|->
name|ctx
operator|=
name|q_SSL_CTX_new
argument_list|(
name|client
condition|?
name|q_SSLv2_client_method
argument_list|()
else|:
name|q_SSLv2_server_method
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|sslContext
operator|->
name|ctx
operator|=
literal|0
expr_stmt|;
comment|// SSL 2 not supported by the system, but chosen deliberately -> error
endif|#
directive|endif
break|break;
case|case
name|QSsl
operator|::
name|SslV3
case|:
name|sslContext
operator|->
name|ctx
operator|=
name|q_SSL_CTX_new
argument_list|(
name|client
condition|?
name|q_SSLv3_client_method
argument_list|()
else|:
name|q_SSLv3_server_method
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QSsl
operator|::
name|SecureProtocols
case|:
comment|// SslV2 will be disabled below
case|case
name|QSsl
operator|::
name|TlsV1SslV3
case|:
comment|// SslV2 will be disabled below
case|case
name|QSsl
operator|::
name|AnyProtocol
case|:
default|default:
name|sslContext
operator|->
name|ctx
operator|=
name|q_SSL_CTX_new
argument_list|(
name|client
condition|?
name|q_SSLv23_client_method
argument_list|()
else|:
name|q_SSLv23_server_method
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QSsl
operator|::
name|TlsV1_0
case|:
name|sslContext
operator|->
name|ctx
operator|=
name|q_SSL_CTX_new
argument_list|(
name|client
condition|?
name|q_TLSv1_client_method
argument_list|()
else|:
name|q_TLSv1_server_method
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QSsl
operator|::
name|TlsV1_1
case|:
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x10001000L
name|sslContext
operator|->
name|ctx
operator|=
name|q_SSL_CTX_new
argument_list|(
name|client
condition|?
name|q_TLSv1_1_client_method
argument_list|()
else|:
name|q_TLSv1_1_server_method
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|sslContext
operator|->
name|ctx
operator|=
literal|0
expr_stmt|;
comment|// TLS 1.1 not supported by the system, but chosen deliberately -> error
endif|#
directive|endif
break|break;
case|case
name|QSsl
operator|::
name|TlsV1_2
case|:
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x10001000L
name|sslContext
operator|->
name|ctx
operator|=
name|q_SSL_CTX_new
argument_list|(
name|client
condition|?
name|q_TLSv1_2_client_method
argument_list|()
else|:
name|q_TLSv1_2_server_method
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|sslContext
operator|->
name|ctx
operator|=
literal|0
expr_stmt|;
comment|// TLS 1.2 not supported by the system, but chosen deliberately -> error
endif|#
directive|endif
break|break;
block|}
if|if
condition|(
operator|!
name|sslContext
operator|->
name|ctx
condition|)
block|{
comment|// After stopping Flash 10 the SSL library looses its ciphers. Try re-adding them
comment|// by re-initializing the library.
if|if
condition|(
operator|!
name|reinitialized
condition|)
block|{
name|reinitialized
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|q_SSL_library_init
argument_list|()
operator|==
literal|1
condition|)
goto|goto
name|init_context
goto|;
block|}
name|sslContext
operator|->
name|errorStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"Error creating SSL context (%1)"
argument_list|)
operator|.
name|arg
argument_list|(
name|QSslSocketBackendPrivate
operator|::
name|getErrorsFromOpenSsl
argument_list|()
argument_list|)
expr_stmt|;
name|sslContext
operator|->
name|errorCode
operator|=
name|QSslError
operator|::
name|UnspecifiedError
expr_stmt|;
return|return
name|sslContext
return|;
block|}
comment|// Enable bug workarounds.
name|long
name|options
init|=
name|QSslSocketBackendPrivate
operator|::
name|setupOpenSslOptions
argument_list|(
name|configuration
operator|.
name|protocol
argument_list|()
argument_list|,
name|configuration
operator|.
name|d
operator|->
name|sslOptions
argument_list|)
decl_stmt|;
name|q_SSL_CTX_set_options
argument_list|(
name|sslContext
operator|->
name|ctx
argument_list|,
name|options
argument_list|)
expr_stmt|;
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x10000000L
comment|// Tell OpenSSL to release memory early
comment|// http://www.openssl.org/docs/ssl/SSL_CTX_set_mode.html
if|if
condition|(
name|q_SSLeay
argument_list|()
operator|>=
literal|0x10000000L
condition|)
name|q_SSL_CTX_set_mode
argument_list|(
name|sslContext
operator|->
name|ctx
argument_list|,
name|SSL_MODE_RELEASE_BUFFERS
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Initialize ciphers
name|QByteArray
name|cipherString
decl_stmt|;
name|int
name|first
init|=
literal|true
decl_stmt|;
name|QList
argument_list|<
name|QSslCipher
argument_list|>
name|ciphers
init|=
name|sslContext
operator|->
name|sslConfiguration
operator|.
name|ciphers
argument_list|()
decl_stmt|;
if|if
condition|(
name|ciphers
operator|.
name|isEmpty
argument_list|()
condition|)
name|ciphers
operator|=
name|QSslSocketPrivate
operator|::
name|defaultCiphers
argument_list|()
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QSslCipher
modifier|&
name|cipher
decl|,
name|ciphers
control|)
block|{
if|if
condition|(
name|first
condition|)
name|first
operator|=
literal|false
expr_stmt|;
else|else
name|cipherString
operator|.
name|append
argument_list|(
literal|':'
argument_list|)
expr_stmt|;
name|cipherString
operator|.
name|append
argument_list|(
name|cipher
operator|.
name|name
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|q_SSL_CTX_set_cipher_list
argument_list|(
name|sslContext
operator|->
name|ctx
argument_list|,
name|cipherString
operator|.
name|data
argument_list|()
argument_list|)
condition|)
block|{
name|sslContext
operator|->
name|errorStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"Invalid or empty cipher list (%1)"
argument_list|)
operator|.
name|arg
argument_list|(
name|QSslSocketBackendPrivate
operator|::
name|getErrorsFromOpenSsl
argument_list|()
argument_list|)
expr_stmt|;
name|sslContext
operator|->
name|errorCode
operator|=
name|QSslError
operator|::
name|UnspecifiedError
expr_stmt|;
return|return
name|sslContext
return|;
block|}
comment|// Add all our CAs to this store.
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
name|expiredCerts
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QSslCertificate
modifier|&
name|caCertificate
decl|,
name|sslContext
operator|->
name|sslConfiguration
operator|.
name|caCertificates
argument_list|()
control|)
block|{
comment|// add expired certs later, so that the
comment|// valid ones are used before the expired ones
if|if
condition|(
name|caCertificate
operator|.
name|expiryDate
argument_list|()
operator|<
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
condition|)
block|{
name|expiredCerts
operator|.
name|append
argument_list|(
name|caCertificate
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|q_X509_STORE_add_cert
argument_list|(
name|sslContext
operator|->
name|ctx
operator|->
name|cert_store
argument_list|,
operator|(
name|X509
operator|*
operator|)
name|caCertificate
operator|.
name|handle
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|bool
name|addExpiredCerts
init|=
literal|true
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
operator|(
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|==
name|MAC_OS_X_VERSION_10_5
operator|)
comment|//On Leopard SSL does not work if we add the expired certificates.
if|if
condition|(
name|QSysInfo
operator|::
name|MacintoshVersion
operator|==
name|QSysInfo
operator|::
name|MV_10_5
condition|)
name|addExpiredCerts
operator|=
literal|false
expr_stmt|;
endif|#
directive|endif
comment|// now add the expired certs
if|if
condition|(
name|addExpiredCerts
condition|)
block|{
foreach|foreach
control|(
specifier|const
name|QSslCertificate
modifier|&
name|caCertificate
decl|,
name|expiredCerts
control|)
block|{
name|q_X509_STORE_add_cert
argument_list|(
name|sslContext
operator|->
name|ctx
operator|->
name|cert_store
argument_list|,
cast|reinterpret_cast
argument_list|<
name|X509
operator|*
argument_list|>
argument_list|(
name|caCertificate
operator|.
name|handle
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|QSslSocketPrivate
operator|::
name|s_loadRootCertsOnDemand
operator|&&
name|allowRootCertOnDemandLoading
condition|)
block|{
comment|// tell OpenSSL the directories where to look up the root certs on demand
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|unixDirs
init|=
name|QSslSocketPrivate
operator|::
name|unixRootCertDirectories
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|a
init|=
literal|0
init|;
name|a
operator|<
name|unixDirs
operator|.
name|count
argument_list|()
condition|;
operator|++
name|a
control|)
name|q_SSL_CTX_load_verify_locations
argument_list|(
name|sslContext
operator|->
name|ctx
argument_list|,
literal|0
argument_list|,
name|unixDirs
operator|.
name|at
argument_list|(
name|a
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Register a custom callback to get all verification errors.
name|X509_STORE_set_verify_cb_func
argument_list|(
name|sslContext
operator|->
name|ctx
operator|->
name|cert_store
argument_list|,
name|q_X509Callback
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sslContext
operator|->
name|sslConfiguration
operator|.
name|localCertificate
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|// Require a private key as well.
if|if
condition|(
name|sslContext
operator|->
name|sslConfiguration
operator|.
name|privateKey
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|sslContext
operator|->
name|errorStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"Cannot provide a certificate with no key, %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QSslSocketBackendPrivate
operator|::
name|getErrorsFromOpenSsl
argument_list|()
argument_list|)
expr_stmt|;
name|sslContext
operator|->
name|errorCode
operator|=
name|QSslError
operator|::
name|UnspecifiedError
expr_stmt|;
return|return
name|sslContext
return|;
block|}
comment|// Load certificate
if|if
condition|(
operator|!
name|q_SSL_CTX_use_certificate
argument_list|(
name|sslContext
operator|->
name|ctx
argument_list|,
operator|(
name|X509
operator|*
operator|)
name|sslContext
operator|->
name|sslConfiguration
operator|.
name|localCertificate
argument_list|()
operator|.
name|handle
argument_list|()
argument_list|)
condition|)
block|{
name|sslContext
operator|->
name|errorStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"Error loading local certificate, %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QSslSocketBackendPrivate
operator|::
name|getErrorsFromOpenSsl
argument_list|()
argument_list|)
expr_stmt|;
name|sslContext
operator|->
name|errorCode
operator|=
name|QSslError
operator|::
name|UnspecifiedError
expr_stmt|;
return|return
name|sslContext
return|;
block|}
if|if
condition|(
name|configuration
operator|.
name|d
operator|->
name|privateKey
operator|.
name|algorithm
argument_list|()
operator|==
name|QSsl
operator|::
name|Opaque
condition|)
block|{
name|sslContext
operator|->
name|pkey
operator|=
cast|reinterpret_cast
argument_list|<
name|EVP_PKEY
operator|*
argument_list|>
argument_list|(
name|configuration
operator|.
name|d
operator|->
name|privateKey
operator|.
name|handle
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Load private key
name|sslContext
operator|->
name|pkey
operator|=
name|q_EVP_PKEY_new
argument_list|()
expr_stmt|;
comment|// before we were using EVP_PKEY_assign_R* functions and did not use EVP_PKEY_free.
comment|// this lead to a memory leak. Now we use the *_set1_* functions which do not
comment|// take ownership of the RSA/DSA key instance because the QSslKey already has ownership.
if|if
condition|(
name|configuration
operator|.
name|d
operator|->
name|privateKey
operator|.
name|algorithm
argument_list|()
operator|==
name|QSsl
operator|::
name|Rsa
condition|)
name|q_EVP_PKEY_set1_RSA
argument_list|(
name|sslContext
operator|->
name|pkey
argument_list|,
cast|reinterpret_cast
argument_list|<
name|RSA
operator|*
argument_list|>
argument_list|(
name|configuration
operator|.
name|d
operator|->
name|privateKey
operator|.
name|handle
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|q_EVP_PKEY_set1_DSA
argument_list|(
name|sslContext
operator|->
name|pkey
argument_list|,
cast|reinterpret_cast
argument_list|<
name|DSA
operator|*
argument_list|>
argument_list|(
name|configuration
operator|.
name|d
operator|->
name|privateKey
operator|.
name|handle
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|q_SSL_CTX_use_PrivateKey
argument_list|(
name|sslContext
operator|->
name|ctx
argument_list|,
name|sslContext
operator|->
name|pkey
argument_list|)
condition|)
block|{
name|sslContext
operator|->
name|errorStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"Error loading private key, %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QSslSocketBackendPrivate
operator|::
name|getErrorsFromOpenSsl
argument_list|()
argument_list|)
expr_stmt|;
name|sslContext
operator|->
name|errorCode
operator|=
name|QSslError
operator|::
name|UnspecifiedError
expr_stmt|;
return|return
name|sslContext
return|;
block|}
if|if
condition|(
name|configuration
operator|.
name|d
operator|->
name|privateKey
operator|.
name|algorithm
argument_list|()
operator|==
name|QSsl
operator|::
name|Opaque
condition|)
name|sslContext
operator|->
name|pkey
operator|=
literal|0
expr_stmt|;
comment|// Don't free the private key, it belongs to QSslKey
comment|// Check if the certificate matches the private key.
if|if
condition|(
operator|!
name|q_SSL_CTX_check_private_key
argument_list|(
name|sslContext
operator|->
name|ctx
argument_list|)
condition|)
block|{
name|sslContext
operator|->
name|errorStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"Private key does not certify public key, %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QSslSocketBackendPrivate
operator|::
name|getErrorsFromOpenSsl
argument_list|()
argument_list|)
expr_stmt|;
name|sslContext
operator|->
name|errorCode
operator|=
name|QSslError
operator|::
name|UnspecifiedError
expr_stmt|;
return|return
name|sslContext
return|;
block|}
block|}
comment|// Initialize peer verification.
if|if
condition|(
name|sslContext
operator|->
name|sslConfiguration
operator|.
name|peerVerifyMode
argument_list|()
operator|==
name|QSslSocket
operator|::
name|VerifyNone
condition|)
block|{
name|q_SSL_CTX_set_verify
argument_list|(
name|sslContext
operator|->
name|ctx
argument_list|,
name|SSL_VERIFY_NONE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|q_SSL_CTX_set_verify
argument_list|(
name|sslContext
operator|->
name|ctx
argument_list|,
name|SSL_VERIFY_PEER
argument_list|,
name|q_X509Callback
argument_list|)
expr_stmt|;
block|}
comment|// Set verification depth.
if|if
condition|(
name|sslContext
operator|->
name|sslConfiguration
operator|.
name|peerVerifyDepth
argument_list|()
operator|!=
literal|0
condition|)
name|q_SSL_CTX_set_verify_depth
argument_list|(
name|sslContext
operator|->
name|ctx
argument_list|,
name|sslContext
operator|->
name|sslConfiguration
operator|.
name|peerVerifyDepth
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|sslContext
return|;
block|}
end_function
begin_comment
comment|// Needs to be deleted by caller
end_comment
begin_function
DECL|function|createSsl
name|SSL
modifier|*
name|QSslContext
operator|::
name|createSsl
parameter_list|()
block|{
name|SSL
modifier|*
name|ssl
init|=
name|q_SSL_new
argument_list|(
name|ctx
argument_list|)
decl_stmt|;
name|q_SSL_clear
argument_list|(
name|ssl
argument_list|)
expr_stmt|;
if|if
condition|(
name|session
condition|)
block|{
comment|// Try to resume the last session we cached
if|if
condition|(
operator|!
name|q_SSL_set_session
argument_list|(
name|ssl
argument_list|,
name|session
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"could not set SSL session"
argument_list|)
expr_stmt|;
name|q_SSL_SESSION_free
argument_list|(
name|session
argument_list|)
expr_stmt|;
name|session
operator|=
literal|0
expr_stmt|;
block|}
block|}
return|return
name|ssl
return|;
block|}
end_function
begin_comment
comment|// We cache exactly one session here
end_comment
begin_function
DECL|function|cacheSession
name|bool
name|QSslContext
operator|::
name|cacheSession
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|)
block|{
comment|// dont cache the same session again
if|if
condition|(
name|session
operator|&&
name|session
operator|==
name|q_SSL_get_session
argument_list|(
name|ssl
argument_list|)
condition|)
return|return
literal|true
return|;
comment|// decrease refcount of currently stored session
comment|// (this might happen if there are several concurrent handshakes in flight)
if|if
condition|(
name|session
condition|)
name|q_SSL_SESSION_free
argument_list|(
name|session
argument_list|)
expr_stmt|;
comment|// cache the session the caller gave us and increase reference count
name|session
operator|=
name|q_SSL_get1_session
argument_list|(
name|ssl
argument_list|)
expr_stmt|;
return|return
operator|(
name|session
operator|!=
name|NULL
operator|)
return|;
block|}
end_function
begin_function
DECL|function|error
name|QSslError
operator|::
name|SslError
name|QSslContext
operator|::
name|error
parameter_list|()
specifier|const
block|{
return|return
name|errorCode
return|;
block|}
end_function
begin_function
DECL|function|errorString
name|QString
name|QSslContext
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|errorStr
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
