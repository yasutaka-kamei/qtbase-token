begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//#define QNETWORKACCESSCACHEBACKEND_DEBUG
end_comment
begin_include
include|#
directive|include
file|"qnetworkaccesscachebackend_p.h"
end_include
begin_include
include|#
directive|include
file|"qabstractnetworkcache.h"
end_include
begin_include
include|#
directive|include
file|"qfileinfo.h"
end_include
begin_include
include|#
directive|include
file|"qurlinfo_p.h"
end_include
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QNetworkAccessCacheBackend
name|QNetworkAccessCacheBackend
operator|::
name|QNetworkAccessCacheBackend
parameter_list|()
member_init_list|:
name|QNetworkAccessBackend
argument_list|()
member_init_list|,
name|device
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QNetworkAccessCacheBackend
name|QNetworkAccessCacheBackend
operator|::
name|~
name|QNetworkAccessCacheBackend
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|open
name|void
name|QNetworkAccessCacheBackend
operator|::
name|open
parameter_list|()
block|{
if|if
condition|(
name|operation
argument_list|()
operator|!=
name|QNetworkAccessManager
operator|::
name|GetOperation
operator|||
operator|!
name|sendCacheContents
argument_list|()
condition|)
block|{
name|QString
name|msg
init|=
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QNetworkAccessCacheBackend"
argument_list|,
literal|"Error opening %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|this
operator|->
name|url
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
name|error
argument_list|(
name|QNetworkReply
operator|::
name|ContentNotFoundError
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|SourceIsFromCacheAttribute
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
name|finished
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sendCacheContents
name|bool
name|QNetworkAccessCacheBackend
operator|::
name|sendCacheContents
parameter_list|()
block|{
name|setCachingEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QAbstractNetworkCache
modifier|*
name|nc
init|=
name|networkCache
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|nc
condition|)
return|return
literal|false
return|;
name|QNetworkCacheMetaData
name|item
init|=
name|nc
operator|->
name|metaData
argument_list|(
name|url
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|item
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
name|QNetworkCacheMetaData
operator|::
name|AttributesMap
name|attributes
init|=
name|item
operator|.
name|attributes
argument_list|()
decl_stmt|;
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|HttpStatusCodeAttribute
argument_list|,
name|attributes
operator|.
name|value
argument_list|(
name|QNetworkRequest
operator|::
name|HttpStatusCodeAttribute
argument_list|)
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|HttpReasonPhraseAttribute
argument_list|,
name|attributes
operator|.
name|value
argument_list|(
name|QNetworkRequest
operator|::
name|HttpReasonPhraseAttribute
argument_list|)
argument_list|)
expr_stmt|;
comment|// set the raw headers
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
name|rawHeaders
init|=
name|item
operator|.
name|rawHeaders
argument_list|()
decl_stmt|;
name|QNetworkCacheMetaData
operator|::
name|RawHeaderList
operator|::
name|ConstIterator
name|it
init|=
name|rawHeaders
operator|.
name|constBegin
argument_list|()
decl_stmt|,
name|end
init|=
name|rawHeaders
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|it
operator|->
name|first
operator|.
name|toLower
argument_list|()
operator|==
literal|"cache-control"
operator|&&
name|it
operator|->
name|second
operator|.
name|toLower
argument_list|()
operator|.
name|contains
argument_list|(
literal|"must-revalidate"
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
name|setRawHeader
argument_list|(
name|it
operator|->
name|first
argument_list|,
name|it
operator|->
name|second
argument_list|)
expr_stmt|;
block|}
comment|// handle a possible redirect
name|QVariant
name|redirectionTarget
init|=
name|attributes
operator|.
name|value
argument_list|(
name|QNetworkRequest
operator|::
name|RedirectionTargetAttribute
argument_list|)
decl_stmt|;
if|if
condition|(
name|redirectionTarget
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|setAttribute
argument_list|(
name|QNetworkRequest
operator|::
name|RedirectionTargetAttribute
argument_list|,
name|redirectionTarget
argument_list|)
expr_stmt|;
name|redirectionRequested
argument_list|(
name|redirectionTarget
operator|.
name|toUrl
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// signal we're open
name|metaDataChanged
argument_list|()
expr_stmt|;
if|if
condition|(
name|operation
argument_list|()
operator|==
name|QNetworkAccessManager
operator|::
name|GetOperation
condition|)
block|{
name|QIODevice
modifier|*
name|contents
init|=
name|nc
operator|->
name|data
argument_list|(
name|url
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|contents
condition|)
return|return
literal|false
return|;
name|contents
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|writeDownstreamData
argument_list|(
name|contents
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|QNETWORKACCESSCACHEBACKEND_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"Successfully sent cache:"
operator|<<
name|url
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|closeDownstreamChannel
name|void
name|QNetworkAccessCacheBackend
operator|::
name|closeDownstreamChannel
parameter_list|()
block|{
if|if
condition|(
name|operation
argument_list|()
operator|==
name|QNetworkAccessManager
operator|::
name|GetOperation
condition|)
block|{
name|device
operator|->
name|close
argument_list|()
expr_stmt|;
operator|delete
name|device
expr_stmt|;
name|device
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|closeUpstreamChannel
name|void
name|QNetworkAccessCacheBackend
operator|::
name|closeUpstreamChannel
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"This function show not have been called!"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|upstreamReadyRead
name|void
name|QNetworkAccessCacheBackend
operator|::
name|upstreamReadyRead
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"This function show not have been called!"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|downstreamReadyWrite
name|void
name|QNetworkAccessCacheBackend
operator|::
name|downstreamReadyWrite
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"This function show not have been called!"
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
