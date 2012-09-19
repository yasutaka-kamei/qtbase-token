begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
name|QFTP_H
end_ifndef
begin_define
DECL|macro|QFTP_H
define|#
directive|define
name|QFTP_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<private/qurlinfo_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_FTP
DECL|variable|QFtpPrivate
name|class
name|QFtpPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QFtp
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QFtp
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QFtp
argument_list|()
block|;      enum
name|State
block|{
name|Unconnected
block|,
name|HostLookup
block|,
name|Connecting
block|,
name|Connected
block|,
name|LoggedIn
block|,
name|Closing
block|}
block|;     enum
name|Error
block|{
name|NoError
block|,
name|UnknownError
block|,
name|HostNotFound
block|,
name|ConnectionRefused
block|,
name|NotConnected
block|}
block|;     enum
name|Command
block|{
name|None
block|,
name|SetTransferMode
block|,
name|SetProxy
block|,
name|ConnectToHost
block|,
name|Login
block|,
name|Close
block|,
name|List
block|,
name|Cd
block|,
name|Get
block|,
name|Put
block|,
name|Remove
block|,
name|Mkdir
block|,
name|Rmdir
block|,
name|Rename
block|,
name|RawCommand
block|}
block|;     enum
name|TransferMode
block|{
name|Active
block|,
name|Passive
block|}
block|;     enum
name|TransferType
block|{
name|Binary
block|,
name|Ascii
block|}
block|;
name|int
name|setProxy
argument_list|(
argument|const QString&host
argument_list|,
argument|quint16 port
argument_list|)
block|;
name|int
name|connectToHost
argument_list|(
argument|const QString&host
argument_list|,
argument|quint16 port=
literal|21
argument_list|)
block|;
name|int
name|login
argument_list|(
specifier|const
name|QString
operator|&
name|user
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|password
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|int
name|close
argument_list|()
block|;
name|int
name|setTransferMode
argument_list|(
argument|TransferMode mode
argument_list|)
block|;
name|int
name|list
argument_list|(
specifier|const
name|QString
operator|&
name|dir
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|int
name|cd
argument_list|(
specifier|const
name|QString
operator|&
name|dir
argument_list|)
block|;
name|int
name|get
argument_list|(
argument|const QString&file
argument_list|,
argument|QIODevice *dev=
literal|0
argument_list|,
argument|TransferType type = Binary
argument_list|)
block|;
name|int
name|put
argument_list|(
argument|const QByteArray&data
argument_list|,
argument|const QString&file
argument_list|,
argument|TransferType type = Binary
argument_list|)
block|;
name|int
name|put
argument_list|(
argument|QIODevice *dev
argument_list|,
argument|const QString&file
argument_list|,
argument|TransferType type = Binary
argument_list|)
block|;
name|int
name|remove
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|int
name|mkdir
argument_list|(
specifier|const
name|QString
operator|&
name|dir
argument_list|)
block|;
name|int
name|rmdir
argument_list|(
specifier|const
name|QString
operator|&
name|dir
argument_list|)
block|;
name|int
name|rename
argument_list|(
specifier|const
name|QString
operator|&
name|oldname
argument_list|,
specifier|const
name|QString
operator|&
name|newname
argument_list|)
block|;
name|int
name|rawCommand
argument_list|(
specifier|const
name|QString
operator|&
name|command
argument_list|)
block|;
name|qint64
name|bytesAvailable
argument_list|()
specifier|const
block|;
name|qint64
name|read
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|QByteArray
name|readAll
argument_list|()
block|;
name|int
name|currentId
argument_list|()
specifier|const
block|;
name|QIODevice
operator|*
name|currentDevice
argument_list|()
specifier|const
block|;
name|Command
name|currentCommand
argument_list|()
specifier|const
block|;
name|bool
name|hasPendingCommands
argument_list|()
specifier|const
block|;
name|void
name|clearPendingCommands
argument_list|()
block|;
name|State
name|state
argument_list|()
specifier|const
block|;
name|Error
name|error
argument_list|()
specifier|const
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|abort
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|stateChanged
argument_list|(
name|int
argument_list|)
block|;
name|void
name|listInfo
argument_list|(
specifier|const
name|QUrlInfo
operator|&
argument_list|)
block|;
name|void
name|readyRead
argument_list|()
block|;
name|void
name|dataTransferProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
block|;
name|void
name|rawCommandReply
argument_list|(
name|int
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|commandStarted
argument_list|(
name|int
argument_list|)
block|;
name|void
name|commandFinished
argument_list|(
name|int
argument_list|,
name|bool
argument_list|)
block|;
name|void
name|done
argument_list|(
name|bool
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QFtp
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFtp
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_startNextCommand()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_piFinished(const QString&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_piError(int, const QString&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_piConnectState(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_piFtpReply(int, const QString&)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FTP
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFTP_H
end_comment
end_unit
