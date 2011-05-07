begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSSCENELINEARINDEX_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSSCENELINEARINDEX_H
define|#
directive|define
name|QGRAPHICSSCENELINEARINDEX_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
operator|||
operator|(
name|QT_EDITION
operator|&
name|QT_MODULE_GRAPHICSVIEW
operator|)
operator|!=
name|QT_MODULE_GRAPHICSVIEW
end_if
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicsitem.h>
end_include
begin_include
include|#
directive|include
file|<private/qgraphicssceneindex_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|Q_AUTOTEST_EXPORT
name|QGraphicsSceneLinearIndex
range|:
name|public
name|QGraphicsSceneIndex
block|{
name|Q_OBJECT
name|public
operator|:
name|QGraphicsSceneLinearIndex
argument_list|(
name|QGraphicsScene
operator|*
name|scene
operator|=
literal|0
argument_list|)
operator|:
name|QGraphicsSceneIndex
argument_list|(
argument|scene
argument_list|)
block|{ }
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|items
argument_list|(
argument|Qt::SortOrder order = Qt::DescendingOrder
argument_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|order
argument_list|)
block|;
return|return
name|m_items
return|;
block|}
name|virtual
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|estimateItems
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|Qt::SortOrder order
argument_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|rect
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|order
argument_list|)
block|;
return|return
name|m_items
return|;
block|}
name|protected
operator|:
name|virtual
name|void
name|clear
argument_list|()
block|{
name|m_items
operator|.
name|clear
argument_list|()
block|; }
name|virtual
name|void
name|addItem
argument_list|(
argument|QGraphicsItem *item
argument_list|)
block|{
name|m_items
operator|<<
name|item
block|; }
name|virtual
name|void
name|removeItem
argument_list|(
argument|QGraphicsItem *item
argument_list|)
block|{
name|m_items
operator|.
name|removeOne
argument_list|(
name|item
argument_list|)
block|; }
name|private
operator|:
name|QList
operator|<
name|QGraphicsItem
operator|*
operator|>
name|m_items
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GRAPHICSVIEW
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGRAPHICSSCENELINEARINDEX_H
end_comment
end_unit
