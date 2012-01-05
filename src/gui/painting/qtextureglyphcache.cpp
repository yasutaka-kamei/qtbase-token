begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|"qtextureglyphcache_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qfontengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qnumeric_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qnativeimage_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|// #define CACHE_DEBUG
comment|// returns the highest number closest to v, which is a power of 2
comment|// NB! assumes 32 bit ints
DECL|function|qt_next_power_of_two
specifier|static
specifier|inline
name|int
name|qt_next_power_of_two
parameter_list|(
name|int
name|v
parameter_list|)
block|{
name|v
operator|--
expr_stmt|;
name|v
operator||=
name|v
operator|>>
literal|1
expr_stmt|;
name|v
operator||=
name|v
operator|>>
literal|2
expr_stmt|;
name|v
operator||=
name|v
operator|>>
literal|4
expr_stmt|;
name|v
operator||=
name|v
operator|>>
literal|8
expr_stmt|;
name|v
operator||=
name|v
operator|>>
literal|16
expr_stmt|;
operator|++
name|v
expr_stmt|;
return|return
name|v
return|;
block|}
end_function
begin_function
DECL|function|calculateSubPixelPositionCount
name|int
name|QTextureGlyphCache
operator|::
name|calculateSubPixelPositionCount
parameter_list|(
name|glyph_t
name|glyph
parameter_list|)
specifier|const
block|{
comment|// Test 12 different subpixel positions since it factors into 3*4 so it gives
comment|// the coverage we need.
name|QList
argument_list|<
name|QImage
argument_list|>
name|images
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
literal|12
condition|;
operator|++
name|i
control|)
block|{
name|QImage
name|img
init|=
name|textureMapForGlyph
argument_list|(
name|glyph
argument_list|,
name|QFixed
operator|::
name|fromReal
argument_list|(
name|i
operator|/
literal|12.0
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|images
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QPainterPath
name|path
decl_stmt|;
name|QFixedPoint
name|point
decl_stmt|;
name|m_current_fontengine
operator|->
name|addGlyphsToPath
argument_list|(
operator|&
name|glyph
argument_list|,
operator|&
name|point
argument_list|,
literal|1
argument_list|,
operator|&
name|path
argument_list|,
name|QTextItem
operator|::
name|RenderFlags
argument_list|()
argument_list|)
expr_stmt|;
comment|// Glyph is space, return 0 to indicate that we need to keep trying
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
name|images
operator|.
name|append
argument_list|(
name|img
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|bool
name|found
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|images
operator|.
name|size
argument_list|()
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|images
operator|.
name|at
argument_list|(
name|j
argument_list|)
operator|==
name|img
condition|)
block|{
name|found
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|found
condition|)
name|images
operator|.
name|append
argument_list|(
name|img
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|images
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|populate
name|bool
name|QTextureGlyphCache
operator|::
name|populate
parameter_list|(
name|QFontEngine
modifier|*
name|fontEngine
parameter_list|,
name|int
name|numGlyphs
parameter_list|,
specifier|const
name|glyph_t
modifier|*
name|glyphs
parameter_list|,
specifier|const
name|QFixedPoint
modifier|*
name|positions
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|CACHE_DEBUG
name|printf
argument_list|(
literal|"Populating with %d glyphs\n"
argument_list|,
name|numGlyphs
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|" -> current transformation: "
operator|<<
name|m_transform
expr_stmt|;
endif|#
directive|endif
name|m_current_fontengine
operator|=
name|fontEngine
expr_stmt|;
specifier|const
name|int
name|margin
init|=
name|glyphMargin
argument_list|()
decl_stmt|;
specifier|const
name|int
name|paddingDoubled
init|=
name|glyphPadding
argument_list|()
operator|*
literal|2
decl_stmt|;
name|bool
name|supportsSubPixelPositions
init|=
name|fontEngine
operator|->
name|supportsSubPixelPositions
argument_list|()
decl_stmt|;
if|if
condition|(
name|fontEngine
operator|->
name|m_subPixelPositionCount
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|supportsSubPixelPositions
condition|)
block|{
name|fontEngine
operator|->
name|m_subPixelPositionCount
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|fontEngine
operator|->
name|m_subPixelPositionCount
operator|==
literal|0
operator|&&
name|i
operator|<
name|numGlyphs
condition|)
name|fontEngine
operator|->
name|m_subPixelPositionCount
operator|=
name|calculateSubPixelPositionCount
argument_list|(
name|glyphs
index|[
name|i
operator|++
index|]
argument_list|)
expr_stmt|;
block|}
block|}
name|QHash
argument_list|<
name|GlyphAndSubPixelPosition
argument_list|,
name|Coord
argument_list|>
name|listItemCoordinates
decl_stmt|;
name|int
name|rowHeight
init|=
literal|0
decl_stmt|;
name|QFontEngine
operator|::
name|GlyphFormat
name|format
decl_stmt|;
switch|switch
condition|(
name|m_type
condition|)
block|{
case|case
name|Raster_A8
case|:
name|format
operator|=
name|QFontEngine
operator|::
name|Format_A8
expr_stmt|;
break|break;
case|case
name|Raster_RGBMask
case|:
name|format
operator|=
name|QFontEngine
operator|::
name|Format_A32
expr_stmt|;
break|break;
default|default:
name|format
operator|=
name|QFontEngine
operator|::
name|Format_Mono
expr_stmt|;
break|break;
block|}
comment|// check each glyph for its metrics and get the required rowHeight.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numGlyphs
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|glyph_t
name|glyph
init|=
name|glyphs
index|[
name|i
index|]
decl_stmt|;
name|QFixed
name|subPixelPosition
decl_stmt|;
if|if
condition|(
name|supportsSubPixelPositions
condition|)
block|{
name|QFixed
name|x
init|=
name|positions
operator|!=
literal|0
condition|?
name|positions
index|[
name|i
index|]
operator|.
name|x
else|:
name|QFixed
argument_list|()
decl_stmt|;
name|subPixelPosition
operator|=
name|fontEngine
operator|->
name|subPixelPositionForX
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|coords
operator|.
name|contains
argument_list|(
name|GlyphAndSubPixelPosition
argument_list|(
name|glyph
argument_list|,
name|subPixelPosition
argument_list|)
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|listItemCoordinates
operator|.
name|contains
argument_list|(
name|GlyphAndSubPixelPosition
argument_list|(
name|glyph
argument_list|,
name|subPixelPosition
argument_list|)
argument_list|)
condition|)
continue|continue;
name|glyph_metrics_t
name|metrics
init|=
name|fontEngine
operator|->
name|alphaMapBoundingBox
argument_list|(
name|glyph
argument_list|,
name|subPixelPosition
argument_list|,
name|m_transform
argument_list|,
name|format
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|CACHE_DEBUG
name|printf
argument_list|(
literal|"(%4x): w=%.2f, h=%.2f, xoff=%.2f, yoff=%.2f, x=%.2f, y=%.2f\n"
argument_list|,
name|glyph
argument_list|,
name|metrics
operator|.
name|width
operator|.
name|toReal
argument_list|()
argument_list|,
name|metrics
operator|.
name|height
operator|.
name|toReal
argument_list|()
argument_list|,
name|metrics
operator|.
name|xoff
operator|.
name|toReal
argument_list|()
argument_list|,
name|metrics
operator|.
name|yoff
operator|.
name|toReal
argument_list|()
argument_list|,
name|metrics
operator|.
name|x
operator|.
name|toReal
argument_list|()
argument_list|,
name|metrics
operator|.
name|y
operator|.
name|toReal
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|GlyphAndSubPixelPosition
name|key
argument_list|(
name|glyph
argument_list|,
name|subPixelPosition
argument_list|)
decl_stmt|;
name|int
name|glyph_width
init|=
name|metrics
operator|.
name|width
operator|.
name|ceil
argument_list|()
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|int
name|glyph_height
init|=
name|metrics
operator|.
name|height
operator|.
name|ceil
argument_list|()
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|glyph_height
operator|==
literal|0
operator|||
name|glyph_width
operator|==
literal|0
condition|)
block|{
comment|// Avoid multiple calls to boundingBox() for non-printable characters
name|Coord
name|c
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|coords
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|c
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|glyph_width
operator|+=
name|margin
operator|*
literal|2
operator|+
literal|4
expr_stmt|;
name|glyph_height
operator|+=
name|margin
operator|*
literal|2
operator|+
literal|4
expr_stmt|;
comment|// align to 8-bit boundary
if|if
condition|(
name|m_type
operator|==
name|QFontEngineGlyphCache
operator|::
name|Raster_Mono
condition|)
name|glyph_width
operator|=
operator|(
name|glyph_width
operator|+
literal|7
operator|)
operator|&
operator|~
literal|7
expr_stmt|;
name|Coord
name|c
init|=
block|{
literal|0
block|,
literal|0
block|,
comment|// will be filled in later
name|glyph_width
block|,
name|glyph_height
block|,
comment|// texture coords
name|metrics
operator|.
name|x
operator|.
name|truncate
argument_list|()
block|,
operator|-
name|metrics
operator|.
name|y
operator|.
name|truncate
argument_list|()
block|}
decl_stmt|;
comment|// baseline for horizontal scripts
name|listItemCoordinates
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|rowHeight
operator|=
name|qMax
argument_list|(
name|rowHeight
argument_list|,
name|glyph_height
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|listItemCoordinates
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
name|rowHeight
operator|+=
name|margin
operator|*
literal|2
operator|+
name|paddingDoubled
expr_stmt|;
if|if
condition|(
name|m_w
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|fontEngine
operator|->
name|maxCharWidth
argument_list|()
operator|<=
name|QT_DEFAULT_TEXTURE_GLYPH_CACHE_WIDTH
condition|)
name|m_w
operator|=
name|QT_DEFAULT_TEXTURE_GLYPH_CACHE_WIDTH
expr_stmt|;
else|else
name|m_w
operator|=
name|qt_next_power_of_two
argument_list|(
name|fontEngine
operator|->
name|maxCharWidth
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// now actually use the coords and paint the wanted glyps into cache.
name|QHash
argument_list|<
name|GlyphAndSubPixelPosition
argument_list|,
name|Coord
argument_list|>
operator|::
name|iterator
name|iter
init|=
name|listItemCoordinates
operator|.
name|begin
argument_list|()
decl_stmt|;
name|int
name|requiredWidth
init|=
name|m_w
decl_stmt|;
while|while
condition|(
name|iter
operator|!=
name|listItemCoordinates
operator|.
name|end
argument_list|()
condition|)
block|{
name|Coord
name|c
init|=
name|iter
operator|.
name|value
argument_list|()
decl_stmt|;
name|m_currentRowHeight
operator|=
name|qMax
argument_list|(
name|m_currentRowHeight
argument_list|,
name|c
operator|.
name|h
operator|+
name|margin
operator|*
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_cx
operator|+
name|c
operator|.
name|w
operator|>
name|requiredWidth
condition|)
block|{
name|int
name|new_width
init|=
name|requiredWidth
operator|*
literal|2
decl_stmt|;
while|while
condition|(
name|new_width
operator|<
name|m_cx
operator|+
name|c
operator|.
name|w
condition|)
name|new_width
operator|*=
literal|2
expr_stmt|;
if|if
condition|(
name|new_width
operator|<=
name|maxTextureWidth
argument_list|()
condition|)
block|{
name|requiredWidth
operator|=
name|new_width
expr_stmt|;
block|}
else|else
block|{
comment|// no room on the current line, start new glyph strip
name|m_cx
operator|=
literal|0
expr_stmt|;
name|m_cy
operator|+=
name|m_currentRowHeight
operator|+
name|paddingDoubled
expr_stmt|;
name|m_currentRowHeight
operator|=
name|c
operator|.
name|h
operator|+
name|margin
operator|*
literal|2
expr_stmt|;
comment|// New row
block|}
block|}
if|if
condition|(
name|maxTextureHeight
argument_list|()
operator|>
literal|0
operator|&&
name|m_cy
operator|+
name|c
operator|.
name|h
operator|>
name|maxTextureHeight
argument_list|()
condition|)
block|{
comment|// We can't make a cache of the required size, so we bail out
return|return
literal|false
return|;
block|}
name|c
operator|.
name|x
operator|=
name|m_cx
expr_stmt|;
name|c
operator|.
name|y
operator|=
name|m_cy
expr_stmt|;
name|coords
operator|.
name|insert
argument_list|(
name|iter
operator|.
name|key
argument_list|()
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|m_pendingGlyphs
operator|.
name|insert
argument_list|(
name|iter
operator|.
name|key
argument_list|()
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|m_cx
operator|+=
name|c
operator|.
name|w
operator|+
name|paddingDoubled
expr_stmt|;
operator|++
name|iter
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|fillInPendingGlyphs
name|void
name|QTextureGlyphCache
operator|::
name|fillInPendingGlyphs
parameter_list|()
block|{
if|if
condition|(
name|m_pendingGlyphs
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|int
name|requiredHeight
init|=
name|m_h
decl_stmt|;
name|int
name|requiredWidth
init|=
name|m_w
decl_stmt|;
comment|// Use a minimum size to avoid a lot of initial reallocations
block|{
name|QHash
argument_list|<
name|GlyphAndSubPixelPosition
argument_list|,
name|Coord
argument_list|>
operator|::
name|iterator
name|iter
init|=
name|m_pendingGlyphs
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|iter
operator|!=
name|m_pendingGlyphs
operator|.
name|end
argument_list|()
condition|)
block|{
name|Coord
name|c
init|=
name|iter
operator|.
name|value
argument_list|()
decl_stmt|;
name|requiredHeight
operator|=
name|qMax
argument_list|(
name|requiredHeight
argument_list|,
name|c
operator|.
name|y
operator|+
name|c
operator|.
name|h
argument_list|)
expr_stmt|;
name|requiredWidth
operator|=
name|qMax
argument_list|(
name|requiredWidth
argument_list|,
name|c
operator|.
name|x
operator|+
name|c
operator|.
name|w
argument_list|)
expr_stmt|;
operator|++
name|iter
expr_stmt|;
block|}
block|}
if|if
condition|(
name|isNull
argument_list|()
operator|||
name|requiredHeight
operator|>
name|m_h
operator|||
name|requiredWidth
operator|>
name|m_w
condition|)
block|{
if|if
condition|(
name|isNull
argument_list|()
condition|)
name|createCache
argument_list|(
name|qt_next_power_of_two
argument_list|(
name|requiredWidth
argument_list|)
argument_list|,
name|qt_next_power_of_two
argument_list|(
name|requiredHeight
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|resizeCache
argument_list|(
name|qt_next_power_of_two
argument_list|(
name|requiredWidth
argument_list|)
argument_list|,
name|qt_next_power_of_two
argument_list|(
name|requiredHeight
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QHash
argument_list|<
name|GlyphAndSubPixelPosition
argument_list|,
name|Coord
argument_list|>
operator|::
name|iterator
name|iter
init|=
name|m_pendingGlyphs
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|iter
operator|!=
name|m_pendingGlyphs
operator|.
name|end
argument_list|()
condition|)
block|{
name|GlyphAndSubPixelPosition
name|key
init|=
name|iter
operator|.
name|key
argument_list|()
decl_stmt|;
name|fillTexture
argument_list|(
name|iter
operator|.
name|value
argument_list|()
argument_list|,
name|key
operator|.
name|glyph
argument_list|,
name|key
operator|.
name|subPixelPosition
argument_list|)
expr_stmt|;
operator|++
name|iter
expr_stmt|;
block|}
block|}
name|m_pendingGlyphs
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|textureMapForGlyph
name|QImage
name|QTextureGlyphCache
operator|::
name|textureMapForGlyph
parameter_list|(
name|glyph_t
name|g
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|m_type
operator|==
name|QFontEngineGlyphCache
operator|::
name|Raster_RGBMask
condition|)
return|return
name|m_current_fontengine
operator|->
name|alphaRGBMapForGlyph
argument_list|(
name|g
argument_list|,
name|subPixelPosition
argument_list|,
name|glyphMargin
argument_list|()
argument_list|,
name|m_transform
argument_list|)
return|;
else|else
return|return
name|m_current_fontengine
operator|->
name|alphaMapForGlyph
argument_list|(
name|g
argument_list|,
name|subPixelPosition
argument_list|,
name|m_transform
argument_list|)
return|;
return|return
name|QImage
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/************************************************************************  * QImageTextureGlyphCache  */
end_comment
begin_function
DECL|function|resizeTextureData
name|void
name|QImageTextureGlyphCache
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
name|m_image
operator|=
name|m_image
operator|.
name|copy
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createTextureData
name|void
name|QImageTextureGlyphCache
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
switch|switch
condition|(
name|m_type
condition|)
block|{
case|case
name|QFontEngineGlyphCache
operator|::
name|Raster_Mono
case|:
name|m_image
operator|=
name|QImage
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|QImage
operator|::
name|Format_Mono
argument_list|)
expr_stmt|;
break|break;
case|case
name|QFontEngineGlyphCache
operator|::
name|Raster_A8
case|:
block|{
name|m_image
operator|=
name|QImage
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|QImage
operator|::
name|Format_Indexed8
argument_list|)
expr_stmt|;
name|m_image
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|QRgb
argument_list|>
name|colors
argument_list|(
literal|256
argument_list|)
decl_stmt|;
name|QRgb
modifier|*
name|it
init|=
name|colors
operator|.
name|data
argument_list|()
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
literal|256
condition|;
operator|++
name|i
operator|,
operator|++
name|it
control|)
operator|*
name|it
operator|=
literal|0xff000000
operator||
name|i
operator||
operator|(
name|i
operator|<<
literal|8
operator|)
operator||
operator|(
name|i
operator|<<
literal|16
operator|)
expr_stmt|;
name|m_image
operator|.
name|setColorTable
argument_list|(
name|colors
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QFontEngineGlyphCache
operator|::
name|Raster_RGBMask
case|:
name|m_image
operator|=
name|QImage
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_function
DECL|function|glyphMargin
name|int
name|QImageTextureGlyphCache
operator|::
name|glyphMargin
parameter_list|()
specifier|const
block|{
return|return
name|m_type
operator|==
name|QFontEngineGlyphCache
operator|::
name|Raster_RGBMask
condition|?
literal|2
else|:
literal|0
return|;
block|}
end_function
begin_function
DECL|function|fillTexture
name|void
name|QImageTextureGlyphCache
operator|::
name|fillTexture
parameter_list|(
specifier|const
name|Coord
modifier|&
name|c
parameter_list|,
name|glyph_t
name|g
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|)
block|{
name|QImage
name|mask
init|=
name|textureMapForGlyph
argument_list|(
name|g
argument_list|,
name|subPixelPosition
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|CACHE_DEBUG
name|printf
argument_list|(
literal|"fillTexture of %dx%d at %d,%d in the cache of %dx%d\n"
argument_list|,
name|c
operator|.
name|w
argument_list|,
name|c
operator|.
name|h
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
argument_list|,
name|m_image
operator|.
name|width
argument_list|()
argument_list|,
name|m_image
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|mask
operator|.
name|width
argument_list|()
operator|>
name|c
operator|.
name|w
operator|||
name|mask
operator|.
name|height
argument_list|()
operator|>
name|c
operator|.
name|h
condition|)
block|{
name|printf
argument_list|(
literal|"   ERROR; mask is bigger than reserved space! %dx%d instead of %dx%d\n"
argument_list|,
name|mask
operator|.
name|width
argument_list|()
argument_list|,
name|mask
operator|.
name|height
argument_list|()
argument_list|,
name|c
operator|.
name|w
argument_list|,
name|c
operator|.
name|h
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
if|if
condition|(
name|m_type
operator|==
name|QFontEngineGlyphCache
operator|::
name|Raster_RGBMask
condition|)
block|{
name|QImage
name|ref
argument_list|(
name|m_image
operator|.
name|bits
argument_list|()
operator|+
operator|(
name|c
operator|.
name|x
operator|*
literal|4
operator|+
name|c
operator|.
name|y
operator|*
name|m_image
operator|.
name|bytesPerLine
argument_list|()
operator|)
argument_list|,
name|qMax
argument_list|(
name|mask
operator|.
name|width
argument_list|()
argument_list|,
name|c
operator|.
name|w
argument_list|)
argument_list|,
name|qMax
argument_list|(
name|mask
operator|.
name|height
argument_list|()
argument_list|,
name|c
operator|.
name|h
argument_list|)
argument_list|,
name|m_image
operator|.
name|bytesPerLine
argument_list|()
argument_list|,
name|m_image
operator|.
name|format
argument_list|()
argument_list|)
decl_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|ref
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|c
operator|.
name|w
argument_list|,
name|c
operator|.
name|h
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// TODO optimize this
name|p
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|mask
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|m_type
operator|==
name|QFontEngineGlyphCache
operator|::
name|Raster_Mono
condition|)
block|{
if|if
condition|(
name|mask
operator|.
name|depth
argument_list|()
operator|>
literal|1
condition|)
block|{
comment|// TODO optimize this
name|mask
operator|=
name|mask
operator|.
name|alphaChannel
argument_list|()
expr_stmt|;
name|mask
operator|.
name|invertPixels
argument_list|()
expr_stmt|;
name|mask
operator|=
name|mask
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_Mono
argument_list|)
expr_stmt|;
block|}
name|int
name|mw
init|=
name|qMin
argument_list|(
name|mask
operator|.
name|width
argument_list|()
argument_list|,
name|c
operator|.
name|w
argument_list|)
decl_stmt|;
name|int
name|mh
init|=
name|qMin
argument_list|(
name|mask
operator|.
name|height
argument_list|()
argument_list|,
name|c
operator|.
name|h
argument_list|)
decl_stmt|;
name|uchar
modifier|*
name|d
init|=
name|m_image
operator|.
name|bits
argument_list|()
decl_stmt|;
name|int
name|dbpl
init|=
name|m_image
operator|.
name|bytesPerLine
argument_list|()
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
name|c
operator|.
name|h
condition|;
operator|++
name|y
control|)
block|{
name|uchar
modifier|*
name|dest
init|=
name|d
operator|+
operator|(
name|c
operator|.
name|y
operator|+
name|y
operator|)
operator|*
name|dbpl
operator|+
name|c
operator|.
name|x
operator|/
literal|8
decl_stmt|;
if|if
condition|(
name|y
operator|<
name|mh
condition|)
block|{
name|uchar
modifier|*
name|src
init|=
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
name|c
operator|.
name|w
operator|/
literal|8
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
name|x
operator|<
operator|(
name|mw
operator|+
literal|7
operator|)
operator|/
literal|8
condition|)
name|dest
index|[
name|x
index|]
operator|=
name|src
index|[
name|x
index|]
expr_stmt|;
else|else
name|dest
index|[
name|x
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
else|else
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|c
operator|.
name|w
operator|/
literal|8
condition|;
operator|++
name|x
control|)
name|dest
index|[
name|x
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|// A8
name|int
name|mw
init|=
name|qMin
argument_list|(
name|mask
operator|.
name|width
argument_list|()
argument_list|,
name|c
operator|.
name|w
argument_list|)
decl_stmt|;
name|int
name|mh
init|=
name|qMin
argument_list|(
name|mask
operator|.
name|height
argument_list|()
argument_list|,
name|c
operator|.
name|h
argument_list|)
decl_stmt|;
name|uchar
modifier|*
name|d
init|=
name|m_image
operator|.
name|bits
argument_list|()
decl_stmt|;
name|int
name|dbpl
init|=
name|m_image
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
if|if
condition|(
name|mask
operator|.
name|depth
argument_list|()
operator|==
literal|1
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
name|c
operator|.
name|h
condition|;
operator|++
name|y
control|)
block|{
name|uchar
modifier|*
name|dest
init|=
name|d
operator|+
operator|(
name|c
operator|.
name|y
operator|+
name|y
operator|)
operator|*
name|dbpl
operator|+
name|c
operator|.
name|x
decl_stmt|;
if|if
condition|(
name|y
operator|<
name|mh
condition|)
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
name|c
operator|.
name|w
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
name|x
operator|<
name|mw
condition|)
name|dest
index|[
name|x
index|]
operator|=
operator|(
name|src
index|[
name|x
operator|>>
literal|3
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
literal|7
operator|-
operator|(
name|x
operator|&
literal|7
operator|)
operator|)
operator|)
operator|)
operator|>
literal|0
condition|?
literal|255
else|:
literal|0
expr_stmt|;
block|}
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|mask
operator|.
name|depth
argument_list|()
operator|==
literal|8
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
name|c
operator|.
name|h
condition|;
operator|++
name|y
control|)
block|{
name|uchar
modifier|*
name|dest
init|=
name|d
operator|+
operator|(
name|c
operator|.
name|y
operator|+
name|y
operator|)
operator|*
name|dbpl
operator|+
name|c
operator|.
name|x
decl_stmt|;
if|if
condition|(
name|y
operator|<
name|mh
condition|)
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
name|c
operator|.
name|w
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
name|x
operator|<
name|mw
condition|)
name|dest
index|[
name|x
index|]
operator|=
name|src
index|[
name|x
index|]
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
ifdef|#
directive|ifdef
name|CACHE_DEBUG
comment|//     QPainter p(&m_image);
comment|//     p.drawLine(
name|QPoint
name|base
argument_list|(
name|c
operator|.
name|x
operator|+
name|glyphMargin
argument_list|()
argument_list|,
name|c
operator|.
name|y
operator|+
name|glyphMargin
argument_list|()
operator|+
name|c
operator|.
name|baseLineY
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_image
operator|.
name|rect
argument_list|()
operator|.
name|contains
argument_list|(
name|base
argument_list|)
condition|)
name|m_image
operator|.
name|setPixel
argument_list|(
name|base
argument_list|,
literal|255
argument_list|)
expr_stmt|;
name|m_image
operator|.
name|save
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"cache-%1.png"
argument_list|)
operator|.
name|arg
argument_list|(
name|qint64
argument_list|(
name|this
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
