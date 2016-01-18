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
file|"submarine.h"
end_include
begin_include
include|#
directive|include
file|"submarine_p.h"
end_include
begin_include
include|#
directive|include
file|"torpedo.h"
end_include
begin_include
include|#
directive|include
file|"pixmapitem.h"
end_include
begin_include
include|#
directive|include
file|"graphicsscene.h"
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
begin_include
include|#
directive|include
file|<QtCore/QSequentialAnimationGroup>
end_include
begin_function
DECL|function|setupDestroyAnimation
specifier|static
name|QAbstractAnimation
modifier|*
name|setupDestroyAnimation
parameter_list|(
name|SubMarine
modifier|*
name|sub
parameter_list|)
block|{
name|QSequentialAnimationGroup
modifier|*
name|group
init|=
operator|new
name|QSequentialAnimationGroup
argument_list|(
name|sub
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|PixmapItem
modifier|*
name|step
init|=
operator|new
name|PixmapItem
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"explosion/submarine/step%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|,
name|GraphicsScene
operator|::
name|Big
argument_list|,
name|sub
argument_list|)
decl_stmt|;
name|step
operator|->
name|setZValue
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|step
operator|->
name|setOpacity
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|anim
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|step
argument_list|,
literal|"opacity"
argument_list|,
name|group
argument_list|)
decl_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setEndValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|AnimationManager
operator|::
name|self
argument_list|()
operator|->
name|registerAnimation
argument_list|(
name|group
argument_list|)
expr_stmt|;
return|return
name|group
return|;
block|}
end_function
begin_constructor
DECL|function|SubMarine
name|SubMarine
operator|::
name|SubMarine
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|int
name|points
parameter_list|)
member_init_list|:
name|PixmapItem
argument_list|(
name|QString
argument_list|(
literal|"submarine"
argument_list|)
argument_list|,
name|GraphicsScene
operator|::
name|Big
argument_list|)
member_init_list|,
name|subType
argument_list|(
name|type
argument_list|)
member_init_list|,
name|subName
argument_list|(
name|name
argument_list|)
member_init_list|,
name|subPoints
argument_list|(
name|points
argument_list|)
member_init_list|,
name|speed
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|direction
argument_list|(
name|SubMarine
operator|::
name|None
argument_list|)
block|{
name|setZValue
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|setTransformOriginPoint
argument_list|(
name|boundingRect
argument_list|()
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|graphicsRotation
operator|=
operator|new
name|QGraphicsRotation
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|graphicsRotation
operator|->
name|setAxis
argument_list|(
name|Qt
operator|::
name|YAxis
argument_list|)
expr_stmt|;
name|graphicsRotation
operator|->
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QGraphicsTransform
modifier|*
argument_list|>
name|r
decl_stmt|;
name|r
operator|.
name|append
argument_list|(
name|graphicsRotation
argument_list|)
expr_stmt|;
name|setTransformations
argument_list|(
name|r
argument_list|)
expr_stmt|;
comment|//We setup the state machine of the submarine
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
comment|//This state is when the boat is moving/rotating
name|QState
modifier|*
name|moving
init|=
operator|new
name|QState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
comment|//This state is when the boat is moving from left to right
name|MovementState
modifier|*
name|movement
init|=
operator|new
name|MovementState
argument_list|(
name|this
argument_list|,
name|moving
argument_list|)
decl_stmt|;
comment|//This state is when the boat is moving from left to right
name|ReturnState
modifier|*
name|rotation
init|=
operator|new
name|ReturnState
argument_list|(
name|this
argument_list|,
name|moving
argument_list|)
decl_stmt|;
comment|//This is the initial state of the moving root state
name|moving
operator|->
name|setInitialState
argument_list|(
name|movement
argument_list|)
expr_stmt|;
name|movement
operator|->
name|addTransition
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|subMarineStateChanged
argument_list|()
argument_list|)
argument_list|,
name|moving
argument_list|)
expr_stmt|;
comment|//This is the initial state of the machine
name|machine
operator|->
name|setInitialState
argument_list|(
name|moving
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
comment|//If the moving animation is finished we move to the return state
name|movement
operator|->
name|addTransition
argument_list|(
name|movement
argument_list|,
name|SIGNAL
argument_list|(
name|animationFinished
argument_list|()
argument_list|)
argument_list|,
name|rotation
argument_list|)
expr_stmt|;
comment|//If the return animation is finished we move to the moving state
name|rotation
operator|->
name|addTransition
argument_list|(
name|rotation
argument_list|,
name|SIGNAL
argument_list|(
name|animationFinished
argument_list|()
argument_list|)
argument_list|,
name|movement
argument_list|)
expr_stmt|;
comment|//This state play the destroyed animation
name|QAnimationState
modifier|*
name|destroyedState
init|=
operator|new
name|QAnimationState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
name|destroyedState
operator|->
name|setAnimation
argument_list|(
name|setupDestroyAnimation
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
comment|//Play a nice animation when the submarine is destroyed
name|moving
operator|->
name|addTransition
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|subMarineDestroyed
argument_list|()
argument_list|)
argument_list|,
name|destroyedState
argument_list|)
expr_stmt|;
comment|//Transition to final state when the destroyed animation is finished
name|destroyedState
operator|->
name|addTransition
argument_list|(
name|destroyedState
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
comment|//The machine has finished to be executed, then the submarine is dead
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
name|subMarineExecutionFinished
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
end_constructor
begin_function
DECL|function|points
name|int
name|SubMarine
operator|::
name|points
parameter_list|()
specifier|const
block|{
return|return
name|subPoints
return|;
block|}
end_function
begin_function
DECL|function|setCurrentDirection
name|void
name|SubMarine
operator|::
name|setCurrentDirection
parameter_list|(
name|SubMarine
operator|::
name|Movement
name|direction
parameter_list|)
block|{
if|if
condition|(
name|this
operator|->
name|direction
operator|==
name|direction
condition|)
return|return;
if|if
condition|(
name|direction
operator|==
name|SubMarine
operator|::
name|Right
operator|&&
name|this
operator|->
name|direction
operator|==
name|SubMarine
operator|::
name|None
condition|)
block|{
name|graphicsRotation
operator|->
name|setAngle
argument_list|(
literal|180
argument_list|)
expr_stmt|;
block|}
name|this
operator|->
name|direction
operator|=
name|direction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentDirection
name|enum
name|SubMarine
operator|::
name|Movement
name|SubMarine
operator|::
name|currentDirection
parameter_list|()
specifier|const
block|{
return|return
name|direction
return|;
block|}
end_function
begin_function
DECL|function|setCurrentSpeed
name|void
name|SubMarine
operator|::
name|setCurrentSpeed
parameter_list|(
name|int
name|speed
parameter_list|)
block|{
if|if
condition|(
name|speed
argument_list|<
literal|0
operator|||
name|speed
argument_list|>
literal|3
condition|)
block|{
name|qWarning
argument_list|(
literal|"SubMarine::setCurrentSpeed : The speed is invalid"
argument_list|)
expr_stmt|;
block|}
name|this
operator|->
name|speed
operator|=
name|speed
expr_stmt|;
emit|emit
name|subMarineStateChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|currentSpeed
name|int
name|SubMarine
operator|::
name|currentSpeed
parameter_list|()
specifier|const
block|{
return|return
name|speed
return|;
block|}
end_function
begin_function
DECL|function|launchTorpedo
name|void
name|SubMarine
operator|::
name|launchTorpedo
parameter_list|(
name|int
name|speed
parameter_list|)
block|{
name|Torpedo
modifier|*
name|torp
init|=
operator|new
name|Torpedo
argument_list|()
decl_stmt|;
name|GraphicsScene
modifier|*
name|scene
init|=
cast|static_cast
argument_list|<
name|GraphicsScene
operator|*
argument_list|>
argument_list|(
name|this
operator|->
name|scene
argument_list|()
argument_list|)
decl_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|torp
argument_list|)
expr_stmt|;
name|torp
operator|->
name|setPos
argument_list|(
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|torp
operator|->
name|setCurrentSpeed
argument_list|(
name|speed
argument_list|)
expr_stmt|;
name|torp
operator|->
name|launch
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|SubMarine
operator|::
name|destroy
parameter_list|()
block|{
emit|emit
name|subMarineDestroyed
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|type
name|int
name|SubMarine
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
end_function
end_unit
