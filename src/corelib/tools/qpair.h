begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAIR_H
end_ifndef
begin_define
DECL|macro|QPAIR_H
define|#
directive|define
name|QPAIR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
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
name|T1
decl_stmt|,
name|class
name|T2
decl|> struct
name|QPair
block|{
typedef|typedef
name|T1
name|first_type
typedef|;
typedef|typedef
name|T2
name|second_type
typedef|;
name|QPair
argument_list|()
operator|:
name|first
argument_list|(
name|T1
argument_list|()
argument_list|)
operator|,
name|second
argument_list|(
argument|T2()
argument_list|)
block|{}
name|QPair
argument_list|(
specifier|const
name|T1
operator|&
name|t1
argument_list|,
specifier|const
name|T2
operator|&
name|t2
argument_list|)
operator|:
name|first
argument_list|(
name|t1
argument_list|)
operator|,
name|second
argument_list|(
argument|t2
argument_list|)
block|{}
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|other
operator|)
block|{
name|first
operator|=
name|other
operator|.
name|first
block|;
name|second
operator|=
name|other
operator|.
name|second
block|;
return|return
operator|*
name|this
return|;
block|}
name|T1
name|first
decl_stmt|;
name|T2
name|second
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
name|p1
operator|.
name|first
operator|==
name|p2
operator|.
name|first
operator|&&
name|p1
operator|.
name|second
operator|==
name|p2
operator|.
name|second
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
operator|!
operator|(
name|p1
operator|==
name|p2
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
name|p1
operator|.
name|first
operator|<
name|p2
operator|.
name|first
operator|||
operator|(
operator|!
operator|(
name|p2
operator|.
name|first
operator|<
name|p1
operator|.
name|first
operator|)
operator|&&
name|p1
operator|.
name|second
operator|<
name|p2
operator|.
name|second
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
name|p2
operator|<
name|p1
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|variable|operator
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
operator|!
operator|(
name|p2
operator|<
name|p1
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
name|Q_INLINE_TEMPLATE
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p1
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p2
operator|)
block|{
return|return
operator|!
operator|(
name|p1
operator|<
name|p2
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|variable|T1
DECL|function|qMakePair
name|Q_OUTOFLINE_TEMPLATE
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
name|qMakePair
argument_list|(
argument|const T1&x
argument_list|,
argument|const T2&y
argument_list|)
block|{
return|return
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|(
name|x
operator|,
name|y
operator|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|s
operator|,
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p
operator|)
block|{
name|s
operator|>>
name|p
operator|.
name|first
operator|>>
name|p
operator|.
name|second
block|;
return|return
name|s
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
specifier|inline
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|s
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p
operator|)
block|{
name|s
operator|<<
name|p
operator|.
name|first
operator|<<
name|p
operator|.
name|second
block|;
return|return
name|s
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPAIR_H
end_comment
end_unit
