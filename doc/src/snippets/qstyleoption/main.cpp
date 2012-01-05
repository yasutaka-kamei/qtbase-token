begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_class
DECL|class|MyPushButton
class|class
name|MyPushButton
super|:
specifier|public
name|QPushButton
block|{
public|public:
name|MyPushButton
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|MyPushButton
name|MyPushButton
operator|::
name|MyPushButton
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QPushButton
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|MyPushButton
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QStyleOptionButton
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
name|state
operator|=
name|isDown
argument_list|()
condition|?
name|QStyle
operator|::
name|State_Sunken
else|:
name|QStyle
operator|::
name|State_Raised
expr_stmt|;
if|if
condition|(
name|isDefault
argument_list|()
condition|)
name|option
operator|.
name|features
operator||=
name|QStyleOptionButton
operator|::
name|DefaultButton
expr_stmt|;
name|option
operator|.
name|text
operator|=
name|text
argument_list|()
expr_stmt|;
name|option
operator|.
name|icon
operator|=
name|icon
argument_list|()
expr_stmt|;
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|style
argument_list|()
operator|->
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_PushButton
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
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|MyStyle
class|class
name|MyStyle
super|:
specifier|public
name|QStyle
block|{
public|public:
name|MyStyle
parameter_list|()
constructor_decl|;
name|void
name|drawPrimitive
parameter_list|(
name|PrimitiveElement
name|element
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|MyStyle
name|MyStyle
operator|::
name|MyStyle
parameter_list|()
block|{
comment|//! [1]
name|QStyleOptionFrame
modifier|*
name|option
decl_stmt|;
if|if
condition|(
specifier|const
name|QStyleOptionFrame
modifier|*
name|frameOption
init|=
name|qstyleoption_cast
argument_list|<
specifier|const
name|QStyleOptionFrame
operator|*
argument_list|>
argument_list|(
name|option
argument_list|)
condition|)
block|{
name|QStyleOptionFrameV2
name|frameOptionV2
argument_list|(
operator|*
name|frameOption
argument_list|)
decl_stmt|;
comment|// draw the frame using frameOptionV2
block|}
comment|//! [1]
comment|//! [2]
if|if
condition|(
specifier|const
name|QStyleOptionProgressBar
modifier|*
name|progressBarOption
init|=
name|qstyleoption_cast
argument_list|<
specifier|const
name|QStyleOptionProgressBar
operator|*
argument_list|>
argument_list|(
name|option
argument_list|)
condition|)
block|{
name|QStyleOptionProgressBarV2
name|progressBarV2
argument_list|(
operator|*
name|progressBarOption
argument_list|)
decl_stmt|;
comment|// draw the progress bar using progressBarV2
block|}
comment|//! [2]
comment|//! [3]
if|if
condition|(
specifier|const
name|QStyleOptionTab
modifier|*
name|tabOption
init|=
name|qstyleoption_cast
argument_list|<
specifier|const
name|QStyleOptionTab
operator|*
argument_list|>
argument_list|(
name|option
argument_list|)
condition|)
block|{
name|QStyleOptionTabV2
name|tabV2
argument_list|(
operator|*
name|tabOption
argument_list|)
decl_stmt|;
comment|// draw the tab using tabV2
block|}
comment|//! [3]
block|}
end_constructor
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|drawPrimitive
name|void
name|MyStyle
operator|::
name|drawPrimitive
parameter_list|(
name|PrimitiveElement
name|element
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
name|element
operator|==
name|PE_FrameFocusRect
condition|)
block|{
specifier|const
name|QStyleOptionFocusRect
modifier|*
name|focusRectOption
init|=
name|qstyleoption_cast
argument_list|<
specifier|const
name|QStyleOptionFocusRect
operator|*
argument_list|>
argument_list|(
name|option
argument_list|)
decl_stmt|;
if|if
condition|(
name|focusRectOption
condition|)
block|{
comment|// ...
block|}
block|}
comment|// ...
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|MyPushButton
name|button
decl_stmt|;
name|button
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
