begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'gridalignment.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GRIDALIGNMENT_H
end_ifndef
begin_define
DECL|macro|GRIDALIGNMENT_H
define|#
directive|define
name|GRIDALIGNMENT_H
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
file|<QtWidgets/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_Form
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QPushButton
modifier|*
name|pushButton
decl_stmt|;
name|QPushButton
modifier|*
name|pushButton_3
decl_stmt|;
name|QPushButton
modifier|*
name|pushButton_2
decl_stmt|;
name|QPushButton
modifier|*
name|pushButton_4
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|Form
parameter_list|)
block|{
if|if
condition|(
name|Form
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|Form
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Form"
argument_list|)
argument_list|)
expr_stmt|;
name|Form
operator|->
name|resize
argument_list|(
literal|279
argument_list|,
literal|163
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|Form
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
name|pushButton
operator|=
name|new
name|QPushButton
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|pushButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pushButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|pushButton
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|AlignLeft
argument_list|)
expr_stmt|;
name|pushButton_3
operator|=
name|new
name|QPushButton
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|pushButton_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pushButton_3"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|pushButton_3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
name|pushButton_2
operator|=
name|new
name|QPushButton
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|pushButton_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pushButton_2"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|pushButton_2
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|pushButton_4
operator|=
name|new
name|QPushButton
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|pushButton_4
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pushButton_4"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|pushButton_4
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|AlignBottom
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|Form
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|Form
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|Form
parameter_list|)
block|{
name|Form
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Form"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|pushButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Left"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|pushButton_3
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Top"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|pushButton_2
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Right"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|pushButton_4
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Form"
argument_list|,
literal|"Bottom"
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
name|Form
range|:
name|public
name|Ui_Form
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
comment|// GRIDALIGNMENT_H
end_comment
end_unit
