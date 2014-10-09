begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// blocklayout.cpp:
end_comment
begin_comment
comment|//   Implementation for block layout classes and methods.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"common/blocklayout.h"
end_include
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_namespace
DECL|namespace|sh
namespace|namespace
name|sh
block|{
DECL|function|BlockLayoutEncoder
name|BlockLayoutEncoder
operator|::
name|BlockLayoutEncoder
parameter_list|()
member_init_list|:
name|mCurrentOffset
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|encodeType
name|BlockMemberInfo
name|BlockLayoutEncoder
operator|::
name|encodeType
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|unsigned
name|int
name|arraySize
parameter_list|,
name|bool
name|isRowMajorMatrix
parameter_list|)
block|{
name|int
name|arrayStride
decl_stmt|;
name|int
name|matrixStride
decl_stmt|;
name|getBlockLayoutInfo
argument_list|(
name|type
argument_list|,
name|arraySize
argument_list|,
name|isRowMajorMatrix
argument_list|,
operator|&
name|arrayStride
argument_list|,
operator|&
name|matrixStride
argument_list|)
expr_stmt|;
specifier|const
name|BlockMemberInfo
name|memberInfo
argument_list|(
name|mCurrentOffset
operator|*
name|BytesPerComponent
argument_list|,
name|arrayStride
operator|*
name|BytesPerComponent
argument_list|,
name|matrixStride
operator|*
name|BytesPerComponent
argument_list|,
name|isRowMajorMatrix
argument_list|)
decl_stmt|;
name|advanceOffset
argument_list|(
name|type
argument_list|,
name|arraySize
argument_list|,
name|isRowMajorMatrix
argument_list|,
name|arrayStride
argument_list|,
name|matrixStride
argument_list|)
expr_stmt|;
return|return
name|memberInfo
return|;
block|}
DECL|function|nextRegister
name|void
name|BlockLayoutEncoder
operator|::
name|nextRegister
parameter_list|()
block|{
name|mCurrentOffset
operator|=
name|rx
operator|::
name|roundUp
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|mCurrentOffset
argument_list|,
name|ComponentsPerRegister
argument_list|)
expr_stmt|;
block|}
DECL|function|Std140BlockEncoder
name|Std140BlockEncoder
operator|::
name|Std140BlockEncoder
parameter_list|()
block|{ }
DECL|function|enterAggregateType
name|void
name|Std140BlockEncoder
operator|::
name|enterAggregateType
parameter_list|()
block|{
name|nextRegister
argument_list|()
expr_stmt|;
block|}
DECL|function|exitAggregateType
name|void
name|Std140BlockEncoder
operator|::
name|exitAggregateType
parameter_list|()
block|{
name|nextRegister
argument_list|()
expr_stmt|;
block|}
DECL|function|getBlockLayoutInfo
name|void
name|Std140BlockEncoder
operator|::
name|getBlockLayoutInfo
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|unsigned
name|int
name|arraySize
parameter_list|,
name|bool
name|isRowMajorMatrix
parameter_list|,
name|int
modifier|*
name|arrayStrideOut
parameter_list|,
name|int
modifier|*
name|matrixStrideOut
parameter_list|)
block|{
comment|// We assume we are only dealing with 4 byte components (no doubles or half-words currently)
name|ASSERT
argument_list|(
name|gl
operator|::
name|VariableComponentSize
argument_list|(
name|gl
operator|::
name|VariableComponentType
argument_list|(
name|type
argument_list|)
argument_list|)
operator|==
name|BytesPerComponent
argument_list|)
expr_stmt|;
name|size_t
name|baseAlignment
init|=
literal|0
decl_stmt|;
name|int
name|matrixStride
init|=
literal|0
decl_stmt|;
name|int
name|arrayStride
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|gl
operator|::
name|IsMatrixType
argument_list|(
name|type
argument_list|)
condition|)
block|{
name|baseAlignment
operator|=
name|ComponentsPerRegister
expr_stmt|;
name|matrixStride
operator|=
name|ComponentsPerRegister
expr_stmt|;
if|if
condition|(
name|arraySize
operator|>
literal|0
condition|)
block|{
specifier|const
name|int
name|numRegisters
init|=
name|gl
operator|::
name|MatrixRegisterCount
argument_list|(
name|type
argument_list|,
name|isRowMajorMatrix
argument_list|)
decl_stmt|;
name|arrayStride
operator|=
name|ComponentsPerRegister
operator|*
name|numRegisters
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|arraySize
operator|>
literal|0
condition|)
block|{
name|baseAlignment
operator|=
name|ComponentsPerRegister
expr_stmt|;
name|arrayStride
operator|=
name|ComponentsPerRegister
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|int
name|numComponents
init|=
name|gl
operator|::
name|VariableComponentCount
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|baseAlignment
operator|=
operator|(
name|numComponents
operator|==
literal|3
condition|?
literal|4u
else|:
cast|static_cast
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|numComponents
argument_list|)
operator|)
expr_stmt|;
block|}
name|mCurrentOffset
operator|=
name|rx
operator|::
name|roundUp
argument_list|(
name|mCurrentOffset
argument_list|,
name|baseAlignment
argument_list|)
expr_stmt|;
operator|*
name|matrixStrideOut
operator|=
name|matrixStride
expr_stmt|;
operator|*
name|arrayStrideOut
operator|=
name|arrayStride
expr_stmt|;
block|}
DECL|function|advanceOffset
name|void
name|Std140BlockEncoder
operator|::
name|advanceOffset
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|unsigned
name|int
name|arraySize
parameter_list|,
name|bool
name|isRowMajorMatrix
parameter_list|,
name|int
name|arrayStride
parameter_list|,
name|int
name|matrixStride
parameter_list|)
block|{
if|if
condition|(
name|arraySize
operator|>
literal|0
condition|)
block|{
name|mCurrentOffset
operator|+=
name|arrayStride
operator|*
name|arraySize
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|gl
operator|::
name|IsMatrixType
argument_list|(
name|type
argument_list|)
condition|)
block|{
name|ASSERT
argument_list|(
name|matrixStride
operator|==
name|ComponentsPerRegister
argument_list|)
expr_stmt|;
specifier|const
name|int
name|numRegisters
init|=
name|gl
operator|::
name|MatrixRegisterCount
argument_list|(
name|type
argument_list|,
name|isRowMajorMatrix
argument_list|)
decl_stmt|;
name|mCurrentOffset
operator|+=
name|ComponentsPerRegister
operator|*
name|numRegisters
expr_stmt|;
block|}
else|else
block|{
name|mCurrentOffset
operator|+=
name|gl
operator|::
name|VariableComponentCount
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|HLSLBlockEncoder
name|HLSLBlockEncoder
operator|::
name|HLSLBlockEncoder
parameter_list|(
name|HLSLBlockEncoderStrategy
name|strategy
parameter_list|)
member_init_list|:
name|mEncoderStrategy
argument_list|(
name|strategy
argument_list|)
block|{ }
DECL|function|enterAggregateType
name|void
name|HLSLBlockEncoder
operator|::
name|enterAggregateType
parameter_list|()
block|{
name|nextRegister
argument_list|()
expr_stmt|;
block|}
DECL|function|exitAggregateType
name|void
name|HLSLBlockEncoder
operator|::
name|exitAggregateType
parameter_list|()
block|{ }
DECL|function|getBlockLayoutInfo
name|void
name|HLSLBlockEncoder
operator|::
name|getBlockLayoutInfo
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|unsigned
name|int
name|arraySize
parameter_list|,
name|bool
name|isRowMajorMatrix
parameter_list|,
name|int
modifier|*
name|arrayStrideOut
parameter_list|,
name|int
modifier|*
name|matrixStrideOut
parameter_list|)
block|{
comment|// We assume we are only dealing with 4 byte components (no doubles or half-words currently)
name|ASSERT
argument_list|(
name|gl
operator|::
name|VariableComponentSize
argument_list|(
name|gl
operator|::
name|VariableComponentType
argument_list|(
name|type
argument_list|)
argument_list|)
operator|==
name|BytesPerComponent
argument_list|)
expr_stmt|;
name|int
name|matrixStride
init|=
literal|0
decl_stmt|;
name|int
name|arrayStride
init|=
literal|0
decl_stmt|;
comment|// if variables are not to be packed, or we're about to
comment|// pack a matrix or array, skip to the start of the next
comment|// register
if|if
condition|(
operator|!
name|isPacked
argument_list|()
operator|||
name|gl
operator|::
name|IsMatrixType
argument_list|(
name|type
argument_list|)
operator|||
name|arraySize
operator|>
literal|0
condition|)
block|{
name|nextRegister
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|gl
operator|::
name|IsMatrixType
argument_list|(
name|type
argument_list|)
condition|)
block|{
name|matrixStride
operator|=
name|ComponentsPerRegister
expr_stmt|;
if|if
condition|(
name|arraySize
operator|>
literal|0
condition|)
block|{
specifier|const
name|int
name|numRegisters
init|=
name|gl
operator|::
name|MatrixRegisterCount
argument_list|(
name|type
argument_list|,
name|isRowMajorMatrix
argument_list|)
decl_stmt|;
name|arrayStride
operator|=
name|ComponentsPerRegister
operator|*
name|numRegisters
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|arraySize
operator|>
literal|0
condition|)
block|{
name|arrayStride
operator|=
name|ComponentsPerRegister
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|isPacked
argument_list|()
condition|)
block|{
name|int
name|numComponents
init|=
name|gl
operator|::
name|VariableComponentCount
argument_list|(
name|type
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|numComponents
operator|+
operator|(
name|mCurrentOffset
operator|%
name|ComponentsPerRegister
operator|)
operator|)
operator|>
name|ComponentsPerRegister
condition|)
block|{
name|nextRegister
argument_list|()
expr_stmt|;
block|}
block|}
operator|*
name|matrixStrideOut
operator|=
name|matrixStride
expr_stmt|;
operator|*
name|arrayStrideOut
operator|=
name|arrayStride
expr_stmt|;
block|}
DECL|function|advanceOffset
name|void
name|HLSLBlockEncoder
operator|::
name|advanceOffset
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|unsigned
name|int
name|arraySize
parameter_list|,
name|bool
name|isRowMajorMatrix
parameter_list|,
name|int
name|arrayStride
parameter_list|,
name|int
name|matrixStride
parameter_list|)
block|{
if|if
condition|(
name|arraySize
operator|>
literal|0
condition|)
block|{
name|mCurrentOffset
operator|+=
name|arrayStride
operator|*
operator|(
name|arraySize
operator|-
literal|1
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|gl
operator|::
name|IsMatrixType
argument_list|(
name|type
argument_list|)
condition|)
block|{
name|ASSERT
argument_list|(
name|matrixStride
operator|==
name|ComponentsPerRegister
argument_list|)
expr_stmt|;
specifier|const
name|int
name|numRegisters
init|=
name|gl
operator|::
name|MatrixRegisterCount
argument_list|(
name|type
argument_list|,
name|isRowMajorMatrix
argument_list|)
decl_stmt|;
specifier|const
name|int
name|numComponents
init|=
name|gl
operator|::
name|MatrixComponentCount
argument_list|(
name|type
argument_list|,
name|isRowMajorMatrix
argument_list|)
decl_stmt|;
name|mCurrentOffset
operator|+=
name|ComponentsPerRegister
operator|*
operator|(
name|numRegisters
operator|-
literal|1
operator|)
expr_stmt|;
name|mCurrentOffset
operator|+=
name|numComponents
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|isPacked
argument_list|()
condition|)
block|{
name|mCurrentOffset
operator|+=
name|gl
operator|::
name|VariableComponentCount
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|mCurrentOffset
operator|+=
name|ComponentsPerRegister
expr_stmt|;
block|}
block|}
DECL|function|skipRegisters
name|void
name|HLSLBlockEncoder
operator|::
name|skipRegisters
parameter_list|(
name|unsigned
name|int
name|numRegisters
parameter_list|)
block|{
name|mCurrentOffset
operator|+=
operator|(
name|numRegisters
operator|*
name|ComponentsPerRegister
operator|)
expr_stmt|;
block|}
DECL|function|GetStrategyFor
name|HLSLBlockEncoder
operator|::
name|HLSLBlockEncoderStrategy
name|HLSLBlockEncoder
operator|::
name|GetStrategyFor
parameter_list|(
name|ShShaderOutput
name|outputType
parameter_list|)
block|{
switch|switch
condition|(
name|outputType
condition|)
block|{
case|case
name|SH_HLSL9_OUTPUT
case|:
return|return
name|ENCODE_LOOSE
return|;
case|case
name|SH_HLSL11_OUTPUT
case|:
return|return
name|ENCODE_PACKED
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|ENCODE_PACKED
return|;
block|}
block|}
template|template
parameter_list|<
name|class
name|ShaderVarType
parameter_list|>
DECL|function|HLSLVariableRegisterCount
name|void
name|HLSLVariableRegisterCount
parameter_list|(
specifier|const
name|ShaderVarType
modifier|&
name|variable
parameter_list|,
name|HLSLBlockEncoder
modifier|*
name|encoder
parameter_list|)
block|{
if|if
condition|(
name|variable
operator|.
name|isStruct
argument_list|()
condition|)
block|{
for|for
control|(
name|size_t
name|arrayElement
init|=
literal|0
init|;
name|arrayElement
operator|<
name|variable
operator|.
name|elementCount
argument_list|()
condition|;
name|arrayElement
operator|++
control|)
block|{
name|encoder
operator|->
name|enterAggregateType
argument_list|()
expr_stmt|;
for|for
control|(
name|size_t
name|fieldIndex
init|=
literal|0
init|;
name|fieldIndex
operator|<
name|variable
operator|.
name|fields
operator|.
name|size
argument_list|()
condition|;
name|fieldIndex
operator|++
control|)
block|{
name|HLSLVariableRegisterCount
argument_list|(
name|variable
operator|.
name|fields
index|[
name|fieldIndex
index|]
argument_list|,
name|encoder
argument_list|)
expr_stmt|;
block|}
name|encoder
operator|->
name|exitAggregateType
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// We operate only on varyings and uniforms, which do not have matrix layout qualifiers
name|encoder
operator|->
name|encodeType
argument_list|(
name|variable
operator|.
name|type
argument_list|,
name|variable
operator|.
name|arraySize
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|HLSLVariableRegisterCount
name|unsigned
name|int
name|HLSLVariableRegisterCount
parameter_list|(
specifier|const
name|Varying
modifier|&
name|variable
parameter_list|)
block|{
name|HLSLBlockEncoder
name|encoder
argument_list|(
name|HLSLBlockEncoder
operator|::
name|ENCODE_PACKED
argument_list|)
decl_stmt|;
name|HLSLVariableRegisterCount
argument_list|(
name|variable
argument_list|,
operator|&
name|encoder
argument_list|)
expr_stmt|;
specifier|const
name|size_t
name|registerBytes
init|=
operator|(
name|encoder
operator|.
name|BytesPerComponent
operator|*
name|encoder
operator|.
name|ComponentsPerRegister
operator|)
decl_stmt|;
return|return
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|rx
operator|::
name|roundUp
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|encoder
operator|.
name|getBlockSize
argument_list|()
argument_list|,
name|registerBytes
argument_list|)
operator|/
name|registerBytes
argument_list|)
return|;
block|}
DECL|function|HLSLVariableRegisterCount
name|unsigned
name|int
name|HLSLVariableRegisterCount
parameter_list|(
specifier|const
name|Uniform
modifier|&
name|variable
parameter_list|,
name|ShShaderOutput
name|outputType
parameter_list|)
block|{
name|HLSLBlockEncoder
name|encoder
argument_list|(
name|HLSLBlockEncoder
operator|::
name|GetStrategyFor
argument_list|(
name|outputType
argument_list|)
argument_list|)
decl_stmt|;
name|HLSLVariableRegisterCount
argument_list|(
name|variable
argument_list|,
operator|&
name|encoder
argument_list|)
expr_stmt|;
specifier|const
name|size_t
name|registerBytes
init|=
operator|(
name|encoder
operator|.
name|BytesPerComponent
operator|*
name|encoder
operator|.
name|ComponentsPerRegister
operator|)
decl_stmt|;
return|return
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|rx
operator|::
name|roundUp
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|encoder
operator|.
name|getBlockSize
argument_list|()
argument_list|,
name|registerBytes
argument_list|)
operator|/
name|registerBytes
argument_list|)
return|;
block|}
block|}
end_namespace
end_unit
