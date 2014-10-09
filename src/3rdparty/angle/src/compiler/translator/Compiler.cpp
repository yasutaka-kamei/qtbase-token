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
begin_include
include|#
directive|include
file|"compiler/translator/BuiltInFunctionEmulator.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Compiler.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/DetectCallDepth.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/ForLoopUnroll.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Initialize.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InitializeParseContext.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InitializeVariables.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/ParseContext.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/RegenerateStructNames.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/RenameFunction.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/ScalarizeVecAndMatConstructorArgs.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/UnfoldShortCircuitAST.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/ValidateLimitations.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/ValidateOutputs.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/VariablePacker.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/depgraph/DependencyGraph.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/depgraph/DependencyGraphOutput.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/timing/RestrictFragmentShaderTiming.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/timing/RestrictVertexShaderTiming.h"
end_include
begin_include
include|#
directive|include
file|"third_party/compiler/ArrayBoundsClamper.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_function
DECL|function|IsWebGLBasedSpec
name|bool
name|IsWebGLBasedSpec
parameter_list|(
name|ShShaderSpec
name|spec
parameter_list|)
block|{
return|return
name|spec
operator|==
name|SH_WEBGL_SPEC
operator|||
name|spec
operator|==
name|SH_CSS_SHADERS_SPEC
return|;
block|}
end_function
begin_function
DECL|function|GetGlobalMaxTokenSize
name|size_t
name|GetGlobalMaxTokenSize
parameter_list|(
name|ShShaderSpec
name|spec
parameter_list|)
block|{
comment|// WebGL defines a max token legnth of 256, while ES2 leaves max token
comment|// size undefined. ES3 defines a max size of 1024 characters.
if|if
condition|(
name|IsWebGLBasedSpec
argument_list|(
name|spec
argument_list|)
condition|)
block|{
return|return
literal|256
return|;
block|}
else|else
block|{
return|return
literal|1024
return|;
block|}
block|}
end_function
begin_namespace
namespace|namespace
block|{
DECL|class|TScopedPoolAllocator
class|class
name|TScopedPoolAllocator
block|{
public|public:
DECL|function|TScopedPoolAllocator
name|TScopedPoolAllocator
parameter_list|(
name|TPoolAllocator
modifier|*
name|allocator
parameter_list|)
member_init_list|:
name|mAllocator
argument_list|(
name|allocator
argument_list|)
block|{
name|mAllocator
operator|->
name|push
argument_list|()
expr_stmt|;
name|SetGlobalPoolAllocator
argument_list|(
name|mAllocator
argument_list|)
expr_stmt|;
block|}
DECL|function|~TScopedPoolAllocator
name|~
name|TScopedPoolAllocator
parameter_list|()
block|{
name|SetGlobalPoolAllocator
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|mAllocator
operator|->
name|pop
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|mAllocator
name|TPoolAllocator
modifier|*
name|mAllocator
decl_stmt|;
block|}
class|;
DECL|class|TScopedSymbolTableLevel
class|class
name|TScopedSymbolTableLevel
block|{
public|public:
DECL|function|TScopedSymbolTableLevel
name|TScopedSymbolTableLevel
parameter_list|(
name|TSymbolTable
modifier|*
name|table
parameter_list|)
member_init_list|:
name|mTable
argument_list|(
name|table
argument_list|)
block|{
name|ASSERT
argument_list|(
name|mTable
operator|->
name|atBuiltInLevel
argument_list|()
argument_list|)
expr_stmt|;
name|mTable
operator|->
name|push
argument_list|()
expr_stmt|;
block|}
DECL|function|~TScopedSymbolTableLevel
name|~
name|TScopedSymbolTableLevel
parameter_list|()
block|{
while|while
condition|(
operator|!
name|mTable
operator|->
name|atBuiltInLevel
argument_list|()
condition|)
name|mTable
operator|->
name|pop
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|mTable
name|TSymbolTable
modifier|*
name|mTable
decl_stmt|;
block|}
class|;
block|}
end_namespace
begin_comment
comment|// namespace
end_comment
begin_constructor
DECL|function|TShHandleBase
name|TShHandleBase
operator|::
name|TShHandleBase
parameter_list|()
block|{
name|allocator
operator|.
name|push
argument_list|()
expr_stmt|;
name|SetGlobalPoolAllocator
argument_list|(
operator|&
name|allocator
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~TShHandleBase
name|TShHandleBase
operator|::
name|~
name|TShHandleBase
parameter_list|()
block|{
name|SetGlobalPoolAllocator
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|allocator
operator|.
name|popAll
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_constructor
DECL|function|TCompiler
name|TCompiler
operator|::
name|TCompiler
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
name|shaderType
argument_list|(
name|type
argument_list|)
member_init_list|,
name|shaderSpec
argument_list|(
name|spec
argument_list|)
member_init_list|,
name|outputType
argument_list|(
name|output
argument_list|)
member_init_list|,
name|maxUniformVectors
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|maxExpressionComplexity
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|maxCallStackDepth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|fragmentPrecisionHigh
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|clampingStrategy
argument_list|(
name|SH_CLAMP_WITH_CLAMP_INTRINSIC
argument_list|)
member_init_list|,
name|builtInFunctionEmulator
argument_list|(
name|type
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~TCompiler
name|TCompiler
operator|::
name|~
name|TCompiler
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|Init
name|bool
name|TCompiler
operator|::
name|Init
parameter_list|(
specifier|const
name|ShBuiltInResources
modifier|&
name|resources
parameter_list|)
block|{
name|shaderVersion
operator|=
literal|100
expr_stmt|;
name|maxUniformVectors
operator|=
operator|(
name|shaderType
operator|==
name|GL_VERTEX_SHADER
operator|)
condition|?
name|resources
operator|.
name|MaxVertexUniformVectors
else|:
name|resources
operator|.
name|MaxFragmentUniformVectors
expr_stmt|;
name|maxExpressionComplexity
operator|=
name|resources
operator|.
name|MaxExpressionComplexity
expr_stmt|;
name|maxCallStackDepth
operator|=
name|resources
operator|.
name|MaxCallStackDepth
expr_stmt|;
name|SetGlobalPoolAllocator
argument_list|(
operator|&
name|allocator
argument_list|)
expr_stmt|;
comment|// Generate built-in symbol table.
if|if
condition|(
operator|!
name|InitBuiltInSymbolTable
argument_list|(
name|resources
argument_list|)
condition|)
return|return
literal|false
return|;
name|InitExtensionBehavior
argument_list|(
name|resources
argument_list|,
name|extensionBehavior
argument_list|)
expr_stmt|;
name|fragmentPrecisionHigh
operator|=
name|resources
operator|.
name|FragmentPrecisionHigh
operator|==
literal|1
expr_stmt|;
name|arrayBoundsClamper
operator|.
name|SetClampingStrategy
argument_list|(
name|resources
operator|.
name|ArrayIndexClampingStrategy
argument_list|)
expr_stmt|;
name|clampingStrategy
operator|=
name|resources
operator|.
name|ArrayIndexClampingStrategy
expr_stmt|;
name|hashFunction
operator|=
name|resources
operator|.
name|HashFunction
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|compile
name|bool
name|TCompiler
operator|::
name|compile
parameter_list|(
specifier|const
name|char
modifier|*
specifier|const
name|shaderStrings
index|[]
parameter_list|,
name|size_t
name|numStrings
parameter_list|,
name|int
name|compileOptions
parameter_list|)
block|{
name|TScopedPoolAllocator
name|scopedAlloc
argument_list|(
operator|&
name|allocator
argument_list|)
decl_stmt|;
name|clearResults
argument_list|()
expr_stmt|;
if|if
condition|(
name|numStrings
operator|==
literal|0
condition|)
return|return
literal|true
return|;
comment|// If compiling for WebGL, validate loop and indexing as well.
if|if
condition|(
name|IsWebGLBasedSpec
argument_list|(
name|shaderSpec
argument_list|)
condition|)
name|compileOptions
operator||=
name|SH_VALIDATE_LOOP_INDEXING
expr_stmt|;
comment|// First string is path of source file if flag is set. The actual source follows.
specifier|const
name|char
modifier|*
name|sourcePath
init|=
name|NULL
decl_stmt|;
name|size_t
name|firstSource
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|compileOptions
operator|&
name|SH_SOURCE_PATH
condition|)
block|{
name|sourcePath
operator|=
name|shaderStrings
index|[
literal|0
index|]
expr_stmt|;
operator|++
name|firstSource
expr_stmt|;
block|}
name|TIntermediate
name|intermediate
argument_list|(
name|infoSink
argument_list|)
decl_stmt|;
name|TParseContext
name|parseContext
argument_list|(
name|symbolTable
argument_list|,
name|extensionBehavior
argument_list|,
name|intermediate
argument_list|,
name|shaderType
argument_list|,
name|shaderSpec
argument_list|,
name|compileOptions
argument_list|,
literal|true
argument_list|,
name|sourcePath
argument_list|,
name|infoSink
argument_list|)
decl_stmt|;
name|parseContext
operator|.
name|fragmentPrecisionHigh
operator|=
name|fragmentPrecisionHigh
expr_stmt|;
name|SetGlobalParseContext
argument_list|(
operator|&
name|parseContext
argument_list|)
expr_stmt|;
comment|// We preserve symbols at the built-in level from compile-to-compile.
comment|// Start pushing the user-defined symbols at global level.
name|TScopedSymbolTableLevel
name|scopedSymbolLevel
argument_list|(
operator|&
name|symbolTable
argument_list|)
decl_stmt|;
comment|// Parse shader.
name|bool
name|success
init|=
operator|(
name|PaParseStrings
argument_list|(
name|numStrings
operator|-
name|firstSource
argument_list|,
operator|&
name|shaderStrings
index|[
name|firstSource
index|]
argument_list|,
name|NULL
argument_list|,
operator|&
name|parseContext
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|parseContext
operator|.
name|treeRoot
operator|!=
name|NULL
operator|)
decl_stmt|;
name|shaderVersion
operator|=
name|parseContext
operator|.
name|getShaderVersion
argument_list|()
expr_stmt|;
if|if
condition|(
name|success
condition|)
block|{
name|TIntermNode
modifier|*
name|root
init|=
name|parseContext
operator|.
name|treeRoot
decl_stmt|;
name|success
operator|=
name|intermediate
operator|.
name|postProcess
argument_list|(
name|root
argument_list|)
expr_stmt|;
comment|// Disallow expressions deemed too complex.
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_LIMIT_EXPRESSION_COMPLEXITY
operator|)
condition|)
name|success
operator|=
name|limitExpressionComplexity
argument_list|(
name|root
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
condition|)
name|success
operator|=
name|detectCallDepth
argument_list|(
name|root
argument_list|,
name|infoSink
argument_list|,
operator|(
name|compileOptions
operator|&
name|SH_LIMIT_CALL_STACK_DEPTH
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|&&
name|shaderVersion
operator|==
literal|300
operator|&&
name|shaderType
operator|==
name|GL_FRAGMENT_SHADER
condition|)
name|success
operator|=
name|validateOutputs
argument_list|(
name|root
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_VALIDATE_LOOP_INDEXING
operator|)
condition|)
name|success
operator|=
name|validateLimitations
argument_list|(
name|root
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_TIMING_RESTRICTIONS
operator|)
condition|)
name|success
operator|=
name|enforceTimingRestrictions
argument_list|(
name|root
argument_list|,
operator|(
name|compileOptions
operator|&
name|SH_DEPENDENCY_GRAPH
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|&&
name|shaderSpec
operator|==
name|SH_CSS_SHADERS_SPEC
condition|)
name|rewriteCSSShader
argument_list|(
name|root
argument_list|)
expr_stmt|;
comment|// Unroll for-loop markup needs to happen after validateLimitations pass.
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_UNROLL_FOR_LOOP_WITH_INTEGER_INDEX
operator|)
condition|)
block|{
name|ForLoopUnrollMarker
name|marker
argument_list|(
name|ForLoopUnrollMarker
operator|::
name|kIntegerIndex
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|marker
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_UNROLL_FOR_LOOP_WITH_SAMPLER_ARRAY_INDEX
operator|)
condition|)
block|{
name|ForLoopUnrollMarker
name|marker
argument_list|(
name|ForLoopUnrollMarker
operator|::
name|kSamplerArrayIndex
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|marker
argument_list|)
expr_stmt|;
if|if
condition|(
name|marker
operator|.
name|samplerArrayIndexIsFloatLoopIndex
argument_list|()
condition|)
block|{
name|infoSink
operator|.
name|info
operator|.
name|prefix
argument_list|(
name|EPrefixError
argument_list|)
expr_stmt|;
name|infoSink
operator|.
name|info
operator|<<
literal|"sampler array index is float loop index"
expr_stmt|;
name|success
operator|=
literal|false
expr_stmt|;
block|}
block|}
comment|// Built-in function emulation needs to happen after validateLimitations pass.
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_EMULATE_BUILT_IN_FUNCTIONS
operator|)
condition|)
name|builtInFunctionEmulator
operator|.
name|MarkBuiltInFunctionsForEmulation
argument_list|(
name|root
argument_list|)
expr_stmt|;
comment|// Clamping uniform array bounds needs to happen after validateLimitations pass.
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_CLAMP_INDIRECT_ARRAY_BOUNDS
operator|)
condition|)
name|arrayBoundsClamper
operator|.
name|MarkIndirectArrayBoundsForClamping
argument_list|(
name|root
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|&&
name|shaderType
operator|==
name|GL_VERTEX_SHADER
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_INIT_GL_POSITION
operator|)
condition|)
name|initializeGLPosition
argument_list|(
name|root
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_UNFOLD_SHORT_CIRCUIT
operator|)
condition|)
block|{
name|UnfoldShortCircuitAST
name|unfoldShortCircuit
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|unfoldShortCircuit
argument_list|)
expr_stmt|;
name|unfoldShortCircuit
operator|.
name|updateTree
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_VARIABLES
operator|)
condition|)
block|{
name|collectVariables
argument_list|(
name|root
argument_list|)
expr_stmt|;
if|if
condition|(
name|compileOptions
operator|&
name|SH_ENFORCE_PACKING_RESTRICTIONS
condition|)
block|{
name|success
operator|=
name|enforcePackingRestrictions
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
block|{
name|infoSink
operator|.
name|info
operator|.
name|prefix
argument_list|(
name|EPrefixError
argument_list|)
expr_stmt|;
name|infoSink
operator|.
name|info
operator|<<
literal|"too many uniforms"
expr_stmt|;
block|}
block|}
if|if
condition|(
name|success
operator|&&
name|shaderType
operator|==
name|GL_VERTEX_SHADER
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_INIT_VARYINGS_WITHOUT_STATIC_USE
operator|)
condition|)
name|initializeVaryingsWithoutStaticUse
argument_list|(
name|root
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_SCALARIZE_VEC_AND_MAT_CONSTRUCTOR_ARGS
operator|)
condition|)
block|{
name|ScalarizeVecAndMatConstructorArgs
name|scalarizer
argument_list|(
name|shaderType
argument_list|,
name|fragmentPrecisionHigh
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|scalarizer
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_REGENERATE_STRUCT_NAMES
operator|)
condition|)
block|{
name|RegenerateStructNames
name|gen
argument_list|(
name|symbolTable
argument_list|,
name|shaderVersion
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|gen
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_INTERMEDIATE_TREE
operator|)
condition|)
name|intermediate
operator|.
name|outputTree
argument_list|(
name|root
argument_list|)
expr_stmt|;
if|if
condition|(
name|success
operator|&&
operator|(
name|compileOptions
operator|&
name|SH_OBJECT_CODE
operator|)
condition|)
name|translate
argument_list|(
name|root
argument_list|)
expr_stmt|;
block|}
comment|// Cleanup memory.
name|intermediate
operator|.
name|remove
argument_list|(
name|parseContext
operator|.
name|treeRoot
argument_list|)
expr_stmt|;
name|SetGlobalParseContext
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
return|return
name|success
return|;
block|}
end_function
begin_function
DECL|function|InitBuiltInSymbolTable
name|bool
name|TCompiler
operator|::
name|InitBuiltInSymbolTable
parameter_list|(
specifier|const
name|ShBuiltInResources
modifier|&
name|resources
parameter_list|)
block|{
name|compileResources
operator|=
name|resources
expr_stmt|;
name|setResourceString
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|symbolTable
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|symbolTable
operator|.
name|push
argument_list|()
expr_stmt|;
comment|// COMMON_BUILTINS
name|symbolTable
operator|.
name|push
argument_list|()
expr_stmt|;
comment|// ESSL1_BUILTINS
name|symbolTable
operator|.
name|push
argument_list|()
expr_stmt|;
comment|// ESSL3_BUILTINS
name|TPublicType
name|integer
decl_stmt|;
name|integer
operator|.
name|type
operator|=
name|EbtInt
expr_stmt|;
name|integer
operator|.
name|primarySize
operator|=
literal|1
expr_stmt|;
name|integer
operator|.
name|secondarySize
operator|=
literal|1
expr_stmt|;
name|integer
operator|.
name|array
operator|=
literal|false
expr_stmt|;
name|TPublicType
name|floatingPoint
decl_stmt|;
name|floatingPoint
operator|.
name|type
operator|=
name|EbtFloat
expr_stmt|;
name|floatingPoint
operator|.
name|primarySize
operator|=
literal|1
expr_stmt|;
name|floatingPoint
operator|.
name|secondarySize
operator|=
literal|1
expr_stmt|;
name|floatingPoint
operator|.
name|array
operator|=
literal|false
expr_stmt|;
name|TPublicType
name|sampler
decl_stmt|;
name|sampler
operator|.
name|primarySize
operator|=
literal|1
expr_stmt|;
name|sampler
operator|.
name|secondarySize
operator|=
literal|1
expr_stmt|;
name|sampler
operator|.
name|array
operator|=
literal|false
expr_stmt|;
switch|switch
condition|(
name|shaderType
condition|)
block|{
case|case
name|GL_FRAGMENT_SHADER
case|:
name|symbolTable
operator|.
name|setDefaultPrecision
argument_list|(
name|integer
argument_list|,
name|EbpMedium
argument_list|)
expr_stmt|;
break|break;
case|case
name|GL_VERTEX_SHADER
case|:
name|symbolTable
operator|.
name|setDefaultPrecision
argument_list|(
name|integer
argument_list|,
name|EbpHigh
argument_list|)
expr_stmt|;
name|symbolTable
operator|.
name|setDefaultPrecision
argument_list|(
name|floatingPoint
argument_list|,
name|EbpHigh
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
literal|false
operator|&&
literal|"Language not supported"
argument_list|)
expr_stmt|;
block|}
comment|// We set defaults for all the sampler types, even those that are
comment|// only available if an extension exists.
for|for
control|(
name|int
name|samplerType
init|=
name|EbtGuardSamplerBegin
operator|+
literal|1
init|;
name|samplerType
operator|<
name|EbtGuardSamplerEnd
condition|;
operator|++
name|samplerType
control|)
block|{
name|sampler
operator|.
name|type
operator|=
cast|static_cast
argument_list|<
name|TBasicType
argument_list|>
argument_list|(
name|samplerType
argument_list|)
expr_stmt|;
name|symbolTable
operator|.
name|setDefaultPrecision
argument_list|(
name|sampler
argument_list|,
name|EbpLow
argument_list|)
expr_stmt|;
block|}
name|InsertBuiltInFunctions
argument_list|(
name|shaderType
argument_list|,
name|shaderSpec
argument_list|,
name|resources
argument_list|,
name|symbolTable
argument_list|)
expr_stmt|;
name|IdentifyBuiltIns
argument_list|(
name|shaderType
argument_list|,
name|shaderSpec
argument_list|,
name|resources
argument_list|,
name|symbolTable
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setResourceString
name|void
name|TCompiler
operator|::
name|setResourceString
parameter_list|()
block|{
name|std
operator|::
name|ostringstream
name|strstream
decl_stmt|;
name|strstream
operator|<<
literal|":MaxVertexAttribs:"
operator|<<
name|compileResources
operator|.
name|MaxVertexAttribs
operator|<<
literal|":MaxVertexUniformVectors:"
operator|<<
name|compileResources
operator|.
name|MaxVertexUniformVectors
operator|<<
literal|":MaxVaryingVectors:"
operator|<<
name|compileResources
operator|.
name|MaxVaryingVectors
operator|<<
literal|":MaxVertexTextureImageUnits:"
operator|<<
name|compileResources
operator|.
name|MaxVertexTextureImageUnits
operator|<<
literal|":MaxCombinedTextureImageUnits:"
operator|<<
name|compileResources
operator|.
name|MaxCombinedTextureImageUnits
operator|<<
literal|":MaxTextureImageUnits:"
operator|<<
name|compileResources
operator|.
name|MaxTextureImageUnits
operator|<<
literal|":MaxFragmentUniformVectors:"
operator|<<
name|compileResources
operator|.
name|MaxFragmentUniformVectors
operator|<<
literal|":MaxDrawBuffers:"
operator|<<
name|compileResources
operator|.
name|MaxDrawBuffers
operator|<<
literal|":OES_standard_derivatives:"
operator|<<
name|compileResources
operator|.
name|OES_standard_derivatives
operator|<<
literal|":OES_EGL_image_external:"
operator|<<
name|compileResources
operator|.
name|OES_EGL_image_external
operator|<<
literal|":ARB_texture_rectangle:"
operator|<<
name|compileResources
operator|.
name|ARB_texture_rectangle
operator|<<
literal|":EXT_draw_buffers:"
operator|<<
name|compileResources
operator|.
name|EXT_draw_buffers
operator|<<
literal|":FragmentPrecisionHigh:"
operator|<<
name|compileResources
operator|.
name|FragmentPrecisionHigh
operator|<<
literal|":MaxExpressionComplexity:"
operator|<<
name|compileResources
operator|.
name|MaxExpressionComplexity
operator|<<
literal|":MaxCallStackDepth:"
operator|<<
name|compileResources
operator|.
name|MaxCallStackDepth
operator|<<
literal|":EXT_frag_depth:"
operator|<<
name|compileResources
operator|.
name|EXT_frag_depth
operator|<<
literal|":EXT_shader_texture_lod:"
operator|<<
name|compileResources
operator|.
name|EXT_shader_texture_lod
operator|<<
literal|":MaxVertexOutputVectors:"
operator|<<
name|compileResources
operator|.
name|MaxVertexOutputVectors
operator|<<
literal|":MaxFragmentInputVectors:"
operator|<<
name|compileResources
operator|.
name|MaxFragmentInputVectors
operator|<<
literal|":MinProgramTexelOffset:"
operator|<<
name|compileResources
operator|.
name|MinProgramTexelOffset
operator|<<
literal|":MaxProgramTexelOffset:"
operator|<<
name|compileResources
operator|.
name|MaxProgramTexelOffset
expr_stmt|;
name|builtInResourcesString
operator|=
name|strstream
operator|.
name|str
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearResults
name|void
name|TCompiler
operator|::
name|clearResults
parameter_list|()
block|{
name|arrayBoundsClamper
operator|.
name|Cleanup
argument_list|()
expr_stmt|;
name|infoSink
operator|.
name|info
operator|.
name|erase
argument_list|()
expr_stmt|;
name|infoSink
operator|.
name|obj
operator|.
name|erase
argument_list|()
expr_stmt|;
name|infoSink
operator|.
name|debug
operator|.
name|erase
argument_list|()
expr_stmt|;
name|attributes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|outputVariables
operator|.
name|clear
argument_list|()
expr_stmt|;
name|uniforms
operator|.
name|clear
argument_list|()
expr_stmt|;
name|expandedUniforms
operator|.
name|clear
argument_list|()
expr_stmt|;
name|varyings
operator|.
name|clear
argument_list|()
expr_stmt|;
name|expandedVaryings
operator|.
name|clear
argument_list|()
expr_stmt|;
name|interfaceBlocks
operator|.
name|clear
argument_list|()
expr_stmt|;
name|builtInFunctionEmulator
operator|.
name|Cleanup
argument_list|()
expr_stmt|;
name|nameMap
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|detectCallDepth
name|bool
name|TCompiler
operator|::
name|detectCallDepth
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|,
name|TInfoSink
modifier|&
name|infoSink
parameter_list|,
name|bool
name|limitCallStackDepth
parameter_list|)
block|{
name|DetectCallDepth
name|detect
argument_list|(
name|infoSink
argument_list|,
name|limitCallStackDepth
argument_list|,
name|maxCallStackDepth
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|detect
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|detect
operator|.
name|detectCallDepth
argument_list|()
condition|)
block|{
case|case
name|DetectCallDepth
operator|::
name|kErrorNone
case|:
return|return
literal|true
return|;
case|case
name|DetectCallDepth
operator|::
name|kErrorMissingMain
case|:
name|infoSink
operator|.
name|info
operator|.
name|prefix
argument_list|(
name|EPrefixError
argument_list|)
expr_stmt|;
name|infoSink
operator|.
name|info
operator|<<
literal|"Missing main()"
expr_stmt|;
return|return
literal|false
return|;
case|case
name|DetectCallDepth
operator|::
name|kErrorRecursion
case|:
name|infoSink
operator|.
name|info
operator|.
name|prefix
argument_list|(
name|EPrefixError
argument_list|)
expr_stmt|;
name|infoSink
operator|.
name|info
operator|<<
literal|"Function recursion detected"
expr_stmt|;
return|return
literal|false
return|;
case|case
name|DetectCallDepth
operator|::
name|kErrorMaxDepthExceeded
case|:
name|infoSink
operator|.
name|info
operator|.
name|prefix
argument_list|(
name|EPrefixError
argument_list|)
expr_stmt|;
name|infoSink
operator|.
name|info
operator|<<
literal|"Function call stack too deep"
expr_stmt|;
return|return
literal|false
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
end_function
begin_function
DECL|function|validateOutputs
name|bool
name|TCompiler
operator|::
name|validateOutputs
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|ValidateOutputs
name|validateOutputs
argument_list|(
name|infoSink
operator|.
name|info
argument_list|,
name|compileResources
operator|.
name|MaxDrawBuffers
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|validateOutputs
argument_list|)
expr_stmt|;
return|return
operator|(
name|validateOutputs
operator|.
name|numErrors
argument_list|()
operator|==
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|rewriteCSSShader
name|void
name|TCompiler
operator|::
name|rewriteCSSShader
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|RenameFunction
name|renamer
argument_list|(
literal|"main("
argument_list|,
literal|"css_main("
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|renamer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|validateLimitations
name|bool
name|TCompiler
operator|::
name|validateLimitations
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|ValidateLimitations
name|validate
argument_list|(
name|shaderType
argument_list|,
name|infoSink
operator|.
name|info
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|validate
argument_list|)
expr_stmt|;
return|return
name|validate
operator|.
name|numErrors
argument_list|()
operator|==
literal|0
return|;
block|}
end_function
begin_function
DECL|function|enforceTimingRestrictions
name|bool
name|TCompiler
operator|::
name|enforceTimingRestrictions
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|,
name|bool
name|outputGraph
parameter_list|)
block|{
if|if
condition|(
name|shaderSpec
operator|!=
name|SH_WEBGL_SPEC
condition|)
block|{
name|infoSink
operator|.
name|info
operator|<<
literal|"Timing restrictions must be enforced under the WebGL spec."
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|shaderType
operator|==
name|GL_FRAGMENT_SHADER
condition|)
block|{
name|TDependencyGraph
name|graph
argument_list|(
name|root
argument_list|)
decl_stmt|;
comment|// Output any errors first.
name|bool
name|success
init|=
name|enforceFragmentShaderTimingRestrictions
argument_list|(
name|graph
argument_list|)
decl_stmt|;
comment|// Then, output the dependency graph.
if|if
condition|(
name|outputGraph
condition|)
block|{
name|TDependencyGraphOutput
name|output
argument_list|(
name|infoSink
operator|.
name|info
argument_list|)
decl_stmt|;
name|output
operator|.
name|outputAllSpanningTrees
argument_list|(
name|graph
argument_list|)
expr_stmt|;
block|}
return|return
name|success
return|;
block|}
else|else
block|{
return|return
name|enforceVertexShaderTimingRestrictions
argument_list|(
name|root
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|limitExpressionComplexity
name|bool
name|TCompiler
operator|::
name|limitExpressionComplexity
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|TMaxDepthTraverser
name|traverser
argument_list|(
name|maxExpressionComplexity
operator|+
literal|1
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|traverser
argument_list|)
expr_stmt|;
if|if
condition|(
name|traverser
operator|.
name|getMaxDepth
argument_list|()
operator|>
name|maxExpressionComplexity
condition|)
block|{
name|infoSink
operator|.
name|info
operator|<<
literal|"Expression too complex."
expr_stmt|;
return|return
literal|false
return|;
block|}
name|TDependencyGraph
name|graph
argument_list|(
name|root
argument_list|)
decl_stmt|;
for|for
control|(
name|TFunctionCallVector
operator|::
name|const_iterator
name|iter
init|=
name|graph
operator|.
name|beginUserDefinedFunctionCalls
argument_list|()
init|;
name|iter
operator|!=
name|graph
operator|.
name|endUserDefinedFunctionCalls
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
name|TGraphFunctionCall
modifier|*
name|samplerSymbol
init|=
operator|*
name|iter
decl_stmt|;
name|TDependencyGraphTraverser
name|graphTraverser
decl_stmt|;
name|samplerSymbol
operator|->
name|traverse
argument_list|(
operator|&
name|graphTraverser
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|enforceFragmentShaderTimingRestrictions
name|bool
name|TCompiler
operator|::
name|enforceFragmentShaderTimingRestrictions
parameter_list|(
specifier|const
name|TDependencyGraph
modifier|&
name|graph
parameter_list|)
block|{
name|RestrictFragmentShaderTiming
name|restrictor
argument_list|(
name|infoSink
operator|.
name|info
argument_list|)
decl_stmt|;
name|restrictor
operator|.
name|enforceRestrictions
argument_list|(
name|graph
argument_list|)
expr_stmt|;
return|return
name|restrictor
operator|.
name|numErrors
argument_list|()
operator|==
literal|0
return|;
block|}
end_function
begin_function
DECL|function|enforceVertexShaderTimingRestrictions
name|bool
name|TCompiler
operator|::
name|enforceVertexShaderTimingRestrictions
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|RestrictVertexShaderTiming
name|restrictor
argument_list|(
name|infoSink
operator|.
name|info
argument_list|)
decl_stmt|;
name|restrictor
operator|.
name|enforceRestrictions
argument_list|(
name|root
argument_list|)
expr_stmt|;
return|return
name|restrictor
operator|.
name|numErrors
argument_list|()
operator|==
literal|0
return|;
block|}
end_function
begin_function
DECL|function|collectVariables
name|void
name|TCompiler
operator|::
name|collectVariables
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|sh
operator|::
name|CollectVariables
name|collect
argument_list|(
operator|&
name|attributes
argument_list|,
operator|&
name|outputVariables
argument_list|,
operator|&
name|uniforms
argument_list|,
operator|&
name|varyings
argument_list|,
operator|&
name|interfaceBlocks
argument_list|,
name|hashFunction
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|collect
argument_list|)
expr_stmt|;
comment|// For backwards compatiblity with ShGetVariableInfo, expand struct
comment|// uniforms and varyings into separate variables for each field.
name|sh
operator|::
name|ExpandVariables
argument_list|(
name|uniforms
argument_list|,
operator|&
name|expandedUniforms
argument_list|)
expr_stmt|;
name|sh
operator|::
name|ExpandVariables
argument_list|(
name|varyings
argument_list|,
operator|&
name|expandedVaryings
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enforcePackingRestrictions
name|bool
name|TCompiler
operator|::
name|enforcePackingRestrictions
parameter_list|()
block|{
name|VariablePacker
name|packer
decl_stmt|;
return|return
name|packer
operator|.
name|CheckVariablesWithinPackingLimits
argument_list|(
name|maxUniformVectors
argument_list|,
name|expandedUniforms
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|initializeGLPosition
name|void
name|TCompiler
operator|::
name|initializeGLPosition
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|InitializeVariables
operator|::
name|InitVariableInfoList
name|variables
decl_stmt|;
name|InitializeVariables
operator|::
name|InitVariableInfo
name|var
argument_list|(
literal|"gl_Position"
argument_list|,
name|TType
argument_list|(
name|EbtFloat
argument_list|,
name|EbpUndefined
argument_list|,
name|EvqPosition
argument_list|,
literal|4
argument_list|)
argument_list|)
decl_stmt|;
name|variables
operator|.
name|push_back
argument_list|(
name|var
argument_list|)
expr_stmt|;
name|InitializeVariables
name|initializer
argument_list|(
name|variables
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|initializer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initializeVaryingsWithoutStaticUse
name|void
name|TCompiler
operator|::
name|initializeVaryingsWithoutStaticUse
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|InitializeVariables
operator|::
name|InitVariableInfoList
name|variables
decl_stmt|;
for|for
control|(
name|size_t
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|varyings
operator|.
name|size
argument_list|()
condition|;
operator|++
name|ii
control|)
block|{
specifier|const
name|sh
operator|::
name|Varying
modifier|&
name|varying
init|=
name|varyings
index|[
name|ii
index|]
decl_stmt|;
if|if
condition|(
name|varying
operator|.
name|staticUse
condition|)
continue|continue;
name|unsigned
name|char
name|primarySize
init|=
cast|static_cast
argument_list|<
name|unsigned
name|char
argument_list|>
argument_list|(
name|gl
operator|::
name|VariableColumnCount
argument_list|(
name|varying
operator|.
name|type
argument_list|)
argument_list|)
decl_stmt|;
name|unsigned
name|char
name|secondarySize
init|=
cast|static_cast
argument_list|<
name|unsigned
name|char
argument_list|>
argument_list|(
name|gl
operator|::
name|VariableRowCount
argument_list|(
name|varying
operator|.
name|type
argument_list|)
argument_list|)
decl_stmt|;
name|TType
name|type
argument_list|(
name|EbtFloat
argument_list|,
name|EbpUndefined
argument_list|,
name|EvqVaryingOut
argument_list|,
name|primarySize
argument_list|,
name|secondarySize
argument_list|,
name|varying
operator|.
name|isArray
argument_list|()
argument_list|)
decl_stmt|;
name|TString
name|name
init|=
name|varying
operator|.
name|name
operator|.
name|c_str
argument_list|()
decl_stmt|;
if|if
condition|(
name|varying
operator|.
name|isArray
argument_list|()
condition|)
block|{
name|type
operator|.
name|setArraySize
argument_list|(
name|varying
operator|.
name|arraySize
argument_list|)
expr_stmt|;
name|name
operator|=
name|name
operator|.
name|substr
argument_list|(
literal|0
argument_list|,
name|name
operator|.
name|find_first_of
argument_list|(
literal|'['
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|InitializeVariables
operator|::
name|InitVariableInfo
name|var
argument_list|(
name|name
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|variables
operator|.
name|push_back
argument_list|(
name|var
argument_list|)
expr_stmt|;
block|}
name|InitializeVariables
name|initializer
argument_list|(
name|variables
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|initializer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getExtensionBehavior
specifier|const
name|TExtensionBehavior
modifier|&
name|TCompiler
operator|::
name|getExtensionBehavior
parameter_list|()
specifier|const
block|{
return|return
name|extensionBehavior
return|;
block|}
end_function
begin_function
DECL|function|getResources
specifier|const
name|ShBuiltInResources
modifier|&
name|TCompiler
operator|::
name|getResources
parameter_list|()
specifier|const
block|{
return|return
name|compileResources
return|;
block|}
end_function
begin_function
DECL|function|getArrayBoundsClamper
specifier|const
name|ArrayBoundsClamper
modifier|&
name|TCompiler
operator|::
name|getArrayBoundsClamper
parameter_list|()
specifier|const
block|{
return|return
name|arrayBoundsClamper
return|;
block|}
end_function
begin_function
DECL|function|getArrayIndexClampingStrategy
name|ShArrayIndexClampingStrategy
name|TCompiler
operator|::
name|getArrayIndexClampingStrategy
parameter_list|()
specifier|const
block|{
return|return
name|clampingStrategy
return|;
block|}
end_function
begin_function
DECL|function|getBuiltInFunctionEmulator
specifier|const
name|BuiltInFunctionEmulator
modifier|&
name|TCompiler
operator|::
name|getBuiltInFunctionEmulator
parameter_list|()
specifier|const
block|{
return|return
name|builtInFunctionEmulator
return|;
block|}
end_function
end_unit
