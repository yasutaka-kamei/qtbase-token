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
begin_comment
comment|// RemovePow is an AST traverser to convert pow(x, y) built-in calls where y is a
end_comment
begin_comment
comment|// constant to exp2(y * log2(x)). This works around an issue in NVIDIA 311 series
end_comment
begin_comment
comment|// OpenGL drivers.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_REMOVEPOW_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_REMOVEPOW_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_REMOVEPOW_H_
end_define
begin_decl_stmt
DECL|variable|TIntermNode
name|class
name|TIntermNode
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|RemovePow
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_REMOVEPOW_H_
end_comment
end_unit