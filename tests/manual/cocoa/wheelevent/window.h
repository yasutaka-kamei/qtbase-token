begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_decl_stmt
name|class
name|Window
range|:
name|public
name|QWindow
block|{
name|public
operator|:
name|Window
argument_list|(
name|QWindow
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|Window
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|)
block|;
name|protected
operator|:
name|void
name|mousePressEvent
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
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|void
name|exposeEvent
argument_list|(
name|QExposeEvent
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
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|void
name|render
argument_list|()
block|;
name|void
name|scheduleRender
argument_list|()
block|;
name|void
name|initialize
argument_list|()
block|;
name|QString
name|m_text
block|;
name|QImage
name|m_image
block|;
name|QPoint
name|m_lastPos
block|;
name|int
name|m_backgroundColorIndex
block|;
name|QBackingStore
operator|*
name|m_backingStore
block|;
name|int
name|m_renderTimer
block|;
name|QPoint
name|scrollOffset
block|; }
decl_stmt|;
end_decl_stmt
end_unit
