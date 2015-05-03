begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIZE_H
end_ifndef
begin_define
DECL|macro|QSIZE_H
define|#
directive|define
name|QSIZE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_CORE_EXPORT
name|QSize
block|{
name|public
label|:
name|Q_DECL_CONSTEXPR
name|QSize
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|QSize
argument_list|(
name|int
name|w
argument_list|,
name|int
name|h
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|width
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|height
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|void
name|setWidth
argument_list|(
name|int
name|w
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|void
name|setHeight
argument_list|(
name|int
name|h
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|void
name|transpose
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSize
name|transposed
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
expr_stmt|;
specifier|inline
name|void
name|scale
argument_list|(
name|int
name|w
argument_list|,
name|int
name|h
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
specifier|inline
name|void
name|scale
argument_list|(
specifier|const
name|QSize
operator|&
name|s
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|QSize
name|scaled
argument_list|(
name|int
name|w
argument_list|,
name|int
name|h
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
name|QSize
name|scaled
argument_list|(
specifier|const
name|QSize
operator|&
name|s
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSize
name|expandedTo
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSize
name|boundedTo
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|int
operator|&
name|rwidth
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|int
operator|&
name|rheight
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSize
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QSize
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSize
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QSize
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSize
operator|&
name|operator
operator|*=
operator|(
name|qreal
name|c
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
specifier|inline
name|QSize
operator|&
name|operator
operator|/=
operator|(
name|qreal
name|c
operator|)
expr_stmt|;
name|friend
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSize
operator|&
operator|,
specifier|const
name|QSize
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|friend
specifier|inline
name|Q_DECL_CONSTEXPR
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSize
operator|&
operator|,
specifier|const
name|QSize
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|friend
specifier|inline
name|Q_DECL_CONSTEXPR
specifier|const
name|QSize
name|operator
operator|+
operator|(
specifier|const
name|QSize
operator|&
operator|,
specifier|const
name|QSize
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|friend
specifier|inline
name|Q_DECL_CONSTEXPR
specifier|const
name|QSize
name|operator
operator|-
operator|(
specifier|const
name|QSize
operator|&
operator|,
specifier|const
name|QSize
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|friend
specifier|inline
name|Q_DECL_CONSTEXPR
specifier|const
name|QSize
name|operator
modifier|*
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|,
name|qreal
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|friend
specifier|inline
name|Q_DECL_CONSTEXPR
specifier|const
name|QSize
name|operator
modifier|*
argument_list|(
name|qreal
argument_list|,
specifier|const
name|QSize
operator|&
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|friend
specifier|inline
specifier|const
name|QSize
name|operator
operator|/
operator|(
specifier|const
name|QSize
operator|&
operator|,
name|qreal
operator|)
expr_stmt|;
name|private
label|:
name|int
name|wd
decl_stmt|;
name|int
name|ht
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QSize
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*****************************************************************************   QSize stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QSize inline functions  *****************************************************************************/
end_comment
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSize
operator|::
name|QSize
argument_list|()
name|Q_DECL_NOTHROW
operator|:
name|wd
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|ht
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
DECL|function|ht
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSize
operator|::
name|QSize
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
name|Q_DECL_NOTHROW
operator|:
name|wd
argument_list|(
name|w
argument_list|)
operator|,
name|ht
argument_list|(
argument|h
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|QSize
operator|::
name|isNull
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|wd
operator|==
literal|0
operator|&&
name|ht
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|QSize
operator|::
name|isEmpty
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|wd
operator|<
literal|1
operator|||
name|ht
operator|<
literal|1
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|QSize
operator|::
name|isValid
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|wd
operator|>=
literal|0
operator|&&
name|ht
operator|>=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QSize
operator|::
name|width
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|wd
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QSize
operator|::
name|height
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|void
name|QSize
operator|::
name|setWidth
argument_list|(
argument|int w
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|wd
operator|=
name|w
block|; }
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|void
name|QSize
operator|::
name|setHeight
argument_list|(
argument|int h
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|ht
operator|=
name|h
block|; }
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSize
name|QSize
operator|::
name|transposed
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|QSize
argument_list|(
name|ht
argument_list|,
name|wd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|void
name|QSize
operator|::
name|scale
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|Qt::AspectRatioMode mode
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|scale
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|)
block|; }
specifier|inline
name|void
name|QSize
operator|::
name|scale
argument_list|(
argument|const QSize&s
argument_list|,
argument|Qt::AspectRatioMode mode
argument_list|)
name|Q_DECL_NOTHROW
block|{
operator|*
name|this
operator|=
name|scaled
argument_list|(
name|s
argument_list|,
name|mode
argument_list|)
block|; }
specifier|inline
name|QSize
name|QSize
operator|::
name|scaled
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|Qt::AspectRatioMode mode
argument_list|)
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|scaled
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|int
operator|&
name|QSize
operator|::
name|rwidth
argument_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|wd
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|int
operator|&
name|QSize
operator|::
name|rheight
argument_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|member|operator
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSize
operator|&
name|QSize
operator|::
name|operator
operator|+=
operator|(
specifier|const
name|QSize
operator|&
name|s
operator|)
name|Q_DECL_NOTHROW
block|{
name|wd
operator|+=
name|s
operator|.
name|wd
block|;
name|ht
operator|+=
name|s
operator|.
name|ht
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSize
operator|&
name|QSize
operator|::
name|operator
operator|-=
operator|(
specifier|const
name|QSize
operator|&
name|s
operator|)
name|Q_DECL_NOTHROW
block|{
name|wd
operator|-=
name|s
operator|.
name|wd
block|;
name|ht
operator|-=
name|s
operator|.
name|ht
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSize
operator|&
name|QSize
operator|::
name|operator
operator|*=
operator|(
name|qreal
name|c
operator|)
name|Q_DECL_NOTHROW
block|{
name|wd
operator|=
name|qRound
argument_list|(
name|wd
operator|*
name|c
argument_list|)
block|;
name|ht
operator|=
name|qRound
argument_list|(
name|ht
operator|*
name|c
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSize
operator|&
name|s1
operator|,
specifier|const
name|QSize
operator|&
name|s2
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|s1
operator|.
name|wd
operator|==
name|s2
operator|.
name|wd
operator|&&
name|s1
operator|.
name|ht
operator|==
name|s2
operator|.
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSize
operator|&
name|s1
operator|,
specifier|const
name|QSize
operator|&
name|s2
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|s1
operator|.
name|wd
operator|!=
name|s2
operator|.
name|wd
operator|||
name|s1
operator|.
name|ht
operator|!=
name|s2
operator|.
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSize
name|operator
operator|+
operator|(
specifier|const
name|QSize
operator|&
name|s1
operator|,
specifier|const
name|QSize
operator|&
name|s2
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QSize
argument_list|(
name|s1
operator|.
name|wd
operator|+
name|s2
operator|.
name|wd
argument_list|,
name|s1
operator|.
name|ht
operator|+
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSize
name|operator
operator|-
operator|(
specifier|const
name|QSize
operator|&
name|s1
operator|,
specifier|const
name|QSize
operator|&
name|s2
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QSize
argument_list|(
name|s1
operator|.
name|wd
operator|-
name|s2
operator|.
name|wd
argument_list|,
name|s1
operator|.
name|ht
operator|-
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSize
name|operator
modifier|*
parameter_list|(
specifier|const
name|QSize
modifier|&
name|s
parameter_list|,
name|qreal
name|c
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|QSize
argument_list|(
name|qRound
argument_list|(
name|s
operator|.
name|wd
operator|*
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|s
operator|.
name|ht
operator|*
name|c
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSize
name|operator
modifier|*
parameter_list|(
name|qreal
name|c
parameter_list|,
specifier|const
name|QSize
modifier|&
name|s
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|QSize
argument_list|(
name|qRound
argument_list|(
name|s
operator|.
name|wd
operator|*
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|s
operator|.
name|ht
operator|*
name|c
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QSize
operator|&
name|QSize
operator|::
name|operator
operator|/=
operator|(
name|qreal
name|c
operator|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|c
argument_list|)
argument_list|)
block|;
name|wd
operator|=
name|qRound
argument_list|(
name|wd
operator|/
name|c
argument_list|)
block|;
name|ht
operator|=
name|qRound
argument_list|(
name|ht
operator|/
name|c
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QSize
name|operator
operator|/
operator|(
specifier|const
name|QSize
operator|&
name|s
operator|,
name|qreal
name|c
operator|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|c
argument_list|)
argument_list|)
block|;
return|return
name|QSize
argument_list|(
name|qRound
argument_list|(
name|s
operator|.
name|wd
operator|/
name|c
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|s
operator|.
name|ht
operator|/
name|c
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSize
name|QSize
operator|::
name|expandedTo
argument_list|(
argument|const QSize& otherSize
argument_list|)
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|QSize
argument_list|(
name|qMax
argument_list|(
name|wd
argument_list|,
name|otherSize
operator|.
name|wd
argument_list|)
argument_list|,
name|qMax
argument_list|(
name|ht
argument_list|,
name|otherSize
operator|.
name|ht
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSize
name|QSize
operator|::
name|boundedTo
argument_list|(
argument|const QSize& otherSize
argument_list|)
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|QSize
argument_list|(
name|qMin
argument_list|(
name|wd
argument_list|,
name|otherSize
operator|.
name|wd
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|ht
argument_list|,
name|otherSize
operator|.
name|ht
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QSize
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSizeF
block|{
name|public
label|:
name|Q_DECL_CONSTEXPR
name|QSizeF
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|QSizeF
argument_list|(
specifier|const
name|QSize
operator|&
name|sz
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|Q_DECL_CONSTEXPR
name|QSizeF
argument_list|(
name|qreal
name|w
argument_list|,
name|qreal
name|h
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|width
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|height
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|void
name|setWidth
argument_list|(
name|qreal
name|w
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|void
name|setHeight
argument_list|(
name|qreal
name|h
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|void
name|transpose
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSizeF
name|transposed
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
specifier|inline
name|void
name|scale
argument_list|(
name|qreal
name|w
argument_list|,
name|qreal
name|h
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
specifier|inline
name|void
name|scale
argument_list|(
specifier|const
name|QSizeF
operator|&
name|s
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|QSizeF
name|scaled
argument_list|(
name|qreal
name|w
argument_list|,
name|qreal
name|h
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
name|QSizeF
name|scaled
argument_list|(
specifier|const
name|QSizeF
operator|&
name|s
argument_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSizeF
name|expandedTo
argument_list|(
specifier|const
name|QSizeF
operator|&
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSizeF
name|boundedTo
argument_list|(
specifier|const
name|QSizeF
operator|&
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|qreal
operator|&
name|rwidth
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|qreal
operator|&
name|rheight
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSizeF
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QSizeF
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSizeF
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QSizeF
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSizeF
operator|&
name|operator
operator|*=
operator|(
name|qreal
name|c
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
specifier|inline
name|QSizeF
operator|&
name|operator
operator|/=
operator|(
name|qreal
name|c
operator|)
expr_stmt|;
name|friend
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSizeF
operator|&
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|friend
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSizeF
operator|&
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|friend
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|+
operator|(
specifier|const
name|QSizeF
operator|&
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|friend
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|-
operator|(
specifier|const
name|QSizeF
operator|&
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
name|Q_DECL_NOTHROW
expr_stmt|;
name|friend
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSizeF
name|operator
modifier|*
argument_list|(
specifier|const
name|QSizeF
operator|&
argument_list|,
name|qreal
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|friend
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSizeF
name|operator
modifier|*
argument_list|(
name|qreal
argument_list|,
specifier|const
name|QSizeF
operator|&
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|friend
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|/
operator|(
specifier|const
name|QSizeF
operator|&
operator|,
name|qreal
operator|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSize
name|toSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|private
label|:
name|qreal
name|wd
decl_stmt|;
name|qreal
name|ht
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QSizeF
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*****************************************************************************   QSizeF stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QSizeF
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QSizeF inline functions  *****************************************************************************/
end_comment
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSizeF
operator|::
name|QSizeF
argument_list|()
name|Q_DECL_NOTHROW
operator|:
name|wd
argument_list|(
operator|-
literal|1.
argument_list|)
operator|,
name|ht
argument_list|(
argument|-
literal|1.
argument_list|)
block|{}
DECL|function|ht
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSizeF
operator|::
name|QSizeF
argument_list|(
argument|const QSize&sz
argument_list|)
name|Q_DECL_NOTHROW
operator|:
name|wd
argument_list|(
name|sz
operator|.
name|width
argument_list|()
argument_list|)
operator|,
name|ht
argument_list|(
argument|sz.height()
argument_list|)
block|{}
DECL|function|ht
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSizeF
operator|::
name|QSizeF
argument_list|(
argument|qreal w
argument_list|,
argument|qreal h
argument_list|)
name|Q_DECL_NOTHROW
operator|:
name|wd
argument_list|(
name|w
argument_list|)
operator|,
name|ht
argument_list|(
argument|h
argument_list|)
block|{}
specifier|inline
name|bool
name|QSizeF
operator|::
name|isNull
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|qIsNull
argument_list|(
name|wd
argument_list|)
operator|&&
name|qIsNull
argument_list|(
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|QSizeF
operator|::
name|isEmpty
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|wd
operator|<=
literal|0.
operator|||
name|ht
operator|<=
literal|0.
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|QSizeF
operator|::
name|isValid
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|wd
operator|>=
literal|0.
operator|&&
name|ht
operator|>=
literal|0.
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|QSizeF
operator|::
name|width
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|wd
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|qreal
name|QSizeF
operator|::
name|height
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|void
name|QSizeF
operator|::
name|setWidth
argument_list|(
argument|qreal w
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|wd
operator|=
name|w
block|; }
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|void
name|QSizeF
operator|::
name|setHeight
argument_list|(
argument|qreal h
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|ht
operator|=
name|h
block|; }
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSizeF
name|QSizeF
operator|::
name|transposed
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|QSizeF
argument_list|(
name|ht
argument_list|,
name|wd
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|void
name|QSizeF
operator|::
name|scale
argument_list|(
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|Qt::AspectRatioMode mode
argument_list|)
name|Q_DECL_NOTHROW
block|{
name|scale
argument_list|(
name|QSizeF
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|)
block|; }
specifier|inline
name|void
name|QSizeF
operator|::
name|scale
argument_list|(
argument|const QSizeF&s
argument_list|,
argument|Qt::AspectRatioMode mode
argument_list|)
name|Q_DECL_NOTHROW
block|{
operator|*
name|this
operator|=
name|scaled
argument_list|(
name|s
argument_list|,
name|mode
argument_list|)
block|; }
specifier|inline
name|QSizeF
name|QSizeF
operator|::
name|scaled
argument_list|(
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|Qt::AspectRatioMode mode
argument_list|)
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|scaled
argument_list|(
name|QSizeF
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|qreal
operator|&
name|QSizeF
operator|::
name|rwidth
argument_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|wd
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|qreal
operator|&
name|QSizeF
operator|::
name|rheight
argument_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|ht
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|member|operator
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSizeF
operator|&
name|QSizeF
operator|::
name|operator
operator|+=
operator|(
specifier|const
name|QSizeF
operator|&
name|s
operator|)
name|Q_DECL_NOTHROW
block|{
name|wd
operator|+=
name|s
operator|.
name|wd
block|;
name|ht
operator|+=
name|s
operator|.
name|ht
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSizeF
operator|&
name|QSizeF
operator|::
name|operator
operator|-=
operator|(
specifier|const
name|QSizeF
operator|&
name|s
operator|)
name|Q_DECL_NOTHROW
block|{
name|wd
operator|-=
name|s
operator|.
name|wd
block|;
name|ht
operator|-=
name|s
operator|.
name|ht
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_RELAXED_CONSTEXPR
specifier|inline
name|QSizeF
operator|&
name|QSizeF
operator|::
name|operator
operator|*=
operator|(
name|qreal
name|c
operator|)
name|Q_DECL_NOTHROW
block|{
name|wd
operator|*=
name|c
block|;
name|ht
operator|*=
name|c
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSizeF
operator|&
name|s1
operator|,
specifier|const
name|QSizeF
operator|&
name|s2
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|qFuzzyCompare
argument_list|(
name|s1
operator|.
name|wd
argument_list|,
name|s2
operator|.
name|wd
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|s1
operator|.
name|ht
argument_list|,
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSizeF
operator|&
name|s1
operator|,
specifier|const
name|QSizeF
operator|&
name|s2
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
operator|!
name|qFuzzyCompare
argument_list|(
name|s1
operator|.
name|wd
argument_list|,
name|s2
operator|.
name|wd
argument_list|)
operator|||
operator|!
name|qFuzzyCompare
argument_list|(
name|s1
operator|.
name|ht
argument_list|,
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|+
operator|(
specifier|const
name|QSizeF
operator|&
name|s1
operator|,
specifier|const
name|QSizeF
operator|&
name|s2
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QSizeF
argument_list|(
name|s1
operator|.
name|wd
operator|+
name|s2
operator|.
name|wd
argument_list|,
name|s1
operator|.
name|ht
operator|+
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|-
operator|(
specifier|const
name|QSizeF
operator|&
name|s1
operator|,
specifier|const
name|QSizeF
operator|&
name|s2
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QSizeF
argument_list|(
name|s1
operator|.
name|wd
operator|-
name|s2
operator|.
name|wd
argument_list|,
name|s1
operator|.
name|ht
operator|-
name|s2
operator|.
name|ht
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSizeF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|s
parameter_list|,
name|qreal
name|c
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|QSizeF
argument_list|(
name|s
operator|.
name|wd
operator|*
name|c
argument_list|,
name|s
operator|.
name|ht
operator|*
name|c
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QSizeF
name|operator
modifier|*
parameter_list|(
name|qreal
name|c
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|s
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
name|QSizeF
argument_list|(
name|s
operator|.
name|wd
operator|*
name|c
argument_list|,
name|s
operator|.
name|ht
operator|*
name|c
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QSizeF
operator|&
name|QSizeF
operator|::
name|operator
operator|/=
operator|(
name|qreal
name|c
operator|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|c
argument_list|)
argument_list|)
block|;
name|wd
operator|=
name|wd
operator|/
name|c
block|;
name|ht
operator|=
name|ht
operator|/
name|c
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
specifier|const
name|QSizeF
name|operator
operator|/
operator|(
specifier|const
name|QSizeF
operator|&
name|s
operator|,
name|qreal
name|c
operator|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|c
argument_list|)
argument_list|)
block|;
return|return
name|QSizeF
argument_list|(
name|s
operator|.
name|wd
operator|/
name|c
argument_list|,
name|s
operator|.
name|ht
operator|/
name|c
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSizeF
name|QSizeF
operator|::
name|expandedTo
argument_list|(
argument|const QSizeF& otherSize
argument_list|)
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|QSizeF
argument_list|(
name|qMax
argument_list|(
name|wd
argument_list|,
name|otherSize
operator|.
name|wd
argument_list|)
argument_list|,
name|qMax
argument_list|(
name|ht
argument_list|,
name|otherSize
operator|.
name|ht
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSizeF
name|QSizeF
operator|::
name|boundedTo
argument_list|(
argument|const QSizeF& otherSize
argument_list|)
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|QSizeF
argument_list|(
name|qMin
argument_list|(
name|wd
argument_list|,
name|otherSize
operator|.
name|wd
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|ht
argument_list|,
name|otherSize
operator|.
name|ht
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QSize
name|QSizeF
operator|::
name|toSize
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|QSize
argument_list|(
name|qRound
argument_list|(
name|wd
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|ht
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QSizeF
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSIZE_H
end_comment
end_unit
