begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTACK_H
end_ifndef
begin_define
DECL|macro|QSTACK_H
define|#
directive|define
name|QSTACK_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
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
name|T
decl|>
name|class
name|QStack
range|:
name|public
name|QVector
operator|<
name|T
operator|>
block|{
name|public
operator|:
specifier|inline
name|QStack
argument_list|()
block|{}
specifier|inline
operator|~
name|QStack
argument_list|()
block|{}
specifier|inline
name|void
name|swap
argument_list|(
argument|QStack<T>&other
argument_list|)
block|{
name|QVector
operator|<
name|T
operator|>
operator|::
name|swap
argument_list|(
name|other
argument_list|)
block|; }
comment|// prevent QVector<->QStack swaps
specifier|inline
name|void
name|push
argument_list|(
argument|const T&t
argument_list|)
block|{
name|QVector
operator|<
name|T
operator|>
operator|::
name|append
argument_list|(
name|t
argument_list|)
block|; }
name|T
name|pop
argument_list|()
block|;
name|T
operator|&
name|top
argument_list|()
block|;
specifier|const
name|T
operator|&
name|top
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|pop
specifier|inline
name|T
name|QStack
operator|<
name|T
operator|>
operator|::
name|pop
argument_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|isEmpty
argument_list|()
argument_list|)
block|;
name|T
name|t
operator|=
name|this
operator|->
name|data
argument_list|()
index|[
name|this
operator|->
name|size
argument_list|()
operator|-
literal|1
index|]
block|;
name|this
operator|->
name|resize
argument_list|(
name|this
operator|->
name|size
argument_list|()
operator|-
literal|1
argument_list|)
block|;
return|return
name|t
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|top
specifier|inline
name|T
operator|&
name|QStack
operator|<
name|T
operator|>
operator|::
name|top
argument_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|isEmpty
argument_list|()
argument_list|)
block|;
name|this
operator|->
name|detach
argument_list|()
block|;
return|return
name|this
operator|->
name|data
argument_list|()
index|[
name|this
operator|->
name|size
argument_list|()
operator|-
literal|1
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|top
specifier|inline
specifier|const
name|T
operator|&
name|QStack
operator|<
name|T
operator|>
operator|::
name|top
argument_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|isEmpty
argument_list|()
argument_list|)
block|;
return|return
name|this
operator|->
name|data
argument_list|()
index|[
name|this
operator|->
name|size
argument_list|()
operator|-
literal|1
index|]
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
comment|// QSTACK_H
end_comment
end_unit
