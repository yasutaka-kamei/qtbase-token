begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'paletteeditor.ui' ** ** Created: Fri Sep 4 10:17:14 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PALETTEEDITOR_H
end_ifndef
begin_define
DECL|macro|PALETTEEDITOR_H
define|#
directive|define
name|PALETTEEDITOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QAction>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QApplication>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QButtonGroup>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDialog>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDialogButtonBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QLabel>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QRadioButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTreeView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|"previewframe.h"
end_include
begin_include
include|#
directive|include
file|"qtcolorbutton.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|qdesigner_internal
block|{
name|class
name|Ui_PaletteEditor
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QGroupBox
modifier|*
name|advancedBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QtColorButton
modifier|*
name|buildButton
decl_stmt|;
name|QTreeView
modifier|*
name|paletteView
decl_stmt|;
name|QRadioButton
modifier|*
name|detailsRadio
decl_stmt|;
name|QRadioButton
modifier|*
name|computeRadio
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QGroupBox
modifier|*
name|GroupBox126
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout1
decl_stmt|;
name|QRadioButton
modifier|*
name|disabledRadio
decl_stmt|;
name|QRadioButton
modifier|*
name|inactiveRadio
decl_stmt|;
name|QRadioButton
modifier|*
name|activeRadio
decl_stmt|;
name|qdesigner_internal
operator|::
name|PreviewFrame
operator|*
name|previewFrame
expr_stmt|;
name|QDialogButtonBox
modifier|*
name|buttonBox
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|qdesigner_internal__PaletteEditor
parameter_list|)
block|{
if|if
condition|(
name|qdesigner_internal__PaletteEditor
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|qdesigner_internal__PaletteEditor
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"qdesigner_internal__PaletteEditor"
argument_list|)
argument_list|)
expr_stmt|;
name|qdesigner_internal__PaletteEditor
operator|->
name|resize
argument_list|(
literal|365
argument_list|,
literal|409
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|7
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|7
operator|)
argument_list|)
decl_stmt|;
name|sizePolicy
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|qdesigner_internal__PaletteEditor
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|qdesigner_internal__PaletteEditor
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|qdesigner_internal__PaletteEditor
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|vboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|vboxLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|advancedBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|qdesigner_internal__PaletteEditor
argument_list|)
expr_stmt|;
name|advancedBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"advancedBox"
argument_list|)
argument_list|)
expr_stmt|;
name|advancedBox
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|advancedBox
operator|->
name|setMaximumSize
argument_list|(
name|QSize
argument_list|(
literal|16777215
argument_list|,
literal|16777215
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|advancedBox
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|gridLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|gridLayout
operator|->
name|setContentsMargins
argument_list|(
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|gridLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|buildButton
operator|=
name|new
name|QtColorButton
argument_list|(
name|advancedBox
argument_list|)
expr_stmt|;
name|buildButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"buildButton"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy1
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|7
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|13
operator|)
argument_list|)
decl_stmt|;
name|sizePolicy1
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy1
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy1
operator|.
name|setHeightForWidth
argument_list|(
name|buildButton
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|buildButton
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy1
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|buildButton
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|paletteView
operator|=
name|new
name|QTreeView
argument_list|(
name|advancedBox
argument_list|)
expr_stmt|;
name|paletteView
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"paletteView"
argument_list|)
argument_list|)
expr_stmt|;
name|paletteView
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|0
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|paletteView
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|detailsRadio
operator|=
name|new
name|QRadioButton
argument_list|(
name|advancedBox
argument_list|)
expr_stmt|;
name|detailsRadio
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"detailsRadio"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|detailsRadio
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|computeRadio
operator|=
name|new
name|QRadioButton
argument_list|(
name|advancedBox
argument_list|)
expr_stmt|;
name|computeRadio
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"computeRadio"
argument_list|)
argument_list|)
expr_stmt|;
name|computeRadio
operator|->
name|setChecked
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|computeRadio
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|advancedBox
argument_list|)
expr_stmt|;
name|label
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|advancedBox
argument_list|)
expr_stmt|;
name|GroupBox126
operator|=
name|new
name|QGroupBox
argument_list|(
name|qdesigner_internal__PaletteEditor
argument_list|)
expr_stmt|;
name|GroupBox126
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"GroupBox126"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy2
argument_list|(
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|5
operator|)
argument_list|,
name|static_cast
operator|<
name|QSizePolicy
operator|::
name|Policy
operator|>
operator|(
literal|7
operator|)
argument_list|)
decl_stmt|;
name|sizePolicy2
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy2
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy2
operator|.
name|setHeightForWidth
argument_list|(
name|GroupBox126
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|GroupBox126
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy2
argument_list|)
expr_stmt|;
name|gridLayout1
operator|=
name|new
name|QGridLayout
argument_list|(
name|GroupBox126
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|gridLayout1
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|gridLayout1
operator|->
name|setContentsMargins
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gridLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|disabledRadio
operator|=
name|new
name|QRadioButton
argument_list|(
name|GroupBox126
argument_list|)
expr_stmt|;
name|disabledRadio
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"disabledRadio"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|disabledRadio
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|inactiveRadio
operator|=
name|new
name|QRadioButton
argument_list|(
name|GroupBox126
argument_list|)
expr_stmt|;
name|inactiveRadio
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"inactiveRadio"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|inactiveRadio
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|activeRadio
operator|=
name|new
name|QRadioButton
argument_list|(
name|GroupBox126
argument_list|)
expr_stmt|;
name|activeRadio
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"activeRadio"
argument_list|)
argument_list|)
expr_stmt|;
name|activeRadio
operator|->
name|setChecked
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|activeRadio
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|previewFrame
operator|=
name|new
name|qdesigner_internal
operator|::
name|PreviewFrame
argument_list|(
name|GroupBox126
argument_list|)
expr_stmt|;
name|previewFrame
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"previewFrame"
argument_list|)
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|previewFrame
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|previewFrame
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|previewFrame
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|GroupBox126
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|qdesigner_internal__PaletteEditor
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"buttonBox"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setStandardButtons
argument_list|(
name|QDialogButtonBox
operator|::
name|Cancel
operator||
name|QDialogButtonBox
operator|::
name|NoButton
operator||
name|QDialogButtonBox
operator|::
name|Ok
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|qdesigner_internal__PaletteEditor
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|qdesigner_internal__PaletteEditor
argument_list|,
name|SLOT
argument_list|(
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|qdesigner_internal__PaletteEditor
argument_list|,
name|SLOT
argument_list|(
name|reject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|qdesigner_internal__PaletteEditor
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|qdesigner_internal__PaletteEditor
parameter_list|)
block|{
name|qdesigner_internal__PaletteEditor
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PaletteEditor"
argument_list|,
literal|"Edit Palette"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|advancedBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PaletteEditor"
argument_list|,
literal|"Tune Palette"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|buildButton
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|detailsRadio
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PaletteEditor"
argument_list|,
literal|"Show Details"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|computeRadio
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PaletteEditor"
argument_list|,
literal|"Compute Details"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PaletteEditor"
argument_list|,
literal|"Quick"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|GroupBox126
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PaletteEditor"
argument_list|,
literal|"Preview"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|disabledRadio
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PaletteEditor"
argument_list|,
literal|"Disabled"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|inactiveRadio
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PaletteEditor"
argument_list|,
literal|"Inactive"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|activeRadio
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"qdesigner_internal::PaletteEditor"
argument_list|,
literal|"Active"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// retranslateUi
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace qdesigner_internal
end_comment
begin_decl_stmt
name|namespace
name|qdesigner_internal
block|{
name|namespace
name|Ui
block|{
name|class
name|PaletteEditor
range|:
name|public
name|Ui_PaletteEditor
block|{}
decl_stmt|;
block|}
comment|// namespace Ui
block|}
end_decl_stmt
begin_comment
comment|// namespace qdesigner_internal
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PALETTEEDITOR_H
end_comment
end_unit
