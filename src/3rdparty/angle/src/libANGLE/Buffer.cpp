begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// Buffer.cpp: Implements the gl::Buffer class, representing storage of vertex and/or
end_comment
begin_comment
comment|// index data. Implements GL buffer objects and related functionality.
end_comment
begin_comment
comment|// [OpenGL ES 2.0.24] section 2.9 page 21.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/Buffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/BufferImpl.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/Renderer.h"
end_include
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|function|Buffer
name|Buffer
operator|::
name|Buffer
parameter_list|(
name|rx
operator|::
name|BufferImpl
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
name|mBuffer
argument_list|(
name|impl
argument_list|)
member_init_list|,
name|mLabel
argument_list|()
member_init_list|,
name|mUsage
argument_list|(
name|GL_STATIC_DRAW
argument_list|)
member_init_list|,
name|mSize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mAccessFlags
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mAccess
argument_list|(
name|GL_WRITE_ONLY_OES
argument_list|)
member_init_list|,
name|mMapped
argument_list|(
name|GL_FALSE
argument_list|)
member_init_list|,
name|mMapPointer
argument_list|(
name|NULL
argument_list|)
member_init_list|,
name|mMapOffset
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mMapLength
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|~Buffer
name|Buffer
operator|::
name|~
name|Buffer
parameter_list|()
block|{
name|SafeDelete
argument_list|(
name|mBuffer
argument_list|)
expr_stmt|;
block|}
DECL|function|setLabel
name|void
name|Buffer
operator|::
name|setLabel
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|label
parameter_list|)
block|{
name|mLabel
operator|=
name|label
expr_stmt|;
block|}
DECL|function|getLabel
specifier|const
name|std
operator|::
name|string
modifier|&
name|Buffer
operator|::
name|getLabel
parameter_list|()
specifier|const
block|{
return|return
name|mLabel
return|;
block|}
DECL|function|bufferData
name|Error
name|Buffer
operator|::
name|bufferData
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|GLsizeiptr
name|size
parameter_list|,
name|GLenum
name|usage
parameter_list|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|mBuffer
operator|->
name|setData
argument_list|(
name|data
argument_list|,
name|size
argument_list|,
name|usage
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
name|mIndexRangeCache
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mUsage
operator|=
name|usage
expr_stmt|;
name|mSize
operator|=
name|size
expr_stmt|;
return|return
name|error
return|;
block|}
DECL|function|bufferSubData
name|Error
name|Buffer
operator|::
name|bufferSubData
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|GLsizeiptr
name|size
parameter_list|,
name|GLintptr
name|offset
parameter_list|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|mBuffer
operator|->
name|setSubData
argument_list|(
name|data
argument_list|,
name|size
argument_list|,
name|offset
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
name|mIndexRangeCache
operator|.
name|invalidateRange
argument_list|(
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|offset
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|size
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
DECL|function|copyBufferSubData
name|Error
name|Buffer
operator|::
name|copyBufferSubData
parameter_list|(
name|Buffer
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
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|mBuffer
operator|->
name|copySubData
argument_list|(
name|source
operator|->
name|getImplementation
argument_list|()
argument_list|,
name|sourceOffset
argument_list|,
name|destOffset
argument_list|,
name|size
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
name|mIndexRangeCache
operator|.
name|invalidateRange
argument_list|(
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|destOffset
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|size
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
DECL|function|map
name|Error
name|Buffer
operator|::
name|map
parameter_list|(
name|GLenum
name|access
parameter_list|)
block|{
name|ASSERT
argument_list|(
operator|!
name|mMapped
argument_list|)
expr_stmt|;
name|Error
name|error
init|=
name|mBuffer
operator|->
name|map
argument_list|(
name|access
argument_list|,
operator|&
name|mMapPointer
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
name|mMapPointer
operator|=
name|NULL
expr_stmt|;
return|return
name|error
return|;
block|}
name|ASSERT
argument_list|(
name|access
operator|==
name|GL_WRITE_ONLY_OES
argument_list|)
expr_stmt|;
name|mMapped
operator|=
name|GL_TRUE
expr_stmt|;
name|mMapOffset
operator|=
literal|0
expr_stmt|;
name|mMapLength
operator|=
name|mSize
expr_stmt|;
name|mAccess
operator|=
name|access
expr_stmt|;
name|mAccessFlags
operator|=
name|GL_MAP_WRITE_BIT
expr_stmt|;
name|mIndexRangeCache
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
name|error
return|;
block|}
DECL|function|mapRange
name|Error
name|Buffer
operator|::
name|mapRange
parameter_list|(
name|GLintptr
name|offset
parameter_list|,
name|GLsizeiptr
name|length
parameter_list|,
name|GLbitfield
name|access
parameter_list|)
block|{
name|ASSERT
argument_list|(
operator|!
name|mMapped
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|offset
operator|+
name|length
operator|<=
name|mSize
argument_list|)
expr_stmt|;
name|Error
name|error
init|=
name|mBuffer
operator|->
name|mapRange
argument_list|(
name|offset
argument_list|,
name|length
argument_list|,
name|access
argument_list|,
operator|&
name|mMapPointer
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
name|mMapPointer
operator|=
name|NULL
expr_stmt|;
return|return
name|error
return|;
block|}
name|mMapped
operator|=
name|GL_TRUE
expr_stmt|;
name|mMapOffset
operator|=
cast|static_cast
argument_list|<
name|GLint64
argument_list|>
argument_list|(
name|offset
argument_list|)
expr_stmt|;
name|mMapLength
operator|=
cast|static_cast
argument_list|<
name|GLint64
argument_list|>
argument_list|(
name|length
argument_list|)
expr_stmt|;
name|mAccess
operator|=
name|GL_WRITE_ONLY_OES
expr_stmt|;
name|mAccessFlags
operator|=
name|access
expr_stmt|;
comment|// The OES_mapbuffer extension states that GL_WRITE_ONLY_OES is the only valid
comment|// value for GL_BUFFER_ACCESS_OES because it was written against ES2.  Since there is
comment|// no update for ES3 and the GL_READ_ONLY and GL_READ_WRITE enums don't exist for ES,
comment|// we cannot properly set GL_BUFFER_ACCESS_OES when glMapBufferRange is called.
if|if
condition|(
operator|(
name|access
operator|&
name|GL_MAP_WRITE_BIT
operator|)
operator|>
literal|0
condition|)
block|{
name|mIndexRangeCache
operator|.
name|invalidateRange
argument_list|(
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|offset
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|length
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
DECL|function|unmap
name|Error
name|Buffer
operator|::
name|unmap
parameter_list|(
name|GLboolean
modifier|*
name|result
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|mMapped
argument_list|)
expr_stmt|;
name|Error
name|error
init|=
name|mBuffer
operator|->
name|unmap
argument_list|(
name|result
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
operator|*
name|result
operator|=
name|GL_FALSE
expr_stmt|;
return|return
name|error
return|;
block|}
name|mMapped
operator|=
name|GL_FALSE
expr_stmt|;
name|mMapPointer
operator|=
name|NULL
expr_stmt|;
name|mMapOffset
operator|=
literal|0
expr_stmt|;
name|mMapLength
operator|=
literal|0
expr_stmt|;
name|mAccess
operator|=
name|GL_WRITE_ONLY_OES
expr_stmt|;
name|mAccessFlags
operator|=
literal|0
expr_stmt|;
return|return
name|error
return|;
block|}
DECL|function|onTransformFeedback
name|void
name|Buffer
operator|::
name|onTransformFeedback
parameter_list|()
block|{
name|mIndexRangeCache
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|onPixelUnpack
name|void
name|Buffer
operator|::
name|onPixelUnpack
parameter_list|()
block|{
name|mIndexRangeCache
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|getIndexRange
name|Error
name|Buffer
operator|::
name|getIndexRange
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|size_t
name|count
parameter_list|,
name|bool
name|primitiveRestartEnabled
parameter_list|,
name|IndexRange
modifier|*
name|outRange
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|mIndexRangeCache
operator|.
name|findRange
argument_list|(
name|type
argument_list|,
name|offset
argument_list|,
name|count
argument_list|,
name|primitiveRestartEnabled
argument_list|,
name|outRange
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
name|Error
name|error
init|=
name|mBuffer
operator|->
name|getIndexRange
argument_list|(
name|type
argument_list|,
name|offset
argument_list|,
name|count
argument_list|,
name|primitiveRestartEnabled
argument_list|,
name|outRange
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
name|mIndexRangeCache
operator|.
name|addRange
argument_list|(
name|type
argument_list|,
name|offset
argument_list|,
name|count
argument_list|,
name|primitiveRestartEnabled
argument_list|,
operator|*
name|outRange
argument_list|)
expr_stmt|;
return|return
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
block|}
end_namespace
end_unit
