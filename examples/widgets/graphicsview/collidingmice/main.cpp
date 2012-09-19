begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mouse.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_decl_stmt
DECL|variable|MouseCount
specifier|static
specifier|const
name|int
name|MouseCount
init|=
literal|7
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|qsrand
argument_list|(
name|QTime
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|.
name|secsTo
argument_list|(
name|QTime
operator|::
name|currentTime
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QGraphicsScene
name|scene
decl_stmt|;
name|scene
operator|.
name|setSceneRect
argument_list|(
operator|-
literal|300
argument_list|,
operator|-
literal|300
argument_list|,
literal|600
argument_list|,
literal|600
argument_list|)
expr_stmt|;
comment|//! [1] //! [2]
name|scene
operator|.
name|setItemIndexMethod
argument_list|(
name|QGraphicsScene
operator|::
name|NoIndex
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|MouseCount
condition|;
operator|++
name|i
control|)
block|{
name|Mouse
modifier|*
name|mouse
init|=
operator|new
name|Mouse
decl_stmt|;
name|mouse
operator|->
name|setPos
argument_list|(
operator|::
name|sin
argument_list|(
operator|(
name|i
operator|*
literal|6.28
operator|)
operator|/
name|MouseCount
argument_list|)
operator|*
literal|200
argument_list|,
operator|::
name|cos
argument_list|(
operator|(
name|i
operator|*
literal|6.28
operator|)
operator|/
name|MouseCount
argument_list|)
operator|*
literal|200
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|mouse
argument_list|)
expr_stmt|;
block|}
comment|//! [3]
comment|//! [4]
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
name|view
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|view
operator|.
name|setBackgroundBrush
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/cheese.jpg"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [4] //! [5]
name|view
operator|.
name|setCacheMode
argument_list|(
name|QGraphicsView
operator|::
name|CacheBackground
argument_list|)
expr_stmt|;
name|view
operator|.
name|setViewportUpdateMode
argument_list|(
name|QGraphicsView
operator|::
name|BoundingRectViewportUpdate
argument_list|)
expr_stmt|;
name|view
operator|.
name|setDragMode
argument_list|(
name|QGraphicsView
operator|::
name|ScrollHandDrag
argument_list|)
expr_stmt|;
comment|//! [5] //! [6]
name|view
operator|.
name|setWindowTitle
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
name|QGraphicsView
argument_list|,
literal|"Colliding Mice"
argument_list|)
argument_list|)
expr_stmt|;
name|view
operator|.
name|resize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTimer
name|timer
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
operator|&
name|scene
argument_list|,
name|SLOT
argument_list|(
name|advance
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|.
name|start
argument_list|(
literal|1000
operator|/
literal|33
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
end_unit
