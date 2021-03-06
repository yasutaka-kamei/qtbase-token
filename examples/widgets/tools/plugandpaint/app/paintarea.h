begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PAINTAREA_H
end_ifndef
begin_define
DECL|macro|PAINTAREA_H
define|#
directive|define
name|PAINTAREA_H
end_define
begin_include
include|#
directive|include
file|<QColor>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QPainterPath>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
DECL|variable|BrushInterface
name|class
name|BrushInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|PaintArea
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|PaintArea
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|bool
name|openImage
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|bool
name|saveImage
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|fileFormat
argument_list|)
block|;
name|void
name|setImage
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|void
name|insertShape
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|)
block|;
name|void
name|setBrushColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|setBrushWidth
argument_list|(
argument|int width
argument_list|)
block|;
name|void
name|setBrush
argument_list|(
name|BrushInterface
operator|*
name|brushInterface
argument_list|,
specifier|const
name|QString
operator|&
name|brush
argument_list|)
block|;
name|QImage
name|image
argument_list|()
specifier|const
block|{
return|return
name|theImage
return|;
block|}
name|QColor
name|brushColor
argument_list|()
specifier|const
block|{
return|return
name|color
return|;
block|}
name|int
name|brushWidth
argument_list|()
specifier|const
block|{
return|return
name|thickness
return|;
block|}
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|setupPainter
argument_list|(
name|QPainter
operator|&
name|painter
argument_list|)
block|;
name|QImage
name|theImage
block|;
name|QColor
name|color
block|;
name|int
name|thickness
block|;
name|BrushInterface
operator|*
name|brushInterface
block|;
name|QString
name|brush
block|;
name|QPoint
name|lastPos
block|;
name|QPainterPath
name|pendingPath
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
