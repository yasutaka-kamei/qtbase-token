begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'tetrixwindow.ui' ** ** Created by: Qt User Interface Compiler version 5.0.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TETRIXWINDOW_H
end_ifndef
begin_define
DECL|macro|TETRIXWINDOW_H
define|#
directive|define
name|TETRIXWINDOW_H
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
file|<QtWidgets/QLCDNumber>
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
file|"tetrixboard.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_TetrixWindow
block|{
name|public
label|:
name|QVBoxLayout
modifier|*
name|vboxLayout
decl_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
name|QPushButton
modifier|*
name|startButton
decl_stmt|;
name|QLCDNumber
modifier|*
name|linesLcd
decl_stmt|;
name|QLabel
modifier|*
name|linesRemovedLabel
decl_stmt|;
name|QPushButton
modifier|*
name|pauseButton
decl_stmt|;
name|QLCDNumber
modifier|*
name|scoreLcd
decl_stmt|;
name|TetrixBoard
modifier|*
name|board
decl_stmt|;
name|QLabel
modifier|*
name|levelLabel
decl_stmt|;
name|QLabel
modifier|*
name|nextLabel
decl_stmt|;
name|QLCDNumber
modifier|*
name|levelLcd
decl_stmt|;
name|QLabel
modifier|*
name|scoreLabel
decl_stmt|;
name|QLabel
modifier|*
name|nextPieceLabel
decl_stmt|;
name|QPushButton
modifier|*
name|quitButton
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|TetrixWindow
parameter_list|)
block|{
if|if
condition|(
name|TetrixWindow
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|TetrixWindow
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"TetrixWindow"
argument_list|)
argument_list|)
expr_stmt|;
name|TetrixWindow
operator|->
name|resize
argument_list|(
literal|537
argument_list|,
literal|475
argument_list|)
expr_stmt|;
name|vboxLayout
operator|=
name|new
name|QVBoxLayout
argument_list|(
name|TetrixWindow
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
name|gridLayout
operator|=
name|new
name|QGridLayout
argument_list|()
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
name|startButton
operator|=
name|new
name|QPushButton
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|startButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"startButton"
argument_list|)
argument_list|)
expr_stmt|;
name|startButton
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|startButton
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|linesLcd
operator|=
name|new
name|QLCDNumber
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|linesLcd
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"linesLcd"
argument_list|)
argument_list|)
expr_stmt|;
name|linesLcd
operator|->
name|setSegmentStyle
argument_list|(
name|QLCDNumber
operator|::
name|Filled
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|linesLcd
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
name|linesRemovedLabel
operator|=
name|new
name|QLabel
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|linesRemovedLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"linesRemovedLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|linesRemovedLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignBottom
operator||
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|linesRemovedLabel
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
name|pauseButton
operator|=
name|new
name|QPushButton
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|pauseButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pauseButton"
argument_list|)
argument_list|)
expr_stmt|;
name|pauseButton
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|pauseButton
argument_list|,
literal|5
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|scoreLcd
operator|=
name|new
name|QLCDNumber
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|scoreLcd
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"scoreLcd"
argument_list|)
argument_list|)
expr_stmt|;
name|scoreLcd
operator|->
name|setSegmentStyle
argument_list|(
name|QLCDNumber
operator|::
name|Filled
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|scoreLcd
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
name|board
operator|=
name|new
name|TetrixBoard
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|board
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"board"
argument_list|)
argument_list|)
expr_stmt|;
name|board
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|board
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|Panel
argument_list|)
expr_stmt|;
name|board
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|board
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|levelLabel
operator|=
name|new
name|QLabel
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|levelLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"levelLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|levelLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignBottom
operator||
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|levelLabel
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
name|nextLabel
operator|=
name|new
name|QLabel
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|nextLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"nextLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|nextLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignBottom
operator||
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|nextLabel
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
name|levelLcd
operator|=
name|new
name|QLCDNumber
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|levelLcd
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"levelLcd"
argument_list|)
argument_list|)
expr_stmt|;
name|levelLcd
operator|->
name|setSegmentStyle
argument_list|(
name|QLCDNumber
operator|::
name|Filled
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|levelLcd
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
name|scoreLabel
operator|=
name|new
name|QLabel
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|scoreLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"scoreLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|scoreLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignBottom
operator||
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|scoreLabel
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
name|nextPieceLabel
operator|=
name|new
name|QLabel
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|nextPieceLabel
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"nextPieceLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|nextPieceLabel
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|Box
argument_list|)
expr_stmt|;
name|nextPieceLabel
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Raised
argument_list|)
expr_stmt|;
name|nextPieceLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|nextPieceLabel
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
name|quitButton
operator|=
name|new
name|QPushButton
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|quitButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"quitButton"
argument_list|)
argument_list|)
expr_stmt|;
name|quitButton
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|quitButton
argument_list|,
literal|4
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|vboxLayout
operator|->
name|addLayout
argument_list|(
name|gridLayout
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|TetrixWindow
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|TetrixWindow
parameter_list|)
block|{
name|TetrixWindow
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TetrixWindow"
argument_list|,
literal|"Tetrix"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|startButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TetrixWindow"
argument_list|,
literal|"&Start"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|linesRemovedLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TetrixWindow"
argument_list|,
literal|"LINES REMOVED"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|pauseButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TetrixWindow"
argument_list|,
literal|"&Pause"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|levelLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TetrixWindow"
argument_list|,
literal|"LEVEL"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|nextLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TetrixWindow"
argument_list|,
literal|"NEXT"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|scoreLabel
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TetrixWindow"
argument_list|,
literal|"SCORE"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|nextPieceLabel
operator|->
name|setText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|quitButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"TetrixWindow"
argument_list|,
literal|"&Quit"
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
name|TetrixWindow
range|:
name|public
name|Ui_TetrixWindow
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
comment|// TETRIXWINDOW_H
end_comment
end_unit
