begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Pier Luigi Fiorini<pierluigi.fiorini@gmail.com> ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Pelagicore AG ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSKMSDEVICE_H
end_ifndef
begin_define
DECL|macro|QEGLFSKMSDEVICE_H
define|#
directive|define
name|QEGLFSKMSDEVICE_H
end_define
begin_include
include|#
directive|include
file|"qeglfskmsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsscreen.h"
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_EGLFS_EXPORT
name|QEglFSKmsDevice
block|{
name|public
label|:
name|QEglFSKmsDevice
argument_list|(
name|QEglFSKmsIntegration
operator|*
name|integration
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QEglFSKmsDevice
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|open
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|close
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|createScreens
parameter_list|()
function_decl|;
name|virtual
name|EGLNativeDisplayType
name|nativeDisplay
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|int
name|fd
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|devicePath
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|virtual
name|QEglFSKmsScreen
modifier|*
name|createScreen
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
function_decl|;
name|void
name|setFd
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
name|QEglFSKmsIntegration
modifier|*
name|m_integration
decl_stmt|;
name|QString
name|m_path
decl_stmt|;
name|int
name|m_dri_fd
decl_stmt|;
name|quint32
name|m_crtc_allocator
decl_stmt|;
name|quint32
name|m_connector_allocator
decl_stmt|;
name|int
name|crtcForConnector
parameter_list|(
name|drmModeResPtr
name|resources
parameter_list|,
name|drmModeConnectorPtr
name|connector
parameter_list|)
function_decl|;
name|QEglFSKmsScreen
modifier|*
name|screenForConnector
parameter_list|(
name|drmModeResPtr
name|resources
parameter_list|,
name|drmModeConnectorPtr
name|connector
parameter_list|,
name|QPoint
name|pos
parameter_list|)
function_decl|;
name|drmModePropertyPtr
name|connectorProperty
parameter_list|(
name|drmModeConnectorPtr
name|connector
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|void
name|pageFlipHandler
parameter_list|(
name|int
name|fd
parameter_list|,
name|unsigned
name|int
name|sequence
parameter_list|,
name|unsigned
name|int
name|tv_sec
parameter_list|,
name|unsigned
name|int
name|tv_usec
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QEglFSKmsDevice
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
