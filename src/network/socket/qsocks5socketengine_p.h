begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSOCKS5SOCKETENGINE_P_H
end_ifndef
begin_define
DECL|macro|QSOCKS5SOCKETENGINE_P_H
define|#
directive|define
name|QSOCKS5SOCKETENGINE_P_H
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
begin_include
include|#
directive|include
file|"qabstractsocketengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkproxy.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SOCKS5
DECL|variable|QSocks5SocketEnginePrivate
name|class
name|QSocks5SocketEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QSocks5SocketEngine
range|:
name|public
name|QAbstractSocketEngine
block|{
name|Q_OBJECT
name|public
operator|:
name|QSocks5SocketEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QSocks5SocketEngine
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
name|void
name|setProxy
argument_list|(
specifier|const
name|QNetworkProxy
operator|&
name|networkProxy
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
name|connectInternal
argument_list|()
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
ifndef|#
directive|ifndef
name|QT_NO_UDPSOCKET
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
name|interface
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
name|interface
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
comment|// QT_NO_NETWORKINTERFACE
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
endif|#
directive|endif
comment|// QT_NO_UDPSOCKET
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
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
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSocks5SocketEngine
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QSocks5SocketEngine
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_controlSocketConnected()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_controlSocketReadNotification()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_controlSocketError(QAbstractSocket::SocketError)
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_UDPSOCKET
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_udpSocketReadNotification()
argument_list|)
endif|#
directive|endif
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_controlSocketBytesWritten()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitPendingReadNotification()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitPendingWriteNotification()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_emitPendingConnectionNotification()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_controlSocketDisconnected()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_controlSocketStateChanged(QAbstractSocket::SocketState)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTcpSocket
name|class
name|QTcpSocket
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSocks5Authenticator
block|{
name|public
label|:
name|QSocks5Authenticator
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QSocks5Authenticator
argument_list|()
expr_stmt|;
name|virtual
name|char
name|methodId
parameter_list|()
function_decl|;
name|virtual
name|bool
name|beginAuthenticate
parameter_list|(
name|QTcpSocket
modifier|*
name|socket
parameter_list|,
name|bool
modifier|*
name|completed
parameter_list|)
function_decl|;
name|virtual
name|bool
name|continueAuthenticate
parameter_list|(
name|QTcpSocket
modifier|*
name|socket
parameter_list|,
name|bool
modifier|*
name|completed
parameter_list|)
function_decl|;
name|virtual
name|bool
name|seal
parameter_list|(
specifier|const
name|QByteArray
name|buf
parameter_list|,
name|QByteArray
modifier|*
name|sealedBuf
parameter_list|)
function_decl|;
name|virtual
name|bool
name|unSeal
parameter_list|(
specifier|const
name|QByteArray
name|sealedBuf
parameter_list|,
name|QByteArray
modifier|*
name|buf
parameter_list|)
function_decl|;
name|virtual
name|bool
name|unSeal
parameter_list|(
name|QTcpSocket
modifier|*
name|sealedSocket
parameter_list|,
name|QByteArray
modifier|*
name|buf
parameter_list|)
function_decl|;
name|virtual
name|QString
name|errorString
parameter_list|()
block|{
return|return
name|QString
argument_list|()
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QSocks5PasswordAuthenticator
range|:
name|public
name|QSocks5Authenticator
block|{
name|public
operator|:
name|QSocks5PasswordAuthenticator
argument_list|(
specifier|const
name|QString
operator|&
name|userName
argument_list|,
specifier|const
name|QString
operator|&
name|password
argument_list|)
block|;
name|char
name|methodId
argument_list|()
block|;
name|bool
name|beginAuthenticate
argument_list|(
name|QTcpSocket
operator|*
name|socket
argument_list|,
name|bool
operator|*
name|completed
argument_list|)
block|;
name|bool
name|continueAuthenticate
argument_list|(
name|QTcpSocket
operator|*
name|socket
argument_list|,
name|bool
operator|*
name|completed
argument_list|)
block|;
name|QString
name|errorString
argument_list|()
block|;
name|private
operator|:
name|QString
name|userName
block|;
name|QString
name|password
block|; }
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QSocks5Data
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|QSocks5ConnectData
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|QSocks5UdpAssociateData
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|QSocks5BindData
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|QSocks5SocketEnginePrivate
range|:
name|public
name|QAbstractSocketEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QSocks5SocketEngine
argument_list|)
name|public
operator|:
name|QSocks5SocketEnginePrivate
argument_list|()
block|;
operator|~
name|QSocks5SocketEnginePrivate
argument_list|()
block|;     enum
name|Socks5State
block|{
name|Uninitialized
operator|=
literal|0
block|,
name|ConnectError
block|,
name|AuthenticationMethodsSent
block|,
name|Authenticating
block|,
name|AuthenticatingError
block|,
name|RequestMethodSent
block|,
name|RequestError
block|,
name|Connected
block|,
name|UdpAssociateSuccess
block|,
name|BindSuccess
block|,
name|ControlSocketError
block|,
name|SocksError
block|,
name|HostNameLookupError
block|}
block|;
name|Socks5State
name|socks5State
block|;      enum
name|Socks5Mode
block|{
name|NoMode
block|,
name|ConnectMode
block|,
name|BindMode
block|,
name|UdpAssociateMode
block|}
block|;
name|Socks5Mode
name|mode
block|;      enum
name|Socks5Error
block|{
name|SocksFailure
operator|=
literal|0x01
block|,
name|ConnectionNotAllowed
operator|=
literal|0x02
block|,
name|NetworkUnreachable
operator|=
literal|0x03
block|,
name|HostUnreachable
operator|=
literal|0x04
block|,
name|ConnectionRefused
operator|=
literal|0x05
block|,
name|TTLExpired
operator|=
literal|0x06
block|,
name|CommandNotSupported
operator|=
literal|0x07
block|,
name|AddressTypeNotSupported
operator|=
literal|0x08
block|,
name|LastKnownError
operator|=
name|AddressTypeNotSupported
block|,
name|UnknownError
block|}
block|;
name|void
name|initialize
argument_list|(
argument|Socks5Mode socks5Mode
argument_list|)
block|;
name|void
name|setErrorState
argument_list|(
argument|Socks5State state
argument_list|,
argument|const QString&extraMessage = QString()
argument_list|)
block|;
name|void
name|setErrorState
argument_list|(
argument|Socks5State state
argument_list|,
argument|Socks5Error socks5error
argument_list|)
block|;
name|void
name|reauthenticate
argument_list|()
block|;
name|void
name|parseAuthenticationMethodReply
argument_list|()
block|;
name|void
name|parseAuthenticatingReply
argument_list|()
block|;
name|void
name|sendRequestMethod
argument_list|()
block|;
name|void
name|parseRequestMethodReply
argument_list|()
block|;
name|void
name|parseNewConnection
argument_list|()
block|;
name|bool
name|waitForConnected
argument_list|(
argument|int msecs
argument_list|,
argument|bool *timedOut
argument_list|)
block|;
name|void
name|_q_controlSocketConnected
argument_list|()
block|;
name|void
name|_q_controlSocketReadNotification
argument_list|()
block|;
name|void
name|_q_controlSocketError
argument_list|(
name|QAbstractSocket
operator|::
name|SocketError
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_UDPSOCKET
name|void
name|checkForDatagrams
argument_list|()
specifier|const
block|;
name|void
name|_q_udpSocketReadNotification
argument_list|()
block|;
endif|#
directive|endif
name|void
name|_q_controlSocketBytesWritten
argument_list|()
block|;
name|void
name|_q_controlSocketDisconnected
argument_list|()
block|;
name|void
name|_q_controlSocketStateChanged
argument_list|(
name|QAbstractSocket
operator|::
name|SocketState
argument_list|)
block|;
name|QNetworkProxy
name|proxyInfo
block|;
name|bool
name|readNotificationEnabled
block|,
name|writeNotificationEnabled
block|,
name|exceptNotificationEnabled
block|;
name|qintptr
name|socketDescriptor
block|;
name|QSocks5Data
operator|*
name|data
block|;
name|QSocks5ConnectData
operator|*
name|connectData
block|;
ifndef|#
directive|ifndef
name|QT_NO_UDPSOCKET
name|QSocks5UdpAssociateData
operator|*
name|udpData
block|;
endif|#
directive|endif
name|QSocks5BindData
operator|*
name|bindData
block|;
name|QString
name|peerName
block|;
name|QByteArray
name|receivedHeaderFragment
block|;
name|mutable
name|bool
name|readNotificationActivated
block|;
name|mutable
name|bool
name|writeNotificationActivated
block|;
name|bool
name|readNotificationPending
block|;
name|void
name|_q_emitPendingReadNotification
argument_list|()
block|;
name|void
name|emitReadNotification
argument_list|()
block|;
name|bool
name|writeNotificationPending
block|;
name|void
name|_q_emitPendingWriteNotification
argument_list|()
block|;
name|void
name|emitWriteNotification
argument_list|()
block|;
name|bool
name|connectionNotificationPending
block|;
name|void
name|_q_emitPendingConnectionNotification
argument_list|()
block|;
name|void
name|emitConnectionNotification
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QSocks5SocketEngineHandler
range|:
name|public
name|QSocketEngineHandler
block|{
name|public
operator|:
name|virtual
name|QAbstractSocketEngine
operator|*
name|createSocketEngine
argument_list|(
argument|QAbstractSocket::SocketType socketType
argument_list|,
argument|const QNetworkProxy&
argument_list|,
argument|QObject *parent
argument_list|)
block|;
name|virtual
name|QAbstractSocketEngine
operator|*
name|createSocketEngine
argument_list|(
argument|qintptr socketDescriptor
argument_list|,
argument|QObject *parent
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
comment|// QT_NO_SOCKS5
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSOCKS5SOCKETENGINE_H
end_comment
end_unit
