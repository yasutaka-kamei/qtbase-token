begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSPROXYWIDGET_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSPROXYWIDGET_H
define|#
directive|define
name|QGRAPHICSPROXYWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicswidget.h>
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
name|QGraphicsProxyWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsProxyWidget
range|:
name|public
name|QGraphicsWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|QGraphicsProxyWidget
argument_list|(
argument|QGraphicsItem *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags wFlags =
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsProxyWidget
argument_list|()
block|;
name|void
name|setWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|;
name|QRectF
name|subWidgetRect
argument_list|(
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QStyleOptionGraphicsItem
operator|*
name|option
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
block|;      enum
block|{
name|Type
operator|=
literal|12
block|}
block|;
name|int
name|type
argument_list|()
specifier|const
block|;
name|QGraphicsProxyWidget
operator|*
name|createProxyForChildWidget
argument_list|(
name|QWidget
operator|*
name|child
argument_list|)
block|;
name|protected
operator|:
name|QVariant
name|itemChange
argument_list|(
argument|GraphicsItemChange change
argument_list|,
argument|const QVariant&value
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|hideEvent
argument_list|(
name|QHideEvent
operator|*
name|event
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
name|QGraphicsSceneContextMenuEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|dragEnterEvent
argument_list|(
name|QGraphicsSceneDragDropEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dragLeaveEvent
argument_list|(
name|QGraphicsSceneDragDropEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dragMoveEvent
argument_list|(
name|QGraphicsSceneDragDropEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|dropEvent
argument_list|(
name|QGraphicsSceneDragDropEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|void
name|hoverEnterEvent
argument_list|(
name|QGraphicsSceneHoverEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|hoverLeaveEvent
argument_list|(
name|QGraphicsSceneHoverEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|hoverMoveEvent
argument_list|(
name|QGraphicsSceneHoverEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|grabMouseEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|ungrabMouseEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
name|QGraphicsSceneWheelEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|keyReleaseEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
comment|// ### Qt 4.5:
comment|// QVariant inputMethodQuery(Qt::InputMethodQuery query) const;
comment|// void inputMethodEvent(QInputMethodEvent *event);
name|QSizeF
name|sizeHint
argument_list|(
argument|Qt::SizeHint which
argument_list|,
argument|const QSizeF&constraint = QSizeF()
argument_list|)
specifier|const
block|;
name|void
name|resizeEvent
argument_list|(
name|QGraphicsSceneResizeEvent
operator|*
name|event
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|QGraphicsProxyWidget
operator|*
name|newProxyWidget
argument_list|(
specifier|const
name|QWidget
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsProxyWidget
argument_list|)
name|Q_DECLARE_PRIVATE_D
argument_list|(
argument|QGraphicsItem::d_ptr.data()
argument_list|,
argument|QGraphicsProxyWidget
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_removeWidgetSlot()
argument_list|)
name|friend
name|class
name|QWidget
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|friend
name|class
name|QGraphicsItem
block|; }
decl_stmt|;
end_decl_stmt
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
