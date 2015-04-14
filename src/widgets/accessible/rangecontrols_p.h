begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_decl_stmt
DECL|variable|QAccessibleLineEdit
name|class
name|QAccessibleLineEdit
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleAbstractSpinBox
range|:
DECL|variable|QAccessibleWidget
name|public
name|QAccessibleWidget
decl_stmt|,
DECL|variable|QAccessibleValueInterface
name|public
name|QAccessibleValueInterface
decl_stmt|,
DECL|variable|QAccessibleTextInterface
name|public
name|QAccessibleTextInterface
decl_stmt|,
name|public
name|QAccessibleEditableTextInterface
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
name|virtual
operator|~
name|QAccessibleAbstractSpinBox
argument_list|()
expr_stmt|;
name|QString
name|text
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
decl_stmt|;
comment|// QAccessibleValueInterface
name|QVariant
name|currentValue
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|setCurrentValue
argument_list|(
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QVariant
name|maximumValue
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QVariant
name|minimumValue
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QVariant
name|minimumStepSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
comment|// QAccessibleTextInterface
name|void
name|addSelection
argument_list|(
name|int
name|startOffset
argument_list|,
name|int
name|endOffset
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QString
name|attributes
argument_list|(
name|int
name|offset
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|int
name|cursorPosition
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QRect
name|characterRect
argument_list|(
name|int
name|offset
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|int
name|selectionCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|int
name|offsetAtPoint
argument_list|(
specifier|const
name|QPoint
operator|&
name|point
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|selection
argument_list|(
name|int
name|selectionIndex
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QString
name|text
argument_list|(
name|int
name|startOffset
argument_list|,
name|int
name|endOffset
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QString
name|textBeforeOffset
argument_list|(
name|int
name|offset
argument_list|,
name|QAccessible
operator|::
name|TextBoundaryType
name|boundaryType
argument_list|,
name|int
operator|*
name|endOffset
argument_list|,
name|int
operator|*
name|startOffset
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QString
name|textAfterOffset
argument_list|(
name|int
name|offset
argument_list|,
name|QAccessible
operator|::
name|TextBoundaryType
name|boundaryType
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QString
name|textAtOffset
argument_list|(
name|int
name|offset
argument_list|,
name|QAccessible
operator|::
name|TextBoundaryType
name|boundaryType
argument_list|,
name|int
operator|*
name|startOffset
argument_list|,
name|int
operator|*
name|endOffset
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|removeSelection
argument_list|(
name|int
name|selectionIndex
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setCursorPosition
argument_list|(
name|int
name|position
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setSelection
argument_list|(
name|int
name|selectionIndex
argument_list|,
name|int
name|startOffset
argument_list|,
name|int
name|endOffset
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|int
name|characterCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|scrollToSubstring
argument_list|(
name|int
name|startIndex
argument_list|,
name|int
name|endIndex
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
comment|// QAccessibleEditableTextInterface
name|void
name|deleteText
argument_list|(
name|int
name|startOffset
argument_list|,
name|int
name|endOffset
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|insertText
argument_list|(
name|int
name|offset
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|replaceText
argument_list|(
name|int
name|startOffset
argument_list|,
name|int
name|endOffset
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|protected
label|:
name|QAbstractSpinBox
operator|*
name|abstractSpinBox
argument_list|()
specifier|const
expr_stmt|;
name|QAccessibleInterface
operator|*
name|lineEditIface
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|mutable
name|QAccessibleLineEdit
modifier|*
name|lineEdit
decl_stmt|;
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
name|Q_DECL_OVERRIDE
block|;
name|using
name|QAccessibleAbstractSpinBox
operator|::
name|text
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
name|Q_DECL_OVERRIDE
decl_stmt|;
comment|// QAccessibleValueInterface
name|QVariant
name|currentValue
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|setCurrentValue
argument_list|(
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QVariant
name|maximumValue
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QVariant
name|minimumValue
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QVariant
name|minimumStepSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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