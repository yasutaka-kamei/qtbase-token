begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOMBOBOX_H
end_ifndef
begin_define
DECL|macro|QCOMBOBOX_H
define|#
directive|define
name|QCOMBOBOX_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qabstractitemdelegate.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_COMBOBOX
DECL|variable|QAbstractItemView
name|class
name|QAbstractItemView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBoxPrivate
name|class
name|QComboBoxPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCompleter
name|class
name|QCompleter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QComboBox
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool editable READ isEditable WRITE setEditable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int count READ count
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString currentText READ currentText WRITE setCurrentText NOTIFY currentTextChanged USER true
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QVariant currentData READ currentData
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int maxVisibleItems READ maxVisibleItems WRITE setMaxVisibleItems
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int maxCount READ maxCount WRITE setMaxCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|InsertPolicy insertPolicy READ insertPolicy WRITE setInsertPolicy
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|SizeAdjustPolicy sizeAdjustPolicy READ sizeAdjustPolicy WRITE setSizeAdjustPolicy
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int minimumContentsLength READ minimumContentsLength WRITE setMinimumContentsLength
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSize iconSize READ iconSize WRITE setIconSize
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
name|Q_PROPERTY
argument_list|(
argument|bool autoCompletion READ autoCompletion WRITE setAutoCompletion DESIGNABLE false
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::CaseSensitivity autoCompletionCaseSensitivity READ autoCompletionCaseSensitivity WRITE setAutoCompletionCaseSensitivity DESIGNABLE false
argument_list|)
endif|#
directive|endif
comment|// QT_NO_COMPLETER
name|Q_PROPERTY
argument_list|(
argument|bool duplicatesEnabled READ duplicatesEnabled WRITE setDuplicatesEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool frame READ hasFrame WRITE setFrame
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int modelColumn READ modelColumn WRITE setModelColumn
argument_list|)
name|public
operator|:
name|explicit
name|QComboBox
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QComboBox
argument_list|()
block|;
name|int
name|maxVisibleItems
argument_list|()
specifier|const
block|;
name|void
name|setMaxVisibleItems
argument_list|(
argument|int maxItems
argument_list|)
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|void
name|setMaxCount
argument_list|(
argument|int max
argument_list|)
block|;
name|int
name|maxCount
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
name|bool
name|autoCompletion
argument_list|()
specifier|const
block|;
name|void
name|setAutoCompletion
argument_list|(
argument|bool enable
argument_list|)
block|;
name|Qt
operator|::
name|CaseSensitivity
name|autoCompletionCaseSensitivity
argument_list|()
specifier|const
block|;
name|void
name|setAutoCompletionCaseSensitivity
argument_list|(
argument|Qt::CaseSensitivity sensitivity
argument_list|)
block|;
endif|#
directive|endif
name|bool
name|duplicatesEnabled
argument_list|()
specifier|const
block|;
name|void
name|setDuplicatesEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|void
name|setFrame
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|hasFrame
argument_list|()
specifier|const
block|;
specifier|inline
name|int
name|findText
argument_list|(
argument|const QString&text
argument_list|,
argument|Qt::MatchFlags flags = static_cast<Qt::MatchFlags>(Qt::MatchExactly|Qt::MatchCaseSensitive)
argument_list|)
specifier|const
block|{
return|return
name|findData
argument_list|(
name|text
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|,
name|flags
argument_list|)
return|;
block|}
name|int
name|findData
argument_list|(
argument|const QVariant&data
argument_list|,
argument|int role = Qt::UserRole
argument_list|,
argument|Qt::MatchFlags flags = static_cast<Qt::MatchFlags>(Qt::MatchExactly|Qt::MatchCaseSensitive)
argument_list|)
specifier|const
block|;      enum
name|InsertPolicy
block|{
name|NoInsert
block|,
name|InsertAtTop
block|,
name|InsertAtCurrent
block|,
name|InsertAtBottom
block|,
name|InsertAfterCurrent
block|,
name|InsertBeforeCurrent
block|,
name|InsertAlphabetically
block|}
block|;
name|Q_ENUM
argument_list|(
argument|InsertPolicy
argument_list|)
name|InsertPolicy
name|insertPolicy
argument_list|()
specifier|const
block|;
name|void
name|setInsertPolicy
argument_list|(
argument|InsertPolicy policy
argument_list|)
block|;      enum
name|SizeAdjustPolicy
block|{
name|AdjustToContents
block|,
name|AdjustToContentsOnFirstShow
block|,
name|AdjustToMinimumContentsLength
block|,
comment|// ### Qt 6: remove
name|AdjustToMinimumContentsLengthWithIcon
block|}
block|;
name|Q_ENUM
argument_list|(
argument|SizeAdjustPolicy
argument_list|)
name|SizeAdjustPolicy
name|sizeAdjustPolicy
argument_list|()
specifier|const
block|;
name|void
name|setSizeAdjustPolicy
argument_list|(
argument|SizeAdjustPolicy policy
argument_list|)
block|;
name|int
name|minimumContentsLength
argument_list|()
specifier|const
block|;
name|void
name|setMinimumContentsLength
argument_list|(
argument|int characters
argument_list|)
block|;
name|QSize
name|iconSize
argument_list|()
specifier|const
block|;
name|void
name|setIconSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|bool
name|isEditable
argument_list|()
specifier|const
block|;
name|void
name|setEditable
argument_list|(
argument|bool editable
argument_list|)
block|;
name|void
name|setLineEdit
argument_list|(
name|QLineEdit
operator|*
name|edit
argument_list|)
block|;
name|QLineEdit
operator|*
name|lineEdit
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_VALIDATOR
name|void
name|setValidator
argument_list|(
specifier|const
name|QValidator
operator|*
name|v
argument_list|)
block|;
specifier|const
name|QValidator
operator|*
name|validator
argument_list|()
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
name|void
name|setCompleter
argument_list|(
name|QCompleter
operator|*
name|c
argument_list|)
block|;
name|QCompleter
operator|*
name|completer
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QAbstractItemDelegate
operator|*
name|itemDelegate
argument_list|()
specifier|const
block|;
name|void
name|setItemDelegate
argument_list|(
name|QAbstractItemDelegate
operator|*
name|delegate
argument_list|)
block|;
name|QAbstractItemModel
operator|*
name|model
argument_list|()
specifier|const
block|;
name|void
name|setModel
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|)
block|;
name|QModelIndex
name|rootModelIndex
argument_list|()
specifier|const
block|;
name|void
name|setRootModelIndex
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|int
name|modelColumn
argument_list|()
specifier|const
block|;
name|void
name|setModelColumn
argument_list|(
argument|int visibleColumn
argument_list|)
block|;
name|int
name|currentIndex
argument_list|()
specifier|const
block|;
name|QString
name|currentText
argument_list|()
specifier|const
block|;
name|QVariant
name|currentData
argument_list|(
argument|int role = Qt::UserRole
argument_list|)
specifier|const
block|;
name|QString
name|itemText
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QIcon
name|itemIcon
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QVariant
name|itemData
argument_list|(
argument|int index
argument_list|,
argument|int role = Qt::UserRole
argument_list|)
specifier|const
block|;
specifier|inline
name|void
name|addItem
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
name|QVariant
operator|&
name|userData
operator|=
name|QVariant
argument_list|()
argument_list|)
block|;
specifier|inline
name|void
name|addItem
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
argument_list|,
specifier|const
name|QVariant
operator|&
name|userData
operator|=
name|QVariant
argument_list|()
argument_list|)
block|;
specifier|inline
name|void
name|addItems
argument_list|(
argument|const QStringList&texts
argument_list|)
block|{
name|insertItems
argument_list|(
name|count
argument_list|()
argument_list|,
name|texts
argument_list|)
block|; }
specifier|inline
name|void
name|insertItem
argument_list|(
argument|int index
argument_list|,
argument|const QString&text
argument_list|,
argument|const QVariant&userData = QVariant()
argument_list|)
block|;
name|void
name|insertItem
argument_list|(
argument|int index
argument_list|,
argument|const QIcon&icon
argument_list|,
argument|const QString&text
argument_list|,
argument|const QVariant&userData = QVariant()
argument_list|)
block|;
name|void
name|insertItems
argument_list|(
argument|int index
argument_list|,
argument|const QStringList&texts
argument_list|)
block|;
name|void
name|insertSeparator
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|removeItem
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|setItemText
argument_list|(
argument|int index
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|void
name|setItemIcon
argument_list|(
argument|int index
argument_list|,
argument|const QIcon&icon
argument_list|)
block|;
name|void
name|setItemData
argument_list|(
argument|int index
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role = Qt::UserRole
argument_list|)
block|;
name|QAbstractItemView
operator|*
name|view
argument_list|()
specifier|const
block|;
name|void
name|setView
argument_list|(
name|QAbstractItemView
operator|*
name|itemView
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|showPopup
argument_list|()
block|;
name|virtual
name|void
name|hidePopup
argument_list|()
block|;
name|bool
name|event
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Q_INVOKABLE
name|QVariant
name|inputMethodQuery
argument_list|(
argument|Qt::InputMethodQuery query
argument_list|,
argument|const QVariant&argument
argument_list|)
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|clear
argument_list|()
block|;
name|void
name|clearEditText
argument_list|()
block|;
name|void
name|setEditText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|setCurrentIndex
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|setCurrentText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|editTextChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|activated
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|activated
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|highlighted
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|highlighted
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|currentIndexChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|currentIndexChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|currentTextChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|protected
operator|:
name|void
name|focusInEvent
argument_list|(
argument|QFocusEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|focusOutEvent
argument_list|(
argument|QFocusEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|changeEvent
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|showEvent
argument_list|(
argument|QShowEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|hideEvent
argument_list|(
argument|QHideEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|keyPressEvent
argument_list|(
argument|QKeyEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|keyReleaseEvent
argument_list|(
argument|QKeyEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
argument|QWheelEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
argument|QContextMenuEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
comment|// QT_NO_CONTEXTMENU
name|void
name|inputMethodEvent
argument_list|(
argument|QInputMethodEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionComboBox *option
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QComboBox
argument_list|(
name|QComboBoxPrivate
operator|&
argument_list|,
name|QWidget
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QComboBox
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QComboBox
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_itemSelected(const QModelIndex&item)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitHighlighted(const QModelIndex&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitCurrentIndexChanged(const QModelIndex&index)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_editingFinished()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_returnPressed()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_resetButton()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_dataChanged(const QModelIndex&, const QModelIndex&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateIndexBeforeChange()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_rowsInserted(const QModelIndex& parent, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_rowsRemoved(const QModelIndex& parent, int start, int end)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_modelDestroyed()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_modelReset()
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_completerActivated(const QModelIndex&index)
argument_list|)
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|addItem
specifier|inline
name|void
name|QComboBox
operator|::
name|addItem
argument_list|(
argument|const QString&atext
argument_list|,
argument|const QVariant&auserData
argument_list|)
block|{
name|insertItem
argument_list|(
name|count
argument_list|()
argument_list|,
name|atext
argument_list|,
name|auserData
argument_list|)
block|; }
DECL|function|addItem
specifier|inline
name|void
name|QComboBox
operator|::
name|addItem
argument_list|(
argument|const QIcon&aicon
argument_list|,
argument|const QString&atext
argument_list|,
argument|const QVariant&auserData
argument_list|)
block|{
name|insertItem
argument_list|(
name|count
argument_list|()
argument_list|,
name|aicon
argument_list|,
name|atext
argument_list|,
name|auserData
argument_list|)
block|; }
DECL|function|insertItem
specifier|inline
name|void
name|QComboBox
operator|::
name|insertItem
argument_list|(
argument|int aindex
argument_list|,
argument|const QString&atext
argument_list|,
argument|const QVariant&auserData
argument_list|)
block|{
name|insertItem
argument_list|(
name|aindex
argument_list|,
name|QIcon
argument_list|()
argument_list|,
name|atext
argument_list|,
name|auserData
argument_list|)
block|; }
endif|#
directive|endif
comment|// QT_NO_COMBOBOX
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOMBOBOX_H
end_comment
end_unit
