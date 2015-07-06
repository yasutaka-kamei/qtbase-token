begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QARRAYDATA_H
end_ifndef
begin_define
DECL|macro|QARRAYDATA_H
define|#
directive|define
name|QARRAYDATA_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qrefcount.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QArrayData
struct|struct
name|Q_CORE_EXPORT
name|QArrayData
block|{
DECL|member|ref
name|QtPrivate
operator|::
name|RefCount
name|ref
expr_stmt|;
DECL|member|size
name|int
name|size
decl_stmt|;
DECL|member|alloc
name|uint
name|alloc
range|:
literal|31
decl_stmt|;
DECL|member|capacityReserved
name|uint
name|capacityReserved
range|:
literal|1
decl_stmt|;
DECL|member|offset
name|qptrdiff
name|offset
decl_stmt|;
comment|// in bytes from beginning of header
DECL|function|data
name|void
modifier|*
name|data
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|size
operator|==
literal|0
operator|||
name|offset
operator|<
literal|0
operator|||
name|size_t
argument_list|(
name|offset
argument_list|)
operator|>=
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
name|offset
return|;
block|}
DECL|function|data
specifier|const
name|void
operator|*
name|data
argument_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|size
operator|==
literal|0
operator|||
name|offset
operator|<
literal|0
operator|||
name|size_t
argument_list|(
name|offset
argument_list|)
operator|>=
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|this
operator|)
operator|+
name|offset
return|;
block|}
comment|// This refers to array data mutability, not "header data" represented by
comment|// data members in QArrayData. Shared data (array and header) must still
comment|// follow COW principles.
DECL|function|isMutable
name|bool
name|isMutable
argument_list|()
specifier|const
block|{
return|return
name|alloc
operator|!=
literal|0
return|;
block|}
DECL|enum|AllocationOption
enum|enum
name|AllocationOption
block|{
DECL|enumerator|CapacityReserved
name|CapacityReserved
init|=
literal|0x1
block|,
if|#
directive|if
name|QT_SUPPORTS
argument_list|(
name|UNSHARABLE_CONTAINERS
argument_list|)
DECL|enumerator|Unsharable
name|Unsharable
init|=
literal|0x2
block|,
endif|#
directive|endif
DECL|enumerator|RawData
name|RawData
init|=
literal|0x4
block|,
DECL|enumerator|Grow
name|Grow
init|=
literal|0x8
block|,
DECL|enumerator|Default
name|Default
init|=
literal|0
block|}
enum|;
DECL|function|Q_DECLARE_FLAGS
name|Q_DECLARE_FLAGS
argument_list|(
argument|AllocationOptions
argument_list|,
argument|AllocationOption
argument_list|)
name|size_t
name|detachCapacity
argument_list|(
name|size_t
name|newSize
argument_list|)
decl|const
block|{
if|if
condition|(
name|capacityReserved
operator|&&
name|newSize
operator|<
name|alloc
condition|)
return|return
name|alloc
return|;
return|return
name|newSize
return|;
block|}
DECL|function|detachFlags
name|AllocationOptions
name|detachFlags
argument_list|()
specifier|const
block|{
name|AllocationOptions
name|result
block|;
if|if
condition|(
name|capacityReserved
condition|)
name|result
operator||=
name|CapacityReserved
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|cloneFlags
name|AllocationOptions
name|cloneFlags
argument_list|()
decl|const
block|{
name|AllocationOptions
name|result
decl_stmt|;
if|if
condition|(
name|capacityReserved
condition|)
name|result
operator||=
name|CapacityReserved
expr_stmt|;
return|return
name|result
return|;
block|}
decl|static
name|QArrayData
modifier|*
name|allocate
argument_list|(
name|size_t
name|objectSize
argument_list|,
name|size_t
name|alignment
argument_list|,
name|size_t
name|capacity
argument_list|,
name|AllocationOptions
name|options
operator|=
name|Default
argument_list|)
DECL|member|Q_REQUIRED_RESULT
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
struct|;
end_struct
begin_decl_stmt
specifier|static
name|void
name|deallocate
argument_list|(
name|QArrayData
operator|*
name|data
argument_list|,
name|size_t
name|objectSize
argument_list|,
DECL|member|Q_DECL_NOTHROW
name|size_t
name|alignment
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|shared_null
specifier|static
specifier|const
name|QArrayData
name|shared_null
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt
begin_function
specifier|static
name|QArrayData
modifier|*
name|sharedNull
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|const_cast
operator|<
name|QArrayData
operator|*
operator|>
operator|(
name|shared_null
operator|)
return|;
block|}
end_function
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QArrayData::AllocationOptions
argument_list|)
end_macro
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|QTypedArrayData
DECL|struct|QArrayData
operator|:
name|QArrayData
block|{
ifdef|#
directive|ifdef
name|QT_STRICT_ITERATORS
name|class
name|iterator
block|{
name|public
operator|:
name|T
operator|*
name|i
block|;
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
end_expr_stmt
begin_typedef
typedef|typedef
name|T
name|value_type
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|T
modifier|*
name|pointer
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|T
modifier|&
name|reference
typedef|;
end_typedef
begin_expr_stmt
specifier|inline
name|iterator
argument_list|()
operator|:
name|i
argument_list|(
argument|Q_NULLPTR
argument_list|)
block|{}
specifier|inline
name|iterator
argument_list|(
name|T
operator|*
name|n
argument_list|)
operator|:
name|i
argument_list|(
argument|n
argument_list|)
block|{}
specifier|inline
name|iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|o
argument_list|)
operator|:
name|i
argument_list|(
argument|o.i
argument_list|)
block|{}
comment|// #### Qt 6: remove, the implicit version is fine
specifier|inline
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|T
operator|*
name|operator
operator|->
expr|(
end_expr_stmt
begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|i
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|T
modifier|&
name|operator
index|[]
argument_list|(
name|int
name|j
argument_list|)
decl|const
block|{
return|return
operator|*
operator|(
name|i
operator|+
name|j
operator|)
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
name|T
operator|*
name|n
operator|=
name|i
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
name|T
operator|*
name|n
operator|=
name|i
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
begin_expr_stmt
specifier|inline
name|operator
name|T
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|i
return|;
block|}
end_expr_stmt
begin_decl_stmt
unit|};
DECL|member|iterator
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
name|T
modifier|*
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
name|T
name|value_type
typedef|;
typedef|typedef
specifier|const
name|T
modifier|*
name|pointer
typedef|;
typedef|typedef
specifier|const
name|T
modifier|&
name|reference
typedef|;
specifier|inline
name|const_iterator
argument_list|()
operator|:
name|i
argument_list|(
argument|Q_NULLPTR
argument_list|)
block|{}
specifier|inline
name|const_iterator
argument_list|(
specifier|const
name|T
operator|*
name|n
argument_list|)
operator|:
name|i
argument_list|(
argument|n
argument_list|)
block|{}
specifier|inline
name|const_iterator
argument_list|(
specifier|const
name|const_iterator
operator|&
name|o
argument_list|)
operator|:
name|i
argument_list|(
argument|o.i
argument_list|)
block|{}
comment|// #### Qt 6: remove, the default version is fine
specifier|inline
name|explicit
name|const_iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|o
argument_list|)
operator|:
name|i
argument_list|(
argument|o.i
argument_list|)
block|{}
specifier|inline
specifier|const
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|i
return|;
block|}
specifier|inline
specifier|const
name|T
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|i
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
specifier|const
name|T
modifier|&
name|operator
index|[]
argument_list|(
name|int
name|j
argument_list|)
decl|const
block|{
return|return
operator|*
operator|(
name|i
operator|+
name|j
operator|)
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
specifier|const
name|T
operator|*
name|n
operator|=
name|i
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
specifier|const
name|T
operator|*
name|n
operator|=
name|i
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
begin_expr_stmt
specifier|inline
name|operator
specifier|const
name|T
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|i
return|;
block|}
end_expr_stmt
begin_decl_stmt
unit|};
DECL|member|const_iterator
name|friend
name|class
name|const_iterator
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
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
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|data
name|T
modifier|*
name|data
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|QArrayData
operator|::
name|data
argument_list|()
operator|)
return|;
block|}
end_function
begin_expr_stmt
DECL|function|data
specifier|const
name|T
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|QArrayData
operator|::
name|data
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|begin
name|iterator
name|begin
parameter_list|(
name|iterator
init|=
name|iterator
argument_list|()
parameter_list|)
block|{
return|return
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|end
name|iterator
name|end
parameter_list|(
name|iterator
init|=
name|iterator
argument_list|()
parameter_list|)
block|{
return|return
name|data
argument_list|()
operator|+
name|size
return|;
block|}
end_function
begin_decl_stmt
DECL|function|begin
name|const_iterator
name|begin
argument_list|(
name|const_iterator
operator|=
name|const_iterator
argument_list|()
argument_list|)
decl|const
block|{
return|return
name|data
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|end
name|const_iterator
name|end
argument_list|(
name|const_iterator
operator|=
name|const_iterator
argument_list|()
argument_list|)
decl|const
block|{
return|return
name|data
argument_list|()
operator|+
name|size
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|constBegin
name|const_iterator
name|constBegin
argument_list|(
name|const_iterator
operator|=
name|const_iterator
argument_list|()
argument_list|)
decl|const
block|{
return|return
name|data
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|constEnd
name|const_iterator
name|constEnd
argument_list|(
name|const_iterator
operator|=
name|const_iterator
argument_list|()
argument_list|)
decl|const
block|{
return|return
name|data
argument_list|()
operator|+
name|size
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|class
name|AlignmentDummy
block|{
name|QArrayData
name|header
decl_stmt|;
name|T
name|data
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function
specifier|static
name|QTypedArrayData
modifier|*
name|allocate
parameter_list|(
name|size_t
name|capacity
parameter_list|,
name|AllocationOptions
name|options
init|=
name|Default
parameter_list|)
function|Q_REQUIRED_RESULT
block|{
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QTypedArrayData
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|QTypedArrayData
operator|*
operator|>
operator|(
name|QArrayData
operator|::
name|allocate
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|AlignmentDummy
argument_list|)
argument_list|,
name|capacity
argument_list|,
name|options
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|deallocate
specifier|static
name|void
name|deallocate
parameter_list|(
name|QArrayData
modifier|*
name|data
parameter_list|)
block|{
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QTypedArrayData
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
argument_list|)
expr_stmt|;
name|QArrayData
operator|::
name|deallocate
argument_list|(
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|Q_ALIGNOF
argument_list|(
name|AlignmentDummy
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromRawData
specifier|static
name|QTypedArrayData
modifier|*
name|fromRawData
parameter_list|(
specifier|const
name|T
modifier|*
name|data
parameter_list|,
name|size_t
name|n
parameter_list|,
name|AllocationOptions
name|options
init|=
name|Default
parameter_list|)
block|{
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QTypedArrayData
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
argument_list|)
expr_stmt|;
name|QTypedArrayData
modifier|*
name|result
init|=
name|allocate
argument_list|(
literal|0
argument_list|,
name|options
operator||
name|RawData
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
condition|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|result
operator|->
name|ref
operator|.
name|isShared
argument_list|()
argument_list|)
expr_stmt|;
comment|// No shared empty, please!
name|result
operator|->
name|offset
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|data
operator|)
operator|-
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|result
operator|)
expr_stmt|;
name|result
operator|->
name|size
operator|=
name|int
argument_list|(
name|n
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
specifier|static
name|QTypedArrayData
modifier|*
name|sharedNull
parameter_list|()
function|Q_DECL_NOTHROW
block|{
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QTypedArrayData
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|QTypedArrayData
operator|*
operator|>
operator|(
name|QArrayData
operator|::
name|sharedNull
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|sharedEmpty
specifier|static
name|QTypedArrayData
modifier|*
name|sharedEmpty
parameter_list|()
block|{
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QTypedArrayData
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|allocate
argument_list|(
comment|/* capacity */
literal|0
argument_list|)
return|;
block|}
end_function
begin_if
if|#
directive|if
name|QT_SUPPORTS
argument_list|(
name|UNSHARABLE_CONTAINERS
argument_list|)
end_if
begin_function
DECL|function|unsharableEmpty
specifier|static
name|QTypedArrayData
modifier|*
name|unsharableEmpty
parameter_list|()
block|{
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QTypedArrayData
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|allocate
argument_list|(
comment|/* capacity */
literal|0
argument_list|,
name|Unsharable
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|};
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|size_t
name|N
operator|>
expr|struct
DECL|struct|QStaticArrayData
name|QStaticArrayData
block|{
DECL|member|header
name|QArrayData
name|header
block|;
DECL|member|data
name|T
name|data
index|[
name|N
index|]
block|; }
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Support for returning QArrayDataPointer<T> from functions
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
DECL|struct|QArrayDataPointerRef
name|QArrayDataPointerRef
block|{
DECL|member|ptr
name|QTypedArrayData
operator|<
name|T
operator|>
operator|*
name|ptr
block|; }
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|Q_STATIC_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET
define|#
directive|define
name|Q_STATIC_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET
parameter_list|(
name|size
parameter_list|,
name|offset
parameter_list|)
define|\
value|{ Q_REFCOUNT_INITIALIZE_STATIC, size, 0, 0, offset }
end_define
begin_comment
unit|\
comment|/**/
end_comment
begin_define
DECL|macro|Q_STATIC_ARRAY_DATA_HEADER_INITIALIZER
define|#
directive|define
name|Q_STATIC_ARRAY_DATA_HEADER_INITIALIZER
parameter_list|(
name|type
parameter_list|,
name|size
parameter_list|)
define|\
value|Q_STATIC_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(size,\         ((sizeof(QArrayData) + (Q_ALIGNOF(type) - 1))& ~(Q_ALIGNOF(type) - 1) ))
end_define
begin_comment
unit|\
comment|/**/
end_comment
begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment
begin_comment
comment|//  Q_ARRAY_LITERAL
end_comment
begin_comment
comment|// The idea here is to place a (read-only) copy of header and array data in an
end_comment
begin_comment
comment|// mmappable portion of the executable (typically, .rodata section). This is
end_comment
begin_comment
comment|// accomplished by hiding a static const instance of QStaticArrayData, which is
end_comment
begin_comment
comment|// POD.
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_VARIADIC_MACROS
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_LAMBDA
argument_list|)
end_if
begin_comment
comment|// Hide array inside a lambda
end_comment
begin_define
DECL|macro|Q_ARRAY_LITERAL
define|#
directive|define
name|Q_ARRAY_LITERAL
parameter_list|(
name|Type
parameter_list|,
modifier|...
parameter_list|)
define|\
value|([]() -> QArrayDataPointerRef<Type> {                                       \
comment|/* MSVC 2010 Doesn't support static variables in a lambda, but */
value|\
comment|/* happily accepts them in a static function of a lambda-local */
value|\
comment|/* struct :-) */
value|\             struct StaticWrapper {                                              \                 static QArrayDataPointerRef<Type> get()                         \                 {                                                               \                     Q_ARRAY_LITERAL_IMPL(Type, __VA_ARGS__)                     \                     return ref;                                                 \                 }                                                               \             };                                                                  \             return StaticWrapper::get();                                        \         }())
end_define
begin_comment
unit|\
comment|/**/
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// defined(Q_COMPILER_VARIADIC_MACROS)
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_ARRAY_LITERAL
argument_list|)
end_if
begin_define
DECL|macro|Q_ARRAY_LITERAL_IMPL
define|#
directive|define
name|Q_ARRAY_LITERAL_IMPL
parameter_list|(
name|Type
parameter_list|,
modifier|...
parameter_list|)
define|\
value|union { Type type_must_be_POD; } dummy; Q_UNUSED(dummy)                     \                                                                                 \
comment|/* Portable compile-time array size computation */
value|\     Type data[] = { __VA_ARGS__ }; Q_UNUSED(data)                               \     enum { Size = sizeof(data) / sizeof(data[0]) };                             \                                                                                 \     static const QStaticArrayData<Type, Size> literal = {                       \         Q_STATIC_ARRAY_DATA_HEADER_INITIALIZER(Type, Size), { __VA_ARGS__ } };  \                                                                                 \     QArrayDataPointerRef<Type> ref =                                            \         { static_cast<QTypedArrayData<Type> *>(                                 \             const_cast<QArrayData *>(&literal.header)) };
end_define
begin_comment
unit|\
comment|/**/
end_comment
begin_else
else|#
directive|else
end_else
begin_comment
comment|// As a fallback, memory is allocated and data copied to the heap.
end_comment
begin_comment
comment|// The fallback macro does NOT use variadic macros and does NOT support
end_comment
begin_comment
comment|// variable number of arguments. It is suitable for char arrays.
end_comment
begin_decl_stmt
name|namespace
name|QtPrivate
block|{
name|template
operator|<
name|class
name|T
operator|,
name|size_t
name|N
operator|>
specifier|inline
name|QArrayDataPointerRef
operator|<
name|T
operator|>
name|qMakeArrayLiteral
argument_list|(
argument|const T (&array)[N]
argument_list|)
block|{
expr|union
block|{
name|T
name|type_must_be_POD
block|; }
name|dummy
block|;
name|Q_UNUSED
argument_list|(
argument|dummy
argument_list|)
name|QArrayDataPointerRef
operator|<
name|T
operator|>
name|result
operator|=
block|{
name|QTypedArrayData
operator|<
name|T
operator|>
operator|::
name|allocate
argument_list|(
argument|N
argument_list|)
block|}
block|;
name|Q_CHECK_PTR
argument_list|(
name|result
operator|.
name|ptr
argument_list|)
block|;
operator|::
name|memcpy
argument_list|(
name|result
operator|.
name|ptr
operator|->
name|data
argument_list|()
argument_list|,
name|array
argument_list|,
name|N
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;
name|result
operator|.
name|ptr
operator|->
name|size
operator|=
name|N
block|;
return|return
name|result
return|;
block|}
block|}
end_decl_stmt
begin_define
DECL|macro|Q_ARRAY_LITERAL
define|#
directive|define
name|Q_ARRAY_LITERAL
parameter_list|(
name|Type
parameter_list|,
name|Array
parameter_list|)
define|\
value|QT_PREPEND_NAMESPACE(QtPrivate::qMakeArrayLiteral)<Type>( Array )
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !defined(Q_ARRAY_LITERAL)
end_comment
begin_decl_stmt
name|namespace
name|QtPrivate
block|{
struct|struct
name|Q_CORE_EXPORT
name|QContainerImplHelper
block|{
enum|enum
name|CutResult
block|{
name|Null
block|,
name|Empty
block|,
name|Full
block|,
name|Subset
block|}
enum|;
specifier|static
name|CutResult
name|mid
parameter_list|(
name|int
name|originalLength
parameter_list|,
name|int
modifier|*
name|position
parameter_list|,
name|int
modifier|*
name|length
parameter_list|)
function_decl|;
block|}
struct|;
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// include guard
end_comment
end_unit
