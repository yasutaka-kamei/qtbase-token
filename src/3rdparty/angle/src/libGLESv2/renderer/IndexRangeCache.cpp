begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// IndexRangeCache.cpp: Defines the rx::IndexRangeCache class which stores information about
end_comment
begin_comment
comment|// ranges of indices.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/IndexRangeCache.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/formatutils.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|<tuple>
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
template|template
parameter_list|<
name|class
name|IndexType
parameter_list|>
DECL|function|ComputeTypedRange
specifier|static
name|RangeUI
name|ComputeTypedRange
parameter_list|(
specifier|const
name|IndexType
modifier|*
name|indices
parameter_list|,
name|GLsizei
name|count
parameter_list|)
block|{
name|unsigned
name|int
name|minIndex
init|=
name|indices
index|[
literal|0
index|]
decl_stmt|;
name|unsigned
name|int
name|maxIndex
init|=
name|indices
index|[
literal|0
index|]
decl_stmt|;
for|for
control|(
name|GLsizei
name|i
init|=
literal|1
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|minIndex
operator|>
name|indices
index|[
name|i
index|]
condition|)
name|minIndex
operator|=
name|indices
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|maxIndex
operator|<
name|indices
index|[
name|i
index|]
condition|)
name|maxIndex
operator|=
name|indices
index|[
name|i
index|]
expr_stmt|;
block|}
return|return
name|RangeUI
argument_list|(
name|minIndex
argument_list|,
name|maxIndex
argument_list|)
return|;
block|}
DECL|function|ComputeRange
name|RangeUI
name|IndexRangeCache
operator|::
name|ComputeRange
parameter_list|(
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|indices
parameter_list|,
name|GLsizei
name|count
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_UNSIGNED_BYTE
case|:
return|return
name|ComputeTypedRange
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|GLubyte
operator|*
argument_list|>
argument_list|(
name|indices
argument_list|)
argument_list|,
name|count
argument_list|)
return|;
case|case
name|GL_UNSIGNED_INT
case|:
return|return
name|ComputeTypedRange
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|GLuint
operator|*
argument_list|>
argument_list|(
name|indices
argument_list|)
argument_list|,
name|count
argument_list|)
return|;
case|case
name|GL_UNSIGNED_SHORT
case|:
return|return
name|ComputeTypedRange
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|GLushort
operator|*
argument_list|>
argument_list|(
name|indices
argument_list|)
argument_list|,
name|count
argument_list|)
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|RangeUI
argument_list|()
return|;
block|}
block|}
DECL|function|addRange
name|void
name|IndexRangeCache
operator|::
name|addRange
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|RangeUI
modifier|&
name|range
parameter_list|,
name|unsigned
name|int
name|streamOffset
parameter_list|)
block|{
name|mIndexRangeCache
index|[
name|IndexRange
argument_list|(
name|type
argument_list|,
name|offset
argument_list|,
name|count
argument_list|)
index|]
operator|=
name|IndexBounds
argument_list|(
name|range
argument_list|,
name|streamOffset
argument_list|)
expr_stmt|;
block|}
DECL|function|invalidateRange
name|void
name|IndexRangeCache
operator|::
name|invalidateRange
parameter_list|(
name|unsigned
name|int
name|offset
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
block|{
name|unsigned
name|int
name|invalidateStart
init|=
name|offset
decl_stmt|;
name|unsigned
name|int
name|invalidateEnd
init|=
name|offset
operator|+
name|size
decl_stmt|;
name|IndexRangeMap
operator|::
name|iterator
name|i
init|=
name|mIndexRangeCache
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|mIndexRangeCache
operator|.
name|end
argument_list|()
condition|)
block|{
name|unsigned
name|int
name|rangeStart
init|=
name|i
operator|->
name|second
operator|.
name|streamOffset
decl_stmt|;
name|unsigned
name|int
name|rangeEnd
init|=
name|i
operator|->
name|second
operator|.
name|streamOffset
operator|+
operator|(
name|gl
operator|::
name|GetTypeInfo
argument_list|(
name|i
operator|->
name|first
operator|.
name|type
argument_list|)
operator|.
name|bytes
operator|*
name|i
operator|->
name|first
operator|.
name|count
operator|)
decl_stmt|;
if|if
condition|(
name|invalidateEnd
argument_list|<
name|rangeStart
operator|||
name|invalidateStart
argument_list|>
name|rangeEnd
condition|)
block|{
operator|++
name|i
expr_stmt|;
block|}
else|else
block|{
name|i
operator|=
name|mIndexRangeCache
operator|.
name|erase
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
block|}
block|}
DECL|function|findRange
name|bool
name|IndexRangeCache
operator|::
name|findRange
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|RangeUI
modifier|*
name|outRange
parameter_list|,
name|unsigned
name|int
modifier|*
name|outStreamOffset
parameter_list|)
specifier|const
block|{
name|IndexRangeMap
operator|::
name|const_iterator
name|i
init|=
name|mIndexRangeCache
operator|.
name|find
argument_list|(
name|IndexRange
argument_list|(
name|type
argument_list|,
name|offset
argument_list|,
name|count
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|!=
name|mIndexRangeCache
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|outRange
condition|)
operator|*
name|outRange
operator|=
name|i
operator|->
name|second
operator|.
name|range
expr_stmt|;
if|if
condition|(
name|outStreamOffset
condition|)
operator|*
name|outStreamOffset
operator|=
name|i
operator|->
name|second
operator|.
name|streamOffset
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
if|if
condition|(
name|outRange
condition|)
operator|*
name|outRange
operator|=
name|RangeUI
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|outStreamOffset
condition|)
operator|*
name|outStreamOffset
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
DECL|function|clear
name|void
name|IndexRangeCache
operator|::
name|clear
parameter_list|()
block|{
name|mIndexRangeCache
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|IndexRange
name|IndexRangeCache
operator|::
name|IndexRange
operator|::
name|IndexRange
parameter_list|()
member_init_list|:
name|type
argument_list|(
name|GL_NONE
argument_list|)
member_init_list|,
name|offset
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|count
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|IndexRange
name|IndexRangeCache
operator|::
name|IndexRange
operator|::
name|IndexRange
parameter_list|(
name|GLenum
name|typ
parameter_list|,
name|intptr_t
name|off
parameter_list|,
name|GLsizei
name|c
parameter_list|)
member_init_list|:
name|type
argument_list|(
name|typ
argument_list|)
member_init_list|,
name|offset
argument_list|(
name|off
argument_list|)
member_init_list|,
name|count
argument_list|(
name|c
argument_list|)
block|{ }
DECL|function|operator <
name|bool
name|IndexRangeCache
operator|::
name|IndexRange
operator|::
name|operator
name|<
parameter_list|(
specifier|const
name|IndexRange
modifier|&
name|rhs
parameter_list|)
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1600
return|return
name|std
operator|::
name|tr1
operator|::
name|make_tuple
argument_list|(
name|type
argument_list|,
name|offset
argument_list|,
name|count
argument_list|)
operator|<
name|std
operator|::
name|tr1
operator|::
name|make_tuple
argument_list|(
name|rhs
operator|.
name|type
argument_list|,
name|rhs
operator|.
name|offset
argument_list|,
name|rhs
operator|.
name|count
argument_list|)
return|;
else|#
directive|else
return|return
name|std
operator|::
name|make_tuple
argument_list|(
name|type
argument_list|,
name|offset
argument_list|,
name|count
argument_list|)
operator|<
name|std
operator|::
name|make_tuple
argument_list|(
name|rhs
operator|.
name|type
argument_list|,
name|rhs
operator|.
name|offset
argument_list|,
name|rhs
operator|.
name|count
argument_list|)
return|;
endif|#
directive|endif
block|}
DECL|function|IndexBounds
name|IndexRangeCache
operator|::
name|IndexBounds
operator|::
name|IndexBounds
parameter_list|()
member_init_list|:
name|range
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
member_init_list|,
name|streamOffset
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|IndexBounds
name|IndexRangeCache
operator|::
name|IndexBounds
operator|::
name|IndexBounds
parameter_list|(
specifier|const
name|RangeUI
modifier|&
name|rangeIn
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|)
member_init_list|:
name|range
argument_list|(
name|rangeIn
argument_list|)
member_init_list|,
name|streamOffset
argument_list|(
name|offset
argument_list|)
block|{ }
block|}
end_namespace
end_unit
