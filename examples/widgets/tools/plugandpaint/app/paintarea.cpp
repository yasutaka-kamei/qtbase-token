begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"interfaces.h"
end_include
begin_include
include|#
directive|include
file|"paintarea.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QMouseEvent>
end_include
begin_constructor
DECL|function|PaintArea
name|PaintArea
operator|::
name|PaintArea
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|theImage
argument_list|(
literal|500
argument_list|,
literal|400
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
member_init_list|,
name|color
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
member_init_list|,
name|thickness
argument_list|(
literal|3
argument_list|)
member_init_list|,
name|brushInterface
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|lastPos
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoBackground
argument_list|)
expr_stmt|;
name|theImage
operator|.
name|fill
argument_list|(
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|openImage
name|bool
name|PaintArea
operator|::
name|openImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QImage
name|image
decl_stmt|;
if|if
condition|(
operator|!
name|image
operator|.
name|load
argument_list|(
name|fileName
argument_list|)
condition|)
return|return
literal|false
return|;
name|setImage
argument_list|(
name|image
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|saveImage
name|bool
name|PaintArea
operator|::
name|saveImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|char
modifier|*
name|fileFormat
parameter_list|)
block|{
return|return
name|theImage
operator|.
name|save
argument_list|(
name|fileName
argument_list|,
name|fileFormat
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setImage
name|void
name|PaintArea
operator|::
name|setImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|theImage
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertShape
name|void
name|PaintArea
operator|::
name|insertShape
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
block|{
name|pendingPath
operator|=
name|path
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setCursor
argument_list|(
name|Qt
operator|::
name|CrossCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|setBrushColor
name|void
name|PaintArea
operator|::
name|setBrushColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|this
operator|->
name|color
operator|=
name|color
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setBrushWidth
name|void
name|PaintArea
operator|::
name|setBrushWidth
parameter_list|(
name|int
name|width
parameter_list|)
block|{
name|thickness
operator|=
name|width
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|setBrush
name|void
name|PaintArea
operator|::
name|setBrush
parameter_list|(
name|BrushInterface
modifier|*
name|brushInterface
parameter_list|,
specifier|const
name|QString
modifier|&
name|brush
parameter_list|)
block|{
name|this
operator|->
name|brushInterface
operator|=
name|brushInterface
expr_stmt|;
name|this
operator|->
name|brush
operator|=
name|brush
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|PaintArea
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|theImage
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|PaintArea
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
comment|/* event */
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|drawImage
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|theImage
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|PaintArea
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
if|if
condition|(
operator|!
name|pendingPath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QPainter
name|painter
argument_list|(
operator|&
name|theImage
argument_list|)
decl_stmt|;
name|setupPainter
argument_list|(
name|painter
argument_list|)
expr_stmt|;
specifier|const
name|QRectF
name|boundingRect
init|=
name|pendingPath
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|QLinearGradient
name|gradient
argument_list|(
name|boundingRect
operator|.
name|topRight
argument_list|()
argument_list|,
name|boundingRect
operator|.
name|bottomLeft
argument_list|()
argument_list|)
decl_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.0
argument_list|,
name|QColor
argument_list|(
name|color
operator|.
name|red
argument_list|()
argument_list|,
name|color
operator|.
name|green
argument_list|()
argument_list|,
name|color
operator|.
name|blue
argument_list|()
argument_list|,
literal|63
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1.0
argument_list|,
name|QColor
argument_list|(
name|color
operator|.
name|red
argument_list|()
argument_list|,
name|color
operator|.
name|green
argument_list|()
argument_list|,
name|color
operator|.
name|blue
argument_list|()
argument_list|,
literal|191
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|gradient
argument_list|)
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
name|event
operator|->
name|pos
argument_list|()
operator|-
name|boundingRect
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPath
argument_list|(
name|pendingPath
argument_list|)
expr_stmt|;
name|pendingPath
operator|=
name|QPainterPath
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|unsetCursor
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|update
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|brushInterface
condition|)
block|{
name|QPainter
name|painter
argument_list|(
operator|&
name|theImage
argument_list|)
decl_stmt|;
name|setupPainter
argument_list|(
name|painter
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|rect
init|=
name|brushInterface
operator|->
name|mousePress
argument_list|(
name|brush
argument_list|,
name|painter
argument_list|,
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|update
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
name|lastPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|PaintArea
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|(
name|event
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
operator|)
operator|&&
name|lastPos
operator|!=
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
condition|)
block|{
if|if
condition|(
name|brushInterface
condition|)
block|{
name|QPainter
name|painter
argument_list|(
operator|&
name|theImage
argument_list|)
decl_stmt|;
name|setupPainter
argument_list|(
name|painter
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|rect
init|=
name|brushInterface
operator|->
name|mouseMove
argument_list|(
name|brush
argument_list|,
name|painter
argument_list|,
name|lastPos
argument_list|,
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|update
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
name|lastPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|PaintArea
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
operator|&&
name|lastPos
operator|!=
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
condition|)
block|{
if|if
condition|(
name|brushInterface
condition|)
block|{
name|QPainter
name|painter
argument_list|(
operator|&
name|theImage
argument_list|)
decl_stmt|;
name|setupPainter
argument_list|(
name|painter
argument_list|)
expr_stmt|;
name|QRect
name|rect
init|=
name|brushInterface
operator|->
name|mouseRelease
argument_list|(
name|brush
argument_list|,
name|painter
argument_list|,
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
name|update
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
name|lastPos
operator|=
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setupPainter
name|void
name|PaintArea
operator|::
name|setupPainter
parameter_list|(
name|QPainter
modifier|&
name|painter
parameter_list|)
block|{
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|color
argument_list|,
name|thickness
argument_list|,
name|Qt
operator|::
name|SolidLine
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|,
name|Qt
operator|::
name|RoundJoin
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
