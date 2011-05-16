begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBWINDOW_H
end_ifndef
begin_define
DECL|macro|QXCBWINDOW_H
define|#
directive|define
name|QXCBWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowFormat>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|<xcb/sync.h>
end_include
begin_include
include|#
directive|include
file|"qxcbobject.h"
end_include
begin_decl_stmt
DECL|variable|QXcbScreen
name|class
name|QXcbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbObject
name|class
name|QXcbWindow
range|:
name|public
name|QXcbObject
decl_stmt|,
name|public
name|QPlatformWindow
block|{
name|public
label|:
name|QXcbWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
expr_stmt|;
operator|~
name|QXcbWindow
argument_list|()
expr_stmt|;
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|void
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
name|Qt
operator|::
name|WindowFlags
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|WindowState
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
expr_stmt|;
name|WId
name|winId
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setParent
parameter_list|(
specifier|const
name|QPlatformWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
function_decl|;
name|void
name|raise
parameter_list|()
function_decl|;
name|void
name|lower
parameter_list|()
function_decl|;
name|void
name|propagateSizeHints
parameter_list|()
function_decl|;
name|void
name|requestActivateWindow
parameter_list|()
function_decl|;
name|QPlatformGLContext
operator|*
name|glContext
argument_list|()
specifier|const
expr_stmt|;
name|xcb_window_t
name|xcb_window
argument_list|()
specifier|const
block|{
return|return
name|m_window
return|;
block|}
name|void
name|handleExposeEvent
parameter_list|(
specifier|const
name|xcb_expose_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleClientMessageEvent
parameter_list|(
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleConfigureNotifyEvent
parameter_list|(
specifier|const
name|xcb_configure_notify_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleButtonPressEvent
parameter_list|(
specifier|const
name|xcb_button_press_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleButtonReleaseEvent
parameter_list|(
specifier|const
name|xcb_button_release_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleMotionNotifyEvent
parameter_list|(
specifier|const
name|xcb_motion_notify_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleEnterNotifyEvent
parameter_list|(
specifier|const
name|xcb_enter_notify_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleLeaveNotifyEvent
parameter_list|(
specifier|const
name|xcb_leave_notify_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleFocusInEvent
parameter_list|(
specifier|const
name|xcb_focus_in_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleFocusOutEvent
parameter_list|(
specifier|const
name|xcb_focus_out_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleMouseEvent
parameter_list|(
name|xcb_button_t
name|detail
parameter_list|,
name|uint16_t
name|state
parameter_list|,
name|xcb_timestamp_t
name|time
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|local
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|global
parameter_list|)
function_decl|;
name|void
name|updateSyncRequestCounter
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|setNetWmWindowTypes
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
decl_stmt|;
name|void
name|changeNetWmState
parameter_list|(
name|bool
name|set
parameter_list|,
name|xcb_atom_t
name|one
parameter_list|,
name|xcb_atom_t
name|two
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|show
parameter_list|()
function_decl|;
name|void
name|hide
parameter_list|()
function_decl|;
name|QXcbScreen
modifier|*
name|m_screen
decl_stmt|;
name|xcb_window_t
name|m_window
decl_stmt|;
name|QPlatformGLContext
modifier|*
name|m_context
decl_stmt|;
name|xcb_sync_int64_t
name|m_syncValue
decl_stmt|;
name|xcb_sync_counter_t
name|m_syncCounter
decl_stmt|;
name|bool
name|m_hasReceivedSyncRequest
decl_stmt|;
name|Qt
operator|::
name|WindowState
name|m_windowState
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
