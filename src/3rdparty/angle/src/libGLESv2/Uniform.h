begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2010-2013 The ANGLE Project Authors. All rights reserved.
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
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_UNIFORM_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_UNIFORM_H_
define|#
directive|define
name|LIBGLESV2_UNIFORM_H_
end_define
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"common/blocklayout.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
comment|// Helper struct representing a single shader uniform
struct|struct
name|LinkedUniform
block|{
name|LinkedUniform
argument_list|(
argument|GLenum type
argument_list|,
argument|GLenum precision
argument_list|,
argument|const std::string&name
argument_list|,
argument|unsigned int arraySize
argument_list|,
argument|const int blockIndex
argument_list|,
argument|const sh::BlockMemberInfo&blockInfo
argument_list|)
empty_stmt|;
operator|~
name|LinkedUniform
argument_list|()
expr_stmt|;
name|bool
name|isArray
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|int
name|elementCount
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isReferencedByVertexShader
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isReferencedByFragmentShader
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isInDefaultBlock
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|dataSize
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSampler
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|GLenum
name|type
decl_stmt|;
specifier|const
name|GLenum
name|precision
decl_stmt|;
specifier|const
name|std
operator|::
name|string
name|name
expr_stmt|;
specifier|const
name|unsigned
name|int
name|arraySize
decl_stmt|;
specifier|const
name|int
name|blockIndex
decl_stmt|;
specifier|const
name|sh
operator|::
name|BlockMemberInfo
name|blockInfo
expr_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
name|bool
name|dirty
decl_stmt|;
name|unsigned
name|int
name|psRegisterIndex
decl_stmt|;
name|unsigned
name|int
name|vsRegisterIndex
decl_stmt|;
name|unsigned
name|int
name|registerCount
decl_stmt|;
comment|// Register "elements" are used for uniform structs in ES3, to appropriately identify single uniforms
comment|// inside aggregate types, which are packed according C-like structure rules.
name|unsigned
name|int
name|registerElement
decl_stmt|;
block|}
struct|;
comment|// Helper struct representing a single shader uniform block
struct|struct
name|UniformBlock
block|{
comment|// use GL_INVALID_INDEX for non-array elements
name|UniformBlock
argument_list|(
argument|const std::string&name
argument_list|,
argument|unsigned int elementIndex
argument_list|,
argument|unsigned int dataSize
argument_list|)
empty_stmt|;
name|bool
name|isArrayElement
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isReferencedByVertexShader
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isReferencedByFragmentShader
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|std
operator|::
name|string
name|name
expr_stmt|;
specifier|const
name|unsigned
name|int
name|elementIndex
decl_stmt|;
specifier|const
name|unsigned
name|int
name|dataSize
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|unsigned
name|int
operator|>
name|memberUniformIndexes
expr_stmt|;
name|unsigned
name|int
name|psRegisterIndex
decl_stmt|;
name|unsigned
name|int
name|vsRegisterIndex
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_UNIFORM_H_
end_comment
end_unit
