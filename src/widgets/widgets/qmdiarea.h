begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMDIAREA_H
end_ifndef
begin_define
DECL|macro|QMDIAREA_H
define|#
directive|define
name|QMDIAREA_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractscrollarea.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qtabwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_MDIAREA
DECL|variable|QMdiSubWindow
name|class
name|QMdiSubWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMdiAreaPrivate
name|class
name|QMdiAreaPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QMdiArea
range|:
name|public
name|QAbstractScrollArea
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|ViewMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QBrush background READ background WRITE setBackground
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|WindowOrder activationOrder READ activationOrder WRITE setActivationOrder
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ViewMode viewMode READ viewMode WRITE setViewMode
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
name|Q_PROPERTY
argument_list|(
argument|bool documentMode READ documentMode WRITE setDocumentMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tabsClosable READ tabsClosable WRITE setTabsClosable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tabsMovable READ tabsMovable WRITE setTabsMovable
argument_list|)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TABWIDGET
name|Q_PROPERTY
argument_list|(
argument|QTabWidget::TabShape tabShape READ tabShape WRITE setTabShape
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QTabWidget::TabPosition tabPosition READ tabPosition WRITE setTabPosition
argument_list|)
endif|#
directive|endif
name|Q_ENUMS
argument_list|(
argument|WindowOrder
argument_list|)
name|public
operator|:
expr|enum
name|AreaOption
block|{
name|DontMaximizeSubWindowOnActivation
operator|=
literal|0x1
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|AreaOptions
argument_list|,
name|AreaOption
argument_list|)
expr|enum
name|WindowOrder
block|{
name|CreationOrder
block|,
name|StackingOrder
block|,
name|ActivationHistoryOrder
block|}
block|;      enum
name|ViewMode
block|{
name|SubWindowView
block|,
name|TabbedView
block|}
block|;
name|QMdiArea
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QMdiArea
argument_list|()
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|QMdiSubWindow
operator|*
name|currentSubWindow
argument_list|()
specifier|const
block|;
name|QMdiSubWindow
operator|*
name|activeSubWindow
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QMdiSubWindow
operator|*
operator|>
name|subWindowList
argument_list|(
argument|WindowOrder order = CreationOrder
argument_list|)
specifier|const
block|;
name|QMdiSubWindow
operator|*
name|addSubWindow
argument_list|(
argument|QWidget *widget
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
name|void
name|removeSubWindow
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QBrush
name|background
argument_list|()
specifier|const
block|;
name|void
name|setBackground
argument_list|(
specifier|const
name|QBrush
operator|&
name|background
argument_list|)
block|;
name|WindowOrder
name|activationOrder
argument_list|()
specifier|const
block|;
name|void
name|setActivationOrder
argument_list|(
argument|WindowOrder order
argument_list|)
block|;
name|void
name|setOption
argument_list|(
argument|AreaOption option
argument_list|,
argument|bool on = true
argument_list|)
block|;
name|bool
name|testOption
argument_list|(
argument|AreaOption opton
argument_list|)
specifier|const
block|;
name|void
name|setViewMode
argument_list|(
argument|ViewMode mode
argument_list|)
block|;
name|ViewMode
name|viewMode
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
name|bool
name|documentMode
argument_list|()
specifier|const
block|;
name|void
name|setDocumentMode
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setTabsClosable
argument_list|(
argument|bool closable
argument_list|)
block|;
name|bool
name|tabsClosable
argument_list|()
specifier|const
block|;
name|void
name|setTabsMovable
argument_list|(
argument|bool movable
argument_list|)
block|;
name|bool
name|tabsMovable
argument_list|()
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TABWIDGET
name|void
name|setTabShape
argument_list|(
argument|QTabWidget::TabShape shape
argument_list|)
block|;
name|QTabWidget
operator|::
name|TabShape
name|tabShape
argument_list|()
specifier|const
block|;
name|void
name|setTabPosition
argument_list|(
argument|QTabWidget::TabPosition position
argument_list|)
block|;
name|QTabWidget
operator|::
name|TabPosition
name|tabPosition
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|subWindowActivated
argument_list|(
name|QMdiSubWindow
operator|*
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setActiveSubWindow
argument_list|(
name|QMdiSubWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|tileSubWindows
argument_list|()
block|;
name|void
name|cascadeSubWindows
argument_list|()
block|;
name|void
name|closeActiveSubWindow
argument_list|()
block|;
name|void
name|closeAllSubWindows
argument_list|()
block|;
name|void
name|activateNextSubWindow
argument_list|()
block|;
name|void
name|activatePreviousSubWindow
argument_list|()
block|;
name|protected
name|Q_SLOTS
operator|:
name|void
name|setupViewport
argument_list|(
name|QWidget
operator|*
name|viewport
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|paintEvent
argument_list|)
block|;
name|void
name|childEvent
argument_list|(
name|QChildEvent
operator|*
name|childEvent
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|resizeEvent
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
name|showEvent
argument_list|(
name|QShowEvent
operator|*
name|showEvent
argument_list|)
block|;
name|bool
name|viewportEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QMdiArea
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QMdiArea
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_deactivateAllWindows()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_processWindowStateChanged(Qt::WindowStates, Qt::WindowStates)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_currentTabChanged(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_closeTab(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_moveTab(int, int)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QMdiArea::AreaOptions
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MDIAREA
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMDIAREA_H
end_comment
end_unit
