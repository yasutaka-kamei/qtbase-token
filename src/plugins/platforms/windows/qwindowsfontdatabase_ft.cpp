begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsfontdatabase_ft.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
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
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSettings>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_ft_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QFontDatabase>
end_include
begin_include
include|#
directive|include
file|<wchar.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|writingSystemFromScript
specifier|static
specifier|inline
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystemFromScript
parameter_list|(
specifier|const
name|QString
modifier|&
name|scriptName
parameter_list|)
block|{
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Western"
argument_list|)
operator|||
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Baltic"
argument_list|)
operator|||
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Central European"
argument_list|)
operator|||
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Turkish"
argument_list|)
operator|||
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Vietnamese"
argument_list|)
operator|||
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"OEM/Dos"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|Latin
return|;
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Thai"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|Thai
return|;
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Symbol"
argument_list|)
operator|||
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Other"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|Symbol
return|;
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"CHINESE_GB2312"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|SimplifiedChinese
return|;
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"CHINESE_BIG5"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|TraditionalChinese
return|;
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Cyrillic"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|Cyrillic
return|;
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Hangul"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|Korean
return|;
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Hebrew"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|Hebrew
return|;
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Greek"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|Greek
return|;
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Japanese"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|Japanese
return|;
if|if
condition|(
name|scriptName
operator|==
name|QStringLiteral
argument_list|(
literal|"Arabic"
argument_list|)
condition|)
return|return
name|QFontDatabase
operator|::
name|Arabic
return|;
return|return
name|QFontDatabase
operator|::
name|Any
return|;
block|}
end_function
begin_comment
comment|// convert 0 ~ 1000 integer to QFont::Weight
end_comment
begin_function
DECL|function|weightFromInteger
specifier|static
specifier|inline
name|QFont
operator|::
name|Weight
name|weightFromInteger
parameter_list|(
name|long
name|weight
parameter_list|)
block|{
if|if
condition|(
name|weight
operator|<
literal|400
condition|)
return|return
name|QFont
operator|::
name|Light
return|;
if|if
condition|(
name|weight
operator|<
literal|600
condition|)
return|return
name|QFont
operator|::
name|Normal
return|;
if|if
condition|(
name|weight
operator|<
literal|700
condition|)
return|return
name|QFont
operator|::
name|DemiBold
return|;
if|if
condition|(
name|weight
operator|<
literal|800
condition|)
return|return
name|QFont
operator|::
name|Bold
return|;
return|return
name|QFont
operator|::
name|Black
return|;
block|}
end_function
begin_function
DECL|function|createFontFile
specifier|static
name|FontFile
modifier|*
name|createFontFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|int
name|index
parameter_list|)
block|{
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
name|fileName
expr_stmt|;
name|fontFile
operator|->
name|indexValue
operator|=
name|index
expr_stmt|;
return|return
name|fontFile
return|;
block|}
end_function
begin_function_decl
specifier|extern
name|bool
name|localizedName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|QString
name|getEnglishName
parameter_list|(
specifier|const
name|QString
modifier|&
name|familyName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_GUI_EXPORT
name|void
name|qt_registerAliasToFontFamily
parameter_list|(
specifier|const
name|QString
modifier|&
name|familyName
parameter_list|,
specifier|const
name|QString
modifier|&
name|alias
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|addFontToDatabase
specifier|static
name|bool
name|addFontToDatabase
parameter_list|(
name|QString
name|familyName
parameter_list|,
specifier|const
name|QString
modifier|&
name|scriptName
parameter_list|,
specifier|const
name|TEXTMETRIC
modifier|*
name|textmetric
parameter_list|,
specifier|const
name|FONTSIGNATURE
modifier|*
name|signature
parameter_list|,
name|int
name|type
parameter_list|)
block|{
typedef|typedef
name|QPair
argument_list|<
name|QString
argument_list|,
name|QStringList
argument_list|>
name|FontKey
typedef|;
comment|// the "@family" fonts are just the same as "family". Ignore them.
if|if
condition|(
name|familyName
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'@'
argument_list|)
operator|||
name|familyName
operator|.
name|startsWith
argument_list|(
name|QStringLiteral
argument_list|(
literal|"WST_"
argument_list|)
argument_list|)
condition|)
return|return
literal|false
return|;
specifier|const
name|int
name|separatorPos
init|=
name|familyName
operator|.
name|indexOf
argument_list|(
name|QStringLiteral
argument_list|(
literal|"::"
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|faceName
init|=
name|separatorPos
operator|!=
operator|-
literal|1
condition|?
name|familyName
operator|.
name|left
argument_list|(
name|separatorPos
argument_list|)
else|:
name|familyName
decl_stmt|;
specifier|const
name|QString
name|fullName
init|=
name|separatorPos
operator|!=
operator|-
literal|1
condition|?
name|familyName
operator|.
name|mid
argument_list|(
name|separatorPos
operator|+
literal|2
argument_list|)
else|:
name|QString
argument_list|()
decl_stmt|;
specifier|static
specifier|const
name|int
name|SMOOTH_SCALABLE
init|=
literal|0xffff
decl_stmt|;
specifier|const
name|QString
name|foundryName
decl_stmt|;
comment|// No such concept.
specifier|const
name|NEWTEXTMETRIC
modifier|*
name|tm
init|=
operator|(
name|NEWTEXTMETRIC
operator|*
operator|)
name|textmetric
decl_stmt|;
specifier|const
name|bool
name|fixed
init|=
operator|!
operator|(
name|tm
operator|->
name|tmPitchAndFamily
operator|&
name|TMPF_FIXED_PITCH
operator|)
decl_stmt|;
specifier|const
name|bool
name|ttf
init|=
operator|(
name|tm
operator|->
name|tmPitchAndFamily
operator|&
name|TMPF_TRUETYPE
operator|)
decl_stmt|;
specifier|const
name|bool
name|scalable
init|=
name|tm
operator|->
name|tmPitchAndFamily
operator|&
operator|(
name|TMPF_VECTOR
operator||
name|TMPF_TRUETYPE
operator|)
decl_stmt|;
specifier|const
name|int
name|size
init|=
name|scalable
condition|?
name|SMOOTH_SCALABLE
else|:
name|tm
operator|->
name|tmHeight
decl_stmt|;
specifier|const
name|QFont
operator|::
name|Style
name|style
init|=
name|tm
operator|->
name|tmItalic
condition|?
name|QFont
operator|::
name|StyleItalic
else|:
name|QFont
operator|::
name|StyleNormal
decl_stmt|;
specifier|const
name|bool
name|antialias
init|=
literal|false
decl_stmt|;
specifier|const
name|QFont
operator|::
name|Weight
name|weight
init|=
name|weightFromInteger
argument_list|(
name|tm
operator|->
name|tmWeight
argument_list|)
decl_stmt|;
specifier|const
name|QFont
operator|::
name|Stretch
name|stretch
init|=
name|QFont
operator|::
name|Unstretched
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseFonts
operator|>
literal|2
condition|)
block|{
name|QDebug
name|nospace
init|=
name|qDebug
argument_list|()
operator|.
name|nospace
argument_list|()
decl_stmt|;
name|nospace
operator|<<
name|__FUNCTION__
operator|<<
name|faceName
operator|<<
name|fullName
operator|<<
name|scriptName
operator|<<
literal|"TTF="
operator|<<
name|ttf
expr_stmt|;
if|if
condition|(
name|type
operator|&
name|DEVICE_FONTTYPE
condition|)
name|nospace
operator|<<
literal|" DEVICE"
expr_stmt|;
if|if
condition|(
name|type
operator|&
name|RASTER_FONTTYPE
condition|)
name|nospace
operator|<<
literal|" RASTER"
expr_stmt|;
if|if
condition|(
name|type
operator|&
name|TRUETYPE_FONTTYPE
condition|)
name|nospace
operator|<<
literal|" TRUETYPE"
expr_stmt|;
name|nospace
operator|<<
literal|" scalable="
operator|<<
name|scalable
operator|<<
literal|" Size="
operator|<<
name|size
operator|<<
literal|" Style="
operator|<<
name|style
operator|<<
literal|" Weight="
operator|<<
name|weight
operator|<<
literal|" stretch="
operator|<<
name|stretch
expr_stmt|;
block|}
name|QString
name|englishName
decl_stmt|;
if|if
condition|(
name|ttf
operator|&&
name|localizedName
argument_list|(
name|faceName
argument_list|)
condition|)
name|englishName
operator|=
name|getEnglishName
argument_list|(
name|faceName
argument_list|)
expr_stmt|;
name|QSupportedWritingSystems
name|writingSystems
decl_stmt|;
if|if
condition|(
name|type
operator|&
name|TRUETYPE_FONTTYPE
condition|)
block|{
name|quint32
name|unicodeRange
index|[
literal|4
index|]
init|=
block|{
name|signature
operator|->
name|fsUsb
index|[
literal|0
index|]
block|,
name|signature
operator|->
name|fsUsb
index|[
literal|1
index|]
block|,
name|signature
operator|->
name|fsUsb
index|[
literal|2
index|]
block|,
name|signature
operator|->
name|fsUsb
index|[
literal|3
index|]
block|}
decl_stmt|;
name|quint32
name|codePageRange
index|[
literal|2
index|]
init|=
block|{
name|signature
operator|->
name|fsCsb
index|[
literal|0
index|]
block|,
name|signature
operator|->
name|fsCsb
index|[
literal|1
index|]
block|}
decl_stmt|;
name|writingSystems
operator|=
name|QBasicFontDatabase
operator|::
name|determineWritingSystemsFromTrueTypeBits
argument_list|(
name|unicodeRange
argument_list|,
name|codePageRange
argument_list|)
expr_stmt|;
comment|// ### Hack to work around problem with Thai text on Windows 7. Segoe UI contains
comment|// the symbol for Baht, and Windows thus reports that it supports the Thai script.
comment|// Since it's the default UI font on this platform, most widgets will be unable to
comment|// display Thai text by default. As a temporary work around, we special case Segoe UI
comment|// and remove the Thai script from its list of supported writing systems.
if|if
condition|(
name|writingSystems
operator|.
name|supported
argument_list|(
name|QFontDatabase
operator|::
name|Thai
argument_list|)
operator|&&
name|faceName
operator|==
name|QStringLiteral
argument_list|(
literal|"Segoe UI"
argument_list|)
condition|)
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|Thai
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|QFontDatabase
operator|::
name|WritingSystem
name|ws
init|=
name|writingSystemFromScript
argument_list|(
name|scriptName
argument_list|)
decl_stmt|;
if|if
condition|(
name|ws
operator|!=
name|QFontDatabase
operator|::
name|Any
condition|)
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|ws
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QSettings
name|fontRegistry
argument_list|(
name|QStringLiteral
argument_list|(
literal|"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts"
argument_list|)
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
specifier|static
name|QVector
argument_list|<
name|FontKey
argument_list|>
name|allFonts
decl_stmt|;
if|if
condition|(
name|allFonts
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QStringList
name|allKeys
init|=
name|fontRegistry
operator|.
name|allKeys
argument_list|()
decl_stmt|;
name|allFonts
operator|.
name|reserve
argument_list|(
name|allKeys
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|trueType
init|=
name|QStringLiteral
argument_list|(
literal|"(TrueType)"
argument_list|)
decl_stmt|;
specifier|const
name|QRegExp
name|sizeListMatch
argument_list|(
name|QStringLiteral
argument_list|(
literal|"\\s(\\d+,)+\\d+"
argument_list|)
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|key
decl|,
name|allKeys
control|)
block|{
name|QString
name|realKey
init|=
name|key
decl_stmt|;
name|realKey
operator|.
name|remove
argument_list|(
name|trueType
argument_list|)
expr_stmt|;
name|realKey
operator|.
name|remove
argument_list|(
name|sizeListMatch
argument_list|)
expr_stmt|;
name|QStringList
name|fonts
decl_stmt|;
specifier|const
name|QStringList
name|fontNames
init|=
name|realKey
operator|.
name|trimmed
argument_list|()
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'&'
argument_list|)
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|fontName
decl|,
name|fontNames
control|)
name|fonts
operator|.
name|push_back
argument_list|(
name|fontName
operator|.
name|trimmed
argument_list|()
argument_list|)
expr_stmt|;
name|allFonts
operator|.
name|push_back
argument_list|(
name|FontKey
argument_list|(
name|key
argument_list|,
name|fonts
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|QString
name|value
decl_stmt|;
name|int
name|index
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|k
init|=
literal|0
init|;
name|k
operator|<
name|allFonts
operator|.
name|size
argument_list|()
condition|;
operator|++
name|k
control|)
block|{
specifier|const
name|FontKey
modifier|&
name|fontKey
init|=
name|allFonts
operator|.
name|at
argument_list|(
name|k
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
name|fontKey
operator|.
name|second
operator|.
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
modifier|&
name|font
init|=
name|fontKey
operator|.
name|second
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|font
operator|==
name|faceName
operator|||
name|fullName
operator|==
name|font
operator|||
name|englishName
operator|==
name|font
condition|)
block|{
name|value
operator|=
name|fontRegistry
operator|.
name|value
argument_list|(
name|fontKey
operator|.
name|first
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|index
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|value
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
block|}
if|if
condition|(
name|value
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|QDir
operator|::
name|isAbsolutePath
argument_list|(
name|value
argument_list|)
condition|)
name|value
operator|.
name|prepend
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"windir"
argument_list|)
operator|+
literal|"\\Fonts\\"
argument_list|)
argument_list|)
expr_stmt|;
name|QPlatformFontDatabase
operator|::
name|registerFont
argument_list|(
name|faceName
argument_list|,
name|foundryName
argument_list|,
name|weight
argument_list|,
name|style
argument_list|,
name|stretch
argument_list|,
name|antialias
argument_list|,
name|scalable
argument_list|,
name|size
argument_list|,
name|fixed
argument_list|,
name|writingSystems
argument_list|,
name|createFontFile
argument_list|(
name|value
argument_list|,
name|index
argument_list|)
argument_list|)
expr_stmt|;
comment|// add fonts windows can generate for us:
if|if
condition|(
name|weight
operator|<=
name|QFont
operator|::
name|DemiBold
condition|)
name|QPlatformFontDatabase
operator|::
name|registerFont
argument_list|(
name|faceName
argument_list|,
name|foundryName
argument_list|,
name|QFont
operator|::
name|Bold
argument_list|,
name|style
argument_list|,
name|stretch
argument_list|,
name|antialias
argument_list|,
name|scalable
argument_list|,
name|size
argument_list|,
name|fixed
argument_list|,
name|writingSystems
argument_list|,
name|createFontFile
argument_list|(
name|value
argument_list|,
name|index
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|style
operator|!=
name|QFont
operator|::
name|StyleItalic
condition|)
name|QPlatformFontDatabase
operator|::
name|registerFont
argument_list|(
name|faceName
argument_list|,
name|foundryName
argument_list|,
name|weight
argument_list|,
name|QFont
operator|::
name|StyleItalic
argument_list|,
name|stretch
argument_list|,
name|antialias
argument_list|,
name|scalable
argument_list|,
name|size
argument_list|,
name|fixed
argument_list|,
name|writingSystems
argument_list|,
name|createFontFile
argument_list|(
name|value
argument_list|,
name|index
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|weight
operator|<=
name|QFont
operator|::
name|DemiBold
operator|&&
name|style
operator|!=
name|QFont
operator|::
name|StyleItalic
condition|)
name|QPlatformFontDatabase
operator|::
name|registerFont
argument_list|(
name|faceName
argument_list|,
name|foundryName
argument_list|,
name|QFont
operator|::
name|Bold
argument_list|,
name|QFont
operator|::
name|StyleItalic
argument_list|,
name|stretch
argument_list|,
name|antialias
argument_list|,
name|scalable
argument_list|,
name|size
argument_list|,
name|fixed
argument_list|,
name|writingSystems
argument_list|,
name|createFontFile
argument_list|(
name|value
argument_list|,
name|index
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|englishName
operator|.
name|isEmpty
argument_list|()
condition|)
name|qt_registerAliasToFontFamily
argument_list|(
name|faceName
argument_list|,
name|englishName
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|storeFont
specifier|static
name|int
name|CALLBACK
name|storeFont
parameter_list|(
name|ENUMLOGFONTEX
modifier|*
name|f
parameter_list|,
name|NEWTEXTMETRICEX
modifier|*
name|textmetric
parameter_list|,
name|int
name|type
parameter_list|,
name|LPARAM
name|namesSetIn
parameter_list|)
block|{
typedef|typedef
name|QSet
argument_list|<
name|QString
argument_list|>
name|StringSet
typedef|;
specifier|const
name|QString
name|familyName
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|f
operator|->
name|elfLogFont
operator|.
name|lfFaceName
argument_list|)
operator|+
name|QStringLiteral
argument_list|(
literal|"::"
argument_list|)
operator|+
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|f
operator|->
name|elfFullName
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|script
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|f
operator|->
name|elfScript
argument_list|)
decl_stmt|;
specifier|const
name|FONTSIGNATURE
name|signature
init|=
name|textmetric
operator|->
name|ntmFontSig
decl_stmt|;
comment|// NEWTEXTMETRICEX is a NEWTEXTMETRIC, which according to the documentation is
comment|// identical to a TEXTMETRIC except for the last four members, which we don't use
comment|// anyway
if|if
condition|(
name|addFontToDatabase
argument_list|(
name|familyName
argument_list|,
name|script
argument_list|,
operator|(
name|TEXTMETRIC
operator|*
operator|)
name|textmetric
argument_list|,
operator|&
name|signature
argument_list|,
name|type
argument_list|)
condition|)
cast|reinterpret_cast
argument_list|<
name|StringSet
operator|*
argument_list|>
argument_list|(
name|namesSetIn
argument_list|)
operator|->
name|insert
argument_list|(
name|familyName
argument_list|)
expr_stmt|;
comment|// keep on enumerating
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|populateFontDatabase
name|void
name|QWindowsFontDatabaseFT
operator|::
name|populateFontDatabase
parameter_list|()
block|{
name|m_families
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QPlatformFontDatabase
operator|::
name|populateFontDatabase
argument_list|()
expr_stmt|;
name|populate
argument_list|()
expr_stmt|;
comment|// Called multiple times.
comment|// Work around EnumFontFamiliesEx() not listing the system font, see below.
specifier|const
name|QString
name|sysFontFamily
init|=
name|QGuiApplication
operator|::
name|font
argument_list|()
operator|.
name|family
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|m_families
operator|.
name|contains
argument_list|(
name|sysFontFamily
argument_list|)
condition|)
name|populate
argument_list|(
name|sysFontFamily
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \brief Populate font database using EnumFontFamiliesEx().      Normally, leaving the name empty should enumerate     all fonts, however, system fonts like "MS Shell Dlg 2"     are only found when specifying the name explicitly. */
end_comment
begin_function
DECL|function|populate
name|void
name|QWindowsFontDatabaseFT
operator|::
name|populate
parameter_list|(
specifier|const
name|QString
modifier|&
name|family
parameter_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseFonts
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|m_families
operator|.
name|size
argument_list|()
operator|<<
name|family
expr_stmt|;
name|HDC
name|dummy
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|LOGFONT
name|lf
decl_stmt|;
name|lf
operator|.
name|lfCharSet
operator|=
name|DEFAULT_CHARSET
expr_stmt|;
if|if
condition|(
name|family
operator|.
name|size
argument_list|()
operator|>=
name|LF_FACESIZE
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Unable to enumerate family '%s'."
argument_list|,
name|__FUNCTION__
argument_list|,
name|qPrintable
argument_list|(
name|family
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|wmemcpy
argument_list|(
name|lf
operator|.
name|lfFaceName
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|family
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|family
operator|.
name|size
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
name|lf
operator|.
name|lfPitchAndFamily
operator|=
literal|0
expr_stmt|;
name|EnumFontFamiliesEx
argument_list|(
name|dummy
argument_list|,
operator|&
name|lf
argument_list|,
operator|(
name|FONTENUMPROC
operator|)
name|storeFont
argument_list|,
operator|(
name|LPARAM
operator|)
operator|&
name|m_families
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|dummy
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fontEngine
name|QFontEngine
modifier|*
name|QWindowsFontDatabaseFT
operator|::
name|fontEngine
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fontDef
parameter_list|,
name|QUnicodeTables
operator|::
name|Script
name|script
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|QFontEngine
modifier|*
name|fe
init|=
name|QBasicFontDatabase
operator|::
name|fontEngine
argument_list|(
name|fontDef
argument_list|,
name|script
argument_list|,
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseFonts
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"FONTDEF"
operator|<<
comment|/*fontDef<<*/
name|script
operator|<<
name|fe
operator|<<
name|handle
expr_stmt|;
return|return
name|fe
return|;
block|}
end_function
begin_function
DECL|function|fontEngine
name|QFontEngine
modifier|*
name|QWindowsFontDatabaseFT
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
name|QFontEngine
modifier|*
name|fe
init|=
name|QPlatformFontDatabase
operator|::
name|fontEngine
argument_list|(
name|fontData
argument_list|,
name|pixelSize
argument_list|,
name|hintingPreference
argument_list|)
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseFonts
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"FONTDATA"
operator|<<
name|fontData
operator|<<
name|pixelSize
operator|<<
name|hintingPreference
operator|<<
name|fe
expr_stmt|;
return|return
name|fe
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|other_tryFonts
specifier|static
specifier|const
name|char
modifier|*
name|other_tryFonts
index|[]
init|=
block|{
literal|"Arial"
block|,
literal|"MS UI Gothic"
block|,
literal|"Gulim"
block|,
literal|"SimSun"
block|,
literal|"PMingLiU"
block|,
literal|"Arial Unicode MS"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|jp_tryFonts
specifier|static
specifier|const
name|char
modifier|*
name|jp_tryFonts
index|[]
init|=
block|{
literal|"MS UI Gothic"
block|,
literal|"Arial"
block|,
literal|"Gulim"
block|,
literal|"SimSun"
block|,
literal|"PMingLiU"
block|,
literal|"Arial Unicode MS"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ch_CN_tryFonts
specifier|static
specifier|const
name|char
modifier|*
name|ch_CN_tryFonts
index|[]
init|=
block|{
literal|"SimSun"
block|,
literal|"Arial"
block|,
literal|"PMingLiU"
block|,
literal|"Gulim"
block|,
literal|"MS UI Gothic"
block|,
literal|"Arial Unicode MS"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ch_TW_tryFonts
specifier|static
specifier|const
name|char
modifier|*
name|ch_TW_tryFonts
index|[]
init|=
block|{
literal|"PMingLiU"
block|,
literal|"Arial"
block|,
literal|"SimSun"
block|,
literal|"Gulim"
block|,
literal|"MS UI Gothic"
block|,
literal|"Arial Unicode MS"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|kr_tryFonts
specifier|static
specifier|const
name|char
modifier|*
name|kr_tryFonts
index|[]
init|=
block|{
literal|"Gulim"
block|,
literal|"Arial"
block|,
literal|"PMingLiU"
block|,
literal|"SimSun"
block|,
literal|"MS UI Gothic"
block|,
literal|"Arial Unicode MS"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|tryFonts
specifier|static
specifier|const
name|char
modifier|*
modifier|*
name|tryFonts
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|fallbacksForFamily
name|QStringList
name|QWindowsFontDatabaseFT
operator|::
name|fallbacksForFamily
parameter_list|(
specifier|const
name|QString
name|family
parameter_list|,
specifier|const
name|QFont
operator|::
name|Style
modifier|&
name|style
parameter_list|,
specifier|const
name|QFont
operator|::
name|StyleHint
modifier|&
name|styleHint
parameter_list|,
specifier|const
name|QUnicodeTables
operator|::
name|Script
modifier|&
name|script
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|script
operator|==
name|QUnicodeTables
operator|::
name|Common
condition|)
block|{
comment|//&& !(request.styleStrategy& QFont::NoFontMerging)) {
name|QFontDatabase
name|db
decl_stmt|;
if|if
condition|(
operator|!
name|db
operator|.
name|writingSystems
argument_list|(
name|family
argument_list|)
operator|.
name|contains
argument_list|(
name|QFontDatabase
operator|::
name|Symbol
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|tryFonts
condition|)
block|{
name|LANGID
name|lid
init|=
name|GetUserDefaultLangID
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|lid
operator|&
literal|0xff
condition|)
block|{
case|case
name|LANG_CHINESE
case|:
comment|// Chinese (Taiwan)
if|if
condition|(
name|lid
operator|==
literal|0x0804
condition|)
comment|// Taiwan
name|tryFonts
operator|=
name|ch_TW_tryFonts
expr_stmt|;
else|else
name|tryFonts
operator|=
name|ch_CN_tryFonts
expr_stmt|;
break|break;
case|case
name|LANG_JAPANESE
case|:
name|tryFonts
operator|=
name|jp_tryFonts
expr_stmt|;
break|break;
case|case
name|LANG_KOREAN
case|:
name|tryFonts
operator|=
name|kr_tryFonts
expr_stmt|;
break|break;
default|default:
name|tryFonts
operator|=
name|other_tryFonts
expr_stmt|;
break|break;
block|}
block|}
name|QStringList
name|list
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|tf
init|=
name|tryFonts
decl_stmt|;
while|while
condition|(
name|tf
operator|&&
operator|*
name|tf
condition|)
block|{
if|if
condition|(
name|m_families
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
operator|*
name|tf
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
operator|*
name|tf
argument_list|)
expr_stmt|;
operator|++
name|tf
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|list
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|list
return|;
block|}
block|}
name|QStringList
name|result
init|=
name|QPlatformFontDatabase
operator|::
name|fallbacksForFamily
argument_list|(
name|family
argument_list|,
name|style
argument_list|,
name|styleHint
argument_list|,
name|script
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|result
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|result
return|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseFonts
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|family
operator|<<
name|style
operator|<<
name|styleHint
operator|<<
name|script
operator|<<
name|result
operator|<<
name|m_families
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|fontDir
name|QString
name|QWindowsFontDatabaseFT
operator|::
name|fontDir
parameter_list|()
specifier|const
block|{
specifier|const
name|QString
name|result
init|=
name|QLatin1String
argument_list|(
name|qgetenv
argument_list|(
literal|"windir"
argument_list|)
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|"/Fonts"
argument_list|)
decl_stmt|;
comment|//QPlatformFontDatabase::fontDir();
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseFonts
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|systemFont
name|HFONT
name|QWindowsFontDatabaseFT
operator|::
name|systemFont
parameter_list|()
block|{
specifier|static
specifier|const
name|HFONT
name|stock_sysfont
init|=
operator|(
name|HFONT
operator|)
name|GetStockObject
argument_list|(
name|SYSTEM_FONT
argument_list|)
decl_stmt|;
return|return
name|stock_sysfont
return|;
block|}
end_function
begin_comment
comment|// Creation functions
end_comment
begin_function
DECL|function|scriptRequiresOpenType
specifier|static
specifier|inline
name|bool
name|scriptRequiresOpenType
parameter_list|(
name|int
name|script
parameter_list|)
block|{
return|return
operator|(
operator|(
name|script
operator|>=
name|QUnicodeTables
operator|::
name|Syriac
operator|&&
name|script
operator|<=
name|QUnicodeTables
operator|::
name|Sinhala
operator|)
operator|||
name|script
operator|==
name|QUnicodeTables
operator|::
name|Khmer
operator|||
name|script
operator|==
name|QUnicodeTables
operator|::
name|Nko
operator|)
return|;
block|}
end_function
begin_function
DECL|function|verticalDPI
specifier|static
specifier|inline
name|int
name|verticalDPI
parameter_list|()
block|{
return|return
name|GetDeviceCaps
argument_list|(
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|displayContext
argument_list|()
argument_list|,
name|LOGPIXELSY
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|defaultFont
name|QFont
name|QWindowsFontDatabaseFT
operator|::
name|defaultFont
parameter_list|()
specifier|const
block|{
return|return
name|QWindowsFontDatabase
operator|::
name|systemDefaultFont
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|LOGFONT_to_QFont
name|QFont
name|QWindowsFontDatabaseFT
operator|::
name|LOGFONT_to_QFont
parameter_list|(
specifier|const
name|LOGFONT
modifier|&
name|logFont
parameter_list|,
name|int
name|verticalDPI_In
parameter_list|)
block|{
if|if
condition|(
name|verticalDPI_In
operator|<=
literal|0
condition|)
name|verticalDPI_In
operator|=
name|verticalDPI
argument_list|()
expr_stmt|;
name|QFont
name|qFont
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|logFont
operator|.
name|lfFaceName
argument_list|)
argument_list|)
decl_stmt|;
name|qFont
operator|.
name|setItalic
argument_list|(
name|logFont
operator|.
name|lfItalic
argument_list|)
expr_stmt|;
if|if
condition|(
name|logFont
operator|.
name|lfWeight
operator|!=
name|FW_DONTCARE
condition|)
name|qFont
operator|.
name|setWeight
argument_list|(
name|weightFromInteger
argument_list|(
name|logFont
operator|.
name|lfWeight
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|logFontHeight
init|=
name|qAbs
argument_list|(
name|logFont
operator|.
name|lfHeight
argument_list|)
decl_stmt|;
name|qFont
operator|.
name|setPointSizeF
argument_list|(
name|logFontHeight
operator|*
literal|72.0
operator|/
name|qreal
argument_list|(
name|verticalDPI_In
argument_list|)
argument_list|)
expr_stmt|;
name|qFont
operator|.
name|setUnderline
argument_list|(
name|logFont
operator|.
name|lfUnderline
argument_list|)
expr_stmt|;
name|qFont
operator|.
name|setOverline
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|qFont
operator|.
name|setStrikeOut
argument_list|(
name|logFont
operator|.
name|lfStrikeOut
argument_list|)
expr_stmt|;
return|return
name|qFont
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
