begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_LINUX
end_ifdef
begin_include
include|#
directive|include
file|<pthread.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QMetaType::Type
argument_list|)
end_macro
begin_class
DECL|class|tst_QMetaType
class|class
name|tst_QMetaType
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
parameter_list|(
name|QList
argument_list|<
name|QVariant
argument_list|>
name|prop
name|READ
name|prop
name|WRITE
name|setProp
parameter_list|)
specifier|public
private|:
DECL|function|tst_QMetaType
name|tst_QMetaType
parameter_list|()
block|{
name|propList
operator|<<
literal|42
operator|<<
literal|"Hello"
expr_stmt|;
block|}
DECL|function|prop
name|QList
argument_list|<
name|QVariant
argument_list|>
name|prop
parameter_list|()
specifier|const
block|{
return|return
name|propList
return|;
block|}
DECL|function|setProp
name|void
name|setProp
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QVariant
argument_list|>
modifier|&
name|list
parameter_list|)
block|{
name|propList
operator|=
name|list
expr_stmt|;
block|}
private|private:
DECL|member|propList
name|QList
argument_list|<
name|QVariant
argument_list|>
name|propList
decl_stmt|;
private|private
name|slots
private|:
name|void
name|defined
parameter_list|()
function_decl|;
name|void
name|threadSafety
parameter_list|()
function_decl|;
name|void
name|namespaces
parameter_list|()
function_decl|;
name|void
name|qMetaTypeId
parameter_list|()
function_decl|;
name|void
name|properties
parameter_list|()
function_decl|;
name|void
name|normalizedTypes
parameter_list|()
function_decl|;
name|void
name|typeName_data
parameter_list|()
function_decl|;
name|void
name|typeName
parameter_list|()
function_decl|;
name|void
name|create
parameter_list|()
function_decl|;
name|void
name|typedefs
parameter_list|()
function_decl|;
name|void
name|isRegistered_data
parameter_list|()
function_decl|;
name|void
name|isRegistered
parameter_list|()
function_decl|;
name|void
name|unregisterType
parameter_list|()
function_decl|;
name|void
name|QTBUG11316_registerStreamBuiltin
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_struct
DECL|struct|Foo
DECL|member|i
struct|struct
name|Foo
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|defined
name|void
name|tst_QMetaType
operator|::
name|defined
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|QMetaTypeId2
argument_list|<
name|QString
argument_list|>
operator|::
name|Defined
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|QMetaTypeId2
argument_list|<
name|Foo
argument_list|>
operator|::
name|Defined
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|QMetaTypeId2
argument_list|<
name|void
operator|*
argument_list|>
operator|::
name|Defined
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|QMetaTypeId2
argument_list|<
name|int
operator|*
argument_list|>
operator|::
name|Defined
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_struct
DECL|struct|Bar
struct|struct
name|Bar
block|{
DECL|function|Bar
name|Bar
parameter_list|()
block|{
comment|// check re-entrancy
if|if
condition|(
operator|!
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|qRegisterMetaType
argument_list|<
name|Foo
argument_list|>
argument_list|(
literal|"Foo"
argument_list|)
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: re-entrancy test failed"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
operator|++
name|failureCount
expr_stmt|;
block|}
block|}
public|public:
DECL|member|failureCount
specifier|static
name|int
name|failureCount
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|member|failureCount
name|int
name|Bar
operator|::
name|failureCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|MetaTypeTorturer
class|class
name|MetaTypeTorturer
super|:
specifier|public
name|QThread
block|{
name|Q_OBJECT
protected|protected:
DECL|function|run
name|void
name|run
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|1000
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QByteArray
name|name
init|=
name|QString
argument_list|(
literal|"Bar%1_%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
operator|.
name|arg
argument_list|(
operator|(
name|size_t
operator|)
name|QThread
operator|::
name|currentThreadId
argument_list|()
argument_list|)
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|nm
init|=
name|name
operator|.
name|constData
argument_list|()
decl_stmt|;
name|int
name|tp
init|=
name|qRegisterMetaType
argument_list|<
name|Bar
argument_list|>
argument_list|(
name|nm
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_LINUX
name|pthread_yield
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|tp
argument_list|)
condition|)
block|{
operator|++
name|failureCount
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
name|name
operator|<<
literal|"is not a registered metatype"
expr_stmt|;
block|}
if|if
condition|(
name|QMetaType
operator|::
name|type
argument_list|(
name|nm
argument_list|)
operator|!=
name|tp
condition|)
block|{
operator|++
name|failureCount
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"Wrong metatype returned for"
operator|<<
name|name
expr_stmt|;
block|}
if|if
condition|(
name|QMetaType
operator|::
name|typeName
argument_list|(
name|tp
argument_list|)
operator|!=
name|name
condition|)
block|{
operator|++
name|failureCount
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"Wrong typeName returned for"
operator|<<
name|tp
expr_stmt|;
block|}
name|void
modifier|*
name|buf
init|=
name|QMetaType
operator|::
name|create
argument_list|(
name|tp
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|void
modifier|*
name|buf2
init|=
name|QMetaType
operator|::
name|create
argument_list|(
name|tp
argument_list|,
name|buf
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|buf
condition|)
block|{
operator|++
name|failureCount
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"Null buffer returned by QMetaType::create(tp, 0)"
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|buf2
condition|)
block|{
operator|++
name|failureCount
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"Null buffer returned by QMetaType::create(tp, buf)"
expr_stmt|;
block|}
name|QMetaType
operator|::
name|destroy
argument_list|(
name|tp
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|destroy
argument_list|(
name|tp
argument_list|,
name|buf2
argument_list|)
expr_stmt|;
block|}
block|}
public|public:
DECL|function|MetaTypeTorturer
name|MetaTypeTorturer
parameter_list|()
member_init_list|:
name|failureCount
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|member|failureCount
name|int
name|failureCount
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|threadSafety
name|void
name|tst_QMetaType
operator|::
name|threadSafety
parameter_list|()
block|{
name|MetaTypeTorturer
name|t1
decl_stmt|;
name|MetaTypeTorturer
name|t2
decl_stmt|;
name|MetaTypeTorturer
name|t3
decl_stmt|;
name|t1
operator|.
name|start
argument_list|()
expr_stmt|;
name|t2
operator|.
name|start
argument_list|()
expr_stmt|;
name|t3
operator|.
name|start
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|t1
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t2
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t3
operator|.
name|wait
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t1
operator|.
name|failureCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t2
operator|.
name|failureCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t3
operator|.
name|failureCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|Bar
operator|::
name|failureCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_namespace
DECL|namespace|TestSpace
namespace|namespace
name|TestSpace
block|{
DECL|struct|Foo
DECL|member|d
struct|struct
name|Foo
block|{
name|double
name|d
decl_stmt|;
block|}
struct|;
block|}
end_namespace
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|TestSpace::Foo
argument_list|)
end_macro
begin_function
DECL|function|namespaces
name|void
name|tst_QMetaType
operator|::
name|namespaces
parameter_list|()
block|{
name|TestSpace
operator|::
name|Foo
name|nf
init|=
block|{
literal|11.12
block|}
decl_stmt|;
name|QVariant
name|v
init|=
name|qVariantFromValue
argument_list|(
name|nf
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|qvariant_cast
argument_list|<
name|TestSpace
operator|::
name|Foo
argument_list|>
argument_list|(
name|v
argument_list|)
operator|.
name|d
argument_list|,
literal|11.12
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qMetaTypeId
name|void
name|tst_QMetaType
operator|::
name|qMetaTypeId
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
operator|::
name|qMetaTypeId
argument_list|<
name|QString
argument_list|>
argument_list|()
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|QString
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|::
name|qMetaTypeId
argument_list|<
name|int
argument_list|>
argument_list|()
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|Int
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|::
name|qMetaTypeId
argument_list|<
name|TestSpace
operator|::
name|Foo
argument_list|>
argument_list|()
argument_list|,
name|QMetaType
operator|::
name|type
argument_list|(
literal|"TestSpace::Foo"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|::
name|qMetaTypeId
argument_list|<
name|char
argument_list|>
argument_list|()
argument_list|,
name|QMetaType
operator|::
name|type
argument_list|(
literal|"char"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|::
name|qMetaTypeId
argument_list|<
name|uchar
argument_list|>
argument_list|()
argument_list|,
name|QMetaType
operator|::
name|type
argument_list|(
literal|"unsigned char"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
argument|::qMetaTypeId<signed char>()
argument_list|,
argument|QMetaType::type(
literal|"signed char"
argument|)
argument_list|)
empty_stmt|;
name|QCOMPARE
argument_list|(
operator|::
name|qMetaTypeId
argument_list|<
name|qint8
argument_list|>
argument_list|()
argument_list|,
name|QMetaType
operator|::
name|type
argument_list|(
literal|"qint8"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|properties
name|void
name|tst_QMetaType
operator|::
name|properties
parameter_list|()
block|{
name|qRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|QVariant
argument_list|>
argument_list|>
argument_list|(
literal|"QList<QVariant>"
argument_list|)
expr_stmt|;
name|QVariant
name|v
init|=
name|property
argument_list|(
literal|"prop"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|v
operator|.
name|typeName
argument_list|()
argument_list|,
literal|"QVariantList"
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|values
init|=
name|v
operator|.
name|toList
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|values
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|values
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
literal|42
argument_list|)
expr_stmt|;
name|values
operator|<<
literal|43
operator|<<
literal|"world"
expr_stmt|;
name|QVERIFY
argument_list|(
name|setProperty
argument_list|(
literal|"prop"
argument_list|,
name|values
argument_list|)
argument_list|)
expr_stmt|;
name|v
operator|=
name|property
argument_list|(
literal|"prop"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v
operator|.
name|toList
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function
begin_struct
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
struct|struct
DECL|struct|Whity
DECL|member|t
name|Whity
block|{
name|T
name|t
decl_stmt|;
block|}
struct|;
end_struct
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Whity< int>
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Whity<double>
argument_list|)
end_macro
begin_function
DECL|function|normalizedTypes
name|void
name|tst_QMetaType
operator|::
name|normalizedTypes
parameter_list|()
block|{
name|int
name|WhityIntId
init|=
operator|::
name|qMetaTypeId
argument_list|<
name|Whity
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|()
decl_stmt|;
name|int
name|WhityDoubleId
init|=
operator|::
name|qMetaTypeId
argument_list|<
name|Whity
argument_list|<
name|double
argument_list|>
argument_list|>
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"Whity<int>"
argument_list|)
argument_list|,
name|WhityIntId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|" Whity< int> "
argument_list|)
argument_list|,
name|WhityIntId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"Whity<int>"
argument_list|)
argument_list|,
name|WhityIntId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"Whity<double>"
argument_list|)
argument_list|,
name|WhityDoubleId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|" Whity< double> "
argument_list|)
argument_list|,
name|WhityDoubleId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"Whity<double>"
argument_list|)
argument_list|,
name|WhityDoubleId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qRegisterMetaType
argument_list|<
name|Whity
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|(
literal|" Whity< int> "
argument_list|)
argument_list|,
name|WhityIntId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qRegisterMetaType
argument_list|<
name|Whity
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|(
literal|"Whity<int>"
argument_list|)
argument_list|,
name|WhityIntId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qRegisterMetaType
argument_list|<
name|Whity
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|(
literal|"Whity<int> "
argument_list|)
argument_list|,
name|WhityIntId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qRegisterMetaType
argument_list|<
name|Whity
argument_list|<
name|double
argument_list|>
argument_list|>
argument_list|(
literal|" Whity< double> "
argument_list|)
argument_list|,
name|WhityDoubleId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qRegisterMetaType
argument_list|<
name|Whity
argument_list|<
name|double
argument_list|>
argument_list|>
argument_list|(
literal|"Whity<double>"
argument_list|)
argument_list|,
name|WhityDoubleId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qRegisterMetaType
argument_list|<
name|Whity
argument_list|<
name|double
argument_list|>
argument_list|>
argument_list|(
literal|"Whity<double> "
argument_list|)
argument_list|,
name|WhityDoubleId
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|typeName_data
name|void
name|tst_QMetaType
operator|::
name|typeName_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QMetaType
operator|::
name|Type
argument_list|>
argument_list|(
literal|"aType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"aTypeName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"void"
argument_list|)
operator|<<
name|QMetaType
operator|::
name|Void
operator|<<
literal|"void"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"int"
argument_list|)
operator|<<
name|QMetaType
operator|::
name|Int
operator|<<
literal|"int"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"double"
argument_list|)
operator|<<
name|QMetaType
operator|::
name|Double
operator|<<
literal|"double"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"qlonglong"
argument_list|)
operator|<<
name|QMetaType
operator|::
name|LongLong
operator|<<
literal|"qlonglong"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QRegExp"
argument_list|)
operator|<<
name|QMetaType
operator|::
name|QRegExp
operator|<<
literal|"QRegExp"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"void*"
argument_list|)
operator|<<
name|QMetaType
operator|::
name|VoidStar
operator|<<
literal|"void*"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ulong"
argument_list|)
operator|<<
name|QMetaType
operator|::
name|ULong
operator|<<
literal|"ulong"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QWidget*"
argument_list|)
operator|<<
name|QMetaType
operator|::
name|QWidgetStar
operator|<<
literal|"QWidget*"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|typeName
name|void
name|tst_QMetaType
operator|::
name|typeName
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QMetaType
operator|::
name|Type
argument_list|,
name|aType
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|aTypeName
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|QMetaType
operator|::
name|typeName
argument_list|(
name|aType
argument_list|)
argument_list|)
argument_list|,
name|aTypeName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|create
name|void
name|tst_QMetaType
operator|::
name|create
parameter_list|()
block|{
name|QSize
name|x
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|void
modifier|*
name|size
init|=
name|QMetaType
operator|::
name|create
argument_list|(
name|QMetaType
operator|::
name|QSize
argument_list|,
operator|&
name|x
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QSize
operator|*
argument_list|>
argument_list|(
name|size
argument_list|)
operator|->
name|width
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|destroy
argument_list|(
name|QMetaType
operator|::
name|QSize
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_typedef
DECL|typedef|CustomString
typedef|typedef
name|QString
name|CustomString
typedef|;
end_typedef
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|CustomString
argument_list|)
end_macro
begin_comment
comment|//this line is useless
end_comment
begin_function
DECL|function|typedefs
name|void
name|tst_QMetaType
operator|::
name|typedefs
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"long long"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|LongLong
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"unsigned long long"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|ULongLong
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"qint8"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|Char
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"quint8"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|UChar
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"qint16"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|Short
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"quint16"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|UShort
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"qint32"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|Int
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"quint32"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|UInt
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"qint64"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|LongLong
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"quint64"
argument_list|)
argument_list|,
name|int
argument_list|(
name|QMetaType
operator|::
name|ULongLong
argument_list|)
argument_list|)
expr_stmt|;
comment|// make sure the qreal typeId is the type id of the type it's defined to
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"qreal"
argument_list|)
argument_list|,
operator|::
name|qMetaTypeId
argument_list|<
name|qreal
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|qRegisterMetaType
argument_list|<
name|CustomString
argument_list|>
argument_list|(
literal|"CustomString"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"CustomString"
argument_list|)
argument_list|,
operator|::
name|qMetaTypeId
argument_list|<
name|CustomString
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
typedef|typedef
name|Whity
argument_list|<
name|double
argument_list|>
name|WhityDouble
typedef|;
name|qRegisterMetaType
argument_list|<
name|WhityDouble
argument_list|>
argument_list|(
literal|"WhityDouble"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|type
argument_list|(
literal|"WhityDouble"
argument_list|)
argument_list|,
operator|::
name|qMetaTypeId
argument_list|<
name|WhityDouble
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|IsRegisteredDummyType
class|class
name|IsRegisteredDummyType
block|{
block|}
class|;
end_class
begin_function
DECL|function|isRegistered_data
name|void
name|tst_QMetaType
operator|::
name|isRegistered_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"typeId"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"registered"
argument_list|)
expr_stmt|;
comment|// predefined/custom types
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QMetaType::Void"
argument_list|)
operator|<<
name|int
argument_list|(
name|QMetaType
operator|::
name|Void
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QMetaType::Int"
argument_list|)
operator|<<
name|int
argument_list|(
name|QMetaType
operator|::
name|Int
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|int
name|dummyTypeId
init|=
name|qRegisterMetaType
argument_list|<
name|IsRegisteredDummyType
argument_list|>
argument_list|(
literal|"IsRegisteredDummyType"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"IsRegisteredDummyType"
argument_list|)
operator|<<
name|dummyTypeId
operator|<<
literal|true
expr_stmt|;
comment|// unknown types
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-1"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-42"
argument_list|)
operator|<<
operator|-
literal|42
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"IsRegisteredDummyType + 1"
argument_list|)
operator|<<
operator|(
name|dummyTypeId
operator|+
literal|1
operator|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isRegistered
name|void
name|tst_QMetaType
operator|::
name|isRegistered
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|typeId
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|registered
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|typeId
argument_list|)
argument_list|,
name|registered
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|RegUnreg
class|class
name|RegUnreg
block|{
public|public:
DECL|function|RegUnreg
name|RegUnreg
parameter_list|()
block|{}
empty_stmt|;
DECL|function|RegUnreg
name|RegUnreg
parameter_list|(
specifier|const
name|RegUnreg
modifier|&
parameter_list|)
block|{}
empty_stmt|;
DECL|function|~RegUnreg
name|~
name|RegUnreg
parameter_list|()
block|{}
empty_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|unregisterType
name|void
name|tst_QMetaType
operator|::
name|unregisterType
parameter_list|()
block|{
comment|// cannot unregister standard types
name|int
name|typeId
init|=
name|qRegisterMetaType
argument_list|<
name|QList
argument_list|<
name|QVariant
argument_list|>
argument_list|>
argument_list|(
literal|"QList<QVariant>"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|typeId
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|unregisterType
argument_list|(
literal|"QList<QVariant>"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|typeId
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|// allow unregister user types
name|typeId
operator|=
name|qRegisterMetaType
argument_list|<
name|RegUnreg
argument_list|>
argument_list|(
literal|"RegUnreg"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|typeId
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QMetaType
operator|::
name|unregisterType
argument_list|(
literal|"RegUnreg"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QMetaType
operator|::
name|isRegistered
argument_list|(
name|typeId
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|QTBUG11316_registerStreamBuiltin
name|void
name|tst_QMetaType
operator|::
name|QTBUG11316_registerStreamBuiltin
parameter_list|()
block|{
comment|//should not crash;
name|qRegisterMetaTypeStreamOperators
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"QString"
argument_list|)
expr_stmt|;
name|qRegisterMetaTypeStreamOperators
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"QVariant"
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QMetaType
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmetatype.moc"
end_include
end_unit
