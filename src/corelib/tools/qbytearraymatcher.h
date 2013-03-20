begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBYTEARRAYMATCHER_H
end_ifndef
begin_define
DECL|macro|QBYTEARRAYMATCHER_H
define|#
directive|define
name|QBYTEARRAYMATCHER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QByteArrayMatcherPrivate
name|class
name|QByteArrayMatcherPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QByteArrayMatcher
block|{
name|public
label|:
name|QByteArrayMatcher
argument_list|()
expr_stmt|;
name|explicit
name|QByteArrayMatcher
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|pattern
parameter_list|)
function_decl|;
name|explicit
name|QByteArrayMatcher
parameter_list|(
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
name|QByteArrayMatcher
argument_list|(
specifier|const
name|QByteArrayMatcher
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QByteArrayMatcher
argument_list|()
expr_stmt|;
name|QByteArrayMatcher
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QByteArrayMatcher
operator|&
name|other
operator|)
decl_stmt|;
name|void
name|setPattern
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|pattern
parameter_list|)
function_decl|;
name|int
name|indexIn
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ba
argument_list|,
name|int
name|from
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|indexIn
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|,
name|int
name|len
argument_list|,
name|int
name|from
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|QByteArray
name|pattern
argument_list|()
specifier|const
block|{
if|if
condition|(
name|q_pattern
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|QByteArray
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|p
operator|.
name|p
operator|)
argument_list|,
name|p
operator|.
name|l
argument_list|)
return|;
return|return
name|q_pattern
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QByteArrayMatcherPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|q_pattern
decl_stmt|;
end_decl_stmt
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
name|uchar
modifier|*
name|p
decl_stmt|;
name|int
name|l
decl_stmt|;
block|}
struct|;
end_struct
begin_union
union|union
block|{
name|uint
name|dummy
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
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBYTEARRAYMATCHER_H
end_comment
end_unit
