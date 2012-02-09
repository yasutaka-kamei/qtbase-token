begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOCALSERVER_P_H
end_ifndef
begin_define
DECL|macro|QLOCALSERVER_P_H
define|#
directive|define
name|QLOCALSERVER_P_H
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
comment|// of the QLocalServer class.  This header file may change from
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
name|QT_NO_LOCALSERVER
end_ifndef
begin_include
include|#
directive|include
file|"qlocalserver.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|<qqueue.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_LOCALSOCKET_TCP
argument_list|)
end_if
begin_include
include|#
directive|include
file|<qtcpserver.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<qwineventnotifier.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<private/qabstractsocketengine_p.h>
end_include
begin_include
include|#
directive|include
file|<qsocketnotifier.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QLocalServerPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QLocalServer
argument_list|)
name|public
operator|:
name|QLocalServerPrivate
argument_list|()
operator|:
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_LOCALSOCKET_TCP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|listenSocket
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|socketNotifier
argument_list|(
literal|0
argument_list|)
block|,
endif|#
directive|endif
name|maxPendingConnections
argument_list|(
literal|30
argument_list|)
block|,
name|error
argument_list|(
name|QAbstractSocket
operator|::
name|UnknownSocketError
argument_list|)
block|,
name|socketOptions
argument_list|(
argument|QLocalServer::NoOptions
argument_list|)
block|{     }
name|void
name|init
argument_list|()
block|;
name|bool
name|listen
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|bool
name|listen
argument_list|(
argument|qintptr socketDescriptor
argument_list|)
block|;
specifier|static
name|bool
name|removeServer
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|void
name|closeServer
argument_list|()
block|;
name|void
name|waitForNewConnection
argument_list|(
argument|int msec
argument_list|,
argument|bool *timedOut
argument_list|)
block|;
name|void
name|_q_onNewConnection
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|QT_LOCALSOCKET_TCP
argument_list|)
name|QTcpServer
name|tcpServer
block|;
name|QMap
operator|<
name|quintptr
block|,
name|QTcpSocket
operator|*
operator|>
name|socketMap
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
block|struct
name|Listener
block|{
name|HANDLE
name|handle
block|;
name|OVERLAPPED
name|overlapped
block|;
name|bool
name|connected
block|;     }
block|;
name|void
name|setError
argument_list|(
specifier|const
name|QString
operator|&
name|function
argument_list|)
block|;
name|bool
name|addListener
argument_list|()
block|;
name|QList
operator|<
name|Listener
operator|>
name|listeners
block|;
name|HANDLE
name|eventHandle
block|;
name|QWinEventNotifier
operator|*
name|connectionEventNotifier
block|;
else|#
directive|else
name|void
name|setError
argument_list|(
specifier|const
name|QString
operator|&
name|function
argument_list|)
block|;
name|int
name|listenSocket
block|;
name|QSocketNotifier
operator|*
name|socketNotifier
block|;
endif|#
directive|endif
name|QString
name|serverName
block|;
name|QString
name|fullServerName
block|;
name|int
name|maxPendingConnections
block|;
name|QQueue
operator|<
name|QLocalSocket
operator|*
operator|>
name|pendingConnections
block|;
name|QString
name|errorString
block|;
name|QAbstractSocket
operator|::
name|SocketError
name|error
block|;
name|QLocalServer
operator|::
name|SocketOptions
name|socketOptions
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LOCALSERVER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOCALSERVER_P_H
end_comment
end_unit
