begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOMBOBOX_P_H
end_ifndef
begin_define
DECL|macro|QCOMBOBOX_P_H
define|#
directive|define
name|QCOMBOBOX_P_H
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
file|"QtWidgets/qcombobox.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMBOBOX
end_ifndef
begin_include
include|#
directive|include
file|"QtWidgets/qabstractslider.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qapplication.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qitemdelegate.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qstandarditemmodel.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qlineedit.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qlistview.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpainter.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qstyle.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpair.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qtimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qcompleter.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qevent.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdebug.h"
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QComboBoxListView
range|:
name|public
name|QListView
block|{
name|Q_OBJECT
name|public
operator|:
name|QComboBoxListView
argument_list|(
name|QComboBox
operator|*
name|cmb
operator|=
literal|0
argument_list|)
operator|:
name|combo
argument_list|(
argument|cmb
argument_list|)
block|{}
name|protected
operator|:
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *event
argument_list|)
block|{
name|resizeContents
argument_list|(
name|viewport
argument_list|()
operator|->
name|width
argument_list|()
argument_list|,
name|contentsSize
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
block|;
name|QListView
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
block|;     }
name|QStyleOptionViewItem
name|viewOptions
argument_list|()
specifier|const
block|{
name|QStyleOptionViewItem
name|option
operator|=
name|QListView
operator|::
name|viewOptions
argument_list|()
block|;
name|option
operator|.
name|showDecorationSelected
operator|=
name|true
block|;
if|if
condition|(
name|combo
condition|)
name|option
operator|.
name|font
operator|=
name|combo
operator|->
name|font
argument_list|()
expr_stmt|;
return|return
name|option
return|;
block|}
end_decl_stmt
begin_function
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|combo
condition|)
block|{
name|QStyleOptionComboBox
name|opt
decl_stmt|;
name|opt
operator|.
name|initFrom
argument_list|(
name|combo
argument_list|)
expr_stmt|;
name|opt
operator|.
name|editable
operator|=
name|combo
operator|->
name|isEditable
argument_list|()
expr_stmt|;
if|if
condition|(
name|combo
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_ComboBox_Popup
argument_list|,
operator|&
name|opt
argument_list|,
name|combo
argument_list|)
condition|)
block|{
comment|//we paint the empty menu area to avoid having blank space that can happen when scrolling
name|QStyleOptionMenuItem
name|menuOpt
decl_stmt|;
name|menuOpt
operator|.
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|menuOpt
operator|.
name|palette
operator|=
name|palette
argument_list|()
expr_stmt|;
name|menuOpt
operator|.
name|state
operator|=
name|QStyle
operator|::
name|State_None
expr_stmt|;
name|menuOpt
operator|.
name|checkType
operator|=
name|QStyleOptionMenuItem
operator|::
name|NotCheckable
expr_stmt|;
name|menuOpt
operator|.
name|menuRect
operator|=
name|e
operator|->
name|rect
argument_list|()
expr_stmt|;
name|menuOpt
operator|.
name|maxIconWidth
operator|=
literal|0
expr_stmt|;
name|menuOpt
operator|.
name|tabWidth
operator|=
literal|0
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|viewport
argument_list|()
argument_list|)
decl_stmt|;
name|combo
operator|->
name|style
argument_list|()
operator|->
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_MenuEmptyArea
argument_list|,
operator|&
name|menuOpt
argument_list|,
operator|&
name|p
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
block|}
name|QListView
operator|::
name|paintEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QComboBox
modifier|*
name|combo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
DECL|variable|QStandardItemModel
name|class
name|QStandardItemModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QComboBoxPrivateScroller
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|QComboBoxPrivateScroller
argument_list|(
argument|QAbstractSlider::SliderAction action
argument_list|,
argument|QWidget *parent
argument_list|)
operator|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|,
name|sliderAction
argument_list|(
argument|action
argument_list|)
block|{
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
block|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoMousePropagation
argument_list|)
block|;     }
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|20
argument_list|,
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_MenuScrollerHeight
argument_list|)
argument_list|)
return|;
block|}
name|protected
operator|:
specifier|inline
name|void
name|stopTimer
argument_list|()
block|{
name|timer
operator|.
name|stop
argument_list|()
block|;     }
specifier|inline
name|void
name|startTimer
argument_list|()
block|{
name|timer
operator|.
name|start
argument_list|(
literal|100
argument_list|,
name|this
argument_list|)
block|;
name|fast
operator|=
name|false
block|;     }
name|void
name|enterEvent
argument_list|(
argument|QEvent *
argument_list|)
block|{
name|startTimer
argument_list|()
block|;     }
name|void
name|leaveEvent
argument_list|(
argument|QEvent *
argument_list|)
block|{
name|stopTimer
argument_list|()
block|;     }
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *e
argument_list|)
block|{
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|timer
operator|.
name|timerId
argument_list|()
condition|)
block|{
name|emit
name|doScroll
parameter_list|(
name|sliderAction
parameter_list|)
function_decl|;
if|if
condition|(
name|fast
condition|)
block|{
name|emit
name|doScroll
parameter_list|(
name|sliderAction
parameter_list|)
function_decl|;
name|emit
name|doScroll
parameter_list|(
name|sliderAction
parameter_list|)
function_decl|;
block|}
block|}
block|}
name|void
name|hideEvent
argument_list|(
argument|QHideEvent *
argument_list|)
block|{
name|stopTimer
argument_list|()
block|;     }
name|void
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *e
argument_list|)
block|{
comment|// Enable fast scrolling if the cursor is directly above or below the popup.
specifier|const
name|int
name|mouseX
operator|=
name|e
operator|->
name|pos
argument_list|()
operator|.
name|x
argument_list|()
block|;
specifier|const
name|int
name|mouseY
operator|=
name|e
operator|->
name|pos
argument_list|()
operator|.
name|y
argument_list|()
block|;
specifier|const
name|bool
name|horizontallyInside
operator|=
name|pos
argument_list|()
operator|.
name|x
argument_list|()
operator|<
name|mouseX
operator|&&
name|mouseX
operator|<
name|rect
argument_list|()
operator|.
name|right
argument_list|()
operator|+
literal|1
block|;
specifier|const
name|bool
name|verticallyOutside
operator|=
operator|(
name|sliderAction
operator|==
name|QAbstractSlider
operator|::
name|SliderSingleStepAdd
operator|)
condition|?
name|rect
argument_list|()
operator|.
name|bottom
argument_list|()
operator|+
literal|1
operator|<
name|mouseY
else|:
name|mouseY
operator|<
name|pos
argument_list|()
operator|.
name|y
argument_list|()
block|;
name|fast
operator|=
name|horizontallyInside
operator|&&
name|verticallyOutside
block|;     }
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *
argument_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
block|;
name|QStyleOptionMenuItem
name|menuOpt
block|;
name|menuOpt
operator|.
name|init
argument_list|(
name|this
argument_list|)
block|;
name|menuOpt
operator|.
name|checkType
operator|=
name|QStyleOptionMenuItem
operator|::
name|NotCheckable
block|;
name|menuOpt
operator|.
name|menuRect
operator|=
name|rect
argument_list|()
block|;
name|menuOpt
operator|.
name|maxIconWidth
operator|=
literal|0
block|;
name|menuOpt
operator|.
name|tabWidth
operator|=
literal|0
block|;
name|menuOpt
operator|.
name|menuItemType
operator|=
name|QStyleOptionMenuItem
operator|::
name|Scroller
block|;
if|if
condition|(
name|sliderAction
operator|==
name|QAbstractSlider
operator|::
name|SliderSingleStepAdd
condition|)
name|menuOpt
operator|.
name|state
operator||=
name|QStyle
operator|::
name|State_DownArrow
expr_stmt|;
name|p
operator|.
name|eraseRect
argument_list|(
name|rect
argument_list|()
argument_list|)
block|;
name|style
argument_list|()
operator|->
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_MenuScroller
argument_list|,
operator|&
name|menuOpt
argument_list|,
operator|&
name|p
argument_list|)
block|;     }
name|Q_SIGNALS
operator|:
name|void
name|doScroll
argument_list|(
argument|int action
argument_list|)
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QAbstractSlider
operator|::
name|SliderAction
name|sliderAction
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QBasicTimer
name|timer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|fast
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_AUTOTEST_EXPORT
name|QComboBoxPrivateContainer
range|:
name|public
name|QFrame
block|{
name|Q_OBJECT
name|public
operator|:
name|QComboBoxPrivateContainer
argument_list|(
name|QAbstractItemView
operator|*
name|itemView
argument_list|,
name|QComboBox
operator|*
name|parent
argument_list|)
block|;
name|QAbstractItemView
operator|*
name|itemView
argument_list|()
specifier|const
block|;
name|void
name|setItemView
argument_list|(
name|QAbstractItemView
operator|*
name|itemView
argument_list|)
block|;
name|int
name|spacing
argument_list|()
specifier|const
block|;
name|void
name|updateTopBottomMargin
argument_list|()
block|;
name|QTimer
name|blockMouseReleaseTimer
block|;
name|QBasicTimer
name|adjustSizeTimer
block|;
name|QPoint
name|initialClickPosition
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|scrollItemView
argument_list|(
argument|int action
argument_list|)
block|;
name|void
name|updateScrollers
argument_list|()
block|;
name|void
name|viewDestroyed
argument_list|()
block|;
name|protected
operator|:
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|hideEvent
argument_list|(
name|QHideEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|timerEvent
argument_list|)
block|;
name|void
name|leaveEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|e
argument_list|)
block|;
name|QStyleOptionComboBox
name|comboStyleOption
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|itemSelected
argument_list|(
specifier|const
name|QModelIndex
operator|&
argument_list|)
block|;
name|void
name|resetButton
argument_list|()
block|;
name|private
operator|:
name|QComboBox
operator|*
name|combo
block|;
name|QAbstractItemView
operator|*
name|view
block|;
name|QComboBoxPrivateScroller
operator|*
name|top
block|;
name|QComboBoxPrivateScroller
operator|*
name|bottom
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QComboMenuDelegate
range|:
name|public
name|QAbstractItemDelegate
block|{
name|Q_OBJECT
name|public
operator|:
name|QComboMenuDelegate
argument_list|(
name|QObject
operator|*
name|parent
argument_list|,
name|QComboBox
operator|*
name|cmb
argument_list|)
operator|:
name|QAbstractItemDelegate
argument_list|(
name|parent
argument_list|)
block|,
name|mCombo
argument_list|(
argument|cmb
argument_list|)
block|{}
name|protected
operator|:
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
name|QStyleOptionMenuItem
name|opt
operator|=
name|getStyleOption
argument_list|(
name|option
argument_list|,
name|index
argument_list|)
block|;
name|painter
operator|->
name|fillRect
argument_list|(
name|option
operator|.
name|rect
argument_list|,
name|opt
operator|.
name|palette
operator|.
name|background
argument_list|()
argument_list|)
block|;
name|mCombo
operator|->
name|style
argument_list|()
operator|->
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_MenuItem
argument_list|,
operator|&
name|opt
argument_list|,
name|painter
argument_list|,
name|mCombo
argument_list|)
block|;     }
name|QSize
name|sizeHint
argument_list|(
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
name|QStyleOptionMenuItem
name|opt
operator|=
name|getStyleOption
argument_list|(
name|option
argument_list|,
name|index
argument_list|)
block|;
return|return
name|mCombo
operator|->
name|style
argument_list|()
operator|->
name|sizeFromContents
argument_list|(
name|QStyle
operator|::
name|CT_MenuItem
argument_list|,
operator|&
name|opt
argument_list|,
name|option
operator|.
name|rect
operator|.
name|size
argument_list|()
argument_list|,
name|mCombo
argument_list|)
return|;
block|}
name|private
operator|:
name|QStyleOptionMenuItem
name|getStyleOption
argument_list|(
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QComboBox
operator|*
name|mCombo
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Note that this class is intentionally not using QStyledItemDelegate
end_comment
begin_comment
comment|// Vista does not use the new theme for combo boxes and there might
end_comment
begin_comment
comment|// be other side effects from using the new class
end_comment
begin_decl_stmt
name|class
name|QComboBoxDelegate
range|:
name|public
name|QItemDelegate
block|{
name|Q_OBJECT
name|public
operator|:
name|QComboBoxDelegate
argument_list|(
name|QObject
operator|*
name|parent
argument_list|,
name|QComboBox
operator|*
name|cmb
argument_list|)
operator|:
name|QItemDelegate
argument_list|(
name|parent
argument_list|)
block|,
name|mCombo
argument_list|(
argument|cmb
argument_list|)
block|{}
specifier|static
name|bool
name|isSeparator
argument_list|(
argument|const QModelIndex&index
argument_list|)
block|{
return|return
name|index
operator|.
name|data
argument_list|(
name|Qt
operator|::
name|AccessibleDescriptionRole
argument_list|)
operator|.
name|toString
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"separator"
argument_list|)
return|;
block|}
specifier|static
name|void
name|setSeparator
argument_list|(
argument|QAbstractItemModel *model
argument_list|,
argument|const QModelIndex&index
argument_list|)
block|{
name|model
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"separator"
argument_list|)
argument_list|,
name|Qt
operator|::
name|AccessibleDescriptionRole
argument_list|)
block|;
if|if
condition|(
name|QStandardItemModel
modifier|*
name|m
init|=
name|qobject_cast
operator|<
name|QStandardItemModel
operator|*
operator|>
operator|(
name|model
operator|)
condition|)
if|if
condition|(
name|QStandardItem
modifier|*
name|item
init|=
name|m
operator|->
name|itemFromIndex
argument_list|(
name|index
argument_list|)
condition|)
name|item
operator|->
name|setFlags
argument_list|(
name|item
operator|->
name|flags
argument_list|()
operator|&
operator|~
operator|(
name|Qt
operator|::
name|ItemIsSelectable
operator||
name|Qt
operator|::
name|ItemIsEnabled
operator|)
argument_list|)
expr_stmt|;
block|}
name|protected
operator|:
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
if|if
condition|(
name|isSeparator
argument_list|(
name|index
argument_list|)
condition|)
block|{
name|QRect
name|rect
init|=
name|option
operator|.
name|rect
decl_stmt|;
if|if
condition|(
specifier|const
name|QAbstractItemView
modifier|*
name|view
init|=
name|qobject_cast
operator|<
specifier|const
name|QAbstractItemView
operator|*
operator|>
operator|(
name|option
operator|.
name|widget
operator|)
condition|)
name|rect
operator|.
name|setWidth
argument_list|(
name|view
operator|->
name|viewport
argument_list|()
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QStyleOption
name|opt
decl_stmt|;
name|opt
operator|.
name|rect
operator|=
name|rect
expr_stmt|;
name|mCombo
operator|->
name|style
argument_list|()
operator|->
name|drawPrimitive
argument_list|(
name|QStyle
operator|::
name|PE_IndicatorToolBarSeparator
argument_list|,
operator|&
name|opt
argument_list|,
name|painter
argument_list|,
name|mCombo
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QItemDelegate
operator|::
name|paint
argument_list|(
name|painter
argument_list|,
name|option
argument_list|,
name|index
argument_list|)
expr_stmt|;
block|}
block|}
name|QSize
name|sizeHint
argument_list|(
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
if|if
condition|(
name|isSeparator
argument_list|(
name|index
argument_list|)
condition|)
block|{
name|int
name|pm
init|=
name|mCombo
operator|->
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_DefaultFrameWidth
argument_list|,
literal|0
argument_list|,
name|mCombo
argument_list|)
decl_stmt|;
return|return
name|QSize
argument_list|(
name|pm
argument_list|,
name|pm
argument_list|)
return|;
block|}
return|return
name|QItemDelegate
operator|::
name|sizeHint
argument_list|(
name|option
argument_list|,
name|index
argument_list|)
return|;
block|}
name|private
operator|:
name|QComboBox
operator|*
name|mCombo
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QComboBoxPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QComboBox
argument_list|)
name|public
operator|:
name|QComboBoxPrivate
argument_list|()
block|;
operator|~
name|QComboBoxPrivate
argument_list|()
block|{}
name|void
name|init
argument_list|()
block|;
name|QComboBoxPrivateContainer
operator|*
name|viewContainer
argument_list|()
block|;
name|void
name|updateLineEditGeometry
argument_list|()
block|;
name|Qt
operator|::
name|MatchFlags
name|matchFlags
argument_list|()
specifier|const
block|;
name|void
name|_q_editingFinished
argument_list|()
block|;
name|void
name|_q_returnPressed
argument_list|()
block|;
name|void
name|_q_complete
argument_list|()
block|;
name|void
name|_q_itemSelected
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|item
argument_list|)
block|;
name|bool
name|contains
argument_list|(
argument|const QString&text
argument_list|,
argument|int role
argument_list|)
block|;
name|void
name|emitActivated
argument_list|(
specifier|const
name|QModelIndex
operator|&
argument_list|)
block|;
name|void
name|_q_emitHighlighted
argument_list|(
specifier|const
name|QModelIndex
operator|&
argument_list|)
block|;
name|void
name|_q_emitCurrentIndexChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|_q_modelDestroyed
argument_list|()
block|;
name|void
name|_q_modelReset
argument_list|()
block|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|void
name|_q_completerActivated
argument_list|()
block|;
endif|#
directive|endif
name|void
name|_q_resetButton
argument_list|()
block|;
name|void
name|_q_dataChanged
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
name|_q_updateIndexBeforeChange
argument_list|()
block|;
name|void
name|_q_rowsInserted
argument_list|(
argument|const QModelIndex& parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|_q_rowsRemoved
argument_list|(
argument|const QModelIndex& parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|updateArrow
argument_list|(
argument|QStyle::StateFlag state
argument_list|)
block|;
name|bool
name|updateHoverControl
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|QRect
name|popupGeometry
argument_list|(
argument|int screen = -
literal|1
argument_list|)
specifier|const
block|;
name|QStyle
operator|::
name|SubControl
name|newHoverControl
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|int
name|computeWidthHint
argument_list|()
specifier|const
block|;
name|QSize
name|recomputeSizeHint
argument_list|(
argument|QSize&sh
argument_list|)
specifier|const
block|;
name|void
name|adjustComboBoxSize
argument_list|()
block|;
name|QString
name|itemText
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|QIcon
name|itemIcon
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|int
name|itemRole
argument_list|()
specifier|const
block|;
name|void
name|updateLayoutDirection
argument_list|()
block|;
name|void
name|setCurrentIndex
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|updateDelegate
argument_list|(
argument|bool force = false
argument_list|)
block|;
name|void
name|keyboardSearchString
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|modelChanged
argument_list|()
block|;
name|void
name|updateViewContainerPaletteAndOpacity
argument_list|()
block|;
name|QAbstractItemModel
operator|*
name|model
block|;
name|QLineEdit
operator|*
name|lineEdit
block|;
name|QComboBoxPrivateContainer
operator|*
name|container
block|;
name|QComboBox
operator|::
name|InsertPolicy
name|insertPolicy
block|;
name|QComboBox
operator|::
name|SizeAdjustPolicy
name|sizeAdjustPolicy
block|;
name|int
name|minimumContentsLength
block|;
name|QSize
name|iconSize
block|;
name|uint
name|shownOnce
operator|:
literal|1
block|;
name|uint
name|autoCompletion
operator|:
literal|1
block|;
name|uint
name|duplicatesEnabled
operator|:
literal|1
block|;
name|uint
name|frame
operator|:
literal|1
block|;
name|uint
name|padding
operator|:
literal|26
block|;
name|int
name|maxVisibleItems
block|;
name|int
name|maxCount
block|;
name|int
name|modelColumn
block|;
name|bool
name|inserting
block|;
name|mutable
name|QSize
name|minimumSizeHint
block|;
name|mutable
name|QSize
name|sizeHint
block|;
name|QStyle
operator|::
name|StateFlag
name|arrowState
block|;
name|QStyle
operator|::
name|SubControl
name|hoverControl
block|;
name|QRect
name|hoverRect
block|;
name|QPersistentModelIndex
name|currentIndex
block|;
name|QPersistentModelIndex
name|root
block|;
name|Qt
operator|::
name|CaseSensitivity
name|autoCompletionCaseSensitivity
block|;
name|int
name|indexBeforeChange
block|;
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
name|QPointer
operator|<
name|QCompleter
operator|>
name|completer
block|;
endif|#
directive|endif
specifier|static
name|QPalette
name|viewContainerPalette
argument_list|(
argument|QComboBox *cmb
argument_list|)
block|{
return|return
name|cmb
operator|->
name|d_func
argument_list|()
operator|->
name|viewContainer
argument_list|()
operator|->
name|palette
argument_list|()
return|;
block|}
expr|}
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COMBOBOX
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOMBOBOX_P_H
end_comment
end_unit
