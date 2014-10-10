begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|"qeglplatformwindow_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglplatformbackingstore_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglplatformscreen_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QEGLPlatformWindow     \brief Base class for EGL-based platform window implementations.     \since 5.2     \internal     \ingroup qpa      Lightweight class providing some basic platform window operations     and interfacing with QEGLPlatformBackingStore.      Almost no QPlatformWindow functions are implemented here. This is     intentional because different platform plugins may use different     strategies for their window management (some may force fullscreen     windows, some may not, some may share the underlying native     surface, some may not, etc.) and therefore it is not sensible to     enforce anything for these functions.      \note Subclasses are responsible for invoking this class'     implementation of create(). When using QEGLPlatformScreen, the     subclasses of this class are expected to utilize the window stack     management functions (addWindow() etc.) provided there.  */
end_comment
begin_constructor
DECL|function|QEGLPlatformWindow
name|QEGLPlatformWindow
operator|::
name|QEGLPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|w
argument_list|)
member_init_list|,
name|m_winId
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|newWId
specifier|static
name|WId
name|newWId
parameter_list|()
block|{
specifier|static
name|WId
name|id
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|id
operator|==
name|std
operator|::
name|numeric_limits
argument_list|<
name|WId
argument_list|>
operator|::
name|max
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QEGLPlatformWindow: Out of window IDs"
argument_list|)
expr_stmt|;
return|return
operator|++
name|id
return|;
block|}
end_function
begin_function
DECL|function|create
name|void
name|QEGLPlatformWindow
operator|::
name|create
parameter_list|()
block|{
name|m_winId
operator|=
name|newWId
argument_list|()
expr_stmt|;
comment|// Save the original surface type before changing to OpenGLSurface.
name|m_raster
operator|=
operator|(
name|window
argument_list|()
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterSurface
operator|)
expr_stmt|;
if|if
condition|(
name|m_raster
condition|)
comment|// change to OpenGL, but not for RasterGLSurface
name|window
argument_list|()
operator|->
name|setSurfaceType
argument_list|(
name|QSurface
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
if|if
condition|(
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Desktop
condition|)
block|{
name|QRect
name|fullscreenRect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|fullscreenRect
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|fullscreenRect
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_function
begin_function
DECL|function|isRaster
name|bool
name|QEGLPlatformWindow
operator|::
name|isRaster
parameter_list|()
specifier|const
block|{
return|return
name|m_raster
operator|||
name|window
argument_list|()
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterGLSurface
return|;
block|}
end_function
begin_function
DECL|function|textures
specifier|const
name|QPlatformTextureList
modifier|*
name|QEGLPlatformWindow
operator|::
name|textures
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_backingStore
condition|)
return|return
name|m_backingStore
operator|->
name|textures
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|composited
name|void
name|QEGLPlatformWindow
operator|::
name|composited
parameter_list|()
block|{
if|if
condition|(
name|m_backingStore
condition|)
name|m_backingStore
operator|->
name|composited
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|winId
name|WId
name|QEGLPlatformWindow
operator|::
name|winId
parameter_list|()
specifier|const
block|{
return|return
name|m_winId
return|;
block|}
end_function
begin_function
DECL|function|setOpacity
name|void
name|QEGLPlatformWindow
operator|::
name|setOpacity
parameter_list|(
name|qreal
parameter_list|)
block|{
if|if
condition|(
operator|!
name|isRaster
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QEGLPlatformWindow: Cannot set opacity for non-raster windows"
argument_list|)
expr_stmt|;
comment|// Nothing to do here. The opacity is stored in the QWindow.
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
