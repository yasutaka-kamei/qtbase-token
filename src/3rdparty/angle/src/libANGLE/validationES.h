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
comment|// validationES.h: Validation functions for generic OpenGL ES entry point parameters
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_VALIDATION_ES_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_VALIDATION_ES_H_
define|#
directive|define
name|LIBANGLE_VALIDATION_ES_H_
end_define
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<GLES3/gl3.h>
end_include
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|Display
decl_stmt|;
name|class
name|Image
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Context
decl_stmt|;
name|class
name|Program
decl_stmt|;
name|class
name|Shader
decl_stmt|;
name|class
name|ValidationContext
decl_stmt|;
name|bool
name|ValidCap
parameter_list|(
specifier|const
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|cap
parameter_list|)
function_decl|;
name|bool
name|ValidTextureTarget
parameter_list|(
specifier|const
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|ValidTexture2DTarget
parameter_list|(
specifier|const
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|ValidTexture3DTarget
parameter_list|(
specifier|const
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|ValidTexture2DDestinationTarget
parameter_list|(
specifier|const
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|ValidTexture3DDestinationTarget
parameter_list|(
specifier|const
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|ValidFramebufferTarget
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|ValidBufferTarget
parameter_list|(
specifier|const
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|ValidBufferParameter
parameter_list|(
specifier|const
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|pname
parameter_list|)
function_decl|;
name|bool
name|ValidMipLevel
parameter_list|(
specifier|const
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|)
function_decl|;
name|bool
name|ValidImageSizeParameters
parameter_list|(
specifier|const
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLsizei
name|depth
parameter_list|,
name|bool
name|isSubImage
parameter_list|)
function_decl|;
name|bool
name|ValidCompressedImageSize
parameter_list|(
specifier|const
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLenum
name|internalFormat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
name|bool
name|ValidQueryType
parameter_list|(
specifier|const
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|queryType
parameter_list|)
function_decl|;
comment|// Returns valid program if id is a valid program name
comment|// Errors INVALID_OPERATION if valid shader is given and returns NULL
comment|// Errors INVALID_VALUE otherwise and returns NULL
name|Program
modifier|*
name|GetValidProgram
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|id
parameter_list|)
function_decl|;
comment|// Returns valid shader if id is a valid shader name
comment|// Errors INVALID_OPERATION if valid program is given and returns NULL
comment|// Errors INVALID_VALUE otherwise and returns NULL
name|Shader
modifier|*
name|GetValidShader
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|id
parameter_list|)
function_decl|;
name|bool
name|ValidateAttachmentTarget
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|attachment
parameter_list|)
function_decl|;
name|bool
name|ValidateRenderbufferStorageParametersBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLsizei
name|samples
parameter_list|,
name|GLenum
name|internalformat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
name|bool
name|ValidateRenderbufferStorageParametersANGLE
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLsizei
name|samples
parameter_list|,
name|GLenum
name|internalformat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
name|bool
name|ValidateFramebufferRenderbufferParameters
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLenum
name|attachment
parameter_list|,
name|GLenum
name|renderbuffertarget
parameter_list|,
name|GLuint
name|renderbuffer
parameter_list|)
function_decl|;
name|bool
name|ValidateBlitFramebufferParameters
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLint
name|srcX0
parameter_list|,
name|GLint
name|srcY0
parameter_list|,
name|GLint
name|srcX1
parameter_list|,
name|GLint
name|srcY1
parameter_list|,
name|GLint
name|dstX0
parameter_list|,
name|GLint
name|dstY0
parameter_list|,
name|GLint
name|dstX1
parameter_list|,
name|GLint
name|dstY1
parameter_list|,
name|GLbitfield
name|mask
parameter_list|,
name|GLenum
name|filter
parameter_list|)
function_decl|;
name|bool
name|ValidateGetVertexAttribParameters
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|pname
parameter_list|)
function_decl|;
name|bool
name|ValidateTexParamParameters
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
name|param
parameter_list|)
function_decl|;
name|bool
name|ValidateSamplerObjectParameter
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|pname
parameter_list|)
function_decl|;
name|bool
name|ValidateReadPixels
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLvoid
modifier|*
name|pixels
parameter_list|)
function_decl|;
name|bool
name|ValidateReadnPixelsEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLsizei
name|bufSize
parameter_list|,
name|GLvoid
modifier|*
name|pixels
parameter_list|)
function_decl|;
name|bool
name|ValidateGenQueriesBase
argument_list|(
name|gl
operator|::
name|Context
operator|*
name|context
argument_list|,
name|GLsizei
name|n
argument_list|,
specifier|const
name|GLuint
operator|*
name|ids
argument_list|)
decl_stmt|;
name|bool
name|ValidateGenQueriesEXT
argument_list|(
name|gl
operator|::
name|Context
operator|*
name|context
argument_list|,
name|GLsizei
name|n
argument_list|,
specifier|const
name|GLuint
operator|*
name|ids
argument_list|)
decl_stmt|;
name|bool
name|ValidateDeleteQueriesBase
argument_list|(
name|gl
operator|::
name|Context
operator|*
name|context
argument_list|,
name|GLsizei
name|n
argument_list|,
specifier|const
name|GLuint
operator|*
name|ids
argument_list|)
decl_stmt|;
name|bool
name|ValidateDeleteQueriesEXT
argument_list|(
name|gl
operator|::
name|Context
operator|*
name|context
argument_list|,
name|GLsizei
name|n
argument_list|,
specifier|const
name|GLuint
operator|*
name|ids
argument_list|)
decl_stmt|;
name|bool
name|ValidateBeginQueryBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLuint
name|id
parameter_list|)
function_decl|;
name|bool
name|ValidateBeginQueryEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLuint
name|id
parameter_list|)
function_decl|;
name|bool
name|ValidateEndQueryBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|ValidateEndQueryEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|ValidateQueryCounterEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|id
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
name|bool
name|ValidateGetQueryivBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|)
function_decl|;
name|bool
name|ValidateGetQueryivEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|ValidateGetQueryObjectValueBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|)
function_decl|;
name|bool
name|ValidateGetQueryObjectivEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|id
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|ValidateGetQueryObjectuivEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|id
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLuint
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|ValidateGetQueryObjecti64vEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|id
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint64
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|ValidateGetQueryObjectui64vEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|id
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLuint64
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|ValidateUniform
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|uniformType
parameter_list|,
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|)
function_decl|;
name|bool
name|ValidateUniformMatrix
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|matrixType
parameter_list|,
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLboolean
name|transpose
parameter_list|)
function_decl|;
name|bool
name|ValidateStateQuery
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLenum
modifier|*
name|nativeType
parameter_list|,
name|unsigned
name|int
modifier|*
name|numParams
parameter_list|)
function_decl|;
name|bool
name|ValidateCopyTexImageParametersBase
parameter_list|(
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLenum
name|internalformat
parameter_list|,
name|bool
name|isSubImage
parameter_list|,
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|,
name|GLint
name|zoffset
parameter_list|,
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLint
name|border
parameter_list|,
name|GLenum
modifier|*
name|textureInternalFormatOut
parameter_list|)
function_decl|;
name|bool
name|ValidateDrawArrays
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|mode
parameter_list|,
name|GLint
name|first
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLsizei
name|primcount
parameter_list|)
function_decl|;
name|bool
name|ValidateDrawArraysInstanced
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|mode
parameter_list|,
name|GLint
name|first
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLsizei
name|primcount
parameter_list|)
function_decl|;
name|bool
name|ValidateDrawArraysInstancedANGLE
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|mode
parameter_list|,
name|GLint
name|first
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLsizei
name|primcount
parameter_list|)
function_decl|;
name|bool
name|ValidateDrawElements
parameter_list|(
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLenum
name|mode
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|indices
parameter_list|,
name|GLsizei
name|primcount
parameter_list|,
name|IndexRange
modifier|*
name|indexRangeOut
parameter_list|)
function_decl|;
name|bool
name|ValidateDrawElementsInstanced
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|mode
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|indices
parameter_list|,
name|GLsizei
name|primcount
parameter_list|,
name|IndexRange
modifier|*
name|indexRangeOut
parameter_list|)
function_decl|;
name|bool
name|ValidateDrawElementsInstancedANGLE
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|mode
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|indices
parameter_list|,
name|GLsizei
name|primcount
parameter_list|,
name|IndexRange
modifier|*
name|indexRangeOut
parameter_list|)
function_decl|;
name|bool
name|ValidateFramebufferTextureBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLenum
name|attachment
parameter_list|,
name|GLuint
name|texture
parameter_list|,
name|GLint
name|level
parameter_list|)
function_decl|;
name|bool
name|ValidateFramebufferTexture2D
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLenum
name|attachment
parameter_list|,
name|GLenum
name|textarget
parameter_list|,
name|GLuint
name|texture
parameter_list|,
name|GLint
name|level
parameter_list|)
function_decl|;
name|bool
name|ValidateFramebufferRenderbuffer
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLenum
name|attachment
parameter_list|,
name|GLenum
name|renderbuffertarget
parameter_list|,
name|GLuint
name|renderbuffer
parameter_list|)
function_decl|;
name|bool
name|ValidateGetUniformBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|program
parameter_list|,
name|GLint
name|location
parameter_list|)
function_decl|;
name|bool
name|ValidateGetUniformfv
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|program
parameter_list|,
name|GLint
name|location
parameter_list|,
name|GLfloat
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|ValidateGetUniformiv
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|program
parameter_list|,
name|GLint
name|location
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|ValidateGetnUniformfvEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|program
parameter_list|,
name|GLint
name|location
parameter_list|,
name|GLsizei
name|bufSize
parameter_list|,
name|GLfloat
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|ValidateGetnUniformivEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|program
parameter_list|,
name|GLint
name|location
parameter_list|,
name|GLsizei
name|bufSize
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|ValidateDiscardFramebufferBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLsizei
name|numAttachments
parameter_list|,
specifier|const
name|GLenum
modifier|*
name|attachments
parameter_list|,
name|bool
name|defaultFramebuffer
parameter_list|)
function_decl|;
name|bool
name|ValidateInsertEventMarkerEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLsizei
name|length
parameter_list|,
specifier|const
name|char
modifier|*
name|marker
parameter_list|)
function_decl|;
name|bool
name|ValidatePushGroupMarkerEXT
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLsizei
name|length
parameter_list|,
specifier|const
name|char
modifier|*
name|marker
parameter_list|)
function_decl|;
name|bool
name|ValidateEGLImageTargetTexture2DOES
argument_list|(
name|Context
operator|*
name|context
argument_list|,
name|egl
operator|::
name|Display
operator|*
name|display
argument_list|,
name|GLenum
name|target
argument_list|,
name|egl
operator|::
name|Image
operator|*
name|image
argument_list|)
decl_stmt|;
name|bool
name|ValidateEGLImageTargetRenderbufferStorageOES
argument_list|(
name|Context
operator|*
name|context
argument_list|,
name|egl
operator|::
name|Display
operator|*
name|display
argument_list|,
name|GLenum
name|target
argument_list|,
name|egl
operator|::
name|Image
operator|*
name|image
argument_list|)
decl_stmt|;
name|bool
name|ValidateBindVertexArrayBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|array
parameter_list|)
function_decl|;
name|bool
name|ValidateDeleteVertexArraysBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLsizei
name|n
parameter_list|)
function_decl|;
name|bool
name|ValidateGenVertexArraysBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLsizei
name|n
parameter_list|)
function_decl|;
name|bool
name|ValidateProgramBinaryBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|program
parameter_list|,
name|GLenum
name|binaryFormat
parameter_list|,
specifier|const
name|void
modifier|*
name|binary
parameter_list|,
name|GLint
name|length
parameter_list|)
function_decl|;
name|bool
name|ValidateGetProgramBinaryBase
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|program
parameter_list|,
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|GLenum
modifier|*
name|binaryFormat
parameter_list|,
name|void
modifier|*
name|binary
parameter_list|)
function_decl|;
name|bool
name|ValidateCopyTexImage2D
parameter_list|(
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLenum
name|internalformat
parameter_list|,
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLint
name|border
parameter_list|)
function_decl|;
name|bool
name|ValidateDrawBuffersBase
parameter_list|(
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLenum
modifier|*
name|bufs
parameter_list|)
function_decl|;
name|bool
name|ValidateCopyTexSubImage2D
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|,
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
comment|// Error messages shared here for use in testing.
specifier|extern
specifier|const
name|char
modifier|*
name|g_ExceedsMaxElementErrorMessage
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace gl
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_VALIDATION_ES_H_
end_comment
end_unit
