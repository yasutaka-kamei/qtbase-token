begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Thiago Macieira<thiago@kde.org> ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_GCC_H
end_ifndef
begin_define
DECL|macro|QATOMIC_GCC_H
define|#
directive|define
name|QATOMIC_GCC_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qgenericatomic.h>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
if|#
directive|if
literal|0
comment|// silence syncqt warnings
expr|QT_END_NAMESPACE QT_END_HEADER
pragma|#
directive|pragma
name|qt_sync_stop_processing
endif|#
directive|endif
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|int
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QAtomicIntegerTraits
operator|<
name|unsigned
name|int
operator|>
block|{ enum
block|{
name|IsInteger
operator|=
literal|1
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT32_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT32_IS_SUPPORTED
end_define
begin_define
DECL|macro|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT32_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_TEST_AND_SET_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_POINTER_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_REFERENCE_COUNTING_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_SOMETIMES_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_SOMETIMES_NATIVE
end_define
begin_expr_stmt
DECL|struct|T
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|QAtomicOps
operator|:
name|QGenericAtomicOps
operator|<
name|QAtomicOps
operator|<
name|T
operator|>
expr|>
block|{
comment|// The GCC intrinsics all have fully-ordered memory semantics, so we define
comment|// only the xxxRelaxed functions. The exception is __sync_lock_and_test,
comment|// which has acquire semantics, so we need to define the Release and
comment|// Ordered versions too.
DECL|typedef|Type
typedef|typedef
name|T
name|Type
typedef|;
ifndef|#
directive|ifndef
name|__ia64__
specifier|static
name|T
name|loadAcquire
argument_list|(
argument|const T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|T
name|tmp
operator|=
name|_q_value
block|;
name|__sync_synchronize
argument_list|()
block|;
return|return
name|tmp
return|;
block|}
specifier|static
name|void
name|storeRelease
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|__sync_synchronize
argument_list|()
block|;
name|_q_value
operator|=
name|newValue
block|;     }
endif|#
directive|endif
specifier|static
name|bool
name|isTestAndSetNative
argument_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_function
specifier|static
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
begin_function
specifier|static
name|bool
name|testAndSetRelaxed
parameter_list|(
name|T
modifier|&
name|_q_value
parameter_list|,
name|T
name|expectedValue
parameter_list|,
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|__sync_bool_compare_and_swap
argument_list|(
operator|&
name|_q_value
argument_list|,
name|expectedValue
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|T
name|fetchAndStoreRelaxed
parameter_list|(
name|T
modifier|&
name|_q_value
parameter_list|,
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|T
name|fetchAndStoreRelease
parameter_list|(
name|T
modifier|&
name|_q_value
parameter_list|,
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|__sync_synchronize
argument_list|()
expr_stmt|;
return|return
name|__sync_lock_test_and_set
argument_list|(
operator|&
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|T
name|fetchAndStoreOrdered
parameter_list|(
name|T
modifier|&
name|_q_value
parameter_list|,
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|fetchAndStoreRelease
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
specifier|static
name|T
name|fetchAndAddRelaxed
argument_list|(
name|T
operator|&
name|_q_value
argument_list|,
name|typename
name|QAtomicAdditiveType
operator|<
name|T
operator|>
operator|::
name|AdditiveT
name|valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|__sync_fetch_and_add
argument_list|(
operator|&
name|_q_value
argument_list|,
name|valueToAdd
operator|*
name|QAtomicAdditiveType
operator|<
name|T
operator|>
operator|::
name|AddScale
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_GCC_H
end_comment
end_unit
