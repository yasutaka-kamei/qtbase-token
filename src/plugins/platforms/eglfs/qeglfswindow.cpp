begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSWindow
name|QEglFSWindow
operator|::
name|QEglFSWindow
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|w
argument_list|)
member_init_list|,
name|m_surface
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_window
argument_list|(
literal|0
argument_list|)
block|{
specifier|static
name|int
name|serialNo
init|=
literal|0
decl_stmt|;
name|m_winid
operator|=
operator|++
name|serialNo
expr_stmt|;
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglWindow %p: %p 0x%x\n"
argument_list|,
name|this
argument_list|,
name|w
argument_list|,
name|uint
argument_list|(
name|m_winid
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~QEglFSWindow
name|QEglFSWindow
operator|::
name|~
name|QEglFSWindow
parameter_list|()
block|{
name|destroy
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|create
name|void
name|QEglFSWindow
operator|::
name|create
parameter_list|()
block|{
if|if
condition|(
name|m_window
condition|)
return|return;
name|setWindowState
argument_list|(
name|Qt
operator|::
name|WindowFullScreen
argument_list|)
expr_stmt|;
if|if
condition|(
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
condition|)
block|{
name|QRect
name|rect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|screenSize
argument_list|()
argument_list|)
decl_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
return|return;
block|}
name|EGLDisplay
name|display
init|=
operator|(
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|window
argument_list|()
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
operator|)
operator|->
name|display
argument_list|()
decl_stmt|;
name|QSurfaceFormat
name|platformFormat
init|=
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|surfaceFormatFor
argument_list|(
name|window
argument_list|()
operator|->
name|requestedFormat
argument_list|()
argument_list|)
decl_stmt|;
name|m_config
operator|=
name|QEglFSIntegration
operator|::
name|chooseConfig
argument_list|(
name|display
argument_list|,
name|platformFormat
argument_list|)
expr_stmt|;
name|m_format
operator|=
name|q_glFormatFromConfig
argument_list|(
name|display
argument_list|,
name|m_config
argument_list|)
expr_stmt|;
name|resetSurface
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|invalidateSurface
name|void
name|QEglFSWindow
operator|::
name|invalidateSurface
parameter_list|()
block|{
comment|// Native surface has been deleted behind our backs
name|m_window
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|m_surface
operator|!=
literal|0
condition|)
block|{
name|EGLDisplay
name|display
init|=
operator|(
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|window
argument_list|()
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
operator|)
operator|->
name|display
argument_list|()
decl_stmt|;
name|eglDestroySurface
argument_list|(
name|display
argument_list|,
name|m_surface
argument_list|)
expr_stmt|;
name|m_surface
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resetSurface
name|void
name|QEglFSWindow
operator|::
name|resetSurface
parameter_list|()
block|{
name|EGLDisplay
name|display
init|=
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|()
argument_list|)
operator|->
name|display
argument_list|()
decl_stmt|;
name|m_window
operator|=
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|createNativeWindow
argument_list|(
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|screenSize
argument_list|()
argument_list|,
name|m_format
argument_list|)
expr_stmt|;
name|m_surface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|display
argument_list|,
name|m_config
argument_list|,
name|m_window
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_surface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|EGLint
name|error
init|=
name|eglGetError
argument_list|()
decl_stmt|;
name|eglTerminate
argument_list|(
name|display
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL Error : Could not create the egl surface: error = 0x%x\n"
argument_list|,
name|error
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|QEglFSWindow
operator|::
name|destroy
parameter_list|()
block|{
if|if
condition|(
name|m_surface
condition|)
block|{
name|EGLDisplay
name|display
init|=
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|()
argument_list|)
operator|->
name|display
argument_list|()
decl_stmt|;
name|eglDestroySurface
argument_list|(
name|display
argument_list|,
name|m_surface
argument_list|)
expr_stmt|;
name|m_surface
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|m_window
condition|)
block|{
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|destroyNativeWindow
argument_list|(
name|m_window
argument_list|)
expr_stmt|;
name|m_window
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QEglFSWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
parameter_list|)
block|{
comment|// We only support full-screen windows
name|QRect
name|rect
argument_list|(
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
argument_list|)
decl_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|QRegion
argument_list|(
name|rect
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setWindowState
name|void
name|QEglFSWindow
operator|::
name|setWindowState
parameter_list|(
name|Qt
operator|::
name|WindowState
parameter_list|)
block|{
name|setGeometry
argument_list|(
name|QRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|winId
name|WId
name|QEglFSWindow
operator|::
name|winId
parameter_list|()
specifier|const
block|{
return|return
name|m_winid
return|;
block|}
end_function
begin_function
DECL|function|format
name|QSurfaceFormat
name|QEglFSWindow
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
