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
comment|// QueryImpl.h: Defines the abstract rx::QueryImpl class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_QUERYIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_QUERYIMPL_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_QUERYIMPL_H_
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
file|<GLES2/gl2.h>
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|QueryImpl
block|{
name|public
label|:
name|explicit
name|QueryImpl
parameter_list|(
name|GLenum
name|type
parameter_list|)
block|{
name|mType
operator|=
name|type
expr_stmt|;
block|}
name|virtual
operator|~
name|QueryImpl
argument_list|()
block|{ }
name|virtual
name|gl
operator|::
name|Error
name|begin
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
name|end
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
name|getResult
argument_list|(
name|GLuint
operator|*
name|params
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
name|isResultAvailable
argument_list|(
name|GLuint
operator|*
name|available
argument_list|)
operator|=
literal|0
expr_stmt|;
name|GLenum
name|getType
argument_list|()
specifier|const
block|{
return|return
name|mType
return|;
block|}
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|QueryImpl
argument_list|)
expr_stmt|;
name|GLenum
name|mType
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_QUERYIMPL_H_
end_comment
end_unit
