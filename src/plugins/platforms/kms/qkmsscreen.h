begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QKMSSCREEN_H
end_ifndef
begin_define
DECL|macro|QKMSSCREEN_H
define|#
directive|define
name|QKMSSCREEN_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformScreen>
end_include
begin_include
include|#
directive|include
file|"qkmsbuffermanager.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QKmsCursor
name|class
name|QKmsCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKmsDevice
name|class
name|QKmsDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKmsContext
name|class
name|QKmsContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QKmsScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
name|QKmsScreen
argument_list|(
argument|QKmsDevice *device
argument_list|,
argument|int connectorId
argument_list|)
block|;
operator|~
name|QKmsScreen
argument_list|()
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|;
name|GLuint
name|framebufferObject
argument_list|()
specifier|const
block|;
name|quint32
name|crtcId
argument_list|()
specifier|const
block|{
return|return
name|m_crtcId
return|;
block|}
name|QKmsDevice
operator|*
name|device
argument_list|()
specifier|const
block|;
comment|//Called by context for each screen
name|void
name|bindFramebuffer
argument_list|()
block|;
name|void
name|swapBuffers
argument_list|()
block|;
name|void
name|setFlipReady
argument_list|(
argument|unsigned int time
argument_list|)
block|;
name|private
operator|:
name|void
name|performPageFlip
argument_list|()
block|;
name|void
name|initializeScreenMode
argument_list|()
block|;
name|void
name|waitForPageFlipComplete
argument_list|()
block|;
name|QKmsDevice
operator|*
name|m_device
block|;
name|bool
name|m_flipReady
block|;
name|quint32
name|m_connectorId
block|;
name|quint32
name|m_crtcId
block|;
name|drmModeModeInfo
name|m_mode
block|;
name|QRect
name|m_geometry
block|;
name|QSizeF
name|m_physicalSize
block|;
name|int
name|m_depth
block|;
name|QImage
operator|::
name|Format
name|m_format
block|;
name|QKmsCursor
operator|*
name|m_cursor
block|;
name|QKmsBufferManager
name|m_bufferManager
block|;
name|unsigned
name|int
name|m_refreshTime
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
comment|// QKMSSCREEN_H
end_comment
end_unit
