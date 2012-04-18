begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMINTEGRATION_KMS_H
end_ifndef
begin_define
DECL|macro|QPLATFORMINTEGRATION_KMS_H
define|#
directive|define
name|QPLATFORMINTEGRATION_KMS_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qdevicediscovery_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QKmsScreen
name|class
name|QKmsScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKmsDevice
name|class
name|QKmsDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKmsVTHandler
name|class
name|QKmsVTHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QKmsIntegration
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformIntegration
block|{
name|Q_OBJECT
name|public
range|:
name|QKmsIntegration
argument_list|()
decl_stmt|;
operator|~
name|QKmsIntegration
argument_list|()
expr_stmt|;
name|bool
name|hasCapability
argument_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
argument_list|)
decl|const
decl_stmt|;
name|QPlatformOpenGLContext
modifier|*
name|createPlatformOpenGLContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
decl|const
decl_stmt|;
name|QPlatformWindow
modifier|*
name|createPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
decl_stmt|;
name|QPlatformBackingStore
modifier|*
name|createPlatformBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
decl_stmt|;
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
expr_stmt|;
name|QAbstractEventDispatcher
operator|*
name|guiThreadEventDispatcher
argument_list|()
specifier|const
expr_stmt|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
expr_stmt|;
name|void
name|addScreen
parameter_list|(
name|QKmsScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
name|QObject
modifier|*
name|createDevice
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|private
name|slots
range|:
name|void
name|addDevice
argument_list|(
specifier|const
name|QString
operator|&
name|deviceNode
argument_list|)
decl_stmt|;
name|void
name|removeDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|deviceNode
parameter_list|)
function_decl|;
name|private
label|:
name|QStringList
name|findDrmDevices
parameter_list|()
function_decl|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|m_screens
expr_stmt|;
name|QList
operator|<
name|QKmsDevice
operator|*
operator|>
name|m_devices
expr_stmt|;
name|QPlatformFontDatabase
modifier|*
name|m_fontDatabase
decl_stmt|;
name|QAbstractEventDispatcher
modifier|*
name|m_eventDispatcher
decl_stmt|;
name|QPlatformNativeInterface
modifier|*
name|m_nativeInterface
decl_stmt|;
name|QKmsVTHandler
modifier|*
name|m_vtHandler
decl_stmt|;
name|QDeviceDiscovery
modifier|*
name|m_deviceDiscovery
decl_stmt|;
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
