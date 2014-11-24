begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Ivan Komissarov<ABBAPOH@gmail.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstorageinfo_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|defaultBufferSize
specifier|static
specifier|const
name|int
name|defaultBufferSize
init|=
name|MAX_PATH
operator|+
literal|1
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|initRootPath
name|void
name|QStorageInfoPrivate
operator|::
name|initRootPath
parameter_list|()
block|{
name|rootPath
operator|=
name|QFileInfo
argument_list|(
name|rootPath
argument_list|)
operator|.
name|canonicalFilePath
argument_list|()
expr_stmt|;
if|if
condition|(
name|rootPath
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QString
name|path
init|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|rootPath
argument_list|)
decl_stmt|;
name|rootPath
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|path
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"\\\\?\\"
argument_list|)
argument_list|)
condition|)
name|path
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|path
operator|.
name|length
argument_list|()
operator|<
literal|2
operator|||
name|path
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|!=
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
condition|)
return|return;
name|path
index|[
literal|0
index|]
operator|=
name|path
index|[
literal|0
index|]
operator|.
name|toUpper
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|path
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|unicode
argument_list|()
operator|>=
literal|'A'
operator|&&
name|path
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|unicode
argument_list|()
operator|<=
literal|'Z'
operator|)
condition|)
return|return;
if|if
condition|(
operator|!
name|path
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
condition|)
name|path
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
expr_stmt|;
comment|// ### test if disk mounted to folder on other disk
name|wchar_t
name|buffer
index|[
name|defaultBufferSize
index|]
decl_stmt|;
if|if
condition|(
operator|::
name|GetVolumePathName
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|path
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|buffer
argument_list|,
name|defaultBufferSize
argument_list|)
condition|)
name|rootPath
operator|=
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|buffer
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getDevice
specifier|static
specifier|inline
name|QByteArray
name|getDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|rootPath
parameter_list|)
block|{
specifier|const
name|QString
name|path
init|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|rootPath
argument_list|)
decl_stmt|;
specifier|const
name|UINT
name|type
init|=
operator|::
name|GetDriveType
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|path
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|DRIVE_REMOTE
condition|)
block|{
name|QVarLengthArray
argument_list|<
name|char
argument_list|,
literal|256
argument_list|>
name|buffer
argument_list|(
literal|256
argument_list|)
decl_stmt|;
name|DWORD
name|bufferLength
init|=
name|buffer
operator|.
name|size
argument_list|()
decl_stmt|;
name|DWORD
name|result
decl_stmt|;
name|UNIVERSAL_NAME_INFO
modifier|*
name|remoteNameInfo
decl_stmt|;
do|do
block|{
name|buffer
operator|.
name|resize
argument_list|(
name|bufferLength
argument_list|)
expr_stmt|;
name|remoteNameInfo
operator|=
cast|reinterpret_cast
argument_list|<
name|UNIVERSAL_NAME_INFO
operator|*
argument_list|>
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|=
operator|::
name|WNetGetUniversalName
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|path
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|UNIVERSAL_NAME_INFO_LEVEL
argument_list|,
name|remoteNameInfo
argument_list|,
operator|&
name|bufferLength
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|result
operator|==
name|ERROR_MORE_DATA
condition|)
do|;
if|if
condition|(
name|result
operator|==
name|NO_ERROR
condition|)
return|return
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|remoteNameInfo
operator|->
name|lpUniversalName
argument_list|)
operator|.
name|toUtf8
argument_list|()
return|;
return|return
name|QByteArray
argument_list|()
return|;
block|}
name|wchar_t
name|deviceBuffer
index|[
literal|51
index|]
decl_stmt|;
if|if
condition|(
operator|::
name|GetVolumeNameForVolumeMountPoint
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|path
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|deviceBuffer
argument_list|,
sizeof|sizeof
argument_list|(
name|deviceBuffer
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
argument_list|)
condition|)
block|{
return|return
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|deviceBuffer
argument_list|)
operator|.
name|toLatin1
argument_list|()
return|;
block|}
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|doStat
name|void
name|QStorageInfoPrivate
operator|::
name|doStat
parameter_list|()
block|{
name|initRootPath
argument_list|()
expr_stmt|;
if|if
condition|(
name|rootPath
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|retrieveVolumeInfo
argument_list|()
expr_stmt|;
name|device
operator|=
name|getDevice
argument_list|(
name|rootPath
argument_list|)
expr_stmt|;
name|retrieveDiskFreeSpace
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|retrieveVolumeInfo
name|void
name|QStorageInfoPrivate
operator|::
name|retrieveVolumeInfo
parameter_list|()
block|{
specifier|const
name|UINT
name|oldmode
init|=
operator|::
name|SetErrorMode
argument_list|(
name|SEM_FAILCRITICALERRORS
operator||
name|SEM_NOOPENFILEERRORBOX
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|path
init|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|rootPath
argument_list|)
decl_stmt|;
name|wchar_t
name|nameBuffer
index|[
name|defaultBufferSize
index|]
decl_stmt|;
name|wchar_t
name|fileSystemTypeBuffer
index|[
name|defaultBufferSize
index|]
decl_stmt|;
name|DWORD
name|fileSystemFlags
init|=
literal|0
decl_stmt|;
specifier|const
name|bool
name|result
init|=
operator|::
name|GetVolumeInformation
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|path
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|nameBuffer
argument_list|,
name|defaultBufferSize
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
operator|&
name|fileSystemFlags
argument_list|,
name|fileSystemTypeBuffer
argument_list|,
name|defaultBufferSize
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
block|{
name|ready
operator|=
literal|false
expr_stmt|;
name|valid
operator|=
operator|::
name|GetLastError
argument_list|()
operator|==
name|ERROR_NOT_READY
expr_stmt|;
block|}
else|else
block|{
name|ready
operator|=
literal|true
expr_stmt|;
name|valid
operator|=
literal|true
expr_stmt|;
name|fileSystemType
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|fileSystemTypeBuffer
argument_list|)
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
name|name
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|nameBuffer
argument_list|)
expr_stmt|;
name|readOnly
operator|=
operator|(
name|fileSystemFlags
operator|&
name|FILE_READ_ONLY_VOLUME
operator|)
operator|!=
literal|0
expr_stmt|;
block|}
operator|::
name|SetErrorMode
argument_list|(
name|oldmode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|retrieveDiskFreeSpace
name|void
name|QStorageInfoPrivate
operator|::
name|retrieveDiskFreeSpace
parameter_list|()
block|{
specifier|const
name|UINT
name|oldmode
init|=
operator|::
name|SetErrorMode
argument_list|(
name|SEM_FAILCRITICALERRORS
operator||
name|SEM_NOOPENFILEERRORBOX
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|path
init|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|rootPath
argument_list|)
decl_stmt|;
operator|::
name|GetDiskFreeSpaceEx
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|path
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|PULARGE_INTEGER
argument_list|(
operator|&
name|bytesAvailable
argument_list|)
argument_list|,
name|PULARGE_INTEGER
argument_list|(
operator|&
name|bytesTotal
argument_list|)
argument_list|,
name|PULARGE_INTEGER
argument_list|(
operator|&
name|bytesFree
argument_list|)
argument_list|)
expr_stmt|;
operator|::
name|SetErrorMode
argument_list|(
name|oldmode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mountedVolumes
name|QList
argument_list|<
name|QStorageInfo
argument_list|>
name|QStorageInfoPrivate
operator|::
name|mountedVolumes
parameter_list|()
block|{
name|QList
argument_list|<
name|QStorageInfo
argument_list|>
name|volumes
decl_stmt|;
name|QString
name|driveName
init|=
name|QStringLiteral
argument_list|(
literal|"A:/"
argument_list|)
decl_stmt|;
specifier|const
name|UINT
name|oldmode
init|=
operator|::
name|SetErrorMode
argument_list|(
name|SEM_FAILCRITICALERRORS
operator||
name|SEM_NOOPENFILEERRORBOX
argument_list|)
decl_stmt|;
name|quint32
name|driveBits
init|=
name|quint32
argument_list|(
operator|::
name|GetLogicalDrives
argument_list|()
argument_list|)
operator|&
literal|0x3ffffff
decl_stmt|;
operator|::
name|SetErrorMode
argument_list|(
name|oldmode
argument_list|)
expr_stmt|;
while|while
condition|(
name|driveBits
condition|)
block|{
if|if
condition|(
name|driveBits
operator|&
literal|1
condition|)
block|{
name|QStorageInfo
name|drive
argument_list|(
name|driveName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|drive
operator|.
name|rootPath
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// drive exists, but not mounted
name|volumes
operator|.
name|append
argument_list|(
name|drive
argument_list|)
expr_stmt|;
block|}
name|driveName
index|[
literal|0
index|]
operator|=
name|driveName
index|[
literal|0
index|]
operator|.
name|unicode
argument_list|()
operator|+
literal|1
expr_stmt|;
name|driveBits
operator|=
name|driveBits
operator|>>
literal|1
expr_stmt|;
block|}
return|return
name|volumes
return|;
block|}
end_function
begin_function
DECL|function|root
name|QStorageInfo
name|QStorageInfoPrivate
operator|::
name|root
parameter_list|()
block|{
return|return
name|QStorageInfo
argument_list|(
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|QFile
operator|::
name|decodeName
argument_list|(
name|qgetenv
argument_list|(
literal|"SystemDrive"
argument_list|)
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
