begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbsystemtraytracker.h"
end_include
begin_include
include|#
directive|include
file|"qxcbconnection.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRect>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|enum
type|{
DECL|enumerator|SystemTrayRequestDock
name|SystemTrayRequestDock
init|=
literal|0
decl_stmt|,
DECL|enumerator|SystemTrayBeginMessage
name|SystemTrayBeginMessage
init|=
literal|1
decl_stmt|,
DECL|enumerator|SystemTrayCancelMessage
name|SystemTrayCancelMessage
init|=
literal|2
end_decl_stmt
begin_comment
unit|};
comment|// QXcbSystemTrayTracker provides API for accessing the tray window and tracks
end_comment
begin_comment
comment|// its lifecyle by listening for its destruction and recreation.
end_comment
begin_comment
comment|// See http://standards.freedesktop.org/systemtray-spec/systemtray-spec-latest.html
end_comment
begin_function
DECL|function|create
name|QXcbSystemTrayTracker
modifier|*
name|QXcbSystemTrayTracker
operator|::
name|create
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|)
block|{
comment|// Selection, tray atoms for GNOME, NET WM Specification
specifier|const
name|xcb_atom_t
name|trayAtom
init|=
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|_NET_SYSTEM_TRAY_OPCODE
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|trayAtom
condition|)
return|return
literal|0
return|;
specifier|const
name|QByteArray
name|netSysTray
init|=
name|QByteArrayLiteral
argument_list|(
literal|"_NET_SYSTEM_TRAY_S"
argument_list|)
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|connection
operator|->
name|primaryScreenNumber
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|xcb_atom_t
name|selection
init|=
name|connection
operator|->
name|internAtom
argument_list|(
name|netSysTray
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|selection
condition|)
return|return
literal|0
return|;
return|return
operator|new
name|QXcbSystemTrayTracker
argument_list|(
name|connection
argument_list|,
name|trayAtom
argument_list|,
name|selection
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QXcbSystemTrayTracker
name|QXcbSystemTrayTracker
operator|::
name|QXcbSystemTrayTracker
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|xcb_atom_t
name|trayAtom
parameter_list|,
name|xcb_atom_t
name|selection
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|connection
argument_list|)
member_init_list|,
name|m_selection
argument_list|(
name|selection
argument_list|)
member_init_list|,
name|m_trayAtom
argument_list|(
name|trayAtom
argument_list|)
member_init_list|,
name|m_connection
argument_list|(
name|connection
argument_list|)
member_init_list|,
name|m_trayWindow
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|locateTrayWindow
name|xcb_window_t
name|QXcbSystemTrayTracker
operator|::
name|locateTrayWindow
parameter_list|(
specifier|const
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|xcb_atom_t
name|selection
parameter_list|)
block|{
name|xcb_get_selection_owner_cookie_t
name|cookie
init|=
name|xcb_get_selection_owner
argument_list|(
name|connection
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|selection
argument_list|)
decl_stmt|;
name|xcb_get_selection_owner_reply_t
modifier|*
name|reply
init|=
name|xcb_get_selection_owner_reply
argument_list|(
name|connection
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|cookie
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
condition|)
return|return
literal|0
return|;
specifier|const
name|xcb_window_t
name|result
init|=
name|reply
operator|->
name|owner
decl_stmt|;
name|free
argument_list|(
name|reply
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|// API for QPlatformNativeInterface/QPlatformSystemTrayIcon: Request a window
end_comment
begin_comment
comment|// to be docked on the tray.
end_comment
begin_function
DECL|function|requestSystemTrayWindowDock
name|void
name|QXcbSystemTrayTracker
operator|::
name|requestSystemTrayWindowDock
parameter_list|(
name|xcb_window_t
name|window
parameter_list|)
specifier|const
block|{
name|xcb_client_message_event_t
name|trayRequest
decl_stmt|;
name|trayRequest
operator|.
name|response_type
operator|=
name|XCB_CLIENT_MESSAGE
expr_stmt|;
name|trayRequest
operator|.
name|format
operator|=
literal|32
expr_stmt|;
name|trayRequest
operator|.
name|sequence
operator|=
literal|0
expr_stmt|;
name|trayRequest
operator|.
name|window
operator|=
name|m_trayWindow
expr_stmt|;
name|trayRequest
operator|.
name|type
operator|=
name|m_trayAtom
expr_stmt|;
name|trayRequest
operator|.
name|data
operator|.
name|data32
index|[
literal|0
index|]
operator|=
name|XCB_CURRENT_TIME
expr_stmt|;
name|trayRequest
operator|.
name|data
operator|.
name|data32
index|[
literal|1
index|]
operator|=
name|SystemTrayRequestDock
expr_stmt|;
name|trayRequest
operator|.
name|data
operator|.
name|data32
index|[
literal|2
index|]
operator|=
name|window
expr_stmt|;
name|xcb_send_event
argument_list|(
name|m_connection
operator|->
name|xcb_connection
argument_list|()
argument_list|,
literal|0
argument_list|,
name|m_trayWindow
argument_list|,
name|XCB_EVENT_MASK_NO_EVENT
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
operator|&
name|trayRequest
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// API for QPlatformNativeInterface/QPlatformSystemTrayIcon: Return tray window.
end_comment
begin_function
DECL|function|trayWindow
name|xcb_window_t
name|QXcbSystemTrayTracker
operator|::
name|trayWindow
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_trayWindow
condition|)
block|{
name|m_trayWindow
operator|=
name|QXcbSystemTrayTracker
operator|::
name|locateTrayWindow
argument_list|(
name|m_connection
argument_list|,
name|m_selection
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_trayWindow
condition|)
block|{
comment|// Listen for DestroyNotify on tray.
name|m_connection
operator|->
name|addWindowEventListener
argument_list|(
name|m_trayWindow
argument_list|,
name|this
argument_list|)
expr_stmt|;
specifier|const
name|quint32
name|mask
init|=
name|XCB_CW_EVENT_MASK
decl_stmt|;
specifier|const
name|quint32
name|value
init|=
name|XCB_EVENT_MASK_STRUCTURE_NOTIFY
decl_stmt|;
name|Q_XCB_CALL2
argument_list|(
name|xcb_change_window_attributes
argument_list|(
name|m_connection
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|m_trayWindow
argument_list|,
name|mask
argument_list|,
operator|&
name|value
argument_list|)
argument_list|,
name|m_connection
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|m_trayWindow
return|;
block|}
end_function
begin_comment
comment|// API for QPlatformNativeInterface/QPlatformSystemTrayIcon: Return the geometry of a
end_comment
begin_comment
comment|// a window parented on the tray. Determines the global geometry via XCB since mapToGlobal
end_comment
begin_comment
comment|// does not work for the QWindow parented on the tray.
end_comment
begin_function
DECL|function|systemTrayWindowGlobalGeometry
name|QRect
name|QXcbSystemTrayTracker
operator|::
name|systemTrayWindowGlobalGeometry
parameter_list|(
name|xcb_window_t
name|window
parameter_list|)
specifier|const
block|{
name|xcb_connection_t
modifier|*
name|conn
init|=
name|m_connection
operator|->
name|xcb_connection
argument_list|()
decl_stmt|;
name|xcb_get_geometry_reply_t
modifier|*
name|geomReply
init|=
name|xcb_get_geometry_reply
argument_list|(
name|conn
argument_list|,
name|xcb_get_geometry
argument_list|(
name|conn
argument_list|,
name|window
argument_list|)
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|geomReply
condition|)
return|return
name|QRect
argument_list|()
return|;
name|xcb_translate_coordinates_reply_t
modifier|*
name|translateReply
init|=
name|xcb_translate_coordinates_reply
argument_list|(
name|conn
argument_list|,
name|xcb_translate_coordinates
argument_list|(
name|conn
argument_list|,
name|window
argument_list|,
name|m_connection
operator|->
name|rootWindow
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|translateReply
condition|)
block|{
name|free
argument_list|(
name|geomReply
argument_list|)
expr_stmt|;
return|return
name|QRect
argument_list|()
return|;
block|}
specifier|const
name|QRect
name|result
argument_list|(
name|QPoint
argument_list|(
name|translateReply
operator|->
name|dst_x
argument_list|,
name|translateReply
operator|->
name|dst_y
argument_list|)
argument_list|,
name|QSize
argument_list|(
name|geomReply
operator|->
name|width
argument_list|,
name|geomReply
operator|->
name|height
argument_list|)
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|translateReply
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|emitSystemTrayWindowChanged
specifier|inline
name|void
name|QXcbSystemTrayTracker
operator|::
name|emitSystemTrayWindowChanged
parameter_list|()
block|{
if|if
condition|(
specifier|const
name|QPlatformScreen
modifier|*
name|ps
init|=
name|m_connection
operator|->
name|primaryScreen
argument_list|()
condition|)
emit|emit
name|systemTrayWindowChanged
argument_list|(
name|ps
operator|->
name|screen
argument_list|()
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|// Client messages with the "MANAGER" atom on the root window indicate creation of a new tray.
end_comment
begin_function
DECL|function|notifyManagerClientMessageEvent
name|void
name|QXcbSystemTrayTracker
operator|::
name|notifyManagerClientMessageEvent
parameter_list|(
specifier|const
name|xcb_client_message_event_t
modifier|*
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|->
name|data
operator|.
name|data32
index|[
literal|1
index|]
operator|==
name|m_selection
condition|)
name|emitSystemTrayWindowChanged
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// Listen for destruction of the tray.
end_comment
begin_function
DECL|function|handleDestroyNotifyEvent
name|void
name|QXcbSystemTrayTracker
operator|::
name|handleDestroyNotifyEvent
parameter_list|(
specifier|const
name|xcb_destroy_notify_event_t
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|window
operator|==
name|m_trayWindow
condition|)
block|{
name|m_connection
operator|->
name|removeWindowEventListener
argument_list|(
name|m_trayWindow
argument_list|)
expr_stmt|;
name|m_trayWindow
operator|=
name|XCB_WINDOW_NONE
expr_stmt|;
name|emitSystemTrayWindowChanged
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|visualHasAlphaChannel
name|bool
name|QXcbSystemTrayTracker
operator|::
name|visualHasAlphaChannel
parameter_list|()
block|{
if|if
condition|(
name|m_trayWindow
operator|==
name|XCB_WINDOW_NONE
condition|)
return|return
literal|false
return|;
name|xcb_atom_t
name|tray_atom
init|=
name|m_connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|_NET_SYSTEM_TRAY_VISUAL
argument_list|)
decl_stmt|;
comment|// Get the xcb property for the _NET_SYSTEM_TRAY_VISUAL atom
name|xcb_get_property_cookie_t
name|systray_atom_cookie
decl_stmt|;
name|xcb_get_property_reply_t
modifier|*
name|systray_atom_reply
decl_stmt|;
name|systray_atom_cookie
operator|=
name|xcb_get_property_unchecked
argument_list|(
name|m_connection
operator|->
name|xcb_connection
argument_list|()
argument_list|,
literal|false
argument_list|,
name|m_trayWindow
argument_list|,
name|tray_atom
argument_list|,
name|XCB_ATOM_VISUALID
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|systray_atom_reply
operator|=
name|xcb_get_property_reply
argument_list|(
name|m_connection
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|systray_atom_cookie
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|systray_atom_reply
condition|)
return|return
literal|false
return|;
name|xcb_visualid_t
name|systrayVisualId
init|=
name|XCB_NONE
decl_stmt|;
if|if
condition|(
name|systray_atom_reply
operator|->
name|value_len
operator|>
literal|0
operator|&&
name|xcb_get_property_value_length
argument_list|(
name|systray_atom_reply
argument_list|)
operator|>
literal|0
condition|)
block|{
name|xcb_visualid_t
modifier|*
name|vids
init|=
operator|(
name|uint32_t
operator|*
operator|)
name|xcb_get_property_value
argument_list|(
name|systray_atom_reply
argument_list|)
decl_stmt|;
name|systrayVisualId
operator|=
name|vids
index|[
literal|0
index|]
expr_stmt|;
block|}
name|free
argument_list|(
name|systray_atom_reply
argument_list|)
expr_stmt|;
if|if
condition|(
name|systrayVisualId
operator|!=
name|XCB_NONE
condition|)
block|{
name|quint8
name|depth
init|=
name|m_connection
operator|->
name|primaryScreen
argument_list|()
operator|->
name|depthOfVisual
argument_list|(
name|systrayVisualId
argument_list|)
decl_stmt|;
return|return
name|depth
operator|==
literal|32
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
