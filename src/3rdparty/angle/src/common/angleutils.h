begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// angleutils.h: Common ANGLE utilities.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMMON_ANGLEUTILS_H_
end_ifndef
begin_define
DECL|macro|COMMON_ANGLEUTILS_H_
define|#
directive|define
name|COMMON_ANGLEUTILS_H_
end_define
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_include
include|#
directive|include
file|<climits>
end_include
begin_include
include|#
directive|include
file|<cstdarg>
end_include
begin_include
include|#
directive|include
file|<cstddef>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_include
include|#
directive|include
file|<sstream>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_comment
comment|// A helper class to disallow copy and assignment operators
end_comment
begin_decl_stmt
name|namespace
name|angle
block|{
name|class
name|NonCopyable
block|{
name|public
label|:
name|NonCopyable
argument_list|()
operator|=
expr|default
expr_stmt|;
operator|~
name|NonCopyable
argument_list|()
operator|=
expr|default
expr_stmt|;
name|protected
label|:
name|NonCopyable
argument_list|(
specifier|const
name|NonCopyable
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|NonCopyable
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
block|}
empty_stmt|;
specifier|extern
specifier|const
name|uintptr_t
name|DirtyPointer
decl_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
specifier|inline
name|size_t
name|ArraySize
argument_list|(
argument|T(&)[N]
argument_list|)
block|{
return|return
name|N
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|typename
name|T
operator|,
name|unsigned
name|int
name|N
operator|>
name|void
name|SafeRelease
argument_list|(
argument|T (&resourceBlock)[N]
argument_list|)
block|{
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|N
condition|;
name|i
operator|++
control|)
block|{
name|SafeRelease
argument_list|(
name|resourceBlock
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|SafeRelease
name|void
name|SafeRelease
argument_list|(
argument|T& resource
argument_list|)
block|{
if|if
condition|(
name|resource
condition|)
block|{
name|resource
operator|->
name|Release
argument_list|()
expr_stmt|;
name|resource
operator|=
name|NULL
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|SafeDelete
name|void
name|SafeDelete
argument_list|(
argument|T*& resource
argument_list|)
block|{
name|delete
name|resource
block|;
name|resource
operator|=
name|NULL
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|SafeDeleteContainer
name|void
name|SafeDeleteContainer
argument_list|(
argument|T& resource
argument_list|)
block|{
for|for
control|(
name|auto
operator|&
name|element
operator|:
name|resource
control|)
block|{
name|SafeDelete
argument_list|(
name|element
argument_list|)
expr_stmt|;
block|}
name|resource
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|SafeDeleteArray
name|void
name|SafeDeleteArray
argument_list|(
argument|T*& resource
argument_list|)
block|{
name|delete
index|[]
name|resource
block|;
name|resource
operator|=
name|NULL
block|; }
comment|// Provide a less-than function for comparing structs
comment|// Note: struct memory must be initialized to zero, because of packing gaps
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|StructLessThan
specifier|inline
name|bool
name|StructLessThan
argument_list|(
argument|const T&a
argument_list|,
argument|const T&b
argument_list|)
block|{
return|return
operator|(
name|memcmp
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|<
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Provide a less-than function for comparing structs
end_comment
begin_comment
comment|// Note: struct memory must be initialized to zero, because of packing gaps
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|StructEquals
specifier|inline
name|bool
name|StructEquals
argument_list|(
argument|const T&a
argument_list|,
argument|const T&b
argument_list|)
block|{
return|return
operator|(
name|memcmp
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|StructZero
specifier|inline
name|void
name|StructZero
argument_list|(
argument|T *obj
argument_list|)
block|{
name|memset
argument_list|(
name|obj
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|IsMaskFlagSet
specifier|inline
name|bool
name|IsMaskFlagSet
argument_list|(
argument|T mask
argument_list|,
argument|T flag
argument_list|)
block|{
comment|// Handles multibit flags as well
return|return
operator|(
name|mask
operator|&
name|flag
operator|)
operator|==
name|flag
return|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|function|MakeStaticString
specifier|inline
specifier|const
name|char
modifier|*
name|MakeStaticString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
block|{
specifier|static
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
name|strings
expr_stmt|;
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
operator|::
name|iterator
name|it
operator|=
name|strings
operator|.
name|find
argument_list|(
name|str
argument_list|)
expr_stmt|;
if|if
condition|(
name|it
operator|!=
name|strings
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|it
operator|->
name|c_str
argument_list|()
return|;
block|}
return|return
name|strings
operator|.
name|insert
argument_list|(
name|str
argument_list|)
operator|.
name|first
operator|->
name|c_str
argument_list|()
return|;
block|}
end_decl_stmt
begin_expr_stmt
DECL|function|ArrayString
specifier|inline
name|std
operator|::
name|string
name|ArrayString
argument_list|(
argument|unsigned int i
argument_list|)
block|{
comment|// We assume UINT_MAX and GL_INVALID_INDEX are equal
comment|// See DynamicHLSL.cpp
if|if
condition|(
name|i
operator|==
name|UINT_MAX
condition|)
block|{
return|return
literal|""
return|;
block|}
name|std
operator|::
name|stringstream
name|strstr
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|strstr
operator|<<
literal|"["
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|strstr
operator|<<
name|i
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|strstr
operator|<<
literal|"]"
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|strstr
operator|.
name|str
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|Str
name|std
operator|::
name|string
name|Str
argument_list|(
argument|int i
argument_list|)
block|{
name|std
operator|::
name|stringstream
name|strstr
block|;
name|strstr
operator|<<
name|i
block|;
return|return
name|strstr
operator|.
name|str
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|size_t
name|FormatStringIntoVector
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
name|va_list
name|vararg
argument_list|,
name|std
operator|::
name|vector
operator|<
name|char
operator|>
operator|&
name|buffer
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|std
operator|::
name|string
name|FormatString
argument_list|(
argument|const char *fmt
argument_list|,
argument|va_list vararg
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|std
operator|::
name|string
name|FormatString
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// snprintf is not defined with MSVC prior to to msvc14
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1900
end_if
begin_define
DECL|macro|snprintf
define|#
directive|define
name|snprintf
value|_snprintf
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|GL_BGRA4_ANGLEX
define|#
directive|define
name|GL_BGRA4_ANGLEX
value|0x6ABC
end_define
begin_define
DECL|macro|GL_BGR5_A1_ANGLEX
define|#
directive|define
name|GL_BGR5_A1_ANGLEX
value|0x6ABD
end_define
begin_define
DECL|macro|GL_INT_64_ANGLEX
define|#
directive|define
name|GL_INT_64_ANGLEX
value|0x6ABE
end_define
begin_define
DECL|macro|GL_STRUCT_ANGLEX
define|#
directive|define
name|GL_STRUCT_ANGLEX
value|0x6ABF
end_define
begin_comment
comment|// Hidden enum for the NULL D3D device type.
end_comment
begin_define
DECL|macro|EGL_PLATFORM_ANGLE_DEVICE_TYPE_NULL_ANGLE
define|#
directive|define
name|EGL_PLATFORM_ANGLE_DEVICE_TYPE_NULL_ANGLE
value|0x6AC0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMMON_ANGLEUTILS_H_
end_comment
end_unit
