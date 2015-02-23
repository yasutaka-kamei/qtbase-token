begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLFSKMSSCREEN_H
end_ifndef
begin_define
DECL|macro|QEGLFSKMSSCREEN_H
define|#
directive|define
name|QEGLFSKMSSCREEN_H
end_define
begin_include
include|#
directive|include
file|"qeglfskmsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qeglfsscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
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
DECL|variable|QEglFSKmsDevice
name|class
name|QEglFSKmsDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEglFSKmsCursor
name|class
name|QEglFSKmsCursor
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QEglFSKmsOutput
struct|struct
name|QEglFSKmsOutput
block|{
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|connector_id
name|uint32_t
name|connector_id
decl_stmt|;
DECL|member|crtc_id
name|uint32_t
name|crtc_id
decl_stmt|;
DECL|member|physical_size
name|QSizeF
name|physical_size
decl_stmt|;
DECL|member|mode
name|int
name|mode
decl_stmt|;
comment|// index of selected mode in list below
DECL|member|mode_set
name|bool
name|mode_set
decl_stmt|;
DECL|member|saved_crtc
name|drmModeCrtcPtr
name|saved_crtc
decl_stmt|;
DECL|member|modes
name|QList
operator|<
name|drmModeModeInfo
operator|>
name|modes
expr_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QEglFSKmsScreen
range|:
name|public
name|QEglFSScreen
block|{
name|public
operator|:
name|QEglFSKmsScreen
argument_list|(
argument|QEglFSKmsIntegration *integration
argument_list|,
argument|QEglFSKmsDevice *device
argument_list|,
argument|QEglFSKmsOutput output
argument_list|,
argument|QPoint position
argument_list|)
block|;
operator|~
name|QEglFSKmsScreen
argument_list|()
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|depth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|ScreenOrientation
name|nativeOrientation
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QEglFSKmsDevice
operator|*
name|device
argument_list|()
specifier|const
block|{
return|return
name|m_device
return|;
block|}
name|gbm_surface
operator|*
name|surface
argument_list|()
specifier|const
block|{
return|return
name|m_gbm_surface
return|;
block|}
name|gbm_surface
operator|*
name|createSurface
argument_list|()
block|;
name|void
name|destroySurface
argument_list|()
block|;
name|void
name|waitForFlip
argument_list|()
block|;
name|void
name|flip
argument_list|()
block|;
name|void
name|flipFinished
argument_list|()
block|;
name|QEglFSKmsOutput
operator|&
name|output
argument_list|()
block|{
return|return
name|m_output
return|;
block|}
name|void
name|restoreMode
argument_list|()
block|;
name|private
operator|:
name|QEglFSKmsIntegration
operator|*
name|m_integration
block|;
name|QEglFSKmsDevice
operator|*
name|m_device
block|;
name|gbm_surface
operator|*
name|m_gbm_surface
block|;
name|gbm_bo
operator|*
name|m_gbm_bo_current
block|;
name|gbm_bo
operator|*
name|m_gbm_bo_next
block|;
name|QEglFSKmsOutput
name|m_output
block|;
name|QPoint
name|m_pos
block|;
name|QScopedPointer
operator|<
name|QEglFSKmsCursor
operator|>
name|m_cursor
block|;      struct
name|FrameBuffer
block|{
name|FrameBuffer
argument_list|()
operator|:
name|fb
argument_list|(
literal|0
argument_list|)
block|{}
name|uint32_t
name|fb
block|;     }
block|;
specifier|static
name|void
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
block|;
name|FrameBuffer
operator|*
name|framebufferForBufferObject
argument_list|(
name|gbm_bo
operator|*
name|bo
argument_list|)
block|;
specifier|static
name|QMutex
name|m_waitForFlipMutex
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
end_unit
