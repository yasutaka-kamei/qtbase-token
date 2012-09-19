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
file|<qsize.h>
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QSize
argument_list|)
end_macro
begin_class
DECL|class|tst_QSize
class|class
name|tst_QSize
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|scale
parameter_list|()
function_decl|;
name|void
name|expandedTo
parameter_list|()
function_decl|;
name|void
name|expandedTo_data
parameter_list|()
function_decl|;
name|void
name|boundedTo_data
parameter_list|()
function_decl|;
name|void
name|boundedTo
parameter_list|()
function_decl|;
name|void
name|transpose_data
parameter_list|()
function_decl|;
name|void
name|transpose
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QSize
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QSize
name|obj1
decl_stmt|;
comment|// int QSize::width()
comment|// void QSize::setWidth(int)
name|obj1
operator|.
name|setWidth
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|obj1
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setWidth
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setWidth
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|obj1
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
comment|// int QSize::height()
comment|// void QSize::setHeight(int)
name|obj1
operator|.
name|setHeight
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|obj1
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setHeight
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setHeight
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|obj1
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|QSizeF
name|obj2
decl_stmt|;
comment|// qreal QSizeF::width()
comment|// void QSizeF::setWidth(qreal)
name|obj2
operator|.
name|setWidth
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0.0
argument_list|,
name|obj2
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|obj2
operator|.
name|setWidth
argument_list|(
literal|1.1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|1.1
argument_list|,
name|obj2
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
comment|// qreal QSizeF::height()
comment|// void QSizeF::setHeight(qreal)
name|obj2
operator|.
name|setHeight
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0.0
argument_list|,
name|obj2
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|obj2
operator|.
name|setHeight
argument_list|(
literal|1.1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|1.1
argument_list|,
name|obj2
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scale
name|void
name|tst_QSize
operator|::
name|scale
parameter_list|()
block|{
name|QSize
name|t1
argument_list|(
literal|10
argument_list|,
literal|12
argument_list|)
decl_stmt|;
name|t1
operator|.
name|scale
argument_list|(
literal|60
argument_list|,
literal|60
argument_list|,
name|Qt
operator|::
name|IgnoreAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t1
argument_list|,
name|QSize
argument_list|(
literal|60
argument_list|,
literal|60
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t2
argument_list|(
literal|10
argument_list|,
literal|12
argument_list|)
decl_stmt|;
name|t2
operator|.
name|scale
argument_list|(
literal|60
argument_list|,
literal|60
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t2
argument_list|,
name|QSize
argument_list|(
literal|50
argument_list|,
literal|60
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t3
argument_list|(
literal|10
argument_list|,
literal|12
argument_list|)
decl_stmt|;
name|t3
operator|.
name|scale
argument_list|(
literal|60
argument_list|,
literal|60
argument_list|,
name|Qt
operator|::
name|KeepAspectRatioByExpanding
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t3
argument_list|,
name|QSize
argument_list|(
literal|60
argument_list|,
literal|72
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t4
argument_list|(
literal|12
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|t4
operator|.
name|scale
argument_list|(
literal|60
argument_list|,
literal|60
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t4
argument_list|,
name|QSize
argument_list|(
literal|60
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t5
argument_list|(
literal|12
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|t5
operator|.
name|scale
argument_list|(
literal|60
argument_list|,
literal|60
argument_list|,
name|Qt
operator|::
name|KeepAspectRatioByExpanding
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t5
argument_list|,
name|QSize
argument_list|(
literal|72
argument_list|,
literal|60
argument_list|)
argument_list|)
expr_stmt|;
comment|// test potential int overflow
name|QSize
name|t6
argument_list|(
literal|88473
argument_list|,
literal|88473
argument_list|)
decl_stmt|;
name|t6
operator|.
name|scale
argument_list|(
literal|141817
argument_list|,
literal|141817
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t6
argument_list|,
name|QSize
argument_list|(
literal|141817
argument_list|,
literal|141817
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t7
argument_list|(
literal|800
argument_list|,
literal|600
argument_list|)
decl_stmt|;
name|t7
operator|.
name|scale
argument_list|(
literal|400
argument_list|,
name|INT_MAX
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t7
argument_list|,
name|QSize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t8
argument_list|(
literal|800
argument_list|,
literal|600
argument_list|)
decl_stmt|;
name|t8
operator|.
name|scale
argument_list|(
name|INT_MAX
argument_list|,
literal|150
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t8
argument_list|,
name|QSize
argument_list|(
literal|200
argument_list|,
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t9
argument_list|(
literal|600
argument_list|,
literal|800
argument_list|)
decl_stmt|;
name|t9
operator|.
name|scale
argument_list|(
literal|300
argument_list|,
name|INT_MAX
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t9
argument_list|,
name|QSize
argument_list|(
literal|300
argument_list|,
literal|400
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t10
argument_list|(
literal|600
argument_list|,
literal|800
argument_list|)
decl_stmt|;
name|t10
operator|.
name|scale
argument_list|(
name|INT_MAX
argument_list|,
literal|200
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t10
argument_list|,
name|QSize
argument_list|(
literal|150
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t11
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|t11
operator|.
name|scale
argument_list|(
literal|240
argument_list|,
literal|200
argument_list|,
name|Qt
operator|::
name|IgnoreAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t11
argument_list|,
name|QSize
argument_list|(
literal|240
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t12
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|t12
operator|.
name|scale
argument_list|(
literal|240
argument_list|,
literal|200
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t12
argument_list|,
name|QSize
argument_list|(
literal|240
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|t13
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|t13
operator|.
name|scale
argument_list|(
literal|240
argument_list|,
literal|200
argument_list|,
name|Qt
operator|::
name|KeepAspectRatioByExpanding
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t13
argument_list|,
name|QSize
argument_list|(
literal|240
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|expandedTo_data
name|void
name|tst_QSize
operator|::
name|expandedTo_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"input1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"input2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|10
argument_list|,
literal|12
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|6
argument_list|,
literal|4
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|10
argument_list|,
literal|12
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|6
argument_list|,
literal|4
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|6
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// This should pick the highest of w,h components independently of each other,
comment|// thus the results don't have to be equal to neither input1 nor input2.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|6
argument_list|,
literal|4
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|4
argument_list|,
literal|6
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|6
argument_list|,
literal|6
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|expandedTo
name|void
name|tst_QSize
operator|::
name|expandedTo
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|input1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|input2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input1
operator|.
name|expandedTo
argument_list|(
name|input2
argument_list|)
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundedTo_data
name|void
name|tst_QSize
operator|::
name|boundedTo_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"input1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"input2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|10
argument_list|,
literal|12
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|6
argument_list|,
literal|4
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|6
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|6
argument_list|,
literal|4
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// This should pick the lowest of w,h components independently of each other,
comment|// thus the results don't have to be equal to neither input1 nor input2.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|6
argument_list|,
literal|4
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|4
argument_list|,
literal|6
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundedTo
name|void
name|tst_QSize
operator|::
name|boundedTo
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|input1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|input2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input1
operator|.
name|boundedTo
argument_list|(
name|input2
argument_list|)
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|transpose_data
name|void
name|tst_QSize
operator|::
name|transpose_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"input1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSize
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|10
argument_list|,
literal|12
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|12
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|6
argument_list|,
literal|4
argument_list|)
operator|<<
name|QSize
argument_list|(
literal|4
argument_list|,
literal|6
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|transpose
name|void
name|tst_QSize
operator|::
name|transpose
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|input1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSize
argument_list|,
name|expected
argument_list|)
expr_stmt|;
comment|// transpose() works only inplace and does not return anything, so we must do the operation itself before the compare.
name|input1
operator|.
name|transpose
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input1
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QSize
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsize.moc"
end_include
end_unit
