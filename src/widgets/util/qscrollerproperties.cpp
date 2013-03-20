begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<QLibrary>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qscrollerproperties.h"
end_include
begin_include
include|#
directive|include
file|"private/qscrollerproperties_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|userDefaults
specifier|static
name|QScrollerPropertiesPrivate
modifier|*
name|userDefaults
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|systemDefaults
specifier|static
name|QScrollerPropertiesPrivate
modifier|*
name|systemDefaults
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|defaults
name|QScrollerPropertiesPrivate
modifier|*
name|QScrollerPropertiesPrivate
operator|::
name|defaults
parameter_list|()
block|{
if|if
condition|(
operator|!
name|systemDefaults
condition|)
block|{
name|QScrollerPropertiesPrivate
name|spp
decl_stmt|;
name|spp
operator|.
name|mousePressEventDelay
operator|=
name|qreal
argument_list|(
literal|0.25
argument_list|)
expr_stmt|;
name|spp
operator|.
name|dragStartDistance
operator|=
name|qreal
argument_list|(
literal|5.0
operator|/
literal|1000
argument_list|)
expr_stmt|;
name|spp
operator|.
name|dragVelocitySmoothingFactor
operator|=
name|qreal
argument_list|(
literal|0.8
argument_list|)
expr_stmt|;
name|spp
operator|.
name|axisLockThreshold
operator|=
name|qreal
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|spp
operator|.
name|scrollingCurve
operator|.
name|setType
argument_list|(
name|QEasingCurve
operator|::
name|OutQuad
argument_list|)
expr_stmt|;
name|spp
operator|.
name|decelerationFactor
operator|=
name|qreal
argument_list|(
literal|0.125
argument_list|)
expr_stmt|;
name|spp
operator|.
name|minimumVelocity
operator|=
name|qreal
argument_list|(
literal|50.0
operator|/
literal|1000
argument_list|)
expr_stmt|;
name|spp
operator|.
name|maximumVelocity
operator|=
name|qreal
argument_list|(
literal|500.0
operator|/
literal|1000
argument_list|)
expr_stmt|;
name|spp
operator|.
name|maximumClickThroughVelocity
operator|=
name|qreal
argument_list|(
literal|66.5
operator|/
literal|1000
argument_list|)
expr_stmt|;
name|spp
operator|.
name|acceleratingFlickMaximumTime
operator|=
name|qreal
argument_list|(
literal|1.25
argument_list|)
expr_stmt|;
name|spp
operator|.
name|acceleratingFlickSpeedupFactor
operator|=
name|qreal
argument_list|(
literal|3.0
argument_list|)
expr_stmt|;
name|spp
operator|.
name|snapPositionRatio
operator|=
name|qreal
argument_list|(
literal|0.5
argument_list|)
expr_stmt|;
name|spp
operator|.
name|snapTime
operator|=
name|qreal
argument_list|(
literal|0.3
argument_list|)
expr_stmt|;
name|spp
operator|.
name|overshootDragResistanceFactor
operator|=
name|qreal
argument_list|(
literal|0.5
argument_list|)
expr_stmt|;
name|spp
operator|.
name|overshootDragDistanceFactor
operator|=
name|qreal
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|spp
operator|.
name|overshootScrollDistanceFactor
operator|=
name|qreal
argument_list|(
literal|0.5
argument_list|)
expr_stmt|;
name|spp
operator|.
name|overshootScrollTime
operator|=
name|qreal
argument_list|(
literal|0.7
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_WIN
if|if
condition|(
name|QLibrary
operator|::
name|resolve
argument_list|(
name|QLatin1String
argument_list|(
literal|"UxTheme"
argument_list|)
argument_list|,
literal|"BeginPanningFeedback"
argument_list|)
condition|)
name|spp
operator|.
name|overshootScrollTime
operator|=
name|qreal
argument_list|(
literal|0.35
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|spp
operator|.
name|hOvershootPolicy
operator|=
name|QScrollerProperties
operator|::
name|OvershootWhenScrollable
expr_stmt|;
name|spp
operator|.
name|vOvershootPolicy
operator|=
name|QScrollerProperties
operator|::
name|OvershootWhenScrollable
expr_stmt|;
name|spp
operator|.
name|frameRate
operator|=
name|QScrollerProperties
operator|::
name|Standard
expr_stmt|;
name|systemDefaults
operator|=
operator|new
name|QScrollerPropertiesPrivate
argument_list|(
name|spp
argument_list|)
expr_stmt|;
block|}
return|return
operator|new
name|QScrollerPropertiesPrivate
argument_list|(
name|userDefaults
condition|?
operator|*
name|userDefaults
else|:
operator|*
name|systemDefaults
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \class QScrollerProperties     \brief The QScrollerProperties class stores the settings for a QScroller.     \since 4.8      \inmodule QtWidgets      The QScrollerProperties class stores the parameters used by QScroller.      The default settings are platform dependent so that Qt emulates the     platform behaviour for kinetic scrolling.      As a convention the QScrollerProperties are in physical units (meter,     seconds) and are converted by QScroller using the current DPI.      \sa QScroller */
end_comment
begin_comment
comment|/*!     Constructs new scroller properties. */
end_comment
begin_constructor
DECL|function|QScrollerProperties
name|QScrollerProperties
operator|::
name|QScrollerProperties
parameter_list|()
member_init_list|:
name|d
argument_list|(
name|QScrollerPropertiesPrivate
operator|::
name|defaults
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a copy of \a sp. */
end_comment
begin_constructor
DECL|function|QScrollerProperties
name|QScrollerProperties
operator|::
name|QScrollerProperties
parameter_list|(
specifier|const
name|QScrollerProperties
modifier|&
name|sp
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QScrollerPropertiesPrivate
argument_list|(
operator|*
name|sp
operator|.
name|d
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Assigns \a sp to these scroller properties and returns a reference to these scroller properties. */
end_comment
begin_function
DECL|function|operator =
name|QScrollerProperties
modifier|&
name|QScrollerProperties
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QScrollerProperties
modifier|&
name|sp
parameter_list|)
block|{
operator|*
name|d
operator|.
name|data
argument_list|()
operator|=
operator|*
name|sp
operator|.
name|d
operator|.
name|data
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Destroys the scroller properties. */
end_comment
begin_destructor
DECL|function|~QScrollerProperties
name|QScrollerProperties
operator|::
name|~
name|QScrollerProperties
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns true if these scroller properties are equal to \a sp; otherwise returns false. */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QScrollerProperties
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QScrollerProperties
modifier|&
name|sp
parameter_list|)
specifier|const
block|{
return|return
operator|*
name|d
operator|.
name|data
argument_list|()
operator|==
operator|*
name|sp
operator|.
name|d
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if these scroller properties are different from \a sp; otherwise returns false. */
end_comment
begin_function
DECL|function|operator !=
name|bool
name|QScrollerProperties
operator|::
name|operator
name|!=
parameter_list|(
specifier|const
name|QScrollerProperties
modifier|&
name|sp
parameter_list|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|d
operator|.
name|data
argument_list|()
operator|==
operator|*
name|sp
operator|.
name|d
operator|.
name|data
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|operator ==
name|bool
name|QScrollerPropertiesPrivate
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QScrollerPropertiesPrivate
modifier|&
name|p
parameter_list|)
specifier|const
block|{
name|bool
name|same
init|=
literal|true
decl_stmt|;
name|same
operator|&=
operator|(
name|mousePressEventDelay
operator|==
name|p
operator|.
name|mousePressEventDelay
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|dragStartDistance
operator|==
name|p
operator|.
name|dragStartDistance
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|dragVelocitySmoothingFactor
operator|==
name|p
operator|.
name|dragVelocitySmoothingFactor
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|axisLockThreshold
operator|==
name|p
operator|.
name|axisLockThreshold
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|scrollingCurve
operator|==
name|p
operator|.
name|scrollingCurve
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|decelerationFactor
operator|==
name|p
operator|.
name|decelerationFactor
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|minimumVelocity
operator|==
name|p
operator|.
name|minimumVelocity
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|maximumVelocity
operator|==
name|p
operator|.
name|maximumVelocity
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|maximumClickThroughVelocity
operator|==
name|p
operator|.
name|maximumClickThroughVelocity
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|acceleratingFlickMaximumTime
operator|==
name|p
operator|.
name|acceleratingFlickMaximumTime
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|acceleratingFlickSpeedupFactor
operator|==
name|p
operator|.
name|acceleratingFlickSpeedupFactor
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|snapPositionRatio
operator|==
name|p
operator|.
name|snapPositionRatio
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|snapTime
operator|==
name|p
operator|.
name|snapTime
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|overshootDragResistanceFactor
operator|==
name|p
operator|.
name|overshootDragResistanceFactor
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|overshootDragDistanceFactor
operator|==
name|p
operator|.
name|overshootDragDistanceFactor
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|overshootScrollDistanceFactor
operator|==
name|p
operator|.
name|overshootScrollDistanceFactor
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|overshootScrollTime
operator|==
name|p
operator|.
name|overshootScrollTime
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|hOvershootPolicy
operator|==
name|p
operator|.
name|hOvershootPolicy
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|vOvershootPolicy
operator|==
name|p
operator|.
name|vOvershootPolicy
operator|)
expr_stmt|;
name|same
operator|&=
operator|(
name|frameRate
operator|==
name|p
operator|.
name|frameRate
operator|)
expr_stmt|;
return|return
name|same
return|;
block|}
end_function
begin_comment
comment|/*!      Sets the scroller properties for all new QScrollerProperties objects to \a sp.       Use this function to override the platform default properties returned by the default      constructor. If you only want to change the scroller properties of a single scroller, use      QScroller::setScrollerProperties()       \note Calling this function will not change the content of already existing      QScrollerProperties objects.       \sa unsetDefaultScrollerProperties() */
end_comment
begin_function
DECL|function|setDefaultScrollerProperties
name|void
name|QScrollerProperties
operator|::
name|setDefaultScrollerProperties
parameter_list|(
specifier|const
name|QScrollerProperties
modifier|&
name|sp
parameter_list|)
block|{
if|if
condition|(
operator|!
name|userDefaults
condition|)
name|userDefaults
operator|=
operator|new
name|QScrollerPropertiesPrivate
argument_list|(
operator|*
name|sp
operator|.
name|d
argument_list|)
expr_stmt|;
else|else
operator|*
name|userDefaults
operator|=
operator|*
name|sp
operator|.
name|d
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!      Sets the scroller properties returned by the default constructor back to the platform default      properties.       \sa setDefaultScrollerProperties() */
end_comment
begin_function
DECL|function|unsetDefaultScrollerProperties
name|void
name|QScrollerProperties
operator|::
name|unsetDefaultScrollerProperties
parameter_list|()
block|{
operator|delete
name|userDefaults
expr_stmt|;
name|userDefaults
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Query the \a metric value of the scroller properties.      \sa setScrollMetric(), ScrollMetric */
end_comment
begin_function
DECL|function|scrollMetric
name|QVariant
name|QScrollerProperties
operator|::
name|scrollMetric
parameter_list|(
name|ScrollMetric
name|metric
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|MousePressEventDelay
case|:
return|return
name|d
operator|->
name|mousePressEventDelay
return|;
case|case
name|DragStartDistance
case|:
return|return
name|d
operator|->
name|dragStartDistance
return|;
case|case
name|DragVelocitySmoothingFactor
case|:
return|return
name|d
operator|->
name|dragVelocitySmoothingFactor
return|;
case|case
name|AxisLockThreshold
case|:
return|return
name|d
operator|->
name|axisLockThreshold
return|;
case|case
name|ScrollingCurve
case|:
return|return
name|d
operator|->
name|scrollingCurve
return|;
case|case
name|DecelerationFactor
case|:
return|return
name|d
operator|->
name|decelerationFactor
return|;
case|case
name|MinimumVelocity
case|:
return|return
name|d
operator|->
name|minimumVelocity
return|;
case|case
name|MaximumVelocity
case|:
return|return
name|d
operator|->
name|maximumVelocity
return|;
case|case
name|MaximumClickThroughVelocity
case|:
return|return
name|d
operator|->
name|maximumClickThroughVelocity
return|;
case|case
name|AcceleratingFlickMaximumTime
case|:
return|return
name|d
operator|->
name|acceleratingFlickMaximumTime
return|;
case|case
name|AcceleratingFlickSpeedupFactor
case|:
return|return
name|d
operator|->
name|acceleratingFlickSpeedupFactor
return|;
case|case
name|SnapPositionRatio
case|:
return|return
name|d
operator|->
name|snapPositionRatio
return|;
case|case
name|SnapTime
case|:
return|return
name|d
operator|->
name|snapTime
return|;
case|case
name|OvershootDragResistanceFactor
case|:
return|return
name|d
operator|->
name|overshootDragResistanceFactor
return|;
case|case
name|OvershootDragDistanceFactor
case|:
return|return
name|d
operator|->
name|overshootDragDistanceFactor
return|;
case|case
name|OvershootScrollDistanceFactor
case|:
return|return
name|d
operator|->
name|overshootScrollDistanceFactor
return|;
case|case
name|OvershootScrollTime
case|:
return|return
name|d
operator|->
name|overshootScrollTime
return|;
case|case
name|HorizontalOvershootPolicy
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|d
operator|->
name|hOvershootPolicy
argument_list|)
return|;
case|case
name|VerticalOvershootPolicy
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|d
operator|->
name|vOvershootPolicy
argument_list|)
return|;
case|case
name|FrameRate
case|:
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|d
operator|->
name|frameRate
argument_list|)
return|;
case|case
name|ScrollMetricCount
case|:
break|break;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Set a specific value of the \a metric ScrollerMetric to \a value.      \sa scrollMetric(), ScrollMetric */
end_comment
begin_function
DECL|function|setScrollMetric
name|void
name|QScrollerProperties
operator|::
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
block|{
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|MousePressEventDelay
case|:
name|d
operator|->
name|mousePressEventDelay
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|DragStartDistance
case|:
name|d
operator|->
name|dragStartDistance
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|DragVelocitySmoothingFactor
case|:
name|d
operator|->
name|dragVelocitySmoothingFactor
operator|=
name|qBound
argument_list|(
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|,
name|value
operator|.
name|toReal
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|AxisLockThreshold
case|:
name|d
operator|->
name|axisLockThreshold
operator|=
name|qBound
argument_list|(
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|,
name|value
operator|.
name|toReal
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|ScrollingCurve
case|:
name|d
operator|->
name|scrollingCurve
operator|=
name|value
operator|.
name|toEasingCurve
argument_list|()
expr_stmt|;
break|break;
case|case
name|DecelerationFactor
case|:
name|d
operator|->
name|decelerationFactor
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|MinimumVelocity
case|:
name|d
operator|->
name|minimumVelocity
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|MaximumVelocity
case|:
name|d
operator|->
name|maximumVelocity
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|MaximumClickThroughVelocity
case|:
name|d
operator|->
name|maximumClickThroughVelocity
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|AcceleratingFlickMaximumTime
case|:
name|d
operator|->
name|acceleratingFlickMaximumTime
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|AcceleratingFlickSpeedupFactor
case|:
name|d
operator|->
name|acceleratingFlickSpeedupFactor
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|SnapPositionRatio
case|:
name|d
operator|->
name|snapPositionRatio
operator|=
name|qBound
argument_list|(
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|,
name|value
operator|.
name|toReal
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|SnapTime
case|:
name|d
operator|->
name|snapTime
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|OvershootDragResistanceFactor
case|:
name|d
operator|->
name|overshootDragResistanceFactor
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|OvershootDragDistanceFactor
case|:
name|d
operator|->
name|overshootDragDistanceFactor
operator|=
name|qBound
argument_list|(
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|,
name|value
operator|.
name|toReal
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|OvershootScrollDistanceFactor
case|:
name|d
operator|->
name|overshootScrollDistanceFactor
operator|=
name|qBound
argument_list|(
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|,
name|value
operator|.
name|toReal
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|OvershootScrollTime
case|:
name|d
operator|->
name|overshootScrollTime
operator|=
name|value
operator|.
name|toReal
argument_list|()
expr_stmt|;
break|break;
case|case
name|HorizontalOvershootPolicy
case|:
name|d
operator|->
name|hOvershootPolicy
operator|=
name|value
operator|.
name|value
argument_list|<
name|QScrollerProperties
operator|::
name|OvershootPolicy
argument_list|>
argument_list|()
expr_stmt|;
break|break;
case|case
name|VerticalOvershootPolicy
case|:
name|d
operator|->
name|vOvershootPolicy
operator|=
name|value
operator|.
name|value
argument_list|<
name|QScrollerProperties
operator|::
name|OvershootPolicy
argument_list|>
argument_list|()
expr_stmt|;
break|break;
case|case
name|FrameRate
case|:
name|d
operator|->
name|frameRate
operator|=
name|value
operator|.
name|value
argument_list|<
name|QScrollerProperties
operator|::
name|FrameRates
argument_list|>
argument_list|()
expr_stmt|;
break|break;
case|case
name|ScrollMetricCount
case|:
break|break;
block|}
block|}
end_function
begin_comment
comment|/*!     \enum QScrollerProperties::FrameRates      This enum describes the available frame rates used while dragging or scrolling.      \value Fps60 60 frames per second     \value Fps30 30 frames per second     \value Fps20 20 frames per second     \value Standard the default value is 60 frames per second (which corresponds to QAbstractAnimation). */
end_comment
begin_comment
comment|/*!     \enum QScrollerProperties::OvershootPolicy      This enum describes the various modes of overshooting.      \value OvershootWhenScrollable Overshooting is possible when the content is scrollable. This is the                                    default.      \value OvershootAlwaysOff Overshooting is never enabled, even when the content is scrollable.      \value OvershootAlwaysOn Overshooting is always enabled, even when the content is not                              scrollable. */
end_comment
begin_comment
comment|/*!     \enum QScrollerProperties::ScrollMetric      This enum contains the different scroll metric types. When not indicated otherwise the     setScrollMetric function expects a QVariant of type qreal.      See the QScroller documentation for further details of the concepts behind the different     values.      \value MousePressEventDelay This is the time a mouse press event is delayed when starting     a flick gesture in \c{[s]}. If the gesture is triggered within that time, no mouse press or     release is sent to the scrolled object. If it triggers after that delay the delayed     mouse press plus a faked release event at global position \c{QPoint(-QWIDGETSIZE_MAX,     -QWIDGETSIZE_MAX)} is sent. If the gesture is canceled, then both the delayed mouse     press plus the real release event are delivered.      \value DragStartDistance This is the minimum distance the touch or mouse point needs to be     moved before the flick gesture is triggered in \c m.      \value DragVelocitySmoothingFactor A value that describes to which extent new drag velocities are     included in the final scrolling velocity.  This value should be in the range between \c 0 and     \c 1.  The lower the value, the more smoothing is applied to the dragging velocity.      \value AxisLockThreshold Restricts the movement to one axis if the movement is inside an angle     around the axis. The threshold must be in the range \c 0 to \c 1.      \value ScrollingCurve The QEasingCurve used when decelerating the scrolling velocity after an     user initiated flick. Please note that this is the easing curve for the positions, \b{not}     the velocity: the default is QEasingCurve::OutQuad, which results in a linear decrease in     velocity (1st derivative) and a constant deceleration (2nd derivative).      \value DecelerationFactor This factor influences how long it takes the scroller to decelerate     to 0 velocity. The actual value depends on the chosen ScrollingCurve. For most     types the value should be in the range from \c 0.1 to \c 2.0      \value MinimumVelocity The minimum velocity that is needed after ending the touch or releasing     the mouse to start scrolling in \c{m/s}.      \value MaximumVelocity This is the maximum velocity that can be reached in \c{m/s}.      \value MaximumClickThroughVelocity This is the maximum allowed scroll speed for a click-through     in \c{m/s}. This means that a click on a currently (slowly) scrolling object will not only stop     the scrolling but the click event will also be delivered to the UI control. This is     useful when using exponential-type scrolling curves.      \value AcceleratingFlickMaximumTime This is the maximum time in \c seconds that a flick gesture     can take to be recognized as an accelerating flick. If set to zero no such gesture is     detected. An "accelerating flick" is a flick gesture executed on an already scrolling object.     In such cases the scrolling speed is multiplied by AcceleratingFlickSpeedupFactor in order to     accelerate it.      \value AcceleratingFlickSpeedupFactor The current speed is multiplied by this number if an     accelerating flick is detected. Should be \c{>= 1}.      \value SnapPositionRatio This is the distance that the user must drag the area beween two snap     points in order to snap it to the next position. \c{0.33} means that the scroll must only     reach one third of the distance between two snap points to snap to the next one. The ratio must     be between \c 0 and \c 1.      \value SnapTime This is the time factor for the scrolling curve. A lower value means that the     scrolling will take longer. The scrolling distance is independet of this value.      \value OvershootDragResistanceFactor This value is the factor between the mouse dragging and     the actual scroll area movement (during overshoot). The factor must be between \c 0 and \c 1.      \value OvershootDragDistanceFactor This is the maximum distance for overshoot movements while     dragging. The actual overshoot distance is calculated by multiplying this value with the     viewport size of the scrolled object. The factor must be between \c 0 and \c 1.      \value OvershootScrollDistanceFactor This is the maximum distance for overshoot movements while     scrolling. The actual overshoot distance is calculated by multiplying this value with the     viewport size of the scrolled object. The factor must be between \c 0 and \c 1.      \value OvershootScrollTime This is the time in \c seconds that is used to play the     complete overshoot animation.      \value HorizontalOvershootPolicy This is the horizontal overshooting policy (see OvershootPolicy).      \value VerticalOvershootPolicy This is the horizontal overshooting policy (see OvershootPolicy).      \value FrameRate This is the frame rate which should be used while dragging or scrolling.     QScroller uses a QAbstractAnimation timer internally to sync all scrolling operations to other     animations that might be active at the same time.  If the standard value of 60 frames per     second is too fast, it can be lowered with this setting,     while still being in-sync with QAbstractAnimation. Please note that only the values of the     FrameRates enum are allowed here.      \value ScrollMetricCount This is always the last entry. */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
