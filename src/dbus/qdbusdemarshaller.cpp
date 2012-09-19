begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusargument_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection.h"
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
specifier|template
type|<
typename|typename
name|T
type|>
DECL|function|qIterGet
specifier|static
specifier|inline
name|T
name|qIterGet
parameter_list|(
name|DBusMessageIter
modifier|*
name|it
parameter_list|)
block|{
comment|// Use a union of expected and largest type q_dbus_message_iter_get_basic
comment|// will return to ensure reading the wrong basic type does not result in
comment|// stack overwrite
union|union
block|{
comment|// The value to be extracted
name|T
name|t
decl_stmt|;
comment|// Largest type that q_dbus_message_iter_get_basic will return
comment|// according to dbus_message_iter_get_basic API documentation
name|dbus_uint64_t
name|maxValue
decl_stmt|;
comment|// A pointer to ensure no stack overwrite in case there is a platform
comment|// where sizeof(void*)> sizeof(dbus_uint64_t)
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
name|value
union|;
comment|// Initialize the value in case a narrower type is extracted to it.
comment|// Note that the result of extracting a narrower type in place of a wider
comment|// one and vice-versa will be platform-dependent.
name|value
operator|.
name|t
operator|=
name|T
argument_list|()
expr_stmt|;
name|q_dbus_message_iter_get_basic
argument_list|(
name|it
argument_list|,
operator|&
name|value
argument_list|)
expr_stmt|;
name|q_dbus_message_iter_next
argument_list|(
name|it
argument_list|)
expr_stmt|;
return|return
name|value
operator|.
name|t
return|;
block|}
end_function
begin_destructor
DECL|function|~QDBusDemarshaller
name|QDBusDemarshaller
operator|::
name|~
name|QDBusDemarshaller
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|currentSignature
specifier|inline
name|QString
name|QDBusDemarshaller
operator|::
name|currentSignature
parameter_list|()
block|{
name|char
modifier|*
name|sig
init|=
name|q_dbus_message_iter_get_signature
argument_list|(
operator|&
name|iterator
argument_list|)
decl_stmt|;
name|QString
name|retval
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|sig
argument_list|)
decl_stmt|;
name|q_dbus_free
argument_list|(
name|sig
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function
begin_function
DECL|function|toByte
specifier|inline
name|uchar
name|QDBusDemarshaller
operator|::
name|toByte
parameter_list|()
block|{
return|return
name|qIterGet
argument_list|<
name|uchar
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toBool
specifier|inline
name|bool
name|QDBusDemarshaller
operator|::
name|toBool
parameter_list|()
block|{
return|return
name|bool
argument_list|(
name|qIterGet
argument_list|<
name|dbus_bool_t
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toUShort
specifier|inline
name|ushort
name|QDBusDemarshaller
operator|::
name|toUShort
parameter_list|()
block|{
return|return
name|qIterGet
argument_list|<
name|dbus_uint16_t
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toShort
specifier|inline
name|short
name|QDBusDemarshaller
operator|::
name|toShort
parameter_list|()
block|{
return|return
name|qIterGet
argument_list|<
name|dbus_int16_t
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toInt
specifier|inline
name|int
name|QDBusDemarshaller
operator|::
name|toInt
parameter_list|()
block|{
return|return
name|qIterGet
argument_list|<
name|dbus_int32_t
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toUInt
specifier|inline
name|uint
name|QDBusDemarshaller
operator|::
name|toUInt
parameter_list|()
block|{
return|return
name|qIterGet
argument_list|<
name|dbus_uint32_t
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toLongLong
specifier|inline
name|qlonglong
name|QDBusDemarshaller
operator|::
name|toLongLong
parameter_list|()
block|{
return|return
name|qIterGet
argument_list|<
name|qlonglong
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toULongLong
specifier|inline
name|qulonglong
name|QDBusDemarshaller
operator|::
name|toULongLong
parameter_list|()
block|{
return|return
name|qIterGet
argument_list|<
name|qulonglong
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toDouble
specifier|inline
name|double
name|QDBusDemarshaller
operator|::
name|toDouble
parameter_list|()
block|{
return|return
name|qIterGet
argument_list|<
name|double
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toStringUnchecked
specifier|inline
name|QString
name|QDBusDemarshaller
operator|::
name|toStringUnchecked
parameter_list|()
block|{
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|qIterGet
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toString
specifier|inline
name|QString
name|QDBusDemarshaller
operator|::
name|toString
parameter_list|()
block|{
if|if
condition|(
name|isCurrentTypeStringLike
argument_list|()
condition|)
return|return
name|toStringUnchecked
argument_list|()
return|;
else|else
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toObjectPathUnchecked
specifier|inline
name|QDBusObjectPath
name|QDBusDemarshaller
operator|::
name|toObjectPathUnchecked
parameter_list|()
block|{
return|return
name|QDBusObjectPath
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|qIterGet
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toObjectPath
specifier|inline
name|QDBusObjectPath
name|QDBusDemarshaller
operator|::
name|toObjectPath
parameter_list|()
block|{
if|if
condition|(
name|isCurrentTypeStringLike
argument_list|()
condition|)
return|return
name|toObjectPathUnchecked
argument_list|()
return|;
else|else
return|return
name|QDBusObjectPath
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toSignatureUnchecked
specifier|inline
name|QDBusSignature
name|QDBusDemarshaller
operator|::
name|toSignatureUnchecked
parameter_list|()
block|{
return|return
name|QDBusSignature
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|qIterGet
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toSignature
specifier|inline
name|QDBusSignature
name|QDBusDemarshaller
operator|::
name|toSignature
parameter_list|()
block|{
if|if
condition|(
name|isCurrentTypeStringLike
argument_list|()
condition|)
return|return
name|toSignatureUnchecked
argument_list|()
return|;
else|else
return|return
name|QDBusSignature
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toUnixFileDescriptor
specifier|inline
name|QDBusUnixFileDescriptor
name|QDBusDemarshaller
operator|::
name|toUnixFileDescriptor
parameter_list|()
block|{
name|QDBusUnixFileDescriptor
name|fd
decl_stmt|;
name|fd
operator|.
name|giveFileDescriptor
argument_list|(
name|qIterGet
argument_list|<
name|dbus_int32_t
argument_list|>
argument_list|(
operator|&
name|iterator
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|fd
return|;
block|}
end_function
begin_function
DECL|function|toVariant
specifier|inline
name|QDBusVariant
name|QDBusDemarshaller
operator|::
name|toVariant
parameter_list|()
block|{
name|QDBusDemarshaller
name|sub
argument_list|(
name|capabilities
argument_list|)
decl_stmt|;
name|sub
operator|.
name|message
operator|=
name|q_dbus_message_ref
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|q_dbus_message_iter_recurse
argument_list|(
operator|&
name|iterator
argument_list|,
operator|&
name|sub
operator|.
name|iterator
argument_list|)
expr_stmt|;
name|q_dbus_message_iter_next
argument_list|(
operator|&
name|iterator
argument_list|)
expr_stmt|;
return|return
name|QDBusVariant
argument_list|(
name|sub
operator|.
name|toVariantInternal
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|currentType
name|QDBusArgument
operator|::
name|ElementType
name|QDBusDemarshaller
operator|::
name|currentType
parameter_list|()
block|{
switch|switch
condition|(
name|q_dbus_message_iter_get_arg_type
argument_list|(
operator|&
name|iterator
argument_list|)
condition|)
block|{
case|case
name|DBUS_TYPE_BYTE
case|:
case|case
name|DBUS_TYPE_INT16
case|:
case|case
name|DBUS_TYPE_UINT16
case|:
case|case
name|DBUS_TYPE_INT32
case|:
case|case
name|DBUS_TYPE_UINT32
case|:
case|case
name|DBUS_TYPE_INT64
case|:
case|case
name|DBUS_TYPE_UINT64
case|:
case|case
name|DBUS_TYPE_BOOLEAN
case|:
case|case
name|DBUS_TYPE_DOUBLE
case|:
case|case
name|DBUS_TYPE_STRING
case|:
case|case
name|DBUS_TYPE_OBJECT_PATH
case|:
case|case
name|DBUS_TYPE_SIGNATURE
case|:
return|return
name|QDBusArgument
operator|::
name|BasicType
return|;
case|case
name|DBUS_TYPE_VARIANT
case|:
return|return
name|QDBusArgument
operator|::
name|VariantType
return|;
case|case
name|DBUS_TYPE_ARRAY
case|:
switch|switch
condition|(
name|q_dbus_message_iter_get_element_type
argument_list|(
operator|&
name|iterator
argument_list|)
condition|)
block|{
case|case
name|DBUS_TYPE_BYTE
case|:
case|case
name|DBUS_TYPE_STRING
case|:
comment|// QByteArray and QStringList
return|return
name|QDBusArgument
operator|::
name|BasicType
return|;
case|case
name|DBUS_TYPE_DICT_ENTRY
case|:
return|return
name|QDBusArgument
operator|::
name|MapType
return|;
default|default:
return|return
name|QDBusArgument
operator|::
name|ArrayType
return|;
block|}
case|case
name|DBUS_TYPE_STRUCT
case|:
return|return
name|QDBusArgument
operator|::
name|StructureType
return|;
case|case
name|DBUS_TYPE_DICT_ENTRY
case|:
return|return
name|QDBusArgument
operator|::
name|MapEntryType
return|;
case|case
name|DBUS_TYPE_UNIX_FD
case|:
return|return
name|capabilities
operator|&
name|QDBusConnection
operator|::
name|UnixFileDescriptorPassing
condition|?
name|QDBusArgument
operator|::
name|BasicType
else|:
name|QDBusArgument
operator|::
name|UnknownType
return|;
case|case
name|DBUS_TYPE_INVALID
case|:
return|return
name|QDBusArgument
operator|::
name|UnknownType
return|;
comment|//    default:
comment|//        qWarning("QDBusDemarshaller: Found unknown D-Bus type %d '%c'",
comment|//                 q_dbus_message_iter_get_arg_type(&iterator),
comment|//                 q_dbus_message_iter_get_arg_type(&iterator));
block|}
return|return
name|QDBusArgument
operator|::
name|UnknownType
return|;
block|}
end_function
begin_function
DECL|function|toVariantInternal
name|QVariant
name|QDBusDemarshaller
operator|::
name|toVariantInternal
parameter_list|()
block|{
switch|switch
condition|(
name|q_dbus_message_iter_get_arg_type
argument_list|(
operator|&
name|iterator
argument_list|)
condition|)
block|{
case|case
name|DBUS_TYPE_BYTE
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|toByte
argument_list|()
argument_list|)
return|;
case|case
name|DBUS_TYPE_INT16
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|toShort
argument_list|()
argument_list|)
return|;
case|case
name|DBUS_TYPE_UINT16
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|toUShort
argument_list|()
argument_list|)
return|;
case|case
name|DBUS_TYPE_INT32
case|:
return|return
name|toInt
argument_list|()
return|;
case|case
name|DBUS_TYPE_UINT32
case|:
return|return
name|toUInt
argument_list|()
return|;
case|case
name|DBUS_TYPE_DOUBLE
case|:
return|return
name|toDouble
argument_list|()
return|;
case|case
name|DBUS_TYPE_BOOLEAN
case|:
return|return
name|toBool
argument_list|()
return|;
case|case
name|DBUS_TYPE_INT64
case|:
return|return
name|toLongLong
argument_list|()
return|;
case|case
name|DBUS_TYPE_UINT64
case|:
return|return
name|toULongLong
argument_list|()
return|;
case|case
name|DBUS_TYPE_STRING
case|:
return|return
name|toStringUnchecked
argument_list|()
return|;
case|case
name|DBUS_TYPE_OBJECT_PATH
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|toObjectPathUnchecked
argument_list|()
argument_list|)
return|;
case|case
name|DBUS_TYPE_SIGNATURE
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|toSignatureUnchecked
argument_list|()
argument_list|)
return|;
case|case
name|DBUS_TYPE_VARIANT
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|toVariant
argument_list|()
argument_list|)
return|;
case|case
name|DBUS_TYPE_ARRAY
case|:
switch|switch
condition|(
name|q_dbus_message_iter_get_element_type
argument_list|(
operator|&
name|iterator
argument_list|)
condition|)
block|{
case|case
name|DBUS_TYPE_BYTE
case|:
comment|// QByteArray
return|return
name|toByteArrayUnchecked
argument_list|()
return|;
case|case
name|DBUS_TYPE_STRING
case|:
return|return
name|toStringListUnchecked
argument_list|()
return|;
case|case
name|DBUS_TYPE_DICT_ENTRY
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|duplicate
argument_list|()
argument_list|)
return|;
default|default:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|duplicate
argument_list|()
argument_list|)
return|;
block|}
case|case
name|DBUS_TYPE_STRUCT
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|duplicate
argument_list|()
argument_list|)
return|;
case|case
name|DBUS_TYPE_UNIX_FD
case|:
if|if
condition|(
name|capabilities
operator|&
name|QDBusConnection
operator|::
name|UnixFileDescriptorPassing
condition|)
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|toUnixFileDescriptor
argument_list|()
argument_list|)
return|;
comment|// fall through
default|default:
comment|//        qWarning("QDBusDemarshaller: Found unknown D-Bus type %d '%c'",
comment|//                 q_dbus_message_iter_get_arg_type(&iterator),
comment|//                 q_dbus_message_iter_get_arg_type(&iterator));
name|char
modifier|*
name|ptr
init|=
literal|0
decl_stmt|;
name|ptr
operator|+=
name|q_dbus_message_iter_get_arg_type
argument_list|(
operator|&
name|iterator
argument_list|)
expr_stmt|;
name|q_dbus_message_iter_next
argument_list|(
operator|&
name|iterator
argument_list|)
expr_stmt|;
comment|// I hope you never dereference this pointer!
return|return
name|QVariant
operator|::
name|fromValue
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|ptr
argument_list|)
return|;
break|break;
block|}
empty_stmt|;
block|}
end_function
begin_function
DECL|function|isCurrentTypeStringLike
name|bool
name|QDBusDemarshaller
operator|::
name|isCurrentTypeStringLike
parameter_list|()
block|{
specifier|const
name|int
name|type
init|=
name|q_dbus_message_iter_get_arg_type
argument_list|(
operator|&
name|iterator
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|DBUS_TYPE_STRING
case|:
comment|//FALLTHROUGH
case|case
name|DBUS_TYPE_OBJECT_PATH
case|:
comment|//FALLTHROUGH
case|case
name|DBUS_TYPE_SIGNATURE
case|:
return|return
literal|true
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
end_function
begin_function
DECL|function|toStringListUnchecked
name|QStringList
name|QDBusDemarshaller
operator|::
name|toStringListUnchecked
parameter_list|()
block|{
name|QStringList
name|list
decl_stmt|;
name|QDBusDemarshaller
name|sub
argument_list|(
name|capabilities
argument_list|)
decl_stmt|;
name|q_dbus_message_iter_recurse
argument_list|(
operator|&
name|iterator
argument_list|,
operator|&
name|sub
operator|.
name|iterator
argument_list|)
expr_stmt|;
name|q_dbus_message_iter_next
argument_list|(
operator|&
name|iterator
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|sub
operator|.
name|atEnd
argument_list|()
condition|)
name|list
operator|.
name|append
argument_list|(
name|sub
operator|.
name|toStringUnchecked
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|toStringList
name|QStringList
name|QDBusDemarshaller
operator|::
name|toStringList
parameter_list|()
block|{
if|if
condition|(
name|q_dbus_message_iter_get_arg_type
argument_list|(
operator|&
name|iterator
argument_list|)
operator|==
name|DBUS_TYPE_ARRAY
operator|&&
name|q_dbus_message_iter_get_element_type
argument_list|(
operator|&
name|iterator
argument_list|)
operator|==
name|DBUS_TYPE_STRING
condition|)
return|return
name|toStringListUnchecked
argument_list|()
return|;
else|else
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toByteArrayUnchecked
name|QByteArray
name|QDBusDemarshaller
operator|::
name|toByteArrayUnchecked
parameter_list|()
block|{
name|DBusMessageIter
name|sub
decl_stmt|;
name|q_dbus_message_iter_recurse
argument_list|(
operator|&
name|iterator
argument_list|,
operator|&
name|sub
argument_list|)
expr_stmt|;
name|q_dbus_message_iter_next
argument_list|(
operator|&
name|iterator
argument_list|)
expr_stmt|;
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
name|q_dbus_message_iter_get_fixed_array
argument_list|(
operator|&
name|sub
argument_list|,
operator|&
name|data
argument_list|,
operator|&
name|len
argument_list|)
expr_stmt|;
return|return
name|QByteArray
argument_list|(
name|data
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toByteArray
name|QByteArray
name|QDBusDemarshaller
operator|::
name|toByteArray
parameter_list|()
block|{
if|if
condition|(
name|q_dbus_message_iter_get_arg_type
argument_list|(
operator|&
name|iterator
argument_list|)
operator|==
name|DBUS_TYPE_ARRAY
operator|&&
name|q_dbus_message_iter_get_element_type
argument_list|(
operator|&
name|iterator
argument_list|)
operator|==
name|DBUS_TYPE_BYTE
condition|)
block|{
return|return
name|toByteArrayUnchecked
argument_list|()
return|;
block|}
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|atEnd
name|bool
name|QDBusDemarshaller
operator|::
name|atEnd
parameter_list|()
block|{
comment|// dbus_message_iter_has_next is broken if the list has one single element
return|return
name|q_dbus_message_iter_get_arg_type
argument_list|(
operator|&
name|iterator
argument_list|)
operator|==
name|DBUS_TYPE_INVALID
return|;
block|}
end_function
begin_function
DECL|function|beginStructure
specifier|inline
name|QDBusDemarshaller
modifier|*
name|QDBusDemarshaller
operator|::
name|beginStructure
parameter_list|()
block|{
return|return
name|beginCommon
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|beginArray
specifier|inline
name|QDBusDemarshaller
modifier|*
name|QDBusDemarshaller
operator|::
name|beginArray
parameter_list|()
block|{
return|return
name|beginCommon
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|beginMap
specifier|inline
name|QDBusDemarshaller
modifier|*
name|QDBusDemarshaller
operator|::
name|beginMap
parameter_list|()
block|{
return|return
name|beginCommon
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|beginMapEntry
specifier|inline
name|QDBusDemarshaller
modifier|*
name|QDBusDemarshaller
operator|::
name|beginMapEntry
parameter_list|()
block|{
return|return
name|beginCommon
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|beginCommon
name|QDBusDemarshaller
modifier|*
name|QDBusDemarshaller
operator|::
name|beginCommon
parameter_list|()
block|{
name|QDBusDemarshaller
modifier|*
name|d
init|=
operator|new
name|QDBusDemarshaller
argument_list|(
name|capabilities
argument_list|)
decl_stmt|;
name|d
operator|->
name|parent
operator|=
name|this
expr_stmt|;
name|d
operator|->
name|message
operator|=
name|q_dbus_message_ref
argument_list|(
name|message
argument_list|)
expr_stmt|;
comment|// recurse
name|q_dbus_message_iter_recurse
argument_list|(
operator|&
name|iterator
argument_list|,
operator|&
name|d
operator|->
name|iterator
argument_list|)
expr_stmt|;
name|q_dbus_message_iter_next
argument_list|(
operator|&
name|iterator
argument_list|)
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_function
DECL|function|endStructure
specifier|inline
name|QDBusDemarshaller
modifier|*
name|QDBusDemarshaller
operator|::
name|endStructure
parameter_list|()
block|{
return|return
name|endCommon
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|endArray
specifier|inline
name|QDBusDemarshaller
modifier|*
name|QDBusDemarshaller
operator|::
name|endArray
parameter_list|()
block|{
return|return
name|endCommon
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|endMap
specifier|inline
name|QDBusDemarshaller
modifier|*
name|QDBusDemarshaller
operator|::
name|endMap
parameter_list|()
block|{
return|return
name|endCommon
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|endMapEntry
specifier|inline
name|QDBusDemarshaller
modifier|*
name|QDBusDemarshaller
operator|::
name|endMapEntry
parameter_list|()
block|{
return|return
name|endCommon
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|endCommon
name|QDBusDemarshaller
modifier|*
name|QDBusDemarshaller
operator|::
name|endCommon
parameter_list|()
block|{
name|QDBusDemarshaller
modifier|*
name|retval
init|=
name|parent
decl_stmt|;
operator|delete
name|this
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function
begin_function
DECL|function|duplicate
name|QDBusArgument
name|QDBusDemarshaller
operator|::
name|duplicate
parameter_list|()
block|{
name|QDBusDemarshaller
modifier|*
name|d
init|=
operator|new
name|QDBusDemarshaller
argument_list|(
name|capabilities
argument_list|)
decl_stmt|;
name|d
operator|->
name|iterator
operator|=
name|iterator
expr_stmt|;
name|d
operator|->
name|message
operator|=
name|q_dbus_message_ref
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|q_dbus_message_iter_next
argument_list|(
operator|&
name|iterator
argument_list|)
expr_stmt|;
return|return
name|QDBusArgumentPrivate
operator|::
name|create
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
