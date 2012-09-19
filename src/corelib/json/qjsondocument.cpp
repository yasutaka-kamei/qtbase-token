begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qjsondocument.h>
end_include
begin_include
include|#
directive|include
file|<qjsonobject.h>
end_include
begin_include
include|#
directive|include
file|<qjsonvalue.h>
end_include
begin_include
include|#
directive|include
file|<qjsonarray.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qvariant.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qjsonwriter_p.h"
end_include
begin_include
include|#
directive|include
file|"qjsonparser_p.h"
end_include
begin_include
include|#
directive|include
file|"qjson_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*! \class QJsonDocument     \inmodule QtCore     \ingroup json     \reentrant     \since 5.0      \brief The QJsonDocument class provides a way to read and write JSON documents.      QJsonDocument is a class that wraps a complete JSON document and can read and     write this document both from a UTF-8 encoded text based representation as well     as Qt's own binary format.      A JSON document can be converted from its text-based representation to a QJsonDocument     using QJsonDocument::fromJson(). toJson() converts it back to text. The parser is very     fast and efficient and converts the JSON to the binary representation used by Qt.      Validity of the parsed document can be queried with !isNull()      A document can be queried as to whether it contains an array or an object using isArray()     and isObject(). The array or object contained in the document can be retrieved using     array() or object() and then read or manipulated.      A document can also be created from a stored binary representation using fromBinaryData() or     fromRawData(). */
end_comment
begin_comment
comment|/*!  * Constructs an empty and invalid document.  */
end_comment
begin_constructor
DECL|function|QJsonDocument
name|QJsonDocument
operator|::
name|QJsonDocument
parameter_list|()
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!  * Creates a QJsonDocument from \a object.  */
end_comment
begin_constructor
DECL|function|QJsonDocument
name|QJsonDocument
operator|::
name|QJsonDocument
parameter_list|(
specifier|const
name|QJsonObject
modifier|&
name|object
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|setObject
argument_list|(
name|object
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!  * Constructs a QJsonDocument from \a array.  */
end_comment
begin_constructor
DECL|function|QJsonDocument
name|QJsonDocument
operator|::
name|QJsonDocument
parameter_list|(
specifier|const
name|QJsonArray
modifier|&
name|array
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|setArray
argument_list|(
name|array
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal  */
end_comment
begin_constructor
DECL|function|QJsonDocument
name|QJsonDocument
operator|::
name|QJsonDocument
parameter_list|(
name|QJsonPrivate
operator|::
name|Data
modifier|*
name|data
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|data
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!  Deletes the document.   Binary data set with fromRawData is not freed.  */
end_comment
begin_destructor
DECL|function|~QJsonDocument
name|QJsonDocument
operator|::
name|~
name|QJsonDocument
parameter_list|()
block|{
if|if
condition|(
name|d
operator|&&
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!  * Creates a copy of the \a other document.  */
end_comment
begin_constructor
DECL|function|QJsonDocument
name|QJsonDocument
operator|::
name|QJsonDocument
parameter_list|(
specifier|const
name|QJsonDocument
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!  * Assigns the \a other document to this QJsonDocument.  * Returns a reference to this object.  */
end_comment
begin_function
DECL|function|operator =
name|QJsonDocument
modifier|&
name|QJsonDocument
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QJsonDocument
modifier|&
name|other
parameter_list|)
block|{
if|if
condition|(
name|d
operator|!=
name|other
operator|.
name|d
condition|)
block|{
if|if
condition|(
name|d
operator|&&
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*! \enum QJsonDocument::DataValidation    This value is used to tell QJsonDocument whether to validate the binary data   when converting to a QJsonDocument using fromBinaryData() or fromRawData().    \value Validate Validate the data before using it. This is the default.   \value BypassValidation Bypasses data validation. Only use if you received the   data from a trusted place and know it's valid, as using of invalid data can crash   the application.   */
end_comment
begin_comment
comment|/*!  Creates a QJsonDocument that uses the first \a size bytes from  \a data. It assumes \a data contains a binary encoded JSON document.  The created document does not take ownership of \a data and the caller  has to guarantee that \a data will not be deleted or modified as long as  any QJsonDocument, QJsonObject or QJsonArray still references the data.   \a data has to be aligned to a 4 byte boundary.   \a validation decides whether the data is checked for validity before being used.  By default the data is validated. If the \a data is not valid, the method returns  a null document.   Returns a QJsonDocument representing the data.   \sa rawData(), fromBinaryData(), isNull(), DataValidation  */
end_comment
begin_function
DECL|function|fromRawData
name|QJsonDocument
name|QJsonDocument
operator|::
name|fromRawData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|int
name|size
parameter_list|,
name|DataValidation
name|validation
parameter_list|)
block|{
if|if
condition|(
name|quintptr
argument_list|(
name|data
argument_list|)
operator|&
literal|3
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QJsonDocument::fromRawData: data has to have 4 byte alignment"
expr_stmt|;
return|return
name|QJsonDocument
argument_list|()
return|;
block|}
name|QJsonPrivate
operator|::
name|Data
modifier|*
name|d
init|=
operator|new
name|QJsonPrivate
operator|::
name|Data
argument_list|(
operator|(
name|char
operator|*
operator|)
name|data
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|d
operator|->
name|ownsData
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|validation
operator|!=
name|BypassValidation
operator|&&
operator|!
name|d
operator|->
name|valid
argument_list|()
condition|)
block|{
operator|delete
name|d
expr_stmt|;
return|return
name|QJsonDocument
argument_list|()
return|;
block|}
return|return
name|QJsonDocument
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the raw binary representation of the data   \a size will contain the size of the returned data.    This method is useful to e.g. stream the JSON document   in it's binary form to a file.  */
end_comment
begin_function
DECL|function|rawData
specifier|const
name|char
modifier|*
name|QJsonDocument
operator|::
name|rawData
parameter_list|(
name|int
modifier|*
name|size
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
block|{
operator|*
name|size
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
operator|*
name|size
operator|=
name|d
operator|->
name|alloc
expr_stmt|;
return|return
name|d
operator|->
name|rawData
return|;
block|}
end_function
begin_comment
comment|/*!  Creates a QJsonDocument from \a data.   \a validation decides whether the data is checked for validity before being used.  By default the data is validated. If the \a data is not valid, the method returns  a null document.   \sa toBinaryData(), fromRawData(), isNull(), DataValidation  */
end_comment
begin_function
DECL|function|fromBinaryData
name|QJsonDocument
name|QJsonDocument
operator|::
name|fromBinaryData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
name|DataValidation
name|validation
parameter_list|)
block|{
if|if
condition|(
name|data
operator|.
name|size
argument_list|()
operator|<
call|(
name|int
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|QJsonPrivate
operator|::
name|Header
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|QJsonPrivate
operator|::
name|Base
argument_list|)
argument_list|)
condition|)
return|return
name|QJsonDocument
argument_list|()
return|;
name|QJsonPrivate
operator|::
name|Header
name|h
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|h
argument_list|,
name|data
operator|.
name|constData
argument_list|()
argument_list|,
sizeof|sizeof
argument_list|(
name|QJsonPrivate
operator|::
name|Header
argument_list|)
argument_list|)
expr_stmt|;
name|QJsonPrivate
operator|::
name|Base
name|root
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|root
argument_list|,
name|data
operator|.
name|constData
argument_list|()
operator|+
sizeof|sizeof
argument_list|(
name|QJsonPrivate
operator|::
name|Header
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|QJsonPrivate
operator|::
name|Base
argument_list|)
argument_list|)
expr_stmt|;
comment|// do basic checks here, so we don't try to allocate more memory than we can.
if|if
condition|(
name|h
operator|.
name|tag
operator|!=
name|QJsonDocument
operator|::
name|BinaryFormatTag
operator|||
name|h
operator|.
name|version
operator|!=
literal|1u
operator|||
sizeof|sizeof
argument_list|(
name|QJsonPrivate
operator|::
name|Header
argument_list|)
operator|+
name|root
operator|.
name|size
operator|>
operator|(
name|uint
operator|)
name|data
operator|.
name|size
argument_list|()
condition|)
return|return
name|QJsonDocument
argument_list|()
return|;
specifier|const
name|uint
name|size
init|=
sizeof|sizeof
argument_list|(
name|QJsonPrivate
operator|::
name|Header
argument_list|)
operator|+
name|root
operator|.
name|size
decl_stmt|;
name|char
modifier|*
name|raw
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|raw
condition|)
return|return
name|QJsonDocument
argument_list|()
return|;
name|memcpy
argument_list|(
name|raw
argument_list|,
name|data
operator|.
name|constData
argument_list|()
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QJsonPrivate
operator|::
name|Data
modifier|*
name|d
init|=
operator|new
name|QJsonPrivate
operator|::
name|Data
argument_list|(
name|raw
argument_list|,
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|validation
operator|!=
name|BypassValidation
operator|&&
operator|!
name|d
operator|->
name|valid
argument_list|()
condition|)
block|{
operator|delete
name|d
expr_stmt|;
return|return
name|QJsonDocument
argument_list|()
return|;
block|}
return|return
name|QJsonDocument
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!  Creates a QJsonDocument from the QVariant \a variant.   If the \a variant contains any other type than a QVariant::Map,  QVariant::List or QVariant::StringList, the returned document  document is invalid.   \sa toVariant()  */
end_comment
begin_function
DECL|function|fromVariant
name|QJsonDocument
name|QJsonDocument
operator|::
name|fromVariant
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|variant
parameter_list|)
block|{
name|QJsonDocument
name|doc
decl_stmt|;
if|if
condition|(
name|variant
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Map
condition|)
block|{
name|doc
operator|.
name|setObject
argument_list|(
name|QJsonObject
operator|::
name|fromVariantMap
argument_list|(
name|variant
operator|.
name|toMap
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|variant
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|List
condition|)
block|{
name|doc
operator|.
name|setArray
argument_list|(
name|QJsonArray
operator|::
name|fromVariantList
argument_list|(
name|variant
operator|.
name|toList
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|variant
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|StringList
condition|)
block|{
name|doc
operator|.
name|setArray
argument_list|(
name|QJsonArray
operator|::
name|fromStringList
argument_list|(
name|variant
operator|.
name|toStringList
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|doc
return|;
block|}
end_function
begin_comment
comment|/*!  Returns a QVariant representing the Json document.   The returned variant will be a QVariantList if the document is  a QJsonArray and a QVariantMap if the document is a QJsonObject.   \sa fromVariant(), QJsonValue::toVariant()  */
end_comment
begin_function
DECL|function|toVariant
name|QVariant
name|QJsonDocument
operator|::
name|toVariant
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
operator|->
name|isArray
argument_list|()
condition|)
return|return
name|QJsonArray
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Array
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
argument_list|)
operator|.
name|toVariantList
argument_list|()
return|;
else|else
return|return
name|QJsonObject
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
argument_list|)
operator|.
name|toVariantMap
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!  Converts the QJsonDocument to a UTF-8 encoded JSON document.   \sa fromJson()  */
end_comment
begin_function
DECL|function|toJson
name|QByteArray
name|QJsonDocument
operator|::
name|toJson
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QByteArray
argument_list|()
return|;
name|QByteArray
name|json
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
operator|->
name|isArray
argument_list|()
condition|)
name|QJsonPrivate
operator|::
name|Writer
operator|::
name|arrayToJson
argument_list|(
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Array
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
argument_list|,
name|json
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|QJsonPrivate
operator|::
name|Writer
operator|::
name|objectToJson
argument_list|(
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
argument_list|,
name|json
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|json
return|;
block|}
end_function
begin_comment
comment|/*!  Parses a UTF-8 encoded JSON document and creates a QJsonDocument  from it.   \a json contains the json document to be parsed.   The optional \a error variable can be used to pass in a QJsonParseError data  structure that will contain information about possible errors encountered during  parsing.   \sa toJson(), QJsonParseError  */
end_comment
begin_function
DECL|function|fromJson
name|QJsonDocument
name|QJsonDocument
operator|::
name|fromJson
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|json
parameter_list|,
name|QJsonParseError
modifier|*
name|error
parameter_list|)
block|{
name|QJsonPrivate
operator|::
name|Parser
name|parser
argument_list|(
name|json
operator|.
name|constData
argument_list|()
argument_list|,
name|json
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|parser
operator|.
name|parse
argument_list|(
name|error
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the document doesn't contain any data.  */
end_comment
begin_function
DECL|function|isEmpty
name|bool
name|QJsonDocument
operator|::
name|isEmpty
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!  Returns a binary representation of the document.   The binary representation is also the native format used internally in Qt,  and is very efficient and fast to convert to and from.   The binary format can be stored on disk and interchanged with other applications  or computers. fromBinaryData() can be used to convert it back into a  JSON document.   \sa fromBinaryData()  */
end_comment
begin_function
DECL|function|toBinaryData
name|QByteArray
name|QJsonDocument
operator|::
name|toBinaryData
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
operator|||
operator|!
name|d
operator|->
name|rawData
condition|)
return|return
name|QByteArray
argument_list|()
return|;
return|return
name|QByteArray
argument_list|(
name|d
operator|->
name|rawData
argument_list|,
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
operator|->
name|size
operator|+
sizeof|sizeof
argument_list|(
name|QJsonPrivate
operator|::
name|Header
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the document contains an array.      \sa array(), isObject()  */
end_comment
begin_function
DECL|function|isArray
name|bool
name|QJsonDocument
operator|::
name|isArray
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
name|QJsonPrivate
operator|::
name|Header
modifier|*
name|h
init|=
operator|(
name|QJsonPrivate
operator|::
name|Header
operator|*
operator|)
name|d
operator|->
name|rawData
decl_stmt|;
return|return
name|h
operator|->
name|root
argument_list|()
operator|->
name|isArray
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the document contains an object.      \sa object(), isArray()  */
end_comment
begin_function
DECL|function|isObject
name|bool
name|QJsonDocument
operator|::
name|isObject
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
name|QJsonPrivate
operator|::
name|Header
modifier|*
name|h
init|=
operator|(
name|QJsonPrivate
operator|::
name|Header
operator|*
operator|)
name|d
operator|->
name|rawData
decl_stmt|;
return|return
name|h
operator|->
name|root
argument_list|()
operator|->
name|isObject
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the QJsonObject contained in the document.      Returns an empty object if the document contains an     array.      \sa isObject(), array(), setObject()  */
end_comment
begin_function
DECL|function|object
name|QJsonObject
name|QJsonDocument
operator|::
name|object
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
condition|)
block|{
name|QJsonPrivate
operator|::
name|Base
modifier|*
name|b
init|=
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
decl_stmt|;
if|if
condition|(
name|b
operator|->
name|isObject
argument_list|()
condition|)
return|return
name|QJsonObject
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|b
argument_list|)
argument_list|)
return|;
block|}
return|return
name|QJsonObject
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the QJsonArray contained in the document.      Returns an empty array if the document contains an     object.      \sa isArray(), object(), setArray()  */
end_comment
begin_function
DECL|function|array
name|QJsonArray
name|QJsonDocument
operator|::
name|array
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
condition|)
block|{
name|QJsonPrivate
operator|::
name|Base
modifier|*
name|b
init|=
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
decl_stmt|;
if|if
condition|(
name|b
operator|->
name|isArray
argument_list|()
condition|)
return|return
name|QJsonArray
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Array
operator|*
argument_list|>
argument_list|(
name|b
argument_list|)
argument_list|)
return|;
block|}
return|return
name|QJsonArray
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets \a object as the main object of this document.      \sa setArray(), object()  */
end_comment
begin_function
DECL|function|setObject
name|void
name|QJsonDocument
operator|::
name|setObject
parameter_list|(
specifier|const
name|QJsonObject
modifier|&
name|object
parameter_list|)
block|{
if|if
condition|(
name|d
operator|&&
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|object
operator|.
name|d
expr_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QJsonPrivate
operator|::
name|Data
argument_list|(
literal|0
argument_list|,
name|QJsonValue
operator|::
name|Object
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|compactionCounter
operator|||
name|object
operator|.
name|o
operator|!=
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
condition|)
block|{
name|QJsonObject
name|o
argument_list|(
name|object
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|compactionCounter
condition|)
name|o
operator|.
name|compact
argument_list|()
expr_stmt|;
else|else
name|o
operator|.
name|detach
argument_list|()
expr_stmt|;
name|d
operator|=
name|o
operator|.
name|d
expr_stmt|;
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
return|return;
block|}
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_function
begin_comment
comment|/*!     Sets \a array as the main object of this document.      \sa setObject(), array()  */
end_comment
begin_function
DECL|function|setArray
name|void
name|QJsonDocument
operator|::
name|setArray
parameter_list|(
specifier|const
name|QJsonArray
modifier|&
name|array
parameter_list|)
block|{
if|if
condition|(
name|d
operator|&&
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|array
operator|.
name|d
expr_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QJsonPrivate
operator|::
name|Data
argument_list|(
literal|0
argument_list|,
name|QJsonValue
operator|::
name|Array
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|compactionCounter
operator|||
name|array
operator|.
name|a
operator|!=
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
condition|)
block|{
name|QJsonArray
name|a
argument_list|(
name|array
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|compactionCounter
condition|)
name|a
operator|.
name|compact
argument_list|()
expr_stmt|;
else|else
name|a
operator|.
name|detach
argument_list|()
expr_stmt|;
name|d
operator|=
name|a
operator|.
name|d
expr_stmt|;
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
return|return;
block|}
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the \a other document is equal to this document.  */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QJsonDocument
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QJsonDocument
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|==
name|other
operator|.
name|d
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|!
name|d
operator|||
operator|!
name|other
operator|.
name|d
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
operator|->
name|isArray
argument_list|()
operator|!=
name|other
operator|.
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
operator|->
name|isArray
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
operator|->
name|isObject
argument_list|()
condition|)
return|return
name|QJsonObject
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
argument_list|)
operator|==
name|QJsonObject
argument_list|(
name|other
operator|.
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|other
operator|.
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
argument_list|)
return|;
else|else
return|return
name|QJsonArray
argument_list|(
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Array
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
argument_list|)
operator|==
name|QJsonArray
argument_list|(
name|other
operator|.
name|d
argument_list|,
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Array
operator|*
argument_list|>
argument_list|(
name|other
operator|.
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!  \fn bool QJsonDocument::operator!=(const QJsonDocument&other) const      returns \c true if \a other is not equal to this document  */
end_comment
begin_comment
comment|/*!     returns true if this document is null.      Null documents are documents created through the default constructor.      Documents created from UTF-8 encoded text or the binary format are     validated during parsing. If validation fails, the returned document     will also be null.  */
end_comment
begin_function
DECL|function|isNull
name|bool
name|QJsonDocument
operator|::
name|isNull
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|d
operator|==
literal|0
operator|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QJsonDocument
modifier|&
name|o
parameter_list|)
block|{
if|if
condition|(
operator|!
name|o
operator|.
name|d
condition|)
block|{
name|dbg
operator|<<
literal|"QJsonDocument()"
expr_stmt|;
return|return
name|dbg
return|;
block|}
name|QByteArray
name|json
decl_stmt|;
if|if
condition|(
name|o
operator|.
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
operator|->
name|isArray
argument_list|()
condition|)
name|QJsonPrivate
operator|::
name|Writer
operator|::
name|arrayToJson
argument_list|(
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Array
operator|*
argument_list|>
argument_list|(
name|o
operator|.
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
argument_list|,
name|json
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|)
expr_stmt|;
else|else
name|QJsonPrivate
operator|::
name|Writer
operator|::
name|objectToJson
argument_list|(
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Object
operator|*
argument_list|>
argument_list|(
name|o
operator|.
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
argument_list|,
name|json
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QJsonDocument("
operator|<<
name|json
operator|.
name|constData
argument_list|()
comment|// print as utf-8 string without extra quotation marks
operator|<<
literal|")"
expr_stmt|;
return|return
name|dbg
operator|.
name|space
argument_list|()
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
