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
comment|// ImageIndex.h: A helper struct for indexing into an Image array
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_IMAGE_INDEX_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_IMAGE_INDEX_H_
define|#
directive|define
name|LIBGLESV2_IMAGE_INDEX_H_
end_define
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
struct|struct
name|ImageIndex
block|{
name|GLenum
name|type
decl_stmt|;
name|GLint
name|mipIndex
decl_stmt|;
name|GLint
name|layerIndex
decl_stmt|;
name|ImageIndex
argument_list|(
argument|GLenum typeIn
argument_list|,
argument|GLint mipIndexIn
argument_list|,
argument|GLint layerIndexIn
argument_list|)
empty_stmt|;
name|ImageIndex
argument_list|(
specifier|const
name|ImageIndex
operator|&
name|other
argument_list|)
expr_stmt|;
name|ImageIndex
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ImageIndex
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|hasLayer
argument_list|()
specifier|const
block|{
return|return
name|layerIndex
operator|!=
name|ENTIRE_LEVEL
return|;
block|}
specifier|static
name|ImageIndex
name|Make2D
parameter_list|(
name|GLint
name|mipIndex
parameter_list|)
function_decl|;
specifier|static
name|ImageIndex
name|MakeCube
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|mipIndex
parameter_list|)
function_decl|;
specifier|static
name|ImageIndex
name|Make2DArray
parameter_list|(
name|GLint
name|mipIndex
parameter_list|,
name|GLint
name|layerIndex
parameter_list|)
function_decl|;
specifier|static
name|ImageIndex
name|Make3D
parameter_list|(
name|GLint
name|mipIndex
parameter_list|,
name|GLint
name|layerIndex
init|=
name|ENTIRE_LEVEL
parameter_list|)
function_decl|;
specifier|static
name|ImageIndex
name|MakeInvalid
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|GLint
name|ENTIRE_LEVEL
init|=
name|static_cast
operator|<
name|GLint
operator|>
operator|(
operator|-
literal|1
operator|)
decl_stmt|;
block|}
struct|;
name|class
name|ImageIndexIterator
block|{
name|public
label|:
specifier|static
name|ImageIndexIterator
name|Make2D
parameter_list|(
name|GLint
name|minMip
parameter_list|,
name|GLint
name|maxMip
parameter_list|)
function_decl|;
specifier|static
name|ImageIndexIterator
name|MakeCube
parameter_list|(
name|GLint
name|minMip
parameter_list|,
name|GLint
name|maxMip
parameter_list|)
function_decl|;
specifier|static
name|ImageIndexIterator
name|Make3D
parameter_list|(
name|GLint
name|minMip
parameter_list|,
name|GLint
name|maxMip
parameter_list|,
name|GLint
name|minLayer
parameter_list|,
name|GLint
name|maxLayer
parameter_list|)
function_decl|;
specifier|static
name|ImageIndexIterator
name|Make2DArray
parameter_list|(
name|GLint
name|minMip
parameter_list|,
name|GLint
name|maxMip
parameter_list|,
specifier|const
name|GLsizei
modifier|*
name|layerCounts
parameter_list|)
function_decl|;
name|ImageIndex
name|next
parameter_list|()
function_decl|;
name|ImageIndex
name|current
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasNext
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|ImageIndexIterator
argument_list|(
argument|GLenum type
argument_list|,
argument|const rx::Range<GLint>&mipRange
argument_list|,
argument|const rx::Range<GLint>&layerRange
argument_list|,
argument|const GLsizei *layerCounts
argument_list|)
empty_stmt|;
name|GLint
name|maxLayer
argument_list|()
specifier|const
expr_stmt|;
name|GLenum
name|mType
decl_stmt|;
name|rx
operator|::
name|Range
operator|<
name|GLint
operator|>
name|mMipRange
expr_stmt|;
name|rx
operator|::
name|Range
operator|<
name|GLint
operator|>
name|mLayerRange
expr_stmt|;
specifier|const
name|GLsizei
modifier|*
name|mLayerCounts
decl_stmt|;
name|GLint
name|mCurrentMip
decl_stmt|;
name|GLint
name|mCurrentLayer
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
comment|// LIBGLESV2_IMAGE_INDEX_H_
end_comment
end_unit
