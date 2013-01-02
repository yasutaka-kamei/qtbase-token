begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTSCROLLAREA_H
end_ifndef
begin_define
DECL|macro|QABSTRACTSCROLLAREA_H
define|#
directive|define
name|QABSTRACTSCROLLAREA_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qframe.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SCROLLAREA
DECL|variable|QMargins
name|class
name|QMargins
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollBar
name|class
name|QScrollBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractScrollAreaPrivate
name|class
name|QAbstractScrollAreaPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QAbstractScrollArea
range|:
name|public
name|QFrame
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|Qt::ScrollBarPolicy verticalScrollBarPolicy READ verticalScrollBarPolicy WRITE setVerticalScrollBarPolicy
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::ScrollBarPolicy horizontalScrollBarPolicy READ horizontalScrollBarPolicy WRITE setHorizontalScrollBarPolicy
argument_list|)
name|public
operator|:
name|explicit
name|QAbstractScrollArea
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QAbstractScrollArea
argument_list|()
block|;
name|Qt
operator|::
name|ScrollBarPolicy
name|verticalScrollBarPolicy
argument_list|()
specifier|const
block|;
name|void
name|setVerticalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarPolicy
argument_list|)
block|;
name|QScrollBar
operator|*
name|verticalScrollBar
argument_list|()
specifier|const
block|;
name|void
name|setVerticalScrollBar
argument_list|(
name|QScrollBar
operator|*
name|scrollbar
argument_list|)
block|;
name|Qt
operator|::
name|ScrollBarPolicy
name|horizontalScrollBarPolicy
argument_list|()
specifier|const
block|;
name|void
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarPolicy
argument_list|)
block|;
name|QScrollBar
operator|*
name|horizontalScrollBar
argument_list|()
specifier|const
block|;
name|void
name|setHorizontalScrollBar
argument_list|(
name|QScrollBar
operator|*
name|scrollbar
argument_list|)
block|;
name|QWidget
operator|*
name|cornerWidget
argument_list|()
specifier|const
block|;
name|void
name|setCornerWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|addScrollBarWidget
argument_list|(
argument|QWidget *widget
argument_list|,
argument|Qt::Alignment alignment
argument_list|)
block|;
name|QWidgetList
name|scrollBarWidgets
argument_list|(
argument|Qt::Alignment alignment
argument_list|)
block|;
name|QWidget
operator|*
name|viewport
argument_list|()
specifier|const
block|;
name|void
name|setViewport
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QSize
name|maximumViewportSize
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setupViewport
argument_list|(
name|QWidget
operator|*
name|viewport
argument_list|)
block|;
name|protected
operator|:
name|QAbstractScrollArea
argument_list|(
name|QAbstractScrollAreaPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setViewportMargins
argument_list|(
argument|int left
argument_list|,
argument|int top
argument_list|,
argument|int right
argument_list|,
argument|int bottom
argument_list|)
block|;
name|void
name|setViewportMargins
argument_list|(
specifier|const
name|QMargins
operator|&
name|margins
argument_list|)
block|;
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|viewportEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
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
name|QDragEnterEvent
operator|*
argument_list|)
block|;
name|void
name|dragMoveEvent
argument_list|(
name|QDragMoveEvent
operator|*
argument_list|)
block|;
name|void
name|dragLeaveEvent
argument_list|(
name|QDragLeaveEvent
operator|*
argument_list|)
block|;
name|void
name|dropEvent
argument_list|(
name|QDropEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|virtual
name|QSize
name|viewportSizeHint
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractScrollArea
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractScrollArea
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_hslide(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_vslide(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_showOrHideScrollBars()
argument_list|)
name|friend
name|class
name|QStyleSheetStyle
block|;
name|friend
name|class
name|QWidgetPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SCROLLAREA
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
comment|// QABSTRACTSCROLLAREA_H
end_comment
end_unit
