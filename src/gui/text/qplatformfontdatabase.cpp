begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_qpa_p.h>
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
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|void
name|qt_registerFont
parameter_list|(
specifier|const
name|QString
modifier|&
name|familyname
parameter_list|,
specifier|const
name|QString
modifier|&
name|stylename
parameter_list|,
specifier|const
name|QString
modifier|&
name|foundryname
parameter_list|,
name|int
name|weight
parameter_list|,
name|QFont
operator|::
name|Style
name|style
parameter_list|,
name|int
name|stretch
parameter_list|,
name|bool
name|antialiased
parameter_list|,
name|bool
name|scalable
parameter_list|,
name|int
name|pixelSize
parameter_list|,
name|bool
name|fixedPitch
parameter_list|,
specifier|const
name|QSupportedWritingSystems
modifier|&
name|writingSystems
parameter_list|,
name|void
modifier|*
name|hanlde
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*!     \fn void QPlatformFontDatabase::registerQPF2Font(const QByteArray&dataArray, void *handle)      Registers the pre-rendered QPF2 font contained in the given \a dataArray.      \sa registerFont() */
end_comment
begin_function
DECL|function|registerQPF2Font
name|void
name|QPlatformFontDatabase
operator|::
name|registerQPF2Font
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|dataArray
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
block|{
if|if
condition|(
name|dataArray
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
return|return;
specifier|const
name|uchar
modifier|*
name|data
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|dataArray
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|QFontEngineQPA
operator|::
name|verifyHeader
argument_list|(
name|data
argument_list|,
name|dataArray
operator|.
name|size
argument_list|()
argument_list|)
condition|)
block|{
name|QString
name|fontName
init|=
name|QFontEngineQPA
operator|::
name|extractHeaderField
argument_list|(
name|data
argument_list|,
name|QFontEngineQPA
operator|::
name|Tag_FontName
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|int
name|pixelSize
init|=
name|QFontEngineQPA
operator|::
name|extractHeaderField
argument_list|(
name|data
argument_list|,
name|QFontEngineQPA
operator|::
name|Tag_PixelSize
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|QVariant
name|weight
init|=
name|QFontEngineQPA
operator|::
name|extractHeaderField
argument_list|(
name|data
argument_list|,
name|QFontEngineQPA
operator|::
name|Tag_Weight
argument_list|)
decl_stmt|;
name|QVariant
name|style
init|=
name|QFontEngineQPA
operator|::
name|extractHeaderField
argument_list|(
name|data
argument_list|,
name|QFontEngineQPA
operator|::
name|Tag_Style
argument_list|)
decl_stmt|;
name|QByteArray
name|writingSystemBits
init|=
name|QFontEngineQPA
operator|::
name|extractHeaderField
argument_list|(
name|data
argument_list|,
name|QFontEngineQPA
operator|::
name|Tag_WritingSystems
argument_list|)
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|fontName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|pixelSize
condition|)
block|{
name|QFont
operator|::
name|Weight
name|fontWeight
init|=
name|QFont
operator|::
name|Normal
decl_stmt|;
if|if
condition|(
name|weight
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Int
operator|||
name|weight
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|UInt
condition|)
name|fontWeight
operator|=
name|QFont
operator|::
name|Weight
argument_list|(
name|weight
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
name|QFont
operator|::
name|Style
name|fontStyle
init|=
cast|static_cast
argument_list|<
name|QFont
operator|::
name|Style
argument_list|>
argument_list|(
name|style
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
name|QSupportedWritingSystems
name|writingSystems
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
name|writingSystemBits
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|uchar
name|currentByte
init|=
name|writingSystemBits
operator|.
name|at
argument_list|(
name|i
argument_list|)
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
literal|8
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|currentByte
operator|&
literal|1
condition|)
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|(
name|i
operator|*
literal|8
operator|+
name|j
argument_list|)
argument_list|)
expr_stmt|;
name|currentByte
operator|>>=
literal|1
expr_stmt|;
block|}
block|}
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
name|fontName
argument_list|,
name|QString
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
name|fontWeight
argument_list|,
name|fontStyle
argument_list|,
name|stretch
argument_list|,
literal|true
argument_list|,
literal|false
argument_list|,
name|pixelSize
argument_list|,
literal|false
argument_list|,
name|writingSystems
argument_list|,
name|handle
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|qDebug
argument_list|()
operator|<<
literal|"header verification of QPF2 font failed. maybe it is corrupt?"
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Registers a font with the given set of attributes describing the font's     foundry, family name, style and stretch information, pixel size, and     supported writing systems. Additional information about whether the font     can be scaled and antialiased can also be provided.      The foundry name and font family are described by \a foundryName and     \a familyName. The font weight (light, normal, bold, etc.), style (normal,     oblique, italic) and stretch information (condensed, expanded, unstretched,     etc.) are specified by \a weight, \a style and \a stretch.      Some fonts can be antialiased and scaled; \a scalable and \a antialiased     can be set to true for fonts with these attributes. The intended pixel     size of non-scalable fonts is specified by \a pixelSize; this value will be     ignored for scalable fonts.      The writing systems supported by the font are specified by the     \a writingSystems argument.      \sa registerQPF2Font() */
end_comment
begin_function
DECL|function|registerFont
name|void
name|QPlatformFontDatabase
operator|::
name|registerFont
parameter_list|(
specifier|const
name|QString
modifier|&
name|familyname
parameter_list|,
specifier|const
name|QString
modifier|&
name|stylename
parameter_list|,
specifier|const
name|QString
modifier|&
name|foundryname
parameter_list|,
name|QFont
operator|::
name|Weight
name|weight
parameter_list|,
name|QFont
operator|::
name|Style
name|style
parameter_list|,
name|QFont
operator|::
name|Stretch
name|stretch
parameter_list|,
name|bool
name|antialiased
parameter_list|,
name|bool
name|scalable
parameter_list|,
name|int
name|pixelSize
parameter_list|,
name|bool
name|fixedPitch
parameter_list|,
specifier|const
name|QSupportedWritingSystems
modifier|&
name|writingSystems
parameter_list|,
name|void
modifier|*
name|usrPtr
parameter_list|)
block|{
if|if
condition|(
name|scalable
condition|)
name|pixelSize
operator|=
literal|0
expr_stmt|;
name|qt_registerFont
argument_list|(
name|familyname
argument_list|,
name|stylename
argument_list|,
name|foundryname
argument_list|,
name|weight
argument_list|,
name|style
argument_list|,
name|stretch
argument_list|,
name|antialiased
argument_list|,
name|scalable
argument_list|,
name|pixelSize
argument_list|,
name|fixedPitch
argument_list|,
name|writingSystems
argument_list|,
name|usrPtr
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QWritingSystemsPrivate
class|class
name|QWritingSystemsPrivate
block|{
public|public:
DECL|function|QWritingSystemsPrivate
name|QWritingSystemsPrivate
parameter_list|()
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|vector
argument_list|(
name|QFontDatabase
operator|::
name|WritingSystemsCount
argument_list|,
literal|false
argument_list|)
block|{     }
DECL|function|QWritingSystemsPrivate
name|QWritingSystemsPrivate
parameter_list|(
specifier|const
name|QWritingSystemsPrivate
modifier|*
name|other
parameter_list|)
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|vector
argument_list|(
name|other
operator|->
name|vector
argument_list|)
block|{     }
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|vector
name|QVector
argument_list|<
name|bool
argument_list|>
name|vector
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     Constructs a new object to handle supported writing systems. */
end_comment
begin_constructor
DECL|function|QSupportedWritingSystems
name|QSupportedWritingSystems
operator|::
name|QSupportedWritingSystems
parameter_list|()
block|{
name|d
operator|=
operator|new
name|QWritingSystemsPrivate
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a copy of the \a other writing systems object. */
end_comment
begin_constructor
DECL|function|QSupportedWritingSystems
name|QSupportedWritingSystems
operator|::
name|QSupportedWritingSystems
parameter_list|(
specifier|const
name|QSupportedWritingSystems
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a copy of the \a other writing systems object. */
end_comment
begin_function
DECL|function|operator =
name|QSupportedWritingSystems
modifier|&
name|QSupportedWritingSystems
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QSupportedWritingSystems
modifier|&
name|other
parameter_list|)
block|{
if|if
condition|(
name|d
operator|!=
name|other
operator|.
name|d
condition|)
block|{
name|other
operator|.
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Destroys the supported writing systems object. */
end_comment
begin_destructor
DECL|function|~QSupportedWritingSystems
name|QSupportedWritingSystems
operator|::
name|~
name|QSupportedWritingSystems
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|detach
name|void
name|QSupportedWritingSystems
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
block|{
name|QWritingSystemsPrivate
modifier|*
name|newd
init|=
operator|new
name|QWritingSystemsPrivate
argument_list|(
name|d
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|newd
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Sets or clears support for the specified \a writingSystem based on the     value given by \a support. */
end_comment
begin_function
DECL|function|setSupported
name|void
name|QSupportedWritingSystems
operator|::
name|setSupported
parameter_list|(
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystem
parameter_list|,
name|bool
name|support
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|vector
index|[
name|writingSystem
index|]
operator|=
name|support
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the writing system specified by \a writingSystem is     supported; otherwise returns false. */
end_comment
begin_function
DECL|function|supported
name|bool
name|QSupportedWritingSystems
operator|::
name|supported
parameter_list|(
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystem
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|vector
operator|.
name|at
argument_list|(
name|writingSystem
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \class QSupportedWritingSystems     \brief The QSupportedWritingSystems class is used when registering fonts with the internal Qt     fontdatabase     \ingroup painting     \inmodule QtGui      Its to provide an easy to use interface for indicating what writing systems a specific font     supports.  */
end_comment
begin_comment
comment|/*!     \internal  */
end_comment
begin_destructor
DECL|function|~QPlatformFontDatabase
name|QPlatformFontDatabase
operator|::
name|~
name|QPlatformFontDatabase
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   This function is called once at startup by Qt's internal font database.   Reimplement this function in a subclass for a convenient place to initialize   the internal font database.    The default implementation looks in the fontDir() location and registers all   QPF2 fonts. */
end_comment
begin_function
DECL|function|populateFontDatabase
name|void
name|QPlatformFontDatabase
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
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|fontpath
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFontDatabase: Cannot find font directory '%s' - is Qt installed correctly?"
argument_list|,
name|qPrintable
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fontpath
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|QDir
name|dir
argument_list|(
name|fontpath
argument_list|)
decl_stmt|;
name|dir
operator|.
name|setNameFilters
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"*.qpf2"
argument_list|)
argument_list|)
expr_stmt|;
name|dir
operator|.
name|refresh
argument_list|()
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
name|int
argument_list|(
name|dir
operator|.
name|count
argument_list|()
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QByteArray
name|fileName
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|dir
operator|.
name|absoluteFilePath
argument_list|(
name|dir
index|[
name|i
index|]
argument_list|)
argument_list|)
decl_stmt|;
name|QFile
name|file
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|fileName
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
specifier|const
name|QByteArray
name|fileData
init|=
name|file
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QByteArray
modifier|*
name|fileDataPtr
init|=
operator|new
name|QByteArray
argument_list|(
name|fileData
argument_list|)
decl_stmt|;
name|registerQPF2Font
argument_list|(
name|fileData
argument_list|,
name|fileDataPtr
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     Returns a multi font engine in the specified \a script to encapsulate \a fontEngine with the     option to fall back to the fonts given by \a fallbacks if \a fontEngine does not support     a certain character. */
end_comment
begin_function
DECL|function|fontEngineMulti
name|QFontEngineMulti
modifier|*
name|QPlatformFontDatabase
operator|::
name|fontEngineMulti
parameter_list|(
name|QFontEngine
modifier|*
name|fontEngine
parameter_list|,
name|QChar
operator|::
name|Script
name|script
parameter_list|)
block|{
return|return
operator|new
name|QFontEngineMultiQPA
argument_list|(
name|fontEngine
argument_list|,
name|script
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the font engine that can be used to render the font described by     the font definition, \a fontDef, in the specified \a script. */
end_comment
begin_function
DECL|function|fontEngine
name|QFontEngine
modifier|*
name|QPlatformFontDatabase
operator|::
name|fontEngine
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fontDef
parameter_list|,
name|QChar
operator|::
name|Script
name|script
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|script
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|handle
argument_list|)
expr_stmt|;
name|QByteArray
modifier|*
name|fileDataPtr
init|=
cast|static_cast
argument_list|<
name|QByteArray
operator|*
argument_list|>
argument_list|(
name|handle
argument_list|)
decl_stmt|;
name|QFontEngineQPA
modifier|*
name|engine
init|=
operator|new
name|QFontEngineQPA
argument_list|(
name|fontDef
argument_list|,
operator|*
name|fileDataPtr
argument_list|)
decl_stmt|;
comment|//qDebug()<< fontDef.pixelSize<< fontDef.weight<< fontDef.style<< fontDef.stretch<< fontDef.styleHint<< fontDef.styleStrategy<< fontDef.family<< script;
return|return
name|engine
return|;
block|}
end_function
begin_function
DECL|function|fontEngine
name|QFontEngine
modifier|*
name|QPlatformFontDatabase
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
name|Q_UNUSED
argument_list|(
name|fontData
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|pixelSize
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|hintingPreference
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support font engines created directly from font data"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a list of alternative fonts for the specified \a family and     \a style and \a script using the \a styleHint given. */
end_comment
begin_function
DECL|function|fallbacksForFamily
name|QStringList
name|QPlatformFontDatabase
operator|::
name|fallbacksForFamily
parameter_list|(
specifier|const
name|QString
modifier|&
name|family
parameter_list|,
name|QFont
operator|::
name|Style
name|style
parameter_list|,
name|QFont
operator|::
name|StyleHint
name|styleHint
parameter_list|,
name|QChar
operator|::
name|Script
name|script
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|family
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|style
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|styleHint
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|script
argument_list|)
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Adds an application font described by the font contained supplied \a fontData     or using the font contained in the file referenced by \a fileName. Returns     a list of family names, or an empty list if the font could not be added.      \note The default implementation of this function does not add an application     font. Subclasses should reimplement this function to perform the necessary     loading and registration of fonts. */
end_comment
begin_function
DECL|function|addApplicationFont
name|QStringList
name|QPlatformFontDatabase
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
name|Q_UNUSED
argument_list|(
name|fontData
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support application fonts"
argument_list|)
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Releases the specified font \a handle. */
end_comment
begin_function
DECL|function|releaseHandle
name|void
name|QPlatformFontDatabase
operator|::
name|releaseHandle
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|QByteArray
modifier|*
name|fileDataPtr
init|=
cast|static_cast
argument_list|<
name|QByteArray
operator|*
argument_list|>
argument_list|(
name|handle
argument_list|)
decl_stmt|;
operator|delete
name|fileDataPtr
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the directory containing the fonts used by the database. */
end_comment
begin_function
DECL|function|fontDir
name|QString
name|QPlatformFontDatabase
operator|::
name|fontDir
parameter_list|()
specifier|const
block|{
name|QString
name|fontpath
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"QT_QPA_FONTDIR"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|fontpath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|fontpath
operator|=
name|QLibraryInfo
operator|::
name|location
argument_list|(
name|QLibraryInfo
operator|::
name|LibrariesPath
argument_list|)
expr_stmt|;
name|fontpath
operator|+=
name|QLatin1String
argument_list|(
literal|"/fonts"
argument_list|)
expr_stmt|;
block|}
return|return
name|fontpath
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the default system font.      \sa QGuiApplication::font()     \since 5.0 */
end_comment
begin_function
DECL|function|defaultFont
name|QFont
name|QPlatformFontDatabase
operator|::
name|defaultFont
parameter_list|()
specifier|const
block|{
return|return
name|QFont
argument_list|(
name|QLatin1String
argument_list|(
literal|"Helvetica"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Resolve alias to actual font family names.      \since 5.0  */
end_comment
begin_function_decl
name|QString
name|qt_resolveFontFamilyAlias
parameter_list|(
specifier|const
name|QString
modifier|&
name|alias
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|resolveFontFamilyAlias
name|QString
name|QPlatformFontDatabase
operator|::
name|resolveFontFamilyAlias
parameter_list|(
specifier|const
name|QString
modifier|&
name|family
parameter_list|)
specifier|const
block|{
return|return
name|qt_resolveFontFamilyAlias
argument_list|(
name|family
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Return true if all fonts are considered scalable when using this font database.     Defaults to false.      \since 5.0  */
end_comment
begin_function
DECL|function|fontsAlwaysScalable
name|bool
name|QPlatformFontDatabase
operator|::
name|fontsAlwaysScalable
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Return list of standard font sizes when using this font database.      \since 5.0  */
end_comment
begin_function
DECL|function|standardSizes
name|QList
argument_list|<
name|int
argument_list|>
name|QPlatformFontDatabase
operator|::
name|standardSizes
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|ret
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|short
name|standard
index|[]
init|=
block|{
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|14
block|,
literal|16
block|,
literal|18
block|,
literal|20
block|,
literal|22
block|,
literal|24
block|,
literal|26
block|,
literal|28
block|,
literal|36
block|,
literal|48
block|,
literal|72
block|,
literal|0
block|}
decl_stmt|;
name|ret
operator|.
name|reserve
argument_list|(
name|int
argument_list|(
sizeof|sizeof
argument_list|(
name|standard
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|standard
index|[
literal|0
index|]
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|unsigned
name|short
modifier|*
name|sizes
init|=
name|standard
decl_stmt|;
while|while
condition|(
operator|*
name|sizes
condition|)
name|ret
operator|<<
operator|*
name|sizes
operator|++
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_comment
comment|// ### copied to tools/makeqpf/qpf2.cpp
end_comment
begin_comment
comment|// see the Unicode subset bitfields in the MSDN docs
end_comment
begin_decl_stmt
DECL|variable|requiredUnicodeBits
specifier|static
specifier|const
name|ushort
name|requiredUnicodeBits
index|[
name|QFontDatabase
operator|::
name|WritingSystemsCount
index|]
index|[
literal|2
index|]
init|=
block|{
block|{
literal|127
block|,
literal|127
block|}
block|,
comment|// Any
block|{
literal|0
block|,
literal|127
block|}
block|,
comment|// Latin
block|{
literal|7
block|,
literal|127
block|}
block|,
comment|// Greek
block|{
literal|9
block|,
literal|127
block|}
block|,
comment|// Cyrillic
block|{
literal|10
block|,
literal|127
block|}
block|,
comment|// Armenian
block|{
literal|11
block|,
literal|127
block|}
block|,
comment|// Hebrew
block|{
literal|13
block|,
literal|127
block|}
block|,
comment|// Arabic
block|{
literal|71
block|,
literal|127
block|}
block|,
comment|// Syriac
block|{
literal|72
block|,
literal|127
block|}
block|,
comment|// Thaana
block|{
literal|15
block|,
literal|127
block|}
block|,
comment|// Devanagari
block|{
literal|16
block|,
literal|127
block|}
block|,
comment|// Bengali
block|{
literal|17
block|,
literal|127
block|}
block|,
comment|// Gurmukhi
block|{
literal|18
block|,
literal|127
block|}
block|,
comment|// Gujarati
block|{
literal|19
block|,
literal|127
block|}
block|,
comment|// Oriya
block|{
literal|20
block|,
literal|127
block|}
block|,
comment|// Tamil
block|{
literal|21
block|,
literal|127
block|}
block|,
comment|// Telugu
block|{
literal|22
block|,
literal|127
block|}
block|,
comment|// Kannada
block|{
literal|23
block|,
literal|127
block|}
block|,
comment|// Malayalam
block|{
literal|73
block|,
literal|127
block|}
block|,
comment|// Sinhala
block|{
literal|24
block|,
literal|127
block|}
block|,
comment|// Thai
block|{
literal|25
block|,
literal|127
block|}
block|,
comment|// Lao
block|{
literal|70
block|,
literal|127
block|}
block|,
comment|// Tibetan
block|{
literal|74
block|,
literal|127
block|}
block|,
comment|// Myanmar
block|{
literal|26
block|,
literal|127
block|}
block|,
comment|// Georgian
block|{
literal|80
block|,
literal|127
block|}
block|,
comment|// Khmer
block|{
literal|126
block|,
literal|127
block|}
block|,
comment|// SimplifiedChinese
block|{
literal|126
block|,
literal|127
block|}
block|,
comment|// TraditionalChinese
block|{
literal|126
block|,
literal|127
block|}
block|,
comment|// Japanese
block|{
literal|56
block|,
literal|127
block|}
block|,
comment|// Korean
block|{
literal|0
block|,
literal|127
block|}
block|,
comment|// Vietnamese (same as latin1)
block|{
literal|126
block|,
literal|127
block|}
block|,
comment|// Other
block|{
literal|78
block|,
literal|127
block|}
block|,
comment|// Ogham
block|{
literal|79
block|,
literal|127
block|}
block|,
comment|// Runic
block|{
literal|14
block|,
literal|127
block|}
block|,
comment|// Nko
block|}
decl_stmt|;
end_decl_stmt
begin_enum
enum|enum
block|{
DECL|enumerator|SimplifiedChineseCsbBit
name|SimplifiedChineseCsbBit
init|=
literal|18
block|,
DECL|enumerator|TraditionalChineseCsbBit
name|TraditionalChineseCsbBit
init|=
literal|20
block|,
DECL|enumerator|JapaneseCsbBit
name|JapaneseCsbBit
init|=
literal|17
block|,
DECL|enumerator|KoreanCsbBit
name|KoreanCsbBit
init|=
literal|21
block|}
enum|;
end_enum
begin_comment
comment|/*!     Helper function that determines the writing systems support by a given     \a unicodeRange and \a codePageRange.      \since 5.1 */
end_comment
begin_function
DECL|function|writingSystemsFromTrueTypeBits
name|QSupportedWritingSystems
name|QPlatformFontDatabase
operator|::
name|writingSystemsFromTrueTypeBits
parameter_list|(
name|quint32
name|unicodeRange
index|[
literal|4
index|]
parameter_list|,
name|quint32
name|codePageRange
index|[
literal|2
index|]
parameter_list|)
block|{
name|QSupportedWritingSystems
name|writingSystems
decl_stmt|;
name|bool
name|hasScript
init|=
literal|false
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
name|QFontDatabase
operator|::
name|WritingSystemsCount
condition|;
operator|++
name|i
control|)
block|{
name|int
name|bit
init|=
name|requiredUnicodeBits
index|[
name|i
index|]
index|[
literal|0
index|]
decl_stmt|;
name|int
name|index
init|=
name|bit
operator|/
literal|32
decl_stmt|;
name|int
name|flag
init|=
literal|1
operator|<<
operator|(
name|bit
operator|&
literal|31
operator|)
decl_stmt|;
if|if
condition|(
name|bit
operator|!=
literal|126
operator|&&
operator|(
name|unicodeRange
index|[
name|index
index|]
operator|&
name|flag
operator|)
condition|)
block|{
name|bit
operator|=
name|requiredUnicodeBits
index|[
name|i
index|]
index|[
literal|1
index|]
expr_stmt|;
name|index
operator|=
name|bit
operator|/
literal|32
expr_stmt|;
name|flag
operator|=
literal|1
operator|<<
operator|(
name|bit
operator|&
literal|31
operator|)
expr_stmt|;
if|if
condition|(
name|bit
operator|==
literal|127
operator|||
operator|(
name|unicodeRange
index|[
name|index
index|]
operator|&
name|flag
operator|)
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|hasScript
operator|=
literal|true
expr_stmt|;
comment|// qDebug("font %s: index=%d, flag=%8x supports script %d", familyName.latin1(), index, flag, i);
block|}
block|}
block|}
if|if
condition|(
name|codePageRange
index|[
literal|0
index|]
operator|&
operator|(
literal|1
operator|<<
name|SimplifiedChineseCsbBit
operator|)
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|SimplifiedChinese
argument_list|)
expr_stmt|;
name|hasScript
operator|=
literal|true
expr_stmt|;
comment|//qDebug("font %s supports Simplified Chinese", familyName.latin1());
block|}
if|if
condition|(
name|codePageRange
index|[
literal|0
index|]
operator|&
operator|(
literal|1
operator|<<
name|TraditionalChineseCsbBit
operator|)
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|TraditionalChinese
argument_list|)
expr_stmt|;
name|hasScript
operator|=
literal|true
expr_stmt|;
comment|//qDebug("font %s supports Traditional Chinese", familyName.latin1());
block|}
if|if
condition|(
name|codePageRange
index|[
literal|0
index|]
operator|&
operator|(
literal|1
operator|<<
name|JapaneseCsbBit
operator|)
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|Japanese
argument_list|)
expr_stmt|;
name|hasScript
operator|=
literal|true
expr_stmt|;
comment|//qDebug("font %s supports Japanese", familyName.latin1());
block|}
if|if
condition|(
name|codePageRange
index|[
literal|0
index|]
operator|&
operator|(
literal|1
operator|<<
name|KoreanCsbBit
operator|)
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|Korean
argument_list|)
expr_stmt|;
name|hasScript
operator|=
literal|true
expr_stmt|;
comment|//qDebug("font %s supports Korean", familyName.latin1());
block|}
if|if
condition|(
operator|!
name|hasScript
condition|)
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|Symbol
argument_list|)
expr_stmt|;
return|return
name|writingSystems
return|;
block|}
end_function
begin_comment
comment|/*!     \class QPlatformFontDatabase     \since 5.0     \internal     \preliminary     \ingroup qpa     \ingroup painting      \brief The QPlatformFontDatabase class makes it possible to customize how fonts     are discovered and how they are rendered      QPlatformFontDatabase is the superclass which is intended to let platform implementations use     native font handling.      Qt has its internal font database which it uses to discover available fonts on the     user's system. To be able to populate this database subclass this class, and     reimplement populateFontDatabase().      Use the function registerFont() to populate the internal font database.      Sometimes a specified font does not have the required glyphs; in such a case, the     fallbackForFamily() function is called automatically to find alternative font     families that can supply alternatives to the missing glyphs.      \sa QSupportedWritingSystems */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
