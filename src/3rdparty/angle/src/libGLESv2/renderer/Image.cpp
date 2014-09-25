begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// Image.h: Implements the rx::Image class, an abstract base class for the
end_comment
begin_comment
comment|// renderer-specific classes which will define the interface to the underlying
end_comment
begin_comment
comment|// surfaces or resources.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Image.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|Image
name|Image
operator|::
name|Image
parameter_list|()
block|{
name|mWidth
operator|=
literal|0
expr_stmt|;
name|mHeight
operator|=
literal|0
expr_stmt|;
name|mDepth
operator|=
literal|0
expr_stmt|;
name|mInternalFormat
operator|=
name|GL_NONE
expr_stmt|;
name|mActualFormat
operator|=
name|GL_NONE
expr_stmt|;
name|mTarget
operator|=
name|GL_NONE
expr_stmt|;
name|mRenderable
operator|=
literal|false
expr_stmt|;
name|mDirty
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_namespace
end_unit
