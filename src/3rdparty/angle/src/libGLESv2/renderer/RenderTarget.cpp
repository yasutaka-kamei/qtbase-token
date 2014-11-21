begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// RenderTarget.cpp: Implements serial handling for rx::RenderTarget
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/RenderTarget.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|member|mCurrentSerial
name|unsigned
name|int
name|RenderTarget
operator|::
name|mCurrentSerial
init|=
literal|1
decl_stmt|;
DECL|function|RenderTarget
name|RenderTarget
operator|::
name|RenderTarget
parameter_list|()
member_init_list|:
name|mSerial
argument_list|(
name|issueSerials
argument_list|(
literal|1
argument_list|)
argument_list|)
block|{ }
DECL|function|~RenderTarget
name|RenderTarget
operator|::
name|~
name|RenderTarget
parameter_list|()
block|{ }
DECL|function|getSerial
name|unsigned
name|int
name|RenderTarget
operator|::
name|getSerial
parameter_list|()
specifier|const
block|{
return|return
name|mSerial
return|;
block|}
DECL|function|issueSerials
name|unsigned
name|int
name|RenderTarget
operator|::
name|issueSerials
parameter_list|(
name|unsigned
name|int
name|count
parameter_list|)
block|{
name|unsigned
name|int
name|firstSerial
init|=
name|mCurrentSerial
decl_stmt|;
name|mCurrentSerial
operator|+=
name|count
expr_stmt|;
return|return
name|firstSerial
return|;
block|}
block|}
end_namespace
end_unit
