begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/qtestassert.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtestlog_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtestresult_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qabstracttestlogger_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qplaintestlogger_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qxunittestlogger_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qxmltestlogger_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QTest
namespace|namespace
name|QTest
block|{
DECL|struct|IgnoreResultList
struct|struct
name|IgnoreResultList
block|{
DECL|function|IgnoreResultList
specifier|inline
name|IgnoreResultList
parameter_list|(
name|QtMsgType
name|tp
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|)
member_init_list|:
name|type
argument_list|(
name|tp
argument_list|)
member_init_list|,
name|next
argument_list|(
literal|0
argument_list|)
block|{
name|msg
operator|=
name|qstrdup
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
DECL|function|~IgnoreResultList
specifier|inline
name|~
name|IgnoreResultList
parameter_list|()
block|{
operator|delete
index|[]
name|msg
expr_stmt|;
block|}
DECL|function|clearList
specifier|static
specifier|inline
name|void
name|clearList
parameter_list|(
name|IgnoreResultList
modifier|*
modifier|&
name|list
parameter_list|)
block|{
while|while
condition|(
name|list
condition|)
block|{
name|IgnoreResultList
modifier|*
name|current
init|=
name|list
decl_stmt|;
name|list
operator|=
name|list
operator|->
name|next
expr_stmt|;
operator|delete
name|current
expr_stmt|;
block|}
block|}
DECL|member|type
name|QtMsgType
name|type
decl_stmt|;
DECL|member|msg
name|char
modifier|*
name|msg
decl_stmt|;
DECL|member|next
name|IgnoreResultList
modifier|*
name|next
decl_stmt|;
block|}
struct|;
DECL|member|ignoreResultList
specifier|static
name|IgnoreResultList
modifier|*
name|ignoreResultList
init|=
literal|0
decl_stmt|;
DECL|struct|LoggerList
struct|struct
name|LoggerList
block|{
DECL|member|logger
name|QAbstractTestLogger
modifier|*
name|logger
decl_stmt|;
DECL|member|next
name|LoggerList
modifier|*
name|next
decl_stmt|;
block|}
struct|;
DECL|class|TestLoggers
class|class
name|TestLoggers
block|{
public|public:
DECL|function|addLogger
specifier|static
name|void
name|addLogger
parameter_list|(
name|QAbstractTestLogger
modifier|*
name|logger
parameter_list|)
block|{
name|LoggerList
modifier|*
name|l
init|=
operator|new
name|LoggerList
decl_stmt|;
name|l
operator|->
name|logger
operator|=
name|logger
expr_stmt|;
name|l
operator|->
name|next
operator|=
name|loggers
expr_stmt|;
name|loggers
operator|=
name|l
expr_stmt|;
block|}
DECL|function|destroyLoggers
specifier|static
name|void
name|destroyLoggers
parameter_list|()
block|{
while|while
condition|(
name|loggers
condition|)
block|{
name|LoggerList
modifier|*
name|l
init|=
name|loggers
decl_stmt|;
name|loggers
operator|=
name|loggers
operator|->
name|next
expr_stmt|;
operator|delete
name|l
operator|->
name|logger
expr_stmt|;
operator|delete
name|l
expr_stmt|;
block|}
block|}
DECL|macro|FOREACH_LOGGER
define|#
directive|define
name|FOREACH_LOGGER
parameter_list|(
name|operation
parameter_list|)
define|\
value|LoggerList *l = loggers; \         while (l) { \             QAbstractTestLogger *logger = l->logger; \             Q_UNUSED(logger); \             operation; \             l = l->next; \         }
DECL|function|startLogging
specifier|static
name|void
name|startLogging
parameter_list|()
block|{
name|FOREACH_LOGGER
argument_list|(
name|logger
operator|->
name|startLogging
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|stopLogging
specifier|static
name|void
name|stopLogging
parameter_list|()
block|{
name|FOREACH_LOGGER
argument_list|(
name|logger
operator|->
name|stopLogging
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|enterTestFunction
specifier|static
name|void
name|enterTestFunction
parameter_list|(
specifier|const
name|char
modifier|*
name|function
parameter_list|)
block|{
name|FOREACH_LOGGER
argument_list|(
name|logger
operator|->
name|enterTestFunction
argument_list|(
name|function
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|leaveTestFunction
specifier|static
name|void
name|leaveTestFunction
parameter_list|()
block|{
name|FOREACH_LOGGER
argument_list|(
name|logger
operator|->
name|leaveTestFunction
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|addIncident
specifier|static
name|void
name|addIncident
parameter_list|(
name|QAbstractTestLogger
operator|::
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
init|=
literal|0
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|)
block|{
name|FOREACH_LOGGER
argument_list|(
name|logger
operator|->
name|addIncident
argument_list|(
name|type
argument_list|,
name|description
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|addBenchmarkResult
specifier|static
name|void
name|addBenchmarkResult
parameter_list|(
specifier|const
name|QBenchmarkResult
modifier|&
name|result
parameter_list|)
block|{
name|FOREACH_LOGGER
argument_list|(
name|logger
operator|->
name|addBenchmarkResult
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|addMessage
specifier|static
name|void
name|addMessage
parameter_list|(
name|QAbstractTestLogger
operator|::
name|MessageTypes
name|type
parameter_list|,
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
literal|0
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|)
block|{
name|FOREACH_LOGGER
argument_list|(
name|logger
operator|->
name|addMessage
argument_list|(
name|type
argument_list|,
name|message
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|outputString
specifier|static
name|void
name|outputString
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|FOREACH_LOGGER
argument_list|(
name|logger
operator|->
name|outputString
argument_list|(
name|msg
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|loggerCount
specifier|static
name|int
name|loggerCount
parameter_list|()
block|{
name|int
name|count
init|=
literal|0
decl_stmt|;
name|FOREACH_LOGGER
argument_list|(
operator|++
name|count
argument_list|)
expr_stmt|;
return|return
name|count
return|;
block|}
private|private:
DECL|member|loggers
specifier|static
name|LoggerList
modifier|*
name|loggers
decl_stmt|;
block|}
class|;
DECL|macro|FOREACH_LOGGER
undef|#
directive|undef
name|FOREACH_LOGGER
DECL|member|loggers
name|LoggerList
modifier|*
name|TestLoggers
operator|::
name|loggers
init|=
literal|0
decl_stmt|;
DECL|member|loggerUsingStdout
specifier|static
name|bool
name|loggerUsingStdout
init|=
literal|false
decl_stmt|;
DECL|member|verbosity
specifier|static
name|int
name|verbosity
init|=
literal|0
decl_stmt|;
DECL|member|maxWarnings
specifier|static
name|int
name|maxWarnings
init|=
literal|2002
decl_stmt|;
DECL|member|oldMessageHandler
specifier|static
name|QtMsgHandler
name|oldMessageHandler
decl_stmt|;
DECL|function|handleIgnoredMessage
specifier|static
name|bool
name|handleIgnoredMessage
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|IgnoreResultList
modifier|*
name|last
init|=
literal|0
decl_stmt|;
name|IgnoreResultList
modifier|*
name|list
init|=
name|ignoreResultList
decl_stmt|;
while|while
condition|(
name|list
condition|)
block|{
if|if
condition|(
name|list
operator|->
name|type
operator|==
name|type
operator|&&
name|strcmp
argument_list|(
name|msg
argument_list|,
name|list
operator|->
name|msg
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|// remove the item from the list
if|if
condition|(
name|last
condition|)
name|last
operator|->
name|next
operator|=
name|list
operator|->
name|next
expr_stmt|;
elseif|else
if|if
condition|(
name|list
operator|->
name|next
condition|)
name|ignoreResultList
operator|=
name|list
operator|->
name|next
expr_stmt|;
else|else
name|ignoreResultList
operator|=
literal|0
expr_stmt|;
operator|delete
name|list
expr_stmt|;
return|return
literal|true
return|;
block|}
name|last
operator|=
name|list
expr_stmt|;
name|list
operator|=
name|list
operator|->
name|next
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|messageHandler
specifier|static
name|void
name|messageHandler
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
specifier|static
name|QBasicAtomicInt
name|counter
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
name|QTest
operator|::
name|maxWarnings
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|msg
operator|||
name|QTest
operator|::
name|TestLoggers
operator|::
name|loggerCount
argument_list|()
operator|==
literal|0
condition|)
block|{
comment|// if this goes wrong, something is seriously broken.
name|qInstallMsgHandler
argument_list|(
name|oldMessageHandler
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|QTest
operator|::
name|TestLoggers
operator|::
name|loggerCount
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|handleIgnoredMessage
argument_list|(
name|type
argument_list|,
name|msg
argument_list|)
condition|)
comment|// the message is expected, so just swallow it.
return|return;
if|if
condition|(
name|type
operator|!=
name|QtFatalMsg
condition|)
block|{
if|if
condition|(
name|counter
operator|.
name|load
argument_list|()
operator|<=
literal|0
condition|)
return|return;
if|if
condition|(
operator|!
name|counter
operator|.
name|deref
argument_list|()
condition|)
block|{
name|QTest
operator|::
name|TestLoggers
operator|::
name|addMessage
argument_list|(
name|QAbstractTestLogger
operator|::
name|QSystem
argument_list|,
literal|"Maximum amount of warnings exceeded. Use -maxwarnings to override."
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QtDebugMsg
case|:
name|QTest
operator|::
name|TestLoggers
operator|::
name|addMessage
argument_list|(
name|QAbstractTestLogger
operator|::
name|QDebug
argument_list|,
name|msg
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtCriticalMsg
case|:
name|QTest
operator|::
name|TestLoggers
operator|::
name|addMessage
argument_list|(
name|QAbstractTestLogger
operator|::
name|QSystem
argument_list|,
name|msg
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtWarningMsg
case|:
name|QTest
operator|::
name|TestLoggers
operator|::
name|addMessage
argument_list|(
name|QAbstractTestLogger
operator|::
name|QWarning
argument_list|,
name|msg
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtFatalMsg
case|:
name|QTest
operator|::
name|TestLoggers
operator|::
name|addMessage
argument_list|(
name|QAbstractTestLogger
operator|::
name|QFatal
argument_list|,
name|msg
argument_list|)
expr_stmt|;
comment|/* Right now, we're inside the custom message handler and we're              * being qt_message_output in qglobal.cpp. After we return from              * this function, it will proceed with calling exit() and abort()              * and hence crash. Therefore, we call these logging functions such              * that we wrap up nicely, and in particular produce well-formed XML. */
name|QTestResult
operator|::
name|addFailure
argument_list|(
literal|"Received a fatal error."
argument_list|,
literal|"Unknown file"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTestLog
operator|::
name|leaveTestFunction
argument_list|()
expr_stmt|;
name|QTestLog
operator|::
name|stopLogging
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
end_namespace
begin_function
DECL|function|enterTestFunction
name|void
name|QTestLog
operator|::
name|enterTestFunction
parameter_list|(
specifier|const
name|char
modifier|*
name|function
parameter_list|)
block|{
if|if
condition|(
name|printAvailableTags
condition|)
return|return;
name|QTEST_ASSERT
argument_list|(
name|function
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|enterTestFunction
argument_list|(
name|function
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unhandledIgnoreMessages
name|int
name|QTestLog
operator|::
name|unhandledIgnoreMessages
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|QTest
operator|::
name|IgnoreResultList
modifier|*
name|list
init|=
name|QTest
operator|::
name|ignoreResultList
decl_stmt|;
while|while
condition|(
name|list
condition|)
block|{
operator|++
name|i
expr_stmt|;
name|list
operator|=
name|list
operator|->
name|next
expr_stmt|;
block|}
return|return
name|i
return|;
block|}
end_function
begin_function
DECL|function|leaveTestFunction
name|void
name|QTestLog
operator|::
name|leaveTestFunction
parameter_list|()
block|{
if|if
condition|(
name|printAvailableTags
condition|)
return|return;
name|QTest
operator|::
name|IgnoreResultList
operator|::
name|clearList
argument_list|(
name|QTest
operator|::
name|ignoreResultList
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|leaveTestFunction
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printUnhandledIgnoreMessages
name|void
name|QTestLog
operator|::
name|printUnhandledIgnoreMessages
parameter_list|()
block|{
name|char
name|msg
index|[
literal|1024
index|]
decl_stmt|;
name|QTest
operator|::
name|IgnoreResultList
modifier|*
name|list
init|=
name|QTest
operator|::
name|ignoreResultList
decl_stmt|;
while|while
condition|(
name|list
condition|)
block|{
name|qsnprintf
argument_list|(
name|msg
argument_list|,
literal|1024
argument_list|,
literal|"Did not receive message: \"%s\""
argument_list|,
name|list
operator|->
name|msg
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|addMessage
argument_list|(
name|QAbstractTestLogger
operator|::
name|Info
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|list
operator|=
name|list
operator|->
name|next
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|addPass
name|void
name|QTestLog
operator|::
name|addPass
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
if|if
condition|(
name|printAvailableTags
condition|)
return|return;
name|QTEST_ASSERT
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|addIncident
argument_list|(
name|QAbstractTestLogger
operator|::
name|Pass
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addFail
name|void
name|QTestLog
operator|::
name|addFail
parameter_list|(
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
name|QTEST_ASSERT
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|addIncident
argument_list|(
name|QAbstractTestLogger
operator|::
name|Fail
argument_list|,
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addXFail
name|void
name|QTestLog
operator|::
name|addXFail
parameter_list|(
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
name|QTEST_ASSERT
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|addIncident
argument_list|(
name|QAbstractTestLogger
operator|::
name|XFail
argument_list|,
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addXPass
name|void
name|QTestLog
operator|::
name|addXPass
parameter_list|(
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
name|QTEST_ASSERT
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|addIncident
argument_list|(
name|QAbstractTestLogger
operator|::
name|XPass
argument_list|,
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addSkip
name|void
name|QTestLog
operator|::
name|addSkip
parameter_list|(
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
name|QTEST_ASSERT
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|addMessage
argument_list|(
name|QAbstractTestLogger
operator|::
name|Skip
argument_list|,
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addBenchmarkResult
name|void
name|QTestLog
operator|::
name|addBenchmarkResult
parameter_list|(
specifier|const
name|QBenchmarkResult
modifier|&
name|result
parameter_list|)
block|{
name|QTest
operator|::
name|TestLoggers
operator|::
name|addBenchmarkResult
argument_list|(
name|result
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startLogging
name|void
name|QTestLog
operator|::
name|startLogging
parameter_list|()
block|{
name|QTest
operator|::
name|TestLoggers
operator|::
name|startLogging
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|oldMessageHandler
operator|=
name|qInstallMsgHandler
argument_list|(
name|QTest
operator|::
name|messageHandler
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stopLogging
name|void
name|QTestLog
operator|::
name|stopLogging
parameter_list|()
block|{
name|qInstallMsgHandler
argument_list|(
name|QTest
operator|::
name|oldMessageHandler
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|stopLogging
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|destroyLoggers
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|loggerUsingStdout
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addLogger
name|void
name|QTestLog
operator|::
name|addLogger
parameter_list|(
name|LogMode
name|mode
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
block|{
if|if
condition|(
name|filename
operator|&&
name|strcmp
argument_list|(
name|filename
argument_list|,
literal|"-"
argument_list|)
operator|==
literal|0
condition|)
name|filename
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|filename
condition|)
name|QTest
operator|::
name|loggerUsingStdout
operator|=
literal|true
expr_stmt|;
name|QAbstractTestLogger
modifier|*
name|logger
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|QTestLog
operator|::
name|Plain
case|:
name|logger
operator|=
operator|new
name|QPlainTestLogger
argument_list|(
name|filename
argument_list|)
expr_stmt|;
break|break;
case|case
name|QTestLog
operator|::
name|XML
case|:
name|logger
operator|=
operator|new
name|QXmlTestLogger
argument_list|(
name|QXmlTestLogger
operator|::
name|Complete
argument_list|,
name|filename
argument_list|)
expr_stmt|;
break|break;
case|case
name|QTestLog
operator|::
name|LightXML
case|:
name|logger
operator|=
operator|new
name|QXmlTestLogger
argument_list|(
name|QXmlTestLogger
operator|::
name|Light
argument_list|,
name|filename
argument_list|)
expr_stmt|;
break|break;
case|case
name|QTestLog
operator|::
name|XunitXML
case|:
name|logger
operator|=
operator|new
name|QXunitTestLogger
argument_list|(
name|filename
argument_list|)
expr_stmt|;
break|break;
block|}
name|QTEST_ASSERT
argument_list|(
name|logger
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|addLogger
argument_list|(
name|logger
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loggerCount
name|int
name|QTestLog
operator|::
name|loggerCount
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|TestLoggers
operator|::
name|loggerCount
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|loggerUsingStdout
name|bool
name|QTestLog
operator|::
name|loggerUsingStdout
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|loggerUsingStdout
return|;
block|}
end_function
begin_function
DECL|function|warn
name|void
name|QTestLog
operator|::
name|warn
parameter_list|(
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
name|QTEST_ASSERT
argument_list|(
name|msg
argument_list|)
expr_stmt|;
if|if
condition|(
name|QTest
operator|::
name|TestLoggers
operator|::
name|loggerCount
argument_list|()
operator|>
literal|0
condition|)
name|QTest
operator|::
name|TestLoggers
operator|::
name|addMessage
argument_list|(
name|QAbstractTestLogger
operator|::
name|Warn
argument_list|,
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|info
name|void
name|QTestLog
operator|::
name|info
parameter_list|(
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
name|QTEST_ASSERT
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|TestLoggers
operator|::
name|addMessage
argument_list|(
name|QAbstractTestLogger
operator|::
name|Info
argument_list|,
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setVerboseLevel
name|void
name|QTestLog
operator|::
name|setVerboseLevel
parameter_list|(
name|int
name|level
parameter_list|)
block|{
name|QTest
operator|::
name|verbosity
operator|=
name|level
expr_stmt|;
block|}
end_function
begin_function
DECL|function|verboseLevel
name|int
name|QTestLog
operator|::
name|verboseLevel
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|verbosity
return|;
block|}
end_function
begin_function
DECL|function|addIgnoreMessage
name|void
name|QTestLog
operator|::
name|addIgnoreMessage
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|QTEST_ASSERT
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|IgnoreResultList
modifier|*
name|item
init|=
operator|new
name|QTest
operator|::
name|IgnoreResultList
argument_list|(
name|type
argument_list|,
name|msg
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|IgnoreResultList
modifier|*
name|list
init|=
name|QTest
operator|::
name|ignoreResultList
decl_stmt|;
if|if
condition|(
operator|!
name|list
condition|)
block|{
name|QTest
operator|::
name|ignoreResultList
operator|=
name|item
expr_stmt|;
return|return;
block|}
while|while
condition|(
name|list
operator|->
name|next
condition|)
name|list
operator|=
name|list
operator|->
name|next
expr_stmt|;
name|list
operator|->
name|next
operator|=
name|item
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setMaxWarnings
name|void
name|QTestLog
operator|::
name|setMaxWarnings
parameter_list|(
name|int
name|m
parameter_list|)
block|{
name|QTest
operator|::
name|maxWarnings
operator|=
name|m
operator|<=
literal|0
condition|?
name|INT_MAX
else|:
name|m
operator|+
literal|2
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|member|printAvailableTags
name|bool
name|QTestLog
operator|::
name|printAvailableTags
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|setPrintAvailableTagsMode
name|void
name|QTestLog
operator|::
name|setPrintAvailableTagsMode
parameter_list|()
block|{
name|printAvailableTags
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
