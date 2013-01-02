begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//Own
end_comment
begin_include
include|#
directive|include
file|"graphicsscene.h"
end_include
begin_include
include|#
directive|include
file|"states.h"
end_include
begin_include
include|#
directive|include
file|"boat.h"
end_include
begin_include
include|#
directive|include
file|"submarine.h"
end_include
begin_include
include|#
directive|include
file|"torpedo.h"
end_include
begin_include
include|#
directive|include
file|"bomb.h"
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
begin_include
include|#
directive|include
file|"progressitem.h"
end_include
begin_include
include|#
directive|include
file|"textinformationitem.h"
end_include
begin_comment
comment|//Qt
end_comment
begin_include
include|#
directive|include
file|<QtCore/QPropertyAnimation>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSequentialAnimationGroup>
end_include
begin_include
include|#
directive|include
file|<QtCore/QParallelAnimationGroup>
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
file|<QtCore/QPauseAnimation>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QAction>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QMessageBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsSceneMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QXmlStreamReader>
end_include
begin_constructor
DECL|function|GraphicsScene
name|GraphicsScene
operator|::
name|GraphicsScene
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|Mode
name|mode
parameter_list|)
member_init_list|:
name|QGraphicsScene
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
member_init_list|,
name|mode
argument_list|(
name|mode
argument_list|)
member_init_list|,
name|boat
argument_list|(
operator|new
name|Boat
argument_list|)
block|{
name|PixmapItem
modifier|*
name|backgroundItem
init|=
operator|new
name|PixmapItem
argument_list|(
name|QString
argument_list|(
literal|"background"
argument_list|)
argument_list|,
name|mode
argument_list|)
decl_stmt|;
name|backgroundItem
operator|->
name|setZValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|backgroundItem
operator|->
name|setPos
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|addItem
argument_list|(
name|backgroundItem
argument_list|)
expr_stmt|;
name|PixmapItem
modifier|*
name|surfaceItem
init|=
operator|new
name|PixmapItem
argument_list|(
name|QString
argument_list|(
literal|"surface"
argument_list|)
argument_list|,
name|mode
argument_list|)
decl_stmt|;
name|surfaceItem
operator|->
name|setZValue
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|surfaceItem
operator|->
name|setPos
argument_list|(
literal|0
argument_list|,
name|sealLevel
argument_list|()
operator|-
name|surfaceItem
operator|->
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|addItem
argument_list|(
name|surfaceItem
argument_list|)
expr_stmt|;
comment|//The item that display score and level
name|progressItem
operator|=
operator|new
name|ProgressItem
argument_list|(
name|backgroundItem
argument_list|)
expr_stmt|;
name|textInformationItem
operator|=
operator|new
name|TextInformationItem
argument_list|(
name|backgroundItem
argument_list|)
expr_stmt|;
name|textInformationItem
operator|->
name|hide
argument_list|()
expr_stmt|;
comment|//We create the boat
name|addItem
argument_list|(
name|boat
argument_list|)
expr_stmt|;
name|boat
operator|->
name|setPos
argument_list|(
name|this
operator|->
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|sealLevel
argument_list|()
operator|-
name|boat
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|boat
operator|->
name|hide
argument_list|()
expr_stmt|;
comment|//parse the xml that contain all data of the game
name|QXmlStreamReader
name|reader
decl_stmt|;
name|QFile
name|file
argument_list|(
literal|":data.xml"
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|reader
operator|.
name|setDevice
argument_list|(
operator|&
name|file
argument_list|)
expr_stmt|;
name|LevelDescription
name|currentLevel
decl_stmt|;
while|while
condition|(
operator|!
name|reader
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|reader
operator|.
name|readNext
argument_list|()
expr_stmt|;
if|if
condition|(
name|reader
operator|.
name|tokenType
argument_list|()
operator|==
name|QXmlStreamReader
operator|::
name|StartElement
condition|)
block|{
if|if
condition|(
name|reader
operator|.
name|name
argument_list|()
operator|==
literal|"submarine"
condition|)
block|{
name|SubmarineDescription
name|desc
decl_stmt|;
name|desc
operator|.
name|name
operator|=
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"name"
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|desc
operator|.
name|points
operator|=
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"points"
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|desc
operator|.
name|type
operator|=
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"type"
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|submarinesData
operator|.
name|append
argument_list|(
name|desc
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|reader
operator|.
name|name
argument_list|()
operator|==
literal|"level"
condition|)
block|{
name|currentLevel
operator|.
name|id
operator|=
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"id"
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|currentLevel
operator|.
name|name
operator|=
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"name"
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|reader
operator|.
name|name
argument_list|()
operator|==
literal|"subinstance"
condition|)
block|{
name|currentLevel
operator|.
name|submarines
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"type"
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|,
name|reader
operator|.
name|attributes
argument_list|()
operator|.
name|value
argument_list|(
literal|"nb"
argument_list|)
operator|.
name|toString
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|reader
operator|.
name|tokenType
argument_list|()
operator|==
name|QXmlStreamReader
operator|::
name|EndElement
condition|)
block|{
if|if
condition|(
name|reader
operator|.
name|name
argument_list|()
operator|==
literal|"level"
condition|)
block|{
name|levelsData
operator|.
name|insert
argument_list|(
name|currentLevel
operator|.
name|id
argument_list|,
name|currentLevel
argument_list|)
expr_stmt|;
name|currentLevel
operator|.
name|submarines
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
end_constructor
begin_function
DECL|function|sealLevel
name|qreal
name|GraphicsScene
operator|::
name|sealLevel
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|mode
operator|==
name|Big
operator|)
condition|?
literal|220
else|:
literal|160
return|;
block|}
end_function
begin_function
DECL|function|setupScene
name|void
name|GraphicsScene
operator|::
name|setupScene
parameter_list|(
name|QAction
modifier|*
name|newAction
parameter_list|,
name|QAction
modifier|*
name|quitAction
parameter_list|)
block|{
specifier|static
specifier|const
name|int
name|nLetters
init|=
literal|10
decl_stmt|;
specifier|static
struct|struct
block|{
name|char
specifier|const
modifier|*
name|pix
decl_stmt|;
name|qreal
name|initX
decl_stmt|,
name|initY
decl_stmt|;
name|qreal
name|destX
decl_stmt|,
name|destY
decl_stmt|;
block|}
name|logoData
index|[
name|nLetters
index|]
init|=
block|{
block|{
literal|"s"
block|,
operator|-
literal|1000
block|,
operator|-
literal|1000
block|,
literal|300
block|,
literal|150
block|}
block|,
block|{
literal|"u"
block|,
operator|-
literal|800
block|,
operator|-
literal|1000
block|,
literal|350
block|,
literal|150
block|}
block|,
block|{
literal|"b"
block|,
operator|-
literal|600
block|,
operator|-
literal|1000
block|,
literal|400
block|,
literal|120
block|}
block|,
block|{
literal|"dash"
block|,
operator|-
literal|400
block|,
operator|-
literal|1000
block|,
literal|460
block|,
literal|150
block|}
block|,
block|{
literal|"a"
block|,
literal|1000
block|,
literal|2000
block|,
literal|350
block|,
literal|250
block|}
block|,
block|{
literal|"t"
block|,
literal|800
block|,
literal|2000
block|,
literal|400
block|,
literal|250
block|}
block|,
block|{
literal|"t2"
block|,
literal|600
block|,
literal|2000
block|,
literal|430
block|,
literal|250
block|}
block|,
block|{
literal|"a2"
block|,
literal|400
block|,
literal|2000
block|,
literal|465
block|,
literal|250
block|}
block|,
block|{
literal|"q"
block|,
literal|200
block|,
literal|2000
block|,
literal|510
block|,
literal|250
block|}
block|,
block|{
literal|"excl"
block|,
literal|0
block|,
literal|2000
block|,
literal|570
block|,
literal|220
block|}
block|}
struct|;
name|QSequentialAnimationGroup
modifier|*
name|lettersGroupMoving
init|=
operator|new
name|QSequentialAnimationGroup
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QParallelAnimationGroup
modifier|*
name|lettersGroupFading
init|=
operator|new
name|QParallelAnimationGroup
argument_list|(
name|this
argument_list|)
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
name|nLetters
condition|;
operator|++
name|i
control|)
block|{
name|PixmapItem
modifier|*
name|logo
init|=
operator|new
name|PixmapItem
argument_list|(
name|QLatin1String
argument_list|(
literal|":/logo-"
argument_list|)
operator|+
name|logoData
index|[
name|i
index|]
operator|.
name|pix
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|logo
operator|->
name|setPos
argument_list|(
name|logoData
index|[
name|i
index|]
operator|.
name|initX
argument_list|,
name|logoData
index|[
name|i
index|]
operator|.
name|initY
argument_list|)
expr_stmt|;
name|logo
operator|->
name|setZValue
argument_list|(
name|i
operator|+
literal|3
argument_list|)
expr_stmt|;
comment|//creation of the animations for moving letters
name|QPropertyAnimation
modifier|*
name|moveAnim
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|logo
argument_list|,
literal|"pos"
argument_list|,
name|lettersGroupMoving
argument_list|)
decl_stmt|;
name|moveAnim
operator|->
name|setEndValue
argument_list|(
name|QPointF
argument_list|(
name|logoData
index|[
name|i
index|]
operator|.
name|destX
argument_list|,
name|logoData
index|[
name|i
index|]
operator|.
name|destY
argument_list|)
argument_list|)
expr_stmt|;
name|moveAnim
operator|->
name|setDuration
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|moveAnim
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|OutElastic
argument_list|)
expr_stmt|;
name|lettersGroupMoving
operator|->
name|addPause
argument_list|(
literal|50
argument_list|)
expr_stmt|;
comment|//creation of the animations for fading out the letters
name|QPropertyAnimation
modifier|*
name|fadeAnim
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|logo
argument_list|,
literal|"opacity"
argument_list|,
name|lettersGroupFading
argument_list|)
decl_stmt|;
name|fadeAnim
operator|->
name|setDuration
argument_list|(
literal|800
argument_list|)
expr_stmt|;
name|fadeAnim
operator|->
name|setEndValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|fadeAnim
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|OutQuad
argument_list|)
expr_stmt|;
block|}
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
comment|//This state is when the player is playing
name|PlayState
modifier|*
name|gameState
init|=
operator|new
name|PlayState
argument_list|(
name|this
argument_list|,
name|machine
argument_list|)
decl_stmt|;
comment|//Final state
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
comment|//Animation when the player enter in the game
name|QAnimationState
modifier|*
name|lettersMovingState
init|=
operator|new
name|QAnimationState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
name|lettersMovingState
operator|->
name|setAnimation
argument_list|(
name|lettersGroupMoving
argument_list|)
expr_stmt|;
comment|//Animation when the welcome screen disappear
name|QAnimationState
modifier|*
name|lettersFadingState
init|=
operator|new
name|QAnimationState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
name|lettersFadingState
operator|->
name|setAnimation
argument_list|(
name|lettersGroupFading
argument_list|)
expr_stmt|;
comment|//if new game then we fade out the welcome screen and start playing
name|lettersMovingState
operator|->
name|addTransition
argument_list|(
name|newAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|lettersFadingState
argument_list|)
expr_stmt|;
name|lettersFadingState
operator|->
name|addTransition
argument_list|(
name|lettersFadingState
argument_list|,
name|SIGNAL
argument_list|(
name|animationFinished
argument_list|()
argument_list|)
argument_list|,
name|gameState
argument_list|)
expr_stmt|;
comment|//New Game is triggered then player start playing
name|gameState
operator|->
name|addTransition
argument_list|(
name|newAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|gameState
argument_list|)
expr_stmt|;
comment|//Wanna quit, then connect to CTRL+Q
name|gameState
operator|->
name|addTransition
argument_list|(
name|quitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|final
argument_list|)
expr_stmt|;
name|lettersMovingState
operator|->
name|addTransition
argument_list|(
name|quitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|final
argument_list|)
expr_stmt|;
comment|//Welcome screen is the initial state
name|machine
operator|->
name|setInitialState
argument_list|(
name|lettersMovingState
argument_list|)
expr_stmt|;
name|machine
operator|->
name|start
argument_list|()
expr_stmt|;
comment|//We reach the final state, then we quit
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
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addItem
name|void
name|GraphicsScene
operator|::
name|addItem
parameter_list|(
name|Bomb
modifier|*
name|bomb
parameter_list|)
block|{
name|bombs
operator|.
name|insert
argument_list|(
name|bomb
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|bomb
argument_list|,
name|SIGNAL
argument_list|(
name|bombExecutionFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onBombExecutionFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QGraphicsScene
operator|::
name|addItem
argument_list|(
name|bomb
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addItem
name|void
name|GraphicsScene
operator|::
name|addItem
parameter_list|(
name|Torpedo
modifier|*
name|torpedo
parameter_list|)
block|{
name|torpedos
operator|.
name|insert
argument_list|(
name|torpedo
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|torpedo
argument_list|,
name|SIGNAL
argument_list|(
name|torpedoExecutionFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onTorpedoExecutionFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QGraphicsScene
operator|::
name|addItem
argument_list|(
name|torpedo
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addItem
name|void
name|GraphicsScene
operator|::
name|addItem
parameter_list|(
name|SubMarine
modifier|*
name|submarine
parameter_list|)
block|{
name|submarines
operator|.
name|insert
argument_list|(
name|submarine
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|submarine
argument_list|,
name|SIGNAL
argument_list|(
name|subMarineExecutionFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onSubMarineExecutionFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QGraphicsScene
operator|::
name|addItem
argument_list|(
name|submarine
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addItem
name|void
name|GraphicsScene
operator|::
name|addItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|item
parameter_list|)
block|{
name|QGraphicsScene
operator|::
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onBombExecutionFinished
name|void
name|GraphicsScene
operator|::
name|onBombExecutionFinished
parameter_list|()
block|{
name|Bomb
modifier|*
name|bomb
init|=
name|qobject_cast
argument_list|<
name|Bomb
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|bombs
operator|.
name|remove
argument_list|(
name|bomb
argument_list|)
expr_stmt|;
name|bomb
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
if|if
condition|(
name|boat
condition|)
name|boat
operator|->
name|setBombsLaunched
argument_list|(
name|boat
operator|->
name|bombsLaunched
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onTorpedoExecutionFinished
name|void
name|GraphicsScene
operator|::
name|onTorpedoExecutionFinished
parameter_list|()
block|{
name|Torpedo
modifier|*
name|torpedo
init|=
name|qobject_cast
argument_list|<
name|Torpedo
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|torpedos
operator|.
name|remove
argument_list|(
name|torpedo
argument_list|)
expr_stmt|;
name|torpedo
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onSubMarineExecutionFinished
name|void
name|GraphicsScene
operator|::
name|onSubMarineExecutionFinished
parameter_list|()
block|{
name|SubMarine
modifier|*
name|submarine
init|=
name|qobject_cast
argument_list|<
name|SubMarine
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|submarines
operator|.
name|remove
argument_list|(
name|submarine
argument_list|)
expr_stmt|;
if|if
condition|(
name|submarines
operator|.
name|count
argument_list|()
operator|==
literal|0
condition|)
emit|emit
name|allSubMarineDestroyed
argument_list|(
name|submarine
operator|->
name|points
argument_list|()
argument_list|)
emit|;
else|else
emit|emit
name|subMarineDestroyed
argument_list|(
name|submarine
operator|->
name|points
argument_list|()
argument_list|)
emit|;
name|submarine
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearScene
name|void
name|GraphicsScene
operator|::
name|clearScene
parameter_list|()
block|{
foreach|foreach
control|(
name|SubMarine
modifier|*
name|sub
decl|,
name|submarines
control|)
block|{
name|sub
operator|->
name|destroy
argument_list|()
expr_stmt|;
name|sub
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
foreach|foreach
control|(
name|Torpedo
modifier|*
name|torpedo
decl|,
name|torpedos
control|)
block|{
name|torpedo
operator|->
name|destroy
argument_list|()
expr_stmt|;
name|torpedo
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
foreach|foreach
control|(
name|Bomb
modifier|*
name|bomb
decl|,
name|bombs
control|)
block|{
name|bomb
operator|->
name|destroy
argument_list|()
expr_stmt|;
name|bomb
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
name|submarines
operator|.
name|clear
argument_list|()
expr_stmt|;
name|bombs
operator|.
name|clear
argument_list|()
expr_stmt|;
name|torpedos
operator|.
name|clear
argument_list|()
expr_stmt|;
name|AnimationManager
operator|::
name|self
argument_list|()
operator|->
name|unregisterAllAnimations
argument_list|()
expr_stmt|;
name|boat
operator|->
name|stop
argument_list|()
expr_stmt|;
name|boat
operator|->
name|hide
argument_list|()
expr_stmt|;
name|boat
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
