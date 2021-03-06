begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 BlackBerry Limited. All rights reserved. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXRASTERWINDOW_H
end_ifndef
begin_define
DECL|macro|QQNXRASTERWINDOW_H
define|#
directive|define
name|QQNXRASTERWINDOW_H
end_define
begin_include
include|#
directive|include
file|"qqnxwindow.h"
end_include
begin_include
include|#
directive|include
file|"qqnxbuffer.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QQnxRasterWindow
range|:
name|public
name|QQnxWindow
block|{
name|public
operator|:
name|QQnxRasterWindow
argument_list|(
argument|QWindow *window
argument_list|,
argument|screen_context_t context
argument_list|,
argument|bool needRootWindow
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
name|QQnxBuffer
operator|&
name|renderBuffer
argument_list|()
block|;
name|bool
name|hasBuffers
argument_list|()
specifier|const
block|{
return|return
operator|!
name|bufferSize
argument_list|()
operator|.
name|isEmpty
argument_list|()
return|;
block|}
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
name|adjustBufferSize
argument_list|()
block|;
name|protected
operator|:
name|int
name|pixelFormat
argument_list|()
specifier|const
block|;
name|void
name|resetBuffers
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
name|private
operator|:
name|QRegion
name|m_previousDirty
block|;
name|QRegion
name|m_scrolled
block|;
name|int
name|m_currentBufferIndex
block|;
name|int
name|m_previousBufferIndex
block|;
name|QQnxBuffer
name|m_buffers
index|[
name|MAX_BUFFER_COUNT
index|]
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
comment|// QQNXRASTERWINDOW_H
end_comment
end_unit
