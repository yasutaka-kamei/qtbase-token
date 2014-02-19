begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|"qeglfscontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglpbuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOffscreenSurface>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_function
DECL|function|initResources
specifier|static
name|void
name|initResources
parameter_list|()
block|{
name|Q_INIT_RESOURCE
argument_list|(
name|cursor
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QEglFSIntegration
name|QEglFSIntegration
operator|::
name|QEglFSIntegration
parameter_list|()
block|{
name|mDisableInputHandlers
operator|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_DISABLE_INPUT"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|initResources
argument_list|()
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QEglFSIntegration
name|QEglFSIntegration
operator|::
name|~
name|QEglFSIntegration
parameter_list|()
block|{
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|platformDestroy
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hasCapability
name|bool
name|QEglFSIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
comment|// We assume that devices will have more and not less capabilities
if|if
condition|(
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|&&
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|hasCapability
argument_list|(
name|cap
argument_list|)
condition|)
return|return
literal|true
return|;
return|return
name|QEGLPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|QEglFSIntegration
operator|::
name|initialize
parameter_list|()
block|{
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|platformInit
argument_list|()
expr_stmt|;
name|QEGLPlatformIntegration
operator|::
name|initialize
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|mDisableInputHandlers
condition|)
name|createInputHandlers
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nativeDisplay
name|EGLNativeDisplayType
name|QEglFSIntegration
operator|::
name|nativeDisplay
parameter_list|()
specifier|const
block|{
return|return
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|platformDisplay
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createScreen
name|QEGLPlatformScreen
modifier|*
name|QEglFSIntegration
operator|::
name|createScreen
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QEglFSScreen
argument_list|(
name|display
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createWindow
name|QEGLPlatformWindow
modifier|*
name|QEglFSIntegration
operator|::
name|createWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QEglFSWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createContext
name|QEGLPlatformContext
modifier|*
name|QEglFSIntegration
operator|::
name|createContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|shareContext
parameter_list|,
name|EGLDisplay
name|display
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QEglFSContext
argument_list|(
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|surfaceFormatFor
argument_list|(
name|format
argument_list|)
argument_list|,
name|shareContext
argument_list|,
name|display
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createOffscreenSurface
name|QPlatformOffscreenSurface
modifier|*
name|QEglFSIntegration
operator|::
name|createOffscreenSurface
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QOffscreenSurface
modifier|*
name|surface
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QEGLPbuffer
argument_list|(
name|display
argument_list|,
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
operator|->
name|surfaceFormatFor
argument_list|(
name|format
argument_list|)
argument_list|,
name|surface
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|styleHint
name|QVariant
name|QEglFSIntegration
operator|::
name|styleHint
parameter_list|(
name|QPlatformIntegration
operator|::
name|StyleHint
name|hint
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|QPlatformIntegration
operator|::
name|ShowIsFullScreen
case|:
return|return
name|screen
argument_list|()
operator|->
name|compositingWindow
argument_list|()
operator|==
literal|0
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|chooseConfig
name|EGLConfig
name|QEglFSIntegration
operator|::
name|chooseConfig
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
class|class
name|Chooser
super|:
specifier|public
name|QEglConfigChooser
block|{
public|public:
name|Chooser
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|QEglFSHooks
modifier|*
name|hooks
parameter_list|)
member_init_list|:
name|QEglConfigChooser
argument_list|(
name|display
argument_list|)
member_init_list|,
name|m_hooks
argument_list|(
name|hooks
argument_list|)
block|{         }
protected|protected:
name|bool
name|filterConfig
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
specifier|const
block|{
return|return
name|m_hooks
operator|->
name|filterConfig
argument_list|(
name|display
argument_list|()
argument_list|,
name|config
argument_list|)
operator|&&
name|QEglConfigChooser
operator|::
name|filterConfig
argument_list|(
name|config
argument_list|)
return|;
block|}
private|private:
name|QEglFSHooks
modifier|*
name|m_hooks
decl_stmt|;
block|}
class|;
name|Chooser
name|chooser
argument_list|(
name|display
argument_list|,
name|QEglFSHooks
operator|::
name|hooks
argument_list|()
argument_list|)
decl_stmt|;
name|chooser
operator|.
name|setSurfaceFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
return|return
name|chooser
operator|.
name|chooseConfig
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
