begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUTUREWATCHER_H
end_ifndef
begin_define
DECL|macro|QFUTUREWATCHER_H
define|#
directive|define
name|QFUTUREWATCHER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qfuture.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QFUTURE
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QEvent
name|class
name|QEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFutureWatcherBasePrivate
name|class
name|QFutureWatcherBasePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QFutureWatcherBase
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFutureWatcherBase
argument_list|)
name|public
operator|:
name|explicit
name|QFutureWatcherBase
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
comment|// de-inline dtor
name|int
name|progressValue
argument_list|()
specifier|const
block|;
name|int
name|progressMinimum
argument_list|()
specifier|const
block|;
name|int
name|progressMaximum
argument_list|()
specifier|const
block|;
name|QString
name|progressText
argument_list|()
specifier|const
block|;
name|bool
name|isStarted
argument_list|()
specifier|const
block|;
name|bool
name|isFinished
argument_list|()
specifier|const
block|;
name|bool
name|isRunning
argument_list|()
specifier|const
block|;
name|bool
name|isCanceled
argument_list|()
specifier|const
block|;
name|bool
name|isPaused
argument_list|()
specifier|const
block|;
name|void
name|waitForFinished
argument_list|()
block|;
name|void
name|setPendingResultsLimit
argument_list|(
argument|int limit
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|started
argument_list|()
block|;
name|void
name|finished
argument_list|()
block|;
name|void
name|canceled
argument_list|()
block|;
name|void
name|paused
argument_list|()
block|;
name|void
name|resumed
argument_list|()
block|;
name|void
name|resultReadyAt
argument_list|(
argument|int resultIndex
argument_list|)
block|;
name|void
name|resultsReadyAt
argument_list|(
argument|int beginIndex
argument_list|,
argument|int endIndex
argument_list|)
block|;
name|void
name|progressRangeChanged
argument_list|(
argument|int minimum
argument_list|,
argument|int maximum
argument_list|)
block|;
name|void
name|progressValueChanged
argument_list|(
argument|int progressValue
argument_list|)
block|;
name|void
name|progressTextChanged
argument_list|(
specifier|const
name|QString
operator|&
name|progressText
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|cancel
argument_list|()
block|;
name|void
name|setPaused
argument_list|(
argument|bool paused
argument_list|)
block|;
name|void
name|pause
argument_list|()
block|;
name|void
name|resume
argument_list|()
block|;
name|void
name|togglePaused
argument_list|()
block|;
name|protected
operator|:
name|void
name|connectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
name|signal
argument_list|)
block|;
name|void
name|disconnectNotify
argument_list|(
specifier|const
name|QMetaMethod
operator|&
name|signal
argument_list|)
block|;
comment|// called from setFuture() implemented in template sub-classes
name|void
name|connectOutputInterface
argument_list|()
block|;
name|void
name|disconnectOutputInterface
argument_list|(
argument|bool pendingAssignment = false
argument_list|)
block|;
name|private
operator|:
comment|// implemented in the template sub-classes
name|virtual
specifier|const
name|QFutureInterfaceBase
operator|&
name|futureInterface
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QFutureInterfaceBase
operator|&
name|futureInterface
argument_list|()
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QFutureWatcher
operator|:
name|public
name|QFutureWatcherBase
block|{
name|public
operator|:
name|explicit
name|QFutureWatcher
argument_list|(
name|QObject
operator|*
name|_parent
operator|=
literal|0
argument_list|)
operator|:
name|QFutureWatcherBase
argument_list|(
argument|_parent
argument_list|)
block|{ }
operator|~
name|QFutureWatcher
argument_list|()
block|{
name|disconnectOutputInterface
argument_list|()
block|; }
name|void
name|setFuture
argument_list|(
specifier|const
name|QFuture
operator|<
name|T
operator|>
operator|&
name|future
argument_list|)
block|;
name|QFuture
operator|<
name|T
operator|>
name|future
argument_list|()
specifier|const
block|{
return|return
name|m_future
return|;
block|}
name|T
name|result
argument_list|()
specifier|const
block|{
return|return
name|m_future
operator|.
name|result
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|T
name|resultAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|m_future
operator|.
name|resultAt
argument_list|(
name|index
argument_list|)
return|;
block|}
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_QDOC
end_ifdef
begin_expr_stmt
name|int
name|progressValue
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|progressMinimum
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|progressMaximum
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|progressText
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isStarted
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isFinished
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isRunning
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isCanceled
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isPaused
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|waitForFinished
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setPendingResultsLimit
parameter_list|(
name|int
name|limit
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|Q_SIGNALS
label|:
end_label
begin_function_decl
name|void
name|started
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|finished
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|canceled
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|paused
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resumed
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resultReadyAt
parameter_list|(
name|int
name|resultIndex
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resultsReadyAt
parameter_list|(
name|int
name|beginIndex
parameter_list|,
name|int
name|endIndex
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|progressRangeChanged
parameter_list|(
name|int
name|minimum
parameter_list|,
name|int
name|maximum
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|progressValueChanged
parameter_list|(
name|int
name|progressValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|progressTextChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|progressText
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|public
name|Q_SLOTS
range|:
name|void
name|cancel
argument_list|()
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setPaused
parameter_list|(
name|bool
name|paused
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|pause
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resume
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|togglePaused
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QFuture
operator|<
name|T
operator|>
name|m_future
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QFutureInterfaceBase
operator|&
name|futureInterface
argument_list|()
specifier|const
block|{
return|return
name|m_future
operator|.
name|d
return|;
block|}
end_expr_stmt
begin_function
name|QFutureInterfaceBase
modifier|&
name|futureInterface
parameter_list|()
block|{
return|return
name|m_future
operator|.
name|d
return|;
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|void
name|QFutureWatcher
operator|<
name|T
operator|>
operator|::
name|setFuture
argument_list|(
argument|const QFuture<T>&_future
argument_list|)
block|{
if|if
condition|(
name|_future
operator|==
name|m_future
condition|)
return|return;
name|disconnectOutputInterface
argument_list|(
name|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_future
operator|=
name|_future
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|connectOutputInterface
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
operator|>
name|class
name|QFutureWatcher
operator|<
name|void
operator|>
operator|:
name|public
name|QFutureWatcherBase
block|{
name|public
operator|:
name|explicit
name|QFutureWatcher
argument_list|(
name|QObject
operator|*
name|_parent
operator|=
literal|0
argument_list|)
operator|:
name|QFutureWatcherBase
argument_list|(
argument|_parent
argument_list|)
block|{ }
operator|~
name|QFutureWatcher
argument_list|()
block|{
name|disconnectOutputInterface
argument_list|()
block|; }
name|void
name|setFuture
argument_list|(
specifier|const
name|QFuture
operator|<
name|void
operator|>
operator|&
name|future
argument_list|)
block|;
name|QFuture
operator|<
name|void
operator|>
name|future
argument_list|()
specifier|const
block|{
return|return
name|m_future
return|;
block|}
name|private
operator|:
name|QFuture
operator|<
name|void
operator|>
name|m_future
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QFutureInterfaceBase
operator|&
name|futureInterface
argument_list|()
specifier|const
block|{
return|return
name|m_future
operator|.
name|d
return|;
block|}
end_expr_stmt
begin_function
name|QFutureInterfaceBase
modifier|&
name|futureInterface
parameter_list|()
block|{
return|return
name|m_future
operator|.
name|d
return|;
block|}
end_function
begin_expr_stmt
unit|};
DECL|function|setFuture
name|Q_INLINE_TEMPLATE
name|void
name|QFutureWatcher
operator|<
name|void
operator|>
operator|::
name|setFuture
argument_list|(
argument|const QFuture<void>&_future
argument_list|)
block|{
if|if
condition|(
name|_future
operator|==
name|m_future
condition|)
return|return;
name|disconnectOutputInterface
argument_list|(
name|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_future
operator|=
name|_future
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|connectOutputInterface
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
unit|}  QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QFUTURE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFUTUREWATCHER_H
end_comment
end_unit
