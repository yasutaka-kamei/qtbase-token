begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHTTPNETWORKREPLY_H
end_ifndef
begin_define
DECL|macro|QHTTPNETWORKREPLY_H
define|#
directive|define
name|QHTTPNETWORKREPLY_H
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
comment|// of the Network Access API.  This header file may change from
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
file|<qplatformdefs.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMPRESS
end_ifndef
begin_struct_decl
struct_decl|struct
name|z_stream_s
struct_decl|;
end_struct_decl
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtNetwork/qtcpsocket.h>
end_include
begin_comment
comment|// it's safe to include these even if SSL support is not enabled
end_comment
begin_include
include|#
directive|include
file|<QtNetwork/qsslsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qsslerror.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkrequest.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkreply.h>
end_include
begin_include
include|#
directive|include
file|<qbuffer.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkheader_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkrequest_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qauthenticator_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qringbuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qbytedata_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QHttpNetworkConnection
name|class
name|QHttpNetworkConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpNetworkConnectionChannel
name|class
name|QHttpNetworkConnectionChannel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpNetworkRequest
name|class
name|QHttpNetworkRequest
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpNetworkConnectionPrivate
name|class
name|QHttpNetworkConnectionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpNetworkReplyPrivate
name|class
name|QHttpNetworkReplyPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|Q_AUTOTEST_EXPORT
name|QHttpNetworkReply
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QHttpNetworkHeader
block|{
name|Q_OBJECT
name|public
range|:
name|explicit
name|QHttpNetworkReply
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
operator|=
name|QUrl
argument_list|()
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|QHttpNetworkReply
argument_list|()
expr_stmt|;
name|QUrl
name|url
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
name|int
name|majorVersion
argument_list|()
specifier|const
expr_stmt|;
name|int
name|minorVersion
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|contentLength
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setContentLength
parameter_list|(
name|qint64
name|length
parameter_list|)
function_decl|;
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
operator|,
name|QByteArray
operator|>
expr|>
name|header
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|headerField
argument_list|(
specifier|const
name|QByteArray
operator|&
name|name
argument_list|,
specifier|const
name|QByteArray
operator|&
name|defaultValue
operator|=
name|QByteArray
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|void
name|setHeaderField
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
function_decl|;
name|void
name|parseHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|header
parameter_list|)
function_decl|;
comment|// mainly for testing
name|QHttpNetworkRequest
name|request
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRequest
parameter_list|(
specifier|const
name|QHttpNetworkRequest
modifier|&
name|request
parameter_list|)
function_decl|;
name|int
name|statusCode
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStatusCode
parameter_list|(
name|int
name|code
parameter_list|)
function_decl|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setErrorString
parameter_list|(
specifier|const
name|QString
modifier|&
name|error
parameter_list|)
function_decl|;
name|QString
name|reasonPhrase
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|bytesAvailableNextBlock
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|readAnyAvailable
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|readAny
parameter_list|()
function_decl|;
name|QByteArray
name|readAll
parameter_list|()
function_decl|;
name|QByteArray
name|read
parameter_list|(
name|qint64
name|amount
parameter_list|)
function_decl|;
name|qint64
name|sizeNextBlock
parameter_list|()
function_decl|;
name|void
name|setDownstreamLimited
parameter_list|(
name|bool
name|t
parameter_list|)
function_decl|;
name|void
name|setReadBufferSize
parameter_list|(
name|qint64
name|size
parameter_list|)
function_decl|;
name|bool
name|supportsUserProvidedDownloadBuffer
parameter_list|()
function_decl|;
name|void
name|setUserProvidedDownloadBuffer
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
name|char
modifier|*
name|userProvidedDownloadBuffer
parameter_list|()
function_decl|;
name|bool
name|isFinished
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isPipeliningUsed
argument_list|()
specifier|const
expr_stmt|;
name|QHttpNetworkConnection
modifier|*
name|connection
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|QSslConfiguration
name|sslConfiguration
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSslConfiguration
parameter_list|(
specifier|const
name|QSslConfiguration
modifier|&
name|config
parameter_list|)
function_decl|;
name|void
name|ignoreSslErrors
parameter_list|()
function_decl|;
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
decl_stmt|;
name|Q_SIGNALS
label|:
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
decl_stmt|;
endif|#
directive|endif
name|Q_SIGNALS
label|:
name|void
name|readyRead
parameter_list|()
function_decl|;
name|void
name|finished
parameter_list|()
function_decl|;
name|void
name|finishedWithError
argument_list|(
name|QNetworkReply
operator|::
name|NetworkError
name|errorCode
argument_list|,
specifier|const
name|QString
operator|&
name|detail
operator|=
name|QString
argument_list|()
argument_list|)
decl_stmt|;
name|void
name|headerChanged
parameter_list|()
function_decl|;
name|void
name|dataReadProgress
parameter_list|(
name|qint64
name|done
parameter_list|,
name|qint64
name|total
parameter_list|)
function_decl|;
name|void
name|dataSendProgress
parameter_list|(
name|qint64
name|done
parameter_list|,
name|qint64
name|total
parameter_list|)
function_decl|;
name|void
name|cacheCredentials
parameter_list|(
specifier|const
name|QHttpNetworkRequest
modifier|&
name|request
parameter_list|,
name|QAuthenticator
modifier|*
name|authenticator
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
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
function_decl|;
endif|#
directive|endif
name|void
name|authenticationRequired
parameter_list|(
specifier|const
name|QHttpNetworkRequest
modifier|&
name|request
parameter_list|,
name|QAuthenticator
modifier|*
name|authenticator
parameter_list|)
function_decl|;
name|private
label|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QHttpNetworkReply
argument_list|)
name|friend
name|class
name|QHttpSocketEngine
decl_stmt|;
name|friend
name|class
name|QHttpNetworkConnection
decl_stmt|;
name|friend
name|class
name|QHttpNetworkConnectionPrivate
decl_stmt|;
name|friend
name|class
name|QHttpNetworkConnectionChannel
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QObjectPrivate
name|class
name|QHttpNetworkReplyPrivate
range|:
name|public
name|QObjectPrivate
decl_stmt|,
name|public
name|QHttpNetworkHeaderPrivate
block|{
name|public
label|:
name|QHttpNetworkReplyPrivate
argument_list|(
specifier|const
name|QUrl
operator|&
name|newUrl
operator|=
name|QUrl
argument_list|()
argument_list|)
expr_stmt|;
operator|~
name|QHttpNetworkReplyPrivate
argument_list|()
expr_stmt|;
name|qint64
name|readStatus
parameter_list|(
name|QAbstractSocket
modifier|*
name|socket
parameter_list|)
function_decl|;
name|bool
name|parseStatus
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|status
parameter_list|)
function_decl|;
name|qint64
name|readHeader
parameter_list|(
name|QAbstractSocket
modifier|*
name|socket
parameter_list|)
function_decl|;
name|void
name|parseHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|header
parameter_list|)
function_decl|;
name|qint64
name|readBody
parameter_list|(
name|QAbstractSocket
modifier|*
name|socket
parameter_list|,
name|QByteDataBuffer
modifier|*
name|out
parameter_list|)
function_decl|;
name|qint64
name|readBodyVeryFast
parameter_list|(
name|QAbstractSocket
modifier|*
name|socket
parameter_list|,
name|char
modifier|*
name|b
parameter_list|)
function_decl|;
name|qint64
name|readBodyFast
parameter_list|(
name|QAbstractSocket
modifier|*
name|socket
parameter_list|,
name|QByteDataBuffer
modifier|*
name|rb
parameter_list|)
function_decl|;
name|bool
name|findChallenge
argument_list|(
name|bool
name|forProxy
argument_list|,
name|QByteArray
operator|&
name|challenge
argument_list|)
decl|const
decl_stmt|;
name|QAuthenticatorPrivate
operator|::
name|Method
name|authenticationMethod
argument_list|(
argument|bool isProxy
argument_list|)
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|clearHttpLayerInformation
parameter_list|()
function_decl|;
name|qint64
name|readReplyBodyRaw
parameter_list|(
name|QAbstractSocket
modifier|*
name|in
parameter_list|,
name|QByteDataBuffer
modifier|*
name|out
parameter_list|,
name|qint64
name|size
parameter_list|)
function_decl|;
name|qint64
name|readReplyBodyChunked
parameter_list|(
name|QAbstractSocket
modifier|*
name|in
parameter_list|,
name|QByteDataBuffer
modifier|*
name|out
parameter_list|)
function_decl|;
name|qint64
name|getChunkSize
parameter_list|(
name|QAbstractSocket
modifier|*
name|in
parameter_list|,
name|qint64
modifier|*
name|chunkSize
parameter_list|)
function_decl|;
name|bool
name|shouldEmitSignals
parameter_list|()
function_decl|;
name|bool
name|expectContent
parameter_list|()
function_decl|;
name|void
name|eraseData
parameter_list|()
function_decl|;
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isChunked
parameter_list|()
function_decl|;
name|bool
name|isConnectionCloseEnabled
parameter_list|()
function_decl|;
name|bool
name|isCompressed
parameter_list|()
function_decl|;
name|void
name|removeAutoDecompressHeader
parameter_list|()
function_decl|;
enum|enum
name|ReplyState
block|{
name|NothingDoneState
block|,
name|ReadingStatusState
block|,
name|ReadingHeaderState
block|,
name|ReadingDataState
block|,
name|AllDoneState
block|}
name|state
enum|;
name|QHttpNetworkRequest
name|request
decl_stmt|;
name|bool
name|ssl
decl_stmt|;
name|int
name|statusCode
decl_stmt|;
name|int
name|majorVersion
decl_stmt|;
name|int
name|minorVersion
decl_stmt|;
name|QString
name|errorString
decl_stmt|;
name|QString
name|reasonPhrase
decl_stmt|;
name|qint64
name|bodyLength
decl_stmt|;
name|qint64
name|contentRead
decl_stmt|;
name|qint64
name|totalProgress
decl_stmt|;
name|QByteArray
name|fragment
decl_stmt|;
comment|// used for header, status, chunk header etc, not for reply data
name|bool
name|chunkedTransferEncoding
decl_stmt|;
name|bool
name|connectionCloseEnabled
decl_stmt|;
name|bool
name|forceConnectionCloseEnabled
decl_stmt|;
name|bool
name|lastChunkRead
decl_stmt|;
name|qint64
name|currentChunkSize
decl_stmt|;
name|qint64
name|currentChunkRead
decl_stmt|;
name|qint64
name|readBufferMaxSize
decl_stmt|;
name|QPointer
operator|<
name|QHttpNetworkConnection
operator|>
name|connection
expr_stmt|;
name|QPointer
operator|<
name|QHttpNetworkConnectionChannel
operator|>
name|connectionChannel
expr_stmt|;
name|bool
name|autoDecompress
decl_stmt|;
name|QByteDataBuffer
name|responseData
decl_stmt|;
comment|// uncompressed body
name|QByteArray
name|compressedData
decl_stmt|;
comment|// compressed body (temporary)
name|bool
name|requestIsPrepared
decl_stmt|;
name|bool
name|pipeliningUsed
decl_stmt|;
name|bool
name|downstreamLimited
decl_stmt|;
name|char
modifier|*
name|userProvidedDownloadBuffer
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_COMPRESS
name|z_stream_s
modifier|*
name|inflateStrm
decl_stmt|;
name|qint64
name|uncompressBodyData
parameter_list|(
name|QByteDataBuffer
modifier|*
name|in
parameter_list|,
name|QByteDataBuffer
modifier|*
name|out
parameter_list|)
function_decl|;
endif|#
directive|endif
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
comment|// QT_NO_HTTP
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QHTTPNETWORKREPLY_H
end_comment
end_unit
