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
comment|// ShaderVars.cpp:
end_comment
begin_comment
comment|//  Methods for GL variable types (varyings, uniforms, etc)
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<GLSLANG/ShaderLang.h>
end_include
begin_include
include|#
directive|include
file|"compiler/translator/compilerdebug.h"
end_include
begin_namespace
DECL|namespace|sh
namespace|namespace
name|sh
block|{
DECL|function|ShaderVariable
name|ShaderVariable
operator|::
name|ShaderVariable
parameter_list|()
member_init_list|:
name|type
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|precision
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|arraySize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|staticUse
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|ShaderVariable
name|ShaderVariable
operator|::
name|ShaderVariable
parameter_list|(
name|GLenum
name|typeIn
parameter_list|,
name|unsigned
name|int
name|arraySizeIn
parameter_list|)
member_init_list|:
name|type
argument_list|(
name|typeIn
argument_list|)
member_init_list|,
name|precision
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|arraySize
argument_list|(
name|arraySizeIn
argument_list|)
member_init_list|,
name|staticUse
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|~ShaderVariable
name|ShaderVariable
operator|::
name|~
name|ShaderVariable
parameter_list|()
block|{}
DECL|function|ShaderVariable
name|ShaderVariable
operator|::
name|ShaderVariable
parameter_list|(
specifier|const
name|ShaderVariable
modifier|&
name|other
parameter_list|)
member_init_list|:
name|type
argument_list|(
name|other
operator|.
name|type
argument_list|)
member_init_list|,
name|precision
argument_list|(
name|other
operator|.
name|precision
argument_list|)
member_init_list|,
name|name
argument_list|(
name|other
operator|.
name|name
argument_list|)
member_init_list|,
name|mappedName
argument_list|(
name|other
operator|.
name|mappedName
argument_list|)
member_init_list|,
name|arraySize
argument_list|(
name|other
operator|.
name|arraySize
argument_list|)
member_init_list|,
name|staticUse
argument_list|(
name|other
operator|.
name|staticUse
argument_list|)
member_init_list|,
name|fields
argument_list|(
name|other
operator|.
name|fields
argument_list|)
member_init_list|,
name|structName
argument_list|(
name|other
operator|.
name|structName
argument_list|)
block|{}
DECL|function|operator =
name|ShaderVariable
modifier|&
name|ShaderVariable
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|ShaderVariable
modifier|&
name|other
parameter_list|)
block|{
name|type
operator|=
name|other
operator|.
name|type
expr_stmt|;
name|precision
operator|=
name|other
operator|.
name|precision
expr_stmt|;
name|name
operator|=
name|other
operator|.
name|name
expr_stmt|;
name|mappedName
operator|=
name|other
operator|.
name|mappedName
expr_stmt|;
name|arraySize
operator|=
name|other
operator|.
name|arraySize
expr_stmt|;
name|staticUse
operator|=
name|other
operator|.
name|staticUse
expr_stmt|;
name|fields
operator|=
name|other
operator|.
name|fields
expr_stmt|;
name|structName
operator|=
name|other
operator|.
name|structName
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator ==
name|bool
name|ShaderVariable
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|ShaderVariable
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|type
operator|!=
name|other
operator|.
name|type
operator|||
name|precision
operator|!=
name|other
operator|.
name|precision
operator|||
name|name
operator|!=
name|other
operator|.
name|name
operator|||
name|mappedName
operator|!=
name|other
operator|.
name|mappedName
operator|||
name|arraySize
operator|!=
name|other
operator|.
name|arraySize
operator|||
name|staticUse
operator|!=
name|other
operator|.
name|staticUse
operator|||
name|fields
operator|.
name|size
argument_list|()
operator|!=
name|other
operator|.
name|fields
operator|.
name|size
argument_list|()
operator|||
name|structName
operator|!=
name|other
operator|.
name|structName
condition|)
block|{
return|return
literal|false
return|;
block|}
for|for
control|(
name|size_t
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|fields
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
if|if
condition|(
name|fields
index|[
name|ii
index|]
operator|!=
name|other
operator|.
name|fields
index|[
name|ii
index|]
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
DECL|function|findInfoByMappedName
name|bool
name|ShaderVariable
operator|::
name|findInfoByMappedName
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|mappedFullName
parameter_list|,
specifier|const
name|ShaderVariable
modifier|*
modifier|*
name|leafVar
parameter_list|,
name|std
operator|::
name|string
modifier|*
name|originalFullName
parameter_list|)
specifier|const
block|{
name|ASSERT
argument_list|(
name|leafVar
operator|&&
name|originalFullName
argument_list|)
expr_stmt|;
comment|// There are three cases:
comment|// 1) the top variable is of struct type;
comment|// 2) the top variable is an array;
comment|// 3) otherwise.
name|size_t
name|pos
init|=
name|mappedFullName
operator|.
name|find_first_of
argument_list|(
literal|".["
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|topName
decl_stmt|;
if|if
condition|(
name|pos
operator|==
name|std
operator|::
name|string
operator|::
name|npos
condition|)
block|{
comment|// Case 3.
if|if
condition|(
name|mappedFullName
operator|!=
name|this
operator|->
name|mappedName
condition|)
return|return
literal|false
return|;
operator|*
name|originalFullName
operator|=
name|this
operator|->
name|name
expr_stmt|;
operator|*
name|leafVar
operator|=
name|this
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
name|std
operator|::
name|string
name|topName
init|=
name|mappedFullName
operator|.
name|substr
argument_list|(
literal|0
argument_list|,
name|pos
argument_list|)
decl_stmt|;
if|if
condition|(
name|topName
operator|!=
name|this
operator|->
name|mappedName
condition|)
return|return
literal|false
return|;
name|std
operator|::
name|string
name|originalName
init|=
name|this
operator|->
name|name
decl_stmt|;
name|std
operator|::
name|string
name|remaining
decl_stmt|;
if|if
condition|(
name|mappedFullName
index|[
name|pos
index|]
operator|==
literal|'['
condition|)
block|{
comment|// Case 2.
name|size_t
name|closePos
init|=
name|mappedFullName
operator|.
name|find_first_of
argument_list|(
literal|']'
argument_list|)
decl_stmt|;
if|if
condition|(
name|closePos
operator|<
name|pos
operator|||
name|closePos
operator|==
name|std
operator|::
name|string
operator|::
name|npos
condition|)
return|return
literal|false
return|;
comment|// Append '[index]'.
name|originalName
operator|+=
name|mappedFullName
operator|.
name|substr
argument_list|(
name|pos
argument_list|,
name|closePos
operator|-
name|pos
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|closePos
operator|+
literal|1
operator|==
name|mappedFullName
operator|.
name|size
argument_list|()
condition|)
block|{
operator|*
name|originalFullName
operator|=
name|originalName
expr_stmt|;
operator|*
name|leafVar
operator|=
name|this
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
comment|// In the form of 'a[0].b', so after ']', '.' is expected.
if|if
condition|(
name|mappedFullName
index|[
name|closePos
operator|+
literal|1
index|]
operator|!=
literal|'.'
condition|)
return|return
literal|false
return|;
name|remaining
operator|=
name|mappedFullName
operator|.
name|substr
argument_list|(
name|closePos
operator|+
literal|2
argument_list|)
expr_stmt|;
comment|// Skip "]."
block|}
block|}
else|else
block|{
comment|// Case 1.
name|remaining
operator|=
name|mappedFullName
operator|.
name|substr
argument_list|(
name|pos
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|// Skip "."
block|}
for|for
control|(
name|size_t
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|this
operator|->
name|fields
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
specifier|const
name|ShaderVariable
modifier|*
name|fieldVar
init|=
name|NULL
decl_stmt|;
name|std
operator|::
name|string
name|originalFieldName
decl_stmt|;
name|bool
name|found
init|=
name|fields
index|[
name|ii
index|]
operator|.
name|findInfoByMappedName
argument_list|(
name|remaining
argument_list|,
operator|&
name|fieldVar
argument_list|,
operator|&
name|originalFieldName
argument_list|)
decl_stmt|;
if|if
condition|(
name|found
condition|)
block|{
operator|*
name|originalFullName
operator|=
name|originalName
operator|+
literal|"."
operator|+
name|originalFieldName
expr_stmt|;
operator|*
name|leafVar
operator|=
name|fieldVar
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
block|}
DECL|function|isSameVariableAtLinkTime
name|bool
name|ShaderVariable
operator|::
name|isSameVariableAtLinkTime
parameter_list|(
specifier|const
name|ShaderVariable
modifier|&
name|other
parameter_list|,
name|bool
name|matchPrecision
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|type
operator|!=
name|other
operator|.
name|type
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|matchPrecision
operator|&&
name|precision
operator|!=
name|other
operator|.
name|precision
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|name
operator|!=
name|other
operator|.
name|name
condition|)
return|return
literal|false
return|;
name|ASSERT
argument_list|(
name|mappedName
operator|==
name|other
operator|.
name|mappedName
argument_list|)
expr_stmt|;
if|if
condition|(
name|arraySize
operator|!=
name|other
operator|.
name|arraySize
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|fields
operator|.
name|size
argument_list|()
operator|!=
name|other
operator|.
name|fields
operator|.
name|size
argument_list|()
condition|)
return|return
literal|false
return|;
for|for
control|(
name|size_t
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|fields
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
if|if
condition|(
operator|!
name|fields
index|[
name|ii
index|]
operator|.
name|isSameVariableAtLinkTime
argument_list|(
name|other
operator|.
name|fields
index|[
name|ii
index|]
argument_list|,
name|matchPrecision
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
block|}
if|if
condition|(
name|structName
operator|!=
name|other
operator|.
name|structName
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
DECL|function|Uniform
name|Uniform
operator|::
name|Uniform
parameter_list|()
block|{}
DECL|function|~Uniform
name|Uniform
operator|::
name|~
name|Uniform
parameter_list|()
block|{}
DECL|function|Uniform
name|Uniform
operator|::
name|Uniform
parameter_list|(
specifier|const
name|Uniform
modifier|&
name|other
parameter_list|)
member_init_list|:
name|ShaderVariable
argument_list|(
name|other
argument_list|)
block|{}
DECL|function|operator =
name|Uniform
modifier|&
name|Uniform
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|Uniform
modifier|&
name|other
parameter_list|)
block|{
name|ShaderVariable
operator|::
name|operator
name|=
parameter_list|(
name|other
parameter_list|)
function_decl|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator ==
name|bool
name|Uniform
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|Uniform
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|ShaderVariable
operator|::
name|operator
name|==
argument_list|(
name|other
argument_list|)
return|;
block|}
DECL|function|isSameUniformAtLinkTime
name|bool
name|Uniform
operator|::
name|isSameUniformAtLinkTime
parameter_list|(
specifier|const
name|Uniform
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|ShaderVariable
operator|::
name|isSameVariableAtLinkTime
argument_list|(
name|other
argument_list|,
literal|true
argument_list|)
return|;
block|}
DECL|function|Attribute
name|Attribute
operator|::
name|Attribute
parameter_list|()
member_init_list|:
name|location
argument_list|(
operator|-
literal|1
argument_list|)
block|{}
DECL|function|~Attribute
name|Attribute
operator|::
name|~
name|Attribute
parameter_list|()
block|{}
DECL|function|Attribute
name|Attribute
operator|::
name|Attribute
parameter_list|(
specifier|const
name|Attribute
modifier|&
name|other
parameter_list|)
member_init_list|:
name|ShaderVariable
argument_list|(
name|other
argument_list|)
member_init_list|,
name|location
argument_list|(
name|other
operator|.
name|location
argument_list|)
block|{}
DECL|function|operator =
name|Attribute
modifier|&
name|Attribute
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|Attribute
modifier|&
name|other
parameter_list|)
block|{
name|ShaderVariable
operator|::
name|operator
name|=
parameter_list|(
name|other
parameter_list|)
function_decl|;
name|location
operator|=
name|other
operator|.
name|location
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator ==
name|bool
name|Attribute
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|Attribute
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|ShaderVariable
operator|::
name|operator
name|==
argument_list|(
name|other
argument_list|)
operator|&&
name|location
operator|==
name|other
operator|.
name|location
operator|)
return|;
block|}
DECL|function|InterfaceBlockField
name|InterfaceBlockField
operator|::
name|InterfaceBlockField
parameter_list|()
member_init_list|:
name|isRowMajorLayout
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|~InterfaceBlockField
name|InterfaceBlockField
operator|::
name|~
name|InterfaceBlockField
parameter_list|()
block|{}
DECL|function|InterfaceBlockField
name|InterfaceBlockField
operator|::
name|InterfaceBlockField
parameter_list|(
specifier|const
name|InterfaceBlockField
modifier|&
name|other
parameter_list|)
member_init_list|:
name|ShaderVariable
argument_list|(
name|other
argument_list|)
member_init_list|,
name|isRowMajorLayout
argument_list|(
name|other
operator|.
name|isRowMajorLayout
argument_list|)
block|{}
DECL|function|operator =
name|InterfaceBlockField
modifier|&
name|InterfaceBlockField
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|InterfaceBlockField
modifier|&
name|other
parameter_list|)
block|{
name|ShaderVariable
operator|::
name|operator
name|=
parameter_list|(
name|other
parameter_list|)
function_decl|;
name|isRowMajorLayout
operator|=
name|other
operator|.
name|isRowMajorLayout
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator ==
name|bool
name|InterfaceBlockField
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|InterfaceBlockField
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|ShaderVariable
operator|::
name|operator
name|==
argument_list|(
name|other
argument_list|)
operator|&&
name|isRowMajorLayout
operator|==
name|other
operator|.
name|isRowMajorLayout
operator|)
return|;
block|}
DECL|function|isSameInterfaceBlockFieldAtLinkTime
name|bool
name|InterfaceBlockField
operator|::
name|isSameInterfaceBlockFieldAtLinkTime
parameter_list|(
specifier|const
name|InterfaceBlockField
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|ShaderVariable
operator|::
name|isSameVariableAtLinkTime
argument_list|(
name|other
argument_list|,
literal|true
argument_list|)
operator|&&
name|isRowMajorLayout
operator|==
name|other
operator|.
name|isRowMajorLayout
operator|)
return|;
block|}
DECL|function|Varying
name|Varying
operator|::
name|Varying
parameter_list|()
member_init_list|:
name|interpolation
argument_list|(
name|INTERPOLATION_SMOOTH
argument_list|)
member_init_list|,
name|isInvariant
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|~Varying
name|Varying
operator|::
name|~
name|Varying
parameter_list|()
block|{}
DECL|function|Varying
name|Varying
operator|::
name|Varying
parameter_list|(
specifier|const
name|Varying
modifier|&
name|other
parameter_list|)
member_init_list|:
name|ShaderVariable
argument_list|(
name|other
argument_list|)
member_init_list|,
name|interpolation
argument_list|(
name|other
operator|.
name|interpolation
argument_list|)
member_init_list|,
name|isInvariant
argument_list|(
name|other
operator|.
name|isInvariant
argument_list|)
block|{}
DECL|function|operator =
name|Varying
modifier|&
name|Varying
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|Varying
modifier|&
name|other
parameter_list|)
block|{
name|ShaderVariable
operator|::
name|operator
name|=
parameter_list|(
name|other
parameter_list|)
function_decl|;
name|interpolation
operator|=
name|other
operator|.
name|interpolation
expr_stmt|;
name|isInvariant
operator|=
name|other
operator|.
name|isInvariant
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|operator ==
name|bool
name|Varying
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|Varying
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|ShaderVariable
operator|::
name|operator
name|==
argument_list|(
name|other
argument_list|)
operator|&&
name|interpolation
operator|==
name|other
operator|.
name|interpolation
operator|&&
name|isInvariant
operator|==
name|other
operator|.
name|isInvariant
operator|)
return|;
block|}
DECL|function|isSameVaryingAtLinkTime
name|bool
name|Varying
operator|::
name|isSameVaryingAtLinkTime
parameter_list|(
specifier|const
name|Varying
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|ShaderVariable
operator|::
name|isSameVariableAtLinkTime
argument_list|(
name|other
argument_list|,
literal|false
argument_list|)
operator|&&
name|interpolation
operator|==
name|other
operator|.
name|interpolation
operator|&&
name|isInvariant
operator|==
name|other
operator|.
name|isInvariant
operator|)
return|;
block|}
DECL|function|InterfaceBlock
name|InterfaceBlock
operator|::
name|InterfaceBlock
parameter_list|()
member_init_list|:
name|arraySize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|layout
argument_list|(
name|BLOCKLAYOUT_PACKED
argument_list|)
member_init_list|,
name|isRowMajorLayout
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|staticUse
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|~InterfaceBlock
name|InterfaceBlock
operator|::
name|~
name|InterfaceBlock
parameter_list|()
block|{}
DECL|function|InterfaceBlock
name|InterfaceBlock
operator|::
name|InterfaceBlock
parameter_list|(
specifier|const
name|InterfaceBlock
modifier|&
name|other
parameter_list|)
member_init_list|:
name|name
argument_list|(
name|other
operator|.
name|name
argument_list|)
member_init_list|,
name|mappedName
argument_list|(
name|other
operator|.
name|mappedName
argument_list|)
member_init_list|,
name|instanceName
argument_list|(
name|other
operator|.
name|instanceName
argument_list|)
member_init_list|,
name|arraySize
argument_list|(
name|other
operator|.
name|arraySize
argument_list|)
member_init_list|,
name|layout
argument_list|(
name|other
operator|.
name|layout
argument_list|)
member_init_list|,
name|isRowMajorLayout
argument_list|(
name|other
operator|.
name|isRowMajorLayout
argument_list|)
member_init_list|,
name|staticUse
argument_list|(
name|other
operator|.
name|staticUse
argument_list|)
member_init_list|,
name|fields
argument_list|(
name|other
operator|.
name|fields
argument_list|)
block|{}
DECL|function|operator =
name|InterfaceBlock
modifier|&
name|InterfaceBlock
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|InterfaceBlock
modifier|&
name|other
parameter_list|)
block|{
name|name
operator|=
name|other
operator|.
name|name
expr_stmt|;
name|mappedName
operator|=
name|other
operator|.
name|mappedName
expr_stmt|;
name|instanceName
operator|=
name|other
operator|.
name|instanceName
expr_stmt|;
name|arraySize
operator|=
name|other
operator|.
name|arraySize
expr_stmt|;
name|layout
operator|=
name|other
operator|.
name|layout
expr_stmt|;
name|isRowMajorLayout
operator|=
name|other
operator|.
name|isRowMajorLayout
expr_stmt|;
name|staticUse
operator|=
name|other
operator|.
name|staticUse
expr_stmt|;
name|fields
operator|=
name|other
operator|.
name|fields
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
block|}
end_namespace
end_unit
