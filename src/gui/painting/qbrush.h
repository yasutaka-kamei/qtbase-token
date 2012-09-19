begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBRUSH_H
end_ifndef
begin_define
DECL|macro|QBRUSH_H
define|#
directive|define
name|QBRUSH_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
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
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qmatrix.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtransform.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_data
argument_list|)
end_if
begin_undef
DECL|macro|m_data
undef|#
directive|undef
name|m_data
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_type
argument_list|)
end_if
begin_undef
DECL|macro|m_type
undef|#
directive|undef
name|m_type
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
expr|struct
name|QBrushData
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGradient
name|class
name|QGradient
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QBrushDataPointerDeleter
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QBrush
block|{
name|public
label|:
name|QBrush
argument_list|()
expr_stmt|;
name|QBrush
argument_list|(
argument|Qt::BrushStyle bs
argument_list|)
empty_stmt|;
name|QBrush
argument_list|(
argument|const QColor&color
argument_list|,
argument|Qt::BrushStyle bs=Qt::SolidPattern
argument_list|)
empty_stmt|;
name|QBrush
argument_list|(
argument|Qt::GlobalColor color
argument_list|,
argument|Qt::BrushStyle bs=Qt::SolidPattern
argument_list|)
empty_stmt|;
name|QBrush
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|)
expr_stmt|;
name|QBrush
argument_list|(
argument|Qt::GlobalColor color
argument_list|,
argument|const QPixmap&pixmap
argument_list|)
empty_stmt|;
name|QBrush
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|)
expr_stmt|;
name|QBrush
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
expr_stmt|;
name|QBrush
argument_list|(
specifier|const
name|QBrush
operator|&
name|brush
argument_list|)
expr_stmt|;
name|QBrush
argument_list|(
specifier|const
name|QGradient
operator|&
name|gradient
argument_list|)
expr_stmt|;
operator|~
name|QBrush
argument_list|()
expr_stmt|;
name|QBrush
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QBrush
operator|&
name|brush
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QBrush
modifier|&
name|operator
init|=
operator|(
name|QBrush
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
parameter_list|(
name|QBrush
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|Qt
operator|::
name|BrushStyle
name|style
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStyle
argument_list|(
name|Qt
operator|::
name|BrushStyle
argument_list|)
decl_stmt|;
specifier|inline
specifier|const
name|QMatrix
operator|&
name|matrix
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMatrix
parameter_list|(
specifier|const
name|QMatrix
modifier|&
name|mat
parameter_list|)
function_decl|;
specifier|inline
name|QTransform
name|transform
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTransform
parameter_list|(
specifier|const
name|QTransform
modifier|&
parameter_list|)
function_decl|;
name|QPixmap
name|texture
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTexture
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
function_decl|;
name|QImage
name|textureImage
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTextureImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
specifier|inline
specifier|const
name|QColor
operator|&
name|color
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setColor
argument_list|(
name|Qt
operator|::
name|GlobalColor
name|color
argument_list|)
decl_stmt|;
specifier|const
name|QGradient
operator|*
name|gradient
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isOpaque
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QBrush
operator|&
name|b
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QBrush
operator|&
name|b
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|operator
operator|==
operator|(
name|b
operator|)
operator|)
return|;
block|}
name|private
label|:
name|friend
name|class
name|QRasterPaintEngine
decl_stmt|;
name|friend
name|class
name|QRasterPaintEnginePrivate
decl_stmt|;
name|friend
struct_decl|struct
name|QSpanData
struct_decl|;
name|friend
name|class
name|QPainter
decl_stmt|;
name|friend
name|bool
name|Q_GUI_EXPORT
name|qHasPixmapTexture
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
function_decl|;
name|void
name|detach
argument_list|(
name|Qt
operator|::
name|BrushStyle
name|newStyle
argument_list|)
decl_stmt|;
name|void
name|init
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|,
name|Qt
operator|::
name|BrushStyle
name|bs
argument_list|)
decl_stmt|;
name|QScopedPointer
operator|<
name|QBrushData
operator|,
name|QBrushDataPointerDeleter
operator|>
name|d
expr_stmt|;
name|void
name|cleanUp
parameter_list|(
name|QBrushData
modifier|*
name|x
parameter_list|)
function_decl|;
name|public
label|:
specifier|inline
name|bool
name|isDetached
argument_list|()
specifier|const
expr_stmt|;
typedef|typedef
name|QScopedPointer
operator|<
name|QBrushData
operator|,
name|QBrushDataPointerDeleter
operator|>
name|DataPtr
expr_stmt|;
specifier|inline
name|DataPtr
modifier|&
name|data_ptr
parameter_list|()
block|{
return|return
name|d
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|setColor
specifier|inline
name|void
name|QBrush
operator|::
name|setColor
argument_list|(
argument|Qt::GlobalColor acolor
argument_list|)
block|{
name|setColor
argument_list|(
name|QColor
argument_list|(
name|acolor
argument_list|)
argument_list|)
block|; }
name|Q_DECLARE_SHARED
argument_list|(
argument|QBrush
argument_list|)
comment|/*****************************************************************************   QBrush stream functions  *****************************************************************************/
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
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
name|QBrush
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|operator
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QBrush
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QBrush
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_struct
DECL|struct|QBrushData
struct|struct
name|QBrushData
block|{
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|style
name|Qt
operator|::
name|BrushStyle
name|style
expr_stmt|;
DECL|member|color
name|QColor
name|color
decl_stmt|;
DECL|member|transform
name|QTransform
name|transform
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
DECL|function|style
specifier|inline
name|Qt
operator|::
name|BrushStyle
name|QBrush
operator|::
name|style
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|style
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|color
specifier|inline
specifier|const
name|QColor
operator|&
name|QBrush
operator|::
name|color
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|color
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|matrix
specifier|inline
specifier|const
name|QMatrix
operator|&
name|QBrush
operator|::
name|matrix
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|transform
operator|.
name|toAffine
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|transform
specifier|inline
name|QTransform
name|QBrush
operator|::
name|transform
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|transform
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isDetached
specifier|inline
name|bool
name|QBrush
operator|::
name|isDetached
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|ref
operator|.
name|load
argument_list|()
operator|==
literal|1
return|;
block|}
end_expr_stmt
begin_comment
comment|/*******************************************************************************  * QGradients  */
end_comment
begin_decl_stmt
DECL|variable|QGradientPrivate
name|class
name|QGradientPrivate
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|qreal
DECL|typedef|QGradientStop
typedef|typedef
name|QPair
operator|<
name|qreal
operator|,
name|QColor
operator|>
name|QGradientStop
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QGradientStops
typedef|typedef
name|QVector
operator|<
name|QGradientStop
operator|>
name|QGradientStops
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QGradient
block|{
name|Q_GADGET
name|Q_ENUMS
argument_list|(
name|Type
name|Spread
name|CoordinateMode
argument_list|)
name|public
range|:     enum
name|Type
block|{
name|LinearGradient
block|,
name|RadialGradient
block|,
name|ConicalGradient
block|,
name|NoGradient
block|}
decl_stmt|;
enum|enum
name|Spread
block|{
name|PadSpread
block|,
name|ReflectSpread
block|,
name|RepeatSpread
block|}
enum|;
enum|enum
name|CoordinateMode
block|{
name|LogicalMode
block|,
name|StretchToDeviceMode
block|,
name|ObjectBoundingMode
block|}
enum|;
enum|enum
name|InterpolationMode
block|{
name|ColorInterpolation
block|,
name|ComponentInterpolation
block|}
enum|;
name|QGradient
argument_list|()
expr_stmt|;
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
specifier|inline
name|void
name|setSpread
parameter_list|(
name|Spread
name|spread
parameter_list|)
function_decl|;
name|Spread
name|spread
argument_list|()
specifier|const
block|{
return|return
name|m_spread
return|;
block|}
name|void
name|setColorAt
parameter_list|(
name|qreal
name|pos
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
name|void
name|setStops
parameter_list|(
specifier|const
name|QGradientStops
modifier|&
name|stops
parameter_list|)
function_decl|;
name|QGradientStops
name|stops
argument_list|()
specifier|const
expr_stmt|;
name|CoordinateMode
name|coordinateMode
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCoordinateMode
parameter_list|(
name|CoordinateMode
name|mode
parameter_list|)
function_decl|;
name|InterpolationMode
name|interpolationMode
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setInterpolationMode
parameter_list|(
name|InterpolationMode
name|mode
parameter_list|)
function_decl|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QGradient
operator|&
name|gradient
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QGradient
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
name|private
label|:
name|friend
name|class
name|QLinearGradient
decl_stmt|;
name|friend
name|class
name|QRadialGradient
decl_stmt|;
name|friend
name|class
name|QConicalGradient
decl_stmt|;
name|friend
name|class
name|QBrush
decl_stmt|;
name|Type
name|m_type
decl_stmt|;
name|Spread
name|m_spread
decl_stmt|;
name|QGradientStops
name|m_stops
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|qreal
name|x1
decl_stmt|,
name|y1
decl_stmt|,
name|x2
decl_stmt|,
name|y2
decl_stmt|;
block|}
name|linear
struct|;
struct|struct
block|{
name|qreal
name|cx
decl_stmt|,
name|cy
decl_stmt|,
name|fx
decl_stmt|,
name|fy
decl_stmt|,
name|cradius
decl_stmt|;
block|}
name|radial
struct|;
struct|struct
block|{
name|qreal
name|cx
decl_stmt|,
name|cy
decl_stmt|,
name|angle
decl_stmt|;
block|}
name|conical
struct|;
block|}
name|m_data
union|;
name|void
modifier|*
name|dummy
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|setSpread
specifier|inline
name|void
name|QGradient
operator|::
name|setSpread
argument_list|(
argument|Spread aspread
argument_list|)
block|{
name|m_spread
operator|=
name|aspread
block|; }
name|class
name|Q_GUI_EXPORT
name|QLinearGradient
operator|:
name|public
name|QGradient
block|{
name|public
operator|:
name|QLinearGradient
argument_list|()
block|;
name|QLinearGradient
argument_list|(
specifier|const
name|QPointF
operator|&
name|start
argument_list|,
specifier|const
name|QPointF
operator|&
name|finalStop
argument_list|)
block|;
name|QLinearGradient
argument_list|(
argument|qreal xStart
argument_list|,
argument|qreal yStart
argument_list|,
argument|qreal xFinalStop
argument_list|,
argument|qreal yFinalStop
argument_list|)
block|;
name|QPointF
name|start
argument_list|()
specifier|const
block|;
name|void
name|setStart
argument_list|(
specifier|const
name|QPointF
operator|&
name|start
argument_list|)
block|;
specifier|inline
name|void
name|setStart
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
block|{
name|setStart
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
block|; }
name|QPointF
name|finalStop
argument_list|()
specifier|const
block|;
name|void
name|setFinalStop
argument_list|(
specifier|const
name|QPointF
operator|&
name|stop
argument_list|)
block|;
specifier|inline
name|void
name|setFinalStop
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
block|{
name|setFinalStop
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
block|; }
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QRadialGradient
range|:
name|public
name|QGradient
block|{
name|public
operator|:
name|QRadialGradient
argument_list|()
block|;
name|QRadialGradient
argument_list|(
argument|const QPointF&center
argument_list|,
argument|qreal radius
argument_list|,
argument|const QPointF&focalPoint
argument_list|)
block|;
name|QRadialGradient
argument_list|(
argument|qreal cx
argument_list|,
argument|qreal cy
argument_list|,
argument|qreal radius
argument_list|,
argument|qreal fx
argument_list|,
argument|qreal fy
argument_list|)
block|;
name|QRadialGradient
argument_list|(
argument|const QPointF&center
argument_list|,
argument|qreal radius
argument_list|)
block|;
name|QRadialGradient
argument_list|(
argument|qreal cx
argument_list|,
argument|qreal cy
argument_list|,
argument|qreal radius
argument_list|)
block|;
name|QRadialGradient
argument_list|(
argument|const QPointF&center
argument_list|,
argument|qreal centerRadius
argument_list|,
argument|const QPointF&focalPoint
argument_list|,
argument|qreal focalRadius
argument_list|)
block|;
name|QRadialGradient
argument_list|(
argument|qreal cx
argument_list|,
argument|qreal cy
argument_list|,
argument|qreal centerRadius
argument_list|,
argument|qreal fx
argument_list|,
argument|qreal fy
argument_list|,
argument|qreal focalRadius
argument_list|)
block|;
name|QPointF
name|center
argument_list|()
specifier|const
block|;
name|void
name|setCenter
argument_list|(
specifier|const
name|QPointF
operator|&
name|center
argument_list|)
block|;
specifier|inline
name|void
name|setCenter
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
block|{
name|setCenter
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
block|; }
name|QPointF
name|focalPoint
argument_list|()
specifier|const
block|;
name|void
name|setFocalPoint
argument_list|(
specifier|const
name|QPointF
operator|&
name|focalPoint
argument_list|)
block|;
specifier|inline
name|void
name|setFocalPoint
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
block|{
name|setFocalPoint
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
block|; }
name|qreal
name|radius
argument_list|()
specifier|const
block|;
name|void
name|setRadius
argument_list|(
argument|qreal radius
argument_list|)
block|;
name|qreal
name|centerRadius
argument_list|()
specifier|const
block|;
name|void
name|setCenterRadius
argument_list|(
argument|qreal radius
argument_list|)
block|;
name|qreal
name|focalRadius
argument_list|()
specifier|const
block|;
name|void
name|setFocalRadius
argument_list|(
argument|qreal radius
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QConicalGradient
range|:
name|public
name|QGradient
block|{
name|public
operator|:
name|QConicalGradient
argument_list|()
block|;
name|QConicalGradient
argument_list|(
argument|const QPointF&center
argument_list|,
argument|qreal startAngle
argument_list|)
block|;
name|QConicalGradient
argument_list|(
argument|qreal cx
argument_list|,
argument|qreal cy
argument_list|,
argument|qreal startAngle
argument_list|)
block|;
name|QPointF
name|center
argument_list|()
specifier|const
block|;
name|void
name|setCenter
argument_list|(
specifier|const
name|QPointF
operator|&
name|center
argument_list|)
block|;
specifier|inline
name|void
name|setCenter
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|)
block|{
name|setCenter
argument_list|(
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
block|; }
name|qreal
name|angle
argument_list|()
specifier|const
block|;
name|void
name|setAngle
argument_list|(
argument|qreal angle
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBRUSH_H
end_comment
end_unit
