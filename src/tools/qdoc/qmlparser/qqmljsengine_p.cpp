begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtQml module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqmljsengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qqmljsglobal_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qnumeric.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_macro
name|QT_QML_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QQmlJS
namespace|namespace
name|QQmlJS
block|{
DECL|function|toDigit
specifier|static
specifier|inline
name|int
name|toDigit
parameter_list|(
name|char
name|c
parameter_list|)
block|{
if|if
condition|(
operator|(
name|c
operator|>=
literal|'0'
operator|)
operator|&&
operator|(
name|c
operator|<=
literal|'9'
operator|)
condition|)
return|return
name|c
operator|-
literal|'0'
return|;
elseif|else
if|if
condition|(
operator|(
name|c
operator|>=
literal|'a'
operator|)
operator|&&
operator|(
name|c
operator|<=
literal|'z'
operator|)
condition|)
return|return
literal|10
operator|+
name|c
operator|-
literal|'a'
return|;
elseif|else
if|if
condition|(
operator|(
name|c
operator|>=
literal|'A'
operator|)
operator|&&
operator|(
name|c
operator|<=
literal|'Z'
operator|)
condition|)
return|return
literal|10
operator|+
name|c
operator|-
literal|'A'
return|;
return|return
operator|-
literal|1
return|;
block|}
DECL|function|integerFromString
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
block|{
if|if
condition|(
name|size
operator|==
literal|0
condition|)
return|return
name|qSNaN
argument_list|()
return|;
name|double
name|sign
init|=
literal|1.0
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|buf
index|[
literal|0
index|]
operator|==
literal|'+'
condition|)
block|{
operator|++
name|i
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|buf
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
block|{
name|sign
operator|=
operator|-
literal|1.0
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
if|if
condition|(
operator|(
operator|(
name|size
operator|-
name|i
operator|)
operator|>=
literal|2
operator|)
operator|&&
operator|(
name|buf
index|[
name|i
index|]
operator|==
literal|'0'
operator|)
condition|)
block|{
if|if
condition|(
operator|(
operator|(
name|buf
index|[
name|i
operator|+
literal|1
index|]
operator|==
literal|'x'
operator|)
operator|||
operator|(
name|buf
index|[
name|i
operator|+
literal|1
index|]
operator|==
literal|'X'
operator|)
operator|)
operator|&&
operator|(
name|radix
operator|<
literal|34
operator|)
condition|)
block|{
if|if
condition|(
operator|(
name|radix
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|radix
operator|!=
literal|16
operator|)
condition|)
return|return
literal|0
return|;
name|radix
operator|=
literal|16
expr_stmt|;
name|i
operator|+=
literal|2
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|radix
operator|==
literal|0
condition|)
block|{
name|radix
operator|=
literal|8
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|radix
operator|==
literal|0
condition|)
block|{
name|radix
operator|=
literal|10
expr_stmt|;
block|}
name|int
name|j
init|=
name|i
decl_stmt|;
for|for
control|(
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
name|int
name|d
init|=
name|toDigit
argument_list|(
name|buf
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|d
operator|==
operator|-
literal|1
operator|)
operator|||
operator|(
name|d
operator|>=
name|radix
operator|)
condition|)
break|break;
block|}
name|double
name|result
decl_stmt|;
if|if
condition|(
name|j
operator|==
name|i
condition|)
block|{
if|if
condition|(
operator|!
name|qstrcmp
argument_list|(
name|buf
argument_list|,
literal|"Infinity"
argument_list|)
condition|)
name|result
operator|=
name|qInf
argument_list|()
expr_stmt|;
else|else
name|result
operator|=
name|qSNaN
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|result
operator|=
literal|0
expr_stmt|;
name|double
name|multiplier
init|=
literal|1
decl_stmt|;
for|for
control|(
operator|--
name|i
init|;
name|i
operator|>=
name|j
condition|;
operator|--
name|i
operator|,
name|multiplier
operator|*=
name|radix
control|)
name|result
operator|+=
name|toDigit
argument_list|(
name|buf
index|[
name|i
index|]
argument_list|)
operator|*
name|multiplier
expr_stmt|;
block|}
name|result
operator|*=
name|sign
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|integerFromString
name|double
name|integerFromString
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
name|int
name|radix
parameter_list|)
block|{
name|QByteArray
name|ba
init|=
name|str
operator|.
name|trimmed
argument_list|()
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
return|return
name|integerFromString
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|,
name|ba
operator|.
name|size
argument_list|()
argument_list|,
name|radix
argument_list|)
return|;
block|}
DECL|function|Engine
name|Engine
operator|::
name|Engine
parameter_list|()
member_init_list|:
name|_lexer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|_directives
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|~Engine
name|Engine
operator|::
name|~
name|Engine
parameter_list|()
block|{ }
DECL|function|setCode
name|void
name|Engine
operator|::
name|setCode
parameter_list|(
specifier|const
name|QString
modifier|&
name|code
parameter_list|)
block|{
name|_code
operator|=
name|code
expr_stmt|;
block|}
DECL|function|addComment
name|void
name|Engine
operator|::
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
block|{
if|if
condition|(
name|len
operator|>
literal|0
condition|)
name|_comments
operator|.
name|append
argument_list|(
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
argument_list|(
name|pos
argument_list|,
name|len
argument_list|,
name|line
argument_list|,
name|col
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|comments
name|QList
argument_list|<
name|QQmlJS
operator|::
name|AST
operator|::
name|SourceLocation
argument_list|>
name|Engine
operator|::
name|comments
parameter_list|()
specifier|const
block|{
return|return
name|_comments
return|;
block|}
DECL|function|lexer
name|Lexer
modifier|*
name|Engine
operator|::
name|lexer
parameter_list|()
specifier|const
block|{
return|return
name|_lexer
return|;
block|}
DECL|function|setLexer
name|void
name|Engine
operator|::
name|setLexer
parameter_list|(
name|Lexer
modifier|*
name|lexer
parameter_list|)
block|{
name|_lexer
operator|=
name|lexer
expr_stmt|;
block|}
DECL|function|directives
name|Directives
modifier|*
name|Engine
operator|::
name|directives
parameter_list|()
specifier|const
block|{
return|return
name|_directives
return|;
block|}
DECL|function|setDirectives
name|void
name|Engine
operator|::
name|setDirectives
parameter_list|(
name|Directives
modifier|*
name|directives
parameter_list|)
block|{
name|_directives
operator|=
name|directives
expr_stmt|;
block|}
DECL|function|pool
name|MemoryPool
modifier|*
name|Engine
operator|::
name|pool
parameter_list|()
block|{
return|return
operator|&
name|_pool
return|;
block|}
DECL|function|newStringRef
name|QStringRef
name|Engine
operator|::
name|newStringRef
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
specifier|const
name|int
name|pos
init|=
name|_extraCode
operator|.
name|length
argument_list|()
decl_stmt|;
name|_extraCode
operator|+=
name|text
expr_stmt|;
return|return
name|_extraCode
operator|.
name|midRef
argument_list|(
name|pos
argument_list|,
name|text
operator|.
name|length
argument_list|()
argument_list|)
return|;
block|}
DECL|function|newStringRef
name|QStringRef
name|Engine
operator|::
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
block|{
return|return
name|newStringRef
argument_list|(
name|QString
argument_list|(
name|chars
argument_list|,
name|size
argument_list|)
argument_list|)
return|;
block|}
block|}
end_namespace
begin_comment
comment|// end of namespace QQmlJS
end_comment
begin_macro
name|QT_QML_END_NAMESPACE
end_macro
end_unit
