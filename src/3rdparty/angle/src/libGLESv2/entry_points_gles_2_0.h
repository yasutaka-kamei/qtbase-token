begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright(c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// entry_points_gles_2_0.h : Defines the GLES 2.0 entry points.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_ENTRYPOINTGLES20_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_ENTRYPOINTGLES20_H_
define|#
directive|define
name|LIBGLESV2_ENTRYPOINTGLES20_H_
end_define
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<export.h>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|ActiveTexture
parameter_list|(
name|GLenum
name|texture
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|AttachShader
parameter_list|(
name|GLuint
name|program
parameter_list|,
name|GLuint
name|shader
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BindAttribLocation
parameter_list|(
name|GLuint
name|program
parameter_list|,
name|GLuint
name|index
parameter_list|,
specifier|const
name|GLchar
modifier|*
name|name
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BindBuffer
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLuint
name|buffer
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BindFramebuffer
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLuint
name|framebuffer
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BindRenderbuffer
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLuint
name|renderbuffer
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BindTexture
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLuint
name|texture
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BlendColor
parameter_list|(
name|GLfloat
name|red
parameter_list|,
name|GLfloat
name|green
parameter_list|,
name|GLfloat
name|blue
parameter_list|,
name|GLfloat
name|alpha
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BlendEquation
parameter_list|(
name|GLenum
name|mode
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BlendEquationSeparate
parameter_list|(
name|GLenum
name|modeRGB
parameter_list|,
name|GLenum
name|modeAlpha
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BlendFunc
parameter_list|(
name|GLenum
name|sfactor
parameter_list|,
name|GLenum
name|dfactor
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BlendFuncSeparate
parameter_list|(
name|GLenum
name|srcRGB
parameter_list|,
name|GLenum
name|dstRGB
parameter_list|,
name|GLenum
name|srcAlpha
parameter_list|,
name|GLenum
name|dstAlpha
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BufferData
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLsizeiptr
name|size
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|data
parameter_list|,
name|GLenum
name|usage
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|BufferSubData
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLintptr
name|offset
parameter_list|,
name|GLsizeiptr
name|size
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|data
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|GLenum
name|GL_APIENTRY
name|CheckFramebufferStatus
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Clear
parameter_list|(
name|GLbitfield
name|mask
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|ClearColor
parameter_list|(
name|GLfloat
name|red
parameter_list|,
name|GLfloat
name|green
parameter_list|,
name|GLfloat
name|blue
parameter_list|,
name|GLfloat
name|alpha
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|ClearDepthf
parameter_list|(
name|GLfloat
name|depth
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|ClearStencil
parameter_list|(
name|GLint
name|s
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|ColorMask
parameter_list|(
name|GLboolean
name|red
parameter_list|,
name|GLboolean
name|green
parameter_list|,
name|GLboolean
name|blue
parameter_list|,
name|GLboolean
name|alpha
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|CompileShader
parameter_list|(
name|GLuint
name|shader
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|CompressedTexImage2D
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLenum
name|internalformat
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
name|GLsizei
name|imageSize
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|data
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|CompressedTexSubImage2D
parameter_list|(
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
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLsizei
name|imageSize
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|data
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|CopyTexImage2D
parameter_list|(
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
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|CopyTexSubImage2D
parameter_list|(
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
name|ANGLE_EXPORT
name|GLuint
name|GL_APIENTRY
name|CreateProgram
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|GLuint
name|GL_APIENTRY
name|CreateShader
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|CullFace
parameter_list|(
name|GLenum
name|mode
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DeleteBuffers
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|buffers
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DeleteFramebuffers
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|framebuffers
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DeleteProgram
parameter_list|(
name|GLuint
name|program
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DeleteRenderbuffers
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|renderbuffers
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DeleteShader
parameter_list|(
name|GLuint
name|shader
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DeleteTextures
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|textures
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DepthFunc
parameter_list|(
name|GLenum
name|func
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DepthMask
parameter_list|(
name|GLboolean
name|flag
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DepthRangef
parameter_list|(
name|GLfloat
name|n
parameter_list|,
name|GLfloat
name|f
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DetachShader
parameter_list|(
name|GLuint
name|program
parameter_list|,
name|GLuint
name|shader
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Disable
parameter_list|(
name|GLenum
name|cap
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DisableVertexAttribArray
parameter_list|(
name|GLuint
name|index
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DrawArrays
parameter_list|(
name|GLenum
name|mode
parameter_list|,
name|GLint
name|first
parameter_list|,
name|GLsizei
name|count
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|DrawElements
parameter_list|(
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
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Enable
parameter_list|(
name|GLenum
name|cap
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|EnableVertexAttribArray
parameter_list|(
name|GLuint
name|index
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|FramebufferRenderbuffer
parameter_list|(
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
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|FramebufferTexture2D
parameter_list|(
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
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|FrontFace
parameter_list|(
name|GLenum
name|mode
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GenBuffers
parameter_list|(
name|GLsizei
name|n
parameter_list|,
name|GLuint
modifier|*
name|buffers
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GenerateMipmap
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GenFramebuffers
parameter_list|(
name|GLsizei
name|n
parameter_list|,
name|GLuint
modifier|*
name|framebuffers
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GenRenderbuffers
parameter_list|(
name|GLsizei
name|n
parameter_list|,
name|GLuint
modifier|*
name|renderbuffers
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GenTextures
parameter_list|(
name|GLsizei
name|n
parameter_list|,
name|GLuint
modifier|*
name|textures
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetActiveAttrib
parameter_list|(
name|GLuint
name|program
parameter_list|,
name|GLuint
name|index
parameter_list|,
name|GLsizei
name|bufsize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|GLint
modifier|*
name|size
parameter_list|,
name|GLenum
modifier|*
name|type
parameter_list|,
name|GLchar
modifier|*
name|name
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetActiveUniform
parameter_list|(
name|GLuint
name|program
parameter_list|,
name|GLuint
name|index
parameter_list|,
name|GLsizei
name|bufsize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|GLint
modifier|*
name|size
parameter_list|,
name|GLenum
modifier|*
name|type
parameter_list|,
name|GLchar
modifier|*
name|name
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetAttachedShaders
parameter_list|(
name|GLuint
name|program
parameter_list|,
name|GLsizei
name|maxcount
parameter_list|,
name|GLsizei
modifier|*
name|count
parameter_list|,
name|GLuint
modifier|*
name|shaders
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|GLint
name|GL_APIENTRY
name|GetAttribLocation
parameter_list|(
name|GLuint
name|program
parameter_list|,
specifier|const
name|GLchar
modifier|*
name|name
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetBooleanv
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLboolean
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetBufferParameteriv
parameter_list|(
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
name|ANGLE_EXPORT
name|GLenum
name|GL_APIENTRY
name|GetError
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetFloatv
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLfloat
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetFramebufferAttachmentParameteriv
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|attachment
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetIntegerv
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetProgramiv
parameter_list|(
name|GLuint
name|program
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetProgramInfoLog
parameter_list|(
name|GLuint
name|program
parameter_list|,
name|GLsizei
name|bufsize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|GLchar
modifier|*
name|infolog
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetRenderbufferParameteriv
parameter_list|(
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
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetShaderiv
parameter_list|(
name|GLuint
name|shader
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetShaderInfoLog
parameter_list|(
name|GLuint
name|shader
parameter_list|,
name|GLsizei
name|bufsize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|GLchar
modifier|*
name|infolog
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetShaderPrecisionFormat
parameter_list|(
name|GLenum
name|shadertype
parameter_list|,
name|GLenum
name|precisiontype
parameter_list|,
name|GLint
modifier|*
name|range
parameter_list|,
name|GLint
modifier|*
name|precision
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetShaderSource
parameter_list|(
name|GLuint
name|shader
parameter_list|,
name|GLsizei
name|bufsize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|GLchar
modifier|*
name|source
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
specifier|const
name|GLubyte
modifier|*
name|GL_APIENTRY
name|GetString
parameter_list|(
name|GLenum
name|name
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetTexParameterfv
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLfloat
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetTexParameteriv
parameter_list|(
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
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetUniformfv
parameter_list|(
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
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetUniformiv
parameter_list|(
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
name|ANGLE_EXPORT
name|GLint
name|GL_APIENTRY
name|GetUniformLocation
parameter_list|(
name|GLuint
name|program
parameter_list|,
specifier|const
name|GLchar
modifier|*
name|name
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetVertexAttribfv
parameter_list|(
name|GLuint
name|index
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLfloat
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetVertexAttribiv
parameter_list|(
name|GLuint
name|index
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|GetVertexAttribPointerv
parameter_list|(
name|GLuint
name|index
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLvoid
modifier|*
modifier|*
name|pointer
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Hint
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|mode
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|GLboolean
name|GL_APIENTRY
name|IsBuffer
parameter_list|(
name|GLuint
name|buffer
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|GLboolean
name|GL_APIENTRY
name|IsEnabled
parameter_list|(
name|GLenum
name|cap
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|GLboolean
name|GL_APIENTRY
name|IsFramebuffer
parameter_list|(
name|GLuint
name|framebuffer
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|GLboolean
name|GL_APIENTRY
name|IsProgram
parameter_list|(
name|GLuint
name|program
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|GLboolean
name|GL_APIENTRY
name|IsRenderbuffer
parameter_list|(
name|GLuint
name|renderbuffer
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|GLboolean
name|GL_APIENTRY
name|IsShader
parameter_list|(
name|GLuint
name|shader
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|GLboolean
name|GL_APIENTRY
name|IsTexture
parameter_list|(
name|GLuint
name|texture
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|LineWidth
parameter_list|(
name|GLfloat
name|width
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|LinkProgram
parameter_list|(
name|GLuint
name|program
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|PixelStorei
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLint
name|param
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|PolygonOffset
parameter_list|(
name|GLfloat
name|factor
parameter_list|,
name|GLfloat
name|units
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|ReadPixels
parameter_list|(
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
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|ReleaseShaderCompiler
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|RenderbufferStorage
parameter_list|(
name|GLenum
name|target
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
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|SampleCoverage
parameter_list|(
name|GLfloat
name|value
parameter_list|,
name|GLboolean
name|invert
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Scissor
parameter_list|(
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
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|ShaderBinary
parameter_list|(
name|GLsizei
name|n
parameter_list|,
specifier|const
name|GLuint
modifier|*
name|shaders
parameter_list|,
name|GLenum
name|binaryformat
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|binary
parameter_list|,
name|GLsizei
name|length
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|ShaderSource
parameter_list|(
name|GLuint
name|shader
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|GLchar
modifier|*
specifier|const
modifier|*
name|string
parameter_list|,
specifier|const
name|GLint
modifier|*
name|length
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|StencilFunc
parameter_list|(
name|GLenum
name|func
parameter_list|,
name|GLint
name|ref
parameter_list|,
name|GLuint
name|mask
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|StencilFuncSeparate
parameter_list|(
name|GLenum
name|face
parameter_list|,
name|GLenum
name|func
parameter_list|,
name|GLint
name|ref
parameter_list|,
name|GLuint
name|mask
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|StencilMask
parameter_list|(
name|GLuint
name|mask
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|StencilMaskSeparate
parameter_list|(
name|GLenum
name|face
parameter_list|,
name|GLuint
name|mask
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|StencilOp
parameter_list|(
name|GLenum
name|fail
parameter_list|,
name|GLenum
name|zfail
parameter_list|,
name|GLenum
name|zpass
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|StencilOpSeparate
parameter_list|(
name|GLenum
name|face
parameter_list|,
name|GLenum
name|fail
parameter_list|,
name|GLenum
name|zfail
parameter_list|,
name|GLenum
name|zpass
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|TexImage2D
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLint
name|internalformat
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
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|TexParameterf
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLfloat
name|param
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|TexParameterfv
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|TexParameteri
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
name|GLint
name|param
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|TexParameteriv
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLenum
name|pname
parameter_list|,
specifier|const
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|TexSubImage2D
parameter_list|(
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
specifier|const
name|GLvoid
modifier|*
name|pixels
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform1f
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLfloat
name|x
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform1fv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|v
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform1i
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLint
name|x
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform1iv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|GLint
modifier|*
name|v
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform2f
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLfloat
name|x
parameter_list|,
name|GLfloat
name|y
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform2fv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|v
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform2i
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform2iv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|GLint
modifier|*
name|v
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform3f
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLfloat
name|x
parameter_list|,
name|GLfloat
name|y
parameter_list|,
name|GLfloat
name|z
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform3fv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|v
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform3i
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLint
name|z
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform3iv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|GLint
modifier|*
name|v
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform4f
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLfloat
name|x
parameter_list|,
name|GLfloat
name|y
parameter_list|,
name|GLfloat
name|z
parameter_list|,
name|GLfloat
name|w
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform4fv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|v
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform4i
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLint
name|z
parameter_list|,
name|GLint
name|w
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Uniform4iv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
specifier|const
name|GLint
modifier|*
name|v
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|UniformMatrix2fv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLboolean
name|transpose
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|value
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|UniformMatrix3fv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLboolean
name|transpose
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|value
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|UniformMatrix4fv
parameter_list|(
name|GLint
name|location
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLboolean
name|transpose
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|value
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|UseProgram
parameter_list|(
name|GLuint
name|program
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|ValidateProgram
parameter_list|(
name|GLuint
name|program
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|VertexAttrib1f
parameter_list|(
name|GLuint
name|indx
parameter_list|,
name|GLfloat
name|x
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|VertexAttrib1fv
parameter_list|(
name|GLuint
name|indx
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|values
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|VertexAttrib2f
parameter_list|(
name|GLuint
name|indx
parameter_list|,
name|GLfloat
name|x
parameter_list|,
name|GLfloat
name|y
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|VertexAttrib2fv
parameter_list|(
name|GLuint
name|indx
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|values
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|VertexAttrib3f
parameter_list|(
name|GLuint
name|indx
parameter_list|,
name|GLfloat
name|x
parameter_list|,
name|GLfloat
name|y
parameter_list|,
name|GLfloat
name|z
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|VertexAttrib3fv
parameter_list|(
name|GLuint
name|indx
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|values
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|VertexAttrib4f
parameter_list|(
name|GLuint
name|indx
parameter_list|,
name|GLfloat
name|x
parameter_list|,
name|GLfloat
name|y
parameter_list|,
name|GLfloat
name|z
parameter_list|,
name|GLfloat
name|w
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|VertexAttrib4fv
parameter_list|(
name|GLuint
name|indx
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|values
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|VertexAttribPointer
parameter_list|(
name|GLuint
name|indx
parameter_list|,
name|GLint
name|size
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLboolean
name|normalized
parameter_list|,
name|GLsizei
name|stride
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|ANGLE_EXPORT
name|void
name|GL_APIENTRY
name|Viewport
parameter_list|(
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
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_ENTRYPOINTGLES20_H_
end_comment
end_unit
