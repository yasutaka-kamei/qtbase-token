begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_include
include|#
directive|include
file|"qfile.h"
end_include
begin_include
include|#
directive|include
file|"qsettings.h"
end_include
begin_include
include|#
directive|include
file|"qlibraryinfo.h"
end_include
begin_include
include|#
directive|include
file|"qscopedpointer.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
end_ifdef
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|QString
name|qmake_libraryInfoFile
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QT_END_NAMESPACE
else|#
directive|else
include|#
directive|include
file|"qcoreapplication.h"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_MAC
include|#
directive|include
file|"private/qcore_mac_p.h"
endif|#
directive|endif
include|#
directive|include
file|"qconfig.cpp"
name|QT_BEGIN_NAMESPACE
specifier|extern
name|void
name|qDumpCPUFeatures
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// in qsimd.cpp
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
end_ifndef
begin_struct
DECL|struct|QLibrarySettings
struct|struct
name|QLibrarySettings
block|{
name|QLibrarySettings
parameter_list|()
constructor_decl|;
DECL|member|settings
name|QScopedPointer
argument_list|<
name|QSettings
argument_list|>
name|settings
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
DECL|member|haveEffectivePaths
name|bool
name|haveEffectivePaths
decl_stmt|;
DECL|member|havePaths
name|bool
name|havePaths
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QLibrarySettings
argument_list|,
argument|qt_library_settings
argument_list|)
end_macro
begin_class
DECL|class|QLibraryInfoPrivate
class|class
name|QLibraryInfoPrivate
block|{
public|public:
specifier|static
name|QSettings
modifier|*
name|findConfiguration
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_BUILD_QMAKE
DECL|function|cleanup
specifier|static
name|void
name|cleanup
parameter_list|()
block|{
name|QLibrarySettings
modifier|*
name|ls
init|=
name|qt_library_settings
argument_list|()
decl_stmt|;
if|if
condition|(
name|ls
condition|)
name|ls
operator|->
name|settings
operator|.
name|reset
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
DECL|function|haveGroup
specifier|static
name|bool
name|haveGroup
parameter_list|(
name|QLibraryInfo
operator|::
name|PathGroup
name|group
parameter_list|)
block|{
name|QLibrarySettings
modifier|*
name|ls
init|=
name|qt_library_settings
argument_list|()
decl_stmt|;
return|return
name|ls
condition|?
operator|(
name|group
operator|==
name|QLibraryInfo
operator|::
name|EffectivePaths
condition|?
name|ls
operator|->
name|haveEffectivePaths
else|:
name|ls
operator|->
name|havePaths
operator|)
else|:
literal|false
return|;
block|}
endif|#
directive|endif
DECL|function|configuration
specifier|static
name|QSettings
modifier|*
name|configuration
parameter_list|()
block|{
name|QLibrarySettings
modifier|*
name|ls
init|=
name|qt_library_settings
argument_list|()
decl_stmt|;
return|return
name|ls
condition|?
name|ls
operator|->
name|settings
operator|.
name|data
argument_list|()
else|:
literal|0
return|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|QLibrarySettings
name|QLibrarySettings
operator|::
name|QLibrarySettings
parameter_list|()
member_init_list|:
name|settings
argument_list|(
name|QLibraryInfoPrivate
operator|::
name|findConfiguration
argument_list|()
argument_list|)
block|{
ifndef|#
directive|ifndef
name|QT_BUILD_QMAKE
name|qAddPostRoutine
argument_list|(
name|QLibraryInfoPrivate
operator|::
name|cleanup
argument_list|)
expr_stmt|;
name|bool
name|haveEffectivePaths
decl_stmt|;
name|bool
name|havePaths
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|settings
condition|)
block|{
comment|// This code needs to be in the regular library, as otherwise a qt.conf that
comment|// works for qmake would break things for dynamically built Qt tools.
name|QStringList
name|children
init|=
name|settings
operator|->
name|childGroups
argument_list|()
decl_stmt|;
name|haveEffectivePaths
operator|=
name|children
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"EffectivePaths"
argument_list|)
argument_list|)
expr_stmt|;
comment|// Backwards compat: an existing but empty file is claimed to contain the Paths section.
name|havePaths
operator|=
operator|!
name|haveEffectivePaths
operator|||
name|children
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"Paths"
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_BUILD_QMAKE
if|if
condition|(
operator|!
name|havePaths
condition|)
name|settings
operator|.
name|reset
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
block|}
else|else
block|{
name|haveEffectivePaths
operator|=
literal|false
expr_stmt|;
name|havePaths
operator|=
literal|false
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_constructor
begin_function
DECL|function|findConfiguration
name|QSettings
modifier|*
name|QLibraryInfoPrivate
operator|::
name|findConfiguration
parameter_list|()
block|{
name|QString
name|qtconfig
init|=
name|QStringLiteral
argument_list|(
literal|":/qt/etc/qt.conf"
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|qtconfig
argument_list|)
condition|)
name|qtconfig
operator|=
name|qmake_libraryInfoFile
argument_list|()
expr_stmt|;
else|#
directive|else
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|qtconfig
argument_list|)
operator|&&
name|QCoreApplication
operator|::
name|instance
argument_list|()
condition|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|CFBundleRef
name|bundleRef
init|=
name|CFBundleGetMainBundle
argument_list|()
decl_stmt|;
if|if
condition|(
name|bundleRef
condition|)
block|{
name|QCFType
argument_list|<
name|CFURLRef
argument_list|>
name|urlRef
init|=
name|CFBundleCopyResourceURL
argument_list|(
name|bundleRef
argument_list|,
name|QCFString
argument_list|(
name|QLatin1String
argument_list|(
literal|"qt.conf"
argument_list|)
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|urlRef
condition|)
block|{
name|QCFString
name|path
init|=
name|CFURLCopyFileSystemPath
argument_list|(
name|urlRef
argument_list|,
name|kCFURLPOSIXPathStyle
argument_list|)
decl_stmt|;
name|qtconfig
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|qtconfig
operator|.
name|isEmpty
argument_list|()
condition|)
endif|#
directive|endif
block|{
name|QDir
name|pwd
argument_list|(
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
argument_list|)
decl_stmt|;
name|qtconfig
operator|=
name|pwd
operator|.
name|filePath
argument_list|(
name|QLatin1String
argument_list|(
literal|"qt.conf"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|qtconfig
argument_list|)
condition|)
return|return
operator|new
name|QSettings
argument_list|(
name|qtconfig
argument_list|,
name|QSettings
operator|::
name|IniFormat
argument_list|)
return|;
return|return
literal|0
return|;
comment|//no luck
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SETTINGS
end_comment
begin_comment
comment|/*!     \class QLibraryInfo     \inmodule QtCore     \brief The QLibraryInfo class provides information about the Qt library.      Many pieces of information are established when Qt is configured and built.     This class provides an abstraction for accessing that information.     By using the static functions of this class, an application can obtain     information about the instance of the Qt library which the application     is using at run-time.      You can also use a \c qt.conf file to override the hard-coded paths     that are compiled into the Qt library. For more information, see     the \l {Using qt.conf} documentation.      \sa QSysInfo, {Using qt.conf} */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BUILD_QMAKE
end_ifndef
begin_comment
comment|/*!     \internal     You cannot create a QLibraryInfo, instead only the static functions are available to query    information. */
end_comment
begin_constructor
DECL|function|QLibraryInfo
name|QLibraryInfo
operator|::
name|QLibraryInfo
parameter_list|()
block|{ }
end_constructor
begin_comment
comment|/*!   Returns the person to whom this build of Qt is licensed.    \sa licensedProducts() */
end_comment
begin_function
name|QString
DECL|function|licensee
name|QLibraryInfo
operator|::
name|licensee
parameter_list|()
block|{
specifier|const
name|char
modifier|*
name|str
init|=
name|QT_CONFIGURE_LICENSEE
decl_stmt|;
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|str
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the products that the license for this build of Qt has access to.    \sa licensee() */
end_comment
begin_function
name|QString
DECL|function|licensedProducts
name|QLibraryInfo
operator|::
name|licensedProducts
parameter_list|()
block|{
specifier|const
name|char
modifier|*
name|str
init|=
name|QT_CONFIGURE_LICENSED_PRODUCTS
decl_stmt|;
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|str
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.6     Returns the installation date for this build of Qt. The install date will     usually be the last time that Qt sources were configured. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATESTRING
end_ifndef
begin_function
name|QDate
DECL|function|buildDate
name|QLibraryInfo
operator|::
name|buildDate
parameter_list|()
block|{
return|return
name|QDate
operator|::
name|fromString
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|qt_configure_installation
operator|+
literal|12
argument_list|)
argument_list|,
name|Qt
operator|::
name|ISODate
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_DATESTRING
end_comment
begin_comment
comment|/*!     \since 5.0     Returns true if this build of Qt was built with debugging enabled, or     false if it was built in release mode. */
end_comment
begin_function
name|bool
DECL|function|isDebugBuild
name|QLibraryInfo
operator|::
name|isDebugBuild
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG
return|return
literal|true
return|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_BUILD_QMAKE
end_comment
begin_struct
specifier|static
specifier|const
struct|struct
block|{
DECL|member|key
DECL|member|value
name|char
name|key
index|[
literal|14
index|]
decl_stmt|,
name|value
index|[
literal|13
index|]
decl_stmt|;
block|}
DECL|variable|qtConfEntries
name|qtConfEntries
index|[]
init|=
block|{
block|{
literal|"Prefix"
block|,
literal|"."
block|}
block|,
block|{
literal|"Documentation"
block|,
literal|"doc"
block|}
block|,
block|{
literal|"Headers"
block|,
literal|"include"
block|}
block|,
block|{
literal|"Libraries"
block|,
literal|"lib"
block|}
block|,
block|{
literal|"Binaries"
block|,
literal|"bin"
block|}
block|,
block|{
literal|"Plugins"
block|,
literal|"plugins"
block|}
block|,
block|{
literal|"Imports"
block|,
literal|"imports"
block|}
block|,
block|{
literal|"Data"
block|,
literal|"."
block|}
block|,
block|{
literal|"Translations"
block|,
literal|"translations"
block|}
block|,
block|{
literal|"Examples"
block|,
literal|"examples"
block|}
block|,
block|{
literal|"Tests"
block|,
literal|"tests"
block|}
block|,
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
block|{
literal|"Sysroot"
block|,
literal|""
block|}
block|,
block|{
literal|"HostPrefix"
block|,
literal|""
block|}
block|,
block|{
literal|"HostBinaries"
block|,
literal|"bin"
block|}
block|,
block|{
literal|"HostData"
block|,
literal|"."
block|}
block|,
endif|#
directive|endif
block|}
struct|;
end_struct
begin_comment
comment|/*!   Returns the location specified by \a loc.  */
end_comment
begin_function
name|QString
DECL|function|location
name|QLibraryInfo
operator|::
name|location
parameter_list|(
name|LibraryLocation
name|loc
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
name|QString
name|ret
init|=
name|rawLocation
argument_list|(
name|loc
argument_list|,
name|FinalPaths
argument_list|)
decl_stmt|;
comment|// Automatically prepend the sysroot to target paths
if|if
condition|(
name|loc
argument_list|<
name|SysrootPath
operator|||
name|loc
argument_list|>
name|LastHostPath
condition|)
block|{
name|QString
name|sysroot
init|=
name|rawLocation
argument_list|(
name|SysrootPath
argument_list|,
name|FinalPaths
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|sysroot
operator|.
name|isEmpty
argument_list|()
operator|&&
name|ret
operator|.
name|length
argument_list|()
operator|>
literal|2
operator|&&
name|ret
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
operator|&&
operator|(
name|ret
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|||
name|ret
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
operator|)
condition|)
name|ret
operator|.
name|replace
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|,
name|sysroot
argument_list|)
expr_stmt|;
comment|// Strip out the drive on Windows targets
else|else
name|ret
operator|.
name|prepend
argument_list|(
name|sysroot
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
name|QString
DECL|function|rawLocation
name|QLibraryInfo
operator|::
name|rawLocation
parameter_list|(
name|LibraryLocation
name|loc
parameter_list|,
name|PathGroup
name|group
parameter_list|)
block|{
else|#
directive|else
define|#
directive|define
name|rawLocation
parameter_list|(
name|loca
parameter_list|,
name|group
parameter_list|)
value|location(loca)
define|#
directive|define
name|group
value|dummy
endif|#
directive|endif
name|QString
name|ret
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
comment|// Logic for choosing the right data source: if EffectivePaths are requested
comment|// and qt.conf with that section is present, use it, otherwise fall back to
comment|// FinalPaths. For FinalPaths, use qt.conf if present and contains not only
comment|// [EffectivePaths], otherwise fall back to builtins.
if|if
condition|(
operator|!
name|QLibraryInfoPrivate
operator|::
name|haveGroup
argument_list|(
name|group
argument_list|)
operator|&&
operator|(
name|group
operator|==
name|FinalPaths
operator|||
operator|!
operator|(
name|group
operator|=
name|FinalPaths
operator|,
name|QLibraryInfoPrivate
operator|::
name|haveGroup
argument_list|(
name|FinalPaths
argument_list|)
operator|)
operator|)
condition|)
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|QT_NO_SETTINGS
argument_list|)
if|if
condition|(
operator|!
name|QLibraryInfoPrivate
operator|::
name|configuration
argument_list|()
condition|)
endif|#
directive|endif
block|{
specifier|const
name|char
modifier|*
name|path
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|loc
operator|>=
literal|0
operator|&&
name|loc
operator|<
sizeof|sizeof
argument_list|(
name|qt_configure_prefix_path_strs
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|qt_configure_prefix_path_strs
index|[
literal|0
index|]
argument_list|)
condition|)
name|path
operator|=
name|qt_configure_prefix_path_strs
index|[
name|loc
index|]
operator|+
literal|12
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WIN
comment|// On Windows we use the registry
elseif|else
if|if
condition|(
name|loc
operator|==
name|SettingsPath
condition|)
name|path
operator|=
name|QT_CONFIGURE_SETTINGS_PATH
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|path
condition|)
name|ret
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|path
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
block|}
else|else
block|{
name|QString
name|key
decl_stmt|;
name|QString
name|defaultValue
decl_stmt|;
if|if
condition|(
name|loc
operator|>=
literal|0
operator|&&
name|loc
operator|<
sizeof|sizeof
argument_list|(
name|qtConfEntries
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|qtConfEntries
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
name|key
operator|=
name|QLatin1String
argument_list|(
name|qtConfEntries
index|[
name|loc
index|]
operator|.
name|key
argument_list|)
expr_stmt|;
name|defaultValue
operator|=
name|QLatin1String
argument_list|(
name|qtConfEntries
index|[
name|loc
index|]
operator|.
name|value
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|Q_OS_WIN
comment|// On Windows we use the registry
elseif|else
if|if
condition|(
name|loc
operator|==
name|SettingsPath
condition|)
name|key
operator|=
name|QLatin1String
argument_list|(
literal|"Settings"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|key
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QSettings
modifier|*
name|config
init|=
name|QLibraryInfoPrivate
operator|::
name|configuration
argument_list|()
decl_stmt|;
name|config
operator|->
name|beginGroup
argument_list|(
name|QLatin1String
argument_list|(
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
name|group
operator|==
name|EffectivePaths
condition|?
literal|"EffectivePaths"
else|:
endif|#
directive|endif
literal|"Paths"
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|=
name|config
operator|->
name|value
argument_list|(
name|key
argument_list|,
name|defaultValue
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
if|if
condition|(
name|ret
operator|.
name|isEmpty
argument_list|()
operator|&&
name|loc
operator|==
name|HostPrefixPath
condition|)
name|ret
operator|=
name|config
operator|->
name|value
argument_list|(
name|QLatin1String
argument_list|(
name|qtConfEntries
index|[
name|PrefixPath
index|]
operator|.
name|key
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|qtConfEntries
index|[
name|PrefixPath
index|]
operator|.
name|value
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// expand environment variables in the form $(ENVVAR)
name|int
name|rep
decl_stmt|;
name|QRegExp
name|reg_var
argument_list|(
name|QLatin1String
argument_list|(
literal|"\\$\\(.*\\)"
argument_list|)
argument_list|)
decl_stmt|;
name|reg_var
operator|.
name|setMinimal
argument_list|(
literal|true
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|rep
operator|=
name|reg_var
operator|.
name|indexIn
argument_list|(
name|ret
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
name|ret
operator|.
name|replace
argument_list|(
name|rep
argument_list|,
name|reg_var
operator|.
name|matchedLength
argument_list|()
argument_list|,
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
name|ret
operator|.
name|mid
argument_list|(
name|rep
operator|+
literal|2
argument_list|,
name|reg_var
operator|.
name|matchedLength
argument_list|()
operator|-
literal|3
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|config
operator|->
name|endGroup
argument_list|()
expr_stmt|;
name|ret
operator|=
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|ret
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// QT_NO_SETTINGS
block|}
if|if
condition|(
operator|!
name|ret
operator|.
name|isEmpty
argument_list|()
operator|&&
name|QDir
operator|::
name|isRelativePath
argument_list|(
name|ret
argument_list|)
condition|)
block|{
name|QString
name|baseDir
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_BUILD_QMAKE
if|if
condition|(
name|loc
operator|==
name|HostPrefixPath
operator|||
name|loc
operator|==
name|PrefixPath
operator|||
name|loc
operator|==
name|SysrootPath
condition|)
block|{
comment|// We make the prefix/sysroot path absolute to the executable's directory.
comment|// loc == PrefixPath while a sysroot is set would make no sense here.
comment|// loc == SysrootPath only makes sense if qmake lives inside the sysroot itself.
name|baseDir
operator|=
name|QFileInfo
argument_list|(
name|qmake_libraryInfoFile
argument_list|()
argument_list|)
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|loc
operator|>
name|SysrootPath
operator|&&
name|loc
operator|<=
name|LastHostPath
condition|)
block|{
comment|// We make any other host path absolute to the host prefix directory.
name|baseDir
operator|=
name|rawLocation
argument_list|(
name|HostPrefixPath
argument_list|,
name|group
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|loc
operator|==
name|PrefixPath
condition|)
block|{
if|if
condition|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
condition|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|CFBundleRef
name|bundleRef
init|=
name|CFBundleGetMainBundle
argument_list|()
decl_stmt|;
if|if
condition|(
name|bundleRef
condition|)
block|{
name|QCFType
argument_list|<
name|CFURLRef
argument_list|>
name|urlRef
init|=
name|CFBundleCopyBundleURL
argument_list|(
name|bundleRef
argument_list|)
decl_stmt|;
if|if
condition|(
name|urlRef
condition|)
block|{
name|QCFString
name|path
init|=
name|CFURLCopyFileSystemPath
argument_list|(
name|urlRef
argument_list|,
name|kCFURLPOSIXPathStyle
argument_list|)
decl_stmt|;
return|return
name|QDir
operator|::
name|cleanPath
argument_list|(
name|QString
argument_list|(
name|path
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|"/Contents/"
argument_list|)
operator|+
name|ret
argument_list|)
return|;
block|}
block|}
endif|#
directive|endif
comment|// We make the prefix path absolute to the executable's directory.
name|baseDir
operator|=
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|baseDir
operator|=
name|QDir
operator|::
name|currentPath
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
else|else
block|{
comment|// we make any other path absolute to the prefix directory
name|baseDir
operator|=
name|rawLocation
argument_list|(
name|PrefixPath
argument_list|,
name|group
argument_list|)
expr_stmt|;
block|}
name|ret
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|baseDir
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|ret
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
comment|/*!     \enum QLibraryInfo::LibraryLocation      \keyword library location      This enum type is used to specify a specific location     specifier:      \value PrefixPath The default prefix for all paths.     \value DocumentationPath The location for documentation upon install.     \value HeadersPath The location for all headers.     \value LibrariesPath The location of installed libraries.     \value BinariesPath The location of installed Qt binaries (tools and applications).     \value PluginsPath The location of installed Qt plugins.     \value ImportsPath The location of installed QML extensions to import.     \value DataPath The location of general Qt data.     \value TranslationsPath The location of translation information for Qt strings.     \value ExamplesPath The location for examples upon install.     \value TestsPath The location of installed Qt testcases.     \value SettingsPath The location for Qt settings. Not applicable on Windows.      \sa location() */
name|QT_END_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
name|defined
argument_list|(
name|ELF_INTERPRETER
argument_list|)
include|#
directive|include
file|<stdio.h>
include|#
directive|include
file|<stdlib.h>
DECL|variable|qt_core_interpreter
specifier|extern
specifier|const
name|char
name|qt_core_interpreter
index|[]
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".interp"
argument_list|)
operator|)
argument_list|)
init|=
name|ELF_INTERPRETER
decl_stmt|;
extern|extern
literal|"C"
name|void
name|qt_core_boilerplate
argument_list|()
decl_stmt|;
DECL|function|qt_core_boilerplate
name|void
name|qt_core_boilerplate
parameter_list|()
block|{
name|printf
argument_list|(
literal|"This is the QtCore library version "
name|QT_VERSION_STR
literal|"\n"
literal|"Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).\n"
literal|"Contact: http://www.qt-project.org/legal\n"
literal|"\n"
literal|"Build date:          %s\n"
literal|"Installation prefix: %s\n"
literal|"Library path:        %s\n"
literal|"Include path:        %s\n"
argument_list|,
name|qt_configure_installation
operator|+
literal|12
argument_list|,
name|qt_configure_prefix_path_strs
index|[
name|QT_PREPEND_NAMESPACE
argument_list|(
name|QLibraryInfo
argument_list|)
operator|::
name|PrefixPath
index|]
operator|+
literal|12
argument_list|,
name|qt_configure_prefix_path_strs
index|[
name|QT_PREPEND_NAMESPACE
argument_list|(
name|QLibraryInfo
argument_list|)
operator|::
name|LibrariesPath
index|]
operator|+
literal|12
argument_list|,
name|qt_configure_prefix_path_strs
index|[
name|QT_PREPEND_NAMESPACE
argument_list|(
name|QLibraryInfo
argument_list|)
operator|::
name|HeadersPath
index|]
operator|+
literal|12
argument_list|)
expr_stmt|;
name|QT_PREPEND_NAMESPACE
function_decl|(
name|qDumpCPUFeatures
function_decl|)
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|QT_EVAL
specifier|extern
name|void
name|qt_core_eval_init
argument_list|(
name|uint
argument_list|)
decl_stmt|;
name|qt_core_eval_init
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
end_unit
