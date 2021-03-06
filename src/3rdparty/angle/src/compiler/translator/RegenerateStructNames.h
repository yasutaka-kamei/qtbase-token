begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_TRANSLATOR_REGENERATESTRUCTNAMES_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_REGENERATESTRUCTNAMES_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_REGENERATESTRUCTNAMES_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/Intermediate.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/SymbolTable.h"
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_decl_stmt
name|class
name|RegenerateStructNames
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|RegenerateStructNames
argument_list|(
argument|const TSymbolTable&symbolTable
argument_list|,
argument|int shaderVersion
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
name|mSymbolTable
argument_list|(
name|symbolTable
argument_list|)
block|,
name|mShaderVersion
argument_list|(
name|shaderVersion
argument_list|)
block|,
name|mScopeDepth
argument_list|(
literal|0
argument_list|)
block|{}
name|protected
operator|:
name|void
name|visitSymbol
argument_list|(
argument|TIntermSymbol *
argument_list|)
name|override
block|;
name|bool
name|visitAggregate
argument_list|(
argument|Visit
argument_list|,
argument|TIntermAggregate *
argument_list|)
name|override
block|;
name|private
operator|:
specifier|const
name|TSymbolTable
operator|&
name|mSymbolTable
block|;
name|int
name|mShaderVersion
block|;
comment|// Indicating the depth of the current scope.
comment|// The global scope is 1.
name|int
name|mScopeDepth
block|;
comment|// If a struct's declared globally, push its ID in this set.
name|std
operator|::
name|set
operator|<
name|int
operator|>
name|mDeclaredGlobalStructs
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_REGENERATESTRUCTNAMES_H_
end_comment
end_unit
