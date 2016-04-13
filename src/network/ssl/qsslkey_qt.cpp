begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Jeremy LainÃ©<jeremy.laine@m4x.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsslkey.h"
end_include
begin_include
include|#
directive|include
file|"qsslkey_p.h"
end_include
begin_include
include|#
directive|include
file|"qasn1element_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcryptographichash.h>
end_include
begin_decl_stmt
name|QT_USE_NAMESPACE
DECL|variable|bits_table
specifier|static
specifier|const
name|quint8
name|bits_table
index|[
literal|256
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|2
block|,
literal|3
block|,
literal|3
block|,
literal|3
block|,
literal|3
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|7
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|,
literal|8
block|, }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// OIDs of named curves allowed in TLS as per RFCs 4492 and 7027,
end_comment
begin_comment
comment|// see also https://www.iana.org/assignments/tls-parameters/tls-parameters.xhtml#tls-parameters-8
end_comment
begin_typedef
DECL|typedef|OidLengthMap
typedef|typedef
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|int
argument_list|>
name|OidLengthMap
typedef|;
end_typedef
begin_function
DECL|function|createOidMap
specifier|static
name|OidLengthMap
name|createOidMap
parameter_list|()
block|{
name|OidLengthMap
name|oids
decl_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.2.840.10045.3.1.1"
argument_list|)
argument_list|,
literal|192
argument_list|)
expr_stmt|;
comment|// secp192r1 a.k.a prime192v1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.2.840.10045.3.1.7"
argument_list|)
argument_list|,
literal|256
argument_list|)
expr_stmt|;
comment|// secp256r1 a.k.a prime256v1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.1"
argument_list|)
argument_list|,
literal|193
argument_list|)
expr_stmt|;
comment|// sect193r2
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.10"
argument_list|)
argument_list|,
literal|256
argument_list|)
expr_stmt|;
comment|// secp256k1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.16"
argument_list|)
argument_list|,
literal|283
argument_list|)
expr_stmt|;
comment|// sect283k1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.17"
argument_list|)
argument_list|,
literal|283
argument_list|)
expr_stmt|;
comment|// sect283r1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.26"
argument_list|)
argument_list|,
literal|233
argument_list|)
expr_stmt|;
comment|// sect233k1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.27"
argument_list|)
argument_list|,
literal|233
argument_list|)
expr_stmt|;
comment|// sect233r1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.3"
argument_list|)
argument_list|,
literal|239
argument_list|)
expr_stmt|;
comment|// sect239k1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.30"
argument_list|)
argument_list|,
literal|160
argument_list|)
expr_stmt|;
comment|// secp160r2
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.31"
argument_list|)
argument_list|,
literal|192
argument_list|)
expr_stmt|;
comment|// secp192k1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.32"
argument_list|)
argument_list|,
literal|224
argument_list|)
expr_stmt|;
comment|// secp224k1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.33"
argument_list|)
argument_list|,
literal|224
argument_list|)
expr_stmt|;
comment|// secp224r1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.34"
argument_list|)
argument_list|,
literal|384
argument_list|)
expr_stmt|;
comment|// secp384r1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.35"
argument_list|)
argument_list|,
literal|521
argument_list|)
expr_stmt|;
comment|// secp521r1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.36"
argument_list|)
argument_list|,
literal|409
argument_list|)
expr_stmt|;
comment|// sect409k1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.37"
argument_list|)
argument_list|,
literal|409
argument_list|)
expr_stmt|;
comment|// sect409r1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.38"
argument_list|)
argument_list|,
literal|571
argument_list|)
expr_stmt|;
comment|// sect571k1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.39"
argument_list|)
argument_list|,
literal|571
argument_list|)
expr_stmt|;
comment|// sect571r1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.8"
argument_list|)
argument_list|,
literal|160
argument_list|)
expr_stmt|;
comment|// secp160r1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.132.0.9"
argument_list|)
argument_list|,
literal|160
argument_list|)
expr_stmt|;
comment|// secp160k1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.36.3.3.2.8.1.1.11"
argument_list|)
argument_list|,
literal|384
argument_list|)
expr_stmt|;
comment|// brainpoolP384r1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.36.3.3.2.8.1.1.13"
argument_list|)
argument_list|,
literal|521
argument_list|)
expr_stmt|;
comment|// brainpoolP512r1
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|cend
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.36.3.3.2.8.1.1.7"
argument_list|)
argument_list|,
literal|256
argument_list|)
expr_stmt|;
comment|// brainpoolP256r1
return|return
name|oids
return|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
argument|OidLengthMap
argument_list|,
argument|oidLengthMap
argument_list|,
argument|(createOidMap())
argument_list|)
end_macro
begin_function
DECL|function|curveBits
specifier|static
name|int
name|curveBits
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|oid
parameter_list|)
block|{
specifier|const
name|int
name|length
init|=
name|oidLengthMap
operator|->
name|value
argument_list|(
name|oid
argument_list|)
decl_stmt|;
return|return
name|length
condition|?
name|length
else|:
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|numberOfBits
specifier|static
name|int
name|numberOfBits
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|modulus
parameter_list|)
block|{
name|int
name|bits
init|=
name|modulus
operator|.
name|size
argument_list|()
operator|*
literal|8
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|modulus
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|quint8
name|b
init|=
name|modulus
index|[
name|i
index|]
decl_stmt|;
name|bits
operator|-=
literal|8
expr_stmt|;
if|if
condition|(
name|b
operator|!=
literal|0
condition|)
block|{
name|bits
operator|+=
name|bits_table
index|[
name|b
index|]
expr_stmt|;
break|break;
block|}
block|}
return|return
name|bits
return|;
block|}
end_function
begin_function
DECL|function|deriveKey
specifier|static
name|QByteArray
name|deriveKey
parameter_list|(
name|QSslKeyPrivate
operator|::
name|Cipher
name|cipher
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|passPhrase
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|iv
parameter_list|)
block|{
name|QByteArray
name|key
decl_stmt|;
name|QCryptographicHash
name|hash
argument_list|(
name|QCryptographicHash
operator|::
name|Md5
argument_list|)
decl_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|passPhrase
argument_list|)
expr_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|iv
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cipher
condition|)
block|{
case|case
name|QSslKeyPrivate
operator|::
name|DesCbc
case|:
name|key
operator|=
name|hash
operator|.
name|result
argument_list|()
operator|.
name|left
argument_list|(
literal|8
argument_list|)
expr_stmt|;
break|break;
case|case
name|QSslKeyPrivate
operator|::
name|DesEde3Cbc
case|:
name|key
operator|=
name|hash
operator|.
name|result
argument_list|()
expr_stmt|;
name|hash
operator|.
name|reset
argument_list|()
expr_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|key
argument_list|)
expr_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|passPhrase
argument_list|)
expr_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|iv
argument_list|)
expr_stmt|;
name|key
operator|+=
name|hash
operator|.
name|result
argument_list|()
operator|.
name|left
argument_list|(
literal|8
argument_list|)
expr_stmt|;
break|break;
case|case
name|QSslKeyPrivate
operator|::
name|Rc2Cbc
case|:
name|key
operator|=
name|hash
operator|.
name|result
argument_list|()
expr_stmt|;
break|break;
block|}
return|return
name|key
return|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|QSslKeyPrivate
operator|::
name|clear
parameter_list|(
name|bool
name|deep
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|deep
argument_list|)
expr_stmt|;
name|isNull
operator|=
literal|true
expr_stmt|;
name|derData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|keyLength
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|decodeDer
name|void
name|QSslKeyPrivate
operator|::
name|decodeDer
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|der
parameter_list|,
name|bool
name|deepClear
parameter_list|)
block|{
name|clear
argument_list|(
name|deepClear
argument_list|)
expr_stmt|;
if|if
condition|(
name|der
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QAsn1Element
name|elem
decl_stmt|;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|der
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return;
if|if
condition|(
name|type
operator|==
name|QSsl
operator|::
name|PublicKey
condition|)
block|{
comment|// key info
name|QDataStream
name|keyStream
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|keyStream
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return;
specifier|const
name|QVector
argument_list|<
name|QAsn1Element
argument_list|>
name|infoItems
init|=
name|elem
operator|.
name|toVector
argument_list|()
decl_stmt|;
if|if
condition|(
name|infoItems
operator|.
name|size
argument_list|()
operator|<
literal|2
operator|||
name|infoItems
index|[
literal|0
index|]
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|ObjectIdentifierType
condition|)
return|return;
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Rsa
condition|)
block|{
if|if
condition|(
name|infoItems
index|[
literal|0
index|]
operator|.
name|toObjectId
argument_list|()
operator|!=
name|RSA_ENCRYPTION_OID
condition|)
return|return;
comment|// key data
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|keyStream
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|BitStringType
operator|||
name|elem
operator|.
name|value
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|elem
operator|.
name|value
argument_list|()
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return;
if|if
condition|(
operator|!
name|elem
operator|.
name|read
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|)
operator|||
name|elem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|IntegerType
condition|)
return|return;
name|keyLength
operator|=
name|numberOfBits
argument_list|(
name|elem
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Dsa
condition|)
block|{
if|if
condition|(
name|infoItems
index|[
literal|0
index|]
operator|.
name|toObjectId
argument_list|()
operator|!=
name|DSA_ENCRYPTION_OID
condition|)
return|return;
if|if
condition|(
name|infoItems
index|[
literal|1
index|]
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|SequenceType
condition|)
return|return;
comment|// key params
specifier|const
name|QVector
argument_list|<
name|QAsn1Element
argument_list|>
name|params
init|=
name|infoItems
index|[
literal|1
index|]
operator|.
name|toVector
argument_list|()
decl_stmt|;
if|if
condition|(
name|params
operator|.
name|isEmpty
argument_list|()
operator|||
name|params
index|[
literal|0
index|]
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|IntegerType
condition|)
return|return;
name|keyLength
operator|=
name|numberOfBits
argument_list|(
name|params
index|[
literal|0
index|]
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Ec
condition|)
block|{
if|if
condition|(
name|infoItems
index|[
literal|0
index|]
operator|.
name|toObjectId
argument_list|()
operator|!=
name|EC_ENCRYPTION_OID
condition|)
return|return;
if|if
condition|(
name|infoItems
index|[
literal|1
index|]
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|ObjectIdentifierType
condition|)
return|return;
name|keyLength
operator|=
name|curveBits
argument_list|(
name|infoItems
index|[
literal|1
index|]
operator|.
name|toObjectId
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
specifier|const
name|QVector
argument_list|<
name|QAsn1Element
argument_list|>
name|items
init|=
name|elem
operator|.
name|toVector
argument_list|()
decl_stmt|;
if|if
condition|(
name|items
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
comment|// version
if|if
condition|(
name|items
index|[
literal|0
index|]
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|IntegerType
condition|)
return|return;
specifier|const
name|QByteArray
name|versionHex
init|=
name|items
index|[
literal|0
index|]
operator|.
name|value
argument_list|()
operator|.
name|toHex
argument_list|()
decl_stmt|;
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Rsa
condition|)
block|{
if|if
condition|(
name|versionHex
operator|!=
literal|"00"
condition|)
return|return;
if|if
condition|(
name|items
operator|.
name|size
argument_list|()
operator|!=
literal|9
operator|||
name|items
index|[
literal|1
index|]
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|IntegerType
condition|)
return|return;
name|keyLength
operator|=
name|numberOfBits
argument_list|(
name|items
index|[
literal|1
index|]
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Dsa
condition|)
block|{
if|if
condition|(
name|versionHex
operator|!=
literal|"00"
condition|)
return|return;
if|if
condition|(
name|items
operator|.
name|size
argument_list|()
operator|!=
literal|6
operator|||
name|items
index|[
literal|1
index|]
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|IntegerType
condition|)
return|return;
name|keyLength
operator|=
name|numberOfBits
argument_list|(
name|items
index|[
literal|1
index|]
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|algorithm
operator|==
name|QSsl
operator|::
name|Ec
condition|)
block|{
if|if
condition|(
name|versionHex
operator|!=
literal|"01"
condition|)
return|return;
if|if
condition|(
name|items
operator|.
name|size
argument_list|()
operator|!=
literal|4
operator|||
name|items
index|[
literal|1
index|]
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|OctetStringType
operator|||
name|items
index|[
literal|2
index|]
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|Context0Type
operator|||
name|items
index|[
literal|3
index|]
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|Context1Type
condition|)
return|return;
name|QAsn1Element
name|oidElem
decl_stmt|;
if|if
condition|(
operator|!
name|oidElem
operator|.
name|read
argument_list|(
name|items
index|[
literal|2
index|]
operator|.
name|value
argument_list|()
argument_list|)
operator|||
name|oidElem
operator|.
name|type
argument_list|()
operator|!=
name|QAsn1Element
operator|::
name|ObjectIdentifierType
condition|)
return|return;
name|keyLength
operator|=
name|curveBits
argument_list|(
name|oidElem
operator|.
name|toObjectId
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|derData
operator|=
name|der
expr_stmt|;
name|isNull
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|decodePem
name|void
name|QSslKeyPrivate
operator|::
name|decodePem
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|pem
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|passPhrase
parameter_list|,
name|bool
name|deepClear
parameter_list|)
block|{
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
name|headers
decl_stmt|;
name|QByteArray
name|data
init|=
name|derFromPem
argument_list|(
name|pem
argument_list|,
operator|&
name|headers
argument_list|)
decl_stmt|;
if|if
condition|(
name|headers
operator|.
name|value
argument_list|(
literal|"Proc-Type"
argument_list|)
operator|==
literal|"4,ENCRYPTED"
condition|)
block|{
specifier|const
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|dekInfo
init|=
name|headers
operator|.
name|value
argument_list|(
literal|"DEK-Info"
argument_list|)
operator|.
name|split
argument_list|(
literal|','
argument_list|)
decl_stmt|;
if|if
condition|(
name|dekInfo
operator|.
name|size
argument_list|()
operator|!=
literal|2
condition|)
block|{
name|clear
argument_list|(
name|deepClear
argument_list|)
expr_stmt|;
return|return;
block|}
name|Cipher
name|cipher
decl_stmt|;
if|if
condition|(
name|dekInfo
operator|.
name|first
argument_list|()
operator|==
literal|"DES-CBC"
condition|)
block|{
name|cipher
operator|=
name|DesCbc
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dekInfo
operator|.
name|first
argument_list|()
operator|==
literal|"DES-EDE3-CBC"
condition|)
block|{
name|cipher
operator|=
name|DesEde3Cbc
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dekInfo
operator|.
name|first
argument_list|()
operator|==
literal|"RC2-CBC"
condition|)
block|{
name|cipher
operator|=
name|Rc2Cbc
expr_stmt|;
block|}
else|else
block|{
name|clear
argument_list|(
name|deepClear
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|const
name|QByteArray
name|iv
init|=
name|QByteArray
operator|::
name|fromHex
argument_list|(
name|dekInfo
operator|.
name|last
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QByteArray
name|key
init|=
name|deriveKey
argument_list|(
name|cipher
argument_list|,
name|passPhrase
argument_list|,
name|iv
argument_list|)
decl_stmt|;
name|data
operator|=
name|decrypt
argument_list|(
name|cipher
argument_list|,
name|data
argument_list|,
name|key
argument_list|,
name|iv
argument_list|)
expr_stmt|;
block|}
name|decodeDer
argument_list|(
name|data
argument_list|,
name|deepClear
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|length
name|int
name|QSslKeyPrivate
operator|::
name|length
parameter_list|()
specifier|const
block|{
return|return
name|keyLength
return|;
block|}
end_function
begin_function
DECL|function|toPem
name|QByteArray
name|QSslKeyPrivate
operator|::
name|toPem
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|passPhrase
parameter_list|)
specifier|const
block|{
name|QByteArray
name|data
decl_stmt|;
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
name|headers
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|QSsl
operator|::
name|PrivateKey
operator|&&
operator|!
name|passPhrase
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// ### use a cryptographically secure random number generator
name|QByteArray
name|iv
decl_stmt|;
name|iv
operator|.
name|resize
argument_list|(
literal|8
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
name|iv
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|iv
index|[
name|i
index|]
operator|=
operator|(
name|qrand
argument_list|()
operator|&
literal|0xff
operator|)
expr_stmt|;
name|Cipher
name|cipher
init|=
name|DesEde3Cbc
decl_stmt|;
specifier|const
name|QByteArray
name|key
init|=
name|deriveKey
argument_list|(
name|cipher
argument_list|,
name|passPhrase
argument_list|,
name|iv
argument_list|)
decl_stmt|;
name|data
operator|=
name|encrypt
argument_list|(
name|cipher
argument_list|,
name|derData
argument_list|,
name|key
argument_list|,
name|iv
argument_list|)
expr_stmt|;
name|headers
operator|.
name|insert
argument_list|(
literal|"Proc-Type"
argument_list|,
literal|"4,ENCRYPTED"
argument_list|)
expr_stmt|;
name|headers
operator|.
name|insert
argument_list|(
literal|"DEK-Info"
argument_list|,
literal|"DES-EDE3-CBC,"
operator|+
name|iv
operator|.
name|toHex
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|data
operator|=
name|derData
expr_stmt|;
block|}
return|return
name|pemFromDer
argument_list|(
name|data
argument_list|,
name|headers
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|handle
name|Qt
operator|::
name|HANDLE
name|QSslKeyPrivate
operator|::
name|handle
parameter_list|()
specifier|const
block|{
return|return
name|opaque
return|;
block|}
end_function
end_unit
