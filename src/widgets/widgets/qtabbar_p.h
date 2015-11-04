begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTABBAR_P_H
end_ifndef
begin_define
DECL|macro|QTABBAR_P_H
define|#
directive|define
name|QTABBAR_P_H
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
file|"qtabbar.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|<qicon.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbutton.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qvariantanimation.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
end_ifndef
begin_define
DECL|macro|ANIMATION_DURATION
define|#
directive|define
name|ANIMATION_DURATION
value|250
end_define
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QTabBarPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTabBar
argument_list|)
name|public
operator|:
name|QTabBarPrivate
argument_list|()
operator|:
name|currentIndex
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|pressedIndex
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|shape
argument_list|(
name|QTabBar
operator|::
name|RoundedNorth
argument_list|)
block|,
name|layoutDirty
argument_list|(
name|false
argument_list|)
block|,
name|drawBase
argument_list|(
name|true
argument_list|)
block|,
name|scrollOffset
argument_list|(
literal|0
argument_list|)
block|,
name|elideModeSetByUser
argument_list|(
name|false
argument_list|)
block|,
name|useScrollButtonsSetByUser
argument_list|(
name|false
argument_list|)
block|,
name|expanding
argument_list|(
name|true
argument_list|)
block|,
name|closeButtonOnTabs
argument_list|(
name|false
argument_list|)
block|,
name|selectionBehaviorOnRemove
argument_list|(
name|QTabBar
operator|::
name|SelectRightTab
argument_list|)
block|,
name|paintWithOffsets
argument_list|(
name|true
argument_list|)
block|,
name|movable
argument_list|(
name|false
argument_list|)
block|,
name|dragInProgress
argument_list|(
name|false
argument_list|)
block|,
name|documentMode
argument_list|(
name|false
argument_list|)
block|,
name|autoHide
argument_list|(
name|false
argument_list|)
block|,
name|changeCurrentOnDrag
argument_list|(
name|false
argument_list|)
block|,
name|switchTabCurrentIndex
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|switchTabTimerId
argument_list|(
literal|0
argument_list|)
block|,
name|movingTab
argument_list|(
literal|0
argument_list|)
ifdef|#
directive|ifdef
name|Q_DEAD_CODE_FROM_QT4_MAC
block|,
name|previousPressedIndex
argument_list|(
argument|-
literal|1
argument_list|)
endif|#
directive|endif
block|{}
name|int
name|currentIndex
block|;
name|int
name|pressedIndex
block|;
name|QTabBar
operator|::
name|Shape
name|shape
block|;
name|bool
name|layoutDirty
block|;
name|bool
name|drawBase
block|;
name|int
name|scrollOffset
block|;      struct
name|Tab
block|{
specifier|inline
name|Tab
argument_list|(
specifier|const
name|QIcon
operator|&
name|ico
argument_list|,
specifier|const
name|QString
operator|&
name|txt
argument_list|)
operator|:
name|enabled
argument_list|(
name|true
argument_list|)
block|,
name|shortcutId
argument_list|(
literal|0
argument_list|)
block|,
name|text
argument_list|(
name|txt
argument_list|)
block|,
name|icon
argument_list|(
name|ico
argument_list|)
block|,
name|leftWidget
argument_list|(
literal|0
argument_list|)
block|,
name|rightWidget
argument_list|(
literal|0
argument_list|)
block|,
name|lastTab
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|dragOffset
argument_list|(
literal|0
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
block|,
name|animation
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
comment|//QT_NO_ANIMATION
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Tab
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|&
name|other
operator|==
name|this
return|;
block|}
name|bool
name|enabled
block|;
name|int
name|shortcutId
block|;
name|QString
name|text
block|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|QString
name|toolTip
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|QString
name|whatsThis
block|;
endif|#
directive|endif
name|QIcon
name|icon
block|;
name|QRect
name|rect
block|;
name|QRect
name|minRect
block|;
name|QRect
name|maxRect
block|;
name|QColor
name|textColor
block|;
name|QVariant
name|data
block|;
name|QWidget
operator|*
name|leftWidget
block|;
name|QWidget
operator|*
name|rightWidget
block|;
name|int
name|lastTab
block|;
name|int
name|dragOffset
block|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
operator|~
name|Tab
argument_list|()
block|{
name|delete
name|animation
block|; }
expr|struct
name|TabBarAnimation
operator|:
name|public
name|QVariantAnimation
block|{
name|TabBarAnimation
argument_list|(
name|Tab
operator|*
name|t
argument_list|,
name|QTabBarPrivate
operator|*
name|_priv
argument_list|)
operator|:
name|tab
argument_list|(
name|t
argument_list|)
block|,
name|priv
argument_list|(
argument|_priv
argument_list|)
block|{
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
block|; }
name|void
name|updateCurrentValue
argument_list|(
argument|const QVariant&current
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|updateState
argument_list|(
argument|State
argument_list|,
argument|State newState
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
comment|//these are needed for the callbacks
name|Tab
operator|*
name|tab
block|;
name|QTabBarPrivate
operator|*
name|priv
block|;         }
operator|*
name|animation
block|;
name|void
name|startAnimation
argument_list|(
argument|QTabBarPrivate *priv
argument_list|,
argument|int duration
argument_list|)
block|{
if|if
condition|(
operator|!
name|priv
operator|->
name|isAnimated
argument_list|()
condition|)
block|{
name|priv
operator|->
name|moveTabFinished
argument_list|(
name|priv
operator|->
name|tabList
operator|.
name|indexOf
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|animation
condition|)
name|animation
operator|=
name|new
name|TabBarAnimation
argument_list|(
name|this
argument_list|,
name|priv
argument_list|)
expr_stmt|;
name|animation
operator|->
name|setStartValue
argument_list|(
name|dragOffset
argument_list|)
block|;
name|animation
operator|->
name|setEndValue
argument_list|(
literal|0
argument_list|)
block|;
name|animation
operator|->
name|setDuration
argument_list|(
name|duration
argument_list|)
block|;
name|animation
operator|->
name|start
argument_list|()
block|;         }
else|#
directive|else
name|void
name|startAnimation
argument_list|(
argument|QTabBarPrivate *priv
argument_list|,
argument|int duration
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|duration
argument_list|)
block|;
name|priv
operator|->
name|moveTabFinished
argument_list|(
name|priv
operator|->
name|tabList
operator|.
name|indexOf
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
block|; }
endif|#
directive|endif
comment|//QT_NO_ANIMATION
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|Tab
operator|>
name|tabList
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|calculateNewPosition
argument_list|(
name|int
name|from
argument_list|,
name|int
name|to
argument_list|,
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|slide
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|to
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|init
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|extraWidth
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|Tab
modifier|*
name|at
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|const
name|Tab
modifier|*
name|at
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|indexAtPos
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isAnimated
argument_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QTabBar
argument_list|)
block|;
return|return
name|q
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Widget_Animate
argument_list|,
literal|0
argument_list|,
name|q
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|bool
name|validIndex
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|index
operator|>=
literal|0
operator|&&
name|index
operator|<
name|tabList
operator|.
name|count
argument_list|()
return|;
block|}
end_decl_stmt
begin_function_decl
name|void
name|setCurrentNextEnabledIndex
parameter_list|(
name|int
name|offset
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QToolButton
modifier|*
name|rightB
decl_stmt|;
end_decl_stmt
begin_comment
comment|// right or bottom
end_comment
begin_decl_stmt
name|QToolButton
modifier|*
name|leftB
decl_stmt|;
end_decl_stmt
begin_comment
comment|// left or top
end_comment
begin_function_decl
name|void
name|_q_scrollTabs
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_closeTab
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|moveTab
parameter_list|(
name|int
name|index
parameter_list|,
name|int
name|offset
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|moveTabFinished
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QRect
name|hoverRect
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|refresh
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|layoutTabs
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|layoutWidgets
parameter_list|(
name|int
name|start
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|layoutTab
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updateMacBorderMetrics
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isTabInMacUnifiedToolbarArea
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setupMovableTab
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|autoHideTabs
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|makeVisible
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QSize
name|iconSize
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|TextElideMode
name|elideMode
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|elideModeSetByUser
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|useScrollButtons
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|useScrollButtonsSetByUser
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|expanding
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|closeButtonOnTabs
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QTabBar
operator|::
name|SelectionBehavior
name|selectionBehaviorOnRemove
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QPoint
name|dragStartPosition
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|paintWithOffsets
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|movable
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|dragInProgress
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|documentMode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|autoHide
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|changeCurrentOnDrag
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|switchTabCurrentIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|switchTabTimerId
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWidget
modifier|*
name|movingTab
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_DEAD_CODE_FROM_QT4_MAC
end_ifdef
begin_decl_stmt
name|int
name|previousPressedIndex
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// shared by tabwidget and qtabbar
end_comment
begin_function
specifier|static
name|void
name|initStyleBaseOption
parameter_list|(
name|QStyleOptionTabBarBase
modifier|*
name|optTabBase
parameter_list|,
name|QTabBar
modifier|*
name|tabbar
parameter_list|,
name|QSize
name|size
parameter_list|)
block|{
name|QStyleOptionTab
name|tabOverlap
decl_stmt|;
name|tabOverlap
operator|.
name|shape
operator|=
name|tabbar
operator|->
name|shape
argument_list|()
expr_stmt|;
name|int
name|overlap
init|=
name|tabbar
operator|->
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_TabBarBaseOverlap
argument_list|,
operator|&
name|tabOverlap
argument_list|,
name|tabbar
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|theParent
init|=
name|tabbar
operator|->
name|parentWidget
argument_list|()
decl_stmt|;
name|optTabBase
operator|->
name|init
argument_list|(
name|tabbar
argument_list|)
expr_stmt|;
name|optTabBase
operator|->
name|shape
operator|=
name|tabbar
operator|->
name|shape
argument_list|()
expr_stmt|;
name|optTabBase
operator|->
name|documentMode
operator|=
name|tabbar
operator|->
name|documentMode
argument_list|()
expr_stmt|;
if|if
condition|(
name|theParent
operator|&&
name|overlap
operator|>
literal|0
condition|)
block|{
name|QRect
name|rect
decl_stmt|;
switch|switch
condition|(
name|tabOverlap
operator|.
name|shape
condition|)
block|{
case|case
name|QTabBar
operator|::
name|RoundedNorth
case|:
case|case
name|QTabBar
operator|::
name|TriangularNorth
case|:
name|rect
operator|.
name|setRect
argument_list|(
literal|0
argument_list|,
name|size
operator|.
name|height
argument_list|()
operator|-
name|overlap
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|overlap
argument_list|)
expr_stmt|;
break|break;
case|case
name|QTabBar
operator|::
name|RoundedSouth
case|:
case|case
name|QTabBar
operator|::
name|TriangularSouth
case|:
name|rect
operator|.
name|setRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|overlap
argument_list|)
expr_stmt|;
break|break;
case|case
name|QTabBar
operator|::
name|RoundedEast
case|:
case|case
name|QTabBar
operator|::
name|TriangularEast
case|:
name|rect
operator|.
name|setRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|overlap
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QTabBar
operator|::
name|RoundedWest
case|:
case|case
name|QTabBar
operator|::
name|TriangularWest
case|:
name|rect
operator|.
name|setRect
argument_list|(
name|size
operator|.
name|width
argument_list|()
operator|-
name|overlap
argument_list|,
literal|0
argument_list|,
name|overlap
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
name|optTabBase
operator|->
name|rect
operator|=
name|rect
expr_stmt|;
block|}
block|}
end_function
begin_function_decl
name|void
name|killSwitchTabTimer
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
unit|};
name|class
name|CloseButton
range|:
name|public
name|QAbstractButton
block|{
name|Q_OBJECT
name|public
operator|:
name|CloseButton
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
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
block|{
return|return
name|sizeHint
argument_list|()
return|;
block|}
name|void
name|enterEvent
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|leaveEvent
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
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
begin_endif
endif|#
directive|endif
end_endif
end_unit
