begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'identifierpage.ui' ** ** Created: Fri Sep 4 10:17:13 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|IDENTIFIERPAGE_H
end_ifndef
begin_define
DECL|macro|IDENTIFIERPAGE_H
define|#
directive|define
name|IDENTIFIERPAGE_H
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
file|<QtWidgets/QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QRadioButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSpacerItem>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_IdentifierPage
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QCheckBox
modifier|*
name|identifierCheckBox
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem1
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem2
decl_stmt|;
name|QRadioButton
modifier|*
name|globalButton
decl_stmt|;
name|QLineEdit
modifier|*
name|prefixLineEdit
decl_stmt|;
name|QRadioButton
modifier|*
name|fileNameButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem3
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|IdentifierPage
parameter_list|)
block|{
if|if
condition|(
name|IdentifierPage
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|IdentifierPage
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"IdentifierPage"
argument_list|)
argument_list|)
expr_stmt|;
name|IdentifierPage
operator|->
name|resize
argument_list|(
literal|417
argument_list|,
literal|242
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|IdentifierPage
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
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem
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
name|identifierCheckBox
operator|=
name|new
name|QCheckBox
argument_list|(
name|IdentifierPage
argument_list|)
expr_stmt|;
name|identifierCheckBox
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"identifierCheckBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|identifierCheckBox
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
name|spacerItem1
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|161
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
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem1
argument_list|,
literal|1
argument_list|,
literal|3
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
literal|30
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem2
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
name|globalButton
operator|=
name|new
name|QRadioButton
argument_list|(
name|IdentifierPage
argument_list|)
expr_stmt|;
name|globalButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"globalButton"
argument_list|)
argument_list|)
expr_stmt|;
name|globalButton
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|globalButton
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
name|globalButton
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
name|prefixLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|IdentifierPage
argument_list|)
expr_stmt|;
name|prefixLineEdit
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"prefixLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|prefixLineEdit
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|prefixLineEdit
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|fileNameButton
operator|=
name|new
name|QRadioButton
argument_list|(
name|IdentifierPage
argument_list|)
expr_stmt|;
name|fileNameButton
operator|->
name|setObjectName
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"fileNameButton"
argument_list|)
argument_list|)
expr_stmt|;
name|fileNameButton
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|fileNameButton
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|spacerItem3
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|31
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
name|gridLayout
operator|->
name|addItem
argument_list|(
name|spacerItem3
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|IdentifierPage
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|globalButton
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|prefixLineEdit
argument_list|,
name|SLOT
argument_list|(
name|setEnabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|IdentifierPage
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|IdentifierPage
parameter_list|)
block|{
name|IdentifierPage
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"IdentifierPage"
argument_list|,
literal|"Form"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|identifierCheckBox
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"IdentifierPage"
argument_list|,
literal|"Create identifiers"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|globalButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"IdentifierPage"
argument_list|,
literal|"Global prefix:"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|fileNameButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"IdentifierPage"
argument_list|,
literal|"Inherit prefix from file names"
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
name|IdentifierPage
range|:
name|public
name|Ui_IdentifierPage
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
comment|// IDENTIFIERPAGE_H
end_comment
end_unit
