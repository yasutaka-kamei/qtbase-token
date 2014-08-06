begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtCore/qfunctions_winrt.h>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.security.cryptography.h>
end_include
begin_include
include|#
directive|include
file|<windows.security.cryptography.core.h>
end_include
begin_include
include|#
directive|include
file|<windows.security.cryptography.certificates.h>
end_include
begin_include
include|#
directive|include
file|<windows.storage.streams.h>
end_include
begin_include
include|#
directive|include
file|<robuffer.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Security
operator|::
name|Cryptography
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Security
operator|::
name|Cryptography
operator|::
name|Certificates
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Security
operator|::
name|Cryptography
operator|::
name|Core
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Storage
operator|::
name|Streams
namespace|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|SslKeyGlobal
struct|struct
name|SslKeyGlobal
block|{
DECL|function|SslKeyGlobal
name|SslKeyGlobal
parameter_list|()
block|{
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Security_Cryptography_CryptographicBuffer
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|bufferFactory
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IAsymmetricKeyAlgorithmProviderStatics
argument_list|>
name|keyProviderFactory
decl_stmt|;
name|hr
operator|=
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Security_Cryptography_Core_AsymmetricKeyAlgorithmProvider
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|keyProviderFactory
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IAsymmetricAlgorithmNamesStatics
argument_list|>
name|algorithmNames
decl_stmt|;
name|hr
operator|=
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Security_Cryptography_Core_AsymmetricAlgorithmNames
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|algorithmNames
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|HString
name|algorithmName
decl_stmt|;
comment|// The algorithm name doesn't matter for imports, so just use PKCS1
name|hr
operator|=
name|algorithmNames
operator|->
name|get_RsaPkcs1
argument_list|(
name|algorithmName
operator|.
name|GetAddressOf
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|keyProviderFactory
operator|->
name|OpenAlgorithm
argument_list|(
name|algorithmName
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|keyProvider
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
DECL|member|bufferFactory
name|ComPtr
argument_list|<
name|ICryptographicBufferStatics
argument_list|>
name|bufferFactory
decl_stmt|;
DECL|member|keyProvider
name|ComPtr
argument_list|<
name|IAsymmetricKeyAlgorithmProvider
argument_list|>
name|keyProvider
decl_stmt|;
block|}
struct|;
end_struct
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|SslKeyGlobal
argument_list|,
argument|g
argument_list|)
end_macro
begin_comment
comment|// Use the opaque struct for key storage
end_comment
begin_struct
DECL|struct|EVP_PKEY
struct|struct
name|EVP_PKEY
block|{
DECL|member|key
name|ComPtr
argument_list|<
name|ICryptographicKey
argument_list|>
name|key
decl_stmt|;
block|}
struct|;
end_struct
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
name|isNull
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|opaque
condition|)
block|{
if|if
condition|(
name|deep
condition|)
block|{
operator|delete
name|opaque
expr_stmt|;
name|opaque
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|opaque
operator|->
name|key
operator|.
name|Reset
argument_list|()
expr_stmt|;
block|}
block|}
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
specifier|const
name|QByteArray
modifier|&
name|passPhrase
parameter_list|,
name|bool
name|deepClear
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|passPhrase
argument_list|)
expr_stmt|;
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
if|if
condition|(
name|type
operator|!=
name|QSsl
operator|::
name|PublicKey
condition|)
block|{
name|qWarning
argument_list|(
literal|"The WinRT SSL backend does not support importing private keys."
argument_list|)
expr_stmt|;
return|return;
block|}
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|IBuffer
argument_list|>
name|buffer
decl_stmt|;
name|hr
operator|=
name|g
operator|->
name|bufferFactory
operator|->
name|CreateFromByteArray
argument_list|(
name|der
operator|.
name|length
argument_list|()
argument_list|,
operator|(
name|BYTE
operator|*
operator|)
name|der
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|buffer
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|opaque
condition|)
name|opaque
operator|=
operator|new
name|EVP_PKEY
expr_stmt|;
name|hr
operator|=
name|g
operator|->
name|keyProvider
operator|->
name|ImportDefaultPublicKeyBlob
argument_list|(
name|buffer
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|opaque
operator|->
name|key
argument_list|)
expr_stmt|;
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Failed to import public key"
argument_list|)
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
name|decodeDer
argument_list|(
name|derFromPem
argument_list|(
name|pem
argument_list|)
argument_list|,
name|passPhrase
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
if|if
condition|(
name|isNull
condition|)
return|return
operator|-
literal|1
return|;
name|Q_ASSERT
argument_list|(
name|opaque
operator|&&
name|opaque
operator|->
name|key
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
name|UINT32
name|keySize
decl_stmt|;
name|hr
operator|=
name|opaque
operator|->
name|key
operator|->
name|get_KeySize
argument_list|(
operator|&
name|keySize
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
return|return
name|keySize
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
name|Q_UNUSED
argument_list|(
name|passPhrase
argument_list|)
expr_stmt|;
name|QByteArray
name|result
decl_stmt|;
if|if
condition|(
name|isNull
condition|)
return|return
name|result
return|;
name|Q_ASSERT
argument_list|(
name|opaque
operator|&&
name|opaque
operator|->
name|key
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|IBuffer
argument_list|>
name|buffer
decl_stmt|;
name|hr
operator|=
name|opaque
operator|->
name|key
operator|->
name|ExportDefaultPublicKeyBlobType
argument_list|(
operator|&
name|buffer
argument_list|)
expr_stmt|;
name|RETURN_IF_FAILED
argument_list|(
literal|"Failed to export key"
argument_list|,
argument|return result
argument_list|)
empty_stmt|;
name|ComPtr
argument_list|<
name|Windows
operator|::
name|Storage
operator|::
name|Streams
operator|::
name|IBufferByteAccess
argument_list|>
name|byteAccess
decl_stmt|;
name|hr
operator|=
name|buffer
operator|.
name|As
argument_list|(
operator|&
name|byteAccess
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
name|hr
operator|=
name|byteAccess
operator|->
name|Buffer
argument_list|(
cast|reinterpret_cast
argument_list|<
name|byte
operator|*
operator|*
argument_list|>
argument_list|(
operator|&
name|data
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|UINT32
name|size
decl_stmt|;
name|hr
operator|=
name|buffer
operator|->
name|get_Length
argument_list|(
operator|&
name|size
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|result
operator|=
name|pemFromDer
argument_list|(
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|data
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
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
condition|?
name|opaque
operator|->
name|key
operator|.
name|Get
argument_list|()
else|:
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit