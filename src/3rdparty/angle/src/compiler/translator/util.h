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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_UTIL_H
end_ifndef
begin_define
DECL|macro|COMPILER_UTIL_H
define|#
directive|define
name|COMPILER_UTIL_H
end_define
begin_include
include|#
directive|include
file|<stack>
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|<GLSLANG/ShaderLang.h>
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Types.h"
end_include
begin_comment
comment|// atof_clamp is like atof but
end_comment
begin_comment
comment|//   1. it forces C locale, i.e. forcing '.' as decimal point.
end_comment
begin_comment
comment|//   2. it clamps the value to -FLT_MAX or FLT_MAX if overflow happens.
end_comment
begin_comment
comment|// Return false if overflow happens.
end_comment
begin_function_decl
specifier|extern
name|bool
name|atof_clamp
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|float
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// If overflow happens, clamp the value to INT_MIN or INT_MAX.
end_comment
begin_comment
comment|// Return false if overflow happens.
end_comment
begin_function_decl
specifier|extern
name|bool
name|atoi_clamp
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|TSymbolTable
name|class
name|TSymbolTable
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|sh
block|{
name|GLenum
name|GLVariableType
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
function_decl|;
name|GLenum
name|GLVariablePrecision
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
function_decl|;
name|bool
name|IsVaryingIn
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
function_decl|;
name|bool
name|IsVaryingOut
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
function_decl|;
name|bool
name|IsVarying
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
function_decl|;
name|InterpolationType
name|GetInterpolationType
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
function_decl|;
name|TString
name|ArrayString
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
function_decl|;
name|class
name|GetVariableTraverser
block|{
name|public
label|:
name|GetVariableTraverser
argument_list|(
specifier|const
name|TSymbolTable
operator|&
name|symbolTable
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|VarT
operator|>
name|void
name|traverse
argument_list|(
specifier|const
name|TType
operator|&
name|type
argument_list|,
specifier|const
name|TString
operator|&
name|name
argument_list|,
name|std
operator|::
name|vector
operator|<
name|VarT
operator|>
operator|*
name|output
argument_list|)
expr_stmt|;
name|protected
label|:
comment|// May be overloaded
name|virtual
name|void
name|visitVariable
parameter_list|(
name|ShaderVariable
modifier|*
name|newVar
parameter_list|)
block|{}
name|private
label|:
comment|// Helper function called by traverse() to fill specific fields
comment|// for attributes/varyings/uniforms.
name|template
operator|<
name|typename
name|VarT
operator|>
name|void
name|setTypeSpecificInfo
argument_list|(
argument|const TType&type
argument_list|,
argument|const TString&name
argument_list|,
argument|VarT *variable
argument_list|)
block|{}
specifier|const
name|TSymbolTable
operator|&
name|mSymbolTable
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GetVariableTraverser
argument_list|)
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
comment|// COMPILER_UTIL_H
end_comment
end_unit
