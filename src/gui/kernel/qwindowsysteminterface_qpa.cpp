begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsysteminterface_qpa.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsysteminterface_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qguiapplication_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qtouchdevice_p.h"
end_include
begin_include
include|#
directive|include
file|<QAbstractEventDispatcher>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|eventTime
name|QTime
name|QWindowSystemInterfacePrivate
operator|::
name|eventTime
decl_stmt|;
end_decl_stmt
begin_comment
comment|//------------------------------------------------------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Callback functions for plugins:
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
DECL|member|windowSystemEventQueue
name|QList
argument_list|<
name|QWindowSystemInterfacePrivate
operator|::
name|WindowSystemEvent
operator|*
argument_list|>
name|QWindowSystemInterfacePrivate
operator|::
name|windowSystemEventQueue
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|queueMutex
name|QMutex
name|QWindowSystemInterfacePrivate
operator|::
name|queueMutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|QPointer
argument_list|<
name|QWindow
argument_list|>
name|qt_last_mouse_receiver
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \class QWindowSystemInterface     \since 5.0     \internal     \preliminary     \ingroup qpa     \brief The QWindowSystemInterface provides an event queue for the QPA platform.      The platform plugins call the various functions to notify about events. The events are queued     until sendWindowSystemEvents() is called by the event dispatcher. */
end_comment
begin_function
DECL|function|handleEnterEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleEnterEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|)
block|{
if|if
condition|(
name|tlw
condition|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|EnterEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|EnterEvent
argument_list|(
name|tlw
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleLeaveEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleLeaveEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|LeaveEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|LeaveEvent
argument_list|(
name|tlw
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleWindowActivated
name|void
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|ActivatedWindowEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|ActivatedWindowEvent
argument_list|(
name|tlw
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleWindowStateChanged
name|void
name|QWindowSystemInterface
operator|::
name|handleWindowStateChanged
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
name|Qt
operator|::
name|WindowState
name|newState
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|WindowStateChangedEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|WindowStateChangedEvent
argument_list|(
name|tlw
argument_list|,
name|newState
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleGeometryChange
name|void
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
specifier|const
name|QRect
modifier|&
name|newRect
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|GeometryChangeEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|GeometryChangeEvent
argument_list|(
name|tlw
argument_list|,
name|newRect
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleSynchronousGeometryChange
name|void
name|QWindowSystemInterface
operator|::
name|handleSynchronousGeometryChange
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
specifier|const
name|QRect
modifier|&
name|newRect
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|GeometryChangeEvent
name|e
argument_list|(
name|tlw
argument_list|,
name|newRect
argument_list|)
decl_stmt|;
name|QGuiApplicationPrivate
operator|::
name|processWindowSystemEvent
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
comment|// send event immediately.
block|}
end_function
begin_function
DECL|function|handleCloseEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleCloseEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|)
block|{
if|if
condition|(
name|tlw
condition|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|CloseEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|CloseEvent
argument_list|(
name|tlw
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleSynchronousCloseEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleSynchronousCloseEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|)
block|{
if|if
condition|(
name|tlw
condition|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|CloseEvent
name|e
argument_list|(
name|tlw
argument_list|)
decl_stmt|;
name|QGuiApplicationPrivate
operator|::
name|processWindowSystemEvent
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!  \a tlw == 0 means that \a ev is in global coords only   */
end_comment
begin_function
DECL|function|handleMouseEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|local
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|global
parameter_list|,
name|Qt
operator|::
name|MouseButtons
name|b
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
parameter_list|)
block|{
name|unsigned
name|long
name|time
init|=
name|QWindowSystemInterfacePrivate
operator|::
name|eventTime
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|handleMouseEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|local
argument_list|,
name|global
argument_list|,
name|b
argument_list|,
name|mods
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleMouseEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
name|ulong
name|timestamp
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|local
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|global
parameter_list|,
name|Qt
operator|::
name|MouseButtons
name|b
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|MouseEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|MouseEvent
argument_list|(
name|tlw
argument_list|,
name|timestamp
argument_list|,
name|local
argument_list|,
name|global
argument_list|,
name|b
argument_list|,
name|mods
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleKeyEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleKeyEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
name|QEvent
operator|::
name|Type
name|t
parameter_list|,
name|int
name|k
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|bool
name|autorep
parameter_list|,
name|ushort
name|count
parameter_list|)
block|{
name|unsigned
name|long
name|time
init|=
name|QWindowSystemInterfacePrivate
operator|::
name|eventTime
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|handleKeyEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|t
argument_list|,
name|k
argument_list|,
name|mods
argument_list|,
name|text
argument_list|,
name|autorep
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleKeyEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleKeyEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
name|ulong
name|timestamp
parameter_list|,
name|QEvent
operator|::
name|Type
name|t
parameter_list|,
name|int
name|k
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|bool
name|autorep
parameter_list|,
name|ushort
name|count
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|KeyEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|KeyEvent
argument_list|(
name|tlw
argument_list|,
name|timestamp
argument_list|,
name|t
argument_list|,
name|k
argument_list|,
name|mods
argument_list|,
name|text
argument_list|,
name|autorep
argument_list|,
name|count
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleExtendedKeyEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleExtendedKeyEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
name|QEvent
operator|::
name|Type
name|type
parameter_list|,
name|int
name|key
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|,
name|quint32
name|nativeScanCode
parameter_list|,
name|quint32
name|nativeVirtualKey
parameter_list|,
name|quint32
name|nativeModifiers
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|bool
name|autorep
parameter_list|,
name|ushort
name|count
parameter_list|)
block|{
name|unsigned
name|long
name|time
init|=
name|QWindowSystemInterfacePrivate
operator|::
name|eventTime
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|handleExtendedKeyEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|type
argument_list|,
name|key
argument_list|,
name|modifiers
argument_list|,
name|nativeScanCode
argument_list|,
name|nativeVirtualKey
argument_list|,
name|nativeModifiers
argument_list|,
name|text
argument_list|,
name|autorep
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleExtendedKeyEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleExtendedKeyEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
name|ulong
name|timestamp
parameter_list|,
name|QEvent
operator|::
name|Type
name|type
parameter_list|,
name|int
name|key
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|,
name|quint32
name|nativeScanCode
parameter_list|,
name|quint32
name|nativeVirtualKey
parameter_list|,
name|quint32
name|nativeModifiers
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|bool
name|autorep
parameter_list|,
name|ushort
name|count
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|KeyEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|KeyEvent
argument_list|(
name|tlw
argument_list|,
name|timestamp
argument_list|,
name|type
argument_list|,
name|key
argument_list|,
name|modifiers
argument_list|,
name|nativeScanCode
argument_list|,
name|nativeVirtualKey
argument_list|,
name|nativeModifiers
argument_list|,
name|text
argument_list|,
name|autorep
argument_list|,
name|count
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleWheelEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleWheelEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|local
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|global
parameter_list|,
name|int
name|d
parameter_list|,
name|Qt
operator|::
name|Orientation
name|o
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
parameter_list|)
block|{
name|unsigned
name|long
name|time
init|=
name|QWindowSystemInterfacePrivate
operator|::
name|eventTime
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|handleWheelEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|local
argument_list|,
name|global
argument_list|,
name|d
argument_list|,
name|o
argument_list|,
name|mods
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleWheelEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleWheelEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
name|ulong
name|timestamp
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|local
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|global
parameter_list|,
name|int
name|d
parameter_list|,
name|Qt
operator|::
name|Orientation
name|o
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|WheelEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|WheelEvent
argument_list|(
name|tlw
argument_list|,
name|timestamp
argument_list|,
name|local
argument_list|,
name|global
argument_list|,
name|d
argument_list|,
name|o
argument_list|,
name|mods
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|windowSystemEventsQueued
name|int
name|QWindowSystemInterfacePrivate
operator|::
name|windowSystemEventsQueued
parameter_list|()
block|{
name|queueMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|int
name|ret
init|=
name|windowSystemEventQueue
operator|.
name|count
argument_list|()
decl_stmt|;
name|queueMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|getWindowSystemEvent
name|QWindowSystemInterfacePrivate
operator|::
name|WindowSystemEvent
modifier|*
name|QWindowSystemInterfacePrivate
operator|::
name|getWindowSystemEvent
parameter_list|()
block|{
name|queueMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|WindowSystemEvent
modifier|*
name|ret
decl_stmt|;
if|if
condition|(
name|windowSystemEventQueue
operator|.
name|isEmpty
argument_list|()
condition|)
name|ret
operator|=
literal|0
expr_stmt|;
else|else
name|ret
operator|=
name|windowSystemEventQueue
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
name|queueMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|queueWindowSystemEvent
name|void
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
parameter_list|(
name|QWindowSystemInterfacePrivate
operator|::
name|WindowSystemEvent
modifier|*
name|ev
parameter_list|)
block|{
name|queueMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|windowSystemEventQueue
operator|.
name|append
argument_list|(
name|ev
argument_list|)
expr_stmt|;
name|queueMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|QAbstractEventDispatcher
modifier|*
name|dispatcher
init|=
name|QGuiApplicationPrivate
operator|::
name|qt_qpa_core_dispatcher
argument_list|()
decl_stmt|;
if|if
condition|(
name|dispatcher
condition|)
name|dispatcher
operator|->
name|wakeUp
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|registerTouchDevice
name|void
name|QWindowSystemInterface
operator|::
name|registerTouchDevice
parameter_list|(
name|QTouchDevice
modifier|*
name|device
parameter_list|)
block|{
name|QTouchDevicePrivate
operator|::
name|registerDevice
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleTouchEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleTouchEvent
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
name|QTouchDevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QList
argument_list|<
name|TouchPoint
argument_list|>
modifier|&
name|points
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
parameter_list|)
block|{
name|unsigned
name|long
name|time
init|=
name|QWindowSystemInterfacePrivate
operator|::
name|eventTime
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|handleTouchEvent
argument_list|(
name|w
argument_list|,
name|time
argument_list|,
name|device
argument_list|,
name|points
argument_list|,
name|mods
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|convertTouchPoints
name|QList
argument_list|<
name|QTouchEvent
operator|::
name|TouchPoint
argument_list|>
name|QWindowSystemInterfacePrivate
operator|::
name|convertTouchPoints
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
modifier|&
name|points
parameter_list|,
name|QEvent
operator|::
name|Type
modifier|*
name|type
parameter_list|)
block|{
name|QList
argument_list|<
name|QTouchEvent
operator|::
name|TouchPoint
argument_list|>
name|touchPoints
decl_stmt|;
name|Qt
operator|::
name|TouchPointStates
name|states
decl_stmt|;
name|QTouchEvent
operator|::
name|TouchPoint
name|p
decl_stmt|;
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
operator|::
name|const_iterator
name|point
init|=
name|points
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|points
operator|.
name|constEnd
argument_list|()
decl_stmt|;
while|while
condition|(
name|point
operator|!=
name|end
condition|)
block|{
name|p
operator|.
name|setId
argument_list|(
name|point
operator|->
name|id
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPressure
argument_list|(
name|point
operator|->
name|pressure
argument_list|)
expr_stmt|;
name|states
operator||=
name|point
operator|->
name|state
expr_stmt|;
name|p
operator|.
name|setState
argument_list|(
name|point
operator|->
name|state
argument_list|)
expr_stmt|;
specifier|const
name|QPointF
name|screenPos
init|=
name|point
operator|->
name|area
operator|.
name|center
argument_list|()
decl_stmt|;
name|p
operator|.
name|setScreenPos
argument_list|(
name|screenPos
argument_list|)
expr_stmt|;
name|p
operator|.
name|setScreenRect
argument_list|(
name|point
operator|->
name|area
argument_list|)
expr_stmt|;
comment|// The local pos and rect are not set, they will be calculated
comment|// when the event gets processed by QGuiApplication.
name|p
operator|.
name|setNormalizedPos
argument_list|(
name|point
operator|->
name|normalPosition
argument_list|)
expr_stmt|;
name|p
operator|.
name|setVelocity
argument_list|(
name|point
operator|->
name|velocity
argument_list|)
expr_stmt|;
name|p
operator|.
name|setFlags
argument_list|(
name|point
operator|->
name|flags
argument_list|)
expr_stmt|;
name|p
operator|.
name|setRawScreenPositions
argument_list|(
name|point
operator|->
name|rawPositions
argument_list|)
expr_stmt|;
name|touchPoints
operator|.
name|append
argument_list|(
name|p
argument_list|)
expr_stmt|;
operator|++
name|point
expr_stmt|;
block|}
comment|// Determine the event type based on the combined point states.
if|if
condition|(
name|type
condition|)
block|{
operator|*
name|type
operator|=
name|QEvent
operator|::
name|TouchUpdate
expr_stmt|;
if|if
condition|(
name|states
operator|==
name|Qt
operator|::
name|TouchPointPressed
condition|)
operator|*
name|type
operator|=
name|QEvent
operator|::
name|TouchBegin
expr_stmt|;
elseif|else
if|if
condition|(
name|states
operator|==
name|Qt
operator|::
name|TouchPointReleased
condition|)
operator|*
name|type
operator|=
name|QEvent
operator|::
name|TouchEnd
expr_stmt|;
block|}
return|return
name|touchPoints
return|;
block|}
end_function
begin_function
DECL|function|handleTouchEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleTouchEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
name|ulong
name|timestamp
parameter_list|,
name|QTouchDevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QList
argument_list|<
name|TouchPoint
argument_list|>
modifier|&
name|points
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|mods
parameter_list|)
block|{
if|if
condition|(
operator|!
name|points
operator|.
name|size
argument_list|()
condition|)
comment|// Touch events must have at least one point
return|return;
if|if
condition|(
operator|!
name|QTouchDevicePrivate
operator|::
name|isRegistered
argument_list|(
name|device
argument_list|)
condition|)
comment|// Disallow passing bogus, non-registered devices.
return|return;
name|QEvent
operator|::
name|Type
name|type
decl_stmt|;
name|QList
argument_list|<
name|QTouchEvent
operator|::
name|TouchPoint
argument_list|>
name|touchPoints
init|=
name|QWindowSystemInterfacePrivate
operator|::
name|convertTouchPoints
argument_list|(
name|points
argument_list|,
operator|&
name|type
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|TouchEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|TouchEvent
argument_list|(
name|tlw
argument_list|,
name|timestamp
argument_list|,
name|type
argument_list|,
name|device
argument_list|,
name|touchPoints
argument_list|,
name|mods
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleScreenOrientationChange
name|void
name|QWindowSystemInterface
operator|::
name|handleScreenOrientationChange
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|orientation
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenOrientationEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenOrientationEvent
argument_list|(
name|screen
argument_list|,
name|orientation
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleScreenGeometryChange
name|void
name|QWindowSystemInterface
operator|::
name|handleScreenGeometryChange
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QRect
modifier|&
name|geometry
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenGeometryEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenGeometryEvent
argument_list|(
name|screen
argument_list|,
name|geometry
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleScreenAvailableGeometryChange
name|void
name|QWindowSystemInterface
operator|::
name|handleScreenAvailableGeometryChange
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QRect
modifier|&
name|availableGeometry
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenAvailableGeometryEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenAvailableGeometryEvent
argument_list|(
name|screen
argument_list|,
name|availableGeometry
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleScreenLogicalDotsPerInchChange
name|void
name|QWindowSystemInterface
operator|::
name|handleScreenLogicalDotsPerInchChange
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
name|qreal
name|dpiX
parameter_list|,
name|qreal
name|dpiY
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenLogicalDotsPerInchEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenLogicalDotsPerInchEvent
argument_list|(
name|screen
argument_list|,
name|dpiX
argument_list|,
name|dpiY
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleMapEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleMapEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|MapEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|MapEvent
argument_list|(
name|tlw
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleUnmapEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleUnmapEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|UnmapEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|UnmapEvent
argument_list|(
name|tlw
argument_list|)
decl_stmt|;
name|QWindowSystemInterfacePrivate
operator|::
name|queueWindowSystemEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleSynchronousExposeEvent
name|void
name|QWindowSystemInterface
operator|::
name|handleSynchronousExposeEvent
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|ExposeEvent
name|e
argument_list|(
name|tlw
argument_list|,
name|region
argument_list|)
decl_stmt|;
name|QGuiApplicationPrivate
operator|::
name|processWindowSystemEvent
argument_list|(
operator|&
name|e
argument_list|)
expr_stmt|;
comment|// send event immediately.
block|}
end_function
begin_function
DECL|function|sendWindowSystemEvents
name|bool
name|QWindowSystemInterface
operator|::
name|sendWindowSystemEvents
parameter_list|(
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
parameter_list|,
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
name|int
name|nevents
init|=
literal|0
decl_stmt|;
comment|// handle gui and posted events
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|WindowSystemEvent
modifier|*
name|event
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|QEventLoop
operator|::
name|ExcludeUserInputEvents
operator|)
operator|&&
name|QWindowSystemInterfacePrivate
operator|::
name|windowSystemEventsQueued
argument_list|()
operator|>
literal|0
condition|)
block|{
comment|// process a pending user input event
name|event
operator|=
name|QWindowSystemInterfacePrivate
operator|::
name|getWindowSystemEvent
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|event
condition|)
break|break;
block|}
else|else
block|{
break|break;
block|}
if|if
condition|(
name|eventDispatcher
operator|->
name|filterEvent
argument_list|(
name|event
argument_list|)
condition|)
block|{
operator|delete
name|event
expr_stmt|;
continue|continue;
block|}
name|nevents
operator|++
expr_stmt|;
name|QGuiApplicationPrivate
operator|::
name|processWindowSystemEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
operator|delete
name|event
expr_stmt|;
block|}
return|return
operator|(
name|nevents
operator|>
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|windowSystemEventsQueued
name|int
name|QWindowSystemInterface
operator|::
name|windowSystemEventsQueued
parameter_list|()
block|{
return|return
name|QWindowSystemInterfacePrivate
operator|::
name|windowSystemEventsQueued
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|handleDrag
name|Qt
operator|::
name|DropAction
name|QWindowSystemInterface
operator|::
name|handleDrag
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
name|QMimeData
modifier|*
name|dropData
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
return|return
name|QGuiApplicationPrivate
operator|::
name|processDrag
argument_list|(
name|w
argument_list|,
name|dropData
argument_list|,
name|p
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|handleDrop
name|Qt
operator|::
name|DropAction
name|QWindowSystemInterface
operator|::
name|handleDrop
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
name|QMimeData
modifier|*
name|dropData
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
return|return
name|QGuiApplicationPrivate
operator|::
name|processDrop
argument_list|(
name|w
argument_list|,
name|dropData
argument_list|,
name|p
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn static QWindowSystemInterface::handleNativeEvent(QWindow *window, const QByteArray&eventType, void *message, long *result)     \brief Passes a native event identified by \a eventType to the \a window.      \note This function can only be called from the GUI thread.     \sa QPlatformNativeInterface::setEventFilter() */
end_comment
begin_function
DECL|function|handleNativeEvent
name|bool
name|QWindowSystemInterface
operator|::
name|handleNativeEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|eventType
parameter_list|,
name|void
modifier|*
name|message
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
block|{
return|return
name|QGuiApplicationPrivate
operator|::
name|processNativeEvent
argument_list|(
name|window
argument_list|,
name|eventType
argument_list|,
name|message
argument_list|,
name|result
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
