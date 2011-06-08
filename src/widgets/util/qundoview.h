begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUNDOVIEW_H
end_ifndef
begin_define
DECL|macro|QUNDOVIEW_H
define|#
directive|define
name|QUNDOVIEW_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qlistview.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UNDOVIEW
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QUndoViewPrivate
name|class
name|QUndoViewPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUndoStack
name|class
name|QUndoStack
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUndoGroup
name|class
name|QUndoGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIcon
name|class
name|QIcon
decl_stmt|;
end_decl_stmt
begin_macro
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
argument|Gui
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QUndoView
range|:
name|public
name|QListView
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QUndoView
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString emptyLabel READ emptyLabel WRITE setEmptyLabel
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QIcon cleanIcon READ cleanIcon WRITE setCleanIcon
argument_list|)
name|public
operator|:
name|explicit
name|QUndoView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QUndoView
argument_list|(
name|QUndoStack
operator|*
name|stack
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
name|explicit
name|QUndoView
argument_list|(
name|QUndoGroup
operator|*
name|group
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
endif|#
directive|endif
operator|~
name|QUndoView
argument_list|()
block|;
name|QUndoStack
operator|*
name|stack
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
name|QUndoGroup
operator|*
name|group
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|setEmptyLabel
argument_list|(
specifier|const
name|QString
operator|&
name|label
argument_list|)
block|;
name|QString
name|emptyLabel
argument_list|()
specifier|const
block|;
name|void
name|setCleanIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
name|QIcon
name|cleanIcon
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setStack
argument_list|(
name|QUndoStack
operator|*
name|stack
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_UNDOGROUP
name|void
name|setGroup
argument_list|(
name|QUndoGroup
operator|*
name|group
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QUndoView
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_UNDOVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QUNDOVIEW_H
end_comment
end_unit
