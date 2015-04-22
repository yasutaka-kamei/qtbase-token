begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
file|"compiler/translator/TranslatorGLSL.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/BuiltInFunctionEmulatorGLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/EmulatePrecision.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/OutputGLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/VersionGLSL.h"
end_include
begin_namespace
namespace|namespace
block|{
comment|// To search for what output variables are used in a fragment shader.
comment|// We handle gl_FragColor and gl_FragData at the moment.
DECL|class|TFragmentOutSearcher
class|class
name|TFragmentOutSearcher
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
DECL|function|TFragmentOutSearcher
name|TFragmentOutSearcher
parameter_list|()
member_init_list|:
name|mUsesGlFragColor
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mUsesGlFragData
argument_list|(
literal|false
argument_list|)
block|{     }
DECL|function|usesGlFragColor
name|bool
name|usesGlFragColor
parameter_list|()
specifier|const
block|{
return|return
name|mUsesGlFragColor
return|;
block|}
DECL|function|usesGlFragData
name|bool
name|usesGlFragData
parameter_list|()
specifier|const
block|{
return|return
name|mUsesGlFragData
return|;
block|}
protected|protected:
specifier|virtual
name|void
name|visitSymbol
parameter_list|(
name|TIntermSymbol
modifier|*
name|node
parameter_list|)
specifier|override
block|{
if|if
condition|(
name|node
operator|->
name|getSymbol
argument_list|()
operator|==
literal|"gl_FragColor"
condition|)
block|{
name|mUsesGlFragColor
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|node
operator|->
name|getSymbol
argument_list|()
operator|==
literal|"gl_FragData"
condition|)
block|{
name|mUsesGlFragData
operator|=
literal|true
expr_stmt|;
block|}
block|}
private|private:
DECL|member|mUsesGlFragColor
name|bool
name|mUsesGlFragColor
decl_stmt|;
DECL|member|mUsesGlFragData
name|bool
name|mUsesGlFragData
decl_stmt|;
block|}
class|;
block|}
end_namespace
begin_comment
comment|// namespace anonymous
end_comment
begin_constructor
DECL|function|TranslatorGLSL
name|TranslatorGLSL
operator|::
name|TranslatorGLSL
parameter_list|(
name|sh
operator|::
name|GLenum
name|type
parameter_list|,
name|ShShaderSpec
name|spec
parameter_list|,
name|ShShaderOutput
name|output
parameter_list|)
member_init_list|:
name|TCompiler
argument_list|(
name|type
argument_list|,
name|spec
argument_list|,
name|output
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|initBuiltInFunctionEmulator
name|void
name|TranslatorGLSL
operator|::
name|initBuiltInFunctionEmulator
parameter_list|(
name|BuiltInFunctionEmulator
modifier|*
name|emu
parameter_list|,
name|int
name|compileOptions
parameter_list|)
block|{
if|if
condition|(
name|compileOptions
operator|&
name|SH_EMULATE_BUILT_IN_FUNCTIONS
condition|)
name|InitBuiltInFunctionEmulatorForGLSL
argument_list|(
name|emu
argument_list|,
name|getShaderType
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|translate
name|void
name|TranslatorGLSL
operator|::
name|translate
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|,
name|int
parameter_list|)
block|{
name|TInfoSinkBase
modifier|&
name|sink
init|=
name|getInfoSink
argument_list|()
operator|.
name|obj
decl_stmt|;
comment|// Write GLSL version.
name|writeVersion
argument_list|(
name|root
argument_list|)
expr_stmt|;
name|writePragma
argument_list|()
expr_stmt|;
comment|// Write extension behaviour as needed
name|writeExtensionBehavior
argument_list|()
expr_stmt|;
name|bool
name|precisionEmulation
init|=
name|getResources
argument_list|()
operator|.
name|WEBGL_debug_shader_precision
operator|&&
name|getPragma
argument_list|()
operator|.
name|debugShaderPrecision
decl_stmt|;
if|if
condition|(
name|precisionEmulation
condition|)
block|{
name|EmulatePrecision
name|emulatePrecision
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|emulatePrecision
argument_list|)
expr_stmt|;
name|emulatePrecision
operator|.
name|updateTree
argument_list|()
expr_stmt|;
name|emulatePrecision
operator|.
name|writeEmulationHelpers
argument_list|(
name|sink
argument_list|,
name|getOutputType
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Write emulated built-in functions if needed.
if|if
condition|(
operator|!
name|getBuiltInFunctionEmulator
argument_list|()
operator|.
name|IsOutputEmpty
argument_list|()
condition|)
block|{
name|sink
operator|<<
literal|"// BEGIN: Generated code for built-in function emulation\n\n"
expr_stmt|;
name|sink
operator|<<
literal|"#define webgl_emu_precision\n\n"
expr_stmt|;
name|getBuiltInFunctionEmulator
argument_list|()
operator|.
name|OutputEmulatedFunctions
argument_list|(
name|sink
argument_list|)
expr_stmt|;
name|sink
operator|<<
literal|"// END: Generated code for built-in function emulation\n\n"
expr_stmt|;
block|}
comment|// Write array bounds clamping emulation if needed.
name|getArrayBoundsClamper
argument_list|()
operator|.
name|OutputClampingFunctionDefinition
argument_list|(
name|sink
argument_list|)
expr_stmt|;
comment|// Declare gl_FragColor and glFragData as webgl_FragColor and webgl_FragData
comment|// if it's core profile shaders and they are used.
if|if
condition|(
name|getShaderType
argument_list|()
operator|==
name|GL_FRAGMENT_SHADER
operator|&&
name|getOutputType
argument_list|()
operator|==
name|SH_GLSL_CORE_OUTPUT
condition|)
block|{
name|TFragmentOutSearcher
name|searcher
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|searcher
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
operator|!
operator|(
name|searcher
operator|.
name|usesGlFragData
argument_list|()
operator|&&
name|searcher
operator|.
name|usesGlFragColor
argument_list|()
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|searcher
operator|.
name|usesGlFragColor
argument_list|()
condition|)
block|{
name|sink
operator|<<
literal|"out vec4 webgl_FragColor;\n"
expr_stmt|;
block|}
if|if
condition|(
name|searcher
operator|.
name|usesGlFragData
argument_list|()
condition|)
block|{
name|sink
operator|<<
literal|"out vec4 webgl_FragData[gl_MaxDrawBuffers];\n"
expr_stmt|;
block|}
block|}
comment|// Write translated shader.
name|TOutputGLSL
name|outputGLSL
argument_list|(
name|sink
argument_list|,
name|getArrayIndexClampingStrategy
argument_list|()
argument_list|,
name|getHashFunction
argument_list|()
argument_list|,
name|getNameMap
argument_list|()
argument_list|,
name|getSymbolTable
argument_list|()
argument_list|,
name|getShaderVersion
argument_list|()
argument_list|,
name|getOutputType
argument_list|()
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|outputGLSL
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writeVersion
name|void
name|TranslatorGLSL
operator|::
name|writeVersion
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|TVersionGLSL
name|versionGLSL
argument_list|(
name|getShaderType
argument_list|()
argument_list|,
name|getPragma
argument_list|()
argument_list|,
name|getOutputType
argument_list|()
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|versionGLSL
argument_list|)
expr_stmt|;
name|int
name|version
init|=
name|versionGLSL
operator|.
name|getVersion
argument_list|()
decl_stmt|;
comment|// We need to write version directive only if it is greater than 110.
comment|// If there is no version directive in the shader, 110 is implied.
if|if
condition|(
name|version
operator|>
literal|110
condition|)
block|{
name|TInfoSinkBase
modifier|&
name|sink
init|=
name|getInfoSink
argument_list|()
operator|.
name|obj
decl_stmt|;
name|sink
operator|<<
literal|"#version "
operator|<<
name|version
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|writeExtensionBehavior
name|void
name|TranslatorGLSL
operator|::
name|writeExtensionBehavior
parameter_list|()
block|{
name|TInfoSinkBase
modifier|&
name|sink
init|=
name|getInfoSink
argument_list|()
operator|.
name|obj
decl_stmt|;
specifier|const
name|TExtensionBehavior
modifier|&
name|extBehavior
init|=
name|getExtensionBehavior
argument_list|()
decl_stmt|;
for|for
control|(
name|TExtensionBehavior
operator|::
name|const_iterator
name|iter
init|=
name|extBehavior
operator|.
name|begin
argument_list|()
init|;
name|iter
operator|!=
name|extBehavior
operator|.
name|end
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
if|if
condition|(
name|iter
operator|->
name|second
operator|==
name|EBhUndefined
condition|)
continue|continue;
comment|// For GLSL output, we don't need to emit most extensions explicitly,
comment|// but some we need to translate.
if|if
condition|(
name|iter
operator|->
name|first
operator|==
literal|"GL_EXT_shader_texture_lod"
condition|)
block|{
name|sink
operator|<<
literal|"#extension GL_ARB_shader_texture_lod : "
operator|<<
name|getBehaviorString
argument_list|(
name|iter
operator|->
name|second
argument_list|)
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
block|}
end_function
end_unit
