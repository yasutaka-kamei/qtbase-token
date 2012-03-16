begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ICON
end_ifndef
begin_include
include|#
directive|include
file|<private/qiconloader_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qicon_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QIconEnginePlugin>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPixmapCache>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformTheme>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QIconEngine>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QStyleOption>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
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
file|<QtGui/QPainter>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<private/qt_cocoa_helpers_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<private/qhexstring_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_GLOBAL_STATIC
argument_list|(
name|QIconLoader
argument_list|,
name|iconLoaderInstance
argument_list|)
comment|/* Theme to use in last resort, if the theme does not have the icon, neither the parents  */
decl|static
DECL|function|fallbackTheme
name|QString
name|fallbackTheme
argument_list|()
argument_list|{     if
operator|(
specifier|const
name|QPlatformTheme
operator|*
name|theme
operator|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|)
block|{
specifier|const
name|QVariant
name|themeHint
operator|=
name|theme
operator|->
name|themeHint
argument_list|(
name|QPlatformTheme
operator|::
name|SystemIconThemeName
argument_list|)
block|;
if|if
condition|(
name|themeHint
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|themeHint
operator|.
name|toString
argument_list|()
return|;
block|}
return|return
name|QString
argument_list|()
return|;
end_decl_stmt
begin_expr_stmt
unit|}  QIconLoader
DECL|function|QIconLoader
operator|::
name|QIconLoader
argument_list|()
operator|:
name|m_themeKey
argument_list|(
literal|1
argument_list|)
operator|,
name|m_supportsSvg
argument_list|(
literal|false
argument_list|)
operator|,
name|m_initialized
argument_list|(
literal|false
argument_list|)
block|{ }
comment|// We lazily initialize the loader to make static icons
comment|// work. Though we do not officially support this.
DECL|function|systemThemeName
specifier|static
specifier|inline
name|QString
name|systemThemeName
argument_list|()
block|{
if|if
condition|(
specifier|const
name|QPlatformTheme
modifier|*
name|theme
init|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
condition|)
block|{
specifier|const
name|QVariant
name|themeHint
init|=
name|theme
operator|->
name|themeHint
argument_list|(
name|QPlatformTheme
operator|::
name|SystemIconThemeName
argument_list|)
decl_stmt|;
if|if
condition|(
name|themeHint
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|themeHint
operator|.
name|toString
argument_list|()
return|;
block|}
end_expr_stmt
begin_return
return|return
name|QString
argument_list|()
return|;
end_return
begin_function
unit|}  static
DECL|function|systemIconSearchPaths
specifier|inline
name|QStringList
name|systemIconSearchPaths
parameter_list|()
block|{
if|if
condition|(
specifier|const
name|QPlatformTheme
modifier|*
name|theme
init|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
condition|)
block|{
specifier|const
name|QVariant
name|themeHint
init|=
name|theme
operator|->
name|themeHint
argument_list|(
name|QPlatformTheme
operator|::
name|IconThemeSearchPaths
argument_list|)
decl_stmt|;
if|if
condition|(
name|themeHint
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|themeHint
operator|.
name|toStringList
argument_list|()
return|;
block|}
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|ensureInitialized
name|void
name|QIconLoader
operator|::
name|ensureInitialized
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_initialized
condition|)
block|{
name|m_initialized
operator|=
literal|true
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|qApp
argument_list|)
expr_stmt|;
name|m_systemTheme
operator|=
name|systemThemeName
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_systemTheme
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_systemTheme
operator|=
name|fallbackTheme
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|QFactoryLoader
name|iconFactoryLoader
argument_list|(
name|QIconEngineFactoryInterface_iid
argument_list|,
name|QLatin1String
argument_list|(
literal|"/iconengines"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
decl_stmt|;
if|if
condition|(
name|iconFactoryLoader
operator|.
name|keys
argument_list|()
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"svg"
argument_list|)
argument_list|)
condition|)
name|m_supportsSvg
operator|=
literal|true
expr_stmt|;
endif|#
directive|endif
comment|//QT_NO_LIBRARY
block|}
block|}
end_function
begin_function
DECL|function|instance
name|QIconLoader
modifier|*
name|QIconLoader
operator|::
name|instance
parameter_list|()
block|{
return|return
name|iconLoaderInstance
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Queries the system theme and invalidates existing
end_comment
begin_comment
comment|// icons if the theme has changed.
end_comment
begin_function
DECL|function|updateSystemTheme
name|void
name|QIconLoader
operator|::
name|updateSystemTheme
parameter_list|()
block|{
comment|// Only change if this is not explicitly set by the user
if|if
condition|(
name|m_userTheme
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|theme
init|=
name|systemThemeName
argument_list|()
decl_stmt|;
if|if
condition|(
name|theme
operator|.
name|isEmpty
argument_list|()
condition|)
name|theme
operator|=
name|fallbackTheme
argument_list|()
expr_stmt|;
if|if
condition|(
name|theme
operator|!=
name|m_systemTheme
condition|)
block|{
name|m_systemTheme
operator|=
name|theme
expr_stmt|;
name|invalidateKey
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|setThemeName
name|void
name|QIconLoader
operator|::
name|setThemeName
parameter_list|(
specifier|const
name|QString
modifier|&
name|themeName
parameter_list|)
block|{
name|m_userTheme
operator|=
name|themeName
expr_stmt|;
name|invalidateKey
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setThemeSearchPath
name|void
name|QIconLoader
operator|::
name|setThemeSearchPath
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|searchPaths
parameter_list|)
block|{
name|m_iconDirs
operator|=
name|searchPaths
expr_stmt|;
name|themeList
operator|.
name|clear
argument_list|()
expr_stmt|;
name|invalidateKey
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|themeSearchPaths
name|QStringList
name|QIconLoader
operator|::
name|themeSearchPaths
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_iconDirs
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|m_iconDirs
operator|=
name|systemIconSearchPaths
argument_list|()
expr_stmt|;
comment|// Always add resource directory as search path
name|m_iconDirs
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|":/icons"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|m_iconDirs
return|;
block|}
end_function
begin_constructor
DECL|function|QIconTheme
name|QIconTheme
operator|::
name|QIconTheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|themeName
parameter_list|)
member_init_list|:
name|m_valid
argument_list|(
literal|false
argument_list|)
block|{
name|QFile
name|themeIndex
decl_stmt|;
name|QList
argument_list|<
name|QIconDirInfo
argument_list|>
name|keyList
decl_stmt|;
name|QStringList
name|iconDirs
init|=
name|QIcon
operator|::
name|themeSearchPaths
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
name|iconDirs
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QDir
name|iconDir
argument_list|(
name|iconDirs
index|[
name|i
index|]
argument_list|)
decl_stmt|;
name|QString
name|themeDir
init|=
name|iconDir
operator|.
name|path
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|themeName
decl_stmt|;
name|themeIndex
operator|.
name|setFileName
argument_list|(
name|themeDir
operator|+
name|QLatin1String
argument_list|(
literal|"/index.theme"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|themeIndex
operator|.
name|exists
argument_list|()
condition|)
block|{
name|m_contentDir
operator|=
name|themeDir
expr_stmt|;
name|m_valid
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
if|if
condition|(
name|themeIndex
operator|.
name|exists
argument_list|()
condition|)
block|{
specifier|const
name|QSettings
name|indexReader
argument_list|(
name|themeIndex
operator|.
name|fileName
argument_list|()
argument_list|,
name|QSettings
operator|::
name|IniFormat
argument_list|)
decl_stmt|;
name|QStringListIterator
name|keyIterator
argument_list|(
name|indexReader
operator|.
name|allKeys
argument_list|()
argument_list|)
decl_stmt|;
while|while
condition|(
name|keyIterator
operator|.
name|hasNext
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|key
init|=
name|keyIterator
operator|.
name|next
argument_list|()
decl_stmt|;
if|if
condition|(
name|key
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"/Size"
argument_list|)
argument_list|)
condition|)
block|{
comment|// Note the QSettings ini-format does not accept
comment|// slashes in key names, hence we have to cheat
if|if
condition|(
name|int
name|size
init|=
name|indexReader
operator|.
name|value
argument_list|(
name|key
argument_list|)
operator|.
name|toInt
argument_list|()
condition|)
block|{
name|QString
name|directoryKey
init|=
name|key
operator|.
name|left
argument_list|(
name|key
operator|.
name|size
argument_list|()
operator|-
literal|5
argument_list|)
decl_stmt|;
name|QIconDirInfo
name|dirInfo
argument_list|(
name|directoryKey
argument_list|)
decl_stmt|;
name|dirInfo
operator|.
name|size
operator|=
name|size
expr_stmt|;
name|QString
name|type
init|=
name|indexReader
operator|.
name|value
argument_list|(
name|directoryKey
operator|+
name|QLatin1String
argument_list|(
literal|"/Type"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|QLatin1String
argument_list|(
literal|"Fixed"
argument_list|)
condition|)
name|dirInfo
operator|.
name|type
operator|=
name|QIconDirInfo
operator|::
name|Fixed
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
name|QLatin1String
argument_list|(
literal|"Scalable"
argument_list|)
condition|)
name|dirInfo
operator|.
name|type
operator|=
name|QIconDirInfo
operator|::
name|Scalable
expr_stmt|;
else|else
name|dirInfo
operator|.
name|type
operator|=
name|QIconDirInfo
operator|::
name|Threshold
expr_stmt|;
name|dirInfo
operator|.
name|threshold
operator|=
name|indexReader
operator|.
name|value
argument_list|(
name|directoryKey
operator|+
name|QLatin1String
argument_list|(
literal|"/Threshold"
argument_list|)
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|dirInfo
operator|.
name|minSize
operator|=
name|indexReader
operator|.
name|value
argument_list|(
name|directoryKey
operator|+
name|QLatin1String
argument_list|(
literal|"/MinSize"
argument_list|)
argument_list|,
name|size
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|dirInfo
operator|.
name|maxSize
operator|=
name|indexReader
operator|.
name|value
argument_list|(
name|directoryKey
operator|+
name|QLatin1String
argument_list|(
literal|"/MaxSize"
argument_list|)
argument_list|,
name|size
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|m_keyList
operator|.
name|append
argument_list|(
name|dirInfo
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|// Parent themes provide fallbacks for missing icons
name|m_parents
operator|=
name|indexReader
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"Icon Theme/Inherits"
argument_list|)
argument_list|)
operator|.
name|toStringList
argument_list|()
expr_stmt|;
comment|// Ensure a default platform fallback for all themes
if|if
condition|(
name|m_parents
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|fallback
init|=
name|fallbackTheme
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|fallback
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_parents
operator|.
name|append
argument_list|(
name|fallback
argument_list|)
expr_stmt|;
block|}
comment|// Ensure that all themes fall back to hicolor
if|if
condition|(
operator|!
name|m_parents
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"hicolor"
argument_list|)
argument_list|)
condition|)
name|m_parents
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"hicolor"
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|//QT_NO_SETTINGS
block|}
end_constructor
begin_function
DECL|function|findIconHelper
name|QThemeIconEntries
name|QIconLoader
operator|::
name|findIconHelper
parameter_list|(
specifier|const
name|QString
modifier|&
name|themeName
parameter_list|,
specifier|const
name|QString
modifier|&
name|iconName
parameter_list|,
name|QStringList
modifier|&
name|visited
parameter_list|)
specifier|const
block|{
name|QThemeIconEntries
name|entries
decl_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|themeName
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QPixmap
name|pixmap
decl_stmt|;
comment|// Used to protect against potential recursions
name|visited
operator|<<
name|themeName
expr_stmt|;
name|QIconTheme
name|theme
init|=
name|themeList
operator|.
name|value
argument_list|(
name|themeName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|theme
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|theme
operator|=
name|QIconTheme
argument_list|(
name|themeName
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|theme
operator|.
name|isValid
argument_list|()
condition|)
name|theme
operator|=
name|QIconTheme
argument_list|(
name|fallbackTheme
argument_list|()
argument_list|)
expr_stmt|;
name|themeList
operator|.
name|insert
argument_list|(
name|themeName
argument_list|,
name|theme
argument_list|)
expr_stmt|;
block|}
name|QString
name|contentDir
init|=
name|theme
operator|.
name|contentDir
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QIconDirInfo
argument_list|>
name|subDirs
init|=
name|theme
operator|.
name|keyList
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|svgext
argument_list|(
name|QLatin1String
argument_list|(
literal|".svg"
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|pngext
argument_list|(
name|QLatin1String
argument_list|(
literal|".png"
argument_list|)
argument_list|)
decl_stmt|;
comment|// Add all relevant files
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|subDirs
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QIconDirInfo
modifier|&
name|dirInfo
init|=
name|subDirs
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QString
name|subdir
init|=
name|dirInfo
operator|.
name|path
decl_stmt|;
name|QDir
name|currentDir
argument_list|(
name|contentDir
operator|+
name|subdir
argument_list|)
decl_stmt|;
if|if
condition|(
name|currentDir
operator|.
name|exists
argument_list|(
name|iconName
operator|+
name|pngext
argument_list|)
condition|)
block|{
name|PixmapEntry
modifier|*
name|iconEntry
init|=
operator|new
name|PixmapEntry
decl_stmt|;
name|iconEntry
operator|->
name|dir
operator|=
name|dirInfo
expr_stmt|;
name|iconEntry
operator|->
name|filename
operator|=
name|currentDir
operator|.
name|filePath
argument_list|(
name|iconName
operator|+
name|pngext
argument_list|)
expr_stmt|;
comment|// Notice we ensure that pixmap entries always come before
comment|// scalable to preserve search order afterwards
name|entries
operator|.
name|prepend
argument_list|(
name|iconEntry
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|m_supportsSvg
operator|&&
name|currentDir
operator|.
name|exists
argument_list|(
name|iconName
operator|+
name|svgext
argument_list|)
condition|)
block|{
name|ScalableEntry
modifier|*
name|iconEntry
init|=
operator|new
name|ScalableEntry
decl_stmt|;
name|iconEntry
operator|->
name|dir
operator|=
name|dirInfo
expr_stmt|;
name|iconEntry
operator|->
name|filename
operator|=
name|currentDir
operator|.
name|filePath
argument_list|(
name|iconName
operator|+
name|svgext
argument_list|)
expr_stmt|;
name|entries
operator|.
name|append
argument_list|(
name|iconEntry
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|entries
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QStringList
name|parents
init|=
name|theme
operator|.
name|parents
argument_list|()
decl_stmt|;
comment|// Search recursively through inherited themes
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|parents
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
name|parentTheme
init|=
name|parents
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|trimmed
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|visited
operator|.
name|contains
argument_list|(
name|parentTheme
argument_list|)
condition|)
comment|// guard against recursion
name|entries
operator|=
name|findIconHelper
argument_list|(
name|parentTheme
argument_list|,
name|iconName
argument_list|,
name|visited
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|entries
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// success
break|break;
block|}
block|}
return|return
name|entries
return|;
block|}
end_function
begin_function
DECL|function|loadIcon
name|QThemeIconEntries
name|QIconLoader
operator|::
name|loadIcon
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|themeName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QStringList
name|visited
decl_stmt|;
return|return
name|findIconHelper
argument_list|(
name|themeName
argument_list|()
argument_list|,
name|name
argument_list|,
name|visited
argument_list|)
return|;
block|}
return|return
name|QThemeIconEntries
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// -------- Icon Loader Engine -------- //
end_comment
begin_constructor
DECL|function|QIconLoaderEngine
name|QIconLoaderEngine
operator|::
name|QIconLoaderEngine
parameter_list|(
specifier|const
name|QString
modifier|&
name|iconName
parameter_list|)
member_init_list|:
name|m_iconName
argument_list|(
name|iconName
argument_list|)
member_init_list|,
name|m_key
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QIconLoaderEngine
name|QIconLoaderEngine
operator|::
name|~
name|QIconLoaderEngine
parameter_list|()
block|{
while|while
condition|(
operator|!
name|m_entries
operator|.
name|isEmpty
argument_list|()
condition|)
operator|delete
name|m_entries
operator|.
name|takeLast
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|m_entries
operator|.
name|size
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_constructor
DECL|function|QIconLoaderEngine
name|QIconLoaderEngine
operator|::
name|QIconLoaderEngine
parameter_list|(
specifier|const
name|QIconLoaderEngine
modifier|&
name|other
parameter_list|)
member_init_list|:
name|QIconEngine
argument_list|(
name|other
argument_list|)
member_init_list|,
name|m_iconName
argument_list|(
name|other
operator|.
name|m_iconName
argument_list|)
member_init_list|,
name|m_key
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|clone
name|QIconEngine
modifier|*
name|QIconLoaderEngine
operator|::
name|clone
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QIconLoaderEngine
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|read
name|bool
name|QIconLoaderEngine
operator|::
name|read
parameter_list|(
name|QDataStream
modifier|&
name|in
parameter_list|)
block|{
name|in
operator|>>
name|m_iconName
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|write
name|bool
name|QIconLoaderEngine
operator|::
name|write
parameter_list|(
name|QDataStream
modifier|&
name|out
parameter_list|)
specifier|const
block|{
name|out
operator|<<
name|m_iconName
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|hasIcon
name|bool
name|QIconLoaderEngine
operator|::
name|hasIcon
parameter_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|m_entries
operator|.
name|isEmpty
argument_list|()
operator|)
return|;
block|}
end_function
begin_comment
comment|// Lazily load the icon
end_comment
begin_function
DECL|function|ensureLoaded
name|void
name|QIconLoaderEngine
operator|::
name|ensureLoaded
parameter_list|()
block|{
name|iconLoaderInstance
argument_list|()
operator|->
name|ensureInitialized
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|iconLoaderInstance
argument_list|()
operator|->
name|themeKey
argument_list|()
operator|==
name|m_key
operator|)
condition|)
block|{
while|while
condition|(
operator|!
name|m_entries
operator|.
name|isEmpty
argument_list|()
condition|)
operator|delete
name|m_entries
operator|.
name|takeLast
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|m_entries
operator|.
name|size
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|m_entries
operator|=
name|iconLoaderInstance
argument_list|()
operator|->
name|loadIcon
argument_list|(
name|m_iconName
argument_list|)
expr_stmt|;
name|m_key
operator|=
name|iconLoaderInstance
argument_list|()
operator|->
name|themeKey
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|paint
name|void
name|QIconLoaderEngine
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|QIcon
operator|::
name|Mode
name|mode
parameter_list|,
name|QIcon
operator|::
name|State
name|state
parameter_list|)
block|{
name|QSize
name|pixmapSize
init|=
name|rect
operator|.
name|size
argument_list|()
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|pixmapSize
operator|*=
name|qt_mac_get_scalefactor
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|painter
operator|->
name|drawPixmap
argument_list|(
name|rect
argument_list|,
name|pixmap
argument_list|(
name|pixmapSize
argument_list|,
name|mode
argument_list|,
name|state
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*  * This algorithm is defined by the freedesktop spec:  * http://standards.freedesktop.org/icon-theme-spec/icon-theme-spec-latest.html  */
end_comment
begin_function
DECL|function|directoryMatchesSize
specifier|static
name|bool
name|directoryMatchesSize
parameter_list|(
specifier|const
name|QIconDirInfo
modifier|&
name|dir
parameter_list|,
name|int
name|iconsize
parameter_list|)
block|{
if|if
condition|(
name|dir
operator|.
name|type
operator|==
name|QIconDirInfo
operator|::
name|Fixed
condition|)
block|{
return|return
name|dir
operator|.
name|size
operator|==
name|iconsize
return|;
block|}
elseif|else
if|if
condition|(
name|dir
operator|.
name|type
operator|==
name|QIconDirInfo
operator|::
name|Scalable
condition|)
block|{
return|return
name|dir
operator|.
name|size
operator|<=
name|dir
operator|.
name|maxSize
operator|&&
name|iconsize
operator|>=
name|dir
operator|.
name|minSize
return|;
block|}
elseif|else
if|if
condition|(
name|dir
operator|.
name|type
operator|==
name|QIconDirInfo
operator|::
name|Threshold
condition|)
block|{
return|return
name|iconsize
operator|>=
name|dir
operator|.
name|size
operator|-
name|dir
operator|.
name|threshold
operator|&&
name|iconsize
operator|<=
name|dir
operator|.
name|size
operator|+
name|dir
operator|.
name|threshold
return|;
block|}
name|Q_ASSERT
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// Not a valid value
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*  * This algorithm is defined by the freedesktop spec:  * http://standards.freedesktop.org/icon-theme-spec/icon-theme-spec-latest.html  */
end_comment
begin_function
DECL|function|directorySizeDistance
specifier|static
name|int
name|directorySizeDistance
parameter_list|(
specifier|const
name|QIconDirInfo
modifier|&
name|dir
parameter_list|,
name|int
name|iconsize
parameter_list|)
block|{
if|if
condition|(
name|dir
operator|.
name|type
operator|==
name|QIconDirInfo
operator|::
name|Fixed
condition|)
block|{
return|return
name|qAbs
argument_list|(
name|dir
operator|.
name|size
operator|-
name|iconsize
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|dir
operator|.
name|type
operator|==
name|QIconDirInfo
operator|::
name|Scalable
condition|)
block|{
if|if
condition|(
name|iconsize
operator|<
name|dir
operator|.
name|minSize
condition|)
return|return
name|dir
operator|.
name|minSize
operator|-
name|iconsize
return|;
elseif|else
if|if
condition|(
name|iconsize
operator|>
name|dir
operator|.
name|maxSize
condition|)
return|return
name|iconsize
operator|-
name|dir
operator|.
name|maxSize
return|;
else|else
return|return
literal|0
return|;
block|}
elseif|else
if|if
condition|(
name|dir
operator|.
name|type
operator|==
name|QIconDirInfo
operator|::
name|Threshold
condition|)
block|{
if|if
condition|(
name|iconsize
operator|<
name|dir
operator|.
name|size
operator|-
name|dir
operator|.
name|threshold
condition|)
return|return
name|dir
operator|.
name|minSize
operator|-
name|iconsize
return|;
elseif|else
if|if
condition|(
name|iconsize
operator|>
name|dir
operator|.
name|size
operator|+
name|dir
operator|.
name|threshold
condition|)
return|return
name|iconsize
operator|-
name|dir
operator|.
name|maxSize
return|;
else|else
return|return
literal|0
return|;
block|}
name|Q_ASSERT
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// Not a valid value
return|return
name|INT_MAX
return|;
block|}
end_function
begin_function
DECL|function|entryForSize
name|QIconLoaderEngineEntry
modifier|*
name|QIconLoaderEngine
operator|::
name|entryForSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|int
name|iconsize
init|=
name|qMin
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
comment|// Note that m_entries are sorted so that png-files
comment|// come first
comment|// Search for exact matches first
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_entries
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QIconLoaderEngineEntry
modifier|*
name|entry
init|=
name|m_entries
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|directoryMatchesSize
argument_list|(
name|entry
operator|->
name|dir
argument_list|,
name|iconsize
argument_list|)
condition|)
block|{
return|return
name|entry
return|;
block|}
block|}
comment|// Find the minimum distance icon
name|int
name|minimalSize
init|=
name|INT_MAX
decl_stmt|;
name|QIconLoaderEngineEntry
modifier|*
name|closestMatch
init|=
literal|0
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
name|m_entries
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QIconLoaderEngineEntry
modifier|*
name|entry
init|=
name|m_entries
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|distance
init|=
name|directorySizeDistance
argument_list|(
name|entry
operator|->
name|dir
argument_list|,
name|iconsize
argument_list|)
decl_stmt|;
if|if
condition|(
name|distance
operator|<
name|minimalSize
condition|)
block|{
name|minimalSize
operator|=
name|distance
expr_stmt|;
name|closestMatch
operator|=
name|entry
expr_stmt|;
block|}
block|}
return|return
name|closestMatch
return|;
block|}
end_function
begin_comment
comment|/*  * Returns the actual icon size. For scalable svg's this is equivalent  * to the requested size. Otherwise the closest match is returned but  * we can never return a bigger size than the requested size.  *  */
end_comment
begin_function
DECL|function|actualSize
name|QSize
name|QIconLoaderEngine
operator|::
name|actualSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QIcon
operator|::
name|Mode
name|mode
parameter_list|,
name|QIcon
operator|::
name|State
name|state
parameter_list|)
block|{
name|ensureLoaded
argument_list|()
expr_stmt|;
name|QIconLoaderEngineEntry
modifier|*
name|entry
init|=
name|entryForSize
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|entry
condition|)
block|{
specifier|const
name|QIconDirInfo
modifier|&
name|dir
init|=
name|entry
operator|->
name|dir
decl_stmt|;
if|if
condition|(
name|dir
operator|.
name|type
operator|==
name|QIconDirInfo
operator|::
name|Scalable
condition|)
return|return
name|size
return|;
else|else
block|{
name|int
name|result
init|=
name|qMin
argument_list|<
name|int
argument_list|>
argument_list|(
name|dir
operator|.
name|size
argument_list|,
name|qMin
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|QSize
argument_list|(
name|result
argument_list|,
name|result
argument_list|)
return|;
block|}
block|}
return|return
name|QIconEngine
operator|::
name|actualSize
argument_list|(
name|size
argument_list|,
name|mode
argument_list|,
name|state
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pixmap
name|QPixmap
name|PixmapEntry
operator|::
name|pixmap
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QIcon
operator|::
name|Mode
name|mode
parameter_list|,
name|QIcon
operator|::
name|State
name|state
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|state
argument_list|)
expr_stmt|;
comment|// Ensure that basePixmap is lazily initialized before generating the
comment|// key, otherwise the cache key is not unique
if|if
condition|(
name|basePixmap
operator|.
name|isNull
argument_list|()
condition|)
name|basePixmap
operator|.
name|load
argument_list|(
name|filename
argument_list|)
expr_stmt|;
name|int
name|actualSize
init|=
name|qMin
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|key
init|=
name|QLatin1Literal
argument_list|(
literal|"$qt_theme_"
argument_list|)
operator|%
name|HexString
argument_list|<
name|qint64
argument_list|>
argument_list|(
name|basePixmap
operator|.
name|cacheKey
argument_list|()
argument_list|)
operator|%
name|HexString
argument_list|<
name|int
argument_list|>
argument_list|(
name|mode
argument_list|)
operator|%
name|HexString
argument_list|<
name|qint64
argument_list|>
argument_list|(
name|qApp
operator|->
name|palette
argument_list|()
operator|.
name|cacheKey
argument_list|()
argument_list|)
operator|%
name|HexString
argument_list|<
name|int
argument_list|>
argument_list|(
name|actualSize
argument_list|)
decl_stmt|;
name|QPixmap
name|cachedPixmap
decl_stmt|;
if|if
condition|(
name|QPixmapCache
operator|::
name|find
argument_list|(
name|key
argument_list|,
operator|&
name|cachedPixmap
argument_list|)
condition|)
block|{
return|return
name|cachedPixmap
return|;
block|}
else|else
block|{
name|QStyleOption
name|opt
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|opt
operator|.
name|palette
operator|=
name|qApp
operator|->
name|palette
argument_list|()
expr_stmt|;
name|cachedPixmap
operator|=
name|qApp
operator|->
name|style
argument_list|()
operator|->
name|generatedIconPixmap
argument_list|(
name|mode
argument_list|,
name|basePixmap
argument_list|,
operator|&
name|opt
argument_list|)
expr_stmt|;
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|key
argument_list|,
name|cachedPixmap
argument_list|)
expr_stmt|;
block|}
return|return
name|cachedPixmap
return|;
block|}
end_function
begin_function
DECL|function|pixmap
name|QPixmap
name|ScalableEntry
operator|::
name|pixmap
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QIcon
operator|::
name|Mode
name|mode
parameter_list|,
name|QIcon
operator|::
name|State
name|state
parameter_list|)
block|{
if|if
condition|(
name|svgIcon
operator|.
name|isNull
argument_list|()
condition|)
name|svgIcon
operator|=
name|QIcon
argument_list|(
name|filename
argument_list|)
expr_stmt|;
comment|// Simply reuse svg icon engine
return|return
name|svgIcon
operator|.
name|pixmap
argument_list|(
name|size
argument_list|,
name|mode
argument_list|,
name|state
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pixmap
name|QPixmap
name|QIconLoaderEngine
operator|::
name|pixmap
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QIcon
operator|::
name|Mode
name|mode
parameter_list|,
name|QIcon
operator|::
name|State
name|state
parameter_list|)
block|{
name|ensureLoaded
argument_list|()
expr_stmt|;
name|QIconLoaderEngineEntry
modifier|*
name|entry
init|=
name|entryForSize
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|entry
condition|)
return|return
name|entry
operator|->
name|pixmap
argument_list|(
name|size
argument_list|,
name|mode
argument_list|,
name|state
argument_list|)
return|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|key
name|QString
name|QIconLoaderEngine
operator|::
name|key
parameter_list|()
specifier|const
block|{
return|return
name|QLatin1String
argument_list|(
literal|"QIconLoaderEngine"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|virtual_hook
name|void
name|QIconLoaderEngine
operator|::
name|virtual_hook
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|ensureLoaded
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|id
condition|)
block|{
case|case
name|QIconEngine
operator|::
name|AvailableSizesHook
case|:
block|{
name|QIconEngine
operator|::
name|AvailableSizesArgument
modifier|&
name|arg
init|=
operator|*
cast|reinterpret_cast
argument_list|<
name|QIconEngine
operator|::
name|AvailableSizesArgument
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
specifier|const
name|QList
argument_list|<
name|QIconDirInfo
argument_list|>
name|directoryKey
init|=
name|iconLoaderInstance
argument_list|()
operator|->
name|theme
argument_list|()
operator|.
name|keyList
argument_list|()
decl_stmt|;
name|arg
operator|.
name|sizes
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// Gets all sizes from the DirectoryInfo entries
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_entries
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|size
init|=
name|m_entries
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|dir
operator|.
name|size
decl_stmt|;
name|arg
operator|.
name|sizes
operator|.
name|append
argument_list|(
name|QSize
argument_list|(
name|size
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
name|QIconEngine
operator|::
name|IconNameHook
case|:
block|{
name|QString
modifier|&
name|name
init|=
operator|*
cast|reinterpret_cast
argument_list|<
name|QString
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|name
operator|=
name|m_iconName
expr_stmt|;
block|}
break|break;
default|default:
name|QIconEngine
operator|::
name|virtual_hook
argument_list|(
name|id
argument_list|,
name|data
argument_list|)
expr_stmt|;
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
comment|//QT_NO_ICON
end_comment
end_unit
