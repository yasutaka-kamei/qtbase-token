begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLEMENU_H
end_ifndef
begin_define
DECL|macro|QACCESSIBLEMENU_H
define|#
directive|define
name|QACCESSIBLEMENU_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qaccessiblewidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
ifndef|#
directive|ifndef
name|QT_NO_MENU
DECL|variable|QMenu
name|class
name|QMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMenuBar
name|class
name|QMenuBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleMenu
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleMenu
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|QAccessible::Text t
argument_list|)
specifier|const
block|;
name|QAccessible
operator|::
name|Role
name|role
argument_list|()
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|parent
argument_list|()
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QMenu
operator|*
name|menu
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
end_ifndef
begin_decl_stmt
name|class
name|QAccessibleMenuBar
range|:
name|public
name|QAccessibleWidget
block|{
name|public
operator|:
name|explicit
name|QAccessibleMenuBar
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|QAccessibleInterface
operator|*
name|child
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *child
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QMenuBar
operator|*
name|menuBar
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENUBAR
end_comment
begin_decl_stmt
DECL|variable|QAccessibleInterface
name|class
name|QAccessibleMenuItem
range|:
name|public
name|QAccessibleInterface
decl_stmt|,
name|public
name|QAccessibleActionInterface
block|{
name|public
label|:
name|explicit
name|QAccessibleMenuItem
parameter_list|(
name|QWidget
modifier|*
name|owner
parameter_list|,
name|QAction
modifier|*
name|w
parameter_list|)
function_decl|;
operator|~
name|QAccessibleMenuItem
argument_list|()
expr_stmt|;
name|void
modifier|*
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
argument_list|)
decl_stmt|;
name|int
name|childCount
argument_list|()
specifier|const
expr_stmt|;
name|QAccessibleInterface
modifier|*
name|childAt
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|int
name|indexOfChild
argument_list|(
specifier|const
name|QAccessibleInterface
operator|*
name|child
argument_list|)
decl|const
decl_stmt|;
name|QAccessibleInterface
operator|*
name|parent
argument_list|()
specifier|const
expr_stmt|;
name|QAccessibleInterface
modifier|*
name|child
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|rect
argument_list|()
specifier|const
expr_stmt|;
name|QAccessible
operator|::
name|Role
name|role
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setText
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
decl_stmt|;
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|text
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|)
decl|const
decl_stmt|;
comment|// QAccessibleActionInterface
name|QStringList
name|actionNames
argument_list|()
specifier|const
expr_stmt|;
name|void
name|doAction
parameter_list|(
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
function_decl|;
name|QStringList
name|keyBindingsForAction
argument_list|(
specifier|const
name|QString
operator|&
name|actionName
argument_list|)
decl|const
decl_stmt|;
name|QWidget
operator|*
name|owner
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|QAction
operator|*
name|action
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QAction
modifier|*
name|m_action
decl_stmt|;
name|QWidget
modifier|*
name|m_owner
decl_stmt|;
comment|// can hold either QMenu or the QMenuBar that contains the action
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
comment|// QT_NO_MENU
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QACCESSIBLEMENU_H
end_comment
end_unit
