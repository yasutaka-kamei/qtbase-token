begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qguiplatformplugin_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qsettings.h>
end_include
begin_include
include|#
directive|include
file|"private/qfactoryloader_p.h"
end_include
begin_include
include|#
directive|include
file|"qstylefactory.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qicon.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|"qguifunctions_wince.h"
end_include
begin_function_decl
specifier|extern
name|bool
name|qt_wince_is_smartphone
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//qguifunctions_wince.cpp
end_comment
begin_function_decl
specifier|extern
name|bool
name|qt_wince_is_mobile
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//qguifunctions_wince.cpp
end_comment
begin_function_decl
specifier|extern
name|bool
name|qt_wince_is_pocket_pc
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//qguifunctions_wince.cpp
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
end_if
begin_include
include|#
directive|include
file|<private/qkde_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qgtkstyle_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qt_x11_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*! \internal     Return (an construct if necesseray) the Gui Platform plugin.      The plugin key to be loaded is inside the QT_PLATFORM_PLUGIN environment variable.     If it is not set, it will be the DESKTOP_SESSION on X11.      If no plugin can be loaded, the default one is returned.  */
DECL|function|qt_guiPlatformPlugin
name|QGuiPlatformPlugin
modifier|*
name|qt_guiPlatformPlugin
parameter_list|()
block|{
specifier|static
name|QGuiPlatformPlugin
modifier|*
name|plugin
decl_stmt|;
if|if
condition|(
operator|!
name|plugin
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|QString
name|key
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"QT_PLATFORM_PLUGIN"
argument_list|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_X11
if|if
condition|(
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|X11
operator|->
name|desktopEnvironment
condition|)
block|{
case|case
name|DE_KDE
case|:
name|key
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"kde"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|key
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"DESKTOP_SESSION"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
endif|#
directive|endif
if|if
condition|(
operator|!
name|key
operator|.
name|isEmpty
argument_list|()
operator|&&
name|QApplication
operator|::
name|desktopSettingsAware
argument_list|()
condition|)
block|{
name|QFactoryLoader
name|loader
argument_list|(
name|QGuiPlatformPluginInterface_iid
argument_list|,
name|QLatin1String
argument_list|(
literal|"/gui_platform"
argument_list|)
argument_list|)
decl_stmt|;
name|plugin
operator|=
name|qobject_cast
argument_list|<
name|QGuiPlatformPlugin
operator|*
argument_list|>
argument_list|(
name|loader
operator|.
name|instance
argument_list|(
name|key
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// QT_NO_LIBRARY
if|if
condition|(
operator|!
name|plugin
condition|)
block|{
specifier|static
name|QGuiPlatformPlugin
name|def
decl_stmt|;
name|plugin
operator|=
operator|&
name|def
expr_stmt|;
block|}
block|}
return|return
name|plugin
return|;
block|}
end_function
begin_comment
comment|/* \class QPlatformPlugin     QGuiPlatformPlugin can be used to integrate Qt applications in a platform built on top of Qt.     The application developer should not know or use the plugin, it is only used by Qt internaly.      But full platforms that are built on top of Qt may provide a plugin so 3rd party Qt applications     running on the platform are integrated.  */
end_comment
begin_comment
comment|/*     The constructor can be used to install hooks in Qt  */
end_comment
begin_constructor
DECL|function|QGuiPlatformPlugin
name|QGuiPlatformPlugin
operator|::
name|QGuiPlatformPlugin
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{}
end_constructor
begin_destructor
DECL|function|~QGuiPlatformPlugin
name|QGuiPlatformPlugin
operator|::
name|~
name|QGuiPlatformPlugin
parameter_list|()
block|{}
end_destructor
begin_comment
comment|/* return the string key to be used by default the application */
end_comment
begin_function
DECL|function|styleName
name|QString
name|QGuiPlatformPlugin
operator|::
name|styleName
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_WS_WINCE
argument_list|)
if|if
condition|(
name|qt_wince_is_smartphone
argument_list|()
operator|||
name|qt_wince_is_pocket_pc
argument_list|()
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"WindowsMobile"
argument_list|)
return|;
else|else
return|return
name|QLatin1String
argument_list|(
literal|"WindowsCE"
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
if|if
condition|(
operator|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|>=
name|QSysInfo
operator|::
name|WV_VISTA
operator|&&
name|QSysInfo
operator|::
name|WindowsVersion
operator|<
name|QSysInfo
operator|::
name|WV_NT_based
operator|)
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"WindowsVista"
argument_list|)
return|;
elseif|else
if|if
condition|(
operator|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|>=
name|QSysInfo
operator|::
name|WV_XP
operator|&&
name|QSysInfo
operator|::
name|WindowsVersion
operator|<
name|QSysInfo
operator|::
name|WV_NT_based
operator|)
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"WindowsXP"
argument_list|)
return|;
else|else
return|return
name|QLatin1String
argument_list|(
literal|"Windows"
argument_list|)
return|;
comment|// default styles for Windows
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_OS_SOLARIS
argument_list|)
return|return
name|QLatin1String
argument_list|(
literal|"CDE"
argument_list|)
return|;
comment|// default style for X11 on Solaris
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_OS_IRIX
argument_list|)
return|return
name|QLatin1String
argument_list|(
literal|"SGI"
argument_list|)
return|;
comment|// default style for X11 on IRIX
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
return|return
name|QLatin1String
argument_list|(
literal|"Macintosh"
argument_list|)
return|;
comment|// default style for all Mac's
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|QString
name|stylename
decl_stmt|;
switch|switch
condition|(
name|X11
operator|->
name|desktopEnvironment
condition|)
block|{
case|case
name|DE_KDE
case|:
name|stylename
operator|=
name|QKde
operator|::
name|kdeStyle
argument_list|()
expr_stmt|;
break|break;
case|case
name|DE_GNOME
case|:
block|{
name|QStringList
name|availableStyles
init|=
name|QStyleFactory
operator|::
name|keys
argument_list|()
decl_stmt|;
comment|// Set QGtkStyle for GNOME if available
name|QString
name|gtkStyleKey
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"GTK+"
argument_list|)
decl_stmt|;
if|if
condition|(
name|availableStyles
operator|.
name|contains
argument_list|(
name|gtkStyleKey
argument_list|)
condition|)
block|{
name|stylename
operator|=
name|gtkStyleKey
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|X11
operator|->
name|use_xrender
condition|)
name|stylename
operator|=
name|QLatin1String
argument_list|(
literal|"cleanlooks"
argument_list|)
expr_stmt|;
else|else
name|stylename
operator|=
name|QLatin1String
argument_list|(
literal|"windows"
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|DE_CDE
case|:
name|stylename
operator|=
name|QLatin1String
argument_list|(
literal|"cde"
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|// Don't do anything
break|break;
block|}
return|return
name|stylename
return|;
else|#
directive|else
return|return
name|QLatin1String
argument_list|(
literal|"Plastique"
argument_list|)
return|;
comment|// default style for X11 and small devices
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/* return an additional default palette  (only work on X11) */
end_comment
begin_function
DECL|function|palette
name|QPalette
name|QGuiPlatformPlugin
operator|::
name|palette
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_WS_X11
if|if
condition|(
name|QApplication
operator|::
name|desktopSettingsAware
argument_list|()
operator|&&
name|X11
operator|->
name|desktopEnvironment
operator|==
name|DE_KDE
condition|)
return|return
name|QKde
operator|::
name|kdePalette
argument_list|()
return|;
endif|#
directive|endif
return|return
name|QPalette
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/* the default icon theme name for QIcon::fromTheme. */
end_comment
begin_function
DECL|function|systemIconThemeName
name|QString
name|QGuiPlatformPlugin
operator|::
name|systemIconThemeName
parameter_list|()
block|{
name|QString
name|result
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_X11
if|if
condition|(
name|X11
operator|->
name|desktopEnvironment
operator|==
name|DE_GNOME
condition|)
block|{
name|result
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"gnome"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_STYLE_GTK
name|result
operator|=
name|QGtkStylePrivate
operator|::
name|getGConfString
argument_list|(
name|QLatin1String
argument_list|(
literal|"/desktop/gnome/interface/icon_theme"
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|X11
operator|->
name|desktopEnvironment
operator|==
name|DE_KDE
condition|)
block|{
name|result
operator|=
name|X11
operator|->
name|desktopVersion
operator|>=
literal|4
condition|?
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"oxygen"
argument_list|)
else|:
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"crystalsvg"
argument_list|)
expr_stmt|;
name|QSettings
name|settings
argument_list|(
name|QKde
operator|::
name|kdeHome
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/share/config/kdeglobals"
argument_list|)
argument_list|,
name|QSettings
operator|::
name|IniFormat
argument_list|)
decl_stmt|;
name|settings
operator|.
name|beginGroup
argument_list|(
name|QLatin1String
argument_list|(
literal|"Icons"
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|=
name|settings
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"Theme"
argument_list|)
argument_list|,
name|result
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|iconThemeSearchPaths
name|QStringList
name|QGuiPlatformPlugin
operator|::
name|iconThemeSearchPaths
parameter_list|()
block|{
name|QStringList
name|paths
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|QString
name|xdgDirString
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|getenv
argument_list|(
literal|"XDG_DATA_DIRS"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|xdgDirString
operator|.
name|isEmpty
argument_list|()
condition|)
name|xdgDirString
operator|=
name|QLatin1String
argument_list|(
literal|"/usr/local/share/:/usr/share/"
argument_list|)
expr_stmt|;
name|QStringList
name|xdgDirs
init|=
name|xdgDirString
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
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
name|xdgDirs
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QDir
name|dir
argument_list|(
name|xdgDirs
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|dir
operator|.
name|exists
argument_list|()
condition|)
name|paths
operator|.
name|append
argument_list|(
name|dir
operator|.
name|path
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/icons"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|X11
operator|->
name|desktopEnvironment
operator|==
name|DE_KDE
condition|)
block|{
name|paths
operator|<<
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
operator|+
name|QKde
operator|::
name|kdeHome
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/share/icons"
argument_list|)
expr_stmt|;
name|QStringList
name|kdeDirs
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|getenv
argument_list|(
literal|"KDEDIRS"
argument_list|)
argument_list|)
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
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
name|kdeDirs
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QDir
name|dir
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
operator|+
name|kdeDirs
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|"/share/icons"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|dir
operator|.
name|exists
argument_list|()
condition|)
name|paths
operator|.
name|append
argument_list|(
name|dir
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Add home directory first in search path
name|QDir
name|homeDir
argument_list|(
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/.icons"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|homeDir
operator|.
name|exists
argument_list|()
condition|)
name|paths
operator|.
name|prepend
argument_list|(
name|homeDir
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
name|paths
operator|.
name|append
argument_list|(
name|qApp
operator|->
name|applicationDirPath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/icons"
argument_list|)
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|paths
operator|.
name|append
argument_list|(
name|qApp
operator|->
name|applicationDirPath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/../Resources/icons"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|paths
return|;
block|}
end_function
begin_comment
comment|/* backend for QFileIconProvider,  null icon means default */
end_comment
begin_function
DECL|function|fileSystemIcon
name|QIcon
name|QGuiPlatformPlugin
operator|::
name|fileSystemIcon
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
parameter_list|)
block|{
return|return
name|QIcon
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/* Like QStyle::styleHint */
end_comment
begin_function
DECL|function|platformHint
name|int
name|QGuiPlatformPlugin
operator|::
name|platformHint
parameter_list|(
name|PlatformHint
name|hint
parameter_list|)
block|{
name|int
name|ret
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|PH_ToolButtonStyle
case|:
name|ret
operator|=
name|Qt
operator|::
name|ToolButtonIconOnly
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_X11
if|if
condition|(
name|X11
operator|->
name|desktopEnvironment
operator|==
name|DE_KDE
operator|&&
name|X11
operator|->
name|desktopVersion
operator|>=
literal|4
operator|&&
name|QApplication
operator|::
name|desktopSettingsAware
argument_list|()
condition|)
block|{
name|ret
operator|=
name|QKde
operator|::
name|kdeToolButtonStyle
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
break|break;
case|case
name|PH_ToolBarIconSize
case|:
ifdef|#
directive|ifdef
name|Q_WS_X11
if|if
condition|(
name|X11
operator|->
name|desktopEnvironment
operator|==
name|DE_KDE
operator|&&
name|X11
operator|->
name|desktopVersion
operator|>=
literal|4
operator|&&
name|QApplication
operator|::
name|desktopSettingsAware
argument_list|()
condition|)
block|{
name|ret
operator|=
name|QKde
operator|::
name|kdeToolBarIconSize
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
comment|//by default keep ret = 0 so QCommonStyle will use the style default
break|break;
default|default:
break|break;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
