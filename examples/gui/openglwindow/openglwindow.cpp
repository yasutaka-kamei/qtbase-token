begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"openglwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLPaintDevice>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_comment
comment|//! [1]
end_comment
begin_constructor
DECL|function|OpenGLWindow
name|OpenGLWindow
operator|::
name|OpenGLWindow
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWindow
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_update_pending
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_animating
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_context
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_device
argument_list|(
literal|0
argument_list|)
block|{
name|setSurfaceType
argument_list|(
name|QWindow
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_destructor
DECL|function|~OpenGLWindow
name|OpenGLWindow
operator|::
name|~
name|OpenGLWindow
parameter_list|()
block|{
operator|delete
name|m_device
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|render
name|void
name|OpenGLWindow
operator|::
name|render
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|painter
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|OpenGLWindow
operator|::
name|initialize
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|render
name|void
name|OpenGLWindow
operator|::
name|render
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_device
condition|)
name|m_device
operator|=
operator|new
name|QOpenGLPaintDevice
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
operator||
name|GL_STENCIL_BUFFER_BIT
argument_list|)
expr_stmt|;
name|m_device
operator|->
name|setSize
argument_list|(
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
name|m_device
argument_list|)
decl_stmt|;
name|render
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|renderLater
name|void
name|OpenGLWindow
operator|::
name|renderLater
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_update_pending
condition|)
block|{
name|m_update_pending
operator|=
literal|true
expr_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|UpdateRequest
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|event
name|bool
name|OpenGLWindow
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|UpdateRequest
case|:
name|renderNow
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
default|default:
return|return
name|QWindow
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|exposeEvent
name|void
name|OpenGLWindow
operator|::
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|isExposed
argument_list|()
condition|)
name|renderNow
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|OpenGLWindow
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|isExposed
argument_list|()
condition|)
name|renderNow
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|renderNow
name|void
name|OpenGLWindow
operator|::
name|renderNow
parameter_list|()
block|{
if|if
condition|(
operator|!
name|isExposed
argument_list|()
condition|)
return|return;
name|m_update_pending
operator|=
literal|false
expr_stmt|;
name|bool
name|needsInitialize
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|m_context
condition|)
block|{
name|m_context
operator|=
operator|new
name|QOpenGLContext
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|setFormat
argument_list|(
name|requestedFormat
argument_list|()
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|create
argument_list|()
expr_stmt|;
name|needsInitialize
operator|=
literal|true
expr_stmt|;
block|}
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|needsInitialize
condition|)
block|{
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
name|initialize
argument_list|()
expr_stmt|;
block|}
name|render
argument_list|()
expr_stmt|;
name|m_context
operator|->
name|swapBuffers
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_animating
condition|)
name|renderLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|setAnimating
name|void
name|OpenGLWindow
operator|::
name|setAnimating
parameter_list|(
name|bool
name|animating
parameter_list|)
block|{
name|m_animating
operator|=
name|animating
expr_stmt|;
if|if
condition|(
name|animating
condition|)
name|renderLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
