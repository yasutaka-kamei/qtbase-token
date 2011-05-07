begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMDIAREA_P_H
end_ifndef
begin_define
DECL|macro|QMDIAREA_P_H
define|#
directive|define
name|QMDIAREA_P_H
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
file|"qmdiarea.h"
end_include
begin_include
include|#
directive|include
file|"qmdisubwindow.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MDIAREA
end_ifndef
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QRect>
end_include
begin_include
include|#
directive|include
file|<QPoint>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qapplication.h>
end_include
begin_include
include|#
directive|include
file|<private/qmdisubwindow_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qabstractscrollarea_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QMdi
block|{
name|class
name|Rearranger
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|RegularTiler
block|,
name|SimpleCascader
block|,
name|IconTiler
block|}
enum|;
comment|// Rearranges widgets relative to domain.
name|virtual
name|void
name|rearrange
argument_list|(
name|QList
operator|<
name|QWidget
operator|*
operator|>
operator|&
name|widgets
argument_list|,
specifier|const
name|QRect
operator|&
name|domain
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|Type
name|type
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
operator|~
name|Rearranger
argument_list|()
block|{}
block|}
empty_stmt|;
name|class
name|RegularTiler
range|:
name|public
name|Rearranger
block|{
comment|// Rearranges widgets according to a regular tiling pattern
comment|// covering the entire domain.
comment|// Both positions and sizes may change.
name|void
name|rearrange
argument_list|(
argument|QList<QWidget *>&widgets
argument_list|,
argument|const QRect&domain
argument_list|)
specifier|const
block|;
specifier|inline
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|Rearranger
operator|::
name|RegularTiler
return|;
block|}
expr|}
block|;
name|class
name|SimpleCascader
operator|:
name|public
name|Rearranger
block|{
comment|// Rearranges widgets according to a simple, regular cascading pattern.
comment|// Widgets are resized to minimumSize.
comment|// Both positions and sizes may change.
name|void
name|rearrange
argument_list|(
argument|QList<QWidget *>&widgets
argument_list|,
argument|const QRect&domain
argument_list|)
specifier|const
block|;
specifier|inline
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|Rearranger
operator|::
name|SimpleCascader
return|;
block|}
expr|}
block|;
name|class
name|IconTiler
operator|:
name|public
name|Rearranger
block|{
comment|// Rearranges icons (assumed to be the same size) according to a regular
comment|// tiling pattern filling up the domain from the bottom.
comment|// Only positions may change.
name|void
name|rearrange
argument_list|(
argument|QList<QWidget *>&widgets
argument_list|,
argument|const QRect&domain
argument_list|)
specifier|const
block|;
specifier|inline
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|Rearranger
operator|::
name|IconTiler
return|;
block|}
expr|}
block|;
name|class
name|Placer
block|{
name|public
operator|:
comment|// Places the rectangle defined by 'size' relative to 'rects' and 'domain'.
comment|// Returns the position of the resulting rectangle.
name|virtual
name|QPoint
name|place
argument_list|(
argument|const QSize&size
argument_list|,
argument|const QList<QRect>&rects
argument_list|,
argument|const QRect&domain
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
operator|~
name|Placer
argument_list|()
block|{}
block|}
block|;
name|class
name|MinOverlapPlacer
operator|:
name|public
name|Placer
block|{
name|QPoint
name|place
argument_list|(
argument|const QSize&size
argument_list|,
argument|const QList<QRect>&rects
argument_list|,
argument|const QRect&domain
argument_list|)
specifier|const
block|;
specifier|static
name|int
name|accumulatedOverlap
argument_list|(
specifier|const
name|QRect
operator|&
name|source
argument_list|,
specifier|const
name|QList
operator|<
name|QRect
operator|>
operator|&
name|rects
argument_list|)
block|;
specifier|static
name|QRect
name|findMinOverlapRect
argument_list|(
specifier|const
name|QList
operator|<
name|QRect
operator|>
operator|&
name|source
argument_list|,
specifier|const
name|QList
operator|<
name|QRect
operator|>
operator|&
name|rects
argument_list|)
block|;
specifier|static
name|void
name|getCandidatePlacements
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QList
operator|<
name|QRect
operator|>
operator|&
name|rects
argument_list|,
specifier|const
name|QRect
operator|&
name|domain
argument_list|,
name|QList
operator|<
name|QRect
operator|>
operator|&
name|candidates
argument_list|)
block|;
specifier|static
name|QPoint
name|findBestPlacement
argument_list|(
specifier|const
name|QRect
operator|&
name|domain
argument_list|,
specifier|const
name|QList
operator|<
name|QRect
operator|>
operator|&
name|rects
argument_list|,
name|QList
operator|<
name|QRect
operator|>
operator|&
name|source
argument_list|)
block|;
specifier|static
name|void
name|findNonInsiders
argument_list|(
specifier|const
name|QRect
operator|&
name|domain
argument_list|,
name|QList
operator|<
name|QRect
operator|>
operator|&
name|source
argument_list|,
name|QList
operator|<
name|QRect
operator|>
operator|&
name|result
argument_list|)
block|;
specifier|static
name|void
name|findMaxOverlappers
argument_list|(
specifier|const
name|QRect
operator|&
name|domain
argument_list|,
specifier|const
name|QList
operator|<
name|QRect
operator|>
operator|&
name|source
argument_list|,
name|QList
operator|<
name|QRect
operator|>
operator|&
name|result
argument_list|)
block|; }
block|; }
comment|// namespace QMdi
DECL|variable|QMdiAreaTabBar
name|class
name|QMdiAreaTabBar
block|;
name|class
name|QMdiAreaPrivate
operator|:
name|public
name|QAbstractScrollAreaPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QMdiArea
argument_list|)
name|public
operator|:
name|QMdiAreaPrivate
argument_list|()
block|;
comment|// Variables.
name|QMdi
operator|::
name|Rearranger
operator|*
name|cascader
block|;
name|QMdi
operator|::
name|Rearranger
operator|*
name|regularTiler
block|;
name|QMdi
operator|::
name|Rearranger
operator|*
name|iconTiler
block|;
name|QMdi
operator|::
name|Placer
operator|*
name|placer
block|;
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
name|QRubberBand
operator|*
name|rubberBand
block|;
endif|#
directive|endif
name|QMdiAreaTabBar
operator|*
name|tabBar
block|;
name|QList
operator|<
name|QMdi
operator|::
name|Rearranger
operator|*
operator|>
name|pendingRearrangements
block|;
name|QList
operator|<
name|QPointer
operator|<
name|QMdiSubWindow
operator|>
expr|>
name|pendingPlacements
block|;
name|QList
operator|<
name|QPointer
operator|<
name|QMdiSubWindow
operator|>
expr|>
name|childWindows
block|;
name|QList
operator|<
name|int
operator|>
name|indicesToActivatedChildren
block|;
name|QPointer
operator|<
name|QMdiSubWindow
operator|>
name|active
block|;
name|QPointer
operator|<
name|QMdiSubWindow
operator|>
name|aboutToBecomeActive
block|;
name|QBrush
name|background
block|;
name|QMdiArea
operator|::
name|WindowOrder
name|activationOrder
block|;
name|QMdiArea
operator|::
name|AreaOptions
name|options
block|;
name|QMdiArea
operator|::
name|ViewMode
name|viewMode
block|;
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
name|bool
name|documentMode
block|;
name|bool
name|tabsClosable
block|;
name|bool
name|tabsMovable
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TABWIDGET
name|QTabWidget
operator|::
name|TabShape
name|tabShape
block|;
name|QTabWidget
operator|::
name|TabPosition
name|tabPosition
block|;
endif|#
directive|endif
name|bool
name|ignoreGeometryChange
block|;
name|bool
name|ignoreWindowStateChange
block|;
name|bool
name|isActivated
block|;
name|bool
name|isSubWindowsTiled
block|;
name|bool
name|showActiveWindowMaximized
block|;
name|bool
name|tileCalledFromResizeEvent
block|;
name|bool
name|updatesDisabledByUs
block|;
name|bool
name|inViewModeChange
block|;
name|int
name|indexToNextWindow
block|;
name|int
name|indexToPreviousWindow
block|;
name|int
name|indexToHighlighted
block|;
name|int
name|indexToLastActiveTab
block|;
name|int
name|resizeTimerId
block|;
name|int
name|tabToPreviousTimerId
block|;
comment|// Slots.
name|void
name|_q_deactivateAllWindows
argument_list|(
name|QMdiSubWindow
operator|*
name|aboutToActivate
operator|=
literal|0
argument_list|)
block|;
name|void
name|_q_processWindowStateChanged
argument_list|(
argument|Qt::WindowStates oldState
argument_list|,
argument|Qt::WindowStates newState
argument_list|)
block|;
name|void
name|_q_currentTabChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|_q_closeTab
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|_q_moveTab
argument_list|(
argument|int from
argument_list|,
argument|int to
argument_list|)
block|;
comment|// Functions.
name|void
name|appendChild
argument_list|(
name|QMdiSubWindow
operator|*
name|child
argument_list|)
block|;
name|void
name|place
argument_list|(
name|QMdi
operator|::
name|Placer
operator|*
name|placer
argument_list|,
name|QMdiSubWindow
operator|*
name|child
argument_list|)
block|;
name|void
name|rearrange
argument_list|(
name|QMdi
operator|::
name|Rearranger
operator|*
name|rearranger
argument_list|)
block|;
name|void
name|arrangeMinimizedSubWindows
argument_list|()
block|;
name|void
name|activateWindow
argument_list|(
name|QMdiSubWindow
operator|*
name|child
argument_list|)
block|;
name|void
name|activateCurrentWindow
argument_list|()
block|;
name|void
name|activateHighlightedWindow
argument_list|()
block|;
name|void
name|emitWindowActivated
argument_list|(
name|QMdiSubWindow
operator|*
name|child
argument_list|)
block|;
name|void
name|resetActiveWindow
argument_list|(
name|QMdiSubWindow
operator|*
name|child
operator|=
literal|0
argument_list|)
block|;
name|void
name|updateActiveWindow
argument_list|(
argument|int removedIndex
argument_list|,
argument|bool activeRemoved
argument_list|)
block|;
name|void
name|updateScrollBars
argument_list|()
block|;
name|void
name|internalRaise
argument_list|(
argument|QMdiSubWindow *child
argument_list|)
specifier|const
block|;
name|bool
name|scrollBarsEnabled
argument_list|()
specifier|const
block|;
name|bool
name|lastWindowAboutToBeDestroyed
argument_list|()
specifier|const
block|;
name|void
name|setChildActivationEnabled
argument_list|(
argument|bool enable = true
argument_list|,
argument|bool onlyNextActivationEvent = false
argument_list|)
specifier|const
block|;
name|QRect
name|resizeToMinimumTileSize
argument_list|(
argument|const QSize&minSubWindowSize
argument_list|,
argument|int subWindowCount
argument_list|)
block|;
name|void
name|scrollBarPolicyChanged
argument_list|(
name|Qt
operator|::
name|Orientation
argument_list|,
name|Qt
operator|::
name|ScrollBarPolicy
argument_list|)
block|;
comment|// reimp
name|QMdiSubWindow
operator|*
name|nextVisibleSubWindow
argument_list|(
argument|int increaseFactor
argument_list|,
argument|QMdiArea::WindowOrder
argument_list|,
argument|int removed = -
literal|1
argument_list|,
argument|int fromIndex = -
literal|1
argument_list|)
specifier|const
block|;
name|void
name|highlightNextSubWindow
argument_list|(
argument|int increaseFactor
argument_list|)
block|;
name|QList
operator|<
name|QMdiSubWindow
operator|*
operator|>
name|subWindowList
argument_list|(
argument|QMdiArea::WindowOrder
argument_list|,
argument|bool reversed = false
argument_list|)
specifier|const
block|;
name|void
name|disconnectSubWindow
argument_list|(
name|QObject
operator|*
name|subWindow
argument_list|)
block|;
name|void
name|setViewMode
argument_list|(
argument|QMdiArea::ViewMode mode
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
name|void
name|updateTabBarGeometry
argument_list|()
block|;
name|void
name|refreshTabBar
argument_list|()
block|;
endif|#
directive|endif
specifier|inline
name|void
name|startResizeTimer
argument_list|()
block|{
name|Q_Q
argument_list|(
name|QMdiArea
argument_list|)
block|;
if|if
condition|(
name|resizeTimerId
operator|>
literal|0
condition|)
name|q
operator|->
name|killTimer
argument_list|(
name|resizeTimerId
argument_list|)
expr_stmt|;
name|resizeTimerId
operator|=
name|q
operator|->
name|startTimer
argument_list|(
literal|200
argument_list|)
block|;     }
specifier|inline
name|void
name|startTabToPreviousTimer
argument_list|()
block|{
name|Q_Q
argument_list|(
name|QMdiArea
argument_list|)
block|;
if|if
condition|(
name|tabToPreviousTimerId
operator|>
literal|0
condition|)
name|q
operator|->
name|killTimer
argument_list|(
name|tabToPreviousTimerId
argument_list|)
expr_stmt|;
name|tabToPreviousTimerId
operator|=
name|q
operator|->
name|startTimer
argument_list|(
name|QApplication
operator|::
name|keyboardInputInterval
argument_list|()
argument_list|)
block|;     }
specifier|inline
name|bool
name|windowStaysOnTop
argument_list|(
argument|QMdiSubWindow *subWindow
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|subWindow
condition|)
return|return
name|false
return|;
return|return
name|subWindow
operator|->
name|windowFlags
argument_list|()
operator|&
name|Qt
operator|::
name|WindowStaysOnTopHint
return|;
block|}
specifier|inline
name|bool
name|isExplicitlyDeactivated
argument_list|(
name|QMdiSubWindow
operator|*
name|subWindow
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|subWindow
condition|)
return|return
name|true
return|;
return|return
name|subWindow
operator|->
name|d_func
argument_list|()
operator|->
name|isExplicitlyDeactivated
return|;
block|}
specifier|inline
name|void
name|setActive
argument_list|(
name|QMdiSubWindow
operator|*
name|subWindow
argument_list|,
name|bool
name|active
operator|=
name|true
argument_list|,
name|bool
name|changeFocus
operator|=
name|true
argument_list|)
decl|const
block|{
if|if
condition|(
name|subWindow
condition|)
name|subWindow
operator|->
name|d_func
argument_list|()
operator|->
name|setActive
argument_list|(
name|active
argument_list|,
name|changeFocus
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
specifier|inline
name|void
name|showRubberBandFor
parameter_list|(
name|QMdiSubWindow
modifier|*
name|subWindow
parameter_list|)
block|{
if|if
condition|(
operator|!
name|subWindow
operator|||
operator|!
name|rubberBand
condition|)
return|return;
name|rubberBand
operator|->
name|setGeometry
argument_list|(
name|subWindow
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|rubberBand
operator|->
name|raise
argument_list|()
expr_stmt|;
name|rubberBand
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|void
name|hideRubberBand
parameter_list|()
block|{
if|if
condition|(
name|rubberBand
operator|&&
name|rubberBand
operator|->
name|isVisible
argument_list|()
condition|)
name|rubberBand
operator|->
name|hide
argument_list|()
expr_stmt|;
name|indexToHighlighted
operator|=
operator|-
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
comment|// QT_NO_RUBBERBAND
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MDIAREA
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMDIAREA_P_H
end_comment
end_unit
