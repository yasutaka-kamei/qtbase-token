begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandreadbackeglintegration.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|"qwaylandreadbackeglwindow.h"
end_include
begin_constructor
DECL|function|QWaylandReadbackEglIntegration
name|QWaylandReadbackEglIntegration
operator|::
name|QWaylandReadbackEglIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|)
member_init_list|:
name|QWaylandGLIntegration
argument_list|()
member_init_list|,
name|mWaylandDisplay
argument_list|(
name|display
argument_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Using Readback-EGL"
expr_stmt|;
name|char
modifier|*
name|display_name
init|=
name|getenv
argument_list|(
literal|"DISPLAY"
argument_list|)
decl_stmt|;
name|mDisplay
operator|=
name|XOpenDisplay
argument_list|(
name|display_name
argument_list|)
expr_stmt|;
name|mScreen
operator|=
name|XDefaultScreen
argument_list|(
name|mDisplay
argument_list|)
expr_stmt|;
name|mRootWindow
operator|=
name|XDefaultRootWindow
argument_list|(
name|mDisplay
argument_list|)
expr_stmt|;
name|XSync
argument_list|(
name|mDisplay
argument_list|,
name|False
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandReadbackEglIntegration
name|QWaylandReadbackEglIntegration
operator|::
name|~
name|QWaylandReadbackEglIntegration
parameter_list|()
block|{
name|XCloseDisplay
argument_list|(
name|mDisplay
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|createGLIntegration
name|QWaylandGLIntegration
modifier|*
name|QWaylandGLIntegration
operator|::
name|createGLIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|waylandDisplay
parameter_list|)
block|{
return|return
operator|new
name|QWaylandReadbackEglIntegration
argument_list|(
name|waylandDisplay
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|QWaylandReadbackEglIntegration
operator|::
name|initialize
parameter_list|()
block|{
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
name|mEglDisplay
operator|=
name|eglGetDisplay
argument_list|(
name|mDisplay
argument_list|)
expr_stmt|;
name|EGLint
name|major
decl_stmt|,
name|minor
decl_stmt|;
name|EGLBoolean
name|initialized
init|=
name|eglInitialize
argument_list|(
name|mEglDisplay
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
decl_stmt|;
if|if
condition|(
name|initialized
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"EGL initialized successfully"
operator|<<
name|major
operator|<<
literal|","
operator|<<
name|minor
expr_stmt|;
block|}
else|else
block|{
name|qDebug
argument_list|()
operator|<<
literal|"EGL could not initialized. All EGL and GL operations will fail"
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createEglWindow
name|QWaylandWindow
modifier|*
name|QWaylandReadbackEglIntegration
operator|::
name|createEglWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
return|return
operator|new
name|QWaylandReadbackEglWindow
argument_list|(
name|widget
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|eglDisplay
name|EGLDisplay
name|QWaylandReadbackEglIntegration
operator|::
name|eglDisplay
parameter_list|()
block|{
return|return
name|mEglDisplay
return|;
block|}
end_function
begin_function
DECL|function|rootWindow
name|Window
name|QWaylandReadbackEglIntegration
operator|::
name|rootWindow
parameter_list|()
specifier|const
block|{
return|return
name|mRootWindow
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QWaylandReadbackEglIntegration
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|XDefaultDepth
argument_list|(
name|mDisplay
argument_list|,
name|mScreen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|xDisplay
name|Display
modifier|*
name|QWaylandReadbackEglIntegration
operator|::
name|xDisplay
parameter_list|()
specifier|const
block|{
return|return
name|mDisplay
return|;
block|}
end_function
begin_function
DECL|function|waylandDisplay
name|QWaylandDisplay
modifier|*
name|QWaylandReadbackEglIntegration
operator|::
name|waylandDisplay
parameter_list|()
specifier|const
block|{
return|return
name|mWaylandDisplay
return|;
block|}
end_function
end_unit
