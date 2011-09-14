begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsguieventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdrag.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsinputcontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformNativeInterface>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<QtGui/QBackingStore>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qeventdispatcher_win_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QWindowsNativeInterface     \brief Provides access to native handles.      Currently implemented keys     \list     \o handle (HWND)     \o getDC (DC)     \o releaseDC Releases the previously acquired DC and returns 0.     \endlist      \ingroup qt-lighthouse-win */
end_comment
begin_class
DECL|class|QWindowsNativeInterface
class|class
name|QWindowsNativeInterface
super|:
specifier|public
name|QPlatformNativeInterface
block|{
public|public:
specifier|virtual
name|void
modifier|*
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
function_decl|;
specifier|virtual
name|void
modifier|*
name|nativeResourceForBackingStore
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QBackingStore
modifier|*
name|bs
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QWindowsNativeInterface
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
if|if
condition|(
operator|!
name|window
operator|||
operator|!
name|window
operator|->
name|handle
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: '%s' requested for null window or window without handle."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QWindowsWindow
modifier|*
name|bw
init|=
cast|static_cast
argument_list|<
name|QWindowsWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|resource
operator|==
literal|"handle"
condition|)
return|return
name|bw
operator|->
name|handle
argument_list|()
return|;
if|if
condition|(
name|window
operator|->
name|surfaceType
argument_list|()
operator|==
name|QWindow
operator|::
name|RasterSurface
condition|)
block|{
if|if
condition|(
name|resource
operator|==
literal|"getDC"
condition|)
return|return
name|bw
operator|->
name|getDC
argument_list|()
return|;
if|if
condition|(
name|resource
operator|==
literal|"releaseDC"
condition|)
block|{
name|bw
operator|->
name|releaseDC
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
name|qWarning
argument_list|(
literal|"%s: Invalid key '%s' requested."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForBackingStore
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|nativeResourceForBackingStore
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QBackingStore
modifier|*
name|bs
parameter_list|)
block|{
if|if
condition|(
operator|!
name|bs
operator|||
operator|!
name|bs
operator|->
name|handle
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: '%s' requested for null backingstore or backingstore without handle."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QWindowsBackingStore
modifier|*
name|wbs
init|=
cast|static_cast
argument_list|<
name|QWindowsBackingStore
operator|*
argument_list|>
argument_list|(
name|bs
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|resource
operator|==
literal|"getDC"
condition|)
return|return
name|wbs
operator|->
name|getDC
argument_list|()
return|;
name|qWarning
argument_list|(
literal|"%s: Invalid key '%s' requested."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \class QWindowsIntegration     \brief QPlatformIntegration implementation for Windows.     \ingroup qt-lighthouse-win */
end_comment
begin_struct
DECL|struct|QWindowsIntegrationPrivate
struct|struct
name|QWindowsIntegrationPrivate
block|{
DECL|typedef|QOpenGLStaticContextPtr
typedef|typedef
name|QSharedPointer
argument_list|<
name|QOpenGLStaticContext
argument_list|>
name|QOpenGLStaticContextPtr
typedef|;
specifier|explicit
name|QWindowsIntegrationPrivate
parameter_list|(
name|bool
name|openGL
parameter_list|)
constructor_decl|;
DECL|member|m_openGL
specifier|const
name|bool
name|m_openGL
decl_stmt|;
DECL|member|m_context
name|QWindowsContext
name|m_context
decl_stmt|;
DECL|member|m_fontDatabase
name|QWindowsFontDatabase
name|m_fontDatabase
decl_stmt|;
DECL|member|m_nativeInterface
name|QWindowsNativeInterface
name|m_nativeInterface
decl_stmt|;
DECL|member|m_clipboard
name|QWindowsClipboard
name|m_clipboard
decl_stmt|;
DECL|member|m_drag
name|QWindowsDrag
name|m_drag
decl_stmt|;
DECL|member|m_eventDispatcher
name|QWindowsGuiEventDispatcher
modifier|*
name|m_eventDispatcher
decl_stmt|;
DECL|member|m_staticOpenGLContext
name|QOpenGLStaticContextPtr
name|m_staticOpenGLContext
decl_stmt|;
DECL|member|m_inputContext
name|QWindowsInputContext
name|m_inputContext
decl_stmt|;
block|}
struct|;
end_struct
begin_constructor
DECL|function|QWindowsIntegrationPrivate
name|QWindowsIntegrationPrivate
operator|::
name|QWindowsIntegrationPrivate
parameter_list|(
name|bool
name|openGL
parameter_list|)
member_init_list|:
name|m_openGL
argument_list|(
name|openGL
argument_list|)
member_init_list|,
name|m_context
argument_list|(
name|openGL
argument_list|)
member_init_list|,
name|m_eventDispatcher
argument_list|(
operator|new
name|QWindowsGuiEventDispatcher
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QWindowsIntegration
name|QWindowsIntegration
operator|::
name|QWindowsIntegration
parameter_list|(
name|bool
name|openGL
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QWindowsIntegrationPrivate
argument_list|(
name|openGL
argument_list|)
argument_list|)
block|{
name|QGuiApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|setEventDispatcher
argument_list|(
name|d
operator|->
name|m_eventDispatcher
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_clipboard
operator|.
name|registerViewer
argument_list|()
expr_stmt|;
foreach|foreach
control|(
name|QPlatformScreen
modifier|*
name|pscr
decl|,
name|QWindowsScreen
operator|::
name|screens
argument_list|()
control|)
name|screenAdded
argument_list|(
name|pscr
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsIntegration
name|QWindowsIntegration
operator|::
name|~
name|QWindowsIntegration
parameter_list|()
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseIntegration
condition|)
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hasCapability
name|bool
name|QWindowsIntegration
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
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|createPlatformPixmap
name|QPlatformPixmap
modifier|*
name|QWindowsIntegration
operator|::
name|createPlatformPixmap
parameter_list|(
name|QPlatformPixmap
operator|::
name|PixelType
name|type
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseIntegration
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|type
expr_stmt|;
return|return
operator|new
name|QRasterPlatformPixmap
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QWindowsIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
specifier|const
name|bool
name|isGL
init|=
name|window
operator|->
name|surfaceType
argument_list|()
operator|==
name|QWindow
operator|::
name|OpenGLSurface
decl_stmt|;
name|QWindowsWindow
operator|::
name|WindowData
name|requested
decl_stmt|;
name|requested
operator|.
name|flags
operator|=
name|window
operator|->
name|windowFlags
argument_list|()
expr_stmt|;
name|requested
operator|.
name|geometry
operator|=
name|window
operator|->
name|geometry
argument_list|()
expr_stmt|;
specifier|const
name|QWindowsWindow
operator|::
name|WindowData
name|obtained
init|=
name|QWindowsWindow
operator|::
name|WindowData
operator|::
name|create
argument_list|(
name|window
argument_list|,
name|requested
argument_list|,
name|window
operator|->
name|windowTitle
argument_list|()
argument_list|,
name|isGL
argument_list|)
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseIntegration
operator|||
name|QWindowsContext
operator|::
name|verboseWindows
condition|)
name|qDebug
argument_list|()
operator|.
name|nospace
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|' '
operator|<<
name|window
operator|<<
literal|'\n'
operator|<<
literal|"    Requested: "
operator|<<
name|requested
operator|.
name|geometry
operator|<<
literal|" Flags="
operator|<<
name|QWindowsWindow
operator|::
name|debugWindowFlags
argument_list|(
name|requested
operator|.
name|flags
argument_list|)
operator|<<
literal|'\n'
operator|<<
literal|"    Obtained : "
operator|<<
name|obtained
operator|.
name|geometry
operator|<<
literal|" Margins "
operator|<<
name|obtained
operator|.
name|frame
operator|<<
literal|" Flags="
operator|<<
name|QWindowsWindow
operator|::
name|debugWindowFlags
argument_list|(
name|obtained
operator|.
name|flags
argument_list|)
operator|<<
literal|" Handle="
operator|<<
name|obtained
operator|.
name|hwnd
operator|<<
literal|'\n'
expr_stmt|;
if|if
condition|(
operator|!
name|obtained
operator|.
name|hwnd
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|requested
operator|.
name|flags
operator|!=
name|obtained
operator|.
name|flags
condition|)
name|window
operator|->
name|setWindowFlags
argument_list|(
name|obtained
operator|.
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|requested
operator|.
name|geometry
operator|!=
name|obtained
operator|.
name|geometry
condition|)
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|,
name|obtained
operator|.
name|geometry
argument_list|)
expr_stmt|;
return|return
operator|new
name|QWindowsWindow
argument_list|(
name|window
argument_list|,
name|obtained
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QWindowsIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseIntegration
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|window
expr_stmt|;
return|return
operator|new
name|QWindowsBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
name|QPlatformOpenGLContext
DECL|function|createPlatformOpenGLContext
modifier|*
name|QWindowsIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseIntegration
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|context
operator|->
name|format
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_staticOpenGLContext
operator|.
name|isNull
argument_list|()
condition|)
name|d
operator|->
name|m_staticOpenGLContext
operator|=
name|QSharedPointer
argument_list|<
name|QOpenGLStaticContext
argument_list|>
argument_list|(
name|QOpenGLStaticContext
operator|::
name|create
argument_list|()
argument_list|)
expr_stmt|;
name|QScopedPointer
argument_list|<
name|QWindowsGLContext
argument_list|>
name|result
argument_list|(
operator|new
name|QWindowsGLContext
argument_list|(
name|d
operator|->
name|m_staticOpenGLContext
argument_list|,
name|context
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|->
name|isValid
argument_list|()
condition|)
return|return
name|result
operator|.
name|take
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QWindowsIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_fontDatabase
return|;
block|}
end_function
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QWindowsIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_nativeInterface
return|;
block|}
end_function
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QWindowsIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_clipboard
return|;
block|}
end_function
begin_function
DECL|function|drag
name|QPlatformDrag
modifier|*
name|QWindowsIntegration
operator|::
name|drag
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseIntegration
condition|)
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
return|return
operator|&
name|d
operator|->
name|m_drag
return|;
block|}
end_function
begin_function
DECL|function|inputContext
name|QPlatformInputContext
modifier|*
name|QWindowsIntegration
operator|::
name|inputContext
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_inputContext
return|;
block|}
end_function
begin_function
DECL|function|instance
name|QWindowsIntegration
modifier|*
name|QWindowsIntegration
operator|::
name|instance
parameter_list|()
block|{
return|return
cast|static_cast
argument_list|<
name|QWindowsIntegration
operator|*
argument_list|>
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|guiThreadEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QWindowsIntegration
operator|::
name|guiThreadEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|m_eventDispatcher
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
