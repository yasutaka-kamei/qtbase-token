begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVDEVTOUCH_P_H
end_ifndef
begin_define
DECL|macro|QEVDEVTOUCH_P_H
define|#
directive|define
name|QEVDEVTOUCH_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_MTDEV
argument_list|)
end_if
begin_struct_decl
struct_decl|struct
name|mtdev
struct_decl|;
end_struct_decl
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEvdevTouchScreenData
name|class
name|QEvdevTouchScreenData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEvdevTouchScreenHandler
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QEvdevTouchScreenHandler
argument_list|(
specifier|const
name|QString
operator|&
name|specification
operator|=
name|QString
argument_list|()
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEvdevTouchScreenHandler
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|readData
argument_list|()
block|;
name|private
operator|:
name|QSocketNotifier
operator|*
name|m_notify
block|;
name|int
name|m_fd
block|;
name|QEvdevTouchScreenData
operator|*
name|d
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_MTDEV
argument_list|)
name|mtdev
operator|*
name|m_mtdev
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEvdevTouchScreenHandlerThread
range|:
name|public
name|QThread
block|{
name|public
operator|:
name|explicit
name|QEvdevTouchScreenHandlerThread
argument_list|(
specifier|const
name|QString
operator|&
name|spec
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEvdevTouchScreenHandlerThread
argument_list|()
block|;
name|void
name|run
argument_list|()
block|;
name|QEvdevTouchScreenHandler
operator|*
name|handler
argument_list|()
block|{
return|return
name|m_handler
return|;
block|}
name|private
operator|:
name|QString
name|m_spec
block|;
name|QEvdevTouchScreenHandler
operator|*
name|m_handler
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
comment|// QEVDEVTOUCH_P_H
end_comment
end_unit
