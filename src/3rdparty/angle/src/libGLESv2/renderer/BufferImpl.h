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
comment|// BufferImpl.h: Defines the abstract rx::BufferImpl class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_BUFFERIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_BUFFERIMPL_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_BUFFERIMPL_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Buffer.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|BufferImpl
block|{
name|public
label|:
name|virtual
operator|~
name|BufferImpl
argument_list|()
block|{ }
name|virtual
name|void
name|setData
argument_list|(
argument|const void* data
argument_list|,
argument|size_t size
argument_list|,
argument|GLenum usage
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
modifier|*
name|getData
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|setSubData
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|offset
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|copySubData
parameter_list|(
name|BufferImpl
modifier|*
name|source
parameter_list|,
name|GLintptr
name|sourceOffset
parameter_list|,
name|GLintptr
name|destOffset
parameter_list|,
name|GLsizeiptr
name|size
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|GLvoid
modifier|*
name|map
parameter_list|(
name|size_t
name|offset
parameter_list|,
name|size_t
name|length
parameter_list|,
name|GLbitfield
name|access
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|unmap
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|markTransformFeedbackUsage
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_BUFFERIMPL_H_
end_comment
end_unit