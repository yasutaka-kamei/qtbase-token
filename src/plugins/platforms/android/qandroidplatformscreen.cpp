begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|"qandroidplatformscreen.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformintegration.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimain.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimenu.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformrasterwindow.h"
end_include
begin_include
include|#
directive|include
file|<android/bitmap.h>
end_include
begin_include
include|#
directive|include
file|<android/native_window_jni.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|QANDROIDPLATFORMSCREEN_DEBUG
end_ifdef
begin_class
DECL|class|ScopedProfiler
class|class
name|ScopedProfiler
block|{
public|public:
DECL|function|ScopedProfiler
name|ScopedProfiler
parameter_list|(
specifier|const
name|QString
modifier|&
name|msg
parameter_list|)
block|{
name|m_msg
operator|=
name|msg
expr_stmt|;
name|m_timer
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
DECL|function|~ScopedProfiler
name|~
name|ScopedProfiler
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
name|m_msg
operator|<<
name|m_timer
operator|.
name|elapsed
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|m_timer
name|QTime
name|m_timer
decl_stmt|;
DECL|member|m_msg
name|QString
name|m_msg
decl_stmt|;
block|}
class|;
end_class
begin_define
DECL|macro|PROFILE_SCOPE
define|#
directive|define
name|PROFILE_SCOPE
value|ScopedProfiler ___sp___(__func__)
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|PROFILE_SCOPE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QAndroidPlatformScreen
name|QAndroidPlatformScreen
operator|::
name|QAndroidPlatformScreen
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
member_init_list|,
name|QPlatformScreen
argument_list|()
block|{
name|m_geometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QAndroidPlatformIntegration
operator|::
name|m_defaultGeometryWidth
argument_list|,
name|QAndroidPlatformIntegration
operator|::
name|m_defaultGeometryHeight
argument_list|)
expr_stmt|;
comment|// Raster only apps should set QT_ANDROID_RASTER_IMAGE_DEPTH to 16
comment|// is way much faster than 32
if|if
condition|(
name|qgetenv
argument_list|(
literal|"QT_ANDROID_RASTER_IMAGE_DEPTH"
argument_list|)
operator|.
name|toInt
argument_list|()
operator|==
literal|16
condition|)
block|{
name|m_format
operator|=
name|QImage
operator|::
name|Format_RGB16
expr_stmt|;
name|m_depth
operator|=
literal|16
expr_stmt|;
block|}
else|else
block|{
name|m_format
operator|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
expr_stmt|;
name|m_depth
operator|=
literal|32
expr_stmt|;
block|}
name|m_physicalSize
operator|.
name|setHeight
argument_list|(
name|QAndroidPlatformIntegration
operator|::
name|m_defaultPhysicalSizeHeight
argument_list|)
expr_stmt|;
name|m_physicalSize
operator|.
name|setWidth
argument_list|(
name|QAndroidPlatformIntegration
operator|::
name|m_defaultPhysicalSizeWidth
argument_list|)
expr_stmt|;
name|m_redrawTimer
operator|.
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_redrawTimer
operator|.
name|setInterval
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|m_redrawTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|doRedraw
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QAndroidPlatformScreen
name|QAndroidPlatformScreen
operator|::
name|~
name|QAndroidPlatformScreen
parameter_list|()
block|{
if|if
condition|(
name|m_id
operator|!=
operator|-
literal|1
condition|)
block|{
name|QtAndroid
operator|::
name|destroySurface
argument_list|(
name|m_id
argument_list|)
expr_stmt|;
name|m_surfaceWaitCondition
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_nativeSurface
condition|)
name|ANativeWindow_release
argument_list|(
name|m_nativeSurface
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|topWindow
name|QWindow
modifier|*
name|QAndroidPlatformScreen
operator|::
name|topWindow
parameter_list|()
specifier|const
block|{
foreach|foreach
control|(
name|QAndroidPlatformWindow
modifier|*
name|w
decl|,
name|m_windowStack
control|)
if|if
condition|(
name|w
operator|->
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Window
operator|||
name|w
operator|->
name|window
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|Dialog
condition|)
return|return
name|w
operator|->
name|window
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|topLevelAt
name|QWindow
modifier|*
name|QAndroidPlatformScreen
operator|::
name|topLevelAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
specifier|const
block|{
foreach|foreach
control|(
name|QAndroidPlatformWindow
modifier|*
name|w
decl|,
name|m_windowStack
control|)
block|{
if|if
condition|(
name|w
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|p
argument_list|,
literal|false
argument_list|)
operator|&&
name|w
operator|->
name|window
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
return|return
name|w
operator|->
name|window
argument_list|()
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|addWindow
name|void
name|QAndroidPlatformScreen
operator|::
name|addWindow
parameter_list|(
name|QAndroidPlatformWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
name|window
operator|->
name|parent
argument_list|()
condition|)
return|return;
name|m_windowStack
operator|.
name|prepend
argument_list|(
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
name|window
operator|->
name|isRaster
argument_list|()
condition|)
name|setDirty
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|w
init|=
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|topWindowChanged
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeWindow
name|void
name|QAndroidPlatformScreen
operator|::
name|removeWindow
parameter_list|(
name|QAndroidPlatformWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
name|window
operator|->
name|parent
argument_list|()
condition|)
return|return;
name|m_windowStack
operator|.
name|removeOne
argument_list|(
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
name|window
operator|->
name|isRaster
argument_list|()
condition|)
block|{
name|setDirty
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QWindow
modifier|*
name|w
init|=
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|topWindowChanged
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|raise
name|void
name|QAndroidPlatformScreen
operator|::
name|raise
parameter_list|(
name|QAndroidPlatformWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
name|window
operator|->
name|parent
argument_list|()
condition|)
return|return;
name|int
name|index
init|=
name|m_windowStack
operator|.
name|indexOf
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|<=
literal|0
condition|)
return|return;
name|m_windowStack
operator|.
name|move
argument_list|(
name|index
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|window
operator|->
name|isRaster
argument_list|()
condition|)
block|{
name|setDirty
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QWindow
modifier|*
name|w
init|=
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|topWindowChanged
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lower
name|void
name|QAndroidPlatformScreen
operator|::
name|lower
parameter_list|(
name|QAndroidPlatformWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
name|window
operator|->
name|parent
argument_list|()
condition|)
return|return;
name|int
name|index
init|=
name|m_windowStack
operator|.
name|indexOf
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
operator|-
literal|1
operator|||
name|index
operator|==
operator|(
name|m_windowStack
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|)
condition|)
return|return;
name|m_windowStack
operator|.
name|move
argument_list|(
name|index
argument_list|,
name|m_windowStack
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|window
operator|->
name|isRaster
argument_list|()
condition|)
block|{
name|setDirty
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QWindow
modifier|*
name|w
init|=
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|topWindowChanged
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scheduleUpdate
name|void
name|QAndroidPlatformScreen
operator|::
name|scheduleUpdate
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_redrawTimer
operator|.
name|isActive
argument_list|()
condition|)
name|m_redrawTimer
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDirty
name|void
name|QAndroidPlatformScreen
operator|::
name|setDirty
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QRect
name|intersection
init|=
name|rect
operator|.
name|intersected
argument_list|(
name|m_geometry
argument_list|)
decl_stmt|;
name|m_dirtyRect
operator||=
name|intersection
expr_stmt|;
name|scheduleUpdate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPhysicalSize
name|void
name|QAndroidPlatformScreen
operator|::
name|setPhysicalSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|m_physicalSize
operator|=
name|size
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QAndroidPlatformScreen
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_surfaceMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_geometry
operator|==
name|rect
condition|)
return|return;
name|m_geometry
operator|=
name|rect
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenGeometryChange
argument_list|(
name|QPlatformScreen
operator|::
name|screen
argument_list|()
argument_list|,
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenAvailableGeometryChange
argument_list|(
name|QPlatformScreen
operator|::
name|screen
argument_list|()
argument_list|,
name|availableGeometry
argument_list|()
argument_list|)
expr_stmt|;
name|resizeMaximizedWindows
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_id
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|m_nativeSurface
condition|)
block|{
name|ANativeWindow_release
argument_list|(
name|m_nativeSurface
argument_list|)
expr_stmt|;
name|m_nativeSurface
operator|=
literal|0
expr_stmt|;
block|}
name|QtAndroid
operator|::
name|setSurfaceGeometry
argument_list|(
name|m_id
argument_list|,
name|rect
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|topWindowChanged
name|void
name|QAndroidPlatformScreen
operator|::
name|topWindowChanged
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
block|{
name|QtAndroidMenu
operator|::
name|setActiveTopLevelWindow
argument_list|(
name|w
argument_list|)
expr_stmt|;
if|if
condition|(
name|w
operator|!=
literal|0
condition|)
block|{
name|QAndroidPlatformWindow
modifier|*
name|platformWindow
init|=
cast|static_cast
argument_list|<
name|QAndroidPlatformWindow
operator|*
argument_list|>
argument_list|(
name|w
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|platformWindow
operator|!=
literal|0
condition|)
name|platformWindow
operator|->
name|updateStatusBarVisibility
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|doRedraw
name|void
name|QAndroidPlatformScreen
operator|::
name|doRedraw
parameter_list|()
block|{
name|PROFILE_SCOPE
expr_stmt|;
if|if
condition|(
name|m_dirtyRect
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|m_surfaceMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_id
operator|==
operator|-
literal|1
condition|)
block|{
name|m_id
operator|=
name|QtAndroid
operator|::
name|createSurface
argument_list|(
name|this
argument_list|,
name|m_geometry
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|m_surfaceWaitCondition
operator|.
name|wait
argument_list|(
operator|&
name|m_surfaceMutex
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_nativeSurface
condition|)
return|return;
name|ANativeWindow_Buffer
name|nativeWindowBuffer
decl_stmt|;
name|ARect
name|nativeWindowRect
decl_stmt|;
name|nativeWindowRect
operator|.
name|top
operator|=
name|m_dirtyRect
operator|.
name|top
argument_list|()
expr_stmt|;
name|nativeWindowRect
operator|.
name|left
operator|=
name|m_dirtyRect
operator|.
name|left
argument_list|()
expr_stmt|;
name|nativeWindowRect
operator|.
name|bottom
operator|=
name|m_dirtyRect
operator|.
name|bottom
argument_list|()
operator|+
literal|1
expr_stmt|;
comment|// for some reason that I don't understand the QRect bottom needs to +1 to be the same with ARect bottom
name|nativeWindowRect
operator|.
name|right
operator|=
name|m_dirtyRect
operator|.
name|right
argument_list|()
operator|+
literal|1
expr_stmt|;
comment|// same for the right
name|int
name|ret
decl_stmt|;
if|if
condition|(
operator|(
name|ret
operator|=
name|ANativeWindow_lock
argument_list|(
name|m_nativeSurface
argument_list|,
operator|&
name|nativeWindowBuffer
argument_list|,
operator|&
name|nativeWindowRect
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"ANativeWindow_lock() failed! error="
operator|<<
name|ret
expr_stmt|;
return|return;
block|}
name|int
name|bpp
init|=
literal|4
decl_stmt|;
name|QImage
operator|::
name|Format
name|format
init|=
name|QImage
operator|::
name|Format_RGBA8888_Premultiplied
decl_stmt|;
if|if
condition|(
name|nativeWindowBuffer
operator|.
name|format
operator|==
name|WINDOW_FORMAT_RGB_565
condition|)
block|{
name|bpp
operator|=
literal|2
expr_stmt|;
name|format
operator|=
name|QImage
operator|::
name|Format_RGB16
expr_stmt|;
block|}
name|QImage
name|screenImage
argument_list|(
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|nativeWindowBuffer
operator|.
name|bits
argument_list|)
argument_list|,
name|nativeWindowBuffer
operator|.
name|width
argument_list|,
name|nativeWindowBuffer
operator|.
name|height
argument_list|,
name|nativeWindowBuffer
operator|.
name|stride
operator|*
name|bpp
argument_list|,
name|format
argument_list|)
decl_stmt|;
name|QPainter
name|compositePainter
argument_list|(
operator|&
name|screenImage
argument_list|)
decl_stmt|;
name|compositePainter
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|QRegion
name|visibleRegion
argument_list|(
name|m_dirtyRect
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QAndroidPlatformWindow
modifier|*
name|window
decl|,
name|m_windowStack
control|)
block|{
if|if
condition|(
operator|!
name|window
operator|->
name|window
argument_list|()
operator|->
name|isVisible
argument_list|()
operator|||
operator|!
name|window
operator|->
name|isRaster
argument_list|()
condition|)
continue|continue;
name|QVector
argument_list|<
name|QRect
argument_list|>
name|visibleRects
init|=
name|visibleRegion
operator|.
name|rects
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|visibleRects
control|)
block|{
name|QRect
name|targetRect
init|=
name|window
operator|->
name|geometry
argument_list|()
decl_stmt|;
name|targetRect
operator|&=
name|rect
expr_stmt|;
if|if
condition|(
name|targetRect
operator|.
name|isNull
argument_list|()
condition|)
continue|continue;
name|visibleRegion
operator|-=
name|targetRect
expr_stmt|;
name|QRect
name|windowRect
init|=
name|targetRect
operator|.
name|translated
argument_list|(
operator|-
name|window
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|)
decl_stmt|;
name|QAndroidPlatformBackingStore
modifier|*
name|backingStore
init|=
cast|static_cast
argument_list|<
name|QAndroidPlatformRasterWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
operator|->
name|backingStore
argument_list|()
decl_stmt|;
if|if
condition|(
name|backingStore
condition|)
name|compositePainter
operator|.
name|drawImage
argument_list|(
name|targetRect
operator|.
name|topLeft
argument_list|()
argument_list|,
name|backingStore
operator|->
name|image
argument_list|()
argument_list|,
name|windowRect
argument_list|)
expr_stmt|;
block|}
block|}
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|visibleRegion
operator|.
name|rects
argument_list|()
control|)
block|{
name|compositePainter
operator|.
name|fillRect
argument_list|(
name|rect
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|ret
operator|=
name|ANativeWindow_unlockAndPost
argument_list|(
name|m_nativeSurface
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|>=
literal|0
condition|)
name|m_dirtyRect
operator|=
name|QRect
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|logicalDpi
name|QDpi
name|QAndroidPlatformScreen
operator|::
name|logicalDpi
parameter_list|()
specifier|const
block|{
name|qreal
name|lDpi
init|=
name|QtAndroid
operator|::
name|scaledDensity
argument_list|()
operator|*
literal|72
decl_stmt|;
return|return
name|QDpi
argument_list|(
name|lDpi
argument_list|,
name|lDpi
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|orientation
name|Qt
operator|::
name|ScreenOrientation
name|QAndroidPlatformScreen
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
return|return
name|QAndroidPlatformIntegration
operator|::
name|m_orientation
return|;
block|}
end_function
begin_function
DECL|function|nativeOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QAndroidPlatformScreen
operator|::
name|nativeOrientation
parameter_list|()
specifier|const
block|{
return|return
name|QAndroidPlatformIntegration
operator|::
name|m_nativeOrientation
return|;
block|}
end_function
begin_function
DECL|function|surfaceChanged
name|void
name|QAndroidPlatformScreen
operator|::
name|surfaceChanged
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
name|surface
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
name|lockSurface
argument_list|()
expr_stmt|;
if|if
condition|(
name|surface
operator|&&
name|w
operator|&&
name|h
condition|)
block|{
if|if
condition|(
name|m_nativeSurface
condition|)
name|ANativeWindow_release
argument_list|(
name|m_nativeSurface
argument_list|)
expr_stmt|;
name|m_nativeSurface
operator|=
name|ANativeWindow_fromSurface
argument_list|(
name|env
argument_list|,
name|surface
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"setDirty"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QRect
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|m_nativeSurface
condition|)
block|{
name|ANativeWindow_release
argument_list|(
name|m_nativeSurface
argument_list|)
expr_stmt|;
name|m_nativeSurface
operator|=
literal|0
expr_stmt|;
block|}
block|}
name|unlockSurface
argument_list|()
expr_stmt|;
name|m_surfaceWaitCondition
operator|.
name|wakeOne
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
