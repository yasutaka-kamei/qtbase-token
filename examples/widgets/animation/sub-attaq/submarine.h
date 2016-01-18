begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__SUBMARINE__H__
end_ifndef
begin_define
DECL|macro|__SUBMARINE__H__
define|#
directive|define
name|__SUBMARINE__H__
end_define
begin_comment
comment|//Qt
end_comment
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsTransform>
end_include
begin_include
include|#
directive|include
file|"pixmapitem.h"
end_include
begin_decl_stmt
DECL|variable|Torpedo
name|class
name|Torpedo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|SubMarine
range|:
name|public
name|PixmapItem
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Movement
block|{
name|None
operator|=
literal|0
block|,
name|Left
block|,
name|Right
block|}
block|;     enum
block|{
name|Type
operator|=
name|UserType
operator|+
literal|1
block|}
block|;
name|SubMarine
argument_list|(
argument|int type
argument_list|,
argument|const QString&name
argument_list|,
argument|int points
argument_list|)
block|;
name|int
name|points
argument_list|()
specifier|const
block|;
name|void
name|setCurrentDirection
argument_list|(
argument|Movement direction
argument_list|)
block|;     enum
name|Movement
name|currentDirection
argument_list|()
specifier|const
block|;
name|void
name|setCurrentSpeed
argument_list|(
argument|int speed
argument_list|)
block|;
name|int
name|currentSpeed
argument_list|()
specifier|const
block|;
name|void
name|launchTorpedo
argument_list|(
argument|int speed
argument_list|)
block|;
name|void
name|destroy
argument_list|()
block|;
name|virtual
name|int
name|type
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QGraphicsRotation
operator|*
name|rotation
argument_list|()
specifier|const
block|{
return|return
name|graphicsRotation
return|;
block|}
name|signals
operator|:
name|void
name|subMarineDestroyed
argument_list|()
block|;
name|void
name|subMarineExecutionFinished
argument_list|()
block|;
name|void
name|subMarineStateChanged
argument_list|()
block|;
name|private
operator|:
name|int
name|subType
block|;
name|QString
name|subName
block|;
name|int
name|subPoints
block|;
name|int
name|speed
block|;
name|Movement
name|direction
block|;
name|QGraphicsRotation
operator|*
name|graphicsRotation
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//__SUBMARINE__H__
end_comment
end_unit
