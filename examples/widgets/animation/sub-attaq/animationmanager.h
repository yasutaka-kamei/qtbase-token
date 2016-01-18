begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ANIMATIONMANAGER_H
end_ifndef
begin_define
DECL|macro|ANIMATIONMANAGER_H
define|#
directive|define
name|ANIMATIONMANAGER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractAnimation
name|class
name|QAbstractAnimation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|AnimationManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|AnimationManager
argument_list|()
block|;
name|void
name|registerAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|anim
argument_list|)
block|;
name|void
name|unregisterAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|anim
argument_list|)
block|;
name|void
name|unregisterAllAnimations
argument_list|()
block|;
specifier|static
name|AnimationManager
operator|*
name|self
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|pauseAll
argument_list|()
block|;
name|void
name|resumeAll
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|unregisterAnimation_helper
argument_list|(
name|QObject
operator|*
name|obj
argument_list|)
block|;
name|private
operator|:
specifier|static
name|AnimationManager
operator|*
name|instance
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|animations
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ANIMATIONMANAGER_H
end_comment
end_unit
