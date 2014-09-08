begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTSPINBOX_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTSPINBOX_P_H
define|#
directive|define
name|QABSTRACTSPINBOX_P_H
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
file|"QtWidgets/qabstractspinbox.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
end_ifndef
begin_include
include|#
directive|include
file|"QtWidgets/qlineedit.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qvalidator.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvariant.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qdatetime_p.h"
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|QVariant
name|operator
operator|+
operator|(
specifier|const
name|QVariant
operator|&
name|arg1
operator|,
specifier|const
name|QVariant
operator|&
name|arg2
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QVariant
name|operator
operator|-
operator|(
specifier|const
name|QVariant
operator|&
name|arg1
operator|,
specifier|const
name|QVariant
operator|&
name|arg2
operator|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QVariant
name|operator
modifier|*
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|arg1
parameter_list|,
name|double
name|multiplier
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|double
name|operator
operator|/
operator|(
specifier|const
name|QVariant
operator|&
name|arg1
operator|,
specifier|const
name|QVariant
operator|&
name|arg2
operator|)
expr_stmt|;
end_expr_stmt
begin_enum
DECL|enum|EmitPolicy
enum|enum
name|EmitPolicy
block|{
DECL|enumerator|EmitIfChanged
name|EmitIfChanged
block|,
DECL|enumerator|AlwaysEmit
name|AlwaysEmit
block|,
DECL|enumerator|NeverEmit
name|NeverEmit
block|}
enum|;
end_enum
begin_enum
DECL|enum|Button
enum|enum
name|Button
block|{
DECL|enumerator|None
name|None
init|=
literal|0x000
block|,
DECL|enumerator|Keyboard
name|Keyboard
init|=
literal|0x001
block|,
DECL|enumerator|Mouse
name|Mouse
init|=
literal|0x002
block|,
DECL|enumerator|Wheel
name|Wheel
init|=
literal|0x004
block|,
DECL|enumerator|ButtonMask
name|ButtonMask
init|=
literal|0x008
block|,
DECL|enumerator|Up
name|Up
init|=
literal|0x010
block|,
DECL|enumerator|Down
name|Down
init|=
literal|0x020
block|,
DECL|enumerator|DirectionMask
name|DirectionMask
init|=
literal|0x040
block|}
enum|;
end_enum
begin_decl_stmt
DECL|variable|QSpinBoxValidator
name|class
name|QSpinBoxValidator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAbstractSpinBoxPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractSpinBox
argument_list|)
name|public
operator|:
name|QAbstractSpinBoxPrivate
argument_list|()
block|;
operator|~
name|QAbstractSpinBoxPrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|reset
argument_list|()
block|;
name|void
name|updateState
argument_list|(
argument|bool up
argument_list|,
argument|bool fromKeyboard = false
argument_list|)
block|;
name|QString
name|stripped
argument_list|(
argument|const QString&text
argument_list|,
argument|int *pos =
literal|0
argument_list|)
specifier|const
block|;
name|bool
name|specialValue
argument_list|()
specifier|const
block|;
name|virtual
name|QVariant
name|getZeroVariant
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setRange
argument_list|(
specifier|const
name|QVariant
operator|&
name|min
argument_list|,
specifier|const
name|QVariant
operator|&
name|max
argument_list|)
block|;
name|void
name|setValue
argument_list|(
argument|const QVariant&val
argument_list|,
argument|EmitPolicy ep
argument_list|,
argument|bool updateEdit = true
argument_list|)
block|;
name|virtual
name|QVariant
name|bound
argument_list|(
argument|const QVariant&val
argument_list|,
argument|const QVariant&old = QVariant()
argument_list|,
argument|int steps =
literal|0
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|updateEdit
argument_list|()
block|;
name|virtual
name|void
name|emitSignals
argument_list|(
argument|EmitPolicy ep
argument_list|,
argument|const QVariant&old
argument_list|)
block|;
name|virtual
name|void
name|interpret
argument_list|(
argument|EmitPolicy ep
argument_list|)
block|;
name|virtual
name|QString
name|textFromValue
argument_list|(
argument|const QVariant&n
argument_list|)
specifier|const
block|;
name|virtual
name|QVariant
name|valueFromText
argument_list|(
argument|const QString&input
argument_list|)
specifier|const
block|;
name|void
name|_q_editorTextChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|_q_editorCursorPositionChanged
argument_list|(
argument|int oldpos
argument_list|,
argument|int newpos
argument_list|)
block|;
name|virtual
name|QStyle
operator|::
name|SubControl
name|newHoverControl
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|bool
name|updateHoverControl
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|virtual
name|void
name|clearCache
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|updateEditFieldGeometry
argument_list|()
block|;
specifier|static
name|int
name|variantCompare
argument_list|(
specifier|const
name|QVariant
operator|&
name|arg1
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg2
argument_list|)
block|;
specifier|static
name|QVariant
name|variantBound
argument_list|(
specifier|const
name|QVariant
operator|&
name|min
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|,
specifier|const
name|QVariant
operator|&
name|max
argument_list|)
block|;
name|QLineEdit
operator|*
name|edit
block|;
name|QString
name|prefix
block|,
name|suffix
block|,
name|specialValueText
block|;
name|QVariant
name|value
block|,
name|minimum
block|,
name|maximum
block|,
name|singleStep
block|;
name|QVariant
operator|::
name|Type
name|type
block|;
name|int
name|spinClickTimerId
block|,
name|spinClickTimerInterval
block|,
name|spinClickThresholdTimerId
block|,
name|spinClickThresholdTimerInterval
block|;
name|int
name|effectiveSpinRepeatRate
block|;
name|uint
name|buttonState
block|;
name|mutable
name|QString
name|cachedText
block|;
name|mutable
name|QVariant
name|cachedValue
block|;
name|mutable
name|QValidator
operator|::
name|State
name|cachedState
block|;
name|mutable
name|QSize
name|cachedSizeHint
block|,
name|cachedMinimumSizeHint
block|;
name|uint
name|pendingEmit
operator|:
literal|1
block|;
name|uint
name|readOnly
operator|:
literal|1
block|;
name|uint
name|wrapping
operator|:
literal|1
block|;
name|uint
name|ignoreCursorPositionChanged
operator|:
literal|1
block|;
name|uint
name|frame
operator|:
literal|1
block|;
name|uint
name|accelerate
operator|:
literal|1
block|;
name|uint
name|keyboardTracking
operator|:
literal|1
block|;
name|uint
name|cleared
operator|:
literal|1
block|;
name|uint
name|ignoreUpdateEdit
operator|:
literal|1
block|;
name|QAbstractSpinBox
operator|::
name|CorrectionMode
name|correctionMode
block|;
name|int
name|acceleration
block|;
name|QStyle
operator|::
name|SubControl
name|hoverControl
block|;
name|QRect
name|hoverRect
block|;
name|QAbstractSpinBox
operator|::
name|ButtonSymbols
name|buttonSymbols
block|;
name|QSpinBoxValidator
operator|*
name|validator
block|;
name|uint
name|showGroupSeparator
operator|:
literal|1
block|;
name|int
name|wheelDeltaRemainder
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSpinBoxValidator
range|:
name|public
name|QValidator
block|{
name|public
operator|:
name|QSpinBoxValidator
argument_list|(
name|QAbstractSpinBox
operator|*
name|qptr
argument_list|,
name|QAbstractSpinBoxPrivate
operator|*
name|dptr
argument_list|)
block|;
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString&input
argument_list|,
argument|int&
argument_list|)
specifier|const
block|;
name|void
name|fixup
argument_list|(
argument|QString&
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QAbstractSpinBox
operator|*
name|qptr
block|;
name|QAbstractSpinBoxPrivate
operator|*
name|dptr
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
comment|// QT_NO_SPINBOX
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTSPINBOX_P_H
end_comment
end_unit
