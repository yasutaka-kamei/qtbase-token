begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTRINGMATCHER_H
end_ifndef
begin_define
DECL|macro|QSTRINGMATCHER_H
define|#
directive|define
name|QSTRINGMATCHER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|QStringMatcherPrivate
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QStringMatcher
decl_stmt|{ public:     QStringMatcher(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_macro
name|QStringMatcher
argument_list|(
argument|const QString&pattern
argument_list|,
argument|Qt::CaseSensitivity cs = Qt::CaseSensitive
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QStringMatcher
argument_list|(
argument|const QChar *uc
argument_list|,
argument|int len
argument_list|,
argument|Qt::CaseSensitivity cs = Qt::CaseSensitive
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QStringMatcher
argument_list|(
specifier|const
name|QStringMatcher
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QStringMatcher
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QStringMatcher
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QStringMatcher
operator|&
name|other
operator|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setPattern
parameter_list|(
specifier|const
name|QString
modifier|&
name|pattern
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|setCaseSensitivity
argument_list|(
name|Qt
operator|::
name|CaseSensitivity
name|cs
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|indexIn
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|int
name|from
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|indexIn
argument_list|(
specifier|const
name|QChar
operator|*
name|str
argument_list|,
name|int
name|length
argument_list|,
name|int
name|from
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QString
name|pattern
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|Qt
operator|::
name|CaseSensitivity
name|caseSensitivity
argument_list|()
specifier|const
block|{
return|return
name|q_cs
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QStringMatcherPrivate
modifier|*
name|d_ptr
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|q_pattern
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|CaseSensitivity
name|q_cs
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_RVCT
end_ifdef
begin_comment
comment|// explicitly allow anonymous unions for RVCT to prevent compiler warnings
end_comment
begin_pragma
pragma|#
directive|pragma
name|push
end_pragma
begin_pragma
pragma|#
directive|pragma
name|anon_unions
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_struct
struct|struct
name|Data
block|{
name|uchar
name|q_skiptable
index|[
literal|256
index|]
decl_stmt|;
specifier|const
name|QChar
modifier|*
name|uc
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
struct|;
end_struct
begin_union
union|union
block|{
name|uint
name|q_data
index|[
literal|256
index|]
decl_stmt|;
name|Data
name|p
decl_stmt|;
block|}
union|;
end_union
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_RVCT
end_ifdef
begin_pragma
pragma|#
directive|pragma
name|pop
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTRINGMATCHER_H
end_comment
end_unit
