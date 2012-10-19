begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCONTIGUOUSCACHE_H
end_ifndef
begin_define
DECL|macro|QCONTIGUOUSCACHE_H
define|#
directive|define
name|QCONTIGUOUSCACHE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|<new>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|macro|QT_QCONTIGUOUSCACHE_DEBUG
undef|#
directive|undef
name|QT_QCONTIGUOUSCACHE_DEBUG
expr|struct
DECL|struct|QContiguousCacheData
name|Q_CORE_EXPORT
name|QContiguousCacheData
block|{
DECL|member|ref
name|QBasicAtomicInt
name|ref
block|;
DECL|member|alloc
name|int
name|alloc
block|;
DECL|member|count
name|int
name|count
block|;
DECL|member|start
name|int
name|start
block|;
DECL|member|offset
name|int
name|offset
block|;
DECL|member|sharable
name|uint
name|sharable
operator|:
literal|1
block|;
DECL|member|reserved
name|uint
name|reserved
operator|:
literal|31
block|;
comment|// total is 24 bytes (HP-UX aCC: 40 bytes)
comment|// the next entry is already aligned to 8 bytes
comment|// there will be an 8 byte gap here if T requires 16-byte alignment
comment|//  (such as long double on 64-bit platforms, __int128, __float128)
specifier|static
name|QContiguousCacheData
operator|*
name|allocateData
argument_list|(
argument|int size
argument_list|,
argument|int alignment
argument_list|)
block|;
specifier|static
name|void
name|freeData
argument_list|(
name|QContiguousCacheData
operator|*
name|data
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT_QCONTIGUOUSCACHE_DEBUG
name|void
name|dump
argument_list|()
specifier|const
block|;
endif|#
directive|endif
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|QContiguousCacheData
name|QContiguousCacheTypedData
operator|:
name|private
name|QContiguousCacheData
block|{
comment|// private inheritance to avoid aliasing warningss
DECL|member|array
name|T
name|array
index|[
literal|1
index|]
block|;
DECL|function|freeData
specifier|static
specifier|inline
name|void
name|freeData
argument_list|(
argument|QContiguousCacheTypedData *data
argument_list|)
block|{
name|QContiguousCacheData
operator|::
name|freeData
argument_list|(
name|data
argument_list|)
block|; }
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QContiguousCache
block|{
typedef|typedef
name|QContiguousCacheTypedData
operator|<
name|T
operator|>
name|Data
expr_stmt|;
block|union
block|{
name|QContiguousCacheData
operator|*
name|d
block|;
name|QContiguousCacheTypedData
operator|<
name|T
operator|>
operator|*
name|p
block|; }
expr_stmt|;
end_expr_stmt
begin_label
name|public
label|:
end_label
begin_comment
comment|// STL compatibility
end_comment
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
name|int
name|size_type
typedef|;
end_typedef
begin_function_decl
name|explicit
name|QContiguousCache
parameter_list|(
name|int
name|capacity
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QContiguousCache
argument_list|(
specifier|const
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|v
argument_list|)
operator|:
name|d
argument_list|(
argument|v.d
argument_list|)
block|{
name|d
operator|->
name|ref
operator|.
name|ref
argument_list|()
block|;
if|if
condition|(
operator|!
name|d
operator|->
name|sharable
condition|)
name|detach_helper
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
operator|~
name|QContiguousCache
argument_list|()
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|freeData
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_if
begin_function
unit|}      inline
name|void
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
name|detach_helper
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|bool
name|isDetached
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|==
literal|1
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|setSharable
parameter_list|(
name|bool
name|sharable
parameter_list|)
block|{
if|if
condition|(
operator|!
name|sharable
condition|)
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|sharable
operator|=
name|sharable
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|other
operator|)
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_expr_stmt
specifier|inline
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
name|QContiguousCache
operator|<
name|T
operator|>
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
specifier|inline
name|void
name|swap
argument_list|(
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|capacity
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|alloc
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
name|d
operator|->
name|count
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|count
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
name|d
operator|->
name|count
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isFull
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|count
operator|==
name|d
operator|->
name|alloc
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|available
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|alloc
operator|-
name|d
operator|->
name|count
return|;
block|}
end_expr_stmt
begin_function_decl
name|void
name|clear
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setCapacity
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|const
name|T
modifier|&
name|at
argument_list|(
name|int
name|pos
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|T
modifier|&
name|operator
function_decl|[]
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|const
name|T
modifier|&
name|operator
index|[]
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|append
parameter_list|(
specifier|const
name|T
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|prepend
parameter_list|(
specifier|const
name|T
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|insert
parameter_list|(
name|int
name|pos
parameter_list|,
specifier|const
name|T
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|inline
name|bool
name|containsIndex
argument_list|(
name|int
name|pos
argument_list|)
decl|const
block|{
return|return
name|pos
operator|>=
name|d
operator|->
name|offset
operator|&&
name|pos
operator|-
name|d
operator|->
name|offset
operator|<
name|d
operator|->
name|count
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|int
name|firstIndex
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|offset
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|lastIndex
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|offset
operator|+
name|d
operator|->
name|count
operator|-
literal|1
return|;
block|}
end_expr_stmt
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
name|p
operator|->
name|array
index|[
name|d
operator|->
name|start
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
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
name|p
operator|->
name|array
index|[
operator|(
name|d
operator|->
name|start
operator|+
name|d
operator|->
name|count
operator|-
literal|1
operator|)
operator|%
name|d
operator|->
name|alloc
index|]
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
name|detach
argument_list|()
expr_stmt|;
return|return
name|p
operator|->
name|array
index|[
name|d
operator|->
name|start
index|]
return|;
block|}
end_function
begin_function
specifier|inline
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
name|detach
argument_list|()
expr_stmt|;
return|return
name|p
operator|->
name|array
index|[
operator|(
name|d
operator|->
name|start
operator|+
name|d
operator|->
name|count
operator|-
literal|1
operator|)
operator|%
name|d
operator|->
name|alloc
index|]
return|;
block|}
end_function
begin_function_decl
name|void
name|removeFirst
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|T
name|takeFirst
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|removeLast
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|T
name|takeLast
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|bool
name|areIndexesValid
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|offset
operator|>=
literal|0
operator|&&
name|d
operator|->
name|offset
operator|<
name|INT_MAX
operator|-
name|d
operator|->
name|count
operator|&&
operator|(
name|d
operator|->
name|offset
operator|%
name|d
operator|->
name|alloc
operator|)
operator|==
name|d
operator|->
name|start
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|normalizeIndexes
parameter_list|()
block|{
name|d
operator|->
name|offset
operator|=
name|d
operator|->
name|start
expr_stmt|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_QCONTIGUOUSCACHE_DEBUG
end_ifdef
begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
block|{
name|p
operator|->
name|dump
argument_list|()
block|; }
endif|#
directive|endif
name|private
operator|:
name|void
name|detach_helper
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QContiguousCacheData
modifier|*
name|allocateData
parameter_list|(
name|int
name|aalloc
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|freeData
parameter_list|(
name|Data
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl
begin_function
name|int
name|sizeOfTypedData
parameter_list|()
block|{
comment|// this is more or less the same as sizeof(Data), except that it doesn't
comment|// count the padding at the end
return|return
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
operator|&
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|Data
operator|*
operator|>
operator|(
name|this
operator|)
operator|)
operator|->
name|array
index|[
literal|1
index|]
operator|)
operator|-
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
end_function
begin_expr_stmt
name|int
name|alignOfTypedData
argument_list|()
specifier|const
block|{
return|return
name|qMax
operator|<
name|int
operator|>
operator|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|Q_ALIGNOF
argument_list|(
name|Data
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|detach_helper
name|void
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|detach_helper
argument_list|()
block|{
expr|union
block|{
name|QContiguousCacheData
operator|*
name|d
block|;
name|QContiguousCacheTypedData
operator|<
name|T
operator|>
operator|*
name|p
block|; }
name|x
block|;
name|x
operator|.
name|d
operator|=
name|allocateData
argument_list|(
name|d
operator|->
name|alloc
argument_list|)
block|;
name|x
operator|.
name|d
operator|->
name|ref
operator|.
name|store
argument_list|(
literal|1
argument_list|)
block|;
name|x
operator|.
name|d
operator|->
name|count
operator|=
name|d
operator|->
name|count
block|;
name|x
operator|.
name|d
operator|->
name|start
operator|=
name|d
operator|->
name|start
block|;
name|x
operator|.
name|d
operator|->
name|offset
operator|=
name|d
operator|->
name|offset
block|;
name|x
operator|.
name|d
operator|->
name|alloc
operator|=
name|d
operator|->
name|alloc
block|;
name|x
operator|.
name|d
operator|->
name|sharable
operator|=
name|true
block|;
name|x
operator|.
name|d
operator|->
name|reserved
operator|=
literal|0
block|;
name|T
operator|*
name|dest
operator|=
name|x
operator|.
name|p
operator|->
name|array
operator|+
name|x
operator|.
name|d
operator|->
name|start
block|;
name|T
operator|*
name|src
operator|=
name|p
operator|->
name|array
operator|+
name|d
operator|->
name|start
block|;
name|int
name|oldcount
operator|=
name|x
operator|.
name|d
operator|->
name|count
block|;
while|while
condition|(
name|oldcount
operator|--
condition|)
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
name|new
argument_list|(
argument|dest
argument_list|)
name|T
argument_list|(
operator|*
name|src
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
operator|*
name|dest
operator|=
operator|*
name|src
expr_stmt|;
block|}
end_else
begin_expr_stmt
name|dest
operator|++
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|dest
operator|==
name|x
operator|.
name|p
operator|->
name|array
operator|+
name|x
operator|.
name|d
operator|->
name|alloc
condition|)
name|dest
operator|=
name|x
operator|.
name|p
operator|->
name|array
expr_stmt|;
end_if
begin_expr_stmt
name|src
operator|++
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|src
operator|==
name|p
operator|->
name|array
operator|+
name|d
operator|->
name|alloc
condition|)
name|src
operator|=
name|p
operator|->
name|array
expr_stmt|;
end_if
begin_expr_stmt
unit|}      if
operator|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
operator|)
name|freeData
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|d
operator|=
name|x
operator|.
name|d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|setCapacity
name|void
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|setCapacity
argument_list|(
argument|int asize
argument_list|)
block|{
if|if
condition|(
name|asize
operator|==
name|d
operator|->
name|alloc
condition|)
return|return;
name|detach
argument_list|()
expr_stmt|;
end_expr_stmt
begin_union
union|union
block|{
name|QContiguousCacheData
modifier|*
name|d
decl_stmt|;
name|QContiguousCacheTypedData
operator|<
name|T
operator|>
operator|*
name|p
expr_stmt|;
block|}
name|x
union|;
end_union
begin_expr_stmt
name|x
operator|.
name|d
operator|=
name|allocateData
argument_list|(
name|asize
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|x
operator|.
name|d
operator|->
name|alloc
operator|=
name|asize
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|x
operator|.
name|d
operator|->
name|count
operator|=
name|qMin
argument_list|(
name|d
operator|->
name|count
argument_list|,
name|asize
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|x
operator|.
name|d
operator|->
name|offset
operator|=
name|d
operator|->
name|offset
operator|+
name|d
operator|->
name|count
operator|-
name|x
operator|.
name|d
operator|->
name|count
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|asize
condition|)
name|x
operator|.
name|d
operator|->
name|start
operator|=
name|x
operator|.
name|d
operator|->
name|offset
operator|%
name|x
operator|.
name|d
operator|->
name|alloc
expr_stmt|;
else|else
name|x
operator|.
name|d
operator|->
name|start
operator|=
literal|0
expr_stmt|;
end_if
begin_decl_stmt
name|int
name|oldcount
init|=
name|x
operator|.
name|d
operator|->
name|count
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|oldcount
condition|)
block|{
name|T
modifier|*
name|dest
init|=
name|x
operator|.
name|p
operator|->
name|array
operator|+
operator|(
name|x
operator|.
name|d
operator|->
name|start
operator|+
name|x
operator|.
name|d
operator|->
name|count
operator|-
literal|1
operator|)
operator|%
name|x
operator|.
name|d
operator|->
name|alloc
decl_stmt|;
name|T
modifier|*
name|src
init|=
name|p
operator|->
name|array
operator|+
operator|(
name|d
operator|->
name|start
operator|+
name|d
operator|->
name|count
operator|-
literal|1
operator|)
operator|%
name|d
operator|->
name|alloc
decl_stmt|;
while|while
condition|(
name|oldcount
operator|--
condition|)
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
name|new
argument_list|(
argument|dest
argument_list|)
name|T
argument_list|(
operator|*
name|src
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|*
name|dest
operator|=
operator|*
name|src
expr_stmt|;
block|}
if|if
condition|(
name|dest
operator|==
name|x
operator|.
name|p
operator|->
name|array
condition|)
name|dest
operator|=
name|x
operator|.
name|p
operator|->
name|array
operator|+
name|x
operator|.
name|d
operator|->
name|alloc
expr_stmt|;
name|dest
operator|--
expr_stmt|;
if|if
condition|(
name|src
operator|==
name|p
operator|->
name|array
condition|)
name|src
operator|=
name|p
operator|->
name|array
operator|+
name|d
operator|->
name|alloc
expr_stmt|;
name|src
operator|--
expr_stmt|;
block|}
block|}
end_if
begin_comment
comment|/* free old */
end_comment
begin_expr_stmt
name|freeData
argument_list|(
name|p
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|d
operator|=
name|x
operator|.
name|d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|clear
name|void
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|clear
argument_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|==
literal|1
condition|)
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
name|int
name|oldcount
init|=
name|d
operator|->
name|count
decl_stmt|;
name|T
modifier|*
name|i
init|=
name|p
operator|->
name|array
operator|+
name|d
operator|->
name|start
decl_stmt|;
name|T
modifier|*
name|e
init|=
name|p
operator|->
name|array
operator|+
name|d
operator|->
name|alloc
decl_stmt|;
while|while
condition|(
name|oldcount
operator|--
condition|)
block|{
name|i
operator|->
expr|~
name|T
argument_list|()
expr_stmt|;
name|i
operator|++
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|e
condition|)
name|i
operator|=
name|p
operator|->
name|array
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}         d
operator|->
name|count
operator|=
name|d
operator|->
name|start
operator|=
name|d
operator|->
name|offset
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_block
unit|} else
block|{
union|union
block|{
name|QContiguousCacheData
modifier|*
name|d
decl_stmt|;
name|QContiguousCacheTypedData
operator|<
name|T
operator|>
operator|*
name|p
expr_stmt|;
block|}
name|x
union|;
name|x
operator|.
name|d
operator|=
name|allocateData
argument_list|(
name|d
operator|->
name|alloc
argument_list|)
expr_stmt|;
name|x
operator|.
name|d
operator|->
name|ref
operator|.
name|store
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|x
operator|.
name|d
operator|->
name|alloc
operator|=
name|d
operator|->
name|alloc
expr_stmt|;
name|x
operator|.
name|d
operator|->
name|count
operator|=
name|x
operator|.
name|d
operator|->
name|start
operator|=
name|x
operator|.
name|d
operator|->
name|offset
operator|=
literal|0
expr_stmt|;
name|x
operator|.
name|d
operator|->
name|sharable
operator|=
name|true
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|freeData
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|d
operator|=
name|x
operator|.
name|d
expr_stmt|;
block|}
end_block
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|allocateData
specifier|inline
name|QContiguousCacheData
operator|*
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|allocateData
argument_list|(
argument|int aalloc
argument_list|)
block|{
return|return
name|QContiguousCacheData
operator|::
name|allocateData
argument_list|(
name|sizeOfTypedData
argument_list|()
operator|+
operator|(
name|aalloc
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|alignOfTypedData
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|QContiguousCache
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|QContiguousCache
argument_list|(
argument|int cap
argument_list|)
block|{
name|d
operator|=
name|allocateData
argument_list|(
name|cap
argument_list|)
block|;
name|d
operator|->
name|ref
operator|.
name|store
argument_list|(
literal|1
argument_list|)
block|;
name|d
operator|->
name|alloc
operator|=
name|cap
block|;
name|d
operator|->
name|count
operator|=
name|d
operator|->
name|start
operator|=
name|d
operator|->
name|offset
operator|=
literal|0
block|;
name|d
operator|->
name|sharable
operator|=
name|true
block|; }
name|template
operator|<
name|typename
name|T
operator|>
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|operator
operator|=
operator|(
specifier|const
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|{
name|other
operator|.
name|d
operator|->
name|ref
operator|.
name|ref
argument_list|()
block|;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|freeData
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|d
operator|->
name|sharable
condition|)
name|detach_helper
argument_list|()
expr_stmt|;
end_if
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|bool
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|operator
operator|==
operator|(
specifier|const
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
if|if
condition|(
name|other
operator|.
name|d
operator|==
name|d
condition|)
return|return
name|true
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|other
operator|.
name|d
operator|->
name|start
operator|!=
name|d
operator|->
name|start
operator|||
name|other
operator|.
name|d
operator|->
name|count
operator|!=
name|d
operator|->
name|count
operator|||
name|other
operator|.
name|d
operator|->
name|offset
operator|!=
name|d
operator|->
name|offset
operator|||
name|other
operator|.
name|d
operator|->
name|alloc
operator|!=
name|d
operator|->
name|alloc
condition|)
return|return
name|false
return|;
end_if
begin_for
for|for
control|(
name|int
name|i
init|=
name|firstIndex
argument_list|()
init|;
name|i
operator|<=
name|lastIndex
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
operator|!
operator|(
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|other
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|)
condition|)
return|return
name|false
return|;
end_for
begin_return
return|return
name|true
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|void
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|freeData
argument_list|(
argument|Data *x
argument_list|)
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
name|int
name|oldcount
init|=
name|d
operator|->
name|count
decl_stmt|;
name|T
modifier|*
name|i
init|=
name|p
operator|->
name|array
operator|+
name|d
operator|->
name|start
decl_stmt|;
name|T
modifier|*
name|e
init|=
name|p
operator|->
name|array
operator|+
name|d
operator|->
name|alloc
decl_stmt|;
while|while
condition|(
name|oldcount
operator|--
condition|)
block|{
name|i
operator|->
expr|~
name|T
argument_list|()
expr_stmt|;
name|i
operator|++
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|e
condition|)
name|i
operator|=
name|p
operator|->
name|array
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}     x
operator|->
name|freeData
argument_list|(
name|x
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|} template
operator|<
name|typename
name|T
operator|>
name|void
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|append
argument_list|(
argument|const T&value
argument_list|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|alloc
condition|)
return|return;
comment|// zero capacity
name|detach
argument_list|()
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
if|if
condition|(
name|d
operator|->
name|count
operator|==
name|d
operator|->
name|alloc
condition|)
operator|(
name|p
operator|->
name|array
operator|+
operator|(
name|d
operator|->
name|start
operator|+
name|d
operator|->
name|count
operator|)
operator|%
name|d
operator|->
name|alloc
operator|)
operator|->
operator|~
name|T
argument_list|()
expr_stmt|;
name|new
argument_list|(
argument|p->array + (d->start+d->count) % d->alloc
argument_list|)
name|T
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|p
operator|->
name|array
index|[
operator|(
name|d
operator|->
name|start
operator|+
name|d
operator|->
name|count
operator|)
operator|%
name|d
operator|->
name|alloc
index|]
operator|=
name|value
expr_stmt|;
block|}
end_if
begin_if
if|if
condition|(
name|d
operator|->
name|count
operator|==
name|d
operator|->
name|alloc
condition|)
block|{
name|d
operator|->
name|start
operator|++
expr_stmt|;
name|d
operator|->
name|start
operator|%=
name|d
operator|->
name|alloc
expr_stmt|;
name|d
operator|->
name|offset
operator|++
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|count
operator|++
expr_stmt|;
block|}
end_if
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|void
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|prepend
argument_list|(
argument|const T&value
argument_list|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|alloc
condition|)
return|return;
comment|// zero capacity
name|detach
argument_list|()
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|d
operator|->
name|start
condition|)
name|d
operator|->
name|start
operator|--
expr_stmt|;
else|else
name|d
operator|->
name|start
operator|=
name|d
operator|->
name|alloc
operator|-
literal|1
expr_stmt|;
end_if
begin_expr_stmt
name|d
operator|->
name|offset
operator|--
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|d
operator|->
name|count
operator|!=
name|d
operator|->
name|alloc
condition|)
name|d
operator|->
name|count
operator|++
expr_stmt|;
elseif|else
if|if
condition|(
name|d
operator|->
name|count
operator|==
name|d
operator|->
name|alloc
condition|)
operator|(
name|p
operator|->
name|array
operator|+
name|d
operator|->
name|start
operator|)
operator|->
operator|~
name|T
argument_list|()
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
name|new
argument_list|(
argument|p->array + d->start
argument_list|)
name|T
argument_list|(
name|value
argument_list|)
expr_stmt|;
else|else
name|p
operator|->
name|array
index|[
name|d
operator|->
name|start
index|]
operator|=
name|value
expr_stmt|;
end_if
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|void
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|insert
argument_list|(
argument|int pos
argument_list|,
argument|const T&value
argument_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|pos
operator|>=
literal|0
operator|&&
name|pos
operator|<
name|INT_MAX
argument_list|,
literal|"QContiguousCache<T>::insert"
argument_list|,
literal|"index out of range"
argument_list|)
block|;
if|if
condition|(
operator|!
name|d
operator|->
name|alloc
condition|)
return|return;
comment|// zero capacity
name|detach
argument_list|()
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|containsIndex
argument_list|(
name|pos
argument_list|)
condition|)
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
operator|(
name|p
operator|->
name|array
operator|+
name|pos
operator|%
name|d
operator|->
name|alloc
operator|)
operator|->
operator|~
name|T
argument_list|()
expr_stmt|;
name|new
argument_list|(
argument|p->array + pos % d->alloc
argument_list|)
name|T
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|p
operator|->
name|array
index|[
name|pos
operator|%
name|d
operator|->
name|alloc
index|]
operator|=
name|value
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|pos
operator|==
name|d
operator|->
name|offset
operator|-
literal|1
condition|)
name|prepend
argument_list|(
name|value
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|pos
operator|==
name|d
operator|->
name|offset
operator|+
name|d
operator|->
name|count
condition|)
name|append
argument_list|(
name|value
argument_list|)
expr_stmt|;
else|else
block|{
comment|// we don't leave gaps.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|offset
operator|=
name|pos
expr_stmt|;
name|d
operator|->
name|start
operator|=
name|pos
operator|%
name|d
operator|->
name|alloc
expr_stmt|;
name|d
operator|->
name|count
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
condition|)
name|new
argument_list|(
argument|p->array + d->start
argument_list|)
name|T
argument_list|(
name|value
argument_list|)
expr_stmt|;
else|else
name|p
operator|->
name|array
index|[
name|d
operator|->
name|start
index|]
operator|=
name|value
expr_stmt|;
block|}
end_if
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
specifier|inline
specifier|const
name|T
operator|&
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|at
argument_list|(
argument|int pos
argument_list|)
specifier|const
block|{
name|Q_ASSERT_X
argument_list|(
name|pos
operator|>=
name|d
operator|->
name|offset
operator|&&
name|pos
operator|-
name|d
operator|->
name|offset
operator|<
name|d
operator|->
name|count
argument_list|,
literal|"QContiguousCache<T>::at"
argument_list|,
literal|"index out of range"
argument_list|)
block|;
return|return
name|p
operator|->
name|array
index|[
name|pos
operator|%
name|d
operator|->
name|alloc
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
specifier|const
name|T
operator|&
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|operator
index|[]
operator|(
name|int
name|pos
operator|)
specifier|const
block|{
name|Q_ASSERT_X
argument_list|(
name|pos
operator|>=
name|d
operator|->
name|offset
operator|&&
name|pos
operator|-
name|d
operator|->
name|offset
operator|<
name|d
operator|->
name|count
argument_list|,
literal|"QContiguousCache<T>::at"
argument_list|,
literal|"index out of range"
argument_list|)
block|;
return|return
name|p
operator|->
name|array
index|[
name|pos
operator|%
name|d
operator|->
name|alloc
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
operator|&
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|operator
index|[]
operator|(
name|int
name|pos
operator|)
block|{
name|detach
argument_list|()
block|;
if|if
condition|(
operator|!
name|containsIndex
argument_list|(
name|pos
argument_list|)
condition|)
name|insert
argument_list|(
name|pos
argument_list|,
name|T
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|p
operator|->
name|array
index|[
name|pos
operator|%
name|d
operator|->
name|alloc
index|]
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|removeFirst
argument_list|()
block|{
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|count
operator|>
literal|0
argument_list|)
block|;
name|detach
argument_list|()
block|;
name|d
operator|->
name|count
operator|--
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
operator|(
name|p
operator|->
name|array
operator|+
name|d
operator|->
name|start
operator|)
operator|->
operator|~
name|T
argument_list|()
expr_stmt|;
name|d
operator|->
name|start
operator|=
operator|(
name|d
operator|->
name|start
operator|+
literal|1
operator|)
operator|%
name|d
operator|->
name|alloc
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|d
operator|->
name|offset
operator|++
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|removeLast
argument_list|()
block|{
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|count
operator|>
literal|0
argument_list|)
block|;
name|detach
argument_list|()
block|;
name|d
operator|->
name|count
operator|--
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
operator|(
name|p
operator|->
name|array
operator|+
operator|(
name|d
operator|->
name|start
operator|+
name|d
operator|->
name|count
operator|)
operator|%
name|d
operator|->
name|alloc
operator|)
operator|->
operator|~
name|T
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|takeFirst
argument_list|()
block|{
name|T
name|t
operator|=
name|first
argument_list|()
block|;
name|removeFirst
argument_list|()
block|;
return|return
name|t
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|QContiguousCache
operator|<
name|T
operator|>
operator|::
name|takeLast
argument_list|()
block|{
name|T
name|t
operator|=
name|last
argument_list|()
block|;
name|removeLast
argument_list|()
block|;
return|return
name|t
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
end_unit
