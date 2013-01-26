begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_ITERATEKERNEL_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_ITERATEKERNEL_H
define|#
directive|define
name|QTCONCURRENT_ITERATEKERNEL_H
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
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrentmedian.h>
end_include
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrentthreadengine.h>
end_include
begin_include
include|#
directive|include
file|<iterator>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|Q_QDOC
name|namespace
name|QtConcurrent
block|{
name|using
name|std
operator|::
name|advance
expr_stmt|;
comment|/*     The BlockSizeManager class manages how many iterations a thread should     reserve and process at a time. This is done by measuring the time spent     in the user code versus the control part code, and then increasing     the block size if the ratio between them is to small. The block size     management is done on the basis of the median of several timing measuremens,     and it is done induvidualy for each thread. */
name|class
name|Q_CONCURRENT_EXPORT
name|BlockSizeManager
block|{
name|public
label|:
name|BlockSizeManager
argument_list|(
argument|int iterationCount
argument_list|)
empty_stmt|;
name|void
name|timeBeforeUser
parameter_list|()
function_decl|;
name|void
name|timeAfterUser
parameter_list|()
function_decl|;
name|int
name|blockSize
parameter_list|()
function_decl|;
name|private
label|:
specifier|inline
name|bool
name|blockSizeMaxed
parameter_list|()
block|{
return|return
operator|(
name|m_blockSize
operator|>=
name|maxBlockSize
operator|)
return|;
block|}
specifier|const
name|int
name|maxBlockSize
decl_stmt|;
name|qint64
name|beforeUser
decl_stmt|;
name|qint64
name|afterUser
decl_stmt|;
name|Median
operator|<
name|double
operator|>
name|controlPartElapsed
expr_stmt|;
name|Median
operator|<
name|double
operator|>
name|userPartElapsed
expr_stmt|;
name|int
name|m_blockSize
decl_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ResultReporter
block|{
name|public
operator|:
name|ResultReporter
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
block|{      }
name|void
name|reserveSpace
argument_list|(
argument|int resultCount
argument_list|)
block|{
name|currentResultCount
operator|=
name|resultCount
block|;
name|vector
operator|.
name|resize
argument_list|(
name|qMax
argument_list|(
name|resultCount
argument_list|,
name|vector
operator|.
name|count
argument_list|()
argument_list|)
argument_list|)
block|;     }
name|void
name|reportResults
argument_list|(
argument|int begin
argument_list|)
block|{
specifier|const
name|int
name|useVectorThreshold
operator|=
literal|4
block|;
comment|// Tunable parameter.
if|if
condition|(
name|currentResultCount
operator|>
name|useVectorThreshold
condition|)
block|{
name|vector
operator|.
name|resize
argument_list|(
name|currentResultCount
argument_list|)
expr_stmt|;
name|threadEngine
operator|->
name|reportResults
argument_list|(
name|vector
argument_list|,
name|begin
argument_list|)
expr_stmt|;
block|}
else|else
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|currentResultCount
condition|;
operator|++
name|i
control|)
name|threadEngine
operator|->
name|reportResult
argument_list|(
operator|&
name|vector
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|begin
operator|+
name|i
argument_list|)
expr_stmt|;
block|}
block|}
specifier|inline
name|T
operator|*
name|getPointer
argument_list|()
block|{
return|return
name|vector
operator|.
name|data
argument_list|()
return|;
block|}
name|int
name|currentResultCount
block|;
name|ThreadEngine
operator|<
name|T
operator|>
operator|*
name|threadEngine
block|;
name|QVector
operator|<
name|T
operator|>
name|vector
block|; }
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|ResultReporter
operator|<
name|void
operator|>
block|{
name|public
operator|:
specifier|inline
name|ResultReporter
argument_list|(
argument|ThreadEngine<void> *
argument_list|)
block|{ }
specifier|inline
name|void
name|reserveSpace
argument_list|(
argument|int
argument_list|)
block|{ }
specifier|inline
name|void
name|reportResults
argument_list|(
argument|int
argument_list|)
block|{ }
specifier|inline
name|void
operator|*
name|getPointer
argument_list|()
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;
specifier|inline
name|bool
name|selectIteration
argument_list|(
argument|std::bidirectional_iterator_tag
argument_list|)
block|{
return|return
name|false
return|;
comment|// while
block|}
specifier|inline
name|bool
name|selectIteration
argument_list|(
argument|std::forward_iterator_tag
argument_list|)
block|{
return|return
name|false
return|;
comment|// while
block|}
specifier|inline
name|bool
name|selectIteration
argument_list|(
argument|std::random_access_iterator_tag
argument_list|)
block|{
return|return
name|true
return|;
comment|// for
block|}
name|template
operator|<
name|typename
name|Iterator
block|,
name|typename
name|T
operator|>
name|class
name|IterateKernel
operator|:
name|public
name|ThreadEngine
operator|<
name|T
operator|>
block|{
name|public
operator|:
typedef|typedef
name|T
name|ResultType
typedef|;
name|IterateKernel
argument_list|(
argument|Iterator _begin
argument_list|,
argument|Iterator _end
argument_list|)
operator|:
name|begin
argument_list|(
name|_begin
argument_list|)
operator|,
name|end
argument_list|(
name|_end
argument_list|)
operator|,
name|current
argument_list|(
name|_begin
argument_list|)
operator|,
name|currentIndex
argument_list|(
literal|0
argument_list|)
operator|,
name|forIteration
argument_list|(
name|selectIteration
argument_list|(
argument|typename std::iterator_traits<Iterator>::iterator_category()
argument_list|)
argument_list|)
operator|,
name|progressReportingEnabled
argument_list|(
argument|true
argument_list|)
block|{
name|iterationCount
operator|=
name|forIteration
operator|?
name|std
operator|::
name|distance
argument_list|(
name|_begin
argument_list|,
name|_end
argument_list|)
operator|:
literal|0
block|;     }
name|virtual
operator|~
name|IterateKernel
argument_list|()
block|{ }
name|virtual
name|bool
name|runIteration
argument_list|(
argument|Iterator it
argument_list|,
argument|int index
argument_list|,
argument|T *result
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|it
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|index
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|result
argument_list|)
block|;
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|runIterations
argument_list|(
argument|Iterator _begin
argument_list|,
argument|int beginIndex
argument_list|,
argument|int endIndex
argument_list|,
argument|T *results
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|_begin
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|beginIndex
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|endIndex
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|results
argument_list|)
block|;
return|return
name|false
return|;
block|}
name|void
name|start
argument_list|()
block|{
name|progressReportingEnabled
operator|=
name|this
operator|->
name|isProgressReportingEnabled
argument_list|()
block|;
if|if
condition|(
name|progressReportingEnabled
operator|&&
name|iterationCount
operator|>
literal|0
condition|)
name|this
operator|->
name|setProgressRange
argument_list|(
literal|0
argument_list|,
name|iterationCount
argument_list|)
expr_stmt|;
block|}
name|bool
name|shouldStartThread
argument_list|()
block|{
if|if
condition|(
name|forIteration
condition|)
return|return
operator|(
name|currentIndex
operator|.
name|load
argument_list|()
operator|<
name|iterationCount
operator|)
operator|&&
operator|!
name|this
operator|->
name|shouldThrottleThread
argument_list|()
return|;
else|else
comment|// whileIteration
return|return
operator|(
name|iteratorThreads
operator|.
name|load
argument_list|()
operator|==
literal|0
operator|)
return|;
block|}
name|ThreadFunctionResult
name|threadFunction
argument_list|()
block|{
if|if
condition|(
name|forIteration
condition|)
return|return
name|this
operator|->
name|forThreadFunction
argument_list|()
return|;
else|else
comment|// whileIteration
return|return
name|this
operator|->
name|whileThreadFunction
argument_list|()
return|;
block|}
name|ThreadFunctionResult
name|forThreadFunction
argument_list|()
block|{
name|BlockSizeManager
name|blockSizeManager
argument_list|(
name|iterationCount
argument_list|)
block|;
name|ResultReporter
operator|<
name|T
operator|>
name|resultReporter
argument_list|(
name|this
argument_list|)
block|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|this
operator|->
name|isCanceled
argument_list|()
condition|)
break|break;
specifier|const
name|int
name|currentBlockSize
init|=
name|blockSizeManager
operator|.
name|blockSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|currentIndex
operator|.
name|load
argument_list|()
operator|>=
name|iterationCount
condition|)
break|break;
comment|// Atomically reserve a block of iterationCount for this thread.
specifier|const
name|int
name|beginIndex
init|=
name|currentIndex
operator|.
name|fetchAndAddRelease
argument_list|(
name|currentBlockSize
argument_list|)
decl_stmt|;
specifier|const
name|int
name|endIndex
init|=
name|qMin
argument_list|(
name|beginIndex
operator|+
name|currentBlockSize
argument_list|,
name|iterationCount
argument_list|)
decl_stmt|;
if|if
condition|(
name|beginIndex
operator|>=
name|endIndex
condition|)
block|{
comment|// No more work
break|break;
block|}
name|this
operator|->
name|waitForResume
argument_list|()
expr_stmt|;
comment|// (only waits if the qfuture is paused.)
if|if
condition|(
name|shouldStartThread
argument_list|()
condition|)
name|this
operator|->
name|startThread
argument_list|()
expr_stmt|;
specifier|const
name|int
name|finalBlockSize
init|=
name|endIndex
operator|-
name|beginIndex
decl_stmt|;
comment|// block size adjusted for possible end-of-range
name|resultReporter
operator|.
name|reserveSpace
argument_list|(
name|finalBlockSize
argument_list|)
expr_stmt|;
comment|// Call user code with the current iteration range.
name|blockSizeManager
operator|.
name|timeBeforeUser
argument_list|()
expr_stmt|;
specifier|const
name|bool
name|resultsAvailable
init|=
name|this
operator|->
name|runIterations
argument_list|(
name|begin
argument_list|,
name|beginIndex
argument_list|,
name|endIndex
argument_list|,
name|resultReporter
operator|.
name|getPointer
argument_list|()
argument_list|)
decl_stmt|;
name|blockSizeManager
operator|.
name|timeAfterUser
argument_list|()
expr_stmt|;
if|if
condition|(
name|resultsAvailable
condition|)
name|resultReporter
operator|.
name|reportResults
argument_list|(
name|beginIndex
argument_list|)
expr_stmt|;
comment|// Report progress if progress reporting enabled.
if|if
condition|(
name|progressReportingEnabled
condition|)
block|{
name|completed
operator|.
name|fetchAndAddAcquire
argument_list|(
name|finalBlockSize
argument_list|)
expr_stmt|;
name|this
operator|->
name|setProgressValue
argument_list|(
name|this
operator|->
name|completed
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|this
operator|->
name|shouldThrottleThread
argument_list|()
condition|)
return|return
name|ThrottleThread
return|;
block|}
return|return
name|ThreadFinished
return|;
block|}
name|ThreadFunctionResult
name|whileThreadFunction
argument_list|()
block|{
if|if
condition|(
name|iteratorThreads
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
operator|==
name|false
condition|)
return|return
name|ThreadFinished
return|;
name|ResultReporter
operator|<
name|T
operator|>
name|resultReporter
argument_list|(
name|this
argument_list|)
block|;
name|resultReporter
operator|.
name|reserveSpace
argument_list|(
literal|1
argument_list|)
block|;
while|while
condition|(
name|current
operator|!=
name|end
condition|)
block|{
comment|// The following two lines breaks support for input iterators according to
comment|// the sgi docs: dereferencing prev after calling ++current is not allowed
comment|// on input iterators. (prev is dereferenced inside user.runIteration())
name|Iterator
name|prev
init|=
name|current
decl_stmt|;
operator|++
name|current
expr_stmt|;
name|int
name|index
init|=
name|currentIndex
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|iteratorThreads
operator|.
name|testAndSetRelease
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|this
operator|->
name|waitForResume
argument_list|()
expr_stmt|;
comment|// (only waits if the qfuture is paused.)
if|if
condition|(
name|shouldStartThread
argument_list|()
condition|)
name|this
operator|->
name|startThread
argument_list|()
expr_stmt|;
specifier|const
name|bool
name|resultAavailable
init|=
name|this
operator|->
name|runIteration
argument_list|(
name|prev
argument_list|,
name|index
argument_list|,
name|resultReporter
operator|.
name|getPointer
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|resultAavailable
condition|)
name|resultReporter
operator|.
name|reportResults
argument_list|(
name|index
argument_list|)
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|shouldThrottleThread
argument_list|()
condition|)
return|return
name|ThrottleThread
return|;
if|if
condition|(
name|iteratorThreads
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
operator|==
name|false
condition|)
return|return
name|ThreadFinished
return|;
block|}
return|return
name|ThreadFinished
return|;
block|}
name|public
label|:
specifier|const
name|Iterator
name|begin
decl_stmt|;
specifier|const
name|Iterator
name|end
decl_stmt|;
name|Iterator
name|current
decl_stmt|;
name|QAtomicInt
name|currentIndex
decl_stmt|;
name|bool
name|forIteration
decl_stmt|;
name|QAtomicInt
name|iteratorThreads
decl_stmt|;
name|int
name|iterationCount
decl_stmt|;
name|bool
name|progressReportingEnabled
decl_stmt|;
name|QAtomicInt
name|completed
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
unit|}
comment|// namespace QtConcurrent
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_QDOC
end_comment
begin_endif
unit|QT_END_NAMESPACE
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
