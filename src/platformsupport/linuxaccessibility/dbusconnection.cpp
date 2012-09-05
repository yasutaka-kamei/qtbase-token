begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class DBusConnection     \internal     \brief Connects to the accessibility dbus.      This is usually a different bus from the session bus. */
end_comment
begin_constructor
DECL|function|DBusConnection
name|DBusConnection
operator|::
name|DBusConnection
parameter_list|()
member_init_list|:
name|dbusConnection
argument_list|(
name|connectDBus
argument_list|()
argument_list|)
block|{}
end_constructor
begin_function
DECL|function|connectDBus
name|QDBusConnection
name|DBusConnection
operator|::
name|connectDBus
parameter_list|()
block|{
name|QString
name|address
init|=
name|getAccessibilityBusAddress
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
name|QDBusConnection
name|c
init|=
name|QDBusConnection
operator|::
name|connectToBus
argument_list|(
name|address
argument_list|,
name|QStringLiteral
argument_list|(
literal|"a11y"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|c
operator|.
name|isConnected
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Connected to accessibility bus at: "
operator|<<
name|address
expr_stmt|;
return|return
name|c
return|;
block|}
name|qWarning
argument_list|(
literal|"Found Accessibility DBus address but cannot connect. Falling back to session bus."
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Accessibility DBus not found. Falling back to session bus."
argument_list|)
expr_stmt|;
block|}
name|QDBusConnection
name|c
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|c
operator|.
name|isConnected
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not connect to DBus."
argument_list|)
expr_stmt|;
block|}
return|return
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|getAccessibilityBusAddress
name|QString
name|DBusConnection
operator|::
name|getAccessibilityBusAddress
parameter_list|()
specifier|const
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
name|QDBusMessage
name|reply
init|=
name|c
operator|.
name|call
argument_list|(
name|m
argument_list|)
decl_stmt|;
if|if
condition|(
name|reply
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ErrorMessage
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Qt at-spi: error getting the accessibility dbus address: "
operator|<<
name|reply
operator|.
name|errorMessage
argument_list|()
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
name|QString
name|busAddress
init|=
name|reply
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Got bus address: "
operator|<<
name|busAddress
expr_stmt|;
return|return
name|busAddress
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the DBus connection that got established. */
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
name|dbusConnection
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
