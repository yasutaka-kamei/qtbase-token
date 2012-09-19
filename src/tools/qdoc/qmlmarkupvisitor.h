begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMLMARKUPVISITOR_H
end_ifndef
begin_define
DECL|macro|QMLMARKUPVISITOR_H
define|#
directive|define
name|QMLMARKUPVISITOR_H
end_define
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|"qqmljsastvisitor_p.h"
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|"tree.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QmlMarkupVisitor
range|:
name|public
name|QQmlJS
operator|::
name|AST
operator|::
name|Visitor
block|{
name|public
operator|:
expr|enum
name|ExtraType
block|{
name|Comment
block|,
name|Pragma
block|}
block|;
name|QmlMarkupVisitor
argument_list|(
specifier|const
name|QString
operator|&
name|code
argument_list|,
specifier|const
name|QList
operator|<
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
operator|>
operator|&
name|pragmas
argument_list|,
name|QQmlJS
operator|::
name|Engine
operator|*
name|engine
argument_list|)
block|;
name|virtual
operator|~
name|QmlMarkupVisitor
argument_list|()
block|;
name|QString
name|markedUpCode
argument_list|()
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiImport
operator|*
argument_list|)
block|;
name|virtual
name|void
name|endVisit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiImport
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiPublicMember
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiObjectDefinition
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiObjectInitializer
operator|*
argument_list|)
block|;
name|virtual
name|void
name|endVisit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiObjectInitializer
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiObjectBinding
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiScriptBinding
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiArrayBinding
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiArrayMemberList
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UiQualifiedId
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ThisExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|IdentifierExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|NullExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|TrueLiteral
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|FalseLiteral
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|NumericLiteral
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|StringLiteral
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|RegExpLiteral
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ArrayLiteral
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ObjectLiteral
operator|*
argument_list|)
block|;
name|virtual
name|void
name|endVisit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ObjectLiteral
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ElementList
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|Elision
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|PropertyNameAndValueList
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ArrayMemberExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|FieldMemberExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|NewMemberExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|NewExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ArgumentList
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|PostIncrementExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|PostDecrementExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|DeleteExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|VoidExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|TypeOfExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|PreIncrementExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|PreDecrementExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UnaryPlusExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|UnaryMinusExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|TildeExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|NotExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|BinaryExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ConditionalExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|Expression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|Block
operator|*
argument_list|)
block|;
name|virtual
name|void
name|endVisit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|Block
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|VariableStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|VariableDeclarationList
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|VariableDeclaration
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|EmptyStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ExpressionStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|IfStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|DoWhileStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|WhileStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ForStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|LocalForStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ForEachStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|LocalForEachStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ContinueStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|BreakStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ReturnStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|WithStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|CaseBlock
operator|*
argument_list|)
block|;
name|virtual
name|void
name|endVisit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|CaseBlock
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|SwitchStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|CaseClause
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|DefaultClause
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|LabelledStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|ThrowStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|TryStatement
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|Catch
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|Finally
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|FunctionDeclaration
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|FunctionExpression
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|FormalParameterList
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|visit
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|DebuggerStatement
operator|*
argument_list|)
block|;
name|protected
operator|:
name|QString
name|protect
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
block|;
name|private
operator|:
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|QString
operator|>
name|StringHash
expr_stmt|;
name|void
name|addExtra
argument_list|(
argument|quint32 start
argument_list|,
argument|quint32 finish
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|addMarkedUpToken
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
operator|&
name|location
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
name|StringHash
operator|&
name|attributes
operator|=
name|StringHash
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|addVerbatim
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
name|first
argument_list|,
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
name|last
operator|=
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|sourceText
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
operator|&
name|location
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QQmlJS
operator|::
name|Engine
operator|*
name|engine
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|ExtraType
operator|>
name|extraTypes
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
operator|>
name|extraLocations
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|source
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|output
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|quint32
name|cursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|extraIndex
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
