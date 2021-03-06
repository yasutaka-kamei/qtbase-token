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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_OUTPUTGLSLBASE_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_OUTPUTGLSLBASE_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_OUTPUTGLSLBASE_H_
end_define
begin_include
include|#
directive|include
file|<set>
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/LoopInfo.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/ParseContext.h"
end_include
begin_decl_stmt
name|class
name|TOutputGLSLBase
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|TOutputGLSLBase
argument_list|(
argument|TInfoSinkBase&objSink
argument_list|,
argument|ShArrayIndexClampingStrategy clampingStrategy
argument_list|,
argument|ShHashFunction64 hashFunction
argument_list|,
argument|NameMap&nameMap
argument_list|,
argument|TSymbolTable& symbolTable
argument_list|,
argument|int shaderVersion
argument_list|,
argument|ShShaderOutput output
argument_list|)
block|;
name|ShShaderOutput
name|getShaderOutput
argument_list|()
specifier|const
block|{
return|return
name|mOutput
return|;
block|}
name|protected
operator|:
name|TInfoSinkBase
operator|&
name|objSink
argument_list|()
block|{
return|return
name|mObjSink
return|;
block|}
name|void
name|writeTriplet
argument_list|(
argument|Visit visit
argument_list|,
argument|const char *preStr
argument_list|,
argument|const char *inStr
argument_list|,
argument|const char *postStr
argument_list|)
block|;
name|void
name|writeLayoutQualifier
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|)
block|;
name|void
name|writeVariableType
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|)
block|;
name|virtual
name|bool
name|writeVariablePrecision
argument_list|(
argument|TPrecision precision
argument_list|)
operator|=
literal|0
block|;
name|void
name|writeFunctionParameters
argument_list|(
specifier|const
name|TIntermSequence
operator|&
name|args
argument_list|)
block|;
specifier|const
name|TConstantUnion
operator|*
name|writeConstantUnion
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|,
specifier|const
name|TConstantUnion
operator|*
name|pConstUnion
argument_list|)
block|;
name|void
name|writeConstructorTriplet
argument_list|(
argument|Visit visit
argument_list|,
argument|const TType&type
argument_list|,
argument|const char *constructorBaseType
argument_list|)
block|;
name|TString
name|getTypeName
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|)
block|;
name|void
name|visitSymbol
argument_list|(
argument|TIntermSymbol *node
argument_list|)
name|override
block|;
name|void
name|visitConstantUnion
argument_list|(
argument|TIntermConstantUnion *node
argument_list|)
name|override
block|;
name|bool
name|visitBinary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBinary *node
argument_list|)
name|override
block|;
name|bool
name|visitUnary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermUnary *node
argument_list|)
name|override
block|;
name|bool
name|visitSelection
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermSelection *node
argument_list|)
name|override
block|;
name|bool
name|visitSwitch
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermSwitch *node
argument_list|)
name|override
block|;
name|bool
name|visitCase
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermCase *node
argument_list|)
name|override
block|;
name|bool
name|visitAggregate
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermAggregate *node
argument_list|)
name|override
block|;
name|bool
name|visitLoop
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermLoop *node
argument_list|)
name|override
block|;
name|bool
name|visitBranch
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBranch *node
argument_list|)
name|override
block|;
name|void
name|visitCodeBlock
argument_list|(
name|TIntermNode
operator|*
name|node
argument_list|)
block|;
comment|// Return the original name if hash function pointer is NULL;
comment|// otherwise return the hashed name.
name|TString
name|hashName
argument_list|(
specifier|const
name|TString
operator|&
name|name
argument_list|)
block|;
comment|// Same as hashName(), but without hashing built-in variables.
name|TString
name|hashVariableName
argument_list|(
specifier|const
name|TString
operator|&
name|name
argument_list|)
block|;
comment|// Same as hashName(), but without hashing built-in functions and with unmangling.
name|TString
name|hashFunctionNameIfNeeded
argument_list|(
specifier|const
name|TName
operator|&
name|mangledName
argument_list|)
block|;
comment|// Used to translate function names for differences between ESSL and GLSL
name|virtual
name|TString
name|translateTextureFunction
argument_list|(
argument|TString&name
argument_list|)
block|{
return|return
name|name
return|;
block|}
name|private
operator|:
name|bool
name|structDeclared
argument_list|(
argument|const TStructure *structure
argument_list|)
specifier|const
block|;
name|void
name|declareStruct
argument_list|(
specifier|const
name|TStructure
operator|*
name|structure
argument_list|)
block|;
name|void
name|declareInterfaceBlockLayout
argument_list|(
specifier|const
name|TInterfaceBlock
operator|*
name|interfaceBlock
argument_list|)
block|;
name|void
name|declareInterfaceBlock
argument_list|(
specifier|const
name|TInterfaceBlock
operator|*
name|interfaceBlock
argument_list|)
block|;
name|void
name|writeBuiltInFunctionTriplet
argument_list|(
argument|Visit visit
argument_list|,
argument|const char *preStr
argument_list|,
argument|bool useEmulatedFunction
argument_list|)
block|;
name|TInfoSinkBase
operator|&
name|mObjSink
block|;
name|bool
name|mDeclaringVariables
block|;
comment|// This set contains all the ids of the structs from every scope.
name|std
operator|::
name|set
operator|<
name|int
operator|>
name|mDeclaredStructs
block|;
comment|// Stack of loops that need to be unrolled.
name|TLoopStack
name|mLoopUnrollStack
block|;
name|ShArrayIndexClampingStrategy
name|mClampingStrategy
block|;
comment|// name hashing.
name|ShHashFunction64
name|mHashFunction
block|;
name|NameMap
operator|&
name|mNameMap
block|;
name|TSymbolTable
operator|&
name|mSymbolTable
block|;
specifier|const
name|int
name|mShaderVersion
block|;
name|ShShaderOutput
name|mOutput
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_OUTPUTGLSLBASE_H_
end_comment
end_unit
