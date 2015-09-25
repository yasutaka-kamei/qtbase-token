begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTSOCKET_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTSOCKET_P_H
define|#
directive|define
name|QABSTRACTSOCKET_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QAbstractSocket class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
begin_include
include|#
directive|include
file|"QtNetwork/qabstractsocket.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbytearray.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qtimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qringbuffer_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qiodevice_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractsocketengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkproxy.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QHostInfo
name|class
name|QHostInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevicePrivate
name|class
name|QAbstractSocketPrivate
range|:
name|public
name|QIODevicePrivate
decl_stmt|,
name|public
name|QAbstractSocketEngineReceiver
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractSocket
argument_list|)
name|public
label|:
name|QAbstractSocketPrivate
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QAbstractSocketPrivate
argument_list|()
expr_stmt|;
comment|// from QAbstractSocketEngineReceiver
specifier|inline
name|void
name|readNotification
parameter_list|()
block|{
name|canReadNotification
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|void
name|writeNotification
parameter_list|()
block|{
name|canWriteNotification
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|void
name|exceptionNotification
parameter_list|()
block|{}
specifier|inline
name|void
name|closeNotification
parameter_list|()
block|{
name|canCloseNotification
argument_list|()
expr_stmt|;
block|}
name|void
name|connectionNotification
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
specifier|inline
name|void
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
name|Q_Q
argument_list|(
name|QAbstractSocket
argument_list|)
expr_stmt|;
name|q
operator|->
name|proxyAuthenticationRequired
argument_list|(
name|proxy
argument_list|,
name|authenticator
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|virtual
name|bool
name|bind
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|address
argument_list|,
name|quint16
name|port
argument_list|,
name|QAbstractSocket
operator|::
name|BindMode
name|mode
argument_list|)
decl_stmt|;
name|bool
name|canReadNotification
parameter_list|()
function_decl|;
name|bool
name|canWriteNotification
parameter_list|()
function_decl|;
name|void
name|canCloseNotification
parameter_list|()
function_decl|;
comment|// slots
name|void
name|_q_connectToNextAddress
parameter_list|()
function_decl|;
name|void
name|_q_startConnecting
parameter_list|(
specifier|const
name|QHostInfo
modifier|&
name|hostInfo
parameter_list|)
function_decl|;
name|void
name|_q_testConnection
parameter_list|()
function_decl|;
name|void
name|_q_abortConnectionAttempt
parameter_list|()
function_decl|;
name|void
name|_q_forceDisconnect
parameter_list|()
function_decl|;
name|bool
name|readSocketNotifierCalled
decl_stmt|;
name|bool
name|readSocketNotifierState
decl_stmt|;
name|bool
name|readSocketNotifierStateSet
decl_stmt|;
name|bool
name|emittedReadyRead
decl_stmt|;
name|bool
name|emittedBytesWritten
decl_stmt|;
name|bool
name|abortCalled
decl_stmt|;
name|bool
name|pendingClose
decl_stmt|;
name|QAbstractSocket
operator|::
name|PauseModes
name|pauseMode
expr_stmt|;
name|QString
name|hostName
decl_stmt|;
name|quint16
name|port
decl_stmt|;
name|QHostAddress
name|host
decl_stmt|;
name|QList
operator|<
name|QHostAddress
operator|>
name|addresses
expr_stmt|;
name|quint16
name|localPort
decl_stmt|;
name|quint16
name|peerPort
decl_stmt|;
name|QHostAddress
name|localAddress
decl_stmt|;
name|QHostAddress
name|peerAddress
decl_stmt|;
name|QString
name|peerName
decl_stmt|;
name|QAbstractSocketEngine
modifier|*
name|socketEngine
decl_stmt|;
name|qintptr
name|cachedSocketDescriptor
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QNetworkProxy
name|proxy
decl_stmt|;
name|QNetworkProxy
name|proxyInUse
decl_stmt|;
name|void
name|resolveProxy
parameter_list|(
specifier|const
name|QString
modifier|&
name|hostName
parameter_list|,
name|quint16
name|port
parameter_list|)
function_decl|;
else|#
directive|else
specifier|inline
name|void
name|resolveProxy
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
name|quint16
parameter_list|)
block|{ }
endif|#
directive|endif
specifier|inline
name|void
name|resolveProxy
parameter_list|(
name|quint16
name|port
parameter_list|)
block|{
name|resolveProxy
argument_list|(
name|QString
argument_list|()
argument_list|,
name|port
argument_list|)
expr_stmt|;
block|}
name|void
name|resetSocketLayer
parameter_list|()
function_decl|;
name|bool
name|flush
parameter_list|()
function_decl|;
name|bool
name|initSocketLayer
argument_list|(
name|QAbstractSocket
operator|::
name|NetworkLayerProtocol
name|protocol
argument_list|)
decl_stmt|;
name|virtual
name|void
name|configureCreatedSocket
parameter_list|()
function_decl|;
name|void
name|startConnectingByName
parameter_list|(
specifier|const
name|QString
modifier|&
name|host
parameter_list|)
function_decl|;
name|void
name|fetchConnectionParameters
parameter_list|()
function_decl|;
name|void
name|setupSocketNotifiers
parameter_list|()
function_decl|;
name|bool
name|readFromSocket
parameter_list|()
function_decl|;
name|bool
name|writeToSocket
parameter_list|()
function_decl|;
name|void
name|emitReadyRead
parameter_list|()
function_decl|;
name|void
name|setError
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
name|errorCode
argument_list|,
specifier|const
name|QString
operator|&
name|errorString
argument_list|)
decl_stmt|;
name|void
name|setErrorAndEmit
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
name|errorCode
argument_list|,
specifier|const
name|QString
operator|&
name|errorString
argument_list|)
decl_stmt|;
name|qint64
name|readBufferMaxSize
decl_stmt|;
name|QRingBuffer
name|writeBuffer
decl_stmt|;
name|bool
name|isBuffered
decl_stmt|;
name|QTimer
modifier|*
name|connectTimer
decl_stmt|;
name|QTimer
modifier|*
name|disconnectTimer
decl_stmt|;
name|int
name|connectTimeElapsed
decl_stmt|;
name|int
name|hostLookupId
decl_stmt|;
name|QAbstractSocket
operator|::
name|SocketType
name|socketType
expr_stmt|;
name|QAbstractSocket
operator|::
name|SocketState
name|state
expr_stmt|;
name|QAbstractSocket
operator|::
name|SocketError
name|socketError
expr_stmt|;
name|QAbstractSocket
operator|::
name|NetworkLayerProtocol
name|preferredNetworkLayerProtocol
expr_stmt|;
name|bool
name|prePauseReadSocketNotifierState
decl_stmt|;
name|bool
name|prePauseWriteSocketNotifierState
decl_stmt|;
name|bool
name|prePauseExceptionSocketNotifierState
decl_stmt|;
specifier|static
name|void
name|pauseSocketNotifiers
parameter_list|(
name|QAbstractSocket
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|void
name|resumeSocketNotifiers
parameter_list|(
name|QAbstractSocket
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|QAbstractSocketEngine
modifier|*
name|getSocketEngine
parameter_list|(
name|QAbstractSocket
modifier|*
parameter_list|)
function_decl|;
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
begin_comment
comment|// QABSTRACTSOCKET_P_H
end_comment
end_unit
