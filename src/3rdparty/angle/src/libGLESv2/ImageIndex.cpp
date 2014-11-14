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
comment|// ImageIndex.cpp: Implementation for ImageIndex methods.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/ImageIndex.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Texture.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|function|ImageIndex
name|ImageIndex
operator|::
name|ImageIndex
parameter_list|(
specifier|const
name|ImageIndex
modifier|&
name|other
parameter_list|)
member_init_list|:
name|type
argument_list|(
name|other
operator|.
name|type
argument_list|)
member_init_list|,
name|mipIndex
argument_list|(
name|other
operator|.
name|mipIndex
argument_list|)
member_init_list|,
name|layerIndex
argument_list|(
name|other
operator|.
name|layerIndex
argument_list|)
block|{}
DECL|function|operator =
name|ImageIndex
modifier|&
name|ImageIndex
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|ImageIndex
modifier|&
name|other
parameter_list|)
block|{
name|type
operator|=
name|other
operator|.
name|type
expr_stmt|;
name|mipIndex
operator|=
name|other
operator|.
name|mipIndex
expr_stmt|;
name|layerIndex
operator|=
name|other
operator|.
name|layerIndex
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
DECL|function|Make2D
name|ImageIndex
name|ImageIndex
operator|::
name|Make2D
parameter_list|(
name|GLint
name|mipIndex
parameter_list|)
block|{
return|return
name|ImageIndex
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|mipIndex
argument_list|,
name|ENTIRE_LEVEL
argument_list|)
return|;
block|}
DECL|function|MakeCube
name|ImageIndex
name|ImageIndex
operator|::
name|MakeCube
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|mipIndex
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|gl
operator|::
name|IsCubemapTextureTarget
argument_list|(
name|target
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ImageIndex
argument_list|(
name|target
argument_list|,
name|mipIndex
argument_list|,
name|TextureCubeMap
operator|::
name|targetToLayerIndex
argument_list|(
name|target
argument_list|)
argument_list|)
return|;
block|}
DECL|function|Make2DArray
name|ImageIndex
name|ImageIndex
operator|::
name|Make2DArray
parameter_list|(
name|GLint
name|mipIndex
parameter_list|,
name|GLint
name|layerIndex
parameter_list|)
block|{
return|return
name|ImageIndex
argument_list|(
name|GL_TEXTURE_2D_ARRAY
argument_list|,
name|mipIndex
argument_list|,
name|layerIndex
argument_list|)
return|;
block|}
DECL|function|Make3D
name|ImageIndex
name|ImageIndex
operator|::
name|Make3D
parameter_list|(
name|GLint
name|mipIndex
parameter_list|,
name|GLint
name|layerIndex
parameter_list|)
block|{
return|return
name|ImageIndex
argument_list|(
name|GL_TEXTURE_3D
argument_list|,
name|mipIndex
argument_list|,
name|layerIndex
argument_list|)
return|;
block|}
DECL|function|MakeInvalid
name|ImageIndex
name|ImageIndex
operator|::
name|MakeInvalid
parameter_list|()
block|{
return|return
name|ImageIndex
argument_list|(
name|GL_NONE
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
DECL|function|ImageIndex
name|ImageIndex
operator|::
name|ImageIndex
parameter_list|(
name|GLenum
name|typeIn
parameter_list|,
name|GLint
name|mipIndexIn
parameter_list|,
name|GLint
name|layerIndexIn
parameter_list|)
member_init_list|:
name|type
argument_list|(
name|typeIn
argument_list|)
member_init_list|,
name|mipIndex
argument_list|(
name|mipIndexIn
argument_list|)
member_init_list|,
name|layerIndex
argument_list|(
name|layerIndexIn
argument_list|)
block|{}
DECL|function|Make2D
name|ImageIndexIterator
name|ImageIndexIterator
operator|::
name|Make2D
parameter_list|(
name|GLint
name|minMip
parameter_list|,
name|GLint
name|maxMip
parameter_list|)
block|{
return|return
name|ImageIndexIterator
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|rx
operator|::
name|Range
argument_list|<
name|GLint
argument_list|>
argument_list|(
name|minMip
argument_list|,
name|maxMip
argument_list|)
argument_list|,
name|rx
operator|::
name|Range
argument_list|<
name|GLint
argument_list|>
argument_list|(
name|ImageIndex
operator|::
name|ENTIRE_LEVEL
argument_list|,
name|ImageIndex
operator|::
name|ENTIRE_LEVEL
argument_list|)
argument_list|,
name|NULL
argument_list|)
return|;
block|}
DECL|function|MakeCube
name|ImageIndexIterator
name|ImageIndexIterator
operator|::
name|MakeCube
parameter_list|(
name|GLint
name|minMip
parameter_list|,
name|GLint
name|maxMip
parameter_list|)
block|{
return|return
name|ImageIndexIterator
argument_list|(
name|GL_TEXTURE_CUBE_MAP
argument_list|,
name|rx
operator|::
name|Range
argument_list|<
name|GLint
argument_list|>
argument_list|(
name|minMip
argument_list|,
name|maxMip
argument_list|)
argument_list|,
name|rx
operator|::
name|Range
argument_list|<
name|GLint
argument_list|>
argument_list|(
literal|0
argument_list|,
literal|6
argument_list|)
argument_list|,
name|NULL
argument_list|)
return|;
block|}
DECL|function|Make3D
name|ImageIndexIterator
name|ImageIndexIterator
operator|::
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
block|{
return|return
name|ImageIndexIterator
argument_list|(
name|GL_TEXTURE_3D
argument_list|,
name|rx
operator|::
name|Range
argument_list|<
name|GLint
argument_list|>
argument_list|(
name|minMip
argument_list|,
name|maxMip
argument_list|)
argument_list|,
name|rx
operator|::
name|Range
argument_list|<
name|GLint
argument_list|>
argument_list|(
name|minLayer
argument_list|,
name|maxLayer
argument_list|)
argument_list|,
name|NULL
argument_list|)
return|;
block|}
DECL|function|Make2DArray
name|ImageIndexIterator
name|ImageIndexIterator
operator|::
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
block|{
return|return
name|ImageIndexIterator
argument_list|(
name|GL_TEXTURE_2D_ARRAY
argument_list|,
name|rx
operator|::
name|Range
argument_list|<
name|GLint
argument_list|>
argument_list|(
name|minMip
argument_list|,
name|maxMip
argument_list|)
argument_list|,
name|rx
operator|::
name|Range
argument_list|<
name|GLint
argument_list|>
argument_list|(
literal|0
argument_list|,
name|IMPLEMENTATION_MAX_2D_ARRAY_TEXTURE_LAYERS
argument_list|)
argument_list|,
name|layerCounts
argument_list|)
return|;
block|}
DECL|function|ImageIndexIterator
name|ImageIndexIterator
operator|::
name|ImageIndexIterator
parameter_list|(
name|GLenum
name|type
parameter_list|,
specifier|const
name|rx
operator|::
name|Range
argument_list|<
name|GLint
argument_list|>
modifier|&
name|mipRange
parameter_list|,
specifier|const
name|rx
operator|::
name|Range
argument_list|<
name|GLint
argument_list|>
modifier|&
name|layerRange
parameter_list|,
specifier|const
name|GLsizei
modifier|*
name|layerCounts
parameter_list|)
member_init_list|:
name|mType
argument_list|(
name|type
argument_list|)
member_init_list|,
name|mMipRange
argument_list|(
name|mipRange
argument_list|)
member_init_list|,
name|mLayerRange
argument_list|(
name|layerRange
argument_list|)
member_init_list|,
name|mLayerCounts
argument_list|(
name|layerCounts
argument_list|)
member_init_list|,
name|mCurrentMip
argument_list|(
name|mipRange
operator|.
name|start
argument_list|)
member_init_list|,
name|mCurrentLayer
argument_list|(
name|layerRange
operator|.
name|start
argument_list|)
block|{}
DECL|function|maxLayer
name|GLint
name|ImageIndexIterator
operator|::
name|maxLayer
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|mLayerCounts
condition|?
cast|static_cast
argument_list|<
name|GLint
argument_list|>
argument_list|(
name|mLayerCounts
index|[
name|mCurrentMip
index|]
argument_list|)
else|:
name|mLayerRange
operator|.
name|end
operator|)
return|;
block|}
DECL|function|next
name|ImageIndex
name|ImageIndexIterator
operator|::
name|next
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|hasNext
argument_list|()
argument_list|)
expr_stmt|;
name|ImageIndex
name|value
init|=
name|current
argument_list|()
decl_stmt|;
comment|// Iterate layers in the inner loop for now. We can add switchable
comment|// layer or mip iteration if we need it.
if|if
condition|(
name|mCurrentLayer
operator|!=
name|ImageIndex
operator|::
name|ENTIRE_LEVEL
condition|)
block|{
if|if
condition|(
name|mCurrentLayer
operator|<
name|maxLayer
argument_list|()
operator|-
literal|1
condition|)
block|{
name|mCurrentLayer
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mCurrentMip
operator|<
name|mMipRange
operator|.
name|end
operator|-
literal|1
condition|)
block|{
name|mCurrentMip
operator|++
expr_stmt|;
name|mCurrentLayer
operator|=
name|mLayerRange
operator|.
name|start
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|mCurrentMip
operator|<
name|mMipRange
operator|.
name|end
operator|-
literal|1
condition|)
block|{
name|mCurrentMip
operator|++
expr_stmt|;
name|mCurrentLayer
operator|=
name|mLayerRange
operator|.
name|start
expr_stmt|;
block|}
return|return
name|value
return|;
block|}
DECL|function|current
name|ImageIndex
name|ImageIndexIterator
operator|::
name|current
parameter_list|()
specifier|const
block|{
name|ImageIndex
name|value
argument_list|(
name|mType
argument_list|,
name|mCurrentMip
argument_list|,
name|mCurrentLayer
argument_list|)
decl_stmt|;
if|if
condition|(
name|mType
operator|==
name|GL_TEXTURE_CUBE_MAP
condition|)
block|{
name|value
operator|.
name|type
operator|=
name|TextureCubeMap
operator|::
name|layerIndexToTarget
argument_list|(
name|mCurrentLayer
argument_list|)
expr_stmt|;
block|}
return|return
name|value
return|;
block|}
DECL|function|hasNext
name|bool
name|ImageIndexIterator
operator|::
name|hasNext
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|mCurrentMip
operator|<
name|mMipRange
operator|.
name|end
operator|||
name|mCurrentLayer
operator|<
name|maxLayer
argument_list|()
operator|)
return|;
block|}
block|}
end_namespace
end_unit
