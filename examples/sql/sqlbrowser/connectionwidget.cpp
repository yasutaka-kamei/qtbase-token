begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"connectionwidget.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_constructor
DECL|function|ConnectionWidget
name|ConnectionWidget
operator|::
name|ConnectionWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|tree
operator|=
operator|new
name|QTreeWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|tree
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"tree"
argument_list|)
argument_list|)
expr_stmt|;
name|tree
operator|->
name|setHeaderLabels
argument_list|(
name|QStringList
argument_list|(
name|tr
argument_list|(
literal|"database"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tree
operator|->
name|header
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
name|QHeaderView
operator|::
name|Stretch
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|refreshAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Refresh"
argument_list|)
argument_list|,
name|tree
argument_list|)
decl_stmt|;
name|metaDataAction
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Show Schema"
argument_list|)
argument_list|,
name|tree
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|refreshAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|refresh
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|metaDataAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|showMetaData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|tree
operator|->
name|addAction
argument_list|(
name|refreshAction
argument_list|)
expr_stmt|;
name|tree
operator|->
name|addAction
argument_list|(
name|metaDataAction
argument_list|)
expr_stmt|;
name|tree
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|ActionsContextMenu
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|tree
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~ConnectionWidget
name|ConnectionWidget
operator|::
name|~
name|ConnectionWidget
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|qDBCaption
specifier|static
name|QString
name|qDBCaption
parameter_list|(
specifier|const
name|QSqlDatabase
modifier|&
name|db
parameter_list|)
block|{
name|QString
name|nm
init|=
name|db
operator|.
name|driverName
argument_list|()
decl_stmt|;
name|nm
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|db
operator|.
name|userName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|nm
operator|.
name|append
argument_list|(
name|db
operator|.
name|userName
argument_list|()
argument_list|)
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'@'
argument_list|)
argument_list|)
expr_stmt|;
name|nm
operator|.
name|append
argument_list|(
name|db
operator|.
name|databaseName
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|nm
return|;
block|}
end_function
begin_function
DECL|function|refresh
name|void
name|ConnectionWidget
operator|::
name|refresh
parameter_list|()
block|{
name|tree
operator|->
name|clear
argument_list|()
expr_stmt|;
name|QStringList
name|connectionNames
init|=
name|QSqlDatabase
operator|::
name|connectionNames
argument_list|()
decl_stmt|;
name|bool
name|gotActiveDb
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|connectionNames
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|root
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|tree
argument_list|)
decl_stmt|;
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|connectionNames
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|root
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|qDBCaption
argument_list|(
name|db
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|connectionNames
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|activeDb
condition|)
block|{
name|gotActiveDb
operator|=
literal|true
expr_stmt|;
name|setActive
argument_list|(
name|root
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|db
operator|.
name|isOpen
argument_list|()
condition|)
block|{
name|QStringList
name|tables
init|=
name|db
operator|.
name|tables
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|t
init|=
literal|0
init|;
name|t
operator|<
name|tables
operator|.
name|count
argument_list|()
condition|;
operator|++
name|t
control|)
block|{
name|QTreeWidgetItem
modifier|*
name|table
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|root
argument_list|)
decl_stmt|;
name|table
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|tables
operator|.
name|at
argument_list|(
name|t
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|gotActiveDb
condition|)
block|{
name|activeDb
operator|=
name|connectionNames
operator|.
name|value
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setActive
argument_list|(
name|tree
operator|->
name|topLevelItem
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|tree
operator|->
name|doItemsLayout
argument_list|()
expr_stmt|;
comment|// HACK
block|}
end_function
begin_function
DECL|function|currentDatabase
name|QSqlDatabase
name|ConnectionWidget
operator|::
name|currentDatabase
parameter_list|()
specifier|const
block|{
return|return
name|QSqlDatabase
operator|::
name|database
argument_list|(
name|activeDb
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qSetBold
specifier|static
name|void
name|qSetBold
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|,
name|bool
name|bold
parameter_list|)
block|{
name|QFont
name|font
init|=
name|item
operator|->
name|font
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|font
operator|.
name|setBold
argument_list|(
name|bold
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFont
argument_list|(
literal|0
argument_list|,
name|font
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setActive
name|void
name|ConnectionWidget
operator|::
name|setActive
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
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
name|tree
operator|->
name|topLevelItemCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|tree
operator|->
name|topLevelItem
argument_list|(
name|i
argument_list|)
operator|->
name|font
argument_list|(
literal|0
argument_list|)
operator|.
name|bold
argument_list|()
condition|)
name|qSetBold
argument_list|(
name|tree
operator|->
name|topLevelItem
argument_list|(
name|i
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|item
condition|)
return|return;
name|qSetBold
argument_list|(
name|item
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|activeDb
operator|=
name|QSqlDatabase
operator|::
name|connectionNames
argument_list|()
operator|.
name|value
argument_list|(
name|tree
operator|->
name|indexOfTopLevelItem
argument_list|(
name|item
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|on_tree_itemActivated
name|void
name|ConnectionWidget
operator|::
name|on_tree_itemActivated
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|,
name|int
comment|/* column */
parameter_list|)
block|{
if|if
condition|(
operator|!
name|item
condition|)
return|return;
if|if
condition|(
operator|!
name|item
operator|->
name|parent
argument_list|()
condition|)
block|{
name|setActive
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setActive
argument_list|(
name|item
operator|->
name|parent
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|tableActivated
argument_list|(
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
argument_list|)
emit|;
block|}
block|}
end_function
begin_function
DECL|function|showMetaData
name|void
name|ConnectionWidget
operator|::
name|showMetaData
parameter_list|()
block|{
name|QTreeWidgetItem
modifier|*
name|cItem
init|=
name|tree
operator|->
name|currentItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|cItem
operator|||
operator|!
name|cItem
operator|->
name|parent
argument_list|()
condition|)
return|return;
name|setActive
argument_list|(
name|cItem
operator|->
name|parent
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|metaDataRequested
argument_list|(
name|cItem
operator|->
name|text
argument_list|(
literal|0
argument_list|)
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|on_tree_currentItemChanged
name|void
name|ConnectionWidget
operator|::
name|on_tree_currentItemChanged
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|current
parameter_list|,
name|QTreeWidgetItem
modifier|*
parameter_list|)
block|{
name|metaDataAction
operator|->
name|setEnabled
argument_list|(
name|current
operator|&&
name|current
operator|->
name|parent
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
