begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author James Turner<james.turner@kdab.com> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMMENU_H
end_ifndef
begin_define
DECL|macro|QPLATFORMMENU_H
define|#
directive|define
name|QPLATFORMMENU_H
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
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QFont>
end_include
begin_include
include|#
directive|include
file|<QtGui/QKeySequence>
end_include
begin_include
include|#
directive|include
file|<QtGui/QIcon>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformMenu
name|class
name|QPlatformMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformMenuItem
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
comment|// copied from, and must stay in sync with, QAction menu roles.
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
block|,
comment|// However these roles are private, perhaps temporarily.
comment|// They could be added as public QAction roles if necessary.
name|CutRole
block|,
name|CopyRole
block|,
name|PasteRole
block|,
name|SelectAllRole
block|,
name|RoleCount
block|}
block|;
name|virtual
name|void
name|setTag
argument_list|(
argument|quintptr tag
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|quintptr
name|tag
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setMenu
argument_list|(
name|QPlatformMenu
operator|*
name|menu
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setVisible
argument_list|(
argument|bool isVisible
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setIsSeparator
argument_list|(
argument|bool isSeparator
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setRole
argument_list|(
argument|MenuRole role
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setCheckable
argument_list|(
argument|bool checkable
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setChecked
argument_list|(
argument|bool isChecked
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setShortcut
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|shortcut
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setIconSize
argument_list|(
argument|int size
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setNativeContents
argument_list|(
argument|WId item
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|item
argument_list|)
block|; }
name|Q_SIGNALS
operator|:
name|void
name|activated
argument_list|()
block|;
name|void
name|hovered
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformMenu
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|MenuType
block|{
name|DefaultMenu
operator|=
literal|0
block|,
name|EditMenu
block|}
block|;
name|virtual
name|void
name|insertMenuItem
argument_list|(
name|QPlatformMenuItem
operator|*
name|menuItem
argument_list|,
name|QPlatformMenuItem
operator|*
name|before
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|removeMenuItem
argument_list|(
name|QPlatformMenuItem
operator|*
name|menuItem
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|syncMenuItem
argument_list|(
name|QPlatformMenuItem
operator|*
name|menuItem
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|syncSeparatorsCollapsible
argument_list|(
argument|bool enable
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setTag
argument_list|(
argument|quintptr tag
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|quintptr
name|tag
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isEnabled
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setMinimumWidth
argument_list|(
argument|int width
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|width
argument_list|)
block|; }
name|virtual
name|void
name|setFont
argument_list|(
argument|const QFont&font
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|font
argument_list|)
block|; }
name|virtual
name|void
name|setMenuType
argument_list|(
argument|MenuType type
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
block|; }
name|virtual
name|void
name|showPopup
argument_list|(
argument|const QWindow *parentWindow
argument_list|,
argument|const QRect&targetRect
argument_list|,
argument|const QPlatformMenuItem *item
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|parentWindow
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|targetRect
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|item
argument_list|)
block|;
name|setVisible
argument_list|(
name|true
argument_list|)
block|;     }
name|virtual
name|void
name|dismiss
argument_list|()
block|{ }
comment|// Closes this and all its related menu popups
name|virtual
name|QPlatformMenuItem
operator|*
name|menuItemAt
argument_list|(
argument|int position
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QPlatformMenuItem
operator|*
name|menuItemForTag
argument_list|(
argument|quintptr tag
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QPlatformMenuItem
operator|*
name|createMenuItem
argument_list|()
specifier|const
block|;
name|virtual
name|QPlatformMenu
operator|*
name|createSubMenu
argument_list|()
specifier|const
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
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformMenuBar
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|virtual
name|void
name|insertMenu
argument_list|(
name|QPlatformMenu
operator|*
name|menu
argument_list|,
name|QPlatformMenu
operator|*
name|before
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|removeMenu
argument_list|(
name|QPlatformMenu
operator|*
name|menu
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|syncMenu
argument_list|(
name|QPlatformMenu
operator|*
name|menuItem
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|handleReparent
argument_list|(
name|QWindow
operator|*
name|newParentWindow
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QPlatformMenu
operator|*
name|menuForTag
argument_list|(
argument|quintptr tag
argument_list|)
specifier|const
operator|=
literal|0
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
end_unit
