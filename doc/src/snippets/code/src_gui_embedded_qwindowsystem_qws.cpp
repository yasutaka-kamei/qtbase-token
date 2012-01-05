begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|save
name|bool
name|MyScreenSaver
operator|::
name|save
parameter_list|(
name|int
name|level
parameter_list|)
block|{
switch|switch
condition|(
name|level
condition|)
block|{
case|case
literal|0
case|:
if|if
condition|(
name|dim_enabled
condition|)
block|{
comment|// dim the screen
block|}
return|return
literal|true
return|;
case|case
literal|1
case|:
if|if
condition|(
name|screenoff_enabled
condition|)
block|{
comment|// turn off the screen
block|}
return|return
literal|true
return|;
case|case
literal|2
case|:
if|if
condition|(
name|suspend_enabled
condition|)
block|{
comment|// suspend
block|}
return|return
literal|true
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
end_function
begin_expr_stmt
operator|...
name|int
name|timings
index|[
literal|4
index|]
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|timings
index|[
literal|0
index|]
operator|=
literal|5000
expr_stmt|;
end_expr_stmt
begin_comment
comment|// dim after 5 seconds
end_comment
begin_expr_stmt
name|timings
index|[
literal|1
index|]
operator|=
literal|10000
expr_stmt|;
end_expr_stmt
begin_comment
comment|// light off after 15 seconds
end_comment
begin_expr_stmt
name|timings
index|[
literal|2
index|]
operator|=
literal|45000
expr_stmt|;
end_expr_stmt
begin_comment
comment|// suspend after 60 seconds
end_comment
begin_expr_stmt
name|timings
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QWSServer
operator|::
name|setScreenSaverIntervals
argument_list|(
name|timings
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// ignore the key/mouse event that turns on the screen
end_comment
begin_decl_stmt
DECL|variable|blocklevel
name|int
name|blocklevel
init|=
literal|1
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
operator|!
name|screenoff_enabled
condition|)
block|{
comment|// screenoff is disabled, ignore the key/mouse event that wakes from suspend
name|blocklevel
operator|=
literal|2
expr_stmt|;
if|if
condition|(
operator|!
name|suspend_enabled
condition|)
block|{
comment|// suspend is disabled, never ignore events
name|blocklevel
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
end_if
begin_expr_stmt
name|QWSServer
operator|::
name|setScreenSaverBlockLevel
argument_list|(
name|blocklevel
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
end_unit
