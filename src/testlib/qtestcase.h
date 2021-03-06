begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTCASE_H
end_ifndef
begin_define
DECL|macro|QTESTCASE_H
define|#
directive|define
name|QTESTCASE_H
end_define
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtypetraits.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtemporarydir.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
end_ifndef
begin_include
include|#
directive|include
file|<exception>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_EXCEPTIONS
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QRegularExpression
name|class
name|QRegularExpression
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QVERIFY
define|#
directive|define
name|QVERIFY
parameter_list|(
name|statement
parameter_list|)
define|\
value|do {\     if (!QTest::qVerify((statement), #statement, "", __FILE__, __LINE__))\         return;\ } while (0)
end_define
begin_define
DECL|macro|QFAIL
define|#
directive|define
name|QFAIL
parameter_list|(
name|message
parameter_list|)
define|\
value|do {\     QTest::qFail(message, __FILE__, __LINE__);\     return;\ } while (0)
end_define
begin_define
DECL|macro|QVERIFY2
define|#
directive|define
name|QVERIFY2
parameter_list|(
name|statement
parameter_list|,
name|description
parameter_list|)
define|\
value|do {\     if (statement) {\         if (!QTest::qVerify(true, #statement, (description), __FILE__, __LINE__))\             return;\     } else {\         if (!QTest::qVerify(false, #statement, (description), __FILE__, __LINE__))\             return;\     }\ } while (0)
end_define
begin_define
DECL|macro|QCOMPARE
define|#
directive|define
name|QCOMPARE
parameter_list|(
name|actual
parameter_list|,
name|expected
parameter_list|)
define|\
value|do {\     if (!QTest::qCompare(actual, expected, #actual, #expected, __FILE__, __LINE__))\         return;\ } while (0)
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
end_ifndef
begin_define
DECL|macro|QVERIFY_EXCEPTION_THROWN
define|#
directive|define
name|QVERIFY_EXCEPTION_THROWN
parameter_list|(
name|expression
parameter_list|,
name|exceptiontype
parameter_list|)
define|\
value|do {\         QT_TRY {\             QT_TRY {\                 expression;\                 QTest::qFail("Expected exception of type " #exceptiontype " to be thrown" \                              " but no exception caught", __FILE__, __LINE__);\                 return;\             } QT_CATCH (const exceptiontype&) {\             }\         } QT_CATCH (const std::exception&e) {\             QByteArray msg = QByteArray() + "Expected exception of type " #exceptiontype \                              " to be thrown but std::exception caught with message: " + e.what(); \             QTest::qFail(msg.constData(), __FILE__, __LINE__);\             return;\         } QT_CATCH (...) {\             QTest::qFail("Expected exception of type " #exceptiontype " to be thrown" \                          " but unknown exception caught", __FILE__, __LINE__);\             return;\         }\     } while (0)
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|// QT_NO_EXCEPTIONS
end_comment
begin_comment
comment|/*  * The expression passed to the macro should throw an exception and we can't  * catch it because Qt has been compiled without exception support. We can't  * skip the expression because it may have side effects and must be executed.  * So, users must use Qt with exception support enabled if they use exceptions  * in their code.  */
end_comment
begin_define
DECL|macro|QVERIFY_EXCEPTION_THROWN
define|#
directive|define
name|QVERIFY_EXCEPTION_THROWN
parameter_list|(
name|expression
parameter_list|,
name|exceptiontype
parameter_list|)
define|\
value|Q_STATIC_ASSERT_X(false, "Support of exceptions is disabled")
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_EXCEPTIONS
end_comment
begin_define
DECL|macro|QTRY_LOOP_IMPL
define|#
directive|define
name|QTRY_LOOP_IMPL
parameter_list|(
name|__expr
parameter_list|,
name|__timeoutValue
parameter_list|,
name|__step
parameter_list|)
define|\
value|if (!(__expr)) { \         QTest::qWait(0); \     } \     int __i = 0; \     for (; __i< __timeoutValue&& !(__expr); __i += __step) { \         QTest::qWait(__step); \     }
end_define
begin_define
DECL|macro|QTRY_TIMEOUT_DEBUG_IMPL
define|#
directive|define
name|QTRY_TIMEOUT_DEBUG_IMPL
parameter_list|(
name|__expr
parameter_list|,
name|__timeoutValue
parameter_list|,
name|__step
parameter_list|)
define|\
value|if (!(__expr)) { \         QTRY_LOOP_IMPL((__expr), (2 * __timeoutValue), __step);\         if (__expr) { \             QString msg = QString::fromUtf8("QTestLib: This test case check (\"%1\") failed because the requested timeout (%2 ms) was too short, %3 ms would have been sufficient this time."); \             msg = msg.arg(QString::fromUtf8(#__expr)).arg(__timeoutValue).arg(__timeoutValue + __i); \             QFAIL(qPrintable(msg)); \         } \     }
end_define
begin_define
DECL|macro|QTRY_IMPL
define|#
directive|define
name|QTRY_IMPL
parameter_list|(
name|__expr
parameter_list|,
name|__timeout
parameter_list|)
define|\
value|const int __step = 50; \     const int __timeoutValue = __timeout; \     QTRY_LOOP_IMPL((__expr), __timeoutValue, __step); \     QTRY_TIMEOUT_DEBUG_IMPL((__expr), __timeoutValue, __step)
end_define
begin_comment
unit|\
comment|// Will try to wait for the expression to become true while allowing event processing
end_comment
begin_define
DECL|macro|QTRY_VERIFY_WITH_TIMEOUT
define|#
directive|define
name|QTRY_VERIFY_WITH_TIMEOUT
parameter_list|(
name|__expr
parameter_list|,
name|__timeout
parameter_list|)
define|\
value|do { \     QTRY_IMPL((__expr), __timeout);\     QVERIFY(__expr); \ } while (0)
end_define
begin_define
DECL|macro|QTRY_VERIFY
define|#
directive|define
name|QTRY_VERIFY
parameter_list|(
name|__expr
parameter_list|)
value|QTRY_VERIFY_WITH_TIMEOUT((__expr), 5000)
end_define
begin_comment
comment|// Will try to wait for the expression to become true while allowing event processing
end_comment
begin_define
DECL|macro|QTRY_VERIFY2_WITH_TIMEOUT
define|#
directive|define
name|QTRY_VERIFY2_WITH_TIMEOUT
parameter_list|(
name|__expr
parameter_list|,
name|__messageExpression
parameter_list|,
name|__timeout
parameter_list|)
define|\
value|do { \     QTRY_IMPL((__expr), __timeout);\     QVERIFY2(__expr, __messageExpression); \ } while (0)
end_define
begin_define
DECL|macro|QTRY_VERIFY2
define|#
directive|define
name|QTRY_VERIFY2
parameter_list|(
name|__expr
parameter_list|,
name|__messageExpression
parameter_list|)
value|QTRY_VERIFY2_WITH_TIMEOUT((__expr), (__messageExpression), 5000)
end_define
begin_comment
comment|// Will try to wait for the comparison to become successful while allowing event processing
end_comment
begin_define
DECL|macro|QTRY_COMPARE_WITH_TIMEOUT
define|#
directive|define
name|QTRY_COMPARE_WITH_TIMEOUT
parameter_list|(
name|__expr
parameter_list|,
name|__expected
parameter_list|,
name|__timeout
parameter_list|)
define|\
value|do { \     QTRY_IMPL(((__expr) == (__expected)), __timeout);\     QCOMPARE((__expr), __expected); \ } while (0)
end_define
begin_define
DECL|macro|QTRY_COMPARE
define|#
directive|define
name|QTRY_COMPARE
parameter_list|(
name|__expr
parameter_list|,
name|__expected
parameter_list|)
value|QTRY_COMPARE_WITH_TIMEOUT((__expr), __expected, 5000)
end_define
begin_define
DECL|macro|QSKIP_INTERNAL
define|#
directive|define
name|QSKIP_INTERNAL
parameter_list|(
name|statement
parameter_list|)
define|\
value|do {\     QTest::qSkip(statement, __FILE__, __LINE__);\     return;\ } while (0)
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_VARIADIC_MACROS
end_ifdef
begin_define
DECL|macro|QSKIP
define|#
directive|define
name|QSKIP
parameter_list|(
name|statement
parameter_list|,
modifier|...
parameter_list|)
value|QSKIP_INTERNAL(statement)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QSKIP
define|#
directive|define
name|QSKIP
parameter_list|(
name|statement
parameter_list|)
value|QSKIP_INTERNAL(statement)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QEXPECT_FAIL
define|#
directive|define
name|QEXPECT_FAIL
parameter_list|(
name|dataIndex
parameter_list|,
name|comment
parameter_list|,
name|mode
parameter_list|)
define|\
value|do {\     if (!QTest::qExpectFail(dataIndex, comment, QTest::mode, __FILE__, __LINE__))\         return;\ } while (0)
end_define
begin_define
DECL|macro|QFETCH
define|#
directive|define
name|QFETCH
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|type name = *static_cast<type *>(QTest::qData(#name, ::qMetaTypeId<type>()))
end_define
begin_define
DECL|macro|QFETCH_GLOBAL
define|#
directive|define
name|QFETCH_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|type name = *static_cast<type *>(QTest::qGlobalData(#name, ::qMetaTypeId<type>()))
end_define
begin_define
DECL|macro|QTEST
define|#
directive|define
name|QTEST
parameter_list|(
name|actual
parameter_list|,
name|testElement
parameter_list|)
define|\
value|do {\     if (!QTest::qTest(actual, testElement, #actual, #testElement, __FILE__, __LINE__))\         return;\ } while (0)
end_define
begin_define
DECL|macro|QWARN
define|#
directive|define
name|QWARN
parameter_list|(
name|msg
parameter_list|)
define|\
value|QTest::qWarn(msg, __FILE__, __LINE__)
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|QT_TESTCASE_BUILDDIR
end_ifdef
begin_define
DECL|macro|QFINDTESTDATA
define|#
directive|define
name|QFINDTESTDATA
parameter_list|(
name|basepath
parameter_list|)
define|\
value|QTest::qFindTestData(basepath, __FILE__, __LINE__, QT_TESTCASE_BUILDDIR)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QFINDTESTDATA
define|#
directive|define
name|QFINDTESTDATA
parameter_list|(
name|basepath
parameter_list|)
define|\
value|QTest::qFindTestData(basepath, __FILE__, __LINE__)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QEXTRACTTESTDATA
define|#
directive|define
name|QEXTRACTTESTDATA
parameter_list|(
name|resourcePath
parameter_list|)
define|\
value|QTest::qExtractTestData(resourcePath)
end_define
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTestData
name|class
name|QTestData
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QTEST_COMPARE_DECL
define|#
directive|define
name|QTEST_COMPARE_DECL
parameter_list|(
name|KLASS
parameter_list|)
define|\
value|template<> Q_TESTLIB_EXPORT char *toString<KLASS>(const KLASS&);
end_define
begin_decl_stmt
name|namespace
name|QTest
block|{
name|namespace
name|Internal
block|{
name|template
operator|<
name|typename
name|T
operator|>
comment|// Output registered enums
specifier|inline
name|typename
name|QtPrivate
operator|::
name|QEnableIf
operator|<
name|QtPrivate
operator|::
name|IsQEnumHelper
operator|<
name|T
operator|>
operator|::
name|Value
operator|,
name|char
operator|*
operator|>
operator|::
name|Type
name|toString
argument_list|(
argument|T e
argument_list|)
block|{
name|QMetaEnum
name|me
operator|=
name|QMetaEnum
operator|::
name|fromType
operator|<
name|T
operator|>
operator|(
operator|)
block|;
return|return
name|qstrdup
argument_list|(
name|me
operator|.
name|valueToKey
argument_list|(
name|int
argument_list|(
name|e
argument_list|)
argument_list|)
argument_list|)
return|;
comment|// int cast is necessary to support enum classes
block|}
name|template
operator|<
name|typename
name|T
operator|>
comment|// Fallback
specifier|inline
name|typename
name|QtPrivate
operator|::
name|QEnableIf
operator|<
operator|!
name|QtPrivate
operator|::
name|IsQEnumHelper
operator|<
name|T
operator|>
operator|::
name|Value
operator|,
name|char
operator|*
operator|>
operator|::
name|Type
name|toString
argument_list|(
argument|const T&
argument_list|)
block|{
return|return
name|Q_NULLPTR
return|;
block|}
block|}
comment|// namespace Internal
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const T&t
argument_list|)
block|{
return|return
name|Internal
operator|::
name|toString
argument_list|(
name|t
argument_list|)
return|;
block|}
name|Q_TESTLIB_EXPORT
name|char
modifier|*
name|toHexRepresentation
parameter_list|(
specifier|const
name|char
modifier|*
name|ba
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|char
modifier|*
name|toPrettyCString
parameter_list|(
specifier|const
name|char
modifier|*
name|unicode
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|char
modifier|*
name|toPrettyUnicode
parameter_list|(
specifier|const
name|ushort
modifier|*
name|unicode
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|char
modifier|*
name|toString
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|char
modifier|*
name|toString
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|int
name|qExec
parameter_list|(
name|QObject
modifier|*
name|testObject
parameter_list|,
name|int
name|argc
init|=
literal|0
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
init|=
name|Q_NULLPTR
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|int
name|qExec
parameter_list|(
name|QObject
modifier|*
name|testObject
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|arguments
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|setMainSourcePath
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
specifier|const
name|char
modifier|*
name|builddir
init|=
name|Q_NULLPTR
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|bool
name|qVerify
parameter_list|(
name|bool
name|statement
parameter_list|,
specifier|const
name|char
modifier|*
name|statementStr
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|qFail
parameter_list|(
specifier|const
name|char
modifier|*
name|statementStr
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|qSkip
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|bool
name|qExpectFail
parameter_list|(
specifier|const
name|char
modifier|*
name|dataIndex
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
parameter_list|,
name|TestFailMode
name|mode
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|qWarn
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|file
init|=
name|Q_NULLPTR
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|ignoreMessage
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_REGULAREXPRESSION
name|Q_TESTLIB_EXPORT
name|void
name|ignoreMessage
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
specifier|const
name|QRegularExpression
modifier|&
name|messagePattern
parameter_list|)
function_decl|;
endif|#
directive|endif
name|Q_TESTLIB_EXPORT
name|QSharedPointer
operator|<
name|QTemporaryDir
operator|>
name|qExtractTestData
argument_list|(
specifier|const
name|QString
operator|&
name|dirName
argument_list|)
expr_stmt|;
name|Q_TESTLIB_EXPORT
name|QString
name|qFindTestData
parameter_list|(
specifier|const
name|char
modifier|*
name|basepath
parameter_list|,
specifier|const
name|char
modifier|*
name|file
init|=
name|Q_NULLPTR
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|builddir
init|=
name|Q_NULLPTR
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|QString
name|qFindTestData
parameter_list|(
specifier|const
name|QString
modifier|&
name|basepath
parameter_list|,
specifier|const
name|char
modifier|*
name|file
init|=
name|Q_NULLPTR
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|builddir
init|=
name|Q_NULLPTR
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
modifier|*
name|qData
parameter_list|(
specifier|const
name|char
modifier|*
name|tagName
parameter_list|,
name|int
name|typeId
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
modifier|*
name|qGlobalData
parameter_list|(
specifier|const
name|char
modifier|*
name|tagName
parameter_list|,
name|int
name|typeId
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
modifier|*
name|qElementData
parameter_list|(
specifier|const
name|char
modifier|*
name|elementName
parameter_list|,
name|int
name|metaTypeId
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|QObject
modifier|*
name|testObject
parameter_list|()
function_decl|;
name|Q_TESTLIB_EXPORT
specifier|const
name|char
modifier|*
name|currentAppName
parameter_list|()
function_decl|;
name|Q_TESTLIB_EXPORT
specifier|const
name|char
modifier|*
name|currentTestFunction
parameter_list|()
function_decl|;
name|Q_TESTLIB_EXPORT
specifier|const
name|char
modifier|*
name|currentDataTag
parameter_list|()
function_decl|;
name|Q_TESTLIB_EXPORT
name|bool
name|currentTestFailed
parameter_list|()
function_decl|;
name|Q_TESTLIB_EXPORT
name|Qt
operator|::
name|Key
name|asciiToKey
argument_list|(
argument|char ascii
argument_list|)
expr_stmt|;
name|Q_TESTLIB_EXPORT
name|char
name|keyToAscii
argument_list|(
name|Qt
operator|::
name|Key
name|key
argument_list|)
decl_stmt|;
name|Q_TESTLIB_EXPORT
name|bool
name|compare_helper
parameter_list|(
name|bool
name|success
parameter_list|,
specifier|const
name|char
modifier|*
name|failureMsg
parameter_list|,
name|char
modifier|*
name|val1
parameter_list|,
name|char
modifier|*
name|val2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|qSleep
parameter_list|(
name|int
name|ms
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|addColumnInternal
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|addColumn
argument_list|(
argument|const char *name
argument_list|,
argument|T * =
literal|0
argument_list|)
block|{
typedef|typedef
name|QtPrivate
operator|::
name|is_same
operator|<
name|T
operator|,
specifier|const
name|char
operator|*
operator|>
name|QIsSameTConstChar
expr_stmt|;
name|Q_STATIC_ASSERT_X
argument_list|(
operator|!
name|QIsSameTConstChar
operator|::
name|value
argument_list|,
literal|"const char* is not allowed as a test data format."
argument_list|)
expr_stmt|;
name|addColumnInternal
argument_list|(
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_function_decl
name|Q_TESTLIB_EXPORT
name|QTestData
modifier|&
name|newRow
parameter_list|(
specifier|const
name|char
modifier|*
name|dataTag
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|T const&t1
argument_list|,
argument|T const&t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_helper
argument_list|(
name|t1
operator|==
name|t2
argument_list|,
literal|"Compared values are not the same"
argument_list|,
name|toString
argument_list|(
name|t1
argument_list|)
argument_list|,
name|toString
argument_list|(
name|t2
argument_list|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_function_decl
name|Q_TESTLIB_EXPORT
name|bool
name|qCompare
parameter_list|(
name|float
specifier|const
modifier|&
name|t1
parameter_list|,
name|float
specifier|const
modifier|&
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_TESTLIB_EXPORT
name|bool
name|qCompare
parameter_list|(
name|double
specifier|const
modifier|&
name|t1
parameter_list|,
name|double
specifier|const
modifier|&
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|bool
name|compare_ptr_helper
parameter_list|(
specifier|const
name|void
modifier|*
name|t1
parameter_list|,
specifier|const
name|void
modifier|*
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
return|return
name|compare_helper
argument_list|(
name|t1
operator|==
name|t2
argument_list|,
literal|"Compared pointers are not the same"
argument_list|,
name|toString
argument_list|(
name|t1
argument_list|)
argument_list|,
name|toString
argument_list|(
name|t2
argument_list|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_function
begin_function_decl
name|Q_TESTLIB_EXPORT
name|bool
name|compare_string_helper
parameter_list|(
specifier|const
name|char
modifier|*
name|t1
parameter_list|,
specifier|const
name|char
modifier|*
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|Q_QDOC
end_ifndef
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|short
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|ushort
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|int
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|uint
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|long
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|ulong
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|qint64
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|quint64
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|float
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|double
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|char
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|signed char
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|unsigned char
argument_list|)
end_macro
begin_macro
name|QTEST_COMPARE_DECL
argument_list|(
argument|bool
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|bool
name|qCompare
argument_list|(
name|T1
specifier|const
operator|&
argument_list|,
name|T2
specifier|const
operator|&
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
specifier|inline
name|bool
name|qCompare
parameter_list|(
name|double
specifier|const
modifier|&
name|t1
parameter_list|,
name|float
specifier|const
modifier|&
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
return|return
name|qCompare
argument_list|(
name|qreal
argument_list|(
name|t1
argument_list|)
argument_list|,
name|qreal
argument_list|(
name|t2
argument_list|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|qCompare
parameter_list|(
name|float
specifier|const
modifier|&
name|t1
parameter_list|,
name|double
specifier|const
modifier|&
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
return|return
name|qCompare
argument_list|(
name|qreal
argument_list|(
name|t1
argument_list|)
argument_list|,
name|qreal
argument_list|(
name|t2
argument_list|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|const T *t1
argument_list|,
argument|const T *t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_ptr_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|T *t1
argument_list|,
argument|T *t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_ptr_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|const T1 *t1
argument_list|,
argument|const T2 *t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_ptr_helper
argument_list|(
name|t1
argument_list|,
name|static_cast
operator|<
specifier|const
name|T1
operator|*
operator|>
operator|(
name|t2
operator|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
specifier|inline
name|bool
name|qCompare
argument_list|(
argument|T1 *t1
argument_list|,
argument|T2 *t2
argument_list|,
argument|const char *actual
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|compare_ptr_helper
argument_list|(
name|const_cast
operator|<
specifier|const
name|T1
operator|*
operator|>
operator|(
name|t1
operator|)
argument_list|,
name|static_cast
operator|<
specifier|const
name|T1
operator|*
operator|>
operator|(
name|const_cast
operator|<
specifier|const
name|T2
operator|*
operator|>
operator|(
name|t2
operator|)
operator|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|bool
name|qCompare
parameter_list|(
specifier|const
name|char
modifier|*
name|t1
parameter_list|,
specifier|const
name|char
modifier|*
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
return|return
name|compare_string_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|qCompare
parameter_list|(
name|char
modifier|*
name|t1
parameter_list|,
name|char
modifier|*
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
return|return
name|compare_string_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/* The next two overloads are for MSVC that shows problems with implicit        conversions      */
end_comment
begin_function
specifier|inline
name|bool
name|qCompare
parameter_list|(
name|char
modifier|*
name|t1
parameter_list|,
specifier|const
name|char
modifier|*
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
return|return
name|compare_string_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|bool
name|qCompare
parameter_list|(
specifier|const
name|char
modifier|*
name|t1
parameter_list|,
name|char
modifier|*
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
return|return
name|compare_string_helper
argument_list|(
name|t1
argument_list|,
name|t2
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|qTest
argument_list|(
argument|const T& actual
argument_list|,
argument|const char *elementName
argument_list|,
argument|const char *actualStr
argument_list|,
argument|const char *expected
argument_list|,
argument|const char *file
argument_list|,
argument|int line
argument_list|)
block|{
return|return
name|qCompare
argument_list|(
name|actual
argument_list|,
operator|*
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|QTest
operator|::
name|qElementData
argument_list|(
name|elementName
argument_list|,
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
operator|)
argument_list|,
name|actualStr
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_expr_stmt
begin_undef
DECL|macro|QTEST_COMPARE_DECL
unit|}
undef|#
directive|undef
name|QTEST_COMPARE_DECL
end_undef
begin_endif
unit|QT_END_NAMESPACE
endif|#
directive|endif
end_endif
end_unit
