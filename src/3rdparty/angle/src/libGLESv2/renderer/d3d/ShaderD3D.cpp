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
comment|// ShaderD3D.cpp: Defines the rx::ShaderD3D class which implements rx::ShaderImpl.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/Shader.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/main.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/RendererD3D.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/ShaderD3D.h"
end_include
begin_include
include|#
directive|include
file|"common/features.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_comment
comment|// Definitions local to the translation unit
end_comment
begin_namespace
namespace|namespace
block|{
DECL|function|GetShaderTypeString
specifier|const
name|char
modifier|*
name|GetShaderTypeString
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_VERTEX_SHADER
case|:
return|return
literal|"VERTEX"
return|;
case|case
name|GL_FRAGMENT_SHADER
case|:
return|return
literal|"FRAGMENT"
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
literal|""
return|;
block|}
block|}
block|}
end_namespace
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
template|template
parameter_list|<
name|typename
name|VarT
parameter_list|>
DECL|function|FilterInactiveVariables
name|void
name|FilterInactiveVariables
parameter_list|(
name|std
operator|::
name|vector
argument_list|<
name|VarT
argument_list|>
modifier|*
name|variableList
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|variableList
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|varIndex
init|=
literal|0
init|;
name|varIndex
operator|<
name|variableList
operator|->
name|size
argument_list|()
condition|;
control|)
block|{
if|if
condition|(
operator|!
operator|(
operator|*
name|variableList
operator|)
index|[
name|varIndex
index|]
operator|.
name|staticUse
condition|)
block|{
name|variableList
operator|->
name|erase
argument_list|(
name|variableList
operator|->
name|begin
argument_list|()
operator|+
name|varIndex
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|varIndex
operator|++
expr_stmt|;
block|}
block|}
block|}
DECL|member|mFragmentCompiler
name|void
modifier|*
name|ShaderD3D
operator|::
name|mFragmentCompiler
init|=
name|NULL
decl_stmt|;
DECL|member|mVertexCompiler
name|void
modifier|*
name|ShaderD3D
operator|::
name|mVertexCompiler
init|=
name|NULL
decl_stmt|;
template|template
parameter_list|<
name|typename
name|VarT
parameter_list|>
DECL|function|GetShaderVariables
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|VarT
argument_list|>
modifier|*
name|GetShaderVariables
parameter_list|(
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|VarT
argument_list|>
modifier|*
name|variableList
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|variableList
argument_list|)
expr_stmt|;
return|return
name|variableList
return|;
block|}
DECL|function|ShaderD3D
name|ShaderD3D
operator|::
name|ShaderD3D
parameter_list|(
specifier|const
name|gl
operator|::
name|Data
modifier|&
name|data
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|RendererD3D
modifier|*
name|renderer
parameter_list|)
member_init_list|:
name|mType
argument_list|(
name|type
argument_list|)
member_init_list|,
name|mRenderer
argument_list|(
name|renderer
argument_list|)
member_init_list|,
name|mShaderVersion
argument_list|(
literal|100
argument_list|)
block|{
name|uncompile
argument_list|()
expr_stmt|;
name|initializeCompiler
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
DECL|function|~ShaderD3D
name|ShaderD3D
operator|::
name|~
name|ShaderD3D
parameter_list|()
block|{ }
DECL|function|makeShaderD3D
name|ShaderD3D
modifier|*
name|ShaderD3D
operator|::
name|makeShaderD3D
parameter_list|(
name|ShaderImpl
modifier|*
name|impl
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|HAS_DYNAMIC_TYPE
argument_list|(
name|ShaderD3D
operator|*
argument_list|,
name|impl
argument_list|)
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|ShaderD3D
operator|*
argument_list|>
argument_list|(
name|impl
argument_list|)
return|;
block|}
DECL|function|makeShaderD3D
specifier|const
name|ShaderD3D
modifier|*
name|ShaderD3D
operator|::
name|makeShaderD3D
parameter_list|(
specifier|const
name|ShaderImpl
modifier|*
name|impl
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|HAS_DYNAMIC_TYPE
argument_list|(
specifier|const
name|ShaderD3D
operator|*
argument_list|,
name|impl
argument_list|)
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
specifier|const
name|ShaderD3D
operator|*
argument_list|>
argument_list|(
name|impl
argument_list|)
return|;
block|}
DECL|function|getDebugInfo
name|std
operator|::
name|string
name|ShaderD3D
operator|::
name|getDebugInfo
parameter_list|()
specifier|const
block|{
return|return
name|mDebugInfo
operator|+
name|std
operator|::
name|string
argument_list|(
literal|"\n// "
argument_list|)
operator|+
name|GetShaderTypeString
argument_list|(
name|mType
argument_list|)
operator|+
literal|" SHADER END\n"
return|;
block|}
comment|// Perform a one-time initialization of the shader compiler (or after being destructed by releaseCompiler)
DECL|function|initializeCompiler
name|void
name|ShaderD3D
operator|::
name|initializeCompiler
parameter_list|(
specifier|const
name|gl
operator|::
name|Data
modifier|&
name|data
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mFragmentCompiler
condition|)
block|{
name|bool
name|result
init|=
name|ShInitialize
argument_list|()
decl_stmt|;
if|if
condition|(
name|result
condition|)
block|{
name|ShShaderSpec
name|specVersion
init|=
operator|(
name|data
operator|.
name|clientVersion
operator|>=
literal|3
operator|)
condition|?
name|SH_GLES3_SPEC
else|:
name|SH_GLES2_SPEC
decl_stmt|;
name|ShShaderOutput
name|hlslVersion
init|=
operator|(
name|mRenderer
operator|->
name|getMajorShaderModel
argument_list|()
operator|>=
literal|4
operator|)
condition|?
name|SH_HLSL11_OUTPUT
else|:
name|SH_HLSL9_OUTPUT
decl_stmt|;
name|ShBuiltInResources
name|resources
decl_stmt|;
name|ShInitBuiltInResources
argument_list|(
operator|&
name|resources
argument_list|)
expr_stmt|;
specifier|const
name|gl
operator|::
name|Caps
modifier|&
name|caps
init|=
operator|*
name|data
operator|.
name|caps
decl_stmt|;
specifier|const
name|gl
operator|::
name|Extensions
modifier|&
name|extensions
init|=
operator|*
name|data
operator|.
name|extensions
decl_stmt|;
name|resources
operator|.
name|MaxVertexAttribs
operator|=
name|caps
operator|.
name|maxVertexAttributes
expr_stmt|;
name|resources
operator|.
name|MaxVertexUniformVectors
operator|=
name|caps
operator|.
name|maxVertexUniformVectors
expr_stmt|;
name|resources
operator|.
name|MaxVaryingVectors
operator|=
name|caps
operator|.
name|maxVaryingVectors
expr_stmt|;
name|resources
operator|.
name|MaxVertexTextureImageUnits
operator|=
name|caps
operator|.
name|maxVertexTextureImageUnits
expr_stmt|;
name|resources
operator|.
name|MaxCombinedTextureImageUnits
operator|=
name|caps
operator|.
name|maxCombinedTextureImageUnits
expr_stmt|;
name|resources
operator|.
name|MaxTextureImageUnits
operator|=
name|caps
operator|.
name|maxTextureImageUnits
expr_stmt|;
name|resources
operator|.
name|MaxFragmentUniformVectors
operator|=
name|caps
operator|.
name|maxFragmentUniformVectors
expr_stmt|;
name|resources
operator|.
name|MaxDrawBuffers
operator|=
name|caps
operator|.
name|maxDrawBuffers
expr_stmt|;
name|resources
operator|.
name|OES_standard_derivatives
operator|=
name|extensions
operator|.
name|standardDerivatives
expr_stmt|;
name|resources
operator|.
name|EXT_draw_buffers
operator|=
name|extensions
operator|.
name|drawBuffers
expr_stmt|;
name|resources
operator|.
name|EXT_shader_texture_lod
operator|=
literal|1
expr_stmt|;
comment|// resources.OES_EGL_image_external = mRenderer->getShareHandleSupport() ? 1 : 0; // TODO: commented out until the extension is actually supported.
name|resources
operator|.
name|FragmentPrecisionHigh
operator|=
literal|1
expr_stmt|;
comment|// Shader Model 2+ always supports FP24 (s16e7) which corresponds to highp
name|resources
operator|.
name|EXT_frag_depth
operator|=
literal|1
expr_stmt|;
comment|// Shader Model 2+ always supports explicit depth output
comment|// GLSL ES 3.0 constants
name|resources
operator|.
name|MaxVertexOutputVectors
operator|=
name|caps
operator|.
name|maxVertexOutputComponents
operator|/
literal|4
expr_stmt|;
name|resources
operator|.
name|MaxFragmentInputVectors
operator|=
name|caps
operator|.
name|maxFragmentInputComponents
operator|/
literal|4
expr_stmt|;
name|resources
operator|.
name|MinProgramTexelOffset
operator|=
name|caps
operator|.
name|minProgramTexelOffset
expr_stmt|;
name|resources
operator|.
name|MaxProgramTexelOffset
operator|=
name|caps
operator|.
name|maxProgramTexelOffset
expr_stmt|;
name|mFragmentCompiler
operator|=
name|ShConstructCompiler
argument_list|(
name|GL_FRAGMENT_SHADER
argument_list|,
name|specVersion
argument_list|,
name|hlslVersion
argument_list|,
operator|&
name|resources
argument_list|)
expr_stmt|;
name|mVertexCompiler
operator|=
name|ShConstructCompiler
argument_list|(
name|GL_VERTEX_SHADER
argument_list|,
name|specVersion
argument_list|,
name|hlslVersion
argument_list|,
operator|&
name|resources
argument_list|)
expr_stmt|;
block|}
block|}
block|}
DECL|function|releaseCompiler
name|void
name|ShaderD3D
operator|::
name|releaseCompiler
parameter_list|()
block|{
name|ShDestruct
argument_list|(
name|mFragmentCompiler
argument_list|)
expr_stmt|;
name|ShDestruct
argument_list|(
name|mVertexCompiler
argument_list|)
expr_stmt|;
name|mFragmentCompiler
operator|=
name|NULL
expr_stmt|;
name|mVertexCompiler
operator|=
name|NULL
expr_stmt|;
name|ShFinalize
argument_list|()
expr_stmt|;
block|}
DECL|function|parseVaryings
name|void
name|ShaderD3D
operator|::
name|parseVaryings
parameter_list|(
name|void
modifier|*
name|compiler
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mHlsl
operator|.
name|empty
argument_list|()
condition|)
block|{
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|sh
operator|::
name|Varying
argument_list|>
modifier|*
name|varyings
init|=
name|ShGetVaryings
argument_list|(
name|compiler
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|varyings
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|varyingIndex
init|=
literal|0
init|;
name|varyingIndex
operator|<
name|varyings
operator|->
name|size
argument_list|()
condition|;
name|varyingIndex
operator|++
control|)
block|{
name|mVaryings
operator|.
name|push_back
argument_list|(
name|gl
operator|::
name|PackedVarying
argument_list|(
operator|(
operator|*
name|varyings
operator|)
index|[
name|varyingIndex
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|mUsesMultipleRenderTargets
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"GL_USES_MRT"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
name|mUsesFragColor
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"GL_USES_FRAG_COLOR"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
name|mUsesFragData
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"GL_USES_FRAG_DATA"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
name|mUsesFragCoord
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"GL_USES_FRAG_COORD"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
name|mUsesFrontFacing
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"GL_USES_FRONT_FACING"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
name|mUsesPointSize
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"GL_USES_POINT_SIZE"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
name|mUsesPointCoord
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"GL_USES_POINT_COORD"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
name|mUsesDepthRange
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"GL_USES_DEPTH_RANGE"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
name|mUsesFragDepth
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"GL_USES_FRAG_DEPTH"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
name|mUsesDiscardRewriting
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"ANGLE_USES_DISCARD_REWRITING"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
name|mUsesNestedBreak
operator|=
name|mHlsl
operator|.
name|find
argument_list|(
literal|"ANGLE_USES_NESTED_BREAK"
argument_list|)
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
expr_stmt|;
block|}
block|}
DECL|function|resetVaryingsRegisterAssignment
name|void
name|ShaderD3D
operator|::
name|resetVaryingsRegisterAssignment
parameter_list|()
block|{
for|for
control|(
name|size_t
name|varyingIndex
init|=
literal|0
init|;
name|varyingIndex
operator|<
name|mVaryings
operator|.
name|size
argument_list|()
condition|;
name|varyingIndex
operator|++
control|)
block|{
name|mVaryings
index|[
name|varyingIndex
index|]
operator|.
name|resetRegisterAssignment
argument_list|()
expr_stmt|;
block|}
block|}
comment|// initialize/clean up previous state
DECL|function|uncompile
name|void
name|ShaderD3D
operator|::
name|uncompile
parameter_list|()
block|{
comment|// set by compileToHLSL
name|mHlsl
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mInfoLog
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mUsesMultipleRenderTargets
operator|=
literal|false
expr_stmt|;
name|mUsesFragColor
operator|=
literal|false
expr_stmt|;
name|mUsesFragData
operator|=
literal|false
expr_stmt|;
name|mUsesFragCoord
operator|=
literal|false
expr_stmt|;
name|mUsesFrontFacing
operator|=
literal|false
expr_stmt|;
name|mUsesPointSize
operator|=
literal|false
expr_stmt|;
name|mUsesPointCoord
operator|=
literal|false
expr_stmt|;
name|mUsesDepthRange
operator|=
literal|false
expr_stmt|;
name|mUsesFragDepth
operator|=
literal|false
expr_stmt|;
name|mShaderVersion
operator|=
literal|100
expr_stmt|;
name|mUsesDiscardRewriting
operator|=
literal|false
expr_stmt|;
name|mUsesNestedBreak
operator|=
literal|false
expr_stmt|;
name|mVaryings
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mUniforms
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mInterfaceBlocks
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mActiveAttributes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mActiveOutputVariables
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mDebugInfo
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|compileToHLSL
name|void
name|ShaderD3D
operator|::
name|compileToHLSL
parameter_list|(
specifier|const
name|gl
operator|::
name|Data
modifier|&
name|data
parameter_list|,
name|void
modifier|*
name|compiler
parameter_list|,
specifier|const
name|std
operator|::
name|string
modifier|&
name|source
parameter_list|)
block|{
comment|// ensure the compiler is loaded
name|initializeCompiler
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|int
name|compileOptions
init|=
operator|(
name|SH_OBJECT_CODE
operator||
name|SH_VARIABLES
operator|)
decl_stmt|;
name|std
operator|::
name|string
name|sourcePath
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
if|if
condition|(
name|gl
operator|::
name|perfActive
argument_list|()
condition|)
block|{
name|sourcePath
operator|=
name|getTempPath
argument_list|()
expr_stmt|;
name|writeFile
argument_list|(
name|sourcePath
operator|.
name|c_str
argument_list|()
argument_list|,
name|source
operator|.
name|c_str
argument_list|()
argument_list|,
name|source
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
name|compileOptions
operator||=
name|SH_LINE_DIRECTIVES
expr_stmt|;
block|}
endif|#
directive|endif
name|int
name|result
decl_stmt|;
if|if
condition|(
name|sourcePath
operator|.
name|empty
argument_list|()
condition|)
block|{
specifier|const
name|char
modifier|*
name|sourceStrings
index|[]
init|=
block|{
name|source
operator|.
name|c_str
argument_list|()
block|,         }
decl_stmt|;
name|result
operator|=
name|ShCompile
argument_list|(
name|compiler
argument_list|,
name|sourceStrings
argument_list|,
name|ArraySize
argument_list|(
name|sourceStrings
argument_list|)
argument_list|,
name|compileOptions
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|char
modifier|*
name|sourceStrings
index|[]
init|=
block|{
name|sourcePath
operator|.
name|c_str
argument_list|()
block|,
name|source
operator|.
name|c_str
argument_list|()
block|,         }
decl_stmt|;
name|result
operator|=
name|ShCompile
argument_list|(
name|compiler
argument_list|,
name|sourceStrings
argument_list|,
name|ArraySize
argument_list|(
name|sourceStrings
argument_list|)
argument_list|,
name|compileOptions
operator||
name|SH_SOURCE_PATH
argument_list|)
expr_stmt|;
block|}
name|mShaderVersion
operator|=
name|ShGetShaderVersion
argument_list|(
name|compiler
argument_list|)
expr_stmt|;
if|if
condition|(
name|mShaderVersion
operator|==
literal|300
operator|&&
name|data
operator|.
name|clientVersion
operator|<
literal|3
condition|)
block|{
name|mInfoLog
operator|=
literal|"GLSL ES 3.00 is not supported by OpenGL ES 2.0 contexts"
expr_stmt|;
name|TRACE
argument_list|(
literal|"\n%s"
argument_list|,
name|mInfoLog
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|result
condition|)
block|{
name|mHlsl
operator|=
name|ShGetObjectCode
argument_list|(
name|compiler
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_DEBUG
comment|// Prefix hlsl shader with commented out glsl shader
comment|// Useful in diagnostics tools like pix which capture the hlsl shaders
name|std
operator|::
name|ostringstream
name|hlslStream
decl_stmt|;
name|hlslStream
operator|<<
literal|"// GLSL\n"
expr_stmt|;
name|hlslStream
operator|<<
literal|"//\n"
expr_stmt|;
name|size_t
name|curPos
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|curPos
operator|!=
name|std
operator|::
name|string
operator|::
name|npos
condition|)
block|{
name|size_t
name|nextLine
init|=
name|source
operator|.
name|find
argument_list|(
literal|"\n"
argument_list|,
name|curPos
argument_list|)
decl_stmt|;
name|size_t
name|len
init|=
operator|(
name|nextLine
operator|==
name|std
operator|::
name|string
operator|::
name|npos
operator|)
condition|?
name|std
operator|::
name|string
operator|::
name|npos
else|:
operator|(
name|nextLine
operator|-
name|curPos
operator|+
literal|1
operator|)
decl_stmt|;
name|hlslStream
operator|<<
literal|"// "
operator|<<
name|source
operator|.
name|substr
argument_list|(
name|curPos
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|curPos
operator|=
operator|(
name|nextLine
operator|==
name|std
operator|::
name|string
operator|::
name|npos
operator|)
condition|?
name|std
operator|::
name|string
operator|::
name|npos
else|:
operator|(
name|nextLine
operator|+
literal|1
operator|)
expr_stmt|;
block|}
name|hlslStream
operator|<<
literal|"\n\n"
expr_stmt|;
name|hlslStream
operator|<<
name|mHlsl
expr_stmt|;
name|mHlsl
operator|=
name|hlslStream
operator|.
name|str
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|mUniforms
operator|=
operator|*
name|GetShaderVariables
argument_list|(
name|ShGetUniforms
argument_list|(
name|compiler
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|uniformIndex
init|=
literal|0
init|;
name|uniformIndex
operator|<
name|mUniforms
operator|.
name|size
argument_list|()
condition|;
name|uniformIndex
operator|++
control|)
block|{
specifier|const
name|sh
operator|::
name|Uniform
modifier|&
name|uniform
init|=
name|mUniforms
index|[
name|uniformIndex
index|]
decl_stmt|;
if|if
condition|(
name|uniform
operator|.
name|staticUse
condition|)
block|{
name|unsigned
name|int
name|index
init|=
operator|-
literal|1
decl_stmt|;
name|bool
name|result
init|=
name|ShGetUniformRegister
argument_list|(
name|compiler
argument_list|,
name|uniform
operator|.
name|name
argument_list|,
operator|&
name|index
argument_list|)
decl_stmt|;
name|UNUSED_ASSERTION_VARIABLE
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|mUniformRegisterMap
index|[
name|uniform
operator|.
name|name
index|]
operator|=
name|index
expr_stmt|;
block|}
block|}
name|mInterfaceBlocks
operator|=
operator|*
name|GetShaderVariables
argument_list|(
name|ShGetInterfaceBlocks
argument_list|(
name|compiler
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|blockIndex
init|=
literal|0
init|;
name|blockIndex
operator|<
name|mInterfaceBlocks
operator|.
name|size
argument_list|()
condition|;
name|blockIndex
operator|++
control|)
block|{
specifier|const
name|sh
operator|::
name|InterfaceBlock
modifier|&
name|interfaceBlock
init|=
name|mInterfaceBlocks
index|[
name|blockIndex
index|]
decl_stmt|;
if|if
condition|(
name|interfaceBlock
operator|.
name|staticUse
condition|)
block|{
name|unsigned
name|int
name|index
init|=
operator|-
literal|1
decl_stmt|;
name|bool
name|result
init|=
name|ShGetInterfaceBlockRegister
argument_list|(
name|compiler
argument_list|,
name|interfaceBlock
operator|.
name|name
argument_list|,
operator|&
name|index
argument_list|)
decl_stmt|;
name|UNUSED_ASSERTION_VARIABLE
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|mInterfaceBlockRegisterMap
index|[
name|interfaceBlock
operator|.
name|name
index|]
operator|=
name|index
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|mInfoLog
operator|=
name|ShGetInfoLog
argument_list|(
name|compiler
argument_list|)
expr_stmt|;
name|TRACE
argument_list|(
literal|"\n%s"
argument_list|,
name|mInfoLog
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|getD3DWorkarounds
name|D3DWorkaroundType
name|ShaderD3D
operator|::
name|getD3DWorkarounds
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|mUsesDiscardRewriting
condition|)
block|{
comment|// ANGLE issue 486:
comment|// Work-around a D3D9 compiler bug that presents itself when using conditional discard, by disabling optimization
return|return
name|ANGLE_D3D_WORKAROUND_SKIP_OPTIMIZATION
return|;
block|}
if|if
condition|(
name|mUsesNestedBreak
condition|)
block|{
comment|// ANGLE issue 603:
comment|// Work-around a D3D9 compiler bug that presents itself when using break in a nested loop, by maximizing optimization
comment|// We want to keep the use of ANGLE_D3D_WORKAROUND_MAX_OPTIMIZATION minimal to prevent hangs, so usesDiscard takes precedence
return|return
name|ANGLE_D3D_WORKAROUND_MAX_OPTIMIZATION
return|;
block|}
return|return
name|ANGLE_D3D_WORKAROUND_NONE
return|;
block|}
comment|// true if varying x has a higher priority in packing than y
DECL|function|compareVarying
name|bool
name|ShaderD3D
operator|::
name|compareVarying
parameter_list|(
specifier|const
name|gl
operator|::
name|PackedVarying
modifier|&
name|x
parameter_list|,
specifier|const
name|gl
operator|::
name|PackedVarying
modifier|&
name|y
parameter_list|)
block|{
if|if
condition|(
name|x
operator|.
name|type
operator|==
name|y
operator|.
name|type
condition|)
block|{
return|return
name|x
operator|.
name|arraySize
operator|>
name|y
operator|.
name|arraySize
return|;
block|}
comment|// Special case for handling structs: we sort these to the end of the list
if|if
condition|(
name|x
operator|.
name|type
operator|==
name|GL_STRUCT_ANGLEX
condition|)
block|{
return|return
literal|false
return|;
block|}
if|if
condition|(
name|y
operator|.
name|type
operator|==
name|GL_STRUCT_ANGLEX
condition|)
block|{
return|return
literal|true
return|;
block|}
return|return
name|gl
operator|::
name|VariableSortOrder
argument_list|(
name|x
operator|.
name|type
argument_list|)
operator|<
name|gl
operator|::
name|VariableSortOrder
argument_list|(
name|y
operator|.
name|type
argument_list|)
return|;
block|}
DECL|function|getUniformRegister
name|unsigned
name|int
name|ShaderD3D
operator|::
name|getUniformRegister
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|uniformName
parameter_list|)
specifier|const
block|{
name|ASSERT
argument_list|(
name|mUniformRegisterMap
operator|.
name|count
argument_list|(
name|uniformName
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
return|return
name|mUniformRegisterMap
operator|.
name|find
argument_list|(
name|uniformName
argument_list|)
operator|->
name|second
return|;
block|}
DECL|function|getInterfaceBlockRegister
name|unsigned
name|int
name|ShaderD3D
operator|::
name|getInterfaceBlockRegister
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|blockName
parameter_list|)
specifier|const
block|{
name|ASSERT
argument_list|(
name|mInterfaceBlockRegisterMap
operator|.
name|count
argument_list|(
name|blockName
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
return|return
name|mInterfaceBlockRegisterMap
operator|.
name|find
argument_list|(
name|blockName
argument_list|)
operator|->
name|second
return|;
block|}
DECL|function|getCompiler
name|void
modifier|*
name|ShaderD3D
operator|::
name|getCompiler
parameter_list|()
block|{
if|if
condition|(
name|mType
operator|==
name|GL_VERTEX_SHADER
condition|)
block|{
return|return
name|mVertexCompiler
return|;
block|}
else|else
block|{
name|ASSERT
argument_list|(
name|mType
operator|==
name|GL_FRAGMENT_SHADER
argument_list|)
expr_stmt|;
return|return
name|mFragmentCompiler
return|;
block|}
block|}
DECL|function|getCompilerOutputType
name|ShShaderOutput
name|ShaderD3D
operator|::
name|getCompilerOutputType
parameter_list|(
name|GLenum
name|shader
parameter_list|)
block|{
name|void
modifier|*
name|compiler
init|=
name|NULL
decl_stmt|;
switch|switch
condition|(
name|shader
condition|)
block|{
case|case
name|GL_VERTEX_SHADER
case|:
name|compiler
operator|=
name|mVertexCompiler
expr_stmt|;
break|break;
case|case
name|GL_FRAGMENT_SHADER
case|:
name|compiler
operator|=
name|mFragmentCompiler
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|SH_HLSL9_OUTPUT
return|;
block|}
return|return
name|ShGetShaderOutputType
argument_list|(
name|compiler
argument_list|)
return|;
block|}
DECL|function|compile
name|bool
name|ShaderD3D
operator|::
name|compile
parameter_list|(
specifier|const
name|gl
operator|::
name|Data
modifier|&
name|data
parameter_list|,
specifier|const
name|std
operator|::
name|string
modifier|&
name|source
parameter_list|)
block|{
name|uncompile
argument_list|()
expr_stmt|;
name|void
modifier|*
name|compiler
init|=
name|getCompiler
argument_list|()
decl_stmt|;
name|compileToHLSL
argument_list|(
name|data
argument_list|,
name|compiler
argument_list|,
name|source
argument_list|)
expr_stmt|;
if|if
condition|(
name|mType
operator|==
name|GL_VERTEX_SHADER
condition|)
block|{
name|parseAttributes
argument_list|(
name|compiler
argument_list|)
expr_stmt|;
block|}
name|parseVaryings
argument_list|(
name|compiler
argument_list|)
expr_stmt|;
if|if
condition|(
name|mType
operator|==
name|GL_FRAGMENT_SHADER
condition|)
block|{
name|std
operator|::
name|sort
argument_list|(
name|mVaryings
operator|.
name|begin
argument_list|()
argument_list|,
name|mVaryings
operator|.
name|end
argument_list|()
argument_list|,
name|compareVarying
argument_list|)
expr_stmt|;
specifier|const
name|std
operator|::
name|string
modifier|&
name|hlsl
init|=
name|getTranslatedSource
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|hlsl
operator|.
name|empty
argument_list|()
condition|)
block|{
name|mActiveOutputVariables
operator|=
operator|*
name|GetShaderVariables
argument_list|(
name|ShGetOutputVariables
argument_list|(
name|compiler
argument_list|)
argument_list|)
expr_stmt|;
name|FilterInactiveVariables
argument_list|(
operator|&
name|mActiveOutputVariables
argument_list|)
expr_stmt|;
block|}
block|}
if|#
directive|if
name|ANGLE_SHADER_DEBUG_INFO
operator|==
name|ANGLE_ENABLED
name|mDebugInfo
operator|+=
name|std
operator|::
name|string
argument_list|(
literal|"// "
argument_list|)
operator|+
name|GetShaderTypeString
argument_list|(
name|mType
argument_list|)
operator|+
literal|" SHADER BEGIN\n"
expr_stmt|;
name|mDebugInfo
operator|+=
literal|"\n// GLSL BEGIN\n\n"
operator|+
name|source
operator|+
literal|"\n\n// GLSL END\n\n\n"
expr_stmt|;
name|mDebugInfo
operator|+=
literal|"// INITIAL HLSL BEGIN\n\n"
operator|+
name|getTranslatedSource
argument_list|()
operator|+
literal|"\n// INITIAL HLSL END\n\n\n"
expr_stmt|;
comment|// Successive steps will append more info
else|#
directive|else
name|mDebugInfo
operator|+=
name|getTranslatedSource
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
operator|!
name|getTranslatedSource
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
DECL|function|parseAttributes
name|void
name|ShaderD3D
operator|::
name|parseAttributes
parameter_list|(
name|void
modifier|*
name|compiler
parameter_list|)
block|{
specifier|const
name|std
operator|::
name|string
modifier|&
name|hlsl
init|=
name|getTranslatedSource
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|hlsl
operator|.
name|empty
argument_list|()
condition|)
block|{
name|mActiveAttributes
operator|=
operator|*
name|GetShaderVariables
argument_list|(
name|ShGetAttributes
argument_list|(
name|compiler
argument_list|)
argument_list|)
expr_stmt|;
name|FilterInactiveVariables
argument_list|(
operator|&
name|mActiveAttributes
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|getSemanticIndex
name|int
name|ShaderD3D
operator|::
name|getSemanticIndex
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|attributeName
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|attributeName
operator|.
name|empty
argument_list|()
condition|)
block|{
name|int
name|semanticIndex
init|=
literal|0
decl_stmt|;
for|for
control|(
name|size_t
name|attributeIndex
init|=
literal|0
init|;
name|attributeIndex
operator|<
name|mActiveAttributes
operator|.
name|size
argument_list|()
condition|;
name|attributeIndex
operator|++
control|)
block|{
specifier|const
name|sh
operator|::
name|ShaderVariable
modifier|&
name|attribute
init|=
name|mActiveAttributes
index|[
name|attributeIndex
index|]
decl_stmt|;
if|if
condition|(
name|attribute
operator|.
name|name
operator|==
name|attributeName
condition|)
block|{
return|return
name|semanticIndex
return|;
block|}
name|semanticIndex
operator|+=
name|gl
operator|::
name|VariableRegisterCount
argument_list|(
name|attribute
operator|.
name|type
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
block|}
end_namespace
end_unit
