begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author James Turner<james.turner@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAMENUBAR_H
end_ifndef
begin_define
DECL|macro|QCOCOAMENUBAR_H
define|#
directive|define
name|QCOCOAMENUBAR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformmenu.h>
end_include
begin_include
include|#
directive|include
file|"qcocoamenu.h"
end_include
begin_decl_stmt
unit|@
DECL|variable|NSMenu
name|class
name|NSMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCocoaWindow
name|class
name|QCocoaWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaMenuBar
range|:
name|public
name|QPlatformMenuBar
block|{
name|public
operator|:
name|QCocoaMenuBar
argument_list|()
block|;
name|virtual
operator|~
name|QCocoaMenuBar
argument_list|()
block|;
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
block|;
name|virtual
name|void
name|removeMenu
argument_list|(
name|QPlatformMenu
operator|*
name|menu
argument_list|)
block|;
name|virtual
name|void
name|syncMenu
argument_list|(
name|QPlatformMenu
operator|*
name|menuItem
argument_list|)
block|;
name|virtual
name|void
name|handleReparent
argument_list|(
name|QWindow
operator|*
name|newParentWindow
argument_list|)
block|;
name|virtual
name|QPlatformMenu
operator|*
name|menuForTag
argument_list|(
argument|quintptr tag
argument_list|)
specifier|const
block|;
specifier|inline
name|NSMenu
operator|*
name|nsMenu
argument_list|()
specifier|const
block|{
return|return
name|m_nativeMenu
return|;
block|}
specifier|static
name|void
name|updateMenuBarImmediately
argument_list|()
block|;
name|QList
operator|<
name|QCocoaMenuItem
operator|*
operator|>
name|merged
argument_list|()
specifier|const
block|;
name|private
operator|:
specifier|static
name|QCocoaWindow
operator|*
name|findWindowForMenubar
argument_list|()
block|;
specifier|static
name|QCocoaMenuBar
operator|*
name|findGlobalMenubar
argument_list|()
block|;
name|bool
name|shouldDisable
argument_list|(
argument|QCocoaWindow *active
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QCocoaMenu
operator|*
operator|>
name|m_menus
block|;
name|NSMenu
operator|*
name|m_nativeMenu
block|;
name|QCocoaWindow
operator|*
name|m_window
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
