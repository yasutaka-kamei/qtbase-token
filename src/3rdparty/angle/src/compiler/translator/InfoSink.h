begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_INFOSINK_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_INFOSINK_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_INFOSINK_H_
end_define
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Common.h"
end_include
begin_comment
comment|// Returns the fractional part of the given floating-point number.
end_comment
begin_function
DECL|function|fractionalPart
specifier|inline
name|float
name|fractionalPart
parameter_list|(
name|float
name|f
parameter_list|)
block|{
name|float
name|intPart
init|=
literal|0.0f
decl_stmt|;
return|return
name|modff
argument_list|(
name|f
argument_list|,
operator|&
name|intPart
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//
end_comment
begin_comment
comment|// TPrefixType is used to centralize how info log messages start.
end_comment
begin_comment
comment|// See below.
end_comment
begin_comment
comment|//
end_comment
begin_enum
DECL|enum|TPrefixType
enum|enum
name|TPrefixType
block|{
DECL|enumerator|EPrefixNone
name|EPrefixNone
block|,
DECL|enumerator|EPrefixWarning
name|EPrefixWarning
block|,
DECL|enumerator|EPrefixError
name|EPrefixError
block|,
DECL|enumerator|EPrefixInternalError
name|EPrefixInternalError
block|,
DECL|enumerator|EPrefixUnimplemented
name|EPrefixUnimplemented
block|,
DECL|enumerator|EPrefixNote
name|EPrefixNote
block|}
enum|;
end_enum
begin_comment
comment|//
end_comment
begin_comment
comment|// Encapsulate info logs for all objects that have them.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// The methods are a general set of tools for getting a variety of
end_comment
begin_comment
comment|// messages and types inserted into the log.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TInfoSinkBase
block|{
name|public
label|:
name|TInfoSinkBase
argument_list|()
block|{}
name|template
operator|<
name|typename
name|T
operator|>
name|TInfoSinkBase
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
name|TPersistStringStream
name|stream
block|;
name|stream
operator|<<
name|t
block|;
name|sink
operator|.
name|append
argument_list|(
name|stream
operator|.
name|str
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Override<< operator for specific types. It is faster to append strings
comment|// and characters directly to the sink.
name|TInfoSinkBase
operator|&
name|operator
operator|<<
operator|(
name|char
name|c
operator|)
block|{
name|sink
operator|.
name|append
argument_list|(
literal|1
argument_list|,
name|c
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|TInfoSinkBase
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|str
operator|)
block|{
name|sink
operator|.
name|append
argument_list|(
name|str
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|TInfoSinkBase
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|TPersistString
operator|&
name|str
operator|)
block|{
name|sink
operator|.
name|append
argument_list|(
name|str
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|TInfoSinkBase
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|TString
operator|&
name|str
operator|)
block|{
name|sink
operator|.
name|append
argument_list|(
name|str
operator|.
name|c_str
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Make sure floats are written with correct precision.
name|TInfoSinkBase
operator|&
name|operator
operator|<<
operator|(
name|float
name|f
operator|)
block|{
comment|// Make sure that at least one decimal point is written. If a number
comment|// does not have a fractional part, the default precision format does
comment|// not write the decimal portion which gets interpreted as integer by
comment|// the compiler.
name|TPersistStringStream
name|stream
block|;
if|if
condition|(
name|fractionalPart
argument_list|(
name|f
argument_list|)
operator|==
literal|0.0f
condition|)
block|{
name|stream
operator|.
name|precision
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|stream
operator|<<
name|std
operator|::
name|showpoint
operator|<<
name|std
operator|::
name|fixed
operator|<<
name|f
expr_stmt|;
block|}
else|else
block|{
name|stream
operator|.
name|unsetf
argument_list|(
name|std
operator|::
name|ios
operator|::
name|fixed
argument_list|)
expr_stmt|;
name|stream
operator|.
name|unsetf
argument_list|(
name|std
operator|::
name|ios
operator|::
name|scientific
argument_list|)
expr_stmt|;
name|stream
operator|.
name|precision
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|stream
operator|<<
name|f
expr_stmt|;
block|}
name|sink
operator|.
name|append
argument_list|(
name|stream
operator|.
name|str
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_comment
comment|// Write boolean values as their names instead of integral value.
end_comment
begin_expr_stmt
name|TInfoSinkBase
operator|&
name|operator
operator|<<
operator|(
name|bool
name|b
operator|)
block|{
specifier|const
name|char
operator|*
name|str
operator|=
name|b
operator|?
literal|"true"
operator|:
literal|"false"
block|;
name|sink
operator|.
name|append
argument_list|(
name|str
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_function
name|void
name|erase
parameter_list|()
block|{
name|sink
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
name|int
name|size
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|sink
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_function
begin_expr_stmt
specifier|const
name|TPersistString
operator|&
name|str
argument_list|()
specifier|const
block|{
return|return
name|sink
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|const
name|char
operator|*
name|c_str
argument_list|()
specifier|const
block|{
return|return
name|sink
operator|.
name|c_str
argument_list|()
return|;
block|}
end_expr_stmt
begin_function_decl
name|void
name|prefix
parameter_list|(
name|TPrefixType
name|p
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|location
parameter_list|(
name|int
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|location
parameter_list|(
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|message
parameter_list|(
name|TPrefixType
name|p
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|loc
parameter_list|,
specifier|const
name|char
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|TPersistString
name|sink
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|TInfoSink
block|{
name|public
label|:
name|TInfoSinkBase
name|info
decl_stmt|;
name|TInfoSinkBase
name|debug
decl_stmt|;
name|TInfoSinkBase
name|obj
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_INFOSINK_H_
end_comment
end_unit
