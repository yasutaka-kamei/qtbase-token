begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMARGINS_H
end_ifndef
begin_define
DECL|macro|QMARGINS_H
define|#
directive|define
name|QMARGINS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|QMargins
block|{
name|public
label|:
name|Q_DECL_CONSTEXPR
name|QMargins
parameter_list|()
function_decl|;
name|Q_DECL_CONSTEXPR
name|QMargins
parameter_list|(
name|int
name|left
parameter_list|,
name|int
name|top
parameter_list|,
name|int
name|right
parameter_list|,
name|int
name|bottom
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|int
name|left
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|int
name|top
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|int
name|right
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|int
name|bottom
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLeft
parameter_list|(
name|int
name|left
parameter_list|)
function_decl|;
name|void
name|setTop
parameter_list|(
name|int
name|top
parameter_list|)
function_decl|;
name|void
name|setRight
parameter_list|(
name|int
name|right
parameter_list|)
function_decl|;
name|void
name|setBottom
parameter_list|(
name|int
name|bottom
parameter_list|)
function_decl|;
name|private
label|:
name|int
name|m_left
decl_stmt|;
name|int
name|m_top
decl_stmt|;
name|int
name|m_right
decl_stmt|;
name|int
name|m_bottom
decl_stmt|;
name|friend
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QMargins
operator|&
operator|,
specifier|const
name|QMargins
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QMargins
operator|&
operator|,
specifier|const
name|QMargins
operator|&
operator|)
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QMargins
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*****************************************************************************   QMargins stream functions  *****************************************************************************/
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
name|QMargins
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
name|QMargins
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*****************************************************************************   QMargins inline functions  *****************************************************************************/
end_comment
begin_expr_stmt
DECL|function|QMargins
name|Q_DECL_CONSTEXPR
specifier|inline
name|QMargins
operator|::
name|QMargins
argument_list|()
operator|:
name|m_left
argument_list|(
literal|0
argument_list|)
operator|,
name|m_top
argument_list|(
literal|0
argument_list|)
operator|,
name|m_right
argument_list|(
literal|0
argument_list|)
operator|,
name|m_bottom
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|QMargins
name|Q_DECL_CONSTEXPR
specifier|inline
name|QMargins
operator|::
name|QMargins
argument_list|(
argument|int aleft
argument_list|,
argument|int atop
argument_list|,
argument|int aright
argument_list|,
argument|int abottom
argument_list|)
operator|:
name|m_left
argument_list|(
name|aleft
argument_list|)
operator|,
name|m_top
argument_list|(
name|atop
argument_list|)
operator|,
name|m_right
argument_list|(
name|aright
argument_list|)
operator|,
name|m_bottom
argument_list|(
argument|abottom
argument_list|)
block|{}
DECL|function|isNull
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|QMargins
operator|::
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|m_left
operator|==
literal|0
operator|&&
name|m_top
operator|==
literal|0
operator|&&
name|m_right
operator|==
literal|0
operator|&&
name|m_bottom
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|left
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QMargins
operator|::
name|left
argument_list|()
specifier|const
block|{
return|return
name|m_left
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|top
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QMargins
operator|::
name|top
argument_list|()
specifier|const
block|{
return|return
name|m_top
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|right
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QMargins
operator|::
name|right
argument_list|()
specifier|const
block|{
return|return
name|m_right
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|bottom
name|Q_DECL_CONSTEXPR
specifier|inline
name|int
name|QMargins
operator|::
name|bottom
argument_list|()
specifier|const
block|{
return|return
name|m_bottom
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setLeft
specifier|inline
name|void
name|QMargins
operator|::
name|setLeft
argument_list|(
argument|int aleft
argument_list|)
block|{
name|m_left
operator|=
name|aleft
block|; }
DECL|function|setTop
specifier|inline
name|void
name|QMargins
operator|::
name|setTop
argument_list|(
argument|int atop
argument_list|)
block|{
name|m_top
operator|=
name|atop
block|; }
DECL|function|setRight
specifier|inline
name|void
name|QMargins
operator|::
name|setRight
argument_list|(
argument|int aright
argument_list|)
block|{
name|m_right
operator|=
name|aright
block|; }
DECL|function|setBottom
specifier|inline
name|void
name|QMargins
operator|::
name|setBottom
argument_list|(
argument|int abottom
argument_list|)
block|{
name|m_bottom
operator|=
name|abottom
block|; }
DECL|function|operator
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QMargins
operator|&
name|m1
operator|,
specifier|const
name|QMargins
operator|&
name|m2
operator|)
block|{
return|return
name|m1
operator|.
name|m_left
operator|==
name|m2
operator|.
name|m_left
operator|&&
name|m1
operator|.
name|m_top
operator|==
name|m2
operator|.
name|m_top
operator|&&
name|m1
operator|.
name|m_right
operator|==
name|m2
operator|.
name|m_right
operator|&&
name|m1
operator|.
name|m_bottom
operator|==
name|m2
operator|.
name|m_bottom
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QMargins
operator|&
name|m1
operator|,
specifier|const
name|QMargins
operator|&
name|m2
operator|)
block|{
return|return
name|m1
operator|.
name|m_left
operator|!=
name|m2
operator|.
name|m_left
operator|||
name|m1
operator|.
name|m_top
operator|!=
name|m2
operator|.
name|m_top
operator|||
name|m1
operator|.
name|m_right
operator|!=
name|m2
operator|.
name|m_right
operator|||
name|m1
operator|.
name|m_bottom
operator|!=
name|m2
operator|.
name|m_bottom
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
name|QMargins
operator|&
operator|)
expr_stmt|;
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
comment|// QMARGINS_H
end_comment
end_unit
