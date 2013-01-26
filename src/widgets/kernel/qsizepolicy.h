begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIZEPOLICY_H
end_ifndef
begin_define
DECL|macro|QSIZEPOLICY_H
define|#
directive|define
name|QSIZEPOLICY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QSizePolicy
block|{
name|Q_GADGET
name|Q_ENUMS
argument_list|(
name|Policy
argument_list|)
name|public
range|:     enum
name|PolicyFlag
block|{
name|GrowFlag
operator|=
literal|1
block|,
name|ExpandFlag
operator|=
literal|2
block|,
name|ShrinkFlag
operator|=
literal|4
block|,
name|IgnoreFlag
operator|=
literal|8
block|}
decl_stmt|;
enum|enum
name|Policy
block|{
name|Fixed
init|=
literal|0
block|,
name|Minimum
init|=
name|GrowFlag
block|,
name|Maximum
init|=
name|ShrinkFlag
block|,
name|Preferred
init|=
name|GrowFlag
operator||
name|ShrinkFlag
block|,
name|MinimumExpanding
init|=
name|GrowFlag
operator||
name|ExpandFlag
block|,
name|Expanding
init|=
name|GrowFlag
operator||
name|ShrinkFlag
operator||
name|ExpandFlag
block|,
name|Ignored
init|=
name|ShrinkFlag
operator||
name|GrowFlag
operator||
name|IgnoreFlag
block|}
enum|;
enum|enum
name|ControlType
block|{
name|DefaultType
init|=
literal|0x00000001
block|,
name|ButtonBox
init|=
literal|0x00000002
block|,
name|CheckBox
init|=
literal|0x00000004
block|,
name|ComboBox
init|=
literal|0x00000008
block|,
name|Frame
init|=
literal|0x00000010
block|,
name|GroupBox
init|=
literal|0x00000020
block|,
name|Label
init|=
literal|0x00000040
block|,
name|Line
init|=
literal|0x00000080
block|,
name|LineEdit
init|=
literal|0x00000100
block|,
name|PushButton
init|=
literal|0x00000200
block|,
name|RadioButton
init|=
literal|0x00000400
block|,
name|Slider
init|=
literal|0x00000800
block|,
name|SpinBox
init|=
literal|0x00001000
block|,
name|TabWidget
init|=
literal|0x00002000
block|,
name|ToolButton
init|=
literal|0x00004000
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ControlTypes
argument_list|,
argument|ControlType
argument_list|)
name|QSizePolicy
argument_list|()
operator|:
name|data
argument_list|(
literal|0
argument_list|)
block|{ }
comment|// ### Qt 5: merge these two constructors (with type == DefaultType)
name|QSizePolicy
argument_list|(
argument|Policy horizontal
argument_list|,
argument|Policy vertical
argument_list|,
argument|ControlType type = DefaultType
argument_list|)
operator|:
name|data
argument_list|(
literal|0
argument_list|)
block|{
name|bits
operator|.
name|horPolicy
operator|=
name|horizontal
block|;
name|bits
operator|.
name|verPolicy
operator|=
name|vertical
block|;
name|setControlType
argument_list|(
name|type
argument_list|)
block|;     }
name|Policy
name|horizontalPolicy
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Policy
operator|>
operator|(
name|bits
operator|.
name|horPolicy
operator|)
return|;
block|}
name|Policy
name|verticalPolicy
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Policy
operator|>
operator|(
name|bits
operator|.
name|verPolicy
operator|)
return|;
block|}
name|ControlType
name|controlType
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setHorizontalPolicy
parameter_list|(
name|Policy
name|d
parameter_list|)
block|{
name|bits
operator|.
name|horPolicy
operator|=
name|d
expr_stmt|;
block|}
name|void
name|setVerticalPolicy
parameter_list|(
name|Policy
name|d
parameter_list|)
block|{
name|bits
operator|.
name|verPolicy
operator|=
name|d
expr_stmt|;
block|}
name|void
name|setControlType
parameter_list|(
name|ControlType
name|type
parameter_list|)
function_decl|;
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
block|{
name|Qt
operator|::
name|Orientations
name|result
block|;
if|if
condition|(
name|verticalPolicy
argument_list|()
operator|&
name|ExpandFlag
condition|)
name|result
operator||=
name|Qt
operator|::
name|Vertical
expr_stmt|;
if|if
condition|(
name|horizontalPolicy
argument_list|()
operator|&
name|ExpandFlag
condition|)
name|result
operator||=
name|Qt
operator|::
name|Horizontal
expr_stmt|;
return|return
name|result
return|;
block|}
end_decl_stmt
begin_function
name|void
name|setHeightForWidth
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|bits
operator|.
name|hfw
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
block|{
return|return
name|bits
operator|.
name|hfw
return|;
block|}
end_expr_stmt
begin_function
name|void
name|setWidthForHeight
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|bits
operator|.
name|wfh
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|hasWidthForHeight
argument_list|()
specifier|const
block|{
return|return
name|bits
operator|.
name|wfh
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSizePolicy
operator|&
name|s
operator|)
specifier|const
block|{
return|return
name|data
operator|==
name|s
operator|.
name|data
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSizePolicy
operator|&
name|s
operator|)
specifier|const
block|{
return|return
name|data
operator|!=
name|s
operator|.
name|data
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// implemented in qlayoutitem.cpp
end_comment
begin_expr_stmt
name|int
name|horizontalStretch
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|bits
operator|.
name|horStretch
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|verticalStretch
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|bits
operator|.
name|verStretch
operator|)
return|;
block|}
end_expr_stmt
begin_function
name|void
name|setHorizontalStretch
parameter_list|(
name|int
name|stretchFactor
parameter_list|)
block|{
name|bits
operator|.
name|horStretch
operator|=
name|static_cast
operator|<
name|quint32
operator|>
operator|(
name|qBound
argument_list|(
literal|0
argument_list|,
name|stretchFactor
argument_list|,
literal|255
argument_list|)
operator|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|setVerticalStretch
parameter_list|(
name|int
name|stretchFactor
parameter_list|)
block|{
name|bits
operator|.
name|verStretch
operator|=
name|static_cast
operator|<
name|quint32
operator|>
operator|(
name|qBound
argument_list|(
literal|0
argument_list|,
name|stretchFactor
argument_list|,
literal|255
argument_list|)
operator|)
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|transpose
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|friend
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QSizePolicy
argument_list|(
argument|int i
argument_list|)
end_macro
begin_macro
unit|:
name|data
argument_list|(
argument|i
argument_list|)
end_macro
begin_block
block|{ }
end_block
begin_union
union|union
block|{
struct|struct
block|{
name|quint32
name|horStretch
range|:
literal|8
decl_stmt|;
name|quint32
name|verStretch
range|:
literal|8
decl_stmt|;
name|quint32
name|horPolicy
range|:
literal|4
decl_stmt|;
name|quint32
name|verPolicy
range|:
literal|4
decl_stmt|;
name|quint32
name|ctype
range|:
literal|5
decl_stmt|;
name|quint32
name|hfw
range|:
literal|1
decl_stmt|;
name|quint32
name|wfh
range|:
literal|1
decl_stmt|;
name|quint32
name|padding
range|:
literal|1
decl_stmt|;
comment|// feel free to use
block|}
name|bits
struct|;
name|quint32
name|data
decl_stmt|;
block|}
union|;
end_union
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QSizePolicy::ControlTypes
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|// implemented in qlayout.cpp
end_comment
begin_expr_stmt
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_WIDGETS_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|dbg
operator|,
specifier|const
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|transpose
specifier|inline
name|void
name|QSizePolicy
operator|::
name|transpose
argument_list|()
block|{
name|Policy
name|hData
operator|=
name|horizontalPolicy
argument_list|()
block|;
name|Policy
name|vData
operator|=
name|verticalPolicy
argument_list|()
block|;
name|int
name|hStretch
operator|=
name|horizontalStretch
argument_list|()
block|;
name|int
name|vStretch
operator|=
name|verticalStretch
argument_list|()
block|;
name|setHorizontalPolicy
argument_list|(
name|vData
argument_list|)
block|;
name|setVerticalPolicy
argument_list|(
name|hData
argument_list|)
block|;
name|setHorizontalStretch
argument_list|(
name|vStretch
argument_list|)
block|;
name|setVerticalStretch
argument_list|(
name|hStretch
argument_list|)
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSIZEPOLICY_H
end_comment
end_unit
