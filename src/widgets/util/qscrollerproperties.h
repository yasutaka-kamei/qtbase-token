begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSCROLLERPROPERTIES_H
end_ifndef
begin_define
DECL|macro|QSCROLLERPROPERTIES_H
define|#
directive|define
name|QSCROLLERPROPERTIES_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaType>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QScroller
name|class
name|QScroller
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollerPrivate
name|class
name|QScrollerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollerPropertiesPrivate
name|class
name|QScrollerPropertiesPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QScrollerProperties
block|{
name|public
label|:
name|QScrollerProperties
argument_list|()
expr_stmt|;
name|QScrollerProperties
argument_list|(
specifier|const
name|QScrollerProperties
operator|&
name|sp
argument_list|)
expr_stmt|;
name|QScrollerProperties
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QScrollerProperties
operator|&
name|sp
operator|)
decl_stmt|;
name|virtual
operator|~
name|QScrollerProperties
argument_list|()
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QScrollerProperties
operator|&
name|sp
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QScrollerProperties
operator|&
name|sp
operator|)
specifier|const
expr_stmt|;
specifier|static
name|void
name|setDefaultScrollerProperties
parameter_list|(
specifier|const
name|QScrollerProperties
modifier|&
name|sp
parameter_list|)
function_decl|;
specifier|static
name|void
name|unsetDefaultScrollerProperties
parameter_list|()
function_decl|;
enum|enum
name|OvershootPolicy
block|{
name|OvershootWhenScrollable
block|,
name|OvershootAlwaysOff
block|,
name|OvershootAlwaysOn
block|}
enum|;
enum|enum
name|FrameRates
block|{
name|Standard
block|,
name|Fps60
block|,
name|Fps30
block|,
name|Fps20
block|}
enum|;
enum|enum
name|ScrollMetric
block|{
name|MousePressEventDelay
block|,
comment|// qreal [s]
name|DragStartDistance
block|,
comment|// qreal [m]
name|DragVelocitySmoothingFactor
block|,
comment|// qreal [0..1/s]  (complex calculation involving time) v = v_new* DASF + v_old * (1-DASF)
name|AxisLockThreshold
block|,
comment|// qreal [0..1] atan(|min(dx,dy)|/|max(dx,dy)|)
name|ScrollingCurve
block|,
comment|// QEasingCurve
name|DecelerationFactor
block|,
comment|// slope of the curve
name|MinimumVelocity
block|,
comment|// qreal [m/s]
name|MaximumVelocity
block|,
comment|// qreal [m/s]
name|MaximumClickThroughVelocity
block|,
comment|// qreal [m/s]
name|AcceleratingFlickMaximumTime
block|,
comment|// qreal [s]
name|AcceleratingFlickSpeedupFactor
block|,
comment|// qreal [1..]
name|SnapPositionRatio
block|,
comment|// qreal [0..1]
name|SnapTime
block|,
comment|// qreal [s]
name|OvershootDragResistanceFactor
block|,
comment|// qreal [0..1]
name|OvershootDragDistanceFactor
block|,
comment|// qreal [0..1]
name|OvershootScrollDistanceFactor
block|,
comment|// qreal [0..1]
name|OvershootScrollTime
block|,
comment|// qreal [s]
name|HorizontalOvershootPolicy
block|,
comment|// enum OvershootPolicy
name|VerticalOvershootPolicy
block|,
comment|// enum OvershootPolicy
name|FrameRate
block|,
comment|// enum FrameRates
name|ScrollMetricCount
block|}
enum|;
name|QVariant
name|scrollMetric
argument_list|(
name|ScrollMetric
name|metric
argument_list|)
decl|const
decl_stmt|;
name|void
name|setScrollMetric
parameter_list|(
name|ScrollMetric
name|metric
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|protected
label|:
name|QScopedPointer
operator|<
name|QScrollerPropertiesPrivate
operator|>
name|d
expr_stmt|;
name|private
label|:
name|QScrollerProperties
argument_list|(
name|QScrollerPropertiesPrivate
operator|&
name|dd
argument_list|)
expr_stmt|;
name|friend
name|class
name|QScrollerPropertiesPrivate
decl_stmt|;
name|friend
name|class
name|QScroller
decl_stmt|;
name|friend
name|class
name|QScrollerPrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QScrollerProperties
operator|::
name|OvershootPolicy
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QScrollerProperties
operator|::
name|FrameRates
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSCROLLERPROPERTIES_H
end_comment
end_unit
