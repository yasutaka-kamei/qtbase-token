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
file|"commands.h"
end_include
begin_include
include|#
directive|include
file|"diagramitem.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|MoveCommand
name|MoveCommand
operator|::
name|MoveCommand
parameter_list|(
name|DiagramItem
modifier|*
name|diagramItem
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|oldPos
parameter_list|,
name|QUndoCommand
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QUndoCommand
argument_list|(
name|parent
argument_list|)
block|{
name|myDiagramItem
operator|=
name|diagramItem
expr_stmt|;
name|newPos
operator|=
name|diagramItem
operator|->
name|pos
argument_list|()
expr_stmt|;
name|myOldPos
operator|=
name|oldPos
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|mergeWith
name|bool
name|MoveCommand
operator|::
name|mergeWith
parameter_list|(
specifier|const
name|QUndoCommand
modifier|*
name|command
parameter_list|)
block|{
specifier|const
name|MoveCommand
modifier|*
name|moveCommand
init|=
cast|static_cast
argument_list|<
specifier|const
name|MoveCommand
operator|*
argument_list|>
argument_list|(
name|command
argument_list|)
decl_stmt|;
name|DiagramItem
modifier|*
name|item
init|=
name|moveCommand
operator|->
name|myDiagramItem
decl_stmt|;
if|if
condition|(
name|myDiagramItem
operator|!=
name|item
condition|)
return|return
literal|false
return|;
name|newPos
operator|=
name|item
operator|->
name|pos
argument_list|()
expr_stmt|;
name|setText
argument_list|(
name|QObject
operator|::
name|tr
argument_list|(
literal|"Move %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|createCommandString
argument_list|(
name|myDiagramItem
argument_list|,
name|newPos
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
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
DECL|function|undo
name|void
name|MoveCommand
operator|::
name|undo
parameter_list|()
block|{
name|myDiagramItem
operator|->
name|setPos
argument_list|(
name|myOldPos
argument_list|)
expr_stmt|;
name|myDiagramItem
operator|->
name|scene
argument_list|()
operator|->
name|update
argument_list|()
expr_stmt|;
name|setText
argument_list|(
name|QObject
operator|::
name|tr
argument_list|(
literal|"Move %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|createCommandString
argument_list|(
name|myDiagramItem
argument_list|,
name|newPos
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|redo
name|void
name|MoveCommand
operator|::
name|redo
parameter_list|()
block|{
name|myDiagramItem
operator|->
name|setPos
argument_list|(
name|newPos
argument_list|)
expr_stmt|;
name|setText
argument_list|(
name|QObject
operator|::
name|tr
argument_list|(
literal|"Move %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|createCommandString
argument_list|(
name|myDiagramItem
argument_list|,
name|newPos
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_constructor
DECL|function|DeleteCommand
name|DeleteCommand
operator|::
name|DeleteCommand
parameter_list|(
name|QGraphicsScene
modifier|*
name|scene
parameter_list|,
name|QUndoCommand
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QUndoCommand
argument_list|(
name|parent
argument_list|)
block|{
name|myGraphicsScene
operator|=
name|scene
expr_stmt|;
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|list
init|=
name|myGraphicsScene
operator|->
name|selectedItems
argument_list|()
decl_stmt|;
name|list
operator|.
name|first
argument_list|()
operator|->
name|setSelected
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|myDiagramItem
operator|=
cast|static_cast
argument_list|<
name|DiagramItem
operator|*
argument_list|>
argument_list|(
name|list
operator|.
name|first
argument_list|()
argument_list|)
expr_stmt|;
name|setText
argument_list|(
name|QObject
operator|::
name|tr
argument_list|(
literal|"Delete %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|createCommandString
argument_list|(
name|myDiagramItem
argument_list|,
name|myDiagramItem
operator|->
name|pos
argument_list|()
argument_list|)
argument_list|)
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
DECL|function|undo
name|void
name|DeleteCommand
operator|::
name|undo
parameter_list|()
block|{
name|myGraphicsScene
operator|->
name|addItem
argument_list|(
name|myDiagramItem
argument_list|)
expr_stmt|;
name|myGraphicsScene
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|redo
name|void
name|DeleteCommand
operator|::
name|redo
parameter_list|()
block|{
name|myGraphicsScene
operator|->
name|removeItem
argument_list|(
name|myDiagramItem
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
begin_constructor
DECL|function|AddCommand
name|AddCommand
operator|::
name|AddCommand
parameter_list|(
name|DiagramItem
operator|::
name|DiagramType
name|addType
parameter_list|,
name|QGraphicsScene
modifier|*
name|scene
parameter_list|,
name|QUndoCommand
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QUndoCommand
argument_list|(
name|parent
argument_list|)
block|{
specifier|static
name|int
name|itemCount
init|=
literal|0
decl_stmt|;
name|myGraphicsScene
operator|=
name|scene
expr_stmt|;
name|myDiagramItem
operator|=
operator|new
name|DiagramItem
argument_list|(
name|addType
argument_list|)
expr_stmt|;
name|initialPosition
operator|=
name|QPointF
argument_list|(
operator|(
name|itemCount
operator|*
literal|15
operator|)
operator|%
name|int
argument_list|(
name|scene
operator|->
name|width
argument_list|()
argument_list|)
argument_list|,
operator|(
name|itemCount
operator|*
literal|15
operator|)
operator|%
name|int
argument_list|(
name|scene
operator|->
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|update
argument_list|()
expr_stmt|;
operator|++
name|itemCount
expr_stmt|;
name|setText
argument_list|(
name|QObject
operator|::
name|tr
argument_list|(
literal|"Add %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|createCommandString
argument_list|(
name|myDiagramItem
argument_list|,
name|initialPosition
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [7]
end_comment
begin_destructor
DECL|function|~AddCommand
name|AddCommand
operator|::
name|~
name|AddCommand
parameter_list|()
block|{
if|if
condition|(
operator|!
name|myDiagramItem
operator|->
name|scene
argument_list|()
condition|)
operator|delete
name|myDiagramItem
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|undo
name|void
name|AddCommand
operator|::
name|undo
parameter_list|()
block|{
name|myGraphicsScene
operator|->
name|removeItem
argument_list|(
name|myDiagramItem
argument_list|)
expr_stmt|;
name|myGraphicsScene
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|redo
name|void
name|AddCommand
operator|::
name|redo
parameter_list|()
block|{
name|myGraphicsScene
operator|->
name|addItem
argument_list|(
name|myDiagramItem
argument_list|)
expr_stmt|;
name|myDiagramItem
operator|->
name|setPos
argument_list|(
name|initialPosition
argument_list|)
expr_stmt|;
name|myGraphicsScene
operator|->
name|clearSelection
argument_list|()
expr_stmt|;
name|myGraphicsScene
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|createCommandString
name|QString
name|createCommandString
parameter_list|(
name|DiagramItem
modifier|*
name|item
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|pos
parameter_list|)
block|{
return|return
name|QObject
operator|::
name|tr
argument_list|(
literal|"%1 at (%2, %3)"
argument_list|)
operator|.
name|arg
argument_list|(
name|item
operator|->
name|diagramType
argument_list|()
operator|==
name|DiagramItem
operator|::
name|Box
condition|?
literal|"Box"
else|:
literal|"Triangle"
argument_list|)
operator|.
name|arg
argument_list|(
name|pos
operator|.
name|x
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|pos
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_function
end_unit
