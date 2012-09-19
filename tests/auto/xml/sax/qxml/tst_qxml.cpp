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
file|<qxml.h>
end_include
begin_class
DECL|class|tst_QXml
class|class
name|tst_QXml
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|interpretedAs0D
parameter_list|()
specifier|const
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
name|void
name|exception
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_class
DECL|class|MyXmlEntityResolver
class|class
name|MyXmlEntityResolver
super|:
specifier|public
name|QXmlEntityResolver
block|{
public|public:
DECL|function|MyXmlEntityResolver
name|MyXmlEntityResolver
parameter_list|()
member_init_list|:
name|QXmlEntityResolver
argument_list|()
block|{}
DECL|function|errorString
name|QString
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
DECL|function|resolveEntity
name|bool
name|resolveEntity
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
name|QXmlInputSource
modifier|*
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|MyXmlContentHandler
class|class
name|MyXmlContentHandler
super|:
specifier|public
name|QXmlContentHandler
block|{
public|public:
DECL|function|MyXmlContentHandler
name|MyXmlContentHandler
parameter_list|()
member_init_list|:
name|QXmlContentHandler
argument_list|()
block|{}
DECL|function|characters
name|bool
name|characters
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|endDocument
name|bool
name|endDocument
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|endElement
name|bool
name|endElement
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|endPrefixMapping
name|bool
name|endPrefixMapping
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|errorString
name|QString
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
DECL|function|ignorableWhitespace
name|bool
name|ignorableWhitespace
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|processingInstruction
name|bool
name|processingInstruction
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|setDocumentLocator
name|void
name|setDocumentLocator
parameter_list|(
name|QXmlLocator
modifier|*
parameter_list|)
block|{ }
DECL|function|skippedEntity
name|bool
name|skippedEntity
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|startDocument
name|bool
name|startDocument
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|startElement
name|bool
name|startElement
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QXmlAttributes
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|startPrefixMapping
name|bool
name|startPrefixMapping
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|MyXmlErrorHandler
class|class
name|MyXmlErrorHandler
super|:
specifier|public
name|QXmlErrorHandler
block|{
public|public:
DECL|function|MyXmlErrorHandler
name|MyXmlErrorHandler
parameter_list|()
member_init_list|:
name|QXmlErrorHandler
argument_list|()
block|{}
DECL|function|errorString
name|QString
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
DECL|function|error
name|bool
name|error
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|fatalError
name|bool
name|fatalError
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|warning
name|bool
name|warning
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|MyXmlLexicalHandler
class|class
name|MyXmlLexicalHandler
super|:
specifier|public
name|QXmlLexicalHandler
block|{
public|public:
DECL|function|MyXmlLexicalHandler
name|MyXmlLexicalHandler
parameter_list|()
member_init_list|:
name|QXmlLexicalHandler
argument_list|()
block|{}
DECL|function|comment
name|bool
name|comment
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|endCDATA
name|bool
name|endCDATA
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|endDTD
name|bool
name|endDTD
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|endEntity
name|bool
name|endEntity
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|errorString
name|QString
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
DECL|function|startCDATA
name|bool
name|startCDATA
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
DECL|function|startDTD
name|bool
name|startDTD
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|startEntity
name|bool
name|startEntity
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|MyXmlDeclHandler
class|class
name|MyXmlDeclHandler
super|:
specifier|public
name|QXmlDeclHandler
block|{
public|public:
DECL|function|MyXmlDeclHandler
name|MyXmlDeclHandler
parameter_list|()
member_init_list|:
name|QXmlDeclHandler
argument_list|()
block|{}
DECL|function|attributeDecl
name|bool
name|attributeDecl
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|errorString
name|QString
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
DECL|function|externalEntityDecl
name|bool
name|externalEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
DECL|function|internalEntityDecl
name|bool
name|internalEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QXml
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QXmlSimpleReader
name|obj1
decl_stmt|;
comment|// QXmlEntityResolver* QXmlSimpleReader::entityResolver()
comment|// void QXmlSimpleReader::setEntityResolver(QXmlEntityResolver*)
name|MyXmlEntityResolver
modifier|*
name|var1
init|=
operator|new
name|MyXmlEntityResolver
decl_stmt|;
name|obj1
operator|.
name|setEntityResolver
argument_list|(
name|var1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QXmlEntityResolver
operator|*
argument_list|>
argument_list|(
name|var1
argument_list|)
argument_list|,
name|obj1
operator|.
name|entityResolver
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setEntityResolver
argument_list|(
operator|(
name|QXmlEntityResolver
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QXmlEntityResolver
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|entityResolver
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|var1
expr_stmt|;
comment|// QXmlContentHandler* QXmlSimpleReader::contentHandler()
comment|// void QXmlSimpleReader::setContentHandler(QXmlContentHandler*)
name|MyXmlContentHandler
modifier|*
name|var2
init|=
operator|new
name|MyXmlContentHandler
decl_stmt|;
name|obj1
operator|.
name|setContentHandler
argument_list|(
name|var2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QXmlContentHandler
operator|*
argument_list|>
argument_list|(
name|var2
argument_list|)
argument_list|,
name|obj1
operator|.
name|contentHandler
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setContentHandler
argument_list|(
operator|(
name|QXmlContentHandler
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QXmlContentHandler
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|contentHandler
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|var2
expr_stmt|;
comment|// QXmlErrorHandler* QXmlSimpleReader::errorHandler()
comment|// void QXmlSimpleReader::setErrorHandler(QXmlErrorHandler*)
name|MyXmlErrorHandler
modifier|*
name|var3
init|=
operator|new
name|MyXmlErrorHandler
decl_stmt|;
name|obj1
operator|.
name|setErrorHandler
argument_list|(
name|var3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QXmlErrorHandler
operator|*
argument_list|>
argument_list|(
name|var3
argument_list|)
argument_list|,
name|obj1
operator|.
name|errorHandler
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setErrorHandler
argument_list|(
operator|(
name|QXmlErrorHandler
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QXmlErrorHandler
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|errorHandler
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|var3
expr_stmt|;
comment|// QXmlLexicalHandler* QXmlSimpleReader::lexicalHandler()
comment|// void QXmlSimpleReader::setLexicalHandler(QXmlLexicalHandler*)
name|MyXmlLexicalHandler
modifier|*
name|var4
init|=
operator|new
name|MyXmlLexicalHandler
decl_stmt|;
name|obj1
operator|.
name|setLexicalHandler
argument_list|(
name|var4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QXmlLexicalHandler
operator|*
argument_list|>
argument_list|(
name|var4
argument_list|)
argument_list|,
name|obj1
operator|.
name|lexicalHandler
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setLexicalHandler
argument_list|(
operator|(
name|QXmlLexicalHandler
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QXmlLexicalHandler
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|lexicalHandler
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|var4
expr_stmt|;
comment|// QXmlDeclHandler* QXmlSimpleReader::declHandler()
comment|// void QXmlSimpleReader::setDeclHandler(QXmlDeclHandler*)
name|MyXmlDeclHandler
modifier|*
name|var5
init|=
operator|new
name|MyXmlDeclHandler
decl_stmt|;
name|obj1
operator|.
name|setDeclHandler
argument_list|(
name|var5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QXmlDeclHandler
operator|*
argument_list|>
argument_list|(
name|var5
argument_list|)
argument_list|,
name|obj1
operator|.
name|declHandler
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setDeclHandler
argument_list|(
operator|(
name|QXmlDeclHandler
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QXmlDeclHandler
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|declHandler
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|var5
expr_stmt|;
block|}
end_function
begin_function
DECL|function|interpretedAs0D
name|void
name|tst_QXml
operator|::
name|interpretedAs0D
parameter_list|()
specifier|const
block|{
comment|/* See task 172632. */
class|class
name|MyHandler
super|:
specifier|public
name|QXmlDefaultHandler
block|{
public|public:
specifier|virtual
name|bool
name|startElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceURI
parameter_list|,
specifier|const
name|QString
modifier|&
name|localName
parameter_list|,
specifier|const
name|QString
modifier|&
name|qName
parameter_list|,
specifier|const
name|QXmlAttributes
modifier|&
name|atts
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|namespaceURI
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|localName
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|qName
argument_list|)
expr_stmt|;
name|attrName
operator|=
name|atts
operator|.
name|qName
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|attrCount
operator|=
name|atts
operator|.
name|count
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
name|QString
name|attrName
decl_stmt|;
name|int
name|attrCount
decl_stmt|;
block|}
class|;
specifier|const
name|QString
name|document
argument_list|(
name|QLatin1String
argument_list|(
literal|"<element "
argument_list|)
operator|+
name|QChar
argument_list|(
literal|0x010D
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|"reated-by=\"an attr value\"/>"
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|testFile
init|=
name|QFINDTESTDATA
argument_list|(
literal|"0x010D.xml"
argument_list|)
decl_stmt|;
if|if
condition|(
name|testFile
operator|.
name|isEmpty
argument_list|()
condition|)
name|QFAIL
argument_list|(
literal|"Cannot find test file 0x010D.xml!"
argument_list|)
expr_stmt|;
name|QFile
name|f
argument_list|(
name|testFile
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
argument_list|)
expr_stmt|;
name|QXmlInputSource
name|data
argument_list|(
operator|&
name|f
argument_list|)
decl_stmt|;
name|QXmlSimpleReader
name|reader
decl_stmt|;
name|MyHandler
name|myHandler
decl_stmt|;
name|reader
operator|.
name|setContentHandler
argument_list|(
operator|&
name|myHandler
argument_list|)
expr_stmt|;
name|reader
operator|.
name|setErrorHandler
argument_list|(
operator|&
name|myHandler
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|reader
operator|.
name|parse
argument_list|(
operator|&
name|data
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|myHandler
operator|.
name|attrCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|myHandler
operator|.
name|attrName
argument_list|,
name|QChar
argument_list|(
literal|0x010D
argument_list|)
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"reated-by"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
end_ifndef
begin_function
DECL|function|exception
name|void
name|tst_QXml
operator|::
name|exception
parameter_list|()
block|{
name|QString
name|message
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"message"
argument_list|)
decl_stmt|;
name|int
name|column
init|=
literal|3
decl_stmt|;
name|int
name|line
init|=
literal|2
decl_stmt|;
name|QString
name|publicId
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"publicId"
argument_list|)
decl_stmt|;
name|QString
name|systemId
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"systemId"
argument_list|)
decl_stmt|;
try|try
block|{
name|QXmlParseException
name|e
argument_list|(
name|message
argument_list|,
name|column
argument_list|,
name|line
argument_list|,
name|publicId
argument_list|,
name|systemId
argument_list|)
decl_stmt|;
throw|throw
name|e
throw|;
block|}
catch|catch
parameter_list|(
name|QXmlParseException
name|e
parameter_list|)
block|{
name|QCOMPARE
argument_list|(
name|e
operator|.
name|message
argument_list|()
argument_list|,
name|message
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|columnNumber
argument_list|()
argument_list|,
name|column
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|lineNumber
argument_list|()
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|publicId
argument_list|()
argument_list|,
name|publicId
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|systemId
argument_list|()
argument_list|,
name|systemId
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QXml
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qxml.moc"
end_include
end_unit
