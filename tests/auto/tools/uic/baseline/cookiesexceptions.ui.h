begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'cookiesexceptions.ui' ** ** Created: Fri Sep 4 10:17:13 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COOKIESEXCEPTIONS_H
end_ifndef
begin_define
DECL|macro|COOKIESEXCEPTIONS_H
define|#
directive|define
name|COOKIESEXCEPTIONS_H
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
file|<QtWidgets/QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|"edittableview.h"
end_include
begin_include
include|#
directive|include
file|"searchlineedit.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_CookiesExceptionsDialog
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QGroupBox
modifier|*
name|newExceptionGroupBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QLineEdit
modifier|*
name|domainLineEdit
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout1
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QPushButton
modifier|*
name|blockButton
decl_stmt|;
name|QPushButton
modifier|*
name|allowForSessionButton
decl_stmt|;
name|QPushButton
modifier|*
name|allowButton
decl_stmt|;
name|QGroupBox
modifier|*
name|ExceptionsGroupBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout1
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem1
decl_stmt|;
name|SearchLineEdit
modifier|*
name|search
decl_stmt|;
name|EditTableView
modifier|*
name|exceptionTable
decl_stmt|;
name|QPushButton
modifier|*
name|removeButton
decl_stmt|;
name|QPushButton
modifier|*
name|removeAllButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem2
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
name|CookiesExceptionsDialog
parameter_list|)
block|{
if|if
condition|(
name|CookiesExceptionsDialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|CookiesExceptionsDialog
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"CookiesExceptionsDialog"
argument_list|)
argument_list|)
expr_stmt|;
name|CookiesExceptionsDialog
operator|->
name|resize
argument_list|(
literal|466
argument_list|,
literal|446
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|CookiesExceptionsDialog
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"vboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|newExceptionGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|CookiesExceptionsDialog
argument_list|)
expr_stmt|;
name|newExceptionGroupBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"newExceptionGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|newExceptionGroupBox
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"gridLayout"
argument_list|)
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
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"hboxLayout"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|newExceptionGroupBox
argument_list|)
expr_stmt|;
name|label
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"label"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|domainLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|newExceptionGroupBox
argument_list|)
expr_stmt|;
name|domainLineEdit
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"domainLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|domainLineEdit
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
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|hboxLayout1
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"hboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|81
argument_list|,
literal|25
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addItem
argument_list|(
name|spacerItem
argument_list|)
expr_stmt|;
name|blockButton
operator|=
name|new
name|QPushButton
argument_list|(
name|newExceptionGroupBox
argument_list|)
expr_stmt|;
name|blockButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"blockButton"
argument_list|)
argument_list|)
expr_stmt|;
name|blockButton
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|blockButton
argument_list|)
expr_stmt|;
name|allowForSessionButton
operator|=
name|new
name|QPushButton
argument_list|(
name|newExceptionGroupBox
argument_list|)
expr_stmt|;
name|allowForSessionButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"allowForSessionButton"
argument_list|)
argument_list|)
expr_stmt|;
name|allowForSessionButton
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|allowForSessionButton
argument_list|)
expr_stmt|;
name|allowButton
operator|=
name|new
name|QPushButton
argument_list|(
name|newExceptionGroupBox
argument_list|)
expr_stmt|;
name|allowButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"allowButton"
argument_list|)
argument_list|)
expr_stmt|;
name|allowButton
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|allowButton
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addLayout
argument_list|(
name|hboxLayout1
argument_list|,
literal|1
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
name|newExceptionGroupBox
argument_list|)
expr_stmt|;
name|ExceptionsGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|CookiesExceptionsDialog
argument_list|)
expr_stmt|;
name|ExceptionsGroupBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"ExceptionsGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|=
name|new
name|QGridLayout
argument_list|(
name|ExceptionsGroupBox
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"gridLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|spacerItem1
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|252
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addItem
argument_list|(
name|spacerItem1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|search
operator|=
name|new
name|SearchLineEdit
argument_list|(
name|ExceptionsGroupBox
argument_list|)
expr_stmt|;
name|search
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"search"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|search
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
name|exceptionTable
operator|=
name|new
name|EditTableView
argument_list|(
name|ExceptionsGroupBox
argument_list|)
expr_stmt|;
name|exceptionTable
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"exceptionTable"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|exceptionTable
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
name|removeButton
operator|=
name|new
name|QPushButton
argument_list|(
name|ExceptionsGroupBox
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"removeButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|removeButton
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
name|removeAllButton
operator|=
name|new
name|QPushButton
argument_list|(
name|ExceptionsGroupBox
argument_list|)
expr_stmt|;
name|removeAllButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"removeAllButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|removeAllButton
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
name|spacerItem2
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|40
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addItem
argument_list|(
name|spacerItem2
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|ExceptionsGroupBox
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
name|new
name|QDialogButtonBox
argument_list|(
name|CookiesExceptionsDialog
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
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
name|CookiesExceptionsDialog
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
name|CookiesExceptionsDialog
argument_list|,
name|SLOT
argument_list|(
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|CookiesExceptionsDialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|CookiesExceptionsDialog
parameter_list|)
block|{
name|CookiesExceptionsDialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"CookiesExceptionsDialog"
argument_list|,
literal|"Cookie Exceptions"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|newExceptionGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"CookiesExceptionsDialog"
argument_list|,
literal|"New Exception"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
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
literal|"CookiesExceptionsDialog"
argument_list|,
literal|"Domain:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|blockButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"CookiesExceptionsDialog"
argument_list|,
literal|"Block"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|allowForSessionButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"CookiesExceptionsDialog"
argument_list|,
literal|"Allow For Session"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|allowButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"CookiesExceptionsDialog"
argument_list|,
literal|"Allow"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|ExceptionsGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"CookiesExceptionsDialog"
argument_list|,
literal|"Exceptions"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|removeButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"CookiesExceptionsDialog"
argument_list|,
literal|"&Remove"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|removeAllButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"CookiesExceptionsDialog"
argument_list|,
literal|"Remove&All"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
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
name|CookiesExceptionsDialog
range|:
name|public
name|Ui_CookiesExceptionsDialog
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
comment|// COOKIESEXCEPTIONS_H
end_comment
end_unit
