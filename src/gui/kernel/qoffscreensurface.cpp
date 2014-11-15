begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qoffscreensurface.h"
end_include
begin_include
include|#
directive|include
file|"qguiapplication_p.h"
end_include
begin_include
include|#
directive|include
file|"qscreen.h"
end_include
begin_include
include|#
directive|include
file|"qplatformintegration.h"
end_include
begin_include
include|#
directive|include
file|"qplatformoffscreensurface.h"
end_include
begin_include
include|#
directive|include
file|"qwindow.h"
end_include
begin_include
include|#
directive|include
file|"qplatformwindow.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QOffscreenSurface     \inmodule QtGui     \since 5.1     \brief The QOffscreenSurface class represents an offscreen surface in the underlying platform.      QOffscreenSurface is intended to be used with QOpenGLContext to allow rendering with OpenGL in     an arbitrary thread without the need to create a QWindow.      Even though the surface is renderable, the surface's pixels are not accessible.     QOffscreenSurface should only be used to create OpenGL resources such as textures     or framebuffer objects.      An application will typically use QOffscreenSurface to perform some time-consuming tasks in a     separate thread in order to avoid stalling the main rendering thread. Resources created in the     QOffscreenSurface's context can be shared with the main OpenGL context. Some common use cases     are asynchronous texture uploads or rendering into a QOpenGLFramebufferObject.      How the offscreen surface is implemented depends on the underlying platform, but it will     typically use a pixel buffer (pbuffer). If the platform doesn't implement or support     offscreen surfaces, QOffscreenSurface will use an invisible QWindow internally.      \note Due to the fact that QOffscreenSurface is backed by a QWindow on some platforms,     cross-platform applications must ensure that create() is only called on the main (GUI)     thread. The QOffscreenSurface is then safe to be used with     \l{QOpenGLContext::makeCurrent()}{makeCurrent()} on other threads, but the     initialization and destruction must always happen on the main (GUI) thread.      \note In order to create an offscreen surface that is guaranteed to be compatible with     a given context and window, make sure to set the format to the context's or the     window's actual format, that is, the QSurfaceFormat returned from     QOpenGLContext::format() or QWindow::format() \e{after the context or window has been     created}. Passing the format returned from QWindow::requestedFormat() to setFormat()     may result in an incompatible offscreen surface since the underlying windowing system     interface may offer a different set of configurations for window and pbuffer surfaces. */
end_comment
begin_class
DECL|class|QOffscreenSurfacePrivate
class|class
name|Q_GUI_EXPORT
name|QOffscreenSurfacePrivate
super|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QOffscreenSurface
parameter_list|)
specifier|public
private|:
DECL|function|QOffscreenSurfacePrivate
name|QOffscreenSurfacePrivate
parameter_list|()
member_init_list|:
name|QObjectPrivate
argument_list|()
member_init_list|,
name|surfaceType
argument_list|(
name|QSurface
operator|::
name|OpenGLSurface
argument_list|)
member_init_list|,
name|platformOffscreenSurface
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|offscreenWindow
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|requestedFormat
argument_list|(
name|QSurfaceFormat
operator|::
name|defaultFormat
argument_list|()
argument_list|)
member_init_list|,
name|screen
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|size
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
block|{     }
DECL|function|~QOffscreenSurfacePrivate
name|~
name|QOffscreenSurfacePrivate
parameter_list|()
block|{     }
DECL|member|surfaceType
name|QSurface
operator|::
name|SurfaceType
name|surfaceType
decl_stmt|;
DECL|member|platformOffscreenSurface
name|QPlatformOffscreenSurface
modifier|*
name|platformOffscreenSurface
decl_stmt|;
DECL|member|offscreenWindow
name|QWindow
modifier|*
name|offscreenWindow
decl_stmt|;
DECL|member|requestedFormat
name|QSurfaceFormat
name|requestedFormat
decl_stmt|;
DECL|member|screen
name|QScreen
modifier|*
name|screen
decl_stmt|;
DECL|member|size
name|QSize
name|size
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     Creates an offscreen surface for the \a targetScreen.      The underlying platform surface is not created until create() is called.      \sa setScreen(), create() */
end_comment
begin_constructor
DECL|function|QOffscreenSurface
name|QOffscreenSurface
operator|::
name|QOffscreenSurface
parameter_list|(
name|QScreen
modifier|*
name|targetScreen
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QOffscreenSurfacePrivate
argument_list|()
argument_list|,
literal|0
argument_list|)
member_init_list|,
name|QSurface
argument_list|(
name|Offscreen
argument_list|)
block|{
name|Q_D
argument_list|(
name|QOffscreenSurface
argument_list|)
expr_stmt|;
name|d
operator|->
name|screen
operator|=
name|targetScreen
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|screen
condition|)
name|d
operator|->
name|screen
operator|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
expr_stmt|;
comment|//if your applications aborts here, then chances are your creating a QOffscreenSurface before
comment|//the screen list is populated.
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|screen
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|screen
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|screenDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the offscreen surface. */
end_comment
begin_destructor
DECL|function|~QOffscreenSurface
name|QOffscreenSurface
operator|::
name|~
name|QOffscreenSurface
parameter_list|()
block|{
name|destroy
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns the surface type of the offscreen surface.      The surface type of an offscreen surface is always QSurface::OpenGLSurface. */
end_comment
begin_function
DECL|function|surfaceType
name|QOffscreenSurface
operator|::
name|SurfaceType
name|QOffscreenSurface
operator|::
name|surfaceType
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOffscreenSurface
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|surfaceType
return|;
block|}
end_function
begin_comment
comment|/*!     Allocates the platform resources associated with the offscreen surface.      It is at this point that the surface format set using setFormat() gets resolved     into an actual native surface.      Call destroy() to free the platform resources if necessary.      \note Some platforms require this function to be called on the main (GUI) thread.      \sa destroy() */
end_comment
begin_function
DECL|function|create
name|void
name|QOffscreenSurface
operator|::
name|create
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOffscreenSurface
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|platformOffscreenSurface
operator|&&
operator|!
name|d
operator|->
name|offscreenWindow
condition|)
block|{
name|d
operator|->
name|platformOffscreenSurface
operator|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|createPlatformOffscreenSurface
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|// No platform offscreen surface, fallback to an invisible window
if|if
condition|(
operator|!
name|d
operator|->
name|platformOffscreenSurface
condition|)
block|{
if|if
condition|(
name|QThread
operator|::
name|currentThread
argument_list|()
operator|!=
name|qGuiApp
operator|->
name|thread
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"Attempting to create QWindow-based QOffscreenSurface outside the gui thread. Expect failures."
argument_list|)
expr_stmt|;
name|d
operator|->
name|offscreenWindow
operator|=
operator|new
name|QWindow
argument_list|(
name|d
operator|->
name|screen
argument_list|)
expr_stmt|;
comment|// Remove this window from the global list since we do not want it to be destroyed when closing the app.
comment|// The QOffscreenSurface has to be usable even after exiting the event loop.
name|QGuiApplicationPrivate
operator|::
name|window_list
operator|.
name|removeOne
argument_list|(
name|d
operator|->
name|offscreenWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|offscreenWindow
operator|->
name|setSurfaceType
argument_list|(
name|QWindow
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
name|d
operator|->
name|offscreenWindow
operator|->
name|setFormat
argument_list|(
name|d
operator|->
name|requestedFormat
argument_list|)
expr_stmt|;
name|d
operator|->
name|offscreenWindow
operator|->
name|setGeometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|d
operator|->
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|d
operator|->
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|offscreenWindow
operator|->
name|create
argument_list|()
expr_stmt|;
block|}
name|QPlatformSurfaceEvent
name|e
argument_list|(
name|QPlatformSurfaceEvent
operator|::
name|SurfaceCreated
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|this
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Releases the native platform resources associated with this offscreen surface.      \sa create() */
end_comment
begin_function
DECL|function|destroy
name|void
name|QOffscreenSurface
operator|::
name|destroy
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOffscreenSurface
argument_list|)
expr_stmt|;
name|QPlatformSurfaceEvent
name|e
argument_list|(
name|QPlatformSurfaceEvent
operator|::
name|SurfaceAboutToBeDestroyed
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|this
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|platformOffscreenSurface
expr_stmt|;
name|d
operator|->
name|platformOffscreenSurface
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|offscreenWindow
condition|)
block|{
name|d
operator|->
name|offscreenWindow
operator|->
name|destroy
argument_list|()
expr_stmt|;
operator|delete
name|d
operator|->
name|offscreenWindow
expr_stmt|;
name|d
operator|->
name|offscreenWindow
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns \c true if this offscreen surface is valid; otherwise returns \c false.      The offscreen surface is valid if the platform resources have been successfuly allocated.      \sa create() */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QOffscreenSurface
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOffscreenSurface
argument_list|)
expr_stmt|;
return|return
operator|(
name|d
operator|->
name|platformOffscreenSurface
operator|&&
name|d
operator|->
name|platformOffscreenSurface
operator|->
name|isValid
argument_list|()
operator|)
operator|||
operator|(
name|d
operator|->
name|offscreenWindow
operator|&&
name|d
operator|->
name|offscreenWindow
operator|->
name|handle
argument_list|()
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the offscreen surface \a format.      The surface format will be resolved in the create() function. Calling     this function after create() will not re-resolve the surface format of the native surface.      \sa create(), destroy() */
end_comment
begin_function
DECL|function|setFormat
name|void
name|QOffscreenSurface
operator|::
name|setFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOffscreenSurface
argument_list|)
expr_stmt|;
name|d
operator|->
name|requestedFormat
operator|=
name|format
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the requested surfaceformat of this offscreen surface.      If the requested format was not supported by the platform implementation,     the requestedFormat will differ from the actual offscreen surface format.      This is the value set with setFormat().      \sa setFormat(), format()  */
end_comment
begin_function
DECL|function|requestedFormat
name|QSurfaceFormat
name|QOffscreenSurface
operator|::
name|requestedFormat
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOffscreenSurface
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|requestedFormat
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the actual format of this offscreen surface.      After the offscreen surface has been created, this function will return the actual     surface format of the surface. It might differ from the requested format if the requested     format could not be fulfilled by the platform.      \sa create(), requestedFormat() */
end_comment
begin_function
DECL|function|format
name|QSurfaceFormat
name|QOffscreenSurface
operator|::
name|format
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOffscreenSurface
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|platformOffscreenSurface
condition|)
return|return
name|d
operator|->
name|platformOffscreenSurface
operator|->
name|format
argument_list|()
return|;
if|if
condition|(
name|d
operator|->
name|offscreenWindow
condition|)
return|return
name|d
operator|->
name|offscreenWindow
operator|->
name|format
argument_list|()
return|;
return|return
name|d
operator|->
name|requestedFormat
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the size of the offscreen surface. */
end_comment
begin_function
DECL|function|size
name|QSize
name|QOffscreenSurface
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOffscreenSurface
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|size
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the screen to which the offscreen surface is connected.      \sa setScreen() */
end_comment
begin_function
DECL|function|screen
name|QScreen
modifier|*
name|QOffscreenSurface
operator|::
name|screen
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOffscreenSurface
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|screen
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the screen to which the offscreen surface is connected.      If the offscreen surface has been created, it will be recreated on the \a newScreen.      \sa screen() */
end_comment
begin_function
DECL|function|setScreen
name|void
name|QOffscreenSurface
operator|::
name|setScreen
parameter_list|(
name|QScreen
modifier|*
name|newScreen
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOffscreenSurface
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|newScreen
condition|)
name|newScreen
operator|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
expr_stmt|;
if|if
condition|(
name|newScreen
operator|!=
name|d
operator|->
name|screen
condition|)
block|{
specifier|const
name|bool
name|wasCreated
init|=
name|d
operator|->
name|platformOffscreenSurface
operator|!=
literal|0
operator|||
name|d
operator|->
name|offscreenWindow
operator|!=
literal|0
decl_stmt|;
if|if
condition|(
name|wasCreated
condition|)
name|destroy
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|screen
condition|)
name|disconnect
argument_list|(
name|d
operator|->
name|screen
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|screenDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|screen
operator|=
name|newScreen
expr_stmt|;
if|if
condition|(
name|newScreen
condition|)
block|{
name|connect
argument_list|(
name|d
operator|->
name|screen
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|screenDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|wasCreated
condition|)
name|create
argument_list|()
expr_stmt|;
block|}
emit|emit
name|screenChanged
argument_list|(
name|newScreen
argument_list|)
emit|;
block|}
block|}
end_function
begin_comment
comment|/*!     Called when the offscreen surface's screen is destroyed.      \internal */
end_comment
begin_function
DECL|function|screenDestroyed
name|void
name|QOffscreenSurface
operator|::
name|screenDestroyed
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QOffscreenSurface
argument_list|)
expr_stmt|;
if|if
condition|(
name|object
operator|==
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|screen
argument_list|)
condition|)
name|setScreen
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QOffscreenSurface::screenChanged(QScreen *screen)      This signal is emitted when an offscreen surface's \a screen changes, either     by being set explicitly with setScreen(), or automatically when     the window's screen is removed. */
end_comment
begin_comment
comment|/*!     Returns the platform offscreen surface corresponding to the offscreen surface.      \internal */
end_comment
begin_function
DECL|function|handle
name|QPlatformOffscreenSurface
modifier|*
name|QOffscreenSurface
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOffscreenSurface
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformOffscreenSurface
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the platform surface corresponding to the offscreen surface.      \internal */
end_comment
begin_function
DECL|function|surfaceHandle
name|QPlatformSurface
modifier|*
name|QOffscreenSurface
operator|::
name|surfaceHandle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QOffscreenSurface
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|offscreenWindow
condition|)
return|return
name|d
operator|->
name|offscreenWindow
operator|->
name|handle
argument_list|()
return|;
return|return
name|d
operator|->
name|platformOffscreenSurface
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
