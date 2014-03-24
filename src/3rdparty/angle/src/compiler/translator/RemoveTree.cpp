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
begin_include
include|#
directive|include
file|"compiler/translator/intermediate.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/RemoveTree.h"
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// Code to recursively delete the intermediate tree.
end_comment
begin_comment
comment|//
end_comment
begin_class
DECL|class|RemoveTree
class|class
name|RemoveTree
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
DECL|function|RemoveTree
name|RemoveTree
parameter_list|()
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|false
argument_list|,
literal|false
argument_list|,
literal|true
argument_list|)
block|{ 	}
protected|protected:
name|void
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
parameter_list|)
function_decl|;
name|void
name|visitConstantUnion
parameter_list|(
name|TIntermConstantUnion
modifier|*
parameter_list|)
function_decl|;
name|bool
name|visitBinary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBinary
modifier|*
parameter_list|)
function_decl|;
name|bool
name|visitUnary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermUnary
modifier|*
parameter_list|)
function_decl|;
name|bool
name|visitSelection
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermSelection
modifier|*
parameter_list|)
function_decl|;
name|bool
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|visitSymbol
name|void
name|RemoveTree
operator|::
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
name|node
parameter_list|)
block|{
operator|delete
name|node
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visitBinary
name|bool
name|RemoveTree
operator|::
name|visitBinary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBinary
modifier|*
name|node
parameter_list|)
block|{
operator|delete
name|node
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|visitUnary
name|bool
name|RemoveTree
operator|::
name|visitUnary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermUnary
modifier|*
name|node
parameter_list|)
block|{
operator|delete
name|node
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|visitAggregate
name|bool
name|RemoveTree
operator|::
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
operator|delete
name|node
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|visitSelection
name|bool
name|RemoveTree
operator|::
name|visitSelection
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermSelection
modifier|*
name|node
parameter_list|)
block|{
operator|delete
name|node
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|visitConstantUnion
name|void
name|RemoveTree
operator|::
name|visitConstantUnion
parameter_list|(
name|TIntermConstantUnion
modifier|*
name|node
parameter_list|)
block|{
operator|delete
name|node
expr_stmt|;
block|}
end_function
begin_comment
comment|//
end_comment
begin_comment
comment|// Entry point.
end_comment
begin_comment
comment|//
end_comment
begin_function
DECL|function|RemoveAllTreeNodes
name|void
name|RemoveAllTreeNodes
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|RemoveTree
name|it
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|it
argument_list|)
expr_stmt|;
block|}
end_function
end_unit