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
begin_define
DECL|macro|ANGLE_DISABLED
define|#
directive|define
name|ANGLE_DISABLED
value|0
end_define
begin_define
DECL|macro|ANGLE_ENABLED
define|#
directive|define
name|ANGLE_ENABLED
value|1
end_define
begin_comment
comment|// Feature defaults
end_comment
begin_comment
comment|// Direct3D9EX
end_comment
begin_comment
comment|// The "Debug This Pixel..." feature in PIX often fails when using the
end_comment
begin_comment
comment|// D3D9Ex interfaces.  In order to get debug pixel to work on a Vista/Win 7
end_comment
begin_comment
comment|// machine, define "ANGLE_D3D9EX=0" in your project file.
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_D3D9EX
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_D3D9EX
define|#
directive|define
name|ANGLE_D3D9EX
value|ANGLE_ENABLED
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Vsync
end_comment
begin_comment
comment|// ENABLED allows Vsync to be configured at runtime
end_comment
begin_comment
comment|// DISABLED disallows Vsync
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_VSYNC
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_VSYNC
define|#
directive|define
name|ANGLE_VSYNC
value|ANGLE_ENABLED
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Program binary loading
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_PROGRAM_BINARY_LOAD
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_PROGRAM_BINARY_LOAD
define|#
directive|define
name|ANGLE_PROGRAM_BINARY_LOAD
value|ANGLE_ENABLED
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Shader debug info
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_SHADER_DEBUG_INFO
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_SHADER_DEBUG_INFO
define|#
directive|define
name|ANGLE_SHADER_DEBUG_INFO
value|ANGLE_DISABLED
end_define
begin_endif
endif|#
directive|endif
end_endif
end_unit