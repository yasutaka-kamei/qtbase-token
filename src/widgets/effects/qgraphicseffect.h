begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSEFFECT_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSEFFECT_H
define|#
directive|define
name|QGRAPHICSEFFECT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
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
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qbrush.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSEFFECT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsItem
name|class
name|QGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOption
name|class
name|QStyleOption
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsEffectSource
name|class
name|QGraphicsEffectSource
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsEffectPrivate
name|class
name|QGraphicsEffectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsEffect
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_FLAGS
argument_list|(
argument|ChangeFlags
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged
argument_list|)
name|public
operator|:
expr|enum
name|ChangeFlag
block|{
name|SourceAttached
operator|=
literal|0x1
block|,
name|SourceDetached
operator|=
literal|0x2
block|,
name|SourceBoundingRectChanged
operator|=
literal|0x4
block|,
name|SourceInvalidated
operator|=
literal|0x8
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|ChangeFlags
argument_list|,
name|ChangeFlag
argument_list|)
expr|enum
name|PixmapPadMode
block|{
name|NoPad
block|,
name|PadToTransparentBorder
block|,
name|PadToEffectiveBoundingRect
block|}
block|;
name|QGraphicsEffect
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QGraphicsEffect
argument_list|()
block|;
name|virtual
name|QRectF
name|boundingRectFor
argument_list|(
argument|const QRectF&sourceRect
argument_list|)
specifier|const
block|;
name|QRectF
name|boundingRect
argument_list|()
specifier|const
block|;
name|bool
name|isEnabled
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|void
name|update
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|enabledChanged
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|protected
operator|:
name|QGraphicsEffect
argument_list|(
name|QGraphicsEffectPrivate
operator|&
name|d
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|sourceChanged
argument_list|(
argument|ChangeFlags flags
argument_list|)
block|;
name|void
name|updateBoundingRect
argument_list|()
block|;
name|bool
name|sourceIsPixmap
argument_list|()
specifier|const
block|;
name|QRectF
name|sourceBoundingRect
argument_list|(
argument|Qt::CoordinateSystem system = Qt::LogicalCoordinates
argument_list|)
specifier|const
block|;
name|void
name|drawSource
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|QPixmap
name|sourcePixmap
argument_list|(
argument|Qt::CoordinateSystem system = Qt::LogicalCoordinates
argument_list|,
argument|QPoint *offset =
literal|0
argument_list|,
argument|PixmapPadMode mode = PadToEffectiveBoundingRect
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsEffect
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsEffect
argument_list|)
name|friend
name|class
name|QGraphicsItem
block|;
name|friend
name|class
name|QGraphicsItemPrivate
block|;
name|friend
name|class
name|QGraphicsScenePrivate
block|;
name|friend
name|class
name|QWidget
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|public
operator|:
name|QGraphicsEffectSource
operator|*
name|source
argument_list|()
specifier|const
block|;
comment|// internal
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGraphicsEffect::ChangeFlags
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|QGraphicsColorizeEffectPrivate
name|class
name|QGraphicsColorizeEffectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsColorizeEffect
range|:
name|public
name|QGraphicsEffect
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QColor color READ color WRITE setColor NOTIFY colorChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal strength READ strength WRITE setStrength NOTIFY strengthChanged
argument_list|)
name|public
operator|:
name|QGraphicsColorizeEffect
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsColorizeEffect
argument_list|()
block|;
name|QColor
name|color
argument_list|()
specifier|const
block|;
name|qreal
name|strength
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setColor
argument_list|(
specifier|const
name|QColor
operator|&
name|c
argument_list|)
block|;
name|void
name|setStrength
argument_list|(
argument|qreal strength
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|colorChanged
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|strengthChanged
argument_list|(
argument|qreal strength
argument_list|)
block|;
name|protected
operator|:
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsColorizeEffect
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsColorizeEffect
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsBlurEffectPrivate
name|class
name|QGraphicsBlurEffectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsBlurEffect
range|:
name|public
name|QGraphicsEffect
block|{
name|Q_OBJECT
name|Q_FLAGS
argument_list|(
argument|BlurHint BlurHints
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal blurRadius READ blurRadius WRITE setBlurRadius NOTIFY blurRadiusChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|BlurHints blurHints READ blurHints WRITE setBlurHints NOTIFY blurHintsChanged
argument_list|)
name|public
operator|:
expr|enum
name|BlurHint
block|{
name|PerformanceHint
operator|=
literal|0x00
block|,
name|QualityHint
operator|=
literal|0x01
block|,
name|AnimationHint
operator|=
literal|0x02
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|BlurHints
argument_list|,
argument|BlurHint
argument_list|)
name|QGraphicsBlurEffect
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsBlurEffect
argument_list|()
block|;
name|QRectF
name|boundingRectFor
argument_list|(
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|qreal
name|blurRadius
argument_list|()
specifier|const
block|;
name|BlurHints
name|blurHints
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setBlurRadius
argument_list|(
argument|qreal blurRadius
argument_list|)
block|;
name|void
name|setBlurHints
argument_list|(
argument|BlurHints hints
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|blurRadiusChanged
argument_list|(
argument|qreal blurRadius
argument_list|)
block|;
name|void
name|blurHintsChanged
argument_list|(
argument|BlurHints hints
argument_list|)
block|;
name|protected
operator|:
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsBlurEffect
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsBlurEffect
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGraphicsBlurEffect::BlurHints
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|QGraphicsDropShadowEffectPrivate
name|class
name|QGraphicsDropShadowEffectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsDropShadowEffect
range|:
name|public
name|QGraphicsEffect
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QPointF offset READ offset WRITE setOffset NOTIFY offsetChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal xOffset READ xOffset WRITE setXOffset NOTIFY offsetChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal yOffset READ yOffset WRITE setYOffset NOTIFY offsetChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal blurRadius READ blurRadius WRITE setBlurRadius NOTIFY blurRadiusChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QColor color READ color WRITE setColor NOTIFY colorChanged
argument_list|)
name|public
operator|:
name|QGraphicsDropShadowEffect
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsDropShadowEffect
argument_list|()
block|;
name|QRectF
name|boundingRectFor
argument_list|(
argument|const QRectF&rect
argument_list|)
specifier|const
block|;
name|QPointF
name|offset
argument_list|()
specifier|const
block|;
specifier|inline
name|qreal
name|xOffset
argument_list|()
specifier|const
block|{
return|return
name|offset
argument_list|()
operator|.
name|x
argument_list|()
return|;
block|}
specifier|inline
name|qreal
name|yOffset
argument_list|()
specifier|const
block|{
return|return
name|offset
argument_list|()
operator|.
name|y
argument_list|()
return|;
block|}
name|qreal
name|blurRadius
argument_list|()
specifier|const
block|;
name|QColor
name|color
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setOffset
argument_list|(
specifier|const
name|QPointF
operator|&
name|ofs
argument_list|)
block|;
specifier|inline
name|void
name|setOffset
argument_list|(
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
block|{
name|setOffset
argument_list|(
name|QPointF
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
argument_list|)
block|; }
specifier|inline
name|void
name|setOffset
argument_list|(
argument|qreal d
argument_list|)
block|{
name|setOffset
argument_list|(
name|QPointF
argument_list|(
name|d
argument_list|,
name|d
argument_list|)
argument_list|)
block|; }
specifier|inline
name|void
name|setXOffset
argument_list|(
argument|qreal dx
argument_list|)
block|{
name|setOffset
argument_list|(
name|QPointF
argument_list|(
name|dx
argument_list|,
name|yOffset
argument_list|()
argument_list|)
argument_list|)
block|; }
specifier|inline
name|void
name|setYOffset
argument_list|(
argument|qreal dy
argument_list|)
block|{
name|setOffset
argument_list|(
name|QPointF
argument_list|(
name|xOffset
argument_list|()
argument_list|,
name|dy
argument_list|)
argument_list|)
block|; }
name|void
name|setBlurRadius
argument_list|(
argument|qreal blurRadius
argument_list|)
block|;
name|void
name|setColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|offsetChanged
argument_list|(
specifier|const
name|QPointF
operator|&
name|offset
argument_list|)
block|;
name|void
name|blurRadiusChanged
argument_list|(
argument|qreal blurRadius
argument_list|)
block|;
name|void
name|colorChanged
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|protected
operator|:
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsDropShadowEffect
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsDropShadowEffect
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsOpacityEffectPrivate
name|class
name|QGraphicsOpacityEffectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsOpacityEffect
range|:
name|public
name|QGraphicsEffect
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|qreal opacity READ opacity WRITE setOpacity NOTIFY opacityChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QBrush opacityMask READ opacityMask WRITE setOpacityMask NOTIFY opacityMaskChanged
argument_list|)
name|public
operator|:
name|QGraphicsOpacityEffect
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QGraphicsOpacityEffect
argument_list|()
block|;
name|qreal
name|opacity
argument_list|()
specifier|const
block|;
name|QBrush
name|opacityMask
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setOpacity
argument_list|(
argument|qreal opacity
argument_list|)
block|;
name|void
name|setOpacityMask
argument_list|(
specifier|const
name|QBrush
operator|&
name|mask
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|opacityChanged
argument_list|(
argument|qreal opacity
argument_list|)
block|;
name|void
name|opacityMaskChanged
argument_list|(
specifier|const
name|QBrush
operator|&
name|mask
argument_list|)
block|;
name|protected
operator|:
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsOpacityEffect
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsOpacityEffect
argument_list|)
block|}
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
comment|//QT_NO_GRAPHICSEFFECT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGRAPHICSEFFECT_H
end_comment
end_unit
