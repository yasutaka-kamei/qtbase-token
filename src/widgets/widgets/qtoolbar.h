begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDYNAMICTOOLBAR_H
end_ifndef
begin_define
DECL|macro|QDYNAMICTOOLBAR_H
define|#
directive|define
name|QDYNAMICTOOLBAR_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_TOOLBAR
name|class
name|QToolBarPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIcon
name|class
name|QIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMainWindow
name|class
name|QMainWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionToolBar
name|class
name|QStyleOptionToolBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QToolBar
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool movable READ isMovable WRITE setMovable                DESIGNABLE (qobject_cast<QMainWindow *>(parentWidget()) !=
literal|0
argument|)                NOTIFY movableChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::ToolBarAreas allowedAreas READ allowedAreas WRITE setAllowedAreas                DESIGNABLE (qobject_cast<QMainWindow *>(parentWidget()) !=
literal|0
argument|)                NOTIFY allowedAreasChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Orientation orientation READ orientation WRITE setOrientation                DESIGNABLE (qobject_cast<QMainWindow *>(parentWidget()) ==
literal|0
argument|)                NOTIFY orientationChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSize iconSize READ iconSize WRITE setIconSize NOTIFY iconSizeChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::ToolButtonStyle toolButtonStyle READ toolButtonStyle WRITE setToolButtonStyle                NOTIFY toolButtonStyleChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool floating READ isFloating
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool floatable READ isFloatable WRITE setFloatable
argument_list|)
name|public
operator|:
name|explicit
name|QToolBar
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QToolBar
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QToolBar
argument_list|()
block|;
name|void
name|setMovable
argument_list|(
argument|bool movable
argument_list|)
block|;
name|bool
name|isMovable
argument_list|()
specifier|const
block|;
name|void
name|setAllowedAreas
argument_list|(
argument|Qt::ToolBarAreas areas
argument_list|)
block|;
name|Qt
operator|::
name|ToolBarAreas
name|allowedAreas
argument_list|()
specifier|const
block|;
specifier|inline
name|bool
name|isAreaAllowed
argument_list|(
argument|Qt::ToolBarArea area
argument_list|)
specifier|const
block|{
return|return
operator|(
name|allowedAreas
argument_list|()
operator|&
name|area
operator|)
operator|==
name|area
return|;
block|}
name|void
name|setOrientation
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
block|;
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|()
specifier|const
block|;
name|void
name|clear
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
specifier|inline
name|void
name|addAction
argument_list|(
argument|QAction *action
argument_list|)
block|{
name|QWidget
operator|::
name|addAction
argument_list|(
name|action
argument_list|)
block|; }
else|#
directive|else
name|using
name|QWidget
operator|::
name|addAction
block|;
endif|#
directive|endif
name|QAction
operator|*
name|addAction
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QAction
operator|*
name|addAction
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
block|;
name|QAction
operator|*
name|addAction
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
name|QAction
operator|*
name|addAction
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
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
name|QAction
operator|*
name|addSeparator
argument_list|()
block|;
name|QAction
operator|*
name|insertSeparator
argument_list|(
name|QAction
operator|*
name|before
argument_list|)
block|;
name|QAction
operator|*
name|addWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QAction
operator|*
name|insertWidget
argument_list|(
name|QAction
operator|*
name|before
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QRect
name|actionGeometry
argument_list|(
argument|QAction *action
argument_list|)
specifier|const
block|;
name|QAction
operator|*
name|actionAt
argument_list|(
argument|const QPoint&p
argument_list|)
specifier|const
block|;
specifier|inline
name|QAction
operator|*
name|actionAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QAction
operator|*
name|toggleViewAction
argument_list|()
specifier|const
block|;
name|QSize
name|iconSize
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|ToolButtonStyle
name|toolButtonStyle
argument_list|()
specifier|const
block|;
name|QWidget
operator|*
name|widgetForAction
argument_list|(
argument|QAction *action
argument_list|)
specifier|const
block|;
name|bool
name|isFloatable
argument_list|()
specifier|const
block|;
name|void
name|setFloatable
argument_list|(
argument|bool floatable
argument_list|)
block|;
name|bool
name|isFloating
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setIconSize
argument_list|(
specifier|const
name|QSize
operator|&
name|iconSize
argument_list|)
block|;
name|void
name|setToolButtonStyle
argument_list|(
argument|Qt::ToolButtonStyle toolButtonStyle
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|actionTriggered
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|movableChanged
argument_list|(
argument|bool movable
argument_list|)
block|;
name|void
name|allowedAreasChanged
argument_list|(
argument|Qt::ToolBarAreas allowedAreas
argument_list|)
block|;
name|void
name|orientationChanged
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
block|;
name|void
name|iconSizeChanged
argument_list|(
specifier|const
name|QSize
operator|&
name|iconSize
argument_list|)
block|;
name|void
name|toolButtonStyleChanged
argument_list|(
argument|Qt::ToolButtonStyle toolButtonStyle
argument_list|)
block|;
name|void
name|topLevelChanged
argument_list|(
argument|bool topLevel
argument_list|)
block|;
name|void
name|visibilityChanged
argument_list|(
argument|bool visible
argument_list|)
block|;
name|protected
operator|:
name|void
name|actionEvent
argument_list|(
name|QActionEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|childEvent
argument_list|(
name|QChildEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionToolBar *option
argument_list|)
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|public
operator|:
name|QT3_SUPPORT_CONSTRUCTOR
name|QToolBar
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
specifier|inline
name|QT3_SUPPORT
name|void
name|setLabel
argument_list|(
argument|const QString&label
argument_list|)
block|{
name|setWindowTitle
argument_list|(
name|label
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|QString
name|label
argument_list|()
specifier|const
block|{
return|return
name|windowTitle
argument_list|()
return|;
block|}
endif|#
directive|endif
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QToolBar
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QToolBar
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_toggleView(bool)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateIconSize(const QSize&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateToolButtonStyle(Qt::ToolButtonStyle)
argument_list|)
name|friend
name|class
name|QMainWindow
block|;
name|friend
name|class
name|QMainWindowLayout
block|;
name|friend
name|class
name|QToolBarLayout
block|;
name|friend
name|class
name|QToolBarAreaLayout
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|actionAt
specifier|inline
name|QAction
operator|*
name|QToolBar
operator|::
name|actionAt
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|)
specifier|const
block|{
return|return
name|actionAt
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TOOLBAR
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
comment|// QDYNAMICTOOLBAR_H
end_comment
end_unit
