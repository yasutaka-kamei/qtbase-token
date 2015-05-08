begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2014 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qhttpprotocolhandler_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qnoncontiguousbytedevice_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qhttpnetworkconnectionchannel_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QHttpProtocolHandler
name|QHttpProtocolHandler
operator|::
name|QHttpProtocolHandler
parameter_list|(
name|QHttpNetworkConnectionChannel
modifier|*
name|channel
parameter_list|)
member_init_list|:
name|QAbstractProtocolHandler
argument_list|(
name|channel
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|_q_receiveReply
name|void
name|QHttpProtocolHandler
operator|::
name|_q_receiveReply
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|m_socket
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_reply
condition|)
block|{
if|if
condition|(
name|m_socket
operator|->
name|bytesAvailable
argument_list|()
operator|>
literal|0
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"QAbstractProtocolHandler::_q_receiveReply() called without QHttpNetworkReply,"
operator|<<
name|m_socket
operator|->
name|bytesAvailable
argument_list|()
operator|<<
literal|"bytes on socket."
expr_stmt|;
name|m_channel
operator|->
name|close
argument_list|()
expr_stmt|;
return|return;
block|}
comment|// only run when the QHttpNetworkConnection is not currently being destructed, e.g.
comment|// this function is called from _q_disconnected which is called because
comment|// of ~QHttpNetworkConnectionPrivate
if|if
condition|(
operator|!
name|qobject_cast
argument_list|<
name|QHttpNetworkConnection
operator|*
argument_list|>
argument_list|(
name|m_connection
argument_list|)
condition|)
block|{
return|return;
block|}
name|QAbstractSocket
operator|::
name|SocketState
name|socketState
init|=
name|m_socket
operator|->
name|state
argument_list|()
decl_stmt|;
comment|// connection might be closed to signal the end of data
if|if
condition|(
name|socketState
operator|==
name|QAbstractSocket
operator|::
name|UnconnectedState
condition|)
block|{
if|if
condition|(
name|m_socket
operator|->
name|bytesAvailable
argument_list|()
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|m_reply
operator|->
name|d_func
argument_list|()
operator|->
name|state
operator|==
name|QHttpNetworkReplyPrivate
operator|::
name|ReadingDataState
condition|)
block|{
comment|// finish this reply. this case happens when the server did not send a content length
name|m_reply
operator|->
name|d_func
argument_list|()
operator|->
name|state
operator|=
name|QHttpNetworkReplyPrivate
operator|::
name|AllDoneState
expr_stmt|;
name|m_channel
operator|->
name|allDone
argument_list|()
expr_stmt|;
return|return;
block|}
else|else
block|{
name|m_channel
operator|->
name|handleUnexpectedEOF
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
else|else
block|{
comment|// socket not connected but still bytes for reading.. just continue in this function
block|}
block|}
comment|// read loop for the response
name|qint64
name|bytes
init|=
literal|0
decl_stmt|;
name|qint64
name|lastBytes
init|=
name|bytes
decl_stmt|;
do|do
block|{
name|lastBytes
operator|=
name|bytes
expr_stmt|;
name|QHttpNetworkReplyPrivate
operator|::
name|ReplyState
name|state
init|=
name|m_reply
operator|->
name|d_func
argument_list|()
operator|->
name|state
decl_stmt|;
switch|switch
condition|(
name|state
condition|)
block|{
case|case
name|QHttpNetworkReplyPrivate
operator|::
name|NothingDoneState
case|:
block|{
name|m_reply
operator|->
name|d_func
argument_list|()
operator|->
name|state
operator|=
name|QHttpNetworkReplyPrivate
operator|::
name|ReadingStatusState
expr_stmt|;
comment|// fallthrough
block|}
case|case
name|QHttpNetworkReplyPrivate
operator|::
name|ReadingStatusState
case|:
block|{
name|qint64
name|statusBytes
init|=
name|m_reply
operator|->
name|d_func
argument_list|()
operator|->
name|readStatus
argument_list|(
name|m_socket
argument_list|)
decl_stmt|;
if|if
condition|(
name|statusBytes
operator|==
operator|-
literal|1
condition|)
block|{
comment|// connection broke while reading status. also handled if later _q_disconnected is called
name|m_channel
operator|->
name|handleUnexpectedEOF
argument_list|()
expr_stmt|;
return|return;
block|}
name|bytes
operator|+=
name|statusBytes
expr_stmt|;
name|m_channel
operator|->
name|lastStatus
operator|=
name|m_reply
operator|->
name|d_func
argument_list|()
operator|->
name|statusCode
expr_stmt|;
break|break;
block|}
case|case
name|QHttpNetworkReplyPrivate
operator|::
name|ReadingHeaderState
case|:
block|{
name|QHttpNetworkReplyPrivate
modifier|*
name|replyPrivate
init|=
name|m_reply
operator|->
name|d_func
argument_list|()
decl_stmt|;
name|qint64
name|headerBytes
init|=
name|replyPrivate
operator|->
name|readHeader
argument_list|(
name|m_socket
argument_list|)
decl_stmt|;
if|if
condition|(
name|headerBytes
operator|==
operator|-
literal|1
condition|)
block|{
comment|// connection broke while reading headers. also handled if later _q_disconnected is called
name|m_channel
operator|->
name|handleUnexpectedEOF
argument_list|()
expr_stmt|;
return|return;
block|}
name|bytes
operator|+=
name|headerBytes
expr_stmt|;
comment|// If headers were parsed successfully now it is the ReadingDataState
if|if
condition|(
name|replyPrivate
operator|->
name|state
operator|==
name|QHttpNetworkReplyPrivate
operator|::
name|ReadingDataState
condition|)
block|{
if|if
condition|(
name|replyPrivate
operator|->
name|isCompressed
argument_list|()
operator|&&
name|replyPrivate
operator|->
name|autoDecompress
condition|)
block|{
comment|// remove the Content-Length from header
name|replyPrivate
operator|->
name|removeAutoDecompressHeader
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|replyPrivate
operator|->
name|autoDecompress
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|replyPrivate
operator|->
name|statusCode
operator|==
literal|100
condition|)
block|{
name|replyPrivate
operator|->
name|clearHttpLayerInformation
argument_list|()
expr_stmt|;
name|replyPrivate
operator|->
name|state
operator|=
name|QHttpNetworkReplyPrivate
operator|::
name|ReadingStatusState
expr_stmt|;
break|break;
comment|// ignore
block|}
if|if
condition|(
name|replyPrivate
operator|->
name|shouldEmitSignals
argument_list|()
condition|)
emit|emit
name|m_reply
operator|->
name|headerChanged
argument_list|()
emit|;
comment|// After headerChanged had been emitted
comment|// we can suddenly have a replyPrivate->userProvidedDownloadBuffer
comment|// this is handled in the ReadingDataState however
if|if
condition|(
operator|!
name|replyPrivate
operator|->
name|expectContent
argument_list|()
condition|)
block|{
name|replyPrivate
operator|->
name|state
operator|=
name|QHttpNetworkReplyPrivate
operator|::
name|AllDoneState
expr_stmt|;
name|m_channel
operator|->
name|allDone
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
break|break;
block|}
case|case
name|QHttpNetworkReplyPrivate
operator|::
name|ReadingDataState
case|:
block|{
name|QHttpNetworkReplyPrivate
modifier|*
name|replyPrivate
init|=
name|m_reply
operator|->
name|d_func
argument_list|()
decl_stmt|;
if|if
condition|(
name|m_socket
operator|->
name|state
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|ConnectedState
operator|&&
name|replyPrivate
operator|->
name|downstreamLimited
operator|&&
operator|!
name|replyPrivate
operator|->
name|responseData
operator|.
name|isEmpty
argument_list|()
operator|&&
name|replyPrivate
operator|->
name|shouldEmitSignals
argument_list|()
condition|)
block|{
comment|// (only do the following when still connected, not when we have already been disconnected and there is still data)
comment|// We already have some HTTP body data. We don't read more from the socket until
comment|// this is fetched by QHttpNetworkAccessHttpBackend. If we would read more,
comment|// we could not limit our read buffer usage.
comment|// We only do this when shouldEmitSignals==true because our HTTP parsing
comment|// always needs to parse the 401/407 replies. Therefore they don't really obey
comment|// to the read buffer maximum size, but we don't care since they should be small.
return|return;
block|}
if|if
condition|(
name|replyPrivate
operator|->
name|userProvidedDownloadBuffer
condition|)
block|{
comment|// the user provided a direct buffer where we should put all our data in.
comment|// this only works when we can tell the user the content length and he/she can allocate
comment|// the buffer in that size.
comment|// note that this call will read only from the still buffered data
name|qint64
name|haveRead
init|=
name|replyPrivate
operator|->
name|readBodyVeryFast
argument_list|(
name|m_socket
argument_list|,
name|replyPrivate
operator|->
name|userProvidedDownloadBuffer
operator|+
name|replyPrivate
operator|->
name|totalProgress
argument_list|)
decl_stmt|;
if|if
condition|(
name|haveRead
operator|>
literal|0
condition|)
block|{
name|bytes
operator|+=
name|haveRead
expr_stmt|;
name|replyPrivate
operator|->
name|totalProgress
operator|+=
name|haveRead
expr_stmt|;
comment|// the user will get notified of it via progress signal
emit|emit
name|m_reply
operator|->
name|dataReadProgress
argument_list|(
name|replyPrivate
operator|->
name|totalProgress
argument_list|,
name|replyPrivate
operator|->
name|bodyLength
argument_list|)
emit|;
block|}
elseif|else
if|if
condition|(
name|haveRead
operator|==
literal|0
condition|)
block|{
comment|// Happens since this called in a loop. Currently no bytes available.
block|}
elseif|else
if|if
condition|(
name|haveRead
operator|<
literal|0
condition|)
block|{
name|m_connection
operator|->
name|d_func
argument_list|()
operator|->
name|emitReplyError
argument_list|(
name|m_socket
argument_list|,
name|m_reply
argument_list|,
name|QNetworkReply
operator|::
name|RemoteHostClosedError
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
elseif|else
if|if
condition|(
operator|!
name|replyPrivate
operator|->
name|isChunked
argument_list|()
operator|&&
operator|!
name|replyPrivate
operator|->
name|autoDecompress
operator|&&
name|replyPrivate
operator|->
name|bodyLength
operator|>
literal|0
condition|)
block|{
comment|// bulk files like images should fulfill these properties and
comment|// we can therefore save on memory copying
name|qint64
name|haveRead
init|=
name|replyPrivate
operator|->
name|readBodyFast
argument_list|(
name|m_socket
argument_list|,
operator|&
name|replyPrivate
operator|->
name|responseData
argument_list|)
decl_stmt|;
name|bytes
operator|+=
name|haveRead
expr_stmt|;
name|replyPrivate
operator|->
name|totalProgress
operator|+=
name|haveRead
expr_stmt|;
if|if
condition|(
name|replyPrivate
operator|->
name|shouldEmitSignals
argument_list|()
condition|)
block|{
emit|emit
name|m_reply
operator|->
name|readyRead
argument_list|()
emit|;
emit|emit
name|m_reply
operator|->
name|dataReadProgress
argument_list|(
name|replyPrivate
operator|->
name|totalProgress
argument_list|,
name|replyPrivate
operator|->
name|bodyLength
argument_list|)
emit|;
block|}
block|}
else|else
block|{
comment|// use the traditional slower reading (for compressed encoding, chunked encoding,
comment|// no content-length etc)
name|qint64
name|haveRead
init|=
name|replyPrivate
operator|->
name|readBody
argument_list|(
name|m_socket
argument_list|,
operator|&
name|replyPrivate
operator|->
name|responseData
argument_list|)
decl_stmt|;
if|if
condition|(
name|haveRead
operator|>
literal|0
condition|)
block|{
name|bytes
operator|+=
name|haveRead
expr_stmt|;
name|replyPrivate
operator|->
name|totalProgress
operator|+=
name|haveRead
expr_stmt|;
if|if
condition|(
name|replyPrivate
operator|->
name|shouldEmitSignals
argument_list|()
condition|)
block|{
emit|emit
name|m_reply
operator|->
name|readyRead
argument_list|()
emit|;
emit|emit
name|m_reply
operator|->
name|dataReadProgress
argument_list|(
name|replyPrivate
operator|->
name|totalProgress
argument_list|,
name|replyPrivate
operator|->
name|bodyLength
argument_list|)
emit|;
block|}
block|}
elseif|else
if|if
condition|(
name|haveRead
operator|==
operator|-
literal|1
condition|)
block|{
comment|// Some error occurred
name|m_connection
operator|->
name|d_func
argument_list|()
operator|->
name|emitReplyError
argument_list|(
name|m_socket
argument_list|,
name|m_reply
argument_list|,
name|QNetworkReply
operator|::
name|ProtocolFailure
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|// still in ReadingDataState? This function will be called again by the socket's readyRead
if|if
condition|(
name|replyPrivate
operator|->
name|state
operator|==
name|QHttpNetworkReplyPrivate
operator|::
name|ReadingDataState
condition|)
break|break;
comment|// everything done, fall through
block|}
case|case
name|QHttpNetworkReplyPrivate
operator|::
name|AllDoneState
case|:
name|m_channel
operator|->
name|allDone
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
do|while
condition|(
name|bytes
operator|!=
name|lastBytes
operator|&&
name|m_reply
condition|)
do|;
block|}
end_function
begin_function
DECL|function|_q_readyRead
name|void
name|QHttpProtocolHandler
operator|::
name|_q_readyRead
parameter_list|()
block|{
if|if
condition|(
name|m_socket
operator|->
name|state
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|ConnectedState
operator|&&
name|m_socket
operator|->
name|bytesAvailable
argument_list|()
operator|==
literal|0
condition|)
block|{
comment|// We got a readyRead but no bytes are available..
comment|// This happens for the Unbuffered QTcpSocket
comment|// Also check if socket is in ConnectedState since
comment|// this function may also be invoked via the event loop.
name|char
name|c
decl_stmt|;
name|qint64
name|ret
init|=
name|m_socket
operator|->
name|peek
argument_list|(
operator|&
name|c
argument_list|,
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|<
literal|0
condition|)
block|{
name|m_channel
operator|->
name|_q_error
argument_list|(
name|m_socket
operator|->
name|error
argument_list|()
argument_list|)
expr_stmt|;
comment|// We still need to handle the reply so it emits its signals etc.
if|if
condition|(
name|m_reply
condition|)
name|_q_receiveReply
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
if|if
condition|(
name|m_channel
operator|->
name|isSocketWaiting
argument_list|()
operator|||
name|m_channel
operator|->
name|isSocketReading
argument_list|()
condition|)
block|{
name|m_channel
operator|->
name|state
operator|=
name|QHttpNetworkConnectionChannel
operator|::
name|ReadingState
expr_stmt|;
if|if
condition|(
name|m_reply
condition|)
name|_q_receiveReply
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sendRequest
name|bool
name|QHttpProtocolHandler
operator|::
name|sendRequest
parameter_list|()
block|{
name|m_reply
operator|=
name|m_channel
operator|->
name|reply
expr_stmt|;
if|if
condition|(
operator|!
name|m_reply
condition|)
block|{
comment|// heh, how should that happen!
name|qWarning
argument_list|()
operator|<<
literal|"QAbstractProtocolHandler::sendRequest() called without QHttpNetworkReply"
expr_stmt|;
name|m_channel
operator|->
name|state
operator|=
name|QHttpNetworkConnectionChannel
operator|::
name|IdleState
expr_stmt|;
return|return
literal|false
return|;
block|}
switch|switch
condition|(
name|m_channel
operator|->
name|state
condition|)
block|{
case|case
name|QHttpNetworkConnectionChannel
operator|::
name|IdleState
case|:
block|{
comment|// write the header
if|if
condition|(
operator|!
name|m_channel
operator|->
name|ensureConnection
argument_list|()
condition|)
block|{
comment|// wait for the connection (and encryption) to be done
comment|// sendRequest will be called again from either
comment|// _q_connected or _q_encrypted
return|return
literal|false
return|;
block|}
name|QString
name|scheme
init|=
name|m_channel
operator|->
name|request
operator|.
name|url
argument_list|()
operator|.
name|scheme
argument_list|()
decl_stmt|;
if|if
condition|(
name|scheme
operator|==
name|QLatin1String
argument_list|(
literal|"preconnect-http"
argument_list|)
operator|||
name|scheme
operator|==
name|QLatin1String
argument_list|(
literal|"preconnect-https"
argument_list|)
condition|)
block|{
name|m_channel
operator|->
name|state
operator|=
name|QHttpNetworkConnectionChannel
operator|::
name|IdleState
expr_stmt|;
name|m_reply
operator|->
name|d_func
argument_list|()
operator|->
name|state
operator|=
name|QHttpNetworkReplyPrivate
operator|::
name|AllDoneState
expr_stmt|;
name|m_channel
operator|->
name|allDone
argument_list|()
expr_stmt|;
name|m_connection
operator|->
name|preConnectFinished
argument_list|()
expr_stmt|;
comment|// will only decrease the counter
name|m_reply
operator|=
literal|0
expr_stmt|;
comment|// so we can reuse this channel
return|return
literal|true
return|;
comment|// we have a working connection and are done
block|}
name|m_channel
operator|->
name|written
operator|=
literal|0
expr_stmt|;
comment|// excluding the header
name|m_channel
operator|->
name|bytesTotal
operator|=
literal|0
expr_stmt|;
name|QHttpNetworkReplyPrivate
modifier|*
name|replyPrivate
init|=
name|m_reply
operator|->
name|d_func
argument_list|()
decl_stmt|;
name|replyPrivate
operator|->
name|clear
argument_list|()
expr_stmt|;
name|replyPrivate
operator|->
name|connection
operator|=
name|m_connection
expr_stmt|;
name|replyPrivate
operator|->
name|connectionChannel
operator|=
name|m_channel
expr_stmt|;
name|replyPrivate
operator|->
name|autoDecompress
operator|=
name|m_channel
operator|->
name|request
operator|.
name|d
operator|->
name|autoDecompress
expr_stmt|;
name|replyPrivate
operator|->
name|pipeliningUsed
operator|=
literal|false
expr_stmt|;
comment|// if the url contains authentication parameters, use the new ones
comment|// both channels will use the new authentication parameters
if|if
condition|(
operator|!
name|m_channel
operator|->
name|request
operator|.
name|url
argument_list|()
operator|.
name|userInfo
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
name|m_channel
operator|->
name|request
operator|.
name|withCredentials
argument_list|()
condition|)
block|{
name|QUrl
name|url
init|=
name|m_channel
operator|->
name|request
operator|.
name|url
argument_list|()
decl_stmt|;
name|QAuthenticator
modifier|&
name|auth
init|=
name|m_channel
operator|->
name|authenticator
decl_stmt|;
if|if
condition|(
name|url
operator|.
name|userName
argument_list|()
operator|!=
name|auth
operator|.
name|user
argument_list|()
operator|||
operator|(
operator|!
name|url
operator|.
name|password
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
name|url
operator|.
name|password
argument_list|()
operator|!=
name|auth
operator|.
name|password
argument_list|()
operator|)
condition|)
block|{
name|auth
operator|.
name|setUser
argument_list|(
name|url
operator|.
name|userName
argument_list|()
argument_list|)
expr_stmt|;
name|auth
operator|.
name|setPassword
argument_list|(
name|url
operator|.
name|password
argument_list|()
argument_list|)
expr_stmt|;
name|m_connection
operator|->
name|d_func
argument_list|()
operator|->
name|copyCredentials
argument_list|(
name|m_connection
operator|->
name|d_func
argument_list|()
operator|->
name|indexOf
argument_list|(
name|m_socket
argument_list|)
argument_list|,
operator|&
name|auth
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
comment|// clear the userinfo,  since we use the same request for resending
comment|// userinfo in url can conflict with the one in the authenticator
name|url
operator|.
name|setUserInfo
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|m_channel
operator|->
name|request
operator|.
name|setUrl
argument_list|(
name|url
argument_list|)
expr_stmt|;
block|}
comment|// Will only be false if Qt WebKit is performing a cross-origin XMLHttpRequest
comment|// and withCredentials has not been set to true.
if|if
condition|(
name|m_channel
operator|->
name|request
operator|.
name|withCredentials
argument_list|()
condition|)
name|m_connection
operator|->
name|d_func
argument_list|()
operator|->
name|createAuthorization
argument_list|(
name|m_socket
argument_list|,
name|m_channel
operator|->
name|request
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
name|QByteArray
name|header
init|=
name|QHttpNetworkRequestPrivate
operator|::
name|header
argument_list|(
name|m_channel
operator|->
name|request
argument_list|,
operator|(
name|m_connection
operator|->
name|d_func
argument_list|()
operator|->
name|networkProxy
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkProxy
operator|::
name|NoProxy
operator|)
argument_list|)
decl_stmt|;
else|#
directive|else
name|QByteArray
name|header
init|=
name|QHttpNetworkRequestPrivate
operator|::
name|header
argument_list|(
name|m_channel
operator|->
name|request
argument_list|,
literal|false
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|m_socket
operator|->
name|write
argument_list|(
name|header
argument_list|)
expr_stmt|;
comment|// flushing is dangerous (QSslSocket calls transmit which might read or error)
comment|//        m_socket->flush();
name|QNonContiguousByteDevice
modifier|*
name|uploadByteDevice
init|=
name|m_channel
operator|->
name|request
operator|.
name|uploadByteDevice
argument_list|()
decl_stmt|;
if|if
condition|(
name|uploadByteDevice
condition|)
block|{
comment|// connect the signals so this function gets called again
name|QObject
operator|::
name|connect
argument_list|(
name|uploadByteDevice
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|m_channel
argument_list|,
name|SLOT
argument_list|(
name|_q_uploadDataReadyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_channel
operator|->
name|bytesTotal
operator|=
name|m_channel
operator|->
name|request
operator|.
name|contentLength
argument_list|()
expr_stmt|;
name|m_channel
operator|->
name|state
operator|=
name|QHttpNetworkConnectionChannel
operator|::
name|WritingState
expr_stmt|;
comment|// start writing data
name|sendRequest
argument_list|()
expr_stmt|;
comment|//recurse
block|}
else|else
block|{
name|m_channel
operator|->
name|state
operator|=
name|QHttpNetworkConnectionChannel
operator|::
name|WaitingState
expr_stmt|;
comment|// now wait for response
name|sendRequest
argument_list|()
expr_stmt|;
comment|//recurse
block|}
break|break;
block|}
case|case
name|QHttpNetworkConnectionChannel
operator|::
name|WritingState
case|:
block|{
comment|// write the data
name|QNonContiguousByteDevice
modifier|*
name|uploadByteDevice
init|=
name|m_channel
operator|->
name|request
operator|.
name|uploadByteDevice
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|uploadByteDevice
operator|||
name|m_channel
operator|->
name|bytesTotal
operator|==
name|m_channel
operator|->
name|written
condition|)
block|{
if|if
condition|(
name|uploadByteDevice
condition|)
emit|emit
name|m_reply
operator|->
name|dataSendProgress
argument_list|(
name|m_channel
operator|->
name|written
argument_list|,
name|m_channel
operator|->
name|bytesTotal
argument_list|)
emit|;
name|m_channel
operator|->
name|state
operator|=
name|QHttpNetworkConnectionChannel
operator|::
name|WaitingState
expr_stmt|;
comment|// now wait for response
name|sendRequest
argument_list|()
expr_stmt|;
comment|// recurse
break|break;
block|}
comment|// only feed the QTcpSocket buffer when there is less than 32 kB in it
specifier|const
name|qint64
name|socketBufferFill
init|=
literal|32
operator|*
literal|1024
decl_stmt|;
specifier|const
name|qint64
name|socketWriteMaxSize
init|=
literal|16
operator|*
literal|1024
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SSL
name|QSslSocket
modifier|*
name|sslSocket
init|=
name|qobject_cast
argument_list|<
name|QSslSocket
operator|*
argument_list|>
argument_list|(
name|m_socket
argument_list|)
decl_stmt|;
comment|// if it is really an ssl socket, check more than just bytesToWrite()
while|while
condition|(
operator|(
name|m_socket
operator|->
name|bytesToWrite
argument_list|()
operator|+
operator|(
name|sslSocket
condition|?
name|sslSocket
operator|->
name|encryptedBytesToWrite
argument_list|()
else|:
literal|0
operator|)
operator|)
operator|<=
name|socketBufferFill
operator|&&
name|m_channel
operator|->
name|bytesTotal
operator|!=
name|m_channel
operator|->
name|written
condition|)
else|#
directive|else
while|while
condition|(
name|m_socket
operator|->
name|bytesToWrite
argument_list|()
operator|<=
name|socketBufferFill
operator|&&
name|m_channel
operator|->
name|bytesTotal
operator|!=
name|m_channel
operator|->
name|written
condition|)
endif|#
directive|endif
block|{
comment|// get pointer to upload data
name|qint64
name|currentReadSize
init|=
literal|0
decl_stmt|;
name|qint64
name|desiredReadSize
init|=
name|qMin
argument_list|(
name|socketWriteMaxSize
argument_list|,
name|m_channel
operator|->
name|bytesTotal
operator|-
name|m_channel
operator|->
name|written
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|readPointer
init|=
name|uploadByteDevice
operator|->
name|readPointer
argument_list|(
name|desiredReadSize
argument_list|,
name|currentReadSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|currentReadSize
operator|==
operator|-
literal|1
condition|)
block|{
comment|// premature eof happened
name|m_connection
operator|->
name|d_func
argument_list|()
operator|->
name|emitReplyError
argument_list|(
name|m_socket
argument_list|,
name|m_reply
argument_list|,
name|QNetworkReply
operator|::
name|UnknownNetworkError
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
elseif|else
if|if
condition|(
name|readPointer
operator|==
literal|0
operator|||
name|currentReadSize
operator|==
literal|0
condition|)
block|{
comment|// nothing to read currently, break the loop
break|break;
block|}
else|else
block|{
if|if
condition|(
name|m_channel
operator|->
name|written
operator|!=
name|uploadByteDevice
operator|->
name|pos
argument_list|()
condition|)
block|{
comment|// Sanity check. This was useful in tracking down an upload corruption.
name|qWarning
argument_list|()
operator|<<
literal|"QHttpProtocolHandler: Internal error in sendRequest. Expected to write at position"
operator|<<
name|m_channel
operator|->
name|written
operator|<<
literal|"but read device is at"
operator|<<
name|uploadByteDevice
operator|->
name|pos
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|m_channel
operator|->
name|written
operator|==
name|uploadByteDevice
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|m_connection
operator|->
name|d_func
argument_list|()
operator|->
name|emitReplyError
argument_list|(
name|m_socket
argument_list|,
name|m_reply
argument_list|,
name|QNetworkReply
operator|::
name|ProtocolFailure
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|qint64
name|currentWriteSize
init|=
name|m_socket
operator|->
name|write
argument_list|(
name|readPointer
argument_list|,
name|currentReadSize
argument_list|)
decl_stmt|;
if|if
condition|(
name|currentWriteSize
operator|==
operator|-
literal|1
operator|||
name|currentWriteSize
operator|!=
name|currentReadSize
condition|)
block|{
comment|// socket broke down
name|m_connection
operator|->
name|d_func
argument_list|()
operator|->
name|emitReplyError
argument_list|(
name|m_socket
argument_list|,
name|m_reply
argument_list|,
name|QNetworkReply
operator|::
name|UnknownNetworkError
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
else|else
block|{
name|m_channel
operator|->
name|written
operator|+=
name|currentWriteSize
expr_stmt|;
name|uploadByteDevice
operator|->
name|advanceReadPointer
argument_list|(
name|currentWriteSize
argument_list|)
expr_stmt|;
emit|emit
name|m_reply
operator|->
name|dataSendProgress
argument_list|(
name|m_channel
operator|->
name|written
argument_list|,
name|m_channel
operator|->
name|bytesTotal
argument_list|)
emit|;
if|if
condition|(
name|m_channel
operator|->
name|written
operator|==
name|m_channel
operator|->
name|bytesTotal
condition|)
block|{
comment|// make sure this function is called once again
name|m_channel
operator|->
name|state
operator|=
name|QHttpNetworkConnectionChannel
operator|::
name|WaitingState
expr_stmt|;
name|sendRequest
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
break|break;
block|}
case|case
name|QHttpNetworkConnectionChannel
operator|::
name|WaitingState
case|:
block|{
name|QNonContiguousByteDevice
modifier|*
name|uploadByteDevice
init|=
name|m_channel
operator|->
name|request
operator|.
name|uploadByteDevice
argument_list|()
decl_stmt|;
if|if
condition|(
name|uploadByteDevice
condition|)
block|{
name|QObject
operator|::
name|disconnect
argument_list|(
name|uploadByteDevice
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|m_channel
argument_list|,
name|SLOT
argument_list|(
name|_q_uploadDataReadyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// HTTP pipelining
comment|//m_connection->d_func()->fillPipeline(m_socket);
comment|//m_socket->flush();
comment|// ensure we try to receive a reply in all cases, even if _q_readyRead_ hat not been called
comment|// this is needed if the sends an reply before we have finished sending the request. In that
comment|// case receiveReply had been called before but ignored the server reply
if|if
condition|(
name|m_socket
operator|->
name|bytesAvailable
argument_list|()
condition|)
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|m_channel
argument_list|,
literal|"_q_receiveReply"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QHttpNetworkConnectionChannel
operator|::
name|ReadingState
case|:
comment|// ignore _q_bytesWritten in these states
comment|// fall through
default|default:
break|break;
block|}
return|return
literal|true
return|;
block|}
end_function
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
end_unit
