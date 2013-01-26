begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWIDGETWINDOW_QPA_P_H
end_ifndef
begin_define
DECL|macro|QWIDGETWINDOW_QPA_P_H
define|#
directive|define
name|QWIDGETWINDOW_QPA_P_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qevent_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCloseEvent
name|class
name|QCloseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMoveEvent
name|class
name|QMoveEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWidgetWindow
range|:
name|public
name|QWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|QWidgetWindow
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
block|{
return|return
name|m_widget
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|QAccessibleInterface
operator|*
name|accessibleRoot
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QObject
operator|*
name|focusObject
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|handleCloseEvent
argument_list|(
name|QCloseEvent
operator|*
argument_list|)
block|;
name|void
name|handleEnterLeaveEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|handleKeyEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|void
name|handleMouseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|handleNonClientAreaMouseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|handleTouchEvent
argument_list|(
name|QTouchEvent
operator|*
argument_list|)
block|;
name|void
name|handleMoveEvent
argument_list|(
name|QMoveEvent
operator|*
argument_list|)
block|;
name|void
name|handleResizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|handleWheelEvent
argument_list|(
name|QWheelEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|handleDragEnterMoveEvent
argument_list|(
name|QDragMoveEvent
operator|*
argument_list|)
block|;
name|void
name|handleDragLeaveEvent
argument_list|(
name|QDragLeaveEvent
operator|*
argument_list|)
block|;
name|void
name|handleDropEvent
argument_list|(
name|QDropEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|void
name|handleExposeEvent
argument_list|(
name|QExposeEvent
operator|*
argument_list|)
block|;
name|void
name|handleWindowStateChangedEvent
argument_list|(
name|QWindowStateChangeEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|nativeEvent
argument_list|(
specifier|const
name|QByteArray
operator|&
name|eventType
argument_list|,
name|void
operator|*
name|message
argument_list|,
name|long
operator|*
name|result
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_TABLETEVENT
name|void
name|handleTabletEvent
argument_list|(
name|QTabletEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|handleContextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|private
name|slots
operator|:
name|void
name|updateObjectName
argument_list|()
block|;
name|private
operator|:
name|void
name|updateGeometry
argument_list|()
block|;
name|QWidget
operator|*
name|m_widget
block|;
name|QPointer
operator|<
name|QWidget
operator|>
name|m_implicit_mouse_grabber
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|QPointer
operator|<
name|QWidget
operator|>
name|m_dragTarget
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWIDGETWINDOW_QPA_P_H
end_comment
end_unit
