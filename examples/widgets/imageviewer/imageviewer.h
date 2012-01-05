begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|IMAGEVIEWER_H
end_ifndef
begin_define
DECL|macro|IMAGEVIEWER_H
define|#
directive|define
name|IMAGEVIEWER_H
end_define
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QPrinter>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollArea
name|class
name|QScrollArea
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollBar
name|class
name|QScrollBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|ImageViewer
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|ImageViewer
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|open
argument_list|()
block|;
name|void
name|print
argument_list|()
block|;
name|void
name|zoomIn
argument_list|()
block|;
name|void
name|zoomOut
argument_list|()
block|;
name|void
name|normalSize
argument_list|()
block|;
name|void
name|fitToWindow
argument_list|()
block|;
name|void
name|about
argument_list|()
block|;
name|private
operator|:
name|void
name|createActions
argument_list|()
block|;
name|void
name|createMenus
argument_list|()
block|;
name|void
name|updateActions
argument_list|()
block|;
name|void
name|scaleImage
argument_list|(
argument|double factor
argument_list|)
block|;
name|void
name|adjustScrollBar
argument_list|(
argument|QScrollBar *scrollBar
argument_list|,
argument|double factor
argument_list|)
block|;
name|QLabel
operator|*
name|imageLabel
block|;
name|QScrollArea
operator|*
name|scrollArea
block|;
name|double
name|scaleFactor
block|;
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
name|QPrinter
name|printer
block|;
endif|#
directive|endif
name|QAction
operator|*
name|openAct
block|;
name|QAction
operator|*
name|printAct
block|;
name|QAction
operator|*
name|exitAct
block|;
name|QAction
operator|*
name|zoomInAct
block|;
name|QAction
operator|*
name|zoomOutAct
block|;
name|QAction
operator|*
name|normalSizeAct
block|;
name|QAction
operator|*
name|fitToWindowAct
block|;
name|QAction
operator|*
name|aboutAct
block|;
name|QAction
operator|*
name|aboutQtAct
block|;
name|QMenu
operator|*
name|fileMenu
block|;
name|QMenu
operator|*
name|viewMenu
block|;
name|QMenu
operator|*
name|helpMenu
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
