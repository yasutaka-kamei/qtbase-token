begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2010 The ANGLE Project Authors. All rights reserved.
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
file|"compiler/translator/util.h"
end_include
begin_include
include|#
directive|include
file|<limits>
end_include
begin_include
include|#
directive|include
file|"compiler/preprocessor/numeric_lex.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/SymbolTable.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_function
DECL|function|strtof_clamp
name|bool
name|strtof_clamp
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|str
parameter_list|,
name|float
modifier|*
name|value
parameter_list|)
block|{
name|bool
name|success
init|=
name|pp
operator|::
name|numeric_lex_float
argument_list|(
name|str
argument_list|,
name|value
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
operator|*
name|value
operator|=
name|std
operator|::
name|numeric_limits
argument_list|<
name|float
argument_list|>
operator|::
name|max
argument_list|()
expr_stmt|;
return|return
name|success
return|;
block|}
end_function
begin_function
DECL|function|atoi_clamp
name|bool
name|atoi_clamp
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|unsigned
name|int
modifier|*
name|value
parameter_list|)
block|{
name|bool
name|success
init|=
name|pp
operator|::
name|numeric_lex_int
argument_list|(
name|str
argument_list|,
name|value
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
operator|*
name|value
operator|=
name|std
operator|::
name|numeric_limits
argument_list|<
name|unsigned
name|int
argument_list|>
operator|::
name|max
argument_list|()
expr_stmt|;
return|return
name|success
return|;
block|}
end_function
begin_namespace
DECL|namespace|sh
namespace|namespace
name|sh
block|{
DECL|function|GLVariableType
name|GLenum
name|GLVariableType
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|.
name|getBasicType
argument_list|()
operator|==
name|EbtFloat
condition|)
block|{
if|if
condition|(
name|type
operator|.
name|isScalar
argument_list|()
condition|)
block|{
return|return
name|GL_FLOAT
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|.
name|isVector
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|type
operator|.
name|getNominalSize
argument_list|()
condition|)
block|{
case|case
literal|2
case|:
return|return
name|GL_FLOAT_VEC2
return|;
case|case
literal|3
case|:
return|return
name|GL_FLOAT_VEC3
return|;
case|case
literal|4
case|:
return|return
name|GL_FLOAT_VEC4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|type
operator|.
name|isMatrix
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|type
operator|.
name|getCols
argument_list|()
condition|)
block|{
case|case
literal|2
case|:
switch|switch
condition|(
name|type
operator|.
name|getRows
argument_list|()
condition|)
block|{
case|case
literal|2
case|:
return|return
name|GL_FLOAT_MAT2
return|;
case|case
literal|3
case|:
return|return
name|GL_FLOAT_MAT2x3
return|;
case|case
literal|4
case|:
return|return
name|GL_FLOAT_MAT2x4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
case|case
literal|3
case|:
switch|switch
condition|(
name|type
operator|.
name|getRows
argument_list|()
condition|)
block|{
case|case
literal|2
case|:
return|return
name|GL_FLOAT_MAT3x2
return|;
case|case
literal|3
case|:
return|return
name|GL_FLOAT_MAT3
return|;
case|case
literal|4
case|:
return|return
name|GL_FLOAT_MAT3x4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
case|case
literal|4
case|:
switch|switch
condition|(
name|type
operator|.
name|getRows
argument_list|()
condition|)
block|{
case|case
literal|2
case|:
return|return
name|GL_FLOAT_MAT4x2
return|;
case|case
literal|3
case|:
return|return
name|GL_FLOAT_MAT4x3
return|;
case|case
literal|4
case|:
return|return
name|GL_FLOAT_MAT4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
else|else
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|.
name|getBasicType
argument_list|()
operator|==
name|EbtInt
condition|)
block|{
if|if
condition|(
name|type
operator|.
name|isScalar
argument_list|()
condition|)
block|{
return|return
name|GL_INT
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|.
name|isVector
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|type
operator|.
name|getNominalSize
argument_list|()
condition|)
block|{
case|case
literal|2
case|:
return|return
name|GL_INT_VEC2
return|;
case|case
literal|3
case|:
return|return
name|GL_INT_VEC3
return|;
case|case
literal|4
case|:
return|return
name|GL_INT_VEC4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
else|else
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|.
name|getBasicType
argument_list|()
operator|==
name|EbtUInt
condition|)
block|{
if|if
condition|(
name|type
operator|.
name|isScalar
argument_list|()
condition|)
block|{
return|return
name|GL_UNSIGNED_INT
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|.
name|isVector
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|type
operator|.
name|getNominalSize
argument_list|()
condition|)
block|{
case|case
literal|2
case|:
return|return
name|GL_UNSIGNED_INT_VEC2
return|;
case|case
literal|3
case|:
return|return
name|GL_UNSIGNED_INT_VEC3
return|;
case|case
literal|4
case|:
return|return
name|GL_UNSIGNED_INT_VEC4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
else|else
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|type
operator|.
name|getBasicType
argument_list|()
operator|==
name|EbtBool
condition|)
block|{
if|if
condition|(
name|type
operator|.
name|isScalar
argument_list|()
condition|)
block|{
return|return
name|GL_BOOL
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|.
name|isVector
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|type
operator|.
name|getNominalSize
argument_list|()
condition|)
block|{
case|case
literal|2
case|:
return|return
name|GL_BOOL_VEC2
return|;
case|case
literal|3
case|:
return|return
name|GL_BOOL_VEC3
return|;
case|case
literal|4
case|:
return|return
name|GL_BOOL_VEC4
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
else|else
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
switch|switch
condition|(
name|type
operator|.
name|getBasicType
argument_list|()
condition|)
block|{
case|case
name|EbtSampler2D
case|:
return|return
name|GL_SAMPLER_2D
return|;
case|case
name|EbtSampler3D
case|:
return|return
name|GL_SAMPLER_3D
return|;
case|case
name|EbtSamplerCube
case|:
return|return
name|GL_SAMPLER_CUBE
return|;
case|case
name|EbtSamplerExternalOES
case|:
return|return
name|GL_SAMPLER_EXTERNAL_OES
return|;
case|case
name|EbtSampler2DRect
case|:
return|return
name|GL_SAMPLER_2D_RECT_ARB
return|;
case|case
name|EbtSampler2DArray
case|:
return|return
name|GL_SAMPLER_2D_ARRAY
return|;
case|case
name|EbtISampler2D
case|:
return|return
name|GL_INT_SAMPLER_2D
return|;
case|case
name|EbtISampler3D
case|:
return|return
name|GL_INT_SAMPLER_3D
return|;
case|case
name|EbtISamplerCube
case|:
return|return
name|GL_INT_SAMPLER_CUBE
return|;
case|case
name|EbtISampler2DArray
case|:
return|return
name|GL_INT_SAMPLER_2D_ARRAY
return|;
case|case
name|EbtUSampler2D
case|:
return|return
name|GL_UNSIGNED_INT_SAMPLER_2D
return|;
case|case
name|EbtUSampler3D
case|:
return|return
name|GL_UNSIGNED_INT_SAMPLER_3D
return|;
case|case
name|EbtUSamplerCube
case|:
return|return
name|GL_UNSIGNED_INT_SAMPLER_CUBE
return|;
case|case
name|EbtUSampler2DArray
case|:
return|return
name|GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
return|;
case|case
name|EbtSampler2DShadow
case|:
return|return
name|GL_SAMPLER_2D_SHADOW
return|;
case|case
name|EbtSamplerCubeShadow
case|:
return|return
name|GL_SAMPLER_CUBE_SHADOW
return|;
case|case
name|EbtSampler2DArrayShadow
case|:
return|return
name|GL_SAMPLER_2D_ARRAY_SHADOW
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
name|GL_NONE
return|;
block|}
DECL|function|GLVariablePrecision
name|GLenum
name|GLVariablePrecision
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|.
name|getBasicType
argument_list|()
operator|==
name|EbtFloat
condition|)
block|{
switch|switch
condition|(
name|type
operator|.
name|getPrecision
argument_list|()
condition|)
block|{
case|case
name|EbpHigh
case|:
return|return
name|GL_HIGH_FLOAT
return|;
case|case
name|EbpMedium
case|:
return|return
name|GL_MEDIUM_FLOAT
return|;
case|case
name|EbpLow
case|:
return|return
name|GL_LOW_FLOAT
return|;
case|case
name|EbpUndefined
case|:
comment|// Should be defined as the default precision by the parser
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|type
operator|.
name|getBasicType
argument_list|()
operator|==
name|EbtInt
operator|||
name|type
operator|.
name|getBasicType
argument_list|()
operator|==
name|EbtUInt
condition|)
block|{
switch|switch
condition|(
name|type
operator|.
name|getPrecision
argument_list|()
condition|)
block|{
case|case
name|EbpHigh
case|:
return|return
name|GL_HIGH_INT
return|;
case|case
name|EbpMedium
case|:
return|return
name|GL_MEDIUM_INT
return|;
case|case
name|EbpLow
case|:
return|return
name|GL_LOW_INT
return|;
case|case
name|EbpUndefined
case|:
comment|// Should be defined as the default precision by the parser
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
comment|// Other types (boolean, sampler) don't have a precision
return|return
name|GL_NONE
return|;
block|}
DECL|function|ArrayString
name|TString
name|ArrayString
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
block|{
if|if
condition|(
operator|!
name|type
operator|.
name|isArray
argument_list|()
condition|)
block|{
return|return
literal|""
return|;
block|}
return|return
literal|"["
operator|+
name|str
argument_list|(
name|type
operator|.
name|getArraySize
argument_list|()
argument_list|)
operator|+
literal|"]"
return|;
block|}
DECL|function|IsVaryingOut
name|bool
name|IsVaryingOut
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
block|{
switch|switch
condition|(
name|qualifier
condition|)
block|{
case|case
name|EvqVaryingOut
case|:
case|case
name|EvqSmoothOut
case|:
case|case
name|EvqFlatOut
case|:
case|case
name|EvqCentroidOut
case|:
case|case
name|EvqVertexOut
case|:
return|return
literal|true
return|;
default|default:
break|break;
block|}
return|return
literal|false
return|;
block|}
DECL|function|IsVaryingIn
name|bool
name|IsVaryingIn
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
block|{
switch|switch
condition|(
name|qualifier
condition|)
block|{
case|case
name|EvqVaryingIn
case|:
case|case
name|EvqSmoothIn
case|:
case|case
name|EvqFlatIn
case|:
case|case
name|EvqCentroidIn
case|:
case|case
name|EvqFragmentIn
case|:
return|return
literal|true
return|;
default|default:
break|break;
block|}
return|return
literal|false
return|;
block|}
DECL|function|IsVarying
name|bool
name|IsVarying
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
block|{
return|return
name|IsVaryingIn
argument_list|(
name|qualifier
argument_list|)
operator|||
name|IsVaryingOut
argument_list|(
name|qualifier
argument_list|)
return|;
block|}
DECL|function|GetInterpolationType
name|InterpolationType
name|GetInterpolationType
parameter_list|(
name|TQualifier
name|qualifier
parameter_list|)
block|{
switch|switch
condition|(
name|qualifier
condition|)
block|{
case|case
name|EvqFlatIn
case|:
case|case
name|EvqFlatOut
case|:
return|return
name|INTERPOLATION_FLAT
return|;
case|case
name|EvqSmoothIn
case|:
case|case
name|EvqSmoothOut
case|:
case|case
name|EvqVertexOut
case|:
case|case
name|EvqFragmentIn
case|:
case|case
name|EvqVaryingIn
case|:
case|case
name|EvqVaryingOut
case|:
return|return
name|INTERPOLATION_SMOOTH
return|;
case|case
name|EvqCentroidIn
case|:
case|case
name|EvqCentroidOut
case|:
return|return
name|INTERPOLATION_CENTROID
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|INTERPOLATION_SMOOTH
return|;
block|}
block|}
DECL|function|GetVariableTraverser
name|GetVariableTraverser
operator|::
name|GetVariableTraverser
parameter_list|(
specifier|const
name|TSymbolTable
modifier|&
name|symbolTable
parameter_list|)
member_init_list|:
name|mSymbolTable
argument_list|(
name|symbolTable
argument_list|)
block|{ }
specifier|template
name|void
name|GetVariableTraverser
operator|::
name|setTypeSpecificInfo
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|,
specifier|const
name|TString
modifier|&
name|name
parameter_list|,
name|InterfaceBlockField
modifier|*
name|variable
parameter_list|)
function_decl|;
specifier|template
name|void
name|GetVariableTraverser
operator|::
name|setTypeSpecificInfo
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|,
specifier|const
name|TString
modifier|&
name|name
parameter_list|,
name|ShaderVariable
modifier|*
name|variable
parameter_list|)
function_decl|;
specifier|template
name|void
name|GetVariableTraverser
operator|::
name|setTypeSpecificInfo
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|,
specifier|const
name|TString
modifier|&
name|name
parameter_list|,
name|Uniform
modifier|*
name|variable
parameter_list|)
function_decl|;
template|template
parameter_list|<>
DECL|function|setTypeSpecificInfo
name|void
name|GetVariableTraverser
operator|::
name|setTypeSpecificInfo
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|,
specifier|const
name|TString
modifier|&
name|name
parameter_list|,
name|Varying
modifier|*
name|variable
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|variable
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|type
operator|.
name|getQualifier
argument_list|()
condition|)
block|{
case|case
name|EvqVaryingIn
case|:
case|case
name|EvqVaryingOut
case|:
case|case
name|EvqVertexOut
case|:
case|case
name|EvqSmoothOut
case|:
case|case
name|EvqFlatOut
case|:
case|case
name|EvqCentroidOut
case|:
if|if
condition|(
name|mSymbolTable
operator|.
name|isVaryingInvariant
argument_list|(
name|std
operator|::
name|string
argument_list|(
name|name
operator|.
name|c_str
argument_list|()
argument_list|)
argument_list|)
operator|||
name|type
operator|.
name|isInvariant
argument_list|()
condition|)
block|{
name|variable
operator|->
name|isInvariant
operator|=
literal|true
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
name|variable
operator|->
name|interpolation
operator|=
name|GetInterpolationType
argument_list|(
name|type
operator|.
name|getQualifier
argument_list|()
argument_list|)
expr_stmt|;
block|}
template|template
parameter_list|<
name|typename
name|VarT
parameter_list|>
DECL|function|traverse
name|void
name|GetVariableTraverser
operator|::
name|traverse
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|,
specifier|const
name|TString
modifier|&
name|name
parameter_list|,
name|std
operator|::
name|vector
argument_list|<
name|VarT
argument_list|>
modifier|*
name|output
parameter_list|)
block|{
specifier|const
name|TStructure
modifier|*
name|structure
init|=
name|type
operator|.
name|getStruct
argument_list|()
decl_stmt|;
name|VarT
name|variable
decl_stmt|;
name|variable
operator|.
name|name
operator|=
name|name
operator|.
name|c_str
argument_list|()
expr_stmt|;
name|variable
operator|.
name|arraySize
operator|=
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|type
operator|.
name|getArraySize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|structure
condition|)
block|{
name|variable
operator|.
name|type
operator|=
name|GLVariableType
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|variable
operator|.
name|precision
operator|=
name|GLVariablePrecision
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Note: this enum value is not exposed outside ANGLE
name|variable
operator|.
name|type
operator|=
name|GL_STRUCT_ANGLEX
expr_stmt|;
name|variable
operator|.
name|structName
operator|=
name|structure
operator|->
name|name
argument_list|()
operator|.
name|c_str
argument_list|()
expr_stmt|;
specifier|const
name|TFieldList
modifier|&
name|fields
init|=
name|structure
operator|->
name|fields
argument_list|()
decl_stmt|;
for|for
control|(
name|size_t
name|fieldIndex
init|=
literal|0
init|;
name|fieldIndex
operator|<
name|fields
operator|.
name|size
argument_list|()
condition|;
name|fieldIndex
operator|++
control|)
block|{
name|TField
modifier|*
name|field
init|=
name|fields
index|[
name|fieldIndex
index|]
decl_stmt|;
name|traverse
argument_list|(
operator|*
name|field
operator|->
name|type
argument_list|()
argument_list|,
name|field
operator|->
name|name
argument_list|()
argument_list|,
operator|&
name|variable
operator|.
name|fields
argument_list|)
expr_stmt|;
block|}
block|}
name|setTypeSpecificInfo
argument_list|(
name|type
argument_list|,
name|name
argument_list|,
operator|&
name|variable
argument_list|)
expr_stmt|;
name|visitVariable
argument_list|(
operator|&
name|variable
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|output
argument_list|)
expr_stmt|;
name|output
operator|->
name|push_back
argument_list|(
name|variable
argument_list|)
expr_stmt|;
block|}
specifier|template
name|void
name|GetVariableTraverser
operator|::
name|traverse
parameter_list|(
specifier|const
name|TType
modifier|&
parameter_list|,
specifier|const
name|TString
modifier|&
parameter_list|,
name|std
operator|::
name|vector
argument_list|<
name|InterfaceBlockField
argument_list|>
modifier|*
parameter_list|)
function_decl|;
specifier|template
name|void
name|GetVariableTraverser
operator|::
name|traverse
parameter_list|(
specifier|const
name|TType
modifier|&
parameter_list|,
specifier|const
name|TString
modifier|&
parameter_list|,
name|std
operator|::
name|vector
argument_list|<
name|ShaderVariable
argument_list|>
modifier|*
parameter_list|)
function_decl|;
specifier|template
name|void
name|GetVariableTraverser
operator|::
name|traverse
parameter_list|(
specifier|const
name|TType
modifier|&
parameter_list|,
specifier|const
name|TString
modifier|&
parameter_list|,
name|std
operator|::
name|vector
argument_list|<
name|Uniform
argument_list|>
modifier|*
parameter_list|)
function_decl|;
specifier|template
name|void
name|GetVariableTraverser
operator|::
name|traverse
parameter_list|(
specifier|const
name|TType
modifier|&
parameter_list|,
specifier|const
name|TString
modifier|&
parameter_list|,
name|std
operator|::
name|vector
argument_list|<
name|Varying
argument_list|>
modifier|*
parameter_list|)
function_decl|;
block|}
end_namespace
end_unit
