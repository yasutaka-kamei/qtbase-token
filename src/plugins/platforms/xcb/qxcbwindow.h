begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
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
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbScreen
name|class
name|QXcbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbEGLSurface
name|class
name|QXcbEGLSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIcon
name|class
name|QIcon
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
enum|enum
name|NetWmState
block|{
name|NetWmStateAbove
init|=
literal|0x1
block|,
name|NetWmStateBelow
init|=
literal|0x2
block|,
name|NetWmStateFullScreen
init|=
literal|0x4
block|,
name|NetWmStateMaximizedHorz
init|=
literal|0x8
block|,
name|NetWmStateMaximizedVert
init|=
literal|0x10
block|,
name|NetWmStateModal
init|=
literal|0x20
block|,
name|NetWmStateStaysOnTop
init|=
literal|0x40
block|,
name|NetWmStateDemandsAttention
init|=
literal|0x80
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|NetWmStates
argument_list|,
argument|NetWmState
argument_list|)
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
name|QMargins
name|frameMargins
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
name|void
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
decl_stmt|;
name|void
name|setWindowState
argument_list|(
name|Qt
operator|::
name|WindowState
name|state
argument_list|)
decl_stmt|;
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
name|bool
name|isExposed
argument_list|()
specifier|const
expr_stmt|;
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
name|setWindowIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
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
if|#
directive|if
name|XCB_USE_MAEMO_WINDOW_PROPERTIES
name|void
name|handleContentOrientationChange
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|bool
name|setKeyboardGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
function_decl|;
name|bool
name|setMouseGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
function_decl|;
name|void
name|setCursor
parameter_list|(
name|xcb_cursor_t
name|cursor
parameter_list|)
function_decl|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|startSystemResize
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|Qt
operator|::
name|Corner
name|corner
argument_list|)
decl_stmt|;
name|void
name|setOpacity
parameter_list|(
name|qreal
name|level
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_SHAPE
argument_list|)
name|void
name|setMask
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// !QT_NO_SHAPE
name|xcb_window_t
name|xcb_window
argument_list|()
specifier|const
block|{
return|return
name|m_window
return|;
block|}
name|uint
name|depth
argument_list|()
specifier|const
block|{
return|return
name|m_depth
return|;
block|}
name|QImage
operator|::
name|Format
name|imageFormat
argument_list|()
specifier|const
block|{
return|return
name|m_imageFormat
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
name|handleMapNotifyEvent
parameter_list|(
specifier|const
name|xcb_map_notify_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleUnmapNotifyEvent
parameter_list|(
specifier|const
name|xcb_unmap_notify_event_t
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
name|handlePropertyNotifyEvent
parameter_list|(
specifier|const
name|xcb_property_notify_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleMouseEvent
argument_list|(
name|xcb_timestamp_t
name|time
argument_list|,
specifier|const
name|QPoint
operator|&
name|local
argument_list|,
specifier|const
name|QPoint
operator|&
name|global
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|)
decl_stmt|;
name|void
name|updateSyncRequestCounter
parameter_list|()
function_decl|;
name|void
name|updateNetWmUserTime
parameter_list|(
name|xcb_timestamp_t
name|timestamp
parameter_list|)
function_decl|;
name|void
name|netWmUserTime
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
name|QXcbEGLSurface
operator|*
name|eglSurface
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|private
label|:
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
name|NetWmStates
name|netWmStates
parameter_list|()
function_decl|;
name|void
name|setNetWmStates
parameter_list|(
name|NetWmStates
parameter_list|)
function_decl|;
name|void
name|setNetWmWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
decl_stmt|;
name|void
name|setMotifWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
decl_stmt|;
name|void
name|updateMotifWmHintsBeforeMap
parameter_list|()
function_decl|;
name|void
name|updateNetWmStateBeforeMap
parameter_list|()
function_decl|;
name|void
name|setTransparentForMouseEvents
parameter_list|(
name|bool
name|transparent
parameter_list|)
function_decl|;
name|void
name|updateDoesNotAcceptFocus
parameter_list|(
name|bool
name|doesNotAcceptFocus
parameter_list|)
function_decl|;
name|QRect
name|windowToWmGeometry
argument_list|(
name|QRect
name|r
argument_list|)
decl|const
decl_stmt|;
name|void
name|create
parameter_list|()
function_decl|;
name|void
name|destroy
parameter_list|()
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
name|uint
name|m_depth
decl_stmt|;
name|QImage
operator|::
name|Format
name|m_imageFormat
expr_stmt|;
name|xcb_sync_int64_t
name|m_syncValue
decl_stmt|;
name|xcb_sync_counter_t
name|m_syncCounter
decl_stmt|;
name|Qt
operator|::
name|WindowState
name|m_windowState
expr_stmt|;
name|xcb_gravity_t
name|m_gravity
decl_stmt|;
name|bool
name|m_mapped
decl_stmt|;
name|bool
name|m_transparent
decl_stmt|;
name|bool
name|m_deferredActivation
decl_stmt|;
name|bool
name|m_deferredExpose
decl_stmt|;
name|bool
name|m_configureNotifyPending
decl_stmt|;
name|xcb_window_t
name|m_netWmUserTimeWindow
decl_stmt|;
name|QSurfaceFormat
name|m_format
decl_stmt|;
name|mutable
name|bool
name|m_dirtyFrameMargins
decl_stmt|;
name|mutable
name|QMargins
name|m_frameMargins
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_EGL
argument_list|)
name|mutable
name|QXcbEGLSurface
modifier|*
name|m_eglSurface
decl_stmt|;
endif|#
directive|endif
name|QRegion
name|m_exposeRegion
decl_stmt|;
name|xcb_visualid_t
name|m_visualId
decl_stmt|;
name|int
name|m_lastWindowStateEvent
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
