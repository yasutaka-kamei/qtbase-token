begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QATOMIC_H
end_ifndef
begin_define
DECL|macro|QATOMIC_H
define|#
directive|define
name|QATOMIC_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbasicatomic.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|>=
literal|406
operator|)
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|push
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wextra"
endif|#
directive|endif
comment|// High-level atomic integer operations
name|class
name|Q_CORE_EXPORT
name|QAtomicInt
range|:
name|public
name|QBasicAtomicInt
block|{
name|public
operator|:
comment|// Non-atomic API
specifier|inline
name|QAtomicInt
argument_list|(
argument|int value =
literal|0
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_ARCH_PARISC
name|this
operator|->
name|_q_lock
index|[
literal|0
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|1
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|2
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|3
index|]
operator|=
operator|-
literal|1
block|;
endif|#
directive|endif
name|_q_value
operator|=
name|value
block|;     }
specifier|inline
name|QAtomicInt
argument_list|(
argument|const QAtomicInt&other
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_ARCH_PARISC
name|this
operator|->
name|_q_lock
index|[
literal|0
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|1
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|2
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|3
index|]
operator|=
operator|-
literal|1
block|;
endif|#
directive|endif
name|store
argument_list|(
name|other
operator|.
name|load
argument_list|()
argument_list|)
block|;     }
specifier|inline
name|QAtomicInt
operator|&
name|operator
operator|=
operator|(
name|int
name|value
operator|)
block|{
name|this
operator|->
name|store
argument_list|(
name|value
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QAtomicInt
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QAtomicInt
operator|&
name|other
operator|)
block|{
name|this
operator|->
name|store
argument_list|(
name|other
operator|.
name|load
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|int
name|value
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|load
argument_list|()
operator|==
name|value
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|int
name|value
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|load
argument_list|()
operator|!=
name|value
return|;
block|}
specifier|inline
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|load
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
operator|!
name|this
operator|->
name|load
argument_list|()
return|;
block|}
ifdef|#
directive|ifdef
name|qdoc
specifier|static
name|bool
name|isReferenceCountingNative
argument_list|()
block|;
specifier|static
name|bool
name|isReferenceCountingWaitFree
argument_list|()
block|;
name|bool
name|ref
argument_list|()
block|;
name|bool
name|deref
argument_list|()
block|;
specifier|static
name|bool
name|isTestAndSetNative
argument_list|()
block|;
specifier|static
name|bool
name|isTestAndSetWaitFree
argument_list|()
block|;
name|bool
name|testAndSetRelaxed
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|;
name|bool
name|testAndSetAcquire
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|;
name|bool
name|testAndSetRelease
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|;
name|bool
name|testAndSetOrdered
argument_list|(
argument|int expectedValue
argument_list|,
argument|int newValue
argument_list|)
block|;
specifier|static
name|bool
name|isFetchAndStoreNative
argument_list|()
block|;
specifier|static
name|bool
name|isFetchAndStoreWaitFree
argument_list|()
block|;
name|int
name|fetchAndStoreRelaxed
argument_list|(
argument|int newValue
argument_list|)
block|;
name|int
name|fetchAndStoreAcquire
argument_list|(
argument|int newValue
argument_list|)
block|;
name|int
name|fetchAndStoreRelease
argument_list|(
argument|int newValue
argument_list|)
block|;
name|int
name|fetchAndStoreOrdered
argument_list|(
argument|int newValue
argument_list|)
block|;
specifier|static
name|bool
name|isFetchAndAddNative
argument_list|()
block|;
specifier|static
name|bool
name|isFetchAndAddWaitFree
argument_list|()
block|;
name|int
name|fetchAndAddRelaxed
argument_list|(
argument|int valueToAdd
argument_list|)
block|;
name|int
name|fetchAndAddAcquire
argument_list|(
argument|int valueToAdd
argument_list|)
block|;
name|int
name|fetchAndAddRelease
argument_list|(
argument|int valueToAdd
argument_list|)
block|;
name|int
name|fetchAndAddOrdered
argument_list|(
argument|int valueToAdd
argument_list|)
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// High-level atomic pointer operations
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QAtomicPointer
operator|:
name|public
name|QBasicAtomicPointer
operator|<
name|T
operator|>
block|{
name|public
operator|:
specifier|inline
name|QAtomicPointer
argument_list|(
argument|T *value =
literal|0
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_ARCH_PARISC
name|this
operator|->
name|_q_lock
index|[
literal|0
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|1
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|2
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|3
index|]
operator|=
operator|-
literal|1
block|;
endif|#
directive|endif
name|store
argument_list|(
name|value
argument_list|)
block|;     }
specifier|inline
name|QAtomicPointer
argument_list|(
argument|const QAtomicPointer<T>&other
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_ARCH_PARISC
name|this
operator|->
name|_q_lock
index|[
literal|0
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|1
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|2
index|]
operator|=
name|this
operator|->
name|_q_lock
index|[
literal|3
index|]
operator|=
operator|-
literal|1
block|;
endif|#
directive|endif
name|store
argument_list|(
name|other
operator|.
name|load
argument_list|()
argument_list|)
block|;     }
specifier|inline
name|QAtomicPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
name|T
operator|*
name|value
operator|)
block|{
name|this
operator|->
name|store
argument_list|(
name|value
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QAtomicPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QAtomicPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|{
name|this
operator|->
name|store
argument_list|(
name|other
operator|.
name|load
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|T
operator|*
name|value
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|load
argument_list|()
operator|==
name|value
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|T
operator|*
name|value
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|load
argument_list|()
operator|!=
name|value
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
operator|!
name|this
operator|->
name|load
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|operator
name|T
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|load
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|T
operator|*
name|operator
operator|->
expr|(
end_expr_stmt
begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|this
operator|->
name|load
argument_list|()
return|;
block|}
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|qdoc
end_ifdef
begin_function_decl
specifier|static
name|bool
name|isTestAndSetNative
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isTestAndSetWaitFree
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|testAndSetRelaxed
parameter_list|(
name|T
modifier|*
name|expectedValue
parameter_list|,
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|testAndSetAcquire
parameter_list|(
name|T
modifier|*
name|expectedValue
parameter_list|,
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|testAndSetRelease
parameter_list|(
name|T
modifier|*
name|expectedValue
parameter_list|,
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|testAndSetOrdered
parameter_list|(
name|T
modifier|*
name|expectedValue
parameter_list|,
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isFetchAndStoreNative
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isFetchAndStoreWaitFree
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndStoreRelaxed
parameter_list|(
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndStoreAcquire
parameter_list|(
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndStoreRelease
parameter_list|(
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndStoreOrdered
parameter_list|(
name|T
modifier|*
name|newValue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isFetchAndAddNative
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isFetchAndAddWaitFree
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndAddRelaxed
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndAddAcquire
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndAddRelease
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|T
modifier|*
name|fetchAndAddOrdered
parameter_list|(
name|qptrdiff
name|valueToAdd
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_if
unit|};
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|*
literal|100
operator|+
name|__GNUC_MINOR__
operator|>=
literal|406
operator|)
end_if
begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|pop
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     This is a helper for the assignment operators of implicitly     shared classes. Your assignment operator should look like this:      \snippet doc/src/snippets/code/src.corelib.thread.qatomic.h 0 */
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qAtomicAssign
specifier|inline
name|void
name|qAtomicAssign
argument_list|(
argument|T *&d
argument_list|,
argument|T *x
argument_list|)
block|{
if|if
condition|(
name|d
operator|==
name|x
condition|)
return|return;
name|x
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|d
decl_stmt|;
end_if
begin_expr_stmt
name|d
operator|=
name|x
expr_stmt|;
end_expr_stmt
begin_comment
unit|}
comment|/*!     This is a helper for the detach method of implicitly shared     classes. Your private class needs a copy constructor which copies     the members and sets the refcount to 1. After that, your detach     function should look like this:      \snippet doc/src/snippets/code/src.corelib.thread.qatomic.h 1 */
end_comment
begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
DECL|function|qAtomicDetach
specifier|inline
name|void
name|qAtomicDetach
argument_list|(
argument|T *&d
argument_list|)
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|==
literal|1
condition|)
return|return;
name|T
operator|*
name|x
operator|=
name|d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|d
operator|=
name|new
name|T
argument_list|(
operator|*
name|d
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|x
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|x
decl_stmt|;
end_if
begin_macro
unit|}  QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QATOMIC_H
end_comment
end_unit
