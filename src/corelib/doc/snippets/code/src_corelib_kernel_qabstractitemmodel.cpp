begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_expr_stmt
name|beginInsertRows
argument_list|(
name|parent
argument_list|,
literal|2
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|beginInsertRows
argument_list|(
name|parent
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_expr_stmt
name|beginRemoveRows
argument_list|(
name|parent
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_expr_stmt
name|beginInsertColumns
argument_list|(
name|parent
argument_list|,
literal|4
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_expr_stmt
name|beginInsertColumns
argument_list|(
name|parent
argument_list|,
literal|6
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_expr_stmt
name|beginRemoveColumns
argument_list|(
name|parent
argument_list|,
literal|4
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_expr_stmt
name|beginMoveRows
argument_list|(
name|sourceParent
argument_list|,
literal|2
argument_list|,
literal|4
argument_list|,
name|destinationParent
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_expr_stmt
name|beginMoveRows
argument_list|(
name|sourceParent
argument_list|,
literal|2
argument_list|,
literal|4
argument_list|,
name|destinationParent
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_expr_stmt
name|beginMoveRows
argument_list|(
name|parent
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|,
name|parent
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_expr_stmt
name|beginMoveRows
argument_list|(
name|parent
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|,
name|parent
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_expr_stmt
name|myData
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|reset
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_expr_stmt
name|beginResetModel
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|myData
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|endResetModel
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_class
DECL|class|CustomDataProxy
class|class
name|CustomDataProxy
super|:
specifier|public
name|QSortFilterProxyModel
block|{
name|Q_OBJECT
public|public:
DECL|function|CustomDataProxy
name|CustomDataProxy
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSortFilterProxyModel
argument_list|(
name|parent
argument_list|)
block|{     }
operator|...
DECL|function|data
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role
argument_list|)
block|{
if|if
condition|(
name|role
operator|!=
name|Qt
operator|::
name|BackgroundRole
condition|)
return|return
name|QSortFilterProxyModel
operator|::
name|data
argument_list|(
name|index
argument_list|,
name|role
argument_list|)
return|;
if|if
condition|(
name|m_customData
operator|.
name|contains
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
condition|)
return|return
name|m_customData
operator|.
name|value
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
return|;
return|return
name|QSortFilterProxyModel
operator|::
name|data
argument_list|(
name|index
argument_list|,
name|role
argument_list|)
return|;
block|}
decl|private
name|slots
range|:
DECL|function|resetInternalData
name|void
name|resetInternalData
argument_list|()
block|{
name|m_customData
operator|.
name|clear
argument_list|()
block|;     }
specifier|private
operator|:
DECL|member|m_customData
name|QHash
argument_list|<
name|int
argument_list|,
name|QVariant
argument_list|>
name|m_customData
class|;
end_class
begin_comment
unit|};
comment|//! [12]
end_comment
end_unit
