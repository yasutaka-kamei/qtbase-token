begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|UTILS_H
end_ifndef
begin_define
DECL|macro|UTILS_H
define|#
directive|define
name|UTILS_H
end_define
begin_include
include|#
directive|include
file|<QComboBox>
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_include
include|#
directive|include
file|<QPair>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QCheckBox
argument_list|)
end_macro
begin_comment
comment|// Associate enum/flag value with a description.
end_comment
begin_struct
struct|struct
name|FlagData
block|{
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|// Helpers for creating combo boxes representing enumeration values from flag data.
end_comment
begin_function_decl
name|QComboBox
modifier|*
name|createCombo
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|FlagData
modifier|*
name|d
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|class
name|Enum
operator|>
DECL|function|comboBoxValue
name|Enum
name|comboBoxValue
argument_list|(
argument|const QComboBox *c
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|Enum
operator|>
operator|(
name|c
operator|->
name|itemData
argument_list|(
name|c
operator|->
name|currentIndex
argument_list|()
argument_list|)
operator|.
name|toInt
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_function_decl
name|void
name|setComboBoxValue
parameter_list|(
name|QComboBox
modifier|*
name|c
parameter_list|,
name|int
name|v
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// A group box with check boxes for option flags.
end_comment
begin_decl_stmt
name|class
name|OptionsControl
range|:
name|public
name|QGroupBox
block|{
name|public
operator|:
name|explicit
name|OptionsControl
argument_list|(
argument|const QString&title
argument_list|,
argument|const FlagData *data
argument_list|,
argument|size_t count
argument_list|,
argument|QWidget *parent
argument_list|)
block|;
name|void
name|setValue
argument_list|(
argument|int flags
argument_list|)
block|;
name|template
operator|<
name|class
name|Enum
operator|>
name|Enum
name|value
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Enum
operator|>
operator|(
name|intValue
argument_list|()
operator|)
return|;
block|}
name|private
operator|:
typedef|typedef
name|QPair
operator|<
name|QCheckBox
operator|*
operator|,
name|int
operator|>
name|CheckBoxFlagPair
expr_stmt|;
name|int
name|intValue
argument_list|()
specifier|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|CheckBoxFlagPair
operator|>
name|m_checkBoxes
expr_stmt|;
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// UTILS_H
end_comment
end_unit