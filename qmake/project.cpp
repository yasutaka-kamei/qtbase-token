begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"project.h"
end_include
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|<qmakeevaluator_p.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_using
using|using
namespace|namespace
name|QMakeInternal
namespace|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QMakeProject
name|QMakeProject
operator|::
name|QMakeProject
parameter_list|()
member_init_list|:
name|QMakeEvaluator
argument_list|(
name|Option
operator|::
name|globals
argument_list|,
name|Option
operator|::
name|parser
argument_list|,
operator|&
name|Option
operator|::
name|evalHandler
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QMakeProject
name|QMakeProject
operator|::
name|QMakeProject
parameter_list|(
name|QMakeProject
modifier|*
name|p
parameter_list|)
member_init_list|:
name|QMakeEvaluator
argument_list|(
name|Option
operator|::
name|globals
argument_list|,
name|Option
operator|::
name|parser
argument_list|,
operator|&
name|Option
operator|::
name|evalHandler
argument_list|)
block|{
name|initFrom
argument_list|(
operator|*
name|p
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|boolRet
name|bool
name|QMakeProject
operator|::
name|boolRet
parameter_list|(
name|VisitReturn
name|vr
parameter_list|)
block|{
if|if
condition|(
name|vr
operator|==
name|ReturnError
condition|)
name|exit
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|vr
operator|==
name|ReturnTrue
operator|||
name|vr
operator|==
name|ReturnFalse
argument_list|)
expr_stmt|;
return|return
name|vr
operator|!=
name|ReturnFalse
return|;
block|}
end_function
begin_function
DECL|function|read
name|bool
name|QMakeProject
operator|::
name|read
parameter_list|(
specifier|const
name|QString
modifier|&
name|project
parameter_list|,
name|LoadFlags
name|what
parameter_list|)
block|{
name|m_projectFile
operator|=
name|project
expr_stmt|;
name|setOutputDir
argument_list|(
name|Option
operator|::
name|output_dir
argument_list|)
expr_stmt|;
name|QString
name|absproj
init|=
operator|(
name|project
operator|==
name|QLatin1String
argument_list|(
literal|"-"
argument_list|)
operator|)
condition|?
name|QLatin1String
argument_list|(
literal|"(stdin)"
argument_list|)
else|:
name|QDir
operator|::
name|cleanPath
argument_list|(
name|QDir
argument_list|(
name|qmake_getpwd
argument_list|()
argument_list|)
operator|.
name|absoluteFilePath
argument_list|(
name|project
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|boolRet
argument_list|(
name|evaluateFile
argument_list|(
name|absproj
argument_list|,
name|QMakeHandler
operator|::
name|EvalProjectFile
argument_list|,
name|what
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|prepareBuiltinArgs
specifier|static
name|ProStringList
name|prepareBuiltinArgs
parameter_list|(
specifier|const
name|QList
argument_list|<
name|ProStringList
argument_list|>
modifier|&
name|args
parameter_list|)
block|{
name|ProStringList
name|ret
decl_stmt|;
name|ret
operator|.
name|reserve
argument_list|(
name|args
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|ProStringList
modifier|&
name|arg
decl|,
name|args
control|)
name|ret
operator|<<
name|arg
operator|.
name|join
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|test
name|bool
name|QMakeProject
operator|::
name|test
parameter_list|(
specifier|const
name|ProKey
modifier|&
name|func
parameter_list|,
specifier|const
name|QList
argument_list|<
name|ProStringList
argument_list|>
modifier|&
name|args
parameter_list|)
block|{
name|m_current
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|int
name|func_t
init|=
name|statics
operator|.
name|functions
operator|.
name|value
argument_list|(
name|func
argument_list|)
condition|)
return|return
name|boolRet
argument_list|(
name|evaluateBuiltinConditional
argument_list|(
name|func_t
argument_list|,
name|func
argument_list|,
name|prepareBuiltinArgs
argument_list|(
name|args
argument_list|)
argument_list|)
argument_list|)
return|;
name|QHash
argument_list|<
name|ProKey
argument_list|,
name|ProFunctionDef
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|m_functionDefs
operator|.
name|testFunctions
operator|.
name|constFind
argument_list|(
name|func
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|m_functionDefs
operator|.
name|testFunctions
operator|.
name|constEnd
argument_list|()
condition|)
return|return
name|boolRet
argument_list|(
name|evaluateBoolFunction
argument_list|(
operator|*
name|it
argument_list|,
name|args
argument_list|,
name|func
argument_list|)
argument_list|)
return|;
name|evalError
argument_list|(
name|QStringLiteral
argument_list|(
literal|"'%1' is not a recognized test function."
argument_list|)
operator|.
name|arg
argument_list|(
name|func
operator|.
name|toQString
argument_list|(
name|m_tmp1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|expand
name|QStringList
name|QMakeProject
operator|::
name|expand
parameter_list|(
specifier|const
name|ProKey
modifier|&
name|func
parameter_list|,
specifier|const
name|QList
argument_list|<
name|ProStringList
argument_list|>
modifier|&
name|args
parameter_list|)
block|{
name|m_current
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|int
name|func_t
init|=
name|statics
operator|.
name|expands
operator|.
name|value
argument_list|(
name|func
argument_list|)
condition|)
return|return
name|evaluateBuiltinExpand
argument_list|(
name|func_t
argument_list|,
name|func
argument_list|,
name|prepareBuiltinArgs
argument_list|(
name|args
argument_list|)
argument_list|)
operator|.
name|toQStringList
argument_list|()
return|;
name|QHash
argument_list|<
name|ProKey
argument_list|,
name|ProFunctionDef
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|m_functionDefs
operator|.
name|replaceFunctions
operator|.
name|constFind
argument_list|(
name|func
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|m_functionDefs
operator|.
name|replaceFunctions
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|QMakeProject
operator|::
name|VisitReturn
name|vr
decl_stmt|;
name|ProStringList
name|ret
init|=
name|evaluateFunction
argument_list|(
operator|*
name|it
argument_list|,
name|args
argument_list|,
operator|&
name|vr
argument_list|)
decl_stmt|;
if|if
condition|(
name|vr
operator|==
name|QMakeProject
operator|::
name|ReturnError
condition|)
name|exit
argument_list|(
literal|3
argument_list|)
expr_stmt|;
return|return
name|ret
operator|.
name|toQStringList
argument_list|()
return|;
block|}
name|evalError
argument_list|(
name|QStringLiteral
argument_list|(
literal|"'%1' is not a recognized replace function."
argument_list|)
operator|.
name|arg
argument_list|(
name|func
operator|.
name|toQString
argument_list|(
name|m_tmp1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|expand
name|ProString
name|QMakeProject
operator|::
name|expand
parameter_list|(
specifier|const
name|QString
modifier|&
name|expr
parameter_list|,
specifier|const
name|QString
modifier|&
name|where
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|ProString
name|ret
decl_stmt|;
if|if
condition|(
name|ProFile
modifier|*
name|pro
init|=
name|m_parser
operator|->
name|parsedProBlock
argument_list|(
name|expr
argument_list|,
name|where
argument_list|,
name|line
argument_list|,
name|QMakeParser
operator|::
name|ValueGrammar
argument_list|)
condition|)
block|{
if|if
condition|(
name|pro
operator|->
name|isOk
argument_list|()
condition|)
block|{
name|m_current
operator|.
name|pro
operator|=
name|pro
expr_stmt|;
name|m_current
operator|.
name|line
operator|=
literal|0
expr_stmt|;
specifier|const
name|ushort
modifier|*
name|tokPtr
init|=
name|pro
operator|->
name|tokPtr
argument_list|()
decl_stmt|;
name|ProStringList
name|result
init|=
name|expandVariableReferences
argument_list|(
name|tokPtr
argument_list|,
literal|1
argument_list|,
literal|true
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|result
operator|.
name|isEmpty
argument_list|()
condition|)
name|ret
operator|=
name|result
operator|.
name|at
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|pro
operator|->
name|deref
argument_list|()
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|isEmpty
name|bool
name|QMakeProject
operator|::
name|isEmpty
parameter_list|(
specifier|const
name|ProKey
modifier|&
name|v
parameter_list|)
specifier|const
block|{
name|ProValueMap
operator|::
name|ConstIterator
name|it
init|=
name|m_valuemapStack
operator|.
name|first
argument_list|()
operator|.
name|constFind
argument_list|(
name|v
argument_list|)
decl_stmt|;
return|return
name|it
operator|==
name|m_valuemapStack
operator|.
name|first
argument_list|()
operator|.
name|constEnd
argument_list|()
operator|||
name|it
operator|->
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|dump
name|void
name|QMakeProject
operator|::
name|dump
parameter_list|()
specifier|const
block|{
name|QStringList
name|out
decl_stmt|;
for|for
control|(
name|ProValueMap
operator|::
name|ConstIterator
name|it
init|=
name|m_valuemapStack
operator|.
name|first
argument_list|()
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|m_valuemapStack
operator|.
name|first
argument_list|()
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
operator|!
name|it
operator|.
name|key
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|'.'
argument_list|)
condition|)
block|{
name|QString
name|str
init|=
name|it
operator|.
name|key
argument_list|()
operator|+
literal|" ="
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|ProString
modifier|&
name|v
decl|,
name|it
operator|.
name|value
argument_list|()
control|)
name|str
operator|+=
literal|' '
operator|+
name|formatValue
argument_list|(
name|v
argument_list|)
expr_stmt|;
name|out
operator|<<
name|str
expr_stmt|;
block|}
block|}
name|out
operator|.
name|sort
argument_list|()
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|v
decl|,
name|out
control|)
name|puts
argument_list|(
name|qPrintable
argument_list|(
name|v
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
