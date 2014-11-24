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
comment|// Fence.h: Defines the gl::FenceNV and gl::FenceSync classes, which support the GL_NV_fence
end_comment
begin_comment
comment|// extension and GLES3 sync objects.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_FENCE_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_FENCE_H_
define|#
directive|define
name|LIBGLESV2_FENCE_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/Error.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"common/RefCountObject.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|FenceNVImpl
decl_stmt|;
name|class
name|FenceSyncImpl
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|FenceNV
block|{
name|public
label|:
name|explicit
name|FenceNV
argument_list|(
name|rx
operator|::
name|FenceNVImpl
operator|*
name|impl
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|FenceNV
argument_list|()
expr_stmt|;
name|GLboolean
name|isFence
argument_list|()
specifier|const
expr_stmt|;
name|Error
name|setFence
parameter_list|(
name|GLenum
name|condition
parameter_list|)
function_decl|;
name|Error
name|testFence
parameter_list|(
name|GLboolean
modifier|*
name|outResult
parameter_list|)
function_decl|;
name|Error
name|finishFence
parameter_list|()
function_decl|;
name|GLboolean
name|getStatus
argument_list|()
specifier|const
block|{
return|return
name|mStatus
return|;
block|}
name|GLuint
name|getCondition
argument_list|()
specifier|const
block|{
return|return
name|mCondition
return|;
block|}
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|FenceNV
argument_list|)
expr_stmt|;
name|rx
operator|::
name|FenceNVImpl
operator|*
name|mFence
expr_stmt|;
name|bool
name|mIsSet
decl_stmt|;
name|GLboolean
name|mStatus
decl_stmt|;
name|GLenum
name|mCondition
decl_stmt|;
block|}
empty_stmt|;
name|class
name|FenceSync
range|:
name|public
name|RefCountObject
block|{
name|public
operator|:
name|explicit
name|FenceSync
argument_list|(
argument|rx::FenceSyncImpl *impl
argument_list|,
argument|GLuint id
argument_list|)
block|;
name|virtual
operator|~
name|FenceSync
argument_list|()
block|;
name|Error
name|set
argument_list|(
argument|GLenum condition
argument_list|)
block|;
name|Error
name|clientWait
argument_list|(
argument|GLbitfield flags
argument_list|,
argument|GLuint64 timeout
argument_list|,
argument|GLenum *outResult
argument_list|)
block|;
name|Error
name|serverWait
argument_list|(
argument|GLbitfield flags
argument_list|,
argument|GLuint64 timeout
argument_list|)
block|;
name|Error
name|getStatus
argument_list|(
argument|GLint *outResult
argument_list|)
specifier|const
block|;
name|GLuint
name|getCondition
argument_list|()
specifier|const
block|{
return|return
name|mCondition
return|;
block|}
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|FenceSync
argument_list|)
block|;
name|rx
operator|::
name|FenceSyncImpl
operator|*
name|mFence
block|;
name|GLenum
name|mCondition
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_FENCE_H_
end_comment
end_unit
