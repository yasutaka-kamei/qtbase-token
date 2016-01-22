begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mymodel.h"
end_include
begin_constructor
DECL|function|MyModel
name|MyModel
operator|::
name|MyModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractTableModel
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//-----------------------------------------------------------------
end_comment
begin_function
DECL|function|rowCount
name|int
name|MyModel
operator|::
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
comment|/*parent*/
parameter_list|)
specifier|const
block|{
return|return
name|ROWS
return|;
block|}
end_function
begin_comment
comment|//-----------------------------------------------------------------
end_comment
begin_function
DECL|function|columnCount
name|int
name|MyModel
operator|::
name|columnCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
comment|/*parent*/
parameter_list|)
specifier|const
block|{
return|return
name|COLS
return|;
block|}
end_function
begin_comment
comment|//-----------------------------------------------------------------
end_comment
begin_function
DECL|function|data
name|QVariant
name|MyModel
operator|::
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
condition|)
block|{
return|return
name|m_gridData
index|[
name|index
operator|.
name|row
argument_list|()
index|]
index|[
name|index
operator|.
name|column
argument_list|()
index|]
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//-----------------------------------------------------------------
end_comment
begin_comment
comment|//! [quoting mymodel_e]
end_comment
begin_function
DECL|function|setData
name|bool
name|MyModel
operator|::
name|setData
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|,
name|int
name|role
parameter_list|)
block|{
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|EditRole
condition|)
block|{
comment|//save value from editor to member m_gridData
name|m_gridData
index|[
name|index
operator|.
name|row
argument_list|()
index|]
index|[
name|index
operator|.
name|column
argument_list|()
index|]
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
comment|//for presentation purposes only: build and emit a joined string
name|QString
name|result
decl_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|ROWS
condition|;
name|row
operator|++
control|)
block|{
for|for
control|(
name|int
name|col
init|=
literal|0
init|;
name|col
operator|<
name|COLS
condition|;
name|col
operator|++
control|)
block|{
name|result
operator|+=
name|m_gridData
index|[
name|row
index|]
index|[
name|col
index|]
operator|+
literal|' '
expr_stmt|;
block|}
block|}
emit|emit
name|editCompleted
argument_list|(
name|result
argument_list|)
emit|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [quoting mymodel_e]
end_comment
begin_comment
comment|//-----------------------------------------------------------------
end_comment
begin_comment
comment|//! [quoting mymodel_f]
end_comment
begin_function
DECL|function|flags
name|Qt
operator|::
name|ItemFlags
name|MyModel
operator|::
name|flags
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
return|return
name|Qt
operator|::
name|ItemIsEditable
operator||
name|QAbstractTableModel
operator|::
name|flags
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [quoting mymodel_f]
end_comment
end_unit
