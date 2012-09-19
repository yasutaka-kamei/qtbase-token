begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSHAREDDATA_H
end_ifndef
begin_define
DECL|macro|QSHAREDDATA_H
define|#
directive|define
name|QSHAREDDATA_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QSharedDataPointer
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QSharedDataPointer
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSharedData
block|{
name|public
label|:
name|mutable
name|QAtomicInt
name|ref
decl_stmt|;
specifier|inline
name|QSharedData
argument_list|()
operator|:
name|ref
argument_list|(
literal|0
argument_list|)
block|{ }
specifier|inline
name|QSharedData
argument_list|(
specifier|const
name|QSharedData
operator|&
argument_list|)
operator|:
name|ref
argument_list|(
literal|0
argument_list|)
block|{ }
name|private
operator|:
comment|// using the assignment operator would lead to corruption in the ref-counting
name|QSharedData
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QSharedData
operator|&
operator|)
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QSharedDataPointer
block|{
name|public
operator|:
typedef|typedef
name|T
name|Type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|T
modifier|*
name|pointer
typedef|;
end_typedef
begin_function
specifier|inline
name|void
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|&&
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
name|detach_helper
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|T
modifier|&
name|operator
modifier|*
parameter_list|()
block|{
name|detach
argument_list|()
expr_stmt|;
return|return
operator|*
name|d
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
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
begin_block
unit|)
block|{
name|detach
argument_list|()
expr_stmt|;
return|return
name|d
return|;
block|}
end_block
begin_expr_stmt
specifier|inline
specifier|const
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
name|d
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|operator
name|T
modifier|*
parameter_list|()
block|{
name|detach
argument_list|()
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|operator
specifier|const
name|T
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|d
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|T
modifier|*
name|data
parameter_list|()
block|{
name|detach
argument_list|()
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
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
specifier|const
name|T
operator|*
name|constData
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
name|operator
operator|==
operator|(
specifier|const
name|QSharedDataPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|d
operator|==
name|other
operator|.
name|d
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSharedDataPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|d
operator|!=
name|other
operator|.
name|d
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSharedDataPointer
argument_list|()
block|{
name|d
operator|=
literal|0
block|; }
specifier|inline
operator|~
name|QSharedDataPointer
argument_list|()
block|{
if|if
condition|(
name|d
operator|&&
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
block|}
end_expr_stmt
begin_function_decl
name|explicit
name|QSharedDataPointer
parameter_list|(
name|T
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|QSharedDataPointer
argument_list|(
specifier|const
name|QSharedDataPointer
operator|<
name|T
operator|>
operator|&
name|o
argument_list|)
operator|:
name|d
argument_list|(
argument|o.d
argument_list|)
block|{
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSharedDataPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QSharedDataPointer
operator|<
name|T
operator|>
operator|&
name|o
operator|)
block|{
if|if
condition|(
name|o
operator|.
name|d
operator|!=
name|d
condition|)
block|{
if|if
condition|(
name|o
operator|.
name|d
condition|)
name|o
operator|.
name|d
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
name|T
modifier|*
name|old
init|=
name|d
decl_stmt|;
name|d
operator|=
name|o
operator|.
name|d
expr_stmt|;
if|if
condition|(
name|old
operator|&&
operator|!
name|old
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|old
decl_stmt|;
block|}
end_expr_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_decl_stmt
unit|}     inline
name|QSharedDataPointer
modifier|&
name|operator
init|=
operator|(
name|T
operator|*
name|o
operator|)
block|{
if|if
condition|(
name|o
operator|!=
name|d
condition|)
block|{
if|if
condition|(
name|o
condition|)
name|o
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
name|T
modifier|*
name|old
init|=
name|d
decl_stmt|;
name|d
operator|=
name|o
expr_stmt|;
if|if
condition|(
name|old
operator|&&
operator|!
name|old
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|old
decl_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_expr_stmt
name|QSharedDataPointer
argument_list|(
name|QSharedDataPointer
operator|&&
name|o
argument_list|)
operator|:
name|d
argument_list|(
argument|o.d
argument_list|)
block|{
name|o
operator|.
name|d
operator|=
literal|0
block|; }
specifier|inline
name|QSharedDataPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
name|QSharedDataPointer
operator|<
name|T
operator|>
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
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
begin_function
specifier|inline
name|void
name|swap
parameter_list|(
name|QSharedDataPointer
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
begin_label
name|protected
label|:
end_label
begin_function_decl
name|T
modifier|*
name|clone
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|detach_helper
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|T
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
name|class
name|QExplicitlySharedDataPointer
block|{
name|public
operator|:
typedef|typedef
name|T
name|Type
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|T
modifier|*
name|pointer
typedef|;
end_typedef
begin_expr_stmt
specifier|inline
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
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
begin_block
unit|)
block|{
return|return
name|d
return|;
block|}
end_block
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
name|d
return|;
block|}
end_expr_stmt
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
specifier|const
name|T
operator|*
name|constData
argument_list|()
specifier|const
block|{
return|return
name|d
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|&&
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
name|detach_helper
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|reset
parameter_list|()
block|{
if|if
condition|(
name|d
operator|&&
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
name|d
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|d
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|d
operator|==
name|other
operator|.
name|d
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|d
operator|!=
name|other
operator|.
name|d
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|T
operator|*
name|ptr
operator|)
specifier|const
block|{
return|return
name|d
operator|==
name|ptr
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|T
operator|*
name|ptr
operator|)
specifier|const
block|{
return|return
name|d
operator|!=
name|ptr
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QExplicitlySharedDataPointer
argument_list|()
block|{
name|d
operator|=
literal|0
block|; }
specifier|inline
operator|~
name|QExplicitlySharedDataPointer
argument_list|()
block|{
if|if
condition|(
name|d
operator|&&
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
block|}
end_expr_stmt
begin_function_decl
name|explicit
name|QExplicitlySharedDataPointer
parameter_list|(
name|T
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|QExplicitlySharedDataPointer
argument_list|(
specifier|const
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
operator|&
name|o
argument_list|)
operator|:
name|d
argument_list|(
argument|o.d
argument_list|)
block|{
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|X
operator|>
specifier|inline
name|QExplicitlySharedDataPointer
argument_list|(
specifier|const
name|QExplicitlySharedDataPointer
operator|<
name|X
operator|>
operator|&
name|o
argument_list|)
operator|:
name|d
argument_list|(
argument|static_cast<T *>(o.data())
argument_list|)
block|{
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
operator|&
name|o
operator|)
block|{
if|if
condition|(
name|o
operator|.
name|d
operator|!=
name|d
condition|)
block|{
if|if
condition|(
name|o
operator|.
name|d
condition|)
name|o
operator|.
name|d
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
name|T
modifier|*
name|old
init|=
name|d
decl_stmt|;
name|d
operator|=
name|o
operator|.
name|d
expr_stmt|;
if|if
condition|(
name|old
operator|&&
operator|!
name|old
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|old
decl_stmt|;
block|}
end_expr_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_decl_stmt
unit|}     inline
name|QExplicitlySharedDataPointer
modifier|&
name|operator
init|=
operator|(
name|T
operator|*
name|o
operator|)
block|{
if|if
condition|(
name|o
operator|!=
name|d
condition|)
block|{
if|if
condition|(
name|o
condition|)
name|o
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
name|T
modifier|*
name|old
init|=
name|d
decl_stmt|;
name|d
operator|=
name|o
expr_stmt|;
if|if
condition|(
name|old
operator|&&
operator|!
name|old
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|old
decl_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_expr_stmt
specifier|inline
name|QExplicitlySharedDataPointer
argument_list|(
name|QExplicitlySharedDataPointer
operator|&&
name|o
argument_list|)
operator|:
name|d
argument_list|(
argument|o.d
argument_list|)
block|{
name|o
operator|.
name|d
operator|=
literal|0
block|; }
specifier|inline
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
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
begin_function
specifier|inline
name|void
name|swap
parameter_list|(
name|QExplicitlySharedDataPointer
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
begin_label
name|protected
label|:
end_label
begin_function_decl
name|T
modifier|*
name|clone
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|detach_helper
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|T
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
DECL|function|QSharedDataPointer
name|Q_INLINE_TEMPLATE
name|QSharedDataPointer
operator|<
name|T
operator|>
operator|::
name|QSharedDataPointer
argument_list|(
name|T
operator|*
name|adata
argument_list|)
operator|:
name|d
argument_list|(
argument|adata
argument_list|)
block|{
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|clone
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QSharedDataPointer
operator|<
name|T
operator|>
operator|::
name|clone
argument_list|()
block|{
return|return
name|new
name|T
argument_list|(
operator|*
name|d
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|detach_helper
name|Q_OUTOFLINE_TEMPLATE
name|void
name|QSharedDataPointer
operator|<
name|T
operator|>
operator|::
name|detach_helper
argument_list|()
block|{
name|T
operator|*
name|x
operator|=
name|clone
argument_list|()
block|;
name|x
operator|->
name|ref
operator|.
name|ref
argument_list|()
block|;
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
name|d
operator|=
name|x
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|clone
name|Q_INLINE_TEMPLATE
name|T
operator|*
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
operator|::
name|clone
argument_list|()
block|{
return|return
name|new
name|T
argument_list|(
operator|*
name|d
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|detach_helper
name|Q_OUTOFLINE_TEMPLATE
name|void
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
operator|::
name|detach_helper
argument_list|()
block|{
name|T
operator|*
name|x
operator|=
name|clone
argument_list|()
block|;
name|x
operator|->
name|ref
operator|.
name|ref
argument_list|()
block|;
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
name|d
operator|=
name|x
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|QExplicitlySharedDataPointer
name|Q_INLINE_TEMPLATE
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
operator|::
name|QExplicitlySharedDataPointer
argument_list|(
name|T
operator|*
name|adata
argument_list|)
operator|:
name|d
argument_list|(
argument|adata
argument_list|)
block|{
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|void
name|qSwap
argument_list|(
argument|QSharedDataPointer<T>&p1
argument_list|,
argument|QSharedDataPointer<T>&p2
argument_list|)
block|{
name|p1
operator|.
name|swap
argument_list|(
name|p2
argument_list|)
block|; }
name|template
operator|<
name|class
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|void
name|qSwap
argument_list|(
argument|QExplicitlySharedDataPointer<T>&p1
argument_list|,
argument|QExplicitlySharedDataPointer<T>&p2
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
name|Q_INLINE_TEMPLATE
name|void
name|swap
argument_list|(
argument|QT_PREPEND_NAMESPACE(QSharedDataPointer)<T>&p1
argument_list|,
argument|QT_PREPEND_NAMESPACE(QSharedDataPointer)<T>&p2
argument_list|)
block|{
name|p1
operator|.
name|swap
argument_list|(
name|p2
argument_list|)
block|; }
name|template
operator|<
name|class
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|void
name|swap
argument_list|(
argument|QT_PREPEND_NAMESPACE(QExplicitlySharedDataPointer)<T>&p1
argument_list|,
argument|QT_PREPEND_NAMESPACE(QExplicitlySharedDataPointer)<T>&p2
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
name|template
operator|<
name|typename
name|T
operator|>
name|Q_DECLARE_TYPEINFO_BODY
argument_list|(
name|QSharedDataPointer
operator|<
name|T
operator|>
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_DECLARE_TYPEINFO_BODY
argument_list|(
name|QExplicitlySharedDataPointer
operator|<
name|T
operator|>
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSHAREDDATA_H
end_comment
end_unit
