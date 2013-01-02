begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qtooltip.h>
end_include
begin_class
DECL|class|tst_QToolTip
class|class
name|tst_QToolTip
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QToolTip
name|tst_QToolTip
parameter_list|()
block|{}
DECL|function|~tst_QToolTip
specifier|virtual
name|~
name|tst_QToolTip
parameter_list|()
block|{}
public|public
name|slots
public|:
DECL|function|initTestCase
name|void
name|initTestCase
parameter_list|()
block|{}
DECL|function|cleanupTestCase
name|void
name|cleanupTestCase
parameter_list|()
block|{}
DECL|function|init
name|void
name|init
parameter_list|()
block|{}
DECL|function|cleanup
name|void
name|cleanup
parameter_list|()
block|{}
private|private
name|slots
private|:
comment|// task-specific tests below me
name|void
name|task183679_data
parameter_list|()
function_decl|;
name|void
name|task183679
parameter_list|()
function_decl|;
name|void
name|whatsThis
parameter_list|()
function_decl|;
name|void
name|setPalette
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|Widget_task183679
class|class
name|Widget_task183679
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|Widget_task183679
name|Widget_task183679
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{}
DECL|function|showDelayedToolTip
name|void
name|showDelayedToolTip
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|QTimer
operator|::
name|singleShot
argument_list|(
name|msecs
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showToolTip
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
private|private
name|slots
private|:
DECL|function|showToolTip
name|void
name|showToolTip
parameter_list|()
block|{
name|QToolTip
operator|::
name|showText
argument_list|(
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|,
literal|"tool tip text"
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Qt::Key
argument_list|)
end_macro
begin_function
DECL|function|task183679_data
name|void
name|tst_QToolTip
operator|::
name|task183679_data
parameter_list|()
block|{
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
literal|"visible"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"non-modifier"
argument_list|)
operator|<<
name|Qt
operator|::
name|Key_A
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Shift"
argument_list|)
operator|<<
name|Qt
operator|::
name|Key_Shift
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Control"
argument_list|)
operator|<<
name|Qt
operator|::
name|Key_Control
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Alt"
argument_list|)
operator|<<
name|Qt
operator|::
name|Key_Alt
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Meta"
argument_list|)
operator|<<
name|Qt
operator|::
name|Key_Meta
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task183679
name|void
name|tst_QToolTip
operator|::
name|task183679
parameter_list|()
block|{
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
name|visible
argument_list|)
expr_stmt|;
name|Widget_task183679
name|widget
decl_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|setActiveWindow
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowActive
argument_list|(
operator|&
name|widget
argument_list|)
argument_list|)
expr_stmt|;
name|widget
operator|.
name|showDelayedToolTip
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|QToolTip
operator|::
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|keyPress
argument_list|(
operator|&
name|widget
argument_list|,
name|key
argument_list|)
expr_stmt|;
comment|// Important: the following delay must be larger than the duration of the timer potentially
comment|// initiated by the key press (currently 300 msecs), but smaller than the minimum
comment|// auto-close timeout (currently 10000 msecs)
name|QTest
operator|::
name|qWait
argument_list|(
literal|1500
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QToolTip
operator|::
name|isVisible
argument_list|()
argument_list|,
name|visible
argument_list|)
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|<QWhatsThis>
end_include
begin_function
DECL|function|whatsThis
name|void
name|tst_QToolTip
operator|::
name|whatsThis
parameter_list|()
block|{
name|qApp
operator|->
name|setStyleSheet
argument_list|(
literal|"QWidget { font-size: 72px; }"
argument_list|)
expr_stmt|;
name|QWhatsThis
operator|::
name|showText
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"THis is text"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|400
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|whatsthis
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|QWidget
modifier|*
name|widget
decl|,
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
control|)
block|{
if|if
condition|(
name|widget
operator|->
name|inherits
argument_list|(
literal|"QWhatsThat"
argument_list|)
condition|)
block|{
name|whatsthis
operator|=
name|widget
expr_stmt|;
break|break;
block|}
block|}
name|QVERIFY
argument_list|(
name|whatsthis
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|whatsthis
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|whatsthis
operator|->
name|height
argument_list|()
operator|>
literal|100
argument_list|)
expr_stmt|;
comment|// Test QTBUG-2416
name|qApp
operator|->
name|setStyleSheet
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPalette
name|void
name|tst_QToolTip
operator|::
name|setPalette
parameter_list|()
block|{
comment|//the previous test may still have a tooltip pending for deletion
name|QVERIFY
argument_list|(
operator|!
name|QToolTip
operator|::
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QToolTip
operator|::
name|showText
argument_list|(
name|QPoint
argument_list|()
argument_list|,
literal|"tool tip text"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|QToolTip
operator|::
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|toolTip
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|QWidget
modifier|*
name|widget
decl|,
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
control|)
block|{
if|if
condition|(
name|widget
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|ToolTip
operator|&&
name|widget
operator|->
name|objectName
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"qtooltip_label"
argument_list|)
condition|)
block|{
name|toolTip
operator|=
name|widget
expr_stmt|;
break|break;
block|}
block|}
name|QVERIFY
argument_list|(
name|toolTip
argument_list|)
expr_stmt|;
name|QTRY_VERIFY
argument_list|(
name|toolTip
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QPalette
name|oldPalette
init|=
name|toolTip
operator|->
name|palette
argument_list|()
decl_stmt|;
name|QPalette
name|newPalette
init|=
name|oldPalette
decl_stmt|;
name|newPalette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|ToolTipBase
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|newPalette
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|ToolTipText
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|QToolTip
operator|::
name|setPalette
argument_list|(
name|newPalette
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|toolTip
operator|->
name|palette
argument_list|()
argument_list|,
name|newPalette
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QToolTip
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtooltip.moc"
end_include
end_unit
