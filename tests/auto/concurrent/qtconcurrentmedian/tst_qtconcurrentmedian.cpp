begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtconcurrentmedian.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QtConcurrentMedian
class|class
name|tst_QtConcurrentMedian
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|median_data
parameter_list|()
function_decl|;
name|void
name|median
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|median_data
name|void
name|tst_QtConcurrentMedian
operator|::
name|median_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QList
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|(
literal|"values"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"expectedMedian"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"size=1"
argument_list|)
operator|<<
operator|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|1
operator|)
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"size=2"
argument_list|)
operator|<<
operator|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|3
operator|<<
literal|2
operator|)
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"size=3"
argument_list|)
operator|<<
operator|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|3
operator|<<
literal|1
operator|<<
literal|2
operator|)
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"gcc bug 58800 (nth_element)"
argument_list|)
operator|<<
operator|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|207089
operator|<<
literal|202585
operator|<<
literal|180067
operator|<<
literal|157549
operator|<<
literal|211592
operator|<<
literal|216096
operator|<<
literal|207089
operator|)
operator|<<
literal|207089
expr_stmt|;
block|}
end_function
begin_function
DECL|function|median
name|void
name|tst_QtConcurrentMedian
operator|::
name|median
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|,
name|values
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|expectedMedian
argument_list|)
expr_stmt|;
name|QtConcurrent
operator|::
name|Median
argument_list|<
name|int
argument_list|>
name|m
argument_list|(
name|values
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|int
name|value
decl|,
name|values
control|)
name|m
operator|.
name|addValue
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|median
argument_list|()
argument_list|,
name|expectedMedian
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QtConcurrentMedian
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtconcurrentmedian.moc"
end_include
end_unit
