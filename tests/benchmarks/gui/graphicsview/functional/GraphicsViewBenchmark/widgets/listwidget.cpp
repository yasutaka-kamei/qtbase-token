begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGraphicsSceneResizeEvent>
end_include
begin_include
include|#
directive|include
file|<QGraphicsGridLayout>
end_include
begin_include
include|#
directive|include
file|<QGraphicsLinearLayout>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|"listwidget.h"
end_include
begin_constructor
DECL|function|ListWidget
name|ListWidget
operator|::
name|ListWidget
parameter_list|(
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|GvbWidget
argument_list|(
name|parent
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
name|m_listView
argument_list|(
operator|new
name|SimpleListView
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
comment|//listView->setViewport(listView->content());
comment|//listView->content()->setParentItem(listView);
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
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
name|m_listView
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
name|addItem
argument_list|(
name|m_listView
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|m_layout
argument_list|)
expr_stmt|;
name|m_scroller
operator|.
name|setScrollable
argument_list|(
name|m_listView
argument_list|)
expr_stmt|;
name|m_listView
operator|->
name|installEventFilter
argument_list|(
operator|&
name|m_scroller
argument_list|)
expr_stmt|;
name|m_listView
operator|->
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~ListWidget
name|ListWidget
operator|::
name|~
name|ListWidget
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|addItem
name|void
name|ListWidget
operator|::
name|addItem
parameter_list|(
name|QGraphicsWidget
modifier|*
name|item
parameter_list|)
block|{
name|m_listView
operator|->
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertItem
name|void
name|ListWidget
operator|::
name|insertItem
parameter_list|(
name|int
name|index
parameter_list|,
name|QGraphicsWidget
modifier|*
name|item
parameter_list|)
block|{
name|m_listView
operator|->
name|insertItem
argument_list|(
name|index
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|takeItem
name|QGraphicsWidget
modifier|*
name|ListWidget
operator|::
name|takeItem
parameter_list|(
name|int
name|row
parameter_list|)
block|{
return|return
name|m_listView
operator|->
name|takeItem
argument_list|(
name|row
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|itemAt
name|QGraphicsWidget
modifier|*
name|ListWidget
operator|::
name|itemAt
parameter_list|(
name|int
name|row
parameter_list|)
block|{
return|return
name|m_listView
operator|->
name|itemAt
argument_list|(
name|row
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/* virtual */
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|ListWidget
operator|::
name|resizeEvent
parameter_list|(
name|QGraphicsSceneResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|QGraphicsWidget
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|itemCount
name|int
name|ListWidget
operator|::
name|itemCount
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_listView
condition|)
return|return
name|m_listView
operator|->
name|itemCount
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|verticalScrollBar
name|ScrollBar
modifier|*
name|ListWidget
operator|::
name|verticalScrollBar
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_listView
condition|)
return|return
name|m_listView
operator|->
name|verticalScrollBar
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|listItemCaching
name|bool
name|ListWidget
operator|::
name|listItemCaching
parameter_list|()
specifier|const
block|{
return|return
name|m_listView
operator|->
name|listItemCaching
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setListItemCaching
name|void
name|ListWidget
operator|::
name|setListItemCaching
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|m_listView
operator|->
name|setListItemCaching
argument_list|(
name|enable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTwoColumns
name|void
name|ListWidget
operator|::
name|setTwoColumns
parameter_list|(
specifier|const
name|bool
name|twoColumns
parameter_list|)
block|{
name|m_listView
operator|->
name|setTwoColumns
argument_list|(
name|twoColumns
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|twoColumns
name|bool
name|ListWidget
operator|::
name|twoColumns
parameter_list|()
block|{
return|return
name|m_listView
operator|->
name|twoColumns
argument_list|()
return|;
block|}
end_function
end_unit
