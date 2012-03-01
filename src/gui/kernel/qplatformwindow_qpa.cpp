begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformwindow_qpa.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowsysteminterface_qpa.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qscreen.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QPlatformWindowPrivate
class|class
name|QPlatformWindowPrivate
block|{
DECL|member|window
name|QWindow
modifier|*
name|window
decl_stmt|;
DECL|member|rect
name|QRect
name|rect
decl_stmt|;
friend|friend
class_decl|class
name|QPlatformWindow
class_decl|;
block|}
class|;
end_class
begin_comment
comment|/*!     Constructs a platform window with the given top level window. */
end_comment
begin_constructor
DECL|function|QPlatformWindow
name|QPlatformWindow
operator|::
name|QPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformSurface
argument_list|(
name|QSurface
operator|::
name|Window
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|QPlatformWindowPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|window
operator|=
name|window
expr_stmt|;
name|d
operator|->
name|rect
operator|=
name|window
operator|->
name|geometry
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Virtual destructor does not delete its top level window. */
end_comment
begin_destructor
DECL|function|~QPlatformWindow
name|QPlatformWindow
operator|::
name|~
name|QPlatformWindow
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns the window which belongs to the QPlatformWindow */
end_comment
begin_function
DECL|function|window
name|QWindow
modifier|*
name|QPlatformWindow
operator|::
name|window
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|window
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the parent platform window (or 0 if orphan). */
end_comment
begin_function
DECL|function|parent
name|QPlatformWindow
modifier|*
name|QPlatformWindow
operator|::
name|parent
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|window
operator|->
name|parent
argument_list|()
condition|?
name|d
operator|->
name|window
operator|->
name|parent
argument_list|()
operator|->
name|handle
argument_list|()
else|:
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the platform screen handle corresponding to this platform window. */
end_comment
begin_function
DECL|function|screen
name|QPlatformScreen
modifier|*
name|QPlatformWindow
operator|::
name|screen
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the actual surface format of the window. */
end_comment
begin_function
DECL|function|format
name|QSurfaceFormat
name|QPlatformWindow
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|QSurfaceFormat
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     This function is called by Qt whenever a window is moved or the window is resized. The resize     can happen programatically(from ie. user application) or by the window manager. This means that     there is no need to call this function specifically from the window manager callback, instead     call QWindowSystemInterface::handleGeometryChange(QWindow *w, const QRect&newRect);      The position(x, y) part of the rect might be inclusive or exclusive of the window frame     as returned by frameMargins(). You can detect this in the plugin by checking     qt_window_private(window())->positionPolicy. */
end_comment
begin_function
DECL|function|setGeometry
name|void
name|QPlatformWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|rect
operator|=
name|rect
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returnes the current geometry of a window */
end_comment
begin_function
DECL|function|geometry
name|QRect
name|QPlatformWindow
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|rect
return|;
block|}
end_function
begin_function
DECL|function|frameMargins
name|QMargins
name|QPlatformWindow
operator|::
name|frameMargins
parameter_list|()
specifier|const
block|{
return|return
name|QMargins
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplemented in subclasses to show the surface     if \a visible is \c true, and hide it if \a visible is \c false. */
end_comment
begin_function
DECL|function|setVisible
name|void
name|QPlatformWindow
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|visible
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleSynchronousExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|QRect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Requests setting the window flags of this surface     to \a type. Returns the actual flags set. */
end_comment
begin_function
DECL|function|setWindowFlags
name|Qt
operator|::
name|WindowFlags
name|QPlatformWindow
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
return|return
name|flags
return|;
block|}
end_function
begin_comment
comment|/*!     Returns if this window is exposed in the windowing system.      An exposeEvent() is sent every time this value changes.  */
end_comment
begin_function
DECL|function|isExposed
name|bool
name|QPlatformWindow
operator|::
name|isExposed
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|window
operator|->
name|isVisible
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Requests setting the window state of this surface     to \a type. Returns the actual state set.      Qt::WindowActive can be ignored. */
end_comment
begin_function
DECL|function|setWindowState
name|Qt
operator|::
name|WindowState
name|QPlatformWindow
operator|::
name|setWindowState
parameter_list|(
name|Qt
operator|::
name|WindowState
parameter_list|)
block|{
return|return
name|Qt
operator|::
name|WindowNoState
return|;
block|}
end_function
begin_comment
comment|/*!   Reimplement in subclasses to return a handle to the native window */
end_comment
begin_function
DECL|function|winId
name|WId
name|QPlatformWindow
operator|::
name|winId
parameter_list|()
specifier|const
block|{
comment|// Return anything but 0. Returning 0 would cause havoc with QWidgets on
comment|// very basic platform plugins that do not reimplement this function,
comment|// because the top-level widget's internalWinId() would always be 0 which
comment|// would mean top-levels are never treated as native.
return|return
name|WId
argument_list|(
literal|1
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     This function is called to enable native child window in QPA. It is common not to support this     feature in Window systems, but can be faked. When this function is called all geometry of this     platform window will be relative to the parent. */
end_comment
begin_comment
comment|//jl: It would be useful to have a property on the platform window which indicated if the sub-class
end_comment
begin_comment
comment|// supported the setParent. If not, then geometry would be in screen coordinates.
end_comment
begin_function
DECL|function|setParent
name|void
name|QPlatformWindow
operator|::
name|setParent
parameter_list|(
specifier|const
name|QPlatformWindow
modifier|*
name|parent
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support setParent!"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to set the window title to \a title */
end_comment
begin_function
DECL|function|setWindowTitle
name|void
name|QPlatformWindow
operator|::
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|title
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to be able to let Qt raise windows to the top of the desktop */
end_comment
begin_function
DECL|function|raise
name|void
name|QPlatformWindow
operator|::
name|raise
parameter_list|()
block|{
name|qWarning
argument_list|(
literal|"This plugin does not support raise()"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to be able to let Qt lower windows to the bottom of the desktop */
end_comment
begin_function
DECL|function|lower
name|void
name|QPlatformWindow
operator|::
name|lower
parameter_list|()
block|{
name|qWarning
argument_list|(
literal|"This plugin does not support lower()"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to propagate the size hints of the QWindow.    The size hints include QWindow::minimumSize(), QWindow::maximumSize(),   QWindow::sizeIncrement(), and QWindow::baseSize(). */
end_comment
begin_function
DECL|function|propagateSizeHints
name|void
name|QPlatformWindow
operator|::
name|propagateSizeHints
parameter_list|()
block|{
name|qWarning
argument_list|(
literal|"This plugin does not support propagateSizeHints()"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to be able to let Qt set the opacity level of a window */
end_comment
begin_function
DECL|function|setOpacity
name|void
name|QPlatformWindow
operator|::
name|setOpacity
parameter_list|(
name|qreal
name|level
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|level
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support setting window opacity"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to let Qt be able to request activation/focus for a window    Some window systems will probably not have callbacks for this functionality,   and then calling QWindowSystemInterface::handleWindowActivated(QWindow *w)   would be sufficient.    If the window system has some event handling/callbacks then call   QWindowSystemInterface::handleWindowActivated(QWindow *w) when the window system   gives the notification.    Default implementation calls QWindowSystem::handleWindowActivated(QWindow *w) */
end_comment
begin_function
DECL|function|requestActivateWindow
name|void
name|QPlatformWindow
operator|::
name|requestActivateWindow
parameter_list|()
block|{
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Handle changes to the orientation of the platform window's contents.    This is a hint to the window manager in case it needs to display   additional content like popups, dialogs, status bars, or similar   in relation to the window.    \sa QWindow::reportContentOrientationChange() */
end_comment
begin_function
DECL|function|handleContentOrientationChange
name|void
name|QPlatformWindow
operator|::
name|handleContentOrientationChange
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|orientation
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Request a different orientation of the platform window.    This tells the window manager how the window wants to be rotated in order   to be displayed, and how input events should be translated.    As an example, a portrait compositor might rotate the window by 90 degrees,   if the window is in landscape. It will also rotate input coordinates from   portrait to landscape such that top right in portrait gets mapped to top   left in landscape.    If the implementation doesn't support the requested orientation it should   signal this by returning an actual supported orientation.    If the implementation doesn't support rotating the window at all it should   return Qt::PrimaryOrientation, this is also the default value.    \sa QWindow::requestWindowOrientation() */
end_comment
begin_function
DECL|function|requestWindowOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QPlatformWindow
operator|::
name|requestWindowOrientation
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|orientation
argument_list|)
expr_stmt|;
return|return
name|Qt
operator|::
name|PrimaryOrientation
return|;
block|}
end_function
begin_function
DECL|function|setKeyboardGrabEnabled
name|bool
name|QPlatformWindow
operator|::
name|setKeyboardGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|grab
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support grabbing the keyboard"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|setMouseGrabEnabled
name|bool
name|QPlatformWindow
operator|::
name|setMouseGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|grab
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support grabbing the mouse"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \class QPlatformWindow     \since 4.8     \internal     \preliminary     \ingroup qpa      \brief The QPlatformWindow class provides an abstraction for top-level windows.      The QPlatformWindow abstraction is used by QWindow for all its top level windows. It is being     created by calling the createPlatformWindow function in the loaded QPlatformIntegration     instance.      QPlatformWindow is used to signal to the windowing system, how Qt perceives its frame.     However, it is not concerned with how Qt renders into the window it represents.      Visible QWindows will always have a QPlatformWindow. However, it is not necessary for     all windows to have a QWindowSurface. This is the case for QOpenGLWidget. And could be the case for     windows where some  3.party renders into it.      The platform specific window handle can be retrieved by the winId function.      QPlatformWindow is also the way QPA defines how native child windows should be supported     through the setParent function.      The only way to retrieve a QPlatformOpenGLContext in QPA is by calling the glContext() function     on QPlatformWindow.      \sa QWindowSurface, QWindow */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
