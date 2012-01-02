begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Copyright (c) 2007-2008, Apple, Inc. ** ** All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are met: ** **   * Redistributions of source code must retain the above copyright notice, **     this list of conditions and the following disclaimer. ** **   * Redistributions in binary form must reproduce the above copyright notice, **     this list of conditions and the following disclaimer in the documentation **     and/or other materials provided with the distribution. ** **   * Neither the name of Apple, Inc. nor the names of its contributors **     may be used to endorse or promote products derived from this software **     without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR ** CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, ** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, ** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR ** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF ** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING ** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS ** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTDISPATCHER_MAC_P_H
end_ifndef
begin_define
DECL|macro|QEVENTDISPATCHER_MAC_P_H
define|#
directive|define
name|QEVENTDISPATCHER_MAC_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|<QtCore/qabstracteventdispatcher.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstack.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qabstracteventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<CoreFoundation/CoreFoundation.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|NSModalSession
typedef|typedef
name|struct
name|_NSModalSession
modifier|*
name|NSModalSession
typedef|;
end_typedef
begin_typedef
DECL|struct|_QCocoaModalSessionInfo
typedef|typedef
struct|struct
name|_QCocoaModalSessionInfo
block|{
DECL|member|window
name|QPointer
operator|<
name|QWindow
operator|>
name|window
expr_stmt|;
DECL|member|session
name|NSModalSession
name|session
decl_stmt|;
DECL|member|nswindow
name|void
modifier|*
name|nswindow
decl_stmt|;
block|}
DECL|typedef|QCocoaModalSessionInfo
name|QCocoaModalSessionInfo
typedef|;
end_typedef
begin_decl_stmt
DECL|variable|QCocoaEventDispatcherPrivate
name|class
name|QCocoaEventDispatcherPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaEventDispatcher
range|:
name|public
name|QAbstractEventDispatcher
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QCocoaEventDispatcher
argument_list|)
name|public
operator|:
name|QCocoaEventDispatcher
argument_list|(
name|QAbstractEventDispatcherPrivate
operator|&
name|priv
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QCocoaEventDispatcher
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QCocoaEventDispatcher
argument_list|()
block|;
name|bool
name|processEvents
argument_list|(
argument|QEventLoop::ProcessEventsFlags flags
argument_list|)
block|;
name|bool
name|hasPendingEvents
argument_list|()
block|;
name|void
name|registerSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|unregisterSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|registerTimer
argument_list|(
argument|int timerId
argument_list|,
argument|int interval
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|QObject *object
argument_list|)
block|;
name|bool
name|unregisterTimer
argument_list|(
argument|int timerId
argument_list|)
block|;
name|bool
name|unregisterTimers
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|QList
operator|<
name|TimerInfo
operator|>
name|registeredTimers
argument_list|(
argument|QObject *object
argument_list|)
specifier|const
block|;
name|void
name|wakeUp
argument_list|()
block|;
name|void
name|interrupt
argument_list|()
block|;
name|void
name|flush
argument_list|()
block|;
name|private
operator|:
comment|//friend void qt_mac_select_timer_callbk(__EventLoopTimer*, void*);
name|friend
name|class
name|QApplicationPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|MacTimerInfo
struct|struct
name|MacTimerInfo
block|{
DECL|member|id
name|int
name|id
decl_stmt|;
DECL|member|interval
name|int
name|interval
decl_stmt|;
DECL|member|timerType
name|Qt
operator|::
name|TimerType
name|timerType
expr_stmt|;
DECL|member|obj
name|QObject
modifier|*
name|obj
decl_stmt|;
DECL|member|pending
name|bool
name|pending
decl_stmt|;
DECL|member|runLoopTimer
name|CFRunLoopTimerRef
name|runLoopTimer
decl_stmt|;
DECL|function|operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MacTimerInfo
operator|&
name|other
operator|)
block|{
return|return
operator|(
name|id
operator|==
name|other
operator|.
name|id
operator|)
return|;
block|}
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|MacTimerHash
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|MacTimerInfo
operator|*
operator|>
name|MacTimerHash
expr_stmt|;
end_typedef
begin_struct
DECL|struct|MacSocketInfo
struct|struct
name|MacSocketInfo
block|{
DECL|function|MacSocketInfo
name|MacSocketInfo
argument_list|()
operator|:
name|socket
argument_list|(
literal|0
argument_list|)
operator|,
name|runloop
argument_list|(
literal|0
argument_list|)
operator|,
name|readNotifier
argument_list|(
literal|0
argument_list|)
operator|,
name|writeNotifier
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|socket
name|CFSocketRef
name|socket
expr_stmt|;
DECL|member|runloop
name|CFRunLoopSourceRef
name|runloop
decl_stmt|;
DECL|member|readNotifier
name|QObject
modifier|*
name|readNotifier
decl_stmt|;
DECL|member|writeNotifier
name|QObject
modifier|*
name|writeNotifier
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|MacSocketHash
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|MacSocketInfo
operator|*
operator|>
name|MacSocketHash
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QCocoaEventDispatcherPrivate
range|:
name|public
name|QAbstractEventDispatcherPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QCocoaEventDispatcher
argument_list|)
name|public
operator|:
name|QCocoaEventDispatcherPrivate
argument_list|()
block|;
specifier|static
name|MacTimerHash
name|macTimerHash
block|;
comment|// Set 'blockSendPostedEvents' to true if you _really_ need
comment|// to make sure that qt events are not posted while calling
comment|// low-level cocoa functions (like beginModalForWindow). And
comment|// use a QBoolBlocker to be safe:
specifier|static
name|bool
name|blockSendPostedEvents
block|;
comment|// The following variables help organizing modal sessions:
specifier|static
name|QStack
operator|<
name|QCocoaModalSessionInfo
operator|>
name|cocoaModalSessionStack
block|;
specifier|static
name|bool
name|currentExecIsNSAppRun
block|;
specifier|static
name|bool
name|nsAppRunCalledByQt
block|;
specifier|static
name|bool
name|cleanupModalSessionsNeeded
block|;
specifier|static
name|NSModalSession
name|currentModalSessionCached
block|;
specifier|static
name|NSModalSession
name|currentModalSession
argument_list|()
block|;
specifier|static
name|void
name|updateChildrenWorksWhenModal
argument_list|()
block|;
specifier|static
name|void
name|temporarilyStopAllModalSessions
argument_list|()
block|;
specifier|static
name|void
name|beginModalSession
argument_list|(
name|QWindow
operator|*
name|widget
argument_list|)
block|;
specifier|static
name|void
name|endModalSession
argument_list|(
name|QWindow
operator|*
name|widget
argument_list|)
block|;
specifier|static
name|void
name|cancelWaitForMoreEvents
argument_list|()
block|;
specifier|static
name|void
name|cleanupModalSessions
argument_list|()
block|;
specifier|static
name|void
name|ensureNSAppInitialized
argument_list|()
block|;
name|MacSocketHash
name|macSockets
block|;
name|QList
operator|<
name|void
operator|*
operator|>
name|queuedUserInputEvents
block|;
comment|// NSEvent *
name|CFRunLoopSourceRef
name|postedEventsSource
block|;
name|CFRunLoopObserverRef
name|waitingObserver
block|;
name|CFRunLoopObserverRef
name|firstTimeObserver
block|;
name|QAtomicInt
name|serialNumber
block|;
name|int
name|lastSerial
block|;
specifier|static
name|bool
name|interrupt
block|;
name|private
operator|:
specifier|static
name|Boolean
name|postedEventSourceEqualCallback
argument_list|(
specifier|const
name|void
operator|*
name|info1
argument_list|,
specifier|const
name|void
operator|*
name|info2
argument_list|)
block|;
specifier|static
name|void
name|postedEventsSourcePerformCallback
argument_list|(
name|void
operator|*
name|info
argument_list|)
block|;
specifier|static
name|void
name|activateTimer
argument_list|(
name|CFRunLoopTimerRef
argument_list|,
name|void
operator|*
name|info
argument_list|)
block|;
specifier|static
name|void
name|waitingObserverCallback
argument_list|(
argument|CFRunLoopObserverRef observer
argument_list|,
argument|CFRunLoopActivity activity
argument_list|,
argument|void *info
argument_list|)
block|;
specifier|static
name|void
name|firstLoopEntry
argument_list|(
argument|CFRunLoopObserverRef ref
argument_list|,
argument|CFRunLoopActivity activity
argument_list|,
argument|void *info
argument_list|)
block|;
name|friend
name|void
name|processPostedEvents
argument_list|(
argument|QCocoaEventDispatcherPrivate *const d
argument_list|,
argument|const bool blockSendPostedEvents
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QtCocoaInterruptDispatcher
range|:
name|public
name|QObject
block|{
specifier|static
name|QtCocoaInterruptDispatcher
operator|*
name|instance
block|;
name|bool
name|cancelled
block|;
name|QtCocoaInterruptDispatcher
argument_list|()
block|;
operator|~
name|QtCocoaInterruptDispatcher
argument_list|()
block|;
name|public
operator|:
specifier|static
name|void
name|interruptLater
argument_list|()
block|;
specifier|static
name|void
name|cancelInterruptLater
argument_list|()
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
comment|// QEVENTDISPATCHER_MAC_P_H
end_comment
end_unit
