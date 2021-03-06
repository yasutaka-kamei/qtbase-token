begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2014 BlackBerry Limited. All rights reserved. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** In addition, as a special exception, the copyright holders listed above give ** permission to link the code of its release of Qt with the OpenSSL project's ** "OpenSSL" library (or modified versions of the "OpenSSL" library that use the ** same license as the original version), and distribute the linked executables. ** ** You must comply with the GNU General Public License version 2 in all ** respects for all of the code used other than the "OpenSSL" code.  If you ** modify this file, you may extend this exception to your version of the file, ** but you are not obligated to do so.  If you do not wish to do so, delete ** this exception statement from your version of this file. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLCONFIGURATION_H
end_ifndef
begin_define
DECL|macro|QSSLCONFIGURATION_H
define|#
directive|define
name|QSSLCONFIGURATION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qsslsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qssl.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SSL
end_ifndef
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QList
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QSslCertificate
name|class
name|QSslCertificate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslCipher
name|class
name|QSslCipher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslKey
name|class
name|QSslKey
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslEllipticCurve
name|class
name|QSslEllipticCurve
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslConfigurationPrivate
name|class
name|QSslConfigurationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QSslConfiguration
block|{
name|public
label|:
name|QSslConfiguration
argument_list|()
expr_stmt|;
name|QSslConfiguration
argument_list|(
specifier|const
name|QSslConfiguration
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QSslConfiguration
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QSslConfiguration
modifier|&
name|operator
init|=
operator|(
name|QSslConfiguration
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QSslConfiguration
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSslConfiguration
operator|&
name|other
operator|)
decl_stmt|;
name|void
name|swap
parameter_list|(
name|QSslConfiguration
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSslConfiguration
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSslConfiguration
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|QSsl
operator|::
name|SslProtocol
name|protocol
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setProtocol
argument_list|(
name|QSsl
operator|::
name|SslProtocol
name|protocol
argument_list|)
decl_stmt|;
comment|// Verification
name|QSslSocket
operator|::
name|PeerVerifyMode
name|peerVerifyMode
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPeerVerifyMode
argument_list|(
name|QSslSocket
operator|::
name|PeerVerifyMode
name|mode
argument_list|)
decl_stmt|;
name|int
name|peerVerifyDepth
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPeerVerifyDepth
parameter_list|(
name|int
name|depth
parameter_list|)
function_decl|;
comment|// Certificate& cipher configuration
name|QList
operator|<
name|QSslCertificate
operator|>
name|localCertificateChain
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLocalCertificateChain
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCertificate
operator|>
operator|&
name|localChain
argument_list|)
decl_stmt|;
name|QSslCertificate
name|localCertificate
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLocalCertificate
parameter_list|(
specifier|const
name|QSslCertificate
modifier|&
name|certificate
parameter_list|)
function_decl|;
name|QSslCertificate
name|peerCertificate
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QSslCertificate
operator|>
name|peerCertificateChain
argument_list|()
specifier|const
expr_stmt|;
name|QSslCipher
name|sessionCipher
argument_list|()
specifier|const
expr_stmt|;
name|QSsl
operator|::
name|SslProtocol
name|sessionProtocol
argument_list|()
specifier|const
expr_stmt|;
comment|// Private keys, for server sockets
name|QSslKey
name|privateKey
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPrivateKey
parameter_list|(
specifier|const
name|QSslKey
modifier|&
name|key
parameter_list|)
function_decl|;
comment|// Cipher settings
name|QList
operator|<
name|QSslCipher
operator|>
name|ciphers
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCiphers
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCipher
operator|>
operator|&
name|ciphers
argument_list|)
decl_stmt|;
specifier|static
name|QList
operator|<
name|QSslCipher
operator|>
name|supportedCiphers
argument_list|()
expr_stmt|;
comment|// Certificate Authority (CA) settings
name|QList
operator|<
name|QSslCertificate
operator|>
name|caCertificates
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCaCertificates
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCertificate
operator|>
operator|&
name|certificates
argument_list|)
decl_stmt|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|systemCaCertificates
argument_list|()
expr_stmt|;
name|void
name|setSslOption
argument_list|(
name|QSsl
operator|::
name|SslOption
name|option
argument_list|,
name|bool
name|on
argument_list|)
decl_stmt|;
name|bool
name|testSslOption
argument_list|(
name|QSsl
operator|::
name|SslOption
name|option
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|sessionTicket
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSessionTicket
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|sessionTicket
parameter_list|)
function_decl|;
name|int
name|sessionTicketLifeTimeHint
argument_list|()
specifier|const
expr_stmt|;
name|QSslKey
name|ephemeralServerKey
argument_list|()
specifier|const
expr_stmt|;
comment|// EC settings
name|QVector
operator|<
name|QSslEllipticCurve
operator|>
name|ellipticCurves
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setEllipticCurves
argument_list|(
specifier|const
name|QVector
operator|<
name|QSslEllipticCurve
operator|>
operator|&
name|curves
argument_list|)
decl_stmt|;
specifier|static
name|QVector
operator|<
name|QSslEllipticCurve
operator|>
name|supportedEllipticCurves
argument_list|()
expr_stmt|;
specifier|static
name|QSslConfiguration
name|defaultConfiguration
parameter_list|()
function_decl|;
specifier|static
name|void
name|setDefaultConfiguration
parameter_list|(
specifier|const
name|QSslConfiguration
modifier|&
name|configuration
parameter_list|)
function_decl|;
enum|enum
name|NextProtocolNegotiationStatus
block|{
name|NextProtocolNegotiationNone
block|,
name|NextProtocolNegotiationNegotiated
block|,
name|NextProtocolNegotiationUnsupported
block|}
enum|;
if|#
directive|if
name|QT_VERSION
operator|>=
name|QT_VERSION_CHECK
argument_list|(
literal|6
operator|,
literal|0
operator|,
literal|0
argument_list|)
name|void
name|setAllowedNextProtocols
argument_list|(
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
name|protocols
argument_list|)
decl_stmt|;
else|#
directive|else
name|void
name|setAllowedNextProtocols
argument_list|(
name|QList
operator|<
name|QByteArray
operator|>
name|protocols
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|QList
operator|<
name|QByteArray
operator|>
name|allowedNextProtocols
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|nextNegotiatedProtocol
argument_list|()
specifier|const
expr_stmt|;
name|NextProtocolNegotiationStatus
name|nextProtocolNegotiationStatus
argument_list|()
specifier|const
expr_stmt|;
specifier|static
specifier|const
name|char
name|NextProtocolSpdy3_0
index|[]
decl_stmt|;
specifier|static
specifier|const
name|char
name|NextProtocolHttp1_1
index|[]
decl_stmt|;
name|private
label|:
name|friend
name|class
name|QSslSocket
decl_stmt|;
name|friend
name|class
name|QSslConfigurationPrivate
decl_stmt|;
name|friend
name|class
name|QSslSocketBackendPrivate
decl_stmt|;
name|friend
name|class
name|QSslContext
decl_stmt|;
name|QSslConfiguration
argument_list|(
name|QSslConfigurationPrivate
operator|*
name|dd
argument_list|)
expr_stmt|;
name|QSharedDataPointer
operator|<
name|QSslConfigurationPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QSslConfiguration
argument_list|)
end_macro
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QSslConfiguration
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SSL
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
