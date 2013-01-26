begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTSLIDER_H
end_ifndef
begin_define
DECL|macro|QABSTRACTSLIDER_H
define|#
directive|define
name|QABSTRACTSLIDER_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractSliderPrivate
name|class
name|QAbstractSliderPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QAbstractSlider
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int minimum READ minimum WRITE setMinimum
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int maximum READ maximum WRITE setMaximum
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int singleStep READ singleStep WRITE setSingleStep
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int pageStep READ pageStep WRITE setPageStep
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int value READ value WRITE setValue NOTIFY valueChanged USER true
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int sliderPosition READ sliderPosition WRITE setSliderPosition NOTIFY sliderMoved
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tracking READ hasTracking WRITE setTracking
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Orientation orientation READ orientation WRITE setOrientation
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool invertedAppearance READ invertedAppearance WRITE setInvertedAppearance
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool invertedControls READ invertedControls WRITE setInvertedControls
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool sliderDown READ isSliderDown WRITE setSliderDown DESIGNABLE false
argument_list|)
name|public
operator|:
name|explicit
name|QAbstractSlider
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QAbstractSlider
argument_list|()
block|;
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|()
specifier|const
block|;
name|void
name|setMinimum
argument_list|(
name|int
argument_list|)
block|;
name|int
name|minimum
argument_list|()
specifier|const
block|;
name|void
name|setMaximum
argument_list|(
name|int
argument_list|)
block|;
name|int
name|maximum
argument_list|()
specifier|const
block|;
name|void
name|setSingleStep
argument_list|(
name|int
argument_list|)
block|;
name|int
name|singleStep
argument_list|()
specifier|const
block|;
name|void
name|setPageStep
argument_list|(
name|int
argument_list|)
block|;
name|int
name|pageStep
argument_list|()
specifier|const
block|;
name|void
name|setTracking
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|hasTracking
argument_list|()
specifier|const
block|;
name|void
name|setSliderDown
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isSliderDown
argument_list|()
specifier|const
block|;
name|void
name|setSliderPosition
argument_list|(
name|int
argument_list|)
block|;
name|int
name|sliderPosition
argument_list|()
specifier|const
block|;
name|void
name|setInvertedAppearance
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|invertedAppearance
argument_list|()
specifier|const
block|;
name|void
name|setInvertedControls
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|invertedControls
argument_list|()
specifier|const
block|;      enum
name|SliderAction
block|{
name|SliderNoAction
block|,
name|SliderSingleStepAdd
block|,
name|SliderSingleStepSub
block|,
name|SliderPageStepAdd
block|,
name|SliderPageStepSub
block|,
name|SliderToMinimum
block|,
name|SliderToMaximum
block|,
name|SliderMove
block|}
block|;
name|int
name|value
argument_list|()
specifier|const
block|;
name|void
name|triggerAction
argument_list|(
argument|SliderAction action
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setValue
argument_list|(
name|int
argument_list|)
block|;
name|void
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Orientation
argument_list|)
block|;
name|void
name|setRange
argument_list|(
argument|int min
argument_list|,
argument|int max
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|valueChanged
argument_list|(
argument|int value
argument_list|)
block|;
name|void
name|sliderPressed
argument_list|()
block|;
name|void
name|sliderMoved
argument_list|(
argument|int position
argument_list|)
block|;
name|void
name|sliderReleased
argument_list|()
block|;
name|void
name|rangeChanged
argument_list|(
argument|int min
argument_list|,
argument|int max
argument_list|)
block|;
name|void
name|actionTriggered
argument_list|(
argument|int action
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|setRepeatAction
argument_list|(
argument|SliderAction action
argument_list|,
argument|int thresholdTime =
literal|500
argument_list|,
argument|int repeatTime =
literal|50
argument_list|)
block|;
name|SliderAction
name|repeatAction
argument_list|()
specifier|const
block|;      enum
name|SliderChange
block|{
name|SliderRangeChange
block|,
name|SliderOrientationChange
block|,
name|SliderStepsChange
block|,
name|SliderValueChange
block|}
block|;
name|virtual
name|void
name|sliderChange
argument_list|(
argument|SliderChange change
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|ev
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|protected
operator|:
name|QAbstractSlider
argument_list|(
name|QAbstractSliderPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractSlider
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractSlider
argument_list|)
block|}
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
comment|// QABSTRACTSLIDER_H
end_comment
end_unit
