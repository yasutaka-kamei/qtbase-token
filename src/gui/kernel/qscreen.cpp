begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qscreen.h"
end_include
begin_include
include|#
directive|include
file|"qscreen_p.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qguiapplication_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QScreen     \since 5.0     \brief The QScreen class is used to query screen properties.     \inmodule QtGui      A note on logical vs physical dots per inch: physical DPI is based on the     actual physical pixel sizes when available, and is useful for print preview     and other cases where it's desirable to know the exact physical dimensions     of screen displayed contents.      Logical dots per inch are used to convert font and user interface elements     from point sizes to pixel sizes, and might be different from the physical     dots per inch. The logical dots per inch are sometimes user-settable in the     desktop environment's settings panel, to let the user globally control UI     and font sizes in different applications.      \inmodule QtGui */
end_comment
begin_constructor
DECL|function|QScreen
name|QScreen
operator|::
name|QScreen
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QScreenPrivate
argument_list|()
argument_list|,
literal|0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QScreen
argument_list|)
expr_stmt|;
name|d
operator|->
name|setPlatformScreen
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setPlatformScreen
name|void
name|QScreenPrivate
operator|::
name|setPlatformScreen
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QScreen
argument_list|)
expr_stmt|;
name|platformScreen
operator|=
name|screen
expr_stmt|;
name|platformScreen
operator|->
name|d_func
argument_list|()
operator|->
name|screen
operator|=
name|q
expr_stmt|;
name|orientation
operator|=
name|platformScreen
operator|->
name|orientation
argument_list|()
expr_stmt|;
name|geometry
operator|=
name|platformScreen
operator|->
name|deviceIndependentGeometry
argument_list|()
expr_stmt|;
name|availableGeometry
operator|=
name|QHighDpi
operator|::
name|fromNative
argument_list|(
name|platformScreen
operator|->
name|availableGeometry
argument_list|()
argument_list|,
name|QHighDpiScaling
operator|::
name|factor
argument_list|(
name|platformScreen
argument_list|)
argument_list|,
name|geometry
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
name|logicalDpi
operator|=
name|platformScreen
operator|->
name|logicalDpi
argument_list|()
expr_stmt|;
name|refreshRate
operator|=
name|platformScreen
operator|->
name|refreshRate
argument_list|()
expr_stmt|;
comment|// safeguard ourselves against buggy platform behavior...
if|if
condition|(
name|refreshRate
operator|<
literal|1.0
condition|)
name|refreshRate
operator|=
literal|60.0
expr_stmt|;
name|updatePrimaryOrientation
argument_list|()
expr_stmt|;
name|filteredOrientation
operator|=
name|orientation
expr_stmt|;
if|if
condition|(
name|filteredOrientation
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|filteredOrientation
operator|=
name|primaryOrientation
expr_stmt|;
name|updateHighDpi
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Destroys the screen.  */
end_comment
begin_destructor
DECL|function|~QScreen
name|QScreen
operator|::
name|~
name|QScreen
parameter_list|()
block|{
if|if
condition|(
operator|!
name|qApp
condition|)
return|return;
comment|// Allow clients to manage windows that are affected by the screen going
comment|// away, before we fall back to moving them to the primary screen.
emit|emit
name|qApp
operator|->
name|screenRemoved
argument_list|(
name|this
argument_list|)
emit|;
if|if
condition|(
name|QGuiApplication
operator|::
name|closingDown
argument_list|()
condition|)
return|return;
name|QScreen
modifier|*
name|primaryScreen
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
decl_stmt|;
if|if
condition|(
name|this
operator|==
name|primaryScreen
condition|)
return|return;
name|bool
name|movingFromVirtualSibling
init|=
name|primaryScreen
operator|&&
name|primaryScreen
operator|->
name|handle
argument_list|()
operator|->
name|virtualSiblings
argument_list|()
operator|.
name|contains
argument_list|(
name|handle
argument_list|()
argument_list|)
decl_stmt|;
comment|// Move any leftover windows to the primary screen
foreach|foreach
control|(
name|QWindow
modifier|*
name|window
decl|,
name|QGuiApplication
operator|::
name|allWindows
argument_list|()
control|)
block|{
if|if
condition|(
operator|!
name|window
operator|->
name|isTopLevel
argument_list|()
operator|||
name|window
operator|->
name|screen
argument_list|()
operator|!=
name|this
condition|)
continue|continue;
specifier|const
name|bool
name|wasVisible
init|=
name|window
operator|->
name|isVisible
argument_list|()
decl_stmt|;
name|window
operator|->
name|setScreen
argument_list|(
name|primaryScreen
argument_list|)
expr_stmt|;
comment|// Re-show window if moved from a virtual sibling screen. Otherwise
comment|// leave it up to the application developer to show the window.
if|if
condition|(
name|movingFromVirtualSibling
condition|)
name|window
operator|->
name|setVisible
argument_list|(
name|wasVisible
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!   Get the platform screen handle. */
end_comment
begin_function
DECL|function|handle
name|QPlatformScreen
modifier|*
name|QScreen
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::name   \brief a user presentable string representing the screen    For example, on X11 these correspond to the XRandr screen names,   typically "VGA1", "HDMI1", etc. */
end_comment
begin_function
DECL|function|name
name|QString
name|QScreen
operator|::
name|name
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|name
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::depth   \brief the color depth of the screen */
end_comment
begin_function
DECL|function|depth
name|int
name|QScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|depth
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::size   \brief the pixel resolution of the screen */
end_comment
begin_function
DECL|function|size
name|QSize
name|QScreen
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|geometry
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalDotsPerInchX   \brief the number of physical dots or pixels per inch in the horizontal direction    This value represents the actual horizontal pixel density on the screen's display.   Depending on what information the underlying system provides the value might not be   entirely accurate.    \sa physicalDotsPerInchY() */
end_comment
begin_function
DECL|function|physicalDotsPerInchX
name|qreal
name|QScreen
operator|::
name|physicalDotsPerInchX
parameter_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|/
name|physicalSize
argument_list|()
operator|.
name|width
argument_list|()
operator|*
name|qreal
argument_list|(
literal|25.4
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalDotsPerInchY   \brief the number of physical dots or pixels per inch in the vertical direction    This value represents the actual vertical pixel density on the screen's display.   Depending on what information the underlying system provides the value might not be   entirely accurate.    \sa physicalDotsPerInchX() */
end_comment
begin_function
DECL|function|physicalDotsPerInchY
name|qreal
name|QScreen
operator|::
name|physicalDotsPerInchY
parameter_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|physicalSize
argument_list|()
operator|.
name|height
argument_list|()
operator|*
name|qreal
argument_list|(
literal|25.4
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalDotsPerInch   \brief the number of physical dots or pixels per inch    This value represents the pixel density on the screen's display.   Depending on what information the underlying system provides the value might not be   entirely accurate.    This is a convenience property that's simply the average of the physicalDotsPerInchX   and physicalDotsPerInchY properties.    \sa physicalDotsPerInchX()   \sa physicalDotsPerInchY() */
end_comment
begin_function
DECL|function|physicalDotsPerInch
name|qreal
name|QScreen
operator|::
name|physicalDotsPerInch
parameter_list|()
specifier|const
block|{
name|QSize
name|sz
init|=
name|size
argument_list|()
decl_stmt|;
name|QSizeF
name|psz
init|=
name|physicalSize
argument_list|()
decl_stmt|;
return|return
operator|(
operator|(
name|sz
operator|.
name|height
argument_list|()
operator|/
name|psz
operator|.
name|height
argument_list|()
operator|)
operator|+
operator|(
name|sz
operator|.
name|width
argument_list|()
operator|/
name|psz
operator|.
name|width
argument_list|()
operator|)
operator|)
operator|*
name|qreal
argument_list|(
literal|25.4
operator|*
literal|0.5
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::logicalDotsPerInchX   \brief the number of logical dots or pixels per inch in the horizontal direction    This value is used to convert font point sizes to pixel sizes.    \sa logicalDotsPerInchY() */
end_comment
begin_function
DECL|function|logicalDotsPerInchX
name|qreal
name|QScreen
operator|::
name|logicalDotsPerInchX
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
if|if
condition|(
name|QHighDpiScaling
operator|::
name|isActive
argument_list|()
condition|)
return|return
name|QHighDpiScaling
operator|::
name|logicalDpi
argument_list|()
operator|.
name|first
return|;
return|return
name|d
operator|->
name|logicalDpi
operator|.
name|first
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::logicalDotsPerInchY   \brief the number of logical dots or pixels per inch in the vertical direction    This value is used to convert font point sizes to pixel sizes.    \sa logicalDotsPerInchX() */
end_comment
begin_function
DECL|function|logicalDotsPerInchY
name|qreal
name|QScreen
operator|::
name|logicalDotsPerInchY
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
if|if
condition|(
name|QHighDpiScaling
operator|::
name|isActive
argument_list|()
condition|)
return|return
name|QHighDpiScaling
operator|::
name|logicalDpi
argument_list|()
operator|.
name|second
return|;
return|return
name|d
operator|->
name|logicalDpi
operator|.
name|second
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::logicalDotsPerInch   \brief the number of logical dots or pixels per inch    This value can be used to convert font point sizes to pixel sizes.    This is a convenience property that's simply the average of the logicalDotsPerInchX   and logicalDotsPerInchY properties.    \sa logicalDotsPerInchX()   \sa logicalDotsPerInchY() */
end_comment
begin_function
DECL|function|logicalDotsPerInch
name|qreal
name|QScreen
operator|::
name|logicalDotsPerInch
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
name|QDpi
name|dpi
init|=
name|QHighDpiScaling
operator|::
name|isActive
argument_list|()
condition|?
name|QHighDpiScaling
operator|::
name|logicalDpi
argument_list|()
else|:
name|d
operator|->
name|logicalDpi
decl_stmt|;
return|return
operator|(
name|dpi
operator|.
name|first
operator|+
name|dpi
operator|.
name|second
operator|)
operator|*
name|qreal
argument_list|(
literal|0.5
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::devicePixelRatio     \brief the screen's ratio between physical pixels and device-independent pixels     \since 5.5      Returns the ratio between physical pixels and device-independent pixels for the screen.      Common values are 1.0 on normal displays and 2.0 on "retina" displays.     Higher values are also possible.      \sa QWindow::devicePixelRatio(), QGuiApplication::devicePixelRatio() */
end_comment
begin_function
DECL|function|devicePixelRatio
name|qreal
name|QScreen
operator|::
name|devicePixelRatio
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|devicePixelRatio
argument_list|()
operator|*
name|QHighDpiScaling
operator|::
name|factor
argument_list|(
name|this
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalSize   \brief the screen's physical size (in millimeters)    The physical size represents the actual physical dimensions of the   screen's display.    Depending on what information the underlying system provides the value   might not be entirely accurate. */
end_comment
begin_function
DECL|function|physicalSize
name|QSizeF
name|QScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|physicalSize
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::availableSize   \brief the screen's available size in pixels    The available size is the size excluding window manager reserved areas   such as task bars and system menus. */
end_comment
begin_function
DECL|function|availableSize
name|QSize
name|QScreen
operator|::
name|availableSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|availableGeometry
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::geometry   \brief the screen's geometry in pixels    As an example this might return QRect(0, 0, 1280, 1024), or in a   virtual desktop setting QRect(1280, 0, 1280, 1024). */
end_comment
begin_function
DECL|function|geometry
name|QRect
name|QScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|geometry
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::availableGeometry   \brief the screen's available geometry in pixels    The available geometry is the geometry excluding window manager reserved areas   such as task bars and system menus. */
end_comment
begin_function
DECL|function|availableGeometry
name|QRect
name|QScreen
operator|::
name|availableGeometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|availableGeometry
return|;
block|}
end_function
begin_comment
comment|/*!   Get the screen's virtual siblings.    The virtual siblings are the screen instances sharing the same virtual desktop.   They share a common coordinate system, and windows can freely be moved or   positioned across them without having to be re-created. */
end_comment
begin_function
DECL|function|virtualSiblings
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|QScreen
operator|::
name|virtualSiblings
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|platformScreens
init|=
name|d
operator|->
name|platformScreen
operator|->
name|virtualSiblings
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
decl_stmt|;
name|screens
operator|.
name|reserve
argument_list|(
name|platformScreens
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QPlatformScreen
modifier|*
name|platformScreen
decl|,
name|platformScreens
control|)
name|screens
operator|<<
name|platformScreen
operator|->
name|screen
argument_list|()
expr_stmt|;
return|return
name|screens
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::virtualSize     \brief the pixel size of the virtual desktop to which this screen belongs    Returns the pixel size of the virtual desktop corresponding to this screen.    This is the combined size of the virtual siblings' individual geometries.    \sa virtualSiblings() */
end_comment
begin_function
DECL|function|virtualSize
name|QSize
name|QScreen
operator|::
name|virtualSize
parameter_list|()
specifier|const
block|{
return|return
name|virtualGeometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::virtualGeometry     \brief the pixel geometry of the virtual desktop to which this screen belongs    Returns the pixel geometry of the virtual desktop corresponding to this screen.    This is the union of the virtual siblings' individual geometries.    \sa virtualSiblings() */
end_comment
begin_function
DECL|function|virtualGeometry
name|QRect
name|QScreen
operator|::
name|virtualGeometry
parameter_list|()
specifier|const
block|{
name|QRect
name|result
decl_stmt|;
foreach|foreach
control|(
name|QScreen
modifier|*
name|screen
decl|,
name|virtualSiblings
argument_list|()
control|)
name|result
operator||=
name|screen
operator|->
name|geometry
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::availableVirtualSize     \brief the available size of the virtual desktop to which this screen belongs    Returns the available pixel size of the virtual desktop corresponding to this screen.    This is the combined size of the virtual siblings' individual available geometries.    \sa availableSize(), virtualSiblings() */
end_comment
begin_function
DECL|function|availableVirtualSize
name|QSize
name|QScreen
operator|::
name|availableVirtualSize
parameter_list|()
specifier|const
block|{
return|return
name|availableVirtualGeometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::availableVirtualGeometry     \brief the available geometry of the virtual desktop to which this screen belongs    Returns the available geometry of the virtual desktop corresponding to this screen.    This is the union of the virtual siblings' individual available geometries.    \sa availableGeometry(), virtualSiblings() */
end_comment
begin_function
DECL|function|availableVirtualGeometry
name|QRect
name|QScreen
operator|::
name|availableVirtualGeometry
parameter_list|()
specifier|const
block|{
name|QRect
name|result
decl_stmt|;
foreach|foreach
control|(
name|QScreen
modifier|*
name|screen
decl|,
name|virtualSiblings
argument_list|()
control|)
name|result
operator||=
name|screen
operator|->
name|availableGeometry
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the orientations that the application is interested in receiving     updates for in conjunction with this screen.      For example, to receive orientation() updates and thus have     orientationChanged() signals being emitted for LandscapeOrientation and     InvertedLandscapeOrientation, call setOrientationUpdateMask() with     \a{mask} set to Qt::LandscapeOrientation | Qt::InvertedLandscapeOrientation.      The default, 0, means no orientationChanged() signals are fired. */
end_comment
begin_function
DECL|function|setOrientationUpdateMask
name|void
name|QScreen
operator|::
name|setOrientationUpdateMask
parameter_list|(
name|Qt
operator|::
name|ScreenOrientations
name|mask
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QScreen
argument_list|)
expr_stmt|;
name|d
operator|->
name|orientationUpdateMask
operator|=
name|mask
expr_stmt|;
name|d
operator|->
name|platformScreen
operator|->
name|setOrientationUpdateMask
argument_list|(
name|mask
argument_list|)
expr_stmt|;
name|QGuiApplicationPrivate
operator|::
name|updateFilteredScreenOrientation
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the currently set orientation update mask.      \sa setOrientationUpdateMask() */
end_comment
begin_function
DECL|function|orientationUpdateMask
name|Qt
operator|::
name|ScreenOrientations
name|QScreen
operator|::
name|orientationUpdateMask
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|orientationUpdateMask
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::orientation     \brief the screen orientation      The screen orientation represents the physical orientation     of the display. For example, the screen orientation of a mobile device     will change based on how it is being held. A change to the orientation     might or might not trigger a change to the primary orientation of the screen.      Changes to this property will be filtered by orientationUpdateMask(),     so in order to receive orientation updates the application must first     call setOrientationUpdateMask() with a mask of the orientations it wants     to receive.      Qt::PrimaryOrientation is never returned.      \sa primaryOrientation() */
end_comment
begin_function
DECL|function|orientation
name|Qt
operator|::
name|ScreenOrientation
name|QScreen
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|filteredOrientation
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::refreshRate   \brief the approximate vertical refresh rate of the screen in Hz */
end_comment
begin_function
DECL|function|refreshRate
name|qreal
name|QScreen
operator|::
name|refreshRate
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|refreshRate
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::primaryOrientation     \brief the primary screen orientation      The primary screen orientation is Qt::LandscapeOrientation     if the screen geometry's width is greater than or equal to its     height, or Qt::PortraitOrientation otherwise. This property might     change when the screen orientation was changed (i.e. when the     display is rotated).     The behavior is however platform dependent and can often be specified in     an application manifest file.  */
end_comment
begin_function
DECL|function|primaryOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QScreen
operator|::
name|primaryOrientation
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|primaryOrientation
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::nativeOrientation     \brief the native screen orientation     \since 5.2      The native orientation of the screen is the orientation where the logo     sticker of the device appears the right way up, or Qt::PrimaryOrientation     if the platform does not support this functionality.      The native orientation is a property of the hardware, and does not change. */
end_comment
begin_function
DECL|function|nativeOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QScreen
operator|::
name|nativeOrientation
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|nativeOrientation
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function to compute the angle of rotation to get from     rotation \a a to rotation \a b.      The result will be 0, 90, 180, or 270.      Qt::PrimaryOrientation is interpreted as the screen's primaryOrientation(). */
end_comment
begin_function
DECL|function|angleBetween
name|int
name|QScreen
operator|::
name|angleBetween
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|a
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|a
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
if|if
condition|(
name|b
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|b
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
return|return
name|QPlatformScreen
operator|::
name|angleBetween
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function to compute a transform that maps from the coordinate system     defined by orientation \a a into the coordinate system defined by orientation     \a b and target dimensions \a target.      Example, \a a is Qt::Landscape, \a b is Qt::Portrait, and \a target is QRect(0, 0, w, h)     the resulting transform will be such that the point QPoint(0, 0) is mapped to QPoint(0, w),     and QPoint(h, w) is mapped to QPoint(0, h). Thus, the landscape coordinate system QRect(0, 0, h, w)     is mapped (with a 90 degree rotation) into the portrait coordinate system QRect(0, 0, w, h).      Qt::PrimaryOrientation is interpreted as the screen's primaryOrientation(). */
end_comment
begin_function
DECL|function|transformBetween
name|QTransform
name|QScreen
operator|::
name|transformBetween
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
parameter_list|,
specifier|const
name|QRect
modifier|&
name|target
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|a
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|a
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
if|if
condition|(
name|b
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|b
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
return|return
name|QPlatformScreen
operator|::
name|transformBetween
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|target
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Maps the rect between two screen orientations.      This will flip the x and y dimensions of the rectangle \a{rect} if the orientation \a{a} is     Qt::PortraitOrientation or Qt::InvertedPortraitOrientation and orientation \a{b} is     Qt::LandscapeOrientation or Qt::InvertedLandscapeOrientation, or vice versa.      Qt::PrimaryOrientation is interpreted as the screen's primaryOrientation(). */
end_comment
begin_function
DECL|function|mapBetween
name|QRect
name|QScreen
operator|::
name|mapBetween
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|a
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|a
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
if|if
condition|(
name|b
operator|==
name|Qt
operator|::
name|PrimaryOrientation
condition|)
name|b
operator|=
name|primaryOrientation
argument_list|()
expr_stmt|;
return|return
name|QPlatformScreen
operator|::
name|mapBetween
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|rect
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function that returns \c true if \a o is either portrait or inverted portrait;     otherwise returns \c false.      Qt::PrimaryOrientation is interpreted as the screen's primaryOrientation(). */
end_comment
begin_function
DECL|function|isPortrait
name|bool
name|QScreen
operator|::
name|isPortrait
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|o
parameter_list|)
specifier|const
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|PortraitOrientation
operator|||
name|o
operator|==
name|Qt
operator|::
name|InvertedPortraitOrientation
operator|||
operator|(
name|o
operator|==
name|Qt
operator|::
name|PrimaryOrientation
operator|&&
name|primaryOrientation
argument_list|()
operator|==
name|Qt
operator|::
name|PortraitOrientation
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function that returns \c true if \a o is either landscape or inverted landscape;     otherwise returns \c false.      Qt::PrimaryOrientation is interpreted as the screen's primaryOrientation(). */
end_comment
begin_function
DECL|function|isLandscape
name|bool
name|QScreen
operator|::
name|isLandscape
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|o
parameter_list|)
specifier|const
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|LandscapeOrientation
operator|||
name|o
operator|==
name|Qt
operator|::
name|InvertedLandscapeOrientation
operator|||
operator|(
name|o
operator|==
name|Qt
operator|::
name|PrimaryOrientation
operator|&&
name|primaryOrientation
argument_list|()
operator|==
name|Qt
operator|::
name|LandscapeOrientation
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QScreen::orientationChanged(Qt::ScreenOrientation orientation)      This signal is emitted when the orientation of the screen     changes with \a orientation as an argument.      \sa orientation() */
end_comment
begin_comment
comment|/*!     \fn void QScreen::primaryOrientationChanged(Qt::ScreenOrientation orientation)      This signal is emitted when the primary orientation of the screen     changes with \a orientation as an argument.      \sa primaryOrientation() */
end_comment
begin_function
DECL|function|updatePrimaryOrientation
name|void
name|QScreenPrivate
operator|::
name|updatePrimaryOrientation
parameter_list|()
block|{
name|primaryOrientation
operator|=
name|geometry
operator|.
name|width
argument_list|()
operator|>=
name|geometry
operator|.
name|height
argument_list|()
condition|?
name|Qt
operator|::
name|LandscapeOrientation
else|:
name|Qt
operator|::
name|PortraitOrientation
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Creates and returns a pixmap constructed by grabbing the contents     of the given \a window restricted by QRect(\a x, \a y, \a width,     \a height).      The arguments (\a{x}, \a{y}) specify the offset in the window,     whereas (\a{width}, \a{height}) specify the area to be copied.  If     \a width is negative, the function copies everything to the right     border of the window. If \a height is negative, the function     copies everything to the bottom of the window.      The window system identifier (\c WId) can be retrieved using the     QWidget::winId() function. The rationale for using a window     identifier and not a QWidget, is to enable grabbing of windows     that are not part of the application, window system frames, and so     on.      The grabWindow() function grabs pixels from the screen, not from     the window, i.e. if there is another window partially or entirely     over the one you grab, you get pixels from the overlying window,     too. The mouse cursor is generally not grabbed.      Note on X11 that if the given \a window doesn't have the same depth     as the root window, and another window partially or entirely     obscures the one you grab, you will \e not get pixels from the     overlying window.  The contents of the obscured areas in the     pixmap will be undefined and uninitialized.      On Windows Vista and above grabbing a layered window, which is     created by setting the Qt::WA_TranslucentBackground attribute, will     not work. Instead grabbing the desktop widget should work.      \warning In general, grabbing an area outside the screen is not     safe. This depends on the underlying window system. */
end_comment
begin_function
DECL|function|grabWindow
name|QPixmap
name|QScreen
operator|::
name|grabWindow
parameter_list|(
name|WId
name|window
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
specifier|const
name|QPlatformScreen
modifier|*
name|platformScreen
init|=
name|handle
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|platformScreen
condition|)
block|{
name|qWarning
argument_list|(
literal|"invoked with handle==0"
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
return|return
name|platformScreen
operator|->
name|grabWindow
argument_list|(
name|window
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|formatRect
specifier|static
specifier|inline
name|void
name|formatRect
parameter_list|(
name|QDebug
modifier|&
name|debug
parameter_list|,
specifier|const
name|QRect
name|r
parameter_list|)
block|{
name|debug
operator|<<
name|r
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|r
operator|.
name|height
argument_list|()
operator|<<
name|forcesign
operator|<<
name|r
operator|.
name|x
argument_list|()
operator|<<
name|r
operator|.
name|y
argument_list|()
operator|<<
name|noforcesign
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator <<
name|Q_GUI_EXPORT
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|debug
parameter_list|,
specifier|const
name|QScreen
modifier|*
name|screen
parameter_list|)
block|{
specifier|const
name|QDebugStateSaver
name|saver
argument_list|(
name|debug
argument_list|)
decl_stmt|;
name|debug
operator|.
name|nospace
argument_list|()
expr_stmt|;
name|debug
operator|<<
literal|"QScreen("
operator|<<
operator|(
specifier|const
name|void
operator|*
operator|)
name|screen
expr_stmt|;
if|if
condition|(
name|screen
condition|)
block|{
name|debug
operator|<<
literal|", name="
operator|<<
name|screen
operator|->
name|name
argument_list|()
expr_stmt|;
if|if
condition|(
name|debug
operator|.
name|verbosity
argument_list|()
operator|>
literal|2
condition|)
block|{
if|if
condition|(
name|screen
operator|==
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
condition|)
name|debug
operator|<<
literal|", primary"
expr_stmt|;
name|debug
operator|<<
literal|", geometry="
expr_stmt|;
name|formatRect
argument_list|(
name|debug
argument_list|,
name|screen
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|debug
operator|<<
literal|", available="
expr_stmt|;
name|formatRect
argument_list|(
name|debug
argument_list|,
name|screen
operator|->
name|availableGeometry
argument_list|()
argument_list|)
expr_stmt|;
name|debug
operator|<<
literal|", logical DPI="
operator|<<
name|screen
operator|->
name|logicalDotsPerInchX
argument_list|()
operator|<<
literal|','
operator|<<
name|screen
operator|->
name|logicalDotsPerInchY
argument_list|()
operator|<<
literal|", physical DPI="
operator|<<
name|screen
operator|->
name|physicalDotsPerInchX
argument_list|()
operator|<<
literal|','
operator|<<
name|screen
operator|->
name|physicalDotsPerInchY
argument_list|()
operator|<<
literal|", devicePixelRatio="
operator|<<
name|screen
operator|->
name|devicePixelRatio
argument_list|()
operator|<<
literal|", orientation="
operator|<<
name|screen
operator|->
name|orientation
argument_list|()
operator|<<
literal|", physical size="
operator|<<
name|screen
operator|->
name|physicalSize
argument_list|()
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|screen
operator|->
name|physicalSize
argument_list|()
operator|.
name|height
argument_list|()
operator|<<
literal|"mm"
expr_stmt|;
block|}
block|}
name|debug
operator|<<
literal|')'
expr_stmt|;
return|return
name|debug
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_DEBUG_STREAM
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
