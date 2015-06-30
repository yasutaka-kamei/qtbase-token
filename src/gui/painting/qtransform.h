begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTRANSFORM_H
end_ifndef
begin_define
DECL|macro|QTRANSFORM_H
define|#
directive|define
name|QTRANSFORM_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qmatrix.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpainterpath.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpolygon.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qregion.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qline.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTransform
block|{
name|public
label|:
enum|enum
name|TransformationType
block|{
name|TxNone
init|=
literal|0x00
block|,
name|TxTranslate
init|=
literal|0x01
block|,
name|TxScale
init|=
literal|0x02
block|,
name|TxRotate
init|=
literal|0x04
block|,
name|TxShear
init|=
literal|0x08
block|,
name|TxProject
init|=
literal|0x10
block|}
enum|;
specifier|inline
name|explicit
name|QTransform
argument_list|(
name|Qt
operator|::
name|Initialization
argument_list|)
range|:
name|affine
argument_list|(
argument|Qt::Uninitialized
argument_list|)
block|{}
name|QTransform
argument_list|()
decl_stmt|;
name|QTransform
argument_list|(
argument|qreal h11
argument_list|,
argument|qreal h12
argument_list|,
argument|qreal h13
argument_list|,
argument|qreal h21
argument_list|,
argument|qreal h22
argument_list|,
argument|qreal h23
argument_list|,
argument|qreal h31
argument_list|,
argument|qreal h32
argument_list|,
argument|qreal h33 =
literal|1.0
argument_list|)
empty_stmt|;
name|QTransform
argument_list|(
argument|qreal h11
argument_list|,
argument|qreal h12
argument_list|,
argument|qreal h21
argument_list|,
argument|qreal h22
argument_list|,
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
empty_stmt|;
name|explicit
name|QTransform
parameter_list|(
specifier|const
name|QMatrix
modifier|&
name|mtx
parameter_list|)
function_decl|;
name|bool
name|isAffine
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isIdentity
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isInvertible
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isScaling
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isRotating
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isTranslating
argument_list|()
specifier|const
expr_stmt|;
name|TransformationType
name|type
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|qreal
name|determinant
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|det
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|m11
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|m12
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|m13
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|m21
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|m22
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|m23
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|m31
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|m32
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|m33
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|dx
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|dy
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMatrix
parameter_list|(
name|qreal
name|m11
parameter_list|,
name|qreal
name|m12
parameter_list|,
name|qreal
name|m13
parameter_list|,
name|qreal
name|m21
parameter_list|,
name|qreal
name|m22
parameter_list|,
name|qreal
name|m23
parameter_list|,
name|qreal
name|m31
parameter_list|,
name|qreal
name|m32
parameter_list|,
name|qreal
name|m33
parameter_list|)
function_decl|;
name|QTransform
name|inverted
argument_list|(
name|bool
operator|*
name|invertible
operator|=
name|Q_NULLPTR
argument_list|)
decl|const
name|Q_REQUIRED_RESULT
decl_stmt|;
name|QTransform
name|adjoint
argument_list|()
specifier|const
name|Q_REQUIRED_RESULT
expr_stmt|;
name|QTransform
name|transposed
argument_list|()
specifier|const
name|Q_REQUIRED_RESULT
expr_stmt|;
name|QTransform
modifier|&
name|translate
parameter_list|(
name|qreal
name|dx
parameter_list|,
name|qreal
name|dy
parameter_list|)
function_decl|;
name|QTransform
modifier|&
name|scale
parameter_list|(
name|qreal
name|sx
parameter_list|,
name|qreal
name|sy
parameter_list|)
function_decl|;
name|QTransform
modifier|&
name|shear
parameter_list|(
name|qreal
name|sh
parameter_list|,
name|qreal
name|sv
parameter_list|)
function_decl|;
name|QTransform
modifier|&
name|rotate
argument_list|(
name|qreal
name|a
argument_list|,
name|Qt
operator|::
name|Axis
name|axis
operator|=
name|Qt
operator|::
name|ZAxis
argument_list|)
decl_stmt|;
name|QTransform
modifier|&
name|rotateRadians
argument_list|(
name|qreal
name|a
argument_list|,
name|Qt
operator|::
name|Axis
name|axis
operator|=
name|Qt
operator|::
name|ZAxis
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|squareToQuad
parameter_list|(
specifier|const
name|QPolygonF
modifier|&
name|square
parameter_list|,
name|QTransform
modifier|&
name|result
parameter_list|)
function_decl|;
specifier|static
name|bool
name|quadToSquare
parameter_list|(
specifier|const
name|QPolygonF
modifier|&
name|quad
parameter_list|,
name|QTransform
modifier|&
name|result
parameter_list|)
function_decl|;
specifier|static
name|bool
name|quadToQuad
parameter_list|(
specifier|const
name|QPolygonF
modifier|&
name|one
parameter_list|,
specifier|const
name|QPolygonF
modifier|&
name|two
parameter_list|,
name|QTransform
modifier|&
name|result
parameter_list|)
function_decl|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QTransform
operator|&
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QTransform
operator|&
operator|)
specifier|const
expr_stmt|;
name|QTransform
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|QTransform
operator|&
operator|)
expr_stmt|;
name|QTransform
name|operator
modifier|*
argument_list|(
specifier|const
name|QTransform
operator|&
name|o
argument_list|)
decl|const
decl_stmt|;
name|QTransform
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QTransform
operator|&
operator|)
decl_stmt|;
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
name|void
name|reset
parameter_list|()
function_decl|;
name|QPoint
name|map
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
name|QPointF
name|map
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
name|QLine
name|map
argument_list|(
specifier|const
name|QLine
operator|&
name|l
argument_list|)
decl|const
decl_stmt|;
name|QLineF
name|map
argument_list|(
specifier|const
name|QLineF
operator|&
name|l
argument_list|)
decl|const
decl_stmt|;
name|QPolygonF
name|map
argument_list|(
specifier|const
name|QPolygonF
operator|&
name|a
argument_list|)
decl|const
decl_stmt|;
name|QPolygon
name|map
argument_list|(
specifier|const
name|QPolygon
operator|&
name|a
argument_list|)
decl|const
decl_stmt|;
name|QRegion
name|map
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QPainterPath
name|map
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
name|QPolygon
name|mapToPolygon
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|mapRect
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|)
decl|const
decl_stmt|;
name|QRectF
name|mapRect
argument_list|(
specifier|const
name|QRectF
operator|&
argument_list|)
decl|const
decl_stmt|;
name|void
name|map
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
name|int
operator|*
name|tx
argument_list|,
name|int
operator|*
name|ty
argument_list|)
decl|const
decl_stmt|;
name|void
name|map
argument_list|(
name|qreal
name|x
argument_list|,
name|qreal
name|y
argument_list|,
name|qreal
operator|*
name|tx
argument_list|,
name|qreal
operator|*
name|ty
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QMatrix
operator|&
name|toAffine
argument_list|()
specifier|const
expr_stmt|;
name|QTransform
operator|&
name|operator
operator|*=
operator|(
name|qreal
name|div
operator|)
expr_stmt|;
name|QTransform
operator|&
name|operator
operator|/=
operator|(
name|qreal
name|div
operator|)
expr_stmt|;
name|QTransform
operator|&
name|operator
operator|+=
operator|(
name|qreal
name|div
operator|)
expr_stmt|;
name|QTransform
operator|&
name|operator
operator|-=
operator|(
name|qreal
name|div
operator|)
expr_stmt|;
specifier|static
name|QTransform
name|fromTranslate
parameter_list|(
name|qreal
name|dx
parameter_list|,
name|qreal
name|dy
parameter_list|)
function_decl|;
specifier|static
name|QTransform
name|fromScale
parameter_list|(
name|qreal
name|dx
parameter_list|,
name|qreal
name|dy
parameter_list|)
function_decl|;
name|private
label|:
specifier|inline
name|QTransform
argument_list|(
argument|qreal h11
argument_list|,
argument|qreal h12
argument_list|,
argument|qreal h13
argument_list|,
argument|qreal h21
argument_list|,
argument|qreal h22
argument_list|,
argument|qreal h23
argument_list|,
argument|qreal h31
argument_list|,
argument|qreal h32
argument_list|,
argument|qreal h33
argument_list|,
argument|bool
argument_list|)
operator|:
name|affine
argument_list|(
name|h11
argument_list|,
name|h12
argument_list|,
name|h21
argument_list|,
name|h22
argument_list|,
name|h31
argument_list|,
name|h32
argument_list|,
name|true
argument_list|)
operator|,
name|m_13
argument_list|(
name|h13
argument_list|)
operator|,
name|m_23
argument_list|(
name|h23
argument_list|)
operator|,
name|m_33
argument_list|(
name|h33
argument_list|)
operator|,
name|m_type
argument_list|(
name|TxNone
argument_list|)
operator|,
name|m_dirty
argument_list|(
name|TxProject
argument_list|)
operator|,
name|d
argument_list|(
argument|Q_NULLPTR
argument_list|)
block|{     }
specifier|inline
name|QTransform
argument_list|(
name|bool
argument_list|)
operator|:
name|affine
argument_list|(
name|true
argument_list|)
operator|,
name|m_13
argument_list|(
literal|0
argument_list|)
operator|,
name|m_23
argument_list|(
literal|0
argument_list|)
operator|,
name|m_33
argument_list|(
literal|1
argument_list|)
operator|,
name|m_type
argument_list|(
name|TxNone
argument_list|)
operator|,
name|m_dirty
argument_list|(
name|TxNone
argument_list|)
operator|,
name|d
argument_list|(
argument|Q_NULLPTR
argument_list|)
block|{     }
specifier|inline
name|TransformationType
name|inline_type
argument_list|()
specifier|const
expr_stmt|;
name|QMatrix
name|affine
decl_stmt|;
name|qreal
name|m_13
decl_stmt|;
name|qreal
name|m_23
decl_stmt|;
name|qreal
name|m_33
decl_stmt|;
name|mutable
name|uint
name|m_type
range|:
literal|5
decl_stmt|;
name|mutable
name|uint
name|m_dirty
range|:
literal|5
decl_stmt|;
name|class
name|Private
decl_stmt|;
name|Private
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QTransform
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|Q_GUI_EXPORT
name|Q_DECL_CONST_FUNCTION
name|uint
name|qHash
argument_list|(
specifier|const
name|QTransform
operator|&
name|key
argument_list|,
name|uint
name|seed
operator|=
literal|0
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
end_decl_stmt
begin_comment
comment|/******* inlines *****/
end_comment
begin_expr_stmt
DECL|function|inline_type
specifier|inline
name|QTransform
operator|::
name|TransformationType
name|QTransform
operator|::
name|inline_type
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_dirty
operator|==
name|TxNone
condition|)
return|return
name|static_cast
operator|<
name|TransformationType
operator|>
operator|(
name|m_type
operator|)
return|;
end_expr_stmt
begin_return
return|return
name|type
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|isAffine
name|bool
name|QTransform
operator|::
name|isAffine
argument_list|()
specifier|const
block|{
return|return
name|inline_type
argument_list|()
operator|<
name|TxProject
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isIdentity
specifier|inline
name|bool
name|QTransform
operator|::
name|isIdentity
argument_list|()
specifier|const
block|{
return|return
name|inline_type
argument_list|()
operator|==
name|TxNone
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isInvertible
specifier|inline
name|bool
name|QTransform
operator|::
name|isInvertible
argument_list|()
specifier|const
block|{
return|return
operator|!
name|qFuzzyIsNull
argument_list|(
name|determinant
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isScaling
specifier|inline
name|bool
name|QTransform
operator|::
name|isScaling
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|>=
name|TxScale
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isRotating
specifier|inline
name|bool
name|QTransform
operator|::
name|isRotating
argument_list|()
specifier|const
block|{
return|return
name|inline_type
argument_list|()
operator|>=
name|TxRotate
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isTranslating
specifier|inline
name|bool
name|QTransform
operator|::
name|isTranslating
argument_list|()
specifier|const
block|{
return|return
name|inline_type
argument_list|()
operator|>=
name|TxTranslate
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|determinant
specifier|inline
name|qreal
name|QTransform
operator|::
name|determinant
argument_list|()
specifier|const
block|{
return|return
name|affine
operator|.
name|_m11
operator|*
operator|(
name|m_33
operator|*
name|affine
operator|.
name|_m22
operator|-
name|affine
operator|.
name|_dy
operator|*
name|m_23
operator|)
operator|-
name|affine
operator|.
name|_m21
operator|*
operator|(
name|m_33
operator|*
name|affine
operator|.
name|_m12
operator|-
name|affine
operator|.
name|_dy
operator|*
name|m_13
operator|)
operator|+
name|affine
operator|.
name|_dx
operator|*
operator|(
name|m_23
operator|*
name|affine
operator|.
name|_m12
operator|-
name|affine
operator|.
name|_m22
operator|*
name|m_13
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|det
specifier|inline
name|qreal
name|QTransform
operator|::
name|det
argument_list|()
specifier|const
block|{
return|return
name|determinant
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|m11
specifier|inline
name|qreal
name|QTransform
operator|::
name|m11
argument_list|()
specifier|const
block|{
return|return
name|affine
operator|.
name|_m11
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|m12
specifier|inline
name|qreal
name|QTransform
operator|::
name|m12
argument_list|()
specifier|const
block|{
return|return
name|affine
operator|.
name|_m12
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|m13
specifier|inline
name|qreal
name|QTransform
operator|::
name|m13
argument_list|()
specifier|const
block|{
return|return
name|m_13
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|m21
specifier|inline
name|qreal
name|QTransform
operator|::
name|m21
argument_list|()
specifier|const
block|{
return|return
name|affine
operator|.
name|_m21
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|m22
specifier|inline
name|qreal
name|QTransform
operator|::
name|m22
argument_list|()
specifier|const
block|{
return|return
name|affine
operator|.
name|_m22
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|m23
specifier|inline
name|qreal
name|QTransform
operator|::
name|m23
argument_list|()
specifier|const
block|{
return|return
name|m_23
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|m31
specifier|inline
name|qreal
name|QTransform
operator|::
name|m31
argument_list|()
specifier|const
block|{
return|return
name|affine
operator|.
name|_dx
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|m32
specifier|inline
name|qreal
name|QTransform
operator|::
name|m32
argument_list|()
specifier|const
block|{
return|return
name|affine
operator|.
name|_dy
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|m33
specifier|inline
name|qreal
name|QTransform
operator|::
name|m33
argument_list|()
specifier|const
block|{
return|return
name|m_33
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|dx
specifier|inline
name|qreal
name|QTransform
operator|::
name|dx
argument_list|()
specifier|const
block|{
return|return
name|affine
operator|.
name|_dx
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|dy
specifier|inline
name|qreal
name|QTransform
operator|::
name|dy
argument_list|()
specifier|const
block|{
return|return
name|affine
operator|.
name|_dy
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|member|operator
specifier|inline
name|QTransform
operator|&
name|QTransform
operator|::
name|operator
operator|*=
operator|(
name|qreal
name|num
operator|)
block|{
if|if
condition|(
name|num
operator|==
literal|1.
condition|)
return|return
operator|*
name|this
return|;
name|affine
operator|.
name|_m11
operator|*=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_m12
operator|*=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_13
operator|*=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_m21
operator|*=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_m22
operator|*=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_23
operator|*=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_dx
operator|*=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_dy
operator|*=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_33
operator|*=
name|num
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|m_dirty
operator|<
name|TxScale
condition|)
name|m_dirty
operator|=
name|TxScale
expr_stmt|;
end_if
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_expr_stmt
unit|} inline
name|QTransform
operator|&
name|QTransform
operator|::
name|operator
operator|/=
operator|(
name|qreal
name|div
operator|)
block|{
if|if
condition|(
name|div
operator|==
literal|0
condition|)
return|return
operator|*
name|this
return|;
name|div
operator|=
literal|1
operator|/
name|div
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|operator
operator|*=
operator|(
name|div
operator|)
return|;
end_return
begin_expr_stmt
unit|} inline
name|QTransform
operator|&
name|QTransform
operator|::
name|operator
operator|+=
operator|(
name|qreal
name|num
operator|)
block|{
if|if
condition|(
name|num
operator|==
literal|0
condition|)
return|return
operator|*
name|this
return|;
name|affine
operator|.
name|_m11
operator|+=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_m12
operator|+=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_13
operator|+=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_m21
operator|+=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_m22
operator|+=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_23
operator|+=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_dx
operator|+=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_dy
operator|+=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_33
operator|+=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_dirty
operator|=
name|TxProject
expr_stmt|;
end_expr_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_expr_stmt
unit|} inline
name|QTransform
operator|&
name|QTransform
operator|::
name|operator
operator|-=
operator|(
name|qreal
name|num
operator|)
block|{
if|if
condition|(
name|num
operator|==
literal|0
condition|)
return|return
operator|*
name|this
return|;
name|affine
operator|.
name|_m11
operator|-=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_m12
operator|-=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_13
operator|-=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_m21
operator|-=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_m22
operator|-=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_23
operator|-=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_dx
operator|-=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|affine
operator|.
name|_dy
operator|-=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_33
operator|-=
name|num
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_dirty
operator|=
name|TxProject
expr_stmt|;
end_expr_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_function
unit|}  inline
name|bool
name|qFuzzyCompare
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|t1
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|t2
parameter_list|)
block|{
return|return
name|qFuzzyCompare
argument_list|(
name|t1
operator|.
name|m11
argument_list|()
argument_list|,
name|t2
operator|.
name|m11
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|t1
operator|.
name|m12
argument_list|()
argument_list|,
name|t2
operator|.
name|m12
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|t1
operator|.
name|m13
argument_list|()
argument_list|,
name|t2
operator|.
name|m13
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|t1
operator|.
name|m21
argument_list|()
argument_list|,
name|t2
operator|.
name|m21
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|t1
operator|.
name|m22
argument_list|()
argument_list|,
name|t2
operator|.
name|m22
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|t1
operator|.
name|m23
argument_list|()
argument_list|,
name|t2
operator|.
name|m23
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|t1
operator|.
name|m31
argument_list|()
argument_list|,
name|t2
operator|.
name|m31
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|t1
operator|.
name|m32
argument_list|()
argument_list|,
name|t2
operator|.
name|m32
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|t1
operator|.
name|m33
argument_list|()
argument_list|,
name|t2
operator|.
name|m33
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/****** stream functions *******************/
end_comment
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
name|QTransform
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
name|QTransform
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
name|QTransform
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/****** end stream functions *******************/
end_comment
begin_comment
comment|// mathematical semantics
end_comment
begin_function
specifier|inline
name|QPoint
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|QPointF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|QLineF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QLineF
modifier|&
name|l
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|l
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|QLine
name|operator
modifier|*
parameter_list|(
specifier|const
name|QLine
modifier|&
name|l
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|l
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|QPolygon
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPolygon
modifier|&
name|a
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|QPolygonF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPolygonF
modifier|&
name|a
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|QRegion
name|operator
modifier|*
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|r
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|r
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|QPainterPath
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|p
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|QTransform
name|operator
modifier|*
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|a
parameter_list|,
name|qreal
name|n
parameter_list|)
block|{
name|QTransform
name|t
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|t
operator|*=
name|n
expr_stmt|;
return|return
name|t
return|;
block|}
end_function
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QTransform
name|operator
operator|/
operator|(
specifier|const
name|QTransform
operator|&
name|a
operator|,
name|qreal
name|n
operator|)
block|{
name|QTransform
name|t
argument_list|(
name|a
argument_list|)
block|;
name|t
operator|/=
name|n
block|;
return|return
name|t
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QTransform
name|operator
operator|+
operator|(
specifier|const
name|QTransform
operator|&
name|a
operator|,
name|qreal
name|n
operator|)
block|{
name|QTransform
name|t
argument_list|(
name|a
argument_list|)
block|;
name|t
operator|+=
name|n
block|;
return|return
name|t
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QTransform
name|operator
operator|-
operator|(
specifier|const
name|QTransform
operator|&
name|a
operator|,
name|qreal
name|n
operator|)
block|{
name|QTransform
name|t
argument_list|(
name|a
argument_list|)
block|;
name|t
operator|-=
name|n
block|;
return|return
name|t
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTRANSFORM_H
end_comment
end_unit
