begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|STATES_H
end_ifndef
begin_define
DECL|macro|STATES_H
define|#
directive|define
name|STATES_H
end_define
begin_comment
comment|//Qt
end_comment
begin_include
include|#
directive|include
file|<QtCore/QState>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSignalTransition>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPropertyAnimation>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QKeyEventTransition>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSet>
end_include
begin_decl_stmt
DECL|variable|GraphicsScene
name|class
name|GraphicsScene
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Boat
name|class
name|Boat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|SubMarine
name|class
name|SubMarine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QStateMachine
name|class
name|QStateMachine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|PlayState
range|:
name|public
name|QState
block|{
name|public
operator|:
name|PlayState
argument_list|(
name|GraphicsScene
operator|*
name|scene
argument_list|,
name|QState
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|PlayState
argument_list|()
block|;
name|protected
operator|:
name|void
name|onEntry
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|GraphicsScene
operator|*
name|scene
block|;
name|QStateMachine
operator|*
name|machine
block|;
name|int
name|currentLevel
block|;
name|int
name|score
block|;
name|QState
operator|*
name|parallelChild
block|;
name|friend
name|class
name|UpdateScoreState
block|;
name|friend
name|class
name|UpdateScoreTransition
block|;
name|friend
name|class
name|WinTransition
block|;
name|friend
name|class
name|CustomSpaceTransition
block|;
name|friend
name|class
name|WinState
block|;
name|friend
name|class
name|LostState
block|;
name|friend
name|class
name|LevelState
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|LevelState
range|:
name|public
name|QState
block|{
name|public
operator|:
name|LevelState
argument_list|(
name|GraphicsScene
operator|*
name|scene
argument_list|,
name|PlayState
operator|*
name|game
argument_list|,
name|QState
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|protected
operator|:
name|void
name|onEntry
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|void
name|initializeLevel
argument_list|()
block|;
name|GraphicsScene
operator|*
name|scene
block|;
name|PlayState
operator|*
name|game
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|PauseState
range|:
name|public
name|QState
block|{
name|public
operator|:
name|PauseState
argument_list|(
name|GraphicsScene
operator|*
name|scene
argument_list|,
name|QState
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|protected
operator|:
name|void
name|onEntry
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|onExit
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|GraphicsScene
operator|*
name|scene
block|;
name|Boat
operator|*
name|boat
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|LostState
range|:
name|public
name|QState
block|{
name|public
operator|:
name|LostState
argument_list|(
name|GraphicsScene
operator|*
name|scene
argument_list|,
name|PlayState
operator|*
name|game
argument_list|,
name|QState
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|protected
operator|:
name|void
name|onEntry
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|onExit
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|GraphicsScene
operator|*
name|scene
block|;
name|PlayState
operator|*
name|game
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|WinState
range|:
name|public
name|QState
block|{
name|public
operator|:
name|WinState
argument_list|(
name|GraphicsScene
operator|*
name|scene
argument_list|,
name|PlayState
operator|*
name|game
argument_list|,
name|QState
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|protected
operator|:
name|void
name|onEntry
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|onExit
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|GraphicsScene
operator|*
name|scene
block|;
name|PlayState
operator|*
name|game
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|UpdateScoreState
range|:
name|public
name|QState
block|{
name|public
operator|:
name|UpdateScoreState
argument_list|(
name|PlayState
operator|*
name|game
argument_list|,
name|QState
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|QPropertyAnimation
operator|*
name|scoreAnimation
block|;
name|PlayState
operator|*
name|game
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//These transtion is used to update the score
end_comment
begin_decl_stmt
name|class
name|UpdateScoreTransition
range|:
name|public
name|QSignalTransition
block|{
name|public
operator|:
name|UpdateScoreTransition
argument_list|(
name|GraphicsScene
operator|*
name|scene
argument_list|,
name|PlayState
operator|*
name|game
argument_list|,
name|QAbstractState
operator|*
name|target
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|eventTest
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|PlayState
operator|*
name|game
block|;
name|GraphicsScene
operator|*
name|scene
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//These transtion test if we have won the game
end_comment
begin_decl_stmt
name|class
name|WinTransition
range|:
name|public
name|QSignalTransition
block|{
name|public
operator|:
name|WinTransition
argument_list|(
name|GraphicsScene
operator|*
name|scene
argument_list|,
name|PlayState
operator|*
name|game
argument_list|,
name|QAbstractState
operator|*
name|target
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|eventTest
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|PlayState
operator|*
name|game
block|;
name|GraphicsScene
operator|*
name|scene
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//These transtion is true if one level has been completed and the player want to continue
end_comment
begin_decl_stmt
name|class
name|CustomSpaceTransition
range|:
name|public
name|QKeyEventTransition
block|{
name|public
operator|:
name|CustomSpaceTransition
argument_list|(
argument|QWidget *widget
argument_list|,
argument|PlayState *game
argument_list|,
argument|QEvent::Type type
argument_list|,
argument|int key
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|eventTest
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|PlayState
operator|*
name|game
block|;
name|int
name|key
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// STATES_H
end_comment
end_unit
