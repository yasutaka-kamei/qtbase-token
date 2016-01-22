begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"piecesmodel.h"
end_include
begin_include
include|#
directive|include
file|"puzzlewidget.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
block|{
name|setupMenus
argument_list|()
expr_stmt|;
name|setupWidgets
argument_list|()
expr_stmt|;
name|model
operator|=
operator|new
name|PiecesModel
argument_list|(
name|puzzleWidget
operator|->
name|pieceSize
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|piecesList
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|setSizePolicy
argument_list|(
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Puzzle"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|openImage
name|void
name|MainWindow
operator|::
name|openImage
parameter_list|()
block|{
specifier|const
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open Image"
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|,
name|tr
argument_list|(
literal|"Image Files (*.png *.jpg *.bmp)"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|loadImage
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadImage
name|void
name|MainWindow
operator|::
name|loadImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QPixmap
name|newImage
decl_stmt|;
if|if
condition|(
operator|!
name|newImage
operator|.
name|load
argument_list|(
name|fileName
argument_list|)
condition|)
block|{
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Open Image"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The image file could not be loaded."
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
return|return;
block|}
name|puzzleImage
operator|=
name|newImage
expr_stmt|;
name|setupPuzzle
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCompleted
name|void
name|MainWindow
operator|::
name|setCompleted
parameter_list|()
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Puzzle Completed"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Congratulations! You have completed the puzzle!\n"
literal|"Click OK to start again."
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Ok
argument_list|)
expr_stmt|;
name|setupPuzzle
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupPuzzle
name|void
name|MainWindow
operator|::
name|setupPuzzle
parameter_list|()
block|{
name|int
name|size
init|=
name|qMin
argument_list|(
name|puzzleImage
operator|.
name|width
argument_list|()
argument_list|,
name|puzzleImage
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|puzzleImage
operator|=
name|puzzleImage
operator|.
name|copy
argument_list|(
operator|(
name|puzzleImage
operator|.
name|width
argument_list|()
operator|-
name|size
operator|)
operator|/
literal|2
argument_list|,
operator|(
name|puzzleImage
operator|.
name|height
argument_list|()
operator|-
name|size
operator|)
operator|/
literal|2
argument_list|,
name|size
argument_list|,
name|size
argument_list|)
operator|.
name|scaled
argument_list|(
name|puzzleWidget
operator|->
name|imageSize
argument_list|()
argument_list|,
name|puzzleWidget
operator|->
name|imageSize
argument_list|()
argument_list|,
name|Qt
operator|::
name|IgnoreAspectRatio
argument_list|,
name|Qt
operator|::
name|SmoothTransformation
argument_list|)
expr_stmt|;
name|qsrand
argument_list|(
name|QCursor
operator|::
name|pos
argument_list|()
operator|.
name|x
argument_list|()
operator|^
name|QCursor
operator|::
name|pos
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|model
operator|->
name|addPieces
argument_list|(
name|puzzleImage
argument_list|)
expr_stmt|;
name|puzzleWidget
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupMenus
name|void
name|MainWindow
operator|::
name|setupMenus
parameter_list|()
block|{
name|QMenu
modifier|*
name|fileMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|openAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|)
decl_stmt|;
name|openAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|exitAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|)
decl_stmt|;
name|exitAction
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|gameMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Game"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|restartAction
init|=
name|gameMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Restart"
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|openAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|openImage
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|qApp
argument_list|,
operator|&
name|QCoreApplication
operator|::
name|quit
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|restartAction
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|setupPuzzle
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupWidgets
name|void
name|MainWindow
operator|::
name|setupWidgets
parameter_list|()
block|{
name|QFrame
modifier|*
name|frame
init|=
operator|new
name|QFrame
decl_stmt|;
name|QHBoxLayout
modifier|*
name|frameLayout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|frame
argument_list|)
decl_stmt|;
name|puzzleWidget
operator|=
operator|new
name|PuzzleWidget
argument_list|(
literal|400
argument_list|)
expr_stmt|;
name|piecesList
operator|=
operator|new
name|QListView
expr_stmt|;
name|piecesList
operator|->
name|setDragEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|piecesList
operator|->
name|setViewMode
argument_list|(
name|QListView
operator|::
name|IconMode
argument_list|)
expr_stmt|;
name|piecesList
operator|->
name|setIconSize
argument_list|(
name|QSize
argument_list|(
name|puzzleWidget
operator|->
name|pieceSize
argument_list|()
operator|-
literal|20
argument_list|,
name|puzzleWidget
operator|->
name|pieceSize
argument_list|()
operator|-
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|piecesList
operator|->
name|setGridSize
argument_list|(
name|QSize
argument_list|(
name|puzzleWidget
operator|->
name|pieceSize
argument_list|()
argument_list|,
name|puzzleWidget
operator|->
name|pieceSize
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|piecesList
operator|->
name|setSpacing
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|piecesList
operator|->
name|setMovement
argument_list|(
name|QListView
operator|::
name|Snap
argument_list|)
expr_stmt|;
name|piecesList
operator|->
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|piecesList
operator|->
name|setDropIndicatorShown
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|PiecesModel
modifier|*
name|model
init|=
operator|new
name|PiecesModel
argument_list|(
name|puzzleWidget
operator|->
name|pieceSize
argument_list|()
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|piecesList
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|puzzleWidget
argument_list|,
operator|&
name|PuzzleWidget
operator|::
name|puzzleCompleted
argument_list|,
name|this
argument_list|,
operator|&
name|MainWindow
operator|::
name|setCompleted
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|frameLayout
operator|->
name|addWidget
argument_list|(
name|piecesList
argument_list|)
expr_stmt|;
name|frameLayout
operator|->
name|addWidget
argument_list|(
name|puzzleWidget
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|frame
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
