begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLEOBJECT_H
end_ifndef
begin_define
DECL|macro|QACCESSIBLEOBJECT_H
define|#
directive|define
name|QACCESSIBLEOBJECT_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qaccessible.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qaccessible2.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
DECL|variable|QAccessibleObjectPrivate
name|class
name|QAccessibleObjectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleObject
range|:
name|public
name|QAccessibleInterface
block|{
name|public
operator|:
name|explicit
name|QAccessibleObject
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|;
comment|// properties
name|QRect
name|rect
argument_list|()
specifier|const
block|;
name|void
name|setText
argument_list|(
argument|QAccessible::Text t
argument_list|,
argument|const QString&text
argument_list|)
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
name|protected
operator|:
name|virtual
operator|~
name|QAccessibleObject
argument_list|()
block|;
name|private
operator|:
name|QAccessibleObjectPrivate
operator|*
name|d
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QAccessibleObject
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleApplication
range|:
name|public
name|QAccessibleObject
block|{
name|public
operator|:
name|QAccessibleApplication
argument_list|()
block|;
name|QWindow
operator|*
name|window
argument_list|()
specifier|const
block|;
comment|// relations
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface*
argument_list|)
specifier|const
block|;
name|QAccessibleInterface
operator|*
name|focusChild
argument_list|()
specifier|const
block|;
comment|// navigation
name|QAccessibleInterface
operator|*
name|parent
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
comment|// properties and state
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
name|QAccessible
operator|::
name|State
name|state
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
comment|// QT_NO_ACCESSIBILITY
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
comment|// QACCESSIBLEOBJECT_H
end_comment
end_unit
