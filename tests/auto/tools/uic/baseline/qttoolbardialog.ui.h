begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'qttoolbardialog.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTTOOLBARDIALOG_H
end_ifndef
begin_define
DECL|macro|QTTOOLBARDIALOG_H
define|#
directive|define
name|QTTOOLBARDIALOG_H
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
file|<QtWidgets/QListWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QToolButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTreeWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_QtToolBarDialog
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QTreeWidget
modifier|*
name|actionTree
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QToolButton
modifier|*
name|newButton
decl_stmt|;
name|QToolButton
modifier|*
name|removeButton
decl_stmt|;
name|QToolButton
modifier|*
name|renameButton
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QToolButton
modifier|*
name|upButton
decl_stmt|;
name|QToolButton
modifier|*
name|leftButton
decl_stmt|;
name|QToolButton
modifier|*
name|rightButton
decl_stmt|;
name|QToolButton
modifier|*
name|downButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QListWidget
modifier|*
name|currentToolBarList
decl_stmt|;
name|QLabel
modifier|*
name|label_3
decl_stmt|;
name|QListWidget
modifier|*
name|toolBarList
decl_stmt|;
name|QDialogButtonBox
modifier|*
name|buttonBox
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|QtToolBarDialog
parameter_list|)
block|{
if|if
condition|(
name|QtToolBarDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|QtToolBarDialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QtToolBarDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|QtToolBarDialog
operator|->
name|resize
argument_list|(
literal|583
argument_list|,
literal|508
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|QtToolBarDialog
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
name|gridLayout
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
name|actionTree
operator|=
name|new
name|QTreeWidget
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|actionTree
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"actionTree"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|actionTree
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|QtToolBarDialog
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
name|hboxLayout
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|hboxLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hboxLayout
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
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label_2"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|label_2
argument_list|)
expr_stmt|;
name|newButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|newButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"newButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|newButton
argument_list|)
expr_stmt|;
name|removeButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"removeButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|removeButton
argument_list|)
expr_stmt|;
name|renameButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|renameButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"renameButton"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|renameButton
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
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|()
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
name|upButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|upButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"upButton"
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
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
name|upButton
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|upButton
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|upButton
argument_list|)
expr_stmt|;
name|leftButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|leftButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"leftButton"
argument_list|)
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|leftButton
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|leftButton
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|leftButton
argument_list|)
expr_stmt|;
name|rightButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|rightButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"rightButton"
argument_list|)
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|rightButton
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|rightButton
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|rightButton
argument_list|)
expr_stmt|;
name|downButton
operator|=
name|new
name|QToolButton
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|downButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"downButton"
argument_list|)
argument_list|)
expr_stmt|;
name|sizePolicy
operator|.
name|setHeightForWidth
argument_list|(
name|downButton
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|downButton
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|downButton
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|29
argument_list|,
literal|16
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout
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
name|currentToolBarList
operator|=
name|new
name|QListWidget
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|currentToolBarList
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"currentToolBarList"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|currentToolBarList
argument_list|,
literal|3
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|label_3
operator|=
name|new
name|QLabel
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label_3"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label_3
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|toolBarList
operator|=
name|new
name|QListWidget
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|toolBarList
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"toolBarList"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|toolBarList
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|QtToolBarDialog
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
name|setStandardButtons
argument_list|(
name|QDialogButtonBox
operator|::
name|Apply
operator||
name|QDialogButtonBox
operator|::
name|Cancel
operator||
name|QDialogButtonBox
operator|::
name|Ok
operator||
name|QDialogButtonBox
operator|::
name|RestoreDefaults
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|newButton
argument_list|,
name|removeButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|removeButton
argument_list|,
name|renameButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|renameButton
argument_list|,
name|toolBarList
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|toolBarList
argument_list|,
name|upButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|upButton
argument_list|,
name|leftButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|leftButton
argument_list|,
name|rightButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|rightButton
argument_list|,
name|downButton
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|setTabOrder
argument_list|(
name|downButton
argument_list|,
name|currentToolBarList
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|QtToolBarDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|QtToolBarDialog
parameter_list|)
block|{
name|QtToolBarDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Customize Toolbars"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|___qtreewidgetitem
init|=
name|actionTree
operator|->
name|headerItem
argument_list|()
decl_stmt|;
name|___qtreewidgetitem
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"1"
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
literal|"QtToolBarDialog"
argument_list|,
literal|"Actions"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|label_2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Toolbars"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|newButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Add new toolbar"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|newButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"New"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|removeButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Remove selected toolbar"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|removeButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Remove"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|renameButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Rename toolbar"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|renameButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Rename"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|upButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Move action up"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|upButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Up"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|leftButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Remove action from toolbar"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|leftButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"<-"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|rightButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Add action to toolbar"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|rightButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"->"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|downButton
operator|->
name|setToolTip
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Move action down"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLTIP
name|downButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Down"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|label_3
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QtToolBarDialog"
argument_list|,
literal|"Current Toolbar Actions"
argument_list|,
literal|0
argument_list|)
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
name|QtToolBarDialog
range|:
name|public
name|Ui_QtToolBarDialog
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
comment|// QTTOOLBARDIALOG_H
end_comment
end_unit
