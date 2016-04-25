begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
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
comment|// Image.cpp: Implements the egl::Image class representing the EGLimage object.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/Image.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Texture.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Renderbuffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/ImageImpl.h"
end_include
begin_namespace
DECL|namespace|egl
namespace|namespace
name|egl
block|{
DECL|function|ImageSibling
name|ImageSibling
operator|::
name|ImageSibling
parameter_list|(
name|GLuint
name|id
parameter_list|)
member_init_list|:
name|RefCountObject
argument_list|(
name|id
argument_list|)
member_init_list|,
name|mSourcesOf
argument_list|()
member_init_list|,
name|mTargetOf
argument_list|()
block|{ }
DECL|function|~ImageSibling
name|ImageSibling
operator|::
name|~
name|ImageSibling
parameter_list|()
block|{
comment|// EGL images should hold a ref to their targets and siblings, a Texture should not be deletable
comment|// while it is attached to an EGL image.
name|ASSERT
argument_list|(
name|mSourcesOf
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|orphanImages
argument_list|()
expr_stmt|;
block|}
DECL|function|setTargetImage
name|void
name|ImageSibling
operator|::
name|setTargetImage
parameter_list|(
name|egl
operator|::
name|Image
modifier|*
name|imageTarget
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|imageTarget
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|mTargetOf
operator|.
name|set
argument_list|(
name|imageTarget
argument_list|)
expr_stmt|;
name|imageTarget
operator|->
name|addTargetSibling
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
DECL|function|orphanImages
name|gl
operator|::
name|Error
name|ImageSibling
operator|::
name|orphanImages
parameter_list|()
block|{
if|if
condition|(
name|mTargetOf
operator|.
name|get
argument_list|()
operator|!=
literal|nullptr
condition|)
block|{
comment|// Can't be a target and have sources.
name|ASSERT
argument_list|(
name|mSourcesOf
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|mTargetOf
operator|->
name|orphanSibling
argument_list|(
name|this
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
name|mTargetOf
operator|.
name|set
argument_list|(
literal|nullptr
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|auto
operator|&
name|sourceImage
operator|:
name|mSourcesOf
control|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|sourceImage
operator|->
name|orphanSibling
argument_list|(
name|this
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
block|}
name|mSourcesOf
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|addImageSource
name|void
name|ImageSibling
operator|::
name|addImageSource
parameter_list|(
name|egl
operator|::
name|Image
modifier|*
name|imageSource
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|imageSource
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|mSourcesOf
operator|.
name|insert
argument_list|(
name|imageSource
argument_list|)
expr_stmt|;
block|}
DECL|function|removeImageSource
name|void
name|ImageSibling
operator|::
name|removeImageSource
parameter_list|(
name|egl
operator|::
name|Image
modifier|*
name|imageSource
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|mSourcesOf
operator|.
name|find
argument_list|(
name|imageSource
argument_list|)
operator|!=
name|mSourcesOf
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|mSourcesOf
operator|.
name|erase
argument_list|(
name|imageSource
argument_list|)
expr_stmt|;
block|}
DECL|function|Image
name|Image
operator|::
name|Image
parameter_list|(
name|rx
operator|::
name|ImageImpl
modifier|*
name|impl
parameter_list|,
name|EGLenum
name|target
parameter_list|,
name|ImageSibling
modifier|*
name|buffer
parameter_list|,
specifier|const
name|AttributeMap
modifier|&
name|attribs
parameter_list|)
member_init_list|:
name|RefCountObject
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mImplementation
argument_list|(
name|impl
argument_list|)
member_init_list|,
name|mInternalFormat
argument_list|(
name|GL_NONE
argument_list|)
member_init_list|,
name|mWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mHeight
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mSamples
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mSource
argument_list|()
member_init_list|,
name|mTargets
argument_list|()
block|{
name|ASSERT
argument_list|(
name|mImplementation
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|buffer
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
name|mSource
operator|.
name|set
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|mSource
operator|->
name|addImageSource
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|IsTextureTarget
argument_list|(
name|target
argument_list|)
condition|)
block|{
name|gl
operator|::
name|Texture
modifier|*
name|texture
init|=
name|rx
operator|::
name|GetAs
argument_list|<
name|gl
operator|::
name|Texture
argument_list|>
argument_list|(
name|mSource
operator|.
name|get
argument_list|()
argument_list|)
decl_stmt|;
name|GLenum
name|textureTarget
init|=
name|egl_gl
operator|::
name|EGLImageTargetToGLTextureTarget
argument_list|(
name|target
argument_list|)
decl_stmt|;
name|size_t
name|level
init|=
name|attribs
operator|.
name|get
argument_list|(
name|EGL_GL_TEXTURE_LEVEL_KHR
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|mInternalFormat
operator|=
name|texture
operator|->
name|getInternalFormat
argument_list|(
name|textureTarget
argument_list|,
name|level
argument_list|)
expr_stmt|;
name|mWidth
operator|=
name|texture
operator|->
name|getWidth
argument_list|(
name|textureTarget
argument_list|,
name|level
argument_list|)
expr_stmt|;
name|mHeight
operator|=
name|texture
operator|->
name|getHeight
argument_list|(
name|textureTarget
argument_list|,
name|level
argument_list|)
expr_stmt|;
name|mSamples
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|IsRenderbufferTarget
argument_list|(
name|target
argument_list|)
condition|)
block|{
name|gl
operator|::
name|Renderbuffer
modifier|*
name|renderbuffer
init|=
name|rx
operator|::
name|GetAs
argument_list|<
name|gl
operator|::
name|Renderbuffer
argument_list|>
argument_list|(
name|mSource
operator|.
name|get
argument_list|()
argument_list|)
decl_stmt|;
name|mInternalFormat
operator|=
name|renderbuffer
operator|->
name|getInternalFormat
argument_list|()
expr_stmt|;
name|mWidth
operator|=
name|renderbuffer
operator|->
name|getWidth
argument_list|()
expr_stmt|;
name|mHeight
operator|=
name|renderbuffer
operator|->
name|getHeight
argument_list|()
expr_stmt|;
name|mSamples
operator|=
name|renderbuffer
operator|->
name|getSamples
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|~Image
name|Image
operator|::
name|~
name|Image
parameter_list|()
block|{
name|SafeDelete
argument_list|(
name|mImplementation
argument_list|)
expr_stmt|;
comment|// All targets should hold a ref to the egl image and it should not be deleted until there are
comment|// no siblings left.
name|ASSERT
argument_list|(
name|mTargets
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
comment|// Tell the source that it is no longer used by this image
if|if
condition|(
name|mSource
operator|.
name|get
argument_list|()
operator|!=
literal|nullptr
condition|)
block|{
name|mSource
operator|->
name|removeImageSource
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mSource
operator|.
name|set
argument_list|(
literal|nullptr
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|addTargetSibling
name|void
name|Image
operator|::
name|addTargetSibling
parameter_list|(
name|ImageSibling
modifier|*
name|sibling
parameter_list|)
block|{
name|mTargets
operator|.
name|insert
argument_list|(
name|sibling
argument_list|)
expr_stmt|;
block|}
DECL|function|orphanSibling
name|gl
operator|::
name|Error
name|Image
operator|::
name|orphanSibling
parameter_list|(
name|ImageSibling
modifier|*
name|sibling
parameter_list|)
block|{
comment|// notify impl
name|gl
operator|::
name|Error
name|error
init|=
name|mImplementation
operator|->
name|orphan
argument_list|(
name|sibling
argument_list|)
decl_stmt|;
if|if
condition|(
name|mSource
operator|.
name|get
argument_list|()
operator|==
name|sibling
condition|)
block|{
comment|// If the sibling is the source, it cannot be a target.
name|ASSERT
argument_list|(
name|mTargets
operator|.
name|find
argument_list|(
name|sibling
argument_list|)
operator|==
name|mTargets
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|mSource
operator|.
name|set
argument_list|(
literal|nullptr
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|mTargets
operator|.
name|erase
argument_list|(
name|sibling
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
DECL|function|getInternalFormat
name|GLenum
name|Image
operator|::
name|getInternalFormat
parameter_list|()
specifier|const
block|{
return|return
name|mInternalFormat
return|;
block|}
DECL|function|getWidth
name|size_t
name|Image
operator|::
name|getWidth
parameter_list|()
specifier|const
block|{
return|return
name|mWidth
return|;
block|}
DECL|function|getHeight
name|size_t
name|Image
operator|::
name|getHeight
parameter_list|()
specifier|const
block|{
return|return
name|mHeight
return|;
block|}
DECL|function|getSamples
name|size_t
name|Image
operator|::
name|getSamples
parameter_list|()
specifier|const
block|{
return|return
name|mSamples
return|;
block|}
DECL|function|getImplementation
name|rx
operator|::
name|ImageImpl
modifier|*
name|Image
operator|::
name|getImplementation
parameter_list|()
block|{
return|return
name|mImplementation
return|;
block|}
DECL|function|getImplementation
specifier|const
name|rx
operator|::
name|ImageImpl
modifier|*
name|Image
operator|::
name|getImplementation
parameter_list|()
specifier|const
block|{
return|return
name|mImplementation
return|;
block|}
block|}
end_namespace
end_unit