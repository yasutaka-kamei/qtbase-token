begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSOPENGLTESTER_H
end_ifndef
begin_define
DECL|macro|QWINDOWSOPENGLTESTER_H
define|#
directive|define
name|QWINDOWSOPENGLTESTER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFlags>
end_include
begin_include
include|#
directive|include
file|<QtCore/qversionnumber.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|GpuDescription
struct|struct
name|GpuDescription
block|{
DECL|function|GpuDescription
name|GpuDescription
argument_list|()
operator|:
name|vendorId
argument_list|(
literal|0
argument_list|)
operator|,
name|deviceId
argument_list|(
literal|0
argument_list|)
operator|,
name|revision
argument_list|(
literal|0
argument_list|)
operator|,
name|subSysId
argument_list|(
literal|0
argument_list|)
block|{}
specifier|static
name|GpuDescription
name|detect
argument_list|()
expr_stmt|;
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|toVariant
argument_list|()
specifier|const
expr_stmt|;
DECL|member|vendorId
name|int
name|vendorId
decl_stmt|;
DECL|member|deviceId
name|int
name|deviceId
decl_stmt|;
DECL|member|revision
name|int
name|revision
decl_stmt|;
DECL|member|subSysId
name|int
name|subSysId
decl_stmt|;
DECL|member|driverVersion
name|QVersionNumber
name|driverVersion
decl_stmt|;
DECL|member|driverName
name|QByteArray
name|driverName
decl_stmt|;
DECL|member|description
name|QByteArray
name|description
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|GpuDescription
operator|&
name|gd
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QWindowsOpenGLTester
block|{
name|public
label|:
enum|enum
name|Renderer
block|{
name|InvalidRenderer
init|=
literal|0x0000
block|,
name|DesktopGl
init|=
literal|0x0001
block|,
name|AngleRendererD3d11
init|=
literal|0x0002
block|,
name|AngleRendererD3d9
init|=
literal|0x0004
block|,
name|AngleRendererD3d11Warp
init|=
literal|0x0008
block|,
comment|// "Windows Advanced Rasterization Platform"
name|AngleBackendMask
init|=
name|AngleRendererD3d11
operator||
name|AngleRendererD3d9
operator||
name|AngleRendererD3d11Warp
block|,
name|Gles
init|=
literal|0x0010
block|,
comment|// ANGLE/unspecified or Generic GLES for Windows CE.
name|GlesMask
init|=
name|Gles
operator||
name|AngleBackendMask
block|,
name|SoftwareRasterizer
init|=
literal|0x0020
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Renderers
argument_list|,
argument|Renderer
argument_list|)
specifier|static
name|Renderer
name|requestedGlesRenderer
parameter_list|()
function_decl|;
specifier|static
name|Renderer
name|requestedRenderer
parameter_list|()
function_decl|;
specifier|static
name|Renderers
name|supportedGlesRenderers
parameter_list|()
function_decl|;
specifier|static
name|Renderers
name|supportedRenderers
parameter_list|()
function_decl|;
name|private
label|:
specifier|static
name|QWindowsOpenGLTester
operator|::
name|Renderers
name|detectSupportedRenderers
argument_list|(
argument|const GpuDescription&gpu
argument_list|,
argument|bool glesOnly
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|testDesktopGL
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QWindowsOpenGLTester::Renderers
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSOPENGLTESTER_H
end_comment
end_unit
