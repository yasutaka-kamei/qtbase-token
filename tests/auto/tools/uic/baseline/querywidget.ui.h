begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'querywidget.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUERYWIDGET_H
end_ifndef
begin_define
DECL|macro|QUERYWIDGET_H
define|#
directive|define
name|QUERYWIDGET_H
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
file|<QtWidgets/QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QStatusBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTextEdit>
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_QueryWidget
block|{
name|public
label|:
name|QWidget
modifier|*
name|centralwidget
decl_stmt|;
name|QVBoxLayout
modifier|*
name|verticalLayout
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QGroupBox
modifier|*
name|inputGroupBox
decl_stmt|;
name|QVBoxLayout
modifier|*
name|verticalLayout_4
decl_stmt|;
name|QVBoxLayout
modifier|*
name|_2
decl_stmt|;
name|QTextEdit
modifier|*
name|inputTextEdit
decl_stmt|;
name|QGroupBox
modifier|*
name|queryGroupBox
decl_stmt|;
name|QVBoxLayout
modifier|*
name|verticalLayout_5
decl_stmt|;
name|QComboBox
modifier|*
name|defaultQueries
decl_stmt|;
name|QTextEdit
modifier|*
name|queryTextEdit
decl_stmt|;
name|QGroupBox
modifier|*
name|outputGroupBox
decl_stmt|;
name|QVBoxLayout
modifier|*
name|verticalLayout_6
decl_stmt|;
name|QVBoxLayout
modifier|*
name|_3
decl_stmt|;
name|QTextEdit
modifier|*
name|outputTextEdit
decl_stmt|;
name|QMenuBar
modifier|*
name|menubar
decl_stmt|;
name|QStatusBar
modifier|*
name|statusbar
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QMainWindow
modifier|*
name|QueryWidget
parameter_list|)
block|{
if|if
condition|(
name|QueryWidget
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|QueryWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QueryWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|QueryWidget
operator|->
name|resize
argument_list|(
literal|545
argument_list|,
literal|531
argument_list|)
expr_stmt|;
name|centralwidget
operator|=
name|new
name|QWidget
argument_list|(
name|QueryWidget
argument_list|)
expr_stmt|;
name|centralwidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"centralwidget"
argument_list|)
argument_list|)
expr_stmt|;
name|centralwidget
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|29
argument_list|,
literal|545
argument_list|,
literal|480
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|centralwidget
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"verticalLayout"
argument_list|)
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
ifndef|#
directive|ifndef
name|Q_OS_MAC
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
name|inputGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|centralwidget
argument_list|)
expr_stmt|;
name|inputGroupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"inputGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|inputGroupBox
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|550
argument_list|,
literal|120
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout_4
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|inputGroupBox
argument_list|)
expr_stmt|;
name|verticalLayout_4
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"verticalLayout_4"
argument_list|)
argument_list|)
expr_stmt|;
name|_2
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|_2
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
name|_2
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
endif|#
directive|endif
name|_2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"_2"
argument_list|)
argument_list|)
expr_stmt|;
name|inputTextEdit
operator|=
name|new
name|QTextEdit
argument_list|(
name|inputGroupBox
argument_list|)
expr_stmt|;
name|inputTextEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"inputTextEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|_2
operator|->
name|addWidget
argument_list|(
name|inputTextEdit
argument_list|)
expr_stmt|;
name|verticalLayout_4
operator|->
name|addLayout
argument_list|(
name|_2
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|inputGroupBox
argument_list|)
expr_stmt|;
name|queryGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|centralwidget
argument_list|)
expr_stmt|;
name|queryGroupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"queryGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|queryGroupBox
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|550
argument_list|,
literal|120
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout_5
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|queryGroupBox
argument_list|)
expr_stmt|;
name|verticalLayout_5
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"verticalLayout_5"
argument_list|)
argument_list|)
expr_stmt|;
name|defaultQueries
operator|=
name|new
name|QComboBox
argument_list|(
name|queryGroupBox
argument_list|)
expr_stmt|;
name|defaultQueries
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"defaultQueries"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout_5
operator|->
name|addWidget
argument_list|(
name|defaultQueries
argument_list|)
expr_stmt|;
name|queryTextEdit
operator|=
name|new
name|QTextEdit
argument_list|(
name|queryGroupBox
argument_list|)
expr_stmt|;
name|queryTextEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"queryTextEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|queryTextEdit
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|400
argument_list|,
literal|60
argument_list|)
argument_list|)
expr_stmt|;
name|queryTextEdit
operator|->
name|setReadOnly
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|queryTextEdit
operator|->
name|setAcceptRichText
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|verticalLayout_5
operator|->
name|addWidget
argument_list|(
name|queryTextEdit
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|queryGroupBox
argument_list|)
expr_stmt|;
name|outputGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|centralwidget
argument_list|)
expr_stmt|;
name|outputGroupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"outputGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|outputGroupBox
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|550
argument_list|,
literal|120
argument_list|)
argument_list|)
expr_stmt|;
name|verticalLayout_6
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|outputGroupBox
argument_list|)
expr_stmt|;
name|verticalLayout_6
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"verticalLayout_6"
argument_list|)
argument_list|)
expr_stmt|;
name|_3
operator|=
name|new
name|QVBoxLayout
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_MAC
name|_3
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
name|_3
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
endif|#
directive|endif
name|_3
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"_3"
argument_list|)
argument_list|)
expr_stmt|;
name|outputTextEdit
operator|=
name|new
name|QTextEdit
argument_list|(
name|outputGroupBox
argument_list|)
expr_stmt|;
name|outputTextEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"outputTextEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|outputTextEdit
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|500
argument_list|,
literal|80
argument_list|)
argument_list|)
expr_stmt|;
name|outputTextEdit
operator|->
name|setReadOnly
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|outputTextEdit
operator|->
name|setAcceptRichText
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|_3
operator|->
name|addWidget
argument_list|(
name|outputTextEdit
argument_list|)
expr_stmt|;
name|verticalLayout_6
operator|->
name|addLayout
argument_list|(
name|_3
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addWidget
argument_list|(
name|outputGroupBox
argument_list|)
expr_stmt|;
name|verticalLayout
operator|->
name|addLayout
argument_list|(
name|vboxLayout
argument_list|)
expr_stmt|;
name|QueryWidget
operator|->
name|setCentralWidget
argument_list|(
name|centralwidget
argument_list|)
expr_stmt|;
name|menubar
operator|=
name|new
name|QMenuBar
argument_list|(
name|QueryWidget
argument_list|)
expr_stmt|;
name|menubar
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"menubar"
argument_list|)
argument_list|)
expr_stmt|;
name|menubar
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|545
argument_list|,
literal|29
argument_list|)
argument_list|)
expr_stmt|;
name|QueryWidget
operator|->
name|setMenuBar
argument_list|(
name|menubar
argument_list|)
expr_stmt|;
name|statusbar
operator|=
name|new
name|QStatusBar
argument_list|(
name|QueryWidget
argument_list|)
expr_stmt|;
name|statusbar
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"statusbar"
argument_list|)
argument_list|)
expr_stmt|;
name|statusbar
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|509
argument_list|,
literal|545
argument_list|,
literal|22
argument_list|)
argument_list|)
expr_stmt|;
name|QueryWidget
operator|->
name|setStatusBar
argument_list|(
name|statusbar
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|QueryWidget
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|QueryWidget
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QMainWindow
modifier|*
name|QueryWidget
parameter_list|)
block|{
name|QueryWidget
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QueryWidget"
argument_list|,
literal|"Recipes XQuery Example"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|inputGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QueryWidget"
argument_list|,
literal|"Input Document"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|queryGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QueryWidget"
argument_list|,
literal|"Select your query:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|outputGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"QueryWidget"
argument_list|,
literal|"Output Document"
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
name|QueryWidget
range|:
name|public
name|Ui_QueryWidget
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
comment|// QUERYWIDGET_H
end_comment
end_unit
