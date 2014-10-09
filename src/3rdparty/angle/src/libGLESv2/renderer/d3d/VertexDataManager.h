begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// VertexDataManager.h: Defines the VertexDataManager, a class that
end_comment
begin_comment
comment|// runs the Buffer translation process.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_VERTEXDATAMANAGER_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_VERTEXDATAMANAGER_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_VERTEXDATAMANAGER_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/Constants.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/VertexAttribute.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
struct_decl|struct
name|VertexAttribute
struct_decl|;
name|class
name|ProgramBinary
decl_stmt|;
struct_decl|struct
name|VertexAttribCurrentValueData
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|BufferD3D
decl_stmt|;
name|class
name|StreamingVertexBufferInterface
decl_stmt|;
name|class
name|VertexBuffer
decl_stmt|;
name|class
name|Renderer
decl_stmt|;
struct|struct
name|TranslatedAttribute
block|{
name|TranslatedAttribute
argument_list|()
operator|:
name|active
argument_list|(
name|false
argument_list|)
operator|,
name|attribute
argument_list|(
name|NULL
argument_list|)
operator|,
name|currentValueType
argument_list|(
name|GL_NONE
argument_list|)
operator|,
name|offset
argument_list|(
literal|0
argument_list|)
operator|,
name|stride
argument_list|(
literal|0
argument_list|)
operator|,
name|vertexBuffer
argument_list|(
name|NULL
argument_list|)
operator|,
name|storage
argument_list|(
name|NULL
argument_list|)
operator|,
name|serial
argument_list|(
literal|0
argument_list|)
operator|,
name|divisor
argument_list|(
literal|0
argument_list|)
block|{}
expr_stmt|;
name|bool
name|active
decl_stmt|;
specifier|const
name|gl
operator|::
name|VertexAttribute
operator|*
name|attribute
expr_stmt|;
name|GLenum
name|currentValueType
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
name|unsigned
name|int
name|stride
decl_stmt|;
comment|// 0 means not to advance the read pointer at all
name|VertexBuffer
modifier|*
name|vertexBuffer
decl_stmt|;
name|BufferD3D
modifier|*
name|storage
decl_stmt|;
name|unsigned
name|int
name|serial
decl_stmt|;
name|unsigned
name|int
name|divisor
decl_stmt|;
block|}
struct|;
name|class
name|VertexDataManager
block|{
name|public
label|:
name|VertexDataManager
argument_list|(
name|rx
operator|::
name|Renderer
operator|*
name|renderer
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|VertexDataManager
argument_list|()
expr_stmt|;
name|gl
operator|::
name|Error
name|prepareVertexData
argument_list|(
argument|const gl::VertexAttribute attribs[]
argument_list|,
argument|const gl::VertexAttribCurrentValueData currentValues[]
argument_list|,
argument|gl::ProgramBinary *programBinary
argument_list|,
argument|GLint start
argument_list|,
argument|GLsizei count
argument_list|,
argument|TranslatedAttribute *outAttribs
argument_list|,
argument|GLsizei instances
argument_list|)
expr_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|VertexDataManager
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|reserveSpaceForAttrib
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|const gl::VertexAttribCurrentValueData&currentValue
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|)
specifier|const
expr_stmt|;
name|void
name|invalidateMatchingStaticData
argument_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
operator|&
name|attrib
argument_list|,
specifier|const
name|gl
operator|::
name|VertexAttribCurrentValueData
operator|&
name|currentValue
argument_list|)
decl|const
decl_stmt|;
name|gl
operator|::
name|Error
name|storeAttribute
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|const gl::VertexAttribCurrentValueData&currentValue
argument_list|,
argument|TranslatedAttribute *translated
argument_list|,
argument|GLint start
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|)
expr_stmt|;
name|gl
operator|::
name|Error
name|storeCurrentValue
argument_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
operator|&
name|attrib
argument_list|,
specifier|const
name|gl
operator|::
name|VertexAttribCurrentValueData
operator|&
name|currentValue
argument_list|,
name|TranslatedAttribute
operator|*
name|translated
argument_list|,
name|gl
operator|::
name|VertexAttribCurrentValueData
operator|*
name|cachedValue
argument_list|,
name|size_t
operator|*
name|cachedOffset
argument_list|,
name|StreamingVertexBufferInterface
operator|*
name|buffer
argument_list|)
expr_stmt|;
name|rx
operator|::
name|Renderer
operator|*
specifier|const
name|mRenderer
expr_stmt|;
name|StreamingVertexBufferInterface
modifier|*
name|mStreamingBuffer
decl_stmt|;
name|gl
operator|::
name|VertexAttribCurrentValueData
name|mCurrentValue
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
expr_stmt|;
name|StreamingVertexBufferInterface
modifier|*
name|mCurrentValueBuffer
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
decl_stmt|;
name|std
operator|::
name|size_t
name|mCurrentValueOffsets
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
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
comment|// LIBGLESV2_RENDERER_VERTEXDATAMANAGER_H_
end_comment
end_unit
