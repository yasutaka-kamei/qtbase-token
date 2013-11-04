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
file|<QtSql/QtSql>
end_include
begin_include
include|#
directive|include
file|"testsqldriver.h"
end_include
begin_class
DECL|class|tst_QSqlResult
class|class
name|tst_QSqlResult
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSqlResult
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|positionalToNamedBinding
parameter_list|()
function_decl|;
name|void
name|parseOfBoundValues
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSqlResult
name|tst_QSqlResult
operator|::
name|tst_QSqlResult
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|positionalToNamedBinding
name|void
name|tst_QSqlResult
operator|::
name|positionalToNamedBinding
parameter_list|()
block|{
name|TestSqlDriver
name|testDriver
decl_stmt|;
name|TestSqlDriverResult
name|result
argument_list|(
operator|&
name|testDriver
argument_list|)
decl_stmt|;
name|QString
name|query
argument_list|(
literal|"INSERT INTO MYTABLE (ID, NAME, BIRTH) VALUES(?, ?, ?)"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
name|query
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parseOfBoundValues
name|void
name|tst_QSqlResult
operator|::
name|parseOfBoundValues
parameter_list|()
block|{
name|TestSqlDriver
name|testDriver
decl_stmt|;
name|TestSqlDriverResult
name|result
argument_list|(
operator|&
name|testDriver
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT :1 AS \":2\""
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT :1 AS ':2'"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT :1 AS [:2]"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|testDriver
operator|.
name|dbmsType
argument_list|()
operator|==
name|QSqlDriverPrivate
operator|::
name|PostgreSQL
condition|)
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT :1 AS [:2]]]"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|testDriver
operator|.
name|dbmsType
argument_list|()
operator|==
name|QSqlDriverPrivate
operator|::
name|PostgreSQL
condition|)
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT :1 AS [:2]]]]]"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|testDriver
operator|.
name|dbmsType
argument_list|()
operator|==
name|QSqlDriverPrivate
operator|::
name|PostgreSQL
condition|)
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT ? AS \"?\""
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT ? AS '?'"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT ? AS [?]"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|testDriver
operator|.
name|dbmsType
argument_list|()
operator|==
name|QSqlDriverPrivate
operator|::
name|PostgreSQL
condition|)
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT ? AS \"'?\""
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT ? AS '?\"'"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT ? AS '?''?'"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|savePrepare
argument_list|(
literal|"SELECT ? AS [\"?']"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|boundValues
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSqlResult
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsqlresult.moc"
end_include
end_unit
