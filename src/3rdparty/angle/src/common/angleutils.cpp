begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"debug.h"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_function
DECL|function|FormatStringIntoVector
name|size_t
name|FormatStringIntoVector
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|vararg
parameter_list|,
name|std
operator|::
name|vector
argument_list|<
name|char
argument_list|>
modifier|&
name|outBuffer
parameter_list|)
block|{
comment|// Attempt to just print to the current buffer
name|int
name|len
init|=
name|vsnprintf
argument_list|(
operator|&
operator|(
name|outBuffer
operator|.
name|front
argument_list|()
operator|)
argument_list|,
name|outBuffer
operator|.
name|size
argument_list|()
argument_list|,
name|fmt
argument_list|,
name|vararg
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|<
literal|0
operator|||
cast|static_cast
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|len
argument_list|)
operator|>=
name|outBuffer
operator|.
name|size
argument_list|()
condition|)
block|{
comment|// Buffer was not large enough, calculate the required size and resize the buffer
name|len
operator|=
name|vsnprintf
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|fmt
argument_list|,
name|vararg
argument_list|)
expr_stmt|;
name|outBuffer
operator|.
name|resize
argument_list|(
name|len
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|// Print again
name|len
operator|=
name|vsnprintf
argument_list|(
operator|&
operator|(
name|outBuffer
operator|.
name|front
argument_list|()
operator|)
argument_list|,
name|outBuffer
operator|.
name|size
argument_list|()
argument_list|,
name|fmt
argument_list|,
name|vararg
argument_list|)
expr_stmt|;
block|}
name|ASSERT
argument_list|(
name|len
operator|>=
literal|0
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|len
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|FormatString
name|std
operator|::
name|string
name|FormatString
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|vararg
parameter_list|)
block|{
specifier|static
name|std
operator|::
name|vector
argument_list|<
name|char
argument_list|>
name|buffer
argument_list|(
literal|512
argument_list|)
decl_stmt|;
name|size_t
name|len
init|=
name|FormatStringIntoVector
argument_list|(
name|fmt
argument_list|,
name|vararg
argument_list|,
name|buffer
argument_list|)
decl_stmt|;
return|return
name|std
operator|::
name|string
argument_list|(
operator|&
name|buffer
index|[
literal|0
index|]
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|FormatString
name|std
operator|::
name|string
name|FormatString
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|vararg
decl_stmt|;
name|va_start
argument_list|(
name|vararg
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|result
init|=
name|FormatString
argument_list|(
name|fmt
argument_list|,
name|vararg
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|vararg
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
end_unit
