begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2015 The ANGLE Project Authors. All rights reserved.
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
comment|// The PruneEmptyDeclarations function prunes unnecessary empty declarations and declarators from the AST.
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/PruneEmptyDeclarations.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_namespace
namespace|namespace
block|{
DECL|class|PruneEmptyDeclarationsTraverser
class|class
name|PruneEmptyDeclarationsTraverser
super|:
specifier|private
name|TIntermTraverser
block|{
public|public:
specifier|static
name|void
name|apply
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
function_decl|;
private|private:
name|PruneEmptyDeclarationsTraverser
parameter_list|()
constructor_decl|;
DECL|member|override
name|bool
name|visitAggregate
parameter_list|(
name|Visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
specifier|override
function_decl|;
block|}
class|;
DECL|function|apply
name|void
name|PruneEmptyDeclarationsTraverser
operator|::
name|apply
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|PruneEmptyDeclarationsTraverser
name|prune
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|prune
argument_list|)
expr_stmt|;
name|prune
operator|.
name|updateTree
argument_list|()
expr_stmt|;
block|}
DECL|function|PruneEmptyDeclarationsTraverser
name|PruneEmptyDeclarationsTraverser
operator|::
name|PruneEmptyDeclarationsTraverser
parameter_list|()
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|)
block|{ }
DECL|function|visitAggregate
name|bool
name|PruneEmptyDeclarationsTraverser
operator|::
name|visitAggregate
parameter_list|(
name|Visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpDeclaration
condition|)
block|{
name|TIntermSequence
modifier|*
name|sequence
init|=
name|node
operator|->
name|getSequence
argument_list|()
decl_stmt|;
if|if
condition|(
name|sequence
operator|->
name|size
argument_list|()
operator|>=
literal|1
condition|)
block|{
name|TIntermSymbol
modifier|*
name|sym
init|=
name|sequence
operator|->
name|front
argument_list|()
operator|->
name|getAsSymbolNode
argument_list|()
decl_stmt|;
comment|// Prune declarations without a variable name, unless it's an interface block declaration.
if|if
condition|(
name|sym
operator|!=
literal|nullptr
operator|&&
name|sym
operator|->
name|getSymbol
argument_list|()
operator|==
literal|""
operator|&&
operator|!
name|sym
operator|->
name|isInterfaceBlock
argument_list|()
condition|)
block|{
if|if
condition|(
name|sequence
operator|->
name|size
argument_list|()
operator|>
literal|1
condition|)
block|{
comment|// Generate a replacement that will remove the empty declarator in the beginning of a declarator
comment|// list. Example of a declaration that will be changed:
comment|// float, a;
comment|// will be changed to
comment|// float a;
comment|// This applies also to struct declarations.
name|TIntermSequence
name|emptyReplacement
decl_stmt|;
name|mMultiReplacements
operator|.
name|push_back
argument_list|(
name|NodeReplaceWithMultipleEntry
argument_list|(
name|node
argument_list|,
name|sym
argument_list|,
name|emptyReplacement
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sym
operator|->
name|getBasicType
argument_list|()
operator|!=
name|EbtStruct
condition|)
block|{
comment|// Single struct declarations may just declare the struct type and no variables, so they should
comment|// not be pruned. All other single empty declarations can be pruned entirely. Example of an empty
comment|// declaration that will be pruned:
comment|// float;
name|TIntermSequence
name|emptyReplacement
decl_stmt|;
name|TIntermAggregate
modifier|*
name|parentAgg
init|=
name|getParentNode
argument_list|()
operator|->
name|getAsAggregate
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|parentAgg
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|mMultiReplacements
operator|.
name|push_back
argument_list|(
name|NodeReplaceWithMultipleEntry
argument_list|(
name|parentAgg
argument_list|,
name|node
argument_list|,
name|emptyReplacement
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace
end_comment
begin_function
DECL|function|PruneEmptyDeclarations
name|void
name|PruneEmptyDeclarations
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|PruneEmptyDeclarationsTraverser
operator|::
name|apply
argument_list|(
name|root
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
