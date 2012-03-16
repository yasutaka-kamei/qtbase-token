begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVDEVMOUSEMANAGER_H
end_ifndef
begin_define
DECL|macro|QEVDEVMOUSEMANAGER_H
define|#
directive|define
name|QEVDEVMOUSEMANAGER_H
end_define
begin_include
include|#
directive|include
file|"qevdevmousehandler.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qudevicehelper_p.h>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QSocketNotifier>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|QEvdevMouseManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QEvdevMouseManager
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
specifier|const
name|QString
operator|&
name|specification
argument_list|)
block|;
operator|~
name|QEvdevMouseManager
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|addMouse
argument_list|(
specifier|const
name|QString
operator|&
name|deviceNode
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|removeMouse
argument_list|(
specifier|const
name|QString
operator|&
name|deviceNode
argument_list|)
block|;
name|private
operator|:
name|QString
name|m_spec
block|;
name|QHash
operator|<
name|QString
block|,
name|QEvdevMouseHandler
operator|*
operator|>
name|m_mice
block|;
name|QUDeviceHelper
operator|*
name|m_udeviceHelper
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_HEADER
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEVDEVMOUSEMANAGER_H
end_comment
end_unit
