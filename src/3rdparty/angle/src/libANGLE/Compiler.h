begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// Compiler.h: Defines the gl::Compiler class, abstracting the ESSL compiler
end_comment
begin_comment
comment|// that a GL context holds.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_COMPILER_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_COMPILER_H_
define|#
directive|define
name|LIBANGLE_COMPILER_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|CompilerImpl
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Compiler
name|final
block|{
name|public
label|:
name|explicit
name|Compiler
argument_list|(
name|rx
operator|::
name|CompilerImpl
operator|*
name|impl
argument_list|)
decl_stmt|;
operator|~
name|Compiler
argument_list|()
expr_stmt|;
name|Error
name|release
parameter_list|()
function_decl|;
name|rx
operator|::
name|CompilerImpl
operator|*
name|getImplementation
argument_list|()
expr_stmt|;
name|private
label|:
name|rx
operator|::
name|CompilerImpl
operator|*
name|mCompiler
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_COMPILER_H_
end_comment
end_unit
