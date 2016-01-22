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
file|"customsqlmodel.h"
end_include
begin_constructor
DECL|function|CustomSqlModel
name|CustomSqlModel
operator|::
name|CustomSqlModel
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
DECL|function|data
name|QVariant
name|CustomSqlModel
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
name|QVariant
name|value
init|=
name|QSqlQueryModel
operator|::
name|data
argument_list|(
name|index
argument_list|,
name|role
argument_list|)
decl_stmt|;
if|if
condition|(
name|value
operator|.
name|isValid
argument_list|()
operator|&&
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
condition|)
block|{
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|==
literal|0
condition|)
return|return
name|value
operator|.
name|toString
argument_list|()
operator|.
name|prepend
argument_list|(
literal|'#'
argument_list|)
return|;
elseif|else
if|if
condition|(
name|index
operator|.
name|column
argument_list|()
operator|==
literal|2
condition|)
return|return
name|value
operator|.
name|toString
argument_list|()
operator|.
name|toUpper
argument_list|()
return|;
block|}
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|TextColorRole
operator|&&
name|index
operator|.
name|column
argument_list|()
operator|==
literal|1
condition|)
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
return|;
return|return
name|value
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
end_unit
