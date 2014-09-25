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
comment|// TextureImpl.h: Defines the abstract rx::TextureImpl classes.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_TEXTUREIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_TEXTUREIMPL_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_TEXTUREIMPL_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/ImageIndex.h"
end_include
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|Surface
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Framebuffer
decl_stmt|;
struct_decl|struct
name|PixelUnpackState
struct_decl|;
struct_decl|struct
name|SamplerState
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Image
decl_stmt|;
name|class
name|Renderer
decl_stmt|;
name|class
name|TextureStorage
decl_stmt|;
name|class
name|TextureImpl
block|{
name|public
label|:
name|virtual
operator|~
name|TextureImpl
argument_list|()
block|{}
expr_stmt|;
comment|// TODO: If this methods could go away that would be ideal;
comment|// TextureStorage should only be necessary for the D3D backend, and as such
comment|// higher level code should not rely on it.
name|virtual
name|TextureStorage
modifier|*
name|getNativeTexture
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Deprecated in favour of the ImageIndex method
name|virtual
name|Image
modifier|*
name|getImage
argument_list|(
name|int
name|level
argument_list|,
name|int
name|layer
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|Image
modifier|*
name|getImage
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|GLsizei
name|getLayerCount
argument_list|(
name|int
name|level
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|setUsage
parameter_list|(
name|GLenum
name|usage
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|setImage
argument_list|(
name|GLenum
name|target
argument_list|,
name|GLint
name|level
argument_list|,
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|GLsizei
name|depth
argument_list|,
name|GLenum
name|internalFormat
argument_list|,
name|GLenum
name|format
argument_list|,
name|GLenum
name|type
argument_list|,
specifier|const
name|gl
operator|::
name|PixelUnpackState
operator|&
name|unpack
argument_list|,
specifier|const
name|void
operator|*
name|pixels
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|setCompressedImage
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLenum
name|format
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
name|GLsizei
name|imageSize
parameter_list|,
specifier|const
name|void
modifier|*
name|pixels
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|subImage
argument_list|(
name|GLenum
name|target
argument_list|,
name|GLint
name|level
argument_list|,
name|GLint
name|xoffset
argument_list|,
name|GLint
name|yoffset
argument_list|,
name|GLint
name|zoffset
argument_list|,
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|GLsizei
name|depth
argument_list|,
name|GLenum
name|format
argument_list|,
name|GLenum
name|type
argument_list|,
specifier|const
name|gl
operator|::
name|PixelUnpackState
operator|&
name|unpack
argument_list|,
specifier|const
name|void
operator|*
name|pixels
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|subImageCompressed
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
name|zoffset
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
name|GLenum
name|format
parameter_list|,
name|GLsizei
name|imageSize
parameter_list|,
specifier|const
name|void
modifier|*
name|pixels
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|copyImage
argument_list|(
name|GLenum
name|target
argument_list|,
name|GLint
name|level
argument_list|,
name|GLenum
name|format
argument_list|,
name|GLint
name|x
argument_list|,
name|GLint
name|y
argument_list|,
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|gl
operator|::
name|Framebuffer
operator|*
name|source
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|copySubImage
argument_list|(
name|GLenum
name|target
argument_list|,
name|GLint
name|level
argument_list|,
name|GLint
name|xoffset
argument_list|,
name|GLint
name|yoffset
argument_list|,
name|GLint
name|zoffset
argument_list|,
name|GLint
name|x
argument_list|,
name|GLint
name|y
argument_list|,
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|gl
operator|::
name|Framebuffer
operator|*
name|source
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|storage
parameter_list|(
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
parameter_list|,
name|GLsizei
name|depth
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|generateMipmaps
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|bindTexImage
argument_list|(
name|egl
operator|::
name|Surface
operator|*
name|surface
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|releaseTexImage
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_TEXTUREIMPL_H_
end_comment
end_unit
