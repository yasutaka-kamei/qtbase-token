begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACTION_H
end_ifndef
begin_define
DECL|macro|QACTION_H
define|#
directive|define
name|QACTION_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qkeysequence.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qicon.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACTION
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QActionGroup
name|class
name|QActionGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QActionPrivate
name|class
name|QActionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsWidget
name|class
name|QGraphicsWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QAction
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAction
argument_list|)
name|Q_ENUMS
argument_list|(
argument|MenuRole
argument_list|)
name|Q_ENUMS
argument_list|(
argument|Priority
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool checkable READ isCheckable WRITE setCheckable NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool checked READ isChecked WRITE setChecked DESIGNABLE isCheckable NOTIFY toggled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool enabled READ isEnabled WRITE setEnabled NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QIcon icon READ icon WRITE setIcon NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString text READ text WRITE setText NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString iconText READ iconText WRITE setIconText NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString toolTip READ toolTip WRITE setToolTip NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString statusTip READ statusTip WRITE setStatusTip NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString whatsThis READ whatsThis WRITE setWhatsThis NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QFont font READ font WRITE setFont NOTIFY changed
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|Q_PROPERTY
argument_list|(
argument|QKeySequence shortcut READ shortcut WRITE setShortcut NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::ShortcutContext shortcutContext READ shortcutContext WRITE setShortcutContext NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool autoRepeat READ autoRepeat WRITE setAutoRepeat NOTIFY changed
argument_list|)
endif|#
directive|endif
name|Q_PROPERTY
argument_list|(
argument|bool visible READ isVisible WRITE setVisible NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|MenuRole menuRole READ menuRole WRITE setMenuRole NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool iconVisibleInMenu READ isIconVisibleInMenu WRITE setIconVisibleInMenu NOTIFY changed
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Priority priority READ priority WRITE setPriority
argument_list|)
name|public
operator|:
comment|// note this is copied into qplatformmenu.h, which must stay in sync
expr|enum
name|MenuRole
block|{
name|NoRole
operator|=
literal|0
block|,
name|TextHeuristicRole
block|,
name|ApplicationSpecificRole
block|,
name|AboutQtRole
block|,
name|AboutRole
block|,
name|PreferencesRole
block|,
name|QuitRole
block|}
block|;     enum
name|Priority
block|{
name|LowPriority
operator|=
literal|0
block|,
name|NormalPriority
operator|=
literal|128
block|,
name|HighPriority
operator|=
literal|256
block|}
block|;
name|explicit
name|QAction
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|QAction
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|QAction
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
name|QObject
operator|*
name|parent
argument_list|)
block|;
operator|~
name|QAction
argument_list|()
block|;
name|void
name|setActionGroup
argument_list|(
name|QActionGroup
operator|*
name|group
argument_list|)
block|;
name|QActionGroup
operator|*
name|actionGroup
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
name|QIcon
name|icon
argument_list|()
specifier|const
block|;
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QString
name|text
argument_list|()
specifier|const
block|;
name|void
name|setIconText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QString
name|iconText
argument_list|()
specifier|const
block|;
name|void
name|setToolTip
argument_list|(
specifier|const
name|QString
operator|&
name|tip
argument_list|)
block|;
name|QString
name|toolTip
argument_list|()
specifier|const
block|;
name|void
name|setStatusTip
argument_list|(
specifier|const
name|QString
operator|&
name|statusTip
argument_list|)
block|;
name|QString
name|statusTip
argument_list|()
specifier|const
block|;
name|void
name|setWhatsThis
argument_list|(
specifier|const
name|QString
operator|&
name|what
argument_list|)
block|;
name|QString
name|whatsThis
argument_list|()
specifier|const
block|;
name|void
name|setPriority
argument_list|(
argument|Priority priority
argument_list|)
block|;
name|Priority
name|priority
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|QMenu
operator|*
name|menu
argument_list|()
specifier|const
block|;
name|void
name|setMenu
argument_list|(
name|QMenu
operator|*
name|menu
argument_list|)
block|;
endif|#
directive|endif
name|void
name|setSeparator
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|isSeparator
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|void
name|setShortcut
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|shortcut
argument_list|)
block|;
name|QKeySequence
name|shortcut
argument_list|()
specifier|const
block|;
name|void
name|setShortcuts
argument_list|(
specifier|const
name|QList
operator|<
name|QKeySequence
operator|>
operator|&
name|shortcuts
argument_list|)
block|;
name|void
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|StandardKey
argument_list|)
block|;
name|QList
operator|<
name|QKeySequence
operator|>
name|shortcuts
argument_list|()
specifier|const
block|;
name|void
name|setShortcutContext
argument_list|(
argument|Qt::ShortcutContext context
argument_list|)
block|;
name|Qt
operator|::
name|ShortcutContext
name|shortcutContext
argument_list|()
specifier|const
block|;
name|void
name|setAutoRepeat
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|autoRepeat
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|setFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|QFont
name|font
argument_list|()
specifier|const
block|;
name|void
name|setCheckable
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isCheckable
argument_list|()
specifier|const
block|;
name|QVariant
name|data
argument_list|()
specifier|const
block|;
name|void
name|setData
argument_list|(
specifier|const
name|QVariant
operator|&
name|var
argument_list|)
block|;
name|bool
name|isChecked
argument_list|()
specifier|const
block|;
name|bool
name|isEnabled
argument_list|()
specifier|const
block|;
name|bool
name|isVisible
argument_list|()
specifier|const
block|;      enum
name|ActionEvent
block|{
name|Trigger
block|,
name|Hover
block|}
block|;
name|void
name|activate
argument_list|(
argument|ActionEvent event
argument_list|)
block|;
name|bool
name|showStatusText
argument_list|(
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
block|;
name|void
name|setMenuRole
argument_list|(
argument|MenuRole menuRole
argument_list|)
block|;
name|MenuRole
name|menuRole
argument_list|()
specifier|const
block|;
name|void
name|setIconVisibleInMenu
argument_list|(
argument|bool visible
argument_list|)
block|;
name|bool
name|isIconVisibleInMenu
argument_list|()
specifier|const
block|;
name|QWidget
operator|*
name|parentWidget
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QWidget
operator|*
operator|>
name|associatedWidgets
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
name|QList
operator|<
name|QGraphicsWidget
operator|*
operator|>
name|associatedGraphicsWidgets
argument_list|()
specifier|const
block|;
comment|// ### suboptimal
endif|#
directive|endif
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|QAction
argument_list|(
name|QActionPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|trigger
argument_list|()
block|{
name|activate
argument_list|(
name|Trigger
argument_list|)
block|; }
name|void
name|hover
argument_list|()
block|{
name|activate
argument_list|(
name|Hover
argument_list|)
block|; }
name|void
name|setChecked
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|toggle
argument_list|()
block|;
name|void
name|setEnabled
argument_list|(
name|bool
argument_list|)
block|;
specifier|inline
name|void
name|setDisabled
argument_list|(
argument|bool b
argument_list|)
block|{
name|setEnabled
argument_list|(
operator|!
name|b
argument_list|)
block|; }
name|void
name|setVisible
argument_list|(
name|bool
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|changed
argument_list|()
block|;
name|void
name|triggered
argument_list|(
argument|bool checked = false
argument_list|)
block|;
name|void
name|hovered
argument_list|()
block|;
name|void
name|toggled
argument_list|(
name|bool
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QAction
argument_list|)
name|friend
name|class
name|QGraphicsWidget
block|;
name|friend
name|class
name|QWidget
block|;
name|friend
name|class
name|QActionGroup
block|;
name|friend
name|class
name|QMenu
block|;
name|friend
name|class
name|QMenuPrivate
block|;
name|friend
name|class
name|QMenuBar
block|;
name|friend
name|class
name|QToolButton
block|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|friend
name|void
name|qt_mac_clear_status_text
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<QtWidgets/qactiongroup.h>
name|QT_END_INCLUDE_NAMESPACE
endif|#
directive|endif
comment|// QT_NO_ACTION
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QACTION_H
end_comment
end_unit
