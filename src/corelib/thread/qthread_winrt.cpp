begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|<QtCore/QElapsedTimer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUuid>
end_include
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfunctions_winrt.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qeventdispatcher_winrt_p.h>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.system.threading.h>
end_include
begin_include
include|#
directive|include
file|<windows.system.threading.core.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|System
operator|::
name|Threading
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|System
operator|::
name|Threading
operator|::
name|Core
namespace|;
end_using
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|nativePriority
specifier|static
name|WorkItemPriority
name|nativePriority
parameter_list|(
name|QThread
operator|::
name|Priority
name|priority
parameter_list|)
block|{
switch|switch
condition|(
name|priority
condition|)
block|{
default|default:
case|case
name|QThread
operator|::
name|NormalPriority
case|:
return|return
name|WorkItemPriority_Normal
return|;
case|case
name|QThread
operator|::
name|IdlePriority
case|:
case|case
name|QThread
operator|::
name|LowestPriority
case|:
case|case
name|QThread
operator|::
name|LowPriority
case|:
return|return
name|WorkItemPriority_Low
return|;
case|case
name|QThread
operator|::
name|HighPriority
case|:
case|case
name|QThread
operator|::
name|HighestPriority
case|:
case|case
name|QThread
operator|::
name|TimeCriticalPriority
case|:
return|return
name|WorkItemPriority_High
return|;
block|}
block|}
end_function
begin_class
DECL|class|QWinRTThreadGlobal
class|class
name|QWinRTThreadGlobal
block|{
public|public:
DECL|function|QWinRTThreadGlobal
name|QWinRTThreadGlobal
parameter_list|()
block|{
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_System_Threading_Core_PreallocatedWorkItem
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|workItemFactory
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_System_Threading_Core_SignalNotifier
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|notifierFactory
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|QString
name|eventName
init|=
name|QUuid
operator|::
name|createUuid
argument_list|()
operator|.
name|toString
argument_list|()
decl_stmt|;
name|dispatchEvent
operator|=
name|CreateEventEx
argument_list|(
name|NULL
argument_list|,
cast|reinterpret_cast
argument_list|<
name|LPCWSTR
argument_list|>
argument_list|(
name|eventName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|,
name|EVENT_ALL_ACCESS
argument_list|)
expr_stmt|;
name|hr
operator|=
name|notifierFactory
operator|->
name|AttachToEvent
argument_list|(
name|HStringReference
argument_list|(
cast|reinterpret_cast
argument_list|<
name|LPCWSTR
argument_list|>
argument_list|(
name|eventName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|Callback
argument_list|<
name|ISignalHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTThreadGlobal
operator|::
name|dispatch
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|notifier
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|notifier
operator|->
name|Enable
argument_list|()
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
DECL|function|~QWinRTThreadGlobal
name|~
name|QWinRTThreadGlobal
parameter_list|()
block|{
name|CloseHandle
argument_list|(
name|dispatchEvent
argument_list|)
expr_stmt|;
block|}
DECL|function|dispatch
name|void
name|dispatch
parameter_list|()
block|{
name|SetEvent
argument_list|(
name|dispatchEvent
argument_list|)
expr_stmt|;
block|}
DECL|function|push
name|void
name|push
parameter_list|(
name|QThreadPrivate
modifier|*
name|d
parameter_list|)
block|{
name|threads
operator|.
name|append
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|function|dispatch
name|HRESULT
name|dispatch
parameter_list|(
name|ISignalNotifier
modifier|*
name|notifier
parameter_list|,
name|boolean
name|timedOut
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|timedOut
argument_list|)
expr_stmt|;
name|notifier
operator|->
name|Enable
argument_list|()
expr_stmt|;
if|if
condition|(
name|threads
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|S_OK
return|;
name|QThreadPrivate
modifier|*
name|thread
init|=
name|threads
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|ComPtr
argument_list|<
name|IPreallocatedWorkItem
argument_list|>
name|workItem
decl_stmt|;
name|HRESULT
name|hr
init|=
name|workItemFactory
operator|->
name|CreateWorkItemWithPriority
argument_list|(
name|Callback
argument_list|<
name|IWorkItemHandler
argument_list|>
argument_list|(
name|thread
argument_list|,
operator|&
name|QThreadPrivate
operator|::
name|start
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|nativePriority
argument_list|(
name|thread
operator|->
name|priority
argument_list|)
argument_list|,
operator|&
name|workItem
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to create thread work item"
argument_list|)
expr_stmt|;
name|thread
operator|->
name|finish
argument_list|()
expr_stmt|;
return|return
name|hr
return|;
block|}
name|hr
operator|=
name|workItem
operator|->
name|RunAsync
argument_list|(
operator|&
name|thread
operator|->
name|handle
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to run work item"
argument_list|)
expr_stmt|;
name|thread
operator|->
name|finish
argument_list|()
expr_stmt|;
return|return
name|hr
return|;
block|}
return|return
name|S_OK
return|;
block|}
DECL|member|dispatchEvent
name|HANDLE
name|dispatchEvent
decl_stmt|;
DECL|member|notifier
name|ComPtr
argument_list|<
name|ISignalNotifier
argument_list|>
name|notifier
decl_stmt|;
DECL|member|notifierFactory
name|ComPtr
argument_list|<
name|ISignalNotifierStatics
argument_list|>
name|notifierFactory
decl_stmt|;
DECL|member|workItemFactory
name|ComPtr
argument_list|<
name|IPreallocatedWorkItemFactory
argument_list|>
name|workItemFactory
decl_stmt|;
DECL|member|threads
name|QList
argument_list|<
name|QThreadPrivate
modifier|*
argument_list|>
name|threads
decl_stmt|;
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QWinRTThreadGlobal
argument_list|,
argument|g
argument_list|)
end_macro
begin_comment
comment|/**************************************************************************  ** QThreadData  *************************************************************************/
end_comment
begin_macro
DECL|variable|qt_current_thread_data
name|__declspec
argument_list|(
argument|thread
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|qt_current_thread_data
specifier|static
name|QThreadData
modifier|*
name|qt_current_thread_data
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|clearCurrentThreadData
name|void
name|QThreadData
operator|::
name|clearCurrentThreadData
parameter_list|()
block|{
name|qt_current_thread_data
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|current
name|QThreadData
modifier|*
name|QThreadData
operator|::
name|current
parameter_list|(
name|bool
name|createIfNecessary
parameter_list|)
block|{
specifier|static
name|bool
name|winmainThread
init|=
literal|true
decl_stmt|;
name|QThreadData
modifier|*
name|threadData
init|=
name|qt_current_thread_data
decl_stmt|;
if|if
condition|(
operator|!
name|threadData
operator|&&
name|createIfNecessary
condition|)
block|{
name|threadData
operator|=
operator|new
name|QThreadData
expr_stmt|;
comment|// This needs to be called prior to new AdoptedThread() to
comment|// avoid recursion.
name|qt_current_thread_data
operator|=
name|threadData
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
name|qt_current_thread_data
operator|=
literal|0
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
operator|&&
operator|!
name|winmainThread
condition|)
name|QCoreApplicationPrivate
operator|::
name|theMainThread
operator|=
name|threadData
operator|->
name|thread
expr_stmt|;
if|if
condition|(
name|winmainThread
condition|)
block|{
name|g
operator|->
name|dispatch
argument_list|()
expr_stmt|;
name|winmainThread
operator|=
literal|false
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
name|Q_D
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|d
operator|->
name|handle
operator|=
name|Q_NULLPTR
expr_stmt|;
name|d
operator|->
name|id
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|createEventDispatcher
argument_list|(
name|d
operator|->
name|data
argument_list|)
expr_stmt|;
block|}
end_function
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
name|QEventDispatcherWinRT
modifier|*
name|eventDispatcher
init|=
operator|new
name|QEventDispatcherWinRT
decl_stmt|;
name|data
operator|->
name|eventDispatcher
operator|.
name|storeRelease
argument_list|(
name|eventDispatcher
argument_list|)
expr_stmt|;
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
name|HRESULT
name|QThreadPrivate
operator|::
name|start
parameter_list|(
name|IAsyncAction
modifier|*
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|qt_current_thread_data
operator|=
name|data
expr_stmt|;
name|id
operator|=
name|GetCurrentThreadId
argument_list|()
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
name|id
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
name|mutex
argument_list|)
decl_stmt|;
name|data
operator|->
name|quitNow
operator|=
name|exited
expr_stmt|;
block|}
if|if
condition|(
name|data
operator|->
name|eventDispatcher
operator|.
name|load
argument_list|()
condition|)
name|data
operator|->
name|eventDispatcher
operator|.
name|load
argument_list|()
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
name|running
operator|=
literal|true
expr_stmt|;
emit|emit
name|q
operator|->
name|started
argument_list|(
name|QThread
operator|::
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
name|QThread
operator|::
name|setTerminationEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|run
argument_list|()
expr_stmt|;
name|finish
argument_list|()
expr_stmt|;
return|return
name|S_OK
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
name|bool
name|lockAnyway
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QThread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
name|lockAnyway
condition|?
operator|&
name|mutex
else|:
literal|0
argument_list|)
decl_stmt|;
name|isInFinish
operator|=
literal|true
expr_stmt|;
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
name|q
operator|->
name|finished
argument_list|(
name|QThread
operator|::
name|QPrivateSignal
argument_list|()
argument_list|)
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
name|data
operator|->
name|eventDispatcher
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
name|eventDispatcher
condition|)
block|{
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
name|running
operator|=
literal|false
expr_stmt|;
name|finished
operator|=
literal|true
expr_stmt|;
name|isInFinish
operator|=
literal|false
expr_stmt|;
name|interruptionRequested
operator|=
literal|false
expr_stmt|;
if|if
condition|(
operator|!
name|waiters
condition|)
block|{
if|if
condition|(
name|handle
condition|)
name|handle
operator|->
name|Release
argument_list|()
expr_stmt|;
name|handle
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
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
name|GetNativeSystemInfo
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
name|msleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
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
name|msleep
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
name|WaitForSingleObjectEx
argument_list|(
name|GetCurrentThread
argument_list|()
argument_list|,
name|msecs
argument_list|,
name|FALSE
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
name|msleep
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
name|d
operator|->
name|interruptionRequested
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|priority
operator|=
name|priority
operator|==
name|QThread
operator|::
name|InheritPriority
condition|?
name|currentThread
argument_list|()
operator|->
name|priority
argument_list|()
else|:
name|priority
expr_stmt|;
name|g
operator|->
name|push
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|g
operator|->
name|dispatch
argument_list|()
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|d
operator|->
name|running
operator|&&
operator|!
name|d
operator|->
name|finished
condition|)
block|{
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
init|=
name|QThread
operator|::
name|currentThread
argument_list|()
operator|->
name|eventDispatcher
argument_list|()
decl_stmt|;
if|if
condition|(
name|eventDispatcher
condition|)
name|eventDispatcher
operator|->
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|AllEvents
argument_list|)
expr_stmt|;
else|else
name|yieldCurrentThread
argument_list|()
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
if|if
condition|(
name|d
operator|->
name|handle
condition|)
block|{
name|ComPtr
argument_list|<
name|IAsyncInfo
argument_list|>
name|info
decl_stmt|;
name|HRESULT
name|hr
init|=
name|d
operator|->
name|handle
operator|->
name|QueryInterface
argument_list|(
name|IID_PPV_ARGS
argument_list|(
operator|&
name|info
argument_list|)
argument_list|)
decl_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|info
operator|->
name|Cancel
argument_list|()
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to cancel thread action"
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|finish
argument_list|(
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
comment|// Alternatively, we could check the handle
name|bool
name|ret
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|finished
condition|)
block|{
name|QElapsedTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|<
name|time
operator|&&
operator|!
name|d
operator|->
name|finished
condition|)
name|yieldCurrentThread
argument_list|()
expr_stmt|;
name|ret
operator|=
name|d
operator|->
name|finished
expr_stmt|;
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
name|d
operator|->
name|finish
argument_list|(
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
if|if
condition|(
name|d
operator|->
name|handle
condition|)
name|d
operator|->
name|handle
operator|->
name|Release
argument_list|()
expr_stmt|;
name|d
operator|->
name|handle
operator|=
name|Q_NULLPTR
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
name|d
operator|->
name|finish
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
comment|// don't leave the mutex locked!
block|}
block|}
end_function
begin_comment
comment|// Caller must hold the mutex
end_comment
begin_function
DECL|function|setPriority
name|void
name|QThreadPrivate
operator|::
name|setPriority
parameter_list|(
name|QThread
operator|::
name|Priority
name|threadPriority
parameter_list|)
block|{
if|if
condition|(
name|running
condition|)
name|qWarning
argument_list|(
literal|"WinRT threads can't change priority while running."
argument_list|)
expr_stmt|;
name|priority
operator|=
name|threadPriority
expr_stmt|;
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
