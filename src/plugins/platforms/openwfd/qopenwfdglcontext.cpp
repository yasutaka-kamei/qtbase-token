begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenwfdglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdwindow.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdscreen.h"
end_include
begin_constructor
DECL|function|QOpenWFDGLContext
name|QOpenWFDGLContext
operator|::
name|QOpenWFDGLContext
parameter_list|(
name|QOpenWFDDevice
modifier|*
name|device
parameter_list|)
member_init_list|:
name|QPlatformOpenGLContext
argument_list|()
member_init_list|,
name|mWfdDevice
argument_list|(
name|device
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|format
name|QSurfaceFormat
name|QOpenWFDGLContext
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
DECL|function|makeCurrent
name|bool
name|QOpenWFDGLContext
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
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
name|EGLDisplay
name|display
init|=
name|mWfdDevice
operator|->
name|eglDisplay
argument_list|()
decl_stmt|;
name|EGLContext
name|context
init|=
name|mWfdDevice
operator|->
name|eglContext
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
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
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"GLContext: eglMakeCurrent FAILED!"
expr_stmt|;
block|}
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
name|QOpenWFDScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QOpenWFDScreen
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
name|QOpenWFDGLContext
operator|::
name|doneCurrent
parameter_list|()
block|{
comment|//do nothing :)
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QOpenWFDGLContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|glFlush
argument_list|()
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
name|QOpenWFDScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QOpenWFDScreen
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
argument|*QOpenWFDGLContext::getProcAddress(const QByteArray&procName)
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
name|QOpenWFDGLContext
operator|::
name|eglContext
parameter_list|()
specifier|const
block|{
return|return
name|mWfdDevice
operator|->
name|eglContext
argument_list|()
return|;
block|}
end_function
end_unit
