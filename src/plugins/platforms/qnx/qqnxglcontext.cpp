begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qqnxrootwindow.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|"qqnxwindow.h"
end_include
begin_include
include|#
directive|include
file|"private/qeglconvenience_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QQNXGLCONTEXT_DEBUG
end_ifdef
begin_define
DECL|macro|qGLContextDebug
define|#
directive|define
name|qGLContextDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qGLContextDebug
define|#
directive|define
name|qGLContextDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|ms_eglDisplay
name|EGLDisplay
name|QQnxGLContext
operator|::
name|ms_eglDisplay
init|=
name|EGL_NO_DISPLAY
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|checkEGLError
specifier|static
name|EGLenum
name|checkEGLError
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
name|errmsg
index|[]
init|=
block|{
literal|"EGL function succeeded"
block|,
literal|"EGL is not initialized, or could not be initialized, for the specified display"
block|,
literal|"EGL cannot access a requested resource"
block|,
literal|"EGL failed to allocate resources for the requested operation"
block|,
literal|"EGL fail to access an unrecognized attribute or attribute value was passed in an attribute list"
block|,
literal|"EGLConfig argument does not name a valid EGLConfig"
block|,
literal|"EGLContext argument does not name a valid EGLContext"
block|,
literal|"EGL current surface of the calling thread is no longer valid"
block|,
literal|"EGLDisplay argument does not name a valid EGLDisplay"
block|,
literal|"EGL arguments are inconsistent"
block|,
literal|"EGLNativePixmapType argument does not refer to a valid native pixmap"
block|,
literal|"EGLNativeWindowType argument does not refer to a valid native window"
block|,
literal|"EGL one or more argument values are invalid"
block|,
literal|"EGLSurface argument does not name a valid surface configured for rendering"
block|,
literal|"EGL power management event has occurred"
block|,     }
decl_stmt|;
name|EGLenum
name|error
init|=
name|eglGetError
argument_list|()
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|msg
argument_list|,
name|errmsg
index|[
name|error
operator|-
name|EGL_SUCCESS
index|]
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_constructor
DECL|function|QQnxGLContext
name|QQnxGLContext
operator|::
name|QQnxGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|glContext
parameter_list|)
member_init_list|:
name|QPlatformOpenGLContext
argument_list|()
member_init_list|,
name|m_glContext
argument_list|(
name|glContext
argument_list|)
member_init_list|,
name|m_eglSurface
argument_list|(
name|EGL_NO_SURFACE
argument_list|)
block|{
name|qGLContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|QSurfaceFormat
name|format
init|=
name|m_glContext
operator|->
name|format
argument_list|()
decl_stmt|;
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
block|{
name|qFatal
argument_list|(
literal|"QQNX: failed to set EGL API, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Get colour channel sizes from window format
name|int
name|alphaSize
init|=
name|format
operator|.
name|alphaBufferSize
argument_list|()
decl_stmt|;
name|int
name|redSize
init|=
name|format
operator|.
name|redBufferSize
argument_list|()
decl_stmt|;
name|int
name|greenSize
init|=
name|format
operator|.
name|greenBufferSize
argument_list|()
decl_stmt|;
name|int
name|blueSize
init|=
name|format
operator|.
name|blueBufferSize
argument_list|()
decl_stmt|;
comment|// Check if all channels are don't care
if|if
condition|(
name|alphaSize
operator|==
operator|-
literal|1
operator|&&
name|redSize
operator|==
operator|-
literal|1
operator|&&
name|greenSize
operator|==
operator|-
literal|1
operator|&&
name|blueSize
operator|==
operator|-
literal|1
condition|)
block|{
comment|// Set colour channels based on depth of window's screen
name|QQnxScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QQnxScreen
operator|*
argument_list|>
argument_list|(
name|glContext
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|depth
init|=
name|screen
operator|->
name|depth
argument_list|()
decl_stmt|;
if|if
condition|(
name|depth
operator|==
literal|32
condition|)
block|{
comment|// SCREEN_FORMAT_RGBA8888
name|alphaSize
operator|=
literal|8
expr_stmt|;
name|redSize
operator|=
literal|8
expr_stmt|;
name|greenSize
operator|=
literal|8
expr_stmt|;
name|blueSize
operator|=
literal|8
expr_stmt|;
block|}
else|else
block|{
comment|// SCREEN_FORMAT_RGB565
name|alphaSize
operator|=
literal|0
expr_stmt|;
name|redSize
operator|=
literal|5
expr_stmt|;
name|greenSize
operator|=
literal|6
expr_stmt|;
name|blueSize
operator|=
literal|5
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// Choose best match based on supported pixel formats
if|if
condition|(
name|alphaSize
operator|<=
literal|0
operator|&&
name|redSize
operator|<=
literal|5
operator|&&
name|greenSize
operator|<=
literal|6
operator|&&
name|blueSize
operator|<=
literal|5
condition|)
block|{
comment|// SCREEN_FORMAT_RGB565
name|alphaSize
operator|=
literal|0
expr_stmt|;
name|redSize
operator|=
literal|5
expr_stmt|;
name|greenSize
operator|=
literal|6
expr_stmt|;
name|blueSize
operator|=
literal|5
expr_stmt|;
block|}
else|else
block|{
comment|// SCREEN_FORMAT_RGBA8888
name|alphaSize
operator|=
literal|8
expr_stmt|;
name|redSize
operator|=
literal|8
expr_stmt|;
name|greenSize
operator|=
literal|8
expr_stmt|;
name|blueSize
operator|=
literal|8
expr_stmt|;
block|}
block|}
comment|// Update colour channel sizes in window format
name|format
operator|.
name|setAlphaBufferSize
argument_list|(
name|alphaSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setRedBufferSize
argument_list|(
name|redSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setGreenBufferSize
argument_list|(
name|greenSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setBlueBufferSize
argument_list|(
name|blueSize
argument_list|)
expr_stmt|;
comment|// Select EGL config based on requested window format
name|m_eglConfig
operator|=
name|q_configFromGLFormat
argument_list|(
name|ms_eglDisplay
argument_list|,
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglConfig
operator|==
literal|0
condition|)
block|{
name|qFatal
argument_list|(
literal|"QQNXQBBWindow: failed to find EGL config"
argument_list|)
expr_stmt|;
block|}
name|m_eglContext
operator|=
name|eglCreateContext
argument_list|(
name|ms_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|,
name|EGL_NO_CONTEXT
argument_list|,
name|contextAttrs
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglContext
operator|==
name|EGL_NO_CONTEXT
condition|)
block|{
name|checkEGLError
argument_list|(
literal|"eglCreateContext"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"QQNXQBBWindow: failed to create EGL context, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Query/cache window format of selected EGL config
name|m_windowFormat
operator|=
name|q_glFormatFromConfig
argument_list|(
name|ms_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxGLContext
name|QQnxGLContext
operator|::
name|~
name|QQnxGLContext
parameter_list|()
block|{
name|qGLContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Cleanup EGL context if it exists
if|if
condition|(
name|m_eglContext
operator|!=
name|EGL_NO_CONTEXT
condition|)
block|{
name|eglDestroyContext
argument_list|(
name|ms_eglDisplay
argument_list|,
name|m_eglContext
argument_list|)
expr_stmt|;
block|}
comment|// Cleanup EGL surface if it exists
name|destroySurface
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initialize
name|void
name|QQnxGLContext
operator|::
name|initialize
parameter_list|()
block|{
name|qGLContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Initialize connection to EGL
name|ms_eglDisplay
operator|=
name|eglGetDisplay
argument_list|(
name|EGL_DEFAULT_DISPLAY
argument_list|)
expr_stmt|;
if|if
condition|(
name|ms_eglDisplay
operator|==
name|EGL_NO_DISPLAY
condition|)
block|{
name|checkEGLError
argument_list|(
literal|"eglGetDisplay"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"QQNXQBBWindow: failed to obtain EGL display"
argument_list|)
expr_stmt|;
block|}
name|EGLBoolean
name|eglResult
init|=
name|eglInitialize
argument_list|(
name|ms_eglDisplay
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|eglResult
operator|!=
name|EGL_TRUE
condition|)
block|{
name|checkEGLError
argument_list|(
literal|"eglInitialize"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"QQNXQBBWindow: failed to initialize EGL display, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|shutdown
name|void
name|QQnxGLContext
operator|::
name|shutdown
parameter_list|()
block|{
name|qGLContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Close connection to EGL
name|eglTerminate
argument_list|(
name|ms_eglDisplay
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeCurrent
name|bool
name|QQnxGLContext
operator|::
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|qGLContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|OpenGLSurface
argument_list|)
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
block|{
name|qFatal
argument_list|(
literal|"QQNXQBBWindow: failed to set EGL API, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_eglSurface
operator|==
name|EGL_NO_SURFACE
condition|)
name|createSurface
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|eglResult
operator|=
name|eglMakeCurrent
argument_list|(
name|ms_eglDisplay
argument_list|,
name|m_eglSurface
argument_list|,
name|m_eglSurface
argument_list|,
name|m_eglContext
argument_list|)
expr_stmt|;
if|if
condition|(
name|eglResult
operator|!=
name|EGL_TRUE
condition|)
block|{
name|checkEGLError
argument_list|(
literal|"eglMakeCurrent"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"QQNX: failed to set current EGL context, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|eglResult
operator|==
name|EGL_TRUE
operator|)
return|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QQnxGLContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|qGLContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// set current rendering API
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
block|{
name|qFatal
argument_list|(
literal|"QQNX: failed to set EGL API, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// clear curent EGL context and unbind EGL surface
name|eglResult
operator|=
name|eglMakeCurrent
argument_list|(
name|ms_eglDisplay
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
expr_stmt|;
if|if
condition|(
name|eglResult
operator|!=
name|EGL_TRUE
condition|)
block|{
name|qFatal
argument_list|(
literal|"QQNX: failed to clear current EGL context, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QQnxGLContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|qGLContextDebug
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
block|{
name|qFatal
argument_list|(
literal|"QQNX: failed to set EGL API, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Post EGL surface to window
name|eglResult
operator|=
name|eglSwapBuffers
argument_list|(
name|ms_eglDisplay
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
block|{
name|qFatal
argument_list|(
literal|"QQNX: failed to swap EGL buffers, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|getProcAddress
name|QFunctionPointer
name|QQnxGLContext
operator|::
name|getProcAddress
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|procName
parameter_list|)
block|{
name|qGLContextDebug
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
block|{
name|qFatal
argument_list|(
literal|"QQNX: failed to set EGL API, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Lookup EGL extension function pointer
return|return
cast|static_cast
argument_list|<
name|QFunctionPointer
argument_list|>
argument_list|(
name|eglGetProcAddress
argument_list|(
name|procName
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|contextAttrs
name|EGLint
modifier|*
name|QQnxGLContext
operator|::
name|contextAttrs
parameter_list|()
block|{
name|qGLContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Choose EGL settings based on OpenGL version
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
specifier|static
name|EGLint
name|attrs
index|[]
init|=
block|{
name|EGL_CONTEXT_CLIENT_VERSION
block|,
literal|2
block|,
name|EGL_NONE
block|}
decl_stmt|;
return|return
name|attrs
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|isCurrent
name|bool
name|QQnxGLContext
operator|::
name|isCurrent
parameter_list|()
specifier|const
block|{
name|qGLContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
operator|(
name|eglGetCurrentContext
argument_list|()
operator|==
name|m_eglContext
operator|)
return|;
block|}
end_function
begin_function
DECL|function|createSurface
name|void
name|QQnxGLContext
operator|::
name|createSurface
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|qGLContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Get a pointer to the corresponding platform window
name|QQnxWindow
modifier|*
name|platformWindow
init|=
cast|dynamic_cast
argument_list|<
name|QQnxWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|platformWindow
condition|)
block|{
name|qFatal
argument_list|(
literal|"QQNX: unable to create EGLSurface without a QQnxWindow"
argument_list|)
expr_stmt|;
block|}
comment|// If the platform window does not yet have any buffers, we create
comment|// a temporary set of buffers with a size of 1x1 pixels. This will
comment|// suffice until such time as the platform window has obtained
comment|// buffers of the proper size
if|if
condition|(
operator|!
name|platformWindow
operator|->
name|hasBuffers
argument_list|()
condition|)
block|{
name|platformWindow
operator|->
name|setPlatformOpenGLContext
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|platformWindow
operator|->
name|setBufferSize
argument_list|(
name|platformWindow
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Obtain the native handle for our window
name|screen_window_t
name|handle
init|=
name|platformWindow
operator|->
name|nativeHandle
argument_list|()
decl_stmt|;
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
comment|// Create EGL surface
name|m_eglSurface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|ms_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|,
operator|(
name|EGLNativeWindowType
operator|)
name|handle
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
name|checkEGLError
argument_list|(
literal|"eglCreateWindowSurface"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"QQNX: failed to create EGL surface, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|destroySurface
name|void
name|QQnxGLContext
operator|::
name|destroySurface
parameter_list|()
block|{
name|qGLContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
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
name|ms_eglDisplay
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
block|{
name|qFatal
argument_list|(
literal|"QQNX: failed to destroy EGL surface, err=%d"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|m_eglSurface
operator|=
name|EGL_NO_SURFACE
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
