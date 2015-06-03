begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNATIVESOCKETENGINE_WINRT_P_H
end_ifndef
begin_define
DECL|macro|QNATIVESOCKETENGINE_WINRT_P_H
define|#
directive|define
name|QNATIVESOCKETENGINE_WINRT_P_H
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
comment|// of the QLibrary class.  This header file may change from
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
file|<QtCore/QEventLoop>
end_include
begin_include
include|#
directive|include
file|<QtCore/QBuffer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_include
include|#
directive|include
file|"QtNetwork/qhostaddress.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractsocketengine_p.h"
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.networking.sockets.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QNativeSocketEnginePrivate
name|class
name|QNativeSocketEnginePrivate
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|WinRtDatagram
struct|struct
name|WinRtDatagram
block|{
DECL|member|data
name|QByteArray
name|data
decl_stmt|;
DECL|member|port
name|int
name|port
decl_stmt|;
DECL|member|address
name|QHostAddress
name|address
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QNativeSocketEngine
range|:
name|public
name|QAbstractSocketEngine
block|{
name|Q_OBJECT
name|public
operator|:
name|QNativeSocketEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QNativeSocketEngine
argument_list|()
block|;
name|bool
name|initialize
argument_list|(
argument|QAbstractSocket::SocketType type
argument_list|,
argument|QAbstractSocket::NetworkLayerProtocol protocol = QAbstractSocket::IPv4Protocol
argument_list|)
block|;
name|bool
name|initialize
argument_list|(
argument|qintptr socketDescriptor
argument_list|,
argument|QAbstractSocket::SocketState socketState = QAbstractSocket::ConnectedState
argument_list|)
block|;
name|qintptr
name|socketDescriptor
argument_list|()
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|bool
name|connectToHost
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|connectToHostByName
argument_list|(
argument|const QString&name
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|bind
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|listen
argument_list|()
block|;
name|int
name|accept
argument_list|()
block|;
name|void
name|close
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
name|bool
name|joinMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|,
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
name|bool
name|leaveMulticastGroup
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|groupAddress
argument_list|,
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
name|QNetworkInterface
name|multicastInterface
argument_list|()
specifier|const
block|;
name|bool
name|setMulticastInterface
argument_list|(
specifier|const
name|QNetworkInterface
operator|&
name|iface
argument_list|)
block|;
endif|#
directive|endif
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
block|;
name|qint64
name|read
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|write
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|qint64
name|readDatagram
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|,
argument|QHostAddress *addr =
literal|0
argument_list|,
argument|quint16 *port =
literal|0
argument_list|)
block|;
name|qint64
name|writeDatagram
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|,
argument|const QHostAddress&addr
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|bool
name|hasPendingDatagrams
argument_list|()
specifier|const
block|;
name|qint64
name|pendingDatagramSize
argument_list|()
specifier|const
block|;
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
block|;
name|qint64
name|receiveBufferSize
argument_list|()
specifier|const
block|;
name|void
name|setReceiveBufferSize
argument_list|(
argument|qint64 bufferSize
argument_list|)
block|;
name|qint64
name|sendBufferSize
argument_list|()
specifier|const
block|;
name|void
name|setSendBufferSize
argument_list|(
argument|qint64 bufferSize
argument_list|)
block|;
name|int
name|option
argument_list|(
argument|SocketOption option
argument_list|)
specifier|const
block|;
name|bool
name|setOption
argument_list|(
argument|SocketOption option
argument_list|,
argument|int value
argument_list|)
block|;
name|bool
name|waitForRead
argument_list|(
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
block|;
name|bool
name|waitForWrite
argument_list|(
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
block|;
name|bool
name|waitForReadOrWrite
argument_list|(
argument|bool *readyToRead
argument_list|,
argument|bool *readyToWrite
argument_list|,
argument|bool checkRead
argument_list|,
argument|bool checkWrite
argument_list|,
argument|int msecs =
literal|30000
argument_list|,
argument|bool *timedOut =
literal|0
argument_list|)
block|;
name|bool
name|isReadNotificationEnabled
argument_list|()
specifier|const
block|;
name|void
name|setReadNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isWriteNotificationEnabled
argument_list|()
specifier|const
block|;
name|void
name|setWriteNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isExceptionNotificationEnabled
argument_list|()
specifier|const
block|;
name|void
name|setExceptionNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|signals
operator|:
name|void
name|connectionReady
argument_list|()
block|;
name|void
name|readReady
argument_list|()
block|;
name|void
name|writeReady
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|establishRead
argument_list|()
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QNativeSocketEngine
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QNativeSocketEngine
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNativeSocketEnginePrivate
range|:
name|public
name|QAbstractSocketEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QNativeSocketEngine
argument_list|)
name|public
operator|:
name|QNativeSocketEnginePrivate
argument_list|()
block|;
operator|~
name|QNativeSocketEnginePrivate
argument_list|()
block|;
name|qintptr
name|socketDescriptor
block|;
name|bool
name|notifyOnRead
block|,
name|notifyOnWrite
block|,
name|notifyOnException
block|;
name|bool
name|closingDown
block|;      enum
name|ErrorString
block|{
name|NonBlockingInitFailedErrorString
block|,
name|BroadcastingInitFailedErrorString
block|,
name|NoIpV6ErrorString
block|,
name|RemoteHostClosedErrorString
block|,
name|TimeOutErrorString
block|,
name|ResourceErrorString
block|,
name|OperationUnsupportedErrorString
block|,
name|ProtocolUnsupportedErrorString
block|,
name|InvalidSocketErrorString
block|,
name|HostUnreachableErrorString
block|,
name|NetworkUnreachableErrorString
block|,
name|AccessErrorString
block|,
name|ConnectionTimeOutErrorString
block|,
name|ConnectionRefusedErrorString
block|,
name|AddressInuseErrorString
block|,
name|AddressNotAvailableErrorString
block|,
name|AddressProtectedErrorString
block|,
name|DatagramTooLargeErrorString
block|,
name|SendDatagramErrorString
block|,
name|ReceiveDatagramErrorString
block|,
name|WriteErrorString
block|,
name|ReadErrorString
block|,
name|PortInuseErrorString
block|,
name|NotSocketErrorString
block|,
name|InvalidProxyTypeString
block|,
name|TemporaryErrorString
block|,
name|UnknownSocketErrorString
operator|=
operator|-
literal|1
block|}
block|;
name|void
name|setError
argument_list|(
argument|QAbstractSocket::SocketError error
argument_list|,
argument|ErrorString errorString
argument_list|)
specifier|const
block|;
comment|// native functions
name|int
name|option
argument_list|(
argument|QNativeSocketEngine::SocketOption option
argument_list|)
specifier|const
block|;
name|bool
name|setOption
argument_list|(
argument|QNativeSocketEngine::SocketOption option
argument_list|,
argument|int value
argument_list|)
block|;
name|bool
name|createNewSocket
argument_list|(
argument|QAbstractSocket::SocketType type
argument_list|,
argument|QAbstractSocket::NetworkLayerProtocol&protocol
argument_list|)
block|;
name|bool
name|checkProxy
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|address
argument_list|)
block|;
name|bool
name|fetchConnectionParameters
argument_list|()
block|;
name|private
operator|:
specifier|inline
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IStreamSocket
operator|*
name|tcpSocket
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IStreamSocket
operator|*
operator|>
operator|(
name|socketDescriptor
operator|)
return|;
block|}
specifier|inline
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IDatagramSocket
operator|*
name|udpSocket
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IDatagramSocket
operator|*
operator|>
operator|(
name|socketDescriptor
operator|)
return|;
block|}
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IStreamSocketListener
operator|>
name|tcpListener
block|;
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|IAsyncAction
operator|>
name|connectOp
block|;
name|QBuffer
name|readBytes
block|;
name|QMutex
name|readMutex
block|;
name|QList
operator|<
name|WinRtDatagram
operator|>
name|pendingDatagrams
block|;
name|QList
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IStreamSocket
operator|*
operator|>
name|pendingConnections
block|;
name|QList
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IStreamSocket
operator|*
operator|>
name|currentConnections
block|;
name|QEventLoop
name|eventLoop
block|;
name|QAbstractSocket
operator|*
name|sslSocket
block|;
name|HRESULT
name|handleBindCompleted
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|IAsyncAction
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|AsyncStatus
argument_list|)
block|;
name|HRESULT
name|handleNewDatagram
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IDatagramSocket
operator|*
name|socket
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IDatagramSocketMessageReceivedEventArgs
operator|*
name|args
argument_list|)
block|;
name|HRESULT
name|handleClientConnection
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IStreamSocketListener
operator|*
name|tcpListener
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
operator|::
name|IStreamSocketListenerConnectionReceivedEventArgs
operator|*
name|args
argument_list|)
block|;
name|HRESULT
name|handleConnectToHost
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|IAsyncAction
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|AsyncStatus
argument_list|)
block|;
name|HRESULT
name|handleReadyRead
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|IAsyncOperationWithProgress
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|Storage
operator|::
name|Streams
operator|::
name|IBuffer
operator|*
argument_list|,
name|UINT32
operator|>
operator|*
name|asyncInfo
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|AsyncStatus
argument_list|)
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
comment|// QNATIVESOCKETENGINE_WINRT_P_H
end_comment
end_unit
