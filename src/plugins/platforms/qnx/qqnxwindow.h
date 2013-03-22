begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXWINDOW_H
end_ifndef
begin_define
DECL|macro|QQNXWINDOW_H
define|#
directive|define
name|QQNXWINDOW_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|"qqnxbuffer.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<screen/screen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// all surfaces double buffered
DECL|macro|MAX_BUFFER_COUNT
define|#
directive|define
name|MAX_BUFFER_COUNT
value|2
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
DECL|variable|QQnxGLContext
name|class
name|QQnxGLContext
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QQnxScreen
name|class
name|QQnxScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSurfaceFormat
name|class
name|QSurfaceFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QQnxWindow
range|:
name|public
name|QPlatformWindow
block|{
name|friend
name|class
name|QQnxScreen
block|;
name|public
operator|:
name|QQnxWindow
argument_list|(
argument|QWindow *window
argument_list|,
argument|screen_context_t context
argument_list|)
block|;
name|virtual
operator|~
name|QQnxWindow
argument_list|()
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|setOpacity
argument_list|(
argument|qreal level
argument_list|)
block|;
name|bool
name|isExposed
argument_list|()
specifier|const
block|;
name|WId
name|winId
argument_list|()
specifier|const
block|{
return|return
operator|(
name|WId
operator|)
name|m_window
return|;
block|}
name|screen_window_t
name|nativeHandle
argument_list|()
specifier|const
block|{
return|return
name|m_window
return|;
block|}
comment|// Called by QQnxGLContext::createSurface()
name|QSize
name|requestedBufferSize
argument_list|()
specifier|const
block|;
name|void
name|adjustBufferSize
argument_list|()
block|;
name|void
name|setBufferSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|QSize
name|bufferSize
argument_list|()
specifier|const
block|{
return|return
name|m_bufferSize
return|;
block|}
name|bool
name|hasBuffers
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_bufferSize
operator|.
name|isEmpty
argument_list|()
return|;
block|}
name|QQnxBuffer
operator|&
name|renderBuffer
argument_list|()
block|;
name|void
name|scroll
argument_list|(
argument|const QRegion&region
argument_list|,
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|bool flush=false
argument_list|)
block|;
name|void
name|post
argument_list|(
specifier|const
name|QRegion
operator|&
name|dirty
argument_list|)
block|;
name|void
name|setScreen
argument_list|(
name|QQnxScreen
operator|*
name|platformScreen
argument_list|)
block|;
name|void
name|setParent
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|raise
argument_list|()
block|;
name|void
name|lower
argument_list|()
block|;
name|void
name|requestActivateWindow
argument_list|()
block|;
name|void
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|void
name|gainedFocus
argument_list|()
block|;
name|QQnxScreen
operator|*
name|screen
argument_list|()
specifier|const
block|{
return|return
name|m_screen
return|;
block|}
specifier|const
name|QList
operator|<
name|QQnxWindow
operator|*
operator|>
operator|&
name|children
argument_list|()
specifier|const
block|{
return|return
name|m_childWindows
return|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
name|void
name|setPlatformOpenGLContext
argument_list|(
name|QQnxGLContext
operator|*
name|platformOpenGLContext
argument_list|)
block|;
name|QQnxGLContext
operator|*
name|platformOpenGLContext
argument_list|()
specifier|const
block|{
return|return
name|m_platformOpenGLContext
return|;
block|}
endif|#
directive|endif
name|QQnxWindow
operator|*
name|findWindow
argument_list|(
argument|screen_window_t windowHandle
argument_list|)
block|;
name|void
name|blitFrom
argument_list|(
name|QQnxWindow
operator|*
name|sourceWindow
argument_list|,
specifier|const
name|QPoint
operator|&
name|sourceOffset
argument_list|,
specifier|const
name|QRegion
operator|&
name|targetRegion
argument_list|)
block|;
name|void
name|minimize
argument_list|()
block|;
name|private
operator|:
name|QRect
name|setGeometryHelper
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|removeFromParent
argument_list|()
block|;
name|void
name|setOffset
argument_list|(
specifier|const
name|QPoint
operator|&
name|setOffset
argument_list|)
block|;
name|void
name|updateVisibility
argument_list|(
argument|bool parentVisible
argument_list|)
block|;
name|void
name|updateZorder
argument_list|(
name|int
operator|&
name|topZorder
argument_list|)
block|;
name|void
name|fetchBuffers
argument_list|()
block|;
comment|// Copies content from the previous buffer (back buffer) to the current buffer (front buffer)
name|void
name|blitPreviousToCurrent
argument_list|(
argument|const QRegion&region
argument_list|,
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|bool flush=false
argument_list|)
block|;
name|void
name|blitHelper
argument_list|(
argument|QQnxBuffer&source
argument_list|,
argument|QQnxBuffer&target
argument_list|,
argument|const QPoint&sourceOffset
argument_list|,
argument|const QPoint&targetOffset
argument_list|,
argument|const QRegion&region
argument_list|,
argument|bool flush = false
argument_list|)
block|;
specifier|static
name|int
name|platformWindowFormatToNativeFormat
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|)
block|;
name|screen_context_t
name|m_screenContext
block|;
name|screen_window_t
name|m_window
block|;
name|QSize
name|m_bufferSize
block|;
name|QQnxBuffer
name|m_buffers
index|[
name|MAX_BUFFER_COUNT
index|]
block|;
name|int
name|m_currentBufferIndex
block|;
name|int
name|m_previousBufferIndex
block|;
name|QRegion
name|m_previousDirty
block|;
name|QRegion
name|m_scrolled
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
name|QQnxGLContext
operator|*
name|m_platformOpenGLContext
block|;
endif|#
directive|endif
name|QQnxScreen
operator|*
name|m_screen
block|;
name|QList
operator|<
name|QQnxWindow
operator|*
operator|>
name|m_childWindows
block|;
name|QQnxWindow
operator|*
name|m_parentWindow
block|;
name|bool
name|m_visible
block|;
name|QRect
name|m_unmaximizedGeometry
block|;
name|Qt
operator|::
name|WindowState
name|m_windowState
block|;
comment|// This mutex is used to protect access to the m_requestedBufferSize
comment|// member. This member is used in conjunction with QQnxGLContext::requestNewSurface()
comment|// to coordinate recreating the EGL surface which involves destroying any
comment|// existing EGL surface; resizing the native window buffers; and creating a new
comment|// EGL surface. All of this has to be done from the thread that is calling
comment|// QQnxGLContext::makeCurrent()
name|mutable
name|QMutex
name|m_mutex
block|;
name|QSize
name|m_requestedBufferSize
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
comment|// QQNXWINDOW_H
end_comment
end_unit
