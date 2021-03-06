begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Pier Luigi Fiorini<pierluigi.fiorini@gmail.com> ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Pelagicore AG ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfskmsgbmintegration.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsgbmdevice.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsgbmscreen.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsgbmcursor.h"
end_include
begin_include
include|#
directive|include
file|"qeglfscursor.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qdevicediscovery_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonDocument>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonArray>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<xf86drm.h>
end_include
begin_include
include|#
directive|include
file|<xf86drmMode.h>
end_include
begin_include
include|#
directive|include
file|<gbm.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|m_waitForFlipMutex
name|QMutex
name|QEglFSKmsGbmScreen
operator|::
name|m_waitForFlipMutex
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QEglFSKmsGbmIntegration
name|QEglFSKmsGbmIntegration
operator|::
name|QEglFSKmsGbmIntegration
parameter_list|()
member_init_list|:
name|QEglFSKmsIntegration
argument_list|()
block|{}
end_constructor
begin_function
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEglFSKmsGbmIntegration
operator|::
name|createNativeWindow
parameter_list|(
name|QPlatformWindow
modifier|*
name|platformWindow
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|QEglFSKmsGbmScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QEglFSKmsGbmScreen
operator|*
argument_list|>
argument_list|(
name|platformWindow
operator|->
name|screen
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|screen
operator|->
name|surface
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Only single window per screen supported!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
cast|reinterpret_cast
argument_list|<
name|EGLNativeWindowType
argument_list|>
argument_list|(
name|screen
operator|->
name|createSurface
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createNativeOffscreenWindow
name|EGLNativeWindowType
name|QEglFSKmsGbmIntegration
operator|::
name|createNativeOffscreenWindow
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|device
argument_list|()
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Creating native off screen window"
expr_stmt|;
name|gbm_surface
modifier|*
name|surface
init|=
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
literal|1
argument_list|,
literal|1
argument_list|,
name|GBM_FORMAT_XRGB8888
argument_list|,
name|GBM_BO_USE_RENDERING
argument_list|)
decl_stmt|;
return|return
cast|reinterpret_cast
argument_list|<
name|EGLNativeWindowType
argument_list|>
argument_list|(
name|surface
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEglFSKmsGbmIntegration
operator|::
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|gbm_surface
modifier|*
name|surface
init|=
cast|reinterpret_cast
argument_list|<
name|gbm_surface
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|gbm_surface_destroy
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createCursor
name|QPlatformCursor
modifier|*
name|QEglFSKmsGbmIntegration
operator|::
name|createCursor
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|hwCursor
argument_list|()
condition|)
return|return
name|Q_NULLPTR
return|;
else|else
return|return
operator|new
name|QEglFSCursor
argument_list|(
name|screen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|presentBuffer
name|void
name|QEglFSKmsGbmIntegration
operator|::
name|presentBuffer
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|QWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QWindow
operator|*
argument_list|>
argument_list|(
name|surface
operator|->
name|surface
argument_list|()
argument_list|)
decl_stmt|;
name|QEglFSKmsScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QEglFSKmsScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|screen
operator|->
name|flip
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createDevice
name|QEglFSKmsDevice
modifier|*
name|QEglFSKmsGbmIntegration
operator|::
name|createDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|devicePath
parameter_list|)
block|{
name|QString
name|path
init|=
name|devicePath
decl_stmt|;
if|if
condition|(
operator|!
name|devicePath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Using DRM device"
operator|<<
name|path
operator|<<
literal|"specified in config file"
expr_stmt|;
block|}
else|else
block|{
name|QDeviceDiscovery
modifier|*
name|d
init|=
name|QDeviceDiscovery
operator|::
name|create
argument_list|(
name|QDeviceDiscovery
operator|::
name|Device_VideoMask
argument_list|)
decl_stmt|;
name|QStringList
name|devices
init|=
name|d
operator|->
name|scanConnectedDevices
argument_list|()
decl_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Found the following video devices:"
operator|<<
name|devices
expr_stmt|;
name|d
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|devices
operator|.
name|isEmpty
argument_list|()
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Could not find DRM device!"
argument_list|)
expr_stmt|;
name|path
operator|=
name|devices
operator|.
name|first
argument_list|()
expr_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Using"
operator|<<
name|path
expr_stmt|;
block|}
return|return
operator|new
name|QEglFSKmsGbmDevice
argument_list|(
name|this
argument_list|,
name|path
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
