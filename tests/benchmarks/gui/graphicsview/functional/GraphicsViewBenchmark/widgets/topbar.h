begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__TOPBAR_H__
end_ifndef
begin_define
DECL|macro|__TOPBAR_H__
define|#
directive|define
name|__TOPBAR_H__
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|"gvbwidget.h"
end_include
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsView
name|class
name|QGraphicsView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|TopBar
range|:
name|public
name|GvbWidget
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Orientation
block|{
name|Portrait
block|,
name|Landscape
block|,
name|None
block|}
block|;
name|public
operator|:
name|TopBar
argument_list|(
name|QGraphicsView
operator|*
name|mainView
argument_list|,
name|QGraphicsWidget
operator|*
name|parent
argument_list|)
block|;
operator|~
name|TopBar
argument_list|()
block|;
name|public
operator|:
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
operator|=
literal|0
argument_list|)
block|;
name|QRectF
name|boundingRect
argument_list|()
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
specifier|inline
name|QPoint
name|getStatusBarLocation
argument_list|()
block|{
return|return
name|m_topBarStatusBarMiddlePoint
operator|+
name|m_topBarStatusBarMiddle
operator|.
name|rect
argument_list|()
operator|.
name|bottomLeft
argument_list|()
return|;
block|}
name|public
name|slots
operator|:
name|void
name|themeChange
argument_list|()
block|;
name|protected
operator|:
name|void
name|mousePressEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|signals
operator|:
name|void
name|clicked
argument_list|(
argument|bool checked = false
argument_list|)
block|;
name|private
operator|:
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
name|setDefaultSizes
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|TopBar
argument_list|)
name|QGraphicsView
operator|*
name|m_mainView
block|;
name|bool
name|m_isLimeTheme
block|;
name|Orientation
name|m_orientation
block|;
comment|//Fonts
name|QFont
name|m_titleFont
block|;
name|QFont
name|m_statusFont
block|;
comment|//Pixmaps
name|QPixmap
name|m_topBarPixmap
block|;
name|QPixmap
name|m_topBarUserIcon
block|;
name|QPixmap
name|m_topBarUserStatus
block|;
name|QPixmap
name|m_topBarStatusBarLeft
block|;
name|QPixmap
name|m_topBarStatusBarRight
block|;
name|QPixmap
name|m_topBarStatusBarMiddle
block|;
comment|//Drawing points
name|QPoint
name|m_topBarUserIconPoint
block|;
name|QPoint
name|m_topBarUserStatusPoint
block|;
name|QPoint
name|m_topBarStatusBarLeftPoint
block|;
name|QPoint
name|m_topBarStatusBarRightPoint
block|;
name|QPoint
name|m_topBarStatusBarMiddlePoint
block|;
name|QPoint
name|m_topBarStatusBarTextPoint
block|;
name|QPoint
name|m_topBarTitlePoint
block|;
comment|//Sizes
name|QHash
operator|<
name|QString
block|,
name|QSize
operator|>
name|m_sizesBlue
block|;
name|QHash
operator|<
name|QString
block|,
name|QSize
operator|>
name|m_sizesLime
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// __TOPBAR_H__
end_comment
end_unit
