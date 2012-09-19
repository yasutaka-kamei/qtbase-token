begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTENGINE_QPA_P_H
end_ifndef
begin_define
DECL|macro|QFONTENGINE_QPA_P_H
define|#
directive|define
name|QFONTENGINE_QPA_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qconfig.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qendian.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QBuffer>
end_include
begin_include
include|#
directive|include
file|"qfontengine_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QFontEngine
name|class
name|QFontEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFreetypeFace
name|class
name|QFreetypeFace
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBuffer
name|class
name|QBuffer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontEngineQPA
range|:
name|public
name|QFontEngine
block|{
name|public
operator|:
comment|// if you add new tags please make sure to update the tables in
comment|// qpfutil.cpp and tools/makeqpf/qpf2.cpp
expr|enum
name|HeaderTag
block|{
name|Tag_FontName
block|,
comment|// 0 string
name|Tag_FileName
block|,
comment|// 1 string
name|Tag_FileIndex
block|,
comment|// 2 quint32
name|Tag_FontRevision
block|,
comment|// 3 quint32
name|Tag_FreeText
block|,
comment|// 4 string
name|Tag_Ascent
block|,
comment|// 5 QFixed
name|Tag_Descent
block|,
comment|// 6 QFixed
name|Tag_Leading
block|,
comment|// 7 QFixed
name|Tag_XHeight
block|,
comment|// 8 QFixed
name|Tag_AverageCharWidth
block|,
comment|// 9 QFixed
name|Tag_MaxCharWidth
block|,
comment|// 10 QFixed
name|Tag_LineThickness
block|,
comment|// 11 QFixed
name|Tag_MinLeftBearing
block|,
comment|// 12 QFixed
name|Tag_MinRightBearing
block|,
comment|// 13 QFixed
name|Tag_UnderlinePosition
block|,
comment|// 14 QFixed
name|Tag_GlyphFormat
block|,
comment|// 15 quint8
name|Tag_PixelSize
block|,
comment|// 16 quint8
name|Tag_Weight
block|,
comment|// 17 quint8
name|Tag_Style
block|,
comment|// 18 quint8
name|Tag_EndOfHeader
block|,
comment|// 19 string
name|Tag_WritingSystems
block|,
comment|// 20 bitfield
name|NumTags
block|}
block|;      enum
name|TagType
block|{
name|StringType
block|,
name|FixedType
block|,
name|UInt8Type
block|,
name|UInt32Type
block|,
name|BitFieldType
block|}
block|;      struct
name|Tag
block|{
name|quint16
name|tag
block|;
name|quint16
name|size
block|;     }
block|;      enum
name|GlyphFormat
block|{
name|BitmapGlyphs
operator|=
literal|1
block|,
name|AlphamapGlyphs
operator|=
literal|8
block|}
block|;      enum
block|{
name|CurrentMajorVersion
operator|=
literal|2
block|,
name|CurrentMinorVersion
operator|=
literal|0
block|}
block|;
comment|// The CMap is identical to the TrueType CMap table format
comment|// The GMap table is a normal array with the total number of
comment|// covered glyphs in the TrueType font
block|enum
name|BlockTag
block|{
name|CMapBlock
block|,
name|GMapBlock
block|,
name|GlyphBlock
block|}
block|;      struct
name|Q_PACKED
name|Header
block|{
name|char
name|magic
index|[
literal|4
index|]
block|;
comment|// 'QPF2'
name|quint32
name|lock
block|;
comment|// values: 0 = unlocked, 0xffffffff = read-only, otherwise qws client id of locking process
name|quint8
name|majorVersion
block|;
name|quint8
name|minorVersion
block|;
name|quint16
name|dataSize
block|;     }
block|;      struct
name|Q_PACKED
name|Block
block|{
name|quint16
name|tag
block|;
name|quint16
name|pad
block|;
name|quint32
name|dataSize
block|;     }
block|;      struct
name|Q_PACKED
name|Glyph
block|{
name|quint8
name|width
block|;
name|quint8
name|height
block|;
name|quint8
name|bytesPerLine
block|;
name|qint8
name|x
block|;
name|qint8
name|y
block|;
name|qint8
name|advance
block|;     }
block|;
name|QFontEngineQPA
argument_list|(
specifier|const
name|QFontDef
operator|&
name|def
argument_list|,
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
block|;
operator|~
name|QFontEngineQPA
argument_list|()
block|;
name|FaceId
name|faceId
argument_list|()
specifier|const
block|{
return|return
name|face_id
return|;
block|}
name|bool
name|getSfntTableData
argument_list|(
argument|uint tag
argument_list|,
argument|uchar *buffer
argument_list|,
argument|uint *length
argument_list|)
specifier|const
block|;
name|bool
name|stringToCMap
argument_list|(
argument|const QChar *str
argument_list|,
argument|int len
argument_list|,
argument|QGlyphLayout *glyphs
argument_list|,
argument|int *nglyphs
argument_list|,
argument|ShaperFlags flags
argument_list|)
specifier|const
block|;
name|void
name|recalcAdvances
argument_list|(
argument|QGlyphLayout *
argument_list|,
argument|ShaperFlags
argument_list|)
specifier|const
block|;
name|void
name|addOutlineToPath
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|const QGlyphLayout&glyphs
argument_list|,
argument|QPainterPath *path
argument_list|,
argument|QTextItem::RenderFlags flags
argument_list|)
block|;
name|QImage
name|alphaMapForGlyph
argument_list|(
argument|glyph_t t
argument_list|)
block|;
name|glyph_metrics_t
name|boundingBox
argument_list|(
specifier|const
name|QGlyphLayout
operator|&
name|glyphs
argument_list|)
block|;
name|glyph_metrics_t
name|boundingBox
argument_list|(
argument|glyph_t glyph
argument_list|)
block|;
name|QFixed
name|ascent
argument_list|()
specifier|const
block|;
name|QFixed
name|descent
argument_list|()
specifier|const
block|;
name|QFixed
name|leading
argument_list|()
specifier|const
block|;
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
block|;
name|qreal
name|minLeftBearing
argument_list|()
specifier|const
block|;
name|qreal
name|minRightBearing
argument_list|()
specifier|const
block|;
name|QFixed
name|underlinePosition
argument_list|()
specifier|const
block|;
name|QFixed
name|lineThickness
argument_list|()
specifier|const
block|;
name|Type
name|type
argument_list|()
specifier|const
block|;
name|bool
name|canRender
argument_list|(
argument|const QChar *string
argument_list|,
argument|int len
argument_list|)
block|;
specifier|inline
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
literal|"QPF2"
return|;
block|}
name|virtual
name|int
name|glyphCount
argument_list|()
specifier|const
block|{
return|return
name|glyphMapEntries
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|;
specifier|const
name|Glyph
operator|*
name|findGlyph
argument_list|(
argument|glyph_t g
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|verifyHeader
argument_list|(
argument|const uchar *data
argument_list|,
argument|int size
argument_list|)
block|;
specifier|static
name|QVariant
name|extractHeaderField
argument_list|(
argument|const uchar *data
argument_list|,
argument|HeaderTag tag
argument_list|)
block|;
name|private
operator|:
specifier|const
name|uchar
operator|*
name|fontData
block|;
name|int
name|dataSize
block|;
specifier|const
name|uchar
operator|*
name|externalCMap
block|;
name|quint32
name|cmapOffset
block|;
name|int
name|cmapSize
block|;
name|quint32
name|glyphMapOffset
block|;
name|quint32
name|glyphMapEntries
block|;
name|quint32
name|glyphDataOffset
block|;
name|quint32
name|glyphDataSize
block|;
name|QString
name|internalFileName
block|;
name|QString
name|encodedFileName
block|;
name|bool
name|readOnly
block|;
name|FaceId
name|face_id
block|;
name|QByteArray
name|freetypeCMapTable
block|;
name|mutable
name|bool
name|kerning_pairs_loaded
block|; }
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QPAGenerator
struct|struct
name|QPAGenerator
block|{
DECL|function|QPAGenerator
name|QPAGenerator
argument_list|(
name|QBuffer
operator|*
name|device
argument_list|,
name|QFontEngine
operator|*
name|engine
argument_list|)
operator|:
name|dev
argument_list|(
name|device
argument_list|)
operator|,
name|fe
argument_list|(
argument|engine
argument_list|)
block|{}
name|void
name|generate
argument_list|()
expr_stmt|;
name|void
name|writeHeader
parameter_list|()
function_decl|;
name|void
name|writeGMap
parameter_list|()
function_decl|;
name|void
name|writeBlock
argument_list|(
name|QFontEngineQPA
operator|::
name|BlockTag
name|tag
argument_list|,
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
decl_stmt|;
name|void
name|writeTaggedString
argument_list|(
name|QFontEngineQPA
operator|::
name|HeaderTag
name|tag
argument_list|,
specifier|const
name|QByteArray
operator|&
name|string
argument_list|)
decl_stmt|;
name|void
name|writeTaggedUInt32
argument_list|(
name|QFontEngineQPA
operator|::
name|HeaderTag
name|tag
argument_list|,
name|quint32
name|value
argument_list|)
decl_stmt|;
name|void
name|writeTaggedUInt8
argument_list|(
name|QFontEngineQPA
operator|::
name|HeaderTag
name|tag
argument_list|,
name|quint8
name|value
argument_list|)
decl_stmt|;
name|void
name|writeTaggedQFixed
argument_list|(
name|QFontEngineQPA
operator|::
name|HeaderTag
name|tag
argument_list|,
name|QFixed
name|value
argument_list|)
decl_stmt|;
DECL|function|writeUInt16
name|void
name|writeUInt16
parameter_list|(
name|quint16
name|value
parameter_list|)
block|{
name|value
operator|=
name|qToBigEndian
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|dev
operator|->
name|write
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
operator|&
name|value
argument_list|,
sizeof|sizeof
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|writeUInt32
name|void
name|writeUInt32
parameter_list|(
name|quint32
name|value
parameter_list|)
block|{
name|value
operator|=
name|qToBigEndian
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|dev
operator|->
name|write
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
operator|&
name|value
argument_list|,
sizeof|sizeof
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|writeUInt8
name|void
name|writeUInt8
parameter_list|(
name|quint8
name|value
parameter_list|)
block|{
name|dev
operator|->
name|write
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
operator|&
name|value
argument_list|,
sizeof|sizeof
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|writeInt8
name|void
name|writeInt8
parameter_list|(
name|qint8
name|value
parameter_list|)
block|{
name|dev
operator|->
name|write
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
operator|&
name|value
argument_list|,
sizeof|sizeof
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|align4
name|void
name|align4
parameter_list|()
block|{
while|while
condition|(
name|dev
operator|->
name|pos
argument_list|()
operator|&
literal|3
condition|)
block|{
name|dev
operator|->
name|putChar
argument_list|(
literal|'\0'
argument_list|)
expr_stmt|;
block|}
block|}
DECL|member|dev
name|QBuffer
modifier|*
name|dev
decl_stmt|;
DECL|member|fe
name|QFontEngine
modifier|*
name|fe
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QFontEngineMultiQPA
range|:
name|public
name|QFontEngineMulti
block|{
name|public
operator|:
name|QFontEngineMultiQPA
argument_list|(
argument|QFontEngine *fe
argument_list|,
argument|int script
argument_list|,
argument|const QStringList&fallbacks
argument_list|)
block|;
name|QFontEngineMultiQPA
argument_list|(
argument|QFontEngine *fe
argument_list|,
argument|int script
argument_list|)
block|;
name|void
name|loadEngine
argument_list|(
argument|int at
argument_list|)
block|;
specifier|static
name|QFontEngine
operator|*
name|createMultiFontEngine
argument_list|(
argument|QFontEngine *fe
argument_list|,
argument|int script
argument_list|)
block|;
name|int
name|fallbackFamilyCount
argument_list|()
specifier|const
block|{
return|return
name|fallbackFamilies
operator|.
name|size
argument_list|()
return|;
block|}
name|QString
name|fallbackFamilyAt
argument_list|(
argument|int at
argument_list|)
specifier|const
block|{
return|return
name|fallbackFamilies
operator|.
name|at
argument_list|(
name|at
argument_list|)
return|;
block|}
name|virtual
name|void
name|ensureFallbackFamiliesQueried
argument_list|()
block|;
name|virtual
name|void
name|setFallbackFamiliesList
argument_list|(
specifier|const
name|QStringList
operator|&
name|fallbacks
argument_list|)
block|;
name|private
operator|:
name|void
name|init
argument_list|(
name|QFontEngine
operator|*
name|fe
argument_list|)
block|;
name|mutable
name|QStringList
name|fallbackFamilies
block|;
name|int
name|script
block|;
name|mutable
name|bool
name|fallbacksQueried
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTENGINE_QPA_P_H
end_comment
end_unit
