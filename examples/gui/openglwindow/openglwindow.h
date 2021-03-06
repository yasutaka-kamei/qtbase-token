begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLPaintDevice
name|class
name|QOpenGLPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [1]
DECL|variable|QWindow
name|class
name|OpenGLWindow
range|:
name|public
name|QWindow
decl_stmt|,
name|protected
name|QOpenGLFunctions
block|{
name|Q_OBJECT
name|public
range|:
name|explicit
name|OpenGLWindow
argument_list|(
name|QWindow
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|OpenGLWindow
argument_list|()
expr_stmt|;
name|virtual
name|void
name|render
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
function_decl|;
name|virtual
name|void
name|render
parameter_list|()
function_decl|;
name|virtual
name|void
name|initialize
parameter_list|()
function_decl|;
name|void
name|setAnimating
parameter_list|(
name|bool
name|animating
parameter_list|)
function_decl|;
name|public
name|slots
range|:
name|void
name|renderLater
argument_list|()
decl_stmt|;
name|void
name|renderNow
parameter_list|()
function_decl|;
name|protected
label|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|exposeEvent
argument_list|(
name|QExposeEvent
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|private
label|:
name|bool
name|m_update_pending
decl_stmt|;
name|bool
name|m_animating
decl_stmt|;
name|QOpenGLContext
modifier|*
name|m_context
decl_stmt|;
name|QOpenGLPaintDevice
modifier|*
name|m_device
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//! [1]
end_comment
end_unit
