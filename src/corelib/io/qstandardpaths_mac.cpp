begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DESKTOPSERVICES
end_ifndef
begin_include
include|#
directive|include
file|"qstandardpaths.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<ApplicationServices/ApplicationServices.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*     Translates a QStandardPaths::StandardLocation into the mac equivalent. */
DECL|function|translateLocation
name|OSType
name|translateLocation
parameter_list|(
name|QStandardPaths
operator|::
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
name|ConfigLocation
case|:
return|return
name|kPreferencesFolderType
return|;
case|case
name|QStandardPaths
operator|::
name|DesktopLocation
case|:
return|return
name|kDesktopFolderType
return|;
case|case
name|QStandardPaths
operator|::
name|DownloadLocation
case|:
comment|// needs NSSearchPathForDirectoriesInDomains with NSDownloadsDirectory
comment|// which needs an objective-C *.mm file...
case|case
name|QStandardPaths
operator|::
name|DocumentsLocation
case|:
return|return
name|kDocumentsFolderType
return|;
case|case
name|QStandardPaths
operator|::
name|FontsLocation
case|:
comment|// There are at least two different font directories on the mac: /Library/Fonts and ~/Library/Fonts.
comment|// To select a specific one we have to specify a different first parameter when calling FSFindFolder.
return|return
name|kFontsFolderType
return|;
case|case
name|QStandardPaths
operator|::
name|ApplicationsLocation
case|:
return|return
name|kApplicationsFolderType
return|;
case|case
name|QStandardPaths
operator|::
name|MusicLocation
case|:
return|return
name|kMusicDocumentsFolderType
return|;
case|case
name|QStandardPaths
operator|::
name|MoviesLocation
case|:
return|return
name|kMovieDocumentsFolderType
return|;
case|case
name|QStandardPaths
operator|::
name|PicturesLocation
case|:
return|return
name|kPictureDocumentsFolderType
return|;
case|case
name|QStandardPaths
operator|::
name|TempLocation
case|:
return|return
name|kTemporaryFolderType
return|;
case|case
name|QStandardPaths
operator|::
name|GenericDataLocation
case|:
case|case
name|QStandardPaths
operator|::
name|RuntimeLocation
case|:
case|case
name|QStandardPaths
operator|::
name|DataLocation
case|:
return|return
name|kApplicationSupportFolderType
return|;
case|case
name|QStandardPaths
operator|::
name|GenericCacheLocation
case|:
case|case
name|QStandardPaths
operator|::
name|CacheLocation
case|:
return|return
name|kCachedDataFolderType
return|;
default|default:
return|return
name|kDesktopFolderType
return|;
block|}
block|}
end_function
begin_comment
comment|/*     Constructs a full unicode path from a FSRef. */
end_comment
begin_function
DECL|function|getFullPath
specifier|static
name|QString
name|getFullPath
parameter_list|(
specifier|const
name|FSRef
modifier|&
name|ref
parameter_list|)
block|{
name|QByteArray
name|ba
argument_list|(
literal|2048
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|FSRefMakePath
argument_list|(
operator|&
name|ref
argument_list|,
cast|reinterpret_cast
argument_list|<
name|UInt8
operator|*
argument_list|>
argument_list|(
name|ba
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|ba
operator|.
name|size
argument_list|()
argument_list|)
operator|==
name|noErr
condition|)
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|ba
argument_list|)
operator|.
name|normalized
argument_list|(
name|QString
operator|::
name|NormalizationForm_C
argument_list|)
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|macLocation
specifier|static
name|QString
name|macLocation
parameter_list|(
name|QStandardPaths
operator|::
name|StandardLocation
name|type
parameter_list|,
name|short
name|domain
parameter_list|)
block|{
comment|// http://developer.apple.com/documentation/Carbon/Reference/Folder_Manager/Reference/reference.html
name|FSRef
name|ref
decl_stmt|;
name|OSErr
name|err
init|=
name|FSFindFolder
argument_list|(
name|domain
argument_list|,
name|translateLocation
argument_list|(
name|type
argument_list|)
argument_list|,
literal|false
argument_list|,
operator|&
name|ref
argument_list|)
decl_stmt|;
if|if
condition|(
name|err
condition|)
return|return
name|QString
argument_list|()
return|;
name|QString
name|path
init|=
name|getFullPath
argument_list|(
name|ref
argument_list|)
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|QStandardPaths
operator|::
name|DataLocation
operator|||
name|type
operator|==
name|QStandardPaths
operator|::
name|CacheLocation
condition|)
block|{
if|if
condition|(
operator|!
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|path
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QCoreApplication
operator|::
name|organizationName
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|path
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
expr_stmt|;
block|}
return|return
name|path
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
name|HomeLocation
case|:
return|return
name|QDir
operator|::
name|homePath
argument_list|()
return|;
case|case
name|TempLocation
case|:
return|return
name|QDir
operator|::
name|tempPath
argument_list|()
return|;
case|case
name|GenericDataLocation
case|:
case|case
name|DataLocation
case|:
case|case
name|GenericCacheLocation
case|:
case|case
name|CacheLocation
case|:
case|case
name|RuntimeLocation
case|:
return|return
name|macLocation
argument_list|(
name|type
argument_list|,
name|kUserDomain
argument_list|)
return|;
default|default:
return|return
name|macLocation
argument_list|(
name|type
argument_list|,
name|kOnAppropriateDisk
argument_list|)
return|;
block|}
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
name|QStringList
name|dirs
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|GenericDataLocation
operator|||
name|type
operator|==
name|DataLocation
operator|||
name|type
operator|==
name|GenericCacheLocation
operator|||
name|type
operator|==
name|CacheLocation
condition|)
block|{
specifier|const
name|QString
name|path
init|=
name|macLocation
argument_list|(
name|type
argument_list|,
name|kOnAppropriateDisk
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
name|dirs
operator|.
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QString
name|localDir
init|=
name|writableLocation
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|dirs
operator|.
name|prepend
argument_list|(
name|localDir
argument_list|)
expr_stmt|;
return|return
name|dirs
return|;
block|}
end_function
begin_function
DECL|function|displayName
name|QString
name|QStandardPaths
operator|::
name|displayName
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
if|if
condition|(
name|QStandardPaths
operator|::
name|HomeLocation
operator|==
name|type
condition|)
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QStandardPaths"
argument_list|,
literal|"Home"
argument_list|)
return|;
name|FSRef
name|ref
decl_stmt|;
name|OSErr
name|err
init|=
name|FSFindFolder
argument_list|(
name|kOnAppropriateDisk
argument_list|,
name|translateLocation
argument_list|(
name|type
argument_list|)
argument_list|,
literal|false
argument_list|,
operator|&
name|ref
argument_list|)
decl_stmt|;
if|if
condition|(
name|err
condition|)
return|return
name|QString
argument_list|()
return|;
name|QCFString
name|displayName
decl_stmt|;
name|err
operator|=
name|LSCopyDisplayNameForRef
argument_list|(
operator|&
name|ref
argument_list|,
operator|&
name|displayName
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
cast|static_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|displayName
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
comment|// QT_NO_DESKTOPSERVICES
end_comment
end_unit
