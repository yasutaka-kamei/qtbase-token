begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2011 The ANGLE Project Authors. All rights reserved.
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
begin_include
include|#
directive|include
file|"Input.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<cassert>
end_include
begin_include
include|#
directive|include
file|<cstring>
end_include
begin_namespace
DECL|namespace|pp
namespace|namespace
name|pp
block|{
DECL|function|Input
name|Input
operator|::
name|Input
parameter_list|()
member_init_list|:
name|mCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mString
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|Input
name|Input
operator|::
name|Input
parameter_list|(
name|int
name|count
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
name|string
index|[]
parameter_list|,
specifier|const
name|int
name|length
index|[]
parameter_list|)
member_init_list|:
name|mCount
argument_list|(
name|count
argument_list|)
member_init_list|,
name|mString
argument_list|(
name|string
argument_list|)
block|{
name|assert
argument_list|(
name|mCount
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|mLength
operator|.
name|reserve
argument_list|(
name|mCount
argument_list|)
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
name|mCount
condition|;
operator|++
name|i
control|)
block|{
name|int
name|len
init|=
name|length
condition|?
name|length
index|[
name|i
index|]
else|:
operator|-
literal|1
decl_stmt|;
name|mLength
operator|.
name|push_back
argument_list|(
name|len
operator|<
literal|0
condition|?
name|strlen
argument_list|(
name|mString
index|[
name|i
index|]
argument_list|)
else|:
name|len
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|read
name|int
name|Input
operator|::
name|read
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|maxSize
parameter_list|)
block|{
name|int
name|nRead
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|nRead
operator|<
name|maxSize
operator|)
operator|&&
operator|(
name|mReadLoc
operator|.
name|sIndex
operator|<
name|mCount
operator|)
condition|)
block|{
name|int
name|size
init|=
name|mLength
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
operator|-
name|mReadLoc
operator|.
name|cIndex
decl_stmt|;
name|size
operator|=
name|std
operator|::
name|min
argument_list|(
name|size
argument_list|,
name|maxSize
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|buf
operator|+
name|nRead
argument_list|,
name|mString
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
operator|+
name|mReadLoc
operator|.
name|cIndex
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|nRead
operator|+=
name|size
expr_stmt|;
name|mReadLoc
operator|.
name|cIndex
operator|+=
name|size
expr_stmt|;
comment|// Advance string if we reached the end of current string.
if|if
condition|(
name|mReadLoc
operator|.
name|cIndex
operator|==
name|mLength
index|[
name|mReadLoc
operator|.
name|sIndex
index|]
condition|)
block|{
operator|++
name|mReadLoc
operator|.
name|sIndex
expr_stmt|;
name|mReadLoc
operator|.
name|cIndex
operator|=
literal|0
expr_stmt|;
block|}
block|}
return|return
name|nRead
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace pp
end_comment
end_unit
