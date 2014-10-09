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
comment|// StructureHLSL.cpp:
end_comment
begin_comment
comment|//   Definitions of methods for HLSL translation of GLSL structures.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/StructureHLSL.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/OutputHLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Types.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/util.h"
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
DECL|function|Std140PaddingHelper
name|Std140PaddingHelper
operator|::
name|Std140PaddingHelper
parameter_list|(
specifier|const
name|std
operator|::
name|map
argument_list|<
name|TString
argument_list|,
name|int
argument_list|>
modifier|&
name|structElementIndexes
parameter_list|,
name|unsigned
modifier|*
name|uniqueCounter
parameter_list|)
member_init_list|:
name|mPaddingCounter
argument_list|(
name|uniqueCounter
argument_list|)
member_init_list|,
name|mElementIndex
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mStructElementIndexes
argument_list|(
name|structElementIndexes
argument_list|)
block|{}
DECL|function|next
name|TString
name|Std140PaddingHelper
operator|::
name|next
parameter_list|()
block|{
name|unsigned
name|value
init|=
operator|(
operator|*
name|mPaddingCounter
operator|)
operator|++
decl_stmt|;
return|return
name|str
argument_list|(
name|value
argument_list|)
return|;
block|}
DECL|function|prePadding
name|int
name|Std140PaddingHelper
operator|::
name|prePadding
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
name|EbtStruct
operator|||
name|type
operator|.
name|isMatrix
argument_list|()
operator|||
name|type
operator|.
name|isArray
argument_list|()
condition|)
block|{
comment|// no padding needed, HLSL will align the field to a new register
name|mElementIndex
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
specifier|const
name|GLenum
name|glType
init|=
name|GLVariableType
argument_list|(
name|type
argument_list|)
decl_stmt|;
specifier|const
name|int
name|numComponents
init|=
name|gl
operator|::
name|VariableComponentCount
argument_list|(
name|glType
argument_list|)
decl_stmt|;
if|if
condition|(
name|numComponents
operator|>=
literal|4
condition|)
block|{
comment|// no padding needed, HLSL will align the field to a new register
name|mElementIndex
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|mElementIndex
operator|+
name|numComponents
operator|>
literal|4
condition|)
block|{
comment|// no padding needed, HLSL will align the field to a new register
name|mElementIndex
operator|=
name|numComponents
expr_stmt|;
return|return
literal|0
return|;
block|}
specifier|const
name|int
name|alignment
init|=
name|numComponents
operator|==
literal|3
condition|?
literal|4
else|:
name|numComponents
decl_stmt|;
specifier|const
name|int
name|paddingOffset
init|=
operator|(
name|mElementIndex
operator|%
name|alignment
operator|)
decl_stmt|;
specifier|const
name|int
name|paddingCount
init|=
operator|(
name|paddingOffset
operator|!=
literal|0
condition|?
operator|(
name|alignment
operator|-
name|paddingOffset
operator|)
else|:
literal|0
operator|)
decl_stmt|;
name|mElementIndex
operator|+=
name|paddingCount
expr_stmt|;
name|mElementIndex
operator|+=
name|numComponents
expr_stmt|;
name|mElementIndex
operator|%=
literal|4
expr_stmt|;
return|return
name|paddingCount
return|;
block|}
DECL|function|prePaddingString
name|TString
name|Std140PaddingHelper
operator|::
name|prePaddingString
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|)
block|{
name|int
name|paddingCount
init|=
name|prePadding
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|TString
name|padding
decl_stmt|;
for|for
control|(
name|int
name|paddingIndex
init|=
literal|0
init|;
name|paddingIndex
operator|<
name|paddingCount
condition|;
name|paddingIndex
operator|++
control|)
block|{
name|padding
operator|+=
literal|"    float pad_"
operator|+
name|next
argument_list|()
operator|+
literal|";\n"
expr_stmt|;
block|}
return|return
name|padding
return|;
block|}
DECL|function|postPaddingString
name|TString
name|Std140PaddingHelper
operator|::
name|postPaddingString
parameter_list|(
specifier|const
name|TType
modifier|&
name|type
parameter_list|,
name|bool
name|useHLSLRowMajorPacking
parameter_list|)
block|{
if|if
condition|(
operator|!
name|type
operator|.
name|isMatrix
argument_list|()
operator|&&
operator|!
name|type
operator|.
name|isArray
argument_list|()
operator|&&
name|type
operator|.
name|getBasicType
argument_list|()
operator|!=
name|EbtStruct
condition|)
block|{
return|return
literal|""
return|;
block|}
name|int
name|numComponents
init|=
literal|0
decl_stmt|;
name|TStructure
modifier|*
name|structure
init|=
name|type
operator|.
name|getStruct
argument_list|()
decl_stmt|;
if|if
condition|(
name|type
operator|.
name|isMatrix
argument_list|()
condition|)
block|{
comment|// This method can also be called from structureString, which does not use layout qualifiers.
comment|// Thus, use the method parameter for determining the matrix packing.
comment|//
comment|// Note HLSL row major packing corresponds to GL API column-major, and vice-versa, since we
comment|// wish to always transpose GL matrices to play well with HLSL's matrix array indexing.
comment|//
specifier|const
name|bool
name|isRowMajorMatrix
init|=
operator|!
name|useHLSLRowMajorPacking
decl_stmt|;
specifier|const
name|GLenum
name|glType
init|=
name|GLVariableType
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|numComponents
operator|=
name|gl
operator|::
name|MatrixComponentCount
argument_list|(
name|glType
argument_list|,
name|isRowMajorMatrix
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|structure
condition|)
block|{
specifier|const
name|TString
modifier|&
name|structName
init|=
name|QualifiedStructNameString
argument_list|(
operator|*
name|structure
argument_list|,
name|useHLSLRowMajorPacking
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|numComponents
operator|=
name|mStructElementIndexes
operator|.
name|find
argument_list|(
name|structName
argument_list|)
operator|->
name|second
expr_stmt|;
if|if
condition|(
name|numComponents
operator|==
literal|0
condition|)
block|{
return|return
literal|""
return|;
block|}
block|}
else|else
block|{
specifier|const
name|GLenum
name|glType
init|=
name|GLVariableType
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|numComponents
operator|=
name|gl
operator|::
name|VariableComponentCount
argument_list|(
name|glType
argument_list|)
expr_stmt|;
block|}
name|TString
name|padding
decl_stmt|;
for|for
control|(
name|int
name|paddingOffset
init|=
name|numComponents
init|;
name|paddingOffset
operator|<
literal|4
condition|;
name|paddingOffset
operator|++
control|)
block|{
name|padding
operator|+=
literal|"    float pad_"
operator|+
name|next
argument_list|()
operator|+
literal|";\n"
expr_stmt|;
block|}
return|return
name|padding
return|;
block|}
DECL|function|StructureHLSL
name|StructureHLSL
operator|::
name|StructureHLSL
parameter_list|()
member_init_list|:
name|mUniquePaddingCounter
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|getPaddingHelper
name|Std140PaddingHelper
name|StructureHLSL
operator|::
name|getPaddingHelper
parameter_list|()
block|{
return|return
name|Std140PaddingHelper
argument_list|(
name|mStd140StructElementIndexes
argument_list|,
operator|&
name|mUniquePaddingCounter
argument_list|)
return|;
block|}
DECL|function|defineQualified
name|TString
name|StructureHLSL
operator|::
name|defineQualified
parameter_list|(
specifier|const
name|TStructure
modifier|&
name|structure
parameter_list|,
name|bool
name|useHLSLRowMajorPacking
parameter_list|,
name|bool
name|useStd140Packing
parameter_list|)
block|{
if|if
condition|(
name|useStd140Packing
condition|)
block|{
name|Std140PaddingHelper
name|padHelper
init|=
name|getPaddingHelper
argument_list|()
decl_stmt|;
return|return
name|define
argument_list|(
name|structure
argument_list|,
name|useHLSLRowMajorPacking
argument_list|,
name|useStd140Packing
argument_list|,
operator|&
name|padHelper
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|define
argument_list|(
name|structure
argument_list|,
name|useHLSLRowMajorPacking
argument_list|,
name|useStd140Packing
argument_list|,
name|NULL
argument_list|)
return|;
block|}
block|}
DECL|function|defineNameless
name|TString
name|StructureHLSL
operator|::
name|defineNameless
parameter_list|(
specifier|const
name|TStructure
modifier|&
name|structure
parameter_list|)
block|{
return|return
name|define
argument_list|(
name|structure
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|,
name|NULL
argument_list|)
return|;
block|}
DECL|function|define
name|TString
name|StructureHLSL
operator|::
name|define
parameter_list|(
specifier|const
name|TStructure
modifier|&
name|structure
parameter_list|,
name|bool
name|useHLSLRowMajorPacking
parameter_list|,
name|bool
name|useStd140Packing
parameter_list|,
name|Std140PaddingHelper
modifier|*
name|padHelper
parameter_list|)
block|{
specifier|const
name|TFieldList
modifier|&
name|fields
init|=
name|structure
operator|.
name|fields
argument_list|()
decl_stmt|;
specifier|const
name|bool
name|isNameless
init|=
operator|(
name|structure
operator|.
name|name
argument_list|()
operator|==
literal|""
operator|)
decl_stmt|;
specifier|const
name|TString
modifier|&
name|structName
init|=
name|QualifiedStructNameString
argument_list|(
name|structure
argument_list|,
name|useHLSLRowMajorPacking
argument_list|,
name|useStd140Packing
argument_list|)
decl_stmt|;
specifier|const
name|TString
name|declareString
init|=
operator|(
name|isNameless
condition|?
literal|"struct"
else|:
literal|"struct "
operator|+
name|structName
operator|)
decl_stmt|;
name|TString
name|string
decl_stmt|;
name|string
operator|+=
name|declareString
operator|+
literal|"\n"
literal|"{\n"
expr_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|fields
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|TField
modifier|&
name|field
init|=
operator|*
name|fields
index|[
name|i
index|]
decl_stmt|;
specifier|const
name|TType
modifier|&
name|fieldType
init|=
operator|*
name|field
operator|.
name|type
argument_list|()
decl_stmt|;
specifier|const
name|TStructure
modifier|*
name|fieldStruct
init|=
name|fieldType
operator|.
name|getStruct
argument_list|()
decl_stmt|;
specifier|const
name|TString
modifier|&
name|fieldTypeString
init|=
name|fieldStruct
condition|?
name|QualifiedStructNameString
argument_list|(
operator|*
name|fieldStruct
argument_list|,
name|useHLSLRowMajorPacking
argument_list|,
name|useStd140Packing
argument_list|)
else|:
name|TypeString
argument_list|(
name|fieldType
argument_list|)
decl_stmt|;
if|if
condition|(
name|padHelper
condition|)
block|{
name|string
operator|+=
name|padHelper
operator|->
name|prePaddingString
argument_list|(
name|fieldType
argument_list|)
expr_stmt|;
block|}
name|string
operator|+=
literal|"    "
operator|+
name|fieldTypeString
operator|+
literal|" "
operator|+
name|DecorateField
argument_list|(
name|field
operator|.
name|name
argument_list|()
argument_list|,
name|structure
argument_list|)
operator|+
name|ArrayString
argument_list|(
name|fieldType
argument_list|)
operator|+
literal|";\n"
expr_stmt|;
if|if
condition|(
name|padHelper
condition|)
block|{
name|string
operator|+=
name|padHelper
operator|->
name|postPaddingString
argument_list|(
name|fieldType
argument_list|,
name|useHLSLRowMajorPacking
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Nameless structs do not finish with a semicolon and newline, to leave room for an instance variable
name|string
operator|+=
operator|(
name|isNameless
condition|?
literal|"} "
else|:
literal|"};\n"
operator|)
expr_stmt|;
return|return
name|string
return|;
block|}
DECL|function|addConstructor
name|void
name|StructureHLSL
operator|::
name|addConstructor
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
specifier|const
name|TIntermSequence
modifier|*
name|parameters
parameter_list|)
block|{
if|if
condition|(
name|name
operator|==
literal|""
condition|)
block|{
return|return;
comment|// Nameless structures don't have constructors
block|}
if|if
condition|(
name|type
operator|.
name|getStruct
argument_list|()
operator|&&
name|mStructNames
operator|.
name|find
argument_list|(
name|name
argument_list|)
operator|!=
name|mStructNames
operator|.
name|end
argument_list|()
condition|)
block|{
return|return;
comment|// Already added
block|}
name|TType
name|ctorType
init|=
name|type
decl_stmt|;
name|ctorType
operator|.
name|clearArrayness
argument_list|()
expr_stmt|;
name|ctorType
operator|.
name|setPrecision
argument_list|(
name|EbpHigh
argument_list|)
expr_stmt|;
name|ctorType
operator|.
name|setQualifier
argument_list|(
name|EvqTemporary
argument_list|)
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
argument_list|<
name|TType
argument_list|>
name|ParameterArray
typedef|;
name|ParameterArray
name|ctorParameters
decl_stmt|;
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
if|if
condition|(
name|structure
condition|)
block|{
name|mStructNames
operator|.
name|insert
argument_list|(
name|name
argument_list|)
expr_stmt|;
comment|// Add element index
name|storeStd140ElementIndex
argument_list|(
operator|*
name|structure
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|storeStd140ElementIndex
argument_list|(
operator|*
name|structure
argument_list|,
literal|true
argument_list|)
expr_stmt|;
specifier|const
name|TString
modifier|&
name|structString
init|=
name|defineQualified
argument_list|(
operator|*
name|structure
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|)
decl_stmt|;
if|if
condition|(
name|std
operator|::
name|find
argument_list|(
name|mStructDeclarations
operator|.
name|begin
argument_list|()
argument_list|,
name|mStructDeclarations
operator|.
name|end
argument_list|()
argument_list|,
name|structString
argument_list|)
operator|==
name|mStructDeclarations
operator|.
name|end
argument_list|()
condition|)
block|{
comment|// Add row-major packed struct for interface blocks
name|TString
name|rowMajorString
init|=
literal|"#pragma pack_matrix(row_major)\n"
operator|+
name|defineQualified
argument_list|(
operator|*
name|structure
argument_list|,
literal|true
argument_list|,
literal|false
argument_list|)
operator|+
literal|"#pragma pack_matrix(column_major)\n"
decl_stmt|;
name|TString
name|std140String
init|=
name|defineQualified
argument_list|(
operator|*
name|structure
argument_list|,
literal|false
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|TString
name|std140RowMajorString
init|=
literal|"#pragma pack_matrix(row_major)\n"
operator|+
name|defineQualified
argument_list|(
operator|*
name|structure
argument_list|,
literal|true
argument_list|,
literal|true
argument_list|)
operator|+
literal|"#pragma pack_matrix(column_major)\n"
decl_stmt|;
name|mStructDeclarations
operator|.
name|push_back
argument_list|(
name|structString
argument_list|)
expr_stmt|;
name|mStructDeclarations
operator|.
name|push_back
argument_list|(
name|rowMajorString
argument_list|)
expr_stmt|;
name|mStructDeclarations
operator|.
name|push_back
argument_list|(
name|std140String
argument_list|)
expr_stmt|;
name|mStructDeclarations
operator|.
name|push_back
argument_list|(
name|std140RowMajorString
argument_list|)
expr_stmt|;
block|}
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
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|fields
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|ctorParameters
operator|.
name|push_back
argument_list|(
operator|*
name|fields
index|[
name|i
index|]
operator|->
name|type
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|parameters
condition|)
block|{
for|for
control|(
name|TIntermSequence
operator|::
name|const_iterator
name|parameter
init|=
name|parameters
operator|->
name|begin
argument_list|()
init|;
name|parameter
operator|!=
name|parameters
operator|->
name|end
argument_list|()
condition|;
name|parameter
operator|++
control|)
block|{
name|ctorParameters
operator|.
name|push_back
argument_list|(
operator|(
operator|*
name|parameter
operator|)
operator|->
name|getAsTyped
argument_list|()
operator|->
name|getType
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|UNREACHABLE
argument_list|()
expr_stmt|;
name|TString
name|constructor
decl_stmt|;
if|if
condition|(
name|ctorType
operator|.
name|getStruct
argument_list|()
condition|)
block|{
name|constructor
operator|+=
name|name
operator|+
literal|" "
operator|+
name|name
operator|+
literal|"_ctor("
expr_stmt|;
block|}
else|else
comment|// Built-in type
block|{
name|constructor
operator|+=
name|TypeString
argument_list|(
name|ctorType
argument_list|)
operator|+
literal|" "
operator|+
name|name
operator|+
literal|"("
expr_stmt|;
block|}
for|for
control|(
name|unsigned
name|int
name|parameter
init|=
literal|0
init|;
name|parameter
operator|<
name|ctorParameters
operator|.
name|size
argument_list|()
condition|;
name|parameter
operator|++
control|)
block|{
specifier|const
name|TType
modifier|&
name|type
init|=
name|ctorParameters
index|[
name|parameter
index|]
decl_stmt|;
name|constructor
operator|+=
name|TypeString
argument_list|(
name|type
argument_list|)
operator|+
literal|" x"
operator|+
name|str
argument_list|(
name|parameter
argument_list|)
operator|+
name|ArrayString
argument_list|(
name|type
argument_list|)
expr_stmt|;
if|if
condition|(
name|parameter
operator|<
name|ctorParameters
operator|.
name|size
argument_list|()
operator|-
literal|1
condition|)
block|{
name|constructor
operator|+=
literal|", "
expr_stmt|;
block|}
block|}
name|constructor
operator|+=
literal|")\n"
literal|"{\n"
expr_stmt|;
if|if
condition|(
name|ctorType
operator|.
name|getStruct
argument_list|()
condition|)
block|{
name|constructor
operator|+=
literal|"    "
operator|+
name|name
operator|+
literal|" structure = {"
expr_stmt|;
block|}
else|else
block|{
name|constructor
operator|+=
literal|"    return "
operator|+
name|TypeString
argument_list|(
name|ctorType
argument_list|)
operator|+
literal|"("
expr_stmt|;
block|}
if|if
condition|(
name|ctorType
operator|.
name|isMatrix
argument_list|()
operator|&&
name|ctorParameters
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
block|{
name|int
name|rows
init|=
name|ctorType
operator|.
name|getRows
argument_list|()
decl_stmt|;
name|int
name|cols
init|=
name|ctorType
operator|.
name|getCols
argument_list|()
decl_stmt|;
specifier|const
name|TType
modifier|&
name|parameter
init|=
name|ctorParameters
index|[
literal|0
index|]
decl_stmt|;
if|if
condition|(
name|parameter
operator|.
name|isScalar
argument_list|()
condition|)
block|{
for|for
control|(
name|int
name|col
init|=
literal|0
init|;
name|col
operator|<
name|cols
condition|;
name|col
operator|++
control|)
block|{
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|rows
condition|;
name|row
operator|++
control|)
block|{
name|constructor
operator|+=
name|TString
argument_list|(
operator|(
name|row
operator|==
name|col
operator|)
condition|?
literal|"x0"
else|:
literal|"0.0"
argument_list|)
expr_stmt|;
if|if
condition|(
name|row
operator|<
name|rows
operator|-
literal|1
operator|||
name|col
operator|<
name|cols
operator|-
literal|1
condition|)
block|{
name|constructor
operator|+=
literal|", "
expr_stmt|;
block|}
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|parameter
operator|.
name|isMatrix
argument_list|()
condition|)
block|{
for|for
control|(
name|int
name|col
init|=
literal|0
init|;
name|col
operator|<
name|cols
condition|;
name|col
operator|++
control|)
block|{
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|rows
condition|;
name|row
operator|++
control|)
block|{
if|if
condition|(
name|row
operator|<
name|parameter
operator|.
name|getRows
argument_list|()
operator|&&
name|col
operator|<
name|parameter
operator|.
name|getCols
argument_list|()
condition|)
block|{
name|constructor
operator|+=
name|TString
argument_list|(
literal|"x0"
argument_list|)
operator|+
literal|"["
operator|+
name|str
argument_list|(
name|col
argument_list|)
operator|+
literal|"]["
operator|+
name|str
argument_list|(
name|row
argument_list|)
operator|+
literal|"]"
expr_stmt|;
block|}
else|else
block|{
name|constructor
operator|+=
name|TString
argument_list|(
operator|(
name|row
operator|==
name|col
operator|)
condition|?
literal|"1.0"
else|:
literal|"0.0"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|row
operator|<
name|rows
operator|-
literal|1
operator|||
name|col
operator|<
name|cols
operator|-
literal|1
condition|)
block|{
name|constructor
operator|+=
literal|", "
expr_stmt|;
block|}
block|}
block|}
block|}
else|else
block|{
name|ASSERT
argument_list|(
name|rows
operator|==
literal|2
operator|&&
name|cols
operator|==
literal|2
operator|&&
name|parameter
operator|.
name|isVector
argument_list|()
operator|&&
name|parameter
operator|.
name|getNominalSize
argument_list|()
operator|==
literal|4
argument_list|)
expr_stmt|;
name|constructor
operator|+=
literal|"x0"
expr_stmt|;
block|}
block|}
else|else
block|{
name|size_t
name|remainingComponents
init|=
name|ctorType
operator|.
name|getObjectSize
argument_list|()
decl_stmt|;
name|size_t
name|parameterIndex
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|remainingComponents
operator|>
literal|0
condition|)
block|{
specifier|const
name|TType
modifier|&
name|parameter
init|=
name|ctorParameters
index|[
name|parameterIndex
index|]
decl_stmt|;
specifier|const
name|size_t
name|parameterSize
init|=
name|parameter
operator|.
name|getObjectSize
argument_list|()
decl_stmt|;
name|bool
name|moreParameters
init|=
name|parameterIndex
operator|+
literal|1
operator|<
name|ctorParameters
operator|.
name|size
argument_list|()
decl_stmt|;
name|constructor
operator|+=
literal|"x"
operator|+
name|str
argument_list|(
name|parameterIndex
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctorType
operator|.
name|getStruct
argument_list|()
condition|)
block|{
name|ASSERT
argument_list|(
name|remainingComponents
operator|==
name|parameterSize
operator|||
name|moreParameters
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|parameterSize
operator|<=
name|remainingComponents
argument_list|)
expr_stmt|;
name|remainingComponents
operator|-=
name|parameterSize
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|parameter
operator|.
name|isScalar
argument_list|()
condition|)
block|{
name|remainingComponents
operator|-=
name|parameter
operator|.
name|getObjectSize
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|parameter
operator|.
name|isVector
argument_list|()
condition|)
block|{
if|if
condition|(
name|remainingComponents
operator|==
name|parameterSize
operator|||
name|moreParameters
condition|)
block|{
name|ASSERT
argument_list|(
name|parameterSize
operator|<=
name|remainingComponents
argument_list|)
expr_stmt|;
name|remainingComponents
operator|-=
name|parameterSize
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|remainingComponents
operator|<
cast|static_cast
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|parameter
operator|.
name|getNominalSize
argument_list|()
argument_list|)
condition|)
block|{
switch|switch
condition|(
name|remainingComponents
condition|)
block|{
case|case
literal|1
case|:
name|constructor
operator|+=
literal|".x"
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|constructor
operator|+=
literal|".xy"
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|constructor
operator|+=
literal|".xyz"
expr_stmt|;
break|break;
case|case
literal|4
case|:
name|constructor
operator|+=
literal|".xyzw"
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
name|remainingComponents
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|parameter
operator|.
name|isMatrix
argument_list|()
condition|)
block|{
name|int
name|column
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|remainingComponents
operator|>
literal|0
operator|&&
name|column
operator|<
name|parameter
operator|.
name|getCols
argument_list|()
condition|)
block|{
name|constructor
operator|+=
literal|"["
operator|+
name|str
argument_list|(
name|column
argument_list|)
operator|+
literal|"]"
expr_stmt|;
if|if
condition|(
name|remainingComponents
operator|<
cast|static_cast
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|parameter
operator|.
name|getRows
argument_list|()
argument_list|)
condition|)
block|{
switch|switch
condition|(
name|remainingComponents
condition|)
block|{
case|case
literal|1
case|:
name|constructor
operator|+=
literal|".x"
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|constructor
operator|+=
literal|".xy"
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|constructor
operator|+=
literal|".xyz"
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
name|remainingComponents
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|remainingComponents
operator|-=
name|parameter
operator|.
name|getRows
argument_list|()
expr_stmt|;
if|if
condition|(
name|remainingComponents
operator|>
literal|0
condition|)
block|{
name|constructor
operator|+=
literal|", x"
operator|+
name|str
argument_list|(
name|parameterIndex
argument_list|)
expr_stmt|;
block|}
block|}
name|column
operator|++
expr_stmt|;
block|}
block|}
else|else
name|UNREACHABLE
argument_list|()
expr_stmt|;
if|if
condition|(
name|moreParameters
condition|)
block|{
name|parameterIndex
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|remainingComponents
condition|)
block|{
name|constructor
operator|+=
literal|", "
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|ctorType
operator|.
name|getStruct
argument_list|()
condition|)
block|{
name|constructor
operator|+=
literal|"};\n"
literal|"    return structure;\n"
literal|"}\n"
expr_stmt|;
block|}
else|else
block|{
name|constructor
operator|+=
literal|");\n"
literal|"}\n"
expr_stmt|;
block|}
name|mConstructors
operator|.
name|insert
argument_list|(
name|constructor
argument_list|)
expr_stmt|;
block|}
DECL|function|structsHeader
name|std
operator|::
name|string
name|StructureHLSL
operator|::
name|structsHeader
parameter_list|()
specifier|const
block|{
name|TInfoSinkBase
name|out
decl_stmt|;
for|for
control|(
name|size_t
name|structIndex
init|=
literal|0
init|;
name|structIndex
operator|<
name|mStructDeclarations
operator|.
name|size
argument_list|()
condition|;
name|structIndex
operator|++
control|)
block|{
name|out
operator|<<
name|mStructDeclarations
index|[
name|structIndex
index|]
expr_stmt|;
block|}
for|for
control|(
name|Constructors
operator|::
name|const_iterator
name|constructor
init|=
name|mConstructors
operator|.
name|begin
argument_list|()
init|;
name|constructor
operator|!=
name|mConstructors
operator|.
name|end
argument_list|()
condition|;
name|constructor
operator|++
control|)
block|{
name|out
operator|<<
operator|*
name|constructor
expr_stmt|;
block|}
return|return
name|out
operator|.
name|str
argument_list|()
return|;
block|}
DECL|function|storeStd140ElementIndex
name|void
name|StructureHLSL
operator|::
name|storeStd140ElementIndex
parameter_list|(
specifier|const
name|TStructure
modifier|&
name|structure
parameter_list|,
name|bool
name|useHLSLRowMajorPacking
parameter_list|)
block|{
name|Std140PaddingHelper
name|padHelper
init|=
name|getPaddingHelper
argument_list|()
decl_stmt|;
specifier|const
name|TFieldList
modifier|&
name|fields
init|=
name|structure
operator|.
name|fields
argument_list|()
decl_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|fields
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|padHelper
operator|.
name|prePadding
argument_list|(
operator|*
name|fields
index|[
name|i
index|]
operator|->
name|type
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Add remaining element index to the global map, for use with nested structs in standard layouts
specifier|const
name|TString
modifier|&
name|structName
init|=
name|QualifiedStructNameString
argument_list|(
name|structure
argument_list|,
name|useHLSLRowMajorPacking
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|mStd140StructElementIndexes
index|[
name|structName
index|]
operator|=
name|padHelper
operator|.
name|elementIndex
argument_list|()
expr_stmt|;
block|}
block|}
end_namespace
end_unit
