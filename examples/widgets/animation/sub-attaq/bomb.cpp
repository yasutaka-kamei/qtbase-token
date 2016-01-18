begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//Own
end_comment
begin_include
include|#
directive|include
file|"bomb.h"
end_include
begin_include
include|#
directive|include
file|"submarine.h"
end_include
begin_include
include|#
directive|include
file|"pixmapitem.h"
end_include
begin_include
include|#
directive|include
file|"animationmanager.h"
end_include
begin_include
include|#
directive|include
file|"qanimationstate.h"
end_include
begin_comment
comment|//Qt
end_comment
begin_include
include|#
directive|include
file|<QtCore/QSequentialAnimationGroup>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPropertyAnimation>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStateMachine>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFinalState>
end_include
begin_constructor
DECL|function|Bomb
name|Bomb
operator|::
name|Bomb
parameter_list|()
member_init_list|:
name|PixmapItem
argument_list|(
name|QString
argument_list|(
literal|"bomb"
argument_list|)
argument_list|,
name|GraphicsScene
operator|::
name|Big
argument_list|)
block|{
name|setZValue
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|launch
name|void
name|Bomb
operator|::
name|launch
parameter_list|(
name|Bomb
operator|::
name|Direction
name|direction
parameter_list|)
block|{
name|QSequentialAnimationGroup
modifier|*
name|launchAnimation
init|=
operator|new
name|QSequentialAnimationGroup
decl_stmt|;
name|AnimationManager
operator|::
name|self
argument_list|()
operator|->
name|registerAnimation
argument_list|(
name|launchAnimation
argument_list|)
expr_stmt|;
name|qreal
name|delta
init|=
name|direction
operator|==
name|Right
condition|?
literal|20
else|:
operator|-
literal|20
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|anim
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|this
argument_list|,
literal|"pos"
argument_list|)
decl_stmt|;
name|anim
operator|->
name|setEndValue
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|()
operator|+
name|delta
argument_list|,
name|y
argument_list|()
operator|-
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
literal|150
argument_list|)
expr_stmt|;
name|launchAnimation
operator|->
name|addAnimation
argument_list|(
name|anim
argument_list|)
expr_stmt|;
name|anim
operator|=
operator|new
name|QPropertyAnimation
argument_list|(
name|this
argument_list|,
literal|"pos"
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setEndValue
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|()
operator|+
name|delta
operator|*
literal|2
argument_list|,
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
literal|150
argument_list|)
expr_stmt|;
name|launchAnimation
operator|->
name|addAnimation
argument_list|(
name|anim
argument_list|)
expr_stmt|;
name|anim
operator|=
operator|new
name|QPropertyAnimation
argument_list|(
name|this
argument_list|,
literal|"pos"
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setEndValue
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|()
operator|+
name|delta
operator|*
literal|2
argument_list|,
name|scene
argument_list|()
operator|->
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
name|y
argument_list|()
operator|/
literal|2
operator|*
literal|60
argument_list|)
expr_stmt|;
name|launchAnimation
operator|->
name|addAnimation
argument_list|(
name|anim
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|anim
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|QVariant
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onAnimationLaunchValueChanged
argument_list|(
name|QVariant
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|bombExploded
argument_list|()
argument_list|)
argument_list|,
name|launchAnimation
argument_list|,
name|SLOT
argument_list|(
name|stop
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//We setup the state machine of the bomb
name|QStateMachine
modifier|*
name|machine
init|=
operator|new
name|QStateMachine
argument_list|(
name|this
argument_list|)
decl_stmt|;
comment|//This state is when the launch animation is playing
name|QAnimationState
modifier|*
name|launched
init|=
operator|new
name|QAnimationState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
name|launched
operator|->
name|setAnimation
argument_list|(
name|launchAnimation
argument_list|)
expr_stmt|;
comment|//End
name|QFinalState
modifier|*
name|final
init|=
operator|new
name|QFinalState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
name|machine
operator|->
name|setInitialState
argument_list|(
name|launched
argument_list|)
expr_stmt|;
comment|//### Add a nice animation when the bomb is destroyed
name|launched
operator|->
name|addTransition
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|bombExploded
argument_list|()
argument_list|)
argument_list|,
name|final
argument_list|)
expr_stmt|;
comment|//If the animation is finished, then we move to the final state
name|launched
operator|->
name|addTransition
argument_list|(
name|launched
argument_list|,
name|SIGNAL
argument_list|(
name|animationFinished
argument_list|()
argument_list|)
argument_list|,
name|final
argument_list|)
expr_stmt|;
comment|//The machine has finished to be executed, then the boat is dead
name|connect
argument_list|(
name|machine
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|bombExecutionFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onAnimationLaunchValueChanged
name|void
name|Bomb
operator|::
name|onAnimationLaunchValueChanged
parameter_list|(
specifier|const
name|QVariant
modifier|&
parameter_list|)
block|{
foreach|foreach
control|(
name|QGraphicsItem
modifier|*
name|item
decl|,
name|collidingItems
argument_list|(
name|Qt
operator|::
name|IntersectsItemBoundingRect
argument_list|)
control|)
block|{
if|if
condition|(
name|item
operator|->
name|type
argument_list|()
operator|==
name|SubMarine
operator|::
name|Type
condition|)
block|{
name|SubMarine
modifier|*
name|s
init|=
cast|static_cast
argument_list|<
name|SubMarine
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
decl_stmt|;
name|destroy
argument_list|()
expr_stmt|;
name|s
operator|->
name|destroy
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|Bomb
operator|::
name|destroy
parameter_list|()
block|{
emit|emit
name|bombExploded
argument_list|()
emit|;
block|}
end_function
end_unit
