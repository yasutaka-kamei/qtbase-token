begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qglpaintdevice_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qgl_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qglpixelbuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qglframebufferobject_p.h>
end_include
begin_include
include|#
directive|include
file|<qopenglfunctions.h>
end_include
begin_include
include|#
directive|include
file|<qwindow.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QGLPaintDevice
name|QGLPaintDevice
operator|::
name|QGLPaintDevice
parameter_list|()
member_init_list|:
name|m_thisFBO
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QGLPaintDevice
name|QGLPaintDevice
operator|::
name|~
name|QGLPaintDevice
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|metric
name|int
name|QGLPaintDevice
operator|::
name|metric
parameter_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
name|metric
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|PdmWidth
case|:
return|return
name|size
argument_list|()
operator|.
name|width
argument_list|()
return|;
case|case
name|PdmHeight
case|:
return|return
name|size
argument_list|()
operator|.
name|height
argument_list|()
return|;
case|case
name|PdmDepth
case|:
block|{
specifier|const
name|QGLFormat
name|f
init|=
name|format
argument_list|()
decl_stmt|;
return|return
name|f
operator|.
name|redBufferSize
argument_list|()
operator|+
name|f
operator|.
name|greenBufferSize
argument_list|()
operator|+
name|f
operator|.
name|blueBufferSize
argument_list|()
operator|+
name|f
operator|.
name|alphaBufferSize
argument_list|()
return|;
block|}
case|case
name|PdmDevicePixelRatio
case|:
return|return
literal|1
return|;
default|default:
name|qWarning
argument_list|(
literal|"QGLPaintDevice::metric() - metric %d not known"
argument_list|,
name|metric
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QGLPaintDevice
operator|::
name|beginPaint
parameter_list|()
block|{
comment|// Make sure our context is the current one:
name|QGLContext
modifier|*
name|ctx
init|=
name|context
argument_list|()
decl_stmt|;
name|ctx
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|refreshCurrentFbo
argument_list|()
expr_stmt|;
comment|// Record the currently bound FBO so we can restore it again
comment|// in endPaint() and bind this device's FBO
comment|//
comment|// Note: m_thisFBO could be zero if the paint device is not
comment|// backed by an FBO (e.g. window back buffer).  But there could
comment|// be a previous FBO bound to the context which we need to
comment|// explicitly unbind.  Otherwise the painting will go into
comment|// the previous FBO instead of to the window.
name|m_previousFBO
operator|=
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|current_fbo
expr_stmt|;
if|if
condition|(
name|m_previousFBO
operator|!=
name|m_thisFBO
condition|)
block|{
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|setCurrentFbo
argument_list|(
name|m_thisFBO
argument_list|)
expr_stmt|;
name|ctx
operator|->
name|contextHandle
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|m_thisFBO
argument_list|)
expr_stmt|;
block|}
comment|// Set the default fbo for the context to m_thisFBO so that
comment|// if some raw GL code between beginNativePainting() and
comment|// endNativePainting() calls QGLFramebufferObject::release(),
comment|// painting will revert to the window surface's fbo.
name|ctx
operator|->
name|d_ptr
operator|->
name|default_fbo
operator|=
name|m_thisFBO
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ensureActiveTarget
name|void
name|QGLPaintDevice
operator|::
name|ensureActiveTarget
parameter_list|()
block|{
name|QGLContext
modifier|*
name|ctx
init|=
name|context
argument_list|()
decl_stmt|;
if|if
condition|(
name|ctx
operator|!=
name|QGLContext
operator|::
name|currentContext
argument_list|()
condition|)
name|ctx
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|refreshCurrentFbo
argument_list|()
expr_stmt|;
if|if
condition|(
name|ctx
operator|->
name|d_ptr
operator|->
name|current_fbo
operator|!=
name|m_thisFBO
condition|)
block|{
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|setCurrentFbo
argument_list|(
name|m_thisFBO
argument_list|)
expr_stmt|;
name|ctx
operator|->
name|contextHandle
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|m_thisFBO
argument_list|)
expr_stmt|;
block|}
name|ctx
operator|->
name|d_ptr
operator|->
name|default_fbo
operator|=
name|m_thisFBO
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QGLPaintDevice
operator|::
name|endPaint
parameter_list|()
block|{
comment|// Make sure the FBO bound at beginPaint is re-bound again here:
name|QGLContext
modifier|*
name|ctx
init|=
name|context
argument_list|()
decl_stmt|;
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|refreshCurrentFbo
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_previousFBO
operator|!=
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|current_fbo
condition|)
block|{
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|setCurrentFbo
argument_list|(
name|m_previousFBO
argument_list|)
expr_stmt|;
name|ctx
operator|->
name|contextHandle
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|m_previousFBO
argument_list|)
expr_stmt|;
block|}
name|ctx
operator|->
name|d_ptr
operator|->
name|default_fbo
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|format
name|QGLFormat
name|QGLPaintDevice
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|context
argument_list|()
operator|->
name|format
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|alphaRequested
name|bool
name|QGLPaintDevice
operator|::
name|alphaRequested
parameter_list|()
specifier|const
block|{
return|return
name|context
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|reqFormat
operator|.
name|alpha
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isFlipped
name|bool
name|QGLPaintDevice
operator|::
name|isFlipped
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|////////////////// QGLWidgetGLPaintDevice //////////////////
end_comment
begin_constructor
DECL|function|QGLWidgetGLPaintDevice
name|QGLWidgetGLPaintDevice
operator|::
name|QGLWidgetGLPaintDevice
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|QGLWidgetGLPaintDevice
operator|::
name|paintEngine
parameter_list|()
specifier|const
block|{
return|return
name|glWidget
operator|->
name|paintEngine
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setWidget
name|void
name|QGLWidgetGLPaintDevice
operator|::
name|setWidget
parameter_list|(
name|QGLWidget
modifier|*
name|w
parameter_list|)
block|{
name|glWidget
operator|=
name|w
expr_stmt|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QGLWidgetGLPaintDevice
operator|::
name|beginPaint
parameter_list|()
block|{
name|QGLPaintDevice
operator|::
name|beginPaint
argument_list|()
expr_stmt|;
name|QOpenGLFunctions
modifier|*
name|funcs
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|glWidget
operator|->
name|d_func
argument_list|()
operator|->
name|disable_clear_on_painter_begin
operator|&&
name|glWidget
operator|->
name|autoFillBackground
argument_list|()
condition|)
block|{
if|if
condition|(
name|glWidget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_TranslucentBackground
argument_list|)
condition|)
name|funcs
operator|->
name|glClearColor
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
else|else
block|{
specifier|const
name|QColor
modifier|&
name|c
init|=
name|glWidget
operator|->
name|palette
argument_list|()
operator|.
name|brush
argument_list|(
name|glWidget
operator|->
name|backgroundRole
argument_list|()
argument_list|)
operator|.
name|color
argument_list|()
decl_stmt|;
name|float
name|alpha
init|=
name|c
operator|.
name|alphaF
argument_list|()
decl_stmt|;
name|funcs
operator|->
name|glClearColor
argument_list|(
name|c
operator|.
name|redF
argument_list|()
operator|*
name|alpha
argument_list|,
name|c
operator|.
name|greenF
argument_list|()
operator|*
name|alpha
argument_list|,
name|c
operator|.
name|blueF
argument_list|()
operator|*
name|alpha
argument_list|,
name|alpha
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|context
argument_list|()
operator|->
name|d_func
argument_list|()
operator|->
name|workaround_needsFullClearOnEveryFrame
condition|)
name|funcs
operator|->
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
operator||
name|GL_STENCIL_BUFFER_BIT
argument_list|)
expr_stmt|;
else|else
name|funcs
operator|->
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QGLWidgetGLPaintDevice
operator|::
name|endPaint
parameter_list|()
block|{
if|if
condition|(
name|glWidget
operator|->
name|autoBufferSwap
argument_list|()
condition|)
name|glWidget
operator|->
name|swapBuffers
argument_list|()
expr_stmt|;
name|QGLPaintDevice
operator|::
name|endPaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|size
name|QSize
name|QGLWidgetGLPaintDevice
operator|::
name|size
parameter_list|()
specifier|const
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
return|return
name|glWidget
operator|->
name|size
argument_list|()
operator|*
operator|(
name|glWidget
operator|->
name|windowHandle
argument_list|()
condition|?
name|glWidget
operator|->
name|windowHandle
argument_list|()
operator|->
name|devicePixelRatio
argument_list|()
else|:
name|qApp
operator|->
name|devicePixelRatio
argument_list|()
operator|)
return|;
else|#
directive|else
return|return
name|glWidget
operator|->
name|size
argument_list|()
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|context
name|QGLContext
modifier|*
name|QGLWidgetGLPaintDevice
operator|::
name|context
parameter_list|()
specifier|const
block|{
return|return
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|glWidget
operator|->
name|context
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// returns the QGLPaintDevice for the given QPaintDevice
end_comment
begin_function
DECL|function|getDevice
name|QGLPaintDevice
modifier|*
name|QGLPaintDevice
operator|::
name|getDevice
parameter_list|(
name|QPaintDevice
modifier|*
name|pd
parameter_list|)
block|{
name|QGLPaintDevice
modifier|*
name|glpd
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|pd
operator|->
name|devType
argument_list|()
condition|)
block|{
case|case
name|QInternal
operator|::
name|Widget
case|:
comment|// Should not be called on a non-gl widget:
name|Q_ASSERT
argument_list|(
name|qobject_cast
argument_list|<
name|QGLWidget
operator|*
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|pd
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|glpd
operator|=
operator|&
operator|(
cast|static_cast
argument_list|<
name|QGLWidget
operator|*
argument_list|>
argument_list|(
name|pd
argument_list|)
operator|->
name|d_func
argument_list|()
operator|->
name|glDevice
operator|)
expr_stmt|;
break|break;
case|case
name|QInternal
operator|::
name|Pbuffer
case|:
name|glpd
operator|=
operator|&
operator|(
cast|static_cast
argument_list|<
name|QGLPixelBuffer
operator|*
argument_list|>
argument_list|(
name|pd
argument_list|)
operator|->
name|d_func
argument_list|()
operator|->
name|glDevice
operator|)
expr_stmt|;
break|break;
case|case
name|QInternal
operator|::
name|FramebufferObject
case|:
name|glpd
operator|=
operator|&
operator|(
cast|static_cast
argument_list|<
name|QGLFramebufferObject
operator|*
argument_list|>
argument_list|(
name|pd
argument_list|)
operator|->
name|d_func
argument_list|()
operator|->
name|glDevice
operator|)
expr_stmt|;
break|break;
case|case
name|QInternal
operator|::
name|Pixmap
case|:
block|{
name|qWarning
argument_list|(
literal|"Pixmap type not supported for GL rendering"
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
name|qWarning
argument_list|(
literal|"QGLPaintDevice::getDevice() - Unknown device type %d"
argument_list|,
name|pd
operator|->
name|devType
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|glpd
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
