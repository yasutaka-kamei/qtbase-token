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
file|<qsqlerror.h>
end_include
begin_class
DECL|class|tst_QSqlError
class|class
name|tst_QSqlError
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSqlError
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSqlError
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
name|construction
parameter_list|()
function_decl|;
name|void
name|operators
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSqlError
name|tst_QSqlError
operator|::
name|tst_QSqlError
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSqlError
name|tst_QSqlError
operator|::
name|~
name|tst_QSqlError
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QSqlError
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QSqlError
name|obj1
decl_stmt|;
comment|// ErrorType QSqlError::type()
comment|// void QSqlError::setType(ErrorType)
name|obj1
operator|.
name|setType
argument_list|(
name|QSqlError
operator|::
name|ErrorType
argument_list|(
name|QSqlError
operator|::
name|NoError
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QSqlError
operator|::
name|ErrorType
argument_list|(
name|QSqlError
operator|::
name|NoError
argument_list|)
argument_list|,
name|obj1
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setType
argument_list|(
name|QSqlError
operator|::
name|ErrorType
argument_list|(
name|QSqlError
operator|::
name|ConnectionError
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QSqlError
operator|::
name|ErrorType
argument_list|(
name|QSqlError
operator|::
name|ConnectionError
argument_list|)
argument_list|,
name|obj1
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setType
argument_list|(
name|QSqlError
operator|::
name|ErrorType
argument_list|(
name|QSqlError
operator|::
name|StatementError
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QSqlError
operator|::
name|ErrorType
argument_list|(
name|QSqlError
operator|::
name|StatementError
argument_list|)
argument_list|,
name|obj1
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setType
argument_list|(
name|QSqlError
operator|::
name|ErrorType
argument_list|(
name|QSqlError
operator|::
name|TransactionError
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QSqlError
operator|::
name|ErrorType
argument_list|(
name|QSqlError
operator|::
name|TransactionError
argument_list|)
argument_list|,
name|obj1
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setType
argument_list|(
name|QSqlError
operator|::
name|ErrorType
argument_list|(
name|QSqlError
operator|::
name|UnknownError
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QSqlError
operator|::
name|ErrorType
argument_list|(
name|QSqlError
operator|::
name|UnknownError
argument_list|)
argument_list|,
name|obj1
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
comment|// int QSqlError::number()
comment|// void QSqlError::setNumber(int)
name|obj1
operator|.
name|setNumber
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
name|number
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setNumber
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
name|number
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setNumber
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
name|number
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|construction
name|void
name|tst_QSqlError
operator|::
name|construction
parameter_list|()
block|{
name|QSqlError
name|obj1
argument_list|(
literal|"drivertext"
argument_list|,
literal|"databasetext"
argument_list|,
name|QSqlError
operator|::
name|UnknownError
argument_list|,
literal|123
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|driverText
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"drivertext"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|databaseText
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"databasetext"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|type
argument_list|()
argument_list|,
name|QSqlError
operator|::
name|UnknownError
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|number
argument_list|()
argument_list|,
literal|123
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|isValid
argument_list|()
expr_stmt|;
name|QSqlError
name|obj2
argument_list|(
name|obj1
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|obj2
operator|.
name|driverText
argument_list|()
argument_list|,
name|obj1
operator|.
name|driverText
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj2
operator|.
name|databaseText
argument_list|()
argument_list|,
name|obj1
operator|.
name|databaseText
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj2
operator|.
name|type
argument_list|()
argument_list|,
name|obj1
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj2
operator|.
name|number
argument_list|()
argument_list|,
name|obj1
operator|.
name|number
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|obj2
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QSqlError
name|obj3
init|=
name|obj2
decl_stmt|;
name|QCOMPARE
argument_list|(
name|obj3
operator|.
name|driverText
argument_list|()
argument_list|,
name|obj2
operator|.
name|driverText
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj3
operator|.
name|databaseText
argument_list|()
argument_list|,
name|obj2
operator|.
name|databaseText
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj3
operator|.
name|type
argument_list|()
argument_list|,
name|obj2
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj3
operator|.
name|number
argument_list|()
argument_list|,
name|obj2
operator|.
name|number
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|obj3
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QSqlError
name|obj4
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|obj4
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operators
name|void
name|tst_QSqlError
operator|::
name|operators
parameter_list|()
block|{
name|QSqlError
name|error1
decl_stmt|;
name|QSqlError
name|error2
decl_stmt|;
name|QSqlError
name|error3
decl_stmt|;
name|error1
operator|.
name|setType
argument_list|(
name|QSqlError
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|error2
operator|.
name|setType
argument_list|(
name|QSqlError
operator|::
name|NoError
argument_list|)
expr_stmt|;
name|error3
operator|.
name|setType
argument_list|(
name|QSqlError
operator|::
name|UnknownError
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|error1
operator|==
name|error2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|error1
operator|!=
name|error3
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSqlError
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsqlerror.moc"
end_include
end_unit
