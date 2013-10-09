begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Intel Corporation ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QGLOBALSTATIC_H
end_ifndef
begin_define
DECL|macro|QGLOBALSTATIC_H
define|#
directive|define
name|QGLOBALSTATIC_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QtGlobalStatic
block|{
enum|enum
name|GuardValues
block|{
name|Destroyed
init|=
operator|-
literal|2
block|,
name|Initialized
init|=
operator|-
literal|1
block|,
name|Uninitialized
init|=
literal|0
block|,
name|Initializing
init|=
literal|1
block|}
enum|;
block|}
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_THREAD
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|)
end_if
begin_comment
comment|// some compilers support thread-safe statics
end_comment
begin_comment
comment|// The IA-64 C++ ABI requires this, so we know that all GCC versions since 3.4
end_comment
begin_comment
comment|// support it. C++11 also requires this behavior.
end_comment
begin_comment
comment|// Clang and Intel CC masquerade as GCC when compiling on Linux.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Apple's libc++abi however uses a global lock for initializing local statics,
end_comment
begin_comment
comment|// which will block other threads also trying to initialize a local static
end_comment
begin_comment
comment|// until the constructor returns ...
end_comment
begin_comment
comment|// We better avoid these kind of problems by using our own locked implementation.
end_comment
begin_define
DECL|macro|Q_GLOBAL_STATIC_INTERNAL
define|#
directive|define
name|Q_GLOBAL_STATIC_INTERNAL
parameter_list|(
name|ARGS
parameter_list|)
define|\
value|Q_DECL_HIDDEN inline Type *innerFunction()                  \     {                                                           \         struct HolderBase {                                     \             ~HolderBase() Q_DECL_NOTHROW                        \             { if (guard.load() == QtGlobalStatic::Initialized)  \                   guard.store(QtGlobalStatic::Destroyed); }     \         };                                                      \         static struct Holder : public HolderBase {              \             Type value;                                         \             Holder()                                            \                 Q_DECL_NOEXCEPT_EXPR(noexcept(Type ARGS))       \                 : value ARGS                                    \             { guard.store(QtGlobalStatic::Initialized); }       \         } holder;                                               \         return&holder.value;                                   \     }
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|// We don't know if this compiler supports thread-safe global statics
end_comment
begin_comment
comment|// so use our own locked implementation
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
include|#
directive|include
file|<QtCore/qmutex.h>
name|QT_BEGIN_NAMESPACE
DECL|macro|Q_GLOBAL_STATIC_INTERNAL
define|#
directive|define
name|Q_GLOBAL_STATIC_INTERNAL
parameter_list|(
name|ARGS
parameter_list|)
define|\
value|Q_DECL_HIDDEN inline Type *innerFunction()                          \     {                                                                   \         static Type *d;                                                 \         static QBasicMutex mutex;                                       \         int x = guard.loadAcquire();                                    \         if (Q_UNLIKELY(x>= QtGlobalStatic::Uninitialized)) {           \             QMutexLocker locker(&mutex);                                \             if (guard.load() == QtGlobalStatic::Uninitialized) {        \                 d = new Type ARGS;                                      \                 static struct Cleanup {                                 \                     ~Cleanup() {                                        \                         delete d;                                       \                         guard.store(QtGlobalStatic::Destroyed);         \                     }                                                   \                 } cleanup;                                              \                 guard.store(QtGlobalStatic::Initialized);               \             }                                                           \         }                                                               \         return d;                                                       \     }
endif|#
directive|endif
comment|// this class must be POD, unless the compiler supports thread-safe statics
DECL|variable|T
DECL|variable|innerFunction
name|template
operator|<
name|typename
name|T
operator|,
name|T
operator|*
call|(
modifier|&
name|innerFunction
call|)
argument_list|()
operator|,
name|QBasicAtomicInt
operator|&
name|guard
operator|>
expr|struct
DECL|struct|QGlobalStatic
name|QGlobalStatic
block|{
DECL|typedef|Type
typedef|typedef
name|T
name|Type
typedef|;
DECL|function|isDestroyed
name|bool
name|isDestroyed
argument_list|()
specifier|const
block|{
return|return
name|guard
operator|.
name|load
argument_list|()
operator|<=
name|QtGlobalStatic
operator|::
name|Destroyed
return|;
block|}
DECL|function|exists
name|bool
name|exists
argument_list|()
specifier|const
block|{
return|return
name|guard
operator|.
name|load
argument_list|()
operator|==
name|QtGlobalStatic
operator|::
name|Initialized
return|;
block|}
name|operator
name|Type
operator|*
operator|(
operator|)
block|{
if|if
condition|(
name|isDestroyed
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt
begin_return
return|return
name|innerFunction
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}     Type
DECL|function|operator
operator|*
name|operator
argument_list|()
operator|(
operator|)
block|{
if|if
condition|(
name|isDestroyed
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt
begin_return
DECL|function|operator
return|return
name|innerFunction
argument_list|()
return|;
end_return
begin_expr_stmt
DECL|function|operator
unit|}     Type
DECL|function|operator
operator|*
name|operator
operator|->
expr|(
end_expr_stmt
begin_block
unit|)
block|{
name|Q_ASSERT_X
argument_list|(
operator|!
name|isDestroyed
argument_list|()
argument_list|,
literal|"Q_GLOBAL_STATIC"
argument_list|,
literal|"The global static was used after being destroyed"
argument_list|)
expr_stmt|;
return|return
name|innerFunction
argument_list|()
return|;
block|}
end_block
begin_function
name|Type
modifier|&
name|operator
modifier|*
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
operator|!
name|isDestroyed
argument_list|()
argument_list|,
literal|"Q_GLOBAL_STATIC"
argument_list|,
literal|"The global static was used after being destroyed"
argument_list|)
expr_stmt|;
return|return
operator|*
name|innerFunction
argument_list|()
return|;
block|}
end_function
begin_define
DECL|macro|Q_GLOBAL_STATIC_WITH_ARGS
unit|};
define|#
directive|define
name|Q_GLOBAL_STATIC_WITH_ARGS
parameter_list|(
name|TYPE
parameter_list|,
name|NAME
parameter_list|,
name|ARGS
parameter_list|)
define|\
value|namespace { namespace Q_QGS_ ## NAME {                                  \         typedef TYPE Type;                                                  \         QBasicAtomicInt guard = Q_BASIC_ATOMIC_INITIALIZER(QtGlobalStatic::Uninitialized); \         Q_GLOBAL_STATIC_INTERNAL(ARGS)                                      \     } }                                                                     \     static QGlobalStatic<TYPE,                                              \                          Q_QGS_ ## NAME::innerFunction,                     \                          Q_QGS_ ## NAME::guard> NAME;
end_define
begin_define
DECL|macro|Q_GLOBAL_STATIC
define|#
directive|define
name|Q_GLOBAL_STATIC
parameter_list|(
name|TYPE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|Q_GLOBAL_STATIC_WITH_ARGS(TYPE, NAME, ())
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLOBALSTATIC_H
end_comment
end_unit
