begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
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
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontextfactory_p.h>
end_include
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
file|"qeglfsoffscreenwindow.h"
end_include
begin_include
include|#
directive|include
file|"qeglfscursor.h"
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
file|<QtPlatformSupport/private/qgenericunixfontdatabase_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixservices_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbvthandler_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qopenglcompositorbackingstore_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformHeaders/QEGLNativeContext>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBINPUT
end_ifndef
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qlibinputhandler_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EVDEV
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
operator|)
end_if
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qevdevmousemanager_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qevdevkeyboardmanager_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qevdevtouchmanager_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_TSLIB
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
operator|)
end_if
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qtslib_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtPlatformHeaders/qeglfsfunctions.h>
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
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|Q_INIT_RESOURCE
argument_list|(
name|cursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSIntegration
name|QEglFSIntegration
operator|::
name|QEglFSIntegration
parameter_list|()
member_init_list|:
name|m_display
argument_list|(
name|EGL_NO_DISPLAY
argument_list|)
member_init_list|,
name|m_inputContext
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_fontDb
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|)
member_init_list|,
name|m_services
argument_list|(
operator|new
name|QGenericUnixServices
argument_list|)
member_init_list|,
name|m_kbdMgr
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_disableInputHandlers
argument_list|(
literal|false
argument_list|)
block|{
name|m_disableInputHandlers
operator|=
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_EGLFS_DISABLE_INPUT"
argument_list|)
expr_stmt|;
name|initResources
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|addScreen
name|void
name|QEglFSIntegration
operator|::
name|addScreen
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
block|{
name|screenAdded
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeScreen
name|void
name|QEglFSIntegration
operator|::
name|removeScreen
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
block|{
name|destroyScreen
argument_list|(
name|screen
argument_list|)
expr_stmt|;
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
name|qt_egl_device_integration
argument_list|()
operator|->
name|platformInit
argument_list|()
expr_stmt|;
name|m_display
operator|=
name|qt_egl_device_integration
argument_list|()
operator|->
name|createDisplay
argument_list|(
name|nativeDisplay
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_display
operator|==
name|EGL_NO_DISPLAY
condition|)
name|qFatal
argument_list|(
literal|"Could not open egl display"
argument_list|)
expr_stmt|;
name|EGLint
name|major
decl_stmt|,
name|minor
decl_stmt|;
if|if
condition|(
operator|!
name|eglInitialize
argument_list|(
name|m_display
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Could not initialize egl display"
argument_list|)
expr_stmt|;
name|m_inputContext
operator|=
name|QPlatformInputContextFactory
operator|::
name|create
argument_list|()
expr_stmt|;
name|m_vtHandler
operator|.
name|reset
argument_list|(
operator|new
name|QFbVtHandler
argument_list|)
expr_stmt|;
if|if
condition|(
name|qt_egl_device_integration
argument_list|()
operator|->
name|usesDefaultScreen
argument_list|()
condition|)
name|addScreen
argument_list|(
operator|new
name|QEglFSScreen
argument_list|(
name|display
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|qt_egl_device_integration
argument_list|()
operator|->
name|screenInit
argument_list|()
expr_stmt|;
comment|// Input code may rely on the screens, so do it only after the screen init.
if|if
condition|(
operator|!
name|m_disableInputHandlers
condition|)
name|createInputHandlers
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|destroy
name|void
name|QEglFSIntegration
operator|::
name|destroy
parameter_list|()
block|{
foreach|foreach
control|(
name|QWindow
modifier|*
name|w
decl|,
name|qGuiApp
operator|->
name|topLevelWindows
argument_list|()
control|)
name|w
operator|->
name|destroy
argument_list|()
expr_stmt|;
name|qt_egl_device_integration
argument_list|()
operator|->
name|screenDestroy
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_display
operator|!=
name|EGL_NO_DISPLAY
condition|)
name|eglTerminate
argument_list|(
name|m_display
argument_list|)
expr_stmt|;
name|qt_egl_device_integration
argument_list|()
operator|->
name|platformDestroy
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QEglFSIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QEglFSIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
name|m_services
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QEglFSIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|m_fontDb
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QEglFSIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QOpenGLCompositorBackingStore
modifier|*
name|bs
init|=
operator|new
name|QOpenGLCompositorBackingStore
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|window
operator|->
name|handle
argument_list|()
condition|)
name|window
operator|->
name|create
argument_list|()
expr_stmt|;
cast|static_cast
argument_list|<
name|QEglFSWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|setBackingStore
argument_list|(
name|bs
argument_list|)
expr_stmt|;
return|return
name|bs
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QEglFSIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QWindowSystemInterface
operator|::
name|flushWindowSystemEvents
argument_list|()
expr_stmt|;
name|QEglFSWindow
modifier|*
name|w
init|=
name|qt_egl_device_integration
argument_list|()
operator|->
name|createWindow
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|w
operator|->
name|create
argument_list|()
expr_stmt|;
if|if
condition|(
name|window
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|ToolTip
condition|)
name|w
operator|->
name|requestActivateWindow
argument_list|()
expr_stmt|;
return|return
name|w
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QEglFSIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
comment|// If there is a "root" window into which raster and QOpenGLWidget content is
comment|// composited, all other contexts must share with its context.
name|QOpenGLContext
modifier|*
name|compositingContext
init|=
name|QOpenGLCompositor
operator|::
name|instance
argument_list|()
operator|->
name|context
argument_list|()
decl_stmt|;
name|EGLDisplay
name|dpy
init|=
name|context
operator|->
name|screen
argument_list|()
condition|?
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|display
argument_list|()
else|:
name|display
argument_list|()
decl_stmt|;
name|QPlatformOpenGLContext
modifier|*
name|share
init|=
name|compositingContext
condition|?
name|compositingContext
operator|->
name|handle
argument_list|()
else|:
name|context
operator|->
name|shareHandle
argument_list|()
decl_stmt|;
name|QVariant
name|nativeHandle
init|=
name|context
operator|->
name|nativeHandle
argument_list|()
decl_stmt|;
name|QEglFSContext
modifier|*
name|ctx
decl_stmt|;
name|QSurfaceFormat
name|adjustedFormat
init|=
name|qt_egl_device_integration
argument_list|()
operator|->
name|surfaceFormatFor
argument_list|(
name|context
operator|->
name|format
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|nativeHandle
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|EGLConfig
name|config
init|=
name|QEglFSIntegration
operator|::
name|chooseConfig
argument_list|(
name|dpy
argument_list|,
name|adjustedFormat
argument_list|)
decl_stmt|;
name|ctx
operator|=
operator|new
name|QEglFSContext
argument_list|(
name|adjustedFormat
argument_list|,
name|share
argument_list|,
name|dpy
argument_list|,
operator|&
name|config
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ctx
operator|=
operator|new
name|QEglFSContext
argument_list|(
name|adjustedFormat
argument_list|,
name|share
argument_list|,
name|dpy
argument_list|,
literal|0
argument_list|,
name|nativeHandle
argument_list|)
expr_stmt|;
block|}
name|nativeHandle
operator|=
name|QVariant
operator|::
name|fromValue
argument_list|<
name|QEGLNativeContext
argument_list|>
argument_list|(
name|QEGLNativeContext
argument_list|(
name|ctx
operator|->
name|eglContext
argument_list|()
argument_list|,
name|dpy
argument_list|)
argument_list|)
expr_stmt|;
name|context
operator|->
name|setNativeHandle
argument_list|(
name|nativeHandle
argument_list|)
expr_stmt|;
return|return
name|ctx
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOffscreenSurface
name|QPlatformOffscreenSurface
modifier|*
name|QEglFSIntegration
operator|::
name|createPlatformOffscreenSurface
parameter_list|(
name|QOffscreenSurface
modifier|*
name|surface
parameter_list|)
specifier|const
block|{
name|EGLDisplay
name|dpy
init|=
name|surface
operator|->
name|screen
argument_list|()
condition|?
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|surface
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|display
argument_list|()
else|:
name|display
argument_list|()
decl_stmt|;
name|QSurfaceFormat
name|fmt
init|=
name|qt_egl_device_integration
argument_list|()
operator|->
name|surfaceFormatFor
argument_list|(
name|surface
operator|->
name|requestedFormat
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|qt_egl_device_integration
argument_list|()
operator|->
name|supportsPBuffers
argument_list|()
condition|)
block|{
name|QEGLPlatformContext
operator|::
name|Flags
name|flags
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|qt_egl_device_integration
argument_list|()
operator|->
name|supportsSurfacelessContexts
argument_list|()
condition|)
name|flags
operator||=
name|QEGLPlatformContext
operator|::
name|NoSurfaceless
expr_stmt|;
return|return
operator|new
name|QEGLPbuffer
argument_list|(
name|dpy
argument_list|,
name|fmt
argument_list|,
name|surface
argument_list|,
name|flags
argument_list|)
return|;
block|}
else|else
block|{
return|return
operator|new
name|QEglFSOffscreenWindow
argument_list|(
name|dpy
argument_list|,
name|fmt
argument_list|,
name|surface
argument_list|)
return|;
block|}
comment|// Never return null. Multiple QWindows are not supported by this plugin.
block|}
end_function
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
name|qt_egl_device_integration
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
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
case|case
name|OpenGL
case|:
return|return
literal|true
return|;
case|case
name|ThreadedOpenGL
case|:
return|return
literal|true
return|;
case|case
name|WindowManagement
case|:
return|return
literal|false
return|;
case|case
name|RasterGLSurface
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QEglFSIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
cast|const_cast
argument_list|<
name|QEglFSIntegration
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
return|;
block|}
end_function
begin_enum
DECL|enum|ResourceType
enum|enum
name|ResourceType
block|{
DECL|enumerator|EglDisplay
name|EglDisplay
block|,
DECL|enumerator|EglWindow
name|EglWindow
block|,
DECL|enumerator|EglContext
name|EglContext
block|,
DECL|enumerator|EglConfig
name|EglConfig
block|,
DECL|enumerator|NativeDisplay
name|NativeDisplay
block|,
DECL|enumerator|XlibDisplay
name|XlibDisplay
block|,
DECL|enumerator|WaylandDisplay
name|WaylandDisplay
block|}
enum|;
end_enum
begin_function
DECL|function|resourceType
specifier|static
name|int
name|resourceType
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
block|{
specifier|static
specifier|const
name|QByteArray
name|names
index|[]
init|=
block|{
comment|// match ResourceType
name|QByteArrayLiteral
argument_list|(
literal|"egldisplay"
argument_list|)
block|,
name|QByteArrayLiteral
argument_list|(
literal|"eglwindow"
argument_list|)
block|,
name|QByteArrayLiteral
argument_list|(
literal|"eglcontext"
argument_list|)
block|,
name|QByteArrayLiteral
argument_list|(
literal|"eglconfig"
argument_list|)
block|,
name|QByteArrayLiteral
argument_list|(
literal|"nativedisplay"
argument_list|)
block|,
name|QByteArrayLiteral
argument_list|(
literal|"display"
argument_list|)
block|,
name|QByteArrayLiteral
argument_list|(
literal|"wl_display"
argument_list|)
block|}
decl_stmt|;
specifier|const
name|QByteArray
modifier|*
name|end
init|=
name|names
operator|+
sizeof|sizeof
argument_list|(
name|names
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|names
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
specifier|const
name|QByteArray
modifier|*
name|result
init|=
name|std
operator|::
name|find
argument_list|(
name|names
argument_list|,
name|end
argument_list|,
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|==
name|end
condition|)
name|result
operator|=
name|std
operator|::
name|find
argument_list|(
name|names
argument_list|,
name|end
argument_list|,
name|key
operator|.
name|toLower
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|int
argument_list|(
name|result
operator|-
name|names
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForIntegration
name|void
modifier|*
name|QEglFSIntegration
operator|::
name|nativeResourceForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|EglDisplay
case|:
name|result
operator|=
name|display
argument_list|()
expr_stmt|;
break|break;
case|case
name|NativeDisplay
case|:
name|result
operator|=
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|nativeDisplay
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|WaylandDisplay
case|:
name|result
operator|=
name|qt_egl_device_integration
argument_list|()
operator|->
name|wlDisplay
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForScreen
name|void
modifier|*
name|QEglFSIntegration
operator|::
name|nativeResourceForScreen
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QScreen
modifier|*
parameter_list|)
block|{
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|XlibDisplay
case|:
comment|// Play nice when using the x11 hooks: Be compatible with xcb that allows querying
comment|// the X Display pointer, which is nothing but our native display.
name|result
operator|=
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|nativeDisplay
argument_list|()
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QEglFSIntegration
operator|::
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|EglDisplay
case|:
if|if
condition|(
name|window
operator|&&
name|window
operator|->
name|handle
argument_list|()
condition|)
name|result
operator|=
cast|static_cast
argument_list|<
name|QEglFSScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
operator|->
name|screen
argument_list|()
argument_list|)
operator|->
name|display
argument_list|()
expr_stmt|;
else|else
name|result
operator|=
name|display
argument_list|()
expr_stmt|;
break|break;
case|case
name|EglWindow
case|:
if|if
condition|(
name|window
operator|&&
name|window
operator|->
name|handle
argument_list|()
condition|)
name|result
operator|=
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
name|QEglFSWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|eglWindow
argument_list|()
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QEglFSIntegration
operator|::
name|nativeResourceForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|EglContext
case|:
if|if
condition|(
name|context
operator|->
name|handle
argument_list|()
condition|)
name|result
operator|=
cast|static_cast
argument_list|<
name|QEglFSContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|eglContext
argument_list|()
expr_stmt|;
break|break;
case|case
name|EglConfig
case|:
if|if
condition|(
name|context
operator|->
name|handle
argument_list|()
condition|)
name|result
operator|=
cast|static_cast
argument_list|<
name|QEglFSContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|eglConfig
argument_list|()
expr_stmt|;
break|break;
case|case
name|EglDisplay
case|:
if|if
condition|(
name|context
operator|->
name|handle
argument_list|()
condition|)
name|result
operator|=
cast|static_cast
argument_list|<
name|QEglFSContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|eglDisplay
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|eglContextForContext
specifier|static
name|void
modifier|*
name|eglContextForContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QEglFSContext
modifier|*
name|handle
init|=
cast|static_cast
argument_list|<
name|QEglFSContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|handle
condition|)
return|return
literal|0
return|;
return|return
name|handle
operator|->
name|eglContext
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForContext
name|QPlatformNativeInterface
operator|::
name|NativeResourceForContextFunction
name|QEglFSIntegration
operator|::
name|nativeResourceFunctionForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
name|QByteArray
name|lowerCaseResource
init|=
name|resource
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|lowerCaseResource
operator|==
literal|"get_egl_context"
condition|)
return|return
name|NativeResourceForContextFunction
argument_list|(
name|eglContextForContext
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|platformFunction
name|QFunctionPointer
name|QEglFSIntegration
operator|::
name|platformFunction
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|function
parameter_list|)
specifier|const
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EVDEV
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
operator|)
if|if
condition|(
name|function
operator|==
name|QEglFSFunctions
operator|::
name|loadKeymapTypeIdentifier
argument_list|()
condition|)
return|return
name|QFunctionPointer
argument_list|(
name|loadKeymapStatic
argument_list|)
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|function
argument_list|)
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|loadKeymapStatic
name|void
name|QEglFSIntegration
operator|::
name|loadKeymapStatic
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EVDEV
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
operator|)
name|QEglFSIntegration
modifier|*
name|self
init|=
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
decl_stmt|;
if|if
condition|(
name|self
operator|->
name|m_kbdMgr
condition|)
name|self
operator|->
name|m_kbdMgr
operator|->
name|loadKeymap
argument_list|(
name|filename
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"QEglFSIntegration: Cannot load keymap, no keyboard handler found"
argument_list|)
expr_stmt|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|filename
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|createInputHandlers
name|void
name|QEglFSIntegration
operator|::
name|createInputHandlers
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_LIBINPUT
if|if
condition|(
operator|!
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_EGLFS_NO_LIBINPUT"
argument_list|)
condition|)
block|{
operator|new
name|QLibInputHandler
argument_list|(
name|QLatin1String
argument_list|(
literal|"libinput"
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EVDEV
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID_NO_SDK
argument_list|)
operator|)
name|m_kbdMgr
operator|=
operator|new
name|QEvdevKeyboardManager
argument_list|(
name|QLatin1String
argument_list|(
literal|"EvdevKeyboard"
argument_list|)
argument_list|,
name|QString
argument_list|()
comment|/* spec */
argument_list|,
name|this
argument_list|)
expr_stmt|;
operator|new
name|QEvdevMouseManager
argument_list|(
name|QLatin1String
argument_list|(
literal|"EvdevMouse"
argument_list|)
argument_list|,
name|QString
argument_list|()
comment|/* spec */
argument_list|,
name|this
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TSLIB
specifier|const
name|bool
name|useTslib
init|=
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_EGLFS_TSLIB"
argument_list|)
decl_stmt|;
if|if
condition|(
name|useTslib
condition|)
operator|new
name|QTsLibMouseHandler
argument_list|(
name|QLatin1String
argument_list|(
literal|"TsLib"
argument_list|)
argument_list|,
name|QString
argument_list|()
comment|/* spec */
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
comment|// QT_NO_TSLIB
operator|new
name|QEvdevTouchManager
argument_list|(
name|QLatin1String
argument_list|(
literal|"EvdevTouch"
argument_list|)
argument_list|,
name|QString
argument_list|()
comment|/* spec */
argument_list|,
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|qt_egl_device_integration
argument_list|()
operator|->
name|platformDisplay
argument_list|()
return|;
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
parameter_list|)
member_init_list|:
name|QEglConfigChooser
argument_list|(
name|display
argument_list|)
block|{ }
name|bool
name|filterConfig
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|qt_egl_device_integration
argument_list|()
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
block|}
class|;
name|Chooser
name|chooser
argument_list|(
name|display
argument_list|)
decl_stmt|;
name|chooser
operator|.
name|setSurfaceType
argument_list|(
name|qt_egl_device_integration
argument_list|()
operator|->
name|surfaceType
argument_list|()
argument_list|)
expr_stmt|;
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
