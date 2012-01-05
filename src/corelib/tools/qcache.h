begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCACHE_H
end_ifndef
begin_define
DECL|macro|QCACHE_H
define|#
directive|define
name|QCACHE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|template
decl|<
name|class
name|Key
decl_stmt|,
name|class
name|T
decl|>
name|class
name|QCache
block|{
struct|struct
name|Node
block|{
specifier|inline
name|Node
argument_list|()
operator|:
name|keyPtr
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|Node
argument_list|(
argument|T *data
argument_list|,
argument|int cost
argument_list|)
operator|:
name|keyPtr
argument_list|(
literal|0
argument_list|)
operator|,
name|t
argument_list|(
name|data
argument_list|)
operator|,
name|c
argument_list|(
name|cost
argument_list|)
operator|,
name|p
argument_list|(
literal|0
argument_list|)
operator|,
name|n
argument_list|(
literal|0
argument_list|)
block|{}
specifier|const
name|Key
operator|*
name|keyPtr
expr_stmt|;
name|T
modifier|*
name|t
decl_stmt|;
name|int
name|c
decl_stmt|;
name|Node
modifier|*
name|p
decl_stmt|,
modifier|*
name|n
decl_stmt|;
block|}
struct|;
name|Node
modifier|*
name|f
decl_stmt|,
modifier|*
name|l
decl_stmt|;
name|QHash
operator|<
name|Key
operator|,
name|Node
operator|>
name|hash
expr_stmt|;
name|void
modifier|*
name|unused
decl_stmt|;
comment|// ### Qt5: remove
name|int
name|mx
decl_stmt|,
name|total
decl_stmt|;
specifier|inline
name|void
name|unlink
parameter_list|(
name|Node
modifier|&
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
operator|.
name|p
condition|)
name|n
operator|.
name|p
operator|->
name|n
operator|=
name|n
operator|.
name|n
expr_stmt|;
if|if
condition|(
name|n
operator|.
name|n
condition|)
name|n
operator|.
name|n
operator|->
name|p
operator|=
name|n
operator|.
name|p
expr_stmt|;
if|if
condition|(
name|l
operator|==
operator|&
name|n
condition|)
name|l
operator|=
name|n
operator|.
name|p
expr_stmt|;
if|if
condition|(
name|f
operator|==
operator|&
name|n
condition|)
name|f
operator|=
name|n
operator|.
name|n
expr_stmt|;
name|total
operator|-=
name|n
operator|.
name|c
expr_stmt|;
name|T
modifier|*
name|obj
init|=
name|n
operator|.
name|t
decl_stmt|;
name|hash
operator|.
name|remove
argument_list|(
operator|*
name|n
operator|.
name|keyPtr
argument_list|)
expr_stmt|;
name|delete
name|obj
decl_stmt|;
block|}
specifier|inline
name|T
modifier|*
name|relink
parameter_list|(
specifier|const
name|Key
modifier|&
name|key
parameter_list|)
block|{
name|typename
name|QHash
operator|<
name|Key
operator|,
name|Node
operator|>
operator|::
name|iterator
name|i
operator|=
name|hash
operator|.
name|find
argument_list|(
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
name|typename
name|QHash
operator|<
name|Key
operator|,
name|Node
operator|>
operator|::
name|const_iterator
argument_list|(
name|i
argument_list|)
operator|==
name|hash
operator|.
name|constEnd
argument_list|()
condition|)
return|return
literal|0
return|;
name|Node
modifier|&
name|n
init|=
operator|*
name|i
decl_stmt|;
if|if
condition|(
name|f
operator|!=
operator|&
name|n
condition|)
block|{
if|if
condition|(
name|n
operator|.
name|p
condition|)
name|n
operator|.
name|p
operator|->
name|n
operator|=
name|n
operator|.
name|n
expr_stmt|;
if|if
condition|(
name|n
operator|.
name|n
condition|)
name|n
operator|.
name|n
operator|->
name|p
operator|=
name|n
operator|.
name|p
expr_stmt|;
if|if
condition|(
name|l
operator|==
operator|&
name|n
condition|)
name|l
operator|=
name|n
operator|.
name|p
expr_stmt|;
name|n
operator|.
name|p
operator|=
literal|0
expr_stmt|;
name|n
operator|.
name|n
operator|=
name|f
expr_stmt|;
name|f
operator|->
name|p
operator|=
operator|&
name|n
expr_stmt|;
name|f
operator|=
operator|&
name|n
expr_stmt|;
block|}
return|return
name|n
operator|.
name|t
return|;
block|}
name|Q_DISABLE_COPY
argument_list|(
argument|QCache
argument_list|)
name|public
label|:
specifier|inline
name|explicit
name|QCache
parameter_list|(
name|int
name|maxCost
init|=
literal|100
parameter_list|)
function_decl|;
specifier|inline
operator|~
name|QCache
argument_list|()
block|{
name|clear
argument_list|()
block|; }
specifier|inline
name|int
name|maxCost
argument_list|()
specifier|const
block|{
return|return
name|mx
return|;
block|}
name|void
name|setMaxCost
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|;
specifier|inline
name|int
name|totalCost
argument_list|()
specifier|const
block|{
return|return
name|total
return|;
block|}
specifier|inline
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|hash
operator|.
name|size
argument_list|()
return|;
block|}
specifier|inline
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
name|hash
operator|.
name|size
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|hash
operator|.
name|isEmpty
argument_list|()
return|;
block|}
specifier|inline
name|QList
operator|<
name|Key
operator|>
name|keys
argument_list|()
specifier|const
block|{
return|return
name|hash
operator|.
name|keys
argument_list|()
return|;
block|}
name|void
name|clear
parameter_list|()
function_decl|;
name|bool
name|insert
parameter_list|(
specifier|const
name|Key
modifier|&
name|key
parameter_list|,
name|T
modifier|*
name|object
parameter_list|,
name|int
name|cost
init|=
literal|1
parameter_list|)
function_decl|;
name|T
modifier|*
name|object
argument_list|(
specifier|const
name|Key
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|bool
name|contains
argument_list|(
specifier|const
name|Key
operator|&
name|key
argument_list|)
decl|const
block|{
return|return
name|hash
operator|.
name|contains
argument_list|(
name|key
argument_list|)
return|;
block|}
name|T
modifier|*
name|operator
index|[]
argument_list|(
specifier|const
name|Key
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
name|bool
name|remove
parameter_list|(
specifier|const
name|Key
modifier|&
name|key
parameter_list|)
function_decl|;
name|T
modifier|*
name|take
parameter_list|(
specifier|const
name|Key
modifier|&
name|key
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|trim
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|variable|Key
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|variable|Key
DECL|function|QCache
specifier|inline
name|QCache
operator|<
name|Key
operator|,
name|T
operator|>
operator|::
name|QCache
argument_list|(
argument|int amaxCost
argument_list|)
operator|:
name|f
argument_list|(
literal|0
argument_list|)
operator|,
name|l
argument_list|(
literal|0
argument_list|)
operator|,
name|unused
argument_list|(
literal|0
argument_list|)
operator|,
name|mx
argument_list|(
name|amaxCost
argument_list|)
operator|,
name|total
argument_list|(
literal|0
argument_list|)
block|{}
DECL|variable|Key
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|variable|Key
DECL|function|clear
specifier|inline
name|void
name|QCache
operator|<
name|Key
operator|,
name|T
operator|>
operator|::
name|clear
argument_list|()
block|{
while|while
condition|(
name|f
condition|)
block|{
name|delete
name|f
operator|->
name|t
decl_stmt|;
name|f
operator|=
name|f
operator|->
name|n
expr_stmt|;
block|}
name|hash
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|l
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|total
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  template
DECL|variable|Key
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|variable|Key
DECL|function|setMaxCost
specifier|inline
name|void
name|QCache
operator|<
name|Key
operator|,
name|T
operator|>
operator|::
name|setMaxCost
argument_list|(
argument|int m
argument_list|)
block|{
name|mx
operator|=
name|m
block|;
name|trim
argument_list|(
name|mx
argument_list|)
block|; }
DECL|variable|Key
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|variable|Key
DECL|function|object
specifier|inline
name|T
operator|*
name|QCache
operator|<
name|Key
operator|,
name|T
operator|>
operator|::
name|object
argument_list|(
argument|const Key&key
argument_list|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|QCache
operator|<
name|Key
operator|,
name|T
operator|>
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|relink
argument_list|(
name|key
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|variable|Key
DECL|function|operator
specifier|inline
name|T
operator|*
name|QCache
operator|<
name|Key
operator|,
name|T
operator|>
operator|::
name|operator
index|[]
operator|(
specifier|const
name|Key
operator|&
name|key
operator|)
specifier|const
block|{
return|return
name|object
argument_list|(
name|key
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|variable|Key
DECL|function|remove
specifier|inline
name|bool
name|QCache
operator|<
name|Key
operator|,
name|T
operator|>
operator|::
name|remove
argument_list|(
argument|const Key&key
argument_list|)
block|{
name|typename
name|QHash
operator|<
name|Key
block|,
name|Node
operator|>
operator|::
name|iterator
name|i
operator|=
name|hash
operator|.
name|find
argument_list|(
name|key
argument_list|)
block|;
if|if
condition|(
name|typename
name|QHash
operator|<
name|Key
operator|,
name|Node
operator|>
operator|::
name|const_iterator
argument_list|(
name|i
argument_list|)
operator|==
name|hash
operator|.
name|constEnd
argument_list|()
condition|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|unlink
argument_list|(
operator|*
name|i
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_else
begin_expr_stmt
unit|}  template
DECL|variable|Key
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|variable|Key
DECL|function|take
specifier|inline
name|T
operator|*
name|QCache
operator|<
name|Key
operator|,
name|T
operator|>
operator|::
name|take
argument_list|(
argument|const Key&key
argument_list|)
block|{
name|typename
name|QHash
operator|<
name|Key
block|,
name|Node
operator|>
operator|::
name|iterator
name|i
operator|=
name|hash
operator|.
name|find
argument_list|(
name|key
argument_list|)
block|;
if|if
condition|(
name|i
operator|==
name|hash
operator|.
name|end
argument_list|()
condition|)
return|return
literal|0
return|;
name|Node
operator|&
name|n
operator|=
operator|*
name|i
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|T
modifier|*
name|t
init|=
name|n
operator|.
name|t
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|n
operator|.
name|t
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|unlink
argument_list|(
name|n
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|t
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|variable|Key
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|variable|Key
DECL|function|insert
name|bool
name|QCache
operator|<
name|Key
operator|,
name|T
operator|>
operator|::
name|insert
argument_list|(
argument|const Key&akey
argument_list|,
argument|T *aobject
argument_list|,
argument|int acost
argument_list|)
block|{
name|remove
argument_list|(
name|akey
argument_list|)
block|;
if|if
condition|(
name|acost
operator|>
name|mx
condition|)
block|{
name|delete
name|aobject
decl_stmt|;
return|return
name|false
return|;
block|}
name|trim
argument_list|(
name|mx
operator|-
name|acost
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|Node
name|sn
parameter_list|(
name|aobject
parameter_list|,
name|acost
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|typename
name|QHash
operator|<
name|Key
operator|,
name|Node
operator|>
operator|::
name|iterator
name|i
operator|=
name|hash
operator|.
name|insert
argument_list|(
name|akey
argument_list|,
name|sn
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|total
operator|+=
name|acost
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|Node
modifier|*
name|n
init|=
operator|&
name|i
operator|.
name|value
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|n
operator|->
name|keyPtr
operator|=
operator|&
name|i
operator|.
name|key
argument_list|()
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|f
condition|)
name|f
operator|->
name|p
operator|=
name|n
expr_stmt|;
end_if
begin_expr_stmt
name|n
operator|->
name|n
operator|=
name|f
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|f
operator|=
name|n
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|l
condition|)
name|l
operator|=
name|f
expr_stmt|;
end_if
begin_return
return|return
name|true
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|variable|Key
operator|<
name|class
name|Key
operator|,
name|class
name|T
operator|>
DECL|variable|Key
DECL|function|trim
name|void
name|QCache
operator|<
name|Key
operator|,
name|T
operator|>
operator|::
name|trim
argument_list|(
argument|int m
argument_list|)
block|{
name|Node
operator|*
name|n
operator|=
name|l
block|;
while|while
condition|(
name|n
operator|&&
name|total
operator|>
name|m
condition|)
block|{
name|Node
modifier|*
name|u
init|=
name|n
decl_stmt|;
name|n
operator|=
name|n
operator|->
name|p
expr_stmt|;
name|unlink
argument_list|(
operator|*
name|u
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_macro
unit|}  QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCACHE_H
end_comment
end_unit
