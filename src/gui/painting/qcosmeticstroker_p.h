begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOSMETICSTROKER_P_H
end_ifndef
begin_define
DECL|macro|QCOSMETICSTROKER_P_H
define|#
directive|define
name|QCOSMETICSTROKER_P_H
end_define
begin_include
include|#
directive|include
file|<private/qdrawhelper_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qvectorpath_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengine_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<qpen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QCosmeticStroker
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|StrokeLine
typedef|typedef
name|void
function_decl|(
modifier|*
name|StrokeLine
function_decl|)
parameter_list|(
name|QCosmeticStroker
modifier|*
name|stroker
parameter_list|,
name|qreal
name|x1
parameter_list|,
name|qreal
name|y1
parameter_list|,
name|qreal
name|x2
parameter_list|,
name|qreal
name|y2
parameter_list|,
name|int
name|caps
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
name|class
name|QCosmeticStroker
block|{
name|public
label|:
struct|struct
name|Point
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
struct|struct
name|PointF
block|{
name|qreal
name|x
decl_stmt|;
name|qreal
name|y
decl_stmt|;
block|}
struct|;
enum|enum
name|Caps
block|{
name|NoCaps
init|=
literal|0
block|,
name|CapBegin
init|=
literal|0x1
block|,
name|CapEnd
init|=
literal|0x2
block|,     }
enum|;
comment|// used to avoid drop outs or duplicated points
enum|enum
name|Direction
block|{
name|TopToBottom
block|,
name|BottomToTop
block|,
name|LeftToRight
block|,
name|RightToLeft
block|}
enum|;
name|QCosmeticStroker
argument_list|(
name|QRasterPaintEngineState
operator|*
name|s
argument_list|,
specifier|const
name|QRect
operator|&
name|dr
argument_list|)
operator|:
name|state
argument_list|(
name|s
argument_list|)
operator|,
name|clip
argument_list|(
name|dr
argument_list|)
operator|,
name|pattern
argument_list|(
literal|0
argument_list|)
operator|,
name|reversePattern
argument_list|(
literal|0
argument_list|)
operator|,
name|patternSize
argument_list|(
literal|0
argument_list|)
operator|,
name|patternLength
argument_list|(
literal|0
argument_list|)
operator|,
name|patternOffset
argument_list|(
literal|0
argument_list|)
operator|,
name|current_span
argument_list|(
literal|0
argument_list|)
operator|,
name|lastDir
argument_list|(
name|LeftToRight
argument_list|)
operator|,
name|lastAxisAligned
argument_list|(
argument|false
argument_list|)
block|{
name|setup
argument_list|()
block|; }
operator|~
name|QCosmeticStroker
argument_list|()
block|{
name|free
argument_list|(
name|pattern
argument_list|)
block|;
name|free
argument_list|(
name|reversePattern
argument_list|)
block|; }
name|void
name|drawLine
argument_list|(
specifier|const
name|QPointF
operator|&
name|p1
argument_list|,
specifier|const
name|QPointF
operator|&
name|p2
argument_list|)
expr_stmt|;
name|void
name|drawPath
parameter_list|(
specifier|const
name|QVectorPath
modifier|&
name|path
parameter_list|)
function_decl|;
name|void
name|drawPoints
parameter_list|(
specifier|const
name|QPoint
modifier|*
name|points
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
name|void
name|drawPoints
parameter_list|(
specifier|const
name|QPointF
modifier|*
name|points
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
name|QRasterPaintEngineState
modifier|*
name|state
decl_stmt|;
name|QRect
name|clip
decl_stmt|;
comment|// clip bounds in real
name|qreal
name|xmin
decl_stmt|,
name|xmax
decl_stmt|;
name|qreal
name|ymin
decl_stmt|,
name|ymax
decl_stmt|;
name|StrokeLine
name|stroke
decl_stmt|;
name|bool
name|drawCaps
decl_stmt|;
name|int
modifier|*
name|pattern
decl_stmt|;
name|int
modifier|*
name|reversePattern
decl_stmt|;
name|int
name|patternSize
decl_stmt|;
name|int
name|patternLength
decl_stmt|;
name|int
name|patternOffset
decl_stmt|;
enum|enum
block|{
name|NSPANS
init|=
literal|255
block|}
enum|;
name|QT_FT_Span
name|spans
index|[
name|NSPANS
index|]
decl_stmt|;
name|int
name|current_span
decl_stmt|;
name|ProcessSpans
name|blend
decl_stmt|;
name|int
name|opacity
decl_stmt|;
name|uint
name|color
decl_stmt|;
name|uint
modifier|*
name|pixels
decl_stmt|;
name|int
name|ppl
decl_stmt|;
name|Direction
name|lastDir
decl_stmt|;
name|Point
name|lastPixel
decl_stmt|;
name|bool
name|lastAxisAligned
decl_stmt|;
name|private
label|:
name|void
name|setup
parameter_list|()
function_decl|;
name|void
name|renderCubic
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p1
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p2
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p3
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p4
parameter_list|,
name|int
name|caps
parameter_list|)
function_decl|;
name|void
name|renderCubicSubdivision
parameter_list|(
name|PointF
modifier|*
name|points
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|caps
parameter_list|)
function_decl|;
comment|// used for closed subpaths
name|void
name|calculateLastPoint
parameter_list|(
name|qreal
name|rx1
parameter_list|,
name|qreal
name|ry1
parameter_list|,
name|qreal
name|rx2
parameter_list|,
name|qreal
name|ry2
parameter_list|)
function_decl|;
name|public
label|:
name|bool
name|clipLine
parameter_list|(
name|qreal
modifier|&
name|x1
parameter_list|,
name|qreal
modifier|&
name|y1
parameter_list|,
name|qreal
modifier|&
name|x2
parameter_list|,
name|qreal
modifier|&
name|y2
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOSMETICLINE_H
end_comment
end_unit
