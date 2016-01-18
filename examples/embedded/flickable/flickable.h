begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FLICKABLE_H
end_ifndef
begin_define
DECL|macro|FLICKABLE_H
define|#
directive|define
name|FLICKABLE_H
end_define
begin_decl_stmt
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FlickableTicker
name|class
name|FlickableTicker
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|FlickablePrivate
name|class
name|FlickablePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Flickable
block|{
name|public
label|:
name|Flickable
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|Flickable
argument_list|()
expr_stmt|;
name|void
name|setThreshold
parameter_list|(
name|int
name|threshold
parameter_list|)
function_decl|;
name|int
name|threshold
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAcceptMouseClick
parameter_list|(
name|QWidget
modifier|*
name|target
parameter_list|)
function_decl|;
name|void
name|handleMousePress
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleMouseMove
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|handleMouseRelease
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|protected
label|:
name|virtual
name|QPoint
name|scrollOffset
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setScrollOffset
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
init|=
literal|0
function_decl|;
name|private
label|:
name|void
name|tick
parameter_list|()
function_decl|;
name|private
label|:
name|FlickablePrivate
modifier|*
name|d
decl_stmt|;
name|friend
name|class
name|FlickableTicker
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// FLICKABLE_H
end_comment
end_unit
