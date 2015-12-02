begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Pier Luigi Fiorini<pierluigi.fiorini@gmail.com> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
DECL|class|QEglFSKmsInterruptHandler
name|class
name|QEglFSKmsInterruptHandler
range|:
specifier|public
name|QObject
block|{
specifier|public
operator|:
DECL|function|QEglFSKmsInterruptHandler
name|QEglFSKmsInterruptHandler
argument_list|(
name|QEglFSKmsScreen
operator|*
name|screen
argument_list|)
operator|:
name|m_screen
argument_list|(
argument|screen
argument_list|)
block|{
name|m_vtHandler
operator|=
cast|static_cast
argument_list|<
name|QEglFSIntegration
operator|*
argument_list|>
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
argument_list|)
operator|->
name|vtHandler
argument_list|()
block|;
name|connect
argument_list|(
name|m_vtHandler
argument_list|,
operator|&
name|QFbVtHandler
operator|::
name|interrupted
argument_list|,
name|this
argument_list|,
operator|&
name|QEglFSKmsInterruptHandler
operator|::
name|restoreVideoMode
argument_list|)
block|;
name|connect
argument_list|(
name|m_vtHandler
argument_list|,
operator|&
name|QFbVtHandler
operator|::
name|aboutToSuspend
argument_list|,
name|this
argument_list|,
operator|&
name|QEglFSKmsInterruptHandler
operator|::
name|restoreVideoMode
argument_list|)
block|;     }
specifier|public
name|slots
operator|:
DECL|function|restoreVideoMode
name|void
name|restoreVideoMode
argument_list|()
block|{
name|m_screen
operator|->
name|restoreMode
argument_list|()
block|; }
specifier|private
operator|:
DECL|member|m_vtHandler
name|QFbVtHandler
operator|*
name|m_vtHandler
block|;
DECL|member|m_screen
name|QEglFSKmsScreen
operator|*
name|m_screen
block|; }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|bufferDestroyedHandler
name|void
name|QEglFSKmsScreen
operator|::
name|bufferDestroyedHandler
parameter_list|(
name|gbm_bo
modifier|*
name|bo
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|FrameBuffer
modifier|*
name|fb
init|=
cast|static_cast
argument_list|<
name|FrameBuffer
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
name|fb
operator|->
name|fb
condition|)
block|{
name|gbm_device
modifier|*
name|device
init|=
name|gbm_bo_get_device
argument_list|(
name|bo
argument_list|)
decl_stmt|;
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
expr_stmt|;
block|}
operator|delete
name|fb
expr_stmt|;
block|}
end_function
begin_function
DECL|function|framebufferForBufferObject
name|QEglFSKmsScreen
operator|::
name|FrameBuffer
modifier|*
name|QEglFSKmsScreen
operator|::
name|framebufferForBufferObject
parameter_list|(
name|gbm_bo
modifier|*
name|bo
parameter_list|)
block|{
block|{
name|FrameBuffer
modifier|*
name|fb
init|=
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
decl_stmt|;
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
init|=
name|gbm_bo_get_width
argument_list|(
name|bo
argument_list|)
decl_stmt|;
name|uint32_t
name|height
init|=
name|gbm_bo_get_height
argument_list|(
name|bo
argument_list|)
decl_stmt|;
name|uint32_t
name|stride
init|=
name|gbm_bo_get_stride
argument_list|(
name|bo
argument_list|)
decl_stmt|;
name|uint32_t
name|handle
init|=
name|gbm_bo_get_handle
argument_list|(
name|bo
argument_list|)
operator|.
name|u32
decl_stmt|;
name|QScopedPointer
argument_list|<
name|FrameBuffer
argument_list|>
name|fb
argument_list|(
operator|new
name|FrameBuffer
argument_list|)
decl_stmt|;
name|int
name|ret
init|=
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
decl_stmt|;
if|if
condition|(
name|ret
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to create KMS FB!"
argument_list|)
expr_stmt|;
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
expr_stmt|;
return|return
name|fb
operator|.
name|take
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QEglFSKmsScreen
name|QEglFSKmsScreen
operator|::
name|QEglFSKmsScreen
parameter_list|(
name|QEglFSKmsIntegration
modifier|*
name|integration
parameter_list|,
name|QEglFSKmsDevice
modifier|*
name|device
parameter_list|,
name|QEglFSKmsOutput
name|output
parameter_list|,
name|QPoint
name|position
parameter_list|)
member_init_list|:
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
member_init_list|,
name|m_integration
argument_list|(
name|integration
argument_list|)
member_init_list|,
name|m_device
argument_list|(
name|device
argument_list|)
member_init_list|,
name|m_gbm_surface
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_gbm_bo_current
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_gbm_bo_next
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_output
argument_list|(
name|output
argument_list|)
member_init_list|,
name|m_pos
argument_list|(
name|position
argument_list|)
member_init_list|,
name|m_cursor
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_powerState
argument_list|(
name|PowerStateOn
argument_list|)
member_init_list|,
name|m_interruptHandler
argument_list|(
operator|new
name|QEglFSKmsInterruptHandler
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|m_siblings
operator|<<
name|this
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEglFSKmsScreen
name|QEglFSKmsScreen
operator|::
name|~
name|QEglFSKmsScreen
parameter_list|()
block|{
if|if
condition|(
name|m_output
operator|.
name|dpms_prop
condition|)
block|{
name|drmModeFreeProperty
argument_list|(
name|m_output
operator|.
name|dpms_prop
argument_list|)
expr_stmt|;
name|m_output
operator|.
name|dpms_prop
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
name|restoreMode
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_output
operator|.
name|saved_crtc
condition|)
block|{
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
block|}
operator|delete
name|m_interruptHandler
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|geometry
name|QRect
name|QEglFSKmsScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
specifier|const
name|int
name|mode
init|=
name|m_output
operator|.
name|mode
decl_stmt|;
return|return
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
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QEglFSKmsScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
literal|32
return|;
block|}
end_function
begin_function
DECL|function|format
name|QImage
operator|::
name|Format
name|QEglFSKmsScreen
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|QImage
operator|::
name|Format_RGB32
return|;
block|}
end_function
begin_function
DECL|function|physicalSize
name|QSizeF
name|QEglFSKmsScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
return|return
name|m_output
operator|.
name|physical_size
return|;
block|}
end_function
begin_function
DECL|function|logicalDpi
name|QDpi
name|QEglFSKmsScreen
operator|::
name|logicalDpi
parameter_list|()
specifier|const
block|{
specifier|const
name|QSizeF
name|ps
init|=
name|physicalSize
argument_list|()
decl_stmt|;
specifier|const
name|QSize
name|s
init|=
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ps
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|s
operator|.
name|isEmpty
argument_list|()
condition|)
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
else|else
return|return
name|QDpi
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nativeOrientation
name|Qt
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
operator|!
name|m_integration
operator|->
name|separateScreens
argument_list|()
condition|)
return|return
name|m_device
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
block|{
name|qErrnoWarning
argument_list|(
literal|"Could not set DRM mode!"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_output
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
name|m_output
operator|.
name|mode_set
operator|=
literal|false
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|refreshRate
name|qreal
name|QEglFSKmsScreen
operator|::
name|refreshRate
parameter_list|()
specifier|const
block|{
name|quint32
name|refresh
init|=
name|m_output
operator|.
name|modes
index|[
name|m_output
operator|.
name|mode
index|]
operator|.
name|vrefresh
decl_stmt|;
return|return
name|refresh
operator|>
literal|0
condition|?
name|refresh
else|:
literal|60
return|;
block|}
end_function
begin_function
DECL|function|subpixelAntialiasingTypeHint
name|QPlatformScreen
operator|::
name|SubpixelAntialiasingType
name|QEglFSKmsScreen
operator|::
name|subpixelAntialiasingTypeHint
parameter_list|()
specifier|const
block|{
switch|switch
condition|(
name|m_output
operator|.
name|subpixel
condition|)
block|{
default|default:
case|case
name|DRM_MODE_SUBPIXEL_UNKNOWN
case|:
case|case
name|DRM_MODE_SUBPIXEL_NONE
case|:
return|return
name|Subpixel_None
return|;
case|case
name|DRM_MODE_SUBPIXEL_HORIZONTAL_RGB
case|:
return|return
name|Subpixel_RGB
return|;
case|case
name|DRM_MODE_SUBPIXEL_HORIZONTAL_BGR
case|:
return|return
name|Subpixel_BGR
return|;
case|case
name|DRM_MODE_SUBPIXEL_VERTICAL_RGB
case|:
return|return
name|Subpixel_VRGB
return|;
case|case
name|DRM_MODE_SUBPIXEL_VERTICAL_BGR
case|:
return|return
name|Subpixel_VBGR
return|;
block|}
block|}
end_function
begin_function
DECL|function|powerState
name|QPlatformScreen
operator|::
name|PowerState
name|QEglFSKmsScreen
operator|::
name|powerState
parameter_list|()
specifier|const
block|{
return|return
name|m_powerState
return|;
block|}
end_function
begin_function
DECL|function|setPowerState
name|void
name|QEglFSKmsScreen
operator|::
name|setPowerState
parameter_list|(
name|QPlatformScreen
operator|::
name|PowerState
name|state
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_output
operator|.
name|dpms_prop
condition|)
return|return;
name|drmModeConnectorSetProperty
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_output
operator|.
name|connector_id
argument_list|,
name|m_output
operator|.
name|dpms_prop
operator|->
name|prop_id
argument_list|,
operator|(
name|int
operator|)
name|state
argument_list|)
expr_stmt|;
name|m_powerState
operator|=
name|state
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
