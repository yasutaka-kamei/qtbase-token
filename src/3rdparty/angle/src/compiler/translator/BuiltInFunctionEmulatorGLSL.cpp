begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2011 The ANGLE Project Authors. All rights reserved.
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
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/BuiltInFunctionEmulator.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/BuiltInFunctionEmulatorGLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/SymbolTable.h"
end_include
begin_function
DECL|function|InitBuiltInFunctionEmulatorForGLSL
name|void
name|InitBuiltInFunctionEmulatorForGLSL
parameter_list|(
name|BuiltInFunctionEmulator
modifier|*
name|emu
parameter_list|,
name|sh
operator|::
name|GLenum
name|shaderType
parameter_list|)
block|{
comment|// we use macros here instead of function definitions to work around more GLSL
comment|// compiler bugs, in particular on NVIDIA hardware on Mac OSX. Macros are
comment|// problematic because if the argument has side-effects they will be repeatedly
comment|// evaluated. This is unlikely to show up in real shaders, but is something to
comment|// consider.
name|TType
name|float1
argument_list|(
name|EbtFloat
argument_list|)
decl_stmt|;
name|TType
name|float2
argument_list|(
name|EbtFloat
argument_list|,
literal|2
argument_list|)
decl_stmt|;
name|TType
name|float3
argument_list|(
name|EbtFloat
argument_list|,
literal|3
argument_list|)
decl_stmt|;
name|TType
name|float4
argument_list|(
name|EbtFloat
argument_list|,
literal|4
argument_list|)
decl_stmt|;
if|if
condition|(
name|shaderType
operator|==
name|GL_FRAGMENT_SHADER
condition|)
block|{
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpCos
argument_list|,
name|float1
argument_list|,
literal|"webgl_emu_precision float webgl_cos_emu(webgl_emu_precision float a) { return cos(a); }"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpCos
argument_list|,
name|float2
argument_list|,
literal|"webgl_emu_precision vec2 webgl_cos_emu(webgl_emu_precision vec2 a) { return cos(a); }"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpCos
argument_list|,
name|float3
argument_list|,
literal|"webgl_emu_precision vec3 webgl_cos_emu(webgl_emu_precision vec3 a) { return cos(a); }"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpCos
argument_list|,
name|float4
argument_list|,
literal|"webgl_emu_precision vec4 webgl_cos_emu(webgl_emu_precision vec4 a) { return cos(a); }"
argument_list|)
expr_stmt|;
block|}
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpDistance
argument_list|,
name|float1
argument_list|,
name|float1
argument_list|,
literal|"#define webgl_distance_emu(x, y) ((x)>= (y) ? (x) - (y) : (y) - (x))"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpDot
argument_list|,
name|float1
argument_list|,
name|float1
argument_list|,
literal|"#define webgl_dot_emu(x, y) ((x) * (y))"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpLength
argument_list|,
name|float1
argument_list|,
literal|"#define webgl_length_emu(x) ((x)>= 0.0 ? (x) : -(x))"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpNormalize
argument_list|,
name|float1
argument_list|,
literal|"#define webgl_normalize_emu(x) ((x) == 0.0 ? 0.0 : ((x)> 0.0 ? 1.0 : -1.0))"
argument_list|)
expr_stmt|;
name|emu
operator|->
name|addEmulatedFunction
argument_list|(
name|EOpReflect
argument_list|,
name|float1
argument_list|,
name|float1
argument_list|,
literal|"#define webgl_reflect_emu(I, N) ((I) - 2.0 * (N) * (I) * (N))"
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
