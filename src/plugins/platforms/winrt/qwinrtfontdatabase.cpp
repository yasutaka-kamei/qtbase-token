begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrtfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WINRT_USE_DWRITE
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/QUuid>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_ft_p.h>
end_include
begin_include
include|#
directive|include
file|<dwrite_1.h>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_WINRT_USE_DWRITE
end_comment
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|fontDir
name|QString
name|QWinRTFontDatabase
operator|::
name|fontDir
parameter_list|()
specifier|const
block|{
name|QString
name|fontDirectory
init|=
name|QBasicFontDatabase
operator|::
name|fontDir
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|fontDirectory
argument_list|)
condition|)
block|{
comment|// Fall back to app directory + fonts, and just app directory after that
specifier|const
name|QString
name|applicationDirPath
init|=
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
decl_stmt|;
name|fontDirectory
operator|=
name|applicationDirPath
operator|+
name|QLatin1String
argument_list|(
literal|"/fonts"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|fontDirectory
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_WINRT_USE_DWRITE
if|if
condition|(
name|m_fontFamilies
operator|.
name|isEmpty
argument_list|()
condition|)
endif|#
directive|endif
name|qWarning
argument_list|(
literal|"No fonts directory found in application package."
argument_list|)
expr_stmt|;
name|fontDirectory
operator|=
name|applicationDirPath
expr_stmt|;
block|}
block|}
return|return
name|fontDirectory
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WINRT_USE_DWRITE
end_ifdef
begin_destructor
DECL|function|~QWinRTFontDatabase
name|QWinRTFontDatabase
operator|::
name|~
name|QWinRTFontDatabase
parameter_list|()
block|{
foreach|foreach
control|(
name|IDWriteFontFile
modifier|*
name|fontFile
decl|,
name|m_fonts
operator|.
name|keys
argument_list|()
control|)
name|fontFile
operator|->
name|Release
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|IDWriteFontFamily
modifier|*
name|fontFamily
decl|,
name|m_fontFamilies
control|)
name|fontFamily
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|defaultFont
name|QFont
name|QWinRTFontDatabase
operator|::
name|defaultFont
parameter_list|()
specifier|const
block|{
return|return
name|QFont
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Segoe UI"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|populateFontDatabase
name|void
name|QWinRTFontDatabase
operator|::
name|populateFontDatabase
parameter_list|()
block|{
name|ComPtr
argument_list|<
name|IDWriteFactory1
argument_list|>
name|factory
decl_stmt|;
name|HRESULT
name|hr
init|=
name|DWriteCreateFactory
argument_list|(
name|DWRITE_FACTORY_TYPE_ISOLATED
argument_list|,
name|__uuidof
argument_list|(
name|IDWriteFactory1
argument_list|)
argument_list|,
operator|&
name|factory
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to create DirectWrite factory: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QBasicFontDatabase
operator|::
name|populateFontDatabase
argument_list|()
expr_stmt|;
return|return;
block|}
name|ComPtr
argument_list|<
name|IDWriteFontCollection
argument_list|>
name|fontCollection
decl_stmt|;
name|hr
operator|=
name|factory
operator|->
name|GetSystemFontCollection
argument_list|(
operator|&
name|fontCollection
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to open system font collection: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QBasicFontDatabase
operator|::
name|populateFontDatabase
argument_list|()
expr_stmt|;
return|return;
block|}
name|int
name|fontFamilyCount
init|=
name|fontCollection
operator|->
name|GetFontFamilyCount
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
name|fontFamilyCount
condition|;
operator|++
name|i
control|)
block|{
name|ComPtr
argument_list|<
name|IDWriteFontFamily
argument_list|>
name|fontFamily
decl_stmt|;
name|hr
operator|=
name|fontCollection
operator|->
name|GetFontFamily
argument_list|(
name|i
argument_list|,
operator|&
name|fontFamily
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font family: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|ComPtr
argument_list|<
name|IDWriteLocalizedStrings
argument_list|>
name|names
decl_stmt|;
name|hr
operator|=
name|fontFamily
operator|->
name|GetFamilyNames
argument_list|(
operator|&
name|names
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font family names: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|quint32
name|familyNameLength
decl_stmt|;
name|hr
operator|=
name|names
operator|->
name|GetStringLength
argument_list|(
literal|0
argument_list|,
operator|&
name|familyNameLength
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get family name length: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|QVector
argument_list|<
name|wchar_t
argument_list|>
name|familyBuffer
argument_list|(
name|familyNameLength
operator|+
literal|1
argument_list|)
decl_stmt|;
name|hr
operator|=
name|names
operator|->
name|GetString
argument_list|(
literal|0
argument_list|,
name|familyBuffer
operator|.
name|data
argument_list|()
argument_list|,
name|familyBuffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to create font family name: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|QString
name|familyName
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|familyBuffer
operator|.
name|data
argument_list|()
argument_list|,
name|familyNameLength
argument_list|)
decl_stmt|;
name|m_fontFamilies
operator|.
name|insert
argument_list|(
name|familyName
argument_list|,
name|fontFamily
operator|.
name|Detach
argument_list|()
argument_list|)
expr_stmt|;
name|registerFontFamily
argument_list|(
name|familyName
argument_list|)
expr_stmt|;
block|}
name|QBasicFontDatabase
operator|::
name|populateFontDatabase
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|populateFamily
name|void
name|QWinRTFontDatabase
operator|::
name|populateFamily
parameter_list|(
specifier|const
name|QString
modifier|&
name|familyName
parameter_list|)
block|{
name|IDWriteFontFamily
modifier|*
name|fontFamily
init|=
name|m_fontFamilies
operator|.
name|value
argument_list|(
name|familyName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fontFamily
condition|)
block|{
name|qWarning
argument_list|(
literal|"The font family %s was not found."
argument_list|,
name|qPrintable
argument_list|(
name|familyName
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|bool
name|fontRegistered
init|=
literal|false
decl_stmt|;
specifier|const
name|int
name|fontCount
init|=
name|fontFamily
operator|->
name|GetFontCount
argument_list|()
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
name|fontCount
condition|;
operator|++
name|j
control|)
block|{
name|ComPtr
argument_list|<
name|IDWriteFont
argument_list|>
name|font
decl_stmt|;
name|HRESULT
name|hr
init|=
name|fontFamily
operator|->
name|GetFont
argument_list|(
name|j
argument_list|,
operator|&
name|font
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|// Skip simulated faces
if|if
condition|(
name|font
operator|->
name|GetSimulations
argument_list|()
operator|!=
name|DWRITE_FONT_SIMULATIONS_NONE
condition|)
continue|continue;
name|ComPtr
argument_list|<
name|IDWriteFontFace
argument_list|>
name|baseFontFace
decl_stmt|;
name|hr
operator|=
name|font
operator|->
name|CreateFontFace
argument_list|(
operator|&
name|baseFontFace
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to create base font face: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|ComPtr
argument_list|<
name|IDWriteFontFace1
argument_list|>
name|fontFace
decl_stmt|;
name|hr
operator|=
name|baseFontFace
operator|.
name|As
argument_list|(
operator|&
name|fontFace
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to create font face: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|// We can't deal with multi-file fonts
name|quint32
name|fileCount
decl_stmt|;
name|hr
operator|=
name|fontFace
operator|->
name|GetFiles
argument_list|(
operator|&
name|fileCount
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font file count: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|fileCount
operator|!=
literal|1
condition|)
continue|continue;
name|ComPtr
argument_list|<
name|IDWriteLocalizedStrings
argument_list|>
name|informationalStrings
decl_stmt|;
name|BOOL
name|exists
decl_stmt|;
name|hr
operator|=
name|font
operator|->
name|GetInformationalStrings
argument_list|(
name|DWRITE_INFORMATIONAL_STRING_MANUFACTURER
argument_list|,
operator|&
name|informationalStrings
argument_list|,
operator|&
name|exists
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font foundry: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|QString
name|foundryName
decl_stmt|;
if|if
condition|(
name|exists
condition|)
block|{
name|quint32
name|length
decl_stmt|;
name|hr
operator|=
name|informationalStrings
operator|->
name|GetStringLength
argument_list|(
literal|0
argument_list|,
operator|&
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"Unable to get foundry name length: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|QVector
argument_list|<
name|wchar_t
argument_list|>
name|buffer
argument_list|(
name|length
operator|+
literal|1
argument_list|)
decl_stmt|;
name|hr
operator|=
name|informationalStrings
operator|->
name|GetString
argument_list|(
literal|0
argument_list|,
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"Unable to get foundry name: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
condition|)
name|foundryName
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
block|}
name|QFont
operator|::
name|Weight
name|weight
decl_stmt|;
switch|switch
condition|(
name|font
operator|->
name|GetWeight
argument_list|()
condition|)
block|{
case|case
name|DWRITE_FONT_WEIGHT_THIN
case|:
case|case
name|DWRITE_FONT_WEIGHT_EXTRA_LIGHT
case|:
case|case
name|DWRITE_FONT_WEIGHT_LIGHT
case|:
case|case
name|DWRITE_FONT_WEIGHT_SEMI_LIGHT
case|:
name|weight
operator|=
name|QFont
operator|::
name|Light
expr_stmt|;
break|break;
default|default:
case|case
name|DWRITE_FONT_WEIGHT_NORMAL
case|:
case|case
name|DWRITE_FONT_WEIGHT_MEDIUM
case|:
name|weight
operator|=
name|QFont
operator|::
name|Normal
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_WEIGHT_DEMI_BOLD
case|:
name|weight
operator|=
name|QFont
operator|::
name|DemiBold
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_WEIGHT_BOLD
case|:
case|case
name|DWRITE_FONT_WEIGHT_EXTRA_BOLD
case|:
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_WEIGHT_BLACK
case|:
case|case
name|DWRITE_FONT_WEIGHT_EXTRA_BLACK
case|:
name|weight
operator|=
name|QFont
operator|::
name|Black
expr_stmt|;
break|break;
block|}
name|QFont
operator|::
name|Style
name|style
decl_stmt|;
switch|switch
condition|(
name|font
operator|->
name|GetStyle
argument_list|()
condition|)
block|{
default|default:
case|case
name|DWRITE_FONT_STYLE_NORMAL
case|:
name|style
operator|=
name|QFont
operator|::
name|StyleNormal
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_STYLE_OBLIQUE
case|:
name|style
operator|=
name|QFont
operator|::
name|StyleOblique
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_STYLE_ITALIC
case|:
name|style
operator|=
name|QFont
operator|::
name|StyleItalic
expr_stmt|;
break|break;
block|}
name|QFont
operator|::
name|Stretch
name|stretch
decl_stmt|;
switch|switch
condition|(
name|font
operator|->
name|GetStretch
argument_list|()
condition|)
block|{
default|default:
case|case
name|DWRITE_FONT_STRETCH_UNDEFINED
case|:
case|case
name|DWRITE_FONT_STRETCH_NORMAL
case|:
name|stretch
operator|=
name|QFont
operator|::
name|Unstretched
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_STRETCH_ULTRA_CONDENSED
case|:
name|stretch
operator|=
name|QFont
operator|::
name|UltraCondensed
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_STRETCH_EXTRA_CONDENSED
case|:
name|stretch
operator|=
name|QFont
operator|::
name|ExtraCondensed
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_STRETCH_CONDENSED
case|:
name|stretch
operator|=
name|QFont
operator|::
name|Condensed
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_STRETCH_SEMI_CONDENSED
case|:
name|stretch
operator|=
name|QFont
operator|::
name|SemiCondensed
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_STRETCH_SEMI_EXPANDED
case|:
name|stretch
operator|=
name|QFont
operator|::
name|SemiExpanded
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_STRETCH_EXPANDED
case|:
name|stretch
operator|=
name|QFont
operator|::
name|Expanded
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_STRETCH_EXTRA_EXPANDED
case|:
name|stretch
operator|=
name|QFont
operator|::
name|ExtraExpanded
expr_stmt|;
break|break;
case|case
name|DWRITE_FONT_STRETCH_ULTRA_EXPANDED
case|:
name|stretch
operator|=
name|QFont
operator|::
name|UltraExpanded
expr_stmt|;
break|break;
block|}
specifier|const
name|bool
name|fixedPitch
init|=
name|fontFace
operator|->
name|IsMonospacedFont
argument_list|()
decl_stmt|;
name|quint32
name|unicodeRange
index|[
literal|4
index|]
decl_stmt|;
name|quint32
name|actualRangeCount
decl_stmt|;
name|hr
operator|=
name|fontFace
operator|->
name|GetUnicodeRanges
argument_list|(
literal|2
argument_list|,
cast|reinterpret_cast
argument_list|<
name|DWRITE_UNICODE_RANGE
operator|*
argument_list|>
argument_list|(
name|unicodeRange
argument_list|)
argument_list|,
operator|&
name|actualRangeCount
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
operator|&&
name|hr
operator|!=
name|E_NOT_SUFFICIENT_BUFFER
condition|)
block|{
comment|// Ignore insufficient buffer; we only need 4 indices
name|qWarning
argument_list|(
literal|"Unable to get font unicode range: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|quint32
name|codePageRange
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|QSupportedWritingSystems
name|writingSystems
init|=
name|QPlatformFontDatabase
operator|::
name|writingSystemsFromTrueTypeBits
argument_list|(
name|unicodeRange
argument_list|,
name|codePageRange
argument_list|)
decl_stmt|;
name|IDWriteFontFile
modifier|*
name|fontFile
decl_stmt|;
name|hr
operator|=
name|fontFace
operator|->
name|GetFiles
argument_list|(
operator|&
name|fileCount
argument_list|,
operator|&
name|fontFile
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font file: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|FontDescription
name|description
init|=
block|{
name|fontFace
operator|->
name|GetIndex
argument_list|()
block|,
name|QUuid
operator|::
name|createUuid
argument_list|()
operator|.
name|toByteArray
argument_list|()
block|}
decl_stmt|;
name|m_fonts
operator|.
name|insert
argument_list|(
name|fontFile
argument_list|,
name|description
argument_list|)
expr_stmt|;
name|registerFont
argument_list|(
name|familyName
argument_list|,
name|QString
argument_list|()
argument_list|,
name|foundryName
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
name|fontRegistered
operator|=
literal|true
expr_stmt|;
block|}
comment|// Always populate something to avoid an assert
if|if
condition|(
operator|!
name|fontRegistered
condition|)
block|{
name|registerFont
argument_list|(
name|familyName
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QFont
operator|::
name|Normal
argument_list|,
name|QFont
operator|::
name|StyleNormal
argument_list|,
name|QFont
operator|::
name|Unstretched
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|,
literal|0
argument_list|,
literal|false
argument_list|,
name|QSupportedWritingSystems
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fontEngine
name|QFontEngine
modifier|*
name|QWinRTFontDatabase
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
name|handle
parameter_list|)
block|{
if|if
condition|(
operator|!
name|handle
condition|)
comment|// Happens if a font family population failed
return|return
literal|0
return|;
name|IDWriteFontFile
modifier|*
name|fontFile
init|=
cast|reinterpret_cast
argument_list|<
name|IDWriteFontFile
operator|*
argument_list|>
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|m_fonts
operator|.
name|contains
argument_list|(
name|fontFile
argument_list|)
condition|)
return|return
name|QBasicFontDatabase
operator|::
name|fontEngine
argument_list|(
name|fontDef
argument_list|,
name|handle
argument_list|)
return|;
specifier|const
name|void
modifier|*
name|referenceKey
decl_stmt|;
name|quint32
name|referenceKeySize
decl_stmt|;
name|HRESULT
name|hr
init|=
name|fontFile
operator|->
name|GetReferenceKey
argument_list|(
operator|&
name|referenceKey
argument_list|,
operator|&
name|referenceKeySize
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font file reference key: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|ComPtr
argument_list|<
name|IDWriteFontFileLoader
argument_list|>
name|loader
decl_stmt|;
name|hr
operator|=
name|fontFile
operator|->
name|GetLoader
argument_list|(
operator|&
name|loader
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font file loader: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|ComPtr
argument_list|<
name|IDWriteFontFileStream
argument_list|>
name|stream
decl_stmt|;
name|hr
operator|=
name|loader
operator|->
name|CreateStreamFromKey
argument_list|(
name|referenceKey
argument_list|,
name|referenceKeySize
argument_list|,
operator|&
name|stream
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font file stream: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|quint64
name|fileSize
decl_stmt|;
name|hr
operator|=
name|stream
operator|->
name|GetFileSize
argument_list|(
operator|&
name|fileSize
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font file size: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
specifier|const
name|void
modifier|*
name|data
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
name|hr
operator|=
name|stream
operator|->
name|ReadFileFragment
argument_list|(
operator|&
name|data
argument_list|,
literal|0
argument_list|,
name|fileSize
argument_list|,
operator|&
name|context
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to get font file data: %s"
argument_list|,
name|qPrintable
argument_list|(
name|qt_error_string
argument_list|(
name|hr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
specifier|const
name|QByteArray
name|fontData
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|data
argument_list|,
name|fileSize
argument_list|)
decl_stmt|;
name|stream
operator|->
name|ReleaseFileFragment
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QFontEngine
operator|::
name|FaceId
name|faceId
decl_stmt|;
specifier|const
name|FontDescription
name|description
init|=
name|m_fonts
operator|.
name|value
argument_list|(
name|fontFile
argument_list|)
decl_stmt|;
name|faceId
operator|.
name|uuid
operator|=
name|description
operator|.
name|uuid
expr_stmt|;
name|faceId
operator|.
name|index
operator|=
name|description
operator|.
name|index
expr_stmt|;
specifier|const
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
operator|::
name|GlyphFormat
name|format
init|=
name|antialias
condition|?
name|QFontEngineFT
operator|::
name|Format_A8
else|:
name|QFontEngineFT
operator|::
name|Format_Mono
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
if|if
condition|(
operator|!
name|engine
operator|->
name|init
argument_list|(
name|faceId
argument_list|,
name|antialias
argument_list|,
name|format
argument_list|,
name|fontData
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
return|return
literal|0
return|;
block|}
return|return
name|engine
return|;
block|}
end_function
begin_function
DECL|function|releaseHandle
name|void
name|QWinRTFontDatabase
operator|::
name|releaseHandle
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
block|{
if|if
condition|(
operator|!
name|handle
condition|)
return|return;
name|IDWriteFontFile
modifier|*
name|fontFile
init|=
cast|reinterpret_cast
argument_list|<
name|IDWriteFontFile
operator|*
argument_list|>
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_fonts
operator|.
name|contains
argument_list|(
name|fontFile
argument_list|)
condition|)
block|{
name|m_fonts
operator|.
name|remove
argument_list|(
name|fontFile
argument_list|)
expr_stmt|;
name|fontFile
operator|->
name|Release
argument_list|()
expr_stmt|;
return|return;
block|}
name|QBasicFontDatabase
operator|::
name|releaseHandle
argument_list|(
name|handle
argument_list|)
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|// QT_WINRT_USE_DWRITE
end_comment
begin_function
DECL|function|defaultFont
name|QFont
name|QWinRTFontDatabase
operator|::
name|defaultFont
parameter_list|()
specifier|const
block|{
return|return
name|QFont
argument_list|(
name|QFontDatabase
argument_list|()
operator|.
name|families
argument_list|()
operator|.
name|value
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_WINRT_USE_DWRITE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
