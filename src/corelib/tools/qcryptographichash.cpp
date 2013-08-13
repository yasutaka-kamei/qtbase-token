begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2013 Richard J. Moore<rich@kde.org>. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qcryptographichash.h>
end_include
begin_include
include|#
directive|include
file|<qiodevice.h>
end_include
begin_include
include|#
directive|include
file|"../../3rdparty/sha1/sha1.cpp"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_CRYPTOGRAPHICHASH_ONLY_SHA1
argument_list|)
end_if
begin_error
error|#
directive|error
literal|"Are you sure you need the other hashing algorithms besides SHA-1?"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_CRYPTOGRAPHICHASH_ONLY_SHA1
end_ifndef
begin_comment
comment|// qdoc and qmake only need SHA-1
end_comment
begin_include
include|#
directive|include
file|"../../3rdparty/md5/md5.h"
end_include
begin_include
include|#
directive|include
file|"../../3rdparty/md5/md5.cpp"
end_include
begin_include
include|#
directive|include
file|"../../3rdparty/md4/md4.h"
end_include
begin_include
include|#
directive|include
file|"../../3rdparty/md4/md4.cpp"
end_include
begin_typedef
DECL|typedef|BitSequence
typedef|typedef
name|unsigned
name|char
name|BitSequence
typedef|;
end_typedef
begin_typedef
DECL|typedef|DataLength
typedef|typedef
name|unsigned
name|long
name|long
name|DataLength
typedef|;
end_typedef
begin_typedef
DECL|enumerator|SUCCESS
DECL|enumerator|FAIL
DECL|enumerator|BAD_HASHLEN
DECL|typedef|HashReturn
typedef|typedef
enum|enum
block|{
name|SUCCESS
init|=
literal|0
block|,
name|FAIL
init|=
literal|1
block|,
name|BAD_HASHLEN
init|=
literal|2
block|}
name|HashReturn
typedef|;
end_typedef
begin_include
include|#
directive|include
file|"../../3rdparty/sha3/KeccakSponge.c"
end_include
begin_typedef
DECL|typedef|hashState
typedef|typedef
name|spongeState
name|hashState
typedef|;
end_typedef
begin_include
include|#
directive|include
file|"../../3rdparty/sha3/KeccakNISTInterface.c"
end_include
begin_comment
comment|/*   This lets us choose between SHA3 implementations at build time.  */
end_comment
begin_typedef
DECL|typedef|SHA3Context
typedef|typedef
name|spongeState
name|SHA3Context
typedef|;
end_typedef
begin_typedef
DECL|typedef|SHA3Init
typedef|typedef
name|HashReturn
function_decl|(
name|SHA3Init
function_decl|)
parameter_list|(
name|hashState
modifier|*
name|state
parameter_list|,
name|int
name|hashbitlen
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|SHA3Update
typedef|typedef
name|HashReturn
function_decl|(
name|SHA3Update
function_decl|)
parameter_list|(
name|hashState
modifier|*
name|state
parameter_list|,
specifier|const
name|BitSequence
modifier|*
name|data
parameter_list|,
name|DataLength
name|databitlen
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|SHA3Final
typedef|typedef
name|HashReturn
function_decl|(
name|SHA3Final
function_decl|)
parameter_list|(
name|hashState
modifier|*
name|state
parameter_list|,
name|BitSequence
modifier|*
name|hashval
parameter_list|)
function_decl|;
end_typedef
begin_if
if|#
directive|if
name|QT_POINTER_SIZE
operator|==
literal|8
end_if
begin_comment
comment|// 64 bit version
end_comment
begin_include
include|#
directive|include
file|"../../3rdparty/sha3/KeccakF-1600-opt64.c"
end_include
begin_decl_stmt
DECL|variable|sha3Init
specifier|static
name|SHA3Init
modifier|*
specifier|const
name|sha3Init
init|=
name|Init
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sha3Update
specifier|static
name|SHA3Update
modifier|*
specifier|const
name|sha3Update
init|=
name|Update
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sha3Final
specifier|static
name|SHA3Final
modifier|*
specifier|const
name|sha3Final
init|=
name|Final
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// 32 bit optimised fallback
end_comment
begin_include
include|#
directive|include
file|"../../3rdparty/sha3/KeccakF-1600-opt32.c"
end_include
begin_decl_stmt
DECL|variable|sha3Init
specifier|static
name|SHA3Init
modifier|*
specifier|const
name|sha3Init
init|=
name|Init
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sha3Update
specifier|static
name|SHA3Update
modifier|*
specifier|const
name|sha3Update
init|=
name|Update
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|sha3Final
specifier|static
name|SHA3Final
modifier|*
specifier|const
name|sha3Final
init|=
name|Final
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*     These #defines replace the typedefs needed by the RFC6234 code. Normally     the typedefs would come from from stdint.h, but since this header is not     available on all platforms (MSVC 2008, for example), we #define them to the     Qt equivalents. */
end_comment
begin_define
DECL|macro|uint64_t
define|#
directive|define
name|uint64_t
value|QT_PREPEND_NAMESPACE(quint64)
end_define
begin_define
DECL|macro|uint32_t
define|#
directive|define
name|uint32_t
value|QT_PREPEND_NAMESPACE(quint32)
end_define
begin_define
DECL|macro|uint8_t
define|#
directive|define
name|uint8_t
value|QT_PREPEND_NAMESPACE(quint8)
end_define
begin_define
DECL|macro|int_least16_t
define|#
directive|define
name|int_least16_t
value|QT_PREPEND_NAMESPACE(qint16)
end_define
begin_comment
comment|// Header from rfc6234 with 1 modification:
end_comment
begin_comment
comment|// sha1.h - commented out '#include<stdint.h>' on line 74
end_comment
begin_include
include|#
directive|include
file|"../../3rdparty/rfc6234/sha.h"
end_include
begin_comment
comment|/*     These 2 functions replace macros of the same name in sha224-256.c and     sha384-512.c. Originally, these macros relied on a global static 'addTemp'     variable. We do not want this for 2 reasons:      1. since we are including the sources directly, the declaration of the 2 conflict      2. static variables are not thread-safe, we do not want multiple threads     computing a hash to corrupt one another */
end_comment
begin_function_decl
specifier|static
name|int
name|SHA224_256AddLength
parameter_list|(
name|SHA256Context
modifier|*
name|context
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|SHA384_512AddLength
parameter_list|(
name|SHA512Context
modifier|*
name|context
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// Sources from rfc6234, with 4 modifications:
end_comment
begin_comment
comment|// sha224-256.c - commented out 'static uint32_t addTemp;' on line 68
end_comment
begin_comment
comment|// sha224-256.c - appended 'M' to the SHA224_256AddLength macro on line 70
end_comment
begin_include
include|#
directive|include
file|"../../3rdparty/rfc6234/sha224-256.c"
end_include
begin_comment
comment|// sha384-512.c - commented out 'static uint64_t addTemp;' on line 302
end_comment
begin_comment
comment|// sha384-512.c - appended 'M' to the SHA224_256AddLength macro on line 304
end_comment
begin_include
include|#
directive|include
file|"../../3rdparty/rfc6234/sha384-512.c"
end_include
begin_undef
DECL|macro|uint64_t
undef|#
directive|undef
name|uint64_t
end_undef
begin_undef
DECL|macro|uint32_t
undef|#
directive|undef
name|uint32_t
end_undef
begin_undef
DECL|macro|uint68_t
undef|#
directive|undef
name|uint68_t
end_undef
begin_undef
DECL|macro|int_least16_t
undef|#
directive|undef
name|int_least16_t
end_undef
begin_function
DECL|function|SHA224_256AddLength
specifier|static
specifier|inline
name|int
name|SHA224_256AddLength
parameter_list|(
name|SHA256Context
modifier|*
name|context
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
block|{
name|QT_PREPEND_NAMESPACE
argument_list|(
argument|quint32
argument_list|)
name|addTemp
expr_stmt|;
return|return
name|SHA224_256AddLengthM
argument_list|(
name|context
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|SHA384_512AddLength
specifier|static
specifier|inline
name|int
name|SHA384_512AddLength
parameter_list|(
name|SHA512Context
modifier|*
name|context
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
block|{
name|QT_PREPEND_NAMESPACE
argument_list|(
argument|quint64
argument_list|)
name|addTemp
expr_stmt|;
return|return
name|SHA384_512AddLengthM
argument_list|(
name|context
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_CRYPTOGRAPHICHASH_ONLY_SHA1
end_comment
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QCryptographicHashPrivate
class|class
name|QCryptographicHashPrivate
block|{
public|public:
DECL|member|method
name|QCryptographicHash
operator|::
name|Algorithm
name|method
decl_stmt|;
union|union
block|{
DECL|member|sha1Context
name|Sha1State
name|sha1Context
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_CRYPTOGRAPHICHASH_ONLY_SHA1
DECL|member|md5Context
name|MD5Context
name|md5Context
decl_stmt|;
DECL|member|md4Context
name|md4_context
name|md4Context
decl_stmt|;
DECL|member|sha224Context
name|SHA224Context
name|sha224Context
decl_stmt|;
DECL|member|sha256Context
name|SHA256Context
name|sha256Context
decl_stmt|;
DECL|member|sha384Context
name|SHA384Context
name|sha384Context
decl_stmt|;
DECL|member|sha512Context
name|SHA512Context
name|sha512Context
decl_stmt|;
DECL|member|sha3Context
name|SHA3Context
name|sha3Context
decl_stmt|;
endif|#
directive|endif
block|}
union|;
DECL|member|result
name|QByteArray
name|result
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!   \class QCryptographicHash   \inmodule QtCore    \brief The QCryptographicHash class provides a way to generate cryptographic hashes.    \since 4.3    \ingroup tools   \reentrant    QCryptographicHash can be used to generate cryptographic hashes of binary or text data.    Currently MD4, MD5, SHA-1, SHA-224, SHA-256, SHA-384, and SHA-512 are supported. */
end_comment
begin_comment
comment|/*!   \enum QCryptographicHash::Algorithm    \value Md4 Generate an MD4 hash sum   \value Md5 Generate an MD5 hash sum   \value Sha1 Generate an SHA-1 hash sum   \value Sha224 Generate an SHA-224 hash sum (SHA-2). Introduced in Qt 5.0   \value Sha256 Generate an SHA-256 hash sum (SHA-2). Introduced in Qt 5.0   \value Sha384 Generate an SHA-384 hash sum (SHA-2). Introduced in Qt 5.0   \value Sha512 Generate an SHA-512 hash sum (SHA-2). Introduced in Qt 5.0   \value Sha3_224 Generate an SHA3-224 hash sum. Introduced in Qt 5.1   \value Sha3_256 Generate an SHA3-256 hash sum. Introduced in Qt 5.1   \value Sha3_384 Generate an SHA3-384 hash sum. Introduced in Qt 5.1   \value Sha3_512 Generate an SHA3-512 hash sum. Introduced in Qt 5.1 */
end_comment
begin_comment
comment|/*!   Constructs an object that can be used to create a cryptographic hash from data using \a method. */
end_comment
begin_constructor
DECL|function|QCryptographicHash
name|QCryptographicHash
operator|::
name|QCryptographicHash
parameter_list|(
name|Algorithm
name|method
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QCryptographicHashPrivate
argument_list|)
block|{
name|d
operator|->
name|method
operator|=
name|method
expr_stmt|;
name|reset
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Destroys the object. */
end_comment
begin_destructor
DECL|function|~QCryptographicHash
name|QCryptographicHash
operator|::
name|~
name|QCryptographicHash
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!   Resets the object. */
end_comment
begin_function
DECL|function|reset
name|void
name|QCryptographicHash
operator|::
name|reset
parameter_list|()
block|{
switch|switch
condition|(
name|d
operator|->
name|method
condition|)
block|{
case|case
name|Sha1
case|:
name|sha1InitState
argument_list|(
operator|&
name|d
operator|->
name|sha1Context
argument_list|)
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|QT_CRYPTOGRAPHICHASH_ONLY_SHA1
default|default:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"QCryptographicHash"
argument_list|,
literal|"Method not compiled in"
argument_list|)
expr_stmt|;
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
break|break;
else|#
directive|else
case|case
name|Md4
case|:
name|md4_init
argument_list|(
operator|&
name|d
operator|->
name|md4Context
argument_list|)
expr_stmt|;
break|break;
case|case
name|Md5
case|:
name|MD5Init
argument_list|(
operator|&
name|d
operator|->
name|md5Context
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha224
case|:
name|SHA224Reset
argument_list|(
operator|&
name|d
operator|->
name|sha224Context
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha256
case|:
name|SHA256Reset
argument_list|(
operator|&
name|d
operator|->
name|sha256Context
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha384
case|:
name|SHA384Reset
argument_list|(
operator|&
name|d
operator|->
name|sha384Context
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha512
case|:
name|SHA512Reset
argument_list|(
operator|&
name|d
operator|->
name|sha512Context
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha3_224
case|:
name|sha3Init
argument_list|(
operator|&
name|d
operator|->
name|sha3Context
argument_list|,
literal|224
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha3_256
case|:
name|sha3Init
argument_list|(
operator|&
name|d
operator|->
name|sha3Context
argument_list|,
literal|256
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha3_384
case|:
name|sha3Init
argument_list|(
operator|&
name|d
operator|->
name|sha3Context
argument_list|,
literal|384
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha3_512
case|:
name|sha3Init
argument_list|(
operator|&
name|d
operator|->
name|sha3Context
argument_list|,
literal|512
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
block|}
name|d
operator|->
name|result
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Adds the first \a length chars of \a data to the cryptographic     hash. */
end_comment
begin_function
DECL|function|addData
name|void
name|QCryptographicHash
operator|::
name|addData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|int
name|length
parameter_list|)
block|{
switch|switch
condition|(
name|d
operator|->
name|method
condition|)
block|{
case|case
name|Sha1
case|:
name|sha1Update
argument_list|(
operator|&
name|d
operator|->
name|sha1Context
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|data
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|QT_CRYPTOGRAPHICHASH_ONLY_SHA1
default|default:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"QCryptographicHash"
argument_list|,
literal|"Method not compiled in"
argument_list|)
expr_stmt|;
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
break|break;
else|#
directive|else
case|case
name|Md4
case|:
name|md4_update
argument_list|(
operator|&
name|d
operator|->
name|md4Context
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|data
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
case|case
name|Md5
case|:
name|MD5Update
argument_list|(
operator|&
name|d
operator|->
name|md5Context
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|data
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha224
case|:
name|SHA224Input
argument_list|(
operator|&
name|d
operator|->
name|sha224Context
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha256
case|:
name|SHA256Input
argument_list|(
operator|&
name|d
operator|->
name|sha256Context
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha384
case|:
name|SHA384Input
argument_list|(
operator|&
name|d
operator|->
name|sha384Context
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha512
case|:
name|SHA512Input
argument_list|(
operator|&
name|d
operator|->
name|sha512Context
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|length
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha3_224
case|:
name|sha3Update
argument_list|(
operator|&
name|d
operator|->
name|sha3Context
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|BitSequence
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|length
operator|*
literal|8
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha3_256
case|:
name|sha3Update
argument_list|(
operator|&
name|d
operator|->
name|sha3Context
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|BitSequence
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|length
operator|*
literal|8
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha3_384
case|:
name|sha3Update
argument_list|(
operator|&
name|d
operator|->
name|sha3Context
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|BitSequence
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|length
operator|*
literal|8
argument_list|)
expr_stmt|;
break|break;
case|case
name|Sha3_512
case|:
name|sha3Update
argument_list|(
operator|&
name|d
operator|->
name|sha3Context
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|BitSequence
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|length
operator|*
literal|8
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
block|}
name|d
operator|->
name|result
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \overload addData() */
end_comment
begin_function
DECL|function|addData
name|void
name|QCryptographicHash
operator|::
name|addData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|addData
argument_list|(
name|data
operator|.
name|constData
argument_list|()
argument_list|,
name|data
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reads the data from the open QIODevice \a device until it ends   and hashes it. Returns true if reading was successful.   \since 5.0  */
end_comment
begin_function
DECL|function|addData
name|bool
name|QCryptographicHash
operator|::
name|addData
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
if|if
condition|(
operator|!
name|device
operator|->
name|isReadable
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|device
operator|->
name|isOpen
argument_list|()
condition|)
return|return
literal|false
return|;
name|char
name|buffer
index|[
literal|1024
index|]
decl_stmt|;
name|int
name|length
decl_stmt|;
while|while
condition|(
operator|(
name|length
operator|=
name|device
operator|->
name|read
argument_list|(
name|buffer
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
argument_list|)
operator|)
operator|>
literal|0
condition|)
name|addData
argument_list|(
name|buffer
argument_list|,
name|length
argument_list|)
expr_stmt|;
return|return
name|device
operator|->
name|atEnd
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the final hash value.    \sa QByteArray::toHex() */
end_comment
begin_function
DECL|function|result
name|QByteArray
name|QCryptographicHash
operator|::
name|result
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|result
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|d
operator|->
name|result
return|;
switch|switch
condition|(
name|d
operator|->
name|method
condition|)
block|{
case|case
name|Sha1
case|:
block|{
name|Sha1State
name|copy
init|=
name|d
operator|->
name|sha1Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|sha1FinalizeState
argument_list|(
operator|&
name|copy
argument_list|)
expr_stmt|;
name|sha1ToHash
argument_list|(
operator|&
name|copy
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
ifdef|#
directive|ifdef
name|QT_CRYPTOGRAPHICHASH_ONLY_SHA1
default|default:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"QCryptographicHash"
argument_list|,
literal|"Method not compiled in"
argument_list|)
expr_stmt|;
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
break|break;
else|#
directive|else
case|case
name|Md4
case|:
block|{
name|md4_context
name|copy
init|=
name|d
operator|->
name|md4Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
name|MD4_RESULTLEN
argument_list|)
expr_stmt|;
name|md4_final
argument_list|(
operator|&
name|copy
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Md5
case|:
block|{
name|MD5Context
name|copy
init|=
name|d
operator|->
name|md5Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|MD5Final
argument_list|(
operator|&
name|copy
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Sha224
case|:
block|{
name|SHA224Context
name|copy
init|=
name|d
operator|->
name|sha224Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
name|SHA224HashSize
argument_list|)
expr_stmt|;
name|SHA224Result
argument_list|(
operator|&
name|copy
argument_list|,
cast|reinterpret_cast
argument_list|<
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Sha256
case|:
block|{
name|SHA256Context
name|copy
init|=
name|d
operator|->
name|sha256Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
name|SHA256HashSize
argument_list|)
expr_stmt|;
name|SHA256Result
argument_list|(
operator|&
name|copy
argument_list|,
cast|reinterpret_cast
argument_list|<
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Sha384
case|:
block|{
name|SHA384Context
name|copy
init|=
name|d
operator|->
name|sha384Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
name|SHA384HashSize
argument_list|)
expr_stmt|;
name|SHA384Result
argument_list|(
operator|&
name|copy
argument_list|,
cast|reinterpret_cast
argument_list|<
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Sha512
case|:
block|{
name|SHA512Context
name|copy
init|=
name|d
operator|->
name|sha512Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
name|SHA512HashSize
argument_list|)
expr_stmt|;
name|SHA512Result
argument_list|(
operator|&
name|copy
argument_list|,
cast|reinterpret_cast
argument_list|<
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Sha3_224
case|:
block|{
name|SHA3Context
name|copy
init|=
name|d
operator|->
name|sha3Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
literal|224
operator|/
literal|8
argument_list|)
expr_stmt|;
name|sha3Final
argument_list|(
operator|&
name|copy
argument_list|,
cast|reinterpret_cast
argument_list|<
name|BitSequence
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Sha3_256
case|:
block|{
name|SHA3Context
name|copy
init|=
name|d
operator|->
name|sha3Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
literal|256
operator|/
literal|8
argument_list|)
expr_stmt|;
name|sha3Final
argument_list|(
operator|&
name|copy
argument_list|,
cast|reinterpret_cast
argument_list|<
name|BitSequence
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Sha3_384
case|:
block|{
name|SHA3Context
name|copy
init|=
name|d
operator|->
name|sha3Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
literal|384
operator|/
literal|8
argument_list|)
expr_stmt|;
name|sha3Final
argument_list|(
operator|&
name|copy
argument_list|,
cast|reinterpret_cast
argument_list|<
name|BitSequence
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|Sha3_512
case|:
block|{
name|SHA3Context
name|copy
init|=
name|d
operator|->
name|sha3Context
decl_stmt|;
name|d
operator|->
name|result
operator|.
name|resize
argument_list|(
literal|512
operator|/
literal|8
argument_list|)
expr_stmt|;
name|sha3Final
argument_list|(
operator|&
name|copy
argument_list|,
cast|reinterpret_cast
argument_list|<
name|BitSequence
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|result
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
endif|#
directive|endif
block|}
return|return
name|d
operator|->
name|result
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the hash of \a data using \a method. */
end_comment
begin_function
DECL|function|hash
name|QByteArray
name|QCryptographicHash
operator|::
name|hash
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
name|Algorithm
name|method
parameter_list|)
block|{
name|QCryptographicHash
name|hash
argument_list|(
name|method
argument_list|)
decl_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|data
argument_list|)
expr_stmt|;
return|return
name|hash
operator|.
name|result
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
