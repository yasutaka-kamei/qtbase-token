begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// UnfoldShortCircuit is an AST traverser to output short-circuiting operators as if-else statements.
end_comment
begin_comment
comment|// The results are assigned to s# temporaries, which are used by the main translator instead of
end_comment
begin_comment
comment|// the original expression.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/UnfoldShortCircuit.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InfoSink.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/OutputHLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/UtilsHLSL.h"
end_include
begin_namespace
DECL|namespace|sh
namespace|namespace
name|sh
block|{
DECL|function|UnfoldShortCircuit
name|UnfoldShortCircuit
operator|::
name|UnfoldShortCircuit
parameter_list|(
name|OutputHLSL
modifier|*
name|outputHLSL
parameter_list|)
member_init_list|:
name|mOutputHLSL
argument_list|(
name|outputHLSL
argument_list|)
block|{
name|mTemporaryIndex
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|traverse
name|void
name|UnfoldShortCircuit
operator|::
name|traverse
parameter_list|(
name|TIntermNode
modifier|*
name|node
parameter_list|)
block|{
name|int
name|rewindIndex
init|=
name|mTemporaryIndex
decl_stmt|;
name|node
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mTemporaryIndex
operator|=
name|rewindIndex
expr_stmt|;
block|}
DECL|function|visitBinary
name|bool
name|UnfoldShortCircuit
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
name|TInfoSinkBase
modifier|&
name|out
init|=
name|mOutputHLSL
operator|->
name|getInfoSink
argument_list|()
decl_stmt|;
comment|// If our right node doesn't have side effects, we know we don't need to unfold this
comment|// expression: there will be no short-circuiting side effects to avoid
comment|// (note: unfolding doesn't depend on the left node -- it will always be evaluated)
if|if
condition|(
operator|!
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|hasSideEffects
argument_list|()
condition|)
block|{
return|return
literal|true
return|;
block|}
switch|switch
condition|(
name|node
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpLogicalOr
case|:
comment|// "x || y" is equivalent to "x ? true : y", which unfolds to "bool s; if(x) s = true; else s = y;",
comment|// and then further simplifies down to "bool s = x; if(!s) s = y;".
block|{
name|int
name|i
init|=
name|mTemporaryIndex
decl_stmt|;
name|out
operator|<<
literal|"bool s"
operator|<<
name|i
operator|<<
literal|";\n"
expr_stmt|;
name|out
operator|<<
literal|"{\n"
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getLeft
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|"s"
operator|<<
name|i
operator|<<
literal|" = "
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getLeft
argument_list|()
operator|->
name|traverse
argument_list|(
name|mOutputHLSL
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|";\n"
expr_stmt|;
name|out
operator|<<
literal|"if (!s"
operator|<<
name|i
operator|<<
literal|")\n"
literal|"{\n"
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|"    s"
operator|<<
name|i
operator|<<
literal|" = "
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|traverse
argument_list|(
name|mOutputHLSL
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|";\n"
literal|"}\n"
expr_stmt|;
name|out
operator|<<
literal|"}\n"
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
block|}
return|return
literal|false
return|;
case|case
name|EOpLogicalAnd
case|:
comment|// "x&& y" is equivalent to "x ? y : false", which unfolds to "bool s; if(x) s = y; else s = false;",
comment|// and then further simplifies down to "bool s = x; if(s) s = y;".
block|{
name|int
name|i
init|=
name|mTemporaryIndex
decl_stmt|;
name|out
operator|<<
literal|"bool s"
operator|<<
name|i
operator|<<
literal|";\n"
expr_stmt|;
name|out
operator|<<
literal|"{\n"
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getLeft
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|"s"
operator|<<
name|i
operator|<<
literal|" = "
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getLeft
argument_list|()
operator|->
name|traverse
argument_list|(
name|mOutputHLSL
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|";\n"
expr_stmt|;
name|out
operator|<<
literal|"if (s"
operator|<<
name|i
operator|<<
literal|")\n"
literal|"{\n"
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|"    s"
operator|<<
name|i
operator|<<
literal|" = "
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getRight
argument_list|()
operator|->
name|traverse
argument_list|(
name|mOutputHLSL
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|";\n"
literal|"}\n"
expr_stmt|;
name|out
operator|<<
literal|"}\n"
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
block|}
return|return
literal|false
return|;
default|default:
return|return
literal|true
return|;
block|}
block|}
DECL|function|visitSelection
name|bool
name|UnfoldShortCircuit
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
name|TInfoSinkBase
modifier|&
name|out
init|=
name|mOutputHLSL
operator|->
name|getInfoSink
argument_list|()
decl_stmt|;
comment|// Unfold "b ? x : y" into "type s; if(b) s = x; else s = y;"
if|if
condition|(
name|node
operator|->
name|usesTernaryOperator
argument_list|()
condition|)
block|{
name|int
name|i
init|=
name|mTemporaryIndex
decl_stmt|;
name|out
operator|<<
name|TypeString
argument_list|(
name|node
operator|->
name|getType
argument_list|()
argument_list|)
operator|<<
literal|" s"
operator|<<
name|i
operator|<<
literal|";\n"
expr_stmt|;
name|out
operator|<<
literal|"{\n"
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getCondition
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|"if ("
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getCondition
argument_list|()
operator|->
name|traverse
argument_list|(
name|mOutputHLSL
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|")\n"
literal|"{\n"
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getTrueBlock
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|"    s"
operator|<<
name|i
operator|<<
literal|" = "
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getTrueBlock
argument_list|()
operator|->
name|traverse
argument_list|(
name|mOutputHLSL
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|";\n"
literal|"}\n"
literal|"else\n"
literal|"{\n"
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getFalseBlock
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|"    s"
operator|<<
name|i
operator|<<
literal|" = "
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
name|node
operator|->
name|getFalseBlock
argument_list|()
operator|->
name|traverse
argument_list|(
name|mOutputHLSL
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|";\n"
literal|"}\n"
expr_stmt|;
name|out
operator|<<
literal|"}\n"
expr_stmt|;
name|mTemporaryIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|visitLoop
name|bool
name|UnfoldShortCircuit
operator|::
name|visitLoop
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermLoop
modifier|*
name|node
parameter_list|)
block|{
name|int
name|rewindIndex
init|=
name|mTemporaryIndex
decl_stmt|;
if|if
condition|(
name|node
operator|->
name|getInit
argument_list|()
condition|)
block|{
name|node
operator|->
name|getInit
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|node
operator|->
name|getCondition
argument_list|()
condition|)
block|{
name|node
operator|->
name|getCondition
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|node
operator|->
name|getExpression
argument_list|()
condition|)
block|{
name|node
operator|->
name|getExpression
argument_list|()
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
name|mTemporaryIndex
operator|=
name|rewindIndex
expr_stmt|;
return|return
literal|false
return|;
block|}
DECL|function|getNextTemporaryIndex
name|int
name|UnfoldShortCircuit
operator|::
name|getNextTemporaryIndex
parameter_list|()
block|{
return|return
name|mTemporaryIndex
operator|++
return|;
block|}
block|}
end_namespace
end_unit
