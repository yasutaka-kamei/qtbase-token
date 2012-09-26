begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTANDARDITEMMODEL_H
end_ifndef
begin_define
DECL|macro|QSTANDARDITEMMODEL_H
define|#
directive|define
name|QSTANDARDITEMMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qbrush.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qicon.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STANDARDITEMMODEL
DECL|variable|QList
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QStandardItemModel
name|class
name|QStandardItemModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStandardItemPrivate
name|class
name|QStandardItemPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QStandardItem
block|{
name|public
label|:
name|QStandardItem
argument_list|()
expr_stmt|;
name|explicit
name|QStandardItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|QStandardItem
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
expr_stmt|;
name|explicit
name|QStandardItem
parameter_list|(
name|int
name|rows
parameter_list|,
name|int
name|columns
init|=
literal|1
parameter_list|)
function_decl|;
name|virtual
operator|~
name|QStandardItem
argument_list|()
expr_stmt|;
name|virtual
name|QVariant
name|data
argument_list|(
name|int
name|role
operator|=
name|Qt
operator|::
name|UserRole
operator|+
literal|1
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|setData
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|,
name|int
name|role
init|=
name|Qt
operator|::
name|UserRole
operator|+
literal|1
parameter_list|)
function_decl|;
specifier|inline
name|QString
name|text
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QString
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
specifier|inline
name|QIcon
name|icon
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QIcon
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|DecorationRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
specifier|inline
name|QString
name|toolTip
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QString
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|ToolTipRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setToolTip
parameter_list|(
specifier|const
name|QString
modifier|&
name|toolTip
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STATUSTIP
specifier|inline
name|QString
name|statusTip
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QString
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|StatusTipRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setStatusTip
parameter_list|(
specifier|const
name|QString
modifier|&
name|statusTip
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
specifier|inline
name|QString
name|whatsThis
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QString
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|WhatsThisRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setWhatsThis
parameter_list|(
specifier|const
name|QString
modifier|&
name|whatsThis
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|inline
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QSize
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|SizeHintRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setSizeHint
parameter_list|(
specifier|const
name|QSize
modifier|&
name|sizeHint
parameter_list|)
function_decl|;
specifier|inline
name|QFont
name|font
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QFont
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|FontRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
function_decl|;
specifier|inline
name|Qt
operator|::
name|Alignment
name|textAlignment
argument_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|Alignment
argument_list|(
name|qvariant_cast
operator|<
name|int
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|TextAlignmentRole
argument_list|)
operator|)
argument_list|)
return|;
block|}
specifier|inline
name|void
name|setTextAlignment
argument_list|(
name|Qt
operator|::
name|Alignment
name|textAlignment
argument_list|)
decl_stmt|;
specifier|inline
name|QBrush
name|background
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QBrush
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|BackgroundRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setBackground
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
function_decl|;
specifier|inline
name|QBrush
name|foreground
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QBrush
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|ForegroundRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setForeground
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
function_decl|;
specifier|inline
name|Qt
operator|::
name|CheckState
name|checkState
argument_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|CheckState
argument_list|(
name|qvariant_cast
operator|<
name|int
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|CheckStateRole
argument_list|)
operator|)
argument_list|)
return|;
block|}
specifier|inline
name|void
name|setCheckState
argument_list|(
name|Qt
operator|::
name|CheckState
name|checkState
argument_list|)
decl_stmt|;
specifier|inline
name|QString
name|accessibleText
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QString
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|AccessibleTextRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setAccessibleText
parameter_list|(
specifier|const
name|QString
modifier|&
name|accessibleText
parameter_list|)
function_decl|;
specifier|inline
name|QString
name|accessibleDescription
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QString
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|AccessibleDescriptionRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setAccessibleDescription
parameter_list|(
specifier|const
name|QString
modifier|&
name|accessibleDescription
parameter_list|)
function_decl|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFlags
argument_list|(
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|)
decl_stmt|;
specifier|inline
name|bool
name|isEnabled
argument_list|()
specifier|const
block|{
return|return
operator|(
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|ItemIsEnabled
operator|)
operator|!=
literal|0
return|;
block|}
name|void
name|setEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isEditable
argument_list|()
specifier|const
block|{
return|return
operator|(
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|ItemIsEditable
operator|)
operator|!=
literal|0
return|;
block|}
name|void
name|setEditable
parameter_list|(
name|bool
name|editable
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isSelectable
argument_list|()
specifier|const
block|{
return|return
operator|(
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|ItemIsSelectable
operator|)
operator|!=
literal|0
return|;
block|}
name|void
name|setSelectable
parameter_list|(
name|bool
name|selectable
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isCheckable
argument_list|()
specifier|const
block|{
return|return
operator|(
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|ItemIsUserCheckable
operator|)
operator|!=
literal|0
return|;
block|}
name|void
name|setCheckable
parameter_list|(
name|bool
name|checkable
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isTristate
argument_list|()
specifier|const
block|{
return|return
operator|(
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|ItemIsTristate
operator|)
operator|!=
literal|0
return|;
block|}
name|void
name|setTristate
parameter_list|(
name|bool
name|tristate
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
specifier|inline
name|bool
name|isDragEnabled
argument_list|()
specifier|const
block|{
return|return
operator|(
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|ItemIsDragEnabled
operator|)
operator|!=
literal|0
return|;
block|}
name|void
name|setDragEnabled
parameter_list|(
name|bool
name|dragEnabled
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isDropEnabled
argument_list|()
specifier|const
block|{
return|return
operator|(
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|ItemIsDropEnabled
operator|)
operator|!=
literal|0
return|;
block|}
name|void
name|setDropEnabled
parameter_list|(
name|bool
name|dropEnabled
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// QT_NO_DRAGANDDROP
name|QStandardItem
operator|*
name|parent
argument_list|()
specifier|const
expr_stmt|;
name|int
name|row
argument_list|()
specifier|const
expr_stmt|;
name|int
name|column
argument_list|()
specifier|const
expr_stmt|;
name|QModelIndex
name|index
argument_list|()
specifier|const
expr_stmt|;
name|QStandardItemModel
operator|*
name|model
argument_list|()
specifier|const
expr_stmt|;
name|int
name|rowCount
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRowCount
parameter_list|(
name|int
name|rows
parameter_list|)
function_decl|;
name|int
name|columnCount
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setColumnCount
parameter_list|(
name|int
name|columns
parameter_list|)
function_decl|;
name|bool
name|hasChildren
argument_list|()
specifier|const
expr_stmt|;
name|QStandardItem
modifier|*
name|child
argument_list|(
name|int
name|row
argument_list|,
name|int
name|column
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|setChild
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
name|QStandardItem
modifier|*
name|item
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setChild
parameter_list|(
name|int
name|row
parameter_list|,
name|QStandardItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
name|insertRow
argument_list|(
name|int
name|row
argument_list|,
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
decl_stmt|;
name|void
name|insertColumn
argument_list|(
name|int
name|column
argument_list|,
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
decl_stmt|;
name|void
name|insertRows
argument_list|(
name|int
name|row
argument_list|,
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
decl_stmt|;
name|void
name|insertRows
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|void
name|insertColumns
parameter_list|(
name|int
name|column
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|void
name|removeRow
parameter_list|(
name|int
name|row
parameter_list|)
function_decl|;
name|void
name|removeColumn
parameter_list|(
name|int
name|column
parameter_list|)
function_decl|;
name|void
name|removeRows
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|void
name|removeColumns
parameter_list|(
name|int
name|column
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
specifier|inline
name|void
name|appendRow
argument_list|(
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|appendRows
argument_list|(
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|appendColumn
argument_list|(
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|insertRow
parameter_list|(
name|int
name|row
parameter_list|,
name|QStandardItem
modifier|*
name|item
parameter_list|)
function_decl|;
specifier|inline
name|void
name|appendRow
parameter_list|(
name|QStandardItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|QStandardItem
modifier|*
name|takeChild
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
init|=
literal|0
parameter_list|)
function_decl|;
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
name|takeRow
argument_list|(
argument|int row
argument_list|)
expr_stmt|;
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
name|takeColumn
argument_list|(
argument|int column
argument_list|)
expr_stmt|;
name|void
name|sortChildren
argument_list|(
name|int
name|column
argument_list|,
name|Qt
operator|::
name|SortOrder
name|order
operator|=
name|Qt
operator|::
name|AscendingOrder
argument_list|)
decl_stmt|;
name|virtual
name|QStandardItem
operator|*
name|clone
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|ItemType
block|{
name|Type
init|=
literal|0
block|,
name|UserType
init|=
literal|1000
block|}
enum|;
name|virtual
name|int
name|type
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|virtual
name|void
name|read
parameter_list|(
name|QDataStream
modifier|&
name|in
parameter_list|)
function_decl|;
name|virtual
name|void
name|write
argument_list|(
name|QDataStream
operator|&
name|out
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|virtual
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QStandardItem
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|protected
label|:
name|QStandardItem
argument_list|(
specifier|const
name|QStandardItem
operator|&
name|other
argument_list|)
expr_stmt|;
name|QStandardItem
argument_list|(
name|QStandardItemPrivate
operator|&
name|dd
argument_list|)
expr_stmt|;
name|QStandardItem
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QStandardItem
operator|&
name|other
operator|)
decl_stmt|;
name|QScopedPointer
operator|<
name|QStandardItemPrivate
operator|>
name|d_ptr
expr_stmt|;
name|void
name|emitDataChanged
parameter_list|()
function_decl|;
name|private
label|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QStandardItem
argument_list|)
name|friend
name|class
name|QStandardItemModelPrivate
decl_stmt|;
name|friend
name|class
name|QStandardItemModel
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|setText
specifier|inline
name|void
name|QStandardItem
operator|::
name|setText
argument_list|(
argument|const QString&atext
argument_list|)
block|{
name|setData
argument_list|(
name|atext
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
block|; }
DECL|function|setIcon
specifier|inline
name|void
name|QStandardItem
operator|::
name|setIcon
argument_list|(
argument|const QIcon&aicon
argument_list|)
block|{
name|setData
argument_list|(
name|aicon
argument_list|,
name|Qt
operator|::
name|DecorationRole
argument_list|)
block|; }
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
DECL|function|setToolTip
specifier|inline
name|void
name|QStandardItem
operator|::
name|setToolTip
argument_list|(
argument|const QString&atoolTip
argument_list|)
block|{
name|setData
argument_list|(
name|atoolTip
argument_list|,
name|Qt
operator|::
name|ToolTipRole
argument_list|)
block|; }
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STATUSTIP
DECL|function|setStatusTip
specifier|inline
name|void
name|QStandardItem
operator|::
name|setStatusTip
argument_list|(
argument|const QString&astatusTip
argument_list|)
block|{
name|setData
argument_list|(
name|astatusTip
argument_list|,
name|Qt
operator|::
name|StatusTipRole
argument_list|)
block|; }
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
DECL|function|setWhatsThis
specifier|inline
name|void
name|QStandardItem
operator|::
name|setWhatsThis
argument_list|(
argument|const QString&awhatsThis
argument_list|)
block|{
name|setData
argument_list|(
name|awhatsThis
argument_list|,
name|Qt
operator|::
name|WhatsThisRole
argument_list|)
block|; }
endif|#
directive|endif
DECL|function|setSizeHint
specifier|inline
name|void
name|QStandardItem
operator|::
name|setSizeHint
argument_list|(
argument|const QSize&asizeHint
argument_list|)
block|{
name|setData
argument_list|(
name|asizeHint
argument_list|,
name|Qt
operator|::
name|SizeHintRole
argument_list|)
block|; }
DECL|function|setFont
specifier|inline
name|void
name|QStandardItem
operator|::
name|setFont
argument_list|(
argument|const QFont&afont
argument_list|)
block|{
name|setData
argument_list|(
name|afont
argument_list|,
name|Qt
operator|::
name|FontRole
argument_list|)
block|; }
DECL|function|setTextAlignment
specifier|inline
name|void
name|QStandardItem
operator|::
name|setTextAlignment
argument_list|(
argument|Qt::Alignment atextAlignment
argument_list|)
block|{
name|setData
argument_list|(
name|int
argument_list|(
name|atextAlignment
argument_list|)
argument_list|,
name|Qt
operator|::
name|TextAlignmentRole
argument_list|)
block|; }
DECL|function|setBackground
specifier|inline
name|void
name|QStandardItem
operator|::
name|setBackground
argument_list|(
argument|const QBrush&abrush
argument_list|)
block|{
name|setData
argument_list|(
name|abrush
argument_list|,
name|Qt
operator|::
name|BackgroundRole
argument_list|)
block|; }
DECL|function|setForeground
specifier|inline
name|void
name|QStandardItem
operator|::
name|setForeground
argument_list|(
argument|const QBrush&abrush
argument_list|)
block|{
name|setData
argument_list|(
name|abrush
argument_list|,
name|Qt
operator|::
name|ForegroundRole
argument_list|)
block|; }
DECL|function|setCheckState
specifier|inline
name|void
name|QStandardItem
operator|::
name|setCheckState
argument_list|(
argument|Qt::CheckState acheckState
argument_list|)
block|{
name|setData
argument_list|(
name|acheckState
argument_list|,
name|Qt
operator|::
name|CheckStateRole
argument_list|)
block|; }
DECL|function|setAccessibleText
specifier|inline
name|void
name|QStandardItem
operator|::
name|setAccessibleText
argument_list|(
argument|const QString&aaccessibleText
argument_list|)
block|{
name|setData
argument_list|(
name|aaccessibleText
argument_list|,
name|Qt
operator|::
name|AccessibleTextRole
argument_list|)
block|; }
DECL|function|setAccessibleDescription
specifier|inline
name|void
name|QStandardItem
operator|::
name|setAccessibleDescription
argument_list|(
argument|const QString&aaccessibleDescription
argument_list|)
block|{
name|setData
argument_list|(
name|aaccessibleDescription
argument_list|,
name|Qt
operator|::
name|AccessibleDescriptionRole
argument_list|)
block|; }
DECL|function|setChild
specifier|inline
name|void
name|QStandardItem
operator|::
name|setChild
argument_list|(
argument|int arow
argument_list|,
argument|QStandardItem *aitem
argument_list|)
block|{
name|setChild
argument_list|(
name|arow
argument_list|,
literal|0
argument_list|,
name|aitem
argument_list|)
block|; }
specifier|inline
name|void
name|QStandardItem
operator|::
name|appendRow
argument_list|(
argument|const QList<QStandardItem*>&aitems
argument_list|)
block|{
name|insertRow
argument_list|(
name|rowCount
argument_list|()
argument_list|,
name|aitems
argument_list|)
block|; }
specifier|inline
name|void
name|QStandardItem
operator|::
name|appendRows
argument_list|(
argument|const QList<QStandardItem*>&aitems
argument_list|)
block|{
name|insertRows
argument_list|(
name|rowCount
argument_list|()
argument_list|,
name|aitems
argument_list|)
block|; }
specifier|inline
name|void
name|QStandardItem
operator|::
name|appendColumn
argument_list|(
argument|const QList<QStandardItem*>&aitems
argument_list|)
block|{
name|insertColumn
argument_list|(
name|columnCount
argument_list|()
argument_list|,
name|aitems
argument_list|)
block|; }
DECL|function|insertRow
specifier|inline
name|void
name|QStandardItem
operator|::
name|insertRow
argument_list|(
argument|int arow
argument_list|,
argument|QStandardItem *aitem
argument_list|)
block|{
name|insertRow
argument_list|(
name|arow
argument_list|,
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|(
operator|)
operator|<<
name|aitem
argument_list|)
block|; }
DECL|function|appendRow
specifier|inline
name|void
name|QStandardItem
operator|::
name|appendRow
argument_list|(
argument|QStandardItem *aitem
argument_list|)
block|{
name|insertRow
argument_list|(
name|rowCount
argument_list|()
argument_list|,
name|aitem
argument_list|)
block|; }
DECL|variable|QStandardItemModelPrivate
name|class
name|QStandardItemModelPrivate
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QStandardItemModel
range|:
name|public
name|QAbstractItemModel
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int sortRole READ sortRole WRITE setSortRole
argument_list|)
name|public
operator|:
name|explicit
name|QStandardItemModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QStandardItemModel
argument_list|(
argument|int rows
argument_list|,
argument|int columns
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
operator|~
name|QStandardItemModel
argument_list|()
block|;
name|void
name|setItemRoleNames
argument_list|(
specifier|const
name|QHash
operator|<
name|int
argument_list|,
name|QByteArray
operator|>
operator|&
name|roleNames
argument_list|)
block|;
name|QModelIndex
name|index
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex&child
argument_list|)
specifier|const
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|bool
name|hasChildren
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QModelIndex
name|sibling
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&idx
argument_list|)
specifier|const
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role = Qt::DisplayRole
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
argument|int role = Qt::EditRole
argument_list|)
block|;
name|QVariant
name|headerData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
block|;
name|bool
name|setHeaderData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role = Qt::EditRole
argument_list|)
block|;
name|bool
name|insertRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|bool
name|insertColumns
argument_list|(
argument|int column
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|bool
name|removeRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|bool
name|removeColumns
argument_list|(
argument|int column
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|Qt
operator|::
name|DropActions
name|supportedDropActions
argument_list|()
specifier|const
block|;
name|QMap
operator|<
name|int
block|,
name|QVariant
operator|>
name|itemData
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|bool
name|setItemData
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|,
specifier|const
name|QMap
operator|<
name|int
argument_list|,
name|QVariant
operator|>
operator|&
name|roles
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
specifier|inline
name|QObject
operator|*
name|parent
argument_list|()
specifier|const
block|{
return|return
name|QObject
operator|::
name|parent
argument_list|()
return|;
block|}
else|#
directive|else
name|using
name|QObject
operator|::
name|parent
block|;
endif|#
directive|endif
name|void
name|sort
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order = Qt::AscendingOrder
argument_list|)
block|;
name|QStandardItem
operator|*
name|itemFromIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QModelIndex
name|indexFromItem
argument_list|(
argument|const QStandardItem *item
argument_list|)
specifier|const
block|;
name|QStandardItem
operator|*
name|item
argument_list|(
argument|int row
argument_list|,
argument|int column =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|setItem
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|QStandardItem *item
argument_list|)
block|;
specifier|inline
name|void
name|setItem
argument_list|(
argument|int row
argument_list|,
argument|QStandardItem *item
argument_list|)
block|;
name|QStandardItem
operator|*
name|invisibleRootItem
argument_list|()
specifier|const
block|;
name|QStandardItem
operator|*
name|horizontalHeaderItem
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setHorizontalHeaderItem
argument_list|(
argument|int column
argument_list|,
argument|QStandardItem *item
argument_list|)
block|;
name|QStandardItem
operator|*
name|verticalHeaderItem
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|void
name|setVerticalHeaderItem
argument_list|(
argument|int row
argument_list|,
argument|QStandardItem *item
argument_list|)
block|;
name|void
name|setHorizontalHeaderLabels
argument_list|(
specifier|const
name|QStringList
operator|&
name|labels
argument_list|)
block|;
name|void
name|setVerticalHeaderLabels
argument_list|(
specifier|const
name|QStringList
operator|&
name|labels
argument_list|)
block|;
name|void
name|setRowCount
argument_list|(
argument|int rows
argument_list|)
block|;
name|void
name|setColumnCount
argument_list|(
argument|int columns
argument_list|)
block|;
name|void
name|appendRow
argument_list|(
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
block|;
name|void
name|appendColumn
argument_list|(
specifier|const
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|&
name|items
argument_list|)
block|;
specifier|inline
name|void
name|appendRow
argument_list|(
name|QStandardItem
operator|*
name|item
argument_list|)
block|;
name|void
name|insertRow
argument_list|(
argument|int row
argument_list|,
argument|const QList<QStandardItem*>&items
argument_list|)
block|;
name|void
name|insertColumn
argument_list|(
argument|int column
argument_list|,
argument|const QList<QStandardItem*>&items
argument_list|)
block|;
specifier|inline
name|void
name|insertRow
argument_list|(
argument|int row
argument_list|,
argument|QStandardItem *item
argument_list|)
block|;
specifier|inline
name|bool
name|insertRow
argument_list|(
argument|int row
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
specifier|inline
name|bool
name|insertColumn
argument_list|(
argument|int column
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
block|;
name|QStandardItem
operator|*
name|takeItem
argument_list|(
argument|int row
argument_list|,
argument|int column =
literal|0
argument_list|)
block|;
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
name|takeRow
argument_list|(
argument|int row
argument_list|)
block|;
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
name|takeColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|QStandardItem
operator|*
name|takeHorizontalHeaderItem
argument_list|(
argument|int column
argument_list|)
block|;
name|QStandardItem
operator|*
name|takeVerticalHeaderItem
argument_list|(
argument|int row
argument_list|)
block|;
specifier|const
name|QStandardItem
operator|*
name|itemPrototype
argument_list|()
specifier|const
block|;
name|void
name|setItemPrototype
argument_list|(
specifier|const
name|QStandardItem
operator|*
name|item
argument_list|)
block|;
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
name|findItems
argument_list|(
argument|const QString&text
argument_list|,
argument|Qt::MatchFlags flags = Qt::MatchExactly
argument_list|,
argument|int column =
literal|0
argument_list|)
specifier|const
block|;
name|int
name|sortRole
argument_list|()
specifier|const
block|;
name|void
name|setSortRole
argument_list|(
argument|int role
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
name|Q_SIGNALS
operator|:
name|void
name|itemChanged
argument_list|(
name|QStandardItem
operator|*
name|item
argument_list|)
block|;
name|protected
operator|:
name|QStandardItemModel
argument_list|(
name|QStandardItemModelPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QStandardItemPrivate
block|;
name|friend
name|class
name|QStandardItem
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QStandardItemModel
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QStandardItemModel
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemChanged(const QModelIndex&topLeft,                                                      const QModelIndex&bottomRight)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|setItem
specifier|inline
name|void
name|QStandardItemModel
operator|::
name|setItem
argument_list|(
argument|int arow
argument_list|,
argument|QStandardItem *aitem
argument_list|)
block|{
name|setItem
argument_list|(
name|arow
argument_list|,
literal|0
argument_list|,
name|aitem
argument_list|)
block|; }
DECL|function|appendRow
specifier|inline
name|void
name|QStandardItemModel
operator|::
name|appendRow
argument_list|(
argument|QStandardItem *aitem
argument_list|)
block|{
name|appendRow
argument_list|(
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|(
operator|)
operator|<<
name|aitem
argument_list|)
block|; }
DECL|function|insertRow
specifier|inline
name|void
name|QStandardItemModel
operator|::
name|insertRow
argument_list|(
argument|int arow
argument_list|,
argument|QStandardItem *aitem
argument_list|)
block|{
name|insertRow
argument_list|(
name|arow
argument_list|,
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
operator|(
operator|)
operator|<<
name|aitem
argument_list|)
block|; }
DECL|function|insertRow
specifier|inline
name|bool
name|QStandardItemModel
operator|::
name|insertRow
argument_list|(
argument|int arow
argument_list|,
argument|const QModelIndex&aparent
argument_list|)
block|{
return|return
name|QAbstractItemModel
operator|::
name|insertRow
argument_list|(
name|arow
argument_list|,
name|aparent
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|insertColumn
specifier|inline
name|bool
name|QStandardItemModel
operator|::
name|insertColumn
argument_list|(
argument|int acolumn
argument_list|,
argument|const QModelIndex&aparent
argument_list|)
block|{
return|return
name|QAbstractItemModel
operator|::
name|insertColumn
argument_list|(
name|acolumn
argument_list|,
name|aparent
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QStandardItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|out
operator|,
specifier|const
name|QStandardItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STANDARDITEMMODEL
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
comment|//QSTANDARDITEMMODEL_H
end_comment
end_unit
