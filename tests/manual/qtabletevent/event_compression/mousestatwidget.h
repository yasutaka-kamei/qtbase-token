begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MOUSESTATWIDGET_H
end_ifndef
begin_define
DECL|macro|MOUSESTATWIDGET_H
define|#
directive|define
name|MOUSESTATWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
DECL|variable|QTabletEvent
name|class
name|QTabletEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimerEvent
name|class
name|QTimerEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintEvent
name|class
name|QPaintEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MouseStatWidget
range|:
name|public
name|QWidget
block|{
name|public
operator|:
name|MouseStatWidget
argument_list|(
argument|bool acceptTabletEvent = true
argument_list|)
block|;
name|protected
operator|:
name|void
name|tabletEvent
argument_list|(
name|QTabletEvent
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
name|timerEvent
argument_list|(
name|QTimerEvent
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
name|private
operator|:
specifier|const
name|bool
name|acceptTabletEvent
block|;
name|int
name|receivedMouseEventCount
block|;
name|int
name|receivedMouseEventCountToPaint
block|;
name|int
name|receivedTabletEventCount
block|;
name|int
name|receivedTabletEventCountToPaint
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MOUSESTATWIDGET_H
end_comment
end_unit
