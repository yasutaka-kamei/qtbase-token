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
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4718
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"compiler/translator/Types.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<climits>
end_include
begin_function
DECL|function|getBasicString
specifier|const
name|char
modifier|*
name|getBasicString
parameter_list|(
name|TBasicType
name|t
parameter_list|)
block|{
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|EbtVoid
case|:
return|return
literal|"void"
return|;
break|break;
case|case
name|EbtFloat
case|:
return|return
literal|"float"
return|;
break|break;
case|case
name|EbtInt
case|:
return|return
literal|"int"
return|;
break|break;
case|case
name|EbtUInt
case|:
return|return
literal|"uint"
return|;
break|break;
case|case
name|EbtBool
case|:
return|return
literal|"bool"
return|;
break|break;
case|case
name|EbtSampler2D
case|:
return|return
literal|"sampler2D"
return|;
break|break;
case|case
name|EbtSampler3D
case|:
return|return
literal|"sampler3D"
return|;
break|break;
case|case
name|EbtSamplerCube
case|:
return|return
literal|"samplerCube"
return|;
break|break;
case|case
name|EbtSamplerExternalOES
case|:
return|return
literal|"samplerExternalOES"
return|;
break|break;
case|case
name|EbtSampler2DRect
case|:
return|return
literal|"sampler2DRect"
return|;
break|break;
case|case
name|EbtSampler2DArray
case|:
return|return
literal|"sampler2DArray"
return|;
break|break;
case|case
name|EbtISampler2D
case|:
return|return
literal|"isampler2D"
return|;
break|break;
case|case
name|EbtISampler3D
case|:
return|return
literal|"isampler3D"
return|;
break|break;
case|case
name|EbtISamplerCube
case|:
return|return
literal|"isamplerCube"
return|;
break|break;
case|case
name|EbtISampler2DArray
case|:
return|return
literal|"isampler2DArray"
return|;
break|break;
case|case
name|EbtUSampler2D
case|:
return|return
literal|"usampler2D"
return|;
break|break;
case|case
name|EbtUSampler3D
case|:
return|return
literal|"usampler3D"
return|;
break|break;
case|case
name|EbtUSamplerCube
case|:
return|return
literal|"usamplerCube"
return|;
break|break;
case|case
name|EbtUSampler2DArray
case|:
return|return
literal|"usampler2DArray"
return|;
break|break;
case|case
name|EbtSampler2DShadow
case|:
return|return
literal|"sampler2DShadow"
return|;
break|break;
case|case
name|EbtSamplerCubeShadow
case|:
return|return
literal|"samplerCubeShadow"
return|;
break|break;
case|case
name|EbtSampler2DArrayShadow
case|:
return|return
literal|"sampler2DArrayShadow"
return|;
break|break;
case|case
name|EbtStruct
case|:
return|return
literal|"structure"
return|;
break|break;
case|case
name|EbtInterfaceBlock
case|:
return|return
literal|"interface block"
return|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
literal|"unknown type"
return|;
block|}
block|}
end_function
begin_constructor
DECL|function|TType
name|TType
operator|::
name|TType
parameter_list|(
specifier|const
name|TPublicType
modifier|&
name|p
parameter_list|)
member_init_list|:
name|type
argument_list|(
name|p
operator|.
name|type
argument_list|)
member_init_list|,
name|precision
argument_list|(
name|p
operator|.
name|precision
argument_list|)
member_init_list|,
name|qualifier
argument_list|(
name|p
operator|.
name|qualifier
argument_list|)
member_init_list|,
name|invariant
argument_list|(
name|p
operator|.
name|invariant
argument_list|)
member_init_list|,
name|layoutQualifier
argument_list|(
name|p
operator|.
name|layoutQualifier
argument_list|)
member_init_list|,
name|primarySize
argument_list|(
name|p
operator|.
name|primarySize
argument_list|)
member_init_list|,
name|secondarySize
argument_list|(
name|p
operator|.
name|secondarySize
argument_list|)
member_init_list|,
name|array
argument_list|(
name|p
operator|.
name|array
argument_list|)
member_init_list|,
name|arraySize
argument_list|(
name|p
operator|.
name|arraySize
argument_list|)
member_init_list|,
name|interfaceBlock
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|structure
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|p
operator|.
name|userDef
condition|)
name|structure
operator|=
name|p
operator|.
name|userDef
operator|->
name|getStruct
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|equals
name|bool
name|TStructure
operator|::
name|equals
parameter_list|(
specifier|const
name|TStructure
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|uniqueId
argument_list|()
operator|==
name|other
operator|.
name|uniqueId
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|getCompleteString
name|TString
name|TType
operator|::
name|getCompleteString
parameter_list|()
specifier|const
block|{
name|TStringStream
name|stream
decl_stmt|;
if|if
condition|(
name|invariant
condition|)
name|stream
operator|<<
literal|"invariant "
expr_stmt|;
if|if
condition|(
name|qualifier
operator|!=
name|EvqTemporary
operator|&&
name|qualifier
operator|!=
name|EvqGlobal
condition|)
name|stream
operator|<<
name|getQualifierString
argument_list|()
operator|<<
literal|" "
expr_stmt|;
if|if
condition|(
name|precision
operator|!=
name|EbpUndefined
condition|)
name|stream
operator|<<
name|getPrecisionString
argument_list|()
operator|<<
literal|" "
expr_stmt|;
if|if
condition|(
name|array
condition|)
name|stream
operator|<<
literal|"array["
operator|<<
name|getArraySize
argument_list|()
operator|<<
literal|"] of "
expr_stmt|;
if|if
condition|(
name|isMatrix
argument_list|()
condition|)
name|stream
operator|<<
name|getCols
argument_list|()
operator|<<
literal|"X"
operator|<<
name|getRows
argument_list|()
operator|<<
literal|" matrix of "
expr_stmt|;
elseif|else
if|if
condition|(
name|isVector
argument_list|()
condition|)
name|stream
operator|<<
name|getNominalSize
argument_list|()
operator|<<
literal|"-component vector of "
expr_stmt|;
name|stream
operator|<<
name|getBasicString
argument_list|()
expr_stmt|;
return|return
name|stream
operator|.
name|str
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//
end_comment
begin_comment
comment|// Recursively generate mangled names.
end_comment
begin_comment
comment|//
end_comment
begin_function
DECL|function|buildMangledName
name|TString
name|TType
operator|::
name|buildMangledName
parameter_list|()
specifier|const
block|{
name|TString
name|mangledName
decl_stmt|;
if|if
condition|(
name|isMatrix
argument_list|()
condition|)
name|mangledName
operator|+=
literal|'m'
expr_stmt|;
elseif|else
if|if
condition|(
name|isVector
argument_list|()
condition|)
name|mangledName
operator|+=
literal|'v'
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtFloat
case|:
name|mangledName
operator|+=
literal|'f'
expr_stmt|;
break|break;
case|case
name|EbtInt
case|:
name|mangledName
operator|+=
literal|'i'
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|mangledName
operator|+=
literal|'u'
expr_stmt|;
break|break;
case|case
name|EbtBool
case|:
name|mangledName
operator|+=
literal|'b'
expr_stmt|;
break|break;
case|case
name|EbtSampler2D
case|:
name|mangledName
operator|+=
literal|"s2"
expr_stmt|;
break|break;
case|case
name|EbtSampler3D
case|:
name|mangledName
operator|+=
literal|"s3"
expr_stmt|;
break|break;
case|case
name|EbtSamplerCube
case|:
name|mangledName
operator|+=
literal|"sC"
expr_stmt|;
break|break;
case|case
name|EbtSampler2DArray
case|:
name|mangledName
operator|+=
literal|"s2a"
expr_stmt|;
break|break;
case|case
name|EbtSamplerExternalOES
case|:
name|mangledName
operator|+=
literal|"sext"
expr_stmt|;
break|break;
case|case
name|EbtSampler2DRect
case|:
name|mangledName
operator|+=
literal|"s2r"
expr_stmt|;
break|break;
case|case
name|EbtISampler2D
case|:
name|mangledName
operator|+=
literal|"is2"
expr_stmt|;
break|break;
case|case
name|EbtISampler3D
case|:
name|mangledName
operator|+=
literal|"is3"
expr_stmt|;
break|break;
case|case
name|EbtISamplerCube
case|:
name|mangledName
operator|+=
literal|"isC"
expr_stmt|;
break|break;
case|case
name|EbtISampler2DArray
case|:
name|mangledName
operator|+=
literal|"is2a"
expr_stmt|;
break|break;
case|case
name|EbtUSampler2D
case|:
name|mangledName
operator|+=
literal|"us2"
expr_stmt|;
break|break;
case|case
name|EbtUSampler3D
case|:
name|mangledName
operator|+=
literal|"us3"
expr_stmt|;
break|break;
case|case
name|EbtUSamplerCube
case|:
name|mangledName
operator|+=
literal|"usC"
expr_stmt|;
break|break;
case|case
name|EbtUSampler2DArray
case|:
name|mangledName
operator|+=
literal|"us2a"
expr_stmt|;
break|break;
case|case
name|EbtSampler2DShadow
case|:
name|mangledName
operator|+=
literal|"s2s"
expr_stmt|;
break|break;
case|case
name|EbtSamplerCubeShadow
case|:
name|mangledName
operator|+=
literal|"sCs"
expr_stmt|;
break|break;
case|case
name|EbtSampler2DArrayShadow
case|:
name|mangledName
operator|+=
literal|"s2as"
expr_stmt|;
break|break;
case|case
name|EbtStruct
case|:
name|mangledName
operator|+=
name|structure
operator|->
name|mangledName
argument_list|()
expr_stmt|;
break|break;
case|case
name|EbtInterfaceBlock
case|:
name|mangledName
operator|+=
name|interfaceBlock
operator|->
name|mangledName
argument_list|()
expr_stmt|;
break|break;
default|default:
comment|// EbtVoid, EbtAddress and non types
break|break;
block|}
if|if
condition|(
name|isMatrix
argument_list|()
condition|)
block|{
name|mangledName
operator|+=
cast|static_cast
argument_list|<
name|char
argument_list|>
argument_list|(
literal|'0'
operator|+
name|getCols
argument_list|()
argument_list|)
expr_stmt|;
name|mangledName
operator|+=
cast|static_cast
argument_list|<
name|char
argument_list|>
argument_list|(
literal|'x'
argument_list|)
expr_stmt|;
name|mangledName
operator|+=
cast|static_cast
argument_list|<
name|char
argument_list|>
argument_list|(
literal|'0'
operator|+
name|getRows
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|mangledName
operator|+=
cast|static_cast
argument_list|<
name|char
argument_list|>
argument_list|(
literal|'0'
operator|+
name|getNominalSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|isArray
argument_list|()
condition|)
block|{
name|char
name|buf
index|[
literal|20
index|]
decl_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%d"
argument_list|,
name|arraySize
argument_list|)
expr_stmt|;
name|mangledName
operator|+=
literal|'['
expr_stmt|;
name|mangledName
operator|+=
name|buf
expr_stmt|;
name|mangledName
operator|+=
literal|']'
expr_stmt|;
block|}
return|return
name|mangledName
return|;
block|}
end_function
begin_function
DECL|function|getObjectSize
name|size_t
name|TType
operator|::
name|getObjectSize
parameter_list|()
specifier|const
block|{
name|size_t
name|totalSize
decl_stmt|;
if|if
condition|(
name|getBasicType
argument_list|()
operator|==
name|EbtStruct
condition|)
name|totalSize
operator|=
name|structure
operator|->
name|objectSize
argument_list|()
expr_stmt|;
else|else
name|totalSize
operator|=
name|primarySize
operator|*
name|secondarySize
expr_stmt|;
if|if
condition|(
name|isArray
argument_list|()
condition|)
block|{
comment|// TODO: getArraySize() returns an int, not a size_t
name|size_t
name|currentArraySize
init|=
name|getArraySize
argument_list|()
decl_stmt|;
if|if
condition|(
name|currentArraySize
operator|>
name|INT_MAX
operator|/
name|totalSize
condition|)
name|totalSize
operator|=
name|INT_MAX
expr_stmt|;
else|else
name|totalSize
operator|*=
name|currentArraySize
expr_stmt|;
block|}
return|return
name|totalSize
return|;
block|}
end_function
begin_function
DECL|function|containsArrays
name|bool
name|TStructure
operator|::
name|containsArrays
parameter_list|()
specifier|const
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mFields
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|TType
modifier|*
name|fieldType
init|=
operator|(
operator|*
name|mFields
operator|)
index|[
name|i
index|]
operator|->
name|type
argument_list|()
decl_stmt|;
if|if
condition|(
name|fieldType
operator|->
name|isArray
argument_list|()
operator|||
name|fieldType
operator|->
name|isStructureContainingArrays
argument_list|()
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|containsType
name|bool
name|TStructure
operator|::
name|containsType
parameter_list|(
name|TBasicType
name|type
parameter_list|)
specifier|const
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mFields
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|TType
modifier|*
name|fieldType
init|=
operator|(
operator|*
name|mFields
operator|)
index|[
name|i
index|]
operator|->
name|type
argument_list|()
decl_stmt|;
if|if
condition|(
name|fieldType
operator|->
name|getBasicType
argument_list|()
operator|==
name|type
operator|||
name|fieldType
operator|->
name|isStructureContainingType
argument_list|(
name|type
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|containsSamplers
name|bool
name|TStructure
operator|::
name|containsSamplers
parameter_list|()
specifier|const
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mFields
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|TType
modifier|*
name|fieldType
init|=
operator|(
operator|*
name|mFields
operator|)
index|[
name|i
index|]
operator|->
name|type
argument_list|()
decl_stmt|;
if|if
condition|(
name|IsSampler
argument_list|(
name|fieldType
operator|->
name|getBasicType
argument_list|()
argument_list|)
operator|||
name|fieldType
operator|->
name|isStructureContainingSamplers
argument_list|()
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|buildMangledName
name|TString
name|TFieldListCollection
operator|::
name|buildMangledName
parameter_list|(
specifier|const
name|TString
modifier|&
name|mangledNamePrefix
parameter_list|)
specifier|const
block|{
name|TString
name|mangledName
argument_list|(
name|mangledNamePrefix
argument_list|)
decl_stmt|;
name|mangledName
operator|+=
operator|*
name|mName
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mFields
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|mangledName
operator|+=
literal|'-'
expr_stmt|;
name|mangledName
operator|+=
operator|(
operator|*
name|mFields
operator|)
index|[
name|i
index|]
operator|->
name|type
argument_list|()
operator|->
name|getMangledName
argument_list|()
expr_stmt|;
block|}
return|return
name|mangledName
return|;
block|}
end_function
begin_function
DECL|function|calculateObjectSize
name|size_t
name|TFieldListCollection
operator|::
name|calculateObjectSize
parameter_list|()
specifier|const
block|{
name|size_t
name|size
init|=
literal|0
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mFields
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|size_t
name|fieldSize
init|=
operator|(
operator|*
name|mFields
operator|)
index|[
name|i
index|]
operator|->
name|type
argument_list|()
operator|->
name|getObjectSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|fieldSize
operator|>
name|INT_MAX
operator|-
name|size
condition|)
name|size
operator|=
name|INT_MAX
expr_stmt|;
else|else
name|size
operator|+=
name|fieldSize
expr_stmt|;
block|}
return|return
name|size
return|;
block|}
end_function
begin_function
DECL|function|calculateDeepestNesting
name|int
name|TStructure
operator|::
name|calculateDeepestNesting
parameter_list|()
specifier|const
block|{
name|int
name|maxNesting
init|=
literal|0
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mFields
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|maxNesting
operator|=
name|std
operator|::
name|max
argument_list|(
name|maxNesting
argument_list|,
operator|(
operator|*
name|mFields
operator|)
index|[
name|i
index|]
operator|->
name|type
argument_list|()
operator|->
name|getDeepestStructNesting
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|1
operator|+
name|maxNesting
return|;
block|}
end_function
end_unit
