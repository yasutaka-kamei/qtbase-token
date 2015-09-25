begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"dbusconnection_p.h"
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusMessage>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusServiceWatcher>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QDBusConnectionInterface>
end_include
begin_include
include|#
directive|include
file|"bus_interface.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<qplatformnativeinterface.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/* note: do not change these to QStringLiteral;    we are unloaded before QtDBus is done using the strings.  */
end_comment
begin_define
DECL|macro|A11Y_SERVICE
define|#
directive|define
name|A11Y_SERVICE
value|QLatin1String("org.a11y.Bus")
end_define
begin_define
DECL|macro|A11Y_PATH
define|#
directive|define
name|A11Y_PATH
value|QLatin1String("/org/a11y/bus")
end_define
begin_comment
comment|/*!     \class DBusConnection     \internal     \brief Connects to the accessibility dbus.      This is usually a different bus from the session bus. */
end_comment
begin_constructor
DECL|function|DBusConnection
name|DBusConnection
operator|::
name|DBusConnection
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_a11yConnection
argument_list|(
name|QString
argument_list|()
argument_list|)
member_init_list|,
name|m_enabled
argument_list|(
literal|false
argument_list|)
block|{
comment|// Start monitoring if "org.a11y.Bus" is registered as DBus service.
name|QDBusConnection
name|c
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
name|dbusWatcher
operator|=
operator|new
name|QDBusServiceWatcher
argument_list|(
name|A11Y_SERVICE
argument_list|,
name|c
argument_list|,
name|QDBusServiceWatcher
operator|::
name|WatchForRegistration
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|dbusWatcher
argument_list|,
name|SIGNAL
argument_list|(
name|serviceRegistered
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|serviceRegistered
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// If it is registered already, setup a11y right away
if|if
condition|(
name|c
operator|.
name|interface
argument_list|()
operator|->
name|isServiceRegistered
argument_list|(
name|A11Y_SERVICE
argument_list|)
condition|)
name|serviceRegistered
argument_list|()
expr_stmt|;
comment|// In addition try if there is an xatom exposing the bus address, this allows applications run as root to work
name|QString
name|address
init|=
name|getAddressFromXCB
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|address
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|m_enabled
operator|=
literal|true
expr_stmt|;
name|connectA11yBus
argument_list|(
name|address
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_function
DECL|function|getAddressFromXCB
name|QString
name|DBusConnection
operator|::
name|getAddressFromXCB
parameter_list|()
block|{
name|QGuiApplication
modifier|*
name|app
init|=
name|qobject_cast
argument_list|<
name|QGuiApplication
operator|*
argument_list|>
argument_list|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|app
condition|)
return|return
name|QString
argument_list|()
return|;
name|QPlatformNativeInterface
modifier|*
name|platformNativeInterface
init|=
name|app
operator|->
name|platformNativeInterface
argument_list|()
decl_stmt|;
name|QByteArray
modifier|*
name|addressByteArray
init|=
cast|reinterpret_cast
argument_list|<
name|QByteArray
operator|*
argument_list|>
argument_list|(
name|platformNativeInterface
operator|->
name|nativeResourceForIntegration
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"AtspiBus"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|addressByteArray
condition|)
block|{
name|QString
name|address
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
operator|*
name|addressByteArray
argument_list|)
decl_stmt|;
operator|delete
name|addressByteArray
expr_stmt|;
return|return
name|address
return|;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// We have the a11y registry on the session bus.
end_comment
begin_comment
comment|// Subscribe to updates about a11y enabled state.
end_comment
begin_comment
comment|// Find out the bus address
end_comment
begin_function
DECL|function|serviceRegistered
name|void
name|DBusConnection
operator|::
name|serviceRegistered
parameter_list|()
block|{
comment|// listen to enabled changes
name|QDBusConnection
name|c
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
name|OrgA11yStatusInterface
modifier|*
name|a11yStatus
init|=
operator|new
name|OrgA11yStatusInterface
argument_list|(
name|A11Y_SERVICE
argument_list|,
name|A11Y_PATH
argument_list|,
name|c
argument_list|,
name|this
argument_list|)
decl_stmt|;
comment|//The variable was introduced because on some embedded platforms there are custom accessibility
comment|//clients which don't set Status.ScreenReaderEnabled to true. The variable is also useful for
comment|//debugging.
specifier|static
specifier|const
name|bool
name|a11yAlwaysOn
init|=
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QT_LINUX_ACCESSIBILITY_ALWAYS_ON"
argument_list|)
decl_stmt|;
comment|// a11yStatus->isEnabled() returns always true (since Gnome 3.6)
name|bool
name|enabled
init|=
name|a11yAlwaysOn
operator|||
name|a11yStatus
operator|->
name|screenReaderEnabled
argument_list|()
decl_stmt|;
if|if
condition|(
name|enabled
operator|!=
name|m_enabled
condition|)
block|{
name|m_enabled
operator|=
name|enabled
expr_stmt|;
if|if
condition|(
name|m_a11yConnection
operator|.
name|isConnected
argument_list|()
condition|)
block|{
emit|emit
name|enabledChanged
argument_list|(
name|m_enabled
argument_list|)
emit|;
block|}
else|else
block|{
name|QDBusConnection
name|c
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
name|QDBusMessage
name|m
init|=
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|QLatin1String
argument_list|(
literal|"org.a11y.Bus"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"/org/a11y/bus"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"org.a11y.Bus"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"GetAddress"
argument_list|)
argument_list|)
decl_stmt|;
name|c
operator|.
name|callWithCallback
argument_list|(
name|m
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|connectA11yBus
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|dbusError
argument_list|(
name|QDBusError
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
comment|//    connect(a11yStatus, ); QtDbus doesn't support notifications for property changes yet
block|}
end_function
begin_function
DECL|function|serviceUnregistered
name|void
name|DBusConnection
operator|::
name|serviceUnregistered
parameter_list|()
block|{
emit|emit
name|enabledChanged
argument_list|(
literal|false
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|connectA11yBus
name|void
name|DBusConnection
operator|::
name|connectA11yBus
parameter_list|(
specifier|const
name|QString
modifier|&
name|address
parameter_list|)
block|{
if|if
condition|(
name|address
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not find Accessibility DBus address."
argument_list|)
expr_stmt|;
return|return;
block|}
name|m_a11yConnection
operator|=
name|QDBusConnection
argument_list|(
name|QDBusConnection
operator|::
name|connectToBus
argument_list|(
name|address
argument_list|,
name|QLatin1String
argument_list|(
literal|"a11y"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_enabled
condition|)
emit|emit
name|enabledChanged
argument_list|(
literal|true
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|dbusError
name|void
name|DBusConnection
operator|::
name|dbusError
parameter_list|(
specifier|const
name|QDBusError
modifier|&
name|error
parameter_list|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Accessibility encountered a DBus error:"
operator|<<
name|error
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the DBus connection that got established.   Or an invalid connection if not yet connected. */
end_comment
begin_function
DECL|function|connection
name|QDBusConnection
name|DBusConnection
operator|::
name|connection
parameter_list|()
specifier|const
block|{
return|return
name|m_a11yConnection
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
