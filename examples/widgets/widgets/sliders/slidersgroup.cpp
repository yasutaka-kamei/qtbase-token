begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"slidersgroup.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|SlidersGroup
name|SlidersGroup
operator|::
name|SlidersGroup
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGroupBox
argument_list|(
name|title
argument_list|,
name|parent
argument_list|)
block|{
name|slider
operator|=
operator|new
name|QSlider
argument_list|(
name|orientation
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setTickPosition
argument_list|(
name|QSlider
operator|::
name|TicksBothSides
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setTickInterval
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setSingleStep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|scrollBar
operator|=
operator|new
name|QScrollBar
argument_list|(
name|orientation
argument_list|)
expr_stmt|;
name|scrollBar
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|dial
operator|=
operator|new
name|QDial
expr_stmt|;
name|dial
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|slider
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|scrollBar
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|scrollBar
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|dial
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|dial
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|slider
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0] //! [1]
name|connect
argument_list|(
name|dial
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1] //! [2]
comment|//! [2] //! [3]
name|QBoxLayout
operator|::
name|Direction
name|direction
decl_stmt|;
comment|//! [3] //! [4]
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
name|direction
operator|=
name|QBoxLayout
operator|::
name|TopToBottom
expr_stmt|;
else|else
name|direction
operator|=
name|QBoxLayout
operator|::
name|LeftToRight
expr_stmt|;
name|QBoxLayout
modifier|*
name|slidersLayout
init|=
operator|new
name|QBoxLayout
argument_list|(
name|direction
argument_list|)
decl_stmt|;
name|slidersLayout
operator|->
name|addWidget
argument_list|(
name|slider
argument_list|)
expr_stmt|;
name|slidersLayout
operator|->
name|addWidget
argument_list|(
name|scrollBar
argument_list|)
expr_stmt|;
name|slidersLayout
operator|->
name|addWidget
argument_list|(
name|dial
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|slidersLayout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|setValue
name|void
name|SlidersGroup
operator|::
name|setValue
parameter_list|(
name|int
name|value
parameter_list|)
comment|//! [5] //! [6]
block|{
name|slider
operator|->
name|setValue
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|setMinimum
name|void
name|SlidersGroup
operator|::
name|setMinimum
parameter_list|(
name|int
name|value
parameter_list|)
comment|//! [7] //! [8]
block|{
name|slider
operator|->
name|setMinimum
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|scrollBar
operator|->
name|setMinimum
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|dial
operator|->
name|setMinimum
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|setMaximum
name|void
name|SlidersGroup
operator|::
name|setMaximum
parameter_list|(
name|int
name|value
parameter_list|)
comment|//! [9] //! [10]
block|{
name|slider
operator|->
name|setMaximum
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|scrollBar
operator|->
name|setMaximum
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|dial
operator|->
name|setMaximum
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|invertAppearance
name|void
name|SlidersGroup
operator|::
name|invertAppearance
parameter_list|(
name|bool
name|invert
parameter_list|)
comment|//! [11] //! [12]
block|{
name|slider
operator|->
name|setInvertedAppearance
argument_list|(
name|invert
argument_list|)
expr_stmt|;
name|scrollBar
operator|->
name|setInvertedAppearance
argument_list|(
name|invert
argument_list|)
expr_stmt|;
name|dial
operator|->
name|setInvertedAppearance
argument_list|(
name|invert
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|invertKeyBindings
name|void
name|SlidersGroup
operator|::
name|invertKeyBindings
parameter_list|(
name|bool
name|invert
parameter_list|)
comment|//! [13] //! [14]
block|{
name|slider
operator|->
name|setInvertedControls
argument_list|(
name|invert
argument_list|)
expr_stmt|;
name|scrollBar
operator|->
name|setInvertedControls
argument_list|(
name|invert
argument_list|)
expr_stmt|;
name|dial
operator|->
name|setInvertedControls
argument_list|(
name|invert
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [14]
end_comment
end_unit
