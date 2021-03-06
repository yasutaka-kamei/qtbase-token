begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qjson_p.h"
end_include
begin_include
include|#
directive|include
file|<qalgorithms.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QJsonPrivate
namespace|namespace
name|QJsonPrivate
block|{
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
DECL|macro|Q_TO_LITTLE_ENDIAN
define|#
directive|define
name|Q_TO_LITTLE_ENDIAN
parameter_list|(
name|x
parameter_list|)
value|(x)
else|#
directive|else
define|#
directive|define
name|Q_TO_LITTLE_ENDIAN
parameter_list|(
name|x
parameter_list|)
value|( ((x& 0xff)<< 24) | ((x& 0xff00)<< 8) | ((x& 0xff0000)>> 8) | ((x& 0xff000000)>> 24) )
endif|#
directive|endif
DECL|member|emptyArray
specifier|static
specifier|const
name|Base
name|emptyArray
init|=
block|{
block|{
name|Q_TO_LITTLE_ENDIAN
argument_list|(
argument|sizeof(Base)
argument_list|)
block|}
block|,
block|{
literal|0
block|}
block|,
block|{
literal|0
block|}
block|}
decl_stmt|;
DECL|member|emptyObject
specifier|static
specifier|const
name|Base
name|emptyObject
init|=
block|{
block|{
name|Q_TO_LITTLE_ENDIAN
argument_list|(
argument|sizeof(Base)
argument_list|)
block|}
block|,
block|{
literal|0
block|}
block|,
block|{
literal|0
block|}
block|}
decl_stmt|;
DECL|function|compact
name|void
name|Data
operator|::
name|compact
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|Value
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|offset
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|compactionCounter
condition|)
return|return;
name|Base
modifier|*
name|base
init|=
name|header
operator|->
name|root
argument_list|()
decl_stmt|;
name|int
name|reserve
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|base
operator|->
name|is_object
condition|)
block|{
name|Object
modifier|*
name|o
init|=
cast|static_cast
argument_list|<
name|Object
operator|*
argument_list|>
argument_list|(
name|base
argument_list|)
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
operator|(
name|int
operator|)
name|o
operator|->
name|length
condition|;
operator|++
name|i
control|)
name|reserve
operator|+=
name|o
operator|->
name|entryAt
argument_list|(
name|i
argument_list|)
operator|->
name|usedStorage
argument_list|(
name|o
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Array
modifier|*
name|a
init|=
cast|static_cast
argument_list|<
name|Array
operator|*
argument_list|>
argument_list|(
name|base
argument_list|)
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
operator|(
name|int
operator|)
name|a
operator|->
name|length
condition|;
operator|++
name|i
control|)
name|reserve
operator|+=
operator|(
operator|*
name|a
operator|)
index|[
name|i
index|]
operator|.
name|usedStorage
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
name|int
name|size
init|=
sizeof|sizeof
argument_list|(
name|Base
argument_list|)
operator|+
name|reserve
operator|+
name|base
operator|->
name|length
operator|*
sizeof|sizeof
argument_list|(
name|offset
argument_list|)
decl_stmt|;
name|int
name|alloc
init|=
sizeof|sizeof
argument_list|(
name|Header
argument_list|)
operator|+
name|size
decl_stmt|;
name|Header
modifier|*
name|h
init|=
operator|(
name|Header
operator|*
operator|)
name|malloc
argument_list|(
name|alloc
argument_list|)
decl_stmt|;
name|h
operator|->
name|tag
operator|=
name|QJsonDocument
operator|::
name|BinaryFormatTag
expr_stmt|;
name|h
operator|->
name|version
operator|=
literal|1
expr_stmt|;
name|Base
modifier|*
name|b
init|=
name|h
operator|->
name|root
argument_list|()
decl_stmt|;
name|b
operator|->
name|size
operator|=
name|size
expr_stmt|;
name|b
operator|->
name|is_object
operator|=
name|header
operator|->
name|root
argument_list|()
operator|->
name|is_object
expr_stmt|;
name|b
operator|->
name|length
operator|=
name|base
operator|->
name|length
expr_stmt|;
name|b
operator|->
name|tableOffset
operator|=
name|reserve
operator|+
sizeof|sizeof
argument_list|(
name|Array
argument_list|)
expr_stmt|;
name|int
name|offset
init|=
sizeof|sizeof
argument_list|(
name|Base
argument_list|)
decl_stmt|;
if|if
condition|(
name|b
operator|->
name|is_object
condition|)
block|{
name|Object
modifier|*
name|o
init|=
cast|static_cast
argument_list|<
name|Object
operator|*
argument_list|>
argument_list|(
name|base
argument_list|)
decl_stmt|;
name|Object
modifier|*
name|no
init|=
cast|static_cast
argument_list|<
name|Object
operator|*
argument_list|>
argument_list|(
name|b
argument_list|)
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
operator|(
name|int
operator|)
name|o
operator|->
name|length
condition|;
operator|++
name|i
control|)
block|{
name|no
operator|->
name|table
argument_list|()
index|[
name|i
index|]
operator|=
name|offset
expr_stmt|;
specifier|const
name|Entry
modifier|*
name|e
init|=
name|o
operator|->
name|entryAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|Entry
modifier|*
name|ne
init|=
name|no
operator|->
name|entryAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|s
init|=
name|e
operator|->
name|size
argument_list|()
decl_stmt|;
name|memcpy
argument_list|(
name|ne
argument_list|,
name|e
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|s
expr_stmt|;
name|int
name|dataSize
init|=
name|e
operator|->
name|value
operator|.
name|usedStorage
argument_list|(
name|o
argument_list|)
decl_stmt|;
if|if
condition|(
name|dataSize
condition|)
block|{
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|no
operator|+
name|offset
argument_list|,
name|e
operator|->
name|value
operator|.
name|data
argument_list|(
name|o
argument_list|)
argument_list|,
name|dataSize
argument_list|)
expr_stmt|;
name|ne
operator|->
name|value
operator|.
name|value
operator|=
name|offset
expr_stmt|;
name|offset
operator|+=
name|dataSize
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|Array
modifier|*
name|a
init|=
cast|static_cast
argument_list|<
name|Array
operator|*
argument_list|>
argument_list|(
name|base
argument_list|)
decl_stmt|;
name|Array
modifier|*
name|na
init|=
cast|static_cast
argument_list|<
name|Array
operator|*
argument_list|>
argument_list|(
name|b
argument_list|)
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
operator|(
name|int
operator|)
name|a
operator|->
name|length
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|Value
modifier|&
name|v
init|=
operator|(
operator|*
name|a
operator|)
index|[
name|i
index|]
decl_stmt|;
name|Value
modifier|&
name|nv
init|=
operator|(
operator|*
name|na
operator|)
index|[
name|i
index|]
decl_stmt|;
name|nv
operator|=
name|v
expr_stmt|;
name|int
name|dataSize
init|=
name|v
operator|.
name|usedStorage
argument_list|(
name|a
argument_list|)
decl_stmt|;
if|if
condition|(
name|dataSize
condition|)
block|{
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|na
operator|+
name|offset
argument_list|,
name|v
operator|.
name|data
argument_list|(
name|a
argument_list|)
argument_list|,
name|dataSize
argument_list|)
expr_stmt|;
name|nv
operator|.
name|value
operator|=
name|offset
expr_stmt|;
name|offset
operator|+=
name|dataSize
expr_stmt|;
block|}
block|}
block|}
name|Q_ASSERT
argument_list|(
name|offset
operator|==
operator|(
name|int
operator|)
name|b
operator|->
name|tableOffset
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|header
argument_list|)
expr_stmt|;
name|header
operator|=
name|h
expr_stmt|;
name|this
operator|->
name|alloc
operator|=
name|alloc
expr_stmt|;
name|compactionCounter
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|valid
name|bool
name|Data
operator|::
name|valid
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|header
operator|->
name|tag
operator|!=
name|QJsonDocument
operator|::
name|BinaryFormatTag
operator|||
name|header
operator|->
name|version
operator|!=
literal|1u
condition|)
return|return
literal|false
return|;
name|bool
name|res
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|header
operator|->
name|root
argument_list|()
operator|->
name|is_object
condition|)
name|res
operator|=
cast|static_cast
argument_list|<
name|Object
operator|*
argument_list|>
argument_list|(
name|header
operator|->
name|root
argument_list|()
argument_list|)
operator|->
name|isValid
argument_list|()
expr_stmt|;
else|else
name|res
operator|=
cast|static_cast
argument_list|<
name|Array
operator|*
argument_list|>
argument_list|(
name|header
operator|->
name|root
argument_list|()
argument_list|)
operator|->
name|isValid
argument_list|()
expr_stmt|;
return|return
name|res
return|;
block|}
DECL|function|reserveSpace
name|int
name|Base
operator|::
name|reserveSpace
parameter_list|(
name|uint
name|dataSize
parameter_list|,
name|int
name|posInTable
parameter_list|,
name|uint
name|numItems
parameter_list|,
name|bool
name|replace
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|posInTable
operator|>=
literal|0
operator|&&
name|posInTable
operator|<=
operator|(
name|int
operator|)
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
name|size
operator|+
name|dataSize
operator|>=
name|Value
operator|::
name|MaxSize
condition|)
block|{
name|qWarning
argument_list|(
literal|"QJson: Document too large to store in data structure %d %d %d"
argument_list|,
operator|(
name|uint
operator|)
name|size
argument_list|,
name|dataSize
argument_list|,
name|Value
operator|::
name|MaxSize
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|offset
name|off
init|=
name|tableOffset
decl_stmt|;
comment|// move table to new position
if|if
condition|(
name|replace
condition|)
block|{
name|memmove
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
name|table
argument_list|()
operator|)
operator|+
name|dataSize
argument_list|,
name|table
argument_list|()
argument_list|,
name|length
operator|*
sizeof|sizeof
argument_list|(
name|offset
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|memmove
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
name|table
argument_list|()
operator|+
name|posInTable
operator|+
name|numItems
operator|)
operator|+
name|dataSize
argument_list|,
name|table
argument_list|()
operator|+
name|posInTable
argument_list|,
operator|(
name|length
operator|-
name|posInTable
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|offset
argument_list|)
argument_list|)
expr_stmt|;
name|memmove
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
name|table
argument_list|()
operator|)
operator|+
name|dataSize
argument_list|,
name|table
argument_list|()
argument_list|,
name|posInTable
operator|*
sizeof|sizeof
argument_list|(
name|offset
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|tableOffset
operator|+=
name|dataSize
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
operator|(
name|int
operator|)
name|numItems
condition|;
operator|++
name|i
control|)
name|table
argument_list|()
index|[
name|posInTable
operator|+
name|i
index|]
operator|=
name|off
expr_stmt|;
name|size
operator|+=
name|dataSize
expr_stmt|;
if|if
condition|(
operator|!
name|replace
condition|)
block|{
name|length
operator|+=
name|numItems
expr_stmt|;
name|size
operator|+=
name|numItems
operator|*
sizeof|sizeof
argument_list|(
name|offset
argument_list|)
expr_stmt|;
block|}
return|return
name|off
return|;
block|}
DECL|function|removeItems
name|void
name|Base
operator|::
name|removeItems
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|numItems
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|pos
operator|>=
literal|0
operator|&&
name|pos
operator|<=
operator|(
name|int
operator|)
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|+
name|numItems
operator|<
operator|(
name|int
operator|)
name|length
condition|)
name|memmove
argument_list|(
name|table
argument_list|()
operator|+
name|pos
argument_list|,
name|table
argument_list|()
operator|+
name|pos
operator|+
name|numItems
argument_list|,
operator|(
name|length
operator|-
name|pos
operator|-
name|numItems
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|offset
argument_list|)
argument_list|)
expr_stmt|;
name|length
operator|-=
name|numItems
expr_stmt|;
block|}
DECL|function|indexOf
name|int
name|Object
operator|::
name|indexOf
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|bool
modifier|*
name|exists
parameter_list|)
specifier|const
block|{
name|int
name|min
init|=
literal|0
decl_stmt|;
name|int
name|n
init|=
name|length
decl_stmt|;
while|while
condition|(
name|n
operator|>
literal|0
condition|)
block|{
name|int
name|half
init|=
name|n
operator|>>
literal|1
decl_stmt|;
name|int
name|middle
init|=
name|min
operator|+
name|half
decl_stmt|;
if|if
condition|(
operator|*
name|entryAt
argument_list|(
name|middle
argument_list|)
operator|>=
name|key
condition|)
block|{
name|n
operator|=
name|half
expr_stmt|;
block|}
else|else
block|{
name|min
operator|=
name|middle
operator|+
literal|1
expr_stmt|;
name|n
operator|-=
name|half
operator|+
literal|1
expr_stmt|;
block|}
block|}
if|if
condition|(
name|min
operator|<
operator|(
name|int
operator|)
name|length
operator|&&
operator|*
name|entryAt
argument_list|(
name|min
argument_list|)
operator|==
name|key
condition|)
block|{
operator|*
name|exists
operator|=
literal|true
expr_stmt|;
return|return
name|min
return|;
block|}
operator|*
name|exists
operator|=
literal|false
expr_stmt|;
return|return
name|min
return|;
block|}
DECL|function|indexOf
name|int
name|Object
operator|::
name|indexOf
parameter_list|(
name|QLatin1String
name|key
parameter_list|,
name|bool
modifier|*
name|exists
parameter_list|)
specifier|const
block|{
name|int
name|min
init|=
literal|0
decl_stmt|;
name|int
name|n
init|=
name|length
decl_stmt|;
while|while
condition|(
name|n
operator|>
literal|0
condition|)
block|{
name|int
name|half
init|=
name|n
operator|>>
literal|1
decl_stmt|;
name|int
name|middle
init|=
name|min
operator|+
name|half
decl_stmt|;
if|if
condition|(
operator|*
name|entryAt
argument_list|(
name|middle
argument_list|)
operator|>=
name|key
condition|)
block|{
name|n
operator|=
name|half
expr_stmt|;
block|}
else|else
block|{
name|min
operator|=
name|middle
operator|+
literal|1
expr_stmt|;
name|n
operator|-=
name|half
operator|+
literal|1
expr_stmt|;
block|}
block|}
if|if
condition|(
name|min
operator|<
operator|(
name|int
operator|)
name|length
operator|&&
operator|*
name|entryAt
argument_list|(
name|min
argument_list|)
operator|==
name|key
condition|)
block|{
operator|*
name|exists
operator|=
literal|true
expr_stmt|;
return|return
name|min
return|;
block|}
operator|*
name|exists
operator|=
literal|false
expr_stmt|;
return|return
name|min
return|;
block|}
DECL|function|isValid
name|bool
name|Object
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|tableOffset
operator|+
name|length
operator|*
sizeof|sizeof
argument_list|(
name|offset
argument_list|)
operator|>
name|size
condition|)
return|return
literal|false
return|;
name|QString
name|lastKey
decl_stmt|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
name|length
condition|;
operator|++
name|i
control|)
block|{
name|offset
name|entryOffset
init|=
name|table
argument_list|()
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|entryOffset
operator|+
sizeof|sizeof
argument_list|(
name|Entry
argument_list|)
operator|>=
name|tableOffset
condition|)
return|return
literal|false
return|;
name|Entry
modifier|*
name|e
init|=
name|entryAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|s
init|=
name|e
operator|->
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|table
argument_list|()
index|[
name|i
index|]
operator|+
name|s
operator|>
name|tableOffset
condition|)
return|return
literal|false
return|;
name|QString
name|key
init|=
name|e
operator|->
name|key
argument_list|()
decl_stmt|;
if|if
condition|(
name|key
operator|<
name|lastKey
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|e
operator|->
name|value
operator|.
name|isValid
argument_list|(
name|this
argument_list|)
condition|)
return|return
literal|false
return|;
name|lastKey
operator|=
name|key
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
DECL|function|isValid
name|bool
name|Array
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|tableOffset
operator|+
name|length
operator|*
sizeof|sizeof
argument_list|(
name|offset
argument_list|)
operator|>
name|size
condition|)
return|return
literal|false
return|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
name|length
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|isValid
argument_list|(
name|this
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
DECL|function|operator ==
name|bool
name|Entry
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|value
operator|.
name|latinKey
condition|)
return|return
operator|(
name|shallowLatin1Key
argument_list|()
operator|==
name|key
operator|)
return|;
else|else
return|return
operator|(
name|shallowKey
argument_list|()
operator|==
name|key
operator|)
return|;
block|}
DECL|function|operator ==
name|bool
name|Entry
operator|::
name|operator
name|==
parameter_list|(
name|QLatin1String
name|key
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|value
operator|.
name|latinKey
condition|)
return|return
name|shallowLatin1Key
argument_list|()
operator|==
name|key
return|;
else|else
return|return
name|shallowKey
argument_list|()
operator|==
name|key
return|;
block|}
DECL|function|operator ==
name|bool
name|Entry
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|Entry
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|value
operator|.
name|latinKey
condition|)
block|{
if|if
condition|(
name|other
operator|.
name|value
operator|.
name|latinKey
condition|)
return|return
name|shallowLatin1Key
argument_list|()
operator|==
name|other
operator|.
name|shallowLatin1Key
argument_list|()
return|;
return|return
name|shallowLatin1Key
argument_list|()
operator|==
name|other
operator|.
name|shallowKey
argument_list|()
return|;
block|}
elseif|else
if|if
condition|(
name|other
operator|.
name|value
operator|.
name|latinKey
condition|)
block|{
return|return
name|shallowKey
argument_list|()
operator|==
name|other
operator|.
name|shallowLatin1Key
argument_list|()
return|;
block|}
return|return
name|shallowKey
argument_list|()
operator|==
name|other
operator|.
name|shallowKey
argument_list|()
return|;
block|}
DECL|function|operator >=
name|bool
name|Entry
operator|::
name|operator
name|>=
parameter_list|(
specifier|const
name|Entry
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|value
operator|.
name|latinKey
condition|)
block|{
if|if
condition|(
name|other
operator|.
name|value
operator|.
name|latinKey
condition|)
return|return
name|shallowLatin1Key
argument_list|()
operator|>=
name|other
operator|.
name|shallowLatin1Key
argument_list|()
return|;
return|return
name|shallowLatin1Key
argument_list|()
operator|>=
name|other
operator|.
name|shallowKey
argument_list|()
return|;
block|}
elseif|else
if|if
condition|(
name|other
operator|.
name|value
operator|.
name|latinKey
condition|)
block|{
return|return
name|shallowKey
argument_list|()
operator|>=
name|other
operator|.
name|shallowLatin1Key
argument_list|()
return|;
block|}
return|return
name|shallowKey
argument_list|()
operator|>=
name|other
operator|.
name|shallowKey
argument_list|()
return|;
block|}
DECL|function|usedStorage
name|int
name|Value
operator|::
name|usedStorage
parameter_list|(
specifier|const
name|Base
modifier|*
name|b
parameter_list|)
specifier|const
block|{
name|int
name|s
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QJsonValue
operator|::
name|Double
case|:
if|if
condition|(
name|latinOrIntValue
condition|)
break|break;
name|s
operator|=
sizeof|sizeof
argument_list|(
name|double
argument_list|)
expr_stmt|;
break|break;
case|case
name|QJsonValue
operator|::
name|String
case|:
block|{
name|char
modifier|*
name|d
init|=
name|data
argument_list|(
name|b
argument_list|)
decl_stmt|;
if|if
condition|(
name|latinOrIntValue
condition|)
name|s
operator|=
sizeof|sizeof
argument_list|(
name|ushort
argument_list|)
operator|+
name|qFromLittleEndian
argument_list|(
operator|*
operator|(
name|ushort
operator|*
operator|)
name|d
argument_list|)
expr_stmt|;
else|else
name|s
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|ushort
argument_list|)
operator|*
name|qFromLittleEndian
argument_list|(
operator|*
operator|(
name|int
operator|*
operator|)
name|d
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QJsonValue
operator|::
name|Array
case|:
case|case
name|QJsonValue
operator|::
name|Object
case|:
name|s
operator|=
name|base
argument_list|(
name|b
argument_list|)
operator|->
name|size
expr_stmt|;
break|break;
case|case
name|QJsonValue
operator|::
name|Null
case|:
case|case
name|QJsonValue
operator|::
name|Bool
case|:
default|default:
break|break;
block|}
return|return
name|alignedSize
argument_list|(
name|s
argument_list|)
return|;
block|}
DECL|function|isValid
name|bool
name|Value
operator|::
name|isValid
parameter_list|(
specifier|const
name|Base
modifier|*
name|b
parameter_list|)
specifier|const
block|{
name|int
name|offset
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QJsonValue
operator|::
name|Double
case|:
if|if
condition|(
name|latinOrIntValue
condition|)
break|break;
comment|// fall through
case|case
name|QJsonValue
operator|::
name|String
case|:
case|case
name|QJsonValue
operator|::
name|Array
case|:
case|case
name|QJsonValue
operator|::
name|Object
case|:
name|offset
operator|=
name|value
expr_stmt|;
break|break;
case|case
name|QJsonValue
operator|::
name|Null
case|:
case|case
name|QJsonValue
operator|::
name|Bool
case|:
default|default:
break|break;
block|}
if|if
condition|(
operator|!
name|offset
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|offset
operator|+
sizeof|sizeof
argument_list|(
name|uint
argument_list|)
operator|>
name|b
operator|->
name|tableOffset
condition|)
return|return
literal|false
return|;
name|int
name|s
init|=
name|usedStorage
argument_list|(
name|b
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|s
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|s
operator|<
literal|0
operator|||
name|offset
operator|+
name|s
operator|>
operator|(
name|int
operator|)
name|b
operator|->
name|tableOffset
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|type
operator|==
name|QJsonValue
operator|::
name|Array
condition|)
return|return
cast|static_cast
argument_list|<
name|Array
operator|*
argument_list|>
argument_list|(
name|base
argument_list|(
name|b
argument_list|)
argument_list|)
operator|->
name|isValid
argument_list|()
return|;
if|if
condition|(
name|type
operator|==
name|QJsonValue
operator|::
name|Object
condition|)
return|return
cast|static_cast
argument_list|<
name|Object
operator|*
argument_list|>
argument_list|(
name|base
argument_list|(
name|b
argument_list|)
argument_list|)
operator|->
name|isValid
argument_list|()
return|;
return|return
literal|true
return|;
block|}
comment|/*!     \internal  */
DECL|function|requiredStorage
name|int
name|Value
operator|::
name|requiredStorage
parameter_list|(
name|QJsonValue
modifier|&
name|v
parameter_list|,
name|bool
modifier|*
name|compressed
parameter_list|)
block|{
operator|*
name|compressed
operator|=
literal|false
expr_stmt|;
switch|switch
condition|(
name|v
operator|.
name|t
condition|)
block|{
case|case
name|QJsonValue
operator|::
name|Double
case|:
if|if
condition|(
name|QJsonPrivate
operator|::
name|compressedNumber
argument_list|(
name|v
operator|.
name|dbl
argument_list|)
operator|!=
name|INT_MAX
condition|)
block|{
operator|*
name|compressed
operator|=
literal|true
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
sizeof|sizeof
argument_list|(
name|double
argument_list|)
return|;
case|case
name|QJsonValue
operator|::
name|String
case|:
block|{
name|QString
name|s
init|=
name|v
operator|.
name|toString
argument_list|()
decl_stmt|;
operator|*
name|compressed
operator|=
name|QJsonPrivate
operator|::
name|useCompressed
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|QJsonPrivate
operator|::
name|qStringSize
argument_list|(
name|s
argument_list|,
operator|*
name|compressed
argument_list|)
return|;
block|}
case|case
name|QJsonValue
operator|::
name|Array
case|:
case|case
name|QJsonValue
operator|::
name|Object
case|:
if|if
condition|(
name|v
operator|.
name|d
operator|&&
name|v
operator|.
name|d
operator|->
name|compactionCounter
condition|)
block|{
name|v
operator|.
name|detach
argument_list|()
expr_stmt|;
name|v
operator|.
name|d
operator|->
name|compact
argument_list|()
expr_stmt|;
name|v
operator|.
name|base
operator|=
cast|static_cast
argument_list|<
name|QJsonPrivate
operator|::
name|Base
operator|*
argument_list|>
argument_list|(
name|v
operator|.
name|d
operator|->
name|header
operator|->
name|root
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|v
operator|.
name|base
condition|?
name|v
operator|.
name|base
operator|->
name|size
else|:
sizeof|sizeof
argument_list|(
name|QJsonPrivate
operator|::
name|Base
argument_list|)
return|;
case|case
name|QJsonValue
operator|::
name|Undefined
case|:
case|case
name|QJsonValue
operator|::
name|Null
case|:
case|case
name|QJsonValue
operator|::
name|Bool
case|:
break|break;
block|}
return|return
literal|0
return|;
block|}
comment|/*!     \internal  */
DECL|function|valueToStore
name|uint
name|Value
operator|::
name|valueToStore
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|v
parameter_list|,
name|uint
name|offset
parameter_list|)
block|{
switch|switch
condition|(
name|v
operator|.
name|t
condition|)
block|{
case|case
name|QJsonValue
operator|::
name|Undefined
case|:
case|case
name|QJsonValue
operator|::
name|Null
case|:
break|break;
case|case
name|QJsonValue
operator|::
name|Bool
case|:
return|return
name|v
operator|.
name|b
return|;
case|case
name|QJsonValue
operator|::
name|Double
case|:
block|{
name|int
name|c
init|=
name|QJsonPrivate
operator|::
name|compressedNumber
argument_list|(
name|v
operator|.
name|dbl
argument_list|)
decl_stmt|;
if|if
condition|(
name|c
operator|!=
name|INT_MAX
condition|)
return|return
name|c
return|;
block|}
comment|// fall through
case|case
name|QJsonValue
operator|::
name|String
case|:
case|case
name|QJsonValue
operator|::
name|Array
case|:
case|case
name|QJsonValue
operator|::
name|Object
case|:
return|return
name|offset
return|;
block|}
return|return
literal|0
return|;
block|}
comment|/*!     \internal  */
DECL|function|copyData
name|void
name|Value
operator|::
name|copyData
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|v
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
name|bool
name|compressed
parameter_list|)
block|{
switch|switch
condition|(
name|v
operator|.
name|t
condition|)
block|{
case|case
name|QJsonValue
operator|::
name|Double
case|:
if|if
condition|(
operator|!
name|compressed
condition|)
block|{
name|qToLittleEndian
argument_list|(
name|v
operator|.
name|ui
argument_list|,
name|dest
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|QJsonValue
operator|::
name|String
case|:
block|{
name|QString
name|str
init|=
name|v
operator|.
name|toString
argument_list|()
decl_stmt|;
name|QJsonPrivate
operator|::
name|copyString
argument_list|(
name|dest
argument_list|,
name|str
argument_list|,
name|compressed
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QJsonValue
operator|::
name|Array
case|:
case|case
name|QJsonValue
operator|::
name|Object
case|:
block|{
specifier|const
name|QJsonPrivate
operator|::
name|Base
modifier|*
name|b
init|=
name|v
operator|.
name|base
decl_stmt|;
if|if
condition|(
operator|!
name|b
condition|)
name|b
operator|=
operator|(
name|v
operator|.
name|t
operator|==
name|QJsonValue
operator|::
name|Array
condition|?
operator|&
name|emptyArray
else|:
operator|&
name|emptyObject
operator|)
expr_stmt|;
name|memcpy
argument_list|(
name|dest
argument_list|,
name|b
argument_list|,
name|b
operator|->
name|size
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
break|break;
block|}
block|}
block|}
end_namespace
begin_comment
comment|// namespace QJsonPrivate
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
