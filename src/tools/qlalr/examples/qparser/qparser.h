begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QLALR module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPARSER_H
end_ifndef
begin_define
DECL|macro|QPARSER_H
define|#
directive|define
name|QPARSER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QSharedDataPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVarLengthArray>
end_include
begin_expr_stmt
DECL|variable|_Parser
DECL|variable|_Table
DECL|variable|_Value
name|template
operator|<
name|typename
name|_Parser
operator|,
name|typename
name|_Table
operator|,
name|typename
name|_Value
operator|=
name|int
operator|>
name|class
name|QParser
operator|:
name|protected
name|_Table
block|{
name|public
operator|:
name|QParser
argument_list|()
block|;
operator|~
name|QParser
argument_list|()
block|;
name|bool
name|parse
argument_list|()
block|;
specifier|inline
name|_Value
operator|&
name|sym
argument_list|(
argument|int index
argument_list|)
block|;
name|private
operator|:
specifier|inline
name|int
name|nextToken
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|_Parser
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|nextToken
argument_list|()
return|;
block|}
specifier|inline
name|void
name|consumeRule
argument_list|(
argument|int rule
argument_list|)
block|{
name|static_cast
operator|<
name|_Parser
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|consumeRule
argument_list|(
name|rule
argument_list|)
block|;     }
expr|enum
block|{
name|DefaultStackSize
operator|=
literal|128
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|struct
name|Data
range|:
name|public
name|QSharedData
block|{
name|Data
argument_list|()
operator|:
name|stackSize
argument_list|(
name|DefaultStackSize
argument_list|)
block|,
name|tos
argument_list|(
literal|0
argument_list|)
block|{}
name|QVarLengthArray
operator|<
name|int
block|,
name|DefaultStackSize
operator|>
name|stateStack
block|;
name|QVarLengthArray
operator|<
name|_Value
block|,
name|DefaultStackSize
operator|>
name|parseStack
block|;
name|int
name|stackSize
block|;
name|int
name|tos
block|;
name|void
name|reallocateStack
argument_list|()
block|{
name|stackSize
operator|<<=
literal|1
block|;
name|stateStack
operator|.
name|resize
argument_list|(
name|stackSize
argument_list|)
block|;
name|parseStack
operator|.
name|resize
argument_list|(
name|stackSize
argument_list|)
block|;         }
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QSharedDataPointer
operator|<
name|Data
operator|>
name|d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
DECL|variable|_Parser
DECL|variable|_Table
name|template
operator|<
name|typename
name|_Parser
operator|,
name|typename
name|_Table
operator|,
name|typename
name|_Value
operator|>
DECL|variable|_Parser
DECL|variable|_Table
DECL|function|sym
specifier|inline
name|_Value
operator|&
name|QParser
operator|<
name|_Parser
operator|,
name|_Table
operator|,
name|_Value
operator|>
operator|::
name|sym
argument_list|(
argument|int n
argument_list|)
block|{
return|return
name|d
operator|->
name|parseStack
index|[
name|d
operator|->
name|tos
operator|+
name|n
operator|-
literal|1
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|_Parser
DECL|variable|_Table
name|template
operator|<
name|typename
name|_Parser
operator|,
name|typename
name|_Table
operator|,
name|typename
name|_Value
operator|>
DECL|variable|_Parser
DECL|variable|_Table
DECL|function|QParser
name|QParser
operator|<
name|_Parser
operator|,
name|_Table
operator|,
name|_Value
operator|>
operator|::
name|QParser
argument_list|()
operator|:
name|d
argument_list|(
argument|new Data()
argument_list|)
block|{ }
DECL|variable|_Parser
DECL|variable|_Table
name|template
operator|<
name|typename
name|_Parser
operator|,
name|typename
name|_Table
operator|,
name|typename
name|_Value
operator|>
DECL|variable|_Parser
DECL|variable|_Table
DECL|function|~QParser
name|QParser
operator|<
name|_Parser
operator|,
name|_Table
operator|,
name|_Value
operator|>
operator|::
operator|~
name|QParser
argument_list|()
block|{ }
DECL|variable|_Parser
DECL|variable|_Table
name|template
operator|<
name|typename
name|_Parser
operator|,
name|typename
name|_Table
operator|,
name|typename
name|_Value
operator|>
DECL|variable|_Parser
DECL|variable|_Table
DECL|function|parse
name|bool
name|QParser
operator|<
name|_Parser
operator|,
name|_Table
operator|,
name|_Value
operator|>
operator|::
name|parse
argument_list|()
block|{
specifier|const
name|int
name|INITIAL_STATE
operator|=
literal|0
block|;
name|d
operator|->
name|tos
operator|=
literal|0
block|;
name|d
operator|->
name|reallocateStack
argument_list|()
block|;
name|int
name|act
operator|=
name|d
operator|->
name|stateStack
index|[
operator|++
name|d
operator|->
name|tos
index|]
operator|=
name|INITIAL_STATE
block|;
name|int
name|token
operator|=
operator|-
literal|1
block|;
name|forever
block|{
if|if
condition|(
name|token
operator|==
operator|-
literal|1
operator|&&
operator|-
name|_Table
operator|::
name|TERMINAL_COUNT
operator|!=
name|_Table
operator|::
name|action_index
index|[
name|act
index|]
condition|)
name|token
operator|=
name|nextToken
argument_list|()
expr_stmt|;
name|act
operator|=
name|_Table
operator|::
name|t_action
argument_list|(
name|act
argument_list|,
name|token
argument_list|)
block|;
if|if
condition|(
name|d
operator|->
name|stateStack
index|[
name|d
operator|->
name|tos
index|]
operator|==
name|_Table
operator|::
name|ACCEPT_STATE
condition|)
return|return
name|true
return|;
elseif|else
if|if
condition|(
name|act
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|++
name|d
operator|->
name|tos
operator|==
name|d
operator|->
name|stackSize
condition|)
name|d
operator|->
name|reallocateStack
argument_list|()
expr_stmt|;
name|d
operator|->
name|parseStack
index|[
name|d
operator|->
name|tos
index|]
operator|=
name|d
operator|->
name|parseStack
index|[
name|d
operator|->
name|tos
operator|-
literal|1
index|]
expr_stmt|;
name|d
operator|->
name|stateStack
index|[
name|d
operator|->
name|tos
index|]
operator|=
name|act
expr_stmt|;
name|token
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_expr_stmt
begin_elseif
elseif|else
if|if
condition|(
name|act
operator|<
literal|0
condition|)
block|{
name|int
name|r
init|=
operator|-
name|act
operator|-
literal|1
decl_stmt|;
name|d
operator|->
name|tos
operator|-=
name|_Table
operator|::
name|rhs
index|[
name|r
index|]
expr_stmt|;
name|act
operator|=
name|d
operator|->
name|stateStack
index|[
name|d
operator|->
name|tos
operator|++
index|]
expr_stmt|;
name|consumeRule
argument_list|(
name|r
argument_list|)
expr_stmt|;
name|act
operator|=
name|d
operator|->
name|stateStack
index|[
name|d
operator|->
name|tos
index|]
operator|=
name|_Table
operator|::
name|nt_action
argument_list|(
name|act
argument_list|,
name|_Table
operator|::
name|lhs
index|[
name|r
index|]
operator|-
name|_Table
operator|::
name|TERMINAL_COUNT
argument_list|)
expr_stmt|;
block|}
end_elseif
begin_else
else|else
break|break;
end_else
begin_expr_stmt
unit|}      return
name|false
expr_stmt|;
end_expr_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// QPARSER_H
end_comment
end_unit