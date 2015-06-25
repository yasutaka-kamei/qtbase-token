begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKREQUEST_H
end_ifndef
begin_define
DECL|macro|QNETWORKREQUEST_H
define|#
directive|define
name|QNETWORKREQUEST_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QSharedDataPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSslConfiguration
name|class
name|QSslConfiguration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkRequestPrivate
name|class
name|QNetworkRequestPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkRequest
block|{
name|public
label|:
enum|enum
name|KnownHeaders
block|{
name|ContentTypeHeader
block|,
name|ContentLengthHeader
block|,
name|LocationHeader
block|,
name|LastModifiedHeader
block|,
name|CookieHeader
block|,
name|SetCookieHeader
block|,
name|ContentDispositionHeader
block|,
comment|// added for QMultipartMessage
name|UserAgentHeader
block|,
name|ServerHeader
block|}
enum|;
enum|enum
name|Attribute
block|{
name|HttpStatusCodeAttribute
block|,
name|HttpReasonPhraseAttribute
block|,
name|RedirectionTargetAttribute
block|,
name|ConnectionEncryptedAttribute
block|,
name|CacheLoadControlAttribute
block|,
name|CacheSaveControlAttribute
block|,
name|SourceIsFromCacheAttribute
block|,
name|DoNotBufferUploadDataAttribute
block|,
name|HttpPipeliningAllowedAttribute
block|,
name|HttpPipeliningWasUsedAttribute
block|,
name|CustomVerbAttribute
block|,
name|CookieLoadControlAttribute
block|,
name|AuthenticationReuseAttribute
block|,
name|CookieSaveControlAttribute
block|,
name|MaximumDownloadBufferSizeAttribute
block|,
comment|// internal
name|DownloadBufferAttribute
block|,
comment|// internal
name|SynchronousRequestAttribute
block|,
comment|// internal
name|BackgroundRequestAttribute
block|,
name|SpdyAllowedAttribute
block|,
name|SpdyWasUsedAttribute
block|,
name|EmitAllUploadProgressSignalsAttribute
block|,
name|FollowRedirectsAttribute
block|,
name|User
init|=
literal|1000
block|,
name|UserMax
init|=
literal|32767
block|}
enum|;
enum|enum
name|CacheLoadControl
block|{
name|AlwaysNetwork
block|,
name|PreferNetwork
block|,
name|PreferCache
block|,
name|AlwaysCache
block|}
enum|;
enum|enum
name|LoadControl
block|{
name|Automatic
init|=
literal|0
block|,
name|Manual
block|}
enum|;
enum|enum
name|Priority
block|{
name|HighPriority
init|=
literal|1
block|,
name|NormalPriority
init|=
literal|3
block|,
name|LowPriority
init|=
literal|5
block|}
enum|;
name|explicit
name|QNetworkRequest
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
init|=
name|QUrl
argument_list|()
parameter_list|)
function_decl|;
name|QNetworkRequest
argument_list|(
specifier|const
name|QNetworkRequest
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QNetworkRequest
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QNetworkRequest
modifier|&
name|operator
init|=
operator|(
name|QNetworkRequest
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QNetworkRequest
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QNetworkRequest
operator|&
name|other
operator|)
decl_stmt|;
name|void
name|swap
parameter_list|(
name|QNetworkRequest
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QNetworkRequest
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QNetworkRequest
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
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
comment|// "cooked" headers
name|QVariant
name|header
argument_list|(
name|KnownHeaders
name|header
argument_list|)
decl|const
decl_stmt|;
name|void
name|setHeader
parameter_list|(
name|KnownHeaders
name|header
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
comment|// raw headers:
name|bool
name|hasRawHeader
argument_list|(
specifier|const
name|QByteArray
operator|&
name|headerName
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|rawHeaderList
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|rawHeader
argument_list|(
specifier|const
name|QByteArray
operator|&
name|headerName
argument_list|)
decl|const
decl_stmt|;
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
comment|// attributes
name|QVariant
name|attribute
argument_list|(
name|Attribute
name|code
argument_list|,
specifier|const
name|QVariant
operator|&
name|defaultValue
operator|=
name|QVariant
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|void
name|setAttribute
parameter_list|(
name|Attribute
name|code
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
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
name|configuration
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|setOriginatingObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
function_decl|;
name|QObject
operator|*
name|originatingObject
argument_list|()
specifier|const
expr_stmt|;
name|Priority
name|priority
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPriority
parameter_list|(
name|Priority
name|priority
parameter_list|)
function_decl|;
comment|// HTTP redirect related
name|int
name|maximumRedirectsAllowed
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMaximumRedirectsAllowed
parameter_list|(
name|int
name|maximumRedirectsAllowed
parameter_list|)
function_decl|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QNetworkRequestPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QNetworkRequestPrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QNetworkRequest
argument_list|)
end_macro
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QNetworkRequest
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
