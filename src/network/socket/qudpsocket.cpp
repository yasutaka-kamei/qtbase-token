begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//#define QUDPSOCKET_DEBUG
end_comment
begin_comment
comment|/*! \class QUdpSocket      \reentrant     \brief The QUdpSocket class provides a UDP socket.      \ingroup network     \inmodule QtNetwork      UDP (User Datagram Protocol) is a lightweight, unreliable,     datagram-oriented, connectionless protocol. It can be used when     reliability isn't important. QUdpSocket is a subclass of     QAbstractSocket that allows you to send and receive UDP     datagrams.      The most common way to use this class is to bind to an address and port     using bind(), then call writeDatagram() and readDatagram() to transfer     data. If you want to use the standard QIODevice functions read(),     readLine(), write(), etc., you must first connect the socket directly to a     peer by calling connectToHost().      The socket emits the bytesWritten() signal every time a datagram     is written to the network. If you just want to send datagrams,     you don't need to call bind().      The readyRead() signal is emitted whenever datagrams arrive. In     that case, hasPendingDatagrams() returns true. Call     pendingDatagramSize() to obtain the size of the first pending     datagram, and readDatagram() to read it.      \note An incoming datagram should be read when you receive the readyRead()     signal, otherwise this signal will not be emitted for the next datagram.      Example:      \snippet doc/src/snippets/code/src_network_socket_qudpsocket.cpp 0      QUdpSocket also supports UDP multicast. Use joinMulticastGroup() and     leaveMulticastGroup() to control group membership, and     QAbstractSocket::MulticastTtlOption and     QAbstractSocket::MulticastLoopbackOption to set the TTL and loopback socket     options. Use setMulticastInterface() to control the outgoing interface for     multicast datagrams, and multicastInterface() to query it.      With QUdpSocket, you can also establish a virtual connection to a     UDP server using connectToHost() and then use read() and write()     to exchange datagrams without specifying the receiver for each     datagram.      The \l{network/broadcastsender}{Broadcast Sender},     \l{network/broadcastreceiver}{Broadcast Receiver},     \l{network/multicastsender}{Multicast Sender}, and     \l{network/multicastreceiver}{Multicast Receiver} examples illustrate how     to use QUdpSocket in applications.      \sa QTcpSocket */
end_comment
begin_include
include|#
directive|include
file|"qhostaddress.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkinterface.h"
end_include
begin_include
include|#
directive|include
file|"qabstractsocket_p.h"
end_include
begin_include
include|#
directive|include
file|"qudpsocket.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_UDPSOCKET
end_ifndef
begin_define
DECL|macro|QT_CHECK_BOUND
define|#
directive|define
name|QT_CHECK_BOUND
parameter_list|(
name|function
parameter_list|,
name|a
parameter_list|)
value|do { \     if (!isValid()) { \         qWarning(function" called on a QUdpSocket when not in QUdpSocket::BoundState"); \         return (a); \     } } while (0)
end_define
begin_class
DECL|class|QUdpSocketPrivate
class|class
name|QUdpSocketPrivate
super|:
specifier|public
name|QAbstractSocketPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QUdpSocket
argument_list|)
name|bool
name|doEnsureInitialized
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|bindAddress
parameter_list|,
name|quint16
name|bindPort
parameter_list|,
specifier|const
name|QHostAddress
modifier|&
name|remoteAddress
parameter_list|)
function_decl|;
public|public:
DECL|function|ensureInitialized
specifier|inline
name|bool
name|ensureInitialized
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|bindAddress
parameter_list|,
name|quint16
name|bindPort
parameter_list|)
block|{
return|return
name|doEnsureInitialized
argument_list|(
name|bindAddress
argument_list|,
name|bindPort
argument_list|,
name|QHostAddress
argument_list|()
argument_list|)
return|;
block|}
DECL|function|ensureInitialized
specifier|inline
name|bool
name|ensureInitialized
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|remoteAddress
parameter_list|)
block|{
return|return
name|doEnsureInitialized
argument_list|(
name|QHostAddress
argument_list|()
argument_list|,
literal|0
argument_list|,
name|remoteAddress
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|doEnsureInitialized
name|bool
name|QUdpSocketPrivate
operator|::
name|doEnsureInitialized
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|bindAddress
parameter_list|,
name|quint16
name|bindPort
parameter_list|,
specifier|const
name|QHostAddress
modifier|&
name|remoteAddress
parameter_list|)
block|{
specifier|const
name|QHostAddress
modifier|*
name|address
init|=
operator|&
name|bindAddress
decl_stmt|;
name|QAbstractSocket
operator|::
name|NetworkLayerProtocol
name|proto
init|=
name|address
operator|->
name|protocol
argument_list|()
decl_stmt|;
if|if
condition|(
name|proto
operator|==
name|QUdpSocket
operator|::
name|UnknownNetworkLayerProtocol
condition|)
block|{
name|address
operator|=
operator|&
name|remoteAddress
expr_stmt|;
name|proto
operator|=
name|address
operator|->
name|protocol
argument_list|()
expr_stmt|;
block|}
comment|// now check if the socket engine is initialized and to the right type
if|if
condition|(
operator|!
name|socketEngine
operator|||
operator|!
name|socketEngine
operator|->
name|isValid
argument_list|()
condition|)
block|{
name|resolveProxy
argument_list|(
name|remoteAddress
operator|.
name|toString
argument_list|()
argument_list|,
name|bindPort
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|initSocketLayer
argument_list|(
name|address
operator|->
name|protocol
argument_list|()
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Creates a QUdpSocket object.      \a parent is passed to the QObject constructor.      \sa socketType() */
end_comment
begin_constructor
DECL|function|QUdpSocket
name|QUdpSocket
operator|::
name|QUdpSocket
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractSocket
argument_list|(
name|UdpSocket
argument_list|,
operator|*
operator|new
name|QUdpSocketPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|isBuffered
operator|=
literal|false
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the socket, closing the connection if necessary.      \sa close() */
end_comment
begin_destructor
DECL|function|~QUdpSocket
name|QUdpSocket
operator|::
name|~
name|QUdpSocket
parameter_list|()
block|{ }
end_destructor
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
end_ifndef
begin_comment
comment|/*!     \since 4.8      Joins the the multicast group specified by \a groupAddress on the default     interface chosen by the operating system. The socket must be in BoundState,     otherwise an error occurs.      Note that if you are attempting to join an IPv4 group, your socket must not     be bound using IPv6 (or in dual mode, using QHostAddress::Any). You must use     QHostAddress::AnyIPv4 instead.      This function returns true if successful; otherwise it returns false     and sets the socket error accordingly.      \sa leaveMulticastGroup() */
end_comment
begin_function
DECL|function|joinMulticastGroup
name|bool
name|QUdpSocket
operator|::
name|joinMulticastGroup
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|groupAddress
parameter_list|)
block|{
return|return
name|joinMulticastGroup
argument_list|(
name|groupAddress
argument_list|,
name|QNetworkInterface
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.8     \overload      Joins the multicast group address \a groupAddress on the interface \a     iface.      \sa leaveMulticastGroup() */
end_comment
begin_function
DECL|function|joinMulticastGroup
name|bool
name|QUdpSocket
operator|::
name|joinMulticastGroup
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|groupAddress
parameter_list|,
specifier|const
name|QNetworkInterface
modifier|&
name|iface
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QUdpSocket
argument_list|)
expr_stmt|;
name|QT_CHECK_BOUND
argument_list|(
literal|"QUdpSocket::joinMulticastGroup()"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|socketEngine
operator|->
name|joinMulticastGroup
argument_list|(
name|groupAddress
argument_list|,
name|iface
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.8      Leaves the multicast group specified by \a groupAddress on the default     interface chosen by the operating system. The socket must be in BoundState,     otherwise an error occurs.     This function returns true if successful; otherwise it returns false and    sets the socket error accordingly.     \sa joinMulticastGroup() */
end_comment
begin_function
DECL|function|leaveMulticastGroup
name|bool
name|QUdpSocket
operator|::
name|leaveMulticastGroup
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|groupAddress
parameter_list|)
block|{
return|return
name|leaveMulticastGroup
argument_list|(
name|groupAddress
argument_list|,
name|QNetworkInterface
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.8     \overload      Leaves the multicast group specified by \a groupAddress on the interface \a     iface.      \sa joinMulticastGroup() */
end_comment
begin_function
DECL|function|leaveMulticastGroup
name|bool
name|QUdpSocket
operator|::
name|leaveMulticastGroup
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|groupAddress
parameter_list|,
specifier|const
name|QNetworkInterface
modifier|&
name|iface
parameter_list|)
block|{
name|QT_CHECK_BOUND
argument_list|(
literal|"QUdpSocket::leaveMulticastGroup()"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
return|return
name|d_func
argument_list|()
operator|->
name|socketEngine
operator|->
name|leaveMulticastGroup
argument_list|(
name|groupAddress
argument_list|,
name|iface
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.8      Returns the interface for the outgoing interface for multicast datagrams.     This corresponds to the IP_MULTICAST_IF socket option for IPv4 sockets and     the IPV6_MULTICAST_IF socket option for IPv6 sockets. If no interface has     been previously set, this function returns an invalid QNetworkInterface.     The socket must be in BoundState, otherwise an invalid QNetworkInterface is     returned.      \sa setMulticastInterface() */
end_comment
begin_function
DECL|function|multicastInterface
name|QNetworkInterface
name|QUdpSocket
operator|::
name|multicastInterface
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QUdpSocket
argument_list|)
expr_stmt|;
name|QT_CHECK_BOUND
argument_list|(
literal|"QUdpSocket::multicastInterface()"
argument_list|,
name|QNetworkInterface
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|socketEngine
operator|->
name|multicastInterface
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.8      Sets the outgoing interface for multicast datagrams to the interface \a     iface. This corresponds to the IP_MULTICAST_IF socket option for IPv4     sockets and the IPV6_MULTICAST_IF socket option for IPv6 sockets. The     socket must be in BoundState, otherwise this function does nothing.      \sa multicastInterface(), joinMulticastGroup(), leaveMulticastGroup() */
end_comment
begin_function
DECL|function|setMulticastInterface
name|void
name|QUdpSocket
operator|::
name|setMulticastInterface
parameter_list|(
specifier|const
name|QNetworkInterface
modifier|&
name|iface
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QUdpSocket
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QUdpSocket::setMulticastInterface() called on a QUdpSocket when not in QUdpSocket::BoundState"
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|socketEngine
operator|->
name|setMulticastInterface
argument_list|(
name|iface
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_NETWORKINTERFACE
end_comment
begin_comment
comment|/*!     Returns true if at least one datagram is waiting to be read;     otherwise returns false.      \sa pendingDatagramSize(), readDatagram() */
end_comment
begin_function
DECL|function|hasPendingDatagrams
name|bool
name|QUdpSocket
operator|::
name|hasPendingDatagrams
parameter_list|()
specifier|const
block|{
name|QT_CHECK_BOUND
argument_list|(
literal|"QUdpSocket::hasPendingDatagrams()"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
return|return
name|d_func
argument_list|()
operator|->
name|socketEngine
operator|->
name|hasPendingDatagrams
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the size of the first pending UDP datagram. If there is     no datagram available, this function returns -1.      \sa hasPendingDatagrams(), readDatagram() */
end_comment
begin_function
DECL|function|pendingDatagramSize
name|qint64
name|QUdpSocket
operator|::
name|pendingDatagramSize
parameter_list|()
specifier|const
block|{
name|QT_CHECK_BOUND
argument_list|(
literal|"QUdpSocket::pendingDatagramSize()"
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|d_func
argument_list|()
operator|->
name|socketEngine
operator|->
name|pendingDatagramSize
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sends the datagram at \a data of size \a size to the host     address \a address at port \a port. Returns the number of     bytes sent on success; otherwise returns -1.      Datagrams are always written as one block. The maximum size of a     datagram is highly platform-dependent, but can be as low as 8192     bytes. If the datagram is too large, this function will return -1     and error() will return DatagramTooLargeError.      Sending datagrams larger than 512 bytes is in general disadvised,     as even if they are sent successfully, they are likely to be     fragmented by the IP layer before arriving at their final     destination.      \warning Calling this function on a connected UDP socket may     result in an error and no packet being sent. If you are using a     connected socket, use write() to send datagrams.      \sa readDatagram(), write() */
end_comment
begin_function
DECL|function|writeDatagram
name|qint64
name|QUdpSocket
operator|::
name|writeDatagram
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|size
parameter_list|,
specifier|const
name|QHostAddress
modifier|&
name|address
parameter_list|,
name|quint16
name|port
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QUdpSocket
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QUDPSOCKET_DEBUG
name|qDebug
argument_list|(
literal|"QUdpSocket::writeDatagram(%p, %llu, \"%s\", %i)"
argument_list|,
name|data
argument_list|,
name|size
argument_list|,
name|address
operator|.
name|toString
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|port
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|d
operator|->
name|doEnsureInitialized
argument_list|(
name|QHostAddress
operator|::
name|Any
argument_list|,
literal|0
argument_list|,
name|address
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|state
argument_list|()
operator|==
name|UnconnectedState
condition|)
name|bind
argument_list|()
expr_stmt|;
name|qint64
name|sent
init|=
name|d
operator|->
name|socketEngine
operator|->
name|writeDatagram
argument_list|(
name|data
argument_list|,
name|size
argument_list|,
name|address
argument_list|,
name|port
argument_list|)
decl_stmt|;
name|d
operator|->
name|cachedSocketDescriptor
operator|=
name|d
operator|->
name|socketEngine
operator|->
name|socketDescriptor
argument_list|()
expr_stmt|;
if|if
condition|(
name|sent
operator|>=
literal|0
condition|)
block|{
emit|emit
name|bytesWritten
argument_list|(
name|sent
argument_list|)
emit|;
block|}
else|else
block|{
name|d
operator|->
name|socketError
operator|=
name|d
operator|->
name|socketEngine
operator|->
name|error
argument_list|()
expr_stmt|;
name|setErrorString
argument_list|(
name|d
operator|->
name|socketEngine
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|(
name|d
operator|->
name|socketError
argument_list|)
emit|;
block|}
return|return
name|sent
return|;
block|}
end_function
begin_comment
comment|/*!     \fn qint64 QUdpSocket::writeDatagram(const QByteArray&datagram,                                              const QHostAddress&host, quint16 port)     \overload      Sends the datagram \a datagram to the host address \a host and at     port \a port. */
end_comment
begin_comment
comment|/*!     Receives a datagram no larger than \a maxSize bytes and stores     it in \a data. The sender's host address and port is stored in     *\a address and *\a port (unless the pointers are 0).      Returns the size of the datagram on success; otherwise returns     -1.      If \a maxSize is too small, the rest of the datagram will be     lost. To avoid loss of data, call pendingDatagramSize() to     determine the size of the pending datagram before attempting to     read it. If \a maxSize is 0, the datagram will be discarded.      \sa writeDatagram(), hasPendingDatagrams(), pendingDatagramSize() */
end_comment
begin_function
DECL|function|readDatagram
name|qint64
name|QUdpSocket
operator|::
name|readDatagram
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxSize
parameter_list|,
name|QHostAddress
modifier|*
name|address
parameter_list|,
name|quint16
modifier|*
name|port
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QUdpSocket
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|QUDPSOCKET_DEBUG
name|qDebug
argument_list|(
literal|"QUdpSocket::readDatagram(%p, %llu, %p, %p)"
argument_list|,
name|data
argument_list|,
name|maxSize
argument_list|,
name|address
argument_list|,
name|port
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QT_CHECK_BOUND
argument_list|(
literal|"QUdpSocket::readDatagram()"
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|qint64
name|readBytes
init|=
name|d
operator|->
name|socketEngine
operator|->
name|readDatagram
argument_list|(
name|data
argument_list|,
name|maxSize
argument_list|,
name|address
argument_list|,
name|port
argument_list|)
decl_stmt|;
name|d_func
argument_list|()
operator|->
name|socketEngine
operator|->
name|setReadNotificationEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|readBytes
operator|<
literal|0
condition|)
block|{
name|d
operator|->
name|socketError
operator|=
name|d
operator|->
name|socketEngine
operator|->
name|error
argument_list|()
expr_stmt|;
name|setErrorString
argument_list|(
name|d
operator|->
name|socketEngine
operator|->
name|errorString
argument_list|()
argument_list|)
expr_stmt|;
emit|emit
name|error
argument_list|(
name|d
operator|->
name|socketError
argument_list|)
emit|;
block|}
return|return
name|readBytes
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_UDPSOCKET
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
