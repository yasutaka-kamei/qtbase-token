begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTERPATH_H
end_ifndef
begin_define
DECL|macro|QPAINTERPATH_H
define|#
directive|define
name|QPAINTERPATH_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qmatrix.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qline.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QFont
decl_stmt|;
DECL|variable|QPainterPathPrivate
name|class
name|QPainterPathPrivate
decl_stmt|;
function|struct QPainterPathPrivateDeleter;
end_function
begin_decl_stmt
DECL|variable|QPainterPathData
name|class
name|QPainterPathData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainterPathStrokerPrivate
name|class
name|QPainterPathStrokerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPolygonF
name|class
name|QPolygonF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVectorPath
name|class
name|QVectorPath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPainterPath
block|{
name|public
label|:
enum|enum
name|ElementType
block|{
name|MoveToElement
block|,
name|LineToElement
block|,
name|CurveToElement
block|,
name|CurveToDataElement
block|}
enum|;
name|class
name|Element
block|{
name|public
label|:
name|qreal
name|x
decl_stmt|;
name|qreal
name|y
decl_stmt|;
name|ElementType
name|type
decl_stmt|;
name|bool
name|isMoveTo
argument_list|()
specifier|const
block|{
return|return
name|type
operator|==
name|MoveToElement
return|;
block|}
name|bool
name|isLineTo
argument_list|()
specifier|const
block|{
return|return
name|type
operator|==
name|LineToElement
return|;
block|}
name|bool
name|isCurveTo
argument_list|()
specifier|const
block|{
return|return
name|type
operator|==
name|CurveToElement
return|;
block|}
name|operator
name|QPointF
argument_list|()
specifier|const
block|{
return|return
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Element
operator|&
name|e
operator|)
specifier|const
block|{
return|return
name|qFuzzyCompare
argument_list|(
name|x
argument_list|,
name|e
operator|.
name|x
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|y
argument_list|,
name|e
operator|.
name|y
argument_list|)
operator|&&
name|type
operator|==
name|e
operator|.
name|type
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Element
operator|&
name|e
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|e
operator|)
return|;
block|}
block|}
empty_stmt|;
name|QPainterPath
argument_list|()
expr_stmt|;
name|explicit
name|QPainterPath
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|startPoint
parameter_list|)
function_decl|;
name|QPainterPath
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|other
argument_list|)
expr_stmt|;
name|QPainterPath
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QPainterPath
operator|&
name|other
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QPainterPath
modifier|&
name|operator
init|=
operator|(
name|QPainterPath
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d_ptr
argument_list|,
name|other
operator|.
name|d_ptr
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
operator|~
name|QPainterPath
argument_list|()
expr_stmt|;
specifier|inline
name|void
name|swap
parameter_list|(
name|QPainterPath
modifier|&
name|other
parameter_list|)
block|{
name|d_ptr
operator|.
name|swap
argument_list|(
name|other
operator|.
name|d_ptr
argument_list|)
expr_stmt|;
block|}
name|void
name|closeSubpath
parameter_list|()
function_decl|;
name|void
name|moveTo
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
function_decl|;
specifier|inline
name|void
name|moveTo
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|)
function_decl|;
name|void
name|lineTo
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
function_decl|;
specifier|inline
name|void
name|lineTo
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|)
function_decl|;
name|void
name|arcMoveTo
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|qreal
name|angle
parameter_list|)
function_decl|;
specifier|inline
name|void
name|arcMoveTo
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|,
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|,
name|qreal
name|angle
parameter_list|)
function_decl|;
name|void
name|arcTo
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|qreal
name|startAngle
parameter_list|,
name|qreal
name|arcLength
parameter_list|)
function_decl|;
specifier|inline
name|void
name|arcTo
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|,
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|,
name|qreal
name|startAngle
parameter_list|,
name|qreal
name|arcLength
parameter_list|)
function_decl|;
name|void
name|cubicTo
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|ctrlPt1
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|ctrlPt2
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|endPt
parameter_list|)
function_decl|;
specifier|inline
name|void
name|cubicTo
parameter_list|(
name|qreal
name|ctrlPt1x
parameter_list|,
name|qreal
name|ctrlPt1y
parameter_list|,
name|qreal
name|ctrlPt2x
parameter_list|,
name|qreal
name|ctrlPt2y
parameter_list|,
name|qreal
name|endPtx
parameter_list|,
name|qreal
name|endPty
parameter_list|)
function_decl|;
name|void
name|quadTo
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|ctrlPt
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|endPt
parameter_list|)
function_decl|;
specifier|inline
name|void
name|quadTo
parameter_list|(
name|qreal
name|ctrlPtx
parameter_list|,
name|qreal
name|ctrlPty
parameter_list|,
name|qreal
name|endPtx
parameter_list|,
name|qreal
name|endPty
parameter_list|)
function_decl|;
name|QPointF
name|currentPosition
argument_list|()
specifier|const
expr_stmt|;
name|void
name|addRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
specifier|inline
name|void
name|addRect
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|,
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|)
function_decl|;
name|void
name|addEllipse
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
specifier|inline
name|void
name|addEllipse
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|,
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|)
function_decl|;
specifier|inline
name|void
name|addEllipse
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|center
parameter_list|,
name|qreal
name|rx
parameter_list|,
name|qreal
name|ry
parameter_list|)
function_decl|;
name|void
name|addPolygon
parameter_list|(
specifier|const
name|QPolygonF
modifier|&
name|polygon
parameter_list|)
function_decl|;
name|void
name|addText
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|point
parameter_list|,
specifier|const
name|QFont
modifier|&
name|f
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
specifier|inline
name|void
name|addText
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|,
specifier|const
name|QFont
modifier|&
name|f
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|void
name|addPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
function_decl|;
name|void
name|addRegion
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
name|void
name|addRoundedRect
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|,
name|qreal
name|xRadius
argument_list|,
name|qreal
name|yRadius
argument_list|,
name|Qt
operator|::
name|SizeMode
name|mode
operator|=
name|Qt
operator|::
name|AbsoluteSize
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|addRoundedRect
argument_list|(
name|qreal
name|x
argument_list|,
name|qreal
name|y
argument_list|,
name|qreal
name|w
argument_list|,
name|qreal
name|h
argument_list|,
name|qreal
name|xRadius
argument_list|,
name|qreal
name|yRadius
argument_list|,
name|Qt
operator|::
name|SizeMode
name|mode
operator|=
name|Qt
operator|::
name|AbsoluteSize
argument_list|)
decl_stmt|;
name|void
name|addRoundRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|int
name|xRnd
parameter_list|,
name|int
name|yRnd
parameter_list|)
function_decl|;
specifier|inline
name|void
name|addRoundRect
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|,
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|,
name|int
name|xRnd
parameter_list|,
name|int
name|yRnd
parameter_list|)
function_decl|;
specifier|inline
name|void
name|addRoundRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|int
name|roundness
parameter_list|)
function_decl|;
specifier|inline
name|void
name|addRoundRect
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|,
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|,
name|int
name|roundness
parameter_list|)
function_decl|;
name|void
name|connectPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
function_decl|;
name|bool
name|contains
argument_list|(
specifier|const
name|QPointF
operator|&
name|pt
argument_list|)
decl|const
decl_stmt|;
name|bool
name|contains
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
decl|const
decl_stmt|;
name|bool
name|intersects
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
decl|const
decl_stmt|;
name|void
name|translate
parameter_list|(
name|qreal
name|dx
parameter_list|,
name|qreal
name|dy
parameter_list|)
function_decl|;
specifier|inline
name|void
name|translate
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|offset
parameter_list|)
function_decl|;
name|QPainterPath
name|translated
argument_list|(
name|qreal
name|dx
argument_list|,
name|qreal
name|dy
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|QPainterPath
name|translated
argument_list|(
specifier|const
name|QPointF
operator|&
name|offset
argument_list|)
decl|const
decl_stmt|;
name|QRectF
name|boundingRect
argument_list|()
specifier|const
expr_stmt|;
name|QRectF
name|controlPointRect
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|FillRule
name|fillRule
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFillRule
argument_list|(
name|Qt
operator|::
name|FillRule
name|fillRule
argument_list|)
decl_stmt|;
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|QPainterPath
name|toReversed
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPolygonF
operator|>
name|toSubpathPolygons
argument_list|(
argument|const QMatrix&matrix = QMatrix()
argument_list|)
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPolygonF
operator|>
name|toFillPolygons
argument_list|(
argument|const QMatrix&matrix = QMatrix()
argument_list|)
specifier|const
expr_stmt|;
name|QPolygonF
name|toFillPolygon
argument_list|(
specifier|const
name|QMatrix
operator|&
name|matrix
operator|=
name|QMatrix
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QPolygonF
operator|>
name|toSubpathPolygons
argument_list|(
argument|const QTransform&matrix
argument_list|)
specifier|const
expr_stmt|;
name|QList
operator|<
name|QPolygonF
operator|>
name|toFillPolygons
argument_list|(
argument|const QTransform&matrix
argument_list|)
specifier|const
expr_stmt|;
name|QPolygonF
name|toFillPolygon
argument_list|(
specifier|const
name|QTransform
operator|&
name|matrix
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|int
name|elementCount
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
specifier|const
name|QPainterPath
operator|::
name|Element
operator|&
name|elementAt
argument_list|(
argument|int i
argument_list|)
specifier|const
expr_stmt|;
specifier|inline
name|void
name|setElementPositionAt
parameter_list|(
name|int
name|i
parameter_list|,
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|)
function_decl|;
name|qreal
name|length
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|percentAtLength
argument_list|(
name|qreal
name|t
argument_list|)
decl|const
decl_stmt|;
name|QPointF
name|pointAtPercent
argument_list|(
name|qreal
name|t
argument_list|)
decl|const
decl_stmt|;
name|qreal
name|angleAtPercent
argument_list|(
name|qreal
name|t
argument_list|)
decl|const
decl_stmt|;
name|qreal
name|slopeAtPercent
argument_list|(
name|qreal
name|t
argument_list|)
decl|const
decl_stmt|;
name|bool
name|intersects
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
name|bool
name|contains
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
name|QPainterPath
name|united
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QPainterPath
name|intersected
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QPainterPath
name|subtracted
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QPainterPath
name|subtractedInverted
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QPainterPath
name|simplified
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPainterPath
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPainterPath
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|QPainterPath
name|operator
modifier|&
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
name|QPainterPath
name|operator
operator||
operator|(
specifier|const
name|QPainterPath
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|QPainterPath
name|operator
operator|+
operator|(
specifier|const
name|QPainterPath
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|QPainterPath
name|operator
operator|-
operator|(
specifier|const
name|QPainterPath
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|QPainterPath
operator|&
name|operator
operator|&=
operator|(
specifier|const
name|QPainterPath
operator|&
name|other
operator|)
expr_stmt|;
name|QPainterPath
operator|&
name|operator
operator||=
operator|(
specifier|const
name|QPainterPath
operator|&
name|other
operator|)
expr_stmt|;
name|QPainterPath
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QPainterPath
operator|&
name|other
operator|)
expr_stmt|;
name|QPainterPath
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QPainterPath
operator|&
name|other
operator|)
expr_stmt|;
name|private
label|:
name|QScopedPointer
operator|<
name|QPainterPathPrivate
operator|,
name|QPainterPathPrivateDeleter
operator|>
name|d_ptr
expr_stmt|;
specifier|inline
name|void
name|ensureData
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d_ptr
condition|)
name|ensureData_helper
argument_list|()
expr_stmt|;
block|}
name|void
name|ensureData_helper
parameter_list|()
function_decl|;
specifier|inline
name|void
name|detach
parameter_list|()
function_decl|;
name|void
name|detach_helper
parameter_list|()
function_decl|;
name|void
name|setDirty
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|void
name|computeBoundingRect
argument_list|()
specifier|const
expr_stmt|;
name|void
name|computeControlPointRect
argument_list|()
specifier|const
expr_stmt|;
name|QPainterPathData
operator|*
name|d_func
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|QPainterPathData
operator|*
operator|>
operator|(
name|d_ptr
operator|.
name|data
argument_list|()
operator|)
return|;
block|}
name|friend
name|class
name|QPainterPathData
decl_stmt|;
name|friend
name|class
name|QPainterPathStroker
decl_stmt|;
name|friend
name|class
name|QPainterPathStrokerPrivate
decl_stmt|;
name|friend
name|class
name|QMatrix
decl_stmt|;
name|friend
name|class
name|QTransform
decl_stmt|;
name|friend
name|class
name|QVectorPath
decl_stmt|;
name|friend
name|Q_GUI_EXPORT
specifier|const
name|QVectorPath
modifier|&
name|qtVectorPathForPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QPainterPath
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QPainterPath
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QPainterPathPrivate
block|{
name|public
label|:
name|friend
name|class
name|QPainterPath
decl_stmt|;
name|friend
name|class
name|QPainterPathData
decl_stmt|;
name|friend
name|class
name|QPainterPathStroker
decl_stmt|;
name|friend
name|class
name|QPainterPathStrokerPrivate
decl_stmt|;
name|friend
name|class
name|QMatrix
decl_stmt|;
name|friend
name|class
name|QTransform
decl_stmt|;
name|friend
name|class
name|QVectorPath
decl_stmt|;
name|friend
struct_decl|struct
name|QPainterPathPrivateDeleter
struct_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QPainterPath
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QPainterPath
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
name|QPainterPathPrivate
argument_list|()
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
block|{}
name|private
operator|:
name|QAtomicInt
name|ref
expr_stmt|;
name|QVector
operator|<
name|QPainterPath
operator|::
name|Element
operator|>
name|elements
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QPainterPath
operator|::
name|Element
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QPainterPath
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QPainterPath
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPainterPathStroker
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPainterPathStroker
argument_list|)
name|public
label|:
name|QPainterPathStroker
argument_list|()
expr_stmt|;
operator|~
name|QPainterPathStroker
argument_list|()
expr_stmt|;
name|void
name|setWidth
parameter_list|(
name|qreal
name|width
parameter_list|)
function_decl|;
name|qreal
name|width
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCapStyle
argument_list|(
name|Qt
operator|::
name|PenCapStyle
name|style
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|PenCapStyle
name|capStyle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setJoinStyle
argument_list|(
name|Qt
operator|::
name|PenJoinStyle
name|style
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|PenJoinStyle
name|joinStyle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMiterLimit
parameter_list|(
name|qreal
name|length
parameter_list|)
function_decl|;
name|qreal
name|miterLimit
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCurveThreshold
parameter_list|(
name|qreal
name|threshold
parameter_list|)
function_decl|;
name|qreal
name|curveThreshold
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDashPattern
argument_list|(
name|Qt
operator|::
name|PenStyle
argument_list|)
decl_stmt|;
name|void
name|setDashPattern
argument_list|(
specifier|const
name|QVector
operator|<
name|qreal
operator|>
operator|&
name|dashPattern
argument_list|)
decl_stmt|;
name|QVector
operator|<
name|qreal
operator|>
name|dashPattern
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDashOffset
parameter_list|(
name|qreal
name|offset
parameter_list|)
function_decl|;
name|qreal
name|dashOffset
argument_list|()
specifier|const
expr_stmt|;
name|QPainterPath
name|createStroke
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPainterPathStroker
argument_list|)
name|friend
name|class
name|QX11PaintEngine
decl_stmt|;
name|QScopedPointer
operator|<
name|QPainterPathStrokerPrivate
operator|>
name|d_ptr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|moveTo
specifier|inline
name|void
name|QPainterPath
operator|::
name|moveTo
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
block|{
name|moveTo
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
block|; }
DECL|function|lineTo
specifier|inline
name|void
name|QPainterPath
operator|::
name|lineTo
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
block|{
name|lineTo
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
block|; }
DECL|function|arcTo
specifier|inline
name|void
name|QPainterPath
operator|::
name|arcTo
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|qreal startAngle
argument_list|,
argument|qreal arcLength
argument_list|)
block|{
name|arcTo
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|startAngle
argument_list|,
name|arcLength
argument_list|)
block|; }
DECL|function|arcMoveTo
specifier|inline
name|void
name|QPainterPath
operator|::
name|arcMoveTo
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|qreal angle
argument_list|)
block|{
name|arcMoveTo
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|angle
argument_list|)
block|; }
DECL|function|cubicTo
specifier|inline
name|void
name|QPainterPath
operator|::
name|cubicTo
argument_list|(
argument|qreal ctrlPt1x
argument_list|,
argument|qreal ctrlPt1y
argument_list|,
argument|qreal ctrlPt2x
argument_list|,
argument|qreal ctrlPt2y
argument_list|,
argument|qreal endPtx
argument_list|,
argument|qreal endPty
argument_list|)
block|{
name|cubicTo
argument_list|(
name|QPointF
argument_list|(
name|ctrlPt1x
argument_list|,
name|ctrlPt1y
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|ctrlPt2x
argument_list|,
name|ctrlPt2y
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|endPtx
argument_list|,
name|endPty
argument_list|)
argument_list|)
block|; }
DECL|function|quadTo
specifier|inline
name|void
name|QPainterPath
operator|::
name|quadTo
argument_list|(
argument|qreal ctrlPtx
argument_list|,
argument|qreal ctrlPty
argument_list|,
argument|qreal endPtx
argument_list|,
argument|qreal endPty
argument_list|)
block|{
name|quadTo
argument_list|(
name|QPointF
argument_list|(
name|ctrlPtx
argument_list|,
name|ctrlPty
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|endPtx
argument_list|,
name|endPty
argument_list|)
argument_list|)
block|; }
DECL|function|addEllipse
specifier|inline
name|void
name|QPainterPath
operator|::
name|addEllipse
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|)
block|{
name|addEllipse
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
block|; }
DECL|function|addEllipse
specifier|inline
name|void
name|QPainterPath
operator|::
name|addEllipse
argument_list|(
argument|const QPointF&center
argument_list|,
argument|qreal rx
argument_list|,
argument|qreal ry
argument_list|)
block|{
name|addEllipse
argument_list|(
name|QRectF
argument_list|(
name|center
operator|.
name|x
argument_list|()
operator|-
name|rx
argument_list|,
name|center
operator|.
name|y
argument_list|()
operator|-
name|ry
argument_list|,
literal|2
operator|*
name|rx
argument_list|,
literal|2
operator|*
name|ry
argument_list|)
argument_list|)
block|; }
DECL|function|addRect
specifier|inline
name|void
name|QPainterPath
operator|::
name|addRect
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|)
block|{
name|addRect
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
block|; }
DECL|function|addRoundedRect
specifier|inline
name|void
name|QPainterPath
operator|::
name|addRoundedRect
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|qreal xRadius
argument_list|,
argument|qreal yRadius
argument_list|,
argument|Qt::SizeMode mode
argument_list|)
block|{
name|addRoundedRect
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|xRadius
argument_list|,
name|yRadius
argument_list|,
name|mode
argument_list|)
block|; }
DECL|function|addRoundRect
specifier|inline
name|void
name|QPainterPath
operator|::
name|addRoundRect
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|int xRnd
argument_list|,
argument|int yRnd
argument_list|)
block|{
name|addRoundRect
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|xRnd
argument_list|,
name|yRnd
argument_list|)
block|; }
DECL|function|addRoundRect
specifier|inline
name|void
name|QPainterPath
operator|::
name|addRoundRect
argument_list|(
argument|const QRectF&rect
argument_list|,
argument|int roundness
argument_list|)
block|{
name|int
name|xRnd
operator|=
name|roundness
block|;
name|int
name|yRnd
operator|=
name|roundness
block|;
if|if
condition|(
name|rect
operator|.
name|width
argument_list|()
operator|>
name|rect
operator|.
name|height
argument_list|()
condition|)
name|xRnd
operator|=
name|int
argument_list|(
name|roundness
operator|*
name|rect
operator|.
name|height
argument_list|()
operator|/
name|rect
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|yRnd
operator|=
name|int
argument_list|(
name|roundness
operator|*
name|rect
operator|.
name|width
argument_list|()
operator|/
name|rect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|addRoundRect
argument_list|(
name|rect
argument_list|,
name|xRnd
argument_list|,
name|yRnd
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  inline
DECL|function|addRoundRect
name|void
name|QPainterPath
operator|::
name|addRoundRect
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|int roundness
argument_list|)
block|{
name|addRoundRect
argument_list|(
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|roundness
argument_list|)
block|; }
DECL|function|addText
specifier|inline
name|void
name|QPainterPath
operator|::
name|addText
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|const QFont&f
argument_list|,
argument|const QString&text
argument_list|)
block|{
name|addText
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|,
name|f
argument_list|,
name|text
argument_list|)
block|; }
DECL|function|translate
specifier|inline
name|void
name|QPainterPath
operator|::
name|translate
argument_list|(
argument|const QPointF&offset
argument_list|)
block|{
name|translate
argument_list|(
name|offset
operator|.
name|x
argument_list|()
argument_list|,
name|offset
operator|.
name|y
argument_list|()
argument_list|)
block|; }
DECL|function|translated
specifier|inline
name|QPainterPath
name|QPainterPath
operator|::
name|translated
argument_list|(
argument|const QPointF&offset
argument_list|)
specifier|const
block|{
return|return
name|translated
argument_list|(
name|offset
operator|.
name|x
argument_list|()
argument_list|,
name|offset
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isEmpty
specifier|inline
name|bool
name|QPainterPath
operator|::
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|d_ptr
operator|||
operator|(
name|d_ptr
operator|->
name|elements
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
name|d_ptr
operator|->
name|elements
operator|.
name|first
argument_list|()
operator|.
name|type
operator|==
name|MoveToElement
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|elementCount
specifier|inline
name|int
name|QPainterPath
operator|::
name|elementCount
argument_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|?
name|d_ptr
operator|->
name|elements
operator|.
name|size
argument_list|()
operator|:
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|elementAt
specifier|inline
specifier|const
name|QPainterPath
operator|::
name|Element
operator|&
name|QPainterPath
operator|::
name|elementAt
argument_list|(
argument|int i
argument_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|d_ptr
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<
name|elementCount
argument_list|()
argument_list|)
block|;
return|return
name|d_ptr
operator|->
name|elements
operator|.
name|at
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setElementPositionAt
specifier|inline
name|void
name|QPainterPath
operator|::
name|setElementPositionAt
argument_list|(
argument|int i
argument_list|,
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|d_ptr
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<
name|elementCount
argument_list|()
argument_list|)
block|;
name|detach
argument_list|()
block|;
name|QPainterPath
operator|::
name|Element
operator|&
name|e
operator|=
name|d_ptr
operator|->
name|elements
index|[
name|i
index|]
block|;
name|e
operator|.
name|x
operator|=
name|x
block|;
name|e
operator|.
name|y
operator|=
name|y
block|; }
DECL|function|detach
specifier|inline
name|void
name|QPainterPath
operator|::
name|detach
argument_list|()
block|{
if|if
condition|(
name|d_ptr
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|!=
literal|1
condition|)
name|detach_helper
argument_list|()
expr_stmt|;
name|setDirty
argument_list|(
name|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifndef
unit|}
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
unit|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QPainterPath
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTERPATH_H
end_comment
end_unit
