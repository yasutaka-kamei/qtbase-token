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
begin_comment
comment|// SearchSymbol is an AST traverser to detect the use of a given symbol name
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/SearchSymbol.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InfoSink.h"
end_include
begin_namespace
DECL|namespace|sh
namespace|namespace
name|sh
block|{
DECL|function|SearchSymbol
name|SearchSymbol
operator|::
name|SearchSymbol
parameter_list|(
specifier|const
name|TString
modifier|&
name|symbol
parameter_list|)
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|)
member_init_list|,
name|mSymbol
argument_list|(
name|symbol
argument_list|)
block|{
name|match
operator|=
literal|false
expr_stmt|;
block|}
DECL|function|traverse
name|void
name|SearchSymbol
operator|::
name|traverse
parameter_list|(
name|TIntermNode
modifier|*
name|node
parameter_list|)
block|{
name|node
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
DECL|function|visitSymbol
name|void
name|SearchSymbol
operator|::
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
name|symbolNode
parameter_list|)
block|{
if|if
condition|(
name|symbolNode
operator|->
name|getSymbol
argument_list|()
operator|==
name|mSymbol
condition|)
block|{
name|match
operator|=
literal|true
expr_stmt|;
block|}
block|}
DECL|function|foundMatch
name|bool
name|SearchSymbol
operator|::
name|foundMatch
parameter_list|()
specifier|const
block|{
return|return
name|match
return|;
block|}
block|}
end_namespace
end_unit
