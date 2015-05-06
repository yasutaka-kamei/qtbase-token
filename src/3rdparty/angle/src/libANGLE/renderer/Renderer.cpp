begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// Renderer.cpp: Implements EGL dependencies for creating and destroying Renderer instances.
end_comment
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/AttributeMap.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/Renderer.h"
end_include
begin_include
include|#
directive|include
file|<EGL/eglext.h>
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|Renderer
name|Renderer
operator|::
name|Renderer
parameter_list|()
member_init_list|:
name|mCapsInitialized
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mWorkaroundsInitialized
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|~Renderer
name|Renderer
operator|::
name|~
name|Renderer
parameter_list|()
block|{ }
DECL|function|getRendererCaps
specifier|const
name|gl
operator|::
name|Caps
modifier|&
name|Renderer
operator|::
name|getRendererCaps
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mCapsInitialized
condition|)
block|{
name|generateCaps
argument_list|(
operator|&
name|mCaps
argument_list|,
operator|&
name|mTextureCaps
argument_list|,
operator|&
name|mExtensions
argument_list|)
expr_stmt|;
name|mCapsInitialized
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|mCaps
return|;
block|}
DECL|function|getRendererTextureCaps
specifier|const
name|gl
operator|::
name|TextureCapsMap
modifier|&
name|Renderer
operator|::
name|getRendererTextureCaps
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mCapsInitialized
condition|)
block|{
name|generateCaps
argument_list|(
operator|&
name|mCaps
argument_list|,
operator|&
name|mTextureCaps
argument_list|,
operator|&
name|mExtensions
argument_list|)
expr_stmt|;
name|mCapsInitialized
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|mTextureCaps
return|;
block|}
DECL|function|getRendererExtensions
specifier|const
name|gl
operator|::
name|Extensions
modifier|&
name|Renderer
operator|::
name|getRendererExtensions
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mCapsInitialized
condition|)
block|{
name|generateCaps
argument_list|(
operator|&
name|mCaps
argument_list|,
operator|&
name|mTextureCaps
argument_list|,
operator|&
name|mExtensions
argument_list|)
expr_stmt|;
name|mCapsInitialized
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|mExtensions
return|;
block|}
DECL|function|getWorkarounds
specifier|const
name|Workarounds
modifier|&
name|Renderer
operator|::
name|getWorkarounds
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mWorkaroundsInitialized
condition|)
block|{
name|mWorkarounds
operator|=
name|generateWorkarounds
argument_list|()
expr_stmt|;
name|mWorkaroundsInitialized
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|mWorkarounds
return|;
block|}
block|}
end_namespace
end_unit