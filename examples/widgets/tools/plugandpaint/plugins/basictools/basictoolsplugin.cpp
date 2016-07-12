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
file|<cmath>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|"basictoolsplugin.h"
end_include
begin_decl_stmt
DECL|variable|Pi
specifier|const
name|float
name|Pi
init|=
literal|3.14159f
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|brushes
name|QStringList
name|BasicToolsPlugin
operator|::
name|brushes
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|tr
argument_list|(
literal|"Pencil"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Air Brush"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Random Letters"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|mousePress
name|QRect
name|BasicToolsPlugin
operator|::
name|mousePress
parameter_list|(
specifier|const
name|QString
modifier|&
name|brush
parameter_list|,
name|QPainter
modifier|&
name|painter
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
return|return
name|mouseMove
argument_list|(
name|brush
argument_list|,
name|painter
argument_list|,
name|pos
argument_list|,
name|pos
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|mouseMove
name|QRect
name|BasicToolsPlugin
operator|::
name|mouseMove
parameter_list|(
specifier|const
name|QString
modifier|&
name|brush
parameter_list|,
name|QPainter
modifier|&
name|painter
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|oldPos
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|newPos
parameter_list|)
block|{
name|painter
operator|.
name|save
argument_list|()
expr_stmt|;
name|int
name|rad
init|=
name|painter
operator|.
name|pen
argument_list|()
operator|.
name|width
argument_list|()
operator|/
literal|2
decl_stmt|;
name|QRect
name|boundingRect
init|=
name|QRect
argument_list|(
name|oldPos
argument_list|,
name|newPos
argument_list|)
operator|.
name|normalized
argument_list|()
operator|.
name|adjusted
argument_list|(
operator|-
name|rad
argument_list|,
operator|-
name|rad
argument_list|,
operator|+
name|rad
argument_list|,
operator|+
name|rad
argument_list|)
decl_stmt|;
name|QColor
name|color
init|=
name|painter
operator|.
name|pen
argument_list|()
operator|.
name|color
argument_list|()
decl_stmt|;
name|int
name|thickness
init|=
name|painter
operator|.
name|pen
argument_list|()
operator|.
name|width
argument_list|()
decl_stmt|;
name|QColor
name|transparentColor
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
literal|0
argument_list|)
decl_stmt|;
comment|//! [2] //! [3]
if|if
condition|(
name|brush
operator|==
name|tr
argument_list|(
literal|"Pencil"
argument_list|)
condition|)
block|{
name|painter
operator|.
name|drawLine
argument_list|(
name|oldPos
argument_list|,
name|newPos
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|brush
operator|==
name|tr
argument_list|(
literal|"Air Brush"
argument_list|)
condition|)
block|{
name|int
name|numSteps
init|=
literal|2
operator|+
operator|(
name|newPos
operator|-
name|oldPos
operator|)
operator|.
name|manhattanLength
argument_list|()
operator|/
literal|2
decl_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|color
argument_list|,
name|Qt
operator|::
name|Dense6Pattern
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numSteps
condition|;
operator|++
name|i
control|)
block|{
name|int
name|x
init|=
name|oldPos
operator|.
name|x
argument_list|()
operator|+
name|i
operator|*
operator|(
name|newPos
operator|.
name|x
argument_list|()
operator|-
name|oldPos
operator|.
name|x
argument_list|()
operator|)
operator|/
operator|(
name|numSteps
operator|-
literal|1
operator|)
decl_stmt|;
name|int
name|y
init|=
name|oldPos
operator|.
name|y
argument_list|()
operator|+
name|i
operator|*
operator|(
name|newPos
operator|.
name|y
argument_list|()
operator|-
name|oldPos
operator|.
name|y
argument_list|()
operator|)
operator|/
operator|(
name|numSteps
operator|-
literal|1
operator|)
decl_stmt|;
name|painter
operator|.
name|drawEllipse
argument_list|(
name|x
operator|-
operator|(
name|thickness
operator|/
literal|2
operator|)
argument_list|,
name|y
operator|-
operator|(
name|thickness
operator|/
literal|2
operator|)
argument_list|,
name|thickness
argument_list|,
name|thickness
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|brush
operator|==
name|tr
argument_list|(
literal|"Random Letters"
argument_list|)
condition|)
block|{
name|QChar
name|ch
argument_list|(
literal|'A'
operator|+
operator|(
name|qrand
argument_list|()
operator|%
literal|26
operator|)
argument_list|)
decl_stmt|;
name|QFont
name|biggerFont
init|=
name|painter
operator|.
name|font
argument_list|()
decl_stmt|;
name|biggerFont
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|biggerFont
operator|.
name|setPointSize
argument_list|(
name|biggerFont
operator|.
name|pointSize
argument_list|()
operator|+
name|thickness
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setFont
argument_list|(
name|biggerFont
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
name|newPos
argument_list|,
name|QString
argument_list|(
name|ch
argument_list|)
argument_list|)
expr_stmt|;
name|QFontMetrics
name|metrics
argument_list|(
name|painter
operator|.
name|font
argument_list|()
argument_list|)
decl_stmt|;
name|boundingRect
operator|=
name|metrics
operator|.
name|boundingRect
argument_list|(
name|ch
argument_list|)
expr_stmt|;
name|boundingRect
operator|.
name|translate
argument_list|(
name|newPos
argument_list|)
expr_stmt|;
name|boundingRect
operator|.
name|adjust
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
operator|+
literal|10
argument_list|,
operator|+
literal|10
argument_list|)
expr_stmt|;
block|}
name|painter
operator|.
name|restore
argument_list|()
expr_stmt|;
return|return
name|boundingRect
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|mouseRelease
name|QRect
name|BasicToolsPlugin
operator|::
name|mouseRelease
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* brush */
parameter_list|,
name|QPainter
modifier|&
comment|/* painter */
parameter_list|,
specifier|const
name|QPoint
modifier|&
comment|/* pos */
parameter_list|)
block|{
return|return
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|shapes
name|QStringList
name|BasicToolsPlugin
operator|::
name|shapes
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|tr
argument_list|(
literal|"Circle"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Star"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Text..."
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|generateShape
name|QPainterPath
name|BasicToolsPlugin
operator|::
name|generateShape
parameter_list|(
specifier|const
name|QString
modifier|&
name|shape
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
name|QPainterPath
name|path
decl_stmt|;
if|if
condition|(
name|shape
operator|==
name|tr
argument_list|(
literal|"Circle"
argument_list|)
condition|)
block|{
name|path
operator|.
name|addEllipse
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|shape
operator|==
name|tr
argument_list|(
literal|"Star"
argument_list|)
condition|)
block|{
name|path
operator|.
name|moveTo
argument_list|(
literal|90
argument_list|,
literal|50
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|5
condition|;
operator|++
name|i
control|)
block|{
name|path
operator|.
name|lineTo
argument_list|(
literal|50
operator|+
literal|40
operator|*
name|std
operator|::
name|cos
argument_list|(
literal|0.8
operator|*
name|i
operator|*
name|Pi
argument_list|)
argument_list|,
literal|50
operator|+
literal|40
operator|*
name|std
operator|::
name|sin
argument_list|(
literal|0.8
operator|*
name|i
operator|*
name|Pi
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|path
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|shape
operator|==
name|tr
argument_list|(
literal|"Text..."
argument_list|)
condition|)
block|{
name|QString
name|text
init|=
name|QInputDialog
operator|::
name|getText
argument_list|(
name|parent
argument_list|,
name|tr
argument_list|(
literal|"Text Shape"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Enter text:"
argument_list|)
argument_list|,
name|QLineEdit
operator|::
name|Normal
argument_list|,
name|tr
argument_list|(
literal|"Qt"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFont
name|timesFont
argument_list|(
literal|"Times"
argument_list|,
literal|50
argument_list|)
decl_stmt|;
name|timesFont
operator|.
name|setStyleStrategy
argument_list|(
name|QFont
operator|::
name|ForceOutline
argument_list|)
expr_stmt|;
name|path
operator|.
name|addText
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|timesFont
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|path
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
DECL|function|filters
name|QStringList
name|BasicToolsPlugin
operator|::
name|filters
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|tr
argument_list|(
literal|"Invert Pixels"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Swap RGB"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Grayscale"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|filterImage
name|QImage
name|BasicToolsPlugin
operator|::
name|filterImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|QWidget
modifier|*
comment|/* parent */
parameter_list|)
block|{
name|QImage
name|result
init|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
if|if
condition|(
name|filter
operator|==
name|tr
argument_list|(
literal|"Invert Pixels"
argument_list|)
condition|)
block|{
name|result
operator|.
name|invertPixels
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|filter
operator|==
name|tr
argument_list|(
literal|"Swap RGB"
argument_list|)
condition|)
block|{
name|result
operator|=
name|result
operator|.
name|rgbSwapped
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|filter
operator|==
name|tr
argument_list|(
literal|"Grayscale"
argument_list|)
condition|)
block|{
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|result
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|result
operator|.
name|width
argument_list|()
condition|;
operator|++
name|x
control|)
block|{
name|int
name|pixel
init|=
name|result
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|int
name|gray
init|=
name|qGray
argument_list|(
name|pixel
argument_list|)
decl_stmt|;
name|int
name|alpha
init|=
name|qAlpha
argument_list|(
name|pixel
argument_list|)
decl_stmt|;
name|result
operator|.
name|setPixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|qRgba
argument_list|(
name|gray
argument_list|,
name|gray
argument_list|,
name|gray
argument_list|,
name|alpha
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
end_unit