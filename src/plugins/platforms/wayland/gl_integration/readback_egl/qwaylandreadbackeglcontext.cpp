begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandreadbackeglcontext.h"
end_include
begin_include
include|#
directive|include
file|"../../../eglconvenience/qeglconvenience.h"
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/QGLContext>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/private/qglextensions_p.h>
end_include
begin_include
include|#
directive|include
file|"qwaylandshmsurface.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_function
DECL|function|qgl_byteSwapImage
specifier|static
specifier|inline
name|void
name|qgl_byteSwapImage
parameter_list|(
name|QImage
modifier|&
name|img
parameter_list|,
name|GLenum
name|pixel_type
parameter_list|)
block|{
specifier|const
name|int
name|width
init|=
name|img
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|height
init|=
name|img
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|pixel_type
operator|==
name|GL_UNSIGNED_INT_8_8_8_8_REV
operator|||
operator|(
name|pixel_type
operator|==
name|GL_UNSIGNED_BYTE
operator|&&
name|QSysInfo
operator|::
name|ByteOrder
operator|==
name|QSysInfo
operator|::
name|LittleEndian
operator|)
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|height
condition|;
operator|++
name|i
control|)
block|{
name|uint
modifier|*
name|p
init|=
operator|(
name|uint
operator|*
operator|)
name|img
operator|.
name|scanLine
argument_list|(
name|i
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|width
condition|;
operator|++
name|x
control|)
name|p
index|[
name|x
index|]
operator|=
operator|(
operator|(
name|p
index|[
name|x
index|]
operator|<<
literal|16
operator|)
operator|&
literal|0xff0000
operator|)
operator||
operator|(
operator|(
name|p
index|[
name|x
index|]
operator|>>
literal|16
operator|)
operator|&
literal|0xff
operator|)
operator||
operator|(
name|p
index|[
name|x
index|]
operator|&
literal|0xff00ff00
operator|)
expr_stmt|;
block|}
block|}
else|else
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|height
condition|;
operator|++
name|i
control|)
block|{
name|uint
modifier|*
name|p
init|=
operator|(
name|uint
operator|*
operator|)
name|img
operator|.
name|scanLine
argument_list|(
name|i
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|width
condition|;
operator|++
name|x
control|)
name|p
index|[
name|x
index|]
operator|=
operator|(
name|p
index|[
name|x
index|]
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|p
index|[
name|x
index|]
operator|>>
literal|24
operator|)
operator|&
literal|0xff
operator|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_constructor
DECL|function|QWaylandReadbackEglContext
name|QWaylandReadbackEglContext
operator|::
name|QWaylandReadbackEglContext
parameter_list|(
name|QWaylandReadbackEglIntegration
modifier|*
name|eglIntegration
parameter_list|,
name|QWaylandReadbackEglWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|mEglIntegration
argument_list|(
name|eglIntegration
argument_list|)
member_init_list|,
name|mWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mBuffer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mPixmap
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mConfig
argument_list|(
name|q_configFromQPlatformWindowFormat
argument_list|(
name|eglIntegration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|window
operator|->
name|widget
argument_list|()
operator|->
name|platformWindowFormat
argument_list|()
argument_list|,
literal|true
argument_list|,
name|EGL_PIXMAP_BIT
argument_list|)
argument_list|)
member_init_list|,
name|mPixmapSurface
argument_list|(
name|EGL_NO_SURFACE
argument_list|)
block|{
name|QVector
argument_list|<
name|EGLint
argument_list|>
name|eglContextAttrs
decl_stmt|;
name|eglContextAttrs
operator|.
name|append
argument_list|(
name|EGL_CONTEXT_CLIENT_VERSION
argument_list|)
expr_stmt|;
name|eglContextAttrs
operator|.
name|append
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|eglContextAttrs
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
name|mContext
operator|=
name|eglCreateContext
argument_list|(
name|eglIntegration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|mConfig
argument_list|,
literal|0
argument_list|,
name|eglContextAttrs
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|geometryChanged
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandReadbackEglContext
name|QWaylandReadbackEglContext
operator|::
name|~
name|QWaylandReadbackEglContext
parameter_list|()
block|{
name|eglDestroyContext
argument_list|(
name|mEglIntegration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|mContext
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|makeCurrent
name|void
name|QWaylandReadbackEglContext
operator|::
name|makeCurrent
parameter_list|()
block|{
name|mWindow
operator|->
name|waitForFrameSync
argument_list|()
expr_stmt|;
name|eglMakeCurrent
argument_list|(
name|mEglIntegration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|mPixmapSurface
argument_list|,
name|mPixmapSurface
argument_list|,
name|mContext
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QWaylandReadbackEglContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|QPlatformGLContext
operator|::
name|doneCurrent
argument_list|()
expr_stmt|;
name|eglMakeCurrent
argument_list|(
name|mEglIntegration
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
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QWaylandReadbackEglContext
operator|::
name|swapBuffers
parameter_list|()
block|{
name|eglSwapBuffers
argument_list|(
name|mEglIntegration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|mPixmapSurface
argument_list|)
expr_stmt|;
if|if
condition|(
name|QWindowContext
operator|::
name|currentContext
argument_list|()
operator|.
name|handle
argument_list|()
operator|!=
name|this
condition|)
block|{
name|makeCurrent
argument_list|()
expr_stmt|;
block|}
name|QSize
name|size
init|=
name|mWindow
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
decl_stmt|;
name|QImage
name|img
argument_list|(
name|size
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|constBits
init|=
name|img
operator|.
name|bits
argument_list|()
decl_stmt|;
name|void
modifier|*
name|pixels
init|=
cast|const_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|constBits
argument_list|)
decl_stmt|;
name|glReadPixels
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|pixels
argument_list|)
expr_stmt|;
name|img
operator|=
name|img
operator|.
name|mirrored
argument_list|()
expr_stmt|;
name|qgl_byteSwapImage
argument_list|(
name|img
argument_list|,
name|GL_UNSIGNED_INT_8_8_8_8_REV
argument_list|)
expr_stmt|;
name|constBits
operator|=
name|img
operator|.
name|bits
argument_list|()
expr_stmt|;
specifier|const
name|uchar
modifier|*
name|constDstBits
init|=
name|mBuffer
operator|->
name|image
argument_list|()
operator|->
name|bits
argument_list|()
decl_stmt|;
name|uchar
modifier|*
name|dstBits
init|=
cast|const_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|constDstBits
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|dstBits
argument_list|,
name|constBits
argument_list|,
operator|(
name|img
operator|.
name|width
argument_list|()
operator|*
literal|4
operator|)
operator|*
name|img
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|mWindow
operator|->
name|damage
argument_list|(
name|QRegion
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getProcAddress
name|void
modifier|*
name|QWaylandReadbackEglContext
operator|::
name|getProcAddress
parameter_list|(
specifier|const
name|QString
modifier|&
name|procName
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|eglGetProcAddress
argument_list|(
name|procName
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|platformWindowFormat
name|QPlatformWindowFormat
name|QWaylandReadbackEglContext
operator|::
name|platformWindowFormat
parameter_list|()
specifier|const
block|{
return|return
name|q_windowFormatFromConfig
argument_list|(
name|mEglIntegration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|mConfig
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|geometryChanged
name|void
name|QWaylandReadbackEglContext
operator|::
name|geometryChanged
parameter_list|()
block|{
name|QSize
name|size
argument_list|(
name|mWindow
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|//QGLWidget wants a context for a window without geometry
name|size
operator|=
name|QSize
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|mWindow
operator|->
name|waitForFrameSync
argument_list|()
expr_stmt|;
operator|delete
name|mBuffer
expr_stmt|;
if|if
condition|(
name|mPixmap
condition|)
name|XFreePixmap
argument_list|(
name|mEglIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mPixmap
argument_list|)
expr_stmt|;
name|mBuffer
operator|=
operator|new
name|QWaylandShmBuffer
argument_list|(
name|mEglIntegration
operator|->
name|waylandDisplay
argument_list|()
argument_list|,
name|size
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
expr_stmt|;
name|mWindow
operator|->
name|attach
argument_list|(
name|mBuffer
argument_list|)
expr_stmt|;
name|mPixmap
operator|=
name|XCreatePixmap
argument_list|(
name|mEglIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|mEglIntegration
operator|->
name|rootWindow
argument_list|()
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
name|mEglIntegration
operator|->
name|depth
argument_list|()
argument_list|)
expr_stmt|;
name|XSync
argument_list|(
name|mEglIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|False
argument_list|)
expr_stmt|;
name|mPixmapSurface
operator|=
name|eglCreatePixmapSurface
argument_list|(
name|mEglIntegration
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|mConfig
argument_list|,
name|mPixmap
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|mPixmapSurface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Could not make egl surface out of pixmap :("
expr_stmt|;
block|}
block|}
end_function
end_unit
