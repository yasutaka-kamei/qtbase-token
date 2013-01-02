begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__GRAPHICSSCENE__H__
end_ifndef
begin_define
DECL|macro|__GRAPHICSSCENE__H__
define|#
directive|define
name|__GRAPHICSSCENE__H__
end_define
begin_comment
comment|//Qt
end_comment
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSet>
end_include
begin_include
include|#
directive|include
file|<QtCore/QState>
end_include
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
DECL|variable|Torpedo
name|class
name|Torpedo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Bomb
name|class
name|Bomb
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|PixmapItem
name|class
name|PixmapItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ProgressItem
name|class
name|ProgressItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TextInformationItem
name|class
name|TextInformationItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|GraphicsScene
range|:
name|public
name|QGraphicsScene
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Mode
block|{
name|Big
operator|=
literal|0
block|,
name|Small
block|}
block|;      struct
name|SubmarineDescription
block|{
name|int
name|type
block|;
name|int
name|points
block|;
name|QString
name|name
block|;     }
block|;      struct
name|LevelDescription
block|{
name|int
name|id
block|;
name|QString
name|name
block|;
name|QList
operator|<
name|QPair
operator|<
name|int
block|,
name|int
operator|>
expr|>
name|submarines
block|;     }
block|;
name|GraphicsScene
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|Mode mode = Big
argument_list|)
block|;
name|qreal
name|sealLevel
argument_list|()
specifier|const
block|;
name|void
name|setupScene
argument_list|(
name|QAction
operator|*
name|newAction
argument_list|,
name|QAction
operator|*
name|quitAction
argument_list|)
block|;
name|void
name|addItem
argument_list|(
name|Bomb
operator|*
name|bomb
argument_list|)
block|;
name|void
name|addItem
argument_list|(
name|Torpedo
operator|*
name|torpedo
argument_list|)
block|;
name|void
name|addItem
argument_list|(
name|SubMarine
operator|*
name|submarine
argument_list|)
block|;
name|void
name|addItem
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|clearScene
argument_list|()
block|;
name|signals
operator|:
name|void
name|subMarineDestroyed
argument_list|(
name|int
argument_list|)
block|;
name|void
name|allSubMarineDestroyed
argument_list|(
name|int
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|onBombExecutionFinished
argument_list|()
block|;
name|void
name|onTorpedoExecutionFinished
argument_list|()
block|;
name|void
name|onSubMarineExecutionFinished
argument_list|()
block|;
name|private
operator|:
name|Mode
name|mode
block|;
name|ProgressItem
operator|*
name|progressItem
block|;
name|TextInformationItem
operator|*
name|textInformationItem
block|;
name|Boat
operator|*
name|boat
block|;
name|QSet
operator|<
name|SubMarine
operator|*
operator|>
name|submarines
block|;
name|QSet
operator|<
name|Bomb
operator|*
operator|>
name|bombs
block|;
name|QSet
operator|<
name|Torpedo
operator|*
operator|>
name|torpedos
block|;
name|QVector
operator|<
name|SubmarineDescription
operator|>
name|submarinesData
block|;
name|QHash
operator|<
name|int
block|,
name|LevelDescription
operator|>
name|levelsData
block|;
name|friend
name|class
name|PauseState
block|;
name|friend
name|class
name|PlayState
block|;
name|friend
name|class
name|LevelState
block|;
name|friend
name|class
name|LostState
block|;
name|friend
name|class
name|WinState
block|;
name|friend
name|class
name|WinTransition
block|;
name|friend
name|class
name|UpdateScoreTransition
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//__GRAPHICSSCENE__H__
end_comment
end_unit
