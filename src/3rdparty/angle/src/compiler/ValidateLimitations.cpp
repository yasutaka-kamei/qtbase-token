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
file|"compiler/ValidateLimitations.h"
end_include
begin_include
include|#
directive|include
file|"compiler/InfoSink.h"
end_include
begin_include
include|#
directive|include
file|"compiler/InitializeParseContext.h"
end_include
begin_include
include|#
directive|include
file|"compiler/ParseHelper.h"
end_include
begin_namespace
namespace|namespace
block|{
DECL|function|IsLoopIndex
name|bool
name|IsLoopIndex
parameter_list|(
specifier|const
name|TIntermSymbol
modifier|*
name|symbol
parameter_list|,
specifier|const
name|TLoopStack
modifier|&
name|stack
parameter_list|)
block|{
for|for
control|(
name|TLoopStack
operator|::
name|const_iterator
name|i
init|=
name|stack
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|stack
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|->
name|index
operator|.
name|id
operator|==
name|symbol
operator|->
name|getId
argument_list|()
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|MarkLoopForUnroll
name|void
name|MarkLoopForUnroll
parameter_list|(
specifier|const
name|TIntermSymbol
modifier|*
name|symbol
parameter_list|,
name|TLoopStack
modifier|&
name|stack
parameter_list|)
block|{
for|for
control|(
name|TLoopStack
operator|::
name|iterator
name|i
init|=
name|stack
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|stack
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|->
name|index
operator|.
name|id
operator|==
name|symbol
operator|->
name|getId
argument_list|()
condition|)
block|{
name|ASSERT
argument_list|(
name|i
operator|->
name|loop
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|i
operator|->
name|loop
operator|->
name|setUnrollFlag
argument_list|(
literal|true
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
comment|// Traverses a node to check if it represents a constant index expression.
comment|// Definition:
comment|// constant-index-expressions are a superset of constant-expressions.
comment|// Constant-index-expressions can include loop indices as defined in
comment|// GLSL ES 1.0 spec, Appendix A, section 4.
comment|// The following are constant-index-expressions:
comment|// - Constant expressions
comment|// - Loop indices as defined in section 4
comment|// - Expressions composed of both of the above
DECL|class|ValidateConstIndexExpr
class|class
name|ValidateConstIndexExpr
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
DECL|function|ValidateConstIndexExpr
name|ValidateConstIndexExpr
parameter_list|(
specifier|const
name|TLoopStack
modifier|&
name|stack
parameter_list|)
member_init_list|:
name|mValid
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|mLoopStack
argument_list|(
name|stack
argument_list|)
block|{}
comment|// Returns true if the parsed node represents a constant index expression.
DECL|function|isValid
name|bool
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|mValid
return|;
block|}
DECL|function|visitSymbol
specifier|virtual
name|void
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
name|symbol
parameter_list|)
block|{
comment|// Only constants and loop indices are allowed in a
comment|// constant index expression.
if|if
condition|(
name|mValid
condition|)
block|{
name|mValid
operator|=
operator|(
name|symbol
operator|->
name|getQualifier
argument_list|()
operator|==
name|EvqConst
operator|)
operator|||
name|IsLoopIndex
argument_list|(
name|symbol
argument_list|,
name|mLoopStack
argument_list|)
expr_stmt|;
block|}
block|}
private|private:
DECL|member|mValid
name|bool
name|mValid
decl_stmt|;
DECL|member|mLoopStack
specifier|const
name|TLoopStack
modifier|&
name|mLoopStack
decl_stmt|;
block|}
class|;
comment|// Traverses a node to check if it uses a loop index.
comment|// If an int loop index is used in its body as a sampler array index,
comment|// mark the loop for unroll.
DECL|class|ValidateLoopIndexExpr
class|class
name|ValidateLoopIndexExpr
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
DECL|function|ValidateLoopIndexExpr
name|ValidateLoopIndexExpr
parameter_list|(
name|TLoopStack
modifier|&
name|stack
parameter_list|)
member_init_list|:
name|mUsesFloatLoopIndex
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mUsesIntLoopIndex
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mLoopStack
argument_list|(
name|stack
argument_list|)
block|{}
DECL|function|usesFloatLoopIndex
name|bool
name|usesFloatLoopIndex
parameter_list|()
specifier|const
block|{
return|return
name|mUsesFloatLoopIndex
return|;
block|}
DECL|function|usesIntLoopIndex
name|bool
name|usesIntLoopIndex
parameter_list|()
specifier|const
block|{
return|return
name|mUsesIntLoopIndex
return|;
block|}
DECL|function|visitSymbol
specifier|virtual
name|void
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
name|symbol
parameter_list|)
block|{
if|if
condition|(
name|IsLoopIndex
argument_list|(
name|symbol
argument_list|,
name|mLoopStack
argument_list|)
condition|)
block|{
switch|switch
condition|(
name|symbol
operator|->
name|getBasicType
argument_list|()
condition|)
block|{
case|case
name|EbtFloat
case|:
name|mUsesFloatLoopIndex
operator|=
literal|true
expr_stmt|;
break|break;
case|case
name|EbtInt
case|:
name|mUsesIntLoopIndex
operator|=
literal|true
expr_stmt|;
name|MarkLoopForUnroll
argument_list|(
name|symbol
argument_list|,
name|mLoopStack
argument_list|)
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
block|}
private|private:
DECL|member|mUsesFloatLoopIndex
name|bool
name|mUsesFloatLoopIndex
decl_stmt|;
DECL|member|mUsesIntLoopIndex
name|bool
name|mUsesIntLoopIndex
decl_stmt|;
DECL|member|mLoopStack
name|TLoopStack
modifier|&
name|mLoopStack
decl_stmt|;
block|}
class|;
block|}
end_namespace
begin_comment
comment|// namespace
end_comment
begin_constructor
DECL|function|ValidateLimitations
name|ValidateLimitations
operator|::
name|ValidateLimitations
parameter_list|(
name|ShShaderType
name|shaderType
parameter_list|,
name|TInfoSinkBase
modifier|&
name|sink
parameter_list|)
member_init_list|:
name|mShaderType
argument_list|(
name|shaderType
argument_list|)
member_init_list|,
name|mSink
argument_list|(
name|sink
argument_list|)
member_init_list|,
name|mNumErrors
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|visitBinary
name|bool
name|ValidateLimitations
operator|::
name|visitBinary
parameter_list|(
name|Visit
parameter_list|,
name|TIntermBinary
modifier|*
name|node
parameter_list|)
block|{
comment|// Check if loop index is modified in the loop body.
name|validateOperation
argument_list|(
name|node
argument_list|,
name|node
operator|->
name|getLeft
argument_list|()
argument_list|)
expr_stmt|;
comment|// Check indexing.
switch|switch
condition|(
name|node
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpIndexDirect
case|:
name|validateIndexing
argument_list|(
name|node
argument_list|)
expr_stmt|;
break|break;
case|case
name|EOpIndexIndirect
case|:
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
comment|// Loop unrolling is a work-around for a Mac Cg compiler bug where it
comment|// crashes when a sampler array's index is also the loop index.
comment|// Once Apple fixes this bug, we should remove the code in this CL.
comment|// See http://codereview.appspot.com/4331048/.
if|if
condition|(
operator|(
name|node
operator|->
name|getLeft
argument_list|()
operator|!=
name|NULL
operator|)
operator|&&
operator|(
name|node
operator|->
name|getRight
argument_list|()
operator|!=
name|NULL
operator|)
operator|&&
operator|(
name|node
operator|->
name|getLeft
argument_list|()
operator|->
name|getAsSymbolNode
argument_list|()
operator|)
condition|)
block|{
name|TIntermSymbol
modifier|*
name|symbol
init|=
name|node
operator|->
name|getLeft
argument_list|()
operator|->
name|getAsSymbolNode
argument_list|()
decl_stmt|;
if|if
condition|(
name|IsSampler
argument_list|(
name|symbol
operator|->
name|getBasicType
argument_list|()
argument_list|)
operator|&&
name|symbol
operator|->
name|isArray
argument_list|()
condition|)
block|{
name|ValidateLoopIndexExpr
name|validate
argument_list|(
name|mLoopStack
argument_list|)
decl_stmt|;
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|traverse
argument_list|(
operator|&
name|validate
argument_list|)
expr_stmt|;
if|if
condition|(
name|validate
operator|.
name|usesFloatLoopIndex
argument_list|()
condition|)
block|{
name|error
argument_list|(
name|node
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"sampler array index is float loop index"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
endif|#
directive|endif
name|validateIndexing
argument_list|(
name|node
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|visitUnary
name|bool
name|ValidateLimitations
operator|::
name|visitUnary
parameter_list|(
name|Visit
parameter_list|,
name|TIntermUnary
modifier|*
name|node
parameter_list|)
block|{
comment|// Check if loop index is modified in the loop body.
name|validateOperation
argument_list|(
name|node
argument_list|,
name|node
operator|->
name|getOperand
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|visitAggregate
name|bool
name|ValidateLimitations
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
switch|switch
condition|(
name|node
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpFunctionCall
case|:
name|validateFunctionCall
argument_list|(
name|node
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|visitLoop
name|bool
name|ValidateLimitations
operator|::
name|visitLoop
parameter_list|(
name|Visit
parameter_list|,
name|TIntermLoop
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
operator|!
name|validateLoopType
argument_list|(
name|node
argument_list|)
condition|)
return|return
literal|false
return|;
name|TLoopInfo
name|info
decl_stmt|;
name|memset
argument_list|(
operator|&
name|info
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|TLoopInfo
argument_list|)
argument_list|)
expr_stmt|;
name|info
operator|.
name|loop
operator|=
name|node
expr_stmt|;
if|if
condition|(
operator|!
name|validateForLoopHeader
argument_list|(
name|node
argument_list|,
operator|&
name|info
argument_list|)
condition|)
return|return
literal|false
return|;
name|TIntermNode
modifier|*
name|body
init|=
name|node
operator|->
name|getBody
argument_list|()
decl_stmt|;
if|if
condition|(
name|body
operator|!=
name|NULL
condition|)
block|{
name|mLoopStack
operator|.
name|push_back
argument_list|(
name|info
argument_list|)
expr_stmt|;
name|body
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mLoopStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
comment|// The loop is fully processed - no need to visit children.
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|error
name|void
name|ValidateLimitations
operator|::
name|error
parameter_list|(
name|TSourceLoc
name|loc
parameter_list|,
specifier|const
name|char
modifier|*
name|reason
parameter_list|,
specifier|const
name|char
modifier|*
name|token
parameter_list|)
block|{
name|mSink
operator|.
name|prefix
argument_list|(
name|EPrefixError
argument_list|)
expr_stmt|;
name|mSink
operator|.
name|location
argument_list|(
name|loc
argument_list|)
expr_stmt|;
name|mSink
operator|<<
literal|"'"
operator|<<
name|token
operator|<<
literal|"' : "
operator|<<
name|reason
operator|<<
literal|"\n"
expr_stmt|;
operator|++
name|mNumErrors
expr_stmt|;
block|}
end_function
begin_function
DECL|function|withinLoopBody
name|bool
name|ValidateLimitations
operator|::
name|withinLoopBody
parameter_list|()
specifier|const
block|{
return|return
operator|!
name|mLoopStack
operator|.
name|empty
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isLoopIndex
name|bool
name|ValidateLimitations
operator|::
name|isLoopIndex
parameter_list|(
specifier|const
name|TIntermSymbol
modifier|*
name|symbol
parameter_list|)
specifier|const
block|{
return|return
name|IsLoopIndex
argument_list|(
name|symbol
argument_list|,
name|mLoopStack
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|validateLoopType
name|bool
name|ValidateLimitations
operator|::
name|validateLoopType
parameter_list|(
name|TIntermLoop
modifier|*
name|node
parameter_list|)
block|{
name|TLoopType
name|type
init|=
name|node
operator|->
name|getType
argument_list|()
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|ELoopFor
condition|)
return|return
literal|true
return|;
comment|// Reject while and do-while loops.
name|error
argument_list|(
name|node
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"This type of loop is not allowed"
argument_list|,
name|type
operator|==
name|ELoopWhile
condition|?
literal|"while"
else|:
literal|"do"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|validateForLoopHeader
name|bool
name|ValidateLimitations
operator|::
name|validateForLoopHeader
parameter_list|(
name|TIntermLoop
modifier|*
name|node
parameter_list|,
name|TLoopInfo
modifier|*
name|info
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|node
operator|->
name|getType
argument_list|()
operator|==
name|ELoopFor
argument_list|)
expr_stmt|;
comment|//
comment|// The for statement has the form:
comment|//    for ( init-declaration ; condition ; expression ) statement
comment|//
if|if
condition|(
operator|!
name|validateForLoopInit
argument_list|(
name|node
argument_list|,
name|info
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|validateForLoopCond
argument_list|(
name|node
argument_list|,
name|info
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|validateForLoopExpr
argument_list|(
name|node
argument_list|,
name|info
argument_list|)
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|validateForLoopInit
name|bool
name|ValidateLimitations
operator|::
name|validateForLoopInit
parameter_list|(
name|TIntermLoop
modifier|*
name|node
parameter_list|,
name|TLoopInfo
modifier|*
name|info
parameter_list|)
block|{
name|TIntermNode
modifier|*
name|init
init|=
name|node
operator|->
name|getInit
argument_list|()
decl_stmt|;
if|if
condition|(
name|init
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
name|node
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Missing init declaration"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|//
comment|// init-declaration has the form:
comment|//     type-specifier identifier = constant-expression
comment|//
name|TIntermAggregate
modifier|*
name|decl
init|=
name|init
operator|->
name|getAsAggregate
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|decl
operator|==
name|NULL
operator|)
operator|||
operator|(
name|decl
operator|->
name|getOp
argument_list|()
operator|!=
name|EOpDeclaration
operator|)
condition|)
block|{
name|error
argument_list|(
name|init
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Invalid init declaration"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// To keep things simple do not allow declaration list.
name|TIntermSequence
modifier|&
name|declSeq
init|=
name|decl
operator|->
name|getSequence
argument_list|()
decl_stmt|;
if|if
condition|(
name|declSeq
operator|.
name|size
argument_list|()
operator|!=
literal|1
condition|)
block|{
name|error
argument_list|(
name|decl
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Invalid init declaration"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|TIntermBinary
modifier|*
name|declInit
init|=
name|declSeq
index|[
literal|0
index|]
operator|->
name|getAsBinaryNode
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|declInit
operator|==
name|NULL
operator|)
operator|||
operator|(
name|declInit
operator|->
name|getOp
argument_list|()
operator|!=
name|EOpInitialize
operator|)
condition|)
block|{
name|error
argument_list|(
name|decl
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Invalid init declaration"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|TIntermSymbol
modifier|*
name|symbol
init|=
name|declInit
operator|->
name|getLeft
argument_list|()
operator|->
name|getAsSymbolNode
argument_list|()
decl_stmt|;
if|if
condition|(
name|symbol
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
name|declInit
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Invalid init declaration"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// The loop index has type int or float.
name|TBasicType
name|type
init|=
name|symbol
operator|->
name|getBasicType
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|type
operator|!=
name|EbtInt
operator|)
operator|&&
operator|(
name|type
operator|!=
name|EbtFloat
operator|)
condition|)
block|{
name|error
argument_list|(
name|symbol
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Invalid type for loop index"
argument_list|,
name|getBasicString
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// The loop index is initialized with constant expression.
if|if
condition|(
operator|!
name|isConstExpr
argument_list|(
name|declInit
operator|->
name|getRight
argument_list|()
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|declInit
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Loop index cannot be initialized with non-constant expression"
argument_list|,
name|symbol
operator|->
name|getSymbol
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|info
operator|->
name|index
operator|.
name|id
operator|=
name|symbol
operator|->
name|getId
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|validateForLoopCond
name|bool
name|ValidateLimitations
operator|::
name|validateForLoopCond
parameter_list|(
name|TIntermLoop
modifier|*
name|node
parameter_list|,
name|TLoopInfo
modifier|*
name|info
parameter_list|)
block|{
name|TIntermNode
modifier|*
name|cond
init|=
name|node
operator|->
name|getCondition
argument_list|()
decl_stmt|;
if|if
condition|(
name|cond
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
name|node
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Missing condition"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|//
comment|// condition has the form:
comment|//     loop_index relational_operator constant_expression
comment|//
name|TIntermBinary
modifier|*
name|binOp
init|=
name|cond
operator|->
name|getAsBinaryNode
argument_list|()
decl_stmt|;
if|if
condition|(
name|binOp
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
name|node
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Invalid condition"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Loop index should be to the left of relational operator.
name|TIntermSymbol
modifier|*
name|symbol
init|=
name|binOp
operator|->
name|getLeft
argument_list|()
operator|->
name|getAsSymbolNode
argument_list|()
decl_stmt|;
if|if
condition|(
name|symbol
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
name|binOp
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Invalid condition"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|symbol
operator|->
name|getId
argument_list|()
operator|!=
name|info
operator|->
name|index
operator|.
name|id
condition|)
block|{
name|error
argument_list|(
name|symbol
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Expected loop index"
argument_list|,
name|symbol
operator|->
name|getSymbol
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Relational operator is one of:>>=<<= == or !=.
switch|switch
condition|(
name|binOp
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpEqual
case|:
case|case
name|EOpNotEqual
case|:
case|case
name|EOpLessThan
case|:
case|case
name|EOpGreaterThan
case|:
case|case
name|EOpLessThanEqual
case|:
case|case
name|EOpGreaterThanEqual
case|:
break|break;
default|default:
name|error
argument_list|(
name|binOp
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Invalid relational operator"
argument_list|,
name|getOperatorString
argument_list|(
name|binOp
operator|->
name|getOp
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
comment|// Loop index must be compared with a constant.
if|if
condition|(
operator|!
name|isConstExpr
argument_list|(
name|binOp
operator|->
name|getRight
argument_list|()
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|binOp
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Loop index cannot be compared with non-constant expression"
argument_list|,
name|symbol
operator|->
name|getSymbol
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|validateForLoopExpr
name|bool
name|ValidateLimitations
operator|::
name|validateForLoopExpr
parameter_list|(
name|TIntermLoop
modifier|*
name|node
parameter_list|,
name|TLoopInfo
modifier|*
name|info
parameter_list|)
block|{
name|TIntermNode
modifier|*
name|expr
init|=
name|node
operator|->
name|getExpression
argument_list|()
decl_stmt|;
if|if
condition|(
name|expr
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
name|node
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Missing expression"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// for expression has one of the following forms:
comment|//     loop_index++
comment|//     loop_index--
comment|//     loop_index += constant_expression
comment|//     loop_index -= constant_expression
comment|//     ++loop_index
comment|//     --loop_index
comment|// The last two forms are not specified in the spec, but I am assuming
comment|// its an oversight.
name|TIntermUnary
modifier|*
name|unOp
init|=
name|expr
operator|->
name|getAsUnaryNode
argument_list|()
decl_stmt|;
name|TIntermBinary
modifier|*
name|binOp
init|=
name|unOp
condition|?
name|NULL
else|:
name|expr
operator|->
name|getAsBinaryNode
argument_list|()
decl_stmt|;
name|TOperator
name|op
init|=
name|EOpNull
decl_stmt|;
name|TIntermSymbol
modifier|*
name|symbol
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|unOp
operator|!=
name|NULL
condition|)
block|{
name|op
operator|=
name|unOp
operator|->
name|getOp
argument_list|()
expr_stmt|;
name|symbol
operator|=
name|unOp
operator|->
name|getOperand
argument_list|()
operator|->
name|getAsSymbolNode
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|binOp
operator|!=
name|NULL
condition|)
block|{
name|op
operator|=
name|binOp
operator|->
name|getOp
argument_list|()
expr_stmt|;
name|symbol
operator|=
name|binOp
operator|->
name|getLeft
argument_list|()
operator|->
name|getAsSymbolNode
argument_list|()
expr_stmt|;
block|}
comment|// The operand must be loop index.
if|if
condition|(
name|symbol
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
name|expr
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Invalid expression"
argument_list|,
literal|"for"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|symbol
operator|->
name|getId
argument_list|()
operator|!=
name|info
operator|->
name|index
operator|.
name|id
condition|)
block|{
name|error
argument_list|(
name|symbol
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Expected loop index"
argument_list|,
name|symbol
operator|->
name|getSymbol
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// The operator is one of: ++ -- += -=.
switch|switch
condition|(
name|op
condition|)
block|{
case|case
name|EOpPostIncrement
case|:
case|case
name|EOpPostDecrement
case|:
case|case
name|EOpPreIncrement
case|:
case|case
name|EOpPreDecrement
case|:
name|ASSERT
argument_list|(
operator|(
name|unOp
operator|!=
name|NULL
operator|)
operator|&&
operator|(
name|binOp
operator|==
name|NULL
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|EOpAddAssign
case|:
case|case
name|EOpSubAssign
case|:
name|ASSERT
argument_list|(
operator|(
name|unOp
operator|==
name|NULL
operator|)
operator|&&
operator|(
name|binOp
operator|!=
name|NULL
operator|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|error
argument_list|(
name|expr
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Invalid operator"
argument_list|,
name|getOperatorString
argument_list|(
name|op
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Loop index must be incremented/decremented with a constant.
if|if
condition|(
name|binOp
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|!
name|isConstExpr
argument_list|(
name|binOp
operator|->
name|getRight
argument_list|()
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|binOp
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Loop index cannot be modified by non-constant expression"
argument_list|,
name|symbol
operator|->
name|getSymbol
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|validateFunctionCall
name|bool
name|ValidateLimitations
operator|::
name|validateFunctionCall
parameter_list|(
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpFunctionCall
argument_list|)
expr_stmt|;
comment|// If not within loop body, there is nothing to check.
if|if
condition|(
operator|!
name|withinLoopBody
argument_list|()
condition|)
return|return
literal|true
return|;
comment|// List of param indices for which loop indices are used as argument.
typedef|typedef
name|std
operator|::
name|vector
argument_list|<
name|int
argument_list|>
name|ParamIndex
typedef|;
name|ParamIndex
name|pIndex
decl_stmt|;
name|TIntermSequence
modifier|&
name|params
init|=
name|node
operator|->
name|getSequence
argument_list|()
decl_stmt|;
for|for
control|(
name|TIntermSequence
operator|::
name|size_type
name|i
init|=
literal|0
init|;
name|i
operator|<
name|params
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|TIntermSymbol
modifier|*
name|symbol
init|=
name|params
index|[
name|i
index|]
operator|->
name|getAsSymbolNode
argument_list|()
decl_stmt|;
if|if
condition|(
name|symbol
operator|&&
name|isLoopIndex
argument_list|(
name|symbol
argument_list|)
condition|)
name|pIndex
operator|.
name|push_back
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
comment|// If none of the loop indices are used as arguments,
comment|// there is nothing to check.
if|if
condition|(
name|pIndex
operator|.
name|empty
argument_list|()
condition|)
return|return
literal|true
return|;
name|bool
name|valid
init|=
literal|true
decl_stmt|;
name|TSymbolTable
modifier|&
name|symbolTable
init|=
name|GlobalParseContext
operator|->
name|symbolTable
decl_stmt|;
name|TSymbol
modifier|*
name|symbol
init|=
name|symbolTable
operator|.
name|find
argument_list|(
name|node
operator|->
name|getName
argument_list|()
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|symbol
operator|&&
name|symbol
operator|->
name|isFunction
argument_list|()
argument_list|)
expr_stmt|;
name|TFunction
modifier|*
name|function
init|=
cast|static_cast
argument_list|<
name|TFunction
operator|*
argument_list|>
argument_list|(
name|symbol
argument_list|)
decl_stmt|;
for|for
control|(
name|ParamIndex
operator|::
name|const_iterator
name|i
init|=
name|pIndex
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|pIndex
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|TParameter
modifier|&
name|param
init|=
name|function
operator|->
name|getParam
argument_list|(
operator|*
name|i
argument_list|)
decl_stmt|;
name|TQualifier
name|qual
init|=
name|param
operator|.
name|type
operator|->
name|getQualifier
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|qual
operator|==
name|EvqOut
operator|)
operator|||
operator|(
name|qual
operator|==
name|EvqInOut
operator|)
condition|)
block|{
name|error
argument_list|(
name|params
index|[
operator|*
name|i
index|]
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Loop index cannot be used as argument to a function out or inout parameter"
argument_list|,
name|params
index|[
operator|*
name|i
index|]
operator|->
name|getAsSymbolNode
argument_list|()
operator|->
name|getSymbol
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
name|valid
operator|=
literal|false
expr_stmt|;
block|}
block|}
return|return
name|valid
return|;
block|}
end_function
begin_function
DECL|function|validateOperation
name|bool
name|ValidateLimitations
operator|::
name|validateOperation
parameter_list|(
name|TIntermOperator
modifier|*
name|node
parameter_list|,
name|TIntermNode
modifier|*
name|operand
parameter_list|)
block|{
comment|// Check if loop index is modified in the loop body.
if|if
condition|(
operator|!
name|withinLoopBody
argument_list|()
operator|||
operator|!
name|node
operator|->
name|modifiesState
argument_list|()
condition|)
return|return
literal|true
return|;
specifier|const
name|TIntermSymbol
modifier|*
name|symbol
init|=
name|operand
operator|->
name|getAsSymbolNode
argument_list|()
decl_stmt|;
if|if
condition|(
name|symbol
operator|&&
name|isLoopIndex
argument_list|(
name|symbol
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|node
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Loop index cannot be statically assigned to within the body of the loop"
argument_list|,
name|symbol
operator|->
name|getSymbol
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|isConstExpr
name|bool
name|ValidateLimitations
operator|::
name|isConstExpr
parameter_list|(
name|TIntermNode
modifier|*
name|node
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|node
operator|!=
name|NULL
argument_list|)
expr_stmt|;
return|return
name|node
operator|->
name|getAsConstantUnion
argument_list|()
operator|!=
name|NULL
return|;
block|}
end_function
begin_function
DECL|function|isConstIndexExpr
name|bool
name|ValidateLimitations
operator|::
name|isConstIndexExpr
parameter_list|(
name|TIntermNode
modifier|*
name|node
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|node
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ValidateConstIndexExpr
name|validate
argument_list|(
name|mLoopStack
argument_list|)
decl_stmt|;
name|node
operator|->
name|traverse
argument_list|(
operator|&
name|validate
argument_list|)
expr_stmt|;
return|return
name|validate
operator|.
name|isValid
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|validateIndexing
name|bool
name|ValidateLimitations
operator|::
name|validateIndexing
parameter_list|(
name|TIntermBinary
modifier|*
name|node
parameter_list|)
block|{
name|ASSERT
argument_list|(
operator|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpIndexDirect
operator|)
operator|||
operator|(
name|node
operator|->
name|getOp
argument_list|()
operator|==
name|EOpIndexIndirect
operator|)
argument_list|)
expr_stmt|;
name|bool
name|valid
init|=
literal|true
decl_stmt|;
name|TIntermTyped
modifier|*
name|index
init|=
name|node
operator|->
name|getRight
argument_list|()
decl_stmt|;
comment|// The index expression must have integral type.
if|if
condition|(
operator|!
name|index
operator|->
name|isScalar
argument_list|()
operator|||
operator|(
name|index
operator|->
name|getBasicType
argument_list|()
operator|!=
name|EbtInt
operator|)
condition|)
block|{
name|error
argument_list|(
name|index
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Index expression must have integral type"
argument_list|,
name|index
operator|->
name|getCompleteString
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
name|valid
operator|=
literal|false
expr_stmt|;
block|}
comment|// The index expession must be a constant-index-expression unless
comment|// the operand is a uniform in a vertex shader.
name|TIntermTyped
modifier|*
name|operand
init|=
name|node
operator|->
name|getLeft
argument_list|()
decl_stmt|;
name|bool
name|skip
init|=
operator|(
name|mShaderType
operator|==
name|SH_VERTEX_SHADER
operator|)
operator|&&
operator|(
name|operand
operator|->
name|getQualifier
argument_list|()
operator|==
name|EvqUniform
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|skip
operator|&&
operator|!
name|isConstIndexExpr
argument_list|(
name|index
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|index
operator|->
name|getLine
argument_list|()
argument_list|,
literal|"Index expression must be constant"
argument_list|,
literal|"[]"
argument_list|)
expr_stmt|;
name|valid
operator|=
literal|false
expr_stmt|;
block|}
return|return
name|valid
return|;
block|}
end_function
end_unit
