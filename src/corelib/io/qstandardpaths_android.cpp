begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstandardpaths.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STANDARDPATHS
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/private/qjni_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qjnihelpers_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|AndroidDirCache
typedef|typedef
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|AndroidDirCache
typedef|;
end_typedef
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|AndroidDirCache
argument_list|,
argument|androidDirCache
argument_list|)
end_macro
begin_function
DECL|function|testDir
specifier|static
name|QString
name|testDir
parameter_list|()
block|{
return|return
name|QStandardPaths
operator|::
name|isTestModeEnabled
argument_list|()
condition|?
name|QLatin1String
argument_list|(
literal|"/qttest"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|""
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|applicationContext
specifier|static
name|QJNIObjectPrivate
name|applicationContext
parameter_list|()
block|{
specifier|static
name|QJNIObjectPrivate
name|appCtx
decl_stmt|;
if|if
condition|(
name|appCtx
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|appCtx
return|;
name|QJNIObjectPrivate
name|context
argument_list|(
name|QtAndroidPrivate
operator|::
name|activity
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|context
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|context
operator|=
name|QtAndroidPrivate
operator|::
name|service
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|context
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|appCtx
return|;
block|}
name|appCtx
operator|=
name|context
operator|.
name|callObjectMethod
argument_list|(
literal|"getApplicationContext"
argument_list|,
literal|"()Landroid/content/Context;"
argument_list|)
expr_stmt|;
return|return
name|appCtx
return|;
block|}
end_function
begin_function
DECL|function|getAbsolutePath
specifier|static
specifier|inline
name|QString
name|getAbsolutePath
parameter_list|(
specifier|const
name|QJNIObjectPrivate
modifier|&
name|file
parameter_list|)
block|{
name|QJNIObjectPrivate
name|path
init|=
name|file
operator|.
name|callObjectMethod
argument_list|(
literal|"getAbsolutePath"
argument_list|,
literal|"()Ljava/lang/String;"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|path
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*  * The root of the external storage  *  */
end_comment
begin_function
DECL|function|getExternalStorageDirectory
specifier|static
name|QString
name|getExternalStorageDirectory
parameter_list|()
block|{
name|QString
modifier|&
name|path
init|=
operator|(
operator|*
name|androidDirCache
operator|)
index|[
name|QStringLiteral
argument_list|(
literal|"EXT_ROOT"
argument_list|)
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|path
return|;
name|QJNIObjectPrivate
name|file
init|=
name|QJNIObjectPrivate
operator|::
name|callStaticObjectMethod
argument_list|(
literal|"android/os/Environment"
argument_list|,
literal|"getExternalStorageDirectory"
argument_list|,
literal|"()Ljava/io/File;"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
operator|(
name|path
operator|=
name|getAbsolutePath
argument_list|(
name|file
argument_list|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/*  * Locations where applications can place user files (public).  * E.g., /storage/Music  */
end_comment
begin_function
DECL|function|getExternalStoragePublicDirectory
specifier|static
name|QString
name|getExternalStoragePublicDirectory
parameter_list|(
specifier|const
name|char
modifier|*
name|directoryField
parameter_list|)
block|{
name|QString
modifier|&
name|path
init|=
operator|(
operator|*
name|androidDirCache
operator|)
index|[
name|QLatin1String
argument_list|(
name|directoryField
argument_list|)
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|path
return|;
name|QJNIObjectPrivate
name|dirField
init|=
name|QJNIObjectPrivate
operator|::
name|getStaticObjectField
argument_list|(
literal|"android/os/Environment"
argument_list|,
name|directoryField
argument_list|,
literal|"Ljava/lang/String;"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|dirField
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
name|QJNIObjectPrivate
name|file
init|=
name|QJNIObjectPrivate
operator|::
name|callStaticObjectMethod
argument_list|(
literal|"android/os/Environment"
argument_list|,
literal|"getExternalStoragePublicDirectory"
argument_list|,
literal|"(Ljava/lang/String;)Ljava/io/File;"
argument_list|,
name|dirField
operator|.
name|object
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
operator|(
name|path
operator|=
name|getAbsolutePath
argument_list|(
name|file
argument_list|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/*  * Locations where applications can place persistent files it owns.  * E.g., /storage/org.app/Music  */
end_comment
begin_function
DECL|function|getExternalFilesDir
specifier|static
name|QString
name|getExternalFilesDir
parameter_list|(
specifier|const
name|char
modifier|*
name|directoryField
init|=
literal|0
parameter_list|)
block|{
name|QString
modifier|&
name|path
init|=
operator|(
operator|*
name|androidDirCache
operator|)
index|[
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"APPNAME_%1"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|directoryField
argument_list|)
argument_list|)
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|path
return|;
name|QJNIObjectPrivate
name|appCtx
init|=
name|applicationContext
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|appCtx
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
name|QJNIObjectPrivate
name|dirField
init|=
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|QLatin1String
argument_list|(
literal|""
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|directoryField
condition|)
block|{
name|dirField
operator|=
name|QJNIObjectPrivate
operator|::
name|getStaticObjectField
argument_list|(
literal|"android/os/Environment"
argument_list|,
name|directoryField
argument_list|,
literal|"Ljava/lang/String;"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dirField
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
block|}
name|QJNIObjectPrivate
name|file
init|=
name|appCtx
operator|.
name|callObjectMethod
argument_list|(
literal|"getExternalFilesDir"
argument_list|,
literal|"(Ljava/lang/String;)Ljava/io/File;"
argument_list|,
name|dirField
operator|.
name|object
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
operator|(
name|path
operator|=
name|getAbsolutePath
argument_list|(
name|file
argument_list|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/*  * Directory where applications can store cache files it owns (public).  * E.g., /storage/org.app/  */
end_comment
begin_function
DECL|function|getExternalCacheDir
specifier|static
name|QString
name|getExternalCacheDir
parameter_list|()
block|{
name|QString
modifier|&
name|path
init|=
operator|(
operator|*
name|androidDirCache
operator|)
index|[
name|QStringLiteral
argument_list|(
literal|"APPNAME_CACHE"
argument_list|)
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|path
return|;
name|QJNIObjectPrivate
name|appCtx
init|=
name|applicationContext
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|appCtx
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
name|QJNIObjectPrivate
name|file
init|=
name|appCtx
operator|.
name|callObjectMethod
argument_list|(
literal|"getExternalCacheDir"
argument_list|,
literal|"()Ljava/io/File;"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
operator|(
name|path
operator|=
name|getAbsolutePath
argument_list|(
name|file
argument_list|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/*  * Directory where applications can store cache files it owns (private).  */
end_comment
begin_function
DECL|function|getCacheDir
specifier|static
name|QString
name|getCacheDir
parameter_list|()
block|{
name|QString
modifier|&
name|path
init|=
operator|(
operator|*
name|androidDirCache
operator|)
index|[
name|QStringLiteral
argument_list|(
literal|"APPROOT_CACHE"
argument_list|)
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|path
return|;
name|QJNIObjectPrivate
name|appCtx
init|=
name|applicationContext
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|appCtx
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
name|QJNIObjectPrivate
name|file
init|=
name|appCtx
operator|.
name|callObjectMethod
argument_list|(
literal|"getCacheDir"
argument_list|,
literal|"()Ljava/io/File;"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
operator|(
name|path
operator|=
name|getAbsolutePath
argument_list|(
name|file
argument_list|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/*  * Directory where applications can store files it owns (private).  * (Same location as $HOME)  */
end_comment
begin_function
DECL|function|getFilesDir
specifier|static
name|QString
name|getFilesDir
parameter_list|()
block|{
name|QString
modifier|&
name|path
init|=
operator|(
operator|*
name|androidDirCache
operator|)
index|[
name|QStringLiteral
argument_list|(
literal|"APPROOT_FILES"
argument_list|)
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|path
return|;
return|return
operator|(
name|path
operator|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|writableLocation
name|QString
name|QStandardPaths
operator|::
name|writableLocation
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QStandardPaths
operator|::
name|MusicLocation
case|:
return|return
name|getExternalStoragePublicDirectory
argument_list|(
literal|"DIRECTORY_MUSIC"
argument_list|)
return|;
case|case
name|QStandardPaths
operator|::
name|MoviesLocation
case|:
return|return
name|getExternalStoragePublicDirectory
argument_list|(
literal|"DIRECTORY_MOVIES"
argument_list|)
return|;
case|case
name|QStandardPaths
operator|::
name|PicturesLocation
case|:
return|return
name|getExternalStoragePublicDirectory
argument_list|(
literal|"DIRECTORY_PICTURES"
argument_list|)
return|;
case|case
name|QStandardPaths
operator|::
name|DocumentsLocation
case|:
if|if
condition|(
name|QtAndroidPrivate
operator|::
name|androidSdkVersion
argument_list|()
operator|>
literal|18
condition|)
return|return
name|getExternalStoragePublicDirectory
argument_list|(
literal|"DIRECTORY_DOCUMENTS"
argument_list|)
return|;
else|else
return|return
name|getExternalStorageDirectory
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/Documents"
argument_list|)
return|;
case|case
name|QStandardPaths
operator|::
name|DownloadLocation
case|:
return|return
name|getExternalStoragePublicDirectory
argument_list|(
literal|"DIRECTORY_DOWNLOADS"
argument_list|)
return|;
case|case
name|QStandardPaths
operator|::
name|GenericConfigLocation
case|:
case|case
name|QStandardPaths
operator|::
name|ConfigLocation
case|:
case|case
name|QStandardPaths
operator|::
name|AppConfigLocation
case|:
return|return
name|getFilesDir
argument_list|()
operator|+
name|testDir
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/settings"
argument_list|)
return|;
case|case
name|QStandardPaths
operator|::
name|GenericDataLocation
case|:
return|return
name|getExternalStorageDirectory
argument_list|()
operator|+
name|testDir
argument_list|()
return|;
case|case
name|QStandardPaths
operator|::
name|AppDataLocation
case|:
case|case
name|QStandardPaths
operator|::
name|AppLocalDataLocation
case|:
return|return
name|getFilesDir
argument_list|()
operator|+
name|testDir
argument_list|()
return|;
case|case
name|QStandardPaths
operator|::
name|GenericCacheLocation
case|:
case|case
name|QStandardPaths
operator|::
name|RuntimeLocation
case|:
case|case
name|QStandardPaths
operator|::
name|TempLocation
case|:
case|case
name|QStandardPaths
operator|::
name|CacheLocation
case|:
return|return
name|getCacheDir
argument_list|()
operator|+
name|testDir
argument_list|()
return|;
case|case
name|QStandardPaths
operator|::
name|DesktopLocation
case|:
case|case
name|QStandardPaths
operator|::
name|HomeLocation
case|:
return|return
name|getFilesDir
argument_list|()
return|;
case|case
name|QStandardPaths
operator|::
name|ApplicationsLocation
case|:
case|case
name|QStandardPaths
operator|::
name|FontsLocation
case|:
default|default:
break|break;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|standardLocations
name|QStringList
name|QStandardPaths
operator|::
name|standardLocations
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|==
name|MusicLocation
condition|)
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|writableLocation
argument_list|(
name|type
argument_list|)
operator|<<
name|getExternalFilesDir
argument_list|(
literal|"DIRECTORY_MUSIC"
argument_list|)
operator|<<
name|getExternalStoragePublicDirectory
argument_list|(
literal|"DIRECTORY_PODCASTS"
argument_list|)
operator|<<
name|getExternalFilesDir
argument_list|(
literal|"DIRECTORY_PODCASTS"
argument_list|)
operator|<<
name|getExternalStoragePublicDirectory
argument_list|(
literal|"DIRECTORY_NOTIFICATIONS"
argument_list|)
operator|<<
name|getExternalFilesDir
argument_list|(
literal|"DIRECTORY_NOTIFICATIONS"
argument_list|)
operator|<<
name|getExternalStoragePublicDirectory
argument_list|(
literal|"DIRECTORY_ALARMS"
argument_list|)
operator|<<
name|getExternalFilesDir
argument_list|(
literal|"DIRECTORY_ALARMS"
argument_list|)
return|;
block|}
if|if
condition|(
name|type
operator|==
name|MoviesLocation
condition|)
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|writableLocation
argument_list|(
name|type
argument_list|)
operator|<<
name|getExternalFilesDir
argument_list|(
literal|"DIRECTORY_MOVIES"
argument_list|)
return|;
block|}
if|if
condition|(
name|type
operator|==
name|PicturesLocation
condition|)
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|writableLocation
argument_list|(
name|type
argument_list|)
operator|<<
name|getExternalFilesDir
argument_list|(
literal|"DIRECTORY_PICTURES"
argument_list|)
return|;
block|}
if|if
condition|(
name|type
operator|==
name|DocumentsLocation
condition|)
block|{
if|if
condition|(
name|QtAndroidPrivate
operator|::
name|androidSdkVersion
argument_list|()
operator|>
literal|18
condition|)
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|writableLocation
argument_list|(
name|type
argument_list|)
operator|<<
name|getExternalFilesDir
argument_list|(
literal|"DIRECTORY_DOCUMENTS"
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|writableLocation
argument_list|(
name|type
argument_list|)
operator|<<
name|getExternalFilesDir
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/Documents"
argument_list|)
return|;
block|}
block|}
if|if
condition|(
name|type
operator|==
name|DownloadLocation
condition|)
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|writableLocation
argument_list|(
name|type
argument_list|)
operator|<<
name|getExternalFilesDir
argument_list|(
literal|"DIRECTORY_DOWNLOADS"
argument_list|)
return|;
block|}
if|if
condition|(
name|type
operator|==
name|AppDataLocation
operator|||
name|type
operator|==
name|AppLocalDataLocation
condition|)
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|writableLocation
argument_list|(
name|type
argument_list|)
operator|<<
name|getExternalFilesDir
argument_list|()
return|;
block|}
if|if
condition|(
name|type
operator|==
name|CacheLocation
condition|)
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|writableLocation
argument_list|(
name|type
argument_list|)
operator|<<
name|getExternalCacheDir
argument_list|()
return|;
block|}
if|if
condition|(
name|type
operator|==
name|FontsLocation
condition|)
block|{
name|QString
modifier|&
name|fontLocation
init|=
operator|(
operator|*
name|androidDirCache
operator|)
index|[
name|QStringLiteral
argument_list|(
literal|"FONT_LOCATION"
argument_list|)
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|fontLocation
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QStringList
argument_list|(
name|fontLocation
argument_list|)
return|;
specifier|const
name|QByteArray
name|ba
init|=
name|qgetenv
argument_list|(
literal|"QT_ANDROID_FONT_LOCATION"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ba
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QStringList
argument_list|(
operator|(
name|fontLocation
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|ba
argument_list|)
argument_list|)
operator|)
argument_list|)
return|;
return|return
name|QStringList
argument_list|(
operator|(
name|fontLocation
operator|=
name|QLatin1String
argument_list|(
literal|"/system/fonts"
argument_list|)
operator|)
argument_list|)
return|;
block|}
return|return
name|QStringList
argument_list|(
name|writableLocation
argument_list|(
name|type
argument_list|)
argument_list|)
return|;
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
comment|// QT_NO_STANDARDPATHS
end_comment
end_unit
