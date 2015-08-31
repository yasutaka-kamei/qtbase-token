begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmirclientplatformservices.h"
end_include
begin_include
include|#
directive|include
file|<QUrl>
end_include
begin_include
include|#
directive|include
file|<ubuntu/application/url_dispatcher/service.h>
end_include
begin_include
include|#
directive|include
file|<ubuntu/application/url_dispatcher/session.h>
end_include
begin_function
DECL|function|openUrl
name|bool
name|QMirClientPlatformServices
operator|::
name|openUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
return|return
name|callDispatcher
argument_list|(
name|url
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|openDocument
name|bool
name|QMirClientPlatformServices
operator|::
name|openDocument
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
return|return
name|callDispatcher
argument_list|(
name|url
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|callDispatcher
name|bool
name|QMirClientPlatformServices
operator|::
name|callDispatcher
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|UAUrlDispatcherSession
modifier|*
name|session
init|=
name|ua_url_dispatcher_session
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|session
condition|)
return|return
literal|false
return|;
name|ua_url_dispatcher_session_open
argument_list|(
name|session
argument_list|,
name|url
operator|.
name|toEncoded
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|session
argument_list|)
expr_stmt|;
comment|// We are returning true here because the other option
comment|// is spawning a nested event loop and wait for the
comment|// callback. But there is no guarantee on how fast
comment|// the callback is going to be so we prefer to avoid the
comment|// nested event loop. Long term plan is improve Qt API
comment|// to support an async openUrl
return|return
literal|true
return|;
block|}
end_function
end_unit