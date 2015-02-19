begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_include
include|#
directive|include
file|"qdbustrayicon_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmenuconnection_p.h"
end_include
begin_include
include|#
directive|include
file|"qstatusnotifieritemadaptor_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmenuadaptor_p.h"
end_include
begin_include
include|#
directive|include
file|"dbusmenu/qdbusplatformmenu_p.h"
end_include
begin_include
include|#
directive|include
file|"qxdgnotificationproxy_p.h"
end_include
begin_include
include|#
directive|include
file|<qplatformmenu.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qrect.h>
end_include
begin_include
include|#
directive|include
file|<qloggingcategory.h>
end_include
begin_include
include|#
directive|include
file|<qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qplatformservices.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|qLcTray
argument_list|,
literal|"qt.qpa.tray"
argument_list|)
decl|static const
DECL|variable|KDEItemFormat
name|QString
name|KDEItemFormat
init|=
name|QStringLiteral
argument_list|(
literal|"org.kde.StatusNotifierItem-%1-%2"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TempFileTemplate
specifier|static
specifier|const
name|QString
name|TempFileTemplate
init|=
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
name|QStringLiteral
argument_list|(
literal|"/qt-trayicon-XXXXXX.png"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|XdgNotificationService
specifier|static
specifier|const
name|QString
name|XdgNotificationService
init|=
name|QStringLiteral
argument_list|(
literal|"org.freedesktop.Notifications"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|XdgNotificationPath
specifier|static
specifier|const
name|QString
name|XdgNotificationPath
init|=
name|QStringLiteral
argument_list|(
literal|"/org/freedesktop/Notifications"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DefaultAction
specifier|static
specifier|const
name|QString
name|DefaultAction
init|=
name|QStringLiteral
argument_list|(
literal|"default"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|instanceCount
specifier|static
name|int
name|instanceCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \class QDBusTrayIcon     \internal */
end_comment
begin_constructor
DECL|function|QDBusTrayIcon
name|QDBusTrayIcon
operator|::
name|QDBusTrayIcon
parameter_list|()
member_init_list|:
name|m_dbusConnection
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_adaptor
argument_list|(
operator|new
name|QStatusNotifierItemAdaptor
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|m_menuAdaptor
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_menu
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_notifier
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_instanceId
argument_list|(
name|KDEItemFormat
operator|.
name|arg
argument_list|(
name|QCoreApplication
operator|::
name|applicationPid
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
operator|++
name|instanceCount
argument_list|)
argument_list|)
member_init_list|,
name|m_category
argument_list|(
name|QStringLiteral
argument_list|(
literal|"ApplicationStatus"
argument_list|)
argument_list|)
member_init_list|,
name|m_defaultStatus
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Active"
argument_list|)
argument_list|)
comment|// be visible all the time.  QSystemTrayIcon has no API to control this.
member_init_list|,
name|m_status
argument_list|(
name|m_defaultStatus
argument_list|)
member_init_list|,
name|m_tempIcon
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_tempAttentionIcon
argument_list|(
name|Q_NULLPTR
argument_list|)
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
expr_stmt|;
if|if
condition|(
name|instanceCount
operator|==
literal|1
condition|)
block|{
name|QDBusMenuItem
operator|::
name|registerDBusTypes
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QXdgDBusImageStruct
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QXdgDBusImageVector
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QXdgDBusToolTipStruct
argument_list|>
argument_list|()
expr_stmt|;
block|}
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|statusChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|m_adaptor
argument_list|,
name|SIGNAL
argument_list|(
name|NewStatus
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|tooltipChanged
argument_list|()
argument_list|)
argument_list|,
name|m_adaptor
argument_list|,
name|SIGNAL
argument_list|(
name|NewToolTip
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|iconChanged
argument_list|()
argument_list|)
argument_list|,
name|m_adaptor
argument_list|,
name|SIGNAL
argument_list|(
name|NewIcon
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|attention
argument_list|()
argument_list|)
argument_list|,
name|m_adaptor
argument_list|,
name|SIGNAL
argument_list|(
name|NewAttentionIcon
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|attention
argument_list|()
argument_list|)
argument_list|,
name|m_adaptor
argument_list|,
name|SIGNAL
argument_list|(
name|NewTitle
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|m_attentionTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|attentionTimerExpired
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_attentionTimer
operator|.
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QDBusTrayIcon
name|QDBusTrayIcon
operator|::
name|~
name|QDBusTrayIcon
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|QDBusTrayIcon
operator|::
name|init
parameter_list|()
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
literal|"registering"
operator|<<
name|m_instanceId
expr_stmt|;
name|dBusConnection
argument_list|()
operator|->
name|registerTrayIcon
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|QDBusTrayIcon
operator|::
name|cleanup
parameter_list|()
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
literal|"unregistering"
operator|<<
name|m_instanceId
expr_stmt|;
name|dBusConnection
argument_list|()
operator|->
name|unregisterTrayIcon
argument_list|(
name|this
argument_list|)
expr_stmt|;
operator|delete
name|m_dbusConnection
expr_stmt|;
name|m_dbusConnection
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
end_function
begin_function
DECL|function|activate
name|void
name|QDBusTrayIcon
operator|::
name|activate
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
name|x
operator|<<
name|y
expr_stmt|;
name|setStatus
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Active"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|attentionTimerExpired
name|void
name|QDBusTrayIcon
operator|::
name|attentionTimerExpired
parameter_list|()
block|{
name|m_messageTitle
operator|=
name|QString
argument_list|()
expr_stmt|;
name|m_message
operator|=
name|QString
argument_list|()
expr_stmt|;
name|m_attentionIcon
operator|=
name|QIcon
argument_list|()
expr_stmt|;
emit|emit
name|attention
argument_list|()
emit|;
emit|emit
name|tooltipChanged
argument_list|()
emit|;
name|setStatus
argument_list|(
name|m_defaultStatus
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setStatus
name|void
name|QDBusTrayIcon
operator|::
name|setStatus
parameter_list|(
specifier|const
name|QString
modifier|&
name|status
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
name|status
expr_stmt|;
if|if
condition|(
name|m_status
operator|==
name|status
condition|)
return|return;
name|m_status
operator|=
name|status
expr_stmt|;
emit|emit
name|statusChanged
argument_list|(
name|m_status
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|tempIcon
name|QTemporaryFile
modifier|*
name|QDBusTrayIcon
operator|::
name|tempIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
comment|// Hack for Unity, which doesn't handle icons sent across D-Bus:
comment|// save the icon to a temp file and set the icon name to that filename.
specifier|static
name|bool
name|necessary
init|=
operator|(
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|services
argument_list|()
operator|->
name|desktopEnvironment
argument_list|()
operator|.
name|split
argument_list|(
literal|':'
argument_list|)
operator|.
name|contains
argument_list|(
literal|"UNITY"
argument_list|)
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|necessary
condition|)
return|return
name|Q_NULLPTR
return|;
name|QTemporaryFile
modifier|*
name|ret
init|=
operator|new
name|QTemporaryFile
argument_list|(
name|TempFileTemplate
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|ret
operator|->
name|open
argument_list|()
expr_stmt|;
name|icon
operator|.
name|pixmap
argument_list|(
name|QSize
argument_list|(
literal|22
argument_list|,
literal|22
argument_list|)
argument_list|)
operator|.
name|save
argument_list|(
name|ret
argument_list|)
expr_stmt|;
name|ret
operator|->
name|close
argument_list|()
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|dBusConnection
name|QDBusMenuConnection
modifier|*
name|QDBusTrayIcon
operator|::
name|dBusConnection
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_dbusConnection
condition|)
block|{
name|m_dbusConnection
operator|=
operator|new
name|QDBusMenuConnection
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_notifier
operator|=
operator|new
name|QXdgNotificationInterface
argument_list|(
name|XdgNotificationService
argument_list|,
name|XdgNotificationPath
argument_list|,
name|m_dbusConnection
operator|->
name|connection
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_notifier
argument_list|,
name|SIGNAL
argument_list|(
name|NotificationClosed
argument_list|(
name|uint
argument_list|,
name|uint
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|notificationClosed
argument_list|(
name|uint
argument_list|,
name|uint
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_notifier
argument_list|,
name|SIGNAL
argument_list|(
name|ActionInvoked
argument_list|(
name|uint
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|actionInvoked
argument_list|(
name|uint
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|m_dbusConnection
return|;
block|}
end_function
begin_function
DECL|function|updateIcon
name|void
name|QDBusTrayIcon
operator|::
name|updateIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
name|m_iconName
operator|=
name|icon
operator|.
name|name
argument_list|()
expr_stmt|;
name|m_icon
operator|=
name|icon
expr_stmt|;
if|if
condition|(
name|m_iconName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|m_tempIcon
condition|)
operator|delete
name|m_tempIcon
expr_stmt|;
name|m_tempIcon
operator|=
name|tempIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_tempIcon
condition|)
name|m_iconName
operator|=
name|m_tempIcon
operator|->
name|fileName
argument_list|()
expr_stmt|;
block|}
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
name|m_iconName
operator|<<
name|icon
operator|.
name|availableSizes
argument_list|()
expr_stmt|;
emit|emit
name|iconChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|updateToolTip
name|void
name|QDBusTrayIcon
operator|::
name|updateToolTip
parameter_list|(
specifier|const
name|QString
modifier|&
name|tooltip
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
name|tooltip
expr_stmt|;
name|m_tooltip
operator|=
name|tooltip
expr_stmt|;
emit|emit
name|tooltipChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|createMenu
name|QPlatformMenu
modifier|*
name|QDBusTrayIcon
operator|::
name|createMenu
parameter_list|()
specifier|const
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_menu
condition|)
cast|const_cast
argument_list|<
name|QDBusTrayIcon
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|m_menu
operator|=
operator|new
name|QDBusPlatformMenu
argument_list|()
expr_stmt|;
return|return
name|m_menu
return|;
block|}
end_function
begin_function
DECL|function|updateMenu
name|void
name|QDBusTrayIcon
operator|::
name|updateMenu
parameter_list|(
name|QPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
name|menu
expr_stmt|;
if|if
condition|(
operator|!
name|m_menu
condition|)
name|m_menu
operator|=
name|qobject_cast
argument_list|<
name|QDBusPlatformMenu
operator|*
argument_list|>
argument_list|(
name|menu
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_menuAdaptor
condition|)
block|{
name|m_menuAdaptor
operator|=
operator|new
name|QDBusMenuAdaptor
argument_list|(
name|m_menu
argument_list|)
expr_stmt|;
comment|// TODO connect(m_menu, , m_menuAdaptor, SIGNAL(ItemActivationRequested(int,uint)));
name|connect
argument_list|(
name|m_menu
argument_list|,
name|SIGNAL
argument_list|(
name|propertiesUpdated
argument_list|(
name|QDBusMenuItemList
argument_list|,
name|QDBusMenuItemKeysList
argument_list|)
argument_list|)
argument_list|,
name|m_menuAdaptor
argument_list|,
name|SIGNAL
argument_list|(
name|ItemsPropertiesUpdated
argument_list|(
name|QDBusMenuItemList
argument_list|,
name|QDBusMenuItemKeysList
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_menu
argument_list|,
name|SIGNAL
argument_list|(
name|updated
argument_list|(
name|uint
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|m_menuAdaptor
argument_list|,
name|SIGNAL
argument_list|(
name|LayoutUpdated
argument_list|(
name|uint
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|m_menu
operator|->
name|emitUpdated
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|contextMenu
name|void
name|QDBusTrayIcon
operator|::
name|contextMenu
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
name|x
operator|<<
name|y
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showMessage
name|void
name|QDBusTrayIcon
operator|::
name|showMessage
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|,
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|,
name|QPlatformSystemTrayIcon
operator|::
name|MessageIcon
name|iconType
parameter_list|,
name|int
name|msecs
parameter_list|)
block|{
name|m_messageTitle
operator|=
name|title
expr_stmt|;
name|m_message
operator|=
name|msg
expr_stmt|;
name|m_attentionIcon
operator|=
name|icon
expr_stmt|;
name|QStringList
name|notificationActions
decl_stmt|;
switch|switch
condition|(
name|iconType
condition|)
block|{
case|case
name|Information
case|:
name|m_attentionIconName
operator|=
name|QStringLiteral
argument_list|(
literal|"dialog-information"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Warning
case|:
name|m_attentionIconName
operator|=
name|QStringLiteral
argument_list|(
literal|"dialog-warning"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Critical
case|:
name|m_attentionIconName
operator|=
name|QStringLiteral
argument_list|(
literal|"dialog-error"
argument_list|)
expr_stmt|;
comment|// If there are actions, the desktop notification may appear as a message dialog
comment|// with button(s), which will interrupt the user and require a response.
comment|// That is an optional feature in implementations of org.freedesktop.Notifications
name|notificationActions
operator|<<
name|DefaultAction
operator|<<
name|tr
argument_list|(
literal|"OK"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|m_attentionIconName
operator|.
name|clear
argument_list|()
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|m_attentionIconName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|m_tempAttentionIcon
condition|)
operator|delete
name|m_tempAttentionIcon
expr_stmt|;
name|m_tempAttentionIcon
operator|=
name|tempIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_tempAttentionIcon
condition|)
name|m_attentionIconName
operator|=
name|m_tempAttentionIcon
operator|->
name|fileName
argument_list|()
expr_stmt|;
block|}
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
name|title
operator|<<
name|msg
operator|<<
name|QPlatformSystemTrayIcon
operator|::
name|metaObject
argument_list|()
operator|->
name|enumerator
argument_list|(
name|QPlatformSystemTrayIcon
operator|::
name|staticMetaObject
operator|.
name|indexOfEnumerator
argument_list|(
literal|"MessageIcon"
argument_list|)
argument_list|)
operator|.
name|valueToKey
argument_list|(
name|iconType
argument_list|)
operator|<<
name|m_attentionIconName
operator|<<
name|msecs
expr_stmt|;
name|setStatus
argument_list|(
name|QStringLiteral
argument_list|(
literal|"NeedsAttention"
argument_list|)
argument_list|)
expr_stmt|;
name|m_attentionTimer
operator|.
name|start
argument_list|(
name|msecs
argument_list|)
expr_stmt|;
emit|emit
name|tooltipChanged
argument_list|()
emit|;
emit|emit
name|attention
argument_list|()
emit|;
comment|// Desktop notification
name|QVariantMap
name|hints
decl_stmt|;
comment|// urgency levels according to https://developer.gnome.org/notification-spec/#urgency-levels
comment|// 0 low, 1 normal, 2 critical
name|int
name|urgency
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|iconType
argument_list|)
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|urgency
operator|<
literal|0
condition|)
comment|// no icon
name|urgency
operator|=
literal|0
expr_stmt|;
name|hints
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"urgency"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|urgency
argument_list|)
argument_list|)
expr_stmt|;
name|m_notifier
operator|->
name|notify
argument_list|(
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
argument_list|,
literal|0
argument_list|,
name|m_attentionIconName
argument_list|,
name|title
argument_list|,
name|msg
argument_list|,
name|notificationActions
argument_list|,
name|hints
argument_list|,
name|msecs
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|actionInvoked
name|void
name|QDBusTrayIcon
operator|::
name|actionInvoked
parameter_list|(
name|uint
name|id
parameter_list|,
specifier|const
name|QString
modifier|&
name|action
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
name|id
operator|<<
name|action
expr_stmt|;
emit|emit
name|messageClicked
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|notificationClosed
name|void
name|QDBusTrayIcon
operator|::
name|notificationClosed
parameter_list|(
name|uint
name|id
parameter_list|,
name|uint
name|reason
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
name|id
operator|<<
name|reason
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isSystemTrayAvailable
name|bool
name|QDBusTrayIcon
operator|::
name|isSystemTrayAvailable
parameter_list|()
specifier|const
block|{
name|QDBusMenuConnection
modifier|*
name|conn
init|=
cast|const_cast
argument_list|<
name|QDBusTrayIcon
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|dBusConnection
argument_list|()
decl_stmt|;
name|qCDebug
argument_list|(
name|qLcTray
argument_list|)
operator|<<
name|conn
operator|->
name|isStatusNotifierHostRegistered
argument_list|()
expr_stmt|;
return|return
name|conn
operator|->
name|isStatusNotifierHostRegistered
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_SYSTEMTRAYICON
end_comment
end_unit
