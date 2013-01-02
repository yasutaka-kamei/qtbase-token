begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author James Turner<james.turner@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAMENUITEM_H
end_ifndef
begin_define
DECL|macro|QCOCOAMENUITEM_H
define|#
directive|define
name|QCOCOAMENUITEM_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformmenu.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_comment
comment|//#define QT_COCOA_ENABLE_MENU_DEBUG
end_comment
begin_decl_stmt
unit|@
DECL|variable|NSMenuItem
name|class
name|NSMenuItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|NSMenuItem
unit|@
DECL|variable|NSMenu
name|class
name|NSMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QCocoaMenu
name|class
name|QCocoaMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaMenuItem
range|:
name|public
name|QPlatformMenuItem
block|{
name|public
operator|:
name|QCocoaMenuItem
argument_list|()
block|;
name|virtual
operator|~
name|QCocoaMenuItem
argument_list|()
block|;
specifier|inline
name|virtual
name|void
name|setTag
argument_list|(
argument|quintptr tag
argument_list|)
block|{
name|m_tag
operator|=
name|tag
block|; }
specifier|inline
name|virtual
name|quintptr
name|tag
argument_list|()
specifier|const
block|{
return|return
name|m_tag
return|;
block|}
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
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
name|void
name|setMenu
argument_list|(
name|QPlatformMenu
operator|*
name|menu
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool isVisible
argument_list|)
block|;
name|void
name|setIsSeparator
argument_list|(
argument|bool isSeparator
argument_list|)
block|;
name|void
name|setFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|void
name|setRole
argument_list|(
argument|MenuRole role
argument_list|)
block|;
name|void
name|setShortcut
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|shortcut
argument_list|)
block|;
name|void
name|setChecked
argument_list|(
argument|bool isChecked
argument_list|)
block|;
name|void
name|setEnabled
argument_list|(
argument|bool isEnabled
argument_list|)
block|;
specifier|inline
name|QString
name|text
argument_list|()
specifier|const
block|{
return|return
name|m_text
return|;
block|}
specifier|inline
name|NSMenuItem
operator|*
name|nsItem
argument_list|()
block|{
return|return
name|m_native
return|;
block|}
name|NSMenuItem
operator|*
name|sync
argument_list|()
block|;
name|void
name|syncMerged
argument_list|()
block|;
name|void
name|syncModalState
argument_list|(
argument|bool modal
argument_list|)
block|;
specifier|inline
name|bool
name|isMerged
argument_list|()
specifier|const
block|{
return|return
name|m_merged
return|;
block|}
specifier|inline
name|bool
name|isEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_enabled
return|;
block|}
specifier|inline
name|bool
name|isSeparator
argument_list|()
specifier|const
block|{
return|return
name|m_isSeparator
return|;
block|}
name|QCocoaMenu
operator|*
name|menu
argument_list|()
specifier|const
block|{
return|return
name|m_menu
return|;
block|}
name|private
operator|:
name|QString
name|mergeText
argument_list|()
block|;
name|QKeySequence
name|mergeAccel
argument_list|()
block|;
name|NSMenuItem
operator|*
name|m_native
block|;
name|QString
name|m_text
block|;
name|QIcon
name|m_icon
block|;
name|QCocoaMenu
operator|*
name|m_menu
block|;
name|bool
name|m_isVisible
block|;
name|bool
name|m_enabled
block|;
name|bool
name|m_isSeparator
block|;
name|QFont
name|m_font
block|;
name|MenuRole
name|m_role
block|;
name|QKeySequence
name|m_shortcut
block|;
name|bool
name|m_checked
block|;
name|bool
name|m_merged
block|;
name|quintptr
name|m_tag
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_HEADER
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
