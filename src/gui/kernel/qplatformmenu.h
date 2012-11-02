begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author James Turner<james.turner@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QT_BEGIN_HEADER
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
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
operator|=
literal|0
block|;
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
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
