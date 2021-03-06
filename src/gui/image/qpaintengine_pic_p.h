begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTENGINE_PIC_P_H
end_ifndef
begin_define
DECL|macro|QPAINTENGINE_PIC_P_H
define|#
directive|define
name|QPAINTENGINE_PIC_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of QAbstractItemModel*.  This header file may change from version
end_comment
begin_comment
comment|// to version without notice, or even be removed.
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
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtGui/qpaintengine.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PICTURE
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPicturePaintEnginePrivate
name|class
name|QPicturePaintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBuffer
name|class
name|QBuffer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPicturePaintEngine
range|:
name|public
name|QPaintEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPicturePaintEngine
argument_list|)
name|public
operator|:
name|QPicturePaintEngine
argument_list|()
block|;
operator|~
name|QPicturePaintEngine
argument_list|()
block|;
name|bool
name|begin
argument_list|(
argument|QPaintDevice *pdev
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|end
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|updateState
argument_list|(
argument|const QPaintEngineState&state
argument_list|)
name|Q_DECL_OVERRIDE
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
argument_list|)
block|;
name|void
name|updateBrushOrigin
argument_list|(
specifier|const
name|QPointF
operator|&
name|origin
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
name|updateBackground
argument_list|(
argument|Qt::BGMode bgmode
argument_list|,
argument|const QBrush&bgBrush
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
name|updateRenderHints
argument_list|(
argument|QPainter::RenderHints hints
argument_list|)
block|;
name|void
name|updateCompositionMode
argument_list|(
argument|QPainter::CompositionMode cmode
argument_list|)
block|;
name|void
name|updateClipEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|updateOpacity
argument_list|(
argument|qreal opacity
argument_list|)
block|;
name|void
name|drawEllipse
argument_list|(
argument|const QRectF&rect
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawPath
argument_list|(
argument|const QPainterPath&path
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawPolygon
argument_list|(
argument|const QPointF *points
argument_list|,
argument|int numPoints
argument_list|,
argument|PolygonDrawMode mode
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|using
name|QPaintEngine
operator|::
name|drawPolygon
block|;
name|void
name|drawPixmap
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QPixmap&pm
argument_list|,
argument|const QRectF&sr
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawTiledPixmap
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QPixmap&pixmap
argument_list|,
argument|const QPointF&s
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawImage
argument_list|(
argument|const QRectF&r
argument_list|,
argument|const QImage&image
argument_list|,
argument|const QRectF&sr
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawTextItem
argument_list|(
argument|const QPointF&p
argument_list|,
argument|const QTextItem&ti
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Type
name|type
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|Picture
return|;
block|}
name|protected
operator|:
name|QPicturePaintEngine
argument_list|(
name|QPaintEnginePrivate
operator|&
name|dptr
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPicturePaintEngine
argument_list|)
name|void
name|writeCmdLength
argument_list|(
argument|int pos
argument_list|,
argument|const QRectF&r
argument_list|,
argument|bool corr
argument_list|)
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
comment|// QT_NO_PICTURE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAINTENGINE_PIC_P_H
end_comment
end_unit
