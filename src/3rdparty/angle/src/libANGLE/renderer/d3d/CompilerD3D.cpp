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
comment|// CompilerD3D.cpp: Implementation of the rx::CompilerD3D class.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/CompilerD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Caps.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Data.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
comment|// Global count of active shader compiler handles. Needed to know when to call ShInitialize and ShFinalize.
DECL|member|activeCompilerHandles
specifier|static
name|size_t
name|activeCompilerHandles
init|=
literal|0
decl_stmt|;
DECL|function|CompilerD3D
name|CompilerD3D
operator|::
name|CompilerD3D
parameter_list|(
specifier|const
name|gl
operator|::
name|Data
modifier|&
name|data
parameter_list|,
name|ShShaderOutput
name|outputType
parameter_list|)
member_init_list|:
name|mSpec
argument_list|(
name|data
operator|.
name|clientVersion
operator|>
literal|2
condition|?
name|SH_GLES3_SPEC
else|:
name|SH_GLES2_SPEC
argument_list|)
member_init_list|,
name|mOutputType
argument_list|(
name|outputType
argument_list|)
member_init_list|,
name|mResources
argument_list|()
member_init_list|,
name|mFragmentCompiler
argument_list|(
name|NULL
argument_list|)
member_init_list|,
name|mVertexCompiler
argument_list|(
name|NULL
argument_list|)
block|{
name|ASSERT
argument_list|(
name|data
operator|.
name|clientVersion
operator|==
literal|2
operator|||
name|data
operator|.
name|clientVersion
operator|==
literal|3
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
name|ShInitBuiltInResources
argument_list|(
operator|&
name|mResources
argument_list|)
expr_stmt|;
name|mResources
operator|.
name|MaxVertexAttribs
operator|=
name|caps
operator|.
name|maxVertexAttributes
expr_stmt|;
name|mResources
operator|.
name|MaxVertexUniformVectors
operator|=
name|caps
operator|.
name|maxVertexUniformVectors
expr_stmt|;
name|mResources
operator|.
name|MaxVaryingVectors
operator|=
name|caps
operator|.
name|maxVaryingVectors
expr_stmt|;
name|mResources
operator|.
name|MaxVertexTextureImageUnits
operator|=
name|caps
operator|.
name|maxVertexTextureImageUnits
expr_stmt|;
name|mResources
operator|.
name|MaxCombinedTextureImageUnits
operator|=
name|caps
operator|.
name|maxCombinedTextureImageUnits
expr_stmt|;
name|mResources
operator|.
name|MaxTextureImageUnits
operator|=
name|caps
operator|.
name|maxTextureImageUnits
expr_stmt|;
name|mResources
operator|.
name|MaxFragmentUniformVectors
operator|=
name|caps
operator|.
name|maxFragmentUniformVectors
expr_stmt|;
name|mResources
operator|.
name|MaxDrawBuffers
operator|=
name|caps
operator|.
name|maxDrawBuffers
expr_stmt|;
name|mResources
operator|.
name|OES_standard_derivatives
operator|=
name|extensions
operator|.
name|standardDerivatives
expr_stmt|;
name|mResources
operator|.
name|EXT_draw_buffers
operator|=
name|extensions
operator|.
name|drawBuffers
expr_stmt|;
name|mResources
operator|.
name|EXT_shader_texture_lod
operator|=
literal|1
expr_stmt|;
comment|// resources.OES_EGL_image_external = mRenderer->getShareHandleSupport() ? 1 : 0; // TODO: commented out until the extension is actually supported.
name|mResources
operator|.
name|FragmentPrecisionHigh
operator|=
literal|1
expr_stmt|;
comment|// Shader Model 2+ always supports FP24 (s16e7) which corresponds to highp
name|mResources
operator|.
name|EXT_frag_depth
operator|=
literal|1
expr_stmt|;
comment|// Shader Model 2+ always supports explicit depth output
comment|// GLSL ES 3.0 constants
name|mResources
operator|.
name|MaxVertexOutputVectors
operator|=
name|caps
operator|.
name|maxVertexOutputComponents
operator|/
literal|4
expr_stmt|;
name|mResources
operator|.
name|MaxFragmentInputVectors
operator|=
name|caps
operator|.
name|maxFragmentInputComponents
operator|/
literal|4
expr_stmt|;
name|mResources
operator|.
name|MinProgramTexelOffset
operator|=
name|caps
operator|.
name|minProgramTexelOffset
expr_stmt|;
name|mResources
operator|.
name|MaxProgramTexelOffset
operator|=
name|caps
operator|.
name|maxProgramTexelOffset
expr_stmt|;
block|}
DECL|function|~CompilerD3D
name|CompilerD3D
operator|::
name|~
name|CompilerD3D
parameter_list|()
block|{
name|release
argument_list|()
expr_stmt|;
block|}
DECL|function|makeCompilerD3D
name|CompilerD3D
modifier|*
name|CompilerD3D
operator|::
name|makeCompilerD3D
parameter_list|(
name|CompilerImpl
modifier|*
name|compiler
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|HAS_DYNAMIC_TYPE
argument_list|(
name|CompilerD3D
operator|*
argument_list|,
name|compiler
argument_list|)
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|CompilerD3D
operator|*
argument_list|>
argument_list|(
name|compiler
argument_list|)
return|;
block|}
DECL|function|release
name|gl
operator|::
name|Error
name|CompilerD3D
operator|::
name|release
parameter_list|()
block|{
if|if
condition|(
name|mFragmentCompiler
condition|)
block|{
name|ShDestruct
argument_list|(
name|mFragmentCompiler
argument_list|)
expr_stmt|;
name|mFragmentCompiler
operator|=
name|NULL
expr_stmt|;
name|ASSERT
argument_list|(
name|activeCompilerHandles
operator|>
literal|0
argument_list|)
expr_stmt|;
name|activeCompilerHandles
operator|--
expr_stmt|;
block|}
if|if
condition|(
name|mVertexCompiler
condition|)
block|{
name|ShDestruct
argument_list|(
name|mVertexCompiler
argument_list|)
expr_stmt|;
name|mVertexCompiler
operator|=
name|NULL
expr_stmt|;
name|ASSERT
argument_list|(
name|activeCompilerHandles
operator|>
literal|0
argument_list|)
expr_stmt|;
name|activeCompilerHandles
operator|--
expr_stmt|;
block|}
if|if
condition|(
name|activeCompilerHandles
operator|==
literal|0
condition|)
block|{
name|ShFinalize
argument_list|()
expr_stmt|;
block|}
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|getCompilerHandle
name|ShHandle
name|CompilerD3D
operator|::
name|getCompilerHandle
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
name|ShHandle
modifier|*
name|compiler
init|=
name|NULL
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|GL_VERTEX_SHADER
case|:
name|compiler
operator|=
operator|&
name|mVertexCompiler
expr_stmt|;
break|break;
case|case
name|GL_FRAGMENT_SHADER
case|:
name|compiler
operator|=
operator|&
name|mFragmentCompiler
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
operator|!
operator|(
operator|*
name|compiler
operator|)
condition|)
block|{
if|if
condition|(
name|activeCompilerHandles
operator|==
literal|0
condition|)
block|{
name|ShInitialize
argument_list|()
expr_stmt|;
block|}
operator|*
name|compiler
operator|=
name|ShConstructCompiler
argument_list|(
name|type
argument_list|,
name|mSpec
argument_list|,
name|mOutputType
argument_list|,
operator|&
name|mResources
argument_list|)
expr_stmt|;
name|activeCompilerHandles
operator|++
expr_stmt|;
block|}
return|return
operator|*
name|compiler
return|;
block|}
block|}
end_namespace
end_unit