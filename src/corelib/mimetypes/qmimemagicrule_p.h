begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMIMEMAGICRULE_P_H
end_ifndef
begin_define
DECL|macro|QMIMEMAGICRULE_P_H
define|#
directive|define
name|QMIMEMAGICRULE_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMimeMagicRulePrivate
name|class
name|QMimeMagicRulePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMimeMagicRule
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|Invalid
init|=
literal|0
block|,
name|String
block|,
name|Host16
block|,
name|Host32
block|,
name|Big16
block|,
name|Big32
block|,
name|Little16
block|,
name|Little32
block|,
name|Byte
block|}
enum|;
name|QMimeMagicRule
argument_list|(
argument|Type type
argument_list|,
argument|const QByteArray&value
argument_list|,
argument|int startPos
argument_list|,
argument|int endPos
argument_list|,
argument|const QByteArray&mask = QByteArray()
argument_list|)
empty_stmt|;
name|QMimeMagicRule
argument_list|(
specifier|const
name|QMimeMagicRule
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QMimeMagicRule
argument_list|()
expr_stmt|;
name|QMimeMagicRule
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QMimeMagicRule
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QMimeMagicRule
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|value
argument_list|()
specifier|const
expr_stmt|;
name|int
name|startPos
argument_list|()
specifier|const
expr_stmt|;
name|int
name|endPos
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|mask
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|matches
argument_list|(
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QMimeMagicRule
operator|>
name|m_subMatches
expr_stmt|;
specifier|static
name|Type
name|type
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|type
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|typeName
parameter_list|(
name|Type
name|type
parameter_list|)
function_decl|;
specifier|static
name|bool
name|matchSubstring
parameter_list|(
specifier|const
name|char
modifier|*
name|dataPtr
parameter_list|,
name|int
name|dataSize
parameter_list|,
name|int
name|rangeStart
parameter_list|,
name|int
name|rangeLength
parameter_list|,
name|int
name|valueLength
parameter_list|,
specifier|const
name|char
modifier|*
name|valueData
parameter_list|,
specifier|const
name|char
modifier|*
name|mask
parameter_list|)
function_decl|;
name|private
label|:
specifier|const
name|QScopedPointer
operator|<
name|QMimeMagicRulePrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMIMEMAGICRULE_H
end_comment
end_unit
