begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QStyleOption>
end_include
begin_include
include|#
directive|include
file|<QStylePainter>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_class
DECL|class|MyWidget
class|class
name|MyWidget
super|:
specifier|public
name|QWidget
block|{
protected|protected:
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|void
name|paintEvent2
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [0] //! [1]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|MyWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
comment|/* event */
parameter_list|)
comment|//! [0]
block|{
comment|//! [2]
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
comment|//! [2]
name|QStyleOptionFocusRect
name|option
decl_stmt|;
name|option
operator|.
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|option
operator|.
name|backgroundColor
operator|=
name|palette
argument_list|()
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Background
argument_list|)
expr_stmt|;
comment|//! [3]
name|style
argument_list|()
operator|->
name|drawPrimitive
argument_list|(
name|QStyle
operator|::
name|PE_FrameFocusRect
argument_list|,
operator|&
name|option
argument_list|,
operator|&
name|painter
argument_list|,
name|this
argument_list|)
expr_stmt|;
comment|//! [3]
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|paintEvent2
name|void
name|MyWidget
operator|::
name|paintEvent2
parameter_list|(
name|QPaintEvent
modifier|*
comment|/* event */
parameter_list|)
comment|//! [4]
block|{
comment|//! [4] //! [5] //! [6]
name|QStylePainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
comment|//! [5]
name|QStyleOptionFocusRect
name|option
decl_stmt|;
name|option
operator|.
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|option
operator|.
name|backgroundColor
operator|=
name|palette
argument_list|()
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Background
argument_list|)
expr_stmt|;
comment|//! [7]
name|painter
operator|.
name|drawPrimitive
argument_list|(
name|QStyle
operator|::
name|PE_FrameFocusRect
argument_list|,
name|option
argument_list|)
expr_stmt|;
comment|//! [7]
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
end_unit
