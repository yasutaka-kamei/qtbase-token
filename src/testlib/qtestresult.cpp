begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qtestresult_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtestlog_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestdata.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestassert.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_decl_stmt
DECL|variable|currentAppName
specifier|static
specifier|const
name|char
modifier|*
name|currentAppName
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QTest
namespace|namespace
name|QTest
block|{
DECL|member|currentTestData
specifier|static
name|QTestData
modifier|*
name|currentTestData
init|=
literal|0
decl_stmt|;
DECL|member|currentGlobalTestData
specifier|static
name|QTestData
modifier|*
name|currentGlobalTestData
init|=
literal|0
decl_stmt|;
DECL|member|currentTestFunc
specifier|static
specifier|const
name|char
modifier|*
name|currentTestFunc
init|=
literal|0
decl_stmt|;
DECL|member|currentTestObjectName
specifier|static
specifier|const
name|char
modifier|*
name|currentTestObjectName
init|=
literal|0
decl_stmt|;
DECL|member|failed
specifier|static
name|bool
name|failed
init|=
literal|false
decl_stmt|;
DECL|member|skipCurrentTest
specifier|static
name|bool
name|skipCurrentTest
init|=
literal|false
decl_stmt|;
DECL|member|blacklistCurrentTest
specifier|static
name|bool
name|blacklistCurrentTest
init|=
literal|false
decl_stmt|;
DECL|member|expectFailComment
specifier|static
specifier|const
name|char
modifier|*
name|expectFailComment
init|=
literal|0
decl_stmt|;
DECL|member|expectFailMode
specifier|static
name|int
name|expectFailMode
init|=
literal|0
decl_stmt|;
block|}
end_namespace
begin_function
DECL|function|reset
name|void
name|QTestResult
operator|::
name|reset
parameter_list|()
block|{
name|QTest
operator|::
name|currentTestData
operator|=
literal|0
expr_stmt|;
name|QTest
operator|::
name|currentGlobalTestData
operator|=
literal|0
expr_stmt|;
name|QTest
operator|::
name|currentTestFunc
operator|=
literal|0
expr_stmt|;
name|QTest
operator|::
name|currentTestObjectName
operator|=
literal|0
expr_stmt|;
name|QTest
operator|::
name|failed
operator|=
literal|false
expr_stmt|;
name|QTest
operator|::
name|expectFailComment
operator|=
literal|0
expr_stmt|;
name|QTest
operator|::
name|expectFailMode
operator|=
literal|0
expr_stmt|;
name|QTest
operator|::
name|blacklistCurrentTest
operator|=
literal|false
expr_stmt|;
name|QTestLog
operator|::
name|resetCounters
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setBlacklistCurrentTest
name|void
name|QTestResult
operator|::
name|setBlacklistCurrentTest
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|QTest
operator|::
name|blacklistCurrentTest
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentTestFailed
name|bool
name|QTestResult
operator|::
name|currentTestFailed
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|failed
return|;
block|}
end_function
begin_function
DECL|function|currentGlobalTestData
name|QTestData
modifier|*
name|QTestResult
operator|::
name|currentGlobalTestData
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|currentGlobalTestData
return|;
block|}
end_function
begin_function
DECL|function|currentTestData
name|QTestData
modifier|*
name|QTestResult
operator|::
name|currentTestData
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|currentTestData
return|;
block|}
end_function
begin_function
DECL|function|setCurrentGlobalTestData
name|void
name|QTestResult
operator|::
name|setCurrentGlobalTestData
parameter_list|(
name|QTestData
modifier|*
name|data
parameter_list|)
block|{
name|QTest
operator|::
name|currentGlobalTestData
operator|=
name|data
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCurrentTestData
name|void
name|QTestResult
operator|::
name|setCurrentTestData
parameter_list|(
name|QTestData
modifier|*
name|data
parameter_list|)
block|{
name|QTest
operator|::
name|currentTestData
operator|=
name|data
expr_stmt|;
name|QTest
operator|::
name|failed
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCurrentTestFunction
name|void
name|QTestResult
operator|::
name|setCurrentTestFunction
parameter_list|(
specifier|const
name|char
modifier|*
name|func
parameter_list|)
block|{
name|QTest
operator|::
name|currentTestFunc
operator|=
name|func
expr_stmt|;
name|QTest
operator|::
name|failed
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|func
condition|)
name|QTestLog
operator|::
name|enterTestFunction
argument_list|(
name|func
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearExpectFail
specifier|static
name|void
name|clearExpectFail
parameter_list|()
block|{
name|QTest
operator|::
name|expectFailMode
operator|=
literal|0
expr_stmt|;
operator|delete
index|[]
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|QTest
operator|::
name|expectFailComment
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|expectFailComment
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|finishedCurrentTestData
name|void
name|QTestResult
operator|::
name|finishedCurrentTestData
parameter_list|()
block|{
if|if
condition|(
name|QTest
operator|::
name|expectFailMode
condition|)
name|addFailure
argument_list|(
literal|"QEXPECT_FAIL was called without any subsequent verification statements"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|clearExpectFail
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|QTest
operator|::
name|failed
operator|&&
name|QTestLog
operator|::
name|unhandledIgnoreMessages
argument_list|()
condition|)
block|{
name|QTestLog
operator|::
name|printUnhandledIgnoreMessages
argument_list|()
expr_stmt|;
name|addFailure
argument_list|(
literal|"Not all expected messages were received"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|QTestLog
operator|::
name|clearIgnoreMessages
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|finishedCurrentTestDataCleanup
name|void
name|QTestResult
operator|::
name|finishedCurrentTestDataCleanup
parameter_list|()
block|{
comment|// If the current test hasn't failed or been skipped, then it passes.
if|if
condition|(
operator|!
name|QTest
operator|::
name|failed
operator|&&
operator|!
name|QTest
operator|::
name|skipCurrentTest
condition|)
block|{
if|if
condition|(
name|QTest
operator|::
name|blacklistCurrentTest
condition|)
name|QTestLog
operator|::
name|addBPass
argument_list|(
literal|""
argument_list|)
expr_stmt|;
else|else
name|QTestLog
operator|::
name|addPass
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
name|QTest
operator|::
name|failed
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|finishedCurrentTestFunction
name|void
name|QTestResult
operator|::
name|finishedCurrentTestFunction
parameter_list|()
block|{
name|QTest
operator|::
name|currentTestFunc
operator|=
literal|0
expr_stmt|;
name|QTest
operator|::
name|failed
operator|=
literal|false
expr_stmt|;
name|QTestLog
operator|::
name|leaveTestFunction
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentTestFunction
specifier|const
name|char
modifier|*
name|QTestResult
operator|::
name|currentTestFunction
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|currentTestFunc
return|;
block|}
end_function
begin_function
DECL|function|currentDataTag
specifier|const
name|char
modifier|*
name|QTestResult
operator|::
name|currentDataTag
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|currentTestData
condition|?
name|QTest
operator|::
name|currentTestData
operator|->
name|dataTag
argument_list|()
else|:
cast|static_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|currentGlobalDataTag
specifier|const
name|char
modifier|*
name|QTestResult
operator|::
name|currentGlobalDataTag
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|currentGlobalTestData
condition|?
name|QTest
operator|::
name|currentGlobalTestData
operator|->
name|dataTag
argument_list|()
else|:
cast|static_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isExpectFailData
specifier|static
name|bool
name|isExpectFailData
parameter_list|(
specifier|const
name|char
modifier|*
name|dataIndex
parameter_list|)
block|{
if|if
condition|(
operator|!
name|dataIndex
operator|||
name|dataIndex
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|!
name|QTest
operator|::
name|currentTestData
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|dataIndex
argument_list|,
name|QTest
operator|::
name|currentTestData
operator|->
name|dataTag
argument_list|()
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|expectFail
name|bool
name|QTestResult
operator|::
name|expectFail
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
name|QTest
operator|::
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
block|{
name|QTEST_ASSERT
argument_list|(
name|comment
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|mode
operator|>
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isExpectFailData
argument_list|(
name|dataIndex
argument_list|)
condition|)
block|{
operator|delete
index|[]
name|comment
expr_stmt|;
return|return
literal|true
return|;
comment|// we don't care
block|}
if|if
condition|(
name|QTest
operator|::
name|expectFailMode
condition|)
block|{
operator|delete
index|[]
name|comment
expr_stmt|;
name|clearExpectFail
argument_list|()
expr_stmt|;
name|addFailure
argument_list|(
literal|"Already expecting a fail"
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QTest
operator|::
name|expectFailMode
operator|=
name|mode
expr_stmt|;
name|QTest
operator|::
name|expectFailComment
operator|=
name|comment
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|checkStatement
specifier|static
name|bool
name|checkStatement
parameter_list|(
name|bool
name|statement
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
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
if|if
condition|(
name|statement
condition|)
block|{
if|if
condition|(
name|QTest
operator|::
name|expectFailMode
condition|)
block|{
name|QTestLog
operator|::
name|addXPass
argument_list|(
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|bool
name|doContinue
init|=
operator|(
name|QTest
operator|::
name|expectFailMode
operator|==
name|QTest
operator|::
name|Continue
operator|)
decl_stmt|;
name|clearExpectFail
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|failed
operator|=
literal|true
expr_stmt|;
return|return
name|doContinue
return|;
block|}
return|return
literal|true
return|;
block|}
if|if
condition|(
name|QTest
operator|::
name|expectFailMode
condition|)
block|{
name|QTestLog
operator|::
name|addXFail
argument_list|(
name|QTest
operator|::
name|expectFailComment
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|bool
name|doContinue
init|=
operator|(
name|QTest
operator|::
name|expectFailMode
operator|==
name|QTest
operator|::
name|Continue
operator|)
decl_stmt|;
name|clearExpectFail
argument_list|()
expr_stmt|;
return|return
name|doContinue
return|;
block|}
name|QTestResult
operator|::
name|addFailure
argument_list|(
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|verify
name|bool
name|QTestResult
operator|::
name|verify
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
block|{
name|QTEST_ASSERT
argument_list|(
name|statementStr
argument_list|)
expr_stmt|;
name|char
name|msg
index|[
literal|1024
index|]
decl_stmt|;
if|if
condition|(
name|QTestLog
operator|::
name|verboseLevel
argument_list|()
operator|>=
literal|2
condition|)
block|{
name|qsnprintf
argument_list|(
name|msg
argument_list|,
literal|1024
argument_list|,
literal|"QVERIFY(%s)"
argument_list|,
name|statementStr
argument_list|)
expr_stmt|;
name|QTestLog
operator|::
name|info
argument_list|(
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|format
init|=
name|QTest
operator|::
name|expectFailMode
condition|?
literal|"'%s' returned TRUE unexpectedly. (%s)"
else|:
literal|"'%s' returned FALSE. (%s)"
decl_stmt|;
name|qsnprintf
argument_list|(
name|msg
argument_list|,
literal|1024
argument_list|,
name|format
argument_list|,
name|statementStr
argument_list|,
name|description
condition|?
name|description
else|:
literal|""
argument_list|)
expr_stmt|;
return|return
name|checkStatement
argument_list|(
name|statement
argument_list|,
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|compare
name|bool
name|QTestResult
operator|::
name|compare
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
block|{
name|QTEST_ASSERT
argument_list|(
name|expected
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|actual
argument_list|)
expr_stmt|;
specifier|const
name|size_t
name|maxMsgLen
init|=
literal|1024
decl_stmt|;
name|char
name|msg
index|[
name|maxMsgLen
index|]
decl_stmt|;
if|if
condition|(
name|QTestLog
operator|::
name|verboseLevel
argument_list|()
operator|>=
literal|2
condition|)
block|{
name|qsnprintf
argument_list|(
name|msg
argument_list|,
name|maxMsgLen
argument_list|,
literal|"QCOMPARE(%s, %s)"
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QTestLog
operator|::
name|info
argument_list|(
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|failureMsg
condition|)
name|failureMsg
operator|=
literal|"Compared values are not the same"
expr_stmt|;
if|if
condition|(
name|success
operator|&&
name|QTest
operator|::
name|expectFailMode
condition|)
block|{
name|qsnprintf
argument_list|(
name|msg
argument_list|,
name|maxMsgLen
argument_list|,
literal|"QCOMPARE(%s, %s) returned TRUE unexpectedly."
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|val1
operator|||
name|val2
condition|)
block|{
name|size_t
name|len1
init|=
name|mbstowcs
argument_list|(
name|NULL
argument_list|,
name|actual
argument_list|,
name|maxMsgLen
argument_list|)
decl_stmt|;
comment|// Last parameter is not ignored on QNX
name|size_t
name|len2
init|=
name|mbstowcs
argument_list|(
name|NULL
argument_list|,
name|expected
argument_list|,
name|maxMsgLen
argument_list|)
decl_stmt|;
comment|// (result is never larger than this).
name|qsnprintf
argument_list|(
name|msg
argument_list|,
name|maxMsgLen
argument_list|,
literal|"%s\n   Actual   (%s)%*s %s\n   Expected (%s)%*s %s"
argument_list|,
name|failureMsg
argument_list|,
name|actual
argument_list|,
name|qMax
argument_list|(
name|len1
argument_list|,
name|len2
argument_list|)
operator|-
name|len1
operator|+
literal|1
argument_list|,
literal|":"
argument_list|,
name|val1
condition|?
name|val1
else|:
literal|"<null>"
argument_list|,
name|expected
argument_list|,
name|qMax
argument_list|(
name|len1
argument_list|,
name|len2
argument_list|)
operator|-
name|len2
operator|+
literal|1
argument_list|,
literal|":"
argument_list|,
name|val2
condition|?
name|val2
else|:
literal|"<null>"
argument_list|)
expr_stmt|;
block|}
else|else
name|qsnprintf
argument_list|(
name|msg
argument_list|,
name|maxMsgLen
argument_list|,
literal|"%s"
argument_list|,
name|failureMsg
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|val1
expr_stmt|;
operator|delete
index|[]
name|val2
expr_stmt|;
return|return
name|checkStatement
argument_list|(
name|success
argument_list|,
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|addFailure
name|void
name|QTestResult
operator|::
name|addFailure
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
block|{
name|clearExpectFail
argument_list|()
expr_stmt|;
if|if
condition|(
name|QTest
operator|::
name|blacklistCurrentTest
condition|)
name|QTestLog
operator|::
name|addBFail
argument_list|(
name|message
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
else|else
name|QTestLog
operator|::
name|addFail
argument_list|(
name|message
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|failed
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addSkip
name|void
name|QTestResult
operator|::
name|addSkip
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
block|{
name|clearExpectFail
argument_list|()
expr_stmt|;
name|QTestLog
operator|::
name|addSkip
argument_list|(
name|message
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCurrentTestObject
name|void
name|QTestResult
operator|::
name|setCurrentTestObject
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|QTest
operator|::
name|currentTestObjectName
operator|=
name|name
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentTestObjectName
specifier|const
name|char
modifier|*
name|QTestResult
operator|::
name|currentTestObjectName
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|currentTestObjectName
condition|?
name|QTest
operator|::
name|currentTestObjectName
else|:
literal|""
return|;
block|}
end_function
begin_function
DECL|function|setSkipCurrentTest
name|void
name|QTestResult
operator|::
name|setSkipCurrentTest
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|QTest
operator|::
name|skipCurrentTest
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_function
DECL|function|skipCurrentTest
name|bool
name|QTestResult
operator|::
name|skipCurrentTest
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|skipCurrentTest
return|;
block|}
end_function
begin_function
DECL|function|setCurrentAppName
name|void
name|QTestResult
operator|::
name|setCurrentAppName
parameter_list|(
specifier|const
name|char
modifier|*
name|appName
parameter_list|)
block|{
operator|::
name|currentAppName
operator|=
name|appName
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentAppName
specifier|const
name|char
modifier|*
name|QTestResult
operator|::
name|currentAppName
parameter_list|()
block|{
return|return
operator|::
name|currentAppName
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
