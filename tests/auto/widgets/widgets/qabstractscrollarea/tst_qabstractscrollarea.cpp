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
file|<qabstractscrollarea.h>
end_include
begin_include
include|#
directive|include
file|<qscrollarea.h>
end_include
begin_include
include|#
directive|include
file|<qscrollbar.h>
end_include
begin_include
include|#
directive|include
file|<qlabel.h>
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|<qdialog.h>
end_include
begin_class
DECL|class|tst_QAbstractScrollArea
class|class
name|tst_QAbstractScrollArea
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QAbstractScrollArea
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QAbstractScrollArea
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|scrollBarWidgets
parameter_list|()
function_decl|;
name|void
name|setScrollBars
parameter_list|()
function_decl|;
name|void
name|setScrollBars2
parameter_list|()
function_decl|;
name|void
name|objectNaming
parameter_list|()
function_decl|;
name|void
name|patternBackground
parameter_list|()
function_decl|;
name|void
name|viewportCrash
parameter_list|()
function_decl|;
name|void
name|task214488_layoutDirection_data
parameter_list|()
function_decl|;
name|void
name|task214488_layoutDirection
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QAbstractScrollArea
name|tst_QAbstractScrollArea
operator|::
name|tst_QAbstractScrollArea
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QAbstractScrollArea
name|tst_QAbstractScrollArea
operator|::
name|~
name|tst_QAbstractScrollArea
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|scrollBarWidgets
name|void
name|tst_QAbstractScrollArea
operator|::
name|scrollBarWidgets
parameter_list|()
block|{
name|QWidget
modifier|*
name|w1
init|=
operator|new
name|QWidget
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|w2
init|=
operator|new
name|QWidget
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|w3
init|=
operator|new
name|QWidget
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|Alignment
name|all
init|=
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignRight
operator||
name|Qt
operator|::
name|AlignTop
operator||
name|Qt
operator|::
name|AlignBottom
decl_stmt|;
name|QWidgetList
name|w1List
init|=
name|QWidgetList
argument_list|()
operator|<<
name|w1
decl_stmt|;
name|QWidgetList
name|w2List
init|=
name|QWidgetList
argument_list|()
operator|<<
name|w2
decl_stmt|;
name|QWidgetList
name|w3List
init|=
name|QWidgetList
argument_list|()
operator|<<
name|w3
decl_stmt|;
name|QWidgetList
name|w1w2List
init|=
name|w1List
operator|+
name|w2List
decl_stmt|;
name|QWidgetList
name|allList
init|=
name|w1List
operator|+
name|w2List
operator|+
name|w3List
decl_stmt|;
name|QAbstractScrollArea
name|area
decl_stmt|;
name|area
operator|.
name|show
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|all
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|area
operator|.
name|addScrollBarWidget
argument_list|(
name|w1
argument_list|,
name|Qt
operator|::
name|AlignLeft
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|all
argument_list|)
argument_list|,
name|w1List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
argument_list|,
name|w1List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignTop
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignBottom
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|area
operator|.
name|addScrollBarWidget
argument_list|(
name|w2
argument_list|,
name|Qt
operator|::
name|AlignBottom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|all
argument_list|)
argument_list|,
name|w1w2List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
argument_list|,
name|w1List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignTop
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignBottom
argument_list|)
argument_list|,
name|w2List
argument_list|)
expr_stmt|;
comment|// duplicate add
name|area
operator|.
name|addScrollBarWidget
argument_list|(
name|w2
argument_list|,
name|Qt
operator|::
name|AlignBottom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|all
argument_list|)
argument_list|,
name|w1w2List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
argument_list|,
name|w1List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignTop
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignBottom
argument_list|)
argument_list|,
name|w2List
argument_list|)
expr_stmt|;
comment|//reparent
name|w2
operator|->
name|setParent
argument_list|(
name|w1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|all
argument_list|)
argument_list|,
name|w1List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
argument_list|,
name|w1List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignTop
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignBottom
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
comment|// add after reparent
name|area
operator|.
name|addScrollBarWidget
argument_list|(
name|w2
argument_list|,
name|Qt
operator|::
name|AlignBottom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|all
argument_list|)
argument_list|,
name|w1w2List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
argument_list|,
name|w1List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignTop
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignBottom
argument_list|)
argument_list|,
name|w2List
argument_list|)
expr_stmt|;
comment|// two widgets at Bottom.
name|area
operator|.
name|addScrollBarWidget
argument_list|(
name|w3
argument_list|,
name|Qt
operator|::
name|AlignBottom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|all
argument_list|)
operator|.
name|toSet
argument_list|()
argument_list|,
name|allList
operator|.
name|toSet
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
argument_list|,
name|w1List
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignTop
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignBottom
argument_list|)
operator|.
name|toSet
argument_list|()
argument_list|,
operator|(
name|w2List
operator|+
name|w3List
operator|)
operator|.
name|toSet
argument_list|()
argument_list|)
expr_stmt|;
comment|//delete
operator|delete
name|w1
expr_stmt|;
operator|delete
name|w2
expr_stmt|;
operator|delete
name|w3
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|all
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignTop
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|scrollBarWidgets
argument_list|(
name|Qt
operator|::
name|AlignBottom
argument_list|)
argument_list|,
name|QWidgetList
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setScrollBars
name|void
name|tst_QAbstractScrollArea
operator|::
name|setScrollBars
parameter_list|()
block|{
name|QScrollArea
name|scrollArea
decl_stmt|;
name|scrollArea
operator|.
name|resize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|show
argument_list|()
expr_stmt|;
name|QPointer
argument_list|<
name|QScrollBar
argument_list|>
name|vbar
init|=
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
decl_stmt|;
name|QPointer
argument_list|<
name|QScrollBar
argument_list|>
name|hbar
init|=
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
decl_stmt|;
comment|// Now set properties on the scroll bars
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|setInvertedAppearance
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|setInvertedControls
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|setTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|setRange
argument_list|(
operator|-
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|setPageStep
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|setSingleStep
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|setValue
argument_list|(
literal|43
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|setInvertedAppearance
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|setInvertedControls
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|setTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|setRange
argument_list|(
operator|-
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|setPageStep
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|setSingleStep
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|setValue
argument_list|(
literal|43
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
comment|// Then replace the scroll bars
name|scrollArea
operator|.
name|setVerticalScrollBar
argument_list|(
operator|new
name|QScrollBar
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|setHorizontalScrollBar
argument_list|(
operator|new
name|QScrollBar
argument_list|)
expr_stmt|;
comment|// Check that the old ones were deleted
name|QVERIFY
argument_list|(
operator|!
name|vbar
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|hbar
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
comment|// Check that all properties have been populated
name|QVERIFY
argument_list|(
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|invertedAppearance
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|invertedControls
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|hasTracking
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|minimum
argument_list|()
argument_list|,
operator|-
literal|100
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|maximum
argument_list|()
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|pageStep
argument_list|()
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|singleStep
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|value
argument_list|()
argument_list|,
literal|43
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|invertedAppearance
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|invertedControls
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|hasTracking
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|minimum
argument_list|()
argument_list|,
operator|-
literal|100
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|maximum
argument_list|()
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|pageStep
argument_list|()
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|singleStep
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|value
argument_list|()
argument_list|,
literal|43
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setScrollBars2
name|void
name|tst_QAbstractScrollArea
operator|::
name|setScrollBars2
parameter_list|()
block|{
name|QAbstractScrollArea
name|scrollArea
decl_stmt|;
name|scrollArea
operator|.
name|resize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|QScrollBar
modifier|*
name|hbar
init|=
operator|new
name|QScrollBar
decl_stmt|;
name|scrollArea
operator|.
name|setHorizontalScrollBar
argument_list|(
name|hbar
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
argument_list|,
name|hbar
argument_list|)
expr_stmt|;
name|QScrollBar
modifier|*
name|vbar
init|=
operator|new
name|QScrollBar
decl_stmt|;
name|scrollArea
operator|.
name|setVerticalScrollBar
argument_list|(
name|vbar
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
argument_list|,
name|vbar
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|show
argument_list|()
expr_stmt|;
comment|// Make sure scroll bars are not explicitly hidden by QAbstractScrollArea itself.
name|QVERIFY
argument_list|(
name|hbar
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|vbar
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
comment|// Hide the OLD scroll bar and ensure that the NEW one is hidden.
name|hbar
operator|->
name|hide
argument_list|()
expr_stmt|;
name|scrollArea
operator|.
name|setHorizontalScrollBar
argument_list|(
operator|new
name|QScrollBar
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|vbar
operator|->
name|hide
argument_list|()
expr_stmt|;
name|scrollArea
operator|.
name|setVerticalScrollBar
argument_list|(
operator|new
name|QScrollBar
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
operator|->
name|show
argument_list|()
expr_stmt|;
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
operator|->
name|show
argument_list|()
expr_stmt|;
comment|// Hide the NEW scroll bar and ensure that it's visible
comment|// (because the OLD one is visible).
name|hbar
operator|=
operator|new
name|QScrollBar
expr_stmt|;
name|hbar
operator|->
name|hide
argument_list|()
expr_stmt|;
name|scrollArea
operator|.
name|setHorizontalScrollBar
argument_list|(
name|hbar
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|hbar
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|vbar
operator|=
operator|new
name|QScrollBar
expr_stmt|;
name|vbar
operator|->
name|hide
argument_list|()
expr_stmt|;
name|scrollArea
operator|.
name|setVerticalScrollBar
argument_list|(
name|vbar
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|vbar
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|vbar
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|vbar
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|hbar
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|hbar
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// we need to make sure the viewport internal widget is named
end_comment
begin_comment
comment|// qt_scrollarea_viewport, otherwise we're going to confuse Squish
end_comment
begin_comment
comment|// and friends.
end_comment
begin_function
DECL|function|objectNaming
name|void
name|tst_QAbstractScrollArea
operator|::
name|objectNaming
parameter_list|()
block|{
name|QScrollArea
name|area
decl_stmt|;
name|QCOMPARE
argument_list|(
name|area
operator|.
name|viewport
argument_list|()
operator|->
name|objectName
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"qt_scrollarea_viewport"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|ViewportCrashWidget
class|class
name|ViewportCrashWidget
super|:
specifier|public
name|QDialog
block|{
public|public:
DECL|function|ViewportCrashWidget
name|ViewportCrashWidget
parameter_list|()
block|{
comment|// temprorary set PaintOnScreen to set the nativeChildrenForced flag.
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_PaintOnScreen
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_PaintOnScreen
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DropSiteRegistered
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|startTimer
argument_list|(
literal|2000
argument_list|)
expr_stmt|;
block|}
DECL|function|timerEvent
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
comment|/* event */
parameter_list|)
block|{
comment|// should not crash.
operator|(
name|void
operator|)
operator|new
name|QScrollArea
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|accept
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|viewportCrash
name|void
name|tst_QAbstractScrollArea
operator|::
name|viewportCrash
parameter_list|()
block|{
name|ViewportCrashWidget
name|w
decl_stmt|;
comment|// should not crash
name|w
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|variable|LayoutDirection
name|Q_DECLARE_METATYPE
argument_list|(
name|Qt
operator|::
name|LayoutDirection
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
name|Q_DECLARE_METATYPE
argument_list|(
name|Qt
operator|::
name|Key
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|task214488_layoutDirection_data
name|void
name|tst_QAbstractScrollArea
operator|::
name|task214488_layoutDirection_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|LayoutDirection
argument_list|>
argument_list|(
literal|"dir"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|Key
argument_list|>
argument_list|(
literal|"key"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"lessThan"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LTR left"
argument_list|)
operator|<<
name|Qt
operator|::
name|LeftToRight
operator|<<
name|Qt
operator|::
name|Key_Left
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LTR right"
argument_list|)
operator|<<
name|Qt
operator|::
name|LeftToRight
operator|<<
name|Qt
operator|::
name|Key_Right
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"RTL left"
argument_list|)
operator|<<
name|Qt
operator|::
name|RightToLeft
operator|<<
name|Qt
operator|::
name|Key_Left
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"RTL right"
argument_list|)
operator|<<
name|Qt
operator|::
name|RightToLeft
operator|<<
name|Qt
operator|::
name|Key_Right
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task214488_layoutDirection
name|void
name|tst_QAbstractScrollArea
operator|::
name|task214488_layoutDirection
parameter_list|()
block|{
name|QScrollArea
name|scrollArea
decl_stmt|;
name|scrollArea
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|QWidget
name|widget
decl_stmt|;
name|widget
operator|.
name|resize
argument_list|(
literal|600
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|setWidget
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|show
argument_list|()
expr_stmt|;
name|QScrollBar
modifier|*
name|hbar
init|=
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
decl_stmt|;
name|hbar
operator|->
name|setValue
argument_list|(
operator|(
name|hbar
operator|->
name|minimum
argument_list|()
operator|+
name|hbar
operator|->
name|maximum
argument_list|()
operator|)
operator|/
literal|2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|LayoutDirection
argument_list|,
name|dir
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|Key
argument_list|,
name|key
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|lessThan
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|setLayoutDirection
argument_list|(
name|dir
argument_list|)
expr_stmt|;
name|int
name|refValue
init|=
name|hbar
operator|->
name|value
argument_list|()
decl_stmt|;
name|qApp
operator|->
name|sendEvent
argument_list|(
operator|&
name|scrollArea
argument_list|,
operator|new
name|QKeyEvent
argument_list|(
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|key
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lessThan
condition|?
operator|(
name|hbar
operator|->
name|value
argument_list|()
operator|<
name|refValue
operator|)
else|:
operator|(
name|hbar
operator|->
name|value
argument_list|()
operator|>
name|refValue
operator|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|patternBackground
name|void
name|tst_QAbstractScrollArea
operator|::
name|patternBackground
parameter_list|()
block|{
name|QWidget
name|topLevel
decl_stmt|;
name|QScrollArea
name|scrollArea
argument_list|(
operator|&
name|topLevel
argument_list|)
decl_stmt|;
name|scrollArea
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|QWidget
name|widget
decl_stmt|;
name|widget
operator|.
name|resize
argument_list|(
literal|600
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|setWidget
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
name|topLevel
operator|.
name|show
argument_list|()
expr_stmt|;
name|QLinearGradient
name|linearGrad
argument_list|(
name|QPointF
argument_list|(
literal|250
argument_list|,
literal|250
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
argument_list|)
decl_stmt|;
name|linearGrad
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|yellow
argument_list|)
expr_stmt|;
name|linearGrad
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|QBrush
name|bg
argument_list|(
name|linearGrad
argument_list|)
decl_stmt|;
name|scrollArea
operator|.
name|viewport
argument_list|()
operator|->
name|setPalette
argument_list|(
name|QPalette
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
name|bg
argument_list|,
name|bg
argument_list|,
name|bg
argument_list|,
name|bg
argument_list|,
name|bg
argument_list|,
name|bg
argument_list|,
name|bg
argument_list|,
name|bg
argument_list|)
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setPalette
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QImage
name|image
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
name|scrollArea
operator|.
name|render
argument_list|(
operator|&
name|image
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
name|QPoint
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|)
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|yellow
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
name|QScrollBar
modifier|*
name|hbar
init|=
name|scrollArea
operator|.
name|horizontalScrollBar
argument_list|()
decl_stmt|;
name|hbar
operator|->
name|setValue
argument_list|(
name|hbar
operator|->
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
name|QScrollBar
modifier|*
name|vbar
init|=
name|scrollArea
operator|.
name|verticalScrollBar
argument_list|()
decl_stmt|;
name|vbar
operator|->
name|setValue
argument_list|(
name|vbar
operator|->
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|scrollArea
operator|.
name|render
argument_list|(
operator|&
name|image
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
operator|.
name|pixel
argument_list|(
name|QPoint
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|)
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QAbstractScrollArea
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qabstractscrollarea.moc"
end_include
end_unit
