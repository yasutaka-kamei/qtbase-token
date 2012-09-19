begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qminimaleglscreen.h"
end_include
begin_include
include|#
directive|include
file|"qminimaleglwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformcontext_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OPENKODE
end_ifdef
begin_include
include|#
directive|include
file|<KD/kd.h>
end_include
begin_include
include|#
directive|include
file|<KD/NV_initialize.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_OPENKODE
end_comment
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// #define QEGL_EXTRA_DEBUG
end_comment
begin_class
DECL|class|QMinimalEglContext
class|class
name|QMinimalEglContext
super|:
specifier|public
name|QEGLPlatformContext
block|{
public|public:
DECL|function|QMinimalEglContext
name|QMinimalEglContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|,
name|EGLDisplay
name|display
parameter_list|,
name|EGLenum
name|eglApi
init|=
name|EGL_OPENGL_ES_API
parameter_list|)
member_init_list|:
name|QEGLPlatformContext
argument_list|(
name|format
argument_list|,
name|share
argument_list|,
name|display
argument_list|,
name|eglApi
argument_list|)
block|{     }
DECL|function|eglSurfaceForPlatformSurface
name|EGLSurface
name|eglSurfaceForPlatformSurface
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|QMinimalEglWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QMinimalEglWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|QMinimalEglScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QMinimalEglScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|screen
operator|->
name|surface
argument_list|()
return|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|QMinimalEglScreen
name|QMinimalEglScreen
operator|::
name|QMinimalEglScreen
parameter_list|(
name|EGLNativeDisplayType
name|display
parameter_list|)
member_init_list|:
name|m_depth
argument_list|(
literal|32
argument_list|)
member_init_list|,
name|m_format
argument_list|(
name|QImage
operator|::
name|Format_Invalid
argument_list|)
member_init_list|,
name|m_platformContext
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_surface
argument_list|(
literal|0
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglScreen %p\n"
argument_list|,
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|EGLint
name|major
decl_stmt|,
name|minor
decl_stmt|;
if|if
condition|(
operator|!
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not bind GL_ES API\n"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL error"
argument_list|)
expr_stmt|;
block|}
name|m_dpy
operator|=
name|eglGetDisplay
argument_list|(
name|display
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_dpy
operator|==
name|EGL_NO_DISPLAY
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not open egl display\n"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL error"
argument_list|)
expr_stmt|;
block|}
name|qWarning
argument_list|(
literal|"Opened display %p\n"
argument_list|,
name|m_dpy
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|eglInitialize
argument_list|(
name|m_dpy
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not initialize egl display\n"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL error"
argument_list|)
expr_stmt|;
block|}
name|qWarning
argument_list|(
literal|"Initialized display %d %d\n"
argument_list|,
name|major
argument_list|,
name|minor
argument_list|)
expr_stmt|;
name|int
name|swapInterval
init|=
literal|1
decl_stmt|;
name|QByteArray
name|swapIntervalString
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_SWAPINTERVAL"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|swapIntervalString
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|swapInterval
operator|=
name|swapIntervalString
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|swapInterval
operator|=
literal|1
expr_stmt|;
block|}
name|eglSwapInterval
argument_list|(
name|m_dpy
argument_list|,
name|swapInterval
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QMinimalEglScreen
name|QMinimalEglScreen
operator|::
name|~
name|QMinimalEglScreen
parameter_list|()
block|{
if|if
condition|(
name|m_surface
condition|)
name|eglDestroySurface
argument_list|(
name|m_dpy
argument_list|,
name|m_surface
argument_list|)
expr_stmt|;
name|eglTerminate
argument_list|(
name|m_dpy
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|createAndSetPlatformContext
name|void
name|QMinimalEglScreen
operator|::
name|createAndSetPlatformContext
parameter_list|()
specifier|const
block|{
cast|const_cast
argument_list|<
name|QMinimalEglScreen
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|createAndSetPlatformContext
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createAndSetPlatformContext
name|void
name|QMinimalEglScreen
operator|::
name|createAndSetPlatformContext
parameter_list|()
block|{
name|QSurfaceFormat
name|platformFormat
decl_stmt|;
name|QByteArray
name|depthString
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_DEPTH"
argument_list|)
decl_stmt|;
if|if
condition|(
name|depthString
operator|.
name|toInt
argument_list|()
operator|==
literal|16
condition|)
block|{
name|platformFormat
operator|.
name|setDepthBufferSize
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setRedBufferSize
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setGreenBufferSize
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setBlueBufferSize
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|m_depth
operator|=
literal|16
expr_stmt|;
name|m_format
operator|=
name|QImage
operator|::
name|Format_RGB16
expr_stmt|;
block|}
else|else
block|{
name|platformFormat
operator|.
name|setDepthBufferSize
argument_list|(
literal|24
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setStencilBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setRedBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setGreenBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setBlueBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|m_depth
operator|=
literal|32
expr_stmt|;
name|m_format
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|qEnvironmentVariableIsEmpty
argument_list|(
literal|"QT_QPA_EGLFS_MULTISAMPLE"
argument_list|)
condition|)
name|platformFormat
operator|.
name|setSamples
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|EGLConfig
name|config
init|=
name|q_configFromGLFormat
argument_list|(
name|m_dpy
argument_list|,
name|platformFormat
argument_list|)
decl_stmt|;
name|EGLNativeWindowType
name|eglWindow
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OPENKODE
if|if
condition|(
name|kdInitializeNV
argument_list|()
operator|==
name|KD_ENOTINITIALIZED
condition|)
block|{
name|qFatal
argument_list|(
literal|"Did not manage to initialize openkode"
argument_list|)
expr_stmt|;
block|}
name|KDWindow
modifier|*
name|window
init|=
name|kdCreateWindow
argument_list|(
name|m_dpy
argument_list|,
name|config
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|kdRealizeWindow
argument_list|(
name|window
argument_list|,
operator|&
name|eglWindow
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|q_printEglConfig
argument_list|(
name|m_dpy
argument_list|,
name|config
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_surface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|m_dpy
argument_list|,
name|config
argument_list|,
name|eglWindow
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
name|qWarning
argument_list|(
literal|"Could not create the egl surface: error = 0x%x\n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
name|eglTerminate
argument_list|(
name|m_dpy
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL error"
argument_list|)
expr_stmt|;
block|}
comment|//    qWarning("Created surface %dx%d\n", w, h);
name|QEGLPlatformContext
modifier|*
name|platformContext
init|=
operator|new
name|QMinimalEglContext
argument_list|(
name|platformFormat
argument_list|,
literal|0
argument_list|,
name|m_dpy
argument_list|)
decl_stmt|;
name|m_platformContext
operator|=
name|platformContext
expr_stmt|;
name|EGLint
name|w
decl_stmt|,
name|h
decl_stmt|;
comment|// screen size detection
name|eglQuerySurface
argument_list|(
name|m_dpy
argument_list|,
name|m_surface
argument_list|,
name|EGL_WIDTH
argument_list|,
operator|&
name|w
argument_list|)
expr_stmt|;
name|eglQuerySurface
argument_list|(
name|m_dpy
argument_list|,
name|m_surface
argument_list|,
name|EGL_HEIGHT
argument_list|,
operator|&
name|h
argument_list|)
expr_stmt|;
name|m_geometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|geometry
name|QRect
name|QMinimalEglScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_geometry
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|createAndSetPlatformContext
argument_list|()
expr_stmt|;
block|}
return|return
name|m_geometry
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QMinimalEglScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|m_depth
return|;
block|}
end_function
begin_function
DECL|function|format
name|QImage
operator|::
name|Format
name|QMinimalEglScreen
operator|::
name|format
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_format
operator|==
name|QImage
operator|::
name|Format_Invalid
condition|)
name|createAndSetPlatformContext
argument_list|()
expr_stmt|;
return|return
name|m_format
return|;
block|}
end_function
begin_function
DECL|function|platformContext
name|QPlatformOpenGLContext
modifier|*
name|QMinimalEglScreen
operator|::
name|platformContext
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_platformContext
condition|)
block|{
name|QMinimalEglScreen
modifier|*
name|that
init|=
cast|const_cast
argument_list|<
name|QMinimalEglScreen
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|that
operator|->
name|createAndSetPlatformContext
argument_list|()
expr_stmt|;
block|}
return|return
name|m_platformContext
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
