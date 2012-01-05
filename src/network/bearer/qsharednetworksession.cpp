begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsharednetworksession_p.h"
end_include
begin_include
include|#
directive|include
file|"qbearerengine_p.h"
end_include
begin_include
include|#
directive|include
file|<QThreadStorage>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|tls
name|QThreadStorage
argument_list|<
name|QSharedNetworkSessionManager
modifier|*
argument_list|>
name|tls
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|sharedNetworkSessionManager
specifier|inline
name|QSharedNetworkSessionManager
modifier|*
name|sharedNetworkSessionManager
parameter_list|()
block|{
name|QSharedNetworkSessionManager
modifier|*
name|rv
init|=
name|tls
operator|.
name|localData
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|rv
condition|)
block|{
name|rv
operator|=
operator|new
name|QSharedNetworkSessionManager
expr_stmt|;
name|tls
operator|.
name|setLocalData
argument_list|(
name|rv
argument_list|)
expr_stmt|;
block|}
return|return
name|rv
return|;
block|}
end_function
begin_function
DECL|function|doDeleteLater
specifier|static
name|void
name|doDeleteLater
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
block|{
name|obj
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getSession
name|QSharedPointer
argument_list|<
name|QNetworkSession
argument_list|>
name|QSharedNetworkSessionManager
operator|::
name|getSession
parameter_list|(
name|QNetworkConfiguration
name|config
parameter_list|)
block|{
name|QSharedNetworkSessionManager
modifier|*
name|m
argument_list|(
name|sharedNetworkSessionManager
argument_list|()
argument_list|)
decl_stmt|;
comment|//if already have a session, return it
if|if
condition|(
name|m
operator|->
name|sessions
operator|.
name|contains
argument_list|(
name|config
argument_list|)
condition|)
block|{
name|QSharedPointer
argument_list|<
name|QNetworkSession
argument_list|>
name|p
init|=
name|m
operator|->
name|sessions
operator|.
name|value
argument_list|(
name|config
argument_list|)
operator|.
name|toStrongRef
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|p
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|p
return|;
block|}
comment|//otherwise make one
name|QSharedPointer
argument_list|<
name|QNetworkSession
argument_list|>
name|session
argument_list|(
operator|new
name|QNetworkSession
argument_list|(
name|config
argument_list|)
argument_list|,
name|doDeleteLater
argument_list|)
decl_stmt|;
name|m
operator|->
name|sessions
index|[
name|config
index|]
operator|=
name|session
expr_stmt|;
return|return
name|session
return|;
block|}
end_function
begin_function
DECL|function|setSession
name|void
name|QSharedNetworkSessionManager
operator|::
name|setSession
parameter_list|(
name|QNetworkConfiguration
name|config
parameter_list|,
name|QSharedPointer
argument_list|<
name|QNetworkSession
argument_list|>
name|session
parameter_list|)
block|{
name|QSharedNetworkSessionManager
modifier|*
name|m
argument_list|(
name|sharedNetworkSessionManager
argument_list|()
argument_list|)
decl_stmt|;
name|m
operator|->
name|sessions
index|[
name|config
index|]
operator|=
name|session
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qHash
name|uint
name|qHash
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
block|{
return|return
operator|(
operator|(
name|uint
operator|)
name|config
operator|.
name|type
argument_list|()
operator|)
operator||
operator|(
operator|(
operator|(
name|uint
operator|)
name|config
operator|.
name|bearerType
argument_list|()
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
operator|(
name|uint
operator|)
name|config
operator|.
name|purpose
argument_list|()
operator|)
operator|<<
literal|16
operator|)
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
comment|// QT_NO_BEARERMANAGEMENT
end_comment
end_unit
