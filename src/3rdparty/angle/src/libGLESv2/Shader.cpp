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
begin_comment
comment|// Shader.cpp: Implements the gl::Shader class and its  derived classes
end_comment
begin_comment
comment|// VertexShader and FragmentShader. Implements GL shader objects and related
end_comment
begin_comment
comment|// functionality. [OpenGL ES 2.0.24] section 2.10 page 24 and section 3.8 page 84.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/Shader.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/ShaderImpl.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Constants.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/ResourceManager.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_include
include|#
directive|include
file|"GLSLANG/ShaderLang.h"
end_include
begin_include
include|#
directive|include
file|<sstream>
end_include
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|function|Shader
name|Shader
operator|::
name|Shader
parameter_list|(
name|ResourceManager
modifier|*
name|manager
parameter_list|,
name|rx
operator|::
name|ShaderImpl
modifier|*
name|impl
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLuint
name|handle
parameter_list|)
member_init_list|:
name|mShader
argument_list|(
name|impl
argument_list|)
member_init_list|,
name|mType
argument_list|(
name|type
argument_list|)
member_init_list|,
name|mHandle
argument_list|(
name|handle
argument_list|)
member_init_list|,
name|mResourceManager
argument_list|(
name|manager
argument_list|)
member_init_list|,
name|mRefCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mDeleteStatus
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mCompiled
argument_list|(
literal|false
argument_list|)
block|{
name|ASSERT
argument_list|(
name|impl
argument_list|)
expr_stmt|;
block|}
DECL|function|~Shader
name|Shader
operator|::
name|~
name|Shader
parameter_list|()
block|{
name|SafeDelete
argument_list|(
name|mShader
argument_list|)
expr_stmt|;
block|}
DECL|function|getHandle
name|GLuint
name|Shader
operator|::
name|getHandle
parameter_list|()
specifier|const
block|{
return|return
name|mHandle
return|;
block|}
DECL|function|setSource
name|void
name|Shader
operator|::
name|setSource
parameter_list|(
name|GLsizei
name|count
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|string
parameter_list|,
specifier|const
name|GLint
modifier|*
name|length
parameter_list|)
block|{
name|std
operator|::
name|ostringstream
name|stream
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
name|stream
operator|<<
name|string
index|[
name|i
index|]
expr_stmt|;
block|}
name|mSource
operator|=
name|stream
operator|.
name|str
argument_list|()
expr_stmt|;
block|}
DECL|function|getInfoLogLength
name|int
name|Shader
operator|::
name|getInfoLogLength
parameter_list|()
specifier|const
block|{
return|return
name|mShader
operator|->
name|getInfoLog
argument_list|()
operator|.
name|empty
argument_list|()
condition|?
literal|0
else|:
operator|(
name|mShader
operator|->
name|getInfoLog
argument_list|()
operator|.
name|length
argument_list|()
operator|+
literal|1
operator|)
return|;
block|}
DECL|function|getInfoLog
name|void
name|Shader
operator|::
name|getInfoLog
parameter_list|(
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|char
modifier|*
name|infoLog
parameter_list|)
specifier|const
block|{
name|int
name|index
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|bufSize
operator|>
literal|0
condition|)
block|{
name|index
operator|=
name|std
operator|::
name|min
argument_list|(
name|bufSize
operator|-
literal|1
argument_list|,
cast|static_cast
argument_list|<
name|GLsizei
argument_list|>
argument_list|(
name|mShader
operator|->
name|getInfoLog
argument_list|()
operator|.
name|length
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|infoLog
argument_list|,
name|mShader
operator|->
name|getInfoLog
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|,
name|index
argument_list|)
expr_stmt|;
name|infoLog
index|[
name|index
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
name|length
condition|)
block|{
operator|*
name|length
operator|=
name|index
expr_stmt|;
block|}
block|}
DECL|function|getSourceLength
name|int
name|Shader
operator|::
name|getSourceLength
parameter_list|()
specifier|const
block|{
return|return
name|mSource
operator|.
name|empty
argument_list|()
condition|?
literal|0
else|:
operator|(
name|mSource
operator|.
name|length
argument_list|()
operator|+
literal|1
operator|)
return|;
block|}
DECL|function|getTranslatedSourceLength
name|int
name|Shader
operator|::
name|getTranslatedSourceLength
parameter_list|()
specifier|const
block|{
return|return
name|mShader
operator|->
name|getTranslatedSource
argument_list|()
operator|.
name|empty
argument_list|()
condition|?
literal|0
else|:
operator|(
name|mShader
operator|->
name|getTranslatedSource
argument_list|()
operator|.
name|length
argument_list|()
operator|+
literal|1
operator|)
return|;
block|}
DECL|function|getSourceImpl
name|void
name|Shader
operator|::
name|getSourceImpl
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|source
parameter_list|,
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
block|{
name|int
name|index
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|bufSize
operator|>
literal|0
condition|)
block|{
name|index
operator|=
name|std
operator|::
name|min
argument_list|(
name|bufSize
operator|-
literal|1
argument_list|,
cast|static_cast
argument_list|<
name|GLsizei
argument_list|>
argument_list|(
name|source
operator|.
name|length
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|buffer
argument_list|,
name|source
operator|.
name|c_str
argument_list|()
argument_list|,
name|index
argument_list|)
expr_stmt|;
name|buffer
index|[
name|index
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
name|length
condition|)
block|{
operator|*
name|length
operator|=
name|index
expr_stmt|;
block|}
block|}
DECL|function|getSource
name|void
name|Shader
operator|::
name|getSource
parameter_list|(
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
specifier|const
block|{
name|getSourceImpl
argument_list|(
name|mSource
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
block|}
DECL|function|getTranslatedSource
name|void
name|Shader
operator|::
name|getTranslatedSource
parameter_list|(
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
specifier|const
block|{
name|getSourceImpl
argument_list|(
name|mShader
operator|->
name|getTranslatedSource
argument_list|()
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
block|}
DECL|function|compile
name|void
name|Shader
operator|::
name|compile
parameter_list|()
block|{
name|mCompiled
operator|=
name|mShader
operator|->
name|compile
argument_list|(
name|mSource
argument_list|)
expr_stmt|;
block|}
DECL|function|addRef
name|void
name|Shader
operator|::
name|addRef
parameter_list|()
block|{
name|mRefCount
operator|++
expr_stmt|;
block|}
DECL|function|release
name|void
name|Shader
operator|::
name|release
parameter_list|()
block|{
name|mRefCount
operator|--
expr_stmt|;
if|if
condition|(
name|mRefCount
operator|==
literal|0
operator|&&
name|mDeleteStatus
condition|)
block|{
name|mResourceManager
operator|->
name|deleteShader
argument_list|(
name|mHandle
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|getRefCount
name|unsigned
name|int
name|Shader
operator|::
name|getRefCount
parameter_list|()
specifier|const
block|{
return|return
name|mRefCount
return|;
block|}
DECL|function|isFlaggedForDeletion
name|bool
name|Shader
operator|::
name|isFlaggedForDeletion
parameter_list|()
specifier|const
block|{
return|return
name|mDeleteStatus
return|;
block|}
DECL|function|flagForDeletion
name|void
name|Shader
operator|::
name|flagForDeletion
parameter_list|()
block|{
name|mDeleteStatus
operator|=
literal|true
expr_stmt|;
block|}
DECL|function|getVaryings
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|gl
operator|::
name|PackedVarying
argument_list|>
modifier|&
name|Shader
operator|::
name|getVaryings
parameter_list|()
specifier|const
block|{
return|return
name|mShader
operator|->
name|getVaryings
argument_list|()
return|;
block|}
DECL|function|getUniforms
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|Uniform
argument_list|>
modifier|&
name|Shader
operator|::
name|getUniforms
parameter_list|()
specifier|const
block|{
return|return
name|mShader
operator|->
name|getUniforms
argument_list|()
return|;
block|}
DECL|function|getInterfaceBlocks
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|InterfaceBlock
argument_list|>
modifier|&
name|Shader
operator|::
name|getInterfaceBlocks
parameter_list|()
specifier|const
block|{
return|return
name|mShader
operator|->
name|getInterfaceBlocks
argument_list|()
return|;
block|}
DECL|function|getActiveAttributes
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|Attribute
argument_list|>
modifier|&
name|Shader
operator|::
name|getActiveAttributes
parameter_list|()
specifier|const
block|{
return|return
name|mShader
operator|->
name|getActiveAttributes
argument_list|()
return|;
block|}
DECL|function|getActiveOutputVariables
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|Attribute
argument_list|>
modifier|&
name|Shader
operator|::
name|getActiveOutputVariables
parameter_list|()
specifier|const
block|{
return|return
name|mShader
operator|->
name|getActiveOutputVariables
argument_list|()
return|;
block|}
DECL|function|getVaryings
name|std
operator|::
name|vector
argument_list|<
name|gl
operator|::
name|PackedVarying
argument_list|>
modifier|&
name|Shader
operator|::
name|getVaryings
parameter_list|()
block|{
return|return
name|mShader
operator|->
name|getVaryings
argument_list|()
return|;
block|}
DECL|function|getUniforms
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|Uniform
argument_list|>
modifier|&
name|Shader
operator|::
name|getUniforms
parameter_list|()
block|{
return|return
name|mShader
operator|->
name|getUniforms
argument_list|()
return|;
block|}
DECL|function|getInterfaceBlocks
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|InterfaceBlock
argument_list|>
modifier|&
name|Shader
operator|::
name|getInterfaceBlocks
parameter_list|()
block|{
return|return
name|mShader
operator|->
name|getInterfaceBlocks
argument_list|()
return|;
block|}
DECL|function|getActiveAttributes
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|Attribute
argument_list|>
modifier|&
name|Shader
operator|::
name|getActiveAttributes
parameter_list|()
block|{
return|return
name|mShader
operator|->
name|getActiveAttributes
argument_list|()
return|;
block|}
DECL|function|getActiveOutputVariables
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|Attribute
argument_list|>
modifier|&
name|Shader
operator|::
name|getActiveOutputVariables
parameter_list|()
block|{
return|return
name|mShader
operator|->
name|getActiveOutputVariables
argument_list|()
return|;
block|}
block|}
end_namespace
end_unit
