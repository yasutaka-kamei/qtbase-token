begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QMouseEvent>
end_include
begin_class
DECL|class|MyCheckBox
class|class
name|MyCheckBox
super|:
specifier|public
name|QCheckBox
block|{
public|public:
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|MyCheckBox
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
comment|// handle left mouse button here
block|}
else|else
block|{
comment|// pass on other buttons to base class
name|QCheckBox
operator|::
name|mousePressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|MyWidget
class|class
name|MyWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|MyCustomEventType
specifier|static
specifier|const
name|int
name|MyCustomEventType
init|=
literal|1099
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|MyCustomEvent
class|class
name|MyCustomEvent
super|:
specifier|public
name|QEvent
block|{
public|public:
DECL|function|MyCustomEvent
name|MyCustomEvent
parameter_list|()
member_init_list|:
name|QEvent
argument_list|(
operator|(
name|QEvent
operator|::
name|Type
operator|)
name|MyCustomEventType
argument_list|)
block|{}
block|}
class|;
end_class
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|event
name|bool
name|MyWidget
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyPress
condition|)
block|{
name|QKeyEvent
modifier|*
name|ke
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|ke
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Tab
condition|)
block|{
comment|// special tab handling here
return|return
literal|true
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|MyCustomEventType
condition|)
block|{
name|MyCustomEvent
modifier|*
name|myEvent
init|=
cast|static_cast
argument_list|<
name|MyCustomEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
comment|// custom event handling here
return|return
literal|true
return|;
block|}
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{ }
end_function
end_unit
