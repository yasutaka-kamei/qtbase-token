begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXMLSTREAM_H
end_ifndef
begin_define
DECL|macro|QXMLSTREAM_H
define|#
directive|define
name|QXMLSTREAM_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XMLSTREAM
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|Q_CORE_EXPORT
name|QXmlStreamStringRef
decl_stmt|{     QString m_string;
end_function
begin_decl_stmt
name|int
name|m_position
decl_stmt|,
name|m_size
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_expr_stmt
specifier|inline
name|QXmlStreamStringRef
argument_list|()
operator|:
name|m_position
argument_list|(
literal|0
argument_list|)
operator|,
name|m_size
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|QXmlStreamStringRef
argument_list|(
specifier|const
name|QStringRef
operator|&
name|aString
argument_list|)
operator|:
name|m_string
argument_list|(
name|aString
operator|.
name|string
argument_list|()
operator|?
operator|*
name|aString
operator|.
name|string
argument_list|()
operator|:
name|QString
argument_list|()
argument_list|)
operator|,
name|m_position
argument_list|(
name|aString
operator|.
name|position
argument_list|()
argument_list|)
operator|,
name|m_size
argument_list|(
argument|aString.size()
argument_list|)
block|{}
specifier|inline
name|QXmlStreamStringRef
argument_list|(
specifier|const
name|QString
operator|&
name|aString
argument_list|)
operator|:
name|m_string
argument_list|(
name|aString
argument_list|)
operator|,
name|m_position
argument_list|(
literal|0
argument_list|)
operator|,
name|m_size
argument_list|(
argument|aString.size()
argument_list|)
block|{}
specifier|inline
operator|~
name|QXmlStreamStringRef
argument_list|()
block|{}
specifier|inline
name|void
name|clear
argument_list|()
block|{
name|m_string
operator|.
name|clear
argument_list|()
block|;
name|m_position
operator|=
name|m_size
operator|=
literal|0
block|; }
specifier|inline
name|operator
name|QStringRef
argument_list|()
specifier|const
block|{
return|return
name|QStringRef
argument_list|(
operator|&
name|m_string
argument_list|,
name|m_position
argument_list|,
name|m_size
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QString
operator|*
name|string
argument_list|()
specifier|const
block|{
return|return
operator|&
name|m_string
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|position
argument_list|()
specifier|const
block|{
return|return
name|m_position
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|m_size
return|;
block|}
end_expr_stmt
begin_decl_stmt
unit|};
DECL|variable|QXmlStreamReaderPrivate
name|class
name|QXmlStreamReaderPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXmlStreamAttributes
name|class
name|QXmlStreamAttributes
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QXmlStreamAttribute
block|{
name|QXmlStreamStringRef
name|m_name
decl_stmt|,
name|m_namespaceUri
decl_stmt|,
name|m_qualifiedName
decl_stmt|,
name|m_value
decl_stmt|;
name|void
modifier|*
name|reserved
decl_stmt|;
name|uint
name|m_isDefault
range|:
literal|1
decl_stmt|;
name|friend
name|class
name|QXmlStreamReaderPrivate
decl_stmt|;
name|friend
name|class
name|QXmlStreamAttributes
decl_stmt|;
name|public
label|:
name|QXmlStreamAttribute
argument_list|()
expr_stmt|;
name|QXmlStreamAttribute
argument_list|(
specifier|const
name|QString
operator|&
name|qualifiedName
argument_list|,
specifier|const
name|QString
operator|&
name|value
argument_list|)
expr_stmt|;
name|QXmlStreamAttribute
argument_list|(
specifier|const
name|QString
operator|&
name|namespaceUri
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|value
argument_list|)
expr_stmt|;
name|QXmlStreamAttribute
argument_list|(
specifier|const
name|QXmlStreamAttribute
operator|&
argument_list|)
expr_stmt|;
name|QXmlStreamAttribute
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QXmlStreamAttribute
operator|&
operator|)
decl_stmt|;
operator|~
name|QXmlStreamAttribute
argument_list|()
expr_stmt|;
specifier|inline
name|QStringRef
name|namespaceUri
argument_list|()
specifier|const
block|{
return|return
name|m_namespaceUri
return|;
block|}
specifier|inline
name|QStringRef
name|name
argument_list|()
specifier|const
block|{
return|return
name|m_name
return|;
block|}
specifier|inline
name|QStringRef
name|qualifiedName
argument_list|()
specifier|const
block|{
return|return
name|m_qualifiedName
return|;
block|}
specifier|inline
name|QStringRef
name|prefix
argument_list|()
specifier|const
block|{
return|return
name|QStringRef
argument_list|(
name|m_qualifiedName
operator|.
name|string
argument_list|()
argument_list|,
name|m_qualifiedName
operator|.
name|position
argument_list|()
argument_list|,
name|qMax
argument_list|(
literal|0
argument_list|,
name|m_qualifiedName
operator|.
name|size
argument_list|()
operator|-
name|m_name
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|QStringRef
name|value
argument_list|()
specifier|const
block|{
return|return
name|m_value
return|;
block|}
specifier|inline
name|bool
name|isDefault
argument_list|()
specifier|const
block|{
return|return
name|m_isDefault
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QXmlStreamAttribute
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|value
argument_list|()
operator|==
name|other
operator|.
name|value
argument_list|()
operator|&&
operator|(
name|namespaceUri
argument_list|()
operator|.
name|isNull
argument_list|()
operator|?
operator|(
name|qualifiedName
argument_list|()
operator|==
name|other
operator|.
name|qualifiedName
argument_list|()
operator|)
operator|:
operator|(
name|namespaceUri
argument_list|()
operator|==
name|other
operator|.
name|namespaceUri
argument_list|()
operator|&&
name|name
argument_list|()
operator|==
name|other
operator|.
name|name
argument_list|()
operator|)
operator|)
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QXmlStreamAttribute
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QXmlStreamAttribute
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QXmlStreamAttributes
range|:
name|public
name|QVector
operator|<
name|QXmlStreamAttribute
operator|>
block|{
name|public
operator|:
specifier|inline
name|QXmlStreamAttributes
argument_list|()
block|{}
name|QStringRef
name|value
argument_list|(
argument|const QString&namespaceUri
argument_list|,
argument|const QString&name
argument_list|)
specifier|const
block|;
name|QStringRef
name|value
argument_list|(
argument|const QString&namespaceUri
argument_list|,
argument|const QLatin1String&name
argument_list|)
specifier|const
block|;
name|QStringRef
name|value
argument_list|(
argument|const QLatin1String&namespaceUri
argument_list|,
argument|const QLatin1String&name
argument_list|)
specifier|const
block|;
name|QStringRef
name|value
argument_list|(
argument|const QString&qualifiedName
argument_list|)
specifier|const
block|;
name|QStringRef
name|value
argument_list|(
argument|const QLatin1String&qualifiedName
argument_list|)
specifier|const
block|;
name|void
name|append
argument_list|(
specifier|const
name|QString
operator|&
name|namespaceUri
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|value
argument_list|)
block|;
name|void
name|append
argument_list|(
specifier|const
name|QString
operator|&
name|qualifiedName
argument_list|,
specifier|const
name|QString
operator|&
name|value
argument_list|)
block|;
specifier|inline
name|bool
name|hasAttribute
argument_list|(
argument|const QString&qualifiedName
argument_list|)
specifier|const
block|{
return|return
operator|!
name|value
argument_list|(
name|qualifiedName
argument_list|)
operator|.
name|isNull
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|hasAttribute
argument_list|(
argument|const QLatin1String&qualifiedName
argument_list|)
specifier|const
block|{
return|return
operator|!
name|value
argument_list|(
name|qualifiedName
argument_list|)
operator|.
name|isNull
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|hasAttribute
argument_list|(
argument|const QString&namespaceUri
argument_list|,
argument|const QString&name
argument_list|)
specifier|const
block|{
return|return
operator|!
name|value
argument_list|(
name|namespaceUri
argument_list|,
name|name
argument_list|)
operator|.
name|isNull
argument_list|()
return|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_NO_USING_KEYWORD
argument_list|)
name|using
name|QVector
operator|<
name|QXmlStreamAttribute
operator|>
operator|::
name|append
block|;
else|#
directive|else
specifier|inline
name|void
name|append
argument_list|(
argument|const QXmlStreamAttribute&attribute
argument_list|)
block|{
name|QVector
operator|<
name|QXmlStreamAttribute
operator|>
operator|::
name|append
argument_list|(
name|attribute
argument_list|)
block|; }
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QXmlStreamNamespaceDeclaration
block|{
name|QXmlStreamStringRef
name|m_prefix
decl_stmt|,
name|m_namespaceUri
decl_stmt|;
name|void
modifier|*
name|reserved
decl_stmt|;
name|friend
name|class
name|QXmlStreamReaderPrivate
decl_stmt|;
name|public
label|:
name|QXmlStreamNamespaceDeclaration
argument_list|()
expr_stmt|;
name|QXmlStreamNamespaceDeclaration
argument_list|(
specifier|const
name|QXmlStreamNamespaceDeclaration
operator|&
argument_list|)
expr_stmt|;
name|QXmlStreamNamespaceDeclaration
argument_list|(
specifier|const
name|QString
operator|&
name|prefix
argument_list|,
specifier|const
name|QString
operator|&
name|namespaceUri
argument_list|)
expr_stmt|;
operator|~
name|QXmlStreamNamespaceDeclaration
argument_list|()
expr_stmt|;
name|QXmlStreamNamespaceDeclaration
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QXmlStreamNamespaceDeclaration
operator|&
operator|)
decl_stmt|;
specifier|inline
name|QStringRef
name|prefix
argument_list|()
specifier|const
block|{
return|return
name|m_prefix
return|;
block|}
specifier|inline
name|QStringRef
name|namespaceUri
argument_list|()
specifier|const
block|{
return|return
name|m_namespaceUri
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QXmlStreamNamespaceDeclaration
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|prefix
argument_list|()
operator|==
name|other
operator|.
name|prefix
argument_list|()
operator|&&
name|namespaceUri
argument_list|()
operator|==
name|other
operator|.
name|namespaceUri
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QXmlStreamNamespaceDeclaration
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QXmlStreamNamespaceDeclaration
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QXmlStreamNamespaceDeclarations
typedef|typedef
name|QVector
operator|<
name|QXmlStreamNamespaceDeclaration
operator|>
name|QXmlStreamNamespaceDeclarations
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QXmlStreamNotationDeclaration
block|{
name|QXmlStreamStringRef
name|m_name
decl_stmt|,
name|m_systemId
decl_stmt|,
name|m_publicId
decl_stmt|;
name|void
modifier|*
name|reserved
decl_stmt|;
name|friend
name|class
name|QXmlStreamReaderPrivate
decl_stmt|;
name|public
label|:
name|QXmlStreamNotationDeclaration
argument_list|()
expr_stmt|;
operator|~
name|QXmlStreamNotationDeclaration
argument_list|()
expr_stmt|;
name|QXmlStreamNotationDeclaration
argument_list|(
specifier|const
name|QXmlStreamNotationDeclaration
operator|&
argument_list|)
expr_stmt|;
name|QXmlStreamNotationDeclaration
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QXmlStreamNotationDeclaration
operator|&
operator|)
decl_stmt|;
specifier|inline
name|QStringRef
name|name
argument_list|()
specifier|const
block|{
return|return
name|m_name
return|;
block|}
specifier|inline
name|QStringRef
name|systemId
argument_list|()
specifier|const
block|{
return|return
name|m_systemId
return|;
block|}
specifier|inline
name|QStringRef
name|publicId
argument_list|()
specifier|const
block|{
return|return
name|m_publicId
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QXmlStreamNotationDeclaration
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|name
argument_list|()
operator|==
name|other
operator|.
name|name
argument_list|()
operator|&&
name|systemId
argument_list|()
operator|==
name|other
operator|.
name|systemId
argument_list|()
operator|&&
name|publicId
argument_list|()
operator|==
name|other
operator|.
name|publicId
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QXmlStreamNotationDeclaration
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QXmlStreamNotationDeclaration
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QXmlStreamNotationDeclarations
typedef|typedef
name|QVector
operator|<
name|QXmlStreamNotationDeclaration
operator|>
name|QXmlStreamNotationDeclarations
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QXmlStreamEntityDeclaration
block|{
name|QXmlStreamStringRef
name|m_name
decl_stmt|,
name|m_notationName
decl_stmt|,
name|m_systemId
decl_stmt|,
name|m_publicId
decl_stmt|,
name|m_value
decl_stmt|;
name|void
modifier|*
name|reserved
decl_stmt|;
name|friend
name|class
name|QXmlStreamReaderPrivate
decl_stmt|;
name|public
label|:
name|QXmlStreamEntityDeclaration
argument_list|()
expr_stmt|;
operator|~
name|QXmlStreamEntityDeclaration
argument_list|()
expr_stmt|;
name|QXmlStreamEntityDeclaration
argument_list|(
specifier|const
name|QXmlStreamEntityDeclaration
operator|&
argument_list|)
expr_stmt|;
name|QXmlStreamEntityDeclaration
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QXmlStreamEntityDeclaration
operator|&
operator|)
decl_stmt|;
specifier|inline
name|QStringRef
name|name
argument_list|()
specifier|const
block|{
return|return
name|m_name
return|;
block|}
specifier|inline
name|QStringRef
name|notationName
argument_list|()
specifier|const
block|{
return|return
name|m_notationName
return|;
block|}
specifier|inline
name|QStringRef
name|systemId
argument_list|()
specifier|const
block|{
return|return
name|m_systemId
return|;
block|}
specifier|inline
name|QStringRef
name|publicId
argument_list|()
specifier|const
block|{
return|return
name|m_publicId
return|;
block|}
specifier|inline
name|QStringRef
name|value
argument_list|()
specifier|const
block|{
return|return
name|m_value
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QXmlStreamEntityDeclaration
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|name
argument_list|()
operator|==
name|other
operator|.
name|name
argument_list|()
operator|&&
name|notationName
argument_list|()
operator|==
name|other
operator|.
name|notationName
argument_list|()
operator|&&
name|systemId
argument_list|()
operator|==
name|other
operator|.
name|systemId
argument_list|()
operator|&&
name|publicId
argument_list|()
operator|==
name|other
operator|.
name|publicId
argument_list|()
operator|&&
name|value
argument_list|()
operator|==
name|other
operator|.
name|value
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QXmlStreamEntityDeclaration
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QXmlStreamEntityDeclaration
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QXmlStreamEntityDeclarations
typedef|typedef
name|QVector
operator|<
name|QXmlStreamEntityDeclaration
operator|>
name|QXmlStreamEntityDeclarations
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QXmlStreamEntityResolver
block|{
name|public
label|:
name|virtual
operator|~
name|QXmlStreamEntityResolver
argument_list|()
expr_stmt|;
name|virtual
name|QString
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
parameter_list|)
function_decl|;
name|virtual
name|QString
name|resolveUndeclaredEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XMLSTREAMREADER
end_ifndef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QXmlStreamReader
block|{
name|QDOC_PROPERTY
argument_list|(
argument|bool namespaceProcessing READ namespaceProcessing WRITE setNamespaceProcessing
argument_list|)
name|public
label|:
enum|enum
name|TokenType
block|{
name|NoToken
init|=
literal|0
block|,
name|Invalid
block|,
name|StartDocument
block|,
name|EndDocument
block|,
name|StartElement
block|,
name|EndElement
block|,
name|Characters
block|,
name|Comment
block|,
name|DTD
block|,
name|EntityReference
block|,
name|ProcessingInstruction
block|}
enum|;
name|QXmlStreamReader
argument_list|()
expr_stmt|;
name|QXmlStreamReader
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
expr_stmt|;
name|QXmlStreamReader
argument_list|(
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
expr_stmt|;
name|QXmlStreamReader
argument_list|(
specifier|const
name|QString
operator|&
name|data
argument_list|)
expr_stmt|;
name|QXmlStreamReader
argument_list|(
specifier|const
name|char
operator|*
name|data
argument_list|)
expr_stmt|;
operator|~
name|QXmlStreamReader
argument_list|()
expr_stmt|;
name|void
name|setDevice
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
name|QIODevice
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
name|void
name|addData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
function_decl|;
name|void
name|addData
parameter_list|(
specifier|const
name|QString
modifier|&
name|data
parameter_list|)
function_decl|;
name|void
name|addData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
name|bool
name|atEnd
argument_list|()
specifier|const
expr_stmt|;
name|TokenType
name|readNext
parameter_list|()
function_decl|;
name|bool
name|readNextStartElement
parameter_list|()
function_decl|;
name|void
name|skipCurrentElement
parameter_list|()
function_decl|;
name|TokenType
name|tokenType
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|tokenString
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setNamespaceProcessing
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|namespaceProcessing
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isStartDocument
argument_list|()
specifier|const
block|{
return|return
name|tokenType
argument_list|()
operator|==
name|StartDocument
return|;
block|}
specifier|inline
name|bool
name|isEndDocument
argument_list|()
specifier|const
block|{
return|return
name|tokenType
argument_list|()
operator|==
name|EndDocument
return|;
block|}
specifier|inline
name|bool
name|isStartElement
argument_list|()
specifier|const
block|{
return|return
name|tokenType
argument_list|()
operator|==
name|StartElement
return|;
block|}
specifier|inline
name|bool
name|isEndElement
argument_list|()
specifier|const
block|{
return|return
name|tokenType
argument_list|()
operator|==
name|EndElement
return|;
block|}
specifier|inline
name|bool
name|isCharacters
argument_list|()
specifier|const
block|{
return|return
name|tokenType
argument_list|()
operator|==
name|Characters
return|;
block|}
name|bool
name|isWhitespace
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isCDATA
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isComment
argument_list|()
specifier|const
block|{
return|return
name|tokenType
argument_list|()
operator|==
name|Comment
return|;
block|}
specifier|inline
name|bool
name|isDTD
argument_list|()
specifier|const
block|{
return|return
name|tokenType
argument_list|()
operator|==
name|DTD
return|;
block|}
specifier|inline
name|bool
name|isEntityReference
argument_list|()
specifier|const
block|{
return|return
name|tokenType
argument_list|()
operator|==
name|EntityReference
return|;
block|}
specifier|inline
name|bool
name|isProcessingInstruction
argument_list|()
specifier|const
block|{
return|return
name|tokenType
argument_list|()
operator|==
name|ProcessingInstruction
return|;
block|}
name|bool
name|isStandaloneDocument
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|documentVersion
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|documentEncoding
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|lineNumber
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|columnNumber
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|characterOffset
argument_list|()
specifier|const
expr_stmt|;
name|QXmlStreamAttributes
name|attributes
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|ReadElementTextBehaviour
block|{
name|ErrorOnUnexpectedElement
block|,
name|IncludeChildElements
block|,
name|SkipChildElements
block|}
enum|;
name|QString
name|readElementText
parameter_list|(
name|ReadElementTextBehaviour
name|behaviour
parameter_list|)
function_decl|;
name|QString
name|readElementText
parameter_list|()
function_decl|;
name|QStringRef
name|name
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|namespaceUri
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|qualifiedName
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|prefix
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|processingInstructionTarget
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|processingInstructionData
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|text
argument_list|()
specifier|const
expr_stmt|;
name|QXmlStreamNamespaceDeclarations
name|namespaceDeclarations
argument_list|()
specifier|const
expr_stmt|;
name|void
name|addExtraNamespaceDeclaration
parameter_list|(
specifier|const
name|QXmlStreamNamespaceDeclaration
modifier|&
name|extraNamespaceDeclaraction
parameter_list|)
function_decl|;
name|void
name|addExtraNamespaceDeclarations
parameter_list|(
specifier|const
name|QXmlStreamNamespaceDeclarations
modifier|&
name|extraNamespaceDeclaractions
parameter_list|)
function_decl|;
name|QXmlStreamNotationDeclarations
name|notationDeclarations
argument_list|()
specifier|const
expr_stmt|;
name|QXmlStreamEntityDeclarations
name|entityDeclarations
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|dtdName
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|dtdPublicId
argument_list|()
specifier|const
expr_stmt|;
name|QStringRef
name|dtdSystemId
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|Error
block|{
name|NoError
block|,
name|UnexpectedElementError
block|,
name|CustomError
block|,
name|NotWellFormedError
block|,
name|PrematureEndOfDocumentError
block|}
enum|;
name|void
name|raiseError
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
name|Error
name|error
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|hasError
argument_list|()
specifier|const
block|{
return|return
name|error
argument_list|()
operator|!=
name|NoError
return|;
block|}
name|void
name|setEntityResolver
parameter_list|(
name|QXmlStreamEntityResolver
modifier|*
name|resolver
parameter_list|)
function_decl|;
name|QXmlStreamEntityResolver
operator|*
name|entityResolver
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QXmlStreamReader
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QXmlStreamReader
argument_list|)
name|QScopedPointer
operator|<
name|QXmlStreamReaderPrivate
operator|>
name|d_ptr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XMLSTREAMREADER
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XMLSTREAMWRITER
end_ifndef
begin_decl_stmt
DECL|variable|QXmlStreamWriterPrivate
name|class
name|QXmlStreamWriterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QXmlStreamWriter
block|{
name|QDOC_PROPERTY
argument_list|(
argument|bool autoFormatting READ autoFormatting WRITE setAutoFormatting
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int autoFormattingIndent READ autoFormattingIndent WRITE setAutoFormattingIndent
argument_list|)
name|public
label|:
name|QXmlStreamWriter
argument_list|()
expr_stmt|;
name|QXmlStreamWriter
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
expr_stmt|;
name|QXmlStreamWriter
argument_list|(
name|QByteArray
operator|*
name|array
argument_list|)
expr_stmt|;
name|QXmlStreamWriter
argument_list|(
name|QString
operator|*
name|string
argument_list|)
expr_stmt|;
operator|~
name|QXmlStreamWriter
argument_list|()
expr_stmt|;
name|void
name|setDevice
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
name|QIODevice
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|void
name|setCodec
parameter_list|(
name|QTextCodec
modifier|*
name|codec
parameter_list|)
function_decl|;
name|void
name|setCodec
parameter_list|(
specifier|const
name|char
modifier|*
name|codecName
parameter_list|)
function_decl|;
name|QTextCodec
operator|*
name|codec
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|void
name|setAutoFormatting
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|bool
name|autoFormatting
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAutoFormattingIndent
parameter_list|(
name|int
name|spacesOrTabs
parameter_list|)
function_decl|;
name|int
name|autoFormattingIndent
argument_list|()
specifier|const
expr_stmt|;
name|void
name|writeAttribute
parameter_list|(
specifier|const
name|QString
modifier|&
name|qualifiedName
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
name|void
name|writeAttribute
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceUri
parameter_list|,
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
name|void
name|writeAttribute
parameter_list|(
specifier|const
name|QXmlStreamAttribute
modifier|&
name|attribute
parameter_list|)
function_decl|;
name|void
name|writeAttributes
parameter_list|(
specifier|const
name|QXmlStreamAttributes
modifier|&
name|attributes
parameter_list|)
function_decl|;
name|void
name|writeCDATA
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|void
name|writeCharacters
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|void
name|writeComment
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|void
name|writeDTD
parameter_list|(
specifier|const
name|QString
modifier|&
name|dtd
parameter_list|)
function_decl|;
name|void
name|writeEmptyElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|qualifiedName
parameter_list|)
function_decl|;
name|void
name|writeEmptyElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceUri
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|void
name|writeTextElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|qualifiedName
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|void
name|writeTextElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceUri
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|void
name|writeEndDocument
parameter_list|()
function_decl|;
name|void
name|writeEndElement
parameter_list|()
function_decl|;
name|void
name|writeEntityReference
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|void
name|writeNamespace
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceUri
parameter_list|,
specifier|const
name|QString
modifier|&
name|prefix
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|void
name|writeDefaultNamespace
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceUri
parameter_list|)
function_decl|;
name|void
name|writeProcessingInstruction
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
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|void
name|writeStartDocument
parameter_list|()
function_decl|;
name|void
name|writeStartDocument
parameter_list|(
specifier|const
name|QString
modifier|&
name|version
parameter_list|)
function_decl|;
name|void
name|writeStartDocument
parameter_list|(
specifier|const
name|QString
modifier|&
name|version
parameter_list|,
name|bool
name|standalone
parameter_list|)
function_decl|;
name|void
name|writeStartElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|qualifiedName
parameter_list|)
function_decl|;
name|void
name|writeStartElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceUri
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_XMLSTREAMREADER
name|void
name|writeCurrentToken
parameter_list|(
specifier|const
name|QXmlStreamReader
modifier|&
name|reader
parameter_list|)
function_decl|;
endif|#
directive|endif
name|bool
name|hasError
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QXmlStreamWriter
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QXmlStreamWriter
argument_list|)
name|QScopedPointer
operator|<
name|QXmlStreamWriterPrivate
operator|>
name|d_ptr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XMLSTREAMWRITER
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_XMLSTREAM
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QXMLSTREAM_H
end_comment
end_unit
