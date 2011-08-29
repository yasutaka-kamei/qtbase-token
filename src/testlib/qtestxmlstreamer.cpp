begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtestxmlstreamer.h"
end_include
begin_include
include|#
directive|include
file|"qtestelement.h"
end_include
begin_include
include|#
directive|include
file|"qtestelementattribute.h"
end_include
begin_include
include|#
directive|include
file|"qtestlogger_p.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/private/qtestlog_p.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/private/qtestresult_p.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/private/qxmltestlogger_p.h"
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QTestXmlStreamer
name|QTestXmlStreamer
operator|::
name|QTestXmlStreamer
parameter_list|(
name|QTestLogger
modifier|*
name|logger
parameter_list|)
member_init_list|:
name|QTestBasicStreamer
argument_list|(
name|logger
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QTestXmlStreamer
name|QTestXmlStreamer
operator|::
name|~
name|QTestXmlStreamer
parameter_list|()
block|{}
end_destructor
begin_function
DECL|function|formatStart
name|void
name|QTestXmlStreamer
operator|::
name|formatStart
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
switch|switch
condition|(
name|element
operator|->
name|elementType
argument_list|()
condition|)
block|{
case|case
name|QTest
operator|::
name|LET_TestCase
case|:
block|{
name|QTestCharBuffer
name|quotedTf
decl_stmt|;
name|QXmlTestLogger
operator|::
name|xmlQuote
argument_list|(
operator|&
name|quotedTf
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Name
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"<TestFunction name=\"%s\">\n"
argument_list|,
name|quotedTf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QTest
operator|::
name|LET_Failure
case|:
block|{
name|QTestCharBuffer
name|cdataDesc
decl_stmt|;
name|QXmlTestLogger
operator|::
name|xmlCdata
argument_list|(
operator|&
name|cdataDesc
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Description
argument_list|)
argument_list|)
expr_stmt|;
name|QTestCharBuffer
name|location
decl_stmt|;
name|QTestCharBuffer
name|quotedFile
decl_stmt|;
name|QXmlTestLogger
operator|::
name|xmlQuote
argument_list|(
operator|&
name|quotedFile
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_File
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|location
argument_list|,
literal|"%s=\"%s\" %s=\"%s\""
argument_list|,
name|element
operator|->
name|attributeName
argument_list|(
name|QTest
operator|::
name|AI_File
argument_list|)
argument_list|,
name|quotedFile
operator|.
name|constData
argument_list|()
argument_list|,
name|element
operator|->
name|attributeName
argument_list|(
name|QTest
operator|::
name|AI_Line
argument_list|)
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Line
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|element
operator|->
name|attribute
argument_list|(
name|QTest
operator|::
name|AI_Tag
argument_list|)
condition|)
block|{
name|QTestCharBuffer
name|cdataTag
decl_stmt|;
name|QXmlTestLogger
operator|::
name|xmlCdata
argument_list|(
operator|&
name|cdataTag
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Tag
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"<Incident type=\"%s\" %s>\n"
literal|"<DataTag><![CDATA[%s]]></DataTag>\n"
literal|"<Description><![CDATA[%s]]></Description>\n"
literal|"</Incident>\n"
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Result
argument_list|)
argument_list|,
name|location
operator|.
name|constData
argument_list|()
argument_list|,
name|cdataTag
operator|.
name|constData
argument_list|()
argument_list|,
name|cdataDesc
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"<Incident type=\"%s\" %s>\n"
literal|"<Description><![CDATA[%s]]></Description>\n"
literal|"</Incident>\n"
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Result
argument_list|)
argument_list|,
name|location
operator|.
name|constData
argument_list|()
argument_list|,
name|cdataDesc
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
case|case
name|QTest
operator|::
name|LET_Error
case|:
block|{
comment|// assuming type and attribute names don't need quoting
name|QTestCharBuffer
name|quotedFile
decl_stmt|;
name|QTestCharBuffer
name|cdataDesc
decl_stmt|;
name|QXmlTestLogger
operator|::
name|xmlQuote
argument_list|(
operator|&
name|quotedFile
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_File
argument_list|)
argument_list|)
expr_stmt|;
name|QXmlTestLogger
operator|::
name|xmlCdata
argument_list|(
operator|&
name|cdataDesc
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Description
argument_list|)
argument_list|)
expr_stmt|;
name|QTestCharBuffer
name|tagbuf
decl_stmt|;
if|if
condition|(
name|element
operator|->
name|attribute
argument_list|(
name|QTest
operator|::
name|AI_Tag
argument_list|)
condition|)
block|{
name|QTestCharBuffer
name|cdataTag
decl_stmt|;
name|QXmlTestLogger
operator|::
name|xmlCdata
argument_list|(
operator|&
name|cdataTag
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Tag
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|tagbuf
argument_list|,
literal|"<DataTag><![CDATA[%s]]></DataTag>\n"
argument_list|,
name|cdataTag
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"<Message type=\"%s\" %s=\"%s\" %s=\"%s\">\n%s<Description><![CDATA[%s]]></Description>\n</Message>\n"
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Type
argument_list|)
argument_list|,
name|element
operator|->
name|attributeName
argument_list|(
name|QTest
operator|::
name|AI_File
argument_list|)
argument_list|,
name|quotedFile
operator|.
name|constData
argument_list|()
argument_list|,
name|element
operator|->
name|attributeName
argument_list|(
name|QTest
operator|::
name|AI_Line
argument_list|)
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Line
argument_list|)
argument_list|,
name|tagbuf
operator|.
name|constData
argument_list|()
argument_list|,
name|cdataDesc
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QTest
operator|::
name|LET_Benchmark
case|:
block|{
comment|// assuming value and iterations don't need quoting
name|QTestCharBuffer
name|quotedMetric
decl_stmt|;
name|QTestCharBuffer
name|quotedTag
decl_stmt|;
name|QXmlTestLogger
operator|::
name|xmlQuote
argument_list|(
operator|&
name|quotedMetric
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Metric
argument_list|)
argument_list|)
expr_stmt|;
name|QXmlTestLogger
operator|::
name|xmlQuote
argument_list|(
operator|&
name|quotedTag
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Tag
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"<BenchmarkResult %s=\"%s\" %s=\"%s\" %s=\"%s\" %s=\"%s\" />\n"
argument_list|,
name|element
operator|->
name|attributeName
argument_list|(
name|QTest
operator|::
name|AI_Metric
argument_list|)
argument_list|,
name|quotedMetric
operator|.
name|constData
argument_list|()
argument_list|,
name|element
operator|->
name|attributeName
argument_list|(
name|QTest
operator|::
name|AI_Tag
argument_list|)
argument_list|,
name|quotedTag
operator|.
name|constData
argument_list|()
argument_list|,
name|element
operator|->
name|attributeName
argument_list|(
name|QTest
operator|::
name|AI_Value
argument_list|)
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Value
argument_list|)
argument_list|,
name|element
operator|->
name|attributeName
argument_list|(
name|QTest
operator|::
name|AI_Iterations
argument_list|)
argument_list|,
name|element
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Iterations
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|formatEnd
name|void
name|QTestXmlStreamer
operator|::
name|formatEnd
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
if|if
condition|(
name|element
operator|->
name|elementType
argument_list|()
operator|==
name|QTest
operator|::
name|LET_TestCase
condition|)
block|{
name|bool
name|failed
init|=
literal|false
decl_stmt|;
for|for
control|(
name|QTestElement
modifier|*
name|child
init|=
name|element
operator|->
name|childElements
argument_list|()
init|;
name|child
condition|;
name|child
operator|=
name|child
operator|->
name|nextElement
argument_list|()
control|)
block|{
if|if
condition|(
name|child
operator|->
name|elementType
argument_list|()
operator|==
name|QTest
operator|::
name|LET_Failure
operator|&&
name|child
operator|->
name|attribute
argument_list|(
name|QTest
operator|::
name|AI_Result
argument_list|)
operator|&&
operator|(
operator|!
name|strcmp
argument_list|(
name|child
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Result
argument_list|)
argument_list|,
literal|"fail"
argument_list|)
operator|||
operator|!
name|strcmp
argument_list|(
name|child
operator|->
name|attributeValue
argument_list|(
name|QTest
operator|::
name|AI_Result
argument_list|)
argument_list|,
literal|"xpass"
argument_list|)
operator|)
condition|)
block|{
name|failed
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
comment|// For passing functions, no Incident has been output yet.
comment|// For failing functions, we already output one.
comment|// Please note: we are outputting "pass" even if there was an xfail etc.
comment|// This is by design (arguably bad design, but dangerous to change now!)
if|if
condition|(
name|element
operator|->
name|attribute
argument_list|(
name|QTest
operator|::
name|AI_Result
argument_list|)
operator|&&
operator|!
name|failed
condition|)
block|{
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"<Incident type=\"pass\" file=\"\" line=\"0\" />\n</TestFunction>\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"</TestFunction>\n"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|formatBeforeAttributes
name|void
name|QTestXmlStreamer
operator|::
name|formatBeforeAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|element
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|output
name|void
name|QTestXmlStreamer
operator|::
name|output
parameter_list|(
name|QTestElement
modifier|*
name|element
parameter_list|)
specifier|const
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
name|QTestCharBuffer
name|quotedTc
decl_stmt|;
name|QXmlTestLogger
operator|::
name|xmlQuote
argument_list|(
operator|&
name|quotedTc
argument_list|,
name|QTestResult
operator|::
name|currentTestObjectName
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n<TestCase name=\"%s\">\n"
argument_list|,
name|quotedTc
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"<Environment>\n<QtVersion>%s</QtVersion>\n<QTestVersion>%s</QTestVersion>\n"
argument_list|,
name|qVersion
argument_list|()
argument_list|,
name|QTEST_VERSION_STR
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"</Environment>\n"
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|QTestBasicStreamer
operator|::
name|output
argument_list|(
name|element
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"</TestCase>\n"
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
