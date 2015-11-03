begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeventdispatcher_winrt_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfunctions_winrt.h>
end_include
begin_include
include|#
directive|include
file|<private/qabstracteventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<functional>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.h>
end_include
begin_include
include|#
directive|include
file|<windows.system.threading.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.core.h>
end_include
begin_include
include|#
directive|include
file|<windows.applicationmodel.core.h>
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
name|UI
operator|::
name|Core
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|Core
namespace|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_define
DECL|macro|INTERRUPT_HANDLE
define|#
directive|define
name|INTERRUPT_HANDLE
value|0
end_define
begin_define
DECL|macro|INVALID_TIMER_ID
define|#
directive|define
name|INVALID_TIMER_ID
value|-1
end_define
begin_struct
DECL|struct|WinRTTimerInfo
struct|struct
name|WinRTTimerInfo
super|:
specifier|public
name|QAbstractEventDispatcher
operator|::
name|TimerInfo
block|{
DECL|function|WinRTTimerInfo
name|WinRTTimerInfo
parameter_list|(
name|int
name|timerId
init|=
name|INVALID_TIMER_ID
parameter_list|,
name|int
name|interval
init|=
literal|0
parameter_list|,
name|Qt
operator|::
name|TimerType
name|timerType
init|=
name|Qt
operator|::
name|CoarseTimer
parameter_list|,
name|QObject
modifier|*
name|obj
init|=
literal|0
parameter_list|,
name|quint64
name|tt
init|=
literal|0
parameter_list|)
member_init_list|:
name|QAbstractEventDispatcher
operator|::
name|TimerInfo
argument_list|(
name|timerId
argument_list|,
name|interval
argument_list|,
name|timerType
argument_list|)
member_init_list|,
name|inEvent
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|object
argument_list|(
name|obj
argument_list|)
member_init_list|,
name|targetTime
argument_list|(
name|tt
argument_list|)
block|{     }
DECL|member|inEvent
name|bool
name|inEvent
decl_stmt|;
DECL|member|object
name|QObject
modifier|*
name|object
decl_stmt|;
DECL|member|targetTime
name|quint64
name|targetTime
decl_stmt|;
block|}
struct|;
end_struct
begin_class
DECL|class|AgileDispatchedHandler
class|class
name|AgileDispatchedHandler
super|:
specifier|public
name|RuntimeClass
argument_list|<
name|RuntimeClassFlags
argument_list|<
name|WinRtClassicComMix
argument_list|>
argument_list|,
name|IDispatchedHandler
argument_list|,
name|IAgileObject
argument_list|>
block|{
public|public:
DECL|function|AgileDispatchedHandler
name|AgileDispatchedHandler
parameter_list|(
specifier|const
name|std
operator|::
name|function
argument_list|<
name|HRESULT
operator|(
operator|)
argument_list|>
modifier|&
name|delegate
parameter_list|)
member_init_list|:
name|delegate
argument_list|(
name|delegate
argument_list|)
block|{     }
DECL|function|Invoke
name|HRESULT
name|__stdcall
name|Invoke
parameter_list|()
block|{
return|return
name|delegate
argument_list|()
return|;
block|}
private|private:
DECL|member|delegate
name|std
operator|::
name|function
argument_list|<
name|HRESULT
operator|(
operator|)
argument_list|>
name|delegate
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QEventDispatcherWinRTPrivate
class|class
name|QEventDispatcherWinRTPrivate
super|:
specifier|public
name|QAbstractEventDispatcherPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QEventDispatcherWinRT
parameter_list|)
specifier|public
private|:
name|QEventDispatcherWinRTPrivate
parameter_list|()
constructor_decl|;
name|~
name|QEventDispatcherWinRTPrivate
parameter_list|()
destructor_decl|;
private|private:
DECL|member|timerIdToObject
name|QHash
argument_list|<
name|int
argument_list|,
name|QObject
modifier|*
argument_list|>
name|timerIdToObject
decl_stmt|;
DECL|member|timerInfos
name|QVector
argument_list|<
name|WinRTTimerInfo
argument_list|>
name|timerInfos
decl_stmt|;
DECL|member|timerHandleToId
name|QHash
argument_list|<
name|HANDLE
argument_list|,
name|int
argument_list|>
name|timerHandleToId
decl_stmt|;
DECL|member|timerIdToHandle
name|QHash
argument_list|<
name|int
argument_list|,
name|HANDLE
argument_list|>
name|timerIdToHandle
decl_stmt|;
DECL|member|timerIdToCancelHandle
name|QHash
argument_list|<
name|int
argument_list|,
name|HANDLE
argument_list|>
name|timerIdToCancelHandle
decl_stmt|;
DECL|function|addTimer
name|void
name|addTimer
parameter_list|(
name|int
name|id
parameter_list|,
name|int
name|interval
parameter_list|,
name|Qt
operator|::
name|TimerType
name|type
parameter_list|,
name|QObject
modifier|*
name|obj
parameter_list|,
name|HANDLE
name|handle
parameter_list|,
name|HANDLE
name|cancelHandle
parameter_list|)
block|{
comment|// Zero timer events do not need these handles.
if|if
condition|(
name|interval
operator|>
literal|0
condition|)
block|{
name|timerHandleToId
operator|.
name|insert
argument_list|(
name|handle
argument_list|,
name|id
argument_list|)
expr_stmt|;
name|timerIdToHandle
operator|.
name|insert
argument_list|(
name|id
argument_list|,
name|handle
argument_list|)
expr_stmt|;
name|timerIdToCancelHandle
operator|.
name|insert
argument_list|(
name|id
argument_list|,
name|cancelHandle
argument_list|)
expr_stmt|;
block|}
name|timerIdToObject
operator|.
name|insert
argument_list|(
name|id
argument_list|,
name|obj
argument_list|)
expr_stmt|;
specifier|const
name|quint64
name|targetTime
init|=
name|qt_msectime
argument_list|()
operator|+
name|interval
decl_stmt|;
specifier|const
name|WinRTTimerInfo
name|info
argument_list|(
name|id
argument_list|,
name|interval
argument_list|,
name|type
argument_list|,
name|obj
argument_list|,
name|targetTime
argument_list|)
decl_stmt|;
if|if
condition|(
name|id
operator|>=
name|timerInfos
operator|.
name|size
argument_list|()
condition|)
name|timerInfos
operator|.
name|resize
argument_list|(
name|id
operator|+
literal|1
argument_list|)
expr_stmt|;
name|timerInfos
index|[
name|id
index|]
operator|=
name|info
expr_stmt|;
name|timerIdToObject
operator|.
name|insert
argument_list|(
name|id
argument_list|,
name|obj
argument_list|)
expr_stmt|;
block|}
DECL|function|removeTimer
name|bool
name|removeTimer
parameter_list|(
name|int
name|id
parameter_list|)
block|{
if|if
condition|(
name|id
operator|>=
name|timerInfos
operator|.
name|size
argument_list|()
condition|)
return|return
literal|false
return|;
name|WinRTTimerInfo
modifier|&
name|info
init|=
name|timerInfos
index|[
name|id
index|]
decl_stmt|;
if|if
condition|(
name|info
operator|.
name|timerId
operator|==
name|INVALID_TIMER_ID
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|info
operator|.
name|interval
operator|>
literal|0
operator|&&
operator|(
operator|!
name|timerIdToHandle
operator|.
name|contains
argument_list|(
name|id
argument_list|)
operator|||
operator|!
name|timerIdToCancelHandle
operator|.
name|contains
argument_list|(
name|id
argument_list|)
operator|)
condition|)
return|return
literal|false
return|;
name|info
operator|.
name|timerId
operator|=
name|INVALID_TIMER_ID
expr_stmt|;
comment|// Remove invalid timerinfos from the vector's end, if the timer with the highest id was removed
name|int
name|lastTimer
init|=
name|timerInfos
operator|.
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
while|while
condition|(
name|lastTimer
operator|>=
literal|0
operator|&&
name|timerInfos
operator|.
name|at
argument_list|(
name|lastTimer
argument_list|)
operator|.
name|timerId
operator|==
name|INVALID_TIMER_ID
condition|)
operator|--
name|lastTimer
expr_stmt|;
if|if
condition|(
name|lastTimer
operator|>=
literal|0
operator|&&
name|lastTimer
operator|!=
name|timerInfos
operator|.
name|size
argument_list|()
operator|-
literal|1
condition|)
name|timerInfos
operator|.
name|resize
argument_list|(
name|lastTimer
operator|+
literal|1
argument_list|)
expr_stmt|;
name|timerIdToObject
operator|.
name|remove
argument_list|(
name|id
argument_list|)
expr_stmt|;
comment|// ... remove handle from all lists
if|if
condition|(
name|info
operator|.
name|interval
operator|>
literal|0
condition|)
block|{
name|HANDLE
name|handle
init|=
name|timerIdToHandle
operator|.
name|take
argument_list|(
name|id
argument_list|)
decl_stmt|;
name|timerHandleToId
operator|.
name|remove
argument_list|(
name|handle
argument_list|)
expr_stmt|;
name|SetEvent
argument_list|(
name|timerIdToCancelHandle
operator|.
name|take
argument_list|(
name|id
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|QEventDispatcherWinRT
name|QEventDispatcherWinRT
operator|::
name|QEventDispatcherWinRT
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractEventDispatcher
argument_list|(
operator|*
operator|new
name|QEventDispatcherWinRTPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QEventDispatcherWinRT
name|QEventDispatcherWinRT
operator|::
name|QEventDispatcherWinRT
parameter_list|(
name|QEventDispatcherWinRTPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractEventDispatcher
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QEventDispatcherWinRT
name|QEventDispatcherWinRT
operator|::
name|~
name|QEventDispatcherWinRT
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|runOnXamlThread
name|HRESULT
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
parameter_list|(
specifier|const
name|std
operator|::
name|function
argument_list|<
name|HRESULT
operator|(
operator|)
argument_list|>
modifier|&
name|delegate
parameter_list|,
name|bool
name|waitForRun
parameter_list|)
block|{
specifier|static
name|__declspec
argument_list|(
argument|thread
argument_list|)
name|ICoreDispatcher
operator|*
name|dispatcher
operator|=
literal|nullptr
expr_stmt|;
if|if
condition|(
operator|!
name|dispatcher
condition|)
block|{
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|ICoreImmersiveApplication
argument_list|>
name|application
decl_stmt|;
name|hr
operator|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_ApplicationModel_Core_CoreApplication
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|application
argument_list|)
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|ICoreApplicationView
argument_list|>
name|view
decl_stmt|;
name|hr
operator|=
name|application
operator|->
name|get_MainView
argument_list|(
operator|&
name|view
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|ICoreWindow
argument_list|>
name|window
decl_stmt|;
name|hr
operator|=
name|view
operator|->
name|get_CoreWindow
argument_list|(
operator|&
name|window
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|window
operator|->
name|get_Dispatcher
argument_list|(
operator|&
name|dispatcher
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
name|HRESULT
name|hr
decl_stmt|;
name|boolean
name|onXamlThread
decl_stmt|;
name|hr
operator|=
name|dispatcher
operator|->
name|get_HasThreadAccess
argument_list|(
operator|&
name|onXamlThread
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
name|onXamlThread
condition|)
comment|// Already there
return|return
name|delegate
argument_list|()
return|;
name|ComPtr
argument_list|<
name|IAsyncAction
argument_list|>
name|op
decl_stmt|;
name|hr
operator|=
name|dispatcher
operator|->
name|RunAsync
argument_list|(
name|CoreDispatcherPriority_Normal
argument_list|,
name|Make
argument_list|<
name|AgileDispatchedHandler
argument_list|>
argument_list|(
name|delegate
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|op
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
operator|||
operator|!
name|waitForRun
condition|)
return|return
name|hr
return|;
return|return
name|QWinRTFunctions
operator|::
name|await
argument_list|(
name|op
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|processEvents
name|bool
name|QEventDispatcherWinRT
operator|::
name|processEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
do|do
block|{
comment|// Additional user events have to be handled before timer events, but the function may not
comment|// return yet.
specifier|const
name|bool
name|userEventsSent
init|=
name|sendPostedEvents
argument_list|(
name|flags
argument_list|)
decl_stmt|;
emit|emit
name|aboutToBlock
argument_list|()
emit|;
specifier|const
name|QVector
argument_list|<
name|HANDLE
argument_list|>
name|timerHandles
init|=
name|d
operator|->
name|timerIdToHandle
operator|.
name|values
argument_list|()
operator|.
name|toVector
argument_list|()
decl_stmt|;
name|DWORD
name|waitResult
init|=
name|WaitForMultipleObjectsEx
argument_list|(
name|timerHandles
operator|.
name|count
argument_list|()
argument_list|,
name|timerHandles
operator|.
name|constData
argument_list|()
argument_list|,
name|FALSE
argument_list|,
literal|1
argument_list|,
name|TRUE
argument_list|)
decl_stmt|;
if|if
condition|(
name|waitResult
operator|>=
name|WAIT_OBJECT_0
operator|&&
name|waitResult
operator|<
name|WAIT_OBJECT_0
operator|+
name|timerHandles
operator|.
name|count
argument_list|()
condition|)
block|{
specifier|const
name|HANDLE
name|handle
init|=
name|timerHandles
operator|.
name|value
argument_list|(
name|waitResult
operator|-
name|WAIT_OBJECT_0
argument_list|)
decl_stmt|;
name|ResetEvent
argument_list|(
name|handle
argument_list|)
expr_stmt|;
specifier|const
name|int
name|timerId
init|=
name|d
operator|->
name|timerHandleToId
operator|.
name|value
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|timerId
operator|==
name|INTERRUPT_HANDLE
condition|)
break|break;
name|WinRTTimerInfo
modifier|&
name|info
init|=
name|d
operator|->
name|timerInfos
index|[
name|timerId
index|]
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|info
operator|.
name|timerId
operator|!=
name|INVALID_TIMER_ID
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QTimerEvent
argument_list|(
name|timerId
argument_list|)
argument_list|)
expr_stmt|;
comment|// Update timer's targetTime
specifier|const
name|quint64
name|targetTime
init|=
name|qt_msectime
argument_list|()
operator|+
name|info
operator|.
name|interval
decl_stmt|;
name|info
operator|.
name|targetTime
operator|=
name|targetTime
expr_stmt|;
emit|emit
name|awake
argument_list|()
emit|;
return|return
literal|true
return|;
block|}
emit|emit
name|awake
argument_list|()
emit|;
if|if
condition|(
name|userEventsSent
condition|)
return|return
literal|true
return|;
block|}
do|while
condition|(
name|flags
operator|&
name|QEventLoop
operator|::
name|WaitForMoreEvents
condition|)
do|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|sendPostedEvents
name|bool
name|QEventDispatcherWinRT
operator|::
name|sendPostedEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasPendingEvents
argument_list|()
condition|)
block|{
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|hasPendingEvents
name|bool
name|QEventDispatcherWinRT
operator|::
name|hasPendingEvents
parameter_list|()
block|{
return|return
name|qGlobalPostedEventsCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|registerSocketNotifier
name|void
name|QEventDispatcherWinRT
operator|::
name|registerSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterSocketNotifier
name|void
name|QEventDispatcherWinRT
operator|::
name|unregisterSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|registerTimer
name|void
name|QEventDispatcherWinRT
operator|::
name|registerTimer
parameter_list|(
name|int
name|timerId
parameter_list|,
name|int
name|interval
parameter_list|,
name|Qt
operator|::
name|TimerType
name|timerType
parameter_list|,
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|timerType
argument_list|)
expr_stmt|;
if|if
condition|(
name|timerId
operator|<
literal|1
operator|||
name|interval
operator|<
literal|0
operator|||
operator|!
name|object
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::registerTimer: invalid arguments"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
elseif|else
if|if
condition|(
name|object
operator|->
name|thread
argument_list|()
operator|!=
name|thread
argument_list|()
operator|||
name|thread
argument_list|()
operator|!=
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::registerTimer: timers cannot be started from another thread"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
comment|// Don't use timer factory for zero-delay timers
if|if
condition|(
name|interval
operator|==
literal|0u
condition|)
block|{
name|d
operator|->
name|addTimer
argument_list|(
name|timerId
argument_list|,
name|interval
argument_list|,
name|timerType
argument_list|,
name|object
argument_list|,
name|INVALID_HANDLE_VALUE
argument_list|,
name|INVALID_HANDLE_VALUE
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QTimerEvent
argument_list|(
name|timerId
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|TimeSpan
name|period
decl_stmt|;
comment|// TimeSpan is based on 100-nanosecond units
name|period
operator|.
name|Duration
operator|=
name|qMax
argument_list|(
name|qint64
argument_list|(
literal|1
argument_list|)
argument_list|,
name|qint64
argument_list|(
name|interval
argument_list|)
operator|*
literal|10000
argument_list|)
expr_stmt|;
specifier|const
name|HANDLE
name|handle
init|=
name|CreateEventEx
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|CREATE_EVENT_MANUAL_RESET
argument_list|,
name|SYNCHRONIZE
operator||
name|EVENT_MODIFY_STATE
argument_list|)
decl_stmt|;
specifier|const
name|HANDLE
name|cancelHandle
init|=
name|CreateEventEx
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|CREATE_EVENT_MANUAL_RESET
argument_list|,
name|SYNCHRONIZE
operator||
name|EVENT_MODIFY_STATE
argument_list|)
decl_stmt|;
name|HRESULT
name|hr
init|=
name|runOnXamlThread
argument_list|(
capture|[
name|cancelHandle
capture|,
name|handle
capture|,
name|period
capture|]
parameter_list|()
block|{
specifier|static
name|ComPtr
argument_list|<
name|IThreadPoolTimerStatics
argument_list|>
name|timerFactory
decl_stmt|;
name|HRESULT
name|hr
decl_stmt|;
if|if
condition|(
operator|!
name|timerFactory
condition|)
block|{
name|hr
operator|=
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_System_Threading_ThreadPoolTimer
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|timerFactory
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
name|IThreadPoolTimer
modifier|*
name|timer
decl_stmt|;
name|hr
operator|=
name|timerFactory
operator|->
name|CreatePeriodicTimerWithCompletion
argument_list|(
name|Callback
argument_list|<
name|ITimerElapsedHandler
argument_list|>
argument_list|(
capture|[
name|handle
capture|,
name|cancelHandle
capture|]
parameter_list|(
name|IThreadPoolTimer
modifier|*
name|timer
parameter_list|)
block|{
name|DWORD
name|cancelResult
type|=
name|WaitForSingleObjectEx
type|(
name|cancelHandle
decl_stmt|, 0,
name|TRUE
decl_stmt|);
if|if
condition|(
name|cancelResult
operator|==
name|WAIT_OBJECT_0
condition|)
block|{
name|timer
operator|->
name|Cancel
argument_list|()
expr_stmt|;
return|return
name|S_OK
return|;
block|}
if|if
condition|(
operator|!
name|SetEvent
argument_list|(
name|handle
argument_list|)
condition|)
block|{
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"QEventDispatcherWinRT::registerTimer"
argument_list|,
literal|"SetEvent should never fail here"
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
return|return
name|S_OK
return|;
block|}
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|period
argument_list|,
name|Callback
argument_list|<
name|ITimerDestroyedHandler
argument_list|>
argument_list|(
capture|[
name|handle
capture|,
name|cancelHandle
capture|]
parameter_list|(
name|IThreadPoolTimer
modifier|*
parameter_list|)
block|{
name|CloseHandle
argument_list|(
name|handle
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|cancelHandle
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|timer
argument_list|)
expr_stmt|;
name|RETURN_HR_IF_FAILED
argument_list|(
literal|"Failed to create periodic timer"
argument_list|)
expr_stmt|;
return|return
name|hr
return|;
block|}
argument_list|,
literal|false
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
name|CloseHandle
argument_list|(
name|handle
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|cancelHandle
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|addTimer
argument_list|(
name|timerId
argument_list|,
name|interval
argument_list|,
name|timerType
argument_list|,
name|object
argument_list|,
name|handle
argument_list|,
name|cancelHandle
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterTimer
name|bool
name|QEventDispatcherWinRT
operator|::
name|unregisterTimer
parameter_list|(
name|int
name|timerId
parameter_list|)
block|{
if|if
condition|(
name|timerId
operator|<
literal|1
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::unregisterTimer: invalid argument"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
if|if
condition|(
name|thread
argument_list|()
operator|!=
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::unregisterTimer: timers cannot be stopped from another thread"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
comment|// As we post all timer events internally, they have to pe removed to prevent stray events
name|QCoreApplicationPrivate
operator|::
name|removePostedTimerEvent
argument_list|(
name|this
argument_list|,
name|timerId
argument_list|)
expr_stmt|;
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|removeTimer
argument_list|(
name|timerId
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|unregisterTimers
name|bool
name|QEventDispatcherWinRT
operator|::
name|unregisterTimers
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
if|if
condition|(
operator|!
name|object
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::unregisterTimers: invalid argument"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
name|QThread
modifier|*
name|currentThread
init|=
name|QThread
operator|::
name|currentThread
argument_list|()
decl_stmt|;
if|if
condition|(
name|object
operator|->
name|thread
argument_list|()
operator|!=
name|thread
argument_list|()
operator|||
name|thread
argument_list|()
operator|!=
name|currentThread
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::unregisterTimers: timers cannot be stopped from another thread"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|int
name|id
decl|,
name|d
operator|->
name|timerIdToObject
operator|.
name|keys
argument_list|()
control|)
block|{
if|if
condition|(
name|d
operator|->
name|timerIdToObject
operator|.
name|value
argument_list|(
name|id
argument_list|)
operator|==
name|object
condition|)
name|unregisterTimer
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|registeredTimers
name|QList
argument_list|<
name|QAbstractEventDispatcher
operator|::
name|TimerInfo
argument_list|>
name|QEventDispatcherWinRT
operator|::
name|registeredTimers
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|object
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT:registeredTimers: invalid argument"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|QList
argument_list|<
name|TimerInfo
argument_list|>
argument_list|()
return|;
block|}
name|Q_D
argument_list|(
specifier|const
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|TimerInfo
argument_list|>
name|timerInfos
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|WinRTTimerInfo
modifier|&
name|info
decl|,
name|d
operator|->
name|timerInfos
control|)
block|{
if|if
condition|(
name|info
operator|.
name|object
operator|==
name|object
operator|&&
name|info
operator|.
name|timerId
operator|!=
name|INVALID_TIMER_ID
condition|)
name|timerInfos
operator|.
name|append
argument_list|(
name|info
argument_list|)
expr_stmt|;
block|}
return|return
name|timerInfos
return|;
block|}
end_function
begin_function
DECL|function|registerEventNotifier
name|bool
name|QEventDispatcherWinRT
operator|::
name|registerEventNotifier
parameter_list|(
name|QWinEventNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|unregisterEventNotifier
name|void
name|QEventDispatcherWinRT
operator|::
name|unregisterEventNotifier
parameter_list|(
name|QWinEventNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|remainingTime
name|int
name|QEventDispatcherWinRT
operator|::
name|remainingTime
parameter_list|(
name|int
name|timerId
parameter_list|)
block|{
if|if
condition|(
name|timerId
operator|<
literal|1
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::remainingTime: invalid argument"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|-
literal|1
return|;
block|}
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
specifier|const
name|WinRTTimerInfo
name|timerInfo
init|=
name|d
operator|->
name|timerInfos
operator|.
name|at
argument_list|(
name|timerId
argument_list|)
decl_stmt|;
if|if
condition|(
name|timerInfo
operator|.
name|timerId
operator|==
name|INVALID_TIMER_ID
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
name|qWarning
argument_list|(
literal|"QEventDispatcherWinRT::remainingTime: timer id %d not found"
argument_list|,
name|timerId
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|-
literal|1
return|;
block|}
specifier|const
name|quint64
name|currentTime
init|=
name|qt_msectime
argument_list|()
decl_stmt|;
if|if
condition|(
name|currentTime
operator|<
name|timerInfo
operator|.
name|targetTime
condition|)
block|{
comment|// time to wait
return|return
name|timerInfo
operator|.
name|targetTime
operator|-
name|currentTime
return|;
block|}
else|else
block|{
return|return
literal|0
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|wakeUp
name|void
name|QEventDispatcherWinRT
operator|::
name|wakeUp
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|interrupt
name|void
name|QEventDispatcherWinRT
operator|::
name|interrupt
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
name|SetEvent
argument_list|(
name|d
operator|->
name|timerIdToHandle
operator|.
name|value
argument_list|(
name|INTERRUPT_HANDLE
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QEventDispatcherWinRT
operator|::
name|flush
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|startingUp
name|void
name|QEventDispatcherWinRT
operator|::
name|startingUp
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|closingDown
name|void
name|QEventDispatcherWinRT
operator|::
name|closingDown
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|event
name|bool
name|QEventDispatcherWinRT
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventDispatcherWinRT
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|Timer
case|:
block|{
name|QTimerEvent
modifier|*
name|timerEvent
init|=
cast|static_cast
argument_list|<
name|QTimerEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
specifier|const
name|int
name|id
init|=
name|timerEvent
operator|->
name|timerId
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|id
operator|<
name|d
operator|->
name|timerInfos
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|WinRTTimerInfo
modifier|&
name|info
init|=
name|d
operator|->
name|timerInfos
index|[
name|id
index|]
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|info
operator|.
name|timerId
operator|!=
name|INVALID_TIMER_ID
argument_list|)
expr_stmt|;
if|if
condition|(
name|info
operator|.
name|inEvent
condition|)
comment|// but don't allow event to recurse
break|break;
name|info
operator|.
name|inEvent
operator|=
literal|true
expr_stmt|;
name|QTimerEvent
name|te
argument_list|(
name|id
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|d
operator|->
name|timerIdToObject
operator|.
name|value
argument_list|(
name|id
argument_list|)
argument_list|,
operator|&
name|te
argument_list|)
expr_stmt|;
comment|// The timer might have been removed in the meanwhile
if|if
condition|(
name|id
operator|>=
name|d
operator|->
name|timerInfos
operator|.
name|size
argument_list|()
condition|)
break|break;
name|info
operator|=
name|d
operator|->
name|timerInfos
index|[
name|id
index|]
expr_stmt|;
if|if
condition|(
name|info
operator|.
name|timerId
operator|==
name|INVALID_TIMER_ID
condition|)
break|break;
if|if
condition|(
name|info
operator|.
name|interval
operator|==
literal|0
operator|&&
name|info
operator|.
name|inEvent
condition|)
block|{
comment|// post the next zero timer event as long as the timer was not restarted
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QTimerEvent
argument_list|(
name|id
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|info
operator|.
name|inEvent
operator|=
literal|false
expr_stmt|;
block|}
default|default:
break|break;
block|}
return|return
name|QAbstractEventDispatcher
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QEventDispatcherWinRTPrivate
name|QEventDispatcherWinRTPrivate
operator|::
name|QEventDispatcherWinRTPrivate
parameter_list|()
block|{
specifier|const
name|bool
name|isGuiThread
init|=
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|&&
name|QThread
operator|::
name|currentThread
argument_list|()
operator|==
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|thread
argument_list|()
decl_stmt|;
name|CoInitializeEx
argument_list|(
name|NULL
argument_list|,
name|isGuiThread
condition|?
name|COINIT_APARTMENTTHREADED
else|:
name|COINIT_MULTITHREADED
argument_list|)
expr_stmt|;
name|HANDLE
name|interruptHandle
init|=
name|CreateEventEx
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|SYNCHRONIZE
operator||
name|EVENT_MODIFY_STATE
argument_list|)
decl_stmt|;
name|timerIdToHandle
operator|.
name|insert
argument_list|(
name|INTERRUPT_HANDLE
argument_list|,
name|interruptHandle
argument_list|)
expr_stmt|;
name|timerHandleToId
operator|.
name|insert
argument_list|(
name|interruptHandle
argument_list|,
name|INTERRUPT_HANDLE
argument_list|)
expr_stmt|;
name|timerInfos
operator|.
name|reserve
argument_list|(
literal|256
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEventDispatcherWinRTPrivate
name|QEventDispatcherWinRTPrivate
operator|::
name|~
name|QEventDispatcherWinRTPrivate
parameter_list|()
block|{
name|CloseHandle
argument_list|(
name|timerIdToHandle
operator|.
name|value
argument_list|(
name|INTERRUPT_HANDLE
argument_list|)
argument_list|)
expr_stmt|;
name|CoUninitialize
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
