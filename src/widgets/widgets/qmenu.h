begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMENU_H
end_ifndef
begin_define
DECL|macro|QMENU_H
define|#
directive|define
name|QMENU_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qicon.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qaction.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qplatformmenu_qpa.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|<windef.h>
end_include
begin_comment
comment|// for HMENU
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|class
name|QMenuPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionMenuItem
name|class
name|QStyleOptionMenuItem
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_decl_stmt
DECL|variable|QMenuItem
name|class
name|QMenuItem
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QMenu
range|:
name|public
name|QWidget
block|{
name|private
operator|:
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QMenu
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool tearOffEnabled READ isTearOffEnabled WRITE setTearOffEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString title READ title WRITE setTitle
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QIcon icon READ icon WRITE setIcon
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool separatorsCollapsible READ separatorsCollapsible WRITE setSeparatorsCollapsible
argument_list|)
name|public
operator|:
name|explicit
name|QMenu
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QMenu
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
operator|~
name|QMenu
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
argument_list|,
specifier|const
name|QKeySequence
operator|&
name|shortcut
operator|=
literal|0
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
argument_list|,
specifier|const
name|QKeySequence
operator|&
name|shortcut
operator|=
literal|0
argument_list|)
block|;
name|QAction
operator|*
name|addMenu
argument_list|(
name|QMenu
operator|*
name|menu
argument_list|)
block|;
name|QMenu
operator|*
name|addMenu
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|QMenu
operator|*
name|addMenu
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|,
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|QAction
operator|*
name|addSeparator
argument_list|()
block|;
name|QAction
operator|*
name|insertMenu
argument_list|(
name|QAction
operator|*
name|before
argument_list|,
name|QMenu
operator|*
name|menu
argument_list|)
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
name|bool
name|isEmpty
argument_list|()
specifier|const
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|setTearOffEnabled
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isTearOffEnabled
argument_list|()
specifier|const
block|;
name|bool
name|isTearOffMenuVisible
argument_list|()
specifier|const
block|;
name|void
name|hideTearOffMenu
argument_list|()
block|;
name|void
name|setDefaultAction
argument_list|(
name|QAction
operator|*
argument_list|)
block|;
name|QAction
operator|*
name|defaultAction
argument_list|()
specifier|const
block|;
name|void
name|setActiveAction
argument_list|(
name|QAction
operator|*
name|act
argument_list|)
block|;
name|QAction
operator|*
name|activeAction
argument_list|()
specifier|const
block|;
name|void
name|popup
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|QAction
operator|*
name|at
operator|=
literal|0
argument_list|)
block|;
name|QAction
operator|*
name|exec
argument_list|()
block|;
name|QAction
operator|*
name|exec
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|QAction
operator|*
name|at
operator|=
literal|0
argument_list|)
block|;
comment|// ### Qt 5: merge
specifier|static
name|QAction
operator|*
name|exec
argument_list|(
name|QList
operator|<
name|QAction
operator|*
operator|>
name|actions
argument_list|,
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|QAction
operator|*
name|at
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QAction
operator|*
name|exec
argument_list|(
name|QList
operator|<
name|QAction
operator|*
operator|>
name|actions
argument_list|,
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
name|QAction
operator|*
name|at
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QRect
name|actionGeometry
argument_list|(
argument|QAction *
argument_list|)
specifier|const
block|;
name|QAction
operator|*
name|actionAt
argument_list|(
argument|const QPoint&
argument_list|)
specifier|const
block|;
name|QAction
operator|*
name|menuAction
argument_list|()
specifier|const
block|;
name|QString
name|title
argument_list|()
specifier|const
block|;
name|void
name|setTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|QIcon
name|icon
argument_list|()
specifier|const
block|;
name|void
name|setIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
name|void
name|setNoReplayFor
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QPlatformMenu
operator|*
name|platformMenu
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_WS_WINCE
name|HMENU
name|wceMenu
argument_list|()
block|;
endif|#
directive|endif
name|bool
name|separatorsCollapsible
argument_list|()
specifier|const
block|;
name|void
name|setSeparatorsCollapsible
argument_list|(
argument|bool collapse
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|aboutToShow
argument_list|()
block|;
name|void
name|aboutToHide
argument_list|()
block|;
name|void
name|triggered
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|hovered
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|protected
operator|:
name|int
name|columnCount
argument_list|()
specifier|const
block|;
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|void
name|enterEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|leaveEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|hideEvent
argument_list|(
name|QHideEvent
operator|*
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|actionEvent
argument_list|(
name|QActionEvent
operator|*
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionMenuItem *option
argument_list|,
argument|const QAction *action
argument_list|)
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_WS_WINCE
name|QAction
operator|*
name|wceCommands
argument_list|(
argument|uint command
argument_list|)
block|;
endif|#
directive|endif
name|private
name|Q_SLOTS
operator|:
name|void
name|internalSetSloppyAction
argument_list|()
block|;
name|void
name|internalDelayedPopup
argument_list|()
block|;
name|private
operator|:
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_actionTriggered()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_actionHovered()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_overrideMenuActionDestroyed()
argument_list|)
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|public
operator|:
comment|//menudata
specifier|inline
name|QT3_SUPPORT
name|uint
name|count
argument_list|()
specifier|const
block|{
return|return
name|actions
argument_list|()
operator|.
name|count
argument_list|()
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|int
name|insertItem
argument_list|(
argument|const QString&text
argument_list|,
argument|const QObject *receiver
argument_list|,
argument|const char* member
argument_list|,
argument|const QKeySequence& shortcut =
literal|0
argument_list|,
argument|int id = -
literal|1
argument_list|,
argument|int index = -
literal|1
argument_list|)
block|{
return|return
name|insertAny
argument_list|(
literal|0
argument_list|,
operator|&
name|text
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|,
operator|&
name|shortcut
argument_list|,
literal|0
argument_list|,
name|id
argument_list|,
name|index
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|int
name|insertItem
argument_list|(
argument|const QIcon& icon
argument_list|,
argument|const QString&text
argument_list|,
argument|const QObject *receiver
argument_list|,
argument|const char* member
argument_list|,
argument|const QKeySequence& shortcut =
literal|0
argument_list|,
argument|int id = -
literal|1
argument_list|,
argument|int index = -
literal|1
argument_list|)
block|{
return|return
name|insertAny
argument_list|(
operator|&
name|icon
argument_list|,
operator|&
name|text
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|,
operator|&
name|shortcut
argument_list|,
literal|0
argument_list|,
name|id
argument_list|,
name|index
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|int
name|insertItem
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|const QObject *receiver
argument_list|,
argument|const char* member
argument_list|,
argument|const QKeySequence& shortcut =
literal|0
argument_list|,
argument|int id = -
literal|1
argument_list|,
argument|int index = -
literal|1
argument_list|)
block|{
name|QIcon
name|icon
argument_list|(
name|pixmap
argument_list|)
block|;
return|return
name|insertAny
argument_list|(
operator|&
name|icon
argument_list|,
literal|0
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|,
operator|&
name|shortcut
argument_list|,
literal|0
argument_list|,
name|id
argument_list|,
name|index
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|int
name|insertItem
argument_list|(
argument|const QString&text
argument_list|,
argument|int id=-
literal|1
argument_list|,
argument|int index=-
literal|1
argument_list|)
block|{
return|return
name|insertAny
argument_list|(
literal|0
argument_list|,
operator|&
name|text
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|id
argument_list|,
name|index
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|int
name|insertItem
argument_list|(
argument|const QIcon& icon
argument_list|,
argument|const QString&text
argument_list|,
argument|int id=-
literal|1
argument_list|,
argument|int index=-
literal|1
argument_list|)
block|{
return|return
name|insertAny
argument_list|(
operator|&
name|icon
argument_list|,
operator|&
name|text
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|id
argument_list|,
name|index
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|int
name|insertItem
argument_list|(
argument|const QString&text
argument_list|,
argument|QMenu *popup
argument_list|,
argument|int id=-
literal|1
argument_list|,
argument|int index=-
literal|1
argument_list|)
block|{
return|return
name|insertAny
argument_list|(
literal|0
argument_list|,
operator|&
name|text
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|popup
argument_list|,
name|id
argument_list|,
name|index
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|int
name|insertItem
argument_list|(
argument|const QIcon& icon
argument_list|,
argument|const QString&text
argument_list|,
argument|QMenu *popup
argument_list|,
argument|int id=-
literal|1
argument_list|,
argument|int index=-
literal|1
argument_list|)
block|{
return|return
name|insertAny
argument_list|(
operator|&
name|icon
argument_list|,
operator|&
name|text
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|popup
argument_list|,
name|id
argument_list|,
name|index
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|int
name|insertItem
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|int id=-
literal|1
argument_list|,
argument|int index=-
literal|1
argument_list|)
block|{
name|QIcon
name|icon
argument_list|(
name|pixmap
argument_list|)
block|;
return|return
name|insertAny
argument_list|(
operator|&
name|icon
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|id
argument_list|,
name|index
argument_list|)
return|;
block|}
specifier|inline
name|QT3_SUPPORT
name|int
name|insertItem
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|QMenu *popup
argument_list|,
argument|int id=-
literal|1
argument_list|,
argument|int index=-
literal|1
argument_list|)
block|{
name|QIcon
name|icon
argument_list|(
name|pixmap
argument_list|)
block|;
return|return
name|insertAny
argument_list|(
operator|&
name|icon
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|popup
argument_list|,
name|id
argument_list|,
name|index
argument_list|)
return|;
block|}
name|QT3_SUPPORT
name|int
name|insertItem
argument_list|(
argument|QMenuItem *item
argument_list|,
argument|int id=-
literal|1
argument_list|,
argument|int index=-
literal|1
argument_list|)
block|;
name|QT3_SUPPORT
name|int
name|insertSeparator
argument_list|(
argument|int index=-
literal|1
argument_list|)
block|;
specifier|inline
name|QT3_SUPPORT
name|void
name|removeItem
argument_list|(
argument|int id
argument_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
name|removeAction
argument_list|(
name|act
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QT3_SUPPORT
name|void
name|removeItemAt
argument_list|(
argument|int index
argument_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|actions
argument_list|()
operator|.
name|value
argument_list|(
name|index
argument_list|)
condition|)
name|removeAction
argument_list|(
name|act
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
specifier|inline
name|QT3_SUPPORT
name|QKeySequence
name|accel
argument_list|(
argument|int id
argument_list|)
specifier|const
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
return|return
name|act
operator|->
name|shortcut
argument_list|()
return|;
return|return
name|QKeySequence
argument_list|()
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setAccel
parameter_list|(
specifier|const
name|QKeySequence
modifier|&
name|key
parameter_list|,
name|int
name|id
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
name|act
operator|->
name|setShortcut
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|QIcon
name|iconSet
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
return|return
name|act
operator|->
name|icon
argument_list|()
return|;
return|return
name|QIcon
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|QString
name|text
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
return|return
name|act
operator|->
name|text
argument_list|()
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|QPixmap
name|pixmap
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
return|return
name|act
operator|->
name|icon
argument_list|()
operator|.
name|pixmap
argument_list|(
name|QSize
argument_list|(
literal|22
argument_list|,
literal|22
argument_list|)
argument_list|)
return|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setWhatsThis
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|QString
modifier|&
name|w
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
name|act
operator|->
name|setWhatsThis
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|QString
name|whatsThis
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
return|return
name|act
operator|->
name|whatsThis
argument_list|()
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|changeItem
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
name|act
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|changeItem
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
name|act
operator|->
name|setIcon
argument_list|(
name|QIcon
argument_list|(
name|pixmap
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|changeItem
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
block|{
name|act
operator|->
name|setIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|act
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setActiveItem
parameter_list|(
name|int
name|id
parameter_list|)
block|{
name|setActiveAction
argument_list|(
name|findActionForId
argument_list|(
name|id
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|isItemActive
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
return|return
name|findActionForId
argument_list|(
name|id
argument_list|)
operator|==
name|activeAction
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|isItemEnabled
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
return|return
name|act
operator|->
name|isEnabled
argument_list|()
return|;
return|return
name|false
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setItemEnabled
parameter_list|(
name|int
name|id
parameter_list|,
name|bool
name|enable
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
name|act
operator|->
name|setEnabled
argument_list|(
name|enable
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|isItemChecked
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
return|return
name|act
operator|->
name|isChecked
argument_list|()
return|;
return|return
name|false
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setItemChecked
parameter_list|(
name|int
name|id
parameter_list|,
name|bool
name|check
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
block|{
name|act
operator|->
name|setCheckable
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|act
operator|->
name|setChecked
argument_list|(
name|check
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|isItemVisible
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
return|return
name|act
operator|->
name|isVisible
argument_list|()
return|;
return|return
name|false
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setItemVisible
parameter_list|(
name|int
name|id
parameter_list|,
name|bool
name|visible
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
name|act
operator|->
name|setVisible
argument_list|(
name|visible
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|QRect
name|itemGeometry
parameter_list|(
name|int
name|index
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|actions
argument_list|()
operator|.
name|value
argument_list|(
name|index
argument_list|)
condition|)
return|return
name|actionGeometry
argument_list|(
name|act
argument_list|)
return|;
return|return
name|QRect
argument_list|()
return|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|QFont
name|itemFont
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
return|return
name|act
operator|->
name|font
argument_list|()
return|;
return|return
name|QFont
argument_list|()
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setItemFont
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
name|act
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|int
name|indexOf
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
return|return
name|actions
argument_list|()
operator|.
name|indexOf
argument_list|(
name|findActionForId
argument_list|(
name|id
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|int
name|idAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
block|{
return|return
name|findIdForAction
argument_list|(
name|actions
argument_list|()
operator|.
name|value
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_function_decl
name|QT3_SUPPORT
name|void
name|setId
parameter_list|(
name|int
name|index
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|activateItemAt
parameter_list|(
name|int
name|index
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|ret
init|=
name|actions
argument_list|()
operator|.
name|value
argument_list|(
name|index
argument_list|)
condition|)
name|ret
operator|->
name|activate
argument_list|(
name|QAction
operator|::
name|Trigger
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|bool
name|connectItem
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
block|{
name|QObject
operator|::
name|connect
argument_list|(
name|act
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|bool
name|disconnectItem
parameter_list|(
name|int
name|id
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
if|if
condition|(
name|QAction
modifier|*
name|act
init|=
name|findActionForId
argument_list|(
name|id
argument_list|)
condition|)
block|{
name|QObject
operator|::
name|disconnect
argument_list|(
name|act
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|receiver
argument_list|,
name|member
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|QT3_SUPPORT
name|QMenuItem
modifier|*
name|findItem
argument_list|(
name|int
name|id
argument_list|)
decl|const
block|{
return|return
name|reinterpret_cast
operator|<
name|QMenuItem
operator|*
operator|>
operator|(
name|findActionForId
argument_list|(
name|id
argument_list|)
operator|)
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setCheckable
parameter_list|(
name|bool
parameter_list|)
block|{}
end_function
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|bool
name|isCheckable
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
end_expr_stmt
begin_function_decl
name|QT3_SUPPORT
name|QMenuItem
modifier|*
name|findPopup
parameter_list|(
name|QMenu
modifier|*
name|popup
parameter_list|,
name|int
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QT3_SUPPORT
name|bool
name|setItemParameter
parameter_list|(
name|int
name|id
parameter_list|,
name|int
name|param
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QT3_SUPPORT
name|int
name|itemParameter
argument_list|(
name|int
name|id
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_comment
comment|//frame
end_comment
begin_expr_stmt
name|QT3_SUPPORT
name|int
name|frameWidth
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|//popupmenu
end_comment
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|popup
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
name|int
name|indexAtPoint
parameter_list|)
block|{
name|popup
argument_list|(
name|pos
argument_list|,
name|actions
argument_list|()
operator|.
name|value
argument_list|(
name|indexAtPoint
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|int
name|insertTearOffHandle
parameter_list|(
name|int
init|=
literal|0
parameter_list|,
name|int
init|=
literal|0
parameter_list|)
block|{
name|setTearOffEnabled
argument_list|(
name|true
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_label
name|protected
label|:
end_label
begin_function
specifier|inline
name|QT3_SUPPORT
name|int
name|itemAtPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|,
name|bool
name|ignoreSeparator
init|=
name|true
parameter_list|)
block|{
name|QAction
modifier|*
name|ret
init|=
name|actionAt
argument_list|(
name|p
argument_list|)
decl_stmt|;
if|if
condition|(
name|ignoreSeparator
operator|&&
name|ret
operator|&&
name|ret
operator|->
name|isSeparator
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|findIdForAction
argument_list|(
name|ret
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QT3_SUPPORT
name|int
name|columns
argument_list|()
specifier|const
block|{
return|return
name|columnCount
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|int
name|itemHeight
parameter_list|(
name|int
name|index
parameter_list|)
block|{
return|return
name|actionGeometry
argument_list|(
name|actions
argument_list|()
operator|.
name|value
argument_list|(
name|index
argument_list|)
argument_list|)
operator|.
name|height
argument_list|()
return|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|int
name|itemHeight
parameter_list|(
name|QMenuItem
modifier|*
name|mi
parameter_list|)
block|{
return|return
name|actionGeometry
argument_list|(
name|reinterpret_cast
operator|<
name|QAction
operator|*
operator|>
operator|(
name|mi
operator|)
argument_list|)
operator|.
name|height
argument_list|()
return|;
block|}
end_function
begin_label
name|Q_SIGNALS
label|:
end_label
begin_function_decl
name|QT_MOC_COMPAT
name|void
name|activated
parameter_list|(
name|int
name|itemId
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QT_MOC_COMPAT
name|void
name|highlighted
parameter_list|(
name|int
name|itemId
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_function_decl
name|int
name|insertAny
parameter_list|(
specifier|const
name|QIcon
modifier|*
name|icon
parameter_list|,
specifier|const
name|QString
modifier|*
name|text
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|,
specifier|const
name|QKeySequence
modifier|*
name|shorcut
parameter_list|,
specifier|const
name|QMenu
modifier|*
name|popup
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QAction
modifier|*
name|findActionForId
argument_list|(
name|int
name|id
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|findIdForAction
argument_list|(
name|QAction
operator|*
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|QMenu
argument_list|(
name|QMenuPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QMenu
argument_list|)
end_macro
begin_decl_stmt
name|friend
name|class
name|QMenuBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QMenuBarPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QTornOffMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|Q3PopupMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QToolButtonPrivate
decl_stmt|;
end_decl_stmt
begin_function_decl
name|friend
name|void
name|qt_mac_emit_menuSignals
parameter_list|(
name|QMenu
modifier|*
name|menu
parameter_list|,
name|bool
name|show
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|friend
name|void
name|qt_mac_menu_emit_hovered
parameter_list|(
name|QMenu
modifier|*
name|menu
parameter_list|,
name|QAction
modifier|*
name|action
parameter_list|)
function_decl|;
end_function_decl
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENU
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
comment|// QMENU_H
end_comment
end_unit
