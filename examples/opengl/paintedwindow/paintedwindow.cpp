begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"paintedwindow.h"
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QOpenGLPaintDevice>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_constructor
DECL|function|PaintedWindow
name|PaintedWindow
operator|::
name|PaintedWindow
parameter_list|()
block|{
name|QSurfaceFormat
name|format
decl_stmt|;
name|format
operator|.
name|setStencilBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|format
operator|.
name|setSamples
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|setSurfaceType
argument_list|(
name|QWindow
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|Window
operator||
name|Qt
operator|::
name|WindowTitleHint
operator||
name|Qt
operator|::
name|WindowMinMaxButtonsHint
operator||
name|Qt
operator|::
name|WindowCloseButtonHint
argument_list|)
expr_stmt|;
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|create
argument_list|()
expr_stmt|;
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
name|format
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|create
argument_list|()
expr_stmt|;
name|m_animation
operator|=
operator|new
name|QPropertyAnimation
argument_list|(
name|this
argument_list|,
literal|"rotation"
argument_list|)
expr_stmt|;
name|m_animation
operator|->
name|setStartValue
argument_list|(
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|m_animation
operator|->
name|setEndValue
argument_list|(
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|m_animation
operator|->
name|setDuration
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|setOrientation
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|primaryOrientation
argument_list|()
argument_list|)
expr_stmt|;
name|m_rotation
operator|=
literal|0
expr_stmt|;
name|m_targetOrientation
operator|=
name|orientation
argument_list|()
expr_stmt|;
name|m_nextTargetOrientation
operator|=
name|Qt
operator|::
name|UnknownOrientation
expr_stmt|;
name|connect
argument_list|(
name|screen
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|currentOrientationChanged
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|orientationChanged
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_animation
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rotationDone
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|rotationChanged
argument_list|(
name|qreal
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|paint
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|resizeEvent
name|void
name|PaintedWindow
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|paint
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|exposeEvent
name|void
name|PaintedWindow
operator|::
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
parameter_list|)
block|{
name|paint
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|PaintedWindow
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{
name|Qt
operator|::
name|ScreenOrientation
name|o
init|=
name|orientation
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|o
condition|)
block|{
case|case
name|Qt
operator|::
name|LandscapeOrientation
case|:
name|orientationChanged
argument_list|(
name|Qt
operator|::
name|PortraitOrientation
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|PortraitOrientation
case|:
name|orientationChanged
argument_list|(
name|Qt
operator|::
name|InvertedLandscapeOrientation
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|InvertedLandscapeOrientation
case|:
name|orientationChanged
argument_list|(
name|Qt
operator|::
name|InvertedPortraitOrientation
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|InvertedPortraitOrientation
case|:
name|orientationChanged
argument_list|(
name|Qt
operator|::
name|LandscapeOrientation
argument_list|)
expr_stmt|;
break|break;
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
name|paint
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|orientationChanged
name|void
name|PaintedWindow
operator|::
name|orientationChanged
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|newOrientation
parameter_list|)
block|{
if|if
condition|(
name|orientation
argument_list|()
operator|==
name|newOrientation
condition|)
return|return;
if|if
condition|(
name|m_animation
operator|->
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Running
condition|)
block|{
name|m_nextTargetOrientation
operator|=
name|newOrientation
expr_stmt|;
return|return;
block|}
name|Qt
operator|::
name|ScreenOrientation
name|screenOrientation
init|=
name|screen
argument_list|()
operator|->
name|primaryOrientation
argument_list|()
decl_stmt|;
name|QRect
name|rect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|m_prevImage
operator|=
name|QImage
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
expr_stmt|;
name|m_nextImage
operator|=
name|QImage
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
expr_stmt|;
name|m_prevImage
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_nextImage
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QPainter
name|p
decl_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|m_prevImage
argument_list|)
expr_stmt|;
name|p
operator|.
name|setTransform
argument_list|(
name|QScreen
operator|::
name|transformBetween
argument_list|(
name|orientation
argument_list|()
argument_list|,
name|screenOrientation
argument_list|,
name|rect
argument_list|)
argument_list|)
expr_stmt|;
name|paint
argument_list|(
operator|&
name|p
argument_list|,
name|QScreen
operator|::
name|mapBetween
argument_list|(
name|orientation
argument_list|()
argument_list|,
name|screenOrientation
argument_list|,
name|rect
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|m_nextImage
argument_list|)
expr_stmt|;
name|p
operator|.
name|setTransform
argument_list|(
name|QScreen
operator|::
name|transformBetween
argument_list|(
name|newOrientation
argument_list|,
name|screenOrientation
argument_list|,
name|rect
argument_list|)
argument_list|)
expr_stmt|;
name|paint
argument_list|(
operator|&
name|p
argument_list|,
name|QScreen
operator|::
name|mapBetween
argument_list|(
name|newOrientation
argument_list|,
name|screenOrientation
argument_list|,
name|rect
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|m_deltaRotation
operator|=
name|QScreen
operator|::
name|angleBetween
argument_list|(
name|newOrientation
argument_list|,
name|orientation
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_deltaRotation
operator|>
literal|180
condition|)
name|m_deltaRotation
operator|=
literal|180
operator|-
name|m_deltaRotation
expr_stmt|;
name|m_targetOrientation
operator|=
name|newOrientation
expr_stmt|;
name|m_animation
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rotationDone
name|void
name|PaintedWindow
operator|::
name|rotationDone
parameter_list|()
block|{
name|setOrientation
argument_list|(
name|m_targetOrientation
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_nextTargetOrientation
operator|!=
name|Qt
operator|::
name|UnknownOrientation
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|m_animation
operator|->
name|state
argument_list|()
operator|!=
name|QAbstractAnimation
operator|::
name|Running
argument_list|)
expr_stmt|;
name|orientationChanged
argument_list|(
name|m_nextTargetOrientation
argument_list|)
expr_stmt|;
name|m_nextTargetOrientation
operator|=
name|Qt
operator|::
name|UnknownOrientation
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setRotation
name|void
name|PaintedWindow
operator|::
name|setRotation
parameter_list|(
name|qreal
name|r
parameter_list|)
block|{
if|if
condition|(
name|r
operator|!=
name|m_rotation
condition|)
block|{
name|m_rotation
operator|=
name|r
expr_stmt|;
emit|emit
name|rotationChanged
argument_list|(
name|r
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|paint
name|void
name|PaintedWindow
operator|::
name|paint
parameter_list|()
block|{
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|screenOrientation
init|=
name|screen
argument_list|()
operator|->
name|primaryOrientation
argument_list|()
decl_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|appOrientation
init|=
name|orientation
argument_list|()
decl_stmt|;
name|QRect
name|rect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QOpenGLPaintDevice
name|device
argument_list|(
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|device
argument_list|)
decl_stmt|;
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addEllipse
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_SourceOver
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillPath
argument_list|(
name|path
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
argument_list|()
operator|!=
name|m_targetOrientation
condition|)
block|{
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|SmoothPixmapTransform
argument_list|)
expr_stmt|;
name|painter
operator|.
name|save
argument_list|()
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|painter
operator|.
name|rotate
argument_list|(
name|m_deltaRotation
operator|*
name|m_rotation
argument_list|)
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
operator|-
name|width
argument_list|()
operator|/
literal|2
argument_list|,
operator|-
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_prevImage
argument_list|)
expr_stmt|;
name|painter
operator|.
name|restore
argument_list|()
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|painter
operator|.
name|rotate
argument_list|(
name|m_deltaRotation
operator|*
name|m_rotation
operator|-
name|m_deltaRotation
argument_list|)
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
operator|-
name|width
argument_list|()
operator|/
literal|2
argument_list|,
operator|-
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setOpacity
argument_list|(
name|m_rotation
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_nextImage
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QRect
name|mapped
init|=
name|QScreen
operator|::
name|mapBetween
argument_list|(
name|appOrientation
argument_list|,
name|screenOrientation
argument_list|,
name|rect
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setTransform
argument_list|(
name|QScreen
operator|::
name|transformBetween
argument_list|(
name|appOrientation
argument_list|,
name|screenOrientation
argument_list|,
name|rect
argument_list|)
argument_list|)
expr_stmt|;
name|paint
argument_list|(
operator|&
name|painter
argument_list|,
name|mapped
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
name|m_context
operator|->
name|swapBuffers
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|PaintedWindow
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|painter
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setPixelSize
argument_list|(
literal|64
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
literal|"Hello"
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
