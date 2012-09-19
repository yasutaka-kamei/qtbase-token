begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
comment|//-------------------------------------------------------
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
literal|2
return|;
block|}
end_function
begin_comment
comment|//-------------------------------------------------------
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
literal|3
return|;
block|}
end_function
begin_comment
comment|//-------------------------------------------------------
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
name|QString
argument_list|(
literal|"Row%1, Column%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|index
operator|.
name|row
argument_list|()
operator|+
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|index
operator|.
name|column
argument_list|()
operator|+
literal|1
argument_list|)
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [quoting mymodel_c]
end_comment
begin_function
DECL|function|headerData
name|QVariant
name|MyModel
operator|::
name|headerData
parameter_list|(
name|int
name|section
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
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
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
switch|switch
condition|(
name|section
condition|)
block|{
case|case
literal|0
case|:
return|return
name|QString
argument_list|(
literal|"first"
argument_list|)
return|;
case|case
literal|1
case|:
return|return
name|QString
argument_list|(
literal|"second"
argument_list|)
return|;
case|case
literal|2
case|:
return|return
name|QString
argument_list|(
literal|"third"
argument_list|)
return|;
block|}
block|}
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [quoting mymodel_c]
end_comment
end_unit
