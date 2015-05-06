begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2011 The ANGLE Project Authors. All rights reserved.
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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_BUILTINFUNCTIONEMULATORGLSL_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_BUILTINFUNCTIONEMULATORGLSL_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_BUILTINFUNCTIONEMULATORGLSL_H_
end_define
begin_include
include|#
directive|include
file|"GLSLANG/ShaderLang.h"
end_include
begin_decl_stmt
DECL|variable|BuiltInFunctionEmulator
name|class
name|BuiltInFunctionEmulator
decl_stmt|;
end_decl_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// This is only a workaround for OpenGL driver bugs, and isn't needed in general.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|void
name|InitBuiltInFunctionEmulatorForGLSL
argument_list|(
name|BuiltInFunctionEmulator
operator|*
name|emu
argument_list|,
name|sh
operator|::
name|GLenum
name|shaderType
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_BUILTINFUNCTIONEMULATORGLSL_H_
end_comment
end_unit