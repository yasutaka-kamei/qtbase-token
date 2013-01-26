begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_INTEGRITY_H
end_ifndef
begin_define
DECL|macro|QATOMIC_INTEGRITY_H
define|#
directive|define
name|QATOMIC_INTEGRITY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qoldbasicatomic.h>
end_include
begin_include
include|#
directive|include
file|<INTEGRITY.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|qt_i2addr
define|#
directive|define
name|qt_i2addr
parameter_list|(
name|a
parameter_list|)
value|reinterpret_cast<Address *>(const_cast<int *>(a))
DECL|macro|qt_p2addr
define|#
directive|define
name|qt_p2addr
parameter_list|(
name|a
parameter_list|)
value|reinterpret_cast<Address *>(const_cast<void *>(a))
DECL|macro|qt_addr
define|#
directive|define
name|qt_addr
parameter_list|(
name|a
parameter_list|)
value|reinterpret_cast<Address>(a)
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_NOT_NATIVE
DECL|function|isReferenceCountingNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isReferenceCountingNative
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isReferenceCountingWaitFree
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isReferenceCountingWaitFree
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_NOT_NATIVE
end_define
begin_expr_stmt
DECL|function|isTestAndSetNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isTestAndSetNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isTestAndSetWaitFree
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isTestAndSetWaitFree
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_NOT_NATIVE
end_define
begin_expr_stmt
DECL|function|isFetchAndStoreNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndStoreNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isFetchAndStoreWaitFree
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndStoreWaitFree
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_NOT_NATIVE
end_define
begin_expr_stmt
DECL|function|isFetchAndAddNative
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndAddNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isFetchAndAddWaitFree
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|isFetchAndAddWaitFree
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_NOT_NATIVE
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isTestAndSetNative
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isTestAndSetNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isTestAndSetWaitFree
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isTestAndSetWaitFree
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_NOT_NATIVE
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndStoreNative
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndStoreNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndStoreWaitFree
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndStoreWaitFree
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_NOT_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_NOT_NATIVE
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndAddNative
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndAddNative
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|isFetchAndAddWaitFree
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|isFetchAndAddWaitFree
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_comment
comment|// Reference counting
end_comment
begin_expr_stmt
DECL|function|ref
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|ref
argument_list|()
block|{
name|int
name|oldval
block|;
name|AtomicModify
argument_list|(
name|qt_i2addr
argument_list|(
operator|&
name|_q_value
argument_list|)
argument_list|,
name|qt_i2addr
argument_list|(
operator|&
name|oldval
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|;
return|return
name|_q_value
operator|!=
operator|-
literal|1
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|deref
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|deref
argument_list|()
block|{
name|int
name|oldval
block|;
name|AtomicModify
argument_list|(
name|qt_i2addr
argument_list|(
operator|&
name|_q_value
argument_list|)
argument_list|,
name|qt_i2addr
argument_list|(
operator|&
name|oldval
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|-
literal|1U
argument_list|)
block|;
return|return
name|_q_value
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_comment
comment|// Test and set for integers
end_comment
begin_expr_stmt
DECL|function|testAndSetOrdered
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetOrdered
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
return|return
name|TestAndSet
argument_list|(
name|qt_i2addr
argument_list|(
operator|&
name|_q_value
argument_list|)
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
operator|==
name|Success
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetRelaxed
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetRelaxed
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetAcquire
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetAcquire
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|testAndSetRelease
specifier|inline
name|bool
name|QBasicAtomicInt
operator|::
name|testAndSetRelease
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and store for integers
end_comment
begin_expr_stmt
DECL|function|fetchAndStoreOrdered
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreOrdered
argument_list|(
argument|int newValue
argument_list|)
block|{
name|int
name|old_val
block|;
do|do
block|{
name|old_val
operator|=
name|_q_value
expr_stmt|;
block|}
end_expr_stmt
begin_while
while|while
condition|(
name|TestAndSet
argument_list|(
name|qt_i2addr
argument_list|(
operator|&
name|_q_value
argument_list|)
argument_list|,
name|old_val
argument_list|,
name|newValue
argument_list|)
operator|!=
name|Success
condition|)
empty_stmt|;
end_while
begin_return
return|return
name|old_val
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|fetchAndStoreRelaxed
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndStoreAcquire
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreAcquire
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndStoreRelease
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndStoreRelease
argument_list|(
argument|int newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and add for integers
end_comment
begin_expr_stmt
DECL|function|fetchAndAddOrdered
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddOrdered
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
name|int
name|old_val
block|;
do|do
block|{
name|old_val
operator|=
name|_q_value
expr_stmt|;
block|}
end_expr_stmt
begin_while
while|while
condition|(
name|TestAndSet
argument_list|(
name|qt_i2addr
argument_list|(
operator|&
name|_q_value
argument_list|)
argument_list|,
name|old_val
argument_list|,
name|old_val
operator|+
name|valueToAdd
argument_list|)
operator|!=
name|Success
condition|)
empty_stmt|;
end_while
begin_return
return|return
name|old_val
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|fetchAndAddRelaxed
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndAddAcquire
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddAcquire
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|fetchAndAddRelease
specifier|inline
name|int
name|QBasicAtomicInt
operator|::
name|fetchAndAddRelease
argument_list|(
argument|int valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Test and set for pointers
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|testAndSetOrdered
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetOrdered
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
argument_list|)
block|{
return|return
name|TestAndSet
argument_list|(
operator|(
name|Address
operator|*
operator|)
operator|&
name|_q_value
argument_list|,
name|qt_addr
argument_list|(
name|expectedValue
argument_list|)
argument_list|,
name|qt_addr
argument_list|(
name|newValue
argument_list|)
argument_list|)
operator|==
name|Success
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|testAndSetRelaxed
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
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
DECL|function|testAndSetAcquire
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetAcquire
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
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
DECL|function|testAndSetRelease
name|Q_INLINE_TEMPLATE
name|bool
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|testAndSetRelease
argument_list|(
argument|T *expectedValue
argument_list|,
argument|T *newValue
argument_list|)
block|{
return|return
name|testAndSetOrdered
argument_list|(
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and store for pointers
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndStoreOrdered
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreOrdered
argument_list|(
argument|T *newValue
argument_list|)
block|{
name|Address
name|old_val
block|;
do|do
block|{
name|old_val
operator|=
operator|*
name|reinterpret_cast
operator|<
name|Address
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|newValue
operator|)
operator|)
expr_stmt|;
block|}
end_expr_stmt
begin_while
while|while
condition|(
name|TestAndSet
argument_list|(
name|reinterpret_cast
operator|<
name|Address
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|T
operator|*
operator|*
operator|>
operator|(
operator|&
name|_q_value
operator|)
operator|)
argument_list|,
name|old_val
argument_list|,
name|qt_addr
argument_list|(
name|newValue
argument_list|)
argument_list|)
operator|!=
name|Success
condition|)
empty_stmt|;
end_while
begin_return
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|old_val
operator|)
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndStoreRelaxed
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|T *newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
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
DECL|function|fetchAndStoreAcquire
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreAcquire
argument_list|(
argument|T *newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
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
DECL|function|fetchAndStoreRelease
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndStoreRelease
argument_list|(
argument|T *newValue
argument_list|)
block|{
return|return
name|fetchAndStoreOrdered
argument_list|(
name|newValue
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Fetch and add for pointers
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndAddOrdered
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddOrdered
argument_list|(
argument|qptrdiff valueToAdd
argument_list|)
block|{
name|AtomicModify
argument_list|(
name|qt_p2addr
argument_list|(
operator|&
name|_q_value
argument_list|)
argument_list|,
name|qt_addr
argument_list|(
name|_q_value
argument_list|)
argument_list|,
name|qt_addr
argument_list|(
name|_q_value
argument_list|)
operator|+
name|valueToAdd
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;
return|return
name|_q_value
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|fetchAndAddRelaxed
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|qptrdiff valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
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
DECL|function|fetchAndAddAcquire
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddAcquire
argument_list|(
argument|qptrdiff valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
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
DECL|function|fetchAndAddRelease
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QBasicAtomicPointer
operator|<
name|T
operator|>
operator|::
name|fetchAndAddRelease
argument_list|(
argument|qptrdiff valueToAdd
argument_list|)
block|{
return|return
name|fetchAndAddOrdered
argument_list|(
name|valueToAdd
argument_list|)
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_INTEGRITY_H
end_comment
end_unit
