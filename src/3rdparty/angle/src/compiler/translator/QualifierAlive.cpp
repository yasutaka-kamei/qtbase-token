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
file|"compiler/translator/IntermNode.h"
end_include
begin_class
DECL|class|TAliveTraverser
class|class
name|TAliveTraverser
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
DECL|function|TAliveTraverser
name|TAliveTraverser
parameter_list|(
name|TQualifier
name|q
parameter_list|)
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|,
literal|true
argument_list|)
member_init_list|,
name|found
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|qualifier
argument_list|(
name|q
argument_list|)
block|{     }
DECL|function|wasFound
name|bool
name|wasFound
parameter_list|()
block|{
return|return
name|found
return|;
block|}
protected|protected:
DECL|member|found
name|bool
name|found
decl_stmt|;
DECL|member|qualifier
name|TQualifier
name|qualifier
decl_stmt|;
name|void
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
parameter_list|)
function_decl|;
name|bool
name|visitSelection
parameter_list|(
name|Visit
parameter_list|,
name|TIntermSelection
modifier|*
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//
end_comment
begin_comment
comment|// Report whether or not a variable of the given qualifier type
end_comment
begin_comment
comment|// is guaranteed written.  Not always possible to determine if
end_comment
begin_comment
comment|// it is written conditionally.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// ?? It does not do this well yet, this is just a place holder
end_comment
begin_comment
comment|// that simply determines if it was reference at all, anywhere.
end_comment
begin_comment
comment|//
end_comment
begin_function
DECL|function|QualifierWritten
name|bool
name|QualifierWritten
parameter_list|(
name|TIntermNode
modifier|*
name|node
parameter_list|,
name|TQualifier
name|qualifier
parameter_list|)
block|{
name|TAliveTraverser
name|it
argument_list|(
name|qualifier
argument_list|)
decl_stmt|;
if|if
condition|(
name|node
condition|)
name|node
operator|->
name|traverse
argument_list|(
operator|&
name|it
argument_list|)
expr_stmt|;
return|return
name|it
operator|.
name|wasFound
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|visitSymbol
name|void
name|TAliveTraverser
operator|::
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
name|node
parameter_list|)
block|{
comment|//
comment|// If it's what we're looking for, record it.
comment|//
if|if
condition|(
name|node
operator|->
name|getQualifier
argument_list|()
operator|==
name|qualifier
condition|)
name|found
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visitSelection
name|bool
name|TAliveTraverser
operator|::
name|visitSelection
parameter_list|(
name|Visit
parameter_list|,
name|TIntermSelection
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|wasFound
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
end_unit
