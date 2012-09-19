begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"variantdelegate.h"
end_include
begin_constructor
DECL|function|VariantDelegate
name|VariantDelegate
operator|::
name|VariantDelegate
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QItemDelegate
argument_list|(
name|parent
argument_list|)
block|{
name|boolExp
operator|.
name|setPattern
argument_list|(
literal|"true|false"
argument_list|)
expr_stmt|;
name|boolExp
operator|.
name|setCaseSensitivity
argument_list|(
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
expr_stmt|;
name|byteArrayExp
operator|.
name|setPattern
argument_list|(
literal|"[\\x00-\\xff]*"
argument_list|)
expr_stmt|;
name|charExp
operator|.
name|setPattern
argument_list|(
literal|"."
argument_list|)
expr_stmt|;
name|colorExp
operator|.
name|setPattern
argument_list|(
literal|"\\(([0-9]*),([0-9]*),([0-9]*),([0-9]*)\\)"
argument_list|)
expr_stmt|;
name|doubleExp
operator|.
name|setPattern
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|pointExp
operator|.
name|setPattern
argument_list|(
literal|"\\((-?[0-9]*),(-?[0-9]*)\\)"
argument_list|)
expr_stmt|;
name|rectExp
operator|.
name|setPattern
argument_list|(
literal|"\\((-?[0-9]*),(-?[0-9]*),(-?[0-9]*),(-?[0-9]*)\\)"
argument_list|)
expr_stmt|;
name|signedIntegerExp
operator|.
name|setPattern
argument_list|(
literal|"-?[0-9]*"
argument_list|)
expr_stmt|;
name|sizeExp
operator|=
name|pointExp
expr_stmt|;
name|unsignedIntegerExp
operator|.
name|setPattern
argument_list|(
literal|"[0-9]*"
argument_list|)
expr_stmt|;
name|dateExp
operator|.
name|setPattern
argument_list|(
literal|"([0-9]{,4})-([0-9]{,2})-([0-9]{,2})"
argument_list|)
expr_stmt|;
name|timeExp
operator|.
name|setPattern
argument_list|(
literal|"([0-9]{,2}):([0-9]{,2}):([0-9]{,2})"
argument_list|)
expr_stmt|;
name|dateTimeExp
operator|.
name|setPattern
argument_list|(
name|dateExp
operator|.
name|pattern
argument_list|()
operator|+
literal|"T"
operator|+
name|timeExp
operator|.
name|pattern
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|paint
name|void
name|VariantDelegate
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|==
literal|2
condition|)
block|{
name|QVariant
name|value
init|=
name|index
operator|.
name|model
argument_list|()
operator|->
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|isSupportedType
argument_list|(
name|value
operator|.
name|type
argument_list|()
argument_list|)
condition|)
block|{
name|QStyleOptionViewItem
name|myOption
init|=
name|option
decl_stmt|;
name|myOption
operator|.
name|state
operator|&=
operator|~
name|QStyle
operator|::
name|State_Enabled
expr_stmt|;
name|QItemDelegate
operator|::
name|paint
argument_list|(
name|painter
argument_list|,
name|myOption
argument_list|,
name|index
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|QItemDelegate
operator|::
name|paint
argument_list|(
name|painter
argument_list|,
name|option
argument_list|,
name|index
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createEditor
name|QWidget
modifier|*
name|VariantDelegate
operator|::
name|createEditor
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
comment|/* option */
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|!=
literal|2
condition|)
return|return
literal|0
return|;
name|QVariant
name|originalValue
init|=
name|index
operator|.
name|model
argument_list|()
operator|->
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|isSupportedType
argument_list|(
name|originalValue
operator|.
name|type
argument_list|()
argument_list|)
condition|)
return|return
literal|0
return|;
name|QLineEdit
modifier|*
name|lineEdit
init|=
operator|new
name|QLineEdit
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|lineEdit
operator|->
name|setFrame
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QRegExp
name|regExp
decl_stmt|;
switch|switch
condition|(
name|originalValue
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QVariant
operator|::
name|Bool
case|:
name|regExp
operator|=
name|boolExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|ByteArray
case|:
name|regExp
operator|=
name|byteArrayExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Char
case|:
name|regExp
operator|=
name|charExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Color
case|:
name|regExp
operator|=
name|colorExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Date
case|:
name|regExp
operator|=
name|dateExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|DateTime
case|:
name|regExp
operator|=
name|dateTimeExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Double
case|:
name|regExp
operator|=
name|doubleExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Int
case|:
case|case
name|QVariant
operator|::
name|LongLong
case|:
name|regExp
operator|=
name|signedIntegerExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Point
case|:
name|regExp
operator|=
name|pointExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Rect
case|:
name|regExp
operator|=
name|rectExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Size
case|:
name|regExp
operator|=
name|sizeExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Time
case|:
name|regExp
operator|=
name|timeExp
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|UInt
case|:
case|case
name|QVariant
operator|::
name|ULongLong
case|:
name|regExp
operator|=
name|unsignedIntegerExp
expr_stmt|;
break|break;
default|default:
empty_stmt|;
block|}
if|if
condition|(
operator|!
name|regExp
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QValidator
modifier|*
name|validator
init|=
operator|new
name|QRegExpValidator
argument_list|(
name|regExp
argument_list|,
name|lineEdit
argument_list|)
decl_stmt|;
name|lineEdit
operator|->
name|setValidator
argument_list|(
name|validator
argument_list|)
expr_stmt|;
block|}
return|return
name|lineEdit
return|;
block|}
end_function
begin_function
DECL|function|setEditorData
name|void
name|VariantDelegate
operator|::
name|setEditorData
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|QVariant
name|value
init|=
name|index
operator|.
name|model
argument_list|()
operator|->
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
decl_stmt|;
if|if
condition|(
name|QLineEdit
modifier|*
name|lineEdit
init|=
name|qobject_cast
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
condition|)
name|lineEdit
operator|->
name|setText
argument_list|(
name|displayText
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setModelData
name|void
name|VariantDelegate
operator|::
name|setModelData
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|,
name|QAbstractItemModel
modifier|*
name|model
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|QLineEdit
modifier|*
name|lineEdit
init|=
name|qobject_cast
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|lineEdit
operator|->
name|isModified
argument_list|()
condition|)
return|return;
name|QString
name|text
init|=
name|lineEdit
operator|->
name|text
argument_list|()
decl_stmt|;
specifier|const
name|QValidator
modifier|*
name|validator
init|=
name|lineEdit
operator|->
name|validator
argument_list|()
decl_stmt|;
if|if
condition|(
name|validator
condition|)
block|{
name|int
name|pos
decl_stmt|;
if|if
condition|(
name|validator
operator|->
name|validate
argument_list|(
name|text
argument_list|,
name|pos
argument_list|)
operator|!=
name|QValidator
operator|::
name|Acceptable
condition|)
return|return;
block|}
name|QVariant
name|originalValue
init|=
name|index
operator|.
name|model
argument_list|()
operator|->
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
decl_stmt|;
name|QVariant
name|value
decl_stmt|;
switch|switch
condition|(
name|originalValue
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QVariant
operator|::
name|Char
case|:
name|value
operator|=
name|text
operator|.
name|at
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Color
case|:
name|colorExp
operator|.
name|exactMatch
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|value
operator|=
name|QColor
argument_list|(
name|qMin
argument_list|(
name|colorExp
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|255
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|colorExp
operator|.
name|cap
argument_list|(
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|255
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|colorExp
operator|.
name|cap
argument_list|(
literal|3
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|255
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|colorExp
operator|.
name|cap
argument_list|(
literal|4
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Date
case|:
block|{
name|QDate
name|date
init|=
name|QDate
operator|::
name|fromString
argument_list|(
name|text
argument_list|,
name|Qt
operator|::
name|ISODate
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|date
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|value
operator|=
name|date
expr_stmt|;
block|}
break|break;
case|case
name|QVariant
operator|::
name|DateTime
case|:
block|{
name|QDateTime
name|dateTime
init|=
name|QDateTime
operator|::
name|fromString
argument_list|(
name|text
argument_list|,
name|Qt
operator|::
name|ISODate
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|dateTime
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|value
operator|=
name|dateTime
expr_stmt|;
block|}
break|break;
case|case
name|QVariant
operator|::
name|Point
case|:
name|pointExp
operator|.
name|exactMatch
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|value
operator|=
name|QPoint
argument_list|(
name|pointExp
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|pointExp
operator|.
name|cap
argument_list|(
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Rect
case|:
name|rectExp
operator|.
name|exactMatch
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|value
operator|=
name|QRect
argument_list|(
name|rectExp
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|rectExp
operator|.
name|cap
argument_list|(
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|rectExp
operator|.
name|cap
argument_list|(
literal|3
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|rectExp
operator|.
name|cap
argument_list|(
literal|4
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Size
case|:
name|sizeExp
operator|.
name|exactMatch
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|value
operator|=
name|QSize
argument_list|(
name|sizeExp
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|sizeExp
operator|.
name|cap
argument_list|(
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|StringList
case|:
name|value
operator|=
name|text
operator|.
name|split
argument_list|(
literal|","
argument_list|)
expr_stmt|;
break|break;
case|case
name|QVariant
operator|::
name|Time
case|:
block|{
name|QTime
name|time
init|=
name|QTime
operator|::
name|fromString
argument_list|(
name|text
argument_list|,
name|Qt
operator|::
name|ISODate
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|time
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|value
operator|=
name|time
expr_stmt|;
block|}
break|break;
default|default:
name|value
operator|=
name|text
expr_stmt|;
name|value
operator|.
name|convert
argument_list|(
name|originalValue
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|model
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|displayText
argument_list|(
name|value
argument_list|)
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
expr_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|value
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isSupportedType
name|bool
name|VariantDelegate
operator|::
name|isSupportedType
parameter_list|(
name|QVariant
operator|::
name|Type
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QVariant
operator|::
name|Bool
case|:
case|case
name|QVariant
operator|::
name|ByteArray
case|:
case|case
name|QVariant
operator|::
name|Char
case|:
case|case
name|QVariant
operator|::
name|Color
case|:
case|case
name|QVariant
operator|::
name|Date
case|:
case|case
name|QVariant
operator|::
name|DateTime
case|:
case|case
name|QVariant
operator|::
name|Double
case|:
case|case
name|QVariant
operator|::
name|Int
case|:
case|case
name|QVariant
operator|::
name|LongLong
case|:
case|case
name|QVariant
operator|::
name|Point
case|:
case|case
name|QVariant
operator|::
name|Rect
case|:
case|case
name|QVariant
operator|::
name|Size
case|:
case|case
name|QVariant
operator|::
name|String
case|:
case|case
name|QVariant
operator|::
name|StringList
case|:
case|case
name|QVariant
operator|::
name|Time
case|:
case|case
name|QVariant
operator|::
name|UInt
case|:
case|case
name|QVariant
operator|::
name|ULongLong
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
DECL|function|displayText
name|QString
name|VariantDelegate
operator|::
name|displayText
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
switch|switch
condition|(
name|value
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QVariant
operator|::
name|Bool
case|:
case|case
name|QVariant
operator|::
name|ByteArray
case|:
case|case
name|QVariant
operator|::
name|Char
case|:
case|case
name|QVariant
operator|::
name|Double
case|:
case|case
name|QVariant
operator|::
name|Int
case|:
case|case
name|QVariant
operator|::
name|LongLong
case|:
case|case
name|QVariant
operator|::
name|String
case|:
case|case
name|QVariant
operator|::
name|UInt
case|:
case|case
name|QVariant
operator|::
name|ULongLong
case|:
return|return
name|value
operator|.
name|toString
argument_list|()
return|;
case|case
name|QVariant
operator|::
name|Color
case|:
block|{
name|QColor
name|color
init|=
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|value
argument_list|)
decl_stmt|;
return|return
name|QString
argument_list|(
literal|"(%1,%2,%3,%4)"
argument_list|)
operator|.
name|arg
argument_list|(
name|color
operator|.
name|red
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|color
operator|.
name|green
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|color
operator|.
name|blue
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|color
operator|.
name|alpha
argument_list|()
argument_list|)
return|;
block|}
case|case
name|QVariant
operator|::
name|Date
case|:
return|return
name|value
operator|.
name|toDate
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|DateTime
case|:
return|return
name|value
operator|.
name|toDateTime
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|Invalid
case|:
return|return
literal|"<Invalid>"
return|;
case|case
name|QVariant
operator|::
name|Point
case|:
block|{
name|QPoint
name|point
init|=
name|value
operator|.
name|toPoint
argument_list|()
decl_stmt|;
return|return
name|QString
argument_list|(
literal|"(%1,%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|point
operator|.
name|x
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|point
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
case|case
name|QVariant
operator|::
name|Rect
case|:
block|{
name|QRect
name|rect
init|=
name|value
operator|.
name|toRect
argument_list|()
decl_stmt|;
return|return
name|QString
argument_list|(
literal|"(%1,%2,%3,%4)"
argument_list|)
operator|.
name|arg
argument_list|(
name|rect
operator|.
name|x
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|rect
operator|.
name|y
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|rect
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|rect
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
case|case
name|QVariant
operator|::
name|Size
case|:
block|{
name|QSize
name|size
init|=
name|value
operator|.
name|toSize
argument_list|()
decl_stmt|;
return|return
name|QString
argument_list|(
literal|"(%1,%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|size
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
case|case
name|QVariant
operator|::
name|StringList
case|:
return|return
name|value
operator|.
name|toStringList
argument_list|()
operator|.
name|join
argument_list|(
literal|","
argument_list|)
return|;
case|case
name|QVariant
operator|::
name|Time
case|:
return|return
name|value
operator|.
name|toTime
argument_list|()
operator|.
name|toString
argument_list|(
name|Qt
operator|::
name|ISODate
argument_list|)
return|;
default|default:
break|break;
block|}
return|return
name|QString
argument_list|(
literal|"<%1>"
argument_list|)
operator|.
name|arg
argument_list|(
name|value
operator|.
name|typeName
argument_list|()
argument_list|)
return|;
block|}
end_function
end_unit
