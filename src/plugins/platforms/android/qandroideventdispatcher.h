begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QANDROIDEVENTDISPATCHER_H
end_ifndef
begin_define
DECL|macro|QANDROIDEVENTDISPATCHER_H
define|#
directive|define
name|QANDROIDEVENTDISPATCHER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSemaphore>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qunixeventdispatcher_qpa_p.h>
end_include
begin_decl_stmt
name|class
name|QAndroidEventDispatcher
range|:
name|public
name|QUnixEventDispatcherQPA
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QAndroidEventDispatcher
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QAndroidEventDispatcher
argument_list|()
block|;
name|void
name|start
argument_list|()
block|;
name|void
name|stop
argument_list|()
block|;
name|void
name|goingToStop
argument_list|(
argument|bool stop
argument_list|)
block|;
name|protected
operator|:
name|bool
name|processEvents
argument_list|(
argument|QEventLoop::ProcessEventsFlags flags
argument_list|)
block|;
name|private
operator|:
name|QAtomicInt
name|m_stopRequest
block|;
name|QAtomicInt
name|m_goingToStop
block|;
name|QSemaphore
name|m_semaphore
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAndroidEventDispatcherStopper
block|{
name|public
label|:
specifier|static
name|QAndroidEventDispatcherStopper
modifier|*
name|instance
parameter_list|()
function_decl|;
specifier|static
name|bool
name|stopped
parameter_list|()
block|{
return|return
operator|!
name|instance
argument_list|()
operator|->
name|started
return|;
block|}
name|void
name|startAll
parameter_list|()
function_decl|;
name|void
name|stopAll
parameter_list|()
function_decl|;
name|void
name|addEventDispatcher
parameter_list|(
name|QAndroidEventDispatcher
modifier|*
name|dispatcher
parameter_list|)
function_decl|;
name|void
name|removeEventDispatcher
parameter_list|(
name|QAndroidEventDispatcher
modifier|*
name|dispatcher
parameter_list|)
function_decl|;
name|void
name|goingToStop
parameter_list|(
name|bool
name|stop
parameter_list|)
function_decl|;
name|private
label|:
name|QMutex
name|m_mutex
decl_stmt|;
name|bool
name|started
init|=
name|true
decl_stmt|;
name|QVector
operator|<
name|QAndroidEventDispatcher
operator|*
operator|>
name|m_dispatchers
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QANDROIDEVENTDISPATCHER_H
end_comment
end_unit
