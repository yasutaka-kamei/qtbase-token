begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsharedmemory.h"
end_include
begin_include
include|#
directive|include
file|"qsharedmemory_p.h"
end_include
begin_include
include|#
directive|include
file|"qsystemsemaphore.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SHAREDMEMORY
end_ifndef
begin_constructor
DECL|function|QSharedMemoryPrivate
name|QSharedMemoryPrivate
operator|::
name|QSharedMemoryPrivate
parameter_list|()
member_init_list|:
name|QObjectPrivate
argument_list|()
member_init_list|,
name|memory
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|size
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|error
argument_list|(
name|QSharedMemory
operator|::
name|NoError
argument_list|)
member_init_list|,
name|systemSemaphore
argument_list|(
name|QString
argument_list|()
argument_list|)
member_init_list|,
name|lockedByMe
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|hand
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|setErrorString
name|void
name|QSharedMemoryPrivate
operator|::
name|setErrorString
parameter_list|(
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
name|BOOL
name|windowsError
init|=
name|GetLastError
argument_list|()
decl_stmt|;
if|if
condition|(
name|windowsError
operator|==
literal|0
condition|)
return|return;
switch|switch
condition|(
name|windowsError
condition|)
block|{
case|case
name|ERROR_ALREADY_EXISTS
case|:
name|error
operator|=
name|QSharedMemory
operator|::
name|AlreadyExists
expr_stmt|;
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: already exists"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|ERROR_FILE_NOT_FOUND
case|:
ifdef|#
directive|ifdef
name|Q_OS_WINCE
comment|// This happens on CE only if no file is present as CreateFileMappingW
comment|// bails out with this error code
case|case
name|ERROR_INVALID_PARAMETER
case|:
endif|#
directive|endif
name|error
operator|=
name|QSharedMemory
operator|::
name|NotFound
expr_stmt|;
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: doesn't exist"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|ERROR_COMMITMENT_LIMIT
case|:
name|error
operator|=
name|QSharedMemory
operator|::
name|InvalidSize
expr_stmt|;
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: invalid size"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|ERROR_NO_SYSTEM_RESOURCES
case|:
case|case
name|ERROR_NOT_ENOUGH_MEMORY
case|:
name|error
operator|=
name|QSharedMemory
operator|::
name|OutOfResources
expr_stmt|;
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: out of resources"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|ERROR_ACCESS_DENIED
case|:
name|error
operator|=
name|QSharedMemory
operator|::
name|PermissionDenied
expr_stmt|;
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: permission denied"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
break|break;
default|default:
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
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
name|windowsError
argument_list|)
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|UnknownError
expr_stmt|;
if|#
directive|if
name|defined
name|QSHAREDMEMORY_DEBUG
name|qDebug
argument_list|()
operator|<<
name|errorString
operator|<<
literal|"key"
operator|<<
name|key
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|handle
name|HANDLE
name|QSharedMemoryPrivate
operator|::
name|handle
parameter_list|()
block|{
if|if
condition|(
operator|!
name|hand
condition|)
block|{
name|QString
name|function
init|=
name|QLatin1String
argument_list|(
literal|"QSharedMemory::handle"
argument_list|)
decl_stmt|;
if|if
condition|(
name|nativeKey
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|error
operator|=
name|QSharedMemory
operator|::
name|KeyError
expr_stmt|;
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: unable to make key"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|hand
operator|=
name|OpenFileMapping
argument_list|(
name|FILE_MAP_ALL_ACCESS
argument_list|,
literal|false
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|nativeKey
operator|.
name|utf16
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// This works for opening a mapping too, but always opens it with read/write access in
comment|// attach as it seems.
name|hand
operator|=
name|CreateFileMapping
argument_list|(
name|INVALID_HANDLE_VALUE
argument_list|,
literal|0
argument_list|,
name|PAGE_READWRITE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|nativeKey
operator|.
name|utf16
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|hand
condition|)
block|{
name|setErrorString
argument_list|(
name|function
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
return|return
name|hand
return|;
block|}
end_function
begin_function
DECL|function|cleanHandle
name|bool
name|QSharedMemoryPrivate
operator|::
name|cleanHandle
parameter_list|()
block|{
if|if
condition|(
name|hand
operator|!=
literal|0
operator|&&
operator|!
name|CloseHandle
argument_list|(
name|hand
argument_list|)
condition|)
block|{
name|hand
operator|=
literal|0
expr_stmt|;
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::cleanHandle"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|hand
operator|=
literal|0
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|create
name|bool
name|QSharedMemoryPrivate
operator|::
name|create
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|QString
name|function
init|=
name|QLatin1String
argument_list|(
literal|"QSharedMemory::create"
argument_list|)
decl_stmt|;
if|if
condition|(
name|nativeKey
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|error
operator|=
name|QSharedMemory
operator|::
name|KeyError
expr_stmt|;
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: key error"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Create the file mapping.
name|hand
operator|=
name|CreateFileMapping
argument_list|(
name|INVALID_HANDLE_VALUE
argument_list|,
literal|0
argument_list|,
name|PAGE_READWRITE
argument_list|,
literal|0
argument_list|,
name|size
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|nativeKey
operator|.
name|utf16
argument_list|()
argument_list|)
expr_stmt|;
name|setErrorString
argument_list|(
name|function
argument_list|)
expr_stmt|;
comment|// hand is valid when it already exists unlike unix so explicitly check
if|if
condition|(
name|error
operator|==
name|QSharedMemory
operator|::
name|AlreadyExists
operator|||
operator|!
name|hand
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|attach
name|bool
name|QSharedMemoryPrivate
operator|::
name|attach
parameter_list|(
name|QSharedMemory
operator|::
name|AccessMode
name|mode
parameter_list|)
block|{
comment|// Grab a pointer to the memory block
name|int
name|permissions
init|=
operator|(
name|mode
operator|==
name|QSharedMemory
operator|::
name|ReadOnly
condition|?
name|FILE_MAP_READ
else|:
name|FILE_MAP_ALL_ACCESS
operator|)
decl_stmt|;
name|memory
operator|=
operator|(
name|void
operator|*
operator|)
name|MapViewOfFile
argument_list|(
name|handle
argument_list|()
argument_list|,
name|permissions
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|memory
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::attach"
argument_list|)
argument_list|)
expr_stmt|;
name|cleanHandle
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Grab the size of the memory we have been given (a multiple of 4K on windows)
name|MEMORY_BASIC_INFORMATION
name|info
decl_stmt|;
if|if
condition|(
operator|!
name|VirtualQuery
argument_list|(
name|memory
argument_list|,
operator|&
name|info
argument_list|,
sizeof|sizeof
argument_list|(
name|info
argument_list|)
argument_list|)
condition|)
block|{
comment|// Windows doesn't set an error code on this one,
comment|// it should only be a kernel memory error.
name|error
operator|=
name|QSharedMemory
operator|::
name|UnknownError
expr_stmt|;
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: size query failed"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::attach: "
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|size
operator|=
name|info
operator|.
name|RegionSize
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|detach
name|bool
name|QSharedMemoryPrivate
operator|::
name|detach
parameter_list|()
block|{
comment|// umap memory
if|if
condition|(
operator|!
name|UnmapViewOfFile
argument_list|(
name|memory
argument_list|)
condition|)
block|{
name|setErrorString
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSharedMemory::detach"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|memory
operator|=
literal|0
expr_stmt|;
name|size
operator|=
literal|0
expr_stmt|;
comment|// close handle
return|return
name|cleanHandle
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_SHAREDMEMORY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
