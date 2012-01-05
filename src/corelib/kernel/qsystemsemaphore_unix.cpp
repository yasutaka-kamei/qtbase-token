begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsystemsemaphore.h"
end_include
begin_include
include|#
directive|include
file|"qsystemsemaphore_p.h"
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
file|<qcoreapplication.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
end_ifndef
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<sys/sem.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_comment
comment|// OpenBSD 4.2 doesn't define EIDRM, see BUGS section:
end_comment
begin_comment
comment|// http://www.openbsd.org/cgi-bin/man.cgi?query=semop&manpath=OpenBSD+4.2
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_OPENBSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EIDRM
argument_list|)
end_if
begin_define
DECL|macro|EIDRM
define|#
directive|define
name|EIDRM
value|EINVAL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QSystemSemaphorePrivate
name|QSystemSemaphorePrivate
operator|::
name|QSystemSemaphorePrivate
parameter_list|()
member_init_list|:
name|semaphore
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|createdFile
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|createdSemaphore
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|unix_key
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|error
argument_list|(
name|QSystemSemaphore
operator|::
name|NoError
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|setErrorString
name|void
name|QSystemSemaphorePrivate
operator|::
name|setErrorString
parameter_list|(
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
comment|// EINVAL is handled in functions so they can give better error strings
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|EPERM
case|:
case|case
name|EACCES
case|:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: permission denied"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|PermissionDenied
expr_stmt|;
break|break;
case|case
name|EEXIST
case|:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: already exists"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|AlreadyExists
expr_stmt|;
break|break;
case|case
name|ENOENT
case|:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: does not exist"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|NotFound
expr_stmt|;
break|break;
case|case
name|ERANGE
case|:
case|case
name|ENOSPC
case|:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: out of resources"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|OutOfResources
expr_stmt|;
break|break;
default|default:
name|errorString
operator|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QSystemSemaphore"
argument_list|,
literal|"%1: unknown error %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
operator|.
name|arg
argument_list|(
name|errno
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|UnknownError
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|errorString
operator|<<
literal|"key"
operator|<<
name|key
operator|<<
literal|"errno"
operator|<<
name|errno
operator|<<
name|EINVAL
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_comment
comment|/*!     \internal      Setup unix_key  */
end_comment
begin_function
DECL|function|handle
name|key_t
name|QSystemSemaphorePrivate
operator|::
name|handle
parameter_list|(
name|QSystemSemaphore
operator|::
name|AccessMode
name|mode
parameter_list|)
block|{
if|if
condition|(
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|errorString
operator|=
name|QCoreApplication
operator|::
name|tr
argument_list|(
literal|"%1: key is empty"
argument_list|,
literal|"QSystemSemaphore"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::handle:"
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|KeyError
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|// ftok requires that an actual file exists somewhere
if|if
condition|(
operator|-
literal|1
operator|!=
name|unix_key
condition|)
return|return
name|unix_key
return|;
comment|// Create the file needed for ftok
name|int
name|built
init|=
name|QSharedMemoryPrivate
operator|::
name|createUnixKeyFile
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|built
condition|)
block|{
name|errorString
operator|=
name|QCoreApplication
operator|::
name|tr
argument_list|(
literal|"%1: unable to make key"
argument_list|,
literal|"QSystemSemaphore"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::handle:"
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|KeyError
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|createdFile
operator|=
operator|(
literal|1
operator|==
name|built
operator|)
expr_stmt|;
comment|// Get the unix key for the created file
name|unix_key
operator|=
name|ftok
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
literal|'Q'
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|unix_key
condition|)
block|{
name|errorString
operator|=
name|QCoreApplication
operator|::
name|tr
argument_list|(
literal|"%1: ftok failed"
argument_list|,
literal|"QSystemSemaphore"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::handle:"
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSystemSemaphore
operator|::
name|KeyError
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|// Get semaphore
name|semaphore
operator|=
name|semget
argument_list|(
name|unix_key
argument_list|,
literal|1
argument_list|,
literal|0666
operator||
name|IPC_CREAT
operator||
name|IPC_EXCL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|semaphore
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|EEXIST
condition|)
name|semaphore
operator|=
name|semget
argument_list|(
name|unix_key
argument_list|,
literal|1
argument_list|,
literal|0666
operator||
name|IPC_CREAT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|semaphore
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::handle"
argument_list|)
argument_list|)
expr_stmt|;
name|cleanHandle
argument_list|()
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
else|else
block|{
name|createdSemaphore
operator|=
literal|true
expr_stmt|;
comment|// Force cleanup of file, it is possible that it can be left over from a crash
name|createdFile
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|mode
operator|==
name|QSystemSemaphore
operator|::
name|Create
condition|)
block|{
name|createdSemaphore
operator|=
literal|true
expr_stmt|;
name|createdFile
operator|=
literal|true
expr_stmt|;
block|}
comment|// Created semaphore so initialize its value.
if|if
condition|(
name|createdSemaphore
operator|&&
name|initialValue
operator|>=
literal|0
condition|)
block|{
name|qt_semun
name|init_op
decl_stmt|;
name|init_op
operator|.
name|val
operator|=
name|initialValue
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|semctl
argument_list|(
name|semaphore
argument_list|,
literal|0
argument_list|,
name|SETVAL
argument_list|,
name|init_op
argument_list|)
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::handle"
argument_list|)
argument_list|)
expr_stmt|;
name|cleanHandle
argument_list|()
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
return|return
name|unix_key
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      Cleanup the unix_key  */
end_comment
begin_function
DECL|function|cleanHandle
name|void
name|QSystemSemaphorePrivate
operator|::
name|cleanHandle
parameter_list|()
block|{
name|unix_key
operator|=
operator|-
literal|1
expr_stmt|;
comment|// remove the file if we made it
if|if
condition|(
name|createdFile
condition|)
block|{
name|QFile
operator|::
name|remove
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|createdFile
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|createdSemaphore
condition|)
block|{
if|if
condition|(
operator|-
literal|1
operator|!=
name|semaphore
condition|)
block|{
if|if
condition|(
operator|-
literal|1
operator|==
name|semctl
argument_list|(
name|semaphore
argument_list|,
literal|0
argument_list|,
name|IPC_RMID
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::cleanHandle"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::cleanHandle semctl failed."
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|semaphore
operator|=
operator|-
literal|1
expr_stmt|;
block|}
name|createdSemaphore
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_function
DECL|function|modifySemaphore
name|bool
name|QSystemSemaphorePrivate
operator|::
name|modifySemaphore
parameter_list|(
name|int
name|count
parameter_list|)
block|{
if|if
condition|(
operator|-
literal|1
operator|==
name|handle
argument_list|()
condition|)
return|return
literal|false
return|;
name|struct
name|sembuf
name|operation
decl_stmt|;
name|operation
operator|.
name|sem_num
operator|=
literal|0
expr_stmt|;
name|operation
operator|.
name|sem_op
operator|=
name|count
expr_stmt|;
name|operation
operator|.
name|sem_flg
operator|=
name|SEM_UNDO
expr_stmt|;
specifier|register
name|int
name|res
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|res
argument_list|,
name|semop
argument_list|(
name|semaphore
argument_list|,
operator|&
name|operation
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|-
literal|1
operator|==
name|res
condition|)
block|{
comment|// If the semaphore was removed be nice and create it and then modifySemaphore again
if|if
condition|(
name|errno
operator|==
name|EINVAL
operator|||
name|errno
operator|==
name|EIDRM
condition|)
block|{
name|semaphore
operator|=
operator|-
literal|1
expr_stmt|;
name|cleanHandle
argument_list|()
expr_stmt|;
name|handle
argument_list|()
expr_stmt|;
return|return
name|modifySemaphore
argument_list|(
name|count
argument_list|)
return|;
block|}
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modifySemaphore"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QSYSTEMSEMAPHORE_DEBUG
name|qDebug
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"QSystemSemaphore::modify failed"
argument_list|)
operator|<<
name|count
operator|<<
name|semctl
argument_list|(
name|semaphore
argument_list|,
literal|0
argument_list|,
name|GETVAL
argument_list|)
operator|<<
name|errno
operator|<<
name|EIDRM
operator|<<
name|EINVAL
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
return|return
literal|true
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
comment|// QT_NO_SYSTEMSEMAPHORE
end_comment
end_unit
