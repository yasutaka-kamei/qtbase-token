begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QSslError     \brief The QSslError class provides an SSL error.     \since 4.3      \reentrant     \ingroup network     \ingroup ssl     \inmodule QtNetwork      QSslError provides a simple API for managing errors during QSslSocket's     SSL handshake.      \sa QSslSocket, QSslCertificate, QSslCipher */
end_comment
begin_comment
comment|/*!     \enum QSslError::SslError      Describes all recognized errors that can occur during an SSL handshake.          \value NoError     \value UnableToGetIssuerCertificate     \value UnableToDecryptCertificateSignature     \value UnableToDecodeIssuerPublicKey     \value CertificateSignatureFailed     \value CertificateNotYetValid     \value CertificateExpired     \value InvalidNotBeforeField     \value InvalidNotAfterField     \value SelfSignedCertificate     \value SelfSignedCertificateInChain     \value UnableToGetLocalIssuerCertificate     \value UnableToVerifyFirstCertificate     \value CertificateRevoked     \value InvalidCaCertificate     \value PathLengthExceeded     \value InvalidPurpose     \value CertificateUntrusted     \value CertificateRejected     \value SubjectIssuerMismatch     \value AuthorityIssuerSerialNumberMismatch     \value NoPeerCertificate     \value HostNameMismatch     \value UnspecifiedError     \value NoSslSupport     \value CertificateBlacklisted      \sa QSslError::errorString() */
end_comment
begin_include
include|#
directive|include
file|"qsslerror.h"
end_include
begin_include
include|#
directive|include
file|"qsslsocket.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|QSslErrorPrivate
class|class
name|QSslErrorPrivate
block|{
public|public:
DECL|member|error
name|QSslError
operator|::
name|SslError
name|error
decl_stmt|;
DECL|member|certificate
name|QSslCertificate
name|certificate
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     Constructs a QSslError object with no error and default certificate.   */
end_comment
begin_comment
comment|// RVCT compiler in debug build does not like about default values in const-
end_comment
begin_comment
comment|// So as an workaround we define all constructor overloads here explicitly
end_comment
begin_constructor
DECL|function|QSslError
name|QSslError
operator|::
name|QSslError
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslErrorPrivate
argument_list|)
block|{
name|d
operator|->
name|error
operator|=
name|QSslError
operator|::
name|NoError
expr_stmt|;
name|d
operator|->
name|certificate
operator|=
name|QSslCertificate
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QSslError object. The argument specifies the \a     error that occurred.  */
end_comment
begin_constructor
DECL|function|QSslError
name|QSslError
operator|::
name|QSslError
parameter_list|(
name|SslError
name|error
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslErrorPrivate
argument_list|)
block|{
name|d
operator|->
name|error
operator|=
name|error
expr_stmt|;
name|d
operator|->
name|certificate
operator|=
name|QSslCertificate
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QSslError object. The two arguments specify the \a     error that occurred, and which \a certificate the error relates to.      \sa QSslCertificate */
end_comment
begin_constructor
DECL|function|QSslError
name|QSslError
operator|::
name|QSslError
parameter_list|(
name|SslError
name|error
parameter_list|,
specifier|const
name|QSslCertificate
modifier|&
name|certificate
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslErrorPrivate
argument_list|)
block|{
name|d
operator|->
name|error
operator|=
name|error
expr_stmt|;
name|d
operator|->
name|certificate
operator|=
name|certificate
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs an identical copy of \a other. */
end_comment
begin_constructor
DECL|function|QSslError
name|QSslError
operator|::
name|QSslError
parameter_list|(
specifier|const
name|QSslError
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslErrorPrivate
argument_list|)
block|{
operator|*
name|d
operator|.
name|data
argument_list|()
operator|=
operator|*
name|other
operator|.
name|d
operator|.
name|data
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QSslError object. */
end_comment
begin_destructor
DECL|function|~QSslError
name|QSslError
operator|::
name|~
name|QSslError
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \since 4.4      Assigns the contents of \a other to this error. */
end_comment
begin_function
DECL|function|operator =
name|QSslError
modifier|&
name|QSslError
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QSslError
modifier|&
name|other
parameter_list|)
block|{
operator|*
name|d
operator|.
name|data
argument_list|()
operator|=
operator|*
name|other
operator|.
name|d
operator|.
name|data
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4      Returns true if this error is equal to \a other; otherwise returns false. */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QSslError
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QSslError
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|error
operator|==
name|other
operator|.
name|d
operator|->
name|error
operator|&&
name|d
operator|->
name|certificate
operator|==
name|other
operator|.
name|d
operator|->
name|certificate
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QSslError::operator!=(const QSslError&other) const     \since 4.4      Returns true if this error is not equal to \a other; otherwise returns     false. */
end_comment
begin_comment
comment|/*!     Returns the type of the error.      \sa errorString(), certificate() */
end_comment
begin_function
DECL|function|error
name|QSslError
operator|::
name|SslError
name|QSslError
operator|::
name|error
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|error
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a short localized human-readable description of the error.      \sa error(), certificate() */
end_comment
begin_function
DECL|function|errorString
name|QString
name|QSslError
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
name|QString
name|errStr
decl_stmt|;
switch|switch
condition|(
name|d
operator|->
name|error
condition|)
block|{
case|case
name|NoError
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"No error"
argument_list|)
expr_stmt|;
break|break;
case|case
name|UnableToGetIssuerCertificate
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The issuer certificate could not be found"
argument_list|)
expr_stmt|;
break|break;
case|case
name|UnableToDecryptCertificateSignature
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The certificate signature could not be decrypted"
argument_list|)
expr_stmt|;
break|break;
case|case
name|UnableToDecodeIssuerPublicKey
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The public key in the certificate could not be read"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CertificateSignatureFailed
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The signature of the certificate is invalid"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CertificateNotYetValid
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The certificate is not yet valid"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CertificateExpired
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The certificate has expired"
argument_list|)
expr_stmt|;
break|break;
case|case
name|InvalidNotBeforeField
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The certificate's notBefore field contains an invalid time"
argument_list|)
expr_stmt|;
break|break;
case|case
name|InvalidNotAfterField
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The certificate's notAfter field contains an invalid time"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SelfSignedCertificate
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The certificate is self-signed, and untrusted"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SelfSignedCertificateInChain
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The root certificate of the certificate chain is self-signed, and untrusted"
argument_list|)
expr_stmt|;
break|break;
case|case
name|UnableToGetLocalIssuerCertificate
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The issuer certificate of a locally looked up certificate could not be found"
argument_list|)
expr_stmt|;
break|break;
case|case
name|UnableToVerifyFirstCertificate
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"No certificates could be verified"
argument_list|)
expr_stmt|;
break|break;
case|case
name|InvalidCaCertificate
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"One of the CA certificates is invalid"
argument_list|)
expr_stmt|;
break|break;
case|case
name|PathLengthExceeded
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The basicConstraints path length parameter has been exceeded"
argument_list|)
expr_stmt|;
break|break;
case|case
name|InvalidPurpose
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The supplied certificate is unsuitable for this purpose"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CertificateUntrusted
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The root CA certificate is not trusted for this purpose"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CertificateRejected
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The root CA certificate is marked to reject the specified purpose"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SubjectIssuerMismatch
case|:
comment|// hostname mismatch
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The current candidate issuer certificate was rejected because its"
literal|" subject name did not match the issuer name of the current certificate"
argument_list|)
expr_stmt|;
break|break;
case|case
name|AuthorityIssuerSerialNumberMismatch
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The current candidate issuer certificate was rejected because"
literal|" its issuer name and serial number was present and did not match the"
literal|" authority key identifier of the current certificate"
argument_list|)
expr_stmt|;
break|break;
case|case
name|NoPeerCertificate
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The peer did not present any certificate"
argument_list|)
expr_stmt|;
break|break;
case|case
name|HostNameMismatch
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The host name did not match any of the valid hosts"
literal|" for this certificate"
argument_list|)
expr_stmt|;
break|break;
case|case
name|NoSslSupport
case|:
break|break;
case|case
name|CertificateBlacklisted
case|:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"The peer certificate is blacklisted"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|errStr
operator|=
name|QSslSocket
operator|::
name|tr
argument_list|(
literal|"Unknown error"
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|errStr
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the certificate associated with this error, or a null certificate     if the error does not relate to any certificate.      \sa error(), errorString() */
end_comment
begin_function
DECL|function|certificate
name|QSslCertificate
name|QSslError
operator|::
name|certificate
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|certificate
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_comment
comment|//class QDebug;
end_comment
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|debug
parameter_list|,
specifier|const
name|QSslError
modifier|&
name|error
parameter_list|)
block|{
name|debug
operator|<<
name|error
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return
name|debug
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|debug
parameter_list|,
specifier|const
name|QSslError
operator|::
name|SslError
modifier|&
name|error
parameter_list|)
block|{
name|debug
operator|<<
name|QSslError
argument_list|(
name|error
argument_list|)
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return
name|debug
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
