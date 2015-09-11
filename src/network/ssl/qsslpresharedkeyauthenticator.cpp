begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Governikus GmbH& Co. KG. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsslpresharedkeyauthenticator.h"
end_include
begin_include
include|#
directive|include
file|"qsslpresharedkeyauthenticator_p.h"
end_include
begin_include
include|#
directive|include
file|<QSharedData>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QSslPreSharedKeyAuthenticatorPrivate
name|QSslPreSharedKeyAuthenticatorPrivate
operator|::
name|QSslPreSharedKeyAuthenticatorPrivate
parameter_list|()
member_init_list|:
name|maximumIdentityLength
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|maximumPreSharedKeyLength
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \class QSslPreSharedKeyAuthenticator      \brief The QSslPreSharedKeyAuthenticator class provides authentication data for pre     shared keys (PSK) ciphersuites.      \inmodule QtNetwork      \reentrant      \ingroup network     \ingroup ssl     \ingroup shared      \since 5.5      The QSslPreSharedKeyAuthenticator class is used by an SSL socket to provide     the required authentication data in a pre shared key (PSK) ciphersuite.      In a PSK handshake, the client must derive a key, which must match the key     set on the server. The exact algorithm of deriving the key depends on the     application; however, for this purpose, the server may send an \e{identity     hint} to the client. This hint, combined with other information (for     instance a passphrase), is then used by the client to construct the shared     key.      The QSslPreSharedKeyAuthenticator provides means to client applications for     completing the PSK handshake. The client application needs to connect a     slot to the QSslSocket::preSharedKeyAuthenticationRequired() signal:      \code      connect(socket,&QSslSocket::preSharedKeyAuthenticationRequired,             this,&AuthManager::handlePreSharedKeyAuthentication);      \endcode      The signal carries a QSslPreSharedKeyAuthenticator object containing the     identity hint the server sent to the client, and which must be filled with the     corresponding client identity and the derived key:      \code      void AuthManager::handlePreSharedKeyAuthentication(QSslPreSharedKeyAuthenticator *authenticator)     {         authenticator->setIdentity("My Qt App");          const QByteArray key = deriveKey(authenticator->identityHint(), passphrase);         authenticator->setPreSharedKey(key);     }      \endcode      \note PSK ciphersuites are supported only when using OpenSSL 1.0.1 (or     greater) as the SSL backend.      \sa QSslSocket */
end_comment
begin_comment
comment|/*!     Constructs a default QSslPreSharedKeyAuthenticator object.      The identity hint, the identity and the key will be initialized to empty     byte arrays; the maximum length for both the identity and the key will be     initialized to 0. */
end_comment
begin_constructor
DECL|function|QSslPreSharedKeyAuthenticator
name|QSslPreSharedKeyAuthenticator
operator|::
name|QSslPreSharedKeyAuthenticator
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslPreSharedKeyAuthenticatorPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the QSslPreSharedKeyAuthenticator object. */
end_comment
begin_destructor
DECL|function|~QSslPreSharedKeyAuthenticator
name|QSslPreSharedKeyAuthenticator
operator|::
name|~
name|QSslPreSharedKeyAuthenticator
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Constructs a QSslPreSharedKeyAuthenticator object as a copy of \a authenticator.      \sa operator=() */
end_comment
begin_constructor
DECL|function|QSslPreSharedKeyAuthenticator
name|QSslPreSharedKeyAuthenticator
operator|::
name|QSslPreSharedKeyAuthenticator
parameter_list|(
specifier|const
name|QSslPreSharedKeyAuthenticator
modifier|&
name|authenticator
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|authenticator
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Assigns the QSslPreSharedKeyAuthenticator object \a authenticator to this object,     and returns a reference to the copy. */
end_comment
begin_function
DECL|function|operator =
name|QSslPreSharedKeyAuthenticator
modifier|&
name|QSslPreSharedKeyAuthenticator
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QSslPreSharedKeyAuthenticator
modifier|&
name|authenticator
parameter_list|)
block|{
name|d
operator|=
name|authenticator
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QSslPreSharedKeyAuthenticator&QSslPreSharedKeyAuthenticator::operator=(QSslPreSharedKeyAuthenticator&&authenticator)      Move-assigns the the QSslPreSharedKeyAuthenticator object \a authenticator to this     object, and returns a reference to the moved instance. */
end_comment
begin_comment
comment|/*!     \fn void QSslPreSharedKeyAuthenticator::swap(QSslPreSharedKeyAuthenticator&authenticator)      Swaps the QSslPreSharedKeyAuthenticator object \a authenticator with this object.     This operation is very fast and never fails. */
end_comment
begin_comment
comment|/*!     Returns the PSK identity hint as provided by the server. The interpretation     of this hint is left to the application. */
end_comment
begin_function
DECL|function|identityHint
name|QByteArray
name|QSslPreSharedKeyAuthenticator
operator|::
name|identityHint
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|identityHint
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the PSK client identity (to be advised to the server) to \a identity.      \note it is possible to set an identity whose length is greater than     maximumIdentityLength(); in this case, only the first maximumIdentityLength()     bytes will be actually sent to the server.      \sa identity(), maximumIdentityLength() */
end_comment
begin_function
DECL|function|setIdentity
name|void
name|QSslPreSharedKeyAuthenticator
operator|::
name|setIdentity
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|identity
parameter_list|)
block|{
name|d
operator|->
name|identity
operator|=
name|identity
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the PSK client identity.      \sa setIdentity() */
end_comment
begin_function
DECL|function|identity
name|QByteArray
name|QSslPreSharedKeyAuthenticator
operator|::
name|identity
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|identity
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the maximum length, in bytes, of the PSK client identity.      \note it is possible to set an identity whose length is greater than     maximumIdentityLength(); in this case, only the first maximumIdentityLength()     bytes will be actually sent to the server.      \sa setIdentity() */
end_comment
begin_function
DECL|function|maximumIdentityLength
name|int
name|QSslPreSharedKeyAuthenticator
operator|::
name|maximumIdentityLength
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|maximumIdentityLength
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the pre shared key to \a preSharedKey.      \note it is possible to set a key whose length is greater than the     maximumPreSharedKeyLength(); in this case, only the first     maximumPreSharedKeyLength() bytes will be actually sent to the server.      \sa preSharedKey(), maximumPreSharedKeyLength(), QByteArray::fromHex() */
end_comment
begin_function
DECL|function|setPreSharedKey
name|void
name|QSslPreSharedKeyAuthenticator
operator|::
name|setPreSharedKey
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|preSharedKey
parameter_list|)
block|{
name|d
operator|->
name|preSharedKey
operator|=
name|preSharedKey
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the pre shared key.      \sa setPreSharedKey() */
end_comment
begin_function
DECL|function|preSharedKey
name|QByteArray
name|QSslPreSharedKeyAuthenticator
operator|::
name|preSharedKey
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|preSharedKey
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the maximum length, in bytes, of the pre shared key.      \note it is possible to set a key whose length is greater than the     maximumPreSharedKeyLength(); in this case, only the first     maximumPreSharedKeyLength() bytes will be actually sent to the server.      \sa setPreSharedKey() */
end_comment
begin_function
DECL|function|maximumPreSharedKeyLength
name|int
name|QSslPreSharedKeyAuthenticator
operator|::
name|maximumPreSharedKeyLength
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|maximumPreSharedKeyLength
return|;
block|}
end_function
begin_comment
comment|/*!     \relates QSslPreSharedKeyAuthenticator     \since 5.5      Returns true if the authenticator object \a lhs is equal to \a rhs; false     otherwise.      Two authenticator objects are equal if and only if they have the same     identity hint, identity, pre shared key, maximum length for the identity     and maximum length for the pre shared key.  */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|QSslPreSharedKeyAuthenticator
modifier|&
name|lhs
parameter_list|,
specifier|const
name|QSslPreSharedKeyAuthenticator
modifier|&
name|rhs
parameter_list|)
block|{
return|return
operator|(
operator|(
name|lhs
operator|.
name|d
operator|==
name|rhs
operator|.
name|d
operator|)
operator|||
operator|(
name|lhs
operator|.
name|d
operator|->
name|identityHint
operator|==
name|rhs
operator|.
name|d
operator|->
name|identityHint
operator|&&
name|lhs
operator|.
name|d
operator|->
name|identity
operator|==
name|rhs
operator|.
name|d
operator|->
name|identity
operator|&&
name|lhs
operator|.
name|d
operator|->
name|maximumIdentityLength
operator|==
name|rhs
operator|.
name|d
operator|->
name|maximumIdentityLength
operator|&&
name|lhs
operator|.
name|d
operator|->
name|preSharedKey
operator|==
name|rhs
operator|.
name|d
operator|->
name|preSharedKey
operator|&&
name|lhs
operator|.
name|d
operator|->
name|maximumPreSharedKeyLength
operator|==
name|rhs
operator|.
name|d
operator|->
name|maximumPreSharedKeyLength
operator|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool operator!=(const QSslPreSharedKeyAuthenticator&lhs, const QSslPreSharedKeyAuthenticator&rhs)     \relates QSslPreSharedKeyAuthenticator     \since 5.5      Returns true if the authenticator object \a lhs is different than \a rhs;     false otherwise.  */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
