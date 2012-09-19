begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_THREADENGINE_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_THREADENGINE_H
define|#
directive|define
name|QTCONCURRENT_THREADENGINE_H
end_define
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrent_global.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qthreadpool.h>
end_include
begin_include
include|#
directive|include
file|<QtConcurrent/qfuture.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrentexception.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qwaitcondition.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsemaphore.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|qdoc
name|namespace
name|QtConcurrent
block|{
comment|// The ThreadEngineBarrier counts worker threads, and allows one
comment|// thread to wait for all others to finish. Tested for its use in
comment|// QtConcurrent, requires more testing for use as a general class.
name|class
name|ThreadEngineBarrier
block|{
name|private
label|:
comment|// The thread count is maintained as an integer in the count atomic
comment|// variable. The count can be either positive or negative - a negative
comment|// count signals that a thread is waiting on the barrier.
name|QAtomicInt
name|count
decl_stmt|;
name|QSemaphore
name|semaphore
decl_stmt|;
name|public
label|:
name|ThreadEngineBarrier
argument_list|()
expr_stmt|;
name|void
name|acquire
parameter_list|()
function_decl|;
name|int
name|release
parameter_list|()
function_decl|;
name|void
name|wait
parameter_list|()
function_decl|;
name|int
name|currentCount
parameter_list|()
function_decl|;
name|bool
name|releaseUnlessLast
parameter_list|()
function_decl|;
block|}
empty_stmt|;
enum|enum
name|ThreadFunctionResult
block|{
name|ThrottleThread
block|,
name|ThreadFinished
block|}
enum|;
comment|// The ThreadEngine controls the threads used in the computation.
comment|// Can be run in three modes: single threaded, multi-threaded blocking
comment|// and multi-threaded asynchronous.
comment|// The code for the single threaded mode is
name|class
name|Q_CONCURRENT_EXPORT
name|ThreadEngineBase
range|:
name|public
name|QRunnable
block|{
name|public
operator|:
comment|// Public API:
name|ThreadEngineBase
argument_list|()
block|;
name|virtual
operator|~
name|ThreadEngineBase
argument_list|()
block|;
name|void
name|startSingleThreaded
argument_list|()
block|;
name|void
name|startBlocking
argument_list|()
block|;
name|void
name|startThread
argument_list|()
block|;
name|bool
name|isCanceled
argument_list|()
block|;
name|void
name|waitForResume
argument_list|()
block|;
name|bool
name|isProgressReportingEnabled
argument_list|()
block|;
name|void
name|setProgressValue
argument_list|(
argument|int progress
argument_list|)
block|;
name|void
name|setProgressRange
argument_list|(
argument|int minimum
argument_list|,
argument|int maximum
argument_list|)
block|;
name|void
name|acquireBarrierSemaphore
argument_list|()
block|;
name|protected
operator|:
comment|// The user overrides these:
name|virtual
name|void
name|start
argument_list|()
block|{}
name|virtual
name|void
name|finish
argument_list|()
block|{}
name|virtual
name|ThreadFunctionResult
name|threadFunction
argument_list|()
block|{
return|return
name|ThreadFinished
return|;
block|}
name|virtual
name|bool
name|shouldStartThread
argument_list|()
block|{
return|return
name|futureInterface
operator|?
operator|!
name|futureInterface
operator|->
name|isPaused
argument_list|()
operator|:
name|true
return|;
block|}
name|virtual
name|bool
name|shouldThrottleThread
argument_list|()
block|{
return|return
name|futureInterface
condition|?
name|futureInterface
operator|->
name|isPaused
argument_list|()
else|:
name|false
return|;
block|}
name|private
operator|:
name|bool
name|startThreadInternal
argument_list|()
block|;
name|void
name|startThreads
argument_list|()
block|;
name|void
name|threadExit
argument_list|()
block|;
name|bool
name|threadThrottleExit
argument_list|()
block|;
name|void
name|run
argument_list|()
block|;
name|virtual
name|void
name|asynchronousFinish
argument_list|()
operator|=
literal|0
block|;
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
name|void
name|handleException
argument_list|(
specifier|const
name|QtConcurrent
operator|::
name|Exception
operator|&
name|exception
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
name|QFutureInterfaceBase
operator|*
name|futureInterface
block|;
name|QThreadPool
operator|*
name|threadPool
block|;
name|ThreadEngineBarrier
name|barrier
block|;
name|QtConcurrent
operator|::
name|internal
operator|::
name|ExceptionStore
name|exceptionStore
block|; }
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ThreadEngine
operator|:
name|public
name|virtual
name|ThreadEngineBase
block|{
name|public
operator|:
typedef|typedef
name|T
name|ResultType
typedef|;
name|virtual
name|T
operator|*
name|result
argument_list|()
block|{
return|return
literal|0
return|;
block|}
name|QFutureInterface
operator|<
name|T
operator|>
operator|*
name|futureInterfaceTyped
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|QFutureInterface
operator|<
name|T
operator|>
operator|*
operator|>
operator|(
name|futureInterface
operator|)
return|;
block|}
comment|// Runs the user algorithm using a single thread.
name|T
operator|*
name|startSingleThreaded
argument_list|()
block|{
name|ThreadEngineBase
operator|::
name|startSingleThreaded
argument_list|()
block|;
return|return
name|result
argument_list|()
return|;
block|}
comment|// Runs the user algorithm using multiple threads.
comment|// This function blocks until the algorithm is finished,
comment|// and then returns the result.
name|T
operator|*
name|startBlocking
argument_list|()
block|{
name|ThreadEngineBase
operator|::
name|startBlocking
argument_list|()
block|;
return|return
name|result
argument_list|()
return|;
block|}
comment|// Runs the user algorithm using multiple threads.
comment|// Does not block, returns a future.
name|QFuture
operator|<
name|T
operator|>
name|startAsynchronously
argument_list|()
block|{
name|futureInterface
operator|=
name|new
name|QFutureInterface
operator|<
name|T
operator|>
operator|(
operator|)
block|;
comment|// reportStart() must be called before starting threads, otherwise the
comment|// user algorithm might finish while reportStart() is running, which
comment|// is very bad.
name|futureInterface
operator|->
name|reportStarted
argument_list|()
block|;
name|QFuture
operator|<
name|T
operator|>
name|future
operator|=
name|QFuture
operator|<
name|T
operator|>
operator|(
name|futureInterfaceTyped
argument_list|()
operator|)
block|;
name|start
argument_list|()
block|;
name|acquireBarrierSemaphore
argument_list|()
block|;
name|threadPool
operator|->
name|start
argument_list|(
name|this
argument_list|)
block|;
return|return
name|future
return|;
block|}
name|void
name|asynchronousFinish
argument_list|()
block|{
name|finish
argument_list|()
block|;
name|futureInterfaceTyped
argument_list|()
operator|->
name|reportFinished
argument_list|(
name|result
argument_list|()
argument_list|)
block|;
name|delete
name|futureInterfaceTyped
argument_list|()
block|;
name|delete
name|this
block|;     }
name|void
name|reportResult
argument_list|(
argument|const T *_result
argument_list|,
argument|int index = -
literal|1
argument_list|)
block|{
if|if
condition|(
name|futureInterface
condition|)
name|futureInterfaceTyped
argument_list|()
operator|->
name|reportResult
argument_list|(
name|_result
argument_list|,
name|index
argument_list|)
expr_stmt|;
block|}
name|void
name|reportResults
argument_list|(
specifier|const
name|QVector
operator|<
name|T
operator|>
operator|&
name|_result
argument_list|,
name|int
name|index
operator|=
operator|-
literal|1
argument_list|,
name|int
name|count
operator|=
operator|-
literal|1
argument_list|)
block|{
if|if
condition|(
name|futureInterface
condition|)
name|futureInterfaceTyped
argument_list|()
operator|->
name|reportResults
argument_list|(
name|_result
argument_list|,
name|index
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// The ThreadEngineStarter class ecapsulates the return type
end_comment
begin_comment
comment|// from the thread engine.
end_comment
begin_comment
comment|// Depending on how the it is used, it will run
end_comment
begin_comment
comment|// the engine in either blocking mode or asynchronous mode.
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ThreadEngineStarterBase
block|{
name|public
operator|:
name|ThreadEngineStarterBase
argument_list|(
name|ThreadEngine
operator|<
name|T
operator|>
operator|*
name|_threadEngine
argument_list|)
operator|:
name|threadEngine
argument_list|(
argument|_threadEngine
argument_list|)
block|{ }
specifier|inline
name|ThreadEngineStarterBase
argument_list|(
specifier|const
name|ThreadEngineStarterBase
operator|&
name|other
argument_list|)
operator|:
name|threadEngine
argument_list|(
argument|other.threadEngine
argument_list|)
block|{ }
name|QFuture
operator|<
name|T
operator|>
name|startAsynchronously
argument_list|()
block|{
return|return
name|threadEngine
operator|->
name|startAsynchronously
argument_list|()
return|;
block|}
name|operator
name|QFuture
operator|<
name|T
operator|>
operator|(
operator|)
block|{
return|return
name|startAsynchronously
argument_list|()
return|;
block|}
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|ThreadEngine
operator|<
name|T
operator|>
operator|*
name|threadEngine
expr_stmt|;
end_expr_stmt
begin_comment
unit|};
comment|// We need to factor out the code that dereferences the T pointer,
end_comment
begin_comment
comment|// with a specialization where T is void. (code that dereferences a void *
end_comment
begin_comment
comment|// won't compile)
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ThreadEngineStarter
operator|:
name|public
name|ThreadEngineStarterBase
operator|<
name|T
operator|>
block|{
typedef|typedef
name|ThreadEngineStarterBase
operator|<
name|T
operator|>
name|Base
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|ThreadEngine
operator|<
name|T
operator|>
name|TypedThreadEngine
expr_stmt|;
end_typedef
begin_label
name|public
label|:
end_label
begin_expr_stmt
name|ThreadEngineStarter
argument_list|(
name|TypedThreadEngine
operator|*
name|eng
argument_list|)
operator|:
name|Base
argument_list|(
argument|eng
argument_list|)
block|{ }
name|T
name|startBlocking
argument_list|()
block|{
name|T
name|t
operator|=
operator|*
name|this
operator|->
name|threadEngine
operator|->
name|startBlocking
argument_list|()
block|;
name|delete
name|this
operator|->
name|threadEngine
block|;
return|return
name|t
return|;
block|}
end_expr_stmt
begin_comment
unit|};
comment|// Full template specialization where T is void.
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|ThreadEngineStarter
operator|<
name|void
operator|>
operator|:
name|public
name|ThreadEngineStarterBase
operator|<
name|void
operator|>
block|{
name|public
operator|:
name|ThreadEngineStarter
operator|<
name|void
operator|>
operator|(
name|ThreadEngine
operator|<
name|void
operator|>
operator|*
name|_threadEngine
operator|)
operator|:
name|ThreadEngineStarterBase
operator|<
name|void
operator|>
operator|(
name|_threadEngine
operator|)
block|{}
name|void
name|startBlocking
argument_list|()
block|{
name|this
operator|->
name|threadEngine
operator|->
name|startBlocking
argument_list|()
block|;
name|delete
name|this
operator|->
name|threadEngine
block|;     }
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|ThreadEngine
operator|>
specifier|inline
name|ThreadEngineStarter
operator|<
name|typename
name|ThreadEngine
operator|::
name|ResultType
operator|>
name|startThreadEngine
argument_list|(
argument|ThreadEngine *threadEngine
argument_list|)
block|{
return|return
name|ThreadEngineStarter
operator|<
name|typename
name|ThreadEngine
operator|::
name|ResultType
operator|>
operator|(
name|threadEngine
operator|)
return|;
block|}
end_expr_stmt
begin_comment
unit|}
comment|// namespace QtConcurrent
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//qdoc
end_comment
begin_macro
unit|QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CONCURRENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
