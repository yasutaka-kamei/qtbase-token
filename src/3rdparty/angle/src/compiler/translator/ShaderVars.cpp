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