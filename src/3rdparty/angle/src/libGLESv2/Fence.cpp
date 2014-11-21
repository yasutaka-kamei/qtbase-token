begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// Fence.cpp: Implements the gl::FenceNV and gl::FenceSync classes, which support the GL_NV_fence
end_comment
begin_comment
comment|// extension and GLES3 sync objects.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/Fence.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/FenceImpl.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/main.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|function|FenceNV
name|FenceNV
operator|::
name|FenceNV
parameter_list|(
name|rx
operator|::
name|FenceNVImpl
modifier|*
name|impl
parameter_list|)
member_init_list|:
name|mFence
argument_list|(
name|impl
argument_list|)
member_init_list|,
name|mIsSet
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mStatus
argument_list|(
name|GL_FALSE
argument_list|)
member_init_list|,
name|mCondition
argument_list|(
name|GL_NONE
argument_list|)
block|{ }
DECL|function|~FenceNV
name|FenceNV
operator|::
name|~
name|FenceNV
parameter_list|()
block|{
name|SafeDelete
argument_list|(
name|mFence
argument_list|)
expr_stmt|;
block|}
DECL|function|isFence
name|GLboolean
name|FenceNV
operator|::
name|isFence
parameter_list|()
specifier|const
block|{
comment|// GL_NV_fence spec:
comment|// A name returned by GenFencesNV, but not yet set via SetFenceNV, is not the name of an existing fence.
return|return
operator|(
name|mIsSet
condition|?
name|GL_TRUE
else|:
name|GL_FALSE
operator|)
return|;
block|}
DECL|function|setFence
name|Error
name|FenceNV
operator|::
name|setFence
parameter_list|(
name|GLenum
name|condition
parameter_list|)
block|{
name|Error
name|error
init|=
name|mFence
operator|->
name|set
argument_list|()
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|mCondition
operator|=
name|condition
expr_stmt|;
name|mStatus
operator|=
name|GL_FALSE
expr_stmt|;
name|mIsSet
operator|=
literal|true
expr_stmt|;
return|return
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|testFence
name|Error
name|FenceNV
operator|::
name|testFence
parameter_list|(
name|GLboolean
modifier|*
name|outResult
parameter_list|)
block|{
comment|// Flush the command buffer by default
name|Error
name|error
init|=
name|mFence
operator|->
name|test
argument_list|(
literal|true
argument_list|,
operator|&
name|mStatus
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
operator|*
name|outResult
operator|=
name|mStatus
expr_stmt|;
return|return
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|finishFence
name|Error
name|FenceNV
operator|::
name|finishFence
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|mIsSet
argument_list|)
expr_stmt|;
return|return
name|mFence
operator|->
name|finishFence
argument_list|(
operator|&
name|mStatus
argument_list|)
return|;
block|}
DECL|function|FenceSync
name|FenceSync
operator|::
name|FenceSync
parameter_list|(
name|rx
operator|::
name|FenceSyncImpl
modifier|*
name|impl
parameter_list|,
name|GLuint
name|id
parameter_list|)
member_init_list|:
name|RefCountObject
argument_list|(
name|id
argument_list|)
member_init_list|,
name|mFence
argument_list|(
name|impl
argument_list|)
member_init_list|,
name|mCondition
argument_list|(
name|GL_NONE
argument_list|)
block|{ }
DECL|function|~FenceSync
name|FenceSync
operator|::
name|~
name|FenceSync
parameter_list|()
block|{
name|SafeDelete
argument_list|(
name|mFence
argument_list|)
expr_stmt|;
block|}
DECL|function|set
name|Error
name|FenceSync
operator|::
name|set
parameter_list|(
name|GLenum
name|condition
parameter_list|)
block|{
name|Error
name|error
init|=
name|mFence
operator|->
name|set
argument_list|()
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|mCondition
operator|=
name|condition
expr_stmt|;
return|return
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|clientWait
name|Error
name|FenceSync
operator|::
name|clientWait
parameter_list|(
name|GLbitfield
name|flags
parameter_list|,
name|GLuint64
name|timeout
parameter_list|,
name|GLenum
modifier|*
name|outResult
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|mCondition
operator|!=
name|GL_NONE
argument_list|)
expr_stmt|;
return|return
name|mFence
operator|->
name|clientWait
argument_list|(
name|flags
argument_list|,
name|timeout
argument_list|,
name|outResult
argument_list|)
return|;
block|}
DECL|function|serverWait
name|Error
name|FenceSync
operator|::
name|serverWait
parameter_list|(
name|GLbitfield
name|flags
parameter_list|,
name|GLuint64
name|timeout
parameter_list|)
block|{
return|return
name|mFence
operator|->
name|serverWait
argument_list|(
name|flags
argument_list|,
name|timeout
argument_list|)
return|;
block|}
DECL|function|getStatus
name|Error
name|FenceSync
operator|::
name|getStatus
parameter_list|(
name|GLint
modifier|*
name|outResult
parameter_list|)
specifier|const
block|{
return|return
name|mFence
operator|->
name|getStatus
argument_list|(
name|outResult
argument_list|)
return|;
block|}
block|}
end_namespace
end_unit
