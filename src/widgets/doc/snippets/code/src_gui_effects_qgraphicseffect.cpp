begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_macro
DECL|function|draw
name|MyGraphicsOpacityEffect
end_macro
begin_expr_stmt
DECL|function|draw
operator|::
name|draw
operator|(
name|QPainter
operator|*
name|painter
operator|)
block|{
comment|// Fully opaque; draw directly without going through a pixmap.
if|if
condition|(
name|qFuzzyCompare
argument_list|(
name|m_opacity
argument_list|,
literal|1
argument_list|)
condition|)
block|{
name|drawSource
argument_list|(
name|painter
argument_list|)
expr_stmt|;
return|return;
block|}
operator|...
end_expr_stmt
begin_comment
unit|}
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
unit|MyGraphicsEffect
DECL|function|draw
operator|::
name|draw
operator|(
name|QPainter
operator|*
name|painter
operator|)
block|{
operator|...
name|QPoint
name|offset
block|;
if|if
condition|(
name|sourceIsPixmap
argument_list|()
condition|)
block|{
comment|// No point in drawing in device coordinates (pixmap will be scaled anyways).
specifier|const
name|QPixmap
name|pixmap
init|=
name|sourcePixmap
argument_list|(
name|Qt
operator|::
name|LogicalCoordinates
argument_list|,
operator|&
name|offset
argument_list|)
decl_stmt|;
operator|...
name|painter
operator|->
name|drawPixmap
argument_list|(
name|offset
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
comment|// Draw pixmap in device coordinates to avoid pixmap scaling;
specifier|const
name|QPixmap
name|pixmap
init|=
name|sourcePixmap
argument_list|(
name|Qt
operator|::
name|DeviceCoordinates
argument_list|,
operator|&
name|offset
argument_list|)
decl_stmt|;
name|painter
operator|->
name|setWorldTransform
argument_list|(
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
operator|...
name|painter
operator|->
name|drawPixmap
argument_list|(
name|offset
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
end_else
begin_expr_stmt
operator|...
end_expr_stmt
begin_comment
unit|}
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
unit|...
name|QLinearGradient
name|alphaGradient
argument_list|(
name|rect
operator|.
name|topLeft
argument_list|()
argument_list|,
name|rect
operator|.
name|bottomLeft
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|alphaGradient
operator|.
name|setColorAt
argument_list|(
literal|0.0
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|alphaGradient
operator|.
name|setColorAt
argument_list|(
literal|0.5
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|alphaGradient
operator|.
name|setColorAt
argument_list|(
literal|1.0
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|effect
name|QGraphicsOpacityEffect
modifier|*
name|effect
init|=
operator|new
name|QGraphicsOpacityEffect
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|effect
operator|->
name|setOpacityMask
argument_list|(
name|alphaGradient
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|...
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
end_unit
