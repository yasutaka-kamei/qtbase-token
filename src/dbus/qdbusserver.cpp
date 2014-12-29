begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2015 Intel Corporation. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusserver.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnectionmanager_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusutil_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QDBusServer     \inmodule QtDBus      \brief The QDBusServer class provides peer-to-peer communication     between processes on the same computer. */
end_comment
begin_comment
comment|/*!     Constructs a QDBusServer with the given \a address, and the given     \a parent. */
end_comment
begin_constructor
DECL|function|QDBusServer
name|QDBusServer
operator|::
name|QDBusServer
parameter_list|(
specifier|const
name|QString
modifier|&
name|address
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{
if|if
condition|(
name|address
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
if|if
condition|(
operator|!
name|qdbus_loadLibDBus
argument_list|()
condition|)
block|{
name|d
operator|=
literal|0
expr_stmt|;
return|return;
block|}
name|d
operator|=
operator|new
name|QDBusConnectionPrivate
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|d
argument_list|,
name|SIGNAL
argument_list|(
name|newServerConnection
argument_list|(
name|QDBusConnectionPrivate
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_newConnection
argument_list|(
name|QDBusConnectionPrivate
operator|*
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|QDBusErrorInternal
name|error
decl_stmt|;
name|d
operator|->
name|setServer
argument_list|(
name|this
argument_list|,
name|q_dbus_server_listen
argument_list|(
name|address
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|error
argument_list|)
argument_list|,
name|error
argument_list|)
expr_stmt|;
name|d
operator|->
name|moveToThread
argument_list|(
name|QDBusConnectionManager
operator|::
name|instance
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QDBusServer with the given \a parent. The server will listen     for connections in \c {/tmp} (on Unix systems) or on a TCP port bound to     localhost (elsewhere). */
end_comment
begin_constructor
DECL|function|QDBusServer
name|QDBusServer
operator|::
name|QDBusServer
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
block|{
ifdef|#
directive|ifdef
name|Q_OS_UNIX
comment|// Use Unix sockets on Unix systems only
specifier|static
specifier|const
name|char
name|address
index|[]
init|=
literal|"unix:tmpdir=/tmp"
decl_stmt|;
else|#
directive|else
specifier|static
specifier|const
name|char
name|address
index|[]
init|=
literal|"tcp:"
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|qdbus_loadLibDBus
argument_list|()
condition|)
block|{
name|d
operator|=
literal|0
expr_stmt|;
return|return;
block|}
name|d
operator|=
operator|new
name|QDBusConnectionPrivate
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|d
argument_list|,
name|SIGNAL
argument_list|(
name|newServerConnection
argument_list|(
name|QDBusConnectionPrivate
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_newConnection
argument_list|(
name|QDBusConnectionPrivate
operator|*
argument_list|)
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|QDBusErrorInternal
name|error
decl_stmt|;
name|d
operator|->
name|setServer
argument_list|(
name|this
argument_list|,
name|q_dbus_server_listen
argument_list|(
name|address
argument_list|,
name|error
argument_list|)
argument_list|,
name|error
argument_list|)
expr_stmt|;
name|d
operator|->
name|moveToThread
argument_list|(
name|QDBusConnectionManager
operator|::
name|instance
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destructs a QDBusServer */
end_comment
begin_destructor
DECL|function|~QDBusServer
name|QDBusServer
operator|::
name|~
name|QDBusServer
parameter_list|()
block|{
if|if
condition|(
name|QDBusConnectionManager
operator|::
name|instance
argument_list|()
condition|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|QDBusConnectionManager
operator|::
name|instance
argument_list|()
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|Q_FOREACH
argument_list|(
argument|const QString&name
argument_list|,
argument|d->serverConnectionNames
argument_list|)
block|{
name|QDBusConnectionManager
operator|::
name|instance
argument_list|()
operator|->
name|removeConnection
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|serverConnectionNames
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|ref
operator|.
name|store
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns \c true if this QDBusServer object is connected.      If it isn't connected, you need to call the constructor again. */
end_comment
begin_function
DECL|function|isConnected
name|bool
name|QDBusServer
operator|::
name|isConnected
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|&&
name|d
operator|->
name|server
operator|&&
name|q_dbus_server_get_is_connected
argument_list|(
name|d
operator|->
name|server
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the last error that happened in this server.      This function is provided for low-level code. */
end_comment
begin_function
DECL|function|lastError
name|QDBusError
name|QDBusServer
operator|::
name|lastError
parameter_list|()
specifier|const
block|{
return|return
name|d
condition|?
name|d
operator|->
name|lastError
else|:
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|Disconnected
argument_list|,
name|QDBusUtil
operator|::
name|disconnectedErrorMessage
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the address this server is associated with. */
end_comment
begin_function
DECL|function|address
name|QString
name|QDBusServer
operator|::
name|address
parameter_list|()
specifier|const
block|{
name|QString
name|addr
decl_stmt|;
if|if
condition|(
name|d
operator|&&
name|d
operator|->
name|server
condition|)
block|{
name|char
modifier|*
name|c
init|=
name|q_dbus_server_get_address
argument_list|(
name|d
operator|->
name|server
argument_list|)
decl_stmt|;
name|addr
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|q_dbus_free
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
return|return
name|addr
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.3      If \a value is set to true, an incoming connection can proceed even if the     connecting client is not authenticated as a user.      By default, this value is false.      \sa isAnonymousAuthenticationAllowed() */
end_comment
begin_function
DECL|function|setAnonymousAuthenticationAllowed
name|void
name|QDBusServer
operator|::
name|setAnonymousAuthenticationAllowed
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|d
operator|->
name|anonymousAuthenticationAllowed
operator|=
name|value
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 5.3      Returns true if anonymous authentication is allowed.      \sa setAnonymousAuthenticationAllowed() */
end_comment
begin_function
DECL|function|isAnonymousAuthenticationAllowed
name|bool
name|QDBusServer
operator|::
name|isAnonymousAuthenticationAllowed
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|anonymousAuthenticationAllowed
return|;
block|}
end_function
begin_comment
comment|/*!   \fn void QDBusServer::newConnection(const QDBusConnection&connection)    This signal is emitted when a new client connection \a connection is   established to the server.  */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qdbusserver.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
end_unit
