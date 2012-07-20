begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PARSER_H
end_ifndef
begin_define
DECL|macro|PARSER_H
define|#
directive|define
name|PARSER_H
end_define
begin_include
include|#
directive|include
file|<QStack>
end_include
begin_include
include|#
directive|include
file|"symbols.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Parser
block|{
name|public
label|:
name|Parser
argument_list|()
operator|:
name|index
argument_list|(
literal|0
argument_list|)
operator|,
name|displayWarnings
argument_list|(
name|true
argument_list|)
operator|,
name|displayNotes
argument_list|(
argument|true
argument_list|)
block|{}
name|Symbols
name|symbols
expr_stmt|;
name|int
name|index
decl_stmt|;
name|bool
name|displayWarnings
decl_stmt|;
name|bool
name|displayNotes
decl_stmt|;
struct|struct
name|IncludePath
block|{
specifier|inline
name|explicit
name|IncludePath
argument_list|(
specifier|const
name|QByteArray
operator|&
name|_path
argument_list|)
operator|:
name|path
argument_list|(
name|_path
argument_list|)
operator|,
name|isFrameworkPath
argument_list|(
argument|false
argument_list|)
block|{}
name|QByteArray
name|path
expr_stmt|;
name|bool
name|isFrameworkPath
decl_stmt|;
block|}
struct|;
name|QList
operator|<
name|IncludePath
operator|>
name|includes
expr_stmt|;
name|QStack
operator|<
name|QByteArray
operator|>
name|currentFilenames
expr_stmt|;
specifier|inline
name|bool
name|hasNext
argument_list|()
specifier|const
block|{
return|return
operator|(
name|index
operator|<
name|symbols
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|Token
name|next
parameter_list|()
block|{
if|if
condition|(
name|index
operator|>=
name|symbols
operator|.
name|size
argument_list|()
condition|)
return|return
name|NOTOKEN
return|;
return|return
name|symbols
operator|.
name|at
argument_list|(
name|index
operator|++
argument_list|)
operator|.
name|token
return|;
block|}
name|bool
name|test
parameter_list|(
name|Token
parameter_list|)
function_decl|;
name|void
name|next
parameter_list|(
name|Token
parameter_list|)
function_decl|;
name|void
name|next
parameter_list|(
name|Token
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
specifier|inline
name|void
name|prev
parameter_list|()
block|{
operator|--
name|index
expr_stmt|;
block|}
specifier|inline
name|Token
name|lookup
parameter_list|(
name|int
name|k
init|=
literal|1
parameter_list|)
function_decl|;
specifier|inline
specifier|const
name|Symbol
modifier|&
name|symbol_lookup
parameter_list|(
name|int
name|k
init|=
literal|1
parameter_list|)
block|{
return|return
name|symbols
operator|.
name|at
argument_list|(
name|index
operator|-
literal|1
operator|+
name|k
argument_list|)
return|;
block|}
specifier|inline
name|Token
name|token
parameter_list|()
block|{
return|return
name|symbols
operator|.
name|at
argument_list|(
name|index
operator|-
literal|1
argument_list|)
operator|.
name|token
return|;
block|}
specifier|inline
name|QByteArray
name|lexem
parameter_list|()
block|{
return|return
name|symbols
operator|.
name|at
argument_list|(
name|index
operator|-
literal|1
argument_list|)
operator|.
name|lexem
argument_list|()
return|;
block|}
specifier|inline
name|QByteArray
name|unquotedLexem
parameter_list|()
block|{
return|return
name|symbols
operator|.
name|at
argument_list|(
name|index
operator|-
literal|1
argument_list|)
operator|.
name|unquotedLexem
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|Symbol
modifier|&
name|symbol
parameter_list|()
block|{
return|return
name|symbols
operator|.
name|at
argument_list|(
name|index
operator|-
literal|1
argument_list|)
return|;
block|}
name|void
name|error
parameter_list|(
name|int
name|rollback
parameter_list|)
function_decl|;
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|warning
parameter_list|(
specifier|const
name|char
modifier|*
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|note
parameter_list|(
specifier|const
name|char
modifier|*
init|=
literal|0
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|test
specifier|inline
name|bool
name|Parser
operator|::
name|test
argument_list|(
argument|Token token
argument_list|)
block|{
if|if
condition|(
name|index
operator|<
name|symbols
operator|.
name|size
argument_list|()
operator|&&
name|symbols
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|token
operator|==
name|token
condition|)
block|{
operator|++
name|index
expr_stmt|;
return|return
name|true
return|;
block|}
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|lookup
name|Token
name|Parser
operator|::
name|lookup
argument_list|(
argument|int k
argument_list|)
block|{
specifier|const
name|int
name|l
operator|=
name|index
operator|-
literal|1
operator|+
name|k
block|;
return|return
name|l
operator|<
name|symbols
operator|.
name|size
argument_list|()
condition|?
name|symbols
operator|.
name|at
argument_list|(
name|l
argument_list|)
operator|.
name|token
else|:
name|NOTOKEN
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|next
specifier|inline
name|void
name|Parser
operator|::
name|next
argument_list|(
argument|Token token
argument_list|)
block|{
if|if
condition|(
operator|!
name|test
argument_list|(
name|token
argument_list|)
condition|)
name|error
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|next
specifier|inline
name|void
name|Parser
operator|::
name|next
argument_list|(
argument|Token token
argument_list|,
argument|const char *msg
argument_list|)
block|{
if|if
condition|(
operator|!
name|test
argument_list|(
name|token
argument_list|)
condition|)
name|error
argument_list|(
name|msg
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
