begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"imagedelegate.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|ImageDelegate
name|ImageDelegate
operator|::
name|ImageDelegate
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QItemDelegate
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|createEditor
name|QWidget
modifier|*
name|ImageDelegate
operator|::
name|createEditor
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
comment|/* option */
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|QComboBox
modifier|*
name|comboBox
init|=
operator|new
name|QComboBox
argument_list|(
name|parent
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
condition|)
block|{
name|comboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Normal"
argument_list|)
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Active"
argument_list|)
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Disabled"
argument_list|)
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Selected"
argument_list|)
argument_list|)
expr_stmt|;
block|}
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
block|{
name|comboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Off"
argument_list|)
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"On"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
name|comboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|emitCommitData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|comboBox
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|setEditorData
name|void
name|ImageDelegate
operator|::
name|setEditorData
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|QComboBox
modifier|*
name|comboBox
init|=
name|qobject_cast
argument_list|<
name|QComboBox
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|comboBox
condition|)
return|return;
name|int
name|pos
init|=
name|comboBox
operator|->
name|findText
argument_list|(
name|index
operator|.
name|model
argument_list|()
operator|->
name|data
argument_list|(
name|index
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|Qt
operator|::
name|MatchExactly
argument_list|)
decl_stmt|;
name|comboBox
operator|->
name|setCurrentIndex
argument_list|(
name|pos
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|setModelData
name|void
name|ImageDelegate
operator|::
name|setModelData
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|,
name|QAbstractItemModel
modifier|*
name|model
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|QComboBox
modifier|*
name|comboBox
init|=
name|qobject_cast
argument_list|<
name|QComboBox
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|comboBox
condition|)
return|return;
name|model
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|comboBox
operator|->
name|currentText
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|emitCommitData
name|void
name|ImageDelegate
operator|::
name|emitCommitData
parameter_list|()
block|{
emit|emit
name|commitData
argument_list|(
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
