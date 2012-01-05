begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SPLITTER_H
end_ifndef
begin_define
DECL|macro|SPLITTER_H
define|#
directive|define
name|SPLITTER_H
end_define
begin_include
include|#
directive|include
file|<QLinearGradient>
end_include
begin_include
include|#
directive|include
file|<QSplitter>
end_include
begin_include
include|#
directive|include
file|<QSplitterHandle>
end_include
begin_decl_stmt
DECL|variable|QPaintEvent
name|class
name|QPaintEvent
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|Splitter
range|:
name|public
name|QSplitter
block|{
name|public
operator|:
name|Splitter
argument_list|(
argument|Qt::Orientation orientation
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|protected
operator|:
name|QSplitterHandle
operator|*
name|createHandle
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|SplitterHandle
range|:
name|public
name|QSplitterHandle
block|{
name|public
operator|:
name|SplitterHandle
argument_list|(
argument|Qt::Orientation orientation
argument_list|,
argument|QSplitter *parent
argument_list|)
block|;
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|QLinearGradient
name|gradient
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
