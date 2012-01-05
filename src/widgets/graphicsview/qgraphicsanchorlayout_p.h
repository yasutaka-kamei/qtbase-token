begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSANCHORLAYOUT_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSANCHORLAYOUT_P_H
define|#
directive|define
name|QGRAPHICSANCHORLAYOUT_P_H
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
file|<QGraphicsWidget>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|"qgraphicslayout_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicsanchorlayout.h"
end_include
begin_include
include|#
directive|include
file|"qgraph_p.h"
end_include
begin_include
include|#
directive|include
file|"qsimplex_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*   The public QGraphicsAnchorLayout interface represents an anchorage point   as a pair of a<QGraphicsLayoutItem *> and a<Qt::AnchorPoint>.    Internally though, it has a graph of anchorage points (vertices) and   anchors (edges), represented by the AnchorVertex and AnchorData structs   respectively. */
end_comment
begin_comment
comment|/*!   \internal    Represents a vertex (anchorage point) in the internal graph */
end_comment
begin_struct
DECL|struct|AnchorVertex
struct|struct
name|AnchorVertex
block|{
DECL|enum|Type
enum|enum
name|Type
block|{
DECL|enumerator|Normal
name|Normal
init|=
literal|0
block|,
DECL|enumerator|Pair
name|Pair
block|}
enum|;
DECL|function|AnchorVertex
name|AnchorVertex
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|Qt::AnchorPoint edge
argument_list|)
block|:
name|m_item
argument_list|(
name|item
argument_list|)
operator|,
name|m_edge
argument_list|(
name|edge
argument_list|)
operator|,
name|m_type
argument_list|(
argument|Normal
argument_list|)
block|{}
DECL|function|AnchorVertex
name|AnchorVertex
argument_list|()
operator|:
name|m_item
argument_list|(
literal|0
argument_list|)
operator|,
name|m_edge
argument_list|(
name|Qt
operator|::
name|AnchorPoint
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|,
name|m_type
argument_list|(
argument|Normal
argument_list|)
block|{}
ifdef|#
directive|ifdef
name|QT_DEBUG
specifier|inline
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
DECL|member|m_item
name|QGraphicsLayoutItem
modifier|*
name|m_item
decl_stmt|;
DECL|member|m_edge
name|Qt
operator|::
name|AnchorPoint
name|m_edge
expr_stmt|;
DECL|member|m_type
name|uint
name|m_type
range|:
literal|1
decl_stmt|;
comment|// Current distance from this vertex to the layout edge (Left or Top)
comment|// Value is calculated from the current anchors sizes.
DECL|member|distance
name|qreal
name|distance
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|/*!   \internal    Represents an edge (anchor) in the internal graph. */
end_comment
begin_decl_stmt
DECL|struct|QSimplexVariable
name|struct
name|AnchorData
range|:
name|public
name|QSimplexVariable
block|{     enum
DECL|enum|Type
name|Type
block|{
DECL|enumerator|Normal
name|Normal
operator|=
literal|0
block|,
DECL|enumerator|Sequential
name|Sequential
block|,
DECL|enumerator|Parallel
name|Parallel
block|}
block|;      enum
DECL|enum|Dependency
name|Dependency
block|{
DECL|enumerator|Independent
name|Independent
operator|=
literal|0
block|,
DECL|enumerator|Master
name|Master
block|,
DECL|enumerator|Slave
name|Slave
block|}
block|;
DECL|function|AnchorData
name|AnchorData
argument_list|()
operator|:
name|QSimplexVariable
argument_list|()
block|,
name|from
argument_list|(
literal|0
argument_list|)
block|,
name|to
argument_list|(
literal|0
argument_list|)
block|,
name|minSize
argument_list|(
literal|0
argument_list|)
block|,
name|prefSize
argument_list|(
literal|0
argument_list|)
block|,
name|maxSize
argument_list|(
literal|0
argument_list|)
block|,
name|minPrefSize
argument_list|(
literal|0
argument_list|)
block|,
name|maxPrefSize
argument_list|(
literal|0
argument_list|)
block|,
name|sizeAtMinimum
argument_list|(
literal|0
argument_list|)
block|,
name|sizeAtPreferred
argument_list|(
literal|0
argument_list|)
block|,
name|sizeAtMaximum
argument_list|(
literal|0
argument_list|)
block|,
name|item
argument_list|(
literal|0
argument_list|)
block|,
name|graphicsAnchor
argument_list|(
literal|0
argument_list|)
block|,
name|type
argument_list|(
name|Normal
argument_list|)
block|,
name|isLayoutAnchor
argument_list|(
name|false
argument_list|)
block|,
name|isCenterAnchor
argument_list|(
name|false
argument_list|)
block|,
name|orientation
argument_list|(
literal|0
argument_list|)
block|,
name|dependency
argument_list|(
argument|Independent
argument_list|)
block|{}
name|virtual
operator|~
name|AnchorData
argument_list|()
block|;
DECL|function|updateChildrenSizes
name|virtual
name|void
name|updateChildrenSizes
argument_list|()
block|{}
name|void
name|refreshSizeHints
argument_list|(
specifier|const
name|QLayoutStyleInfo
operator|*
name|styleInfo
operator|=
literal|0
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|void
name|dump
argument_list|(
argument|int indent =
literal|2
argument_list|)
block|;
specifier|inline
name|QString
name|toString
argument_list|()
specifier|const
block|;
DECL|member|name
name|QString
name|name
block|;
endif|#
directive|endif
comment|// Anchor is semantically directed
DECL|member|from
name|AnchorVertex
operator|*
name|from
block|;
DECL|member|to
name|AnchorVertex
operator|*
name|to
block|;
comment|// Nominal sizes
comment|// These are the intrinsic size restrictions for a given item. They are
comment|// used as input for the calculation of the actual sizes.
comment|// These values are filled by the refreshSizeHints method, based on the
comment|// anchor size policy, the size hints of the item it (possibly) represents
comment|// and the layout spacing information.
DECL|member|minSize
name|qreal
name|minSize
block|;
DECL|member|prefSize
name|qreal
name|prefSize
block|;
DECL|member|maxSize
name|qreal
name|maxSize
block|;
DECL|member|minPrefSize
name|qreal
name|minPrefSize
block|;
DECL|member|maxPrefSize
name|qreal
name|maxPrefSize
block|;
comment|// Calculated sizes
comment|// These attributes define which sizes should that anchor be in when the
comment|// layout is at its minimum, preferred or maximum sizes. Values are
comment|// calculated by the Simplex solver based on the current layout setup.
DECL|member|sizeAtMinimum
name|qreal
name|sizeAtMinimum
block|;
DECL|member|sizeAtPreferred
name|qreal
name|sizeAtPreferred
block|;
DECL|member|sizeAtMaximum
name|qreal
name|sizeAtMaximum
block|;
comment|// References to the classes that represent this anchor in the public world
comment|// An anchor may represent a LayoutItem, it may also be acessible externally
comment|// through a GraphicsAnchor "handler".
DECL|member|item
name|QGraphicsLayoutItem
operator|*
name|item
block|;
DECL|member|graphicsAnchor
name|QGraphicsAnchor
operator|*
name|graphicsAnchor
block|;
DECL|member|type
name|uint
name|type
operator|:
literal|2
block|;
comment|// either Normal, Sequential or Parallel
DECL|member|isLayoutAnchor
name|uint
name|isLayoutAnchor
operator|:
literal|1
block|;
comment|// if this anchor is an internal layout anchor
DECL|member|isCenterAnchor
name|uint
name|isCenterAnchor
operator|:
literal|1
block|;
DECL|member|orientation
name|uint
name|orientation
operator|:
literal|1
block|;
DECL|member|dependency
name|uint
name|dependency
operator|:
literal|2
block|;
comment|// either Independent, Master or Slave
block|}
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_DEBUG
end_ifdef
begin_expr_stmt
DECL|function|toString
specifier|inline
name|QString
name|AnchorData
operator|::
name|toString
argument_list|()
specifier|const
block|{
return|return
name|QString
operator|::
name|fromAscii
argument_list|(
literal|"Anchor(%1)"
argument_list|)
operator|.
name|arg
argument_list|(
name|name
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|struct|AnchorData
name|struct
name|SequentialAnchorData
range|:
name|public
name|AnchorData
block|{
name|SequentialAnchorData
argument_list|(
specifier|const
name|QVector
operator|<
name|AnchorVertex
operator|*
operator|>
operator|&
name|vertices
argument_list|,
specifier|const
name|QVector
operator|<
name|AnchorData
operator|*
operator|>
operator|&
name|edges
argument_list|)
DECL|function|m_edges
operator|:
name|AnchorData
argument_list|()
block|,
name|m_children
argument_list|(
name|vertices
argument_list|)
block|,
name|m_edges
argument_list|(
argument|edges
argument_list|)
block|{
name|type
operator|=
name|AnchorData
operator|::
name|Sequential
block|;
name|orientation
operator|=
name|m_edges
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|orientation
block|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|name
operator|=
name|QString
operator|::
name|fromAscii
argument_list|(
literal|"%1 -- %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|vertices
operator|.
name|first
argument_list|()
operator|->
name|toString
argument_list|()
argument_list|,
name|vertices
operator|.
name|last
argument_list|()
operator|->
name|toString
argument_list|()
argument_list|)
block|;
endif|#
directive|endif
block|}
name|virtual
name|void
name|updateChildrenSizes
argument_list|()
block|;
name|void
name|calculateSizeHints
argument_list|()
block|;
DECL|member|m_children
name|QVector
operator|<
name|AnchorVertex
operator|*
operator|>
name|m_children
block|;
comment|// list of vertices in the sequence
DECL|member|m_edges
name|QVector
operator|<
name|AnchorData
operator|*
operator|>
name|m_edges
block|;
comment|// keep the list of edges too.
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|struct|AnchorData
name|struct
name|ParallelAnchorData
range|:
name|public
name|AnchorData
block|{
DECL|function|ParallelAnchorData
name|ParallelAnchorData
argument_list|(
name|AnchorData
operator|*
name|first
argument_list|,
name|AnchorData
operator|*
name|second
argument_list|)
operator|:
name|AnchorData
argument_list|()
block|,
name|firstEdge
argument_list|(
name|first
argument_list|)
block|,
name|secondEdge
argument_list|(
argument|second
argument_list|)
block|{
name|type
operator|=
name|AnchorData
operator|::
name|Parallel
block|;
name|orientation
operator|=
name|first
operator|->
name|orientation
block|;
comment|// This assert whether the child anchors share their vertices
name|Q_ASSERT
argument_list|(
operator|(
operator|(
name|first
operator|->
name|from
operator|==
name|second
operator|->
name|from
operator|)
operator|&&
operator|(
name|first
operator|->
name|to
operator|==
name|second
operator|->
name|to
operator|)
operator|)
operator|||
operator|(
operator|(
name|first
operator|->
name|from
operator|==
name|second
operator|->
name|to
operator|)
operator|&&
operator|(
name|first
operator|->
name|to
operator|==
name|second
operator|->
name|from
operator|)
operator|)
argument_list|)
block|;
comment|// Our convention will be that the parallel group anchor will have the same
comment|// direction as the first anchor.
name|from
operator|=
name|first
operator|->
name|from
block|;
name|to
operator|=
name|first
operator|->
name|to
block|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|name
operator|=
name|QString
operator|::
name|fromAscii
argument_list|(
literal|"%1 | %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|first
operator|->
name|toString
argument_list|()
argument_list|,
name|second
operator|->
name|toString
argument_list|()
argument_list|)
block|;
endif|#
directive|endif
block|}
name|virtual
name|void
name|updateChildrenSizes
argument_list|()
block|;
name|bool
name|calculateSizeHints
argument_list|()
block|;
DECL|function|secondForward
name|bool
name|secondForward
argument_list|()
specifier|const
block|{
comment|// We have the convention that the first children will define the direction of the
comment|// pararell group. Note that we can't rely on 'this->from' or 'this->to'  because they
comment|// might be changed by vertex simplification.
return|return
name|firstEdge
operator|->
name|from
operator|==
name|secondEdge
operator|->
name|from
return|;
block|}
DECL|member|firstEdge
name|AnchorData
operator|*
name|firstEdge
block|;
DECL|member|secondEdge
name|AnchorData
operator|*
name|secondEdge
block|;
DECL|member|m_firstConstraints
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
name|m_firstConstraints
block|;
DECL|member|m_secondConstraints
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
name|m_secondConstraints
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|struct|AnchorVertex
name|struct
name|AnchorVertexPair
range|:
name|public
name|AnchorVertex
block|{
DECL|function|AnchorVertexPair
name|AnchorVertexPair
argument_list|(
name|AnchorVertex
operator|*
name|v1
argument_list|,
name|AnchorVertex
operator|*
name|v2
argument_list|,
name|AnchorData
operator|*
name|data
argument_list|)
operator|:
name|AnchorVertex
argument_list|()
block|,
name|m_first
argument_list|(
name|v1
argument_list|)
block|,
name|m_second
argument_list|(
name|v2
argument_list|)
block|,
name|m_removedAnchor
argument_list|(
argument|data
argument_list|)
block|{
name|m_type
operator|=
name|AnchorVertex
operator|::
name|Pair
block|;     }
DECL|member|m_first
name|AnchorVertex
operator|*
name|m_first
block|;
DECL|member|m_second
name|AnchorVertex
operator|*
name|m_second
block|;
DECL|member|m_removedAnchor
name|AnchorData
operator|*
name|m_removedAnchor
block|;
DECL|member|m_firstAnchors
name|QList
operator|<
name|AnchorData
operator|*
operator|>
name|m_firstAnchors
block|;
DECL|member|m_secondAnchors
name|QList
operator|<
name|AnchorData
operator|*
operator|>
name|m_secondAnchors
block|; }
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_DEBUG
end_ifdef
begin_expr_stmt
DECL|function|toString
specifier|inline
name|QString
name|AnchorVertex
operator|::
name|toString
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|this
condition|)
block|{
return|return
name|QLatin1String
argument_list|(
literal|"NULL"
argument_list|)
return|;
block|}
end_expr_stmt
begin_elseif
elseif|else
if|if
condition|(
name|m_type
operator|==
name|Pair
condition|)
block|{
specifier|const
name|AnchorVertexPair
modifier|*
name|vp
init|=
name|static_cast
operator|<
specifier|const
name|AnchorVertexPair
operator|*
operator|>
operator|(
name|this
operator|)
decl_stmt|;
return|return
name|QString
operator|::
name|fromAscii
argument_list|(
literal|"(%1, %2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|vp
operator|->
name|m_first
operator|->
name|toString
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|vp
operator|->
name|m_second
operator|->
name|toString
argument_list|()
argument_list|)
return|;
block|}
end_elseif
begin_elseif
elseif|else
if|if
condition|(
operator|!
name|m_item
condition|)
block|{
return|return
name|QString
operator|::
name|fromAscii
argument_list|(
literal|"NULL_%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|quintptr
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
block|}
end_elseif
begin_decl_stmt
name|QString
name|edge
decl_stmt|;
end_decl_stmt
begin_switch
switch|switch
condition|(
name|m_edge
condition|)
block|{
case|case
name|Qt
operator|::
name|AnchorLeft
case|:
name|edge
operator|=
name|QLatin1String
argument_list|(
literal|"Left"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|AnchorHorizontalCenter
case|:
name|edge
operator|=
name|QLatin1String
argument_list|(
literal|"HorizontalCenter"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|AnchorRight
case|:
name|edge
operator|=
name|QLatin1String
argument_list|(
literal|"Right"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|AnchorTop
case|:
name|edge
operator|=
name|QLatin1String
argument_list|(
literal|"Top"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|AnchorVerticalCenter
case|:
name|edge
operator|=
name|QLatin1String
argument_list|(
literal|"VerticalCenter"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|AnchorBottom
case|:
name|edge
operator|=
name|QLatin1String
argument_list|(
literal|"Bottom"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|edge
operator|=
name|QLatin1String
argument_list|(
literal|"None"
argument_list|)
expr_stmt|;
break|break;
block|}
end_switch
begin_decl_stmt
name|QString
name|itemName
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|m_item
operator|->
name|isLayout
argument_list|()
condition|)
block|{
name|itemName
operator|=
name|QLatin1String
argument_list|(
literal|"layout"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|QGraphicsItem
modifier|*
name|item
init|=
name|m_item
operator|->
name|graphicsItem
argument_list|()
condition|)
block|{
name|itemName
operator|=
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
block|}
end_if
begin_expr_stmt
name|edge
operator|.
name|insert
argument_list|(
literal|0
argument_list|,
name|QLatin1String
argument_list|(
literal|"%1_"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|edge
operator|.
name|arg
argument_list|(
name|itemName
argument_list|)
return|;
end_return
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|/*!   \internal    Representation of a valid path for a given vertex in the graph.   In this struct, "positives" is the set of anchors that have been   traversed in the forward direction, while "negatives" is the set   with the ones walked backwards.    This paths are compared against each other to produce LP Constraints,   the exact order in which the anchors were traversed is not relevant. */
end_comment
begin_macro
unit|class
name|GraphPath
end_macro
begin_block
block|{
name|public
label|:
name|GraphPath
argument_list|()
block|{}
name|QSimplexConstraint
modifier|*
name|constraint
argument_list|(
specifier|const
name|GraphPath
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|QSet
operator|<
name|AnchorData
operator|*
operator|>
name|positives
expr_stmt|;
name|QSet
operator|<
name|AnchorData
operator|*
operator|>
name|negatives
expr_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QGraphicsAnchorLayoutPrivate
name|class
name|QGraphicsAnchorLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \internal */
end_comment
begin_decl_stmt
name|class
name|QGraphicsAnchorPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsAnchor
argument_list|)
name|public
operator|:
name|explicit
name|QGraphicsAnchorPrivate
argument_list|(
argument|int version = QObjectPrivateVersion
argument_list|)
block|;
operator|~
name|QGraphicsAnchorPrivate
argument_list|()
block|;
name|void
name|setSpacing
argument_list|(
argument|qreal value
argument_list|)
block|;
name|void
name|unsetSpacing
argument_list|()
block|;
name|qreal
name|spacing
argument_list|()
specifier|const
block|;
name|void
name|setSizePolicy
argument_list|(
argument|QSizePolicy::Policy policy
argument_list|)
block|;
name|QGraphicsAnchorLayoutPrivate
operator|*
name|layoutPrivate
block|;
name|AnchorData
operator|*
name|data
block|;
comment|// Size information for user controlled anchor
name|QSizePolicy
operator|::
name|Policy
name|sizePolicy
block|;
name|qreal
name|preferredSize
block|;
name|uint
name|hasSize
operator|:
literal|1
block|;
comment|// if false, get size from style.
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!   \internal    QGraphicsAnchorLayout private methods and attributes. */
end_comment
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QGraphicsAnchorLayoutPrivate
range|:
name|public
name|QGraphicsLayoutPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsAnchorLayout
argument_list|)
name|public
operator|:
comment|// When the layout geometry is different from its Minimum, Preferred
comment|// or Maximum values, interpolation is used to calculate the geometries
comment|// of the items.
comment|//
comment|// Interval represents which interpolation interval are we operating in.
expr|enum
name|Interval
block|{
name|MinimumToMinPreferred
operator|=
literal|0
block|,
name|MinPreferredToPreferred
block|,
name|PreferredToMaxPreferred
block|,
name|MaxPreferredToMaximum
block|}
block|;
comment|// Several structures internal to the layout are duplicated to handle
comment|// both Horizontal and Vertical restrictions.
comment|//
comment|// Orientation is used to reference the right structure in each context
block|enum
name|Orientation
block|{
name|Horizontal
operator|=
literal|0
block|,
name|Vertical
block|,
name|NOrientations
block|}
block|;
name|QGraphicsAnchorLayoutPrivate
argument_list|()
block|;
specifier|static
name|QGraphicsAnchorLayoutPrivate
operator|*
name|get
argument_list|(
argument|QGraphicsAnchorLayout *q
argument_list|)
block|{
return|return
name|q
operator|?
name|q
operator|->
name|d_func
argument_list|()
operator|:
literal|0
return|;
block|}
specifier|static
name|Qt
operator|::
name|AnchorPoint
name|oppositeEdge
argument_list|(
argument|Qt::AnchorPoint edge
argument_list|)
block|;
specifier|static
name|Orientation
name|edgeOrientation
argument_list|(
argument|Qt::AnchorPoint edge
argument_list|)
block|;
specifier|static
name|Qt
operator|::
name|AnchorPoint
name|pickEdge
argument_list|(
argument|Qt::AnchorPoint edge
argument_list|,
argument|Orientation orientation
argument_list|)
block|{
if|if
condition|(
name|orientation
operator|==
name|Vertical
operator|&&
name|int
argument_list|(
name|edge
argument_list|)
operator|<=
literal|2
condition|)
return|return
operator|(
name|Qt
operator|::
name|AnchorPoint
operator|)
operator|(
name|edge
operator|+
literal|3
operator|)
return|;
elseif|else
if|if
condition|(
name|orientation
operator|==
name|Horizontal
operator|&&
name|int
argument_list|(
name|edge
argument_list|)
operator|>=
literal|3
condition|)
block|{
return|return
operator|(
name|Qt
operator|::
name|AnchorPoint
operator|)
operator|(
name|edge
operator|-
literal|3
operator|)
return|;
block|}
return|return
name|edge
return|;
block|}
comment|// Init methods
name|void
name|createLayoutEdges
argument_list|()
block|;
name|void
name|deleteLayoutEdges
argument_list|()
block|;
name|void
name|createItemEdges
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|item
argument_list|)
block|;
name|void
name|createCenterAnchors
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|Qt::AnchorPoint centerEdge
argument_list|)
block|;
name|void
name|removeCenterAnchors
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|Qt::AnchorPoint centerEdge
argument_list|,
argument|bool substitute = true
argument_list|)
block|;
name|void
name|removeCenterConstraints
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|Orientation orientation
argument_list|)
block|;
name|QGraphicsAnchor
operator|*
name|acquireGraphicsAnchor
argument_list|(
argument|AnchorData *data
argument_list|)
block|{
name|Q_Q
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
block|;
if|if
condition|(
operator|!
name|data
operator|->
name|graphicsAnchor
condition|)
block|{
name|data
operator|->
name|graphicsAnchor
operator|=
name|new
name|QGraphicsAnchor
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|data
operator|->
name|graphicsAnchor
operator|->
name|d_func
argument_list|()
operator|->
name|data
operator|=
name|data
expr_stmt|;
block|}
return|return
name|data
operator|->
name|graphicsAnchor
return|;
block|}
comment|// function used by the 4 API functions
name|QGraphicsAnchor
operator|*
name|addAnchor
argument_list|(
argument|QGraphicsLayoutItem *firstItem
argument_list|,
argument|Qt::AnchorPoint firstEdge
argument_list|,
argument|QGraphicsLayoutItem *secondItem
argument_list|,
argument|Qt::AnchorPoint secondEdge
argument_list|,
argument|qreal *spacing =
literal|0
argument_list|)
block|;
comment|// Helper for Anchor Manipulation methods
name|void
name|addAnchor_helper
argument_list|(
argument|QGraphicsLayoutItem *firstItem
argument_list|,
argument|Qt::AnchorPoint firstEdge
argument_list|,
argument|QGraphicsLayoutItem *secondItem
argument_list|,
argument|Qt::AnchorPoint secondEdge
argument_list|,
argument|AnchorData *data
argument_list|)
block|;
name|QGraphicsAnchor
operator|*
name|getAnchor
argument_list|(
argument|QGraphicsLayoutItem *firstItem
argument_list|,
argument|Qt::AnchorPoint firstEdge
argument_list|,
argument|QGraphicsLayoutItem *secondItem
argument_list|,
argument|Qt::AnchorPoint secondEdge
argument_list|)
block|;
name|void
name|removeAnchor
argument_list|(
name|AnchorVertex
operator|*
name|firstVertex
argument_list|,
name|AnchorVertex
operator|*
name|secondVertex
argument_list|)
block|;
name|void
name|removeAnchor_helper
argument_list|(
name|AnchorVertex
operator|*
name|v1
argument_list|,
name|AnchorVertex
operator|*
name|v2
argument_list|)
block|;
name|void
name|removeAnchors
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|item
argument_list|)
block|;
name|void
name|removeVertex
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|Qt::AnchorPoint edge
argument_list|)
block|;
name|void
name|correctEdgeDirection
argument_list|(
name|QGraphicsLayoutItem
operator|*
operator|&
name|firstItem
argument_list|,
name|Qt
operator|::
name|AnchorPoint
operator|&
name|firstEdge
argument_list|,
name|QGraphicsLayoutItem
operator|*
operator|&
name|secondItem
argument_list|,
name|Qt
operator|::
name|AnchorPoint
operator|&
name|secondEdge
argument_list|)
block|;
name|QLayoutStyleInfo
operator|&
name|styleInfo
argument_list|()
specifier|const
block|;
name|AnchorData
operator|*
name|addAnchorMaybeParallel
argument_list|(
name|AnchorData
operator|*
name|newAnchor
argument_list|,
name|bool
operator|*
name|feasible
argument_list|)
block|;
comment|// Activation
name|void
name|calculateGraphs
argument_list|()
block|;
name|void
name|calculateGraphs
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
comment|// Simplification
name|bool
name|simplifyGraph
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|bool
name|simplifyVertices
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|bool
name|simplifyGraphIteration
argument_list|(
argument|Orientation orientation
argument_list|,
argument|bool *feasible
argument_list|)
block|;
name|bool
name|replaceVertex
argument_list|(
argument|Orientation orientation
argument_list|,
argument|AnchorVertex *oldV
argument_list|,
argument|AnchorVertex *newV
argument_list|,
argument|const QList<AnchorData *>&edges
argument_list|)
block|;
name|void
name|restoreSimplifiedGraph
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|void
name|restoreSimplifiedAnchor
argument_list|(
name|AnchorData
operator|*
name|edge
argument_list|)
block|;
name|void
name|restoreSimplifiedConstraints
argument_list|(
name|ParallelAnchorData
operator|*
name|parallel
argument_list|)
block|;
name|void
name|restoreVertices
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|bool
name|calculateTrunk
argument_list|(
argument|Orientation orientation
argument_list|,
argument|const GraphPath&trunkPath
argument_list|,
argument|const QList<QSimplexConstraint *>&constraints
argument_list|,
argument|const QList<AnchorData *>&variables
argument_list|)
block|;
name|bool
name|calculateNonTrunk
argument_list|(
specifier|const
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
operator|&
name|constraints
argument_list|,
specifier|const
name|QList
operator|<
name|AnchorData
operator|*
operator|>
operator|&
name|variables
argument_list|)
block|;
comment|// Support functions for calculateGraph()
name|void
name|refreshAllSizeHints
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|void
name|findPaths
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|void
name|constraintsFromPaths
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|void
name|updateAnchorSizes
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
name|constraintsFromSizeHints
argument_list|(
specifier|const
name|QList
operator|<
name|AnchorData
operator|*
operator|>
operator|&
name|anchors
argument_list|)
block|;
name|QList
operator|<
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
expr|>
name|getGraphParts
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|void
name|identifyFloatItems
argument_list|(
argument|const QSet<AnchorData *>&visited
argument_list|,
argument|Orientation orientation
argument_list|)
block|;
name|void
name|identifyNonFloatItems_helper
argument_list|(
specifier|const
name|AnchorData
operator|*
name|ad
argument_list|,
name|QSet
operator|<
name|QGraphicsLayoutItem
operator|*
operator|>
operator|*
name|nonFloatingItemsIdentifiedSoFar
argument_list|)
block|;
specifier|inline
name|AnchorVertex
operator|*
name|internalVertex
argument_list|(
argument|const QPair<QGraphicsLayoutItem*
argument_list|,
argument|Qt::AnchorPoint>&itemEdge
argument_list|)
specifier|const
block|{
return|return
name|m_vertexList
operator|.
name|value
argument_list|(
name|itemEdge
argument_list|)
operator|.
name|first
return|;
block|}
specifier|inline
name|AnchorVertex
operator|*
name|internalVertex
argument_list|(
argument|const QGraphicsLayoutItem *item
argument_list|,
argument|Qt::AnchorPoint edge
argument_list|)
specifier|const
block|{
return|return
name|internalVertex
argument_list|(
name|qMakePair
argument_list|(
name|const_cast
operator|<
name|QGraphicsLayoutItem
operator|*
operator|>
operator|(
name|item
operator|)
argument_list|,
name|edge
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|void
name|changeLayoutVertex
argument_list|(
argument|Orientation orientation
argument_list|,
argument|AnchorVertex *oldV
argument_list|,
argument|AnchorVertex *newV
argument_list|)
block|{
if|if
condition|(
name|layoutFirstVertex
index|[
name|orientation
index|]
operator|==
name|oldV
condition|)
name|layoutFirstVertex
index|[
name|orientation
index|]
operator|=
name|newV
expr_stmt|;
elseif|else
if|if
condition|(
name|layoutCentralVertex
index|[
name|orientation
index|]
operator|==
name|oldV
condition|)
name|layoutCentralVertex
index|[
name|orientation
index|]
operator|=
name|newV
expr_stmt|;
elseif|else
if|if
condition|(
name|layoutLastVertex
index|[
name|orientation
index|]
operator|==
name|oldV
condition|)
name|layoutLastVertex
index|[
name|orientation
index|]
operator|=
name|newV
expr_stmt|;
block|}
name|AnchorVertex
operator|*
name|addInternalVertex
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|Qt::AnchorPoint edge
argument_list|)
block|;
name|void
name|removeInternalVertex
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|,
argument|Qt::AnchorPoint edge
argument_list|)
block|;
comment|// Geometry interpolation methods
name|void
name|setItemsGeometries
argument_list|(
specifier|const
name|QRectF
operator|&
name|geom
argument_list|)
block|;
name|void
name|calculateVertexPositions
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|void
name|setupEdgesInterpolation
argument_list|(
argument|Orientation orientation
argument_list|)
block|;
name|void
name|interpolateEdge
argument_list|(
name|AnchorVertex
operator|*
name|base
argument_list|,
name|AnchorData
operator|*
name|edge
argument_list|)
block|;
comment|// Linear Programming solver methods
name|bool
name|solveMinMax
argument_list|(
argument|const QList<QSimplexConstraint *>&constraints
argument_list|,
argument|GraphPath path
argument_list|,
argument|qreal *min
argument_list|,
argument|qreal *max
argument_list|)
block|;
name|bool
name|solvePreferred
argument_list|(
specifier|const
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
operator|&
name|constraints
argument_list|,
specifier|const
name|QList
operator|<
name|AnchorData
operator|*
operator|>
operator|&
name|variables
argument_list|)
block|;
name|bool
name|hasConflicts
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT_DEBUG
name|void
name|dumpGraph
argument_list|(
specifier|const
name|QString
operator|&
name|name
operator|=
name|QString
argument_list|()
argument_list|)
block|;
endif|#
directive|endif
name|qreal
name|spacings
index|[
name|NOrientations
index|]
block|;
comment|// Size hints from simplex engine
name|qreal
name|sizeHints
index|[
literal|2
index|]
index|[
literal|3
index|]
block|;
comment|// Items
name|QVector
operator|<
name|QGraphicsLayoutItem
operator|*
operator|>
name|items
block|;
comment|// Mapping between high level anchorage points (Item, Edge) to low level
comment|// ones (Graph Vertices)
name|QHash
operator|<
name|QPair
operator|<
name|QGraphicsLayoutItem
operator|*
block|,
name|Qt
operator|::
name|AnchorPoint
operator|>
block|,
name|QPair
operator|<
name|AnchorVertex
operator|*
block|,
name|int
operator|>
expr|>
name|m_vertexList
block|;
comment|// Internal graph of anchorage points and anchors, for both orientations
name|Graph
operator|<
name|AnchorVertex
block|,
name|AnchorData
operator|>
name|graph
index|[
literal|2
index|]
block|;
name|AnchorVertex
operator|*
name|layoutFirstVertex
index|[
literal|2
index|]
block|;
name|AnchorVertex
operator|*
name|layoutCentralVertex
index|[
literal|2
index|]
block|;
name|AnchorVertex
operator|*
name|layoutLastVertex
index|[
literal|2
index|]
block|;
comment|// Combined anchors in order of creation
name|QList
operator|<
name|AnchorVertexPair
operator|*
operator|>
name|simplifiedVertices
index|[
literal|2
index|]
block|;
name|QList
operator|<
name|AnchorData
operator|*
operator|>
name|anchorsFromSimplifiedVertices
index|[
literal|2
index|]
block|;
comment|// Graph paths and constraints, for both orientations
name|QMultiHash
operator|<
name|AnchorVertex
operator|*
block|,
name|GraphPath
operator|>
name|graphPaths
index|[
literal|2
index|]
block|;
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
name|constraints
index|[
literal|2
index|]
block|;
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
name|itemCenterConstraints
index|[
literal|2
index|]
block|;
comment|// The interpolation interval and progress based on the current size
comment|// as well as the key values (minimum, preferred and maximum)
name|Interval
name|interpolationInterval
index|[
literal|2
index|]
block|;
name|qreal
name|interpolationProgress
index|[
literal|2
index|]
block|;
name|bool
name|graphHasConflicts
index|[
literal|2
index|]
block|;
name|QSet
operator|<
name|QGraphicsLayoutItem
operator|*
operator|>
name|m_floatItems
index|[
literal|2
index|]
block|;
if|#
directive|if
name|defined
argument_list|(
name|QT_DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_AUTOTEST_EXPORT
argument_list|)
name|bool
name|lastCalculationUsedSimplex
index|[
literal|2
index|]
block|;
endif|#
directive|endif
name|uint
name|calculateGraphCacheDirty
operator|:
literal|1
block|;
name|mutable
name|uint
name|styleInfoDirty
operator|:
literal|1
block|;
name|mutable
name|QLayoutStyleInfo
name|cachedStyleInfo
block|;
name|friend
name|class
name|QGraphicsAnchorPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_GRAPHICSVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
