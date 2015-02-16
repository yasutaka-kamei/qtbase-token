begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfskmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsdevice.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmscursor.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
DECL|function|bufferDestroyedHandler
name|void
name|QEglFSKmsScreen
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
name|QEglFSKmsScreen
operator|::
name|FrameBuffer
modifier|*
name|QEglFSKmsScreen
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
name|m_device
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
DECL|function|QEglFSKmsScreen
name|QEglFSKmsScreen
operator|::
name|QEglFSKmsScreen
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
name|QEglFSScreen
argument_list|(
name|eglGetDisplay
argument_list|(
cast|reinterpret_cast
argument_list|<
name|EGLNativeDisplayType
argument_list|>
argument_list|(
name|device
operator|->
name|device
argument_list|()
argument_list|)
argument_list|)
argument_list|)
decl_stmt|,
name|m_integration
argument_list|(
name|integration
argument_list|)
decl_stmt|,
name|m_device
argument_list|(
name|device
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
name|m_output
argument_list|(
name|output
argument_list|)
decl_stmt|,
name|m_pos
argument_list|(
name|position
argument_list|)
decl_stmt|,
name|m_cursor
argument_list|(
name|Q_NULLPTR
argument_list|)
argument_list|{ }
DECL|function|~QEglFSKmsScreen
name|QEglFSKmsScreen
operator|::
name|~
name|QEglFSKmsScreen
argument_list|()
argument_list|{
name|restoreMode
argument_list|()
argument_list|; }
DECL|function|geometry
name|QRect
name|QEglFSKmsScreen
operator|::
name|geometry
argument_list|()
decl|const
argument_list|{
specifier|const
name|int
name|mode
operator|=
name|m_output
operator|.
name|mode
argument_list|;     return
name|QRect
argument_list|(
name|m_pos
operator|.
name|x
argument_list|()
argument_list|,
name|m_pos
operator|.
name|y
argument_list|()
argument_list|,
name|m_output
operator|.
name|modes
index|[
name|mode
index|]
operator|.
name|hdisplay
argument_list|,
name|m_output
operator|.
name|modes
index|[
name|mode
index|]
operator|.
name|vdisplay
argument_list|)
argument_list|; }
DECL|function|depth
name|int
name|QEglFSKmsScreen
operator|::
name|depth
argument_list|()
decl|const
argument_list|{     return
literal|32
argument_list|; }
DECL|function|format
name|QImage
operator|::
name|Format
name|QEglFSKmsScreen
operator|::
name|format
argument_list|()
decl|const
argument_list|{     return
name|QImage
operator|::
name|Format_RGB32
argument_list|; }
DECL|function|physicalSize
name|QSizeF
name|QEglFSKmsScreen
operator|::
name|physicalSize
argument_list|()
decl|const
argument_list|{     return
name|m_output
operator|.
name|physical_size
argument_list|; }
DECL|function|logicalDpi
name|QDpi
name|QEglFSKmsScreen
operator|::
name|logicalDpi
argument_list|()
decl|const
argument_list|{
name|QSizeF
name|ps
operator|=
name|physicalSize
argument_list|()
argument_list|;
name|QSize
name|s
operator|=
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|;      if
operator|(
name|ps
operator|.
name|isValid
argument_list|()
operator|&&
name|s
operator|.
name|isValid
argument_list|()
operator|)
return|return
name|QDpi
argument_list|(
literal|25.4
operator|*
name|s
operator|.
name|width
argument_list|()
operator|/
name|ps
operator|.
name|width
argument_list|()
argument_list|,
literal|25.4
operator|*
name|s
operator|.
name|height
argument_list|()
operator|/
name|ps
operator|.
name|height
argument_list|()
argument_list|)
return|;
end_decl_stmt
begin_else
else|else
return|return
name|QDpi
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
return|;
end_else
begin_function
unit|}  Qt
DECL|function|nativeOrientation
operator|::
name|ScreenOrientation
name|QEglFSKmsScreen
operator|::
name|nativeOrientation
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|PrimaryOrientation
return|;
block|}
end_function
begin_function
DECL|function|orientation
name|Qt
operator|::
name|ScreenOrientation
name|QEglFSKmsScreen
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|PrimaryOrientation
return|;
block|}
end_function
begin_function
DECL|function|name
name|QString
name|QEglFSKmsScreen
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|m_output
operator|.
name|name
return|;
block|}
end_function
begin_function
DECL|function|cursor
name|QPlatformCursor
modifier|*
name|QEglFSKmsScreen
operator|::
name|cursor
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_integration
operator|->
name|hwCursor
argument_list|()
condition|)
block|{
if|if
condition|(
name|m_cursor
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QEglFSKmsScreen
modifier|*
name|that
init|=
cast|const_cast
argument_list|<
name|QEglFSKmsScreen
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|that
operator|->
name|m_cursor
operator|.
name|reset
argument_list|(
operator|new
name|QEglFSKmsCursor
argument_list|(
name|that
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|m_cursor
operator|.
name|data
argument_list|()
return|;
block|}
else|else
block|{
return|return
name|QEglFSScreen
operator|::
name|cursor
argument_list|()
return|;
block|}
block|}
end_function
begin_function
DECL|function|createSurface
name|gbm_surface
modifier|*
name|QEglFSKmsScreen
operator|::
name|createSurface
parameter_list|()
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
name|m_device
operator|->
name|device
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
return|return
name|m_gbm_surface
return|;
block|}
end_function
begin_function
DECL|function|destroySurface
name|void
name|QEglFSKmsScreen
operator|::
name|destroySurface
parameter_list|()
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
block|}
end_function
begin_function
DECL|function|waitForFlip
name|void
name|QEglFSKmsScreen
operator|::
name|waitForFlip
parameter_list|()
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
decl_stmt|;
while|while
condition|(
name|m_gbm_bo_next
condition|)
name|m_device
operator|->
name|handleDrmEvent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|flip
name|void
name|QEglFSKmsScreen
operator|::
name|flip
parameter_list|()
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
name|FrameBuffer
modifier|*
name|fb
init|=
name|framebufferForBufferObject
argument_list|(
name|m_gbm_bo_next
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|m_output
operator|.
name|mode_set
condition|)
block|{
name|int
name|ret
init|=
name|drmModeSetCrtc
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_output
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
name|m_output
operator|.
name|connector_id
argument_list|,
literal|1
argument_list|,
operator|&
name|m_output
operator|.
name|modes
index|[
name|m_output
operator|.
name|mode
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
condition|)
name|qErrnoWarning
argument_list|(
literal|"Could not set DRM mode!"
argument_list|)
expr_stmt|;
else|else
name|m_output
operator|.
name|mode_set
operator|=
literal|true
expr_stmt|;
block|}
name|int
name|ret
init|=
name|drmModePageFlip
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_output
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
block|}
end_function
begin_function
DECL|function|flipFinished
name|void
name|QEglFSKmsScreen
operator|::
name|flipFinished
parameter_list|()
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
name|m_gbm_bo_next
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
end_function
begin_function
DECL|function|restoreMode
name|void
name|QEglFSKmsScreen
operator|::
name|restoreMode
parameter_list|()
block|{
if|if
condition|(
name|m_output
operator|.
name|mode_set
operator|&&
name|m_output
operator|.
name|saved_crtc
condition|)
block|{
name|drmModeSetCrtc
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_output
operator|.
name|saved_crtc
operator|->
name|crtc_id
argument_list|,
name|m_output
operator|.
name|saved_crtc
operator|->
name|buffer_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|m_output
operator|.
name|connector_id
argument_list|,
literal|1
argument_list|,
operator|&
name|m_output
operator|.
name|saved_crtc
operator|->
name|mode
argument_list|)
expr_stmt|;
name|drmModeFreeCrtc
argument_list|(
name|m_output
operator|.
name|saved_crtc
argument_list|)
expr_stmt|;
name|m_output
operator|.
name|saved_crtc
operator|=
name|Q_NULLPTR
expr_stmt|;
name|m_output
operator|.
name|mode_set
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
