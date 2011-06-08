begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSEFFECT_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSEFFECT_P_H
define|#
directive|define
name|QGRAPHICSEFFECT_P_H
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
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
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
file|"qgraphicseffect.h"
end_include
begin_include
include|#
directive|include
file|<QPixmapCache>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpixmapfilter_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSEFFECT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsEffectSourcePrivate
name|class
name|QGraphicsEffectSourcePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsEffectSource
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
operator|~
name|QGraphicsEffectSource
argument_list|()
block|;
specifier|const
name|QGraphicsItem
operator|*
name|graphicsItem
argument_list|()
specifier|const
block|;
specifier|const
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|;
specifier|const
name|QStyleOption
operator|*
name|styleOption
argument_list|()
specifier|const
block|;
name|bool
name|isPixmap
argument_list|()
specifier|const
block|;
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|void
name|update
argument_list|()
block|;
name|QRectF
name|boundingRect
argument_list|(
argument|Qt::CoordinateSystem coordinateSystem = Qt::LogicalCoordinates
argument_list|)
specifier|const
block|;
name|QRect
name|deviceRect
argument_list|()
specifier|const
block|;
name|QPixmap
name|pixmap
argument_list|(
argument|Qt::CoordinateSystem system = Qt::LogicalCoordinates
argument_list|,
argument|QPoint *offset =
literal|0
argument_list|,
argument|QGraphicsEffect::PixmapPadMode mode = QGraphicsEffect::PadToEffectiveBoundingRect
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QGraphicsEffectSource
argument_list|(
name|QGraphicsEffectSourcePrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsEffectSource
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsEffectSource
argument_list|)
name|friend
name|class
name|QGraphicsEffect
block|;
name|friend
name|class
name|QGraphicsEffectPrivate
block|;
name|friend
name|class
name|QGraphicsScenePrivate
block|;
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
name|QWidget
block|;
name|friend
name|class
name|QWidgetPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGraphicsEffectSourcePrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsEffectSource
argument_list|)
name|public
operator|:
name|QGraphicsEffectSourcePrivate
argument_list|()
operator|:
name|QObjectPrivate
argument_list|()
block|,
name|m_cachedSystem
argument_list|(
name|Qt
operator|::
name|DeviceCoordinates
argument_list|)
block|,
name|m_cachedMode
argument_list|(
argument|QGraphicsEffect::PadToTransparentBorder
argument_list|)
block|{}
expr|enum
name|InvalidateReason
block|{
name|TransformChanged
block|,
name|EffectRectChanged
block|,
name|SourceChanged
block|}
block|;
name|virtual
operator|~
name|QGraphicsEffectSourcePrivate
argument_list|()
block|;
name|virtual
name|void
name|detach
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|QRectF
name|boundingRect
argument_list|(
argument|Qt::CoordinateSystem system
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QRect
name|deviceRect
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|QGraphicsItem
operator|*
name|graphicsItem
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|QStyleOption
operator|*
name|styleOption
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|update
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|isPixmap
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QPixmap
name|pixmap
argument_list|(
argument|Qt::CoordinateSystem system
argument_list|,
argument|QPoint *offset =
literal|0
argument_list|,
argument|QGraphicsEffect::PixmapPadMode mode = QGraphicsEffect::PadToTransparentBorder
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|effectBoundingRectChanged
argument_list|()
operator|=
literal|0
block|;
name|void
name|setCachedOffset
argument_list|(
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|void
name|invalidateCache
argument_list|(
argument|InvalidateReason reason = SourceChanged
argument_list|)
specifier|const
block|;
name|Qt
operator|::
name|CoordinateSystem
name|currentCachedSystem
argument_list|()
specifier|const
block|{
return|return
name|m_cachedSystem
return|;
block|}
name|QGraphicsEffect
operator|::
name|PixmapPadMode
name|currentCachedMode
argument_list|()
specifier|const
block|{
return|return
name|m_cachedMode
return|;
block|}
name|friend
name|class
name|QGraphicsScenePrivate
block|;
name|friend
name|class
name|QGraphicsItem
block|;
name|friend
name|class
name|QGraphicsItemPrivate
block|;
name|private
operator|:
name|mutable
name|Qt
operator|::
name|CoordinateSystem
name|m_cachedSystem
block|;
name|mutable
name|QGraphicsEffect
operator|::
name|PixmapPadMode
name|m_cachedMode
block|;
name|mutable
name|QPoint
name|m_cachedOffset
block|;
name|mutable
name|QPixmapCache
operator|::
name|Key
name|m_cacheKey
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGraphicsEffectPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsEffect
argument_list|)
name|public
operator|:
name|QGraphicsEffectPrivate
argument_list|()
operator|:
name|source
argument_list|(
literal|0
argument_list|)
block|,
name|isEnabled
argument_list|(
literal|1
argument_list|)
block|{}
specifier|inline
name|void
name|setGraphicsEffectSource
argument_list|(
argument|QGraphicsEffectSource *newSource
argument_list|)
block|{
name|QGraphicsEffect
operator|::
name|ChangeFlags
name|flags
block|;
if|if
condition|(
name|source
condition|)
block|{
name|flags
operator||=
name|QGraphicsEffect
operator|::
name|SourceDetached
expr_stmt|;
name|source
operator|->
name|d_func
argument_list|()
operator|->
name|invalidateCache
argument_list|()
expr_stmt|;
name|source
operator|->
name|d_func
argument_list|()
operator|->
name|detach
argument_list|()
expr_stmt|;
name|delete
name|source
decl_stmt|;
block|}
name|source
operator|=
name|newSource
expr_stmt|;
if|if
condition|(
name|newSource
condition|)
name|flags
operator||=
name|QGraphicsEffect
operator|::
name|SourceAttached
expr_stmt|;
name|q_func
argument_list|()
operator|->
name|sourceChanged
argument_list|(
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|}      QGraphicsEffectSource
operator|*
name|source
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QRectF
name|boundingRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|quint32
name|isEnabled
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|quint32
name|padding
range|:
literal|31
decl_stmt|;
end_decl_stmt
begin_comment
comment|// feel free to use
end_comment
begin_decl_stmt
unit|};
name|class
name|QGraphicsColorizeEffectPrivate
range|:
name|public
name|QGraphicsEffectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsColorizeEffect
argument_list|)
name|public
operator|:
name|QGraphicsColorizeEffectPrivate
argument_list|()
operator|:
name|opaque
argument_list|(
argument|true
argument_list|)
block|{
name|filter
operator|=
name|new
name|QPixmapColorizeFilter
block|;     }
operator|~
name|QGraphicsColorizeEffectPrivate
argument_list|()
block|{
name|delete
name|filter
block|; }
name|QPixmapColorizeFilter
operator|*
name|filter
block|;
name|quint32
name|opaque
operator|:
literal|1
block|;
name|quint32
name|padding
operator|:
literal|31
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGraphicsBlurEffectPrivate
range|:
name|public
name|QGraphicsEffectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsBlurEffect
argument_list|)
name|public
operator|:
name|QGraphicsBlurEffectPrivate
argument_list|()
operator|:
name|filter
argument_list|(
argument|new QPixmapBlurFilter
argument_list|)
block|{}
operator|~
name|QGraphicsBlurEffectPrivate
argument_list|()
block|{
name|delete
name|filter
block|; }
name|QPixmapBlurFilter
operator|*
name|filter
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGraphicsDropShadowEffectPrivate
range|:
name|public
name|QGraphicsEffectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsDropShadowEffect
argument_list|)
name|public
operator|:
name|QGraphicsDropShadowEffectPrivate
argument_list|()
operator|:
name|filter
argument_list|(
argument|new QPixmapDropShadowFilter
argument_list|)
block|{}
operator|~
name|QGraphicsDropShadowEffectPrivate
argument_list|()
block|{
name|delete
name|filter
block|; }
name|QPixmapDropShadowFilter
operator|*
name|filter
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGraphicsOpacityEffectPrivate
range|:
name|public
name|QGraphicsEffectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsOpacityEffect
argument_list|)
name|public
operator|:
name|QGraphicsOpacityEffectPrivate
argument_list|()
operator|:
name|opacity
argument_list|(
name|qreal
argument_list|(
literal|0.7
argument_list|)
argument_list|)
block|,
name|isFullyTransparent
argument_list|(
literal|0
argument_list|)
block|,
name|isFullyOpaque
argument_list|(
literal|0
argument_list|)
block|,
name|hasOpacityMask
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|QGraphicsOpacityEffectPrivate
argument_list|()
block|{}
name|qreal
name|opacity
block|;
name|QBrush
name|opacityMask
block|;
name|uint
name|isFullyTransparent
operator|:
literal|1
block|;
name|uint
name|isFullyOpaque
operator|:
literal|1
block|;
name|uint
name|hasOpacityMask
operator|:
literal|1
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
comment|//QT_NO_GRAPHICSEFFECT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGRAPHICSEFFECT_P_H
end_comment
end_unit
