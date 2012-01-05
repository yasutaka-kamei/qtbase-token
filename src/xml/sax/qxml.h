begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtXml module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXML_H
end_ifndef
begin_define
DECL|macro|QXML_H
define|#
directive|define
name|QXML_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Xml
parameter_list|)
name|class
name|QXmlNamespaceSupport
decl_stmt|;
DECL|variable|QXmlAttributes
name|class
name|QXmlAttributes
decl_stmt|;
DECL|variable|QXmlContentHandler
name|class
name|QXmlContentHandler
decl_stmt|;
DECL|variable|QXmlDefaultHandler
name|class
name|QXmlDefaultHandler
decl_stmt|;
DECL|variable|QXmlDTDHandler
name|class
name|QXmlDTDHandler
decl_stmt|;
DECL|variable|QXmlEntityResolver
name|class
name|QXmlEntityResolver
decl_stmt|;
DECL|variable|QXmlErrorHandler
name|class
name|QXmlErrorHandler
decl_stmt|;
DECL|variable|QXmlLexicalHandler
name|class
name|QXmlLexicalHandler
decl_stmt|;
DECL|variable|QXmlDeclHandler
name|class
name|QXmlDeclHandler
decl_stmt|;
DECL|variable|QXmlInputSource
name|class
name|QXmlInputSource
decl_stmt|;
DECL|variable|QXmlLocator
name|class
name|QXmlLocator
decl_stmt|;
DECL|variable|QXmlNamespaceSupport
name|class
name|QXmlNamespaceSupport
decl_stmt|;
DECL|variable|QXmlParseException
name|class
name|QXmlParseException
decl_stmt|;
DECL|variable|QXmlReader
name|class
name|QXmlReader
decl_stmt|;
DECL|variable|QXmlSimpleReader
name|class
name|QXmlSimpleReader
decl_stmt|;
DECL|variable|QXmlSimpleReaderPrivate
name|class
name|QXmlSimpleReaderPrivate
decl_stmt|;
DECL|variable|QXmlNamespaceSupportPrivate
name|class
name|QXmlNamespaceSupportPrivate
decl_stmt|;
DECL|variable|QXmlAttributesPrivate
name|class
name|QXmlAttributesPrivate
decl_stmt|;
DECL|variable|QXmlInputSourcePrivate
name|class
name|QXmlInputSourcePrivate
decl_stmt|;
DECL|variable|QXmlParseExceptionPrivate
name|class
name|QXmlParseExceptionPrivate
decl_stmt|;
DECL|variable|QXmlLocatorPrivate
name|class
name|QXmlLocatorPrivate
decl_stmt|;
DECL|variable|QXmlDefaultHandlerPrivate
name|class
name|QXmlDefaultHandlerPrivate
decl_stmt|;
comment|//
comment|// SAX Namespace Support
comment|//
name|class
name|Q_XML_EXPORT
name|QXmlNamespaceSupport
decl_stmt|{ public:     QXmlNamespaceSupport(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
operator|~
name|QXmlNamespaceSupport
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setPrefix
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QString
name|prefix
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|uri
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|splitName
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|QString
operator|&
argument_list|,
name|QString
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|processName
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
name|bool
argument_list|,
name|QString
operator|&
argument_list|,
name|QString
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QStringList
name|prefixes
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QStringList
name|prefixes
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|pushContext
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|popContext
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|reset
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QXmlNamespaceSupportPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QXmlSimpleReaderPrivate
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QXmlNamespaceSupport
argument_list|)
end_macro
begin_comment
unit|};
comment|//
end_comment
begin_comment
comment|// SAX Attributes
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlAttributes
block|{
name|public
label|:
name|QXmlAttributes
argument_list|()
block|{}
name|virtual
operator|~
name|QXmlAttributes
argument_list|()
block|{}
name|int
name|index
argument_list|(
argument|const QString& qName
argument_list|)
specifier|const
expr_stmt|;
name|int
name|index
argument_list|(
specifier|const
name|QLatin1String
operator|&
name|qName
argument_list|)
decl|const
decl_stmt|;
name|int
name|index
argument_list|(
specifier|const
name|QString
operator|&
name|uri
argument_list|,
specifier|const
name|QString
operator|&
name|localPart
argument_list|)
decl|const
decl_stmt|;
name|int
name|length
argument_list|()
specifier|const
expr_stmt|;
name|int
name|count
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|localName
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QString
name|qName
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QString
name|uri
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QString
name|type
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QString
name|type
argument_list|(
specifier|const
name|QString
operator|&
name|qName
argument_list|)
decl|const
decl_stmt|;
name|QString
name|type
argument_list|(
specifier|const
name|QString
operator|&
name|uri
argument_list|,
specifier|const
name|QString
operator|&
name|localName
argument_list|)
decl|const
decl_stmt|;
name|QString
name|value
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QString
name|value
argument_list|(
specifier|const
name|QString
operator|&
name|qName
argument_list|)
decl|const
decl_stmt|;
name|QString
name|value
argument_list|(
specifier|const
name|QLatin1String
operator|&
name|qName
argument_list|)
decl|const
decl_stmt|;
name|QString
name|value
argument_list|(
specifier|const
name|QString
operator|&
name|uri
argument_list|,
specifier|const
name|QString
operator|&
name|localName
argument_list|)
decl|const
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|append
parameter_list|(
specifier|const
name|QString
modifier|&
name|qName
parameter_list|,
specifier|const
name|QString
modifier|&
name|uri
parameter_list|,
specifier|const
name|QString
modifier|&
name|localPart
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
name|private
label|:
struct|struct
name|Attribute
block|{
name|QString
name|qname
decl_stmt|,
name|uri
decl_stmt|,
name|localname
decl_stmt|,
name|value
decl_stmt|;
block|}
struct|;
typedef|typedef
name|QList
operator|<
name|Attribute
operator|>
name|AttributeList
expr_stmt|;
name|AttributeList
name|attList
decl_stmt|;
name|QXmlAttributesPrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// SAX Input Source
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlInputSource
block|{
name|public
label|:
name|QXmlInputSource
argument_list|()
expr_stmt|;
name|QXmlInputSource
argument_list|(
name|QIODevice
operator|*
name|dev
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QXmlInputSource
argument_list|()
expr_stmt|;
name|virtual
name|void
name|setData
parameter_list|(
specifier|const
name|QString
modifier|&
name|dat
parameter_list|)
function_decl|;
name|virtual
name|void
name|setData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|dat
parameter_list|)
function_decl|;
name|virtual
name|void
name|fetchData
parameter_list|()
function_decl|;
name|virtual
name|QString
name|data
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QChar
name|next
parameter_list|()
function_decl|;
name|virtual
name|void
name|reset
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|ushort
name|EndOfData
decl_stmt|;
specifier|static
specifier|const
name|ushort
name|EndOfDocument
decl_stmt|;
name|protected
label|:
name|virtual
name|QString
name|fromRawData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
name|bool
name|beginning
init|=
name|false
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|init
parameter_list|()
function_decl|;
name|QXmlInputSourcePrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// SAX Exception Classes
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlParseException
block|{
name|public
label|:
name|explicit
name|QXmlParseException
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
init|=
name|QString
argument_list|()
parameter_list|,
name|int
name|c
init|=
operator|-
literal|1
parameter_list|,
name|int
name|l
init|=
operator|-
literal|1
parameter_list|,
specifier|const
name|QString
modifier|&
name|p
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|s
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|QXmlParseException
argument_list|(
specifier|const
name|QXmlParseException
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QXmlParseException
argument_list|()
expr_stmt|;
name|int
name|columnNumber
argument_list|()
specifier|const
expr_stmt|;
name|int
name|lineNumber
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|publicId
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|systemId
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|message
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QScopedPointer
operator|<
name|QXmlParseExceptionPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// XML Reader
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlReader
block|{
name|public
label|:
name|virtual
operator|~
name|QXmlReader
argument_list|()
block|{}
name|virtual
name|bool
name|feature
argument_list|(
argument|const QString& name
argument_list|,
argument|bool *ok =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setFeature
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|bool
name|value
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|hasFeature
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
modifier|*
name|property
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|setProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|hasProperty
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|setEntityResolver
parameter_list|(
name|QXmlEntityResolver
modifier|*
name|handler
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QXmlEntityResolver
operator|*
name|entityResolver
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setDTDHandler
parameter_list|(
name|QXmlDTDHandler
modifier|*
name|handler
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QXmlDTDHandler
operator|*
name|DTDHandler
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setContentHandler
parameter_list|(
name|QXmlContentHandler
modifier|*
name|handler
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QXmlContentHandler
operator|*
name|contentHandler
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setErrorHandler
parameter_list|(
name|QXmlErrorHandler
modifier|*
name|handler
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QXmlErrorHandler
operator|*
name|errorHandler
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setLexicalHandler
parameter_list|(
name|QXmlLexicalHandler
modifier|*
name|handler
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QXmlLexicalHandler
operator|*
name|lexicalHandler
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setDeclHandler
parameter_list|(
name|QXmlDeclHandler
modifier|*
name|handler
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QXmlDeclHandler
operator|*
name|declHandler
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|parse
parameter_list|(
specifier|const
name|QXmlInputSource
modifier|&
name|input
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|parse
parameter_list|(
specifier|const
name|QXmlInputSource
modifier|*
name|input
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlSimpleReader
range|:
name|public
name|QXmlReader
block|{
name|public
operator|:
name|QXmlSimpleReader
argument_list|()
block|;
name|virtual
operator|~
name|QXmlSimpleReader
argument_list|()
block|;
name|bool
name|feature
argument_list|(
argument|const QString& name
argument_list|,
argument|bool *ok =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|setFeature
argument_list|(
argument|const QString& name
argument_list|,
argument|bool value
argument_list|)
block|;
name|bool
name|hasFeature
argument_list|(
argument|const QString& name
argument_list|)
specifier|const
block|;
name|void
operator|*
name|property
argument_list|(
argument|const QString& name
argument_list|,
argument|bool *ok =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|setProperty
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|void
operator|*
name|value
argument_list|)
block|;
name|bool
name|hasProperty
argument_list|(
argument|const QString& name
argument_list|)
specifier|const
block|;
name|void
name|setEntityResolver
argument_list|(
name|QXmlEntityResolver
operator|*
name|handler
argument_list|)
block|;
name|QXmlEntityResolver
operator|*
name|entityResolver
argument_list|()
specifier|const
block|;
name|void
name|setDTDHandler
argument_list|(
name|QXmlDTDHandler
operator|*
name|handler
argument_list|)
block|;
name|QXmlDTDHandler
operator|*
name|DTDHandler
argument_list|()
specifier|const
block|;
name|void
name|setContentHandler
argument_list|(
name|QXmlContentHandler
operator|*
name|handler
argument_list|)
block|;
name|QXmlContentHandler
operator|*
name|contentHandler
argument_list|()
specifier|const
block|;
name|void
name|setErrorHandler
argument_list|(
name|QXmlErrorHandler
operator|*
name|handler
argument_list|)
block|;
name|QXmlErrorHandler
operator|*
name|errorHandler
argument_list|()
specifier|const
block|;
name|void
name|setLexicalHandler
argument_list|(
name|QXmlLexicalHandler
operator|*
name|handler
argument_list|)
block|;
name|QXmlLexicalHandler
operator|*
name|lexicalHandler
argument_list|()
specifier|const
block|;
name|void
name|setDeclHandler
argument_list|(
name|QXmlDeclHandler
operator|*
name|handler
argument_list|)
block|;
name|QXmlDeclHandler
operator|*
name|declHandler
argument_list|()
specifier|const
block|;
name|bool
name|parse
argument_list|(
specifier|const
name|QXmlInputSource
operator|&
name|input
argument_list|)
block|;
name|bool
name|parse
argument_list|(
specifier|const
name|QXmlInputSource
operator|*
name|input
argument_list|)
block|;
name|virtual
name|bool
name|parse
argument_list|(
argument|const QXmlInputSource* input
argument_list|,
argument|bool incremental
argument_list|)
block|;
name|virtual
name|bool
name|parseContinue
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QXmlSimpleReader
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QXmlSimpleReader
argument_list|)
name|QScopedPointer
operator|<
name|QXmlSimpleReaderPrivate
operator|>
name|d_ptr
block|;
name|friend
name|class
name|QXmlSimpleReaderLocator
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// SAX Locator
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlLocator
block|{
name|public
label|:
name|QXmlLocator
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QXmlLocator
argument_list|()
expr_stmt|;
name|virtual
name|int
name|columnNumber
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|int
name|lineNumber
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//    QString getPublicId() const
comment|//    QString getSystemId() const
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// SAX handler classes
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlContentHandler
block|{
name|public
label|:
name|virtual
operator|~
name|QXmlContentHandler
argument_list|()
block|{}
name|virtual
name|void
name|setDocumentLocator
argument_list|(
name|QXmlLocator
operator|*
name|locator
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|startDocument
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|endDocument
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|startPrefixMapping
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|,
specifier|const
name|QString
modifier|&
name|uri
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|endPrefixMapping
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
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
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|endElement
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
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|characters
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|ignorableWhitespace
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|processingInstruction
parameter_list|(
specifier|const
name|QString
modifier|&
name|target
parameter_list|,
specifier|const
name|QString
modifier|&
name|data
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|skippedEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QString
name|errorString
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlErrorHandler
block|{
name|public
label|:
name|virtual
operator|~
name|QXmlErrorHandler
argument_list|()
block|{}
name|virtual
name|bool
name|warning
argument_list|(
specifier|const
name|QXmlParseException
operator|&
name|exception
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|error
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|fatalError
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QString
name|errorString
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlDTDHandler
block|{
name|public
label|:
name|virtual
operator|~
name|QXmlDTDHandler
argument_list|()
block|{}
name|virtual
name|bool
name|notationDecl
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|publicId
argument_list|,
specifier|const
name|QString
operator|&
name|systemId
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|unparsedEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|,
specifier|const
name|QString
modifier|&
name|notationName
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QString
name|errorString
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlEntityResolver
block|{
name|public
label|:
name|virtual
operator|~
name|QXmlEntityResolver
argument_list|()
block|{}
name|virtual
name|bool
name|resolveEntity
argument_list|(
specifier|const
name|QString
operator|&
name|publicId
argument_list|,
specifier|const
name|QString
operator|&
name|systemId
argument_list|,
name|QXmlInputSource
operator|*
operator|&
name|ret
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|QString
name|errorString
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlLexicalHandler
block|{
name|public
label|:
name|virtual
operator|~
name|QXmlLexicalHandler
argument_list|()
block|{}
name|virtual
name|bool
name|startDTD
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|publicId
argument_list|,
specifier|const
name|QString
operator|&
name|systemId
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|endDTD
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|startEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|endEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|startCDATA
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|endCDATA
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|comment
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QString
name|errorString
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_XML_EXPORT
name|QXmlDeclHandler
block|{
name|public
label|:
name|virtual
operator|~
name|QXmlDeclHandler
argument_list|()
block|{}
name|virtual
name|bool
name|attributeDecl
argument_list|(
specifier|const
name|QString
operator|&
name|eName
argument_list|,
specifier|const
name|QString
operator|&
name|aName
argument_list|,
specifier|const
name|QString
operator|&
name|type
argument_list|,
specifier|const
name|QString
operator|&
name|valueDefault
argument_list|,
specifier|const
name|QString
operator|&
name|value
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|internalEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|externalEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QString
name|errorString
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// ### Qt 5: Conform to SAX by adding elementDecl
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QXmlContentHandler
DECL|variable|QXmlErrorHandler
DECL|variable|QXmlDTDHandler
DECL|variable|QXmlEntityResolver
DECL|variable|QXmlLexicalHandler
name|class
name|Q_XML_EXPORT
name|QXmlDefaultHandler
range|:
name|public
name|QXmlContentHandler
decl_stmt|,
name|public
name|QXmlErrorHandler
decl_stmt|,
name|public
name|QXmlDTDHandler
decl_stmt|,
name|public
name|QXmlEntityResolver
decl_stmt|,
name|public
name|QXmlLexicalHandler
decl_stmt|,
name|public
name|QXmlDeclHandler
block|{
name|public
label|:
name|QXmlDefaultHandler
argument_list|()
block|{ }
name|virtual
operator|~
name|QXmlDefaultHandler
argument_list|()
block|{ }
name|void
name|setDocumentLocator
argument_list|(
name|QXmlLocator
operator|*
name|locator
argument_list|)
expr_stmt|;
name|bool
name|startDocument
parameter_list|()
function_decl|;
name|bool
name|endDocument
parameter_list|()
function_decl|;
name|bool
name|startPrefixMapping
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|,
specifier|const
name|QString
modifier|&
name|uri
parameter_list|)
function_decl|;
name|bool
name|endPrefixMapping
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|)
function_decl|;
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
function_decl|;
name|bool
name|endElement
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
parameter_list|)
function_decl|;
name|bool
name|characters
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
function_decl|;
name|bool
name|ignorableWhitespace
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
function_decl|;
name|bool
name|processingInstruction
parameter_list|(
specifier|const
name|QString
modifier|&
name|target
parameter_list|,
specifier|const
name|QString
modifier|&
name|data
parameter_list|)
function_decl|;
name|bool
name|skippedEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|bool
name|warning
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
function_decl|;
name|bool
name|error
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
function_decl|;
name|bool
name|fatalError
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
function_decl|;
name|bool
name|notationDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|)
function_decl|;
name|bool
name|unparsedEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|,
specifier|const
name|QString
modifier|&
name|notationName
parameter_list|)
function_decl|;
name|bool
name|resolveEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|,
name|QXmlInputSource
modifier|*
modifier|&
name|ret
parameter_list|)
function_decl|;
name|bool
name|startDTD
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|)
function_decl|;
name|bool
name|endDTD
parameter_list|()
function_decl|;
name|bool
name|startEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|bool
name|endEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|bool
name|startCDATA
parameter_list|()
function_decl|;
name|bool
name|endCDATA
parameter_list|()
function_decl|;
name|bool
name|comment
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
function_decl|;
name|bool
name|attributeDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|eName
parameter_list|,
specifier|const
name|QString
modifier|&
name|aName
parameter_list|,
specifier|const
name|QString
modifier|&
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|valueDefault
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
name|bool
name|internalEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
name|bool
name|externalEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|)
function_decl|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QXmlDefaultHandlerPrivate
modifier|*
name|d
decl_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QXmlDefaultHandler
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// inlines
end_comment
begin_expr_stmt
DECL|function|count
specifier|inline
name|int
name|QXmlAttributes
operator|::
name|count
argument_list|()
specifier|const
block|{
return|return
name|length
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QXML_H
end_comment
end_unit
