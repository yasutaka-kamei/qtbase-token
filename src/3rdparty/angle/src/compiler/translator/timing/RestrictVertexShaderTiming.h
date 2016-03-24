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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_TIMING_RESTRICTVERTEXSHADERTIMING_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_TIMING_RESTRICTVERTEXSHADERTIMING_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_TIMING_RESTRICTVERTEXSHADERTIMING_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InfoSink.h"
end_include
begin_decl_stmt
DECL|variable|TInfoSinkBase
name|class
name|TInfoSinkBase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|RestrictVertexShaderTiming
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|RestrictVertexShaderTiming
argument_list|(
name|TInfoSinkBase
operator|&
name|sink
argument_list|)
operator|:
name|TIntermTraverser
argument_list|(
name|true
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|mSink
argument_list|(
name|sink
argument_list|)
block|,
name|mNumErrors
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|enforceRestrictions
argument_list|(
argument|TIntermNode* root
argument_list|)
block|{
name|root
operator|->
name|traverse
argument_list|(
name|this
argument_list|)
block|; }
name|int
name|numErrors
argument_list|()
block|{
return|return
name|mNumErrors
return|;
block|}
name|void
name|visitSymbol
argument_list|(
argument|TIntermSymbol *
argument_list|)
name|override
block|;
name|private
operator|:
name|TInfoSinkBase
operator|&
name|mSink
block|;
name|int
name|mNumErrors
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_TIMING_RESTRICTVERTEXSHADERTIMING_H_
end_comment
end_unit
