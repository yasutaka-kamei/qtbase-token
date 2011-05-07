begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHEADERVIEW_P_H
end_ifndef
begin_define
DECL|macro|QHEADERVIEW_P_H
define|#
directive|define
name|QHEADERVIEW_P_H
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
end_ifndef
begin_include
include|#
directive|include
file|"QtCore/qbitarray.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qapplication.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qlabel.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QHeaderViewPrivate
range|:
name|public
name|QAbstractItemViewPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QHeaderView
argument_list|)
name|public
operator|:
expr|enum
name|StateVersion
block|{
name|VersionMarker
operator|=
literal|0xff
block|}
block|;
name|QHeaderViewPrivate
argument_list|()
operator|:
name|state
argument_list|(
name|NoState
argument_list|)
block|,
name|offset
argument_list|(
literal|0
argument_list|)
block|,
name|sortIndicatorOrder
argument_list|(
name|Qt
operator|::
name|DescendingOrder
argument_list|)
block|,
name|sortIndicatorSection
argument_list|(
literal|0
argument_list|)
block|,
name|sortIndicatorShown
argument_list|(
name|false
argument_list|)
block|,
name|lastPos
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|firstPos
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|originalSize
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|section
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|target
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|pressed
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|hover
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|length
argument_list|(
literal|0
argument_list|)
block|,
name|sectionCount
argument_list|(
literal|0
argument_list|)
block|,
name|movableSections
argument_list|(
name|false
argument_list|)
block|,
name|clickableSections
argument_list|(
name|false
argument_list|)
block|,
name|highlightSelected
argument_list|(
name|false
argument_list|)
block|,
name|stretchLastSection
argument_list|(
name|false
argument_list|)
block|,
name|cascadingResizing
argument_list|(
name|false
argument_list|)
block|,
name|resizeRecursionBlock
argument_list|(
name|false
argument_list|)
block|,
name|stretchSections
argument_list|(
literal|0
argument_list|)
block|,
name|contentsSections
argument_list|(
literal|0
argument_list|)
block|,
name|minimumSectionSize
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|lastSectionSize
argument_list|(
literal|0
argument_list|)
block|,
name|sectionIndicatorOffset
argument_list|(
literal|0
argument_list|)
block|,
name|sectionIndicator
argument_list|(
literal|0
argument_list|)
block|,
name|globalResizeMode
argument_list|(
argument|QHeaderView::Interactive
argument_list|)
block|{}
name|int
name|lastVisibleVisualIndex
argument_list|()
specifier|const
block|;
name|int
name|sectionHandleAt
argument_list|(
argument|int position
argument_list|)
block|;
name|void
name|setupSectionIndicator
argument_list|(
argument|int section
argument_list|,
argument|int position
argument_list|)
block|;
name|void
name|updateSectionIndicator
argument_list|(
argument|int section
argument_list|,
argument|int position
argument_list|)
block|;
name|void
name|updateHiddenSections
argument_list|(
argument|int logicalFirst
argument_list|,
argument|int logicalLast
argument_list|)
block|;
name|void
name|resizeSections
argument_list|(
argument|QHeaderView::ResizeMode globalMode
argument_list|,
argument|bool useGlobalMode = false
argument_list|)
block|;
name|void
name|_q_sectionsRemoved
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
name|_q_layoutAboutToBeChanged
argument_list|()
block|;
name|void
name|_q_layoutChanged
argument_list|()
block|;
name|bool
name|isSectionSelected
argument_list|(
argument|int section
argument_list|)
specifier|const
block|;
specifier|inline
name|bool
name|rowIntersectsSelection
argument_list|(
argument|int row
argument_list|)
specifier|const
block|{
return|return
operator|(
name|selectionModel
operator|?
name|selectionModel
operator|->
name|rowIntersectsSelection
argument_list|(
name|row
argument_list|,
name|root
argument_list|)
operator|:
name|false
operator|)
return|;
block|}
specifier|inline
name|bool
name|columnIntersectsSelection
argument_list|(
argument|int column
argument_list|)
specifier|const
block|{
return|return
operator|(
name|selectionModel
condition|?
name|selectionModel
operator|->
name|columnIntersectsSelection
argument_list|(
name|column
argument_list|,
name|root
argument_list|)
else|:
name|false
operator|)
return|;
block|}
specifier|inline
name|bool
name|sectionIntersectsSelection
argument_list|(
argument|int logical
argument_list|)
specifier|const
block|{
return|return
operator|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
name|columnIntersectsSelection
argument_list|(
name|logical
argument_list|)
else|:
name|rowIntersectsSelection
argument_list|(
name|logical
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|bool
name|isRowSelected
argument_list|(
argument|int row
argument_list|)
specifier|const
block|{
return|return
operator|(
name|selectionModel
condition|?
name|selectionModel
operator|->
name|isRowSelected
argument_list|(
name|row
argument_list|,
name|root
argument_list|)
else|:
name|false
operator|)
return|;
block|}
specifier|inline
name|bool
name|isColumnSelected
argument_list|(
argument|int column
argument_list|)
specifier|const
block|{
return|return
operator|(
name|selectionModel
condition|?
name|selectionModel
operator|->
name|isColumnSelected
argument_list|(
name|column
argument_list|,
name|root
argument_list|)
else|:
name|false
operator|)
return|;
block|}
specifier|inline
name|void
name|prepareSectionSelected
argument_list|()
block|{
if|if
condition|(
operator|!
name|selectionModel
operator|||
operator|!
name|selectionModel
operator|->
name|hasSelection
argument_list|()
condition|)
name|sectionSelected
operator|.
name|clear
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|sectionSelected
operator|.
name|count
argument_list|()
operator|!=
name|sectionCount
operator|*
literal|2
condition|)
name|sectionSelected
operator|.
name|fill
argument_list|(
name|false
argument_list|,
name|sectionCount
operator|*
literal|2
argument_list|)
expr_stmt|;
else|else
name|sectionSelected
operator|.
name|fill
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|bool
name|reverse
argument_list|()
specifier|const
block|{
return|return
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
operator|&&
name|q_func
argument_list|()
operator|->
name|isRightToLeft
argument_list|()
return|;
block|}
specifier|inline
name|int
name|logicalIndex
argument_list|(
argument|int visualIndex
argument_list|)
specifier|const
block|{
return|return
name|logicalIndices
operator|.
name|isEmpty
argument_list|()
operator|?
name|visualIndex
operator|:
name|logicalIndices
operator|.
name|at
argument_list|(
name|visualIndex
argument_list|)
return|;
block|}
specifier|inline
name|int
name|visualIndex
argument_list|(
argument|int logicalIndex
argument_list|)
specifier|const
block|{
return|return
name|visualIndices
operator|.
name|isEmpty
argument_list|()
condition|?
name|logicalIndex
else|:
name|visualIndices
operator|.
name|at
argument_list|(
name|logicalIndex
argument_list|)
return|;
block|}
specifier|inline
name|void
name|setDefaultValues
argument_list|(
argument|Qt::Orientation o
argument_list|)
block|{
name|orientation
operator|=
name|o
block|;
name|defaultSectionSize
operator|=
operator|(
name|o
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
literal|100
else|:
name|qMax
argument_list|(
name|q_func
argument_list|()
operator|->
name|minimumSectionSize
argument_list|()
argument_list|,
literal|30
argument_list|)
operator|)
block|;
name|defaultAlignment
operator|=
operator|(
name|o
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
name|Qt
operator|::
name|Alignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
else|:
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignVCenter
operator|)
block|;     }
specifier|inline
name|bool
name|isVisualIndexHidden
argument_list|(
argument|int visual
argument_list|)
specifier|const
block|{
return|return
operator|!
name|sectionHidden
operator|.
name|isEmpty
argument_list|()
operator|&&
name|sectionHidden
operator|.
name|at
argument_list|(
name|visual
argument_list|)
return|;
block|}
specifier|inline
name|void
name|setVisualIndexHidden
argument_list|(
argument|int visual
argument_list|,
argument|bool hidden
argument_list|)
block|{
if|if
condition|(
operator|!
name|sectionHidden
operator|.
name|isEmpty
argument_list|()
condition|)
name|sectionHidden
operator|.
name|setBit
argument_list|(
name|visual
argument_list|,
name|hidden
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|bool
name|hasAutoResizeSections
argument_list|()
specifier|const
block|{
return|return
name|stretchSections
operator|||
name|stretchLastSection
operator|||
name|contentsSections
return|;
block|}
name|QStyleOptionHeader
name|getStyleOption
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|invalidateCachedSizeHint
argument_list|()
specifier|const
block|{
name|cachedSizeHint
operator|=
name|QSize
argument_list|()
block|;     }
specifier|inline
name|void
name|initializeIndexMapping
argument_list|()
specifier|const
block|{
if|if
condition|(
name|visualIndices
operator|.
name|count
argument_list|()
operator|!=
name|sectionCount
operator|||
name|logicalIndices
operator|.
name|count
argument_list|()
operator|!=
name|sectionCount
condition|)
block|{
name|visualIndices
operator|.
name|resize
argument_list|(
name|sectionCount
argument_list|)
expr_stmt|;
name|logicalIndices
operator|.
name|resize
argument_list|(
name|sectionCount
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|s
init|=
literal|0
init|;
name|s
operator|<
name|sectionCount
condition|;
operator|++
name|s
control|)
block|{
name|visualIndices
index|[
name|s
index|]
operator|=
name|s
expr_stmt|;
name|logicalIndices
index|[
name|s
index|]
operator|=
name|s
expr_stmt|;
block|}
block|}
block|}
specifier|inline
name|void
name|clearCascadingSections
argument_list|()
block|{
name|firstCascadingSection
operator|=
name|sectionCount
block|;
name|lastCascadingSection
operator|=
literal|0
block|;
name|cascadingSectionSize
operator|.
name|clear
argument_list|()
block|;     }
specifier|inline
name|void
name|saveCascadingSectionSize
argument_list|(
argument|int visual
argument_list|,
argument|int size
argument_list|)
block|{
if|if
condition|(
operator|!
name|cascadingSectionSize
operator|.
name|contains
argument_list|(
name|visual
argument_list|)
condition|)
block|{
name|cascadingSectionSize
operator|.
name|insert
argument_list|(
name|visual
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|firstCascadingSection
operator|=
name|qMin
argument_list|(
name|firstCascadingSection
argument_list|,
name|visual
argument_list|)
expr_stmt|;
name|lastCascadingSection
operator|=
name|qMax
argument_list|(
name|lastCascadingSection
argument_list|,
name|visual
argument_list|)
expr_stmt|;
block|}
block|}
specifier|inline
name|bool
name|sectionIsCascadable
argument_list|(
argument|int visual
argument_list|)
specifier|const
block|{
return|return
name|headerSectionResizeMode
argument_list|(
name|visual
argument_list|)
operator|==
name|QHeaderView
operator|::
name|Interactive
return|;
block|}
specifier|inline
name|int
name|modelSectionCount
argument_list|()
specifier|const
block|{
return|return
operator|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
operator|?
name|model
operator|->
name|columnCount
argument_list|(
name|root
argument_list|)
operator|:
name|model
operator|->
name|rowCount
argument_list|(
name|root
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|bool
name|modelIsEmpty
argument_list|()
specifier|const
block|{
return|return
operator|(
name|model
operator|->
name|rowCount
argument_list|(
name|root
argument_list|)
operator|==
literal|0
operator|||
name|model
operator|->
name|columnCount
argument_list|(
name|root
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
specifier|inline
name|void
name|doDelayedResizeSections
argument_list|()
block|{
if|if
condition|(
operator|!
name|delayedResize
operator|.
name|isActive
argument_list|()
condition|)
name|delayedResize
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
name|executePostedResize
argument_list|()
specifier|const
block|{
if|if
condition|(
name|delayedResize
operator|.
name|isActive
argument_list|()
operator|&&
name|state
operator|==
name|NoState
condition|)
block|{
name|const_cast
operator|<
name|QHeaderView
operator|*
operator|>
operator|(
name|q_func
argument_list|()
operator|)
operator|->
name|resizeSections
argument_list|()
expr_stmt|;
block|}
block|}
name|void
name|clear
argument_list|()
block|;
name|void
name|flipSortIndicator
argument_list|(
argument|int section
argument_list|)
block|;
name|void
name|cascadingResize
argument_list|(
argument|int visual
argument_list|,
argument|int newSize
argument_list|)
block|;      enum
name|State
block|{
name|NoState
block|,
name|ResizeSection
block|,
name|MoveSection
block|,
name|SelectSections
block|,
name|NoClear
block|}
name|state
block|;
name|int
name|offset
block|;
name|Qt
operator|::
name|Orientation
name|orientation
block|;
name|Qt
operator|::
name|SortOrder
name|sortIndicatorOrder
block|;
name|int
name|sortIndicatorSection
block|;
name|bool
name|sortIndicatorShown
block|;
name|mutable
name|QVector
operator|<
name|int
operator|>
name|visualIndices
block|;
comment|// visualIndex = visualIndices.at(logicalIndex)
name|mutable
name|QVector
operator|<
name|int
operator|>
name|logicalIndices
block|;
comment|// logicalIndex = row or column in the model
name|mutable
name|QBitArray
name|sectionSelected
block|;
comment|// from logical index to bit
name|mutable
name|QBitArray
name|sectionHidden
block|;
comment|// from visual index to bit
name|mutable
name|QHash
operator|<
name|int
block|,
name|int
operator|>
name|hiddenSectionSize
block|;
comment|// from logical index to section size
name|mutable
name|QHash
operator|<
name|int
block|,
name|int
operator|>
name|cascadingSectionSize
block|;
comment|// from visual index to section size
name|mutable
name|QSize
name|cachedSizeHint
block|;
name|mutable
name|QBasicTimer
name|delayedResize
block|;
name|int
name|firstCascadingSection
block|;
name|int
name|lastCascadingSection
block|;
name|int
name|lastPos
block|;
name|int
name|firstPos
block|;
name|int
name|originalSize
block|;
name|int
name|section
block|;
comment|// used for resizing and moving sections
name|int
name|target
block|;
name|int
name|pressed
block|;
name|int
name|hover
block|;
name|int
name|length
block|;
name|int
name|sectionCount
block|;
name|bool
name|movableSections
block|;
name|bool
name|clickableSections
block|;
name|bool
name|highlightSelected
block|;
name|bool
name|stretchLastSection
block|;
name|bool
name|cascadingResizing
block|;
name|bool
name|resizeRecursionBlock
block|;
name|int
name|stretchSections
block|;
name|int
name|contentsSections
block|;
name|int
name|defaultSectionSize
block|;
name|int
name|minimumSectionSize
block|;
name|int
name|lastSectionSize
block|;
comment|// $$$
name|int
name|sectionIndicatorOffset
block|;
name|Qt
operator|::
name|Alignment
name|defaultAlignment
block|;
name|QLabel
operator|*
name|sectionIndicator
block|;
name|QHeaderView
operator|::
name|ResizeMode
name|globalResizeMode
block|;
name|QList
operator|<
name|QPersistentModelIndex
operator|>
name|persistentHiddenSections
block|;
comment|// header section spans
block|struct
name|SectionSpan
block|{
name|int
name|size
block|;
name|int
name|count
block|;
name|QHeaderView
operator|::
name|ResizeMode
name|resizeMode
block|;
specifier|inline
name|SectionSpan
argument_list|()
operator|:
name|size
argument_list|(
literal|0
argument_list|)
block|,
name|count
argument_list|(
literal|0
argument_list|)
block|,
name|resizeMode
argument_list|(
argument|QHeaderView::Interactive
argument_list|)
block|{}
specifier|inline
name|SectionSpan
argument_list|(
argument|int length
argument_list|,
argument|int sections
argument_list|,
argument|QHeaderView::ResizeMode mode
argument_list|)
operator|:
name|size
argument_list|(
name|length
argument_list|)
block|,
name|count
argument_list|(
name|sections
argument_list|)
block|,
name|resizeMode
argument_list|(
argument|mode
argument_list|)
block|{}
specifier|inline
name|int
name|sectionSize
argument_list|()
specifier|const
block|{
return|return
operator|(
name|count
operator|>
literal|0
operator|?
name|size
operator|/
name|count
operator|:
literal|0
operator|)
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
specifier|inline
name|void
name|write
argument_list|(
argument|QDataStream&out
argument_list|)
specifier|const
block|{
name|out
operator|<<
name|size
block|;
name|out
operator|<<
name|count
block|;
name|out
operator|<<
operator|(
name|int
operator|)
name|resizeMode
block|; }
specifier|inline
name|void
name|read
argument_list|(
argument|QDataStream&in
argument_list|)
block|{
name|in
operator|>>
name|size
block|;
name|in
operator|>>
name|count
block|;
name|int
name|m
block|;
name|in
operator|>>
name|m
block|;
name|resizeMode
operator|=
operator|(
name|QHeaderView
operator|::
name|ResizeMode
operator|)
name|m
block|; }
endif|#
directive|endif
expr|}
block|;
name|QVector
operator|<
name|SectionSpan
operator|>
name|sectionSpans
block|;
name|void
name|createSectionSpan
argument_list|(
argument|int start
argument_list|,
argument|int end
argument_list|,
argument|int size
argument_list|,
argument|QHeaderView::ResizeMode mode
argument_list|)
block|;
name|void
name|removeSectionsFromSpans
argument_list|(
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|resizeSectionSpan
argument_list|(
argument|int visualIndex
argument_list|,
argument|int oldSize
argument_list|,
argument|int newSize
argument_list|)
block|;
name|void
name|setDefaultSectionSize
argument_list|(
argument|int size
argument_list|)
block|;
specifier|inline
name|int
name|headerSectionCount
argument_list|()
specifier|const
block|{
comment|// for debugging
name|int
name|count
operator|=
literal|0
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|sectionSpans
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|count
operator|+=
name|sectionSpans
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|count
expr_stmt|;
return|return
name|count
return|;
block|}
specifier|inline
name|int
name|headerLength
argument_list|()
specifier|const
block|{
comment|// for debugging
name|int
name|len
operator|=
literal|0
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|sectionSpans
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|len
operator|+=
name|sectionSpans
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|size
expr_stmt|;
return|return
name|len
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|void
name|removeSpans
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|spans
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
name|spans
operator|.
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
name|length
operator|-=
name|sectionSpans
operator|.
name|at
argument_list|(
name|spans
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
operator|.
name|size
expr_stmt|;
name|sectionSpans
operator|.
name|remove
argument_list|(
name|spans
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|int
name|sectionSpanIndex
argument_list|(
name|int
name|visual
argument_list|)
decl|const
block|{
name|int
name|section_start
init|=
literal|0
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
name|sectionSpans
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|section_end
init|=
name|section_start
operator|+
name|sectionSpans
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|count
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|visual
operator|>=
name|section_start
operator|&&
name|visual
operator|<=
name|section_end
condition|)
return|return
name|i
return|;
name|section_start
operator|=
name|section_end
operator|+
literal|1
expr_stmt|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|int
name|headerSectionSize
argument_list|(
name|int
name|visual
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|headerSectionPosition
argument_list|(
name|int
name|visual
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|headerVisualIndexAt
argument_list|(
name|int
name|position
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_comment
comment|// resize mode
end_comment
begin_decl_stmt
name|void
name|setHeaderSectionResizeMode
argument_list|(
name|int
name|visual
argument_list|,
name|QHeaderView
operator|::
name|ResizeMode
name|mode
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QHeaderView
operator|::
name|ResizeMode
name|headerSectionResizeMode
argument_list|(
argument|int visual
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|setGlobalHeaderResizeMode
argument_list|(
name|QHeaderView
operator|::
name|ResizeMode
name|mode
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// other
end_comment
begin_decl_stmt
name|int
name|viewSectionSizeHint
argument_list|(
name|int
name|logical
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|adjustedVisualIndex
argument_list|(
name|int
name|visualIndex
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_decl_stmt
name|void
name|write
argument_list|(
name|QDataStream
operator|&
name|out
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|read
parameter_list|(
name|QDataStream
modifier|&
name|in
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
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
comment|// QHEADERVIEW_P_H
end_comment
end_unit
