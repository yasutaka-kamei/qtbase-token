begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLEWIDGET_H
end_ifndef
begin_define
DECL|macro|QACCESSIBLEWIDGET_H
define|#
directive|define
name|QACCESSIBLEWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qaccessibleobject.h>
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
name|QT_NO_ACCESSIBILITY
name|class
name|QAccessibleWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QAccessibleWidget
range|:
name|public
name|QAccessibleObject
block|{
name|public
operator|:
name|explicit
name|QAccessibleWidget
argument_list|(
argument|QWidget *o
argument_list|,
argument|Role r = Client
argument_list|,
argument|const QString& name = QString()
argument_list|)
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
name|Relation
name|relationTo
argument_list|(
argument|int child
argument_list|,
argument|const QAccessibleInterface *other
argument_list|,
argument|int otherChild
argument_list|)
specifier|const
block|;
name|int
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag rel
argument_list|,
argument|int entry
argument_list|,
argument|QAccessibleInterface **target
argument_list|)
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|Role
name|role
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|State
name|state
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACTION
name|int
name|userActionCount
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
operator|~
name|QAccessibleWidget
argument_list|()
block|;
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|;
name|QObject
operator|*
name|parentObject
argument_list|()
specifier|const
block|;
name|void
name|addControllingSignal
argument_list|(
specifier|const
name|QString
operator|&
name|signal
argument_list|)
block|;
name|void
name|setValue
argument_list|(
specifier|const
name|QString
operator|&
name|value
argument_list|)
block|;
name|void
name|setDescription
argument_list|(
specifier|const
name|QString
operator|&
name|desc
argument_list|)
block|;
name|void
name|setHelp
argument_list|(
specifier|const
name|QString
operator|&
name|help
argument_list|)
block|;
name|void
name|setAccelerator
argument_list|(
specifier|const
name|QString
operator|&
name|accel
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QAccessibleWidgetEx
block|;
name|QAccessibleWidgetPrivate
operator|*
name|d
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QAccessibleWidget
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QAccessibleWidgetEx
range|:
name|public
name|QAccessibleObjectEx
block|{
name|public
operator|:
name|explicit
name|QAccessibleWidgetEx
argument_list|(
argument|QWidget *o
argument_list|,
argument|Role r = Client
argument_list|,
argument|const QString& name = QString()
argument_list|)
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
name|Relation
name|relationTo
argument_list|(
argument|int child
argument_list|,
argument|const QAccessibleInterface *other
argument_list|,
argument|int otherChild
argument_list|)
specifier|const
block|;
name|int
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag rel
argument_list|,
argument|int entry
argument_list|,
argument|QAccessibleInterface **target
argument_list|)
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|Role
name|role
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|State
name|state
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
name|QVariant
name|invokeMethodEx
argument_list|(
argument|Method method
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
name|protected
operator|:
operator|~
name|QAccessibleWidgetEx
argument_list|()
block|;
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|;
name|QObject
operator|*
name|parentObject
argument_list|()
specifier|const
block|;
name|void
name|addControllingSignal
argument_list|(
specifier|const
name|QString
operator|&
name|signal
argument_list|)
block|;
name|void
name|setValue
argument_list|(
specifier|const
name|QString
operator|&
name|value
argument_list|)
block|;
name|void
name|setDescription
argument_list|(
specifier|const
name|QString
operator|&
name|desc
argument_list|)
block|;
name|void
name|setHelp
argument_list|(
specifier|const
name|QString
operator|&
name|help
argument_list|)
block|;
name|void
name|setAccelerator
argument_list|(
specifier|const
name|QString
operator|&
name|accel
argument_list|)
block|;
name|private
operator|:
name|QAccessibleWidgetPrivate
operator|*
name|d
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QAccessibleWidgetEx
argument_list|)
block|}
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
comment|// QACCESSIBLEWIDGET_H
end_comment
end_unit
