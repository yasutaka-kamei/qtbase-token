begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qtreewidgetitemiterator_p.h>
end_include
begin_include
include|#
directive|include
file|"qtreewidget.h"
end_include
begin_include
include|#
directive|include
file|"qtreewidget_p.h"
end_include
begin_include
include|#
directive|include
file|"qwidgetitemdata_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TREEWIDGET
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \class QTreeWidgetItemIterator   \ingroup model-view   \inmodule QtWidgets     \brief The QTreeWidgetItemIterator class provides a way to iterate over the   items in a QTreeWidget instance.    The iterator will walk the items in a pre-order traversal order, thus visiting the   parent node \e before it continues to the child nodes.    For example, the following code examples each item in a tree, checking the   text in the first column against a user-specified search string:    \snippet qtreewidgetitemiterator-using/mainwindow.cpp 0    It is also possible to filter out certain types of node by passing certain   \l{IteratorFlag}{flags} to the constructor of QTreeWidgetItemIterator.    \sa QTreeWidget, {Model/View Programming}, QTreeWidgetItem */
end_comment
begin_comment
comment|/*!     Constructs an iterator for the same QTreeWidget as \a it. The     current iterator item is set to point on the current item of \a it. */
end_comment
begin_constructor
DECL|function|QTreeWidgetItemIterator
name|QTreeWidgetItemIterator
operator|::
name|QTreeWidgetItemIterator
parameter_list|(
specifier|const
name|QTreeWidgetItemIterator
modifier|&
name|it
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QTreeWidgetItemIteratorPrivate
argument_list|(
operator|*
operator|(
name|it
operator|.
name|d_ptr
operator|)
argument_list|)
argument_list|)
member_init_list|,
name|current
argument_list|(
name|it
operator|.
name|current
argument_list|)
member_init_list|,
name|flags
argument_list|(
name|it
operator|.
name|flags
argument_list|)
block|{
name|Q_D
argument_list|(
name|QTreeWidgetItemIterator
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|m_model
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_model
operator|->
name|iterators
operator|.
name|append
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs an iterator for the given \a widget that uses the specified \a flags     to determine which items are found during iteration.     The iterator is set to point to the first top-level item contained in the widget,     or the next matching item if the top-level item doesn't match the flags.      \sa QTreeWidgetItemIterator::IteratorFlag */
end_comment
begin_constructor
DECL|function|QTreeWidgetItemIterator
name|QTreeWidgetItemIterator
operator|::
name|QTreeWidgetItemIterator
parameter_list|(
name|QTreeWidget
modifier|*
name|widget
parameter_list|,
name|IteratorFlags
name|flags
parameter_list|)
member_init_list|:
name|current
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|flags
argument_list|(
name|flags
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|QTreeModel
modifier|*
name|model
init|=
name|qobject_cast
argument_list|<
name|QTreeModel
operator|*
argument_list|>
argument_list|(
name|widget
operator|->
name|model
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|d_ptr
operator|.
name|reset
argument_list|(
operator|new
name|QTreeWidgetItemIteratorPrivate
argument_list|(
name|this
argument_list|,
name|model
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|iterators
operator|.
name|append
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|model
operator|->
name|rootItem
operator|->
name|children
operator|.
name|isEmpty
argument_list|()
condition|)
name|current
operator|=
name|model
operator|->
name|rootItem
operator|->
name|children
operator|.
name|first
argument_list|()
expr_stmt|;
if|if
condition|(
name|current
operator|&&
operator|!
name|matchesFlags
argument_list|(
name|current
argument_list|)
condition|)
operator|++
operator|(
operator|*
name|this
operator|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs an iterator for the given \a item that uses the specified \a flags     to determine which items are found during iteration.     The iterator is set to point to \a item, or the next matching item if \a item     doesn't match the flags.      \sa QTreeWidgetItemIterator::IteratorFlag */
end_comment
begin_constructor
DECL|function|QTreeWidgetItemIterator
name|QTreeWidgetItemIterator
operator|::
name|QTreeWidgetItemIterator
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|,
name|IteratorFlags
name|flags
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QTreeWidgetItemIteratorPrivate
argument_list|(
name|this
argument_list|,
name|qobject_cast
argument_list|<
name|QTreeModel
operator|*
argument_list|>
argument_list|(
name|item
operator|->
name|view
operator|->
name|model
argument_list|()
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|current
argument_list|(
name|item
argument_list|)
member_init_list|,
name|flags
argument_list|(
name|flags
argument_list|)
block|{
name|Q_D
argument_list|(
name|QTreeWidgetItemIterator
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|QTreeModel
modifier|*
name|model
init|=
name|qobject_cast
argument_list|<
name|QTreeModel
operator|*
argument_list|>
argument_list|(
name|item
operator|->
name|view
operator|->
name|model
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|model
operator|->
name|iterators
operator|.
name|append
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|// Initialize m_currentIndex and m_parentIndex as it would be if we had traversed from
comment|// the beginning.
name|QTreeWidgetItem
modifier|*
name|parent
init|=
name|item
decl_stmt|;
name|parent
operator|=
name|parent
operator|->
name|parent
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QTreeWidgetItem
modifier|*
argument_list|>
name|children
init|=
name|parent
condition|?
name|parent
operator|->
name|children
else|:
name|d
operator|->
name|m_model
operator|->
name|rootItem
operator|->
name|children
decl_stmt|;
name|d
operator|->
name|m_currentIndex
operator|=
name|children
operator|.
name|indexOf
argument_list|(
name|item
argument_list|)
expr_stmt|;
while|while
condition|(
name|parent
condition|)
block|{
name|QTreeWidgetItem
modifier|*
name|itm
init|=
name|parent
decl_stmt|;
name|parent
operator|=
name|parent
operator|->
name|parent
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QTreeWidgetItem
modifier|*
argument_list|>
name|children
init|=
name|parent
condition|?
name|parent
operator|->
name|children
else|:
name|d
operator|->
name|m_model
operator|->
name|rootItem
operator|->
name|children
decl_stmt|;
name|int
name|index
init|=
name|children
operator|.
name|indexOf
argument_list|(
name|itm
argument_list|)
decl_stmt|;
name|d
operator|->
name|m_parentIndex
operator|.
name|prepend
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|current
operator|&&
operator|!
name|matchesFlags
argument_list|(
name|current
argument_list|)
condition|)
operator|++
operator|(
operator|*
name|this
operator|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the iterator. */
end_comment
begin_destructor
DECL|function|~QTreeWidgetItemIterator
name|QTreeWidgetItemIterator
operator|::
name|~
name|QTreeWidgetItemIterator
parameter_list|()
block|{
name|d_func
argument_list|()
operator|->
name|m_model
operator|->
name|iterators
operator|.
name|removeAll
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Assignment. Makes a copy of \a it and returns a reference to its     iterator. */
end_comment
begin_function
DECL|function|operator =
name|QTreeWidgetItemIterator
modifier|&
name|QTreeWidgetItemIterator
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QTreeWidgetItemIterator
modifier|&
name|it
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QTreeWidgetItemIterator
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_func
argument_list|()
operator|->
name|m_model
operator|!=
name|it
operator|.
name|d_func
argument_list|()
operator|->
name|m_model
condition|)
block|{
name|d_func
argument_list|()
operator|->
name|m_model
operator|->
name|iterators
operator|.
name|removeAll
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|it
operator|.
name|d_func
argument_list|()
operator|->
name|m_model
operator|->
name|iterators
operator|.
name|append
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
name|current
operator|=
name|it
operator|.
name|current
expr_stmt|;
name|flags
operator|=
name|it
operator|.
name|flags
expr_stmt|;
name|d
operator|->
name|operator
name|=
argument_list|(
operator|*
name|it
operator|.
name|d_func
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     The prefix ++ operator (++it) advances the iterator to the next matching item     and returns a reference to the resulting iterator.     Sets the current pointer to 0 if the current item is the last matching item. */
end_comment
begin_function
DECL|function|operator ++
name|QTreeWidgetItemIterator
modifier|&
name|QTreeWidgetItemIterator
operator|::
name|operator
name|++
parameter_list|()
block|{
if|if
condition|(
name|current
condition|)
do|do
block|{
name|current
operator|=
name|d_func
argument_list|()
operator|->
name|next
argument_list|(
name|current
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|current
operator|&&
operator|!
name|matchesFlags
argument_list|(
name|current
argument_list|)
condition|)
do|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     The prefix -- operator (--it) advances the iterator to the previous matching item     and returns a reference to the resulting iterator.     Sets the current pointer to 0 if the current item is the first matching item. */
end_comment
begin_function
DECL|function|operator --
name|QTreeWidgetItemIterator
modifier|&
name|QTreeWidgetItemIterator
operator|::
name|operator
name|--
parameter_list|()
block|{
if|if
condition|(
name|current
condition|)
do|do
block|{
name|current
operator|=
name|d_func
argument_list|()
operator|->
name|previous
argument_list|(
name|current
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|current
operator|&&
operator|!
name|matchesFlags
argument_list|(
name|current
argument_list|)
condition|)
do|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|matchesFlags
name|bool
name|QTreeWidgetItemIterator
operator|::
name|matchesFlags
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|item
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|flags
operator|==
name|All
condition|)
return|return
literal|true
return|;
block|{
name|Qt
operator|::
name|ItemFlags
name|itemFlags
init|=
name|item
operator|->
name|flags
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|flags
operator|&
name|Selectable
operator|)
operator|&&
operator|!
operator|(
name|itemFlags
operator|&
name|Qt
operator|::
name|ItemIsSelectable
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|NotSelectable
operator|)
operator|&&
operator|(
name|itemFlags
operator|&
name|Qt
operator|::
name|ItemIsSelectable
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|DragEnabled
operator|)
operator|&&
operator|!
operator|(
name|itemFlags
operator|&
name|Qt
operator|::
name|ItemIsDragEnabled
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|DragDisabled
operator|)
operator|&&
operator|(
name|itemFlags
operator|&
name|Qt
operator|::
name|ItemIsDragEnabled
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|DropEnabled
operator|)
operator|&&
operator|!
operator|(
name|itemFlags
operator|&
name|Qt
operator|::
name|ItemIsDropEnabled
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|DropDisabled
operator|)
operator|&&
operator|(
name|itemFlags
operator|&
name|Qt
operator|::
name|ItemIsDropEnabled
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|Enabled
operator|)
operator|&&
operator|!
operator|(
name|itemFlags
operator|&
name|Qt
operator|::
name|ItemIsEnabled
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|Disabled
operator|)
operator|&&
operator|(
name|itemFlags
operator|&
name|Qt
operator|::
name|ItemIsEnabled
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|Editable
operator|)
operator|&&
operator|!
operator|(
name|itemFlags
operator|&
name|Qt
operator|::
name|ItemIsEditable
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|NotEditable
operator|)
operator|&&
operator|(
name|itemFlags
operator|&
name|Qt
operator|::
name|ItemIsEditable
operator|)
condition|)
return|return
literal|false
return|;
block|}
if|if
condition|(
name|flags
operator|&
operator|(
name|Checked
operator||
name|NotChecked
operator|)
condition|)
block|{
comment|// ### We only test the check state for column 0
name|Qt
operator|::
name|CheckState
name|check
init|=
name|item
operator|->
name|checkState
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// PartiallyChecked matches as Checked.
if|if
condition|(
operator|(
name|flags
operator|&
name|Checked
operator|)
operator|&&
operator|(
name|check
operator|==
name|Qt
operator|::
name|Unchecked
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|NotChecked
operator|)
operator|&&
operator|(
name|check
operator|!=
name|Qt
operator|::
name|Unchecked
operator|)
condition|)
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|(
name|flags
operator|&
name|HasChildren
operator|)
operator|&&
operator|!
name|item
operator|->
name|childCount
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|NoChildren
operator|)
operator|&&
name|item
operator|->
name|childCount
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|Hidden
operator|)
operator|&&
operator|!
name|item
operator|->
name|isHidden
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|NotHidden
operator|)
operator|&&
name|item
operator|->
name|isHidden
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|Selected
operator|)
operator|&&
operator|!
name|item
operator|->
name|isSelected
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|(
name|flags
operator|&
name|Unselected
operator|)
operator|&&
name|item
operator|->
name|isSelected
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*  * Implementation of QTreeWidgetItemIteratorPrivate  */
end_comment
begin_function
DECL|function|nextSibling
name|QTreeWidgetItem
modifier|*
name|QTreeWidgetItemIteratorPrivate
operator|::
name|nextSibling
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|next
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|QTreeWidgetItem
modifier|*
name|par
init|=
name|item
operator|->
name|parent
argument_list|()
condition|)
block|{
name|int
name|i
init|=
name|par
operator|->
name|indexOfChild
argument_list|(
cast|const_cast
argument_list|<
name|QTreeWidgetItem
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
argument_list|)
decl_stmt|;
name|next
operator|=
name|par
operator|->
name|child
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QTreeWidget
modifier|*
name|tw
init|=
name|item
operator|->
name|treeWidget
argument_list|()
decl_stmt|;
name|int
name|i
init|=
name|tw
operator|->
name|indexOfTopLevelItem
argument_list|(
cast|const_cast
argument_list|<
name|QTreeWidgetItem
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
argument_list|)
decl_stmt|;
name|next
operator|=
name|tw
operator|->
name|topLevelItem
argument_list|(
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|next
return|;
block|}
end_function
begin_function
DECL|function|next
name|QTreeWidgetItem
modifier|*
name|QTreeWidgetItemIteratorPrivate
operator|::
name|next
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|current
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current
condition|)
return|return
literal|0
return|;
name|QTreeWidgetItem
modifier|*
name|next
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|current
operator|->
name|childCount
argument_list|()
condition|)
block|{
comment|// walk the child
name|m_parentIndex
operator|.
name|push
argument_list|(
name|m_currentIndex
argument_list|)
expr_stmt|;
name|m_currentIndex
operator|=
literal|0
expr_stmt|;
name|next
operator|=
name|current
operator|->
name|child
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// walk the sibling
name|QTreeWidgetItem
modifier|*
name|parent
init|=
name|current
operator|->
name|parent
argument_list|()
decl_stmt|;
name|next
operator|=
name|parent
condition|?
name|parent
operator|->
name|child
argument_list|(
name|m_currentIndex
operator|+
literal|1
argument_list|)
else|:
name|m_model
operator|->
name|rootItem
operator|->
name|child
argument_list|(
name|m_currentIndex
operator|+
literal|1
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|next
operator|&&
name|parent
condition|)
block|{
comment|// if we had no sibling walk up the parent and try the sibling of that
name|parent
operator|=
name|parent
operator|->
name|parent
argument_list|()
expr_stmt|;
name|m_currentIndex
operator|=
name|m_parentIndex
operator|.
name|pop
argument_list|()
expr_stmt|;
name|next
operator|=
name|parent
condition|?
name|parent
operator|->
name|child
argument_list|(
name|m_currentIndex
operator|+
literal|1
argument_list|)
else|:
name|m_model
operator|->
name|rootItem
operator|->
name|child
argument_list|(
name|m_currentIndex
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|next
condition|)
operator|++
operator|(
name|m_currentIndex
operator|)
expr_stmt|;
block|}
return|return
name|next
return|;
block|}
end_function
begin_function
DECL|function|previous
name|QTreeWidgetItem
modifier|*
name|QTreeWidgetItemIteratorPrivate
operator|::
name|previous
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|current
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current
condition|)
return|return
literal|0
return|;
name|QTreeWidgetItem
modifier|*
name|prev
init|=
literal|0
decl_stmt|;
comment|// walk the previous sibling
name|QTreeWidgetItem
modifier|*
name|parent
init|=
name|current
operator|->
name|parent
argument_list|()
decl_stmt|;
name|prev
operator|=
name|parent
condition|?
name|parent
operator|->
name|child
argument_list|(
name|m_currentIndex
operator|-
literal|1
argument_list|)
else|:
name|m_model
operator|->
name|rootItem
operator|->
name|child
argument_list|(
name|m_currentIndex
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|prev
condition|)
block|{
comment|// Yes, we had a previous sibling but we need go down to the last leafnode.
operator|--
name|m_currentIndex
expr_stmt|;
while|while
condition|(
name|prev
operator|&&
name|prev
operator|->
name|childCount
argument_list|()
condition|)
block|{
name|m_parentIndex
operator|.
name|push
argument_list|(
name|m_currentIndex
argument_list|)
expr_stmt|;
name|m_currentIndex
operator|=
name|prev
operator|->
name|childCount
argument_list|()
operator|-
literal|1
expr_stmt|;
name|prev
operator|=
name|prev
operator|->
name|child
argument_list|(
name|m_currentIndex
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|parent
condition|)
block|{
name|m_currentIndex
operator|=
name|m_parentIndex
operator|.
name|pop
argument_list|()
expr_stmt|;
name|prev
operator|=
name|parent
expr_stmt|;
block|}
return|return
name|prev
return|;
block|}
end_function
begin_function
DECL|function|ensureValidIterator
name|void
name|QTreeWidgetItemIteratorPrivate
operator|::
name|ensureValidIterator
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|itemToBeRemoved
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QTreeWidgetItemIterator
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|itemToBeRemoved
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|q
operator|->
name|current
condition|)
return|return;
name|QTreeWidgetItem
modifier|*
name|nextItem
init|=
name|q
operator|->
name|current
decl_stmt|;
comment|// Do not walk to the ancestor to find the other item if they have the same parent.
if|if
condition|(
name|nextItem
operator|->
name|parent
argument_list|()
operator|!=
name|itemToBeRemoved
operator|->
name|parent
argument_list|()
condition|)
block|{
while|while
condition|(
name|nextItem
operator|->
name|parent
argument_list|()
operator|&&
name|nextItem
operator|!=
name|itemToBeRemoved
condition|)
block|{
name|nextItem
operator|=
name|nextItem
operator|->
name|parent
argument_list|()
expr_stmt|;
block|}
block|}
comment|// If the item to be removed is an ancestor of the current iterator item,
comment|// we need to adjust the iterator.
if|if
condition|(
name|nextItem
operator|==
name|itemToBeRemoved
condition|)
block|{
name|QTreeWidgetItem
modifier|*
name|parent
init|=
name|nextItem
decl_stmt|;
name|nextItem
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|parent
operator|&&
operator|!
name|nextItem
condition|)
block|{
name|nextItem
operator|=
name|nextSibling
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|parent
operator|=
name|parent
operator|->
name|parent
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|nextItem
condition|)
block|{
comment|// Ooooh... Set the iterator to the next valid item
operator|*
name|q
operator|=
name|QTreeWidgetItemIterator
argument_list|(
name|nextItem
argument_list|,
name|q
operator|->
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|q
operator|->
name|matchesFlags
argument_list|(
name|nextItem
argument_list|)
operator|)
condition|)
operator|++
operator|(
operator|*
name|q
operator|)
expr_stmt|;
block|}
else|else
block|{
comment|// set it to null.
name|q
operator|->
name|current
operator|=
literal|0
expr_stmt|;
name|m_parentIndex
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
if|if
condition|(
name|nextItem
operator|->
name|parent
argument_list|()
operator|==
name|itemToBeRemoved
operator|->
name|parent
argument_list|()
condition|)
block|{
comment|// They have the same parent, i.e. we have to adjust the m_currentIndex member of the iterator
comment|// if the deleted item is to the left of the nextItem.
name|QTreeWidgetItem
modifier|*
name|par
init|=
name|itemToBeRemoved
operator|->
name|parent
argument_list|()
decl_stmt|;
comment|// We know they both have the same parent.
name|QTreeWidget
modifier|*
name|tw
init|=
name|itemToBeRemoved
operator|->
name|treeWidget
argument_list|()
decl_stmt|;
comment|// ..and widget
name|int
name|indexOfItemToBeRemoved
init|=
name|par
condition|?
name|par
operator|->
name|indexOfChild
argument_list|(
cast|const_cast
argument_list|<
name|QTreeWidgetItem
operator|*
argument_list|>
argument_list|(
name|itemToBeRemoved
argument_list|)
argument_list|)
else|:
name|tw
operator|->
name|indexOfTopLevelItem
argument_list|(
cast|const_cast
argument_list|<
name|QTreeWidgetItem
operator|*
argument_list|>
argument_list|(
name|itemToBeRemoved
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|indexOfNextItem
init|=
name|par
condition|?
name|par
operator|->
name|indexOfChild
argument_list|(
name|nextItem
argument_list|)
else|:
name|tw
operator|->
name|indexOfTopLevelItem
argument_list|(
name|nextItem
argument_list|)
decl_stmt|;
if|if
condition|(
name|indexOfItemToBeRemoved
operator|<=
name|indexOfNextItem
condition|)
block|{
comment|// A sibling to the left of us was deleted, adjust the m_currentIndex member of the iterator.
comment|// Note that the m_currentIndex will be wrong until the item is actually removed!
name|m_currentIndex
operator|--
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!   \fn const QTreeWidgetItemIterator QTreeWidgetItemIterator::operator++(int)    The postfix ++ operator (it++) advances the iterator to the next matching item   and returns an iterator to the previously current item. */
end_comment
begin_comment
comment|/*!   \fn QTreeWidgetItemIterator&QTreeWidgetItemIterator::operator+=(int n)    Makes the iterator go forward by \a n matching items. (If n is negative, the   iterator goes backward.)    If the current item is beyond the last item, the current item pointer is   set to 0. Returns the resulting iterator. */
end_comment
begin_comment
comment|/*!   \fn const QTreeWidgetItemIterator QTreeWidgetItemIterator::operator--(int)    The postfix -- operator (it--) makes the preceding matching item current and returns an iterator to the previously current item. */
end_comment
begin_comment
comment|/*!   \fn QTreeWidgetItemIterator&QTreeWidgetItemIterator::operator-=(int n)    Makes the iterator go backward by \a n matching items. (If n is negative, the   iterator goes forward.)    If the current item is ahead of the last item, the current item pointer is   set to 0. Returns the resulting iterator. */
end_comment
begin_comment
comment|/*!   \fn QTreeWidgetItem *QTreeWidgetItemIterator::operator*() const    Dereference operator. Returns a pointer to the current item. */
end_comment
begin_comment
comment|/*!     \enum QTreeWidgetItemIterator::IteratorFlag      These flags can be passed to a QTreeWidgetItemIterator constructor     (OR-ed together if more than one is used), so that the iterator     will only iterate over items that match the given flags.      \value All     \value Hidden     \value NotHidden     \value Selected     \value Unselected     \value Selectable     \value NotSelectable     \value DragEnabled     \value DragDisabled     \value DropEnabled     \value DropDisabled     \value HasChildren     \value NoChildren     \value Checked     \value NotChecked     \value Enabled     \value Disabled     \value Editable     \value NotEditable     \value UserFlag */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TREEWIDGET
end_comment
end_unit
