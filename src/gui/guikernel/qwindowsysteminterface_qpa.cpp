begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QAbstractEventDispatcher>
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
name|QPoint
modifier|&
name|local
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|global
parameter_list|,
name|Qt
operator|::
name|MouseButtons
name|b
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
name|QPoint
modifier|&
name|local
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|global
parameter_list|,
name|Qt
operator|::
name|MouseButtons
name|b
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
name|QPoint
modifier|&
name|local
parameter_list|,
specifier|const
name|QPoint
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
name|QPoint
modifier|&
name|local
parameter_list|,
specifier|const
name|QPoint
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
name|QEvent
operator|::
name|Type
name|type
parameter_list|,
name|QTouchEvent
operator|::
name|DeviceType
name|devType
parameter_list|,
specifier|const
name|QList
argument_list|<
expr|struct
name|TouchPoint
argument_list|>
modifier|&
name|points
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
name|type
argument_list|,
name|devType
argument_list|,
name|points
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
name|QTouchEvent
operator|::
name|DeviceType
name|devType
parameter_list|,
specifier|const
name|QList
argument_list|<
expr|struct
name|TouchPoint
argument_list|>
modifier|&
name|points
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
expr|struct
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
expr|struct
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
name|Qt
operator|::
name|TouchPointStates
name|state
init|=
name|point
operator|->
name|state
decl_stmt|;
if|if
condition|(
name|point
operator|->
name|isPrimary
condition|)
block|{
name|state
operator||=
name|Qt
operator|::
name|TouchPointPrimary
expr_stmt|;
block|}
name|p
operator|.
name|setState
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|p
operator|.
name|setRect
argument_list|(
name|point
operator|->
name|area
argument_list|)
expr_stmt|;
name|p
operator|.
name|setScreenPos
argument_list|(
name|point
operator|->
name|area
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|setNormalizedPos
argument_list|(
name|point
operator|->
name|normalPosition
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
name|devType
argument_list|,
name|touchPoints
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
name|int
name|screenIndex
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
name|screenIndex
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
name|int
name|screenIndex
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
name|screenIndex
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
DECL|function|handleScreenCountChange
name|void
name|QWindowSystemInterface
operator|::
name|handleScreenCountChange
parameter_list|(
name|int
name|count
parameter_list|)
block|{
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenCountEvent
modifier|*
name|e
init|=
operator|new
name|QWindowSystemInterfacePrivate
operator|::
name|ScreenCountEvent
argument_list|(
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
