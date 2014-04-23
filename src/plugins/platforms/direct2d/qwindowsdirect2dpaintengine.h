begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSDIRECT2DPAINTENGINE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSDIRECT2DPAINTENGINE_H
define|#
directive|define
name|QWINDOWSDIRECT2DPAINTENGINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpaintengineex_p.h>
end_include
begin_include
include|#
directive|include
file|<d2d1_1.h>
end_include
begin_include
include|#
directive|include
file|<dwrite_1.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsDirect2DPaintEnginePrivate
name|class
name|QWindowsDirect2DPaintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsDirect2DBitmap
name|class
name|QWindowsDirect2DBitmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsDirect2DPaintEngine
range|:
name|public
name|QPaintEngineEx
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWindowsDirect2DPaintEngine
argument_list|)
name|public
operator|:
name|QWindowsDirect2DPaintEngine
argument_list|(
name|QWindowsDirect2DBitmap
operator|*
name|bitmap
argument_list|)
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
name|Type
name|type
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|fill
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|const QBrush&brush
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|clip
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|Qt::ClipOperation op
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|clipEnabledChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|penChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|brushChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|brushOriginChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|opacityChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|compositionModeChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|renderHintsChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|transformChanged
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawImage
argument_list|(
argument|const QRectF&rectangle
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
name|drawStaticTextItem
argument_list|(
argument|QStaticTextItem *staticTextItem
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawTextItem
argument_list|(
argument|const QPointF&p
argument_list|,
argument|const QTextItem&textItem
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|drawGlyphRun
argument_list|(
argument|const D2D1_POINT_2F&pos
argument_list|,
argument|IDWriteFontFace *fontFace
argument_list|,
argument|const QFont&font
argument_list|,
argument|int numGlyphs
argument_list|,
argument|const UINT16 *glyphIndices
argument_list|,
argument|const FLOAT *glyphAdvances
argument_list|,
argument|const DWRITE_GLYPH_OFFSET *glyphOffsets
argument_list|,
argument|bool rtl
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
comment|// QWINDOWSDIRECT2DPAINTENGINE_H
end_comment
end_unit
