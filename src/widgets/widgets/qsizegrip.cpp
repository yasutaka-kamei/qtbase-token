begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsizegrip.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SIZEGRIP
end_ifndef
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qstyle.h"
end_include
begin_include
include|#
directive|include
file|"qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"qlayout.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|<QDesktopWidget>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<private/qt_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<private/qwidget_p.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qabstractscrollarea.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_include
include|#
directive|include
file|"private/qapplication_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
DECL|macro|SZ_SIZEBOTTOMRIGHT
define|#
directive|define
name|SZ_SIZEBOTTOMRIGHT
value|0xf008
DECL|macro|SZ_SIZEBOTTOMLEFT
define|#
directive|define
name|SZ_SIZEBOTTOMLEFT
value|0xf007
DECL|macro|SZ_SIZETOPLEFT
define|#
directive|define
name|SZ_SIZETOPLEFT
value|0xf004
DECL|macro|SZ_SIZETOPRIGHT
define|#
directive|define
name|SZ_SIZETOPRIGHT
value|0xf005
name|HMENU
name|qt_getWindowsSystemMenu
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|qt_sizegrip_topLevelWidget
specifier|static
name|QWidget
modifier|*
name|qt_sizegrip_topLevelWidget
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
while|while
condition|(
name|w
operator|&&
operator|!
name|w
operator|->
name|isWindow
argument_list|()
operator|&&
name|w
operator|->
name|windowType
argument_list|()
operator|!=
name|Qt
operator|::
name|SubWindow
condition|)
name|w
operator|=
name|w
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
return|return
name|w
return|;
block|}
end_function
begin_class
DECL|class|QSizeGripPrivate
class|class
name|QSizeGripPrivate
super|:
specifier|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QSizeGrip
parameter_list|)
specifier|public
private|:
name|void
name|init
parameter_list|()
function_decl|;
DECL|member|p
name|QPoint
name|p
decl_stmt|;
DECL|member|r
name|QRect
name|r
decl_stmt|;
DECL|member|d
name|int
name|d
decl_stmt|;
DECL|member|dxMax
name|int
name|dxMax
decl_stmt|;
DECL|member|dyMax
name|int
name|dyMax
decl_stmt|;
DECL|member|m_corner
name|Qt
operator|::
name|Corner
name|m_corner
decl_stmt|;
DECL|member|gotMousePress
name|bool
name|gotMousePress
decl_stmt|;
DECL|member|tlw
name|QWidget
modifier|*
name|tlw
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|void
name|updateMacSizer
parameter_list|(
name|bool
name|hide
parameter_list|)
specifier|const
function_decl|;
endif|#
directive|endif
name|Qt
operator|::
name|Corner
name|corner
parameter_list|()
specifier|const
function_decl|;
DECL|function|atBottom
specifier|inline
name|bool
name|atBottom
parameter_list|()
specifier|const
block|{
return|return
name|m_corner
operator|==
name|Qt
operator|::
name|BottomRightCorner
operator|||
name|m_corner
operator|==
name|Qt
operator|::
name|BottomLeftCorner
return|;
block|}
DECL|function|atLeft
specifier|inline
name|bool
name|atLeft
parameter_list|()
specifier|const
block|{
return|return
name|m_corner
operator|==
name|Qt
operator|::
name|BottomLeftCorner
operator|||
name|m_corner
operator|==
name|Qt
operator|::
name|TopLeftCorner
return|;
block|}
DECL|function|updateTopLevelWidget
name|void
name|updateTopLevelWidget
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QSizeGrip
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|w
init|=
name|qt_sizegrip_topLevelWidget
argument_list|(
name|q
argument_list|)
decl_stmt|;
if|if
condition|(
name|tlw
operator|==
name|w
condition|)
return|return;
if|if
condition|(
name|tlw
condition|)
name|tlw
operator|->
name|removeEventFilter
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|tlw
operator|=
name|w
expr_stmt|;
if|if
condition|(
name|tlw
condition|)
name|tlw
operator|->
name|installEventFilter
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
comment|// This slot is invoked by QLayout when the size grip is added to
comment|// a layout or reparented after the tlw is shown. This re-implementation is basically
comment|// the same as QWidgetPrivate::_q_showIfNotHidden except that it checks
comment|// for Qt::WindowFullScreen and Qt::WindowMaximized as well.
DECL|function|_q_showIfNotHidden
name|void
name|_q_showIfNotHidden
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QSizeGrip
argument_list|)
expr_stmt|;
name|bool
name|showSizeGrip
init|=
operator|!
operator|(
name|q
operator|->
name|isHidden
argument_list|()
operator|&&
name|q
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_ExplicitShowHide
argument_list|)
operator|)
decl_stmt|;
name|updateTopLevelWidget
argument_list|()
expr_stmt|;
if|if
condition|(
name|tlw
operator|&&
name|showSizeGrip
condition|)
block|{
name|Qt
operator|::
name|WindowStates
name|sizeGripNotVisibleState
init|=
name|Qt
operator|::
name|WindowFullScreen
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_WS_MAC
name|sizeGripNotVisibleState
operator||=
name|Qt
operator|::
name|WindowMaximized
expr_stmt|;
endif|#
directive|endif
comment|// Don't show the size grip if the tlw is maximized or in full screen mode.
name|showSizeGrip
operator|=
operator|!
operator|(
name|tlw
operator|->
name|windowState
argument_list|()
operator|&
name|sizeGripNotVisibleState
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|showSizeGrip
condition|)
name|q
operator|->
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_function
DECL|function|updateMacSizer
name|void
name|QSizeGripPrivate
operator|::
name|updateMacSizer
parameter_list|(
name|bool
name|hide
parameter_list|)
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QSizeGrip
argument_list|)
expr_stmt|;
if|if
condition|(
name|QApplication
operator|::
name|closingDown
argument_list|()
operator|||
operator|!
name|parent
condition|)
return|return;
name|QWidget
modifier|*
name|topLevelWindow
init|=
name|qt_sizegrip_topLevelWidget
argument_list|(
cast|const_cast
argument_list|<
name|QSizeGrip
operator|*
argument_list|>
argument_list|(
name|q
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|topLevelWindow
operator|&&
name|topLevelWindow
operator|->
name|isWindow
argument_list|()
condition|)
name|QWidgetPrivate
operator|::
name|qt_mac_update_sizer
argument_list|(
name|topLevelWindow
argument_list|,
name|hide
condition|?
operator|-
literal|1
else|:
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|corner
name|Qt
operator|::
name|Corner
name|QSizeGripPrivate
operator|::
name|corner
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QSizeGrip
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|tlw
init|=
name|qt_sizegrip_topLevelWidget
argument_list|(
cast|const_cast
argument_list|<
name|QSizeGrip
operator|*
argument_list|>
argument_list|(
name|q
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|sizeGripPos
init|=
name|q
operator|->
name|mapTo
argument_list|(
name|tlw
argument_list|,
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|bool
name|isAtBottom
init|=
name|sizeGripPos
operator|.
name|y
argument_list|()
operator|>=
name|tlw
operator|->
name|height
argument_list|()
operator|/
literal|2
decl_stmt|;
name|bool
name|isAtLeft
init|=
name|sizeGripPos
operator|.
name|x
argument_list|()
operator|<=
name|tlw
operator|->
name|width
argument_list|()
operator|/
literal|2
decl_stmt|;
if|if
condition|(
name|isAtLeft
condition|)
return|return
name|isAtBottom
condition|?
name|Qt
operator|::
name|BottomLeftCorner
else|:
name|Qt
operator|::
name|TopLeftCorner
return|;
else|else
return|return
name|isAtBottom
condition|?
name|Qt
operator|::
name|BottomRightCorner
else|:
name|Qt
operator|::
name|TopRightCorner
return|;
block|}
end_function
begin_comment
comment|/*!     \class QSizeGrip      \brief The QSizeGrip class provides a resize handle for resizing top-level windows.      \ingroup mainwindow-classes     \ingroup basicwidgets     \inmodule QtWidgets      This widget works like the standard Windows resize handle. In the     X11 version this resize handle generally works differently from     the one provided by the system if the X11 window manager does not     support necessary modern post-ICCCM specifications.      Put this widget anywhere in a widget tree and the user can use it     to resize the top-level window or any widget with the Qt::SubWindow     flag set. Generally, this should be in the lower right-hand corner.     Note that QStatusBar already uses this widget, so if you have a     status bar (e.g., you are using QMainWindow), then you don't need     to use this widget explicitly.      On some platforms the size grip automatically hides itself when the     window is shown full screen or maximised.      \table 50%     \row \li \inlineimage plastique-sizegrip.png Screenshot of a Plastique style size grip     \li A size grip widget at the bottom-right corner of a main window, shown in the     \l{Plastique Style Widget Gallery}{Plastique widget style}.     \endtable      The QSizeGrip class inherits QWidget and reimplements the \l     {QWidget::mousePressEvent()}{mousePressEvent()} and \l     {QWidget::mouseMoveEvent()}{mouseMoveEvent()} functions to feature     the resize functionality, and the \l     {QWidget::paintEvent()}{paintEvent()} function to render the     size grip widget.      \sa QStatusBar, QWidget::windowState() */
end_comment
begin_comment
comment|/*!     Constructs a resize corner as a child widget of  the given \a     parent. */
end_comment
begin_constructor
DECL|function|QSizeGrip
name|QSizeGrip
operator|::
name|QSizeGrip
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QSizeGripPrivate
argument_list|,
name|parent
argument_list|,
literal|0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QSizeGrip
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|init
name|void
name|QSizeGripPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QSizeGrip
argument_list|)
expr_stmt|;
name|dxMax
operator|=
literal|0
expr_stmt|;
name|dyMax
operator|=
literal|0
expr_stmt|;
name|tlw
operator|=
literal|0
expr_stmt|;
name|m_corner
operator|=
name|q
operator|->
name|isLeftToRight
argument_list|()
condition|?
name|Qt
operator|::
name|BottomRightCorner
else|:
name|Qt
operator|::
name|BottomLeftCorner
expr_stmt|;
name|gotMousePress
operator|=
literal|false
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CURSOR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|q
operator|->
name|setCursor
argument_list|(
name|m_corner
operator|==
name|Qt
operator|::
name|TopLeftCorner
operator|||
name|m_corner
operator|==
name|Qt
operator|::
name|BottomRightCorner
condition|?
name|Qt
operator|::
name|SizeFDiagCursor
else|:
name|Qt
operator|::
name|SizeBDiagCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|q
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
argument_list|)
expr_stmt|;
name|updateTopLevelWidget
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Destroys this size grip. */
end_comment
begin_destructor
DECL|function|~QSizeGrip
name|QSizeGrip
operator|::
name|~
name|QSizeGrip
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QSizeGrip
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|QStyleOption
name|opt
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|opt
operator|.
name|init
argument_list|(
name|this
argument_list|)
expr_stmt|;
return|return
operator|(
name|style
argument_list|()
operator|->
name|sizeFromContents
argument_list|(
name|QStyle
operator|::
name|CT_SizeGrip
argument_list|,
operator|&
name|opt
argument_list|,
name|QSize
argument_list|(
literal|13
argument_list|,
literal|13
argument_list|)
argument_list|,
name|this
argument_list|)
operator|.
name|expandedTo
argument_list|(
name|QApplication
operator|::
name|globalStrut
argument_list|()
argument_list|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Paints the resize grip.      Resize grips are usually rendered as small diagonal textured lines     in the lower-right corner. The paint event is passed in the \a     event parameter. */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QSizeGrip
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|Q_D
argument_list|(
name|QSizeGrip
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOptionSizeGrip
name|opt
decl_stmt|;
name|opt
operator|.
name|init
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|opt
operator|.
name|corner
operator|=
name|d
operator|->
name|m_corner
expr_stmt|;
name|style
argument_list|()
operator|->
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_SizeGrip
argument_list|,
operator|&
name|opt
argument_list|,
operator|&
name|painter
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QSizeGrip::mousePressEvent(QMouseEvent * event)      Receives the mouse press events for the widget, and primes the     resize operation. The mouse press event is passed in the \a event     parameter. */
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|QSizeGrip
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|button
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|QWidget
operator|::
name|mousePressEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return;
block|}
name|Q_D
argument_list|(
name|QSizeGrip
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|tlw
init|=
name|qt_sizegrip_topLevelWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|d
operator|->
name|p
operator|=
name|e
operator|->
name|globalPos
argument_list|()
expr_stmt|;
name|d
operator|->
name|gotMousePress
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|r
operator|=
name|tlw
operator|->
name|geometry
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_X11
comment|// Use a native X11 sizegrip for "real" top-level windows if supported.
if|if
condition|(
name|tlw
operator|->
name|isWindow
argument_list|()
operator|&&
name|X11
operator|->
name|isSupportedByWM
argument_list|(
name|ATOM
argument_list|(
name|_NET_WM_MOVERESIZE
argument_list|)
argument_list|)
operator|&&
operator|!
operator|(
name|tlw
operator|->
name|windowFlags
argument_list|()
operator|&
name|Qt
operator|::
name|X11BypassWindowManagerHint
operator|)
operator|&&
operator|!
name|tlw
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_DontShowOnScreen
argument_list|)
operator|&&
operator|!
name|tlw
operator|->
name|hasHeightForWidth
argument_list|()
condition|)
block|{
name|XEvent
name|xev
decl_stmt|;
name|xev
operator|.
name|xclient
operator|.
name|type
operator|=
name|ClientMessage
expr_stmt|;
name|xev
operator|.
name|xclient
operator|.
name|message_type
operator|=
name|ATOM
argument_list|(
name|_NET_WM_MOVERESIZE
argument_list|)
expr_stmt|;
name|xev
operator|.
name|xclient
operator|.
name|display
operator|=
name|X11
operator|->
name|display
expr_stmt|;
name|xev
operator|.
name|xclient
operator|.
name|window
operator|=
name|tlw
operator|->
name|winId
argument_list|()
expr_stmt|;
name|xev
operator|.
name|xclient
operator|.
name|format
operator|=
literal|32
expr_stmt|;
name|xev
operator|.
name|xclient
operator|.
name|data
operator|.
name|l
index|[
literal|0
index|]
operator|=
name|e
operator|->
name|globalPos
argument_list|()
operator|.
name|x
argument_list|()
expr_stmt|;
name|xev
operator|.
name|xclient
operator|.
name|data
operator|.
name|l
index|[
literal|1
index|]
operator|=
name|e
operator|->
name|globalPos
argument_list|()
operator|.
name|y
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|atBottom
argument_list|()
condition|)
name|xev
operator|.
name|xclient
operator|.
name|data
operator|.
name|l
index|[
literal|2
index|]
operator|=
name|d
operator|->
name|atLeft
argument_list|()
condition|?
literal|6
else|:
literal|4
expr_stmt|;
comment|// bottomleft/bottomright
else|else
name|xev
operator|.
name|xclient
operator|.
name|data
operator|.
name|l
index|[
literal|2
index|]
operator|=
name|d
operator|->
name|atLeft
argument_list|()
condition|?
literal|0
else|:
literal|2
expr_stmt|;
comment|// topleft/topright
name|xev
operator|.
name|xclient
operator|.
name|data
operator|.
name|l
index|[
literal|3
index|]
operator|=
name|Button1
expr_stmt|;
name|xev
operator|.
name|xclient
operator|.
name|data
operator|.
name|l
index|[
literal|4
index|]
operator|=
literal|0
expr_stmt|;
name|XUngrabPointer
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|X11
operator|->
name|time
argument_list|)
expr_stmt|;
name|XSendEvent
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|QX11Info
operator|::
name|appRootWindow
argument_list|(
name|x11Info
argument_list|()
operator|.
name|screen
argument_list|()
argument_list|)
argument_list|,
name|False
argument_list|,
name|SubstructureRedirectMask
operator||
name|SubstructureNotifyMask
argument_list|,
operator|&
name|xev
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
comment|// Q_WS_X11
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|tlw
operator|->
name|isWindow
argument_list|()
operator|&&
operator|!
name|tlw
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_DontShowOnScreen
argument_list|)
operator|&&
operator|!
name|tlw
operator|->
name|hasHeightForWidth
argument_list|()
condition|)
block|{
name|uint
name|orientation
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|atBottom
argument_list|()
condition|)
name|orientation
operator|=
name|d
operator|->
name|atLeft
argument_list|()
condition|?
name|SZ_SIZEBOTTOMLEFT
else|:
name|SZ_SIZEBOTTOMRIGHT
expr_stmt|;
else|else
name|orientation
operator|=
name|d
operator|->
name|atLeft
argument_list|()
condition|?
name|SZ_SIZETOPLEFT
else|:
name|SZ_SIZETOPRIGHT
expr_stmt|;
name|ReleaseCapture
argument_list|()
expr_stmt|;
name|PostMessage
argument_list|(
name|QApplicationPrivate
operator|::
name|getHWNDForWidget
argument_list|(
name|tlw
argument_list|)
argument_list|,
name|WM_SYSCOMMAND
argument_list|,
name|orientation
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
comment|// Q_OS_WIN
comment|// Find available desktop/workspace geometry.
name|QRect
name|availableGeometry
decl_stmt|;
name|bool
name|hasVerticalSizeConstraint
init|=
literal|true
decl_stmt|;
name|bool
name|hasHorizontalSizeConstraint
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|tlw
operator|->
name|isWindow
argument_list|()
condition|)
name|availableGeometry
operator|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|(
name|tlw
argument_list|)
expr_stmt|;
else|else
block|{
specifier|const
name|QWidget
modifier|*
name|tlwParent
init|=
name|tlw
operator|->
name|parentWidget
argument_list|()
decl_stmt|;
comment|// Check if tlw is inside QAbstractScrollArea/QScrollArea.
comment|// If that's the case tlw->parentWidget() will return the viewport
comment|// and tlw->parentWidget()->parentWidget() will return the scroll area.
ifndef|#
directive|ifndef
name|QT_NO_SCROLLAREA
name|QAbstractScrollArea
modifier|*
name|scrollArea
init|=
name|qobject_cast
argument_list|<
name|QAbstractScrollArea
operator|*
argument_list|>
argument_list|(
name|tlwParent
operator|->
name|parentWidget
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|scrollArea
condition|)
block|{
name|hasHorizontalSizeConstraint
operator|=
name|scrollArea
operator|->
name|horizontalScrollBarPolicy
argument_list|()
operator|==
name|Qt
operator|::
name|ScrollBarAlwaysOff
expr_stmt|;
name|hasVerticalSizeConstraint
operator|=
name|scrollArea
operator|->
name|verticalScrollBarPolicy
argument_list|()
operator|==
name|Qt
operator|::
name|ScrollBarAlwaysOff
expr_stmt|;
block|}
endif|#
directive|endif
comment|// QT_NO_SCROLLAREA
name|availableGeometry
operator|=
name|tlwParent
operator|->
name|contentsRect
argument_list|()
expr_stmt|;
block|}
comment|// Find frame geometries, title bar height, and decoration sizes.
specifier|const
name|QRect
name|frameGeometry
init|=
name|tlw
operator|->
name|frameGeometry
argument_list|()
decl_stmt|;
specifier|const
name|int
name|titleBarHeight
init|=
name|qMax
argument_list|(
name|tlw
operator|->
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
operator|-
name|frameGeometry
operator|.
name|y
argument_list|()
argument_list|,
literal|0
argument_list|)
decl_stmt|;
specifier|const
name|int
name|bottomDecoration
init|=
name|qMax
argument_list|(
name|frameGeometry
operator|.
name|height
argument_list|()
operator|-
name|tlw
operator|->
name|height
argument_list|()
operator|-
name|titleBarHeight
argument_list|,
literal|0
argument_list|)
decl_stmt|;
specifier|const
name|int
name|leftRightDecoration
init|=
name|qMax
argument_list|(
operator|(
name|frameGeometry
operator|.
name|width
argument_list|()
operator|-
name|tlw
operator|->
name|width
argument_list|()
operator|)
operator|/
literal|2
argument_list|,
literal|0
argument_list|)
decl_stmt|;
comment|// Determine dyMax depending on whether the sizegrip is at the bottom
comment|// of the widget or not.
if|if
condition|(
name|d
operator|->
name|atBottom
argument_list|()
condition|)
block|{
if|if
condition|(
name|hasVerticalSizeConstraint
condition|)
name|d
operator|->
name|dyMax
operator|=
name|availableGeometry
operator|.
name|bottom
argument_list|()
operator|-
name|d
operator|->
name|r
operator|.
name|bottom
argument_list|()
operator|-
name|bottomDecoration
expr_stmt|;
else|else
name|d
operator|->
name|dyMax
operator|=
name|INT_MAX
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|hasVerticalSizeConstraint
condition|)
name|d
operator|->
name|dyMax
operator|=
name|availableGeometry
operator|.
name|y
argument_list|()
operator|-
name|d
operator|->
name|r
operator|.
name|y
argument_list|()
operator|+
name|titleBarHeight
expr_stmt|;
else|else
name|d
operator|->
name|dyMax
operator|=
operator|-
name|INT_MAX
expr_stmt|;
block|}
comment|// In RTL mode, the size grip is to the left; find dxMax from the desktop/workspace
comment|// geometry, the size grip geometry and the width of the decoration.
if|if
condition|(
name|d
operator|->
name|atLeft
argument_list|()
condition|)
block|{
if|if
condition|(
name|hasHorizontalSizeConstraint
condition|)
name|d
operator|->
name|dxMax
operator|=
name|availableGeometry
operator|.
name|x
argument_list|()
operator|-
name|d
operator|->
name|r
operator|.
name|x
argument_list|()
operator|+
name|leftRightDecoration
expr_stmt|;
else|else
name|d
operator|->
name|dxMax
operator|=
operator|-
name|INT_MAX
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|hasHorizontalSizeConstraint
condition|)
name|d
operator|->
name|dxMax
operator|=
name|availableGeometry
operator|.
name|right
argument_list|()
operator|-
name|d
operator|->
name|r
operator|.
name|right
argument_list|()
operator|-
name|leftRightDecoration
expr_stmt|;
else|else
name|d
operator|->
name|dxMax
operator|=
name|INT_MAX
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \fn void QSizeGrip::mouseMoveEvent(QMouseEvent * event)     Resizes the top-level widget containing this widget. The mouse     move event is passed in the \a event parameter. */
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|QSizeGrip
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|buttons
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|QWidget
operator|::
name|mouseMoveEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
return|return;
block|}
name|Q_D
argument_list|(
name|QSizeGrip
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|tlw
init|=
name|qt_sizegrip_topLevelWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|gotMousePress
operator|||
name|tlw
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_ConfigPending
argument_list|)
condition|)
return|return;
ifdef|#
directive|ifdef
name|Q_WS_X11
if|if
condition|(
name|tlw
operator|->
name|isWindow
argument_list|()
operator|&&
name|X11
operator|->
name|isSupportedByWM
argument_list|(
name|ATOM
argument_list|(
name|_NET_WM_MOVERESIZE
argument_list|)
argument_list|)
operator|&&
name|tlw
operator|->
name|isTopLevel
argument_list|()
operator|&&
operator|!
operator|(
name|tlw
operator|->
name|windowFlags
argument_list|()
operator|&
name|Qt
operator|::
name|X11BypassWindowManagerHint
operator|)
operator|&&
operator|!
name|tlw
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_DontShowOnScreen
argument_list|)
operator|&&
operator|!
name|tlw
operator|->
name|hasHeightForWidth
argument_list|()
condition|)
return|return;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|tlw
operator|->
name|isWindow
argument_list|()
operator|&&
name|qt_getWindowsSystemMenu
argument_list|(
name|tlw
argument_list|)
operator|&&
operator|!
name|tlw
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_DontShowOnScreen
argument_list|)
operator|&&
operator|!
name|tlw
operator|->
name|hasHeightForWidth
argument_list|()
condition|)
block|{
if|if
condition|(
specifier|const
name|HWND
name|hwnd
init|=
name|QApplicationPrivate
operator|::
name|getHWNDForWidget
argument_list|(
name|tlw
argument_list|)
condition|)
block|{
name|MSG
name|msg
decl_stmt|;
while|while
condition|(
name|PeekMessage
argument_list|(
operator|&
name|msg
argument_list|,
name|hwnd
argument_list|,
name|WM_MOUSEMOVE
argument_list|,
name|WM_MOUSEMOVE
argument_list|,
name|PM_REMOVE
argument_list|)
condition|)
empty_stmt|;
return|return;
block|}
block|}
endif|#
directive|endif
name|QPoint
name|np
argument_list|(
name|e
operator|->
name|globalPos
argument_list|()
argument_list|)
decl_stmt|;
comment|// Don't extend beyond the available geometry; bound to dyMax and dxMax.
name|QSize
name|ns
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|atBottom
argument_list|()
condition|)
name|ns
operator|.
name|rheight
argument_list|()
operator|=
name|d
operator|->
name|r
operator|.
name|height
argument_list|()
operator|+
name|qMin
argument_list|(
name|np
operator|.
name|y
argument_list|()
operator|-
name|d
operator|->
name|p
operator|.
name|y
argument_list|()
argument_list|,
name|d
operator|->
name|dyMax
argument_list|)
expr_stmt|;
else|else
name|ns
operator|.
name|rheight
argument_list|()
operator|=
name|d
operator|->
name|r
operator|.
name|height
argument_list|()
operator|-
name|qMax
argument_list|(
name|np
operator|.
name|y
argument_list|()
operator|-
name|d
operator|->
name|p
operator|.
name|y
argument_list|()
argument_list|,
name|d
operator|->
name|dyMax
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|atLeft
argument_list|()
condition|)
name|ns
operator|.
name|rwidth
argument_list|()
operator|=
name|d
operator|->
name|r
operator|.
name|width
argument_list|()
operator|-
name|qMax
argument_list|(
name|np
operator|.
name|x
argument_list|()
operator|-
name|d
operator|->
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|d
operator|->
name|dxMax
argument_list|)
expr_stmt|;
else|else
name|ns
operator|.
name|rwidth
argument_list|()
operator|=
name|d
operator|->
name|r
operator|.
name|width
argument_list|()
operator|+
name|qMin
argument_list|(
name|np
operator|.
name|x
argument_list|()
operator|-
name|d
operator|->
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|d
operator|->
name|dxMax
argument_list|)
expr_stmt|;
name|ns
operator|=
name|QLayout
operator|::
name|closestAcceptableSize
argument_list|(
name|tlw
argument_list|,
name|ns
argument_list|)
expr_stmt|;
name|QPoint
name|p
decl_stmt|;
name|QRect
name|nr
argument_list|(
name|p
argument_list|,
name|ns
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|atBottom
argument_list|()
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|atLeft
argument_list|()
condition|)
name|nr
operator|.
name|moveTopRight
argument_list|(
name|d
operator|->
name|r
operator|.
name|topRight
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|nr
operator|.
name|moveTopLeft
argument_list|(
name|d
operator|->
name|r
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|d
operator|->
name|atLeft
argument_list|()
condition|)
name|nr
operator|.
name|moveBottomRight
argument_list|(
name|d
operator|->
name|r
operator|.
name|bottomRight
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|nr
operator|.
name|moveBottomLeft
argument_list|(
name|d
operator|->
name|r
operator|.
name|bottomLeft
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|tlw
operator|->
name|setGeometry
argument_list|(
name|nr
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|QSizeGrip
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|mouseEvent
parameter_list|)
block|{
if|if
condition|(
name|mouseEvent
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|Q_D
argument_list|(
name|QSizeGrip
argument_list|)
expr_stmt|;
name|d
operator|->
name|gotMousePress
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|p
operator|=
name|QPoint
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QWidget
operator|::
name|mouseReleaseEvent
argument_list|(
name|mouseEvent
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|moveEvent
name|void
name|QSizeGrip
operator|::
name|moveEvent
parameter_list|(
name|QMoveEvent
modifier|*
comment|/*moveEvent*/
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSizeGrip
argument_list|)
expr_stmt|;
comment|// We're inside a resize operation; no update necessary.
if|if
condition|(
operator|!
name|d
operator|->
name|p
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|d
operator|->
name|m_corner
operator|=
name|d
operator|->
name|corner
argument_list|()
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CURSOR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|setCursor
argument_list|(
name|d
operator|->
name|m_corner
operator|==
name|Qt
operator|::
name|TopLeftCorner
operator|||
name|d
operator|->
name|m_corner
operator|==
name|Qt
operator|::
name|BottomRightCorner
condition|?
name|Qt
operator|::
name|SizeFDiagCursor
else|:
name|Qt
operator|::
name|SizeBDiagCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|showEvent
name|void
name|QSizeGrip
operator|::
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
name|showEvent
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|d_func
argument_list|()
operator|->
name|updateMacSizer
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QWidget
operator|::
name|showEvent
argument_list|(
name|showEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|hideEvent
name|void
name|QSizeGrip
operator|::
name|hideEvent
parameter_list|(
name|QHideEvent
modifier|*
name|hideEvent
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|d_func
argument_list|()
operator|->
name|updateMacSizer
argument_list|(
literal|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QWidget
operator|::
name|hideEvent
argument_list|(
name|hideEvent
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|setVisible
name|void
name|QSizeGrip
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|QWidget
operator|::
name|setVisible
argument_list|(
name|visible
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|eventFilter
name|bool
name|QSizeGrip
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSizeGrip
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|isHidden
argument_list|()
operator|&&
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_ExplicitShowHide
argument_list|)
operator|)
operator|||
name|e
operator|->
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|WindowStateChange
operator|||
name|o
operator|!=
name|d
operator|->
name|tlw
condition|)
block|{
return|return
name|QWidget
operator|::
name|eventFilter
argument_list|(
name|o
argument_list|,
name|e
argument_list|)
return|;
block|}
name|Qt
operator|::
name|WindowStates
name|sizeGripNotVisibleState
init|=
name|Qt
operator|::
name|WindowFullScreen
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_WS_MAC
name|sizeGripNotVisibleState
operator||=
name|Qt
operator|::
name|WindowMaximized
expr_stmt|;
endif|#
directive|endif
comment|// Don't show the size grip if the tlw is maximized or in full screen mode.
name|setVisible
argument_list|(
operator|!
operator|(
name|d
operator|->
name|tlw
operator|->
name|windowState
argument_list|()
operator|&
name|sizeGripNotVisibleState
operator|)
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_ExplicitShowHide
argument_list|,
literal|false
argument_list|)
expr_stmt|;
return|return
name|QWidget
operator|::
name|eventFilter
argument_list|(
name|o
argument_list|,
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QSizeGrip
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qsizegrip.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_SIZEGRIP
end_comment
end_unit
