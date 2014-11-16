begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHTTPSOCKETENGINE_P_H
end_ifndef
begin_define
DECL|macro|QHTTPSOCKETENGINE_P_H
define|#
directive|define
name|QHTTPSOCKETENGINE_P_H
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
file|"private/qabstractsocketengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qabstractsocket.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkproxy.h"
end_include
begin_include
include|#
directive|include
file|"private/qauthenticator_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_NETWORKPROXY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_HTTP
argument_list|)
DECL|variable|QTcpSocket
name|class
name|QTcpSocket
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpNetworkReply
name|class
name|QHttpNetworkReply
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpSocketEnginePrivate
name|class
name|QHttpSocketEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QHttpSocketEngine
range|:
name|public
name|QAbstractSocketEngine
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|HttpState
block|{
name|None
block|,
name|ConnectSent
block|,
name|Connected
block|,
name|SendAuthentication
block|,
name|ReadResponseContent
block|,
name|ReadResponseHeader
block|}
block|;
name|QHttpSocketEngine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QHttpSocketEngine
argument_list|()
block|;
name|bool
name|initialize
argument_list|(
argument|QAbstractSocket::SocketType type
argument_list|,
argument|QAbstractSocket::NetworkLayerProtocol protocol = QAbstractSocket::IPv4Protocol
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|initialize
argument_list|(
argument|qintptr socketDescriptor
argument_list|,
argument|QAbstractSocket::SocketState socketState = QAbstractSocket::ConnectedState
argument_list|)
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|bool
name|connectToHostByName
argument_list|(
argument|const QString&name
argument_list|,
argument|quint16 port
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|bind
argument_list|(
argument|const QHostAddress&address
argument_list|,
argument|quint16 port
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|listen
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|int
name|accept
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|close
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|read
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|write
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
name|Q_DECL_OVERRIDE
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
argument|const QHostAddress&groupAddress
argument_list|,
argument|const QNetworkInterface&interface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|leaveMulticastGroup
argument_list|(
argument|const QHostAddress&groupAddress
argument_list|,
argument|const QNetworkInterface&interface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QNetworkInterface
name|multicastInterface
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setMulticastInterface
argument_list|(
argument|const QNetworkInterface&iface
argument_list|)
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasPendingDatagrams
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qint64
name|pendingDatagramSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
comment|// QT_NO_UDPSOCKET
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|option
argument_list|(
argument|SocketOption option
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setOption
argument_list|(
argument|SocketOption option
argument_list|,
argument|int value
argument_list|)
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
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
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isReadNotificationEnabled
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setReadNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isWriteNotificationEnabled
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setWriteNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isExceptionNotificationEnabled
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setExceptionNotificationEnabled
argument_list|(
argument|bool enable
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|public
name|slots
operator|:
name|void
name|slotSocketConnected
argument_list|()
block|;
name|void
name|slotSocketDisconnected
argument_list|()
block|;
name|void
name|slotSocketReadNotification
argument_list|()
block|;
name|void
name|slotSocketBytesWritten
argument_list|()
block|;
name|void
name|slotSocketError
argument_list|(
argument|QAbstractSocket::SocketError error
argument_list|)
block|;
name|void
name|slotSocketStateChanged
argument_list|(
argument|QAbstractSocket::SocketState state
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|emitPendingReadNotification
argument_list|()
block|;
name|void
name|emitPendingWriteNotification
argument_list|()
block|;
name|void
name|emitPendingConnectionNotification
argument_list|()
block|;
name|private
operator|:
name|void
name|emitReadNotification
argument_list|()
block|;
name|void
name|emitWriteNotification
argument_list|()
block|;
name|void
name|emitConnectionNotification
argument_list|()
block|;
name|bool
name|readHttpHeader
argument_list|()
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QHttpSocketEngine
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QHttpSocketEngine
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QHttpSocketEnginePrivate
range|:
name|public
name|QAbstractSocketEnginePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QHttpSocketEngine
argument_list|)
name|public
operator|:
name|QHttpSocketEnginePrivate
argument_list|()
block|;
operator|~
name|QHttpSocketEnginePrivate
argument_list|()
block|;
name|QNetworkProxy
name|proxy
block|;
name|QString
name|peerName
block|;
name|QTcpSocket
operator|*
name|socket
block|;
name|QHttpNetworkReply
operator|*
name|reply
block|;
comment|// only used for parsing the proxy response
name|QHttpSocketEngine
operator|::
name|HttpState
name|state
block|;
name|QAuthenticator
name|authenticator
block|;
name|bool
name|readNotificationEnabled
block|;
name|bool
name|writeNotificationEnabled
block|;
name|bool
name|exceptNotificationEnabled
block|;
name|bool
name|readNotificationActivated
block|;
name|bool
name|writeNotificationActivated
block|;
name|bool
name|readNotificationPending
block|;
name|bool
name|writeNotificationPending
block|;
name|bool
name|connectionNotificationPending
block|;
name|bool
name|credentialsSent
block|;
name|uint
name|pendingResponseData
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QHttpSocketEngineHandler
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
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QAbstractSocketEngine
operator|*
name|createSocketEngine
argument_list|(
argument|qintptr socketDescripter
argument_list|,
argument|QObject *parent
argument_list|)
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QHTTPSOCKETENGINE_H
end_comment
end_unit
