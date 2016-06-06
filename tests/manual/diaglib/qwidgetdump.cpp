begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwidgetdump.h"
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_if
if|#
directive|if
name|QT_VERSION
operator|>
literal|0x050000
end_if
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_namespace
DECL|namespace|QtDiag
namespace|namespace
name|QtDiag
block|{
DECL|member|qtWidgetClasses
specifier|static
specifier|const
name|char
modifier|*
name|qtWidgetClasses
index|[]
init|=
block|{
literal|"QAbstractItemView"
block|,
literal|"QAbstractScrollArea"
block|,
literal|"QAbstractSlider"
block|,
literal|"QAbstractSpinBox"
block|,
literal|"QCalendarWidget"
block|,
literal|"QCheckBox"
block|,
literal|"QColorDialog"
block|,
literal|"QColumnView"
block|,
literal|"QComboBox"
block|,
literal|"QCommandLinkButton"
block|,
literal|"QDateEdit"
block|,
literal|"QDateTimeEdit"
block|,
literal|"QDesktopWidget"
block|,
literal|"QDial"
block|,
literal|"QDialog"
block|,
literal|"QDialogButtonBox"
block|,
literal|"QDockWidget"
block|,
literal|"QDoubleSpinBox"
block|,
literal|"QErrorMessage"
block|,
literal|"QFileDialog"
block|,
literal|"QFontComboBox"
block|,
literal|"QFontDialog"
block|,
literal|"QFrame"
block|,
literal|"QGraphicsView"
block|,
literal|"QGroupBox"
block|,
literal|"QHeaderView"
block|,
literal|"QInputDialog"
block|,
literal|"QLCDNumber"
block|,
literal|"QLabel"
block|,
literal|"QLineEdit"
block|,
literal|"QListView"
block|,
literal|"QListWidget"
block|,
literal|"QMainWindow"
block|,
literal|"QMdiArea"
block|,
literal|"QMdiSubWindow"
block|,
literal|"QMenu"
block|,
literal|"QMenuBar"
block|,
literal|"QMessageBox"
block|,
literal|"QOpenGLWidget"
block|,
literal|"QPlainTextEdit"
block|,
literal|"QProgressBar"
block|,
literal|"QProgressDialog"
block|,
literal|"QPushButton"
block|,
literal|"QRadioButton"
block|,
literal|"QRubberBand"
block|,
literal|"QScrollArea"
block|,
literal|"QScrollBar"
block|,
literal|"QSlider"
block|,
literal|"QSpinBox"
block|,
literal|"QSplashScreen"
block|,
literal|"QSplitter"
block|,
literal|"QStackedWidget"
block|,
literal|"QStatusBar"
block|,
literal|"QTabBar"
block|,
literal|"QTabWidget"
block|,
literal|"QTableView"
block|,
literal|"QTableWidget"
block|,
literal|"QTextBrowser"
block|,
literal|"QTextEdit"
block|,
literal|"QTimeEdit"
block|,
literal|"QToolBar"
block|,
literal|"QToolBox"
block|,
literal|"QToolButton"
block|,
literal|"QTreeView"
block|,
literal|"QTreeWidget"
block|,
literal|"QWidget"
block|,
literal|"QWizard"
block|,
literal|"QWizardPage"
block|}
decl_stmt|;
DECL|function|isQtWidget
specifier|static
name|bool
name|isQtWidget
parameter_list|(
specifier|const
name|char
modifier|*
name|className
parameter_list|)
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|,
name|count
init|=
sizeof|sizeof
argument_list|(
name|qtWidgetClasses
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|qtWidgetClasses
index|[
literal|0
index|]
argument_list|)
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|!
name|qstrcmp
argument_list|(
name|className
argument_list|,
name|qtWidgetClasses
index|[
name|i
index|]
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|formatWidgetClass
specifier|static
name|void
name|formatWidgetClass
parameter_list|(
name|QTextStream
modifier|&
name|str
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|w
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|str
operator|<<
name|mo
operator|->
name|className
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|isQtWidget
argument_list|(
name|mo
operator|->
name|className
argument_list|()
argument_list|)
condition|)
block|{
name|mo
operator|=
name|mo
operator|->
name|superClass
argument_list|()
expr_stmt|;
name|str
operator|<<
literal|':'
operator|<<
name|mo
operator|->
name|className
argument_list|()
expr_stmt|;
block|}
specifier|const
name|QString
name|on
init|=
name|w
operator|->
name|objectName
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|on
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|<<
literal|"/\""
operator|<<
name|on
operator|<<
literal|'"'
expr_stmt|;
block|}
DECL|function|dumpWidgetRecursion
specifier|static
name|void
name|dumpWidgetRecursion
parameter_list|(
name|QTextStream
modifier|&
name|str
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|,
name|FormatWindowOptions
name|options
parameter_list|,
name|int
name|depth
init|=
literal|0
parameter_list|)
block|{
name|indentStream
argument_list|(
name|str
argument_list|,
literal|2
operator|*
name|depth
argument_list|)
expr_stmt|;
name|formatWidgetClass
argument_list|(
name|str
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|str
operator|<<
literal|' '
operator|<<
operator|(
name|w
operator|->
name|isVisible
argument_list|()
condition|?
literal|"[visible] "
else|:
literal|"[hidden] "
operator|)
expr_stmt|;
if|if
condition|(
specifier|const
name|WId
name|nativeWinId
init|=
name|w
operator|->
name|internalWinId
argument_list|()
condition|)
name|str
operator|<<
literal|"[native: "
operator|<<
name|hex
operator|<<
name|showbase
operator|<<
name|nativeWinId
operator|<<
name|dec
operator|<<
name|noshowbase
operator|<<
literal|"] "
expr_stmt|;
if|if
condition|(
name|w
operator|->
name|isWindow
argument_list|()
condition|)
name|str
operator|<<
literal|"[top] "
expr_stmt|;
name|str
operator|<<
operator|(
name|w
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Mapped
argument_list|)
condition|?
literal|"[mapped] "
else|:
literal|"[not mapped] "
operator|)
expr_stmt|;
if|if
condition|(
name|w
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_DontCreateNativeAncestors
argument_list|)
condition|)
name|str
operator|<<
literal|"[NoNativeAncestors] "
expr_stmt|;
if|if
condition|(
specifier|const
name|int
name|states
init|=
name|w
operator|->
name|windowState
argument_list|()
condition|)
name|str
operator|<<
literal|"windowState="
operator|<<
name|hex
operator|<<
name|showbase
operator|<<
name|states
operator|<<
name|dec
operator|<<
name|noshowbase
operator|<<
literal|' '
expr_stmt|;
name|formatRect
argument_list|(
name|str
argument_list|,
name|w
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|w
operator|->
name|isWindow
argument_list|()
condition|)
block|{
specifier|const
name|QRect
name|normalGeometry
init|=
name|w
operator|->
name|normalGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|normalGeometry
operator|.
name|isValid
argument_list|()
operator|&&
operator|!
name|normalGeometry
operator|.
name|isEmpty
argument_list|()
operator|&&
name|normalGeometry
operator|!=
name|w
operator|->
name|geometry
argument_list|()
condition|)
block|{
name|str
operator|<<
literal|" normal="
expr_stmt|;
name|formatRect
argument_list|(
name|str
argument_list|,
name|w
operator|->
name|normalGeometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
operator|(
name|options
operator|&
name|DontPrintWindowFlags
operator|)
condition|)
block|{
name|str
operator|<<
literal|' '
expr_stmt|;
name|formatWindowFlags
argument_list|(
name|str
argument_list|,
name|w
operator|->
name|windowFlags
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|options
operator|&
name|PrintSizeConstraints
condition|)
block|{
name|str
operator|<<
literal|' '
expr_stmt|;
specifier|const
name|QSize
name|minimumSize
init|=
name|w
operator|->
name|minimumSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|minimumSize
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|||
name|minimumSize
operator|.
name|height
argument_list|()
operator|>
literal|0
condition|)
name|str
operator|<<
literal|"minimumSize="
operator|<<
name|minimumSize
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|minimumSize
operator|.
name|height
argument_list|()
operator|<<
literal|' '
expr_stmt|;
specifier|const
name|QSize
name|sizeHint
init|=
name|w
operator|->
name|sizeHint
argument_list|()
decl_stmt|;
specifier|const
name|QSize
name|minimumSizeHint
init|=
name|w
operator|->
name|minimumSizeHint
argument_list|()
decl_stmt|;
if|if
condition|(
name|minimumSizeHint
operator|.
name|isValid
argument_list|()
operator|&&
operator|!
operator|(
name|sizeHint
operator|.
name|isValid
argument_list|()
operator|&&
name|minimumSizeHint
operator|==
name|sizeHint
operator|)
condition|)
name|str
operator|<<
literal|"minimumSizeHint="
operator|<<
name|minimumSizeHint
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|minimumSizeHint
operator|.
name|height
argument_list|()
operator|<<
literal|' '
expr_stmt|;
if|if
condition|(
name|sizeHint
operator|.
name|isValid
argument_list|()
condition|)
name|str
operator|<<
literal|"sizeHint="
operator|<<
name|sizeHint
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|sizeHint
operator|.
name|height
argument_list|()
operator|<<
literal|' '
expr_stmt|;
specifier|const
name|QSize
name|maximumSize
init|=
name|w
operator|->
name|maximumSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|maximumSize
operator|.
name|width
argument_list|()
operator|<
name|QWIDGETSIZE_MAX
operator|||
name|maximumSize
operator|.
name|height
argument_list|()
operator|<
name|QWIDGETSIZE_MAX
condition|)
name|str
operator|<<
literal|"maximumSize="
operator|<<
name|maximumSize
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|maximumSize
operator|.
name|height
argument_list|()
operator|<<
literal|' '
expr_stmt|;
block|}
name|str
operator|<<
literal|'\n'
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>
literal|0x050000
if|if
condition|(
specifier|const
name|QWindow
modifier|*
name|win
init|=
name|w
operator|->
name|windowHandle
argument_list|()
condition|)
block|{
name|indentStream
argument_list|(
name|str
argument_list|,
literal|2
operator|*
operator|(
literal|1
operator|+
name|depth
operator|)
argument_list|)
expr_stmt|;
name|formatWindow
argument_list|(
name|str
argument_list|,
name|win
argument_list|,
name|options
argument_list|)
expr_stmt|;
name|str
operator|<<
literal|'\n'
expr_stmt|;
block|}
endif|#
directive|endif
comment|// Qt 5
foreach|foreach
control|(
specifier|const
name|QObject
modifier|*
name|co
decl|,
name|w
operator|->
name|children
argument_list|()
control|)
block|{
if|if
condition|(
name|co
operator|->
name|isWidgetType
argument_list|()
condition|)
name|dumpWidgetRecursion
argument_list|(
name|str
argument_list|,
cast|static_cast
argument_list|<
specifier|const
name|QWidget
operator|*
argument_list|>
argument_list|(
name|co
argument_list|)
argument_list|,
name|options
argument_list|,
name|depth
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|dumpAllWidgets
name|void
name|dumpAllWidgets
parameter_list|(
name|FormatWindowOptions
name|options
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|root
parameter_list|)
block|{
name|QString
name|d
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|d
argument_list|)
decl_stmt|;
name|str
operator|<<
literal|"### QWidgets:\n"
expr_stmt|;
name|QWidgetList
name|topLevels
decl_stmt|;
if|if
condition|(
name|root
condition|)
name|topLevels
operator|.
name|append
argument_list|(
cast|const_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|root
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|topLevels
operator|=
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QWidget
modifier|*
name|tw
decl|,
name|topLevels
control|)
name|dumpWidgetRecursion
argument_list|(
name|str
argument_list|,
name|tw
argument_list|,
name|options
argument_list|)
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050400
block|{
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|line
decl|,
name|d
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
control|)
name|qDebug
argument_list|()
operator|.
name|noquote
argument_list|()
operator|<<
name|line
expr_stmt|;
block|}
else|#
directive|else
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|qPrintable
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_namespace
begin_comment
comment|// namespace QtDiag
end_comment
end_unit
