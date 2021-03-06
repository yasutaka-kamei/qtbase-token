begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMENU_P_H
end_ifndef
begin_define
DECL|macro|QMENU_P_H
define|#
directive|define
name|QMENU_P_H
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
file|"QtWidgets/qmenubar.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformmenu.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_MENU
DECL|variable|QTornOffMenu
name|class
name|QTornOffMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEventLoop
name|class
name|QEventLoop
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_struct
DECL|struct|QWceMenuAction
struct|struct
name|QWceMenuAction
block|{
DECL|member|command
name|uint
name|command
decl_stmt|;
DECL|member|action
name|QPointer
operator|<
name|QAction
operator|>
name|action
expr_stmt|;
DECL|member|menuHandle
name|HMENU
name|menuHandle
decl_stmt|;
DECL|function|QWceMenuAction
name|QWceMenuAction
argument_list|()
operator|:
name|menuHandle
argument_list|(
literal|0
argument_list|)
operator|,
name|command
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QSetValueOnDestroy
block|{
name|public
operator|:
name|QSetValueOnDestroy
argument_list|(
argument|T&toSet
argument_list|,
argument|T value
argument_list|)
operator|:
name|toSet
argument_list|(
name|toSet
argument_list|)
block|,
name|value
argument_list|(
argument|value
argument_list|)
block|{ }
operator|~
name|QSetValueOnDestroy
argument_list|()
block|{
name|toSet
operator|=
name|value
block|; }
name|private
operator|:
name|T
operator|&
name|toSet
block|;
name|T
name|value
block|; }
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QMenuSloppyState
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QMenuSloppyState
argument_list|)
name|public
label|:
name|QMenuSloppyState
argument_list|()
operator|:
name|m_menu
argument_list|(
name|Q_NULLPTR
argument_list|)
operator|,
name|m_enabled
argument_list|(
name|false
argument_list|)
operator|,
name|m_uni_directional
argument_list|(
name|false
argument_list|)
operator|,
name|m_select_other_actions
argument_list|(
name|false
argument_list|)
operator|,
name|m_first_mouse
argument_list|(
name|true
argument_list|)
operator|,
name|m_init_guard
argument_list|(
name|false
argument_list|)
operator|,
name|m_uni_dir_discarded_count
argument_list|(
literal|0
argument_list|)
operator|,
name|m_uni_dir_fail_at_count
argument_list|(
literal|0
argument_list|)
operator|,
name|m_timeout
argument_list|(
literal|0
argument_list|)
operator|,
name|m_reset_action
argument_list|(
name|Q_NULLPTR
argument_list|)
operator|,
name|m_origin_action
argument_list|(
name|Q_NULLPTR
argument_list|)
operator|,
name|m_parent
argument_list|(
argument|Q_NULLPTR
argument_list|)
block|{ }
operator|~
name|QMenuSloppyState
argument_list|()
block|{
name|reset
argument_list|()
block|; }
name|void
name|initialize
argument_list|(
argument|QMenu *menu
argument_list|)
block|{
name|m_menu
operator|=
name|menu
block|;
name|m_uni_directional
operator|=
name|menu
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Menu_SubMenuUniDirection
argument_list|,
literal|0
argument_list|,
name|menu
argument_list|)
block|;
name|m_uni_dir_fail_at_count
operator|=
name|menu
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Menu_SubMenuUniDirectionFailCount
argument_list|,
literal|0
argument_list|,
name|menu
argument_list|)
block|;
name|m_select_other_actions
operator|=
name|menu
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Menu_SubMenuSloppySelectOtherActions
argument_list|,
literal|0
argument_list|,
name|menu
argument_list|)
block|;
name|m_timeout
operator|=
name|menu
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Menu_SubMenuSloppyCloseTimeout
argument_list|)
block|;
name|m_discard_state_when_entering_parent
operator|=
name|menu
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Menu_SubMenuResetWhenReenteringParent
argument_list|)
block|;
name|m_dont_start_time_on_leave
operator|=
name|menu
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Menu_SubMenuDontStartSloppyOnLeave
argument_list|)
block|;
name|reset
argument_list|()
block|;     }
name|void
name|reset
argument_list|()
expr_stmt|;
name|bool
name|enabled
argument_list|()
specifier|const
block|{
return|return
name|m_enabled
return|;
block|}
name|void
name|setResetAction
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
block|{
name|m_reset_action
operator|=
name|action
expr_stmt|;
block|}
enum|enum
name|MouseEventResult
block|{
name|EventIsProcessed
block|,
name|EventShouldBePropagated
block|,
name|EventDiscardsSloppyState
block|}
enum|;
name|void
name|startTimer
parameter_list|()
block|{
if|if
condition|(
name|m_enabled
condition|)
name|m_time
operator|.
name|start
argument_list|(
name|m_timeout
argument_list|,
name|m_menu
argument_list|)
expr_stmt|;
block|}
name|void
name|startTimerIfNotRunning
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_time
operator|.
name|isActive
argument_list|()
condition|)
name|startTimer
argument_list|()
expr_stmt|;
block|}
name|void
name|stopTimer
parameter_list|()
block|{
name|m_time
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
name|void
name|enter
parameter_list|()
function_decl|;
name|void
name|childEnter
parameter_list|()
block|{
name|stopTimer
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_parent
condition|)
name|m_parent
operator|->
name|childEnter
argument_list|()
expr_stmt|;
block|}
name|void
name|leave
parameter_list|()
block|{
if|if
condition|(
name|m_dont_start_time_on_leave
condition|)
return|return;
if|if
condition|(
name|m_parent
condition|)
name|m_parent
operator|->
name|childLeave
argument_list|()
expr_stmt|;
name|startTimer
argument_list|()
expr_stmt|;
block|}
name|void
name|childLeave
parameter_list|()
function_decl|;
specifier|static
name|float
name|slope
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p1
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p2
parameter_list|)
block|{
specifier|const
name|QPointF
name|slope
init|=
name|p2
operator|-
name|p1
decl_stmt|;
if|if
condition|(
name|slope
operator|.
name|x
argument_list|()
operator|==
literal|0
condition|)
return|return
literal|9999
return|;
return|return
name|slope
operator|.
name|y
argument_list|()
operator|/
name|slope
operator|.
name|x
argument_list|()
return|;
block|}
name|bool
name|checkSlope
parameter_list|(
name|qreal
name|oldS
parameter_list|,
name|qreal
name|newS
parameter_list|,
name|bool
name|wantSteeper
parameter_list|)
block|{
if|if
condition|(
name|wantSteeper
condition|)
return|return
name|oldS
operator|<=
name|newS
return|;
return|return
name|newS
operator|<=
name|oldS
return|;
block|}
name|MouseEventResult
name|processMouseEvent
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|mousePos
parameter_list|,
name|QAction
modifier|*
name|resetAction
parameter_list|,
name|QAction
modifier|*
name|currentAction
parameter_list|)
block|{
if|if
condition|(
name|m_parent
condition|)
name|m_parent
operator|->
name|stopTimer
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_enabled
condition|)
return|return
name|EventShouldBePropagated
return|;
if|if
condition|(
operator|!
name|m_time
operator|.
name|isActive
argument_list|()
condition|)
name|startTimer
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_sub_menu
condition|)
block|{
name|reset
argument_list|()
expr_stmt|;
return|return
name|EventShouldBePropagated
return|;
block|}
name|QSetValueOnDestroy
operator|<
name|bool
operator|>
name|setFirstMouse
argument_list|(
name|m_first_mouse
argument_list|,
name|false
argument_list|)
expr_stmt|;
name|QSetValueOnDestroy
operator|<
name|QPointF
operator|>
name|setPreviousPoint
argument_list|(
name|m_previous_point
argument_list|,
name|mousePos
argument_list|)
expr_stmt|;
if|if
condition|(
name|resetAction
operator|&&
name|resetAction
operator|->
name|isSeparator
argument_list|()
condition|)
name|m_reset_action
operator|=
name|Q_NULLPTR
expr_stmt|;
else|else
block|{
name|m_reset_action
operator|=
name|resetAction
expr_stmt|;
block|}
if|if
condition|(
name|m_action_rect
operator|.
name|contains
argument_list|(
name|mousePos
argument_list|)
condition|)
block|{
name|startTimer
argument_list|()
expr_stmt|;
return|return
name|currentAction
operator|==
name|m_menu
operator|->
name|menuAction
argument_list|()
condition|?
name|EventIsProcessed
else|:
name|EventShouldBePropagated
return|;
block|}
if|if
condition|(
name|m_uni_directional
operator|&&
operator|!
name|m_first_mouse
operator|&&
name|resetAction
operator|!=
name|m_origin_action
condition|)
block|{
name|bool
name|left_to_right
init|=
name|m_menu
operator|->
name|layoutDirection
argument_list|()
operator|==
name|Qt
operator|::
name|LeftToRight
decl_stmt|;
name|QRect
name|sub_menu_rect
init|=
name|m_sub_menu
operator|->
name|geometry
argument_list|()
decl_stmt|;
name|QPoint
name|sub_menu_top
init|=
name|left_to_right
condition|?
name|sub_menu_rect
operator|.
name|topLeft
argument_list|()
else|:
name|sub_menu_rect
operator|.
name|topRight
argument_list|()
decl_stmt|;
name|QPoint
name|sub_menu_bottom
init|=
name|left_to_right
condition|?
name|sub_menu_rect
operator|.
name|bottomLeft
argument_list|()
else|:
name|sub_menu_rect
operator|.
name|bottomRight
argument_list|()
decl_stmt|;
name|qreal
name|prev_slope_top
init|=
name|slope
argument_list|(
name|m_previous_point
argument_list|,
name|sub_menu_top
argument_list|)
decl_stmt|;
name|qreal
name|prev_slope_bottom
init|=
name|slope
argument_list|(
name|m_previous_point
argument_list|,
name|sub_menu_bottom
argument_list|)
decl_stmt|;
name|qreal
name|current_slope_top
init|=
name|slope
argument_list|(
name|mousePos
argument_list|,
name|sub_menu_top
argument_list|)
decl_stmt|;
name|qreal
name|current_slope_bottom
init|=
name|slope
argument_list|(
name|mousePos
argument_list|,
name|sub_menu_bottom
argument_list|)
decl_stmt|;
name|bool
name|slopeTop
init|=
name|checkSlope
argument_list|(
name|prev_slope_top
argument_list|,
name|current_slope_top
argument_list|,
name|sub_menu_top
operator|.
name|y
argument_list|()
operator|<
name|mousePos
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|bool
name|slopeBottom
init|=
name|checkSlope
argument_list|(
name|prev_slope_bottom
argument_list|,
name|current_slope_bottom
argument_list|,
name|sub_menu_bottom
operator|.
name|y
argument_list|()
operator|>
name|mousePos
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|bool
name|rightDirection
init|=
name|false
decl_stmt|;
name|int
name|mouseDir
init|=
name|m_previous_point
operator|.
name|y
argument_list|()
operator|-
name|mousePos
operator|.
name|y
argument_list|()
decl_stmt|;
if|if
condition|(
name|mouseDir
operator|>=
literal|0
condition|)
block|{
name|rightDirection
operator|=
name|rightDirection
operator|||
name|slopeTop
expr_stmt|;
block|}
if|if
condition|(
name|mouseDir
operator|<=
literal|0
condition|)
block|{
name|rightDirection
operator|=
name|rightDirection
operator|||
name|slopeBottom
expr_stmt|;
block|}
if|if
condition|(
name|m_uni_dir_discarded_count
operator|>=
name|m_uni_dir_fail_at_count
operator|&&
operator|!
name|rightDirection
condition|)
block|{
name|m_uni_dir_discarded_count
operator|=
literal|0
expr_stmt|;
return|return
name|EventDiscardsSloppyState
return|;
block|}
if|if
condition|(
operator|!
name|rightDirection
condition|)
name|m_uni_dir_discarded_count
operator|++
expr_stmt|;
else|else
name|m_uni_dir_discarded_count
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|m_select_other_actions
condition|?
name|EventShouldBePropagated
else|:
name|EventIsProcessed
return|;
block|}
name|void
name|setSubMenuPopup
parameter_list|(
specifier|const
name|QRect
modifier|&
name|actionRect
parameter_list|,
name|QAction
modifier|*
name|resetAction
parameter_list|,
name|QMenu
modifier|*
name|subMenu
parameter_list|)
function_decl|;
name|bool
name|hasParentActiveDelayTimer
argument_list|()
specifier|const
expr_stmt|;
name|void
name|timeout
parameter_list|()
function_decl|;
name|int
name|timeForTimeout
argument_list|()
specifier|const
block|{
return|return
name|m_timeout
return|;
block|}
name|bool
name|isTimerId
argument_list|(
name|int
name|timerId
argument_list|)
decl|const
block|{
return|return
name|m_time
operator|.
name|timerId
argument_list|()
operator|==
name|timerId
return|;
block|}
name|QMenu
operator|*
name|subMenu
argument_list|()
specifier|const
block|{
return|return
name|m_sub_menu
return|;
block|}
name|private
label|:
name|QMenu
modifier|*
name|m_menu
decl_stmt|;
name|bool
name|m_enabled
decl_stmt|;
name|bool
name|m_uni_directional
decl_stmt|;
name|bool
name|m_select_other_actions
decl_stmt|;
name|bool
name|m_first_mouse
decl_stmt|;
name|bool
name|m_init_guard
decl_stmt|;
name|bool
name|m_discard_state_when_entering_parent
decl_stmt|;
name|bool
name|m_dont_start_time_on_leave
decl_stmt|;
name|short
name|m_uni_dir_discarded_count
decl_stmt|;
name|short
name|m_uni_dir_fail_at_count
decl_stmt|;
name|short
name|m_timeout
decl_stmt|;
name|QBasicTimer
name|m_time
decl_stmt|;
name|QAction
modifier|*
name|m_reset_action
decl_stmt|;
name|QAction
modifier|*
name|m_origin_action
decl_stmt|;
name|QRectF
name|m_action_rect
decl_stmt|;
name|QPointF
name|m_previous_point
decl_stmt|;
name|QPointer
operator|<
name|QMenu
operator|>
name|m_sub_menu
expr_stmt|;
name|QMenuSloppyState
modifier|*
name|m_parent
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QMenuPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QMenu
argument_list|)
name|public
operator|:
name|QMenuPrivate
argument_list|()
operator|:
name|itemsDirty
argument_list|(
literal|0
argument_list|)
block|,
name|maxIconWidth
argument_list|(
literal|0
argument_list|)
block|,
name|tabWidth
argument_list|(
literal|0
argument_list|)
block|,
name|ncols
argument_list|(
literal|0
argument_list|)
block|,
name|collapsibleSeparators
argument_list|(
name|true
argument_list|)
block|,
name|toolTipsVisible
argument_list|(
name|false
argument_list|)
block|,
name|activationRecursionGuard
argument_list|(
name|false
argument_list|)
block|,
name|delayedPopupGuard
argument_list|(
name|false
argument_list|)
block|,
name|hasReceievedEnter
argument_list|(
name|false
argument_list|)
block|,
name|hasHadMouse
argument_list|(
literal|0
argument_list|)
block|,
name|aboutToHide
argument_list|(
literal|0
argument_list|)
block|,
name|motions
argument_list|(
literal|0
argument_list|)
block|,
name|currentAction
argument_list|(
literal|0
argument_list|)
block|,
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|selectAction
argument_list|(
literal|0
argument_list|)
block|,
name|cancelAction
argument_list|(
literal|0
argument_list|)
block|,
endif|#
directive|endif
name|scroll
argument_list|(
literal|0
argument_list|)
block|,
name|eventLoop
argument_list|(
literal|0
argument_list|)
block|,
name|tearoff
argument_list|(
literal|0
argument_list|)
block|,
name|tornoff
argument_list|(
literal|0
argument_list|)
block|,
name|tearoffHighlighted
argument_list|(
literal|0
argument_list|)
block|,
name|hasCheckableItems
argument_list|(
literal|0
argument_list|)
block|,
name|doChildEffects
argument_list|(
name|false
argument_list|)
block|,
name|platformMenu
argument_list|(
literal|0
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MENUBAR
argument_list|)
block|,
name|wce_menu
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{ }
operator|~
name|QMenuPrivate
argument_list|()
block|{
name|delete
name|scroll
block|;
if|if
condition|(
operator|!
name|platformMenu
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|platformMenu
operator|->
name|parent
argument_list|()
condition|)
name|delete
name|platformMenu
operator|.
name|data
parameter_list|()
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MENUBAR
argument_list|)
name|delete
name|wce_menu
block|;
endif|#
directive|endif
block|}
name|void
name|init
argument_list|()
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setPlatformMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|syncPlatformMenu
parameter_list|()
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_OSX
end_ifdef
begin_function_decl
name|void
name|moveWidgetToPlatformItem
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|QPlatformMenuItem
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
name|QMenuPrivate
modifier|*
name|get
parameter_list|(
name|QMenu
modifier|*
name|m
parameter_list|)
block|{
return|return
name|m
operator|->
name|d_func
argument_list|()
return|;
block|}
end_function
begin_expr_stmt
name|int
name|scrollerHeight
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|//item calculations
end_comment
begin_decl_stmt
name|mutable
name|uint
name|itemsDirty
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|uint
name|maxIconWidth
decl_stmt|,
name|tabWidth
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|actionRect
argument_list|(
name|QAction
operator|*
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|mutable
name|QVector
operator|<
name|QRect
operator|>
name|actionRects
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|mutable
name|QHash
operator|<
name|QAction
operator|*
operator|,
name|QWidget
operator|*
operator|>
name|widgetItems
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|void
name|updateActionRects
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|updateActionRects
argument_list|(
specifier|const
name|QRect
operator|&
name|screen
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|popupGeometry
argument_list|(
specifier|const
name|QWidget
operator|*
name|widget
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|popupGeometry
argument_list|(
name|int
name|screen
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|uint
name|ncols
range|:
literal|4
decl_stmt|;
end_decl_stmt
begin_comment
comment|//4 bits is probably plenty
end_comment
begin_decl_stmt
name|uint
name|collapsibleSeparators
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|toolTipsVisible
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QSize
name|adjustMenuSizeForScreen
parameter_list|(
specifier|const
name|QRect
modifier|&
name|screen
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|getLastVisibleAction
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|activationRecursionGuard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|delayedPopupGuard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|hasReceievedEnter
decl_stmt|;
end_decl_stmt
begin_comment
comment|//selection
end_comment
begin_decl_stmt
specifier|static
name|QMenu
modifier|*
name|mouseDown
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPoint
name|mousePopupPos
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|hasHadMouse
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|aboutToHide
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|motions
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|mousePopupDelay
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|currentAction
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
end_ifdef
begin_decl_stmt
name|QAction
modifier|*
name|selectAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|cancelAction
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_struct
struct|struct
name|DelayState
block|{
name|DelayState
argument_list|()
operator|:
name|parent
argument_list|(
literal|0
argument_list|)
operator|,
name|action
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|initialize
argument_list|(
argument|QMenu *parent
argument_list|)
block|{
name|this
operator|->
name|parent
operator|=
name|parent
block|;         }
name|void
name|start
argument_list|(
argument|int timeout
argument_list|,
argument|QAction *toStartAction
argument_list|)
block|{
if|if
condition|(
name|timer
operator|.
name|isActive
argument_list|()
operator|&&
name|toStartAction
operator|==
name|action
condition|)
return|return;
name|action
operator|=
name|toStartAction
expr_stmt|;
name|timer
operator|.
name|start
argument_list|(
name|timeout
argument_list|,
name|parent
argument_list|)
expr_stmt|;
block|}
name|void
name|stop
argument_list|()
block|{
name|action
operator|=
literal|0
expr_stmt|;
name|timer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
name|QMenu
modifier|*
name|parent
struct|;
end_struct
begin_decl_stmt
name|QBasicTimer
name|timer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|action
decl_stmt|;
end_decl_stmt
begin_empty_stmt
unit|} delayState
empty_stmt|;
end_empty_stmt
begin_enum
enum|enum
name|SelectionReason
block|{
name|SelectedFromKeyboard
block|,
name|SelectedFromElsewhere
block|}
enum|;
end_enum
begin_expr_stmt
name|QWidget
operator|*
name|topCausedWidget
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QAction
modifier|*
name|actionAt
argument_list|(
name|QPoint
name|p
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setFirstActionActive
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setCurrentAction
parameter_list|(
name|QAction
modifier|*
parameter_list|,
name|int
name|popup
init|=
operator|-
literal|1
parameter_list|,
name|SelectionReason
name|reason
init|=
name|SelectedFromElsewhere
parameter_list|,
name|bool
name|activateFirst
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|popupAction
parameter_list|(
name|QAction
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setSyncAction
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//scrolling support
end_comment
begin_struct
struct|struct
name|QMenuScroller
block|{
enum|enum
name|ScrollLocation
block|{
name|ScrollStay
block|,
name|ScrollBottom
block|,
name|ScrollTop
block|,
name|ScrollCenter
block|}
enum|;
enum|enum
name|ScrollDirection
block|{
name|ScrollNone
init|=
literal|0
block|,
name|ScrollUp
init|=
literal|0x01
block|,
name|ScrollDown
init|=
literal|0x02
block|}
enum|;
name|uint
name|scrollFlags
range|:
literal|2
decl_stmt|,
name|scrollDirection
range|:
literal|2
decl_stmt|;
name|int
name|scrollOffset
decl_stmt|;
name|QBasicTimer
name|scrollTimer
decl_stmt|;
name|QMenuScroller
argument_list|()
operator|:
name|scrollFlags
argument_list|(
name|ScrollNone
argument_list|)
operator|,
name|scrollDirection
argument_list|(
name|ScrollNone
argument_list|)
operator|,
name|scrollOffset
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|QMenuScroller
argument_list|()
block|{ }
block|}
modifier|*
name|scroll
struct|;
end_struct
begin_decl_stmt
name|void
name|scrollMenu
argument_list|(
name|QMenuScroller
operator|::
name|ScrollLocation
name|location
argument_list|,
name|bool
name|active
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|scrollMenu
argument_list|(
name|QMenuScroller
operator|::
name|ScrollDirection
name|direction
argument_list|,
name|bool
name|page
operator|=
name|false
argument_list|,
name|bool
name|active
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|scrollMenu
argument_list|(
name|QAction
operator|*
name|action
argument_list|,
name|QMenuScroller
operator|::
name|ScrollLocation
name|location
argument_list|,
name|bool
name|active
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//synchronous operation (ie exec())
end_comment
begin_decl_stmt
name|QEventLoop
modifier|*
name|eventLoop
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QAction
operator|>
name|syncAction
expr_stmt|;
end_expr_stmt
begin_comment
comment|//search buffer
end_comment
begin_decl_stmt
name|QString
name|searchBuffer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicTimer
name|searchBufferTimer
decl_stmt|;
end_decl_stmt
begin_comment
comment|//passing of mouse events up the parent hierarchy
end_comment
begin_expr_stmt
name|QPointer
operator|<
name|QMenu
operator|>
name|activeMenu
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|mouseEventTaken
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//used to walk up the popup list
end_comment
begin_struct
struct|struct
name|QMenuCaused
block|{
name|QPointer
operator|<
name|QWidget
operator|>
name|widget
expr_stmt|;
name|QPointer
operator|<
name|QAction
operator|>
name|action
expr_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|virtual
name|QVector
operator|<
name|QPointer
operator|<
name|QWidget
operator|>
expr|>
name|calcCausedStack
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QMenuCaused
name|causedPopup
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|hideUpToMenuBar
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hideMenu
parameter_list|(
name|QMenu
modifier|*
name|menu
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//index mappings
end_comment
begin_decl_stmt
specifier|inline
name|QAction
modifier|*
name|actionAt
argument_list|(
name|int
name|i
argument_list|)
decl|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|int
name|indexOf
argument_list|(
name|QAction
operator|*
name|act
argument_list|)
decl|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|indexOf
argument_list|(
name|act
argument_list|)
return|;
block|}
end_decl_stmt
begin_comment
comment|//tear off support
end_comment
begin_decl_stmt
name|uint
name|tearoff
range|:
literal|1
decl_stmt|,
name|tornoff
range|:
literal|1
decl_stmt|,
name|tearoffHighlighted
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QTornOffMenu
operator|>
name|tornPopup
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|mutable
name|bool
name|hasCheckableItems
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QMenuSloppyState
name|sloppyState
decl_stmt|;
end_decl_stmt
begin_comment
comment|//default action
end_comment
begin_expr_stmt
name|QPointer
operator|<
name|QAction
operator|>
name|defaultAction
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QAction
modifier|*
name|menuAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|defaultMenuAction
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setOverrideMenuAction
parameter_list|(
name|QAction
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_overrideMenuActionDestroyed
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//firing of events
end_comment
begin_decl_stmt
name|void
name|activateAction
argument_list|(
name|QAction
operator|*
argument_list|,
name|QAction
operator|::
name|ActionEvent
argument_list|,
name|bool
name|self
operator|=
name|true
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|activateCausedStack
argument_list|(
specifier|const
name|QVector
operator|<
name|QPointer
operator|<
name|QWidget
operator|>
expr|>
operator|&
argument_list|,
name|QAction
operator|*
argument_list|,
name|QAction
operator|::
name|ActionEvent
argument_list|,
name|bool
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|_q_actionTriggered
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_actionHovered
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_platformMenuAboutToShow
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|hasMouseMoved
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|globalPos
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updateLayoutDirection
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//menu fading/scrolling effects
end_comment
begin_decl_stmt
name|bool
name|doChildEffects
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QPlatformMenu
operator|>
name|platformMenu
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QAction
operator|>
name|actionAboutToTrigger
expr_stmt|;
end_expr_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MENUBAR
argument_list|)
end_if
begin_struct
struct|struct
name|QWceMenuPrivate
block|{
name|QList
operator|<
name|QWceMenuAction
operator|*
operator|>
name|actionItems
expr_stmt|;
name|HMENU
name|menuHandle
decl_stmt|;
name|QWceMenuPrivate
argument_list|()
expr_stmt|;
operator|~
name|QWceMenuPrivate
argument_list|()
expr_stmt|;
name|void
name|addAction
parameter_list|(
name|QAction
modifier|*
parameter_list|,
name|QWceMenuAction
modifier|*
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|addAction
parameter_list|(
name|QWceMenuAction
modifier|*
parameter_list|,
name|QWceMenuAction
modifier|*
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|syncAction
parameter_list|(
name|QWceMenuAction
modifier|*
parameter_list|)
function_decl|;
specifier|inline
name|void
name|syncAction
parameter_list|(
name|QAction
modifier|*
name|a
parameter_list|)
block|{
name|syncAction
argument_list|(
name|findAction
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|removeAction
parameter_list|(
name|QWceMenuAction
modifier|*
parameter_list|)
function_decl|;
name|void
name|rebuild
parameter_list|()
function_decl|;
specifier|inline
name|void
name|removeAction
parameter_list|(
name|QAction
modifier|*
name|a
parameter_list|)
block|{
name|removeAction
argument_list|(
name|findAction
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QWceMenuAction
modifier|*
name|findAction
parameter_list|(
name|QAction
modifier|*
name|a
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|actionItems
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QWceMenuAction
modifier|*
name|act
init|=
name|actionItems
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|a
operator|==
name|act
operator|->
name|action
condition|)
return|return
name|act
return|;
block|}
return|return
literal|0
return|;
block|}
block|}
modifier|*
name|wce_menu
struct|;
end_struct
begin_function_decl
name|HMENU
name|wceMenu
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QAction
modifier|*
name|wceCommands
parameter_list|(
name|uint
name|command
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QPointer
operator|<
name|QWidget
operator|>
name|noReplayFor
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|static
name|QPointer
operator|<
name|QMenu
operator|>
name|previousMouseMenu
expr_stmt|;
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENU
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMENU_P_H
end_comment
end_unit
