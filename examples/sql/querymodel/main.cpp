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
file|"../connection.h"
end_include
begin_include
include|#
directive|include
file|"customsqlmodel.h"
end_include
begin_include
include|#
directive|include
file|"editablesqlmodel.h"
end_include
begin_function
DECL|function|initializeModel
name|void
name|initializeModel
parameter_list|(
name|QSqlQueryModel
modifier|*
name|model
parameter_list|)
block|{
name|model
operator|->
name|setQuery
argument_list|(
literal|"select * from person"
argument_list|)
expr_stmt|;
name|model
operator|->
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
name|model
operator|->
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
name|model
operator|->
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
begin_function
DECL|function|createView
name|QTableView
modifier|*
name|createView
parameter_list|(
name|QSqlQueryModel
modifier|*
name|model
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
init|=
literal|""
parameter_list|)
block|{
name|QTableView
modifier|*
name|view
init|=
operator|new
name|QTableView
decl_stmt|;
name|view
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
specifier|static
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|view
operator|->
name|setWindowTitle
argument_list|(
name|title
argument_list|)
expr_stmt|;
name|view
operator|->
name|move
argument_list|(
literal|100
operator|+
name|offset
argument_list|,
literal|100
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|20
expr_stmt|;
name|view
operator|->
name|show
argument_list|()
expr_stmt|;
return|return
name|view
return|;
block|}
end_function
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
if|if
condition|(
operator|!
name|createConnection
argument_list|()
condition|)
return|return
literal|1
return|;
name|QSqlQueryModel
name|plainModel
decl_stmt|;
name|EditableSqlModel
name|editableModel
decl_stmt|;
name|CustomSqlModel
name|customModel
decl_stmt|;
name|initializeModel
argument_list|(
operator|&
name|plainModel
argument_list|)
expr_stmt|;
name|initializeModel
argument_list|(
operator|&
name|editableModel
argument_list|)
expr_stmt|;
name|initializeModel
argument_list|(
operator|&
name|customModel
argument_list|)
expr_stmt|;
name|createView
argument_list|(
operator|&
name|plainModel
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Plain Query Model"
argument_list|)
argument_list|)
expr_stmt|;
name|createView
argument_list|(
operator|&
name|editableModel
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Editable Query Model"
argument_list|)
argument_list|)
expr_stmt|;
name|createView
argument_list|(
operator|&
name|customModel
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Custom Query Model"
argument_list|)
argument_list|)
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
