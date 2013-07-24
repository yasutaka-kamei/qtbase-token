begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|RANGECONTROLS_H
end_ifndef
begin_define
DECL|macro|RANGECONTROLS_H
define|#
directive|define
name|RANGECONTROLS_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qaccessiblewidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
DECL|variable|QAbstractSpinBox
name|class
name|QAbstractSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractSlider
name|class
name|QAbstractSlider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScrollBar
name|class
name|QScrollBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSlider
name|class
name|QSlider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSpinBox
name|class
name|QSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDoubleSpinBox
name|class
name|QDoubleSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDial
name|class
name|QDial
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
end_ifndef
begin_decl_stmt
DECL|variable|QAccessibleWidget
name|class
name|QAccessibleAbstractSpinBox
range|:
name|public
name|QAccessibleWidget
decl_stmt|,
name|public
name|QAccessibleValueInterface
comment|// TODO, public QAccessibleActionInterface
block|{
name|public
label|:
name|explicit
name|QAccessibleAbstractSpinBox
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
function_decl|;
name|QString
name|text
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|)
decl|const
decl_stmt|;
name|void
modifier|*
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
argument_list|)
decl_stmt|;
comment|// QAccessibleValueInterface
name|QVariant
name|currentValue
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|QVariant
name|maximumValue
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|minimumValue
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|minimumStepSize
argument_list|()
specifier|const
expr_stmt|;
comment|// FIXME Action interface
name|protected
label|:
name|QAbstractSpinBox
operator|*
name|abstractSpinBox
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QAccessibleSpinBox
range|:
name|public
name|QAccessibleAbstractSpinBox
block|{
name|public
operator|:
name|explicit
name|QAccessibleSpinBox
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|protected
operator|:
name|QSpinBox
operator|*
name|spinBox
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleDoubleSpinBox
range|:
name|public
name|QAccessibleAbstractSpinBox
block|{
name|public
operator|:
name|explicit
name|QAccessibleDoubleSpinBox
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QString
name|text
argument_list|(
argument|QAccessible::Text t
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QDoubleSpinBox
operator|*
name|doubleSpinBox
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SPINBOX
end_comment
begin_decl_stmt
DECL|variable|QAccessibleWidget
name|class
name|QAccessibleAbstractSlider
range|:
name|public
name|QAccessibleWidget
decl_stmt|,
name|public
name|QAccessibleValueInterface
block|{
name|public
label|:
name|explicit
name|QAccessibleAbstractSlider
argument_list|(
name|QWidget
operator|*
name|w
argument_list|,
name|QAccessible
operator|::
name|Role
name|r
operator|=
name|QAccessible
operator|::
name|Slider
argument_list|)
decl_stmt|;
name|void
modifier|*
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
argument_list|)
decl_stmt|;
comment|// QAccessibleValueInterface
name|QVariant
name|currentValue
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|QVariant
name|maximumValue
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|minimumValue
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|minimumStepSize
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|QAbstractSlider
operator|*
name|abstractSlider
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SCROLLBAR
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleScrollBar
range|:
name|public
name|QAccessibleAbstractSlider
block|{
name|public
operator|:
name|explicit
name|QAccessibleScrollBar
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|QString
name|text
argument_list|(
argument|QAccessible::Text t
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QScrollBar
operator|*
name|scrollBar
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SCROLLBAR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SLIDER
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleSlider
range|:
name|public
name|QAccessibleAbstractSlider
block|{
name|public
operator|:
name|explicit
name|QAccessibleSlider
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|QString
name|text
argument_list|(
argument|QAccessible::Text t
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QSlider
operator|*
name|slider
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SLIDER
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DIAL
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleDial
range|:
name|public
name|QAccessibleAbstractSlider
block|{
name|public
operator|:
name|explicit
name|QAccessibleDial
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|QString
name|text
argument_list|(
argument|QAccessible::Text textType
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QDial
operator|*
name|dial
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DIAL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// RANGECONTROLS_H
end_comment
end_unit
