begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSTRAYICON_H
end_ifndef
begin_define
DECL|macro|QDBUSTRAYICON_H
define|#
directive|define
name|QDBUSTRAYICON_H
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_include
include|#
directive|include
file|<QIcon>
end_include
begin_include
include|#
directive|include
file|<QTemporaryFile>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|"QtGui/qpa/qplatformsystemtrayicon.h"
end_include
begin_include
include|#
directive|include
file|"private/qdbusmenuconnection_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QStatusNotifierItemAdaptor
name|class
name|QStatusNotifierItemAdaptor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusMenuAdaptor
name|class
name|QDBusMenuAdaptor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPlatformMenu
name|class
name|QDBusPlatformMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXdgNotificationInterface
name|class
name|QXdgNotificationInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusTrayIcon
range|:
name|public
name|QPlatformSystemTrayIcon
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString category READ category NOTIFY categoryChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString status READ status NOTIFY statusChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString tooltip READ tooltip NOTIFY tooltipChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString iconName READ iconName NOTIFY iconChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QIcon icon READ icon NOTIFY iconChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool isRequestingAttention READ isRequestingAttention NOTIFY attention
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString attentionTitle READ attentionTitle NOTIFY attention
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString attentionMessage READ attentionMessage NOTIFY attention
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString attentionIconName READ attentionIconName NOTIFY attention
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QIcon attentionIcon READ attentionIcon NOTIFY attention
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QDBusPlatformMenu *menu READ menu NOTIFY menuChanged
argument_list|)
name|public
operator|:
name|QDBusTrayIcon
argument_list|()
block|;
name|virtual
operator|~
name|QDBusTrayIcon
argument_list|()
block|;
name|QDBusMenuConnection
operator|*
name|dBusConnection
argument_list|()
block|;
name|void
name|init
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|cleanup
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|updateIcon
argument_list|(
argument|const QIcon&icon
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|updateToolTip
argument_list|(
argument|const QString&tooltip
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|updateMenu
argument_list|(
argument|QPlatformMenu *menu
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QPlatformMenu
operator|*
name|createMenu
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|showMessage
argument_list|(
argument|const QString&title
argument_list|,
argument|const QString&msg
argument_list|,
argument|const QIcon&icon
argument_list|,
argument|MessageIcon iconType
argument_list|,
argument|int msecs
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isSystemTrayAvailable
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|supportsMessages
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|true
return|;
block|}
name|QRect
name|geometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QRect
argument_list|()
return|;
block|}
name|QString
name|category
argument_list|()
specifier|const
block|{
return|return
name|m_category
return|;
block|}
name|QString
name|status
argument_list|()
specifier|const
block|{
return|return
name|m_status
return|;
block|}
name|QString
name|tooltip
argument_list|()
specifier|const
block|{
return|return
name|m_tooltip
return|;
block|}
name|QString
name|iconName
argument_list|()
specifier|const
block|{
return|return
name|m_iconName
return|;
block|}
specifier|const
name|QIcon
operator|&
name|icon
argument_list|()
specifier|const
block|{
return|return
name|m_icon
return|;
block|}
name|bool
name|isRequestingAttention
argument_list|()
specifier|const
block|{
return|return
name|m_attentionTimer
operator|.
name|isActive
argument_list|()
return|;
block|}
name|QString
name|attentionTitle
argument_list|()
specifier|const
block|{
return|return
name|m_messageTitle
return|;
block|}
name|QString
name|attentionMessage
argument_list|()
specifier|const
block|{
return|return
name|m_message
return|;
block|}
name|QString
name|attentionIconName
argument_list|()
specifier|const
block|{
return|return
name|m_attentionIconName
return|;
block|}
specifier|const
name|QIcon
operator|&
name|attentionIcon
argument_list|()
specifier|const
block|{
return|return
name|m_attentionIcon
return|;
block|}
name|QString
name|instanceId
argument_list|()
specifier|const
block|{
return|return
name|m_instanceId
return|;
block|}
name|QDBusPlatformMenu
operator|*
name|menu
argument_list|()
block|{
return|return
name|m_menu
return|;
block|}
name|signals
operator|:
name|void
name|categoryChanged
argument_list|()
block|;
name|void
name|statusChanged
argument_list|(
argument|QString arg
argument_list|)
block|;
name|void
name|tooltipChanged
argument_list|()
block|;
name|void
name|iconChanged
argument_list|()
block|;
name|void
name|attention
argument_list|()
block|;
name|void
name|menuChanged
argument_list|()
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|attentionTimerExpired
argument_list|()
block|;
name|void
name|actionInvoked
argument_list|(
argument|uint id
argument_list|,
argument|const QString&action
argument_list|)
block|;
name|void
name|notificationClosed
argument_list|(
argument|uint id
argument_list|,
argument|uint reason
argument_list|)
block|;
name|private
operator|:
name|void
name|setStatus
argument_list|(
specifier|const
name|QString
operator|&
name|status
argument_list|)
block|;
name|QTemporaryFile
operator|*
name|tempIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
name|private
operator|:
name|QDBusMenuConnection
operator|*
name|m_dbusConnection
block|;
name|QStatusNotifierItemAdaptor
operator|*
name|m_adaptor
block|;
name|QDBusMenuAdaptor
operator|*
name|m_menuAdaptor
block|;
name|QDBusPlatformMenu
operator|*
name|m_menu
block|;
name|QXdgNotificationInterface
operator|*
name|m_notifier
block|;
name|QString
name|m_instanceId
block|;
name|QString
name|m_category
block|;
name|QString
name|m_defaultStatus
block|;
name|QString
name|m_status
block|;
name|QString
name|m_tooltip
block|;
name|QString
name|m_messageTitle
block|;
name|QString
name|m_message
block|;
name|QIcon
name|m_icon
block|;
name|QTemporaryFile
operator|*
name|m_tempIcon
block|;
name|QString
name|m_iconName
block|;
name|QIcon
name|m_attentionIcon
block|;
name|QTemporaryFile
operator|*
name|m_tempAttentionIcon
block|;
name|QString
name|m_attentionIconName
block|;
name|QTimer
name|m_attentionTimer
block|;
name|bool
name|m_isRequestingAttention
block|;
name|bool
name|m_hasMenu
block|;
name|bool
name|m_registered
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
begin_comment
comment|// QT_NO_SYSTEMTRAYICON
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDBUSTRAYICON_H
end_comment
end_unit
