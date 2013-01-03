begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qdrawhelper_x86_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_COMPILER_SUPPORTS_SSSE3
end_ifdef
begin_include
include|#
directive|include
file|<private/qdrawingprimitive_sse2_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|blend_pixel
specifier|inline
specifier|static
name|void
name|blend_pixel
parameter_list|(
name|quint32
modifier|&
name|dst
parameter_list|,
specifier|const
name|quint32
name|src
parameter_list|)
block|{
if|if
condition|(
name|src
operator|>=
literal|0xff000000
condition|)
name|dst
operator|=
name|src
expr_stmt|;
elseif|else
if|if
condition|(
name|src
operator|!=
literal|0
condition|)
name|dst
operator|=
name|src
operator|+
name|BYTE_MUL
argument_list|(
name|dst
argument_list|,
name|qAlpha
argument_list|(
operator|~
name|src
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/* The instruction palignr uses direct arguments, so we have to generate the code fo the different    shift (4, 8, 12). Checking the alignment inside the loop is unfortunatelly way too slow.  */
end_comment
begin_define
DECL|macro|BLENDING_LOOP
define|#
directive|define
name|BLENDING_LOOP
parameter_list|(
name|palignrOffset
parameter_list|,
name|length
parameter_list|)
define|\
value|for (; x-minusOffsetToAlignSrcOn16Bytes< length-7; x += 4) { \         const __m128i srcVectorLastLoaded = _mm_load_si128((__m128i *)&src[x - minusOffsetToAlignSrcOn16Bytes + 4]);\         const __m128i srcVector = _mm_alignr_epi8(srcVectorLastLoaded, srcVectorPrevLoaded, palignrOffset); \         const __m128i srcVectorAlpha = _mm_and_si128(srcVector, alphaMask); \         if (_mm_movemask_epi8(_mm_cmpeq_epi32(srcVectorAlpha, alphaMask)) == 0xffff) { \             _mm_store_si128((__m128i *)&dst[x], srcVector); \         } else if (_mm_movemask_epi8(_mm_cmpeq_epi32(srcVectorAlpha, nullVector)) != 0xffff) { \             __m128i alphaChannel = _mm_shuffle_epi8(srcVector, alphaShuffleMask); \             alphaChannel = _mm_sub_epi16(one, alphaChannel); \             const __m128i dstVector = _mm_load_si128((__m128i *)&dst[x]); \             __m128i destMultipliedByOneMinusAlpha; \             BYTE_MUL_SSE2(destMultipliedByOneMinusAlpha, dstVector, alphaChannel, colorMask, half); \             const __m128i result = _mm_add_epi8(srcVector, destMultipliedByOneMinusAlpha); \             _mm_store_si128((__m128i *)&dst[x], result); \         } \         srcVectorPrevLoaded = srcVectorLastLoaded;\     }
end_define
begin_comment
comment|// Basically blend src over dst with the const alpha defined as constAlphaVector.
end_comment
begin_comment
comment|// nullVector, half, one, colorMask are constant across the whole image/texture, and should be defined as:
end_comment
begin_comment
comment|//const __m128i nullVector = _mm_set1_epi32(0);
end_comment
begin_comment
comment|//const __m128i half = _mm_set1_epi16(0x80);
end_comment
begin_comment
comment|//const __m128i one = _mm_set1_epi16(0xff);
end_comment
begin_comment
comment|//const __m128i colorMask = _mm_set1_epi32(0x00ff00ff);
end_comment
begin_comment
comment|//const __m128i alphaMask = _mm_set1_epi32(0xff000000);
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// The computation being done is:
end_comment
begin_comment
comment|// result = s + d * (1-alpha)
end_comment
begin_comment
comment|// with shortcuts if fully opaque or fully transparent.
end_comment
begin_define
DECL|macro|BLEND_SOURCE_OVER_ARGB32_SSSE3
define|#
directive|define
name|BLEND_SOURCE_OVER_ARGB32_SSSE3
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|length
parameter_list|,
name|nullVector
parameter_list|,
name|half
parameter_list|,
name|one
parameter_list|,
name|colorMask
parameter_list|,
name|alphaMask
parameter_list|)
value|{ \     int x = 0; \ \
comment|/* First, get dst aligned. */
value|\     ALIGNMENT_PROLOGUE_16BYTES(dst, x, length) { \         blend_pixel(dst[x], src[x]); \     } \ \     const int minusOffsetToAlignSrcOn16Bytes = (reinterpret_cast<quintptr>(&(src[x]))>> 2)& 0x3;\ \     if (!minusOffsetToAlignSrcOn16Bytes) {\
comment|/* src is aligned, usual algorithm but with aligned operations.\            See the SSE2 version for more documentation on the algorithm itself. */
value|\         const __m128i alphaShuffleMask = _mm_set_epi8(0xff,15,0xff,15,0xff,11,0xff,11,0xff,7,0xff,7,0xff,3,0xff,3);\         for (; x< length-3; x += 4) { \             const __m128i srcVector = _mm_load_si128((__m128i *)&src[x]); \             const __m128i srcVectorAlpha = _mm_and_si128(srcVector, alphaMask); \             if (_mm_movemask_epi8(_mm_cmpeq_epi32(srcVectorAlpha, alphaMask)) == 0xffff) { \                 _mm_store_si128((__m128i *)&dst[x], srcVector); \             } else if (_mm_movemask_epi8(_mm_cmpeq_epi32(srcVectorAlpha, nullVector)) != 0xffff) { \                 __m128i alphaChannel = _mm_shuffle_epi8(srcVector, alphaShuffleMask); \                 alphaChannel = _mm_sub_epi16(one, alphaChannel); \                 const __m128i dstVector = _mm_load_si128((__m128i *)&dst[x]); \                 __m128i destMultipliedByOneMinusAlpha; \                 BYTE_MUL_SSE2(destMultipliedByOneMinusAlpha, dstVector, alphaChannel, colorMask, half); \                 const __m128i result = _mm_add_epi8(srcVector, destMultipliedByOneMinusAlpha); \                 _mm_store_si128((__m128i *)&dst[x], result); \             } \         }
comment|/* end for() */
value|\     } else if ((length - x)>= 8) {\
comment|/* We use two vectors to extract the src: prevLoaded for the first pixels, lastLoaded for the current pixels. */
value|\         __m128i srcVectorPrevLoaded = _mm_load_si128((__m128i *)&src[x - minusOffsetToAlignSrcOn16Bytes]);\         const int palignrOffset = minusOffsetToAlignSrcOn16Bytes<< 2;\ \         const __m128i alphaShuffleMask = _mm_set_epi8(0xff,15,0xff,15,0xff,11,0xff,11,0xff,7,0xff,7,0xff,3,0xff,3);\         switch (palignrOffset) {\         case 4:\             BLENDING_LOOP(4, length)\             break;\         case 8:\             BLENDING_LOOP(8, length)\             break;\         case 12:\             BLENDING_LOOP(12, length)\             break;\         }\     }\     for (; x< length; ++x) \         blend_pixel(dst[x], src[x]); \ }
end_define
begin_function
DECL|function|qt_blend_argb32_on_argb32_ssse3
name|void
name|qt_blend_argb32_on_argb32_ssse3
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
specifier|const
name|quint32
modifier|*
name|src
init|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
name|srcPixels
decl_stmt|;
name|quint32
modifier|*
name|dst
init|=
operator|(
name|quint32
operator|*
operator|)
name|destPixels
decl_stmt|;
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
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
name|one
init|=
name|_mm_set1_epi16
argument_list|(
literal|0xff
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
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
name|BLEND_SOURCE_OVER_ARGB32_SSSE3
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|w
argument_list|,
name|nullVector
argument_list|,
name|half
argument_list|,
name|one
argument_list|,
name|colorMask
argument_list|,
name|alphaMask
argument_list|)
expr_stmt|;
name|dst
operator|=
operator|(
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
name|uchar
operator|*
operator|)
name|dst
operator|)
operator|+
name|dbpl
operator|)
expr_stmt|;
name|src
operator|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|src
operator|)
operator|+
name|sbpl
operator|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|const_alpha
operator|!=
literal|0
condition|)
block|{
comment|// dest = (s + d * sia) * ca + d * cia
comment|//      = s * ca + d * (sia * ca + cia)
comment|//      = s * ca + d * (1 - sa*ca)
name|const_alpha
operator|=
operator|(
name|const_alpha
operator|*
literal|255
operator|)
operator|>>
literal|8
expr_stmt|;
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
name|one
init|=
name|_mm_set1_epi16
argument_list|(
literal|0xff
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
specifier|const
name|__m128i
name|constAlphaVector
init|=
name|_mm_set1_epi16
argument_list|(
name|const_alpha
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
name|BLEND_SOURCE_OVER_ARGB32_WITH_CONST_ALPHA_SSE2
argument_list|(
argument|dst
argument_list|,
argument|src
argument_list|,
argument|w
argument_list|,
argument|nullVector
argument_list|,
argument|half
argument_list|,
argument|one
argument_list|,
argument|colorMask
argument_list|,
argument|constAlphaVector
argument_list|)
name|dst
operator|=
operator|(
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
name|uchar
operator|*
operator|)
name|dst
operator|)
operator|+
name|dbpl
operator|)
expr_stmt|;
name|src
operator|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|src
operator|)
operator|+
name|sbpl
operator|)
expr_stmt|;
block|}
block|}
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
comment|// QT_COMPILER_SUPPORTS_SSSE3
end_comment
end_unit
