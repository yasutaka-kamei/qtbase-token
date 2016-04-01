begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopengltextureglyphcache_p.h"
end_include
begin_include
include|#
directive|include
file|"qopenglpaintengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qopenglengineshadersource_p.h"
end_include
begin_include
include|#
directive|include
file|"qopenglextensions_p.h"
end_include
begin_include
include|#
directive|include
file|<qrgb.h>
end_include
begin_include
include|#
directive|include
file|<private/qdrawhelper_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|qopengltextureglyphcache_serial_number
name|QBasicAtomicInt
name|qopengltextureglyphcache_serial_number
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QOpenGLTextureGlyphCache
name|QOpenGLTextureGlyphCache
operator|::
name|QOpenGLTextureGlyphCache
parameter_list|(
name|QFontEngine
operator|::
name|GlyphFormat
name|format
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|)
member_init_list|:
name|QImageTextureGlyphCache
argument_list|(
name|format
argument_list|,
name|matrix
argument_list|)
member_init_list|,
name|m_textureResource
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|pex
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_blitProgram
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_filterMode
argument_list|(
name|Nearest
argument_list|)
member_init_list|,
name|m_serialNumber
argument_list|(
name|qopengltextureglyphcache_serial_number
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
argument_list|)
member_init_list|,
name|m_buffer
argument_list|(
name|QOpenGLBuffer
operator|::
name|VertexBuffer
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_GL_TEXTURE_GLYPH_CACHE_DEBUG
name|qDebug
argument_list|(
literal|" -> QOpenGLTextureGlyphCache() %p for context %p."
argument_list|,
name|this
argument_list|,
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_vertexCoordinateArray
index|[
literal|0
index|]
operator|=
operator|-
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|1
index|]
operator|=
operator|-
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|2
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|3
index|]
operator|=
operator|-
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|4
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|5
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|6
index|]
operator|=
operator|-
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|7
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|0
index|]
operator|=
literal|0.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|1
index|]
operator|=
literal|0.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|2
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|3
index|]
operator|=
literal|0.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|4
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|5
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|6
index|]
operator|=
literal|0.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|7
index|]
operator|=
literal|1.0f
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QOpenGLTextureGlyphCache
name|QOpenGLTextureGlyphCache
operator|::
name|~
name|QOpenGLTextureGlyphCache
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_GL_TEXTURE_GLYPH_CACHE_DEBUG
name|qDebug
argument_list|(
literal|" -> ~QOpenGLTextureGlyphCache() %p."
argument_list|,
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_function
DECL|function|isCoreProfile
specifier|static
specifier|inline
name|bool
name|isCoreProfile
parameter_list|()
block|{
return|return
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|format
argument_list|()
operator|.
name|profile
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|CoreProfile
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|createTextureData
name|void
name|QOpenGLTextureGlyphCache
operator|::
name|createTextureData
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QOpenGLContext
modifier|*
name|ctx
init|=
cast|const_cast
argument_list|<
name|QOpenGLContext
operator|*
argument_list|>
argument_list|(
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QOpenGLTextureGlyphCache::createTextureData: Called with no context"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// create in QImageTextureGlyphCache baseclass is meant to be called
comment|// only to create the initial image and does not preserve the content,
comment|// so we don't call when this function is called from resize.
if|if
condition|(
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|workaround_brokenFBOReadBack
operator|&&
name|image
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
name|QImageTextureGlyphCache
operator|::
name|createTextureData
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
comment|// Make the lower glyph texture size 16 x 16.
if|if
condition|(
name|width
operator|<
literal|16
condition|)
name|width
operator|=
literal|16
expr_stmt|;
if|if
condition|(
name|height
operator|<
literal|16
condition|)
name|height
operator|=
literal|16
expr_stmt|;
if|if
condition|(
name|m_textureResource
operator|&&
operator|!
name|m_textureResource
operator|->
name|m_texture
condition|)
block|{
operator|delete
name|m_textureResource
expr_stmt|;
name|m_textureResource
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_textureResource
condition|)
name|m_textureResource
operator|=
operator|new
name|QOpenGLGlyphTexture
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|QOpenGLFunctions
modifier|*
name|funcs
init|=
name|ctx
operator|->
name|functions
argument_list|()
decl_stmt|;
name|funcs
operator|->
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
name|m_textureResource
operator|->
name|m_width
operator|=
name|width
expr_stmt|;
name|m_textureResource
operator|->
name|m_height
operator|=
name|height
expr_stmt|;
if|if
condition|(
name|m_format
operator|==
name|QFontEngine
operator|::
name|Format_A32
operator|||
name|m_format
operator|==
name|QFontEngine
operator|::
name|Format_ARGB
condition|)
block|{
name|QVarLengthArray
argument_list|<
name|uchar
argument_list|>
name|data
argument_list|(
name|width
operator|*
name|height
operator|*
literal|4
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|data
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|data
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|funcs
operator|->
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
operator|&
name|data
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QVarLengthArray
argument_list|<
name|uchar
argument_list|>
name|data
argument_list|(
name|width
operator|*
name|height
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|data
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|data
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
specifier|const
name|GLint
name|internalFormat
init|=
name|isCoreProfile
argument_list|()
condition|?
name|GL_R8
else|:
name|GL_ALPHA
decl_stmt|;
specifier|const
name|GLenum
name|format
init|=
name|isCoreProfile
argument_list|()
condition|?
name|GL_RED
else|:
name|GL_ALPHA
decl_stmt|;
else|#
directive|else
specifier|const
name|GLint
name|internalFormat
init|=
name|GL_ALPHA
decl_stmt|;
specifier|const
name|GLenum
name|format
init|=
name|GL_ALPHA
decl_stmt|;
endif|#
directive|endif
name|funcs
operator|->
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|internalFormat
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
literal|0
argument_list|,
name|format
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
operator|&
name|data
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|m_filterMode
operator|=
name|Nearest
expr_stmt|;
if|if
condition|(
operator|!
name|m_buffer
operator|.
name|isCreated
argument_list|()
condition|)
block|{
name|m_buffer
operator|.
name|create
argument_list|()
expr_stmt|;
name|m_buffer
operator|.
name|bind
argument_list|()
expr_stmt|;
specifier|static
name|GLfloat
name|buf
index|[
sizeof|sizeof
argument_list|(
name|m_vertexCoordinateArray
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|m_textureCoordinateArray
argument_list|)
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|buf
argument_list|,
name|m_vertexCoordinateArray
argument_list|,
sizeof|sizeof
argument_list|(
name|m_vertexCoordinateArray
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|buf
operator|+
operator|(
sizeof|sizeof
argument_list|(
name|m_vertexCoordinateArray
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
operator|)
argument_list|,
name|m_textureCoordinateArray
argument_list|,
sizeof|sizeof
argument_list|(
name|m_textureCoordinateArray
argument_list|)
argument_list|)
expr_stmt|;
name|m_buffer
operator|.
name|allocate
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
name|m_buffer
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_vao
operator|.
name|isCreated
argument_list|()
condition|)
name|m_vao
operator|.
name|create
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupVertexAttribs
name|void
name|QOpenGLTextureGlyphCache
operator|::
name|setupVertexAttribs
parameter_list|()
block|{
name|m_buffer
operator|.
name|bind
argument_list|()
expr_stmt|;
name|m_blitProgram
operator|->
name|setAttributeBuffer
argument_list|(
name|int
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|)
argument_list|,
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|setAttributeBuffer
argument_list|(
name|int
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|)
argument_list|,
name|GL_FLOAT
argument_list|,
sizeof|sizeof
argument_list|(
name|m_vertexCoordinateArray
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|enableAttributeArray
argument_list|(
name|int
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|)
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|enableAttributeArray
argument_list|(
name|int
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|)
argument_list|)
expr_stmt|;
name|m_buffer
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|load_glyph_image_to_texture
specifier|static
name|void
name|load_glyph_image_to_texture
parameter_list|(
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|,
name|QImage
modifier|&
name|img
parameter_list|,
name|GLuint
name|texture
parameter_list|,
name|int
name|tx
parameter_list|,
name|int
name|ty
parameter_list|)
block|{
name|QOpenGLFunctions
modifier|*
name|funcs
init|=
name|ctx
operator|->
name|functions
argument_list|()
decl_stmt|;
specifier|const
name|int
name|imgWidth
init|=
name|img
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|imgHeight
init|=
name|img
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|img
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_Mono
condition|)
block|{
name|img
operator|=
name|img
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_Grayscale8
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|img
operator|.
name|depth
argument_list|()
operator|==
literal|32
condition|)
block|{
if|if
condition|(
name|img
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_RGB32
comment|// We need to make the alpha component equal to the average of the RGB values.
comment|// This is needed when drawing sub-pixel antialiased text on translucent targets.
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
operator|||
name|img
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
else|#
directive|else
operator|||
operator|(
name|img
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
operator|&&
name|ctx
operator|->
name|isOpenGLES
argument_list|()
operator|)
endif|#
directive|endif
condition|)
block|{
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|imgHeight
condition|;
operator|++
name|y
control|)
block|{
name|QRgb
modifier|*
name|src
init|=
operator|(
name|QRgb
operator|*
operator|)
name|img
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|imgWidth
condition|;
operator|++
name|x
control|)
block|{
name|int
name|r
init|=
name|qRed
argument_list|(
name|src
index|[
name|x
index|]
argument_list|)
decl_stmt|;
name|int
name|g
init|=
name|qGreen
argument_list|(
name|src
index|[
name|x
index|]
argument_list|)
decl_stmt|;
name|int
name|b
init|=
name|qBlue
argument_list|(
name|src
index|[
name|x
index|]
argument_list|)
decl_stmt|;
name|int
name|avg
decl_stmt|;
if|if
condition|(
name|img
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_RGB32
condition|)
name|avg
operator|=
operator|(
name|r
operator|+
name|g
operator|+
name|b
operator|+
literal|1
operator|)
operator|/
literal|3
expr_stmt|;
comment|// "+1" for rounding.
else|else
comment|// Format_ARGB_Premultiplied
name|avg
operator|=
name|qAlpha
argument_list|(
name|src
index|[
name|x
index|]
argument_list|)
expr_stmt|;
name|src
index|[
name|x
index|]
operator|=
name|qRgba
argument_list|(
name|r
argument_list|,
name|g
argument_list|,
name|b
argument_list|,
name|avg
argument_list|)
expr_stmt|;
comment|// swizzle the bits to accommodate for the GL_RGBA upload.
if|#
directive|if
name|Q_BYTE_ORDER
operator|!=
name|Q_BIG_ENDIAN
if|if
condition|(
name|ctx
operator|->
name|isOpenGLES
argument_list|()
condition|)
endif|#
directive|endif
name|src
index|[
name|x
index|]
operator|=
name|ARGB2RGBA
argument_list|(
name|src
index|[
name|x
index|]
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|texture
argument_list|)
expr_stmt|;
if|if
condition|(
name|img
operator|.
name|depth
argument_list|()
operator|==
literal|32
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
name|GLenum
name|fmt
init|=
name|GL_RGBA
decl_stmt|;
else|#
directive|else
name|GLenum
name|fmt
init|=
name|ctx
operator|->
name|isOpenGLES
argument_list|()
condition|?
name|GL_RGBA
else|:
name|GL_BGRA
decl_stmt|;
endif|#
directive|endif
comment|// QT_OPENGL_ES_2
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
name|fmt
operator|=
name|GL_RGBA
expr_stmt|;
endif|#
directive|endif
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|tx
argument_list|,
name|ty
argument_list|,
name|imgWidth
argument_list|,
name|imgHeight
argument_list|,
name|fmt
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|img
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// The scanlines in image are 32-bit aligned, even for mono or 8-bit formats. This
comment|// is good because it matches the default of 4 bytes for GL_UNPACK_ALIGNMENT.
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
specifier|const
name|GLenum
name|format
init|=
name|isCoreProfile
argument_list|()
condition|?
name|GL_RED
else|:
name|GL_ALPHA
decl_stmt|;
else|#
directive|else
specifier|const
name|GLenum
name|format
init|=
name|GL_ALPHA
decl_stmt|;
endif|#
directive|endif
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|tx
argument_list|,
name|ty
argument_list|,
name|imgWidth
argument_list|,
name|imgHeight
argument_list|,
name|format
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|img
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|load_glyph_image_region_to_texture
specifier|static
name|void
name|load_glyph_image_region_to_texture
parameter_list|(
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|,
specifier|const
name|QImage
modifier|&
name|srcImg
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|GLuint
name|texture
parameter_list|,
name|int
name|tx
parameter_list|,
name|int
name|ty
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|x
operator|+
name|w
operator|<=
name|srcImg
operator|.
name|width
argument_list|()
operator|&&
name|y
operator|+
name|h
operator|<=
name|srcImg
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QImage
name|img
decl_stmt|;
if|if
condition|(
name|x
operator|!=
literal|0
operator|||
name|y
operator|!=
literal|0
operator|||
name|w
operator|!=
name|srcImg
operator|.
name|width
argument_list|()
operator|||
name|h
operator|!=
name|srcImg
operator|.
name|height
argument_list|()
condition|)
name|img
operator|=
name|srcImg
operator|.
name|copy
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
else|else
name|img
operator|=
name|srcImg
expr_stmt|;
name|load_glyph_image_to_texture
argument_list|(
name|ctx
argument_list|,
name|img
argument_list|,
name|texture
argument_list|,
name|tx
argument_list|,
name|ty
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeTextureData
name|void
name|QOpenGLTextureGlyphCache
operator|::
name|resizeTextureData
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QOpenGLContext
modifier|*
name|ctx
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QOpenGLTextureGlyphCache::resizeTextureData: Called with no context"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QOpenGLFunctions
modifier|*
name|funcs
init|=
name|ctx
operator|->
name|functions
argument_list|()
decl_stmt|;
name|GLint
name|oldFbo
decl_stmt|;
name|funcs
operator|->
name|glGetIntegerv
argument_list|(
name|GL_FRAMEBUFFER_BINDING
argument_list|,
operator|&
name|oldFbo
argument_list|)
expr_stmt|;
name|int
name|oldWidth
init|=
name|m_textureResource
operator|->
name|m_width
decl_stmt|;
name|int
name|oldHeight
init|=
name|m_textureResource
operator|->
name|m_height
decl_stmt|;
comment|// Make the lower glyph texture size 16 x 16.
if|if
condition|(
name|width
operator|<
literal|16
condition|)
name|width
operator|=
literal|16
expr_stmt|;
if|if
condition|(
name|height
operator|<
literal|16
condition|)
name|height
operator|=
literal|16
expr_stmt|;
name|GLuint
name|oldTexture
init|=
name|m_textureResource
operator|->
name|m_texture
decl_stmt|;
name|createTextureData
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|workaround_brokenFBOReadBack
condition|)
block|{
name|QImageTextureGlyphCache
operator|::
name|resizeTextureData
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
name|load_glyph_image_region_to_texture
argument_list|(
name|ctx
argument_list|,
name|image
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|qMin
argument_list|(
name|oldWidth
argument_list|,
name|width
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|oldHeight
argument_list|,
name|height
argument_list|)
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// ### the QTextureGlyphCache API needs to be reworked to allow
comment|// ### resizeTextureData to fail
name|funcs
operator|->
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|m_textureResource
operator|->
name|m_fbo
argument_list|)
expr_stmt|;
name|GLuint
name|tmp_texture
decl_stmt|;
name|funcs
operator|->
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|tmp_texture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|tmp_texture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|oldWidth
argument_list|,
name|oldHeight
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|m_filterMode
operator|=
name|Nearest
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glFramebufferTexture2D
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_COLOR_ATTACHMENT0
argument_list|,
name|GL_TEXTURE_2D
argument_list|,
name|tmp_texture
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glActiveTexture
argument_list|(
name|GL_TEXTURE0
operator|+
name|QT_IMAGE_TEXTURE_UNIT
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|oldTexture
argument_list|)
expr_stmt|;
if|if
condition|(
name|pex
operator|!=
literal|0
condition|)
name|pex
operator|->
name|transferMode
argument_list|(
name|BrushDrawingMode
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDisable
argument_list|(
name|GL_STENCIL_TEST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDisable
argument_list|(
name|GL_SCISSOR_TEST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|oldWidth
argument_list|,
name|oldHeight
argument_list|)
expr_stmt|;
name|QOpenGLShaderProgram
modifier|*
name|blitProgram
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|pex
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|m_blitProgram
operator|==
literal|0
condition|)
block|{
name|m_blitProgram
operator|=
operator|new
name|QOpenGLShaderProgram
expr_stmt|;
specifier|const
name|bool
name|isCoreProfile
init|=
name|ctx
operator|->
name|format
argument_list|()
operator|.
name|profile
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|CoreProfile
decl_stmt|;
block|{
name|QString
name|source
decl_stmt|;
name|source
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
name|isCoreProfile
condition|?
name|qopenglslMainWithTexCoordsVertexShader_core
else|:
name|qopenglslMainWithTexCoordsVertexShader
argument_list|)
argument_list|)
expr_stmt|;
name|source
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
name|isCoreProfile
condition|?
name|qopenglslUntransformedPositionVertexShader_core
else|:
name|qopenglslUntransformedPositionVertexShader
argument_list|)
argument_list|)
expr_stmt|;
name|QOpenGLShader
modifier|*
name|vertexShader
init|=
operator|new
name|QOpenGLShader
argument_list|(
name|QOpenGLShader
operator|::
name|Vertex
argument_list|,
name|m_blitProgram
argument_list|)
decl_stmt|;
name|vertexShader
operator|->
name|compileSourceCode
argument_list|(
name|source
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|addShader
argument_list|(
name|vertexShader
argument_list|)
expr_stmt|;
block|}
block|{
name|QString
name|source
decl_stmt|;
name|source
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
name|isCoreProfile
condition|?
name|qopenglslMainFragmentShader_core
else|:
name|qopenglslMainFragmentShader
argument_list|)
argument_list|)
expr_stmt|;
name|source
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
name|isCoreProfile
condition|?
name|qopenglslImageSrcFragmentShader_core
else|:
name|qopenglslImageSrcFragmentShader
argument_list|)
argument_list|)
expr_stmt|;
name|QOpenGLShader
modifier|*
name|fragmentShader
init|=
operator|new
name|QOpenGLShader
argument_list|(
name|QOpenGLShader
operator|::
name|Fragment
argument_list|,
name|m_blitProgram
argument_list|)
decl_stmt|;
name|fragmentShader
operator|->
name|compileSourceCode
argument_list|(
name|source
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|addShader
argument_list|(
name|fragmentShader
argument_list|)
expr_stmt|;
block|}
name|m_blitProgram
operator|->
name|bindAttributeLocation
argument_list|(
literal|"vertexCoordsArray"
argument_list|,
name|QT_VERTEX_COORDS_ATTR
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|bindAttributeLocation
argument_list|(
literal|"textureCoordArray"
argument_list|,
name|QT_TEXTURE_COORDS_ATTR
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|link
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_vao
operator|.
name|isCreated
argument_list|()
condition|)
block|{
name|m_vao
operator|.
name|bind
argument_list|()
expr_stmt|;
name|setupVertexAttribs
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_vao
operator|.
name|isCreated
argument_list|()
condition|)
name|m_vao
operator|.
name|bind
argument_list|()
expr_stmt|;
else|else
name|setupVertexAttribs
argument_list|()
expr_stmt|;
name|m_blitProgram
operator|->
name|bind
argument_list|()
expr_stmt|;
name|blitProgram
operator|=
name|m_blitProgram
expr_stmt|;
block|}
else|else
block|{
name|pex
operator|->
name|setVertexAttributePointer
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|,
name|m_vertexCoordinateArray
argument_list|)
expr_stmt|;
name|pex
operator|->
name|setVertexAttributePointer
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|,
name|m_textureCoordinateArray
argument_list|)
expr_stmt|;
name|pex
operator|->
name|shaderManager
operator|->
name|useBlitProgram
argument_list|()
expr_stmt|;
name|blitProgram
operator|=
name|pex
operator|->
name|shaderManager
operator|->
name|blitProgram
argument_list|()
expr_stmt|;
block|}
name|blitProgram
operator|->
name|setUniformValue
argument_list|(
literal|"imageTexture"
argument_list|,
name|QT_IMAGE_TEXTURE_UNIT
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDrawArrays
argument_list|(
name|GL_TRIANGLE_FAN
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glCopyTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|oldWidth
argument_list|,
name|oldHeight
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_COLOR_ATTACHMENT0
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|tmp_texture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|oldTexture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
operator|(
name|GLuint
operator|)
name|oldFbo
argument_list|)
expr_stmt|;
if|if
condition|(
name|pex
operator|!=
literal|0
condition|)
block|{
name|funcs
operator|->
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pex
operator|->
name|width
argument_list|,
name|pex
operator|->
name|height
argument_list|)
expr_stmt|;
name|pex
operator|->
name|updateClipScissorTest
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|m_vao
operator|.
name|isCreated
argument_list|()
condition|)
block|{
name|m_vao
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|m_blitProgram
operator|->
name|disableAttributeArray
argument_list|(
name|int
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|)
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|disableAttributeArray
argument_list|(
name|int
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|fillTexture
name|void
name|QOpenGLTextureGlyphCache
operator|::
name|fillTexture
parameter_list|(
specifier|const
name|Coord
modifier|&
name|c
parameter_list|,
name|glyph_t
name|glyph
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|)
block|{
name|QOpenGLContext
modifier|*
name|ctx
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QOpenGLTextureGlyphCache::fillTexture: Called with no context"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|workaround_brokenFBOReadBack
condition|)
block|{
name|QImageTextureGlyphCache
operator|::
name|fillTexture
argument_list|(
name|c
argument_list|,
name|glyph
argument_list|,
name|subPixelPosition
argument_list|)
expr_stmt|;
name|load_glyph_image_region_to_texture
argument_list|(
name|ctx
argument_list|,
name|image
argument_list|()
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
argument_list|,
name|c
operator|.
name|w
argument_list|,
name|c
operator|.
name|h
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
argument_list|)
expr_stmt|;
return|return;
block|}
name|QImage
name|mask
init|=
name|textureMapForGlyph
argument_list|(
name|glyph
argument_list|,
name|subPixelPosition
argument_list|)
decl_stmt|;
name|load_glyph_image_to_texture
argument_list|(
name|ctx
argument_list|,
name|mask
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|glyphPadding
name|int
name|QOpenGLTextureGlyphCache
operator|::
name|glyphPadding
parameter_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|maxTextureWidth
name|int
name|QOpenGLTextureGlyphCache
operator|::
name|maxTextureWidth
parameter_list|()
specifier|const
block|{
name|QOpenGLContext
modifier|*
name|ctx
init|=
cast|const_cast
argument_list|<
name|QOpenGLContext
operator|*
argument_list|>
argument_list|(
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
literal|0
condition|)
return|return
name|QImageTextureGlyphCache
operator|::
name|maxTextureWidth
argument_list|()
return|;
else|else
return|return
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|maxTextureSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|maxTextureHeight
name|int
name|QOpenGLTextureGlyphCache
operator|::
name|maxTextureHeight
parameter_list|()
specifier|const
block|{
name|QOpenGLContext
modifier|*
name|ctx
init|=
cast|const_cast
argument_list|<
name|QOpenGLContext
operator|*
argument_list|>
argument_list|(
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
literal|0
condition|)
return|return
name|QImageTextureGlyphCache
operator|::
name|maxTextureHeight
argument_list|()
return|;
if|if
condition|(
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|workaround_brokenTexSubImage
condition|)
return|return
name|qMin
argument_list|(
literal|1024
argument_list|,
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|maxTextureSize
argument_list|()
argument_list|)
return|;
else|else
return|return
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|maxTextureSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|QOpenGLTextureGlyphCache
operator|::
name|clear
parameter_list|()
block|{
if|if
condition|(
name|m_textureResource
condition|)
name|m_textureResource
operator|->
name|free
argument_list|()
expr_stmt|;
name|m_textureResource
operator|=
literal|0
expr_stmt|;
operator|delete
name|m_blitProgram
expr_stmt|;
name|m_blitProgram
operator|=
literal|0
expr_stmt|;
name|m_w
operator|=
literal|0
expr_stmt|;
name|m_h
operator|=
literal|0
expr_stmt|;
name|m_cx
operator|=
literal|0
expr_stmt|;
name|m_cy
operator|=
literal|0
expr_stmt|;
name|m_currentRowHeight
operator|=
literal|0
expr_stmt|;
name|coords
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
