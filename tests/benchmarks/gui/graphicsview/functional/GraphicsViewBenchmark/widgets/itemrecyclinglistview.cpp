begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"itemrecyclinglistview.h"
end_include
begin_constructor
DECL|function|ItemRecyclingListView
name|ItemRecyclingListView
operator|::
name|ItemRecyclingListView
parameter_list|(
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|AbstractItemView
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_rootIndex
argument_list|()
block|{ }
end_constructor
begin_comment
comment|/*virtual*/
end_comment
begin_destructor
DECL|function|~ItemRecyclingListView
name|ItemRecyclingListView
operator|::
name|~
name|ItemRecyclingListView
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|setCurrentRow
name|void
name|ItemRecyclingListView
operator|::
name|setCurrentRow
parameter_list|(
specifier|const
name|int
name|row
parameter_list|)
block|{
name|setCurrentIndex
argument_list|(
name|model
argument_list|()
operator|->
name|index
argument_list|(
name|row
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rows
name|int
name|ItemRecyclingListView
operator|::
name|rows
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_model
condition|)
return|return
name|m_model
operator|->
name|rowCount
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|rowsInserted
name|void
name|ItemRecyclingListView
operator|::
name|rowsInserted
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
block|{
if|if
condition|(
name|parent
operator|==
name|m_rootIndex
condition|)
block|{
name|AbstractItemView
operator|::
name|rowsInserted
argument_list|(
name|parent
argument_list|,
name|start
argument_list|,
name|end
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*virtual*/
end_comment
begin_function
DECL|function|rowsRemoved
name|void
name|ItemRecyclingListView
operator|::
name|rowsRemoved
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
block|{
if|if
condition|(
name|parent
operator|==
name|m_rootIndex
condition|)
block|{
name|AbstractItemView
operator|::
name|rowsRemoved
argument_list|(
name|parent
argument_list|,
name|start
argument_list|,
name|end
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
