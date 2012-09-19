begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   qmlcodemarker.cpp */
end_comment
begin_include
include|#
directive|include
file|"qqmljsast_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljsastfwd_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljsengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljslexer_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljsparser_p.h"
end_include
begin_include
include|#
directive|include
file|"atom.h"
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|"qmlcodemarker.h"
end_include
begin_include
include|#
directive|include
file|"qmlmarkupvisitor.h"
end_include
begin_include
include|#
directive|include
file|"text.h"
end_include
begin_include
include|#
directive|include
file|"tree.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QmlCodeMarker
name|QmlCodeMarker
operator|::
name|QmlCodeMarker
parameter_list|()
block|{ }
end_function
begin_destructor
DECL|function|~QmlCodeMarker
name|QmlCodeMarker
operator|::
name|~
name|QmlCodeMarker
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Returns true if the \a code is recognized by the parser.  */
end_comment
begin_function
DECL|function|recognizeCode
name|bool
name|QmlCodeMarker
operator|::
name|recognizeCode
parameter_list|(
specifier|const
name|QString
modifier|&
name|code
parameter_list|)
block|{
name|QQmlJS
operator|::
name|Engine
name|engine
decl_stmt|;
name|QQmlJS
operator|::
name|Lexer
name|lexer
argument_list|(
operator|&
name|engine
argument_list|)
decl_stmt|;
name|QQmlJS
operator|::
name|Parser
name|parser
argument_list|(
operator|&
name|engine
argument_list|)
decl_stmt|;
name|QString
name|newCode
init|=
name|code
decl_stmt|;
name|extractPragmas
argument_list|(
name|newCode
argument_list|)
expr_stmt|;
name|lexer
operator|.
name|setCode
argument_list|(
name|newCode
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
name|parser
operator|.
name|parse
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Returns true if \a ext is any of a list of file extensions   for the QML language.  */
end_comment
begin_function
DECL|function|recognizeExtension
name|bool
name|QmlCodeMarker
operator|::
name|recognizeExtension
parameter_list|(
specifier|const
name|QString
modifier|&
name|ext
parameter_list|)
block|{
return|return
name|ext
operator|==
literal|"qml"
return|;
block|}
end_function
begin_comment
comment|/*!   Returns true if the \a language is recognized. Only "QML" is   recognized by this marker.  */
end_comment
begin_function
DECL|function|recognizeLanguage
name|bool
name|QmlCodeMarker
operator|::
name|recognizeLanguage
parameter_list|(
specifier|const
name|QString
modifier|&
name|language
parameter_list|)
block|{
return|return
name|language
operator|==
literal|"QML"
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the type of atom used to represent QML code in the documentation. */
end_comment
begin_function
DECL|function|atomType
name|Atom
operator|::
name|Type
name|QmlCodeMarker
operator|::
name|atomType
parameter_list|()
specifier|const
block|{
return|return
name|Atom
operator|::
name|Qml
return|;
block|}
end_function
begin_function
DECL|function|markedUpCode
name|QString
name|QmlCodeMarker
operator|::
name|markedUpCode
parameter_list|(
specifier|const
name|QString
modifier|&
name|code
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|,
specifier|const
name|Location
modifier|&
name|location
parameter_list|)
block|{
return|return
name|addMarkUp
argument_list|(
name|code
argument_list|,
name|relative
argument_list|,
name|location
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|markedUpName
name|QString
name|QmlCodeMarker
operator|::
name|markedUpName
parameter_list|(
specifier|const
name|Node
modifier|*
name|node
parameter_list|)
block|{
name|QString
name|name
init|=
name|linkTag
argument_list|(
name|node
argument_list|,
name|taggedNode
argument_list|(
name|node
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|node
operator|->
name|type
argument_list|()
operator|==
name|Node
operator|::
name|QmlMethod
condition|)
name|name
operator|+=
literal|"()"
expr_stmt|;
return|return
name|name
return|;
block|}
end_function
begin_function
DECL|function|markedUpFullName
name|QString
name|QmlCodeMarker
operator|::
name|markedUpFullName
parameter_list|(
specifier|const
name|Node
modifier|*
name|node
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|)
block|{
if|if
condition|(
name|node
operator|->
name|name
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
return|return
literal|"global"
return|;
block|}
else|else
block|{
name|QString
name|fullName
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|fullName
operator|.
name|prepend
argument_list|(
name|markedUpName
argument_list|(
name|node
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|parent
argument_list|()
operator|==
name|relative
operator|||
name|node
operator|->
name|parent
argument_list|()
operator|->
name|name
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
name|fullName
operator|.
name|prepend
argument_list|(
literal|"<@op>::</@op>"
argument_list|)
expr_stmt|;
name|node
operator|=
name|node
operator|->
name|parent
argument_list|()
expr_stmt|;
block|}
return|return
name|fullName
return|;
block|}
block|}
end_function
begin_function
DECL|function|markedUpIncludes
name|QString
name|QmlCodeMarker
operator|::
name|markedUpIncludes
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|includes
parameter_list|)
block|{
name|QString
name|code
decl_stmt|;
name|QStringList
operator|::
name|ConstIterator
name|inc
init|=
name|includes
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|inc
operator|!=
name|includes
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|code
operator|+=
literal|"import "
operator|+
operator|*
name|inc
operator|+
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
operator|++
name|inc
expr_stmt|;
block|}
name|Location
name|location
decl_stmt|;
return|return
name|addMarkUp
argument_list|(
name|code
argument_list|,
literal|0
argument_list|,
name|location
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|functionBeginRegExp
name|QString
name|QmlCodeMarker
operator|::
name|functionBeginRegExp
parameter_list|(
specifier|const
name|QString
modifier|&
name|funcName
parameter_list|)
block|{
return|return
name|QLatin1Char
argument_list|(
literal|'^'
argument_list|)
operator|+
name|QRegExp
operator|::
name|escape
argument_list|(
literal|"function "
operator|+
name|funcName
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'$'
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|functionEndRegExp
name|QString
name|QmlCodeMarker
operator|::
name|functionEndRegExp
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* funcName */
parameter_list|)
block|{
return|return
literal|"^\\}$"
return|;
block|}
end_function
begin_function
DECL|function|addMarkUp
name|QString
name|QmlCodeMarker
operator|::
name|addMarkUp
parameter_list|(
specifier|const
name|QString
modifier|&
name|code
parameter_list|,
specifier|const
name|Node
modifier|*
comment|/* relative */
parameter_list|,
specifier|const
name|Location
modifier|&
name|location
parameter_list|)
block|{
name|QQmlJS
operator|::
name|Engine
name|engine
decl_stmt|;
name|QQmlJS
operator|::
name|Lexer
name|lexer
argument_list|(
operator|&
name|engine
argument_list|)
decl_stmt|;
name|QString
name|newCode
init|=
name|code
decl_stmt|;
name|QList
argument_list|<
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
argument_list|>
name|pragmas
init|=
name|extractPragmas
argument_list|(
name|newCode
argument_list|)
decl_stmt|;
name|lexer
operator|.
name|setCode
argument_list|(
name|newCode
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QQmlJS
operator|::
name|Parser
name|parser
argument_list|(
operator|&
name|engine
argument_list|)
decl_stmt|;
name|QString
name|output
decl_stmt|;
if|if
condition|(
name|parser
operator|.
name|parse
argument_list|()
condition|)
block|{
name|QQmlJS
operator|::
name|AST
operator|::
name|UiProgram
modifier|*
name|ast
init|=
name|parser
operator|.
name|ast
argument_list|()
decl_stmt|;
comment|// Pass the unmodified code to the visitor so that pragmas and other
comment|// unhandled source text can be output.
name|QmlMarkupVisitor
name|visitor
argument_list|(
name|code
argument_list|,
name|pragmas
argument_list|,
operator|&
name|engine
argument_list|)
decl_stmt|;
name|QQmlJS
operator|::
name|AST
operator|::
name|Node
operator|::
name|accept
argument_list|(
name|ast
argument_list|,
operator|&
name|visitor
argument_list|)
expr_stmt|;
name|output
operator|=
name|visitor
operator|.
name|markedUpCode
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|location
operator|.
name|warning
argument_list|(
name|tr
argument_list|(
literal|"Unable to parse QML snippet: \"%1\" at line %2, column %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|parser
operator|.
name|errorMessage
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|parser
operator|.
name|errorLineNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|parser
operator|.
name|errorColumnNumber
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|output
operator|=
name|protect
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
return|return
name|output
return|;
block|}
end_function
begin_comment
comment|/*   Copied and pasted from   src/declarative/qml/qqmlscriptparser.cpp. */
end_comment
begin_function
DECL|function|replaceWithSpace
specifier|static
name|void
name|replaceWithSpace
parameter_list|(
name|QString
modifier|&
name|str
parameter_list|,
name|int
name|idx
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|QChar
modifier|*
name|data
init|=
name|str
operator|.
name|data
argument_list|()
operator|+
name|idx
decl_stmt|;
specifier|const
name|QChar
name|space
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|ii
init|=
literal|0
init|;
name|ii
operator|<
name|n
condition|;
operator|++
name|ii
control|)
operator|*
name|data
operator|++
operator|=
name|space
expr_stmt|;
block|}
end_function
begin_comment
comment|/*   Copied and pasted from   src/declarative/qml/qqmlscriptparser.cpp then modified to   return a list of removed pragmas.    Searches for ".pragma<value>" declarations within \a script.   Currently supported pragmas are: library */
end_comment
begin_function
DECL|function|extractPragmas
name|QList
argument_list|<
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
argument_list|>
name|QmlCodeMarker
operator|::
name|extractPragmas
parameter_list|(
name|QString
modifier|&
name|script
parameter_list|)
block|{
specifier|const
name|QString
name|pragma
argument_list|(
name|QLatin1String
argument_list|(
literal|"pragma"
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|library
argument_list|(
name|QLatin1String
argument_list|(
literal|"library"
argument_list|)
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
argument_list|>
name|removed
decl_stmt|;
name|QQmlJS
operator|::
name|Lexer
name|l
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|l
operator|.
name|setCode
argument_list|(
name|script
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|int
name|token
init|=
name|l
operator|.
name|lex
argument_list|()
decl_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
if|if
condition|(
name|token
operator|!=
name|QQmlJSGrammar
operator|::
name|T_DOT
condition|)
return|return
name|removed
return|;
name|int
name|startOffset
init|=
name|l
operator|.
name|tokenOffset
argument_list|()
decl_stmt|;
name|int
name|startLine
init|=
name|l
operator|.
name|tokenStartLine
argument_list|()
decl_stmt|;
name|int
name|startColumn
init|=
name|l
operator|.
name|tokenStartColumn
argument_list|()
decl_stmt|;
name|token
operator|=
name|l
operator|.
name|lex
argument_list|()
expr_stmt|;
if|if
condition|(
name|token
operator|!=
name|QQmlJSGrammar
operator|::
name|T_IDENTIFIER
operator|||
name|l
operator|.
name|tokenStartLine
argument_list|()
operator|!=
name|startLine
operator|||
name|script
operator|.
name|mid
argument_list|(
name|l
operator|.
name|tokenOffset
argument_list|()
argument_list|,
name|l
operator|.
name|tokenLength
argument_list|()
argument_list|)
operator|!=
name|pragma
condition|)
return|return
name|removed
return|;
name|token
operator|=
name|l
operator|.
name|lex
argument_list|()
expr_stmt|;
if|if
condition|(
name|token
operator|!=
name|QQmlJSGrammar
operator|::
name|T_IDENTIFIER
operator|||
name|l
operator|.
name|tokenStartLine
argument_list|()
operator|!=
name|startLine
condition|)
return|return
name|removed
return|;
name|QString
name|pragmaValue
init|=
name|script
operator|.
name|mid
argument_list|(
name|l
operator|.
name|tokenOffset
argument_list|()
argument_list|,
name|l
operator|.
name|tokenLength
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|endOffset
init|=
name|l
operator|.
name|tokenLength
argument_list|()
operator|+
name|l
operator|.
name|tokenOffset
argument_list|()
decl_stmt|;
name|token
operator|=
name|l
operator|.
name|lex
argument_list|()
expr_stmt|;
if|if
condition|(
name|l
operator|.
name|tokenStartLine
argument_list|()
operator|==
name|startLine
condition|)
return|return
name|removed
return|;
if|if
condition|(
name|pragmaValue
operator|==
name|QLatin1String
argument_list|(
literal|"library"
argument_list|)
condition|)
block|{
name|replaceWithSpace
argument_list|(
name|script
argument_list|,
name|startOffset
argument_list|,
name|endOffset
operator|-
name|startOffset
argument_list|)
expr_stmt|;
name|removed
operator|.
name|append
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
argument_list|(
name|startOffset
argument_list|,
name|endOffset
operator|-
name|startOffset
argument_list|,
name|startLine
argument_list|,
name|startColumn
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
return|return
name|removed
return|;
block|}
return|return
name|removed
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
