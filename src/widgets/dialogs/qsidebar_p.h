begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIDEBAR_H
end_ifndef
begin_define
DECL|macro|QSIDEBAR_H
define|#
directive|define
name|QSIDEBAR_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qlistwidget.h>
end_include
begin_include
include|#
directive|include
file|<qstandarditemmodel.h>
end_include
begin_include
include|#
directive|include
file|<qstyleditemdelegate.h>
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILEDIALOG
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFileSystemModel
name|class
name|QFileSystemModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSideBarDelegate
range|:
name|public
name|QStyledItemDelegate
block|{
name|public
operator|:
name|QSideBarDelegate
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QStyledItemDelegate
argument_list|(
argument|parent
argument_list|)
block|{}
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionViewItem *option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QUrlModel
range|:
name|public
name|QStandardItemModel
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Roles
block|{
name|UrlRole
operator|=
name|Qt
operator|::
name|UserRole
operator|+
literal|1
block|,
name|EnabledRole
operator|=
name|Qt
operator|::
name|UserRole
operator|+
literal|2
block|}
block|;
name|QUrlModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QStringList
name|mimeTypes
argument_list|()
specifier|const
block|;
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|const QModelIndexList&indexes
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|bool
name|canDrop
argument_list|(
name|QDragEnterEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|dropMimeData
argument_list|(
argument|const QMimeData *data
argument_list|,
argument|Qt::DropAction action
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&parent
argument_list|)
block|;
endif|#
directive|endif
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|bool
name|setData
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role=Qt::EditRole
argument_list|)
block|;
name|void
name|setUrls
argument_list|(
specifier|const
name|QList
operator|<
name|QUrl
operator|>
operator|&
name|list
argument_list|)
block|;
name|void
name|addUrls
argument_list|(
argument|const QList<QUrl>&urls
argument_list|,
argument|int row = -
literal|1
argument_list|,
argument|bool move = true
argument_list|)
block|;
name|QList
operator|<
name|QUrl
operator|>
name|urls
argument_list|()
specifier|const
block|;
name|void
name|setFileSystemModel
argument_list|(
name|QFileSystemModel
operator|*
name|model
argument_list|)
block|;
name|bool
name|showFullPath
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|dataChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|topLeft
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|bottomRight
argument_list|)
block|;
name|void
name|layoutChanged
argument_list|()
block|;
name|private
operator|:
name|void
name|setUrl
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|,
specifier|const
name|QUrl
operator|&
name|url
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|dirIndex
argument_list|)
block|;
name|void
name|changed
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|addIndexToWatch
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|QFileSystemModel
operator|*
name|fileSystemModel
block|;
name|QList
operator|<
name|QPair
operator|<
name|QModelIndex
block|,
name|QString
operator|>
expr|>
name|watching
block|;
name|QList
operator|<
name|QUrl
operator|>
name|invalidUrls
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QSidebar
range|:
name|public
name|QListView
block|{
name|Q_OBJECT
name|Q_SIGNALS
operator|:
name|void
name|goToUrl
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
block|;
name|public
operator|:
name|QSidebar
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setModelAndUrls
argument_list|(
name|QFileSystemModel
operator|*
name|model
argument_list|,
specifier|const
name|QList
operator|<
name|QUrl
operator|>
operator|&
name|newUrls
argument_list|)
block|;
operator|~
name|QSidebar
argument_list|()
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|void
name|setUrls
argument_list|(
argument|const QList<QUrl>&list
argument_list|)
block|{
name|urlModel
operator|->
name|setUrls
argument_list|(
name|list
argument_list|)
block|; }
name|void
name|addUrls
argument_list|(
argument|const QList<QUrl>&list
argument_list|,
argument|int row
argument_list|)
block|{
name|urlModel
operator|->
name|addUrls
argument_list|(
name|list
argument_list|,
name|row
argument_list|)
block|; }
name|QList
operator|<
name|QUrl
operator|>
name|urls
argument_list|()
specifier|const
block|{
return|return
name|urlModel
operator|->
name|urls
argument_list|()
return|;
block|}
name|void
name|selectUrl
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|void
name|dragEnterEvent
argument_list|(
name|QDragEnterEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|private
name|Q_SLOTS
operator|:
name|void
name|clicked
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|void
name|showContextMenu
argument_list|(
specifier|const
name|QPoint
operator|&
name|position
argument_list|)
block|;
endif|#
directive|endif
name|void
name|removeEntry
argument_list|()
block|;
name|private
operator|:
name|QUrlModel
operator|*
name|urlModel
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FILEDIALOG
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSIDEBAR_H
end_comment
end_unit
