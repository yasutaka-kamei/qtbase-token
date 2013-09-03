begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBCONNECTION_H
end_ifndef
begin_define
DECL|macro|QXCBCONNECTION_H
define|#
directive|define
name|QXCBCONNECTION_H
end_define
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<QVarLengthArray>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_comment
comment|// This is needed to make Qt compile together with XKB. xkb.h is using a variable
end_comment
begin_comment
comment|// which is called 'explicit', this is a reserved keyword in c++ */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XKB
end_ifndef
begin_define
DECL|macro|explicit
define|#
directive|define
name|explicit
value|dont_use_cxx_explicit
end_define
begin_include
include|#
directive|include
file|<xcb/xkb.h>
end_include
begin_undef
DECL|macro|explicit
undef|#
directive|undef
name|explicit
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABLETEVENT
end_ifndef
begin_include
include|#
directive|include
file|<QTabletEvent>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_XINPUT2_MAEMO
end_ifdef
begin_struct_decl
struct_decl|struct
name|XInput2MaemoData
struct_decl|;
end_struct_decl
begin_elif
elif|#
directive|elif
name|XCB_USE_XINPUT2
end_elif
begin_include
include|#
directive|include
file|<X11/extensions/XI2.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|XI_TouchBeginMask
end_ifdef
begin_define
DECL|macro|XCB_USE_XINPUT22
define|#
directive|define
name|XCB_USE_XINPUT22
end_define
begin_comment
DECL|macro|XCB_USE_XINPUT22
comment|// XI 2.2 adds multi-point touch support
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_struct_decl
struct_decl|struct
name|XInput2DeviceData
struct_decl|;
end_struct_decl
begin_endif
endif|#
directive|endif
end_endif
begin_struct_decl
struct_decl|struct
name|xcb_randr_get_output_info_reply_t
struct_decl|;
end_struct_decl
begin_comment
comment|//#define Q_XCB_DEBUG
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbScreen
name|class
name|QXcbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbWindow
name|class
name|QXcbWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbDrag
name|class
name|QXcbDrag
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbKeyboard
name|class
name|QXcbKeyboard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbClipboard
name|class
name|QXcbClipboard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbWMSupport
name|class
name|QXcbWMSupport
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbNativeInterface
name|class
name|QXcbNativeInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbSystemTrayTracker
name|class
name|QXcbSystemTrayTracker
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QXcbAtom
block|{
enum|enum
name|Atom
block|{
comment|// window-manager<-> client protocols
name|WM_PROTOCOLS
block|,
name|WM_DELETE_WINDOW
block|,
name|WM_TAKE_FOCUS
block|,
name|_NET_WM_PING
block|,
name|_NET_WM_CONTEXT_HELP
block|,
name|_NET_WM_SYNC_REQUEST
block|,
name|_NET_WM_SYNC_REQUEST_COUNTER
block|,
name|MANAGER
block|,
comment|// System tray notification
name|_NET_SYSTEM_TRAY_OPCODE
block|,
comment|// System tray operation
comment|// ICCCM window state
name|WM_STATE
block|,
name|WM_CHANGE_STATE
block|,
name|WM_CLASS
block|,
comment|// Session management
name|WM_CLIENT_LEADER
block|,
name|WM_WINDOW_ROLE
block|,
name|SM_CLIENT_ID
block|,
comment|// Clipboard
name|CLIPBOARD
block|,
name|INCR
block|,
name|TARGETS
block|,
name|MULTIPLE
block|,
name|TIMESTAMP
block|,
name|SAVE_TARGETS
block|,
name|CLIP_TEMPORARY
block|,
name|_QT_SELECTION
block|,
name|_QT_CLIPBOARD_SENTINEL
block|,
name|_QT_SELECTION_SENTINEL
block|,
name|CLIPBOARD_MANAGER
block|,
name|RESOURCE_MANAGER
block|,
name|_XSETROOT_ID
block|,
name|_QT_SCROLL_DONE
block|,
name|_QT_INPUT_ENCODING
block|,
comment|// Qt/XCB specific
name|_QT_CLOSE_CONNECTION
block|,
name|_MOTIF_WM_HINTS
block|,
name|DTWM_IS_RUNNING
block|,
name|ENLIGHTENMENT_DESKTOP
block|,
name|_DT_SAVE_MODE
block|,
name|_SGI_DESKS_MANAGER
block|,
comment|// EWMH (aka NETWM)
name|_NET_SUPPORTED
block|,
name|_NET_VIRTUAL_ROOTS
block|,
name|_NET_WORKAREA
block|,
name|_NET_MOVERESIZE_WINDOW
block|,
name|_NET_WM_MOVERESIZE
block|,
name|_NET_WM_NAME
block|,
name|_NET_WM_ICON_NAME
block|,
name|_NET_WM_ICON
block|,
name|_NET_WM_PID
block|,
name|_NET_WM_WINDOW_OPACITY
block|,
name|_NET_WM_STATE
block|,
name|_NET_WM_STATE_ABOVE
block|,
name|_NET_WM_STATE_BELOW
block|,
name|_NET_WM_STATE_FULLSCREEN
block|,
name|_NET_WM_STATE_MAXIMIZED_HORZ
block|,
name|_NET_WM_STATE_MAXIMIZED_VERT
block|,
name|_NET_WM_STATE_MODAL
block|,
name|_NET_WM_STATE_STAYS_ON_TOP
block|,
name|_NET_WM_STATE_DEMANDS_ATTENTION
block|,
name|_NET_WM_USER_TIME
block|,
name|_NET_WM_USER_TIME_WINDOW
block|,
name|_NET_WM_FULL_PLACEMENT
block|,
name|_NET_WM_WINDOW_TYPE
block|,
name|_NET_WM_WINDOW_TYPE_DESKTOP
block|,
name|_NET_WM_WINDOW_TYPE_DOCK
block|,
name|_NET_WM_WINDOW_TYPE_TOOLBAR
block|,
name|_NET_WM_WINDOW_TYPE_MENU
block|,
name|_NET_WM_WINDOW_TYPE_UTILITY
block|,
name|_NET_WM_WINDOW_TYPE_SPLASH
block|,
name|_NET_WM_WINDOW_TYPE_DIALOG
block|,
name|_NET_WM_WINDOW_TYPE_DROPDOWN_MENU
block|,
name|_NET_WM_WINDOW_TYPE_POPUP_MENU
block|,
name|_NET_WM_WINDOW_TYPE_TOOLTIP
block|,
name|_NET_WM_WINDOW_TYPE_NOTIFICATION
block|,
name|_NET_WM_WINDOW_TYPE_COMBO
block|,
name|_NET_WM_WINDOW_TYPE_DND
block|,
name|_NET_WM_WINDOW_TYPE_NORMAL
block|,
name|_KDE_NET_WM_WINDOW_TYPE_OVERRIDE
block|,
name|_KDE_NET_WM_FRAME_STRUT
block|,
name|_NET_STARTUP_INFO
block|,
name|_NET_STARTUP_INFO_BEGIN
block|,
name|_NET_SUPPORTING_WM_CHECK
block|,
name|_NET_WM_CM_S0
block|,
name|_NET_SYSTEM_TRAY_VISUAL
block|,
name|_NET_ACTIVE_WINDOW
block|,
comment|// Property formats
name|TEXT
block|,
name|UTF8_STRING
block|,
name|CARDINAL
block|,
comment|// Xdnd
name|XdndEnter
block|,
name|XdndPosition
block|,
name|XdndStatus
block|,
name|XdndLeave
block|,
name|XdndDrop
block|,
name|XdndFinished
block|,
name|XdndTypelist
block|,
name|XdndActionList
block|,
name|XdndSelection
block|,
name|XdndAware
block|,
name|XdndProxy
block|,
name|XdndActionCopy
block|,
name|XdndActionLink
block|,
name|XdndActionMove
block|,
name|XdndActionPrivate
block|,
comment|// Motif DND
name|_MOTIF_DRAG_AND_DROP_MESSAGE
block|,
name|_MOTIF_DRAG_INITIATOR_INFO
block|,
name|_MOTIF_DRAG_RECEIVER_INFO
block|,
name|_MOTIF_DRAG_WINDOW
block|,
name|_MOTIF_DRAG_TARGETS
block|,
name|XmTRANSFER_SUCCESS
block|,
name|XmTRANSFER_FAILURE
block|,
comment|// Xkb
name|_XKB_RULES_NAMES
block|,
comment|// XEMBED
name|_XEMBED
block|,
name|_XEMBED_INFO
block|,
comment|// XInput2
name|ButtonLeft
block|,
name|ButtonMiddle
block|,
name|ButtonRight
block|,
name|ButtonWheelUp
block|,
name|ButtonWheelDown
block|,
name|ButtonHorizWheelLeft
block|,
name|ButtonHorizWheelRight
block|,
name|AbsMTPositionX
block|,
name|AbsMTPositionY
block|,
name|AbsMTTouchMajor
block|,
name|AbsMTTouchMinor
block|,
name|AbsMTPressure
block|,
name|AbsMTTrackingID
block|,
name|MaxContacts
block|,
name|RelX
block|,
name|RelY
block|,
comment|// XInput2 tablet
name|AbsX
block|,
name|AbsY
block|,
name|AbsPressure
block|,
name|AbsTiltX
block|,
name|AbsTiltY
block|,
name|AbsWheel
block|,
name|AbsDistance
block|,
name|WacomSerialIDs
block|,
name|INTEGER
block|,
if|#
directive|if
name|XCB_USE_MAEMO_WINDOW_PROPERTIES
name|MeegoTouchOrientationAngle
block|,
endif|#
directive|endif
name|_XSETTINGS_SETTINGS
block|,
name|NPredefinedAtoms
block|,
name|_QT_SETTINGS_TIMESTAMP
init|=
name|NPredefinedAtoms
block|,
name|NAtoms
block|}
enum|;
block|}
end_decl_stmt
begin_typedef
DECL|typedef|xcb_generic_event_t
DECL|typedef|QXcbEventArray
typedef|typedef
name|QVarLengthArray
operator|<
name|xcb_generic_event_t
operator|*
operator|,
literal|64
operator|>
name|QXcbEventArray
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|variable|QXcbConnection
name|class
name|QXcbConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXcbEventReader
range|:
name|public
name|QThread
block|{
name|Q_OBJECT
name|public
operator|:
name|QXcbEventReader
argument_list|(
name|QXcbConnection
operator|*
name|connection
argument_list|)
block|;
name|void
name|run
argument_list|()
block|;
name|QXcbEventArray
operator|*
name|lock
argument_list|()
block|;
name|void
name|unlock
argument_list|()
block|;
name|bool
name|startThread
argument_list|()
block|;
name|signals
operator|:
name|void
name|eventPending
argument_list|()
block|;
name|private
operator|:
name|void
name|addEvent
argument_list|(
name|xcb_generic_event_t
operator|*
name|event
argument_list|)
block|;
name|QMutex
name|m_mutex
block|;
name|QXcbEventArray
name|m_events
block|;
name|QXcbConnection
operator|*
name|m_connection
block|;
typedef|typedef
name|xcb_generic_event_t
modifier|*
function_decl|(
modifier|*
name|XcbPollForQueuedEventFunctionPointer
function_decl|)
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
parameter_list|)
function_decl|;
name|XcbPollForQueuedEventFunctionPointer
name|m_xcb_poll_for_queued_event
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|QXcbWindowEventListener
block|{
name|public
label|:
name|virtual
name|bool
name|handleGenericEvent
parameter_list|(
name|xcb_generic_event_t
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|void
name|handleExposeEvent
parameter_list|(
specifier|const
name|xcb_expose_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleClientMessageEvent
parameter_list|(
specifier|const
name|xcb_client_message_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleConfigureNotifyEvent
parameter_list|(
specifier|const
name|xcb_configure_notify_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleMapNotifyEvent
parameter_list|(
specifier|const
name|xcb_map_notify_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleUnmapNotifyEvent
parameter_list|(
specifier|const
name|xcb_unmap_notify_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleDestroyNotifyEvent
parameter_list|(
specifier|const
name|xcb_destroy_notify_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleButtonPressEvent
parameter_list|(
specifier|const
name|xcb_button_press_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleButtonReleaseEvent
parameter_list|(
specifier|const
name|xcb_button_release_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleMotionNotifyEvent
parameter_list|(
specifier|const
name|xcb_motion_notify_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleEnterNotifyEvent
parameter_list|(
specifier|const
name|xcb_enter_notify_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleLeaveNotifyEvent
parameter_list|(
specifier|const
name|xcb_leave_notify_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleFocusInEvent
parameter_list|(
specifier|const
name|xcb_focus_in_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handleFocusOutEvent
parameter_list|(
specifier|const
name|xcb_focus_out_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|handlePropertyNotifyEvent
parameter_list|(
specifier|const
name|xcb_property_notify_event_t
modifier|*
parameter_list|)
block|{}
name|virtual
name|QXcbWindow
modifier|*
name|toWindow
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
DECL|typedef|xcb_window_t
DECL|typedef|WindowMapper
typedef|typedef
name|QHash
operator|<
name|xcb_window_t
operator|,
name|QXcbWindowEventListener
operator|*
operator|>
name|WindowMapper
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXcbConnection
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QXcbConnection
argument_list|(
argument|QXcbNativeInterface *nativeInterface
argument_list|,
argument|bool canGrabServer
argument_list|,
argument|const char *displayName =
literal|0
argument_list|)
block|;
operator|~
name|QXcbConnection
argument_list|()
block|;
name|QXcbConnection
operator|*
name|connection
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|QXcbConnection
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
specifier|const
name|QList
operator|<
name|QXcbScreen
operator|*
operator|>
operator|&
name|screens
argument_list|()
specifier|const
block|{
return|return
name|m_screens
return|;
block|}
name|int
name|primaryScreen
argument_list|()
specifier|const
block|{
return|return
name|m_primaryScreen
return|;
block|}
specifier|inline
name|xcb_atom_t
name|atom
argument_list|(
argument|QXcbAtom::Atom atom
argument_list|)
specifier|const
block|{
return|return
name|m_allAtoms
index|[
name|atom
index|]
return|;
block|}
name|QXcbAtom
operator|::
name|Atom
name|qatom
argument_list|(
argument|xcb_atom_t atom
argument_list|)
specifier|const
block|;
name|xcb_atom_t
name|internAtom
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|QByteArray
name|atomName
argument_list|(
argument|xcb_atom_t atom
argument_list|)
block|;
specifier|const
name|char
operator|*
name|displayName
argument_list|()
specifier|const
block|{
return|return
name|m_displayName
operator|.
name|constData
argument_list|()
return|;
block|}
name|xcb_connection_t
operator|*
name|xcb_connection
argument_list|()
specifier|const
block|{
return|return
name|m_connection
return|;
block|}
specifier|const
name|xcb_setup_t
operator|*
name|setup
argument_list|()
specifier|const
block|{
return|return
name|m_setup
return|;
block|}
specifier|const
name|xcb_format_t
operator|*
name|formatForDepth
argument_list|(
argument|uint8_t depth
argument_list|)
specifier|const
block|;
name|QXcbKeyboard
operator|*
name|keyboard
argument_list|()
specifier|const
block|{
return|return
name|m_keyboard
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|QXcbClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
block|{
return|return
name|m_clipboard
return|;
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|QXcbDrag
operator|*
name|drag
argument_list|()
specifier|const
block|{
return|return
name|m_drag
return|;
block|}
endif|#
directive|endif
name|QXcbWMSupport
operator|*
name|wmSupport
argument_list|()
specifier|const
block|{
return|return
name|m_wmSupport
operator|.
name|data
argument_list|()
return|;
block|}
name|xcb_window_t
name|rootWindow
argument_list|()
block|;
ifdef|#
directive|ifdef
name|XCB_USE_XLIB
name|void
operator|*
name|xlib_display
argument_list|()
specifier|const
block|{
return|return
name|m_xlib_display
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XCB_USE_EGL
name|bool
name|hasEgl
argument_list|()
specifier|const
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
name|void
operator|*
name|egl_display
argument_list|()
specifier|const
block|{
return|return
name|m_egl_display
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XCB_USE_XINPUT2_MAEMO
name|bool
name|isUsingXInput2Maemo
argument_list|()
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_XINPUT2
argument_list|)
name|void
name|xi2Select
argument_list|(
argument|xcb_window_t window
argument_list|)
block|;
endif|#
directive|endif
name|void
name|sync
argument_list|()
block|;
name|void
name|flush
argument_list|()
block|{
name|xcb_flush
argument_list|(
name|m_connection
argument_list|)
block|; }
name|void
name|handleXcbError
argument_list|(
name|xcb_generic_error_t
operator|*
name|error
argument_list|)
block|;
name|void
name|handleXcbEvent
argument_list|(
name|xcb_generic_event_t
operator|*
name|event
argument_list|)
block|;
name|void
name|addWindowEventListener
argument_list|(
argument|xcb_window_t id
argument_list|,
argument|QXcbWindowEventListener *eventListener
argument_list|)
block|;
name|void
name|removeWindowEventListener
argument_list|(
argument|xcb_window_t id
argument_list|)
block|;
name|QXcbWindowEventListener
operator|*
name|windowEventListenerFromId
argument_list|(
argument|xcb_window_t id
argument_list|)
block|;
name|QXcbWindow
operator|*
name|platformWindowFromId
argument_list|(
argument|xcb_window_t id
argument_list|)
block|;
name|xcb_generic_event_t
operator|*
name|checkEvent
argument_list|(
argument|int type
argument_list|)
block|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|xcb_generic_event_t
operator|*
name|checkEvent
argument_list|(
name|T
operator|&
name|checker
argument_list|)
block|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|PeekFunc
function_decl|)
parameter_list|(
name|QXcbConnection
modifier|*
parameter_list|,
name|xcb_generic_event_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|addPeekFunc
argument_list|(
argument|PeekFunc f
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|xcb_timestamp_t
name|time
argument_list|()
specifier|const
block|{
return|return
name|m_time
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|setTime
parameter_list|(
name|xcb_timestamp_t
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|>
name|m_time
condition|)
name|m_time
operator|=
name|t
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|xcb_timestamp_t
name|netWmUserTime
argument_list|()
specifier|const
block|{
return|return
name|m_netWmUserTime
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|setNetWmUserTime
parameter_list|(
name|xcb_timestamp_t
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|>
name|m_netWmUserTime
condition|)
name|m_netWmUserTime
operator|=
name|t
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|hasGLX
argument_list|()
specifier|const
block|{
return|return
name|has_glx_extension
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|hasXFixes
argument_list|()
specifier|const
block|{
return|return
name|xfixes_first_event
operator|>
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|hasXShape
argument_list|()
specifier|const
block|{
return|return
name|has_shape_extension
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|hasXRandr
argument_list|()
specifier|const
block|{
return|return
name|has_randr_extension
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|hasInputShape
argument_list|()
specifier|const
block|{
return|return
name|has_input_shape
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|hasTouchWithoutMouseEmulation
argument_list|()
specifier|const
block|{
return|return
name|has_touch_without_mouse_emulation
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|hasXKB
argument_list|()
specifier|const
block|{
return|return
name|has_xkb
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|supportsThreadedRendering
argument_list|()
specifier|const
block|{
return|return
name|m_reader
operator|->
name|isRunning
argument_list|()
return|;
block|}
end_expr_stmt
begin_function_decl
name|xcb_timestamp_t
name|getTimestamp
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|Qt
operator|::
name|MouseButtons
name|buttons
argument_list|()
specifier|const
block|{
return|return
name|m_buttons
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QXcbWindow
operator|*
name|focusWindow
argument_list|()
specifier|const
block|{
return|return
name|m_focusWindow
return|;
block|}
end_expr_stmt
begin_function_decl
name|void
name|setFocusWindow
parameter_list|(
name|QXcbWindow
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QByteArray
name|startupId
argument_list|()
specifier|const
block|{
return|return
name|m_startupId
return|;
block|}
end_expr_stmt
begin_function
name|void
name|clearStartupId
parameter_list|()
block|{
name|m_startupId
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|grabServer
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|ungrabServer
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|QXcbNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
block|{
return|return
name|m_nativeInterface
return|;
block|}
end_expr_stmt
begin_function_decl
name|QXcbSystemTrayTracker
modifier|*
name|systemTrayTracker
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|private
name|slots
range|:
name|void
name|processXcbEvents
argument_list|()
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_function_decl
name|void
name|initializeAllAtoms
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|sendConnectionEvent
argument_list|(
name|QXcbAtom
operator|::
name|Atom
name|atom
argument_list|,
name|uint
name|id
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|initializeGLX
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|initializeXFixes
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|initializeXRender
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|initializeXRandr
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|initializeXShape
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|initializeXKB
parameter_list|()
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_XINPUT2_MAEMO
end_ifdef
begin_function_decl
name|void
name|initializeXInput2Maemo
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|finalizeXInput2Maemo
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleGenericEventMaemo
parameter_list|(
name|xcb_ge_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|handleClientMessageEvent
parameter_list|(
specifier|const
name|xcb_client_message_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QXcbScreen
modifier|*
name|findOrCreateScreen
argument_list|(
name|QList
operator|<
name|QXcbScreen
operator|*
operator|>
operator|&
name|newScreens
argument_list|,
name|int
name|screenNumber
argument_list|,
name|xcb_screen_t
operator|*
name|xcbScreen
argument_list|,
name|xcb_randr_get_output_info_reply_t
operator|*
name|output
operator|=
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|updateScreens
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleButtonPress
parameter_list|(
name|xcb_generic_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|handleButtonRelease
parameter_list|(
name|xcb_generic_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|m_xi2Enabled
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_xi2Minor
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_XINPUT2
end_ifdef
begin_function_decl
name|void
name|initializeXInput2
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|finalizeXInput2
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|XInput2DeviceData
modifier|*
name|deviceForId
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|xi2HandleEvent
parameter_list|(
name|xcb_ge_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|int
name|m_xiOpCode
decl_stmt|,
name|m_xiEventBase
decl_stmt|,
name|m_xiErrorBase
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABLETEVENT
end_ifndef
begin_struct
struct|struct
name|TabletData
block|{
name|TabletData
argument_list|()
operator|:
name|deviceId
argument_list|(
literal|0
argument_list|)
operator|,
name|down
argument_list|(
name|false
argument_list|)
operator|,
name|serialId
argument_list|(
literal|0
argument_list|)
operator|,
name|inProximity
argument_list|(
argument|false
argument_list|)
block|{ }
name|int
name|deviceId
expr_stmt|;
name|QTabletEvent
operator|::
name|PointerType
name|pointerType
expr_stmt|;
name|bool
name|down
decl_stmt|;
name|qint64
name|serialId
decl_stmt|;
name|bool
name|inProximity
decl_stmt|;
struct|struct
name|ValuatorClassInfo
block|{
name|ValuatorClassInfo
argument_list|()
operator|:
name|minVal
argument_list|(
literal|0
argument_list|)
operator|,
name|maxVal
argument_list|(
literal|0
argument_list|)
block|{ }
name|double
name|minVal
expr_stmt|;
name|double
name|maxVal
decl_stmt|;
name|int
name|number
decl_stmt|;
block|}
struct|;
name|QHash
operator|<
name|int
operator|,
name|ValuatorClassInfo
operator|>
name|valuatorInfo
expr_stmt|;
block|}
struct|;
end_struct
begin_function_decl
name|bool
name|xi2HandleTabletEvent
parameter_list|(
name|void
modifier|*
name|event
parameter_list|,
name|TabletData
modifier|*
name|tabletData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|xi2ReportTabletEvent
parameter_list|(
specifier|const
name|TabletData
modifier|&
name|tabletData
parameter_list|,
name|void
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QVector
operator|<
name|TabletData
operator|>
name|m_tabletData
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// XCB_USE_XINPUT2
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_XINPUT2
argument_list|)
operator|||
name|defined
argument_list|(
name|XCB_USE_XINPUT2_MAEMO
argument_list|)
end_if
begin_function_decl
specifier|static
name|int
name|xi2CountBits
parameter_list|(
name|unsigned
name|char
modifier|*
name|ptr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|xi2GetValuatorValueIfSet
parameter_list|(
name|void
modifier|*
name|event
parameter_list|,
name|int
name|valuatorNum
parameter_list|,
name|double
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|xi2PrepareXIGenericDeviceEvent
parameter_list|(
name|xcb_ge_event_t
modifier|*
name|event
parameter_list|,
name|int
name|opCode
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|xcb_connection_t
modifier|*
name|m_connection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|xcb_setup_t
modifier|*
name|m_setup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_canGrabServer
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QXcbScreen
operator|*
operator|>
name|m_screens
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|m_primaryScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|xcb_atom_t
name|m_allAtoms
index|[
name|QXcbAtom
operator|::
name|NAtoms
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|xcb_timestamp_t
name|m_time
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|xcb_timestamp_t
name|m_netWmUserTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|m_displayName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|xcb_window_t
name|m_connectionEventListener
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QXcbKeyboard
modifier|*
name|m_keyboard
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_decl_stmt
name|QXcbClipboard
modifier|*
name|m_clipboard
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_decl_stmt
name|QXcbDrag
modifier|*
name|m_drag
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QScopedPointer
operator|<
name|QXcbWMSupport
operator|>
name|m_wmSupport
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QXcbNativeInterface
modifier|*
name|m_nativeInterface
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_XLIB
argument_list|)
end_if
begin_decl_stmt
name|void
modifier|*
name|m_xlib_display
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QXcbEventReader
modifier|*
name|m_reader
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_XINPUT2_MAEMO
end_ifdef
begin_decl_stmt
name|XInput2MaemoData
modifier|*
name|m_xinputData
decl_stmt|;
end_decl_stmt
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|XCB_USE_XINPUT2
argument_list|)
end_elif
begin_expr_stmt
name|QHash
operator|<
name|int
operator|,
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|>
name|m_touchPoints
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|int
operator|,
name|XInput2DeviceData
operator|*
operator|>
name|m_touchDevices
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
end_if
begin_decl_stmt
name|void
modifier|*
name|m_egl_display
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_has_egl
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_XCB_DEBUG
end_ifdef
begin_struct
struct|struct
name|CallInfo
block|{
name|int
name|sequence
decl_stmt|;
name|QByteArray
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QVector
operator|<
name|CallInfo
operator|>
name|m_callLog
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QMutex
name|m_callLogMutex
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|log
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|int
name|sequence
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|cookie_t
operator|>
name|friend
name|cookie_t
name|q_xcb_call_template
argument_list|(
argument|const cookie_t&cookie
argument_list|,
argument|QXcbConnection *connection
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|WindowMapper
name|m_mapper
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QVector
operator|<
name|PeekFunc
operator|>
name|m_peekFuncs
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|uint32_t
name|xfixes_first_event
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint32_t
name|xrandr_first_event
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint32_t
name|xkb_first_event
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|has_glx_extension
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|has_shape_extension
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|has_randr_extension
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|has_input_shape
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|has_touch_without_mouse_emulation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|has_xkb
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|MouseButtons
name|m_buttons
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QXcbWindow
modifier|*
name|m_focusWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|m_startupId
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QXcbSystemTrayTracker
modifier|*
name|m_systemTrayTracker
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|DISPLAY_FROM_XCB
unit|};
define|#
directive|define
name|DISPLAY_FROM_XCB
parameter_list|(
name|object
parameter_list|)
value|((Display *)(object->connection()->xlib_display()))
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|checkEvent
name|xcb_generic_event_t
operator|*
name|QXcbConnection
operator|::
name|checkEvent
argument_list|(
argument|T&checker
argument_list|)
block|{
name|QXcbEventArray
operator|*
name|eventqueue
operator|=
name|m_reader
operator|->
name|lock
argument_list|()
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|eventqueue
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|xcb_generic_event_t
modifier|*
name|event
init|=
name|eventqueue
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|checker
operator|.
name|checkEvent
argument_list|(
name|event
argument_list|)
condition|)
block|{
operator|(
operator|*
name|eventqueue
operator|)
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|m_reader
operator|->
name|unlock
argument_list|()
expr_stmt|;
return|return
name|event
return|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}     m_reader
operator|->
name|unlock
argument_list|()
expr_stmt|;
end_expr_stmt
begin_return
return|return
literal|0
return|;
end_return
begin_macro
unit|}  class
name|QXcbConnectionGrabber
end_macro
begin_block
block|{
name|public
label|:
name|QXcbConnectionGrabber
argument_list|(
name|QXcbConnection
operator|*
name|connection
argument_list|)
expr_stmt|;
operator|~
name|QXcbConnectionGrabber
argument_list|()
expr_stmt|;
name|void
name|release
parameter_list|()
function_decl|;
name|private
label|:
name|QXcbConnection
modifier|*
name|m_connection
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_XCB_DEBUG
end_ifdef
begin_expr_stmt
name|template
operator|<
name|typename
name|cookie_t
operator|>
DECL|function|q_xcb_call_template
name|cookie_t
name|q_xcb_call_template
argument_list|(
argument|const cookie_t&cookie
argument_list|,
argument|QXcbConnection *connection
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
name|connection
operator|->
name|log
argument_list|(
name|file
argument_list|,
name|line
argument_list|,
name|cookie
operator|.
name|sequence
argument_list|)
block|;
return|return
name|cookie
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|Q_XCB_CALL
define|#
directive|define
name|Q_XCB_CALL
parameter_list|(
name|x
parameter_list|)
value|q_xcb_call_template(x, connection(), __FILE__, __LINE__)
end_define
begin_define
DECL|macro|Q_XCB_CALL2
define|#
directive|define
name|Q_XCB_CALL2
parameter_list|(
name|x
parameter_list|,
name|connection
parameter_list|)
value|q_xcb_call_template(x, connection, __FILE__, __LINE__)
end_define
begin_define
DECL|macro|Q_XCB_NOOP
define|#
directive|define
name|Q_XCB_NOOP
parameter_list|(
name|c
parameter_list|)
value|q_xcb_call_template(xcb_no_operation(c->xcb_connection()), c, __FILE__, __LINE__);
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_XCB_CALL
define|#
directive|define
name|Q_XCB_CALL
parameter_list|(
name|x
parameter_list|)
value|x
end_define
begin_define
DECL|macro|Q_XCB_CALL2
define|#
directive|define
name|Q_XCB_CALL2
parameter_list|(
name|x
parameter_list|,
name|connection
parameter_list|)
value|x
end_define
begin_define
DECL|macro|Q_XCB_NOOP
define|#
directive|define
name|Q_XCB_NOOP
parameter_list|(
name|c
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
end_if
begin_define
DECL|macro|EGL_DISPLAY_FROM_XCB
define|#
directive|define
name|EGL_DISPLAY_FROM_XCB
parameter_list|(
name|object
parameter_list|)
value|((EGLDisplay)(object->connection()->egl_display()))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
