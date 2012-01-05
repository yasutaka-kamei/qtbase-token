begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DBUSDISPATCHER_H
end_ifndef
begin_define
DECL|macro|DBUSDISPATCHER_H
define|#
directive|define
name|DBUSDISPATCHER_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_decl_stmt
name|namespace
name|Maemo
block|{
name|class
name|DBusDispatcherPrivate
decl_stmt|;
name|class
name|DBusDispatcher
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|DBusDispatcher
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QString
operator|&
name|interface
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|DBusDispatcher
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QString
operator|&
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|signalPath
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|DBusDispatcher
argument_list|()
block|;
name|QList
operator|<
name|QVariant
operator|>
name|call
argument_list|(
specifier|const
name|QString
operator|&
name|method
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg1
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg2
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg3
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg4
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg5
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg6
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg7
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg8
operator|=
name|QVariant
argument_list|()
argument_list|)
block|;
name|bool
name|callAsynchronous
argument_list|(
specifier|const
name|QString
operator|&
name|method
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg1
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg2
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg3
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg4
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg5
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg6
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg7
operator|=
name|QVariant
argument_list|()
argument_list|,
specifier|const
name|QVariant
operator|&
name|arg8
operator|=
name|QVariant
argument_list|()
argument_list|)
block|;
name|void
name|emitSignalReceived
argument_list|(
specifier|const
name|QString
operator|&
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|signal
argument_list|,
specifier|const
name|QList
operator|<
name|QVariant
operator|>
operator|&
name|args
argument_list|)
block|;
name|void
name|emitCallReply
argument_list|(
specifier|const
name|QString
operator|&
name|method
argument_list|,
specifier|const
name|QList
operator|<
name|QVariant
operator|>
operator|&
name|args
argument_list|,
specifier|const
name|QString
operator|&
name|error
operator|=
literal|""
argument_list|)
block|;
name|void
name|synchronousDispatch
argument_list|(
argument|int timeout_ms
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|signalReceived
argument_list|(
specifier|const
name|QString
operator|&
name|interface
argument_list|,
specifier|const
name|QString
operator|&
name|signal
argument_list|,
specifier|const
name|QList
operator|<
name|QVariant
operator|>
operator|&
name|args
argument_list|)
block|;
name|void
name|callReply
argument_list|(
specifier|const
name|QString
operator|&
name|method
argument_list|,
specifier|const
name|QList
operator|<
name|QVariant
operator|>
operator|&
name|args
argument_list|,
specifier|const
name|QString
operator|&
name|error
argument_list|)
block|;
name|protected
operator|:
name|void
name|setupDBus
argument_list|()
block|;
name|private
operator|:
name|DBusDispatcherPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// Maemo namespace
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
