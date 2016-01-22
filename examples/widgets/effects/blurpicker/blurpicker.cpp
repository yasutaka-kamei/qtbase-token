begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"blurpicker.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_include
include|#
directive|include
file|"blureffect.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|M_PI
end_ifndef
begin_define
DECL|macro|M_PI
define|#
directive|define
name|M_PI
value|3.14159265358979323846
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|BlurPicker
name|BlurPicker
operator|::
name|BlurPicker
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_index
argument_list|(
literal|0.0
argument_list|)
member_init_list|,
name|m_animation
argument_list|(
name|this
argument_list|,
literal|"index"
argument_list|)
block|{
name|setBackgroundBrush
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/background.jpg"
argument_list|)
argument_list|)
expr_stmt|;
name|setScene
argument_list|(
operator|new
name|QGraphicsScene
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|setupScene
argument_list|()
expr_stmt|;
name|setIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_animation
operator|.
name|setDuration
argument_list|(
literal|400
argument_list|)
expr_stmt|;
name|m_animation
operator|.
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutSine
argument_list|)
expr_stmt|;
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|NoFrame
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|index
name|qreal
name|BlurPicker
operator|::
name|index
parameter_list|()
specifier|const
block|{
return|return
name|m_index
return|;
block|}
end_function
begin_function
DECL|function|setIndex
name|void
name|BlurPicker
operator|::
name|setIndex
parameter_list|(
name|qreal
name|index
parameter_list|)
block|{
name|m_index
operator|=
name|index
expr_stmt|;
name|qreal
name|baseline
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_icons
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QGraphicsItem
modifier|*
name|icon
init|=
name|m_icons
index|[
name|i
index|]
decl_stmt|;
name|qreal
name|a
init|=
operator|(
operator|(
name|i
operator|+
name|m_index
operator|)
operator|*
literal|2
operator|*
name|M_PI
operator|)
operator|/
name|m_icons
operator|.
name|count
argument_list|()
decl_stmt|;
name|qreal
name|xs
init|=
literal|170
operator|*
name|qSin
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|qreal
name|ys
init|=
literal|100
operator|*
name|qCos
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|QPointF
name|pos
argument_list|(
name|xs
argument_list|,
name|ys
argument_list|)
decl_stmt|;
name|pos
operator|=
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
operator|-
literal|20
argument_list|)
operator|.
name|map
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|pos
operator|-=
name|QPointF
argument_list|(
literal|40
argument_list|,
literal|40
argument_list|)
expr_stmt|;
name|icon
operator|->
name|setPos
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|baseline
operator|=
name|qMax
argument_list|(
name|baseline
argument_list|,
name|ys
argument_list|)
expr_stmt|;
cast|static_cast
argument_list|<
name|BlurEffect
operator|*
argument_list|>
argument_list|(
name|icon
operator|->
name|graphicsEffect
argument_list|()
argument_list|)
operator|->
name|setBaseLine
argument_list|(
name|baseline
argument_list|)
expr_stmt|;
block|}
name|scene
argument_list|()
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupScene
name|void
name|BlurPicker
operator|::
name|setupScene
parameter_list|()
block|{
name|scene
argument_list|()
operator|->
name|setSceneRect
argument_list|(
operator|-
literal|200
argument_list|,
operator|-
literal|120
argument_list|,
literal|400
argument_list|,
literal|240
argument_list|)
expr_stmt|;
name|QStringList
name|names
decl_stmt|;
name|names
operator|<<
literal|":/images/accessories-calculator.png"
expr_stmt|;
name|names
operator|<<
literal|":/images/accessories-text-editor.png"
expr_stmt|;
name|names
operator|<<
literal|":/images/help-browser.png"
expr_stmt|;
name|names
operator|<<
literal|":/images/internet-group-chat.png"
expr_stmt|;
name|names
operator|<<
literal|":/images/internet-mail.png"
expr_stmt|;
name|names
operator|<<
literal|":/images/internet-web-browser.png"
expr_stmt|;
name|names
operator|<<
literal|":/images/office-calendar.png"
expr_stmt|;
name|names
operator|<<
literal|":/images/system-users.png"
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
name|names
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QPixmap
name|pixmap
argument_list|(
name|names
index|[
name|i
index|]
argument_list|)
decl_stmt|;
name|QGraphicsPixmapItem
modifier|*
name|icon
init|=
name|scene
argument_list|()
operator|->
name|addPixmap
argument_list|(
name|pixmap
argument_list|)
decl_stmt|;
name|icon
operator|->
name|setZValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|icon
operator|->
name|setGraphicsEffect
argument_list|(
operator|new
name|BlurEffect
argument_list|(
name|icon
argument_list|)
argument_list|)
expr_stmt|;
name|m_icons
operator|<<
name|icon
expr_stmt|;
block|}
name|QGraphicsPixmapItem
modifier|*
name|bg
init|=
name|scene
argument_list|()
operator|->
name|addPixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/background.jpg"
argument_list|)
argument_list|)
decl_stmt|;
name|bg
operator|->
name|setZValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bg
operator|->
name|setPos
argument_list|(
operator|-
literal|200
argument_list|,
operator|-
literal|150
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyPressEvent
name|void
name|BlurPicker
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
name|int
name|delta
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|event
operator|->
name|key
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_Left
case|:
name|delta
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Right
case|:
name|delta
operator|=
literal|1
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|m_animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
operator|&&
name|delta
condition|)
block|{
name|m_animation
operator|.
name|setEndValue
argument_list|(
name|m_index
operator|+
name|delta
argument_list|)
expr_stmt|;
name|m_animation
operator|.
name|start
argument_list|()
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|BlurPicker
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
comment|/* event */
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|BlurPicker
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|int
name|delta
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|event
operator|->
name|x
argument_list|()
operator|>
operator|(
name|width
argument_list|()
operator|/
literal|2
operator|)
condition|)
block|{
name|delta
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|delta
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|m_animation
operator|.
name|state
argument_list|()
operator|==
name|QAbstractAnimation
operator|::
name|Stopped
operator|&&
name|delta
condition|)
block|{
name|m_animation
operator|.
name|setEndValue
argument_list|(
name|m_index
operator|+
name|delta
argument_list|)
expr_stmt|;
name|m_animation
operator|.
name|start
argument_list|()
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
block|}
end_function
end_unit
