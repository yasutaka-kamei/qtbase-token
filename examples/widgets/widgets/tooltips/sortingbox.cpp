begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|"sortingbox.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|SortingBox
name|SortingBox
operator|::
name|SortingBox
parameter_list|()
block|{
comment|//! [0] //! [1]
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [1] //! [2]
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
expr_stmt|;
comment|//! [2]
name|itemInMotion
operator|=
literal|0
expr_stmt|;
comment|//! [3]
name|newCircleButton
operator|=
name|createToolButton
argument_list|(
name|tr
argument_list|(
literal|"New Circle"
argument_list|)
argument_list|,
name|QIcon
argument_list|(
literal|":/images/circle.png"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|createNewCircle
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|newSquareButton
operator|=
name|createToolButton
argument_list|(
name|tr
argument_list|(
literal|"New Square"
argument_list|)
argument_list|,
name|QIcon
argument_list|(
literal|":/images/square.png"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|createNewSquare
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|newTriangleButton
operator|=
name|createToolButton
argument_list|(
name|tr
argument_list|(
literal|"New Triangle"
argument_list|)
argument_list|,
name|QIcon
argument_list|(
literal|":/images/triangle.png"
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|createNewTriangle
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|circlePath
operator|.
name|addEllipse
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|squarePath
operator|.
name|addRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|qreal
name|x
init|=
name|trianglePath
operator|.
name|currentPosition
argument_list|()
operator|.
name|x
argument_list|()
decl_stmt|;
name|qreal
name|y
init|=
name|trianglePath
operator|.
name|currentPosition
argument_list|()
operator|.
name|y
argument_list|()
decl_stmt|;
name|trianglePath
operator|.
name|moveTo
argument_list|(
name|x
operator|+
literal|120
operator|/
literal|2
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|trianglePath
operator|.
name|lineTo
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|trianglePath
operator|.
name|lineTo
argument_list|(
literal|120
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|trianglePath
operator|.
name|lineTo
argument_list|(
name|x
operator|+
literal|120
operator|/
literal|2
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|//! [3] //! [4]
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Tool Tips"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|500
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|createShapeItem
argument_list|(
name|circlePath
argument_list|,
name|tr
argument_list|(
literal|"Circle"
argument_list|)
argument_list|,
name|initialItemPosition
argument_list|(
name|circlePath
argument_list|)
argument_list|,
name|initialItemColor
argument_list|()
argument_list|)
expr_stmt|;
name|createShapeItem
argument_list|(
name|squarePath
argument_list|,
name|tr
argument_list|(
literal|"Square"
argument_list|)
argument_list|,
name|initialItemPosition
argument_list|(
name|squarePath
argument_list|)
argument_list|,
name|initialItemColor
argument_list|()
argument_list|)
expr_stmt|;
name|createShapeItem
argument_list|(
name|trianglePath
argument_list|,
name|tr
argument_list|(
literal|"Triangle"
argument_list|)
argument_list|,
name|initialItemPosition
argument_list|(
name|trianglePath
argument_list|)
argument_list|,
name|initialItemColor
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|event
name|bool
name|SortingBox
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
comment|//! [5] //! [6]
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|ToolTip
condition|)
block|{
name|QHelpEvent
modifier|*
name|helpEvent
init|=
cast|static_cast
argument_list|<
name|QHelpEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|int
name|index
init|=
name|itemAt
argument_list|(
name|helpEvent
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
block|{
name|QToolTip
operator|::
name|showText
argument_list|(
name|helpEvent
operator|->
name|globalPos
argument_list|()
argument_list|,
name|shapeItems
index|[
name|index
index|]
operator|.
name|toolTip
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QToolTip
operator|::
name|hideText
argument_list|()
expr_stmt|;
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|SortingBox
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
comment|/* event */
parameter_list|)
block|{
name|int
name|margin
init|=
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_DefaultTopLevelMargin
argument_list|)
decl_stmt|;
name|int
name|x
init|=
name|width
argument_list|()
operator|-
name|margin
decl_stmt|;
name|int
name|y
init|=
name|height
argument_list|()
operator|-
name|margin
decl_stmt|;
name|y
operator|=
name|updateButtonGeometry
argument_list|(
name|newCircleButton
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|y
operator|=
name|updateButtonGeometry
argument_list|(
name|newSquareButton
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|updateButtonGeometry
argument_list|(
name|newTriangleButton
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|SortingBox
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
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|ShapeItem
name|shapeItem
decl|,
name|shapeItems
control|)
block|{
comment|//! [8] //! [9]
name|painter
operator|.
name|translate
argument_list|(
name|shapeItem
operator|.
name|position
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [9] //! [10]
name|painter
operator|.
name|setBrush
argument_list|(
name|shapeItem
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPath
argument_list|(
name|shapeItem
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
operator|-
name|shapeItem
operator|.
name|position
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|SortingBox
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
name|int
name|index
init|=
name|itemAt
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
block|{
name|itemInMotion
operator|=
operator|&
name|shapeItems
index|[
name|index
index|]
expr_stmt|;
name|previousPosition
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
name|shapeItems
operator|.
name|move
argument_list|(
name|index
argument_list|,
name|shapeItems
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|SortingBox
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
name|itemInMotion
condition|)
name|moveItemTo
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|SortingBox
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
name|itemInMotion
condition|)
block|{
name|moveItemTo
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|itemInMotion
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_function
DECL|function|createNewCircle
name|void
name|SortingBox
operator|::
name|createNewCircle
parameter_list|()
block|{
specifier|static
name|int
name|count
init|=
literal|1
decl_stmt|;
name|createShapeItem
argument_list|(
name|circlePath
argument_list|,
name|tr
argument_list|(
literal|"Circle<%1>"
argument_list|)
operator|.
name|arg
argument_list|(
operator|++
name|count
argument_list|)
argument_list|,
name|randomItemPosition
argument_list|()
argument_list|,
name|randomItemColor
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|createNewSquare
name|void
name|SortingBox
operator|::
name|createNewSquare
parameter_list|()
block|{
specifier|static
name|int
name|count
init|=
literal|1
decl_stmt|;
name|createShapeItem
argument_list|(
name|squarePath
argument_list|,
name|tr
argument_list|(
literal|"Square<%1>"
argument_list|)
operator|.
name|arg
argument_list|(
operator|++
name|count
argument_list|)
argument_list|,
name|randomItemPosition
argument_list|()
argument_list|,
name|randomItemColor
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_function
DECL|function|createNewTriangle
name|void
name|SortingBox
operator|::
name|createNewTriangle
parameter_list|()
block|{
specifier|static
name|int
name|count
init|=
literal|1
decl_stmt|;
name|createShapeItem
argument_list|(
name|trianglePath
argument_list|,
name|tr
argument_list|(
literal|"Triangle<%1>"
argument_list|)
operator|.
name|arg
argument_list|(
operator|++
name|count
argument_list|)
argument_list|,
name|randomItemPosition
argument_list|()
argument_list|,
name|randomItemColor
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_function
DECL|function|itemAt
name|int
name|SortingBox
operator|::
name|itemAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
name|shapeItems
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
specifier|const
name|ShapeItem
modifier|&
name|item
init|=
name|shapeItems
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|item
operator|.
name|path
argument_list|()
operator|.
name|contains
argument_list|(
name|pos
operator|-
name|item
operator|.
name|position
argument_list|()
argument_list|)
condition|)
return|return
name|i
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_function
DECL|function|moveItemTo
name|void
name|SortingBox
operator|::
name|moveItemTo
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|QPoint
name|offset
init|=
name|pos
operator|-
name|previousPosition
decl_stmt|;
name|itemInMotion
operator|->
name|setPosition
argument_list|(
name|itemInMotion
operator|->
name|position
argument_list|()
operator|+
name|offset
argument_list|)
expr_stmt|;
comment|//! [18] //! [19]
name|previousPosition
operator|=
name|pos
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [19]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_function
DECL|function|updateButtonGeometry
name|int
name|SortingBox
operator|::
name|updateButtonGeometry
parameter_list|(
name|QToolButton
modifier|*
name|button
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|QSize
name|size
init|=
name|button
operator|->
name|sizeHint
argument_list|()
decl_stmt|;
name|button
operator|->
name|setGeometry
argument_list|(
name|x
operator|-
name|size
operator|.
name|rwidth
argument_list|()
argument_list|,
name|y
operator|-
name|size
operator|.
name|rheight
argument_list|()
argument_list|,
name|size
operator|.
name|rwidth
argument_list|()
argument_list|,
name|size
operator|.
name|rheight
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|y
operator|-
name|size
operator|.
name|rheight
argument_list|()
operator|-
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_DefaultLayoutSpacing
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_function
DECL|function|createShapeItem
name|void
name|SortingBox
operator|::
name|createShapeItem
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|toolTip
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|ShapeItem
name|shapeItem
decl_stmt|;
name|shapeItem
operator|.
name|setPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|shapeItem
operator|.
name|setToolTip
argument_list|(
name|toolTip
argument_list|)
expr_stmt|;
name|shapeItem
operator|.
name|setPosition
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|shapeItem
operator|.
name|setColor
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|shapeItems
operator|.
name|append
argument_list|(
name|shapeItem
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_function
DECL|function|createToolButton
name|QToolButton
modifier|*
name|SortingBox
operator|::
name|createToolButton
parameter_list|(
specifier|const
name|QString
modifier|&
name|toolTip
parameter_list|,
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
name|QToolButton
modifier|*
name|button
init|=
operator|new
name|QToolButton
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|button
operator|->
name|setToolTip
argument_list|(
name|toolTip
argument_list|)
expr_stmt|;
name|button
operator|->
name|setIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|button
operator|->
name|setIconSize
argument_list|(
name|QSize
argument_list|(
literal|32
argument_list|,
literal|32
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|member
argument_list|)
expr_stmt|;
return|return
name|button
return|;
block|}
end_function
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_function
DECL|function|initialItemPosition
name|QPoint
name|SortingBox
operator|::
name|initialItemPosition
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
init|=
operator|(
name|height
argument_list|()
operator|-
operator|(
name|int
operator|)
name|path
operator|.
name|controlPointRect
argument_list|()
operator|.
name|height
argument_list|()
operator|)
operator|/
literal|2
decl_stmt|;
if|if
condition|(
name|shapeItems
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
name|x
operator|=
operator|(
operator|(
literal|3
operator|*
name|width
argument_list|()
operator|)
operator|/
literal|2
operator|-
operator|(
name|int
operator|)
name|path
operator|.
name|controlPointRect
argument_list|()
operator|.
name|width
argument_list|()
operator|)
operator|/
literal|2
expr_stmt|;
else|else
name|x
operator|=
operator|(
name|width
argument_list|()
operator|/
name|shapeItems
operator|.
name|size
argument_list|()
operator|-
operator|(
name|int
operator|)
name|path
operator|.
name|controlPointRect
argument_list|()
operator|.
name|width
argument_list|()
operator|)
operator|/
literal|2
expr_stmt|;
return|return
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [23]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_function
DECL|function|randomItemPosition
name|QPoint
name|SortingBox
operator|::
name|randomItemPosition
parameter_list|()
block|{
return|return
name|QPoint
argument_list|(
name|qrand
argument_list|()
operator|%
operator|(
name|width
argument_list|()
operator|-
literal|120
operator|)
argument_list|,
name|qrand
argument_list|()
operator|%
operator|(
name|height
argument_list|()
operator|-
literal|120
operator|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_function
DECL|function|initialItemColor
name|QColor
name|SortingBox
operator|::
name|initialItemColor
parameter_list|()
block|{
return|return
name|QColor
operator|::
name|fromHsv
argument_list|(
operator|(
operator|(
name|shapeItems
operator|.
name|size
argument_list|()
operator|+
literal|1
operator|)
operator|*
literal|85
operator|)
operator|%
literal|256
argument_list|,
literal|255
argument_list|,
literal|190
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [25]
end_comment
begin_comment
comment|//! [26]
end_comment
begin_function
DECL|function|randomItemColor
name|QColor
name|SortingBox
operator|::
name|randomItemColor
parameter_list|()
block|{
return|return
name|QColor
operator|::
name|fromHsv
argument_list|(
name|qrand
argument_list|()
operator|%
literal|256
argument_list|,
literal|255
argument_list|,
literal|190
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [26]
end_comment
end_unit
