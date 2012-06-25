begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"knob.h"
end_include
begin_include
include|#
directive|include
file|<QBrush>
end_include
begin_include
include|#
directive|include
file|<QTouchEvent>
end_include
begin_constructor
DECL|function|Knob
name|Knob
operator|::
name|Knob
parameter_list|()
member_init_list|:
name|QGraphicsEllipseItem
argument_list|(
operator|-
literal|50
argument_list|,
operator|-
literal|50
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
block|{
name|setAcceptTouchEvents
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setBrush
argument_list|(
name|Qt
operator|::
name|lightGray
argument_list|)
expr_stmt|;
name|QGraphicsEllipseItem
modifier|*
name|leftItem
init|=
operator|new
name|QGraphicsEllipseItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|leftItem
operator|->
name|setPos
argument_list|(
operator|-
literal|40
argument_list|,
operator|-
literal|10
argument_list|)
expr_stmt|;
name|leftItem
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
name|QGraphicsEllipseItem
modifier|*
name|rightItem
init|=
operator|new
name|QGraphicsEllipseItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|rightItem
operator|->
name|setPos
argument_list|(
literal|20
argument_list|,
operator|-
literal|10
argument_list|)
expr_stmt|;
name|rightItem
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|darkRed
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|sceneEvent
name|bool
name|Knob
operator|::
name|sceneEvent
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
name|TouchBegin
case|:
case|case
name|QEvent
operator|::
name|TouchUpdate
case|:
case|case
name|QEvent
operator|::
name|TouchEnd
case|:
block|{
name|QTouchEvent
modifier|*
name|touchEvent
init|=
cast|static_cast
argument_list|<
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|touchEvent
operator|->
name|touchPoints
argument_list|()
operator|.
name|count
argument_list|()
operator|==
literal|2
condition|)
block|{
specifier|const
name|QTouchEvent
operator|::
name|TouchPoint
modifier|&
name|touchPoint1
init|=
name|touchEvent
operator|->
name|touchPoints
argument_list|()
operator|.
name|first
argument_list|()
decl_stmt|;
specifier|const
name|QTouchEvent
operator|::
name|TouchPoint
modifier|&
name|touchPoint2
init|=
name|touchEvent
operator|->
name|touchPoints
argument_list|()
operator|.
name|last
argument_list|()
decl_stmt|;
name|QLineF
name|line1
argument_list|(
name|touchPoint1
operator|.
name|lastScenePos
argument_list|()
argument_list|,
name|touchPoint2
operator|.
name|lastScenePos
argument_list|()
argument_list|)
decl_stmt|;
name|QLineF
name|line2
argument_list|(
name|touchPoint1
operator|.
name|scenePos
argument_list|()
argument_list|,
name|touchPoint2
operator|.
name|scenePos
argument_list|()
argument_list|)
decl_stmt|;
name|setTransform
argument_list|(
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
name|line2
operator|.
name|angleTo
argument_list|(
name|line1
argument_list|)
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
default|default:
return|return
name|QGraphicsItem
operator|::
name|sceneEvent
argument_list|(
name|event
argument_list|)
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
end_unit
