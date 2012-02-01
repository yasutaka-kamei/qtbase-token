begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTHREAD_P_H
end_ifndef
begin_define
DECL|macro|QTHREAD_P_H
define|#
directive|define
name|QTHREAD_P_H
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
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qthread.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmutex.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstack.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qwaitcondition.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEventLoop
name|class
name|QEventLoop
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPostEvent
block|{
name|public
label|:
name|QObject
modifier|*
name|receiver
decl_stmt|;
name|QEvent
modifier|*
name|event
decl_stmt|;
name|int
name|priority
decl_stmt|;
specifier|inline
name|QPostEvent
argument_list|()
operator|:
name|receiver
argument_list|(
literal|0
argument_list|)
operator|,
name|event
argument_list|(
literal|0
argument_list|)
operator|,
name|priority
argument_list|(
literal|0
argument_list|)
block|{ }
specifier|inline
name|QPostEvent
argument_list|(
argument|QObject *r
argument_list|,
argument|QEvent *e
argument_list|,
argument|int p
argument_list|)
operator|:
name|receiver
argument_list|(
name|r
argument_list|)
operator|,
name|event
argument_list|(
name|e
argument_list|)
operator|,
name|priority
argument_list|(
argument|p
argument_list|)
block|{ }
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QPostEvent
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|int
name|priority
operator|,
specifier|const
name|QPostEvent
operator|&
name|pe
operator|)
block|{
return|return
name|pe
operator|.
name|priority
operator|<
name|priority
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QPostEvent
operator|&
name|pe
operator|,
name|int
name|priority
operator|)
block|{
return|return
name|priority
operator|<
name|pe
operator|.
name|priority
return|;
block|}
end_expr_stmt
begin_comment
comment|// This class holds the list of posted events.
end_comment
begin_comment
comment|//  The list has to be kept sorted by priority
end_comment
begin_decl_stmt
name|class
name|QPostEventList
range|:
name|public
name|QVector
operator|<
name|QPostEvent
operator|>
block|{
name|public
operator|:
comment|// recursion == recursion count for sendPostedEvents()
name|int
name|recursion
block|;
comment|// sendOffset == the current event to start sending
name|int
name|startOffset
block|;
comment|// insertionOffset == set by sendPostedEvents to tell postEvent() where to start insertions
name|int
name|insertionOffset
block|;
name|QMutex
name|mutex
block|;
specifier|inline
name|QPostEventList
argument_list|()
operator|:
name|QVector
operator|<
name|QPostEvent
operator|>
operator|(
operator|)
block|,
name|recursion
argument_list|(
literal|0
argument_list|)
block|,
name|startOffset
argument_list|(
literal|0
argument_list|)
block|,
name|insertionOffset
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|addEvent
argument_list|(
argument|const QPostEvent&ev
argument_list|)
block|{
name|int
name|priority
operator|=
name|ev
operator|.
name|priority
block|;
if|if
condition|(
name|isEmpty
argument_list|()
operator|||
name|last
argument_list|()
operator|.
name|priority
operator|>=
name|priority
operator|||
name|begin
argument_list|()
operator|+
name|insertionOffset
operator|>=
name|end
argument_list|()
condition|)
block|{
comment|// optimization: we can simply append if the last event in
comment|// the queue has higher or equal priority
name|append
argument_list|(
name|ev
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// insert event in descending priority order, using upper
comment|// bound for a given priority (to ensure proper ordering
comment|// of events with the same priority)
name|QPostEventList
operator|::
name|iterator
name|at
operator|=
name|qUpperBound
argument_list|(
name|begin
argument_list|()
operator|+
name|insertionOffset
argument_list|,
name|end
argument_list|()
argument_list|,
name|priority
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|at
argument_list|,
name|ev
argument_list|)
expr_stmt|;
block|}
block|}
name|private
operator|:
comment|//hides because they do not keep that list sorted. addEvent must be used
name|using
name|QVector
operator|<
name|QPostEvent
operator|>
operator|::
name|append
block|;
name|using
name|QVector
operator|<
name|QPostEvent
operator|>
operator|::
name|insert
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_decl_stmt
name|class
name|QThreadPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QThread
argument_list|)
name|public
operator|:
name|QThreadPrivate
argument_list|(
name|QThreadData
operator|*
name|d
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QThreadPrivate
argument_list|()
block|;
name|mutable
name|QMutex
name|mutex
block|;
name|bool
name|running
block|;
name|bool
name|finished
block|;
name|bool
name|terminated
block|;
name|bool
name|isInFinish
block|;
comment|//when in QThreadPrivate::finish
name|bool
name|exited
block|;
name|int
name|returnCode
block|;
name|uint
name|stackSize
block|;
name|QThread
operator|::
name|Priority
name|priority
block|;
specifier|static
name|QThread
operator|*
name|threadForId
argument_list|(
argument|int id
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_OS_UNIX
name|pthread_t
name|thread_id
block|;
name|QWaitCondition
name|thread_done
block|;
specifier|static
name|void
operator|*
name|start
argument_list|(
name|void
operator|*
name|arg
argument_list|)
block|;
specifier|static
name|void
name|finish
argument_list|(
name|void
operator|*
argument_list|)
block|;
endif|#
directive|endif
comment|// Q_OS_UNIX
ifdef|#
directive|ifdef
name|Q_OS_WIN
specifier|static
name|unsigned
name|int
name|__stdcall
name|start
argument_list|(
name|void
operator|*
argument_list|)
block|;
specifier|static
name|void
name|finish
argument_list|(
argument|void *
argument_list|,
argument|bool lockAnyway=true
argument_list|)
block|;
name|Qt
operator|::
name|HANDLE
name|handle
block|;
name|unsigned
name|int
name|id
block|;
name|int
name|waiters
block|;
name|bool
name|terminationEnabled
block|,
name|terminatePending
block|;
endif|#
directive|endif
name|QThreadData
operator|*
name|data
block|;
specifier|static
name|void
name|createEventDispatcher
argument_list|(
name|QThreadData
operator|*
name|data
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_decl_stmt
name|class
name|QThreadPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
name|QThreadPrivate
argument_list|(
name|QThreadData
operator|*
name|d
operator|=
literal|0
argument_list|)
operator|:
name|data
argument_list|(
argument|d ? d : new QThreadData
argument_list|)
block|{}
operator|~
name|QThreadPrivate
argument_list|()
block|{
name|delete
name|data
block|; }
name|QThreadData
operator|*
name|data
block|;
specifier|static
name|void
name|setCurrentThread
argument_list|(
argument|QThread*
argument_list|)
block|{}
specifier|static
name|QThread
operator|*
name|threadForId
argument_list|(
argument|int
argument_list|)
block|{
return|return
name|QThread
operator|::
name|currentThread
argument_list|()
return|;
block|}
specifier|static
name|void
name|createEventDispatcher
argument_list|(
name|QThreadData
operator|*
name|data
argument_list|)
block|;
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QThread
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_decl_stmt
name|class
name|QThreadData
block|{
name|QAtomicInt
name|_ref
decl_stmt|;
name|public
label|:
name|QThreadData
argument_list|(
argument|int initialRefCount =
literal|1
argument_list|)
empty_stmt|;
operator|~
name|QThreadData
argument_list|()
expr_stmt|;
specifier|static
name|QThreadData
modifier|*
name|current
parameter_list|()
function_decl|;
specifier|static
name|QThreadData
modifier|*
name|get2
parameter_list|(
name|QThread
modifier|*
name|thread
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|thread
operator|!=
literal|0
argument_list|,
literal|"QThread"
argument_list|,
literal|"internal error"
argument_list|)
expr_stmt|;
return|return
name|thread
operator|->
name|d_func
argument_list|()
operator|->
name|data
return|;
block|}
name|void
name|ref
parameter_list|()
function_decl|;
name|void
name|deref
parameter_list|()
function_decl|;
name|QThread
modifier|*
name|thread
decl_stmt|;
name|Qt
operator|::
name|HANDLE
name|threadId
expr_stmt|;
name|bool
name|quitNow
decl_stmt|;
name|int
name|loopLevel
decl_stmt|;
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
decl_stmt|;
name|QStack
operator|<
name|QEventLoop
operator|*
operator|>
name|eventLoops
expr_stmt|;
name|QPostEventList
name|postEventList
decl_stmt|;
name|bool
name|canWait
decl_stmt|;
name|QVector
operator|<
name|void
operator|*
operator|>
name|tls
expr_stmt|;
name|bool
name|isAdopted
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QScopedLoopLevelCounter
block|{
name|QThreadData
modifier|*
name|threadData
decl_stmt|;
name|public
label|:
specifier|inline
name|QScopedLoopLevelCounter
argument_list|(
name|QThreadData
operator|*
name|threadData
argument_list|)
operator|:
name|threadData
argument_list|(
argument|threadData
argument_list|)
block|{
operator|++
name|threadData
operator|->
name|loopLevel
block|; }
specifier|inline
operator|~
name|QScopedLoopLevelCounter
argument_list|()
block|{
operator|--
name|threadData
operator|->
name|loopLevel
block|; }
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// thread wrapper for the main() thread
end_comment
begin_decl_stmt
name|class
name|QAdoptedThread
range|:
name|public
name|QThread
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QThread
argument_list|)
name|public
operator|:
name|QAdoptedThread
argument_list|(
name|QThreadData
operator|*
name|data
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QAdoptedThread
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|private
operator|:
name|void
name|run
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
comment|// QTHREAD_P_H
end_comment
end_unit
