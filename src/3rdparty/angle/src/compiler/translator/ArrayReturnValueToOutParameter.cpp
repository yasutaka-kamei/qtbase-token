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
comment|// The ArrayReturnValueToOutParameter function changes return values of an array type to out parameters in
end_comment
begin_comment
comment|// function definitions, prototypes, and call sites.
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/ArrayReturnValueToOutParameter.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_namespace
namespace|namespace
block|{
DECL|function|CopyAggregateChildren
name|void
name|CopyAggregateChildren
parameter_list|(
name|TIntermAggregate
modifier|*
name|from
parameter_list|,
name|TIntermAggregate
modifier|*
name|to
parameter_list|)
block|{
specifier|const
name|TIntermSequence
modifier|*
name|fromSequence
init|=
name|from
operator|->
name|getSequence
argument_list|()
decl_stmt|;
for|for
control|(
name|size_t
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|fromSequence
operator|->
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
name|to
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|fromSequence
operator|->
name|at
argument_list|(
name|ii
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|CreateReturnValueSymbol
name|TIntermSymbol
modifier|*
name|CreateReturnValueSymbol
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
block|{
name|TIntermSymbol
modifier|*
name|node
init|=
operator|new
name|TIntermSymbol
argument_list|(
literal|0
argument_list|,
literal|"angle_return"
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|node
operator|->
name|setInternal
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return
name|node
return|;
block|}
DECL|function|CreateReturnValueOutSymbol
name|TIntermSymbol
modifier|*
name|CreateReturnValueOutSymbol
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
block|{
name|TType
name|outType
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|outType
operator|.
name|setQualifier
argument_list|(
name|EvqOut
argument_list|)
expr_stmt|;
return|return
name|CreateReturnValueSymbol
argument_list|(
name|outType
argument_list|)
return|;
block|}
DECL|function|CreateReplacementCall
name|TIntermAggregate
modifier|*
name|CreateReplacementCall
parameter_list|(
name|TIntermAggregate
modifier|*
name|originalCall
parameter_list|,
name|TIntermTyped
modifier|*
name|returnValueTarget
parameter_list|)
block|{
name|TIntermAggregate
modifier|*
name|replacementCall
init|=
operator|new
name|TIntermAggregate
argument_list|(
name|EOpFunctionCall
argument_list|)
decl_stmt|;
name|replacementCall
operator|->
name|setType
argument_list|(
name|TType
argument_list|(
name|EbtVoid
argument_list|)
argument_list|)
expr_stmt|;
name|replacementCall
operator|->
name|setUserDefined
argument_list|()
expr_stmt|;
name|replacementCall
operator|->
name|setNameObj
argument_list|(
name|originalCall
operator|->
name|getNameObj
argument_list|()
argument_list|)
expr_stmt|;
name|replacementCall
operator|->
name|setFunctionId
argument_list|(
name|originalCall
operator|->
name|getFunctionId
argument_list|()
argument_list|)
expr_stmt|;
name|replacementCall
operator|->
name|setLine
argument_list|(
name|originalCall
operator|->
name|getLine
argument_list|()
argument_list|)
expr_stmt|;
name|TIntermSequence
modifier|*
name|replacementParameters
init|=
name|replacementCall
operator|->
name|getSequence
argument_list|()
decl_stmt|;
name|TIntermSequence
modifier|*
name|originalParameters
init|=
name|originalCall
operator|->
name|getSequence
argument_list|()
decl_stmt|;
for|for
control|(
name|auto
operator|&
name|param
operator|:
operator|*
name|originalParameters
control|)
block|{
name|replacementParameters
operator|->
name|push_back
argument_list|(
name|param
argument_list|)
expr_stmt|;
block|}
name|replacementParameters
operator|->
name|push_back
argument_list|(
name|returnValueTarget
argument_list|)
expr_stmt|;
return|return
name|replacementCall
return|;
block|}
DECL|class|ArrayReturnValueToOutParameterTraverser
class|class
name|ArrayReturnValueToOutParameterTraverser
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
parameter_list|,
name|unsigned
name|int
modifier|*
name|temporaryIndex
parameter_list|)
function_decl|;
private|private:
name|ArrayReturnValueToOutParameterTraverser
parameter_list|()
constructor_decl|;
DECL|member|override
name|bool
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
specifier|override
function_decl|;
DECL|member|override
name|bool
name|visitBranch
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBranch
modifier|*
name|node
parameter_list|)
specifier|override
function_decl|;
DECL|member|override
name|bool
name|visitBinary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBinary
modifier|*
name|node
parameter_list|)
specifier|override
function_decl|;
DECL|member|mInFunctionWithArrayReturnValue
name|bool
name|mInFunctionWithArrayReturnValue
decl_stmt|;
block|}
class|;
DECL|function|apply
name|void
name|ArrayReturnValueToOutParameterTraverser
operator|::
name|apply
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|,
name|unsigned
name|int
modifier|*
name|temporaryIndex
parameter_list|)
block|{
name|ArrayReturnValueToOutParameterTraverser
name|arrayReturnValueToOutParam
decl_stmt|;
name|arrayReturnValueToOutParam
operator|.
name|useTemporaryIndex
argument_list|(
name|temporaryIndex
argument_list|)
expr_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|arrayReturnValueToOutParam
argument_list|)
expr_stmt|;
name|arrayReturnValueToOutParam
operator|.
name|updateTree
argument_list|()
expr_stmt|;
block|}
DECL|function|ArrayReturnValueToOutParameterTraverser
name|ArrayReturnValueToOutParameterTraverser
operator|::
name|ArrayReturnValueToOutParameterTraverser
parameter_list|()
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|,
literal|true
argument_list|)
member_init_list|,
name|mInFunctionWithArrayReturnValue
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|visitAggregate
name|bool
name|ArrayReturnValueToOutParameterTraverser
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
if|if
condition|(
name|visit
operator|==
name|PreVisit
condition|)
block|{
if|if
condition|(
name|node
operator|->
name|isArray
argument_list|()
condition|)
block|{
if|if
condition|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpFunction
condition|)
block|{
comment|// Replace the parameters child node of the function definition with another node
comment|// that has the out parameter added.
comment|// Also set the function to return void.
name|TIntermAggregate
modifier|*
name|params
init|=
name|node
operator|->
name|getSequence
argument_list|()
operator|->
name|front
argument_list|()
operator|->
name|getAsAggregate
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|params
operator|!=
literal|nullptr
operator|&&
name|params
operator|->
name|getOp
argument_list|()
operator|==
name|EOpParameters
argument_list|)
expr_stmt|;
name|TIntermAggregate
modifier|*
name|replacementParams
init|=
operator|new
name|TIntermAggregate
decl_stmt|;
name|replacementParams
operator|->
name|setOp
argument_list|(
name|EOpParameters
argument_list|)
expr_stmt|;
name|CopyAggregateChildren
argument_list|(
name|params
argument_list|,
name|replacementParams
argument_list|)
expr_stmt|;
name|replacementParams
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|CreateReturnValueOutSymbol
argument_list|(
name|node
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|replacementParams
operator|->
name|setLine
argument_list|(
name|params
operator|->
name|getLine
argument_list|()
argument_list|)
expr_stmt|;
name|mReplacements
operator|.
name|push_back
argument_list|(
name|NodeUpdateEntry
argument_list|(
name|node
argument_list|,
name|params
argument_list|,
name|replacementParams
argument_list|,
literal|false
argument_list|)
argument_list|)
expr_stmt|;
name|node
operator|->
name|setType
argument_list|(
name|TType
argument_list|(
name|EbtVoid
argument_list|)
argument_list|)
expr_stmt|;
name|mInFunctionWithArrayReturnValue
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpPrototype
condition|)
block|{
comment|// Replace the whole prototype node with another node that has the out parameter added.
name|TIntermAggregate
modifier|*
name|replacement
init|=
operator|new
name|TIntermAggregate
decl_stmt|;
name|replacement
operator|->
name|setOp
argument_list|(
name|EOpPrototype
argument_list|)
expr_stmt|;
name|CopyAggregateChildren
argument_list|(
name|node
argument_list|,
name|replacement
argument_list|)
expr_stmt|;
name|replacement
operator|->
name|getSequence
argument_list|()
operator|->
name|push_back
argument_list|(
name|CreateReturnValueOutSymbol
argument_list|(
name|node
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|replacement
operator|->
name|setUserDefined
argument_list|()
expr_stmt|;
name|replacement
operator|->
name|setNameObj
argument_list|(
name|node
operator|->
name|getNameObj
argument_list|()
argument_list|)
expr_stmt|;
name|replacement
operator|->
name|setFunctionId
argument_list|(
name|node
operator|->
name|getFunctionId
argument_list|()
argument_list|)
expr_stmt|;
name|replacement
operator|->
name|setLine
argument_list|(
name|node
operator|->
name|getLine
argument_list|()
argument_list|)
expr_stmt|;
name|replacement
operator|->
name|setType
argument_list|(
name|TType
argument_list|(
name|EbtVoid
argument_list|)
argument_list|)
expr_stmt|;
name|mReplacements
operator|.
name|push_back
argument_list|(
name|NodeUpdateEntry
argument_list|(
name|getParentNode
argument_list|()
argument_list|,
name|node
argument_list|,
name|replacement
argument_list|,
literal|false
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpFunctionCall
condition|)
block|{
comment|// Handle call sites where the returned array is not assigned.
comment|// Examples where f() is a function returning an array:
comment|// 1. f();
comment|// 2. another_array == f();
comment|// 3. another_function(f());
comment|// 4. return f();
comment|// Cases 2 to 4 are already converted to simpler cases by SeparateExpressionsReturningArrays, so we
comment|// only need to worry about the case where a function call returning an array forms an expression by
comment|// itself.
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
if|if
condition|(
name|parentAgg
operator|!=
literal|nullptr
operator|&&
name|parentAgg
operator|->
name|getOp
argument_list|()
operator|==
name|EOpSequence
condition|)
block|{
name|nextTemporaryIndex
argument_list|()
expr_stmt|;
name|TIntermSequence
name|replacements
decl_stmt|;
name|replacements
operator|.
name|push_back
argument_list|(
name|createTempDeclaration
argument_list|(
name|node
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|TIntermSymbol
modifier|*
name|returnSymbol
init|=
name|createTempSymbol
argument_list|(
name|node
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
name|replacements
operator|.
name|push_back
argument_list|(
name|CreateReplacementCall
argument_list|(
name|node
argument_list|,
name|returnSymbol
argument_list|)
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
name|replacements
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|visit
operator|==
name|PostVisit
condition|)
block|{
if|if
condition|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpFunction
condition|)
block|{
name|mInFunctionWithArrayReturnValue
operator|=
literal|false
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
DECL|function|visitBranch
name|bool
name|ArrayReturnValueToOutParameterTraverser
operator|::
name|visitBranch
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermBranch
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|mInFunctionWithArrayReturnValue
operator|&&
name|node
operator|->
name|getFlowOp
argument_list|()
operator|==
name|EOpReturn
condition|)
block|{
comment|// Instead of returning a value, assign to the out parameter and then return.
name|TIntermSequence
name|replacements
decl_stmt|;
name|TIntermBinary
modifier|*
name|replacementAssignment
init|=
operator|new
name|TIntermBinary
argument_list|(
name|EOpAssign
argument_list|)
decl_stmt|;
name|TIntermTyped
modifier|*
name|expression
init|=
name|node
operator|->
name|getExpression
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|expression
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|replacementAssignment
operator|->
name|setLeft
argument_list|(
name|CreateReturnValueSymbol
argument_list|(
name|expression
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|replacementAssignment
operator|->
name|setRight
argument_list|(
name|node
operator|->
name|getExpression
argument_list|()
argument_list|)
expr_stmt|;
name|replacementAssignment
operator|->
name|setType
argument_list|(
name|expression
operator|->
name|getType
argument_list|()
argument_list|)
expr_stmt|;
name|replacementAssignment
operator|->
name|setLine
argument_list|(
name|expression
operator|->
name|getLine
argument_list|()
argument_list|)
expr_stmt|;
name|replacements
operator|.
name|push_back
argument_list|(
name|replacementAssignment
argument_list|)
expr_stmt|;
name|TIntermBranch
modifier|*
name|replacementBranch
init|=
operator|new
name|TIntermBranch
argument_list|(
name|EOpReturn
argument_list|,
literal|nullptr
argument_list|)
decl_stmt|;
name|replacementBranch
operator|->
name|setLine
argument_list|(
name|node
operator|->
name|getLine
argument_list|()
argument_list|)
expr_stmt|;
name|replacements
operator|.
name|push_back
argument_list|(
name|replacementBranch
argument_list|)
expr_stmt|;
name|mMultiReplacements
operator|.
name|push_back
argument_list|(
name|NodeReplaceWithMultipleEntry
argument_list|(
name|getParentNode
argument_list|()
operator|->
name|getAsAggregate
argument_list|()
argument_list|,
name|node
argument_list|,
name|replacements
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|visitBinary
name|bool
name|ArrayReturnValueToOutParameterTraverser
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
if|if
condition|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpAssign
operator|&&
name|node
operator|->
name|getLeft
argument_list|()
operator|->
name|isArray
argument_list|()
condition|)
block|{
name|TIntermAggregate
modifier|*
name|rightAgg
init|=
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|getAsAggregate
argument_list|()
decl_stmt|;
if|if
condition|(
name|rightAgg
operator|!=
literal|nullptr
operator|&&
name|rightAgg
operator|->
name|getOp
argument_list|()
operator|==
name|EOpFunctionCall
operator|&&
name|rightAgg
operator|->
name|isUserDefined
argument_list|()
condition|)
block|{
name|TIntermAggregate
modifier|*
name|replacementCall
init|=
name|CreateReplacementCall
argument_list|(
name|rightAgg
argument_list|,
name|node
operator|->
name|getLeft
argument_list|()
argument_list|)
decl_stmt|;
name|mReplacements
operator|.
name|push_back
argument_list|(
name|NodeUpdateEntry
argument_list|(
name|getParentNode
argument_list|()
argument_list|,
name|node
argument_list|,
name|replacementCall
argument_list|,
literal|false
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
return|return
literal|false
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace
end_comment
begin_function
DECL|function|ArrayReturnValueToOutParameter
name|void
name|ArrayReturnValueToOutParameter
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|,
name|unsigned
name|int
modifier|*
name|temporaryIndex
parameter_list|)
block|{
name|ArrayReturnValueToOutParameterTraverser
operator|::
name|apply
argument_list|(
name|root
argument_list|,
name|temporaryIndex
argument_list|)
expr_stmt|;
block|}
end_function
end_unit