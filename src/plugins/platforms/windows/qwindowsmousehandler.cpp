begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (info@qt.nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsmousehandler.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedArrayPointer>
end_include
begin_include
include|#
directive|include
file|<windowsx.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|compressMouseMove
specifier|static
specifier|inline
name|void
name|compressMouseMove
parameter_list|(
name|MSG
modifier|*
name|msg
parameter_list|)
block|{
comment|// Compress mouse move events
if|if
condition|(
name|msg
operator|->
name|message
operator|==
name|WM_MOUSEMOVE
condition|)
block|{
name|MSG
name|mouseMsg
decl_stmt|;
while|while
condition|(
name|PeekMessage
argument_list|(
operator|&
name|mouseMsg
argument_list|,
name|msg
operator|->
name|hwnd
argument_list|,
name|WM_MOUSEFIRST
argument_list|,
name|WM_MOUSELAST
argument_list|,
name|PM_NOREMOVE
argument_list|)
condition|)
block|{
if|if
condition|(
name|mouseMsg
operator|.
name|message
operator|==
name|WM_MOUSEMOVE
condition|)
block|{
DECL|macro|PEEKMESSAGE_IS_BROKEN
define|#
directive|define
name|PEEKMESSAGE_IS_BROKEN
value|1
ifdef|#
directive|ifdef
name|PEEKMESSAGE_IS_BROKEN
comment|// Since the Windows PeekMessage() function doesn't
comment|// correctly return the wParam for WM_MOUSEMOVE events
comment|// if there is a key release event in the queue
comment|// _before_ the mouse event, we have to also consider
comment|// key release events (kls 2003-05-13):
name|MSG
name|keyMsg
decl_stmt|;
name|bool
name|done
init|=
literal|false
decl_stmt|;
while|while
condition|(
name|PeekMessage
argument_list|(
operator|&
name|keyMsg
argument_list|,
literal|0
argument_list|,
name|WM_KEYFIRST
argument_list|,
name|WM_KEYLAST
argument_list|,
name|PM_NOREMOVE
argument_list|)
condition|)
block|{
if|if
condition|(
name|keyMsg
operator|.
name|time
operator|<
name|mouseMsg
operator|.
name|time
condition|)
block|{
if|if
condition|(
operator|(
name|keyMsg
operator|.
name|lParam
operator|&
literal|0xC0000000
operator|)
operator|==
literal|0x40000000
condition|)
block|{
name|PeekMessage
argument_list|(
operator|&
name|keyMsg
argument_list|,
literal|0
argument_list|,
name|keyMsg
operator|.
name|message
argument_list|,
name|keyMsg
operator|.
name|message
argument_list|,
name|PM_REMOVE
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|done
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
else|else
block|{
break|break;
comment|// no key event before the WM_MOUSEMOVE event
block|}
block|}
if|if
condition|(
name|done
condition|)
break|break;
else|#
directive|else
comment|// Actually the following 'if' should work instead of
comment|// the above key event checking, but apparently
comment|// PeekMessage() is broken :-(
if|if
condition|(
name|mouseMsg
operator|.
name|wParam
operator|!=
name|msg
operator|.
name|wParam
condition|)
break|break;
comment|// leave the message in the queue because
comment|// the key state has changed
endif|#
directive|endif
comment|// Update the passed in MSG structure with the
comment|// most recent one.
name|msg
operator|->
name|lParam
operator|=
name|mouseMsg
operator|.
name|lParam
expr_stmt|;
name|msg
operator|->
name|wParam
operator|=
name|mouseMsg
operator|.
name|wParam
expr_stmt|;
comment|// Extract the x,y coordinates from the lParam as we do in the WndProc
name|msg
operator|->
name|pt
operator|.
name|x
operator|=
name|GET_X_LPARAM
argument_list|(
name|mouseMsg
operator|.
name|lParam
argument_list|)
expr_stmt|;
name|msg
operator|->
name|pt
operator|.
name|y
operator|=
name|GET_Y_LPARAM
argument_list|(
name|mouseMsg
operator|.
name|lParam
argument_list|)
expr_stmt|;
name|ClientToScreen
argument_list|(
name|msg
operator|->
name|hwnd
argument_list|,
operator|&
operator|(
name|msg
operator|->
name|pt
operator|)
argument_list|)
expr_stmt|;
comment|// Remove the mouse move message
name|PeekMessage
argument_list|(
operator|&
name|mouseMsg
argument_list|,
name|msg
operator|->
name|hwnd
argument_list|,
name|WM_MOUSEMOVE
argument_list|,
name|WM_MOUSEMOVE
argument_list|,
name|PM_REMOVE
argument_list|)
expr_stmt|;
block|}
else|else
block|{
break|break;
comment|// there was no more WM_MOUSEMOVE event
block|}
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     \class QWindowsMouseHandler     \brief Windows mouse handler      Dispatches mouse and touch events. Separate for code cleanliness.      \ingroup qt-lighthouse-win */
end_comment
begin_constructor
DECL|function|QWindowsMouseHandler
name|QWindowsMouseHandler
operator|::
name|QWindowsMouseHandler
parameter_list|()
member_init_list|:
name|m_windowUnderMouse
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|translateMouseEvent
name|bool
name|QWindowsMouseHandler
operator|::
name|translateMouseEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|HWND
name|hwnd
parameter_list|,
name|QtWindows
operator|::
name|WindowsEventType
name|et
parameter_list|,
name|MSG
name|msg
parameter_list|,
name|LRESULT
modifier|*
name|result
parameter_list|)
block|{
if|if
condition|(
name|et
operator|&
name|QtWindows
operator|::
name|NonClientEventFlag
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|et
operator|==
name|QtWindows
operator|::
name|MouseWheelEvent
condition|)
return|return
name|translateMouseWheelEvent
argument_list|(
name|window
argument_list|,
name|hwnd
argument_list|,
name|msg
argument_list|,
name|result
argument_list|)
return|;
operator|*
name|result
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|msg
operator|.
name|message
operator|==
name|WM_MOUSELEAVE
condition|)
block|{
comment|// When moving out of a child, MouseMove within parent is received first
comment|// (see below)
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseEvents
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"WM_MOUSELEAVE for "
operator|<<
name|window
operator|<<
literal|" current= "
operator|<<
name|m_windowUnderMouse
expr_stmt|;
if|if
condition|(
name|window
operator|==
name|m_windowUnderMouse
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleLeaveEvent
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|m_windowUnderMouse
operator|=
literal|0
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
name|compressMouseMove
argument_list|(
operator|&
name|msg
argument_list|)
expr_stmt|;
specifier|const
name|QPoint
name|client
argument_list|(
name|GET_X_LPARAM
argument_list|(
name|msg
operator|.
name|lParam
argument_list|)
argument_list|,
name|GET_Y_LPARAM
argument_list|(
name|msg
operator|.
name|lParam
argument_list|)
argument_list|)
decl_stmt|;
comment|// Enter new window: track to generate leave event.
if|if
condition|(
name|m_windowUnderMouse
operator|!=
name|window
condition|)
block|{
comment|// The tracking on m_windowUnderMouse might still be active and
comment|// trigger later on.
if|if
condition|(
name|m_windowUnderMouse
condition|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseEvents
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Synthetic leave for "
operator|<<
name|m_windowUnderMouse
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleLeaveEvent
argument_list|(
name|m_windowUnderMouse
argument_list|)
expr_stmt|;
block|}
name|m_windowUnderMouse
operator|=
name|window
expr_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseEvents
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Entering "
operator|<<
name|window
expr_stmt|;
name|QWindowsWindow
operator|::
name|baseWindowOf
argument_list|(
name|window
argument_list|)
operator|->
name|applyCursor
argument_list|()
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleEnterEvent
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|TRACKMOUSEEVENT
name|tme
decl_stmt|;
name|tme
operator|.
name|cbSize
operator|=
sizeof|sizeof
argument_list|(
name|TRACKMOUSEEVENT
argument_list|)
expr_stmt|;
name|tme
operator|.
name|dwFlags
operator|=
name|TME_LEAVE
expr_stmt|;
name|tme
operator|.
name|hwndTrack
operator|=
name|hwnd
expr_stmt|;
name|tme
operator|.
name|dwHoverTime
operator|=
name|HOVER_DEFAULT
expr_stmt|;
comment|//
if|if
condition|(
operator|!
name|TrackMouseEvent
argument_list|(
operator|&
name|tme
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"TrackMouseEvent failed."
argument_list|)
expr_stmt|;
block|}
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
name|window
argument_list|,
name|client
argument_list|,
name|QWindowsGeometryHint
operator|::
name|mapToGlobal
argument_list|(
name|hwnd
argument_list|,
name|client
argument_list|)
argument_list|,
name|keyStateToMouseButtons
argument_list|(
operator|(
name|int
operator|)
name|msg
operator|.
name|wParam
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|translateMouseWheelEvent
name|bool
name|QWindowsMouseHandler
operator|::
name|translateMouseWheelEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|HWND
parameter_list|,
name|MSG
name|msg
parameter_list|,
name|LRESULT
modifier|*
parameter_list|)
block|{
specifier|const
name|Qt
operator|::
name|MouseButtons
name|buttons
init|=
name|keyStateToMouseButtons
argument_list|(
operator|(
name|int
operator|)
name|msg
operator|.
name|wParam
argument_list|)
decl_stmt|;
name|int
name|delta
decl_stmt|;
if|if
condition|(
name|msg
operator|.
name|message
operator|==
name|WM_MOUSEWHEEL
operator|||
name|msg
operator|.
name|message
operator|==
name|WM_MOUSEHWHEEL
condition|)
name|delta
operator|=
operator|(
name|short
operator|)
name|HIWORD
argument_list|(
name|msg
operator|.
name|wParam
argument_list|)
expr_stmt|;
else|else
name|delta
operator|=
operator|(
name|int
operator|)
name|msg
operator|.
name|wParam
expr_stmt|;
name|Qt
operator|::
name|Orientation
name|orientation
init|=
operator|(
name|msg
operator|.
name|message
operator|==
name|WM_MOUSEHWHEEL
operator|||
operator|(
name|buttons
operator|&
name|Qt
operator|::
name|AltModifier
operator|)
operator|)
condition|?
name|Qt
operator|::
name|Horizontal
else|:
name|Qt
operator|::
name|Vertical
decl_stmt|;
comment|// according to the MSDN documentation on WM_MOUSEHWHEEL:
comment|// a positive value indicates that the wheel was rotated to the right;
comment|// a negative value indicates that the wheel was rotated to the left.
comment|// Qt defines this value as the exact opposite, so we have to flip the value!
if|if
condition|(
name|msg
operator|.
name|message
operator|==
name|WM_MOUSEHWHEEL
condition|)
name|delta
operator|=
operator|-
name|delta
expr_stmt|;
specifier|const
name|QPoint
name|globalPos
argument_list|(
name|GET_X_LPARAM
argument_list|(
name|msg
operator|.
name|lParam
argument_list|)
argument_list|,
name|GET_Y_LPARAM
argument_list|(
name|msg
operator|.
name|lParam
argument_list|)
argument_list|)
decl_stmt|;
comment|// TODO: if there is a widget under the mouse and it is not shadowed
comment|// QWindow *receiver = windowAt(pos);
comment|// by modality, we send the event to it first.
comment|//synaptics touchpad shows its own widget at this position
comment|//so widgetAt() will fail with that HWND, try child of this widget
comment|// if (!receiver) receiver = window->childAt(pos);
name|QWindow
modifier|*
name|receiver
init|=
name|window
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWheelEvent
argument_list|(
name|receiver
argument_list|,
name|QWindowsGeometryHint
operator|::
name|mapFromGlobal
argument_list|(
name|receiver
argument_list|,
name|globalPos
argument_list|)
argument_list|,
name|globalPos
argument_list|,
name|delta
argument_list|,
name|orientation
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|// from bool QApplicationPrivate::translateTouchEvent()
end_comment
begin_function
DECL|function|translateTouchEvent
name|bool
name|QWindowsMouseHandler
operator|::
name|translateTouchEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|HWND
parameter_list|,
name|QtWindows
operator|::
name|WindowsEventType
parameter_list|,
name|MSG
name|msg
parameter_list|,
name|LRESULT
modifier|*
parameter_list|)
block|{
typedef|typedef
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|QTouchPoint
typedef|;
typedef|typedef
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
name|QTouchPointList
typedef|;
specifier|const
name|QRect
name|screenGeometry
init|=
name|window
operator|->
name|screen
argument_list|()
operator|->
name|geometry
argument_list|()
decl_stmt|;
specifier|const
name|int
name|winTouchPointCount
init|=
name|msg
operator|.
name|wParam
decl_stmt|;
name|QScopedArrayPointer
argument_list|<
name|TOUCHINPUT
argument_list|>
name|winTouchInputs
argument_list|(
operator|new
name|TOUCHINPUT
index|[
name|winTouchPointCount
index|]
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|winTouchInputs
operator|.
name|data
argument_list|()
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|TOUCHINPUT
argument_list|)
operator|*
name|winTouchPointCount
argument_list|)
expr_stmt|;
name|QTouchPointList
name|touchPoints
decl_stmt|;
name|touchPoints
operator|.
name|reserve
argument_list|(
name|winTouchPointCount
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|TouchPointStates
name|allStates
init|=
literal|0
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|getTouchInputInfo
argument_list|)
expr_stmt|;
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|getTouchInputInfo
argument_list|(
operator|(
name|HANDLE
operator|)
name|msg
operator|.
name|lParam
argument_list|,
name|msg
operator|.
name|wParam
argument_list|,
name|winTouchInputs
operator|.
name|data
argument_list|()
argument_list|,
sizeof|sizeof
argument_list|(
name|TOUCHINPUT
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|winTouchPointCount
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|TOUCHINPUT
modifier|&
name|winTouchInput
init|=
name|winTouchInputs
index|[
name|i
index|]
decl_stmt|;
name|QTouchPoint
name|touchPoint
decl_stmt|;
name|touchPoint
operator|.
name|pressure
operator|=
literal|1.0
expr_stmt|;
name|touchPoint
operator|.
name|isPrimary
operator|=
operator|(
name|winTouchInput
operator|.
name|dwFlags
operator|&
name|TOUCHEVENTF_PRIMARY
operator|)
operator|!=
literal|0
expr_stmt|;
name|touchPoint
operator|.
name|id
operator|=
name|m_touchInputIDToTouchPointID
operator|.
name|value
argument_list|(
name|winTouchInput
operator|.
name|dwID
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|touchPoint
operator|.
name|id
operator|==
operator|-
literal|1
condition|)
block|{
name|touchPoint
operator|.
name|id
operator|=
name|m_touchInputIDToTouchPointID
operator|.
name|size
argument_list|()
expr_stmt|;
name|m_touchInputIDToTouchPointID
operator|.
name|insert
argument_list|(
name|winTouchInput
operator|.
name|dwID
argument_list|,
name|touchPoint
operator|.
name|id
argument_list|)
expr_stmt|;
block|}
name|QPointF
name|screenPos
init|=
name|QPointF
argument_list|(
name|qreal
argument_list|(
name|winTouchInput
operator|.
name|x
argument_list|)
operator|/
name|qreal
argument_list|(
literal|100.
argument_list|)
argument_list|,
name|qreal
argument_list|(
name|winTouchInput
operator|.
name|y
argument_list|)
operator|/
name|qreal
argument_list|(
literal|100.
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|winTouchInput
operator|.
name|dwMask
operator|&
name|TOUCHINPUTMASKF_CONTACTAREA
condition|)
name|touchPoint
operator|.
name|area
operator|.
name|setSize
argument_list|(
name|QSizeF
argument_list|(
name|qreal
argument_list|(
name|winTouchInput
operator|.
name|cxContact
argument_list|)
operator|/
name|qreal
argument_list|(
literal|100.
argument_list|)
argument_list|,
name|qreal
argument_list|(
name|winTouchInput
operator|.
name|cyContact
argument_list|)
operator|/
name|qreal
argument_list|(
literal|100.
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|touchPoint
operator|.
name|area
operator|.
name|moveCenter
argument_list|(
name|screenPos
argument_list|)
expr_stmt|;
if|if
condition|(
name|winTouchInput
operator|.
name|dwFlags
operator|&
name|TOUCHEVENTF_DOWN
condition|)
block|{
name|touchPoint
operator|.
name|state
operator|=
name|Qt
operator|::
name|TouchPointPressed
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|winTouchInput
operator|.
name|dwFlags
operator|&
name|TOUCHEVENTF_UP
condition|)
block|{
name|touchPoint
operator|.
name|state
operator|=
name|Qt
operator|::
name|TouchPointReleased
expr_stmt|;
block|}
else|else
block|{
comment|// TODO: Previous code checked"
comment|// screenPos == touchPoint.normalPosition -> Qt::TouchPointStationary, but
comment|// but touchPoint.normalPosition was never initialized?
name|touchPoint
operator|.
name|state
operator|=
name|touchPoint
operator|.
name|state
expr_stmt|;
block|}
name|touchPoint
operator|.
name|normalPosition
operator|=
name|QPointF
argument_list|(
name|screenPos
operator|.
name|x
argument_list|()
operator|/
name|screenGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|screenPos
operator|.
name|y
argument_list|()
operator|/
name|screenGeometry
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|allStates
operator||=
name|touchPoint
operator|.
name|state
expr_stmt|;
name|touchPoints
operator|.
name|append
argument_list|(
name|touchPoint
argument_list|)
expr_stmt|;
block|}
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|closeTouchInputHandle
argument_list|(
operator|(
name|HANDLE
operator|)
name|msg
operator|.
name|lParam
argument_list|)
expr_stmt|;
comment|// all touch points released, forget the ids we've seen, they may not be reused
if|if
condition|(
operator|(
name|allStates
operator|&
name|Qt
operator|::
name|TouchPointStateMask
operator|)
operator|==
name|Qt
operator|::
name|TouchPointReleased
condition|)
name|m_touchInputIDToTouchPointID
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// TODO: Device used to be hardcoded to screen in previous code.
comment|// What is the correct event type? Which parts of translateRawTouchEvent() are required?
name|QWindowSystemInterface
operator|::
name|handleTouchEvent
argument_list|(
name|window
argument_list|,
name|QEvent
operator|::
name|TouchBegin
argument_list|,
name|QTouchEvent
operator|::
name|TouchScreen
argument_list|,
name|touchPoints
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
