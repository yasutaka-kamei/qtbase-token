begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglwidget_p.h"
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/private/qwidget_p.h>
end_include
begin_include
include|#
directive|include
file|<QOpenGLFramebufferObject>
end_include
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QOpenGLWidgetPrivate
class|class
name|QOpenGLWidgetPrivate
super|:
specifier|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QOpenGLWidget
parameter_list|)
specifier|public
private|:
DECL|function|QOpenGLWidgetPrivate
name|QOpenGLWidgetPrivate
parameter_list|()
member_init_list|:
name|fbo
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|uninitialized
argument_list|(
literal|true
argument_list|)
block|{
name|setRenderToTexture
argument_list|()
expr_stmt|;
block|}
DECL|function|textureId
name|GLuint
name|textureId
parameter_list|()
specifier|const
block|{
return|return
name|fbo
condition|?
name|fbo
operator|->
name|texture
argument_list|()
else|:
literal|0
return|;
block|}
DECL|function|surface
specifier|const
name|QSurface
modifier|*
name|surface
parameter_list|()
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|window
argument_list|()
operator|->
name|windowHandle
argument_list|()
return|;
block|}
DECL|function|surface
name|QSurface
modifier|*
name|surface
parameter_list|()
block|{
return|return
name|q_func
argument_list|()
operator|->
name|window
argument_list|()
operator|->
name|windowHandle
argument_list|()
return|;
block|}
name|void
name|initialize
parameter_list|()
function_decl|;
DECL|member|context
name|QOpenGLContext
name|context
decl_stmt|;
DECL|member|fbo
name|QOpenGLFramebufferObject
modifier|*
name|fbo
decl_stmt|;
DECL|member|uninitialized
name|bool
name|uninitialized
decl_stmt|;
DECL|member|w
DECL|member|h
name|int
name|w
decl_stmt|,
name|h
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|initialize
name|void
name|QOpenGLWidgetPrivate
operator|::
name|initialize
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QOpenGLWidget
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|uninitialized
condition|)
return|return;
name|context
operator|.
name|setShareContext
argument_list|(
name|get
argument_list|(
name|q
operator|->
name|window
argument_list|()
argument_list|)
operator|->
name|shareContext
argument_list|()
argument_list|)
expr_stmt|;
name|context
operator|.
name|setFormat
argument_list|(
name|surface
argument_list|()
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|context
operator|.
name|create
argument_list|()
expr_stmt|;
name|context
operator|.
name|makeCurrent
argument_list|(
name|surface
argument_list|()
argument_list|)
expr_stmt|;
name|q
operator|->
name|initializeGL
argument_list|()
expr_stmt|;
name|uninitialized
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QOpenGLWidget
name|QOpenGLWidget
operator|::
name|QOpenGLWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|f
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|(
operator|new
name|QOpenGLWidgetPrivate
operator|)
argument_list|,
name|parent
argument_list|,
name|f
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QOpenGLWidget
name|QOpenGLWidget
operator|::
name|~
name|QOpenGLWidget
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|isValid
name|bool
name|QOpenGLWidget
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLWidget
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|context
operator|.
name|isValid
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|makeCurrent
name|void
name|QOpenGLWidget
operator|::
name|makeCurrent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLWidget
argument_list|)
expr_stmt|;
name|d
operator|->
name|context
operator|.
name|makeCurrent
argument_list|(
name|d
operator|->
name|surface
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|fbo
operator|->
name|bind
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QOpenGLWidget
operator|::
name|doneCurrent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLWidget
argument_list|)
expr_stmt|;
name|d
operator|->
name|context
operator|.
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|format
name|QSurfaceFormat
name|QOpenGLWidget
operator|::
name|format
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLWidget
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|surface
argument_list|()
operator|->
name|format
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultFramebufferObject
name|GLuint
name|QOpenGLWidget
operator|::
name|defaultFramebufferObject
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOpenGLWidget
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|fbo
condition|?
name|d
operator|->
name|fbo
operator|->
name|handle
argument_list|()
else|:
literal|0
return|;
block|}
end_function
begin_function
DECL|function|initializeGL
name|void
name|QOpenGLWidget
operator|::
name|initializeGL
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|resizeGL
name|void
name|QOpenGLWidget
operator|::
name|resizeGL
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|h
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintGL
name|void
name|QOpenGLWidget
operator|::
name|paintGL
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|updateGL
name|void
name|QOpenGLWidget
operator|::
name|updateGL
parameter_list|()
block|{
name|makeCurrent
argument_list|()
expr_stmt|;
name|paintGL
argument_list|()
expr_stmt|;
name|glFlush
argument_list|()
expr_stmt|;
name|doneCurrent
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|QOpenGLWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOpenGLWidget
argument_list|)
expr_stmt|;
name|d
operator|->
name|w
operator|=
name|width
argument_list|()
expr_stmt|;
name|d
operator|->
name|h
operator|=
name|height
argument_list|()
expr_stmt|;
name|d
operator|->
name|initialize
argument_list|()
expr_stmt|;
name|d
operator|->
name|context
operator|.
name|makeCurrent
argument_list|(
name|d
operator|->
name|surface
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|fbo
expr_stmt|;
comment|// recreate when resized
name|d
operator|->
name|fbo
operator|=
operator|new
name|QOpenGLFramebufferObject
argument_list|(
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|fbo
operator|->
name|bind
argument_list|()
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|d
operator|->
name|fbo
operator|->
name|texture
argument_list|()
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_REPEAT
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_REPEAT
argument_list|)
expr_stmt|;
name|resizeGL
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|paintGL
argument_list|()
expr_stmt|;
name|glFlush
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|QOpenGLWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|qWarning
argument_list|(
literal|"QOpenGLWidget does not support paintEvent() yet."
argument_list|)
expr_stmt|;
return|return;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
