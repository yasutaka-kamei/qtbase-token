begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qkmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qkmsdevice.h"
end_include
begin_include
include|#
directive|include
file|"qkmscontext.h"
end_include
begin_include
include|#
directive|include
file|"qkmswindow.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QKmsContext
name|QKmsContext
operator|::
name|QKmsContext
parameter_list|(
name|QKmsDevice
modifier|*
name|device
parameter_list|)
member_init_list|:
name|QPlatformOpenGLContext
argument_list|()
member_init_list|,
name|m_device
argument_list|(
name|device
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|makeCurrent
name|bool
name|QKmsContext
operator|::
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|EGLDisplay
name|display
init|=
name|m_device
operator|->
name|eglDisplay
argument_list|()
decl_stmt|;
name|EGLContext
name|context
init|=
name|m_device
operator|->
name|eglContext
argument_list|()
decl_stmt|;
name|bool
name|ok
init|=
name|eglMakeCurrent
argument_list|(
name|display
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|context
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"QKmsContext::makeCurrent(): eglError: %d, this: %p"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|QPlatformWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QPlatformWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|QKmsScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QKmsScreen
operator|*
argument_list|>
argument_list|(
name|QPlatformScreen
operator|::
name|platformScreenForWindow
argument_list|(
name|window
operator|->
name|window
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|screen
operator|->
name|bindFramebuffer
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QKmsContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|bool
name|ok
init|=
name|eglMakeCurrent
argument_list|(
name|m_device
operator|->
name|eglDisplay
argument_list|()
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
literal|"QKmsContext::doneCurrent(): eglError: %d, this: %p"
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
name|QKmsContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
comment|//After flush, the current render target should be moved to
comment|//latest complete
name|glFlush
argument_list|()
expr_stmt|;
comment|//Cast context to a window surface and get the screen the context
comment|//is on and call swapBuffers on that screen.
name|QPlatformWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QPlatformWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|QKmsScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QKmsScreen
operator|*
argument_list|>
argument_list|(
name|QPlatformScreen
operator|::
name|platformScreenForWindow
argument_list|(
name|window
operator|->
name|window
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|screen
operator|->
name|swapBuffers
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
DECL|function|getProcAddress
name|void
argument_list|(
argument|*QKmsContext::getProcAddress(const QByteArray&procName)
argument_list|)
end_macro
begin_expr_stmt
DECL|function|getProcAddress
operator|(
operator|)
block|{
return|return
name|eglGetProcAddress
argument_list|(
name|procName
operator|.
name|data
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|eglContext
name|EGLContext
name|QKmsContext
operator|::
name|eglContext
parameter_list|()
specifier|const
block|{
return|return
name|m_device
operator|->
name|eglContext
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|format
name|QSurfaceFormat
name|QKmsContext
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
begin_function
DECL|function|defaultFramebufferObject
name|GLuint
name|QKmsContext
operator|::
name|defaultFramebufferObject
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
specifier|const
block|{
name|QPlatformWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QPlatformWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|QKmsScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QKmsScreen
operator|*
argument_list|>
argument_list|(
name|QPlatformScreen
operator|::
name|platformScreenForWindow
argument_list|(
name|window
operator|->
name|window
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|screen
operator|->
name|framebufferObject
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
