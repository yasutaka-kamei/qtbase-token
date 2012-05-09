begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of an example program for Qt. ** EDITIONS: NOLIMITS ** ****************************************************************************/
end_comment
begin_comment
comment|/*   model.cpp    A simple model that uses a QStringList as its data source. */
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"model.h"
end_include
begin_constructor
DECL|function|DragDropListModel
name|DragDropListModel
operator|::
name|DragDropListModel
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|strings
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QStringListModel
argument_list|(
name|strings
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|dropMimeData
name|bool
name|DragDropListModel
operator|::
name|dropMimeData
parameter_list|(
specifier|const
name|QMimeData
modifier|*
name|data
parameter_list|,
name|Qt
operator|::
name|DropAction
name|action
parameter_list|,
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
block|{
if|if
condition|(
name|action
operator|==
name|Qt
operator|::
name|IgnoreAction
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|!
name|data
operator|->
name|hasFormat
argument_list|(
literal|"application/vnd.text.list"
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|column
operator|>
literal|0
condition|)
comment|//! [0] //! [1]
return|return
literal|false
return|;
comment|//! [1]
comment|//! [2]
name|int
name|beginRow
decl_stmt|;
if|if
condition|(
name|row
operator|!=
operator|-
literal|1
condition|)
name|beginRow
operator|=
name|row
expr_stmt|;
comment|//! [2] //! [3]
elseif|else
if|if
condition|(
name|parent
operator|.
name|isValid
argument_list|()
condition|)
name|beginRow
operator|=
name|parent
operator|.
name|row
argument_list|()
expr_stmt|;
comment|//! [3] //! [4]
else|else
name|beginRow
operator|=
name|rowCount
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|QByteArray
name|encodedData
init|=
name|data
operator|->
name|data
argument_list|(
literal|"application/vnd.text.list"
argument_list|)
decl_stmt|;
name|QDataStream
name|stream
argument_list|(
operator|&
name|encodedData
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|QStringList
name|newItems
decl_stmt|;
name|int
name|rows
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|!
name|stream
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|text
decl_stmt|;
name|stream
operator|>>
name|text
expr_stmt|;
name|newItems
operator|<<
name|text
expr_stmt|;
operator|++
name|rows
expr_stmt|;
block|}
comment|//! [5]
comment|//! [6]
name|insertRows
argument_list|(
name|beginRow
argument_list|,
name|rows
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|text
decl|,
name|newItems
control|)
block|{
name|QModelIndex
name|idx
init|=
name|index
argument_list|(
name|beginRow
argument_list|,
literal|0
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
decl_stmt|;
name|setData
argument_list|(
name|idx
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|beginRow
operator|++
expr_stmt|;
block|}
return|return
literal|true
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
DECL|function|flags
name|Qt
operator|::
name|ItemFlags
name|DragDropListModel
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
name|defaultFlags
init|=
name|QStringListModel
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
name|isValid
argument_list|()
condition|)
return|return
name|Qt
operator|::
name|ItemIsDragEnabled
operator||
name|Qt
operator|::
name|ItemIsDropEnabled
operator||
name|defaultFlags
return|;
else|else
return|return
name|Qt
operator|::
name|ItemIsDropEnabled
operator||
name|defaultFlags
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
DECL|function|mimeData
name|QMimeData
modifier|*
name|DragDropListModel
operator|::
name|mimeData
parameter_list|(
specifier|const
name|QModelIndexList
modifier|&
name|indexes
parameter_list|)
specifier|const
block|{
name|QMimeData
modifier|*
name|mimeData
init|=
operator|new
name|QMimeData
argument_list|()
decl_stmt|;
name|QByteArray
name|encodedData
decl_stmt|;
name|QDataStream
name|stream
argument_list|(
operator|&
name|encodedData
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QModelIndex
modifier|&
name|index
decl|,
name|indexes
control|)
block|{
if|if
condition|(
name|index
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QString
name|text
init|=
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|stream
operator|<<
name|text
expr_stmt|;
block|}
block|}
name|mimeData
operator|->
name|setData
argument_list|(
literal|"application/vnd.text.list"
argument_list|,
name|encodedData
argument_list|)
expr_stmt|;
return|return
name|mimeData
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
DECL|function|mimeTypes
name|QStringList
name|DragDropListModel
operator|::
name|mimeTypes
parameter_list|()
specifier|const
block|{
name|QStringList
name|types
decl_stmt|;
name|types
operator|<<
literal|"application/vnd.text.list"
expr_stmt|;
return|return
name|types
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
DECL|function|supportedDropActions
name|Qt
operator|::
name|DropActions
name|DragDropListModel
operator|::
name|supportedDropActions
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|CopyAction
operator||
name|Qt
operator|::
name|MoveAction
return|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
end_unit
