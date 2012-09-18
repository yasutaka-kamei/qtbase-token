begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"norwegianwoodstyle.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|polish
name|void
name|NorwegianWoodStyle
operator|::
name|polish
parameter_list|(
name|QPalette
modifier|&
name|palette
parameter_list|)
block|{
name|QColor
name|brown
argument_list|(
literal|212
argument_list|,
literal|140
argument_list|,
literal|95
argument_list|)
decl_stmt|;
name|QColor
name|beige
argument_list|(
literal|236
argument_list|,
literal|182
argument_list|,
literal|120
argument_list|)
decl_stmt|;
name|QColor
name|slightlyOpaqueBlack
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|63
argument_list|)
decl_stmt|;
name|QPixmap
name|backgroundImage
argument_list|(
literal|":/images/woodbackground.png"
argument_list|)
decl_stmt|;
name|QPixmap
name|buttonImage
argument_list|(
literal|":/images/woodbutton.png"
argument_list|)
decl_stmt|;
name|QPixmap
name|midImage
init|=
name|buttonImage
decl_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|midImage
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
name|painter
operator|.
name|fillRect
argument_list|(
name|midImage
operator|.
name|rect
argument_list|()
argument_list|,
name|slightlyOpaqueBlack
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|palette
operator|=
name|QPalette
argument_list|(
name|brown
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|BrightText
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|,
name|beige
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Highlight
argument_list|,
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
name|setTexture
argument_list|(
name|palette
argument_list|,
name|QPalette
operator|::
name|Button
argument_list|,
name|buttonImage
argument_list|)
expr_stmt|;
name|setTexture
argument_list|(
name|palette
argument_list|,
name|QPalette
operator|::
name|Mid
argument_list|,
name|midImage
argument_list|)
expr_stmt|;
name|setTexture
argument_list|(
name|palette
argument_list|,
name|QPalette
operator|::
name|Window
argument_list|,
name|backgroundImage
argument_list|)
expr_stmt|;
name|QBrush
name|brush
init|=
name|palette
operator|.
name|background
argument_list|()
decl_stmt|;
name|brush
operator|.
name|setColor
argument_list|(
name|brush
operator|.
name|color
argument_list|()
operator|.
name|dark
argument_list|()
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|WindowText
argument_list|,
name|brush
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Text
argument_list|,
name|brush
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|brush
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Base
argument_list|,
name|brush
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Button
argument_list|,
name|brush
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Mid
argument_list|,
name|brush
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|polish
name|void
name|NorwegianWoodStyle
operator|::
name|polish
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
comment|//! [3] //! [4]
block|{
if|if
condition|(
name|qobject_cast
argument_list|<
name|QPushButton
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
operator|||
name|qobject_cast
argument_list|<
name|QComboBox
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
condition|)
name|widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_Hover
argument_list|,
literal|true
argument_list|)
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
DECL|function|unpolish
name|void
name|NorwegianWoodStyle
operator|::
name|unpolish
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
comment|//! [5] //! [6]
block|{
if|if
condition|(
name|qobject_cast
argument_list|<
name|QPushButton
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
operator|||
name|qobject_cast
argument_list|<
name|QComboBox
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
condition|)
name|widget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_Hover
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|pixelMetric
name|int
name|NorwegianWoodStyle
operator|::
name|pixelMetric
parameter_list|(
name|PixelMetric
name|metric
parameter_list|,
comment|//! [7] //! [8]
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|PM_ComboBoxFrameWidth
case|:
return|return
literal|8
return|;
case|case
name|PM_ScrollBarExtent
case|:
return|return
name|QWindowsStyle
operator|::
name|pixelMetric
argument_list|(
name|metric
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
operator|+
literal|4
return|;
default|default:
return|return
name|QWindowsStyle
operator|::
name|pixelMetric
argument_list|(
name|metric
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
return|;
block|}
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|styleHint
name|int
name|NorwegianWoodStyle
operator|::
name|styleHint
parameter_list|(
name|StyleHint
name|hint
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
comment|//! [9] //! [10]
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QStyleHintReturn
modifier|*
name|returnData
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|SH_DitherDisabledText
case|:
return|return
name|int
argument_list|(
literal|false
argument_list|)
return|;
case|case
name|SH_EtchDisabledText
case|:
return|return
name|int
argument_list|(
literal|true
argument_list|)
return|;
default|default:
return|return
name|QWindowsStyle
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|,
name|option
argument_list|,
name|widget
argument_list|,
name|returnData
argument_list|)
return|;
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
DECL|function|drawPrimitive
name|void
name|NorwegianWoodStyle
operator|::
name|drawPrimitive
parameter_list|(
name|PrimitiveElement
name|element
parameter_list|,
comment|//! [11] //! [12]
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|element
condition|)
block|{
case|case
name|PE_PanelButtonCommand
case|:
block|{
name|int
name|delta
init|=
operator|(
name|option
operator|->
name|state
operator|&
name|State_MouseOver
operator|)
condition|?
literal|64
else|:
literal|0
decl_stmt|;
name|QColor
name|slightlyOpaqueBlack
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|63
argument_list|)
decl_stmt|;
name|QColor
name|semiTransparentWhite
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|127
operator|+
name|delta
argument_list|)
decl_stmt|;
name|QColor
name|semiTransparentBlack
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|127
operator|-
name|delta
argument_list|)
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|width
decl_stmt|,
name|height
decl_stmt|;
name|option
operator|->
name|rect
operator|.
name|getRect
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|y
argument_list|,
operator|&
name|width
argument_list|,
operator|&
name|height
argument_list|)
expr_stmt|;
comment|//! [12]
comment|//! [13]
name|QPainterPath
name|roundRect
init|=
name|roundRectPath
argument_list|(
name|option
operator|->
name|rect
argument_list|)
decl_stmt|;
comment|//! [13] //! [14]
name|int
name|radius
init|=
name|qMin
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
operator|/
literal|2
decl_stmt|;
comment|//! [14]
comment|//! [15]
name|QBrush
name|brush
decl_stmt|;
comment|//! [15] //! [16]
name|bool
name|darker
decl_stmt|;
specifier|const
name|QStyleOptionButton
modifier|*
name|buttonOption
init|=
name|qstyleoption_cast
argument_list|<
specifier|const
name|QStyleOptionButton
operator|*
argument_list|>
argument_list|(
name|option
argument_list|)
decl_stmt|;
if|if
condition|(
name|buttonOption
operator|&&
operator|(
name|buttonOption
operator|->
name|features
operator|&
name|QStyleOptionButton
operator|::
name|Flat
operator|)
condition|)
block|{
name|brush
operator|=
name|option
operator|->
name|palette
operator|.
name|background
argument_list|()
expr_stmt|;
name|darker
operator|=
operator|(
name|option
operator|->
name|state
operator|&
operator|(
name|State_Sunken
operator||
name|State_On
operator|)
operator|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|option
operator|->
name|state
operator|&
operator|(
name|State_Sunken
operator||
name|State_On
operator|)
condition|)
block|{
name|brush
operator|=
name|option
operator|->
name|palette
operator|.
name|mid
argument_list|()
expr_stmt|;
name|darker
operator|=
operator|!
operator|(
name|option
operator|->
name|state
operator|&
name|State_Sunken
operator|)
expr_stmt|;
block|}
else|else
block|{
name|brush
operator|=
name|option
operator|->
name|palette
operator|.
name|button
argument_list|()
expr_stmt|;
name|darker
operator|=
literal|false
expr_stmt|;
comment|//! [16] //! [17]
block|}
comment|//! [17] //! [18]
block|}
comment|//! [18]
comment|//! [19]
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
comment|//! [19] //! [20]
name|painter
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|//! [20] //! [21]
name|painter
operator|->
name|fillPath
argument_list|(
name|roundRect
argument_list|,
name|brush
argument_list|)
expr_stmt|;
comment|//! [21] //! [22]
if|if
condition|(
name|darker
condition|)
comment|//! [22] //! [23]
name|painter
operator|->
name|fillPath
argument_list|(
name|roundRect
argument_list|,
name|slightlyOpaqueBlack
argument_list|)
expr_stmt|;
comment|//! [23]
comment|//! [24]
name|int
name|penWidth
decl_stmt|;
comment|//! [24] //! [25]
if|if
condition|(
name|radius
operator|<
literal|10
condition|)
name|penWidth
operator|=
literal|3
expr_stmt|;
elseif|else
if|if
condition|(
name|radius
operator|<
literal|20
condition|)
name|penWidth
operator|=
literal|5
expr_stmt|;
else|else
name|penWidth
operator|=
literal|7
expr_stmt|;
name|QPen
name|topPen
argument_list|(
name|semiTransparentWhite
argument_list|,
name|penWidth
argument_list|)
decl_stmt|;
name|QPen
name|bottomPen
argument_list|(
name|semiTransparentBlack
argument_list|,
name|penWidth
argument_list|)
decl_stmt|;
if|if
condition|(
name|option
operator|->
name|state
operator|&
operator|(
name|State_Sunken
operator||
name|State_On
operator|)
condition|)
name|qSwap
argument_list|(
name|topPen
argument_list|,
name|bottomPen
argument_list|)
expr_stmt|;
comment|//! [25]
comment|//! [26]
name|int
name|x1
init|=
name|x
decl_stmt|;
name|int
name|x2
init|=
name|x
operator|+
name|radius
decl_stmt|;
name|int
name|x3
init|=
name|x
operator|+
name|width
operator|-
name|radius
decl_stmt|;
name|int
name|x4
init|=
name|x
operator|+
name|width
decl_stmt|;
if|if
condition|(
name|option
operator|->
name|direction
operator|==
name|Qt
operator|::
name|RightToLeft
condition|)
block|{
name|qSwap
argument_list|(
name|x1
argument_list|,
name|x4
argument_list|)
expr_stmt|;
name|qSwap
argument_list|(
name|x2
argument_list|,
name|x3
argument_list|)
expr_stmt|;
block|}
name|QPolygon
name|topHalf
decl_stmt|;
name|topHalf
operator|<<
name|QPoint
argument_list|(
name|x1
argument_list|,
name|y
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|x4
argument_list|,
name|y
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|x3
argument_list|,
name|y
operator|+
name|radius
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|x2
argument_list|,
name|y
operator|+
name|height
operator|-
name|radius
argument_list|)
operator|<<
name|QPoint
argument_list|(
name|x1
argument_list|,
name|y
operator|+
name|height
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setClipPath
argument_list|(
name|roundRect
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setClipRegion
argument_list|(
name|topHalf
argument_list|,
name|Qt
operator|::
name|IntersectClip
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|topPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPath
argument_list|(
name|roundRect
argument_list|)
expr_stmt|;
comment|//! [26] //! [32]
name|QPolygon
name|bottomHalf
init|=
name|topHalf
decl_stmt|;
name|bottomHalf
index|[
literal|0
index|]
operator|=
name|QPoint
argument_list|(
name|x4
argument_list|,
name|y
operator|+
name|height
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setClipPath
argument_list|(
name|roundRect
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setClipRegion
argument_list|(
name|bottomHalf
argument_list|,
name|Qt
operator|::
name|IntersectClip
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|bottomPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPath
argument_list|(
name|roundRect
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|option
operator|->
name|palette
operator|.
name|foreground
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setClipping
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPath
argument_list|(
name|roundRect
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
break|break;
comment|//! [32] //! [33]
default|default:
comment|//! [33] //! [34]
name|QWindowsStyle
operator|::
name|drawPrimitive
argument_list|(
name|element
argument_list|,
name|option
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [34]
end_comment
begin_comment
comment|//! [35]
end_comment
begin_function
DECL|function|drawControl
name|void
name|NorwegianWoodStyle
operator|::
name|drawControl
parameter_list|(
name|ControlElement
name|element
parameter_list|,
comment|//! [35] //! [36]
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|element
condition|)
block|{
case|case
name|CE_PushButtonLabel
case|:
block|{
name|QStyleOptionButton
name|myButtonOption
decl_stmt|;
specifier|const
name|QStyleOptionButton
modifier|*
name|buttonOption
init|=
name|qstyleoption_cast
argument_list|<
specifier|const
name|QStyleOptionButton
operator|*
argument_list|>
argument_list|(
name|option
argument_list|)
decl_stmt|;
if|if
condition|(
name|buttonOption
condition|)
block|{
name|myButtonOption
operator|=
operator|*
name|buttonOption
expr_stmt|;
if|if
condition|(
name|myButtonOption
operator|.
name|palette
operator|.
name|currentColorGroup
argument_list|()
operator|!=
name|QPalette
operator|::
name|Disabled
condition|)
block|{
if|if
condition|(
name|myButtonOption
operator|.
name|state
operator|&
operator|(
name|State_Sunken
operator||
name|State_On
operator|)
condition|)
block|{
name|myButtonOption
operator|.
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|myButtonOption
operator|.
name|palette
operator|.
name|brightText
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|QWindowsStyle
operator|::
name|drawControl
argument_list|(
name|element
argument_list|,
operator|&
name|myButtonOption
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|QWindowsStyle
operator|::
name|drawControl
argument_list|(
name|element
argument_list|,
name|option
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [36]
end_comment
begin_comment
comment|//! [37]
end_comment
begin_function
DECL|function|setTexture
name|void
name|NorwegianWoodStyle
operator|::
name|setTexture
parameter_list|(
name|QPalette
modifier|&
name|palette
parameter_list|,
name|QPalette
operator|::
name|ColorRole
name|role
parameter_list|,
comment|//! [37] //! [38]
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QPalette
operator|::
name|NColorGroups
condition|;
operator|++
name|i
control|)
block|{
name|QColor
name|color
init|=
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|ColorGroup
argument_list|(
name|i
argument_list|)
argument_list|,
name|role
argument_list|)
operator|.
name|color
argument_list|()
decl_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|ColorGroup
argument_list|(
name|i
argument_list|)
argument_list|,
name|role
argument_list|,
name|QBrush
argument_list|(
name|color
argument_list|,
name|pixmap
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [38]
end_comment
begin_comment
comment|//! [39]
end_comment
begin_function
DECL|function|roundRectPath
name|QPainterPath
name|NorwegianWoodStyle
operator|::
name|roundRectPath
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
comment|//! [39] //! [40]
block|{
name|int
name|radius
init|=
name|qMin
argument_list|(
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|)
operator|/
literal|2
decl_stmt|;
name|int
name|diam
init|=
literal|2
operator|*
name|radius
decl_stmt|;
name|int
name|x1
decl_stmt|,
name|y1
decl_stmt|,
name|x2
decl_stmt|,
name|y2
decl_stmt|;
name|rect
operator|.
name|getCoords
argument_list|(
operator|&
name|x1
argument_list|,
operator|&
name|y1
argument_list|,
operator|&
name|x2
argument_list|,
operator|&
name|y2
argument_list|)
expr_stmt|;
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|moveTo
argument_list|(
name|x2
argument_list|,
name|y1
operator|+
name|radius
argument_list|)
expr_stmt|;
name|path
operator|.
name|arcTo
argument_list|(
name|QRect
argument_list|(
name|x2
operator|-
name|diam
argument_list|,
name|y1
argument_list|,
name|diam
argument_list|,
name|diam
argument_list|)
argument_list|,
literal|0.0
argument_list|,
operator|+
literal|90.0
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
name|x1
operator|+
name|radius
argument_list|,
name|y1
argument_list|)
expr_stmt|;
name|path
operator|.
name|arcTo
argument_list|(
name|QRect
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
name|diam
argument_list|,
name|diam
argument_list|)
argument_list|,
literal|90.0
argument_list|,
operator|+
literal|90.0
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
name|x1
argument_list|,
name|y2
operator|-
name|radius
argument_list|)
expr_stmt|;
name|path
operator|.
name|arcTo
argument_list|(
name|QRect
argument_list|(
name|x1
argument_list|,
name|y2
operator|-
name|diam
argument_list|,
name|diam
argument_list|,
name|diam
argument_list|)
argument_list|,
literal|180.0
argument_list|,
operator|+
literal|90.0
argument_list|)
expr_stmt|;
name|path
operator|.
name|lineTo
argument_list|(
name|x1
operator|+
name|radius
argument_list|,
name|y2
argument_list|)
expr_stmt|;
name|path
operator|.
name|arcTo
argument_list|(
name|QRect
argument_list|(
name|x2
operator|-
name|diam
argument_list|,
name|y2
operator|-
name|diam
argument_list|,
name|diam
argument_list|,
name|diam
argument_list|)
argument_list|,
literal|270.0
argument_list|,
operator|+
literal|90.0
argument_list|)
expr_stmt|;
name|path
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
return|return
name|path
return|;
block|}
end_function
begin_comment
comment|//! [40]
end_comment
end_unit
