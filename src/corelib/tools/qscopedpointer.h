begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSCOPEDPOINTER_H
end_ifndef
begin_define
DECL|macro|QSCOPEDPOINTER_H
define|#
directive|define
name|QSCOPEDPOINTER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|QScopedPointerDeleter
name|QScopedPointerDeleter
block|{
DECL|function|cleanup
specifier|static
specifier|inline
name|void
name|cleanup
argument_list|(
argument|T *pointer
argument_list|)
block|{
comment|// Enforce a complete type.
comment|// If you get a compile error here, read the section on forward declared
comment|// classes in the QScopedPointer documentation.
typedef|typedef
name|char
name|IsIncompleteType
index|[
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|?
literal|1
operator|:
operator|-
literal|1
index|]
typedef|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|IsIncompleteType
argument_list|)
block|;
name|delete
name|pointer
block|;     }
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|QScopedPointerArrayDeleter
name|QScopedPointerArrayDeleter
block|{
DECL|function|cleanup
specifier|static
specifier|inline
name|void
name|cleanup
argument_list|(
argument|T *pointer
argument_list|)
block|{
comment|// Enforce a complete type.
comment|// If you get a compile error here, read the section on forward declared
comment|// classes in the QScopedPointer documentation.
typedef|typedef
name|char
name|IsIncompleteType
index|[
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|?
literal|1
operator|:
operator|-
literal|1
index|]
typedef|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|IsIncompleteType
argument_list|)
block|;
name|delete
index|[]
name|pointer
block|;     }
end_expr_stmt
begin_struct
DECL|struct|QScopedPointerPodDeleter
unit|};
struct|struct
name|QScopedPointerPodDeleter
block|{
DECL|function|cleanup
specifier|static
specifier|inline
name|void
name|cleanup
parameter_list|(
name|void
modifier|*
name|pointer
parameter_list|)
block|{
if|if
condition|(
name|pointer
condition|)
name|free
argument_list|(
name|pointer
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
end_ifndef
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|QScopedPointerObjectDeleteLater
name|QScopedPointerObjectDeleteLater
block|{
DECL|function|cleanup
specifier|static
specifier|inline
name|void
name|cleanup
argument_list|(
argument|T *pointer
argument_list|)
block|{
if|if
condition|(
name|pointer
condition|)
name|pointer
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|function|cleanup
unit|};
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QScopedPointerDeleteLater
typedef|typedef
name|QScopedPointerObjectDeleteLater
operator|<
name|QObject
operator|>
name|QScopedPointerDeleteLater
expr_stmt|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|variable|T
DECL|variable|Cleanup
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Cleanup
operator|=
name|QScopedPointerDeleter
operator|<
name|T
operator|>
expr|>
name|class
name|QScopedPointer
block|{
typedef|typedef
name|T
operator|*
name|QScopedPointer
operator|::
operator|*
name|RestrictedBool
expr_stmt|;
name|public
operator|:
name|explicit
specifier|inline
name|QScopedPointer
argument_list|(
name|T
operator|*
name|p
operator|=
literal|0
argument_list|)
operator|:
name|d
argument_list|(
argument|p
argument_list|)
block|{     }
specifier|inline
operator|~
name|QScopedPointer
argument_list|()
block|{
name|T
operator|*
name|oldD
operator|=
name|this
operator|->
name|d
block|;
name|Cleanup
operator|::
name|cleanup
argument_list|(
name|oldD
argument_list|)
block|;     }
specifier|inline
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|d
argument_list|)
block|;
return|return
operator|*
name|d
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
name|Q_ASSERT
argument_list|(
name|d
argument_list|)
block|;
return|return
name|d
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
name|d
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
end_if
begin_expr_stmt
specifier|inline
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|isNull
argument_list|()
operator|?
literal|0
operator|:
operator|&
name|QScopedPointer
operator|::
name|d
return|;
block|}
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_expr_stmt
specifier|inline
name|operator
name|RestrictedBool
argument_list|()
specifier|const
block|{
return|return
name|isNull
argument_list|()
operator|?
literal|0
operator|:
operator|&
name|QScopedPointer
operator|::
name|d
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
specifier|inline
name|T
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|d
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
operator|!
name|d
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|reset
parameter_list|(
name|T
modifier|*
name|other
init|=
literal|0
parameter_list|)
block|{
if|if
condition|(
name|d
operator|==
name|other
condition|)
return|return;
name|T
modifier|*
name|oldD
init|=
name|d
decl_stmt|;
name|d
operator|=
name|other
expr_stmt|;
name|Cleanup
operator|::
name|cleanup
argument_list|(
name|oldD
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|T
modifier|*
name|take
parameter_list|()
block|{
name|T
modifier|*
name|oldD
init|=
name|d
decl_stmt|;
name|d
operator|=
literal|0
expr_stmt|;
return|return
name|oldD
return|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|void
name|swap
argument_list|(
name|QScopedPointer
operator|<
name|T
argument_list|,
name|Cleanup
operator|>
operator|&
name|other
argument_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_typedef
typedef|typedef
name|T
modifier|*
name|pointer
typedef|;
end_typedef
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|T
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QScopedPointer
argument_list|)
end_macro
begin_expr_stmt
unit|};
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|Cleanup
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QScopedPointer
operator|<
name|T
operator|,
name|Cleanup
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|QScopedPointer
operator|<
name|T
operator|,
name|Cleanup
operator|>
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|data
argument_list|()
operator|==
name|rhs
operator|.
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|Cleanup
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QScopedPointer
operator|<
name|T
operator|,
name|Cleanup
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|QScopedPointer
operator|<
name|T
operator|,
name|Cleanup
operator|>
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|data
argument_list|()
operator|!=
name|rhs
operator|.
name|data
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|,
name|class
name|Cleanup
operator|>
DECL|function|qSwap
name|Q_INLINE_TEMPLATE
name|void
name|qSwap
argument_list|(
argument|QScopedPointer<T
argument_list|,
argument|Cleanup>&p1
argument_list|,
argument|QScopedPointer<T
argument_list|,
argument|Cleanup>&p2
argument_list|)
block|{
name|p1
operator|.
name|swap
argument_list|(
name|p2
argument_list|)
block|; }
name|QT_END_NAMESPACE
name|namespace
name|std
block|{
name|template
operator|<
name|class
name|T
block|,
name|class
name|Cleanup
operator|>
name|Q_INLINE_TEMPLATE
name|void
name|swap
argument_list|(
argument|QT_PREPEND_NAMESPACE(QScopedPointer)<T
argument_list|,
argument|Cleanup>&p1
argument_list|,
argument|QT_PREPEND_NAMESPACE(QScopedPointer)<T
argument_list|,
argument|Cleanup>&p2
argument_list|)
block|{
name|p1
operator|.
name|swap
argument_list|(
name|p2
argument_list|)
block|; }
block|}
name|QT_BEGIN_NAMESPACE
name|namespace
name|QtPrivate
block|{
name|template
operator|<
name|typename
name|X
block|,
name|typename
name|Y
operator|>
expr|struct
name|QScopedArrayEnsureSameType
block|;
name|template
operator|<
name|typename
name|X
operator|>
expr|struct
name|QScopedArrayEnsureSameType
operator|<
name|X
block|,
name|X
operator|>
block|{
typedef|typedef
name|X
modifier|*
name|Type
typedef|;
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|X
operator|>
expr|struct
name|QScopedArrayEnsureSameType
operator|<
specifier|const
name|X
operator|,
name|X
operator|>
block|{
typedef|typedef
name|X
modifier|*
name|Type
typedef|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
unit|}  template
DECL|variable|T
DECL|variable|Cleanup
operator|<
name|typename
name|T
operator|,
name|typename
name|Cleanup
operator|=
name|QScopedPointerArrayDeleter
operator|<
name|T
operator|>
expr|>
name|class
name|QScopedArrayPointer
operator|:
name|public
name|QScopedPointer
operator|<
name|T
operator|,
name|Cleanup
operator|>
block|{
name|public
operator|:
specifier|inline
name|QScopedArrayPointer
argument_list|()
operator|:
name|QScopedPointer
operator|<
name|T
block|,
name|Cleanup
operator|>
operator|(
literal|0
operator|)
block|{}
name|template
operator|<
name|typename
name|D
operator|>
name|explicit
specifier|inline
name|QScopedArrayPointer
argument_list|(
argument|D *p
argument_list|,
argument|typename QtPrivate::QScopedArrayEnsureSameType<T
argument_list|,
argument|D>::Type =
literal|0
argument_list|)
operator|:
name|QScopedPointer
operator|<
name|T
block|,
name|Cleanup
operator|>
operator|(
name|p
operator|)
block|{     }
specifier|inline
name|T
operator|&
name|operator
index|[]
operator|(
name|int
name|i
operator|)
block|{
return|return
name|this
operator|->
name|d
index|[
name|i
index|]
return|;
block|}
specifier|inline
specifier|const
name|T
operator|&
name|operator
index|[]
operator|(
name|int
name|i
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|d
index|[
name|i
index|]
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_function
name|explicit
specifier|inline
name|QScopedArrayPointer
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{
comment|// Enforce the same type.
comment|// If you get a compile error here, make sure you declare
comment|// QScopedArrayPointer with the same template type as you pass to the
comment|// constructor. See also the QScopedPointer documentation.
comment|// Storing a scalar array as a pointer to a different type is not
comment|// allowed and results in undefined behavior.
block|}
end_function
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QScopedArrayPointer
argument_list|)
end_macro
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSCOPEDPOINTER_H
end_comment
end_unit
