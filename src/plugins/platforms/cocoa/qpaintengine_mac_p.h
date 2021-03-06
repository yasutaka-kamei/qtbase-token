begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTENGINE_MAC_P_H
end_ifndef
begin_define
DECL|macro|QPAINTENGINE_MAC_P_H
define|#
directive|define
name|QPAINTENGINE_MAC_P_H
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
file|"QtGui/qpaintengine.h"
end_include
begin_include
include|#
directive|include
file|"private/qpaintengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qpolygonclipper_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qfont_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"qt_mac_p.h"
end_include
begin_typedef
DECL|typedef|CGColorSpaceRef
typedef|typedef
name|struct
name|CGColorSpace
modifier|*
name|CGColorSpaceRef
typedef|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCoreGraphicsPaintEnginePrivate
name|class
name|QCoreGraphicsPaintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCoreGraphicsPaintEngine
range|:
name|public
name|QPaintEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QCoreGraphicsPaintEngine
argument_list|)
name|public
operator|:
name|QCoreGraphicsPaintEngine
argument_list|()
block|;
operator|~
name|QCoreGraphicsPaintEngine
argument_list|()
block|;
name|bool
name|begin
argument_list|(
name|QPaintDevice
operator|*
name|pdev
argument_list|)
block|;
name|bool
name|end
argument_list|()
block|;
specifier|static
name|CGColorSpaceRef
name|macGenericColorSpace
argument_list|()
block|;
specifier|static
name|CGColorSpaceRef
name|macDisplayColorSpace
argument_list|(
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
block|;
name|void
name|updateState
argument_list|(
specifier|const
name|QPaintEngineState
operator|&
name|state
argument_list|)
block|;
name|void
name|updatePen
argument_list|(
specifier|const
name|QPen
operator|&
name|pen
argument_list|)
block|;
name|void
name|updateBrush
argument_list|(
specifier|const
name|QBrush
operator|&
name|brush
argument_list|,
specifier|const
name|QPointF
operator|&
name|pt
argument_list|)
block|;
name|void
name|updateFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|void
name|updateOpacity
argument_list|(
argument|qreal opacity
argument_list|)
block|;
name|void
name|updateMatrix
argument_list|(
specifier|const
name|QTransform
operator|&
name|matrix
argument_list|)
block|;
name|void
name|updateTransform
argument_list|(
specifier|const
name|QTransform
operator|&
name|matrix
argument_list|)
block|;
name|void
name|updateClipRegion
argument_list|(
argument|const QRegion&region
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|void
name|updateClipPath
argument_list|(
argument|const QPainterPath&path
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
block|;
name|void
name|updateCompositionMode
argument_list|(
argument|QPainter::CompositionMode mode
argument_list|)
block|;
name|void
name|updateRenderHints
argument_list|(
argument|QPainter::RenderHints hints
argument_list|)
block|;
name|void
name|drawLines
argument_list|(
argument|const QLineF *lines
argument_list|,
argument|int lineCount
argument_list|)
block|;
name|void
name|drawRects
argument_list|(
argument|const QRectF *rects
argument_list|,
argument|int rectCount
argument_list|)
block|;
name|void
name|drawPoints
argument_list|(
argument|const QPointF *p
argument_list|,
argument|int pointCount
argument_list|)
block|;
name|void
name|drawEllipse
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|)
block|;
name|void
name|drawPath
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|)
block|;
name|void
name|drawPolygon
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int pointCount
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
block|;
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pm
argument_list|,
specifier|const
name|QRectF
operator|&
name|sr
argument_list|)
block|;
name|void
name|drawTiledPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QPointF
operator|&
name|s
argument_list|)
block|;
name|void
name|drawTextItem
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|,
specifier|const
name|QTextItem
operator|&
name|item
argument_list|)
block|;
name|void
name|drawImage
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QImage&pm
argument_list|,
argument|const QRectF&sr
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|QPaintEngine
operator|::
name|CoreGraphics
return|;
block|}
name|CGContextRef
name|handle
argument_list|()
specifier|const
block|;
specifier|static
name|void
name|initialize
argument_list|()
block|;
specifier|static
name|void
name|cleanup
argument_list|()
block|;
name|QPainter
operator|::
name|RenderHints
name|supportedRenderHints
argument_list|()
specifier|const
block|;
comment|//avoid partial shadowed overload warnings...
name|void
name|drawLines
argument_list|(
argument|const QLine *lines
argument_list|,
argument|int lineCount
argument_list|)
block|{
name|QPaintEngine
operator|::
name|drawLines
argument_list|(
name|lines
argument_list|,
name|lineCount
argument_list|)
block|; }
name|void
name|drawRects
argument_list|(
argument|const QRect *rects
argument_list|,
argument|int rectCount
argument_list|)
block|{
name|QPaintEngine
operator|::
name|drawRects
argument_list|(
name|rects
argument_list|,
name|rectCount
argument_list|)
block|; }
name|void
name|drawPoints
argument_list|(
argument|const QPoint *p
argument_list|,
argument|int pointCount
argument_list|)
block|{
name|QPaintEngine
operator|::
name|drawPoints
argument_list|(
name|p
argument_list|,
name|pointCount
argument_list|)
block|; }
name|void
name|drawEllipse
argument_list|(
argument|const QRect&r
argument_list|)
block|{
name|QPaintEngine
operator|::
name|drawEllipse
argument_list|(
name|r
argument_list|)
block|; }
name|void
name|drawPolygon
argument_list|(
argument|const QPoint *points
argument_list|,
argument|int pointCount
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
block|{
name|QPaintEngine
operator|::
name|drawPolygon
argument_list|(
name|points
argument_list|,
name|pointCount
argument_list|,
name|mode
argument_list|)
block|; }
name|protected
operator|:
name|friend
name|class
name|QMacPrintEngine
block|;
name|friend
name|class
name|QMacPrintEnginePrivate
block|;
name|QCoreGraphicsPaintEngine
argument_list|(
name|QPaintEnginePrivate
operator|&
name|dptr
argument_list|)
block|;
name|private
operator|:
specifier|static
name|bool
name|m_postRoutineRegistered
block|;
specifier|static
name|CGColorSpaceRef
name|m_genericColorSpace
block|;
specifier|static
name|QHash
operator|<
name|CGDirectDisplayID
block|,
name|CGColorSpaceRef
operator|>
name|m_displayColorSpaceHash
block|;
specifier|static
name|void
name|cleanUpMacColorSpaces
argument_list|()
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QCoreGraphicsPaintEngine
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*****************************************************************************   Private data  *****************************************************************************/
end_comment
begin_decl_stmt
name|class
name|QCoreGraphicsPaintEnginePrivate
range|:
name|public
name|QPaintEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QCoreGraphicsPaintEngine
argument_list|)
name|public
operator|:
name|QCoreGraphicsPaintEnginePrivate
argument_list|()
operator|:
name|hd
argument_list|(
literal|0
argument_list|)
block|,
name|shading
argument_list|(
literal|0
argument_list|)
block|,
name|stackCount
argument_list|(
literal|0
argument_list|)
block|,
name|complexXForm
argument_list|(
name|false
argument_list|)
block|,
name|disabledSmoothFonts
argument_list|(
argument|false
argument_list|)
block|{     }
expr|struct
block|{
name|QPen
name|pen
block|;
name|QBrush
name|brush
block|;
name|uint
name|clipEnabled
operator|:
literal|1
block|;
name|QRegion
name|clip
block|;
name|QTransform
name|transform
block|;    }
name|current
block|;
comment|//state info (shared with QD)
name|CGAffineTransform
name|orig_xform
block|;
comment|//cg structures
name|CGContextRef
name|hd
block|;
name|CGShadingRef
name|shading
block|;
name|int
name|stackCount
block|;
name|bool
name|complexXForm
block|;
name|bool
name|disabledSmoothFonts
block|;     enum
block|{
name|CosmeticNone
block|,
name|CosmeticTransformPath
block|,
name|CosmeticSetPenWidth
block|}
name|cosmeticPen
block|;
comment|// pixel and cosmetic pen size in user coordinates.
name|QPointF
name|pixelSize
block|;
name|float
name|cosmeticPenSize
block|;
comment|//internal functions
block|enum
block|{
name|CGStroke
operator|=
literal|0x01
block|,
name|CGEOFill
operator|=
literal|0x02
block|,
name|CGFill
operator|=
literal|0x04
block|}
block|;
name|void
name|drawPath
argument_list|(
argument|uchar ops
argument_list|,
argument|CGMutablePathRef path =
literal|0
argument_list|)
block|;
name|void
name|setClip
argument_list|(
specifier|const
name|QRegion
operator|*
name|rgn
operator|=
literal|0
argument_list|)
block|;
name|void
name|resetClip
argument_list|()
block|;
name|void
name|setFillBrush
argument_list|(
specifier|const
name|QPointF
operator|&
name|origin
operator|=
name|QPoint
argument_list|()
argument_list|)
block|;
name|void
name|setStrokePen
argument_list|(
specifier|const
name|QPen
operator|&
name|pen
argument_list|)
block|;
specifier|inline
name|void
name|saveGraphicsState
argument_list|()
block|;
specifier|inline
name|void
name|restoreGraphicsState
argument_list|()
block|;
name|float
name|penOffset
argument_list|()
block|;
name|QPointF
name|devicePixelSize
argument_list|(
argument|CGContextRef context
argument_list|)
block|;
name|float
name|adjustPenWidth
argument_list|(
argument|float penWidth
argument_list|)
block|;
specifier|inline
name|void
name|setTransform
argument_list|(
argument|const QTransform *matrix=
literal|0
argument_list|)
block|{
name|CGContextConcatCTM
argument_list|(
name|hd
argument_list|,
name|CGAffineTransformInvert
argument_list|(
name|CGContextGetCTM
argument_list|(
name|hd
argument_list|)
argument_list|)
argument_list|)
block|;
name|CGAffineTransform
name|xform
operator|=
name|orig_xform
block|;
if|if
condition|(
name|matrix
condition|)
block|{
specifier|extern
name|CGAffineTransform
name|qt_mac_convert_transform_to_cg
parameter_list|(
specifier|const
name|QTransform
modifier|&
parameter_list|)
function_decl|;
name|xform
operator|=
name|CGAffineTransformConcat
argument_list|(
name|qt_mac_convert_transform_to_cg
argument_list|(
operator|*
name|matrix
argument_list|)
argument_list|,
name|xform
argument_list|)
expr_stmt|;
block|}
name|CGContextConcatCTM
argument_list|(
name|hd
argument_list|,
name|xform
argument_list|)
expr_stmt|;
name|CGContextSetTextMatrix
argument_list|(
name|hd
argument_list|,
name|xform
argument_list|)
block|;     }
end_decl_stmt
begin_expr_stmt
unit|};
DECL|function|saveGraphicsState
specifier|inline
name|void
name|QCoreGraphicsPaintEnginePrivate
operator|::
name|saveGraphicsState
argument_list|()
block|{
operator|++
name|stackCount
block|;
name|CGContextSaveGState
argument_list|(
name|hd
argument_list|)
block|; }
DECL|function|restoreGraphicsState
specifier|inline
name|void
name|QCoreGraphicsPaintEnginePrivate
operator|::
name|restoreGraphicsState
argument_list|()
block|{
operator|--
name|stackCount
block|;
name|Q_ASSERT
argument_list|(
name|stackCount
operator|>=
literal|0
argument_list|)
block|;
name|CGContextRestoreGState
argument_list|(
name|hd
argument_list|)
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTENGINE_MAC_P_H
end_comment
end_unit
