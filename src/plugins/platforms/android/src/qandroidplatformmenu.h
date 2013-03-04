begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QANDROIDPLATFORMMENU_H
end_ifndef
begin_define
DECL|macro|QANDROIDPLATFORMMENU_H
define|#
directive|define
name|QANDROIDPLATFORMMENU_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformmenu.h>
end_include
begin_include
include|#
directive|include
file|<qvector.h>
end_include
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_decl_stmt
DECL|variable|QAndroidPlatformMenuItem
name|class
name|QAndroidPlatformMenuItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAndroidPlatformMenu
range|:
name|public
name|QPlatformMenu
block|{
name|public
operator|:
typedef|typedef
name|QVector
operator|<
name|QAndroidPlatformMenuItem
operator|*
operator|>
name|PlatformMenuItemsType
expr_stmt|;
name|public
operator|:
name|QAndroidPlatformMenu
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|~
name|QAndroidPlatformMenu
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
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
function_decl|;
end_function_decl
begin_function_decl
name|void
name|removeMenuItem
parameter_list|(
name|QPlatformMenuItem
modifier|*
name|menuItem
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|syncMenuItem
parameter_list|(
name|QPlatformMenuItem
modifier|*
name|menuItem
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|syncSeparatorsCollapsible
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setTag
parameter_list|(
name|quintptr
name|tag
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|quintptr
name|tag
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|text
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QIcon
name|icon
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isEnabled
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isVisible
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QPlatformMenuItem
modifier|*
name|menuItemAt
argument_list|(
name|int
name|position
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPlatformMenuItem
modifier|*
name|menuItemForTag
argument_list|(
name|quintptr
name|tag
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|PlatformMenuItemsType
name|menuItems
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QMutex
modifier|*
name|menuItemsMutex
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|PlatformMenuItemsType
name|m_menuItems
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|quintptr
name|m_tag
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|m_text
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QIcon
name|m_icon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_enabled
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_isVisible
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QMutex
name|m_menuItemsMutex
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QANDROIDPLATFORMMENU_H
end_comment
end_unit
