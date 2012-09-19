begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_define
DECL|macro|EGL_EGLEXT_PROTOTYPES
define|#
directive|define
name|EGL_EGLEXT_PROTOTYPES
value|1
end_define
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<EGL/eglext.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QKmsScreen
name|class
name|QKmsScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|gbm_device
name|class
name|gbm_device
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
name|widgetCursor
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
name|EGLImageKHR
name|m_eglImage
block|;
name|QPlatformCursorImage
operator|*
name|m_cursorImage
block|;
name|bool
name|m_moved
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
