begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Canonical, Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmirclientglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientwindow.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientlogging.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<dlfcn.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
end_if
begin_function
DECL|function|printOpenGLESConfig
specifier|static
name|void
name|printOpenGLESConfig
parameter_list|()
block|{
specifier|static
name|bool
name|once
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|once
condition|)
block|{
specifier|const
name|char
modifier|*
name|string
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
name|LOG
argument_list|(
literal|"OpenGL ES vendor: %s"
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|string
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
name|LOG
argument_list|(
literal|"OpenGL ES renderer: %s"
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|string
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
name|LOG
argument_list|(
literal|"OpenGL ES version: %s"
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|string
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
name|LOG
argument_list|(
literal|"OpenGL ES Shading Language version: %s"
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|string
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
name|LOG
argument_list|(
literal|"OpenGL ES extensions: %s"
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|once
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|api_in_use
specifier|static
name|EGLenum
name|api_in_use
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QTUBUNTU_USE_OPENGL
return|return
name|EGL_OPENGL_API
return|;
else|#
directive|else
return|return
name|EGL_OPENGL_ES_API
return|;
endif|#
directive|endif
block|}
end_function
begin_constructor
DECL|function|QMirClientOpenGLContext
name|QMirClientOpenGLContext
operator|::
name|QMirClientOpenGLContext
parameter_list|(
name|QMirClientScreen
modifier|*
name|screen
parameter_list|,
name|QMirClientOpenGLContext
modifier|*
name|share
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|screen
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|mEglDisplay
operator|=
name|screen
operator|->
name|eglDisplay
argument_list|()
expr_stmt|;
name|mScreen
operator|=
name|screen
expr_stmt|;
comment|// Create an OpenGL ES 2 context.
name|QVector
argument_list|<
name|EGLint
argument_list|>
name|attribs
decl_stmt|;
name|attribs
operator|.
name|append
argument_list|(
name|EGL_CONTEXT_CLIENT_VERSION
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|append
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|eglBindAPI
argument_list|(
name|api_in_use
argument_list|()
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
name|mEglContext
operator|=
name|eglCreateContext
argument_list|(
name|mEglDisplay
argument_list|,
name|screen
operator|->
name|eglConfig
argument_list|()
argument_list|,
name|share
condition|?
name|share
operator|->
name|eglContext
argument_list|()
else|:
name|EGL_NO_CONTEXT
argument_list|,
name|attribs
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|DASSERT
argument_list|(
name|mEglContext
operator|!=
name|EGL_NO_CONTEXT
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QMirClientOpenGLContext
name|QMirClientOpenGLContext
operator|::
name|~
name|QMirClientOpenGLContext
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|eglDestroyContext
argument_list|(
name|mEglDisplay
argument_list|,
name|mEglContext
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|makeCurrent
name|bool
name|QMirClientOpenGLContext
operator|::
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|DASSERT
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
name|EGLSurface
name|eglSurface
init|=
cast|static_cast
argument_list|<
name|QMirClientWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|eglSurface
argument_list|()
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
name|eglBindAPI
argument_list|(
name|api_in_use
argument_list|()
argument_list|)
expr_stmt|;
name|eglMakeCurrent
argument_list|(
name|mEglDisplay
argument_list|,
name|eglSurface
argument_list|,
name|eglSurface
argument_list|,
name|mEglContext
argument_list|)
expr_stmt|;
else|#
directive|else
name|ASSERT
argument_list|(
name|eglBindAPI
argument_list|(
name|api_in_use
argument_list|()
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|eglMakeCurrent
argument_list|(
name|mEglDisplay
argument_list|,
name|eglSurface
argument_list|,
name|eglSurface
argument_list|,
name|mEglContext
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
name|printOpenGLESConfig
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// When running on the emulator, shaders will be compiled using a thin wrapper around the desktop drivers.
comment|// These wrappers might not support the precision qualifiers, so set the workaround flag to true.
specifier|const
name|char
modifier|*
name|rendererString
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|glGetString
argument_list|(
name|GL_RENDERER
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|rendererString
operator|!=
literal|0
operator|&&
name|qstrncmp
argument_list|(
name|rendererString
argument_list|,
literal|"Android Emulator"
argument_list|,
literal|16
argument_list|)
operator|==
literal|0
condition|)
block|{
name|QOpenGLContextPrivate
modifier|*
name|ctx_d
init|=
name|QOpenGLContextPrivate
operator|::
name|get
argument_list|(
name|context
argument_list|()
argument_list|)
decl_stmt|;
name|ctx_d
operator|->
name|workaround_missingPrecisionQualifiers
operator|=
literal|true
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QMirClientOpenGLContext
operator|::
name|doneCurrent
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
name|eglBindAPI
argument_list|(
name|api_in_use
argument_list|()
argument_list|)
expr_stmt|;
name|eglMakeCurrent
argument_list|(
name|mEglDisplay
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
expr_stmt|;
else|#
directive|else
name|ASSERT
argument_list|(
name|eglBindAPI
argument_list|(
name|api_in_use
argument_list|()
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|eglMakeCurrent
argument_list|(
name|mEglDisplay
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QMirClientOpenGLContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|QMirClientWindow
modifier|*
name|ubuntuWindow
init|=
cast|static_cast
argument_list|<
name|QMirClientWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|EGLSurface
name|eglSurface
init|=
name|ubuntuWindow
operator|->
name|eglSurface
argument_list|()
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
name|eglBindAPI
argument_list|(
name|api_in_use
argument_list|()
argument_list|)
expr_stmt|;
name|eglSwapBuffers
argument_list|(
name|mEglDisplay
argument_list|,
name|eglSurface
argument_list|)
expr_stmt|;
else|#
directive|else
name|ASSERT
argument_list|(
name|eglBindAPI
argument_list|(
name|api_in_use
argument_list|()
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|eglSwapBuffers
argument_list|(
name|mEglDisplay
argument_list|,
name|eglSurface
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ubuntuWindow
operator|->
name|onSwapBuffersDone
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getProcAddress
name|QFunctionPointer
name|QMirClientOpenGLContext
operator|::
name|getProcAddress
parameter_list|(
specifier|const
name|char
modifier|*
name|procName
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
name|eglBindAPI
argument_list|(
name|api_in_use
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|ASSERT
argument_list|(
name|eglBindAPI
argument_list|(
name|api_in_use
argument_list|()
argument_list|)
operator|==
name|EGL_TRUE
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QFunctionPointer
name|proc
init|=
operator|(
name|QFunctionPointer
operator|)
name|eglGetProcAddress
argument_list|(
name|procName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|proc
condition|)
name|proc
operator|=
operator|(
name|QFunctionPointer
operator|)
name|dlsym
argument_list|(
name|RTLD_DEFAULT
argument_list|,
name|procName
argument_list|)
expr_stmt|;
return|return
name|proc
return|;
block|}
end_function
end_unit
