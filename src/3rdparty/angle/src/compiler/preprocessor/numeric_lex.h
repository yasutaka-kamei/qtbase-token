begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// numeric_lex.h: Functions to extract numeric values from string.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_PREPROCESSOR_NUMERICLEX_H_
end_ifndef
begin_define
DECL|macro|COMPILER_PREPROCESSOR_NUMERICLEX_H_
define|#
directive|define
name|COMPILER_PREPROCESSOR_NUMERICLEX_H_
end_define
begin_include
include|#
directive|include
file|<sstream>
end_include
begin_decl_stmt
name|namespace
name|pp
block|{
specifier|inline
name|std
operator|::
name|ios
operator|::
name|fmtflags
name|numeric_base_int
argument_list|(
argument|const std::string&str
argument_list|)
block|{
if|if
condition|(
operator|(
name|str
operator|.
name|size
argument_list|()
operator|>=
literal|2
operator|)
operator|&&
operator|(
name|str
index|[
literal|0
index|]
operator|==
literal|'0'
operator|)
operator|&&
operator|(
name|str
index|[
literal|1
index|]
operator|==
literal|'x'
operator|||
name|str
index|[
literal|1
index|]
operator|==
literal|'X'
operator|)
condition|)
block|{
return|return
name|std
operator|::
name|ios
operator|::
name|hex
return|;
block|}
if|if
condition|(
operator|(
name|str
operator|.
name|size
argument_list|()
operator|>=
literal|1
operator|)
operator|&&
operator|(
name|str
index|[
literal|0
index|]
operator|==
literal|'0'
operator|)
condition|)
block|{
return|return
name|std
operator|::
name|ios
operator|::
name|oct
return|;
block|}
return|return
name|std
operator|::
name|ios
operator|::
name|dec
return|;
block|}
comment|// The following functions parse the given string to extract a numerical
comment|// value of the given type. These functions assume that the string is
comment|// of the correct form. They can only fail if the parsed value is too big,
comment|// in which case false is returned.
name|template
operator|<
name|typename
name|IntType
operator|>
name|bool
name|numeric_lex_int
argument_list|(
argument|const std::string&str
argument_list|,
argument|IntType *value
argument_list|)
block|{
name|std
operator|::
name|istringstream
name|stream
argument_list|(
name|str
argument_list|)
block|;
comment|// This should not be necessary, but MSVS has a buggy implementation.
comment|// It returns incorrect results if the base is not specified.
name|stream
operator|.
name|setf
argument_list|(
name|numeric_base_int
argument_list|(
name|str
argument_list|)
argument_list|,
name|std
operator|::
name|ios
operator|::
name|basefield
argument_list|)
block|;
name|stream
operator|>>
operator|(
operator|*
name|value
operator|)
block|;
return|return
operator|!
name|stream
operator|.
name|fail
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|FloatType
operator|>
name|bool
name|numeric_lex_float
argument_list|(
argument|const std::string&str
argument_list|,
argument|FloatType *value
argument_list|)
block|{
name|std
operator|::
name|istringstream
name|stream
argument_list|(
name|str
argument_list|)
block|;
comment|// Force "C" locale so that decimal character is always '.', and
comment|// not dependent on the current locale.
name|stream
operator|.
name|imbue
argument_list|(
name|std
operator|::
name|locale
operator|::
name|classic
argument_list|()
argument_list|)
block|;
name|stream
operator|>>
operator|(
operator|*
name|value
operator|)
block|;
return|return
operator|!
name|stream
operator|.
name|fail
argument_list|()
return|;
block|}
block|}
end_decl_stmt
begin_comment
comment|// namespace pp.
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_PREPROCESSOR_NUMERICLEX_H_
end_comment
end_unit
