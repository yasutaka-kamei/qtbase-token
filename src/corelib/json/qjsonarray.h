begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QJSONARRAY_H
end_ifndef
begin_define
DECL|macro|QJSONARRAY_H
define|#
directive|define
name|QJSONARRAY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qjsonvalue.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qiterator.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_INITIALIZER_LISTS
argument_list|)
end_if
begin_include
include|#
directive|include
file|<initializer_list>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_expr_stmt
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
begin_typedef
DECL|typedef|QVariantList
typedef|typedef
name|QList
operator|<
name|QVariant
operator|>
name|QVariantList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QJsonArray
block|{
name|public
label|:
name|QJsonArray
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_INITIALIZER_LISTS
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|QJsonArray
argument_list|(
argument|std::initializer_list<QJsonValue> args
argument_list|)
block|{
name|initialize
argument_list|()
expr_stmt|;
for|for
control|(
name|std
operator|::
name|initializer_list
operator|<
name|QJsonValue
operator|>
operator|::
name|const_iterator
name|i
operator|=
name|args
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|args
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
name|append
argument_list|(
operator|*
name|i
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
operator|~
name|QJsonArray
argument_list|()
expr_stmt|;
name|QJsonArray
argument_list|(
specifier|const
name|QJsonArray
operator|&
name|other
argument_list|)
expr_stmt|;
name|QJsonArray
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QJsonArray
operator|&
name|other
operator|)
decl_stmt|;
specifier|static
name|QJsonArray
name|fromStringList
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|list
parameter_list|)
function_decl|;
specifier|static
name|QJsonArray
name|fromVariantList
parameter_list|(
specifier|const
name|QVariantList
modifier|&
name|list
parameter_list|)
function_decl|;
name|QVariantList
name|toVariantList
argument_list|()
specifier|const
expr_stmt|;
name|int
name|size
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|QJsonValue
name|at
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|QJsonValue
name|first
argument_list|()
specifier|const
expr_stmt|;
name|QJsonValue
name|last
argument_list|()
specifier|const
expr_stmt|;
name|void
name|prepend
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|value
parameter_list|)
function_decl|;
name|void
name|append
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|value
parameter_list|)
function_decl|;
name|void
name|removeAt
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
name|QJsonValue
name|takeAt
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
specifier|inline
name|void
name|removeFirst
parameter_list|()
block|{
name|removeAt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|removeLast
parameter_list|()
block|{
name|removeAt
argument_list|(
name|size
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|void
name|insert
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|QJsonValue
modifier|&
name|value
parameter_list|)
function_decl|;
name|void
name|replace
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|QJsonValue
modifier|&
name|value
parameter_list|)
function_decl|;
name|bool
name|contains
argument_list|(
specifier|const
name|QJsonValue
operator|&
name|element
argument_list|)
decl|const
decl_stmt|;
name|QJsonValueRef
name|operator
function_decl|[]
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
name|QJsonValue
name|operator
index|[]
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QJsonArray
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QJsonArray
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|class
name|const_iterator
decl_stmt|;
name|class
name|iterator
block|{
name|public
label|:
name|QJsonArray
modifier|*
name|a
decl_stmt|;
name|int
name|i
decl_stmt|;
typedef|typedef
name|std
operator|::
name|random_access_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|int
name|difference_type
typedef|;
typedef|typedef
name|QJsonValue
name|value_type
typedef|;
typedef|typedef
name|QJsonValueRef
name|reference
typedef|;
typedef|typedef
name|QJsonValueRefPtr
name|pointer
typedef|;
specifier|inline
name|iterator
argument_list|()
operator|:
name|a
argument_list|(
name|Q_NULLPTR
argument_list|)
operator|,
name|i
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
specifier|inline
name|iterator
argument_list|(
argument|QJsonArray *array
argument_list|,
argument|int index
argument_list|)
operator|:
name|a
argument_list|(
name|array
argument_list|)
operator|,
name|i
argument_list|(
argument|index
argument_list|)
block|{ }
specifier|inline
name|QJsonValueRef
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|QJsonValueRef
argument_list|(
name|a
argument_list|,
name|i
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|Q_QDOC
specifier|inline
name|QJsonValueRef
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
else|#
directive|else
specifier|inline
name|QJsonValueRefPtr
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|QJsonValueRefPtr
argument_list|(
name|a
argument_list|,
name|i
argument_list|)
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
specifier|inline
name|QJsonValueRef
name|operator
index|[]
argument_list|(
name|int
name|j
argument_list|)
decl|const
block|{
return|return
name|QJsonValueRef
argument_list|(
name|a
argument_list|,
name|i
operator|+
name|j
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|o
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|o
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|<
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|<=
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|>
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|>=
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|o
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|o
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|<
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|<=
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|>
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|>=
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|iterator
name|n
operator|=
operator|*
name|this
block|;
operator|++
name|i
block|;
return|return
name|n
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
name|i
operator|--
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|iterator
name|n
operator|=
operator|*
name|this
block|;
name|i
operator|--
block|;
return|return
name|n
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|+=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|+=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|-=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|-=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|+
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|a
argument_list|,
name|i
operator|+
name|j
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|-
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|a
argument_list|,
name|i
operator|-
name|j
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|operator
operator|-
operator|(
name|iterator
name|j
operator|)
specifier|const
block|{
return|return
name|i
operator|-
name|j
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_decl_stmt
unit|};
name|friend
name|class
name|iterator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|const_iterator
block|{
name|public
label|:
specifier|const
name|QJsonArray
modifier|*
name|a
decl_stmt|;
name|int
name|i
decl_stmt|;
typedef|typedef
name|std
operator|::
name|random_access_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|qptrdiff
name|difference_type
typedef|;
typedef|typedef
name|QJsonValue
name|value_type
typedef|;
typedef|typedef
name|QJsonValue
name|reference
typedef|;
typedef|typedef
name|QJsonValuePtr
name|pointer
typedef|;
specifier|inline
name|const_iterator
argument_list|()
operator|:
name|a
argument_list|(
name|Q_NULLPTR
argument_list|)
operator|,
name|i
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
specifier|inline
name|const_iterator
argument_list|(
argument|const QJsonArray *array
argument_list|,
argument|int index
argument_list|)
operator|:
name|a
argument_list|(
name|array
argument_list|)
operator|,
name|i
argument_list|(
argument|index
argument_list|)
block|{ }
if|#
directive|if
name|QT_VERSION
operator|<
name|QT_VERSION_CHECK
argument_list|(
literal|6
operator|,
literal|0
operator|,
literal|0
argument_list|)
specifier|inline
name|const_iterator
argument_list|(
specifier|const
name|const_iterator
operator|&
name|o
argument_list|)
operator|:
name|a
argument_list|(
name|o
operator|.
name|a
argument_list|)
operator|,
name|i
argument_list|(
argument|o.i
argument_list|)
block|{}
comment|// ### Qt 6: Removed so class can be trivially-copyable
endif|#
directive|endif
specifier|inline
name|const_iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|o
argument_list|)
operator|:
name|a
argument_list|(
name|o
operator|.
name|a
argument_list|)
operator|,
name|i
argument_list|(
argument|o.i
argument_list|)
block|{}
specifier|inline
name|QJsonValue
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|a
operator|->
name|at
argument_list|(
name|i
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|Q_QDOC
specifier|inline
name|QJsonValue
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
specifier|inline
name|QJsonValuePtr
name|operator
operator|->
expr|(
end_expr_stmt
begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|QJsonValuePtr
argument_list|(
name|a
operator|->
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
specifier|inline
name|QJsonValue
name|operator
index|[]
argument_list|(
name|int
name|j
argument_list|)
decl|const
block|{
return|return
name|a
operator|->
name|at
argument_list|(
name|i
operator|+
name|j
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|o
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|o
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|<
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|<=
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|>
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|const_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|i
operator|>=
name|other
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|const_iterator
name|n
operator|=
operator|*
name|this
block|;
operator|++
name|i
block|;
return|return
name|n
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
name|i
operator|--
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|const_iterator
name|n
operator|=
operator|*
name|this
block|;
name|i
operator|--
block|;
return|return
name|n
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|+=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|+=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|-=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|-=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|+
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|a
argument_list|,
name|i
operator|+
name|j
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|-
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|a
argument_list|,
name|i
operator|-
name|j
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|operator
operator|-
operator|(
name|const_iterator
name|j
operator|)
specifier|const
block|{
return|return
name|i
operator|-
name|j
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_decl_stmt
unit|};
name|friend
name|class
name|const_iterator
decl_stmt|;
end_decl_stmt
begin_comment
comment|// stl style
end_comment
begin_function
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
name|detach2
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|constBegin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
name|detach2
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|constEnd
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|iterator
name|insert
parameter_list|(
name|iterator
name|before
parameter_list|,
specifier|const
name|QJsonValue
modifier|&
name|value
parameter_list|)
block|{
name|insert
argument_list|(
name|before
operator|.
name|i
argument_list|,
name|value
argument_list|)
expr_stmt|;
return|return
name|before
return|;
block|}
end_function
begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|it
parameter_list|)
block|{
name|removeAt
argument_list|(
name|it
operator|.
name|i
argument_list|)
expr_stmt|;
return|return
name|it
return|;
block|}
end_function
begin_comment
comment|// more Qt
end_comment
begin_typedef
typedef|typedef
name|iterator
name|Iterator
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|const_iterator
name|ConstIterator
typedef|;
end_typedef
begin_comment
comment|// convenience
end_comment
begin_expr_stmt
specifier|inline
name|QJsonArray
name|operator
operator|+
operator|(
specifier|const
name|QJsonValue
operator|&
name|v
operator|)
specifier|const
block|{
name|QJsonArray
name|n
operator|=
operator|*
name|this
block|;
name|n
operator|+=
name|v
block|;
return|return
name|n
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QJsonArray
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QJsonValue
operator|&
name|v
operator|)
block|{
name|append
argument_list|(
name|v
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QJsonArray
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QJsonValue
operator|&
name|v
operator|)
block|{
name|append
argument_list|(
name|v
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_comment
comment|// stl compatibility
end_comment
begin_function
specifier|inline
name|void
name|push_back
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|t
parameter_list|)
block|{
name|append
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|push_front
parameter_list|(
specifier|const
name|QJsonValue
modifier|&
name|t
parameter_list|)
block|{
name|prepend
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|pop_front
parameter_list|()
block|{
name|removeFirst
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|pop_back
parameter_list|()
block|{
name|removeLast
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_typedef
typedef|typedef
name|int
name|size_type
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|QJsonValue
name|value_type
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|value_type
modifier|*
name|pointer
typedef|;
end_typedef
begin_typedef
typedef|typedef
specifier|const
name|value_type
modifier|*
name|const_pointer
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|QJsonValueRef
name|reference
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|QJsonValue
name|const_reference
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|difference_type
typedef|;
end_typedef
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|friend
name|class
name|QJsonPrivate
operator|::
name|Data
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|friend
name|class
name|QJsonValue
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QJsonDocument
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|friend
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QJsonArray
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QJsonArray
argument_list|(
name|QJsonPrivate
operator|::
name|Data
operator|*
name|data
argument_list|,
name|QJsonPrivate
operator|::
name|Array
operator|*
name|array
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|initialize
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|compact
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// ### Qt 6: remove me and merge with detach2
end_comment
begin_function_decl
name|void
name|detach
parameter_list|(
name|uint
name|reserve
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|detach2
parameter_list|(
name|uint
name|reserve
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QJsonPrivate
operator|::
name|Data
operator|*
name|d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QJsonPrivate
operator|::
name|Array
operator|*
name|a
expr_stmt|;
end_expr_stmt
begin_if
unit|};
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_JSON_READONLY
argument_list|)
end_if
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QJsonArray
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QJSONARRAY_H
end_comment
end_unit
