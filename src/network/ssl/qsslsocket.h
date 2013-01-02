begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLSOCKET_H
end_ifndef
begin_define
DECL|macro|QSSLSOCKET_H
define|#
directive|define
name|QSSLSOCKET_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qregexp.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SSL
end_ifndef
begin_include
include|#
directive|include
file|<QtNetwork/qtcpsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qsslerror.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SSL
DECL|variable|QDir
name|class
name|QDir
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslCipher
name|class
name|QSslCipher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslCertificate
name|class
name|QSslCertificate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslConfiguration
name|class
name|QSslConfiguration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslSocketPrivate
name|class
name|QSslSocketPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QSslSocket
range|:
name|public
name|QTcpSocket
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|SslMode
block|{
name|UnencryptedMode
block|,
name|SslClientMode
block|,
name|SslServerMode
block|}
block|;      enum
name|PeerVerifyMode
block|{
name|VerifyNone
block|,
name|QueryPeer
block|,
name|VerifyPeer
block|,
name|AutoVerifyPeer
block|}
block|;
name|explicit
name|QSslSocket
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QSslSocket
argument_list|()
block|;
name|void
name|resume
argument_list|()
block|;
comment|// to continue after proxy authentication required, SSL errors etc.
comment|// Autostarting the SSL client handshake.
name|void
name|connectToHostEncrypted
argument_list|(
argument|const QString&hostName
argument_list|,
argument|quint16 port
argument_list|,
argument|OpenMode mode = ReadWrite
argument_list|,
argument|NetworkLayerProtocol protocol = AnyIPProtocol
argument_list|)
block|;
name|void
name|connectToHostEncrypted
argument_list|(
argument|const QString&hostName
argument_list|,
argument|quint16 port
argument_list|,
argument|const QString&sslPeerName
argument_list|,
argument|OpenMode mode = ReadWrite
argument_list|,
argument|NetworkLayerProtocol protocol = AnyIPProtocol
argument_list|)
block|;
name|bool
name|setSocketDescriptor
argument_list|(
argument|qintptr socketDescriptor
argument_list|,
argument|SocketState state = ConnectedState
argument_list|,
argument|OpenMode openMode = ReadWrite
argument_list|)
block|;
name|using
name|QAbstractSocket
operator|::
name|connectToHost
block|;
name|void
name|connectToHost
argument_list|(
argument|const QString&hostName
argument_list|,
argument|quint16 port
argument_list|,
argument|OpenMode openMode = ReadWrite
argument_list|,
argument|NetworkLayerProtocol protocol = AnyIPProtocol
argument_list|)
block|;
name|void
name|disconnectFromHost
argument_list|()
block|;
name|virtual
name|void
name|setSocketOption
argument_list|(
argument|QAbstractSocket::SocketOption option
argument_list|,
argument|const QVariant&value
argument_list|)
block|;
name|virtual
name|QVariant
name|socketOption
argument_list|(
argument|QAbstractSocket::SocketOption option
argument_list|)
block|;
name|SslMode
name|mode
argument_list|()
specifier|const
block|;
name|bool
name|isEncrypted
argument_list|()
specifier|const
block|;
name|QSsl
operator|::
name|SslProtocol
name|protocol
argument_list|()
specifier|const
block|;
name|void
name|setProtocol
argument_list|(
argument|QSsl::SslProtocol protocol
argument_list|)
block|;
name|QSslSocket
operator|::
name|PeerVerifyMode
name|peerVerifyMode
argument_list|()
specifier|const
block|;
name|void
name|setPeerVerifyMode
argument_list|(
argument|QSslSocket::PeerVerifyMode mode
argument_list|)
block|;
name|int
name|peerVerifyDepth
argument_list|()
specifier|const
block|;
name|void
name|setPeerVerifyDepth
argument_list|(
argument|int depth
argument_list|)
block|;
name|QString
name|peerVerifyName
argument_list|()
specifier|const
block|;
name|void
name|setPeerVerifyName
argument_list|(
specifier|const
name|QString
operator|&
name|hostName
argument_list|)
block|;
comment|// From QIODevice
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
block|;
name|qint64
name|bytesToWrite
argument_list|()
specifier|const
block|;
name|bool
name|canReadLine
argument_list|()
specifier|const
block|;
name|void
name|close
argument_list|()
block|;
name|bool
name|atEnd
argument_list|()
specifier|const
block|;
name|bool
name|flush
argument_list|()
block|;
name|void
name|abort
argument_list|()
block|;
comment|// From QAbstractSocket:
name|void
name|setReadBufferSize
argument_list|(
argument|qint64 size
argument_list|)
block|;
comment|// Similar to QIODevice's:
name|qint64
name|encryptedBytesAvailable
argument_list|()
specifier|const
block|;
name|qint64
name|encryptedBytesToWrite
argument_list|()
specifier|const
block|;
comment|// SSL configuration
name|QSslConfiguration
name|sslConfiguration
argument_list|()
specifier|const
block|;
name|void
name|setSslConfiguration
argument_list|(
specifier|const
name|QSslConfiguration
operator|&
name|config
argument_list|)
block|;
comment|// Certificate& cipher accessors.
name|void
name|setLocalCertificate
argument_list|(
specifier|const
name|QSslCertificate
operator|&
name|certificate
argument_list|)
block|;
name|void
name|setLocalCertificate
argument_list|(
argument|const QString&fileName
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|)
block|;
name|QSslCertificate
name|localCertificate
argument_list|()
specifier|const
block|;
name|QSslCertificate
name|peerCertificate
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QSslCertificate
operator|>
name|peerCertificateChain
argument_list|()
specifier|const
block|;
name|QSslCipher
name|sessionCipher
argument_list|()
specifier|const
block|;
comment|// Private keys, for server sockets.
name|void
name|setPrivateKey
argument_list|(
specifier|const
name|QSslKey
operator|&
name|key
argument_list|)
block|;
name|void
name|setPrivateKey
argument_list|(
argument|const QString&fileName
argument_list|,
argument|QSsl::KeyAlgorithm algorithm = QSsl::Rsa
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|,
argument|const QByteArray&passPhrase = QByteArray()
argument_list|)
block|;
name|QSslKey
name|privateKey
argument_list|()
specifier|const
block|;
comment|// Cipher settings.
name|QList
operator|<
name|QSslCipher
operator|>
name|ciphers
argument_list|()
specifier|const
block|;
name|void
name|setCiphers
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCipher
operator|>
operator|&
name|ciphers
argument_list|)
block|;
name|void
name|setCiphers
argument_list|(
specifier|const
name|QString
operator|&
name|ciphers
argument_list|)
block|;
specifier|static
name|void
name|setDefaultCiphers
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCipher
operator|>
operator|&
name|ciphers
argument_list|)
block|;
specifier|static
name|QList
operator|<
name|QSslCipher
operator|>
name|defaultCiphers
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QSslCipher
operator|>
name|supportedCiphers
argument_list|()
block|;
comment|// CA settings.
name|bool
name|addCaCertificates
argument_list|(
argument|const QString&path
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|,
argument|QRegExp::PatternSyntax syntax = QRegExp::FixedString
argument_list|)
block|;
name|void
name|addCaCertificate
argument_list|(
specifier|const
name|QSslCertificate
operator|&
name|certificate
argument_list|)
block|;
name|void
name|addCaCertificates
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCertificate
operator|>
operator|&
name|certificates
argument_list|)
block|;
name|void
name|setCaCertificates
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCertificate
operator|>
operator|&
name|certificates
argument_list|)
block|;
name|QList
operator|<
name|QSslCertificate
operator|>
name|caCertificates
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|addDefaultCaCertificates
argument_list|(
argument|const QString&path
argument_list|,
argument|QSsl::EncodingFormat format = QSsl::Pem
argument_list|,
argument|QRegExp::PatternSyntax syntax = QRegExp::FixedString
argument_list|)
block|;
specifier|static
name|void
name|addDefaultCaCertificate
argument_list|(
specifier|const
name|QSslCertificate
operator|&
name|certificate
argument_list|)
block|;
specifier|static
name|void
name|addDefaultCaCertificates
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCertificate
operator|>
operator|&
name|certificates
argument_list|)
block|;
specifier|static
name|void
name|setDefaultCaCertificates
argument_list|(
specifier|const
name|QList
operator|<
name|QSslCertificate
operator|>
operator|&
name|certificates
argument_list|)
block|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|defaultCaCertificates
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QSslCertificate
operator|>
name|systemCaCertificates
argument_list|()
block|;
name|bool
name|waitForConnected
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForEncrypted
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForReadyRead
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForBytesWritten
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|bool
name|waitForDisconnected
argument_list|(
argument|int msecs =
literal|30000
argument_list|)
block|;
name|QList
operator|<
name|QSslError
operator|>
name|sslErrors
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|supportsSsl
argument_list|()
block|;
specifier|static
name|long
name|sslLibraryVersionNumber
argument_list|()
block|;
specifier|static
name|QString
name|sslLibraryVersionString
argument_list|()
block|;
name|void
name|ignoreSslErrors
argument_list|(
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
name|errors
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|startClientEncryption
argument_list|()
block|;
name|void
name|startServerEncryption
argument_list|()
block|;
name|void
name|ignoreSslErrors
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|encrypted
argument_list|()
block|;
name|void
name|peerVerifyError
argument_list|(
specifier|const
name|QSslError
operator|&
name|error
argument_list|)
block|;
name|void
name|sslErrors
argument_list|(
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
name|errors
argument_list|)
block|;
name|void
name|modeChanged
argument_list|(
argument|QSslSocket::SslMode newMode
argument_list|)
block|;
name|void
name|encryptedBytesWritten
argument_list|(
argument|qint64 totalBytes
argument_list|)
block|;
name|protected
operator|:
name|qint64
name|readData
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|writeData
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSslSocket
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QSslSocket
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_connectedSlot()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_hostFoundSlot()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_disconnectedSlot()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_stateChangedSlot(QAbstractSocket::SocketState)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_errorSlot(QAbstractSocket::SocketError)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_readyReadSlot()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_bytesWrittenSlot(qint64)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_flushWriteBuffer()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_flushReadBuffer()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_resumeImplementation()
argument_list|)
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_caRootLoaded(QSslCertificate,QSslCertificate)
argument_list|)
endif|#
directive|endif
name|friend
name|class
name|QSslSocketBackendPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SSL
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
