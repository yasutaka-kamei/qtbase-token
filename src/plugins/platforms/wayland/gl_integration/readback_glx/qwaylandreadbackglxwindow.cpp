begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_include
include|#
directive|include
file|"qwaylandreadbackglxwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandshmbackingstore.h"
end_include
begin_constructor
DECL|function|QWaylandReadbackGlxWindow
name|QWaylandReadbackGlxWindow
operator|::
name|QWaylandReadbackGlxWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|QWaylandReadbackGlxIntegration
modifier|*
name|glxIntegration
parameter_list|)
member_init_list|:
name|QWaylandShmWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|m_glxIntegration
argument_list|(
name|glxIntegration
argument_list|)
member_init_list|,
name|m_buffer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_pixmap
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_config
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_glxPixmap
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_window
argument_list|(
name|window
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|windowType
name|QWaylandWindow
operator|::
name|WindowType
name|QWaylandReadbackGlxWindow
operator|::
name|windowType
parameter_list|()
specifier|const
block|{
comment|//yeah. this type needs a new name
return|return
name|QWaylandWindow
operator|::
name|Egl
return|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QWaylandReadbackGlxWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QWaylandShmWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_pixmap
condition|)
block|{
operator|delete
name|mBuffer
expr_stmt|;
comment|//XFreePixmap deletes the glxPixmap as well
name|XFreePixmap
argument_list|(
name|m_glxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|m_pixmap
argument_list|)
expr_stmt|;
name|m_pixmap
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|glxPixmap
name|GLXPixmap
name|QWaylandReadbackGlxWindow
operator|::
name|glxPixmap
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_pixmap
condition|)
cast|const_cast
argument_list|<
name|QWaylandReadbackGlxWindow
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|createSurface
argument_list|()
expr_stmt|;
return|return
name|m_glxPixmap
return|;
block|}
end_function
begin_function
DECL|function|buffer
name|uchar
modifier|*
name|QWaylandReadbackGlxWindow
operator|::
name|buffer
parameter_list|()
block|{
return|return
name|m_buffer
operator|->
name|image
argument_list|()
operator|->
name|bits
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createGLSurface
name|QPlatformGLSurface
modifier|*
name|QWaylandReadbackGlxWindow
operator|::
name|createGLSurface
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QWaylandReadbackGlxSurface
argument_list|(
cast|const_cast
argument_list|<
name|QWaylandReadbackGlxWindow
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createSurface
name|void
name|QWaylandReadbackGlxWindow
operator|::
name|createSurface
parameter_list|()
block|{
name|QSize
name|size
argument_list|(
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
name|waitForFrameSync
argument_list|()
expr_stmt|;
name|m_buffer
operator|=
operator|new
name|QWaylandShmBuffer
argument_list|(
name|m_glxIntegration
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
name|attach
argument_list|(
name|m_buffer
argument_list|)
expr_stmt|;
name|int
name|depth
init|=
name|XDefaultDepth
argument_list|(
name|m_glxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|m_glxIntegration
operator|->
name|screen
argument_list|()
argument_list|)
decl_stmt|;
name|m_pixmap
operator|=
name|XCreatePixmap
argument_list|(
name|m_glxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|m_glxIntegration
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
name|depth
argument_list|)
expr_stmt|;
name|XSync
argument_list|(
name|m_glxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|False
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_config
condition|)
name|m_config
operator|=
name|qglx_findConfig
argument_list|(
name|m_glxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|m_glxIntegration
operator|->
name|screen
argument_list|()
argument_list|,
name|m_window
operator|->
name|glFormat
argument_list|()
argument_list|)
expr_stmt|;
name|m_glxPixmap
operator|=
name|glXCreatePixmap
argument_list|(
name|m_glxIntegration
operator|->
name|xDisplay
argument_list|()
argument_list|,
name|m_config
argument_list|,
name|m_pixmap
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_glxPixmap
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Could not make glx surface out of pixmap :("
expr_stmt|;
block|}
end_function
end_unit
