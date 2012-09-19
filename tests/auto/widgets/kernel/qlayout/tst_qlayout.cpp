begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qboxlayout.h>
end_include
begin_include
include|#
directive|include
file|<qmenubar.h>
end_include
begin_include
include|#
directive|include
file|<qdialog.h>
end_include
begin_include
include|#
directive|include
file|<qsizegrip.h>
end_include
begin_include
include|#
directive|include
file|<qlabel.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QFrame>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWindowsStyle>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QSizePolicy>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QComboBox>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QRadioButton>
end_include
begin_include
include|#
directive|include
file|<private/qlayoutengine_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<QtWidgets/QMacStyle>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QLayout
class|class
name|tst_QLayout
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QLayout
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QLayout
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|geometry
parameter_list|()
function_decl|;
name|void
name|smartMaxSize
parameter_list|()
function_decl|;
name|void
name|setLayoutBugs
parameter_list|()
function_decl|;
name|void
name|setContentsMargins
parameter_list|()
function_decl|;
name|void
name|layoutItemRect
parameter_list|()
function_decl|;
name|void
name|warnIfWrongParent
parameter_list|()
function_decl|;
name|void
name|controlTypes
parameter_list|()
function_decl|;
name|void
name|controlTypes2
parameter_list|()
function_decl|;
name|void
name|adjustSizeShouldMakeSureLayoutIsActivated
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QLayout
name|tst_QLayout
operator|::
name|tst_QLayout
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QLayout
name|tst_QLayout
operator|::
name|~
name|tst_QLayout
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QLayout
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QBoxLayout
name|obj1
argument_list|(
name|QBoxLayout
operator|::
name|LeftToRight
argument_list|)
decl_stmt|;
comment|// QWidget * QLayout::menuBar()
comment|// void QLayout::setMenuBar(QWidget *)
name|QMenuBar
modifier|*
name|var1
init|=
operator|new
name|QMenuBar
argument_list|()
decl_stmt|;
name|obj1
operator|.
name|setMenuBar
argument_list|(
name|var1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|var1
argument_list|)
argument_list|,
name|obj1
operator|.
name|menuBar
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMenuBar
argument_list|(
operator|(
name|QWidget
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QWidget
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|menuBar
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|var1
expr_stmt|;
block|}
end_function
begin_class
DECL|class|SizeHinterFrame
class|class
name|SizeHinterFrame
super|:
specifier|public
name|QFrame
block|{
public|public:
DECL|function|SizeHinterFrame
name|SizeHinterFrame
parameter_list|(
specifier|const
name|QSize
modifier|&
name|sh
parameter_list|,
specifier|const
name|QSize
modifier|&
name|msh
init|=
name|QSize
argument_list|()
parameter_list|)
member_init_list|:
name|QFrame
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|sh
argument_list|(
name|sh
argument_list|)
member_init_list|,
name|msh
argument_list|(
name|msh
argument_list|)
block|{
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|Box
operator||
name|QFrame
operator|::
name|Plain
argument_list|)
expr_stmt|;
block|}
DECL|function|setSizeHint
name|void
name|setSizeHint
parameter_list|(
specifier|const
name|QSize
modifier|&
name|s
parameter_list|)
block|{
name|sh
operator|=
name|s
expr_stmt|;
block|}
DECL|function|sizeHint
name|QSize
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|sh
return|;
block|}
DECL|function|minimumSizeHint
name|QSize
name|minimumSizeHint
parameter_list|()
specifier|const
block|{
return|return
name|msh
return|;
block|}
private|private:
DECL|member|sh
name|QSize
name|sh
decl_stmt|;
DECL|member|msh
name|QSize
name|msh
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|geometry
name|void
name|tst_QLayout
operator|::
name|geometry
parameter_list|()
block|{
comment|// For QWindowsStyle we know that QWidgetItem::geometry() and QWidget::geometry()
comment|// should be the same.
name|QApplication
operator|::
name|setStyle
argument_list|(
operator|new
name|QWindowsStyle
argument_list|)
expr_stmt|;
name|QWidget
name|topLevel
decl_stmt|;
name|QWidget
name|w
argument_list|(
operator|&
name|topLevel
argument_list|)
decl_stmt|;
name|QVBoxLayout
name|layout
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|SizeHinterFrame
name|widget
argument_list|(
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
decl_stmt|;
name|layout
operator|.
name|addWidget
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
name|QLayoutItem
modifier|*
name|item
init|=
name|layout
operator|.
name|itemAt
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|topLevel
operator|.
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|110
argument_list|,
literal|110
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|110
argument_list|,
literal|110
argument_list|)
argument_list|)
expr_stmt|;
name|widget
operator|.
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
name|widget
operator|.
name|setMaximumSize
argument_list|(
name|QSize
argument_list|(
literal|90
argument_list|,
literal|90
argument_list|)
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setSizeHint
argument_list|(
name|QSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|item
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|90
argument_list|,
literal|90
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|smartMaxSize
name|void
name|tst_QLayout
operator|::
name|smartMaxSize
parameter_list|()
block|{
name|QVector
argument_list|<
name|int
argument_list|>
name|expectedWidths
decl_stmt|;
name|QFile
name|f
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"baseline/smartmaxsize"
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QTextStream
name|stream
argument_list|(
operator|&
name|f
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|stream
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|line
init|=
name|stream
operator|.
name|readLine
argument_list|(
literal|200
argument_list|)
decl_stmt|;
name|expectedWidths
operator|.
name|append
argument_list|(
name|line
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|,
literal|6
argument_list|,
operator|-
literal|1
argument_list|,
name|QString
operator|::
name|SectionSkipEmpty
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
name|int
name|sizeCombinations
index|[]
init|=
block|{
literal|0
block|,
literal|10
block|,
literal|20
block|,
name|QWIDGETSIZE_MAX
block|}
decl_stmt|;
name|QSizePolicy
operator|::
name|Policy
name|policies
index|[]
init|=
block|{
name|QSizePolicy
operator|::
name|Fixed
block|,
name|QSizePolicy
operator|::
name|Minimum
block|,
name|QSizePolicy
operator|::
name|Maximum
block|,
name|QSizePolicy
operator|::
name|Preferred
block|,
name|QSizePolicy
operator|::
name|Expanding
block|,
name|QSizePolicy
operator|::
name|MinimumExpanding
block|,
name|QSizePolicy
operator|::
name|Ignored
block|}
decl_stmt|;
name|Qt
operator|::
name|Alignment
name|alignments
index|[]
init|=
block|{
literal|0
block|,
name|Qt
operator|::
name|AlignLeft
block|,
name|Qt
operator|::
name|AlignRight
block|,
name|Qt
operator|::
name|AlignHCenter
block|}
decl_stmt|;
name|int
name|expectedIndex
init|=
literal|0
decl_stmt|;
name|int
name|regressionCount
init|=
literal|0
decl_stmt|;
for|for
control|(
name|size_t
name|p
init|=
literal|0
init|;
name|p
operator|<
sizeof|sizeof
argument_list|(
name|policies
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|QSizePolicy
operator|::
name|Policy
argument_list|)
condition|;
operator|++
name|p
control|)
block|{
name|QSizePolicy
name|sizePolicy
decl_stmt|;
name|sizePolicy
operator|.
name|setHorizontalPolicy
argument_list|(
name|policies
index|[
name|p
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|min
init|=
literal|0
init|;
name|min
operator|<
sizeof|sizeof
argument_list|(
name|sizeCombinations
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|;
operator|++
name|min
control|)
block|{
name|int
name|minSize
init|=
name|sizeCombinations
index|[
name|min
index|]
decl_stmt|;
for|for
control|(
name|size_t
name|max
init|=
literal|0
init|;
name|max
operator|<
sizeof|sizeof
argument_list|(
name|sizeCombinations
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|;
operator|++
name|max
control|)
block|{
name|int
name|maxSize
init|=
name|sizeCombinations
index|[
name|max
index|]
decl_stmt|;
for|for
control|(
name|size_t
name|sh
init|=
literal|0
init|;
name|sh
operator|<
sizeof|sizeof
argument_list|(
name|sizeCombinations
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|;
operator|++
name|sh
control|)
block|{
name|int
name|sizeHint
init|=
name|sizeCombinations
index|[
name|sh
index|]
decl_stmt|;
for|for
control|(
name|size_t
name|a
init|=
literal|0
init|;
name|a
operator|<
sizeof|sizeof
argument_list|(
name|alignments
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|;
operator|++
name|a
control|)
block|{
name|Qt
operator|::
name|Alignment
name|align
init|=
name|alignments
index|[
name|a
index|]
decl_stmt|;
name|QSize
name|sz
init|=
name|qSmartMaxSize
argument_list|(
name|QSize
argument_list|(
name|sizeHint
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QSize
argument_list|(
name|minSize
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QSize
argument_list|(
name|maxSize
argument_list|,
literal|1
argument_list|)
argument_list|,
name|sizePolicy
argument_list|,
name|align
argument_list|)
decl_stmt|;
name|int
name|width
init|=
name|sz
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|expectedWidth
init|=
name|expectedWidths
index|[
name|expectedIndex
index|]
decl_stmt|;
if|if
condition|(
name|width
operator|!=
name|expectedWidth
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"error at index"
operator|<<
name|expectedIndex
operator|<<
literal|":"
operator|<<
name|sizePolicy
operator|.
name|horizontalPolicy
argument_list|()
operator|<<
name|align
operator|<<
name|minSize
operator|<<
name|sizeHint
operator|<<
name|maxSize
operator|<<
name|width
expr_stmt|;
operator|++
name|regressionCount
expr_stmt|;
block|}
operator|++
name|expectedIndex
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
name|QCOMPARE
argument_list|(
name|regressionCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setLayoutBugs
name|void
name|tst_QLayout
operator|::
name|setLayoutBugs
parameter_list|()
block|{
name|QWidget
name|widget
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hBoxLayout
init|=
operator|new
name|QHBoxLayout
argument_list|(
operator|&
name|widget
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|6
condition|;
operator|++
name|i
control|)
block|{
name|QPushButton
modifier|*
name|pushButton
init|=
operator|new
name|QPushButton
argument_list|(
literal|"Press me!"
argument_list|,
operator|&
name|widget
argument_list|)
decl_stmt|;
name|hBoxLayout
operator|->
name|addWidget
argument_list|(
name|pushButton
argument_list|)
expr_stmt|;
block|}
name|widget
operator|.
name|setLayout
argument_list|(
name|hBoxLayout
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|widget
operator|.
name|layout
argument_list|()
operator|==
name|hBoxLayout
argument_list|)
expr_stmt|;
name|QWidget
name|containerWidget
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|containerWidget
operator|.
name|setLayout
argument_list|(
name|widget
operator|.
name|layout
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|widget
operator|.
name|layout
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|containerWidget
operator|.
name|layout
argument_list|()
operator|==
name|hBoxLayout
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|MyLayout
class|class
name|MyLayout
super|:
specifier|public
name|QLayout
block|{
public|public:
DECL|function|MyLayout
name|MyLayout
parameter_list|()
member_init_list|:
name|invalidated
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|invalidate
specifier|virtual
name|void
name|invalidate
parameter_list|()
block|{
name|invalidated
operator|=
literal|true
expr_stmt|;
block|}
DECL|member|invalidated
name|bool
name|invalidated
decl_stmt|;
DECL|function|sizeHint
name|QSize
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|()
return|;
block|}
DECL|function|addItem
name|void
name|addItem
parameter_list|(
name|QLayoutItem
modifier|*
parameter_list|)
block|{}
DECL|function|itemAt
name|QLayoutItem
modifier|*
name|itemAt
parameter_list|(
name|int
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
DECL|function|takeAt
name|QLayoutItem
modifier|*
name|takeAt
parameter_list|(
name|int
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
DECL|function|count
name|int
name|count
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|setContentsMargins
name|void
name|tst_QLayout
operator|::
name|setContentsMargins
parameter_list|()
block|{
name|MyLayout
name|layout
decl_stmt|;
name|layout
operator|.
name|invalidated
operator|=
literal|false
expr_stmt|;
name|int
name|left
decl_stmt|,
name|top
decl_stmt|,
name|right
decl_stmt|,
name|bottom
decl_stmt|;
name|layout
operator|.
name|setContentsMargins
argument_list|(
literal|52
argument_list|,
literal|53
argument_list|,
literal|54
argument_list|,
literal|55
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layout
operator|.
name|invalidated
argument_list|)
expr_stmt|;
name|layout
operator|.
name|invalidated
operator|=
literal|false
expr_stmt|;
name|layout
operator|.
name|getContentsMargins
argument_list|(
operator|&
name|left
argument_list|,
operator|&
name|top
argument_list|,
operator|&
name|right
argument_list|,
operator|&
name|bottom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|left
argument_list|,
literal|52
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|top
argument_list|,
literal|53
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|right
argument_list|,
literal|54
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bottom
argument_list|,
literal|55
argument_list|)
expr_stmt|;
name|layout
operator|.
name|setContentsMargins
argument_list|(
literal|52
argument_list|,
literal|53
argument_list|,
literal|54
argument_list|,
literal|55
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|layout
operator|.
name|invalidated
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|EventReceiver
class|class
name|EventReceiver
super|:
specifier|public
name|QObject
block|{
public|public:
DECL|function|eventFilter
name|bool
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|watched
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Show
condition|)
block|{
name|geom
operator|=
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|watched
argument_list|)
operator|->
name|geometry
argument_list|()
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
DECL|member|geom
name|QRect
name|geom
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|layoutItemRect
name|void
name|tst_QLayout
operator|::
name|layoutItemRect
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
if|if
condition|(
name|qobject_cast
argument_list|<
name|QMacStyle
operator|*
argument_list|>
argument_list|(
name|QApplication
operator|::
name|style
argument_list|()
argument_list|)
condition|)
block|{
name|QWidget
modifier|*
name|window
init|=
operator|new
name|QWidget
decl_stmt|;
name|QRadioButton
modifier|*
name|radio
init|=
operator|new
name|QRadioButton
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|QWidgetItem
name|item
argument_list|(
name|radio
argument_list|)
decl_stmt|;
name|EventReceiver
name|eventReceiver
decl_stmt|;
name|radio
operator|->
name|installEventFilter
argument_list|(
operator|&
name|eventReceiver
argument_list|)
expr_stmt|;
name|radio
operator|->
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QSize
name|s
init|=
name|item
operator|.
name|sizeHint
argument_list|()
decl_stmt|;
name|item
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignVCenter
argument_list|)
expr_stmt|;
name|item
operator|.
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|s
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|radio
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
name|radio
operator|->
name|sizeHint
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|radio
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|warnIfWrongParent
name|void
name|tst_QLayout
operator|::
name|warnIfWrongParent
parameter_list|()
block|{
name|QWidget
name|root
decl_stmt|;
name|QHBoxLayout
name|lay
decl_stmt|;
name|lay
operator|.
name|setParent
argument_list|(
operator|&
name|root
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QLayout::parentWidget: A layout can only have another layout as a parent."
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|lay
operator|.
name|parentWidget
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|controlTypes
name|void
name|tst_QLayout
operator|::
name|controlTypes
parameter_list|()
block|{
name|QVBoxLayout
name|layout
decl_stmt|;
name|QCOMPARE
argument_list|(
name|layout
operator|.
name|controlTypes
argument_list|()
argument_list|,
name|QSizePolicy
operator|::
name|DefaultType
argument_list|)
expr_stmt|;
name|QSizePolicy
name|p
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|controlType
argument_list|()
argument_list|,
name|QSizePolicy
operator|::
name|DefaultType
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|controlTypes2
name|void
name|tst_QLayout
operator|::
name|controlTypes2
parameter_list|()
block|{
name|QWidget
decl|main
decl_stmt|;
name|QVBoxLayout
modifier|*
specifier|const
name|layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
operator|&
expr|main
argument_list|)
decl_stmt|;
name|layout
operator|->
name|setMargin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QComboBox
modifier|*
name|combo
init|=
operator|new
name|QComboBox
argument_list|(
operator|&
expr|main
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|combo
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layout
operator|->
name|controlTypes
argument_list|()
argument_list|,
name|QSizePolicy
operator|::
name|ComboBox
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|adjustSizeShouldMakeSureLayoutIsActivated
name|void
name|tst_QLayout
operator|::
name|adjustSizeShouldMakeSureLayoutIsActivated
parameter_list|()
block|{
name|QWidget
decl|main
decl_stmt|;
name|QVBoxLayout
modifier|*
specifier|const
name|layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
operator|&
expr|main
argument_list|)
decl_stmt|;
name|layout
operator|->
name|setMargin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|SizeHinterFrame
modifier|*
name|frame
init|=
operator|new
name|SizeHinterFrame
argument_list|(
name|QSize
argument_list|(
literal|200
argument_list|,
literal|10
argument_list|)
argument_list|,
name|QSize
argument_list|(
literal|200
argument_list|,
literal|8
argument_list|)
argument_list|)
decl_stmt|;
name|frame
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|frame
argument_list|)
expr_stmt|;
name|SizeHinterFrame
modifier|*
name|frame2
init|=
operator|new
name|SizeHinterFrame
argument_list|(
name|QSize
argument_list|(
literal|200
argument_list|,
literal|10
argument_list|)
argument_list|,
name|QSize
argument_list|(
literal|200
argument_list|,
literal|8
argument_list|)
argument_list|)
decl_stmt|;
name|frame2
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|frame2
argument_list|)
expr_stmt|;
expr|main
operator|.
name|show
argument_list|()
expr_stmt|;
name|frame2
operator|->
name|hide
argument_list|()
expr_stmt|;
expr|main
operator|.
name|adjustSize
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
expr|main
operator|.
name|size
argument_list|()
argument_list|,
name|QSize
argument_list|(
literal|200
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QLayout
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qlayout.moc"
end_include
end_unit
