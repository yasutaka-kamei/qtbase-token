begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'remotecontrol.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|REMOTECONTROL_H
end_ifndef
begin_define
DECL|macro|REMOTECONTROL_H
define|#
directive|define
name|REMOTECONTROL_H
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
file|<QtWidgets/QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QMenu>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QMenuBar>
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
file|<QtWidgets/QStatusBar>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QToolButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_RemoteControlClass
block|{
name|public
label|:
name|QAction
modifier|*
name|actionQuit
decl_stmt|;
name|QWidget
modifier|*
name|centralWidget
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QLabel
modifier|*
name|label
decl_stmt|;
name|QLineEdit
modifier|*
name|startUrlLineEdit
decl_stmt|;
name|QPushButton
modifier|*
name|launchButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem1
decl_stmt|;
name|QGroupBox
modifier|*
name|actionGroupBox
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout1
decl_stmt|;
name|QLabel
modifier|*
name|label_2
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
decl_stmt|;
name|QLineEdit
modifier|*
name|indexLineEdit
decl_stmt|;
name|QToolButton
modifier|*
name|indexButton
decl_stmt|;
name|QLabel
modifier|*
name|label_4
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout1
decl_stmt|;
name|QLineEdit
modifier|*
name|identifierLineEdit
decl_stmt|;
name|QToolButton
modifier|*
name|identifierButton
decl_stmt|;
name|QLabel
modifier|*
name|label_3
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout2
decl_stmt|;
name|QLineEdit
modifier|*
name|urlLineEdit
decl_stmt|;
name|QToolButton
modifier|*
name|urlButton
decl_stmt|;
name|QPushButton
modifier|*
name|syncContentsButton
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacerItem2
decl_stmt|;
name|QCheckBox
modifier|*
name|contentsCheckBox
decl_stmt|;
name|QCheckBox
modifier|*
name|indexCheckBox
decl_stmt|;
name|QCheckBox
modifier|*
name|bookmarksCheckBox
decl_stmt|;
name|QMenuBar
modifier|*
name|menuBar
decl_stmt|;
name|QMenu
modifier|*
name|menuFile
decl_stmt|;
name|QStatusBar
modifier|*
name|statusBar
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QMainWindow
modifier|*
name|RemoteControlClass
parameter_list|)
block|{
if|if
condition|(
name|RemoteControlClass
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|RemoteControlClass
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"RemoteControlClass"
argument_list|)
argument_list|)
expr_stmt|;
name|RemoteControlClass
operator|->
name|resize
argument_list|(
literal|344
argument_list|,
literal|364
argument_list|)
expr_stmt|;
name|actionQuit
operator|=
name|new
name|QAction
argument_list|(
name|RemoteControlClass
argument_list|)
expr_stmt|;
name|actionQuit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"actionQuit"
argument_list|)
argument_list|)
expr_stmt|;
name|centralWidget
operator|=
name|new
name|QWidget
argument_list|(
name|RemoteControlClass
argument_list|)
expr_stmt|;
name|centralWidget
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"centralWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|setContentsMargins
argument_list|(
literal|11
argument_list|,
literal|11
argument_list|,
literal|11
argument_list|,
literal|11
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
name|label
operator|=
name|new
name|QLabel
argument_list|(
name|centralWidget
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
name|startUrlLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
name|startUrlLineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"startUrlLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|startUrlLineEdit
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
name|launchButton
operator|=
name|new
name|QPushButton
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
name|launchButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"launchButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|launchButton
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|spacerItem
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|101
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
name|spacerItem
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|spacerItem1
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|113
argument_list|,
literal|16
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
name|spacerItem1
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
name|actionGroupBox
operator|=
name|new
name|QGroupBox
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
name|actionGroupBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"actionGroupBox"
argument_list|)
argument_list|)
expr_stmt|;
name|actionGroupBox
operator|->
name|setEnabled
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|gridLayout1
operator|=
name|new
name|QGridLayout
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|setSpacing
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|setContentsMargins
argument_list|(
literal|11
argument_list|,
literal|11
argument_list|,
literal|11
argument_list|,
literal|11
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
name|label_2
operator|=
name|new
name|QLabel
argument_list|(
name|actionGroupBox
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
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|label_2
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
name|setSpacing
argument_list|(
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
name|indexLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|indexLineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"indexLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|indexLineEdit
argument_list|)
expr_stmt|;
name|indexButton
operator|=
name|new
name|QToolButton
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|indexButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"indexButton"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QIcon
name|icon
init|=
name|QIcon
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|":/remotecontrol/enter.png"
argument_list|)
argument_list|)
decl_stmt|;
name|indexButton
operator|->
name|setIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|indexButton
argument_list|)
expr_stmt|;
name|gridLayout1
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
name|label_4
operator|=
name|new
name|QLabel
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|label_4
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"label_4"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|label_4
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
name|hboxLayout1
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|hboxLayout1
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hboxLayout1"
argument_list|)
argument_list|)
expr_stmt|;
name|identifierLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|identifierLineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"identifierLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|identifierLineEdit
argument_list|)
expr_stmt|;
name|identifierButton
operator|=
name|new
name|QToolButton
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|identifierButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"identifierButton"
argument_list|)
argument_list|)
expr_stmt|;
name|identifierButton
operator|->
name|setIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|hboxLayout1
operator|->
name|addWidget
argument_list|(
name|identifierButton
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addLayout
argument_list|(
name|hboxLayout1
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
name|label_3
operator|=
name|new
name|QLabel
argument_list|(
name|actionGroupBox
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
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|label_3
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
name|hboxLayout2
operator|=
name|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|hboxLayout2
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hboxLayout2"
argument_list|)
argument_list|)
expr_stmt|;
name|urlLineEdit
operator|=
name|new
name|QLineEdit
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|urlLineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"urlLineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|->
name|addWidget
argument_list|(
name|urlLineEdit
argument_list|)
expr_stmt|;
name|urlButton
operator|=
name|new
name|QToolButton
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|urlButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"urlButton"
argument_list|)
argument_list|)
expr_stmt|;
name|urlButton
operator|->
name|setIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|hboxLayout2
operator|->
name|addWidget
argument_list|(
name|urlButton
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addLayout
argument_list|(
name|hboxLayout2
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
name|syncContentsButton
operator|=
name|new
name|QPushButton
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|syncContentsButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"syncContentsButton"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|syncContentsButton
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
name|spacerItem2
operator|=
name|new
name|QSpacerItem
argument_list|(
literal|81
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
literal|3
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|contentsCheckBox
operator|=
name|new
name|QCheckBox
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|contentsCheckBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"contentsCheckBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|contentsCheckBox
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|indexCheckBox
operator|=
name|new
name|QCheckBox
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|indexCheckBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"indexCheckBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|indexCheckBox
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|bookmarksCheckBox
operator|=
name|new
name|QCheckBox
argument_list|(
name|actionGroupBox
argument_list|)
expr_stmt|;
name|bookmarksCheckBox
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"bookmarksCheckBox"
argument_list|)
argument_list|)
expr_stmt|;
name|gridLayout1
operator|->
name|addWidget
argument_list|(
name|bookmarksCheckBox
argument_list|,
literal|6
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|actionGroupBox
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|RemoteControlClass
operator|->
name|setCentralWidget
argument_list|(
name|centralWidget
argument_list|)
expr_stmt|;
name|menuBar
operator|=
name|new
name|QMenuBar
argument_list|(
name|RemoteControlClass
argument_list|)
expr_stmt|;
name|menuBar
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"menuBar"
argument_list|)
argument_list|)
expr_stmt|;
name|menuBar
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|344
argument_list|,
literal|21
argument_list|)
argument_list|)
expr_stmt|;
name|menuFile
operator|=
name|new
name|QMenu
argument_list|(
name|menuBar
argument_list|)
expr_stmt|;
name|menuFile
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"menuFile"
argument_list|)
argument_list|)
expr_stmt|;
name|RemoteControlClass
operator|->
name|setMenuBar
argument_list|(
name|menuBar
argument_list|)
expr_stmt|;
name|statusBar
operator|=
name|new
name|QStatusBar
argument_list|(
name|RemoteControlClass
argument_list|)
expr_stmt|;
name|statusBar
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"statusBar"
argument_list|)
argument_list|)
expr_stmt|;
name|RemoteControlClass
operator|->
name|setStatusBar
argument_list|(
name|statusBar
argument_list|)
expr_stmt|;
name|menuBar
operator|->
name|addAction
argument_list|(
name|menuFile
operator|->
name|menuAction
argument_list|()
argument_list|)
expr_stmt|;
name|menuFile
operator|->
name|addAction
argument_list|(
name|actionQuit
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|RemoteControlClass
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|RemoteControlClass
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QMainWindow
modifier|*
name|RemoteControlClass
parameter_list|)
block|{
name|RemoteControlClass
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"RemoteControlClass"
argument_list|,
literal|"RemoteControl"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|actionQuit
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"RemoteControlClass"
argument_list|,
literal|"Quit"
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
literal|"RemoteControlClass"
argument_list|,
literal|"Start URL:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|launchButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"RemoteControlClass"
argument_list|,
literal|"Launch Qt HelpViewer"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|actionGroupBox
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"RemoteControlClass"
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
literal|"RemoteControlClass"
argument_list|,
literal|"Search in Index:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|indexButton
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|label_4
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"RemoteControlClass"
argument_list|,
literal|"Identifier:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|identifierButton
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
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
literal|"RemoteControlClass"
argument_list|,
literal|"Show URL:"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|urlButton
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|syncContentsButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"RemoteControlClass"
argument_list|,
literal|"Sync Contents"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|contentsCheckBox
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"RemoteControlClass"
argument_list|,
literal|"Show Contents"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|indexCheckBox
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"RemoteControlClass"
argument_list|,
literal|"Show Index"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|bookmarksCheckBox
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"RemoteControlClass"
argument_list|,
literal|"Show Bookmarks"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|menuFile
operator|->
name|setTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"RemoteControlClass"
argument_list|,
literal|"File"
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
name|RemoteControlClass
range|:
name|public
name|Ui_RemoteControlClass
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
comment|// REMOTECONTROL_H
end_comment
end_unit
