begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 - 2014 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxeglwindow.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|"qqnxglcontext.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXEGLWINDOW_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qEglWindowDebug
define|#
directive|define
name|qEglWindowDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qEglWindowDebug
define|#
directive|define
name|qEglWindowDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxEglWindow
name|QQnxEglWindow
operator|::
name|QQnxEglWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|screen_context_t
name|context
parameter_list|,
name|bool
name|needRootWindow
parameter_list|)
member_init_list|:
name|QQnxWindow
argument_list|(
name|window
argument_list|,
name|context
argument_list|,
name|needRootWindow
argument_list|)
member_init_list|,
name|m_platformOpenGLContext
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_newSurfaceRequested
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|m_eglSurface
argument_list|(
name|EGL_NO_SURFACE
argument_list|)
block|{
name|initWindow
argument_list|()
expr_stmt|;
comment|// Set window usage
specifier|const
name|int
name|val
init|=
name|SCREEN_USAGE_OPENGL_ES2
decl_stmt|;
specifier|const
name|int
name|result
init|=
name|screen_set_window_property_iv
argument_list|(
name|nativeHandle
argument_list|()
argument_list|,
name|SCREEN_PROPERTY_USAGE
argument_list|,
operator|&
name|val
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
name|qFatal
argument_list|(
literal|"QQnxEglWindow: failed to set window alpha usage, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|m_requestedBufferSize
operator|=
name|shouldMakeFullScreen
argument_list|()
condition|?
name|screen
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
else|:
name|window
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxEglWindow
name|QQnxEglWindow
operator|::
name|~
name|QQnxEglWindow
parameter_list|()
block|{
comment|// Cleanup EGL surface if it exists
name|destroyEGLSurface
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|createEGLSurface
name|void
name|QQnxEglWindow
operator|::
name|createEGLSurface
parameter_list|()
block|{
comment|// Fetch the surface size from the window and update
comment|// the window's buffers before we create the EGL surface
specifier|const
name|QSize
name|surfaceSize
init|=
name|requestedBufferSize
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|surfaceSize
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QQNX: Trying to create 0 size EGL surface. "
literal|"Please set a valid window size before calling QOpenGLContext::makeCurrent()"
argument_list|)
expr_stmt|;
return|return;
block|}
name|setBufferSize
argument_list|(
name|surfaceSize
argument_list|)
expr_stmt|;
specifier|const
name|EGLint
name|eglSurfaceAttrs
index|[]
init|=
block|{
name|EGL_RENDER_BUFFER
block|,
name|EGL_BACK_BUFFER
block|,
name|EGL_NONE
block|}
decl_stmt|;
name|qEglWindowDebug
argument_list|()
operator|<<
literal|"Creating EGL surface"
operator|<<
name|platformOpenGLContext
argument_list|()
operator|->
name|getEglDisplay
argument_list|()
operator|<<
name|platformOpenGLContext
argument_list|()
operator|->
name|getEglConfig
argument_list|()
expr_stmt|;
comment|// Create EGL surface
name|m_eglSurface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|platformOpenGLContext
argument_list|()
operator|->
name|getEglDisplay
argument_list|()
argument_list|,
name|platformOpenGLContext
argument_list|()
operator|->
name|getEglConfig
argument_list|()
argument_list|,
operator|(
name|EGLNativeWindowType
operator|)
name|nativeHandle
argument_list|()
argument_list|,
name|eglSurfaceAttrs
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglSurface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
specifier|const
name|EGLenum
name|error
init|=
name|QQnxGLContext
operator|::
name|checkEGLError
argument_list|(
literal|"eglCreateWindowSurface"
argument_list|)
decl_stmt|;
name|qWarning
argument_list|(
literal|"QQNX: failed to create EGL surface, err=%d"
argument_list|,
name|error
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|destroyEGLSurface
name|void
name|QQnxEglWindow
operator|::
name|destroyEGLSurface
parameter_list|()
block|{
comment|// Destroy EGL surface if it exists
if|if
condition|(
name|m_eglSurface
operator|!=
name|EGL_NO_SURFACE
condition|)
block|{
name|EGLBoolean
name|eglResult
init|=
name|eglDestroySurface
argument_list|(
name|platformOpenGLContext
argument_list|()
operator|->
name|getEglDisplay
argument_list|()
argument_list|,
name|m_eglSurface
argument_list|)
decl_stmt|;
if|if
condition|(
name|eglResult
operator|!=
name|EGL_TRUE
condition|)
name|qFatal
argument_list|(
literal|"QQNX: failed to destroy EGL surface, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|m_eglSurface
operator|=
name|EGL_NO_SURFACE
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapEGLBuffers
name|void
name|QQnxEglWindow
operator|::
name|swapEGLBuffers
parameter_list|()
block|{
name|qEglWindowDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Set current rendering API
name|EGLBoolean
name|eglResult
init|=
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
decl_stmt|;
if|if
condition|(
name|eglResult
operator|!=
name|EGL_TRUE
condition|)
name|qFatal
argument_list|(
literal|"QQNX: failed to set EGL API, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
comment|// Post EGL surface to window
name|eglResult
operator|=
name|eglSwapBuffers
argument_list|(
name|m_platformOpenGLContext
operator|->
name|getEglDisplay
argument_list|()
argument_list|,
name|m_eglSurface
argument_list|)
expr_stmt|;
if|if
condition|(
name|eglResult
operator|!=
name|EGL_TRUE
condition|)
name|qFatal
argument_list|(
literal|"QQNX: failed to swap EGL buffers, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
name|windowPosted
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getSurface
name|EGLSurface
name|QQnxEglWindow
operator|::
name|getSurface
parameter_list|()
block|{
if|if
condition|(
name|m_newSurfaceRequested
operator|.
name|testAndSetOrdered
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|)
condition|)
block|{
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
comment|//Set geomety must not reset the requestedBufferSize till
comment|//the surface is created
if|if
condition|(
name|m_eglSurface
operator|!=
name|EGL_NO_SURFACE
condition|)
block|{
name|platformOpenGLContext
argument_list|()
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
name|destroyEGLSurface
argument_list|()
expr_stmt|;
block|}
name|createEGLSurface
argument_list|()
expr_stmt|;
block|}
return|return
name|m_eglSurface
return|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QQnxEglWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
comment|//If this is the root window, it has to be shown fullscreen
specifier|const
name|QRect
modifier|&
name|newGeometry
init|=
name|shouldMakeFullScreen
argument_list|()
condition|?
name|screen
argument_list|()
operator|->
name|geometry
argument_list|()
else|:
name|rect
decl_stmt|;
comment|//We need to request that the GL context updates
comment|// the EGLsurface on which it is rendering.
block|{
comment|// We want the setting of the atomic bool in the GL context to be atomic with
comment|// setting m_requestedBufferSize and therefore extended the scope to include
comment|// that test.
specifier|const
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|m_mutex
argument_list|)
decl_stmt|;
name|m_requestedBufferSize
operator|=
name|newGeometry
operator|.
name|size
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_platformOpenGLContext
operator|!=
literal|0
operator|&&
name|bufferSize
argument_list|()
operator|!=
name|newGeometry
operator|.
name|size
argument_list|()
condition|)
name|m_newSurfaceRequested
operator|.
name|testAndSetRelease
argument_list|(
literal|false
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
name|QQnxWindow
operator|::
name|setGeometry
argument_list|(
name|newGeometry
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|requestedBufferSize
name|QSize
name|QQnxEglWindow
operator|::
name|requestedBufferSize
parameter_list|()
specifier|const
block|{
return|return
name|m_requestedBufferSize
return|;
block|}
end_function
begin_function
DECL|function|setPlatformOpenGLContext
name|void
name|QQnxEglWindow
operator|::
name|setPlatformOpenGLContext
parameter_list|(
name|QQnxGLContext
modifier|*
name|platformOpenGLContext
parameter_list|)
block|{
comment|// This function does not take ownership of the platform gl context.
comment|// It is owned by the frontend QOpenGLContext
name|m_platformOpenGLContext
operator|=
name|platformOpenGLContext
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pixelFormat
name|int
name|QQnxEglWindow
operator|::
name|pixelFormat
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_platformOpenGLContext
condition|)
comment|//The platform GL context was not set yet
return|return
operator|-
literal|1
return|;
specifier|const
name|QSurfaceFormat
name|format
init|=
name|m_platformOpenGLContext
operator|->
name|format
argument_list|()
decl_stmt|;
comment|// Extract size of color channels from window format
specifier|const
name|int
name|redSize
init|=
name|format
operator|.
name|redBufferSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|redSize
operator|==
operator|-
literal|1
condition|)
name|qFatal
argument_list|(
literal|"QQnxWindow: red size not defined"
argument_list|)
expr_stmt|;
specifier|const
name|int
name|greenSize
init|=
name|format
operator|.
name|greenBufferSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|greenSize
operator|==
operator|-
literal|1
condition|)
name|qFatal
argument_list|(
literal|"QQnxWindow: green size not defined"
argument_list|)
expr_stmt|;
specifier|const
name|int
name|blueSize
init|=
name|format
operator|.
name|blueBufferSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|blueSize
operator|==
operator|-
literal|1
condition|)
name|qFatal
argument_list|(
literal|"QQnxWindow: blue size not defined"
argument_list|)
expr_stmt|;
comment|// select matching native format
if|if
condition|(
name|redSize
operator|==
literal|5
operator|&&
name|greenSize
operator|==
literal|6
operator|&&
name|blueSize
operator|==
literal|5
condition|)
return|return
name|SCREEN_FORMAT_RGB565
return|;
elseif|else
if|if
condition|(
name|redSize
operator|==
literal|8
operator|&&
name|greenSize
operator|==
literal|8
operator|&&
name|blueSize
operator|==
literal|8
condition|)
return|return
name|SCREEN_FORMAT_RGBA8888
return|;
name|qFatal
argument_list|(
literal|"QQnxWindow: unsupported pixel format"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resetBuffers
name|void
name|QQnxEglWindow
operator|::
name|resetBuffers
parameter_list|()
block|{
name|m_requestedBufferSize
operator|=
name|QSize
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
