begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTREEVIEW_P_H
end_ifndef
begin_define
DECL|macro|QTREEVIEW_P_H
define|#
directive|define
name|QTREEVIEW_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
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
file|"private/qabstractitemview_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariantanimation.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TREEVIEW
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QTreeViewItem
struct|struct
name|QTreeViewItem
block|{
DECL|function|QTreeViewItem
name|QTreeViewItem
argument_list|()
operator|:
name|parentItem
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|expanded
argument_list|(
name|false
argument_list|)
operator|,
name|spanning
argument_list|(
name|false
argument_list|)
operator|,
name|hasChildren
argument_list|(
name|false
argument_list|)
operator|,
name|hasMoreSiblings
argument_list|(
name|false
argument_list|)
operator|,
name|total
argument_list|(
literal|0
argument_list|)
operator|,
name|level
argument_list|(
literal|0
argument_list|)
operator|,
name|height
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|index
name|QModelIndex
name|index
expr_stmt|;
comment|// we remove items whenever the indexes are invalidated
DECL|member|parentItem
name|int
name|parentItem
decl_stmt|;
comment|// parent item index in viewItems
DECL|member|expanded
name|uint
name|expanded
range|:
literal|1
decl_stmt|;
DECL|member|spanning
name|uint
name|spanning
range|:
literal|1
decl_stmt|;
DECL|member|hasChildren
name|uint
name|hasChildren
range|:
literal|1
decl_stmt|;
comment|// if the item has visible children (even if collapsed)
DECL|member|hasMoreSiblings
name|uint
name|hasMoreSiblings
range|:
literal|1
decl_stmt|;
DECL|member|total
name|uint
name|total
range|:
literal|28
decl_stmt|;
comment|// total number of children visible
DECL|member|level
name|uint
name|level
range|:
literal|16
decl_stmt|;
comment|// indentation
DECL|member|height
name|int
name|height
range|:
literal|16
decl_stmt|;
comment|// row height
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QTreeViewItem
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTreeViewPrivate
range|:
name|public
name|QAbstractItemViewPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTreeView
argument_list|)
name|public
operator|:
name|QTreeViewPrivate
argument_list|()
operator|:
name|QAbstractItemViewPrivate
argument_list|()
block|,
name|header
argument_list|(
literal|0
argument_list|)
block|,
name|indent
argument_list|(
literal|20
argument_list|)
block|,
name|lastViewedItem
argument_list|(
literal|0
argument_list|)
block|,
name|defaultItemHeight
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|uniformRowHeights
argument_list|(
name|false
argument_list|)
block|,
name|rootDecoration
argument_list|(
name|true
argument_list|)
block|,
name|itemsExpandable
argument_list|(
name|true
argument_list|)
block|,
name|sortingEnabled
argument_list|(
name|false
argument_list|)
block|,
name|expandsOnDoubleClick
argument_list|(
name|true
argument_list|)
block|,
name|allColumnsShowFocus
argument_list|(
name|false
argument_list|)
block|,
name|current
argument_list|(
literal|0
argument_list|)
block|,
name|spanning
argument_list|(
name|false
argument_list|)
block|,
name|animationsEnabled
argument_list|(
name|false
argument_list|)
block|,
name|columnResizeTimerID
argument_list|(
literal|0
argument_list|)
block|,
name|autoExpandDelay
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|hoverBranch
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|geometryRecursionBlock
argument_list|(
name|false
argument_list|)
block|,
name|hasRemovedItems
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|QTreeViewPrivate
argument_list|()
block|{}
name|void
name|initialize
argument_list|()
block|;
name|QItemViewPaintPairs
name|draggablePaintPairs
argument_list|(
argument|const QModelIndexList&indexes
argument_list|,
argument|QRect *r
argument_list|)
specifier|const
block|;
name|void
name|adjustViewOptionsForIndex
argument_list|(
argument|QStyleOptionViewItem *option
argument_list|,
argument|const QModelIndex&current
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
block|struct
name|AnimatedOperation
operator|:
name|public
name|QVariantAnimation
block|{
name|int
name|item
block|;
name|QPixmap
name|before
block|;
name|QPixmap
name|after
block|;
name|QWidget
operator|*
name|viewport
block|;
name|AnimatedOperation
argument_list|()
operator|:
name|item
argument_list|(
literal|0
argument_list|)
block|{
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
block|; }
name|int
name|top
argument_list|()
specifier|const
block|{
return|return
name|startValue
argument_list|()
operator|.
name|toInt
argument_list|()
return|;
block|}
name|QRect
name|rect
argument_list|()
specifier|const
block|{
name|QRect
name|rect
operator|=
name|viewport
operator|->
name|rect
argument_list|()
block|;
name|rect
operator|.
name|moveTop
argument_list|(
name|top
argument_list|()
argument_list|)
block|;
return|return
name|rect
return|;
block|}
name|void
name|updateCurrentValue
argument_list|(
argument|const QVariant&
argument_list|)
block|{
name|viewport
operator|->
name|update
argument_list|(
name|rect
argument_list|()
argument_list|)
block|; }
name|void
name|updateState
argument_list|(
argument|State state
argument_list|,
argument|State
argument_list|)
block|{
if|if
condition|(
name|state
operator|==
name|Stopped
condition|)
name|before
operator|=
name|after
operator|=
name|QPixmap
argument_list|()
expr_stmt|;
block|}
expr|}
name|animatedOperation
block|;
name|void
name|prepareAnimatedOperation
argument_list|(
argument|int item
argument_list|,
argument|QVariantAnimation::Direction d
argument_list|)
block|;
name|void
name|beginAnimatedOperation
argument_list|()
block|;
name|void
name|drawAnimatedOperation
argument_list|(
argument|QPainter *painter
argument_list|)
specifier|const
block|;
name|QPixmap
name|renderTreeToPixmapForAnimation
argument_list|(
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|void
name|_q_endAnimatedOperation
argument_list|()
block|;
endif|#
directive|endif
comment|//QT_NO_ANIMATION
name|void
name|expand
argument_list|(
argument|int item
argument_list|,
argument|bool emitSignal
argument_list|)
block|;
name|void
name|collapse
argument_list|(
argument|int item
argument_list|,
argument|bool emitSignal
argument_list|)
block|;
name|void
name|_q_columnsAboutToBeRemoved
argument_list|(
specifier|const
name|QModelIndex
operator|&
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
block|;
name|void
name|_q_columnsRemoved
argument_list|(
specifier|const
name|QModelIndex
operator|&
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
block|;
name|void
name|_q_modelAboutToBeReset
argument_list|()
block|;
name|void
name|_q_sortIndicatorChanged
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order
argument_list|)
block|;
name|void
name|_q_modelDestroyed
argument_list|()
block|;
name|void
name|layout
argument_list|(
argument|int item
argument_list|,
argument|bool recusiveExpanding = false
argument_list|,
argument|bool afterIsUninitialized = false
argument_list|)
block|;
name|int
name|pageUp
argument_list|(
argument|int item
argument_list|)
specifier|const
block|;
name|int
name|pageDown
argument_list|(
argument|int item
argument_list|)
specifier|const
block|;
name|int
name|itemHeight
argument_list|(
argument|int item
argument_list|)
specifier|const
block|;
name|int
name|indentationForItem
argument_list|(
argument|int item
argument_list|)
specifier|const
block|;
name|int
name|coordinateForItem
argument_list|(
argument|int item
argument_list|)
specifier|const
block|;
name|int
name|itemAtCoordinate
argument_list|(
argument|int coordinate
argument_list|)
specifier|const
block|;
name|int
name|viewIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QModelIndex
name|modelIndex
argument_list|(
argument|int i
argument_list|,
argument|int column =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|insertViewItems
argument_list|(
argument|int pos
argument_list|,
argument|int count
argument_list|,
argument|const QTreeViewItem&viewItem
argument_list|)
block|;
name|void
name|removeViewItems
argument_list|(
argument|int pos
argument_list|,
argument|int count
argument_list|)
block|;
if|#
directive|if
literal|0
block|bool checkViewItems() const;
endif|#
directive|endif
name|int
name|firstVisibleItem
argument_list|(
argument|int *offset =
literal|0
argument_list|)
specifier|const
block|;
name|int
name|columnAt
argument_list|(
argument|int x
argument_list|)
specifier|const
block|;
name|bool
name|hasVisibleChildren
argument_list|(
argument|const QModelIndex& parent
argument_list|)
specifier|const
block|;
name|bool
name|expandOrCollapseItemAtPos
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|void
name|updateScrollBars
argument_list|()
block|;
name|int
name|itemDecorationAt
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|QRect
name|itemDecorationRect
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QPair
operator|<
name|int
block|,
name|int
operator|>
expr|>
name|columnRanges
argument_list|(
argument|const QModelIndex&topIndex
argument_list|,
argument|const QModelIndex&bottomIndex
argument_list|)
specifier|const
block|;
name|void
name|select
argument_list|(
argument|const QModelIndex&start
argument_list|,
argument|const QModelIndex&stop
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
name|QPair
operator|<
name|int
block|,
name|int
operator|>
name|startAndEndColumns
argument_list|(
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|void
name|updateChildCount
argument_list|(
argument|const int parentItem
argument_list|,
argument|const int delta
argument_list|)
block|;
name|void
name|paintAlternatingRowColors
argument_list|(
argument|QPainter *painter
argument_list|,
argument|QStyleOptionViewItem *option
argument_list|,
argument|int y
argument_list|,
argument|int bottom
argument_list|)
specifier|const
block|;
comment|// logicalIndices: vector of currently visibly logical indices
comment|// itemPositions: vector of view item positions (beginning/middle/end/onlyone)
name|void
name|calcLogicalIndices
argument_list|(
argument|QVector<int> *logicalIndices
argument_list|,
argument|QVector<QStyleOptionViewItem::ViewItemPosition> *itemPositions
argument_list|,
argument|int left
argument_list|,
argument|int right
argument_list|)
specifier|const
block|;
name|QHeaderView
operator|*
name|header
block|;
name|int
name|indent
block|;
name|mutable
name|QVector
operator|<
name|QTreeViewItem
operator|>
name|viewItems
block|;
name|mutable
name|int
name|lastViewedItem
block|;
name|int
name|defaultItemHeight
block|;
comment|// this is just a number; contentsHeight() / numItems
name|bool
name|uniformRowHeights
block|;
comment|// used when all rows have the same height
name|bool
name|rootDecoration
block|;
name|bool
name|itemsExpandable
block|;
name|bool
name|sortingEnabled
block|;
name|bool
name|expandsOnDoubleClick
block|;
name|bool
name|allColumnsShowFocus
block|;
comment|// used for drawing
name|mutable
name|QPair
operator|<
name|int
block|,
name|int
operator|>
name|leftAndRight
block|;
name|mutable
name|int
name|current
block|;
name|mutable
name|bool
name|spanning
block|;
comment|// used when expanding and collapsing items
name|QSet
operator|<
name|QPersistentModelIndex
operator|>
name|expandedIndexes
block|;
name|bool
name|animationsEnabled
block|;
specifier|inline
name|bool
name|storeExpanded
argument_list|(
argument|const QPersistentModelIndex&idx
argument_list|)
block|{
if|if
condition|(
name|expandedIndexes
operator|.
name|contains
argument_list|(
name|idx
argument_list|)
condition|)
return|return
name|false
return|;
name|expandedIndexes
operator|.
name|insert
argument_list|(
name|idx
argument_list|)
block|;
return|return
name|true
return|;
block|}
specifier|inline
name|bool
name|isIndexExpanded
argument_list|(
argument|const QModelIndex&idx
argument_list|)
specifier|const
block|{
comment|//We first check if the idx is a QPersistentModelIndex, because creating QPersistentModelIndex is slow
return|return
operator|!
operator|(
name|idx
operator|.
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|ItemNeverHasChildren
operator|)
operator|&&
name|isPersistent
argument_list|(
name|idx
argument_list|)
operator|&&
name|expandedIndexes
operator|.
name|contains
argument_list|(
name|idx
argument_list|)
return|;
block|}
comment|// used when hiding and showing items
name|QSet
operator|<
name|QPersistentModelIndex
operator|>
name|hiddenIndexes
block|;
specifier|inline
name|bool
name|isRowHidden
argument_list|(
argument|const QModelIndex&idx
argument_list|)
specifier|const
block|{
comment|//We first check if the idx is a QPersistentModelIndex, because creating QPersistentModelIndex is slow
return|return
name|isPersistent
argument_list|(
name|idx
argument_list|)
operator|&&
name|hiddenIndexes
operator|.
name|contains
argument_list|(
name|idx
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isItemHiddenOrDisabled
argument_list|(
argument|int i
argument_list|)
specifier|const
block|{
if|if
condition|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>=
name|viewItems
operator|.
name|count
argument_list|()
condition|)
return|return
name|false
return|;
specifier|const
name|QModelIndex
name|index
operator|=
name|viewItems
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|index
block|;
return|return
name|isRowHidden
argument_list|(
name|index
argument_list|)
operator|||
operator|!
name|isIndexEnabled
argument_list|(
name|index
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|int
name|above
argument_list|(
name|int
name|item
argument_list|)
decl|const
block|{
name|int
name|i
init|=
name|item
decl_stmt|;
while|while
condition|(
name|isItemHiddenOrDisabled
argument_list|(
operator|--
name|item
argument_list|)
condition|)
block|{}
return|return
name|item
operator|<
literal|0
condition|?
name|i
else|:
name|item
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|int
name|below
argument_list|(
name|int
name|item
argument_list|)
decl|const
block|{
name|int
name|i
init|=
name|item
decl_stmt|;
while|while
condition|(
name|isItemHiddenOrDisabled
argument_list|(
operator|++
name|item
argument_list|)
condition|)
block|{}
return|return
name|item
operator|>=
name|viewItems
operator|.
name|count
argument_list|()
condition|?
name|i
else|:
name|item
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|void
name|invalidateHeightCache
argument_list|(
name|int
name|item
argument_list|)
decl|const
block|{
name|viewItems
index|[
name|item
index|]
operator|.
name|height
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|int
name|accessibleTable2Index
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
name|viewIndex
argument_list|(
name|index
argument_list|)
operator|+
operator|(
name|header
condition|?
literal|1
else|:
literal|0
operator|)
operator|)
operator|*
name|model
operator|->
name|columnCount
argument_list|()
operator|+
name|index
operator|.
name|column
argument_list|()
operator|+
literal|1
return|;
block|}
end_decl_stmt
begin_comment
comment|// used for spanning rows
end_comment
begin_expr_stmt
name|QVector
operator|<
name|QPersistentModelIndex
operator|>
name|spanningIndexes
expr_stmt|;
end_expr_stmt
begin_comment
comment|// used for updating resized columns
end_comment
begin_decl_stmt
name|int
name|columnResizeTimerID
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|int
operator|>
name|columnsToUpdate
expr_stmt|;
end_expr_stmt
begin_comment
comment|// used for the automatic opening of nodes during DND
end_comment
begin_decl_stmt
name|int
name|autoExpandDelay
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicTimer
name|openTimer
decl_stmt|;
end_decl_stmt
begin_comment
comment|// used for drawing hilighted expand/collapse indicators
end_comment
begin_decl_stmt
name|mutable
name|int
name|hoverBranch
decl_stmt|;
end_decl_stmt
begin_comment
comment|// used for blocking recursion when calling setViewportMargins from updateGeometries
end_comment
begin_decl_stmt
name|bool
name|geometryRecursionBlock
decl_stmt|;
end_decl_stmt
begin_comment
comment|// If we should clean the set
end_comment
begin_decl_stmt
name|bool
name|hasRemovedItems
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
comment|// QT_NO_TREEVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTREEVIEW_P_H
end_comment
end_unit
