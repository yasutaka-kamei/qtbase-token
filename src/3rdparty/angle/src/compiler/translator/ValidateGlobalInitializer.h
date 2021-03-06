begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2015 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_TRANSLATOR_VALIDATEGLOBALINITIALIZER_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_VALIDATEGLOBALINITIALIZER_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_VALIDATEGLOBALINITIALIZER_H_
end_define
begin_decl_stmt
DECL|variable|TIntermTyped
name|class
name|TIntermTyped
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TParseContext
name|class
name|TParseContext
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Returns true if the initializer is valid.
end_comment
begin_function_decl
name|bool
name|ValidateGlobalInitializer
parameter_list|(
name|TIntermTyped
modifier|*
name|initializer
parameter_list|,
specifier|const
name|TParseContext
modifier|*
name|context
parameter_list|,
name|bool
modifier|*
name|warning
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_VALIDATEGLOBALINITIALIZER_H_
end_comment
end_unit
