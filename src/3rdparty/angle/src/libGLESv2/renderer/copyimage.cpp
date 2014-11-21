begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
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
comment|// copyimage.cpp: Defines image copying functions
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/copyimage.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|CopyBGRA8ToRGBA8
name|void
name|CopyBGRA8ToRGBA8
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|source
parameter_list|,
name|uint8_t
modifier|*
name|dest
parameter_list|)
block|{
name|uint32_t
name|argb
init|=
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|uint32_t
operator|*
argument_list|>
argument_list|(
name|source
argument_list|)
decl_stmt|;
operator|*
cast|reinterpret_cast
argument_list|<
name|uint32_t
operator|*
argument_list|>
argument_list|(
name|dest
argument_list|)
operator|=
operator|(
name|argb
operator|&
literal|0xFF00FF00
operator|)
operator||
comment|// Keep alpha and green
operator|(
name|argb
operator|&
literal|0x00FF0000
operator|)
operator|>>
literal|16
operator||
comment|// Move red to blue
operator|(
name|argb
operator|&
literal|0x000000FF
operator|)
operator|<<
literal|16
expr_stmt|;
comment|// Move blue to red
block|}
block|}
end_namespace
end_unit
