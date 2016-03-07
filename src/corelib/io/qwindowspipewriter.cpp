begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowspipewriter_p.h"
end_include
begin_include
include|#
directive|include
file|"qiodevice_p.h"
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|bool
name|qt_cancelIo
parameter_list|(
name|HANDLE
name|handle
parameter_list|,
name|OVERLAPPED
modifier|*
name|overlapped
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// from qwindowspipereader.cpp
end_comment
begin_constructor
DECL|function|Overlapped
name|QWindowsPipeWriter
operator|::
name|Overlapped
operator|::
name|Overlapped
parameter_list|(
name|QWindowsPipeWriter
modifier|*
name|pipeWriter
parameter_list|)
member_init_list|:
name|pipeWriter
argument_list|(
name|pipeWriter
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|clear
name|void
name|QWindowsPipeWriter
operator|::
name|Overlapped
operator|::
name|clear
parameter_list|()
block|{
name|ZeroMemory
argument_list|(
name|this
argument_list|,
sizeof|sizeof
argument_list|(
name|OVERLAPPED
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QWindowsPipeWriter
name|QWindowsPipeWriter
operator|::
name|QWindowsPipeWriter
parameter_list|(
name|HANDLE
name|pipeWriteEnd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|handle
argument_list|(
name|pipeWriteEnd
argument_list|)
member_init_list|,
name|overlapped
argument_list|(
name|this
argument_list|)
member_init_list|,
name|numberOfBytesToWrite
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|pendingBytesWrittenValue
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|stopped
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|writeSequenceStarted
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|notifiedCalled
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|bytesWrittenPending
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|inBytesWritten
argument_list|(
literal|false
argument_list|)
block|{
name|connect
argument_list|(
name|this
argument_list|,
operator|&
name|QWindowsPipeWriter
operator|::
name|_q_queueBytesWritten
argument_list|,
name|this
argument_list|,
operator|&
name|QWindowsPipeWriter
operator|::
name|emitPendingBytesWrittenValue
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsPipeWriter
name|QWindowsPipeWriter
operator|::
name|~
name|QWindowsPipeWriter
parameter_list|()
block|{
name|stop
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|waitForWrite
name|bool
name|QWindowsPipeWriter
operator|::
name|waitForWrite
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
if|if
condition|(
operator|!
name|writeSequenceStarted
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|bytesWrittenPending
condition|)
block|{
if|if
condition|(
operator|!
name|inBytesWritten
condition|)
name|emitPendingBytesWrittenValue
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
operator|!
name|waitForNotification
argument_list|(
name|msecs
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|bytesWrittenPending
condition|)
block|{
if|if
condition|(
operator|!
name|inBytesWritten
condition|)
name|emitPendingBytesWrittenValue
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
DECL|function|bytesToWrite
name|qint64
name|QWindowsPipeWriter
operator|::
name|bytesToWrite
parameter_list|()
specifier|const
block|{
return|return
name|numberOfBytesToWrite
return|;
block|}
end_function
begin_function
DECL|function|emitPendingBytesWrittenValue
name|void
name|QWindowsPipeWriter
operator|::
name|emitPendingBytesWrittenValue
parameter_list|()
block|{
if|if
condition|(
name|bytesWrittenPending
condition|)
block|{
name|bytesWrittenPending
operator|=
literal|false
expr_stmt|;
specifier|const
name|qint64
name|bytes
init|=
name|pendingBytesWrittenValue
decl_stmt|;
name|pendingBytesWrittenValue
operator|=
literal|0
expr_stmt|;
name|inBytesWritten
operator|=
literal|true
expr_stmt|;
emit|emit
name|bytesWritten
argument_list|(
name|bytes
argument_list|)
emit|;
name|inBytesWritten
operator|=
literal|false
expr_stmt|;
emit|emit
name|canWrite
argument_list|()
emit|;
block|}
block|}
end_function
begin_function
DECL|function|writeFileCompleted
name|void
name|QWindowsPipeWriter
operator|::
name|writeFileCompleted
parameter_list|(
name|DWORD
name|errorCode
parameter_list|,
name|DWORD
name|numberOfBytesTransfered
parameter_list|,
name|OVERLAPPED
modifier|*
name|overlappedBase
parameter_list|)
block|{
name|Overlapped
modifier|*
name|overlapped
init|=
cast|static_cast
argument_list|<
name|Overlapped
operator|*
argument_list|>
argument_list|(
name|overlappedBase
argument_list|)
decl_stmt|;
name|overlapped
operator|->
name|pipeWriter
operator|->
name|notified
argument_list|(
name|errorCode
argument_list|,
name|numberOfBytesTransfered
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal     Will be called whenever the write operation completes.  */
end_comment
begin_function
DECL|function|notified
name|void
name|QWindowsPipeWriter
operator|::
name|notified
parameter_list|(
name|DWORD
name|errorCode
parameter_list|,
name|DWORD
name|numberOfBytesWritten
parameter_list|)
block|{
name|notifiedCalled
operator|=
literal|true
expr_stmt|;
name|writeSequenceStarted
operator|=
literal|false
expr_stmt|;
name|numberOfBytesToWrite
operator|=
literal|0
expr_stmt|;
switch|switch
condition|(
name|errorCode
condition|)
block|{
case|case
name|ERROR_SUCCESS
case|:
break|break;
case|case
name|ERROR_OPERATION_ABORTED
case|:
if|if
condition|(
name|stopped
condition|)
break|break;
comment|// fall through
default|default:
name|qErrnoWarning
argument_list|(
name|errorCode
argument_list|,
literal|"QWindowsPipeWriter: asynchronous write failed."
argument_list|)
expr_stmt|;
break|break;
block|}
comment|// After the writer was stopped, the only reason why this function can be called is the
comment|// completion of a cancellation. No signals should be emitted, and no new write sequence should
comment|// be started in this case.
if|if
condition|(
name|stopped
condition|)
return|return;
name|pendingBytesWrittenValue
operator|+=
name|qint64
argument_list|(
name|numberOfBytesWritten
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|bytesWrittenPending
condition|)
block|{
name|bytesWrittenPending
operator|=
literal|true
expr_stmt|;
emit|emit
name|_q_queueBytesWritten
argument_list|(
name|QWindowsPipeWriter
operator|::
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|waitForNotification
name|bool
name|QWindowsPipeWriter
operator|::
name|waitForNotification
parameter_list|(
name|int
name|timeout
parameter_list|)
block|{
name|QElapsedTimer
name|t
decl_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
name|notifiedCalled
operator|=
literal|false
expr_stmt|;
name|int
name|msecs
init|=
name|timeout
decl_stmt|;
while|while
condition|(
name|SleepEx
argument_list|(
name|msecs
operator|==
operator|-
literal|1
condition|?
name|INFINITE
else|:
name|msecs
argument_list|,
name|TRUE
argument_list|)
operator|==
name|WAIT_IO_COMPLETION
condition|)
block|{
if|if
condition|(
name|notifiedCalled
condition|)
return|return
literal|true
return|;
comment|// Some other I/O completion routine was called. Wait some more.
name|msecs
operator|=
name|qt_subtract_from_timeout
argument_list|(
name|timeout
argument_list|,
name|t
operator|.
name|elapsed
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|msecs
condition|)
break|break;
block|}
return|return
name|notifiedCalled
return|;
block|}
end_function
begin_function
DECL|function|write
name|qint64
name|QWindowsPipeWriter
operator|::
name|write
parameter_list|(
specifier|const
name|char
modifier|*
name|ptr
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
block|{
if|if
condition|(
name|writeSequenceStarted
condition|)
return|return
literal|0
return|;
name|overlapped
operator|.
name|clear
argument_list|()
expr_stmt|;
name|numberOfBytesToWrite
operator|=
name|maxlen
expr_stmt|;
name|stopped
operator|=
literal|false
expr_stmt|;
name|writeSequenceStarted
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|WriteFileEx
argument_list|(
name|handle
argument_list|,
name|ptr
argument_list|,
name|maxlen
argument_list|,
operator|&
name|overlapped
argument_list|,
operator|&
name|writeFileCompleted
argument_list|)
condition|)
block|{
name|writeSequenceStarted
operator|=
literal|false
expr_stmt|;
name|qErrnoWarning
argument_list|(
literal|"QWindowsPipeWriter::write failed."
argument_list|)
expr_stmt|;
block|}
return|return
name|maxlen
return|;
block|}
end_function
begin_function
DECL|function|stop
name|void
name|QWindowsPipeWriter
operator|::
name|stop
parameter_list|()
block|{
name|stopped
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|writeSequenceStarted
condition|)
block|{
if|if
condition|(
operator|!
name|qt_cancelIo
argument_list|(
name|handle
argument_list|,
operator|&
name|overlapped
argument_list|)
condition|)
block|{
specifier|const
name|DWORD
name|dwError
init|=
name|GetLastError
argument_list|()
decl_stmt|;
if|if
condition|(
name|dwError
operator|!=
name|ERROR_NOT_FOUND
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|dwError
argument_list|,
literal|"QWindowsPipeWriter: qt_cancelIo on handle %x failed."
argument_list|,
name|handle
argument_list|)
expr_stmt|;
block|}
block|}
name|waitForNotification
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
