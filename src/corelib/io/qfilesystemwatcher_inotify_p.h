begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILESYSTEMWATCHER_INOTIFY_P_H
end_ifndef
begin_define
DECL|macro|QFILESYSTEMWATCHER_INOTIFY_P_H
define|#
directive|define
name|QFILESYSTEMWATCHER_INOTIFY_P_H
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
file|"qfilesystemwatcher_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsocketnotifier.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QInotifyFileSystemWatcherEngine
range|:
name|public
name|QFileSystemWatcherEngine
block|{
name|Q_OBJECT
name|public
operator|:
operator|~
name|QInotifyFileSystemWatcherEngine
argument_list|()
block|;
specifier|static
name|QInotifyFileSystemWatcherEngine
operator|*
name|create
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|QStringList
name|addPaths
argument_list|(
argument|const QStringList&paths
argument_list|,
argument|QStringList *files
argument_list|,
argument|QStringList *directories
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|removePaths
argument_list|(
argument|const QStringList&paths
argument_list|,
argument|QStringList *files
argument_list|,
argument|QStringList *directories
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|readFromInotify
argument_list|()
block|;
name|private
operator|:
name|QString
name|getPathFromID
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QInotifyFileSystemWatcherEngine
argument_list|(
argument|int fd
argument_list|,
argument|QObject *parent
argument_list|)
block|;
name|int
name|inotifyFd
block|;
name|QHash
operator|<
name|QString
block|,
name|int
operator|>
name|pathToID
block|;
name|QMultiHash
operator|<
name|int
block|,
name|QString
operator|>
name|idToPath
block|;
name|QSocketNotifier
name|notifier
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
comment|// QT_NO_FILESYSTEMWATCHER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILESYSTEMWATCHER_INOTIFY_P_H
end_comment
end_unit
