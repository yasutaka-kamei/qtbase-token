begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfilesystemwatcher.h"
end_include
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
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_INOTIFY
argument_list|)
operator|)
end_if
begin_define
DECL|macro|USE_INOTIFY
define|#
directive|define
name|USE_INOTIFY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qfilesystemwatcher_polling_p.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qfilesystemwatcher_win_p.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|USE_INOTIFY
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"qfilesystemwatcher_inotify_p.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_FREEBSD
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_NETBSD
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_OPENBSD
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_IOS
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"qfilesystemwatcher_kqueue_p.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_OSX
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"qfilesystemwatcher_fsevents_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|createNativeEngine
name|QFileSystemWatcherEngine
modifier|*
name|QFileSystemWatcherPrivate
operator|::
name|createNativeEngine
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
return|return
operator|new
name|QWindowsFileSystemWatcherEngine
argument_list|(
name|parent
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|USE_INOTIFY
argument_list|)
comment|// there is a chance that inotify may fail on Linux pre-2.6.13 (August
comment|// 2005), so we can't just new inotify directly.
return|return
name|QInotifyFileSystemWatcherEngine
operator|::
name|create
argument_list|(
name|parent
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_FREEBSD
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_NETBSD
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_OPENBSD
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_IOS
argument_list|)
return|return
name|QKqueueFileSystemWatcherEngine
operator|::
name|create
argument_list|(
name|parent
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_OSX
argument_list|)
return|return
name|QFseventsFileSystemWatcherEngine
operator|::
name|create
argument_list|(
name|parent
argument_list|)
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|parent
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_constructor
DECL|function|QFileSystemWatcherPrivate
name|QFileSystemWatcherPrivate
operator|::
name|QFileSystemWatcherPrivate
parameter_list|()
member_init_list|:
name|native
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|poller
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|init
name|void
name|QFileSystemWatcherPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
name|native
operator|=
name|createNativeEngine
argument_list|(
name|q
argument_list|)
expr_stmt|;
if|if
condition|(
name|native
condition|)
block|{
name|QObject
operator|::
name|connect
argument_list|(
name|native
argument_list|,
name|SIGNAL
argument_list|(
name|fileChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_fileChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|native
argument_list|,
name|SIGNAL
argument_list|(
name|directoryChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_directoryChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|initPollerEngine
name|void
name|QFileSystemWatcherPrivate
operator|::
name|initPollerEngine
parameter_list|()
block|{
if|if
condition|(
name|poller
condition|)
return|return;
name|Q_Q
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
name|poller
operator|=
operator|new
name|QPollingFileSystemWatcherEngine
argument_list|(
name|q
argument_list|)
expr_stmt|;
comment|// that was a mouthful
name|QObject
operator|::
name|connect
argument_list|(
name|poller
argument_list|,
name|SIGNAL
argument_list|(
name|fileChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_fileChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|poller
argument_list|,
name|SIGNAL
argument_list|(
name|directoryChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_directoryChanged
argument_list|(
name|QString
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_fileChanged
name|void
name|QFileSystemWatcherPrivate
operator|::
name|_q_fileChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|bool
name|removed
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|files
operator|.
name|contains
argument_list|(
name|path
argument_list|)
condition|)
block|{
comment|// the path was removed after a change was detected, but before we delivered the signal
return|return;
block|}
if|if
condition|(
name|removed
condition|)
name|files
operator|.
name|removeAll
argument_list|(
name|path
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|fileChanged
argument_list|(
name|path
argument_list|,
name|QFileSystemWatcher
operator|::
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|_q_directoryChanged
name|void
name|QFileSystemWatcherPrivate
operator|::
name|_q_directoryChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|bool
name|removed
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|directories
operator|.
name|contains
argument_list|(
name|path
argument_list|)
condition|)
block|{
comment|// perhaps the path was removed after a change was detected, but before we delivered the signal
return|return;
block|}
if|if
condition|(
name|removed
condition|)
name|directories
operator|.
name|removeAll
argument_list|(
name|path
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|directoryChanged
argument_list|(
name|path
argument_list|,
name|QFileSystemWatcher
operator|::
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|/*!     \class QFileSystemWatcher     \inmodule QtCore     \brief The QFileSystemWatcher class provides an interface for monitoring files and directories for modifications.     \ingroup io     \since 4.2     \reentrant      QFileSystemWatcher monitors the file system for changes to files     and directories by watching a list of specified paths.      Call addPath() to watch a particular file or directory. Multiple     paths can be added using the addPaths() function. Existing paths can     be removed by using the removePath() and removePaths() functions.      QFileSystemWatcher examines each path added to it. Files that have     been added to the QFileSystemWatcher can be accessed using the     files() function, and directories using the directories() function.      The fileChanged() signal is emitted when a file has been modified,     renamed or removed from disk. Similarly, the directoryChanged()     signal is emitted when a directory or its contents is modified or     removed.  Note that QFileSystemWatcher stops monitoring files once     they have been renamed or removed from disk, and directories once     they have been removed from disk.      \note On systems running a Linux kernel without inotify support,     file systems that contain watched paths cannot be unmounted.      \note Windows CE does not support directory monitoring by     default as this depends on the file system driver installed.      \note The act of monitoring files and directories for     modifications consumes system resources. This implies there is a     limit to the number of files and directories your process can     monitor simultaneously. On all BSD variants, for     example, an open file descriptor is required for each monitored     file. Some system limits the number of open file descriptors to 256     by default. This means that addPath() and addPaths() will fail if     your process tries to add more than 256 files or directories to     the file system monitor. Also note that your process may have     other file descriptors open in addition to the ones for files     being monitored, and these other open descriptors also count in     the total. OS X uses a different backend and does not     suffer from this issue.       \sa QFile, QDir */
end_comment
begin_comment
comment|/*!     Constructs a new file system watcher object with the given \a parent. */
end_comment
begin_constructor
DECL|function|QFileSystemWatcher
name|QFileSystemWatcher
operator|::
name|QFileSystemWatcher
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QFileSystemWatcherPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a new file system watcher object with the given \a parent     which monitors the specified \a paths list. */
end_comment
begin_constructor
DECL|function|QFileSystemWatcher
name|QFileSystemWatcher
operator|::
name|QFileSystemWatcher
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QFileSystemWatcherPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|init
argument_list|()
expr_stmt|;
name|addPaths
argument_list|(
name|paths
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the file system watcher. */
end_comment
begin_destructor
DECL|function|~QFileSystemWatcher
name|QFileSystemWatcher
operator|::
name|~
name|QFileSystemWatcher
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Adds \a path to the file system watcher if \a path exists. The     path is not added if it does not exist, or if it is already being     monitored by the file system watcher.      If \a path specifies a directory, the directoryChanged() signal     will be emitted when \a path is modified or removed from disk;     otherwise the fileChanged() signal is emitted when \a path is     modified, renamed or removed.      If the watch was successful, true is returned.      Reasons for a watch failure are generally system-dependent, but     may include the resource not existing, access failures, or the     total watch count limit, if the platform has one.      \note There may be a system dependent limit to the number of     files and directories that can be monitored simultaneously.     If this limit is been reached, \a path will not be monitored,     and false is returned.      \sa addPaths(), removePath() */
end_comment
begin_function
DECL|function|addPath
name|bool
name|QFileSystemWatcher
operator|::
name|addPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFileSystemWatcher::addPath: path is empty"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|QStringList
name|paths
init|=
name|addPaths
argument_list|(
name|QStringList
argument_list|(
name|path
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|paths
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Adds each path in \a paths to the file system watcher. Paths are     not added if they not exist, or if they are already being     monitored by the file system watcher.      If a path specifies a directory, the directoryChanged() signal     will be emitted when the path is modified or removed from disk;     otherwise the fileChanged() signal is emitted when the path is     modified, renamed, or removed.      The return value is a list of paths that could not be watched.      Reasons for a watch failure are generally system-dependent, but     may include the resource not existing, access failures, or the     total watch count limit, if the platform has one.      \note There may be a system dependent limit to the number of     files and directories that can be monitored simultaneously.     If this limit has been reached, the excess \a paths will not     be monitored, and they will be added to the returned QStringList.      \sa addPath(), removePaths() */
end_comment
begin_function
DECL|function|addPaths
name|QStringList
name|QFileSystemWatcher
operator|::
name|addPaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
name|QStringList
name|p
init|=
name|paths
decl_stmt|;
name|QMutableListIterator
argument_list|<
name|QString
argument_list|>
name|it
argument_list|(
name|p
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
block|{
specifier|const
name|QString
modifier|&
name|path
init|=
name|it
operator|.
name|next
argument_list|()
decl_stmt|;
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|p
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFileSystemWatcher::addPaths: list is empty"
argument_list|)
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
name|QFileSystemWatcherEngine
modifier|*
name|engine
init|=
literal|0
decl_stmt|;
specifier|const
name|QString
name|on
init|=
name|objectName
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|on
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"_qt_autotest_force_engine_"
argument_list|)
argument_list|)
condition|)
block|{
comment|// Normal runtime case - search intelligently for best engine
if|if
condition|(
name|d
operator|->
name|native
condition|)
block|{
name|engine
operator|=
name|d
operator|->
name|native
expr_stmt|;
block|}
else|else
block|{
name|d_func
argument_list|()
operator|->
name|initPollerEngine
argument_list|()
expr_stmt|;
name|engine
operator|=
name|d
operator|->
name|poller
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// Autotest override case - use the explicitly selected engine only
specifier|const
name|QStringRef
name|forceName
init|=
name|on
operator|.
name|midRef
argument_list|(
literal|26
argument_list|)
decl_stmt|;
if|if
condition|(
name|forceName
operator|==
name|QLatin1String
argument_list|(
literal|"poller"
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"QFileSystemWatcher: skipping native engine, using only polling engine"
expr_stmt|;
name|d_func
argument_list|()
operator|->
name|initPollerEngine
argument_list|()
expr_stmt|;
name|engine
operator|=
name|d
operator|->
name|poller
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|forceName
operator|==
name|QLatin1String
argument_list|(
literal|"native"
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"QFileSystemWatcher: skipping polling engine, using only native engine"
expr_stmt|;
name|engine
operator|=
name|d
operator|->
name|native
expr_stmt|;
block|}
block|}
if|if
condition|(
name|engine
condition|)
name|p
operator|=
name|engine
operator|->
name|addPaths
argument_list|(
name|p
argument_list|,
operator|&
name|d
operator|->
name|files
argument_list|,
operator|&
name|d
operator|->
name|directories
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function
begin_comment
comment|/*!     Removes the specified \a path from the file system watcher.      If the watch is successfully removed, true is returned.      Reasons for watch removal failing are generally system-dependent,     but may be due to the path having already been deleted, for example.      \sa removePaths(), addPath() */
end_comment
begin_function
DECL|function|removePath
name|bool
name|QFileSystemWatcher
operator|::
name|removePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFileSystemWatcher::removePath: path is empty"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|QStringList
name|paths
init|=
name|removePaths
argument_list|(
name|QStringList
argument_list|(
name|path
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|paths
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Removes the specified \a paths from the file system watcher.      The return value is a list of paths which were not able to be     unwatched successfully.      Reasons for watch removal failing are generally system-dependent,     but may be due to the path having already been deleted, for example.      \sa removePath(), addPaths() */
end_comment
begin_function
DECL|function|removePaths
name|QStringList
name|QFileSystemWatcher
operator|::
name|removePaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
name|QStringList
name|p
init|=
name|paths
decl_stmt|;
name|QMutableListIterator
argument_list|<
name|QString
argument_list|>
name|it
argument_list|(
name|p
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
block|{
specifier|const
name|QString
modifier|&
name|path
init|=
name|it
operator|.
name|next
argument_list|()
decl_stmt|;
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|p
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QFileSystemWatcher::removePaths: list is empty"
argument_list|)
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
if|if
condition|(
name|d
operator|->
name|native
condition|)
name|p
operator|=
name|d
operator|->
name|native
operator|->
name|removePaths
argument_list|(
name|p
argument_list|,
operator|&
name|d
operator|->
name|files
argument_list|,
operator|&
name|d
operator|->
name|directories
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|poller
condition|)
name|p
operator|=
name|d
operator|->
name|poller
operator|->
name|removePaths
argument_list|(
name|p
argument_list|,
operator|&
name|d
operator|->
name|files
argument_list|,
operator|&
name|d
operator|->
name|directories
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QFileSystemWatcher::fileChanged(const QString&path)      This signal is emitted when the file at the specified \a path is     modified, renamed or removed from disk.      \sa directoryChanged() */
end_comment
begin_comment
comment|/*!     \fn void QFileSystemWatcher::directoryChanged(const QString&path)      This signal is emitted when the directory at a specified \a path     is modified (e.g., when a file is added or deleted) or removed     from disk. Note that if there are several changes during a short     period of time, some of the changes might not emit this signal.     However, the last change in the sequence of changes will always     generate this signal.      \sa fileChanged() */
end_comment
begin_comment
comment|/*!     \fn QStringList QFileSystemWatcher::directories() const      Returns a list of paths to directories that are being watched.      \sa files() */
end_comment
begin_comment
comment|/*!     \fn QStringList QFileSystemWatcher::files() const      Returns a list of paths to files that are being watched.      \sa directories() */
end_comment
begin_function
DECL|function|directories
name|QStringList
name|QFileSystemWatcher
operator|::
name|directories
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|directories
return|;
block|}
end_function
begin_function
DECL|function|files
name|QStringList
name|QFileSystemWatcher
operator|::
name|files
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFileSystemWatcher
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|files
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qfilesystemwatcher.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FILESYSTEMWATCHER
end_comment
end_unit
