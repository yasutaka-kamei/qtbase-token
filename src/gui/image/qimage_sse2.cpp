begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qimage.h"
end_include
begin_include
include|#
directive|include
file|<private/qimage_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qsimd_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdrawhelper_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdrawingprimitive_sse2_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_COMPILER_SUPPORTS_SSE2
end_ifdef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|convert_ARGB_to_ARGB_PM_inplace_sse2
name|bool
name|convert_ARGB_to_ARGB_PM_inplace_sse2
parameter_list|(
name|QImageData
modifier|*
name|data
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|data
operator|->
name|format
operator|==
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
expr_stmt|;
comment|// extra pixels on each line
specifier|const
name|int
name|spare
init|=
name|data
operator|->
name|width
operator|&
literal|3
decl_stmt|;
comment|// width in pixels of the pad at the end of each line
specifier|const
name|int
name|pad
init|=
operator|(
name|data
operator|->
name|bytes_per_line
operator|>>
literal|2
operator|)
operator|-
name|data
operator|->
name|width
decl_stmt|;
specifier|const
name|int
name|iter
init|=
name|data
operator|->
name|width
operator|>>
literal|2
decl_stmt|;
name|int
name|height
init|=
name|data
operator|->
name|height
decl_stmt|;
specifier|const
name|__m128i
name|alphaMask
init|=
name|_mm_set1_epi32
argument_list|(
literal|0xff000000
argument_list|)
decl_stmt|;
specifier|const
name|__m128i
name|nullVector
init|=
name|_mm_setzero_si128
argument_list|()
decl_stmt|;
specifier|const
name|__m128i
name|half
init|=
name|_mm_set1_epi16
argument_list|(
literal|0x80
argument_list|)
decl_stmt|;
specifier|const
name|__m128i
name|colorMask
init|=
name|_mm_set1_epi32
argument_list|(
literal|0x00ff00ff
argument_list|)
decl_stmt|;
name|__m128i
modifier|*
name|d
init|=
cast|reinterpret_cast
argument_list|<
name|__m128i
operator|*
argument_list|>
argument_list|(
name|data
operator|->
name|data
argument_list|)
decl_stmt|;
while|while
condition|(
name|height
operator|--
condition|)
block|{
specifier|const
name|__m128i
modifier|*
name|end
init|=
name|d
operator|+
name|iter
decl_stmt|;
for|for
control|(
init|;
name|d
operator|!=
name|end
condition|;
operator|++
name|d
control|)
block|{
specifier|const
name|__m128i
name|srcVector
init|=
name|_mm_loadu_si128
argument_list|(
name|d
argument_list|)
decl_stmt|;
specifier|const
name|__m128i
name|srcVectorAlpha
init|=
name|_mm_and_si128
argument_list|(
name|srcVector
argument_list|,
name|alphaMask
argument_list|)
decl_stmt|;
if|if
condition|(
name|_mm_movemask_epi8
argument_list|(
name|_mm_cmpeq_epi32
argument_list|(
name|srcVectorAlpha
argument_list|,
name|alphaMask
argument_list|)
argument_list|)
operator|==
literal|0xffff
condition|)
block|{
comment|// opaque, data is unchanged
block|}
elseif|else
if|if
condition|(
name|_mm_movemask_epi8
argument_list|(
name|_mm_cmpeq_epi32
argument_list|(
name|srcVectorAlpha
argument_list|,
name|nullVector
argument_list|)
argument_list|)
operator|==
literal|0xffff
condition|)
block|{
comment|// fully transparent
name|_mm_storeu_si128
argument_list|(
name|d
argument_list|,
name|nullVector
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|__m128i
name|alphaChannel
init|=
name|_mm_srli_epi32
argument_list|(
name|srcVector
argument_list|,
literal|24
argument_list|)
decl_stmt|;
name|alphaChannel
operator|=
name|_mm_or_si128
argument_list|(
name|alphaChannel
argument_list|,
name|_mm_slli_epi32
argument_list|(
name|alphaChannel
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
name|__m128i
name|result
decl_stmt|;
name|BYTE_MUL_SSE2
argument_list|(
name|result
argument_list|,
name|srcVector
argument_list|,
name|alphaChannel
argument_list|,
name|colorMask
argument_list|,
name|half
argument_list|)
expr_stmt|;
name|result
operator|=
name|_mm_or_si128
argument_list|(
name|_mm_andnot_si128
argument_list|(
name|alphaMask
argument_list|,
name|result
argument_list|)
argument_list|,
name|srcVectorAlpha
argument_list|)
expr_stmt|;
name|_mm_storeu_si128
argument_list|(
name|d
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
block|}
name|QRgb
modifier|*
name|p
init|=
cast|reinterpret_cast
argument_list|<
name|QRgb
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|QRgb
modifier|*
name|pe
init|=
name|p
operator|+
name|spare
decl_stmt|;
for|for
control|(
init|;
name|p
operator|!=
name|pe
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
operator|*
name|p
operator|<
literal|0x00ffffff
condition|)
operator|*
name|p
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|p
operator|<
literal|0xff000000
condition|)
operator|*
name|p
operator|=
name|qPremultiply
argument_list|(
operator|*
name|p
argument_list|)
expr_stmt|;
block|}
name|d
operator|=
cast|reinterpret_cast
argument_list|<
name|__m128i
operator|*
argument_list|>
argument_list|(
name|p
operator|+
name|pad
argument_list|)
expr_stmt|;
block|}
name|data
operator|->
name|format
operator|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_COMPILER_SUPPORTS_SSE2
end_comment
end_unit
