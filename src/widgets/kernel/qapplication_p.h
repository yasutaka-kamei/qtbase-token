begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QAPPLICATION_P_H
end_ifndef
begin_define
DECL|macro|QAPPLICATION_P_H
define|#
directive|define
name|QAPPLICATION_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of qapplication_*.cpp, qwidget*.cpp, qcolor_x11.cpp, qfiledialog.cpp
end_comment
begin_comment
comment|// and many other.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtWidgets/qapplication.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qevent.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qfont.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qcursor.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qregion.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwidget.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|"QtCore/qmutex.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qtranslator.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"private/qcoreapplication_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpoint.h"
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|"private/qguiapplication_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QClipboard
name|class
name|QClipboard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsScene
name|class
name|QGraphicsScene
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTouchDevice
name|class
name|QTouchDevice
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
DECL|variable|QGestureManager
name|class
name|QGestureManager
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
specifier|extern
name|Q_GUI_EXPORT
name|bool
name|qt_is_gui_used
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_decl_stmt
specifier|extern
name|QClipboard
modifier|*
name|qt_clipboard
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_CYGWIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_extern
extern|extern QSysInfo::WinVersion qt_winver;
end_extern
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_decl_stmt
specifier|extern
name|DWORD
name|qt_cever
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_elif
begin_extern
extern|extern QSysInfo::MacVersion qt_macver;
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|QByteArray
DECL|typedef|FontHash
typedef|typedef
name|QHash
operator|<
name|QByteArray
operator|,
name|QFont
operator|>
name|FontHash
expr_stmt|;
end_typedef
begin_function_decl
name|FontHash
modifier|*
name|qt_app_fonts_hash
parameter_list|()
function_decl|;
end_function_decl
begin_typedef
DECL|typedef|QByteArray
DECL|typedef|PaletteHash
typedef|typedef
name|QHash
operator|<
name|QByteArray
operator|,
name|QPalette
operator|>
name|PaletteHash
expr_stmt|;
end_typedef
begin_function_decl
name|PaletteHash
modifier|*
name|qt_app_palettes_hash
parameter_list|()
function_decl|;
end_function_decl
begin_define
DECL|macro|QApplicationPrivateBase
define|#
directive|define
name|QApplicationPrivateBase
value|QGuiApplicationPrivate
end_define
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QApplicationPrivate
range|:
name|public
name|QApplicationPrivateBase
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QApplication
argument_list|)
name|public
operator|:
name|QApplicationPrivate
argument_list|(
argument|int&argc
argument_list|,
argument|char **argv
argument_list|,
argument|int flags
argument_list|)
block|;
operator|~
name|QApplicationPrivate
argument_list|()
block|;
name|virtual
name|void
name|notifyLayoutDirectionChange
argument_list|()
block|;
name|virtual
name|void
name|notifyActiveWindowChange
argument_list|(
name|QWindow
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|shouldQuit
argument_list|()
block|;
name|bool
name|tryCloseAllWindows
argument_list|()
name|Q_DECL_OVERRIDE
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
specifier|static
name|bool
name|x11_apply_settings
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|void
name|reset_instance_pointer
argument_list|()
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WINCE
specifier|static
name|int
name|autoMaximizeThreshold
block|;
endif|#
directive|endif
specifier|static
name|bool
name|autoSipEnabled
block|;
specifier|static
name|QString
name|desktopStyleKey
argument_list|()
block|;
name|void
name|createEventDispatcher
argument_list|()
block|;
specifier|static
name|void
name|dispatchEnterLeave
argument_list|(
name|QWidget
operator|*
name|enter
argument_list|,
name|QWidget
operator|*
name|leave
argument_list|,
specifier|const
name|QPointF
operator|&
name|globalPosF
argument_list|)
block|;
name|void
name|notifyWindowIconChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
comment|//modality
name|bool
name|isWindowBlocked
argument_list|(
argument|QWindow *window
argument_list|,
argument|QWindow **blockingWindow =
literal|0
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|bool
name|isBlockedByModal
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
specifier|static
name|bool
name|modalState
argument_list|()
block|;
specifier|static
name|bool
name|tryModalHelper
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|QWidget
operator|*
operator|*
name|rettop
operator|=
literal|0
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
specifier|static
name|QWidget
operator|*
name|tryModalHelper_sys
argument_list|(
name|QWidget
operator|*
name|top
argument_list|)
block|;
name|bool
name|canQuit
argument_list|()
block|;
endif|#
directive|endif
comment|//style
specifier|static
name|bool
name|usesNativeStyle
argument_list|()
block|{
return|return
operator|!
name|overrides_native_style
return|;
block|}
name|bool
name|notify_helper
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|construct
argument_list|(
ifdef|#
directive|ifdef
name|Q_WS_X11
argument|Display *dpy =
literal|0
argument_list|,
argument|Qt::HANDLE visual =
literal|0
argument_list|,
argument|Qt::HANDLE cmap =
literal|0
endif|#
directive|endif
argument_list|)
block|;
name|void
name|initialize
argument_list|()
block|;
name|void
name|process_cmdline
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
specifier|static
name|void
name|x11_initialize_style
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|bool
name|inPopupMode
argument_list|()
block|;
name|void
name|closePopup
argument_list|(
name|QWidget
operator|*
name|popup
argument_list|)
block|;
name|void
name|openPopup
argument_list|(
name|QWidget
operator|*
name|popup
argument_list|)
block|;
specifier|static
name|void
name|setFocusWidget
argument_list|(
argument|QWidget *focus
argument_list|,
argument|Qt::FocusReason reason
argument_list|)
block|;
specifier|static
name|QWidget
operator|*
name|focusNextPrevChild_helper
argument_list|(
argument|QWidget *toplevel
argument_list|,
argument|bool next
argument_list|,
argument|bool *wrappingOccurred =
literal|0
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
comment|// Maintain a list of all scenes to ensure font and palette propagation to
comment|// all scenes.
name|QList
operator|<
name|QGraphicsScene
operator|*
operator|>
name|scene_list
block|;
endif|#
directive|endif
name|QBasicTimer
name|toolTipWakeUp
block|,
name|toolTipFallAsleep
block|;
name|QPoint
name|toolTipPos
block|,
name|toolTipGlobalPos
block|,
name|hoverGlobalPos
block|;
name|QPointer
operator|<
name|QWidget
operator|>
name|toolTipWidget
block|;
specifier|static
name|QSize
name|app_strut
block|;
specifier|static
name|QWidgetList
operator|*
name|popupWidgets
block|;
specifier|static
name|QStyle
operator|*
name|app_style
block|;
specifier|static
name|bool
name|overrides_native_style
block|;
specifier|static
name|int
name|app_cspec
block|;
specifier|static
name|QPalette
operator|*
name|sys_pal
block|;
specifier|static
name|QPalette
operator|*
name|set_pal
block|;
name|protected
operator|:
name|void
name|notifyThemeChanged
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|notifyDragStarted
argument_list|(
specifier|const
name|QDrag
operator|*
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_NO_DRAGANDDROP
name|public
operator|:
specifier|static
name|QFont
operator|*
name|sys_font
block|;
specifier|static
name|QFont
operator|*
name|set_font
block|;
specifier|static
name|QWidget
operator|*
name|main_widget
block|;
specifier|static
name|QWidget
operator|*
name|focus_widget
block|;
specifier|static
name|QWidget
operator|*
name|hidden_focus_widget
block|;
specifier|static
name|QWidget
operator|*
name|active_window
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
specifier|static
name|int
name|wheel_scroll_lines
block|;
endif|#
directive|endif
specifier|static
name|int
name|enabledAnimations
block|;
comment|// Combination of QPlatformTheme::UiEffect
specifier|static
name|bool
name|widgetCount
block|;
comment|// Coupled with -widgetcount switch
specifier|static
name|bool
name|load_testability
block|;
comment|// Coupled with -testability switch
specifier|static
name|void
name|setSystemPalette
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
block|;
specifier|static
name|void
name|setPalette_helper
argument_list|(
argument|const QPalette&palette
argument_list|,
argument|const char* className
argument_list|,
argument|bool clearWidgetPaletteHash
argument_list|)
block|;
specifier|static
name|void
name|initializeWidgetPaletteHash
argument_list|()
block|;
specifier|static
name|void
name|initializeWidgetFontHash
argument_list|()
block|;
specifier|static
name|void
name|setSystemFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
specifier|static
name|void
name|applyX11SpecificCommandLineArguments
argument_list|(
name|QWidget
operator|*
name|main_widget
argument_list|)
block|;
endif|#
directive|endif
specifier|static
name|QApplicationPrivate
operator|*
name|instance
argument_list|()
block|{
return|return
name|self
return|;
block|}
specifier|static
name|QString
name|styleOverride
block|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
specifier|static
name|QWidget
operator|*
name|oldEditFocus
block|;
specifier|static
name|Qt
operator|::
name|NavigationMode
name|navigationMode
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|void
name|_q_alertTimeOut
argument_list|()
block|;
name|QHash
operator|<
name|QWidget
operator|*
block|,
name|QTimer
operator|*
operator|>
name|alertTimerHash
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
specifier|static
name|QString
name|styleSheet
block|;
endif|#
directive|endif
specifier|static
name|QPointer
operator|<
name|QWidget
operator|>
name|leaveAfterRelease
block|;
specifier|static
name|QWidget
operator|*
name|pickMouseReceiver
argument_list|(
argument|QWidget *candidate
argument_list|,
argument|const QPoint&windowPos
argument_list|,
argument|QPoint *pos
argument_list|,
argument|QEvent::Type type
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|,
argument|QWidget *buttonDown
argument_list|,
argument|QWidget *alienWidget
argument_list|)
block|;
specifier|static
name|bool
name|sendMouseEvent
argument_list|(
argument|QWidget *receiver
argument_list|,
argument|QMouseEvent *event
argument_list|,
argument|QWidget *alienWidget
argument_list|,
argument|QWidget *native
argument_list|,
argument|QWidget **buttonDown
argument_list|,
argument|QPointer<QWidget>&lastMouseReceiver
argument_list|,
argument|bool spontaneous = true
argument_list|)
block|;
name|void
name|sendSyntheticEnterLeave
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
specifier|static
name|QWindow
operator|*
name|windowForWidget
argument_list|(
argument|const QWidget *widget
argument_list|)
block|{
if|if
condition|(
name|QWindow
modifier|*
name|window
init|=
name|widget
operator|->
name|windowHandle
argument_list|()
condition|)
return|return
name|window
return|;
if|if
condition|(
specifier|const
name|QWidget
modifier|*
name|nativeParent
init|=
name|widget
operator|->
name|nativeParentWidget
argument_list|()
condition|)
return|return
name|nativeParent
operator|->
name|windowHandle
argument_list|()
return|;
end_decl_stmt
begin_return
return|return
literal|0
return|;
end_return
begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_function
unit|static
name|HWND
name|getHWNDForWidget
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
name|QWindow
modifier|*
name|window
init|=
name|windowForWidget
argument_list|(
name|widget
argument_list|)
condition|)
if|if
condition|(
name|window
operator|->
name|handle
argument_list|()
condition|)
return|return
name|static_cast
operator|<
name|HWND
operator|>
operator|(
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
operator|->
name|nativeResourceForWindow
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"handle"
argument_list|)
argument_list|,
name|window
argument_list|)
operator|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
name|QGestureManager
modifier|*
name|gestureManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWidget
modifier|*
name|gestureWidget
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
end_if
begin_decl_stmt
name|QPixmap
modifier|*
name|move_cursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPixmap
modifier|*
name|copy_cursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPixmap
modifier|*
name|link_cursor
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
end_if
begin_decl_stmt
name|QPixmap
modifier|*
name|ignore_cursor
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|void
name|updateTouchPointsForWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QTouchEvent
modifier|*
name|touchEvent
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|initializeMultitouch
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|initializeMultitouch_sys
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|cleanupMultitouch
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|cleanupMultitouch_sys
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QWidget
modifier|*
name|findClosestTouchPointTarget
parameter_list|(
name|QTouchDevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|screenPos
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|appendTouchPoint
argument_list|(
specifier|const
name|QTouchEvent
operator|::
name|TouchPoint
operator|&
name|touchPoint
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|removeTouchPoint
parameter_list|(
name|int
name|touchPointId
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|bool
name|translateRawTouchEvent
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|QTouchDevice
operator|*
name|device
argument_list|,
specifier|const
name|QList
operator|<
name|QTouchEvent
operator|::
name|TouchPoint
operator|>
operator|&
name|touchPoints
argument_list|,
name|ulong
name|timestamp
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|void
name|translateTouchCancel
parameter_list|(
name|QTouchDevice
modifier|*
name|device
parameter_list|,
name|ulong
name|timestamp
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QPixmap
name|applyQIconStyleHelper
argument_list|(
name|QIcon
operator|::
name|Mode
name|mode
argument_list|,
specifier|const
name|QPixmap
operator|&
name|base
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
specifier|static
name|QApplicationPrivate
modifier|*
name|self
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|bool
name|tryCloseAllWidgetWindows
parameter_list|(
name|QWindowList
modifier|*
name|processedWindows
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|giveFocusAccordingToFocusPolicy
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|,
name|QPoint
name|localPos
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|bool
name|shouldSetFocus
argument_list|(
name|QWidget
operator|*
name|w
argument_list|,
name|Qt
operator|::
name|FocusPolicy
name|policy
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|bool
name|isAlien
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_if
unit|};
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
end_if
begin_function_decl
specifier|extern
name|void
name|qt_win_set_cursor
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
end_elif
begin_function_decl
specifier|extern
name|void
name|qt_x11_enforce_cursor
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|void
name|qt_x11_enforce_cursor
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_else
else|#
directive|else
end_else
begin_function_decl
specifier|extern
name|void
name|qt_qpa_set_cursor
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl
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
begin_comment
comment|// QAPPLICATION_P_H
end_comment
end_unit
