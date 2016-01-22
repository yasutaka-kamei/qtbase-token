begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_include
include|#
directive|include
file|"editablesqlmodel.h"
end_include
begin_constructor
DECL|function|EditableSqlModel
name|EditableSqlModel
operator|::
name|EditableSqlModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSqlQueryModel
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|flags
name|Qt
operator|::
name|ItemFlags
name|EditableSqlModel
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
name|Qt
operator|::
name|ItemFlags
name|flags
init|=
name|QSqlQueryModel
operator|::
name|flags
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|==
literal|1
operator|||
name|index
operator|.
name|column
argument_list|()
operator|==
literal|2
condition|)
name|flags
operator||=
name|Qt
operator|::
name|ItemIsEditable
expr_stmt|;
return|return
name|flags
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|setData
name|bool
name|EditableSqlModel
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
comment|/* role */
parameter_list|)
block|{
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|<
literal|1
operator|||
name|index
operator|.
name|column
argument_list|()
operator|>
literal|2
condition|)
return|return
literal|false
return|;
name|QModelIndex
name|primaryKeyIndex
init|=
name|QSqlQueryModel
operator|::
name|index
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|id
init|=
name|data
argument_list|(
name|primaryKeyIndex
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|clear
argument_list|()
expr_stmt|;
name|bool
name|ok
decl_stmt|;
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|==
literal|1
condition|)
block|{
name|ok
operator|=
name|setFirstName
argument_list|(
name|id
argument_list|,
name|value
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ok
operator|=
name|setLastName
argument_list|(
name|id
argument_list|,
name|value
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|refresh
argument_list|()
expr_stmt|;
return|return
name|ok
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|refresh
name|void
name|EditableSqlModel
operator|::
name|refresh
parameter_list|()
block|{
name|setQuery
argument_list|(
literal|"select * from person"
argument_list|)
expr_stmt|;
name|setHeaderData
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"ID"
argument_list|)
argument_list|)
expr_stmt|;
name|setHeaderData
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"First name"
argument_list|)
argument_list|)
expr_stmt|;
name|setHeaderData
argument_list|(
literal|2
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Last name"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|setFirstName
name|bool
name|EditableSqlModel
operator|::
name|setFirstName
parameter_list|(
name|int
name|personId
parameter_list|,
specifier|const
name|QString
modifier|&
name|firstName
parameter_list|)
block|{
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|prepare
argument_list|(
literal|"update person set firstname = ? where id = ?"
argument_list|)
expr_stmt|;
name|query
operator|.
name|addBindValue
argument_list|(
name|firstName
argument_list|)
expr_stmt|;
name|query
operator|.
name|addBindValue
argument_list|(
name|personId
argument_list|)
expr_stmt|;
return|return
name|query
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|setLastName
name|bool
name|EditableSqlModel
operator|::
name|setLastName
parameter_list|(
name|int
name|personId
parameter_list|,
specifier|const
name|QString
modifier|&
name|lastName
parameter_list|)
block|{
name|QSqlQuery
name|query
decl_stmt|;
name|query
operator|.
name|prepare
argument_list|(
literal|"update person set lastname = ? where id = ?"
argument_list|)
expr_stmt|;
name|query
operator|.
name|addBindValue
argument_list|(
name|lastName
argument_list|)
expr_stmt|;
name|query
operator|.
name|addBindValue
argument_list|(
name|personId
argument_list|)
expr_stmt|;
return|return
name|query
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
