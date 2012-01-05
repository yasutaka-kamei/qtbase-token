begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTLIST_H
end_ifndef
begin_define
DECL|macro|QTEXTLIST_H
define|#
directive|define
name|QTEXTLIST_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qtextobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QTextListPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCursor
name|class
name|QTextCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextList
range|:
name|public
name|QTextBlockGroup
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QTextList
argument_list|(
name|QTextDocument
operator|*
name|doc
argument_list|)
block|;
operator|~
name|QTextList
argument_list|()
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|count
argument_list|()
operator|==
literal|0
return|;
block|}
name|QTextBlock
name|item
argument_list|(
argument|int i
argument_list|)
specifier|const
block|;
name|int
name|itemNumber
argument_list|(
argument|const QTextBlock&
argument_list|)
specifier|const
block|;
name|QString
name|itemText
argument_list|(
argument|const QTextBlock&
argument_list|)
specifier|const
block|;
name|void
name|removeItem
argument_list|(
argument|int i
argument_list|)
block|;
name|void
name|remove
argument_list|(
specifier|const
name|QTextBlock
operator|&
argument_list|)
block|;
name|void
name|add
argument_list|(
specifier|const
name|QTextBlock
operator|&
name|block
argument_list|)
block|;
specifier|inline
name|void
name|setFormat
argument_list|(
specifier|const
name|QTextListFormat
operator|&
name|format
argument_list|)
block|;
name|QTextListFormat
name|format
argument_list|()
specifier|const
block|{
return|return
name|QTextObject
operator|::
name|format
argument_list|()
operator|.
name|toListFormat
argument_list|()
return|;
block|}
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTextList
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTextList
argument_list|)
expr|}
block|;
DECL|function|setFormat
specifier|inline
name|void
name|QTextList
operator|::
name|setFormat
argument_list|(
argument|const QTextListFormat&aformat
argument_list|)
block|{
name|QTextObject
operator|::
name|setFormat
argument_list|(
name|aformat
argument_list|)
block|; }
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEXTLIST_H
end_comment
end_unit
