begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|"qmutex_p.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|<linux/futex.h>
end_include
begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<asm/unistd.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_LINUX_FUTEX
end_ifndef
begin_error
error|#
directive|error
literal|"Qt build is broken: qmutex_linux.cpp is being built but futex support is not wanted"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*  * QBasicMutex implementation on Linux with futexes  *  * QBasicMutex contains one pointer value, which can contain one of four  * different values:  *    0x0       unlocked, non-recursive mutex  *    0x1       locked non-recursive mutex, no waiters  *    0x3       locked non-recursive mutex, at least one waiter  *> 0x3      recursive mutex, points to a QMutexPrivate object  *  * LOCKING (non-recursive):  *  * A non-recursive mutex starts in the 0x0 state, indicating that it's  * unlocked. When the first thread attempts to lock it, it will perform a  * testAndSetAcquire from 0x0 to 0x1. If that succeeds, the caller concludes  * that it successfully locked the mutex. That happens in fastTryLock().  *  * If that testAndSetAcquire fails, QBasicMutex::lockInternal is called.  *  * lockInternal will examine the value of the pointer. Otherwise, it will use  * futexes to sleep and wait for another thread to unlock. To do that, it needs  * to set a pointer value of 0x3, which indicates that thread is waiting. It  * does that by a simple fetchAndStoreAcquire operation.  *  * If the pointer value was 0x0, it means we succeeded in acquiring the mutex.  * For other values, it will then call FUTEX_WAIT and with an expected value of  * 0x3.  *  * If the pointer value changed before futex(2) managed to sleep, it will  * return -1 / EWOULDBLOCK, in which case we have to start over. And even if we  * are woken up directly by a FUTEX_WAKE, we need to acquire the mutex, so we  * start over again.  *  * UNLOCKING (non-recursive):  *  * To unlock, we need to set a value of 0x0 to indicate it's unlocked. The  * first attempt is a testAndSetRelease operation from 0x1 to 0x0. If that  * succeeds, we're done.  *  * If it fails, unlockInternal() is called. The only possibility is that the  * mutex value was 0x3, which indicates some other thread is waiting or was  * waiting in the past. We then set the mutex to 0x0 and perform a FUTEX_WAKE.  */
DECL|variable|futexFlagSupport
specifier|static
name|QBasicAtomicInt
name|futexFlagSupport
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|checkFutexPrivateSupport
specifier|static
name|int
name|checkFutexPrivateSupport
parameter_list|()
block|{
name|int
name|value
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|FUTEX_PRIVATE_FLAG
argument_list|)
comment|// check if the kernel supports extra futex flags
comment|// FUTEX_PRIVATE_FLAG appeared in v2.6.22
name|Q_STATIC_ASSERT
argument_list|(
name|FUTEX_PRIVATE_FLAG
operator|!=
literal|0x80000000
argument_list|)
expr_stmt|;
comment|// try an operation that has no side-effects: wake up 42 threads
comment|// futex will return -1 (errno==ENOSYS) if the flag isn't supported
comment|// there should be no other error conditions
name|value
operator|=
name|syscall
argument_list|(
name|__NR_futex
argument_list|,
operator|&
name|futexFlagSupport
argument_list|,
name|FUTEX_WAKE
operator||
name|FUTEX_PRIVATE_FLAG
argument_list|,
literal|42
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|value
operator|!=
operator|-
literal|1
condition|)
name|value
operator|=
name|FUTEX_PRIVATE_FLAG
expr_stmt|;
else|else
name|value
operator|=
literal|0
expr_stmt|;
else|#
directive|else
name|value
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
name|futexFlagSupport
operator|.
name|store
argument_list|(
name|value
argument_list|)
expr_stmt|;
return|return
name|value
return|;
block|}
end_function
begin_function
DECL|function|futexFlags
specifier|static
specifier|inline
name|int
name|futexFlags
parameter_list|()
block|{
name|int
name|value
init|=
name|futexFlagSupport
operator|.
name|load
argument_list|()
decl_stmt|;
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|value
operator|!=
operator|-
literal|1
argument_list|)
condition|)
return|return
name|value
return|;
return|return
name|checkFutexPrivateSupport
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|int
name|_q_futex
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|op
parameter_list|,
name|int
name|val
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|)
name|Q_DECL_NOTHROW
block|{
specifier|volatile
name|int
modifier|*
name|int_addr
init|=
cast|reinterpret_cast
argument_list|<
specifier|volatile
name|int
operator|*
argument_list|>
argument_list|(
name|addr
argument_list|)
decl_stmt|;
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
operator|&&
name|QT_POINTER_SIZE
operator|==
literal|8
name|int_addr
operator|++
expr_stmt|;
comment|//We want a pointer to the 32 least significant bit of QMutex::d
endif|#
directive|endif
name|int
modifier|*
name|addr2
init|=
literal|0
decl_stmt|;
name|int
name|val2
init|=
literal|0
decl_stmt|;
comment|// we use __NR_futex because some libcs (like Android's bionic) don't
comment|// provide SYS_futex etc.
return|return
name|syscall
argument_list|(
name|__NR_futex
argument_list|,
name|int_addr
argument_list|,
name|op
operator||
name|futexFlags
argument_list|()
argument_list|,
name|val
argument_list|,
name|timeout
argument_list|,
name|addr2
argument_list|,
name|val2
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|dummyFutexValue
specifier|static
specifier|inline
name|QMutexData
modifier|*
name|dummyFutexValue
parameter_list|()
block|{
return|return
cast|reinterpret_cast
argument_list|<
name|QMutexData
operator|*
argument_list|>
argument_list|(
name|quintptr
argument_list|(
literal|3
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|bool
name|IsTimed
parameter_list|>
specifier|static
specifier|inline
name|bool
name|lockInternal_helper
parameter_list|(
name|QBasicAtomicPointer
argument_list|<
name|QMutexData
argument_list|>
modifier|&
name|d_ptr
parameter_list|,
name|int
name|timeout
init|=
operator|-
literal|1
parameter_list|,
name|QElapsedTimer
modifier|*
name|elapsedTimer
init|=
literal|0
parameter_list|)
name|Q_DECL_NOTHROW
block|{
if|if
condition|(
operator|!
name|IsTimed
condition|)
name|timeout
operator|=
operator|-
literal|1
expr_stmt|;
comment|// we're here because fastTryLock() has just failed
if|if
condition|(
name|timeout
operator|==
literal|0
condition|)
return|return
literal|false
return|;
name|struct
name|timespec
name|ts
decl_stmt|,
modifier|*
name|pts
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|IsTimed
operator|&&
name|timeout
operator|>
literal|0
condition|)
block|{
name|ts
operator|.
name|tv_sec
operator|=
name|timeout
operator|/
literal|1000
expr_stmt|;
name|ts
operator|.
name|tv_nsec
operator|=
operator|(
name|timeout
operator|%
literal|1000
operator|)
operator|*
literal|1000
operator|*
literal|1000
expr_stmt|;
block|}
comment|// the mutex is locked already, set a bit indicating we're waiting
while|while
condition|(
name|d_ptr
operator|.
name|fetchAndStoreAcquire
argument_list|(
name|dummyFutexValue
argument_list|()
argument_list|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|IsTimed
operator|&&
name|pts
operator|==
operator|&
name|ts
condition|)
block|{
comment|// recalculate the timeout
name|qint64
name|xtimeout
init|=
name|qint64
argument_list|(
name|timeout
argument_list|)
operator|*
literal|1000
operator|*
literal|1000
decl_stmt|;
name|xtimeout
operator|-=
name|elapsedTimer
operator|->
name|nsecsElapsed
argument_list|()
expr_stmt|;
if|if
condition|(
name|xtimeout
operator|<=
literal|0
condition|)
block|{
comment|// timer expired after we returned
return|return
literal|false
return|;
block|}
name|ts
operator|.
name|tv_sec
operator|=
name|xtimeout
operator|/
name|Q_INT64_C
argument_list|(
literal|1000
argument_list|)
operator|/
literal|1000
operator|/
literal|1000
expr_stmt|;
name|ts
operator|.
name|tv_nsec
operator|=
name|xtimeout
operator|%
operator|(
name|Q_INT64_C
argument_list|(
literal|1000
argument_list|)
operator|*
literal|1000
operator|*
literal|1000
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|IsTimed
operator|&&
name|timeout
operator|>
literal|0
condition|)
name|pts
operator|=
operator|&
name|ts
expr_stmt|;
comment|// successfully set the waiting bit, now sleep
name|int
name|r
init|=
name|_q_futex
argument_list|(
operator|&
name|d_ptr
argument_list|,
name|FUTEX_WAIT
argument_list|,
name|quintptr
argument_list|(
name|dummyFutexValue
argument_list|()
argument_list|)
argument_list|,
name|pts
argument_list|)
decl_stmt|;
if|if
condition|(
name|IsTimed
operator|&&
name|r
operator|!=
literal|0
operator|&&
name|errno
operator|==
name|ETIMEDOUT
condition|)
return|return
literal|false
return|;
comment|// we got woken up, so try to acquire the mutex
comment|// note we must set to dummyFutexValue because there could be other threads
comment|// also waiting
block|}
name|Q_ASSERT
argument_list|(
name|d_ptr
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
name|void
name|QBasicMutex
operator|::
name|lockInternal
parameter_list|()
name|Q_DECL_NOTHROW
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isRecursive
argument_list|()
argument_list|)
expr_stmt|;
name|lockInternal_helper
argument_list|<
literal|false
argument_list|>
argument_list|(
name|d_ptr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|bool
name|QBasicMutex
operator|::
name|lockInternal
parameter_list|(
name|int
name|timeout
parameter_list|)
name|Q_DECL_NOTHROW
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isRecursive
argument_list|()
argument_list|)
expr_stmt|;
name|QElapsedTimer
name|elapsedTimer
decl_stmt|;
name|elapsedTimer
operator|.
name|start
argument_list|()
expr_stmt|;
return|return
name|lockInternal_helper
argument_list|<
literal|true
argument_list|>
argument_list|(
name|d_ptr
argument_list|,
name|timeout
argument_list|,
operator|&
name|elapsedTimer
argument_list|)
return|;
block|}
end_function
begin_function
name|void
name|QBasicMutex
operator|::
name|unlockInternal
parameter_list|()
name|Q_DECL_NOTHROW
block|{
name|QMutexData
modifier|*
name|d
init|=
name|d_ptr
operator|.
name|load
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|d
argument_list|)
expr_stmt|;
comment|//we must be locked
name|Q_ASSERT
argument_list|(
name|d
operator|!=
name|dummyLocked
argument_list|()
argument_list|)
expr_stmt|;
comment|// testAndSetRelease(dummyLocked(), 0) failed
name|Q_UNUSED
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|isRecursive
argument_list|()
argument_list|)
expr_stmt|;
name|d_ptr
operator|.
name|storeRelease
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|_q_futex
argument_list|(
operator|&
name|d_ptr
argument_list|,
name|FUTEX_WAKE
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
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
