begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtQml module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQMLJSENGINE_P_H
end_ifndef
begin_define
DECL|macro|QQMLJSENGINE_P_H
define|#
directive|define
name|QQMLJSENGINE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qqmljsglobal_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljsastfwd_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljsmemorypool_p.h"
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_decl_stmt
name|QT_QML_BEGIN_NAMESPACE
name|namespace
name|QQmlJS
block|{
name|class
name|Lexer
decl_stmt|;
name|class
name|MemoryPool
decl_stmt|;
name|class
name|QML_PARSER_EXPORT
name|DiagnosticMessage
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|Warning
block|,
name|Error
block|}
enum|;
name|DiagnosticMessage
argument_list|()
operator|:
name|kind
argument_list|(
argument|Error
argument_list|)
block|{}
name|DiagnosticMessage
argument_list|(
argument|Kind kind
argument_list|,
argument|const AST::SourceLocation&loc
argument_list|,
argument|const QString&message
argument_list|)
operator|:
name|kind
argument_list|(
name|kind
argument_list|)
operator|,
name|loc
argument_list|(
name|loc
argument_list|)
operator|,
name|message
argument_list|(
argument|message
argument_list|)
block|{}
name|bool
name|isWarning
argument_list|()
specifier|const
block|{
return|return
name|kind
operator|==
name|Warning
return|;
block|}
name|bool
name|isError
argument_list|()
specifier|const
block|{
return|return
name|kind
operator|==
name|Error
return|;
block|}
name|Kind
name|kind
decl_stmt|;
name|AST
operator|::
name|SourceLocation
name|loc
expr_stmt|;
name|QString
name|message
decl_stmt|;
block|}
empty_stmt|;
name|class
name|QML_PARSER_EXPORT
name|Engine
block|{
name|Lexer
modifier|*
name|_lexer
decl_stmt|;
name|MemoryPool
name|_pool
decl_stmt|;
name|QList
operator|<
name|AST
operator|::
name|SourceLocation
operator|>
name|_comments
expr_stmt|;
name|QString
name|_extraCode
decl_stmt|;
name|QString
name|_code
decl_stmt|;
name|public
label|:
name|Engine
argument_list|()
expr_stmt|;
operator|~
name|Engine
argument_list|()
expr_stmt|;
name|void
name|setCode
parameter_list|(
specifier|const
name|QString
modifier|&
name|code
parameter_list|)
function_decl|;
name|void
name|addComment
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|line
parameter_list|,
name|int
name|col
parameter_list|)
function_decl|;
name|QList
operator|<
name|AST
operator|::
name|SourceLocation
operator|>
name|comments
argument_list|()
specifier|const
expr_stmt|;
name|Lexer
operator|*
name|lexer
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLexer
parameter_list|(
name|Lexer
modifier|*
name|lexer
parameter_list|)
function_decl|;
name|MemoryPool
modifier|*
name|pool
parameter_list|()
function_decl|;
specifier|inline
name|QStringRef
name|midRef
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|size
parameter_list|)
block|{
return|return
name|_code
operator|.
name|midRef
argument_list|(
name|position
argument_list|,
name|size
argument_list|)
return|;
block|}
name|QStringRef
name|newStringRef
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
function_decl|;
name|QStringRef
name|newStringRef
parameter_list|(
specifier|const
name|QChar
modifier|*
name|chars
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|double
name|integerFromString
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|radix
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_comment
comment|// end of namespace QQmlJS
end_comment
begin_macro
name|QT_QML_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QQMLJSENGINE_P_H
end_comment
end_unit
