begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfilesystemwatcher_polling_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qtimer.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QPollingFileSystemWatcherEngine
name|QPollingFileSystemWatcherEngine
operator|::
name|QPollingFileSystemWatcherEngine
parameter_list|()
member_init_list|:
name|timer
argument_list|(
name|this
argument_list|)
block|{
name|connect
argument_list|(
operator|&
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|addPaths
name|QStringList
name|QPollingFileSystemWatcherEngine
operator|::
name|addPaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|,
name|QStringList
modifier|*
name|files
parameter_list|,
name|QStringList
modifier|*
name|directories
parameter_list|)
block|{
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
name|QString
name|path
init|=
name|it
operator|.
name|next
argument_list|()
decl_stmt|;
name|QFileInfo
name|fi
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fi
operator|.
name|exists
argument_list|()
condition|)
continue|continue;
if|if
condition|(
name|fi
operator|.
name|isDir
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|directories
operator|->
name|contains
argument_list|(
name|path
argument_list|)
condition|)
name|directories
operator|->
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|fi
operator|=
name|QFileInfo
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
expr_stmt|;
name|this
operator|->
name|directories
operator|.
name|insert
argument_list|(
name|path
argument_list|,
name|fi
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|files
operator|->
name|contains
argument_list|(
name|path
argument_list|)
condition|)
name|files
operator|->
name|append
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|this
operator|->
name|files
operator|.
name|insert
argument_list|(
name|path
argument_list|,
name|fi
argument_list|)
expr_stmt|;
block|}
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|(
operator|!
name|this
operator|->
name|files
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|this
operator|->
name|directories
operator|.
name|isEmpty
argument_list|()
operator|)
operator|&&
operator|!
name|timer
operator|.
name|isActive
argument_list|()
condition|)
block|{
name|timer
operator|.
name|start
argument_list|(
name|PollingInterval
argument_list|)
expr_stmt|;
block|}
return|return
name|p
return|;
block|}
end_function
begin_function
DECL|function|removePaths
name|QStringList
name|QPollingFileSystemWatcherEngine
operator|::
name|removePaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|,
name|QStringList
modifier|*
name|files
parameter_list|,
name|QStringList
modifier|*
name|directories
parameter_list|)
block|{
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
name|QString
name|path
init|=
name|it
operator|.
name|next
argument_list|()
decl_stmt|;
if|if
condition|(
name|this
operator|->
name|directories
operator|.
name|remove
argument_list|(
name|path
argument_list|)
condition|)
block|{
name|directories
operator|->
name|removeAll
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|this
operator|->
name|files
operator|.
name|remove
argument_list|(
name|path
argument_list|)
condition|)
block|{
name|files
operator|->
name|removeAll
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|this
operator|->
name|files
operator|.
name|isEmpty
argument_list|()
operator|&&
name|this
operator|->
name|directories
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|timer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
return|return
name|p
return|;
block|}
end_function
begin_function
DECL|function|timeout
name|void
name|QPollingFileSystemWatcherEngine
operator|::
name|timeout
parameter_list|()
block|{
name|QMutableHashIterator
argument_list|<
name|QString
argument_list|,
name|FileInfo
argument_list|>
name|fit
argument_list|(
name|files
argument_list|)
decl_stmt|;
while|while
condition|(
name|fit
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|FileInfo
argument_list|>
operator|::
name|iterator
name|x
init|=
name|fit
operator|.
name|next
argument_list|()
decl_stmt|;
name|QString
name|path
init|=
name|x
operator|.
name|key
argument_list|()
decl_stmt|;
name|QFileInfo
name|fi
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fi
operator|.
name|exists
argument_list|()
condition|)
block|{
name|fit
operator|.
name|remove
argument_list|()
expr_stmt|;
emit|emit
name|fileChanged
argument_list|(
name|path
argument_list|,
literal|true
argument_list|)
emit|;
block|}
elseif|else
if|if
condition|(
name|x
operator|.
name|value
argument_list|()
operator|!=
name|fi
condition|)
block|{
name|x
operator|.
name|value
argument_list|()
operator|=
name|fi
expr_stmt|;
emit|emit
name|fileChanged
argument_list|(
name|path
argument_list|,
literal|false
argument_list|)
emit|;
block|}
block|}
name|QMutableHashIterator
argument_list|<
name|QString
argument_list|,
name|FileInfo
argument_list|>
name|dit
argument_list|(
name|directories
argument_list|)
decl_stmt|;
while|while
condition|(
name|dit
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|FileInfo
argument_list|>
operator|::
name|iterator
name|x
init|=
name|dit
operator|.
name|next
argument_list|()
decl_stmt|;
name|QString
name|path
init|=
name|x
operator|.
name|key
argument_list|()
decl_stmt|;
name|QFileInfo
name|fi
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|path
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|fi
operator|=
name|QFileInfo
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|fi
operator|.
name|exists
argument_list|()
condition|)
block|{
name|dit
operator|.
name|remove
argument_list|()
expr_stmt|;
emit|emit
name|directoryChanged
argument_list|(
name|path
argument_list|,
literal|true
argument_list|)
emit|;
block|}
elseif|else
if|if
condition|(
name|x
operator|.
name|value
argument_list|()
operator|!=
name|fi
condition|)
block|{
name|fi
operator|.
name|refresh
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|fi
operator|.
name|exists
argument_list|()
condition|)
block|{
name|dit
operator|.
name|remove
argument_list|()
expr_stmt|;
emit|emit
name|directoryChanged
argument_list|(
name|path
argument_list|,
literal|true
argument_list|)
emit|;
block|}
else|else
block|{
name|x
operator|.
name|value
argument_list|()
operator|=
name|fi
expr_stmt|;
emit|emit
name|directoryChanged
argument_list|(
name|path
argument_list|,
literal|false
argument_list|)
emit|;
block|}
block|}
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
