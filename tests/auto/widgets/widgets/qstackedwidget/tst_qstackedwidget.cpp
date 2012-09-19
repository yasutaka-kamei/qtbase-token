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
file|<qstackedwidget.h>
end_include
begin_include
include|#
directive|include
file|<qpushbutton.h>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_class
DECL|class|tst_QStackedWidget
class|class
name|tst_QStackedWidget
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QStackedWidget
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QStackedWidget
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
name|testMinimumSize
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QStackedWidget
name|tst_QStackedWidget
operator|::
name|tst_QStackedWidget
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QStackedWidget
name|tst_QStackedWidget
operator|::
name|~
name|tst_QStackedWidget
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing that stackedwidget respect the minimum size of it's contents (task 95319)
end_comment
begin_function
DECL|function|testMinimumSize
name|void
name|tst_QStackedWidget
operator|::
name|testMinimumSize
parameter_list|()
block|{
name|QWidget
name|w
decl_stmt|;
name|QStackedWidget
name|sw
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|QPushButton
name|button
argument_list|(
literal|"Text"
argument_list|,
operator|&
name|sw
argument_list|)
decl_stmt|;
name|sw
operator|.
name|addWidget
argument_list|(
operator|&
name|button
argument_list|)
expr_stmt|;
name|QHBoxLayout
name|hboxLayout
decl_stmt|;
name|hboxLayout
operator|.
name|addWidget
argument_list|(
operator|&
name|sw
argument_list|)
expr_stmt|;
name|w
operator|.
name|setLayout
argument_list|(
operator|&
name|hboxLayout
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|minimumSize
argument_list|()
operator|!=
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QStackedWidget
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QStackedWidget
name|obj1
decl_stmt|;
comment|// int QStackedWidget::currentIndex()
comment|// void QStackedWidget::setCurrentIndex(int)
name|obj1
operator|.
name|setCurrentIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|-
literal|1
argument_list|,
name|obj1
operator|.
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentIndex
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|-
literal|1
argument_list|,
name|obj1
operator|.
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentIndex
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|-
literal|1
argument_list|,
name|obj1
operator|.
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
comment|// QWidget * QStackedWidget::currentWidget()
comment|// void QStackedWidget::setCurrentWidget(QWidget *)
name|QWidget
modifier|*
name|var2
init|=
operator|new
name|QWidget
argument_list|()
decl_stmt|;
name|obj1
operator|.
name|addWidget
argument_list|(
name|var2
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setCurrentWidget
argument_list|(
name|var2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var2
argument_list|,
name|obj1
operator|.
name|currentWidget
argument_list|()
argument_list|)
expr_stmt|;
comment|// Disabled, task to fix is 128939.
if|#
directive|if
literal|0
comment|// Layouts assert on any unknown widgets here, 0-pointers included.
comment|// This seems wrong behavior, since the setCurrentIndex(int), which
comment|// is really a convenience function for setCurrentWidget(QWidget*),
comment|// has no problem handling out-of-bounds indices.
comment|// ("convenience function" => "just another way of achieving the
comment|// same goal")
block|obj1.setCurrentWidget((QWidget *)0);     QCOMPARE(obj1.currentWidget(), var2);
endif|#
directive|endif
operator|delete
name|var2
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QStackedWidget
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qstackedwidget.moc"
end_include
end_unit
