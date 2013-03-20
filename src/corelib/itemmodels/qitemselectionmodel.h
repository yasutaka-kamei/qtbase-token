begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QITEMSELECTIONMODEL_H
end_ifndef
begin_define
DECL|macro|QITEMSELECTIONMODEL_H
define|#
directive|define
name|QITEMSELECTIONMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
name|class
name|Q_CORE_EXPORT
name|QItemSelectionRange
block|{
name|public
label|:
specifier|inline
name|QItemSelectionRange
argument_list|()
block|{}
specifier|inline
name|QItemSelectionRange
argument_list|(
specifier|const
name|QItemSelectionRange
operator|&
name|other
argument_list|)
operator|:
name|tl
argument_list|(
name|other
operator|.
name|tl
argument_list|)
operator|,
name|br
argument_list|(
argument|other.br
argument_list|)
block|{}
specifier|inline
name|QItemSelectionRange
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|topLeft
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|bottomRight
argument_list|)
expr_stmt|;
name|explicit
specifier|inline
name|QItemSelectionRange
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
name|tl
operator|=
name|index
expr_stmt|;
name|br
operator|=
name|tl
expr_stmt|;
block|}
specifier|inline
name|int
name|top
argument_list|()
specifier|const
block|{
return|return
name|tl
operator|.
name|row
argument_list|()
return|;
block|}
specifier|inline
name|int
name|left
argument_list|()
specifier|const
block|{
return|return
name|tl
operator|.
name|column
argument_list|()
return|;
block|}
specifier|inline
name|int
name|bottom
argument_list|()
specifier|const
block|{
return|return
name|br
operator|.
name|row
argument_list|()
return|;
block|}
specifier|inline
name|int
name|right
argument_list|()
specifier|const
block|{
return|return
name|br
operator|.
name|column
argument_list|()
return|;
block|}
specifier|inline
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|br
operator|.
name|column
argument_list|()
operator|-
name|tl
operator|.
name|column
argument_list|()
operator|+
literal|1
return|;
block|}
specifier|inline
name|int
name|height
argument_list|()
specifier|const
block|{
return|return
name|br
operator|.
name|row
argument_list|()
operator|-
name|tl
operator|.
name|row
argument_list|()
operator|+
literal|1
return|;
block|}
specifier|inline
specifier|const
name|QPersistentModelIndex
operator|&
name|topLeft
argument_list|()
specifier|const
block|{
return|return
name|tl
return|;
block|}
specifier|inline
specifier|const
name|QPersistentModelIndex
operator|&
name|bottomRight
argument_list|()
specifier|const
block|{
return|return
name|br
return|;
block|}
specifier|inline
name|QModelIndex
name|parent
argument_list|()
specifier|const
block|{
return|return
name|tl
operator|.
name|parent
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|QAbstractItemModel
operator|*
name|model
argument_list|()
specifier|const
block|{
return|return
name|tl
operator|.
name|model
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|contains
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
block|{
return|return
operator|(
name|parent
argument_list|()
operator|==
name|index
operator|.
name|parent
argument_list|()
operator|&&
name|tl
operator|.
name|row
argument_list|()
operator|<=
name|index
operator|.
name|row
argument_list|()
operator|&&
name|tl
operator|.
name|column
argument_list|()
operator|<=
name|index
operator|.
name|column
argument_list|()
operator|&&
name|br
operator|.
name|row
argument_list|()
operator|>=
name|index
operator|.
name|row
argument_list|()
operator|&&
name|br
operator|.
name|column
argument_list|()
operator|>=
name|index
operator|.
name|column
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|bool
name|contains
argument_list|(
name|int
name|row
argument_list|,
name|int
name|column
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|parentIndex
argument_list|)
decl|const
block|{
return|return
operator|(
name|parent
argument_list|()
operator|==
name|parentIndex
operator|&&
name|tl
operator|.
name|row
argument_list|()
operator|<=
name|row
operator|&&
name|tl
operator|.
name|column
argument_list|()
operator|<=
name|column
operator|&&
name|br
operator|.
name|row
argument_list|()
operator|>=
name|row
operator|&&
name|br
operator|.
name|column
argument_list|()
operator|>=
name|column
operator|)
return|;
block|}
name|bool
name|intersects
argument_list|(
specifier|const
name|QItemSelectionRange
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
specifier|inline
name|QItemSelectionRange
name|intersect
argument_list|(
specifier|const
name|QItemSelectionRange
operator|&
name|other
argument_list|)
decl|const
block|{
return|return
name|intersected
argument_list|(
name|other
argument_list|)
return|;
block|}
endif|#
directive|endif
name|QItemSelectionRange
name|intersected
argument_list|(
specifier|const
name|QItemSelectionRange
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QItemSelectionRange
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|tl
operator|==
name|other
operator|.
name|tl
operator|&&
name|br
operator|==
name|other
operator|.
name|br
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QItemSelectionRange
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QItemSelectionRange
operator|&
name|other
operator|)
specifier|const
block|{
comment|// Comparing parents will compare the models, but if two equivalent ranges
comment|// in two different models have invalid parents, they would appear the same
if|if
condition|(
name|other
operator|.
name|tl
operator|.
name|model
argument_list|()
operator|==
name|tl
operator|.
name|model
argument_list|()
condition|)
block|{
comment|// parent has to be calculated, so we only do so once.
specifier|const
name|QModelIndex
name|topLeftParent
init|=
name|tl
operator|.
name|parent
argument_list|()
decl_stmt|;
specifier|const
name|QModelIndex
name|otherTopLeftParent
init|=
name|other
operator|.
name|tl
operator|.
name|parent
argument_list|()
decl_stmt|;
if|if
condition|(
name|topLeftParent
operator|==
name|otherTopLeftParent
condition|)
block|{
if|if
condition|(
name|other
operator|.
name|tl
operator|.
name|row
argument_list|()
operator|==
name|tl
operator|.
name|row
argument_list|()
condition|)
block|{
if|if
condition|(
name|other
operator|.
name|tl
operator|.
name|column
argument_list|()
operator|==
name|tl
operator|.
name|column
argument_list|()
condition|)
block|{
if|if
condition|(
name|other
operator|.
name|br
operator|.
name|row
argument_list|()
operator|==
name|br
operator|.
name|row
argument_list|()
condition|)
block|{
return|return
name|br
operator|.
name|column
argument_list|()
operator|<
name|other
operator|.
name|br
operator|.
name|column
argument_list|()
return|;
block|}
return|return
name|br
operator|.
name|row
argument_list|()
operator|<
name|other
operator|.
name|br
operator|.
name|row
argument_list|()
return|;
block|}
return|return
name|tl
operator|.
name|column
argument_list|()
operator|<
name|other
operator|.
name|tl
operator|.
name|column
argument_list|()
return|;
block|}
return|return
name|tl
operator|.
name|row
argument_list|()
operator|<
name|other
operator|.
name|tl
operator|.
name|row
argument_list|()
return|;
block|}
return|return
name|topLeftParent
operator|<
name|otherTopLeftParent
return|;
block|}
return|return
name|tl
operator|.
name|model
argument_list|()
operator|<
name|other
operator|.
name|tl
operator|.
name|model
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|(
name|tl
operator|.
name|isValid
argument_list|()
operator|&&
name|br
operator|.
name|isValid
argument_list|()
operator|&&
name|tl
operator|.
name|parent
argument_list|()
operator|==
name|br
operator|.
name|parent
argument_list|()
operator|&&
name|top
argument_list|()
operator|<=
name|bottom
argument_list|()
operator|&&
name|left
argument_list|()
operator|<=
name|right
argument_list|()
operator|)
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|QModelIndexList
name|indexes
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QPersistentModelIndex
name|tl
decl_stmt|,
name|br
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QItemSelectionRange
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|QItemSelectionRange
specifier|inline
name|QItemSelectionRange
operator|::
name|QItemSelectionRange
argument_list|(
argument|const QModelIndex&atopLeft
argument_list|,
argument|const QModelIndex&abottomRight
argument_list|)
block|{
name|tl
operator|=
name|atopLeft
block|;
name|br
operator|=
name|abottomRight
block|; }
DECL|variable|QItemSelection
name|class
name|QItemSelection
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QItemSelectionModelPrivate
name|class
name|QItemSelectionModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QItemSelectionModel
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QItemSelectionModel
argument_list|)
name|Q_FLAGS
argument_list|(
argument|SelectionFlags
argument_list|)
name|public
operator|:
expr|enum
name|SelectionFlag
block|{
name|NoUpdate
operator|=
literal|0x0000
block|,
name|Clear
operator|=
literal|0x0001
block|,
name|Select
operator|=
literal|0x0002
block|,
name|Deselect
operator|=
literal|0x0004
block|,
name|Toggle
operator|=
literal|0x0008
block|,
name|Current
operator|=
literal|0x0010
block|,
name|Rows
operator|=
literal|0x0020
block|,
name|Columns
operator|=
literal|0x0040
block|,
name|SelectCurrent
operator|=
name|Select
operator||
name|Current
block|,
name|ToggleCurrent
operator|=
name|Toggle
operator||
name|Current
block|,
name|ClearAndSelect
operator|=
name|Clear
operator||
name|Select
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|SelectionFlags
argument_list|,
argument|SelectionFlag
argument_list|)
name|explicit
name|QItemSelectionModel
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|)
block|;
name|explicit
name|QItemSelectionModel
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|virtual
operator|~
name|QItemSelectionModel
argument_list|()
block|;
name|QModelIndex
name|currentIndex
argument_list|()
specifier|const
block|;
name|bool
name|isSelected
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|bool
name|isRowSelected
argument_list|(
argument|int row
argument_list|,
argument|const QModelIndex&parent
argument_list|)
specifier|const
block|;
name|bool
name|isColumnSelected
argument_list|(
argument|int column
argument_list|,
argument|const QModelIndex&parent
argument_list|)
specifier|const
block|;
name|bool
name|rowIntersectsSelection
argument_list|(
argument|int row
argument_list|,
argument|const QModelIndex&parent
argument_list|)
specifier|const
block|;
name|bool
name|columnIntersectsSelection
argument_list|(
argument|int column
argument_list|,
argument|const QModelIndex&parent
argument_list|)
specifier|const
block|;
name|bool
name|hasSelection
argument_list|()
specifier|const
block|;
name|QModelIndexList
name|selectedIndexes
argument_list|()
specifier|const
block|;
name|QModelIndexList
name|selectedRows
argument_list|(
argument|int column =
literal|0
argument_list|)
specifier|const
block|;
name|QModelIndexList
name|selectedColumns
argument_list|(
argument|int row =
literal|0
argument_list|)
specifier|const
block|;
specifier|const
name|QItemSelection
name|selection
argument_list|()
specifier|const
block|;
specifier|const
name|QAbstractItemModel
operator|*
name|model
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|virtual
name|void
name|setCurrentIndex
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
name|virtual
name|void
name|select
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
name|virtual
name|void
name|select
argument_list|(
argument|const QItemSelection&selection
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
name|virtual
name|void
name|clear
argument_list|()
block|;
name|virtual
name|void
name|reset
argument_list|()
block|;
name|void
name|clearSelection
argument_list|()
block|;
name|virtual
name|void
name|clearCurrentIndex
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|selectionChanged
argument_list|(
specifier|const
name|QItemSelection
operator|&
name|selected
argument_list|,
specifier|const
name|QItemSelection
operator|&
name|deselected
argument_list|)
block|;
name|void
name|currentChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|current
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|previous
argument_list|)
block|;
name|void
name|currentRowChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|current
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|previous
argument_list|)
block|;
name|void
name|currentColumnChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|current
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|previous
argument_list|)
block|;
name|protected
operator|:
name|QItemSelectionModel
argument_list|(
name|QItemSelectionModelPrivate
operator|&
name|dd
argument_list|,
name|QAbstractItemModel
operator|*
name|model
argument_list|)
block|;
name|void
name|emitSelectionChanged
argument_list|(
specifier|const
name|QItemSelection
operator|&
name|newSelection
argument_list|,
specifier|const
name|QItemSelection
operator|&
name|oldSelection
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QItemSelectionModel
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_columnsAboutToBeRemoved(const QModelIndex&, int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_rowsAboutToBeRemoved(const QModelIndex&, int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_columnsAboutToBeInserted(const QModelIndex&, int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_rowsAboutToBeInserted(const QModelIndex&, int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_layoutAboutToBeChanged(const QList<QPersistentModelIndex>&parents = QList<QPersistentModelIndex>(), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoHint)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_layoutChanged(const QList<QPersistentModelIndex>&parents = QList<QPersistentModelIndex>(), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoHint)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QItemSelectionModel::SelectionFlags
argument_list|)
end_macro
begin_comment
comment|// dummy implentation of qHash() necessary for instantiating QList<QItemSelectionRange>::toSet() with MSVC
end_comment
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QItemSelectionRange
modifier|&
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QItemSelection
range|:
name|public
name|QList
operator|<
name|QItemSelectionRange
operator|>
block|{
name|public
operator|:
name|QItemSelection
argument_list|()
block|{}
name|QItemSelection
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|topLeft
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|bottomRight
argument_list|)
block|;
name|void
name|select
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|topLeft
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|bottomRight
argument_list|)
block|;
name|bool
name|contains
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QModelIndexList
name|indexes
argument_list|()
specifier|const
block|;
name|void
name|merge
argument_list|(
argument|const QItemSelection&other
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
specifier|static
name|void
name|split
argument_list|(
specifier|const
name|QItemSelectionRange
operator|&
name|range
argument_list|,
specifier|const
name|QItemSelectionRange
operator|&
name|other
argument_list|,
name|QItemSelection
operator|*
name|result
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QItemSelectionRange
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ITEMVIEWS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QITEMSELECTIONMODEL_H
end_comment
end_unit
