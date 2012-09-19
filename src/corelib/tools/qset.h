begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSET_H
end_ifndef
begin_define
DECL|macro|QSET_H
define|#
directive|define
name|QSET_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QSet
block|{
typedef|typedef
name|QHash
operator|<
name|T
operator|,
name|QHashDummyValue
operator|>
name|Hash
expr_stmt|;
name|public
operator|:
specifier|inline
name|QSet
argument_list|()
block|{}
specifier|inline
name|QSet
argument_list|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
operator|:
name|q_hash
argument_list|(
argument|other.q_hash
argument_list|)
block|{}
specifier|inline
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|{
name|q_hash
operator|=
name|other
operator|.
name|q_hash
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
specifier|inline
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
name|QSet
operator|<
name|T
operator|>
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|q_hash
argument_list|,
name|other
operator|.
name|q_hash
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
begin_decl_stmt
specifier|inline
name|void
name|swap
argument_list|(
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
block|{
name|q_hash
operator|.
name|swap
argument_list|(
name|other
operator|.
name|q_hash
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|q_hash
operator|==
name|other
operator|.
name|q_hash
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
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|q_hash
operator|!=
name|other
operator|.
name|q_hash
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|capacity
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|capacity
argument_list|()
return|;
block|}
end_expr_stmt
begin_function_decl
specifier|inline
name|void
name|reserve
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|void
name|squeeze
parameter_list|()
block|{
name|q_hash
operator|.
name|squeeze
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|detach
parameter_list|()
block|{
name|q_hash
operator|.
name|detach
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|bool
name|isDetached
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|isDetached
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|setSharable
parameter_list|(
name|bool
name|sharable
parameter_list|)
block|{
name|q_hash
operator|.
name|setSharable
argument_list|(
name|sharable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|clear
parameter_list|()
block|{
name|q_hash
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|remove
parameter_list|(
specifier|const
name|T
modifier|&
name|value
parameter_list|)
block|{
return|return
name|q_hash
operator|.
name|remove
argument_list|(
name|value
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|bool
name|contains
argument_list|(
specifier|const
name|T
operator|&
name|value
argument_list|)
decl|const
block|{
return|return
name|q_hash
operator|.
name|contains
argument_list|(
name|value
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|bool
name|contains
argument_list|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|set
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|const_iterator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|iterator
block|{
typedef|typedef
name|QHash
operator|<
name|T
operator|,
name|QHashDummyValue
operator|>
name|Hash
expr_stmt|;
name|typename
name|Hash
operator|::
name|iterator
name|i
expr_stmt|;
name|friend
name|class
name|const_iterator
decl_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|bidirectional_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|qptrdiff
name|difference_type
typedef|;
typedef|typedef
name|T
name|value_type
typedef|;
typedef|typedef
specifier|const
name|T
modifier|*
name|pointer
typedef|;
typedef|typedef
specifier|const
name|T
modifier|&
name|reference
typedef|;
specifier|inline
name|iterator
argument_list|()
block|{}
specifier|inline
name|iterator
argument_list|(
argument|typename Hash::iterator o
argument_list|)
operator|:
name|i
argument_list|(
argument|o
argument_list|)
block|{}
specifier|inline
name|iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|o
argument_list|)
operator|:
name|i
argument_list|(
argument|o.i
argument_list|)
block|{}
specifier|inline
name|iterator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
block|{
name|i
operator|=
name|o
operator|.
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
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
name|i
operator|.
name|key
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|T
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|i
operator|.
name|key
argument_list|()
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|o
operator|.
name|i
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
name|iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|o
operator|.
name|i
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
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|o
operator|.
name|i
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
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|o
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|iterator
name|r
operator|=
operator|*
name|this
block|;
operator|++
name|i
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|iterator
name|r
operator|=
operator|*
name|this
block|;
operator|--
name|i
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|+
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|i
operator|+
name|j
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
name|operator
operator|-
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|i
operator|-
name|j
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|+=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|+=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|iterator
operator|&
name|operator
operator|-=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|-=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_decl_stmt
unit|};
name|class
name|const_iterator
block|{
typedef|typedef
name|QHash
operator|<
name|T
operator|,
name|QHashDummyValue
operator|>
name|Hash
expr_stmt|;
name|typename
name|Hash
operator|::
name|const_iterator
name|i
expr_stmt|;
name|friend
name|class
name|iterator
decl_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|bidirectional_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|qptrdiff
name|difference_type
typedef|;
typedef|typedef
name|T
name|value_type
typedef|;
typedef|typedef
specifier|const
name|T
modifier|*
name|pointer
typedef|;
typedef|typedef
specifier|const
name|T
modifier|&
name|reference
typedef|;
specifier|inline
name|const_iterator
argument_list|()
block|{}
specifier|inline
name|const_iterator
argument_list|(
argument|typename Hash::const_iterator o
argument_list|)
operator|:
name|i
argument_list|(
argument|o
argument_list|)
block|{}
specifier|inline
name|const_iterator
argument_list|(
specifier|const
name|const_iterator
operator|&
name|o
argument_list|)
operator|:
name|i
argument_list|(
argument|o.i
argument_list|)
block|{}
specifier|inline
name|const_iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|o
argument_list|)
operator|:
name|i
argument_list|(
argument|o.i
argument_list|)
block|{}
specifier|inline
name|const_iterator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
block|{
name|i
operator|=
name|o
operator|.
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
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
name|i
operator|.
name|key
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|T
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|i
operator|.
name|key
argument_list|()
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|o
operator|.
name|i
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
name|const_iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|i
operator|!=
name|o
operator|.
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|const_iterator
name|r
operator|=
operator|*
name|this
block|;
operator|++
name|i
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|const_iterator
name|r
operator|=
operator|*
name|this
block|;
operator|--
name|i
block|;
return|return
name|r
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|+
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|i
operator|+
name|j
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|operator
operator|-
operator|(
name|int
name|j
operator|)
specifier|const
block|{
return|return
name|i
operator|-
name|j
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|+=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|+=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
operator|&
name|operator
operator|-=
operator|(
name|int
name|j
operator|)
block|{
name|i
operator|-=
name|j
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_comment
unit|};
comment|// STL style
end_comment
begin_function
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|q_hash
operator|.
name|begin
argument_list|()
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|cbegin
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|constBegin
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|constBegin
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
return|return
name|q_hash
operator|.
name|end
argument_list|()
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|cend
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|const_iterator
name|constEnd
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|constEnd
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|i
parameter_list|)
block|{
return|return
name|q_hash
operator|.
name|erase
argument_list|(
argument|reinterpret_cast<typename Hash::iterator&>(i)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// more Qt
end_comment
begin_typedef
typedef|typedef
name|iterator
name|Iterator
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|const_iterator
name|ConstIterator
typedef|;
end_typedef
begin_expr_stmt
specifier|inline
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
name|q_hash
operator|.
name|count
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|iterator
name|insert
parameter_list|(
specifier|const
name|T
modifier|&
name|value
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|typename
name|Hash
operator|::
name|iterator
operator|>
operator|(
name|q_hash
operator|.
name|insert
argument_list|(
name|value
argument_list|,
name|QHashDummyValue
argument_list|()
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
name|iterator
name|find
parameter_list|(
specifier|const
name|T
modifier|&
name|value
parameter_list|)
block|{
return|return
name|q_hash
operator|.
name|find
argument_list|(
name|value
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|const_iterator
name|find
argument_list|(
specifier|const
name|T
operator|&
name|value
argument_list|)
decl|const
block|{
return|return
name|q_hash
operator|.
name|find
argument_list|(
name|value
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|const_iterator
name|constFind
argument_list|(
specifier|const
name|T
operator|&
name|value
argument_list|)
decl|const
block|{
return|return
name|find
argument_list|(
name|value
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|QSet
operator|<
name|T
operator|>
operator|&
name|unite
argument_list|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSet
operator|<
name|T
operator|>
operator|&
name|intersect
argument_list|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSet
operator|<
name|T
operator|>
operator|&
name|subtract
argument_list|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// STL compatibility
end_comment
begin_typedef
typedef|typedef
name|T
name|key_type
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|T
name|value_type
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|value_type
modifier|*
name|pointer
typedef|;
end_typedef
begin_typedef
typedef|typedef
specifier|const
name|value_type
modifier|*
name|const_pointer
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|value_type
modifier|&
name|reference
typedef|;
end_typedef
begin_typedef
typedef|typedef
specifier|const
name|value_type
modifier|&
name|const_reference
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|qptrdiff
name|difference_type
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|size_type
typedef|;
end_typedef
begin_expr_stmt
specifier|inline
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_comment
comment|// comfort
end_comment
begin_expr_stmt
specifier|inline
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
name|value
operator|)
block|{
name|insert
argument_list|(
name|value
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
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator||=
operator|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|{
name|unite
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
begin_expr_stmt
specifier|inline
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator||=
operator|(
specifier|const
name|T
operator|&
name|value
operator|)
block|{
name|insert
argument_list|(
name|value
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
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator|&=
operator|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|{
name|intersect
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
begin_expr_stmt
specifier|inline
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator|&=
operator|(
specifier|const
name|T
operator|&
name|value
operator|)
block|{
name|QSet
operator|<
name|T
operator|>
name|result
block|;
if|if
condition|(
name|contains
argument_list|(
name|value
argument_list|)
condition|)
name|result
operator|.
name|insert
argument_list|(
name|value
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
operator|(
operator|*
name|this
operator|=
name|result
operator|)
return|;
end_return
begin_expr_stmt
unit|}     inline
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|{
name|unite
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
begin_expr_stmt
specifier|inline
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|T
operator|&
name|value
operator|)
block|{
name|insert
argument_list|(
name|value
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
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
block|{
name|subtract
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
begin_expr_stmt
specifier|inline
name|QSet
operator|<
name|T
operator|>
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|T
operator|&
name|value
operator|)
block|{
name|remove
argument_list|(
name|value
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
name|QSet
operator|<
name|T
operator|>
name|operator
operator||
operator|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
name|QSet
operator|<
name|T
operator|>
name|result
operator|=
operator|*
name|this
block|;
name|result
operator||=
name|other
block|;
return|return
name|result
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSet
operator|<
name|T
operator|>
name|operator
operator|&
operator|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
name|QSet
operator|<
name|T
operator|>
name|result
operator|=
operator|*
name|this
block|;
name|result
operator|&=
name|other
block|;
return|return
name|result
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSet
operator|<
name|T
operator|>
name|operator
operator|+
operator|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
name|QSet
operator|<
name|T
operator|>
name|result
operator|=
operator|*
name|this
block|;
name|result
operator|+=
name|other
block|;
return|return
name|result
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QSet
operator|<
name|T
operator|>
name|operator
operator|-
operator|(
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
name|QSet
operator|<
name|T
operator|>
name|result
operator|=
operator|*
name|this
block|;
name|result
operator|-=
name|other
block|;
return|return
name|result
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|T
operator|>
name|toList
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QList
operator|<
name|T
operator|>
name|values
argument_list|()
specifier|const
block|{
return|return
name|toList
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|static
name|QSet
operator|<
name|T
operator|>
name|fromList
argument_list|(
specifier|const
name|QList
operator|<
name|T
operator|>
operator|&
name|list
argument_list|)
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|Hash
name|q_hash
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
DECL|function|reserve
name|Q_INLINE_TEMPLATE
name|void
name|QSet
operator|<
name|T
operator|>
operator|::
name|reserve
argument_list|(
argument|int asize
argument_list|)
block|{
name|q_hash
operator|.
name|reserve
argument_list|(
name|asize
argument_list|)
block|; }
name|template
operator|<
name|class
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|QSet
operator|<
name|T
operator|>
operator|&
name|QSet
operator|<
name|T
operator|>
operator|::
name|unite
argument_list|(
argument|const QSet<T>&other
argument_list|)
block|{
name|QSet
operator|<
name|T
operator|>
name|copy
argument_list|(
name|other
argument_list|)
block|;
name|typename
name|QSet
operator|<
name|T
operator|>
operator|::
name|const_iterator
name|i
operator|=
name|copy
operator|.
name|constEnd
argument_list|()
block|;
while|while
condition|(
name|i
operator|!=
name|copy
operator|.
name|constBegin
argument_list|()
condition|)
block|{
operator|--
name|i
expr_stmt|;
name|insert
argument_list|(
operator|*
name|i
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|QSet
operator|<
name|T
operator|>
operator|&
name|QSet
operator|<
name|T
operator|>
operator|::
name|intersect
argument_list|(
argument|const QSet<T>&other
argument_list|)
block|{
name|QSet
operator|<
name|T
operator|>
name|copy1
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|QSet
operator|<
name|T
operator|>
name|copy2
argument_list|(
name|other
argument_list|)
block|;
name|typename
name|QSet
operator|<
name|T
operator|>
operator|::
name|const_iterator
name|i
operator|=
name|copy1
operator|.
name|constEnd
argument_list|()
block|;
while|while
condition|(
name|i
operator|!=
name|copy1
operator|.
name|constBegin
argument_list|()
condition|)
block|{
operator|--
name|i
expr_stmt|;
if|if
condition|(
operator|!
name|copy2
operator|.
name|contains
argument_list|(
operator|*
name|i
argument_list|)
condition|)
name|remove
argument_list|(
operator|*
name|i
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|QSet
operator|<
name|T
operator|>
operator|&
name|QSet
operator|<
name|T
operator|>
operator|::
name|subtract
argument_list|(
argument|const QSet<T>&other
argument_list|)
block|{
name|QSet
operator|<
name|T
operator|>
name|copy1
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|QSet
operator|<
name|T
operator|>
name|copy2
argument_list|(
name|other
argument_list|)
block|;
name|typename
name|QSet
operator|<
name|T
operator|>
operator|::
name|const_iterator
name|i
operator|=
name|copy1
operator|.
name|constEnd
argument_list|()
block|;
while|while
condition|(
name|i
operator|!=
name|copy1
operator|.
name|constBegin
argument_list|()
condition|)
block|{
operator|--
name|i
expr_stmt|;
if|if
condition|(
name|copy2
operator|.
name|contains
argument_list|(
operator|*
name|i
argument_list|)
condition|)
name|remove
argument_list|(
operator|*
name|i
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
name|Q_INLINE_TEMPLATE
name|bool
name|QSet
operator|<
name|T
operator|>
operator|::
name|contains
argument_list|(
argument|const QSet<T>&other
argument_list|)
specifier|const
block|{
name|typename
name|QSet
operator|<
name|T
operator|>
operator|::
name|const_iterator
name|i
operator|=
name|other
operator|.
name|constBegin
argument_list|()
block|;
while|while
condition|(
name|i
operator|!=
name|other
operator|.
name|constEnd
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|contains
argument_list|(
operator|*
name|i
argument_list|)
condition|)
return|return
name|false
return|;
operator|++
name|i
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|true
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|toList
name|Q_OUTOFLINE_TEMPLATE
name|QList
operator|<
name|T
operator|>
name|QSet
operator|<
name|T
operator|>
operator|::
name|toList
argument_list|()
specifier|const
block|{
name|QList
operator|<
name|T
operator|>
name|result
block|;
name|result
operator|.
name|reserve
argument_list|(
name|size
argument_list|()
argument_list|)
block|;
name|typename
name|QSet
operator|<
name|T
operator|>
operator|::
name|const_iterator
name|i
operator|=
name|constBegin
argument_list|()
block|;
while|while
condition|(
name|i
operator|!=
name|constEnd
argument_list|()
condition|)
block|{
name|result
operator|.
name|append
argument_list|(
operator|*
name|i
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|result
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
DECL|function|toSet
name|Q_OUTOFLINE_TEMPLATE
name|QSet
operator|<
name|T
operator|>
name|QList
operator|<
name|T
operator|>
operator|::
name|toSet
argument_list|()
specifier|const
block|{
name|QSet
operator|<
name|T
operator|>
name|result
block|;
name|result
operator|.
name|reserve
argument_list|(
name|size
argument_list|()
argument_list|)
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|result
operator|.
name|insert
argument_list|(
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|result
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|QSet
operator|<
name|T
operator|>
name|QSet
operator|<
name|T
operator|>
operator|::
name|fromList
argument_list|(
argument|const QList<T>&list
argument_list|)
block|{
return|return
name|list
operator|.
name|toSet
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|QList
operator|<
name|T
operator|>
name|QList
operator|<
name|T
operator|>
operator|::
name|fromSet
argument_list|(
argument|const QSet<T>&set
argument_list|)
block|{
return|return
name|set
operator|.
name|toList
argument_list|()
return|;
block|}
end_expr_stmt
begin_macro
DECL|function|Q_DECLARE_SEQUENTIAL_ITERATOR
name|Q_DECLARE_SEQUENTIAL_ITERATOR
argument_list|(
argument|Set
argument_list|)
end_macro
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QMutableSetIterator
block|{
typedef|typedef
name|typename
name|QSet
operator|<
name|T
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
name|QSet
operator|<
name|T
operator|>
operator|*
name|c
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|iterator
name|i
decl_stmt|,
name|n
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|item_exists
argument_list|()
specifier|const
block|{
return|return
name|c
operator|->
name|constEnd
argument_list|()
operator|!=
name|n
return|;
block|}
end_expr_stmt
begin_label
name|public
label|:
end_label
begin_expr_stmt
specifier|inline
name|QMutableSetIterator
argument_list|(
name|QSet
operator|<
name|T
operator|>
operator|&
name|container
argument_list|)
operator|:
name|c
argument_list|(
argument|&container
argument_list|)
block|{
name|c
operator|->
name|setSharable
argument_list|(
name|false
argument_list|)
block|;
name|i
operator|=
name|c
operator|->
name|begin
argument_list|()
block|;
name|n
operator|=
name|c
operator|->
name|end
argument_list|()
block|; }
specifier|inline
operator|~
name|QMutableSetIterator
argument_list|()
block|{
name|c
operator|->
name|setSharable
argument_list|(
name|true
argument_list|)
block|; }
specifier|inline
name|QMutableSetIterator
operator|&
name|operator
operator|=
operator|(
name|QSet
operator|<
name|T
operator|>
operator|&
name|container
operator|)
block|{
name|c
operator|->
name|setSharable
argument_list|(
name|true
argument_list|)
block|;
name|c
operator|=
operator|&
name|container
block|;
name|c
operator|->
name|setSharable
argument_list|(
name|false
argument_list|)
block|;
name|i
operator|=
name|c
operator|->
name|begin
argument_list|()
block|;
name|n
operator|=
name|c
operator|->
name|end
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|toFront
parameter_list|()
block|{
name|i
operator|=
name|c
operator|->
name|begin
argument_list|()
expr_stmt|;
name|n
operator|=
name|c
operator|->
name|end
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|toBack
parameter_list|()
block|{
name|i
operator|=
name|c
operator|->
name|end
argument_list|()
expr_stmt|;
name|n
operator|=
name|i
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|bool
name|hasNext
argument_list|()
specifier|const
block|{
return|return
name|c
operator|->
name|constEnd
argument_list|()
operator|!=
name|i
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|const
name|T
modifier|&
name|next
parameter_list|()
block|{
name|n
operator|=
name|i
operator|++
expr_stmt|;
return|return
operator|*
name|n
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
name|T
operator|&
name|peekNext
argument_list|()
specifier|const
block|{
return|return
operator|*
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|hasPrevious
argument_list|()
specifier|const
block|{
return|return
name|c
operator|->
name|constBegin
argument_list|()
operator|!=
name|i
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
specifier|const
name|T
modifier|&
name|previous
parameter_list|()
block|{
name|n
operator|=
operator|--
name|i
expr_stmt|;
return|return
operator|*
name|n
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
name|T
operator|&
name|peekPrevious
argument_list|()
specifier|const
block|{
name|iterator
name|p
operator|=
name|i
block|;
return|return
operator|*
operator|--
name|p
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|remove
parameter_list|()
block|{
if|if
condition|(
name|c
operator|->
name|constEnd
argument_list|()
operator|!=
name|n
condition|)
block|{
name|i
operator|=
name|c
operator|->
name|erase
argument_list|(
name|n
argument_list|)
expr_stmt|;
name|n
operator|=
name|c
operator|->
name|end
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_expr_stmt
specifier|inline
specifier|const
name|T
operator|&
name|value
argument_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|item_exists
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|n
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|bool
name|findNext
parameter_list|(
specifier|const
name|T
modifier|&
name|t
parameter_list|)
block|{
while|while
condition|(
name|c
operator|->
name|constEnd
argument_list|()
operator|!=
operator|(
name|n
operator|=
name|i
operator|)
condition|)
if|if
condition|(
operator|*
name|i
operator|++
operator|==
name|t
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|findPrevious
parameter_list|(
specifier|const
name|T
modifier|&
name|t
parameter_list|)
block|{
while|while
condition|(
name|c
operator|->
name|constBegin
argument_list|()
operator|!=
name|i
condition|)
if|if
condition|(
operator|*
operator|(
name|n
operator|=
operator|--
name|i
operator|)
operator|==
name|t
condition|)
return|return
name|true
return|;
name|n
operator|=
name|c
operator|->
name|end
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
end_function
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
comment|// QSET_H
end_comment
end_unit
