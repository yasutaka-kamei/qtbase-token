begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILESYSTEMWATCHER_POLLING_P_H
end_ifndef
begin_define
DECL|macro|QFILESYSTEMWATCHER_POLLING_P_H
define|#
directive|define
name|QFILESYSTEMWATCHER_POLLING_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|<QtCore/qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtimer.h>
end_include
begin_include
include|#
directive|include
file|"qfilesystemwatcher_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enumerator|PollingInterval
name|enum
type|{
name|PollingInterval
init|=
literal|1000
end_decl_stmt
begin_decl_stmt
DECL|enumerator|PollingInterval
unit|};
name|class
name|QPollingFileSystemWatcherEngine
range|:
name|public
name|QFileSystemWatcherEngine
block|{
name|Q_OBJECT
name|class
name|FileInfo
block|{
name|uint
name|ownerId
block|;
name|uint
name|groupId
block|;
name|QFile
operator|::
name|Permissions
name|permissions
block|;
name|QDateTime
name|lastModified
block|;
name|QStringList
name|entries
block|;
name|public
operator|:
name|FileInfo
argument_list|(
specifier|const
name|QFileInfo
operator|&
name|fileInfo
argument_list|)
operator|:
name|ownerId
argument_list|(
name|fileInfo
operator|.
name|ownerId
argument_list|()
argument_list|)
block|,
name|groupId
argument_list|(
name|fileInfo
operator|.
name|groupId
argument_list|()
argument_list|)
block|,
name|permissions
argument_list|(
name|fileInfo
operator|.
name|permissions
argument_list|()
argument_list|)
block|,
name|lastModified
argument_list|(
argument|fileInfo.lastModified()
argument_list|)
block|{
if|if
condition|(
name|fileInfo
operator|.
name|isDir
argument_list|()
condition|)
block|{
name|entries
operator|=
name|fileInfo
operator|.
name|absoluteDir
argument_list|()
operator|.
name|entryList
argument_list|(
name|QDir
operator|::
name|AllEntries
argument_list|)
expr_stmt|;
block|}
block|}
name|FileInfo
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QFileInfo
operator|&
name|fileInfo
operator|)
block|{
operator|*
name|this
operator|=
name|FileInfo
argument_list|(
name|fileInfo
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QFileInfo
operator|&
name|fileInfo
operator|)
specifier|const
block|{
if|if
condition|(
name|fileInfo
operator|.
name|isDir
argument_list|()
operator|&&
name|entries
operator|!=
name|fileInfo
operator|.
name|absoluteDir
argument_list|()
operator|.
name|entryList
argument_list|(
name|QDir
operator|::
name|AllEntries
argument_list|)
condition|)
return|return
name|true
return|;
return|return
operator|(
name|ownerId
operator|!=
name|fileInfo
operator|.
name|ownerId
argument_list|()
operator|||
name|groupId
operator|!=
name|fileInfo
operator|.
name|groupId
argument_list|()
operator|||
name|permissions
operator|!=
name|fileInfo
operator|.
name|permissions
argument_list|()
operator|||
name|lastModified
operator|!=
name|fileInfo
operator|.
name|lastModified
argument_list|()
operator|)
return|;
block|}
expr|}
block|;
name|QHash
operator|<
name|QString
block|,
name|FileInfo
operator|>
name|files
block|,
name|directories
block|;
name|public
operator|:
name|QPollingFileSystemWatcherEngine
argument_list|()
block|;
name|QStringList
name|addPaths
argument_list|(
specifier|const
name|QStringList
operator|&
name|paths
argument_list|,
name|QStringList
operator|*
name|files
argument_list|,
name|QStringList
operator|*
name|directories
argument_list|)
block|;
name|QStringList
name|removePaths
argument_list|(
specifier|const
name|QStringList
operator|&
name|paths
argument_list|,
name|QStringList
operator|*
name|files
argument_list|,
name|QStringList
operator|*
name|directories
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|timeout
argument_list|()
block|;
name|private
operator|:
name|QTimer
name|timer
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
comment|// QFILESYSTEMWATCHER_POLLING_P_H
end_comment
end_unit
