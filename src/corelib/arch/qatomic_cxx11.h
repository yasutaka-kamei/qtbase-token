begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Thiago Macieira<thiago@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_CXX11_H
end_ifndef
begin_define
DECL|macro|QATOMIC_CXX11_H
define|#
directive|define
name|QATOMIC_CXX11_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qgenericatomic.h>
end_include
begin_include
include|#
directive|include
file|<atomic>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
literal|0
comment|// silence syncqt warnings
expr|QT_END_NAMESPACE
pragma|#
directive|pragma
name|qt_sync_skip_header_check
pragma|#
directive|pragma
name|qt_sync_stop_processing
endif|#
directive|endif
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_INT32_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT32_IS_SUPPORTED
DECL|macro|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_INT32_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_TEST_AND_SET_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_POINTER_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
DECL|struct|QAtomicOpsSupport
DECL|enumerator|IsSupported
name|template
operator|<
operator|>
expr|struct
name|QAtomicOpsSupport
operator|<
literal|1
operator|>
block|{ enum
block|{
name|IsSupported
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|struct|QAtomicOpsSupport
DECL|enumerator|IsSupported
name|template
operator|<
operator|>
expr|struct
name|QAtomicOpsSupport
operator|<
literal|2
operator|>
block|{ enum
block|{
name|IsSupported
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|struct|QAtomicOpsSupport
DECL|enumerator|IsSupported
name|template
operator|<
operator|>
expr|struct
name|QAtomicOpsSupport
operator|<
literal|8
operator|>
block|{ enum
block|{
name|IsSupported
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_INT8_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT8_IS_SUPPORTED
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT16_IS_SUPPORTED
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT64_IS_SUPPORTED
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_expr_stmt
DECL|struct|QAtomicOps
name|template
operator|<
name|typename
name|X
operator|>
expr|struct
name|QAtomicOps
block|{
DECL|typedef|Type
typedef|typedef
name|std
operator|::
name|atomic
operator|<
name|X
operator|>
name|Type
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|load
argument_list|(
argument|const std::atomic<T>&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_relaxed
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|load
argument_list|(
argument|const volatile std::atomic<T>&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_relaxed
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|loadAcquire
argument_list|(
argument|const std::atomic<T>&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_acquire
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|loadAcquire
argument_list|(
argument|const volatile std::atomic<T>&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_acquire
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|void
name|store
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|_q_value
operator|.
name|store
argument_list|(
name|newValue
argument_list|,
name|std
operator|::
name|memory_order_relaxed
argument_list|)
block|;     }
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|void
name|storeRelease
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|_q_value
operator|.
name|store
argument_list|(
name|newValue
argument_list|,
name|std
operator|::
name|memory_order_release
argument_list|)
block|;     }
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isReferenceCountingNative
argument_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isReferenceCountingWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|false
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|bool
name|ref
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|)
block|{
return|return
operator|++
name|_q_value
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|bool
name|deref
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
operator|--
name|_q_value
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|false
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|false
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|testAndSetRelaxed
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|,
argument|T *currentValue =
literal|0
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|bool
name|tmp
operator|=
name|_q_value
operator|.
name|compare_exchange_strong
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|,
name|std
operator|::
name|memory_order_relaxed
argument_list|)
block|;
if|if
condition|(
name|currentValue
condition|)
operator|*
name|currentValue
operator|=
name|expectedValue
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|tmp
return|;
end_return
begin_expr_stmt
unit|}      template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|testAndSetAcquire
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|,
argument|T *currentValue =
literal|0
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|bool
name|tmp
operator|=
name|_q_value
operator|.
name|compare_exchange_strong
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|,
name|std
operator|::
name|memory_order_acquire
argument_list|)
block|;
if|if
condition|(
name|currentValue
condition|)
operator|*
name|currentValue
operator|=
name|expectedValue
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|tmp
return|;
end_return
begin_expr_stmt
unit|}      template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|testAndSetRelease
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|,
argument|T *currentValue =
literal|0
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|bool
name|tmp
operator|=
name|_q_value
operator|.
name|compare_exchange_strong
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|,
name|std
operator|::
name|memory_order_release
argument_list|)
block|;
if|if
condition|(
name|currentValue
condition|)
operator|*
name|currentValue
operator|=
name|expectedValue
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|tmp
return|;
end_return
begin_expr_stmt
unit|}      template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|testAndSetOrdered
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|,
argument|T *currentValue =
literal|0
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|bool
name|tmp
operator|=
name|_q_value
operator|.
name|compare_exchange_strong
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|,
name|std
operator|::
name|memory_order_acq_rel
argument_list|)
block|;
if|if
condition|(
name|currentValue
condition|)
operator|*
name|currentValue
operator|=
name|expectedValue
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|tmp
return|;
end_return
begin_function
unit|}      static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|false
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|false
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|fetchAndStoreRelaxed
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|exchange
argument_list|(
name|newValue
argument_list|,
name|std
operator|::
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|fetchAndStoreAcquire
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|exchange
argument_list|(
name|newValue
argument_list|,
name|std
operator|::
name|memory_order_acquire
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|fetchAndStoreRelease
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|exchange
argument_list|(
name|newValue
argument_list|,
name|std
operator|::
name|memory_order_release
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|fetchAndStoreOrdered
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|exchange
argument_list|(
name|newValue
argument_list|,
name|std
operator|::
name|memory_order_acq_rel
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndAddNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|false
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndAddWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|false
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndAddRelaxed
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_add
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndAddAcquire
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_add
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_acquire
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndAddRelease
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_add
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_release
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndAddOrdered
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_add
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_acq_rel
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndSubRelaxed
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_sub
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndSubAcquire
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_sub
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_acquire
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndSubRelease
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_sub
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_release
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndSubOrdered
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_sub
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_acq_rel
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndAndRelaxed
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_and
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndAndAcquire
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_and
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_acquire
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndAndRelease
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_and
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_release
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndAndOrdered
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_and
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_acq_rel
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndOrRelaxed
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_or
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndOrAcquire
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_or
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_acquire
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndOrRelease
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_or
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_release
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndOrOrdered
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_or
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_acq_rel
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndXorRelaxed
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_xor
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndXorAcquire
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_xor
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_acquire
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndXorRelease
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_xor
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_release
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|T
name|fetchAndXorOrdered
argument_list|(
argument|std::atomic<T>&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
operator|.
name|fetch_xor
argument_list|(
name|valueToAdd
argument_list|,
name|std
operator|::
name|memory_order_acq_rel
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|ATOMIC_VAR_INIT
end_ifdef
begin_define
DECL|macro|Q_BASIC_ATOMIC_INITIALIZER
define|#
directive|define
name|Q_BASIC_ATOMIC_INITIALIZER
parameter_list|(
name|a
parameter_list|)
value|{ ATOMIC_VAR_INIT(a) }
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_BASIC_ATOMIC_INITIALIZER
define|#
directive|define
name|Q_BASIC_ATOMIC_INITIALIZER
parameter_list|(
name|a
parameter_list|)
value|{ {a} }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_CXX0X_H
end_comment
end_unit
