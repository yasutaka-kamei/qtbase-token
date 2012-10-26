begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//#define WINVER 0x0500
end_comment
begin_if
if|#
directive|if
name|_WIN32_WINNT
operator|<
literal|0x0400
end_if
begin_define
DECL|macro|_WIN32_WINNT
define|#
directive|define
name|_WIN32_WINNT
value|0x0400
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qthread.h"
end_include
begin_include
include|#
directive|include
file|"qthread_p.h"
end_include
begin_include
include|#
directive|include
file|"qthreadstorage.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qpointer.h>
end_include
begin_include
include|#
directive|include
file|<private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qeventdispatcher_win_p.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|_MT
end_ifndef
begin_define
DECL|macro|_MT
define|#
directive|define
name|_MT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<process.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"qfunctions_wince.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|void
name|qt_watch_adopted_thread
parameter_list|(
specifier|const
name|HANDLE
name|adoptedThreadHandle
parameter_list|,
name|QThread
modifier|*
name|qthread
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|DWORD
name|WINAPI
name|qt_adopted_thread_watcher_function
parameter_list|(
name|LPVOID
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|qt_current_thread_data_tls_index
specifier|static
name|DWORD
name|qt_current_thread_data_tls_index
init|=
name|TLS_OUT_OF_INDEXES
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qt_create_tls
name|void
name|qt_create_tls
parameter_list|()
block|{
if|if
condition|(
name|qt_current_thread_data_tls_index
operator|!=
name|TLS_OUT_OF_INDEXES
condition|)
return|return;
specifier|static
name|QMutex
name|mutex
decl_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
name|qt_current_thread_data_tls_index
operator|=
name|TlsAlloc
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_free_tls
specifier|static
name|void
name|qt_free_tls
parameter_list|()
block|{
if|if
condition|(
name|qt_current_thread_data_tls_index
operator|!=
name|TLS_OUT_OF_INDEXES
condition|)
block|{
name|TlsFree
argument_list|(
name|qt_current_thread_data_tls_index
argument_list|)
expr_stmt|;
name|qt_current_thread_data_tls_index
operator|=
name|TLS_OUT_OF_INDEXES
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|Q_DESTRUCTOR_FUNCTION
argument_list|(
argument|qt_free_tls
argument_list|)
end_macro
begin_comment
comment|/*     QThreadData */
end_comment
begin_function
DECL|function|current
name|QThreadData
modifier|*
name|QThreadData
operator|::
name|current
parameter_list|()
block|{
name|qt_create_tls
argument_list|()
expr_stmt|;
name|QThreadData
modifier|*
name|threadData
init|=
cast|reinterpret_cast
argument_list|<
name|QThreadData
operator|*
argument_list|>
argument_list|(
name|TlsGetValue
argument_list|(
name|qt_current_thread_data_tls_index
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|threadData
condition|)
block|{
name|threadData
operator|=
operator|new
name|QThreadData
expr_stmt|;
comment|// This needs to be called prior to new AdoptedThread() to
comment|// avoid recursion.
name|TlsSetValue
argument_list|(
name|qt_current_thread_data_tls_index
argument_list|,
name|threadData
argument_list|)
expr_stmt|;
name|QT_TRY
block|{
name|threadData
operator|->
name|thread
operator|=
operator|new
name|QAdoptedThread
argument_list|(
name|threadData
argument_list|)
expr_stmt|;
block|}
name|QT_CATCH
argument_list|(
argument|...
argument_list|)
block|{
name|TlsSetValue
argument_list|(
name|qt_current_thread_data_tls_index
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|threadData
operator|->
name|deref
argument_list|()
expr_stmt|;
name|threadData
operator|=
literal|0
expr_stmt|;
name|QT_RETHROW
expr_stmt|;
block|}
name|threadData
operator|->
name|deref
argument_list|()
expr_stmt|;
name|threadData
operator|->
name|isAdopted
operator|=
literal|true
expr_stmt|;
name|threadData
operator|->
name|threadId
operator|=
cast|reinterpret_cast
argument_list|<
name|Qt
operator|::
name|HANDLE
argument_list|>
argument_list|(
name|GetCurrentThreadId
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QCoreApplicationPrivate
operator|::
name|theMainThread
condition|)
block|{
name|QCoreApplicationPrivate
operator|::
name|theMainThread
operator|=
name|threadData
operator|->
name|thread
expr_stmt|;
block|}
else|else
block|{
name|HANDLE
name|realHandle
init|=
name|INVALID_HANDLE_VALUE
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_WIN32_WCE
argument_list|)
operator|&&
operator|(
name|_WIN32_WCE
operator|>=
literal|0x600
operator|)
operator|)
name|DuplicateHandle
argument_list|(
name|GetCurrentProcess
argument_list|()
argument_list|,
name|GetCurrentThread
argument_list|()
argument_list|,
name|GetCurrentProcess
argument_list|()
argument_list|,
operator|&
name|realHandle
argument_list|,
literal|0
argument_list|,
name|FALSE
argument_list|,
name|DUPLICATE_SAME_ACCESS
argument_list|)
expr_stmt|;
else|#
directive|else
name|realHandle
operator|=
cast|reinterpret_cast
argument_list|<
name|HANDLE
argument_list|>
argument_list|(
name|GetCurrentThreadId
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|qt_watch_adopted_thread
argument_list|(
name|realHandle
argument_list|,
name|threadData
operator|->
name|thread
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|threadData
return|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QAdoptedThread
operator|::
name|init
parameter_list|()
block|{
name|d_func
argument_list|()
operator|->
name|handle
operator|=
name|GetCurrentThread
argument_list|()
expr_stmt|;
name|d_func
argument_list|()
operator|->
name|id
operator|=
name|GetCurrentThreadId
argument_list|()
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|qt_adopted_thread_handles
specifier|static
name|QVector
argument_list|<
name|HANDLE
argument_list|>
name|qt_adopted_thread_handles
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_adopted_qthreads
specifier|static
name|QVector
argument_list|<
name|QThread
modifier|*
argument_list|>
name|qt_adopted_qthreads
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_adopted_thread_watcher_mutex
specifier|static
name|QMutex
name|qt_adopted_thread_watcher_mutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_adopted_thread_watcher_id
specifier|static
name|DWORD
name|qt_adopted_thread_watcher_id
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_adopted_thread_wakeup
specifier|static
name|HANDLE
name|qt_adopted_thread_wakeup
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \internal     Adds an adopted thread to the list of threads that Qt watches to make sure     the thread data is properly cleaned up. This function starts the watcher     thread if necessary. */
end_comment
begin_function
DECL|function|qt_watch_adopted_thread
name|void
name|qt_watch_adopted_thread
parameter_list|(
specifier|const
name|HANDLE
name|adoptedThreadHandle
parameter_list|,
name|QThread
modifier|*
name|qthread
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|qt_adopted_thread_watcher_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|GetCurrentThreadId
argument_list|()
operator|==
name|qt_adopted_thread_watcher_id
condition|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_WIN32_WCE
argument_list|)
operator|&&
operator|(
name|_WIN32_WCE
operator|>=
literal|0x600
operator|)
operator|)
name|CloseHandle
argument_list|(
name|adoptedThreadHandle
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
name|qt_adopted_thread_handles
operator|.
name|append
argument_list|(
name|adoptedThreadHandle
argument_list|)
expr_stmt|;
name|qt_adopted_qthreads
operator|.
name|append
argument_list|(
name|qthread
argument_list|)
expr_stmt|;
comment|// Start watcher thread if it is not already running.
if|if
condition|(
name|qt_adopted_thread_watcher_id
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|qt_adopted_thread_wakeup
operator|==
literal|0
condition|)
block|{
name|qt_adopted_thread_wakeup
operator|=
name|CreateEvent
argument_list|(
literal|0
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qt_adopted_thread_handles
operator|.
name|prepend
argument_list|(
name|qt_adopted_thread_wakeup
argument_list|)
expr_stmt|;
block|}
name|CreateThread
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|qt_adopted_thread_watcher_function
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|qt_adopted_thread_watcher_id
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|SetEvent
argument_list|(
name|qt_adopted_thread_wakeup
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*     This function loops and waits for native adopted threads to finish.     When this happens it derefs the QThreadData for the adopted thread     to make sure it gets cleaned up properly. */
end_comment
begin_function
DECL|function|qt_adopted_thread_watcher_function
name|DWORD
name|WINAPI
name|qt_adopted_thread_watcher_function
parameter_list|(
name|LPVOID
parameter_list|)
block|{
forever|forever
block|{
name|qt_adopted_thread_watcher_mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|qt_adopted_thread_handles
operator|.
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
name|qt_adopted_thread_watcher_id
operator|=
literal|0
expr_stmt|;
name|qt_adopted_thread_watcher_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
break|break;
block|}
name|QVector
argument_list|<
name|HANDLE
argument_list|>
name|handlesCopy
init|=
name|qt_adopted_thread_handles
decl_stmt|;
name|qt_adopted_thread_watcher_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|DWORD
name|ret
init|=
name|WAIT_TIMEOUT
decl_stmt|;
name|int
name|loops
init|=
operator|(
name|handlesCopy
operator|.
name|count
argument_list|()
operator|/
name|MAXIMUM_WAIT_OBJECTS
operator|)
operator|+
literal|1
decl_stmt|,
name|offset
decl_stmt|,
name|count
decl_stmt|;
if|if
condition|(
name|loops
operator|==
literal|1
condition|)
block|{
comment|// no need to loop, no timeout
name|offset
operator|=
literal|0
expr_stmt|;
name|count
operator|=
name|handlesCopy
operator|.
name|count
argument_list|()
expr_stmt|;
name|ret
operator|=
name|WaitForMultipleObjects
argument_list|(
name|handlesCopy
operator|.
name|count
argument_list|()
argument_list|,
name|handlesCopy
operator|.
name|constData
argument_list|()
argument_list|,
literal|false
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|loop
init|=
literal|0
decl_stmt|;
do|do
block|{
name|offset
operator|=
name|loop
operator|*
name|MAXIMUM_WAIT_OBJECTS
expr_stmt|;
name|count
operator|=
name|qMin
argument_list|(
name|handlesCopy
operator|.
name|count
argument_list|()
operator|-
name|offset
argument_list|,
name|MAXIMUM_WAIT_OBJECTS
argument_list|)
expr_stmt|;
name|ret
operator|=
name|WaitForMultipleObjects
argument_list|(
name|count
argument_list|,
name|handlesCopy
operator|.
name|constData
argument_list|()
operator|+
name|offset
argument_list|,
literal|false
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|loop
operator|=
operator|(
name|loop
operator|+
literal|1
operator|)
operator|%
name|loops
expr_stmt|;
block|}
do|while
condition|(
name|ret
operator|==
name|WAIT_TIMEOUT
condition|)
do|;
block|}
if|if
condition|(
name|ret
operator|==
name|WAIT_FAILED
operator|||
name|ret
operator|>=
name|WAIT_OBJECT_0
operator|+
name|uint
argument_list|(
name|count
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QThread internal error while waiting for adopted threads: %d"
argument_list|,
name|int
argument_list|(
name|GetLastError
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
specifier|const
name|int
name|handleIndex
init|=
name|offset
operator|+
name|ret
operator|-
name|WAIT_OBJECT_0
decl_stmt|;
if|if
condition|(
name|handleIndex
operator|==
literal|0
condition|)
block|{
comment|// New handle to watch was added.
continue|continue;
block|}
else|else
block|{
comment|//             printf("(qt) - qt_adopted_thread_watcher_function... called\n");
specifier|const
name|int
name|qthreadIndex
init|=
name|handleIndex
operator|-
literal|1
decl_stmt|;
name|qt_adopted_thread_watcher_mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QThreadData
modifier|*
name|data
init|=
name|QThreadData
operator|::
name|get2
argument_list|(
name|qt_adopted_qthreads
operator|.
name|at
argument_list|(
name|qthreadIndex
argument_list|)
argument_list|)
decl_stmt|;
name|qt_adopted_thread_watcher_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
name|data
operator|->
name|isAdopted
condition|)
block|{
name|QThread
modifier|*
name|thread
init|=
name|data
operator|->
name|thread
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|thread
argument_list|)
expr_stmt|;
name|QThreadPrivate
modifier|*
name|thread_p
init|=
cast|static_cast
argument_list|<
name|QThreadPrivate
operator|*
argument_list|>
argument_list|(
name|QObjectPrivate
operator|::
name|get
argument_list|(
name|thread
argument_list|)
argument_list|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
argument|thread_p
argument_list|)
name|Q_ASSERT
argument_list|(
operator|!
name|thread_p
operator|->
name|finished
argument_list|)
expr_stmt|;
name|thread_p
operator|->
name|finish
argument_list|(
name|thread
argument_list|)
expr_stmt|;
block|}
name|data
operator|->
name|deref
argument_list|()
expr_stmt|;
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|qt_adopted_thread_watcher_mutex
argument_list|)
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_WIN32_WCE
argument_list|)
operator|&&
operator|(
name|_WIN32_WCE
operator|>=
literal|0x600
operator|)
operator|)
name|CloseHandle
argument_list|(
name|qt_adopted_thread_handles
operator|.
name|at
argument_list|(
name|handleIndex
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|qt_adopted_thread_handles
operator|.
name|remove
argument_list|(
name|handleIndex
argument_list|)
expr_stmt|;
name|qt_adopted_qthreads
operator|.
name|remove
argument_list|(
name|qthreadIndex
argument_list|)
expr_stmt|;
block|}
block|}
name|QThreadData
modifier|*
name|threadData
init|=
cast|reinterpret_cast
argument_list|<
name|QThreadData
operator|*
argument_list|>
argument_list|(
name|TlsGetValue
argument_list|(
name|qt_current_thread_data_tls_index
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|threadData
condition|)
name|threadData
operator|->
name|deref
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WIN64
end_ifndef
begin_define
DECL|macro|ULONG_PTR
define|#
directive|define
name|ULONG_PTR
value|DWORD
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|struct|tagTHREADNAME_INFO
typedef|typedef
struct|struct
name|tagTHREADNAME_INFO
block|{
DECL|member|dwType
name|DWORD
name|dwType
decl_stmt|;
comment|// must be 0x1000
DECL|member|szName
name|LPCSTR
name|szName
decl_stmt|;
comment|// pointer to name (in user addr space)
DECL|member|dwThreadID
name|HANDLE
name|dwThreadID
decl_stmt|;
comment|// thread ID (-1=caller thread)
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
comment|// reserved for future use, must be zero
block|}
DECL|typedef|THREADNAME_INFO
name|THREADNAME_INFO
typedef|;
end_typedef
begin_function
DECL|function|qt_set_thread_name
name|void
name|qt_set_thread_name
parameter_list|(
name|HANDLE
name|threadId
parameter_list|,
name|LPCSTR
name|threadName
parameter_list|)
block|{
name|THREADNAME_INFO
name|info
decl_stmt|;
name|info
operator|.
name|dwType
operator|=
literal|0x1000
expr_stmt|;
name|info
operator|.
name|szName
operator|=
name|threadName
expr_stmt|;
name|info
operator|.
name|dwThreadID
operator|=
name|threadId
expr_stmt|;
name|info
operator|.
name|dwFlags
operator|=
literal|0
expr_stmt|;
name|__try
block|{
name|RaiseException
argument_list|(
literal|0x406D1388
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|info
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|DWORD
argument_list|)
argument_list|,
operator|(
specifier|const
name|ULONG_PTR
operator|*
operator|)
operator|&
name|info
argument_list|)
expr_stmt|;
block|}
name|__except
argument_list|(
argument|EXCEPTION_CONTINUE_EXECUTION
argument_list|)
block|{     }
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_DEBUG&& Q_CC_MSVC&& !Q_OS_WINCE
end_comment
begin_comment
comment|/**************************************************************************  ** QThreadPrivate  *************************************************************************/
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_function
DECL|function|createEventDispatcher
name|void
name|QThreadPrivate
operator|::
name|createEventDispatcher
parameter_list|(
name|QThreadData
modifier|*
name|data
parameter_list|)
block|{
name|data
operator|->
name|eventDispatcher
operator|=
operator|new
name|QEventDispatcherWin32
expr_stmt|;
name|data
operator|->
name|eventDispatcher
operator|->
name|startingUp
argument_list|()
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_function
DECL|function|start
name|unsigned
name|int
name|__stdcall
name|QT_ENSURE_STACK_ALIGNED_FOR_SSE
name|QThreadPrivate
operator|::
name|start
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|QThread
modifier|*
name|thr
init|=
cast|reinterpret_cast
argument_list|<
name|QThread
operator|*
argument_list|>
argument_list|(
name|arg
argument_list|)
decl_stmt|;
name|QThreadData
modifier|*
name|data
init|=
name|QThreadData
operator|::
name|get2
argument_list|(
name|thr
argument_list|)
decl_stmt|;
name|qt_create_tls
argument_list|()
expr_stmt|;
name|TlsSetValue
argument_list|(
name|qt_current_thread_data_tls_index
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|data
operator|->
name|threadId
operator|=
cast|reinterpret_cast
argument_list|<
name|Qt
operator|::
name|HANDLE
argument_list|>
argument_list|(
name|GetCurrentThreadId
argument_list|()
argument_list|)
expr_stmt|;
name|QThread
operator|::
name|setTerminationEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|thr
operator|->
name|d_func
argument_list|()
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|data
operator|->
name|quitNow
operator|=
name|thr
operator|->
name|d_func
argument_list|()
operator|->
name|exited
expr_stmt|;
block|}
if|if
condition|(
name|data
operator|->
name|eventDispatcher
condition|)
comment|// custom event dispatcher set?
name|data
operator|->
name|eventDispatcher
operator|->
name|startingUp
argument_list|()
expr_stmt|;
else|else
name|createEventDispatcher
argument_list|(
name|data
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
comment|// sets the name of the current thread.
name|QByteArray
name|objectName
init|=
name|thr
operator|->
name|objectName
argument_list|()
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
name|qt_set_thread_name
argument_list|(
operator|(
name|HANDLE
operator|)
operator|-
literal|1
argument_list|,
name|objectName
operator|.
name|isEmpty
argument_list|()
condition|?
name|thr
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
else|:
name|objectName
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
emit|emit
name|thr
operator|->
name|started
argument_list|()
emit|;
name|QThread
operator|::
name|setTerminationEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|thr
operator|->
name|run
argument_list|()
expr_stmt|;
name|finish
argument_list|(
name|arg
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|finish
name|void
name|QThreadPrivate
operator|::
name|finish
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|bool
name|lockAnyway
parameter_list|)
block|{
name|QThread
modifier|*
name|thr
init|=
cast|reinterpret_cast
argument_list|<
name|QThread
operator|*
argument_list|>
argument_list|(
name|arg
argument_list|)
decl_stmt|;
name|QThreadPrivate
modifier|*
name|d
init|=
name|thr
operator|->
name|d_func
argument_list|()
decl_stmt|;
name|QMutexLocker
name|locker
argument_list|(
name|lockAnyway
condition|?
operator|&
name|d
operator|->
name|mutex
else|:
literal|0
argument_list|)
decl_stmt|;
name|d
operator|->
name|isInFinish
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|priority
operator|=
name|QThread
operator|::
name|InheritPriority
expr_stmt|;
name|void
modifier|*
modifier|*
name|tls_data
init|=
cast|reinterpret_cast
argument_list|<
name|void
operator|*
operator|*
argument_list|>
argument_list|(
operator|&
name|d
operator|->
name|data
operator|->
name|tls
argument_list|)
decl_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
emit|emit
name|thr
operator|->
name|finished
argument_list|()
emit|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
literal|0
argument_list|,
name|QEvent
operator|::
name|DeferredDelete
argument_list|)
expr_stmt|;
name|QThreadStorageData
operator|::
name|finish
argument_list|(
name|tls_data
argument_list|)
expr_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
init|=
name|d
operator|->
name|data
operator|->
name|eventDispatcher
decl_stmt|;
if|if
condition|(
name|eventDispatcher
condition|)
block|{
name|d
operator|->
name|data
operator|->
name|eventDispatcher
operator|=
literal|0
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|eventDispatcher
operator|->
name|closingDown
argument_list|()
expr_stmt|;
operator|delete
name|eventDispatcher
expr_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|running
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|finished
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|isInFinish
operator|=
literal|false
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|waiters
condition|)
block|{
name|CloseHandle
argument_list|(
name|d
operator|->
name|handle
argument_list|)
expr_stmt|;
name|d
operator|->
name|handle
operator|=
literal|0
expr_stmt|;
block|}
name|d
operator|->
name|id
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/**************************************************************************  ** QThread  *************************************************************************/
end_comment
begin_function
name|Qt
operator|::
name|HANDLE
name|QThread
operator|::
name|currentThreadId
parameter_list|()
name|Q_DECL_NOTHROW
block|{
return|return
cast|reinterpret_cast
argument_list|<
name|Qt
operator|::
name|HANDLE
argument_list|>
argument_list|(
name|GetCurrentThreadId
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
name|int
name|QThread
operator|::
name|idealThreadCount
parameter_list|()
name|Q_DECL_NOTHROW
block|{
name|SYSTEM_INFO
name|sysinfo
decl_stmt|;
name|GetSystemInfo
argument_list|(
operator|&
name|sysinfo
argument_list|)
expr_stmt|;
return|return
name|sysinfo
operator|.
name|dwNumberOfProcessors
return|;
block|}
end_function
begin_function
DECL|function|yieldCurrentThread
name|void
name|QThread
operator|::
name|yieldCurrentThread
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|SwitchToThread
argument_list|()
expr_stmt|;
else|#
directive|else
operator|::
name|Sleep
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|sleep
name|void
name|QThread
operator|::
name|sleep
parameter_list|(
name|unsigned
name|long
name|secs
parameter_list|)
block|{
operator|::
name|Sleep
argument_list|(
name|secs
operator|*
literal|1000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|msleep
name|void
name|QThread
operator|::
name|msleep
parameter_list|(
name|unsigned
name|long
name|msecs
parameter_list|)
block|{
operator|::
name|Sleep
argument_list|(
name|msecs
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|usleep
name|void
name|QThread
operator|::
name|usleep
parameter_list|(
name|unsigned
name|long
name|usecs
parameter_list|)
block|{
operator|::
name|Sleep
argument_list|(
operator|(
name|usecs
operator|/
literal|1000
operator|)
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|start
name|void
name|QThread
operator|::
name|start
parameter_list|(
name|Priority
name|priority
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|isInFinish
condition|)
block|{
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|wait
argument_list|()
expr_stmt|;
name|locker
operator|.
name|relock
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|running
condition|)
return|return;
name|d
operator|->
name|running
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|finished
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|exited
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|returnCode
operator|=
literal|0
expr_stmt|;
comment|/*       NOTE: we create the thread in the suspended state, set the       priority and then resume the thread.        since threads are created with normal priority by default, we       could get into a case where a thread (with priority less than       NormalPriority) tries to create a new thread (also with priority       less than NormalPriority), but the newly created thread preempts       its 'parent' and runs at normal priority.     */
name|d
operator|->
name|handle
operator|=
operator|(
name|Qt
operator|::
name|HANDLE
operator|)
name|_beginthreadex
argument_list|(
name|NULL
argument_list|,
name|d
operator|->
name|stackSize
argument_list|,
name|QThreadPrivate
operator|::
name|start
argument_list|,
name|this
argument_list|,
name|CREATE_SUSPENDED
argument_list|,
operator|&
operator|(
name|d
operator|->
name|id
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|handle
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|errno
argument_list|,
literal|"QThread::start: Failed to create thread"
argument_list|)
expr_stmt|;
name|d
operator|->
name|running
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|finished
operator|=
literal|true
expr_stmt|;
return|return;
block|}
name|int
name|prio
decl_stmt|;
name|d
operator|->
name|priority
operator|=
name|priority
expr_stmt|;
switch|switch
condition|(
name|d
operator|->
name|priority
condition|)
block|{
case|case
name|IdlePriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_IDLE
expr_stmt|;
break|break;
case|case
name|LowestPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_LOWEST
expr_stmt|;
break|break;
case|case
name|LowPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_BELOW_NORMAL
expr_stmt|;
break|break;
case|case
name|NormalPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_NORMAL
expr_stmt|;
break|break;
case|case
name|HighPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_ABOVE_NORMAL
expr_stmt|;
break|break;
case|case
name|HighestPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_HIGHEST
expr_stmt|;
break|break;
case|case
name|TimeCriticalPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_TIME_CRITICAL
expr_stmt|;
break|break;
case|case
name|InheritPriority
case|:
default|default:
name|prio
operator|=
name|GetThreadPriority
argument_list|(
name|GetCurrentThread
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|!
name|SetThreadPriority
argument_list|(
name|d
operator|->
name|handle
argument_list|,
name|prio
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"QThread::start: Failed to set thread priority"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ResumeThread
argument_list|(
name|d
operator|->
name|handle
argument_list|)
operator|==
operator|(
name|DWORD
operator|)
operator|-
literal|1
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"QThread::start: Failed to resume new thread"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|terminate
name|void
name|QThread
operator|::
name|terminate
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|running
condition|)
return|return;
if|if
condition|(
operator|!
name|d
operator|->
name|terminationEnabled
condition|)
block|{
name|d
operator|->
name|terminatePending
operator|=
literal|true
expr_stmt|;
return|return;
block|}
name|TerminateThread
argument_list|(
name|d
operator|->
name|handle
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QThreadPrivate
operator|::
name|finish
argument_list|(
name|this
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wait
name|bool
name|QThread
operator|::
name|wait
parameter_list|(
name|unsigned
name|long
name|time
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|id
operator|==
name|GetCurrentThreadId
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QThread::wait: Thread tried to wait on itself"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|d
operator|->
name|finished
operator|||
operator|!
name|d
operator|->
name|running
condition|)
return|return
literal|true
return|;
operator|++
name|d
operator|->
name|waiters
expr_stmt|;
name|locker
operator|.
name|mutex
argument_list|()
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|bool
name|ret
init|=
literal|false
decl_stmt|;
switch|switch
condition|(
name|WaitForSingleObject
argument_list|(
name|d
operator|->
name|handle
argument_list|,
name|time
argument_list|)
condition|)
block|{
case|case
name|WAIT_OBJECT_0
case|:
name|ret
operator|=
literal|true
expr_stmt|;
break|break;
case|case
name|WAIT_FAILED
case|:
name|qErrnoWarning
argument_list|(
literal|"QThread::wait: Thread wait failure"
argument_list|)
expr_stmt|;
break|break;
case|case
name|WAIT_ABANDONED
case|:
case|case
name|WAIT_TIMEOUT
case|:
default|default:
break|break;
block|}
name|locker
operator|.
name|mutex
argument_list|()
operator|->
name|lock
argument_list|()
expr_stmt|;
operator|--
name|d
operator|->
name|waiters
expr_stmt|;
if|if
condition|(
name|ret
operator|&&
operator|!
name|d
operator|->
name|finished
condition|)
block|{
comment|// thread was terminated by someone else
name|QThreadPrivate
operator|::
name|finish
argument_list|(
name|this
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|finished
operator|&&
operator|!
name|d
operator|->
name|waiters
condition|)
block|{
name|CloseHandle
argument_list|(
name|d
operator|->
name|handle
argument_list|)
expr_stmt|;
name|d
operator|->
name|handle
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|setTerminationEnabled
name|void
name|QThread
operator|::
name|setTerminationEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|QThread
modifier|*
name|thr
init|=
name|currentThread
argument_list|()
decl_stmt|;
name|Q_ASSERT_X
argument_list|(
name|thr
operator|!=
literal|0
argument_list|,
literal|"QThread::setTerminationEnabled()"
argument_list|,
literal|"Current thread was not started with QThread."
argument_list|)
expr_stmt|;
name|QThreadPrivate
modifier|*
name|d
init|=
name|thr
operator|->
name|d_func
argument_list|()
decl_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|d
operator|->
name|terminationEnabled
operator|=
name|enabled
expr_stmt|;
if|if
condition|(
name|enabled
operator|&&
name|d
operator|->
name|terminatePending
condition|)
block|{
name|QThreadPrivate
operator|::
name|finish
argument_list|(
name|thr
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
comment|// don't leave the mutex locked!
name|_endthreadex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setPriority
name|void
name|QThread
operator|::
name|setPriority
parameter_list|(
name|Priority
name|priority
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|running
condition|)
block|{
name|qWarning
argument_list|(
literal|"QThread::setPriority: Cannot set priority, thread is not running"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// copied from start() with a few modifications:
name|int
name|prio
decl_stmt|;
name|d
operator|->
name|priority
operator|=
name|priority
expr_stmt|;
switch|switch
condition|(
name|d
operator|->
name|priority
condition|)
block|{
case|case
name|IdlePriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_IDLE
expr_stmt|;
break|break;
case|case
name|LowestPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_LOWEST
expr_stmt|;
break|break;
case|case
name|LowPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_BELOW_NORMAL
expr_stmt|;
break|break;
case|case
name|NormalPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_NORMAL
expr_stmt|;
break|break;
case|case
name|HighPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_ABOVE_NORMAL
expr_stmt|;
break|break;
case|case
name|HighestPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_HIGHEST
expr_stmt|;
break|break;
case|case
name|TimeCriticalPriority
case|:
name|prio
operator|=
name|THREAD_PRIORITY_TIME_CRITICAL
expr_stmt|;
break|break;
case|case
name|InheritPriority
case|:
default|default:
name|qWarning
argument_list|(
literal|"QThread::setPriority: Argument cannot be InheritPriority"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|SetThreadPriority
argument_list|(
name|d
operator|->
name|handle
argument_list|,
name|prio
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"QThread::setPriority: Failed to set thread priority"
argument_list|)
expr_stmt|;
block|}
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
comment|// QT_NO_THREAD
end_comment
end_unit
