begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformmenu.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformmenuitem.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimenu.h"
end_include
begin_constructor
DECL|function|QAndroidPlatformMenu
name|QAndroidPlatformMenu
operator|::
name|QAndroidPlatformMenu
parameter_list|()
block|{
name|m_tag
operator|=
cast|reinterpret_cast
argument_list|<
name|quintptr
argument_list|>
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|// QMenu will overwrite this later, but we need a unique ID for QtQuick
name|m_enabled
operator|=
literal|true
expr_stmt|;
name|m_isVisible
operator|=
literal|true
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QAndroidPlatformMenu
name|QAndroidPlatformMenu
operator|::
name|~
name|QAndroidPlatformMenu
parameter_list|()
block|{
name|QtAndroidMenu
operator|::
name|androidPlatformMenuDestroyed
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|insertMenuItem
name|void
name|QAndroidPlatformMenu
operator|::
name|insertMenuItem
parameter_list|(
name|QPlatformMenuItem
modifier|*
name|menuItem
parameter_list|,
name|QPlatformMenuItem
modifier|*
name|before
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_menuItemsMutex
argument_list|)
decl_stmt|;
name|m_menuItems
operator|.
name|insert
argument_list|(
name|qFind
argument_list|(
name|m_menuItems
operator|.
name|begin
argument_list|()
argument_list|,
name|m_menuItems
operator|.
name|end
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QAndroidPlatformMenuItem
operator|*
argument_list|>
argument_list|(
name|before
argument_list|)
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|QAndroidPlatformMenuItem
operator|*
argument_list|>
argument_list|(
name|menuItem
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeMenuItem
name|void
name|QAndroidPlatformMenu
operator|::
name|removeMenuItem
parameter_list|(
name|QPlatformMenuItem
modifier|*
name|menuItem
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_menuItemsMutex
argument_list|)
decl_stmt|;
name|PlatformMenuItemsType
operator|::
name|iterator
name|it
init|=
name|qFind
argument_list|(
name|m_menuItems
operator|.
name|begin
argument_list|()
argument_list|,
name|m_menuItems
operator|.
name|end
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QAndroidPlatformMenuItem
operator|*
argument_list|>
argument_list|(
name|menuItem
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|m_menuItems
operator|.
name|end
argument_list|()
condition|)
name|m_menuItems
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|syncMenuItem
name|void
name|QAndroidPlatformMenu
operator|::
name|syncMenuItem
parameter_list|(
name|QPlatformMenuItem
modifier|*
name|menuItem
parameter_list|)
block|{
name|PlatformMenuItemsType
operator|::
name|iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|m_menuItems
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|m_menuItems
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|it
operator|)
operator|->
name|tag
argument_list|()
operator|==
name|menuItem
operator|->
name|tag
argument_list|()
condition|)
break|break;
block|}
if|if
condition|(
name|it
operator|!=
name|m_menuItems
operator|.
name|end
argument_list|()
condition|)
name|QtAndroidMenu
operator|::
name|syncMenu
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|syncSeparatorsCollapsible
name|void
name|QAndroidPlatformMenu
operator|::
name|syncSeparatorsCollapsible
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|enable
argument_list|)
block|}
end_function
begin_function
DECL|function|setTag
name|void
name|QAndroidPlatformMenu
operator|::
name|setTag
parameter_list|(
name|quintptr
name|tag
parameter_list|)
block|{
name|m_tag
operator|=
name|tag
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tag
name|quintptr
name|QAndroidPlatformMenu
operator|::
name|tag
parameter_list|()
specifier|const
block|{
return|return
name|m_tag
return|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|QAndroidPlatformMenu
operator|::
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|m_text
operator|=
name|text
expr_stmt|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAndroidPlatformMenu
operator|::
name|text
parameter_list|()
specifier|const
block|{
return|return
name|m_text
return|;
block|}
end_function
begin_function
DECL|function|setIcon
name|void
name|QAndroidPlatformMenu
operator|::
name|setIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
name|m_icon
operator|=
name|icon
expr_stmt|;
block|}
end_function
begin_function
DECL|function|icon
name|QIcon
name|QAndroidPlatformMenu
operator|::
name|icon
parameter_list|()
specifier|const
block|{
return|return
name|m_icon
return|;
block|}
end_function
begin_function
DECL|function|setEnabled
name|void
name|QAndroidPlatformMenu
operator|::
name|setEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|m_enabled
operator|=
name|enabled
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isEnabled
name|bool
name|QAndroidPlatformMenu
operator|::
name|isEnabled
parameter_list|()
specifier|const
block|{
return|return
name|m_enabled
return|;
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QAndroidPlatformMenu
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|m_isVisible
operator|=
name|visible
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isVisible
name|bool
name|QAndroidPlatformMenu
operator|::
name|isVisible
parameter_list|()
specifier|const
block|{
return|return
name|m_isVisible
return|;
block|}
end_function
begin_function
DECL|function|showPopup
name|void
name|QAndroidPlatformMenu
operator|::
name|showPopup
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|parentWindow
parameter_list|,
name|QPoint
name|pos
parameter_list|,
specifier|const
name|QPlatformMenuItem
modifier|*
name|item
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|parentWindow
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QtAndroidMenu
operator|::
name|showContextMenu
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|menuItemAt
name|QPlatformMenuItem
modifier|*
name|QAndroidPlatformMenu
operator|::
name|menuItemAt
parameter_list|(
name|int
name|position
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|position
operator|<
name|m_menuItems
operator|.
name|size
argument_list|()
condition|)
return|return
name|m_menuItems
index|[
name|position
index|]
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|menuItemForTag
name|QPlatformMenuItem
modifier|*
name|QAndroidPlatformMenu
operator|::
name|menuItemForTag
parameter_list|(
name|quintptr
name|tag
parameter_list|)
specifier|const
block|{
foreach|foreach
control|(
name|QPlatformMenuItem
modifier|*
name|menuItem
decl|,
name|m_menuItems
control|)
block|{
if|if
condition|(
name|menuItem
operator|->
name|tag
argument_list|()
operator|==
name|tag
condition|)
return|return
name|menuItem
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|menuItems
name|QAndroidPlatformMenu
operator|::
name|PlatformMenuItemsType
name|QAndroidPlatformMenu
operator|::
name|menuItems
parameter_list|()
specifier|const
block|{
return|return
name|m_menuItems
return|;
block|}
end_function
begin_function
DECL|function|menuItemsMutex
name|QMutex
modifier|*
name|QAndroidPlatformMenu
operator|::
name|menuItemsMutex
parameter_list|()
block|{
return|return
operator|&
name|m_menuItemsMutex
return|;
block|}
end_function
end_unit
