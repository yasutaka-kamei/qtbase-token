begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandbuffer.h"
end_include
begin_include
include|#
directive|include
file|"qwaylanddisplay.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandinputdevice.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandscreen.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WAYLAND_WINDOWMANAGER_SUPPORT
end_ifdef
begin_include
include|#
directive|include
file|"windowmanager_integration/qwaylandwindowmanagerintegration.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWidget>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_constructor
DECL|function|QWaylandWindow
name|QWaylandWindow
operator|::
name|QWaylandWindow
parameter_list|(
name|QWidget
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mDisplay
argument_list|(
name|QWaylandScreen
operator|::
name|waylandScreenFromWidget
argument_list|(
name|window
argument_list|)
operator|->
name|display
argument_list|()
argument_list|)
member_init_list|,
name|mBuffer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mWaitingForFrameSync
argument_list|(
literal|false
argument_list|)
block|{
specifier|static
name|WId
name|id
init|=
literal|1
decl_stmt|;
name|mWindowId
operator|=
name|id
operator|++
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_WAYLAND_WINDOWMANAGER_SUPPORT
name|mDisplay
operator|->
name|windowManagerIntegration
argument_list|()
operator|->
name|mapClientToProcess
argument_list|(
name|qApp
operator|->
name|applicationPid
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|mSurface
operator|=
name|mDisplay
operator|->
name|createSurface
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandWindow
name|QWaylandWindow
operator|::
name|~
name|QWaylandWindow
parameter_list|()
block|{
if|if
condition|(
name|mSurface
condition|)
name|wl_surface_destroy
argument_list|(
name|mSurface
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QWaylandInputDevice
modifier|*
argument_list|>
name|inputDevices
init|=
name|mDisplay
operator|->
name|inputDevices
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|inputDevices
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|inputDevices
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|handleWindowDestroyed
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|winId
name|WId
name|QWaylandWindow
operator|::
name|winId
parameter_list|()
specifier|const
block|{
return|return
name|mWindowId
return|;
block|}
end_function
begin_function
DECL|function|setParent
name|void
name|QWaylandWindow
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
literal|"Sub window is not supported"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QWaylandWindow
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mSurface
operator|&&
name|visible
condition|)
block|{
name|mSurface
operator|=
name|mDisplay
operator|->
name|createSurface
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|newSurfaceCreated
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|visible
condition|)
block|{
name|wl_surface_map_toplevel
argument_list|(
name|mSurface
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|wl_surface_destroy
argument_list|(
name|mSurface
argument_list|)
expr_stmt|;
name|mSurface
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|configure
name|void
name|QWaylandWindow
operator|::
name|configure
parameter_list|(
name|uint32_t
name|time
parameter_list|,
name|uint32_t
name|edges
parameter_list|,
name|int32_t
name|x
parameter_list|,
name|int32_t
name|y
parameter_list|,
name|int32_t
name|width
parameter_list|,
name|int32_t
name|height
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|time
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|edges
argument_list|)
expr_stmt|;
name|QRect
name|geometry
init|=
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|setGeometry
argument_list|(
name|geometry
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|widget
argument_list|()
argument_list|,
name|geometry
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|attach
name|void
name|QWaylandWindow
operator|::
name|attach
parameter_list|(
name|QWaylandBuffer
modifier|*
name|buffer
parameter_list|)
block|{
name|mBuffer
operator|=
name|buffer
expr_stmt|;
if|if
condition|(
name|mSurface
condition|)
block|{
name|wl_surface_attach
argument_list|(
name|mSurface
argument_list|,
name|buffer
operator|->
name|buffer
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|damage
name|void
name|QWaylandWindow
operator|::
name|damage
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
comment|//We have to do sync stuff before calling damage, or we might
comment|//get a frame callback before we get the timestamp
name|mDisplay
operator|->
name|frameCallback
argument_list|(
name|QWaylandWindow
operator|::
name|frameCallback
argument_list|,
name|mSurface
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|mWaitingForFrameSync
operator|=
literal|true
expr_stmt|;
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|region
operator|.
name|rects
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|rects
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|QRect
name|rect
init|=
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|wl_surface_damage
argument_list|(
name|mSurface
argument_list|,
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|newSurfaceCreated
name|void
name|QWaylandWindow
operator|::
name|newSurfaceCreated
parameter_list|()
block|{
if|if
condition|(
name|mBuffer
condition|)
block|{
name|wl_surface_attach
argument_list|(
name|mSurface
argument_list|,
name|mBuffer
operator|->
name|buffer
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|frameCallback
name|void
name|QWaylandWindow
operator|::
name|frameCallback
parameter_list|(
name|struct
name|wl_surface
modifier|*
name|surface
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|uint32_t
name|time
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|time
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|QWaylandWindow
modifier|*
name|self
init|=
cast|static_cast
argument_list|<
name|QWaylandWindow
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|self
operator|->
name|mWaitingForFrameSync
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForFrameSync
name|void
name|QWaylandWindow
operator|::
name|waitForFrameSync
parameter_list|()
block|{
name|mDisplay
operator|->
name|flushRequests
argument_list|()
expr_stmt|;
while|while
condition|(
name|mWaitingForFrameSync
condition|)
name|mDisplay
operator|->
name|blockingReadEvents
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
