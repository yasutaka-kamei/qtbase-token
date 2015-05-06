begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// TransformFeedbackImpl.h: Defines the abstract rx::TransformFeedbackImpl class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_TRANSFORMFEEDBACKIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_TRANSFORMFEEDBACKIMPL_H_
define|#
directive|define
name|LIBANGLE_RENDERER_TRANSFORMFEEDBACKIMPL_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/TransformFeedback.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|TransformFeedbackImpl
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|virtual
operator|~
name|TransformFeedbackImpl
argument_list|()
block|{ }
name|virtual
name|void
name|begin
argument_list|(
argument|GLenum primitiveMode
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|end
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|pause
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|resume
argument_list|()
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_TRANSFORMFEEDBACKIMPL_H_
end_comment
end_unit