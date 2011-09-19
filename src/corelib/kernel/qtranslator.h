begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTRANSLATOR_H
end_ifndef
begin_define
DECL|macro|QTRANSLATOR_H
define|#
directive|define
name|QTRANSLATOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
name|class
name|QLocale
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTranslatorPrivate
name|class
name|QTranslatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTranslator
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QTranslator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QTranslator
argument_list|()
block|;
name|virtual
name|QString
name|translate
argument_list|(
argument|const char *context
argument_list|,
argument|const char *sourceText
argument_list|,
argument|const char *disambiguation =
literal|0
argument_list|,
argument|int n = -
literal|1
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isEmpty
argument_list|()
specifier|const
block|;
name|bool
name|load
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|,
specifier|const
name|QString
operator|&
name|directory
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|search_delimiters
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|suffix
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|bool
name|load
argument_list|(
specifier|const
name|QLocale
operator|&
name|locale
argument_list|,
specifier|const
name|QString
operator|&
name|filename
argument_list|,
specifier|const
name|QString
operator|&
name|prefix
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|directory
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|suffix
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|bool
name|load
argument_list|(
argument|const uchar *data
argument_list|,
argument|int len
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTranslator
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTranslator
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TRANSLATION
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTRANSLATOR_H
end_comment
end_unit
