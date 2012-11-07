begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Copyright (c) 2007-2008, Apple, Inc. ** ** All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are met: ** **   * Redistributions of source code must retain the above copyright notice, **     this list of conditions and the following disclaimer. ** **   * Redistributions in binary form must reproduce the above copyright notice, **     this list of conditions and the following disclaimer in the documentation **     and/or other materials provided with the distribution. ** **   * Neither the name of Apple, Inc. nor the names of its contributors **     may be used to endorse or promote products derived from this software **     without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR ** CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, ** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, ** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR ** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF ** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING ** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS ** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTDISPATCHER_IOS_P_H
end_ifndef
begin_define
DECL|macro|QEVENTDISPATCHER_IOS_P_H
define|#
directive|define
name|QEVENTDISPATCHER_IOS_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstracteventdispatcher.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qtimerinfo_unix_p.h>
end_include
begin_include
include|#
directive|include
file|<CoreFoundation/CoreFoundation.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QIOSEventDispatcher
range|:
name|public
name|QAbstractEventDispatcher
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QIOSEventDispatcher
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QIOSEventDispatcher
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
name|QAbstractEventDispatcher
operator|::
name|TimerInfo
operator|>
name|registeredTimers
argument_list|(
argument|QObject *object
argument_list|)
specifier|const
block|;
name|int
name|remainingTime
argument_list|(
argument|int timerId
argument_list|)
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
name|bool
name|m_interrupted
block|;
name|CFRunLoopSourceRef
name|m_postedEventsRunLoopSource
block|;
name|CFRunLoopSourceRef
name|m_blockingTimerRunLoopSource
block|;
name|QTimerInfoList
name|m_timerInfoList
block|;
name|CFRunLoopTimerRef
name|m_runLoopTimerRef
block|;
name|void
name|processPostedEvents
argument_list|()
block|;
name|void
name|maybeStartCFRunLoopTimer
argument_list|()
block|;
name|void
name|maybeStopCFRunLoopTimer
argument_list|()
block|;
specifier|static
name|void
name|postedEventsRunLoopCallback
argument_list|(
name|void
operator|*
name|info
argument_list|)
block|;
specifier|static
name|void
name|nonBlockingTimerRunLoopCallback
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
name|blockingTimerRunLoopCallback
argument_list|(
name|void
operator|*
name|info
argument_list|)
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
comment|// QEVENTDISPATCHER_IOS_P_H
end_comment
end_unit
