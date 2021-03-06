begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author James Turner<james.turner@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_expr_stmt
DECL|variable|NSMenuItem
name|Q_FORWARD_DECLARE_OBJC_CLASS
argument_list|(
name|NSMenuItem
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|NSMenu
name|Q_FORWARD_DECLARE_OBJC_CLASS
argument_list|(
name|NSMenu
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|NSObject
name|Q_FORWARD_DECLARE_OBJC_CLASS
argument_list|(
name|NSObject
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|NSView
name|Q_FORWARD_DECLARE_OBJC_CLASS
argument_list|(
name|NSView
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCocoaMenu
name|class
name|QCocoaMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaMenuObject
block|{
name|public
label|:
name|void
name|setMenuParent
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|)
block|{
name|parent
operator|=
name|o
expr_stmt|;
block|}
name|QObject
operator|*
name|menuParent
argument_list|()
specifier|const
block|{
return|return
name|parent
return|;
block|}
name|private
label|:
name|QPointer
operator|<
name|QObject
operator|>
name|parent
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QPlatformMenuItem
name|class
name|QCocoaMenuItem
range|:
name|public
name|QPlatformMenuItem
decl_stmt|,
name|public
name|QCocoaMenuObject
block|{
name|public
label|:
name|QCocoaMenuItem
argument_list|()
expr_stmt|;
operator|~
name|QCocoaMenuItem
argument_list|()
expr_stmt|;
name|void
name|setTag
parameter_list|(
name|quintptr
name|tag
parameter_list|)
function|Q_DECL_OVERRIDE
block|{
name|m_tag
operator|=
name|tag
expr_stmt|;
block|}
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
name|setText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setMenu
argument_list|(
name|QPlatformMenu
operator|*
name|menu
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setVisible
argument_list|(
name|bool
name|isVisible
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setIsSeparator
argument_list|(
name|bool
name|isSeparator
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setRole
argument_list|(
name|MenuRole
name|role
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setShortcut
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|shortcut
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setCheckable
parameter_list|(
name|bool
name|checkable
parameter_list|)
function|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
argument|checkable
argument_list|)
block|}
name|void
name|setChecked
argument_list|(
name|bool
name|isChecked
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setEnabled
argument_list|(
name|bool
name|isEnabled
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setIconSize
argument_list|(
name|int
name|size
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setNativeContents
argument_list|(
name|WId
name|item
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
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
modifier|*
name|nsItem
parameter_list|()
block|{
return|return
name|m_native
return|;
block|}
name|NSMenuItem
modifier|*
name|sync
parameter_list|()
function_decl|;
name|void
name|syncMerged
parameter_list|()
function_decl|;
name|void
name|syncModalState
parameter_list|(
name|bool
name|modal
parameter_list|)
function_decl|;
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
name|MenuRole
name|effectiveRole
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QString
name|mergeText
parameter_list|()
function_decl|;
name|QKeySequence
name|mergeAccel
parameter_list|()
function_decl|;
name|NSMenuItem
modifier|*
name|m_native
decl_stmt|;
name|NSView
modifier|*
name|m_itemView
decl_stmt|;
name|QString
name|m_text
decl_stmt|;
name|bool
name|m_textSynced
decl_stmt|;
name|QIcon
name|m_icon
decl_stmt|;
name|QPointer
operator|<
name|QCocoaMenu
operator|>
name|m_menu
expr_stmt|;
name|bool
name|m_isVisible
decl_stmt|;
name|bool
name|m_enabled
decl_stmt|;
name|bool
name|m_isSeparator
decl_stmt|;
name|QFont
name|m_font
decl_stmt|;
name|MenuRole
name|m_role
decl_stmt|;
name|MenuRole
name|m_detectedRole
decl_stmt|;
name|QKeySequence
name|m_shortcut
decl_stmt|;
name|bool
name|m_checked
decl_stmt|;
name|bool
name|m_merged
decl_stmt|;
name|quintptr
name|m_tag
decl_stmt|;
name|int
name|m_iconSize
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
