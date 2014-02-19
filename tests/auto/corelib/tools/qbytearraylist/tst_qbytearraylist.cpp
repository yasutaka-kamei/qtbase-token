begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 by Southwest Research Institute (R) ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qbytearraylist.h>
end_include
begin_include
include|#
directive|include
file|<qmetatype.h>
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QByteArrayList
argument_list|)
end_macro
begin_class
DECL|class|tst_QByteArrayList
class|class
name|tst_QByteArrayList
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|join
parameter_list|()
specifier|const
function_decl|;
name|void
name|join_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|joinByteArray
parameter_list|()
specifier|const
function_decl|;
name|void
name|joinByteArray_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|joinChar
parameter_list|()
specifier|const
function_decl|;
name|void
name|joinChar_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|joinEmptiness
parameter_list|()
specifier|const
function_decl|;
name|void
name|operator_plus
parameter_list|()
specifier|const
function_decl|;
name|void
name|operator_plus_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|initializeList
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|join
name|void
name|tst_QByteArrayList
operator|::
name|join
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QByteArrayList
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input
operator|.
name|join
argument_list|()
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|join_data
name|void
name|tst_QByteArrayList
operator|::
name|join_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArrayList
argument_list|>
argument_list|(
literal|"input"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"expectedResult"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QByteArrayList
argument_list|()
operator|<<
name|QByteArray
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|QByteArrayList
argument_list|(
literal|"one"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"one"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|"b"
operator|)
operator|<<
name|QByteArray
argument_list|(
literal|"ab"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data4"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|joinByteArray
name|void
name|tst_QByteArrayList
operator|::
name|joinByteArray
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QByteArrayList
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|separator
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input
operator|.
name|join
argument_list|(
name|separator
argument_list|)
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|joinByteArray_data
name|void
name|tst_QByteArrayList
operator|::
name|joinByteArray_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArrayList
argument_list|>
argument_list|(
literal|"input"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"separator"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"expectedResult"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QByteArrayList
argument_list|()
operator|<<
name|QByteArray
argument_list|()
operator|<<
name|QByteArray
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|QByteArrayList
argument_list|()
operator|<<
name|QByteArray
argument_list|(
literal|"separator"
argument_list|)
operator|<<
name|QByteArray
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QByteArrayList
argument_list|(
literal|"one"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"separator"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"one"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data4"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|"b"
operator|)
operator|<<
name|QByteArray
argument_list|(
literal|" "
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"a b"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data5"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
operator|<<
name|QByteArray
argument_list|(
literal|" "
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"a b c"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data6"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
operator|<<
name|QByteArray
argument_list|()
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data7"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
operator|<<
name|QByteArray
argument_list|(
literal|""
argument_list|)
comment|//empty
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|joinChar
name|void
name|tst_QByteArrayList
operator|::
name|joinChar
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QByteArrayList
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|char
argument_list|,
name|separator
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input
operator|.
name|join
argument_list|(
name|separator
argument_list|)
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|joinChar_data
name|void
name|tst_QByteArrayList
operator|::
name|joinChar_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArrayList
argument_list|>
argument_list|(
literal|"input"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|char
argument_list|>
argument_list|(
literal|"separator"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"expectedResult"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QByteArrayList
argument_list|()
operator|<<
literal|' '
operator|<<
name|QByteArray
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|"b"
operator|)
operator|<<
literal|' '
operator|<<
name|QByteArray
argument_list|(
literal|"a b"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
operator|<<
literal|' '
operator|<<
name|QByteArray
argument_list|(
literal|"a b c"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|joinEmptiness
name|void
name|tst_QByteArrayList
operator|::
name|joinEmptiness
parameter_list|()
specifier|const
block|{
name|QByteArrayList
name|list
decl_stmt|;
name|QByteArray
name|string
init|=
name|list
operator|.
name|join
argument_list|(
name|QByteArray
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|string
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|string
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_plus
name|void
name|tst_QByteArrayList
operator|::
name|operator_plus
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QByteArrayList
argument_list|,
name|a1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArrayList
argument_list|,
name|a2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArrayList
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a1
operator|+
name|a2
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
name|a1
operator|+=
name|a2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|a1
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_plus_data
name|void
name|tst_QByteArrayList
operator|::
name|operator_plus_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArrayList
argument_list|>
argument_list|(
literal|"a1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArrayList
argument_list|>
argument_list|(
literal|"a2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArrayList
argument_list|>
argument_list|(
literal|"expectedResult"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"simpl"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"blank1"
argument_list|)
operator|<<
name|QByteArrayList
argument_list|()
operator|<<
name|QByteArrayList
argument_list|()
operator|<<
name|QByteArrayList
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"blank2"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty1"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|""
operator|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|""
operator|<<
literal|"b"
operator|<<
literal|"c"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty2"
argument_list|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|""
operator|<<
literal|"c"
operator|)
operator|<<
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|""
operator|<<
literal|"c"
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initializeList
name|void
name|tst_QByteArrayList
operator|::
name|initializeList
parameter_list|()
specifier|const
block|{
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
comment|// C++11 support is required
name|QByteArrayList
name|v1
argument_list|{
name|QByteArray
argument_list|(
literal|"hello"
argument_list|)
argument_list|,
literal|"world"
argument_list|,
name|QByteArray
argument_list|(
literal|"plop"
argument_list|)
argument_list|}
decl_stmt|;
name|QCOMPARE
argument_list|(
name|v1
argument_list|,
operator|(
name|QByteArrayList
argument_list|()
operator|<<
literal|"hello"
operator|<<
literal|"world"
operator|<<
literal|"plop"
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v1
argument_list|,
operator|(
name|QByteArrayList
block|{
literal|"hello"
block|,
literal|"world"
block|,
literal|"plop"
block|}
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QByteArrayList
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qbytearraylist.moc"
end_include
end_unit
