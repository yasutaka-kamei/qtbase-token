begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// utilities.h: Conversion functions and other utility routines.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMMON_UTILITIES_H_
end_ifndef
begin_define
DECL|macro|COMMON_UTILITIES_H_
define|#
directive|define
name|COMMON_UTILITIES_H_
end_define
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<EGL/eglext.h>
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
file|<math.h>
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
name|int
name|VariableComponentCount
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|GLenum
name|VariableComponentType
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|size_t
name|VariableComponentSize
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|size_t
name|VariableInternalSize
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|size_t
name|VariableExternalSize
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|GLenum
name|VariableBoolVectorType
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|int
name|VariableRowCount
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|int
name|VariableColumnCount
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|bool
name|IsSamplerType
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|GLenum
name|SamplerTypeToTextureType
parameter_list|(
name|GLenum
name|samplerType
parameter_list|)
function_decl|;
name|bool
name|IsMatrixType
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|GLenum
name|TransposeMatrixType
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|int
name|VariableRegisterCount
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|int
name|MatrixRegisterCount
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|bool
name|isRowMajorMatrix
parameter_list|)
function_decl|;
name|int
name|MatrixComponentCount
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|bool
name|isRowMajorMatrix
parameter_list|)
function_decl|;
name|int
name|VariableSortOrder
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|int
name|AllocateFirstFreeBits
parameter_list|(
name|unsigned
name|int
modifier|*
name|bits
parameter_list|,
name|unsigned
name|int
name|allocationSize
parameter_list|,
name|unsigned
name|int
name|bitsSize
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|GLenum
name|FirstCubeMapTextureTarget
init|=
name|GL_TEXTURE_CUBE_MAP_POSITIVE_X
decl_stmt|;
specifier|static
specifier|const
name|GLenum
name|LastCubeMapTextureTarget
init|=
name|GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
decl_stmt|;
name|bool
name|IsCubeMapTextureTarget
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|size_t
name|CubeMapTextureTargetToLayerIndex
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|GLenum
name|LayerIndexToCubeMapTextureTarget
parameter_list|(
name|size_t
name|index
parameter_list|)
function_decl|;
comment|// Parse the base uniform name and array index.  Returns the base name of the uniform. outSubscript is
comment|// set to GL_INVALID_INDEX if the provided name is not an array or the array index is invalid.
name|std
operator|::
name|string
name|ParseUniformName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|,
name|size_t
operator|*
name|outSubscript
argument_list|)
expr_stmt|;
comment|// Find the range of index values in the provided indices pointer.  Primitive restart indices are
comment|// only counted in the range if primitive restart is disabled.
name|IndexRange
name|ComputeIndexRange
parameter_list|(
name|GLenum
name|indexType
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|indices
parameter_list|,
name|size_t
name|count
parameter_list|,
name|bool
name|primitiveRestartEnabled
parameter_list|)
function_decl|;
comment|// Get the primitive restart index value for the given index type.
name|GLuint
name|GetPrimitiveRestartIndex
parameter_list|(
name|GLenum
name|indexType
parameter_list|)
function_decl|;
name|bool
name|IsTriangleMode
parameter_list|(
name|GLenum
name|drawMode
parameter_list|)
function_decl|;
comment|// [OpenGL ES 3.0.2] Section 2.3.1 page 14
comment|// Data Conversion For State-Setting Commands
comment|// Floating-point values are rounded to the nearest integer, instead of truncated, as done by static_cast.
name|template
operator|<
name|typename
name|outT
operator|>
name|outT
name|iround
argument_list|(
argument|GLfloat value
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|outT
operator|>
operator|(
name|value
operator|>
literal|0.0f
operator|?
name|floor
argument_list|(
name|value
operator|+
literal|0.5f
argument_list|)
operator|:
name|ceil
argument_list|(
name|value
operator|-
literal|0.5f
argument_list|)
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|outT
operator|>
name|outT
name|uiround
argument_list|(
argument|GLfloat value
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|outT
operator|>
operator|(
name|value
operator|+
literal|0.5f
operator|)
return|;
block|}
name|unsigned
name|int
name|ParseAndStripArrayIndex
argument_list|(
name|std
operator|::
name|string
operator|*
name|name
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace gl
end_comment
begin_decl_stmt
name|namespace
name|egl
block|{
specifier|static
specifier|const
name|EGLenum
name|FirstCubeMapTextureTarget
init|=
name|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X_KHR
decl_stmt|;
specifier|static
specifier|const
name|EGLenum
name|LastCubeMapTextureTarget
init|=
name|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_KHR
decl_stmt|;
name|bool
name|IsCubeMapTextureTarget
parameter_list|(
name|EGLenum
name|target
parameter_list|)
function_decl|;
name|size_t
name|CubeMapTextureTargetToLayerIndex
parameter_list|(
name|EGLenum
name|target
parameter_list|)
function_decl|;
name|EGLenum
name|LayerIndexToCubeMapTextureTarget
parameter_list|(
name|size_t
name|index
parameter_list|)
function_decl|;
name|bool
name|IsTextureTarget
parameter_list|(
name|EGLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|IsRenderbufferTarget
parameter_list|(
name|EGLenum
name|target
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|egl_gl
block|{
name|GLenum
name|EGLCubeMapTargetToGLCubeMapTarget
parameter_list|(
name|EGLenum
name|eglTarget
parameter_list|)
function_decl|;
name|GLenum
name|EGLImageTargetToGLTextureTarget
parameter_list|(
name|EGLenum
name|eglTarget
parameter_list|)
function_decl|;
name|GLuint
name|EGLClientBufferToGLObjectHandle
parameter_list|(
name|EGLClientBuffer
name|buffer
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
end_if
begin_expr_stmt
name|std
operator|::
name|string
name|getTempPath
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|writeFile
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_PLATFORM_WINDOWS
argument_list|)
end_if
begin_function_decl
name|void
name|ScheduleYield
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMMON_UTILITIES_H_
end_comment
end_unit
