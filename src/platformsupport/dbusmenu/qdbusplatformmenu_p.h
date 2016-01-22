begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSPLATFORMMENU_H
end_ifndef
begin_define
DECL|macro|QDBUSPLATFORMMENU_H
define|#
directive|define
name|QDBUSPLATFORMMENU_H
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
comment|// This file is part of the DBus menu support and is not meant to be used
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
file|<qpa/qplatformmenu.h>
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|"qdbusmenutypes_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|qLcMenu
argument_list|)
name|class
name|QDBusPlatformMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusPlatformMenuItem
range|:
name|public
name|QPlatformMenuItem
block|{
name|Q_OBJECT
name|public
operator|:
name|QDBusPlatformMenuItem
argument_list|(
argument|quintptr tag =
literal|0LL
argument_list|)
block|;
operator|~
name|QDBusPlatformMenuItem
argument_list|()
block|;
name|quintptr
name|tag
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_tag
return|;
block|}
name|void
name|setTag
argument_list|(
argument|quintptr tag
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|const
name|QString
name|text
argument_list|()
specifier|const
block|{
return|return
name|m_text
return|;
block|}
name|void
name|setText
argument_list|(
argument|const QString&text
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QIcon
name|icon
argument_list|()
specifier|const
block|{
return|return
name|m_icon
return|;
block|}
name|void
name|setIcon
argument_list|(
argument|const QIcon&icon
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|const
name|QPlatformMenu
operator|*
name|menu
argument_list|()
specifier|const
block|{
return|return
name|m_subMenu
return|;
block|}
name|void
name|setMenu
argument_list|(
argument|QPlatformMenu *menu
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_isEnabled
return|;
block|}
name|void
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isVisible
argument_list|()
specifier|const
block|{
return|return
name|m_isVisible
return|;
block|}
name|void
name|setVisible
argument_list|(
argument|bool isVisible
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isSeparator
argument_list|()
specifier|const
block|{
return|return
name|m_isSeparator
return|;
block|}
name|void
name|setIsSeparator
argument_list|(
argument|bool isSeparator
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setFont
argument_list|(
argument|const QFont&font
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|font
argument_list|)
block|; }
name|void
name|setRole
argument_list|(
argument|MenuRole role
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isCheckable
argument_list|()
specifier|const
block|{
return|return
name|m_isCheckable
return|;
block|}
name|void
name|setCheckable
argument_list|(
argument|bool checkable
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isChecked
argument_list|()
specifier|const
block|{
return|return
name|m_isChecked
return|;
block|}
name|void
name|setChecked
argument_list|(
argument|bool isChecked
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasExclusiveGroup
argument_list|()
specifier|const
block|{
return|return
name|m_hasExclusiveGroup
return|;
block|}
name|void
name|setHasExclusiveGroup
argument_list|(
argument|bool hasExclusiveGroup
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QKeySequence
name|shortcut
argument_list|()
specifier|const
block|{
return|return
name|m_shortcut
return|;
block|}
name|void
name|setShortcut
argument_list|(
argument|const QKeySequence& shortcut
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setIconSize
argument_list|(
argument|int size
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
block|; }
name|void
name|setNativeContents
argument_list|(
argument|WId item
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|item
argument_list|)
block|; }
name|int
name|dbusID
argument_list|()
specifier|const
block|{
return|return
name|m_dbusID
return|;
block|}
name|void
name|trigger
argument_list|()
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDBusPlatformMenuItem
operator|&
name|other
operator|)
block|{
return|return
name|m_tag
operator|==
name|other
operator|.
name|m_tag
return|;
block|}
specifier|static
name|QDBusPlatformMenuItem
operator|*
name|byId
argument_list|(
argument|int id
argument_list|)
block|;
specifier|static
name|QList
operator|<
specifier|const
name|QDBusPlatformMenuItem
operator|*
operator|>
name|byIds
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|ids
argument_list|)
block|;
name|private
operator|:
name|quintptr
name|m_tag
block|;
name|QString
name|m_text
block|;
name|QIcon
name|m_icon
block|;
name|QPlatformMenu
operator|*
name|m_subMenu
block|;
name|MenuRole
name|m_role
operator|:
literal|4
block|;
name|bool
name|m_isEnabled
operator|:
literal|1
block|;
name|bool
name|m_isVisible
operator|:
literal|1
block|;
name|bool
name|m_isSeparator
operator|:
literal|1
block|;
name|bool
name|m_isCheckable
operator|:
literal|1
block|;
name|bool
name|m_isChecked
operator|:
literal|1
block|;
name|int
name|m_dbusID
operator|:
literal|16
block|;
name|bool
name|m_hasExclusiveGroup
operator|:
literal|1
block|;
name|int
name|m_reserved
operator|:
literal|6
block|;
name|QKeySequence
name|m_shortcut
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusPlatformMenu
range|:
name|public
name|QPlatformMenu
block|{
name|Q_OBJECT
name|public
operator|:
name|QDBusPlatformMenu
argument_list|(
argument|quintptr tag =
literal|0LL
argument_list|)
block|;
operator|~
name|QDBusPlatformMenu
argument_list|()
block|;
name|void
name|insertMenuItem
argument_list|(
argument|QPlatformMenuItem *menuItem
argument_list|,
argument|QPlatformMenuItem *before
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|removeMenuItem
argument_list|(
argument|QPlatformMenuItem *menuItem
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|syncMenuItem
argument_list|(
argument|QPlatformMenuItem *menuItem
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|syncSeparatorsCollapsible
argument_list|(
argument|bool enable
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|enable
argument_list|)
block|; }
name|quintptr
name|tag
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_tag
return|;
block|}
name|void
name|setTag
argument_list|(
argument|quintptr tag
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|const
name|QString
name|text
argument_list|()
specifier|const
block|{
return|return
name|m_text
return|;
block|}
name|void
name|setText
argument_list|(
argument|const QString&text
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setIcon
argument_list|(
argument|const QIcon&icon
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setMinimumWidth
argument_list|(
argument|int width
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|width
argument_list|)
block|; }
name|void
name|setFont
argument_list|(
argument|const QFont&font
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|font
argument_list|)
block|; }
name|void
name|setMenuType
argument_list|(
argument|MenuType type
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
block|; }
name|int
name|dbusID
argument_list|()
specifier|const
block|{
return|return
name|m_dbusID
return|;
block|}
name|void
name|showPopup
argument_list|(
argument|const QWindow *parentWindow
argument_list|,
argument|const QRect&targetRect
argument_list|,
argument|const QPlatformMenuItem *item
argument_list|)
name|Q_DECL_OVERRIDE
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
name|void
name|dismiss
argument_list|()
name|Q_DECL_OVERRIDE
block|{ }
comment|// Closes this and all its related menu popups
name|QPlatformMenuItem
operator|*
name|menuItemAt
argument_list|(
argument|int position
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformMenuItem
operator|*
name|menuItemForTag
argument_list|(
argument|quintptr tag
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|const
name|QList
operator|<
name|QDBusPlatformMenuItem
operator|*
operator|>
name|items
argument_list|()
specifier|const
block|;
name|QPlatformMenuItem
operator|*
name|createMenuItem
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformMenu
operator|*
name|createSubMenu
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDBusPlatformMenu
operator|&
name|other
operator|)
block|{
return|return
name|m_tag
operator|==
name|other
operator|.
name|m_tag
return|;
block|}
specifier|static
name|QDBusPlatformMenu
operator|*
name|byId
argument_list|(
argument|int id
argument_list|)
block|;
specifier|static
name|QList
operator|<
name|QDBusPlatformMenu
operator|*
operator|>
name|topLevelMenus
argument_list|()
block|{
return|return
name|m_topLevelMenus
return|;
block|}
name|uint
name|revision
argument_list|()
specifier|const
block|{
return|return
name|m_revision
return|;
block|}
name|void
name|emitUpdated
argument_list|()
block|;
name|signals
operator|:
name|void
name|updated
argument_list|(
argument|uint revision
argument_list|,
argument|int dbusId
argument_list|)
block|;
name|void
name|propertiesUpdated
argument_list|(
argument|QDBusMenuItemList updatedProps
argument_list|,
argument|QDBusMenuItemKeysList removedProps
argument_list|)
block|;
name|private
operator|:
name|quintptr
name|m_tag
block|;
name|QString
name|m_text
block|;
name|QIcon
name|m_icon
block|;
name|bool
name|m_isEnabled
block|;
name|bool
name|m_isVisible
block|;
name|bool
name|m_isSeparator
block|;
name|int
name|m_dbusID
block|;
name|uint
name|m_revision
block|;
name|QHash
operator|<
name|quintptr
block|,
name|QDBusPlatformMenuItem
operator|*
operator|>
name|m_itemsByTag
block|;
name|QList
operator|<
name|QDBusPlatformMenuItem
operator|*
operator|>
name|m_items
block|;
name|QDBusPlatformMenuItem
operator|*
name|m_containingMenuItem
block|;
specifier|static
name|QList
operator|<
name|QDBusPlatformMenu
operator|*
operator|>
name|m_topLevelMenus
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
