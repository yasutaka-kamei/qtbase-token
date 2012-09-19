begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LISTITEMCONTAINER_H
end_ifndef
begin_define
DECL|macro|LISTITEMCONTAINER_H
define|#
directive|define
name|LISTITEMCONTAINER_H
end_define
begin_include
include|#
directive|include
file|<QGraphicsWidget>
end_include
begin_include
include|#
directive|include
file|<QColor>
end_include
begin_include
include|#
directive|include
file|"abstractitemcontainer.h"
end_include
begin_decl_stmt
DECL|variable|QGraphicsLinearLayout
name|class
name|QGraphicsLinearLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|AbstractViewItem
name|class
name|AbstractViewItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ListItemCache
name|class
name|ListItemCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ListItem
name|class
name|ListItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ItemRecyclingList
name|class
name|ItemRecyclingList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|ListItemContainer
range|:
name|public
name|AbstractItemContainer
block|{
name|Q_OBJECT
name|public
operator|:
name|ListItemContainer
argument_list|(
argument|int bufferSize
argument_list|,
argument|ItemRecyclingList *view
argument_list|,
argument|QGraphicsWidget *parent=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|ListItemContainer
argument_list|()
block|;
name|virtual
name|void
name|setTwoColumns
argument_list|(
argument|const bool twoColumns
argument_list|)
block|;
name|bool
name|listItemCaching
argument_list|()
specifier|const
block|;
name|void
name|setListItemCaching
argument_list|(
argument|const bool enabled
argument_list|)
block|;
name|virtual
name|void
name|setListItemCaching
argument_list|(
argument|const bool enabled
argument_list|,
argument|const int index
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|addItemToVisibleLayout
argument_list|(
argument|int index
argument_list|,
argument|AbstractViewItem *item
argument_list|)
block|;
name|virtual
name|void
name|removeItemFromVisibleLayout
argument_list|(
name|AbstractViewItem
operator|*
name|item
argument_list|)
block|;
name|virtual
name|void
name|adjustVisibleContainerSize
argument_list|(
specifier|const
name|QSizeF
operator|&
name|size
argument_list|)
block|;
name|virtual
name|int
name|maxItemCountInItemBuffer
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|ListItemContainer
argument_list|)
name|ItemRecyclingList
operator|*
name|m_view
block|;
name|QGraphicsLinearLayout
operator|*
name|m_layout
block|;
name|void
name|setListItemCaching
argument_list|(
argument|const bool enabled
argument_list|,
argument|ListItem *listItem
argument_list|)
block|;
name|bool
name|m_listItemCaching
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LISTITEMCONTAINER_H
end_comment
end_unit
