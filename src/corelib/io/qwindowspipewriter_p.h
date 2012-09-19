begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qthread.h>
end_include
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qwaitcondition.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_THREAD
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
name|totalTimeOut
operator|-
name|timer
operator|.
name|elapsed
argument_list|()
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
name|QTime
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
name|QThread
block|{
name|Q_OBJECT
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
name|public
operator|:
name|explicit
name|QWindowsPipeWriter
argument_list|(
argument|HANDLE writePipe
argument_list|,
argument|QObject * parent =
literal|0
argument_list|)
block|;
operator|~
name|QWindowsPipeWriter
argument_list|()
block|;
name|bool
name|waitForWrite
argument_list|(
argument|int msecs
argument_list|)
block|;
name|qint64
name|write
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|lock
argument_list|)
block|;
return|return
name|data
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|hadWritten
argument_list|()
specifier|const
block|{
return|return
name|hasWritten
return|;
block|}
name|protected
operator|:
name|void
name|run
argument_list|()
block|;
name|private
operator|:
name|QByteArray
name|data
block|;
name|QWaitCondition
name|waitCondition
block|;
name|mutable
name|QMutex
name|lock
block|;
name|HANDLE
name|writePipe
block|;
specifier|volatile
name|bool
name|quitNow
block|;
name|bool
name|hasWritten
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_THREAD
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROCESS
end_comment
end_unit
