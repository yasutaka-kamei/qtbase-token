begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTANDARDITEMMODEL_P_H
end_ifndef
begin_define
DECL|macro|QSTANDARDITEMMODEL_P_H
define|#
directive|define
name|QSTANDARDITEMMODEL_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"private/qabstractitemmodel_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STANDARDITEMMODEL
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstack.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QStandardItemData
block|{
name|public
label|:
specifier|inline
name|QStandardItemData
argument_list|()
operator|:
name|role
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
specifier|inline
name|QStandardItemData
argument_list|(
argument|int r
argument_list|,
argument|QVariant v
argument_list|)
operator|:
name|role
argument_list|(
name|r
argument_list|)
operator|,
name|value
argument_list|(
argument|v
argument_list|)
block|{}
name|int
name|role
expr_stmt|;
name|QVariant
name|value
decl_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QStandardItemData
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|role
operator|==
name|other
operator|.
name|role
operator|&&
name|value
operator|==
name|other
operator|.
name|value
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QStandardItemData
operator|&
name|data
operator|)
block|{
name|in
operator|>>
name|data
operator|.
name|role
block|;
name|in
operator|>>
name|data
operator|.
name|value
block|;
return|return
name|in
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|out
operator|,
specifier|const
name|QStandardItemData
operator|&
name|data
operator|)
block|{
name|out
operator|<<
name|data
operator|.
name|role
block|;
name|out
operator|<<
name|data
operator|.
name|value
block|;
return|return
name|out
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_decl_stmt
name|class
name|QStandardItemPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QStandardItem
argument_list|)
name|public
label|:
specifier|inline
name|QStandardItemPrivate
argument_list|()
operator|:
name|model
argument_list|(
literal|0
argument_list|)
operator|,
name|parent
argument_list|(
literal|0
argument_list|)
operator|,
name|rows
argument_list|(
literal|0
argument_list|)
operator|,
name|columns
argument_list|(
literal|0
argument_list|)
operator|,
name|q_ptr
argument_list|(
literal|0
argument_list|)
operator|,
name|lastIndexOf
argument_list|(
literal|2
argument_list|)
block|{ }
name|virtual
operator|~
name|QStandardItemPrivate
argument_list|()
expr_stmt|;
specifier|inline
name|int
name|childIndex
argument_list|(
name|int
name|row
argument_list|,
name|int
name|column
argument_list|)
decl|const
block|{
if|if
condition|(
operator|(
name|row
operator|<
literal|0
operator|)
operator|||
operator|(
name|column
operator|<
literal|0
operator|)
operator|||
operator|(
name|row
operator|>=
name|rowCount
argument_list|()
operator|)
operator|||
operator|(
name|column
operator|>=
name|columnCount
argument_list|()
operator|)
condition|)
block|{
return|return
operator|-
literal|1
return|;
block|}
return|return
operator|(
name|row
operator|*
name|columnCount
argument_list|()
operator|)
operator|+
name|column
return|;
block|}
specifier|inline
name|int
name|childIndex
parameter_list|(
specifier|const
name|QStandardItem
modifier|*
name|child
parameter_list|)
block|{
name|int
name|start
init|=
name|qMax
argument_list|(
literal|0
argument_list|,
name|lastIndexOf
operator|-
literal|2
argument_list|)
decl_stmt|;
name|lastIndexOf
operator|=
name|children
operator|.
name|indexOf
argument_list|(
name|const_cast
operator|<
name|QStandardItem
operator|*
operator|>
operator|(
name|child
operator|)
argument_list|,
name|start
argument_list|)
expr_stmt|;
if|if
condition|(
name|lastIndexOf
operator|==
operator|-
literal|1
operator|&&
name|start
operator|!=
literal|0
condition|)
name|lastIndexOf
operator|=
name|children
operator|.
name|lastIndexOf
argument_list|(
name|const_cast
operator|<
name|QStandardItem
operator|*
operator|>
operator|(
name|child
operator|)
argument_list|,
name|start
argument_list|)
expr_stmt|;
return|return
name|lastIndexOf
return|;
block|}
name|QPair
operator|<
name|int
operator|,
name|int
operator|>
name|position
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setChild
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
name|QStandardItem
modifier|*
name|item
parameter_list|,
name|bool
name|emitChanged
init|=
name|false
parameter_list|)
function_decl|;
specifier|inline
name|int
name|rowCount
argument_list|()
specifier|const
block|{
return|return
name|rows
return|;
block|}
specifier|inline
name|int
name|columnCount
argument_list|()
specifier|const
block|{
return|return
name|columns
return|;
block|}
name|void
name|childDeleted
parameter_list|(
name|QStandardItem
modifier|*
name|child
parameter_list|)
function_decl|;
name|void
name|setModel
parameter_list|(
name|QStandardItemModel
modifier|*
name|mod
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setParentAndModel
parameter_list|(
name|QStandardItem
modifier|*
name|par
parameter_list|,
name|QStandardItemModel
modifier|*
name|mod
parameter_list|)
block|{
name|setModel
argument_list|(
name|mod
argument_list|)
expr_stmt|;
name|parent
operator|=
name|par
expr_stmt|;
block|}
name|void
name|changeFlags
argument_list|(
name|bool
name|enable
argument_list|,
name|Qt
operator|::
name|ItemFlags
name|f
argument_list|)
decl_stmt|;
name|void
name|setItemData
argument_list|(
specifier|const
name|QMap
operator|<
name|int
argument_list|,
name|QVariant
operator|>
operator|&
name|roles
argument_list|)
decl_stmt|;
specifier|const
name|QMap
operator|<
name|int
operator|,
name|QVariant
operator|>
name|itemData
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|insertRows
argument_list|(
name|int
name|row
argument_list|,
name|int
name|count
argument_list|,
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
decl_stmt|;
name|bool
name|insertRows
argument_list|(
name|int
name|row
argument_list|,
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
decl_stmt|;
name|bool
name|insertColumns
argument_list|(
name|int
name|column
argument_list|,
name|int
name|count
argument_list|,
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
decl_stmt|;
name|void
name|sortChildren
argument_list|(
name|int
name|column
argument_list|,
name|Qt
operator|::
name|SortOrder
name|order
argument_list|)
decl_stmt|;
name|QStandardItemModel
modifier|*
name|model
decl_stmt|;
name|QStandardItem
modifier|*
name|parent
decl_stmt|;
name|QVector
operator|<
name|QStandardItemData
operator|>
name|values
expr_stmt|;
name|QVector
operator|<
name|QStandardItem
operator|*
operator|>
name|children
expr_stmt|;
name|int
name|rows
decl_stmt|;
name|int
name|columns
decl_stmt|;
name|QStandardItem
modifier|*
name|q_ptr
decl_stmt|;
name|int
name|lastIndexOf
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QStandardItemModelPrivate
range|:
name|public
name|QAbstractItemModelPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QStandardItemModel
argument_list|)
name|public
operator|:
name|QStandardItemModelPrivate
argument_list|()
block|;
name|virtual
operator|~
name|QStandardItemModelPrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
specifier|inline
name|QStandardItem
operator|*
name|createItem
argument_list|()
specifier|const
block|{
return|return
name|itemPrototype
operator|?
name|itemPrototype
operator|->
name|clone
argument_list|()
operator|:
name|new
name|QStandardItem
return|;
block|}
specifier|inline
name|QStandardItem
operator|*
name|itemFromIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QStandardItemModel
argument_list|)
block|;
if|if
condition|(
operator|!
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|root
operator|.
name|data
argument_list|()
return|;
if|if
condition|(
name|index
operator|.
name|model
argument_list|()
operator|!=
name|q
condition|)
return|return
literal|0
return|;
name|QStandardItem
operator|*
name|parent
operator|=
name|static_cast
operator|<
name|QStandardItem
operator|*
operator|>
operator|(
name|index
operator|.
name|internalPointer
argument_list|()
operator|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|parent
operator|==
literal|0
condition|)
return|return
literal|0
return|;
end_if
begin_return
return|return
name|parent
operator|->
name|child
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|,
name|index
operator|.
name|column
argument_list|()
argument_list|)
return|;
end_return
begin_macro
unit|}      void
name|sort
argument_list|(
argument|QStandardItem *parent
argument_list|,
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function_decl
name|void
name|itemChanged
parameter_list|(
name|QStandardItem
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|rowsAboutToBeInserted
parameter_list|(
name|QStandardItem
modifier|*
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|columnsAboutToBeInserted
parameter_list|(
name|QStandardItem
modifier|*
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|rowsAboutToBeRemoved
parameter_list|(
name|QStandardItem
modifier|*
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|columnsAboutToBeRemoved
parameter_list|(
name|QStandardItem
modifier|*
name|parent
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|rowsInserted
parameter_list|(
name|QStandardItem
modifier|*
name|parent
parameter_list|,
name|int
name|row
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|columnsInserted
parameter_list|(
name|QStandardItem
modifier|*
name|parent
parameter_list|,
name|int
name|column
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|rowsRemoved
parameter_list|(
name|QStandardItem
modifier|*
name|parent
parameter_list|,
name|int
name|row
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|columnsRemoved
parameter_list|(
name|QStandardItem
modifier|*
name|parent
parameter_list|,
name|int
name|column
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_emitItemChanged
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|topLeft
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|bottomRight
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|decodeDataRecursive
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|QStandardItem
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QVector
operator|<
name|QStandardItem
operator|*
operator|>
name|columnHeaderItems
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QVector
operator|<
name|QStandardItem
operator|*
operator|>
name|rowHeaderItems
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QScopedPointer
operator|<
name|QStandardItem
operator|>
name|root
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|const
name|QStandardItem
modifier|*
name|itemPrototype
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|sortRole
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STANDARDITEMMODEL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTANDARDITEMMODEL_P_H
end_comment
end_unit
