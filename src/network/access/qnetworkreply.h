begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKREPLY_H
end_ifndef
begin_define
DECL|macro|QNETWORKREPLY_H
define|#
directive|define
name|QNETWORKREPLY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QIODevice>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkRequest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QNetworkAccessManager>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAuthenticator
name|class
name|QAuthenticator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslConfiguration
name|class
name|QSslConfiguration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSslError
name|class
name|QSslError
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkReplyPrivate
name|class
name|QNetworkReplyPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkReply
range|:
name|public
name|QIODevice
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|NetworkError
argument_list|)
name|public
operator|:
expr|enum
name|NetworkError
block|{
name|NoError
operator|=
literal|0
block|,
comment|// network layer errors [relating to the destination server] (1-99):
name|ConnectionRefusedError
operator|=
literal|1
block|,
name|RemoteHostClosedError
block|,
name|HostNotFoundError
block|,
name|TimeoutError
block|,
name|OperationCanceledError
block|,
name|SslHandshakeFailedError
block|,
name|TemporaryNetworkFailureError
block|,
name|UnknownNetworkError
operator|=
literal|99
block|,
comment|// proxy errors (101-199):
name|ProxyConnectionRefusedError
operator|=
literal|101
block|,
name|ProxyConnectionClosedError
block|,
name|ProxyNotFoundError
block|,
name|ProxyTimeoutError
block|,
name|ProxyAuthenticationRequiredError
block|,
name|UnknownProxyError
operator|=
literal|199
block|,
comment|// content errors (201-299):
name|ContentAccessDenied
operator|=
literal|201
block|,
name|ContentOperationNotPermittedError
block|,
name|ContentNotFoundError
block|,
name|AuthenticationRequiredError
block|,
name|ContentReSendError
block|,
name|UnknownContentError
operator|=
literal|299
block|,
comment|// protocol errors
name|ProtocolUnknownError
operator|=
literal|301
block|,
name|ProtocolInvalidOperationError
block|,
name|ProtocolFailure
operator|=
literal|399
block|}
block|;
operator|~
name|QNetworkReply
argument_list|()
block|;
name|virtual
name|void
name|abort
argument_list|()
operator|=
literal|0
block|;
comment|// reimplemented from QIODevice
name|virtual
name|void
name|close
argument_list|()
block|;
name|virtual
name|bool
name|isSequential
argument_list|()
specifier|const
block|;
comment|// like QAbstractSocket:
name|qint64
name|readBufferSize
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setReadBufferSize
argument_list|(
argument|qint64 size
argument_list|)
block|;
name|QNetworkAccessManager
operator|*
name|manager
argument_list|()
specifier|const
block|;
name|QNetworkAccessManager
operator|::
name|Operation
name|operation
argument_list|()
specifier|const
block|;
name|QNetworkRequest
name|request
argument_list|()
specifier|const
block|;
name|NetworkError
name|error
argument_list|()
specifier|const
block|;
name|bool
name|isFinished
argument_list|()
specifier|const
block|;
name|bool
name|isRunning
argument_list|()
specifier|const
block|;
name|QUrl
name|url
argument_list|()
specifier|const
block|;
comment|// "cooked" headers
name|QVariant
name|header
argument_list|(
argument|QNetworkRequest::KnownHeaders header
argument_list|)
specifier|const
block|;
comment|// raw headers:
name|bool
name|hasRawHeader
argument_list|(
argument|const QByteArray&headerName
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|rawHeaderList
argument_list|()
specifier|const
block|;
name|QByteArray
name|rawHeader
argument_list|(
argument|const QByteArray&headerName
argument_list|)
specifier|const
block|;
typedef|typedef
name|QPair
operator|<
name|QByteArray
operator|,
name|QByteArray
operator|>
name|RawHeaderPair
expr_stmt|;
specifier|const
name|QList
operator|<
name|RawHeaderPair
operator|>
operator|&
name|rawHeaderPairs
argument_list|()
specifier|const
decl_stmt|;
end_decl_stmt
begin_comment
comment|// attributes
end_comment
begin_decl_stmt
name|QVariant
name|attribute
argument_list|(
name|QNetworkRequest
operator|::
name|Attribute
name|code
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SSL
end_ifndef
begin_expr_stmt
name|QSslConfiguration
name|sslConfiguration
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setSslConfiguration
parameter_list|(
specifier|const
name|QSslConfiguration
modifier|&
name|configuration
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
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
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|public
name|Q_SLOTS
range|:
name|virtual
name|void
name|ignoreSslErrors
argument_list|()
decl_stmt|;
end_decl_stmt
begin_label
name|Q_SIGNALS
label|:
end_label
begin_function_decl
name|void
name|metaDataChanged
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|finished
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|error
argument_list|(
name|QNetworkReply
operator|::
name|NetworkError
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SSL
end_ifndef
begin_decl_stmt
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
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|uploadProgress
parameter_list|(
name|qint64
name|bytesSent
parameter_list|,
name|qint64
name|bytesTotal
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|downloadProgress
parameter_list|(
name|qint64
name|bytesReceived
parameter_list|,
name|qint64
name|bytesTotal
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_function_decl
name|explicit
name|QNetworkReply
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QNetworkReply
argument_list|(
name|QNetworkReplyPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|qint64
name|writeData
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|setOperation
argument_list|(
name|QNetworkAccessManager
operator|::
name|Operation
name|operation
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setRequest
parameter_list|(
specifier|const
name|QNetworkRequest
modifier|&
name|request
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setError
parameter_list|(
name|NetworkError
name|errorCode
parameter_list|,
specifier|const
name|QString
modifier|&
name|errorString
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setFinished
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|KnownHeaders
name|header
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setRawHeader
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|headerName
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|Attribute
name|code
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|void
name|sslConfigurationImplementation
argument_list|(
name|QSslConfiguration
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|void
name|setSslConfigurationImplementation
parameter_list|(
specifier|const
name|QSslConfiguration
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|void
name|ignoreSslErrorsImplementation
argument_list|(
specifier|const
name|QList
operator|<
name|QSslError
operator|>
operator|&
argument_list|)
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QNetworkReply
argument_list|)
end_macro
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
