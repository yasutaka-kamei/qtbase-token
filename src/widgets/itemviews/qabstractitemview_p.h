begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTITEMVIEW_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTITEMVIEW_P_H
define|#
directive|define
name|QABSTRACTITEMVIEW_P_H
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
file|"private/qabstractscrollarea_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractitemmodel_p.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qapplication.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qevent.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmimedata.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpainter.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpair.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qregion.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdebug.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qelapsedtimer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QEditorInfo
struct|struct
name|QEditorInfo
block|{
DECL|function|QEditorInfo
name|QEditorInfo
argument_list|(
argument|QWidget *e
argument_list|,
argument|bool s
argument_list|)
block|:
name|widget
argument_list|(
name|QPointer
operator|<
name|QWidget
operator|>
operator|(
name|e
operator|)
argument_list|)
operator|,
name|isStatic
argument_list|(
argument|s
argument_list|)
block|{}
DECL|function|QEditorInfo
name|QEditorInfo
argument_list|()
operator|:
name|isStatic
argument_list|(
argument|false
argument_list|)
block|{}
DECL|member|widget
name|QPointer
operator|<
name|QWidget
operator|>
name|widget
expr_stmt|;
DECL|member|isStatic
name|bool
name|isStatic
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|//  Fast associativity between Persistent editors and indices.
end_comment
begin_typedef
DECL|typedef|QWidget
DECL|typedef|QEditorIndexHash
typedef|typedef
name|QHash
operator|<
name|QWidget
operator|*
operator|,
name|QPersistentModelIndex
operator|>
name|QEditorIndexHash
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QPersistentModelIndex
DECL|typedef|QIndexEditorHash
typedef|typedef
name|QHash
operator|<
name|QPersistentModelIndex
operator|,
name|QEditorInfo
operator|>
name|QIndexEditorHash
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QRect
DECL|typedef|QItemViewPaintPair
typedef|typedef
name|QPair
operator|<
name|QRect
operator|,
name|QModelIndex
operator|>
name|QItemViewPaintPair
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QItemViewPaintPairs
typedef|typedef
name|QList
operator|<
name|QItemViewPaintPair
operator|>
name|QItemViewPaintPairs
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QEmptyModel
range|:
name|public
name|QAbstractItemModel
block|{
name|public
operator|:
name|explicit
name|QEmptyModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QAbstractItemModel
argument_list|(
argument|parent
argument_list|)
block|{}
name|QModelIndex
name|index
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
name|QModelIndex
argument_list|()
return|;
block|}
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
name|QModelIndex
argument_list|()
return|;
block|}
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|bool
name|hasChildren
argument_list|(
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&
argument_list|,
argument|int
argument_list|)
specifier|const
block|{
return|return
name|QVariant
argument_list|()
return|;
block|}
expr|}
block|;
name|class
name|Q_AUTOTEST_EXPORT
name|QAbstractItemViewPrivate
operator|:
name|public
name|QAbstractScrollAreaPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractItemView
argument_list|)
name|public
operator|:
name|QAbstractItemViewPrivate
argument_list|()
block|;
name|virtual
operator|~
name|QAbstractItemViewPrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|virtual
name|void
name|_q_rowsRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|virtual
name|void
name|_q_rowsInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|virtual
name|void
name|_q_columnsAboutToBeRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|virtual
name|void
name|_q_columnsRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|virtual
name|void
name|_q_columnsInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|virtual
name|void
name|_q_modelDestroyed
argument_list|()
block|;
name|virtual
name|void
name|_q_layoutChanged
argument_list|()
block|;
name|virtual
name|void
name|_q_rowsMoved
argument_list|(
argument|const QModelIndex&source
argument_list|,
argument|int sourceStart
argument_list|,
argument|int sourceEnd
argument_list|,
argument|const QModelIndex&destination
argument_list|,
argument|int destinationStart
argument_list|)
block|;
name|virtual
name|void
name|_q_columnsMoved
argument_list|(
argument|const QModelIndex&source
argument_list|,
argument|int sourceStart
argument_list|,
argument|int sourceEnd
argument_list|,
argument|const QModelIndex&destination
argument_list|,
argument|int destinationStart
argument_list|)
block|;
name|void
name|_q_headerDataChanged
argument_list|()
block|{
name|doDelayedItemsLayout
argument_list|()
block|; }
name|void
name|_q_scrollerStateChanged
argument_list|()
block|;
name|void
name|fetchMore
argument_list|()
block|;
name|bool
name|shouldEdit
argument_list|(
argument|QAbstractItemView::EditTrigger trigger
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|bool
name|shouldForwardEvent
argument_list|(
argument|QAbstractItemView::EditTrigger trigger
argument_list|,
argument|const QEvent *event
argument_list|)
specifier|const
block|;
name|bool
name|shouldAutoScroll
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|void
name|doDelayedItemsLayout
argument_list|(
argument|int delay =
literal|0
argument_list|)
block|;
name|void
name|interruptDelayedItemsLayout
argument_list|()
specifier|const
block|;
name|void
name|updateGeometry
argument_list|()
block|;
name|void
name|startAutoScroll
argument_list|()
block|{
comment|// ### it would be nice to make this into a style hint one day
name|int
name|scrollInterval
operator|=
operator|(
name|verticalScrollMode
operator|==
name|QAbstractItemView
operator|::
name|ScrollPerItem
operator|)
operator|?
literal|150
operator|:
literal|50
block|;
name|autoScrollTimer
operator|.
name|start
argument_list|(
name|scrollInterval
argument_list|,
name|q_func
argument_list|()
argument_list|)
block|;
name|autoScrollCount
operator|=
literal|0
block|;     }
name|void
name|stopAutoScroll
argument_list|()
block|{
name|autoScrollTimer
operator|.
name|stop
argument_list|()
block|;
name|autoScrollCount
operator|=
literal|0
block|;}
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|virtual
name|bool
name|dropOn
argument_list|(
name|QDropEvent
operator|*
name|event
argument_list|,
name|int
operator|*
name|row
argument_list|,
name|int
operator|*
name|col
argument_list|,
name|QModelIndex
operator|*
name|index
argument_list|)
block|;
endif|#
directive|endif
name|bool
name|droppingOnItself
argument_list|(
name|QDropEvent
operator|*
name|event
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|QWidget
operator|*
name|editor
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|,
specifier|const
name|QStyleOptionViewItem
operator|&
name|options
argument_list|)
block|;
name|bool
name|sendDelegateEvent
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|QEvent *event
argument_list|)
specifier|const
block|;
name|bool
name|openEditor
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|updateEditorData
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
name|QItemSelectionModel
operator|::
name|SelectionFlags
name|multiSelectionCommand
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QEvent *event
argument_list|)
specifier|const
block|;
name|QItemSelectionModel
operator|::
name|SelectionFlags
name|extendedSelectionCommand
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QEvent *event
argument_list|)
specifier|const
block|;
name|QItemSelectionModel
operator|::
name|SelectionFlags
name|contiguousSelectionCommand
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QEvent *event
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|selectAll
argument_list|(
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
name|void
name|setHoverIndex
argument_list|(
specifier|const
name|QPersistentModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|checkMouseMove
argument_list|(
specifier|const
name|QPersistentModelIndex
operator|&
name|index
argument_list|)
block|;
specifier|inline
name|void
name|checkMouseMove
argument_list|(
argument|const QPoint&pos
argument_list|)
block|{
name|checkMouseMove
argument_list|(
name|q_func
argument_list|()
operator|->
name|indexAt
argument_list|(
name|pos
argument_list|)
argument_list|)
block|; }
specifier|inline
name|QItemSelectionModel
operator|::
name|SelectionFlags
name|selectionBehaviorFlags
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|selectionBehavior
condition|)
block|{
case|case
name|QAbstractItemView
operator|::
name|SelectRows
case|:
return|return
name|QItemSelectionModel
operator|::
name|Rows
return|;
case|case
name|QAbstractItemView
operator|::
name|SelectColumns
case|:
return|return
name|QItemSelectionModel
operator|::
name|Columns
return|;
case|case
name|QAbstractItemView
operator|::
name|SelectItems
case|:
default|default:
return|return
name|QItemSelectionModel
operator|::
name|NoUpdate
return|;
block|}
block|}
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|virtual
name|QAbstractItemView
operator|::
name|DropIndicatorPosition
name|position
argument_list|(
argument|const QPoint&pos
argument_list|,
argument|const QRect&rect
argument_list|,
argument|const QModelIndex&idx
argument_list|)
specifier|const
block|;
specifier|inline
name|bool
name|canDrop
argument_list|(
argument|QDropEvent *event
argument_list|)
block|{
name|QModelIndex
name|index
block|;
name|int
name|col
operator|=
operator|-
literal|1
block|;
name|int
name|row
operator|=
operator|-
literal|1
block|;
specifier|const
name|QMimeData
operator|*
name|mime
operator|=
name|event
operator|->
name|mimeData
argument_list|()
block|;
comment|// Drag enter event shall always be accepted, if mime type and action match.
comment|// Whether the data can actually be dropped will be checked in drag move.
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|DragEnter
condition|)
block|{
specifier|const
name|QStringList
name|modelTypes
init|=
name|model
operator|->
name|mimeTypes
argument_list|()
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
name|modelTypes
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|mime
operator|->
name|hasFormat
argument_list|(
name|modelTypes
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
operator|&&
operator|(
name|event
operator|->
name|dropAction
argument_list|()
operator|&
name|model
operator|->
name|supportedDropActions
argument_list|()
operator|)
condition|)
return|return
name|true
return|;
block|}
if|if
condition|(
name|dropOn
argument_list|(
name|event
argument_list|,
operator|&
name|row
argument_list|,
operator|&
name|col
argument_list|,
operator|&
name|index
argument_list|)
condition|)
block|{
return|return
name|model
operator|->
name|canDropMimeData
argument_list|(
name|mime
argument_list|,
name|dragDropMode
operator|==
name|QAbstractItemView
operator|::
name|InternalMove
condition|?
name|Qt
operator|::
name|MoveAction
else|:
name|event
operator|->
name|dropAction
argument_list|()
argument_list|,
name|row
argument_list|,
name|col
argument_list|,
name|index
argument_list|)
return|;
block|}
return|return
name|false
return|;
block|}
specifier|inline
name|void
name|paintDropIndicator
argument_list|(
argument|QPainter *painter
argument_list|)
block|{
if|if
condition|(
name|showDropIndicator
operator|&&
name|state
operator|==
name|QAbstractItemView
operator|::
name|DraggingState
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
operator|&&
name|viewport
operator|->
name|cursor
argument_list|()
operator|.
name|shape
argument_list|()
operator|!=
name|Qt
operator|::
name|ForbiddenCursor
endif|#
directive|endif
condition|)
block|{
name|QStyleOption
name|opt
decl_stmt|;
name|opt
operator|.
name|init
argument_list|(
name|q_func
argument_list|()
argument_list|)
expr_stmt|;
name|opt
operator|.
name|rect
operator|=
name|dropIndicatorRect
expr_stmt|;
name|q_func
argument_list|()
operator|->
name|style
argument_list|()
operator|->
name|drawPrimitive
argument_list|(
name|QStyle
operator|::
name|PE_IndicatorItemViewItemDrop
argument_list|,
operator|&
name|opt
argument_list|,
name|painter
argument_list|,
name|q_func
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
name|virtual
name|QItemViewPaintPairs
name|draggablePaintPairs
argument_list|(
argument|const QModelIndexList&indexes
argument_list|,
argument|QRect *r
argument_list|)
specifier|const
block|;
comment|// reimplemented in subclasses
name|virtual
name|void
name|adjustViewOptionsForIndex
argument_list|(
argument|QStyleOptionViewItem*
argument_list|,
argument|const QModelIndex&
argument_list|)
specifier|const
block|{}
specifier|inline
name|void
name|releaseEditor
argument_list|(
argument|QWidget *editor
argument_list|,
argument|const QModelIndex&index = QModelIndex()
argument_list|)
specifier|const
block|{
if|if
condition|(
name|editor
condition|)
block|{
name|QObject
operator|::
name|disconnect
argument_list|(
name|editor
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|q_func
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|editorDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|editor
operator|->
name|removeEventFilter
argument_list|(
name|itemDelegate
argument_list|)
expr_stmt|;
name|editor
operator|->
name|hide
argument_list|()
expr_stmt|;
name|QAbstractItemDelegate
modifier|*
name|delegate
init|=
name|delegateForIndex
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
name|delegate
condition|)
name|delegate
operator|->
name|destroyEditor
argument_list|(
name|editor
argument_list|,
name|index
argument_list|)
expr_stmt|;
else|else
name|editor
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|executePostedLayout
argument_list|()
specifier|const
block|{
if|if
condition|(
name|delayedPendingLayout
operator|&&
name|state
operator|!=
name|QAbstractItemView
operator|::
name|CollapsingState
condition|)
block|{
name|interruptDelayedItemsLayout
argument_list|()
expr_stmt|;
name|const_cast
operator|<
name|QAbstractItemView
operator|*
operator|>
operator|(
name|q_func
argument_list|()
operator|)
operator|->
name|doItemsLayout
argument_list|()
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|setDirtyRegion
argument_list|(
argument|const QRegion&visualRegion
argument_list|)
block|{
name|updateRegion
operator|+=
name|visualRegion
block|;
if|if
condition|(
operator|!
name|updateTimer
operator|.
name|isActive
argument_list|()
condition|)
name|updateTimer
operator|.
name|start
argument_list|(
literal|0
argument_list|,
name|q_func
argument_list|()
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|scrollDirtyRegion
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|{
name|scrollDelayOffset
operator|=
name|QPoint
argument_list|(
operator|-
name|dx
argument_list|,
operator|-
name|dy
argument_list|)
block|;
name|updateDirtyRegion
argument_list|()
block|;
name|scrollDelayOffset
operator|=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
block|;     }
specifier|inline
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|{
name|scrollDirtyRegion
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
block|;
name|viewport
operator|->
name|scroll
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
block|;     }
name|void
name|updateDirtyRegion
argument_list|()
block|{
name|updateTimer
operator|.
name|stop
argument_list|()
block|;
name|viewport
operator|->
name|update
argument_list|(
name|updateRegion
argument_list|)
block|;
name|updateRegion
operator|=
name|QRegion
argument_list|()
block|;     }
name|void
name|clearOrRemove
argument_list|()
block|;
name|void
name|checkPersistentEditorFocus
argument_list|()
block|;
name|QPixmap
name|renderToPixmap
argument_list|(
argument|const QModelIndexList&indexes
argument_list|,
argument|QRect *r
argument_list|)
specifier|const
block|;
specifier|inline
name|QPoint
name|offset
argument_list|()
specifier|const
block|{
specifier|const
name|Q_Q
argument_list|(
name|QAbstractItemView
argument_list|)
block|;
return|return
name|QPoint
argument_list|(
name|q
operator|->
name|isRightToLeft
argument_list|()
condition|?
operator|-
name|q
operator|->
name|horizontalOffset
argument_list|()
else|:
name|q
operator|->
name|horizontalOffset
argument_list|()
argument_list|,
name|q
operator|->
name|verticalOffset
argument_list|()
argument_list|)
return|;
block|}
specifier|const
name|QEditorInfo
operator|&
name|editorForIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
specifier|inline
name|bool
name|hasEditor
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
return|return
name|indexEditorHash
operator|.
name|find
argument_list|(
name|index
argument_list|)
operator|!=
name|indexEditorHash
operator|.
name|constEnd
argument_list|()
return|;
block|}
name|QModelIndex
name|indexForEditor
argument_list|(
argument|QWidget *editor
argument_list|)
specifier|const
block|;
name|void
name|addEditor
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|QWidget *editor
argument_list|,
argument|bool isStatic
argument_list|)
block|;
name|void
name|removeEditor
argument_list|(
name|QWidget
operator|*
name|editor
argument_list|)
block|;
specifier|inline
name|bool
name|isAnimating
argument_list|()
specifier|const
block|{
return|return
name|state
operator|==
name|QAbstractItemView
operator|::
name|AnimatingState
return|;
block|}
specifier|inline
name|QAbstractItemDelegate
operator|*
name|delegateForIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
name|QMap
operator|<
name|int
block|,
name|QPointer
operator|<
name|QAbstractItemDelegate
operator|>
expr|>
operator|::
name|ConstIterator
name|it
block|;
name|it
operator|=
name|rowDelegates
operator|.
name|find
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|it
operator|!=
name|rowDelegates
operator|.
name|end
argument_list|()
condition|)
return|return
name|it
operator|.
name|value
argument_list|()
return|;
name|it
operator|=
name|columnDelegates
operator|.
name|find
argument_list|(
name|index
operator|.
name|column
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|it
operator|!=
name|columnDelegates
operator|.
name|end
argument_list|()
condition|)
return|return
name|it
operator|.
name|value
argument_list|()
return|;
return|return
name|itemDelegate
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|bool
name|isIndexValid
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
name|index
operator|.
name|row
argument_list|()
operator|>=
literal|0
operator|)
operator|&&
operator|(
name|index
operator|.
name|column
argument_list|()
operator|>=
literal|0
operator|)
operator|&&
operator|(
name|index
operator|.
name|model
argument_list|()
operator|==
name|model
operator|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|bool
name|isIndexSelectable
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
name|model
operator|->
name|flags
argument_list|(
name|index
argument_list|)
operator|&
name|Qt
operator|::
name|ItemIsSelectable
operator|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|bool
name|isIndexEnabled
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
name|model
operator|->
name|flags
argument_list|(
name|index
argument_list|)
operator|&
name|Qt
operator|::
name|ItemIsEnabled
operator|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|bool
name|isIndexDropEnabled
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
name|model
operator|->
name|flags
argument_list|(
name|index
argument_list|)
operator|&
name|Qt
operator|::
name|ItemIsDropEnabled
operator|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|bool
name|isIndexDragEnabled
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
name|model
operator|->
name|flags
argument_list|(
name|index
argument_list|)
operator|&
name|Qt
operator|::
name|ItemIsDragEnabled
operator|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|virtual
name|bool
name|selectionAllowed
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
block|{
comment|// in some views we want to go ahead with selections, even if the index is invalid
return|return
name|isIndexValid
argument_list|(
name|index
argument_list|)
operator|&&
name|isIndexSelectable
argument_list|(
name|index
argument_list|)
return|;
block|}
end_decl_stmt
begin_comment
comment|// reimplemented from QAbstractScrollAreaPrivate
end_comment
begin_expr_stmt
name|virtual
name|QPoint
name|contentsOffset
argument_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QAbstractItemView
argument_list|)
block|;
return|return
name|QPoint
argument_list|(
name|q
operator|->
name|horizontalOffset
argument_list|()
argument_list|,
name|q
operator|->
name|verticalOffset
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|/**      * For now, assume that we have few editors, if we need a more efficient implementation      * we should add a QMap<QAbstractItemDelegate*, int> member.      */
end_comment
begin_decl_stmt
name|int
name|delegateRefCount
argument_list|(
specifier|const
name|QAbstractItemDelegate
operator|*
name|delegate
argument_list|)
decl|const
block|{
name|int
name|ref
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|itemDelegate
operator|==
name|delegate
condition|)
operator|++
name|ref
expr_stmt|;
for|for
control|(
name|int
name|maps
init|=
literal|0
init|;
name|maps
operator|<
literal|2
condition|;
operator|++
name|maps
control|)
block|{
specifier|const
name|QMap
operator|<
name|int
operator|,
name|QPointer
operator|<
name|QAbstractItemDelegate
operator|>
expr|>
operator|*
name|delegates
operator|=
name|maps
condition|?
operator|&
name|columnDelegates
else|:
operator|&
name|rowDelegates
expr_stmt|;
for|for
control|(
name|QMap
operator|<
name|int
operator|,
name|QPointer
operator|<
name|QAbstractItemDelegate
operator|>
expr|>
operator|::
name|const_iterator
name|it
operator|=
name|delegates
operator|->
name|begin
argument_list|()
init|;
name|it
operator|!=
name|delegates
operator|->
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|it
operator|.
name|value
argument_list|()
operator|==
name|delegate
condition|)
block|{
operator|++
name|ref
expr_stmt|;
comment|// optimization, we are only interested in the ref count values 0, 1 or>=2
if|if
condition|(
name|ref
operator|>=
literal|2
condition|)
block|{
return|return
name|ref
return|;
block|}
block|}
block|}
block|}
return|return
name|ref
return|;
block|}
end_decl_stmt
begin_comment
comment|/**      * return true if the index is registered as a QPersistentModelIndex      */
end_comment
begin_decl_stmt
specifier|inline
name|bool
name|isPersistent
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
block|{
return|return
name|static_cast
operator|<
name|QAbstractItemModelPrivate
operator|*
operator|>
operator|(
name|model
operator|->
name|d_ptr
operator|.
name|data
argument_list|()
operator|)
operator|->
name|persistent
operator|.
name|indexes
operator|.
name|contains
argument_list|(
name|index
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|QModelIndexList
name|selectedDraggableIndexes
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QStyleOptionViewItem
name|viewOptionsV1
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function
name|void
name|doDelayedReset
parameter_list|()
block|{
comment|//we delay the reset of the timer because some views (QTableView)
comment|//with headers can't handle the fact that the model has been destroyed
comment|//all _q_modelDestroyed slots must have been called
if|if
condition|(
operator|!
name|delayedReset
operator|.
name|isActive
argument_list|()
condition|)
name|delayedReset
operator|.
name|start
argument_list|(
literal|0
argument_list|,
name|q_func
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|QAbstractItemModel
modifier|*
name|model
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QAbstractItemDelegate
operator|>
name|itemDelegate
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMap
operator|<
name|int
operator|,
name|QPointer
operator|<
name|QAbstractItemDelegate
operator|>
expr|>
name|rowDelegates
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMap
operator|<
name|int
operator|,
name|QPointer
operator|<
name|QAbstractItemDelegate
operator|>
expr|>
name|columnDelegates
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QItemSelectionModel
operator|>
name|selectionModel
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QItemSelectionModel
operator|::
name|SelectionFlag
name|ctrlDragSelectionFlag
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|noSelectionOnMousePress
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QAbstractItemView
operator|::
name|SelectionMode
name|selectionMode
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QAbstractItemView
operator|::
name|SelectionBehavior
name|selectionBehavior
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QEditorIndexHash
name|editorIndexHash
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QIndexEditorHash
name|indexEditorHash
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QSet
operator|<
name|QWidget
operator|*
operator|>
name|persistent
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QWidget
modifier|*
name|currentlyCommittingEditor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPersistentModelIndex
name|enteredIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPersistentModelIndex
name|pressedIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPersistentModelIndex
name|currentSelectionStartIndex
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|KeyboardModifiers
name|pressedModifiers
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QPoint
name|pressedPosition
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|pressedAlreadySelected
decl_stmt|;
end_decl_stmt
begin_comment
comment|//forces the next mouseMoveEvent to send the viewportEntered signal
end_comment
begin_comment
comment|//if the mouse is over the viewport and not over an item
end_comment
begin_decl_stmt
name|bool
name|viewportEnteredNeeded
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QAbstractItemView
operator|::
name|State
name|state
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QAbstractItemView
operator|::
name|State
name|stateBeforeAnimation
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QAbstractItemView
operator|::
name|EditTriggers
name|editTriggers
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QAbstractItemView
operator|::
name|EditTrigger
name|lastTrigger
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QPersistentModelIndex
name|root
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPersistentModelIndex
name|hover
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|tabKeyNavigation
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_decl_stmt
name|bool
name|showDropIndicator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|dropIndicatorRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|dragEnabled
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QAbstractItemView
operator|::
name|DragDropMode
name|dragDropMode
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|overwrite
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QAbstractItemView
operator|::
name|DropIndicatorPosition
name|dropIndicatorPosition
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Qt
operator|::
name|DropAction
name|defaultDropAction
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QString
name|keyboardInput
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QElapsedTimer
name|keyboardInputTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|autoScroll
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicTimer
name|autoScrollTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|autoScrollMargin
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|autoScrollCount
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|shouldScrollToCurrentOnShow
decl_stmt|;
end_decl_stmt
begin_comment
comment|//used to know if we should scroll to current on show event
end_comment
begin_decl_stmt
name|bool
name|shouldClearStatusTip
decl_stmt|;
end_decl_stmt
begin_comment
comment|//if there is a statustip currently shown that need to be cleared when leaving.
end_comment
begin_decl_stmt
name|bool
name|alternatingColors
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSize
name|iconSize
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|TextElideMode
name|textElideMode
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QRegion
name|updateRegion
decl_stmt|;
end_decl_stmt
begin_comment
comment|// used for the internal update system
end_comment
begin_decl_stmt
name|QPoint
name|scrollDelayOffset
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicTimer
name|updateTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicTimer
name|delayedEditing
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicTimer
name|delayedAutoScroll
decl_stmt|;
end_decl_stmt
begin_comment
comment|//used when an item is clicked
end_comment
begin_decl_stmt
name|QBasicTimer
name|delayedReset
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QAbstractItemView
operator|::
name|ScrollMode
name|verticalScrollMode
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QAbstractItemView
operator|::
name|ScrollMode
name|horizontalScrollMode
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_comment
comment|// the selection before the last mouse down. In case we have to restore it for scrolling
end_comment
begin_decl_stmt
name|QItemSelection
name|oldSelection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QModelIndex
name|oldCurrent
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|bool
name|currentIndexSet
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|wrapItemText
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|bool
name|delayedPendingLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|moveCursorUpdatedView
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|mutable
name|QBasicTimer
name|delayedLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|QBasicTimer
name|fetchMoreTimer
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<qvector.h>
name|QT_END_INCLUDE_NAMESPACE
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|int
name|qBinarySearch
argument_list|(
argument|const QVector<T>&vec
argument_list|,
argument|const T&item
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|{
name|int
name|i
operator|=
operator|(
name|start
operator|+
name|end
operator|+
literal|1
operator|)
operator|>>
literal|1
block|;
while|while
condition|(
name|end
operator|-
name|start
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|vec
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|>
name|item
condition|)
name|end
operator|=
name|i
operator|-
literal|1
expr_stmt|;
else|else
name|start
operator|=
name|i
expr_stmt|;
name|i
operator|=
operator|(
name|start
operator|+
name|end
operator|+
literal|1
operator|)
operator|>>
literal|1
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|i
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ITEMVIEWS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTITEMVIEW_P_H
end_comment
end_unit
