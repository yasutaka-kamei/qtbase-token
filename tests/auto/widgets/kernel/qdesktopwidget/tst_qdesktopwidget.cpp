begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QDesktopWidget>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_class
DECL|class|tst_QDesktopWidget
class|class
name|tst_QDesktopWidget
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|numScreens
parameter_list|()
function_decl|;
name|void
name|primaryScreen
parameter_list|()
function_decl|;
name|void
name|screenNumberForQWidget
parameter_list|()
function_decl|;
name|void
name|screenNumberForQPoint
parameter_list|()
function_decl|;
name|void
name|availableGeometry
parameter_list|()
function_decl|;
name|void
name|screenGeometry
parameter_list|()
function_decl|;
name|void
name|topLevels
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|cleanup
name|void
name|tst_QDesktopWidget
operator|::
name|cleanup
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|numScreens
name|void
name|tst_QDesktopWidget
operator|::
name|numScreens
parameter_list|()
block|{
name|QDesktopWidget
name|desktop
decl_stmt|;
name|QVERIFY
argument_list|(
name|desktop
operator|.
name|numScreens
argument_list|()
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|primaryScreen
name|void
name|tst_QDesktopWidget
operator|::
name|primaryScreen
parameter_list|()
block|{
name|QDesktopWidget
name|desktop
decl_stmt|;
name|QVERIFY
argument_list|(
name|desktop
operator|.
name|primaryScreen
argument_list|()
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|desktop
operator|.
name|primaryScreen
argument_list|()
operator|<
name|desktop
operator|.
name|numScreens
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|availableGeometry
name|void
name|tst_QDesktopWidget
operator|::
name|availableGeometry
parameter_list|()
block|{
name|QDesktopWidget
name|desktop
decl_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDesktopWidget::availableGeometry(): Attempt "
literal|"to get the available geometry of a null widget"
argument_list|)
expr_stmt|;
name|desktop
operator|.
name|availableGeometry
argument_list|(
operator|(
name|QWidget
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QRect
name|total
decl_stmt|;
name|QRect
name|available
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
name|desktop
operator|.
name|screenCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|total
operator|=
name|desktop
operator|.
name|screenGeometry
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|available
operator|=
name|desktop
operator|.
name|availableGeometry
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|total
operator|.
name|contains
argument_list|(
name|available
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|total
operator|=
name|desktop
operator|.
name|screenGeometry
argument_list|()
expr_stmt|;
name|available
operator|=
name|desktop
operator|.
name|availableGeometry
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|total
operator|.
name|contains
argument_list|(
name|available
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|desktop
operator|.
name|availableGeometry
argument_list|(
name|desktop
operator|.
name|primaryScreen
argument_list|()
argument_list|)
argument_list|,
name|available
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|desktop
operator|.
name|screenGeometry
argument_list|(
name|desktop
operator|.
name|primaryScreen
argument_list|()
argument_list|)
argument_list|,
name|total
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screenNumberForQWidget
name|void
name|tst_QDesktopWidget
operator|::
name|screenNumberForQWidget
parameter_list|()
block|{
name|QDesktopWidget
name|desktop
decl_stmt|;
name|QCOMPARE
argument_list|(
name|desktop
operator|.
name|screenNumber
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QWidget
name|widget
decl_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|widget
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|widget
operator|.
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|widgetScreen
init|=
name|desktop
operator|.
name|screenNumber
argument_list|(
operator|&
name|widget
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|widgetScreen
operator|>
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|widgetScreen
operator|<
name|desktop
operator|.
name|numScreens
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screenNumberForQPoint
name|void
name|tst_QDesktopWidget
operator|::
name|screenNumberForQPoint
parameter_list|()
block|{
comment|// make sure QDesktopWidget::screenNumber(QPoint) returns the correct screen
name|QDesktopWidget
modifier|*
name|desktopWidget
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
decl_stmt|;
name|QRect
name|allScreens
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
name|desktopWidget
operator|->
name|numScreens
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QRect
name|screenGeometry
init|=
name|desktopWidget
operator|->
name|screenGeometry
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|desktopWidget
operator|->
name|screenNumber
argument_list|(
name|screenGeometry
operator|.
name|center
argument_list|()
argument_list|)
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|allScreens
operator||=
name|screenGeometry
expr_stmt|;
block|}
comment|// make sure QDesktopWidget::screenNumber(QPoint) returns a valid screen for points that aren't on any screen
name|int
name|screen
decl_stmt|;
name|screen
operator|=
name|desktopWidget
operator|->
name|screenNumber
argument_list|(
name|allScreens
operator|.
name|topLeft
argument_list|()
operator|-
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|screen
operator|>=
literal|0
operator|&&
name|screen
operator|<
name|desktopWidget
operator|->
name|numScreens
argument_list|()
argument_list|)
expr_stmt|;
name|screen
operator|=
name|desktopWidget
operator|->
name|screenNumber
argument_list|(
name|allScreens
operator|.
name|topRight
argument_list|()
operator|+
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|screen
operator|>=
literal|0
operator|&&
name|screen
operator|<
name|desktopWidget
operator|->
name|numScreens
argument_list|()
argument_list|)
expr_stmt|;
name|screen
operator|=
name|desktopWidget
operator|->
name|screenNumber
argument_list|(
name|allScreens
operator|.
name|bottomLeft
argument_list|()
operator|-
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|screen
operator|>=
literal|0
operator|&&
name|screen
operator|<
name|desktopWidget
operator|->
name|numScreens
argument_list|()
argument_list|)
expr_stmt|;
name|screen
operator|=
name|desktopWidget
operator|->
name|screenNumber
argument_list|(
name|allScreens
operator|.
name|bottomRight
argument_list|()
operator|+
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|screen
operator|>=
literal|0
operator|&&
name|screen
operator|<
name|desktopWidget
operator|->
name|numScreens
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screenGeometry
name|void
name|tst_QDesktopWidget
operator|::
name|screenGeometry
parameter_list|()
block|{
name|QDesktopWidget
modifier|*
name|desktopWidget
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
decl_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QDesktopWidget::screenGeometry(): Attempt "
literal|"to get the screen geometry of a null widget"
argument_list|)
expr_stmt|;
name|QRect
name|r
init|=
name|desktopWidget
operator|->
name|screenGeometry
argument_list|(
operator|(
name|QWidget
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|r
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QWidget
name|widget
decl_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|widget
argument_list|)
argument_list|)
expr_stmt|;
name|r
operator|=
name|desktopWidget
operator|->
name|screenGeometry
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
name|QRect
name|total
decl_stmt|;
name|QRect
name|available
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
name|desktopWidget
operator|->
name|screenCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|total
operator|=
name|desktopWidget
operator|->
name|screenGeometry
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|available
operator|=
name|desktopWidget
operator|->
name|availableGeometry
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|topLevels
name|void
name|tst_QDesktopWidget
operator|::
name|topLevels
parameter_list|()
block|{
comment|// Desktop widgets/windows should not be listed as top-levels.
name|int
name|topLevelDesktopWidgets
init|=
literal|0
decl_stmt|;
name|int
name|topLevelDesktopWindows
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QWidget
modifier|*
name|w
decl|,
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
control|)
if|if
condition|(
name|w
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
condition|)
name|topLevelDesktopWidgets
operator|++
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QWindow
modifier|*
name|w
decl|,
name|QGuiApplication
operator|::
name|topLevelWindows
argument_list|()
control|)
if|if
condition|(
name|w
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
condition|)
name|topLevelDesktopWindows
operator|++
expr_stmt|;
name|QCOMPARE
argument_list|(
name|topLevelDesktopWidgets
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|topLevelDesktopWindows
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QDesktopWidget
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdesktopwidget.moc"
end_include
end_unit
