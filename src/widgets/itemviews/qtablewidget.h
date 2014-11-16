begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTABLEWIDGET_H
end_ifndef
begin_define
DECL|macro|QTABLEWIDGET_H
define|#
directive|define
name|QTABLEWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qtableview.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_comment
comment|//#include<QtWidgets/qitemselectionmodel.h>
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TABLEWIDGET
name|class
name|Q_WIDGETS_EXPORT
name|QTableWidgetSelectionRange
block|{
name|public
label|:
name|QTableWidgetSelectionRange
argument_list|()
expr_stmt|;
name|QTableWidgetSelectionRange
argument_list|(
argument|int top
argument_list|,
argument|int left
argument_list|,
argument|int bottom
argument_list|,
argument|int right
argument_list|)
empty_stmt|;
name|QTableWidgetSelectionRange
argument_list|(
specifier|const
name|QTableWidgetSelectionRange
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QTableWidgetSelectionRange
argument_list|()
expr_stmt|;
specifier|inline
name|int
name|topRow
argument_list|()
specifier|const
block|{
return|return
name|top
return|;
block|}
specifier|inline
name|int
name|bottomRow
argument_list|()
specifier|const
block|{
return|return
name|bottom
return|;
block|}
specifier|inline
name|int
name|leftColumn
argument_list|()
specifier|const
block|{
return|return
name|left
return|;
block|}
specifier|inline
name|int
name|rightColumn
argument_list|()
specifier|const
block|{
return|return
name|right
return|;
block|}
specifier|inline
name|int
name|rowCount
argument_list|()
specifier|const
block|{
return|return
name|bottom
operator|-
name|top
operator|+
literal|1
return|;
block|}
specifier|inline
name|int
name|columnCount
argument_list|()
specifier|const
block|{
return|return
name|right
operator|-
name|left
operator|+
literal|1
return|;
block|}
name|private
label|:
name|int
name|top
decl_stmt|,
name|left
decl_stmt|,
name|bottom
decl_stmt|,
name|right
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QTableWidget
name|class
name|QTableWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTableModel
name|class
name|QTableModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidgetItemData
name|class
name|QWidgetItemData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTableWidgetItemPrivate
name|class
name|QTableWidgetItemPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTableWidgetItem
block|{
name|friend
name|class
name|QTableWidget
decl_stmt|;
name|friend
name|class
name|QTableModel
decl_stmt|;
name|public
label|:
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
name|explicit
name|QTableWidgetItem
parameter_list|(
name|int
name|type
init|=
name|Type
parameter_list|)
function_decl|;
name|explicit
name|QTableWidgetItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|int
name|type
init|=
name|Type
parameter_list|)
function_decl|;
name|explicit
name|QTableWidgetItem
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|int
name|type
init|=
name|Type
parameter_list|)
function_decl|;
name|QTableWidgetItem
argument_list|(
specifier|const
name|QTableWidgetItem
operator|&
name|other
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QTableWidgetItem
argument_list|()
expr_stmt|;
name|virtual
name|QTableWidgetItem
operator|*
name|clone
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|QTableWidget
operator|*
name|tableWidget
argument_list|()
specifier|const
block|{
return|return
name|view
return|;
block|}
specifier|inline
name|int
name|row
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|int
name|column
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|void
name|setSelected
parameter_list|(
name|bool
name|select
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isSelected
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|()
specifier|const
block|{
return|return
name|itemFlags
return|;
block|}
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
name|QString
name|text
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
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
specifier|inline
name|QString
name|statusTip
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|(
name|Qt
operator|::
name|StatusTipRole
argument_list|)
operator|.
name|toString
argument_list|()
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
name|data
argument_list|(
name|Qt
operator|::
name|ToolTipRole
argument_list|)
operator|.
name|toString
argument_list|()
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
name|QT_NO_WHATSTHIS
specifier|inline
name|QString
name|whatsThis
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|(
name|Qt
operator|::
name|WhatsThisRole
argument_list|)
operator|.
name|toString
argument_list|()
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
name|int
name|textAlignment
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|(
name|Qt
operator|::
name|TextAlignmentRole
argument_list|)
operator|.
name|toInt
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setTextAlignment
parameter_list|(
name|int
name|alignment
parameter_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|TextAlignmentRole
argument_list|,
name|alignment
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QColor
name|backgroundColor
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QColor
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|BackgroundColorRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setBackgroundColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|BackgroundColorRole
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
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
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|BackgroundRole
argument_list|,
name|brush
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QColor
name|textColor
argument_list|()
specifier|const
block|{
return|return
name|qvariant_cast
operator|<
name|QColor
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|TextColorRole
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|void
name|setTextColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|TextColorRole
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
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
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|ForegroundRole
argument_list|,
name|brush
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|Qt
operator|::
name|CheckState
name|checkState
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Qt
operator|::
name|CheckState
operator|>
operator|(
name|data
argument_list|(
name|Qt
operator|::
name|CheckStateRole
argument_list|)
operator|.
name|toInt
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|void
name|setCheckState
argument_list|(
name|Qt
operator|::
name|CheckState
name|state
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|CheckStateRole
argument_list|,
name|state
argument_list|)
expr_stmt|;
block|}
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
name|size
parameter_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|SizeHintRole
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
name|virtual
name|QVariant
name|data
argument_list|(
name|int
name|role
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|setData
parameter_list|(
name|int
name|role
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|virtual
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QTableWidgetItem
operator|&
name|other
operator|)
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
name|QTableWidgetItem
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QTableWidgetItem
operator|&
name|other
operator|)
decl_stmt|;
specifier|inline
name|int
name|type
argument_list|()
specifier|const
block|{
return|return
name|rtti
return|;
block|}
name|private
label|:
name|int
name|rtti
decl_stmt|;
name|QVector
operator|<
name|QWidgetItemData
operator|>
name|values
expr_stmt|;
name|QTableWidget
modifier|*
name|view
decl_stmt|;
name|QTableWidgetItemPrivate
modifier|*
name|d
decl_stmt|;
name|Qt
operator|::
name|ItemFlags
name|itemFlags
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|setText
specifier|inline
name|void
name|QTableWidgetItem
operator|::
name|setText
argument_list|(
argument|const QString&atext
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|,
name|atext
argument_list|)
block|; }
DECL|function|setIcon
specifier|inline
name|void
name|QTableWidgetItem
operator|::
name|setIcon
argument_list|(
argument|const QIcon&aicon
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|DecorationRole
argument_list|,
name|aicon
argument_list|)
block|; }
DECL|function|setStatusTip
specifier|inline
name|void
name|QTableWidgetItem
operator|::
name|setStatusTip
argument_list|(
argument|const QString&astatusTip
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|StatusTipRole
argument_list|,
name|astatusTip
argument_list|)
block|; }
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
DECL|function|setToolTip
specifier|inline
name|void
name|QTableWidgetItem
operator|::
name|setToolTip
argument_list|(
argument|const QString&atoolTip
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|ToolTipRole
argument_list|,
name|atoolTip
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
name|QTableWidgetItem
operator|::
name|setWhatsThis
argument_list|(
argument|const QString&awhatsThis
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|WhatsThisRole
argument_list|,
name|awhatsThis
argument_list|)
block|; }
endif|#
directive|endif
DECL|function|setFont
specifier|inline
name|void
name|QTableWidgetItem
operator|::
name|setFont
argument_list|(
argument|const QFont&afont
argument_list|)
block|{
name|setData
argument_list|(
name|Qt
operator|::
name|FontRole
argument_list|,
name|afont
argument_list|)
block|; }
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QTableWidgetItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_WIDGETS_EXPORT
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
name|QTableWidgetItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QTableWidgetPrivate
name|class
name|QTableWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTableWidget
range|:
name|public
name|QTableView
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int rowCount READ rowCount WRITE setRowCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int columnCount READ columnCount WRITE setColumnCount
argument_list|)
name|friend
name|class
name|QTableModel
block|;
name|public
operator|:
name|explicit
name|QTableWidget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QTableWidget
argument_list|(
argument|int rows
argument_list|,
argument|int columns
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
operator|~
name|QTableWidget
argument_list|()
block|;
name|void
name|setRowCount
argument_list|(
argument|int rows
argument_list|)
block|;
name|int
name|rowCount
argument_list|()
specifier|const
block|;
name|void
name|setColumnCount
argument_list|(
argument|int columns
argument_list|)
block|;
name|int
name|columnCount
argument_list|()
specifier|const
block|;
name|int
name|row
argument_list|(
argument|const QTableWidgetItem *item
argument_list|)
specifier|const
block|;
name|int
name|column
argument_list|(
argument|const QTableWidgetItem *item
argument_list|)
specifier|const
block|;
name|QTableWidgetItem
operator|*
name|item
argument_list|(
argument|int row
argument_list|,
argument|int column
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
argument|QTableWidgetItem *item
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|takeItem
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
block|;
name|QTableWidgetItem
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
argument|QTableWidgetItem *item
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|takeVerticalHeaderItem
argument_list|(
argument|int row
argument_list|)
block|;
name|QTableWidgetItem
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
argument|QTableWidgetItem *item
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|takeHorizontalHeaderItem
argument_list|(
argument|int column
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
name|setHorizontalHeaderLabels
argument_list|(
specifier|const
name|QStringList
operator|&
name|labels
argument_list|)
block|;
name|int
name|currentRow
argument_list|()
specifier|const
block|;
name|int
name|currentColumn
argument_list|()
specifier|const
block|;
name|QTableWidgetItem
operator|*
name|currentItem
argument_list|()
specifier|const
block|;
name|void
name|setCurrentItem
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|setCurrentItem
argument_list|(
argument|QTableWidgetItem *item
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
name|void
name|setCurrentCell
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|setCurrentCell
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|QItemSelectionModel::SelectionFlags command
argument_list|)
block|;
name|void
name|sortItems
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order = Qt::AscendingOrder
argument_list|)
block|;
name|void
name|setSortingEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isSortingEnabled
argument_list|()
specifier|const
block|;
name|void
name|editItem
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|openPersistentEditor
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|closePersistentEditor
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|QWidget
operator|*
name|cellWidget
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setCellWidget
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|QWidget *widget
argument_list|)
block|;
specifier|inline
name|void
name|removeCellWidget
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
block|;
name|bool
name|isItemSelected
argument_list|(
argument|const QTableWidgetItem *item
argument_list|)
specifier|const
block|;
name|void
name|setItemSelected
argument_list|(
argument|const QTableWidgetItem *item
argument_list|,
argument|bool select
argument_list|)
block|;
name|void
name|setRangeSelected
argument_list|(
argument|const QTableWidgetSelectionRange&range
argument_list|,
argument|bool select
argument_list|)
block|;
name|QList
operator|<
name|QTableWidgetSelectionRange
operator|>
name|selectedRanges
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QTableWidgetItem
operator|*
operator|>
name|selectedItems
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QTableWidgetItem
operator|*
operator|>
name|findItems
argument_list|(
argument|const QString&text
argument_list|,
argument|Qt::MatchFlags flags
argument_list|)
specifier|const
block|;
name|int
name|visualRow
argument_list|(
argument|int logicalRow
argument_list|)
specifier|const
block|;
name|int
name|visualColumn
argument_list|(
argument|int logicalColumn
argument_list|)
specifier|const
block|;
name|QTableWidgetItem
operator|*
name|itemAt
argument_list|(
argument|const QPoint&p
argument_list|)
specifier|const
block|;
specifier|inline
name|QTableWidgetItem
operator|*
name|itemAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QRect
name|visualItemRect
argument_list|(
argument|const QTableWidgetItem *item
argument_list|)
specifier|const
block|;
specifier|const
name|QTableWidgetItem
operator|*
name|itemPrototype
argument_list|()
specifier|const
block|;
name|void
name|setItemPrototype
argument_list|(
specifier|const
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|scrollToItem
argument_list|(
argument|const QTableWidgetItem *item
argument_list|,
argument|QAbstractItemView::ScrollHint hint = EnsureVisible
argument_list|)
block|;
name|void
name|insertRow
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|insertColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|removeRow
argument_list|(
argument|int row
argument_list|)
block|;
name|void
name|removeColumn
argument_list|(
argument|int column
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|clearContents
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|itemPressed
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemClicked
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemDoubleClicked
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemActivated
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemEntered
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|itemChanged
argument_list|(
name|QTableWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|currentItemChanged
argument_list|(
name|QTableWidgetItem
operator|*
name|current
argument_list|,
name|QTableWidgetItem
operator|*
name|previous
argument_list|)
block|;
name|void
name|itemSelectionChanged
argument_list|()
block|;
name|void
name|cellPressed
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|cellClicked
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|cellDoubleClicked
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|cellActivated
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|cellEntered
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|cellChanged
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
block|;
name|void
name|currentCellChanged
argument_list|(
argument|int currentRow
argument_list|,
argument|int currentColumn
argument_list|,
argument|int previousRow
argument_list|,
argument|int previousColumn
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QStringList
name|mimeTypes
argument_list|()
specifier|const
block|;
name|virtual
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|const QList<QTableWidgetItem*> items
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|dropMimeData
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QMimeData *data
argument_list|,
argument|Qt::DropAction action
argument_list|)
block|;
name|virtual
name|Qt
operator|::
name|DropActions
name|supportedDropActions
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QTableWidgetItem
operator|*
operator|>
name|items
argument_list|(
argument|const QMimeData *data
argument_list|)
specifier|const
block|;
name|QModelIndex
name|indexFromItem
argument_list|(
argument|QTableWidgetItem *item
argument_list|)
specifier|const
block|;
name|QTableWidgetItem
operator|*
name|itemFromIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|dropEvent
argument_list|(
argument|QDropEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|setModel
argument_list|(
argument|QAbstractItemModel *model
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTableWidget
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QTableWidget
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemPressed(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemClicked(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemDoubleClicked(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemActivated(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemEntered(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitItemChanged(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitCurrentItemChanged(const QModelIndex&previous, const QModelIndex&current)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_sort()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_dataChanged(const QModelIndex&topLeft, const QModelIndex&bottomRight)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|removeCellWidget
specifier|inline
name|void
name|QTableWidget
operator|::
name|removeCellWidget
argument_list|(
argument|int arow
argument_list|,
argument|int acolumn
argument_list|)
block|{
name|setCellWidget
argument_list|(
name|arow
argument_list|,
name|acolumn
argument_list|,
literal|0
argument_list|)
block|; }
DECL|function|itemAt
specifier|inline
name|QTableWidgetItem
operator|*
name|QTableWidget
operator|::
name|itemAt
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|)
specifier|const
block|{
return|return
name|itemAt
argument_list|(
name|QPoint
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|row
specifier|inline
name|int
name|QTableWidgetItem
operator|::
name|row
argument_list|()
specifier|const
block|{
return|return
operator|(
name|view
operator|?
name|view
operator|->
name|row
argument_list|(
name|this
argument_list|)
operator|:
operator|-
literal|1
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|column
specifier|inline
name|int
name|QTableWidgetItem
operator|::
name|column
argument_list|()
specifier|const
block|{
return|return
operator|(
name|view
operator|?
name|view
operator|->
name|column
argument_list|(
name|this
argument_list|)
operator|:
operator|-
literal|1
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setSelected
specifier|inline
name|void
name|QTableWidgetItem
operator|::
name|setSelected
argument_list|(
argument|bool aselect
argument_list|)
block|{
if|if
condition|(
name|view
condition|)
name|view
operator|->
name|setItemSelected
argument_list|(
name|this
argument_list|,
name|aselect
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isSelected
specifier|inline
name|bool
name|QTableWidgetItem
operator|::
name|isSelected
argument_list|()
specifier|const
block|{
return|return
operator|(
name|view
operator|?
name|view
operator|->
name|isItemSelected
argument_list|(
name|this
argument_list|)
operator|:
name|false
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABLEWIDGET
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTABLEWIDGET_H
end_comment
end_unit
