begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qabstractsocketengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qnativesocketengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkproxy.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QSocketEngineHandlerList
class|class
name|QSocketEngineHandlerList
super|:
specifier|public
name|QList
argument_list|<
name|QSocketEngineHandler
modifier|*
argument_list|>
block|{
public|public:
DECL|member|mutex
name|QMutex
name|mutex
decl_stmt|;
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QSocketEngineHandlerList
argument_list|,
argument|socketHandlers
argument_list|)
end_macro
begin_constructor
DECL|function|QSocketEngineHandler
name|QSocketEngineHandler
operator|::
name|QSocketEngineHandler
parameter_list|()
block|{
if|if
condition|(
operator|!
name|socketHandlers
argument_list|()
condition|)
return|return;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|socketHandlers
argument_list|()
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|socketHandlers
argument_list|()
operator|->
name|prepend
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QSocketEngineHandler
name|QSocketEngineHandler
operator|::
name|~
name|QSocketEngineHandler
parameter_list|()
block|{
if|if
condition|(
operator|!
name|socketHandlers
argument_list|()
condition|)
return|return;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|socketHandlers
argument_list|()
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|socketHandlers
argument_list|()
operator|->
name|removeAll
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_constructor
DECL|function|QAbstractSocketEnginePrivate
name|QAbstractSocketEnginePrivate
operator|::
name|QAbstractSocketEnginePrivate
parameter_list|()
member_init_list|:
name|socketError
argument_list|(
name|QAbstractSocket
operator|::
name|UnknownSocketError
argument_list|)
member_init_list|,
name|hasSetSocketError
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|socketErrorString
argument_list|(
name|QLatin1String
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
name|QSocketLayer
argument_list|,
literal|"Unknown error"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|socketState
argument_list|(
name|QAbstractSocket
operator|::
name|UnconnectedState
argument_list|)
member_init_list|,
name|socketType
argument_list|(
name|QAbstractSocket
operator|::
name|UnknownSocketType
argument_list|)
member_init_list|,
name|socketProtocol
argument_list|(
name|QAbstractSocket
operator|::
name|UnknownNetworkLayerProtocol
argument_list|)
member_init_list|,
name|localPort
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|peerPort
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|receiver
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QAbstractSocketEngine
name|QAbstractSocketEngine
operator|::
name|QAbstractSocketEngine
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QAbstractSocketEnginePrivate
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QAbstractSocketEngine
name|QAbstractSocketEngine
operator|::
name|QAbstractSocketEngine
parameter_list|(
name|QAbstractSocketEnginePrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|createSocketEngine
name|QAbstractSocketEngine
modifier|*
name|QAbstractSocketEngine
operator|::
name|createSocketEngine
parameter_list|(
name|QAbstractSocket
operator|::
name|SocketType
name|socketType
parameter_list|,
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
comment|// proxy type must have been resolved by now
if|if
condition|(
name|proxy
operator|.
name|type
argument_list|()
operator|==
name|QNetworkProxy
operator|::
name|DefaultProxy
condition|)
return|return
literal|0
return|;
endif|#
directive|endif
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|socketHandlers
argument_list|()
operator|->
name|mutex
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|socketHandlers
argument_list|()
operator|->
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|QAbstractSocketEngine
modifier|*
name|ret
init|=
name|socketHandlers
argument_list|()
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|createSocketEngine
argument_list|(
name|socketType
argument_list|,
name|proxy
argument_list|,
name|parent
argument_list|)
condition|)
return|return
name|ret
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
comment|// only NoProxy can have reached here
if|if
condition|(
name|proxy
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkProxy
operator|::
name|NoProxy
condition|)
return|return
literal|0
return|;
endif|#
directive|endif
return|return
operator|new
name|QNativeSocketEngine
argument_list|(
name|parent
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createSocketEngine
name|QAbstractSocketEngine
modifier|*
name|QAbstractSocketEngine
operator|::
name|createSocketEngine
parameter_list|(
name|qintptr
name|socketDescripter
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|socketHandlers
argument_list|()
operator|->
name|mutex
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|socketHandlers
argument_list|()
operator|->
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|QAbstractSocketEngine
modifier|*
name|ret
init|=
name|socketHandlers
argument_list|()
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|createSocketEngine
argument_list|(
name|socketDescripter
argument_list|,
name|parent
argument_list|)
condition|)
return|return
name|ret
return|;
block|}
return|return
operator|new
name|QNativeSocketEngine
argument_list|(
name|parent
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|error
name|QAbstractSocket
operator|::
name|SocketError
name|QAbstractSocketEngine
operator|::
name|error
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|socketError
return|;
block|}
end_function
begin_function
DECL|function|errorString
name|QString
name|QAbstractSocketEngine
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|socketErrorString
return|;
block|}
end_function
begin_function
DECL|function|setError
name|void
name|QAbstractSocketEngine
operator|::
name|setError
parameter_list|(
name|QAbstractSocket
operator|::
name|SocketError
name|error
parameter_list|,
specifier|const
name|QString
modifier|&
name|errorString
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractSocketEngine
argument_list|)
expr_stmt|;
name|d
operator|->
name|socketError
operator|=
name|error
expr_stmt|;
name|d
operator|->
name|socketErrorString
operator|=
name|errorString
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setReceiver
name|void
name|QAbstractSocketEngine
operator|::
name|setReceiver
parameter_list|(
name|QAbstractSocketEngineReceiver
modifier|*
name|receiver
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|receiver
operator|=
name|receiver
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readNotification
name|void
name|QAbstractSocketEngine
operator|::
name|readNotification
parameter_list|()
block|{
if|if
condition|(
name|QAbstractSocketEngineReceiver
modifier|*
name|receiver
init|=
name|d_func
argument_list|()
operator|->
name|receiver
condition|)
name|receiver
operator|->
name|readNotification
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writeNotification
name|void
name|QAbstractSocketEngine
operator|::
name|writeNotification
parameter_list|()
block|{
if|if
condition|(
name|QAbstractSocketEngineReceiver
modifier|*
name|receiver
init|=
name|d_func
argument_list|()
operator|->
name|receiver
condition|)
name|receiver
operator|->
name|writeNotification
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|exceptionNotification
name|void
name|QAbstractSocketEngine
operator|::
name|exceptionNotification
parameter_list|()
block|{
if|if
condition|(
name|QAbstractSocketEngineReceiver
modifier|*
name|receiver
init|=
name|d_func
argument_list|()
operator|->
name|receiver
condition|)
name|receiver
operator|->
name|exceptionNotification
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|closeNotification
name|void
name|QAbstractSocketEngine
operator|::
name|closeNotification
parameter_list|()
block|{
if|if
condition|(
name|QAbstractSocketEngineReceiver
modifier|*
name|receiver
init|=
name|d_func
argument_list|()
operator|->
name|receiver
condition|)
name|receiver
operator|->
name|closeNotification
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connectionNotification
name|void
name|QAbstractSocketEngine
operator|::
name|connectionNotification
parameter_list|()
block|{
if|if
condition|(
name|QAbstractSocketEngineReceiver
modifier|*
name|receiver
init|=
name|d_func
argument_list|()
operator|->
name|receiver
condition|)
name|receiver
operator|->
name|connectionNotification
argument_list|()
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_function
DECL|function|proxyAuthenticationRequired
name|void
name|QAbstractSocketEngine
operator|::
name|proxyAuthenticationRequired
parameter_list|(
specifier|const
name|QNetworkProxy
modifier|&
name|proxy
parameter_list|,
name|QAuthenticator
modifier|*
name|authenticator
parameter_list|)
block|{
if|if
condition|(
name|QAbstractSocketEngineReceiver
modifier|*
name|receiver
init|=
name|d_func
argument_list|()
operator|->
name|receiver
condition|)
name|receiver
operator|->
name|proxyAuthenticationRequired
argument_list|(
name|proxy
argument_list|,
name|authenticator
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|state
name|QAbstractSocket
operator|::
name|SocketState
name|QAbstractSocketEngine
operator|::
name|state
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|socketState
return|;
block|}
end_function
begin_function
DECL|function|setState
name|void
name|QAbstractSocketEngine
operator|::
name|setState
parameter_list|(
name|QAbstractSocket
operator|::
name|SocketState
name|state
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|socketState
operator|=
name|state
expr_stmt|;
block|}
end_function
begin_function
DECL|function|socketType
name|QAbstractSocket
operator|::
name|SocketType
name|QAbstractSocketEngine
operator|::
name|socketType
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|socketType
return|;
block|}
end_function
begin_function
DECL|function|setSocketType
name|void
name|QAbstractSocketEngine
operator|::
name|setSocketType
parameter_list|(
name|QAbstractSocket
operator|::
name|SocketType
name|socketType
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|socketType
operator|=
name|socketType
expr_stmt|;
block|}
end_function
begin_function
DECL|function|protocol
name|QAbstractSocket
operator|::
name|NetworkLayerProtocol
name|QAbstractSocketEngine
operator|::
name|protocol
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|socketProtocol
return|;
block|}
end_function
begin_function
DECL|function|setProtocol
name|void
name|QAbstractSocketEngine
operator|::
name|setProtocol
parameter_list|(
name|QAbstractSocket
operator|::
name|NetworkLayerProtocol
name|protocol
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|socketProtocol
operator|=
name|protocol
expr_stmt|;
block|}
end_function
begin_function
DECL|function|localAddress
name|QHostAddress
name|QAbstractSocketEngine
operator|::
name|localAddress
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|localAddress
return|;
block|}
end_function
begin_function
DECL|function|setLocalAddress
name|void
name|QAbstractSocketEngine
operator|::
name|setLocalAddress
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|address
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|localAddress
operator|=
name|address
expr_stmt|;
block|}
end_function
begin_function
DECL|function|localPort
name|quint16
name|QAbstractSocketEngine
operator|::
name|localPort
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|localPort
return|;
block|}
end_function
begin_function
DECL|function|setLocalPort
name|void
name|QAbstractSocketEngine
operator|::
name|setLocalPort
parameter_list|(
name|quint16
name|port
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|localPort
operator|=
name|port
expr_stmt|;
block|}
end_function
begin_function
DECL|function|peerAddress
name|QHostAddress
name|QAbstractSocketEngine
operator|::
name|peerAddress
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|peerAddress
return|;
block|}
end_function
begin_function
DECL|function|setPeerAddress
name|void
name|QAbstractSocketEngine
operator|::
name|setPeerAddress
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|address
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|peerAddress
operator|=
name|address
expr_stmt|;
block|}
end_function
begin_function
DECL|function|peerPort
name|quint16
name|QAbstractSocketEngine
operator|::
name|peerPort
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|peerPort
return|;
block|}
end_function
begin_function
DECL|function|setPeerPort
name|void
name|QAbstractSocketEngine
operator|::
name|setPeerPort
parameter_list|(
name|quint16
name|port
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|peerPort
operator|=
name|port
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
