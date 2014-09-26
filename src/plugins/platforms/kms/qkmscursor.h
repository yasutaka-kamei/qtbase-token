begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QKMSCURSOR_H
end_ifndef
begin_define
DECL|macro|QKMSCURSOR_H
define|#
directive|define
name|QKMSCURSOR_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_struct_decl
struct_decl|struct
name|gbm_device
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|gbm_bo
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QKmsScreen
name|class
name|QKmsScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QKmsCursor
range|:
name|public
name|QPlatformCursor
block|{
name|public
operator|:
name|QKmsCursor
argument_list|(
name|QKmsScreen
operator|*
name|screen
argument_list|)
block|;
operator|~
name|QKmsCursor
argument_list|()
block|;
name|void
name|pointerEvent
argument_list|(
specifier|const
name|QMouseEvent
operator|&
name|event
argument_list|)
block|;
name|void
name|changeCursor
argument_list|(
name|QCursor
operator|*
name|windowCursor
argument_list|,
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|private
operator|:
name|QKmsScreen
operator|*
name|m_screen
block|;
name|gbm_device
operator|*
name|m_graphicsBufferManager
block|;
name|gbm_bo
operator|*
name|m_cursorBufferObject
block|;
name|QPlatformCursorImage
operator|*
name|m_cursorImage
block|;
name|bool
name|m_moved
block|;
name|QSize
name|m_cursorSize
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
comment|// QKMSCURSOR_H
end_comment
end_unit
