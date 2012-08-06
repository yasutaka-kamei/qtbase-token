begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2011 Thiago Macieira<thiago@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_X86_H
end_ifndef
begin_define
DECL|macro|QATOMIC_X86_H
define|#
directive|define
name|QATOMIC_X86_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qgenericatomic.h>
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
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT_REFERENCE_COUNTING_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT_TEST_AND_SET_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_STORE_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT_FETCH_AND_ADD_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT32_IS_SUPPORTED
define|#
directive|define
name|Q_ATOMIC_INT32_IS_SUPPORTED
DECL|macro|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT32_REFERENCE_COUNTING_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT32_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_TEST_AND_SET_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT32_TEST_AND_SET_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_STORE_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT32_FETCH_AND_ADD_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_POINTER_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_POINTER_TEST_AND_SET_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_STORE_IS_WAIT_FREE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_ALWAYS_NATIVE
DECL|macro|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_POINTER_FETCH_AND_ADD_IS_WAIT_FREE
DECL|struct|size
name|template
operator|<
name|int
name|size
operator|>
expr|struct
name|QBasicAtomicOps
operator|:
name|QGenericAtomicOps
operator|<
name|QBasicAtomicOps
operator|<
name|size
operator|>
expr|>
block|{
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
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isReferenceCountingWaitFree
argument_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|member|Q_DECL_NOTHROW
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|member|Q_DECL_NOTHROW
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
expr_stmt|;
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
name|true
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
name|true
return|;
block|}
end_function
begin_expr_stmt
DECL|member|Q_DECL_NOTHROW
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
DECL|member|Q_DECL_NOTHROW
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|,
argument|T *currentValue
argument_list|)
name|Q_DECL_NOTHROW
expr_stmt|;
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|true
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
name|true
return|;
block|}
end_function
begin_expr_stmt
DECL|member|Q_DECL_NOTHROW
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
expr_stmt|;
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
name|true
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
name|true
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
DECL|member|Q_DECL_NOTHROW
name|T
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|member|Q_DECL_NOTHROW
unit|};
DECL|function|sizeof
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|QAtomicOps
operator|:
name|QBasicAtomicOps
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
block|{
typedef|typedef
name|T
name|Type
typedef|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_expr_stmt
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
begin_comment
comment|/*  * Guide for the inline assembly below:  *  * x86 instructions are in the form "{opcode}{length} {source}, {destination}",  * where the length is one of the letters "b" (byte), "w" (word, 16-bit), "l"  * (dword, 32-bit), "q" (qword, 64-bit).  *  * In most cases, we can omit the length because it's inferred from one of the  * registers. For example, "xchg %0,%1" doesn't need the length suffix because  * we can only exchange data of the same size and one of the operands must be a  * register.  *  * The exception is the increment and decrement functions, where we add and  * subtract an immediate value (1). For those, we need to specify the length.  * GCC and ICC support the syntax "add%z0 $1, %0", where "%z0" expands to the  * length of the operand. Unfortunately, clang as of 3.0 doesn't support that.  * For that reason, the ref() and deref() functions are rolled out for all  * sizes.  *  * The functions are also rolled out for the 1-byte operations since those  * require a special register constraint "q" to force the compiler to schedule  * one of the 8-bit registers. It's probably a compiler bug that it tries to  * use a register that doesn't exist.  *  * Finally, 64-bit operations are supported via the cmpxchg8b instruction on  * 32-bit processors, via specialisation below.  */
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"addb  $1, %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
literal|2
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"incw %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"addl $1, %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"subb $1, %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
literal|2
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"decw %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
literal|4
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"subl $1, %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
name|size
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"cmpxchg %3,%2\n"
literal|"sete %1\n"
operator|:
literal|"=a"
operator|(
name|newValue
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|newValue
operator|)
operator|,
literal|"0"
operator|(
name|expectedValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"cmpxchg %3,%2\n"
literal|"sete %1\n"
operator|:
literal|"=a"
operator|(
name|newValue
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"q"
operator|(
name|newValue
operator|)
operator|,
literal|"0"
operator|(
name|expectedValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
name|size
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|,
argument|T *currentValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"cmpxchg %3,%2\n"
literal|"sete %1\n"
operator|:
literal|"=a"
operator|(
name|newValue
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"r"
operator|(
name|newValue
operator|)
operator|,
literal|"0"
operator|(
name|expectedValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
operator|*
name|currentValue
operator|=
name|newValue
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|,
argument|T *currentValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"cmpxchg %3,%2\n"
literal|"sete %1\n"
operator|:
literal|"=a"
operator|(
name|newValue
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"q"
operator|(
name|newValue
operator|)
operator|,
literal|"0"
operator|(
name|expectedValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
operator|*
name|currentValue
operator|=
name|newValue
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|QBasicAtomicOps
operator|<
name|size
operator|>
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|asm
specifier|volatile
operator|(
literal|"xchg %0,%1"
operator|:
literal|"=r"
operator|(
name|newValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"0"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|newValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|fetchAndStoreRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|asm
specifier|volatile
operator|(
literal|"xchg %0,%1"
operator|:
literal|"=q"
operator|(
name|newValue
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"0"
operator|(
name|newValue
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|newValue
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|QBasicAtomicOps
operator|<
name|size
operator|>
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|T
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"xadd %0,%1"
operator|:
literal|"=r"
operator|(
name|result
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"0"
operator|(
name|T
argument_list|(
name|valueToAdd
operator|*
name|QAtomicAdditiveType
operator|<
name|T
operator|>
operator|::
name|AddScale
argument_list|)
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|result
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|QBasicAtomicOps
operator|<
literal|1
operator|>
operator|::
name|fetchAndAddRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|typename QAtomicAdditiveType<T>::AdditiveT valueToAdd
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|T
name|result
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"xadd %0,%1"
operator|:
literal|"=q"
operator|(
name|result
operator|)
operator|,
literal|"+m"
operator|(
name|_q_value
operator|)
operator|:
literal|"0"
operator|(
name|T
argument_list|(
name|valueToAdd
operator|*
name|QAtomicAdditiveType
operator|<
name|T
operator|>
operator|::
name|AddScale
argument_list|)
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|result
return|;
block|}
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
DECL|macro|Q_ATOMIC_INT8_REFERENCE_COUNTING_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT8_REFERENCE_COUNTING_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT8_TEST_AND_SET_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT8_FETCH_AND_STORE_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT8_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT8_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT8_FETCH_AND_ADD_IS_WAIT_FREE
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
DECL|macro|Q_ATOMIC_INT16_REFERENCE_COUNTING_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT16_REFERENCE_COUNTING_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT16_TEST_AND_SET_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT16_FETCH_AND_STORE_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT16_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT16_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT16_FETCH_AND_ADD_IS_WAIT_FREE
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|Q_PROCESSOR_X86_64
end_ifdef
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
DECL|macro|Q_ATOMIC_INT64_REFERENCE_COUNTING_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT64_REFERENCE_COUNTING_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_TEST_AND_SET_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_TEST_AND_SET_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_TEST_AND_SET_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT64_TEST_AND_SET_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_STORE_IS_WAIT_FREE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_ALWAYS_NATIVE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_ALWAYS_NATIVE
end_define
begin_define
DECL|macro|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_WAIT_FREE
define|#
directive|define
name|Q_ATOMIC_INT64_FETCH_AND_ADD_IS_WAIT_FREE
end_define
begin_comment
comment|// native support for 64-bit types
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
literal|8
operator|>
operator|::
name|ref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"addq $1, %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|QBasicAtomicOps
operator|<
literal|8
operator|>
operator|::
name|deref
argument_list|(
argument|T&_q_value
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|unsigned
name|char
name|ret
block|;
name|asm
specifier|volatile
operator|(
literal|"lock\n"
literal|"subq $1, %0\n"
literal|"setne %1"
operator|:
literal|"=m"
operator|(
name|_q_value
operator|)
operator|,
literal|"=qm"
operator|(
name|ret
operator|)
operator|:
literal|"m"
operator|(
name|_q_value
operator|)
operator|:
literal|"memory"
operator|)
block|;
return|return
name|ret
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// i386 architecture, emulate 64-bit support via cmpxchg8b
end_comment
begin_expr_stmt
DECL|struct|QBasicAtomicOps
name|template
operator|<
operator|>
expr|struct
name|QBasicAtomicOps
operator|<
literal|8
operator|>
operator|:
name|QGenericAtomicOps
operator|<
name|QBasicAtomicOps
operator|<
literal|8
operator|>
expr|>
block|{
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetNative
argument_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetWaitFree
argument_list|()
name|Q_DECL_NOTHROW
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
specifier|static
specifier|inline
name|bool
name|testAndSetRelaxed
argument_list|(
argument|T&_q_value
argument_list|,
argument|T expectedValue
argument_list|,
argument|T newValue
argument_list|)
name|Q_DECL_NOTHROW
block|{
ifdef|#
directive|ifdef
name|__PIC__
DECL|macro|EBX_reg
define|#
directive|define
name|EBX_reg
value|"r"
DECL|macro|EBX_load
define|#
directive|define
name|EBX_load
parameter_list|(
name|reg
parameter_list|)
value|"xchg " reg ", %%ebx\n"
else|#
directive|else
define|#
directive|define
name|EBX_reg
value|"b"
define|#
directive|define
name|EBX_load
parameter_list|(
name|reg
parameter_list|)
endif|#
directive|endif
name|quint32
name|highExpectedValue
operator|=
name|quint32
argument_list|(
name|newValue
operator|>>
literal|32
argument_list|)
block|;
comment|// ECX
name|asm
specifier|volatile
operator|(
name|EBX_load
argument_list|(
literal|"%3"
argument_list|)
literal|"lock\n"
literal|"cmpxchg8b %0\n"
name|EBX_load
argument_list|(
literal|"%3"
argument_list|)
literal|"sete %%cl\n"
operator|:
literal|"+m"
operator|(
name|_q_value
operator|)
operator|,
literal|"+c"
operator|(
name|highExpectedValue
operator|)
operator|,
literal|"+&A"
operator|(
name|expectedValue
operator|)
operator|:
name|EBX_reg
argument_list|(
name|quint32
argument_list|(
name|newValue
operator|&
literal|0xffffffff
argument_list|)
argument_list|)
operator|:
literal|"memory"
operator|)
block|;
comment|// if the comparison failed, expectedValue here contains the current value
return|return
name|quint8
argument_list|(
name|highExpectedValue
argument_list|)
operator|!=
literal|0
return|;
DECL|macro|EBX_reg
undef|#
directive|undef
name|EBX_reg
DECL|macro|EBX_load
undef|#
directive|undef
name|EBX_load
block|}
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_error
error|#
directive|error
literal|"This compiler for x86 is not supported"
end_error
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
comment|// QATOMIC_X86_H
end_comment
end_unit
