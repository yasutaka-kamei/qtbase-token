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
file|"customviewstyle.h"
end_include
begin_function
DECL|function|drawPrimitive
name|void
name|CustomViewStyle
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
specifier|const
block|{
comment|//![0]
switch|switch
condition|(
name|element
condition|)
block|{
case|case
operator|(
name|PE_PanelItemViewItem
operator|)
case|:
block|{
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|QPoint
name|topLeft
init|=
name|option
operator|->
name|rect
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|QPoint
name|bottomRight
init|=
name|option
operator|->
name|rect
operator|.
name|topRight
argument_list|()
decl_stmt|;
name|QLinearGradient
name|backgroundGradient
argument_list|(
name|topLeft
argument_list|,
name|bottomRight
argument_list|)
decl_stmt|;
name|backgroundGradient
operator|.
name|setColorAt
argument_list|(
literal|0.0
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|yellow
argument_list|)
operator|.
name|lighter
argument_list|(
literal|190
argument_list|)
argument_list|)
expr_stmt|;
name|backgroundGradient
operator|.
name|setColorAt
argument_list|(
literal|1.0
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|option
operator|->
name|rect
argument_list|,
name|QBrush
argument_list|(
name|backgroundGradient
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
break|break;
block|}
default|default:
name|QWindowsStyle
operator|::
name|drawPrimitive
argument_list|(
name|element
argument_list|,
name|option
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
comment|//![0]
block|}
end_function
end_unit
