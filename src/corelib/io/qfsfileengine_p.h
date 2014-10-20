begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFSFILEENGINE_P_H
end_ifndef
begin_define
DECL|macro|QFSFILEENGINE_P_H
define|#
directive|define
name|QFSFILEENGINE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/private/qabstractfileengine_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfilesystementry_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qfilesystemmetadata_p.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FSFILEENGINE
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE_STD
argument_list|)
operator|&&
name|_WIN32_WCE
operator|<
literal|0x600
DECL|macro|Q_USE_DEPRECATED_MAP_API
define|#
directive|define
name|Q_USE_DEPRECATED_MAP_API
value|1
endif|#
directive|endif
DECL|variable|QFSFileEnginePrivate
name|class
name|QFSFileEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QFSFileEngine
range|:
name|public
name|QAbstractFileEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFSFileEngine
argument_list|)
name|public
operator|:
name|QFSFileEngine
argument_list|()
block|;
name|explicit
name|QFSFileEngine
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
operator|~
name|QFSFileEngine
argument_list|()
block|;
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode openMode
argument_list|)
block|;
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|FILE *fh
argument_list|)
block|;
name|bool
name|close
argument_list|()
block|;
name|bool
name|flush
argument_list|()
block|;
name|bool
name|syncToDisk
argument_list|()
block|;
name|qint64
name|size
argument_list|()
specifier|const
block|;
name|qint64
name|pos
argument_list|()
specifier|const
block|;
name|bool
name|seek
argument_list|(
name|qint64
argument_list|)
block|;
name|bool
name|isSequential
argument_list|()
specifier|const
block|;
name|bool
name|remove
argument_list|()
block|;
name|bool
name|copy
argument_list|(
specifier|const
name|QString
operator|&
name|newName
argument_list|)
block|;
name|bool
name|rename
argument_list|(
specifier|const
name|QString
operator|&
name|newName
argument_list|)
block|;
name|bool
name|renameOverwrite
argument_list|(
specifier|const
name|QString
operator|&
name|newName
argument_list|)
block|;
name|bool
name|link
argument_list|(
specifier|const
name|QString
operator|&
name|newName
argument_list|)
block|;
name|bool
name|mkdir
argument_list|(
argument|const QString&dirName
argument_list|,
argument|bool createParentDirectories
argument_list|)
specifier|const
block|;
name|bool
name|rmdir
argument_list|(
argument|const QString&dirName
argument_list|,
argument|bool recurseParentDirectories
argument_list|)
specifier|const
block|;
name|bool
name|setSize
argument_list|(
argument|qint64 size
argument_list|)
block|;
name|bool
name|caseSensitive
argument_list|()
specifier|const
block|;
name|bool
name|isRelativePath
argument_list|()
specifier|const
block|;
name|QStringList
name|entryList
argument_list|(
argument|QDir::Filters filters
argument_list|,
argument|const QStringList&filterNames
argument_list|)
specifier|const
block|;
name|FileFlags
name|fileFlags
argument_list|(
argument|FileFlags type
argument_list|)
specifier|const
block|;
name|bool
name|setPermissions
argument_list|(
argument|uint perms
argument_list|)
block|;
name|QString
name|fileName
argument_list|(
argument|FileName file
argument_list|)
specifier|const
block|;
name|uint
name|ownerId
argument_list|(
argument|FileOwner
argument_list|)
specifier|const
block|;
name|QString
name|owner
argument_list|(
argument|FileOwner
argument_list|)
specifier|const
block|;
name|QDateTime
name|fileTime
argument_list|(
argument|FileTime time
argument_list|)
specifier|const
block|;
name|void
name|setFileName
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|int
name|handle
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMITERATOR
name|Iterator
operator|*
name|beginEntryList
argument_list|(
argument|QDir::Filters filters
argument_list|,
argument|const QStringList&filterNames
argument_list|)
block|;
name|Iterator
operator|*
name|endEntryList
argument_list|()
block|;
endif|#
directive|endif
name|qint64
name|read
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|readLine
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|write
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|bool
name|extension
argument_list|(
argument|Extension extension
argument_list|,
argument|const ExtensionOption *option =
literal|0
argument_list|,
argument|ExtensionReturn *output =
literal|0
argument_list|)
block|;
name|bool
name|supportsExtension
argument_list|(
argument|Extension extension
argument_list|)
specifier|const
block|;
comment|//FS only!!
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|int fd
argument_list|)
block|;
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|int fd
argument_list|,
argument|QFile::FileHandleFlags handleFlags
argument_list|)
block|;
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|FILE *fh
argument_list|,
argument|QFile::FileHandleFlags handleFlags
argument_list|)
block|;
specifier|static
name|bool
name|setCurrentPath
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
specifier|static
name|QString
name|currentPath
argument_list|(
specifier|const
name|QString
operator|&
name|path
operator|=
name|QString
argument_list|()
argument_list|)
block|;
specifier|static
name|QString
name|homePath
argument_list|()
block|;
specifier|static
name|QString
name|rootPath
argument_list|()
block|;
specifier|static
name|QString
name|tempPath
argument_list|()
block|;
specifier|static
name|QFileInfoList
name|drives
argument_list|()
block|;
name|protected
operator|:
name|QFSFileEngine
argument_list|(
name|QFSFileEnginePrivate
operator|&
name|dd
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QFSFileEnginePrivate
range|:
name|public
name|QAbstractFileEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFSFileEngine
argument_list|)
name|public
operator|:
ifdef|#
directive|ifdef
name|Q_OS_WIN
specifier|static
name|QString
name|longFileName
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
endif|#
directive|endif
name|QFileSystemEntry
name|fileEntry
block|;
name|QIODevice
operator|::
name|OpenMode
name|openMode
block|;
name|bool
name|nativeOpen
argument_list|(
argument|QIODevice::OpenMode openMode
argument_list|)
block|;
name|bool
name|openFh
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|FILE *fh
argument_list|)
block|;
name|bool
name|openFd
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|,
argument|int fd
argument_list|)
block|;
name|bool
name|nativeClose
argument_list|()
block|;
name|bool
name|closeFdFh
argument_list|()
block|;
name|bool
name|nativeFlush
argument_list|()
block|;
name|bool
name|nativeSyncToDisk
argument_list|()
block|;
name|bool
name|flushFh
argument_list|()
block|;
name|qint64
name|nativeSize
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|qint64
name|sizeFdFh
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|qint64
name|nativePos
argument_list|()
specifier|const
block|;
name|qint64
name|posFdFh
argument_list|()
specifier|const
block|;
name|bool
name|nativeSeek
argument_list|(
name|qint64
argument_list|)
block|;
name|bool
name|seekFdFh
argument_list|(
name|qint64
argument_list|)
block|;
name|qint64
name|nativeRead
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|readFdFh
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|nativeReadLine
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|readLineFdFh
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|nativeWrite
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|qint64
name|writeFdFh
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|int
name|nativeHandle
argument_list|()
specifier|const
block|;
name|bool
name|nativeIsSequential
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|bool
name|isSequentialFdFh
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|uchar
operator|*
name|map
argument_list|(
argument|qint64 offset
argument_list|,
argument|qint64 size
argument_list|,
argument|QFile::MemoryMapFlags flags
argument_list|)
block|;
name|bool
name|unmap
argument_list|(
name|uchar
operator|*
name|ptr
argument_list|)
block|;
name|void
name|unmapAll
argument_list|()
block|;
name|mutable
name|QFileSystemMetaData
name|metaData
block|;
name|FILE
operator|*
name|fh
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|HANDLE
name|fileHandle
block|;
name|HANDLE
name|mapHandle
block|;
name|QHash
operator|<
name|uchar
operator|*
block|,
name|DWORD
comment|/* offset % AllocationGranularity */
operator|>
name|maps
block|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|mutable
name|int
name|cachedFd
block|;
endif|#
directive|endif
name|mutable
name|DWORD
name|fileAttrib
block|;
else|#
directive|else
name|QHash
operator|<
name|uchar
operator|*
block|,
name|QPair
operator|<
name|int
comment|/*offset % PageSize*/
block|,
name|size_t
comment|/*length + offset % PageSize*/
operator|>
expr|>
name|maps
block|;
endif|#
directive|endif
name|int
name|fd
block|;      enum
name|LastIOCommand
block|{
name|IOFlushCommand
block|,
name|IOReadCommand
block|,
name|IOWriteCommand
block|}
block|;
name|LastIOCommand
name|lastIOCommand
block|;
name|bool
name|lastFlushFailed
block|;
name|bool
name|closeFileHandle
block|;
name|mutable
name|uint
name|is_sequential
operator|:
literal|2
block|;
name|mutable
name|uint
name|could_stat
operator|:
literal|1
block|;
name|mutable
name|uint
name|tried_stat
operator|:
literal|1
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|mutable
name|uint
name|need_lstat
operator|:
literal|1
block|;
name|mutable
name|uint
name|is_link
operator|:
literal|1
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|bool
name|doStat
argument_list|(
argument|QFileSystemMetaData::MetaDataFlags flags
argument_list|)
specifier|const
block|;
else|#
directive|else
name|bool
name|doStat
argument_list|(
argument|QFileSystemMetaData::MetaDataFlags flags = QFileSystemMetaData::PosixStatFlags
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|bool
name|isSymlink
argument_list|()
specifier|const
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
name|int
name|sysOpen
argument_list|(
argument|const QString&
argument_list|,
argument|int flags
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
name|QFSFileEnginePrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|QAbstractFileEngine
operator|::
name|FileFlags
name|getPermissions
argument_list|(
argument|QAbstractFileEngine::FileFlags type
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FSFILEENGINE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFSFILEENGINE_P_H
end_comment
end_unit
