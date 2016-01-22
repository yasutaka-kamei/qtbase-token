begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DIAGRAMITEM_H
end_ifndef
begin_define
DECL|macro|DIAGRAMITEM_H
define|#
directive|define
name|DIAGRAMITEM_H
end_define
begin_include
include|#
directive|include
file|<QGraphicsPolygonItem>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsItem
name|class
name|QGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsScene
name|class
name|QGraphicsScene
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneMouseEvent
name|class
name|QGraphicsSceneMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPointF
name|class
name|QPointF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|DiagramItem
range|:
name|public
name|QGraphicsPolygonItem
block|{
name|public
operator|:
expr|enum
block|{
name|Type
operator|=
name|UserType
operator|+
literal|1
block|}
block|;     enum
name|DiagramType
block|{
name|Box
block|,
name|Triangle
block|}
block|;
name|explicit
name|DiagramItem
argument_list|(
argument|DiagramType diagramType
argument_list|,
argument|QGraphicsItem *item =
literal|0
argument_list|)
block|;
name|DiagramType
name|diagramType
argument_list|()
specifier|const
block|{
return|return
name|polygon
argument_list|()
operator|==
name|boxPolygon
operator|?
name|Box
operator|:
name|Triangle
return|;
block|}
name|int
name|type
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|Type
return|;
block|}
name|private
operator|:
name|QPolygonF
name|boxPolygon
block|;
name|QPolygonF
name|trianglePolygon
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
