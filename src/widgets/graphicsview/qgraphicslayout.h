begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSLAYOUT_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSLAYOUT_H
define|#
directive|define
name|QGRAPHICSLAYOUT_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicslayoutitem.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
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
name|class
name|QGraphicsLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsLayoutItem
name|class
name|QGraphicsLayoutItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsWidget
name|class
name|QGraphicsWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QGraphicsLayout
range|:
name|public
name|QGraphicsLayoutItem
block|{
name|public
operator|:
name|QGraphicsLayout
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsLayout
argument_list|()
block|;
name|void
name|setContentsMargins
argument_list|(
argument|qreal left
argument_list|,
argument|qreal top
argument_list|,
argument|qreal right
argument_list|,
argument|qreal bottom
argument_list|)
block|;
name|void
name|getContentsMargins
argument_list|(
argument|qreal *left
argument_list|,
argument|qreal *top
argument_list|,
argument|qreal *right
argument_list|,
argument|qreal *bottom
argument_list|)
specifier|const
block|;
name|void
name|activate
argument_list|()
block|;
name|bool
name|isActivated
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|invalidate
argument_list|()
block|;
name|virtual
name|void
name|updateGeometry
argument_list|()
block|;
name|virtual
name|void
name|widgetEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|int
name|count
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QGraphicsLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int i
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|removeAt
argument_list|(
argument|int index
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|QGraphicsLayout
argument_list|(
name|QGraphicsLayoutPrivate
operator|&
argument_list|,
name|QGraphicsLayoutItem
operator|*
argument_list|)
block|;
name|void
name|addChildLayoutItem
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|layoutItem
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsLayout
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsLayout
argument_list|)
name|friend
name|class
name|QGraphicsWidget
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_INTERFACE
argument_list|(
argument|QGraphicsLayout
argument_list|,
literal|"com.trolltech.Qt.QGraphicsLayout"
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
