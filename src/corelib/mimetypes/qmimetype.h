begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMIMETYPE_H
end_ifndef
begin_define
DECL|macro|QMIMETYPE_H
define|#
directive|define
name|QMIMETYPE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QMimeTypePrivate
name|class
name|QMimeTypePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileinfo
name|class
name|QFileinfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QMimeType
block|{
name|public
label|:
name|QMimeType
argument_list|()
expr_stmt|;
name|QMimeType
argument_list|(
specifier|const
name|QMimeType
operator|&
name|other
argument_list|)
expr_stmt|;
name|QMimeType
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QMimeType
operator|&
name|other
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QMimeType
modifier|&
name|operator
init|=
operator|(
name|QMimeType
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|void
name|swap
parameter_list|(
name|QMimeType
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|explicit
name|QMimeType
parameter_list|(
specifier|const
name|QMimeTypePrivate
modifier|&
name|dd
parameter_list|)
function_decl|;
operator|~
name|QMimeType
argument_list|()
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QMimeType
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QMimeType
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDefault
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|comment
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|genericIconName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|iconName
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|globPatterns
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|parentMimeTypes
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|allAncestors
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|suffixes
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|preferredSuffix
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|inherits
argument_list|(
specifier|const
name|QString
operator|&
name|mimeTypeName
argument_list|)
decl|const
decl_stmt|;
name|QString
name|filterString
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|QMimeTypeParserBase
decl_stmt|;
name|friend
name|class
name|MimeTypeMapEntry
decl_stmt|;
name|friend
name|class
name|QMimeDatabasePrivate
decl_stmt|;
name|friend
name|class
name|QMimeXMLProvider
decl_stmt|;
name|friend
name|class
name|QMimeBinaryProvider
decl_stmt|;
name|friend
name|class
name|QMimeTypePrivate
decl_stmt|;
name|QExplicitlySharedDataPointer
operator|<
name|QMimeTypePrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QMimeType
argument_list|)
end_macro
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMIMETYPE_H
end_comment
end_unit
