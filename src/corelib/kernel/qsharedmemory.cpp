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
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qcryptographichash.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|QT_NO_SHAREDMEMORY
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_NO_SYSTEMSEMAPHORE
argument_list|)
operator|)
comment|/*!     \internal      Generate a string from the key which can be any unicode string into     the subset that the win/unix kernel allows.      On Unix this will be a file name   */
name|QString
DECL|function|makePlatformSafeKey
name|QSharedMemoryPrivate
operator|::
name|makePlatformSafeKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|)
block|{
if|if
condition|(
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
name|QString
name|result
init|=
name|prefix
decl_stmt|;
name|QString
name|part1
init|=
name|key
decl_stmt|;
name|part1
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
name|QLatin1String
argument_list|(
literal|"[^A-Za-z]"
argument_list|)
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|.
name|append
argument_list|(
name|part1
argument_list|)
expr_stmt|;
name|QByteArray
name|hex
init|=
name|QCryptographicHash
operator|::
name|hash
argument_list|(
name|key
operator|.
name|toUtf8
argument_list|()
argument_list|,
name|QCryptographicHash
operator|::
name|Sha1
argument_list|)
operator|.
name|toHex
argument_list|()
decl_stmt|;
name|result
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
name|hex
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
return|return
name|result
return|;
else|#
directive|else
return|return
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|result
return|;
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SHAREDMEMORY&& QT_NO_SHAREDMEMORY
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SHAREDMEMORY
end_ifndef
begin_comment
comment|/*!   \class QSharedMemory   \since 4.4    \brief The QSharedMemory class provides access to a shared memory segment.    QSharedMemory provides access to a shared memory segment by multiple   threads and processes. It also provides a way for a single thread or   process to lock the memory for exclusive access.    When using this class, be aware of the following platform   differences:    \list    \li Windows: QSharedMemory does not "own" the shared memory segment.   When all threads or processes that have an instance of QSharedMemory   attached to a particular shared memory segment have either destroyed   their instance of QSharedMemory or exited, the Windows kernel   releases the shared memory segment automatically.    \li Unix: QSharedMemory "owns" the shared memory segment. When the   last thread or process that has an instance of QSharedMemory   attached to a particular shared memory segment detaches from the   segment by destroying its instance of QSharedMemory, the Unix kernel   release the shared memory segment. But if that last thread or   process crashes without running the QSharedMemory destructor, the   shared memory segment survives the crash.    \li HP-UX: Only one attach to a shared memory segment is allowed per   process. This means that QSharedMemory should not be used across   multiple threads in the same process in HP-UX.    \endlist    Remember to lock the shared memory with lock() before reading from   or writing to the shared memory, and remember to release the lock   with unlock() after you are done.    Unlike QtSharedMemory, QSharedMemory automatically destroys the   shared memory segment when the last instance of QSharedMemory is   detached from the segment, and no references to the segment   remain. Do not mix using QtSharedMemory and QSharedMemory. Port   everything to QSharedMemory.    \warning QSharedMemory changes the key in a Qt-specific way, unless otherwise   specified. Interoperation with non-Qt applications is achieved by first creating   a default shared memory with QSharedMemory() and then setting a native key with   setNativeKey(). When using native keys, shared memory is not protected against   multiple accesses on it (e.g. unable to lock()) and a user-defined mechanism   should be used to achieve a such protection.  */
end_comment
begin_comment
comment|/*!   \overload QSharedMemory()    Constructs a shared memory object with the given \a parent.  The   shared memory object's key is not set by the constructor, so the   shared memory object does not have an underlying shared memory   segment attached. The key must be set with setKey() or setNativeKey()   before create() or attach() can be used.    \sa setKey()  */
end_comment
begin_constructor
DECL|function|QSharedMemory
name|QSharedMemory
operator|::
name|QSharedMemory
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
name|QSharedMemoryPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Constructs a shared memory object with the given \a parent and with   its key set to \a key. Because its key is set, its create() and   attach() functions can be called.    \sa setKey(), create(), attach()  */
end_comment
begin_constructor
DECL|function|QSharedMemory
name|QSharedMemory
operator|::
name|QSharedMemory
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
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
name|QSharedMemoryPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|setKey
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   The destructor clears the key, which forces the shared memory object   to \l {detach()} {detach} from its underlying shared memory   segment. If this shared memory object is the last one connected to   the shared memory segment, the detach() operation destroys the   shared memory segment.    \sa detach() isAttached()  */
end_comment
begin_destructor
DECL|function|~QSharedMemory
name|QSharedMemory
operator|::
name|~
name|QSharedMemory
parameter_list|()
block|{
name|setKey
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!   Sets the platform independent \a key for this shared memory object. If \a key   is the same as the current key, the function returns without doing anything.    You can call key() to retrieve the platform independent key. Internally,   QSharedMemory converts this key into a platform specific key. If you instead   call nativeKey(), you will get the platform specific, converted key.    If the shared memory object is attached to an underlying shared memory   segment, it will \l {detach()} {detach} from it before setting the new key.   This function does not do an attach().    \sa key() nativeKey() isAttached() */
end_comment
begin_function
DECL|function|setKey
name|void
name|QSharedMemory
operator|::
name|setKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSharedMemory
argument_list|)
expr_stmt|;
if|if
condition|(
name|key
operator|==
name|d
operator|->
name|key
operator|&&
name|d
operator|->
name|makePlatformSafeKey
argument_list|(
name|key
argument_list|)
operator|==
name|d
operator|->
name|nativeKey
condition|)
return|return;
if|if
condition|(
name|isAttached
argument_list|()
condition|)
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|cleanHandle
argument_list|()
expr_stmt|;
name|d
operator|->
name|key
operator|=
name|key
expr_stmt|;
name|d
operator|->
name|nativeKey
operator|=
name|d
operator|->
name|makePlatformSafeKey
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \since 4.8    Sets the native, platform specific, \a key for this shared memory object. If   \a key is the same as the current native key, the function returns without   doing anything. If all you want is to assign a key to a segment, you should   call setKey() instead.    You can call nativeKey() to retrieve the native key. If a native key has been   assigned, calling key() will return a null string.    If the shared memory object is attached to an underlying shared memory   segment, it will \l {detach()} {detach} from it before setting the new key.   This function does not do an attach().    The application will not be portable if you set a native key.    \sa nativeKey() key() isAttached() */
end_comment
begin_function
DECL|function|setNativeKey
name|void
name|QSharedMemory
operator|::
name|setNativeKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSharedMemory
argument_list|)
expr_stmt|;
if|if
condition|(
name|key
operator|==
name|d
operator|->
name|nativeKey
operator|&&
name|d
operator|->
name|key
operator|.
name|isNull
argument_list|()
condition|)
return|return;
if|if
condition|(
name|isAttached
argument_list|()
condition|)
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|cleanHandle
argument_list|()
expr_stmt|;
name|d
operator|->
name|key
operator|=
name|QString
argument_list|()
expr_stmt|;
name|d
operator|->
name|nativeKey
operator|=
name|key
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initKey
name|bool
name|QSharedMemoryPrivate
operator|::
name|initKey
parameter_list|()
block|{
if|if
condition|(
operator|!
name|cleanHandle
argument_list|()
condition|)
return|return
literal|false
return|;
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
name|systemSemaphore
operator|.
name|setKey
argument_list|(
name|QString
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|systemSemaphore
operator|.
name|setKey
argument_list|(
name|key
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|systemSemaphore
operator|.
name|error
argument_list|()
operator|!=
name|QSystemSemaphore
operator|::
name|NoError
condition|)
block|{
name|QString
name|function
init|=
name|QLatin1String
argument_list|(
literal|"QSharedMemoryPrivate::initKey"
argument_list|)
decl_stmt|;
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: unable to set key on lock"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|systemSemaphore
operator|.
name|error
argument_list|()
condition|)
block|{
case|case
name|QSystemSemaphore
operator|::
name|PermissionDenied
case|:
name|error
operator|=
name|QSharedMemory
operator|::
name|PermissionDenied
expr_stmt|;
break|break;
case|case
name|QSystemSemaphore
operator|::
name|KeyError
case|:
name|error
operator|=
name|QSharedMemory
operator|::
name|KeyError
expr_stmt|;
break|break;
case|case
name|QSystemSemaphore
operator|::
name|AlreadyExists
case|:
name|error
operator|=
name|QSharedMemory
operator|::
name|AlreadyExists
expr_stmt|;
break|break;
case|case
name|QSystemSemaphore
operator|::
name|NotFound
case|:
name|error
operator|=
name|QSharedMemory
operator|::
name|NotFound
expr_stmt|;
break|break;
case|case
name|QSystemSemaphore
operator|::
name|OutOfResources
case|:
name|error
operator|=
name|QSharedMemory
operator|::
name|OutOfResources
expr_stmt|;
break|break;
case|case
name|QSystemSemaphore
operator|::
name|UnknownError
case|:
default|default:
name|error
operator|=
name|QSharedMemory
operator|::
name|UnknownError
expr_stmt|;
break|break;
block|}
return|return
literal|false
return|;
block|}
endif|#
directive|endif
name|errorString
operator|=
name|QString
argument_list|()
expr_stmt|;
name|error
operator|=
name|QSharedMemory
operator|::
name|NoError
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the key assigned with setKey() to this shared memory, or a null key   if no key has been assigned, or if the segment is using a nativeKey(). The   key is the identifier used by Qt applications to identify the shared memory   segment.    You can find the native, platform specific, key used by the operating system   by calling nativeKey().    \sa setKey() setNativeKey()  */
end_comment
begin_function
DECL|function|key
name|QString
name|QSharedMemory
operator|::
name|key
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSharedMemory
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|key
return|;
block|}
end_function
begin_comment
comment|/*!   \since 4.8    Returns the native, platform specific, key for this shared memory object. The   native key is the identifier used by the operating system to identify the   shared memory segment.    You can use the native key to access shared memory segments that have not   been created by Qt, or to grant shared memory access to non-Qt applications.    \sa setKey() setNativeKey() */
end_comment
begin_function
DECL|function|nativeKey
name|QString
name|QSharedMemory
operator|::
name|nativeKey
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSharedMemory
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|nativeKey
return|;
block|}
end_function
begin_comment
comment|/*!   Creates a shared memory segment of \a size bytes with the key passed to the   constructor, set with setKey() or set with setNativeKey(), then attaches to   the new shared memory segment with the given access \a mode and returns   \tt true. If a shared memory segment identified by the key already exists,   the attach operation is not performed and \tt false is returned. When the   return value is \tt false, call error() to determine which error occurred.    \sa error()  */
end_comment
begin_function
DECL|function|create
name|bool
name|QSharedMemory
operator|::
name|create
parameter_list|(
name|int
name|size
parameter_list|,
name|AccessMode
name|mode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSharedMemory
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|initKey
argument_list|()
condition|)
return|return
literal|false
return|;
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
ifndef|#
directive|ifndef
name|Q_OS_WIN
comment|// Take ownership and force set initialValue because the semaphore
comment|// might have already existed from a previous crash.
name|d
operator|->
name|systemSemaphore
operator|.
name|setKey
argument_list|(
name|d
operator|->
name|key
argument_list|,
literal|1
argument_list|,
name|QSystemSemaphore
operator|::
name|Create
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|QString
name|function
init|=
name|QLatin1String
argument_list|(
literal|"QSharedMemory::create"
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
name|QSharedMemoryLocker
name|lock
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|key
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|d
operator|->
name|tryLocker
argument_list|(
operator|&
name|lock
argument_list|,
name|function
argument_list|)
condition|)
return|return
literal|false
return|;
endif|#
directive|endif
if|if
condition|(
name|size
operator|<=
literal|0
condition|)
block|{
name|d
operator|->
name|error
operator|=
name|QSharedMemory
operator|::
name|InvalidSize
expr_stmt|;
name|d
operator|->
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: create size is less then 0"
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
if|if
condition|(
operator|!
name|d
operator|->
name|create
argument_list|(
name|size
argument_list|)
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|attach
argument_list|(
name|mode
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the size of the attached shared memory segment. If no shared   memory segment is attached, 0 is returned.    \sa create() attach()  */
end_comment
begin_function
DECL|function|size
name|int
name|QSharedMemory
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSharedMemory
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|size
return|;
block|}
end_function
begin_comment
comment|/*!   \enum QSharedMemory::AccessMode    \value ReadOnly The shared memory segment is read-only. Writing to   the shared memory segment is not allowed. An attempt to write to a   shared memory segment created with ReadOnly causes the program to   abort.    \value ReadWrite Reading and writing the shared memory segment are   both allowed. */
end_comment
begin_comment
comment|/*!   Attempts to attach the process to the shared memory segment   identified by the key that was passed to the constructor or to a   call to setKey() or setNativeKey(). The access \a mode is \l {QSharedMemory::}   {ReadWrite} by default. It can also be \l {QSharedMemory::}   {ReadOnly}. Returns true if the attach operation is successful. If   false is returned, call error() to determine which error occurred.   After attaching the shared memory segment, a pointer to the shared   memory can be obtained by calling data().    \sa isAttached(), detach(), create()  */
end_comment
begin_function
DECL|function|attach
name|bool
name|QSharedMemory
operator|::
name|attach
parameter_list|(
name|AccessMode
name|mode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSharedMemory
argument_list|)
expr_stmt|;
if|if
condition|(
name|isAttached
argument_list|()
operator|||
operator|!
name|d
operator|->
name|initKey
argument_list|()
condition|)
return|return
literal|false
return|;
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
name|QSharedMemoryLocker
name|lock
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|key
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|d
operator|->
name|tryLocker
argument_list|(
operator|&
name|lock
argument_list|,
name|QLatin1String
argument_list|(
literal|"QSharedMemory::attach"
argument_list|)
argument_list|)
condition|)
return|return
literal|false
return|;
endif|#
directive|endif
if|if
condition|(
name|isAttached
argument_list|()
operator|||
operator|!
name|d
operator|->
name|handle
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|attach
argument_list|(
name|mode
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns true if this process is attached to the shared memory   segment.    \sa attach(), detach()  */
end_comment
begin_function
DECL|function|isAttached
name|bool
name|QSharedMemory
operator|::
name|isAttached
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSharedMemory
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|!=
name|d
operator|->
name|memory
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!   Detaches the process from the shared memory segment. If this was the   last process attached to the shared memory segment, then the shared   memory segment is released by the system, i.e., the contents are   destroyed. The function returns true if it detaches the shared   memory segment. If it returns false, it usually means the segment   either isn't attached, or it is locked by another process.    \sa attach(), isAttached()  */
end_comment
begin_function
DECL|function|detach
name|bool
name|QSharedMemory
operator|::
name|detach
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSharedMemory
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isAttached
argument_list|()
condition|)
return|return
literal|false
return|;
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
name|QSharedMemoryLocker
name|lock
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|key
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|d
operator|->
name|tryLocker
argument_list|(
operator|&
name|lock
argument_list|,
name|QLatin1String
argument_list|(
literal|"QSharedMemory::detach"
argument_list|)
argument_list|)
condition|)
return|return
literal|false
return|;
endif|#
directive|endif
return|return
name|d
operator|->
name|detach
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Returns a pointer to the contents of the shared memory segment, if   one is attached. Otherwise it returns null. Remember to lock the   shared memory with lock() before reading from or writing to the   shared memory, and remember to release the lock with unlock() after   you are done.    \sa attach()  */
end_comment
begin_function
DECL|function|data
name|void
modifier|*
name|QSharedMemory
operator|::
name|data
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSharedMemory
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|memory
return|;
block|}
end_function
begin_comment
comment|/*!   Returns a const pointer to the contents of the shared memory   segment, if one is attached. Otherwise it returns null. Remember to   lock the shared memory with lock() before reading from or writing to   the shared memory, and remember to release the lock with unlock()   after you are done.    \sa attach() create()  */
end_comment
begin_function
DECL|function|constData
specifier|const
name|void
modifier|*
name|QSharedMemory
operator|::
name|constData
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSharedMemory
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|memory
return|;
block|}
end_function
begin_comment
comment|/*!   \overload data()  */
end_comment
begin_function
DECL|function|data
specifier|const
name|void
modifier|*
name|QSharedMemory
operator|::
name|data
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSharedMemory
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|memory
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
end_ifndef
begin_comment
comment|/*!   This is a semaphore that locks the shared memory segment for access   by this process and returns true. If another process has locked the   segment, this function blocks until the lock is released. Then it   acquires the lock and returns true. If this function returns false,   it means that you have ignored a false return from create() or attach(),   that you have set the key with setNativeKey() or that   QSystemSemaphore::acquire() failed due to an unknown system error.    \sa unlock(), data(), QSystemSemaphore::acquire()  */
end_comment
begin_function
DECL|function|lock
name|bool
name|QSharedMemory
operator|::
name|lock
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSharedMemory
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|lockedByMe
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSharedMemory::lock: already locked"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|d
operator|->
name|systemSemaphore
operator|.
name|acquire
argument_list|()
condition|)
block|{
name|d
operator|->
name|lockedByMe
operator|=
literal|true
expr_stmt|;
return|return
literal|true
return|;
block|}
name|QString
name|function
init|=
name|QLatin1String
argument_list|(
literal|"QSharedMemory::lock"
argument_list|)
decl_stmt|;
name|d
operator|->
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: unable to lock"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|d
operator|->
name|error
operator|=
name|QSharedMemory
operator|::
name|LockError
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!   Releases the lock on the shared memory segment and returns true, if   the lock is currently held by this process. If the segment is not   locked, or if the lock is held by another process, nothing happens   and false is returned.    \sa lock()  */
end_comment
begin_function
DECL|function|unlock
name|bool
name|QSharedMemory
operator|::
name|unlock
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSharedMemory
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|lockedByMe
condition|)
return|return
literal|false
return|;
name|d
operator|->
name|lockedByMe
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|systemSemaphore
operator|.
name|release
argument_list|()
condition|)
return|return
literal|true
return|;
name|QString
name|function
init|=
name|QLatin1String
argument_list|(
literal|"QSharedMemory::unlock"
argument_list|)
decl_stmt|;
name|d
operator|->
name|errorString
operator|=
name|QSharedMemory
operator|::
name|tr
argument_list|(
literal|"%1: unable to unlock"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|d
operator|->
name|error
operator|=
name|QSharedMemory
operator|::
name|LockError
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMSEMAPHORE
end_comment
begin_comment
comment|/*!   \enum QSharedMemory::SharedMemoryError    \value NoError No error occurred.    \value PermissionDenied The operation failed because the caller   didn't have the required permissions.    \value InvalidSize A create operation failed because the requested   size was invalid.    \value KeyError The operation failed because of an invalid key.    \value AlreadyExists A create() operation failed because a shared   memory segment with the specified key already existed.    \value NotFound An attach() failed because a shared memory segment   with the specified key could not be found.    \value LockError The attempt to lock() the shared memory segment   failed because create() or attach() failed and returned false, or   because a system error occurred in QSystemSemaphore::acquire().    \value OutOfResources A create() operation failed because there was   not enough memory available to fill the request.    \value UnknownError Something else happened and it was bad. */
end_comment
begin_comment
comment|/*!   Returns a value indicating whether an error occurred, and, if so,   which error it was.    \sa errorString()  */
end_comment
begin_function
DECL|function|error
name|QSharedMemory
operator|::
name|SharedMemoryError
name|QSharedMemory
operator|::
name|error
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSharedMemory
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|error
return|;
block|}
end_function
begin_comment
comment|/*!   Returns a text description of the last error that occurred. If   error() returns an \l {QSharedMemory::SharedMemoryError} {error   value}, call this function to get a text string that describes the   error.    \sa error()  */
end_comment
begin_function
DECL|function|errorString
name|QString
name|QSharedMemory
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSharedMemory
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|errorString
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SHAREDMEMORY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
