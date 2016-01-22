begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WIDGET_H
end_ifndef
begin_define
DECL|macro|WIDGET_H
define|#
directive|define
name|WIDGET_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QComboBox
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QTextEdit
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QVBoxLayout
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QSurfaceFormat
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QSurface
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Widget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|Widget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|start
argument_list|()
block|;
name|void
name|renderWindowReady
argument_list|()
block|;
name|void
name|renderWindowError
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|)
block|;
name|private
operator|:
name|void
name|addVersions
argument_list|(
name|QLayout
operator|*
name|layout
argument_list|)
block|;
name|void
name|addProfiles
argument_list|(
name|QLayout
operator|*
name|layout
argument_list|)
block|;
name|void
name|addOptions
argument_list|(
name|QLayout
operator|*
name|layout
argument_list|)
block|;
name|void
name|addRenderableTypes
argument_list|(
name|QLayout
operator|*
name|layout
argument_list|)
block|;
name|void
name|addRenderWindow
argument_list|()
block|;
name|void
name|printFormat
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|)
block|;
name|QComboBox
operator|*
name|m_version
block|;
name|QLayout
operator|*
name|m_profiles
block|;
name|QLayout
operator|*
name|m_options
block|;
name|QLayout
operator|*
name|m_renderables
block|;
name|QTextEdit
operator|*
name|m_output
block|;
name|QTextEdit
operator|*
name|m_extensions
block|;
name|QVBoxLayout
operator|*
name|m_renderWindowLayout
block|;
name|QWidget
operator|*
name|m_renderWindowContainer
block|;
name|QSurface
operator|*
name|m_surface
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// WIDGET_H
end_comment
end_unit
