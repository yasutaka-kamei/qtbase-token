begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSPIPEWRITER_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSPIPEWRITER_P_H
define|#
directive|define
name|QWINDOWSPIPEWRITER_P_H
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
file|<qelapsedtimer.h>
end_include
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|SLEEPMIN
define|#
directive|define
name|SLEEPMIN
value|10
DECL|macro|SLEEPMAX
define|#
directive|define
name|SLEEPMAX
value|500
name|class
name|QIncrementalSleepTimer
block|{
name|public
label|:
name|QIncrementalSleepTimer
argument_list|(
argument|int msecs
argument_list|)
block|:
name|totalTimeOut
argument_list|(
name|msecs
argument_list|)
operator|,
name|nextSleep
argument_list|(
argument|qMin(SLEEPMIN, totalTimeOut)
argument_list|)
block|{
if|if
condition|(
name|totalTimeOut
operator|==
operator|-
literal|1
condition|)
name|nextSleep
operator|=
name|SLEEPMIN
expr_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_function
name|int
name|nextSleepTime
parameter_list|()
block|{
name|int
name|tmp
init|=
name|nextSleep
decl_stmt|;
name|nextSleep
operator|=
name|qMin
argument_list|(
name|nextSleep
operator|*
literal|2
argument_list|,
name|qMin
argument_list|(
name|SLEEPMAX
argument_list|,
name|timeLeft
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function
begin_expr_stmt
name|int
name|timeLeft
argument_list|()
specifier|const
block|{
if|if
condition|(
name|totalTimeOut
operator|==
operator|-
literal|1
condition|)
return|return
name|SLEEPMAX
return|;
end_expr_stmt
begin_return
return|return
name|qMax
argument_list|(
name|int
argument_list|(
name|totalTimeOut
operator|-
name|timer
operator|.
name|elapsed
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|)
return|;
end_return
begin_macro
unit|}      bool
name|hasTimedOut
argument_list|()
end_macro
begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|totalTimeOut
operator|==
operator|-
literal|1
condition|)
return|return
name|false
return|;
end_expr_stmt
begin_return
return|return
name|timer
operator|.
name|elapsed
argument_list|()
operator|>=
name|totalTimeOut
return|;
end_return
begin_macro
unit|}      void
name|resetIncrements
argument_list|()
end_macro
begin_block
block|{
name|nextSleep
operator|=
name|qMin
argument_list|(
name|SLEEPMIN
argument_list|,
name|timeLeft
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_block
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QElapsedTimer
name|timer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|totalTimeOut
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|nextSleep
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_CORE_EXPORT
name|QWindowsPipeWriter
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QWindowsPipeWriter
argument_list|(
argument|HANDLE pipeWriteEnd
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
operator|~
name|QWindowsPipeWriter
argument_list|()
block|;
name|qint64
name|write
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|void
name|stop
argument_list|()
block|;
name|bool
name|waitForWrite
argument_list|(
argument|int msecs
argument_list|)
block|;
name|bool
name|isWriteOperationActive
argument_list|()
specifier|const
block|{
return|return
name|writeSequenceStarted
return|;
block|}
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|canWrite
argument_list|()
block|;
name|void
name|bytesWritten
argument_list|(
argument|qint64 bytes
argument_list|)
block|;
name|void
name|_q_queueBytesWritten
argument_list|(
name|QPrivateSignal
argument_list|)
block|;
name|private
operator|:
specifier|static
name|void
name|CALLBACK
name|writeFileCompleted
argument_list|(
argument|DWORD errorCode
argument_list|,
argument|DWORD numberOfBytesTransfered
argument_list|,
argument|OVERLAPPED *overlappedBase
argument_list|)
block|;
name|void
name|notified
argument_list|(
argument|DWORD errorCode
argument_list|,
argument|DWORD numberOfBytesWritten
argument_list|)
block|;
name|bool
name|waitForNotification
argument_list|(
argument|int timeout
argument_list|)
block|;
name|void
name|emitPendingBytesWrittenValue
argument_list|()
block|;
name|class
name|Overlapped
operator|:
name|public
name|OVERLAPPED
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|Overlapped
argument_list|)
name|public
operator|:
name|explicit
name|Overlapped
argument_list|(
name|QWindowsPipeWriter
operator|*
name|pipeWriter
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|QWindowsPipeWriter
operator|*
name|pipeWriter
block|;     }
block|;
name|HANDLE
name|handle
block|;
name|Overlapped
name|overlapped
block|;
name|qint64
name|numberOfBytesToWrite
block|;
name|qint64
name|pendingBytesWrittenValue
block|;
name|bool
name|stopped
block|;
name|bool
name|writeSequenceStarted
block|;
name|bool
name|notifiedCalled
block|;
name|bool
name|bytesWrittenPending
block|;
name|bool
name|inBytesWritten
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
comment|// QT_NO_PROCESS
end_comment
end_unit
