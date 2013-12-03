begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Thiago Macieira<thiago@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QBASICATOMIC_H
end_ifndef
begin_define
DECL|macro|QBASICATOMIC_H
define|#
directive|define
name|QBASICATOMIC_H
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qatomic_bootstrap.h>
end_include
begin_comment
comment|// Compiler dependent implementation
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<QtCore/qatomic_msvc.h>
end_include
begin_comment
comment|// Processor dependent implementation
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_ARM_V7
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_PROCESSOR_ARM_32
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"QtCore/qatomic_armv7.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_ARM_V6
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_PROCESSOR_ARM_32
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"QtCore/qatomic_armv6.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_ARM_V5
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_PROCESSOR_ARM_32
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"QtCore/qatomic_armv5.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_IA64
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"QtCore/qatomic_ia64.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_MIPS
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"QtCore/qatomic_mips.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_SPARC
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"QtCore/qatomic_sparc.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<QtCore/qatomic_x86.h>
end_include
begin_comment
comment|// Fallback compiler dependent implementation
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_COMPILER_ATOMICS
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_COMPILER_CONSTEXPR
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<QtCore/qatomic_cxx11.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<QtCore/qatomic_gcc.h>
end_include
begin_comment
comment|// Fallback operating system dependent implementation
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<QtCore/qatomic_unix.h>
end_include
begin_comment
comment|// No fallback
end_comment
begin_else
else|#
directive|else
end_else
begin_error
error|#
directive|error
literal|"Qt has not been ported to this platform"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
literal|0
comment|// silence syncqt warnings
expr|QT_END_NAMESPACE
pragma|#
directive|pragma
name|qt_no_master_include
pragma|#
directive|pragma
name|qt_sync_stop_processing
endif|#
directive|endif
comment|// New atomics
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_CONSTEXPR
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_COMPILER_DEFAULT_MEMBERS
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_COMPILER_DELETE_MEMBERS
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_CLANG
argument_list|)
operator|&&
operator|(
operator|(
operator|(
operator|(
name|__clang_major__
operator|*
literal|100
operator|)
operator|+
name|__clang_minor__
operator|)
operator|<
literal|303
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|__apple_build_version__
argument_list|)
expr|\
operator|)
comment|/* Do not define QT_BASIC_ATOMIC_HAS_CONSTRUCTORS for "stock" clang before version 3.3.       Apple's version has different (higher!) version numbers, so disable it for all of them for now.       (The only way to distinguish between them seems to be a check for __apple_build_version__ .)        For details about the bug: see http://llvm.org/bugs/show_bug.cgi?id=12670     */
else|#
directive|else
define|#
directive|define
name|QT_BASIC_ATOMIC_HAS_CONSTRUCTORS
endif|#
directive|endif
endif|#
directive|endif
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QBasicAtomicInteger
block|{
name|public
operator|:
typedef|typedef
name|QAtomicOps
operator|<
name|T
operator|>
name|Ops
expr_stmt|;
comment|// static check that this is a valid integer
name|Q_STATIC_ASSERT_X
argument_list|(
name|QAtomicIntegerTraits
operator|<
name|T
operator|>
operator|::
name|IsInteger
argument_list|,
literal|"Template parameter is not a supported integer on this platform"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|typename
name|Ops
operator|::
name|Type
name|_q_value
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Everything below is either implemented in ../arch/qatomic_XXX.h or (as fallback) in qgenericatomic.h
end_comment
begin_expr_stmt
name|T
name|load
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|load
argument_list|(
name|_q_value
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|void
name|store
parameter_list|(
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|Ops
operator|::
name|store
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|T
name|loadAcquire
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|loadAcquire
argument_list|(
name|_q_value
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|void
name|storeRelease
parameter_list|(
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|Ops
operator|::
name|storeRelease
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isReferenceCountingNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isReferenceCountingNative
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isReferenceCountingWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isReferenceCountingWaitFree
argument_list|()
return|;
block|}
end_function
begin_function
name|bool
name|ref
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|ref
argument_list|(
name|_q_value
argument_list|)
return|;
block|}
end_function
begin_function
name|bool
name|deref
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|deref
argument_list|(
name|_q_value
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isTestAndSetNative
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isTestAndSetWaitFree
argument_list|()
return|;
block|}
end_function
begin_function
name|bool
name|testAndSetRelaxed
parameter_list|(
name|T
name|expectedValue
parameter_list|,
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|testAndSetRelaxed
argument_list|(
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
name|bool
name|testAndSetAcquire
parameter_list|(
name|T
name|expectedValue
parameter_list|,
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|testAndSetAcquire
argument_list|(
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
name|bool
name|testAndSetRelease
parameter_list|(
name|T
name|expectedValue
parameter_list|,
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|testAndSetRelease
argument_list|(
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
name|bool
name|testAndSetOrdered
parameter_list|(
name|T
name|expectedValue
parameter_list|,
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|testAndSetOrdered
argument_list|(
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
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isFetchAndStoreNative
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isFetchAndStoreWaitFree
argument_list|()
return|;
block|}
end_function
begin_function
name|T
name|fetchAndStoreRelaxed
parameter_list|(
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreRelaxed
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|T
name|fetchAndStoreAcquire
parameter_list|(
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreAcquire
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|T
name|fetchAndStoreRelease
parameter_list|(
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreRelease
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|T
name|fetchAndStoreOrdered
parameter_list|(
name|T
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreOrdered
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndAddNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isFetchAndAddNative
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndAddWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isFetchAndAddWaitFree
argument_list|()
return|;
block|}
end_function
begin_function
name|T
name|fetchAndAddRelaxed
parameter_list|(
name|T
name|valueToAdd
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndAddRelaxed
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_function
name|T
name|fetchAndAddAcquire
parameter_list|(
name|T
name|valueToAdd
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndAddAcquire
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_function
name|T
name|fetchAndAddRelease
parameter_list|(
name|T
name|valueToAdd
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndAddRelease
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_function
name|T
name|fetchAndAddOrdered
parameter_list|(
name|T
name|valueToAdd
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndAddOrdered
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BASIC_ATOMIC_HAS_CONSTRUCTORS
end_ifdef
begin_expr_stmt
name|QBasicAtomicInteger
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|constexpr
name|QBasicAtomicInteger
argument_list|(
name|T
name|value
argument_list|)
name|Q_DECL_NOTHROW
range|:
name|_q_value
argument_list|(
argument|value
argument_list|)
block|{}
name|QBasicAtomicInteger
argument_list|(
specifier|const
name|QBasicAtomicInteger
operator|&
argument_list|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicAtomicInteger
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QBasicAtomicInteger
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicAtomicInteger
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QBasicAtomicInteger
operator|&
operator|)
specifier|volatile
operator|=
name|delete
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|QBasicAtomicInt
unit|};
typedef|typedef
name|QBasicAtomicInteger
operator|<
name|int
operator|>
name|QBasicAtomicInt
expr_stmt|;
end_typedef
begin_expr_stmt
name|template
operator|<
name|typename
name|X
operator|>
name|class
name|QBasicAtomicPointer
block|{
name|public
operator|:
typedef|typedef
name|X
modifier|*
name|Type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QAtomicOps
operator|<
name|Type
operator|>
name|Ops
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|typename
name|Ops
operator|::
name|Type
name|AtomicType
expr_stmt|;
end_typedef
begin_decl_stmt
name|AtomicType
name|_q_value
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Non-atomic API
end_comment
begin_expr_stmt
name|Type
name|load
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|_q_value
return|;
block|}
end_expr_stmt
begin_function
name|void
name|store
parameter_list|(
name|Type
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|_q_value
operator|=
name|newValue
expr_stmt|;
block|}
end_function
begin_comment
comment|// Atomic API, implemented in qatomic_XXX.h
end_comment
begin_expr_stmt
name|Type
name|loadAcquire
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|loadAcquire
argument_list|(
name|_q_value
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|void
name|storeRelease
parameter_list|(
name|Type
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|Ops
operator|::
name|storeRelease
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isTestAndSetNative
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isTestAndSetWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isTestAndSetWaitFree
argument_list|()
return|;
block|}
end_function
begin_function
name|bool
name|testAndSetRelaxed
parameter_list|(
name|Type
name|expectedValue
parameter_list|,
name|Type
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|testAndSetRelaxed
argument_list|(
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
name|bool
name|testAndSetAcquire
parameter_list|(
name|Type
name|expectedValue
parameter_list|,
name|Type
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|testAndSetAcquire
argument_list|(
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
name|bool
name|testAndSetRelease
parameter_list|(
name|Type
name|expectedValue
parameter_list|,
name|Type
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|testAndSetRelease
argument_list|(
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
name|bool
name|testAndSetOrdered
parameter_list|(
name|Type
name|expectedValue
parameter_list|,
name|Type
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|testAndSetOrdered
argument_list|(
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
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isFetchAndStoreNative
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndStoreWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isFetchAndStoreWaitFree
argument_list|()
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndStoreRelaxed
parameter_list|(
name|Type
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreRelaxed
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndStoreAcquire
parameter_list|(
name|Type
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreAcquire
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndStoreRelease
parameter_list|(
name|Type
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreRelease
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndStoreOrdered
parameter_list|(
name|Type
name|newValue
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndStoreOrdered
argument_list|(
name|_q_value
argument_list|,
name|newValue
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndAddNative
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isFetchAndAddNative
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|Q_DECL_CONSTEXPR
name|bool
name|isFetchAndAddWaitFree
parameter_list|()
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|isFetchAndAddWaitFree
argument_list|()
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndAddRelaxed
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndAddRelaxed
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndAddAcquire
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndAddAcquire
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndAddRelease
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndAddRelease
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_function
name|Type
name|fetchAndAddOrdered
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|Ops
operator|::
name|fetchAndAddOrdered
argument_list|(
name|_q_value
argument_list|,
name|valueToAdd
argument_list|)
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BASIC_ATOMIC_HAS_CONSTRUCTORS
end_ifdef
begin_expr_stmt
name|QBasicAtomicPointer
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|constexpr
name|QBasicAtomicPointer
argument_list|(
name|Type
name|value
argument_list|)
name|Q_DECL_NOTHROW
range|:
name|_q_value
argument_list|(
argument|value
argument_list|)
block|{}
name|QBasicAtomicPointer
argument_list|(
specifier|const
name|QBasicAtomicPointer
operator|&
argument_list|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicAtomicPointer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QBasicAtomicPointer
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicAtomicPointer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QBasicAtomicPointer
operator|&
operator|)
specifier|volatile
operator|=
name|delete
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|Q_BASIC_ATOMIC_INITIALIZER
end_ifndef
begin_define
DECL|macro|Q_BASIC_ATOMIC_INITIALIZER
define|#
directive|define
name|Q_BASIC_ATOMIC_INITIALIZER
parameter_list|(
name|a
parameter_list|)
value|{ (a) }
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
comment|// QBASICATOMIC_H
end_comment
end_unit
