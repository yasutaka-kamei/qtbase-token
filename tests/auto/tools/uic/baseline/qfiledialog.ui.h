begin_unit
begin_comment
comment|/* ********************************************************************* ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the autotests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ********************************************************************* */
end_comment
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'qfiledialog.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILEDIALOG_H
end_ifndef
begin_define
DECL|macro|QFILEDIALOG_H
define|#
directive|define
name|QFILEDIALOG_H
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
file|<QtWidgets/QComboBox>
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
file|<QtWidgets/QFrame>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHBoxLayout>
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
file|<QtWidgets/QSplitter>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QStackedWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QToolButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_include
include|#
directive|include
file|"qfiledialog_p.h"
end_include
begin_include
include|#
directive|include
file|"qsidebar_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_QFileDialog
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QLabel
modifier|*
name|lookInLabel
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QFileDialogComboBox
modifier|*
name|lookInCombo
decl_stmt|;
name|QToolButton
modifier|*
name|backButton
decl_stmt|;
name|QToolButton
modifier|*
name|forwardButton
decl_stmt|;
name|QToolButton
modifier|*
name|toParentButton
decl_stmt|;
name|QToolButton
modifier|*
name|newFolderButton
decl_stmt|;
name|QToolButton
modifier|*
name|listModeButton
decl_stmt|;
name|QToolButton
modifier|*
name|detailModeButton
decl_stmt|;
name|QSplitter
modifier|*
name|splitter
decl_stmt|;
name|QSidebar
modifier|*
name|sidebar
decl_stmt|;
name|QFrame
modifier|*
name|frame
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QStackedWidget
modifier|*
name|stackedWidget
decl_stmt|;
name|QWidget
modifier|*
name|page
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout1
decl_stmt|;
name|QFileDialogListView
modifier|*
name|listView
decl_stmt|;
name|QWidget
modifier|*
name|page_2
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout2
decl_stmt|;
name|QFileDialogTreeView
modifier|*
name|treeView
decl_stmt|;
name|QLabel
modifier|*
name|fileNameLabel
decl_stmt|;
name|QFileDialogLineEdit
modifier|*
name|fileNameEdit
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|buttonBox
decl_stmt|;
name|QLabel
modifier|*
name|fileTypeLabel
decl_stmt|;
name|QComboBox
modifier|*
name|fileTypeCombo
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|QFileDialog
parameter_list|)
block|{
if|if
condition|(
name|QFileDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|QFileDialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QFileDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|QFileDialog
operator|->
name|resize
argument_list|(
literal|521
argument_list|,
literal|316
argument_list|)
expr_stmt|;
name|QFileDialog
operator|->
name|setSizeGripEnabled
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
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
name|lookInLabel
operator|=
name|new
name|QLabel
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|lookInLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"lookInLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|lookInLabel
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
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|hboxLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|lookInCombo
operator|=
name|new
name|QFileDialogComboBox
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|lookInCombo
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"lookInCombo"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
decl_stmt|;
name|sizePolicy
operator|.
name|setHorizontalStretch
argument_list|(
literal|1
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
name|lookInCombo
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|lookInCombo
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|lookInCombo
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|50
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|lookInCombo
argument_list|)
expr_stmt|;
name|backButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|backButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"backButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|backButton
argument_list|)
expr_stmt|;
name|forwardButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|forwardButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"forwardButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|forwardButton
argument_list|)
expr_stmt|;
name|toParentButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|toParentButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"toParentButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|toParentButton
argument_list|)
expr_stmt|;
name|newFolderButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|newFolderButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newFolderButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|newFolderButton
argument_list|)
expr_stmt|;
name|listModeButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|listModeButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"listModeButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|listModeButton
argument_list|)
expr_stmt|;
name|detailModeButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|detailModeButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"detailModeButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|detailModeButton
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|splitter
operator|=
name|new
name|QSplitter
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"splitter"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy1
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
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
name|splitter
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy1
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|sidebar
operator|=
name|new
name|QSidebar
argument_list|(
name|splitter
argument_list|)
expr_stmt|;
name|sidebar
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"sidebar"
argument_list|)
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|addWidget
argument_list|(
name|sidebar
argument_list|)
expr_stmt|;
name|frame
operator|=
name|new
name|QFrame
argument_list|(
name|splitter
argument_list|)
expr_stmt|;
name|frame
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"frame"
argument_list|)
argument_list|)
expr_stmt|;
name|frame
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|NoFrame
argument_list|)
expr_stmt|;
name|frame
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Raised
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|frame
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
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
name|vboxLayout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|stackedWidget
operator|=
name|new
name|QStackedWidget
argument_list|(
name|frame
argument_list|)
expr_stmt|;
name|stackedWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"stackedWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|page
operator|=
name|new
name|QWidget
argument_list|()
expr_stmt|;
name|page
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"page"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|listView
operator|=
name|new
name|QFileDialogListView
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|listView
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"listView"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout1
operator|->
name|addWidget
argument_list|(
name|listView
argument_list|)
expr_stmt|;
name|stackedWidget
operator|->
name|addWidget
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|page_2
operator|=
name|new
name|QWidget
argument_list|()
expr_stmt|;
name|page_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"page_2"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|page_2
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vboxLayout2"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|treeView
operator|=
name|new
name|QFileDialogTreeView
argument_list|(
name|page_2
argument_list|)
expr_stmt|;
name|treeView
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"treeView"
argument_list|)
argument_list|)
expr_stmt|;
name|vboxLayout2
operator|->
name|addWidget
argument_list|(
name|treeView
argument_list|)
expr_stmt|;
name|stackedWidget
operator|->
name|addWidget
argument_list|(
name|page_2
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|stackedWidget
argument_list|)
expr_stmt|;
name|splitter
operator|->
name|addWidget
argument_list|(
name|frame
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|splitter
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
name|fileNameLabel
operator|=
name|new
name|QLabel
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|fileNameLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"fileNameLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy2
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
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
name|fileNameLabel
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|fileNameLabel
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy2
argument_list|)
expr_stmt|;
name|fileNameLabel
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
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|fileNameLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|fileNameEdit
operator|=
name|new
name|QFileDialogLineEdit
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|fileNameEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"fileNameEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy3
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
decl_stmt|;
name|sizePolicy3
operator|.
name|setHorizontalStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|sizePolicy3
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy3
operator|.
name|setHeightForWidth
argument_list|(
name|fileNameEdit
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|fileNameEdit
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy3
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|fileNameEdit
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|QFileDialog
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
name|Vertical
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
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|fileTypeLabel
operator|=
name|new
name|QLabel
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|fileTypeLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"fileTypeLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy4
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
decl_stmt|;
name|sizePolicy4
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy4
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy4
operator|.
name|setHeightForWidth
argument_list|(
name|fileTypeLabel
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|fileTypeLabel
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy4
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|fileTypeLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|fileTypeCombo
operator|=
name|new
name|QComboBox
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|fileTypeCombo
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"fileTypeCombo"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy5
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
decl_stmt|;
name|sizePolicy5
operator|.
name|setHorizontalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy5
operator|.
name|setVerticalStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|sizePolicy5
operator|.
name|setHeightForWidth
argument_list|(
name|fileTypeCombo
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|fileTypeCombo
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy5
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|fileTypeCombo
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|lookInCombo
argument_list|,
name|backButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|backButton
argument_list|,
name|forwardButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|forwardButton
argument_list|,
name|toParentButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|toParentButton
argument_list|,
name|newFolderButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|newFolderButton
argument_list|,
name|listModeButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|listModeButton
argument_list|,
name|detailModeButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|detailModeButton
argument_list|,
name|sidebar
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|sidebar
argument_list|,
name|listView
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|listView
argument_list|,
name|fileNameEdit
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|fileNameEdit
argument_list|,
name|fileTypeCombo
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|fileTypeCombo
argument_list|,
name|buttonBox
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|buttonBox
argument_list|,
name|treeView
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
name|stackedWidget
operator|->
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|QFileDialog
parameter_list|)
block|{
name|lookInLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Look in:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|backButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Back"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|forwardButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Forward"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|toParentButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Parent Directory"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|newFolderButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Create New Folder"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|listModeButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"List View"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|detailModeButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Detail View"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|fileTypeLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QFileDialog"
argument_list|,
literal|"Files of type:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|QFileDialog
argument_list|)
expr_stmt|;
block|}
comment|// retranslateUi
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|namespace
name|Ui
block|{
name|class
name|QFileDialog
range|:
name|public
name|Ui_QFileDialog
block|{}
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace Ui
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILEDIALOG_H
end_comment
end_unit
