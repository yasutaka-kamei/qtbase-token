begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglplatformcontext_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglconvenience_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QEGLPlatformContext     \brief An EGL context implementation.     \since 5.2     \internal     \ingroup qpa      Implement QPlatformOpenGLContext using EGL. To use it in platform     plugins a subclass must be created since     eglSurfaceForPlatformSurface() has to be reimplemented. This     function is used for mapping platform surfaces (windows) to EGL     surfaces and is necessary since different platform plugins may     have different ways of handling native windows (for example, a     plugin may choose not to back every platform window by a real EGL     surface). Other than that, no further customization is necessary.  */
DECL|function|bindApi
specifier|static
specifier|inline
name|void
name|bindApi
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
switch|switch
condition|(
name|format
operator|.
name|renderableType
argument_list|()
condition|)
block|{
case|case
name|QSurfaceFormat
operator|::
name|OpenVG
case|:
name|eglBindAPI
argument_list|(
name|EGL_OPENVG_API
argument_list|)
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|EGL_VERSION_1_4
case|case
name|QSurfaceFormat
operator|::
name|DefaultRenderableType
case|:
if|if
condition|(
operator|!
name|QOpenGLFunctions
operator|::
name|isES
argument_list|()
condition|)
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_API
argument_list|)
expr_stmt|;
else|else
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
break|break;
case|case
name|QSurfaceFormat
operator|::
name|OpenGL
case|:
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_API
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|QSurfaceFormat
operator|::
name|OpenGLES
case|:
default|default:
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_constructor
DECL|function|QEGLPlatformContext
name|QEGLPlatformContext
operator|::
name|QEGLPlatformContext
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
parameter_list|)
member_init_list|:
name|m_eglDisplay
argument_list|(
name|display
argument_list|)
member_init_list|,
name|m_eglConfig
argument_list|(
name|q_configFromGLFormat
argument_list|(
name|display
argument_list|,
name|format
argument_list|)
argument_list|)
member_init_list|,
name|m_swapInterval
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_swapIntervalEnvChecked
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_swapIntervalFromEnv
argument_list|(
operator|-
literal|1
argument_list|)
block|{
name|init
argument_list|(
name|format
argument_list|,
name|share
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|eglApi
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QEGLPlatformContext
name|QEGLPlatformContext
operator|::
name|QEGLPlatformContext
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
name|EGLConfig
name|config
parameter_list|,
name|EGLenum
name|eglApi
parameter_list|)
member_init_list|:
name|m_eglDisplay
argument_list|(
name|display
argument_list|)
member_init_list|,
name|m_eglConfig
argument_list|(
name|config
argument_list|)
member_init_list|,
name|m_swapInterval
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_swapIntervalEnvChecked
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_swapIntervalFromEnv
argument_list|(
operator|-
literal|1
argument_list|)
block|{
name|init
argument_list|(
name|format
argument_list|,
name|share
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|eglApi
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|init
name|void
name|QEGLPlatformContext
operator|::
name|init
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|)
block|{
name|m_format
operator|=
name|q_glFormatFromConfig
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|)
expr_stmt|;
name|m_shareContext
operator|=
name|share
condition|?
cast|static_cast
argument_list|<
name|QEGLPlatformContext
operator|*
argument_list|>
argument_list|(
name|share
argument_list|)
operator|->
name|m_eglContext
else|:
literal|0
expr_stmt|;
name|QVector
argument_list|<
name|EGLint
argument_list|>
name|contextAttrs
decl_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|EGL_CONTEXT_CLIENT_VERSION
argument_list|)
expr_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|format
operator|.
name|majorVersion
argument_list|()
argument_list|)
expr_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
name|bindApi
argument_list|(
name|m_format
argument_list|)
expr_stmt|;
name|m_eglContext
operator|=
name|eglCreateContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|,
name|m_shareContext
argument_list|,
name|contextAttrs
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglContext
operator|==
name|EGL_NO_CONTEXT
operator|&&
name|m_shareContext
operator|!=
name|EGL_NO_CONTEXT
condition|)
block|{
name|m_shareContext
operator|=
literal|0
expr_stmt|;
name|m_eglContext
operator|=
name|eglCreateContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|,
literal|0
argument_list|,
name|contextAttrs
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|makeCurrent
name|bool
name|QEGLPlatformContext
operator|::
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|supportsOpenGL
argument_list|()
argument_list|)
expr_stmt|;
name|bindApi
argument_list|(
name|m_format
argument_list|)
expr_stmt|;
name|EGLSurface
name|eglSurface
init|=
name|eglSurfaceForPlatformSurface
argument_list|(
name|surface
argument_list|)
decl_stmt|;
comment|// shortcut: on some GPUs, eglMakeCurrent is not a cheap operation
if|if
condition|(
name|eglGetCurrentContext
argument_list|()
operator|==
name|m_eglContext
operator|&&
name|eglGetCurrentDisplay
argument_list|()
operator|==
name|m_eglDisplay
operator|&&
name|eglGetCurrentSurface
argument_list|(
name|EGL_READ
argument_list|)
operator|==
name|eglSurface
operator|&&
name|eglGetCurrentSurface
argument_list|(
name|EGL_DRAW
argument_list|)
operator|==
name|eglSurface
condition|)
block|{
return|return
literal|true
return|;
block|}
name|bool
name|ok
init|=
name|eglMakeCurrent
argument_list|(
name|m_eglDisplay
argument_list|,
name|eglSurface
argument_list|,
name|eglSurface
argument_list|,
name|m_eglContext
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"QEGLPlatformContext::makeCurrent: eglError: %x, this: %p \n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
specifier|static
name|bool
name|showDebug
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|showDebug
condition|)
block|{
name|showDebug
operator|=
literal|false
expr_stmt|;
specifier|const
name|char
modifier|*
name|str
init|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_VENDOR
argument_list|)
decl_stmt|;
name|qWarning
argument_list|(
literal|"Vendor %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|str
operator|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_RENDERER
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Renderer %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|str
operator|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_VERSION
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Version %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|str
operator|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_SHADING_LANGUAGE_VERSION
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Extensions %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|str
operator|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_EXTENSIONS
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Extensions %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|ok
condition|)
block|{
if|if
condition|(
operator|!
name|m_swapIntervalEnvChecked
condition|)
block|{
name|m_swapIntervalEnvChecked
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QT_QPA_EGLFS_SWAPINTERVAL"
argument_list|)
condition|)
block|{
name|QByteArray
name|swapIntervalString
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_SWAPINTERVAL"
argument_list|)
decl_stmt|;
name|bool
name|ok
decl_stmt|;
specifier|const
name|int
name|swapInterval
init|=
name|swapIntervalString
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
name|m_swapIntervalFromEnv
operator|=
name|swapInterval
expr_stmt|;
block|}
block|}
specifier|const
name|int
name|requestedSwapInterval
init|=
name|m_swapIntervalFromEnv
operator|>=
literal|0
condition|?
name|m_swapIntervalFromEnv
else|:
name|surface
operator|->
name|format
argument_list|()
operator|.
name|swapInterval
argument_list|()
decl_stmt|;
if|if
condition|(
name|requestedSwapInterval
operator|>=
literal|0
operator|&&
name|m_swapInterval
operator|!=
name|requestedSwapInterval
condition|)
block|{
name|m_swapInterval
operator|=
name|requestedSwapInterval
expr_stmt|;
name|eglSwapInterval
argument_list|(
name|eglDisplay
argument_list|()
argument_list|,
name|m_swapInterval
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|ok
return|;
block|}
end_function
begin_destructor
DECL|function|~QEGLPlatformContext
name|QEGLPlatformContext
operator|::
name|~
name|QEGLPlatformContext
parameter_list|()
block|{
if|if
condition|(
name|m_eglContext
operator|!=
name|EGL_NO_CONTEXT
condition|)
block|{
name|eglDestroyContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglContext
argument_list|)
expr_stmt|;
name|m_eglContext
operator|=
name|EGL_NO_CONTEXT
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|doneCurrent
name|void
name|QEGLPlatformContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|bindApi
argument_list|(
name|m_format
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
name|eglMakeCurrent
argument_list|(
name|m_eglDisplay
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"QEGLPlatformContext::doneCurrent(): eglError: %d, this: %p \n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QEGLPlatformContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|bindApi
argument_list|(
name|m_format
argument_list|)
expr_stmt|;
name|EGLSurface
name|eglSurface
init|=
name|eglSurfaceForPlatformSurface
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|bool
name|ok
init|=
name|eglSwapBuffers
argument_list|(
name|m_eglDisplay
argument_list|,
name|eglSurface
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"QEGLPlatformContext::swapBuffers(): eglError: %d, this: %p \n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
DECL|function|getProcAddress
name|void
argument_list|(
argument|*QEGLPlatformContext::getProcAddress(const QByteArray&procName)
argument_list|)
end_macro
begin_expr_stmt
DECL|function|getProcAddress
operator|(
operator|)
block|{
name|bindApi
argument_list|(
name|m_format
argument_list|)
block|;
return|return
name|eglGetProcAddress
argument_list|(
name|procName
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|format
name|QSurfaceFormat
name|QEGLPlatformContext
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
begin_function
DECL|function|eglContext
name|EGLContext
name|QEGLPlatformContext
operator|::
name|eglContext
parameter_list|()
specifier|const
block|{
return|return
name|m_eglContext
return|;
block|}
end_function
begin_function
DECL|function|eglDisplay
name|EGLDisplay
name|QEGLPlatformContext
operator|::
name|eglDisplay
parameter_list|()
specifier|const
block|{
return|return
name|m_eglDisplay
return|;
block|}
end_function
begin_function
DECL|function|eglConfig
name|EGLConfig
name|QEGLPlatformContext
operator|::
name|eglConfig
parameter_list|()
specifier|const
block|{
return|return
name|m_eglConfig
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
