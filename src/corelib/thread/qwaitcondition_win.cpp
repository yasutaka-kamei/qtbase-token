begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaitcondition.h"
end_include
begin_include
include|#
directive|include
file|"qnamespace.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qreadwritelock.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_include
include|#
directive|include
file|"qalgorithms.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_define
DECL|macro|Q_MUTEX_T
define|#
directive|define
name|Q_MUTEX_T
value|void*
end_define
begin_include
include|#
directive|include
file|<private/qmutex_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qreadwritelock_p.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|//***********************************************************************
end_comment
begin_comment
comment|// QWaitConditionPrivate
end_comment
begin_comment
comment|// **********************************************************************
end_comment
begin_class
DECL|class|QWaitConditionEvent
class|class
name|QWaitConditionEvent
block|{
public|public:
DECL|function|QWaitConditionEvent
specifier|inline
name|QWaitConditionEvent
parameter_list|()
member_init_list|:
name|priority
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|wokenUp
argument_list|(
literal|false
argument_list|)
block|{
name|event
operator|=
name|CreateEvent
argument_list|(
name|NULL
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
DECL|function|~QWaitConditionEvent
specifier|inline
name|~
name|QWaitConditionEvent
parameter_list|()
block|{
name|CloseHandle
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
DECL|member|priority
name|int
name|priority
decl_stmt|;
DECL|member|wokenUp
name|bool
name|wokenUp
decl_stmt|;
DECL|member|event
name|HANDLE
name|event
decl_stmt|;
block|}
class|;
end_class
begin_typedef
DECL|typedef|EventQueue
typedef|typedef
name|QList
argument_list|<
name|QWaitConditionEvent
modifier|*
argument_list|>
name|EventQueue
typedef|;
end_typedef
begin_class
DECL|class|QWaitConditionPrivate
class|class
name|QWaitConditionPrivate
block|{
public|public:
DECL|member|mtx
name|QMutex
name|mtx
decl_stmt|;
DECL|member|queue
name|EventQueue
name|queue
decl_stmt|;
DECL|member|freeQueue
name|EventQueue
name|freeQueue
decl_stmt|;
name|QWaitConditionEvent
modifier|*
name|pre
parameter_list|()
function_decl|;
name|bool
name|wait
parameter_list|(
name|QWaitConditionEvent
modifier|*
name|wce
parameter_list|,
name|unsigned
name|long
name|time
parameter_list|)
function_decl|;
name|void
name|post
parameter_list|(
name|QWaitConditionEvent
modifier|*
name|wce
parameter_list|,
name|bool
name|ret
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|pre
name|QWaitConditionEvent
modifier|*
name|QWaitConditionPrivate
operator|::
name|pre
parameter_list|()
block|{
name|mtx
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QWaitConditionEvent
modifier|*
name|wce
init|=
name|freeQueue
operator|.
name|isEmpty
argument_list|()
condition|?
operator|new
name|QWaitConditionEvent
else|:
name|freeQueue
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|wce
operator|->
name|priority
operator|=
name|GetThreadPriority
argument_list|(
name|GetCurrentThread
argument_list|()
argument_list|)
expr_stmt|;
name|wce
operator|->
name|wokenUp
operator|=
literal|false
expr_stmt|;
comment|// insert 'wce' into the queue (sorted by priority)
name|int
name|index
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|index
operator|<
name|queue
operator|.
name|size
argument_list|()
condition|;
operator|++
name|index
control|)
block|{
name|QWaitConditionEvent
modifier|*
name|current
init|=
name|queue
operator|.
name|at
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
name|current
operator|->
name|priority
operator|<
name|wce
operator|->
name|priority
condition|)
break|break;
block|}
name|queue
operator|.
name|insert
argument_list|(
name|index
argument_list|,
name|wce
argument_list|)
expr_stmt|;
name|mtx
operator|.
name|unlock
argument_list|()
expr_stmt|;
return|return
name|wce
return|;
block|}
end_function
begin_function
DECL|function|wait
name|bool
name|QWaitConditionPrivate
operator|::
name|wait
parameter_list|(
name|QWaitConditionEvent
modifier|*
name|wce
parameter_list|,
name|unsigned
name|long
name|time
parameter_list|)
block|{
comment|// wait for the event
name|bool
name|ret
init|=
literal|false
decl_stmt|;
switch|switch
condition|(
name|WaitForSingleObject
argument_list|(
name|wce
operator|->
name|event
argument_list|,
name|time
argument_list|)
condition|)
block|{
default|default:
break|break;
case|case
name|WAIT_OBJECT_0
case|:
name|ret
operator|=
literal|true
expr_stmt|;
break|break;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|post
name|void
name|QWaitConditionPrivate
operator|::
name|post
parameter_list|(
name|QWaitConditionEvent
modifier|*
name|wce
parameter_list|,
name|bool
name|ret
parameter_list|)
block|{
name|mtx
operator|.
name|lock
argument_list|()
expr_stmt|;
comment|// remove 'wce' from the queue
name|queue
operator|.
name|removeAll
argument_list|(
name|wce
argument_list|)
expr_stmt|;
name|ResetEvent
argument_list|(
name|wce
operator|->
name|event
argument_list|)
expr_stmt|;
name|freeQueue
operator|.
name|append
argument_list|(
name|wce
argument_list|)
expr_stmt|;
comment|// wakeups delivered after the timeout should be forwarded to the next waiter
if|if
condition|(
operator|!
name|ret
operator|&&
name|wce
operator|->
name|wokenUp
operator|&&
operator|!
name|queue
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QWaitConditionEvent
modifier|*
name|other
init|=
name|queue
operator|.
name|first
argument_list|()
decl_stmt|;
name|SetEvent
argument_list|(
name|other
operator|->
name|event
argument_list|)
expr_stmt|;
name|other
operator|->
name|wokenUp
operator|=
literal|true
expr_stmt|;
block|}
name|mtx
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//***********************************************************************
end_comment
begin_comment
comment|// QWaitCondition implementation
end_comment
begin_comment
comment|//***********************************************************************
end_comment
begin_constructor
DECL|function|QWaitCondition
name|QWaitCondition
operator|::
name|QWaitCondition
parameter_list|()
block|{
name|d
operator|=
operator|new
name|QWaitConditionPrivate
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaitCondition
name|QWaitCondition
operator|::
name|~
name|QWaitCondition
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|queue
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWaitCondition: Destroyed while threads are still waiting"
argument_list|)
expr_stmt|;
name|qDeleteAll
argument_list|(
name|d
operator|->
name|queue
argument_list|)
expr_stmt|;
block|}
name|qDeleteAll
argument_list|(
name|d
operator|->
name|freeQueue
argument_list|)
expr_stmt|;
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|wait
name|bool
name|QWaitCondition
operator|::
name|wait
parameter_list|(
name|QMutex
modifier|*
name|mutex
parameter_list|,
name|unsigned
name|long
name|time
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mutex
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|mutex
operator|->
name|isRecursive
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWaitCondition::wait: Cannot wait on recursive mutexes"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QWaitConditionEvent
modifier|*
name|wce
init|=
name|d
operator|->
name|pre
argument_list|()
decl_stmt|;
name|mutex
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|bool
name|returnValue
init|=
name|d
operator|->
name|wait
argument_list|(
name|wce
argument_list|,
name|time
argument_list|)
decl_stmt|;
name|mutex
operator|->
name|lock
argument_list|()
expr_stmt|;
name|d
operator|->
name|post
argument_list|(
name|wce
argument_list|,
name|returnValue
argument_list|)
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
DECL|function|wait
name|bool
name|QWaitCondition
operator|::
name|wait
parameter_list|(
name|QReadWriteLock
modifier|*
name|readWriteLock
parameter_list|,
name|unsigned
name|long
name|time
parameter_list|)
block|{
if|if
condition|(
operator|!
name|readWriteLock
operator|||
name|readWriteLock
operator|->
name|d
operator|->
name|accessCount
operator|==
literal|0
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|readWriteLock
operator|->
name|d
operator|->
name|accessCount
operator|<
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWaitCondition: cannot wait on QReadWriteLocks with recursive lockForWrite()"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QWaitConditionEvent
modifier|*
name|wce
init|=
name|d
operator|->
name|pre
argument_list|()
decl_stmt|;
name|int
name|previousAccessCount
init|=
name|readWriteLock
operator|->
name|d
operator|->
name|accessCount
decl_stmt|;
name|readWriteLock
operator|->
name|unlock
argument_list|()
expr_stmt|;
name|bool
name|returnValue
init|=
name|d
operator|->
name|wait
argument_list|(
name|wce
argument_list|,
name|time
argument_list|)
decl_stmt|;
if|if
condition|(
name|previousAccessCount
operator|<
literal|0
condition|)
name|readWriteLock
operator|->
name|lockForWrite
argument_list|()
expr_stmt|;
else|else
name|readWriteLock
operator|->
name|lockForRead
argument_list|()
expr_stmt|;
name|d
operator|->
name|post
argument_list|(
name|wce
argument_list|,
name|returnValue
argument_list|)
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
DECL|function|wakeOne
name|void
name|QWaitCondition
operator|::
name|wakeOne
parameter_list|()
block|{
comment|// wake up the first waiting thread in the queue
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mtx
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|queue
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWaitConditionEvent
modifier|*
name|current
init|=
name|d
operator|->
name|queue
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|current
operator|->
name|wokenUp
condition|)
continue|continue;
name|SetEvent
argument_list|(
name|current
operator|->
name|event
argument_list|)
expr_stmt|;
name|current
operator|->
name|wokenUp
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_function
DECL|function|wakeAll
name|void
name|QWaitCondition
operator|::
name|wakeAll
parameter_list|()
block|{
comment|// wake up the all threads in the queue
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mtx
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|queue
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWaitConditionEvent
modifier|*
name|current
init|=
name|d
operator|->
name|queue
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|SetEvent
argument_list|(
name|current
operator|->
name|event
argument_list|)
expr_stmt|;
name|current
operator|->
name|wokenUp
operator|=
literal|true
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
end_unit
