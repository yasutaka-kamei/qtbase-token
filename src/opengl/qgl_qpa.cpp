begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|"qgl.h"
end_include
begin_include
include|#
directive|include
file|"qgl_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     Returns an OpenGL format for the window format specified by \a format. */
DECL|function|fromSurfaceFormat
name|QGLFormat
name|QGLFormat
operator|::
name|fromSurfaceFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|QGLFormat
name|retFormat
decl_stmt|;
if|if
condition|(
name|format
operator|.
name|alphaBufferSize
argument_list|()
operator|>=
literal|0
condition|)
name|retFormat
operator|.
name|setAlphaBufferSize
argument_list|(
name|format
operator|.
name|alphaBufferSize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|blueBufferSize
argument_list|()
operator|>=
literal|0
condition|)
name|retFormat
operator|.
name|setBlueBufferSize
argument_list|(
name|format
operator|.
name|blueBufferSize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|greenBufferSize
argument_list|()
operator|>=
literal|0
condition|)
name|retFormat
operator|.
name|setGreenBufferSize
argument_list|(
name|format
operator|.
name|greenBufferSize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|redBufferSize
argument_list|()
operator|>=
literal|0
condition|)
name|retFormat
operator|.
name|setRedBufferSize
argument_list|(
name|format
operator|.
name|redBufferSize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|depthBufferSize
argument_list|()
operator|>=
literal|0
condition|)
name|retFormat
operator|.
name|setDepthBufferSize
argument_list|(
name|format
operator|.
name|depthBufferSize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|samples
argument_list|()
operator|>
literal|1
condition|)
block|{
name|retFormat
operator|.
name|setSampleBuffers
argument_list|(
name|format
operator|.
name|samples
argument_list|()
argument_list|)
expr_stmt|;
name|retFormat
operator|.
name|setSamples
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|format
operator|.
name|stencilBufferSize
argument_list|()
operator|>
literal|0
condition|)
block|{
name|retFormat
operator|.
name|setStencil
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|retFormat
operator|.
name|setStencilBufferSize
argument_list|(
name|format
operator|.
name|stencilBufferSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|retFormat
operator|.
name|setDoubleBuffer
argument_list|(
name|format
operator|.
name|swapBehavior
argument_list|()
operator|!=
name|QSurfaceFormat
operator|::
name|SingleBuffer
argument_list|)
expr_stmt|;
name|retFormat
operator|.
name|setStereo
argument_list|(
name|format
operator|.
name|stereo
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|retFormat
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a window format for the OpenGL format specified by \a format. */
end_comment
begin_function
DECL|function|toSurfaceFormat
name|QSurfaceFormat
name|QGLFormat
operator|::
name|toSurfaceFormat
parameter_list|(
specifier|const
name|QGLFormat
modifier|&
name|format
parameter_list|)
block|{
name|QSurfaceFormat
name|retFormat
decl_stmt|;
if|if
condition|(
name|format
operator|.
name|alpha
argument_list|()
condition|)
name|retFormat
operator|.
name|setAlphaBufferSize
argument_list|(
name|format
operator|.
name|alphaBufferSize
argument_list|()
operator|==
operator|-
literal|1
condition|?
literal|1
else|:
name|format
operator|.
name|alphaBufferSize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|blueBufferSize
argument_list|()
operator|>=
literal|0
condition|)
name|retFormat
operator|.
name|setBlueBufferSize
argument_list|(
name|format
operator|.
name|blueBufferSize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|greenBufferSize
argument_list|()
operator|>=
literal|0
condition|)
name|retFormat
operator|.
name|setGreenBufferSize
argument_list|(
name|format
operator|.
name|greenBufferSize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|redBufferSize
argument_list|()
operator|>=
literal|0
condition|)
name|retFormat
operator|.
name|setRedBufferSize
argument_list|(
name|format
operator|.
name|redBufferSize
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|depth
argument_list|()
condition|)
name|retFormat
operator|.
name|setDepthBufferSize
argument_list|(
name|format
operator|.
name|depthBufferSize
argument_list|()
operator|==
operator|-
literal|1
condition|?
literal|1
else|:
name|format
operator|.
name|depthBufferSize
argument_list|()
argument_list|)
expr_stmt|;
name|retFormat
operator|.
name|setSwapBehavior
argument_list|(
name|format
operator|.
name|doubleBuffer
argument_list|()
condition|?
name|QSurfaceFormat
operator|::
name|DoubleBuffer
else|:
name|QSurfaceFormat
operator|::
name|DefaultSwapBehavior
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|sampleBuffers
argument_list|()
condition|)
name|retFormat
operator|.
name|setSamples
argument_list|(
name|format
operator|.
name|samples
argument_list|()
operator|==
operator|-
literal|1
condition|?
literal|4
else|:
name|format
operator|.
name|samples
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|stencil
argument_list|()
condition|)
name|retFormat
operator|.
name|setStencilBufferSize
argument_list|(
name|format
operator|.
name|stencilBufferSize
argument_list|()
operator|==
operator|-
literal|1
condition|?
literal|1
else|:
name|format
operator|.
name|stencilBufferSize
argument_list|()
argument_list|)
expr_stmt|;
name|retFormat
operator|.
name|setStereo
argument_list|(
name|format
operator|.
name|stereo
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|retFormat
return|;
block|}
end_function
begin_function
DECL|function|setupSharing
name|void
name|QGLContextPrivate
operator|::
name|setupSharing
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QGLContext
argument_list|)
expr_stmt|;
name|QGuiGLContext
modifier|*
name|sharedContext
init|=
name|guiGlContext
operator|->
name|shareContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|sharedContext
condition|)
block|{
name|QGLContext
modifier|*
name|actualSharedContext
init|=
name|QGLContext
operator|::
name|fromGuiGLContext
argument_list|(
name|sharedContext
argument_list|)
decl_stmt|;
name|sharing
operator|=
literal|true
expr_stmt|;
name|QGLContextGroup
operator|::
name|addShare
argument_list|(
name|q
argument_list|,
name|actualSharedContext
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|hasOpenGL
name|bool
name|QGLFormat
operator|::
name|hasOpenGL
parameter_list|()
block|{
return|return
name|QApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|hasCapability
argument_list|(
name|QPlatformIntegration
operator|::
name|OpenGL
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qDeleteQGLContext
name|void
name|qDeleteQGLContext
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|QGLContext
modifier|*
name|context
init|=
cast|static_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|handle
argument_list|)
decl_stmt|;
operator|delete
name|context
expr_stmt|;
block|}
end_function
begin_function
DECL|function|chooseContext
name|bool
name|QGLContext
operator|::
name|chooseContext
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|shareContext
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLContext
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|paintDevice
operator|||
name|d
operator|->
name|paintDevice
operator|->
name|devType
argument_list|()
operator|!=
name|QInternal
operator|::
name|Widget
condition|)
block|{
name|d
operator|->
name|valid
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|QWidget
modifier|*
name|widget
init|=
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|paintDevice
argument_list|)
decl_stmt|;
name|QGLFormat
name|glformat
init|=
name|format
argument_list|()
decl_stmt|;
name|QSurfaceFormat
name|winFormat
init|=
name|QGLFormat
operator|::
name|toSurfaceFormat
argument_list|(
name|glformat
argument_list|)
decl_stmt|;
if|if
condition|(
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_TranslucentBackground
argument_list|)
condition|)
name|winFormat
operator|.
name|setAlphaBufferSize
argument_list|(
name|qMax
argument_list|(
name|winFormat
operator|.
name|alphaBufferSize
argument_list|()
argument_list|,
literal|8
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|widget
operator|->
name|windowHandle
argument_list|()
operator|->
name|handle
argument_list|()
condition|)
block|{
name|widget
operator|->
name|windowHandle
argument_list|()
operator|->
name|setSurfaceType
argument_list|(
name|QWindow
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
name|widget
operator|->
name|windowHandle
argument_list|()
operator|->
name|setFormat
argument_list|(
name|winFormat
argument_list|)
expr_stmt|;
name|widget
operator|->
name|winId
argument_list|()
expr_stmt|;
comment|//make window
block|}
operator|delete
name|d
operator|->
name|guiGlContext
expr_stmt|;
name|QGuiGLContext
modifier|*
name|shareGlContext
init|=
name|shareContext
condition|?
name|shareContext
operator|->
name|d_func
argument_list|()
operator|->
name|guiGlContext
else|:
literal|0
decl_stmt|;
name|d
operator|->
name|guiGlContext
operator|=
operator|new
name|QGuiGLContext
argument_list|(
name|winFormat
argument_list|,
name|shareGlContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|glFormat
operator|=
name|QGLFormat
operator|::
name|fromSurfaceFormat
argument_list|(
name|d
operator|->
name|guiGlContext
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|valid
operator|=
name|d
operator|->
name|guiGlContext
operator|->
name|isValid
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|valid
condition|)
block|{
name|d
operator|->
name|guiGlContext
operator|->
name|setQGLContextHandle
argument_list|(
name|this
argument_list|,
name|qDeleteQGLContext
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|setupSharing
argument_list|()
expr_stmt|;
block|}
return|return
name|d
operator|->
name|valid
return|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QGLContext
operator|::
name|reset
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLContext
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|valid
condition|)
return|return;
name|d
operator|->
name|cleanup
argument_list|()
expr_stmt|;
name|d
operator|->
name|crWin
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|sharing
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|valid
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|transpColor
operator|=
name|QColor
argument_list|()
expr_stmt|;
name|d
operator|->
name|initDone
operator|=
literal|false
expr_stmt|;
name|QGLContextGroup
operator|::
name|removeShare
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|guiGlContext
condition|)
block|{
name|d
operator|->
name|guiGlContext
operator|->
name|setQGLContextHandle
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|makeCurrent
name|void
name|QGLContext
operator|::
name|makeCurrent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLContext
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|paintDevice
operator|||
name|d
operator|->
name|paintDevice
operator|->
name|devType
argument_list|()
operator|!=
name|QInternal
operator|::
name|Widget
condition|)
return|return;
name|QWidget
modifier|*
name|widget
init|=
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|paintDevice
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|widget
operator|->
name|windowHandle
argument_list|()
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|guiGlContext
operator|->
name|makeCurrent
argument_list|(
name|widget
operator|->
name|windowHandle
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|workaroundsCached
condition|)
block|{
name|d
operator|->
name|workaroundsCached
operator|=
literal|true
expr_stmt|;
specifier|const
name|char
modifier|*
name|renderer
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|glGetString
argument_list|(
name|GL_RENDERER
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|renderer
operator|&&
name|strstr
argument_list|(
name|renderer
argument_list|,
literal|"Mali"
argument_list|)
condition|)
block|{
name|d
operator|->
name|workaround_brokenFBOReadBack
operator|=
literal|true
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QGLContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|guiGlContext
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QGLContext
operator|::
name|swapBuffers
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLContext
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|paintDevice
operator|||
name|d
operator|->
name|paintDevice
operator|->
name|devType
argument_list|()
operator|!=
name|QInternal
operator|::
name|Widget
condition|)
return|return;
name|QWidget
modifier|*
name|widget
init|=
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|paintDevice
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|widget
operator|->
name|windowHandle
argument_list|()
condition|)
return|return;
name|d
operator|->
name|guiGlContext
operator|->
name|swapBuffers
argument_list|(
name|widget
operator|->
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getProcAddress
name|void
modifier|*
name|QGLContext
operator|::
name|getProcAddress
parameter_list|(
specifier|const
name|QString
modifier|&
name|procName
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLContext
argument_list|)
expr_stmt|;
return|return
operator|(
name|void
operator|*
operator|)
name|d
operator|->
name|guiGlContext
operator|->
name|getProcAddress
argument_list|(
name|procName
operator|.
name|toAscii
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setContext
name|void
name|QGLWidget
operator|::
name|setContext
parameter_list|(
name|QGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QGLContext
modifier|*
name|shareContext
parameter_list|,
name|bool
name|deleteOldContext
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLWidget
argument_list|)
expr_stmt|;
if|if
condition|(
name|context
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLWidget::setContext: Cannot set null context"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|context
operator|->
name|device
argument_list|()
operator|==
literal|0
condition|)
comment|// a context may refere to more than 1 window.
name|context
operator|->
name|setDevice
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|//but its better to point to 1 of them than none of them.
name|QGLContext
modifier|*
name|oldcx
init|=
name|d
operator|->
name|glcx
decl_stmt|;
name|d
operator|->
name|glcx
operator|=
name|context
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|glcx
operator|->
name|isValid
argument_list|()
condition|)
name|d
operator|->
name|glcx
operator|->
name|create
argument_list|(
name|shareContext
condition|?
name|shareContext
else|:
name|oldcx
argument_list|)
expr_stmt|;
if|if
condition|(
name|deleteOldContext
condition|)
operator|delete
name|oldcx
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QGLWidgetPrivate
operator|::
name|init
parameter_list|(
name|QGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QGLWidget
modifier|*
name|shareWidget
parameter_list|)
block|{
name|initContext
argument_list|(
name|context
argument_list|,
name|shareWidget
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasOpenGLOverlays
name|bool
name|QGLFormat
operator|::
name|hasOpenGLOverlays
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|overlayTransparentColor
name|QColor
name|QGLContext
operator|::
name|overlayTransparentColor
parameter_list|()
specifier|const
block|{
return|return
name|QColor
argument_list|()
return|;
comment|// Invalid color
block|}
end_function
begin_function
DECL|function|colorIndex
name|uint
name|QGLContext
operator|::
name|colorIndex
parameter_list|(
specifier|const
name|QColor
modifier|&
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|generateFontDisplayLists
name|void
name|QGLContext
operator|::
name|generateFontDisplayLists
parameter_list|(
specifier|const
name|QFont
modifier|&
name|fnt
parameter_list|,
name|int
name|listBase
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|fnt
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|listBase
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     QGLTemporaryContext implementation */
end_comment
begin_class
DECL|class|QGLTemporaryContextPrivate
class|class
name|QGLTemporaryContextPrivate
block|{
public|public:
DECL|member|window
name|QWindow
modifier|*
name|window
decl_stmt|;
DECL|member|context
name|QGuiGLContext
modifier|*
name|context
decl_stmt|;
DECL|member|oldContext
name|QGLContext
modifier|*
name|oldContext
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QGLTemporaryContext
name|QGLTemporaryContext
operator|::
name|QGLTemporaryContext
parameter_list|(
name|bool
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QGLTemporaryContextPrivate
argument_list|)
block|{
name|d
operator|->
name|oldContext
operator|=
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|window
operator|=
operator|new
name|QWindow
expr_stmt|;
name|d
operator|->
name|window
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
name|window
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|window
operator|->
name|create
argument_list|()
expr_stmt|;
name|d
operator|->
name|context
operator|=
operator|new
name|QGuiGLContext
expr_stmt|;
name|d
operator|->
name|context
operator|->
name|makeCurrent
argument_list|(
name|d
operator|->
name|window
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QGLTemporaryContext
name|QGLTemporaryContext
operator|::
name|~
name|QGLTemporaryContext
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|oldContext
condition|)
name|d
operator|->
name|oldContext
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
operator|delete
name|d
operator|->
name|context
expr_stmt|;
operator|delete
name|d
operator|->
name|window
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|renderCxPm
name|bool
name|QGLWidgetPrivate
operator|::
name|renderCxPm
parameter_list|(
name|QPixmap
modifier|*
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*! \internal   Free up any allocated colormaps. This fn is only called for   top-level widgets. */
end_comment
begin_function
DECL|function|cleanupColormaps
name|void
name|QGLWidgetPrivate
operator|::
name|cleanupColormaps
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|setMouseTracking
name|void
name|QGLWidget
operator|::
name|setMouseTracking
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|enable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|QGLWidget
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|QGLWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLWidget
argument_list|)
expr_stmt|;
name|QWidget
operator|::
name|resizeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isValid
argument_list|()
condition|)
return|return;
name|makeCurrent
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|glcx
operator|->
name|initialized
argument_list|()
condition|)
name|glInit
argument_list|()
expr_stmt|;
name|resizeGL
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|overlayContext
specifier|const
name|QGLContext
modifier|*
name|QGLWidget
operator|::
name|overlayContext
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|makeOverlayCurrent
name|void
name|QGLWidget
operator|::
name|makeOverlayCurrent
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|updateOverlayGL
name|void
name|QGLWidget
operator|::
name|updateOverlayGL
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|colormap
specifier|const
name|QGLColormap
modifier|&
name|QGLWidget
operator|::
name|colormap
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLWidget
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|cmap
return|;
block|}
end_function
begin_function
DECL|function|setColormap
name|void
name|QGLWidget
operator|::
name|setColormap
parameter_list|(
specifier|const
name|QGLColormap
modifier|&
name|c
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QGLContext
name|QGLContext
operator|::
name|QGLContext
parameter_list|(
name|QGuiGLContext
modifier|*
name|context
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QGLContextPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|Q_D
argument_list|(
name|QGLContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|(
literal|0
argument_list|,
name|QGLFormat
operator|::
name|fromSurfaceFormat
argument_list|(
name|context
operator|->
name|format
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|guiGlContext
operator|=
name|context
expr_stmt|;
name|d
operator|->
name|guiGlContext
operator|->
name|setQGLContextHandle
argument_list|(
name|this
argument_list|,
name|qDeleteQGLContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|valid
operator|=
name|context
operator|->
name|isValid
argument_list|()
expr_stmt|;
name|d
operator|->
name|setupSharing
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|contextHandle
name|QGuiGLContext
modifier|*
name|QGLContext
operator|::
name|contextHandle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLContext
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|guiGlContext
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a OpenGL context for the window context specified by \a windowContext */
end_comment
begin_function
DECL|function|fromGuiGLContext
name|QGLContext
modifier|*
name|QGLContext
operator|::
name|fromGuiGLContext
parameter_list|(
name|QGuiGLContext
modifier|*
name|context
parameter_list|)
block|{
if|if
condition|(
operator|!
name|context
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|context
operator|->
name|qGLContextHandle
argument_list|()
condition|)
block|{
return|return
cast|reinterpret_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|qGLContextHandle
argument_list|()
argument_list|)
return|;
block|}
name|QGLContext
modifier|*
name|glContext
init|=
operator|new
name|QGLContext
argument_list|(
name|context
argument_list|)
decl_stmt|;
comment|//Dont call create on context. This can cause the platformFormat to be set on the widget, which
comment|//will cause the platformWindow to be recreated.
return|return
name|glContext
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
