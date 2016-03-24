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
comment|// validationES2.h: Validation functions for OpenGL ES 2.0 entry point parameters
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_VALIDATION_ES2_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_VALIDATION_ES2_H_
define|#
directive|define
name|LIBANGLE_VALIDATION_ES2_H_
end_define
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2ext.h>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Context
decl_stmt|;
name|class
name|ValidationContext
decl_stmt|;
name|bool
name|ValidateES2TexImageParameters
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
name|GLenum
name|internalformat
parameter_list|,
name|bool
name|isCompressed
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
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|pixels
parameter_list|)
function_decl|;
name|bool
name|ValidateES2CopyTexImageParameters
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
name|ValidateES2TexStorageParameters
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLsizei
name|levels
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
name|ValidES2ReadFormatType
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|)
function_decl|;
name|bool
name|ValidateDiscardFramebufferEXT
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
parameter_list|)
function_decl|;
name|bool
name|ValidateDrawBuffersEXT
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
name|ValidateBindVertexArrayOES
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
name|ValidateDeleteVertexArraysOES
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
name|ValidateGenVertexArraysOES
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
name|ValidateIsVertexArrayOES
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|)
function_decl|;
name|bool
name|ValidateProgramBinaryOES
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
name|ValidateGetProgramBinaryOES
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
comment|// GL_KHR_debug
name|bool
name|ValidateDebugMessageControlKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|source
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLenum
name|severity
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|ids
parameter_list|,
name|GLboolean
name|enabled
parameter_list|)
function_decl|;
name|bool
name|ValidateDebugMessageInsertKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|source
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLuint
name|id
parameter_list|,
name|GLenum
name|severity
parameter_list|,
name|GLsizei
name|length
parameter_list|,
specifier|const
name|GLchar
modifier|*
name|buf
parameter_list|)
function_decl|;
name|bool
name|ValidateDebugMessageCallbackKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLDEBUGPROCKHR
name|callback
parameter_list|,
specifier|const
name|void
modifier|*
name|userParam
parameter_list|)
function_decl|;
name|bool
name|ValidateGetDebugMessageLogKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLuint
name|count
parameter_list|,
name|GLsizei
name|bufSize
parameter_list|,
name|GLenum
modifier|*
name|sources
parameter_list|,
name|GLenum
modifier|*
name|types
parameter_list|,
name|GLuint
modifier|*
name|ids
parameter_list|,
name|GLenum
modifier|*
name|severities
parameter_list|,
name|GLsizei
modifier|*
name|lengths
parameter_list|,
name|GLchar
modifier|*
name|messageLog
parameter_list|)
function_decl|;
name|bool
name|ValidatePushDebugGroupKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|source
parameter_list|,
name|GLuint
name|id
parameter_list|,
name|GLsizei
name|length
parameter_list|,
specifier|const
name|GLchar
modifier|*
name|message
parameter_list|)
function_decl|;
name|bool
name|ValidatePopDebugGroupKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|)
function_decl|;
name|bool
name|ValidateObjectLabelKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|identifier
parameter_list|,
name|GLuint
name|name
parameter_list|,
name|GLsizei
name|length
parameter_list|,
specifier|const
name|GLchar
modifier|*
name|label
parameter_list|)
function_decl|;
name|bool
name|ValidateGetObjectLabelKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|identifier
parameter_list|,
name|GLuint
name|name
parameter_list|,
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|GLchar
modifier|*
name|label
parameter_list|)
function_decl|;
name|bool
name|ValidateObjectPtrLabelKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|GLsizei
name|length
parameter_list|,
specifier|const
name|GLchar
modifier|*
name|label
parameter_list|)
function_decl|;
name|bool
name|ValidateGetObjectPtrLabelKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|GLchar
modifier|*
name|label
parameter_list|)
function_decl|;
name|bool
name|ValidateGetPointervKHR
parameter_list|(
name|Context
modifier|*
name|context
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|void
modifier|*
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|ValidateBlitFramebufferANGLE
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
name|ValidateClear
parameter_list|(
name|ValidationContext
modifier|*
name|context
parameter_list|,
name|GLbitfield
name|mask
parameter_list|)
function_decl|;
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
comment|// LIBANGLE_VALIDATION_ES2_H_
end_comment
end_unit
