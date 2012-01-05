begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUTUREINTERFACE_P_H
end_ifndef
begin_define
DECL|macro|QFUTUREINTERFACE_P_H
define|#
directive|define
name|QFUTUREINTERFACE_P_H
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
file|<QtCore/qelapsedtimer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qwaitcondition.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrunnable.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFutureCallOutEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
expr|enum
name|CallOutType
block|{
name|Started
block|,
name|Finished
block|,
name|Canceled
block|,
name|Paused
block|,
name|Resumed
block|,
name|Progress
block|,
name|ProgressRange
block|,
name|ResultsReady
block|}
block|;
name|QFutureCallOutEvent
argument_list|()
operator|:
name|QEvent
argument_list|(
name|QEvent
operator|::
name|FutureCallOut
argument_list|)
block|,
name|callOutType
argument_list|(
name|CallOutType
argument_list|(
literal|0
argument_list|)
argument_list|)
block|,
name|index1
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|index2
argument_list|(
argument|-
literal|1
argument_list|)
block|{ }
name|QFutureCallOutEvent
argument_list|(
argument|CallOutType callOutType
argument_list|,
argument|int index1 = -
literal|1
argument_list|)
operator|:
name|QEvent
argument_list|(
name|QEvent
operator|::
name|FutureCallOut
argument_list|)
block|,
name|callOutType
argument_list|(
name|callOutType
argument_list|)
block|,
name|index1
argument_list|(
name|index1
argument_list|)
block|,
name|index2
argument_list|(
argument|-
literal|1
argument_list|)
block|{ }
name|QFutureCallOutEvent
argument_list|(
argument|CallOutType callOutType
argument_list|,
argument|int index1
argument_list|,
argument|int index2
argument_list|)
operator|:
name|QEvent
argument_list|(
name|QEvent
operator|::
name|FutureCallOut
argument_list|)
block|,
name|callOutType
argument_list|(
name|callOutType
argument_list|)
block|,
name|index1
argument_list|(
name|index1
argument_list|)
block|,
name|index2
argument_list|(
argument|index2
argument_list|)
block|{ }
name|QFutureCallOutEvent
argument_list|(
argument|CallOutType callOutType
argument_list|,
argument|int index1
argument_list|,
argument|const QString&text
argument_list|)
operator|:
name|QEvent
argument_list|(
name|QEvent
operator|::
name|FutureCallOut
argument_list|)
block|,
name|callOutType
argument_list|(
name|callOutType
argument_list|)
block|,
name|index1
argument_list|(
name|index1
argument_list|)
block|,
name|index2
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|text
argument_list|(
argument|text
argument_list|)
block|{ }
name|CallOutType
name|callOutType
block|;
name|int
name|index1
block|;
name|int
name|index2
block|;
name|QString
name|text
block|;
name|QFutureCallOutEvent
operator|*
name|clone
argument_list|()
specifier|const
block|{
return|return
name|new
name|QFutureCallOutEvent
argument_list|(
name|callOutType
argument_list|,
name|index1
argument_list|,
name|index2
argument_list|,
name|text
argument_list|)
return|;
block|}
name|private
operator|:
name|QFutureCallOutEvent
argument_list|(
argument|CallOutType callOutType
argument_list|,
argument|int index1
argument_list|,
argument|int index2
argument_list|,
argument|const QString&text
argument_list|)
operator|:
name|QEvent
argument_list|(
name|QEvent
operator|::
name|FutureCallOut
argument_list|)
block|,
name|callOutType
argument_list|(
name|callOutType
argument_list|)
block|,
name|index1
argument_list|(
name|index1
argument_list|)
block|,
name|index2
argument_list|(
name|index2
argument_list|)
block|,
name|text
argument_list|(
argument|text
argument_list|)
block|{ }
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFutureCallOutInterface
block|{
name|public
label|:
name|virtual
operator|~
name|QFutureCallOutInterface
argument_list|()
block|{}
name|virtual
name|void
name|postCallOutEvent
argument_list|(
specifier|const
name|QFutureCallOutEvent
operator|&
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|callOutInterfaceDisconnected
parameter_list|()
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QFutureInterfaceBasePrivate
block|{
name|public
label|:
name|QFutureInterfaceBasePrivate
argument_list|(
argument|QFutureInterfaceBase::State initialState
argument_list|)
empty_stmt|;
name|QAtomicInt
name|refCount
decl_stmt|;
name|mutable
name|QMutex
name|m_mutex
decl_stmt|;
name|QWaitCondition
name|waitCondition
decl_stmt|;
name|QList
operator|<
name|QFutureCallOutInterface
operator|*
operator|>
name|outputConnections
expr_stmt|;
name|int
name|m_progressValue
decl_stmt|;
name|int
name|m_progressMinimum
decl_stmt|;
name|int
name|m_progressMaximum
decl_stmt|;
name|QFutureInterfaceBase
operator|::
name|State
name|state
expr_stmt|;
name|QElapsedTimer
name|progressTime
decl_stmt|;
name|QWaitCondition
name|pausedWaitCondition
decl_stmt|;
name|int
name|pendingResults
decl_stmt|;
name|QtConcurrent
operator|::
name|ResultStoreBase
name|m_results
expr_stmt|;
name|bool
name|manualProgress
decl_stmt|;
name|int
name|m_expectedResultCount
decl_stmt|;
name|QtConcurrent
operator|::
name|internal
operator|::
name|ExceptionStore
name|m_exceptionStore
expr_stmt|;
name|QString
name|m_progressText
decl_stmt|;
name|QRunnable
modifier|*
name|runnable
decl_stmt|;
comment|// Internal functions that does not change the mutex state.
comment|// The mutex must be locked when calling these.
name|int
name|internal_resultCount
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|internal_isResultReadyAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|bool
name|internal_waitForNextResult
parameter_list|()
function_decl|;
name|bool
name|internal_updateProgress
parameter_list|(
name|int
name|progress
parameter_list|,
specifier|const
name|QString
modifier|&
name|progressText
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|void
name|internal_setThrottled
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|void
name|sendCallOut
parameter_list|(
specifier|const
name|QFutureCallOutEvent
modifier|&
name|callOut
parameter_list|)
function_decl|;
name|void
name|sendCallOuts
parameter_list|(
specifier|const
name|QFutureCallOutEvent
modifier|&
name|callOut1
parameter_list|,
specifier|const
name|QFutureCallOutEvent
modifier|&
name|callOut2
parameter_list|)
function_decl|;
name|void
name|connectOutputInterface
parameter_list|(
name|QFutureCallOutInterface
modifier|*
name|iface
parameter_list|)
function_decl|;
name|void
name|disconnectOutputInterface
parameter_list|(
name|QFutureCallOutInterface
modifier|*
name|iface
parameter_list|)
function_decl|;
name|void
name|setState
argument_list|(
name|QFutureInterfaceBase
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
