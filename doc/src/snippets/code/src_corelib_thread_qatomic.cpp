begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|operator =
name|MySharedType
modifier|&
name|MySharedType
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|MySharedType
modifier|&
name|other
parameter_list|)
block|{
operator|(
name|void
operator|)
name|other
operator|.
name|data
operator|->
name|atomicInt
operator|.
name|ref
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|data
operator|->
name|atomicInt
operator|.
name|deref
argument_list|()
condition|)
block|{
comment|// The last reference has been released
operator|delete
name|d
expr_stmt|;
block|}
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_if
if|if
condition|(
name|currentValue
operator|==
name|expectedValue
condition|)
block|{
name|currentValue
operator|=
name|newValue
expr_stmt|;
return|return
literal|true
return|;
block|}
end_if
begin_return
return|return
literal|false
return|;
end_return
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|originalValue
name|int
name|originalValue
init|=
name|currentValue
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|currentValue
operator|=
name|newValue
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|originalValue
return|;
end_return
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|originalValue
name|int
name|originalValue
init|=
name|currentValue
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|currentValue
operator|+=
name|valueToAdd
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|originalValue
return|;
end_return
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_if
if|if
condition|(
name|currentValue
operator|==
name|expectedValue
condition|)
block|{
name|currentValue
operator|=
name|newValue
expr_stmt|;
return|return
literal|true
return|;
block|}
end_if
begin_return
return|return
literal|false
return|;
end_return
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
name|T
modifier|*
name|originalValue
init|=
name|currentValue
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|currentValue
operator|=
name|newValue
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|originalValue
return|;
end_return
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
name|T
modifier|*
name|originalValue
init|=
name|currentValue
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|currentValue
operator|+=
name|valueToAdd
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|originalValue
return|;
end_return
begin_comment
comment|//! [6]
end_comment
end_unit
