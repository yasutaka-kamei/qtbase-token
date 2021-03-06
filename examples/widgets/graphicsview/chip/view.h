begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|VIEW_H
end_ifndef
begin_define
DECL|macro|VIEW_H
define|#
directive|define
name|VIEW_H
end_define
begin_include
include|#
directive|include
file|<QFrame>
end_include
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSlider
name|class
name|QSlider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolButton
name|class
name|QToolButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|View
name|class
name|View
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|GraphicsView
range|:
name|public
name|QGraphicsView
block|{
name|Q_OBJECT
name|public
operator|:
name|GraphicsView
argument_list|(
name|View
operator|*
name|v
argument_list|)
operator|:
name|QGraphicsView
argument_list|()
block|,
name|view
argument_list|(
argument|v
argument_list|)
block|{ }
name|protected
operator|:
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
argument|QWheelEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|private
operator|:
name|View
operator|*
name|view
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|View
range|:
name|public
name|QFrame
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|View
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QGraphicsView
operator|*
name|view
argument_list|()
specifier|const
block|;
name|public
name|slots
operator|:
name|void
name|zoomIn
argument_list|(
argument|int level =
literal|1
argument_list|)
block|;
name|void
name|zoomOut
argument_list|(
argument|int level =
literal|1
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|resetView
argument_list|()
block|;
name|void
name|setResetButtonEnabled
argument_list|()
block|;
name|void
name|setupMatrix
argument_list|()
block|;
name|void
name|togglePointerMode
argument_list|()
block|;
name|void
name|toggleOpenGL
argument_list|()
block|;
name|void
name|toggleAntialiasing
argument_list|()
block|;
name|void
name|print
argument_list|()
block|;
name|void
name|rotateLeft
argument_list|()
block|;
name|void
name|rotateRight
argument_list|()
block|;
name|private
operator|:
name|GraphicsView
operator|*
name|graphicsView
block|;
name|QLabel
operator|*
name|label
block|;
name|QLabel
operator|*
name|label2
block|;
name|QToolButton
operator|*
name|selectModeButton
block|;
name|QToolButton
operator|*
name|dragModeButton
block|;
name|QToolButton
operator|*
name|openGlButton
block|;
name|QToolButton
operator|*
name|antialiasButton
block|;
name|QToolButton
operator|*
name|printButton
block|;
name|QToolButton
operator|*
name|resetButton
block|;
name|QSlider
operator|*
name|zoomSlider
block|;
name|QSlider
operator|*
name|rotateSlider
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// VIEW_H
end_comment
end_unit
