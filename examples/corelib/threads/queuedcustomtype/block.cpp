begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QColor>
end_include
begin_include
include|#
directive|include
file|<QRect>
end_include
begin_include
include|#
directive|include
file|"block.h"
end_include
begin_constructor
DECL|function|Block
name|Block
operator|::
name|Block
parameter_list|()
block|{ }
end_constructor
begin_constructor
DECL|function|Block
name|Block
operator|::
name|Block
parameter_list|(
specifier|const
name|Block
modifier|&
name|other
parameter_list|)
block|{
name|m_rect
operator|=
name|other
operator|.
name|m_rect
expr_stmt|;
name|m_color
operator|=
name|other
operator|.
name|m_color
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Block
name|Block
operator|::
name|~
name|Block
parameter_list|()
block|{ }
end_destructor
begin_constructor
DECL|function|Block
name|Block
operator|::
name|Block
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|m_rect
operator|=
name|rect
expr_stmt|;
name|m_color
operator|=
name|color
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|color
name|QColor
name|Block
operator|::
name|color
parameter_list|()
specifier|const
block|{
return|return
name|m_color
return|;
block|}
end_function
begin_function
DECL|function|rect
name|QRect
name|Block
operator|::
name|rect
parameter_list|()
specifier|const
block|{
return|return
name|m_rect
return|;
block|}
end_function
end_unit
