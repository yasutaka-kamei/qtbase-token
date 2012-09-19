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
file|<qqueue.h>
end_include
begin_class
DECL|class|tst_QQueue
class|class
name|tst_QQueue
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|enqueue_dequeue_data
parameter_list|()
function_decl|;
name|void
name|enqueue_dequeue
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|enqueue_dequeue_data
name|void
name|tst_QQueue
operator|::
name|enqueue_dequeue_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"num_items"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1"
argument_list|)
operator|<<
literal|11
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2"
argument_list|)
operator|<<
literal|211
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3"
argument_list|)
operator|<<
literal|1024
operator|+
literal|211
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enqueue_dequeue
name|void
name|tst_QQueue
operator|::
name|enqueue_dequeue
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|num_items
argument_list|)
expr_stmt|;
name|int
modifier|*
name|values
init|=
operator|new
name|int
index|[
name|num_items
index|]
decl_stmt|;
name|QQueue
argument_list|<
name|int
argument_list|>
name|queue_v
decl_stmt|;
name|QQueue
argument_list|<
name|int
modifier|*
argument_list|>
name|queue_p
decl_stmt|;
name|QVERIFY
argument_list|(
name|queue_v
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|queue_p
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|num_items
condition|;
name|i
operator|++
control|)
block|{
name|values
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
name|queue_p
operator|.
name|enqueue
argument_list|(
name|values
operator|+
name|i
argument_list|)
expr_stmt|;
name|queue_v
operator|.
name|enqueue
argument_list|(
name|values
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
operator|!
name|queue_p
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|queue_v
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|num_items
condition|;
name|i
operator|++
control|)
block|{
name|int
name|v
decl_stmt|,
modifier|*
name|p
decl_stmt|;
name|v
operator|=
name|queue_v
operator|.
name|head
argument_list|()
expr_stmt|;
name|p
operator|=
name|queue_p
operator|.
name|head
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|*
name|p
argument_list|,
name|v
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|v
operator|=
name|queue_v
operator|.
name|dequeue
argument_list|()
expr_stmt|;
name|p
operator|=
name|queue_p
operator|.
name|dequeue
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|*
name|p
argument_list|,
name|v
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v
argument_list|,
name|values
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|queue_v
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|queue_p
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|values
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QQueue
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qqueue.moc"
end_include
end_unit
