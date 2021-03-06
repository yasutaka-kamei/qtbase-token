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
file|"settingstree.h"
end_include
begin_include
include|#
directive|include
file|"variantdelegate.h"
end_include
begin_constructor
DECL|function|SettingsTree
name|SettingsTree
operator|::
name|SettingsTree
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QTreeWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|autoRefresh
argument_list|(
literal|false
argument_list|)
block|{
name|setItemDelegate
argument_list|(
operator|new
name|VariantDelegate
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|labels
decl_stmt|;
name|labels
operator|<<
name|tr
argument_list|(
literal|"Setting"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Type"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Value"
argument_list|)
expr_stmt|;
name|setHeaderLabels
argument_list|(
name|labels
argument_list|)
expr_stmt|;
name|header
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
literal|0
argument_list|,
name|QHeaderView
operator|::
name|ResizeToContents
argument_list|)
expr_stmt|;
name|header
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
literal|1
argument_list|,
name|QHeaderView
operator|::
name|ResizeToContents
argument_list|)
expr_stmt|;
name|header
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
literal|2
argument_list|,
name|QHeaderView
operator|::
name|Stretch
argument_list|)
expr_stmt|;
name|refreshTimer
operator|.
name|setInterval
argument_list|(
literal|2000
argument_list|)
expr_stmt|;
name|groupIcon
operator|.
name|addPixmap
argument_list|(
name|style
argument_list|()
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_DirClosedIcon
argument_list|)
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|Off
argument_list|)
expr_stmt|;
name|groupIcon
operator|.
name|addPixmap
argument_list|(
name|style
argument_list|()
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_DirOpenIcon
argument_list|)
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|On
argument_list|)
expr_stmt|;
name|keyIcon
operator|.
name|addPixmap
argument_list|(
name|style
argument_list|()
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_FileIcon
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|refreshTimer
argument_list|,
operator|&
name|QTimer
operator|::
name|timeout
argument_list|,
name|this
argument_list|,
operator|&
name|SettingsTree
operator|::
name|maybeRefresh
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~SettingsTree
name|SettingsTree
operator|::
name|~
name|SettingsTree
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|setSettingsObject
name|void
name|SettingsTree
operator|::
name|setSettingsObject
parameter_list|(
specifier|const
name|SettingsPtr
modifier|&
name|newSettings
parameter_list|)
block|{
name|settings
operator|=
name|newSettings
expr_stmt|;
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|settings
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|refreshTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|refresh
argument_list|()
expr_stmt|;
if|if
condition|(
name|autoRefresh
condition|)
name|refreshTimer
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSize
name|SettingsTree
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
specifier|const
name|QRect
name|availableGeometry
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|(
name|this
argument_list|)
decl_stmt|;
return|return
name|QSize
argument_list|(
name|availableGeometry
operator|.
name|width
argument_list|()
operator|*
literal|2
operator|/
literal|3
argument_list|,
name|availableGeometry
operator|.
name|height
argument_list|()
operator|*
literal|2
operator|/
literal|3
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setAutoRefresh
name|void
name|SettingsTree
operator|::
name|setAutoRefresh
parameter_list|(
name|bool
name|autoRefresh
parameter_list|)
block|{
name|this
operator|->
name|autoRefresh
operator|=
name|autoRefresh
expr_stmt|;
if|if
condition|(
operator|!
name|settings
operator|.
name|isNull
argument_list|()
condition|)
block|{
if|if
condition|(
name|autoRefresh
condition|)
block|{
name|maybeRefresh
argument_list|()
expr_stmt|;
name|refreshTimer
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|refreshTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|setFallbacksEnabled
name|void
name|SettingsTree
operator|::
name|setFallbacksEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
if|if
condition|(
operator|!
name|settings
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|settings
operator|->
name|setFallbacksEnabled
argument_list|(
name|enabled
argument_list|)
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|maybeRefresh
name|void
name|SettingsTree
operator|::
name|maybeRefresh
parameter_list|()
block|{
if|if
condition|(
name|state
argument_list|()
operator|!=
name|EditingState
condition|)
name|refresh
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|refresh
name|void
name|SettingsTree
operator|::
name|refresh
parameter_list|()
block|{
if|if
condition|(
name|settings
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|disconnect
argument_list|(
name|this
argument_list|,
operator|&
name|QTreeWidget
operator|::
name|itemChanged
argument_list|,
name|this
argument_list|,
operator|&
name|SettingsTree
operator|::
name|updateSetting
argument_list|)
expr_stmt|;
name|settings
operator|->
name|sync
argument_list|()
expr_stmt|;
name|updateChildItems
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
operator|&
name|QTreeWidget
operator|::
name|itemChanged
argument_list|,
name|this
argument_list|,
operator|&
name|SettingsTree
operator|::
name|updateSetting
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|SettingsTree
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|WindowActivate
condition|)
block|{
if|if
condition|(
name|isActiveWindow
argument_list|()
operator|&&
name|autoRefresh
condition|)
name|maybeRefresh
argument_list|()
expr_stmt|;
block|}
return|return
name|QTreeWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|updateSetting
name|void
name|SettingsTree
operator|::
name|updateSetting
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
block|{
name|QString
name|key
init|=
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QTreeWidgetItem
modifier|*
name|ancestor
init|=
name|item
operator|->
name|parent
argument_list|()
decl_stmt|;
while|while
condition|(
name|ancestor
condition|)
block|{
name|key
operator|.
name|prepend
argument_list|(
name|ancestor
operator|->
name|text
argument_list|(
literal|0
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
expr_stmt|;
name|ancestor
operator|=
name|ancestor
operator|->
name|parent
argument_list|()
expr_stmt|;
block|}
name|settings
operator|->
name|setValue
argument_list|(
name|key
argument_list|,
name|item
operator|->
name|data
argument_list|(
literal|2
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|autoRefresh
condition|)
name|refresh
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateChildItems
name|void
name|SettingsTree
operator|::
name|updateChildItems
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|parent
parameter_list|)
block|{
name|int
name|dividerIndex
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|QString
name|group
decl|,
name|settings
operator|->
name|childGroups
argument_list|()
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|child
decl_stmt|;
name|int
name|childIndex
init|=
name|findChild
argument_list|(
name|parent
argument_list|,
name|group
argument_list|,
name|dividerIndex
argument_list|)
decl_stmt|;
if|if
condition|(
name|childIndex
operator|!=
operator|-
literal|1
condition|)
block|{
name|child
operator|=
name|childAt
argument_list|(
name|parent
argument_list|,
name|childIndex
argument_list|)
expr_stmt|;
name|child
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|child
operator|->
name|setText
argument_list|(
literal|2
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|child
operator|->
name|setData
argument_list|(
literal|2
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
name|moveItemForward
argument_list|(
name|parent
argument_list|,
name|childIndex
argument_list|,
name|dividerIndex
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|child
operator|=
name|createItem
argument_list|(
name|group
argument_list|,
name|parent
argument_list|,
name|dividerIndex
argument_list|)
expr_stmt|;
block|}
name|child
operator|->
name|setIcon
argument_list|(
literal|0
argument_list|,
name|groupIcon
argument_list|)
expr_stmt|;
operator|++
name|dividerIndex
expr_stmt|;
name|settings
operator|->
name|beginGroup
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|updateChildItems
argument_list|(
name|child
argument_list|)
expr_stmt|;
name|settings
operator|->
name|endGroup
argument_list|()
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|key
decl|,
name|settings
operator|->
name|childKeys
argument_list|()
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|child
decl_stmt|;
name|int
name|childIndex
init|=
name|findChild
argument_list|(
name|parent
argument_list|,
name|key
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|childIndex
operator|==
operator|-
literal|1
operator|||
name|childIndex
operator|>=
name|dividerIndex
condition|)
block|{
if|if
condition|(
name|childIndex
operator|!=
operator|-
literal|1
condition|)
block|{
name|child
operator|=
name|childAt
argument_list|(
name|parent
argument_list|,
name|childIndex
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|child
operator|->
name|childCount
argument_list|()
condition|;
operator|++
name|i
control|)
operator|delete
name|childAt
argument_list|(
name|child
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|moveItemForward
argument_list|(
name|parent
argument_list|,
name|childIndex
argument_list|,
name|dividerIndex
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|child
operator|=
name|createItem
argument_list|(
name|key
argument_list|,
name|parent
argument_list|,
name|dividerIndex
argument_list|)
expr_stmt|;
block|}
name|child
operator|->
name|setIcon
argument_list|(
literal|0
argument_list|,
name|keyIcon
argument_list|)
expr_stmt|;
operator|++
name|dividerIndex
expr_stmt|;
block|}
else|else
block|{
name|child
operator|=
name|childAt
argument_list|(
name|parent
argument_list|,
name|childIndex
argument_list|)
expr_stmt|;
block|}
name|QVariant
name|value
init|=
name|settings
operator|->
name|value
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|value
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Invalid
condition|)
block|{
name|child
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
literal|"Invalid"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|child
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
name|value
operator|.
name|typeName
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|child
operator|->
name|setText
argument_list|(
literal|2
argument_list|,
name|VariantDelegate
operator|::
name|displayText
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
name|child
operator|->
name|setData
argument_list|(
literal|2
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|dividerIndex
operator|<
name|childCount
argument_list|(
name|parent
argument_list|)
condition|)
operator|delete
name|childAt
argument_list|(
name|parent
argument_list|,
name|dividerIndex
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createItem
name|QTreeWidgetItem
modifier|*
name|SettingsTree
operator|::
name|createItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QTreeWidgetItem
modifier|*
name|parent
parameter_list|,
name|int
name|index
parameter_list|)
block|{
name|QTreeWidgetItem
modifier|*
name|after
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|index
operator|!=
literal|0
condition|)
name|after
operator|=
name|childAt
argument_list|(
name|parent
argument_list|,
name|index
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|item
decl_stmt|;
if|if
condition|(
name|parent
condition|)
name|item
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|parent
argument_list|,
name|after
argument_list|)
expr_stmt|;
else|else
name|item
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|this
argument_list|,
name|after
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFlags
argument_list|(
name|item
operator|->
name|flags
argument_list|()
operator||
name|Qt
operator|::
name|ItemIsEditable
argument_list|)
expr_stmt|;
return|return
name|item
return|;
block|}
end_function
begin_function
DECL|function|childAt
name|QTreeWidgetItem
modifier|*
name|SettingsTree
operator|::
name|childAt
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|parent
parameter_list|,
name|int
name|index
parameter_list|)
block|{
if|if
condition|(
name|parent
condition|)
return|return
name|parent
operator|->
name|child
argument_list|(
name|index
argument_list|)
return|;
else|else
return|return
name|topLevelItem
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|childCount
name|int
name|SettingsTree
operator|::
name|childCount
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|parent
parameter_list|)
block|{
if|if
condition|(
name|parent
condition|)
return|return
name|parent
operator|->
name|childCount
argument_list|()
return|;
else|else
return|return
name|topLevelItemCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|findChild
name|int
name|SettingsTree
operator|::
name|findChild
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|int
name|startIndex
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
name|startIndex
init|;
name|i
operator|<
name|childCount
argument_list|(
name|parent
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|childAt
argument_list|(
name|parent
argument_list|,
name|i
argument_list|)
operator|->
name|text
argument_list|(
literal|0
argument_list|)
operator|==
name|text
condition|)
return|return
name|i
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|moveItemForward
name|void
name|SettingsTree
operator|::
name|moveItemForward
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|parent
parameter_list|,
name|int
name|oldIndex
parameter_list|,
name|int
name|newIndex
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|oldIndex
operator|-
name|newIndex
condition|;
operator|++
name|i
control|)
operator|delete
name|childAt
argument_list|(
name|parent
argument_list|,
name|newIndex
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
