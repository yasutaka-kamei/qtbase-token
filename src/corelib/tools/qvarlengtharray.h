begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVARLENGTHARRAY_H
end_ifndef
begin_define
DECL|macro|QVARLENGTHARRAY_H
define|#
directive|define
name|QVARLENGTHARRAY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qcontainerfwd.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qalgorithms.h>
end_include
begin_include
include|#
directive|include
file|<new>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|QPodList
name|class
name|QPodList
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Prealloc = 256 by default, specified in qcontainerfwd.h
end_comment
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
name|class
name|QVarLengthArray
block|{
name|public
operator|:
specifier|inline
name|explicit
name|QVarLengthArray
argument_list|(
argument|int size =
literal|0
argument_list|)
block|;
specifier|inline
name|QVarLengthArray
argument_list|(
specifier|const
name|QVarLengthArray
operator|<
name|T
argument_list|,
name|Prealloc
operator|>
operator|&
name|other
argument_list|)
operator|:
name|a
argument_list|(
name|Prealloc
argument_list|)
block|,
name|s
argument_list|(
literal|0
argument_list|)
block|,
name|ptr
argument_list|(
argument|reinterpret_cast<T *>(array)
argument_list|)
block|{
name|append
argument_list|(
name|other
operator|.
name|constData
argument_list|()
argument_list|,
name|other
operator|.
name|size
argument_list|()
argument_list|)
block|;     }
specifier|inline
operator|~
name|QVarLengthArray
argument_list|()
block|{
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
condition|)
block|{
name|T
modifier|*
name|i
init|=
name|ptr
operator|+
name|s
decl_stmt|;
while|while
condition|(
name|i
operator|--
operator|!=
name|ptr
condition|)
name|i
operator|->
expr|~
name|T
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|ptr
operator|!=
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|array
operator|)
condition|)
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|&
name|other
operator|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|other
condition|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|append
argument_list|(
name|other
operator|.
name|constData
argument_list|()
argument_list|,
name|other
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_function
unit|}      inline
name|void
name|removeLast
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|s
operator|>
literal|0
argument_list|)
expr_stmt|;
name|realloc
argument_list|(
name|s
operator|-
literal|1
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|s
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
name|s
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|length
argument_list|()
specifier|const
block|{
return|return
name|s
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|T
modifier|&
name|first
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|begin
argument_list|()
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
name|T
operator|&
name|first
argument_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isEmpty
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|begin
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
name|T
modifier|&
name|last
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
operator|(
name|end
argument_list|()
operator|-
literal|1
operator|)
return|;
block|}
end_function
begin_expr_stmt
specifier|const
name|T
operator|&
name|last
argument_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isEmpty
argument_list|()
argument_list|)
block|;
return|return
operator|*
operator|(
name|end
argument_list|()
operator|-
literal|1
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
operator|(
name|s
operator|==
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_function_decl
specifier|inline
name|void
name|resize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|void
name|clear
parameter_list|()
block|{
name|resize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|int
name|capacity
argument_list|()
specifier|const
block|{
return|return
name|a
return|;
block|}
end_expr_stmt
begin_function_decl
specifier|inline
name|void
name|reserve
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|T
modifier|&
name|operator
function|[]
parameter_list|(
name|int
name|idx
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|idx
operator|>=
literal|0
operator|&&
name|idx
operator|<
name|s
argument_list|)
expr_stmt|;
return|return
name|ptr
index|[
name|idx
index|]
return|;
block|}
end_function
begin_decl_stmt
specifier|inline
specifier|const
name|T
modifier|&
name|operator
index|[]
argument_list|(
name|int
name|idx
argument_list|)
decl|const
block|{
name|Q_ASSERT
argument_list|(
name|idx
operator|>=
literal|0
operator|&&
name|idx
operator|<
name|s
argument_list|)
expr_stmt|;
return|return
name|ptr
index|[
name|idx
index|]
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
specifier|const
name|T
modifier|&
name|at
argument_list|(
name|int
name|idx
argument_list|)
decl|const
block|{
return|return
name|operator
index|[]
operator|(
name|idx
operator|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|T
name|value
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|T
name|value
argument_list|(
name|int
name|i
argument_list|,
specifier|const
name|T
operator|&
name|defaultValue
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function
specifier|inline
name|void
name|append
parameter_list|(
specifier|const
name|T
modifier|&
name|t
parameter_list|)
block|{
if|if
condition|(
name|s
operator|==
name|a
condition|)
comment|// i.e. s != 0
name|realloc
argument_list|(
name|s
argument_list|,
name|s
operator|<<
literal|1
argument_list|)
expr_stmt|;
specifier|const
name|int
name|idx
init|=
name|s
operator|++
decl_stmt|;
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
condition|)
block|{
name|new
argument_list|(
argument|ptr + idx
argument_list|)
name|T
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ptr
index|[
name|idx
index|]
operator|=
name|t
expr_stmt|;
block|}
block|}
end_function
begin_function_decl
name|void
name|append
parameter_list|(
specifier|const
name|T
modifier|*
name|buf
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
name|t
operator|)
block|{
name|append
argument_list|(
name|t
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
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|T
operator|&
name|t
operator|)
block|{
name|append
argument_list|(
name|t
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_function_decl
name|void
name|prepend
parameter_list|(
specifier|const
name|T
modifier|&
name|t
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|insert
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|T
modifier|&
name|t
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|insert
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|n
parameter_list|,
specifier|const
name|T
modifier|&
name|t
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|replace
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|T
modifier|&
name|t
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|remove
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|remove
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|T
modifier|*
name|data
parameter_list|()
block|{
return|return
name|ptr
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
name|T
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|ptr
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|T
operator|*
name|constData
argument_list|()
specifier|const
block|{
return|return
name|ptr
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
name|T
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
name|value_type
modifier|&
name|reference
typedef|;
end_typedef
begin_typedef
typedef|typedef
specifier|const
name|value_type
modifier|&
name|const_reference
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|qptrdiff
name|difference_type
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|T
modifier|*
name|iterator
typedef|;
end_typedef
begin_typedef
typedef|typedef
specifier|const
name|T
modifier|*
name|const_iterator
typedef|;
end_typedef
begin_function
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|ptr
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
name|ptr
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|cbegin
argument_list|()
specifier|const
block|{
return|return
name|ptr
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
name|ptr
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
return|return
name|ptr
operator|+
name|s
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
name|ptr
operator|+
name|s
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|cend
argument_list|()
specifier|const
block|{
return|return
name|ptr
operator|+
name|s
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
name|ptr
operator|+
name|s
return|;
block|}
end_expr_stmt
begin_function_decl
name|iterator
name|insert
parameter_list|(
name|iterator
name|before
parameter_list|,
name|int
name|n
parameter_list|,
specifier|const
name|T
modifier|&
name|x
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|iterator
name|insert
parameter_list|(
name|iterator
name|before
parameter_list|,
specifier|const
name|T
modifier|&
name|x
parameter_list|)
block|{
return|return
name|insert
argument_list|(
name|before
argument_list|,
literal|1
argument_list|,
name|x
argument_list|)
return|;
block|}
end_function
begin_function_decl
name|iterator
name|erase
parameter_list|(
name|iterator
name|begin
parameter_list|,
name|iterator
name|end
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|iterator
name|erase
parameter_list|(
name|iterator
name|pos
parameter_list|)
block|{
return|return
name|erase
argument_list|(
name|pos
argument_list|,
name|pos
operator|+
literal|1
argument_list|)
return|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|friend
name|class
name|QPodList
operator|<
name|T
operator|,
name|Prealloc
operator|>
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|realloc
parameter_list|(
name|int
name|size
parameter_list|,
name|int
name|alloc
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt
begin_comment
comment|// capacity
end_comment
begin_decl_stmt
name|int
name|s
decl_stmt|;
end_decl_stmt
begin_comment
comment|// size
end_comment
begin_decl_stmt
name|T
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt
begin_comment
comment|// data
end_comment
begin_union
union|union
block|{
name|char
name|array
index|[
name|Prealloc
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
index|]
decl_stmt|;
name|qint64
name|q_for_alignment_1
decl_stmt|;
name|double
name|q_for_alignment_2
decl_stmt|;
block|}
union|;
end_union
begin_expr_stmt
unit|};
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|QVarLengthArray
name|Q_INLINE_TEMPLATE
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|QVarLengthArray
argument_list|(
argument|int asize
argument_list|)
operator|:
name|s
argument_list|(
argument|asize
argument_list|)
block|{
if|if
condition|(
name|s
operator|>
name|Prealloc
condition|)
block|{
name|ptr
operator|=
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|malloc
argument_list|(
name|s
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
name|a
operator|=
name|s
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|ptr
operator|=
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|array
operator|)
expr_stmt|;
name|a
operator|=
name|Prealloc
expr_stmt|;
block|}
end_else
begin_if
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
condition|)
block|{
name|T
modifier|*
name|i
init|=
name|ptr
operator|+
name|s
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|ptr
condition|)
name|new
argument_list|(
argument|--i
argument_list|)
name|T
expr_stmt|;
block|}
end_if
begin_expr_stmt
unit|}  template
DECL|variable|T
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|resize
name|Q_INLINE_TEMPLATE
name|void
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|resize
argument_list|(
argument|int asize
argument_list|)
block|{
name|realloc
argument_list|(
name|asize
argument_list|,
name|qMax
argument_list|(
name|asize
argument_list|,
name|a
argument_list|)
argument_list|)
block|; }
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|reserve
name|Q_INLINE_TEMPLATE
name|void
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|reserve
argument_list|(
argument|int asize
argument_list|)
block|{
if|if
condition|(
name|asize
operator|>
name|a
condition|)
name|realloc
argument_list|(
name|s
argument_list|,
name|asize
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|append
name|Q_OUTOFLINE_TEMPLATE
name|void
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|append
argument_list|(
argument|const T *abuf
argument_list|,
argument|int increment
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|abuf
argument_list|)
block|;
if|if
condition|(
name|increment
operator|<=
literal|0
condition|)
return|return;
specifier|const
name|int
name|asize
operator|=
name|s
operator|+
name|increment
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|asize
operator|>=
name|a
condition|)
name|realloc
argument_list|(
name|s
argument_list|,
name|qMax
argument_list|(
name|s
operator|*
literal|2
argument_list|,
name|asize
argument_list|)
argument_list|)
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
condition|)
block|{
comment|// call constructor for new objects (which can throw)
while|while
condition|(
name|s
operator|<
name|asize
condition|)
name|new
argument_list|(
argument|ptr+(s++)
argument_list|)
name|T
argument_list|(
operator|*
name|abuf
operator|++
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|memcpy
argument_list|(
operator|&
name|ptr
index|[
name|s
index|]
argument_list|,
name|abuf
argument_list|,
name|increment
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
name|s
operator|=
name|asize
expr_stmt|;
block|}
end_if
begin_expr_stmt
unit|}  template
DECL|variable|T
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|realloc
name|Q_OUTOFLINE_TEMPLATE
name|void
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|realloc
argument_list|(
argument|int asize
argument_list|,
argument|int aalloc
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|aalloc
operator|>=
name|asize
argument_list|)
block|;
name|T
operator|*
name|oldPtr
operator|=
name|ptr
block|;
name|int
name|osize
operator|=
name|s
block|;
specifier|const
name|int
name|copySize
operator|=
name|qMin
argument_list|(
name|asize
argument_list|,
name|osize
argument_list|)
block|;
if|if
condition|(
name|aalloc
operator|!=
name|a
condition|)
block|{
name|ptr
operator|=
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|malloc
argument_list|(
name|aalloc
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptr
condition|)
block|{
name|s
operator|=
literal|0
expr_stmt|;
name|a
operator|=
name|aalloc
expr_stmt|;
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isStatic
condition|)
block|{
name|QT_TRY
block|{
comment|// copy all the old elements
while|while
condition|(
name|s
operator|<
name|copySize
condition|)
block|{
name|new
argument_list|(
argument|ptr+s
argument_list|)
name|T
argument_list|(
operator|*
operator|(
name|oldPtr
operator|+
name|s
operator|)
argument_list|)
expr_stmt|;
operator|(
name|oldPtr
operator|+
name|s
operator|)
operator|->
operator|~
name|T
argument_list|()
expr_stmt|;
name|s
operator|++
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|} QT_CATCH
operator|(
operator|...
operator|)
block|{
comment|// clean up all the old objects and then free the old ptr
name|int
name|sClean
operator|=
name|s
block|;
while|while
condition|(
name|sClean
operator|<
name|osize
condition|)
operator|(
name|oldPtr
operator|+
operator|(
name|sClean
operator|++
operator|)
operator|)
operator|->
operator|~
name|T
argument_list|()
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|oldPtr
operator|!=
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|array
operator|)
operator|&&
name|oldPtr
operator|!=
name|ptr
condition|)
name|free
argument_list|(
name|oldPtr
argument_list|)
expr_stmt|;
end_if
begin_expr_stmt
name|QT_RETHROW
expr_stmt|;
end_expr_stmt
begin_else
unit|}             }
else|else
block|{
name|memcpy
argument_list|(
name|ptr
argument_list|,
name|oldPtr
argument_list|,
name|copySize
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_else
begin_block
unit|} else
block|{
name|ptr
operator|=
name|oldPtr
expr_stmt|;
return|return;
block|}
end_block
begin_expr_stmt
unit|}     s
operator|=
name|copySize
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
condition|)
block|{
comment|// destroy remaining old objects
while|while
condition|(
name|osize
operator|>
name|asize
condition|)
operator|(
name|oldPtr
operator|+
operator|(
operator|--
name|osize
operator|)
operator|)
operator|->
operator|~
name|T
argument_list|()
expr_stmt|;
block|}
end_if
begin_if
if|if
condition|(
name|oldPtr
operator|!=
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|array
operator|)
operator|&&
name|oldPtr
operator|!=
name|ptr
condition|)
name|free
argument_list|(
name|oldPtr
argument_list|)
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
condition|)
block|{
comment|// call default constructor for new objects (which can throw)
while|while
condition|(
name|s
operator|<
name|asize
condition|)
name|new
argument_list|(
argument|ptr+(s++)
argument_list|)
name|T
expr_stmt|;
block|}
else|else
block|{
name|s
operator|=
name|asize
expr_stmt|;
block|}
end_if
begin_expr_stmt
unit|}  template
DECL|variable|T
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|value
name|Q_OUTOFLINE_TEMPLATE
name|T
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|value
argument_list|(
argument|int i
argument_list|)
specifier|const
block|{
if|if
condition|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>=
name|size
argument_list|()
condition|)
block|{
return|return
name|T
argument_list|()
return|;
block|}
end_expr_stmt
begin_return
return|return
name|at
argument_list|(
name|i
argument_list|)
return|;
end_return
begin_expr_stmt
unit|} template
DECL|variable|T
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|value
name|Q_OUTOFLINE_TEMPLATE
name|T
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|value
argument_list|(
argument|int i
argument_list|,
argument|const T&defaultValue
argument_list|)
specifier|const
block|{
return|return
operator|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>=
name|size
argument_list|()
operator|)
operator|?
name|defaultValue
operator|:
name|at
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|insert
specifier|inline
name|void
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|insert
argument_list|(
argument|int i
argument_list|,
argument|const T&t
argument_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<=
name|s
argument_list|,
literal|"QVarLengthArray::insert"
argument_list|,
literal|"index out of range"
argument_list|)
block|;
name|insert
argument_list|(
name|begin
argument_list|()
operator|+
name|i
argument_list|,
literal|1
argument_list|,
name|t
argument_list|)
block|; }
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|insert
specifier|inline
name|void
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|insert
argument_list|(
argument|int i
argument_list|,
argument|int n
argument_list|,
argument|const T&t
argument_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<=
name|s
argument_list|,
literal|"QVarLengthArray::insert"
argument_list|,
literal|"index out of range"
argument_list|)
block|;
name|insert
argument_list|(
name|begin
argument_list|()
operator|+
name|i
argument_list|,
name|n
argument_list|,
name|t
argument_list|)
block|; }
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|remove
specifier|inline
name|void
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|remove
argument_list|(
argument|int i
argument_list|,
argument|int n
argument_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|n
operator|>=
literal|0
operator|&&
name|i
operator|+
name|n
operator|<=
name|s
argument_list|,
literal|"QVarLengthArray::remove"
argument_list|,
literal|"index out of range"
argument_list|)
block|;
name|erase
argument_list|(
name|begin
argument_list|()
operator|+
name|i
argument_list|,
name|begin
argument_list|()
operator|+
name|i
operator|+
name|n
argument_list|)
block|; }
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|remove
specifier|inline
name|void
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|remove
argument_list|(
argument|int i
argument_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<
name|s
argument_list|,
literal|"QVarLengthArray::remove"
argument_list|,
literal|"index out of range"
argument_list|)
block|;
name|erase
argument_list|(
name|begin
argument_list|()
operator|+
name|i
argument_list|,
name|begin
argument_list|()
operator|+
name|i
operator|+
literal|1
argument_list|)
block|; }
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|prepend
specifier|inline
name|void
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|prepend
argument_list|(
argument|const T&t
argument_list|)
block|{
name|insert
argument_list|(
name|begin
argument_list|()
argument_list|,
literal|1
argument_list|,
name|t
argument_list|)
block|; }
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|function|replace
specifier|inline
name|void
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|replace
argument_list|(
argument|int i
argument_list|,
argument|const T&t
argument_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<
name|s
argument_list|,
literal|"QVarLengthArray::replace"
argument_list|,
literal|"index out of range"
argument_list|)
block|;
specifier|const
name|T
name|copy
argument_list|(
name|t
argument_list|)
block|;
name|data
argument_list|()
index|[
name|i
index|]
operator|=
name|copy
block|; }
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|variable|T
DECL|function|insert
name|Q_OUTOFLINE_TEMPLATE
name|typename
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|iterator
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|insert
argument_list|(
argument|iterator before
argument_list|,
argument|size_type n
argument_list|,
argument|const T&t
argument_list|)
block|{
name|int
name|offset
operator|=
name|int
argument_list|(
name|before
operator|-
name|ptr
argument_list|)
block|;
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
name|resize
argument_list|(
name|s
operator|+
name|n
argument_list|)
expr_stmt|;
specifier|const
name|T
name|copy
parameter_list|(
name|t
parameter_list|)
function_decl|;
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isStatic
condition|)
block|{
name|T
modifier|*
name|b
init|=
name|ptr
operator|+
name|offset
decl_stmt|;
name|T
modifier|*
name|j
init|=
name|ptr
operator|+
name|s
decl_stmt|;
name|T
modifier|*
name|i
init|=
name|j
operator|-
name|n
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|b
condition|)
operator|*
operator|--
name|j
operator|=
operator|*
operator|--
name|i
expr_stmt|;
name|i
operator|=
name|b
operator|+
name|n
expr_stmt|;
while|while
condition|(
name|i
operator|!=
name|b
condition|)
operator|*
operator|--
name|i
operator|=
name|copy
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|T
modifier|*
name|b
init|=
name|ptr
operator|+
name|offset
decl_stmt|;
name|T
modifier|*
name|i
init|=
name|b
operator|+
name|n
decl_stmt|;
name|memmove
argument_list|(
name|i
argument_list|,
name|b
argument_list|,
operator|(
name|s
operator|-
name|offset
operator|-
name|n
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
name|i
operator|!=
name|b
condition|)
name|new
argument_list|(
argument|--i
argument_list|)
name|T
argument_list|(
name|copy
argument_list|)
expr_stmt|;
block|}
end_else
begin_expr_stmt
unit|}     return
name|ptr
operator|+
name|offset
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
DECL|variable|T
operator|<
name|class
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
DECL|variable|T
DECL|function|erase
name|Q_OUTOFLINE_TEMPLATE
name|typename
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|iterator
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
operator|::
name|erase
argument_list|(
argument|iterator abegin
argument_list|,
argument|iterator aend
argument_list|)
block|{
name|int
name|f
operator|=
name|int
argument_list|(
name|abegin
operator|-
name|ptr
argument_list|)
block|;
name|int
name|l
operator|=
name|int
argument_list|(
name|aend
operator|-
name|ptr
argument_list|)
block|;
name|int
name|n
operator|=
name|l
operator|-
name|f
block|;
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
condition|)
block|{
name|qCopy
argument_list|(
name|ptr
operator|+
name|l
argument_list|,
name|ptr
operator|+
name|s
argument_list|,
name|ptr
operator|+
name|f
argument_list|)
expr_stmt|;
name|T
modifier|*
name|i
init|=
name|ptr
operator|+
name|s
decl_stmt|;
name|T
modifier|*
name|b
init|=
name|ptr
operator|+
name|s
operator|-
name|n
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|b
condition|)
block|{
operator|--
name|i
expr_stmt|;
name|i
operator|->
expr|~
name|T
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_block
unit|} else
block|{
name|memmove
argument_list|(
name|ptr
operator|+
name|f
argument_list|,
name|ptr
operator|+
name|l
argument_list|,
operator|(
name|s
operator|-
name|l
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block
begin_expr_stmt
name|s
operator|-=
name|n
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|ptr
operator|+
name|f
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|variable|T
DECL|variable|Prealloc1
operator|<
name|typename
name|T
operator|,
name|int
name|Prealloc1
operator|,
name|int
name|Prealloc2
operator|>
DECL|function|operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc1
operator|>
operator|&
name|l
operator|,
specifier|const
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc2
operator|>
operator|&
name|r
operator|)
block|{
if|if
condition|(
name|l
operator|.
name|size
argument_list|()
operator|!=
name|r
operator|.
name|size
argument_list|()
condition|)
return|return
name|false
return|;
end_expr_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|l
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|l
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|!=
name|r
operator|.
name|at
argument_list|(
name|i
argument_list|)
condition|)
return|return
name|false
return|;
block|}
end_for
begin_return
return|return
name|true
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|variable|T
DECL|variable|Prealloc1
operator|<
name|typename
name|T
operator|,
name|int
name|Prealloc1
operator|,
name|int
name|Prealloc2
operator|>
DECL|function|operator
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc1
operator|>
operator|&
name|l
operator|,
specifier|const
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc2
operator|>
operator|&
name|r
operator|)
block|{
return|return
operator|!
operator|(
name|l
operator|==
name|r
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QVARLENGTHARRAY_H
end_comment
end_unit
