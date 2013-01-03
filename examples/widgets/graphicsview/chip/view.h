begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|VIEW_H
end_ifndef
begin_define
DECL|macro|VIEW_H
define|#
directive|define
name|VIEW_H
end_define
begin_include
include|#
directive|include
file|<QFrame>
end_include
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSlider
name|class
name|QSlider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolButton
name|class
name|QToolButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|View
name|class
name|View
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|GraphicsView
range|:
name|public
name|QGraphicsView
block|{
name|Q_OBJECT
name|public
operator|:
name|GraphicsView
argument_list|(
name|View
operator|*
name|v
argument_list|)
operator|:
name|QGraphicsView
argument_list|()
block|,
name|view
argument_list|(
argument|v
argument_list|)
block|{ }
name|protected
operator|:
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
name|private
operator|:
name|View
operator|*
name|view
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|View
range|:
name|public
name|QFrame
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|View
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QGraphicsView
operator|*
name|view
argument_list|()
specifier|const
block|;
name|public
name|slots
operator|:
name|void
name|zoomIn
argument_list|(
argument|int level =
literal|1
argument_list|)
block|;
name|void
name|zoomOut
argument_list|(
argument|int level =
literal|1
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|resetView
argument_list|()
block|;
name|void
name|setResetButtonEnabled
argument_list|()
block|;
name|void
name|setupMatrix
argument_list|()
block|;
name|void
name|togglePointerMode
argument_list|()
block|;
name|void
name|toggleOpenGL
argument_list|()
block|;
name|void
name|toggleAntialiasing
argument_list|()
block|;
name|void
name|print
argument_list|()
block|;
name|void
name|rotateLeft
argument_list|()
block|;
name|void
name|rotateRight
argument_list|()
block|;
name|private
operator|:
name|GraphicsView
operator|*
name|graphicsView
block|;
name|QLabel
operator|*
name|label
block|;
name|QLabel
operator|*
name|label2
block|;
name|QToolButton
operator|*
name|selectModeButton
block|;
name|QToolButton
operator|*
name|dragModeButton
block|;
name|QToolButton
operator|*
name|openGlButton
block|;
name|QToolButton
operator|*
name|antialiasButton
block|;
name|QToolButton
operator|*
name|printButton
block|;
name|QToolButton
operator|*
name|resetButton
block|;
name|QSlider
operator|*
name|zoomSlider
block|;
name|QSlider
operator|*
name|rotateSlider
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// VIEW_H
end_comment
end_unit
