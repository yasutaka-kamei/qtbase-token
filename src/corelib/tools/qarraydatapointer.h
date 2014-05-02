begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QARRAYDATAPOINTER_H
end_ifndef
begin_define
DECL|macro|QARRAYDATAPOINTER_H
define|#
directive|define
name|QARRAYDATAPOINTER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qarraydataops.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|template
operator|<
name|class
name|T
operator|>
expr|struct
DECL|struct|QArrayDataPointer
name|QArrayDataPointer
block|{
DECL|member|private
name|private
operator|:
typedef|typedef
name|QTypedArrayData
operator|<
name|T
operator|>
name|Data
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|DataOps
typedef|typedef
name|QArrayDataOps
operator|<
name|T
operator|>
name|DataOps
expr_stmt|;
end_typedef
begin_label
DECL|member|public
name|public
label|:
end_label
begin_expr_stmt
name|QArrayDataPointer
argument_list|()
operator|:
name|d
argument_list|(
argument|Data::sharedNull()
argument_list|)
block|{     }
name|QArrayDataPointer
argument_list|(
specifier|const
name|QArrayDataPointer
operator|&
name|other
argument_list|)
operator|:
name|d
argument_list|(
argument|other.d->ref.ref()             ? other.d             : other.clone(other.d->cloneFlags())
argument_list|)
block|{     }
name|explicit
name|QArrayDataPointer
argument_list|(
name|QTypedArrayData
operator|<
name|T
operator|>
operator|*
name|ptr
argument_list|)
operator|:
name|d
argument_list|(
argument|ptr
argument_list|)
block|{
name|Q_CHECK_PTR
argument_list|(
name|ptr
argument_list|)
block|;     }
name|QArrayDataPointer
argument_list|(
name|QArrayDataPointerRef
operator|<
name|T
operator|>
name|ref
argument_list|)
DECL|function|d
operator|:
name|d
argument_list|(
argument|ref.ptr
argument_list|)
block|{     }
DECL|variable|operator
name|QArrayDataPointer
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QArrayDataPointer
operator|&
name|other
operator|)
block|{
name|QArrayDataPointer
name|tmp
argument_list|(
name|other
argument_list|)
block|;
name|this
operator|->
name|swap
argument_list|(
name|tmp
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_expr_stmt
name|QArrayDataPointer
argument_list|(
name|QArrayDataPointer
operator|&&
name|other
argument_list|)
operator|:
name|d
argument_list|(
argument|other.d
argument_list|)
block|{
name|other
operator|.
name|d
operator|=
name|Data
operator|::
name|sharedNull
argument_list|()
block|;     }
name|QArrayDataPointer
operator|&
name|operator
operator|=
operator|(
name|QArrayDataPointer
operator|&&
name|other
operator|)
block|{
name|this
operator|->
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|DataOps
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
name|static_cast
operator|<
name|DataOps
operator|*
operator|>
operator|(
name|d
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|DataOps
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
name|static_cast
operator|<
name|DataOps
operator|*
operator|>
operator|(
name|d
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
operator|~
name|QArrayDataPointer
argument_list|()
block|{
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
block|{
if|if
condition|(
name|d
operator|->
name|isMutable
argument_list|()
condition|)
operator|(
operator|*
name|this
operator|)
operator|->
name|destroyAll
argument_list|()
expr_stmt|;
name|Data
operator|::
name|deallocate
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_macro
unit|}      bool
name|isNull
argument_list|()
end_macro
begin_expr_stmt
specifier|const
block|{
return|return
name|d
operator|==
name|Data
operator|::
name|sharedNull
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Data
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
name|bool
name|needsDetach
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|!
name|d
operator|->
name|isMutable
argument_list|()
operator|||
name|d
operator|->
name|ref
operator|.
name|isShared
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
name|QT_SUPPORTS
argument_list|(
name|UNSHARABLE_CONTAINERS
argument_list|)
end_if
begin_function
name|void
name|setSharable
parameter_list|(
name|bool
name|sharable
parameter_list|)
block|{
if|if
condition|(
name|needsDetach
argument_list|()
condition|)
block|{
name|Data
modifier|*
name|detached
init|=
name|clone
argument_list|(
name|sharable
condition|?
name|d
operator|->
name|detachFlags
argument_list|()
operator|&
operator|~
name|QArrayData
operator|::
name|Unsharable
else|:
name|d
operator|->
name|detachFlags
argument_list|()
operator||
name|QArrayData
operator|::
name|Unsharable
argument_list|)
decl_stmt|;
name|QArrayDataPointer
name|old
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|d
operator|=
name|detached
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|ref
operator|.
name|setSharable
argument_list|(
name|sharable
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_expr_stmt
name|bool
name|isSharable
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|isSharable
argument_list|()
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|void
name|swap
parameter_list|(
name|QArrayDataPointer
modifier|&
name|other
parameter_list|)
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
end_function
begin_function
name|void
name|clear
parameter_list|()
block|{
name|QArrayDataPointer
name|tmp
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|d
operator|=
name|Data
operator|::
name|sharedNull
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
name|bool
name|detach
parameter_list|()
block|{
if|if
condition|(
name|needsDetach
argument_list|()
condition|)
block|{
name|Data
modifier|*
name|copy
init|=
name|clone
argument_list|(
name|d
operator|->
name|detachFlags
argument_list|()
argument_list|)
decl_stmt|;
name|QArrayDataPointer
name|old
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|d
operator|=
name|copy
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|Data
modifier|*
name|clone
argument_list|(
name|QArrayData
operator|::
name|AllocationOptions
name|options
argument_list|)
decl|const
name|Q_REQUIRED_RESULT
block|{
name|QArrayDataPointer
name|copy
argument_list|(
name|Data
operator|::
name|allocate
argument_list|(
name|d
operator|->
name|detachCapacity
argument_list|(
name|d
operator|->
name|size
argument_list|)
argument_list|,
name|options
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|size
condition|)
name|copy
operator|->
name|copyAppend
argument_list|(
name|d
operator|->
name|begin
argument_list|()
argument_list|,
name|d
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|Data
modifier|*
name|result
init|=
name|copy
operator|.
name|d
decl_stmt|;
name|copy
operator|.
name|d
operator|=
name|Data
operator|::
name|sharedNull
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Data
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QArrayDataPointer
operator|<
name|T
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|QArrayDataPointer
operator|<
name|T
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
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QArrayDataPointer
operator|<
name|T
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|QArrayDataPointer
operator|<
name|T
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
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|void
name|qSwap
argument_list|(
argument|QArrayDataPointer<T>&p1
argument_list|,
argument|QArrayDataPointer<T>&p2
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
operator|>
specifier|inline
name|void
name|swap
argument_list|(
argument|QT_PREPEND_NAMESPACE(QArrayDataPointer)<T>&p1
argument_list|,
argument|QT_PREPEND_NAMESPACE(QArrayDataPointer)<T>&p2
argument_list|)
block|{
name|p1
operator|.
name|swap
argument_list|(
name|p2
argument_list|)
block|;     }
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// include guard
end_comment
end_unit
