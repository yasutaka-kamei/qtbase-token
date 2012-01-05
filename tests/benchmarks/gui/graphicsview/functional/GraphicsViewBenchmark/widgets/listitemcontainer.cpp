begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|<QGraphicsLinearLayout>
end_include
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|"listitemcontainer.h"
end_include
begin_include
include|#
directive|include
file|"abstractviewitem.h"
end_include
begin_include
include|#
directive|include
file|"recycledlistitem.h"
end_include
begin_include
include|#
directive|include
file|"listitemcache.h"
end_include
begin_include
include|#
directive|include
file|"itemrecyclinglist.h"
end_include
begin_constructor
DECL|function|ListItemContainer
name|ListItemContainer
operator|::
name|ListItemContainer
parameter_list|(
name|int
name|bufferSize
parameter_list|,
name|ItemRecyclingList
modifier|*
name|view
parameter_list|,
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|AbstractItemContainer
argument_list|(
name|bufferSize
argument_list|,
name|parent
argument_list|)
member_init_list|,
name|m_view
argument_list|(
name|view
argument_list|)
member_init_list|,
name|m_layout
argument_list|(
operator|new
name|QGraphicsLinearLayout
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
argument_list|)
member_init_list|,
name|m_listItemCaching
argument_list|(
literal|false
argument_list|)
block|{
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|m_layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*virtual*/
end_comment
begin_destructor
DECL|function|~ListItemContainer
name|ListItemContainer
operator|::
name|~
name|ListItemContainer
parameter_list|()
block|{
name|setListItemCaching
argument_list|(
literal|false
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_items
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|m_layout
operator|->
name|removeItem
argument_list|(
name|m_items
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|m_items
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|setParentItem
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|qDeleteAll
argument_list|(
name|m_items
argument_list|)
expr_stmt|;
name|m_items
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|listItemCaching
name|bool
name|ListItemContainer
operator|::
name|listItemCaching
parameter_list|()
specifier|const
block|{
return|return
name|m_listItemCaching
return|;
block|}
end_function
begin_function
DECL|function|setListItemCaching
name|void
name|ListItemContainer
operator|::
name|setListItemCaching
parameter_list|(
specifier|const
name|bool
name|enabled
parameter_list|)
block|{
if|if
condition|(
name|m_listItemCaching
operator|==
name|enabled
condition|)
return|return;
name|m_listItemCaching
operator|=
name|enabled
expr_stmt|;
specifier|const
name|int
name|itemCount
init|=
name|m_layout
operator|->
name|count
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|itemCount
condition|;
operator|++
name|i
control|)
name|setListItemCaching
argument_list|(
name|enabled
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|adjustVisibleContainerSize
name|void
name|ListItemContainer
operator|::
name|adjustVisibleContainerSize
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
block|{
name|m_layout
operator|->
name|setPreferredWidth
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|addItemToVisibleLayout
name|void
name|ListItemContainer
operator|::
name|addItemToVisibleLayout
parameter_list|(
name|int
name|index
parameter_list|,
name|AbstractViewItem
modifier|*
name|item
parameter_list|)
block|{
name|m_layout
operator|->
name|insertItem
argument_list|(
name|index
argument_list|,
name|item
argument_list|)
expr_stmt|;
name|setListItemCaching
argument_list|(
name|m_listItemCaching
argument_list|,
name|index
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|removeItemFromVisibleLayout
name|void
name|ListItemContainer
operator|::
name|removeItemFromVisibleLayout
parameter_list|(
name|AbstractViewItem
modifier|*
name|item
parameter_list|)
block|{
name|m_layout
operator|->
name|removeItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|RecycledListItem
modifier|*
name|recycledItem
init|=
cast|static_cast
argument_list|<
name|RecycledListItem
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|recycledItem
condition|)
return|return;
name|ListItem
modifier|*
name|listItem
init|=
name|recycledItem
operator|->
name|item
argument_list|()
decl_stmt|;
name|setListItemCaching
argument_list|(
literal|false
argument_list|,
name|listItem
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|maxItemCountInItemBuffer
name|int
name|ListItemContainer
operator|::
name|maxItemCountInItemBuffer
parameter_list|()
specifier|const
block|{
name|int
name|count
init|=
name|AbstractItemContainer
operator|::
name|maxItemCountInItemBuffer
argument_list|()
decl_stmt|;
if|if
condition|(
name|count
operator|>
literal|0
condition|)
block|{
name|int
name|currentItemCount
init|=
name|m_items
operator|.
name|count
argument_list|()
decl_stmt|;
name|qreal
name|heightOfOneItem
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|currentItemCount
operator|>
literal|0
condition|)
block|{
name|heightOfOneItem
operator|=
name|m_layout
operator|->
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
operator|.
name|height
argument_list|()
operator|/
name|currentItemCount
expr_stmt|;
block|}
name|int
name|guess
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|heightOfOneItem
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|m_prototype
condition|)
block|{
name|heightOfOneItem
operator|=
name|m_prototype
operator|->
name|effectiveSizeHint
argument_list|(
name|Qt
operator|::
name|PreferredSize
argument_list|)
operator|.
name|height
argument_list|()
expr_stmt|;
block|}
else|else
name|heightOfOneItem
operator|=
literal|50
expr_stmt|;
comment|// TODO magic number, do we have better guess if prototype is not set?
block|}
if|if
condition|(
name|heightOfOneItem
operator|>
literal|0
condition|)
block|{
name|guess
operator|=
name|qCeil
argument_list|(
name|m_itemView
operator|->
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|heightOfOneItem
argument_list|)
operator|+
name|m_bufferSize
expr_stmt|;
if|if
condition|(
name|guess
operator|<
name|currentItemCount
condition|)
block|{
if|if
condition|(
name|guess
operator|>
name|currentItemCount
operator|-
literal|2
condition|)
block|{
comment|// TODO magic number here, Can we use buffer size?
name|guess
operator|=
name|currentItemCount
expr_stmt|;
block|}
block|}
block|}
name|count
operator|=
name|qMin
argument_list|(
name|guess
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
return|return
name|count
return|;
block|}
end_function
begin_function
DECL|function|setListItemCaching
name|void
name|ListItemContainer
operator|::
name|setListItemCaching
parameter_list|(
specifier|const
name|bool
name|enabled
parameter_list|,
specifier|const
name|int
name|index
parameter_list|)
block|{
name|RecycledListItem
modifier|*
name|recycledItem
init|=
cast|static_cast
argument_list|<
name|RecycledListItem
operator|*
argument_list|>
argument_list|(
name|m_layout
operator|->
name|itemAt
argument_list|(
name|index
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|recycledItem
condition|)
return|return;
name|ListItem
modifier|*
name|listItem
init|=
name|recycledItem
operator|->
name|item
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|listItem
condition|)
return|return;
name|setListItemCaching
argument_list|(
name|enabled
argument_list|,
name|listItem
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setListItemCaching
name|void
name|ListItemContainer
operator|::
name|setListItemCaching
parameter_list|(
specifier|const
name|bool
name|enabled
parameter_list|,
name|ListItem
modifier|*
name|listItem
parameter_list|)
block|{
if|if
condition|(
operator|!
name|listItem
condition|)
return|return;
comment|// Deletes the effect.
name|listItem
operator|->
name|setGraphicsEffect
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|enabled
condition|)
block|{
name|ListItemCache
modifier|*
name|cache
init|=
operator|new
name|ListItemCache
decl_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|listItem
operator|->
name|graphicsEffect
argument_list|()
argument_list|)
expr_stmt|;
name|listItem
operator|->
name|setGraphicsEffect
argument_list|(
name|cache
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setTwoColumns
name|void
name|ListItemContainer
operator|::
name|setTwoColumns
parameter_list|(
specifier|const
name|bool
name|twoColumns
parameter_list|)
block|{
name|AbstractItemContainer
operator|::
name|setTwoColumns
argument_list|(
name|twoColumns
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_layout
operator|->
name|isActivated
argument_list|()
condition|)
name|m_layout
operator|->
name|activate
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
