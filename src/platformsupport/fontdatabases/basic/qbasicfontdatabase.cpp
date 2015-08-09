begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbasicfontdatabase_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLibraryInfo>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUuid>
end_include
begin_include
include|#
directive|include
file|<QtCore/QtEndian>
end_include
begin_undef
DECL|macro|QT_NO_FREETYPE
undef|#
directive|undef
name|QT_NO_FREETYPE
end_undef
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_ft_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TABLES_H
end_include
begin_include
include|#
directive|include
include|FT_ERRORS_H
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|populateFontDatabase
name|void
name|QBasicFontDatabase
operator|::
name|populateFontDatabase
parameter_list|()
block|{
name|QString
name|fontpath
init|=
name|fontDir
argument_list|()
decl_stmt|;
name|QDir
name|dir
argument_list|(
name|fontpath
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|dir
operator|.
name|exists
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFontDatabase: Cannot find font directory %s - is Qt installed correctly?"
argument_list|,
name|qPrintable
argument_list|(
name|fontpath
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|QStringList
name|nameFilters
decl_stmt|;
name|nameFilters
operator|<<
name|QLatin1String
argument_list|(
literal|"*.ttf"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"*.ttc"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"*.pfa"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"*.pfb"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"*.otf"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QFileInfo
modifier|&
name|fi
decl|,
name|dir
operator|.
name|entryInfoList
argument_list|(
name|nameFilters
argument_list|,
name|QDir
operator|::
name|Files
argument_list|)
control|)
block|{
specifier|const
name|QByteArray
name|file
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|fi
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
decl_stmt|;
name|QBasicFontDatabase
operator|::
name|addTTFile
argument_list|(
name|QByteArray
argument_list|()
argument_list|,
name|file
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setHintingPreference
specifier|inline
specifier|static
name|void
name|setHintingPreference
parameter_list|(
name|QFontEngine
modifier|*
name|engine
parameter_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
parameter_list|)
block|{
switch|switch
condition|(
name|hintingPreference
condition|)
block|{
case|case
name|QFont
operator|::
name|PreferNoHinting
case|:
name|engine
operator|->
name|setDefaultHintStyle
argument_list|(
name|QFontEngineFT
operator|::
name|HintNone
argument_list|)
expr_stmt|;
break|break;
case|case
name|QFont
operator|::
name|PreferFullHinting
case|:
name|engine
operator|->
name|setDefaultHintStyle
argument_list|(
name|QFontEngineFT
operator|::
name|HintFull
argument_list|)
expr_stmt|;
break|break;
case|case
name|QFont
operator|::
name|PreferVerticalHinting
case|:
name|engine
operator|->
name|setDefaultHintStyle
argument_list|(
name|QFontEngineFT
operator|::
name|HintLight
argument_list|)
expr_stmt|;
break|break;
case|case
name|QFont
operator|::
name|PreferDefaultHinting
case|:
comment|// Leave it as it is
break|break;
block|}
block|}
end_function
begin_function
DECL|function|fontEngine
name|QFontEngine
modifier|*
name|QBasicFontDatabase
operator|::
name|fontEngine
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fontDef
parameter_list|,
name|void
modifier|*
name|usrPtr
parameter_list|)
block|{
name|FontFile
modifier|*
name|fontfile
init|=
cast|static_cast
argument_list|<
name|FontFile
operator|*
argument_list|>
argument_list|(
name|usrPtr
argument_list|)
decl_stmt|;
name|QFontEngine
operator|::
name|FaceId
name|fid
decl_stmt|;
name|fid
operator|.
name|filename
operator|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|fontfile
operator|->
name|fileName
argument_list|)
expr_stmt|;
name|fid
operator|.
name|index
operator|=
name|fontfile
operator|->
name|indexValue
expr_stmt|;
name|bool
name|antialias
init|=
operator|!
operator|(
name|fontDef
operator|.
name|styleStrategy
operator|&
name|QFont
operator|::
name|NoAntialias
operator|)
decl_stmt|;
name|QFontEngineFT
modifier|*
name|engine
init|=
operator|new
name|QFontEngineFT
argument_list|(
name|fontDef
argument_list|)
decl_stmt|;
name|QFontEngineFT
operator|::
name|GlyphFormat
name|format
init|=
name|QFontEngineFT
operator|::
name|Format_Mono
decl_stmt|;
if|if
condition|(
name|antialias
condition|)
block|{
name|QFontEngine
operator|::
name|SubpixelAntialiasingType
name|subpixelType
init|=
name|subpixelAntialiasingTypeHint
argument_list|()
decl_stmt|;
if|if
condition|(
name|subpixelType
operator|==
name|QFontEngine
operator|::
name|Subpixel_None
operator|||
operator|(
name|fontDef
operator|.
name|styleStrategy
operator|&
name|QFont
operator|::
name|NoSubpixelAntialias
operator|)
condition|)
block|{
name|format
operator|=
name|QFontEngineFT
operator|::
name|Format_A8
expr_stmt|;
name|engine
operator|->
name|subpixelType
operator|=
name|QFontEngine
operator|::
name|Subpixel_None
expr_stmt|;
block|}
else|else
block|{
name|format
operator|=
name|QFontEngineFT
operator|::
name|Format_A32
expr_stmt|;
name|engine
operator|->
name|subpixelType
operator|=
name|subpixelType
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|engine
operator|->
name|init
argument_list|(
name|fid
argument_list|,
name|antialias
argument_list|,
name|format
argument_list|)
operator|||
name|engine
operator|->
name|invalid
argument_list|()
condition|)
block|{
operator|delete
name|engine
expr_stmt|;
name|engine
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|setHintingPreference
argument_list|(
name|engine
argument_list|,
cast|static_cast
argument_list|<
name|QFont
operator|::
name|HintingPreference
argument_list|>
argument_list|(
name|fontDef
operator|.
name|hintingPreference
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|engine
return|;
block|}
end_function
begin_namespace
namespace|namespace
block|{
DECL|class|QFontEngineFTRawData
class|class
name|QFontEngineFTRawData
super|:
specifier|public
name|QFontEngineFT
block|{
public|public:
DECL|function|QFontEngineFTRawData
name|QFontEngineFTRawData
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fontDef
parameter_list|)
member_init_list|:
name|QFontEngineFT
argument_list|(
name|fontDef
argument_list|)
block|{         }
DECL|function|updateFamilyNameAndStyle
name|void
name|updateFamilyNameAndStyle
parameter_list|()
block|{
name|fontDef
operator|.
name|family
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|freetype
operator|->
name|face
operator|->
name|family_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|freetype
operator|->
name|face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_ITALIC
condition|)
name|fontDef
operator|.
name|style
operator|=
name|QFont
operator|::
name|StyleItalic
expr_stmt|;
if|if
condition|(
name|freetype
operator|->
name|face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_BOLD
condition|)
name|fontDef
operator|.
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
block|}
DECL|function|initFromData
name|bool
name|initFromData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|)
block|{
name|FaceId
name|faceId
decl_stmt|;
name|faceId
operator|.
name|filename
operator|=
literal|""
expr_stmt|;
name|faceId
operator|.
name|index
operator|=
literal|0
expr_stmt|;
name|faceId
operator|.
name|uuid
operator|=
name|QUuid
operator|::
name|createUuid
argument_list|()
operator|.
name|toByteArray
argument_list|()
expr_stmt|;
return|return
name|init
argument_list|(
name|faceId
argument_list|,
literal|true
argument_list|,
name|Format_None
argument_list|,
name|fontData
argument_list|)
return|;
block|}
block|}
class|;
block|}
end_namespace
begin_function
DECL|function|fontEngine
name|QFontEngine
modifier|*
name|QBasicFontDatabase
operator|::
name|fontEngine
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
name|qreal
name|pixelSize
parameter_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
parameter_list|)
block|{
name|QFontDef
name|fontDef
decl_stmt|;
name|fontDef
operator|.
name|pixelSize
operator|=
name|pixelSize
expr_stmt|;
name|fontDef
operator|.
name|hintingPreference
operator|=
name|hintingPreference
expr_stmt|;
name|QFontEngineFTRawData
modifier|*
name|fe
init|=
operator|new
name|QFontEngineFTRawData
argument_list|(
name|fontDef
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fe
operator|->
name|initFromData
argument_list|(
name|fontData
argument_list|)
condition|)
block|{
operator|delete
name|fe
expr_stmt|;
return|return
literal|0
return|;
block|}
name|fe
operator|->
name|updateFamilyNameAndStyle
argument_list|()
expr_stmt|;
name|setHintingPreference
argument_list|(
name|fe
argument_list|,
name|hintingPreference
argument_list|)
expr_stmt|;
return|return
name|fe
return|;
block|}
end_function
begin_function
DECL|function|addApplicationFont
name|QStringList
name|QBasicFontDatabase
operator|::
name|addApplicationFont
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
return|return
name|QBasicFontDatabase
operator|::
name|addTTFile
argument_list|(
name|fontData
argument_list|,
name|fileName
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|releaseHandle
name|void
name|QBasicFontDatabase
operator|::
name|releaseHandle
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|FontFile
modifier|*
name|file
init|=
cast|static_cast
argument_list|<
name|FontFile
operator|*
argument_list|>
argument_list|(
name|handle
argument_list|)
decl_stmt|;
operator|delete
name|file
expr_stmt|;
block|}
end_function
begin_function_decl
specifier|extern
name|FT_Library
name|qt_getFreetype
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|addTTFile
name|QStringList
name|QBasicFontDatabase
operator|::
name|addTTFile
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|file
parameter_list|)
block|{
name|FT_Library
name|library
init|=
name|qt_getFreetype
argument_list|()
decl_stmt|;
name|int
name|index
init|=
literal|0
decl_stmt|;
name|int
name|numFaces
init|=
literal|0
decl_stmt|;
name|QStringList
name|families
decl_stmt|;
do|do
block|{
name|FT_Face
name|face
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
if|if
condition|(
operator|!
name|fontData
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|error
operator|=
name|FT_New_Memory_Face
argument_list|(
name|library
argument_list|,
operator|(
specifier|const
name|FT_Byte
operator|*
operator|)
name|fontData
operator|.
name|constData
argument_list|()
argument_list|,
name|fontData
operator|.
name|size
argument_list|()
argument_list|,
name|index
argument_list|,
operator|&
name|face
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|error
operator|=
name|FT_New_Face
argument_list|(
name|library
argument_list|,
name|file
operator|.
name|constData
argument_list|()
argument_list|,
name|index
argument_list|,
operator|&
name|face
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|error
operator|!=
name|FT_Err_Ok
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"FT_New_Face failed with index"
operator|<<
name|index
operator|<<
literal|":"
operator|<<
name|hex
operator|<<
name|error
expr_stmt|;
break|break;
block|}
name|numFaces
operator|=
name|face
operator|->
name|num_faces
expr_stmt|;
name|QFont
operator|::
name|Weight
name|weight
init|=
name|QFont
operator|::
name|Normal
decl_stmt|;
name|QFont
operator|::
name|Style
name|style
init|=
name|QFont
operator|::
name|StyleNormal
decl_stmt|;
if|if
condition|(
name|face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_ITALIC
condition|)
name|style
operator|=
name|QFont
operator|::
name|StyleItalic
expr_stmt|;
if|if
condition|(
name|face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_BOLD
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
name|bool
name|fixedPitch
init|=
operator|(
name|face
operator|->
name|face_flags
operator|&
name|FT_FACE_FLAG_FIXED_WIDTH
operator|)
decl_stmt|;
name|QSupportedWritingSystems
name|writingSystems
decl_stmt|;
comment|// detect symbol fonts
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|face
operator|->
name|num_charmaps
condition|;
operator|++
name|i
control|)
block|{
name|FT_CharMap
name|cm
init|=
name|face
operator|->
name|charmaps
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|cm
operator|->
name|encoding
operator|==
name|FT_ENCODING_ADOBE_CUSTOM
operator|||
name|cm
operator|->
name|encoding
operator|==
name|FT_ENCODING_MS_SYMBOL
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|Symbol
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|TT_OS2
modifier|*
name|os2
init|=
operator|(
name|TT_OS2
operator|*
operator|)
name|FT_Get_Sfnt_Table
argument_list|(
name|face
argument_list|,
name|ft_sfnt_os2
argument_list|)
decl_stmt|;
if|if
condition|(
name|os2
condition|)
block|{
name|quint32
name|unicodeRange
index|[
literal|4
index|]
init|=
block|{
name|quint32
argument_list|(
name|os2
operator|->
name|ulUnicodeRange1
argument_list|)
block|,
name|quint32
argument_list|(
name|os2
operator|->
name|ulUnicodeRange2
argument_list|)
block|,
name|quint32
argument_list|(
name|os2
operator|->
name|ulUnicodeRange3
argument_list|)
block|,
name|quint32
argument_list|(
argument|os2->ulUnicodeRange4
argument_list|)
block|}
decl_stmt|;
name|quint32
name|codePageRange
index|[
literal|2
index|]
init|=
block|{
name|quint32
argument_list|(
name|os2
operator|->
name|ulCodePageRange1
argument_list|)
block|,
name|quint32
argument_list|(
argument|os2->ulCodePageRange2
argument_list|)
block|}
decl_stmt|;
name|writingSystems
operator|=
name|QPlatformFontDatabase
operator|::
name|writingSystemsFromTrueTypeBits
argument_list|(
name|unicodeRange
argument_list|,
name|codePageRange
argument_list|)
expr_stmt|;
if|if
condition|(
name|os2
operator|->
name|usWeightClass
condition|)
block|{
name|weight
operator|=
name|QPlatformFontDatabase
operator|::
name|weightFromInteger
argument_list|(
name|os2
operator|->
name|usWeightClass
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|os2
operator|->
name|panose
index|[
literal|2
index|]
condition|)
block|{
name|int
name|w
init|=
name|os2
operator|->
name|panose
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|w
operator|<=
literal|1
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Thin
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|2
condition|)
name|weight
operator|=
name|QFont
operator|::
name|ExtraLight
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|3
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Light
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|5
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Normal
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|6
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Medium
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|7
condition|)
name|weight
operator|=
name|QFont
operator|::
name|DemiBold
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|8
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|9
condition|)
name|weight
operator|=
name|QFont
operator|::
name|ExtraBold
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|10
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Black
expr_stmt|;
block|}
block|}
name|QString
name|family
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|face
operator|->
name|family_name
argument_list|)
decl_stmt|;
name|FontFile
modifier|*
name|fontFile
init|=
operator|new
name|FontFile
decl_stmt|;
name|fontFile
operator|->
name|fileName
operator|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|fontFile
operator|->
name|indexValue
operator|=
name|index
expr_stmt|;
name|QFont
operator|::
name|Stretch
name|stretch
init|=
name|QFont
operator|::
name|Unstretched
decl_stmt|;
name|registerFont
argument_list|(
name|family
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|face
operator|->
name|style_name
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|weight
argument_list|,
name|style
argument_list|,
name|stretch
argument_list|,
literal|true
argument_list|,
literal|true
argument_list|,
literal|0
argument_list|,
name|fixedPitch
argument_list|,
name|writingSystems
argument_list|,
name|fontFile
argument_list|)
expr_stmt|;
name|families
operator|.
name|append
argument_list|(
name|family
argument_list|)
expr_stmt|;
name|FT_Done_Face
argument_list|(
name|face
argument_list|)
expr_stmt|;
operator|++
name|index
expr_stmt|;
block|}
do|while
condition|(
name|index
operator|<
name|numFaces
condition|)
do|;
return|return
name|families
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
