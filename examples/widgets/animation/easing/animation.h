begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ANIMATION_H
end_ifndef
begin_define
DECL|macro|ANIMATION_H
define|#
directive|define
name|ANIMATION_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpropertyanimation.h>
end_include
begin_decl_stmt
name|class
name|Animation
range|:
name|public
name|QPropertyAnimation
block|{
name|public
operator|:
expr|enum
name|PathType
block|{
name|LinearPath
block|,
name|CirclePath
block|,
name|NPathTypes
block|}
block|;
name|Animation
argument_list|(
name|QObject
operator|*
name|target
argument_list|,
specifier|const
name|QByteArray
operator|&
name|prop
argument_list|)
operator|:
name|QPropertyAnimation
argument_list|(
argument|target
argument_list|,
argument|prop
argument_list|)
block|{
name|setPathType
argument_list|(
name|LinearPath
argument_list|)
block|;     }
name|void
name|setPathType
argument_list|(
argument|PathType pathType
argument_list|)
block|{
if|if
condition|(
name|pathType
operator|>=
name|NPathTypes
condition|)
name|qWarning
argument_list|(
literal|"Unknown pathType %d"
argument_list|,
name|pathType
argument_list|)
expr_stmt|;
name|m_pathType
operator|=
name|pathType
block|;
name|m_path
operator|=
name|QPainterPath
argument_list|()
block|;     }
name|void
name|updateCurrentTime
argument_list|(
argument|int currentTime
argument_list|)
name|Q_DECL_OVERRIDE
block|{
if|if
condition|(
name|m_pathType
operator|==
name|CirclePath
condition|)
block|{
if|if
condition|(
name|m_path
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QPointF
name|to
init|=
name|endValue
argument_list|()
operator|.
name|toPointF
argument_list|()
decl_stmt|;
name|QPointF
name|from
init|=
name|startValue
argument_list|()
operator|.
name|toPointF
argument_list|()
decl_stmt|;
name|m_path
operator|.
name|moveTo
argument_list|(
name|from
argument_list|)
expr_stmt|;
name|m_path
operator|.
name|addEllipse
argument_list|(
name|QRectF
argument_list|(
name|from
argument_list|,
name|to
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|int
name|dura
init|=
name|duration
argument_list|()
decl_stmt|;
specifier|const
name|qreal
name|progress
init|=
operator|(
operator|(
name|dura
operator|==
literal|0
operator|)
condition|?
literal|1
else|:
operator|(
operator|(
operator|(
operator|(
name|currentTime
operator|-
literal|1
operator|)
operator|%
name|dura
operator|)
operator|+
literal|1
operator|)
operator|/
name|qreal
argument_list|(
name|dura
argument_list|)
operator|)
operator|)
decl_stmt|;
name|qreal
name|easedProgress
init|=
name|easingCurve
argument_list|()
operator|.
name|valueForProgress
argument_list|(
name|progress
argument_list|)
decl_stmt|;
if|if
condition|(
name|easedProgress
operator|>
literal|1.0
condition|)
block|{
name|easedProgress
operator|-=
literal|1.0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|easedProgress
operator|<
literal|0
condition|)
block|{
name|easedProgress
operator|+=
literal|1.0
expr_stmt|;
block|}
name|QPointF
name|pt
init|=
name|m_path
operator|.
name|pointAtPercent
argument_list|(
name|easedProgress
argument_list|)
decl_stmt|;
name|updateCurrentValue
argument_list|(
name|pt
argument_list|)
expr_stmt|;
name|emit
name|valueChanged
parameter_list|(
name|pt
parameter_list|)
function_decl|;
block|}
else|else
block|{
name|QPropertyAnimation
operator|::
name|updateCurrentTime
argument_list|(
name|currentTime
argument_list|)
expr_stmt|;
block|}
block|}
name|QPainterPath
name|m_path
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PathType
name|m_pathType
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// ANIMATION_H
end_comment
end_unit
