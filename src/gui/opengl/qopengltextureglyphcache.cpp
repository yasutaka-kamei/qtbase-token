begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QFontEngineGlyphCache
operator|::
name|Type
name|type
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|)
member_init_list|:
name|QImageTextureGlyphCache
argument_list|(
name|type
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
operator|delete
name|m_blitProgram
expr_stmt|;
block|}
end_destructor
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
operator|delete
name|m_textureResource
expr_stmt|;
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
name|m_type
operator|==
name|QFontEngineGlyphCache
operator|::
name|Raster_RGBMask
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
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_ALPHA
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
literal|0
argument_list|,
name|GL_ALPHA
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
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexParameterf
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
name|Q_ASSERT
argument_list|(
name|image
argument_list|()
operator|.
name|depth
argument_list|()
operator|==
literal|8
argument_list|)
expr_stmt|;
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|oldHeight
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
argument_list|()
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|oldTexture
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// ### the QTextureGlyphCache API needs to be reworked to allow
comment|// ### resizeTextureData to fail
name|QOpenGLFunctions
name|funcs
argument_list|(
name|ctx
argument_list|)
decl_stmt|;
name|funcs
operator|.
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
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|tmp_texture
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|tmp_texture
argument_list|)
expr_stmt|;
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
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexParameterf
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
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|funcs
operator|.
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
operator|.
name|glActiveTexture
argument_list|(
name|GL_TEXTURE0
operator|+
name|QT_IMAGE_TEXTURE_UNIT
argument_list|)
expr_stmt|;
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
name|glDisable
argument_list|(
name|GL_STENCIL_TEST
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_SCISSOR_TEST
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
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
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
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
block|}
name|funcs
operator|.
name|glVertexAttribPointer
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|m_vertexCoordinateArray
argument_list|)
expr_stmt|;
name|funcs
operator|.
name|glVertexAttribPointer
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|m_textureCoordinateArray
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|bind
argument_list|()
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
name|m_blitProgram
operator|->
name|disableAttributeArray
argument_list|(
name|int
argument_list|(
name|QT_OPACITY_ATTR
argument_list|)
argument_list|)
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
name|glDrawArrays
argument_list|(
name|GL_TRIANGLE_FAN
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
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
operator|.
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
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|tmp_texture
argument_list|)
expr_stmt|;
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|oldTexture
argument_list|)
expr_stmt|;
name|funcs
operator|.
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|current_fbo
argument_list|)
expr_stmt|;
if|if
condition|(
name|pex
operator|!=
literal|0
condition|)
block|{
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
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
specifier|const
name|QImage
modifier|&
name|texture
init|=
name|image
argument_list|()
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|bits
init|=
name|texture
operator|.
name|constBits
argument_list|()
decl_stmt|;
name|bits
operator|+=
name|c
operator|.
name|y
operator|*
name|texture
operator|.
name|bytesPerLine
argument_list|()
operator|+
name|c
operator|.
name|x
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|c
operator|.
name|h
condition|;
operator|++
name|i
control|)
block|{
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
operator|+
name|i
argument_list|,
name|c
operator|.
name|w
argument_list|,
literal|1
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|bits
argument_list|)
expr_stmt|;
name|bits
operator|+=
name|texture
operator|.
name|bytesPerLine
argument_list|()
expr_stmt|;
block|}
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
specifier|const
name|int
name|maskWidth
init|=
name|mask
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|maskHeight
init|=
name|mask
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|mask
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_Mono
condition|)
block|{
name|mask
operator|=
name|mask
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_Indexed8
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|maskHeight
condition|;
operator|++
name|y
control|)
block|{
name|uchar
modifier|*
name|src
init|=
operator|(
name|uchar
operator|*
operator|)
name|mask
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
name|maskWidth
condition|;
operator|++
name|x
control|)
name|src
index|[
name|x
index|]
operator|=
operator|-
name|src
index|[
name|x
index|]
expr_stmt|;
comment|// convert 0 and 1 into 0 and 255
block|}
block|}
elseif|else
if|if
condition|(
name|mask
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_RGB32
condition|)
block|{
comment|// Make the alpha component equal to the average of the RGB values.
comment|// This is needed when drawing sub-pixel antialiased text on translucent targets.
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|maskHeight
condition|;
operator|++
name|y
control|)
block|{
name|quint32
modifier|*
name|src
init|=
operator|(
name|quint32
operator|*
operator|)
name|mask
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
name|maskWidth
condition|;
operator|++
name|x
control|)
block|{
name|uchar
name|r
init|=
name|src
index|[
name|x
index|]
operator|>>
literal|16
decl_stmt|;
name|uchar
name|g
init|=
name|src
index|[
name|x
index|]
operator|>>
literal|8
decl_stmt|;
name|uchar
name|b
init|=
name|src
index|[
name|x
index|]
decl_stmt|;
name|quint32
name|avg
init|=
operator|(
name|quint32
argument_list|(
name|r
argument_list|)
operator|+
name|quint32
argument_list|(
name|g
argument_list|)
operator|+
name|quint32
argument_list|(
name|b
argument_list|)
operator|+
literal|1
operator|)
operator|/
literal|3
decl_stmt|;
comment|// "+1" for rounding.
name|src
index|[
name|x
index|]
operator|=
operator|(
name|src
index|[
name|x
index|]
operator|&
literal|0x00ffffff
operator|)
operator||
operator|(
name|avg
operator|<<
literal|24
operator|)
expr_stmt|;
block|}
block|}
block|}
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
if|if
condition|(
name|mask
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_RGB32
condition|)
block|{
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
argument_list|,
name|maskWidth
argument_list|,
name|maskHeight
argument_list|,
name|GL_BGRA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|mask
operator|.
name|bits
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// glTexSubImage2D() might cause some garbage to appear in the texture if the mask width is
comment|// not a multiple of four bytes. The bug appeared on a computer with 32-bit Windows Vista
comment|// and nVidia GeForce 8500GT. GL_UNPACK_ALIGNMENT is set to four bytes, 'mask' has a
comment|// multiple of four bytes per line, and most of the glyph shows up correctly in the
comment|// texture, which makes me think that this is a driver bug.
comment|// One workaround is to make sure the mask width is a multiple of four bytes, for instance
comment|// by converting it to a format with four bytes per pixel. Another is to copy one line at a
comment|// time.
if|#
directive|if
literal|0
block|if (!ctx->d_func()->workaround_brokenAlphaTexSubImage_init) {
comment|// don't know which driver versions exhibit this bug, so be conservative for now
block|const QByteArray versionString(reinterpret_cast<const char*>(glGetString(GL_VERSION)));             glctx->d_func()->workaround_brokenAlphaTexSubImage = versionString.indexOf("NVIDIA")>= 0;             glctx->d_func()->workaround_brokenAlphaTexSubImage_init = true;         }
endif|#
directive|endif
if|#
directive|if
literal|0
block|if (ctx->d_func()->workaround_brokenAlphaTexSubImage) {             for (int i = 0; i< maskHeight; ++i)                 glTexSubImage2D(GL_TEXTURE_2D, 0, c.x, c.y + i, maskWidth, 1, GL_ALPHA, GL_UNSIGNED_BYTE, mask.scanLine(i));         } else {
endif|#
directive|endif
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
argument_list|,
name|maskWidth
argument_list|,
name|maskHeight
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|mask
operator|.
name|bits
argument_list|()
argument_list|)
expr_stmt|;
comment|//        }
block|}
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
name|m_textureResource
operator|->
name|free
argument_list|()
expr_stmt|;
name|m_textureResource
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
