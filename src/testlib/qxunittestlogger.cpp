begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qxunittestlogger_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtestelement_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtestxunitstreamer_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestcase.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtestresult_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmark_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|min
end_ifdef
begin_comment
comment|// windows.h without NOMINMAX is included by the benchmark headers.
end_comment
begin_undef
DECL|macro|min
undef|#
directive|undef
name|min
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|max
end_ifdef
begin_undef
DECL|macro|max
undef|#
directive|undef
name|max
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/qlibraryinfo.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QXunitTestLogger
name|QXunitTestLogger
operator|::
name|QXunitTestLogger
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
member_init_list|:
name|QAbstractTestLogger
argument_list|(
name|filename
argument_list|)
member_init_list|,
name|listOfTestcases
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|currentLogElement
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|errorLogElement
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|logFormatter
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|testCounter
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|failureCounter
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|errorCounter
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QXunitTestLogger
name|QXunitTestLogger
operator|::
name|~
name|QXunitTestLogger
parameter_list|()
block|{
operator|delete
name|currentLogElement
expr_stmt|;
operator|delete
name|logFormatter
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|startLogging
name|void
name|QXunitTestLogger
operator|::
name|startLogging
parameter_list|()
block|{
name|QAbstractTestLogger
operator|::
name|startLogging
argument_list|()
expr_stmt|;
name|logFormatter
operator|=
operator|new
name|QTestXunitStreamer
argument_list|(
name|this
argument_list|)
expr_stmt|;
operator|delete
name|errorLogElement
expr_stmt|;
name|errorLogElement
operator|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_SystemError
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stopLogging
name|void
name|QXunitTestLogger
operator|::
name|stopLogging
parameter_list|()
block|{
name|QTestElement
modifier|*
name|iterator
init|=
name|listOfTestcases
decl_stmt|;
name|char
name|buf
index|[
literal|10
index|]
decl_stmt|;
name|currentLogElement
operator|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_TestSuite
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Name
argument_list|,
name|QTestResult
operator|::
name|currentTestObjectName
argument_list|()
argument_list|)
expr_stmt|;
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%i"
argument_list|,
name|testCounter
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Tests
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%i"
argument_list|,
name|failureCounter
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Failures
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%i"
argument_list|,
name|errorCounter
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Errors
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|QTestElement
modifier|*
name|property
decl_stmt|;
name|QTestElement
modifier|*
name|properties
init|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_Properties
argument_list|)
decl_stmt|;
name|property
operator|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_Property
argument_list|)
expr_stmt|;
name|property
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Name
argument_list|,
literal|"QTestVersion"
argument_list|)
expr_stmt|;
name|property
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_PropertyValue
argument_list|,
name|QTEST_VERSION_STR
argument_list|)
expr_stmt|;
name|properties
operator|->
name|addLogElement
argument_list|(
name|property
argument_list|)
expr_stmt|;
name|property
operator|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_Property
argument_list|)
expr_stmt|;
name|property
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Name
argument_list|,
literal|"QtVersion"
argument_list|)
expr_stmt|;
name|property
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_PropertyValue
argument_list|,
name|qVersion
argument_list|()
argument_list|)
expr_stmt|;
name|properties
operator|->
name|addLogElement
argument_list|(
name|property
argument_list|)
expr_stmt|;
name|property
operator|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_Property
argument_list|)
expr_stmt|;
name|property
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Name
argument_list|,
literal|"QtBuild"
argument_list|)
expr_stmt|;
name|property
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_PropertyValue
argument_list|,
name|QLibraryInfo
operator|::
name|build
argument_list|()
argument_list|)
expr_stmt|;
name|properties
operator|->
name|addLogElement
argument_list|(
name|property
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addLogElement
argument_list|(
name|properties
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addLogElement
argument_list|(
name|iterator
argument_list|)
expr_stmt|;
comment|/* For correct indenting, make sure every testcase knows its parent */
name|QTestElement
modifier|*
name|testcase
init|=
name|iterator
decl_stmt|;
while|while
condition|(
name|testcase
condition|)
block|{
name|testcase
operator|->
name|setParent
argument_list|(
name|currentLogElement
argument_list|)
expr_stmt|;
name|testcase
operator|=
name|testcase
operator|->
name|nextElement
argument_list|()
expr_stmt|;
block|}
name|currentLogElement
operator|->
name|addLogElement
argument_list|(
name|errorLogElement
argument_list|)
expr_stmt|;
name|QTestElement
modifier|*
name|it
init|=
name|currentLogElement
decl_stmt|;
name|logFormatter
operator|->
name|output
argument_list|(
name|it
argument_list|)
expr_stmt|;
name|QAbstractTestLogger
operator|::
name|stopLogging
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enterTestFunction
name|void
name|QXunitTestLogger
operator|::
name|enterTestFunction
parameter_list|(
specifier|const
name|char
modifier|*
name|function
parameter_list|)
block|{
name|currentLogElement
operator|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_TestCase
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Name
argument_list|,
name|function
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addToList
argument_list|(
operator|&
name|listOfTestcases
argument_list|)
expr_stmt|;
operator|++
name|testCounter
expr_stmt|;
block|}
end_function
begin_function
DECL|function|leaveTestFunction
name|void
name|QXunitTestLogger
operator|::
name|leaveTestFunction
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|addIncident
name|void
name|QXunitTestLogger
operator|::
name|addIncident
parameter_list|(
name|IncidentTypes
name|type
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
specifier|const
name|char
modifier|*
name|typeBuf
init|=
literal|0
decl_stmt|;
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QAbstractTestLogger
operator|::
name|XPass
case|:
operator|++
name|failureCounter
expr_stmt|;
name|typeBuf
operator|=
literal|"xpass"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|Pass
case|:
name|typeBuf
operator|=
literal|"pass"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|XFail
case|:
name|typeBuf
operator|=
literal|"xfail"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|Fail
case|:
operator|++
name|failureCounter
expr_stmt|;
name|typeBuf
operator|=
literal|"fail"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|BlacklistedPass
case|:
name|typeBuf
operator|=
literal|"bpass"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|BlacklistedFail
case|:
operator|++
name|failureCounter
expr_stmt|;
name|typeBuf
operator|=
literal|"bfail"
expr_stmt|;
break|break;
default|default:
name|typeBuf
operator|=
literal|"??????"
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|Fail
operator|||
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|XPass
condition|)
block|{
name|QTestElement
modifier|*
name|failureElement
init|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_Failure
argument_list|)
decl_stmt|;
name|failureElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Result
argument_list|,
name|typeBuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|file
condition|)
name|failureElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_File
argument_list|,
name|file
argument_list|)
expr_stmt|;
else|else
name|failureElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_File
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%i"
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|failureElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Line
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|failureElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Description
argument_list|,
name|description
argument_list|)
expr_stmt|;
name|addTag
argument_list|(
name|failureElement
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addLogElement
argument_list|(
name|failureElement
argument_list|)
expr_stmt|;
block|}
comment|/*         Only one result can be shown for the whole testfunction.         Check if we currently have a result, and if so, overwrite it         iff the new result is worse.     */
name|QTestElementAttribute
modifier|*
name|resultAttr
init|=
cast|const_cast
argument_list|<
name|QTestElementAttribute
operator|*
argument_list|>
argument_list|(
name|currentLogElement
operator|->
name|attribute
argument_list|(
name|QTest
operator|::
name|AI_Result
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|resultAttr
condition|)
block|{
specifier|const
name|char
modifier|*
name|oldResult
init|=
name|resultAttr
operator|->
name|value
argument_list|()
decl_stmt|;
name|bool
name|overwrite
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|oldResult
argument_list|,
literal|"pass"
argument_list|)
condition|)
block|{
name|overwrite
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|oldResult
argument_list|,
literal|"bpass"
argument_list|)
condition|)
block|{
name|overwrite
operator|=
operator|(
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|XPass
operator|||
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|Fail
operator|)
operator|||
operator|(
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|XFail
operator|)
operator|||
operator|(
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|BlacklistedFail
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|oldResult
argument_list|,
literal|"bfail"
argument_list|)
condition|)
block|{
name|overwrite
operator|=
operator|(
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|XPass
operator|||
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|Fail
operator|)
operator|||
operator|(
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|XFail
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|oldResult
argument_list|,
literal|"xfail"
argument_list|)
condition|)
block|{
name|overwrite
operator|=
operator|(
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|XPass
operator|||
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|Fail
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|oldResult
argument_list|,
literal|"xpass"
argument_list|)
condition|)
block|{
name|overwrite
operator|=
operator|(
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|Fail
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|overwrite
condition|)
block|{
name|resultAttr
operator|->
name|setPair
argument_list|(
name|QTest
operator|::
name|AI_Result
argument_list|,
name|typeBuf
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|currentLogElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Result
argument_list|,
name|typeBuf
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|file
condition|)
name|currentLogElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_File
argument_list|,
name|file
argument_list|)
expr_stmt|;
else|else
name|currentLogElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_File
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%i"
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Line
argument_list|,
name|buf
argument_list|)
expr_stmt|;
comment|/*         Since XFAIL does not add a failure to the testlog in xunitxml, add a message, so we still         have some information about the expected failure.     */
if|if
condition|(
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|XFail
condition|)
block|{
name|QXunitTestLogger
operator|::
name|addMessage
argument_list|(
name|QAbstractTestLogger
operator|::
name|Info
argument_list|,
name|QString
operator|::
name|fromUtf8
argument_list|(
name|description
argument_list|)
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|addBenchmarkResult
name|void
name|QXunitTestLogger
operator|::
name|addBenchmarkResult
parameter_list|(
specifier|const
name|QBenchmarkResult
modifier|&
name|result
parameter_list|)
block|{
name|QTestElement
modifier|*
name|benchmarkElement
init|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_Benchmark
argument_list|)
decl_stmt|;
name|benchmarkElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Metric
argument_list|,
name|QTest
operator|::
name|benchmarkMetricName
argument_list|(
name|QBenchmarkTestMethodData
operator|::
name|current
operator|->
name|result
operator|.
name|metric
argument_list|)
argument_list|)
expr_stmt|;
name|benchmarkElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Tag
argument_list|,
name|result
operator|.
name|context
operator|.
name|tag
operator|.
name|toUtf8
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|valuePerIteration
init|=
name|qreal
argument_list|(
name|result
operator|.
name|value
argument_list|)
operator|/
name|qreal
argument_list|(
name|result
operator|.
name|iterations
argument_list|)
decl_stmt|;
name|benchmarkElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Value
argument_list|,
name|QByteArray
operator|::
name|number
argument_list|(
name|valuePerIteration
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%i"
argument_list|,
name|result
operator|.
name|iterations
argument_list|)
expr_stmt|;
name|benchmarkElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Iterations
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addLogElement
argument_list|(
name|benchmarkElement
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addTag
name|void
name|QXunitTestLogger
operator|::
name|addTag
parameter_list|(
name|QTestElement
modifier|*
name|element
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|tag
init|=
name|QTestResult
operator|::
name|currentDataTag
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|gtag
init|=
name|QTestResult
operator|::
name|currentGlobalDataTag
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|filler
init|=
operator|(
name|tag
operator|&&
name|gtag
operator|)
condition|?
literal|":"
else|:
literal|""
decl_stmt|;
if|if
condition|(
operator|(
operator|!
name|tag
operator|||
operator|!
name|tag
index|[
literal|0
index|]
operator|)
operator|&&
operator|(
operator|!
name|gtag
operator|||
operator|!
name|gtag
index|[
literal|0
index|]
operator|)
condition|)
block|{
return|return;
block|}
if|if
condition|(
operator|!
name|tag
condition|)
block|{
name|tag
operator|=
literal|""
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|gtag
condition|)
block|{
name|gtag
operator|=
literal|""
expr_stmt|;
block|}
name|QTestCharBuffer
name|buf
decl_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"%s%s%s"
argument_list|,
name|gtag
argument_list|,
name|filler
argument_list|,
name|tag
argument_list|)
expr_stmt|;
name|element
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Tag
argument_list|,
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addMessage
name|void
name|QXunitTestLogger
operator|::
name|addMessage
parameter_list|(
name|MessageTypes
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
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
name|QTestElement
modifier|*
name|errorElement
init|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_Error
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|typeBuf
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QAbstractTestLogger
operator|::
name|Warn
case|:
name|typeBuf
operator|=
literal|"warn"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|QSystem
case|:
name|typeBuf
operator|=
literal|"system"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|QDebug
case|:
name|typeBuf
operator|=
literal|"qdebug"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|QInfo
case|:
name|typeBuf
operator|=
literal|"qinfo"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|QWarning
case|:
name|typeBuf
operator|=
literal|"qwarn"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|QFatal
case|:
name|typeBuf
operator|=
literal|"qfatal"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|Skip
case|:
name|typeBuf
operator|=
literal|"skip"
expr_stmt|;
break|break;
case|case
name|QAbstractTestLogger
operator|::
name|Info
case|:
name|typeBuf
operator|=
literal|"info"
expr_stmt|;
break|break;
default|default:
name|typeBuf
operator|=
literal|"??????"
expr_stmt|;
break|break;
block|}
name|errorElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Type
argument_list|,
name|typeBuf
argument_list|)
expr_stmt|;
name|errorElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Description
argument_list|,
name|message
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|addTag
argument_list|(
name|errorElement
argument_list|)
expr_stmt|;
if|if
condition|(
name|file
condition|)
name|errorElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_File
argument_list|,
name|file
argument_list|)
expr_stmt|;
else|else
name|errorElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_File
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%i"
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|errorElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Line
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|currentLogElement
operator|->
name|addLogElement
argument_list|(
name|errorElement
argument_list|)
expr_stmt|;
operator|++
name|errorCounter
expr_stmt|;
comment|// Also add the message to the system error log (i.e. stderr), if one exists
if|if
condition|(
name|errorLogElement
condition|)
block|{
name|QTestElement
modifier|*
name|systemErrorElement
init|=
operator|new
name|QTestElement
argument_list|(
name|QTest
operator|::
name|LET_Error
argument_list|)
decl_stmt|;
name|systemErrorElement
operator|->
name|addAttribute
argument_list|(
name|QTest
operator|::
name|AI_Description
argument_list|,
name|message
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|errorLogElement
operator|->
name|addLogElement
argument_list|(
name|systemErrorElement
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
