begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*     treeitem.cpp      A container for items of data supplied by the simple tree model. */
end_comment
begin_include
include|#
directive|include
file|"treeitem.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|TreeItem
name|TreeItem
operator|::
name|TreeItem
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|QVariant
argument_list|>
modifier|&
name|data
parameter_list|,
name|TreeItem
modifier|*
name|parent
parameter_list|)
block|{
name|parentItem
operator|=
name|parent
expr_stmt|;
name|itemData
operator|=
name|data
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_destructor
DECL|function|~TreeItem
name|TreeItem
operator|::
name|~
name|TreeItem
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|childItems
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|child
name|TreeItem
modifier|*
name|TreeItem
operator|::
name|child
parameter_list|(
name|int
name|number
parameter_list|)
block|{
return|return
name|childItems
operator|.
name|value
argument_list|(
name|number
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|childCount
name|int
name|TreeItem
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
return|return
name|childItems
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|childNumber
name|int
name|TreeItem
operator|::
name|childNumber
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|parentItem
condition|)
return|return
name|parentItem
operator|->
name|childItems
operator|.
name|indexOf
argument_list|(
cast|const_cast
argument_list|<
name|TreeItem
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|columnCount
name|int
name|TreeItem
operator|::
name|columnCount
parameter_list|()
specifier|const
block|{
return|return
name|itemData
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|data
name|QVariant
name|TreeItem
operator|::
name|data
parameter_list|(
name|int
name|column
parameter_list|)
specifier|const
block|{
return|return
name|itemData
operator|.
name|value
argument_list|(
name|column
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|insertChildren
name|bool
name|TreeItem
operator|::
name|insertChildren
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|columns
parameter_list|)
block|{
if|if
condition|(
name|position
argument_list|<
literal|0
operator|||
name|position
argument_list|>
name|childItems
operator|.
name|size
argument_list|()
condition|)
return|return
literal|false
return|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|count
condition|;
operator|++
name|row
control|)
block|{
name|QVector
argument_list|<
name|QVariant
argument_list|>
name|data
argument_list|(
name|columns
argument_list|)
decl_stmt|;
name|TreeItem
modifier|*
name|item
init|=
operator|new
name|TreeItem
argument_list|(
name|data
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|childItems
operator|.
name|insert
argument_list|(
name|position
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|insertColumns
name|bool
name|TreeItem
operator|::
name|insertColumns
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|columns
parameter_list|)
block|{
if|if
condition|(
name|position
argument_list|<
literal|0
operator|||
name|position
argument_list|>
name|itemData
operator|.
name|size
argument_list|()
condition|)
return|return
literal|false
return|;
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
name|columns
condition|;
operator|++
name|column
control|)
name|itemData
operator|.
name|insert
argument_list|(
name|position
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|TreeItem
modifier|*
name|child
decl|,
name|childItems
control|)
name|child
operator|->
name|insertColumns
argument_list|(
name|position
argument_list|,
name|columns
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|parent
name|TreeItem
modifier|*
name|TreeItem
operator|::
name|parent
parameter_list|()
block|{
return|return
name|parentItem
return|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|removeChildren
name|bool
name|TreeItem
operator|::
name|removeChildren
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|count
parameter_list|)
block|{
if|if
condition|(
name|position
argument_list|<
literal|0
operator|||
name|position
operator|+
name|count
argument_list|>
name|childItems
operator|.
name|size
argument_list|()
condition|)
return|return
literal|false
return|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|count
condition|;
operator|++
name|row
control|)
operator|delete
name|childItems
operator|.
name|takeAt
argument_list|(
name|position
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|removeColumns
name|bool
name|TreeItem
operator|::
name|removeColumns
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|columns
parameter_list|)
block|{
if|if
condition|(
name|position
argument_list|<
literal|0
operator|||
name|position
operator|+
name|columns
argument_list|>
name|itemData
operator|.
name|size
argument_list|()
condition|)
return|return
literal|false
return|;
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
name|columns
condition|;
operator|++
name|column
control|)
name|itemData
operator|.
name|remove
argument_list|(
name|position
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|TreeItem
modifier|*
name|child
decl|,
name|childItems
control|)
name|child
operator|->
name|removeColumns
argument_list|(
name|position
argument_list|,
name|columns
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|setData
name|bool
name|TreeItem
operator|::
name|setData
parameter_list|(
name|int
name|column
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|column
operator|<
literal|0
operator|||
name|column
operator|>=
name|itemData
operator|.
name|size
argument_list|()
condition|)
return|return
literal|false
return|;
name|itemData
index|[
name|column
index|]
operator|=
name|value
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
end_unit
