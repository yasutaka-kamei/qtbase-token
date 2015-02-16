begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
DECL|variable|QEglFSKmsScreen
name|class
name|QEglFSKmsScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
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
name|bool
name|open
parameter_list|()
function_decl|;
name|void
name|close
parameter_list|()
function_decl|;
name|void
name|createScreens
parameter_list|()
function_decl|;
name|gbm_device
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
name|int
name|fd
argument_list|()
specifier|const
expr_stmt|;
name|void
name|handleDrmEvent
parameter_list|()
function_decl|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QEglFSKmsDevice
argument_list|)
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
name|gbm_device
modifier|*
name|m_gbm_device
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
