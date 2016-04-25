begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Pier Luigi Fiorini<pierluigi.fiorini@gmail.com> ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Pelagicore AG ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfskmsgbmscreen.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsgbmdevice.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsgbmcursor.h"
end_include
begin_include
include|#
directive|include
file|"qeglfsintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbvthandler_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
DECL|function|bufferDestroyedHandler
name|void
name|QEglFSKmsGbmScreen
operator|::
name|bufferDestroyedHandler
argument_list|(
name|gbm_bo
operator|*
name|bo
argument_list|,
name|void
operator|*
name|data
argument_list|)
argument_list|{
name|FrameBuffer
operator|*
name|fb
operator|=
cast|static_cast
argument_list|<
name|FrameBuffer
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|;      if
operator|(
name|fb
operator|->
name|fb
operator|)
block|{
name|gbm_device
operator|*
name|device
operator|=
name|gbm_bo_get_device
argument_list|(
name|bo
argument_list|)
block|;
name|drmModeRmFB
argument_list|(
name|gbm_device_get_fd
argument_list|(
name|device
argument_list|)
argument_list|,
name|fb
operator|->
name|fb
argument_list|)
block|;     }
operator|delete
name|fb
argument_list|; }
DECL|function|framebufferForBufferObject
name|QEglFSKmsGbmScreen
operator|::
name|FrameBuffer
modifier|*
name|QEglFSKmsGbmScreen
operator|::
name|framebufferForBufferObject
argument_list|(
name|gbm_bo
operator|*
name|bo
argument_list|)
argument_list|{
block|{
name|FrameBuffer
operator|*
name|fb
operator|=
cast|static_cast
argument_list|<
name|FrameBuffer
operator|*
argument_list|>
argument_list|(
name|gbm_bo_get_user_data
argument_list|(
name|bo
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|fb
condition|)
return|return
name|fb
return|;
block|}
name|uint32_t
name|width
operator|=
name|gbm_bo_get_width
argument_list|(
name|bo
argument_list|)
argument_list|;
name|uint32_t
name|height
operator|=
name|gbm_bo_get_height
argument_list|(
name|bo
argument_list|)
argument_list|;
name|uint32_t
name|stride
operator|=
name|gbm_bo_get_stride
argument_list|(
name|bo
argument_list|)
argument_list|;
name|uint32_t
name|handle
operator|=
name|gbm_bo_get_handle
argument_list|(
name|bo
argument_list|)
operator|.
name|u32
argument_list|;
name|QScopedPointer
argument_list|<
name|FrameBuffer
argument_list|>
name|fb
argument_list|(
operator|new
name|FrameBuffer
argument_list|)
argument_list|;
name|int
name|ret
operator|=
name|drmModeAddFB
argument_list|(
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
literal|24
argument_list|,
literal|32
argument_list|,
name|stride
argument_list|,
name|handle
argument_list|,
operator|&
name|fb
operator|->
name|fb
argument_list|)
argument_list|;      if
operator|(
name|ret
operator|)
block|{
name|qWarning
argument_list|(
literal|"Failed to create KMS FB!"
argument_list|)
block|;
return|return
name|Q_NULLPTR
return|;
block|}
name|gbm_bo_set_user_data
argument_list|(
name|bo
argument_list|,
name|fb
operator|.
name|data
argument_list|()
argument_list|,
name|bufferDestroyedHandler
argument_list|)
argument_list|;     return
name|fb
operator|.
name|take
argument_list|()
argument_list|; }
DECL|function|QEglFSKmsGbmScreen
name|QEglFSKmsGbmScreen
operator|::
name|QEglFSKmsGbmScreen
argument_list|(
name|QEglFSKmsIntegration
operator|*
name|integration
argument_list|,
name|QEglFSKmsDevice
operator|*
name|device
argument_list|,
name|QEglFSKmsOutput
name|output
argument_list|,
name|QPoint
name|position
argument_list|)
range|:
name|QEglFSKmsScreen
argument_list|(
name|integration
argument_list|,
name|device
argument_list|,
name|output
argument_list|,
name|position
argument_list|)
decl_stmt|,
name|m_gbm_surface
argument_list|(
name|Q_NULLPTR
argument_list|)
decl_stmt|,
name|m_gbm_bo_current
argument_list|(
name|Q_NULLPTR
argument_list|)
decl_stmt|,
name|m_gbm_bo_next
argument_list|(
name|Q_NULLPTR
argument_list|)
decl_stmt|,
name|m_cursor
argument_list|(
name|Q_NULLPTR
argument_list|)
argument_list|{ }
DECL|function|~QEglFSKmsGbmScreen
name|QEglFSKmsGbmScreen
operator|::
name|~
name|QEglFSKmsGbmScreen
argument_list|()
argument_list|{ }
DECL|function|cursor
name|QPlatformCursor
modifier|*
name|QEglFSKmsGbmScreen
operator|::
name|cursor
argument_list|()
decl|const
argument_list|{     if
operator|(
name|integration
argument_list|()
operator|->
name|hwCursor
argument_list|()
operator|)
block|{
if|if
condition|(
operator|!
name|integration
argument_list|()
operator|->
name|separateScreens
argument_list|()
condition|)
return|return
cast|static_cast
argument_list|<
name|QEglFSKmsGbmDevice
operator|*
argument_list|>
argument_list|(
name|device
argument_list|()
argument_list|)
operator|->
name|globalCursor
argument_list|()
return|;
if|if
condition|(
name|m_cursor
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QEglFSKmsGbmScreen
operator|*
name|that
operator|=
cast|const_cast
argument_list|<
name|QEglFSKmsGbmScreen
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
block|;
name|that
operator|->
name|m_cursor
operator|.
name|reset
argument_list|(
operator|new
name|QEglFSKmsGbmCursor
argument_list|(
name|that
argument_list|)
argument_list|)
expr_stmt|;
end_decl_stmt
begin_expr_stmt
unit|}          return
name|m_cursor
operator|.
name|data
argument_list|()
expr_stmt|;
end_expr_stmt
begin_block
unit|} else
block|{
return|return
name|QEglFSScreen
operator|::
name|cursor
argument_list|()
return|;
block|}
end_block
begin_expr_stmt
unit|}  gbm_surface
DECL|function|createSurface
operator|*
name|QEglFSKmsGbmScreen
operator|::
name|createSurface
operator|(
operator|)
block|{
if|if
condition|(
operator|!
name|m_gbm_surface
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Creating window for screen"
operator|<<
name|name
argument_list|()
expr_stmt|;
name|m_gbm_surface
operator|=
name|gbm_surface_create
argument_list|(
cast|static_cast
argument_list|<
name|QEglFSKmsGbmDevice
operator|*
argument_list|>
argument_list|(
name|device
argument_list|()
argument_list|)
operator|->
name|gbmDevice
argument_list|()
argument_list|,
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
argument_list|,
name|GBM_FORMAT_XRGB8888
argument_list|,
name|GBM_BO_USE_SCANOUT
operator||
name|GBM_BO_USE_RENDERING
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|m_gbm_surface
return|;
end_return
begin_macro
unit|}  void
DECL|function|destroySurface
name|QEglFSKmsGbmScreen
end_macro
begin_expr_stmt
DECL|function|destroySurface
operator|::
name|destroySurface
operator|(
operator|)
block|{
if|if
condition|(
name|m_gbm_bo_current
condition|)
block|{
name|gbm_bo_destroy
argument_list|(
name|m_gbm_bo_current
argument_list|)
expr_stmt|;
name|m_gbm_bo_current
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
end_expr_stmt
begin_if
if|if
condition|(
name|m_gbm_bo_next
condition|)
block|{
name|gbm_bo_destroy
argument_list|(
name|m_gbm_bo_next
argument_list|)
expr_stmt|;
name|m_gbm_bo_next
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
end_if
begin_if
if|if
condition|(
name|m_gbm_surface
condition|)
block|{
name|gbm_surface_destroy
argument_list|(
name|m_gbm_surface
argument_list|)
expr_stmt|;
name|m_gbm_surface
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
end_if
begin_macro
unit|}  void
DECL|function|waitForFlip
name|QEglFSKmsGbmScreen
end_macro
begin_expr_stmt
DECL|function|waitForFlip
operator|::
name|waitForFlip
operator|(
operator|)
block|{
comment|// Don't lock the mutex unless we actually need to
if|if
condition|(
operator|!
name|m_gbm_bo_next
condition|)
return|return;
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_waitForFlipMutex
argument_list|)
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
name|m_gbm_bo_next
condition|)
cast|static_cast
argument_list|<
name|QEglFSKmsGbmDevice
operator|*
argument_list|>
argument_list|(
name|device
argument_list|()
argument_list|)
operator|->
name|handleDrmEvent
argument_list|()
expr_stmt|;
end_while
begin_macro
unit|}  void
DECL|function|flip
name|QEglFSKmsGbmScreen
end_macro
begin_expr_stmt
DECL|function|flip
operator|::
name|flip
operator|(
operator|)
block|{
if|if
condition|(
operator|!
name|m_gbm_surface
condition|)
block|{
name|qWarning
argument_list|(
literal|"Cannot sync before platform init!"
argument_list|)
expr_stmt|;
return|return;
block|}
name|m_gbm_bo_next
operator|=
name|gbm_surface_lock_front_buffer
argument_list|(
name|m_gbm_surface
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|m_gbm_bo_next
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not lock GBM surface front buffer!"
argument_list|)
expr_stmt|;
return|return;
block|}
end_if
begin_decl_stmt
name|FrameBuffer
modifier|*
name|fb
init|=
name|framebufferForBufferObject
argument_list|(
name|m_gbm_bo_next
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
operator|!
name|output
argument_list|()
operator|.
name|mode_set
condition|)
block|{
name|int
name|ret
init|=
name|drmModeSetCrtc
argument_list|(
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|output
argument_list|()
operator|.
name|crtc_id
argument_list|,
name|fb
operator|->
name|fb
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|output
argument_list|()
operator|.
name|connector_id
argument_list|,
literal|1
argument_list|,
operator|&
name|output
argument_list|()
operator|.
name|modes
index|[
name|output
argument_list|()
operator|.
name|mode
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"Could not set DRM mode!"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|output
argument_list|()
operator|.
name|mode_set
operator|=
literal|true
expr_stmt|;
name|setPowerState
argument_list|(
name|PowerStateOn
argument_list|)
expr_stmt|;
block|}
block|}
end_if
begin_decl_stmt
name|int
name|ret
init|=
name|drmModePageFlip
argument_list|(
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|output
argument_list|()
operator|.
name|crtc_id
argument_list|,
name|fb
operator|->
name|fb
argument_list|,
name|DRM_MODE_PAGE_FLIP_EVENT
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|ret
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"Could not queue DRM page flip!"
argument_list|)
expr_stmt|;
name|gbm_surface_release_buffer
argument_list|(
name|m_gbm_surface
argument_list|,
name|m_gbm_bo_next
argument_list|)
expr_stmt|;
name|m_gbm_bo_next
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
end_if
begin_macro
unit|}  void
DECL|function|flipFinished
name|QEglFSKmsGbmScreen
end_macro
begin_expr_stmt
DECL|function|flipFinished
operator|::
name|flipFinished
operator|(
operator|)
block|{
if|if
condition|(
name|m_gbm_bo_current
condition|)
name|gbm_surface_release_buffer
argument_list|(
name|m_gbm_surface
argument_list|,
name|m_gbm_bo_current
argument_list|)
expr_stmt|;
name|m_gbm_bo_current
operator|=
name|m_gbm_bo_next
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_gbm_bo_next
operator|=
name|Q_NULLPTR
expr_stmt|;
end_expr_stmt
unit|}  QT_END_NAMESPACE
end_unit