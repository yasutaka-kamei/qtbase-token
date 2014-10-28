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
begin_comment
comment|// RenderbufferImpl.h: Defines the abstract class gl::RenderbufferImpl
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_RENDERBUFFERIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_RENDERBUFFERIMPL_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_RENDERBUFFERIMPL_H_
end_define
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
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
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RenderbufferImpl
block|{
name|public
label|:
name|RenderbufferImpl
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|RenderbufferImpl
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
name|setStorage
argument_list|(
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei samples
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|GLsizei
name|getWidth
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|GLsizei
name|getHeight
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|GLenum
name|getInternalFormat
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|GLenum
name|getActualFormat
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|GLsizei
name|getSamples
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RenderbufferImpl
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_RENDERBUFFERIMPL_H_
end_comment
end_unit