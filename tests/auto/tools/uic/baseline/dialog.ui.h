begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'dialog.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DIALOG_H
end_ifndef
begin_define
DECL|macro|DIALOG_H
define|#
directive|define
name|DIALOG_H
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
file|<QtWidgets/QLabel>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QPushButton>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_Dialog
block|{
name|public
label|:
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QPushButton
modifier|*
name|loadFromFileButton
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QPushButton
modifier|*
name|loadFromSharedMemoryButton
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QDialog
modifier|*
name|Dialog
parameter_list|)
block|{
if|if
condition|(
name|Dialog
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|Dialog
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Dialog"
argument_list|)
argument_list|)
expr_stmt|;
name|Dialog
operator|->
name|resize
argument_list|(
literal|451
argument_list|,
literal|322
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|Dialog
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
name|loadFromFileButton
operator|=
name|new
name|QPushButton
argument_list|(
name|Dialog
argument_list|)
expr_stmt|;
name|loadFromFileButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"loadFromFileButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|loadFromFileButton
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
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|Dialog
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
name|label
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|label
operator|->
name|setWordWrap
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label
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
name|loadFromSharedMemoryButton
operator|=
name|new
name|QPushButton
argument_list|(
name|Dialog
argument_list|)
expr_stmt|;
name|loadFromSharedMemoryButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"loadFromSharedMemoryButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|loadFromSharedMemoryButton
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
name|retranslateUi
argument_list|(
name|Dialog
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|Dialog
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QDialog
modifier|*
name|Dialog
parameter_list|)
block|{
name|Dialog
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Dialog"
argument_list|,
literal|"Dialog"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|loadFromFileButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Dialog"
argument_list|,
literal|"Load Image From File..."
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
literal|"Dialog"
argument_list|,
literal|"Launch two of these dialogs.  In the first, press the top button and load an image from a file.  In the second, press the bottom button and display the loaded image from shared memory."
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|loadFromSharedMemoryButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Dialog"
argument_list|,
literal|"Display Image From Shared Memory"
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
name|Dialog
range|:
name|public
name|Ui_Dialog
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
comment|// DIALOG_H
end_comment
end_unit
