begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHTTPNETWORKREQUEST_H
end_ifndef
begin_define
DECL|macro|QHTTPNETWORKREQUEST_H
define|#
directive|define
name|QHTTPNETWORKREQUEST_H
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_include
include|#
directive|include
file|<private/qhttpnetworkheader_p.h>
end_include
begin_include
include|#
directive|include
file|<qmetatype.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QNonContiguousByteDevice
name|class
name|QNonContiguousByteDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHttpNetworkRequestPrivate
name|class
name|QHttpNetworkRequestPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QHttpNetworkRequest
range|:
name|public
name|QHttpNetworkHeader
block|{
name|public
operator|:
expr|enum
name|Operation
block|{
name|Options
block|,
name|Get
block|,
name|Head
block|,
name|Post
block|,
name|Put
block|,
name|Delete
block|,
name|Trace
block|,
name|Connect
block|,
name|Custom
block|}
block|;      enum
name|Priority
block|{
name|HighPriority
block|,
name|NormalPriority
block|,
name|LowPriority
block|}
block|;
name|QHttpNetworkRequest
argument_list|(
argument|const QUrl&url = QUrl()
argument_list|,
argument|Operation operation = Get
argument_list|,
argument|Priority priority = NormalPriority
argument_list|)
block|;
name|QHttpNetworkRequest
argument_list|(
specifier|const
name|QHttpNetworkRequest
operator|&
name|other
argument_list|)
block|;
name|virtual
operator|~
name|QHttpNetworkRequest
argument_list|()
block|;
name|QHttpNetworkRequest
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QHttpNetworkRequest
operator|&
name|other
operator|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QHttpNetworkRequest
operator|&
name|other
operator|)
specifier|const
block|;
name|QUrl
name|url
argument_list|()
specifier|const
block|;
name|void
name|setUrl
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
block|;
name|int
name|majorVersion
argument_list|()
specifier|const
block|;
name|int
name|minorVersion
argument_list|()
specifier|const
block|;
name|qint64
name|contentLength
argument_list|()
specifier|const
block|;
name|void
name|setContentLength
argument_list|(
argument|qint64 length
argument_list|)
block|;
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
block|,
name|QByteArray
operator|>
expr|>
name|header
argument_list|()
specifier|const
block|;
name|QByteArray
name|headerField
argument_list|(
argument|const QByteArray&name
argument_list|,
argument|const QByteArray&defaultValue = QByteArray()
argument_list|)
specifier|const
block|;
name|void
name|setHeaderField
argument_list|(
specifier|const
name|QByteArray
operator|&
name|name
argument_list|,
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
block|;
name|Operation
name|operation
argument_list|()
specifier|const
block|;
name|void
name|setOperation
argument_list|(
argument|Operation operation
argument_list|)
block|;
name|QByteArray
name|customVerb
argument_list|()
specifier|const
block|;
name|void
name|setCustomVerb
argument_list|(
specifier|const
name|QByteArray
operator|&
name|customOperation
argument_list|)
block|;
name|Priority
name|priority
argument_list|()
specifier|const
block|;
name|void
name|setPriority
argument_list|(
argument|Priority priority
argument_list|)
block|;
name|bool
name|isPipeliningAllowed
argument_list|()
specifier|const
block|;
name|void
name|setPipeliningAllowed
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|withCredentials
argument_list|()
specifier|const
block|;
name|void
name|setWithCredentials
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|isSsl
argument_list|()
specifier|const
block|;
name|void
name|setSsl
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|setUploadByteDevice
argument_list|(
name|QNonContiguousByteDevice
operator|*
name|bd
argument_list|)
block|;
name|QNonContiguousByteDevice
operator|*
name|uploadByteDevice
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QSharedDataPointer
operator|<
name|QHttpNetworkRequestPrivate
operator|>
name|d
block|;
name|friend
name|class
name|QHttpNetworkRequestPrivate
block|;
name|friend
name|class
name|QHttpNetworkConnectionPrivate
block|;
name|friend
name|class
name|QHttpNetworkConnectionChannel
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QHttpNetworkRequestPrivate
range|:
name|public
name|QHttpNetworkHeaderPrivate
block|{
name|public
operator|:
name|QHttpNetworkRequestPrivate
argument_list|(
argument|QHttpNetworkRequest::Operation op
argument_list|,
argument|QHttpNetworkRequest::Priority pri
argument_list|,
argument|const QUrl&newUrl = QUrl()
argument_list|)
block|;
name|QHttpNetworkRequestPrivate
argument_list|(
specifier|const
name|QHttpNetworkRequestPrivate
operator|&
name|other
argument_list|)
block|;
operator|~
name|QHttpNetworkRequestPrivate
argument_list|()
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QHttpNetworkRequestPrivate
operator|&
name|other
operator|)
specifier|const
block|;
name|QByteArray
name|methodName
argument_list|()
specifier|const
block|;
name|QByteArray
name|uri
argument_list|(
argument|bool throughProxy
argument_list|)
specifier|const
block|;
specifier|static
name|QByteArray
name|header
argument_list|(
argument|const QHttpNetworkRequest&request
argument_list|,
argument|bool throughProxy
argument_list|)
block|;
name|QHttpNetworkRequest
operator|::
name|Operation
name|operation
block|;
name|QByteArray
name|customVerb
block|;
name|QHttpNetworkRequest
operator|::
name|Priority
name|priority
block|;
name|mutable
name|QNonContiguousByteDevice
operator|*
name|uploadByteDevice
block|;
name|bool
name|autoDecompress
block|;
name|bool
name|pipeliningAllowed
block|;
name|bool
name|withCredentials
block|;
name|bool
name|ssl
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QHttpNetworkRequest
argument_list|)
end_decl_stmt
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
comment|// QHTTPNETWORKREQUEST_H
end_comment
end_unit
