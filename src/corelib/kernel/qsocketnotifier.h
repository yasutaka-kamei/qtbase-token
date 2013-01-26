begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSOCKETNOTIFIER_H
end_ifndef
begin_define
DECL|macro|QSOCKETNOTIFIER_H
define|#
directive|define
name|QSOCKETNOTIFIER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSocketNotifierPrivate
name|class
name|QSocketNotifierPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSocketNotifier
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSocketNotifier
argument_list|)
name|public
operator|:
expr|enum
name|Type
block|{
name|Read
block|,
name|Write
block|,
name|Exception
block|}
block|;
name|QSocketNotifier
argument_list|(
argument|qintptr socket
argument_list|,
argument|Type
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
operator|~
name|QSocketNotifier
argument_list|()
block|;
name|qintptr
name|socket
argument_list|()
specifier|const
block|;
name|Type
name|type
argument_list|()
specifier|const
block|;
name|bool
name|isEnabled
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setEnabled
argument_list|(
name|bool
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|activated
argument_list|(
argument|int socket
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
argument_list|,
argument|QPrivateSignal
endif|#
directive|endif
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSocketNotifier
argument_list|)
block|}
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
comment|// QSOCKETNOTIFIER_H
end_comment
end_unit
