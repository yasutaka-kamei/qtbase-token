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
file|<QtTest/private/qplaintestlogger_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmark_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkmetric_p.h>
end_include
begin_include
include|#
directive|include
file|<stdarg.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
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
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_ANDROID
end_ifdef
begin_include
include|#
directive|include
file|<android/log.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QTest
namespace|namespace
name|QTest
block|{
DECL|function|incidentType2String
specifier|static
specifier|const
name|char
modifier|*
name|incidentType2String
parameter_list|(
name|QAbstractTestLogger
operator|::
name|IncidentTypes
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QAbstractTestLogger
operator|::
name|Pass
case|:
return|return
literal|"PASS   "
return|;
case|case
name|QAbstractTestLogger
operator|::
name|XFail
case|:
return|return
literal|"XFAIL  "
return|;
case|case
name|QAbstractTestLogger
operator|::
name|Fail
case|:
return|return
literal|"FAIL!  "
return|;
case|case
name|QAbstractTestLogger
operator|::
name|XPass
case|:
return|return
literal|"XPASS  "
return|;
block|}
return|return
literal|"??????"
return|;
block|}
DECL|function|benchmarkResult2String
specifier|static
specifier|const
name|char
modifier|*
name|benchmarkResult2String
parameter_list|()
block|{
return|return
literal|"RESULT "
return|;
block|}
DECL|function|messageType2String
specifier|static
specifier|const
name|char
modifier|*
name|messageType2String
parameter_list|(
name|QAbstractTestLogger
operator|::
name|MessageTypes
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QAbstractTestLogger
operator|::
name|Skip
case|:
return|return
literal|"SKIP   "
return|;
case|case
name|QAbstractTestLogger
operator|::
name|Warn
case|:
return|return
literal|"WARNING"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|QWarning
case|:
return|return
literal|"QWARN  "
return|;
case|case
name|QAbstractTestLogger
operator|::
name|QDebug
case|:
return|return
literal|"QDEBUG "
return|;
case|case
name|QAbstractTestLogger
operator|::
name|QSystem
case|:
return|return
literal|"QSYSTEM"
return|;
case|case
name|QAbstractTestLogger
operator|::
name|QFatal
case|:
return|return
literal|"QFATAL "
return|;
case|case
name|QAbstractTestLogger
operator|::
name|Info
case|:
return|return
literal|"INFO   "
return|;
block|}
return|return
literal|"??????"
return|;
block|}
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|countSignificantDigits
specifier|static
name|int
name|countSignificantDigits
parameter_list|(
name|T
name|num
parameter_list|)
block|{
if|if
condition|(
name|num
operator|<=
literal|0
condition|)
return|return
literal|0
return|;
name|int
name|digits
init|=
literal|0
decl_stmt|;
name|qreal
name|divisor
init|=
literal|1
decl_stmt|;
while|while
condition|(
name|num
operator|/
name|divisor
operator|>=
literal|1
condition|)
block|{
name|divisor
operator|*=
literal|10
expr_stmt|;
operator|++
name|digits
expr_stmt|;
block|}
return|return
name|digits
return|;
block|}
comment|// Pretty-prints a benchmark result using the given number of digits.
DECL|function|formatResult
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
name|QString
name|formatResult
parameter_list|(
name|T
name|number
parameter_list|,
name|int
name|significantDigits
parameter_list|)
block|{
if|if
condition|(
name|number
operator|<
name|T
argument_list|(
literal|0
argument_list|)
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"NAN"
argument_list|)
return|;
if|if
condition|(
name|number
operator|==
name|T
argument_list|(
literal|0
argument_list|)
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"0"
argument_list|)
return|;
name|QString
name|beforeDecimalPoint
init|=
name|QString
operator|::
name|number
argument_list|(
name|qint64
argument_list|(
name|number
argument_list|)
argument_list|,
literal|'f'
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QString
name|afterDecimalPoint
init|=
name|QString
operator|::
name|number
argument_list|(
name|number
argument_list|,
literal|'f'
argument_list|,
literal|20
argument_list|)
decl_stmt|;
name|afterDecimalPoint
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|beforeDecimalPoint
operator|.
name|count
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
name|int
name|beforeUse
init|=
name|qMin
argument_list|(
name|beforeDecimalPoint
operator|.
name|count
argument_list|()
argument_list|,
name|significantDigits
argument_list|)
decl_stmt|;
name|int
name|beforeRemove
init|=
name|beforeDecimalPoint
operator|.
name|count
argument_list|()
operator|-
name|beforeUse
decl_stmt|;
comment|// Replace insignificant digits before the decimal point with zeros.
name|beforeDecimalPoint
operator|.
name|chop
argument_list|(
name|beforeRemove
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|beforeRemove
condition|;
operator|++
name|i
control|)
block|{
name|beforeDecimalPoint
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'0'
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|int
name|afterUse
init|=
name|significantDigits
operator|-
name|beforeUse
decl_stmt|;
comment|// leading zeroes after the decimal point does not count towards the digit use.
if|if
condition|(
name|beforeDecimalPoint
operator|==
name|QLatin1String
argument_list|(
literal|"0"
argument_list|)
operator|&&
name|afterDecimalPoint
operator|.
name|isEmpty
argument_list|()
operator|==
literal|false
condition|)
block|{
operator|++
name|afterUse
expr_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|afterDecimalPoint
operator|.
name|count
argument_list|()
operator|&&
name|afterDecimalPoint
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'0'
argument_list|)
condition|)
block|{
operator|++
name|i
expr_stmt|;
block|}
name|afterUse
operator|+=
name|i
expr_stmt|;
block|}
name|int
name|afterRemove
init|=
name|afterDecimalPoint
operator|.
name|count
argument_list|()
operator|-
name|afterUse
decl_stmt|;
name|afterDecimalPoint
operator|.
name|chop
argument_list|(
name|afterRemove
argument_list|)
expr_stmt|;
name|QChar
name|separator
init|=
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
decl_stmt|;
name|QChar
name|decimalPoint
init|=
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
decl_stmt|;
comment|// insert thousands separators
name|int
name|length
init|=
name|beforeDecimalPoint
operator|.
name|length
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|beforeDecimalPoint
operator|.
name|length
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|1
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
operator|(
name|length
operator|-
name|i
operator|)
operator|%
literal|3
operator|==
literal|0
condition|)
name|beforeDecimalPoint
operator|.
name|insert
argument_list|(
name|i
argument_list|,
name|separator
argument_list|)
expr_stmt|;
block|}
name|QString
name|print
decl_stmt|;
name|print
operator|=
name|beforeDecimalPoint
expr_stmt|;
if|if
condition|(
name|afterUse
operator|>
literal|0
condition|)
name|print
operator|.
name|append
argument_list|(
name|decimalPoint
argument_list|)
expr_stmt|;
name|print
operator|+=
name|afterDecimalPoint
expr_stmt|;
return|return
name|print
return|;
block|}
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|formatResult
name|int
name|formatResult
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|bufferSize
parameter_list|,
name|T
name|number
parameter_list|,
name|int
name|significantDigits
parameter_list|)
block|{
name|QString
name|result
init|=
name|formatResult
argument_list|(
name|number
argument_list|,
name|significantDigits
argument_list|)
decl_stmt|;
name|qstrncpy
argument_list|(
name|buffer
argument_list|,
name|result
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|bufferSize
argument_list|)
expr_stmt|;
name|int
name|size
init|=
name|result
operator|.
name|count
argument_list|()
decl_stmt|;
return|return
name|size
return|;
block|}
block|}
end_namespace
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_function_decl
name|Q_CORE_EXPORT
name|bool
name|qWinLogToStderr
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// defined in qlogging.cpp
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|outputMessage
name|void
name|QPlainTestLogger
operator|::
name|outputMessage
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|QString
name|strUtf16
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|str
argument_list|)
decl_stmt|;
specifier|const
name|int
name|maxOutputLength
init|=
literal|255
decl_stmt|;
do|do
block|{
name|QString
name|tmp
init|=
name|strUtf16
operator|.
name|left
argument_list|(
name|maxOutputLength
argument_list|)
decl_stmt|;
name|OutputDebugString
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|tmp
operator|.
name|utf16
argument_list|()
argument_list|)
expr_stmt|;
name|strUtf16
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|maxOutputLength
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|strUtf16
operator|.
name|isEmpty
argument_list|()
condition|)
do|;
if|if
condition|(
name|stream
operator|!=
name|stdout
condition|)
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
comment|// log to system log only if output is not redirected, and no console is attached
if|if
condition|(
operator|!
name|qWinLogToStderr
argument_list|()
operator|&&
name|stream
operator|==
name|stdout
condition|)
block|{
name|OutputDebugStringA
argument_list|(
name|str
argument_list|)
expr_stmt|;
return|return;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
name|__android_log_write
argument_list|(
name|ANDROID_LOG_INFO
argument_list|,
literal|"QTestLib"
argument_list|,
name|str
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|outputString
argument_list|(
name|str
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printMessage
name|void
name|QPlainTestLogger
operator|::
name|printMessage
parameter_list|(
specifier|const
name|char
modifier|*
name|type
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
name|QTEST_ASSERT
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|QTestCharBuffer
name|buf
decl_stmt|;
specifier|const
name|char
modifier|*
name|fn
init|=
name|QTestResult
operator|::
name|currentTestFunction
argument_list|()
condition|?
name|QTestResult
operator|::
name|currentTestFunction
argument_list|()
else|:
literal|"UnknownTestFunc"
decl_stmt|;
specifier|const
name|char
modifier|*
name|tag
init|=
name|QTestResult
operator|::
name|currentDataTag
argument_list|()
condition|?
name|QTestResult
operator|::
name|currentDataTag
argument_list|()
else|:
literal|""
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
condition|?
name|QTestResult
operator|::
name|currentGlobalDataTag
argument_list|()
else|:
literal|""
decl_stmt|;
specifier|const
name|char
modifier|*
name|filler
init|=
operator|(
name|tag
index|[
literal|0
index|]
operator|&&
name|gtag
index|[
literal|0
index|]
operator|)
condition|?
literal|":"
else|:
literal|""
decl_stmt|;
if|if
condition|(
name|file
condition|)
block|{
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"%s: %s::%s(%s%s%s)%s%s\n"
ifdef|#
directive|ifdef
name|Q_OS_WIN
literal|"%s(%d) : failure location\n"
else|#
directive|else
literal|"   Loc: [%s(%d)]\n"
endif|#
directive|endif
argument_list|,
name|type
argument_list|,
name|QTestResult
operator|::
name|currentTestObjectName
argument_list|()
argument_list|,
name|fn
argument_list|,
name|gtag
argument_list|,
name|filler
argument_list|,
name|tag
argument_list|,
name|msg
index|[
literal|0
index|]
condition|?
literal|" "
else|:
literal|""
argument_list|,
name|msg
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"%s: %s::%s(%s%s%s)%s%s\n"
argument_list|,
name|type
argument_list|,
name|QTestResult
operator|::
name|currentTestObjectName
argument_list|()
argument_list|,
name|fn
argument_list|,
name|gtag
argument_list|,
name|filler
argument_list|,
name|tag
argument_list|,
name|msg
index|[
literal|0
index|]
condition|?
literal|" "
else|:
literal|""
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
comment|// In colored mode, printf above stripped our nonprintable control characters.
comment|// Put them back.
name|memcpy
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|,
name|type
argument_list|,
name|strlen
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
name|outputMessage
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printBenchmarkResult
name|void
name|QPlainTestLogger
operator|::
name|printBenchmarkResult
parameter_list|(
specifier|const
name|QBenchmarkResult
modifier|&
name|result
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|bmtag
init|=
name|QTest
operator|::
name|benchmarkResult2String
argument_list|()
decl_stmt|;
name|char
name|buf1
index|[
literal|1024
index|]
decl_stmt|;
name|qsnprintf
argument_list|(
name|buf1
argument_list|,
sizeof|sizeof
argument_list|(
name|buf1
argument_list|)
argument_list|,
literal|"%s: %s::%s"
argument_list|,
name|bmtag
argument_list|,
name|QTestResult
operator|::
name|currentTestObjectName
argument_list|()
argument_list|,
name|result
operator|.
name|context
operator|.
name|slotName
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|char
name|bufTag
index|[
literal|1024
index|]
decl_stmt|;
name|bufTag
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|QByteArray
name|tag
init|=
name|result
operator|.
name|context
operator|.
name|tag
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
if|if
condition|(
name|tag
operator|.
name|isEmpty
argument_list|()
operator|==
literal|false
condition|)
block|{
name|qsnprintf
argument_list|(
name|bufTag
argument_list|,
sizeof|sizeof
argument_list|(
name|bufTag
argument_list|)
argument_list|,
literal|":\"%s\""
argument_list|,
name|tag
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|char
name|fillFormat
index|[
literal|8
index|]
decl_stmt|;
name|int
name|fillLength
init|=
literal|5
decl_stmt|;
name|qsnprintf
argument_list|(
name|fillFormat
argument_list|,
sizeof|sizeof
argument_list|(
name|fillFormat
argument_list|)
argument_list|,
literal|":\n%%%ds"
argument_list|,
name|fillLength
argument_list|)
expr_stmt|;
name|char
name|fill
index|[
literal|1024
index|]
decl_stmt|;
name|qsnprintf
argument_list|(
name|fill
argument_list|,
sizeof|sizeof
argument_list|(
name|fill
argument_list|)
argument_list|,
name|fillFormat
argument_list|,
literal|""
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|unitText
init|=
name|QTest
operator|::
name|benchmarkMetricUnit
argument_list|(
name|result
operator|.
name|metric
argument_list|)
decl_stmt|;
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
name|char
name|resultBuffer
index|[
literal|100
index|]
init|=
literal|""
decl_stmt|;
name|QTest
operator|::
name|formatResult
argument_list|(
name|resultBuffer
argument_list|,
literal|100
argument_list|,
name|valuePerIteration
argument_list|,
name|QTest
operator|::
name|countSignificantDigits
argument_list|(
name|result
operator|.
name|value
argument_list|)
argument_list|)
expr_stmt|;
name|char
name|buf2
index|[
literal|1024
index|]
decl_stmt|;
name|qsnprintf
argument_list|(
name|buf2
argument_list|,
sizeof|sizeof
argument_list|(
name|buf2
argument_list|)
argument_list|,
literal|"%s %s"
argument_list|,
name|resultBuffer
argument_list|,
name|unitText
argument_list|)
expr_stmt|;
name|char
name|buf2_
index|[
literal|1024
index|]
decl_stmt|;
name|QByteArray
name|iterationText
init|=
literal|" per iteration"
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|result
operator|.
name|iterations
operator|>
literal|0
argument_list|)
expr_stmt|;
name|qsnprintf
argument_list|(
name|buf2_
argument_list|,
sizeof|sizeof
argument_list|(
name|buf2_
argument_list|)
argument_list|,
literal|"%s"
argument_list|,
name|iterationText
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|char
name|buf3
index|[
literal|1024
index|]
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|result
operator|.
name|iterations
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|formatResult
argument_list|(
name|resultBuffer
argument_list|,
literal|100
argument_list|,
name|result
operator|.
name|value
argument_list|,
name|QTest
operator|::
name|countSignificantDigits
argument_list|(
name|result
operator|.
name|value
argument_list|)
argument_list|)
expr_stmt|;
name|qsnprintf
argument_list|(
name|buf3
argument_list|,
sizeof|sizeof
argument_list|(
name|buf3
argument_list|)
argument_list|,
literal|" (total: %s, iterations: %d)"
argument_list|,
name|resultBuffer
argument_list|,
name|result
operator|.
name|iterations
argument_list|)
expr_stmt|;
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
if|if
condition|(
name|result
operator|.
name|setByMacro
condition|)
block|{
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%s%s%s%s%s%s\n"
argument_list|,
name|buf1
argument_list|,
name|bufTag
argument_list|,
name|fill
argument_list|,
name|buf2
argument_list|,
name|buf2_
argument_list|,
name|buf3
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%s%s%s%s\n"
argument_list|,
name|buf1
argument_list|,
name|bufTag
argument_list|,
name|fill
argument_list|,
name|buf2
argument_list|)
expr_stmt|;
block|}
name|memcpy
argument_list|(
name|buf
argument_list|,
name|bmtag
argument_list|,
name|strlen
argument_list|(
name|bmtag
argument_list|)
argument_list|)
expr_stmt|;
name|outputMessage
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QPlainTestLogger
name|QPlainTestLogger
operator|::
name|QPlainTestLogger
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
block|{ }
end_constructor
begin_destructor
DECL|function|~QPlainTestLogger
name|QPlainTestLogger
operator|::
name|~
name|QPlainTestLogger
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|startLogging
name|void
name|QPlainTestLogger
operator|::
name|startLogging
parameter_list|()
block|{
name|QAbstractTestLogger
operator|::
name|startLogging
argument_list|()
expr_stmt|;
name|char
name|buf
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
operator|<
literal|0
condition|)
block|{
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"Testing %s\n"
argument_list|,
name|QTestResult
operator|::
name|currentTestObjectName
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"********* Start testing of %s *********\n"
literal|"Config: Using QtTest library "
name|QTEST_VERSION_STR
literal|", Qt %s\n"
argument_list|,
name|QTestResult
operator|::
name|currentTestObjectName
argument_list|()
argument_list|,
name|qVersion
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|outputMessage
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stopLogging
name|void
name|QPlainTestLogger
operator|::
name|stopLogging
parameter_list|()
block|{
name|char
name|buf
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
operator|<
literal|0
condition|)
block|{
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"Totals: %d passed, %d failed, %d skipped\n"
argument_list|,
name|QTestLog
operator|::
name|passCount
argument_list|()
argument_list|,
name|QTestLog
operator|::
name|failCount
argument_list|()
argument_list|,
name|QTestLog
operator|::
name|skipCount
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qsnprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"Totals: %d passed, %d failed, %d skipped\n"
literal|"********* Finished testing of %s *********\n"
argument_list|,
name|QTestLog
operator|::
name|passCount
argument_list|()
argument_list|,
name|QTestLog
operator|::
name|failCount
argument_list|()
argument_list|,
name|QTestLog
operator|::
name|skipCount
argument_list|()
argument_list|,
name|QTestResult
operator|::
name|currentTestObjectName
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|outputMessage
argument_list|(
name|buf
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
name|QPlainTestLogger
operator|::
name|enterTestFunction
parameter_list|(
specifier|const
name|char
modifier|*
comment|/*function*/
parameter_list|)
block|{
if|if
condition|(
name|QTestLog
operator|::
name|verboseLevel
argument_list|()
operator|>=
literal|1
condition|)
name|printMessage
argument_list|(
name|QTest
operator|::
name|messageType2String
argument_list|(
name|Info
argument_list|)
argument_list|,
literal|"entering"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|leaveTestFunction
name|void
name|QPlainTestLogger
operator|::
name|leaveTestFunction
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|addIncident
name|void
name|QPlainTestLogger
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
comment|// suppress PASS and XFAIL in silent mode
if|if
condition|(
operator|(
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|Pass
operator|||
name|type
operator|==
name|QAbstractTestLogger
operator|::
name|XFail
operator|)
operator|&&
name|QTestLog
operator|::
name|verboseLevel
argument_list|()
operator|<
literal|0
condition|)
return|return;
name|printMessage
argument_list|(
name|QTest
operator|::
name|incidentType2String
argument_list|(
name|type
argument_list|)
argument_list|,
name|description
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
name|QPlainTestLogger
operator|::
name|addBenchmarkResult
parameter_list|(
specifier|const
name|QBenchmarkResult
modifier|&
name|result
parameter_list|)
block|{
comment|// suppress benchmark results in silent mode
if|if
condition|(
name|QTestLog
operator|::
name|verboseLevel
argument_list|()
operator|<
literal|0
condition|)
return|return;
name|printBenchmarkResult
argument_list|(
name|result
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addMessage
name|void
name|QPlainTestLogger
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
comment|// suppress non-fatal messages in silent mode
if|if
condition|(
name|type
operator|!=
name|QAbstractTestLogger
operator|::
name|QFatal
operator|&&
name|QTestLog
operator|::
name|verboseLevel
argument_list|()
operator|<
literal|0
condition|)
return|return;
name|printMessage
argument_list|(
name|QTest
operator|::
name|messageType2String
argument_list|(
name|type
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|message
argument_list|)
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
