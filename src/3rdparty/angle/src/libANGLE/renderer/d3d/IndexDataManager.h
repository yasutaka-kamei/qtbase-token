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
comment|// IndexDataManager.h: Defines the IndexDataManager, a class that
end_comment
begin_comment
comment|// runs the Buffer translation process for index buffers.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_INDEXDATAMANAGER_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_INDEXDATAMANAGER_H_
define|#
directive|define
name|LIBANGLE_INDEXDATAMANAGER_H_
end_define
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RendererD3D.h"
end_include
begin_macro
name|namespace
end_macro
begin_block
block|{
enum|enum
block|{
name|INITIAL_INDEX_BUFFER_SIZE
init|=
literal|4096
operator|*
expr|sizeof
operator|(
name|GLuint
operator|)
block|}
enum|;
block|}
end_block
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Buffer
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|IndexBufferInterface
decl_stmt|;
name|class
name|StaticIndexBufferInterface
decl_stmt|;
name|class
name|StreamingIndexBufferInterface
decl_stmt|;
name|class
name|IndexBuffer
decl_stmt|;
name|class
name|BufferD3D
decl_stmt|;
name|class
name|RendererD3D
decl_stmt|;
struct|struct
name|SourceIndexData
block|{
name|BufferD3D
modifier|*
name|srcBuffer
decl_stmt|;
specifier|const
name|GLvoid
modifier|*
name|srcIndices
decl_stmt|;
name|unsigned
name|int
name|srcCount
decl_stmt|;
name|GLenum
name|srcIndexType
decl_stmt|;
name|bool
name|srcIndicesChanged
decl_stmt|;
block|}
struct|;
struct|struct
name|TranslatedIndexData
block|{
name|gl
operator|::
name|IndexRange
name|indexRange
expr_stmt|;
name|unsigned
name|int
name|startIndex
decl_stmt|;
name|unsigned
name|int
name|startOffset
decl_stmt|;
comment|// In bytes
name|IndexBuffer
modifier|*
name|indexBuffer
decl_stmt|;
name|BufferD3D
modifier|*
name|storage
decl_stmt|;
name|GLenum
name|indexType
decl_stmt|;
name|unsigned
name|int
name|serial
decl_stmt|;
name|SourceIndexData
name|srcIndexData
decl_stmt|;
block|}
struct|;
name|class
name|IndexDataManager
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|explicit
name|IndexDataManager
argument_list|(
argument|BufferFactoryD3D *factory
argument_list|,
argument|RendererClass rendererClass
argument_list|)
block|;
name|virtual
operator|~
name|IndexDataManager
argument_list|()
block|;
name|gl
operator|::
name|Error
name|prepareIndexData
argument_list|(
argument|GLenum srcType
argument_list|,
argument|GLsizei count
argument_list|,
argument|gl::Buffer *glBuffer
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|TranslatedIndexData *translated
argument_list|,
argument|bool primitiveRestartFixedIndexEnabled
argument_list|)
block|;
name|private
operator|:
name|gl
operator|::
name|Error
name|streamIndexData
argument_list|(
argument|const GLvoid *data
argument_list|,
argument|unsigned int count
argument_list|,
argument|GLenum srcType
argument_list|,
argument|GLenum dstType
argument_list|,
argument|bool usePrimitiveRestartFixedIndex
argument_list|,
argument|TranslatedIndexData *translated
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getStreamingIndexBuffer
argument_list|(
argument|GLenum destinationIndexType
argument_list|,
argument|IndexBufferInterface **outBuffer
argument_list|)
block|;
name|BufferFactoryD3D
operator|*
specifier|const
name|mFactory
block|;
name|RendererClass
name|mRendererClass
block|;
name|StreamingIndexBufferInterface
operator|*
name|mStreamingBufferShort
block|;
name|StreamingIndexBufferInterface
operator|*
name|mStreamingBufferInt
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_INDEXDATAMANAGER_H_
end_comment
end_unit
